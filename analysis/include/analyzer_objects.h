#ifndef analyzer_objects_h

#include "analyzer_config.h"

class analyzer_objects : public analyzer_config {
public:
    analyzer_objects();
    virtual ~analyzer_objects();

    // Calculate the Delta R between two points in eta-phi space
    double dR(double eta1, double phi1, double eta2, double phi2);

    // Calculate the difference in phi between two angles
    double DeltaPhi(double phi1, double phi2);

    // Functions to check various conditions for Dt clusters

    bool askDoesPassNominal_dt(int index);

    bool askDoesPassClusterSize_dt(int index);
    bool askDoesPassOverlapMuon_dt(int index);
    bool askDoesOverlapGenMuon_dt(int index);
    bool askDoesPassRPCMatching_dt(int index);
    bool askDoesPassMuonVeto_dt(int index);
    bool askDoesPassMB1Veto_dt(int index);
    bool askDoesPassRPCTimeCut_dt(int index);
    bool askDoesPassMB1Adjacent_dt(int index);
    bool askDoesPassClusterEta_dt(int index);
    bool askDoesPassMaxStation_dt(int index);
    bool askDoesPassMaxStation3_dt(int index);
    bool askDoesPassMaxStation4_dt(int index);

    // Functions to check various conditions for Csc clusters
    bool askDoesPassClusterSize_csc(int index);
    bool askDoesPassOverlapMuon_csc(int index);
    bool askDoesOverlapGenLLP_csc(int index);
    bool askDoesPassME1112Veto_csc(int index);
    bool askDoesPassMB1Veto_csc(int index);
    bool askDoesPassRB1Veto_csc(int index);
    bool askDoesPassMuonVeto_csc(int index);
    bool askDoesPassClusterTime_csc(int index);
    bool askDoesPassClusterTimeSpread_csc(int index);
    bool askDoesPassClusterEta_csc(int index);
    bool askDoesPassdPhiLeadMuon_csc(int index);
    bool askDoesPassdPhiLeadMuon_dt(int index);
    bool askDoesPassID_csc(int index);

    // Get the indices of muons passing a given pT and eta cut
    std::vector<int> muonPassSel(Float_t muPtCut, Float_t muEtaCut);

    // Get the indices of Dt clusters passing the selection criteria for different bins
    std::vector<int> DtClusterPassSel_test(bool passHLT);
    std::vector<int> DtClusterPassSel_testOOT(bool passHLT);
    std::vector<int> DtClusterPassSel_SR(bool passHLT);
    std::vector<int> DtClusterPassSel_OOT(bool passHLT);
    std::vector<int> DtClusterPassSel_SR2(bool passHLT);
    std::vector<int> DtClusterPassSel_OOT2(bool passHLT);

    // Get the indices of Csc clusters passing the selection criteria for different bins
    std::vector<int> CscClusterPassSel_test(bool passHLT);
    std::vector<int> CscClusterPassSel_testOOT(bool passHLT);
    std::vector<int> CscClusterPassSel_SR(bool passHLT);
    std::vector<int> CscClusterPassSel_OOT(bool passHLT);
    std::vector<int> CscClusterPassSel_SR2(bool passHLT);
    std::vector<int> CscClusterPassSel_OOT2(bool passHLT);

    // Perform the cut flow analysis for Dt clusters
    void DtClusterPassSel_CutFlow();

    // Perform the cut flow analysis for Csc clusters
    void CscClusterPassSel_CutFlow();
};

#endif
