#include "TMath.h"
#include "analyzer_objects.h"
#include <iostream>
#include <math.h>

//----------------------------analyzer_objects
analyzer_objects::analyzer_objects() {}

//----------------------~analyzer_objects
analyzer_objects::~analyzer_objects() {}

std::vector<int> analyzer_objects::muonPassSel(Float_t muPtCut, Float_t muEtaCut) {
    std::vector<int> ids;
    passGoodMuon = false;

    for (int j = 0; j < nLeptons; j++) {
        if (abs(lepPdgId[j]) != 13)
            continue;
        
        cutFlow["Muon Exists"] += 1;

        if (lepPt[j] <= muPtCut) 
            continue;
        
        cutFlow["MuonPt > 7 GeV"] += 1;

        if (lepEta[j] >= fabs(muEtaCut)) 
            continue;
        
        cutFlow["abs(MuonEta) < 1.5"] += 1;

        if (!lepMuon_passHLTFilter[j]) 
            continue;
        
        cutFlow["MuonHLTRequirement"] += 1;

        if (lepMuonQuality[j] < pow(2, 25)) 
            continue;
        
        cutFlow["MuonQuality"] += 1;
        passGoodMuon = true;
        ids.push_back(j);
    }

    return ids;
}


//========================================================= Begin Region Definitions

//--------------------------------------------------------- Begin Test-OOT
std::vector<int> analyzer_objects::CscClusterPassSel_testOOT(bool passHLT) { 
    std::vector<int> ids;                                     
    if (!passHLT)
        return ids;
    else {
        
        
        for (int j = 0; j < nCscRechitClusters; j++) {
            if ( 
                   askDoesPassOverlapMuon_csc(j) 
                && askDoesPassME1112Veto_csc(j) 
                && askDoesPassMB1Veto_csc(j) 
                && askDoesPassRB1Veto_csc(j) 
                && askDoesPassMuonVeto_csc(j) 
                && !askDoesPassClusterTime_csc(j) 
                && askDoesPassClusterTimeSpread_csc(j) 
                && askDoesPassID_csc(j) 
                && !askDoesPassdPhiLeadMuon_csc(j) 
                && askDoesPassClusterEta_csc(j)
                // && askDoesOverlapGenLLP_csc(j) 
                // && askDoesPassClusterSize_csc(j)
            ) 
                
                ids.push_back(j);
        }
    }
    return ids;
}

std::vector<int> analyzer_objects::DtClusterPassSel_testOOT(bool passHLT) {
    std::vector<int> ids;
    if (!passHLT)
        return ids;
    else {

        
        for (int j = 0; j < nDtRechitClusters; j++) {
            if (
                   askDoesPassClusterSize_dt(j) 
                && askDoesPassOverlapMuon_dt(j) 
                && askDoesPassRPCMatching_dt(j) 
                && askDoesPassMuonVeto_dt(j) 
                && askDoesPassMB1Veto_dt(j) 
                && askDoesPassMB1Adjacent_dt(j)

                && !askDoesPassRPCTimeCut_dt(j) 
                && !askDoesPassMaxStation_dt(j)
            ) 
                
                ids.push_back(j);
        }
    }
    return ids;
}
//--------------------------------------------------------- End Test-OOT


//--------------------------------------------------------- Begin Test
std::vector<int> analyzer_objects::CscClusterPassSel_test(bool passHLT) {
    std::vector<int> ids;
    if (!passHLT)
        return ids;
    else {

        
        for (int j = 0; j < nCscRechitClusters; j++) {
            if (
                   askDoesPassOverlapMuon_csc(j) 
                && askDoesPassME1112Veto_csc(j) 
                && askDoesPassMB1Veto_csc(j) 
                && askDoesPassRB1Veto_csc(j) 
                && askDoesPassMuonVeto_csc(j) 
                && askDoesPassClusterTime_csc(j) 
                && askDoesPassClusterTimeSpread_csc(j) 
                && askDoesPassID_csc(j) 
                && !askDoesPassdPhiLeadMuon_csc(j) 
                && askDoesPassClusterEta_csc(j)
            ) 
                
                ids.push_back(j);
        }
    }
    return ids;
}

