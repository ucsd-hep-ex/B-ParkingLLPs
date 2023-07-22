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

const TString sampleName = "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300";

// Function to initialize the sample
void initializeSample(TString& s_Sample, TString& s_Path, TString& Sample, TString& theSample) {
  if(s_Sample != "") {
    Sample = s_Path+s_Sample+".root";
    theSample = s_Sample;
  }
  else {
    TString inpath = "root://cmsxrootd.fnal.gov//store/user/ddiaz/B-Parking/V1p19_1/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300/";
    Sample = inpath+sampleName+".root";
    theSample = sampleName;
  }
  std::cout<<Sample<<std::endl;
}

// Function to initialize the bin names
void initializeBinNames(std::vector<TString>& selBinNames) {
  selBinNames.push_back("test");
  selBinNames.push_back("testOOT");
  selBinNames.push_back("SR");
  selBinNames.push_back("OOT");
}

int main(int argc, char* argv[]){
  //start stopwatch
  TStopwatch sw;
  sw.Start();

  TString s_Sample = ParseCommandLine( argc, argv, "--Sample=" );
  TString s_Path   = ParseCommandLine( argc, argv, "--Path=" );
  Bool_t isMC = kTRUE;

  TChain* chain = new TChain("MuonSystem");

  TString Sample;
  TString theSample;
  initializeSample(s_Sample, s_Path, Sample, theSample);

  chain->Add(Sample);

  if(theSample.Contains("Parking")) isMC = kFALSE;

  std::vector<TString> selBinNames;
  initializeBinNames(selBinNames);

  TFile *f;
  analyzer S;
  if (S.doTree()) f = new TFile("roots/"+theSample+"_tup.root", "recreate");
  S.Init(chain, isMC);
  S.setConfig();
  for (int i =0; i<selBinNames.size(); i++){
    S.f_out.push_back( new TFile("roots/"+theSample+selBinNames[i]+"_plots.root", "RECREATE") ); 
  }
  S.InitHistos();
  S.Loop(f);
  for (int j = 0; j<selBinNames.size(); j++){
    std::cout<<"Closing "<<selBinNames[j]<<"  histograms file"<<std::endl;
    S.f_out[j]->Close();
  }

  std::cout<<"Done with Final Loop"<<std::endl;

  // end stopwatch
  sw.Stop();
  std::cout << "Real Time: " << sw.RealTime()/60.0 <<" mins"<< std::endl;
  std::cout << "CPU Time: " << sw.CpuTime()/60.0 <<" mins"<< std::endl;

  return 0;
}
