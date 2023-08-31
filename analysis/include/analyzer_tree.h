#ifndef analyzer_tree_h
#define analyzer_tree_h

#include "analyzer_objects.h"

class analyzer_tree : public analyzer_objects{

  public : 
 
           analyzer_tree();
  virtual ~analyzer_tree();

  virtual void clearTree();
  virtual void setTree();

  //----the miniTree
  TTree* Tree = new TTree("miniTree","miniTree");

  //----vectors to be filled in miniTree
  std::vector<int>   t_Event;
  std::vector<Float_t>   t_eventW;

  //----link vectors to branches
  TBranch* bEvent       = Tree->Branch("Event", &t_Event); 
  TBranch* beventW      = Tree->Branch("eventW", &t_eventW); 


};

#endif

