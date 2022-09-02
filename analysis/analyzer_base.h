#ifndef analyzer_base_h
#define analyzer_base_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class analyzer_base {
public :
   TChain          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   UInt_t          runNum;
   UInt_t          MC_condition;
   UInt_t          lumiSec;
   UInt_t          evtNum;
   Float_t         rho;
   UInt_t          npv;
   Bool_t          Flag2_HBHENoiseFilter;
   Bool_t          Flag2_HBHEIsoNoiseFilter;
   Bool_t          Flag2_BadPFMuonFilter;
   Bool_t          Flag2_globalSuperTightHalo2016Filter;
   Bool_t          Flag2_globalTightHalo2016Filter;
   Bool_t          Flag2_BadChargedCandidateFilter;
   Bool_t          Flag2_EcalDeadCellTriggerPrimitiveFilter;
   Bool_t          Flag2_ecalBadCalibFilter;
   Bool_t          Flag2_eeBadScFilter;
   Bool_t          Flag2_all;
   Float_t         metEENoise;
   Float_t         metPhiEENoise;
   Float_t         gLLP_eta;
   Float_t         gLLP_phi;
   Float_t         gLLP_csc;
   Float_t         gLLP_dt;
   Float_t         gLLP_beta;
   Float_t         gLLP_e;
   Float_t         gLLP_pt;
   Float_t         gLLP_ctau;
   Float_t         gLLP_decay_vertex_r;
   Float_t         gLLP_decay_vertex_x;
   Float_t         gLLP_decay_vertex_y;
   Float_t         gLLP_decay_vertex_z;
   Int_t           nLeptons;
   Float_t         lepE[27];   //[nLeptons]
   Float_t         lepPt[27];   //[nLeptons]
   Float_t         lepEta[27];   //[nLeptons]
   Float_t         lepPhi[27];   //[nLeptons]
   Int_t           lepPdgId[27];   //[nLeptons]
   Float_t         lepDZ[27];   //[nLeptons]
   Bool_t          lepLooseId[27];   //[nLeptons]
   Bool_t          lepTightId[27];   //[nLeptons]
   Int_t           nJets;
   Float_t         jetE[7];   //[nJets]
   Float_t         jetPt[7];   //[nJets]
   Float_t         jetEta[7];   //[nJets]
   Float_t         jetPhi[7];   //[nJets]
   Bool_t          jetTightPassId[7];   //[nJets]
   Bool_t          HLTDecision[1201];
   Int_t           nCscRechits;
   Int_t           nEarlyCscRechits;
   Int_t           nLateCscRechits;
   Int_t           nEarly2CscRechits;
   Int_t           nLate2CscRechits;
   Int_t           nCscRings;
   Int_t           nCscPositiveYRechits;
   Int_t           nCscNegativeYRechits;
   Float_t         cscPosTpeak;
   Float_t         cscNegTpeak;
   Int_t           nCscRechitsChamberPlus11;
   Int_t           nCscRechitsChamberPlus12;
   Int_t           nCscRechitsChamberPlus13;
   Int_t           nCscRechitsChamberPlus21;
   Int_t           nCscRechitsChamberPlus22;
   Int_t           nCscRechitsChamberPlus31;
   Int_t           nCscRechitsChamberPlus32;
   Int_t           nCscRechitsChamberPlus41;
   Int_t           nCscRechitsChamberPlus42;
   Int_t           nCscRechitsChamberMinus11;
   Int_t           nCscRechitsChamberMinus12;
   Int_t           nCscRechitsChamberMinus13;
   Int_t           nCscRechitsChamberMinus21;
   Int_t           nCscRechitsChamberMinus22;
   Int_t           nCscRechitsChamberMinus31;
   Int_t           nCscRechitsChamberMinus32;
   Int_t           nCscRechitsChamberMinus41;
   Int_t           nCscRechitsChamberMinus42;
   Int_t           nDTRechits;
   Int_t           nDtRings;
   Int_t           nDtWheels25;
   Int_t           nDtStations25;
   Int_t           nDTPositiveYRechits;
   Int_t           nDTNegativeYRechits;
   Int_t           nDTRechitsWheelMinus2;
   Int_t           nDTRechitsWheelMinus1;
   Int_t           nDTRechitsWheel0;
   Int_t           nDTRechitsWheelPlus1;
   Int_t           nDTRechitsWheelPlus2;
   Int_t           nDTRechitsStation1;
   Int_t           nDTRechitsStation2;
   Int_t           nDTRechitsStation3;
   Int_t           nDTRechitsStation4;
   Int_t           nDTRechitsChamberMinus12;
   Int_t           nDTRechitsChamberMinus11;
   Int_t           nDTRechitsChamber10;
   Int_t           nDTRechitsChamberPlus11;
   Int_t           nDTRechitsChamberPlus12;
   Int_t           nDTRechitsChamberMinus22;
   Int_t           nDTRechitsChamberMinus21;
   Int_t           nDTRechitsChamber20;
   Int_t           nDTRechitsChamberPlus21;
   Int_t           nDTRechitsChamberPlus22;
   Int_t           nDTRechitsChamberMinus32;
   Int_t           nDTRechitsChamberMinus31;
   Int_t           nDTRechitsChamber30;
   Int_t           nDTRechitsChamberPlus31;
   Int_t           nDTRechitsChamberPlus32;
   Int_t           nDTRechitsChamberMinus42;
   Int_t           nDTRechitsChamberMinus41;
   Int_t           nDTRechitsChamber40;
   Int_t           nDTRechitsChamberPlus41;
   Int_t           nDTRechitsChamberPlus42;
   Int_t           nCscRechitClusters;
   Float_t         cscRechitClusterX[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterY[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterZ[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTime[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeWeighted[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeTotal[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeSpread[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeSpreadWeighted[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeSpreadWeightedAll[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterGenMuonDeltaR[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterXYSpread[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMajorAxis[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMinorAxis[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterEtaPhiSpread[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterPhiSpread[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterEtaSpread[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterDeltaRSpread[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterXSpread[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterRSpread[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterYSpread[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterZSpread[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterPhi[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterEta[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterSize[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMe11Ratio[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMe12Ratio[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNStation[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNStation5[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNStation10[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNStation10perc[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterAvgStation[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterAvgStation5[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterAvgStation10[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterAvgStation10perc[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterMaxStation[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMaxStationRatio[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNChamber[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterMaxChamber[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMaxChamberRatio[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus11[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus12[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus13[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus21[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus22[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus31[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus32[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus41[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus42[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus11[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus12[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus13[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus21[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus22[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus31[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus32[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus41[3];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus42[3];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_cscRechits_0p4[3];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_dtRechits_phi0p2[3];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_dtRechits_0p4[3];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_MB1_0p4[3];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_dtSeg_0p4[3];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_MB1Seg_0p4[3];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_RB1_0p4[3];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_RE12_0p4[3];   //[nCscRechitClusters]
   Float_t         cscRechitCluster_match_gLLP_deltaR[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterJetVetoPt[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterJetVetoEta[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterJetVetoPhi[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterJetVetoE[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMuonVetoPt[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMuonVetoE[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMuonVetoPhi[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMuonVetoEta[3];   //[nCscRechitClusters]
   Bool_t          cscRechitClusterMuonVetoLooseId[3];   //[nCscRechitClusters]
   Bool_t          cscRechitClusterMuonVetoGlobal[3];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMetEENoise_dPhi[3];   //[nCscRechitClusters]
   Int_t           nDtRechitClusters;
   Float_t         dtRechitClusterMaxDPhi[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMaxDPhi_index[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegStation1[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegStation2[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegStation3[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegStation4[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNOppositeSegStation1[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNOppositeSegStation2[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNOppositeSegStation3[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNOppositeSegStation4[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterX[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterY[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterZ[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterTime[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterTimeWire[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterTimeWirePruned[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterTimeTotal[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterWheel[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterTimeSpread[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterTimeTotalSpread[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterTimeTotalSpreadPruned[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterTimeWireSpread[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterGenMuonDeltaR[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterXYSpread[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMajorAxis[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMinorAxis[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterEtaPhiSpread[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterPhiSpread[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterEtaSpread[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterDeltaRSpread[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterXSpread[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterRSpread[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterYSpread[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterZSpread[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterPhi[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterEta[4];   //[nDtRechitClusters]
   Bool_t          dtRechitClusterOverlap[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterSize[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHit[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHitStation1[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHitStation2[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHitStation3[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHitStation4[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMe11Ratio[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMe12Ratio[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNStation[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNStation5[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNStation10[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNStation10perc[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterAvgStation[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterAvgStation5[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterAvgStation10[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterAvgStation10perc[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMaxStation[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMaxStationRatio[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNChamber[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMaxChamber[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMaxChamberRatio[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegmentStation1[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegmentStation2[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegmentStation3[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegmentStation4[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus11[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus12[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus13[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus21[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus22[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus31[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus32[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus41[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus42[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus11[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus12[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus13[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus21[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus22[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus31[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus32[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus41[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus42[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus11[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus12[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus13[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus21[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus22[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus31[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus32[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus41[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus42[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus11[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus12[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus13[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus21[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus22[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus31[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus32[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus41[4];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus42[4];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTime_dPhi0p5[4];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTimeSpread_dPhi0p5[4];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTime_dR0p4[4];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTimeSpread_dR0p4[4];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RPChits_dR0p4[4];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTime_sameStation_dR0p4[4];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4[4];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RPChits_sameStation_dR0p4[4];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_gLLP_deltaR[4];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RPChits_dPhi0p5[4];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RPCBx_dPhi0p5[4];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RB1_0p4[4];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RB1_dPhi0p5[4];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1Seg_0p4[4];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1Seg_0p5[4];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1hits_0p4[4];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1hits_0p5[4];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1hits_cosmics_plus[4];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1hits_cosmics_minus[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterJetVetoPt[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterJetVetoEta[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterJetVetoPhi[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterJetVetoE[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMuonVetoPt[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMuonVetoE[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMuonVetoPhi[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMuonVetoEta[4];   //[nDtRechitClusters]
   Bool_t          dtRechitClusterMuonVetoLooseId[4];   //[nDtRechitClusters]
   Bool_t          dtRechitClusterMuonVetoGlobal[4];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMetEENoise_dPhi[4];   //[nDtRechitClusters]
   Float_t         weight;

   // List of branches
   TBranch        *b_runNum;   //!
   TBranch        *b_MC_condition;   //!
   TBranch        *b_lumiSec;   //!
   TBranch        *b_evtNum;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_npv;   //!
   TBranch        *b_Flag2_HBHENoiseFilter;   //!
   TBranch        *b_Flag2_HBHEIsoNoiseFilter;   //!
   TBranch        *b_Flag2_BadPFMuonFilter;   //!
   TBranch        *b_Flag2_globalSuperTightHalo2016Filter;   //!
   TBranch        *b_Flag2_globalTightHalo2016Filter;   //!
   TBranch        *b_Flag2_BadChargedCandidateFilter;   //!
   TBranch        *b_Flag2_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_Flag2_ecalBadCalibFilter;   //!
   TBranch        *b_Flag2_eeBadScFilter;   //!
   TBranch        *b_Flag2_all;   //!
   TBranch        *b_metEENoise;   //!
   TBranch        *b_metPhiEENoise;   //!
   TBranch        *b_gLLP_eta;   //!
   TBranch        *b_gLLP_phi;   //!
   TBranch        *b_gLLP_csc;   //!
   TBranch        *b_gLLP_dt;   //!
   TBranch        *b_gLLP_beta;   //!
   TBranch        *b_gLLP_e;   //!
   TBranch        *b_gLLP_pt;   //!
   TBranch        *b_gLLP_ctau;   //!
   TBranch        *b_gLLP_decay_vertex_r;   //!
   TBranch        *b_gLLP_decay_vertex_x;   //!
   TBranch        *b_gLLP_decay_vertex_y;   //!
   TBranch        *b_gLLP_decay_vertex_z;   //!
   TBranch        *b_nLeptons;   //!
   TBranch        *b_lepE;   //!
   TBranch        *b_lepPt;   //!
   TBranch        *b_lepEta;   //!
   TBranch        *b_lepPhi;   //!
   TBranch        *b_lepPdgId;   //!
   TBranch        *b_lepDZ;   //!
   TBranch        *b_lepLooseId;   //!
   TBranch        *b_lepTightId;   //!
   TBranch        *b_nJets;   //!
   TBranch        *b_jetE;   //!
   TBranch        *b_jetPt;   //!
   TBranch        *b_jetEta;   //!
   TBranch        *b_jetPhi;   //!
   TBranch        *b_jetTightPassId;   //!
   TBranch        *b_HLTDecision;   //!
   TBranch        *b_nCscRechits;   //!
   TBranch        *b_nEarlyCscRechits;   //!
   TBranch        *b_nLateCscRechits;   //!
   TBranch        *b_nEarly2CscRechits;   //!
   TBranch        *b_nLate2CscRechits;   //!
   TBranch        *b_nCscRings;   //!
   TBranch        *b_nCscPositiveYRechits;   //!
   TBranch        *b_nCscNegativeYRechits;   //!
   TBranch        *b_cscPosTpeak;   //!
   TBranch        *b_cscNegTpeak;   //!
   TBranch        *b_nCscRechitsChamberPlus11;   //!
   TBranch        *b_nCscRechitsChamberPlus12;   //!
   TBranch        *b_nCscRechitsChamberPlus13;   //!
   TBranch        *b_nCscRechitsChamberPlus21;   //!
   TBranch        *b_nCscRechitsChamberPlus22;   //!
   TBranch        *b_nCscRechitsChamberPlus31;   //!
   TBranch        *b_nCscRechitsChamberPlus32;   //!
   TBranch        *b_nCscRechitsChamberPlus41;   //!
   TBranch        *b_nCscRechitsChamberPlus42;   //!
   TBranch        *b_nCscRechitsChamberMinus11;   //!
   TBranch        *b_nCscRechitsChamberMinus12;   //!
   TBranch        *b_nCscRechitsChamberMinus13;   //!
   TBranch        *b_nCscRechitsChamberMinus21;   //!
   TBranch        *b_nCscRechitsChamberMinus22;   //!
   TBranch        *b_nCscRechitsChamberMinus31;   //!
   TBranch        *b_nCscRechitsChamberMinus32;   //!
   TBranch        *b_nCscRechitsChamberMinus41;   //!
   TBranch        *b_nCscRechitsChamberMinus42;   //!
   TBranch        *b_nDTRechits;   //!
   TBranch        *b_nDtRings;   //!
   TBranch        *b_nDtWheels25;   //!
   TBranch        *b_nDtStations25;   //!
   TBranch        *b_nDTPositiveYRechits;   //!
   TBranch        *b_nDTNegativeYRechits;   //!
   TBranch        *b_nDTRechitsWheelMinus2;   //!
   TBranch        *b_nDTRechitsWheelMinus1;   //!
   TBranch        *b_nDTRechitsWheel0;   //!
   TBranch        *b_nDTRechitsWheelPlus1;   //!
   TBranch        *b_nDTRechitsWheelPlus2;   //!
   TBranch        *b_nDTRechitsStation1;   //!
   TBranch        *b_nDTRechitsStation2;   //!
   TBranch        *b_nDTRechitsStation3;   //!
   TBranch        *b_nDTRechitsStation4;   //!
   TBranch        *b_nDTRechitsChamberMinus12;   //!
   TBranch        *b_nDTRechitsChamberMinus11;   //!
   TBranch        *b_nDTRechitsChamber10;   //!
   TBranch        *b_nDTRechitsChamberPlus11;   //!
   TBranch        *b_nDTRechitsChamberPlus12;   //!
   TBranch        *b_nDTRechitsChamberMinus22;   //!
   TBranch        *b_nDTRechitsChamberMinus21;   //!
   TBranch        *b_nDTRechitsChamber20;   //!
   TBranch        *b_nDTRechitsChamberPlus21;   //!
   TBranch        *b_nDTRechitsChamberPlus22;   //!
   TBranch        *b_nDTRechitsChamberMinus32;   //!
   TBranch        *b_nDTRechitsChamberMinus31;   //!
   TBranch        *b_nDTRechitsChamber30;   //!
   TBranch        *b_nDTRechitsChamberPlus31;   //!
   TBranch        *b_nDTRechitsChamberPlus32;   //!
   TBranch        *b_nDTRechitsChamberMinus42;   //!
   TBranch        *b_nDTRechitsChamberMinus41;   //!
   TBranch        *b_nDTRechitsChamber40;   //!
   TBranch        *b_nDTRechitsChamberPlus41;   //!
   TBranch        *b_nDTRechitsChamberPlus42;   //!
   TBranch        *b_nCscRechitClusters;   //!
   TBranch        *b_cscRechitClusterX;   //!
   TBranch        *b_cscRechitClusterY;   //!
   TBranch        *b_cscRechitClusterZ;   //!
   TBranch        *b_cscRechitClusterTime;   //!
   TBranch        *b_cscRechitClusterTimeWeighted;   //!
   TBranch        *b_cscRechitClusterTimeTotal;   //!
   TBranch        *b_cscRechitClusterTimeSpread;   //!
   TBranch        *b_cscRechitClusterTimeSpreadWeighted;   //!
   TBranch        *b_cscRechitClusterTimeSpreadWeightedAll;   //!
   TBranch        *b_cscRechitClusterGenMuonDeltaR;   //!
   TBranch        *b_cscRechitClusterXYSpread;   //!
   TBranch        *b_cscRechitClusterMajorAxis;   //!
   TBranch        *b_cscRechitClusterMinorAxis;   //!
   TBranch        *b_cscRechitClusterEtaPhiSpread;   //!
   TBranch        *b_cscRechitClusterPhiSpread;   //!
   TBranch        *b_cscRechitClusterEtaSpread;   //!
   TBranch        *b_cscRechitClusterDeltaRSpread;   //!
   TBranch        *b_cscRechitClusterXSpread;   //!
   TBranch        *b_cscRechitClusterRSpread;   //!
   TBranch        *b_cscRechitClusterYSpread;   //!
   TBranch        *b_cscRechitClusterZSpread;   //!
   TBranch        *b_cscRechitClusterPhi;   //!
   TBranch        *b_cscRechitClusterEta;   //!
   TBranch        *b_cscRechitClusterSize;   //!
   TBranch        *b_cscRechitClusterMe11Ratio;   //!
   TBranch        *b_cscRechitClusterMe12Ratio;   //!
   TBranch        *b_cscRechitClusterNStation;   //!
   TBranch        *b_cscRechitClusterNStation5;   //!
   TBranch        *b_cscRechitClusterNStation10;   //!
   TBranch        *b_cscRechitClusterNStation10perc;   //!
   TBranch        *b_cscRechitClusterAvgStation;   //!
   TBranch        *b_cscRechitClusterAvgStation5;   //!
   TBranch        *b_cscRechitClusterAvgStation10;   //!
   TBranch        *b_cscRechitClusterAvgStation10perc;   //!
   TBranch        *b_cscRechitClusterMaxStation;   //!
   TBranch        *b_cscRechitClusterMaxStationRatio;   //!
   TBranch        *b_cscRechitClusterNChamber;   //!
   TBranch        *b_cscRechitClusterMaxChamber;   //!
   TBranch        *b_cscRechitClusterMaxChamberRatio;   //!
   TBranch        *b_cscRechitClusterNRechitChamberPlus11;   //!
   TBranch        *b_cscRechitClusterNRechitChamberPlus12;   //!
   TBranch        *b_cscRechitClusterNRechitChamberPlus13;   //!
   TBranch        *b_cscRechitClusterNRechitChamberPlus21;   //!
   TBranch        *b_cscRechitClusterNRechitChamberPlus22;   //!
   TBranch        *b_cscRechitClusterNRechitChamberPlus31;   //!
   TBranch        *b_cscRechitClusterNRechitChamberPlus32;   //!
   TBranch        *b_cscRechitClusterNRechitChamberPlus41;   //!
   TBranch        *b_cscRechitClusterNRechitChamberPlus42;   //!
   TBranch        *b_cscRechitClusterNRechitChamberMinus11;   //!
   TBranch        *b_cscRechitClusterNRechitChamberMinus12;   //!
   TBranch        *b_cscRechitClusterNRechitChamberMinus13;   //!
   TBranch        *b_cscRechitClusterNRechitChamberMinus21;   //!
   TBranch        *b_cscRechitClusterNRechitChamberMinus22;   //!
   TBranch        *b_cscRechitClusterNRechitChamberMinus31;   //!
   TBranch        *b_cscRechitClusterNRechitChamberMinus32;   //!
   TBranch        *b_cscRechitClusterNRechitChamberMinus41;   //!
   TBranch        *b_cscRechitClusterNRechitChamberMinus42;   //!
   TBranch        *b_cscRechitCluster_match_cscRechits_0p4;   //!
   TBranch        *b_cscRechitCluster_match_dtRechits_phi0p2;   //!
   TBranch        *b_cscRechitCluster_match_dtRechits_0p4;   //!
   TBranch        *b_cscRechitCluster_match_MB1_0p4;   //!
   TBranch        *b_cscRechitCluster_match_dtSeg_0p4;   //!
   TBranch        *b_cscRechitCluster_match_MB1Seg_0p4;   //!
   TBranch        *b_cscRechitCluster_match_RB1_0p4;   //!
   TBranch        *b_cscRechitCluster_match_RE12_0p4;   //!
   TBranch        *b_cscRechitCluster_match_gLLP_deltaR;   //!
   TBranch        *b_cscRechitClusterJetVetoPt;   //!
   TBranch        *b_cscRechitClusterJetVetoEta;   //!
   TBranch        *b_cscRechitClusterJetVetoPhi;   //!
   TBranch        *b_cscRechitClusterJetVetoE;   //!
   TBranch        *b_cscRechitClusterMuonVetoPt;   //!
   TBranch        *b_cscRechitClusterMuonVetoE;   //!
   TBranch        *b_cscRechitClusterMuonVetoPhi;   //!
   TBranch        *b_cscRechitClusterMuonVetoEta;   //!
   TBranch        *b_cscRechitClusterMuonVetoLooseId;   //!
   TBranch        *b_cscRechitClusterMuonVetoGlobal;   //!
   TBranch        *b_cscRechitClusterMetEENoise_dPhi;   //!
   TBranch        *b_nDtRechitClusters;   //!
   TBranch        *b_dtRechitClusterMaxDPhi;   //!
   TBranch        *b_dtRechitClusterMaxDPhi_index;   //!
   TBranch        *b_dtRechitClusterNSegStation1;   //!
   TBranch        *b_dtRechitClusterNSegStation2;   //!
   TBranch        *b_dtRechitClusterNSegStation3;   //!
   TBranch        *b_dtRechitClusterNSegStation4;   //!
   TBranch        *b_dtRechitClusterNOppositeSegStation1;   //!
   TBranch        *b_dtRechitClusterNOppositeSegStation2;   //!
   TBranch        *b_dtRechitClusterNOppositeSegStation3;   //!
   TBranch        *b_dtRechitClusterNOppositeSegStation4;   //!
   TBranch        *b_dtRechitClusterX;   //!
   TBranch        *b_dtRechitClusterY;   //!
   TBranch        *b_dtRechitClusterZ;   //!
   TBranch        *b_dtRechitClusterTime;   //!
   TBranch        *b_dtRechitClusterTimeWire;   //!
   TBranch        *b_dtRechitClusterTimeWirePruned;   //!
   TBranch        *b_dtRechitClusterTimeTotal;   //!
   TBranch        *b_dtRechitClusterWheel;   //!
   TBranch        *b_dtRechitClusterTimeSpread;   //!
   TBranch        *b_dtRechitClusterTimeTotalSpread;   //!
   TBranch        *b_dtRechitClusterTimeTotalSpreadPruned;   //!
   TBranch        *b_dtRechitClusterTimeWireSpread;   //!
   TBranch        *b_dtRechitClusterGenMuonDeltaR;   //!
   TBranch        *b_dtRechitClusterXYSpread;   //!
   TBranch        *b_dtRechitClusterMajorAxis;   //!
   TBranch        *b_dtRechitClusterMinorAxis;   //!
   TBranch        *b_dtRechitClusterEtaPhiSpread;   //!
   TBranch        *b_dtRechitClusterPhiSpread;   //!
   TBranch        *b_dtRechitClusterEtaSpread;   //!
   TBranch        *b_dtRechitClusterDeltaRSpread;   //!
   TBranch        *b_dtRechitClusterXSpread;   //!
   TBranch        *b_dtRechitClusterRSpread;   //!
   TBranch        *b_dtRechitClusterYSpread;   //!
   TBranch        *b_dtRechitClusterZSpread;   //!
   TBranch        *b_dtRechitClusterPhi;   //!
   TBranch        *b_dtRechitClusterEta;   //!
   TBranch        *b_dtRechitClusterOverlap;   //!
   TBranch        *b_dtRechitClusterSize;   //!
   TBranch        *b_dtRechitClusterNoiseHit;   //!
   TBranch        *b_dtRechitClusterNoiseHitStation1;   //!
   TBranch        *b_dtRechitClusterNoiseHitStation2;   //!
   TBranch        *b_dtRechitClusterNoiseHitStation3;   //!
   TBranch        *b_dtRechitClusterNoiseHitStation4;   //!
   TBranch        *b_dtRechitClusterMe11Ratio;   //!
   TBranch        *b_dtRechitClusterMe12Ratio;   //!
   TBranch        *b_dtRechitClusterNStation;   //!
   TBranch        *b_dtRechitClusterNStation5;   //!
   TBranch        *b_dtRechitClusterNStation10;   //!
   TBranch        *b_dtRechitClusterNStation10perc;   //!
   TBranch        *b_dtRechitClusterAvgStation;   //!
   TBranch        *b_dtRechitClusterAvgStation5;   //!
   TBranch        *b_dtRechitClusterAvgStation10;   //!
   TBranch        *b_dtRechitClusterAvgStation10perc;   //!
   TBranch        *b_dtRechitClusterMaxStation;   //!
   TBranch        *b_dtRechitClusterMaxStationRatio;   //!
   TBranch        *b_dtRechitClusterNChamber;   //!
   TBranch        *b_dtRechitClusterMaxChamber;   //!
   TBranch        *b_dtRechitClusterMaxChamberRatio;   //!
   TBranch        *b_dtRechitClusterNSegmentStation1;   //!
   TBranch        *b_dtRechitClusterNSegmentStation2;   //!
   TBranch        *b_dtRechitClusterNSegmentStation3;   //!
   TBranch        *b_dtRechitClusterNSegmentStation4;   //!
   TBranch        *b_dtRechitClusterNRechitChamberPlus11;   //!
   TBranch        *b_dtRechitClusterNRechitChamberPlus12;   //!
   TBranch        *b_dtRechitClusterNRechitChamberPlus13;   //!
   TBranch        *b_dtRechitClusterNRechitChamberPlus21;   //!
   TBranch        *b_dtRechitClusterNRechitChamberPlus22;   //!
   TBranch        *b_dtRechitClusterNRechitChamberPlus31;   //!
   TBranch        *b_dtRechitClusterNRechitChamberPlus32;   //!
   TBranch        *b_dtRechitClusterNRechitChamberPlus41;   //!
   TBranch        *b_dtRechitClusterNRechitChamberPlus42;   //!
   TBranch        *b_dtRechitClusterNRechitChamberMinus11;   //!
   TBranch        *b_dtRechitClusterNRechitChamberMinus12;   //!
   TBranch        *b_dtRechitClusterNRechitChamberMinus13;   //!
   TBranch        *b_dtRechitClusterNRechitChamberMinus21;   //!
   TBranch        *b_dtRechitClusterNRechitChamberMinus22;   //!
   TBranch        *b_dtRechitClusterNRechitChamberMinus31;   //!
   TBranch        *b_dtRechitClusterNRechitChamberMinus32;   //!
   TBranch        *b_dtRechitClusterNRechitChamberMinus41;   //!
   TBranch        *b_dtRechitClusterNRechitChamberMinus42;   //!
   TBranch        *b_dtRechitClusterNLayersChamberPlus11;   //!
   TBranch        *b_dtRechitClusterNLayersChamberPlus12;   //!
   TBranch        *b_dtRechitClusterNLayersChamberPlus13;   //!
   TBranch        *b_dtRechitClusterNLayersChamberPlus21;   //!
   TBranch        *b_dtRechitClusterNLayersChamberPlus22;   //!
   TBranch        *b_dtRechitClusterNLayersChamberPlus31;   //!
   TBranch        *b_dtRechitClusterNLayersChamberPlus32;   //!
   TBranch        *b_dtRechitClusterNLayersChamberPlus41;   //!
   TBranch        *b_dtRechitClusterNLayersChamberPlus42;   //!
   TBranch        *b_dtRechitClusterNLayersChamberMinus11;   //!
   TBranch        *b_dtRechitClusterNLayersChamberMinus12;   //!
   TBranch        *b_dtRechitClusterNLayersChamberMinus13;   //!
   TBranch        *b_dtRechitClusterNLayersChamberMinus21;   //!
   TBranch        *b_dtRechitClusterNLayersChamberMinus22;   //!
   TBranch        *b_dtRechitClusterNLayersChamberMinus31;   //!
   TBranch        *b_dtRechitClusterNLayersChamberMinus32;   //!
   TBranch        *b_dtRechitClusterNLayersChamberMinus41;   //!
   TBranch        *b_dtRechitClusterNLayersChamberMinus42;   //!
   TBranch        *b_dtRechitCluster_match_RPCTime_dPhi0p5;   //!
   TBranch        *b_dtRechitCluster_match_RPCTimeSpread_dPhi0p5;   //!
   TBranch        *b_dtRechitCluster_match_RPCTime_dR0p4;   //!
   TBranch        *b_dtRechitCluster_match_RPCTimeSpread_dR0p4;   //!
   TBranch        *b_dtRechitCluster_match_RPChits_dR0p4;   //!
   TBranch        *b_dtRechitCluster_match_RPCTime_sameStation_dR0p4;   //!
   TBranch        *b_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4;   //!
   TBranch        *b_dtRechitCluster_match_RPChits_sameStation_dR0p4;   //!
   TBranch        *b_dtRechitCluster_match_gLLP_deltaR;   //!
   TBranch        *b_dtRechitCluster_match_RPChits_dPhi0p5;   //!
   TBranch        *b_dtRechitCluster_match_RPCBx_dPhi0p5;   //!
   TBranch        *b_dtRechitCluster_match_RB1_0p4;   //!
   TBranch        *b_dtRechitCluster_match_RB1_dPhi0p5;   //!
   TBranch        *b_dtRechitCluster_match_MB1Seg_0p4;   //!
   TBranch        *b_dtRechitCluster_match_MB1Seg_0p5;   //!
   TBranch        *b_dtRechitCluster_match_MB1hits_0p4;   //!
   TBranch        *b_dtRechitCluster_match_MB1hits_0p5;   //!
   TBranch        *b_dtRechitCluster_match_MB1hits_cosmics_plus;   //!
   TBranch        *b_dtRechitCluster_match_MB1hits_cosmics_minus;   //!
   TBranch        *b_dtRechitClusterJetVetoPt;   //!
   TBranch        *b_dtRechitClusterJetVetoEta;   //!
   TBranch        *b_dtRechitClusterJetVetoPhi;   //!
   TBranch        *b_dtRechitClusterJetVetoE;   //!
   TBranch        *b_dtRechitClusterMuonVetoPt;   //!
   TBranch        *b_dtRechitClusterMuonVetoE;   //!
   TBranch        *b_dtRechitClusterMuonVetoPhi;   //!
   TBranch        *b_dtRechitClusterMuonVetoEta;   //!
   TBranch        *b_dtRechitClusterMuonVetoLooseId;   //!
   TBranch        *b_dtRechitClusterMuonVetoGlobal;   //!
   TBranch        *b_dtRechitClusterMetEENoise_dPhi;   //!
   TBranch        *b_weight;   //!




   analyzer_base();
   virtual ~analyzer_base();
   virtual void Init(TChain *tree);
   virtual Long64_t LoadTree(Long64_t entry);
};
#endif
