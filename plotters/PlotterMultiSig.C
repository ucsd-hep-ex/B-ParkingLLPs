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


#include <TString.h>
TString lumiText = "41.58 fb^{-1} (13 TeV)";
TString extraText   = "Preliminary";
//Margins
const float leftMargin   = 0.12;
const float rightMargin  = 0.05;
const float topMargin    = 0.07;
const float bottomMargin = 0.10;

struct SignalInfo {
    TString name;
    TString mass;
    TString dl;
};

SignalInfo extractSignalInfo(TString signalName) {
    Ssiz_t pos1   = signalName.Index("PhiT");
    Ssiz_t pos2   = signalName.Last('_');
    Ssiz_t pos3   = signalName.Index("_ctau");
    Ssiz_t pos_ct = signalName.Index("to");
    Ssiz_t pos_m  = signalName.Index("mPhi");

    //TString dl      = signalName(pos_ct+2, pos2-(pos_ct+2));
    TString dl      = signalName(pos2 + 1, signalName.Length() - pos2 - 1);
    TString mass    = signalName(pos_m+4, pos3-(pos_m+4));
    mass.ReplaceAll("p", ".");

    SignalInfo info;
    info.name = signalName(pos1, pos2 - pos1);
    info.mass = mass;
    info.dl = dl;

    return info;
}

bool AddCMS( TCanvas* C )
{
  C->cd();
  float lumix = 0.955;
  float lumiy = 0.945;
  float lumifont = 42;

  float cmsx = 0.25;
  float cmsy = 0.94;
  float cmsTextFont   = 61;  // default is helvetic-bold
  float extrax = cmsx +0.20;
  float extray = cmsy;
  float extraTextFont = 52;  // default is helvetica-italics
  // ratio of "CMS" and extra text size
  float extraOverCmsTextSize  = 0.76;
  float cmsSize = 0.06;
  TLatex latex;
  latex.SetNDC();
  latex.SetTextAngle(0);
  latex.SetTextColor(kBlack);
  float extraTextSize = extraOverCmsTextSize*cmsSize;
  latex.SetTextFont(lumifont);
  latex.SetTextAlign(31);
  latex.SetTextSize(cmsSize);
  latex.DrawLatex(lumix, lumiy,lumiText);

  latex.SetTextFont(cmsTextFont);
  latex.SetTextAlign(31);
  latex.SetTextSize(cmsSize);
  latex.DrawLatex(cmsx, cmsy, "CMS");

  latex.SetTextFont(extraTextFont);
  latex.SetTextAlign(31);
  latex.SetTextSize(extraTextSize);
  latex.DrawLatex(extrax, extray, extraText);
  return true;
};

void setCanvas(TCanvas* c){

  c->SetHighLightColor(2);
  c->SetFillColor(0);
  c->SetBorderMode(0);
  c->SetBorderSize(2);
  c->SetLeftMargin( leftMargin );
  c->SetRightMargin( rightMargin );
  c->SetTopMargin( topMargin );
  c->SetBottomMargin( bottomMargin );
  c->SetFrameBorderMode(0);
  c->SetFrameBorderMode(0);
  c->SetLogy();
  c->SetLogx();

  gStyle->SetPaintTextFormat("4.3f");
}

