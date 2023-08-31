import pickle
import awkward as ak
import hist as hs
import numpy as np
import mplhep as hep

from coffea import processor
from coffea.nanoevents.methods import vector, candidate
from coffea.nanoevents import BaseSchema

class ProcessorV3(processor.ProcessorABC):
    def __init__(self, sys):
        self.MuonSystem = sys
        
        
    def delta_cls_gLLP(self, events):
        cluster_eta = []
        cluster_phi = []
        if self.MuonSystem == "DT":
            cluster_eta = events.dtRechitClusterEta
            cluster_phi = events.dtRechitClusterPhi
        elif self.MuonSystem == "CSC":
            cluster_eta = events.cscRechitClusterEta
            cluster_phi = events.cscRechitClusterPhi
        
        clusts = ak.zip(
            {
                'pt': ak.zeros_like(cluster_phi),
                'phi': cluster_phi,
                'eta': cluster_eta,
                'E': ak.zeros_like(cluster_phi),
            },
            with_name = 'PtEtaPhiMLorentzVector',
            behavior = vector.behavior,                 
          )
        
        gLLPs = ak.zip(
            {
                'pt': events.gLLP_pt,
                'phi': events.gLLP_phi,
                'eta': events.gLLP_eta,
                'E': events.gLLP_e,
            },
            with_name = 'PtEtaPhiMLorentzVector',
            behavior = vector.behavior,                 
          )        
        cls_llp_pairs = ak.cartesian({
            "cls": clusts,
            "llp": gLLPs
        }, nested = True) 
        
        deltaR = (cls_llp_pairs.cls).delta_r(cls_llp_pairs.llp)
        deltaEta = abs(cls_llp_pairs.cls.eta - cls_llp_pairs.llp.eta)
        deltaPhi = np.arctan2(np.sin(cls_llp_pairs.cls.phi - cls_llp_pairs.llp.phi), 
                              np.cos(cls_llp_pairs.cls.phi - cls_llp_pairs.llp.phi))
        
        deltaR, deltaEta, deltaPhi = ak.flatten(deltaR, axis=2), ak.flatten(deltaEta, axis=2), ak.flatten(deltaPhi, axis=2)
        return deltaR, deltaEta, deltaPhi,
    
    def delta_cls_leadmuon(self, events):
        cluster_eta = []
        cluster_phi = []
        if self.MuonSystem == "DT":
            cluster_eta = events.dtRechitClusterEta
            cluster_phi = events.dtRechitClusterPhi
        elif self.MuonSystem == "CSC":
            cluster_eta = events.cscRechitClusterEta
            cluster_phi = events.cscRechitClusterPhi

        clusts = ak.zip(
            {
                'pt': ak.zeros_like(cluster_phi),
                'phi': cluster_phi,
                'eta': cluster_eta,
                'E': ak.zeros_like(cluster_phi),
            },
            with_name = 'PtEtaPhiMLorentzVector',
            behavior = vector.behavior,                 
          )
        leadMuons = ak.zip(
            {
                'pt': events.muonPt,
                'phi': events.muonPhi,
                'eta': events.muonEta,
                'E': events.muonE,
            },
            with_name = 'PtEtaPhiMLorentzVector',
            behavior = vector.behavior,                 
          )
        cls_muon_pairs = ak.cartesian({
            "cls": clusts, 
            "muon": leadMuons,
        }, nested = True)
 
        deltaR = (cls_muon_pairs.cls).delta_r(cls_muon_pairs.muon)
        deltaEta = abs(cls_muon_pairs.cls.eta - cls_muon_pairs.muon.eta)
        deltaPhi = np.arctan2(np.sin(cls_muon_pairs.cls.phi - cls_muon_pairs.muon.phi), 
                              np.cos(cls_muon_pairs.cls.phi - cls_muon_pairs.muon.phi))
        deltaR, deltaEta, deltaPhi = ak.flatten(deltaR, axis=2), ak.flatten(deltaEta, axis=2), ak.flatten(deltaPhi, axis=2)
        return deltaR, deltaEta, deltaPhi

    def delta_leadmuon_cls(self, events):
        cluster_eta = []
        cluster_phi = []
        if self.MuonSystem == "DT":
            cluster_eta = events.dtRechitClusterEta
            cluster_phi = events.dtRechitClusterPhi
        elif self.MuonSystem == "CSC":
            cluster_eta = events.cscRechitClusterEta
            cluster_phi = events.cscRechitClusterPhi

        clusts = ak.zip(
            {
                'pt': ak.zeros_like(cluster_phi),
                'phi': cluster_phi,
                'eta': cluster_eta,
                'E': ak.zeros_like(cluster_phi),
            },
            with_name = 'PtEtaPhiMLorentzVector',
            behavior = vector.behavior,                 
          )
        leadMuons = ak.zip(
            {
                'pt': events.muonPt,
                'phi': events.muonPhi,
                'eta': events.muonEta,
                'E': events.muonE,
            },
            with_name = 'PtEtaPhiMLorentzVector',
            behavior = vector.behavior,                 
          )
        cls_muon_pairs = ak.cartesian({
            "muon": leadMuons,
            "cls": clusts, 
        }, nested = True)
 
        deltaR = (cls_muon_pairs.cls).delta_r(cls_muon_pairs.muon)
        deltaEta = abs(cls_muon_pairs.cls.eta - cls_muon_pairs.muon.eta)
        deltaPhi = np.arctan2(np.sin(cls_muon_pairs.cls.phi - cls_muon_pairs.muon.phi), 
                              np.cos(cls_muon_pairs.cls.phi - cls_muon_pairs.muon.phi))
        mask = (ak.min(deltaR, axis=2, mask_identity=True) == deltaR)
        deltaR, deltaEta, deltaPhi = ak.flatten(deltaR[mask], axis=2), ak.flatten(deltaEta[mask], axis=2), ak.flatten(deltaPhi[mask], axis=2)
        return deltaR, deltaEta, deltaPhi

    def delta_kaon_cls(self, events):
        cluster_eta = []
        cluster_phi = []
        if self.MuonSystem == "DT":
            cluster_eta = events.dtRechitClusterEta
            cluster_phi = events.dtRechitClusterPhi
        elif self.MuonSystem == "CSC":
            cluster_eta = events.cscRechitClusterEta
            cluster_phi = events.cscRechitClusterPhi

        clusts = ak.zip(
            {
                'pt': ak.zeros_like(cluster_phi),
                'phi': cluster_phi,
                'eta': cluster_eta,
                'E': ak.zeros_like(cluster_phi),
            },
            with_name = 'PtEtaPhiMLorentzVector',
            behavior = vector.behavior,                 
          )
        leadMuons = ak.zip(
            {
                'pt': events.kaonPt,
                'phi': events.kaonPhi,
                'eta': events.kaonEta,
                'E': events.kaonE,
            },
            with_name = 'PtEtaPhiMLorentzVector',
            behavior = vector.behavior,
          )
        cls_muon_pairs = ak.cartesian({
            "cls": clusts, 
            "muon": leadMuons,
        }, nested = True)
 
        deltaR = (cls_muon_pairs.cls).delta_r(cls_muon_pairs.muon)
        deltaEta = abs(cls_muon_pairs.cls.eta - cls_muon_pairs.muon.eta)
        deltaPhi = np.arctan2(np.sin(cls_muon_pairs.cls.phi - cls_muon_pairs.muon.phi), 
                              np.cos(cls_muon_pairs.cls.phi - cls_muon_pairs.muon.phi))
        deltaR, deltaEta, deltaPhi = ak.flatten(deltaR, axis=2), ak.flatten(deltaEta, axis=2), ak.flatten(deltaPhi, axis=2)
        return deltaR, deltaEta, deltaPhi

    def delta_kaon_gllp(self, events):
        cluster_eta = []
        cluster_phi = []
        if self.MuonSystem == "DT":
            cluster_eta = events.dtRechitClusterEta
            cluster_phi = events.dtRechitClusterPhi
        elif self.MuonSystem == "CSC":
            cluster_eta = events.cscRechitClusterEta
            cluster_phi = events.cscRechitClusterPhi
        
        clusts = ak.zip(
            {
                'pt': ak.zeros_like(cluster_phi),
                'phi': cluster_phi,
                'eta': cluster_eta,
                'E': ak.zeros_like(cluster_phi),
            },
            with_name = 'PtEtaPhiMLorentzVector',
            behavior = vector.behavior,                 
          )
        
        gLLPs = ak.zip(
            {
                'pt': events.kaonPt[:,0],
                'phi': events.kaonPhi[:,0],
                'eta': events.kaonEta[:,0],
                'E': events.kaonE[:,0],
            },
            with_name = 'PtEtaPhiMLorentzVector',
            behavior = vector.behavior,
          )        
        cls_llp_pairs = ak.cartesian({
            "cls": clusts,
            "llp": gLLPs
        }, nested = True) 
        
        deltaR = (cls_llp_pairs.cls).delta_r(cls_llp_pairs.llp)
        deltaEta = abs(cls_llp_pairs.cls.eta - cls_llp_pairs.llp.eta)
        deltaPhi = np.arctan2(np.sin(cls_llp_pairs.cls.phi - cls_llp_pairs.llp.phi), 
                              np.cos(cls_llp_pairs.cls.phi - cls_llp_pairs.llp.phi))
       
        deltaR, deltaEta, deltaPhi = ak.flatten(deltaR, axis=2), ak.flatten(deltaEta, axis=2), ak.flatten(deltaPhi, axis=2)
        return deltaR, deltaEta, deltaPhi,

    def process(self, events):
        signame = 'Phi'
        
        # >>> output dict init >>>
        dataset = events.metadata['dataset']
        out = {
            dataset: {},
            f'{dataset}_cuts': {},
            f'{dataset}_vars': {},
        }
        # <<< output dict init <<<

        out[dataset][f'numEvents_pretrigger'] = len(events)
        out[dataset][f'numEvents_pretrigger_SF'] = len(events)
        
        muoncut = abs(events.lepPdgId) == 13
        events['muonE'] = events.lepE[muoncut]
        events['muonPt'] = events.lepPt[muoncut]
        events['muonEta'] = events.lepEta[muoncut]
        events['muonPhi'] = events.lepPhi[muoncut]
        events['muonPdgId'] = events.lepPdgId[muoncut]
        events['muonDZ'] = events.lepDZ[muoncut]
        events['muonLooseId'] = events.lepLooseId[muoncut]
        events['muonTightId'] = events.lepTightId[muoncut] 
        if signame in dataset:
            events['muonDXY'] = events.lepDXY[muoncut]
            events['muonDXYErr'] = events.lepDXYErr[muoncut]
            events['muonSF'] = events.lepSF[muoncut]
            out[dataset][f'numEvents_|muonId| == 13_SF'] = len(events.muonPt)
        events['muonType'] = events.lepMuonType[muoncut]
        events['muonQuality'] = events.lepMuonQuality[muoncut]
        events['muon_passHLTFilter'] = events.lepMuon_passHLTFilter[muoncut]
        events = events[ak.count(events.muonPt, axis=1) > 0] #kill all events with empty muons
        out[dataset][f'numEvents_|muonId| == 13'] = len(events.muonPt)

        # cut and mutate events based on this new branch
        def muoncutter(events, muoncut):
            events['muonE'] = events.muonE[muoncut]
            events['muonPt'] = events.muonPt[muoncut]
            events['muonEta'] = events.muonEta[muoncut]
            events['muonPhi'] = events.muonPhi[muoncut]
            events['muonPdgId'] = events.muonPdgId[muoncut]
            events['muonDZ'] = events.muonDZ[muoncut]
            events['muonLooseId'] = events.muonLooseId[muoncut]
            events['muonTightId'] = events.muonTightId[muoncut]
            if signame in dataset:
                events['muonDXY'] = events.muonDXY[muoncut]
                events['muonDXYErr'] = events.muonDXYErr[muoncut]
                events['muonSF'] = events.muonSF[muoncut]
            # if '1p0' not in dataset:
            events['muonType'] = events.muonType[muoncut]
            events['muonQuality'] = events.muonQuality[muoncut]
            events['muon_passHLTFilter'] = events.muon_passHLTFilter[muoncut]
            events = events[ak.count(events.muonPt, axis=1) > 0] #kill all events with empty muons
            return events
        
        events = muoncutter(events, abs(events.muonEta) < 1.5)
        out[dataset][f'numEvents_|muonEta| < 1.5'] = len(events.muonPt)
        if signame in dataset:
            out[dataset][f'numEvents_|muonEta| < 1.5_SF'] = len(events.muonPt)
        events = muoncutter(events, events.muonPt > 7)
        out[dataset][f'numEvents_muonPt > 7'] = len(events.muonPt)
        if signame in dataset:
            out[dataset][f'numEvents_muonPt > 7_SF'] = len(events.muonPt)
        events = muoncutter(events, ak.any(events.muon_passHLTFilter[:,:,range(60,68)], axis=2))
        out[dataset][f'numEvents_muonHLTReq'] = len(events.muonPt)
        if signame in dataset:
            out[dataset][f'numEvents_muonHLTReq_SF'] = sum(np.prod(events.muonSF, axis = 1))
        events = muoncutter(events, events.muonQuality >= 2**25)
        out[dataset][f'numEvents_muonQual >= 2^25'] = len(events.muonPt)
        if signame in dataset:
            out[dataset][f'numEvents_muonQual >= 2^25_SF'] = sum(np.prod(events.muonSF, axis = 1))
        
        cls_leadmuon_deltaR, cls_leadmuon_deltaEta, cls_leadmuon_deltaPhi = self.delta_leadmuon_cls(events)
        events['dtRechitCluster_leadmuon_deltaR_muon'] = cls_leadmuon_deltaR

        leadcut = (ak.max(events.muonPt, axis=1, mask_identity=True) == events.muonPt)
        events['leadMuonE'] = events.muonE[leadcut]
        events['leadMuonPt'] = events.muonPt[leadcut]
        events['leadMuonEta'] = events.muonEta[leadcut]
        events['leadMuonPhi'] = events.muonPhi[leadcut]
        events['leadMuonPdgId'] = events.muonPdgId[leadcut]
        events['leadMuonDZ'] = events.muonDZ[leadcut]
        events['leadMuonLooseId'] = events.muonLooseId[leadcut]
        events['leadMuonTightId'] = events.muonTightId[leadcut]
        if signame in dataset:
            events['leadmuonSF'] = events.muonSF[leadcut]
            events['leadmuonDXY'] = events.muonDXY[leadcut]
            events['leadmuonDXYErr'] = events.muonDXYErr[leadcut]
        events['leadMuonType'] = events.muonType[leadcut]
        events['leadMuonQuality'] = events.muonQuality[leadcut]
        events['leadMuon_passHLTFilter'] = events.muon_passHLTFilter[leadcut]
        out[dataset][f'numEvents_muonLeadPtReq'] = len(events.muonPt) # sum(np.prod(events.leadmuonSF, axis = 1))
        if signame in dataset:
            out[dataset][f'numEvents_muonLeadPtReq_SF'] = sum(np.prod(events.leadmuonSF, axis = 1))

        trig_muon_cut = (ak.min(events.dtRechitCluster_leadmuon_deltaR_muon, axis=1, mask_identity=True) == events.dtRechitCluster_leadmuon_deltaR_muon)
        trig_muon_cut = ak.Array([[True] if i is None else list(i) for i in list(trig_muon_cut)])
        events = muoncutter(events, trig_muon_cut)
        events = events[(ak.count(events.muonPhi, axis=1) > 0)] #just kill all events with no muons

        events['nMuons'] = ak.count(events.muonE, axis = 1)
        events['muonE'] = events.muonE[:,0]
        events['muonPt'] = events.muonPt[:,0]
        events['muonEta'] = events.muonEta[:,0]
        events['muonPhi'] = events.muonPhi[:,0]
        events['muonPdgId'] = events.muonPdgId[:,0]
        events['muonDZ'] = events.muonDZ[:,0]
        events['muonLooseId'] = events.muonLooseId[:,0]
        events['muonTightId'] = events.muonTightId[:,0]
        if signame in dataset:
            events['muonSF'] = np.prod(events.muonSF, axis = 1)
            events['muonDXY'] = events.muonDXY[:,0]
            events['muonDXYErr'] = events.muonDXYErr[:,0]
        events['muonType'] = events.muonType[:,0]
        events['muonQuality'] = events.muonQuality[:,0]
        events['muon_passHLTFilter'] = events.muon_passHLTFilter[:,0]

        if signame in dataset:
            cls_llp_deltaR, cls_llp_deltaEta, cls_llp_deltaPhi = self.delta_cls_gLLP(events)
            events['RechitCluster_llp_deltaR']   = cls_llp_deltaR
            events['RechitCluster_llp_deltaEta'] = cls_llp_deltaEta
            events['RechitCluster_llp_deltaPhi'] = cls_llp_deltaPhi

        cls_leadmuon_deltaR, cls_leadmuon_deltaEta, cls_leadmuon_deltaPhi = self.delta_cls_leadmuon(events)
        events['RechitCluster_leadmuon_deltaR']   = cls_leadmuon_deltaR
        events['RechitCluster_leadmuon_deltaEta'] = cls_leadmuon_deltaEta
        events['RechitCluster_leadmuon_deltaPhi'] = cls_leadmuon_deltaPhi
        
        Cuts = {}
        Vars = {}
        eventVars = {}

        __ = lambda x: x
        bins = 30
        
        # ================================================================= CSC =================================================================
        if self.MuonSystem == "CSC":
            dummy = ak.values_astype(ak.ones_like(events.nCscRechitClusters), 'bool') #dummy truth vector of same shape as csc variables
            Cuts = {
                'posttrigger': dummy, 
                'llp_acc': (events.gLLP_csc == 1) if signame in dataset else dummy,
                'num Cluster > 0': (events.nCscRechitClusters > 0),
                'dR_gllp_cls < .4': (events.RechitCluster_llp_deltaR < .4) if signame in dataset else dummy,
                'dR_lmuon_cls > .8': (events.RechitCluster_leadmuon_deltaR > .8),
                'ME1112_veto': ((events.cscRechitClusterNRechitChamberPlus11 <= 0)&(events.cscRechitClusterNRechitChamberMinus11 <= 0)&
                                (events.cscRechitClusterNRechitChamberPlus12 <= 0)&(events.cscRechitClusterNRechitChamberMinus12 <= 0)),
                're12_veto': (events.cscRechitCluster_match_RE12_0p4 == 0),
                'mb1_veto': (events.cscRechitCluster_match_MB1Seg_0p4 == 0),
                'rb1_veto': (events.cscRechitCluster_match_RB1_0p4 == 0),
                'muon_veto_pt < 20': (events.cscRechitClusterMuonVetoPt < 20),
                '-5 < cls_time < 12.5': ((events.cscRechitClusterTimeWeighted <= 12.5)&(events.cscRechitClusterTimeWeighted >= -5)),
                '|cls_timeSpread| < 20': (events.cscRechitClusterTimeSpreadWeightedAll <= 20),
                '|cls_eta| < 1.9': (abs(events.cscRechitClusterEta) < 1.9),
                'cut_based_ID': (((events.cscRechitClusterNStation10 >  1) & (abs(events.cscRechitClusterEta) < 1.9)) |
                                 ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 4) & (abs(events.cscRechitClusterEta) < 1.8)) |
                                 ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 3) & (abs(events.cscRechitClusterEta) < 1.5)) |
                                 ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 2) & (abs(events.cscRechitClusterEta) < 1.7)) |
                                 ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 1) & (abs(events.cscRechitClusterEta) < 1.0))),
                'cls_size > 130': (events.cscRechitClusterSize >= 130),
            }

            Vars = {
                'cscRechitClusterNRechitChamberPlus11':  [bins,    0,  10, __, ],
                'cscRechitClusterNRechitChamberMinus11': [bins,    0,  10, __, ],
                'cscRechitClusterNRechitChamberPlus12':  [bins,    0,  10, __, ],
                'cscRechitClusterNRechitChamberMinus12': [bins,    0,  10, __, ],
                'cscRechitCluster_match_RE12_0p4':       [bins,    0,  10, __, ],
                'cscRechitCluster_match_MB1Seg_0p4':     [bins,    0,  10, __, ],
                'cscRechitCluster_match_RB1_0p4':        [bins,    0,  10, __, ],
                'cscRechitClusterMuonVetoPt':            [bins,    0, 100, __, ],
                'cscRechitClusterTimeWeighted':          [bins,  -20,  20, __, ],
                'cscRechitClusterTimeSpreadWeightedAll': [bins,    0,  30, __, ],
                'cscRechitClusterEta':                   [bins,    -3,   3, __,],
                'cscRechitClusterSize':                  [bins,    50, 300, __, ],
                'cscRechitClusterNStation10':            [bins,    0,   5, __, ],
                'cscRechitClusterAvgStation10':          [bins,    0,   5, abs, ],
            }

            # if 'background' in dataset: # this is explicitly to protect from unblinding data
            Vars['cscRechitClusterSize'] = [int(bins/5),    50, 100, __, ]

        # ================================================================= DT =================================================================
        elif self.MuonSystem == "DT":
            HLT_MU_IP_sel = range(1157,1197)
            Cuts['eventHLT_cut'] = ak.any(events.HLTDecision[:,HLT_MU_IP_sel], axis=1)
            dummy = ak.values_astype(ak.ones_like(events.nDtRechitClusters), 'bool') #dummy truth vector of same shape as csc variables
            if dataset != 'background':
                Cuts['llp_decayed_in_dt']   = (events.gLLP_dt == 1)
            Cuts['N clusters >= 1']         = ((events.nDtRechitClusters >= 1) & (events.dtRechitClusterSize >= 50))
            if dataset != 'background':
                Cuts['cls_llp_deltaR_cut']  = (events.RechitCluster_llp_deltaR < 0.4)
            Cuts['cls_trigg_muon_deltaR_cut'] = (events.RechitCluster_leadmuon_deltaR > 0.8)
            Cuts['rpc_matching']            = (events.dtRechitCluster_match_RPChits_dPhi0p5 > 0)
            Cuts['muon_veto']               = (events.dtRechitClusterMuonVetoPt < 20)
            Cuts['mb1_veto']                = (events.dtRechitCluster_match_MB1hits_0p5 <= 1)
            Cuts['rpc_time_cut']            = (events.dtRechitCluster_match_RPCBx_dPhi0p5 == 0)
            Cuts['mb1_adjacent']            = (events.dtRechitCluster_match_MB1hits_cosmics_plus <= 8) & (events.dtRechitCluster_match_MB1hits_cosmics_minus <= 8)
            Cuts['cluster_size_100']        = (events.dtRechitClusterSize > 100)

            Vars = {
                'nDtRechitClusters':   [bins, 0, 5,    __, ],
                'nCscRechitClusters':  [bins, 0, 5,    __, ],
                'dtRechitClusterSize': [bins, 50, 300, __, ],
                'dtRechitClusterEta':  [bins, -3, 3,   __, ],
                'dtRechitClusterPhi':  [bins, -3, 3,   __, ],
                'dtRechitClusterMaxStation':   [bins, 0, 5, __, ],
                'dtRechitClusterNStation':     [bins, 0, 5, __, ],
                'dtRechitClusterNStation10':     [bins, 0, 5, __, ],
                'dtRechitClusterAvgStation10': [bins, 0, 5, __, ],
                'dtRechitCluster_match_RPCBx_dPhi0p5': [10, -5, 5, __, ],
                'dtRechitClusterJetVetoPt': [bins, 0, 100, __,],
            }
            eventVars['nDtStations25'] = [5, 0, 5, __,]
            eventVars['nDtWheels25'] = [6, 0, 6, __,]

        # Common variables for CSC and DT ====================================================================================================
        # Common variables for CSC and DT ====================================================================================================
        # Common variables for CSC and DT ====================================================================================================
        if signame in dataset:
            eventVars['gLLP_decay_vertex_r'] = [2*bins,   0, 1200, abs, ]
            eventVars['gLLP_decay_vertex_z'] = [2*bins,   0, 1200, abs, ]
            eventVars['gLLP_e'] = [bins,   0, 100, __, ]
            eventVars['gLLP_pt'] = [bins,   0, 100, __, ]
            eventVars['gLLP_dt'] = [bins,   0, 3, __, ]
            eventVars['gLLP_csc'] = [bins,   0, 3, __, ]
            eventVars['gLLP_ctau'] = [bins,   0, 1000, __, ]
            eventVars['gLLP_eta'] = [bins,   -3, 3, __, ]
            eventVars['gLLP_phi'] = [bins,   -4, 4, __, ]
            Vars['RechitCluster_llp_deltaR']   = [bins, 0, 5, __,]
            Vars['RechitCluster_llp_deltaEta'] = [bins, 0, 5, abs,]
            Vars['RechitCluster_llp_deltaPhi'] = [bins, 0, 5, __,]
            Vars['muonSF'] = [bins, 0, 1, __, ]
            Vars['muonDXY'] = [bins, 0, 50, __, ]
            Vars['muonDXYErr'] = [bins, 0, 50, __, ]

        Vars['nMuons']  = [bins, 0, 10, __, ]
        Vars['muonEta'] = [bins, -3, 3, __,]
        Vars['muonPhi'] = [bins, -3, 3, __,]
        Vars['muonPt'] = [bins, 0, 50, __,]
        Vars['nJets'] = [bins, 0, 100, __, ]
        Vars['RechitCluster_leadmuon_deltaR']   = [bins, 0, 5, __,]
        Vars['RechitCluster_leadmuon_deltaEta'] = [bins, 0, 5, abs,]
        Vars['RechitCluster_leadmuon_deltaPhi'] = [bins, 0, 5, __,]
        eventVars['metEENoise'] = [bins, 0, 100, __, ]
        eventVars['gLLP_ctau'] = [bins, 0, 1e3, __, ]
        eventVars['runNum'] = [1000, 0, 1000, __, ]
        eventVars['lumiSec'] = [1000, 0, 1000, __, ]
        eventVars['evtNum'] = [1000, 0, 1000, __, ]
        # eventVars['weight'] = [1000, 0, 1000, __, ]
        
        # Common variables for CSC and DT ====================================================================================================
        # Common variables for CSC and DT ====================================================================================================
        # Common variables for CSC and DT ====================================================================================================

        Vars = Vars | eventVars
        
        # >>> create hists >>> START

        bigCut = Cuts[list(Cuts.keys())[0]] #sets first cut
        for cut in Cuts:
            #print()
            #print(cut)
            out[f'{dataset}_cuts'][cut] = 1
            bigCut = bigCut & Cuts[cut]
            
            if bigCut.layout.minmax_depth == (2,2):
                temp = ak.any(bigCut, axis=1)
            elif bigCut.layout.minmax_depth == (1,1):
                temp = bigCut

            out[dataset][f'numEvents_{cut}'] = sum(temp)
            if signame in dataset:
                # out[dataset][f'numEvents_{cut}_SF'] = sum(ak.flatten(events["muonSF"], axis=None))
                out[dataset][f'numEvents_{cut}_SF'] = sum(events.muonSF[temp])
            for var in Vars:
                # print(var)
                v = Vars[var]
                if bigCut.layout.minmax_depth == (2,2) and events[var].layout.minmax_depth == (1,1):
                    temp2 = ak.any(bigCut, axis=1)
                else:
                    temp2 = bigCut
                data = events[var][temp2]
                data = ak.flatten(data, axis=None)
                # data = v[3](data)
                
                key = f'{var} with {cut}'
                if var == 'gLLP_ctau':
                    out[f'{dataset}_vars'][key] = tuple(data.to_list())
                
                if var == 'muonSF':
                    out[f'{dataset}_vars'][key] = tuple(data.to_list())
                                       
                out[dataset][key] = hs.Hist.new.Reg(v[0], v[1], v[2], name=var, label=var).Double()
                out[dataset][key].fill(data)
        # <<< create hists <<<

        return out
    
    def postprocess(self, accumulator):
        return accumulator

