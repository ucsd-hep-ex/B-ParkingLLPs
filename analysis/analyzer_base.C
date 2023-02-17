#include "analyzer_base.h"
#include "TMath.h"
#include <iostream>

//----------------------------analyzer_base
analyzer_base::analyzer_base() 
{
}

//----------------------------~analyzer_base
analyzer_base::~analyzer_base()
{
}


Long64_t analyzer_base::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      //Notify();
   }
   return centry;
}


void analyzer_base::Init(TChain *tree)
{
   std::cout<<"in the INITT "<<std::endl;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runNum", &runNum, &b_runNum);
   fChain->SetBranchAddress("MC_condition", &MC_condition, &b_MC_condition);
   fChain->SetBranchAddress("lumiSec", &lumiSec, &b_lumiSec);
   fChain->SetBranchAddress("evtNum", &evtNum, &b_evtNum);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("npv", &npv, &b_npv);
   fChain->SetBranchAddress("Flag2_all", &Flag2_all, &b_Flag2_all);
   fChain->SetBranchAddress("metEENoise", &metEENoise, &b_metEENoise);
   fChain->SetBranchAddress("metPhiEENoise", &metPhiEENoise, &b_metPhiEENoise);
   fChain->SetBranchAddress("gLLP_eta", &gLLP_eta, &b_gLLP_eta);
   fChain->SetBranchAddress("gLLP_phi", &gLLP_phi, &b_gLLP_phi);
   fChain->SetBranchAddress("gLLP_csc", &gLLP_csc, &b_gLLP_csc);
   fChain->SetBranchAddress("gLLP_dt", &gLLP_dt, &b_gLLP_dt);
   fChain->SetBranchAddress("gLLP_beta", &gLLP_beta, &b_gLLP_beta);
   fChain->SetBranchAddress("gLLP_e", &gLLP_e, &b_gLLP_e);
   fChain->SetBranchAddress("gLLP_pt", &gLLP_pt, &b_gLLP_pt);
   fChain->SetBranchAddress("gLLP_ctau", &gLLP_ctau, &b_gLLP_ctau);
   fChain->SetBranchAddress("gLLP_decay_vertex_r", &gLLP_decay_vertex_r, &b_gLLP_decay_vertex_r);
   fChain->SetBranchAddress("gLLP_decay_vertex_x", &gLLP_decay_vertex_x, &b_gLLP_decay_vertex_x);
   fChain->SetBranchAddress("gLLP_decay_vertex_y", &gLLP_decay_vertex_y, &b_gLLP_decay_vertex_y);
   fChain->SetBranchAddress("gLLP_decay_vertex_z", &gLLP_decay_vertex_z, &b_gLLP_decay_vertex_z);
   fChain->SetBranchAddress("nGenParticles", &nGenParticles, &b_nGenParticles);
   fChain->SetBranchAddress("gParticleE",   &gParticleE , &b_gParticleE);
   fChain->SetBranchAddress("gParticlePt",  &gParticlePt , &b_gParticlePt);
   fChain->SetBranchAddress("gParticleEta", &gParticleEta , &b_gParticleEta);
   fChain->SetBranchAddress("gParticlePhi", &gParticlePhi , &b_gParticlePhi);
   fChain->SetBranchAddress("gParticleId",  &gParticleId , &b_gParticleId);
   fChain->SetBranchAddress("gParticleMotherId", &gParticleMotherId, &b_gParticleMotherId);
   fChain->SetBranchAddress("gParticleMotherIndex", &gParticleMotherIndex, &b_gParticleMotherIndex);
   fChain->SetBranchAddress("nLeptons", &nLeptons, &b_nLeptons);
   fChain->SetBranchAddress("lepE", lepE, &b_lepE);
   fChain->SetBranchAddress("lepPt", lepPt, &b_lepPt);
   fChain->SetBranchAddress("lepMuonType", lepMuonType, &b_lepMuonType);
   fChain->SetBranchAddress("lepMuonQuality", lepMuonQuality, &b_lepMuonQuality);
   fChain->SetBranchAddress("lepMuon_passHLTFilter", lepMuon_passHLTFilter, &b_lepMuon_passHLTFilter);
   fChain->SetBranchAddress("lepEta", lepEta, &b_lepEta);
   fChain->SetBranchAddress("lepPhi", lepPhi, &b_lepPhi);
   fChain->SetBranchAddress("lepPdgId", lepPdgId, &b_lepPdgId);
   fChain->SetBranchAddress("lepDZ", lepDZ, &b_lepDZ);
   fChain->SetBranchAddress("lepDXY", lepDXY, &b_lepDXY);
   fChain->SetBranchAddress("lepDXYErr", lepDXYErr, &b_lepDXYErr);
   fChain->SetBranchAddress("lepSF", lepSF, &b_lepSF);
   fChain->SetBranchAddress("lepLooseId", lepLooseId, &b_lepLooseId);
   fChain->SetBranchAddress("lepTightId", lepTightId, &b_lepTightId);
   fChain->SetBranchAddress("nJets", &nJets, &b_nJets);
   fChain->SetBranchAddress("jetE", jetE, &b_jetE);
   fChain->SetBranchAddress("jetPt", jetPt, &b_jetPt);
   fChain->SetBranchAddress("jetEta", jetEta, &b_jetEta);
   fChain->SetBranchAddress("jetPhi", jetPhi, &b_jetPhi);
   fChain->SetBranchAddress("jetTightPassId", jetTightPassId, &b_jetTightPassId);
   fChain->SetBranchAddress("HLTDecision", HLTDecision, &b_HLTDecision);
   fChain->SetBranchAddress("nCscRechits", &nCscRechits, &b_nCscRechits);
   fChain->SetBranchAddress("nCscRings", &nCscRings, &b_nCscRings);
   fChain->SetBranchAddress("nDTRechits", &nDTRechits, &b_nDTRechits);
   fChain->SetBranchAddress("nDtRings", &nDtRings, &b_nDtRings);
   fChain->SetBranchAddress("nCscRechitClusters", &nCscRechitClusters, &b_nCscRechitClusters);
   fChain->SetBranchAddress("cscRechitClusterX", cscRechitClusterX, &b_cscRechitClusterX);
   fChain->SetBranchAddress("cscRechitClusterY", cscRechitClusterY, &b_cscRechitClusterY);
   fChain->SetBranchAddress("cscRechitClusterZ", cscRechitClusterZ, &b_cscRechitClusterZ);
   fChain->SetBranchAddress("cscRechitClusterTimeWeighted", cscRechitClusterTimeWeighted, &b_cscRechitClusterTimeWeighted);
   fChain->SetBranchAddress("cscRechitClusterTimeSpreadWeightedAll", cscRechitClusterTimeSpreadWeightedAll, &b_cscRechitClusterTimeSpreadWeightedAll);
   fChain->SetBranchAddress("cscRechitClusterGenMuonDeltaR", cscRechitClusterGenMuonDeltaR, &b_cscRechitClusterGenMuonDeltaR);
   fChain->SetBranchAddress("cscRechitClusterPhi", cscRechitClusterPhi, &b_cscRechitClusterPhi);
   fChain->SetBranchAddress("cscRechitClusterEta", cscRechitClusterEta, &b_cscRechitClusterEta);
   fChain->SetBranchAddress("cscRechitClusterSize", cscRechitClusterSize, &b_cscRechitClusterSize);
   fChain->SetBranchAddress("cscRechitClusterMe11Ratio", cscRechitClusterMe11Ratio, &b_cscRechitClusterMe11Ratio);
   fChain->SetBranchAddress("cscRechitClusterMe12Ratio", cscRechitClusterMe12Ratio, &b_cscRechitClusterMe12Ratio);
   fChain->SetBranchAddress("cscRechitClusterNStation", cscRechitClusterNStation, &b_cscRechitClusterNStation);
   fChain->SetBranchAddress("cscRechitClusterNStation5", cscRechitClusterNStation5, &b_cscRechitClusterNStation5);
   fChain->SetBranchAddress("cscRechitClusterNStation10", cscRechitClusterNStation10, &b_cscRechitClusterNStation10);
   fChain->SetBranchAddress("cscRechitClusterNStation10perc", cscRechitClusterNStation10perc, &b_cscRechitClusterNStation10perc);
   fChain->SetBranchAddress("cscRechitClusterAvgStation", cscRechitClusterAvgStation, &b_cscRechitClusterAvgStation);
   fChain->SetBranchAddress("cscRechitClusterAvgStation5", cscRechitClusterAvgStation5, &b_cscRechitClusterAvgStation5);
   fChain->SetBranchAddress("cscRechitClusterAvgStation10", cscRechitClusterAvgStation10, &b_cscRechitClusterAvgStation10);
   fChain->SetBranchAddress("cscRechitClusterAvgStation10perc", cscRechitClusterAvgStation10perc, &b_cscRechitClusterAvgStation10perc);
   fChain->SetBranchAddress("cscRechitClusterMaxStation", cscRechitClusterMaxStation, &b_cscRechitClusterMaxStation);
   fChain->SetBranchAddress("cscRechitClusterMaxStationRatio", cscRechitClusterMaxStationRatio, &b_cscRechitClusterMaxStationRatio);
   fChain->SetBranchAddress("cscRechitClusterNChamber", cscRechitClusterNChamber, &b_cscRechitClusterNChamber);
   fChain->SetBranchAddress("cscRechitClusterMaxChamber", cscRechitClusterMaxChamber, &b_cscRechitClusterMaxChamber);
   fChain->SetBranchAddress("cscRechitClusterMaxChamberRatio", cscRechitClusterMaxChamberRatio, &b_cscRechitClusterMaxChamberRatio);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus11", cscRechitClusterNRechitChamberPlus11, &b_cscRechitClusterNRechitChamberPlus11);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus12", cscRechitClusterNRechitChamberPlus12, &b_cscRechitClusterNRechitChamberPlus12);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus13", cscRechitClusterNRechitChamberPlus13, &b_cscRechitClusterNRechitChamberPlus13);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus21", cscRechitClusterNRechitChamberPlus21, &b_cscRechitClusterNRechitChamberPlus21);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus22", cscRechitClusterNRechitChamberPlus22, &b_cscRechitClusterNRechitChamberPlus22);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus31", cscRechitClusterNRechitChamberPlus31, &b_cscRechitClusterNRechitChamberPlus31);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus32", cscRechitClusterNRechitChamberPlus32, &b_cscRechitClusterNRechitChamberPlus32);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus41", cscRechitClusterNRechitChamberPlus41, &b_cscRechitClusterNRechitChamberPlus41);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberPlus42", cscRechitClusterNRechitChamberPlus42, &b_cscRechitClusterNRechitChamberPlus42);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus11", cscRechitClusterNRechitChamberMinus11, &b_cscRechitClusterNRechitChamberMinus11);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus12", cscRechitClusterNRechitChamberMinus12, &b_cscRechitClusterNRechitChamberMinus12);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus13", cscRechitClusterNRechitChamberMinus13, &b_cscRechitClusterNRechitChamberMinus13);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus21", cscRechitClusterNRechitChamberMinus21, &b_cscRechitClusterNRechitChamberMinus21);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus22", cscRechitClusterNRechitChamberMinus22, &b_cscRechitClusterNRechitChamberMinus22);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus31", cscRechitClusterNRechitChamberMinus31, &b_cscRechitClusterNRechitChamberMinus31);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus32", cscRechitClusterNRechitChamberMinus32, &b_cscRechitClusterNRechitChamberMinus32);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus41", cscRechitClusterNRechitChamberMinus41, &b_cscRechitClusterNRechitChamberMinus41);
   fChain->SetBranchAddress("cscRechitClusterNRechitChamberMinus42", cscRechitClusterNRechitChamberMinus42, &b_cscRechitClusterNRechitChamberMinus42);
   fChain->SetBranchAddress("cscRechitCluster_match_cscRechits_0p4", cscRechitCluster_match_cscRechits_0p4, &b_cscRechitCluster_match_cscRechits_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_dtRechits_phi0p2", cscRechitCluster_match_dtRechits_phi0p2, &b_cscRechitCluster_match_dtRechits_phi0p2);
   fChain->SetBranchAddress("cscRechitCluster_match_dtRechits_0p4", cscRechitCluster_match_dtRechits_0p4, &b_cscRechitCluster_match_dtRechits_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_MB1_0p4", cscRechitCluster_match_MB1_0p4, &b_cscRechitCluster_match_MB1_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_dtSeg_0p4", cscRechitCluster_match_dtSeg_0p4, &b_cscRechitCluster_match_dtSeg_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_MB1Seg_0p4", cscRechitCluster_match_MB1Seg_0p4, &b_cscRechitCluster_match_MB1Seg_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_RB1_0p4", cscRechitCluster_match_RB1_0p4, &b_cscRechitCluster_match_RB1_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_RE12_0p4", cscRechitCluster_match_RE12_0p4, &b_cscRechitCluster_match_RE12_0p4);
   fChain->SetBranchAddress("cscRechitCluster_match_gLLP_deltaR", cscRechitCluster_match_gLLP_deltaR, &b_cscRechitCluster_match_gLLP_deltaR);
   fChain->SetBranchAddress("cscRechitClusterJetVetoPt", cscRechitClusterJetVetoPt, &b_cscRechitClusterJetVetoPt);
   fChain->SetBranchAddress("cscRechitClusterMuonVetoPt", cscRechitClusterMuonVetoPt, &b_cscRechitClusterMuonVetoPt);
   fChain->SetBranchAddress("cscRechitClusterGenMuonVetoPt_dR0p8", cscRechitClusterGenMuonVetoPt_dR0p8, &b_cscRechitClusterGenMuonVetoPt_dR0p8);
   fChain->SetBranchAddress("cscRechitClusterMuonVetoPt", cscRechitClusterGenMuonVetoPt, &b_cscRechitClusterGenMuonVetoPt);
   fChain->SetBranchAddress("cscRechitClusterMetEENoise_dPhi", cscRechitClusterMetEENoise_dPhi, &b_cscRechitClusterMetEENoise_dPhi);
   fChain->SetBranchAddress("nDtRechitClusters", &nDtRechitClusters, &b_nDtRechitClusters);
   fChain->SetBranchAddress("dtRechitClusterMaxDPhi", dtRechitClusterMaxDPhi, &b_dtRechitClusterMaxDPhi);
   fChain->SetBranchAddress("dtRechitClusterMaxDPhi_index", dtRechitClusterMaxDPhi_index, &b_dtRechitClusterMaxDPhi_index);
   fChain->SetBranchAddress("dtRechitClusterNSegStation1", dtRechitClusterNSegStation1, &b_dtRechitClusterNSegStation1);
   fChain->SetBranchAddress("dtRechitClusterNSegStation2", dtRechitClusterNSegStation2, &b_dtRechitClusterNSegStation2);
   fChain->SetBranchAddress("dtRechitClusterNSegStation3", dtRechitClusterNSegStation3, &b_dtRechitClusterNSegStation3);
   fChain->SetBranchAddress("dtRechitClusterNSegStation4", dtRechitClusterNSegStation4, &b_dtRechitClusterNSegStation4);
   fChain->SetBranchAddress("dtRechitClusterNOppositeSegStation1", dtRechitClusterNOppositeSegStation1, &b_dtRechitClusterNOppositeSegStation1);
   fChain->SetBranchAddress("dtRechitClusterNOppositeSegStation2", dtRechitClusterNOppositeSegStation2, &b_dtRechitClusterNOppositeSegStation2);
   fChain->SetBranchAddress("dtRechitClusterNOppositeSegStation3", dtRechitClusterNOppositeSegStation3, &b_dtRechitClusterNOppositeSegStation3);
   fChain->SetBranchAddress("dtRechitClusterNOppositeSegStation4", dtRechitClusterNOppositeSegStation4, &b_dtRechitClusterNOppositeSegStation4);
   fChain->SetBranchAddress("dtRechitClusterX", dtRechitClusterX, &b_dtRechitClusterX);
   fChain->SetBranchAddress("dtRechitClusterY", dtRechitClusterY, &b_dtRechitClusterY);
   fChain->SetBranchAddress("dtRechitClusterZ", dtRechitClusterZ, &b_dtRechitClusterZ);
   fChain->SetBranchAddress("dtRechitClusterWheel", dtRechitClusterWheel, &b_dtRechitClusterWheel);
   fChain->SetBranchAddress("dtRechitClusterGenMuonDeltaR", dtRechitClusterGenMuonDeltaR, &b_dtRechitClusterGenMuonDeltaR);
   fChain->SetBranchAddress("dtRechitClusterPhi", dtRechitClusterPhi, &b_dtRechitClusterPhi);
   fChain->SetBranchAddress("dtRechitClusterEta", dtRechitClusterEta, &b_dtRechitClusterEta);
   fChain->SetBranchAddress("dtRechitClusterOverlap", dtRechitClusterOverlap, &b_dtRechitClusterOverlap);
   fChain->SetBranchAddress("dtRechitClusterSize", dtRechitClusterSize, &b_dtRechitClusterSize);
   fChain->SetBranchAddress("dtRechitClusterNoiseHit", dtRechitClusterNoiseHit, &b_dtRechitClusterNoiseHit);
   fChain->SetBranchAddress("dtRechitClusterNoiseHitStation1", dtRechitClusterNoiseHitStation1, &b_dtRechitClusterNoiseHitStation1);
   fChain->SetBranchAddress("dtRechitClusterNoiseHitStation2", dtRechitClusterNoiseHitStation2, &b_dtRechitClusterNoiseHitStation2);
   fChain->SetBranchAddress("dtRechitClusterNoiseHitStation3", dtRechitClusterNoiseHitStation3, &b_dtRechitClusterNoiseHitStation3);
   fChain->SetBranchAddress("dtRechitClusterNoiseHitStation4", dtRechitClusterNoiseHitStation4, &b_dtRechitClusterNoiseHitStation4);
   fChain->SetBranchAddress("dtRechitClusterMe11Ratio", dtRechitClusterMe11Ratio, &b_dtRechitClusterMe11Ratio);
   fChain->SetBranchAddress("dtRechitClusterMe12Ratio", dtRechitClusterMe12Ratio, &b_dtRechitClusterMe12Ratio);
   fChain->SetBranchAddress("dtRechitClusterNStation", dtRechitClusterNStation, &b_dtRechitClusterNStation);
   fChain->SetBranchAddress("dtRechitClusterNStation5", dtRechitClusterNStation5, &b_dtRechitClusterNStation5);
   fChain->SetBranchAddress("dtRechitClusterNStation10", dtRechitClusterNStation10, &b_dtRechitClusterNStation10);
   fChain->SetBranchAddress("dtRechitClusterNStation10perc", dtRechitClusterNStation10perc, &b_dtRechitClusterNStation10perc);
   fChain->SetBranchAddress("dtRechitClusterAvgStation", dtRechitClusterAvgStation, &b_dtRechitClusterAvgStation);
   fChain->SetBranchAddress("dtRechitClusterAvgStation5", dtRechitClusterAvgStation5, &b_dtRechitClusterAvgStation5);
   fChain->SetBranchAddress("dtRechitClusterAvgStation10", dtRechitClusterAvgStation10, &b_dtRechitClusterAvgStation10);
   fChain->SetBranchAddress("dtRechitClusterAvgStation10perc", dtRechitClusterAvgStation10perc, &b_dtRechitClusterAvgStation10perc);
   fChain->SetBranchAddress("dtRechitClusterMaxStation", dtRechitClusterMaxStation, &b_dtRechitClusterMaxStation);
   fChain->SetBranchAddress("dtRechitClusterMaxStationRatio", dtRechitClusterMaxStationRatio, &b_dtRechitClusterMaxStationRatio);
   fChain->SetBranchAddress("dtRechitClusterNChamber", dtRechitClusterNChamber, &b_dtRechitClusterNChamber);
   fChain->SetBranchAddress("dtRechitClusterMaxChamber", dtRechitClusterMaxChamber, &b_dtRechitClusterMaxChamber);
   fChain->SetBranchAddress("dtRechitClusterMaxChamberRatio", dtRechitClusterMaxChamberRatio, &b_dtRechitClusterMaxChamberRatio);
   fChain->SetBranchAddress("dtRechitClusterNSegmentStation1", dtRechitClusterNSegmentStation1, &b_dtRechitClusterNSegmentStation1);
   fChain->SetBranchAddress("dtRechitClusterNSegmentStation2", dtRechitClusterNSegmentStation2, &b_dtRechitClusterNSegmentStation2);
   fChain->SetBranchAddress("dtRechitClusterNSegmentStation3", dtRechitClusterNSegmentStation3, &b_dtRechitClusterNSegmentStation3);
   fChain->SetBranchAddress("dtRechitClusterNSegmentStation4", dtRechitClusterNSegmentStation4, &b_dtRechitClusterNSegmentStation4);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus11", dtRechitClusterNRechitChamberPlus11, &b_dtRechitClusterNRechitChamberPlus11);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus12", dtRechitClusterNRechitChamberPlus12, &b_dtRechitClusterNRechitChamberPlus12);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus13", dtRechitClusterNRechitChamberPlus13, &b_dtRechitClusterNRechitChamberPlus13);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus21", dtRechitClusterNRechitChamberPlus21, &b_dtRechitClusterNRechitChamberPlus21);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus22", dtRechitClusterNRechitChamberPlus22, &b_dtRechitClusterNRechitChamberPlus22);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus31", dtRechitClusterNRechitChamberPlus31, &b_dtRechitClusterNRechitChamberPlus31);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus32", dtRechitClusterNRechitChamberPlus32, &b_dtRechitClusterNRechitChamberPlus32);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus41", dtRechitClusterNRechitChamberPlus41, &b_dtRechitClusterNRechitChamberPlus41);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberPlus42", dtRechitClusterNRechitChamberPlus42, &b_dtRechitClusterNRechitChamberPlus42);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus11", dtRechitClusterNRechitChamberMinus11, &b_dtRechitClusterNRechitChamberMinus11);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus12", dtRechitClusterNRechitChamberMinus12, &b_dtRechitClusterNRechitChamberMinus12);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus13", dtRechitClusterNRechitChamberMinus13, &b_dtRechitClusterNRechitChamberMinus13);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus21", dtRechitClusterNRechitChamberMinus21, &b_dtRechitClusterNRechitChamberMinus21);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus22", dtRechitClusterNRechitChamberMinus22, &b_dtRechitClusterNRechitChamberMinus22);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus31", dtRechitClusterNRechitChamberMinus31, &b_dtRechitClusterNRechitChamberMinus31);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus32", dtRechitClusterNRechitChamberMinus32, &b_dtRechitClusterNRechitChamberMinus32);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus41", dtRechitClusterNRechitChamberMinus41, &b_dtRechitClusterNRechitChamberMinus41);
   fChain->SetBranchAddress("dtRechitClusterNRechitChamberMinus42", dtRechitClusterNRechitChamberMinus42, &b_dtRechitClusterNRechitChamberMinus42);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus11", dtRechitClusterNLayersChamberPlus11, &b_dtRechitClusterNLayersChamberPlus11);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus12", dtRechitClusterNLayersChamberPlus12, &b_dtRechitClusterNLayersChamberPlus12);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus13", dtRechitClusterNLayersChamberPlus13, &b_dtRechitClusterNLayersChamberPlus13);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus21", dtRechitClusterNLayersChamberPlus21, &b_dtRechitClusterNLayersChamberPlus21);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus22", dtRechitClusterNLayersChamberPlus22, &b_dtRechitClusterNLayersChamberPlus22);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus31", dtRechitClusterNLayersChamberPlus31, &b_dtRechitClusterNLayersChamberPlus31);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus32", dtRechitClusterNLayersChamberPlus32, &b_dtRechitClusterNLayersChamberPlus32);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus41", dtRechitClusterNLayersChamberPlus41, &b_dtRechitClusterNLayersChamberPlus41);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberPlus42", dtRechitClusterNLayersChamberPlus42, &b_dtRechitClusterNLayersChamberPlus42);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus11", dtRechitClusterNLayersChamberMinus11, &b_dtRechitClusterNLayersChamberMinus11);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus12", dtRechitClusterNLayersChamberMinus12, &b_dtRechitClusterNLayersChamberMinus12);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus13", dtRechitClusterNLayersChamberMinus13, &b_dtRechitClusterNLayersChamberMinus13);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus21", dtRechitClusterNLayersChamberMinus21, &b_dtRechitClusterNLayersChamberMinus21);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus22", dtRechitClusterNLayersChamberMinus22, &b_dtRechitClusterNLayersChamberMinus22);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus31", dtRechitClusterNLayersChamberMinus31, &b_dtRechitClusterNLayersChamberMinus31);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus32", dtRechitClusterNLayersChamberMinus32, &b_dtRechitClusterNLayersChamberMinus32);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus41", dtRechitClusterNLayersChamberMinus41, &b_dtRechitClusterNLayersChamberMinus41);
   fChain->SetBranchAddress("dtRechitClusterNLayersChamberMinus42", dtRechitClusterNLayersChamberMinus42, &b_dtRechitClusterNLayersChamberMinus42);
   fChain->SetBranchAddress("dtRechitCluster_match_RPCTime_dR0p4", dtRechitCluster_match_RPCTime_dR0p4, &b_dtRechitCluster_match_RPCTime_dR0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_RPCTimeSpread_dR0p4", dtRechitCluster_match_RPCTimeSpread_dR0p4, &b_dtRechitCluster_match_RPCTimeSpread_dR0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_RPChits_dR0p4", dtRechitCluster_match_RPChits_dR0p4, &b_dtRechitCluster_match_RPChits_dR0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_RPCTime_sameStation_dR0p4", dtRechitCluster_match_RPCTime_sameStation_dR0p4, &b_dtRechitCluster_match_RPCTime_sameStation_dR0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4", dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4, &b_dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_RPChits_sameStation_dR0p4", dtRechitCluster_match_RPChits_sameStation_dR0p4, &b_dtRechitCluster_match_RPChits_sameStation_dR0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_gLLP_deltaR", dtRechitCluster_match_gLLP_deltaR, &b_dtRechitCluster_match_gLLP_deltaR);
   fChain->SetBranchAddress("dtRechitCluster_match_RB1_0p4", dtRechitCluster_match_RB1_0p4, &b_dtRechitCluster_match_RB1_0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_RB1_dPhi0p5", dtRechitCluster_match_RB1_dPhi0p5, &b_dtRechitCluster_match_RB1_dPhi0p5);
   fChain->SetBranchAddress("dtRechitCluster_match_MB1Seg_0p4", dtRechitCluster_match_MB1Seg_0p4, &b_dtRechitCluster_match_MB1Seg_0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_MB1Seg_0p5", dtRechitCluster_match_MB1Seg_0p5, &b_dtRechitCluster_match_MB1Seg_0p5);
   fChain->SetBranchAddress("dtRechitCluster_match_MB1hits_0p4", dtRechitCluster_match_MB1hits_0p4, &b_dtRechitCluster_match_MB1hits_0p4);
   fChain->SetBranchAddress("dtRechitCluster_match_MB1hits_0p5", dtRechitCluster_match_MB1hits_0p5, &b_dtRechitCluster_match_MB1hits_0p5);
   fChain->SetBranchAddress("dtRechitCluster_match_MB1hits_cosmics_plus", dtRechitCluster_match_MB1hits_cosmics_plus, &b_dtRechitCluster_match_MB1hits_cosmics_plus);
   fChain->SetBranchAddress("dtRechitCluster_match_MB1hits_cosmics_minus", dtRechitCluster_match_MB1hits_cosmics_minus, &b_dtRechitCluster_match_MB1hits_cosmics_minus);
   fChain->SetBranchAddress("dtRechitClusterJetVetoPt", dtRechitClusterJetVetoPt, &b_dtRechitClusterJetVetoPt);
   fChain->SetBranchAddress("dtRechitClusterJetVetoE", dtRechitClusterJetVetoE, &b_dtRechitClusterJetVetoE);
   fChain->SetBranchAddress("dtRechitClusterGenMuonVetoPt", dtRechitClusterGenMuonVetoPt, &b_dtRechitClusterGenMuonVetoPt);
   fChain->SetBranchAddress("dtRechitClusterGenMuonVetoPt_dR0p8", dtRechitClusterGenMuonVetoPt_dR0p8, &b_dtRechitClusterGenMuonVetoPt_dR0p8);
   fChain->SetBranchAddress("dtRechitClusterMuonVetoPt", dtRechitClusterMuonVetoPt, &b_dtRechitClusterMuonVetoPt);
   fChain->SetBranchAddress("dtRechitClusterMetEENoise_dPhi", dtRechitClusterMetEENoise_dPhi, &b_dtRechitClusterMetEENoise_dPhi);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
}


//-------------------------dR
double analyzer_base::dR(double eta1, double phi1, double eta2, double phi2)
{
  double deltaeta = abs(eta1 - eta2);
  double deltaphi = DeltaPhi(phi1, phi2);
  double deltar = sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
  return deltar;
}

//-------------------------DeltaPhi
double analyzer_base::DeltaPhi(double phi1, double phi2)
//Gives the (minimum) separation in phi between the specified phi values
//Must return a positive value
{
  double pi = TMath::Pi();
  double dphi = fabs(phi1-phi2);
  if(dphi>pi)
    dphi = 2.0*pi - dphi;
  return dphi;
}
