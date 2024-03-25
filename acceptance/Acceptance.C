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
#include <string>
#include <vector>
#include <sstream>

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

std::vector<std::string> split(const std::string& s, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    size_t found;
    while ((found = s.find(delimiter, pos)) != std::string::npos) {
        tokens.push_back(s.substr(pos, found - pos));
        pos = found + delimiter.length();
    }
    tokens.push_back(s.substr(pos));
    return tokens;
}

void Acceptance::Loop(int argc, char* argv[])
{
    if (fChain == 0) return;
    std::string path = argv[1];
    std::string base = "/eos/uscms/store/user/ahayrape/BToLLPK_signal_samples/";
    const char * title = split(path, base)[0].c_str();
    std::cout<<title<<std::endl;
    // Long64_t nentries = fChain->GetEntriesFast();
    Long64_t nentries = fChain->GetEntries();

    TH1F* h_dr_cscLLP = new TH1F("h_dr_cscLLP",  "h_dr_cscLLP", 100, 0, 1);
    TH1F* h_dr_dtLLP  = new TH1F("h_dr_dtLLP" ,  "h_dr_dtLLP" , 100, 0, 1);


    Long64_t nbytes = 0, nb = 0;
    float acc_denom = 0, acc_num_csc = 0, acc_num_dt = 0;
    const Int_t n_ctau = 17;
    const Int_t n_events = 10000;
    const Int_t step = 10000 / n_ctau;
    
    Double_t ctau_list                 [n_ctau] = {};
    Double_t acceptance_vs_ctau_denom  [n_ctau] = {};
    Double_t acceptance_vs_ctau_dt_num [n_ctau] = {};
    Double_t acceptance_vs_ctau_csc_num[n_ctau] = {};
    Double_t acceptance_vs_ctau_dt     [n_ctau] = {};
    Double_t acceptance_vs_ctau_csc    [n_ctau] = {};
    TH1F * ctau_hist     = new TH1F("ctau_hist"    , "ctau_hist"    , 30, 0, 100);
    TH1F * ctau_rew_hist = new TH1F("ctau_rew_hist", "ctau_rew_hist", 30, 0, 100);

    TH1F* h_gLLP_ctau = new TH1F("h_gLLP_ctau",  "h_gLLP_ctau", 100, 0, 1000);
    TH1F* h_gLLP_ctau_300 = new TH1F("h_gLLP_ctau_300",  "h_gLLP_ctau_300", 100, 0, 1000);
    TH1F* h_gLLP_ctau_1000 = new TH1F("h_gLLP_ctau_1000",  "h_gLLP_ctau_1000", 100, 0, 1000);

    // std::cout<<ctau_reweighter(gLLP_ctau, ctau_mean, ctau)<<std::endl;
    
    for (int ct = 0; ct < n_ctau; ct++) {
        ctau_list[ct] = 0.1 * pow(2, ct);
        acceptance_vs_ctau_denom[ct] = 0;
        acceptance_vs_ctau_csc_num[ct] = 0;
        acceptance_vs_ctau_dt_num[ct] = 0;
        acceptance_vs_ctau_dt[ct] = 0;
        acceptance_vs_ctau_csc[ct] = 0;
    }
    for (Long64_t jentry=0; jentry<nentries; jentry++) {
        Long64_t ientry = LoadTree(jentry);
        // std::cout<<doesPassHLT()<<std::endl;
        // if(!doesPassHLT()) continue;
        if (jentry %10000 == 0) std::cout<<"Event: "<<jentry<<" -of- "<<nentries<<std::endl;
        if (ientry >= n_events) break;
        nb = fChain->GetEntry(jentry);
        nbytes += nb;

        int length = sizeof(HLTDecision) / sizeof(HLTDecision[0]);
        int ctau_mean = extractIntegers(argv[1]) / 10;
        h_gLLP_ctau ->Fill(gLLP_ctau);
        h_gLLP_ctau_300 ->Fill(gLLP_ctau, ctau_reweighter(gLLP_ctau, ctau_mean, 30.));
        h_gLLP_ctau_1000 ->Fill(gLLP_ctau, ctau_reweighter(gLLP_ctau, ctau_mean, 100.));
        std::cout<<gLLP_ctau<<", "<<ctau_mean<<", "<<ctau_reweighter(gLLP_ctau, ctau_mean*10, 100)<<std::endl;
        
        ctau_hist     -> Fill(gLLP_ctau);
        ctau_rew_hist -> Fill(gLLP_ctau, ctau_reweighter(gLLP_ctau, ctau_mean, 100));
        
        // for (Int_t ct = 1; ct < n_ctau; ct++) {
        for (Int_t ct = 0; ct < sizeof(ctau_list) / sizeof(ctau_list[0]); ct++) {
          // Double_t ctau = 10 * ct;
          Double_t ctau = ctau_list[ct];
          // ctau_list[ct] = ctau;
          // std::cout<<gLLP_ctau<<std::endl;
          // std::cout<<(gLLP_dt==1.0)<<", "<<(gLLP_csc==1.0)<<std::endl;
          if (gLLP_dt == 1.0) {
              acceptance_vs_ctau_dt_num [ct] += ctau_reweighter(gLLP_ctau, ctau_mean, ctau);
              // if (ctau_mean == 300) {
              // std::cout<<ctau_reweighter(gLLP_ctau, ctau_mean, ctau)<<std::endl;
              // }
          }
          if (gLLP_csc == 1.0) {
              acceptance_vs_ctau_csc_num[ct] += ctau_reweighter(gLLP_ctau, ctau_mean, ctau);
              // if (ctau_mean == 300) {
              // std::cout<<ctau_reweighter(gLLP_ctau, ctau_mean, ctau)<<std::endl;
              // }
          }
          // std::cout<<std::endl;
          acceptance_vs_ctau_denom[ct] += ctau_reweighter(gLLP_ctau, ctau_mean, ctau);
        }
    }
    
    // for (int j = 1; j<n_ctau; j++){
    for (int j = 0; j<n_ctau; j++){
      std::cout<<ctau_list[j]<<", "<<acceptance_vs_ctau_dt_num[j] / acceptance_vs_ctau_denom[j]<<", "<<acceptance_vs_ctau_csc_num[j] / acceptance_vs_ctau_denom[j]<<std::endl;
      if (acceptance_vs_ctau_denom[j] > 0){
        acceptance_vs_ctau_dt [j] = acceptance_vs_ctau_dt_num [j]/acceptance_vs_ctau_denom[j];
        acceptance_vs_ctau_csc[j] = acceptance_vs_ctau_csc_num[j]/acceptance_vs_ctau_denom[j];
      }
      else {
        acceptance_vs_ctau_dt [j] = 0;
        acceptance_vs_ctau_csc[j] = 0;
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
    acc_csc->GetYaxis()->SetRangeUser(1e-6, 1);
    acc_dt->GetYaxis()->SetRangeUser(1e-6, 1);
    acc_csc->SetTitle(title);
    acc_dt->SetTitle(title);
    acc_csc->Draw();
    acc_dt->Draw("same");
    l->AddEntry(acc_csc, "CSC");
    l->AddEntry(acc_dt, "DT");
    // l->Draw("SAME");
    c2->SaveAs("acc_vs_ctau.png");
    c2->Close();
    
    TCanvas* c = new TCanvas( "ctau_before_after", "ctau_before_after", 2119, 33, 1500, 1000 );
    l = new TLegend(0.65, 0.7, 0.9, 0.9);
    ctau_hist->SetLineColor(4);
    ctau_hist->SetLineWidth(3);
    ctau_rew_hist->SetLineColor(2);
    ctau_rew_hist->SetLineWidth(5);
    ctau_hist->Draw();
    ctau_rew_hist->Draw("SAME");
    l->AddEntry(ctau_hist, "Before");
    l->AddEntry(ctau_rew_hist, "After");
    l->Draw("SAME");
    c->SaveAs("ctau_before_after.png");
    c->Close();
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
    TCanvas* c3 = new TCanvas( "c3", "c3", 2119, 33, 1500, 1000 );
    c3->SetLogy();
    //c2->SetLogx();
    h_gLLP_ctau->SetLineColor(kRed);
    h_gLLP_ctau_300->SetLineColor(kBlack);
    h_gLLP_ctau_1000->SetLineColor(kBlue);

    h_gLLP_ctau->Scale(1./h_gLLP_ctau->Integral(0,-1));
    h_gLLP_ctau_300->Scale(1./h_gLLP_ctau_300->Integral(0,-1));
    h_gLLP_ctau_1000->Scale(1./h_gLLP_ctau_1000->Integral(0,-1));
 
    h_gLLP_ctau->Draw("hist");
    h_gLLP_ctau_300->Draw("hist same");
    h_gLLP_ctau_1000->Draw("hist same");

    TString s_gLLP_ctau = Form("%s: Orig Mean = %.2f", h_gLLP_ctau->GetName(), h_gLLP_ctau->GetMean());
    TString s_gLLP_ctau_300  = Form("%s: ReW30 Mean = %.2f", h_gLLP_ctau_300->GetName(), h_gLLP_ctau_300->GetMean());
    TString s_gLLP_ctau_1000 = Form("%s: ReW100 Mean = %.2f", h_gLLP_ctau_1000->GetName(), h_gLLP_ctau_1000->GetMean());

    TLegend * l3 = new TLegend(0.65, 0.7, 0.9, 0.9);
    l3->AddEntry(h_gLLP_ctau,s_gLLP_ctau );
    l3->AddEntry(h_gLLP_ctau_300, s_gLLP_ctau_300);
    l3->AddEntry(h_gLLP_ctau_1000, s_gLLP_ctau_1000);
    l3->Draw("SAME");

    c3->SaveAs("reweight.png");
    c3->Close();
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
    // if (HLTDecision[t]) {std::cout<<HLTDecision[t]<<std::endl;}
    // std::cout<<HLTDecision[t]<<std::endl;
    if (HLTDecision[t]) {doesPass = true; continue;}
  }
  return doesPass;
}

