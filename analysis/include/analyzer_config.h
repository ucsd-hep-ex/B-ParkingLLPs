#ifndef analyzer_config_h
#define analyzer_config_h

#include "analyzer_base.h"

class analyzer_config : public analyzer_base {

public:
  analyzer_config();
  virtual ~analyzer_config();
  void setConfig();

  // Number of selected bin names
  static const int SELBINNAMESIZE = 4;

  // Boolean flags for configuration options
  static const Bool_t b_cutFlow = kTRUE;  // Enable/disable cut flow analysis
  //static const Bool_t b_doTree = kTRUE;  // Enable/disable tree analysis
  static const Bool_t b_doTree = kFALSE;  // Enable/disable tree analysis

  // Variables for analysis configuration
  Float_t muPt;  // Muon pT cut
  Float_t muEta; // Muon eta cut

  int DtSize;  // Size of Dt (Drift Tube) data
  int CscSize; // Size of Csc (Cathode Strip Chamber) data

  Float_t CscEta; // Eta cut for Csc clusters
  Float_t DtEta;  // Eta cut for Dt clusters

  double dr_LeadMu_DtCluster;  // Delta R cut between leading muon and Dt cluster
  double dr_LeadMu_CscCluster; // Delta R cut between leading muon and Csc cluster
  double dr_GenMu_DtCluster;   // Delta R cut between generated muon and Dt cluster
  double dr_GenMu_CscCluster;  // Delta R cut between generated muon and Csc cluster

  Float_t DtMuonVetoPt;   // Muon veto pT for Dt clusters
  Float_t CscMuonVetoPt;  // Muon veto pT for Csc clusters
  Int_t DtMB1Veto;        // MB1 veto for Dt clusters

  double dPhiCut_LeadMu_CscCluster; // Delta Phi cut between leading muon and Csc cluster
  double dPhiCut_LeadMu_DtCluster;  // Delta Phi cut between leading muon and Dt cluster

  Float_t cscClusterTimeLow;    // Lower time cut for Csc clusters
  Float_t cscClusterTimeHigh;   // Upper time cut for Csc clusters
  Float_t cscClusterTimeSpread; // Time spread cut for Csc clusters

  int HLTIndexLow;  // Lower index for HLT (High-Level Trigger) selection
  int HLTIndexHigh; // Upper index for HLT (High-Level Trigger) selection

  Bool_t doCutFlow(); // Check if cut flow analysis is enabled
  Bool_t doTree();    // Check if tree analysis is enabled
};

#endif
