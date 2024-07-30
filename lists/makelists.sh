#!/bin/bash

# Makes a list of files in eos
# then greps through to separate into samples
# 
# output files are xxx/lists/<sample>.list
# formatted as one file per line: /store/group/xxx.root
listdir=${CMSSW_BASE}/src/B-ParkingLLPs/lists

makealist() {
 if grep -q "$1" dir.out; then
   printf "Making %s\n" $1
   fullsamplename=$(grep -i "$2" ${listdir}/allfiles.masterlist)
   printf "%s\n"  ${fullsamplename} > ${listdir}/$1.list
   sed -i -e "s@/eos/uscms@@" ${listdir}/$1.list
   cp ${listdir}/$1.list tmp.list
   awk '{sub(/\.root$/, "", $0); print}' tmp.list > ${listdir}/$1.list
   rm tmp.list
 else
   printf "Skipping %s, not found in dir.out\n" "$1"
 fi
}

# Data
#SingleEle
makealist "SingleElectron_2016B"        "/SingleElectron_2016B_0"
makealist "SingleElectron_2016B_v2"        "/SingleElectron_2016B_v2"
makealist "SingleElectron_2016C"        "/SingleElectron_2016C_"
makealist "SingleElectron_2016D"        "/SingleElectron_2016D_"
makealist "SingleElectron_2016E"        "/SingleElectron_2016E_"
makealist "SingleElectron_2016F"        "/SingleElectron_2016F_"
makealist "SingleElectron_2016G"        "/SingleElectron_2016G_"
makealist "SingleElectron_2016H"        "/SingleElectron_2016H_"

makealist "SingleElectron_2017B"        "/SingleElectron_2017B_"
makealist "SingleElectron_2017C"        "/SingleElectron_2017C_0"
makealist "SingleElectron_2017C_v2"        "/SingleElectron_2017C_v2_"
makealist "SingleElectron_2017D"        "/SingleElectron_2017D_"
makealist "SingleElectron_2017E"        "/SingleElectron_2017E_"
makealist "SingleElectron_2017F"        "/SingleElectron_2017F_"
makealist "SingleElectron_2017G"        "/SingleElectron_2017G_"
makealist "SingleElectron_2017H"        "/SingleElectron_2017H_"

makealist "EGamma_2018A"        "/EGamma_2018A_"
makealist "EGamma_2018B"        "/EGamma_2018B_"
makealist "EGamma_2018C"        "/EGamma_2018C_"
makealist "EGamma_2018D"        "/EGamma_2018D_"
#SingleMu
makealist "SingleMuon_2016B"        "/SingleMuon_2016B_"
makealist "SingleMuon_2016C"        "/SingleMuon_2016C_"
makealist "SingleMuon_2016D"        "/SingleMuon_2016D_"
makealist "SingleMuon_2016E"        "/SingleMuon_2016E_"
makealist "SingleMuon_2016F"        "/SingleMuon_2016F_"
makealist "SingleMuon_2016G"        "/SingleMuon_2016G_"
makealist "SingleMuon_2016H"        "/SingleMuon_2016H_"

makealist "SingleMuon_2017B"        "/SingleMuon_2017B_"
makealist "SingleMuon_2017C"        "/SingleMuon_2017C_"
makealist "SingleMuon_2017D"        "/SingleMuon_2017D_"
makealist "SingleMuon_2017E"        "/SingleMuon_2017E_"
makealist "SingleMuon_2017F"        "/SingleMuon_2017F_"
makealist "SingleMuon_2017G"        "/SingleMuon_2017G_"
makealist "SingleMuon_2017H"        "/SingleMuon_2017H_"

makealist "SingleMuon_2018A"        "/SingleMuon_2018A_"
makealist "SingleMuon_2018B"        "/SingleMuon_2018B_"
makealist "SingleMuon_2018C"        "/SingleMuon_2018C_"
makealist "SingleMuon_2018D"        "/SingleMuon_2018D_"

makealist "ParkingBPH1_2018A"        "/ParkingBPH1_2018A"
makealist "ParkingBPH2_2018A"        "/ParkingBPH2_2018A"
makealist "ParkingBPH3_2018A"        "/ParkingBPH3_2018A"
makealist "ParkingBPH4_2018A"        "/ParkingBPH4_2018A"
makealist "ParkingBPH5_2018A"        "/ParkingBPH5_2018A"
makealist "ParkingBPH6_2018A"        "/ParkingBPH6_2018A"
makealist "ParkingBPH1_2018B"        "/ParkingBPH1_2018B"
makealist "ParkingBPH2_2018B"        "/ParkingBPH2_2018B"
makealist "ParkingBPH3_2018B"        "/ParkingBPH3_2018B"
makealist "ParkingBPH4_2018B"        "/ParkingBPH4_2018B"
makealist "ParkingBPH5_2018B"        "/ParkingBPH5_2018B"
makealist "ParkingBPH6_2018B"        "/ParkingBPH6_2018B"
makealist "ParkingBPH1_2018C"        "/ParkingBPH1_2018C"
makealist "ParkingBPH2_2018C"        "/ParkingBPH2_2018C"
makealist "ParkingBPH3_2018C"        "/ParkingBPH3_2018C"
makealist "ParkingBPH4_2018C"        "/ParkingBPH4_2018C"
makealist "ParkingBPH5_2018C"        "/ParkingBPH5_2018C"
makealist "ParkingBPH1_2018D"        "/ParkingBPH1_2018D"
makealist "ParkingBPH2_2018D"        "/ParkingBPH2_2018D"
makealist "ParkingBPH3_2018D"        "/ParkingBPH3_2018D"
makealist "ParkingBPH4_2018D"        "/ParkingBPH4_2018D"
makealist "ParkingBPH5_2018D"        "/ParkingBPH5_2018D"

## Signal Pi0Pi0
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau3000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau3000/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p5_ctau500"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p5_ctau500/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p5_ctau5000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p5_ctau5000/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau300"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau300/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau10000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau10000/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau2000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau2000/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau10000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau10000/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau3000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau3000/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau10000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau10000/B"
#
#
## Signal Pi+Pi-
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau3000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau3000/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau500"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau500/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau5000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau5000/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau300"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau300/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau10000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau10000/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau2000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau2000/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau10000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau10000/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau3000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau3000/B"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau10000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau10000/B"
