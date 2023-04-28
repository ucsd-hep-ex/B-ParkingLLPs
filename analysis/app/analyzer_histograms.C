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

void analyzer_histograms::InitHistos(){
  for (int i = 0; i< SELBINNAMESIZE; i++){
    f_out[i]->cd();
    h_nLeptons                             [i]             = InitTH1F("h_nLeptons", "h_nLeptons", 100, 0, 100);
    h_nCscRechits                          [i] = InitTH1F("nCscRechits", "nCscRechits", 300, 0, 300);
    h_cscRechitClusterSize                 [i] = InitTH1F("h_cscRechitClusterSize", "h_cscRechitClusterSize", 300, 0, 300);
    h_cscRechitClusterDPhiLeadMuon         [i] = InitTH1F("h_cscRechitClusterDPhiLeadMuon", "h_cscRechitClusterDPhiLeadMuon", 30, 0, 4);
    h_cscRechitClusterTime                 [i] = InitTH1F("h_cscRechitClusterTime"                 , "h_cscRechitClusterTime",         200, -100, 100);
    h_cscRechitClusterTimeWeighted         [i] = InitTH1F("h_cscRechitClusterTimeWeighted"         , "h_cscRechitClusterTimeWeighted", 200, -100, 100);
    h_cscRechitClusterTimeTotal            [i] = InitTH1F("h_cscRechitClusterTimeTotal"            , "h_cscRechitClusterTimeTotal",    200, -100, 100);
    h_cscRechitClusterTimeSpread           [i] = InitTH1F("h_cscRechitClusterTimeSpread",            "h_cscRechitClusterTimeSpread",            200, 0, 200);
    h_cscRechitClusterTimeSpreadWeighted   [i] = InitTH1F("h_cscRechitClusterTimeSpreadWeighted",     "h_cscRechitClusterTimeSpreadWeighted",   200, 0, 200);
    h_cscRechitClusterTimeSpreadWeightedAll[i] = InitTH1F("h_cscRechitClusterTimeSpreadWeightedAll", "h_cscRechitClusterTimeSpreadWeightedAll", 200, 0, 200);


    h_nDTRechits                                           [i] = InitTH1F("h_nDTRechits",  "h_nDTRechits",  300, 0, 300);
    h_dtRechitClusterSize                                  [i] = InitTH1F("h_dtRechitClusterSize",  "h_dtRechitClusterSize",  300, 0, 300);
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

void analyzer_histograms::FillHistos(int selbin){
  f_out[selbin]->cd();
  h_nLeptons[selbin]->Fill(nLeptons);
  
  if(CscClusterPassSel_all[selbin].size()>0) h_nCscRechits[selbin]->Fill(nCscRechits);
  for(int i = 0; i < CscClusterPassSel_all[selbin].size(); i++){
    int c =  CscClusterPassSel_all[selbin][i];
    double dPhi = -999;
    if(muon_list.size()>0) dPhi = DeltaPhi(lepPhi[muon_list[0]], cscRechitClusterPhi[c]);
    h_cscRechitClusterDPhiLeadMuon           [selbin]->Fill(dPhi);  
    h_cscRechitClusterSize                   [selbin]->Fill(cscRechitClusterSize                 [c]);
    h_cscRechitClusterTime                   [selbin]->Fill(cscRechitClusterTime                 [c]);
    h_cscRechitClusterTimeWeighted           [selbin]->Fill(cscRechitClusterTimeWeighted         [c]);
    h_cscRechitClusterTimeTotal              [selbin]->Fill(cscRechitClusterTimeTotal            [c]);
    h_cscRechitClusterTimeSpread             [selbin]->Fill(cscRechitClusterTimeSpread           [c]);
    h_cscRechitClusterTimeSpreadWeighted     [selbin]->Fill(cscRechitClusterTimeSpreadWeighted   [c]);
    h_cscRechitClusterTimeSpreadWeightedAll  [selbin]->Fill(cscRechitClusterTimeSpreadWeightedAll[c]);
  }
    if(DtClusterPassSel_all[selbin].size()>0) h_nDTRechits[selbin]->Fill(nDTRechits);
  for(int i = 0; i < DtClusterPassSel_all[selbin].size(); i++){
    int d = DtClusterPassSel_all[selbin][i];
    double dPhi = -999;
    if(muon_list.size()>0) dPhi = DeltaPhi(lepPhi[muon_list[0]], dtRechitClusterPhi[d]);
    h_dtRechitClusterDPhiLeadMuon                            [selbin]->Fill(dPhi);  
    h_dtRechitCluster_match_RPCBx_dPhi0p5                    [selbin]->Fill(dtRechitCluster_match_RPCBx_dPhi0p5                  [d]);  
    h_dtRechitClusterSize                                    [selbin]->Fill(cscRechitClusterSize                                 [d]);
    h_dtRechitCluster_match_RPCTime_dR0p4                    [selbin]->Fill(dtRechitCluster_match_RPCTime_dR0p4                  [d]);
    h_dtRechitCluster_match_RPCTimeSpread_dR0p4              [selbin]->Fill(dtRechitCluster_match_RPCTimeSpread_dR0p4            [d]);
    h_dtRechitCluster_match_RPChits_dR0p4                    [selbin]->Fill(dtRechitCluster_match_RPChits_dR0p4                  [d]);
    h_dtRechitCluster_match_RPCTime_dPhi0p5                  [selbin]->Fill(dtRechitCluster_match_RPCTime_dPhi0p5                [d]);
    h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5            [selbin]->Fill(dtRechitCluster_match_RPCTimeSpread_dPhi0p5          [d]);
    h_dtRechitCluster_match_RPCTime_sameStation_dR0p4        [selbin]->Fill(dtRechitCluster_match_RPCTime_sameStation_dR0p4      [d]);
    h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4  [selbin]->Fill(dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4[d]);
  }
}

void analyzer_histograms::WriteHistos(int selbin){
  f_out[selbin]->cd();
  h_nLeptons[selbin]->Write();
  
  h_cscRechitClusterDPhiLeadMuon           [selbin]->Write();
  h_nCscRechits                            [selbin]->Write();
  h_cscRechitClusterSize                   [selbin]->Write();
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
  h_dtRechitCluster_match_RPCTime_dR0p4                    [selbin]->Delete();
  h_dtRechitCluster_match_RPCTimeSpread_dR0p4              [selbin]->Delete();
  h_dtRechitCluster_match_RPChits_dR0p4                    [selbin]->Delete();
  h_dtRechitCluster_match_RPCTime_dPhi0p5                  [selbin]->Delete();
  h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5            [selbin]->Delete();
  h_dtRechitCluster_match_RPCTime_sameStation_dR0p4        [selbin]->Delete();
  h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4  [selbin]->Delete();
}
