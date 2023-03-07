#ifndef analyzer_selections_h
#define analyzer_selections_h

#include "analyzer_objects.h"

class analyzer_selections : public analyzer_objects{

  public : 
 
           analyzer_selections();
  virtual ~analyzer_selections();

 bool SignalRegion(TString clusterFlavour);
 bool OOTRegion(TString clusterFlavour);
};

#endif

