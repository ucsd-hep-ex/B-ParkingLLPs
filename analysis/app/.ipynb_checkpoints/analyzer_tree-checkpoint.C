#include "analyzer_tree.h"

//----------------------------analyzer_selections
analyzer_tree::analyzer_tree() {}

//----------------------~analyzer_selections
analyzer_tree::~analyzer_tree() {}

void analyzer_tree::clearTree() { 
  t_Event.clear(); 
  t_dtRechitClusterNStation10.clear();
  t_dtRechitClusterAvgStation10.clear();
  t_dtRechitClusterEta.clear();
}

void analyzer_tree::setTree() {
  t_Event.push_back(evtNum); 

  for(int i=0; i < DtClusterPassSel_all[0].size(); i++){
    int d = DtClusterPassSel_all[0][i];
    t_dtRechitClusterNStation10.push_back(dtRechitClusterNStation10[d]);
    t_dtRechitClusterAvgStation10.push_back(dtRechitClusterAvgStation10[d]);
    t_dtRechitClusterEta.push_back(dtRechitClusterEta[d]);      
  }
}
