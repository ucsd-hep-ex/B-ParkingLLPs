import numpy as np
from hepdata_lib import Submission, Table, Variable, RootFileReader, Uncertainty
import ROOT as rt
import uproot
import os
import pdb
import pandas as pd

submission = Submission()
submission.read_abstract("abstract.txt")
base = "./roots"
files = os.listdir(base)
print(files)

files = {}
branch = {}
variable_label = "fig2_clsTime"
base = "./roots/"
files[variable_label] = "cscRechitClusterTime_nominal.root"
branch["background"] = "h_bkg__20"
branch[f"{variable_label}_pipluspiminus0p3_100"] = "h_sig__15"
branch[f"{variable_label}_pipluspiminus1p0_100"] = "h_sig__17"
branch[f"{variable_label}_pipluspiminus2p0_1000"] = "h_sig__19"
titles = ["Background-Enriched Data", "m = 0.3 GeV, c$\\tau_{\Phi}$ = 100 mm", "m = 1.0 GeV, c$\\tau_{\Phi}$ = 300 mm", "m = 2.0 GeV, c$\\tau_{\Phi}$ = 1000 mm"]
labels = ["background", "m0p3_ct100", "m1p0_ct300", "m2p0_ct1000"]
x_label = "t_{cluster}"
y_label = "a.u."

description = "Distributions of the CSC cluster time shown for signal samples with m = 0.3 GeV, c$\\tau_{\Phi}$ = 100 mm, m = 1.0 GeV, c$\\tau_{\Phi}$ = 300 mm, m = 2.0 GeV, c$\\tau_{\Phi}$ = 1000 mm and the background-enriched data."

filename = f"{base}{files[variable_label]}"
print(filename)
reader = rt.TFile(filename, 'READ')

table = Table(f'Figure 2')
table.description=description
table.location = f'Figure 2'
table.keywords["cmenergies"] = ["13000.0"]
table.keywords["observables"] = ["EFF"]
var = {}
unc = {}
x_edges = []
hist = reader.Get(branch["background"])
for i in range(1, hist.GetXaxis().GetNbins()+1):
    if hist.GetXaxis().GetBinLowEdge(i) < -30 or hist.GetXaxis().GetBinUpEdge(i) > 30: continue
    # if hist.GetBinContent(i) == 0: continue
    x_edges.append((hist.GetXaxis().GetBinLowEdge(i), hist.GetXaxis().GetBinUpEdge(i)))

var[0] = Variable(f'Cluster time', is_independent = True, is_binned = True, units = 'ns') 
var[0].values = x_edges

for b_i, (b_k, b) in enumerate(branch.items()):
    print(b_i, b_k, b)
    var[b_i+1] = Variable(f'Fraction of events: {titles[b_i]}', is_independent = False, is_binned = False, units = '') 
    y = []
    yerr = []
    hist = reader.Get(b)
    print(hist)
    for i in range(1, hist.GetXaxis().GetNbins()+1):
        if hist.GetXaxis().GetBinLowEdge(i) < -30 or hist.GetXaxis().GetBinUpEdge(i) > 30: continue
        if b_i == 0:
            x_edges.append((hist.GetXaxis().GetBinLowEdge(i), hist.GetXaxis().GetBinUpEdge(i)))
        # y.append(hist.GetBinContent(i))
        if hist.GetBinContent(i) == 0:
            # pass
            y.append('-')#-999)
            yerr.append(0)#1.0)
        else:
            # pass
            y.append(hist.GetBinContent(i))            
            yerr.append(hist.GetBinError(i))
    print(len(y), len(yerr))
    unc[b_i+1] = Uncertainty("Statistical")
    var[b_i+1].values = y
    unc[b_i+1].values = yerr
    var[b_i+1].add_uncertainty(unc[b_i+1])
    print(len(x_edges), len(y))

for k, v in var.items():
    table.add_variable(v)
submission.add_table(table)

