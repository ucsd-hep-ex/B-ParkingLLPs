#ifndef analyzer_base_h
#define analyzer_base_h

#include <TROOT.h>

class analyzer_base {
public :
   //TChain          *fChain;   //!pointer to the analyzed TTree or TChain
   //Int_t           fCurrent; //!current Tree number in a TChain

   Int_t nLeptons_;



   analyzer_base();
   virtual ~analyzer_base();
   virtual void Initt();
};
#endif
