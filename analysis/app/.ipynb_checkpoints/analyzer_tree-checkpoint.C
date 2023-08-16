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
}

void analyzer_tree::setTree(){
  t_Event.push_back(evtNum);
}

