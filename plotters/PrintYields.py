import ROOT as rt
import argparse
import pandas as pd
import mplhep as hep
import matplotlib.pyplot as plt
import cmsstyle as CMS

base = "/eos/user/d/ddiaz/forAram/"
base = "/eos/user/a/arhayrap/"
plt.style.use(hep.style.CMS)
extraText   = "";
color = rt.TColor.GetColor("#ff3300")
lumiText = "41.6 fb^{-1} (13 TeV)";

def custom_drawCMSLabel(pad=None, text="CMS", xpos=0.15, ypos=0.94, size=0.06, bold=False):
    latex = rt.TLatex()
    latex.SetNDC()
    if (bold): latex.SetTextFont(62)
    else: latex.SetTextFont(42)
    latex.SetTextSize(size)
    latex.DrawLatex(xpos, ypos, text)

def swap_histogram_axis(h1):
    nbinx = h1.GetNbinsX()
    nbiny = h1.GetNbinsY()
    x1 = h1.GetXaxis().GetBinLowEdge(1)
    x2 = h1.GetXaxis().GetBinLowEdge(nbinx)+h1.GetXaxis().GetBinWidth(nbinx)
    y1 = h1.GetYaxis().GetBinLowEdge(1)
    y2 = h1.GetYaxis().GetBinLowEdge(nbiny)+h1.GetYaxis().GetBinWidth(nbiny)

    h2 = rt.TH2F("h1_swap","h1_swap",nbiny,y1,y2,nbinx,x1,x2)
    c = rt.TCanvas("c_swap")
    for i in range(nbinx): 
        for j in range(nbiny): 
            c = h1.GetBinContent(i,j)
            h2.SetBinContent(j,i,c)
    h2.GetYaxis().SetRangeUser(1, 3.2);
    return h2

