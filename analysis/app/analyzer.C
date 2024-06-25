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
const std::map<int, double> DecayEff_M0p3_300  = { {1, 0.000212707}, {3, 0.00367283}, {5, 0.00985236}, {7, 0.0172625}, {10, 0.0291508}, {30, 0.098065}, {50, 0.145035}, {70, 0.17793}, {100, 0.210862}, {300, 0.258932}, {500, 0.241418}, {700, 0.212747}, {1000, 0.154672}, {3000, 0.0245574}, {5000, 0.0140187}, {7000, 0.0109439}, {10000, 0.00906553}, };
const std::map<int, double> DecayEff_M0p3_1000 = { {1, 0.000100618}, {3, 0.00254258}, {5, 0.00800441}, {7, 0.0150262}, {10, 0.0266616}, {30, 0.0960547}, {50, 0.143494}, {70, 0.176623}, {100, 0.209753}, {300, 0.257636}, {500, 0.239831}, {700, 0.216861}, {1000, 0.186889}, {3000, 0.0931888}, {5000, 0.0591638}, {7000, 0.0432097}, {10000, 0.0318571}, };
const std::map<int, double> DecayEff_M0p3_3000 = { {1, 3.19287e-06}, {3, 0.00115684}, {5, 0.0048204}, {7, 0.0100535}, {10, 0.0195385}, {30, 0.0865576}, {50, 0.135586}, {70, 0.170079}, {100, 0.204531}, {300, 0.254481}, {500, 0.237463}, {700, 0.215004}, {1000, 0.185533}, {3000, 0.094442}, {5000, 0.0628719}, {7000, 0.0456011}, {10000, 0.0300701}, };

const std::map<int, double> DecayEff_M0p5_500  = { {1, 3.77367e-06}, {3, 0.000629733}, {5, 0.00289072}, {7, 0.00647825}, {10, 0.0131938}, {30, 0.0614839}, {50, 0.0998057}, {70, 0.129796}, {100, 0.164053}, {300, 0.249964}, {500, 0.257718}, {700, 0.248426}, {1000, 0.228888}, {3000, 0.16045}, {5000, 0.141178}, {7000, 0.132671}, {10000, 0.126259}, };
const std::map<int, double> DecayEff_M0p5_5000 = { {1, 3.32679e-08}, {3, 0.000327521}, {5, 0.00226438}, {7, 0.00549864}, {10, 0.0114807}, {30, 0.0572667}, {50, 0.0968001}, {70, 0.12804}, {100, 0.163598}, {300, 0.252375}, {500, 0.260743}, {700, 0.251347}, {1000, 0.230423}, {3000, 0.135273}, {5000, 0.0950152}, {7000, 0.0733655}, {10000, 0.0548025}, };

const std::map<int, double> DecayEff_M1_1000  = { {1, 1.58719e-06}, {3, 0.000436579}, {5, 0.00146078}, {7, 0.00281546}, {10, 0.00531544}, {30, 0.0280819}, {50, 0.0518268}, {70, 0.0731419}, {100, 0.100674}, {300, 0.20359}, {500, 0.241852}, {700, 0.255632}, {1000, 0.25756}, {3000, 0.195259}, {5000, 0.158016}, {7000, 0.138829}, {10000, 0.123611}, };
const std::map<int, double> DecayEff_M1_10000 = { {1, 3.43275e-10}, {3, 6.0315e-05}, {5, 0.000552854}, {7, 0.00144642}, {10, 0.00322973}, {30, 0.0247581}, {50, 0.0500272}, {70, 0.0725855}, {100, 0.101274}, {300, 0.207775}, {500, 0.247514}, {700, 0.261634}, {1000, 0.263282}, {3000, 0.194883}, {5000, 0.14726}, {7000, 0.117929}, {10000, 0.0907816}, };

