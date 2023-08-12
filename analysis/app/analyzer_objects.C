#include "TMath.h"
#include "analyzer_objects.h"
#include <iostream>
#include <math.h>

//----------------------------analyzer_objects
analyzer_objects::analyzer_objects() {}

//----------------------~analyzer_objects
analyzer_objects::~analyzer_objects() {}

std::vector<int> analyzer_objects::muonPassSel(Float_t muPtCut, Float_t muEtaCut){
  std::vector<int> ids;
  bool MuonExists  = false;
  bool MuonPassPt  = false;
  bool MuonPassEta = false;
  bool MuonPassHLTFilter = false;
  bool MuonPassQuality = false;
  passGoodMuon = false;
  for (int j = 0; j<nLeptons; j++){
    if(abs(lepPdgId[j]) != 13) continue;
    MuonExists = true;
    if(lepPt[j] > muPtCut){
      MuonPassPt = true;
      if(lepEta[j] < fabs(muEtaCut)){ 
        MuonPassEta = true;
        if(lepMuon_passHLTFilter[j]){
         MuonPassHLTFilter = true;
         if(lepMuonQuality[j] >= pow(2,25)){
           MuonPassQuality = true;
           passGoodMuon = true;
           ids.push_back(j);
         }
        }
      }
    }
  }
  if(MuonExists )       cutFlow["Muon Exists"] +=1;
  if(MuonPassPt )       cutFlow["MuonPt > 7 GeV"] +=1;
  if(MuonPassEta)       cutFlow["abs(MuonEta) < 1.5"] +=1;
  if(MuonPassHLTFilter) cutFlow["MuonHLTRequirement"] +=1;
  if(MuonPassQuality)   cutFlow["MuonQuality"] +=1;
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
                   askDoesPassNominal_dt(j)

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
                   askDoesPassNominal_dt(j)

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
            ) 
                ids.push_back(j);
        }
    }
    return ids;
}

//--------- Region Definitions

//-------- Test-OOT Selections                                         // loggit
std::vector<int> analyzer_objects::CscClusterPassSel_testOOT(bool passHLT){    // loggit
  std::vector<int> ids;                                                // loggit
  if(!passHLT) return ids;
  else{
    for (int j = 0; j <nCscRechitClusters; j++){                       // loggit
      if(                                                              // loggit
        askDoesPassClusterSize_csc(j)       &&                        // loggit 
        askDoesPassOverlapMuon_csc(j)        &&                        // loggit
        askDoesPassME1112Veto_csc(j)         &&                        // loggit
        askDoesPassMB1Veto_csc(j)            &&                        // loggit
        askDoesPassRB1Veto_csc(j)            &&                        // loggit
        askDoesPassMuonVeto_csc(j)           &&                        // loggit
        !askDoesPassClusterTime_csc(j)       &&                        // loggit
        askDoesPassClusterTimeSpread_csc(j)  &&                        // loggit
        askDoesPassID_csc(j)                 &&                        // loggit
        !askDoesPassdPhiLeadMuon_csc(j)      &&                       // loggit
        askDoesPassClusterEta_csc(j)         //&&                      // loggit
        //askDoesOverlapGenLLP_csc(j)          &&                      // loggit
        ) ids.push_back(j);                                            // loggit
    }                                                                  // loggit
  } 
  return ids;                                                          // loggit
}                                                                      // loggit

std::vector<int> analyzer_objects::DtClusterPassSel_testOOT(bool passHLT){     // loggit
  std::vector<int> ids;                                                // loggit
  if(!passHLT) return ids;
  else{
    for (int j = 0; j <nDtRechitClusters; j++){                        // loggit
      if(                                                              // loggit
        askDoesPassClusterSize_dt(j) &&                              // loggit
        askDoesPassOverlapMuon_dt(j) &&                              // loggit
        askDoesPassRPCMatching_dt(j) &&                              // loggit
        askDoesPassRPCTimeCut_dt(j)  &&                              // loggit
        askDoesPassMB1Adjacent_dt(j) &&                              // loggit 
        askDoesPassMB1Veto_dt(j)     &&                              // loggit
        askDoesPassMuonVeto_dt(j)    &&                              // loggit
        askDoesPassClusterEta_dt(j)  //&&                              // loggit
        //askDoesOverlapGenMuon_dt(j)  &&                              // loggit
        ) ids.push_back(j);                                            // loggit
    }                                                                  // loggit
  }                                                                    
  return ids;                                                          // loggit
}                                                                      // loggit

