#ifndef analyzer_base_h
#define analyzer_base_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <map>

#define N_MAX_LEPTONS 100
#define N_MAX_TRACKS 2000
#define N_MAX_JETS 100
#define N_MAX_CSC 200
#define N_MAX_CSCRECHITS 5000
#define N_MAX_DTRECHITS 20000
#define NTriggersMAX 1201 // Number of trigger in the .dat file
//#define N_CSC_CUT 20
//#define JET_PT_CUT 10
//#define MUON_PT_CUT 20
#define N_MAX_GPARTICLES 5000
#define MAX_MuonHLTFilters 100

class analyzer_base {
public :
   TChain          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   //global variables here
   Bool_t isMC;
   int counter  = 0;
   int counter2 = 0;
   std::vector<TFile*> f_out;
   std::vector<std::vector<int>> DtClusterPassSel_all;
   std::vector<std::vector<int>> CscClusterPassSel_all;
   std::vector<int> muon_list;
   std::vector<int> DtCluster_list;
   std::vector<int> CscCluster_list;

   bool passGoodMuon = false;
   //CSCs
   bool PassClusterSize_csc       = false;
   bool PassOverlapMuon_csc       = false;
   bool OverlapGenLLP_csc         = false;
   bool PassME1112Veto_csc        = false;
   bool PassMB1Veto_csc           = false;
   bool PassRB1Veto_csc           = false;
   bool PassMuonVeto_csc          = false;
   bool PassClusterTime_csc       = false;
   bool PassClusterTimeSpread_csc = false;
   bool PassClusterEta_csc        = false;
   bool PassID_csc                = false;
   //DTs
   bool PassClusterSize_dt = false;
   bool PassOverlapMuon_dt = false;
   bool OverlapGenMuon_dt  = false;
   bool PassRPCMatching_dt = false;
   bool PassMuonVeto_dt    = false;
   bool PassMB1Veto_dt     = false;
   bool PassRPCTimeCut_dt  = false;
   bool PassMB1Adjacent_dt = false;

   std::map<TString,float> cutFlow;
   std::vector<TString> cutFlowKeys;

