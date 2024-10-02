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
//Bin 0-20  0/0: 0
//Bin 20-30  7/1.52953e+08: 4.57657e-08
//Bin 30-40  3/5.77042e+07: 5.19892e-08
//Bin 40-50  5/2.72756e+07: 1.83314e-07
//Bin 50-60  2/1.67449e+07: 1.19439e-07
//Bin 60-75  3/1.58503e+07: 1.89271e-07
//Bin 75-200  8/3.08478e+07: 2.59337e-07
//Bin 200-500  5/3.67576e+06: 1.36026e-06
//Bin 500-1000  0/166103: 0

Float_t FakeRate(Float_t Pt){
  Float_t fr = 1.0;
  if (Pt < 20.  || Pt >= 1000.) fr = 0.;
  if (Pt >= 20.  && Pt < 30. ) fr = 3.35397e-06;
  if (Pt >= 30.  && Pt < 40. ) fr = 4.21113e-06;
  if (Pt >= 40.  && Pt < 50. ) fr = 5.05947e-06;
  if (Pt >= 50.  && Pt < 60. ) fr = 6.15113e-06;
  if (Pt >= 60.  && Pt < 75. ) fr = 6.81374e-06;
  if (Pt >= 75.  && Pt < 200.) fr = 7.5532e-06;
  if (Pt >= 200. && Pt < 500.) fr = 1.44188e-05;
  if (Pt >= 500. && Pt < 1000.) fr = 1.80611e-05;
  return fr;
}
Float_t FakeRate50_100(Float_t Pt){
  Float_t fr = 1.0;
  if (Pt < 20.  || Pt >= 1000.) fr = 0.;
  if (Pt >= 20.  && Pt < 30. ) fr = 2.929e-06;
  if (Pt >= 30.  && Pt < 40. ) fr = 3.65658e-06;
  if (Pt >= 40.  && Pt < 50. ) fr = 4.36287e-06;
  if (Pt >= 50.  && Pt < 60. ) fr = 4.8373e-06;
  if (Pt >= 60.  && Pt < 75. ) fr = 5.29958e-06;
  if (Pt >= 75.  && Pt < 200.) fr = 6.19168e-06;
  if (Pt >= 200. && Pt < 500.) fr = 1.08821e-05;
  if (Pt >= 500. && Pt < 1000.) fr = 1.80611e-05;
  return fr;
}
Float_t FakeRate100_200(Float_t Pt){
  Float_t fr = 1.0;
  if (Pt < 20.  || Pt >= 500.) fr = 0.;
  if (Pt >= 20.  && Pt < 30. ) fr = 3.72663e-07;
  if (Pt >= 30.  && Pt < 40. ) fr = 4.50573e-07;
  if (Pt >= 40.  && Pt < 50. ) fr = 5.13279e-07;
  if (Pt >= 50.  && Pt < 60. ) fr = 1.07496e-06;
  if (Pt >= 60.  && Pt < 75. ) fr = 1.2618e-06;
  if (Pt >= 75.  && Pt < 200.) fr = 1.06977e-06;
  if (Pt >= 200. && Pt < 500.) fr = 1.90437e-06;
  return fr;
}
Float_t FakeRate200_300(Float_t Pt){
  Float_t fr = 1.0;
  if (Pt < 20.  || Pt >= 500.) fr = 0.;
  if (Pt >= 20.  && Pt < 30. ) fr = 4.57657e-08;
  if (Pt >= 30.  && Pt < 40. ) fr = 5.19892e-08;
  if (Pt >= 40.  && Pt < 50. ) fr = 1.83314e-07;
  if (Pt >= 50.  && Pt < 60. ) fr = 1.19439e-07;
  if (Pt >= 60.  && Pt < 75. ) fr = 1.89271e-07;
  if (Pt >= 75.  && Pt < 200.) fr = 2.59337e-07;
  if (Pt >= 200. && Pt < 500.) fr = 1.36026e-06;
  return fr;
}

Float_t FakeRate300(Float_t Pt){
  Float_t fr = 1.0;
  if (Pt < 20.  || Pt >= 500.) fr = 0.;
  if (Pt >= 20.  && Pt < 30. ) fr = 9.70978e-09;
  if (Pt >= 30.  && Pt < 40. ) fr = 3.45226e-08;
  if (Pt >= 40.  && Pt < 50. ) fr = 3.99186e-08;
  if (Pt >= 50.  && Pt < 60. ) fr = 6.25698e-08;
  if (Pt >= 60.  && Pt < 75. ) fr = 7.00959e-08;
  if (Pt >= 75.  && Pt < 200.) fr = 1.15568e-07;
  if (Pt >= 200. && Pt < 500.) fr = 2.1248e-07;
  return fr;
}

TH1F* InitTH1F (TString name, TString title, int nbins, Float_t binLow, Float_t binHigh){

  TH1F* histoTH1F = new TH1F( name , title , nbins , binLow , binHigh );
  histoTH1F->Sumw2();

  return histoTH1F;
}
TH1F* InitTH1F (TString name, TString title, int nbins, float bins[]){

  TH1F* histoTH1F = new TH1F( name , title , nbins , bins );
  histoTH1F->Sumw2();

  return histoTH1F;
}

TH2F* InitTH2F (TString name, TString title, int nbinsX, Float_t binXLow, Float_t binXHigh, int nbinsY, Float_t binYLow, Float_t binYHigh){

  TH2F* histoTH2F = new TH2F( name , title , nbinsX , binXLow , binXHigh, nbinsY , binYLow , binYHigh );
  histoTH2F->Sumw2();

  return histoTH2F;
}

