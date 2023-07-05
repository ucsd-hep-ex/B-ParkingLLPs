#ifndef analyzer_config_h
#define analyzer_config_h

#include "analyzer_base.h"

class analyzer_config : public analyzer_base{

  public : 
 
           analyzer_config();
  virtual ~analyzer_config();
  void     setConfig();
  
  static const int SELBINNAMESIZE  = 4;
  //static const Bool_t b_cutFlow = kFALSE;
  static const Bool_t b_cutFlow = kTRUE;
  static const Bool_t b_doTree = kFALSE;
  //static const Bool_t b_doTree = kTRUE;

  Float_t muPt;
  Float_t muEta;

  int DtSize;
  int CscSize;
 
  Float_t CscEta;
  Float_t DtEta;

  double dr_LeadMu_DtCluster;
  double dr_LeadMu_CscCluster;
  double dr_GenMu_DtCluster;
  double dr_GenMu_CscCluster;
 
  Float_t DtMuonVetoPt;
  Float_t CscMuonVetoPt;
  Int_t   DtMB1Veto;
  
  double dPhiCut_LeadMu_CscCluster;
  double dPhiCut_LeadMu_DtCluster;

  Float_t cscClusterTimeLow;
  Float_t cscClusterTimeHigh;
  Float_t cscClusterTimeSpread;

  int HLTIndexLow;
  int HLTIndexHigh;

  Bool_t doCutFlow();
  Bool_t doTree();
};
#endif