std::vector<int> analyzer_objects::DtClusterPassSel_test(bool passHLT) {
    std::vector<int> ids;
    if (!passHLT)
        return ids;
    else {

        
        for (int j = 0; j < nDtRechitClusters; j++) {
            if (
                   askDoesPassClusterSize_dt(j) 
                && askDoesPassOverlapMuon_dt(j) 
                && askDoesPassRPCMatching_dt(j) 
                && askDoesPassMuonVeto_dt(j) 
                && askDoesPassMB1Veto_dt(j) 
                && askDoesPassMB1Adjacent_dt(j)

                && askDoesPassRPCTimeCut_dt(j) 
                && !askDoesPassMaxStation_dt(j)
            ) 
                
                ids.push_back(j);
        }
    }
    return ids;
}
//--------------------------------------------------------- End Test

//--------------------------------------------------------- Begin OOT
std::vector<int> analyzer_objects::CscClusterPassSel_OOT(bool passHLT) {
    std::vector<int> ids;
    if (!passHLT)
        return ids;
    else {

        
        for (int j = 0; j < nCscRechitClusters; j++) {
            if (
                   askDoesPassOverlapMuon_csc(j) 
                && askDoesPassME1112Veto_csc(j) 
                && askDoesPassMB1Veto_csc(j) 
                && askDoesPassRB1Veto_csc(j) 
                && askDoesPassMuonVeto_csc(j) 
                && !askDoesPassClusterTime_csc(j) 
                && askDoesPassClusterTimeSpread_csc(j) 
                && askDoesPassdPhiLeadMuon_csc(j) 
                && askDoesPassClusterEta_csc(j) 
                && askDoesPassID_csc(j)
                // && askDoesOverlapGenLLP_csc(j) 
                // && askDoesPassClusterSize_csc(j)
            ) 
                
                ids.push_back(j);
        }
    }
    return ids;
}

std::vector<int> analyzer_objects::DtClusterPassSel_OOT(bool passHLT) {
    std::vector<int> ids;
    if (!passHLT)
        return ids;
    else {

        
        for (int j = 0; j < nDtRechitClusters; j++) {
            if (
                   askDoesPassClusterSize_dt(j) 
                && askDoesPassOverlapMuon_dt(j) 
                && askDoesPassRPCMatching_dt(j) 
                && askDoesPassMuonVeto_dt(j) 
                && askDoesPassMB1Veto_dt(j) 
                && askDoesPassMB1Adjacent_dt(j)

                && !askDoesPassRPCTimeCut_dt(j) 
                && askDoesPassMaxStation_dt(j)
            ) 
                
                ids.push_back(j);
        }
    }
    return ids;
}
//--------------------------------------------------------- End OOT

//--------------------------------------------------------- Begin SR
std::vector<int> analyzer_objects::CscClusterPassSel_SR(bool passHLT) {
    std::vector<int> ids;
    if (!passHLT)
        return ids;
    else {

        
        for (int j = 0; j < nCscRechitClusters; j++) {
            if (
                   askDoesPassClusterSize_csc(j) 
                && askDoesPassOverlapMuon_csc(j) 
                && askDoesPassME1112Veto_csc(j) 
                && askDoesPassMB1Veto_csc(j) 
                && askDoesPassRB1Veto_csc(j) 
                && askDoesPassMuonVeto_csc(j) 
                && askDoesPassClusterTime_csc(j) 
                && askDoesPassClusterTimeSpread_csc(j) 
                && askDoesPassdPhiLeadMuon_csc(j) 
                && askDoesPassClusterEta_csc(j) 
                && askDoesPassID_csc(j)
                // && askDoesOverlapGenLLP_csc(j)
                ){
                    
                    ids.push_back(j);
                
                    counter++;
            }
        }
    }
    return ids;
}

std::vector<int> analyzer_objects::DtClusterPassSel_SR(bool passHLT) {
    std::vector<int> ids;
    if (!passHLT)
        return ids;
    else {

        
        for (int j = 0; j < nDtRechitClusters; j++) {
            if (
                   askDoesPassClusterSize_dt(j) 
                && askDoesPassOverlapMuon_dt(j) 
                && askDoesPassRPCMatching_dt(j) 
                && askDoesPassMuonVeto_dt(j) 
                && askDoesPassMB1Veto_dt(j) 
                && askDoesPassMB1Adjacent_dt(j)

                && askDoesPassRPCTimeCut_dt(j) 
                && askDoesPassMaxStation_dt(j)
            ) 
                
                ids.push_back(j);
        }
    }
    return ids;
}
//--------------------------------------------------------- End SR

