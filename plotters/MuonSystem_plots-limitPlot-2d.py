# limit for 2 tag
import ROOT as rt
import math
import root_numpy as rtnp
import csv
import re
import sys
import collections
import os
from collections import OrderedDict
import uproot
# import pandas as pd

import scipy
# import awkward
import numpy as np
import time
from lib.histo_utilities import create_TH1D, create_TH2D, std_color_list, create_TGraph, make_ratio_plot
from lib.limit_plots import *
import lib.CMS_lumi as CMS_lumi
import lib.tdrstyle as tdrstyle
import os
import importlib

tdrstyle.setTDRStyle()

print(sys.version)

limitTrees =OrderedDict()
dataCards = OrderedDict()

limitTrees_obs =OrderedDict()
dataCards_obs = OrderedDict()

decay = 'PiPlusPiMinus'

samples_pipluspiminus = [
    'SigPiPlusPiMinus_M0p3',
    'SigPiPlusPiMinus_M0p5',
    'SigPiPlusPiMinus_M1p0',
    'SigPiPlusPiMinus_M2p0',
    'SigPiPlusPiMinus_M3p0',
]

samples = [
    'Sig_M0p3',
    'Sig_M0p5',
    'Sig_M1p0',
    'Sig_M2p0',
    'Sig_M3p0',
]

# base = f"/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/Stats/CMSSW_10_2_13/src/ABCD/Lim_WP23_GJson_{unblind}_lepIDSF_IT"
# base = f"./Lim_WP23_GJson_{unblind}_lepIDSF_IT"

base = "/eos/user/d/ddiaz/forAram"
base_old = "/eos/user/d/ddiaz/forAram"
# base_old = "/eos/user/a/arhayrap/test"

limitDir_old = f'{base_old}/Lim_WP23_GJson_unBlinded_lepIDSF_moreStats1_IT--beforePi0'
dataCardDir_old = f'{base_old}/Lim_WP23_GJson_unBlinded_lepIDSF_moreStats1_IT--beforePi0'

# limitDir_old = f'{base_old}/Lim_WP23_GJson_unBlinded_lepIDSF_moreStats1_1_IT'
# dataCardDir_old = f'{base_old}/Lim_WP23_GJson_unBlinded_lepIDSF_moreStats1_1_IT'

limitDir = f'{base}/Lim_WP23_GJson_unBlinded_lepIDSF_moreStats1_IT'
dataCardDir = f'{base}/Lim_WP23_GJson_unBlinded_lepIDSF_moreStats1_IT'

lumi = 137000
nCsc = 100
nDt = 80

ctaus = np.array([3,5,10,30,50,70,100,300,500,700,1000,3000,5000,10000])
category = "csc"

# mass = ['0p3', '0p5', '1p0', '2p0', '3p0']
# expected = ['0.025', '0.160','0.500','0.840','0.975']

for i_m, m in enumerate(samples):
    limitTrees[m] = {}
    dataCards[m] = {}
    for ct in ctaus:
        ct_str = str(ct).replace('.','p')
        if ct == int(ct):ct_str = str(int(ct)).replace('.','p')
        else: ct_str      = str(ct).replace('.','p')
        if ("0p3" in m) or ("1p0" in m):
            dataCardLocation  = dataCardDir + '/'+m+'_low_ctau'+ct_str+'/'+samples_pipluspiminus[i_m]+'_low_ctau'+ct_str+"/"+ category.upper() + '/card.txt'
            print(dataCardLocation)
            limitTreeLocation =    limitDir + '/'+m+'_low_ctau'+ct_str+'/'+samples_pipluspiminus[i_m]+'_low_ctau'+ct_str+"/"+ category.upper() + '/higgsCombineTest.AsymptoticLimits.mH120.root'
            dataCards[m][ct]  = dataCardLocation
            limitTrees[m][ct] = limitTreeLocation
        else:
            dataCardLocation  = dataCardDir + '/'+m+'_low_ctau'+ct_str+'/'+ category.upper() + '/card.txt'
            print(dataCardLocation)
            limitTreeLocation =    limitDir + '/'+m+'_low_ctau'+ct_str+'/'+ category.upper() + '/higgsCombineTest.AsymptoticLimits.mH120.root'
            dataCards[m][ct]  = dataCardLocation
            limitTrees[m][ct] = limitTreeLocation
