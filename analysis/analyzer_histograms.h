#ifndef analyzer_histograms_h
#define analyzer_histograms_h

#include "TH1F.h"
#include "TH2F.h"

#include "analyzer_objects.h"

class analyzer_histograms : public analyzer_objects{

  public : 
 
           analyzer_histograms();
  virtual ~analyzer_histograms();

  TH1F* h_nLeptons;
  
  void InitHistos();
  void FillHistos();
  void WriteHistos();


};

#endif