class ProcessorV2(processor.ProcessorABC):
    
    def delta_cls_X(self, events, X):
        clusts = ak.zip(
            {
                'pt': ak.zeros_like(events.cscRechitClusterPhi),
                'phi': events.cscRechitClusterPhi,
                'eta': events.cscRechitClusterEta,
                'E': ak.zeros_like(events.cscRechitClusterPhi),
            },
            with_name = 'PtEtaPhiMLorentzVector',
            behavior = vector.behavior,                 
        )        
        
        if X == 'gLLP':
            p = ak.zip(
                {
                    'pt': events.gLLP_pt,
                    'phi': events.gLLP_phi,
                    'eta': events.gLLP_eta,
                    'E': events.gLLP_e,
                },
                with_name = 'PtEtaPhiMLorentzVector',
                behavior = vector.behavior,                 
            )              
        elif X == 'leadmuon':
            p = ak.zip(
                {
                    'pt': events.leadMuonPt,
                    'phi': events.leadMuonPhi,
                    'eta': events.leadMuonEta,
                    'E': events.leadMuonE,
                },
                with_name = 'PtEtaPhiMLorentzVector',
                behavior = vector.behavior,                 
            )             
        else:
            raise Exception(f'X = {X} is not "gLLP" or "leadMuon".')
        
        cls_p_pairs = ak.cartesian(
            {
                "cls": clusts, 
                "p": p
            },
            nested = True
        )         

        deltaR = (cls_p_pairs.cls).delta_r(cls_p_pairs.p)
        deltaEta = abs(cls_p_pairs.cls.eta - cls_p_pairs.p.eta)
        #deltaPhi = np.sqrt(deltaR**2 - deltaEta**2)
        deltaPhi = np.arctan2(np.sin(cls_p_pairs.cls.phi - cls_p_pairs.p.phi), 
                              np.cos(cls_p_pairs.cls.phi - cls_p_pairs.p.phi))
        
        deltaR, deltaEta, deltaPhi = ak.flatten(deltaR, axis=2), ak.flatten(deltaEta, axis=2), ak.flatten(deltaPhi, axis=2)
        return deltaR, deltaEta, deltaPhi,
        
    
    def process(self, events):
        
        signame = 'Phi'
        
        # >>> output dict init >>>
        dataset = events.metadata['dataset']
        out = {
            dataset: {},
            f'{dataset}_cuts': {},
            f'{dataset}_vars': {},
        }
        # <<< output dict init <<<
        
        out[dataset][f'numEvents_pretrigger'] = len(events)
        
        # >>> some preprocessing >>>
        
            # add a new set of branches that only consists of values pertaining to muons
        muoncut = abs(events.lepPdgId) == 13
        events['muonE'] = events.lepE[muoncut]
        events['muonPt'] = events.lepPt[muoncut]
        events['muonEta'] = events.lepEta[muoncut]
        events['muonPhi'] = events.lepPhi[muoncut]
        events['muonPdgId'] = events.lepPdgId[muoncut]
        events['muonDZ'] = events.lepDZ[muoncut]
        events['muonLooseId'] = events.lepLooseId[muoncut]
        events['muonTightId'] = events.lepTightId[muoncut] 
        events['muonType'] = events.lepMuonType[muoncut]
        events['muonQuality'] = events.lepMuonQuality[muoncut]
        events['muon_passHLTFilter'] = events.lepMuon_passHLTFilter[muoncut]
        events = events[ak.count(events.muonPt, axis=1) > 0] #kill all events with empty muons
        out[dataset][f'numEvents_|muonId| == 13'] = len(events.muonPt)
        
        
            # cut and mutate events based on this new branch
        def muoncutter(events, muoncut):
            events['muonE'] = events.muonE[muoncut]
            events['muonPt'] = events.muonPt[muoncut]
            events['muonEta'] = events.muonEta[muoncut]
            events['muonPhi'] = events.muonPhi[muoncut]
            events['muonPdgId'] = events.muonPdgId[muoncut]
            events['muonDZ'] = events.muonDZ[muoncut]
            events['muonLooseId'] = events.muonLooseId[muoncut]
            events['muonTightId'] = events.muonTightId[muoncut]
            events['muonType'] = events.muonType[muoncut]
            events['muonQuality'] = events.muonQuality[muoncut]
            events['muon_passHLTFilter'] = events.muon_passHLTFilter[muoncut]
            events = events[ak.count(events.muonPt, axis=1) > 0] #kill all events with empty muons
            return events

        events = muoncutter(events, ak.any(events.muon_passHLTFilter[:,:,range(60,68)], axis=2))
        out[dataset][f'numEvents_muonHLTReq'] = len(events.muonPt)
            
        events = muoncutter(events, abs(events.muonEta) < 1.5)
        out[dataset][f'numEvents_|muonEta| < 1.5'] = len(events.muonPt)
        events = muoncutter(events, events.muonPt > 7)
        out[dataset][f'numEvents_muonPt > 7'] = len(events.muonPt)
        
        events = muoncutter(events, events.muonQuality >= 2**25)
        out[dataset][f'numEvents_soft_muon_ID'] = len(events.muonPt) 
            
            # finally keep only the leading muon
        leadcut = (ak.max(events.muonPt, axis=1, mask_identity=True) == events.muonPt)
        events['leadMuonE'] = events.muonE[leadcut][:,0]
        events['leadMuonPt'] = events.muonPt[leadcut][:,0]
        events['leadMuonEta'] = events.muonEta[leadcut][:,0]
        events['leadMuonPhi'] = events.muonPhi[leadcut][:,0]
        events['leadMuonPdgId'] = events.muonPdgId[leadcut][:,0]
        events['leadMuonDZ'] = events.muonDZ[leadcut][:,0]
        events['leadMuonLooseId'] = events.muonLooseId[leadcut][:,0]
        events['leadMuonTightId'] = events.muonTightId[leadcut][:,0]
        events['leadMuonType'] = events.muonType[leadcut][:,0]
        events['leadMuonQuality'] = events.muonQuality[leadcut][:,0]
        events['leadMuon_passHLTFilter'] = events.muon_passHLTFilter[leadcut][:,0]                
        out[dataset][f'numEvents_leadMuon_cut'] = len(events.leadMuonPt)

            # add branches pertaining to deltaR between either leading muon and cluster, or llp and cluster
        if signame in dataset:
            cls_llp_deltaR, cls_llp_deltaEta, cls_llp_deltaPhi = self.delta_cls_X(events, X='gLLP')
            events['cscRechitCluster_llp_deltaR'] = cls_llp_deltaR
            events['cscRechitCluster_llp_deltaEta'] = cls_llp_deltaEta
            events['cscRechitCluster_llp_deltaPhi'] = cls_llp_deltaPhi

            events['gLLP_decay_vertex_z_matched'] = events.gLLP_decay_vertex_z.mask[ak.any(cls_llp_deltaR < .4, axis=1)]
            events['gLLP_e_matched'] = events.gLLP_e.mask[ak.any(cls_llp_deltaR < .4, axis=1)]
            
        cls_leadmuon_deltaR, cls_leadmuon_deltaEta, cls_leadmuon_deltaPhi = self.delta_cls_X(events, X='leadmuon')
        events['cscRechitCluster_leadmuon_deltaR'] = cls_leadmuon_deltaR
        events['cscRechitCluster_leadmuon_deltaEta'] = cls_leadmuon_deltaEta
        events['cscRechitCluster_leadmuon_deltaPhi'] = cls_leadmuon_deltaPhi
        # <<< some preprocessing <<<

        
        # >>> cut definitions >>> 
        dummy = ak.values_astype(ak.ones_like(events.nCscRechitClusters), 'bool') #dummy truth vector of same shape as csc variables
        cscCuts = {
            'posttrigger': dummy, 
            'llp_acc': (events.gLLP_csc == 1) if signame in dataset else dummy,
            'num Cluster > 0': (events.nCscRechitClusters > 0),
            'dR_gllp_cls < .4': (events.cscRechitCluster_llp_deltaR < .4) if signame in dataset else dummy,
            'dR_lmuon_cls > .8': (events.cscRechitCluster_leadmuon_deltaR > .8),
            'ME1112_veto': ((events.cscRechitClusterNRechitChamberPlus11 <= 0)&(events.cscRechitClusterNRechitChamberMinus11 <= 0)&
                            (events.cscRechitClusterNRechitChamberPlus12 <= 0)&(events.cscRechitClusterNRechitChamberMinus12 <= 0)),
            're12_veto': (events.cscRechitCluster_match_RE12_0p4 == 0),
            'mb1_veto': (events.cscRechitCluster_match_MB1Seg_0p4 == 0),
            'rb1_veto': (events.cscRechitCluster_match_RB1_0p4 == 0),
            'muon_veto_pt < 20': (events.cscRechitClusterMuonVetoPt < 20),
            '-5 < cls_time < 12.5': ((events.cscRechitClusterTimeWeighted <= 12.5)&(events.cscRechitClusterTimeWeighted >= -5)),
            '|cls_timeSpread| < 20': (events.cscRechitClusterTimeSpreadWeightedAll <= 20),
            '|cls_eta| < 1.9': (abs(events.cscRechitClusterEta) < 1.9),
            # 'cut_based_ID': (
            #         ((events.cscRechitClusterNStation10 >  1) & (abs(events.cscRechitClusterEta) < 1.9)) |
            #         ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 4) & (abs(events.cscRechitClusterEta) < 1.8)) |
            #         ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 3) & (abs(events.cscRechitClusterEta) < 1.6)) |
            #         ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 2) & (abs(events.cscRechitClusterEta) < 1.6)) |
            #         ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 1) & (abs(events.cscRechitClusterEta) < 1.1))
            #     ),
            'cut_based_ID': (
                    ((events.cscRechitClusterNStation10 >  1) & (abs(events.cscRechitClusterEta) < 1.9)) |
                    ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 4) & (abs(events.cscRechitClusterEta) < 1.8)) |
                    ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 3) & (abs(events.cscRechitClusterEta) > 1.5)) |
                    ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 2) & (abs(events.cscRechitClusterEta) < 1.7)) |
                    ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 1) & (abs(events.cscRechitClusterEta) < 1.0))
                ),
            
            
            'cls_size > 130': (events.cscRechitClusterSize >= 130),
        }
        # <<< cut definitions <<<

        # >>> variables to be plotted >>>                
        __ = lambda x: x
        bins = 30
        
        #must be same shape as any csc variable
        cscVars = {
            'cscRechitClusterNRechitChamberPlus11':  [bins,    0,  10, __, ],
            'cscRechitClusterNRechitChamberMinus11': [bins,    0,  10, __, ],
            'cscRechitClusterNRechitChamberPlus12':  [bins,    0,  10, __, ],
            'cscRechitClusterNRechitChamberMinus12': [bins,    0,  10, __, ],
            'cscRechitCluster_match_RE12_0p4':       [bins,    0,  10, __, ],
            'cscRechitCluster_match_MB1Seg_0p4':     [bins,    0,  10, __, ],
            'cscRechitCluster_match_RB1_0p4':        [bins,    0,  10, __, ],
            'cscRechitClusterMuonVetoPt':            [bins,    0, 100, __, ],
            'cscRechitClusterTimeWeighted':          [bins,  -20,  20, __, ],
            'cscRechitClusterTimeSpreadWeightedAll': [bins,    0,  30, __, ],
            'cscRechitClusterEta':                   [bins,    0,   3, abs,],
            'cscRechitClusterSize':                  [bins,    50, 300, __, ],
            'cscRechitClusterNStation10':            [bins,    0,   5, __, ],
            'cscRechitClusterAvgStation10':          [bins,    0,   5, abs, ],
        }
        
        if 'background' in dataset: # this is explicitly to protect from unblinding data
            cscVars['cscRechitClusterSize'] = [int(bins/5),    50, 100, __, ]

        if signame in dataset:
            cscVars['cscRechitCluster_llp_deltaR']   = [bins, 0, 5, __,]
            cscVars['cscRechitCluster_llp_deltaEta'] = [bins, 0, 5, abs,]
            cscVars['cscRechitCluster_llp_deltaPhi'] = [bins, 0, 5, __,]

        cscVars['cscRechitCluster_leadmuon_deltaR']   = [bins, 0, 5, __,]
        cscVars['cscRechitCluster_leadmuon_deltaEta'] = [bins, 0, 5, abs,]
        cscVars['cscRechitCluster_leadmuon_deltaPhi'] = [bins, 0, 5, __,]
        
        #must be flat variables of length nEvents
        eventVars = {
            'metEENoise': [bins,   0, 100, __, ],
            'gLLP_ctau': [bins, 0, 1e3, __, ],
        }
        
        if signame in dataset:        
            eventVars['gLLP_decay_vertex_z'] = [2*bins,   0, 1200, abs, ]
            eventVars['gLLP_decay_vertex_z_matched'] = [2*bins,   0, 1200, abs, ]
            eventVars['gLLP_e'] = [bins,   0, 100, __, ]
            eventVars['gLLP_e_matched'] = [bins,   0, 100, __, ]
            
        Vars = cscVars | eventVars
        # <<< variables to be plotted <<<
        
        
        # >>> create hists >>> 
        bigCut = cscCuts[list(cscCuts.keys())[0]] #sets first cut
        for cut in cscCuts:
            out[f'{dataset}_cuts'][cut] = 1       
            bigCut = bigCut & cscCuts[cut]
            
            if bigCut.layout.minmax_depth == (2,2):
                temp = ak.any(bigCut, axis=1)
            elif bigCut.layout.minmax_depth == (1,1):
                temp = bigCut
                          
            out[dataset][f'numEvents_{cut}'] = sum(temp)
            
            for var in Vars:

                out[f'{dataset}_vars'][var] = 1  
                v = Vars[var]
                
                if bigCut.layout.minmax_depth == (2,2) and events[var].layout.minmax_depth == (1,1):
                    temp2 = ak.any(bigCut, axis=1)
                else:
                    temp2 = bigCut
                
                data = ak.flatten(events[var][temp2], axis=None)
                data = v[3](data)
                key = f'{var} with {cut}'
                
                if signame in dataset:
                    out[f'{dataset}_vars'][key] = data.to_list()
                    
                if 'gLLP_e' in var:
                    out[dataset][key] = hs.Hist.new.Reg(v[0], v[1]+1, v[2], name=var, label=var, transform=hs.axis.transform.log).Double()
                else:
                    out[dataset][key] = hs.Hist.new.Reg(v[0], v[1], v[2], name=var, label=var).Double()
                out[dataset][key].fill(data) 
        # <<< create hists <<<
        return out
    
    def postprocess(self, accumulator):
        return accumulator
    


