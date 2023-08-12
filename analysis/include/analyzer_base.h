// Macro guard for analyzer_base.h file to prevent double inclusion
#ifndef analyzer_base_h 
#define analyzer_base_h 

// Inclusions of ROOT library files
#include <TChain.h> // ROOT class to handle a collection of ROOT files as if they were a single large file
#include <TFile.h> // ROOT class to handle and analyze data stored in ROOT files
#include <TROOT.h> // The main interface to the ROOT system
#include <map> // Standard C++ library for map data structure

// Define constants for maximum sizes of various objects
#define N_MAX_LEPTONS 100
#define N_MAX_TRACKS 2000
#define N_MAX_JETS 100
#define N_MAX_CSC 200
#define N_MAX_CSCRECHITS 5000
#define N_MAX_DTRECHITS 20000
#define NTriggersMAX 1201 // Number of trigger in the .dat file
#define N_MAX_GPARTICLES 5000
#define MAX_MuonHLTFilters 100

// The analyzer_base class definition
class analyzer_base {
public:
    TChain *fChain; //! Pointer to the analyzed TTree or TChain
    Int_t fCurrent; //! Current Tree number in a TChain
    
    // Global variables
    Bool_t isMC = kFALSE; // Flag to check if the data is Monte Carlo
    int counter = 0; // General counter
    int counter2 = 0; // Second general counter
    std::vector<TFile *> f_out; // Vector of output ROOT files
    std::vector<std::vector<int>> DtClusterPassSel_all; // Vector of vectors storing passing selections of DT Clusters
    std::vector<std::vector<int>> CscClusterPassSel_all; // Vector of vectors storing passing selections of CSC Clusters
    std::vector<int> muon_list; // List of muons
    std::vector<int> DtCluster_list; // List of DT clusters
    std::vector<int> CscCluster_list; // List of CSC clusters
    
    // Selection flags
    bool passGoodMuon = false; // Flag indicating if there's a good muon
    // CSCs
    bool PassClusterSize_csc = false; // Flag indicating CSC cluster size
    bool PassOverlapMuon_csc = false; // Flag indicating overlapping muon CSC
    bool OverlapGenLLP_csc = false; // Flag indicating overlapping LLP CSC
    bool PassME1112Veto_csc = false; // Flag indicating veto pass of ME1112 CSC
    bool PassMB1Veto_csc = false; // Flag indicating veto pass of MB1 CSC
    bool PassRB1Veto_csc = false; // Flag indicating veto pass of RB1 CSC
    bool PassMuonVeto_csc = false; // Flag indicating veto pass of Muon CSC
    bool PassClusterTime_csc = false; // Flag indicating cluster time of CSC
    bool PassClusterTimeSpread_csc = false; // Flag indicating cluster time spread of CSC
    bool PassClusterEta_csc = false; // Flag indicating cluster eta of CSC
    bool PassID_csc = false; // Flag indicating pass of CSC ID
    // DTs
    bool PassClusterSize_dt = false; // Flag indicating DT cluster size
    bool PassOverlapMuon_dt = false; // Flag indicating overlapping muon DT
    bool OverlapGenMuon_dt = false; // Flag indicating overlapping GenMuon DT
    bool PassRPCMatching_dt = false; // Flag indicating RPC matching DT
    bool PassMuonVeto_dt = false; // Flag indicating veto pass of Muon DT
    bool PassMB1Veto_dt = false; // Flag indicating veto pass of MB1 DT
    bool PassRPCTimeCut_dt = false; // Flag indicating RPC time cut DT
    bool PassMB1Adjacent_dt = false; // Flag indicating adjacent MB1 DT
    
    std::map<TString, float> cutFlow; // Map to store cut flow information, with TString as key and float as value
    std::vector<TString> cutFlowKeys; // Vector to store the keys for the cutFlow map

   //global variables here
   Bool_t isMC;
   int counter  = 0;
   int counter2 = 0;
   std::vector<TFile*> f_out;
   std::vector<std::vector<int>> DtClusterPassSel_all;
   std::vector<std::vector<int>> CscClusterPassSel_all;
   std::vector<int> muon_list;
   std::vector<int> DtCluster_list;
   std::vector<int> CscCluster_list;

    analyzer_base();
    virtual ~analyzer_base();
    virtual void Init(TChain *tree, Bool_t isMC_);
    virtual Long64_t LoadTree(Long64_t entry);
    double dR(double eta1, double phi1, double eta2, double phi2);
    double DeltaPhi(double phi1, double phi2);
};
#endif
