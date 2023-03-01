#define analyzer_cxx
#include "analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <iterator>
#include <iostream>
#include <iomanip>

using namespace std;

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
   Long64_t nentries = fChain->GetEntriesFast();
   //Long64_t nentries = 20;
   Long64_t nbytes = 0, nb = 0;
   std::cout<<"nentries: "<<nentries<<std::endl;

   //set up cutFlow entries
   cutFlow.insert(std::pair<TString, float> ("No cuts", nentries));     cutFlowKeys.push_back("No cuts");
   cutFlow.insert(std::pair<TString, float> ("Muon Exists", 0));        cutFlowKeys.push_back("Muon Exists");
   cutFlow.insert(std::pair<TString, float> ("MuonPt > 7 GeV", 0));     cutFlowKeys.push_back("MuonPt > 7 GeV");
   cutFlow.insert(std::pair<TString, float> ("abs(MuonEta) < 1.5", 0)); cutFlowKeys.push_back("abs(MuonEta) < 1.5");
   cutFlow.insert(std::pair<TString, float> ("MuonHLtRequirement", 0)); cutFlowKeys.push_back("MuonHLtRequirement");

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (jentry %1000000 == 0) std::cout<<"Event: "<<jentry<<" -of- "<<nentries<<std::endl;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
   
      //object lists
      muon_list =  muonPassSel(muPt, muEta);

      //Fill the histograms by event
      FillHistos();

   }//end jentries

   //print cutFlow table
   int width = 20;
   for (int c = 0; c<cutFlowKeys.size(); c++) {
    std::cout << '\t'<<setw(width)<<left<< cutFlowKeys[c] << '\t'<<setw(width)<<left<< cutFlow[cutFlowKeys[c]]
         << '\n';
   }

   WriteHistos();
   
}
