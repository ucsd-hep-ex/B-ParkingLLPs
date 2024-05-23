#define fakeRate_cxx
#include "fakeRate.h"
#include <TH2.h>
#include <TFile.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include "TMath.h"

//-------------------------DeltaPhi
double DeltaPhi(double phi1, double phi2)
//Gives the (minimum) separation in phi between the specified phi values
//Must return a positive value
{
  double pi = TMath::Pi();
  double dphi = fabs(phi1-phi2);
  if(dphi>pi)
    dphi = 2.0*pi - dphi;
  return dphi;
}

double dR(double eta1, double phi1, double eta2, double phi2)
{
  double deltaeta = abs(eta1 - eta2);
  double deltaphi = DeltaPhi(phi1, phi2);
  double deltar = sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
  return deltar;
}

bool fakeRate::isGoodMuon(int index){
  if (fabs(lepPdgId[index]) !=13) return false;
  if(!(lepPt[index] > 7. &&
     fabs(lepEta[index]) < 1.5 &&
     lepMuonQuality[index] >= pow(2,25))
    ) return false;
  return true;
}

int fakeRate::MuonPresent(){
  int MuIndex = -1;
  for(int i = 0; i<nLeptons; i++){
    if(fabs(lepPdgId[i]) ==13 && isGoodMuon(i)){
      MuIndex = i;
      break;
    }
  }
  return MuIndex;
}

bool fakeRate::doesPassCSCID(int index){
  if ((cscRechitClusterNStation10[index] > 1 && fabs(cscRechitClusterEta[index])<1.8) || 
      (cscRechitClusterNStation10[index]== 1 && fabs(cscRechitClusterAvgStation10[index])==4 && fabs(cscRechitClusterEta[index])<1.8) || 
      (cscRechitClusterNStation10[index]== 1 && fabs(cscRechitClusterAvgStation10[index])==3 && fabs(cscRechitClusterEta[index])<1.6) || 
      (cscRechitClusterNStation10[index]== 1 && fabs(cscRechitClusterAvgStation10[index])==2 && fabs(cscRechitClusterEta[index])<1.7) || 
      (cscRechitClusterNStation10[index]== 1 && fabs(cscRechitClusterAvgStation10[index])==1 && fabs(cscRechitClusterEta[index])<1.1) )  
      return true;
  else return false; 
}

float fakeRate::DrOverlapMuon(int index){
  int muIndex = MuonPresent();
  if (muIndex > -1){
    if(isGoodMuon(muIndex)){
      return dR(lepEta[muIndex],lepPhi[muIndex],cscRechitClusterEta[index],cscRechitClusterPhi[index]);
    }
    else return 999;
  }
  else return 999;
}

bool fakeRate::isGoodCSC(int index){
  //--passOverlapMuon
  if(DrOverlapMuon(index) <= 0.8) return false;
  //MinClusterSize
  if(cscRechitClusterSize[index] < 50) return false;
  //--ME11/12Veto
  if (!(cscRechitClusterNRechitChamberPlus11[index]  <=0 && 
        cscRechitClusterNRechitChamberMinus11[index] <=0 &&
        cscRechitClusterNRechitChamberPlus12[index]  <=0 && 
        cscRechitClusterNRechitChamberMinus12[index] <=0)) 
  return false;
  //--MB1Veto
  if(cscRechitCluster_match_MB1Seg_0p4[index] > 0) return false;
  //--RB1Veto
  if(cscRechitCluster_match_RB1_0p4[index] > 0) return false;
  //--RE12Veto
  if(cscRechitCluster_match_RE12_0p4[index] > 0) return false;
  //--MuonVeto
  if(cscRechitClusterMuonVetoPt[index] > 20.) return false; 
  //--ClusterTime
  if(cscRechitClusterTimeWeighted[index] < -5. && 
     cscRechitClusterTimeWeighted[index] > 12.5) 
  return false;
  //--ClusterTimeSpread
  if( cscRechitClusterTimeSpreadWeightedAll[index] > 20.) return false;
  //--ClusterEta
  if( fabs(cscRechitClusterEta[index]) >= 1.9) return false;
  //--ClusterID
  if (!doesPassCSCID(index)) return false;    

  //--if pass all vetos
  return true;
}


