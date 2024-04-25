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

Float_t ctau_reweighter(Float_t t, Float_t tau0, Float_t tau1) {
    Float_t numerator = (1.0f / tau1) * expf(-t / tau1);
    Float_t denominator = (1.0f / tau0) * expf(-t / tau0);

    return numerator / denominator;
}

Float_t genFilterEff(TString sample) {

    Float_t GenFilterEff;
//    if(sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau3000" || sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau3000"){
//        GenFilterEff = 0.094442;
//    }else if(sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau500" || sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p5_ctau500"){
//        GenFilterEff = 0.257718;
//    }else if(sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau5000" || sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p5_ctau5000"){
//        GenFilterEff = 0.0950152;
//    }else if(sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau10000" || sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau10000"){
//        GenFilterEff = 0.0907816;
//    }else if(sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau2000" || sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau2000"){
//        GenFilterEff = 0.252473;
//    }else if(sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau10000" || sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau10000"){
//        GenFilterEff = 0.127579;
//    }else if(sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau3000" || sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau3000"){
//        GenFilterEff = 0.239329;
//    }else if(sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau10000" || sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau10000"){
//        GenFilterEff = 0.146031;
//    }else{
//        GenFilterEff = 1.0;
//    }

    if(sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau1000"){
      GenFilterEff = 0.2133676092544987;
    }else if(sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300"){
      GenFilterEff = 0.2913132061492869;
    }else if(sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300"){
      GenFilterEff = 0.2919021657580153;
    }else if(sample == "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau1000"){
      GenFilterEff = 0.2140541025727333;
    }else{
      GenFilterEff = 1.0;
    }
    return GenFilterEff;
}

Double_t clusterSizeResponseFactor (TString muon_station) {
    if (muon_station == "CSC") {
        return 220 / 275;
    } else if (muon_station == "DT") {
        return 110 / 136;
    }
}

