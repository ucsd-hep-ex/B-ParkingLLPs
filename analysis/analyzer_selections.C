#include "analyzer_selections.h"

//----------------------------analyzer_selections
analyzer_selections::analyzer_selections()
{
}

//----------------------~analyzer_selections
analyzer_selections::~analyzer_selections()
{
}

bool analyzer_selections::SignalRegion(TString clusterFlavour){
  if (clusterFlavour =="DT"){
    if (PassClusterSize_dt && 
        PassOverlapMuon_dt && 
        OverlapGenMuon_dt  && 
        PassRPCMatching_dt && 
        PassMuonVeto_dt    &&
        PassMB1Veto_dt     && 
        PassRPCTimeCut_dt  && 
        PassMB1Adjacent_dt) return true;
    else return false;
  }
  else if (clusterFlavour =="CSC"){
    if (PassClusterSize_csc       && 
        PassOverlapMuon_csc       && 
        OverlapGenLLP_csc         && 
        PassME1112Veto_csc        && 
        PassMB1Veto_csc           && 
        PassRB1Veto_csc           &&
        PassMuonVeto_csc          && 
        PassClusterTime_csc       && 
        PassClusterTimeSpread_csc && 
        PassClusterEta_csc        && 
        PassID_csc) return true;
     else return false;
  }
  else return false;
}

bool analyzer_selections::OOTRegion(TString clusterFlavour){
  if (clusterFlavour =="DT"){
    if (PassClusterSize_dt && 
        PassOverlapMuon_dt && 
        OverlapGenMuon_dt  && 
        PassRPCMatching_dt && 
        PassMuonVeto_dt    &&
        PassMB1Veto_dt     && 
        !PassRPCTimeCut_dt && 
        PassMB1Adjacent_dt) return true;
    else return false;
  }
  else if (clusterFlavour =="CSC"){
    if (PassClusterSize_csc       && 
        PassOverlapMuon_csc       && 
        OverlapGenLLP_csc         && 
        PassME1112Veto_csc        && 
        PassMB1Veto_csc           && 
        PassRB1Veto_csc           &&
        PassMuonVeto_csc          && 
        !PassClusterTime_csc      && 
        PassClusterTimeSpread_csc && 
        PassClusterEta_csc        && 
        PassID_csc) return true;
     else return false;
  }
  else return false;
}
