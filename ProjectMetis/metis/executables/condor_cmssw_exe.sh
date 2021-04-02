#!/bin/bash

OUTPUTDIR=$1
OUTPUTNAME=$2
INPUTFILENAMES=$3
IFILE=$4
PSET=$5
CMSSWVERSION=$6
SCRAMARCH=$7
NEVTS=$8
FIRSTEVT=$9
EXPECTEDNEVTS=${10}
OTHEROUTPUTS=${11}
PSETARGS="${@:12}" # since args can have spaces, we take 10th-->last argument as one

# Make sure OUTPUTNAME doesn't have .root since we add it manually
OUTPUTNAME=$(echo $OUTPUTNAME | sed 's/\.root//')

export SCRAM_ARCH=${SCRAMARCH}

function getjobad {
    grep -i "^$1" "$_CONDOR_JOB_AD" | cut -d= -f2- | xargs echo
}
function setup_chirp {
    if [ -e ./condor_chirp ]; then
    # Note, in the home directory
        mkdir chirpdir
        mv condor_chirp chirpdir/
        export PATH="$PATH:$(pwd)/chirpdir"
        echo "[chirp] Found and put condor_chirp into $(pwd)/chirpdir"
    elif [ -e /usr/libexec/condor/condor_chirp ]; then
        export PATH="$PATH:/usr/libexec/condor"
        echo "[chirp] Found condor_chirp in /usr/libexec/condor"
    else
        echo "[chirp] No condor_chirp :("
    fi
}
function chirp {
    # Note, $1 (the classad name) must start with Chirp
    condor_chirp set_job_attr_delayed $1 $2
    ret=$?
    echo "[chirp] Chirped $1 => $2 with exit code $ret"
}
function edit_pset {
    echo "process.maxEvents.input = cms.untracked.int32(${NEVTS})" >> pset.py
    echo "if hasattr(process,'externalLHEProducer'):" >> pset.py
    echo "    process.externalLHEProducer.nEvents = cms.untracked.uint32(${NEVTS})" >> pset.py
    echo "set_output_name(\"${OUTPUTNAME}.root\")" >> pset.py
    if [[ "$INPUTFILENAMES" != "dummy"* ]]; then
        echo "process.source.fileNames = cms.untracked.vstring([" >> pset.py
        for INPUTFILENAME in $(echo "$INPUTFILENAMES" | sed -n 1'p' | tr ',' '\n'); do
            INPUTFILENAME=$(echo $INPUTFILENAME | sed 's|^/hadoop/cms||')
            # INPUTFILENAME="root://xrootd.unl.edu/${INPUTFILENAME}"
            echo "\"${INPUTFILENAME}\"," >> pset.py
        done
        echo "])" >> pset.py
    fi
    if [ "$FIRSTEVT" -ge 0 ]; then
        # events to skip, event number to assign to first event
        echo "try:" >> pset.py
        echo "    if not 'Empty' in str(process.source): process.source.skipEvents = cms.untracked.uint32(max(${FIRSTEVT}-1,0))" >> pset.py
        echo "except: pass" >> pset.py
        echo "try:" >> pset.py
        echo "    process.source.firstEvent = cms.untracked.uint32(${FIRSTEVT})" >> pset.py
        echo "except: pass" >> pset.py
    fi
}
function stageout {
    COPY_SRC=$1
    COPY_DEST=$2
    retries=0
    COPY_STATUS=1
    until [ $retries -ge 3 ]
    do
        echo "Stageout attempt $((retries+1)): env -i X509_USER_PROXY=${X509_USER_PROXY} gfal-copy -p -f -t 7200 --verbose --checksum ADLER32 ${COPY_SRC} ${COPY_DEST}"
        env -i X509_USER_PROXY=${X509_USER_PROXY} gfal-copy -p -f -t 7200 --verbose --checksum ADLER32 ${COPY_SRC} ${COPY_DEST}
        COPY_STATUS=$?
        if [ $COPY_STATUS -ne 0 ]; then
            echo "Failed stageout attempt $((retries+1))"
        else
            echo "Successful stageout with $retries retries"
            break
        fi
        retries=$[$retries+1]
        echo "Sleeping for 30m"
        sleep 30m
    done
    if [ $COPY_STATUS -ne 0 ]; then
        echo "Removing output file because gfal-copy crashed with code $COPY_STATUS"
        env -i X509_USER_PROXY=${X509_USER_PROXY} gfal-rm --verbose ${COPY_DEST}
        REMOVE_STATUS=$?
        if [ $REMOVE_STATUS -ne 0 ]; then
            echo "Uhh, gfal-copy crashed and then the gfal-rm also crashed with code $REMOVE_STATUS"
            echo "You probably have a corrupt file sitting on hadoop now."
            exit 1
        fi
    fi
}

