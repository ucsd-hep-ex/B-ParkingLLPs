#define analyzer_cxx
#include "analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <iterator>
#include <map>
#include <iostream>

analyzer::analyzer() 
{
}

analyzer::~analyzer()
{
}

void analyzer::Loop()
{
   std::cout<<"In Loop"<<std::endl;
   fChain->GetListOfBranches();
   if (fChain == 0) return;
   std::map<TString,float> cutFlow;
   //Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nentries = 20;
   Long64_t nbytes = 0, nb = 0;
   std::cout<<"nentries: "<<nentries<<std::endl;
   cutFlow.insert(std::pair<TString, float> ("No cuts", nentries));
   cutFlow.insert(std::pair<TString, float> ("abs(LepID)==13", 0));
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (jentry %1000000 == 0) std::cout<<"Event: "<<jentry<<" -of- "<<nentries<<std::endl;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      //Fill cutFlow
      if(abs(lepPdgId[0])==13) cutFlow["abs(LepID)==13"] += 1;

      for (int j=0; j< nLeptons; j++){
      std::cout<<"PdgId: "<<lepPdgId[j] <<"      ,"<<"Pt: "<<lepPt[j]<<std::endl;
      }
      //Fill the histograms by event
      FillHistos();

      std::cout<<"################# EVENT  "<< jentry<<"   #####################"<<std::endl;
   }//end jentries
   for (std::map<TString,float>::iterator itr = cutFlow.begin(); itr != cutFlow.end(); ++itr) {
    std::cout << '\t' << itr->first << '\t' << itr->second
         << '\n';
   }

   WriteHistos();
   
}