class ProcessorV1(processor.ProcessorABC):
    
    def delta_cls_X(self, events, X):
        clusts = ak.zip(
            {
                'pt': ak.zeros_like(events.cscRechitClusterPhi),
                'phi': events.cscRechitClusterPhi,
                'eta': events.cscRechitClusterEta,
                'E': ak.zeros_like(events.cscRechitClusterPhi),
            },
            with_name = 'PtEtaPhiMLorentzVector',
            behavior = vector.behavior,                 
        )        
        
        if X == 'gLLP':
            p = ak.zip(
                {
                    'pt': events.gLLP_pt,
                    'phi': events.gLLP_phi,
                    'eta': events.gLLP_eta,
                    'E': events.gLLP_e,
                },
                with_name = 'PtEtaPhiMLorentzVector',
                behavior = vector.behavior,                 
            )              
        elif X == 'leadmuon':
            p = ak.zip(
                {
                    'pt': events.leadMuonPt,
                    'phi': events.leadMuonPhi,
                    'eta': events.leadMuonEta,
                    'E': events.leadMuonE,
                },
                with_name = 'PtEtaPhiMLorentzVector',
                behavior = vector.behavior,                 
            )             
        else:
            raise Exception(f'X = {X} is not "gLLP" or "leadMuon".')
        
        cls_p_pairs = ak.cartesian(
            {
                "cls": clusts, 
                "p": p
            },
            nested = True
        )         

        deltaR = (cls_p_pairs.cls).delta_r(cls_p_pairs.p)
        deltaEta = abs(cls_p_pairs.cls.eta - cls_p_pairs.p.eta)
        #deltaPhi = np.sqrt(deltaR**2 - deltaEta**2)
        deltaPhi = np.arctan2(np.sin(cls_p_pairs.cls.phi - cls_p_pairs.p.phi), 
                              np.cos(cls_p_pairs.cls.phi - cls_p_pairs.p.phi))
        
        deltaR, deltaEta, deltaPhi = ak.flatten(deltaR, axis=2), ak.flatten(deltaEta, axis=2), ak.flatten(deltaPhi, axis=2)
        return deltaR, deltaEta, deltaPhi,
        
    
    def process(self, events):
        
        signame = 'Phi'
        
        # >>> output dict init >>>
        dataset = events.metadata['dataset']
        out = {
            dataset: {},
            f'{dataset}_cuts': {},
            f'{dataset}_vars': {},
        }
        # <<< output dict init <<<
        
        out[dataset][f'numEvents_pretrigger'] = len(events)
        
        # >>> some preprocessing >>>
        
            # add a new set of branches that only consists of values pertaining to muons
        muoncut = abs(events.lepPdgId) == 13
        events['muonE'] = events.lepE[muoncut]
        events['muonPt'] = events.lepPt[muoncut]
        events['muonEta'] = events.lepEta[muoncut]
        events['muonPhi'] = events.lepPhi[muoncut]
        events['muonPdgId'] = events.lepPdgId[muoncut]
        events['muonDZ'] = events.lepDZ[muoncut]
        events['muonLooseId'] = events.lepLooseId[muoncut]
        events['muonTightId'] = events.lepTightId[muoncut] 
        events['muonType'] = events.lepMuonType[muoncut]
        events['muonQuality'] = events.lepMuonQuality[muoncut]
        events['muon_passHLTFilter'] = events.lepMuon_passHLTFilter[muoncut]
        events = events[ak.count(events.muonPt, axis=1) > 0] #kill all events with empty muons
        out[dataset][f'numEvents_|muonId| == 13'] = len(events.muonPt)
        
        
            # cut and mutate events based on this new branch
        def muoncutter(events, muoncut):
            events['muonE'] = events.muonE[muoncut]
            events['muonPt'] = events.muonPt[muoncut]
            events['muonEta'] = events.muonEta[muoncut]
            events['muonPhi'] = events.muonPhi[muoncut]
            events['muonPdgId'] = events.muonPdgId[muoncut]
            events['muonDZ'] = events.muonDZ[muoncut]
            events['muonLooseId'] = events.muonLooseId[muoncut]
            events['muonTightId'] = events.muonTightId[muoncut]
            events['muonType'] = events.muonType[muoncut]
            events['muonQuality'] = events.muonQuality[muoncut]
            events['muon_passHLTFilter'] = events.muon_passHLTFilter[muoncut]
            events = events[ak.count(events.muonPt, axis=1) > 0] #kill all events with empty muons
            return events

        events = muoncutter(events, ak.any(events.muon_passHLTFilter[:,:,range(60,68)], axis=2))
        out[dataset][f'numEvents_muonHLTReq'] = len(events.muonPt)
            
        events = muoncutter(events, abs(events.muonEta) < 1.5)
        out[dataset][f'numEvents_|muonEta| < 1.5'] = len(events.muonPt)
        events = muoncutter(events, events.muonPt > 7)
        out[dataset][f'numEvents_muonPt > 7'] = len(events.muonPt)
        
        events = muoncutter(events, events.muonQuality >= 2**25)
        out[dataset][f'numEvents_soft_muon_ID'] = len(events.muonPt) 
            
            # finally keep only the leading muon
        leadcut = (ak.max(events.muonPt, axis=1, mask_identity=True) == events.muonPt)
        events['leadMuonE'] = events.muonE[leadcut][:,0]
        events['leadMuonPt'] = events.muonPt[leadcut][:,0]
        events['leadMuonEta'] = events.muonEta[leadcut][:,0]
        events['leadMuonPhi'] = events.muonPhi[leadcut][:,0]
        events['leadMuonPdgId'] = events.muonPdgId[leadcut][:,0]
        events['leadMuonDZ'] = events.muonDZ[leadcut][:,0]
        events['leadMuonLooseId'] = events.muonLooseId[leadcut][:,0]
        events['leadMuonTightId'] = events.muonTightId[leadcut][:,0]
        events['leadMuonType'] = events.muonType[leadcut][:,0]
        events['leadMuonQuality'] = events.muonQuality[leadcut][:,0]
        events['leadMuon_passHLTFilter'] = events.muon_passHLTFilter[leadcut][:,0]                
        out[dataset][f'numEvents_leadMuon_cut'] = len(events.leadMuonPt)

            # add branches pertaining to deltaR between either leading muon and cluster, or llp and cluster
        if signame in dataset:
            cls_llp_deltaR, cls_llp_deltaEta, cls_llp_deltaPhi = self.delta_cls_X(events, X='gLLP')
            events['cscRechitCluster_llp_deltaR'] = cls_llp_deltaR
            events['cscRechitCluster_llp_deltaEta'] = cls_llp_deltaEta
            events['cscRechitCluster_llp_deltaPhi'] = cls_llp_deltaPhi

            events['gLLP_decay_vertex_z_matched'] = events.gLLP_decay_vertex_z.mask[ak.any(cls_llp_deltaR < .4, axis=1)]
            events['gLLP_e_matched'] = events.gLLP_e.mask[ak.any(cls_llp_deltaR < .4, axis=1)]
            
        cls_leadmuon_deltaR, cls_leadmuon_deltaEta, cls_leadmuon_deltaPhi = self.delta_cls_X(events, X='leadmuon')
        events['cscRechitCluster_leadmuon_deltaR'] = cls_leadmuon_deltaR
        events['cscRechitCluster_leadmuon_deltaEta'] = cls_leadmuon_deltaEta
        events['cscRechitCluster_leadmuon_deltaPhi'] = cls_leadmuon_deltaPhi
        # <<< some preprocessing <<<

        
        # >>> cut definitions >>> 
        dummy = ak.values_astype(ak.ones_like(events.nCscRechitClusters), 'bool') #dummy truth vector of same shape as csc variables
        cscCuts = {
            'posttrigger': dummy, 
            'llp_acc': (events.gLLP_csc == 1) if signame in dataset else dummy,
            'num Cluster > 0': (events.nCscRechitClusters > 0),
            'dR_gllp_cls < .4': (events.cscRechitCluster_llp_deltaR < .4) if signame in dataset else dummy,
            'dR_lmuon_cls > .8': (events.cscRechitCluster_leadmuon_deltaR > .8),
            'ME1112_veto': ((events.cscRechitClusterNRechitChamberPlus11 <= 0)&(events.cscRechitClusterNRechitChamberMinus11 <= 0)&
                            (events.cscRechitClusterNRechitChamberPlus12 <= 0)&(events.cscRechitClusterNRechitChamberMinus12 <= 0)),
            're12_veto': (events.cscRechitCluster_match_RE12_0p4 == 0),
            'mb1_veto': (events.cscRechitCluster_match_MB1Seg_0p4 == 0),
            'rb1_veto': (events.cscRechitCluster_match_RB1_0p4 == 0),
            'muon_veto_pt < 20': (events.cscRechitClusterMuonVetoPt < 20),
            '-5 < cls_time < 12.5': ((events.cscRechitClusterTimeWeighted <= 12.5)&(events.cscRechitClusterTimeWeighted >= -5)),
            '|cls_timeSpread| < 20': (events.cscRechitClusterTimeSpreadWeightedAll <= 20),
            '|cls_eta| < 1.9': (abs(events.cscRechitClusterEta) < 1.9),
            'cut_based_ID': (((events.cscRechitClusterNStation10 >  1) & (abs(events.cscRechitClusterEta) < 1.9)) |
                             ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 4) & (abs(events.cscRechitClusterEta) < 1.8)) |
                             ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 3) & (abs(events.cscRechitClusterEta) < 1.6)) |
                             ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 2) & (abs(events.cscRechitClusterEta) < 1.6)) |
                             ((events.cscRechitClusterNStation10 == 1) & (abs(events.cscRechitClusterAvgStation10) == 1) & (abs(events.cscRechitClusterEta) < 1.1))),
            'cls_size > 130': (events.cscRechitClusterSize >= 130),
        }
        # <<< cut definitions <<<

        # >>> variables to be plotted >>>                
        __ = lambda x: x
        bins = 30
        
        #must be same shape as any csc variable
        cscVars = {
            'cscRechitClusterNRechitChamberPlus11':  [bins,    0,  10, __, ],
            'cscRechitClusterNRechitChamberMinus11': [bins,    0,  10, __, ],
            'cscRechitClusterNRechitChamberPlus12':  [bins,    0,  10, __, ],
            'cscRechitClusterNRechitChamberMinus12': [bins,    0,  10, __, ],
            'cscRechitCluster_match_RE12_0p4':       [bins,    0,  10, __, ],
            'cscRechitCluster_match_MB1Seg_0p4':     [bins,    0,  10, __, ],
            'cscRechitCluster_match_RB1_0p4':        [bins,    0,  10, __, ],
            'cscRechitClusterMuonVetoPt':            [bins,    0, 100, __, ],
            'cscRechitClusterTimeWeighted':          [bins,  -20,  20, __, ],
            'cscRechitClusterTimeSpreadWeightedAll': [bins,    0,  30, __, ],
            'cscRechitClusterEta':                   [bins,    0,   3, abs,],
            'cscRechitClusterSize':                  [bins,    50, 300, __, ],
            'cscRechitClusterNStation10':            [bins,    0,   5, __, ],
            'cscRechitClusterAvgStation10':          [bins,    0,   5, abs, ],
        }
        
        if 'background' in dataset: # this is explicitly to protect from unblinding data
            cscVars['cscRechitClusterSize'] = [int(bins/5),    50, 100, __, ]

        if signame in dataset:
            cscVars['cscRechitCluster_llp_deltaR']   = [bins, 0, 5, __,]
            cscVars['cscRechitCluster_llp_deltaEta'] = [bins, 0, 5, abs,]
            cscVars['cscRechitCluster_llp_deltaPhi'] = [bins, 0, 5, __,]

        cscVars['cscRechitCluster_leadmuon_deltaR']   = [bins, 0, 5, __,]
        cscVars['cscRechitCluster_leadmuon_deltaEta'] = [bins, 0, 5, abs,]
        cscVars['cscRechitCluster_leadmuon_deltaPhi'] = [bins, 0, 5, __,]
        
        #must be flat variables of length nEvents
        eventVars = {
            'metEENoise': [bins,   0, 100, __, ],
            'gLLP_ctau': [bins, 0, 1e3, __, ],
        }
        
        if signame in dataset:        
            eventVars['gLLP_decay_vertex_z'] = [2*bins,   0, 1200, abs, ]
            eventVars['gLLP_decay_vertex_z_matched'] = [2*bins,   0, 1200, abs, ]
            eventVars['gLLP_e'] = [bins,   0, 100, __, ]
            eventVars['gLLP_e_matched'] = [bins,   0, 100, __, ]
            
        Vars = cscVars | eventVars
        # <<< variables to be plotted <<<
        
        
        # >>> create hists >>> 
        bigCut = cscCuts[list(cscCuts.keys())[0]] #sets first cut
        for cut in cscCuts:
            out[f'{dataset}_cuts'][cut] = 1       
            bigCut = bigCut & cscCuts[cut]
            
            if bigCut.layout.minmax_depth == (2,2):
                temp = ak.any(bigCut, axis=1)
            elif bigCut.layout.minmax_depth == (1,1):
                temp = bigCut
                          
            out[dataset][f'numEvents_{cut}'] = sum(temp)
            
            for var in Vars:

                out[f'{dataset}_vars'][var] = 1  
                v = Vars[var]
                
                if bigCut.layout.minmax_depth == (2,2) and events[var].layout.minmax_depth == (1,1):
                    temp2 = ak.any(bigCut, axis=1)
                else:
                    temp2 = bigCut
                
                data = ak.flatten(events[var][temp2], axis=None)
                data = v[3](data)
                key = f'{var} with {cut}'
                
                if signame in dataset:
                    out[f'{dataset}_vars'][key] = data.to_list()
                    
                if 'gLLP_e' in var:
                    out[dataset][key] = hs.Hist.new.Reg(v[0], v[1]+1, v[2], name=var, label=var, transform=hs.axis.transform.log).Double()
                else:
                    out[dataset][key] = hs.Hist.new.Reg(v[0], v[1], v[2], name=var, label=var).Double()
                out[dataset][key].fill(data) 
        # <<< create hists <<<
        return out
    
    def postprocess(self, accumulator):
        return accumulator
    