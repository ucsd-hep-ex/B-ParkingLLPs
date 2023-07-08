#include "TMath.h"
#include "analyzer_objects.h"
#include <iostream>
#include <math.h>

//----------------------------analyzer_objects
analyzer_objects::analyzer_objects() {}

//----------------------~analyzer_objects
analyzer_objects::~analyzer_objects() {}

std::vector<int> analyzer_objects::muonPassSel(Float_t muPtCut,
                                               Float_t muEtaCut) {
  std::vector<int> ids;
  bool MuonExists = false;
  bool MuonPassPt = false;
  bool MuonPassEta = false;
  bool MuonPassHLTFilter = false;
  bool MuonPassQuality = false;
  passGoodMuon = false;
  for (int j = 0; j < nLeptons; j++) {
    if (abs(lepPdgId[j]) != 13)
      continue;
    MuonExists = true;
    if (lepPt[j] > muPtCut) {
      MuonPassPt = true;
      if (lepEta[j] < fabs(muEtaCut)) {
        MuonPassEta = true;
        if (lepMuon_passHLTFilter[j]) {
          MuonPassHLTFilter = true;
          if (lepMuonQuality[j] >= pow(2, 25)) {
            MuonPassQuality = true;
            passGoodMuon = true;
            ids.push_back(j);
          }
        }
      }
    }
  }
  if (MuonExists)
    cutFlow["Muon Exists"] += 1;
  if (MuonPassPt)
    cutFlow["MuonPt > 7 GeV"] += 1;
  if (MuonPassEta)
    cutFlow["abs(MuonEta) < 1.5"] += 1;
  if (MuonPassHLTFilter)
    cutFlow["MuonHLTRequirement"] += 1;
  if (MuonPassQuality)
    cutFlow["MuonQuality"] += 1;
  return ids;
}

//--------- Region Definitions

//-------- Test-OOT Selections                                         // loggit
std::vector<int>
analyzer_objects::CscClusterPassSel_testOOT(bool passHLT) { // loggit
  std::vector<int> ids;                                     // loggit
  if (!passHLT)
    return ids;
  else {
    for (int j = 0; j < nCscRechitClusters; j++) { // loggit
      if (                                         // loggit
           // askDoesPassClusterSize_csc(j)        &&                      //
           // loggit
          askDoesPassOverlapMuon_csc(j) &&       // loggit
          askDoesPassME1112Veto_csc(j) &&        // loggit
          askDoesPassMB1Veto_csc(j) &&           // loggit
          askDoesPassRB1Veto_csc(j) &&           // loggit
          askDoesPassMuonVeto_csc(j) &&          // loggit
          !askDoesPassClusterTime_csc(j) &&      // loggit
          askDoesPassClusterTimeSpread_csc(j) && // loggit
          askDoesPassID_csc(j) &&                // loggit
          !askDoesPassdPhiLeadMuon_csc(j) &&     // loggit
          askDoesPassClusterEta_csc(j) //&&                      // loggit
          // askDoesOverlapGenLLP_csc(j)          &&                      //
          // loggit
      )
        ids.push_back(j); // loggit
    }                     // loggit
  }
  return ids; // loggit
} // loggit

std::vector<int>
analyzer_objects::DtClusterPassSel_testOOT(bool passHLT) { // loggit
  std::vector<int> ids;                                    // loggit
  if (!passHLT)
    return ids;
  else {
    for (int j = 0; j < nDtRechitClusters; j++) { // loggit
      if (                                        // loggit
           // askDoesPassClusterSize_dt(j) &&                              //
           // loggit
          askDoesPassOverlapMuon_dt(j) && // loggit
          askDoesPassRPCMatching_dt(j) && // loggit
          askDoesPassRPCTimeCut_dt(j) &&  // loggit
          askDoesPassMB1Adjacent_dt(j) && // loggit
          askDoesPassMB1Veto_dt(j) &&     // loggit
          askDoesPassMuonVeto_dt(j) //&&                              // loggit
          // askDoesPassClusterEta_dt(j)         //&&                     //
          // loggit askDoesOverlapGenMuon_dt(j)  && // loggit
      )
        ids.push_back(j); // loggit
    }                     // loggit
  }
  return ids; // loggit
} // loggit

