###########################################################################
# Use this to hadd the fakeRate files when they have been created in condor
###########################################################################

versionName=$version
base_dir=${CMSSW_BASE}/src/B-ParkingLLPs/condor/gitignore

printf "hadd ${base_dir}/${versionName}/EGamma_2018.root\\" >tmp.sh
printf "\n ${base_dir}/${versionName}/EGamma_2018A/hadded/EGamma_2018A.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/EGamma_2018B/hadded/EGamma_2018B.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/EGamma_2018C/hadded/EGamma_2018C.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/EGamma_2018D/hadded/EGamma_2018D.root\\" >>tmp.sh
bash tmp.sh
rm tmp.sh

printf "hadd ${base_dir}/${versionName}/SingleMuon_2018.root\\" >tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2018A/hadded/SingleMuon_2018A.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2018B/hadded/SingleMuon_2018B.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2018C/hadded/SingleMuon_2018C.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2018D/hadded/SingleMuon_2018D.root\\" >>tmp.sh
bash tmp.sh
rm tmp.sh



printf "hadd ${base_dir}/${versionName}/SingleMuon_2017.root\\" >tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2017B/hadded/SingleMuon_2017B.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2017C/hadded/SingleMuon_2017C.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2017D/hadded/SingleMuon_2017D.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2017E/hadded/SingleMuon_2017E.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2017F/hadded/SingleMuon_2017F.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2017G/hadded/SingleMuon_2017G.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2017H/hadded/SingleMuon_2017H.root\\" >>tmp.sh
bash tmp.sh
rm tmp.sh

printf "hadd ${base_dir}/${versionName}/SingleElectron_2017.root\\" >tmp.sh
printf "\n ${base_dir}/${versionName}/SingleElectron_2017B/hadded/SingleElectron_2017B.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleElectron_2017C_v2/hadded/SingleElectron_2017C_v2.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleElectron_2017D/hadded/SingleElectron_2017D.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleElectron_2017E/hadded/SingleElectron_2017E.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleElectron_2017F/hadded/SingleElectron_2017F.root\\" >>tmp.sh
#printf "\n ${base_dir}/${versionName}/SingleElectron_2017G/hadded/SingleElectron_2017G.root\\" >>tmp.sh
#printf "\n ${base_dir}/${versionName}/SingleElectron_2017H/hadded/SingleElectron_2017H.root\\" >>tmp.sh
bash tmp.sh
rm tmp.sh



printf "hadd ${base_dir}/${versionName}/SingleMuon_2016.root\\" >tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2016B/hadded/SingleMuon_2016B.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2016C/hadded/SingleMuon_2016C.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2016D/hadded/SingleMuon_2016D.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2016E/hadded/SingleMuon_2016E.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2016F/hadded/SingleMuon_2016F.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2016G/hadded/SingleMuon_2016G.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2016H/hadded/SingleMuon_2016H.root\\" >>tmp.sh
bash tmp.sh
rm tmp.sh

printf "hadd ${base_dir}/${versionName}/SingleElectron_2016.root\\" >tmp.sh
printf "\n ${base_dir}/${versionName}/SingleElectron_2016B_v2/hadded/SingleElectron_2016B_v2.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleElectron_2016C/hadded/SingleElectron_2016C.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleElectron_2016D/hadded/SingleElectron_2016D.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleElectron_2016E/hadded/SingleElectron_2016E.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleElectron_2016F/hadded/SingleElectron_2016F.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleElectron_2016G/hadded/SingleElectron_2016G.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleElectron_2016H/hadded/SingleElectron_2016H.root\\" >>tmp.sh
bash tmp.sh
rm tmp.sh


printf "hadd ${base_dir}/${versionName}/SingleElectron.root\\" >tmp.sh
printf "\n ${base_dir}/${versionName}/SingleElectron_2016.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleElectron_2017.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/EGamma_2018.root\\" >>tmp.sh
bash tmp.sh
rm tmp.sh

printf "hadd ${base_dir}/${versionName}/SingleMuon.root\\" >tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2016.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2017.root\\" >>tmp.sh
printf "\n ${base_dir}/${versionName}/SingleMuon_2018.root\\" >>tmp.sh
bash tmp.sh
rm tmp.sh


hadd ${base_dir}/${versionName}/Run2.root ${base_dir}/${versionName}/SingleMuon.root ${base_dir}/${versionName}/SingleElectron.root