void analyzer_histograms::InitHistos(){
  for (int i = 0; i< SELBINNAMESIZE; i++){
    unsigned n_b = 24;
    unsigned n_b2 = 16;
    float x_bins[n_b] = {50,60,70,80,89,100,110,120,130,140,150,160,170,180,190,200,225,260,300,350,400,500,600,1000};
    float x_bins2[n_b2] = {130,140,150,160,170,180,190,200,225,260,300,350,400,500,600,1000};
    float jetPt_bins[] = {0.,20.,30.,40.,50.,60.,75.,200.,500.,1000.};
    int nBins = sizeof(jetPt_bins)/sizeof(float) -1;
    f_out[i]->cd();
    
    h_nJets  [i] = InitTH1F("h_nJets", "h_nJets", 20, 0, 20);
    h_NoMDS_jetCISV[i] = InitTH1F("h_NoMDS_jetCISV", "h_NoMDS_jetCISV", 30, 0, 1.5);
    h_NoMDS_jetPt  [i] = InitTH1F("h_NoMDS_jetPt",   "h_NoMDS_jetPt", nBins, jetPt_bins);
    h_NoMDS_jetPt_PassDPhi  [i] = InitTH1F("h_NoMDS_jetPt_PassDPhi",   "h_NoMDS_jetPt_PassDPhi", nBins, jetPt_bins);
    h_NoMDS_jetPt_PassDPhi_inRegion  [i] = InitTH1F("h_NoMDS_jetPt_PassDPhi_inRegion",   "h_NoMDS_jetPt_PassDPhi_inRegion", nBins, jetPt_bins);
    h_NoMDS_jetEta [i] = InitTH1F("h_NoMDS_jetEta",  "h_NoMDS_jetEta", 30, -5,5);
    h_NoMDS_jetDPhiLeadMuon [i] = InitTH1F("h_NoMDS_jetDPhiLeadMuon","h_NoMDS_jetDPhiLeadMuon", 30,0,4);
    h_NoMDS_jetDPhiLeadMuonFine [i] = InitTH1F("h_NoMDS_jetDPhiLeadMuonFine","h_NoMDS_jetDPhiLeadMuonFine", 40,0,4);

    h_NoMDS50_100_jetCISV[i] = InitTH1F("h_NoMDS50_100_jetCISV", "h_NoMDS50_100_jetCISV", 30, 0, 1.5);
    h_NoMDS50_100_jetPt  [i] = InitTH1F("h_NoMDS50_100_jetPt",   "h_NoMDS50_100_jetPt", nBins, jetPt_bins);
    h_NoMDS50_100_jetEta [i] = InitTH1F("h_NoMDS50_100_jetEta",  "h_NoMDS50_100_jetEta", 30, -5,5);
    h_NoMDS50_100_jetDPhiLeadMuon [i] = InitTH1F("h_NoMDS50_100_jetDPhiLeadMuon","h_NoMDS50_100_jetDPhiLeadMuon", 30,0,4);
    h_NoMDS50_100_jetDPhiLeadMuonFine [i] = InitTH1F("h_NoMDS50_100_jetDPhiLeadMuonFine","h_NoMDS50_100_jetDPhiLeadMuonFine", 40,0,4);

    h_NoMDS100_200_jetCISV[i] = InitTH1F("h_NoMDS100_200_jetCISV", "h_NoMDS100_200_jetCISV", 30, 0, 1.5);
    h_NoMDS100_200_jetPt  [i] = InitTH1F("h_NoMDS100_200_jetPt",   "h_NoMDS100_200_jetPt", nBins, jetPt_bins);
    h_NoMDS100_200_jetEta [i] = InitTH1F("h_NoMDS100_200_jetEta",  "h_NoMDS100_200_jetEta", 30, -5,5);
    h_NoMDS100_200_jetDPhiLeadMuon [i] = InitTH1F("h_NoMDS100_200_jetDPhiLeadMuon","h_NoMDS100_200_jetDPhiLeadMuon", 30,0,4);
    h_NoMDS100_200_jetDPhiLeadMuonFine [i] = InitTH1F("h_NoMDS100_200_jetDPhiLeadMuonFine","h_NoMDS100_200_jetDPhiLeadMuonFine", 40,0,4);

    h_NoMDS200_300_jetCISV[i] = InitTH1F("h_NoMDS200_300_jetCISV", "h_NoMDS200_300_jetCISV", 30, 0, 1.5);
    h_NoMDS200_300_jetPt  [i] = InitTH1F("h_NoMDS200_300_jetPt",   "h_NoMDS200_300_jetPt", nBins, jetPt_bins);
    h_NoMDS200_300_jetEta [i] = InitTH1F("h_NoMDS200_300_jetEta",  "h_NoMDS200_300_jetEta", 30, -5,5);
    h_NoMDS200_300_jetDPhiLeadMuon [i] = InitTH1F("h_NoMDS200_300_jetDPhiLeadMuon","h_NoMDS200_300_jetDPhiLeadMuon", 30,0,4);
    h_NoMDS200_300_jetDPhiLeadMuonFine [i] = InitTH1F("h_NoMDS200_300_jetDPhiLeadMuonFine","h_NoMDS200_300_jetDPhiLeadMuonFine", 40,0,4);

    h_NoMDS300_jetCISV[i] = InitTH1F(             "h_NoMDS300_jetCISV",            "h_NoMDS300_jetCISV", 30, 0, 1.5);
    h_NoMDS300_jetPt  [i] = InitTH1F(             "h_NoMDS300_jetPt",              "h_NoMDS300_jetPt", nBins, jetPt_bins);
    h_NoMDS300_jetEta [i] = InitTH1F(             "h_NoMDS300_jetEta",             "h_NoMDS300_jetEta", 30, -5,5);
    h_NoMDS300_jetDPhiLeadMuon [i] = InitTH1F(    "h_NoMDS300_jetDPhiLeadMuon",    "h_NoMDS300_jetDPhiLeadMuon", 30,0,4);
    h_NoMDS300_jetDPhiLeadMuonFine [i] = InitTH1F("h_NoMDS300_jetDPhiLeadMuonFine","h_NoMDS300_jetDPhiLeadMuonFine", 40,0,4);
    h_NoMDS300_jetDPhiLeadMuonFine2 [i] = InitTH1F("h_NoMDS300_jetDPhiLeadMuonFine2","h_NoMDS300_jetDPhiLeadMuonFine2", 40,0,4);
    h_NoMDS300_jetDPhiLeadMuonFine2_inRegion [i] = InitTH1F("h_NoMDS300_jetDPhiLeadMuonFine2_inRegion","h_NoMDS300_jetDPhiLeadMuonFine2_inRegion", 40,0,4);

    h_nLeptons  [i] = InitTH1F("h_nLeptons", "h_nLeptons", 100, 0, 100);
    h_gLLP_ctau [i] = InitTH1F("h_gLLP_ctau", "h_gLLP_ctau", 100, 0, 1000);

    h_cscRechitClusterDPhivsSize           [i] = InitTH2F("h_cscRechitClusterDPhivsSize", "h_cscRechitClusterDPhivsSize",650,50,700,40,0,4);
    h_cscRechitClusterPhivsEta             [i] = InitTH2F("h_cscRechitClusterPhivsEta"  , "h_cscRechitClusterPhivsEta",80,-2.,2.,40,-3.5,3.5);

    h_nCscRechits                          [i] = InitTH1F("nCscRechits", "nCscRechits", 300, 0, 300);
    h_cscRechitClusterSize                 [i] = InitTH1F("h_cscRechitClusterSize", "h_cscRechitClusterSize", 650, 50, 700);
    h_cscRechitClusterSize_FailPass        [i] = InitTH1F("h_cscRechitClusterSize_FailPass", "h_cscRechitClusterSizeFailPass", 2, -0.5, 1.5);
    h_cscRechitClusterSize_FailPass_uw     [i] = InitTH1F("h_cscRechitClusterSize_FailPass_uw", "h_cscRechitClusterSizeFailPass_uw", 2, -0.5, 1.5);
    h_cscRechitClusterSize_v               [i] = InitTH1F("h_cscRechitClusterSize_v", "h_cscRechitClusterSize_v", n_b-1, x_bins);
    h_cscRechitClusterSize_v2              [i] = InitTH1F("h_cscRechitClusterSize_v2", "h_cscRechitClusterSize_v2", n_b2-1, x_bins2);
    h_cscRechitClusterDPhiLeadMuon         [i] = InitTH1F("h_cscRechitClusterDPhiLeadMuon", "h_cscRechitClusterDPhiLeadMuon", 30, 0, 4);
    h_cscRechitClusterDPhiLeadMuon_v2      [i] = InitTH1F("h_cscRechitClusterDPhiLeadMuon_v2", "h_cscRechitClusterDPhiLeadMuon_v2", 17, 1, 3.2);
    h_cscRechitClusterDPhiLeadMuon_fail    [i] = InitTH1F("h_cscRechitClusterDPhiLeadMuon_fail", "h_cscRechitClusterDPhiLeadMuon_fail", 40, 0, 4);
    h_cscRechitClusterDPhiLeadMuon_pass    [i] = InitTH1F("h_cscRechitClusterDPhiLeadMuon_pass", "h_cscRechitClusterDPhiLeadMuon_pass", 40, 0, 4);
    h_cscRechitClusterPhi                  [i] = InitTH1F("h_cscRechitClusterPhi", "h_cscRechitClusterPhi", 40, -3.5, 3.5);
    h_cscRechitClusterEta                  [i] = InitTH1F("h_cscRechitClusterEta", "h_cscRechitClusterEta", 40, -5., 5.);
    h_cscRechitClusterEtaZoom              [i] = InitTH1F("h_cscRechitClusterEtaZoom", "h_cscRechitClusterEtaZoom", 80, -2., 2.);
    h_cscRechitClusterMuonVetoPt           [i] = InitTH1F("h_cscRechitClusterMuonVetoPt", "h_cscRechitClusterMuonVetoPt", 100, 0.,200.);
    h_cscRechitClusterTime                 [i] = InitTH1F("h_cscRechitClusterTime"                 , "h_cscRechitClusterTime",         200, -100, 100);
    h_cscRechitClusterTimeWeighted         [i] = InitTH1F("h_cscRechitClusterTimeWeighted"         , "h_cscRechitClusterTimeWeighted", 200, -100, 100);
    h_cscRechitClusterTimeTotal            [i] = InitTH1F("h_cscRechitClusterTimeTotal"            , "h_cscRechitClusterTimeTotal",    200, -100, 100);
    h_cscRechitClusterTimeSpread           [i] = InitTH1F("h_cscRechitClusterTimeSpread",            "h_cscRechitClusterTimeSpread",            200, 0, 200);
    h_cscRechitClusterTimeSpreadWeighted   [i] = InitTH1F("h_cscRechitClusterTimeSpreadWeighted",     "h_cscRechitClusterTimeSpreadWeighted",   200, 0, 200);
    h_cscRechitClusterTimeSpreadWeightedAll[i] = InitTH1F("h_cscRechitClusterTimeSpreadWeightedAll", "h_cscRechitClusterTimeSpreadWeightedAll", 200, 0, 200);

    h_cscRechitClusterZ                    [i] = InitTH1F("h_cscRechitClusterZ", "h_cscRechitClusterZ", 600, -1500., 1500.);
    h_cscRechitClusterNStation             [i] = InitTH1F("h_cscRechitClusterNStation", "h_cscRechitClusterNStation", 600, -1500., 1500.);
    h_cscRechitClusterNStation10           [i] = InitTH1F("h_cscRechitClusterNStation10", "h_cscRechitClusterNStation10", 10, 0., 10.);
    h_cscRechitClusterMaxStation           [i] = InitTH1F("h_cscRechitClusterMaxStation", "h_cscRechitClusterMaxStation", 20, -10., 10.);
    h_cscRechitClusterJetVetoPt            [i] = InitTH1F("h_cscRechitClusterJetVetoPt", "h_cscRechitClusterJetVetoPt", 500, 0., 500.);

    h_nDTRechits                                           [i] = InitTH1F("h_nDTRechits",  "h_nDTRechits",  300, 0, 300);
    h_dtRechitClusterSize                                  [i] = InitTH1F("h_dtRechitClusterSize",  "h_dtRechitClusterSize",  450, 50, 500);
    h_dtRechitClusterSize_FailPass                         [i] = InitTH1F("h_dtRechitClusterSize_FailPass",  "h_dtRechitClusterSize_FailPass",  2, -0.5, 1.5);
    h_dtRechitClusterSize_FailPass_uw                      [i] = InitTH1F("h_dtRechitClusterSize_FailPass_uw",  "h_dtRechitClusterSize_FailPass_uw",  2, -0.5, 1.5);
    h_dtRechitClusterSize_v                                [i] = InitTH1F("h_dtRechitClusterSize_v",  "h_dtRechitClusterSize_v", n_b-1, x_bins);
    h_dtRechitClusterSize_v2                               [i] = InitTH1F("h_dtRechitClusterSize_v2", "h_dtRechitClusterSize_v2", n_b2-1, x_bins2);
    h_dtRechitClusterPhi                                   [i] = InitTH1F("h_dtRechitClusterPhi",  "h_dtRechitClusterPhi",  40, -3.5, 3.5);
    h_dtRechitClusterEta                                   [i] = InitTH1F("h_dtRechitClusterEta",  "h_dtRechitClusterEta",  40, -5., 5);
    h_dtRechitClusterMuonVetoPt                            [i] = InitTH1F("h_dtRechitClusterMuonVetoPt", "h_dtRechitClusterMuonVetoPt", 100, 0.,200.);
    h_dtRechitClusterDPhiLeadMuon                          [i] = InitTH1F("h_dtRechitClusterDPhiLeadMuon",  "h_dtRechitClusterDPhiLeadMuon",  30, 0, 4);
    h_dtRechitClusterDPhiLeadMuon_fail                     [i] = InitTH1F("h_dtRechitClusterDPhiLeadMuon_fail",  "h_dtRechitClusterDPhiLeadMuon_fail",  30, 0, 4);
    h_dtRechitClusterDPhiLeadMuon_pass                     [i] = InitTH1F("h_dtRechitClusterDPhiLeadMuon_pass",  "h_dtRechitClusterDPhiLeadMuon_pass",  30, 0, 4);
    h_dtRechitCluster_match_RPCBx_dPhi0p5                  [i] = InitTH1F("h_dtRechitCluster_match_RPCBx_dPhi0p5",  "h_dtRechitCluster_match_RPCBx_dPhi0p5",  20, -10, 10);
    h_dtRechitCluster_match_RPCTime_dR0p4                  [i] = InitTH1F("h_dtRechitCluster_match_RPCTime_dR0p4", "h_dtRechitCluster_match_RPCTime_dR0p4",  200, -100, 100);
    h_dtRechitCluster_match_RPCTimeSpread_dR0p4            [i] = InitTH1F("h_dtRechitCluster_match_RPCTimeSpread_dR0p4", "h_dtRechitCluster_match_RPCTimeSpread_dR0p4",  200, -100, 100);
    h_dtRechitCluster_match_RPChits_dR0p4                  [i] = InitTH1F("h_dtRechitCluster_match_RPChits_dR0p4", "h_dtRechitCluster_match_RPChits_dR0p4",  200, -100, 100);
    h_dtRechitCluster_match_RPCTime_dPhi0p5                [i] = InitTH1F("h_dtRechitCluster_match_RPCTime_dPhi0p5",  "h_dtRechitCluster_match_RPCTime_dPhi0p5",  200, -100, 100);
    h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5          [i] = InitTH1F("h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5", "h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5",  200, -100, 100);
    h_dtRechitCluster_match_RPCTime_sameStation_dR0p4      [i] = InitTH1F("h_dtRechitCluster_match_RPCTime_sameStation_dR0p4", "h_dtRechitCluster_match_RPCTime_sameStation_dR0p4", 200, -100, 100);
    h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4[i] = InitTH1F("h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4", "h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4", 200, -100, 100);
    h_dtRechitClusterMaxStation                            [i] = InitTH1F("h_dtRechitClusterMaxStation", "h_dtRechitClusterMaxStation", 30, 0, 5);
  }
}

