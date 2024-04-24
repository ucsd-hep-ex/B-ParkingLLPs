#include "FWCore/FWLite/interface/AutoLibraryLoader.h"
#include "DataFormats/FWLite/interface/Handle.h"
#include "DataFormats/FWLite/interface/Event.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include "TCanvas.h"
#include "TH1F.h"
#include "TFile.h"

// From fragment
//BFilter = cms.EDFilter("MCMultiParticleFilter",
//   AcceptMore = cms.bool(True),
//   EtaMax = cms.vdouble(10.0, 10.0, 10.0),
//   NumRequired = cms.int32(1),
//   ParticleID = cms.vint32(521, 511, 531),
//   PtMin = cms.vdouble(0.0, 0.0, 0.0),
//   Status = cms.vint32(0, 0, 0)
//)
//
//MuonFilter = cms.EDFilter("MCMultiParticleFilter",
//   AcceptMore = cms.bool(True),
//   EtaMax = cms.vdouble(10.0),
//   NumRequired = cms.int32(1),
//   ParticleID = cms.vint32(13),
//   PtMin = cms.vdouble(5.0),
//   Status = cms.vint32(0)
//)

//change etaMax to 2.0 from 10.0
bool passMuonFilter(float pT, float eta){
  bool pass = false;
  if(fabs(eta) < 2. && pT > 5.) pass = true;
  return pass;
}

void CheckGenFilters() {
    int STOP = 100000;
    gSystem->Load("libFWCoreFWLite.so");
    AutoLibraryLoader::enable();

    //fwlite::Event event(TFile::Open("data/BToKPhi_NoFilters_PhiToPiPlusPiMinus_m-0p3_ctau-300_TuneCP5_13TeV_pythia8.root"));
    fwlite::Event event(TFile::Open("data/BToKPhi_PhiToPiPlusPiMinus_m-0p3_ctau-300_TuneCP5_13TeV_pythia8-10k.root"));
    //fwlite::Event event(TFile::Open("data/BToKPhi_NoFilters_PhiToPiPlusPiMinus_m-0p3_ctau-300_TuneCP5_13TeV_pythia8-10k.root"));
    int nEvents = 0;
    TH1F* h_MuonEta = new TH1F("h_MuonEta", "h_MuonEta", 50, -10, 10);
    TH1F* h_MuonEtaPassSel = new TH1F("h_MuonEtaPassSel", "h_MuonEtaPassSel", 50, -10, 10);
    TH1F* h_pdgID = new TH1F("h_pdgID", "h_pdgID", 31, -15, 15);
    float Num = 0;
    float Den = 0;
    float nMuons = 0;
    for (event.toBegin(); !event.atEnd(); ++event) {
        if(nEvents%1000==0) std:cout<<"Processed "<<nEvents<<"  Events"<<std::endl;
        if(nEvents>=STOP) break;
        Den++;
        fwlite::Handle<std::vector<reco::GenParticle>> genParticles;
        genParticles.getByLabel(event, "genParticles");
        
        bool EventPass = false;
        for (const reco::GenParticle &p : *genParticles) {
          if(abs(p.pdgId()) == 13){
            nMuons++;
            h_MuonEta->Fill(p.eta());
            h_pdgID->Fill(p.pdgId());
            float muEta = p.eta();
            if( passMuonFilter(p.pt(), muEta) ) {
              if(!EventPass) Num++;
              EventPass = true;
              h_MuonEtaPassSel->Fill(p.eta());
              }
            //std::cout << "Event "<<nEvents<<
            //            "  Particle PDG ID: " << p.pdgId() << 
            //            ", pt: " << p.pt() << 
            //            ", eta: " << p.eta() << 
            //            ", status: " << p.status()<<
            //            std::endl;
          }   
        }   
      nEvents++;
    }   
    std::cout<<"nMuons "<<nMuons<<std::endl;
    std::cout<<"Num/Den "<<Num<<"/"<<Den<<" "<<Num/Den<<std::endl;
    TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
    h_MuonEta->Draw("");
    c1->SaveAs("h_MuonEta.png");
    
    h_pdgID->Draw("");
    c1->SaveAs("h_pdgID.png");

    h_MuonEtaPassSel->Draw("");
    c1->SaveAs("h_MuonEtaPassSel.png");
}
