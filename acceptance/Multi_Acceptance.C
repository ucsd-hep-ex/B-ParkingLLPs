#define Multi_Acceptance_cxx
#include "Multi_Acceptance.h"
#include <iostream>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <ctype.h>
#include "TMath.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TLine.h"
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

void Multi_Acceptance::Loop(int argc, char* argv[])
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
    TH1F* h_gLLP_ctau = new TH1F("h_gLLP_ctau",  "h_gLLP_ctau", 100, 0, 1000);

    Long64_t nbytes = 0, nb = 0;
    float acc_denom = 0, acc_num_csc = 0, acc_num_dt = 0;
    const Int_t n_ctau = 23;
    const Double_t ctau_range_start = 1e-2;
    const Int_t n_events = 10000;
    const Int_t step = 10000 / n_ctau;
    
    // Find the intersection points m = 1.0 GeV
    Float_t gLLP_ctau1, gLLP_ctau2, gLLP_ctau3;
    Double_t ctau_int_1, ctau_int_2;
    
    TFile * file1 = TFile::Open("/eos/uscms/store/user/ahayrape/BToLLPK_signal_samples/BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau300.root");
    TFile * file2 = TFile::Open("/eos/uscms/store/user/ahayrape/BToLLPK_signal_samples/BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000.root");
    TFile * file3 = TFile::Open("/eos/uscms/store/user/ahayrape/BToLLPK_signal_samples/BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau10000.root");
    
    TTree * tree1 = file1->Get<TTree>("MuonSystem");
    TTree * tree2 = file2->Get<TTree>("MuonSystem");
    TTree * tree3 = file3->Get<TTree>("MuonSystem");
    
    tree1->SetBranchAddress("gLLP_ctau", &gLLP_ctau1);
    tree2->SetBranchAddress("gLLP_ctau", &gLLP_ctau2);
    tree3->SetBranchAddress("gLLP_ctau", &gLLP_ctau3);
    
    TH1F * ctau_hist_1 = new TH1F("ctau_hist_1", "ctau_hist_1", 50, 0, 400);
    TH1F * ctau_hist_2 = new TH1F("ctau_hist_2", "ctau_hist_2", 50, 0, 400);
    TH1F * ctau_hist_3 = new TH1F("ctau_hist_3", "ctau_hist_3", 50, 0, 400);
    
    for (Long64_t jentry=0; jentry<tree1->GetEntries(); jentry++) {
        tree1->GetEntry(jentry);
        ctau_hist_1->Fill(gLLP_ctau1);
    }
    
    for (Long64_t jentry=0; jentry<tree2->GetEntries(); jentry++) {
        tree2->GetEntry(jentry);
        ctau_hist_2->Fill(gLLP_ctau2);
    }
    
    for (Long64_t jentry=0; jentry<tree3->GetEntries(); jentry++) {
        tree3->GetEntry(jentry);
        ctau_hist_3->Fill(gLLP_ctau3);
    }
    
    TCanvas* c_ctaus = new TCanvas( "ctau", "ctau", 2119, 33, 1500, 1000 );
    TLegend * legend = new TLegend(0.65, 0.7, 0.9, 0.9);
    ctau_hist_1->SetLineColor(4);
    ctau_hist_1->SetLineWidth(3);
    ctau_hist_2->SetLineColor(2);
    ctau_hist_2->SetLineWidth(3);
    ctau_hist_3->SetLineColor(6);
    ctau_hist_3->SetLineWidth(3);
    ctau_hist_1->Draw();
    ctau_hist_2->Draw("SAME");
    ctau_hist_3->Draw("SAME");
    legend->AddEntry(ctau_hist_1, "c#tau 30 cm");
    legend->AddEntry(ctau_hist_2, "c#tau 100 cm");
    legend->AddEntry(ctau_hist_3, "c#tau 1000 cm");
    legend->Draw("SAME");
    
    // Finding intersection between sample 1 and sample 3.
    const int n_bins = ctau_hist_1->GetNbinsX();
    Double_t dy[n_bins] = {};
    Double_t min_dy = 1000000;
    Double_t min_ctau = 0;
    int min_index = 0;
    for (int bin = 1; bin <= n_bins; bin++) {
        dy[bin] = abs(ctau_hist_1->GetBinContent(bin) - ctau_hist_3->GetBinContent(bin));
        if (min_dy > dy[bin]) {
            min_dy = dy[bin];
            min_ctau = ctau_hist_1->GetXaxis()->GetBinCenter(bin); // (ctau_hist_1->GetBinContent(bin) + ctau_hist_3->GetBinContent(bin)) / 2;
            min_index = bin;
        }
    }
    TLine *line = new TLine(min_ctau,0,min_ctau, 200000);
    line->SetLineColor(kRed);
    line->SetLineWidth(3);
    line->Draw();
    c_ctaus->Update();
    c_ctaus->SaveAs("ctau_hitsograms.png");
    c_ctaus->Close();

    int l1 = 0;
    int l2 = 0;
    for (int ct = 1; ct <= n_ctau; ct++) {
        Double_t ctau_value = ctau_range_start * pow(2, ct);
        if (ctau_value <= min_ctau) {
            l1++;
        } else {
            l2++;
        }
    }
    
    Double_t ctau_list[n_ctau] = {};
    Double_t ctau_list_1[l1] = {};
    Double_t ctau_list_2[l2] = {};
    int ct_1 = 0;
    int ct_2 = 0;
    for (int ct = 0; ct < n_ctau; ct++) {
        Double_t ctau_value = ctau_range_start * pow(2, ct);
        ctau_list[ct] = ctau_value;
        // ctau_list_1[ct] = 0.1 * pow(2, ct);
        // ctau_list_2[ct] = 0.1 * pow(2, ct);
        if (ctau_value <= min_ctau) {
            ctau_list_1[ct_1] = ctau_value;
            ct_1++;
        } else {
            std::cout<<ctau_value<<std::endl;
            ctau_list_2[ct_2] = ctau_value;
            ct_2++;
        }
    }
    
    std::cout<<"The intersection point between 300 and 1000: "<<min_dy<<", bin index: "<<min_index<<std::endl;
    Double_t acceptance_vs_ctau_denom  [n_ctau] = {};
    Double_t acceptance_vs_ctau_dt_num [n_ctau] = {};
    Double_t acceptance_vs_ctau_csc_num[n_ctau] = {};
    Double_t acceptance_vs_ctau_dt     [n_ctau] = {};
    Double_t acceptance_vs_ctau_csc    [n_ctau] = {};
    TH1F * ctau_hist     = new TH1F("ctau_hist"    , "ctau_hist"    , n_bins, 0, 400);
    TH1F * ctau_rew_hist = new TH1F("ctau_rew_hist", "ctau_rew_hist", n_bins, 0, 400);
    std::cout<<"Make histograms"<<std::endl;
    
    for (int ct = 0; ct < n_ctau; ct++) {
        acceptance_vs_ctau_denom[ct] = 0;
        acceptance_vs_ctau_csc_num[ct] = 0;
        acceptance_vs_ctau_dt_num[ct] = 0;
        acceptance_vs_ctau_dt[ct] = 0;
        acceptance_vs_ctau_csc[ct] = 0;
    }
    
    // Reweighting the middle ctau sample: ctau = 1000mm. Sample 1 = file 1, Sample 2 = file 3.
    // std::cout<<min_ctau<<std::endl;
    // std::cout<<sizeof(ctau_list_1) / sizeof(ctau_list_1[0]) + sizeof(ctau_list_2) / sizeof(ctau_list_2[0])<<std::endl<<std::endl;
    for (Long64_t jentry=0; jentry<nentries; jentry++) {
        Long64_t ientry = LoadTree(jentry);
        // std::cout<<doesPassHLT()<<std::endl;
        // if(!doesPassHLT()) continue;
        if (jentry %10000 == 0) std::cout<<"Event: "<<jentry<<" -of- "<<nentries<<std::endl;
        if (ientry >= n_events) break;
        nb = fChain->GetEntry(jentry);
        nbytes += nb;

        int length = sizeof(HLTDecision) / sizeof(HLTDecision[0]);
        // std::cout<<sizeof(ctau_list_1) / sizeof(ctau_list_1[0]) + sizeof(ctau_list_2) / sizeof(ctau_list_2[0])<<std::endl;
        // std::cout<<sizeof(acceptance_vs_ctau_dt_num) / sizeof(acceptance_vs_ctau_dt_num[0])<<std::endl<<std::endl;
        Double_t weight = 0.0;
        // int (sizeof(ctau_list_1) / sizeof(ctau_list_1[0])) + (sizeof(ctau_list_2) / sizeof(ctau_list_2[0]));
        if (gLLP_ctau <= min_ctau) {
            int ctau_mean = ctau_hist_1->GetMean(); // extractIntegers(argv[1]) / 10;
            for (Int_t ct = 0; ct <= sizeof(ctau_list_1) / sizeof(ctau_list_1[0]); ct++) {
              weight = ctau_reweighter(gLLP_ctau, ctau_mean, ctau_list_1[ct]);
              Double_t ctau = ctau_list_1[ct];
              if (gLLP_dt == 1.0) {
                  acceptance_vs_ctau_dt_num [ct] += weight;
              }
              if (gLLP_csc == 1.0) {
                  acceptance_vs_ctau_csc_num[ct] += weight;
              }
              acceptance_vs_ctau_denom[ct] += weight;
            }
        }
        else if (gLLP_ctau > min_ctau) {
            int ctau_mean = ctau_hist_3->GetMean(); // extractIntegers(argv[1]) / 10;
            // std::cout<<"Large ctau mean: "<<ctau_mean<<std::endl;
            for (Int_t ct = 0; ct <= sizeof(ctau_list_2) / sizeof(ctau_list_2[0]); ct++) {
            // for (Int_t ct = sizeof(ctau_list_1) / sizeof(ctau_list_1[0]); ct < (sizeof(ctau_list_1) / sizeof(ctau_list_1[0])) + (sizeof(ctau_list_2) / sizeof(ctau_list_2[0])); ct++) {
              weight = ctau_reweighter(gLLP_ctau, ctau_mean, ctau_list_2[ct]);
              if (abs(ctau_list_2[ct] - 163.84) < 5) {
                  std::cout<<gLLP_ctau<<", "<<weight<<", "<<std::endl;
              }
              // ct = ct + sizeof(ctau_list_1) / sizeof(ctau_list_1[0]);
              Double_t ctau = ctau_list_2[ct];
              if (gLLP_dt == 1.0) {
                  acceptance_vs_ctau_dt_num [(ct + (sizeof(ctau_list_1) / sizeof(ctau_list_1[0])))] += weight;
              }
              if (gLLP_csc == 1.0) {
                  acceptance_vs_ctau_csc_num[(ct + (sizeof(ctau_list_1) / sizeof(ctau_list_1[0])))] += weight;
              }
              acceptance_vs_ctau_denom[(ct + (sizeof(ctau_list_1) / sizeof(ctau_list_1[0])))] += weight; 
            }
        }
        ctau_hist     -> Fill(gLLP_ctau);
        ctau_rew_hist -> Fill(gLLP_ctau, weight);
    }
    
    std::cout<<"Fill histograms"<<std::endl;

    // for (int j = 1; j<n_ctau; j++){
    for (int j = 0; j<n_ctau; j++) {
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
    TLegend * l = new TLegend(0.75, 0.8, 1.0, 1.0);
    acc_csc->SetLineColor(2);
    acc_dt->SetLineColor(4);
    acc_csc->SetLineWidth(5);
    acc_dt->SetLineWidth(3);
    acc_csc->GetYaxis()->SetRangeUser(1e-6, 20);
    acc_dt->GetYaxis()->SetRangeUser(1e-6, 20);
    // acc_csc->SetTitle(title);
    // acc_dt->SetTitle(title);
    acc_csc->Draw();
    acc_dt->Draw("SAME");
    l->AddEntry(acc_csc, "CSC");
    l->AddEntry(acc_dt, "DT");
    l->Draw("SAME");
    c2->SaveAs("acc_vs_ctau.png");
    c2->Close();
    
    TCanvas* c = new TCanvas( "ctau_before_after", "ctau_before_after", 2119, 33, 1500, 1000 );
    l = new TLegend(0.7, 0.75, 0.9, 0.9);
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

    std::cout<<"Plotting histograms"<<std::endl;

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
double Multi_Acceptance::dR(double eta1, double phi1, double eta2, double phi2)
{
  double deltaeta = abs(eta1 - eta2);
  double deltaphi = DeltaPhi(phi1, phi2);
  double deltar = sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
  return deltar;
}

//-------------------------DeltaPhi
double Multi_Acceptance::DeltaPhi(double phi1, double phi2)
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
Double_t Multi_Acceptance::ctau_weight_rescale(Double_t ct, Double_t ctp, Double_t cti) {
    Double_t output = 0.0;
    if (ctp == 0) {
        output = 0.0;
    } else {
        output = (ct / ctp) * (exp(-1*cti/ctp) / exp(-1*cti/ct));
    }
    return output;
}

// ------------------------- Defining cuts
bool Multi_Acceptance::HLT_cuts() {
    int length = sizeof(HLTDecision) / sizeof(HLTDecision[0]);
    for (int i = 0; i < length; i++) {
        if ((HLTDecision[i] == true) && (i > 1157) && (i < 1197)) {
            return true;
        }
    }
    return false;
}

bool Multi_Acceptance::doesPassHLT() {
  bool doesPass = false;
  for (int t= 1157; t <= 1197; t++){
    // if (HLTDecision[t]) {std::cout<<HLTDecision[t]<<std::endl;}
    // std::cout<<HLTDecision[t]<<std::endl;
    if (HLTDecision[t]) {doesPass = true; continue;}
  }
  return doesPass;
}

