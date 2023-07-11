#include "CommandLineInput.h"
#include "TH1F.h"
#include "TH2F.h"
#include "analyzer.h"
#include "analyzer_base.h"
#include <TChain.h>
#include <TFile.h>
#include <TTree.h>
#include <fstream>

#include <TStopwatch.h>

int main(int argc, char *argv[]) {
  // start stopwatch
  TStopwatch sw;
  sw.Start();

  // Parse command line arguments
  TString s_Sample = ParseCommandLine(argc, argv, "--Sample=");
  TString s_Path = ParseCommandLine(argc, argv, "--Path=");
  Bool_t isMC = kTRUE;

  // Create a TChain object to hold the input data
  TChain *chain = new TChain("MuonSystem");

  // Define the input path and sample name
  TString inpath =
      "root://cmsxrootd.fnal.gov//store/user/ddiaz/B-Parking/V1p19_1/"
      "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300/";
  TString sampleName =
      "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300";

  // Add the input files to the chain
  TString Sample;
  TString theSample;
  if (s_Sample != "") {
    Sample = s_Path + s_Sample + ".root";
    theSample = s_Sample;
  } else {
    Sample = inpath + sampleName + ".root";
    theSample = sampleName;
  }
  std::cout << Sample << std::endl;
  chain->Add(Sample);

  // Check if the sample is data or Monte Carlo
  if (theSample.Contains("Parking"))
    isMC = kFALSE;

  // Define the names of the selected bins
  std::vector<TString> selBinNames;
  selBinNames.push_back("test");
  selBinNames.push_back("testOOT");
  selBinNames.push_back("SR");
  selBinNames.push_back("OOT");

  // Create a TFile object for writing the output histograms (if using tree)
  TFile *f;
  analyzer S;
  if (S.doTree())
    f = new TFile("roots/" + theSample + "_tup.root", "recreate");

  // Initialize the analyzer
  S.Init(chain, isMC);
  S.setConfig();

  // Create output TFile objects for each selected bin
  for (int i = 0; i < selBinNames.size(); i++) {
    S.f_out.push_back(new TFile(
        "roots/" + theSample + selBinNames[i] + "_plots.root", "RECREATE"));
  }

  // Initialize histograms
  S.InitHistos();

  // Run the analysis loop
  S.Loop(f);

  // Close the output TFile objects
  for (int j = 0; j < selBinNames.size(); j++) {
    std::cout << "Closing " << selBinNames[j] << "  histograms file"
              << std::endl;
    S.f_out[j]->Close();
  }

  std::cout << "Done with Final Loop" << std::endl;

  // Stop the stopwatch and print the elapsed time
  sw.Stop();
  std::cout << "Real Time: " << sw.RealTime() / 60.0 << " mins" << std::endl;
  std::cout << "CPU Time: " << sw.CpuTime() / 60.0 << " mins" << std::endl;

  return 0;
}
