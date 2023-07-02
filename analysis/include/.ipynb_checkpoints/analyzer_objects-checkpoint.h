#ifndef analyzer_objects_h
#define analyzer_objects_h

#include "analyzer_config.h"

class analyzer_objects : public analyzer_config{

  public : 
 
           analyzer_objects();
  virtual ~analyzer_objects();

  double dR(double eta1, double phi1, double eta2, double phi2);
  double DeltaPhi(double phi1, double phi2);

 
  bool askDoesPassClusterSize_dt (int index);
  bool askDoesPassOverlapMuon_dt (int index);
  bool askDoesOverlapGenMuon_dt  (int index);
  bool askDoesPassRPCMatching_dt (int index);
  bool askDoesPassMuonVeto_dt    (int index);
  bool askDoesPassMB1Veto_dt     (int index);
  bool askDoesPassRPCTimeCut_dt  (int index);
  bool askDoesPassMB1Adjacent_dt (int index);
  bool askDoesPassClusterEta_dt  (int index);
  bool askDoesPassID_dt          (int index);

  bool askDoesPassClusterSize_csc       (int index);
  bool askDoesPassOverlapMuon_csc       (int index);
  bool askDoesOverlapGenLLP_csc         (int index);
  bool askDoesPassME1112Veto_csc        (int index);
  bool askDoesPassMB1Veto_csc           (int index);
  bool askDoesPassRB1Veto_csc           (int index);
  bool askDoesPassMuonVeto_csc          (int index);
  bool askDoesPassClusterTime_csc       (int index);
  bool askDoesPassClusterTimeSpread_csc (int index);
  bool askDoesPassClusterEta_csc        (int index);
  bool askDoesPassdPhiLeadMuon_csc      (int index);
  bool askDoesPassID_csc                (int index);


  std::vector<int> muonPassSel(Float_t muPtCut, Float_t muEtaCut);
  std::vector<int> DtClusterPassSel      (bool passHLT);
  std::vector<int> DtClusterPassSel_SR   (bool passHLT);
  std::vector<int> DtClusterPassSel_OOT  (bool passHLT);
  std::vector<int> CscClusterPassSel     (bool passHLT);
  std::vector<int> CscClusterPassSel_SR  (bool passHLT);
  std::vector<int> CscClusterPassSel_OOT (bool passHLT);

  void DtClusterPassSel_CutFlow ();
  void CscClusterPassSel_CutFlow();
};

#endif