//-------- Test Selections                                             // loggit
std::vector<int>
analyzer_objects::CscClusterPassSel_test(bool passHLT) { // loggit
  std::vector<int> ids;                                  // loggit
  if (!passHLT)
    return ids;
  else {
    for (int j = 0; j < nCscRechitClusters; j++) { // loggit
      if (                                         // loggit
           // askDoesPassClusterSize_csc(j)        &&                      //
           // loggit
          askDoesPassOverlapMuon_csc(j) &&       // loggit
          askDoesPassME1112Veto_csc(j) &&        // loggit
          askDoesPassMB1Veto_csc(j) &&           // loggit
          askDoesPassRB1Veto_csc(j) &&           // loggit
          askDoesPassMuonVeto_csc(j) &&          // loggit
          askDoesPassClusterTime_csc(j) &&       // loggit
          askDoesPassClusterTimeSpread_csc(j) && // loggit
          askDoesPassID_csc(j) &&                // loggit
          !askDoesPassdPhiLeadMuon_csc(j) &&     // loggit
          askDoesPassClusterEta_csc(j) //&&                      // loggit
          // askDoesOverlapGenLLP_csc(j)          &&                      //
          // loggit
      )
        ids.push_back(j); // loggit
    }                     // loggit
  }
  return ids; // loggit
} // loggit

std::vector<int>
analyzer_objects::DtClusterPassSel_test(bool passHLT) { // loggit
  std::vector<int> ids;                                 // loggit
  if (!passHLT)
    return ids;
  else {
    for (int j = 0; j < nDtRechitClusters; j++) { // loggit
      if (                                        // loggit
           // askDoesPassClusterSize_dt(j) &&                              //
           // loggit
          askDoesPassOverlapMuon_dt(j) && // loggit
          askDoesPassRPCMatching_dt(j) && // loggit
          askDoesPassRPCTimeCut_dt(j) &&  // loggit
          askDoesPassMB1Adjacent_dt(j) && // loggit
          askDoesPassMB1Veto_dt(j) &&     // loggit
          askDoesPassMuonVeto_dt(j) //&&                              // loggit
          // askDoesPassClusterEta_dt(j)         //&&                     //
          // loggit askDoesOverlapGenMuon_dt(j)  && // loggit
      )
        ids.push_back(j); // loggit
    }                     // loggit
  }
  return ids; // loggit
} // loggit
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------- Out of Time Region                              //
//loggit
std::vector<int>
analyzer_objects::CscClusterPassSel_OOT(bool passHLT) { // loggit
  std::vector<int> ids;                                 // loggit
  if (!passHLT)
    return ids;
  else {
    for (int j = 0; j < nCscRechitClusters; j++) { // loggit
      if (                                         // loggit
           // askDoesPassClusterSize_csc(j)        &&                         //
           // loggit
          askDoesPassOverlapMuon_csc(j) &&       // loggit
          askDoesPassME1112Veto_csc(j) &&        // loggit
          askDoesPassMB1Veto_csc(j) &&           // loggit
          askDoesPassRB1Veto_csc(j) &&           // loggit
          askDoesPassMuonVeto_csc(j) &&          // loggit
          !askDoesPassClusterTime_csc(j) &&      // loggit
          askDoesPassClusterTimeSpread_csc(j) && // loggit
          askDoesPassdPhiLeadMuon_csc(j) &&      // loggit
          askDoesPassClusterEta_csc(j) &&        // loggit
          // askDoesOverlapGenLLP_csc(j)          &&                         //
          // loggit
          askDoesPassID_csc(j))
        ids.push_back(j); // loggit
    }                     // loggit
  }
  return ids; // loggit
} // loggit

