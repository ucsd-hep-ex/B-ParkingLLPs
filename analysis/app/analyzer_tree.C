#include "analyzer_tree.h"

//----------------------------analyzer_selections
analyzer_tree::analyzer_tree()
{
}

//----------------------~analyzer_selections
analyzer_tree::~analyzer_tree()
{
}

void analyzer_tree::clearTree(){
  t_Event.clear();
  t_eventW.clear();
 
    
}

void analyzer_tree::setTree(){
  t_Event.push_back(evtNum);
  t_eventW.push_back(eventW);
  for(int i=0; i<tup_CscCluster_list.size(); i++){
    int c = tup_CscCluster_list[i];
    t_cscRechitClusterSize.push_back(cscRechitClusterSize[c]);
  }
  for(int j=0; j< tup_DtCluster_list.size(); j++){
    int d = tup_DtCluster_list[j];
    t_dtRechitClusterSize.push_back(dtRechitClusterSize[d]);
  }
}