//-------- Test Selections                                             // loggit
std::vector<int> analyzer_objects::CscClusterPassSel_test(bool passHLT){    // loggit
  std::vector<int> ids;                                                // loggit
  if(!passHLT) return ids;
  else{
    for (int j = 0; j <nCscRechitClusters; j++){                       // loggit
      if(                                                              // loggit
        askDoesPassClusterSize_csc(j)       &&                        // loggit 
        askDoesPassOverlapMuon_csc(j)        &&                        // loggit
        askDoesPassME1112Veto_csc(j)         &&                        // loggit
        askDoesPassMB1Veto_csc(j)            &&                        // loggit
        askDoesPassRB1Veto_csc(j)            &&                        // loggit
        askDoesPassMuonVeto_csc(j)           &&                        // loggit
        askDoesPassClusterTime_csc(j)        &&                        // loggit
        askDoesPassClusterTimeSpread_csc(j)  &&                        // loggit
        askDoesPassID_csc(j)                 &&                        // loggit
        !askDoesPassdPhiLeadMuon_csc(j)       &&                        // loggit
        askDoesPassClusterEta_csc(j)         //&&                        // loggit
        //askDoesOverlapGenLLP_csc(j)          &&                      // loggit
        ) ids.push_back(j);                                            // loggit
    }                                                                  // loggit
  } 
  return ids;                                                          // loggit
}                                                                      // loggit

std::vector<int> analyzer_objects::DtClusterPassSel_test(bool passHLT){     // loggit
  std::vector<int> ids;                                                // loggit
  if(!passHLT) return ids;
  else{
    for (int j = 0; j <nDtRechitClusters; j++){                        // loggit
      if(                                                              // loggit
        askDoesPassClusterSize_dt(j) &&                              // loggit
        askDoesPassOverlapMuon_dt(j) &&                              // loggit
        askDoesPassRPCMatching_dt(j) &&                              // loggit
        askDoesPassRPCTimeCut_dt(j)  &&                              // loggit
        askDoesPassMB1Adjacent_dt(j) &&                              // loggit 
        askDoesPassMB1Veto_dt(j)     &&                              // loggit
        askDoesPassMuonVeto_dt(j)    &&                              // loggit
        askDoesPassClusterEta_dt(j)  //&&                                // loggit
        //askDoesOverlapGenMuon_dt(j)  &&                              // loggit
        ) ids.push_back(j);                                            // loggit
    }                                                                  // loggit
  }                                                                    
  return ids;                                                          // loggit
}                                                                      // loggit
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------- Out of Time Region                              // loggit
std::vector<int> analyzer_objects::CscClusterPassSel_OOT(bool passHLT){ // loggit
  std::vector<int> ids;                                                 // loggit
  if(!passHLT) return ids;                                                       
  else{                                                                          
    for (int j = 0; j <nCscRechitClusters; j++){                        // loggit
      if(                                                               // loggit
        askDoesPassClusterSize_csc(j)        &&                         // loggit
        askDoesPassOverlapMuon_csc(j)        &&                         // loggit
        askDoesPassME1112Veto_csc(j)         &&                         // loggit
        askDoesPassMB1Veto_csc(j)            &&                         // loggit
        askDoesPassRB1Veto_csc(j)            &&                         // loggit
        askDoesPassMuonVeto_csc(j)           &&                         // loggit
        !askDoesPassClusterTime_csc(j)       &&                         // loggit
        askDoesPassClusterTimeSpread_csc(j)  &&                         // loggit
        askDoesPassdPhiLeadMuon_csc(j)       &&                         // loggit
        askDoesPassClusterEta_csc(j)         &&                         // loggit
        //askDoesOverlapGenLLP_csc(j)          &&                         // loggit
        askDoesPassID_csc(j)                   
        ) ids.push_back(j);      // loggit
    }                                                                   // loggit
  }                                                                              
  return ids;                                                           // loggit
}                                                                       // loggit
                                                                                 
