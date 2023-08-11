#include "analyzer_tree.h"

// Constructor
analyzer_tree::analyzer_tree() {}

// Destructor
analyzer_tree::~analyzer_tree() {}

// Clear the tree data
void analyzer_tree::clearTree() { 
    t_Event.clear(); 
    t_dtRechitClusterNStation10.clear();
    t_dtRechitClusterAvgStation10.clear();
    t_dtRechitClusterMaxStation.clear();
    
    t_dtRechitClusterEta.clear();
}

// Set the tree data
void analyzer_tree::setTree() {
    t_Event.push_back(evtNum); 

    for (int i = 0; i < DtClusterPassSel_all[0].size(); i++) {
        int d = DtClusterPassSel_all[0][i];
        t_dtRechitClusterNStation10.push_back(dtRechitClusterNStation10[d]);
        t_dtRechitClusterAvgStation10.push_back(dtRechitClusterAvgStation10[d]);
        t_dtRechitClusterMaxStation.push_back(dtRechitClusterMaxStation[d]);
        
        t_dtRechitClusterEta.push_back(dtRechitClusterEta[d]); 
    }
}

