#include "Acceptance.h"
#include <iostream>

int main(int argc, char* argv[]){

  TString Sample=argv[1]; // "/uscms/home/ahayrape/nobackup/BToPhiK_Analysis/New_signal/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300.root";
  std::cout<<Sample<<std::endl;
  TChain* chain = new TChain("MuonSystem");
  chain->Add(Sample);
  Acceptance m;
  m.Init(chain);
  m.Loop(argc, argv);

  return 0;
}
