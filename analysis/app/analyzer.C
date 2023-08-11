#define analyzer_cxx
#include "analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <iterator>
#include <iostream>
#include <iomanip>

using namespace std;

analyzer::analyzer() 
{
}

analyzer::~analyzer()
{
}

void analyzer::Loop(TFile *f)
{
   std::cout<<"In Loop"<<std::endl;
   fChain->GetListOfBranches();
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   //Long64_t nentries = 10000000;
   Long64_t nbytes = 0, nb = 0;
   std::cout<<"nentries: "<<nentries<<std::endl;

   //set up cutFlow entries
   cutFlow.insert(std::pair<TString, float> ("No cuts", nentries));            cutFlowKeys.push_back("No cuts");
   cutFlow.insert(std::pair<TString, float> ("Muon Exists", 0));               cutFlowKeys.push_back("Muon Exists");
   cutFlow.insert(std::pair<TString, float> ("MuonPt > 7 GeV", 0));            cutFlowKeys.push_back("MuonPt > 7 GeV");
   cutFlow.insert(std::pair<TString, float> ("abs(MuonEta) < 1.5", 0));        cutFlowKeys.push_back("abs(MuonEta) < 1.5");
   cutFlow.insert(std::pair<TString, float> ("MuonHLTRequirement", 0));        cutFlowKeys.push_back("MuonHLTRequirement");
   cutFlow.insert(std::pair<TString, float> ("MuonQuality", 0));               cutFlowKeys.push_back("MuonQuality");
   cutFlow.insert(std::pair<TString, float> ("HLT", 0));                       cutFlowKeys.push_back("HLT");
   //-- Dts
   cutFlow.insert(std::pair<TString, float> ("nDtRechitClusters > 0", 0));     cutFlowKeys.push_back("nDtRechitClusters > 0");
   cutFlow.insert(std::pair<TString, float> ("DtClusterSize >= 50", 0));       cutFlowKeys.push_back("DtClusterSize >= 50");
   cutFlow.insert(std::pair<TString, float> ("DtPassOverlapLeadMuon", 0));     cutFlowKeys.push_back("DtPassOverlapLeadMuon");
   cutFlow.insert(std::pair<TString, float> ("DtOverlapGenLLP", 0));           cutFlowKeys.push_back("DtOverlapGenLLP");
   cutFlow.insert(std::pair<TString, float> ("DtPassRPCMatching", 0));         cutFlowKeys.push_back("DtPassRPCMatching");
   cutFlow.insert(std::pair<TString, float> ("DtPassMuonVeto", 0));            cutFlowKeys.push_back("DtPassMuonVeto");
   cutFlow.insert(std::pair<TString, float> ("DtPassMB1Veto", 0));             cutFlowKeys.push_back("DtPassMB1Veto");
   cutFlow.insert(std::pair<TString, float> ("DtPassRPCTimeCut", 0));          cutFlowKeys.push_back("DtPassRPCTimeCut");
   cutFlow.insert(std::pair<TString, float> ("DtPassMB1Adjacent", 0));         cutFlowKeys.push_back("DtPassMB1Adjacent");
   //-- CSCs
   cutFlow.insert(std::pair<TString, float> ("nCscRechitClusters > 0", 0));    cutFlowKeys.push_back("nCscRechitClusters > 0");
   cutFlow.insert(std::pair<TString, float> ("CscClusterSize >= 0", 0));       cutFlowKeys.push_back("CscClusterSize >= 0");
   cutFlow.insert(std::pair<TString, float> ("CscPassOverlapLeadMuon", 0));    cutFlowKeys.push_back("CscPassOverlapLeadMuon");
   cutFlow.insert(std::pair<TString, float> ("CscOverlapGenLLP", 0));          cutFlowKeys.push_back("CscOverlapGenLLP");
   cutFlow.insert(std::pair<TString, float> ("CscPassME1112Veto", 0));         cutFlowKeys.push_back("CscPassME1112Veto");
   cutFlow.insert(std::pair<TString, float> ("CscPassMB1Veto", 0));            cutFlowKeys.push_back("CscPassMB1Veto");
   cutFlow.insert(std::pair<TString, float> ("CscPassRB1Veto", 0));            cutFlowKeys.push_back("CscPassRB1Veto");
   cutFlow.insert(std::pair<TString, float> ("CscPassMuonVeto", 0));           cutFlowKeys.push_back("CscPassMuonVeto");
   cutFlow.insert(std::pair<TString, float> ("CscPassClusterTime", 0));        cutFlowKeys.push_back("CscPassClusterTime");
   cutFlow.insert(std::pair<TString, float> ("CscPassClusterTimeSpread", 0));  cutFlowKeys.push_back("CscPassClusterTimeSpread");
   cutFlow.insert(std::pair<TString, float> ("CscPassClusterEta", 0));         cutFlowKeys.push_back("CscPassClusterEta");
   cutFlow.insert(std::pair<TString, float> ("CscPassID", 0));                 cutFlowKeys.push_back("CscPassID");


   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (jentry %1000000 == 0) std::cout<<"Event: "<<jentry<<" -of- "<<nentries<<std::endl;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

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

   }//end jentries
   //Write miniTree
   if (b_doTree){
     f->cd();
     Tree->CloneTree()->Write();
     f->Close();
   }
   //print cutFlow table
   if(b_cutFlow){
     int width = 30;
     for (int c = 0; c<cutFlowKeys.size(); c++) {
      std::cout << '\t'<<setw(width)<<left<< cutFlowKeys[c] <<","<< '\t'<<setw(width)<<left<< cutFlow[cutFlowKeys[c]]
           << '\n';
     }
   }
   std::cout<<"isMC?: "<<isMC<<std::endl;
   std::cout<<"Make Tree?: "<<b_doTree<<std::endl;
   std::cout<<"Counter: "<<counter<<std::endl;
   std::cout<<"Counter2: "<<counter2<<std::endl;
   WriteHistos(0);
   WriteHistos(1);
   WriteHistos(2);
   WriteHistos(3);
   
}

