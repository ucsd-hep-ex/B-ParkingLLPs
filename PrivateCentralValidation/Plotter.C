#include "TH1D.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"

void Plotter() {
    
    // Central
    TFile * central_file = new TFile("Central_PiPlusPiMinus_0p3_300.root");
    TH1D * central_gen_muon_e      = (TH1D *) central_file -> Get("MUON_E");
    TH1D * central_gen_muon_pt      = (TH1D *) central_file -> Get("MUON_PT");
    TH1D * central_gen_muon_eta     = (TH1D *) central_file -> Get("MUON_ETA");
    TH1D * central_gen_muon_phi     = (TH1D *) central_file -> Get("MUON_PHI");
    TH1D * central_reco_muon_e      = (TH1D *) central_file -> Get("RECO_MUON_E");
    TH1D * central_reco_muon_pt     = (TH1D *) central_file -> Get("RECO_MUON_PT");
    TH1D * central_reco_muon_eta    = (TH1D *) central_file -> Get("RECO_MUON_ETA");
    TH1D * central_reco_muon_phi    = (TH1D *) central_file -> Get("RECO_MUON_PHI");
    TH1D * central_llp_e            = (TH1D *) central_file -> Get("LLP_E");
    TH1D * central_llp_pt           = (TH1D *) central_file -> Get("LLP_PT");
    TH1D * central_llp_eta          = (TH1D *) central_file -> Get("LLP_ETA");
    TH1D * central_llp_phi          = (TH1D *) central_file -> Get("LLP_PHI");
    TH1D * central_llp_ctau         = (TH1D *) central_file -> Get("LLP_CTAU");
    TH1D * central_llp_decay_vertex_r = (TH1D *) central_file -> Get("LLP_DECAY_R");
    TH1D * central_llp_decay_vertex_z = (TH1D *) central_file -> Get("LLP_DECAY_Z");
    TH1D * central_llp_daughter_e = (TH1D *) central_file -> Get("LLP_DAUGHTER_E");
    TH1D * central_llp_daughter_pt = (TH1D *) central_file -> Get("LLP_DAUGHTER_PT");
    TH1D * central_llp_daughter_eta = (TH1D *) central_file -> Get("LLP_DAUGHTER_ETA");
    TH1D * central_llp_daughter_phi = (TH1D *) central_file -> Get("LLP_DAUGHTER_PHI");
    TH1D * central_llp_daughter_status = (TH1D *) central_file -> Get("LLP_DAUGHTER_STATUS");
    TH1D * central_llp_daughter_id = (TH1D *) central_file -> Get("LLP_DAUGHTER_ID");
    TH1D * central_llp_granddaughter_e = (TH1D *) central_file -> Get("LLP_GRAND_DAUGHTER_E");
    TH1D * central_llp_granddaughter_pt = (TH1D *) central_file -> Get("LLP_GRAND_DAUGHTER_PT");
    TH1D * central_llp_granddaughter_eta = (TH1D *) central_file -> Get("LLP_GRAND_DAUGHTER_ETA");
    TH1D * central_llp_granddaughter_phi = (TH1D *) central_file -> Get("LLP_GRAND_DAUGHTER_PHI");
    TH1D * central_llp_granddaughter_status = (TH1D *) central_file -> Get("LLP_GRAND_DAUGHTER_STATUS");
    TH1D * central_llp_granddaughter_id = (TH1D *) central_file -> Get("LLP_GRAND_DAUGHTER_ID");
    TH1D * central_llp_daughter_pi_e = (TH1D *) central_file -> Get("LLP_DAUGHTER_PI_E");
    TH1D * central_llp_daughter_pi_pt = (TH1D *) central_file -> Get("LLP_DAUGHTER_PI_PT");
    TH1D * central_llp_daughter_pi_eta = (TH1D *) central_file -> Get("LLP_DAUGHTER_PI_ETA");
    TH1D * central_llp_daughter_pi_phi = (TH1D *) central_file -> Get("LLP_DAUGHTER_PI_PHI");
    TH1D * central_llp_daughter_pi_status = (TH1D *) central_file -> Get("LLP_DAUGHTER_PI_STATUS");
    TH1D * central_llp_daughter_pi_id = (TH1D *) central_file -> Get("LLP_DAUGHTER_PI_ID");
    TH1D * central_csc_cluster_size = (TH1D *) central_file -> Get("CSC_CLUSTER_SIZE");
    TH1D * central_csc_cluster_eta  = (TH1D *) central_file -> Get("CSC_CLUSTER_ETA");
    TH1D * central_csc_cluster_phi  = (TH1D *) central_file -> Get("CSC_CLUSTER_PHI");
    TH1D * central_csc_cluster_dr  = (TH1D *) central_file -> Get("CSC_CLUSTER_DR");
    TH1D * central_csc_cluster_n    = (TH1D *) central_file -> Get("CSC_N_CLUSTERS");
    TH1D * central_llp_csc_cluster_size = (TH1D *) central_file -> Get("LLP_CSC_CLUSTER_SIZE");
    TH1D * central_llp_csc_cluster_eta  = (TH1D *) central_file -> Get("LLP_CSC_CLUSTER_ETA");
    TH1D * central_llp_csc_cluster_phi  = (TH1D *) central_file -> Get("LLP_CSC_CLUSTER_PHI");
    TH1D * central_llp_csc_cluster_n    = (TH1D *) central_file -> Get("LLP_CSC_CLUSTER_N");
    TH1D * central_llp_decay_vertex_cluster_r  = (TH1D *) central_file -> Get("LLP_CSC_CLUSTER_DECAY_VERTEX_R");
    TH1D * central_llp_decay_vertex_cluster_z  = (TH1D *) central_file -> Get("LLP_CSC_CLUSTER_DECAY_VERTEX_Z");
    TH1D * central_llp_cluster_e  = (TH1D *) central_file -> Get("LLP_MATCHED_E");
    TH1D * central_llp_cluster_pt  = (TH1D *) central_file -> Get("LLP_MATCHED_PT");
    TH1D * central_llp_cluster_eta  = (TH1D *) central_file -> Get("LLP_MATCHED_ETA");
    TH1D * central_llp_cluster_phi  = (TH1D *) central_file -> Get("LLP_MATCHED_PHI");
    TH1D * central_muon_csc_cluster_size = (TH1D *) central_file -> Get("MUON_CSC_CLUSTER_SIZE");
    TH1D * central_muon_csc_cluster_eta  = (TH1D *) central_file -> Get("MUON_CSC_CLUSTER_ETA");
    TH1D * central_muon_csc_cluster_phi  = (TH1D *) central_file -> Get("MUON_CSC_CLUSTER_PHI");
    TH1D * central_dt_cluster_size  = (TH1D *) central_file -> Get("DT_CLUSTER_SIZE");
    TH1D * central_dt_cluster_eta   = (TH1D *) central_file -> Get("DT_CLUSTER_ETA");
    TH1D * central_dt_cluster_phi   = (TH1D *) central_file -> Get("DT_CLUSTER_PHI");
    TH1D * central_dt_cluster_n     = (TH1D *) central_file -> Get("DT_N_CLUSTERS");
    TH1D * central_n_csc_rechits  = (TH1D *) central_file -> Get("N_CSC_RECHITS");
    TH1D * central_csc_rechits_eta  = (TH1D *) central_file -> Get("CSC_RECHITS_ETA");
    TH1D * central_csc_rechits_phi  = (TH1D *) central_file -> Get("CSC_RECHITS_PHI");
    TH1D * central_csc_rechits_x   = (TH1D *) central_file -> Get("CSC_RECHITS_X");
    TH1D * central_csc_rechits_y   = (TH1D *) central_file -> Get("CSC_RECHITS_Y");
    TH1D * central_csc_rechits_z   = (TH1D *) central_file -> Get("CSC_RECHITS_Z");
    TH1D * central_csc_rechits_e   = (TH1D *) central_file -> Get("CSC_RECHITS_E");
    TH1D * central_csc_rechits_stations   = (TH1D *) central_file -> Get("CSC_RECHITS_STATION");
    TH1D * central_csc_rechits_chambers   = (TH1D *) central_file -> Get("CSC_RECHITS_CHAMBER");
    TH1D * central_csc_rechits_tpeak   = (TH1D *) central_file -> Get("CSC_RECHITS_TPEAK");
    TH1D * central_csc_rechits_twire   = (TH1D *) central_file -> Get("CSC_RECHITS_TWIRE");
    // Private
    TFile * local_file = new TFile("Private_PiPlusPiMinus_0p3_300.root");
    TH1D * local_gen_muon_e      = (TH1D *) local_file -> Get("MUON_E");
    TH1D * local_gen_muon_pt      = (TH1D *) local_file -> Get("MUON_PT");
    TH1D * local_gen_muon_eta     = (TH1D *) local_file -> Get("MUON_ETA");
    TH1D * local_gen_muon_phi     = (TH1D *) local_file -> Get("MUON_PHI");
    TH1D * local_reco_muon_e     = (TH1D *) local_file -> Get("RECO_MUON_E");
    TH1D * local_reco_muon_pt     = (TH1D *) local_file -> Get("RECO_MUON_PT");
    TH1D * local_reco_muon_eta    = (TH1D *) local_file -> Get("RECO_MUON_ETA");
    TH1D * local_reco_muon_phi    = (TH1D *) local_file -> Get("RECO_MUON_PHI");
    TH1D * local_llp_e            = (TH1D *) local_file -> Get("LLP_E");
    TH1D * local_llp_pt           = (TH1D *) local_file -> Get("LLP_PT");
    TH1D * local_llp_eta          = (TH1D *) local_file -> Get("LLP_ETA");
    TH1D * local_llp_phi          = (TH1D *) local_file -> Get("LLP_PHI");
    TH1D * local_llp_ctau         = (TH1D *) local_file -> Get("LLP_CTAU");
    TH1D * local_llp_decay_vertex_r = (TH1D *) local_file -> Get("LLP_DECAY_R");
    TH1D * local_llp_decay_vertex_z = (TH1D *) local_file -> Get("LLP_DECAY_Z");
    TH1D * local_csc_cluster_size = (TH1D *) local_file -> Get("CSC_CLUSTER_SIZE");
    TH1D * local_csc_cluster_eta  = (TH1D *) local_file -> Get("CSC_CLUSTER_ETA");
    TH1D * local_csc_cluster_phi  = (TH1D *) local_file -> Get("CSC_CLUSTER_PHI");
    TH1D * local_csc_cluster_dr  = (TH1D *) local_file -> Get("CSC_CLUSTER_DR");
    TH1D * local_csc_cluster_n    = (TH1D *) local_file -> Get("CSC_N_CLUSTERS");
    // TH1D * local_llp_decay_vertex_r = (TH1D *) local_file -> Get("LLP_DECAY_R");
    // TH1D * local_llp_decay_vertex_z = (TH1D *) local_file -> Get("LLP_DECAY_Z");
    TH1D * local_llp_daughter_e = (TH1D *) local_file -> Get("LLP_DAUGHTER_E");
    TH1D * local_llp_daughter_pt = (TH1D *) local_file -> Get("LLP_DAUGHTER_PT");
    TH1D * local_llp_daughter_eta = (TH1D *) local_file -> Get("LLP_DAUGHTER_ETA");
    TH1D * local_llp_daughter_phi = (TH1D *) local_file -> Get("LLP_DAUGHTER_PHI");
    TH1D * local_llp_daughter_status = (TH1D *) local_file -> Get("LLP_DAUGHTER_STATUS");
    TH1D * local_llp_daughter_id = (TH1D *) local_file -> Get("LLP_DAUGHTER_ID");
    TH1D * local_llp_granddaughter_e = (TH1D *) local_file -> Get("LLP_GRAND_DAUGHTER_E");
    TH1D * local_llp_granddaughter_pt = (TH1D *) local_file -> Get("LLP_GRAND_DAUGHTER_PT");
    TH1D * local_llp_granddaughter_eta = (TH1D *) local_file -> Get("LLP_GRAND_DAUGHTER_ETA");
    TH1D * local_llp_granddaughter_phi = (TH1D *) local_file -> Get("LLP_GRAND_DAUGHTER_PHI");
    TH1D * local_llp_granddaughter_status = (TH1D *) local_file -> Get("LLP_GRAND_DAUGHTER_STATUS");
    TH1D * local_llp_granddaughter_id = (TH1D *) local_file -> Get("LLP_GRAND_DAUGHTER_ID");
    TH1D * local_llp_daughter_pi_e = (TH1D *) local_file -> Get("LLP_DAUGHTER_PI_E");
    TH1D * local_llp_daughter_pi_pt = (TH1D *) local_file -> Get("LLP_DAUGHTER_PI_PT");
    TH1D * local_llp_daughter_pi_eta = (TH1D *) local_file -> Get("LLP_DAUGHTER_PI_ETA");
    TH1D * local_llp_daughter_pi_phi = (TH1D *) local_file -> Get("LLP_DAUGHTER_PI_PHI");
    TH1D * local_llp_daughter_pi_status = (TH1D *) local_file -> Get("LLP_DAUGHTER_PI_STATUS");
    TH1D * local_llp_daughter_pi_id = (TH1D *) local_file -> Get("LLP_DAUGHTER_PI_ID");
    TH1D * local_llp_csc_cluster_size = (TH1D *) local_file -> Get("LLP_CSC_CLUSTER_SIZE");
    TH1D * local_llp_csc_cluster_eta  = (TH1D *) local_file -> Get("LLP_CSC_CLUSTER_ETA");
    TH1D * local_llp_csc_cluster_phi  = (TH1D *) local_file -> Get("LLP_CSC_CLUSTER_PHI");
    TH1D * local_llp_csc_cluster_n    = (TH1D *) local_file -> Get("LLP_CSC_CLUSTER_N");
    TH1D * local_llp_decay_vertex_cluster_r  = (TH1D *) local_file -> Get("LLP_CSC_CLUSTER_DECAY_VERTEX_R");
    TH1D * local_llp_decay_vertex_cluster_z  = (TH1D *) local_file -> Get("LLP_CSC_CLUSTER_DECAY_VERTEX_Z");
    TH1D * local_llp_cluster_e  = (TH1D *) local_file -> Get("LLP_MATCHED_E");
    TH1D * local_llp_cluster_pt  = (TH1D *) local_file -> Get("LLP_MATCHED_PT");
    TH1D * local_llp_cluster_eta  = (TH1D *) local_file -> Get("LLP_MATCHED_ETA");
    TH1D * local_llp_cluster_phi  = (TH1D *) local_file -> Get("LLP_MATCHED_PHI");
    TH1D * local_muon_csc_cluster_size = (TH1D *) local_file -> Get("MUON_CSC_CLUSTER_SIZE");
    TH1D * local_muon_csc_cluster_eta  = (TH1D *) local_file -> Get("MUON_CSC_CLUSTER_ETA");
    TH1D * local_muon_csc_cluster_phi  = (TH1D *) local_file -> Get("MUON_CSC_CLUSTER_PHI");
    TH1D * local_dt_cluster_size  = (TH1D *) local_file -> Get("DT_CLUSTER_SIZE");
    TH1D * local_dt_cluster_eta   = (TH1D *) local_file -> Get("DT_CLUSTER_ETA");
    TH1D * local_dt_cluster_phi   = (TH1D *) local_file -> Get("DT_CLUSTER_PHI");
    TH1D * local_dt_cluster_n     = (TH1D *) local_file -> Get("DT_N_CLUSTERS");
    TH1D * local_n_csc_rechits  = (TH1D *) local_file -> Get("N_CSC_RECHITS");
    TH1D * local_csc_rechits_eta  = (TH1D *) local_file -> Get("CSC_RECHITS_ETA");
    TH1D * local_csc_rechits_phi  = (TH1D *) local_file -> Get("CSC_RECHITS_PHI");
    TH1D * local_csc_rechits_x   = (TH1D *) local_file -> Get("CSC_RECHITS_X");
    TH1D * local_csc_rechits_y   = (TH1D *) local_file -> Get("CSC_RECHITS_Y");
    TH1D * local_csc_rechits_z   = (TH1D *) local_file -> Get("CSC_RECHITS_Z");
    TH1D * local_csc_rechits_e   = (TH1D *) local_file -> Get("CSC_RECHITS_E");
    TH1D * local_csc_rechits_stations   = (TH1D *) local_file -> Get("CSC_RECHITS_STATION");
    TH1D * local_csc_rechits_chambers   = (TH1D *) local_file -> Get("CSC_RECHITS_CHAMBER");
    TH1D * local_csc_rechits_tpeak   = (TH1D *) local_file -> Get("CSC_RECHITS_TPEAK");
    TH1D * local_csc_rechits_twire   = (TH1D *) local_file -> Get("CSC_RECHITS_TWIRE");
    
    TH1D * central_histograms[] = {
                                  central_gen_muon_e, \
                                  central_gen_muon_pt, \
                                  central_gen_muon_eta, \
                                  central_gen_muon_phi, \
                                  central_reco_muon_e, \
                                  central_reco_muon_pt, \
                                  central_reco_muon_eta, \
                                  central_reco_muon_phi, \
                                  central_llp_e, \
                                  central_llp_pt, \
                                  central_llp_eta, \
                                  central_llp_phi, \
                                  central_llp_ctau, \
                                  central_llp_decay_vertex_r, \
                                  central_llp_decay_vertex_z, \
                                  central_csc_cluster_size, \
                                  central_csc_cluster_eta, \
                                  central_csc_cluster_phi, \
                                  central_csc_cluster_dr, \
                                  central_csc_cluster_n, \
                                  central_llp_csc_cluster_size, \
                                  central_llp_csc_cluster_eta, \
                                  central_llp_csc_cluster_phi, \
                                  central_llp_decay_vertex_cluster_r, \
                                  central_llp_decay_vertex_cluster_z, \
                                  central_muon_csc_cluster_size, \
                                  central_muon_csc_cluster_eta, \
                                  central_muon_csc_cluster_phi, \
                                  central_dt_cluster_size, \
                                  central_dt_cluster_eta, \
                                  central_dt_cluster_phi, \
                                  central_dt_cluster_n, \
                                  central_n_csc_rechits, \
                                  central_csc_rechits_eta, \
                                  central_csc_rechits_phi, \
                                  central_csc_rechits_x, \
                                  central_csc_rechits_y, \
                                  central_csc_rechits_z, \
                                  central_csc_rechits_stations, \
                                  central_csc_rechits_chambers, \
                                  central_csc_rechits_twire, \
                                  central_csc_rechits_tpeak, \
                                  central_csc_rechits_e, \
                                  central_llp_cluster_e, \
                                  central_llp_cluster_pt, \
                                  central_llp_cluster_eta, \
                                  central_llp_cluster_phi, \
                                  central_llp_csc_cluster_n, \
                                  central_llp_daughter_e, \
                                  central_llp_daughter_pt, \
                                  central_llp_daughter_eta, \
                                  central_llp_daughter_phi, \
                                  central_llp_daughter_status, \
                                  central_llp_daughter_id, \
                                  central_llp_granddaughter_e, \
                                  central_llp_granddaughter_pt, \
                                  central_llp_granddaughter_eta, \
                                  central_llp_granddaughter_phi, \
                                  central_llp_granddaughter_status, \
                                  central_llp_granddaughter_id, \
                                  central_llp_daughter_pi_e, \
                                  central_llp_daughter_pi_pt, \
                                  central_llp_daughter_pi_eta, \
                                  central_llp_daughter_pi_phi, \
                                  central_llp_daughter_pi_status, \
                                  central_llp_daughter_pi_id
                                  };

    TH1D * local_histograms[] = {
                                  local_gen_muon_e, \
                                  local_gen_muon_pt, \
                                  local_gen_muon_eta, \
                                  local_gen_muon_phi, \
                                  local_reco_muon_e, \
                                  local_reco_muon_pt, \
                                  local_reco_muon_eta, \
                                  local_reco_muon_phi, \
                                  local_llp_e, \
                                  local_llp_pt, \
                                  local_llp_eta, \
                                  local_llp_phi, \
                                  local_llp_ctau, \
                                  local_llp_decay_vertex_r, \
                                  local_llp_decay_vertex_z, \
                                  local_csc_cluster_size, \
                                  local_csc_cluster_eta, \
                                  local_csc_cluster_phi, \
                                  local_csc_cluster_dr, \
                                  local_csc_cluster_n, \
                                  local_llp_csc_cluster_size, \
                                  local_llp_csc_cluster_eta, \
                                  local_llp_csc_cluster_phi, \
                                  local_llp_decay_vertex_cluster_r, \
                                  local_llp_decay_vertex_cluster_z, \
                                  local_muon_csc_cluster_size, \
                                  local_muon_csc_cluster_eta, \
                                  local_muon_csc_cluster_phi, \
                                  local_dt_cluster_size, \
                                  local_dt_cluster_eta, \
                                  local_dt_cluster_phi, \
                                  local_dt_cluster_n, \
                                  local_n_csc_rechits, \
                                  local_csc_rechits_eta, \
                                  local_csc_rechits_phi, \
                                  local_csc_rechits_x, \
                                  local_csc_rechits_y, \
                                  local_csc_rechits_z, \
                                  local_csc_rechits_stations, \
                                  local_csc_rechits_chambers, \
                                  local_csc_rechits_twire, \
                                  local_csc_rechits_tpeak, \
                                  local_csc_rechits_e, \
                                  local_llp_cluster_e, \
                                  local_llp_cluster_pt, \
                                  local_llp_cluster_eta, \
                                  local_llp_cluster_phi, \
                                  local_llp_csc_cluster_n, \
                                  local_llp_daughter_e, \
                                  local_llp_daughter_pt, \
                                  local_llp_daughter_eta, \
                                  local_llp_daughter_phi, \
                                  local_llp_daughter_status, \
                                  local_llp_daughter_id, \
                                  local_llp_granddaughter_e, \
                                  local_llp_granddaughter_pt, \
                                  local_llp_granddaughter_eta, \
                                  local_llp_granddaughter_phi, \
                                  local_llp_granddaughter_status, \
                                  local_llp_granddaughter_id, \
                                  local_llp_daughter_pi_e, \
                                  local_llp_daughter_pi_pt, \
                                  local_llp_daughter_pi_eta, \
                                  local_llp_daughter_pi_phi, \
                                  local_llp_daughter_pi_status, \
                                  local_llp_daughter_pi_id
                                  };

    TString names[] = {
        "E_MU_GEN", \
        "PT_MU_GEN", \
        "ETA_MU_GEN", \
        "PHI_MU_GEN", \
        "E_MU_RECO", \
        "PT_MU_RECO", \
        "ETA_MU_RECO", \
        "PHI_MU_RECO", \
        "E_LLP", \
        "PT_LLP", \
        "ETA_LLP", \
        "PHI_LLP", \
        "CTAU_LLP", \
        "R_LLP", \
        "Z_LLP", \
        "CLS_SIZE_CSC", \
        "CLS_ETA_CSC", \
        "CLS_PHI_CSC", \
        "CLS_DR_CSC", \
        "CLS_N_CSC", \
        "LLP_CLS_SIZE_CSC", \
        "LLP_CLS_ETA_CSC", \
        "LLP_CLS_PHI_CSC", \
        "R_CLUSTER_LLP", \
        "Z_CLUSTER_LLP", \
        "MUON_CLS_SIZE_CSC", \
        "MUON_CLS_ETA_CSC", \
        "MUON_CLS_PHI_CSC", \
        "CLS_SIZE_DT", \
        "CLS_ETA_DT", \
        "CLS_PHI_DT", \
        "CLS_N_DT", \
        "N_CSC_RECHITS", \
        "CSC_RECHITS_ETA", \
        "CSC_RECHITS_PHI", \
        "CSC_RECHITS_X", \
        "CSC_RECHITS_Y", \
        "CSC_RECHITS_Z", \
        "CSC_RECHITS_STATIONS", \
        "CSC_RECHITS_CHAMBERS", \
        "CSC_RECHITS_TWIRE", \
        "CSC_RECHITS_TPEAK", \
        "ENERGY", \
        "LLP_MATCHED_E", \
        "LLP_MATCHED_PT", \
        "LLP_MATCHED_ETA", \
        "LLP_MATCHED_PHI", \
        "Number_of_matched_clusters", \
        "LLP_DAUGHTER_E", \
        "LLP_DAUGHTER_PT", \
        "LLP_DAUGHTER_ETA", \
        "LLP_DAUGHTER_PHI", \
        "LLP_DAUGHTER_STATUS", \
        "LLP_DAUGHTER_ID", \
        "LLP_GRAND_DAUGHTER_E", \
        "LLP_GRAND_DAUGHTER_PT", \
        "LLP_GRAND_DAUGHTER_ETA", \
        "LLP_GRAND_DAUGHTER_PHI", \
        "LLP_GRAND_DAUGHTER_STATUS", \
        "LLP_GRAND_DAUGHTER_ID", \
        "LLP_DAUGHTER_PI_E", \
        "LLP_DAUGHTER_PI_PT", \
        "LLP_DAUGHTER_PI_ETA", \
        "LLP_DAUGHTER_PI_PHI", \
        "LLP_DAUGHTER_PI_STATUS", \
        "LLP_DAUGHTER_PI_ID"
    };
    
    TString labels[] = {
        "E_{GEN, #mu} [GeV]", \
        "P_{T, GEN, #mu} [GeV]", \
        "#eta_{GEN, #mu}", \
        "#phi_{GEN, #mu}", \
        "E_{RECO, #mu} [GeV]", \
        "P_{T, RECO, #mu} [GeV]", \
        "#eta_{RECO, #mu}", \
        "#phi_{RECO, #mu}", \
        "E_{#LLP} [GeV]", \
        "P_{T, #LLP} [GeV]", \
        "#eta_{#LLP}", \
        "#phi_{#LLP}", \
        "c#tau_{#LLP}", \
        "R_LLP", \
        "Z_LLP", \
        "Cluster size CSC", \
        "#eta_{cluster, CSC}", \
        "#phi_{cluster, CSC}", \
        "#DeltaR_{cluster, CSC}", \
        "Number of clusters (CSC)", \
        "Cluster size LLP CSC", \
        "#eta_{cluster, LLP, CSC}", \
        "#phi_{cluster, LLP, CSC}", \
        "R_CLUSTER_LLP", \
        "Z_CLUSTER_LLP", \
        "Cluster size MUON CSC", \
        "#eta_{cluster, MUON, CSC}", \
        "#phi_{cluster, MUON, CSC}", \
        "Cluster size DT", \
        "#eta_{cluster, DT}", \
        "#phi_{cluster, DT}", \
        "Number of clusters (DT)", \
        "N_{Rechits, CSC}", \
        "#eta_{rechits, CSC}", \
        "#phi_{rechits, CSC}", \
        "#x_{rechits, CSC}", \
        "#y_{rechits, CSC}", \
        "#z_{rechits, CSC}", \
        "Station", \
        "Chamber", \
        "Twire", \
        "Tpeak", \
        "Energy [GeV]", \
        "E_{LLP, matched}", \
        "P_{T, LLP, matched}", \
        "#eta_{LLP, matched}", \
        "#phi_{LLP, matched}", \
        "N_{cls, matched}", \
        "E_{LLP, daughter}", \
        "P_{T, LLP, daughter}", \
        "#eta_{LLP, daughter}", \
        "#phi_{LLP, daughter}", \
        "Status_{LLP, daughter}", \
        "ID_{LLP, daughter}", \
        "E_{LLP, granddaughter}", \
        "P_{T, LLP, granddaughter}", \
        "#eta_{LLP, granddaughter}", \
        "#phi_{LLP, granddaughter}", \
        "Status_{LLP, granddaughter}", \
        "ID_{LLP, granddaughter}", \
        "E_{LLP, daughter, PI}", \
        "P_{T, LLP, daughter, PI}", \
        "#eta_{LLP, daughter, PI}", \
        "#phi_{LLP, daughter, PI}", \
        "Status_{LLP, daughter, PI}", \
        "ID_{LLP, daughter, PI}",
    };
    
    cout<<sizeof(names)/sizeof(names[0])<<" "<<sizeof(labels)/sizeof(labels[0])<<" "<<sizeof(central_histograms)/sizeof(central_histograms[0])<<" "<<sizeof(local_histograms)/sizeof(local_histograms[0])<<endl;
    
    gStyle->SetOptStat(0000);
    
    for (int h = 0; h < sizeof(central_histograms) / sizeof(central_histograms[0]); h++) {
    
    local_histograms[h] -> Scale (1 / local_histograms[h]->Integral());
    central_histograms[h] -> Scale (1 / central_histograms[h]->Integral());
    
    TCanvas * c = new TCanvas("Canvas_" + names[h], "Canvas" + names[h], 1200, 1000);
    TLegend * l = new TLegend(0.8, 0.9, 1.0, 1.0);
    
    c->SetLogy();

    // rp->GetUpperPad()->cd();

    central_histograms[h]->Draw("HIST E");
    local_histograms[h]->Draw("SAME HIST E");
    
    // c->cd(1); // ==================================================================================================================

    central_histograms[h]->SetLineColor(4);
    local_histograms[h]->SetLineColor(2);

    central_histograms[h]->SetLineWidth(3);
    local_histograms[h]->SetLineWidth(3);

    central_histograms[h]->SetTitle("");
    local_histograms[h]->SetTitle("");

    c->cd(1)->SetTicks(0, 1);
    // c->cd(1)->Update();

    auto rp = new TRatioPlot(central_histograms[h], local_histograms[h]);
    rp->Draw("ep");
    rp->GetUpperRefYaxis()->SetLabelSize(0.04);

    // rp->GetLowerPad()->cd();

    rp->GetLowYaxis()->SetNdivisions(505);
    // rp->GetLowerRefGraph()->SetMinimum(0.0001);
    // rp->GetLowerRefGraph()->SetMaximum(4.0);
    l->AddEntry(central_histograms[h], "Central");
    // l->AddEntry(central_histograms[h], "New Private");
    l->AddEntry(local_histograms[h], "Private");
    l->Draw("SAME");
    
    local_histograms[h]->GetYaxis()->SetTitle("");
    local_histograms[h]->GetXaxis()->SetTitle("");
    central_histograms[h]->GetYaxis()->SetTitle("Events");
    central_histograms[h]->GetXaxis()->SetTitle(labels[h]);
    
    // c->SaveAs("./plot_dump/" + names[h] + ".png");
    c->SaveAs("./plot_dump_log/" + names[h] + ".png");

    }
    /*
    c->cd(2); // ==================================================================================================================

    central_muon_eta->SetLineColor(4);
    local_reco_muon_eta->SetLineColor(2);

    central_muon_eta->SetLineWidth(3);
    local_muon_eta->SetLineWidth(3);

    // l->AddEntry(central_muon_eta, "Central");
    // l->AddEntry(local_muon_eta, "Local");

    central_muon_eta->SetTitle("");
    local_muon_eta->SetTitle("");

    central_muon_eta->Draw("HIST E");
    local_muon_eta->Draw("HIST E SAME");

    rp = new TRatioPlot(central_muon_eta, local_muon_eta);
    c->cd(2)->SetTicks(0, 1);
    rp->Draw("SAME");
    rp->GetLowYaxis()->SetNdivisions(505);
    rp->GetLowerRefGraph()->SetMinimum(0.0);
    rp->GetLowerRefGraph()->SetMaximum(4.0);
    c->cd(2)->Update();

    // local_muon_eta->GetYaxis()->SetTitle("Events");
    // central_muon_eta->GetYaxis()->SetTitle("Events");
    central_muon_eta->GetXaxis()->SetTitle("#eta_{#mu}");

    c->cd(3); // ===============================
    
    l->AddEntry(central_muon_pt, "Central");
    l->AddEntry(local_muon_pt, "Private");
    l->Draw("SAME");
    
    c->cd(6); // ==================================================================================================================

    central_llp_ctau->SetLineColor(4);
    local_llp_ctau->SetLineColor(2);

    central_llp_ctau->SetLineWidth(3);
    local_llp_ctau->SetLineWidth(3);

    central_llp_ctau->Draw("HIST E");
    local_llp_ctau->Draw("HIST E SAME");

    central_llp_ctau->SetTitle("");
    local_llp_ctau->SetTitle("");

    c->cd(6)->SetLogy();
    c->cd(6)->Update();

    rp = new TRatioPlot(central_llp_ctau, local_llp_ctau);
    c->cd(6)->SetTicks(0, 1);
    rp->Draw("SAME");
    rp->GetLowYaxis()->SetNdivisions(505);
    rp->GetLowerRefGraph()->SetMinimum(0.0);
    rp->GetLowerRefGraph()->SetMaximum(4.0);
    c->cd(6)->Update();

    // local_llp_ctau->GetYaxis()->SetTitle("Events");
    // central_llp_ctau->GetYaxis()->SetTitle("Events");
    central_llp_ctau->GetXaxis()->SetTitle("c#tau_{LLP} [cm]");
    
    c->cd(4); // ==================================================================================================================

    central_llp_pt->SetLineColor(4);
    local_llp_pt->SetLineColor(2);

    central_llp_pt->SetLineWidth(3);
    local_llp_pt->SetLineWidth(3);

    central_llp_pt->Draw("HIST E");
    local_llp_pt->Draw("HIST E SAME");

    central_llp_pt->SetTitle("");
    local_llp_pt->SetTitle("");

    c->cd(4)->SetLogy();
    c->cd(4)->Update();

    rp = new TRatioPlot(central_llp_pt, local_llp_pt);
    c->cd(4)->SetTicks(0, 1);
    rp->Draw("SAME");
    rp->GetLowYaxis()->SetNdivisions(505);
    rp->GetLowerRefGraph()->SetMinimum(0.0);
    rp->GetLowerRefGraph()->SetMaximum(4.0);
    c->cd(4)->Update();
    
    // local_llp_pt->GetYaxis()->SetTitle("Events");
    // central_llp_pt->GetYaxis()->SetTitle("Events");
    central_llp_pt->GetXaxis()->SetTitle("P_{T, LLP} [GeV]");
    
    c->cd(5); // ==================================================================================================================

    central_llp_eta->SetLineColor(4);
    local_llp_eta->SetLineColor(2);

    central_llp_eta->SetLineWidth(3);
    local_llp_eta->SetLineWidth(3);

    central_llp_eta->Draw("HIST E");
    local_llp_eta->Draw("HIST E SAME");

    central_llp_eta->SetTitle("");
    local_llp_eta->SetTitle("");

    rp = new TRatioPlot(central_llp_eta, local_llp_eta);
    c->cd(5)->SetTicks(0, 1);
    rp->Draw("SAME");
    rp->GetLowYaxis()->SetNdivisions(505);
    rp->GetLowerRefGraph()->SetMinimum(0.0);
    rp->GetLowerRefGraph()->SetMaximum(4.0);
    c->cd(5)->Update();

    // local_llp_eta->GetYaxis()->SetTitle("Events");
    // central_llp_eta->GetYaxis()->SetTitle("Events");
    central_llp_eta->GetXaxis()->SetTitle("#eta_{LLP}");

    */

}