#define Acceptance_cxx
#include "Acceptance.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TMath.h"

void Acceptance::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   TH1F* h_dr_cscLLP = new TH1F("h_dr_cscLLP",  "h_dr_cscLLP", 100, 0, 1);
   TH1F* h_gLLP_ctau = new TH1F("h_gLLP_ctau",  "h_gLLP_ctau", 100, 0, 1000);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

     h_gLLP_ctau->Fill(gLLP_ctau);
     for (int i = 0; i<nCscRechitClusters; i++){
       double csc_dr = dR(gLLP_eta, gLLP_phi, cscRechitClusterPhi[i], cscRechitClusterEta[i]);
       h_dr_cscLLP->Fill(csc_dr);
     }
 

   }

  TCanvas* c1 = new TCanvas( "c", "c", 2119, 33, 800, 700 );
   h_dr_cscLLP->Draw();
   c1->SaveAs("h_dr_cscLLP.pdf");
   h_gLLP_ctau->Draw();
   c1->SaveAs("h_gLLP_ctau.pdf");

   
}


//----------------------------dR
double Acceptance::dR(double eta1, double phi1, double eta2, double phi2)
{
  double deltaeta = abs(eta1 - eta2);
  double deltaphi = DeltaPhi(phi1, phi2);
  double deltar = sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
  return deltar;
}

//-------------------------DeltaPhi
double Acceptance::DeltaPhi(double phi1, double phi2)
//Gives the (minimum) separation in phi between the specified phi values
//Must return a positive value
{
  double pi = 3.14;//TMath::Pi();
  double dphi = fabs(phi1-phi2);
  if(dphi>pi)
    dphi = 2.0*pi - dphi;
  return dphi;
}
