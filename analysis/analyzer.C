#define analyzer_cxx
#include "analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


void analyzer::Loop()
{
   if (fChain == 0) return;

   
   //TH1F h_jetPt = new TH1F("h_jetPt","h_jetPt", 100,0.,500.);
   Long64_t nentries = 10;//fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      std::cout<<"Hello World"<<std::endl;
     // for (unsigned i=0; i<nJets; i++){
     //    h_jetPt->Fill(jetPt[i]);
     // }

   }
}
