import numpy as np
from hepdata_lib import Submission, Table, Variable, RootFileReader, Uncertainty
import ROOT as rt
import uproot
import os
import pdb

submission = Submission()
base = "../ConvertCToRoot/roots"
files = os.listdir(base)
print(files)

files = {}
branch = {}
variable_label = "fig2_clsTime"
base = "../ConvertCToRoot/roots/"
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
    if hist.GetXaxis().GetBinLowEdge(i) < -60 or hist.GetXaxis().GetBinUpEdge(i) > 60: continue
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
        if hist.GetXaxis().GetBinLowEdge(i) < -60 or hist.GetXaxis().GetBinUpEdge(i) > 60: continue
        if b_i == 0:
            x_edges.append((hist.GetXaxis().GetBinLowEdge(i), hist.GetXaxis().GetBinUpEdge(i)))
        # y.append(hist.GetBinContent(i))
        if hist.GetBinContent(i) == 0:
            # pass
            y.append(-999)
            yerr.append(0.0)
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
base = "../ConvertCToRoot/roots/"
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
        y.append(hist.GetBinContent(i))
        # if hist.GetBinContent(i) == 0: continue
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
base = "../ConvertCToRoot/roots/"
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
            y.append(-999)
            yerr.append(0.0)
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
base = "../ConvertCToRoot/roots/"
variable_label = "fig5_DeltaclsMuonVSClsSize"
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

    table = Table(f'Figure 5')
    table.description=description
    table.location = f'Figure 5'
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
keys = ["data_0p3","data_1p0","data_2p0", "data_3p0"]
filename = "../ConvertCToRoot/roots/Limit_PiAll_WP23_GJson_unBlinded_lepIDSF_MAll_low_CSC.root"
# for f, filename in enumerate(["m0p3_limit.txt", "m1p0_limit.txt", "m2p0_limit.txt", "m3p0_limit.txt"]):

x = {}
data_obs = {}
data_median = {}
data_plus = {}
data_minus = {}

for l, label in enumerate(labels):
    table = Table(f"Figure 6 ({labels[l]})")
    table.description = "Exclusion limits at 95% CL on the $B \\rightarrow K \Phi$ as a function of the decay distance of the long-lived particle."
    table.location = "Figure 6"

    table.keywords["observables"] = ["CLS", "CLS"]
    table.keywords["cmenergies"] = ["13000"]
    
    file = uproot.open(filename)
    
    x[keys[l]] = []
    data_obs[keys[l]] = []
    data_median[keys[l]] = []
    data_plus[keys[l]] = []
    data_minus[keys[l]] = []
    print(file)
    hist_median = file.get(f"Graph{l*3}")
    hist_obs = file.get(f"Graph{l*3+2}")
    hist_errors = file.get(f"Graph{l*3+1}")
    nbins = len(hist_median.values()[0])
    nbins_errors = len(hist_errors.values()[0])
    print(len(hist_median.values()[0]), len(hist_obs.values()[0]), len(hist_errors.values()[0]))
    print(len(hist_median.values()[1]), len(hist_obs.values()[1]), len(hist_errors.values()[1]))
    print(hist_median.values()[1], hist_obs.values()[1])
    for i in range(1, nbins):
        x[keys[l]].append(hist_median.values()[0][i])
        data_obs[keys[l]].append(hist_obs.values()[1][i])
        data_median[keys[l]].append(hist_median.values()[1][i])
        data_plus[keys[l]].append(hist_errors.values()[1][i])
        data_minus[keys[l]].append(hist_errors.values()[1][nbins_errors-i])

    x_v = Variable("c$\\tau$", is_independent=True, is_binned=False, units="mm")
    x_v.values = x[keys[l]]

    expL = Variable("95% CL upper limit on $B \\rightarrow K \Phi$", is_independent=False, is_binned=False, units="")
    expL.values = data_median[keys[l]]
    expL.add_qualifier("SQRT(S)", 13, "TeV")
    expL.add_qualifier("Quantile", "Median expected limit")

    obsL = Variable("95% CL upper limit's observed value on $B \\rightarrow K \Phi$", is_independent=False, is_binned=False, units="")
    obsL.values = data_obs[keys[l]]
    obsL.add_qualifier("SQRT(S)", 13, "TeV")
    obsL.add_qualifier("Quantile", "Observed limit")

    OneS_p = Variable("95% CL upper limit's observed value -1$\sigma$ on $B \\rightarrow K \Phi$", is_independent=False, is_binned=False, units="")
    OneS_p.values = data_plus[keys[l]]
    OneS_p.add_qualifier("SQRT(S)", 13, "TeV")
    OneS_p.add_qualifier("Quantile", "-1 $\\sigma$")

    OneS_m = Variable("95% CL upper limit's observed value +1$\sigma$ on $B \\rightarrow K \Phi$", is_independent=False, is_binned=False, units="")
    OneS_m.values = data_minus[keys[l]]
    OneS_m.add_qualifier("SQRT(S)", 13, "TeV")
    OneS_m.add_qualifier("Quantile", "+1 $\\sigma$")

    table.add_variable(x_v)
    table.add_variable(expL)
    table.add_variable(obsL)
    table.add_variable(OneS_p)
    table.add_variable(OneS_m)
    submission.add_table(table)

files = {}
branch = {}
base = "../ConvertCToRoot/roots/"
variable_label = "fig7_limits_vs_ctau_mass"
files[variable_label] = "BToPhiK_AnalysisPiPlusPiMinus_2d_expected.root"
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

    table = Table(f'Figure 7')
    table.description=description
    table.location = f'Figure 7'
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

contour_location = "../../plotters/"
contour_files = [f"{contour_location}limit_vs_ctau_mass_0p01_contour.txt", f"{contour_location}limit_vs_ctau_mass_0p001_contour.txt"]
Table_titles = ["The contour of the limits for BR = 0.01", "The contour of the limits for BR = 0.001"]
descriptions = ["The contour of the 2D distribution which includes the generation parameter values corresponding to the BR of 0.01.", "The contour of the 2D distribution which includes the generation parameter values corresponding to the BR of 0.001."]
for c, f_c in enumerate(contour_files):
    with open(f_c, "r") as contour:
        table = Table(Table_titles[c])
        table.location = "Figure 7"
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

os.system("mkdir -p submission_file")
os.system('rm -rf submission_file')
submission.create_files('submission_file/')
