import os

from metis.Sample import DBSSample, DirectorySample
from metis.CondorTask import CondorTask
from metis.StatsParser import StatsParser
import samples
from time import sleep

import sys
from pprint import pprint

condorpath = os.path.dirname(os.path.realpath(__file__))

if __name__ == "__main__":

    samples_list = []
    samples_list += samples.samples_VVV4L_2018.keys() # See condor/samples.py
    samples_list += samples.samples_VVV4L_2017.keys() # See condor/samples.py
    samples_list += samples.samples_VVV4L_2016.keys() # See condor/samples.py
    samples_list += samples.samples_VVV4L_2016_EFT.keys()
    samples_list += samples.samples_VVV4L_2017_EFT.keys()
    samples_list += samples.samples_VVV4L_2018_EFT.keys()

    # submission tag
    tag = "v7"

    # Task summary for printing out msummary
    task_summary = {}

    while True:

        total_nfiles = 0

        # Boolean to aggregate whether all tasks are complete
        all_tasks_complete = True

        condor_submit_params_do_fetch = {"sites": "T2_US_UCSD", "use_xrootd":True, "classads": [ ["metis_extraargs", "fetch_nano"] ]}
        condor_submit_params_no_fetch = {"sites": "T2_US_UCSD", "use_xrootd":True}

        badfiles = []

        for sample in samples_list:

            task = CondorTask(
                    sample = sample,
                    files_per_output = 1,
                    output_name = "output.root",
                    tag = tag,
                    condor_submit_params = condor_submit_params_do_fetch,
                    cmssw_version = "CMSSW_10_5_0",
                    input_executable = "condor_executable_skimmer_metis.sh", # your condor executable here
                    tarfile = "/nfs-7/userdata/phchang/NanoSkimmerPackages/NanoSkimmer_v3.package.tar.gz", # your tarfile with assorted goodies here
                    special_dir = "FourLepNanoSkim/{}".format(tag), # output files into /hadoop/cms/store/<user>/<special_dir>
            )

            total_nfiles += (len(sample.get_files()))

            # Straightforward logic
            if not task.complete():
                task.process()

            # Aggregate whether all tasks are complete
            all_tasks_complete = all_tasks_complete and task.complete()

            # Set task summary
            task_summary[task.get_sample().get_datasetname()] = task.get_task_summary()

            # # Checking for XCache error
            # this_summary = task.get_task_summary()
            # jobs = this_summary['jobs']
            # for job in jobs:
            #     err_file = jobs[job]['condor_jobs'][-1]['logfile_err']
            #     err = open(err_file)
            #     # Parse the error file
            #     has_badread = False
            #     downloaded = False
            #     in_nano_postproc_bloc = False
            #     for line in err.readlines():
            #         ls = line.strip()
            #         if in_nano_postproc_bloc:
            #             if "badread" in ls:
            #                 has_badread = True
            #             if "Running count" in ls:
            #                 break
            #         if "MB/s" in ls:
            #             downloaded = True
            #         if "Running nano_postproc.py" in ls:
            #             in_nano_postproc_bloc = True
            #     if has_badread:
            #         out_file = jobs[job]['condor_jobs'][-1]['logfile_out']
            #         out = open(out_file)
            #         for line in out.readlines():
            #             ls = line.strip()
            #             if "TRANSFER:EXIT" in ls and ".root" in ls:
            #                 badfile ="/hadoop/cms/store/user" + ls.split("/store/user")[1]
            #                 badfiles.append(badfile)

        # badfile_summary = open("badfiles.txt", "w")
        # for badfile in badfiles:
        #     badfile_summary.write(badfile + "\n")

        print("total_nfiles: {}".format(total_nfiles))

        # Parse the summary and make a summary.txt that will be used to pretty status of the jobs
        os.system("rm web_summary.json")
        webdir="~/public_html/FourLeptonNanoSkimmerDashboard"
        StatsParser(data=task_summary, webdir=webdir).do()
        os.system("chmod -R 755 {}".format(webdir))
        # os.system("cp {}/web_summary.json {}/../ProjectMetis/".format(webdir, condorpath))
        os.system("msummary -i {}/web_summary.json -r".format(webdir))

        # If all done exit the loop
        if all_tasks_complete:
            print("")
            print("All job finished")
            print("")
            break

        # Neat trick to not exit the script for force updating
        print('Press Ctrl-C to force update, otherwise will sleep for 600 seconds')
        try:
            for i in reversed(range(0, 600)):
                sleep(1) # could use a backward counter to be preeety :)
                sys.stdout.write("\r{} mins {} seconds till updating ...".format(i/60, i%60))
                sys.stdout.flush()
        except KeyboardInterrupt:
            raw_input("Press Enter to force update, or Ctrl-C to quit.")
            print("Force updating...")
