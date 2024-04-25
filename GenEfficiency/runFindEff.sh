fileName=(\
 "/store/group/lpclonglived/B-ParkingLLPs//V1p19_9/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi0p3_ctau3000/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi0p3_ctau3000.root" \
 "/store/group/lpclonglived/B-ParkingLLPs//V1p19_9/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi0p5_ctau500/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi0p5_ctau500.root" \
 "/store/group/lpclonglived/B-ParkingLLPs//V1p19_9/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi0p5_ctau5000/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi0p5_ctau5000.root" \
 "/store/group/lpclonglived/B-ParkingLLPs//V1p19_9/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi1p0_ctau10000/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi1p0_ctau10000.root" \
 "/store/group/lpclonglived/B-ParkingLLPs//V1p19_9/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi2p0_ctau10000/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi2p0_ctau10000.root" \
 "/store/group/lpclonglived/B-ParkingLLPs//V1p19_9/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi2p0_ctau2000/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi2p0_ctau2000.root" \
 "/store/group/lpclonglived/B-ParkingLLPs//V1p19_9/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi3p0_ctau10000/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi3p0_ctau10000.root" \
 "/store/group/lpclonglived/B-ParkingLLPs//V1p19_9/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi3p0_ctau3000/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi3p0_ctau3000.root" \
)


for name in ${fileName[@]}
do
    ctau0=$(echo $name | sed 's/.*ctau\([0-9]*\)\.root/\1/')
    echo $name $ctau0 
    #For now default to have tauPrime = tau0, i.e., no reweighting ctau 
    root -l -b -q 'FindEff.C("'${name}'", '$ctau0')'
done
