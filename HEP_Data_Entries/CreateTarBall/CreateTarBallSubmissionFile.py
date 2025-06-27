import numpy as np
from hepdata_lib import Submission, Table, Variable, RootFileReader, Uncertainty
import ROOT as rt
import uproot
import os
import pdb
<<<<<<< HEAD
=======
import pandas as pd
>>>>>>> c00e0ff26dda8f9985561974e6dc88cfd7abcab0

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
<<<<<<< HEAD
    if hist.GetXaxis().GetBinLowEdge(i) < -60 or hist.GetXaxis().GetBinUpEdge(i) > 60: continue
=======
    if hist.GetXaxis().GetBinLowEdge(i) < -30 or hist.GetXaxis().GetBinUpEdge(i) > 30: continue
>>>>>>> c00e0ff26dda8f9985561974e6dc88cfd7abcab0
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
<<<<<<< HEAD
        if hist.GetXaxis().GetBinLowEdge(i) < -60 or hist.GetXaxis().GetBinUpEdge(i) > 60: continue
=======
        if hist.GetXaxis().GetBinLowEdge(i) < -30 or hist.GetXaxis().GetBinUpEdge(i) > 30: continue
>>>>>>> c00e0ff26dda8f9985561974e6dc88cfd7abcab0
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

<<<<<<< HEAD
=======
base = "../CutflowTables/"
mass = ["0p3", "0p5", "1p0", "2p0", "3p0"]
ctau = ["70", "100", "300", "700", "700"]
channel = ["PiPlusPiMinus", "Pi0Pi0"]
selections = ["Nocuts", "HLT", "nCscRechitClusters>0", "CscPassID"]
selections_names = ["All events", "Muon(trigger and > 7 GeV)", "CSC cluster > 0", "CSC cluster selections (vetos, | $\eta$ | and time)"]

# BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300.csv

pi0pi0_df_ratios     = [[1.00,0.0752,0.0054,0.0005], 
                        [1.00,0.0750,0.0057,0.0006], 
                        [1.00,0.0761,0.0061,0.0007]]

pipluspiminus_ratios = [[1.00,0.0748,0.0063,0.0008], 
                        [1.00,0.0754,0.0069,0.0009], 
                        [1.00,0.0754,0.0073,0.0010]]


pi0pi0_df_errors     = [[0.0,0.0001517780868,0.00003974548187,0.00001305377457],
                        [0.0,0.0001081607832,0.00002912450386,0.000009952361337],
                        [0.0,0.0001115185327,0.000030848887,0.00001122346313]]

pipluspiminus_errors = [[0.0,0.0001480775491,0.00004251317895,0.00001527795008],
                        [0.0,0.0001502502594,0.00004501478714,0.00001699086803],
                        [0.0,0.0001504787281,0.0000466316669,0.00001786720683]]
                        
pi0pi0_df_ratios     = [[1,8.57E-02,6.82E-03,6.58E-04],
                        [1,8.76E-02,7.06E-03,6.52E-04],
                        [1,8.33E-02,6.77E-03,6.24E-04],
                        [1,8.28E-02,6.90E-03,7.03E-04], 
                        [1,8.60E-02,7.49E-03,7.89E-04]]

pipluspiminus_ratios = [[1,8.53E-02,9.78E-03,1.13E-03],
                        [1,8.65E-02,1.03E-02,1.03E-03],
                        [1,8.34E-02,9.13E-03,1.07E-03],
                        [1,8.28E-02,9.32E-03,1.14E-03],
                        [1,8.59E-02,1.08E-02,1.27E-03]]

pi0pi0_df_errors     = [[0.0,3.76E-04,1.01E-04,3.09E-05],
                        [0.0,1.64E-04,4.38E-05,1.31E-05],
                        [0.0,2.31E-04,6.33E-05,1.89E-05],
                        [0.0,1.50E-04,4.16E-05,1.30E-05],
                        [0.0,1.84E-04,5.30E-05,1.68E-05]]

pipluspiminus_errors = [[0.0,3.76E-04,1.26E-04,4.18E-05],
                        [0.0,2.89E-04,9.60E-05,3.23E-05],
                        [0.0,8.64E-04,2.15E-04,2.52E-05],
                        [0.0,2.07E-04,6.98E-05,2.36E-05],
                        [0.0,2.51E-04,8.82E-05,2.85E-05]]

ratios = {"PiPlusPiMinus": pipluspiminus_ratios, "Pi0Pi0": pi0pi0_df_ratios}
errors = {"PiPlusPiMinus": pipluspiminus_errors, "Pi0Pi0": pi0pi0_df_errors}

for i in range(len(channel)):
    table = Table(f'Signal efficiency, {channel[i]} decay channel.')
    var = {}
    var_err = {}
    unc = {}
    x = []
    hist = reader.Get(branch["background"])
    var[0] = Variable(f'Selection step', is_independent = True, is_binned = False) 
    for j in range(len(mass)):
        # filename = f"{base}/weighted_cutflow_tables/BToKPhi_MuonLLPDecayGenFilter_PhiTo{channel[i]}_mPhi{mass[j]}_ctau{ctau[j]}_weighted.csv"
        # filename_err = f"{base}/not_weighted_cutflow_tables/BToKPhi_MuonLLPDecayGenFilter_PhiTo{channel[i]}_mPhi{mass[j]}_ctau{ctau[j]}_not_weighted_err.csv"
        # data = pd.read_csv(filename)
        # data_err = pd.read_csv(filename_err)
        data_err_sel = errors[channel[i]] # data_err[data["Selections"].isin(selections)]
        data_sel = ratios[channel[i]] # data[data["Selections"].isin(selections)]
        var[0].values = selections_names # data_sel["Selections"]
        # data_err_sel["Cum efficiency"].iloc[0] = 0.0
        var[f"MLLP = {mass[j]}"] = Variable(f'MLLP = {mass[j].replace("p", ".")} GeV', is_independent = False, is_binned = False)
        var_err[f"MLLP = {mass[j]}"] = Uncertainty("Statistical")
        var[f"MLLP = {mass[j]}"].values = data_sel[j] # ["Cum efficiency"]
        var_err[f"MLLP = {mass[j]}"].values = data_err_sel[j] # ["Cum efficiency"]
        var[f"MLLP = {mass[j]}"].add_uncertainty(var_err[f"MLLP = {mass[j]}"])
        if (j == 0): table.add_variable(var[0])
        table.add_variable(var[f"MLLP = {mass[j]}"])
    submission.add_table(table)

>>>>>>> c00e0ff26dda8f9985561974e6dc88cfd7abcab0
os.system("mkdir -p submission_file")
os.system('rm -rf submission_file')
submission.create_files('submission_file/')
