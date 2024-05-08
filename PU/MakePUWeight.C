#include <iostream>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <ctype.h>
#include "TMath.h"
#include "TGraph.h"
#include "TLegend.h"
#include <typeinfo>
#include <string>
#include <vector>
#include <sstream>


void MakePUWeight(){

TFile* f_data = TFile::Open("ParkingBPH_2018.root"); 
TH1F* h_data = (TH1F*)f_data->Get("pileup")->Clone();


TString prefix="root://cmsxrootd.fnal.gov///store/group/lpclonglived/B-ParkingLLPs/V1p19_9/";
std::cout<<prefix<<"BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300.root"<<std::endl;
TFile* f_sig1 = TFile::Open(prefix+"BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300.root");
TTree* tree1 = (TTree*)f_sig1->Get("MuonSystem");
TH1F* h1 = new TH1F("h1", "Histogram of nPU", 100, 0, 100); 
tree1->Draw("npu>>h1");


h_data->Scale(1./h_data->Integral(0,-1));
h1->Scale(1./h1->Integral(0,-1));

TH1F* h_correction = (TH1F*)h_data->Clone();
h_correction->Divide(h1);


TCanvas *c = new TCanvas("c1", "c1", 800, 600);
//TLegend leg = new TLegend( 0.73, 0.65, 0.93, 0.88, NULL, "brNDC" );
TLegend* leg = new TLegend();

h_data->SetLineColor(kBlack);
h_data->SetStats( 0 );

h_correction->Draw();
c->SaveAs("PUCorrection.pdf");

h_data->Draw();
h1->Draw("sames");
leg->Draw("sames");





leg->AddEntry(h_data, "Data");
leg->AddEntry(h1, "Pi0 Sig1");
c->SaveAs("nPU.pdf");
}

