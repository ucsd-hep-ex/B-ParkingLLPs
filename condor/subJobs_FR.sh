#!/bin/bash
##########################################
# Use to submit jobs for the fakeRate code
##########################################

doSubmit=true
listdir=${CMSSW_BASE}/src/B-ParkingLLPs/lists/FR
path="root://cmsxrootd.fnal.gov/"
filesPerJob=20
maxJobs=-1
padding=7
#path="root://cmsxrootd.fnal.gov//store/user/aaportel/B-Parking/V1p19_7"

lists=(  \
 "EGamma_2018A" \
 "EGamma_2018B" \
 "EGamma_2018C" \
 "EGamma_2018D" \
 "SingleElectron_2016B_v2" \
 "SingleElectron_2016C" \
 "SingleElectron_2016D" \
 "SingleElectron_2016E" \
 "SingleElectron_2016F" \
 "SingleElectron_2016G" \
 "SingleElectron_2016H" \
 "SingleElectron_2017B" \
 "SingleElectron_2017C_v2" \
 "SingleElectron_2017D" \
 "SingleElectron_2017E" \
 "SingleElectron_2017F" \
 "SingleElectron_2017G" \
 "SingleElectron_2017H" \
 "SingleMuon_2016B" \
 "SingleMuon_2016C" \
 "SingleMuon_2016D" \
 "SingleMuon_2016E" \
 "SingleMuon_2016F" \
 "SingleMuon_2016G" \
 "SingleMuon_2016H" \
 "SingleMuon_2017B" \
 "SingleMuon_2017C" \
 "SingleMuon_2017D" \
 "SingleMuon_2017E" \
 "SingleMuon_2017F" \
 "SingleMuon_2017G" \
 "SingleMuon_2017H" \
 "SingleMuon_2018A" \
 "SingleMuon_2018B" \
 "SingleMuon_2018C" \
 "SingleMuon_2018D" \
)

# "SingleElectron_2016B_v2" \
# "SingleElectron_2016C" \
# "SingleElectron_2016D" \
# "SingleElectron_2016E" \
# "SingleElectron_2016F" \
# "SingleElectron_2016G" \
# "SingleElectron_2016H" \
# "SingleElectron_2017B" \
# "SingleElectron_2017C_v2" \
# "SingleElectron_2017D" \
# "SingleElectron_2017E" \
# "SingleElectron_2017F" \
# "SingleElectron_2017G" \
# "SingleElectron_2017H" \
# "EGamma_2018A" \
# "EGamma_2018B" \
# "EGamma_2018C" \
# "EGamma_2018D" \
# "SingleMuon_2016B" \
# "SingleMuon_2016C" \
# "SingleMuon_2016D" \
# "SingleMuon_2016E" \
# "SingleMuon_2016F" \
# "SingleMuon_2016G" \
# "SingleMuon_2016H" \
# "SingleMuon_2017B" \
# "SingleMuon_2017C" \
# "SingleMuon_2017D" \
# "SingleMuon_2017E" \
# "SingleMuon_2017F" \
# "SingleMuon_2017G" \
# "SingleMuon_2017H" \
# "SingleMuon_2018A" \
# "SingleMuon_2018B" \
# "SingleMuon_2018C" \
# "SingleMuon_2018D" \


#compile
pushd ../fakeRate/
make clean; make 
popd
echo ""
read -p $'\e[1;31m Please provide a version name for these jobs: \e[0m' vName

mkdir -p gitignore/$vName

cd gitignore/$vName
cp ../../../fakeRate/RunfakeRate.exe .
cp ../../../fakeRate/*JSON*.txt .

prep_and_submit(){
  local listName=$1
  Name=$listName
  #--count number of jobs
  nlines=`cat ${listdir}/${Name}.list | wc -l`
  njobs1=$((nlines/filesPerJob))
  njobs2=$((nlines%filesPerJob))
  if [ $njobs2 -gt 0 ]; then
    njobs=$((njobs1+1))
  else  
    njobs=$((njobs1))
  fi

  if [ $maxJobs -eq -1 ]; then 
    nTotalJobs=$((njobs))
  elif [ $maxJobs -lt $njobs ]; then
    nTotalJobs=$maxJobs
  else
    nTotalJobs=$((nTotalJobs+njobs))
  fi
  echo Total number of jobs for $Name : $nTotalJobs

  # Proceed to split and submit
  mkdir -p $Name
  mkdir -p $Name/logs
  cd $Name 
  # breaking up input file list
  split -l $filesPerJob -d -a $padding --additional-suffix=.txt $listdir/${Name}.list ${Name}"_"
  mkdir -p lists
  mv *.txt lists/
  tar -zcf lists.tgz lists
 
  # write base for submit file
  printf "universe = vanilla\n" > submitfile
  printf "Executable = ${CMSSW_BASE}/src/B-ParkingLLPs/condor/runJobs_FR.sh\n" >> submitfile
  printf "Should_Transfer_Files = YES \n" >> submitfile
  printf "WhenToTransferOutput = ON_EXIT\n" >> submitfile
  printf "Transfer_Input_Files = ../RunfakeRate.exe, lists.tgz, ../Cert_271036-284044_13TeV_ReReco_07Aug2017_Collisions16_JSON.txt, ../Cert_294927-306462_13TeV_EOY2017ReReco_Collisions17_JSON_v1.txt, ../Cert_314472-325175_13TeV_17SeptEarlyReReco2018ABC_PromptEraD_Collisions18_JSON.txt, ../All_JSON.txt \n" >> submitfile
  
  printf "notify_user = $(whoami)@cern.ch\n" >> submitfile
  printf "x509userproxy = $X509_USER_PROXY\n" >> submitfile
  printf "\n" >> submitfile
  printf "Output = logs/runFR_\$(Cluster)_\$(Process).stdout\n" >> submitfile
  printf "Error  = logs/runFR_\$(Cluster)_\$(Process).stderr\n" >> submitfile
  printf "Log    = logs/runFR_\$(Cluster)_\$(Process).log\n" >> submitfile
  printf "\n" >> submitfile
  
  jobnrlow=0
  jobnr=0
  until [ ${jobnrlow} -ge ${nTotalJobs} ]; do
    index=$(printf "%0*d" ${padding} ${jobnr})
    samples_file=lists/${Name}"_"${index}.txt
    echo $samples_file
    #Now loop over sampleLists
    printf "Arguments = $samples_file $index\n" >> submitfile
    printf "Queue\n" >> submitfile
    printf "\n" >> submitfile
    # increment filenumber counters
    jobnrlow=$(( ${jobnrlow} + 1 ))
    jobnr=$(( ${jobnr} + 1 ))
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
  prep_and_submit "$listName"
done
cd ../..
