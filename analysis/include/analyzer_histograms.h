#ifndef analyzer_histograms_h
#define analyzer_histograms_h

#include "TH1F.h"
#include "TH2F.h"

#include "analyzer_selections.h"

class analyzer_histograms : public analyzer_selections{

  public : 
 
           analyzer_histograms();
  virtual ~analyzer_histograms();

  TH1F* h_nLeptons                      [SELBINNAMESIZE];


  TH1F* h_cscRechitClusterDPhiLeadMuon           [SELBINNAMESIZE];
  TH1F* h_nCscRechits                            [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterSize                   [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterPhi                    [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterEta                    [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterTime                   [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterTimeWeighted           [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterTimeTotal              [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterTimeSpread             [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterTimeSpreadWeighted     [SELBINNAMESIZE];
  TH1F* h_cscRechitClusterTimeSpreadWeightedAll  [SELBINNAMESIZE];


  TH1F* h_dtRechitClusterDPhiLeadMuon                            [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPCBx_dPhi0p5                    [SELBINNAMESIZE];
  TH1F* h_nDTRechits                                             [SELBINNAMESIZE];
  TH1F* h_dtRechitClusterSize                                    [SELBINNAMESIZE];
  TH1F* h_dtRechitClusterPhi                                     [SELBINNAMESIZE];
  TH1F* h_dtRechitClusterEta                                     [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPCTime_dR0p4                    [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPCTimeSpread_dR0p4              [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPChits_dR0p4                    [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPCTime_dPhi0p5                  [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5            [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPCTime_sameStation_dR0p4        [SELBINNAMESIZE];
  TH1F* h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4  [SELBINNAMESIZE];
  
  void InitHistos();
  void FillHistos( int selbin );
  void WriteHistos( int selbin );
  void DeleteHistos( int selbin );


};

#endif

