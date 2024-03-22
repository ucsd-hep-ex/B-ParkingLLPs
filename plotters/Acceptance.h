//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Mar 20 13:[N_MAX_Cluster][N_MAX_GEN]:14 2024 by ROOT version [N_MAX_GEN].10/09
// from TTree MuonSystem/MuonSystem
// found on file: /uscms/home/ahayrape/nobackup/BToPhiK_Analysis/New_signal/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300.root
//////////////////////////////////////////////////////////

#ifndef Acceptance_h
#define Acceptance_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>


#define N_MAX_GEN 200
#define N_MAX_Cluster 200
// Header file for the classes stored in the TTree if any.

class Acceptance {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           nCscRechitClusters;
   Float_t         cscRechitClusterPhi[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterEta[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           nDtRechitClusters;
   Float_t         dtRechitClusterPhi[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterEta[N_MAX_Cluster];   //[nDtRechitClusters]
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
   Bool_t          HLTDecision[1201];

   /*
   UInt_t          runNum;
   UInt_t          MC_condition;
   UInt_t          lumiSec;
   UInt_t          evtNum;
   Float_t         rho;
   Int_t           npv;
   Int_t           npu;
   Float_t         pileupWeight;
   Float_t         pileupWeightUp;
   Float_t         pileupWeightDown;
   Float_t         genWeight;
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
   Int_t           nGenParticles;
   Float_t         gParticleE[N_MAX_GEN];   //[nGenParticles]
   Float_t         gParticlePt[N_MAX_GEN];   //[nGenParticles]
   Float_t         gParticleEta[N_MAX_GEN];   //[nGenParticles]
   Float_t         gParticlePhi[N_MAX_GEN];   //[nGenParticles]
   Int_t           gParticleId[N_MAX_GEN];   //[nGenParticles]
   Int_t           gParticleMotherId[N_MAX_GEN];   //[nGenParticles]
   Int_t           gParticleMotherIndex[N_MAX_GEN];   //[nGenParticles]
   Int_t           nLeptons;
   Float_t         lepE[29];   //[nLeptons]
   Float_t         lepPt[29];   //[nLeptons]
   UInt_t          lepMuonType[29];   //[nLeptons]
   UInt_t          lepMuonQuality[29];   //[nLeptons]
   Bool_t          lepMuon_passHLTFilter[29][100];   //[nLeptons]
   Float_t         lepEta[29];   //[nLeptons]
   Float_t         lepPhi[29];   //[nLeptons]
   Int_t           lepPdgId[29];   //[nLeptons]
   Float_t         lepDZ[29];   //[nLeptons]
   Float_t         lepDXY[29];   //[nLeptons]
   Float_t         lepDXYErr[29];   //[nLeptons]
   Float_t         lepSF[29];   //[nLeptons]
   Bool_t          lepLooseId[29];   //[nLeptons]
   Bool_t          lepTightId[29];   //[nLeptons]
   Bool_t          HLTDecision[1201];
   Int_t           nCscRechits;
   Int_t           nDtRechits;
   Int_t           nCscRings;
   Int_t           nDtRings;
   Float_t         cscRechitClusterX[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterY[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterZ[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTime[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeWeighted[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeTotal[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeSpread[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeSpreadWeighted[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeSpreadWeightedAll[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterGenMuonDeltaR[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterSize[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMe11Ratio[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMe12Ratio[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNStation[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNStation5[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNStation10[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNStation10perc[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterAvgStation[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterAvgStation5[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterAvgStation10[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterAvgStation10perc[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMatchedTrackSumPt_0p2[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMatchedTrackLeadPt_0p2[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterMatchedTrackSize_0p2[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMatchedTrackSumPt_0p3[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMatchedTrackLeadPt_0p3[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterMatchedTrackSize_0p3[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMatchedTrackSumPt_0p4[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMatchedTrackLeadPt_0p4[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterMatchedTrackSize_0p4[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMatchedTrackSumPt_trk_pos_0p5[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMatchedTrackLeadPt_trk_pos_0p5[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterMatchedTrackSize_trk_pos_0p5[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMatchedTrackSumPt_trk_pos_0p2[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMatchedTrackLeadPt_trk_pos_0p2[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterMatchedTrackSize_trk_pos_0p2[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMatchedTrackSumPt_trk_pos_0p3[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMatchedTrackLeadPt_trk_pos_0p3[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterMatchedTrackSize_trk_pos_0p3[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMatchedTrackSumPt_trk_pos_0p4[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMatchedTrackLeadPt_trk_pos_0p4[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterMatchedTrackSize_trk_pos_0p4[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterMaxStation[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMaxStationRatio[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNChamber[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterMaxChamber[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMaxChamberRatio[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus11[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus12[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus13[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus21[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus22[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus31[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus32[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus41[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus42[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus11[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus12[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus13[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus21[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus22[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus31[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus32[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus41[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus42[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_dtSeg_0p4[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_MB1Seg_0p4[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_RB1_0p4[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_RE12_0p4[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitCluster_match_gLLP_deltaR[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterJetVetoPt[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMuonVetoPt[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterGenMuonVetoPt_dR0p8[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterGenMuonVetoPt[N_MAX_Cluster];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMetEENoise_dPhi[N_MAX_Cluster];   //[nCscRechitClusters]
   Int_t           nDtRechitClusters;
   Float_t         dtRechitClusterMaxDPhi[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMaxDPhi_index[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackSumPt_0p2[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackLeadPt_0p2[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMatchedTrackSize_0p2[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackSumPt_0p3[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackLeadPt_0p3[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMatchedTrackSize_0p3[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackSumPt_0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackLeadPt_0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMatchedTrackSize_0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackSumPt_0p5[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackLeadPt_0p5[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMatchedTrackSize_0p5[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackSumPt_trk_pos_0p2[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackLeadPt_trk_pos_0p2[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMatchedTrackSize_trk_pos_0p2[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackSumPt_trk_pos_0p3[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackLeadPt_trk_pos_0p3[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMatchedTrackSize_trk_pos_0p3[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackSumPt_trk_pos_0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackLeadPt_trk_pos_0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMatchedTrackSize_trk_pos_0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackSumPt_trk_pos_0p5[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMatchedTrackLeadPt_trk_pos_0p5[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMatchedTrackSize_trk_pos_0p5[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegStation1[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegStation2[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegStation3[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegStation4[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNOppositeSegStation1[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNOppositeSegStation2[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNOppositeSegStation3[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNOppositeSegStation4[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterX[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterY[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterZ[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterWheel[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterPhi[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterEta[N_MAX_Cluster];   //[nDtRechitClusters]
   Bool_t          dtRechitClusterOverlap[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterSize[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHit[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHitStation1[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHitStation2[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHitStation3[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHitStation4[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMe11Ratio[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMe12Ratio[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNStation[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNStation5[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNStation10[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNStation10perc[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterAvgStation[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterAvgStation5[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterAvgStation10[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterAvgStation10perc[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMaxStation[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMaxStationRatio[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNChamber[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMaxChamber[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMaxChamberRatio[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegmentStation1[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegmentStation2[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegmentStation3[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegmentStation4[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTime_dPhi0p5[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTimeSpread_dPhi0p5[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTime_dR0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTimeSpread_dR0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RPChits_dR0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTime_sameStation_dR0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RPChits_sameStation_dR0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_gLLP_deltaR[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RPChits_dPhi0p5[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RPCBx_dPhi0p5[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RB1_0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RB1_dPhi0p5[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1Seg_0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1Seg_0p5[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1hits_0p4[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1hits_0p5[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1hits_cosmics_plus[N_MAX_Cluster];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1hits_cosmics_minus[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterJetVetoPt[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterJetVetoE[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterGenMuonVetoPt[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterGenMuonVetoPt_dR0p8[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMuonVetoPt[N_MAX_Cluster];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMetEENoise_dPhi[N_MAX_Cluster];   //[nDtRechitClusters]
   */
   TBranch        *b_nDtRings;   //!
   TBranch        *b_nCscRechitClusters;   //!
   TBranch        *b_cscRechitClusterPhi;   //!
   TBranch        *b_cscRechitClusterEta;   //!
   TBranch        *b_nDtRechitClusters;   //!
   TBranch        *b_dtRechitClusterPhi;   //!
   TBranch        *b_dtRechitClusterEta;   //!
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
   TBranch        *b_HLTDecision;   //!
   // List of branches
   /*
   TBranch        *b_runNum;   //!
   TBranch        *b_MC_condition;   //!
   TBranch        *b_lumiSec;   //!
   TBranch        *b_evtNum;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_npv;   //!
   TBranch        *b_npu;   //!
   TBranch        *b_pileupWeight;   //!
   TBranch        *b_pileupWeightUp;   //!
   TBranch        *b_pileupWeightDown;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_Flag2_all;   //!
   TBranch        *b_metEENoise;   //!
   TBranch        *b_metPhiEENoise;   //!
   TBranch        *b_nGenParticles;   //!
   TBranch        *b_gParticleE;   //!
   TBranch        *b_gParticlePt;   //!
   TBranch        *b_gParticleEta;   //!
   TBranch        *b_gParticlePhi;   //!
   TBranch        *b_gParticleId;   //!
   TBranch        *b_gParticleMotherId;   //!
   TBranch        *b_gParticleMotherIndex;   //!
   TBranch        *b_nLeptons;   //!
   TBranch        *b_lepE;   //!
   TBranch        *b_lepPt;   //!
   TBranch        *b_lepMuonType;   //!
   TBranch        *b_lepMuonQuality;   //!
   TBranch        *b_lepMuon_passHLTFilter;   //!
   TBranch        *b_lepEta;   //!
   TBranch        *b_lepPhi;   //!
   TBranch        *b_lepPdgId;   //!
   TBranch        *b_lepDZ;   //!
   TBranch        *b_lepDXY;   //!
   TBranch        *b_lepDXYErr;   //!
   TBranch        *b_lepSF;   //!
   TBranch        *b_lepLooseId;   //!
   TBranch        *b_lepTightId;   //!
   TBranch        *b_nCscRechits;   //!
   TBranch        *b_nDtRechits;   //!
   TBranch        *b_nCscRings;   //!
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
   TBranch        *b_cscRechitClusterMatchedTrackSumPt_0p2;   //!
   TBranch        *b_cscRechitClusterMatchedTrackLeadPt_0p2;   //!
   TBranch        *b_cscRechitClusterMatchedTrackSize_0p2;   //!
   TBranch        *b_cscRechitClusterMatchedTrackSumPt_0p3;   //!
   TBranch        *b_cscRechitClusterMatchedTrackLeadPt_0p3;   //!
   TBranch        *b_cscRechitClusterMatchedTrackSize_0p3;   //!
   TBranch        *b_cscRechitClusterMatchedTrackSumPt_0p4;   //!
   TBranch        *b_cscRechitClusterMatchedTrackLeadPt_0p4;   //!
   TBranch        *b_cscRechitClusterMatchedTrackSize_0p4;   //!
   TBranch        *b_cscRechitClusterMatchedTrackSumPt_trk_pos_0p5;   //!
   TBranch        *b_cscRechitClusterMatchedTrackLeadPt_trk_pos_0p5;   //!
   TBranch        *b_cscRechitClusterMatchedTrackSize_trk_pos_0p5;   //!
   TBranch        *b_cscRechitClusterMatchedTrackSumPt_trk_pos_0p2;   //!
   TBranch        *b_cscRechitClusterMatchedTrackLeadPt_trk_pos_0p2;   //!
   TBranch        *b_cscRechitClusterMatchedTrackSize_trk_pos_0p2;   //!
   TBranch        *b_cscRechitClusterMatchedTrackSumPt_trk_pos_0p3;   //!
   TBranch        *b_cscRechitClusterMatchedTrackLeadPt_trk_pos_0p3;   //!
   TBranch        *b_cscRechitClusterMatchedTrackSize_trk_pos_0p3;   //!
   TBranch        *b_cscRechitClusterMatchedTrackSumPt_trk_pos_0p4;   //!
   TBranch        *b_cscRechitClusterMatchedTrackLeadPt_trk_pos_0p4;   //!
   TBranch        *b_cscRechitClusterMatchedTrackSize_trk_pos_0p4;   //!
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
   TBranch        *b_cscRechitCluster_match_dtSeg_0p4;   //!
   TBranch        *b_cscRechitCluster_match_MB1Seg_0p4;   //!
   TBranch        *b_cscRechitCluster_match_RB1_0p4;   //!
   TBranch        *b_cscRechitCluster_match_RE12_0p4;   //!
   TBranch        *b_cscRechitCluster_match_gLLP_deltaR;   //!
   TBranch        *b_cscRechitClusterJetVetoPt;   //!
   TBranch        *b_cscRechitClusterMuonVetoPt;   //!
   TBranch        *b_cscRechitClusterGenMuonVetoPt_dR0p8;   //!
   TBranch        *b_cscRechitClusterGenMuonVetoPt;   //!
   TBranch        *b_cscRechitClusterMetEENoise_dPhi;   //!
   TBranch        *b_nDtRechitClusters;   //!
   TBranch        *b_dtRechitClusterMaxDPhi;   //!
   TBranch        *b_dtRechitClusterMaxDPhi_index;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSumPt_0p2;   //!
   TBranch        *b_dtRechitClusterMatchedTrackLeadPt_0p2;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSize_0p2;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSumPt_0p3;   //!
   TBranch        *b_dtRechitClusterMatchedTrackLeadPt_0p3;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSize_0p3;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSumPt_0p4;   //!
   TBranch        *b_dtRechitClusterMatchedTrackLeadPt_0p4;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSize_0p4;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSumPt_0p5;   //!
   TBranch        *b_dtRechitClusterMatchedTrackLeadPt_0p5;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSize_0p5;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSumPt_trk_pos_0p2;   //!
   TBranch        *b_dtRechitClusterMatchedTrackLeadPt_trk_pos_0p2;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSize_trk_pos_0p2;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSumPt_trk_pos_0p3;   //!
   TBranch        *b_dtRechitClusterMatchedTrackLeadPt_trk_pos_0p3;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSize_trk_pos_0p3;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSumPt_trk_pos_0p4;   //!
   TBranch        *b_dtRechitClusterMatchedTrackLeadPt_trk_pos_0p4;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSize_trk_pos_0p4;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSumPt_trk_pos_0p5;   //!
   TBranch        *b_dtRechitClusterMatchedTrackLeadPt_trk_pos_0p5;   //!
   TBranch        *b_dtRechitClusterMatchedTrackSize_trk_pos_0p5;   //!
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
   TBranch        *b_dtRechitClusterWheel;   //!
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
   TBranch        *b_dtRechitClusterJetVetoE;   //!
   TBranch        *b_dtRechitClusterGenMuonVetoPt;   //!
   TBranch        *b_dtRechitClusterGenMuonVetoPt_dR0p8;   //!
   TBranch        *b_dtRechitClusterMuonVetoPt;   //!
   TBranch        *b_dtRechitClusterMetEENoise_dPhi;   //!
   */

   Acceptance(TTree *tree=0);
   virtual ~Acceptance();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(int, char**);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   double dR(double eta1, double phi1, double eta2, double phi2);
   double DeltaPhi(double phi1, double phi2);
   Double_t ctau_weight_rescale(float ct, float ctp, float cti);
   bool HLT_cuts();
};

#endif

#ifdef Acceptance_cxx
Acceptance::Acceptance(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/uscms/home/ahayrape/nobackup/BToPhiK_Analysis/New_signal/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/uscms/home/ahayrape/nobackup/BToPhiK_Analysis/New_signal/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300.root");
      }
      f->GetObject("MuonSystem",tree);

   }
   Init(tree);
}

Acceptance::~Acceptance()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Acceptance::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Acceptance::LoadTree(Long64_t entry)
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

void Acceptance::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);
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
   fChain->SetBranchAddress("HLTDecision", HLTDecision, &b_HLTDecision);
   fChain->SetBranchAddress("nCscRechitClusters", &nCscRechitClusters, &b_nCscRechitClusters);
   fChain->SetBranchAddress("cscRechitClusterPhi", cscRechitClusterPhi, &b_cscRechitClusterPhi);
   fChain->SetBranchAddress("cscRechitClusterEta", cscRechitClusterEta, &b_cscRechitClusterEta);
   fChain->SetBranchAddress("nDtRechitClusters", &nDtRechitClusters, &b_nDtRechitClusters);
   fChain->SetBranchAddress("dtRechitClusterPhi", dtRechitClusterPhi, &b_dtRechitClusterPhi);
   fChain->SetBranchAddress("dtRechitClusterEta", dtRechitClusterEta, &b_dtRechitClusterEta);

   /*
   fChain->SetBranchAddress("runNun", &runNum, &b_runNum);
   fChain->SetBranchAddress("MC_condition", &MC_condition, &b_MC_condition);
   fChain->SetBranchAddress("lumiSec", &lumiSec, &b_lumiSec);
   fChain->SetBranchAddress("evtNum", &evtNum, &b_evtNum);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("npv", &npv, &b_npv);
   fChain->SetBranchAddress("npu", &npu, &b_npu);
   fChain->SetBranchAddress("pileupWeight", &pileupWeight, &b_pileupWeight);
   fChain->SetBranchAddress("pileupWeightUp", &pileupWeightUp, &b_pileupWeightUp);
   fChain->SetBranchAddress("pileupWeightDown", &pileupWeightDown, &b_pileupWeightDown);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
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
   fChain->SetBranchAddress("nGenParticles", &nGenParticles, &b_nGenParticles);
   fChain->SetBranchAddress("gParticleE", gParticleE, &b_gParticleE);
   fChain->SetBranchAddress("gParticlePt", gParticlePt, &b_gParticlePt);
   fChain->SetBranchAddress("gParticleEta", gParticleEta, &b_gParticleEta);
   fChain->SetBranchAddress("gParticlePhi", gParticlePhi, &b_gParticlePhi);
   fChain->SetBranchAddress("gParticleId", gParticleId, &b_gParticleId);
   fChain->SetBranchAddress("gParticleMotherId", gParticleMotherId, &b_gParticleMotherId);
   fChain->SetBranchAddress("gParticleMotherIndex", gParticleMotherIndex, &b_gParticleMotherIndex);
   fChain->SetBranchAddress("nLeptons", &nLeptons, &b_nLeptons);
   fChain->SetBranchAddress("lepE", lepE, &b_lepE);
   fChain->SetBranchAddress("lepPt", lepPt, &b_lepPt);
   fChain->SetBranchAddress("lepMuonType", lepMuonType, &b_lepMuonType);
   fChain->SetBranchAddress("lepMuonQuality", lepMuonQuality, &b_lepMuonQuality);
   fChain->SetBranchAddress("lepMuon_passHLTFilter", lepMuon_passHLTFilter, &b_lepMuon_passHLTFilter);
   fChain->SetBranchAddress("lepEta", lepEta, &b_lepEta);
   fChain->SetBranchAddress("lepPhi", lepPhi, &b_lepPhi);
   fChain->SetBranchAddress("lepPdgId", lepPdgId, &b_lepPdgId);
   fChain->SetBranchAddress("lepDZ", lepDZ, &b_lepDZ);
   fChain->SetBranchAddress("lepDXY", lepDXY, &b_lepDXY);
   fChain->SetBranchAddress("lepDXYErr", lepDXYErr, &b_lepDXYErr);
   fChain->SetBranchAddress("lepSF", lepSF, &b_lepSF);
   fChain->SetBranchAddress("lepLooseId", lepLooseId, &b_lepLooseId);
   fChain->SetBranchAddress("lepTightId", lepTightId, &b_lepTightId);
   fChain->SetBranchAddress("HLTDecision", HLTDecision, &b_HLTDecision);
   fChain->SetBranchAddress("nCscRechits", &nCscRechits, &b_nCscRechits);
   fChain->SetBranchAddress("nDtRechits", &nDtRechits, &b_nDtRechits);
   fChain->SetBranchAddress("nCscRings", &nCscRings, &b_nCscRings);
   fChain->SetBranchAddress("nDtRings", &nDtRings, &b_nDtRings);
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
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackSumPt_0p2", cscRechitClusterMatchedTrackSumPt_0p2, &b_cscRechitClusterMatchedTrackSumPt_0p2);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackLeadPt_0p2", cscRechitClusterMatchedTrackLeadPt_0p2, &b_cscRechitClusterMatchedTrackLeadPt_0p2);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackSize_0p2", cscRechitClusterMatchedTrackSize_0p2, &b_cscRechitClusterMatchedTrackSize_0p2);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackSumPt_0p3", cscRechitClusterMatchedTrackSumPt_0p3, &b_cscRechitClusterMatchedTrackSumPt_0p3);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackLeadPt_0p3", cscRechitClusterMatchedTrackLeadPt_0p3, &b_cscRechitClusterMatchedTrackLeadPt_0p3);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackSize_0p3", cscRechitClusterMatchedTrackSize_0p3, &b_cscRechitClusterMatchedTrackSize_0p3);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackSumPt_0p4", cscRechitClusterMatchedTrackSumPt_0p4, &b_cscRechitClusterMatchedTrackSumPt_0p4);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackLeadPt_0p4", cscRechitClusterMatchedTrackLeadPt_0p4, &b_cscRechitClusterMatchedTrackLeadPt_0p4);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackSize_0p4", cscRechitClusterMatchedTrackSize_0p4, &b_cscRechitClusterMatchedTrackSize_0p4);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackSumPt_trk_pos_0p5", cscRechitClusterMatchedTrackSumPt_trk_pos_0p5, &b_cscRechitClusterMatchedTrackSumPt_trk_pos_0p5);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackLeadPt_trk_pos_0p5", cscRechitClusterMatchedTrackLeadPt_trk_pos_0p5, &b_cscRechitClusterMatchedTrackLeadPt_trk_pos_0p5);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackSize_trk_pos_0p5", cscRechitClusterMatchedTrackSize_trk_pos_0p5, &b_cscRechitClusterMatchedTrackSize_trk_pos_0p5);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackSumPt_trk_pos_0p2", cscRechitClusterMatchedTrackSumPt_trk_pos_0p2, &b_cscRechitClusterMatchedTrackSumPt_trk_pos_0p2);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackLeadPt_trk_pos_0p2", cscRechitClusterMatchedTrackLeadPt_trk_pos_0p2, &b_cscRechitClusterMatchedTrackLeadPt_trk_pos_0p2);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackSize_trk_pos_0p2", cscRechitClusterMatchedTrackSize_trk_pos_0p2, &b_cscRechitClusterMatchedTrackSize_trk_pos_0p2);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackSumPt_trk_pos_0p3", cscRechitClusterMatchedTrackSumPt_trk_pos_0p3, &b_cscRechitClusterMatchedTrackSumPt_trk_pos_0p3);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackLeadPt_trk_pos_0p3", cscRechitClusterMatchedTrackLeadPt_trk_pos_0p3, &b_cscRechitClusterMatchedTrackLeadPt_trk_pos_0p3);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackSize_trk_pos_0p3", cscRechitClusterMatchedTrackSize_trk_pos_0p3, &b_cscRechitClusterMatchedTrackSize_trk_pos_0p3);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackSumPt_trk_pos_0p4", cscRechitClusterMatchedTrackSumPt_trk_pos_0p4, &b_cscRechitClusterMatchedTrackSumPt_trk_pos_0p4);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackLeadPt_trk_pos_0p4", cscRechitClusterMatchedTrackLeadPt_trk_pos_0p4, &b_cscRechitClusterMatchedTrackLeadPt_trk_pos_0p4);
   fChain->SetBranchAddress("cscRechitClusterMatchedTrackSize_trk_pos_0p4", cscRechitClusterMatchedTrackSize_trk_pos_0p4, &b_cscRechitClusterMatchedTrackSize_trk_pos_0p4);
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
   fChain->SetBranchAddress("cscRechitCluster_match_dtSeg_0p4", cscRechitCluster_match_dtSeg_0p4, &b_cscRechitCluster_match_dtSeg_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_MB1Seg_0p4", cscRechitCluster_match_MB1Seg_0p4, &b_cscRechitCluster_match_MB1Seg_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_RB1_0p4", cscRechitCluster_match_RB1_0p4, &b_cscRechitCluster_match_RB1_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_RE12_0p4", cscRechitCluster_match_RE12_0p4, &b_cscRechitCluster_match_RE12_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_gLLP_deltaR", cscRechitCluster_match_gLLP_deltaR, &b_cscRechitCluster_match_gLLP_deltaR);
   fChain->SetBranchAddress("cscRechitClusterJetVetoPt", cscRechitClusterJetVetoPt, &b_cscRechitClusterJetVetoPt);
   fChain->SetBranchAddress("cscRechitClusterMuonVetoPt", cscRechitClusterMuonVetoPt, &b_cscRechitClusterMuonVetoPt);
   fChain->SetBranchAddress("cscRechitClusterGenMuonVetoPt_dR0p8", cscRechitClusterGenMuonVetoPt_dR0p8, &b_cscRechitClusterGenMuonVetoPt_dR0p8);
   fChain->SetBranchAddress("cscRechitClusterGenMuonVetoPt", cscRechitClusterGenMuonVetoPt, &b_cscRechitClusterGenMuonVetoPt);
   fChain->SetBranchAddress("cscRechitClusterMetEENoise_dPhi", cscRechitClusterMetEENoise_dPhi, &b_cscRechitClusterMetEENoise_dPhi);
   fChain->SetBranchAddress("nDtRechitClusters", &nDtRechitClusters, &b_nDtRechitClusters);
   fChain->SetBranchAddress("dtRechitClusterMaxDPhi", dtRechitClusterMaxDPhi, &b_dtRechitClusterMaxDPhi);
   fChain->SetBranchAddress("dtRechitClusterMaxDPhi_index", dtRechitClusterMaxDPhi_index, &b_dtRechitClusterMaxDPhi_index);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSumPt_0p2", dtRechitClusterMatchedTrackSumPt_0p2, &b_dtRechitClusterMatchedTrackSumPt_0p2);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackLeadPt_0p2", dtRechitClusterMatchedTrackLeadPt_0p2, &b_dtRechitClusterMatchedTrackLeadPt_0p2);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSize_0p2", dtRechitClusterMatchedTrackSize_0p2, &b_dtRechitClusterMatchedTrackSize_0p2);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSumPt_0p3", dtRechitClusterMatchedTrackSumPt_0p3, &b_dtRechitClusterMatchedTrackSumPt_0p3);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackLeadPt_0p3", dtRechitClusterMatchedTrackLeadPt_0p3, &b_dtRechitClusterMatchedTrackLeadPt_0p3);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSize_0p3", dtRechitClusterMatchedTrackSize_0p3, &b_dtRechitClusterMatchedTrackSize_0p3);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSumPt_0p4", dtRechitClusterMatchedTrackSumPt_0p4, &b_dtRechitClusterMatchedTrackSumPt_0p4);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackLeadPt_0p4", dtRechitClusterMatchedTrackLeadPt_0p4, &b_dtRechitClusterMatchedTrackLeadPt_0p4);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSize_0p4", dtRechitClusterMatchedTrackSize_0p4, &b_dtRechitClusterMatchedTrackSize_0p4);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSumPt_0p5", dtRechitClusterMatchedTrackSumPt_0p5, &b_dtRechitClusterMatchedTrackSumPt_0p5);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackLeadPt_0p5", dtRechitClusterMatchedTrackLeadPt_0p5, &b_dtRechitClusterMatchedTrackLeadPt_0p5);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSize_0p5", dtRechitClusterMatchedTrackSize_0p5, &b_dtRechitClusterMatchedTrackSize_0p5);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSumPt_trk_pos_0p2", dtRechitClusterMatchedTrackSumPt_trk_pos_0p2, &b_dtRechitClusterMatchedTrackSumPt_trk_pos_0p2);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackLeadPt_trk_pos_0p2", dtRechitClusterMatchedTrackLeadPt_trk_pos_0p2, &b_dtRechitClusterMatchedTrackLeadPt_trk_pos_0p2);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSize_trk_pos_0p2", dtRechitClusterMatchedTrackSize_trk_pos_0p2, &b_dtRechitClusterMatchedTrackSize_trk_pos_0p2);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSumPt_trk_pos_0p3", dtRechitClusterMatchedTrackSumPt_trk_pos_0p3, &b_dtRechitClusterMatchedTrackSumPt_trk_pos_0p3);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackLeadPt_trk_pos_0p3", dtRechitClusterMatchedTrackLeadPt_trk_pos_0p3, &b_dtRechitClusterMatchedTrackLeadPt_trk_pos_0p3);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSize_trk_pos_0p3", dtRechitClusterMatchedTrackSize_trk_pos_0p3, &b_dtRechitClusterMatchedTrackSize_trk_pos_0p3);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSumPt_trk_pos_0p4", dtRechitClusterMatchedTrackSumPt_trk_pos_0p4, &b_dtRechitClusterMatchedTrackSumPt_trk_pos_0p4);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackLeadPt_trk_pos_0p4", dtRechitClusterMatchedTrackLeadPt_trk_pos_0p4, &b_dtRechitClusterMatchedTrackLeadPt_trk_pos_0p4);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSize_trk_pos_0p4", dtRechitClusterMatchedTrackSize_trk_pos_0p4, &b_dtRechitClusterMatchedTrackSize_trk_pos_0p4);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSumPt_trk_pos_0p5", dtRechitClusterMatchedTrackSumPt_trk_pos_0p5, &b_dtRechitClusterMatchedTrackSumPt_trk_pos_0p5);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackLeadPt_trk_pos_0p5", dtRechitClusterMatchedTrackLeadPt_trk_pos_0p5, &b_dtRechitClusterMatchedTrackLeadPt_trk_pos_0p5);
   fChain->SetBranchAddress("dtRechitClusterMatchedTrackSize_trk_pos_0p5", dtRechitClusterMatchedTrackSize_trk_pos_0p5, &b_dtRechitClusterMatchedTrackSize_trk_pos_0p5);
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
   fChain->SetBranchAddress("dtRechitClusterWheel", dtRechitClusterWheel, &b_dtRechitClusterWheel);
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
   fChain->SetBranchAddress("dtRechitClusterJetVetoE", dtRechitClusterJetVetoE, &b_dtRechitClusterJetVetoE);
   fChain->SetBranchAddress("dtRechitClusterGenMuonVetoPt", dtRechitClusterGenMuonVetoPt, &b_dtRechitClusterGenMuonVetoPt);
   fChain->SetBranchAddress("dtRechitClusterGenMuonVetoPt_dR0p8", dtRechitClusterGenMuonVetoPt_dR0p8, &b_dtRechitClusterGenMuonVetoPt_dR0p8);
   fChain->SetBranchAddress("dtRechitClusterMuonVetoPt", dtRechitClusterMuonVetoPt, &b_dtRechitClusterMuonVetoPt);
   fChain->SetBranchAddress("dtRechitClusterMetEENoise_dPhi", dtRechitClusterMetEENoise_dPhi, &b_dtRechitClusterMetEENoise_dPhi);
   */
   Notify();
}

Bool_t Acceptance::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Acceptance::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Acceptance::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Acceptance_cxx
