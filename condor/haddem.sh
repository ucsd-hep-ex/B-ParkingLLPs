versionName=invertID #DPhi2p8Both #WP3   #MuonVetoPtStudy   #OPT  #ABCD-BothDPhi-tightDPhi
base_dir=${CMSSW_BASE}/src/B-ParkingLLPs/condor/gitignore

Regions=(\
 Fail_plots\
 FailOOT_plots\
 Pass_plots\
 PassOOT_plots\
 nominal_plots\
)

Samples=(\
 ParkingBPH1_2018A\
 ParkingBPH2_2018A\
 ParkingBPH3_2018A\
 ParkingBPH4_2018A\
 ParkingBPH5_2018A\
 ParkingBPH6_2018A\
 ParkingBPH1_2018B\
 ParkingBPH2_2018B\
 ParkingBPH3_2018B\
 ParkingBPH4_2018B\
 ParkingBPH5_2018B\
 ParkingBPH6_2018B\
 ParkingBPH1_2018C\
 ParkingBPH2_2018C\
 ParkingBPH3_2018C\
 ParkingBPH4_2018C\
 ParkingBPH5_2018C\
 ParkingBPH1_2018D\
 ParkingBPH2_2018D\
 ParkingBPH3_2018D\
 ParkingBPH4_2018D\
 ParkingBPH5_2018D\
)
 #ParkingBPH1_2018A\
 #ParkingBPH2_2018A\
 #ParkingBPH3_2018A\
 #ParkingBPH4_2018A\
 #ParkingBPH5_2018A\
 #ParkingBPH6_2018A\
 #ParkingBPH1_2018B\
 #ParkingBPH2_2018B\
 #ParkingBPH3_2018B\
 #ParkingBPH4_2018B\
 #ParkingBPH5_2018B\
 #ParkingBPH6_2018B\
 #ParkingBPH1_2018C\
 #ParkingBPH2_2018C\
 #ParkingBPH3_2018C\
 #ParkingBPH4_2018C\
 #ParkingBPH5_2018C\
 #ParkingBPH1_2018D\
 #ParkingBPH2_2018D\
 #ParkingBPH3_2018D\

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
  printf "hadd ${base_dir}/$versionName/${sample_name}/hadded/${sample_name}_${region_name}.root\\" >> tmp.sh
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
  #rm -f tmp.sh
}


for sample in ${Samples[@]}
do
  rm -rf ${base_dir}/${versionName}/${sample}/hadded
  mkdir -p ${base_dir}/${versionName}/${sample}/hadded
  for region in ${Regions[@]}
  do
    listName="sample_list_$region"
    declare -a "$listName"
    for f in ${base_dir}/${versionName}/${sample}/*${region}*.root
    do
      eval "$listName+=(\"$f\")"
    done
    #Print for debugging 
    #print_array_elements "$listName"
    hadder "$listName" "$sample" "$region"
    unset "$listName"
  done
done
