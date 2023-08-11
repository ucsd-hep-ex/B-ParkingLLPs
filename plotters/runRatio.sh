aversion=BkgEst-ID-CSC-FINAL
inpath1="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/condor/gitignore/${aversion}/ParkingBPH4_2018AtestOOT_plots.root"
inpath2="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/condor/gitignore/${aversion}/ParkingBPH4_2018AOOT_plots.root"

#inpath1="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/condor/gitignore/${aversion}/ParkingBPH4_2018Atest_plots.root"
#inpath2="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/condor/gitignore/${aversion}/ParkingBPH4_2018ASR_plots.root"

var=h_cscRechitClusterSize_v

dolog=true

root -l -b -q 'Ratio.C('$dolog', "'$inpath1'", "'$inpath2'", "'$var'", "'$aversion'")'
