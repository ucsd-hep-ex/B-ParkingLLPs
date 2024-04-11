#!/bin/bash

export PATH=${PATH}:/cvmfs/cms.cern.ch/common
export CMS_PATH=/cvmfs/cms.cern.ch

export SCRAM_ARCH=slc7_amd64_gcc630
scramv1 project CMSSW CMSSW_9_4_4
cd CMSSW_9_4_4/src
scramv1 build -j 10
eval `scramv1 runtime -sh` # cmsenv
cd ../../

hostname
echo make an ls
ls
source /cvmfs/cms.cern.ch/cmsset_default.sh

echo " "
echo pwd and ls
echo " "
pwd
ls

mkdir roots


./RunAnalyzer.exe --Path=$1 --Sample=$2 --to_ctau=$3

mv roots/*.root .
ls
