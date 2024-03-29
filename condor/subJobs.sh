#!/bin/bash

doSubmit=true
listdir=${CMSSW_BASE}/src/B-ParkingLLPs/lists/V1p19_7
path="root://cmsxrootd.fnal.gov/"
#path="root://cmsxrootd.fnal.gov//store/user/aaportel/B-Parking/V1p19_7"

lists=(  \
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

#ctau_values=(1\ 
#               3    5    7    10 \
#               30   50   70   100 \
#               300  500  700  1000 \
#               3000 5000 7000 10000)
#
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

for listName in ${lists[@]}
do
  mkdir -p $listName
  mkdir -p $listName/logs
  cd $listName 
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
  echo $samples_file
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
    printf "Arguments = $thePath $sampleName_ \n" >> submitfile
    printf "Queue\n" >> submitfile
    printf "\n" >> submitfile
  done
  #actually submit
  if [ ${doSubmit} = true ]
  then
    condor_submit submitfile
  fi
  cd ..
done
cd ../..