void fakeRate::Loop()
{
   if (fChain == 0) return;
   std::cout << "Number of files in chain (from Loop): " << fChain->GetListOfFiles()->GetEntries() << std::endl; 
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nentries2 = fChain->GetEntries();

   TFile* outFile = TFile::Open("histos.root", "RECREATE");

  //set pT binnning
  float x_bins[] = {0.,50.,100.,500.,1000.};
  int nBins = sizeof(x_bins)/sizeof(float) -1;

   

   TH1F* h_nPass      = new TH1F("h_nPass","h_nPass", 3,0,3);
   TH1F* h_nPassTotal = new TH1F("h_nPassTotal","h_nPassTotal", 3,0,3);
   TH1F* h_nJets   = new TH1F("h_nJets", "h_nJets", 20, 0, 20);
   TH1F* h_JetCISV = new TH1F("h_JetCISV", "h_JetCISV", 30, 0, 1.5);
   TH1F* h_dr_j_csc = new TH1F("h_dr_j_csc", "h_dr_j_csc", 50, 0, 15);
   TH1F* h_j_PassBtag_pT         = new TH1F("h_j_PassBtag_pT",        "h_j_PassBtag_pT",          nBins, x_bins);
   TH1F* h_j_csc_Match_pT        = new TH1F("h_j_csc_Match_pT",       "h_j_csc_Match_pT",         nBins, x_bins);
   TH1F* h_j_csc_Match_pT50_100  = new TH1F("h_j_csc_Match_pT50_100", "h_j_csc_Match_pT50_100",   nBins, x_bins);
   TH1F* h_j_csc_Match_pT100_200 = new TH1F("h_j_csc_Match_pT100_200", "h_j_csc_Match_pT100_200", nBins, x_bins);
   TH1F* h_j_csc_Match_pT200     = new TH1F("h_j_csc_Match_pT200",     "h_j_csc_Match_pT200",     nBins, x_bins);
   TH1F* h_j_csc_NoMatch_pT      = new TH1F("h_j_csc_NoMatch_pT",      "h_j_csc_NoMatch_pT",      nBins, x_bins);

   TH1F* h_j_PassBtag_eta = new TH1F("h_j_PassBtag_eta", "h_j_PassBtag_eta", 30, -5, 5);
   TH1F* h_j_csc_Match_eta = new TH1F("h_j_csc_Match_eta", "h_j_csc_Match_eta", 30, -5, 5);
   TH1F* h_j_csc_Match_eta50_100 = new TH1F("h_j_csc_Match_eta50_100", "h_j_csc_Match_eta50_100", 30, -5, 5);
   TH1F* h_j_csc_Match_eta100_200 = new TH1F("h_j_csc_Match_eta100_200", "h_j_csc_Match_eta100_200", 30, -5, 5);
   TH1F* h_j_csc_Match_eta200 = new TH1F("h_j_csc_Match_eta200", "h_j_csc_Match_eta200", 30, -5, 5);
   TH1F* h_j_csc_NoMatch_eta = new TH1F("h_j_csc_NoMatch_eta", "h_j_csc_NoMatch_eta", 30, -5, 5);
   
   TH1F* h_cscRechitClusterSize = new TH1F("h_cscRechitClusterSize", "h_cscRechitClusterSize", 100, 0, 600);

   float counter = 0;
   int n50_100 = 0;
   int n100_200 = 0;
   int n200 = 0;
   int nTotal = 0;
   bool found50_100;
   bool found100_200;
   bool found200;
   //std::cout<<"In Loop"<<std::endl;
   Long64_t nbytes = 0, nb = 0;
   std::cout<< nentries2<<std::endl;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      found50_100 = false;
      found100_200 = false;
      found200 = false;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if(jentry%100000 ==0) std::cout<<"Processing "<<jentry<<"  of "<<nentries2<<std::endl; 
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      //if(jentry<10) std::cout<<"----------"<<jentry<<"-----------"<<std::endl;
      if(met<30.) continue;
      // Jet loop
      h_nJets->Fill(nJets);
      double j_eta = -999;
      double j_pT = -999;
      double j_phi = -999;
      double dr_j_csc = -999;
      for(int j = 0; j < nJets; j++){
        //only care for jets passing b-tagging req.
        //if(jetCISV[j] < 0.8484) continue; //original
        //from https://twiki.cern.ch/twiki/bin/view/CMS/BtagRecommendation80X
        if(jetCISV[j] < 0.460) continue;  //loose
        //if(jetCISV[j] < 0.800) continue;  //medium
        //if(jetCISV[j] < 0.935) continue;  //tight
        if(jetPt[j] < 20.) continue;
        //if (jentry < 10) std::cout<<jetPt[j]<<std::endl;
        j_eta = jetEta[j];
        j_phi = jetPhi[j];
        j_pT = jetPt[j];
        h_j_PassBtag_pT ->Fill(j_pT);
        h_j_PassBtag_eta ->Fill(j_eta);
        h_JetCISV->Fill(jetCISV[j]);
        if(j_pT>=100.&& j_pT<=500.) counter++;

        //loop over CSC clusters
        double c_eta = -999;
        double c_phi = -999;
        bool matchFound = false;
        bool matchFound50_100 = false;
        bool matchFound100_200 = false;
        bool matchFound200 = false;
        for (int c = 0; c < nCscRechitClusters; c++){
         if(!isGoodCSC(c)) continue;
         h_cscRechitClusterSize->Fill(cscRechitClusterSize[c]);
         c_eta = cscRechitClusterEta[c];
         c_phi = cscRechitClusterPhi[c];
         dr_j_csc = dR(c_eta,c_phi,j_eta,j_phi); 
         h_dr_j_csc->Fill(dr_j_csc);
         if (dr_j_csc < 0.4){
          matchFound = true;
          if (cscRechitClusterSize[c] >=50  && cscRechitClusterSize[c]<100) matchFound50_100 = true;
          if (cscRechitClusterSize[c] >=100 && cscRechitClusterSize[c]<200) matchFound100_200 = true;
          if (cscRechitClusterSize[c] >=200                               ) matchFound200 = true;
         }
        }
        if (matchFound){
          h_j_csc_Match_pT->Fill(j_pT);
          h_j_csc_Match_eta->Fill(j_eta);
        }
        else{
          h_j_csc_NoMatch_pT->Fill(j_pT);
          h_j_csc_NoMatch_eta->Fill(j_eta);
        }
        if (matchFound50_100){
          h_j_csc_Match_pT50_100->Fill(j_pT);
          h_j_csc_Match_eta50_100->Fill(j_eta);
          found50_100=true;
        }
        if (matchFound100_200){
          h_j_csc_Match_pT100_200->Fill(j_pT);
          h_j_csc_Match_eta100_200->Fill(j_eta);
          found100_200=true;
        }
        if (matchFound200){
          h_j_csc_Match_pT200->Fill(j_pT);
          h_j_csc_Match_eta200->Fill(j_eta);
          found200=true;
        }
      }
      if(found50_100) n50_100++;
      if(found100_200) n100_200++;
      if(found200) n200++;
      nTotal++;
   }//end loop events
   h_nPass->SetBinContent(1,n50_100);
   h_nPass->SetBinContent(2,n100_200);
   h_nPass->SetBinContent(3,n200);
   h_nPassTotal->SetBinContent(1,nTotal);
   h_nPassTotal->SetBinContent(2,nTotal);
   h_nPassTotal->SetBinContent(3,nTotal);
   std::cout<<counter<<std::endl;
   TCanvas *c = new TCanvas("c1", "c1", 800, 600);
   h_JetCISV->Draw("hist");
   c->SaveAs("h_JetCISV.pdf");
   c->SaveAs("h_JetCISV.png");

   c->Clear();
   h_cscRechitClusterSize->Draw("hist");
   c->SaveAs("h_cscRechitClusterSize.pdf");
   c->SaveAs("h_cscRechitClusterSize.png");
   
   c->Clear();
   h_nJets->Draw("hist");
   c->SaveAs("h_nJets.pdf");
   c->SaveAs("h_nJets.png");

   c->Clear();
   h_dr_j_csc->Draw("hist");
   c->SaveAs("h_dr_j_csc.pdf");
   c->SaveAs("h_dr_j_csc.png");

   c->Clear();
   h_nPass->Draw("hist");
   c->SaveAs("h_nPass.png");
   c->SaveAs("h_nPass.pdf");

   c->Clear();
   h_nPassTotal->Draw("hist");
   c->SaveAs("h_nPassTotal.png");
   c->SaveAs("h_nPassTotal.pdf");

   c->Clear();
   h_j_csc_NoMatch_pT->Draw("hist");
   c->SaveAs("h_j_csc_NoMatch_pT.pdf");
   c->SaveAs("h_j_csc_NoMatch_pT.png");

   c->Clear();
   h_j_csc_Match_pT->Draw("hist");
   c->SaveAs("h_j_csc_Match_pT.pdf");
   c->SaveAs("h_j_csc_Match_pT.png");

   c->Clear();
   h_j_PassBtag_pT->Draw("hist");
   c->SaveAs("h_j_PassBtag_pT.pdf");
   c->SaveAs("h_j_PassBtag_pT.png");

   c->Clear();
   h_j_csc_NoMatch_eta->Draw("hist");
   c->SaveAs("h_j_csc_NoMatch_eta.pdf");
   c->SaveAs("h_j_csc_NoMatch_eta.png");

   c->Clear();
   h_j_csc_Match_eta->Draw("hist");
   c->SaveAs("h_j_csc_Match_eta.pdf");
   c->SaveAs("h_j_csc_Match_eta.png");

   c->Clear();
   h_j_PassBtag_eta->Draw("hist");
   c->SaveAs("h_j_PassBtag_eta.pdf");
   c->SaveAs("h_j_PassBtag_eta.png");

   TH1F* h_nPassEff = (TH1F*) h_nPass->Clone();
   h_nPassEff->Divide(h_nPassTotal);
   h_nPassEff->SetTitle("h_nPassEff");
   h_nPassEff->Sumw2();

   TH1F* h_j_csc_MatchEff_pT = (TH1F*) h_j_csc_Match_pT->Clone();
   h_j_csc_MatchEff_pT->Divide(h_j_PassBtag_pT);
   h_j_csc_MatchEff_pT->SetTitle("h_j_csc_MatchEff_pT");
   h_j_csc_MatchEff_pT->Sumw2();

   TH1F* h_j_csc_MatchEff_pT50_100 = (TH1F*) h_j_csc_Match_pT50_100->Clone();
   h_j_csc_MatchEff_pT50_100->Divide(h_j_PassBtag_pT);
   h_j_csc_MatchEff_pT50_100->SetTitle("h_j_csc_MatchEff_pT50_100");
   h_j_csc_MatchEff_pT50_100->Sumw2();

   TH1F* h_j_csc_MatchEff_pT100_200 = (TH1F*) h_j_csc_Match_pT100_200->Clone();
   h_j_csc_MatchEff_pT100_200->Divide(h_j_PassBtag_pT);
   h_j_csc_MatchEff_pT100_200->SetTitle("h_j_csc_MatchEff_pT100_200");
   h_j_csc_MatchEff_pT100_200->Sumw2();

   TH1F* h_j_csc_MatchEff_pT200 = (TH1F*) h_j_csc_Match_pT200->Clone();
   h_j_csc_MatchEff_pT200->Divide(h_j_PassBtag_pT);
   h_j_csc_MatchEff_pT200->SetTitle("h_j_csc_MatchEff_pT200");
   h_j_csc_MatchEff_pT200->Sumw2();

   TH1F* h_j_csc_MatchEff_eta = (TH1F*) h_j_csc_Match_eta->Clone();
   h_j_csc_MatchEff_eta->Divide(h_j_PassBtag_eta);
   h_j_csc_MatchEff_eta->SetTitle("h_j_csc_MatchEff_eta");
   h_j_csc_MatchEff_eta->Sumw2();

   TH1F* h_j_csc_MatchEff_eta50_100 = (TH1F*) h_j_csc_Match_eta50_100->Clone();
   h_j_csc_MatchEff_eta50_100->Divide(h_j_PassBtag_eta);
   h_j_csc_MatchEff_eta50_100->SetTitle("h_j_csc_MatchEff_eta50_100");
   h_j_csc_MatchEff_eta50_100->Sumw2();

   TH1F* h_j_csc_MatchEff_eta100_200 = (TH1F*) h_j_csc_Match_eta100_200->Clone();
   h_j_csc_MatchEff_eta100_200->Divide(h_j_PassBtag_eta);
   h_j_csc_MatchEff_eta100_200->SetTitle("h_j_csc_MatchEff_eta100_200");
   h_j_csc_MatchEff_eta100_200->Sumw2();

   TH1F* h_j_csc_MatchEff_eta200 = (TH1F*) h_j_csc_Match_eta200->Clone();
   h_j_csc_MatchEff_eta200->Divide(h_j_PassBtag_eta);
   h_j_csc_MatchEff_eta200->SetTitle("h_j_csc_MatchEff_eta200");
   h_j_csc_MatchEff_eta200->Sumw2();

   c->Clear();
   h_nPassEff->Draw("hist");
   c->SaveAs("h_nPassEff.pdf");
   c->SaveAs("h_nPassEff.png");
  
   c->Clear();
   h_j_csc_MatchEff_pT->Draw("hist");
   c->SaveAs("h_j_csc_MatchEff_pT.pdf");
   c->SaveAs("h_j_csc_MatchEff_pT.png");

   c->Clear();
   h_j_csc_MatchEff_pT50_100->Draw("hist");
   c->SaveAs("h_j_csc_MatchEff_pT50_100.pdf");
   c->SaveAs("h_j_csc_MatchEff_pT50_100.png");

   c->Clear();
   h_j_csc_MatchEff_pT100_200->Draw("hist");
   c->SaveAs("h_j_csc_MatchEff_pT100_200.pdf");
   c->SaveAs("h_j_csc_MatchEff_pT100_200.png");

   c->Clear();
   h_j_csc_MatchEff_pT200->Draw("hist");
   c->SaveAs("h_j_csc_MatchEff_pT200.pdf");
   c->SaveAs("h_j_csc_MatchEff_pT200.png");

   c->Clear();
   h_j_csc_MatchEff_eta->Draw("hist");
   c->SaveAs("h_j_csc_MatchEff_eta.pdf");
   c->SaveAs("h_j_csc_MatchEff_eta.png");

   c->Clear();
   h_j_csc_MatchEff_eta50_100->Draw("hist");
   c->SaveAs("h_j_csc_MatchEff_eta50_100.pdf");
   c->SaveAs("h_j_csc_MatchEff_eta50_100.png");

   c->Clear();
   h_j_csc_MatchEff_eta100_200->Draw("hist");
   c->SaveAs("h_j_csc_MatchEff_eta100_200.pdf");
   c->SaveAs("h_j_csc_MatchEff_eta100_200.png");

   c->Clear();
   h_j_csc_MatchEff_eta200->Draw("hist");
   c->SaveAs("h_j_csc_MatchEff_eta200.pdf");
   c->SaveAs("h_j_csc_MatchEff_eta200.png");

   h_JetCISV->Write();
   h_nJets->Write();
   h_cscRechitClusterSize->Write();
   h_dr_j_csc->Write();

   h_nPass->Write();
   h_nPassTotal->Write();
   h_nPassEff->Write();

   h_j_csc_NoMatch_pT->Write();
   h_j_csc_Match_pT->Write();
   h_j_PassBtag_pT->Write();
   h_j_csc_NoMatch_eta->Write();
   h_j_csc_Match_eta->Write();
   h_j_PassBtag_eta->Write();

   h_j_csc_MatchEff_pT->Write();
   h_j_csc_MatchEff_pT50_100->Write();
   h_j_csc_MatchEff_pT100_200->Write();
   h_j_csc_MatchEff_pT200->Write();
   h_j_csc_Match_pT->Write();
   h_j_csc_Match_pT50_100->Write();
   h_j_csc_Match_pT100_200->Write();
   h_j_csc_Match_pT200->Write();

   h_j_csc_MatchEff_eta->Write();
   h_j_csc_MatchEff_eta50_100->Write();
   h_j_csc_MatchEff_eta100_200->Write();
   h_j_csc_MatchEff_eta200->Write();
   h_j_csc_Match_eta->Write();
   h_j_csc_Match_eta50_100->Write();
   h_j_csc_Match_eta100_200->Write();
   h_j_csc_Match_eta200->Write();
   outFile->Close();
}
