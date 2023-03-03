#ifndef analyzer_histograms_h
#define analyzer_histograms_h

#include "TH1F.h"
#include "TH2F.h"

#include "analyzer_selections.h"

class analyzer_histograms : public analyzer_selections{

  public : 
 
           analyzer_histograms();
  virtual ~analyzer_histograms();

  TH1F* h_nLeptons;
  TH1F* h_cscRechitClusterSize;
  TH1F* h_dtRechitClusterSize;
  
  void InitHistos();
  void FillHistos();
  void WriteHistos();


};

#endif

