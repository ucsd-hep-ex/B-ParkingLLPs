#!/bin/bash

doSubmit=true
path="root://cmsxrootd.fnal.gov//store/user/ddiaz/B-Parking/V1p19_7"

samples=(  \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau300" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau300" \
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
printf "Executable = ../../runJobs_mult_ctau.sh\n" >> submitfile
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

ctau_values=(1\ 
               3    5    7    10 \
               30   50   70   100 \
               300  500  700  1000 \
               3000 5000 7000 10000)

for sample in ${samples[@]}
do
  for ctau in ${ctau_values[@]}
  do
    printf "Arguments = --Path=$path/$sample/ --Sample=$sample --to_ctau=$ctau \n" >> submitfile
    printf "Queue\n" >> submitfile
    printf "\n" >> submitfile
  done
done

if [ ${doSubmit} = true ]
then
 condor_submit submitfile
fi

cd ../..