def AddCMS( C ):
    C.cd()
    C.SetTopMargin(0.12)
    lumix = 0.45
    lumiy = 0.91
    lumifont = 42
    cmsx = 0.00
    cmsy = 0.91
    cmsTextFont = 61
    extrax = cmsx + 0.15
    extray = cmsy
    extraTextFont = 52
    extraOverCmsTextSize  = 0.76
    cmsSize = 0.06
    latex = rt.TLatex()
    latex.SetNDC()
    latex.SetTextAngle(0)
    latex.SetTextColor(1)
    extraTextSize = extraOverCmsTextSize*cmsSize
    latex.SetTextFont(lumifont)
    latex.SetTextAlign(31)
    latex.SetTextSize(cmsSize)
    latex.DrawLatex(lumix, lumiy,lumiText)

    latex.SetTextFont(cmsTextFont)
    latex.SetTextAlign(31)
    latex.SetTextSize(cmsSize)
    latex.DrawLatex(cmsx, cmsy, "CMS")
  
    latex.SetTextFont(extraTextFont)
    latex.SetTextAlign(31)
    latex.SetTextSize(extraTextSize)
    latex.DrawLatex(extrax, extray, extraText)
    return True

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Print the signal yields")
    parser.add_argument("--Project", action = "store")
    parser.add_argument("--SignalName", action = "store")
    args = parser.parse_args()
    hep.cms.label()
    
    f = rt.TFile((f"{base}ParkingBPH_2018_OPT.root")) # with muon veto
    
    hists = [f.Get("IT_yields"), f.Get("OOT_yields")]
    labels = ["IT", "OOT"]
    regions = ["All", "A", "B", "C", "D", "Pred_bkg"]
    output_array = []
    for l in range(len(labels)):
        A = hists[l].GetBinContent(1)
        B = hists[l].GetBinContent(2)
        C = hists[l].GetBinContent(3)
        D = hists[l].GetBinContent(4)
        ALL = hists[l].GetBinContent(5)
        pred_bkg = C * B / D
        output_array.append([ALL, A, B, C, D, pred_bkg])
    output_df = pd.DataFrame(data=output_array, columns = regions, index = labels)
    print(output_df)
    output_df.to_csv(f"./yields/{args.SignalName}.csv")
    
    rt.gStyle.SetNumberContours(100)
    rt.gStyle.SetLineWidth(3)
    rt.gStyle.SetOptStat(0)
    rt.gROOT.SetBatch(True)

    # Get the 2D plots:
    OOT_CLS_DPHI_CSC = f.Get("OOT_CLS_DPHI_CSC")
    OOT_CLS_DPHI_CSC = swap_histogram_axis(OOT_CLS_DPHI_CSC)

    CMS.drawCMSLabel = custom_drawCMSLabel
    CMS.SetLumi("")
    CMS.SetExtraText("")
    CMS.SetEnergy("")
    CMS.SetCmsText("")
    Canv_OOT = CMS.cmsCanvas("OOT_CLS_DPHI_CSC",50,500,1,3.2,"N_{hits}","#Delta#phi(cluster,    #mu_{ trigger } )",square=False,extraSpace=0.05,iPos=0.0,with_z_axis=True,scaleLumi=1.0,yTitOffset=0.0)
    Canv_OOT.SetRightMargin(0.15)
    CMS.drawCMSLabel(bold=True)
    CMS.drawCMSLabel(text=lumiText, xpos=0.58, bold=False)
    # OOT_CLS_DPHI_CSC.Draw("same colz")
    OOT_CLS_DPHI_CSC.GetZaxis().SetTitle("Events")
    OOT_CLS_DPHI_CSC.GetZaxis().SetLabelSize(0.05)
    OOT_CLS_DPHI_CSC.GetZaxis().SetNdivisions(5)
    OOT_CLS_DPHI_CSC.GetZaxis().SetTitleSize(0.04)
    OOT_CLS_DPHI_CSC.Draw("same colz")

    # AddCMS(Canv_OOT)
    
    pt_a = rt.TPaveText(380,2.5,410,3,"br")
    pt_a.SetBorderSize(0)
    pt_a.SetFillStyle(0)
    pt_a_LaTex = pt_a.AddText("A")
    pt_a.SetTextSize(0.15)
    pt_a_LaTex.SetTextColor(color)
    pt_a.Draw("same")
   
    pt_b = rt.TPaveText(380,1.5,410,2,"br")
    pt_b.SetBorderSize(0)
    pt_b.SetFillStyle(0)
    pt_b_LaTex = pt_b.AddText("B")
    pt_b.SetTextSize(0.15)
    pt_b_LaTex.SetTextColor(color)
    pt_b.Draw("same")
   
    pt_c = rt.TPaveText(165,2.5,195,3,"br")
    pt_c.SetBorderSize(0)
    pt_c.SetFillStyle(0)
    pt_c_LaTex = pt_c.AddText("C")
    pt_c.SetTextSize(0.15)
    pt_c_LaTex.SetTextColor(color)
    pt_c.Draw("same")
   
    pt_d = rt.TPaveText(165,1.5,195,2,"br")
    pt_d.SetBorderSize(0)
    pt_d.SetFillStyle(0)
    pt_d_LaTex = pt_d.AddText("D")
    pt_d.SetTextSize(0.15)
    pt_d_LaTex.SetTextColor(color)
    pt_d.Draw("same")

    pt_d.Draw("same")

    CMS.SetCMSPalette()

    line_v = rt.TLine(310,1,310,3.2)
    line_v.SetLineColor(color)
    line_v.SetLineWidth(4)
    line_v.Draw("same")
    line_h = rt.TLine(50,2.2,500,2.2)
    line_h.SetLineColor(color)
    line_h.SetLineWidth(4)
    line_h.Draw("same")
    Canv_OOT.Update()
    Canv_OOT.SaveAs("./plotDump/2D_histogram/OOT_CLS_DPHI_CSC.png")
    Canv_OOT.SaveAs("./plotDump/2D_histogram/OOT_CLS_DPHI_CSC.pdf")
    Canv_OOT.SaveAs("./plotDump/2D_histogram/OOT_CLS_DPHI_CSC.C")
    Canv_OOT.Clear()
    Canv_OOT.Close()
    
    # Canv_OOT = rt.TCanvas("OOT_CLS_DPHI_DT", "OOT_CLS_DPHI_DT", 1500, 1000)
    # Canv_OOT.SetRightMargin(0.15)
    OOT_CLS_DPHI_DT = f.Get("OOT_CLS_DPHI_DT")
    OOT_CLS_DPHI_DT = swap_histogram_axis(OOT_CLS_DPHI_DT)
    # OOT_CLS_DPHI_DT.GetXaxis().SetRangeUser(50, 500);
    # OOT_CLS_DPHI_DT.GetYaxis().SetRangeUser(1, 3.2);
    # OOT_CLS_DPHI_DT.SetTitle("")
    # OOT_CLS_DPHI_DT.GetXaxis().SetTitleOffset(1.3)
    # OOT_CLS_DPHI_DT.GetXaxis().SetTitle("N_{hits}")
    # OOT_CLS_DPHI_DT.GetYaxis().SetTitle("\Delta\phi(cluster, \mu_{ trigger })")
    # OOT_CLS_DPHI_DT.Draw("colz")

    Canv_OOT = CMS.cmsCanvas("OOT_CLS_DPHI_DT",50,500,1,3.2,"N_{hits}","#Delta#phi(cluster,    #mu_{ trigger } )",square=False,extraSpace=0.05,iPos=0.0,with_z_axis=True,scaleLumi=1.0,yTitOffset=0.0)
    Canv_OOT.SetRightMargin(0.15)
    CMS.drawCMSLabel(bold=True)
    CMS.drawCMSLabel(text=lumiText, xpos=0.58, bold=False)
    # OOT_CLS_DPHI_DT.Draw("same colz")
    OOT_CLS_DPHI_DT.GetZaxis().SetTitle("Events")
    OOT_CLS_DPHI_DT.GetZaxis().SetLabelSize(0.05)
    OOT_CLS_DPHI_DT.GetZaxis().SetNdivisions(5)
    OOT_CLS_DPHI_DT.GetZaxis().SetTitleSize(0.04)
    OOT_CLS_DPHI_DT.Draw("same colz")

    # AddCMS(Canv_OOT)
    
    pt_a = rt.TPaveText(380,2.5,410,3,"br")
    pt_a.SetBorderSize(0)
    pt_a.SetFillStyle(0)
    pt_a_LaTex = pt_a.AddText("A")
    pt_a.SetTextSize(0.15)
    pt_a_LaTex.SetTextColor(color)
    pt_a.Draw("same")
   
    pt_b = rt.TPaveText(380,1.5,410,2,"br")
    pt_b.SetBorderSize(0)
    pt_b.SetFillStyle(0)
    pt_b_LaTex = pt_b.AddText("B")
    pt_b.SetTextSize(0.15)
    pt_b_LaTex.SetTextColor(color)
    pt_b.Draw("same")
   
    pt_c = rt.TPaveText(165,2.5,195,3,"br")
    pt_c.SetBorderSize(0)
    pt_c.SetFillStyle(0)
    pt_c_LaTex = pt_c.AddText("C")
    pt_c.SetTextSize(0.15)
    pt_c_LaTex.SetTextColor(color)
    pt_c.Draw("same")

    pt_d = rt.TPaveText(165,1.5,195,2,"br")
    pt_d.SetBorderSize(0)
    pt_d.SetFillStyle(0)
    pt_d_LaTex = pt_d.AddText("D")
    pt_d.SetTextSize(0.15)
    pt_d_LaTex.SetTextColor(color)
    pt_d.Draw("same")
    
    line_v = rt.TLine(310,1,310,3.2)
    line_v.SetLineWidth(4)
    line_v.SetLineColor(color)
    line_v.Draw("same")
    line_h = rt.TLine(50,2.2,500,2.2)
    line_h.SetLineWidth(4)
    line_h.SetLineColor(color)
    line_h.Draw("same")
    
    Canv_OOT.SaveAs("./plotDump/2D_histogram/OOT_CLS_DPHI_DT.png")
    Canv_OOT.SaveAs("./plotDump/2D_histogram/OOT_CLS_DPHI_DT.pdf")
    Canv_OOT.SaveAs("./plotDump/2D_histogram/OOT_CLS_DPHI_DT.C")
    Canv_OOT.Clear()
    Canv_OOT.Close()
    
    # Canv_IT = rt.TCanvas("IT_CLS_DPHI_DT", "IT_CLS_DPHI_DT", 1500, 1000)
    # Canv_IT.SetRightMargin(0.15)
    IT_CLS_DPHI_DT = f.Get("IT_CLS_DPHI_DT")
    IT_CLS_DPHI_DT = swap_histogram_axis(IT_CLS_DPHI_DT)
    # IT_CLS_DPHI_DT.GetXaxis().SetRangeUser(50, 500)
    # IT_CLS_DPHI_DT.GetYaxis().SetRangeUser(1, 3.2)
    # IT_CLS_DPHI_DT.SetTitle("")
    # IT_CLS_DPHI_DT.GetXaxis().SetTitleOffset(1.3)
    # IT_CLS_DPHI_DT.GetXaxis().SetTitle("N_{hits}")
    # IT_CLS_DPHI_DT.GetYaxis().SetTitle("\Delta\phi(cluster, \mu_{ trigger })")
    # IT_CLS_DPHI_DT.Draw("colz")

    Canv_IT = CMS.cmsCanvas("IT_CLS_DPHI_DT",50,500,1,3.2,"N_{hits}","#Delta#phi(cluster,    #mu_{ trigger } )",square=False,extraSpace=0.05,iPos=0.0,with_z_axis=True,scaleLumi=1.0,yTitOffset=0.0)
    Canv_IT.SetRightMargin(0.15)
    CMS.drawCMSLabel(bold=True)
    CMS.drawCMSLabel(text=lumiText, xpos=0.58, bold=False)
    # IT_CLS_DPHI_DT.Draw("same colz")
    IT_CLS_DPHI_DT.GetZaxis().SetTitle("Events")
    IT_CLS_DPHI_DT.GetZaxis().SetLabelSize(0.05)
    IT_CLS_DPHI_DT.GetZaxis().SetNdivisions(5)
    IT_CLS_DPHI_DT.GetZaxis().SetTitleSize(0.04)
    IT_CLS_DPHI_DT.Draw("same colz")

    # AddCMS(Canv_OOT)
    
    pt_a = rt.TPaveText(380,2.5,410,3,"br")
    pt_a.SetBorderSize(0)
    pt_a.SetFillStyle(0)
    pt_a_LaTex = pt_a.AddText("A")
    pt_a.SetTextSize(0.15)
    pt_a_LaTex.SetTextColor(color)
    pt_a.Draw("same")
   
    pt_b = rt.TPaveText(380,1.5,410,2,"br")
    pt_b.SetBorderSize(0)
    pt_b.SetFillStyle(0)
    pt_b_LaTex = pt_b.AddText("B")
    pt_b.SetTextSize(0.15)
    pt_b_LaTex.SetTextColor(color)
    pt_b.Draw("same")
   
    pt_c = rt.TPaveText(165,2.5,195,3,"br")
    pt_c.SetBorderSize(0)
    pt_c.SetFillStyle(0)
    pt_c_LaTex = pt_c.AddText("C")
    pt_c.SetTextSize(0.15)
    pt_c_LaTex.SetTextColor(color)
    pt_c.Draw("same")
   
    pt_d = rt.TPaveText(165,1.5,195,2,"br")
    pt_d.SetBorderSize(0)
    pt_d.SetFillStyle(0)
    pt_d_LaTex = pt_d.AddText("D")
    pt_d.SetTextSize(0.15)
    pt_d_LaTex.SetTextColor(color)
    pt_d.Draw("same")

    line_v = rt.TLine(310,1,310,3.2)
    line_v.SetLineWidth(4)
    line_v.SetLineColor(color)
    line_v.Draw("same")
    line_h = rt.TLine(50,2.2,500,2.2)
    line_h.SetLineWidth(4)
    line_h.SetLineColor(color)
    line_h.Draw("same")
    
    Canv_IT.SaveAs("./plotDump/2D_histogram/IT_CLS_DPHI_DT.png")
    Canv_IT.SaveAs("./plotDump/2D_histogram/IT_CLS_DPHI_DT.pdf")
    Canv_IT.SaveAs("./plotDump/2D_histogram/IT_CLS_DPHI_DT.C")
    Canv_IT.Clear()
    Canv_IT.Close()

    # Canv_IT = rt.TCanvas("IT_CLS_DPHI_CSC", "IT_CLS_DPHI_CSC", 1500, 1000)
    # Canv_IT.SetRightMargin(0.15)
    IT_CLS_DPHI_CSC = f.Get("IT_CLS_DPHI_CSC")
    IT_CLS_DPHI_CSC = swap_histogram_axis(IT_CLS_DPHI_CSC)
    # IT_CLS_DPHI_CSC.GetXaxis().SetRangeUser(50, 500)
    # IT_CLS_DPHI_CSC.GetYaxis().SetRangeUser(1, 3.2)
    # IT_CLS_DPHI_CSC.SetTitle("")
    # IT_CLS_DPHI_CSC.GetXaxis().SetTitleOffset(1.3)
    # IT_CLS_DPHI_CSC.GetXaxis().SetTitle("N_{hits}")
    # IT_CLS_DPHI_CSC.GetYaxis().SetTitle("\Delta\phi(cluster, \mu_{ trigger })")
    # IT_CLS_DPHI_CSC.Draw("colz")
    # AddCMS(Canv_IT)

    Canv_IT = CMS.cmsCanvas("IT_CLS_DPHI_CSC",50,500,1,3.2,"N_{hits}","#Delta#phi(cluster,    #mu_{ trigger } )",square=False,extraSpace=0.05,iPos=0.0,with_z_axis=True,scaleLumi=1.0,yTitOffset=0.0)
    Canv_IT.SetRightMargin(0.15)
    CMS.drawCMSLabel(bold=True)
    CMS.drawCMSLabel(text=lumiText, xpos=0.58, bold=False)
    # IT_CLS_DPHI_DT.Draw("same colz")
    IT_CLS_DPHI_DT.GetZaxis().SetTitle("Events")
    IT_CLS_DPHI_DT.GetZaxis().SetLabelSize(0.05)
    IT_CLS_DPHI_DT.GetZaxis().SetNdivisions(5)
    IT_CLS_DPHI_DT.GetZaxis().SetTitleSize(0.04)
    IT_CLS_DPHI_DT.Draw("same colz")

    # AddCMS(Canv_OOT)
    
    pt_a = rt.TPaveText(380,2.5,410,3,"br")
    pt_a.SetBorderSize(0)
    pt_a.SetFillStyle(0)
    pt_a_LaTex = pt_a.AddText("A")
    pt_a.SetTextSize(0.15)
    pt_a_LaTex.SetTextColor(color)
    pt_a.Draw("same")
   
    pt_b = rt.TPaveText(380,1.5,410,2,"br")
    pt_b.SetBorderSize(0)
    pt_b.SetFillStyle(0)
    pt_b_LaTex = pt_b.AddText("B")
    pt_b.SetTextSize(0.15)
    pt_b_LaTex.SetTextColor(color)
    pt_b.Draw("same")
   
    pt_c = rt.TPaveText(165,2.5,195,3,"br")
    pt_c.SetBorderSize(0)
    pt_c.SetFillStyle(0)
    pt_c_LaTex = pt_c.AddText("C")
    pt_c.SetTextSize(0.15)
    pt_c_LaTex.SetTextColor(color)
    pt_c.Draw("same")
   
    pt_d = rt.TPaveText(165,1.5,195,2,"br")
    pt_d.SetBorderSize(0)
    pt_d.SetFillStyle(0)
    pt_d_LaTex = pt_d.AddText("D")
    pt_d.SetTextSize(0.15)
    pt_d_LaTex.SetTextColor(color)
    pt_d.Draw("same")
    
    line_v = rt.TLine(310,1,310,3.2)
    line_v.SetLineWidth(4)
    line_v.SetLineColor(color)
    line_v.Draw("same")
    line_h = rt.TLine(50,2.2,500,2.2)
    line_h.SetLineWidth(4)
    line_h.SetLineColor(color)
    line_h.Draw("same")
    
    Canv_IT.SaveAs("./plotDump/2D_histogram/IT_CLS_DPHI_CSC.png")
    Canv_IT.SaveAs("./plotDump/2D_histogram/IT_CLS_DPHI_CSC.pdf")
    Canv_IT.SaveAs("./plotDump/2D_histogram/IT_CLS_DPHI_CSC.C")
    Canv_IT.Clear()
    Canv_IT.Close()

    IT_CLS_DPHI_CSC_copy = IT_CLS_DPHI_CSC.Clone()
    
    IT_CLS_DPHI_CSC_copy.GetXaxis().SetRangeUser(2.2, 3.2)
    IT_CLS_DPHI_CSC_copy.GetYaxis().SetRangeUser(310, 3000)
    region_A_IT = IT_CLS_DPHI_CSC_copy.Integral()
    
    IT_CLS_DPHI_CSC_copy.GetXaxis().SetRangeUser(0.0, 2.2)
    IT_CLS_DPHI_CSC_copy.GetYaxis().SetRangeUser(0.0, 310)
    region_D_IT = IT_CLS_DPHI_CSC_copy.Integral()
    
    IT_CLS_DPHI_CSC_copy.GetXaxis().SetRangeUser(2.2, 3.2)
    IT_CLS_DPHI_CSC_copy.GetYaxis().SetRangeUser(0.0, 310)
    region_C_IT = IT_CLS_DPHI_CSC_copy.Integral()
    
    IT_CLS_DPHI_CSC_copy.GetXaxis().SetRangeUser(0.0, 2.2)
    IT_CLS_DPHI_CSC_copy.GetYaxis().SetRangeUser(310, 3000)
    region_B_IT = IT_CLS_DPHI_CSC_copy.Integral()
    
    print("-----------------------------> Region A integral: ", region_A_IT)
    print("-----------------------------> Region B integral: ", region_B_IT)
    print("-----------------------------> Region C integral: ", region_C_IT)
    print("-----------------------------> Region D integral: ", region_D_IT)
    
