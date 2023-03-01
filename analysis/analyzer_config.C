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

  dr_LeadMu_DtCluster = 0.8;
  dr_LeadMu_CscCluster = 0.8;
  dr_GenMu_DtCluster = 0.4;
  dr_GenMu_CscCluster = 0.4;

  DtMuonVetoPt = 20.;
  DtMB1Veto = 1;

  HLTIndexLow = 1157;
  HLTIndexHigh = 1197;

}
