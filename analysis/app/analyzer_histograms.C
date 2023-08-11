#include "analyzer_histograms.h"
#include <iostream>

//----------------------------analyzer_histograms
analyzer_histograms::analyzer_histograms()
{
}

//----------------------~analyzer_histograms
analyzer_histograms::~analyzer_histograms()
{
}

TH1F* InitTH1F (TString name, TString title, int nbins, Float_t binLow, Float_t binHigh){

  TH1F* histoTH1F = new TH1F( name , title , nbins , binLow , binHigh );
  histoTH1F->Sumw2();

  return histoTH1F;
}
TH1F* InitTH1F (TString name, TString title, int nbins, float bins[]){

  TH1F* histoTH1F = new TH1F( name , title , nbins , bins );
  histoTH1F->Sumw2();

  return histoTH1F;
}

void analyzer_histograms::InitHistos(){
  for (int i = 0; i< SELBINNAMESIZE; i++){
    unsigned n_b = 19;
    unsigned n_b2 = 11;
    float x_bins[n_b] = {50,60,70,80,89,100,110,120,130,140,150,160,170,180,190,200,225,260,300};
    float x_bins2[n_b2] = {130,140,150,160,170,180,190,200,225,260,300};
    f_out[i]->cd();
    h_nLeptons                             [i]             = InitTH1F("h_nLeptons", "h_nLeptons", 100, 0, 100);
    h_nCscRechits                          [i] = InitTH1F("nCscRechits", "nCscRechits", 300, 0, 300);
    h_cscRechitClusterSize                 [i] = InitTH1F("h_cscRechitClusterSize", "h_cscRechitClusterSize", 250, 50, 300);
    h_cscRechitClusterSize_v               [i] = InitTH1F("h_cscRechitClusterSize_v", "h_cscRechitClusterSize_v", n_b-1, x_bins);
    h_cscRechitClusterSize_v2              [i] = InitTH1F("h_cscRechitClusterSize_v2", "h_cscRechitClusterSize_v2", n_b2-1, x_bins2);
    h_cscRechitClusterPhi                  [i] = InitTH1F("h_cscRechitClusterPhi", "h_cscRechitClusterPhi", 40, -3.5, 3.5);
    h_cscRechitClusterEta                  [i] = InitTH1F("h_cscRechitClusterEta", "h_cscRechitClusterEta", 40, -5., 5.);
    h_cscRechitClusterDPhiLeadMuon         [i] = InitTH1F("h_cscRechitClusterDPhiLeadMuon", "h_cscRechitClusterDPhiLeadMuon", 30, 0, 4);
    h_cscRechitClusterTime                 [i] = InitTH1F("h_cscRechitClusterTime"                 , "h_cscRechitClusterTime",         200, -100, 100);
    h_cscRechitClusterTimeWeighted         [i] = InitTH1F("h_cscRechitClusterTimeWeighted"         , "h_cscRechitClusterTimeWeighted", 200, -100, 100);
    h_cscRechitClusterTimeTotal            [i] = InitTH1F("h_cscRechitClusterTimeTotal"            , "h_cscRechitClusterTimeTotal",    200, -100, 100);
    h_cscRechitClusterTimeSpread           [i] = InitTH1F("h_cscRechitClusterTimeSpread",            "h_cscRechitClusterTimeSpread",            200, 0, 200);
    h_cscRechitClusterTimeSpreadWeighted   [i] = InitTH1F("h_cscRechitClusterTimeSpreadWeighted",     "h_cscRechitClusterTimeSpreadWeighted",   200, 0, 200);
    h_cscRechitClusterTimeSpreadWeightedAll[i] = InitTH1F("h_cscRechitClusterTimeSpreadWeightedAll", "h_cscRechitClusterTimeSpreadWeightedAll", 200, 0, 200);


    h_nDTRechits                                           [i] = InitTH1F("h_nDTRechits",  "h_nDTRechits",  300, 0, 300);
    h_dtRechitClusterSize                                  [i] = InitTH1F("h_dtRechitClusterSize",  "h_dtRechitClusterSize",  250, 50, 300);
    h_dtRechitClusterPhi                                   [i] = InitTH1F("h_dtRechitClusterPhi",  "h_dtRechitClusterPhi",  40, -3.5, 3.5);
    h_dtRechitClusterEta                                   [i] = InitTH1F("h_dtRechitClusterEta",  "h_dtRechitClusterEta",  40, -5., 5);
    h_dtRechitClusterDPhiLeadMuon                          [i] = InitTH1F("h_dtRechitClusterDPhiLeadMuon",  "h_dtRechitClusterDPhiLeadMuon",  30, 0, 4);
    h_dtRechitCluster_match_RPCBx_dPhi0p5                  [i] = InitTH1F("h_dtRechitCluster_match_RPCBx_dPhi0p5",  "h_dtRechitCluster_match_RPCBx_dPhi0p5",  20, -10, 10);
    h_dtRechitCluster_match_RPCTime_dR0p4                  [i] = InitTH1F("h_dtRechitCluster_match_RPCTime_dR0p4", "h_dtRechitCluster_match_RPCTime_dR0p4",  200, -100, 100);
    h_dtRechitCluster_match_RPCTimeSpread_dR0p4            [i] = InitTH1F("h_dtRechitCluster_match_RPCTimeSpread_dR0p4", "h_dtRechitCluster_match_RPCTimeSpread_dR0p4",  200, -100, 100);
    h_dtRechitCluster_match_RPChits_dR0p4                  [i] = InitTH1F("h_dtRechitCluster_match_RPChits_dR0p4", "h_dtRechitCluster_match_RPChits_dR0p4",  200, -100, 100);
    h_dtRechitCluster_match_RPCTime_dPhi0p5                [i] = InitTH1F("h_dtRechitCluster_match_RPCTime_dPhi0p5",  "h_dtRechitCluster_match_RPCTime_dPhi0p5",  200, -100, 100);
    h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5          [i] = InitTH1F("h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5", "h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5",  200, -100, 100);
    h_dtRechitCluster_match_RPCTime_sameStation_dR0p4      [i] = InitTH1F("h_dtRechitCluster_match_RPCTime_sameStation_dR0p4", "h_dtRechitCluster_match_RPCTime_sameStation_dR0p4", 200, -100, 100);
    h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4[i] = InitTH1F("h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4", "h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4", 200, -100, 100);
  }
}

