#ifndef analyzer_objects_h
#define analyzer_objects_h

#include "analyzer_config.h"

class analyzer_objects : public analyzer_config{

  public : 
 
           analyzer_objects();
  virtual ~analyzer_objects();

  std::vector<int> muonPassSel(Float_t muPtCut, Float_t muEtaCut);
};

#endif
