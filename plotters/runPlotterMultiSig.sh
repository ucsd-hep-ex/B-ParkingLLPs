aversion=JustEXTSamples #WP23_countJets_ValidationBand_GJson_lepIDSF #EXTSamples #DPhi-MS3-Limits #BkgEst-DPhi-CSC-reBinClstrSize-4Regions #FullSel-B4DPhi #OOT-dPhi #LooseRegion
path="${CMSSW_BASE}/src/B-ParkingLLPs/condor/gitignore/${aversion}/"
#path="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/condor/gitignore/${aversion}/"
#path="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/Stats/CMSSW_10_2_13/src/combine-llp/inputs_${aversion}/"
#path="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/roots/"
mkdir -p plotDump/${aversion}
#cp ${path}/setup.C plotDump/${aversion}

regions=(\
"nominalPlusTime" \
)
#"nominalPlusTime" \
#"PassOOT" \
# "test" \
# "testOOT" \
# "SR"  \
# "OOT" \

signal=(\
"BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300_to_70" \
"BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau500_to_100" \
"BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000_to_300" \
"BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau2000_to_700" \
"BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau3000_to_700" \
)
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000to1000_" \
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000to1000_" \
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau300to300_" \
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000to1000_" \

signal_str=$(IFS=','; echo "${signal[*]}")

dologs=(\
 true  \
)

for region in ${regions[@]}
do
 for dolog in ${dologs[@]}
 do
   root -l -b -q 'PlotterMultiSig.C("'$region'", '$dolog', "'$path'", "'$aversion'", "'$signal_str'")'
 done
done

#root -l -b -q 'Plotter.C("test", false,"/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/roots/")'
#root -l -b -q 'Plotter.C("SR", false,  "/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/roots/")'
#root -l -b -q 'Plotter.C("OOT", false, "/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/roots/")'
#root -l -b -q 'Plotter.C("test", true, "/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/roots/")'
#root -l -b -q 'Plotter.C("SR",   true,  "/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/roots/")'
#root -l -b -q 'Plotter.C("OOT",  true,  "/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/roots/")'
#root -l -b -q 'Plotter.C("test", true,  "/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/roots/")'
#root -l -b -q 'Plotter.C("SR",   false, "/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/roots/")'
#root -l -b -q 'Plotter.C("OOT",  false, "/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/roots/")'
#root -l -b -q 'Plotter.C("test", false, "/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/roots/")'