print(len(limitTrees))
limits = {}
for i,m in enumerate(limitTrees.keys()):

    limits[m] = np.ones((len(ctaus), 6))*1000000
    for j, k in enumerate(limitTrees[m].keys()):
        try:
            line = open(dataCards[m][k], "r").readline()
            line = float(line.split("#SF: ")[1]) # 1.88423E-06
            if len(uproot.open(limitTrees[m][k]).keys()) == 2:
                T = uproot.open(limitTrees[m][k])['limit']['limit'].array()
                limits[m][j] = np.array(T)*line
        except:
            ct_str = str(ctaus[j]).replace('.','p')
            dataCardLocation_old  = dataCardDir_old + '/' +samples_pipluspiminus[i]+'_low_ctau'+ct_str+"/"+ category.upper() + '/card.txt'
            limitTreeLocation_old =    limitDir_old + '/' +samples_pipluspiminus[i]+'_low_ctau'+ct_str+"/"+ category.upper() + '/higgsCombineTest.AsymptoticLimits.mH120.root'
            print(f"Card not found: {dataCardLocation}. Using the old path: {dataCardLocation_old}.")
            try:
                line = open(dataCardLocation_old, "r").readline()
                line = float(line.split("#SF: ")[1]) # 1.88423E-06
                if len(uproot.open(limitTreeLocation_old).keys()) == 2:
                    T = uproot.open(limitTreeLocation_old)['limit']['limit'].array()
                    limits[m][j] = np.array(T)*line
            except:
                print("The old path didn't work as well.")

    limits[m] = np.array(limits[m])

print(ctaus)
# print(limits)

importlib.reload(sys.modules['lib.CMS_lumi'])

decays =['PiPlusPiMinus']

opac_1sig = 0.25
opac_2sig = 0.1

for decay in decays:
    # leg = rt.TLegend(0.2,0.15,0.5,0.32)
    leg = rt.TLegend(0.4,0.15,0.7,0.32)
    leg.SetFillStyle(0)
    leg.SetTextSize(0.03)
    leg.SetBorderSize(0)
    rt.gStyle.SetLegendFillColor(1)
    leg.SetEntrySeparation(0.01)