files = {}
branch = {}
variable_label = "fig3_clsSize"
base = "./roots/"
files[variable_label] = "cscRechitClusterSize_nominal_log.root"
branch["background"] = "h_bkg__13"
branch[f"{variable_label}_pipluspiminus0p3_100"] = "h_sig__8"
branch[f"{variable_label}_pipluspiminus1p0_100"] = "h_sig__10"
branch[f"{variable_label}_pipluspiminus2p0_1000"] = "h_sig__12"
titles = ["Background-Enriched Data", "m = 0.3 GeV, c$\\tau_{\Phi}$ = 100 mm", "m = 1.0 GeV, c$\\tau_{\Phi}$ = 300 mm", "m = 2.0 GeV, c$\\tau_{\Phi}$ = 1000 mm"]
labels = ["background", "m0p3_ct100", "m1p0_ct300", "m2p0_ct1000"]
x_label = "Cluster size"
y_label = "a.u."

description = "Distributions of the CSC cluster size $N_{hits}$ shown for signal samples with m = 0.3 GeV, c$\\tau_{\Phi}$ = 100 mm, m = 1.0 GeV, c$\\tau_{\Phi}$ = 300 mm, m = 2.0 GeV, c$\\tau_{\Phi}$ = 1000 mm and the background-enriched data."

filename = f"{base}{files[variable_label]}"
print(filename)
reader = rt.TFile(filename, 'READ')

table = Table(f'Figure 3 (Cluster size)')
table.description=description
table.location = f'Figure 3'
table.keywords["cmenergies"] = ["13000.0"]
table.keywords["observables"] = ["EFF"]

var = {}
unc = {}
x_edges = []
hist = reader.Get(branch["background"])
for i in range(1, hist.GetXaxis().GetNbins()+1):
    if hist.GetXaxis().GetBinUpEdge(i) > 500: continue
    # if hist.GetBinContent(i) == 0: continue
    x_edges.append((hist.GetXaxis().GetBinLowEdge(i), hist.GetXaxis().GetBinUpEdge(i)))

var[0] = Variable(f'Cluster size', is_independent = True, is_binned = True, units = 'ns') 
var[0].values = x_edges

for b_i, (b_k, b) in enumerate(branch.items()):
    print(b_i, b_k, b)
    var[b_i+1] = Variable(f'Fraction of events: {titles[b_i]}', is_independent = False, is_binned = False, units = '') 
    y = []
    yerr = []
    hist = reader.Get(b)
    print(hist)
    for i in range(1, hist.GetXaxis().GetNbins()+1):
        if hist.GetXaxis().GetBinUpEdge(i) > 500: continue
        if b_i == 0:
            x_edges.append((hist.GetXaxis().GetBinLowEdge(i), hist.GetXaxis().GetBinUpEdge(i)))
        # y.append(hist.GetBinContent(i))
        # if hist.GetBinContent(i) == 0: continue
        # yerr.append(hist.GetBinError(i))
        if hist.GetBinContent(i) == 0:
            # pass
            y.append('-')#-999)
            yerr.append(0)#1.0)
        else:
            # pass
            y.append(hist.GetBinContent(i))
            yerr.append(hist.GetBinError(i))


    unc[b_i+1] = Uncertainty("Statistical")
    var[b_i+1].values = y
    unc[b_i+1].values = yerr
    var[b_i+1].add_uncertainty(unc[b_i+1])
    print(len(x_edges), len(y))

for k, v in var.items():
    table.add_variable(v)
submission.add_table(table)

files = {}
branch = {}
variable_label = "fig3_DeltaclsMuon"
base = "./roots/"
files[variable_label] = "cscRechitClusterDPhiLeadMuon_nominal_log.root"
branch["background"] = "h_bkg__6"
branch[f"{variable_label}_pipluspiminus0p3_100"] = "h_sig__1"
branch[f"{variable_label}_pipluspiminus1p0_100"] = "h_sig__3"
branch[f"{variable_label}_pipluspiminus2p0_1000"] = "h_sig__5"
titles = ["Background-Enriched Data", "m = 0.3 GeV, c$\\tau_{\Phi}$ = 100 mm", "m = 1.0 GeV, c$\\tau_{\Phi}$ = 300 mm", "m = 2.0 GeV, c$\\tau_{\Phi}$ = 1000 mm"]
labels = ["background", "m0p3_ct100", "m1p0_ct300", "m2p0_ct1000"]
x_label = "$\Delta\Phi(cluster, \\mu_{trigger})$"
y_label = "a.u."

