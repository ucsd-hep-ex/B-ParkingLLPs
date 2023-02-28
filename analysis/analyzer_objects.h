#ifndef analyzer_objects_h
#define analyzer_objects_h

#include "analyzer_base.h"

class analyzer_objects : public analyzer_base{

  public : 
 
           analyzer_objects();
  virtual ~analyzer_objects();

  std::vector<int> muonPassSel();
};

#endif
