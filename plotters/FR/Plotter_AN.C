#include <iostream>
#include<algorithm>
#include "TString.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TLegend.h"
#include "TPad.h"
#include "TStyle.h"
#include "TText.h"
#include "TFile.h"
#include <stdio.h>
#include <cstdlib> /* mkdir */

#include <stdlib.h>     /* getenv */

//CMS STANDARD
TString extraText   = "";
TString lumiText = "41.6 fb^{-1} (13 TeV)";

int HexToROOTColor(const char* hex) {
    int r, g, b;
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);
    return TColor::GetColor(r, g, b);
}

bool AddCMS( TCanvas* C )
{
  C->cd();
  float lumix = 0.9;
  float lumiy = 0.91;
  float lumifont = 42;

  float cmsx = 0.33;
  float cmsy = 0.81;
  
  float cmsTextFont   = 61;  // default is helvetic-bold
  float extrax = cmsx +0.3;
  float extray = cmsy;
  float extraTextFont = 52;  // default is helvetica-italics
  // ratio of "CMS" and extra text size
  float extraOverCmsTextSize  = 0.76;
  float cmsSize = 0.075;
  TLatex latex;
  latex.SetNDC();
  latex.SetTextAngle(0);
  latex.SetTextColor(kBlack);
  float extraTextSize = extraOverCmsTextSize*cmsSize;
  latex.SetTextFont(lumifont);
  latex.SetTextAlign(31);
  latex.SetTextSize(0.8*cmsSize);
  latex.DrawLatex(lumix, lumiy,lumiText);

  latex.SetTextFont(cmsTextFont);
  latex.SetTextAlign(31);
  latex.SetTextSize(cmsSize);
  latex.DrawLatex(cmsx, cmsy, "CMS");

  latex.SetTextFont(extraTextFont);
  latex.SetTextAlign(31);
  latex.SetTextSize(extraTextSize);
  latex.DrawLatex(extrax, extray, extraText);
  std::cout<<"-------------------------- Just drew the CMS style elements"<<std::endl;
  return true;
};

