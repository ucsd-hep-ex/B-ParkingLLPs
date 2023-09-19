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
  std::vector<Float_t>   t_cscRechitClusterSize;
  std::vector<Float_t>   t_dtRechitClusterSize;

  //----link vectors to branches
  TBranch* b_Event       = Tree->Branch("Event", &t_Event); 
  TBranch* b_eventW      = Tree->Branch("eventW", &t_eventW); 
  TBranch* b_cscRechitClusterSize = Tree->Branch("cscRechitClusterSize", &t_cscRechitClusterSize); 
  TBranch* b_dtRechitClusterSize = Tree->Branch("dtRechitClusterSize", &t_dtRechitClusterSize); 


};

#endif

