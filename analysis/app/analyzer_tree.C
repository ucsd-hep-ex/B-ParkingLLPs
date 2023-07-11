#include "analyzer_tree.h"

//----------------------------analyzer_selections
analyzer_tree::analyzer_tree() {}

//----------------------~analyzer_selections
analyzer_tree::~analyzer_tree() {}

void analyzer_tree::clearTree() { 
  t_Event.clear(); 
  t_dtRechitClusterN10.clear();
  t_dtRechitClusterAvg10.clear();
  t_dtRechitClusterEta.clear();
}

void analyzer_tree::setTree() {
  t_Event.push_back(evtNum); 

  for(int i=0; i < DtClusterPassSel_all[0].size(); i++){
    int d = DTClusterPassSell_all[0][i];
    t_dtRechitClusterN10.push_back(d);
    t_dtRechitClusterAvg10.push_back(d);
    t_dtRechitClusterEta.push_back(d);      
  }
}
