#!/bin/bash

# Makes a list of files in eos
# then greps through to separate into samples
# 
# output files are xxx/lists/<sample>.list
# formatted as one file per line: /store/group/xxx.root
listdir=/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/lists

makealist() {
 printf "Making %s\n" $1
 fullsamplename=$(grep -i "$2" ${listdir}/allfiles.masterlist)
 printf "%s\n"  ${fullsamplename} > ${listdir}/$1.list
 sed -i -e "s@/eos/uscms@@" ${listdir}/$1.list
}

# Data
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

# Signal Pi0Pi0
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau300"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau300"
# Signal Pi+Pi-
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000"
makealist "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau300"            "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau300"
