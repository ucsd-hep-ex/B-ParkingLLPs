#ifndef analyzer_histograms_h
#define analyzer_histograms_h

#include "TH1F.h"
#include "TH2F.h"

#include "analyzer_tree.h"

class analyzer_histograms : public analyzer_tree{

  public : 
 
           analyzer_histograms();
  virtual ~analyzer_histograms();

  TH1F* h_nLeptons                      [SELBINNAMESIZE];
  TH1F* h_gLLP_ctau                      [SELBINNAMESIZE];

  TH1F* h_nJets                      [SELBINNAMESIZE];
  TH1F* h_NoMDS_jetCISV              [SELBINNAMESIZE];
  TH1F* h_NoMDS_jetPt                [SELBINNAMESIZE];
  TH1F* h_NoMDS_jetEta               [SELBINNAMESIZE];
  TH1F* h_NoMDS_jetDPhiLeadMuon      [SELBINNAMESIZE];
  TH1F* h_NoMDS_jetDPhiLeadMuonFine  [SELBINNAMESIZE];
  
  TH1F* h_NoMDS300_jetCISV              [SELBINNAMESIZE];
  TH1F* h_NoMDS300_jetPt                [SELBINNAMESIZE];
  TH1F* h_NoMDS300_jetEta               [SELBINNAMESIZE];
  TH1F* h_NoMDS300_jetDPhiLeadMuon      [SELBINNAMESIZE];
  TH1F* h_NoMDS300_jetDPhiLeadMuonFine  [SELBINNAMESIZE];

  TH1F* h_cscRechitClusterDPhiLeadMuon           [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterDPhiLeadMuon_fail      [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterDPhiLeadMuon_pass      [SELBINNAMESIZE];
  TH1F* h_nCscRechits                            [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterSize                   [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterSize_FailPass          [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterSize_FailPass_uw       [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterSize_v                 [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterSize_v2                [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterPhi                    [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterEta                    [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterEtaZoom                [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterMuonVetoPt             [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterTime                   [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterTimeWeighted           [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterTimeTotal              [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterTimeSpread             [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterTimeSpreadWeighted     [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterTimeSpreadWeightedAll  [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterZ                      [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterNStation               [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterNStation10             [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterMaxStation             [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterJetVetoPt              [SELBINNAMESIZE];

  TH2F* h_cscRechitClusterPhivsEta    [SELBINNAMESIZE];
  TH2F* h_cscRechitClusterDPhivsSize  [SELBINNAMESIZE];

  TH1F* h_dtRechitClusterDPhiLeadMuon                            [SELBINNAMESIZE];
  TH1F* h_dtRechitClusterDPhiLeadMuon_fail                       [SELBINNAMESIZE];
  TH1F* h_dtRechitClusterDPhiLeadMuon_pass                       [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPCBx_dPhi0p5                    [SELBINNAMESIZE];
  TH1F* h_nDTRechits                                             [SELBINNAMESIZE];
  TH1F* h_dtRechitClusterSize                                    [SELBINNAMESIZE];
  TH1F* h_dtRechitClusterSize_FailPass                           [SELBINNAMESIZE];
  TH1F* h_dtRechitClusterSize_FailPass_uw                        [SELBINNAMESIZE];
  TH1F* h_dtRechitClusterSize_v                                  [SELBINNAMESIZE];
  TH1F* h_dtRechitClusterSize_v2                                 [SELBINNAMESIZE];
  TH1F* h_dtRechitClusterPhi                                     [SELBINNAMESIZE];
  TH1F* h_dtRechitClusterEta                                     [SELBINNAMESIZE];
  TH1F* h_dtRechitClusterMuonVetoPt                              [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPCTime_dR0p4                    [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPCTimeSpread_dR0p4              [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPChits_dR0p4                    [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPCTime_dPhi0p5                  [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5            [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPCTime_sameStation_dR0p4        [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4  [SELBINNAMESIZE];
  TH1F* h_dtRechitClusterMaxStation                              [SELBINNAMESIZE];

  void InitHistos();
  void FillHistos( int selbin, Float_t ew);
  void WriteHistos( int selbin );
  void DeleteHistos( int selbin );


};

#endif

