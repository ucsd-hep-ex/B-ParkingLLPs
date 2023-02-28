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
  //h_nLeptons->Fill(nLeptons);
  //h_nLeptons->Write();

}

void analyzer_histograms::FillHistos(){
  f_out[0]->cd();
//  std::cout<<"passed cd"<<std::endl;
  h_nLeptons->Fill(nLeptons);

}

void analyzer_histograms::WriteHistos(){
  f_out[0]->cd();
  h_nLeptons->Write();

}
