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
  t_dtRechitClusterNStation10.push_back(evtNum);
  t_dtRechitClusterAvgStation10.push_back(evtNum);
  t_dtRechitClusterEta.push_back(evtNum);
}
