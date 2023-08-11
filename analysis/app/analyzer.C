#define analyzer_cxx
#include "analyzer.h"
#include <TCanvas.h>
#include <TH2.h>
#include <TLorentzVector.h>
#include <TStyle.h>
#include <iomanip>
#include <iostream>
#include <iterator>

using namespace std;

analyzer::analyzer() {}

analyzer::~analyzer() {}

void analyzer::Loop(TFile *f) {
    std::cout << "In Loop" << std::endl;
    fChain->GetListOfBranches();
    if (fChain == 0)
        return;
    Long64_t nentries = fChain->GetEntriesFast();
    Long64_t nbytes = 0, nb = 0;
    std::cout << "nentries: " << nentries << std::endl;
    
    // set up cutFlow entries
    cutFlow.insert(std::pair<TString, float>("No cuts", nentries));
    cutFlowKeys.push_back("No cuts");

    std::vector<TString> keys = {
        "Muon Exists",
        "MuonPt > 7 GeV", 
        "abs(MuonEta) < 1.5",
        "MuonHLTRequirement", 
        "MuonQuality", 
        "HLT", 
        "nDtRechitClusters > 0",
        "DtClusterSize >= 50", 
        "DtPassOverlapLeadMuon", 
        "DtOverlapGenLLP",
        "DtPassRPCMatching", 
        "DtPassMuonVeto", 
        "DtPassMB1Veto", 
        "DtPassRPCTimeCut", 
        "DtPassMB1Adjacent", 
        "DtMaxStation",
        "nCscRechitClusters > 0",
        "CscClusterSize >= 0", 
        "CscPassOverlapLeadMuon", 
        "CscOverlapGenLLP",
        "CscPassME1112Veto", 
        "CscPassMB1Veto", 
        "CscPassRB1Veto", 
        "CscPassMuonVeto", 
        "CscPassClusterTime", 
        "CscPassClusterTimeSpread",
        "CscPassClusterEta", 
        "CscPassID"
    };

    for (const auto& key : keys) {
        cutFlow.insert(std::pair<TString, float>(key, 0));
        cutFlowKeys.push_back(key);
    }

    for (Long64_t jentry = 0; jentry < nentries; jentry++) {
    // for (Long64_t jentry = 0; jentry < 2; jentry++) {


      //Make Event Weight
      Float_t event_weight = 1.0;
      if(isMC) event_weight = 1.0;
      if(jentry==0) std::cout<<"event_weight: "<<event_weight<<std::endl;


      //fill miniTree 
      if (b_doTree){
        f->cd();
        clearTree();
        setTree();
        Tree->Fill();
      } 
      // object lists
      muon_list       =  muonPassSel(muPt, muEta);
      std::vector<std::vector<int>> dummy; 
      dummy.push_back( CscClusterPassSel_test(doesPassHLT()) );
      dummy.push_back( CscClusterPassSel_testOOT(doesPassHLT()) );
      dummy.push_back( CscClusterPassSel_SR(doesPassHLT()) );
      dummy.push_back( CscClusterPassSel_OOT(doesPassHLT()) );
      CscClusterPassSel_all = dummy;
      dummy.clear();
      dummy.push_back( DtClusterPassSel_test(doesPassHLT()) );
      dummy.push_back( DtClusterPassSel_testOOT(doesPassHLT()) );
      dummy.push_back( DtClusterPassSel_SR(doesPassHLT()) );
      dummy.push_back( DtClusterPassSel_OOT(doesPassHLT()) );
      DtClusterPassSel_all = dummy;

      // continue doing the cutflow
      if(doesPassHLT() && b_cutFlow) {
      cutFlow["HLT"] +=1;
      DtClusterPassSel_CutFlow (event_weight);
      CscClusterPassSel_CutFlow(event_weight);
      }

      //Fill the histograms by event
      FillHistos(0, event_weight);
      FillHistos(1, event_weight);
      FillHistos(2, event_weight);
      FillHistos(3, event_weight);


        // Fill the histograms by event
        FillHistos(0);
        FillHistos(1);
        FillHistos(2);
        FillHistos(3);
        FillHistos(4);
        FillHistos(5);
    } // end jentries

    // Write miniTree
    if (b_doTree) {
        f->cd();
        Tree->CloneTree()->Write();
        f->Close();
    }
  
    // print cutFlow table
    if (b_cutFlow) {
        int width = 30;
        for (int c = 0; c < cutFlowKeys.size(); c++) {
            std::cout << '\t' << setw(width) << left << cutFlowKeys[c] << "," << '\t'
                      << setw(width) << left << cutFlow[cutFlowKeys[c]] << '\n';
        }
    }
  
    std::cout << "isMC?: " << isMC << std::endl;
    std::cout << "Make Tree?: " << b_doTree << std::endl;
    std::cout << "Counter: " << counter << std::endl;
    std::cout << "Counter2: " << counter2 << std::endl;
    WriteHistos(0);
    WriteHistos(1);
    WriteHistos(2);
    WriteHistos(3);
    WriteHistos(4);
    WriteHistos(5);
}
