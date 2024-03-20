#include "Acceptance.h"


int main(){


  TString Sample="/uscms/home/ahayrape/nobackup/BToPhiK_Analysis/New_signal/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300.root";

  TChain* chain = new TChain("MuonSystem");
  chain->Add(Sample); 
  Acceptance m;
  m.Init(chain);
  m.Loop();

  return 0;
}
