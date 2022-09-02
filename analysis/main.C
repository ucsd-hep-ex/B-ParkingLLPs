#include "analyzer.h"
#include <TTree.h>
#include <TFile.h>
#include <TChain.h>
#include "TH1F.h"
#include "TH2F.h"
#include <fstream>

int main(){

TChain* chain = new TChain("MuonSystem");
TString inpath = "root://cmsxrootd.fnal.gov//store/group/phys_exotica/delayedjets/displacedJetMuonAnalyzer/csc/V1p17/MC_Fall18/v2/v3/normalized/";

//Fill Sample file Chain
std::fstream s;
TString sampleName = "BToKPhi_MuonGenFilter_mPhi1p0_ctau1000_1pb_weighted.root";
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

return 0;
}
