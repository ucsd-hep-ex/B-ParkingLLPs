#include "analyzer.h"
#include "analyzer_base.h"
#include <TTree.h>
#include <TFile.h>
#include <TChain.h>
#include "TH1F.h"
#include "TH2F.h"
#include <fstream>

#include <TStopwatch.h>


int main(){

//start stopwatch
TStopwatch sw;
sw.Start();

TChain* chain = new TChain("MuonSystem");
//TString inpath = "root://cmsxrootd.fnal.gov//store/user/ddiaz/B-Parking/V1p19_0/ParkingBPH4_2018A/";
TString inpath = "root://cmsxrootd.fnal.gov//store/user/ddiaz/B-Parking/V1p19_0/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300/";

//Fill Sample file Chain
///??std::fstream s;
//TString sampleName = "ParkingBPH4_2018A.root";
TString sampleName = "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300.root";
std::cout<<inpath+sampleName<<std::endl;
chain->Add(inpath+sampleName);


//TFile *f = TFile::Open(sampleName+"_plots.root", "recreate");
analyzer S;
S.Init(chain);
S.f_out.push_back( new TFile(sampleName+"_plots.root", "RECREATE") ); 
S.InitHistos();
S.Loop();
S.f_out[0]->Close();


std::cout<<"Done with Final Loop"<<std::endl;

// end stopwatch
sw.Stop();
std::cout << "Real Time: " << sw.RealTime()/60.0 <<" mins"<< std::endl;
std::cout << "CPU Time: " << sw.CpuTime()/60.0 <<" mins"<< std::endl;


return 0;
}
