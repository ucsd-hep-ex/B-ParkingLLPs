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
}

//evnt weight
//cluster size
// does pass dt
    //max station
//does pass csc
    //ID
    //dphi