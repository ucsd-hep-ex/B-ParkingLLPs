#ifndef analyzer_objects_h
#define analyzer_objects_h

#include "analyzer_config.h"

class analyzer_objects : public analyzer_config{

  public : 
 
           analyzer_objects();
  virtual ~analyzer_objects();

  double dR(double eta1, double phi1, double eta2, double phi2);
  double DeltaPhi(double phi1, double phi2);

  std::vector<int> muonPassSel(Float_t muPtCut, Float_t muEtaCut);
  std::vector<int> DtClusterPassSel (bool passHLT, int DtSizeCut , float dr_MuonCut);
  std::vector<int> CscClusterPassSel(bool passHLT, int CscSizeCut, float dr_MuonCut);

  void DtClusterPassSel_CutFlow (int DtSizeCut , float dr_MuonCut);
  void CscClusterPassSel_CutFlow(int CscSizeCut, float dr_MuonCut);
};

#endif