description = "Distributions of the $\Delta\Phi$ between the CSC cluster and the trigger muon, shown for signal samples with m = 0.3 GeV c$\\tau_{\Phi}$ = 100 mm, m = 1.0 GeV c$\\tau_{\Phi}$ = 300 mm, m = 2.0 GeV c$\\tau_{\Phi}$ = 1000 mm and the background-enriched data."

filename = f"{base}{files[variable_label]}"
print(filename)
reader = rt.TFile(filename, 'READ')

table = Table('Figure 3 ($\Delta\Phi(cluster, \\mu_{trigger})$)')
table.description=description
table.location = f'Figure 3'
table.keywords["cmenergies"] = ["13000.0"]
table.keywords["observables"] = ["EFF"]

var = {}
unc = {}
x_edges = []
hist = reader.Get(branch["background"])
for i in range(1, hist.GetXaxis().GetNbins()+1):
    if hist.GetXaxis().GetBinLowEdge(i) < 0.9 or hist.GetXaxis().GetBinUpEdge(i) > 3.2: continue
    # if hist.GetBinContent(i) == 0: continue
    x_edges.append((hist.GetXaxis().GetBinLowEdge(i), hist.GetXaxis().GetBinUpEdge(i)))

var[0] = Variable("$\Delta\Phi$ (cluster, $\\mu_{trigger}$)", is_independent = True, is_binned = True, units = '') 
var[0].values = x_edges

for b_i, (b_k, b) in enumerate(branch.items()):
    print(b_i, b_k, b)
    var[b_i+1] = Variable(f'Fraction of events: {titles[b_i]}', is_independent = False, is_binned = False, units = '') 
    y = []
    yerr = []
    hist = reader.Get(b)
    print(hist)
    for i in range(1, hist.GetXaxis().GetNbins()+1):
        if hist.GetXaxis().GetBinLowEdge(i) < 0.9 or hist.GetXaxis().GetBinUpEdge(i) > 3.2: continue
        if b_i == 0:
            x_edges.append((hist.GetXaxis().GetBinLowEdge(i), hist.GetXaxis().GetBinUpEdge(i)))
        # y.append(hist.GetBinContent(i))
        # if hist.GetBinContent(i) == 0: continue
        # yerr.append(hist.GetBinError(i))
        if hist.GetBinContent(i) == 0:
            # pass
            y.append('-')#-999)
            yerr.append(0)#0.0)
        else:
            y.append(hist.GetBinContent(i))
            yerr.append(hist.GetBinError(i))

    unc[b_i+1] = Uncertainty("Statistical")
    var[b_i+1].values = y
    unc[b_i+1].values = yerr
    var[b_i+1].add_uncertainty(unc[b_i+1])
    print(len(x_edges), len(y))

for k, v in var.items():
    table.add_variable(v)
submission.add_table(table)

files = {}
branch = {}
base = "./roots/"
variable_label = "fig4_DeltaclsMuonVSClsSize"
files[variable_label] = "OOT_CLS_DPHI_CSC.root"
branch["background"] = "h1_swap"
titles = ["Background-Enriched Data"]
labels = ["background"]
x_label = "Number of hits"
y_label = "$\Delta\Phi$ (cluster, $\\mu_{trigger}$)"
z_label = "Fraction of events"

description = ""

filename = f"{base}{files[variable_label]}"
print(filename)
reader = rt.TFile(filename, 'READ')

