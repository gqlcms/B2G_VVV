import os
import time

from metis.CondorTask import CondorTask
from metis.Sample import DBSSample
from metis.StatsParser import StatsParser

if not os.path.exists("inputs.tar.gz"):
    os.system("tar cvzf inputs.tar.gz looper.py")

for i in range(100):
    total_summary = {}
    for dataset in [
            "/DYJetsToLL_M-4to50_HT-100to200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/RunIIAutumn18NanoAODv7-Nano02Apr2020_102X_upgrade2018_realistic_v21-v1/NANOAODSIM",
            ]:
        task = CondorTask(
                sample = DBSSample(dataset=dataset),
                events_per_output = 1e6,
                output_name = "output.root",
                tag = "nanotestv1",
                cmssw_version = "CMSSW_10_2_5",
                scram_arch = "slc6_amd64_gcc700",
                tarfile = "inputs.tar.gz",
                executable = "condor_nano_exe.sh",
                )
        task.process()
        total_summary[task.get_sample().get_datasetname()] = task.get_task_summary()

    StatsParser(data=total_summary, webdir="~/public_html/dump/metis_nanotest/").do()
    time.sleep(30*60)