void analyzer::Loop(TFile *f, Float_t from_ctau, Float_t to_ctau, TString theSample, Float_t NEvents)
{
   // Cross-section in femtobarns. 0.4=fragmentation fraction
   const float SIGMA = (1/0.4)*5.72E11;
   std::cout<<theSample<<std::endl;
   std::cout<<"In Loop"<<std::endl;
   fChain->GetListOfBranches();
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   //Long64_t nentries = 100;
   Long64_t nbytes = 0, nb = 0;
   std::cout<<"nentries: "<<nentries<<std::endl;

   //set up cutFlow entries
   cutFlow.insert(std::pair<TString, float> ("No cuts", 0));                   cutFlowKeys.push_back("No cuts");
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
   cutFlow.insert(std::pair<TString, float> ("DtPassMaxStation", 0));          cutFlowKeys.push_back("DtPassMaxStation");

   //-- CSCs
   cutFlow.insert(std::pair<TString, float> ("nCscRechitClusters > 0", 0));    cutFlowKeys.push_back("nCscRechitClusters > 0");
   cutFlow.insert(std::pair<TString, float> ("CscClusterSize >= 0", 0));       cutFlowKeys.push_back("CscClusterSize >= 0");
   cutFlow.insert(std::pair<TString, float> ("CscPassOverlapLeadMuon", 0));    cutFlowKeys.push_back("CscPassOverlapLeadMuon");
   cutFlow.insert(std::pair<TString, float> ("CscOverlapGenLLP", 0));          cutFlowKeys.push_back("CscOverlapGenLLP");
   cutFlow.insert(std::pair<TString, float> ("CscPassME1112Veto", 0));         cutFlowKeys.push_back("CscPassME1112Veto");
   cutFlow.insert(std::pair<TString, float> ("CscPassMB1Veto", 0));            cutFlowKeys.push_back("CscPassMB1Veto");
   cutFlow.insert(std::pair<TString, float> ("CscPassRB1Veto", 0));            cutFlowKeys.push_back("CscPassRB1Veto");
   cutFlow.insert(std::pair<TString, float> ("CscPassRE12Veto", 0));           cutFlowKeys.push_back("CscPassRE12Veto");
   cutFlow.insert(std::pair<TString, float> ("CscPassMuonVeto", 0));           cutFlowKeys.push_back("CscPassMuonVeto");
   cutFlow.insert(std::pair<TString, float> ("CscPassClusterTime", 0));        cutFlowKeys.push_back("CscPassClusterTime");
   cutFlow.insert(std::pair<TString, float> ("CscPassClusterTimeSpread", 0));  cutFlowKeys.push_back("CscPassClusterTimeSpread");
   cutFlow.insert(std::pair<TString, float> ("CscPassClusterEta", 0));         cutFlowKeys.push_back("CscPassClusterEta");
   cutFlow.insert(std::pair<TString, float> ("CscPassID", 0));                 cutFlowKeys.push_back("CscPassID");


   bool found = true;
   TFile *OPT_Histos;
   TFile *f_Weights;
   TH2F * n_events_CSC_A;
   TH2F * n_events_CSC_B;
   TH2F * n_events_CSC_C;
   TH2F * n_events_CSC_D;

   TH2F * n_events_DT_A;
   TH2F * n_events_DT_B;
   TH2F * n_events_DT_C;
   TH2F * n_events_DT_D;
   //f_Weights = TFile::Open("roots/Weights.root","recreate");
   //TH1F * h_Wctau = new TH1F("h_Wctau", "h_Wctau", 100, 0.,5.);

   if (isMC) {
       for (int k = 0; k < 200 /*cscRechitClusterSize.size()*/; k++) {
           cscRechitClusterSize[k] *= clusterSizeResponseFactor("CSC");
       }
       for (int k = 0; k < 200 /*dtRechitClusterSize.size()*/; k++) {
           dtRechitClusterSize[k] *= clusterSizeResponseFactor("DT");
       }
   }

   if(doScan){
     OPT_Histos = TFile::Open("roots/OPT_Histos.root","RECREATE");
     n_events_CSC_A = new TH2F("NeventsCSC_A", "NeventsCSC_A", 42, 1.2, 5.4, 42, 80, 500);
     n_events_CSC_B = new TH2F("NeventsCSC_B", "NeventsCSC_B", 42, 1.2, 5.4, 42, 80, 500);
     n_events_CSC_C = new TH2F("NeventsCSC_C", "NeventsCSC_C", 42, 1.2, 5.4, 42, 80, 500);
     n_events_CSC_D = new TH2F("NeventsCSC_D", "NeventsCSC_D", 42, 1.2, 5.4, 42, 80, 500);

     n_events_DT_A = new TH2F("NeventsDT_A", "NeventsDT_A", 42, 1.2, 5.4, 42, 80, 500);
     n_events_DT_B = new TH2F("NeventsDT_B", "NeventsDT_B", 42, 1.2, 5.4, 42, 80, 500);
     n_events_DT_C = new TH2F("NeventsDT_C", "NeventsDT_C", 42, 1.2, 5.4, 42, 80, 500);
     n_events_DT_D = new TH2F("NeventsDT_D", "NeventsDT_D", 42, 1.2, 5.4, 42, 80, 500);
   }

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (jentry %10000 == 0) std::cout<<"Event: "<<jentry<<" -of- "<<nentries<<std::endl;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      //Make MuonList
      muon_list       =  muonPassSel(muPt, muEta);
       
      //Make Event Weight event_weight=(sigma*Lumi)*genLLPFilterEffSF*TriggerEffSF*[1/Sum GenWeight]*PUWeight*genMuonFilterEff*genEventWeight
      Float_t event_weight = 1.0;
     
      if(isMC) event_weight = SIGMA*
                              ctau_reweighter(gLLP_ctau, from_ctau, to_ctau)*
                              pileupWeight*
                              genFilterEff(theSample)*
                              genMuonFilterEff*
                              (1./NEvents);
       
      if(isMC && muon_list.size()>0) event_weight=event_weight*lepSF[muon_list[0]];
      // Just print 
      if(muon_list.size()>0 && found) {
        std::cout<<"sample: "        <<theSample<<
                   "  event_weight: "<<event_weight<<
                   "  event: "       <<jentry<<
                   "  NMuons: "      <<muon_list.size()<<
                   "  w_ctau: "      <<ctau_reweighter(gLLP_ctau, from_ctau, to_ctau)<<
                   "  PUweight: "    <<pileupWeight<<
                   "  lepSF: "       <<lepSF[muon_list[0]]<<
                   "  genFilterEff: "<<genFilterEff(theSample)<<
                   "  genMuonFilterEff: "<<genMuonFilterEff<<
                   "  NEvents-total: "<<NEvents<<
                   std::endl; 
        found = false;
      }
      //saving in the global variable 
      eventW = event_weight;
      //counter+=ctau_reweighter(gLLP_ctau, from_ctau, to_ctau); 
      //counter2+=genFilterEff(theSample)*ctau_reweighter(gLLP_ctau, from_ctau, to_ctau); 
      //counter2+=0.0950152*ctau_reweighter(gLLP_ctau, from_ctau, to_ctau); 
      //h_Wctau->Fill(ctau_reweighter(gLLP_ctau, from_ctau, to_ctau));
      //fill miniTree 
      if (b_doTree){
        f->cd();
        clearTree();
        setTree();
        Tree->Fill();
      } 
      // object lists
      std::vector<std::vector<int>> dummy; 
      dummy.push_back( CscClusterPassSel_Fail    (doesPassHLT()) );
      dummy.push_back( CscClusterPassSel_FailOOT (doesPassHLT()) );
      dummy.push_back( CscClusterPassSel_Pass    (doesPassHLT()) );
      dummy.push_back( CscClusterPassSel_PassOOT (doesPassHLT()) );
      dummy.push_back( CscClusterPassSel_nominal (doesPassHLT()) );

      CscClusterPassSel_all = dummy;
      dummy.clear();
      dummy.push_back( DtClusterPassSel_Fail   (doesPassHLT()) );
      dummy.push_back( DtClusterPassSel_FailOOT(doesPassHLT()) );
      dummy.push_back( DtClusterPassSel_Pass   (doesPassHLT()) );
      dummy.push_back( DtClusterPassSel_PassOOT(doesPassHLT()) );
      dummy.push_back( DtClusterPassSel_nominal(doesPassHLT()) );
      DtClusterPassSel_all = dummy;

      if(doScan){
        int cls_cut_min = 80;
        float dphi_cut_min = 1.2;
        int Nbins =42;
        if (muon_list.size() != 0) {
          for (int i = 0; i < Nbins; i++) { // dphi cuts
            for (int j = 0; j < Nbins; j++) { // cluster cuts
              int   cls_cut  = cls_cut_min  +  j*10;
              float dphi_cut = dphi_cut_min +  i*0.1;
              bool pass = false;
              for (int k = 0; k < CscClusterPassSel_nominal(doesPassHLT()).size(); k++) {
                if (pass) break;
                float dphi = DeltaPhi(cscRechitClusterPhi[CscClusterPassSel_nominal(doesPassHLT())[k]], lepPhi[muon_list[0]]);
                if      (cscRechitClusterSize[CscClusterPassSel_nominal(doesPassHLT())[k]] >= cls_cut && dphi >= dphi_cut) { // Region A
                    n_events_CSC_A->SetBinContent(i+1, j+1, n_events_CSC_A->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
                else if (cscRechitClusterSize[CscClusterPassSel_nominal(doesPassHLT())[k]] >= cls_cut && dphi < dphi_cut ) { // Region B
                    n_events_CSC_B->SetBinContent(i+1, j+1, n_events_CSC_B->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
                else if (cscRechitClusterSize[CscClusterPassSel_nominal(doesPassHLT())[k]] < cls_cut  && dphi >= dphi_cut) { // Region C
                    n_events_CSC_C->SetBinContent(i+1, j+1, n_events_CSC_C->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
                else if (cscRechitClusterSize[CscClusterPassSel_nominal(doesPassHLT())[k]] < cls_cut  && dphi < dphi_cut ) { // Region D
                    n_events_CSC_D->SetBinContent(i+1, j+1, n_events_CSC_D->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
              }
              pass = false;
              // cout<<cls_cut<<endl;
              // cout<<dphi_cut<<endl;
              for (int k = 0; k < DtClusterPassSel_nominal(doesPassHLT()).size(); k++) {
                if (pass) break;
                float dphi = DeltaPhi(dtRechitClusterPhi[DtClusterPassSel_nominal(doesPassHLT())[k]], lepPhi[muon_list[0]]);
                if      (dtRechitClusterSize[DtClusterPassSel_nominal(doesPassHLT())[k]] >= cls_cut && dphi >= dphi_cut) { // Region A
                    n_events_DT_A->SetBinContent(i+1, j+1, n_events_DT_A->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
                else if (dtRechitClusterSize[DtClusterPassSel_nominal(doesPassHLT())[k]] >= cls_cut && dphi < dphi_cut ) { // Region B
                    n_events_DT_B->SetBinContent(i+1, j+1, n_events_DT_B->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
                else if (dtRechitClusterSize[DtClusterPassSel_nominal(doesPassHLT())[k]] < cls_cut  && dphi >= dphi_cut) { // Region C
                    n_events_DT_C->SetBinContent(i+1, j+1, n_events_DT_C->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
                else if (dtRechitClusterSize[DtClusterPassSel_nominal(doesPassHLT())[k]] < cls_cut  && dphi < dphi_cut ) { // Region D
                    n_events_DT_D->SetBinContent(i+1, j+1, n_events_DT_D->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
              }
            }
          }
        }//if (muon_list.size() != 0)
      }//if(doScan)


      tup_DtCluster_list.clear();
      tup_DtCluster_list = DtClusterPassSel_nominal(doesPassHLT());
      tup_CscCluster_list.clear();
      tup_CscCluster_list = CscClusterPassSel_nominal(doesPassHLT());

      if(b_cutFlow) cutFlow["No cuts"] += event_weight;

      muonPassSel_cutflow(muPt, muEta, event_weight);
       
      // continue doing the cutflow
      if(doesPassHLT() && b_cutFlow && muon_list.size() > 0) { 
      cutFlow["HLT"] += event_weight;

      
      DtClusterPassSel_CutFlow (event_weight);
      CscClusterPassSel_CutFlow(event_weight);
      }
       
      //Fill the histograms by event
      FillHistos(0, event_weight);
      FillHistos(1, event_weight);
      FillHistos(2, event_weight);
      FillHistos(3, event_weight);
      FillHistos(4, event_weight);


   }//end jentries
   //std::cout<<"h_WctauMean "<<h_Wctau->GetMean()<<std::endl;
   //f_Weights->cd();
   //h_Wctau->Write();
   //f_Weights->Close();

   if(doScan){
     OPT_Histos->cd();
     n_events_CSC_A->Write();
     n_events_CSC_B->Write();
     n_events_CSC_C->Write();
     n_events_CSC_D->Write();
     n_events_DT_A ->Write();
     n_events_DT_B ->Write();
     n_events_DT_C ->Write();
     n_events_DT_D ->Write();
     OPT_Histos->Close();
   }
   //Write miniTree
   if (b_doTree){
     f->cd();
     Tree->CloneTree()->Write();
     f->Close();
   }
   //print cutFlow table
   if(b_cutFlow){
     // cutFlow["No Cuts"] = counter;

     int width = 30;
     for (int c = 0; c<cutFlowKeys.size(); c++) {
      std::cout << '\t'<<setw(width)<<left<< cutFlowKeys[c] <<","<< '\t'<<setw(width)<<left<< cutFlow[cutFlowKeys[c]]
           << '\n';
     }
   }
   std::cout<<"isMC?: "<<isMC<<std::endl;
   std::cout<<"Make Tree?: "<<b_doTree<<std::endl;
   std::cout<<"Counter (Sum Wctau): "<<counter<<std::endl;
   std::cout<<"Counter2 (Sum Wctau*LLPDecayEff): "<<counter2<<std::endl;
   WriteHistos(0);
   WriteHistos(1);
   WriteHistos(2);
   WriteHistos(3);
   WriteHistos(4);

}