//========================================================= Ends Region Definitions



//========================================================= Begin Cutflow Stuff
void analyzer_objects::DtClusterPassSel_CutFlow() {
    double dR_mu, dR_LLP;

    if (nDtRechitClusters > 0) cutFlow["nDtRechitClusters > 0"] += 1;


    for (int j = 0; j < nDtRechitClusters; j++) {
        dR_mu = muon_list.size() > 0 ? dR(lepEta[muon_list[0]], lepPhi[muon_list[0]], dtRechitClusterEta[j], dtRechitClusterPhi[j]) : 0.0;
        dR_LLP = dR(gLLP_eta, gLLP_phi, dtRechitClusterEta[j], dtRechitClusterPhi[j]);

        if (dtRechitClusterSize[j] < DtSize) continue;
        cutFlow["DtClusterSize >= 50"] += 1;

        if (dR_mu <= dr_LeadMu_DtCluster) continue;
        cutFlow["DtPassOverlapLeadMuon"] += 1;

        if (isMC && dR_LLP >= dr_GenMu_DtCluster) continue;
        cutFlow["DtOverlapGenLLP"] += 1;

        if (dtRechitCluster_match_RPChits_dPhi0p5[j] <= 0) continue;
        cutFlow["DtPassRPCMatching"] += 1;

        if (dtRechitClusterMuonVetoPt[j] >= DtMuonVetoPt) continue;
        cutFlow["DtPassMuonVeto"] += 1;

        if (dtRechitCluster_match_MB1hits_0p5[j] > DtMB1Veto) continue;
        cutFlow["DtPassMB1Veto"] += 1;

        if (dtRechitCluster_match_RPCBx_dPhi0p5[j] != 0) continue;
        cutFlow["DtPassRPCTimeCut"] += 1;

        if (dtRechitCluster_match_MB1hits_cosmics_plus[j] > 8 || dtRechitCluster_match_MB1hits_cosmics_minus[j] > 8) continue;
        cutFlow["DtPassMB1Adjacent"] += 1;
    }
}


void analyzer_objects::CscClusterPassSel_CutFlow() {
    double dR_mu, dR_LLP;

    if (nCscRechitClusters > 0) cutFlow["nCscRechitClusters > 0"] += 1;


    for (int j = 0; j < nCscRechitClusters; j++) {
        dR_mu = muon_list.size() > 0 ? dR(lepEta[muon_list[0]], lepPhi[muon_list[0]], cscRechitClusterEta[j], cscRechitClusterPhi[j]) : 0.0;
        dR_LLP = dR(gLLP_eta, gLLP_phi, cscRechitClusterEta[j], cscRechitClusterPhi[j]);

        if (cscRechitClusterSize[j] < CscSize) continue;
        cutFlow["CscClusterSize >= 0"] += 1;

        if (dR_mu <= dr_LeadMu_CscCluster) continue;
        cutFlow["CscPassOverlapLeadMuon"] += 1;

        if (isMC && dR_LLP >= dr_GenMu_CscCluster) continue;
        cutFlow["CscOverlapGenLLP"] += 1;

        if (cscRechitClusterNRechitChamberPlus11[j] > 0 || cscRechitClusterNRechitChamberMinus11[j] > 0 || cscRechitClusterNRechitChamberPlus12[j] > 0 || cscRechitClusterNRechitChamberMinus12[j] > 0) continue;
        cutFlow["CscPassME1112Veto"] += 1;

        if (cscRechitCluster_match_MB1Seg_0p4[j] != 0) continue;
        cutFlow["CscPassMB1Veto"] += 1;

        if (cscRechitCluster_match_RB1_0p4[j] != 0) continue;
        cutFlow["CscPassRB1Veto"] += 1;

        if (cscRechitClusterMuonVetoPt[j] >= CscMuonVetoPt) continue;
        cutFlow["CscPassMuonVeto"] += 1;

        if (cscRechitClusterTimeWeighted[j] < cscClusterTimeLow || cscRechitClusterTimeWeighted[j] > cscClusterTimeHigh) continue;
        cutFlow["CscPassClusterTime"] += 1;

        if (cscRechitClusterTimeSpreadWeightedAll[j] > cscClusterTimeSpread) continue;
        cutFlow["CscPassClusterTimeSpread"] += 1;

        if (fabs(cscRechitClusterEta[j]) >= CscEta) continue;
        cutFlow["CscPassClusterEta"] += 1;

        bool PassID = (cscRechitClusterNStation10[j] > 1 && fabs(cscRechitClusterEta[j]) < 1.9) ||
                      (cscRechitClusterNStation10[j] == 1 && fabs(cscRechitClusterAvgStation10[j]) == 4 && fabs(cscRechitClusterEta[j]) < 1.8) ||
                      (cscRechitClusterNStation10[j] == 1 && fabs(cscRechitClusterAvgStation10[j]) == 3 && fabs(cscRechitClusterEta[j]) < 1.5) ||
                      (cscRechitClusterNStation10[j] == 1 && fabs(cscRechitClusterAvgStation10[j]) == 2 && fabs(cscRechitClusterEta[j]) < 1.7) ||
                      (cscRechitClusterNStation10[j] == 1 && fabs(cscRechitClusterAvgStation10[j]) == 1 && fabs(cscRechitClusterEta[j]) < 1.0);
        if (!PassID) continue;
        cutFlow["CscPassID"] += 1;
    }
}
//========================================================= End Cutflow Stuff