std::vector<int>
analyzer_objects::DtClusterPassSel_OOT(bool passHLT) { // loggit
  std::vector<int> ids;                                // loggit
  if (!passHLT)
    return ids;
  else {
    for (int j = 0; j < nDtRechitClusters; j++) { // loggit
      if (                                        // loggit
          askDoesPassClusterSize_dt(j) &&         // loggit
          askDoesPassOverlapMuon_dt(j) &&         // loggit
          askDoesOverlapGenMuon_dt(j) &&          // loggit
          askDoesPassRPCMatching_dt(j) &&         // loggit
          askDoesPassMuonVeto_dt(j) &&            // loggit
          askDoesPassMB1Veto_dt(j) &&             // loggit
          !askDoesPassRPCTimeCut_dt(j) &&         // loggit
          // askDoesPassClusterEta_dt(j)         //&&                     //
          // loggit
          askDoesPassMB1Adjacent_dt(j))
        ids.push_back(j); // loggit
    }                     // loggit
  }
  return ids; // loggit
} // loggit
////////////////////////////////////////////////////
//--------------------- Signal Region                                  // loggit
std::vector<int>
analyzer_objects::CscClusterPassSel_SR(bool passHLT) { // loggit
  std::vector<int> ids;                                // loggit
  if (!passHLT)
    return ids;
  else {
    for (int j = 0; j < nCscRechitClusters; j++) { // loggit
      if (                                         // loggit
          askDoesPassClusterSize_csc(j) &&         // loggit
          askDoesPassOverlapMuon_csc(j) &&         // loggit
          // askDoesOverlapGenLLP_csc(j)          &&                        //
          // loggit
          askDoesPassME1112Veto_csc(j) &&        // loggit
          askDoesPassMB1Veto_csc(j) &&           // loggit
          askDoesPassRB1Veto_csc(j) &&           // loggit
          askDoesPassMuonVeto_csc(j) &&          // loggit
          askDoesPassClusterTime_csc(j) &&       // loggit
          askDoesPassClusterTimeSpread_csc(j) && // loggit
          askDoesPassdPhiLeadMuon_csc(j) &&      // loggit
          askDoesPassClusterEta_csc(j) &&        // loggit
          askDoesPassID_csc(j)) {                // loggit
        ids.push_back(j);                        // loggit
        counter++;
      } // loggit
    }   // loggit
  }
  return ids; // loggit
} // loggit

std::vector<int> analyzer_objects::DtClusterPassSel_SR(bool passHLT) { // loggit
  std::vector<int> ids;                                                // loggit
  if (!passHLT)
    return ids;
  else {
    for (int j = 0; j < nDtRechitClusters; j++) { // loggit
      if (                                        // loggit
          askDoesPassClusterSize_dt(j) &&         // loggit
          askDoesPassOverlapMuon_dt(j) &&         // loggit
          askDoesOverlapGenMuon_dt(j) &&          // loggit
          askDoesPassRPCMatching_dt(j) &&         // loggit
          askDoesPassMuonVeto_dt(j) &&            // loggit
          askDoesPassMB1Veto_dt(j) &&             // loggit
          askDoesPassRPCTimeCut_dt(j) &&          // loggit
          // askDoesPassClusterEta_dt(j)         //&&                     //
          // loggit
          askDoesPassMB1Adjacent_dt(j))
        ids.push_back(j); // loggit
    }                     // loggit
  }
  return ids; // loggit
} // loggit
////////////////////////////////////////////////////

