#ifndef analyzer_tree_h
#define analyzer_tree_h

#include "analyzer_objects.h"

class analyzer_tree : public analyzer_objects {

public:
  analyzer_tree();
  virtual ~analyzer_tree();

  // Clear the tree variables
  virtual void clearTree();
  
  // Set up the tree structure
  virtual void setTree();

  // The miniTree object
  TTree *Tree = new TTree("miniTree", "miniTree");

  // Vectors to be filled in the miniTree
  std::vector<int>   t_Event;  // Event variable
  std::vector<int>   t_dtRechitClusterN10;  // Event variable
  std::vector<float> t_dtRechitClusterAvg10;  // Event variable
  std::vector<float> t_dtRechitClusterEta;  // Event variable


  // Link vectors to branches in the miniTree
  TBranch *bEvent                = Tree->Branch("Event", &t_Event);  // Branch for Event variable
  TBranch *bdtRechitClusterN10   = Tree->Branch("dtRechitClusterN10", &t_dtRechitClusterN10);  // Branch for Event variable
  TBranch *bdtRechitClusterAvg10 = Tree->Branch("dtRechitClusterAvg10", &t_dtRechitClusterAvg10);  // Branch for Event variable
  TBranch *bdtRechitClusterEta   = Tree->Branch("dtRechitClusterEta", &t_dtRechitClusterEta);  // Branch for Event variable
  
};

#endif