//========================================================= Begin Geometric functions
//--------------------------------------------------------- dR
double analyzer_objects::dR(double eta1, double phi1, double eta2, double phi2) {
    double deltaeta = abs(eta1 - eta2);
    double deltaphi = DeltaPhi(phi1, phi2);
    return sqrt(deltaeta * deltaeta + deltaphi * deltaphi);
}

//--------------------------------------------------------- DeltaPhi
// Gives the (minimum) separation in phi between the specified phi values
// Must return a positive value
double analyzer_objects::DeltaPhi(double phi1, double phi2){
    double pi = TMath::Pi();
    double dphi = fabs(phi1 - phi2);
    return (dphi > pi) ? (2.0 * pi - dphi) : dphi;
}
//========================================================= End Geometric functions

//========================================================= Begin Selection booleans
//--------------------------------------------------------- Begin DTs
bool analyzer_objects::askDoesPassOverlapMuon_dt(int index) {
    double dR_mu = (muon_list.size() > 0) ? dR(lepEta[muon_list[0]], lepPhi[muon_list[0]], dtRechitClusterEta[index], dtRechitClusterPhi[index]) : 0.0;
    return (dR_mu > dr_LeadMu_DtCluster);
}

bool analyzer_objects::askDoesPassdPhiLeadMuon_dt(int index) {
    double dPhi = (muon_list.size() > 0) ? DeltaPhi(lepPhi[muon_list[0]], dtRechitClusterPhi[index]) : -999.0;
    return (dPhi > dPhiCut_LeadMu_DtCluster);
}

bool analyzer_objects::askDoesPassClusterEta_dt(int index) {
    return (std::fabs(dtRechitClusterEta[index]) < DtEta);
}

bool analyzer_objects::askDoesOverlapGenMuon_dt(int index) {
    if (!isMC) return true; // If Data, this cut does nothing
    double dR_LLP = dR(gLLP_eta, gLLP_phi, dtRechitClusterEta[index], dtRechitClusterPhi[index]);
    return (dR_LLP < dr_GenMu_DtCluster);
}

bool analyzer_objects::askDoesPassClusterSize_dt(int index) {
    return (dtRechitClusterSize[index] >= DtSize);
}

bool analyzer_objects::askDoesPassRPCMatching_dt(int index) {
    return (dtRechitCluster_match_RPCBx_dPhi0p5 [index] > 0);
}

bool analyzer_objects::askDoesPassMuonVeto_dt(int index) {
    return (dtRechitClusterMuonVetoPt[index] < DtMuonVetoPt);
}

bool analyzer_objects::askDoesPassMB1Veto_dt(int index) {
    return (dtRechitCluster_match_MB1hits_0p5[index] <= DtMB1Veto);
}

bool analyzer_objects::askDoesPassRPCTimeCut_dt(int index) {
    return (dtRechitCluster_match_RPCBx_dPhi0p5[index] == 0);
}

