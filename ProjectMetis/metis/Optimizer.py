import time
import os
import sys
import itertools
import traceback
import datetime
import urllib
import json

from metis.Sample import DBSSample
from metis.CMSSWTask import CMSSWTask
from metis.StatsParser import StatsParser
from metis.Utils import send_email, interruptible_sleep, cached, from_timestamp, good_sites
from metis.LogParser import log_parser
from pprint import pprint

import scripts.dis_client as dis
import urllib

# NOTE xcache patterns are in
# /cvmfs/cms.cern.ch/SITECONF/T2_US_UCSD/PhEDEx/storage.xml
# TODO Do we want to add UCSD/Caltech to `get_file_replicas` when one of these matches
    # path-match="/+store/(data/Run2016[A-Z]/[^/]+/MINIAOD/03Feb2017.*)" 
    # path-match="/+store/(mc/RunIISummer16MiniAODv2/[^/]+/MINIAODSIM/PUMoriond17_80X_.*)" 
    # path-match="/+store/(mc/RunIIFall17MiniAODv2/[^/]+/MINIAODSIM/.*)"
    # path-match="/+store/(data/Run2017[A-Z]/[^/]+/MINIAOD/31Mar2018-.*)"

def get_file_replicas_uncached(dsname, dasgoclient=False):
    if os.getenv("USEDASGOCLIENT", False):
        dasgoclient = True
    if dasgoclient:
        url = "https://cmsweb.cern.ch/phedex/datasvc/json/prod/fileReplicas?dataset={}".format(dsname)
        response = urllib.urlopen(url).read()
        info = json.loads(response)["phedex"]["block"]
    else:
        rawresponse = dis.query(dsname, typ="sites", detail=True)
        info = rawresponse["payload"]["block"]
    file_replicas = {}
    for block in info:
        for fd in block["file"]:
            filesizeGB = round(fd["bytes"]/(1.0e6),2)
            fname = fd["name"]
            nodes = []
            for node in fd["replica"]:
                name = str(node["node"])
                if node.get("se",None) and "TAPE" in node["se"]: continue # no tape
                if "_US_" not in name: continue # only US
                if "FNAL" in name: # can't run directly at fnal, but purdue is basically next to fnal
                    name = "T2_US_Purdue"
                    # though if it's already at purdue anyway, no need to duplicate the node name
                    if name in nodes: continue
                nodes.append(name)
            file_replicas[fname] = {
                    "name": fname,
                    "nodes": nodes,
                    "filesizeGB": filesizeGB
                    }
    return file_replicas
get_file_replicas = cached(default_max_age = datetime.timedelta(seconds=21*24*3600), filename="site_cache.shelf")(get_file_replicas_uncached)
    
class Optimizer(object):
    def __init__(self):
        """
        Yes. It's a single function and doesn't need to be a class.
        But in the future this may track state or something.
        """
        pass

    def get_sites(self, task, v_ins, v_out):

        replica_info = get_file_replicas(task.get_sample().get_datasetname())
        sub_history = task.get_job_submission_history()
        logdir_full = os.path.abspath("{0}/logs/std_logs/".format(task.get_taskdir()))
        logdir_full = os.path.abspath("{0}/logs/std_logs/".format(task.get_taskdir()))
        last_run_site = None
        v_csvsites = [] # comma-separated sites for each job to submit
        for ins,out in zip(v_ins,v_out):
            index = out.get_index()
            cids = sub_history.get(index,[])
            # set of all sites where the job has run before (and failed presumably)
            already_ran = set([])
            times_run = {}
            for cid in cids:
                logfname = "{0}/1e.{1}.{2}".format(logdir_full, cid, "out")
                parsed = log_parser(logfname,do_header=True,do_error=False,do_rate=False)
                site = parsed.get("site","")
                if not site: continue
                already_ran.update(site)
                last_run_site = site[:]
                if not site in times_run: times_run[site] = 1
                times_run[site] += 1
            sites_per_file = []
            for infile in ins:
                if infile.get_name() not in replica_info:
                    print "[!] File {} for job {} not found on phedex".format(infile.get_name(),index)
                replica_sites = replica_info.get(infile.get_name(),{}).get("nodes",[])
                sites_per_file.append(set(replica_sites))
            # the intersection of all sites per input file (i.e., sites where all inputs exist)
            sites_with_all_files = reduce(lambda x,y: x&y, sites_per_file)
            # union (i.e., sites where at least one input exists)
            sites_with_some_files = reduce(lambda x,y: x|y, sites_per_file)

            had3failures = set([s for s,num in times_run.items() if num>=3])

            if len(cids) > 20:
                print "[!] File {} for job {} has failed 20 times already at {}".format(out.get_name(),index,str(times_run))

            # best list = pool of good sites where we 
            # - have not had at least 3 previous failures
            # - have all files
            # - blacklisting last site where the job was run
            # if a file goes into the best case site (files are all there, <3 failures, not last run there),
            # and then it fails, then it will be the last_run_site, and then fall into the last case
            # if it fails again, it should be able to go back into case 1 provided it didn't fail >=3 times
            possible_sites = (good_sites & sites_with_all_files) - had3failures - set([last_run_site])
            if len(possible_sites) > 0:
                v_csvsites.append(",".join(possible_sites))
                continue

            # relax "have all files" to "have at least one file"
            possible_sites = (good_sites & sites_with_some_files) - had3failures - set([last_run_site])
            if len(possible_sites) > 0:
                v_csvsites.append(",".join(possible_sites))
                continue

            # relax "have not had at least 3 previous failures"
            possible_sites = (good_sites & sites_with_some_files) - set([last_run_site])
            if len(possible_sites) > 0:
                v_csvsites.append(",".join(possible_sites))
                continue

            # relax file locality entirely
            possible_sites = (good_sites) - set([last_run_site])
            if len(possible_sites) > 0:
                v_csvsites.append(",".join(possible_sites))
                continue

            raise RuntimeError("No sites to submit to. good_sites = {}, last_run_site = {}".format(good_sites,last_run_site))
            
        if len(v_csvsites) != len(v_out):
            raise RuntimeError("Optimizer failed to give desired sites list with length ({}) equal to the jobs ({})".format(len(v_csvsites), len(v_out)))

        return v_csvsites

if __name__ == "__main__":
    pass