   // Declaration of leaf types
   UInt_t          runNum;
   UInt_t          MC_condition;
   UInt_t          lumiSec;
   UInt_t          evtNum;
   Float_t         rho;
   UInt_t          npv;
   Bool_t          Flag2_all;
   Float_t         pileupWeight;
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
   Float_t         gParticleE[N_MAX_GPARTICLES];          //[nGenParticles]
   Float_t         gParticlePt[N_MAX_GPARTICLES];         //[nGenParticles]
   Float_t         gParticleEta[N_MAX_GPARTICLES];        //[nGenParticles]
   Float_t         gParticlePhi[N_MAX_GPARTICLES];        //[nGenParticles]
   Int_t           gParticleId[N_MAX_GPARTICLES];         //[nGenParticles]
   Int_t           gParticleMotherId[N_MAX_GPARTICLES];   //[nGenParticles]
   Int_t           gParticleMotherIndex[N_MAX_GPARTICLES];//[nGenParticles]
   Int_t           nLeptons;
   Float_t         lepE[N_MAX_LEPTONS];   //[nLeptons]
   Float_t         lepPt[N_MAX_LEPTONS];   //[nLeptons]
   UInt_t          lepMuonType[N_MAX_LEPTONS];   //[nLeptons]
   UInt_t          lepMuonQuality[N_MAX_LEPTONS];   //[nLeptons]
   Bool_t          lepMuon_passHLTFilter[N_MAX_LEPTONS][MAX_MuonHLTFilters];   //[nLeptons]
   Float_t         lepEta[N_MAX_LEPTONS];   //[nLeptons]
   Float_t         lepPhi[N_MAX_LEPTONS];   //[nLeptons]
   Int_t           lepPdgId[N_MAX_LEPTONS];   //[nLeptons]
   Float_t         lepDZ[N_MAX_LEPTONS];   //[nLeptons]
   Float_t         lepDXY[N_MAX_LEPTONS];   //[nLeptons]
   Float_t         lepDXYErr[N_MAX_LEPTONS];   //[nLeptons]
   Float_t         lepSF[N_MAX_LEPTONS];   //[nLeptons]
   Bool_t          lepLooseId[N_MAX_LEPTONS];   //[nLeptons]
   Bool_t          lepTightId[N_MAX_LEPTONS];   //[nLeptons]
   Int_t           nJets;
   Float_t         jetE[N_MAX_JETS];   //[nJets]
   Float_t         jetPt[N_MAX_JETS];   //[nJets]
   Float_t         jetEta[N_MAX_JETS];   //[nJets]
   Float_t         jetPhi[N_MAX_JETS];   //[nJets]
   Bool_t          jetTightPassId[N_MAX_JETS];   //[nJets]
   Bool_t          HLTDecision[NTriggersMAX];
   Int_t           nCscRechits;
   Int_t           nDTRechits;
   Int_t           nCscRings;
   Int_t           nDtRings;
   Int_t           nCscRechitClusters;
   Float_t         cscRechitClusterX[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterY[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterZ[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTime[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeWeighted[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeTotal[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeSpread[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeSpreadWeighted[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterTimeSpreadWeightedAll[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterGenMuonDeltaR[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterPhi[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterEta[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterSize[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMe11Ratio[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMe12Ratio[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNStation[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNStation5[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNStation10[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNStation10perc[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterAvgStation[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterAvgStation5[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterAvgStation10[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterAvgStation10perc[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterMaxStation[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMaxStationRatio[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNChamber[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterMaxChamber[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMaxChamberRatio[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus11[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus12[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus13[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus21[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus22[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus31[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus32[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus41[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberPlus42[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus11[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus12[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus13[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus21[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus22[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus31[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus32[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus41[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitClusterNRechitChamberMinus42[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_cscRechits_0p4[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_dtRechits_phi0p2[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_dtRechits_0p4[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_MB1_0p4[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_dtSeg_0p4[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_MB1Seg_0p4[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_RB1_0p4[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           cscRechitCluster_match_RE12_0p4[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitCluster_match_gLLP_deltaR[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterJetVetoPt[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMuonVetoPt[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterGenMuonVetoPt_dR0p8[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterGenMuonVetoPt[N_MAX_CSC];   //[nCscRechitClusters]
   Float_t         cscRechitClusterMetEENoise_dPhi[N_MAX_CSC];   //[nCscRechitClusters]
   Int_t           nDtRechitClusters;
   Float_t         dtRechitClusterMaxDPhi[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMaxDPhi_index[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegStation1[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegStation2[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegStation3[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegStation4[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNOppositeSegStation1[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNOppositeSegStation2[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNOppositeSegStation3[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNOppositeSegStation4[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterX[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterY[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterZ[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterWheel[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterGenMuonDeltaR[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterPhi[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterEta[N_MAX_CSC];   //[nDtRechitClusters]
   Bool_t          dtRechitClusterOverlap[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterSize[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHit[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHitStation1[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHitStation2[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHitStation3[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNoiseHitStation4[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMe11Ratio[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMe12Ratio[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNStation[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNStation5[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNStation10[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNStation10perc[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterAvgStation[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterAvgStation5[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterAvgStation10[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterAvgStation10perc[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMaxStation[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMaxStationRatio[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNChamber[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterMaxChamber[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMaxChamberRatio[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegmentStation1[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegmentStation2[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegmentStation3[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNSegmentStation4[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus11[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus12[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus13[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus21[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus22[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus31[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus32[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus41[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberPlus42[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus11[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus12[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus13[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus21[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus22[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus31[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus32[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus41[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNRechitChamberMinus42[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus11[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus12[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus13[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus21[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus22[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus31[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus32[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus41[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberPlus42[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus11[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus12[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus13[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus21[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus22[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus31[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus32[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus41[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitClusterNLayersChamberMinus42[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTime_dR0p4[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTimeSpread_dR0p4[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RPChits_dR0p4[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTime_dPhi0p5[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTimeSpread_dPhi0p5[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTime_sameStation_dR0p4[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RPChits_sameStation_dR0p4[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitCluster_match_gLLP_deltaR[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RPChits_dPhi0p5[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RPCBx_dPhi0p5[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RB1_0p4[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_RB1_dPhi0p5[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1Seg_0p4[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1Seg_0p5[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1hits_0p4[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1hits_0p5[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1hits_cosmics_plus[N_MAX_CSC];   //[nDtRechitClusters]
   Int_t           dtRechitCluster_match_MB1hits_cosmics_minus[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterJetVetoPt[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterJetVetoE[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterGenMuonVetoPt[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterGenMuonVetoPt_dR0p8[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMuonVetoPt[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         dtRechitClusterMetEENoise_dPhi[N_MAX_CSC];   //[nDtRechitClusters]
   Float_t         weight;

   // List of branches
   TBranch        *b_runNum;   //!
   TBranch        *b_MC_condition;   //!
   TBranch        *b_lumiSec;   //!
   TBranch        *b_evtNum;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_npv;   //!
   TBranch        *b_Flag2_all;   //!
   TBranch        *b_pileupWeight;   //!
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
   TBranch        *b_nJets;   //!
   TBranch        *b_jetE;   //!
   TBranch        *b_jetPt;   //!
   TBranch        *b_jetEta;   //!
   TBranch        *b_jetPhi;   //!
   TBranch        *b_jetTightPassId;   //!
   TBranch        *b_HLTDecision;   //!
   TBranch        *b_nCscRechits;   //!
   TBranch        *b_nDTRechits;   //!
   TBranch        *b_nCscRings;   //!
   TBranch        *b_nDtRings;   //!
   TBranch        *b_nCscRechitClusters;   //!
   TBranch        *b_cscRechitClusterX;   //!
   TBranch        *b_cscRechitClusterY;   //!
   TBranch        *b_cscRechitClusterZ;   //!
   TBranch        *b_cscRechitClusterTime;   //!
   TBranch        *b_cscRechitClusterTimeTotal;   //!
   TBranch        *b_cscRechitClusterTimeWeighted;   //!
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
   TBranch        *b_cscRechitClusterMuonVetoPt;   //!
   TBranch        *b_cscRechitClusterGenMuonVetoPt_dR0p8;   //!
   TBranch        *b_cscRechitClusterGenMuonVetoPt;   //!
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
   TBranch        *b_dtRechitClusterWheel;   //!
   TBranch        *b_dtRechitClusterGenMuonDeltaR;   //!
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
   TBranch        *b_dtRechitClusterJetVetoE;   //!
   TBranch        *b_dtRechitClusterGenMuonVetoPt;   //!
   TBranch        *b_dtRechitClusterGenMuonVetoPt_dR0p8;   //!
   TBranch        *b_dtRechitClusterMuonVetoPt;   //!
   TBranch        *b_dtRechitClusterMetEENoise_dPhi;   //!
   TBranch        *b_weight;   //!




   analyzer_base();
   virtual ~analyzer_base();
   virtual void Init(TChain *tree, Bool_t isMC_);
   virtual Long64_t LoadTree(Long64_t entry);
   double        dR(double eta1, double phi1, double eta2, double phi2);
   double        DeltaPhi(double phi1, double phi2);
};
#endif
