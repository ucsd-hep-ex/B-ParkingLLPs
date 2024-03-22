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

void Acceptance::Loop(int argc, char* argv[])
{
    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();

    TH1F* h_dr_cscLLP = new TH1F("h_dr_cscLLP",  "h_dr_cscLLP", 100, 0, 1);
    TH1F* h_dr_dtLLP  = new TH1F("h_dr_dtLLP" ,  "h_dr_dtLLP" , 100, 0, 1);
    TH1F* h_gLLP_ctau = new TH1F("h_gLLP_ctau",  "h_gLLP_ctau", 100, 0, 1000);

    Long64_t nbytes = 0, nb = 0;
    float acc_denom = 0, acc_num_csc = 0, acc_num_dt = 0;
    const Int_t n_ctau = 10000;
    const Int_t n_events = 100;
    Double_t ctau_list             [n_ctau] = {};
    Double_t acceptance_vs_ctau_dt [n_ctau] = {};
    Double_t acceptance_vs_ctau_csc[n_ctau] = {};

    for (Int_t ct = 0; ct < n_ctau; ct++) {
    Double_t ctau = ct;
    std::cout<<ct<<std::endl;
    ctau_list[ct] = ctau;
    acceptance_vs_ctau_dt[ct] = 0.0;
    acceptance_vs_ctau_csc[ct] = 0.0;
    for (Long64_t jentry=0; jentry<nentries; jentry++) {
        Long64_t ientry = LoadTree(jentry);
        // std::cout<<jentry<<std::endl;
        // ------------------------------------- CUTS -------------------------------------
        if (ientry > n_events) break;
        nb = fChain->GetEntry(jentry);
        nbytes += nb;

        int length = sizeof(HLTDecision) / sizeof(HLTDecision[0]);
        // std::cout<<ientry<<std::endl;
        // std::cout<<length<<std::endl;
        // if (Acceptance::HLT_cuts() == false) continue;
        // ------------------------------------- CUTS -------------------------------------
        int ctau_mean = extractIntegers(argv[1]);
        
        h_gLLP_ctau->Fill(gLLP_ctau);
        for (int i = 0; i<nCscRechitClusters; i++){
            double csc_dr = dR(gLLP_eta, gLLP_phi, cscRechitClusterPhi[i], cscRechitClusterEta[i]);
            h_dr_cscLLP->Fill(csc_dr);
        }
        for (int i = 0; i<nDtRechitClusters; i++){
            double dt_dr  = dR(gLLP_eta, gLLP_phi,  dtRechitClusterPhi[i],  dtRechitClusterEta[i]);
            h_dr_dtLLP->Fill(dt_dr);
        }
        if (gLLP_dt == 1.0) {
            acc_num_dt = acc_num_dt + 1;
            acceptance_vs_ctau_dt [ct] = acceptance_vs_ctau_dt [ct] + ctau_weight_rescale(ctau_mean, ctau, gLLP_ctau);
            // std::cout<<ctau_weight_rescale(ctau_mean, ctau, gLLP_ctau)<<std::endl;
        }
        if (gLLP_csc == 1.0) {
            acc_num_csc = acc_num_csc + 1;
            acceptance_vs_ctau_csc[ct] = acceptance_vs_ctau_csc[ct] + ctau_weight_rescale(ctau_mean, ctau, gLLP_ctau);
        }
        //bool dt = (gLLP_dt==1);
        //std::cout<<dt<<std::endl;
        acc_denom += 1;
    }
    acceptance_vs_ctau_dt [ct] = acceptance_vs_ctau_dt [ct]; /// acc_num_dt;
    acceptance_vs_ctau_csc[ct] = acceptance_vs_ctau_csc[ct]; /// acc_num_csc;
    std::cout<<ctau_list[ct]<<" , "<<acceptance_vs_ctau_dt[ct]<<" , "<<acceptance_vs_ctau_csc[ct]<<std::endl;
    }
    

    std::cout<<n_ctau<<", "<<sizeof(acceptance_vs_ctau_dt)/sizeof(acceptance_vs_ctau_dt[0])<<", "<<sizeof(acceptance_vs_ctau_csc)/sizeof(acceptance_vs_ctau_csc[0])<<std::endl;
    std::cout<<acc_num_csc<<","<<acc_num_dt<<","<<acc_denom<<std::endl;
    std::cout<<acc_num_csc*100/acc_denom<<","<<acc_num_dt*100/acc_denom<<std::endl;
    
    TCanvas* c1 = new TCanvas( "c", "c", 2119, 33, 1500, 1000 );
    h_dr_cscLLP->Draw();
    c1->SaveAs("h_dr_cscLLP.pdf");
    c1->Close();

    c1          = new TCanvas( "c", "c", 2119, 33, 1500, 1000 );
    h_dr_dtLLP->Draw();
    c1->SaveAs("h_dr_dtLLP.pdf");
    c1->Close();

    c1          = new TCanvas( "c", "c", 2119, 33, 1500, 1000 );
    h_gLLP_ctau->Draw();
    c1->SaveAs("h_gLLP_ctau.pdf");
    c1->Close();

    c1          = new TCanvas( "c", "c", 2119, 33, 1500, 1000 );
    // c1->SetLogy();
    // double ctau_list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example data
    // double acceptance_vs_ctau_csc[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1}; // Example data
    // double acceptance_vs_ctau_dt[10] = {0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0}; // Example data

    // std::cout<<n_ctau<<", "<<ctau_list<<", "<<acceptance_vs_ctau_csc<<std::endl;
    TGraph * acc_csc = new TGraph(n_ctau, ctau_list, acceptance_vs_ctau_csc);
    TGraph * acc_dt  = new TGraph(n_ctau, ctau_list, acceptance_vs_ctau_dt );
    TLegend * l = new TLegend(0.65, 0.7, 0.9, 0.9);
    acc_csc->SetLineColor(2);
    acc_dt->SetLineColor(4);
    acc_csc->SetLineWidth(3);
    acc_dt->SetLineWidth(3);
    acc_csc->Draw();
    acc_dt->Draw("SAME");
    l->AddEntry(acc_csc, "CSC");
    l->AddEntry(acc_dt, "DT");
    l->Draw("SAME");
    c1->SaveAs("acc_vs_ctau.png");
    c1->Close();
    
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
Double_t Acceptance::ctau_weight_rescale(float ct, float ctp, float cti) {
    // std::cout<<ct<<", "<<ctp<<", "<<cti<<std::endl;
    return (ct*exp(-1*cti/ctp)) / (ctp*exp(-1*cti/ct));
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

