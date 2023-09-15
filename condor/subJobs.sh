#!/bin/bash

doSubmit=true
path="root://cmsxrootd.fnal.gov//store/user/ddiaz/B-Parking/V1p19_7"
#path="root://cmsxrootd.fnal.gov//store/user/aaportel/B-Parking/V1p19_7"

samples=(  \
"ParkingBPH1_2018B" \
"ParkingBPH2_2018B" \
#"ParkingBPH1_2018C" \
#"ParkingBPH2_2018C" \
#"ParkingBPH3_2018C" \
#"ParkingBPH4_2018C" \
#"ParkingBPH5_2018C" \
#"ParkingBPH1_2018A" \
#"ParkingBPH2_2018A" \
#"ParkingBPH3_2018A" \
#"ParkingBPH4_2018A" \
#"ParkingBPH5_2018A" \
#"ParkingBPH6_2018A" \
#"ParkingBPH3_2018B" \
#"ParkingBPH4_2018B" \
#"ParkingBPH5_2018B" \
#"ParkingBPH6_2018B" \
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300" \
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000" \
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau300" \
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300" \
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000" \
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau300" \
#"ParkingBPH1_2018A" \
#"ParkingBPH2_2018A" \
#"ParkingBPH3_2018A" \
#"ParkingBPH4_2018A" \
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300" \
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
