#ifndef analyzer_config_h
#define analyzer_config_h

#include "analyzer_base.h"

class analyzer_config : public analyzer_base{

  public : 
 
           analyzer_config();
  virtual ~analyzer_config();
  void     setConfig();


  Float_t muPt;
  Float_t muEta;

  int DtSize;
  int CscSize;

  double dr_LeadMu_DtCluster;
  double dr_LeadMu_CscCluster;
  double dr_GenMu_DtCluster;
  double dr_GenMu_CscCluster;
 
  Float_t DtMuonVetoPt;
  Int_t   DtMB1Veto;

  int HLTIndexLow;
  int HLTIndexHigh;
};
#endif

