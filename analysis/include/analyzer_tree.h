#ifndef analyzer_tree_h
#define analyzer_tree_h

#include "analyzer_objects.h"

class analyzer_tree : public analyzer_objects {

public:
  analyzer_tree();
  virtual ~analyzer_tree();

  virtual void clearTree();
  virtual void setTree();

  //----the miniTree
  TTree *Tree = new TTree("miniTree", "miniTree");

  //----vectors to be filled in miniTree
  std::vector<int> t_Event;
  std::vector<float> t_dtRechitClusterNStation10;
  std::vector<float> t_dtRechitClusterAvgStation10;
  std::vector<float> t_dtRechitClusterEta;

  //----link vectors to branches
  TBranch *bEvent = Tree->Branch("Event", &t_Event);
  TBranch *bdtRechitClusterNStation10 =
      Tree->Branch("dtRechitClusterNStation10", &t_dtRechitClusterNStation10);
  TBranch *bdtRechitClusterAvgStation10 = Tree->Branch(
      "dtRechitClusterAvgStation10", &t_dtRechitClusterAvgStation10);
  TBranch *bdtRechitClusterEta =
      Tree->Branch("dtRechitClusterEta", &t_dtRechitClusterEta);
};

#endif