void analyzer_histograms::FillHistos(int selbin, Float_t ew, const std::vector<int> &CscList){
  f_out[selbin]->cd();
  h_nLeptons[selbin]->Fill(nLeptons, ew);
  h_gLLP_ctau[selbin]->Fill(gLLP_ctau, ew);

  h_nJets[selbin]->Fill(nJets,ew);
  for(int j = 0; j<jet_list.size(); j++){
    int jet=jet_list[j];
    double dPhi_j = -999;
    if(muon_list.size()>0) dPhi_j = DeltaPhi(lepPhi[muon_list[0]], jetPhi[jet]);
    Float_t FR       = FakeRate(jetPt[jet]);
    Float_t FR50_100 = FakeRate50_100(jetPt[jet]);
    Float_t FR100_200= FakeRate100_200(jetPt[jet]);
    Float_t FR200_300= FakeRate200_300(jetPt[jet]);
    Float_t FR300    = FakeRate300(jetPt[jet]);
    h_NoMDS_jetPt               [selbin]->Fill(jetPt[jet],ew*FR);
    h_NoMDS_jetCISV             [selbin]->Fill(jetCISV[jet],ew*FR);
    h_NoMDS_jetEta              [selbin]->Fill(jetEta[jet],ew*FR);
    h_NoMDS_jetDPhiLeadMuon     [selbin]->Fill(dPhi_j, ew*FR);
    h_NoMDS_jetDPhiLeadMuonFine [selbin]->Fill(dPhi_j, ew*FR);

    h_NoMDS50_100_jetPt               [selbin]->Fill(jetPt[jet],ew*FR50_100);
    h_NoMDS50_100_jetCISV             [selbin]->Fill(jetCISV[jet],ew*FR50_100);
    h_NoMDS50_100_jetEta              [selbin]->Fill(jetEta[jet],ew*FR50_100);
    h_NoMDS50_100_jetDPhiLeadMuon     [selbin]->Fill(dPhi_j, ew*FR50_100);
    h_NoMDS50_100_jetDPhiLeadMuonFine [selbin]->Fill(dPhi_j, ew*FR50_100);

    h_NoMDS100_200_jetPt               [selbin]->Fill(jetPt[jet],ew*FR100_200);
    h_NoMDS100_200_jetCISV             [selbin]->Fill(jetCISV[jet],ew*FR100_200);
    h_NoMDS100_200_jetEta              [selbin]->Fill(jetEta[jet],ew*FR100_200);
    h_NoMDS100_200_jetDPhiLeadMuon     [selbin]->Fill(dPhi_j, ew*FR100_200);
    h_NoMDS100_200_jetDPhiLeadMuonFine [selbin]->Fill(dPhi_j, ew*FR100_200);

    h_NoMDS200_300_jetPt               [selbin]->Fill(jetPt[jet],ew*FR200_300);
    h_NoMDS200_300_jetCISV             [selbin]->Fill(jetCISV[jet],ew*FR200_300);
    h_NoMDS200_300_jetEta              [selbin]->Fill(jetEta[jet],ew*FR200_300);
    h_NoMDS200_300_jetDPhiLeadMuon     [selbin]->Fill(dPhi_j, ew*FR200_300);
    h_NoMDS200_300_jetDPhiLeadMuonFine [selbin]->Fill(dPhi_j, ew*FR200_300);

    h_NoMDS300_jetPt               [selbin]->Fill(jetPt[jet],ew*FR300);
    h_NoMDS300_jetCISV             [selbin]->Fill(jetCISV[jet],ew*FR300);
    h_NoMDS300_jetEta              [selbin]->Fill(jetEta[jet],ew*FR300);
    h_NoMDS300_jetDPhiLeadMuon     [selbin]->Fill(dPhi_j, ew*FR300);
    h_NoMDS300_jetDPhiLeadMuonFine [selbin]->Fill(dPhi_j, ew*FR300);
    if(dPhi_j > dPhiCut_LeadMu_CscCluster){
      h_NoMDS300_jetDPhiLeadMuonFine2 [selbin]->Fill(dPhi_j, ew*FR300);
      h_NoMDS_jetPt_PassDPhi          [selbin]->Fill(jetPt[jet],ew);
      if(CscList.size()>0){
        h_NoMDS300_jetDPhiLeadMuonFine2_inRegion [selbin]->Fill(dPhi_j, ew*FR300);
        h_NoMDS_jetPt_PassDPhi_inRegion          [selbin]->Fill(jetPt[jet]);//,ew);
      }
    }
  }
  if(CscList.size()>0){
    h_nCscRechits[selbin]->Fill(nCscRechits, ew);
    bool passCSC = false;
    bool wasFilled_fail = false;
    bool wasFilled_pass = false;
    
    for(int i = 0; i < CscList.size(); i++){
      int c =  CscList[i];
      double dPhi = -999;
      if(muon_list.size()>0) dPhi = DeltaPhi(lepPhi[muon_list[0]], cscRechitClusterPhi[c]);
      h_cscRechitClusterPhivsEta               [selbin]->Fill(cscRechitClusterEta[c], cscRechitClusterPhi[c], ew);
      h_cscRechitClusterDPhivsSize             [selbin]->Fill(cscRechitClusterSize[c],                  dPhi, ew);

      h_cscRechitClusterDPhiLeadMuon           [selbin]->Fill(dPhi, ew);  
      h_cscRechitClusterDPhiLeadMuon_v2        [selbin]->Fill(dPhi, ew);  
      h_cscRechitClusterSize                   [selbin]->Fill(cscRechitClusterSize                 [c], ew);
      if(cscRechitClusterSize[c]>CscSize)      passCSC = true;
      if(passCSC          && !wasFilled_pass) {
        h_cscRechitClusterDPhiLeadMuon_pass[selbin]->Fill(dPhi, ew); 
        wasFilled_pass = true;
      }
      if(passCSC == false && !wasFilled_fail) {
        h_cscRechitClusterDPhiLeadMuon_fail[selbin]->Fill(dPhi, ew); 
        wasFilled_fail = true;
      }
      h_cscRechitClusterSize_v                 [selbin]->Fill(cscRechitClusterSize                 [c], ew);
      h_cscRechitClusterSize_v2                [selbin]->Fill(cscRechitClusterSize                 [c], ew);
      h_cscRechitClusterEta                    [selbin]->Fill(cscRechitClusterEta                  [c], ew);
      h_cscRechitClusterEtaZoom                [selbin]->Fill(cscRechitClusterEta                  [c], ew);
      h_cscRechitClusterMuonVetoPt             [selbin]->Fill(cscRechitClusterMuonVetoPt           [c], ew);
      h_cscRechitClusterPhi                    [selbin]->Fill(cscRechitClusterPhi                  [c], ew);
      h_cscRechitClusterTime                   [selbin]->Fill(cscRechitClusterTime                 [c], ew);
      h_cscRechitClusterTimeWeighted           [selbin]->Fill(cscRechitClusterTimeWeighted         [c], ew);
      h_cscRechitClusterTimeTotal              [selbin]->Fill(cscRechitClusterTimeTotal            [c], ew);
      h_cscRechitClusterTimeSpread             [selbin]->Fill(cscRechitClusterTimeSpread           [c], ew);
      h_cscRechitClusterTimeSpreadWeighted     [selbin]->Fill(cscRechitClusterTimeSpreadWeighted   [c], ew);
      h_cscRechitClusterTimeSpreadWeightedAll  [selbin]->Fill(cscRechitClusterTimeSpreadWeightedAll[c], ew);
      h_cscRechitClusterZ                      [selbin]->Fill(cscRechitClusterZ                    [c], ew);
      h_cscRechitClusterNStation               [selbin]->Fill(cscRechitClusterNStation             [c], ew);
      h_cscRechitClusterNStation10             [selbin]->Fill(cscRechitClusterNStation10           [c], ew);
      h_cscRechitClusterMaxStation             [selbin]->Fill(cscRechitClusterMaxStation           [c], ew);
      h_cscRechitClusterJetVetoPt              [selbin]->Fill(cscRechitClusterJetVetoPt            [c], ew);
    }
    //special case for ABCD method, we only care about NPass(bin 1) and NFail (bin 0)
    if (passCSC) {
      h_cscRechitClusterSize_FailPass[selbin]->Fill(1., ew);
      h_cscRechitClusterSize_FailPass_uw[selbin]->Fill(1., 1.);
    }
    else         {
      h_cscRechitClusterSize_FailPass[selbin]->Fill(0., ew);
      h_cscRechitClusterSize_FailPass_uw[selbin]->Fill(0., 1.);
    }
  }
  if(DtClusterPassSel_all[selbin].size()>0) {
    h_nDTRechits[selbin]->Fill(nDTRechits, ew);
    bool passDT = false;
    for(int i = 0; i < DtClusterPassSel_all[selbin].size(); i++){
      int d = DtClusterPassSel_all[selbin][i];
      double dPhi = -999;
      if(muon_list.size()>0) dPhi = DeltaPhi(lepPhi[muon_list[0]], dtRechitClusterPhi[d]);
      h_dtRechitClusterDPhiLeadMuon                            [selbin]->Fill(dPhi, ew);  
      h_dtRechitCluster_match_RPCBx_dPhi0p5                    [selbin]->Fill(dtRechitCluster_match_RPCBx_dPhi0p5                  [d], ew);  
      h_dtRechitClusterSize                                    [selbin]->Fill(dtRechitClusterSize                                  [d], ew);
      if(dtRechitClusterSize[d]>DtSize)                        passDT = true;
      if(passDT)                                               h_dtRechitClusterDPhiLeadMuon_pass[selbin]->Fill(dPhi, ew);  
      if(!passDT)                                              h_dtRechitClusterDPhiLeadMuon_fail[selbin]->Fill(dPhi, ew);  
      h_dtRechitClusterSize_v                                  [selbin]->Fill(dtRechitClusterSize                                  [d], ew);
      h_dtRechitClusterSize_v2                                 [selbin]->Fill(dtRechitClusterSize                                  [d], ew);
      h_dtRechitClusterEta                                     [selbin]->Fill(dtRechitClusterEta                                   [d], ew);
      h_dtRechitClusterMuonVetoPt                              [selbin]->Fill(dtRechitClusterMuonVetoPt                            [d], ew);
      h_dtRechitClusterPhi                                     [selbin]->Fill(dtRechitClusterPhi                                   [d], ew);
      h_dtRechitCluster_match_RPCTime_dR0p4                    [selbin]->Fill(dtRechitCluster_match_RPCTime_dR0p4                  [d], ew);
      h_dtRechitCluster_match_RPCTimeSpread_dR0p4              [selbin]->Fill(dtRechitCluster_match_RPCTimeSpread_dR0p4            [d], ew);
      h_dtRechitCluster_match_RPChits_dR0p4                    [selbin]->Fill(dtRechitCluster_match_RPChits_dR0p4                  [d], ew);
      h_dtRechitCluster_match_RPCTime_dPhi0p5                  [selbin]->Fill(dtRechitCluster_match_RPCTime_dPhi0p5                [d], ew);
      h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5            [selbin]->Fill(dtRechitCluster_match_RPCTimeSpread_dPhi0p5          [d], ew);
      h_dtRechitCluster_match_RPCTime_sameStation_dR0p4        [selbin]->Fill(dtRechitCluster_match_RPCTime_sameStation_dR0p4      [d], ew);
      h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4  [selbin]->Fill(dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4[d], ew);
      h_dtRechitClusterMaxStation                              [selbin]->Fill(dtRechitClusterMaxStation                            [d], ew);
    }
      //special case for ABCD method, we only care about NPass(bin 1) and NFail (bin 0)
      if (passDT) {
        h_dtRechitClusterSize_FailPass[selbin]->Fill(1., ew);
        h_dtRechitClusterSize_FailPass_uw[selbin]->Fill(1., 1.);
      }
      else        {
        h_dtRechitClusterSize_FailPass[selbin]->Fill(0., ew);
        h_dtRechitClusterSize_FailPass_uw[selbin]->Fill(0., 1.);
      }
  }
}

