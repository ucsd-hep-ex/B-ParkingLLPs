aversion=MuonVetoPtStudy #DPhi-MS3-Limits #BkgEst-DPhi-CSC-reBinClstrSize-4Regions #FullSel-B4DPhi #OOT-dPhi #LooseRegion
path="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/condor/gitignore/${aversion}/"
#path="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/Stats/CMSSW_10_2_13/src/combine-llp/inputs_${aversion}/"
#path="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/roots/"
mkdir -p plotDump/${aversion}
cp ${path}/setup.C plotDump/${aversion}

regions=(\
"nominal" \
)
#"PassOOT" \
# "test" \
# "testOOT" \
# "SR"  \
# "OOT" \

signal=(\
"BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300to300_" \
"BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300to300_" \
)
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000to1000_" \
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000to1000_" \
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau300to300_" \
#"BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000to1000_" \

dologs=(\
 false \
 true  \
)

for region in ${regions[@]}
do
 for s in ${signal[@]}
 do
   for dolog in ${dologs[@]}
   do
     root -l -b -q 'Plotter.C("'$region'", '$dolog', "'$path'", "'$aversion'", "'$s'")'
   done
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