#     leg2.SetTextSize(0.032)
#     leg2.SetBorderSize(0)
#     leg2.SetEntrySeparation(0.01)
    c = rt.TCanvas('c','c', 1000, 800)
    c.SetRightMargin(0.04)

    rt.gStyle.SetOptFit(1011)
    ctaus_m = ctaus
    h = create_TH2D(np.column_stack((np.array(0), np.array(0))), axis_title = ['LLP mass [GeV]','log10(c#tau)',''], binning = [100,0,30,300,-4,1])
    sample_temp = []
    m_sample = []
    x = array('d',[])
    y = array('d',[])
    z = array('d',[])
    for m in samples:
        m_sample.append(float(m[m.find('_M')+2:].replace('p','.')))
        sample_temp.append(m)
    
    max_mass = 3 
    min_mass = 0.3 

    h = create_TH2D(np.column_stack((np.array(0), np.array(0))), axis_title = ['LLP mass [GeV]','c#tau [mm]','95% CL upper limit on BR(B#rightarrow K#Phi)'], \
                    binning = [80,math.log10(min_mass),math.log10(max_mass),80,0.5,4])

    for m in m_sample:
        m = float(m)
        use_m_s = 0.0
        if m > np.max(m_sample): 
            use_m_s = np.max(m_sample)
            index   = np.argmax(m_sample)
        else:
            for i, m_s in enumerate(m_sample):
                if m <= m_s:
                    use_m_s = m_s
                    index = i
                    break
        cond = limits[sample_temp[index]][:,2] > 0 # < 10000

        # if decay == 'Pi0Pi0'       : cond = np.logical_and(cond, np.logical_not(ctaus_m==0.125))
        # if decay == 'PiPlusPiMinus': cond = np.logical_and(cond, np.logical_not(ctaus_m==0.002))
        
        for j in range(len(ctaus_m[cond])):
            if ctaus_m[cond][j] == 0.0:continue
            x.append(math.log10(float(m)))
            y.append(math.log10(ctaus_m[cond][j]))
            z.append(math.log10(limits[sample_temp[index]][:,2][cond][j]))
            print()
            print(m)
            h.SetBinContent(h.GetXaxis().FindBin(math.log10(float(m))), h.GetYaxis().FindBin(math.log10(ctaus_m[cond][j])), limits[sample_temp[index]][:,2][cond][j])

    h = interpolate2D(x,y,z, h, 0.2, 1.0)
    tdrstyle.setTDRStyle()

    #############
    # plot contour
    #############

    contours = array('d',[0.001, 0.01])
    hframed = frameTH2D(h)
    hframed = h.Clone()

    hframed = log_scale_conversion(hframed)
    hframed.SetContour(len(contours),contours)
    hframed.SetMaximum(1)
    hframed.SetMinimum(0.0001)
    hframed.Draw("CONT Z LIST")

    rt.gPad.Update()

    h = log_scale_conversion(h)
    # plt.hist(h, bins = 100)
    # plt.show()
    h.SetMinimum(1e-5)
    h.SetMaximum(1.0)
    h.GetXaxis().SetMoreLogLabels()
    h.GetXaxis().SetNoExponent()
    h.GetXaxis().SetTitleSize(0.035)
    h.GetYaxis().SetTitleSize(0.035)
    h.GetZaxis().SetTitleSize(0.035)
    h.GetXaxis().SetLabelSize(0.035)
    h.GetYaxis().SetLabelSize(0.035)
    h.GetZaxis().SetLabelSize(0.035)
    h.GetXaxis().SetTitleOffset(1.5)
    h.GetYaxis().SetTitleOffset(1.5)
    h.GetZaxis().SetTitleOffset(1.5)
    h.Draw('colz')
    
    conts = rt.gROOT.GetListOfSpecials().FindObject("contours")
    cont_gr = []
    for i in range(conts.GetSize()):
        print(i)
        contour0 = conts.At(i)
        curv = contour0.First()
        for i in range(contour0.GetSize()):
            for j in range(contour0[i].GetN()):
                print(contour0[i].GetPointX(j), contour0[i].GetPointY(j))
            print()
        finalcurv = rt.TGraph(1)
        try:
            curv.SetLineWidth(3)
            curv.SetLineColor(std_color_list[0])
            curv.SetLineStyle(std_color_list[i])
            curv.Draw("lsame")
            finalcurv = curv.Clone()
            maxN = curv.GetN()
            # print(maxN)
            print(contour0.GetSize())
            print()
            for j in range(1, contour0.GetSize()):
                print(j)
                curv = contour0.After(curv)
                curv.SetLineWidth(3)
                curv.SetLineColor(rt.kBlack)
                curv.SetLineStyle(std_color_list[i])
                curv.Draw("lsame")
                if curv.GetN()>maxN:
                    maxN = curv.GetN()
                    finalcurv = curv.Clone()
            cont_gr.append(finalcurv)
        except AttributeError:
            print ("ERROR: no curve drawn for contour %s "%(i))
    for idex in range(len(cont_gr)):
        i = len(cont_gr)-idex-1
        leg.AddEntry(cont_gr[i],'BR(B#rightarrow K#Phi) = '+str(contours[len(contours)-idex-1]), 'L')
        finalcurv.Draw('lsame')

    latex = rt.TLatex()
    latex.SetTextSize(0.05)
    latex.SetTextFont(42)

    # if decay   == 'Pi0Pi0'       : latex.DrawLatex(max_mass/3,0.00007, "LLP #rightarrow #pi^{0}#pi^{0}")
    # elif decay == 'PiPlusPiMinus': latex.DrawLatex(max_mass/3,0.00007, "LLP #rightarrow #pi^{+}#pi^{-}")
    
    leg.Draw()
    
    c.SetRightMargin(0.3)
    c.SetLogz()
    c.SetLogx()
    c.SetLogy()
    c.Draw()
    
    output_dir_name = "2D_limit_plot"
    output_dir = f"{os.getcwd()}/plotDump/{output_dir_name}"
    os.system(f"mkdir -p {output_dir}")
    
    if not os.path.isdir(output_dir):os.makedirs(output_dir)
    name = output_dir + decay

    c.SaveAs(name+'_2d_expected.png')
    c.SaveAs(name+'_2d_expected.C')
    c.SaveAs(name+'_2d_expected.pdf')

#     tdrstyle.setTDRStyle()

