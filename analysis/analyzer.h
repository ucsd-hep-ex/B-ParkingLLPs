//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Sep  1 02:22:32 2022 by ROOT version 6.24/06
// from TTree MuonSystem/MuonSystem
// found on file: BToKPhi_MuonGenFilter_mPhi1p0_ctau1000_1pb_weighted.root
//////////////////////////////////////////////////////////

#ifndef analyzer_h
#define analyzer_h

#include <iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "analyzer_base.h"
// Header file for the classes stored in the TTree if any.

class analyzer : public analyzer_base {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

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

   analyzer(TTree *tree=0);
   virtual ~analyzer();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef analyzer_cxx
analyzer::analyzer(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("BToKPhi_MuonGenFilter_mPhi1p0_ctau1000_1pb_weighted.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("BToKPhi_MuonGenFilter_mPhi1p0_ctau1000_1pb_weighted.root");
      }
      f->GetObject("MuonSystem",tree);

   }
   Init(tree);
}

analyzer::~analyzer()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t analyzer::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t analyzer::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void analyzer::Init(TTree *tree)
{

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runNum", &runNum, &b_runNum);
   fChain->SetBranchAddress("MC_condition", &MC_condition, &b_MC_condition);
   fChain->SetBranchAddress("lumiSec", &lumiSec, &b_lumiSec);
   fChain->SetBranchAddress("evtNum", &evtNum, &b_evtNum);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("npv", &npv, &b_npv);
   fChain->SetBranchAddress("Flag2_HBHENoiseFilter", &Flag2_HBHENoiseFilter, &b_Flag2_HBHENoiseFilter);
   fChain->SetBranchAddress("Flag2_HBHEIsoNoiseFilter", &Flag2_HBHEIsoNoiseFilter, &b_Flag2_HBHEIsoNoiseFilter);
   fChain->SetBranchAddress("Flag2_BadPFMuonFilter", &Flag2_BadPFMuonFilter, &b_Flag2_BadPFMuonFilter);
   fChain->SetBranchAddress("Flag2_globalSuperTightHalo2016Filter", &Flag2_globalSuperTightHalo2016Filter, &b_Flag2_globalSuperTightHalo2016Filter);
   fChain->SetBranchAddress("Flag2_globalTightHalo2016Filter", &Flag2_globalTightHalo2016Filter, &b_Flag2_globalTightHalo2016Filter);
   fChain->SetBranchAddress("Flag2_BadChargedCandidateFilter", &Flag2_BadChargedCandidateFilter, &b_Flag2_BadChargedCandidateFilter);
   fChain->SetBranchAddress("Flag2_EcalDeadCellTriggerPrimitiveFilter", &Flag2_EcalDeadCellTriggerPrimitiveFilter, &b_Flag2_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("Flag2_ecalBadCalibFilter", &Flag2_ecalBadCalibFilter, &b_Flag2_ecalBadCalibFilter);
   fChain->SetBranchAddress("Flag2_eeBadScFilter", &Flag2_eeBadScFilter, &b_Flag2_eeBadScFilter);
   fChain->SetBranchAddress("Flag2_all", &Flag2_all, &b_Flag2_all);
   fChain->SetBranchAddress("metEENoise", &metEENoise, &b_metEENoise);
   fChain->SetBranchAddress("metPhiEENoise", &metPhiEENoise, &b_metPhiEENoise);
   fChain->SetBranchAddress("gLLP_eta", &gLLP_eta, &b_gLLP_eta);
   fChain->SetBranchAddress("gLLP_phi", &gLLP_phi, &b_gLLP_phi);
   fChain->SetBranchAddress("gLLP_csc", &gLLP_csc, &b_gLLP_csc);
   fChain->SetBranchAddress("gLLP_dt", &gLLP_dt, &b_gLLP_dt);
   fChain->SetBranchAddress("gLLP_beta", &gLLP_beta, &b_gLLP_beta);
   fChain->SetBranchAddress("gLLP_e", &gLLP_e, &b_gLLP_e);
   fChain->SetBranchAddress("gLLP_pt", &gLLP_pt, &b_gLLP_pt);
   fChain->SetBranchAddress("gLLP_ctau", &gLLP_ctau, &b_gLLP_ctau);
   fChain->SetBranchAddress("gLLP_decay_vertex_r", &gLLP_decay_vertex_r, &b_gLLP_decay_vertex_r);
   fChain->SetBranchAddress("gLLP_decay_vertex_x", &gLLP_decay_vertex_x, &b_gLLP_decay_vertex_x);
   fChain->SetBranchAddress("gLLP_decay_vertex_y", &gLLP_decay_vertex_y, &b_gLLP_decay_vertex_y);
   fChain->SetBranchAddress("gLLP_decay_vertex_z", &gLLP_decay_vertex_z, &b_gLLP_decay_vertex_z);
   fChain->SetBranchAddress("nLeptons", &nLeptons, &b_nLeptons);
   fChain->SetBranchAddress("lepE", lepE, &b_lepE);
   fChain->SetBranchAddress("lepPt", lepPt, &b_lepPt);
   fChain->SetBranchAddress("lepEta", lepEta, &b_lepEta);
   fChain->SetBranchAddress("lepPhi", lepPhi, &b_lepPhi);
   fChain->SetBranchAddress("lepPdgId", lepPdgId, &b_lepPdgId);
   fChain->SetBranchAddress("lepDZ", lepDZ, &b_lepDZ);
   fChain->SetBranchAddress("lepLooseId", lepLooseId, &b_lepLooseId);
   fChain->SetBranchAddress("lepTightId", lepTightId, &b_lepTightId);
   fChain->SetBranchAddress("nJets", &nJets, &b_nJets);
   fChain->SetBranchAddress("jetE", jetE, &b_jetE);
   fChain->SetBranchAddress("jetPt", jetPt, &b_jetPt);
   fChain->SetBranchAddress("jetEta", jetEta, &b_jetEta);
   fChain->SetBranchAddress("jetPhi", jetPhi, &b_jetPhi);
   fChain->SetBranchAddress("jetTightPassId", jetTightPassId, &b_jetTightPassId);
   fChain->SetBranchAddress("HLTDecision", HLTDecision, &b_HLTDecision);
   fChain->SetBranchAddress("nCscRechits", &nCscRechits, &b_nCscRechits);
   fChain->SetBranchAddress("nEarlyCscRechits", &nEarlyCscRechits, &b_nEarlyCscRechits);
   fChain->SetBranchAddress("nLateCscRechits", &nLateCscRechits, &b_nLateCscRechits);
   fChain->SetBranchAddress("nEarly2CscRechits", &nEarly2CscRechits, &b_nEarly2CscRechits);
   fChain->SetBranchAddress("nLate2CscRechits", &nLate2CscRechits, &b_nLate2CscRechits);
   fChain->SetBranchAddress("nCscRings", &nCscRings, &b_nCscRings);
   fChain->SetBranchAddress("nCscPositiveYRechits", &nCscPositiveYRechits, &b_nCscPositiveYRechits);
   fChain->SetBranchAddress("nCscNegativeYRechits", &nCscNegativeYRechits, &b_nCscNegativeYRechits);
   fChain->SetBranchAddress("cscPosTpeak", &cscPosTpeak, &b_cscPosTpeak);
   fChain->SetBranchAddress("cscNegTpeak", &cscNegTpeak, &b_cscNegTpeak);
   fChain->SetBranchAddress("nCscRechitsChamberPlus11", &nCscRechitsChamberPlus11, &b_nCscRechitsChamberPlus11);
   fChain->SetBranchAddress("nCscRechitsChamberPlus12", &nCscRechitsChamberPlus12, &b_nCscRechitsChamberPlus12);
   fChain->SetBranchAddress("nCscRechitsChamberPlus13", &nCscRechitsChamberPlus13, &b_nCscRechitsChamberPlus13);
   fChain->SetBranchAddress("nCscRechitsChamberPlus21", &nCscRechitsChamberPlus21, &b_nCscRechitsChamberPlus21);
   fChain->SetBranchAddress("nCscRechitsChamberPlus22", &nCscRechitsChamberPlus22, &b_nCscRechitsChamberPlus22);
   fChain->SetBranchAddress("nCscRechitsChamberPlus31", &nCscRechitsChamberPlus31, &b_nCscRechitsChamberPlus31);
   fChain->SetBranchAddress("nCscRechitsChamberPlus32", &nCscRechitsChamberPlus32, &b_nCscRechitsChamberPlus32);
   fChain->SetBranchAddress("nCscRechitsChamberPlus41", &nCscRechitsChamberPlus41, &b_nCscRechitsChamberPlus41);
   fChain->SetBranchAddress("nCscRechitsChamberPlus42", &nCscRechitsChamberPlus42, &b_nCscRechitsChamberPlus42);
   fChain->SetBranchAddress("nCscRechitsChamberMinus11", &nCscRechitsChamberMinus11, &b_nCscRechitsChamberMinus11);
   fChain->SetBranchAddress("nCscRechitsChamberMinus12", &nCscRechitsChamberMinus12, &b_nCscRechitsChamberMinus12);
   fChain->SetBranchAddress("nCscRechitsChamberMinus13", &nCscRechitsChamberMinus13, &b_nCscRechitsChamberMinus13);
   fChain->SetBranchAddress("nCscRechitsChamberMinus21", &nCscRechitsChamberMinus21, &b_nCscRechitsChamberMinus21);
   fChain->SetBranchAddress("nCscRechitsChamberMinus22", &nCscRechitsChamberMinus22, &b_nCscRechitsChamberMinus22);
   fChain->SetBranchAddress("nCscRechitsChamberMinus31", &nCscRechitsChamberMinus31, &b_nCscRechitsChamberMinus31);
   fChain->SetBranchAddress("nCscRechitsChamberMinus32", &nCscRechitsChamberMinus32, &b_nCscRechitsChamberMinus32);
   fChain->SetBranchAddress("nCscRechitsChamberMinus41", &nCscRechitsChamberMinus41, &b_nCscRechitsChamberMinus41);
   fChain->SetBranchAddress("nCscRechitsChamberMinus42", &nCscRechitsChamberMinus42, &b_nCscRechitsChamberMinus42);
   fChain->SetBranchAddress("nDTRechits", &nDTRechits, &b_nDTRechits);
   fChain->SetBranchAddress("nDtRings", &nDtRings, &b_nDtRings);
   fChain->SetBranchAddress("nDtWheels25", &nDtWheels25, &b_nDtWheels25);
   fChain->SetBranchAddress("nDtStations25", &nDtStations25, &b_nDtStations25);
   fChain->SetBranchAddress("nDTPositiveYRechits", &nDTPositiveYRechits, &b_nDTPositiveYRechits);
   fChain->SetBranchAddress("nDTNegativeYRechits", &nDTNegativeYRechits, &b_nDTNegativeYRechits);
   fChain->SetBranchAddress("nDTRechitsWheelMinus2", &nDTRechitsWheelMinus2, &b_nDTRechitsWheelMinus2);
   fChain->SetBranchAddress("nDTRechitsWheelMinus1", &nDTRechitsWheelMinus1, &b_nDTRechitsWheelMinus1);
   fChain->SetBranchAddress("nDTRechitsWheel0", &nDTRechitsWheel0, &b_nDTRechitsWheel0);
   fChain->SetBranchAddress("nDTRechitsWheelPlus1", &nDTRechitsWheelPlus1, &b_nDTRechitsWheelPlus1);
   fChain->SetBranchAddress("nDTRechitsWheelPlus2", &nDTRechitsWheelPlus2, &b_nDTRechitsWheelPlus2);
   fChain->SetBranchAddress("nDTRechitsStation1", &nDTRechitsStation1, &b_nDTRechitsStation1);
   fChain->SetBranchAddress("nDTRechitsStation2", &nDTRechitsStation2, &b_nDTRechitsStation2);
   fChain->SetBranchAddress("nDTRechitsStation3", &nDTRechitsStation3, &b_nDTRechitsStation3);
   fChain->SetBranchAddress("nDTRechitsStation4", &nDTRechitsStation4, &b_nDTRechitsStation4);
   fChain->SetBranchAddress("nDTRechitsChamberMinus12", &nDTRechitsChamberMinus12, &b_nDTRechitsChamberMinus12);
   fChain->SetBranchAddress("nDTRechitsChamberMinus11", &nDTRechitsChamberMinus11, &b_nDTRechitsChamberMinus11);
   fChain->SetBranchAddress("nDTRechitsChamber10", &nDTRechitsChamber10, &b_nDTRechitsChamber10);
   fChain->SetBranchAddress("nDTRechitsChamberPlus11", &nDTRechitsChamberPlus11, &b_nDTRechitsChamberPlus11);
   fChain->SetBranchAddress("nDTRechitsChamberPlus12", &nDTRechitsChamberPlus12, &b_nDTRechitsChamberPlus12);
   fChain->SetBranchAddress("nDTRechitsChamberMinus22", &nDTRechitsChamberMinus22, &b_nDTRechitsChamberMinus22);
   fChain->SetBranchAddress("nDTRechitsChamberMinus21", &nDTRechitsChamberMinus21, &b_nDTRechitsChamberMinus21);
   fChain->SetBranchAddress("nDTRechitsChamber20", &nDTRechitsChamber20, &b_nDTRechitsChamber20);
   fChain->SetBranchAddress("nDTRechitsChamberPlus21", &nDTRechitsChamberPlus21, &b_nDTRechitsChamberPlus21);
   fChain->SetBranchAddress("nDTRechitsChamberPlus22", &nDTRechitsChamberPlus22, &b_nDTRechitsChamberPlus22);
   fChain->SetBranchAddress("nDTRechitsChamberMinus32", &nDTRechitsChamberMinus32, &b_nDTRechitsChamberMinus32);
   fChain->SetBranchAddress("nDTRechitsChamberMinus31", &nDTRechitsChamberMinus31, &b_nDTRechitsChamberMinus31);
   fChain->SetBranchAddress("nDTRechitsChamber30", &nDTRechitsChamber30, &b_nDTRechitsChamber30);
   fChain->SetBranchAddress("nDTRechitsChamberPlus31", &nDTRechitsChamberPlus31, &b_nDTRechitsChamberPlus31);
   fChain->SetBranchAddress("nDTRechitsChamberPlus32", &nDTRechitsChamberPlus32, &b_nDTRechitsChamberPlus32);
   fChain->SetBranchAddress("nDTRechitsChamberMinus42", &nDTRechitsChamberMinus42, &b_nDTRechitsChamberMinus42);
   fChain->SetBranchAddress("nDTRechitsChamberMinus41", &nDTRechitsChamberMinus41, &b_nDTRechitsChamberMinus41);
   fChain->SetBranchAddress("nDTRechitsChamber40", &nDTRechitsChamber40, &b_nDTRechitsChamber40);
   fChain->SetBranchAddress("nDTRechitsChamberPlus41", &nDTRechitsChamberPlus41, &b_nDTRechitsChamberPlus41);
   fChain->SetBranchAddress("nDTRechitsChamberPlus42", &nDTRechitsChamberPlus42, &b_nDTRechitsChamberPlus42);
   fChain->SetBranchAddress("nCscRechitClusters", &nCscRechitClusters, &b_nCscRechitClusters);
   fChain->SetBranchAddress("cscRechitClusterX", cscRechitClusterX, &b_cscRechitClusterX);
   fChain->SetBranchAddress("cscRechitClusterY", cscRechitClusterY, &b_cscRechitClusterY);
   fChain->SetBranchAddress("cscRechitClusterZ", cscRechitClusterZ, &b_cscRechitClusterZ);
   fChain->SetBranchAddress("cscRechitClusterTime", cscRechitClusterTime, &b_cscRechitClusterTime);
   fChain->SetBranchAddress("cscRechitClusterTimeWeighted", cscRechitClusterTimeWeighted, &b_cscRechitClusterTimeWeighted);
   fChain->SetBranchAddress("cscRechitClusterTimeTotal", cscRechitClusterTimeTotal, &b_cscRechitClusterTimeTotal);
   fChain->SetBranchAddress("cscRechitClusterTimeSpread", cscRechitClusterTimeSpread, &b_cscRechitClusterTimeSpread);
   fChain->SetBranchAddress("cscRechitClusterTimeSpreadWeighted", cscRechitClusterTimeSpreadWeighted, &b_cscRechitClusterTimeSpreadWeighted);
   fChain->SetBranchAddress("cscRechitClusterTimeSpreadWeightedAll", cscRechitClusterTimeSpreadWeightedAll, &b_cscRechitClusterTimeSpreadWeightedAll);
   fChain->SetBranchAddress("cscRechitClusterGenMuonDeltaR", cscRechitClusterGenMuonDeltaR, &b_cscRechitClusterGenMuonDeltaR);
   fChain->SetBranchAddress("cscRechitClusterXYSpread", cscRechitClusterXYSpread, &b_cscRechitClusterXYSpread);
   fChain->SetBranchAddress("cscRechitClusterMajorAxis", cscRechitClusterMajorAxis, &b_cscRechitClusterMajorAxis);
   fChain->SetBranchAddress("cscRechitClusterMinorAxis", cscRechitClusterMinorAxis, &b_cscRechitClusterMinorAxis);
   fChain->SetBranchAddress("cscRechitClusterEtaPhiSpread", cscRechitClusterEtaPhiSpread, &b_cscRechitClusterEtaPhiSpread);
   fChain->SetBranchAddress("cscRechitClusterPhiSpread", cscRechitClusterPhiSpread, &b_cscRechitClusterPhiSpread);
   fChain->SetBranchAddress("cscRechitClusterEtaSpread", cscRechitClusterEtaSpread, &b_cscRechitClusterEtaSpread);
   fChain->SetBranchAddress("cscRechitClusterDeltaRSpread", cscRechitClusterDeltaRSpread, &b_cscRechitClusterDeltaRSpread);
   fChain->SetBranchAddress("cscRechitClusterXSpread", cscRechitClusterXSpread, &b_cscRechitClusterXSpread);
   fChain->SetBranchAddress("cscRechitClusterRSpread", cscRechitClusterRSpread, &b_cscRechitClusterRSpread);
   fChain->SetBranchAddress("cscRechitClusterYSpread", cscRechitClusterYSpread, &b_cscRechitClusterYSpread);
   fChain->SetBranchAddress("cscRechitClusterZSpread", cscRechitClusterZSpread, &b_cscRechitClusterZSpread);
   fChain->SetBranchAddress("cscRechitClusterPhi", cscRechitClusterPhi, &b_cscRechitClusterPhi);
   fChain->SetBranchAddress("cscRechitClusterEta", cscRechitClusterEta, &b_cscRechitClusterEta);
   fChain->SetBranchAddress("cscRechitClusterSize", cscRechitClusterSize, &b_cscRechitClusterSize);
   fChain->SetBranchAddress("cscRechitClusterMe11Ratio", cscRechitClusterMe11Ratio, &b_cscRechitClusterMe11Ratio);
   fChain->SetBranchAddress("cscRechitClusterMe12Ratio", cscRechitClusterMe12Ratio, &b_cscRechitClusterMe12Ratio);
   fChain->SetBranchAddress("cscRechitClusterNStation", cscRechitClusterNStation, &b_cscRechitClusterNStation);
   fChain->SetBranchAddress("cscRechitClusterNStation5", cscRechitClusterNStation5, &b_cscRechitClusterNStation5);
   fChain->SetBranchAddress("cscRechitClusterNStation10", cscRechitClusterNStation10, &b_cscRechitClusterNStation10);
   fChain->SetBranchAddress("cscRechitClusterNStation10perc", cscRechitClusterNStation10perc, &b_cscRechitClusterNStation10perc);
   fChain->SetBranchAddress("cscRechitClusterAvgStation", cscRechitClusterAvgStation, &b_cscRechitClusterAvgStation);
   fChain->SetBranchAddress("cscRechitClusterAvgStation5", cscRechitClusterAvgStation5, &b_cscRechitClusterAvgStation5);
   fChain->SetBranchAddress("cscRechitClusterAvgStation10", cscRechitClusterAvgStation10, &b_cscRechitClusterAvgStation10);
   fChain->SetBranchAddress("cscRechitClusterAvgStation10perc", cscRechitClusterAvgStation10perc, &b_cscRechitClusterAvgStation10perc);
   fChain->SetBranchAddress("cscRechitClusterMaxStation", cscRechitClusterMaxStation, &b_cscRechitClusterMaxStation);
   fChain->SetBranchAddress("cscRechitClusterMaxStationRatio", cscRechitClusterMaxStationRatio, &b_cscRechitClusterMaxStationRatio);
   fChain->SetBranchAddress("cscRechitClusterNChamber", cscRechitClusterNChamber, &b_cscRechitClusterNChamber);
   fChain->SetBranchAddress("cscRechitClusterMaxChamber", cscRechitClusterMaxChamber, &b_cscRechitClusterMaxChamber);
   fChain->SetBranchAddress("cscRechitClusterMaxChamberRatio", cscRechitClusterMaxChamberRatio, &b_cscRechitClusterMaxChamberRatio);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus11", cscRechitClusterNRechitChamberPlus11, &b_cscRechitClusterNRechitChamberPlus11);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus12", cscRechitClusterNRechitChamberPlus12, &b_cscRechitClusterNRechitChamberPlus12);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus13", cscRechitClusterNRechitChamberPlus13, &b_cscRechitClusterNRechitChamberPlus13);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus21", cscRechitClusterNRechitChamberPlus21, &b_cscRechitClusterNRechitChamberPlus21);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus22", cscRechitClusterNRechitChamberPlus22, &b_cscRechitClusterNRechitChamberPlus22);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus31", cscRechitClusterNRechitChamberPlus31, &b_cscRechitClusterNRechitChamberPlus31);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus32", cscRechitClusterNRechitChamberPlus32, &b_cscRechitClusterNRechitChamberPlus32);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus41", cscRechitClusterNRechitChamberPlus41, &b_cscRechitClusterNRechitChamberPlus41);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus42", cscRechitClusterNRechitChamberPlus42, &b_cscRechitClusterNRechitChamberPlus42);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus11", cscRechitClusterNRechitChamberMinus11, &b_cscRechitClusterNRechitChamberMinus11);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus12", cscRechitClusterNRechitChamberMinus12, &b_cscRechitClusterNRechitChamberMinus12);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus13", cscRechitClusterNRechitChamberMinus13, &b_cscRechitClusterNRechitChamberMinus13);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus21", cscRechitClusterNRechitChamberMinus21, &b_cscRechitClusterNRechitChamberMinus21);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus22", cscRechitClusterNRechitChamberMinus22, &b_cscRechitClusterNRechitChamberMinus22);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus31", cscRechitClusterNRechitChamberMinus31, &b_cscRechitClusterNRechitChamberMinus31);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus32", cscRechitClusterNRechitChamberMinus32, &b_cscRechitClusterNRechitChamberMinus32);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus41", cscRechitClusterNRechitChamberMinus41, &b_cscRechitClusterNRechitChamberMinus41);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus42", cscRechitClusterNRechitChamberMinus42, &b_cscRechitClusterNRechitChamberMinus42);
   fChain->SetBranchAddress("cscRechitCluster_match_cscRechits_0p4", cscRechitCluster_match_cscRechits_0p4, &b_cscRechitCluster_match_cscRechits_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_dtRechits_phi0p2", cscRechitCluster_match_dtRechits_phi0p2, &b_cscRechitCluster_match_dtRechits_phi0p2);
   fChain->SetBranchAddress("cscRechitCluster_match_dtRechits_0p4", cscRechitCluster_match_dtRechits_0p4, &b_cscRechitCluster_match_dtRechits_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_MB1_0p4", cscRechitCluster_match_MB1_0p4, &b_cscRechitCluster_match_MB1_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_dtSeg_0p4", cscRechitCluster_match_dtSeg_0p4, &b_cscRechitCluster_match_dtSeg_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_MB1Seg_0p4", cscRechitCluster_match_MB1Seg_0p4, &b_cscRechitCluster_match_MB1Seg_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_RB1_0p4", cscRechitCluster_match_RB1_0p4, &b_cscRechitCluster_match_RB1_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_RE12_0p4", cscRechitCluster_match_RE12_0p4, &b_cscRechitCluster_match_RE12_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_gLLP_deltaR", cscRechitCluster_match_gLLP_deltaR, &b_cscRechitCluster_match_gLLP_deltaR);
   fChain->SetBranchAddress("cscRechitClusterJetVetoPt", cscRechitClusterJetVetoPt, &b_cscRechitClusterJetVetoPt);
   fChain->SetBranchAddress("cscRechitClusterJetVetoEta", cscRechitClusterJetVetoEta, &b_cscRechitClusterJetVetoEta);
   fChain->SetBranchAddress("cscRechitClusterJetVetoPhi", cscRechitClusterJetVetoPhi, &b_cscRechitClusterJetVetoPhi);
   fChain->SetBranchAddress("cscRechitClusterJetVetoE", cscRechitClusterJetVetoE, &b_cscRechitClusterJetVetoE);
   fChain->SetBranchAddress("cscRechitClusterMuonVetoPt", cscRechitClusterMuonVetoPt, &b_cscRechitClusterMuonVetoPt);
   fChain->SetBranchAddress("cscRechitClusterMuonVetoE", cscRechitClusterMuonVetoE, &b_cscRechitClusterMuonVetoE);
   fChain->SetBranchAddress("cscRechitClusterMuonVetoPhi", cscRechitClusterMuonVetoPhi, &b_cscRechitClusterMuonVetoPhi);
   fChain->SetBranchAddress("cscRechitClusterMuonVetoEta", cscRechitClusterMuonVetoEta, &b_cscRechitClusterMuonVetoEta);
   fChain->SetBranchAddress("cscRechitClusterMuonVetoLooseId", cscRechitClusterMuonVetoLooseId, &b_cscRechitClusterMuonVetoLooseId);
   fChain->SetBranchAddress("cscRechitClusterMuonVetoGlobal", cscRechitClusterMuonVetoGlobal, &b_cscRechitClusterMuonVetoGlobal);
   fChain->SetBranchAddress("cscRechitClusterMetEENoise_dPhi", cscRechitClusterMetEENoise_dPhi, &b_cscRechitClusterMetEENoise_dPhi);
   fChain->SetBranchAddress("nDtRechitClusters", &nDtRechitClusters, &b_nDtRechitClusters);
   fChain->SetBranchAddress("dtRechitClusterMaxDPhi", dtRechitClusterMaxDPhi, &b_dtRechitClusterMaxDPhi);
   fChain->SetBranchAddress("dtRechitClusterMaxDPhi_index", dtRechitClusterMaxDPhi_index, &b_dtRechitClusterMaxDPhi_index);
   fChain->SetBranchAddress("dtRechitClusterNSegStation1", dtRechitClusterNSegStation1, &b_dtRechitClusterNSegStation1);
   fChain->SetBranchAddress("dtRechitClusterNSegStation2", dtRechitClusterNSegStation2, &b_dtRechitClusterNSegStation2);
   fChain->SetBranchAddress("dtRechitClusterNSegStation3", dtRechitClusterNSegStation3, &b_dtRechitClusterNSegStation3);
   fChain->SetBranchAddress("dtRechitClusterNSegStation4", dtRechitClusterNSegStation4, &b_dtRechitClusterNSegStation4);
   fChain->SetBranchAddress("dtRechitClusterNOppositeSegStation1", dtRechitClusterNOppositeSegStation1, &b_dtRechitClusterNOppositeSegStation1);
   fChain->SetBranchAddress("dtRechitClusterNOppositeSegStation2", dtRechitClusterNOppositeSegStation2, &b_dtRechitClusterNOppositeSegStation2);
   fChain->SetBranchAddress("dtRechitClusterNOppositeSegStation3", dtRechitClusterNOppositeSegStation3, &b_dtRechitClusterNOppositeSegStation3);
   fChain->SetBranchAddress("dtRechitClusterNOppositeSegStation4", dtRechitClusterNOppositeSegStation4, &b_dtRechitClusterNOppositeSegStation4);
   fChain->SetBranchAddress("dtRechitClusterX", dtRechitClusterX, &b_dtRechitClusterX);
   fChain->SetBranchAddress("dtRechitClusterY", dtRechitClusterY, &b_dtRechitClusterY);
   fChain->SetBranchAddress("dtRechitClusterZ", dtRechitClusterZ, &b_dtRechitClusterZ);
   fChain->SetBranchAddress("dtRechitClusterTime", dtRechitClusterTime, &b_dtRechitClusterTime);
   fChain->SetBranchAddress("dtRechitClusterTimeWire", dtRechitClusterTimeWire, &b_dtRechitClusterTimeWire);
   fChain->SetBranchAddress("dtRechitClusterTimeWirePruned", dtRechitClusterTimeWirePruned, &b_dtRechitClusterTimeWirePruned);
   fChain->SetBranchAddress("dtRechitClusterTimeTotal", dtRechitClusterTimeTotal, &b_dtRechitClusterTimeTotal);
   fChain->SetBranchAddress("dtRechitClusterWheel", dtRechitClusterWheel, &b_dtRechitClusterWheel);
   fChain->SetBranchAddress("dtRechitClusterTimeSpread", dtRechitClusterTimeSpread, &b_dtRechitClusterTimeSpread);
   fChain->SetBranchAddress("dtRechitClusterTimeTotalSpread", dtRechitClusterTimeTotalSpread, &b_dtRechitClusterTimeTotalSpread);
   fChain->SetBranchAddress("dtRechitClusterTimeTotalSpreadPruned", dtRechitClusterTimeTotalSpreadPruned, &b_dtRechitClusterTimeTotalSpreadPruned);
   fChain->SetBranchAddress("dtRechitClusterTimeWireSpread", dtRechitClusterTimeWireSpread, &b_dtRechitClusterTimeWireSpread);
   fChain->SetBranchAddress("dtRechitClusterGenMuonDeltaR", dtRechitClusterGenMuonDeltaR, &b_dtRechitClusterGenMuonDeltaR);
   fChain->SetBranchAddress("dtRechitClusterXYSpread", dtRechitClusterXYSpread, &b_dtRechitClusterXYSpread);
   fChain->SetBranchAddress("dtRechitClusterMajorAxis", dtRechitClusterMajorAxis, &b_dtRechitClusterMajorAxis);
   fChain->SetBranchAddress("dtRechitClusterMinorAxis", dtRechitClusterMinorAxis, &b_dtRechitClusterMinorAxis);
   fChain->SetBranchAddress("dtRechitClusterEtaPhiSpread", dtRechitClusterEtaPhiSpread, &b_dtRechitClusterEtaPhiSpread);
   fChain->SetBranchAddress("dtRechitClusterPhiSpread", dtRechitClusterPhiSpread, &b_dtRechitClusterPhiSpread);
   fChain->SetBranchAddress("dtRechitClusterEtaSpread", dtRechitClusterEtaSpread, &b_dtRechitClusterEtaSpread);
   fChain->SetBranchAddress("dtRechitClusterDeltaRSpread", dtRechitClusterDeltaRSpread, &b_dtRechitClusterDeltaRSpread);
   fChain->SetBranchAddress("dtRechitClusterXSpread", dtRechitClusterXSpread, &b_dtRechitClusterXSpread);
   fChain->SetBranchAddress("dtRechitClusterRSpread", dtRechitClusterRSpread, &b_dtRechitClusterRSpread);
   fChain->SetBranchAddress("dtRechitClusterYSpread", dtRechitClusterYSpread, &b_dtRechitClusterYSpread);
   fChain->SetBranchAddress("dtRechitClusterZSpread", dtRechitClusterZSpread, &b_dtRechitClusterZSpread);
   fChain->SetBranchAddress("dtRechitClusterPhi", dtRechitClusterPhi, &b_dtRechitClusterPhi);
   fChain->SetBranchAddress("dtRechitClusterEta", dtRechitClusterEta, &b_dtRechitClusterEta);
   fChain->SetBranchAddress("dtRechitClusterOverlap", dtRechitClusterOverlap, &b_dtRechitClusterOverlap);
   fChain->SetBranchAddress("dtRechitClusterSize", dtRechitClusterSize, &b_dtRechitClusterSize);
   fChain->SetBranchAddress("dtRechitClusterNoiseHit", dtRechitClusterNoiseHit, &b_dtRechitClusterNoiseHit);
   fChain->SetBranchAddress("dtRechitClusterNoiseHitStation1", dtRechitClusterNoiseHitStation1, &b_dtRechitClusterNoiseHitStation1);
   fChain->SetBranchAddress("dtRechitClusterNoiseHitStation2", dtRechitClusterNoiseHitStation2, &b_dtRechitClusterNoiseHitStation2);
   fChain->SetBranchAddress("dtRechitClusterNoiseHitStation3", dtRechitClusterNoiseHitStation3, &b_dtRechitClusterNoiseHitStation3);
   fChain->SetBranchAddress("dtRechitClusterNoiseHitStation4", dtRechitClusterNoiseHitStation4, &b_dtRechitClusterNoiseHitStation4);
   fChain->SetBranchAddress("dtRechitClusterMe11Ratio", dtRechitClusterMe11Ratio, &b_dtRechitClusterMe11Ratio);
   fChain->SetBranchAddress("dtRechitClusterMe12Ratio", dtRechitClusterMe12Ratio, &b_dtRechitClusterMe12Ratio);
   fChain->SetBranchAddress("dtRechitClusterNStation", dtRechitClusterNStation, &b_dtRechitClusterNStation);
   fChain->SetBranchAddress("dtRechitClusterNStation5", dtRechitClusterNStation5, &b_dtRechitClusterNStation5);
   fChain->SetBranchAddress("dtRechitClusterNStation10", dtRechitClusterNStation10, &b_dtRechitClusterNStation10);
   fChain->SetBranchAddress("dtRechitClusterNStation10perc", dtRechitClusterNStation10perc, &b_dtRechitClusterNStation10perc);
   fChain->SetBranchAddress("dtRechitClusterAvgStation", dtRechitClusterAvgStation, &b_dtRechitClusterAvgStation);
   fChain->SetBranchAddress("dtRechitClusterAvgStation5", dtRechitClusterAvgStation5, &b_dtRechitClusterAvgStation5);
   fChain->SetBranchAddress("dtRechitClusterAvgStation10", dtRechitClusterAvgStation10, &b_dtRechitClusterAvgStation10);
   fChain->SetBranchAddress("dtRechitClusterAvgStation10perc", dtRechitClusterAvgStation10perc, &b_dtRechitClusterAvgStation10perc);
   fChain->SetBranchAddress("dtRechitClusterMaxStation", dtRechitClusterMaxStation, &b_dtRechitClusterMaxStation);
   fChain->SetBranchAddress("dtRechitClusterMaxStationRatio", dtRechitClusterMaxStationRatio, &b_dtRechitClusterMaxStationRatio);
   fChain->SetBranchAddress("dtRechitClusterNChamber", dtRechitClusterNChamber, &b_dtRechitClusterNChamber);
   fChain->SetBranchAddress("dtRechitClusterMaxChamber", dtRechitClusterMaxChamber, &b_dtRechitClusterMaxChamber);
   fChain->SetBranchAddress("dtRechitClusterMaxChamberRatio", dtRechitClusterMaxChamberRatio, &b_dtRechitClusterMaxChamberRatio);
   fChain->SetBranchAddress("dtRechitClusterNSegmentStation1", dtRechitClusterNSegmentStation1, &b_dtRechitClusterNSegmentStation1);
   fChain->SetBranchAddress("dtRechitClusterNSegmentStation2", dtRechitClusterNSegmentStation2, &b_dtRechitClusterNSegmentStation2);
   fChain->SetBranchAddress("dtRechitClusterNSegmentStation3", dtRechitClusterNSegmentStation3, &b_dtRechitClusterNSegmentStation3);
   fChain->SetBranchAddress("dtRechitClusterNSegmentStation4", dtRechitClusterNSegmentStation4, &b_dtRechitClusterNSegmentStation4);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus11", dtRechitClusterNRechitChamberPlus11, &b_dtRechitClusterNRechitChamberPlus11);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus12", dtRechitClusterNRechitChamberPlus12, &b_dtRechitClusterNRechitChamberPlus12);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus13", dtRechitClusterNRechitChamberPlus13, &b_dtRechitClusterNRechitChamberPlus13);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus21", dtRechitClusterNRechitChamberPlus21, &b_dtRechitClusterNRechitChamberPlus21);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus22", dtRechitClusterNRechitChamberPlus22, &b_dtRechitClusterNRechitChamberPlus22);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus31", dtRechitClusterNRechitChamberPlus31, &b_dtRechitClusterNRechitChamberPlus31);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus32", dtRechitClusterNRechitChamberPlus32, &b_dtRechitClusterNRechitChamberPlus32);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus41", dtRechitClusterNRechitChamberPlus41, &b_dtRechitClusterNRechitChamberPlus41);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus42", dtRechitClusterNRechitChamberPlus42, &b_dtRechitClusterNRechitChamberPlus42);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus11", dtRechitClusterNRechitChamberMinus11, &b_dtRechitClusterNRechitChamberMinus11);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus12", dtRechitClusterNRechitChamberMinus12, &b_dtRechitClusterNRechitChamberMinus12);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus13", dtRechitClusterNRechitChamberMinus13, &b_dtRechitClusterNRechitChamberMinus13);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus21", dtRechitClusterNRechitChamberMinus21, &b_dtRechitClusterNRechitChamberMinus21);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus22", dtRechitClusterNRechitChamberMinus22, &b_dtRechitClusterNRechitChamberMinus22);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus31", dtRechitClusterNRechitChamberMinus31, &b_dtRechitClusterNRechitChamberMinus31);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus32", dtRechitClusterNRechitChamberMinus32, &b_dtRechitClusterNRechitChamberMinus32);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus41", dtRechitClusterNRechitChamberMinus41, &b_dtRechitClusterNRechitChamberMinus41);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus42", dtRechitClusterNRechitChamberMinus42, &b_dtRechitClusterNRechitChamberMinus42);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus11", dtRechitClusterNLayersChamberPlus11, &b_dtRechitClusterNLayersChamberPlus11);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus12", dtRechitClusterNLayersChamberPlus12, &b_dtRechitClusterNLayersChamberPlus12);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus13", dtRechitClusterNLayersChamberPlus13, &b_dtRechitClusterNLayersChamberPlus13);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus21", dtRechitClusterNLayersChamberPlus21, &b_dtRechitClusterNLayersChamberPlus21);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus22", dtRechitClusterNLayersChamberPlus22, &b_dtRechitClusterNLayersChamberPlus22);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus31", dtRechitClusterNLayersChamberPlus31, &b_dtRechitClusterNLayersChamberPlus31);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus32", dtRechitClusterNLayersChamberPlus32, &b_dtRechitClusterNLayersChamberPlus32);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus41", dtRechitClusterNLayersChamberPlus41, &b_dtRechitClusterNLayersChamberPlus41);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus42", dtRechitClusterNLayersChamberPlus42, &b_dtRechitClusterNLayersChamberPlus42);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus11", dtRechitClusterNLayersChamberMinus11, &b_dtRechitClusterNLayersChamberMinus11);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus12", dtRechitClusterNLayersChamberMinus12, &b_dtRechitClusterNLayersChamberMinus12);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus13", dtRechitClusterNLayersChamberMinus13, &b_dtRechitClusterNLayersChamberMinus13);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus21", dtRechitClusterNLayersChamberMinus21, &b_dtRechitClusterNLayersChamberMinus21);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus22", dtRechitClusterNLayersChamberMinus22, &b_dtRechitClusterNLayersChamberMinus22);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus31", dtRechitClusterNLayersChamberMinus31, &b_dtRechitClusterNLayersChamberMinus31);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus32", dtRechitClusterNLayersChamberMinus32, &b_dtRechitClusterNLayersChamberMinus32);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus41", dtRechitClusterNLayersChamberMinus41, &b_dtRechitClusterNLayersChamberMinus41);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus42", dtRechitClusterNLayersChamberMinus42, &b_dtRechitClusterNLayersChamberMinus42);
   fChain->SetBranchAddress("dtRechitCluster_match_RPCTime_dPhi0p5", dtRechitCluster_match_RPCTime_dPhi0p5, &b_dtRechitCluster_match_RPCTime_dPhi0p5);
   fChain->SetBranchAddress("dtRechitCluster_match_RPCTimeSpread_dPhi0p5", dtRechitCluster_match_RPCTimeSpread_dPhi0p5, &b_dtRechitCluster_match_RPCTimeSpread_dPhi0p5);
   fChain->SetBranchAddress("dtRechitCluster_match_RPCTime_dR0p4", dtRechitCluster_match_RPCTime_dR0p4, &b_dtRechitCluster_match_RPCTime_dR0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_RPCTimeSpread_dR0p4", dtRechitCluster_match_RPCTimeSpread_dR0p4, &b_dtRechitCluster_match_RPCTimeSpread_dR0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_RPChits_dR0p4", dtRechitCluster_match_RPChits_dR0p4, &b_dtRechitCluster_match_RPChits_dR0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_RPCTime_sameStation_dR0p4", dtRechitCluster_match_RPCTime_sameStation_dR0p4, &b_dtRechitCluster_match_RPCTime_sameStation_dR0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4", dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4, &b_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_RPChits_sameStation_dR0p4", dtRechitCluster_match_RPChits_sameStation_dR0p4, &b_dtRechitCluster_match_RPChits_sameStation_dR0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_gLLP_deltaR", dtRechitCluster_match_gLLP_deltaR, &b_dtRechitCluster_match_gLLP_deltaR);
   fChain->SetBranchAddress("dtRechitCluster_match_RPChits_dPhi0p5", dtRechitCluster_match_RPChits_dPhi0p5, &b_dtRechitCluster_match_RPChits_dPhi0p5);
   fChain->SetBranchAddress("dtRechitCluster_match_RPCBx_dPhi0p5", dtRechitCluster_match_RPCBx_dPhi0p5, &b_dtRechitCluster_match_RPCBx_dPhi0p5);
   fChain->SetBranchAddress("dtRechitCluster_match_RB1_0p4", dtRechitCluster_match_RB1_0p4, &b_dtRechitCluster_match_RB1_0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_RB1_dPhi0p5", dtRechitCluster_match_RB1_dPhi0p5, &b_dtRechitCluster_match_RB1_dPhi0p5);
   fChain->SetBranchAddress("dtRechitCluster_match_MB1Seg_0p4", dtRechitCluster_match_MB1Seg_0p4, &b_dtRechitCluster_match_MB1Seg_0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_MB1Seg_0p5", dtRechitCluster_match_MB1Seg_0p5, &b_dtRechitCluster_match_MB1Seg_0p5);
   fChain->SetBranchAddress("dtRechitCluster_match_MB1hits_0p4", dtRechitCluster_match_MB1hits_0p4, &b_dtRechitCluster_match_MB1hits_0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_MB1hits_0p5", dtRechitCluster_match_MB1hits_0p5, &b_dtRechitCluster_match_MB1hits_0p5);
   fChain->SetBranchAddress("dtRechitCluster_match_MB1hits_cosmics_plus", dtRechitCluster_match_MB1hits_cosmics_plus, &b_dtRechitCluster_match_MB1hits_cosmics_plus);
   fChain->SetBranchAddress("dtRechitCluster_match_MB1hits_cosmics_minus", dtRechitCluster_match_MB1hits_cosmics_minus, &b_dtRechitCluster_match_MB1hits_cosmics_minus);
   fChain->SetBranchAddress("dtRechitClusterJetVetoPt", dtRechitClusterJetVetoPt, &b_dtRechitClusterJetVetoPt);
   fChain->SetBranchAddress("dtRechitClusterJetVetoEta", dtRechitClusterJetVetoEta, &b_dtRechitClusterJetVetoEta);
   fChain->SetBranchAddress("dtRechitClusterJetVetoPhi", dtRechitClusterJetVetoPhi, &b_dtRechitClusterJetVetoPhi);
   fChain->SetBranchAddress("dtRechitClusterJetVetoE", dtRechitClusterJetVetoE, &b_dtRechitClusterJetVetoE);
   fChain->SetBranchAddress("dtRechitClusterMuonVetoPt", dtRechitClusterMuonVetoPt, &b_dtRechitClusterMuonVetoPt);
   fChain->SetBranchAddress("dtRechitClusterMuonVetoE", dtRechitClusterMuonVetoE, &b_dtRechitClusterMuonVetoE);
   fChain->SetBranchAddress("dtRechitClusterMuonVetoPhi", dtRechitClusterMuonVetoPhi, &b_dtRechitClusterMuonVetoPhi);
   fChain->SetBranchAddress("dtRechitClusterMuonVetoEta", dtRechitClusterMuonVetoEta, &b_dtRechitClusterMuonVetoEta);
   fChain->SetBranchAddress("dtRechitClusterMuonVetoLooseId", dtRechitClusterMuonVetoLooseId, &b_dtRechitClusterMuonVetoLooseId);
   fChain->SetBranchAddress("dtRechitClusterMuonVetoGlobal", dtRechitClusterMuonVetoGlobal, &b_dtRechitClusterMuonVetoGlobal);
   fChain->SetBranchAddress("dtRechitClusterMetEENoise_dPhi", dtRechitClusterMetEENoise_dPhi, &b_dtRechitClusterMetEENoise_dPhi);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   Notify();
}

Bool_t analyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void analyzer::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t analyzer::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef analyzer_cxx
