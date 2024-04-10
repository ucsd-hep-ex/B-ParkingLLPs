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
    std::string base = "/eos/uscms/store/user/ahayrape/Christina_v9/"; // "/eos/uscms/store/user/ahayrape/BToLLPK_signal_samples/";
    const char * title = split(path, base)[0].c_str();
    std::cout<<title<<std::endl;
    // Long64_t nentries = fChain->GetEntriesFast();
    Long64_t nentries = fChain->GetEntries();

    TH1F* h_dr_cscLLP = new TH1F("h_dr_cscLLP",  "h_dr_cscLLP", 100, 0, 1);
    TH1F* h_dr_dtLLP  = new TH1F("h_dr_dtLLP" ,  "h_dr_dtLLP" , 100, 0, 1);
    TH1F* h_gLLP_ctau = new TH1F("h_gLLP_ctau",  "h_gLLP_ctau", 100, 0, 1000);

    Long64_t nbytes = 0, nb = 0;
    float acc_denom = 0, acc_num_csc = 0, acc_num_dt = 0;
    const Int_t n_ctau = 50;
    const Int_t n_events = 10000;
    const Int_t step = 10000 / n_ctau;
    
    Double_t ctau_list                 [n_ctau] = {0.5011872336272722, 0.6134160033222739, 0.7507756939629209, 0.9188937680019572, 1.1246578221198198, 1.3764977638335685, 1.6847311747385425, 2.0619860095022204, 2.523717948083162, 3.0888435964774805, 3.780515477471076, 4.6270705618430465, 5.663191200210693, 6.931326017507085, 8.48342898244072, 10.383087899535756, 12.708129525529293, 15.553808038632717, 19.03670748843424, 23.29951810515372, 28.516882147934723, 34.90254878959579, 42.7181311649226, 52.28382434830956, 63.99152336349263, 78.32087865456269, 95.85894679172917, 117.3242414777768, 143.59617019622158, 175.7510624854793, 215.1062658744057, 263.27411603701364, 322.2279922591419, 394.3831644306426, 482.6957437677871, 590.7837911587943, 723.0755447967351, 884.9908398088808, 1083.163152428003, 1325.7113655901096, 1622.5723898705216, 1985.9082668407484, 2430.604433384409, 2974.879560266062, 3641.031949310677, 4456.353068194609, 5454.245649277327, 6675.592159647419, 8170.4297069661025, 10000.0};
    Double_t acc_csc_test_values       [n_ctau] = {0.0008064074564464935, 0.0013825857061475167, 0.002254466382783252, 0.003540588733083682, 0.005388162594699997, 0.007959959796754812, 0.011414148432867678, 0.015883263960244823, 0.021458933426819617, 0.02818283871968372, 0.03603572903790532, 0.04491719747287379, 0.05462113006760594, 0.06482244439726297, 0.07508942216807145, 0.08492410495618982, 0.09381959812232897, 0.10131668575053317, 0.10704667863952136, 0.11075777326496823, 0.11232866146849145, 0.11177176367039533, 0.10922456570674209, 0.10492776239980275, 0.09919313720422376, 0.09236761620416888, 0.08480026641186064, 0.07681747292676443, 0.06871042975732149, 0.06073760964631715, 0.053136479590286695, 0.046125629746002414, 0.03988294130786767, 0.034512701231087836, 0.030030056724367496, 0.02637455002965095, 0.02344075251425543, 0.021108323105412895, 0.019262185848347376, 0.0178023234468139, 0.01664645550657553, 0.01572898720223728, 0.014998502190086263, 0.014415009964721079, 0.013947470933858067, 0.01357175905905016, 0.013269058145529148, 0.01302462830336251, 0.012826867379490445, 0.012666599313253138};
    Double_t diff_eff                  [n_ctau] = {};
    Double_t acceptance_vs_ctau_denom  [n_ctau] = {};
    Double_t acceptance_vs_ctau_dt_num [n_ctau] = {};
    Double_t acceptance_vs_ctau_csc_num[n_ctau] = {};
    Double_t acceptance_vs_ctau_dt     [n_ctau] = {};
    Double_t acceptance_vs_ctau_csc    [n_ctau] = {};
    TH1F * ctau_hist     = new TH1F("ctau_hist"    , "ctau_hist"    , 30, 0, 100);
    TH1F * ctau_rew_hist = new TH1F("ctau_rew_hist", "ctau_rew_hist", 30, 0, 100);
    // std::cout<<ctau_reweighter(gLLP_ctau, ctau_mean, ctau)<<std::endl;
    
    for (int ct = 0; ct < n_ctau; ct++) {
        // ctau_list[ct] = 0.1 * pow(2, ct);
        acceptance_vs_ctau_denom[ct] = 0;
        acceptance_vs_ctau_csc_num[ct] = 0;
        acceptance_vs_ctau_dt_num[ct] = 0;
        acceptance_vs_ctau_dt[ct] = 0;
        acceptance_vs_ctau_csc[ct] = 0;
    }
    for (Long64_t jentry=0; jentry<nentries; jentry++) {
        Long64_t ientry = LoadTree(jentry);
        // std::cout<<doesPassHLT()<<std::endl;
        if (jentry %10000 == 0) std::cout<<"Event: "<<jentry<<" -of- "<<nentries<<std::endl;
        // if (ientry >= n_events) break;
        nb = fChain->GetEntry(jentry);
        nbytes += nb;
        int n_muons = 0;
        for (int m = 0; m < sizeof(lepPdgId) / sizeof(lepPdgId[0]); m++) {
            bool HLT_filter = false;
            for (int h = 60; h <= 68; h++) {
                if (lepMuon_passHLTFilter[m][h] == true) {
                    HLT_filter = true;
                }
            }
            if (abs(lepPdgId[m]) == 13 && HLT_filter == true && abs(lepEta[m]) < 1.5 && lepPt[m] > 7 && lepMuonQuality[m] > pow(2, 25)) {
                n_muons++;
            }
        }
        // n_muons == 0
        if(!doesPassHLT() || n_muons == 0) continue;

        int length = sizeof(HLTDecision) / sizeof(HLTDecision[0]);
        int ctau_mean = 100; // extractIntegers(argv[1]) / 10;
        
        ctau_hist     -> Fill(gLLP_ctau);
        ctau_rew_hist -> Fill(gLLP_ctau, ctau_reweighter(gLLP_ctau, ctau_mean, 100));
        
        for (Int_t ct = 0; ct < sizeof(ctau_list) / sizeof(ctau_list[0]); ct++) {
          Double_t ctau = ctau_list[ct];
          if (gLLP_dt == 1.0) {
              acceptance_vs_ctau_dt_num [ct] += ctau_reweighter(gLLP_ctau, ctau_mean, ctau);
          }
          if (gLLP_csc == 1.0) {
              acceptance_vs_ctau_csc_num[ct] += ctau_reweighter(gLLP_ctau, ctau_mean, ctau);
          }
          acceptance_vs_ctau_denom[ct] += ctau_reweighter(gLLP_ctau, ctau_mean, ctau);
        }
    }
    
    // for (int j = 1; j<n_ctau; j++){
    for (int j = 0; j<n_ctau; j++){
      std::cout<<ctau_list[j]<<", "<<acceptance_vs_ctau_dt_num[j] / acceptance_vs_ctau_denom[j]<<", "<<(acceptance_vs_ctau_csc_num[j] / acceptance_vs_ctau_denom[j])<<", "<<abs((acceptance_vs_ctau_csc_num[j] / acceptance_vs_ctau_denom[j]) - acc_csc_test_values[j])<<std::endl;
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
    
    TGraph * acc_csc_test = new TGraph(n_ctau, ctau_list, acc_csc_test_values);
    TGraph * acc_csc = new TGraph(n_ctau, ctau_list, acceptance_vs_ctau_csc);
    TGraph * acc_dt  = new TGraph(n_ctau, ctau_list, acceptance_vs_ctau_dt );
    TLegend * l = new TLegend(0.65, 0.7, 0.9, 0.9);
    acc_csc_test->SetLineColor(1);
    acc_csc->SetLineColor(2);
    acc_dt->SetLineColor(4);
    acc_csc_test->SetLineWidth(3);
    acc_csc->SetLineWidth(3);
    acc_dt->SetLineWidth(3);
    acc_csc_test->GetYaxis()->SetRangeUser(7*1e-4, 1);
    acc_csc->GetYaxis()->SetRangeUser(7*1e-4, 1);
    acc_dt->GetYaxis()->SetRangeUser(7*1e-4, 1);
    acc_csc->SetTitle(title);
    acc_dt->SetTitle(title);
    acc_csc->Draw();
    acc_csc_test->Draw("same");
    acc_dt->Draw("same");
    gPad->SetGridy();
    gPad->SetGridx();
    l->AddEntry(acc_csc, "CSC");
    l->AddEntry(acc_csc_test, "CSC with cuts");
    l->AddEntry(acc_dt, "DT");
    l->Draw("SAME");
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
    if (HLTDecision[t] == 1.0) {doesPass = true; continue;}
  }
  return doesPass;
}

