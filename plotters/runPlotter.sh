#path="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/roots/"
#invertID
path="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/condor/gitignore/ADDTIME-MUPTVETO-TIMESPREAD/"

regions=(\
 "test" \
 "SR"  \
 "OOT" \
)

dologs=(\
 false \
 true  \
)

for region in ${regions[@]}
do
 for dolog in ${dologs[@]}
 do
   root -l -b -q 'Plotter.C("'$region'", '$dolog', "'$path'")'
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