void analyzer_histograms::WriteHistos(int selbin){
  f_out[selbin]->cd();
  h_nLeptons[selbin]->Write();
  h_gLLP_ctau[selbin]->Write();

  h_nJets[selbin]->Write();
  h_NoMDS_jetCISV[selbin]->Write();
  h_NoMDS_jetPt[selbin]->Write();
  h_NoMDS_jetPt_PassDPhi[selbin]->Write();
  h_NoMDS_jetPt_PassDPhi_inRegion[selbin]->Write();
  h_NoMDS_jetEta[selbin]->Write();
  h_NoMDS_jetDPhiLeadMuon[selbin]->Write();
  h_NoMDS_jetDPhiLeadMuonFine[selbin]->Write();

  h_NoMDS50_100_jetCISV[selbin]->Write();
  h_NoMDS50_100_jetPt[selbin]->Write();
  h_NoMDS50_100_jetEta[selbin]->Write();
  h_NoMDS50_100_jetDPhiLeadMuon[selbin]->Write();
  h_NoMDS50_100_jetDPhiLeadMuonFine[selbin]->Write();

  h_NoMDS100_200_jetCISV[selbin]->Write();
  h_NoMDS100_200_jetPt[selbin]->Write();
  h_NoMDS100_200_jetEta[selbin]->Write();
  h_NoMDS100_200_jetDPhiLeadMuon[selbin]->Write();
  h_NoMDS100_200_jetDPhiLeadMuonFine[selbin]->Write();

  h_NoMDS200_300_jetCISV[selbin]->Write();
  h_NoMDS200_300_jetPt[selbin]->Write();
  h_NoMDS200_300_jetEta[selbin]->Write();
  h_NoMDS200_300_jetDPhiLeadMuon[selbin]->Write();
  h_NoMDS200_300_jetDPhiLeadMuonFine[selbin]->Write();

  h_NoMDS300_jetCISV[selbin]->Write();
  h_NoMDS300_jetPt[selbin]->Write();
  h_NoMDS300_jetEta[selbin]->Write();
  h_NoMDS300_jetDPhiLeadMuon[selbin]->Write();
  h_NoMDS300_jetDPhiLeadMuonFine[selbin]->Write();
  h_NoMDS300_jetDPhiLeadMuonFine2[selbin]->Write();
  h_NoMDS300_jetDPhiLeadMuonFine2_inRegion[selbin]->Write();
  
  h_cscRechitClusterPhivsEta               [selbin]->Write();
  h_cscRechitClusterDPhivsSize             [selbin]->Write();
  h_cscRechitClusterDPhiLeadMuon           [selbin]->Write();
  h_cscRechitClusterDPhiLeadMuon_v2        [selbin]->Write();
  h_cscRechitClusterDPhiLeadMuon_pass      [selbin]->Write();
  h_cscRechitClusterDPhiLeadMuon_fail      [selbin]->Write();
  h_nCscRechits                            [selbin]->Write();
  h_cscRechitClusterSize                   [selbin]->Write();
  h_cscRechitClusterSize_FailPass          [selbin]->Write();
  h_cscRechitClusterSize_FailPass_uw       [selbin]->Write();
  h_cscRechitClusterSize_v                 [selbin]->Write();
  h_cscRechitClusterSize_v2                [selbin]->Write();
  h_cscRechitClusterEta                    [selbin]->Write();
  h_cscRechitClusterEtaZoom                [selbin]->Write();
  h_cscRechitClusterMuonVetoPt             [selbin]->Write();
  h_cscRechitClusterPhi                    [selbin]->Write();
  h_cscRechitClusterTime                   [selbin]->Write();
  h_cscRechitClusterTimeWeighted           [selbin]->Write();
  h_cscRechitClusterTimeTotal              [selbin]->Write();
  h_cscRechitClusterTimeSpread             [selbin]->Write();
  h_cscRechitClusterTimeSpreadWeighted     [selbin]->Write();
  h_cscRechitClusterTimeSpreadWeightedAll  [selbin]->Write();
 
  h_cscRechitClusterZ                      [selbin]->Write();
  h_cscRechitClusterNStation               [selbin]->Write();
  h_cscRechitClusterNStation10             [selbin]->Write();
  h_cscRechitClusterMaxStation             [selbin]->Write();
  h_cscRechitClusterJetVetoPt              [selbin]->Write();

  h_dtRechitClusterDPhiLeadMuon                            [selbin]->Write();
  h_dtRechitClusterDPhiLeadMuon_pass                       [selbin]->Write();
  h_dtRechitClusterDPhiLeadMuon_fail                       [selbin]->Write();
  h_dtRechitCluster_match_RPCBx_dPhi0p5                    [selbin]->Write();
  h_nDTRechits                                             [selbin]->Write();
  h_dtRechitClusterSize                                    [selbin]->Write();
  h_dtRechitClusterSize_FailPass                           [selbin]->Write();
  h_dtRechitClusterSize_FailPass_uw                        [selbin]->Write();
  h_dtRechitClusterSize_v                                  [selbin]->Write();
  h_dtRechitClusterSize_v2                                 [selbin]->Write();
  h_dtRechitClusterEta                                     [selbin]->Write();
  h_dtRechitClusterMuonVetoPt                              [selbin]->Write();
  h_dtRechitClusterPhi                                     [selbin]->Write();
  h_dtRechitCluster_match_RPCTime_dR0p4                    [selbin]->Write();
  h_dtRechitCluster_match_RPCTimeSpread_dR0p4              [selbin]->Write();
  h_dtRechitCluster_match_RPChits_dR0p4                    [selbin]->Write();
  h_dtRechitCluster_match_RPCTime_dPhi0p5                  [selbin]->Write();
  h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5            [selbin]->Write();
  h_dtRechitCluster_match_RPCTime_sameStation_dR0p4        [selbin]->Write();
  h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4  [selbin]->Write();
  h_dtRechitClusterMaxStation                              [selbin]->Write();
}