for b_i, (b_k, b) in enumerate(branch.items()):
    print(b_i, b_k, b)

    table = Table(f'Figure 4')
    table.description=description
    table.location = f'Figure 4'
    table.keywords["cmenergies"] = ["13000.0"]
    table.keywords["observables"] = ["EFF"]
    table.description = "The 2D distribution of the $\Delta\Phi$ (cluster, $\\mu_{trigger}$) vs the number of hits in clusters, in events from the out-of-time region."

    var = {}
    unc = {}

    var[0] = Variable('$N_{hits}$', is_independent = True, is_binned = True, units = '') 
    var[1] = Variable('$\Delta\Phi$ (cluster, $\\mu_{trigger}$)', is_independent = True, is_binned = True, units = '') 
    var[2] = Variable('Fraction of events', is_independent = False, is_binned = False, units = '') 

    x_edges = []
    y_edges = []
    z = []
    zerr = []
    hist = reader.Get(b)
    print(hist)
    for i in range(1, hist.GetXaxis().GetNbins()+1):
        for j in range(1, hist.GetYaxis().GetNbins()+1):
            if (hist.GetBinContent(i, j) == 0.0 or hist.GetBinError(i, j) == 0.0): continue
            x_edges.append((hist.GetXaxis().GetBinLowEdge(i), hist.GetXaxis().GetBinUpEdge(i)))
            y_edges.append((hist.GetYaxis().GetBinLowEdge(j), hist.GetYaxis().GetBinUpEdge(j)))
            z.append(hist.GetBinContent(i, j))
            zerr.append(hist.GetBinError(i, j))

    unc[2] = Uncertainty("Statistical")
    print(len(x_edges), len(y_edges), len(z), len(zerr))
    var[0].values = x_edges
    var[1].values = y_edges
    var[2].values = z
    unc[2].values = zerr
    var[2].add_uncertainty(unc[2])
    for k, v in var.items():
        table.add_variable(v)
    submission.add_table(table)

labels = ["m = 0.3 GeV", "m = 1.0 GeV", "m = 2.0 GeV", "m = 3.0 GeV"]
keys = ["1dLimit_M0p3.txt","1dLimit_M1p0.txt","1dLimit_M2p0.txt", "1dLimit_M3p0.txt"]

for l, label in enumerate(labels): 
    table = Table(f"Figure 5 ({label})")
    table.description = "Exclusion limits at 95% CL on the $B \\rightarrow K \Phi$ as a function of the decay distance of the long-lived particle."
    table.location = "Figure 5"
    
    table.keywords["observables"] = ["CLS", "CLS"]
    table.keywords["cmenergies"] = ["13000"]
    
    data = np.loadtxt(f'txt_files/{keys[l]}', delimiter=',')
    ctau_values = data[:, 0]
    expL_values = data[:, 1]
    oneS_lower_values = data[:, 2]
    oneS_upper_values = data[:, 3]
    obsL_values = data[:, 4]
    
    ct = Variable("c$\\tau$", is_independent=True, is_binned=False, units="mm")
    ct.values = ctau_values
    
    expL = Variable("95% CL upper limit on $B \\rightarrow K \Phi$", is_independent=False, is_binned=False, units="")
    expL.values = expL_values
    expL.add_qualifier("SQRT(S)", 13, "TeV")
    expL.add_qualifier("Quantile", "Median expected limit")
    
    obsL = Variable("95% CL upper limit's observed value on $B \\rightarrow K \Phi$", is_independent=False, is_binned=False, units="")
    obsL.values = obsL_values
    obsL.add_qualifier("SQRT(S)", 13, "TeV")
    obsL.add_qualifier("Quantile", "Observed limit")
    
    OneS_p = Variable("95% CL upper limit's observed value -1$\sigma$ on $B \\rightarrow K \Phi$", is_independent=False, is_binned=False, units="")
    OneS_p.values = oneS_lower_values
    OneS_p.add_qualifier("SQRT(S)", 13, "TeV")
    OneS_p.add_qualifier("Quantile", "-1 $\\sigma$")
    
    OneS_m = Variable("95% CL upper limit's observed value +1$\sigma$ on $B \\rightarrow K \Phi$", is_independent=False, is_binned=False, units="")
    OneS_m.values = oneS_upper_values
    OneS_m.add_qualifier("SQRT(S)", 13, "TeV")
    OneS_m.add_qualifier("Quantile", "+1 $\\sigma$")
    
    table.add_variable(ct)
    table.add_variable(expL)
    table.add_variable(obsL)
    table.add_variable(OneS_p)
    table.add_variable(OneS_m)
    submission.add_table(table)