const std::map<int, double> DecayEff_M2_2000  = { {1, 2.54035e-13}, {3, 2.08154e-06}, {5, 4.82268e-05}, {7, 0.0002002}, {10, 0.000650378}, {30, 0.00906239}, {50, 0.0218598}, {70, 0.0354108}, {100, 0.0548716}, {300, 0.146233}, {500, 0.196283}, {700, 0.225008}, {1000, 0.246836}, {2000, 0.252473}, {3000, 0.232328}, {5000, 0.190787}, {7000, 0.161788}, {10000, 0.135619}, };
const std::map<int, double> DecayEff_M2_10000 = { {1, 5.36051e-17}, {3, 4.29226e-07}, {5, 3.50064e-05}, {7, 0.000232487}, {10, 0.000989261}, {30, 0.013645}, {50, 0.0280934}, {70, 0.0412442}, {100, 0.059097}, {300, 0.14649}, {500, 0.196192}, {700, 0.224438}, {1000, 0.245474}, {3000, 0.229871}, {5000, 0.189518}, {7000, 0.159104}, {10000, 0.127579}, };

const std::map<int, double> DecayEff_M3_3000  = { {1, 7.72181e-22}, {3, 6.33557e-09}, {5, 1.93e-06}, {7, 2.07529e-05}, {10, 0.000122248}, {30, 0.00386146}, {50, 0.011704}, {70, 0.0212436}, {100, 0.0362698}, {300, 0.117752}, {500, 0.168509}, {700, 0.200698}, {1000, 0.228747}, {3000, 0.239329}, {5000, 0.20582}, {7000, 0.178628}, {10000, 0.151509}, };
const std::map<int, double> DecayEff_M3_10000 = { {1, 6.38056e-24}, {3, 1.65837e-09}, {5, 1.27692e-06}, {7, 2.27757e-05}, {10, 0.000196286}, {30, 0.00585752}, {50, 0.0143705}, {70, 0.0240373}, {100, 0.0392737}, {300, 0.122177}, {500, 0.172873}, {700, 0.204767}, {1000, 0.232418}, {3000, 0.241803}, {5000, 0.207522}, {7000, 0.178299}, {10000, 0.146031}, };
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

Float_t genFilterEff(TString sample, int to_ctau) {

    Float_t GenFilterEff;
    std::map<int, double> theMap;   

    if(sample.Contains("mPhi0p3_ctau300"))        theMap = DecayEff_M0p3_300; // GenFilterEff =0.258932;  
    else if(sample.Contains("mPhi0p3_ctau1000"))  theMap = DecayEff_M0p3_1000;// GenFilterEff =0.186889;  
    else if(sample.Contains("mPhi0p3_ctau3000"))  theMap = DecayEff_M0p3_3000;// GenFilterEff =0.094442;  
    else if(sample.Contains("mPhi0p5_ctau500"))   theMap = DecayEff_M0p5_500; // GenFilterEff =0.257718;  
    else if(sample.Contains("mPhi0p5_ctau5000"))  theMap = DecayEff_M0p5_5000;// GenFilterEff =0.0950152; 
    else if(sample.Contains("mPhi1p0_ctau1000"))  theMap = DecayEff_M1_1000;  // GenFilterEff =0.25756;   
    else if(sample.Contains("mPhi1p0_ctau10000")) theMap = DecayEff_M1_10000; // GenFilterEff =0.0907816; 
    else if(sample.Contains("mPhi2p0_ctau2000"))  theMap = DecayEff_M2_2000;  // GenFilterEff =0.252473;  
    else if(sample.Contains("mPhi2p0_ctau10000")) theMap = DecayEff_M2_10000; // GenFilterEff =0.127579;  
    else if(sample.Contains("mPhi3p0_ctau3000"))  theMap = DecayEff_M3_3000;  // GenFilterEff =0.239329;  
    else if(sample.Contains("mPhi3p0_ctau10000")) theMap = DecayEff_M3_10000; // GenFilterEff =0.146031;  
    else{
      return GenFilterEff = 1.0;
    }
    auto it = theMap.find(to_ctau);
    if (it != theMap.end()) GenFilterEff = theMap.at(to_ctau);
    else GenFilterEff = 1.0;

    return GenFilterEff;
}

