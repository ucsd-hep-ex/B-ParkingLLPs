#include "analyzer_config.h"

//----------------------------analyzer_config
analyzer_config::analyzer_config()
{
}

//----------------------~analyzer_config
analyzer_config::~analyzer_config()
{
}

void analyzer_config::setConfig(){ // loggit

  doScan = false;                    //loggit

  genMuonFilterEff = 0.00541267;      // loggit

  muPt = 7.;                       // loggit
  muEta = 1.5;                     // loggit

  //Size cuts for histo definition
  //objects.C uses >=50 selection
  CscSize = 310;              // loggit
  DtSize  = 160;                    // loggit

  CscEta = 1.9;                    // loggit
  DtEta = 1.9;                     // loggit

  dr_LeadMu_DtCluster = 0.8;       // loggit
  dr_LeadMu_CscCluster = 0.8;      // loggit
  dr_GenMu_DtCluster = 0.4;        // loggit
  dr_GenMu_CscCluster = 0.4;       // loggit

  DtMuonVetoPt = 20.;              // loggit
  CscMuonVetoPt = 20.;             // loggit
 
  DtMB1Veto = 1;                   // loggit

  dPhiCut_LeadMu_CscCluster = 2.5;  //loggit
  dPhiCut_LeadMu_DtCluster = 2.5;   //loggit

  cscClusterTimeLow = -5.;         // loggit
  cscClusterTimeHigh = 12.5;       // loggit
  cscClusterTimeSpread = 20.;      // loggit

  HLTIndexLow = 1157;              // loggit
  HLTIndexHigh = 1197;             // loggit

}                                  // loggit

Bool_t analyzer_config::doCutFlow(){
  return b_cutFlow;
}
Bool_t analyzer_config::doTree(){
  return b_doTree;
}