files = {}
branch = {}
base = "./roots/"
variable_label = "fig6_limits_vs_ctau_mass"
files[variable_label] = "PiPlusPiMinus_2d_expected.root"
branch["background"] = "unnamed"
titles = ["Background-Enriched Data"]
labels = ["background"]
x_label = "$m_{LLP}$"
y_label = "c $\\tau$"
z_label = "$\Phi$K $\\rightarrow$ 95% CL upper limit on BR(B)"

description = "The estimated BR limits for a range of generator parameters: $0.3 < m_{LLP}$ < 3.0 GeV and 0 < $c\\tau$ < 10000 mm." 

filename = f"{base}{files[variable_label]}"
print(filename)
reader = rt.TFile(filename, 'READ')

for b_i, (b_k, b) in enumerate(branch.items()):
    print(b_i, b_k, b)

    table = Table(f'Figure 6')
    table.description=description
    table.location = f'Figure 6'
    table.keywords["cmenergies"] = ["13000.0"]
    table.keywords["observables"] = ["EFF"]

    var = {}
    unc = {}
    # var[0] = Variable('N_{hits}', is_independent = True, is_binned = True, units = '') 
    # var[1] = Variable('Φ proper decay length [mm]', is_independent = True, is_binned = True, units = '') 
    # var[2] = Variable('ΦK→95 % CL Upper Limit on BR(B)', is_independent = False, is_binned = False, units = '') 

    var[0] = Variable('$m_{LLP}$', is_independent = True, is_binned = True, units = 'GeV') 
    var[1] = Variable('c$\\tau$', is_independent = True, is_binned = True, units = 'mm') 
    var[2] = Variable('$\Phi$K $\\rightarrow$ 95% CL Upper Limit on BR(B)', is_independent = False, is_binned = False, units = '') 

    x_edges = []
    y_edges = []
    z = []
    zerr = []
    hist = reader.Get(b)
    hist.RebinX(100)
    hist.RebinY(100)
    print(hist)
    for i in range(1, hist.GetXaxis().GetNbins()+1):
        for j in range(1, hist.GetYaxis().GetNbins()+1):
            # if (hist.GetBinContent(i, j) == 0.0 or hist.GetBinError(i, j) == 0.0 or hist.GetBinContent(i, j) > 1.0): continue
            x_edges.append((hist.GetXaxis().GetBinLowEdge(i), hist.GetXaxis().GetBinUpEdge(i)))
            y_edges.append((hist.GetYaxis().GetBinLowEdge(j), hist.GetYaxis().GetBinUpEdge(j)))
            z.append(hist.GetBinContent(i, j))
            zerr.append(hist.GetBinError(i, j))

    unc[2] = Uncertainty("Statistical")
    print(len(x_edges), len(y_edges), len(z), len(zerr))
    var[0].values = x_edges
    var[1].values = y_edges
    var[2].values = z
    for k, v in var.items():
        table.add_variable(v)
    submission.add_table(table)

contour_location = "./2D_limit_plot_test/"
contour_files = [f"{contour_location}limit_vs_ctau_mass_0p01_contour.txt", f"{contour_location}limit_vs_ctau_mass_0p001_contour.txt"]
Table_titles = ["The contour of the limits for BR = 0.01", "The contour of the limits for BR = 0.001"]
descriptions = ["The contour of the 2D distribution which includes the generation parameter values corresponding to the BR of 0.01.", "The contour of the 2D distribution which includes the generation parameter values corresponding to the BR of 0.001."]
for c, f_c in enumerate(contour_files):
    with open(f_c, "r") as contour:
        table = Table(Table_titles[c])
        table.location = "Figure 6"
        table.description = descriptions[c]
        ctau = Variable("$c\\tau$", is_independent=True, is_binned=False, units="mm")
        llp_mass = Variable("$m_{LLP}$", is_independent=False, is_binned=False, units = "GeV")
        x = []
        y = []
        for l in contour.readlines():
            x.append(float(l.split(" ")[0]))
            y.append(float(l.split(" ")[1]))
        ctau.values = x
        llp_mass.values = y
        table.add_variable(ctau)
        table.add_variable(llp_mass)
        submission.add_table(table)

