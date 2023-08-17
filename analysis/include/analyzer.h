//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Sep  1 02:22:32 2022 by ROOT version 6.24/06
// from TTree MuonSystem/MuonSystem
// found on file: BToKPhi_MuonGenFilter_mPhi1p0_ctau1000_1pb_weighted.root
//////////////////////////////////////////////////////////

#ifndef analyzer_h
#define analyzer_h

#include <iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "analyzer_histograms.h"

class analyzer : public analyzer_histograms {
public :
   //TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   //Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   analyzer();
   virtual ~analyzer();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   //virtual Long64_t LoadTree(Long64_t entry);
   //virtual void     Init(TTree *tree);
   virtual void     Loop(TFile *f, Float_t from_ctau, Float_t to_ctau);
   //virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   bool doesPassHLT(); 
};

#endif

#ifdef analyzer_cxx


Int_t analyzer::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}



void analyzer::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t analyzer::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}


bool analyzer::doesPassHLT(){
  bool doesPass = false;
  for (int t= HLTIndexLow; t <= HLTIndexHigh; t++){
    if (HLTDecision[t]) {doesPass = true; continue;}
  }
  return doesPass;
}
#endif // #ifdef analyzer_cxx