std::vector<int> analyzer_objects::DtClusterPassSel_OOT(bool passHLT){  // loggit
  std::vector<int> ids;                                                 // loggit
  if(!passHLT) return ids;
  else{
    for (int j = 0; j <nDtRechitClusters; j++){                         // loggit
      if(                                                               // loggit
        askDoesPassClusterSize_dt(j) &&                                 // loggit
        askDoesPassOverlapMuon_dt(j) &&                                 // loggit
        askDoesOverlapGenMuon_dt(j)  &&                                 // loggit
        askDoesPassRPCMatching_dt(j) &&                                 // loggit
        askDoesPassMuonVeto_dt(j)    &&                                 // loggit
        askDoesPassMB1Veto_dt(j)     &&                                 // loggit
        !askDoesPassRPCTimeCut_dt(j) &&                                 // loggit
        askDoesPassClusterEta_dt(j)  &&                                 // loggit
        askDoesPassMB1Adjacent_dt(j)   ) ids.push_back(j);              // loggit
    }                                                                   // loggit
  }
  return ids;                                                           // loggit
}                                                                       // loggit
////////////////////////////////////////////////////
//--------------------- Signal Region                                  // loggit
std::vector<int> analyzer_objects::CscClusterPassSel_SR(bool passHLT){ // loggit
  std::vector<int> ids;                                                // loggit
  if(!passHLT) return ids;
  else{
    for (int j = 0; j <nCscRechitClusters; j++){                       // loggit
      if(                                                              // loggit
        askDoesPassClusterSize_csc(j)        &&                        // loggit
        askDoesPassOverlapMuon_csc(j)        &&                        // loggit
        //askDoesOverlapGenLLP_csc(j)          &&                        // loggit
        askDoesPassME1112Veto_csc(j)         &&                        // loggit
        askDoesPassMB1Veto_csc(j)            &&                        // loggit
        askDoesPassRB1Veto_csc(j)            &&                        // loggit
        askDoesPassMuonVeto_csc(j)           &&                        // loggit
        askDoesPassClusterTime_csc(j)        &&                        // loggit
        askDoesPassClusterTimeSpread_csc(j)  &&                        // loggit
        askDoesPassdPhiLeadMuon_csc(j)       &&                        // loggit
        askDoesPassClusterEta_csc(j)         &&                        // loggit
        askDoesPassID_csc(j)                   ){                      // loggit
        ids.push_back(j);                                              // loggit
        counter++;
      }                                                                // loggit
    }                                                                  // loggit
  } 
  return ids;                                                          // loggit
}                                                                      // loggit

std::vector<int> analyzer_objects::DtClusterPassSel_SR(bool passHLT){  // loggit
  std::vector<int> ids;                                                // loggit
  if(!passHLT) return ids;
  else{
    for (int j = 0; j <nDtRechitClusters; j++){                        // loggit
      if(                                                              // loggit
        askDoesPassClusterSize_dt(j) &&                                // loggit
        askDoesPassOverlapMuon_dt(j) &&                                // loggit
        askDoesOverlapGenMuon_dt(j)  &&                                // loggit
        askDoesPassRPCMatching_dt(j) &&                                // loggit
        askDoesPassMuonVeto_dt(j)    &&                                // loggit
        askDoesPassMB1Veto_dt(j)     &&                                // loggit
        askDoesPassRPCTimeCut_dt(j)  &&                                // loggit
        askDoesPassClusterEta_dt(j)  &&                                // loggit
        askDoesPassMB1Adjacent_dt(j)   ) ids.push_back(j);             // loggit
    }                                                                  // loggit
  }
  return ids;                                                          // loggit
}                                                                      // loggit
////////////////////////////////////////////////////

std::vector<int> analyzer_objects::DtClusterPassSel_OOT2(bool passHLT) {
    std::vector<int> ids;
    if (!passHLT)
        return ids;
    else {
        for (int j = 0; j < nDtRechitClusters; j++) {
            if (
                   askDoesPassNominal_dt(j)

                && !askDoesPassRPCTimeCut_dt(j) 
                && askDoesPassMaxStation4_dt(j)
            )     
                ids.push_back(j);
        }
    }
    return ids;
}
//--------------------------------------------------------- End OOT2

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
                   askDoesPassNominal_dt(j)

                && askDoesPassRPCTimeCut_dt(j) 
                && askDoesPassMaxStation3_dt(j)
            )   
                ids.push_back(j);
        }
    }
    return ids;
}
//--------------------------------------------------------- End SR

