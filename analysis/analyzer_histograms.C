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

//TH1F* InitTH1F (TString name, TString title, int nbins, Float_t binLow, Float_t binHigh){
//
//  TH1F* histoTH1F = new TH1F( name , title , nbins , binLow , binHigh );
//  histoTH1F->Sumw2();
//
//  return histoTH1F;
//}

void analyzer_histograms::InitHistos(){
  f_out[0]->cd();
  h_nLeptons = new TH1F("h_nLeptons", "h_nLeptons", 100, 0, 100);
  h_cscRechitClusterSize = new TH1F("h_cscRechitClusterSize", "h_cscRechitClusterSize", 300, 0, 300);
  h_dtRechitClusterSize  = new TH1F("h_dtRechitClusterSize",  "h_dtRechitClusterSize",  300, 0, 300);

}

void analyzer_histograms::FillHistos(){
  f_out[0]->cd();
  h_nLeptons->Fill(nLeptons);
  for(int i = 0; i < CscCluster_list.size(); i++){
    int c = CscCluster_list[i];
    h_cscRechitClusterSize->Fill(cscRechitClusterSize[i]);
  }
  for(int i = 0; i < DtCluster_list.size(); i++){
    int d = DtCluster_list[i];
    h_dtRechitClusterSize->Fill(cscRechitClusterSize[d]);
  }
}

void analyzer_histograms::WriteHistos(){
  f_out[0]->cd();
  h_nLeptons->Write();
  h_cscRechitClusterSize->Write();
  h_dtRechitClusterSize->Write();

}
