#include "analyzer.h"
#include "analyzer_base.h"
#include <TTree.h>
#include <TFile.h>
#include <TChain.h>
#include "TH1F.h"
#include "TH2F.h"
#include <fstream>
#include "CommandLineInput.h"
#include <TStopwatch.h>

const TString sampleName = "PhiToPiPlusPiMinus_mPhi0p3_ctau300";

// Function to initialize the sample
void initializeSample(TString& s_Sample, TString& s_Path, TString& Sample, TString& theSample) {
    // If a specific sample name is provided as a command-line argument, use that.
    // Otherwise, use the default sample name and path.
    if (s_Sample != "") {
        Sample = s_Path + s_Sample + ".root";
        theSample = s_Sample;
    } else {
        // Default path for the sample on the CMS computing cluster at Fermilab.
        TString inpath = "/eos/uscms/store/user/ahayrape/BigNtupler/";
        Sample = inpath + sampleName + ".root";
        theSample = sampleName;
    }
    std::cout << Sample << std::endl;
}

// Function to initialize the bin names
void initializeBinNames(std::vector<TString>& selBinNames) {
    // Initialize the vector with predefined bin names.
    selBinNames.push_back("test");
    selBinNames.push_back("testOOT");
    selBinNames.push_back("SR");
    selBinNames.push_back("OOT");
    selBinNames.push_back("SR2");
    selBinNames.push_back("OOT2");
}

int main(int argc, char* argv[]) {
    // Start the stopwatch to measure execution time.
    TStopwatch sw;
    sw.Start();
    
    // Parse command-line arguments to get the sample name and path.
    TString s_Sample = ParseCommandLine(argc, argv, "--Sample=");
    TString s_Path = ParseCommandLine(argc, argv, "--Path=");
    // Flag to indicate if the sample is from Monte Carlo (MC) or data.
    Bool_t isMC = kTRUE;
    
    // Create a TChain to read the data from the ROOT files.
    TChain* chain = new TChain("MuonSystem");
    
    TString Sample;
    TString theSample;
    // Initialize the sample name and path using the provided or default values.
    initializeSample(s_Sample, s_Path, Sample, theSample);
    
    // Add the ROOT file(s) to the TChain.
    chain->Add(Sample);
    
    // Determine if the sample is from data or Monte Carlo based on its name.
    if (theSample.Contains("Parking"))
        isMC = kFALSE;
    
    // Create a vector to hold bin names used for histograms.
    std::vector<TString> selBinNames;
    // Initialize the vector with predefined bin names.
    initializeBinNames(selBinNames);
    
    TFile* f;
    analyzer S;
    // If the analyzer should save the data to a TTree, create a ROOT file to store the tree.
    if (S.doTree())
        f = new TFile("roots/" + theSample + "_tup.root", "recreate");
    
    // Initialize the analyzer with the TChain and specify whether it's MC or data.
    S.Init(chain, isMC);
    // Set configuration parameters for the analyzer.
    S.setConfig();
    
    // Create ROOT files for each bin's histograms.
    for (int i = 0; i < selBinNames.size(); i++) {
        S.f_out.push_back(new TFile("roots/" + theSample + selBinNames[i] + "_plots.root", "RECREATE"));
    }
    
    // Initialize histograms and other objects needed by the analyzer.
    S.InitHistos();
    
    // Perform the analysis loop over the data.
    S.Loop(f);
    
    // Close the ROOT files for each bin's histograms.
    for (int j = 0; j < selBinNames.size(); j++) {
        std::cout << "Closing " << selBinNames[j] << " histograms file" << std::endl;
        S.f_out[j]->Close();
    }
    
    std::cout << "Done with Final Loop" << std::endl;
    
    // Stop the stopwatch and print the elapsed time.
    sw.Stop();
    std::cout << "Real Time: " << sw.RealTime() / 60.0 << " mins" << std::endl;
    std::cout << "CPU Time: " << sw.CpuTime() / 60.0 << " mins" << std::endl;
    
    return 0;
}