void analyzer_histograms::DeleteHistos(int selbin){
  f_out[selbin]->cd();
  h_nLeptons[selbin]->Delete();
  h_gLLP_ctau[selbin]->Delete();

  h_nJets[selbin]->Delete();
  h_NoMDS_jetCISV[selbin]->Delete();
  h_NoMDS_jetPt[selbin]->Delete();
  h_NoMDS_jetPt_PassDPhi[selbin]->Delete();
  h_NoMDS_jetPt_PassDPhi_inRegion[selbin]->Delete();
  h_NoMDS_jetEta[selbin]->Delete();
  h_NoMDS_jetDPhiLeadMuon[selbin]->Delete();
  h_NoMDS_jetDPhiLeadMuonFine[selbin]->Delete();

  h_NoMDS50_100_jetCISV[selbin]->Delete();
  h_NoMDS50_100_jetPt[selbin]->Delete();
  h_NoMDS50_100_jetEta[selbin]->Delete();
  h_NoMDS50_100_jetDPhiLeadMuon[selbin]->Delete();
  h_NoMDS50_100_jetDPhiLeadMuonFine[selbin]->Delete();

  h_NoMDS100_200_jetCISV[selbin]->Delete();
  h_NoMDS100_200_jetPt[selbin]->Delete();
  h_NoMDS100_200_jetEta[selbin]->Delete();
  h_NoMDS100_200_jetDPhiLeadMuon[selbin]->Delete();
  h_NoMDS100_200_jetDPhiLeadMuonFine[selbin]->Delete();

  h_NoMDS200_300_jetCISV[selbin]->Delete();
  h_NoMDS200_300_jetPt[selbin]->Delete();
  h_NoMDS200_300_jetEta[selbin]->Delete();
  h_NoMDS200_300_jetDPhiLeadMuon[selbin]->Delete();
  h_NoMDS200_300_jetDPhiLeadMuonFine[selbin]->Delete();

  h_NoMDS300_jetCISV[selbin]->Delete();
  h_NoMDS300_jetPt[selbin]->Delete();
  h_NoMDS300_jetEta[selbin]->Delete();
  h_NoMDS300_jetDPhiLeadMuon[selbin]->Delete();
  h_NoMDS300_jetDPhiLeadMuonFine[selbin]->Delete();
  h_NoMDS300_jetDPhiLeadMuonFine2[selbin]->Delete();
  h_NoMDS300_jetDPhiLeadMuonFine2_inRegion[selbin]->Delete();

  h_cscRechitClusterPhivsEta               [selbin]->Delete();
  h_cscRechitClusterDPhivsSize             [selbin]->Delete();
  h_cscRechitClusterDPhiLeadMuon           [selbin]->Delete();
  h_cscRechitClusterDPhiLeadMuon_v2        [selbin]->Delete();
  h_cscRechitClusterDPhiLeadMuon_pass      [selbin]->Delete();
  h_cscRechitClusterDPhiLeadMuon_fail      [selbin]->Delete();
  h_nCscRechits                            [selbin]->Delete();
  h_cscRechitClusterSize                   [selbin]->Delete();
  h_cscRechitClusterSize_FailPass          [selbin]->Delete();
  h_cscRechitClusterSize_FailPass_uw       [selbin]->Delete();
  h_cscRechitClusterSize_v                 [selbin]->Delete();
  h_cscRechitClusterSize_v2                [selbin]->Delete();
  h_cscRechitClusterEta                    [selbin]->Delete();
  h_cscRechitClusterEtaZoom                [selbin]->Delete();
  h_cscRechitClusterMuonVetoPt             [selbin]->Delete();
  h_cscRechitClusterPhi                    [selbin]->Delete();
  h_cscRechitClusterTime                   [selbin]->Delete();
  h_cscRechitClusterTimeWeighted           [selbin]->Delete();
  h_cscRechitClusterTimeTotal              [selbin]->Delete();
  h_cscRechitClusterTimeSpread             [selbin]->Delete();
  h_cscRechitClusterTimeSpreadWeighted     [selbin]->Delete();
  h_cscRechitClusterTimeSpreadWeightedAll  [selbin]->Delete();

  h_cscRechitClusterZ                      [selbin]->Delete();
  h_cscRechitClusterNStation               [selbin]->Delete();
  h_cscRechitClusterNStation10             [selbin]->Delete();
  h_cscRechitClusterMaxStation             [selbin]->Delete();
  h_cscRechitClusterJetVetoPt              [selbin]->Delete();

  h_dtRechitClusterDPhiLeadMuon                            [selbin]->Delete();
  h_dtRechitClusterDPhiLeadMuon_pass                       [selbin]->Delete();
  h_dtRechitClusterDPhiLeadMuon_fail                       [selbin]->Delete();
  h_dtRechitCluster_match_RPCBx_dPhi0p5                    [selbin]->Delete();
  h_nDTRechits                                             [selbin]->Delete();
  h_dtRechitClusterSize                                    [selbin]->Delete();
  h_dtRechitClusterSize_FailPass                           [selbin]->Delete();
  h_dtRechitClusterSize_FailPass_uw                        [selbin]->Delete();
  h_dtRechitClusterSize_v                                  [selbin]->Delete();
  h_dtRechitClusterSize_v2                                 [selbin]->Delete();
  h_dtRechitClusterEta                                     [selbin]->Delete();
  h_dtRechitClusterMuonVetoPt                              [selbin]->Delete();
  h_dtRechitClusterPhi                                     [selbin]->Delete();
  h_dtRechitCluster_match_RPCTime_dR0p4                    [selbin]->Delete();
  h_dtRechitCluster_match_RPCTimeSpread_dR0p4              [selbin]->Delete();
  h_dtRechitCluster_match_RPChits_dR0p4                    [selbin]->Delete();
  h_dtRechitCluster_match_RPCTime_dPhi0p5                  [selbin]->Delete();
  h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5            [selbin]->Delete();
  h_dtRechitCluster_match_RPCTime_sameStation_dR0p4        [selbin]->Delete();
  h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4  [selbin]->Delete();
  h_dtRechitClusterMaxStation                              [selbin]->Delete();

}
