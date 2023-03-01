#ifndef analyzer_config_h
#define analyzer_config_h

#include "analyzer_base.h"

class analyzer_config : public analyzer_base{

  public : 
 
           analyzer_config();
  virtual ~analyzer_config();
  void     setConfig();


  Float_t muPt;
  Float_t muEta;
};
#endif

