#!/bin/bash

export PATH=${PATH}:/cvmfs/cms.cern.ch/common
export CMS_PATH=/cvmfs/cms.cern.ch

export X509_CERT_DIR=/cvmfs/grid.cern.ch/etc/grid-security/certificates/

export SCRAM_ARCH=el9_amd64_gcc12
scramv1 project CMSSW CMSSW_14_0_6_patch1
cd CMSSW_14_0_6_patch1/src
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
cd roots
if [[ "$2" =~ _([0-9]+)$ ]]; then
  index="${BASH_REMATCH[1]}"
else
  index=""
fi
mv Jets.root Jets_${index}.root
cd .. 
mv roots/*.root .
ls
