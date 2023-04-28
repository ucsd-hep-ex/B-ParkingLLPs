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

TChain* chain = new TChain("MuonSystem");
//TString inpath = "root://cmsxrootd.fnal.gov//store/user/ddiaz/B-Parking/V1p19_1/ParkingBPH4_2018A/";
TString inpath = "root://cmsxrootd.fnal.gov//store/user/ddiaz/B-Parking/V1p19_1/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300/";
//-- what Tony and Aram use
//TString inpath = "root://cmsxrootd.fnal.gov//store/user/ahayrape/BigNtupler/";

//Fill Sample file Chain
//TString sampleName = "ParkingBPH4_2018A";
TString sampleName = "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300";
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
selBinNames.push_back("SR");
selBinNames.push_back("OOT");

//TFile *f = TFile::Open(theSample+"_plots.root", "recreate");
analyzer S;
S.Init(chain, isMC);
S.setConfig();
for (int i =0; i<selBinNames.size(); i++){
  S.f_out.push_back( new TFile("roots/"+theSample+selBinNames[i]+"_plots.root", "RECREATE") ); 
}
S.InitHistos();
S.Loop();
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
