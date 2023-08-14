#ifndef analyzer_histograms_h
#define analyzer_histograms_h

#include "TH1F.h"
#include "TH2F.h"
#include "analyzer_tree.h"

// Define the size of the array of histograms for selected bins
const int SELBINNAMESIZE = 10; // Change the value according to your needs

class analyzer_histograms : public analyzer_tree {

public:
    // Constructor
    analyzer_histograms();

    // Destructor
    virtual ~analyzer_histograms();

    // Initialize histograms
    void InitHistos();

    // Fill histograms for a given selected bin
    void FillHistos(int selbin);

    // Write histograms for a given selected bin
    void WriteHistos(int selbin);

    // Delete histograms for a given selected bin
    void DeleteHistos(int selbin);

    // Add your new histograms below this comment block
    // To add another histogram:
    // 1. Declare the new histogram as a public member.
    //    For example:
    //    TH1F* h_newHistogram[SELBINNAMESIZE];
    //
    // 2. Go back to analyzer_histogram.C


    // Histograms for the number of leptons in each selected bin
    TH1F* h_nLeptons[SELBINNAMESIZE];

    // Histograms for CSC rechit cluster variables in each selected bin
    TH1F* h_cscRechitClusterDPhiLeadMuon[SELBINNAMESIZE];
    TH1F* h_nCscRechits[SELBINNAMESIZE];
    TH1F* h_cscRechitClusterSize[SELBINNAMESIZE];
    TH1F* h_cscRechitClusterSize_v[SELBINNAMESIZE];
    TH1F* h_cscRechitClusterPhi[SELBINNAMESIZE];
    TH1F* h_cscRechitClusterEta[SELBINNAMESIZE];
    TH1F* h_cscRechitClusterTime[SELBINNAMESIZE];
    TH1F* h_cscRechitClusterTimeWeighted[SELBINNAMESIZE];
    TH1F* h_cscRechitClusterTimeTotal[SELBINNAMESIZE];
    TH1F* h_cscRechitClusterTimeSpread[SELBINNAMESIZE];
    TH1F* h_cscRechitClusterTimeSpreadWeighted[SELBINNAMESIZE];
    TH1F* h_cscRechitClusterTimeSpreadWeightedAll[SELBINNAMESIZE];

    // Histograms for DT rechit cluster variables in each selected bin
    TH1F* h_dtRechitClusterDPhiLeadMuon[SELBINNAMESIZE];
    TH1F* h_dtRechitCluster_match_RPCBx_dPhi0p5[SELBINNAMESIZE];
    TH1F* h_nDTRechits[SELBINNAMESIZE];
    TH1F* h_dtRechitClusterSize[SELBINNAMESIZE];
    TH1F* h_dtRechitClusterPhi[SELBINNAMESIZE];
    TH1F* h_dtRechitClusterEta[SELBINNAMESIZE];
    TH1F* h_dtRechitCluster_match_RPCTime_dR0p4[SELBINNAMESIZE];
    TH1F* h_dtRechitCluster_match_RPCTimeSpread_dR0p4[SELBINNAMESIZE];
    TH1F* h_dtRechitCluster_match_RPChits_dR0p4[SELBINNAMESIZE];
    TH1F* h_dtRechitCluster_match_RPCTime_dPhi0p5[SELBINNAMESIZE];
    TH1F* h_dtRechitCluster_match_RPCTimeSpread_dPhi0p5[SELBINNAMESIZE];
    TH1F* h_dtRechitCluster_match_RPCTime_sameStation_dR0p4[SELBINNAMESIZE];
    TH1F* h_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4[SELBINNAMESIZE];
};

#endif