bool analyzer_objects::askDoesPassMB1Adjacent_dt(int index) {
    return (dtRechitCluster_match_MB1hits_cosmics_plus[index] <= 8 &&
            dtRechitCluster_match_MB1hits_cosmics_minus[index] <= 8);
}

bool analyzer_objects::askDoesPassMaxStation_dt(int index) {
    return (dtRechitClusterMaxStation[index] >= 3);
}

//--------------------------------------------------------- End DTs


//--------------------------------------------------------- Begin CSCs
bool analyzer_objects::askDoesPassClusterSize_csc(int index) {
    return (cscRechitClusterSize[index] >= CscSize);
}

bool analyzer_objects::askDoesPassOverlapMuon_csc(int index) {
    double dR_mu = (muon_list.size() > 0) ? dR(lepEta[muon_list[0]], lepPhi[muon_list[0]], cscRechitClusterEta[index], cscRechitClusterPhi[index]) : 0.0;
    return (dR_mu > dr_LeadMu_CscCluster);
}

bool analyzer_objects::askDoesPassdPhiLeadMuon_csc(int index) {
    double dPhi = (muon_list.size() > 0) ? DeltaPhi(lepPhi[muon_list[0]], cscRechitClusterPhi[index]) : -999.0;
    return (dPhi > dPhiCut_LeadMu_CscCluster);
}

bool analyzer_objects::askDoesOverlapGenLLP_csc(int index) {
    if (!isMC) return true; // If Data, this cut does nothing
    double dR_LLP = dR(gLLP_eta, gLLP_phi, cscRechitClusterEta[index], cscRechitClusterPhi[index]);
    return (dR_LLP < dr_GenMu_CscCluster);
}

bool analyzer_objects::askDoesPassME1112Veto_csc(int index) {
    return (cscRechitClusterNRechitChamberPlus11[index] <= 0 &&
            cscRechitClusterNRechitChamberMinus11[index] <= 0 &&
            cscRechitClusterNRechitChamberPlus12[index] <= 0 &&
            cscRechitClusterNRechitChamberMinus12[index] <= 0);
}

bool analyzer_objects::askDoesPassMB1Veto_csc(int index) {
    return (cscRechitCluster_match_MB1Seg_0p4[index] == 0);
}

bool analyzer_objects::askDoesPassRB1Veto_csc(int index) {
    return (cscRechitCluster_match_RB1_0p4[index] == 0);
}

bool analyzer_objects::askDoesPassMuonVeto_csc(int index) {
    return (cscRechitClusterMuonVetoPt[index] < CscMuonVetoPt);
}

bool analyzer_objects::askDoesPassClusterTime_csc(int index) {
    return (cscRechitClusterTimeWeighted[index] >= cscClusterTimeLow &&
            cscRechitClusterTimeWeighted[index] <= cscClusterTimeHigh);
}

bool analyzer_objects::askDoesPassClusterTimeSpread_csc(int index) {
    return (cscRechitClusterTimeSpreadWeightedAll[index] <= cscClusterTimeSpread);
}

bool analyzer_objects::askDoesPassClusterEta_csc(int index) {
    return (std::fabs(cscRechitClusterEta[index]) < CscEta);
}

bool analyzer_objects::askDoesPassID_csc(int index) {
    return ((cscRechitClusterNStation10[index] > 1 && std::fabs(cscRechitClusterEta[index]) < 1.8) ||
            (cscRechitClusterNStation10[index] == 1 && std::fabs(cscRechitClusterAvgStation10[index]) == 4 && std::fabs(cscRechitClusterEta[index]) < 1.8) ||
            (cscRechitClusterNStation10[index] == 1 && std::fabs(cscRechitClusterAvgStation10[index]) == 3 && std::fabs(cscRechitClusterEta[index]) < 1.6) ||
            (cscRechitClusterNStation10[index] == 1 && std::fabs(cscRechitClusterAvgStation10[index]) == 2 && std::fabs(cscRechitClusterEta[index]) < 1.7) ||
            (cscRechitClusterNStation10[index] == 1 && std::fabs(cscRechitClusterAvgStation10[index]) == 1 && std::fabs(cscRechitClusterEta[index]) < 1.1));
}
//--------------------------------------------------------- End CSCs
//========================================================= End Selection booleans