void analyzer_histograms::FillHistos(int selbin, Float_t ew){
  f_out[selbin]->cd();
  h_nLeptons[selbin]->Fill(nLeptons, ew);
  
  if(CscClusterPassSel_all[selbin].size()>0) h_nCscRechits[selbin]->Fill(nCscRechits, ew);
  for(int i = 0; i < CscClusterPassSel_all[selbin].size(); i++){
    int c =  CscClusterPassSel_all[selbin][i];
    double dPhi = -999;
    if(muon_list.size()>0) dPhi = DeltaPhi(lepPhi[muon_list[0]], cscRechitClusterPhi[c]);
    h_cscRechitClusterDPhiLeadMuon           [selbin]->Fill(dPhi, ew);  
    h_cscRechitClusterSize                   [selbin]->Fill(cscRechitClusterSize                 [c], ew);
    h_cscRechitClusterSize_v                 [selbin]->Fill(cscRechitClusterSize                 [c], ew);
    h_cscRechitClusterSize_v2                [selbin]->Fill(cscRechitClusterSize                 [c], ew);
    h_cscRechitClusterEta                    [selbin]->Fill(cscRechitClusterEta                  [c], ew);
    h_cscRechitClusterPhi                    [selbin]->Fill(cscRechitClusterPhi                  [c], ew);
    h_cscRechitClusterTime                   [selbin]->Fill(cscRechitClusterTime                 [c], ew);
    h_cscRechitClusterTimeWeighted           [selbin]->Fill(cscRechitClusterTimeWeighted         [c], ew);
    h_cscRechitClusterTimeTotal              [selbin]->Fill(cscRechitClusterTimeTotal            [c], ew);
    h_cscRechitClusterTimeSpread             [selbin]->Fill(cscRechitClusterTimeSpread           [c], ew);
    h_cscRechitClusterTimeSpreadWeighted     [selbin]->Fill(cscRechitClusterTimeSpreadWeighted   [c], ew);
    h_cscRechitClusterTimeSpreadWeightedAll  [selbin]->Fill(cscRechitClusterTimeSpreadWeightedAll[c], ew);
  }
    if(DtClusterPassSel_all[selbin].size()>0) h_nDTRechits[selbin]->Fill(nDTRechits, ew);
  for(int i = 0; i < DtClusterPassSel_all[selbin].size(); i++){
    int d = DtClusterPassSel_all[selbin][i];
    double dPhi = -999;
    if(muon_list.size()>0) dPhi = DeltaPhi(lepPhi[muon_list[0]], dtRechitClusterPhi[d]);
    h_dtRechitClusterDPhiLeadMuon                            [selbin]->Fill(dPhi, ew);  
    h_dtRechitCluster_match_RPCBx_dPhi0p5                    [selbin]->Fill(dtRechitCluster_match_RPCBx_dPhi0p5                  [d], ew);  
    h_dtRechitClusterSize                                    [selbin]->Fill(cscRechitClusterSize                                 [d], ew);
    h_dtRechitClusterEta                                     [selbin]->Fill(cscRechitClusterEta                                  [d], ew);
    h_dtRechitClusterPhi                                     [selbin]->Fill(cscRechitClusterPhi                                  [d], ew);
    h_dtRechitCluster_match_RPCTime_dR0p4                    [selbin]->Fill(dtRechitCluster_match_RPCTime_dR0p4                  [d], ew);
    h_dtRechitCluster_match_RPCTimeSpread_dR0p4              [selbin]->Fill(dtRechitCluster_match_RPCTimeSpread_dR0p4            [d], ew);
    h_dtRechitCluster_match_RPChits_dR0p4                    [selbin]->Fill(dtRechitCluster_match_RPChits_dR0p4                  [d], ew);
    h_dtRechitCluster_match_RPCTime_dPhi0p5                  [selbin]->Fill(dtRechitCluster_match_RPCTime_dPhi0p5                [d], ew);
    h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5            [selbin]->Fill(dtRechitCluster_match_RPCTimeSpread_dPhi0p5          [d], ew);
    h_dtRechitCluster_match_RPCTime_sameStation_dR0p4        [selbin]->Fill(dtRechitCluster_match_RPCTime_sameStation_dR0p4      [d], ew);
    h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4  [selbin]->Fill(dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4[d], ew);
  }
}

