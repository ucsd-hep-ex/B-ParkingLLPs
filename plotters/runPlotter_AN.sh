aversion=1D_histograms_pi0pi0
path="/eos/user/d/ddiaz/forAram/EXTSamples/"
path="/uscms/home/ahayrape/nobackup/BToPhiK_Analysis/B-ParkingLLPs/HEP_Data_Entries/CutflowTables/"
mkdir -p plotDump/${aversion}

regions=(\
"nominal" \
)
#"PassOOT" \
# "test" \
# "testOOT" \
# "SR"  \
# "OOT" \


dologs=(\
 false \
 true  \
)

for region in ${regions[@]}
do
    for dolog in ${dologs[@]}
    do
	root -l -b -q 'Plotter_AN.C("'$region'", '$dolog', "'$path'", "'$aversion'")'
    done
done
