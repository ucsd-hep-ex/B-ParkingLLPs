#include "analyzer_objects.h"
#include <math.h>

//----------------------------analyzer_objects
analyzer_objects::analyzer_objects()
{
}

//----------------------~analyzer_objects
analyzer_objects::~analyzer_objects()
{
}


std::vector<int> analyzer_objects::muonPassSel(Float_t muPtCut, Float_t muEtaCut){

  std::vector<int> ids;
  bool MuonExists  = false;
  bool MuonPassPt  = false;
  bool MuonPassEta = false;
  bool MuonPassHLTFilter = false;
  bool MuonPassQuality = false;
  for (int j = 0; j<nLeptons; j++){
    if(abs(lepPdgId[j]) != 13) continue;
    MuonExists = true;
    if(lepPt[j] > muPtCut){
      MuonPassPt = true;
      if(lepEta[j] < fabs(muEtaCut)){ 
        MuonPassEta = true;
        if(lepMuon_passHLTFilter[j]){
         MuonPassHLTFilter = true;
         if(lepMuonQuality[j] >= pow(2,25)){
           MuonPassQuality = true;
           ids.push_back(j);
         }
        }
      }
    }
  }
  if(MuonExists )       cutFlow["Muon Exists"] +=1;
  if(MuonPassPt )       cutFlow["MuonPt > 7 GeV"] +=1;
  if(MuonPassEta)       cutFlow["abs(MuonEta) < 1.5"] +=1;
  if(MuonPassHLTFilter) cutFlow["MuonHLTRequirement"] +=1;
  if(MuonPassQuality)   cutFlow["MuonQuality"] +=1;
  return ids;

}
