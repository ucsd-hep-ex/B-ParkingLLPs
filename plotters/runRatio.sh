inpath1="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/condor/gitignore/OOT-dPhi/ParkingBPH4_2018Atest_plots.root"
inpath2="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/condor/gitignore/OOT-dPhi/ParkingBPH4_2018AOOT_plots.root"


var=h_cscRechitClusterSize

dolog=true

root -l -b -q 'Ratio.C('$dolog', "'$inpath1'", "'$inpath2'", "'$var'")'
