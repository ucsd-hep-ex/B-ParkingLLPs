#include "analyzer_objects.h"
#include <math.h>
#include "TMath.h"

//----------------------------analyzer_objects
analyzer_objects::analyzer_objects()
{
}

//----------------------~analyzer_objects
analyzer_objects::~analyzer_objects()
{
}


std::vector<int> analyzer_objects::muonPassSel(Float_t muPtCut, Float_t muEtaCut){

  std::vector<int> ids;
  bool MuonExists  = false;
  bool MuonPassPt  = false;
  bool MuonPassEta = false;
  bool MuonPassHLTFilter = false;
  bool MuonPassQuality = false;
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

std::vector<int> analyzer_objects::DtClusterPassSel(bool passHLT, int DtSizeCut, float dr_MuonCut){
  std::vector<int> ids;
  double dR_mu;
  double dR_LLP;
  if(!passHLT) return ids;
  else{
    bool PassClusterSize = false;
    bool PassOverlapMuon = false;
    bool OverlapGenMuon  = false;
    bool PassRPCMatching = false;
    bool PassMuonVeto    = false;
    bool PassMB1Veto     = false;
    bool PassRPCTimeCut  = false;
    bool PassMB1Adjacent = false;
    for (int j = 0; j <nDtRechitClusters; j++){
      if (muon_list.size()>0) dR_mu = dR(lepEta[muon_list[0]], lepPhi[muon_list[0]], dtRechitClusterEta[j], dtRechitClusterPhi[j]);
      else dR_mu = 0.0;
      dR_LLP = dR(gLLP_eta, gLLP_phi, dtRechitClusterEta[j], dtRechitClusterPhi[j]);
      if(dtRechitClusterSize[j] >= DtSizeCut){
        PassClusterSize = true;
        if( dR_mu > dr_MuonCut){
          PassOverlapMuon = true;
          if(dR_LLP < dr_GenMu_DtCluster){
            OverlapGenMuon = true;
            counter++;
            if (dtRechitCluster_match_RPChits_dPhi0p5[j] > 0){
              PassRPCMatching = true;
              if(dtRechitClusterMuonVetoPt[j] < DtMuonVetoPt){
                PassMuonVeto = true;
                if( dtRechitCluster_match_MB1hits_0p5[j] >= DtMB1Veto){
                  PassMB1Veto = true;
                  if(dtRechitCluster_match_RPCBx_dPhi0p5[j] == 0){
                    PassRPCTimeCut = true;
                    if(dtRechitCluster_match_MB1hits_cosmics_plus[j] <=8&& dtRechitCluster_match_MB1hits_cosmics_minus[j]<=8){
                      PassMB1Adjacent = true;
                      ids.push_back(j);
                    }  
                  }
                }
              }
            }
          }
        }
      }
    }
    if(nDtRechitClusters>0)   cutFlow["nDtRechitClusters > 0"] +=1;
    if(PassClusterSize)       cutFlow["DtClusterSize >= 50"] +=1;
    if(PassOverlapMuon)       cutFlow["DtPassOverlapLeadMuon"] +=1;
    if(OverlapGenMuon)        cutFlow["DtOverlapGenLLP"] +=1;
    if(PassRPCMatching)       cutFlow["DtPassRPCMatching"] +=1;
    if(PassMuonVeto)          cutFlow["DtPassMuonVeto"] +=1;
    if(PassMB1Veto)           cutFlow["DtPassMB1Veto"] +=1;
    if(PassRPCTimeCut)        cutFlow["DtPassRPCTimeCut"] +=1;
    if(PassMB1Adjacent)       cutFlow["DtPassMB1Adjacent"] +=1;
    return ids;
  }
}

std::vector<int> analyzer_objects::CscClusterPassSel(bool passHLT, int CscSizeCut, float dr_MuonCut){
  std::vector<int> ids;
  double dR_mu;
  double dR_LLP;
  if(!passHLT) return ids;
  else{
    bool PassClusterSize    = false;
    bool PassOverlapMuon    = false;
    bool OverlapGenLLP      = false;
    for (int j = 0; j <nCscRechitClusters; j++){
      if (muon_list.size()>0) dR_mu = dR(lepEta[muon_list[0]], lepPhi[muon_list[0]], cscRechitClusterEta[j], cscRechitClusterPhi[j]);
      else dR_mu = 0.0;
      dR_LLP = dR(gLLP_eta, gLLP_phi, cscRechitClusterEta[j], cscRechitClusterPhi[j]);
      if(cscRechitClusterSize[j] >= CscSizeCut){
        PassClusterSize = true;
        if( dR_mu > dr_MuonCut){
          PassOverlapMuon = true;
          if(dR_LLP < dr_GenMu_CscCluster){
          OverlapGenLLP = true;
          ids.push_back(j);
          }
        }
      }
    }
    if(nCscRechitClusters>0)  cutFlow["nCscRechitClusters > 0"] +=1;
    if(PassClusterSize)       cutFlow["CscClusterSize >= 0"] +=1;
    if(PassOverlapMuon)       cutFlow["CscPassOverlapLeadMuon"] +=1;
    if(OverlapGenLLP)         cutFlow["CscOverlapGenLLP"] +=1;
    return ids;
  }
}

//----------------------------dR
double analyzer_objects::dR(double eta1, double phi1, double eta2, double phi2)
{
  double deltaeta = abs(eta1 - eta2);
  double deltaphi = DeltaPhi(phi1, phi2);
  double deltar = sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
  return deltar;
}

//-------------------------DeltaPhi
double analyzer_objects::DeltaPhi(double phi1, double phi2)
//Gives the (minimum) separation in phi between the specified phi values
//Must return a positive value
{
  double pi = TMath::Pi();
  double dphi = fabs(phi1-phi2);
  if(dphi>pi)
    dphi = 2.0*pi - dphi;
  return dphi;
}
