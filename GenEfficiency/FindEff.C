/*
// Use example
// root -l -b -q 'FindEff.C("/store/group/lpclonglived/B-ParkingLLPs//V1p19_9/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi0p3_ctau3000/BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi0p3_ctau3000.root", 3000)'
// First argument the file name, second argument is the lifetime target for re-weighting
*/

#include <iostream>
#include <algorithm>
#include "TFile.h"
#include "TH1F.h"
#include "TTree.h"
#include "TCanvas.h"

bool earlyStop = false;
int NStop = 100;

TString ExtractFileName(const TString& fullPath) {
    // Find the last '/' in the path
    Ssiz_t lastSlashPos = fullPath.Last('/');

    // Extract everything after the last '/'
    TString fileNameWithExtension = fullPath(lastSlashPos + 1, fullPath.Length() - lastSlashPos - 1);

    // Now, remove the ".root" extension; assuming it ends with ".root"
    TString fileName = fileNameWithExtension;
    if (fileName.EndsWith(".root")) {
        fileName.Resize(fileName.Length() - 5); // Remove the last 5 characters (".root")
    }

    return fileName;
}


Float_t ctau_weight(Float_t t, Float_t tau0, Float_t tau1) {
    Float_t numerator = (1.0f / tau1) * expf(-t / tau1);
    Float_t denominator = (1.0f / tau0) * expf(-t / tau0);

    return numerator / denominator;
}

//Let's assume Si's code is in mm 
bool PassFilter(float r, float z, float eta){
    bool doesPass = false;
    //  Original version (mm?)
    //if( !( fabs(z)<4000 && r <2000 ) && fabs(z) < 12000 && r < 8000 && fabs(eta) < 4.0 ) doesPass = true;
    //  Assuming we need to divide by 10 for cm
    if( !( fabs(z)<400 && r <200 ) && fabs(z) < 1200 && r < 800 && fabs(eta) < 4.0 ) doesPass = true;
    return doesPass;
}



float CalcEff(TString s_f_genOnly, float tau0, float tauPrime ){

    //TString s_f_genOnly = "BToKPhi_MuonGenFilter_PhiToPiPlusPiMinus_GenOnly_mPhi0p3_ctau3000.root"; 

    TFile* f_genOnly = TFile::Open("root://cmsxrootd.fnal.gov//"+s_f_genOnly);

    if (!f_genOnly || f_genOnly->IsZombie()) {
        std::cerr << "Error opening f_genOnly" << std::endl;
        return 0;
    }

    // Get the TTree from the file
    TTree *tree_genOnly = nullptr;
    f_genOnly->GetObject("MuonSystem", tree_genOnly);
    if (!tree_genOnly) {
        std::cerr << "Error retrieving MuonSystem TTree tree_genOnly" << std::endl;
        f_genOnly->Close();
        0;
    }

    // set your binning
    //TH1F *h_gLLP_ctau  = new TH1F("h_gLLP_ctau" , "h_gLLP_ctau" , 100, 0, 500);
    

    // Set branch address
    float gLLP_r_genOnly, gLLP_z_genOnly, gLLP_eta_genOnly, gLLP_ctau_genOnly, ew;
    float Num = 0.0;
    float Den = 0.0;
    
    tree_genOnly->SetBranchAddress("gLLP_decay_vertex_r", &gLLP_r_genOnly);
    tree_genOnly->SetBranchAddress("gLLP_decay_vertex_z", &gLLP_z_genOnly);
    tree_genOnly->SetBranchAddress("gLLP_eta", &gLLP_eta_genOnly);
    tree_genOnly->SetBranchAddress("gLLP_ctau", &gLLP_ctau_genOnly);
 
    Long64_t nEntries_genOnly; 
    if(earlyStop) nEntries_genOnly  = NStop;
    else          nEntries_genOnly  = tree_genOnly->GetEntries(); 
    for (Long64_t i = 0; i < nEntries_genOnly; i++) {
        tree_genOnly->GetEntry(i);
        //h_gLLP_ctau->Fill(gLLP_ctau_genOnly);   
        ew = ctau_weight(gLLP_ctau_genOnly*10., tau0, tauPrime); 
        Den+=ew;
        if( PassFilter(gLLP_r_genOnly, gLLP_z_genOnly, gLLP_eta_genOnly) ) Num+=ew; 
    }
//    TCanvas *c = new TCanvas("c1", "c1", 800, 600);
//    h_gLLP_ctau->Draw();
//    c->SaveAs("ctau.png");
//    c->Close();
    // Close the ROOT file
    f_genOnly->Close();
//    TFile* f_out = new TFile("FindEff.root", "recreate");
//    h_gLLP_ctau->Write();
//    f_out->Close();
    TString fileName = ExtractFileName(s_f_genOnly);
    std::cout<<"Sample: "<<fileName<<"   ctauPrime: "<< tauPrime<<"  Eff = "<<Num<<"/"<<Den<<" = "<<Num/Den<<std::endl; 
    return Num/Den; 
}

void FindEff(TString s_f_genOnly, float tauPrime){
   // Find the start position of 'ctau'
  Ssiz_t startPos = s_f_genOnly.Index("ctau") + 4; // +4 to move past 'ctau'
  // Find the length of the number by finding the position of '.root' starting from startPos
  Ssiz_t len = s_f_genOnly.Index(".root", startPos) - startPos;
  
  // Extract the number as a substring
  TString s_ctau = s_f_genOnly(startPos, len);
  
  // Convert TString to integer if necessary
  float tau0 = TString(s_ctau).Atof();
  const int nctau = 1;
  std::vector<float> ct; //{1,10,100,1000,3000};
  std::vector<float> eff;

  //always include default ct
  ct.push_back(tau0);
  ct.push_back(tauPrime);
  
  sort(ct.begin(), ct.end());
  auto it = unique(ct.begin(), ct.end()); 
  ct.erase(it, ct.end());

  for (int i  = 0; i< ct.size(); i++ ){
    eff.push_back( CalcEff(s_f_genOnly, tau0, ct[i]) ); 
  }

//  TGraph *gr = new TGraph(nctau,ct,eff);
//  TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
//  gr->Draw("AC*");
//  c1->SaveAs(s_f_genOnly+".png");

}