Double_t clusterSizeResponseFactor (TString muon_station) {
    float SF;
    if (muon_station == "CSC") {
        SF =  310. / 407.;
    } else if (muon_station == "DT") {
        SF = 160. / 218.;
    }
    return SF;
}

void analyzer::Loop(TFile *f, Float_t from_ctau, Float_t to_ctau, TString theSample, Float_t NEvents)
{
   int i_to_ctau = static_cast<int>(to_ctau*10.);    
   std::cout<<i_to_ctau<<"  "<<genFilterEff(theSample,i_to_ctau)<<std::endl;
   // Cross-section in femtobarns. 0.4=fragmentation fraction
   const float SIGMA = (1/0.4)*5.72E11;
   std::cout<<theSample<<std::endl;
   std::cout<<"In Loop"<<std::endl;
   fChain->GetListOfBranches();
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   //Long64_t nentries = 100000;
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
                              genFilterEff(theSample, i_to_ctau)*
                              genMuonFilterEff*
                              (1./NEvents);
       
      if(isMC && muon_list.size()>0) event_weight=event_weight*lepSF[muon_list[0]];
      //if(isMC && muon_list.size()>0) event_weight=event_weight*lepSFup[muon_list[0]];
      //if(isMC && muon_list.size()>0) event_weight=event_weight*lepSFdn[muon_list[0]];
      // Just print 
      if(muon_list.size()>0 && found) {
        std::cout<<"sample: "        <<theSample<<
                   "  event_weight: "<<event_weight<<
                   "  event: "       <<jentry<<
                   "  NMuons: "      <<muon_list.size()<<
                   "  w_ctau: "      <<ctau_reweighter(gLLP_ctau, from_ctau, to_ctau)<<
                   "  PUweight: "    <<pileupWeight<<
                   "  lepSF: "       <<lepSF[muon_list[0]]<<
                   "  genFilterEff: "<<genFilterEff(theSample, to_ctau)<<
                   "  genMuonFilterEff: "<<genMuonFilterEff<<
                   "  NEvents-total: "<<NEvents<<
                   std::endl; 
        //std::cout<<"Pt:"<<lepPt[muon_list[0]]<<"  IPSig:"<<lepDXYErr[muon_list[0]]<<"  SF:"<<lepSF[muon_list[0]]<<"  SFup:"<<lepSFup[muon_list[0]]<<"  SFdn:"<<lepSFdn[muon_list[0]]<<std::endl;
        found = false;
      }
      //saving in the global variable 
      eventW = event_weight;
      if (isMC) {
          for (int k = 0; k < 200; k++) {
              cscRechitClusterSize[k] *= clusterSizeResponseFactor("CSC");
          }
          for (int k = 0; k < 200; k++) {
              dtRechitClusterSize[k] *= clusterSizeResponseFactor("DT");
          }
      }
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
      //If this changes check indices used below for the PassSel_all vectors
      std::vector<std::vector<int>> dummy; 
      dummy.push_back( CscClusterPassSel_Fail    (doesPassHLT()) );
      dummy.push_back( CscClusterPassSel_FailOOT (doesPassHLT()) );
      dummy.push_back( CscClusterPassSel_Pass    (doesPassHLT()) );
      dummy.push_back( CscClusterPassSel_PassOOT (doesPassHLT()) );
      dummy.push_back( CscClusterPassSel_nominal (doesPassHLT()) );
      dummy.push_back( CscClusterPassSel_nominalPlusTime (doesPassHLT()) );
      dummy.push_back( CscClusterPassSel_PassCS (doesPassHLT()) );
      dummy.push_back( CscClusterPassSel_FailCS (doesPassHLT()) );

      CscClusterPassSel_all = dummy;
      dummy.clear();
      dummy.push_back( DtClusterPassSel_Fail   (doesPassHLT()) );
      dummy.push_back( DtClusterPassSel_FailOOT(doesPassHLT()) );
      dummy.push_back( DtClusterPassSel_Pass   (doesPassHLT()) );
      dummy.push_back( DtClusterPassSel_PassOOT(doesPassHLT()) );
      dummy.push_back( DtClusterPassSel_nominal(doesPassHLT()) );
      dummy.push_back( DtClusterPassSel_nominalPlusTime(doesPassHLT()) );
      dummy.push_back( DtClusterPassSel_PassCS(doesPassHLT()) );
      dummy.push_back( DtClusterPassSel_FailCS(doesPassHLT()) );
      DtClusterPassSel_all = dummy;
      //Make JetList
      jet_list       =  jetPassSel(jetPtMin, jetCISV_Cut);

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
              for (int k = 0; k < CscClusterPassSel_all[4].size(); k++) {
                if (pass) break;
                int csc = CscClusterPassSel_all[4][k];
                float dphi = DeltaPhi(cscRechitClusterPhi[csc], lepPhi[muon_list[0]]);
                if      (cscRechitClusterSize[csc] >= cls_cut && dphi >= dphi_cut) { // Region A
                    n_events_CSC_A->SetBinContent(i+1, j+1, n_events_CSC_A->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
                else if (cscRechitClusterSize[csc] >= cls_cut && dphi < dphi_cut ) { // Region B
                    n_events_CSC_B->SetBinContent(i+1, j+1, n_events_CSC_B->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
                else if (cscRechitClusterSize[csc] < cls_cut  && dphi >= dphi_cut) { // Region C
                    n_events_CSC_C->SetBinContent(i+1, j+1, n_events_CSC_C->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
                else if (cscRechitClusterSize[csc] < cls_cut  && dphi < dphi_cut ) { // Region D
                    n_events_CSC_D->SetBinContent(i+1, j+1, n_events_CSC_D->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
              }
              pass = false;
              for (int k = 0; k < DtClusterPassSel_all[4].size(); k++) {
                int dt = DtClusterPassSel_all[4][k];
                if (pass) break;
                float dphi = DeltaPhi(dtRechitClusterPhi[dt], lepPhi[muon_list[0]]);
                if      (dtRechitClusterSize[dt] >= cls_cut && dphi >= dphi_cut) { // Region A
                    n_events_DT_A->SetBinContent(i+1, j+1, n_events_DT_A->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
                else if (dtRechitClusterSize[dt] >= cls_cut && dphi < dphi_cut ) { // Region B
                    n_events_DT_B->SetBinContent(i+1, j+1, n_events_DT_B->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
                else if (dtRechitClusterSize[dt] < cls_cut  && dphi >= dphi_cut) { // Region C
                    n_events_DT_C->SetBinContent(i+1, j+1, n_events_DT_C->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
                else if (dtRechitClusterSize[dt] < cls_cut  && dphi < dphi_cut ) { // Region D
                    n_events_DT_D->SetBinContent(i+1, j+1, n_events_DT_D->GetBinContent(i+1, j+1) + eventW);
                    pass = true;
                }
              }
            }
          }
        }//if (muon_list.size() != 0)
      }//if(doScan)

      if(CscClusterPassSel_all[3].size()>0){
      bool passCheck=false;
      for(int i=0; i<CscClusterPassSel_all[3].size(); i++){
        if (cscRechitClusterSize[CscClusterPassSel_all[3][i]] >= CscSize) passCheck = true;
      }
      if (passCheck) std::cout<<"**********************"<<
                           "  THERUN:"<< runNum<<"   Lumi:"<<lumiSec<<"  Event:"<<evtNum<<std::endl;
      }
      tup_DtCluster_list.clear();
      tup_DtCluster_list = DtClusterPassSel_all[4];
      tup_CscCluster_list.clear();
      tup_CscCluster_list = CscClusterPassSel_all[4];

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
      FillHistos(5, event_weight);
      FillHistos(6, event_weight);
      FillHistos(7, event_weight);


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
   WriteHistos(5);
   WriteHistos(6);
   WriteHistos(7);

}

