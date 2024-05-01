#!/bin/bash

doSubmit=true
listdir=${CMSSW_BASE}/src/B-ParkingLLPs/lists/V1p19_9
path="root://cmsxrootd.fnal.gov/"
#path="root://cmsxrootd.fnal.gov//store/user/aaportel/B-Parking/V1p19_7"

lists=(  \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau3000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p5_ctau5000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau10000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau10000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau10000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau3000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau5000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau10000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau10000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau10000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p5_ctau500" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau2000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau3000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau500" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau300" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau2000" \
 "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau3000" \
 "ParkingBPH1_2018A" \
 "ParkingBPH2_2018A" \
 "ParkingBPH3_2018A" \
 "ParkingBPH4_2018A" \
 "ParkingBPH5_2018A" \
 "ParkingBPH6_2018A" \
 "ParkingBPH1_2018B" \
 "ParkingBPH2_2018B" \
 "ParkingBPH3_2018B" \
 "ParkingBPH4_2018B" \
 "ParkingBPH5_2018B" \
 "ParkingBPH6_2018B" \
 "ParkingBPH1_2018C" \
 "ParkingBPH2_2018C" \
 "ParkingBPH3_2018C" \
 "ParkingBPH4_2018C" \
 "ParkingBPH5_2018C" \
 "ParkingBPH1_2018D" \
 "ParkingBPH2_2018D" \
 "ParkingBPH3_2018D" \
 "ParkingBPH4_2018D" \
 "ParkingBPH5_2018D" \
)

#--High ctau List------
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau3000" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p5_ctau5000" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau10000" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau10000" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau10000" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau3000" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau5000" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau10000" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau10000" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau10000" \


#-- Low ctau List ---
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p5_ctau500" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau300" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau2000" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau3000" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau500" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau300" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau2000" \
# "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau3000" \


#-- All ---
# "ParkingBPH1_2018A" \
# "ParkingBPH2_2018A" \
# "ParkingBPH3_2018A" \
# "ParkingBPH4_2018A" \
# "ParkingBPH5_2018A" \
# "ParkingBPH6_2018A" \
# "ParkingBPH1_2018B" \
# "ParkingBPH2_2018B" \
# "ParkingBPH3_2018B" \
# "ParkingBPH4_2018B" \
# "ParkingBPH5_2018B" \
# "ParkingBPH6_2018B" \
# "ParkingBPH1_2018C" \
# "ParkingBPH2_2018C" \
# "ParkingBPH3_2018C" \
# "ParkingBPH4_2018C" \
# "ParkingBPH5_2018C" \
# "ParkingBPH1_2018D" \
# "ParkingBPH2_2018D" \
# "ParkingBPH3_2018D" \
# "ParkingBPH4_2018D" \
# "ParkingBPH5_2018D" \

ctau_values=(1\ 
               3    5    7    10 \
               30   50   70   100 \
               300  500  700  1000 \
               3000 5000 7000 10000 \
)

#compile analyzer
pushd ../analysis/
make clean; make 
popd
echo ""
read -p $'\e[1;31m Please provide a version name for these jobs: \e[0m' vName

mkdir -p gitignore/$vName

cd gitignore/$vName
cp ../../../analysis/RunAnalyzer.exe .
setUp="./setup.C"
grep -h "loggit" ../../../analysis/app/* >> ${setUp}


prep_and_submit(){
  local listName=$1
  local ctau=${2:-}
  Name=$listName
  if [ -n "$ctau" ]; then
    Name=${listName}_to_${ctau}
  fi
  
  mkdir -p $Name
  mkdir -p $Name/logs
  cd $Name 
  # write base for submit file
  printf "universe = vanilla\n" > submitfile
  printf "Executable = ${CMSSW_BASE}/src/B-ParkingLLPs/condor/runJobs.sh\n" >> submitfile
  printf "Should_Transfer_Files = YES \n" >> submitfile
  printf "WhenToTransferOutput = ON_EXIT\n" >> submitfile
  printf "Transfer_Input_Files = ../RunAnalyzer.exe\n" >> submitfile
  
  printf "notify_user = $(whoami)@cern.ch\n" >> submitfile
  printf "x509userproxy = $X509_USER_PROXY\n" >> submitfile
  printf "\n" >> submitfile
  printf "Output = logs/runanalyzer_\$(Cluster)_\$(Process).stdout\n" >> submitfile
  printf "Error  = logs/runanalyzer_\$(Cluster)_\$(Process).stderr\n" >> submitfile
  printf "Log    = logs/runanalyzer_\$(Cluster)_\$(Process).log\n" >> submitfile
  printf "\n" >> submitfile
  samples_file=${listdir}/${listName}.list
  if [ -n "$ctau" ]; then
    echo $samples_file to $ctau
  else
    echo $samples_file
  fi
  if [ -e "$samples_file" ]; then
    # Read sample entries from the file and store them in an array
    mapfile -t samples < "$samples_file"
  else
    echo "Error: The samples file '$samples_file' does not exist."
    exit 1
  fi  
  #Now loop over individual entries
  for sample in ${samples[@]}
  do
    # Remove leading and trailing whitespace (if any)
    sample="${sample#"${sample%%[![:space:]]*}"}"
    sample="${sample%"${sample##*[![:space:]]}"}"
    # Check if the line is not empty
    if [ -n "$sample" ]; then
      # Use parameter expansion to extract the path and filename
      path_="${sample%/*}/"
      sampleName_="${sample##*/}"
      thePath="${path}${path_}"
    fi 
    if [ -n "$ctau" ]; then 
      printf "Arguments = $thePath $sampleName_ $ctau\n" >> submitfile
    else
      printf "Arguments = $thePath $sampleName_ "" \n" >> submitfile
    fi
    printf "Queue\n" >> submitfile
    printf "\n" >> submitfile
  done
  #actually submit
  if [ ${doSubmit} = true ]
  then
    condor_submit submitfile
  fi
  cd ..
}

##----------------------------------------Main
for listName in ${lists[@]}
do
  if [[ $listName == *"Parking"* ]]; then
    prep_and_submit "$listName"
  else
    for ctau in ${ctau_values[@]}
    do
      prep_and_submit "$listName" "$ctau"
    done
  fi
done
cd ../..
