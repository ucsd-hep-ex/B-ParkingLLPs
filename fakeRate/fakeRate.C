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

  //--if pass all vetos
  return true;
}

bool fakeRate::isGoodDT(int index){
  //--passOverlapMuon
  if(DrOverlapMuon(index, "dt") <= 0.8, "dt") return false;
  //--MinClusterSize
  if(dtRechitClusterSize[index] < 50) return false;
  //--ClusterEta
  if( fabs(dtRechitClusterEta[index]) >= 1.9) return false;
  //--RPCMatching
  if (dtRechitCluster_match_RPChits_dPhi0p5[index] < 0) return false;
  //--MuonVeto
  if (dtRechitClusterMuonVetoPt[index] > 20.) return false;
  //--MB1Veto
  if (dtRechitCluster_match_MB1hits_0p5[index] >1) return false;
  //--RPCTimeCut
  if(dtRechitCluster_match_RPCBx_dPhi0p5[index] != 0) return false;
  //--MB1Adj
  if(dtRechitCluster_match_MB1hits_cosmics_plus[index]>8 && dtRechitCluster_match_MB1hits_cosmics_minus[index]>8) return false;
  //--MaxStation
  if(dtRechitClusterMaxStation[index] < 3) return false;

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

   TH1F* h_nPass      = new TH1F("h_nPass","h_nPass", 4,0,3);
   TH1F* h_nPass_dt   = new TH1F("h_nPass_dt","h_nPass_dt", 4,0,3);
   TH1F* h_nPassTotal = new TH1F("h_nPassTotal","h_nPassTotal", 4,0,3);
   TH1F* h_nJets   = new TH1F("h_nJets", "h_nJets", 20, 0, 20);
   TH1F* h_JetCISV = new TH1F("h_JetCISV", "h_JetCISV", 30, 0, 1.5);
   TH1F* h_dr_j_csc = new TH1F("h_dr_j_csc", "h_dr_j_csc", 50, 0, 15);
   TH1F* h_dr_j_dt  = new TH1F("h_dr_j_dt", "h_dr_j_dt", 50, 0, 15);
   TH1F* h_j_PassBtag_pT         = new TH1F("h_j_PassBtag_pT",        "h_j_PassBtag_pT",          nBins, x_bins);
   TH1F* h_j_csc_Match_pT        = new TH1F("h_j_csc_Match_pT",       "h_j_csc_Match_pT",         nBins, x_bins);
   TH1F* h_j_csc_Match_pT50_100  = new TH1F("h_j_csc_Match_pT50_100", "h_j_csc_Match_pT50_100",   nBins, x_bins);
   TH1F* h_j_csc_Match_pT100_200 = new TH1F("h_j_csc_Match_pT100_200", "h_j_csc_Match_pT100_200", nBins, x_bins);
   TH1F* h_j_csc_Match_pT200_300 = new TH1F("h_j_csc_Match_pT200_300", "h_j_csc_Match_pT200_300", nBins, x_bins);
   TH1F* h_j_csc_Match_pT300     = new TH1F("h_j_csc_Match_pT300",     "h_j_csc_Match_pT300",     nBins, x_bins);
   TH1F* h_j_csc_NoMatch_pT      = new TH1F("h_j_csc_NoMatch_pT",      "h_j_csc_NoMatch_pT",      nBins, x_bins);
   TH1F* h_j_dt_Match_pT        = new TH1F("h_j_dt_Match_pT",        "h_j_dt_Match_pT",         nBins, x_bins);
   TH1F* h_j_dt_Match_pT50_100  = new TH1F("h_j_dt_Match_pT50_100",  "h_j_dt_Match_pT50_100",   nBins, x_bins);
   TH1F* h_j_dt_Match_pT100_200 = new TH1F("h_j_dt_Match_pT100_200", "h_j_dt_Match_pT100_200", nBins, x_bins);
   TH1F* h_j_dt_Match_pT200_300 = new TH1F("h_j_dt_Match_pT200_300", "h_j_dt_Match_pT200_300", nBins, x_bins);
   TH1F* h_j_dt_Match_pT300     = new TH1F("h_j_dt_Match_pT300",     "h_j_dt_Match_pT300",     nBins, x_bins);
   TH1F* h_j_dt_NoMatch_pT      = new TH1F("h_j_dt_NoMatch_pT",      "h_j_dt_NoMatch_pT",      nBins, x_bins);

   TH1F* h_j_PassBtag_eta = new TH1F("h_j_PassBtag_eta", "h_j_PassBtag_eta", 30, -5, 5);
   TH1F* h_j_csc_Match_eta = new TH1F("h_j_csc_Match_eta", "h_j_csc_Match_eta", 30, -5, 5);
   TH1F* h_j_csc_Match_eta50_100 = new TH1F("h_j_csc_Match_eta50_100", "h_j_csc_Match_eta50_100", 30, -5, 5);
   TH1F* h_j_csc_Match_eta100_200 = new TH1F("h_j_csc_Match_eta100_200", "h_j_csc_Match_eta100_200", 30, -5, 5);
   TH1F* h_j_csc_Match_eta200_300 = new TH1F("h_j_csc_Match_eta200_300", "h_j_csc_Match_eta200_300", 30, -5, 5);
   TH1F* h_j_csc_Match_eta300 = new TH1F("h_j_csc_Match_eta300", "h_j_csc_Match_eta300", 30, -5, 5);
   TH1F* h_j_csc_NoMatch_eta = new TH1F("h_j_csc_NoMatch_eta", "h_j_csc_NoMatch_eta", 30, -5, 5);
   TH1F* h_j_dt_Match_eta        = new TH1F("h_j_dt_Match_eta",        "h_j_dt_Match_eta", 30, -5, 5);
   TH1F* h_j_dt_Match_eta50_100  = new TH1F("h_j_dt_Match_eta50_100",  "h_j_dt_Match_eta50_100", 30, -5, 5);
   TH1F* h_j_dt_Match_eta100_200 = new TH1F("h_j_dt_Match_eta100_200", "h_j_dt_Match_eta100_200", 30, -5, 5);
   TH1F* h_j_dt_Match_eta200_300 = new TH1F("h_j_dt_Match_eta200_300", "h_j_dt_Match_eta200_300", 30, -5, 5);
   TH1F* h_j_dt_Match_eta300     = new TH1F("h_j_dt_Match_eta300",     "h_j_dt_Match_eta300", 30, -5, 5);
   TH1F* h_j_dt_NoMatch_eta      = new TH1F("h_j_dt_NoMatch_eta",      "h_j_dt_NoMatch_eta", 30, -5, 5);
   
   TH1F* h_cscRechitClusterSize = new TH1F("h_cscRechitClusterSize", "h_cscRechitClusterSize", 100, 0, 600);
   TH1F* h_dtRechitClusterSize  = new TH1F("h_dtRechitClusterSize", "h_dtRechitClusterSize", 100, 0, 600);

   float counter = 0;
   int n50_100 = 0;
   int n100_200 = 0;
   int n200_300 = 0;
   int n300 = 0;
   int dt_n50_100 = 0;
   int dt_n100_200 = 0;
   int dt_n200_300 = 0;
   int dt_n300 = 0;
   int nTotal = 0;
   bool found50_100;
   bool found100_200;
   bool found200_300;
   bool found300;
   bool dt_found50_100;
   bool dt_found100_200;
   bool dt_found200_300;
   bool dt_found300;
   //std::cout<<"In Loop"<<std::endl;
   Long64_t nbytes = 0, nb = 0;
   std::cout<< nentries2<<std::endl;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      found50_100 = false;
      found100_200 = false;
      found200_300 = false;
      found300 = false;
      dt_found50_100 = false;
      dt_found100_200 = false;
      dt_found200_300 = false;
      dt_found300 = false;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if(jentry%100000 ==0) std::cout<<"Processing "<<jentry<<"  of "<<nentries2<<std::endl; 
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      //if(jentry>10000) break;
      if(met<30.) continue;
      // Jet loop
      h_nJets->Fill(nJets);
      double j_eta = -999;
      double j_pT = -999;
      double j_phi = -999;
      double dr_j_csc = -999;
      double dr_j_dt = -999;
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
        double d_eta = -999;
        double d_phi = -999;
        bool matchFound = false;
        bool matchFound50_100 = false;
        bool matchFound100_200 = false;
        bool matchFound200_300 = false;
        bool matchFound300 = false;
        bool dt_matchFound = false;
        bool dt_matchFound50_100 = false;
        bool dt_matchFound100_200 = false;
        bool dt_matchFound200_300 = false;
        bool dt_matchFound300 = false;
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
          if (cscRechitClusterSize[c] >=200 && cscRechitClusterSize[c]<300) matchFound200_300 = true;
          if (cscRechitClusterSize[c] >=300                               ) matchFound300 = true;
         }
        }//end CSC loop
        for (int d = 0; d < nDtRechitClusters; d++){
         if(!isGoodDT(d)) continue;
         h_dtRechitClusterSize->Fill(dtRechitClusterSize[d]);
         d_eta = dtRechitClusterEta[d];
         d_phi = dtRechitClusterPhi[d];
         dr_j_dt = dR(d_eta,d_phi,j_eta,j_phi); 
         h_dr_j_dt->Fill(dr_j_dt);
         if (dr_j_dt < 0.4){
          dt_matchFound = true;
          if (dtRechitClusterSize[d] >=50  && dtRechitClusterSize[d]<100) dt_matchFound50_100 = true;
          if (dtRechitClusterSize[d] >=100 && dtRechitClusterSize[d]<200) dt_matchFound100_200 = true;
          if (dtRechitClusterSize[d] >=200 && dtRechitClusterSize[d]<300) dt_matchFound200_300 = true;
          if (dtRechitClusterSize[d] >=300                              ) dt_matchFound300 = true;
         }
        }//end DT loop
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
        if (matchFound200_300){
          h_j_csc_Match_pT200_300->Fill(j_pT);
          h_j_csc_Match_eta200_300->Fill(j_eta);
          found200_300=true;
        }
        if (matchFound300){
          h_j_csc_Match_pT300->Fill(j_pT);
          h_j_csc_Match_eta300->Fill(j_eta);
          found300=true;
        }
        //Now for DTs
        if (dt_matchFound){
          h_j_dt_Match_pT->Fill(j_pT);
          h_j_dt_Match_eta->Fill(j_eta);
        }
        else{
          h_j_dt_NoMatch_pT->Fill(j_pT);
          h_j_dt_NoMatch_eta->Fill(j_eta);
        }
        if (dt_matchFound50_100){
          h_j_dt_Match_pT50_100->Fill(j_pT);
          h_j_dt_Match_eta50_100->Fill(j_eta);
          dt_found50_100=true;
        }
        if (dt_matchFound100_200){
          h_j_dt_Match_pT100_200->Fill(j_pT);
          h_j_dt_Match_eta100_200->Fill(j_eta);
          dt_found100_200=true;
        }
        if (dt_matchFound200_300){
          h_j_dt_Match_pT200_300->Fill(j_pT);
          h_j_dt_Match_eta200_300->Fill(j_eta);
          dt_found200_300=true;
        }
        if (dt_matchFound300){
          h_j_dt_Match_pT300->Fill(j_pT);
          h_j_dt_Match_eta300->Fill(j_eta);
          dt_found300=true;
        }
      }
      if(found50_100)  n50_100++;
      if(found100_200) n100_200++;
      if(found200_300) n200_300++;
      if(found300)     n300++;
      if(dt_found50_100)  dt_n50_100++;
      if(dt_found100_200) dt_n100_200++;
      if(dt_found200_300) dt_n200_300++;
      if(dt_found300)     dt_n300++;
      nTotal++;
   }//end loop events
   h_nPass->SetBinContent(1,n50_100);
   h_nPass->SetBinContent(2,n100_200);
   h_nPass->SetBinContent(3,n200_300);
   h_nPass->SetBinContent(4,n300);
   h_nPassTotal->SetBinContent(1,nTotal);
   h_nPassTotal->SetBinContent(2,nTotal);
   h_nPassTotal->SetBinContent(3,nTotal);
   h_nPassTotal->SetBinContent(4,nTotal);
   h_nPass_dt->SetBinContent(1,dt_n50_100);
   h_nPass_dt->SetBinContent(2,dt_n100_200);
   h_nPass_dt->SetBinContent(3,dt_n200_300);
   h_nPass_dt->SetBinContent(4,dt_n300);
   std::cout<<counter<<std::endl;
   TH1F* h_nPassEff                  = DivideHists(h_nPass,h_nPassTotal,"h_nPassEff");
   TH1F* h_nPassEff_dt               = DivideHists(h_nPass_dt,h_nPassTotal,"h_nPassEff");
   TH1F* h_j_csc_MatchEff_pT         = DivideHists(h_j_csc_Match_pT        ,h_j_PassBtag_pT,"h_j_csc_MatchEff_pT");
   TH1F* h_j_csc_MatchEff_pT50_100   = DivideHists(h_j_csc_Match_pT50_100  ,h_j_PassBtag_pT,"h_j_csc_MatchEff_pT50_100");
   TH1F* h_j_csc_MatchEff_pT100_200  = DivideHists(h_j_csc_Match_pT100_200 ,h_j_PassBtag_pT,"h_j_csc_MatchEff_pT100_200");
   TH1F* h_j_csc_MatchEff_pT200_300  = DivideHists(h_j_csc_Match_pT200_300 ,h_j_PassBtag_pT,"h_j_csc_MatchEff_pT200_300");
   TH1F* h_j_csc_MatchEff_pT300      = DivideHists(h_j_csc_Match_pT300     ,h_j_PassBtag_pT,"h_j_csc_MatchEff_pT300");
   TH1F* h_j_csc_MatchEff_eta        = DivideHists(h_j_csc_Match_eta       ,h_j_PassBtag_eta,"h_j_csc_MatchEff_eta");
   TH1F* h_j_csc_MatchEff_eta50_100  = DivideHists(h_j_csc_Match_eta50_100 ,h_j_PassBtag_eta,"h_j_csc_MatchEff_eta50_100");
   TH1F* h_j_csc_MatchEff_eta100_200 = DivideHists(h_j_csc_Match_eta100_200,h_j_PassBtag_eta,"h_j_csc_MatchEff_eta100_200");
   TH1F* h_j_csc_MatchEff_eta200_300 = DivideHists(h_j_csc_Match_eta200_300,h_j_PassBtag_eta,"h_j_csc_MatchEff_eta200_300");
   TH1F* h_j_csc_MatchEff_eta300     = DivideHists(h_j_csc_Match_eta300    ,h_j_PassBtag_eta,"h_j_csc_MatchEff_eta300");
   TH1F* h_j_dt_MatchEff_pT         = DivideHists(h_j_dt_Match_pT        ,h_j_PassBtag_pT,"h_j_dt_MatchEff_pT");
   TH1F* h_j_dt_MatchEff_pT50_100   = DivideHists(h_j_dt_Match_pT50_100  ,h_j_PassBtag_pT,"h_j_dt_MatchEff_pT50_100");
   TH1F* h_j_dt_MatchEff_pT100_200  = DivideHists(h_j_dt_Match_pT100_200 ,h_j_PassBtag_pT,"h_j_dt_MatchEff_pT100_200");
   TH1F* h_j_dt_MatchEff_pT200_300  = DivideHists(h_j_dt_Match_pT200_300 ,h_j_PassBtag_pT,"h_j_dt_MatchEff_pT200_300");
   TH1F* h_j_dt_MatchEff_pT300      = DivideHists(h_j_dt_Match_pT300     ,h_j_PassBtag_pT,"h_j_dt_MatchEff_pT300");
   TH1F* h_j_dt_MatchEff_eta        = DivideHists(h_j_dt_Match_eta       ,h_j_PassBtag_eta,"h_j_dt_MatchEff_eta");
   TH1F* h_j_dt_MatchEff_eta50_100  = DivideHists(h_j_dt_Match_eta50_100 ,h_j_PassBtag_eta,"h_j_dt_MatchEff_eta50_100");
   TH1F* h_j_dt_MatchEff_eta100_200 = DivideHists(h_j_dt_Match_eta100_200,h_j_PassBtag_eta,"h_j_dt_MatchEff_eta100_200");
   TH1F* h_j_dt_MatchEff_eta200_300 = DivideHists(h_j_dt_Match_eta200_300,h_j_PassBtag_eta,"h_j_dt_MatchEff_eta200_300");
   TH1F* h_j_dt_MatchEff_eta300     = DivideHists(h_j_dt_Match_eta300    ,h_j_PassBtag_eta,"h_j_dt_MatchEff_eta300");

   if (DOLOCAL){
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
     h_j_csc_MatchEff_pT200_300->Draw("hist");
     c->SaveAs("h_j_csc_MatchEff_pT200_300.pdf");
     c->SaveAs("h_j_csc_MatchEff_pT200_300.png");

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
     h_j_csc_MatchEff_eta200_300->Draw("hist");
     c->SaveAs("h_j_csc_MatchEff_eta200_300.pdf");
     c->SaveAs("h_j_csc_MatchEff_eta200_300.png");
   }

   h_JetCISV->Write();
   h_nJets->Write();
   h_cscRechitClusterSize->Write();
   h_dr_j_csc->Write();
   h_dtRechitClusterSize->Write();
   h_dr_j_dt->Write();

   h_nPass->Write();
   h_nPassTotal->Write();
   h_nPassEff->Write();

   h_j_csc_NoMatch_pT->Write();
   h_j_PassBtag_pT->Write();
   h_j_csc_NoMatch_eta->Write();
   h_j_PassBtag_eta->Write();

   h_j_csc_MatchEff_pT->Write();
   h_j_csc_MatchEff_pT50_100->Write();
   h_j_csc_MatchEff_pT100_200->Write();
   h_j_csc_MatchEff_pT200_300->Write();
   h_j_csc_MatchEff_pT300->Write();
   h_j_csc_Match_pT->Write();
   h_j_csc_Match_pT50_100->Write();
   h_j_csc_Match_pT100_200->Write();
   h_j_csc_Match_pT200_300->Write();
   h_j_csc_Match_pT300->Write();

   h_j_csc_MatchEff_eta->Write();
   h_j_csc_MatchEff_eta50_100->Write();
   h_j_csc_MatchEff_eta100_200->Write();
   h_j_csc_MatchEff_eta200_300->Write();
   h_j_csc_MatchEff_eta300->Write();
   h_j_csc_Match_eta->Write();
   h_j_csc_Match_eta50_100->Write();
   h_j_csc_Match_eta100_200->Write();
   h_j_csc_Match_eta200_300->Write();
   h_j_csc_Match_eta300->Write();

   h_j_dt_MatchEff_pT->Write();
   h_j_dt_MatchEff_pT50_100->Write();
   h_j_dt_MatchEff_pT100_200->Write();
   h_j_dt_MatchEff_pT200_300->Write();
   h_j_dt_MatchEff_pT300->Write();
   h_j_dt_Match_pT->Write();
   h_j_dt_Match_pT50_100->Write();
   h_j_dt_Match_pT100_200->Write();
   h_j_dt_Match_pT200_300->Write();
   h_j_dt_Match_pT300->Write();

   h_j_dt_MatchEff_eta->Write();
   h_j_dt_MatchEff_eta50_100->Write();
   h_j_dt_MatchEff_eta100_200->Write();
   h_j_dt_MatchEff_eta200_300->Write();
   h_j_dt_MatchEff_eta300->Write();
   h_j_dt_Match_eta->Write();
   h_j_dt_Match_eta50_100->Write();
   h_j_dt_Match_eta100_200->Write();
   h_j_dt_Match_eta200_300->Write();
   h_j_dt_Match_eta300->Write();

   outFile->Close();
}
