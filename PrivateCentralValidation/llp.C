#define llp_cxx
#include "llp.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

double delta_phi(double phi1, double phi2) {
  double dphi = phi1-phi2;
  while (dphi > TMath::Pi())
    dphi -= TMath::TwoPi();
  while (dphi <= -TMath::Pi())
    dphi += TMath::TwoPi();
  return dphi;
}

void llp::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   // TFile * output = new TFile("output_private.root", "recreate");
   // TFile * output = new TFile("output_central.root", "recreate");
   TFile * output = new TFile("output.root", "recreate");
   TH1D * LLP_E = new TH1D("LLP_E", "LLP_E", 100, 0, 50);
   TH1D * LLP_PT = new TH1D("LLP_PT", "LLP_PT", 100, 0, 50);
   TH1D * LLP_ETA = new TH1D("LLP_ETA", "LLP_ETA", 100, -5, 5);
   TH1D * LLP_PHI = new TH1D("LLP_PHI", "LLP_PHI", 100, -5, 5);
   TH1D * LLP_CTAU = new TH1D("LLP_CTAU", "LLP_CTAU", 300, 0, 500);
   
   TH1D * LLP_DECAY_R = new TH1D("LLP_DECAY_R", "LLP_DECAY_R", 150, 0, 1500);
   TH1D * LLP_DECAY_Z = new TH1D("LLP_DECAY_Z", "LLP_DECAY_Z", 150, 0, 1500);
   TH1D * LLP_DECAY_DAUGHTER = new TH1D("LLP_DECAY_DAUGHTER", "LLP_DECAY_DAUGHTER", 1000, 0, 1000);
   TH2D * LLP_DECAY = new TH2D("LLP_DECAY", "LLP_DECAY", 150, 0, 1500, 150, 0, 1000);
   TH1D * LLP_MATCHED_E = new TH1D("LLP_MATCHED_E", "LLP_MATCHED_E", 100, 0, 50);
   TH1D * LLP_MATCHED_PT = new TH1D("LLP_MATCHED_PT", "LLP_MATCHED_PT", 100, 0, 50);
   TH1D * LLP_MATCHED_ETA = new TH1D("LLP_MATCHED_ETA", "LLP_MATCHED_ETA", 100, -5, 5);
   TH1D * LLP_MATCHED_PHI = new TH1D("LLP_MATCHED_PHI", "LLP_MATCHED_PHI", 100, -5, 5);
   TH2D * LLP_MATCHED_DECAY_VERTEX = new TH2D("LLP_CSC_CLUSTER_DECAY_VERTEX", "LLP_CSC_CLUSTER_DECAY_VERTEX", 150, 0, 1500, 150, 0, 1000);
   TH1D * LLP_MATCHED_DECAY_VERTEX_R = new TH1D("LLP_CSC_CLUSTER_DECAY_VERTEX_R", "LLP_CSC_CLUSTER_DECAY_VERTEX_R", 150, 0, 1000);
   TH1D * LLP_MATCHED_DECAY_VERTEX_Z = new TH1D("LLP_CSC_CLUSTER_DECAY_VERTEX_Z", "LLP_CSC_CLUSTER_DECAY_VERTEX_Z", 150, 0, 1500);

   TH1D * MUON_E = new TH1D("MUON_E", "MUON_E", 100, 0, 50);
   TH1D * MUON_PT = new TH1D("MUON_PT", "MUON_PT", 100, 0, 50);
   TH1D * MUON_ETA = new TH1D("MUON_ETA", "MUON_ETA", 100, -4, 4);
   TH1D * MUON_PHI = new TH1D("MUON_PHI", "MUON_PHI", 100, -4, 4);
   
   TH1D * RECO_MUON_E = new TH1D("RECO_MUON_E", "RECO_MUON_E", 100, 0, 50);
   TH1D * RECO_MUON_PT = new TH1D("RECO_MUON_PT", "RECO_MUON_PT", 100, 0, 50);
   TH1D * RECO_MUON_ETA = new TH1D("RECO_MUON_ETA", "RECO_MUON_ETA", 100, -4, 4);
   TH1D * RECO_MUON_PHI = new TH1D("RECO_MUON_PHI", "RECO_MUON_PHI", 100, -4, 4);

   TH1D * DT_CLUSTER_N = new TH1D("DT_N_CLUSTERS", "DT_N_CLUSTERS", 10, 0, 10);
   TH1D * DT_CLUSTER_SIZE = new TH1D("DT_CLUSTER_SIZE", "DT_CLUSTER_SIZE", 100, 0, 500);
   TH1D * DT_CLUSTER_ETA = new TH1D("DT_CLUSTER_ETA", "DT_CLUSTER_ETA", 100, -4, 4);
   TH1D * DT_CLUSTER_PHI = new TH1D("DT_CLUSTER_PHI", "DT_CLUSTER_PHI", 100, -4, 4);

   TH1D * CSC_CLUSTER_N = new TH1D("CSC_N_CLUSTERS", "CSC_N_CLUSTERS", 10, 0, 10);
   TH1D * CSC_CLUSTER_SIZE = new TH1D("CSC_CLUSTER_SIZE", "CSC_CLUSTER_SIZE", 100, 0, 500);
   TH1D * CSC_CLUSTER_ETA = new TH1D("CSC_CLUSTER_ETA", "CSC_CLUSTER_ETA", 100, -4, 4);
   TH1D * CSC_CLUSTER_PHI = new TH1D("CSC_CLUSTER_PHI", "CSC_CLUSTER_PHI", 100, -4, 4);
   TH1D * CSC_CLUSTER_DR = new TH1D("CSC_CLUSTER_DR", "CSC_CLUSTER_DR", 100, 0, 10);

   TH1D * LLP_CSC_CLUSTER_N = new TH1D("LLP_CSC_CLUSTER_N", "LLP_CSC_CLUSTER_N", 10, 0, 10);
   TH1D * LLP_CSC_CLUSTER_SIZE = new TH1D("LLP_CSC_CLUSTER_SIZE", "LLP_CSC_CLUSTER_SIZE", 100, 0, 500);
   TH1D * LLP_CSC_CLUSTER_ETA = new TH1D("LLP_CSC_CLUSTER_ETA", "LLP_CSC_CLUSTER_ETA", 100, -4, 4);
   TH1D * LLP_CSC_CLUSTER_PHI = new TH1D("LLP_CSC_CLUSTER_PHI", "LLP_CSC_CLUSTER_PHI", 100, -4, 4);

   TH1D * LLP_GRAND_DAUGHTER_ID  = new TH1D("LLP_GRAND_DAUGHTER_ID", "LLP_GRAND_DAUGHTER_ID", 1000, 0, 1000);
   TH1D * LLP_GRAND_DAUGHTER_E   = new TH1D("LLP_GRAND_DAUGHTER_E", "LLP_GRAND_DAUGHTER_E", 100, 0, 50);
   TH1D * LLP_GRAND_DAUGHTER_PT  = new TH1D("LLP_GRAND_DAUGHTER_PT", "LLP_GRAND_DAUGHTER_PT", 100, 0, 50);
   TH1D * LLP_GRAND_DAUGHTER_ETA = new TH1D("LLP_GRAND_DAUGHTER_ETA", "LLP_GRAND_DAUGHTER_ETA", 100, -4, 4);
   TH1D * LLP_GRAND_DAUGHTER_PHI = new TH1D("LLP_GRAND_DAUGHTER_PHI", "LLP_GRAND_DAUGHTER_PHI", 100, -4, 4);
   TH1D * LLP_GRAND_DAUGHTER_STATUS = new TH1D("LLP_GRAND_DAUGHTER_STATUS", "LLP_GRAND_DAUGHTER_STATUS", 100, -20, 20);

   TH1D * LLP_DAUGHTER_ID  = new TH1D("LLP_DAUGHTER_ID", "LLP_DAUGHTER_ID", 1000, 0, 1000);
   TH1D * LLP_DAUGHTER_E  = new TH1D("LLP_DAUGHTER_E", "LLP_DAUGHTER_E", 100, 0, 50);
   TH1D * LLP_DAUGHTER_PT  = new TH1D("LLP_DAUGHTER_PT", "LLP_DAUGHTER_PT", 100, 0, 50);
   TH1D * LLP_DAUGHTER_ETA = new TH1D("LLP_DAUGHTER_ETA", "LLP_DAUGHTER_ETA", 100, -4, 4);
   TH1D * LLP_DAUGHTER_PHI = new TH1D("LLP_DAUGHTER_PHI", "LLP_DAUGHTER_PHI", 100, -4, 4);
   TH1D * LLP_DAUGHTER_STATUS = new TH1D("LLP_DAUGHTER_STATUS", "LLP_DAUGHTER_STATUS", 100, -20, 20);

   TH1D * LLP_DAUGHTER_PI_ID  = new TH1D("LLP_DAUGHTER_PI_ID", "LLP_DAUGHTER_PI_ID", 1000, 0, 1000);
   TH1D * LLP_DAUGHTER_PI_E  = new TH1D("LLP_DAUGHTER_PI_E", "LLP_DAUGHTER_PI_E", 100, 0, 50);
   TH1D * LLP_DAUGHTER_PI_PT  = new TH1D("LLP_DAUGHTER_PI_PT", "LLP_DAUGHTER_PI_PT", 100, 0, 50);
   TH1D * LLP_DAUGHTER_PI_ETA = new TH1D("LLP_DAUGHTER_PI_ETA", "LLP_DAUGHTER_PI_ETA", 100, -4, 4);
   TH1D * LLP_DAUGHTER_PI_PHI = new TH1D("LLP_DAUGHTER_PI_PHI", "LLP_DAUGHTER_PI_PHI", 100, -4, 4);
   TH1D * LLP_DAUGHTER_PI_STATUS = new TH1D("LLP_DAUGHTER_PI_STATUS", "LLP_DAUGHTER_PI_STATUS", 100, -20, 20);

   TH1D * N_CSC_RECHITS = new TH1D("N_CSC_RECHITS", "N_CSC_RECHITS", 100, 0, 400);
   TH1D * CSC_RECHITS_ETA = new TH1D("CSC_RECHITS_ETA", "CSC_RECHITS_ETA", 100, -4, 4);
   TH1D * CSC_RECHITS_PHI = new TH1D("CSC_RECHITS_PHI", "CSC_RECHITS_PHI", 100, -4, 4);
   TH1D * CSC_RECHITS_E = new TH1D("CSC_RECHITS_E", "CSC_RECHITS_E", 100, 0, 300);
   TH1D * CSC_RECHITS_X = new TH1D("CSC_RECHITS_X", "CSC_RECHITS_X", 100, 0, 800);
   TH1D * CSC_RECHITS_Y = new TH1D("CSC_RECHITS_Y", "CSC_RECHITS_Y", 100, 0, 800);
   TH1D * CSC_RECHITS_Z = new TH1D("CSC_RECHITS_Z", "CSC_RECHITS_Z", 100, 0, 1200);
   TH1D * CSC_RECHITS_STATION = new TH1D("CSC_RECHITS_STATION", "CSC_RECHITS_STATION", 10, 0, 10);
   TH1D * CSC_RECHITS_CHAMBER = new TH1D("CSC_RECHITS_CHAMBER", "CSC_RECHITS_CHAMBER", 100, -50, 50);
   TH1D * CSC_RECHITS_TPEAK = new TH1D("CSC_RECHITS_TPEAK", "CSC_RECHITS_TPEAK", 80, -200, 200);
   TH1D * CSC_RECHITS_TWIRE = new TH1D("CSC_RECHITS_TWIRE", "CSC_RECHITS_TWIRE", 100, -300, 300);

   TH1D * MUON_CSC_CLUSTER_SIZE = new TH1D("MUON_CSC_CLUSTER_SIZE", "MUON_CSC_CLUSTER_SIZE", 100, 0, 500);
   TH1D * MUON_CSC_CLUSTER_ETA = new TH1D("MUON_CSC_CLUSTER_ETA", "MUON_CSC_CLUSTER_ETA", 100, -4, 4);
   TH1D * MUON_CSC_CLUSTER_PHI = new TH1D("MUON_CSC_CLUSTER_PHI", "MUON_CSC_CLUSTER_PHI", 100, -4, 4);

   float matched_llps = 0.0;
   float llps = 0.0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry > 100000) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if (ientry % 1000 == 0.0) {
          cout<<ientry<<"/"<<nentries<<endl;
      }
      bool found_llp = false;
      bool found_llp_daughter = false;
      double llp_eta = -1000;
      double llp_phi = -1000;
      double llp_pt = -1000;
      double llp_e = -1000;
      double llp_pos_x = -1000;
      double llp_pos_y = -1000;
      double llp_pos_z = -1000;
      double muon_eta = -1000;
      double muon_phi = -1000;
      double muon_pt = -1000;
      double muon_e = -1000;
      int n_cls_llp = 0;
      std::vector<int> daughter_index;
      
      for (int j = 0; j < nGenParticle; j++) {
          if (gParticleId[j] == 9900015) {
              found_llp = true;
              llps+=1;
              llp_e = gParticleE[j];
              llp_pt = gParticlePt[j];
              llp_eta = gParticleEta[j];
              llp_phi = gParticlePhi[j];
              LLP_E->Fill(gParticleE[j]);
              LLP_PT->Fill(gParticlePt[j]);
              LLP_ETA->Fill(gParticleEta[j]);
              LLP_PHI->Fill(gParticlePhi[j]);
          }
          if (gParticleMotherId[j] == 9900015) {
              found_llp_daughter = true;
              llp_pos_x = gParticleProdVertexX[j];
              llp_pos_y = gParticleProdVertexY[j];
              llp_pos_z = gParticleProdVertexZ[j];
              double r = sqrt(pow(llp_pos_x, 2) + pow(llp_pos_y, 2));
              LLP_DECAY->Fill(fabs(llp_pos_z), r);
              LLP_DECAY_R->Fill(r);
              LLP_DECAY_Z->Fill(fabs(llp_pos_z));
              LLP_DECAY_DAUGHTER->Fill(gParticleId[j]);
              LLP_DAUGHTER_ID->Fill(gParticleId[j]);
              LLP_DAUGHTER_E->Fill(gParticleE[j]);
              LLP_DAUGHTER_PT->Fill(gParticlePt[j]);
              LLP_DAUGHTER_ETA->Fill(gParticleEta[j]);
              LLP_DAUGHTER_PHI->Fill(gParticlePhi[j]);
              LLP_DAUGHTER_STATUS->Fill(gParticleStatus[j]);
              daughter_index.push_back(gParticleId[j]);
              if (abs(gParticleId[j]) == 211) {
                  LLP_DAUGHTER_PI_ID->Fill(gParticleId[j]);
                  LLP_DAUGHTER_PI_E->Fill(gParticleE[j]);
                  LLP_DAUGHTER_PI_PT->Fill(gParticlePt[j]);
                  LLP_DAUGHTER_PI_ETA->Fill(gParticleEta[j]);
                  LLP_DAUGHTER_PI_PHI->Fill(gParticlePhi[j]);
                  LLP_DAUGHTER_PI_STATUS->Fill(gParticleStatus[j]);
              }
              double llp_p_x = llp_pt*cos(llp_phi);
              double llp_p_y = llp_pt*sin(llp_phi);
              double llp_p_z = llp_pt*sinh(llp_eta);
              TLorentzVector * lorenz_vector = new TLorentzVector(llp_p_x, llp_p_y, llp_p_z, llp_e);
              double gamma = 1.0 / sqrt(1.0 - pow(lorenz_vector->Beta(), 2));
              double d = sqrt(pow(r, 2) + pow(llp_pos_z, 2));
              double ctau = d / (lorenz_vector->Beta() * gamma);
              LLP_CTAU->Fill(ctau);
          }
          /*
          find(daughter_id.begin(), daughter_id.end(), gParticleMotherId[j]);
          if (it!=daughter_id.end()) {
              std::cout<<gParticleId[j]<std::endl;
              LLP_GRAND_DAUGHTER_ID->Fill(gParticleId[j]);
              LLP_GRAND_DAUGHTER_PT->Fill(gParticlePt[j]);
              LLP_GRAND_DAUGHTER_ETA->Fill(gParticleEta[j]);
              LLP_GRAND_DAUGHTER_PHI->Fill(gParticlePhi[j]);
              LLP_GRAND_DAUGHTER_STATUS->Fill(gParticleStatus[j]);
          }*/
          if (fabs(gParticleId[j]) == 13 && gParticleStatus[j] == 1) {
              muon_e = gParticleE[j];
              muon_pt = gParticlePt[j];
              muon_eta = gParticleEta[j];
              muon_phi = gParticlePhi[j];
              MUON_E->Fill(gParticleE[j]);
              MUON_PT->Fill(gParticlePt[j]);
              MUON_ETA->Fill(gParticleEta[j]);
              MUON_PHI->Fill(gParticlePhi[j]);
          }
      }
      
      for (int j = 0; j < nGenParticle; j++) {
          auto it = find(daughter_index.begin(), daughter_index.end(), gParticleMotherIndex[j]);
          if (it!=daughter_index.end()) {
              LLP_GRAND_DAUGHTER_ID->Fill(gParticleId[j]);
              LLP_GRAND_DAUGHTER_E->Fill(gParticleE[j]);
              LLP_GRAND_DAUGHTER_PT->Fill(gParticlePt[j]);
              LLP_GRAND_DAUGHTER_ETA->Fill(gParticleEta[j]);
              LLP_GRAND_DAUGHTER_PHI->Fill(gParticlePhi[j]);
              LLP_GRAND_DAUGHTER_STATUS->Fill(gParticleStatus[j]);
          }
      }
      
      N_CSC_RECHITS->Fill(ncscRechits);
      for (int j = 0; j < ncscRechits; j++) {
          CSC_RECHITS_PHI->Fill(cscRechitsPhi[j]);
          CSC_RECHITS_ETA->Fill(cscRechitsEta[j]);
          CSC_RECHITS_X->Fill(fabs(cscRechitsX[j]));
          CSC_RECHITS_Y->Fill(fabs(cscRechitsY[j]));
          CSC_RECHITS_Z->Fill(fabs(cscRechitsZ[j]));
          CSC_RECHITS_E->Fill(cscRechitsE[j]);
          CSC_RECHITS_STATION->Fill(cscRechitsStation[j]);
          CSC_RECHITS_CHAMBER->Fill(cscRechitsChamber[j]);
          CSC_RECHITS_TPEAK->Fill(cscRechitsTpeak[j]);
          CSC_RECHITS_TWIRE->Fill(cscRechitsTwire[j]);
      }
      
      for (int j = 0; j < nMuons; j++) {
          RECO_MUON_PT->Fill(muonPt[j]);
          RECO_MUON_E->Fill(muonE[j]);
          RECO_MUON_ETA->Fill(muonEta[j]);
          RECO_MUON_PHI->Fill(muonPhi[j]);
      }
      
      CSC_CLUSTER_N -> Fill(nCscRechitClusters);
      for (int c = 0; c < nCscRechitClusters; c++) {
          CSC_CLUSTER_SIZE->Fill(cscRechitClusterSize[c]);
          CSC_CLUSTER_ETA ->Fill(cscRechitClusterEta[c]);
          CSC_CLUSTER_PHI ->Fill(cscRechitClusterPhi[c]);
          double dphi = delta_phi(cscRechitClusterPhi[c], llp_phi);
          double deta = fabs(cscRechitClusterEta[c] - llp_eta);
          double dr = sqrt(pow(dphi, 2) + pow(deta, 2));
          CSC_CLUSTER_DR->Fill(dr);
          if (dr < 0.4) {
              n_cls_llp++;
              LLP_CSC_CLUSTER_SIZE->Fill(cscRechitClusterSize[c]);
              LLP_CSC_CLUSTER_ETA->Fill(cscRechitClusterEta[c]);
              LLP_CSC_CLUSTER_PHI->Fill(cscRechitClusterPhi[c]);
              matched_llps += 1;
              double r = sqrt(pow(llp_pos_x, 2) + pow(llp_pos_y, 2));
              LLP_MATCHED_E->Fill(llp_e);
              LLP_MATCHED_PT->Fill(llp_pt);
              LLP_MATCHED_ETA->Fill(llp_eta);
              LLP_MATCHED_PHI->Fill(llp_phi);
              LLP_MATCHED_DECAY_VERTEX->Fill(fabs(llp_pos_z), r);
              LLP_MATCHED_DECAY_VERTEX_R->Fill(r);
              LLP_MATCHED_DECAY_VERTEX_Z->Fill(fabs(llp_pos_z));
          }
          dphi = delta_phi(cscRechitClusterPhi[c], muon_phi);
          deta = fabs(cscRechitClusterEta[c] - muon_eta);
          dr = sqrt(pow(dphi, 2) + pow(deta, 2));
          if (dr < 0.4) {
              MUON_CSC_CLUSTER_SIZE->Fill(cscRechitClusterSize[c]);
              MUON_CSC_CLUSTER_ETA->Fill(cscRechitClusterEta[c]);
              MUON_CSC_CLUSTER_PHI->Fill(cscRechitClusterPhi[c]);
          }
      }
      LLP_CSC_CLUSTER_N -> Fill(n_cls_llp);

      /*
      DT_CLUSTER_N -> Fill(nDtRechitClusters);
      for (int c = 0; c < nDtRechitClusters; c++) {
          DT_CLUSTER_SIZE->Fill(dtRechitClusterSize[c]);
          DT_CLUSTER_ETA ->Fill(dtRechitClusterEta[c]);
          DT_CLUSTER_PHI ->Fill(dtRechitClusterPhi[c]);
      }
      */
   }
   cout<<matched_llps<<"  /  "<<llps<<endl;
   LLP_DECAY->Write();
   LLP_MATCHED_DECAY_VERTEX->Write();
   LLP_MATCHED_DECAY_VERTEX_R->Write();
   LLP_MATCHED_DECAY_VERTEX_Z->Write();
   LLP_MATCHED_E->Write();
   LLP_MATCHED_PT->Write();
   LLP_MATCHED_PHI->Write();
   LLP_MATCHED_ETA->Write();
   LLP_DECAY_R->Write();
   LLP_DECAY_Z->Write();
   LLP_CTAU->Write();
   LLP_E->Write();
   LLP_PT->Write();
   LLP_ETA->Write();
   LLP_PHI->Write();
   LLP_DAUGHTER_E->Write();
   LLP_DAUGHTER_PT->Write();
   LLP_DAUGHTER_ETA->Write();
   LLP_DAUGHTER_PHI->Write();
   LLP_DAUGHTER_STATUS->Write();
   LLP_DAUGHTER_ID->Write();
   
   LLP_GRAND_DAUGHTER_E->Write();
   LLP_GRAND_DAUGHTER_PT->Write();
   LLP_GRAND_DAUGHTER_ETA->Write();
   LLP_GRAND_DAUGHTER_PHI->Write();
   LLP_GRAND_DAUGHTER_STATUS->Write();
   LLP_GRAND_DAUGHTER_ID->Write();
   
   LLP_DAUGHTER_PI_E->Write();
   LLP_DAUGHTER_PI_PT->Write();
   LLP_DAUGHTER_PI_ETA->Write();
   LLP_DAUGHTER_PI_PHI->Write();
   LLP_DAUGHTER_PI_STATUS->Write();
   LLP_DAUGHTER_PI_ID->Write();
   MUON_E->Write();
   MUON_PT->Write();
   MUON_ETA->Write();
   MUON_PHI->Write();
   RECO_MUON_E->Write();
   RECO_MUON_PT->Write();
   RECO_MUON_ETA->Write();
   RECO_MUON_PHI->Write();
   CSC_CLUSTER_SIZE->Write();
   CSC_CLUSTER_ETA->Write();
   CSC_CLUSTER_PHI->Write();
   CSC_CLUSTER_DR->Write();
   CSC_CLUSTER_N->Write();
   LLP_CSC_CLUSTER_SIZE->Write();
   LLP_CSC_CLUSTER_ETA->Write();
   LLP_CSC_CLUSTER_PHI->Write();
   MUON_CSC_CLUSTER_SIZE->Write();
   MUON_CSC_CLUSTER_ETA->Write();
   MUON_CSC_CLUSTER_PHI->Write();
   DT_CLUSTER_SIZE->Write();
   DT_CLUSTER_ETA->Write();
   DT_CLUSTER_PHI->Write();
   DT_CLUSTER_N->Write();
   N_CSC_RECHITS->Write();
   CSC_RECHITS_PHI->Write();
   CSC_RECHITS_ETA->Write();
   CSC_RECHITS_X->Write();
   CSC_RECHITS_Y->Write();
   CSC_RECHITS_Z->Write();
   CSC_RECHITS_E->Write();
   CSC_RECHITS_STATION->Write();
   CSC_RECHITS_CHAMBER->Write();
   CSC_RECHITS_TPEAK->Write();
   CSC_RECHITS_TWIRE->Write();
   LLP_CSC_CLUSTER_N->Write();
   LLP_DECAY_DAUGHTER->Write();

   output->Close();

}
