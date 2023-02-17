#define analyzer_cxx
#include "analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>

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

   //std::vector<TLorentzVector> v_CscRechitClusters;
   
   TH1F* h_nLeptons = new TH1F("h_nLeptons","h_nLeptons", 100,0,100);
   TH1F* h_lepPt   = new TH1F("h_lepPt","h_lepPt", 100,0,500);
   Long64_t nentries = 1000001;//fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (jentry %1000000 == 0) std::cout<<"Event: "<<jentry<<" -of- "<<nentries<<std::endl;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      for (int i=0; i<nLeptons; i++){
	h_lepPt->Fill(lepPt[i]);
      }
      h_nLeptons->Fill(nLeptons);


      //v_CscRechitClusters.clear();
      //TLorentzVector* lv_llp = new TLorentzVector(gLLP_pt, gLLP_eta, gLLP_phi, gLLP_e);
      //for (unsigned i=0; i<nCscRechitClusters; i++){
      //   TLorentzVector lv;
      //   lv.SetXYZT(cscRechitClusterX[i], cscRechitClusterY[i], cscRechitClusterZ[i], cscRechitClusterTime[i]);
      //   v_CscRechitClusters.push_back(lv);
      //}

   }
   TCanvas *c = new TCanvas();
   h_nLeptons->Draw();
   c->SaveAs("h_nLeptons.pdf");
   h_lepPt->Draw();
   c->SaveAs("h_lepPt.pdf");
   
}
