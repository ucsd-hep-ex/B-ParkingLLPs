#ifndef analyzer_objects_h
#define analyzer_objects_h

#include "analyzer_config.h"
#include "TH1F.h"

class analyzer_objects : public analyzer_config{

  public : 
 
           analyzer_objects();
  virtual ~analyzer_objects();

  bool askDoesPassClusterSize_dt (int index);
  bool askDoesPassOverlapMuon_dt (int index);
  bool askDoesOverlapGenMuon_dt  (int index);
  bool askDoesPassRPCMatching_dt (int index);
  bool askDoesPassMuonVeto_dt    (int index);
  bool askDoesPassMB1Veto_dt     (int index);
  bool askDoesPassRPCTimeCut_dt  (int index);
  bool askDoesPassMB1Adjacent_dt (int index);
  bool askDoesPassClusterEta_dt  (int index);
  bool askDoesPassdPhiLeadMuon_dt       (int index);

  bool askDoesPassJetVetoPt_csc         (int index);
  bool askDoesPassClusterSize_csc       (int index);
  bool askDoesPassOverlapMuon_csc       (int index);
  bool askDoesOverlapGenLLP_csc         (int index);
  bool askDoesPassME1112Veto_csc        (int index);
  bool askDoesPassMB1Veto_csc           (int index);
  bool askDoesPassRB1Veto_csc           (int index);
  bool askDoesPassRE12Veto_csc          (int index);
  bool askDoesPassMuonVeto_csc          (int index);
  bool askDoesPassClusterTime_csc       (int index);
  bool askDoesPassClusterTimeSpread_csc (int index);
  bool askDoesPassClusterEta_csc        (int index);
  bool askDoesPassMinDPhiLeadMuon_csc   (int index);
  bool askDoesPassdPhiLeadMuon_csc      (int index);
  bool askDoesPassID_csc                (int index);

  bool askDoesPassMaxStation_dt(int index);
  bool askDoesPassMaxStation3_dt(int index);
  bool askDoesPassMaxStation4_dt(int index);

  bool askDoesPassNominal_dt(int index);
  bool askDoesPassNominal_csc(int index);

  std::vector<int> muonPassSel(Float_t muPtCut, Float_t muEtaCut);
  void muonPassSel_cutflow(Float_t muPtCut, Float_t muEtaCut, Float_t ew, TH1F * cutflow_histogram[]);

  std::vector<int> DtClusterPassSel_Fail      (bool passHLT);
  std::vector<int> DtClusterPassSel_FailOOT   (bool passHLT);
  std::vector<int> DtClusterPassSel_Pass      (bool passHLT);
  std::vector<int> DtClusterPassSel_PassOOT   (bool passHLT);

  std::vector<int> CscClusterPassSel_Fail     (bool passHLT);
  std::vector<int> CscClusterPassSel_FailOOT  (bool passHLT);
  std::vector<int> CscClusterPassSel_Pass     (bool passHLT);
  std::vector<int> CscClusterPassSel_PassOOT  (bool passHLT);

  std::vector<int> DtClusterPassSel_nominal          (bool passHLT);
  std::vector<int> CscClusterPassSel_nominal         (bool passHLT);
  std::vector<int> DtClusterPassSel_nominalPlusTime  (bool passHLT);
  std::vector<int> CscClusterPassSel_nominalPlusTime (bool passHLT);

  std::vector<int> DtClusterPassSel_PassCS   (bool passHLT);
  std::vector<int> DtClusterPassSel_FailCS   (bool passHLT);
  std::vector<int> CscClusterPassSel_PassCS  (bool passHLT);
  std::vector<int> CscClusterPassSel_FailCS  (bool passHLT);

  void DtClusterPassSel_CutFlow (Float_t ew, TH1F * cutflow_histogram[]);
  void CscClusterPassSel_CutFlow(Float_t ew, TH1F * cutflow_histogram[]);
  std::vector<int> jetPassSel(Float_t jetPtCut, Float_t CISVCut);
};

#endif
