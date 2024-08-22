###############################################
# Use this after haddem.sh to add the DataFiles 
###############################################

versionName=$version
base_dir=${CMSSW_BASE}/src/B-ParkingLLPs/condor/gitignore

Regions=(\
)
# "_"\
# Fail_plots\
# FailOOT_plots\
# Pass_plots\
# PassOOT_plots\
# nominal_plots\
# nominalPlusTime_plots\
# PassCS_plots\
# FailCS_plots\


for reg in ${Regions[@]}
do
  printf "hadd ${base_dir}/${versionName}/Parking_2018_${reg}.root\\" >tmp.sh
#  printf "hadd ${base_dir}/${versionName}/Parking_2018A_${reg}.root\\" >tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH1_2018A/hadded/ParkingBPH1_2018A_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH2_2018A/hadded/ParkingBPH2_2018A_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH3_2018A/hadded/ParkingBPH3_2018A_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH4_2018A/hadded/ParkingBPH4_2018A_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH5_2018A/hadded/ParkingBPH5_2018A_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH6_2018A/hadded/ParkingBPH6_2018A_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH1_2018B/hadded/ParkingBPH1_2018B_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH2_2018B/hadded/ParkingBPH2_2018B_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH3_2018B/hadded/ParkingBPH3_2018B_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH4_2018B/hadded/ParkingBPH4_2018B_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH5_2018B/hadded/ParkingBPH5_2018B_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH6_2018B/hadded/ParkingBPH6_2018B_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH1_2018C/hadded/ParkingBPH1_2018C_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH2_2018C/hadded/ParkingBPH2_2018C_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH3_2018C/hadded/ParkingBPH3_2018C_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH4_2018C/hadded/ParkingBPH4_2018C_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH5_2018C/hadded/ParkingBPH5_2018C_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH1_2018D/hadded/ParkingBPH1_2018D_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH2_2018D/hadded/ParkingBPH2_2018D_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH3_2018D/hadded/ParkingBPH3_2018D_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH4_2018D/hadded/ParkingBPH4_2018D_${reg}.root\\" >>tmp.sh
  printf "\n ${base_dir}/${versionName}/ParkingBPH5_2018D/hadded/ParkingBPH5_2018D_${reg}.root\\" >>tmp.sh

  bash tmp.sh
done