base = "../CutflowTables/"
#mass = ["0p3", "0p5", "1p0", "2p0", "3p0"]
mass = ["0p3","0p5","1p0", "2p0", "3p0"]
ctau = ["70", "100", "300", "700", "700"]
channel = ["PiPlusPiMinus", "Pi0Pi0"]
channel2 = ["hadronic shower", "electromagnetic shower"]
selections_names = ["All events", "Muon(trigger, ID, selections)", "CSC cluster > 0", "CSC cluster selections (vetos, | $\eta$ | and time)", r"Signal Region ($N_{\mathrm{rechits}}$ > 310 and $\Delta\phi(\mathrm{cluster},\ \mu_{\mathrm{lead}})$ < 2.1)"]
names= [
    "All Events","Muon Present","Pass Trigger and Muon selections",
    "Number of CSC clusters > 0","Number of Hits in CSC clusters > 50",
    "Cluster does not overlap with a muon ($\Delta$R>0.4)","passOverlapGen",
    "Pass ME11/12 Veto","Pass MB1 Veto","Pass RB1 Veto","Pass RE12 Veto","Pass Muon Veto",
    "Pass Cluster Time selection","Pass Cluster Time Spread selection",
    "Cluster $\abs{\eta}$ <1.9","Pass Cut-based ID selection", "Pass all selections"
]
#names[i=0] = All events
#names[i=1] = Muon Present
#names[i=2] = Pass Trigger and Muon Selections
#names[i=3] = N CSC Clusters >0
#names[i=15] = Pass all cluster-level selections before NHits and dPhi
#names[i=16] = Pass all selections
indices_to_keep = [0, 2, 3, 15, 16]

M0p5_Pi0Pi0 = [1, 0.933, 0.0816, 0.00657, 0.00443, 0.00402, 0.00326, 0.00182, 0.00182, 0.00181, 0.00179, 0.00178, 0.00178, 0.00174, 0.000798, 0.000607, 3.54e-08 ]
M0p5_errUp_Pi0Pi0 = [0, 0.000173, 0.000141, 4.05e-05, 3.38e-05, 3.2e-05, 2.92e-05, 2.16e-05, 2.16e-05, 2.16e-05, 2.15e-05, 2.14e-05, 2.14e-05, 2.12e-05, 1.39e-05, 1.22e-05, 2.5e-08 ]
M0p5_errDn_Pi0Pi0 = [0, 0.000173, 0.000141, 4.05e-05, 3.38e-05, 3.2e-05, 2.92e-05, 2.16e-05, 2.16e-05, 2.16e-05, 2.15e-05, 2.14e-05, 2.14e-05, 2.12e-05, 1.39e-05, 1.22e-05, 2.5e-08 ]

M1p0_Pi0Pi0 = [1, 0.934, 0.0776, 0.0063, 0.00417, 0.00379, 0.00306, 0.00172, 0.00172, 0.00171, 0.00169, 0.00169, 0.00168, 0.00164, 0.000779, 0.000581, 2.1e-06 ]
M1p0_errUp_Pi0Pi0 = [0, 0.00025, 0.000199, 5.86e-05, 4.83e-05, 4.6e-05, 4.17e-05, 3.12e-05, 3.11e-05, 3.1e-05, 3.09e-05, 3.08e-05, 3.08e-05, 3.05e-05, 2.05e-05, 1.76e-05, 1.67e-06 ]
M1p0_errDn_Pi0Pi0 = [0, 0.00025, 0.000199, 5.86e-05, 4.83e-05, 4.6e-05, 4.17e-05, 3.12e-05, 3.11e-05, 3.1e-05, 3.09e-05, 3.08e-05, 3.08e-05, 3.05e-05, 2.05e-05, 1.76e-05, 1.67e-06 ]