void PlotterMultiSig(TString region, bool dolog, TString inpath, TString aversion, TString signalStr){
  bool plotbkg = false;
  std::vector<TFile*> sigFile;
  std::vector<TH1F*>  h_sig;
  std::vector<TString> signals;
  std::vector<TString> sigName;
  std::vector<TString> sigpath;
  std::vector<SignalInfo> info;
  TObjArray* tokens = signalStr.Tokenize(",");
  std::vector<int> theColor = {kBlue, kBlack, kGreen, kRed, kOrange};
  TString nameFixed;
  for (int i = 0; i < tokens->GetEntries(); ++i) {
      signals.push_back(((TObjString*)tokens->At(i))->GetString());
      info.push_back(extractSignalInfo(signals[i]));
      sigName.push_back(info[i].name.Data());
      nameFixed = signals[i];
      nameFixed.ReplaceAll("_to_", "to");
      sigpath.push_back(inpath+signals[i]+"/"+nameFixed+"_"+region+"_plots.root");
      sigFile.push_back(TFile::Open(sigpath[i]));
  }

  TString bkgName = "Parking_2018_";
  TString bkgpath  = inpath+bkgName+region+"_plots.root";
  TFile* bkgFile;
  if(plotbkg) bkgFile =  TFile::Open(bkgpath);  
  TH1F* h_bkg;

   // make canvas and text
  //TCanvas* canvas = new TCanvas("canvas","canvas",900,100,500,500); 
  TCanvas* canvas = new TCanvas( "canvas", "canvas", 2119, 33, 800, 700 );
  setCanvas(canvas);
  gStyle->SetOptStat(0);
  gPad->SetLogy(dolog);
  gPad->SetLogx(0);
  //gPad->SetGrid();
  gPad->SetTickx();
  gPad->SetTicky();
  gStyle->SetLineWidth(3);
  gStyle->SetPalette(71); //kBlueGreenYellow

  std::vector<TString> variables;
  variables.clear();
  variables.push_back("cscRechitClusterDPhiLeadMuon");
  variables.push_back("cscRechitClusterSize");
  variables.push_back("cscRechitClusterSize_v");
  variables.push_back("cscRechitClusterSize_v2");
//  variables.push_back("dtRechitClusterMaxStation");
//  variables.push_back("cscRechitClusterSize");
//  variables.push_back("cscRechitClusterSize_v");
//  variables.push_back("cscRechitClusterTime");
//  variables.push_back("cscRechitClusterEta");
//  variables.push_back("cscRechitClusterPhi");
//  variables.push_back("cscRechitClusterTimeTotal");
//  variables.push_back("cscRechitClusterTimeWeighted");
//  variables.push_back("cscRechitClusterTimeSpread");
//  variables.push_back("cscRechitClusterTimeSpreadWeighted");
//  variables.push_back("cscRechitClusterTimeSpreadWeightedAll");
//  //variables.push_back("nLeptons");
//  //variables.push_back("nCscRechits");
//  variables.push_back("cscRechitClusterMuonVetoPt");
//  variables.push_back("dtRechitClusterMuonVetoPt");
//  variables.push_back("dtRechitClusterDPhiLeadMuon");
//  variables.push_back("dtRechitClusterEta");
//  variables.push_back("dtRechitClusterSize");
  //variables.push_back("dtRechitClusterPhi");
  //variables.push_back("dtRechitCluster_match_RPCBx_dPhi0p5");
  //variables.push_back("cscRechitClusterTime");
  //variables.push_back("cscRechitClusterTimeTotal");
  //variables.push_back("cscRechitClusterTimeWeighted");
  //variabes.push_back("nDTRechits");
  //variables.push_back("dtRechitCluster_match_RPCTime_dR0p4");
  //variables.push_back("dtRechitCluster_match_RPCTimeSpread_dR0p4");
  //variables.push_back("dtRechitCluster_match_RPChits_dR0p4");
  //variables.push_back("dtRechitCluster_match_RPCTime_dPhi0p5");
  //variables.push_back("dtRechitCluster_match_RPCTimeSpread_dPhi0p5");
  //variables.push_back("dtRechitCluster_match_RPCTime_sameStation_dR0p4");
  //variables.push_back("dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4");

  for (int i =0; i<variables.size(); i++){
    // legend
    TLegend *leg = new TLegend(0.15,0.75,0.85,0.87);
    leg->SetNColumns(1);
    leg->SetBorderSize(0);
    leg->SetFillColor(kWhite);
    canvas->Clear();
    setCanvas(canvas);
    double norm=1.0; 
    double ymax=0;
    if(plotbkg){
      if(variables[i]=="nCscRechits") h_bkg  = (TH1F*)bkgFile->Get(variables[i])->Clone("h_bkg");
      else                            h_bkg  = (TH1F*)bkgFile->Get("h_"+variables[i])->Clone("h_bkg");
      //if (h_bkg->GetEntries()>0)  h_bkg->Scale(1./h_bkg->Integral());
      ymax = h_bkg->GetMaximum();
      //if(variables[i] =="cscRechitClusterDPhiLeadMuon"){
      //  h_bkg ->Rebin(3);
      //  h_bkg ->GetXaxis()->SetRangeUser(0.9,3.3);
      //}
      //if(variables[i] =="cscRechitClusterSize"){
      //  h_bkg ->Rebin(10);
      //}
      h_bkg->Draw("hist");
    }
    h_sig.resize(sigFile.size());
    for(int j = 0; j<h_sig.size(); j++){ 
      if(variables[i]=="nCscRechits")  h_sig[j]  = (TH1F*)sigFile[j]->Get(variables[i])->Clone(TString::Format("h_sig_%d",j));
      else                             h_sig[j]  = (TH1F*)sigFile[j]->Get("h_"+variables[i])->Clone(TString::Format("h_sig_%d",j));
      if (h_sig[j]->GetEntries()>0)  h_sig[j]->Scale(1./h_sig[j]->Integral());

      //if(info2.dl=="1000") h_sig2->Scale(10.*41.58*0.0003);
      //if(info.dl =="1000") h_sig ->Scale(10.*41.58*0.0003);
      //if(info2.dl=="300")  h_sig2->Scale(10.*41.58*1.e-04);
      //if(info.dl =="300")  h_sig ->Scale(10.*41.58*1.e-04);

      //h_sig ->Scale(41.58*1.e-04);
      //h_sig2->Scale(41.58*0.0003);

      ymax = max(h_sig[j]->GetMaximum(), ymax);   

      if(variables[i] =="cscRechitClusterSize_v2"){
      //  h_sig[j] ->Rebin(3);
        h_sig[j] ->GetXaxis()->SetRangeUser(50,200);
      }
    
      if(variables[i] =="cscRechitClusterDPhiLeadMuon"){
      //  h_sig[j] ->Rebin(3);
        h_sig[j] ->GetXaxis()->SetRangeUser(0.9,3.3);
      }
      if(variables[i] =="cscRechitClusterSize"){
        h_sig[j] ->Rebin(20);
      }
    }
    for (int k=0; k<h_sig.size(); k++){
      if (!plotbkg && k==0)  h_sig[k]->Draw("hist E1");
      else                   h_sig[k]->Draw("hist E1 sames");
      if(dolog)  {
        h_sig[k]->SetMaximum(ymax*(1000)); 
        h_sig[k]->SetMinimum(0.000001);
      }
      else{ 
        h_sig[k]->SetMaximum(ymax*(1.2));
      }

      h_sig[k]->SetTitle("");    
      h_sig[k]->GetYaxis()->SetTitle("Events");
      //h_sig->GetYaxis()->SetTitle("a.u.");
      h_sig[k]->GetYaxis()->SetTitleOffset(1.5);
      h_sig[k]->GetXaxis()->SetTitle(variables[i]);
      if(variables[i].Contains("Size"))
        h_sig[k]->GetXaxis()->SetTitle("N_{Rechits}");
      if(variables[i].Contains("DPhi"))
        h_sig[k]->GetXaxis()->SetTitle("#Delta#Phi(Cluster, #mu)");
      h_sig[k]->SetLineColor(theColor[k]);
      h_sig[k]->SetLineWidth(2);

      if(plotbkg) h_bkg->SetLineColor(kBlack);
      if(plotbkg) h_bkg->SetLineWidth(2);
      if (sigName[k].Contains("PhiToPiPlusPiMinus")) leg->AddEntry(h_sig[k],   TString("#Phi#rightarrow#pi^{+}#pi^{-}    m_{#Phi}=")+info[k].mass+ "GeV, c#tau_{#Phi}="+info[k].dl+"mm","l");
      else                                           leg->AddEntry(h_sig[k],   TString("#Phi#rightarrow#pi^{0}#pi^{0}    m_{#Phi}=")+info[k].mass+ "GeV, c#tau_{#Phi}="+info[k].dl+"mm","l");
    }
    AddCMS(canvas);
    if(plotbkg) leg->AddEntry(h_bkg, "Background","l");
    leg->Draw("sames");
    gPad->Update();
    gPad->SetLogx(0);
    gPad->RedrawAxis();

    if(dolog) canvas->SaveAs("plotDump/"+aversion+"/"+variables[i]+"_"+region+"_log.pdf");
    else canvas->SaveAs("plotDump/"+aversion+"/"+variables[i]+"_"+region+".pdf");
//    if(dolog) canvas->SaveAs("plotDump/"+aversion+"/"+variables[i]+"_"+region+"_log.C");
//    else canvas->SaveAs("plotDump/"+aversion+"/"+variables[i]+"_"+region+".C");
  } 
}