void analyzer_histograms::WriteHistos(int selbin){
  f_out[selbin]->cd();
  h_nLeptons[selbin]->Write();
  
  h_cscRechitClusterDPhiLeadMuon           [selbin]->Write();
  h_nCscRechits                            [selbin]->Write();
  h_cscRechitClusterSize                   [selbin]->Write();
  h_cscRechitClusterSize_v                 [selbin]->Write();
  h_cscRechitClusterSize_v2                [selbin]->Write();
  h_cscRechitClusterEta                    [selbin]->Write();
  h_cscRechitClusterPhi                    [selbin]->Write();
  h_cscRechitClusterTime                   [selbin]->Write();
  h_cscRechitClusterTimeWeighted           [selbin]->Write();
  h_cscRechitClusterTimeTotal              [selbin]->Write();
  h_cscRechitClusterTimeSpread             [selbin]->Write();
  h_cscRechitClusterTimeSpreadWeighted     [selbin]->Write();
  h_cscRechitClusterTimeSpreadWeightedAll  [selbin]->Write();

  h_dtRechitClusterDPhiLeadMuon                            [selbin]->Write();
  h_dtRechitCluster_match_RPCBx_dPhi0p5                    [selbin]->Write();
  h_nDTRechits                                             [selbin]->Write();
  h_dtRechitClusterSize                                    [selbin]->Write();
  h_dtRechitClusterEta                                     [selbin]->Write();
  h_dtRechitClusterPhi                                     [selbin]->Write();
  h_dtRechitCluster_match_RPCTime_dR0p4                    [selbin]->Write();
  h_dtRechitCluster_match_RPCTimeSpread_dR0p4              [selbin]->Write();
  h_dtRechitCluster_match_RPChits_dR0p4                    [selbin]->Write();
  h_dtRechitCluster_match_RPCTime_dPhi0p5                  [selbin]->Write();
  h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5            [selbin]->Write();
  h_dtRechitCluster_match_RPCTime_sameStation_dR0p4        [selbin]->Write();
  h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4  [selbin]->Write();
}

void analyzer_histograms::DeleteHistos(int selbin){
  f_out[selbin]->cd();
  h_nLeptons[selbin]->Delete();

  h_cscRechitClusterDPhiLeadMuon           [selbin]->Delete();
  h_nCscRechits                            [selbin]->Delete();
  h_cscRechitClusterSize                   [selbin]->Delete();
  h_cscRechitClusterSize_v                 [selbin]->Delete();
  h_cscRechitClusterSize_v2                [selbin]->Delete();
  h_cscRechitClusterEta                    [selbin]->Delete();
  h_cscRechitClusterPhi                    [selbin]->Delete();
  h_cscRechitClusterTime                   [selbin]->Delete();
  h_cscRechitClusterTimeWeighted           [selbin]->Delete();
  h_cscRechitClusterTimeTotal              [selbin]->Delete();
  h_cscRechitClusterTimeSpread             [selbin]->Delete();
  h_cscRechitClusterTimeSpreadWeighted     [selbin]->Delete();
  h_cscRechitClusterTimeSpreadWeightedAll  [selbin]->Delete();

  h_dtRechitClusterDPhiLeadMuon                            [selbin]->Delete();
  h_dtRechitCluster_match_RPCBx_dPhi0p5                    [selbin]->Delete();
  h_nDTRechits                                             [selbin]->Delete();
  h_dtRechitClusterSize                                    [selbin]->Delete();
  h_dtRechitClusterEta                                     [selbin]->Delete();
  h_dtRechitClusterPhi                                     [selbin]->Delete();
  h_dtRechitCluster_match_RPCTime_dR0p4                    [selbin]->Delete();
  h_dtRechitCluster_match_RPCTimeSpread_dR0p4              [selbin]->Delete();
  h_dtRechitCluster_match_RPChits_dR0p4                    [selbin]->Delete();
  h_dtRechitCluster_match_RPCTime_dPhi0p5                  [selbin]->Delete();
  h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5            [selbin]->Delete();
  h_dtRechitCluster_match_RPCTime_sameStation_dR0p4        [selbin]->Delete();
  h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4  [selbin]->Delete();
}
