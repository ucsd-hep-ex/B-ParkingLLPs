#!/bin/bash

doSubmit=true
path="root://cmsxrootd.fnal.gov//store/user/ddiaz/B-Parking/V1p19_7"

samples=(  \
"BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300" \
"ParkingBPH4_2018A" \
)

#compile analyzer
pushd ../analysis/
make clean; make 
popd
echo ""
read -p $'\e[1;31m Please provide a version name for these jobs: \e[0m' vName

mkdir -p gitignore/$vName
mkdir -p gitignore/$vName/logs

cd gitignore/$vName
cp ../../../analysis/RunAnalyzer.exe .
setUp="./setup.C"
grep -h "loggit" ../../../analysis/app/* >> ${setUp}

# write base for submit file
printf "universe = vanilla\n" > submitfile
printf "Executable = ../../runJobs.sh\n" >> submitfile
printf "Should_Transfer_Files = YES \n" >> submitfile
printf "WhenToTransferOutput = ON_EXIT\n" >> submitfile
printf "Transfer_Input_Files = RunAnalyzer.exe\n" >> submitfile

printf "notify_user = $(whoami)@cern.ch\n" >> submitfile
printf "x509userproxy = $X509_USER_PROXY\n" >> submitfile
printf "\n" >> submitfile
printf "Output = logs/runanalyzer_\$(Cluster)_\$(Process).stdout\n" >> submitfile
printf "Error  = logs/runanalyzer_\$(Cluster)_\$(Process).stderr\n" >> submitfile
printf "Log    = logs/runanalyzer_\$(Cluster)_\$(Process).log\n" >> submitfile
printf "\n" >> submitfile


for sample in ${samples[@]}
do
  printf "Arguments = $path/$sample/ $sample \n" >> submitfile
  printf "Queue\n" >> submitfile
  printf "\n" >> submitfile
done

if [ ${doSubmit} = true ]
then
 condor_submit submitfile
fi

cd ../..
