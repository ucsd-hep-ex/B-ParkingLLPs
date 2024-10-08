#############################################################################
# Use this to hadd the results of the fakeRate code when executing via condor
#############################################################################

versionName=${version}
base_dir=${CMSSW_BASE}/src/B-ParkingLLPs/condor/gitignore

Regions=(\
 "_"\
)

Samples=(\
 EGamma_2018A\
 EGamma_2018B\
 EGamma_2018C\
 EGamma_2018D\
 SingleMuon_2018A\
 SingleMuon_2018B\
 SingleMuon_2018C\
 SingleMuon_2018D\
 SingleMuon_2017B\
 SingleMuon_2017C\
 SingleMuon_2017D\
 SingleMuon_2017E\
 SingleMuon_2017F\
 SingleMuon_2017G\
 SingleMuon_2017H\
 SingleElectron_2017B\
 SingleElectron_2017C_v2\
 SingleElectron_2017D\
 SingleElectron_2017E\
 SingleElectron_2017F\
 SingleElectron_2017G\
 SingleElectron_2017H\
 SingleMuon_2016B\
 SingleMuon_2016C\
 SingleMuon_2016D\
 SingleMuon_2016E\
 SingleMuon_2016F\
 SingleMuon_2016G\
 SingleMuon_2016H\
 SingleElectron_2016B_v2\
 SingleElectron_2016C\
 SingleElectron_2016D\
 SingleElectron_2016E\
 SingleElectron_2016F\
 SingleElectron_2016G\
 SingleElectron_2016H\
)
print_array_elements(){
  local array_name="$1"
  echo ${array_name}
  eval "echo \"\${$array_name[@]}\""
}

hadder(){
  local file_names="$1"
  local sample_name="$2"
  local region_name="$3"
 
  eval "local -a files=(\"\${$file_names[@]}\")"
  list_size="${#files[@]}"
  touch tmp.sh
  printf "#!/bin/bash\n\n" > tmp.sh
  iter=0
  haddnr=0
  printf "hadd ${base_dir}/$versionName/${sample_name}/${sample_name}_${region_name}-hadd${haddnr}.root\\" >> tmp.sh
  for f in "${files[@]}"
  do
    if [ $((${iter}%191)) == 0 ] && [ ${iter} -ne 0 ]
    then
      ###Avoid trying to hadd one file
      if [ ${iter} -ne $((${list_size}-1)) ]
      then
        haddnr=$(( ${haddnr} + 1 ))
        printf "\n\n" >> tmp.sh
        printf "hadd ${base_dir}/$versionName/${sample_name}/${sample_name}_${region_name}-hadd${haddnr}.root\\" >> tmp.sh
      fi
    fi
    printf "\n ${f}\\"     >>       tmp.sh
    iter=$(( ${iter} + 1 ))
  done
  printf "\n\n" >> tmp.sh
  printf "##--Now Merge the final file \n" >> tmp.sh
  printf "hadd ${base_dir}/$versionName/${sample_name}/hadded/${sample_name}.root\\" >> tmp.sh
  iter2=0
  if [ $haddnr -gt 0 ]
  then
    until [ $iter2 -gt $haddnr ]
    do
      printf "\n ${base_dir}/$versionName/${sample_name}/${sample_name}_${region_name}-hadd${iter2}.root\\" >> tmp.sh
      iter2=$(( ${iter2} + 1 ))
    done
  else
    printf "\n ${base_dir}/$versionName/${sample_name}/${sample_name}_${region_name}-hadd${iter2}.root\\" >>tmp.sh
  fi
  
  bash tmp.sh
  echo $file_names
  echo $sample_name
  echo $region_name
  rm -f tmp.sh
}


for sample in ${Samples[@]}
do
  rm -rf ${base_dir}/${versionName}/${sample}/hadded
  mkdir -p ${base_dir}/${versionName}/${sample}/hadded
  for region in ${Regions[@]}
  do
    listName="sample_list_$region"
    declare -a "$listName"
    for f in ${base_dir}/${versionName}/${sample}/*histos*.root
    do
      eval "$listName+=(\"$f\")"
    done
    #Print for debugging 
    #print_array_elements "$listName"
    hadder "$listName" "$sample" "$region"
    unset "$listName"
  done
done