// ----CutFlow Table stuff
void analyzer_objects::DtClusterPassSel_CutFlow() {
  double dR_mu;
  double dR_LLP;
  bool PassAll = false;
  bool PassClusterSize = false;
  bool PassOverlapMuon = false;
  bool OverlapGenMuon = false;
  bool PassRPCMatching = false;
  bool PassMuonVeto = false;
  bool PassMB1Veto = false;
  bool PassRPCTimeCut = false;
  bool PassMB1Adjacent = false;
  if (isMC) {
    for (int j = 0; j < nDtRechitClusters; j++) {
      if (muon_list.size() > 0)
        dR_mu = dR(lepEta[muon_list[0]], lepPhi[muon_list[0]],
                   dtRechitClusterEta[j], dtRechitClusterPhi[j]);
      else
        dR_mu = 0.0;
      dR_LLP =
          dR(gLLP_eta, gLLP_phi, dtRechitClusterEta[j], dtRechitClusterPhi[j]);
      if (dtRechitClusterSize[j] >= DtSize) {
        PassClusterSize = true;
        if (dR_mu > dr_LeadMu_DtCluster) {
          PassOverlapMuon = true;
          if (dR_LLP < dr_GenMu_DtCluster) {
            OverlapGenMuon = true;
            if (dtRechitCluster_match_RPChits_dPhi0p5[j] > 0) {
              PassRPCMatching = true;
              if (dtRechitClusterMuonVetoPt[j] < DtMuonVetoPt) {
                PassMuonVeto = true;
                if (dtRechitCluster_match_MB1hits_0p5[j] <= DtMB1Veto) {
                  PassMB1Veto = true;
                  if (dtRechitCluster_match_RPCBx_dPhi0p5[j] == 0) {
                    PassRPCTimeCut = true;
                    if (dtRechitCluster_match_MB1hits_cosmics_plus[j] <= 8 &&
                        dtRechitCluster_match_MB1hits_cosmics_minus[j] <= 8) {
                      PassMB1Adjacent = true;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  } else {
    OverlapGenMuon = true;
    for (int j = 0; j < nDtRechitClusters; j++) {
      if (muon_list.size() > 0)
        dR_mu = dR(lepEta[muon_list[0]], lepPhi[muon_list[0]],
                   dtRechitClusterEta[j], dtRechitClusterPhi[j]);
      else
        dR_mu = 0.0;
      dR_LLP =
          dR(gLLP_eta, gLLP_phi, dtRechitClusterEta[j], dtRechitClusterPhi[j]);
      if (dtRechitClusterSize[j] >= DtSize) {
        PassClusterSize = true;
        if (dR_mu > dr_LeadMu_DtCluster) {
          PassOverlapMuon = true;
          if (dtRechitCluster_match_RPChits_dPhi0p5[j] > 0) {
            PassRPCMatching = true;
            if (dtRechitClusterMuonVetoPt[j] < DtMuonVetoPt) {
              PassMuonVeto = true;
              if (dtRechitCluster_match_MB1hits_0p5[j] <= DtMB1Veto) {
                PassMB1Veto = true;
                if (dtRechitCluster_match_RPCBx_dPhi0p5[j] == 0) {
                  PassRPCTimeCut = true;
                  if (dtRechitCluster_match_MB1hits_cosmics_plus[j] <= 8 &&
                      dtRechitCluster_match_MB1hits_cosmics_minus[j] <= 8) {
                    PassMB1Adjacent = true;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (nDtRechitClusters > 0)
    cutFlow["nDtRechitClusters > 0"] += 1;
  if (PassClusterSize)
    cutFlow["DtClusterSize >= 50"] += 1;
  if (PassOverlapMuon)
    cutFlow["DtPassOverlapLeadMuon"] += 1;
  if (OverlapGenMuon)
    cutFlow["DtOverlapGenLLP"] += 1;
  if (PassRPCMatching)
    cutFlow["DtPassRPCMatching"] += 1;
  if (PassMuonVeto)
    cutFlow["DtPassMuonVeto"] += 1;
  if (PassMB1Veto)
    cutFlow["DtPassMB1Veto"] += 1;
  if (PassRPCTimeCut)
    cutFlow["DtPassRPCTimeCut"] += 1;
  if (PassMB1Adjacent)
    cutFlow["DtPassMB1Adjacent"] += 1;
}

void analyzer_objects::CscClusterPassSel_CutFlow() {
  double dR_mu;
  double dR_LLP;
  bool PassClusterSize = false;
  bool PassOverlapMuon = false;
  bool OverlapGenLLP = false;
  bool PassME1112Veto = false;
  bool PassMB1Veto = false;
  bool PassRB1Veto = false;
  bool PassMuonVeto = false;
  bool PassClusterTime = false;
  bool PassClusterTimeSpread = false;
  bool PassClusterEta = false;
  bool PassID = false;
  if (isMC) {
    for (int j = 0; j < nCscRechitClusters; j++) {
      if (muon_list.size() > 0)
        dR_mu = dR(lepEta[muon_list[0]], lepPhi[muon_list[0]],
                   cscRechitClusterEta[j], cscRechitClusterPhi[j]);
      else
        dR_mu = 0.0;
      dR_LLP = dR(gLLP_eta, gLLP_phi, cscRechitClusterEta[j],
                  cscRechitClusterPhi[j]);
      if (cscRechitClusterSize[j] >= CscSize) {
        PassClusterSize = true;
        if (dR_mu > dr_LeadMu_CscCluster) {
          PassOverlapMuon = true;
          if (dR_LLP < dr_GenMu_CscCluster) {
            OverlapGenLLP = true;
            if (cscRechitClusterNRechitChamberPlus11[j] <= 0 &&
                cscRechitClusterNRechitChamberMinus11[j] <= 0 &&
                cscRechitClusterNRechitChamberPlus12[j] <= 0 &&
                cscRechitClusterNRechitChamberMinus12[j] <= 0) {
              PassME1112Veto = true;
              if (cscRechitCluster_match_MB1Seg_0p4[j] == 0) {
                PassMB1Veto = true;
                if (cscRechitCluster_match_RB1_0p4[j] == 0) {
                  PassRB1Veto = true;
                  if (cscRechitClusterMuonVetoPt[j] < CscMuonVetoPt) {
                    PassMuonVeto = true;
                    if (cscRechitClusterTimeWeighted[j] >= cscClusterTimeLow &&
                        cscRechitClusterTimeWeighted[j] <= cscClusterTimeHigh) {
                      PassClusterTime = true;
                      if (cscRechitClusterTimeSpreadWeightedAll[j] <=
                          cscClusterTimeSpread) {
                        PassClusterTimeSpread = true;
                        if (fabs(cscRechitClusterEta[j]) < CscEta) {
                          PassClusterEta = true;
                          if ((cscRechitClusterNStation10[j] > 1 &&
                               fabs(cscRechitClusterEta[j]) < 1.9) ||
                              (cscRechitClusterNStation10[j] == 1 &&
                               fabs(cscRechitClusterAvgStation10[j]) == 4 &&
                               fabs(cscRechitClusterEta[j]) < 1.8) ||
                              (cscRechitClusterNStation10[j] == 1 &&
                               fabs(cscRechitClusterAvgStation10[j]) == 3 &&
                               fabs(cscRechitClusterEta[j]) < 1.5) ||
                              (cscRechitClusterNStation10[j] == 1 &&
                               fabs(cscRechitClusterAvgStation10[j]) == 2 &&
                               fabs(cscRechitClusterEta[j]) < 1.7) ||
                              (cscRechitClusterNStation10[j] == 1 &&
                               fabs(cscRechitClusterAvgStation10[j]) == 1 &&
                               fabs(cscRechitClusterEta[j]) < 1.0)) {
                            PassID = true;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  } else {
    OverlapGenLLP = true;
    for (int j = 0; j < nCscRechitClusters; j++) {
      if (muon_list.size() > 0)
        dR_mu = dR(lepEta[muon_list[0]], lepPhi[muon_list[0]],
                   cscRechitClusterEta[j], cscRechitClusterPhi[j]);
      else
        dR_mu = 0.0;
      dR_LLP = dR(gLLP_eta, gLLP_phi, cscRechitClusterEta[j],
                  cscRechitClusterPhi[j]);
      if (cscRechitClusterSize[j] >= CscSize) {
        PassClusterSize = true;
        if (dR_mu > dr_LeadMu_CscCluster) {
          PassOverlapMuon = true;
          if (cscRechitClusterNRechitChamberPlus11[j] <= 0 &&
              cscRechitClusterNRechitChamberMinus11[j] <= 0 &&
              cscRechitClusterNRechitChamberPlus12[j] <= 0 &&
              cscRechitClusterNRechitChamberMinus12[j] <= 0) {
            PassME1112Veto = true;
            if (cscRechitCluster_match_MB1Seg_0p4[j] == 0) {
              PassMB1Veto = true;
              if (cscRechitCluster_match_RB1_0p4[j] == 0) {
                PassRB1Veto = true;
                if (cscRechitClusterMuonVetoPt[j] < CscMuonVetoPt) {
                  PassMuonVeto = true;
                  if (cscRechitClusterTimeWeighted[j] >= cscClusterTimeLow &&
                      cscRechitClusterTimeWeighted[j] <= cscClusterTimeHigh) {
                    PassClusterTime = true;
                    if (cscRechitClusterTimeSpreadWeightedAll[j] <=
                        cscClusterTimeSpread) {
                      PassClusterTimeSpread = true;
                      if (fabs(cscRechitClusterEta[j]) < CscEta) {
                        PassClusterEta = true;
                        if ((cscRechitClusterNStation10[j] > 1 &&
                             fabs(cscRechitClusterEta[j]) < 1.9) ||
                            (cscRechitClusterNStation10[j] == 1 &&
                             fabs(cscRechitClusterAvgStation10[j]) == 4 &&
                             fabs(cscRechitClusterEta[j]) < 1.8) ||
                            (cscRechitClusterNStation10[j] == 1 &&
                             fabs(cscRechitClusterAvgStation10[j]) == 3 &&
                             fabs(cscRechitClusterEta[j]) < 1.5) ||
                            (cscRechitClusterNStation10[j] == 1 &&
                             fabs(cscRechitClusterAvgStation10[j]) == 2 &&
                             fabs(cscRechitClusterEta[j]) < 1.7) ||
                            (cscRechitClusterNStation10[j] == 1 &&
                             fabs(cscRechitClusterAvgStation10[j]) == 1 &&
                             fabs(cscRechitClusterEta[j]) < 1.0)) {
                          PassID = true;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (nCscRechitClusters > 0)
    cutFlow["nCscRechitClusters > 0"] += 1;
  if (PassClusterSize)
    cutFlow["CscClusterSize >= 0"] += 1;
  if (PassOverlapMuon)
    cutFlow["CscPassOverlapLeadMuon"] += 1;
  if (OverlapGenLLP)
    cutFlow["CscOverlapGenLLP"] += 1;
  if (PassME1112Veto)
    cutFlow["CscPassME1112Veto"] += 1;
  if (PassMB1Veto)
    cutFlow["CscPassMB1Veto"] += 1;
  if (PassRB1Veto)
    cutFlow["CscPassRB1Veto"] += 1;
  if (PassMuonVeto)
    cutFlow["CscPassMuonVeto"] += 1;
  if (PassClusterTime)
    cutFlow["CscPassClusterTime"] += 1;
  if (PassClusterTimeSpread)
    cutFlow["CscPassClusterTimeSpread"] += 1;
  if (PassClusterEta)
    cutFlow["CscPassClusterEta"] += 1;
  if (PassID)
    cutFlow["CscPassID"] += 1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//----------------------------dR
double analyzer_objects::dR(double eta1, double phi1, double eta2,
                            double phi2) {
  double deltaeta = abs(eta1 - eta2);
  double deltaphi = DeltaPhi(phi1, phi2);
  double deltar = sqrt(deltaeta * deltaeta + deltaphi * deltaphi);
  return deltar;
}

//-------------------------DeltaPhi
double analyzer_objects::DeltaPhi(double phi1, double phi2)
// Gives the (minimum) separation in phi between the specified phi values
// Must return a positive value
{
  double pi = TMath::Pi();
  double dphi = fabs(phi1 - phi2);
  if (dphi > pi)
    dphi = 2.0 * pi - dphi;
  return dphi;
}
//------------------------Selection booleans
/// --------------DTs
bool analyzer_objects::askDoesPassOverlapMuon_dt(int index) {
  double dR_mu;
  if (muon_list.size() > 0)
    dR_mu = dR(lepEta[muon_list[0]], lepPhi[muon_list[0]],
               dtRechitClusterEta[index], dtRechitClusterPhi[index]);
  else
    dR_mu = 0.0;

  if (dR_mu > dr_LeadMu_DtCluster)
    return true;
  else
    return false;
}

bool analyzer_objects::askDoesPassdPhiLeadMuon_dt(int index) {
  double dPhi;
  if (muon_list.size() > 0)
    dPhi = DeltaPhi(lepPhi[muon_list[0]], dtRechitClusterPhi[index]);
  else
    dPhi = -999.;

  if (dPhi > dPhiCut_LeadMu_DtCluster)
    return true;
  else
    return false;
}
bool analyzer_objects::askDoesPassClusterEta_dt(int index) {
  if (fabs(dtRechitClusterEta[index]) < DtEta)
    return true;
  else
    return false;
}

bool analyzer_objects::askDoesOverlapGenMuon_dt(int index) {
  double dR_LLP = dR(gLLP_eta, gLLP_phi, dtRechitClusterEta[index],
                     dtRechitClusterPhi[index]);
  if (isMC) {
    if (dR_LLP < dr_GenMu_DtCluster)
      return true;
    else
      return false;
  } else
    return true; // if Data this cut does nothing
}
bool analyzer_objects::askDoesPassClusterSize_dt(int index) {
  if (dtRechitClusterSize[index] >= DtSize)
    return true;
  else
    return false;
}

bool analyzer_objects::askDoesPassRPCMatching_dt(int index) {
  if (dtRechitCluster_match_RPChits_dPhi0p5[index] > 0)
    return true;
  else
    return false;
}

bool analyzer_objects::askDoesPassMuonVeto_dt(int index) {
  if (dtRechitClusterMuonVetoPt[index] < DtMuonVetoPt)
    return true;
  else
    return false;
}

bool analyzer_objects::askDoesPassMB1Veto_dt(int index) {
  if (dtRechitCluster_match_MB1hits_0p5[index] <= DtMB1Veto)
    return true;
  else
    return false;
}

bool analyzer_objects::askDoesPassRPCTimeCut_dt(int index) {
  if (dtRechitCluster_match_RPCBx_dPhi0p5[index] == 0)
    return true;
  else
    return false;
}

bool analyzer_objects::askDoesPassMB1Adjacent_dt(int index) {
  if (dtRechitCluster_match_MB1hits_cosmics_plus[index] <= 8 &&
      dtRechitCluster_match_MB1hits_cosmics_minus[index] <= 8)
    return true;
  else
    return false;
}
///////////////////////////////////////
///------------CSCs
bool analyzer_objects::askDoesPassClusterSize_csc(int index) {
  if (cscRechitClusterSize[index] >= CscSize)
    return true;
  else
    return false;
}
bool analyzer_objects::askDoesPassOverlapMuon_csc(int index) {
  double dR_mu;
  if (muon_list.size() > 0)
    dR_mu = dR(lepEta[muon_list[0]], lepPhi[muon_list[0]],
               cscRechitClusterEta[index], cscRechitClusterPhi[index]);
  else
    dR_mu = 0.0;

  if (dR_mu > dr_LeadMu_CscCluster)
    return true;
  else
    return false;
}
bool analyzer_objects::askDoesPassdPhiLeadMuon_csc(int index) {
  double dPhi;
  if (muon_list.size() > 0)
    dPhi = DeltaPhi(lepPhi[muon_list[0]], cscRechitClusterPhi[index]);
  else
    dPhi = -999.;

  if (dPhi > dPhiCut_LeadMu_CscCluster)
    return true;
  else
    return false;
}

bool analyzer_objects::askDoesOverlapGenLLP_csc(int index) {
  double dR_LLP = dR(gLLP_eta, gLLP_phi, cscRechitClusterEta[index],
                     cscRechitClusterPhi[index]);
  if (isMC) {
    if (dR_LLP < dr_GenMu_CscCluster)
      return true;
    else
      return false;
  } else
    return true; // if Data this cut does nothing
}

bool analyzer_objects::askDoesPassME1112Veto_csc(int index) {
  if (cscRechitClusterNRechitChamberPlus11[index] <= 0 &&
      cscRechitClusterNRechitChamberMinus11[index] <= 0 &&
      cscRechitClusterNRechitChamberPlus12[index] <= 0 &&
      cscRechitClusterNRechitChamberMinus12[index] <= 0)
    return true;
  else
    return false;
}

bool analyzer_objects::askDoesPassMB1Veto_csc(int index) {
  if (cscRechitCluster_match_MB1Seg_0p4[index] == 0)
    return true;
  else
    return false;
}

bool analyzer_objects::askDoesPassRB1Veto_csc(int index) {
  if (cscRechitCluster_match_RB1_0p4[index] == 0)
    return true;
  else
    return false;
}

bool analyzer_objects::askDoesPassMuonVeto_csc(int index) {
  if (cscRechitClusterMuonVetoPt[index] < CscMuonVetoPt)
    return true;
  else
    return false;
}

bool analyzer_objects::askDoesPassClusterTime_csc(int index) {
  if (cscRechitClusterTimeWeighted[index] >= cscClusterTimeLow &&
      cscRechitClusterTimeWeighted[index] <= cscClusterTimeHigh)
    return true;
  else
    return false;
}

bool analyzer_objects::askDoesPassClusterTimeSpread_csc(int index) {
  if (cscRechitClusterTimeSpreadWeightedAll[index] <= cscClusterTimeSpread)
    return true;
  else
    return false;
}

bool analyzer_objects::askDoesPassClusterEta_csc(int index) {
  if (fabs(cscRechitClusterEta[index]) < CscEta)
    return true;
  else
    return false;
}
bool analyzer_objects::askDoesPassID_csc(int index) {
  if ((cscRechitClusterNStation10[index] > 1 &&
       fabs(cscRechitClusterEta[index]) < 1.8) ||
      (cscRechitClusterNStation10[index] == 1 &&
       fabs(cscRechitClusterAvgStation10[index]) == 4 &&
       fabs(cscRechitClusterEta[index]) < 1.8) ||
      (cscRechitClusterNStation10[index] == 1 &&
       fabs(cscRechitClusterAvgStation10[index]) == 3 &&
       fabs(cscRechitClusterEta[index]) < 1.6) ||
      (cscRechitClusterNStation10[index] == 1 &&
       fabs(cscRechitClusterAvgStation10[index]) == 2 &&
       fabs(cscRechitClusterEta[index]) < 1.7) ||
      (cscRechitClusterNStation10[index] == 1 &&
       fabs(cscRechitClusterAvgStation10[index]) == 1 &&
       fabs(cscRechitClusterEta[index]) < 1.1))
    return true;
  else
    return false;
}

// These should be the old version before Aram Optimized. __CHECKME
// bool analyzer_objects::askDoesPassID_csc(int index){
//  if ((cscRechitClusterNStation10[index] > 1 &&
//  fabs(cscRechitClusterEta[index])<1.9) ||
//      (cscRechitClusterNStation10[index]== 1 &&
//      fabs(cscRechitClusterAvgStation10[index])==4 &&
//      fabs(cscRechitClusterEta[index])<1.8) ||
//      (cscRechitClusterNStation10[index]== 1 &&
//      fabs(cscRechitClusterAvgStation10[index])==3 &&
//      fabs(cscRechitClusterEta[index])<1.5) ||
//      (cscRechitClusterNStation10[index]== 1 &&
//      fabs(cscRechitClusterAvgStation10[index])==2 &&
//      fabs(cscRechitClusterEta[index])<1.7) ||
//      (cscRechitClusterNStation10[index]== 1 &&
//      fabs(cscRechitClusterAvgStation10[index])==1 &&
//      fabs(cscRechitClusterEta[index])<1.0) )  return true;
//  else return false;
//}
