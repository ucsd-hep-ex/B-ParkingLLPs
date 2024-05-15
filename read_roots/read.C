#include <iostream>
#include <algorithm>
#include "TFile.h"
#include "TH1F.h"
#include "TTree.h"
#include "TCanvas.h"

void read() {
    // Open the ROOT file
    TFile *file1 = TFile::Open("BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau300.root");
    TFile *file2 = TFile::Open("BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000.root");
    if (!file1 || file1->IsZombie()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    if (!file2 || file2->IsZombie()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    // Get the TTree from the file
    TTree *tree_300 = nullptr;
    file1->GetObject("MuonSystem", tree_300);
    if (!tree_300) {
        std::cerr << "Error retrieving MuonSystem TTree" << std::endl;
        file1->Close();
        return;
    }
    TTree *tree_1000 = nullptr;
    file2->GetObject("MuonSystem", tree_1000);
    if (!tree_1000) {
        std::cerr << "Error retrieving MuonSystem TTree" << std::endl;
        file2->Close();
        return;
    }

    // set your binning
    TH1F *h_gLLP_ctau_300 = new TH1F("h_gLLP_ctau_300", "h_gLLP_ctau_300", 100, 0, 1000);
    TH1F *h_gLLP_ctau_1000 = new TH1F("h_gLLP_ctau_1000", "h_gLLP_ctau_1000", 100, 0, 1000);
    

    // Set branch address
    float gLLP_ctau_300;
    float gLLP_ctau_1000;
    
    tree_300->SetBranchAddress("gLLP_ctau", &gLLP_ctau_300);
    tree_1000->SetBranchAddress("gLLP_ctau", &gLLP_ctau_1000);

    // Loop over the tree entries and fill the histogram
    Long64_t nEntries_300 = tree_300->GetEntries();
    for (Long64_t i = 0; i < nEntries_300; i++) {
        tree_300->GetEntry(i);
        h_gLLP_ctau_300->Fill(gLLP_ctau_300);
    }
    h_gLLP_ctau_300->Scale(1./h_gLLP_ctau_300->Integral(0,-1));
    Long64_t nEntries_1000 = tree_1000->GetEntries();
    for (Long64_t i = 0; i < nEntries_1000; i++) {
        tree_1000->GetEntry(i);
        h_gLLP_ctau_1000->Fill(gLLP_ctau_1000);

    }
    h_gLLP_ctau_1000->Scale(1./h_gLLP_ctau_1000->Integral(0,-1));

    

    // Now you can use the histograms you saved in the loop here
    //compare which tree has the shorter bins
    //int binNum =std::min(h_gLLP_ctau_300->GetNbinsX(), h_gLLP_ctau_1000->GetNbinsX());
    //initialize an array to store the difference between binNumber
    //float abs_bin_diff[100];


    int binNum_300 = h_gLLP_ctau_300->GetNbinsX();
    std::cout << "content of ctau_300's bins" << endl;
    for(int i= 1; i < binNum_300; i++)
    {
        std::cout << i <<" "<<h_gLLP_ctau_300->GetBinContent(i)<< std::endl;

    }
    int binNum_1000 = h_gLLP_ctau_1000->GetNbinsX();
    std::cout << "content of ctau_1000's bins" << endl;
    for(int i= 1; i < binNum_1000; i++)
    {
        std::cout << i <<" "<<h_gLLP_ctau_1000->GetBinContent(i)<< std::endl;

    }

    //getting the difference between each binsif(h_gLLP_ctau_300->GetBinContent(i) !=0)
    
    //std::cout << h_gLLP_ctau_300->GetBinContent(i)<< std::endl;

     for (int i = 1; i <= 40; i++)
     {
        //getting the ratio of two decay length
        float ratio = h_gLLP_ctau_300->GetBinContent(i)/h_gLLP_ctau_1000->GetBinContent(i);
        //std::cout<<i <<" "<<h_gLLP_ctau_300->GetBinContent(i)<<"  "<<h_gLLP_ctau_1000->GetBinContent(i)<<"  "<< ratio<<std::endl;
        
     }
    //finding the minimum difference, where the intersection we want to find
    // float min_diff = abs_bin_diff[0];
    // float x_cor;
    // for(int j = 1; j < 100; j++)
    // {
    //     if (abs_bin_diff[j-1] < min_diff && (h_gLLP_ctau_300->GetBinContent(j-1)!=0 && h_gLLP_ctau_1000->GetBinContent(j-1) != 0))
    //     {
    //         min_diff = abs_bin_diff[j-1];
    //         x_cor = h_gLLP_ctau_1000->GetBinCenter(j);
    //     }
    // }

    //print out the minimum difference and the x-coordinate of the intersection
    // std::cout << min_diff << std::endl;
    // std::cout << x_cor << std::endl;

    float ratio_closest_to_1 = h_gLLP_ctau_300->GetBinContent(1)/h_gLLP_ctau_1000->GetBinContent(1);
    int NumBin = 1;
    for (int i = 1; i<= 40; i++)
    {
        if (abs(1-h_gLLP_ctau_300->GetBinContent(i)/h_gLLP_ctau_1000->GetBinContent(i)) < abs(1-ratio_closest_to_1))
        {
            ratio_closest_to_1 = h_gLLP_ctau_300->GetBinContent(i)/h_gLLP_ctau_1000->GetBinContent(i);
            NumBin = i;
        }
    }
    float x_cor = h_gLLP_ctau_300->GetBinCenter(NumBin);
    std::cout<<"x coordinate of the intersection is: " << x_cor << " with ratio: " <<ratio_closest_to_1<< std::endl;


     
    
    // virtual Double_t GetBinCenter (Int_t 3)


    // For Plotting
    TCanvas *c1 = new TCanvas("c1", "gLLP_ctau Distribution", 800, 600);
    h_gLLP_ctau_300->Draw();
    TCanvas *c2 = new TCanvas("c2", "gLLP_ctau Distribution", 800, 600);
    h_gLLP_ctau_1000->Draw();

    // Save the canvas to a file
    c1->SaveAs("h_gLLP_PhiToPi0Pi_ctau300.png");
    c1->SetLogy();
    c1->SaveAs("h_gLLP_PhiToPi0Pi_ctau300_log.png");
    c2->SaveAs("h_gLLP_PhiToPi0Pi_ctau1000.png");
    c2->SetLogy();
    c2->SaveAs("h_gLLP_PhiToPi0Pi_ctau1000_log.png");

    // Close the ROOT file
    file1->Close();
    file2->Close();
}

