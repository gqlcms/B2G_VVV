<img src="http://i.imgur.com/oYKKgyW.png" width="350">

[![Build Status](https://travis-ci.org/aminnj/ProjectMetis.png)](https://travis-ci.org/aminnj/ProjectMetis)
[![Coverage Status](https://coveralls.io/repos/github/aminnj/ProjectMetis/badge.png)](https://coveralls.io/github/aminnj/ProjectMetis)

Concrete things that ProjectMetis can do:
* Submission of arbitrary CMSSW jobs on a dataset (or list of files) to condor
  * A dataset could be a published DBS dataset, a directory (containing files), or a dataset published on [DIS](https://github.com/aminnj/dis)
  * Arbitrary CMSSW jobs include CMS4
* Submit arbitrary "bash" jobs to condor (facilitates "babymaking")
* Chain a set of CMSSW tasks to go from LHE to MINIAOD

In the process of fulfilling the above, ProjectMetis exposes some nice standalone API for:
* `condor_q`, `condor_submit`, etc.
* [DIS](https://github.com/aminnj/dis) integration (i.e., queries to internal SNT database, MCM, PhEDEx, DBS)

## Installation and Setup
0. Checkout this repository
1. Set up environment via `source setup.sh`. Note that this doesn't overwrite an existing CMSSW environment if you already have one

## Example
CRAB-like operation requires a dataset name, a CMSSW pset, and a tarball of the environment (if necessary).
Here's a quick preview, but there are more use case examples in `examples/`.
```python
from metis.CMSSWTask import CMSSWTask
from metis.Sample import DBSSample
from metis.StatsParser import StatsParser
import time

def run():
    total_summary = {}
    for dsname in [
                "/SingleMuon/Run2017H-17Nov2017-v2/MINIAOD",
                "/DoubleMuon/Run2017H-17Nov2017-v1/MINIAOD",
            ]:
        task = CMSSWTask(
                sample = DBSSample(dataset=dsname),
                events_per_output = 700e3,
                output_name = "output.root",
                tag = "v1",
                pset = "pset_NANO_from_MINIAOD.py",
                cmssw_version = "CMSSW_10_2_5",
                scram_arch = "slc6_amd64_gcc700",
                # Optionally specify a tarball of the CMSSW environment made with `mtarfile`
                # tarfile = "/nfs-7/userdata/libCMS3/lib_CMS4_V00-00-03_workaround.tar.gz",
                )

        # Chunk inputs, submit to condor, resubmit failures, etc
        task.process()

        total_summary[task.get_sample().get_datasetname()] = task.get_task_summary()

    # Web dashboard
    StatsParser(data=total_summary, webdir="~/public_html/dump/metis_nano/").do()

if __name__ == "__main__":
    for i in range(100):
        run()
        time.sleep(30*60)
```


## Unit tests
Unit tests will be written in `test/` following the convention of appending `_t.py` to the class which it tests.
Workflow tests will also be written in `test/` following the convention of prepending `test_` to the name, e.g., `test_DummyMoveWorkflow.py`.

The full unit test suite is run using the executable `mtest` in `scripts/` (if Metis is set up properly, you need only execute the command `mtest`). For more fine-grained control, try
* for all class unit tests, execute the following from this project directory: `python -m unittest discover -p "*_t.py"`
* for all workflow tests, execute `python -m unittest discover -p "test_*.py"`
* for all tests, execute: `python -m unittest discover -s test -p "*.py"`

## Development
General workflow is 
* Make changes
* Test with `mtest` (or if it's a minor change, ignore this and let the continuous integration take care of testing)
* Submit a PR
