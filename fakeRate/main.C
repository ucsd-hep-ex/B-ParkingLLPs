#include "fakeRate.h"
#include <TTree.h>
#include <TFile.h>
#include <TChain.h>
#include "TH1F.h"
#include "TH2F.h"
#include <TRegexp.h>
#include <fstream>

#include "CommandLineInput.h"

#include <TStopwatch.h>

using namespace std;
int main(int argc, char* argv[]){
//start stopwatch
TStopwatch sw;
sw.Start();

TString s_SampleList = ParseCommandLine( argc, argv, "--SampleList=" );
//TString s_Path   = ParseCommandLine( argc, argv, "--Path=" );
    
TChain* chain = new TChain("MuonSystem");
//TChain* chain = new TChain("llp_merged");
//TString inpath = "root://cmsxrootd.fnal.gov//store/user/lpclonglived/HNL/skim_ttbar_v2/EGamma_2018A/";
//TString inpath = "root://cmsxrootd.fnal.gov//store/user/lpclonglived/HNL/skim_ttbar_v2/SingleElectron_2017F/";
//TString inpath = "/uscms/home/kkwok/lpclonglived/HNL/skim_ttbar_v2/";
//TString inpath = "root://cmsxrootd.fnal.gov//store/group/phys_exotica/delayedjets/displacedJetMuonNtuple/V1p17/One_Lepton_Merged_MS_Hits/EGamma/2018D/";
//TString inpath = "/uscms_data/d3/ddiaz/BParkingLLPs/CMSSW_14_0_6_patch1/src/B-ParkingLLPs/fakeRate/";
//TString inpath = "/eos/uscms/store/group/lpclonglived/B-ParkingLLPs/V1p17_5/EGamma_2018A/";
TString inpath = "/eos/uscms/store/user/lpclonglived/B-ParkingLLPs/V1p17_7/";
//TString inpath = "/eos/uscms/store/user/ahayrape/B-Parking_Output/v1p19_12/";

//Fill Sample file Chain
std::vector<TString> sampleName;
//sampleName.push_back("ParkingBPH1_2018A/ParkingBPH1_2018A-hadd0");
//sampleName.push_back("ParkingBPH1_2018A/ParkingBPH1_2018A-hadd1");
//sampleName.push_back("ParkingBPH1_2018A/ParkingBPH1_2018A-hadd2");
//sampleName.push_back("SingleMuon_2016B/SingleMuon_2016B");
//sampleName.push_back("SingleMuon_2016C/SingleMuon_2016C");
//sampleName.push_back("SingleMuon_2016D/SingleMuon_2016D");
//sampleName.push_back("SingleMuon_2016E/SingleMuon_2016E");
//sampleName.push_back("SingleMuon_2016F/SingleMuon_2016F");
//sampleName.push_back("SingleMuon_2016G/SingleMuon_2016G");
//sampleName.push_back("SingleMuon_2016H/SingleMuon_2016H");
sampleName.push_back("SingleElectron_2016B_v2/SingleElectron_2016B_v2");
//sampleName.push_back("SingleElectron_2016C/SingleElectron_2016C");
//sampleName.push_back("SingleElectron_2016D/SingleElectron_2016D");
//sampleName.push_back("SingleElectron_2016E/SingleElectron_2016E");
//sampleName.push_back("SingleElectron_2016F/SingleElectron_2016F");
//sampleName.push_back("SingleElectron_2016G/SingleElectron_2016G");
//sampleName.push_back("SingleElectron_2016H/SingleElectron_2016H");


std::vector<TString> Sample;
//TString Sample;
if(s_SampleList != "") {
  //Sample=s_Path+s_Sample+".root";
  ifstream infile;
  infile.open(s_SampleList);
  string s_Sample="";
  while(getline(infile,s_Sample)){ 
    Sample.push_back("root://cmsxrootd.fnal.gov//"+s_Sample+".root");
    std::cout<<"read in: "<<("root://cmsxrootd.fnal.gov//"+s_Sample+".root")<<std::endl;
  }
}
else {
  //Sample = inpath+sampleName+".root";
  for (int l=0; l<sampleName.size(); l++){
    Sample.push_back(inpath+sampleName[l]+".root");
  }
}
TString year;
if(Sample.size()>0){
       if(Sample[0].Contains("2016")) year = "2016";
  else if(Sample[0].Contains("2017")) year = "2017";
  else if(Sample[0].Contains("2018")) year = "2018";
  else year = "All";
}
else year = "All";
    
//std::cout<<Sample<<std::endl;
//chain->Add(Sample);
for (int k = 0; k< Sample.size(); k++){
  chain->Add(Sample[k]);
}

std::cout << "Number of files in chain: " << chain->GetListOfFiles()->GetEntries() << std::endl;    

//TFile *f;

fakeRate S;
S.Init(chain);
S.Loop(year);


std::cout<<"Done with Final Loop"<<std::endl;

// end stopwatch
sw.Stop();
std::cout << "Real Time: " << sw.RealTime()/60.0 <<" mins"<< std::endl;
std::cout << "CPU Time: " << sw.CpuTime()/60.0 <<" mins"<< std::endl;


return 0;
}
