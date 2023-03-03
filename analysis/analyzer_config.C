#include "analyzer_config.h"

//----------------------------analyzer_config
analyzer_config::analyzer_config()
{
}

//----------------------~analyzer_config
analyzer_config::~analyzer_config()
{
}

void analyzer_config::setConfig(){

  muPt = 7.;
  muEta = 1.5;

  DtSize = 50;
  CscSize = 0;

  CscEta = 1.9;

  dr_LeadMu_DtCluster = 0.8;
  dr_LeadMu_CscCluster = 0.8;
  dr_GenMu_DtCluster = 0.4;
  dr_GenMu_CscCluster = 0.4;

  DtMuonVetoPt = 20.;
  CscMuonVetoPt = 20.;
 
  DtMB1Veto = 1;

  cscClusterTimeLow = -5.;
  cscClusterTimeHigh = 12.5;
  cscClusterTimeSpread = 20.;

  HLTIndexLow = 1157;
  HLTIndexHigh = 1197;


}

Bool_t analyzer_config::doCutFlow(){
  return b_cutFlow;
}