M0p3_PiPlusPiMinus = [1, 0.933, 0.0794, 0.0091, 0.00665, 0.00613, 0.00538, 0.00303, 0.00297, 0.00294, 0.00291, 0.00283, 0.00283, 0.0027, 0.00135, 0.00105, 3.07e-05 ]
M0p3_errUp_PiPlusPiMinus = [0, 0.000399, 0.000324, 0.000116, 0.000101, 9.72e-05, 9.21e-05, 6.7e-05, 6.62e-05, 6.59e-05, 6.55e-05, 6.44e-05, 6.43e-05, 6.29e-05, 4.41e-05, 3.89e-05, 1.01e-05 ]
M0p3_errDn_PiPlusPiMinus = [0, 0.000399, 0.000324, 0.000116, 0.000101, 9.72e-05, 9.21e-05, 6.7e-05, 6.62e-05, 6.59e-05, 6.55e-05, 6.44e-05, 6.43e-05, 6.29e-05, 4.41e-05, 3.89e-05, 1.01e-05 ]

M0p5_PiPlusPiMinus = [1, 0.933, 0.0805, 0.00958, 0.00704, 0.0065, 0.00575, 0.0031, 0.00302, 0.00299, 0.00296, 0.00289, 0.00288, 0.00279, 0.00126, 0.000956, 1.94e-05 ]
M0p5_errUp_PiPlusPiMinus = [0, 0.000308, 0.000251, 9.32e-05, 8.21e-05, 7.87e-05, 7.49e-05, 5.27e-05, 5.17e-05, 5.15e-05, 5.13e-05, 5.07e-05, 5.07e-05, 4.98e-05, 3.22e-05, 2.75e-05, 5.84e-06 ]
M0p5_errDn_PiPlusPiMinus = [0, 0.000308, 0.000251, 9.32e-05, 8.21e-05, 7.87e-05, 7.49e-05, 5.27e-05, 5.17e-05, 5.15e-05, 5.13e-05, 5.07e-05, 5.07e-05, 4.98e-05, 3.22e-05, 2.75e-05, 5.84e-06 ]

M1p0_PiPlusPiMinus = [1, 0.934, 0.0776, 0.0085, 0.00608, 0.00559, 0.00491, 0.00286, 0.00281, 0.00278, 0.00275, 0.00268, 0.00268, 0.00258, 0.00129, 0.000994, 1.31e-05 ]
M1p0_errUp_PiPlusPiMinus = [0, 0.000245, 0.000196, 6.92e-05, 6.01e-05, 5.75e-05, 5.48e-05, 4.08e-05, 4.04e-05, 4.02e-05, 4e-05, 3.95e-05, 3.94e-05, 3.87e-05, 2.69e-05, 2.35e-05, 3.4e-06 ]
M1p0_errDn_PiPlusPiMinus = [0, 0.000245, 0.000196, 6.92e-05, 6.01e-05, 5.75e-05, 5.48e-05, 4.08e-05, 4.04e-05, 4.02e-05, 4e-05, 3.95e-05, 3.94e-05, 3.87e-05, 2.69e-05, 2.35e-05, 3.4e-06 ]

M2p0_PiPlusPiMinus = [1, 0.934, 0.0703, 0.00639, 0.00419, 0.00384, 0.00317, 0.00202, 0.00198, 0.00196, 0.00194, 0.0019, 0.0019, 0.00183, 0.00103, 0.000841, 5.58e-06 ]
M2p0_errUp_PiPlusPiMinus = [0, 0.000175, 0.000131, 4.01e-05, 3.27e-05, 3.13e-05, 2.86e-05, 2.29e-05, 2.27e-05, 2.26e-05, 2.25e-05, 2.22e-05, 2.22e-05, 2.19e-05, 1.65e-05, 1.49e-05, 1.28e-06 ]
M2p0_errDn_PiPlusPiMinus = [0, 0.000175, 0.000131, 4.01e-05, 3.27e-05, 3.13e-05, 2.86e-05, 2.29e-05, 2.27e-05, 2.26e-05, 2.25e-05, 2.22e-05, 2.22e-05, 2.19e-05, 1.65e-05, 1.49e-05, 1.28e-06 ]

