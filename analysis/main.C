#include "analyzer.h"
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
TString inpath = "root://cmsxrootd.fnal.gov//store/user/ddiaz/B-Parking/V1p19_0/ParkingBPH4_2018A/";

//Fill Sample file Chain
std::fstream s;
TString sampleName = "ParkingBPH4_2018A.root";
std::cout<<inpath+sampleName<<std::endl;
chain->Add(inpath+sampleName);
//TString outFileName = sampleName+".root";


analyzer S;
S.Init(chain);
S.Loop();

//std::vector<float> *vz = S.vz;







//TFile *f = TFile::Open(sampleName+"_plots.root", "recreate");
//f->cd();
//   h_pf_pt->Write();
//   h_pf_vz->Write();
//f->Close();

std::cout<<"Done with Final Loop"<<std::endl;

// end stopwatch
sw.Stop();
std::cout << "Real Time: " << sw.RealTime()/60.0 <<" mins"<< std::endl;
std::cout << "CPU Time: " << sw.CpuTime()/60.0 <<" mins"<< std::endl;


return 0;
}
