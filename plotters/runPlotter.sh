#path="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/roots/"
#invertID
aversion=DPhi-MS3-Limits #BkgEst-DPhi-CSC-reBinClstrSize-4Regions #FullSel-B4DPhi #OOT-dPhi #LooseRegion
#path="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/condor/gitignore/${aversion}/"
path="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/Stats/CMSSW_10_2_13/src/combine-llp/inputs_${aversion}/"
mkdir -p plotDump/${aversion}
cp ${path}/setup.C plotDump/${aversion}

regions=(\
# "test" \
# "testOOT" \
 "SR"  \
# "OOT" \
)

dologs=(\
 false \
 true  \
)

for region in ${regions[@]}
do
 for dolog in ${dologs[@]}
 do
   root -l -b -q 'Plotter.C("'$region'", '$dolog', "'$path'", "'$aversion'")'
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
