#define Acceptance_cxx
#include "Acceptance.h"
#include <iostream>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <ctype.h>
#include "TMath.h"
#include "TGraph.h"
#include "TLegend.h"
#include <typeinfo>

int extractIntegers(const char *str) {
    const char *ptr = str;
    int num;
    bool found_trigger = false;
    while (*ptr) {
        if (ptr == "c") found_trigger = true;
        if (found_trigger) continue;
        if (isdigit(*ptr)) {
            // If the current character is a digit, start extracting the integer
            num = atoi(ptr);
            while (isdigit(*ptr))
                ptr++; // reference ++ means move to the next element
        } else {
            // Move to the next character
            ptr++; // reference ++ means move to the next element
        }
    }
    // printf("%d\n", num);
    return num;
}

Double_t find_max(Double_t array[]) {
    Double_t maximum = array[0];
    Int_t size = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < size; i++) {
        if (maximum < array[i]) {
            maximum = array[i];
        }
    }
    return maximum;
}


Float_t ctau_reweighter(Float_t t, Float_t tau0, Float_t tau1) {
    Float_t numerator = (1.0f / tau1) * expf(-t / tau1);
    Float_t denominator = (1.0f / tau0) * expf(-t / tau0);

    return numerator / denominator;
}

Double_t find_min(Double_t array[]) {
    Double_t minimum = array[0];
    Int_t size = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < size; i++) {
        if (minimum > array[i]) {
            minimum = array[i];
        }
    }
    return minimum;
}

void Acceptance::Loop(int argc, char* argv[])
{
    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();

    TH1F* h_dr_cscLLP = new TH1F("h_dr_cscLLP",  "h_dr_cscLLP", 100, 0, 1);
    TH1F* h_dr_dtLLP  = new TH1F("h_dr_dtLLP" ,  "h_dr_dtLLP" , 100, 0, 1);
    TH1F* h_gLLP_ctau = new TH1F("h_gLLP_ctau",  "h_gLLP_ctau", 100, 0, 1000);

    Long64_t nbytes = 0, nb = 0;
    float acc_denom = 0, acc_num_csc = 0, acc_num_dt = 0;
    const Int_t n_ctau = 1000;
    const Int_t n_events = 10000;
    Double_t ctau_list             [n_ctau] = {1, 10, 100, 1000, 10000};
    Double_t acceptance_vs_ctau_denom [n_ctau] = {};
    Double_t acceptance_vs_ctau_dt_num [n_ctau] = {};
    Double_t acceptance_vs_ctau_csc_num[n_ctau] = {};
    Double_t acceptance_vs_ctau_dt [n_ctau] = {};
    Double_t acceptance_vs_ctau_csc[n_ctau] = {};

    for (Long64_t jentry=0; jentry<nentries; jentry++) {
        Long64_t ientry = LoadTree(jentry);
        //if(!doesPassHLT()) continue;
        if (jentry %10000 == 0) std::cout<<"Event: "<<jentry<<" -of- "<<nentries<<std::endl;
        if (ientry >= n_events) break;
        nb = fChain->GetEntry(jentry);
        nbytes += nb;

        int length = sizeof(HLTDecision) / sizeof(HLTDecision[0]);
        int ctau_mean = extractIntegers(argv[1]) / 10;
     
        for (Int_t ct = 1; ct < n_ctau; ct++) {
          Double_t ctau = 10 * ct;
          ctau_list[ct] = ctau;
        
          if (gLLP_dt == 1.0) {
              acceptance_vs_ctau_dt_num [ct] += ctau_reweighter(gLLP_ctau, ctau_mean, ctau);
          }
          if (gLLP_csc == 1.0) {
              acceptance_vs_ctau_csc_num[ct] += ctau_reweighter(gLLP_ctau, ctau_mean, ctau);
          }
          acceptance_vs_ctau_denom[ct] += ctau_reweighter(gLLP_ctau, ctau_mean, ctau);
        }
    }
    for (int j = 1; j<n_ctau; j++){
      if (acceptance_vs_ctau_denom[j] > 0){
        acceptance_vs_ctau_dt [j]  = acceptance_vs_ctau_dt_num[j] /acceptance_vs_ctau_denom[j]; 
        acceptance_vs_ctau_csc [j] = acceptance_vs_ctau_csc_num[j]/acceptance_vs_ctau_denom[j];
      }
      else {
        acceptance_vs_ctau_dt [j]  = 0;
        acceptance_vs_ctau_csc [j] = 0; 
      }
    }
    TCanvas* c2 = new TCanvas( "c2", "c2", 2119, 33, 1500, 1000 );
    c2->SetLogy();
    c2->SetLogx();
    
    TGraph * acc_csc = new TGraph(n_ctau, ctau_list, acceptance_vs_ctau_csc);
    TGraph * acc_dt  = new TGraph(n_ctau, ctau_list, acceptance_vs_ctau_dt );
    TLegend * l = new TLegend(0.65, 0.7, 0.9, 0.9);
    acc_csc->SetLineColor(2);
    acc_dt->SetLineColor(4);
    acc_csc->SetLineWidth(5);
    acc_dt->SetLineWidth(3);
    acc_csc->GetYaxis()->SetRangeUser(1e-3, 1);
    acc_dt->GetYaxis()->SetRangeUser(1e-3, 1);
    acc_csc->Draw();
    acc_dt->Draw("same");
    l->AddEntry(acc_csc, "CSC");
    l->AddEntry(acc_dt, "DT");
    l->Draw("SAME");
    c2->SaveAs("acc_vs_ctau.png");
    c2->Close();
    
    /*
    c1          = new TCanvas( "c", "c", 2119, 33, 800, 700 );
    double x[100], y[100];
    int n = 20;
    for (int i=0;i<n;i++) {
      x[i] = i*0.1;
      y[i] = 10*sin(x[i]+0.2);
    }
    auto g = new TGraph(n,x,y);
    g->SetTitle("Graph title;X title;Y title");
    g->Draw("AC*");
    c1->SaveAs("example.png");
    c1->Close();
    */
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

// ------------------------- Reweighting
Double_t Acceptance::ctau_weight_rescale(Double_t ct, Double_t ctp, Double_t cti) {
    Double_t output = 0.0;
    if (ctp == 0) {
        output = 0.0;
    } else {
        output = (ct / ctp) * (exp(-1*cti/ctp) / exp(-1*cti/ct));
    }
    return output;
}
// ------------------------- Defining cuts
bool Acceptance::HLT_cuts()
{
    int length = sizeof(HLTDecision) / sizeof(HLTDecision[0]);
    for (int i = 0; i < length; i++) {
        if ((HLTDecision[i] == true) && (i > 1157) && (i < 1197)) {
            return true;
        }
    }
    return false;
}
bool Acceptance::doesPassHLT(){
  bool doesPass = false;
  for (int t= 1157; t <= 1197; t++){
    if (HLTDecision[t]) {doesPass = true; continue;}
  }
  return doesPass;
}