setup_chirp

echo -e "\n--- begin header output ---\n" #                     <----- section division
echo "OUTPUTDIR: $OUTPUTDIR"
echo "OUTPUTNAME: $OUTPUTNAME"
echo "INPUTFILENAMES: $INPUTFILENAMES"
echo "IFILE: $IFILE"
echo "PSET: $PSET"
echo "CMSSWVERSION: $CMSSWVERSION"
echo "SCRAMARCH: $SCRAMARCH"
echo "NEVTS: $NEVTS"
echo "EXPECTEDNEVTS: $EXPECTEDNEVTS"
echo "OTHEROUTPUTS: $OTHEROUTPUTS"
echo "PSETARGS: $PSETARGS"
# echo  CLASSAD: $(cat "$_CONDOR_JOB_AD")

echo "GLIDEIN_CMSSite: $GLIDEIN_CMSSite"
echo "hostname: $(hostname)"
echo "uname -a: $(uname -a)"
echo "time: $(date +%s)"
echo "args: $@"
echo "tag: $(getjobad tag)"
echo "taskname: $(getjobad taskname)"

echo -e "\n--- end header output ---\n" #                       <----- section division

if [ -r "$OSGVO_CMSSW_Path"/cmsset_default.sh ]; then
    echo "sourcing environment: source $OSGVO_CMSSW_Path/cmsset_default.sh"
    source "$OSGVO_CMSSW_Path"/cmsset_default.sh
elif [ -r "$OSG_APP"/cmssoft/cms/cmsset_default.sh ]; then
    echo "sourcing environment: source $OSG_APP/cmssoft/cms/cmsset_default.sh"
    source "$OSG_APP"/cmssoft/cms/cmsset_default.sh
elif [ -r /cvmfs/cms.cern.ch/cmsset_default.sh ]; then
    echo "sourcing environment: source /cvmfs/cms.cern.ch/cmsset_default.sh"
    source /cvmfs/cms.cern.ch/cmsset_default.sh
else
    echo "ERROR! Couldn't find $OSGVO_CMSSW_Path/cmsset_default.sh or /cvmfs/cms.cern.ch/cmsset_default.sh or $OSG_APP/cmssoft/cms/cmsset_default.sh"
    exit 1
fi

# holy crap this is a mess. :( why does PAT code have to do such insane
# things with paths?
# if the first file in the tarball filelist starts with CMSSW, then it is
# a tarball made outside of the full CMSSW directory, and must be handled
# differently
tarfile=package.tar.gz
if [ ! -z $(tar -tf ${tarfile} | head -n 1 | grep "^CMSSW") ]; then
    echo "this is a full cmssw tar file"
    tar xf ${tarfile}
    cd $CMSSWVERSION
    echo $PWD
    echo "Running ProjectRename"
    scramv1 b ProjectRename
    echo "Running `scramv1 runtime -sh`"
    eval `scramv1 runtime -sh`
    mv ../$PSET pset.py
    mv ../${tarfile} .