//--------------------------------------------------------- Begin SR2
std::vector<int> analyzer_objects::CscClusterPassSel_SR2(bool passHLT) {
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

std::vector<int> analyzer_objects::DtClusterPassSel_SR2(bool passHLT) {
    std::vector<int> ids;
    if (!passHLT)
        return ids;
    else {
        for (int j = 0; j < nDtRechitClusters; j++) {
            if (
                   askDoesPassNominal_dt(j)

                && askDoesPassRPCTimeCut_dt(j) 
                && askDoesPassMaxStation4_dt(j)
            )   
                ids.push_back(j);
        }
    }
    return ids;
}
//--------------------------------------------------------- End SR2
//========================================================= Ends Region Definitions


// ----CutFlow Table stuff
void analyzer_objects::DtClusterPassSel_CutFlow(Float_t ew){

  double dR_mu;
  double dR_LLP;
  bool PassAll         = false;
  bool PassClusterSize = false;
  bool PassOverlapMuon = false;
  bool OverlapGenMuon  = false;
  bool PassRPCMatching = false;
  bool PassMuonVeto    = false;
  bool PassMB1Veto     = false;
  bool PassRPCTimeCut  = false;
  bool PassMB1Adjacent = false;
  bool PassMaxStation  = false;
  if(isMC){
    for (int j = 0; j <nDtRechitClusters; j++){
      if (muon_list.size()>0) dR_mu = dR(lepEta[muon_list[0]], lepPhi[muon_list[0]], dtRechitClusterEta[j], dtRechitClusterPhi[j]);
      else dR_mu = 0.0;
      dR_LLP = dR(gLLP_eta, gLLP_phi, dtRechitClusterEta[j], dtRechitClusterPhi[j]);
      if(dtRechitClusterSize[j] >= DtSize){
        PassClusterSize = true;
        if( dR_mu > dr_LeadMu_DtCluster){
          PassOverlapMuon = true;
          if(dR_LLP < dr_GenMu_DtCluster){
            OverlapGenMuon = true;
            if (dtRechitCluster_match_RPChits_dPhi0p5[j] > 0){
              PassRPCMatching = true;
              if(dtRechitClusterMuonVetoPt[j] < DtMuonVetoPt){
                PassMuonVeto = true;
                if( dtRechitCluster_match_MB1hits_0p5[j] <= DtMB1Veto){
                  PassMB1Veto = true;
                  if(dtRechitCluster_match_RPCBx_dPhi0p5[j] == 0){
                    PassRPCTimeCut = true;
                    if(dtRechitCluster_match_MB1hits_cosmics_plus[j] <=8&& dtRechitCluster_match_MB1hits_cosmics_minus[j]<=8){
                      PassMB1Adjacent = true;
                        if(dtRechitClusterMaxStation[j] >= 3){
                          PassMaxStation = true;
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
  else{
    OverlapGenMuon = true;
    for (int j = 0; j <nDtRechitClusters; j++){
      if (muon_list.size()>0) dR_mu = dR(lepEta[muon_list[0]], lepPhi[muon_list[0]], dtRechitClusterEta[j], dtRechitClusterPhi[j]);
      else dR_mu = 0.0;
      dR_LLP = dR(gLLP_eta, gLLP_phi, dtRechitClusterEta[j], dtRechitClusterPhi[j]);
      if(dtRechitClusterSize[j] >= DtSize){
        PassClusterSize = true;
        if( dR_mu > dr_LeadMu_DtCluster){
          PassOverlapMuon = true;
          if (dtRechitCluster_match_RPChits_dPhi0p5[j] > 0){
            PassRPCMatching = true;
            if(dtRechitClusterMuonVetoPt[j] < DtMuonVetoPt){
              PassMuonVeto = true;
              if( dtRechitCluster_match_MB1hits_0p5[j] <= DtMB1Veto){
                PassMB1Veto = true;
                if(dtRechitCluster_match_RPCBx_dPhi0p5[j] == 0){
                  PassRPCTimeCut = true;
                  if(dtRechitCluster_match_MB1hits_cosmics_plus[j] <=8&& dtRechitCluster_match_MB1hits_cosmics_minus[j]<=8){
                    PassMB1Adjacent = true;
                      if(dtRechitClusterMaxStation[j] >= 3){
                        PassMaxStation = true;
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
  if(nDtRechitClusters>0)   cutFlow["nDtRechitClusters > 0"] +=ew;
  if(PassClusterSize)       cutFlow["DtClusterSize >= 50"] +=ew;
  if(PassOverlapMuon)       cutFlow["DtPassOverlapLeadMuon"] +=ew;
  if(OverlapGenMuon)        cutFlow["DtOverlapGenLLP"] +=ew;
  if(PassRPCMatching)       cutFlow["DtPassRPCMatching"] +=ew;
  if(PassMuonVeto)          cutFlow["DtPassMuonVeto"] +=ew;
  if(PassMB1Veto)           cutFlow["DtPassMB1Veto"] +=ew;
  if(PassRPCTimeCut)        cutFlow["DtPassRPCTimeCut"] +=ew;
  if(PassMB1Adjacent)       cutFlow["DtPassMB1Adjacent"] +=ew;
}

void analyzer_objects::CscClusterPassSel_CutFlow(Float_t ew){
  double dR_mu;
  double dR_LLP;
  bool PassClusterSize       = false;
  bool PassOverlapMuon       = false;
  bool OverlapGenLLP         = false;
  bool PassME1112Veto        = false;
  bool PassMB1Veto           = false;
  bool PassRB1Veto           = false;
  bool PassMuonVeto          = false;
  bool PassClusterTime       = false;
  bool PassClusterTimeSpread = false;
  bool PassClusterEta        = false;
  bool PassID                = false;
  if(isMC){
    for (int j = 0; j <nCscRechitClusters; j++){
      if (muon_list.size()>0) dR_mu = dR(lepEta[muon_list[0]], lepPhi[muon_list[0]], cscRechitClusterEta[j], cscRechitClusterPhi[j]);
      else dR_mu = 0.0;
      dR_LLP = dR(gLLP_eta, gLLP_phi, cscRechitClusterEta[j], cscRechitClusterPhi[j]);
      if(cscRechitClusterSize[j] >= CscSize){
        PassClusterSize = true;
        if( dR_mu > dr_LeadMu_CscCluster){
          PassOverlapMuon = true;
          if(dR_LLP < dr_GenMu_CscCluster){
          OverlapGenLLP = true;
            if( cscRechitClusterNRechitChamberPlus11[j] <=0 && cscRechitClusterNRechitChamberMinus11[j] <=0 &&
                cscRechitClusterNRechitChamberPlus12[j] <=0 && cscRechitClusterNRechitChamberMinus12[j] <=0){
              PassME1112Veto = true;
              if( cscRechitCluster_match_MB1Seg_0p4[j] == 0){
                PassMB1Veto = true;
                if(cscRechitCluster_match_RB1_0p4[j] == 0){
                  PassRB1Veto = true;
                  if(cscRechitClusterMuonVetoPt[j] < CscMuonVetoPt){
                    PassMuonVeto = true;
                    if( cscRechitClusterTimeWeighted[j] >= cscClusterTimeLow && cscRechitClusterTimeWeighted[j] <= cscClusterTimeHigh){
                      PassClusterTime = true;
                      if(cscRechitClusterTimeSpreadWeightedAll[j] <= cscClusterTimeSpread){
                        PassClusterTimeSpread = true;
                        if(fabs(cscRechitClusterEta[j]) < CscEta){
                          PassClusterEta = true;
                          if( 
        		           (cscRechitClusterNStation10[j] > 1 && fabs(cscRechitClusterEta[j])<1.9) || 
                             (cscRechitClusterNStation10[j]== 1 && fabs(cscRechitClusterAvgStation10[j])==4 && fabs(cscRechitClusterEta[j])<1.8) || 
                             (cscRechitClusterNStation10[j]== 1 && fabs(cscRechitClusterAvgStation10[j])==3 && fabs(cscRechitClusterEta[j])<1.5) || 
                             (cscRechitClusterNStation10[j]== 1 && fabs(cscRechitClusterAvgStation10[j])==2 && fabs(cscRechitClusterEta[j])<1.7) || 
                             (cscRechitClusterNStation10[j]== 1 && fabs(cscRechitClusterAvgStation10[j])==1 && fabs(cscRechitClusterEta[j])<1.0)  
                            ){
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
  }
  else{
    OverlapGenLLP = true;
    for (int j = 0; j <nCscRechitClusters; j++){
      if (muon_list.size()>0) dR_mu = dR(lepEta[muon_list[0]], lepPhi[muon_list[0]], cscRechitClusterEta[j], cscRechitClusterPhi[j]);
      else dR_mu = 0.0;
      dR_LLP = dR(gLLP_eta, gLLP_phi, cscRechitClusterEta[j], cscRechitClusterPhi[j]);
      if(cscRechitClusterSize[j] >= CscSize){
        PassClusterSize = true;
        if( dR_mu > dr_LeadMu_CscCluster){
          PassOverlapMuon = true;
          if( cscRechitClusterNRechitChamberPlus11[j] <=0 && cscRechitClusterNRechitChamberMinus11[j] <=0 &&
              cscRechitClusterNRechitChamberPlus12[j] <=0 && cscRechitClusterNRechitChamberMinus12[j] <=0){
            PassME1112Veto = true;
            if( cscRechitCluster_match_MB1Seg_0p4[j] == 0){
              PassMB1Veto = true;
              if(cscRechitCluster_match_RB1_0p4[j] == 0){
                PassRB1Veto = true;
                if(cscRechitClusterMuonVetoPt[j] < CscMuonVetoPt){
                  PassMuonVeto = true;
                  if( cscRechitClusterTimeWeighted[j] >= cscClusterTimeLow && cscRechitClusterTimeWeighted[j] <= cscClusterTimeHigh){
                    PassClusterTime = true;
                    if(cscRechitClusterTimeSpreadWeightedAll[j] <= cscClusterTimeSpread){
                      PassClusterTimeSpread = true;
                      if(fabs(cscRechitClusterEta[j]) < CscEta){
                        PassClusterEta = true;
                        if( 
              	           (cscRechitClusterNStation10[j] > 1 && fabs(cscRechitClusterEta[j])<1.9) || 
                           (cscRechitClusterNStation10[j]== 1 && fabs(cscRechitClusterAvgStation10[j])==4 && fabs(cscRechitClusterEta[j])<1.8) || 
                           (cscRechitClusterNStation10[j]== 1 && fabs(cscRechitClusterAvgStation10[j])==3 && fabs(cscRechitClusterEta[j])<1.5) || 
                           (cscRechitClusterNStation10[j]== 1 && fabs(cscRechitClusterAvgStation10[j])==2 && fabs(cscRechitClusterEta[j])<1.7) || 
                           (cscRechitClusterNStation10[j]== 1 && fabs(cscRechitClusterAvgStation10[j])==1 && fabs(cscRechitClusterEta[j])<1.0)  
                          ){
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
    if(nCscRechitClusters>0)  cutFlow["nCscRechitClusters > 0"] +=ew;
    if(PassClusterSize)       cutFlow["CscClusterSize >= 0"] +=ew;
    if(PassOverlapMuon)       cutFlow["CscPassOverlapLeadMuon"] +=ew;
    if(OverlapGenLLP)         cutFlow["CscOverlapGenLLP"] +=ew;
    if(PassME1112Veto)        cutFlow["CscPassME1112Veto"] +=ew;
    if(PassMB1Veto)           cutFlow["CscPassMB1Veto"] +=ew;
    if(PassRB1Veto)           cutFlow["CscPassRB1Veto"] +=ew;
    if(PassMuonVeto)          cutFlow["CscPassMuonVeto"] +=ew;
    if(PassClusterTime)       cutFlow["CscPassClusterTime"] +=ew;
    if(PassClusterTimeSpread) cutFlow["CscPassClusterTimeSpread"] +=ew;
    if(PassClusterEta)        cutFlow["CscPassClusterEta"] +=ew;
    if(PassID)                cutFlow["CscPassID"] +=ew;
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

bool analyzer_objects::askDoesPassNominal_dt(int index) {
    return askDoesPassClusterSize_dt(index) 
        && askDoesPassOverlapMuon_dt(index) 
        && askDoesPassRPCMatching_dt(index) 
        && askDoesPassMuonVeto_dt(index)
        && askDoesPassMB1Veto_dt(index)
        && askDoesPassMB1Adjacent_dt(index);
}


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
    return (dtRechitCluster_match_RPChits_dPhi0p5[index] > 0);
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

bool analyzer_objects::askDoesPassMaxStation3_dt(int index) {
    return (dtRechitClusterMaxStation[index] == 3);
}

bool analyzer_objects::askDoesPassMaxStation4_dt(int index) {
    return (dtRechitClusterMaxStation[index] == 4);
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