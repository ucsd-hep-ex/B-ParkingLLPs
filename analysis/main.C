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


int main(int argc, char* argv[]){
//start stopwatch
TStopwatch sw;
sw.Start();

TString s_Sample = ParseCommandLine( argc, argv, "--Sample=" );
TString s_Path   = ParseCommandLine( argc, argv, "--Path=" );
Bool_t isMC = kTRUE;

TString from_ctau_str = ParseCommandLine(argc, argv, "--from_ctau=");
TString to_ctau_str = ParseCommandLine(argc, argv, "--to_ctau=");

if ((from_ctau_str == "" && to_ctau_str != "") ||
    (from_ctau_str != "" && to_ctau_str == "")) {
  std::cerr << "Error: Both --from_ctau and --to_ctau must be specified together, or not at all.\n";
  return 1; // Exit the program with an error code
}

Float_t from_ctau = 1000.0; // Default value
Float_t to_ctau = 1000.0;   // Default value

if (from_ctau_str != "") from_ctau = atof(from_ctau_str.Data());
if (to_ctau_str != "") to_ctau = atof(to_ctau_str.Data());
    
TChain* chain = new TChain("MuonSystem");
//TString inpath = "root://cmsxrootd.fnal.gov//store/user/ddiaz/B-Parking/V1p19_1/ParkingBPH4_2018A/";
TString inpath = "root://cmsxrootd.fnal.gov//store/user/ddiaz/B-Parking/V1p19_6/BToKPhi_MuonGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300/";
//TString inpath = "root://cmsxrootd.fnal.gov//store/user/ddiaz/B-Parking/V1p19_1/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300/";
//TString inpath = "/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/llp_analyzer/";
//-- what Tony and Aram use
//TString inpath = "root://cmsxrootd.fnal.gov//store/user/ahayrape/BigNtupler/";

//Fill Sample file Chain
//TString sampleName = "ParkingBPH4_2018A";
TString sampleName = "BToKPhi_MuonGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300";
//TString sampleName = "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300";
//TString sampleName = "MuonSystem_Tree";
//-- what Tony and Aram use
//TString sampleName = "PhiToPi0Pi0_mPhi0p3_ctau300";


TString Sample;
TString theSample;
if(s_Sample != "") {
  Sample = s_Path+s_Sample+".root";
  theSample = s_Sample;
}
else {
  Sample = inpath+sampleName+".root";
  theSample = sampleName;
}
std::cout<<Sample<<std::endl;
chain->Add(Sample);

if(theSample.Contains("Parking")) isMC = kFALSE;

std::vector<TString> selBinNames;
selBinNames.push_back("test");
selBinNames.push_back("testOOT");
selBinNames.push_back("SR");
selBinNames.push_back("OOT");
selBinNames.push_back("SR2");
selBinNames.push_back("OOT2");


TFile *f;
analyzer S;
if (S.doTree()) f = new TFile("roots/"+theSample+"_tup.root", "recreate");
S.Init(chain, isMC);
S.setConfig();
for (int i =0; i<selBinNames.size(); i++){
  S.f_out.push_back( new TFile("roots/"+theSample+selBinNames[i]+"_plots.root", "RECREATE") ); 
}
S.InitHistos();
S.Loop(f, from_ctau, to_ctau, theSample);
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
