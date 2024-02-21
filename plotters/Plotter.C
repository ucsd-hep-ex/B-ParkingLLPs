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


void Plotter(TString region, bool dolog, TString inpath, TString aversion, TString signalName){

  //BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300to300_Fail_plots.root
  Ssiz_t pos1   = signalName.Index("PhiT");
  Ssiz_t pos2   = signalName.Last('_');
  Ssiz_t pos3   = signalName.Index("_ctau");
  Ssiz_t pos_ct = signalName.Index("to");
  Ssiz_t pos_m  = signalName.Index("mPhi");

  TString dl      = signalName(pos_ct+2,pos2-(pos_ct+2) );
  TString mass    = signalName(pos_m+4,pos3-(pos_m+4));
  mass.ReplaceAll("p", ".");
  TString sigName = signalName(pos1,pos2);
  std::cout<<"Short Name: "<<sigName<<std::endl;
  TString bkgName = "Parking_2018A_";

  TString sigpath = inpath+signalName+region+"_plots.root";
  TString bkgpath = inpath+bkgName+region+"_plots.root";

  TFile* sigFile = TFile::Open(sigpath);  
  TFile* bkgFile = TFile::Open(bkgpath);  
  std::cout<<sigpath<<std::endl;
  std::cout<<bkgpath<<std::endl;
  TH1F* h_sig;
  TH1F* h_bkg;

   // make canvas and text
  TCanvas* canvas = new TCanvas("canvas","canvas",900,100,500,500); 
  gStyle->SetOptStat(0);
  gPad->SetLogy(dolog);
  gPad->SetGrid();
  gPad->SetTickx();
  gPad->SetTicky();
  gStyle->SetLineWidth(3);
  gStyle->SetPalette(71); //kBlueGreenYellow

  std::vector<TString> variables;
  variables.clear();
//  variables.push_back("cscRechitClusterDPhiLeadMuon");
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
  variables.push_back("cscRechitClusterMuonVetoPt");
  variables.push_back("dtRechitClusterMuonVetoPt");
//  variables.push_back("dtRechitClusterDPhiLeadMuon");
//  variables.push_back("dtRechitClusterEta");
//  variables.push_back("dtRechitClusterSize");
  //variables.push_back("dtRechitClusterPhi");
  //variables.push_back("dtRechitCluster_match_RPCBx_dPhi0p5");
  //variables.push_back("cscRechitClusterTime");
  //variables.push_back("cscRechitClusterTimeTotal");
  //variables.push_back("cscRechitClusterTimeWeighted");
  //variables.push_back("nDTRechits");
  //variables.push_back("dtRechitCluster_match_RPCTime_dR0p4");
  //variables.push_back("dtRechitCluster_match_RPCTimeSpread_dR0p4");
  //variables.push_back("dtRechitCluster_match_RPChits_dR0p4");
  //variables.push_back("dtRechitCluster_match_RPCTime_dPhi0p5");
  //variables.push_back("dtRechitCluster_match_RPCTimeSpread_dPhi0p5");
  //variables.push_back("dtRechitCluster_match_RPCTime_sameStation_dR0p4");
  //variables.push_back("dtRechitCluster_match_RPCTimeSpread_sameStation_dR0p4");

  for (int i =0; i<variables.size(); i++){
  
  if(variables[i]=="nCscRechits"){
    h_sig = (TH1F*)sigFile->Get(variables[i])->Clone("h_sig");
    h_bkg = (TH1F*)bkgFile->Get(variables[i])->Clone("h_bkg");
  }
  else{
    h_sig = (TH1F*)sigFile->Get("h_"+variables[i])->Clone("h_sig");
    h_bkg = (TH1F*)bkgFile->Get("h_"+variables[i])->Clone("h_bkg");
  }
    std::cout<<"MaxSignal: "<<h_sig->GetMaximum()<<"    Maxbkg: "<<h_bkg->GetMaximum()<<std::endl;
    std::cout<<"Normalize to unity"<<std::endl;
    if (h_sig->GetEntries()>0) h_sig->Scale(1./h_sig->Integral());
    if (h_bkg->GetEntries()>0) h_bkg->Scale(1./h_bkg->Integral());
    std::cout<<"MaxSignal_: "<<h_sig->GetMaximum()<<"    Maxbkg_: "<<h_bkg->GetMaximum()<<std::endl;

    double ymax=0;
    ymax = max(h_sig->GetMaximum(), h_bkg->GetMaximum());   

    // legend
    TLegend *leg = new TLegend(0.15,0.8,0.85,0.9);
    leg->SetNColumns(2);
    leg->SetBorderSize(0);
    leg->SetFillColor(kWhite);
 
    canvas->Clear();

    h_sig->Draw("hist");
    h_bkg->Draw("hist sames");
    if(dolog)  {h_sig->SetMaximum(ymax*(4)); h_sig->SetMinimum(0.001);}
    else       h_sig->SetMaximum(ymax*(1.2));

    h_sig->SetTitle("");    
    h_sig->GetYaxis()->SetTitle("a.u.");
    h_sig->GetYaxis()->SetTitleOffset(1.5);
    h_sig->GetXaxis()->SetTitle(variables[i]);
    h_sig->SetLineColor(kRed);
    h_bkg->SetLineColor(kBlack);

    h_sig->SetLineWidth(2);
    h_bkg->SetLineWidth(2);

    if (sigName.Contains("PhiToPiPlusPiMinus")) leg->AddEntry(h_sig, "#Phi#rightarrow#pi^{+}#pi^{-}    m_{#Phi}="+mass+"GeV, c#tau_{#Phi}="+dl+"mm","l");
    else                                        leg->AddEntry(h_sig, "#Phi#rightarrow#pi^{0}#pi^{0}    m_{#Phi}="+mass+"GeV, c#tau_{#Phi}="+dl+"mm","l");
    leg->AddEntry(h_bkg, "Background","l");
    leg->Draw("sames");
    gPad->Update();
    gPad->RedrawAxis();

    if(dolog) canvas->SaveAs("plotDump/"+aversion+"/"+sigName+variables[i]+"_"+region+"_log.pdf");
    else canvas->SaveAs("plotDump/"+aversion+"/"+sigName+variables[i]+"_"+region+".pdf");
  } 
}