M2p0_PiPlusPiMinus = [1, 0.933, 0.0771, 0.00868, 0.00613, 0.00565, 0.00492, 0.00286, 0.0028, 0.00277, 0.00274, 0.00269, 0.00268, 0.0026, 0.00133, 0.00106, 1.32e-05 ]
M2p0_errUp_PiPlusPiMinus = [0, 0.000226, 0.000179, 6.44e-05, 5.53e-05, 5.3e-05, 5.01e-05, 3.71e-05, 3.66e-05, 3.64e-05, 3.62e-05, 3.58e-05, 3.58e-05, 3.52e-05, 2.46e-05, 2.19e-05, 3.12e-06 ]
M2p0_errDn_PiPlusPiMinus = [0, 0.000226, 0.000179, 6.44e-05, 5.53e-05, 5.3e-05, 5.01e-05, 3.71e-05, 3.66e-05, 3.64e-05, 3.62e-05, 3.58e-05, 3.58e-05, 3.52e-05, 2.46e-05, 2.19e-05, 3.12e-06 ]

M3p0_PiPlusPiMinus = [1, 0.933, 0.0799, 0.01, 0.00739, 0.00683, 0.00609, 0.00343, 0.00334, 0.0033, 0.00325, 0.00318, 0.00318, 0.00308, 0.00152, 0.00118, 2.51e-05 ]
M3p0_errUp_PiPlusPiMinus = [0, 0.000266, 0.000215, 8.12e-05, 7.13e-05, 6.86e-05, 6.53e-05, 4.73e-05, 4.65e-05, 4.62e-05, 4.58e-05, 4.53e-05, 4.52e-05, 4.47e-05, 3.03e-05, 2.65e-05, 5.32e-06 ]
M3p0_errDn_PiPlusPiMinus = [0, 0.000266, 0.000215, 8.12e-05, 7.13e-05, 6.86e-05, 6.53e-05, 4.73e-05, 4.65e-05, 4.62e-05, 4.58e-05, 4.53e-05, 4.52e-05, 4.47e-05, 3.03e-05, 2.65e-05, 5.32e-06 ]


for i in range(len(channel)):
    table = Table(f'Signal efficiency: {channel2[i]} decay mode')
    table.description=f"Signal cut-flow efficiencies for the {channel2[i]} decay mode"
    table.location =f"{channel2[i]} decay mode efficiencies" 
    table.keywords["cmenergies"] = ["13000.0"]
    table.keywords["observables"] = ["EFF"]
    var = {}
    var_err = {}
    unc = {}
    x = []
    var[0] = Variable(f'Selection step', is_independent = True, is_binned = False) 
    table.add_variable(var[0])
    for j in range(len(mass)):
        if channel[i] == "Pi0Pi0" and mass[j] == "0p3":
             continue
        if channel[i] == "Pi0Pi0" and mass[j] == "2p0":
             continue
        if channel[i] == "Pi0Pi0" and mass[j] == "3p0":
             continue
        var[0].values = selections_names #[names[k] for k in indices_to_keep]

        var[f"MLLP = {mass[j]}"] = Variable(f'MLLP = {mass[j].replace("p", ".")} GeV', is_independent = False, is_binned = False)
        var_err[f"MLLP = {mass[j]}"] = Uncertainty("Statistical")

        varname = f"M{mass[j]}_{channel[i]}"
        varname_err = f"M{mass[j]}_errUp_{channel[i]}"
        
        full_var = globals().get(varname) 
        full_err = globals().get(varname_err) 

        var[f"MLLP = {mass[j]}"].values     = [full_var[k] for k in indices_to_keep]
        var_err[f"MLLP = {mass[j]}"].values = [full_err[k] for k in indices_to_keep]
        var[f"MLLP = {mass[j]}"].add_uncertainty(var_err[f"MLLP = {mass[j]}"])
        #f (j == 0): table.add_variable(var[0])
        table.add_variable(var[f"MLLP = {mass[j]}"])
    submission.add_table(table)

os.system("mkdir -p submission_file")
os.system('rm -rf submission_file')
submission.create_files('submission_file/')
