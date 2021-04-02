#!/bin/bash

echo "*********************************"
echo "*                               *"
echo "*                               *"
echo "* doVVVAnalysis Production Test *"
echo "*                               *"
echo "*                               *"
echo "*********************************"

TESTWWWNANO=/hadoop/cms/store/group/snt/nanoaod/mc/RunIIAutumn18NanoAODv6/WWW_4F_TuneCP5_13TeV-amcatnlo-pythia8/NANOAODSIM/Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1/40000/C6F0D303-3547-FC48-BB23-7F358947B577.root
TESTWWZNANO=/hadoop/cms/store/group/snt/nanoaod/mc/RunIIAutumn18NanoAODv6/WWZ_TuneCP5_13TeV-amcatnlo-pythia8/NANOAODSIM/Nano25Oct2019_102X_upgrade2018_realistic_v20_ext1-v1/250000/48CCBB58-ABA5-7B44-9F03-57CB9707ACF0.root

rm -rf testdir/
mkdir -p testdir/

rm -f .testjobsnano.txt
for i in $(seq 0 7); do
    echo "./doVVVAnalysis -n 50000 -i ${TESTWWWNANO} -t Events -o testdir/www_${i}.root -m ${i} -w > testdir/www_${i}.log 2>&1" >> .testjobsnano.txt
    echo "./doVVVAnalysis -n 50000 -i ${TESTWWZNANO} -t Events -o testdir/wwz_${i}.root -m ${i} -w > testdir/wwz_${i}.log 2>&1" >> .testjobsnano.txt
done

xargs.sh .testjobsnano.txt

rm -f .testjobsskim.txt
for i in $(seq 0 7); do
    echo "./doVVVAnalysis -V -n 50000 -i testdir/www_${i}.root -t t -o testdir/www_common_${i}.root -m ${i} -w > testdir/www_common_${i}.log 2>&1" >> .testjobsskim.txt
    echo "./doVVVAnalysis -V -n 50000 -i testdir/wwz_${i}.root -t t -o testdir/wwz_common_${i}.root -m ${i} -w > testdir/wwz_common_${i}.log 2>&1" >> .testjobsskim.txt
done

xargs.sh .testjobsskim.txt
