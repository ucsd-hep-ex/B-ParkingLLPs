#include "analyzer.h"
#include "analyzer_base.h"
#include <TTree.h>
#include <TFile.h>
#include <TChain.h>
#include "TH1F.h"
#include "TH2F.h"
#include <TRegexp.h>
#include <fstream>
#include "CommandLineInput.h"

#include <TStopwatch.h>


int main(int argc, char* argv[]){
//start stopwatch
TStopwatch sw;
sw.Start();

TString s_Sample = ParseCommandLine( argc, argv, "--Sample=" );
TString s_Path   = ParseCommandLine( argc, argv, "--Path=" );
TString to_ctau_str = ParseCommandLine(argc, argv, "--to_ctau=");
Bool_t isMC = kTRUE;
    
TChain* chain = new TChain("MuonSystem");
TString inpath = "/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_14_0_6_patch1/src/B-ParkingLLPs/analysis/";
//TString inpath = "root://cmsxrootd.fnal.gov//store/user/ahayrape/B-Parking_Output/v1p19_12/ParkingBPH1_2018A/";
//TString inpath = "root://cmsxrootd.fnal.gov//store/group/lpclonglived/B-ParkingLLPs//V1p19_9/BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300/";
//TString inpath = "root://cmsxrootd.fnal.gov//store/group/lpclonglived/B-ParkingLLPs//V1p19_14/BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300/";
//TString inpath = "root://cmsxrootd.fnal.gov//store/group/lpclonglived/B-ParkingLLPs//V1p19_9/BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau5000/";

//Fill Sample file Chain
TString sampleName = "ParkingBPH1_2018A_partialJets_BIG";
//TString sampleName = "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300";
//TString sampleName = "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau5000";


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

// Find the position of "_ctau" in the sample name
Ssiz_t pos = theSample.Index("_ctau");

// Extract the substring starting from the position of "_ctau" till the end
TString from_ctau_str = theSample(pos, theSample.Length() - pos);

// Remove the "_ctau" prefix
from_ctau_str.ReplaceAll("_ctau", "");

// Convert the string to a float
Float_t from_ctau = atof(from_ctau_str.Data())/10.;
Float_t to_ctau = from_ctau;

if (to_ctau_str != "") {
    to_ctau = atof(to_ctau_str.Data())/10.; // Override to_ctau if argument provided
    to_ctau_str = "to"+to_ctau_str;
}
else {
    to_ctau_str = "to"+from_ctau_str;
}

std::cout<<"to_ctau_str:  "<< to_ctau_str<<std::endl;
std::cout<<"from: "<<from_ctau<<" cm"<<std::endl;
    
std::cout<<"to: "<<to_ctau<<" cm"<<std::endl;

    
std::cout<<Sample<<std::endl;
chain->Add(Sample);

if(theSample.Contains("Parking")) isMC = kFALSE;

std::vector<TString> selBinNames;
selBinNames.push_back("Fail");
selBinNames.push_back("FailOOT");
selBinNames.push_back("Pass");
selBinNames.push_back("PassOOT");
selBinNames.push_back("nominal");
selBinNames.push_back("nominalPlusTime");
selBinNames.push_back("PassCS");
selBinNames.push_back("FailCS");

    
// grab NEvents
TFile* f0 = TFile::Open(Sample);
Float_t NEvents = ((TH1F*)f0->Get("NEvents"))->GetBinContent(1);
std::cout<<NEvents<<std::endl;
f0->Close();

TFile *f;
analyzer S;
if (S.doTree()) f = new TFile("roots/"+theSample+to_ctau_str+"_tup.root", "recreate");
S.Init(chain, isMC);
S.setConfig();
for (int i =0; i<selBinNames.size(); i++){
  S.f_out.push_back( new TFile("roots/"+theSample+to_ctau_str+"_"+selBinNames[i]+"_plots.root", "RECREATE") ); 
}
S.InitHistos();
S.Loop(f, from_ctau, to_ctau, theSample, NEvents);
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
