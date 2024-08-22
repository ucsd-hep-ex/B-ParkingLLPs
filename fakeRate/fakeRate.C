#define fakeRate_cxx
#include "fakeRate.h"
#include <TH2.h>
#include <TFile.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include "TMath.h"

const bool DOLOCAL = false;

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

//finds first muon object if present in lepton list
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

bool fakeRate::doesPassDPhi(int index, double lower, double upper){
  int muIndex = MuonPresent();
  if (muIndex > -1){
    double dphiJ = DeltaPhi(lepPhi[muIndex], jetPhi[index]);
    if(dphiJ>lower && dphiJ<upper) 
      return true;
    else 
      return false;
  }
  else return false;
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

float fakeRate::DrOverlapMuon(int index, TString type){
  int muIndex = MuonPresent();
  if (muIndex > -1){
    if(isGoodMuon(muIndex)){
      if(type.Contains("csc"))return dR(lepEta[muIndex],lepPhi[muIndex],cscRechitClusterEta[index],cscRechitClusterPhi[index]);
      if(type.Contains("dt"))return dR(lepEta[muIndex],lepPhi[muIndex],dtRechitClusterEta[index],dtRechitClusterPhi[index]);
      else return 999;
    }
    else return 999;
  }
  else return 999;
}

bool fakeRate::isGoodCSC(int index){
  //--passOverlapMuon
  if(DrOverlapMuon(index, "csc") <= 0.8) return false;
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
  //if (doesPassCSCID(index)) return false;    //for VR

  //--if pass all vetos
  return true;
}

TH1F* DivideHists(TH1F* hist1, TH1F* hist2, TString hname) {
    TH1F* result = (TH1F*) hist1->Clone();
    result->Divide(hist2);
    result->SetTitle(hname);
    result->SetName(hname);
    result->Sumw2();
    return result;
}

void fakeRate::Loop()
{
   if (fChain == 0) return;
   std::cout << "Number of files in chain (from Loop): " << fChain->GetListOfFiles()->GetEntries() << std::endl; 
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nentries2 = fChain->GetEntries();

   TFile* outFile = TFile::Open("histos.root", "RECREATE");

  //set pT binnning
  float x_bins[] = {0.,20.,30.,40.,50.,60.,75.,200.,500.,1000.};
  int nBins = sizeof(x_bins)/sizeof(float) -1;
  float y_bins[] = {50.,100.,200.,300.,
                    310.,320.,330.,340.,350.,
                    360.,370.,380.,390.,400.,
                    410.,420.,430.,440.,450.,
                    460.,470.,480.,490.,500.,
                   1000.};
  int nYBins = sizeof(y_bins)/sizeof(float) -1;
  bool matchesFound[nYBins];
  float nFound[nYBins];

  TH2F* h_Num = new TH2F("h_Num",  "h_Num",  nBins, x_bins, nYBins, y_bins);
  TH2F* h_Den = new TH2F("h_Den",  "h_Den",  nBins, x_bins, nYBins, y_bins);
  
  TH2F* h_Eff = new TH2F("h_Eff",  "h_Eff",  nBins, x_bins, nYBins, y_bins);

   TH1F* h_nPass      = new TH1F("h_nPass","h_nPass", 4,0,3);
   TH1F* h_nPassTotal = new TH1F("h_nPassTotal","h_nPassTotal", 4,0,3);
   TH1F* h_nJets   = new TH1F("h_nJets", "h_nJets", 20, 0, 20);
   TH1F* h_JetCISV = new TH1F("h_JetCISV", "h_JetCISV", 30, 0, 1.5);
   TH1F* h_dr_j_csc = new TH1F("h_dr_j_csc", "h_dr_j_csc", 50, 0, 15);
   TH1F* h_j_PassBtag_pT         = new TH1F("h_j_PassBtag_pT",          "h_j_PassBtag_pT",          nBins, x_bins);
   TH1F* h_j_PassBtag_pT_valBand = new TH1F("h_j_PassBtag_pT_valBand",  "h_j_PassBtag_pT_valBand",  nBins, x_bins);
   TH1F* h_j_PassBtag_pT_SR      = new TH1F("h_j_PassBtag_pT_SR",       "h_j_PassBtag_pT_SR",       nBins, x_bins);

   TH1F* h_j_csc_Match_pT50_100  = new TH1F("h_j_csc_Match_pT50_100", "h_j_csc_Match_pT50_100",   nBins, x_bins);
   TH1F* h_j_csc_Match_pT        = new TH1F("h_j_csc_Match_pT",       "h_j_csc_Match_pT",      nBins, x_bins);
   TH1F* h_j_csc_NoMatch_pT      = new TH1F("h_j_csc_NoMatch_pT",      "h_j_csc_NoMatch_pT",      nBins, x_bins);

   TH1F* h_cscRechitClusterSize = new TH1F("h_cscRechitClusterSize", "h_cscRechitClusterSize", 100, 0, 600);

   int n50_100 = 0;
   int nTotal = 0;
   std::fill_n(nFound, nYBins, 0.0);
   bool found50_100;
   //std::cout<<"In Loop"<<std::endl;
   Long64_t nbytes = 0, nb = 0;
   std::cout<< nentries2<<std::endl;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      found50_100 = false;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if(jentry%100000 ==0) std::cout<<"Processing "<<jentry<<"  of "<<nentries2<<std::endl; 
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      //if(jentry>5000) break;
      //if(met<30.) continue;  //----------------Turned off for getting BP nJets
      // Jet loop
      h_nJets->Fill(nJets);
      double j_eta, j_pT, j_phi, dr_j_csc;
      j_eta= j_pT =j_phi = dr_j_csc = -999;
      for(int j = 0; j < nJets; j++){
        //only care for jets passing b-tagging req.
        //if(jetCISV[j] < 0.8484) continue; //original
        //from https://twiki.cern.ch/twiki/bin/view/CMS/BtagRecommendation80X
        //if(jetCISV[j] < 0.460) continue;  //loose
        //if(jetCISV[j] < 0.800) continue;  //medium
        //if(jetCISV[j] < 0.935) continue;  //tight
        if(jetPt[j] < 20.) continue;
        j_eta = jetEta[j];
        j_phi = jetPhi[j];
        j_pT = jetPt[j];
        h_j_PassBtag_pT ->Fill(j_pT);
        h_JetCISV->Fill(jetCISV[j]);
        double c_eta, c_phi;
        c_eta = c_phi = -999;
        bool matchFound = false;
        bool matchFound50_100 = false;
        std::fill_n(matchesFound, nYBins, false);
        //loop over CSC clusters
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
          for (int k = 0; k<nYBins; k++)
          {
           //if ( cscRechitClusterSize[c] >=y_bins[k] && cscRechitClusterSize[c]<y_bins[k+1] ) matchesFound[k] = true; //old method, not inclusive
           //if ( cscRechitClusterSize[c] < y_bins[k] ) matchesFound[k] = true;  //--- Invert CS cut
           if ( cscRechitClusterSize[c] >=y_bins[k] && jetCISV[j] >= 0.460) matchesFound[k] = true;
          }
         }
        }//end CSC loop
        if (matchFound){
          h_j_csc_Match_pT->Fill(j_pT);
        }
        else{
          h_j_csc_NoMatch_pT->Fill(j_pT);
        }
        if (matchFound50_100){
          h_j_csc_Match_pT50_100->Fill(j_pT);
          found50_100=true;
        }
        for (int l =0; l<nYBins; l++){
          if (matchesFound[l])         h_Num        ->Fill(j_pT,y_bins[l]+5.);
        }

      } //---jet loop
      if(found50_100)  n50_100++;
      for (int l =0; l<nYBins; l++){
        if (matchesFound[l]) nFound[l]++;
      }
      
      nTotal++;
   }//end loop events
   std::cout<< "nFound50_100: "<< n50_100 <<std::endl;
   for (int y=1; y<=nYBins; y++){
    std::cout<<"bin "<<y<<"_"<<y+1<<"  "<<nFound[y]<<std::endl;
    for (int x=1; x<=nBins; x++){
      h_Den->SetBinContent(x,y,h_j_PassBtag_pT->GetBinContent(x)); 
    }
   }
   h_Eff = (TH2F*) h_Num->Clone();
   h_Eff->Divide(h_Den);
   h_Eff->SetTitle("h_Eff");
   h_Eff->SetName("h_Eff");
   h_Eff->Sumw2();
   TH1F* h_j_csc_MatchEff_pT50_100   = DivideHists(h_j_csc_Match_pT50_100  ,h_j_PassBtag_pT,"h_j_csc_MatchEff_pT50_100");
   if (DOLOCAL){
     TCanvas *c = new TCanvas("c1", "c1", 800, 600);
     h_j_PassBtag_pT->Draw("hist");
     c->SaveAs("h_j_PassBtag_pT.pdf");
     c->SaveAs("h_j_PassBtag_pT.png");

     c->Clear();
   }
  // h_JetCISV->Write();
  // h_nJets->Write();
   h_j_csc_Match_pT50_100->Write();
   h_cscRechitClusterSize->Write();
   h_j_csc_MatchEff_pT50_100->Write();
   h_j_PassBtag_pT->Write();
   h_Eff->Write();
   h_Num->Write();
   h_Den->Write();
   outFile->Close();
}