void Plotter_AN(TString region, bool dolog, TString inpath, TString aversion){

  TString bkgName = "Parking_2018_";
  // TString bkgpath = "root://eoscms.cern.ch//eos/user/d/ddiaz/forAram/Parking_2018_nominal_plots.root";
  TString bkgpath = "Parking_2018_nominal_plots.root";
  TFile * bkgFile = TFile::Open(bkgpath);
  std::vector<TString> signalName;
  signalName.clear();
  
  signalName.push_back("BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300_to_100/BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300to100_");
  //signalName.push_back("BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300_to_100/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300to100_");

  //signalName.push_back("BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau500_to_100/BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau500_ext2to100_");
  //signalName.push_back("BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p5_ctau500_to_100/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p5_ctau500_ext2to100_");

  signalName.push_back("BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000_to_300/BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000_ext2to300_");
  //signalName.push_back("BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000_to_300/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000_ext2to300_");

  signalName.push_back("BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau2000_to_1000/BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau2000_ext2to1000_");
  //signalName.push_back("BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau2000_to_1000/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau2000_ext2to1000_");

  //signalName.push_back("BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau3000_to_1000/BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau3000_ext2to1000_");
  //signalName.push_back("BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau3000_to_1000/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau3000_ext2to1000_");
  
  int lineStyles[] = {2,9,6,1,3,4,5,7,8,10};
  int colors[] = {HexToROOTColor("#5790fc"), 
                  HexToROOTColor("#f89c20"), 
                  HexToROOTColor("#e42536"),
                  HexToROOTColor("#964a8b"), 
                  HexToROOTColor("#9c9ca1"), 
                  HexToROOTColor("#7a21dd"), 
                  kGreen, kSpring+1, kYellow, kOrange};

  // make canvas and text
  TCanvas* canvas = new TCanvas("canvas","canvas",1,1,800,800);
  canvas->SetLeftMargin(0.15);
  canvas->SetBottomMargin(0.14);
  gStyle->SetOptStat(0);
  gPad->SetLogy(dolog);
  gPad->SetTickx();
  gPad->SetTicky();
  gStyle->SetLineWidth(3);
  gStyle->SetPalette(71); //kBlueGreenYellow

  std::vector<TString> variables;
  variables.clear();
  variables.push_back("cscRechitClusterDPhiLeadMuon");
  variables.push_back("cscRechitClusterSize");
  variables.push_back("cscRechitClusterTime");

 for (int i =0; i<variables.size(); i++){
  std::vector<TH1F*> h_sig;
  TH1F * h_bkg;
  TLegend *leg = new TLegend(0.15,0.57,0.95,0.78);
  leg->SetNColumns(1);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.052);
  leg->SetFillColor(kWhite);
  cout<<variables[i]<<"   "<<i<<endl;

  for (int j =0; j<signalName.size(); j++) {

  Ssiz_t pos1   = signalName[j].Index("PhiT");
  Ssiz_t pos2;
  TString legend_decay_channel;
  if (signalName[j].Contains("PiPlusPiMinus")) {
      pos2   = signalName[j].Index("/BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus");
      legend_decay_channel = "#rightarrow #pi^{+}#pi^{-}";
  } else {
      pos2   = signalName[j].Index("/BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0");
      legend_decay_channel = "#rightarrow #pi^{0}#pi^{0}";
  }
  
  Ssiz_t pos3   = signalName[j].Index("_ctau");
  Ssiz_t pos_ct = signalName[j].Index("to");
  Ssiz_t pos_m  = signalName[j].Index("mPhi");
  TString dl      = signalName[j](pos_ct+3,pos2-(pos_ct+3)); // (start_index, steps towards right)
  std::cout<<"------------------------------->  "<<pos_ct+3<<"  <->  "<<pos2<<"  <->  "<<dl<<"  <->  "<<signalName[j]<<std::endl;
  TString mass    = signalName[j](pos_m+4,pos3-(pos_m+4));
  mass.ReplaceAll("p", ".");
  TString sigName = signalName[j](pos1,pos2);
  TString sigpath = inpath+signalName[j]+region+"_plots.root";
  cout<<sigpath<<endl;
  
  if(variables[i]=="nCscRechits"){
    h_sig.push_back((TH1F*)TFile::Open(sigpath)->Get(variables[i])->Clone("h_sig"));
    h_bkg = (TH1F*)bkgFile->Get(variables[i])->Clone("h_bkg");
  }
  else{
    h_sig.push_back((TH1F*)TFile::Open(sigpath)->Get("h_"+variables[i])->Clone("h_sig"));
    h_bkg = (TH1F*)bkgFile->Get("h_"+variables[i])->Clone("h_bkg");
  }
  if (variables[i]=="cscRechitClusterSize" || variables[i]=="dtRechitClusterSize") {
       h_sig[j]->Rebin(10);
       h_bkg->Rebin(10);
  }

    std::cout<<"Normalize to unity"<<std::endl;
    std::cout<<"Number of events SIGNAL: "<<h_sig[j]->GetEntries()<<std::endl;
    // std::cout<<"Number of events DATA  : "<<h_bkg->GetEntries()<<std::endl;
    if (h_sig[j]->GetEntries()>0) h_sig[j]->Scale(1./h_sig[j]->Integral());
    if (h_bkg->GetEntries()>0) h_bkg->Scale(1./h_bkg->Integral());
    if (variables[i] == "cscRechitClusterDPhiLeadMuon" || variables[i] == "dtRechitClusterDPhiLeadMuon") {
        // h_sig[j]->Rebin(2);
        // h_bkg->Rebin(2);
        h_sig[j]->GetXaxis()->SetRangeUser(0.95, 3.2);
        if (dolog) {
            h_sig[j]->SetMaximum(10.0);
            h_sig[j]->SetMinimum(0.001);
        }
        else {
            h_sig[j]->SetMaximum(0.3);
            h_sig[j]->SetMinimum(0.001);
        }
    }
    if (variables[i] == "cscRechitClusterTime" || variables[i] == "dtRechitClusterTime") {
        // h_sig[j]->Rebin(2);
        // h_bkg->Rebin(2);
        if (dolog) {
            h_sig[j]->SetMaximum(100.0);
            h_sig[j]->SetMinimum(0.000001);
        }
        else {
            h_sig[j]->SetMaximum(0.42);
            h_sig[j]->SetMinimum(0.00000);
            h_sig[j]->GetXaxis()->SetRangeUser(-30,30);
            h_bkg->GetXaxis()->SetRangeUser(-30,30);
        }
    }
    if (variables[i] == "cscRechitClusterTimeSpread" || variables[i] == "dtRechitClusterTimeSpread") {
        // h_sig[j]->Rebin(2);
        // h_bkg->Rebin(2);
        if (dolog) {
            h_sig[j]->SetMaximum(100.0);
            h_sig[j]->SetMinimum(0.000001);
        }
        else {
            h_sig[j]->SetMaximum(0.42);
            h_sig[j]->SetMinimum(0.000001);
        }
    }
    if (variables[i] == "dtRechitClusterSize" || variables[i] == "cscRechitClusterSize") {
        h_sig[j]->Rebin(3);
        h_bkg->Rebin(3);
        h_sig[j]->GetXaxis()->SetRangeUser(50,530);
        if (dolog) {
            h_sig[j]->SetMaximum(1000.0);
            // h_sig[j]->SetMinimum(0.001);
            h_sig[j]->SetMinimum(0.001);
        }
        else {
            h_sig[j]->SetMaximum(1.5);
            // h_sig[j]->SetMinimum(0.001);
            h_sig[j]->SetMinimum(0.001);
        }
        h_sig[j]->GetXaxis()->SetNdivisions(505);
    }
    
    if (variables[i] == "gLLP_ctau") {
        h_sig[j]->GetXaxis()->SetRangeUser(50,530);
        if (dolog) {
            h_sig[j]->SetMaximum(10.0);
            h_sig[j]->SetMinimum(0.00001);
        }
        else {
            h_sig[j]->SetMaximum(1.5);
            h_sig[j]->SetMinimum(0.00001);
        }
    }
    
    if (variables[i] == "cscRechitClusterMuonVetoPt") {
        h_sig[j]->GetXaxis()->SetRangeUser(0, 40);
        h_bkg->GetXaxis()->SetRangeUser(0, 40);
    }

    double ymax=0;
    ymax = max(h_sig[j]->GetMaximum(), h_sig[j]->GetMaximum());

   leg->SetTextSize(0.04);
   leg->SetMargin(0.15);
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(3);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   leg->SetMargin(0.22);

    if (j != 0) {
        h_sig[j]->Draw("hist e sames");
    } else {
        h_sig[j]->Draw("hist e");
        // leg->AddEntry(h_bkg, "Background","l");
        leg->AddEntry(h_bkg, "Background-enriched data","l");
    }
    h_bkg->Draw("hist e sames");
    // if(dolog)  {h_sig[j]->SetMaximum(ymax*(50)); h_sig[j]->SetMinimum(0.001);}
    // if(dolog)  {h_sig[j]->SetMaximum(10); h_sig[j]->SetMinimum(0.001);}
    // else       h_sig[j]->SetMaximum(ymax*(1.5));

    h_sig[j]->SetTitle("");
    h_sig[j]->GetYaxis()->SetTitle("a.u.");
    h_sig[j]->GetYaxis()->SetTitleOffset(1.0);
    // h_sig[j]->GetXaxis()->SetTitleOffset(0.8);
    h_sig[j]->GetXaxis()->SetTitleOffset(1.0);
    h_sig[j]->GetYaxis()->SetTitleSize(0.04);
    h_sig[j]->GetXaxis()->SetTitleSize(0.04);
    h_sig[j]->GetXaxis()->SetTitle(variables[i]);
    
    double originalYSize = h_sig[j]->GetYaxis()->GetTitleSize();
    double originalXSize = h_sig[j]->GetXaxis()->GetTitleSize();
    double originalYlabelSize = h_sig[j]->GetYaxis()->GetLabelSize();
    double originalXlabelSize = h_sig[j]->GetXaxis()->GetLabelSize();
    
    h_sig[j]->GetXaxis()->SetLabelSize(originalXlabelSize*1.5);
    h_sig[j]->GetYaxis()->SetLabelSize(originalYlabelSize*1.5);
    h_sig[j]->GetYaxis()->SetTitleSize(originalYSize * 1.5);
    h_sig[j]->GetXaxis()->SetTitleSize(originalXSize * 1.5);
    
    gPad->SetLeftMargin(0.15);
    gPad->SetBottomMargin(0.14);
    
    if (variables[i].Contains("Bx") && variables[i].Contains("dt")) {
        h_sig[j]->GetXaxis()->SetTitle("Bunch crossing");
    } else if (variables[i].Contains("Time") && variables[i].Contains("csc")) {
        h_sig[j]->GetXaxis()->SetTitle("t_{cluster} [ns]");
        h_sig[j]->GetXaxis()->SetRangeUser(-30, 30);
        h_sig[j]->GetYaxis()->SetTitleOffset(1.2);
    }

    if (variables[i].Contains("ClusterSize") && variables[i].Contains("dt")) {
        h_sig[j]->GetXaxis()->SetTitle("N_{Hits}");
    } if (variables[i].Contains("ClusterSize") && variables[i].Contains("csc")) {
        h_sig[j]->GetXaxis()->SetTitle("N_{hits}");
        h_sig[j]->GetYaxis()->SetTitleOffset(1.2);
    }

    if (variables[i].Contains("DPhi") && variables[i].Contains("dt")) {
        h_sig[j]->GetXaxis()->SetTitle("#Delta#phi(cluster, #mu_{trigger})");
    } if (variables[i].Contains("DPhi") && variables[i].Contains("csc")) {
        h_sig[j]->GetXaxis()->SetTitle("#Delta#phi(cluster, #mu_{trigger})");
        h_sig[j]->GetYaxis()->SetTitleOffset(1.2);
    }
    
    h_bkg->SetLineWidth(3);
    h_bkg->SetLineColor(1);

    h_sig[j]->SetLineColor(colors[j]);
    h_sig[j]->SetLineStyle(lineStyles[j]);
    h_sig[j]->SetLineWidth(3);

    std::cout<<"------------------------------->  "<<pos_ct+3<<"  <->  "<<pos2<<"  <->  "<<dl<<"  <->  "<<signalName[j]<<std::endl;
    if (sigName.Contains("PhiToPiPlusPiMinus")) {
        if (j == 1 && false) { // For the plot which demonstrates the reweighted ctau distribution.
            leg->AddEntry(h_sig[j], "m_{#Phi" + legend_decay_channel + "}=0.3 GeV, c#tau_{#Phi}=1000 #rightarrow 300 mm","l");
        } else {
            leg->AddEntry(h_sig[j], "m_{#Phi} = "+mass+" GeV, c#tau_{#Phi} = "+dl+" mm","l");
        }
    }
    else {
        // h_sig[j]->SetLineStyle(7);
        //leg->AddEntry(h_sig[j], "m_{#Phi" + legend_decay_channel + "}="+mass+" GeV, c#tau_{#Phi}="+dl+" mm","l");
        leg->AddEntry(h_sig[j], "m_{#Phi} = "+mass+" GeV, c#tau_{#Phi}="+dl+" mm","l");

    }

    AddCMS(canvas);
    // leg->Draw("sames");
    gPad->Update();
    // gPad->RedrawAxis();
  }

    leg->Draw("sames");
    // gPad->Update();
    gPad->RedrawAxis();
    cout<<variables[i]<<endl;
    if(dolog) {
        canvas->SaveAs("plotDump/"+variables[i]+"_"+region+"_log.pdf");
        canvas->SaveAs("plotDump/"+variables[i]+"_"+region+"_log.C");
    }
    else {
        canvas->SaveAs("plotDump/"+variables[i]+"_"+region+".pdf");
        canvas->SaveAs("plotDump/"+variables[i]+"_"+region+".C");
    }
    canvas->Clear();

  }
}