else
    echo "this is a selective cmssw tar file"
    eval `scramv1 project CMSSW $CMSSWVERSION`
    cd $CMSSWVERSION
    eval `scramv1 runtime -sh`
    mv ../$PSET pset.py
    if [ -e ../${tarfile} ]; then
        mv ../${tarfile} ${tarfile};
        tar xf ${tarfile};
    fi
    scram b
    [ -e package.tar.gz ] && tar xf package.tar.gz
    # Needed or else cmssw can't find libmcfm_705.so
    # export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${CMSSW_BASE}/src/ZZMatrixElement/MELA/data/${SCRAM_ARCH}
    # This is nicer than above. both work, and both have scary but benign warnings/printouts
    cp ${CMSSW_BASE}/src/ZZMatrixElement/MELA/data/${SCRAM_ARCH}/*.so ${CMSSW_BASE}/lib/${SCRAM_ARCH}/
    # "Needed" to get rid of benign warnings/printouts
    export ROOT_INCLUDE_PATH=${ROOT_INCLUDE_PATH}:${CMSSW_BASE}/src/ZZMatrixElement/MELA/interface
fi

# # logging every 45 seconds gives ~100kb log file/3 hours
# dstat -cdngytlmrs --float --nocolor -T --output dsout.csv 180 >& /dev/null &


echo "before running: ls -lrth"
ls -lrth

echo -e "\n--- begin running ---\n" #                           <----- section division

chirp ChirpMetisExpectedNevents $EXPECTEDNEVTS

chirp ChirpMetisStatus "before_cmsRun"

edit_pset

cmsRun pset.py ${PSETARGS}
CMSRUN_STATUS=$?

chirp ChirpMetisStatus "after_cmsRun"

echo "after running: ls -lrth"
ls -lrth

if [[ $CMSRUN_STATUS != 0 ]]; then
    echo "Removing output file because cmsRun crashed with exit code $?"
    rm ${OUTPUTNAME}.root
    exit 1
fi


if [ -z "$(getjobad metis_dontchecktree)" ]; then

    # Add some metadata
    # Right now, total/negative event counts, but obviously extensible
    python << EOL
import ROOT as r
fin = r.TFile("${OUTPUTNAME}.root","update")
t = fin.Get("Events")
t.GetUserInfo().Clear()
nevts = t.GetEntries()
nevts_neg = nevts - t.GetEntries("genps_weight > 0")
evts = r.TParameter(int)("nevts", nevts)
evts_neg = r.TParameter(int)("nevts_neg", nevts_neg)
print "Writing metadata. Nevents = {0} ({1} negative)".format(nevts, nevts_neg)
t.GetUserInfo().Add(evts)
t.GetUserInfo().Add(evts_neg)
t.Write("",r.TObject.kOverwrite)
t.GetUserInfo().Print()
EOL

    # Rigorous sweeproot which checks ALL branches for ALL events.
    # If GetEntry() returns -1, then there was an I/O problem, so we will delete it
    # Special consideration to ignore stupid CMSSW errors and old root versions
    python << EOL
import ROOT as r
import os
import traceback
foundBad = False
try:
    f1 = r.TFile("${OUTPUTNAME}.root")
    t = f1.Get("Events")
    nevts = t.GetEntries()
    expectednevts = ${EXPECTEDNEVTS}
    print "[RSR] ntuple has %i events and expected %i" % (t.GetEntries(), expectednevts)
    if int(expectednevts) > 0 and int(t.GetEntries()) != int(expectednevts):
        print "[RSR] nevents mismatch"
        foundBad = True
    if not "root/5.3" in r.__file__:
        for i in range(0,t.GetEntries(),1):
            if t.GetEntry(i) < 0:
                foundBad = True
                print "[RSR] found bad event %i" % i
                break
except Exception as ex:
    msg = traceback.format_exc()
    if "EDProductGetter" not in msg:
        foundBad = True
if foundBad:
    print "[RSR] removing output file because it does not deserve to live"
    os.system("rm ${OUTPUTNAME}.root")
else: print "[RSR] passed the rigorous sweeproot"
EOL

    if [ "$?" != "0" ]; then
        echo "Removing output file because sweeproot crashed with exit code $?"
        rm ${OUTPUTNAME}.root
        exit 1
    fi

else
    echo "Not checking tree or adding metadata";
fi

echo -e "\n--- end running ---\n" #                             <----- section division

echo -e "\n--- begin copying output ---\n" #                    <----- section division

echo "Sending output file $OUTPUTNAME.root"

if [ ! -e "$OUTPUTNAME.root" ]; then
    echo "ERROR! Output $OUTPUTNAME.root doesn't exist"
    exit 1
fi

echo "time before copy: $(date +%s)"
chirp ChirpMetisStatus "before_copy"

COPY_SRC="file://`pwd`/${OUTPUTNAME}.root"
COPY_DEST="gsiftp://gftp.t2.ucsd.edu${OUTPUTDIR}/${OUTPUTNAME}_${IFILE}.root"
stageout $COPY_SRC $COPY_DEST

for OTHEROUTPUT in $(echo "$OTHEROUTPUTS" | sed -n 1'p' | tr ',' '\n'); do
    [ -e ${OTHEROUTPUT} ] && {
        NOROOT=$(echo $OTHEROUTPUT | sed 's/\.root//')
        COPY_SRC="file://`pwd`/${NOROOT}.root"
        COPY_DEST="gsiftp://gftp.t2.ucsd.edu${OUTPUTDIR}/${NOROOT}_${IFILE}.root"
        stageout $COPY_SRC $COPY_DEST
    }
done

echo -e "\n--- end copying output ---\n" #                      <----- section division

echo -e "\n--- begin dstat output ---\n" #                      <----- section division
# cat dsout.csv
echo -e "\n--- end dstat output ---\n" #                        <----- section division

echo "time at end: $(date +%s)"

chirp ChirpMetisStatus "done"

