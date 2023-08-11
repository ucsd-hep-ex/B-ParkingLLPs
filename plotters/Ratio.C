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


void Ratio(bool dolog, TString inpath1, TString inpath2, TString var, TString aversion){

 TFile* f1 = TFile::Open(inpath1);
 TFile* f2 = TFile::Open(inpath2);

 Ssiz_t length1 = inpath1.Last('.') - inpath1.Last('/')-7;
 Ssiz_t length2 = inpath2.Last('.') - inpath2.Last('/')-7;
 TString name1 = inpath1(inpath1.Last('/')+1, length1);
 TString name2 = inpath2(inpath2.Last('/')+1, length2);

 TH1F* h_r;
 TH1F* h_1 = (TH1F*) f1->Get(var)->Clone("h_1");//name1+"-"+var);
 TH1F* h_2 = (TH1F*) f2->Get(var)->Clone("h_2");//name2+"-"+var);

  // canvas and text attributes
 int canx = 1100;
 int cany = 1200;
 //int cany = 900;
 float lmarg = 0.12;
 float rmarg = 0.05;

 TCanvas* canvas = new TCanvas("canvas","canvas",canx,cany); 

 gStyle->SetOptStat(0);
 gPad->SetLogy(dolog);
 gPad->SetTickx();
 gPad->SetTicky();
 gStyle->SetLineWidth(3);
 gStyle->SetPalette(kBird);

 canvas->Clear();
 canvas->cd();

 //float pad_bottom = 0;
 float pad_bottom = 0.25;
 TPad *plotpad  = new TPad("plotpad", "plotpad", 0, pad_bottom, 1, 1);
 //plotpad->SetBottomMargin(0.12);
 plotpad->SetBottomMargin(0.04);
 plotpad->SetLeftMargin(lmarg);
 plotpad->SetRightMargin(rmarg);
 plotpad->SetFrameLineWidth(3);
 plotpad->SetLogy(dolog);
 plotpad->Draw();

 canvas->cd();
 TPad *ratiopad = new TPad("ratiopad", "ratiopad", 0, 0, 1, 0.25);
 ratiopad->SetTopMargin(0.04);
 ratiopad->SetBottomMargin(0.4);
 ratiopad->SetFrameLineWidth(3);
 ratiopad->SetLeftMargin(lmarg);
 ratiopad->SetRightMargin(rmarg);
 ratiopad->SetLogy(0);
 ratiopad->SetGrid();
 ratiopad->Draw();
 canvas->cd(); 

 plotpad->cd();

 // make legend
 TLegend *leg;
 leg = new TLegend(0.3,0.65,0.88,0.89);
 leg->SetBorderSize(0);
 leg->SetNColumns(1);
 leg->SetFillColor(kWhite);


 h_1->SetLineColor(kBlack);
 h_2->SetLineColor(kRed);

 if(dolog) h_1->SetMaximum(10*h_1->GetMaximum());
 else h_1->SetMaximum(1.5*h_1->GetMaximum());

 h_1->Draw("hist");
 h_2->Draw("hist sames");

 leg->AddEntry(h_1, "h_1 = "+name1, "l");
 leg->AddEntry(h_2, "h_2 = "+name2, "l");

 leg->Draw("sames");

 h_r = (TH1F*) h_1->Clone("ratio");
 if(h_2->Integral(-1,-1)>0) h_r->Divide(h_2);
 ratiopad->cd();
 h_r->SetTitle("");
 h_r->GetYaxis()->SetTitleSize(40);
 h_r->GetYaxis()->SetTitleFont(43);
 h_r->GetYaxis()->SetTitleOffset(1.55);
 h_r->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
 h_r->GetYaxis()->SetLabelSize(20);
 h_r->GetYaxis()->SetNdivisions(-105);
 h_r->GetYaxis()->SetTitle("h1/h2");
 // Xaxis ratio plot settings
 h_r->GetXaxis()->SetTitleSize(40);
 h_r->GetXaxis()->SetTitleFont(43);
 h_r->GetXaxis()->SetTitleOffset(4.0);
 h_r->GetXaxis()->SetLabelFont(43); //43 Absolute font size in pixel (precision 3)
 h_r->GetXaxis()->SetLabelSize(30);//20
 h_r->SetMarkerStyle(20);
 h_r->SetMarkerSize(1.5); 

 h_r->GetYaxis()->SetRangeUser(0.0,2.0);
 h_r->Draw("ep");

 if(dolog) canvas->SaveAs("plotDump/"+aversion+"/"+name1+"-"+name2+"-"+var+"-ratio_log.pdf");
 else canvas->SaveAs("plotDump/"+aversion+"/"+name1+"-"+name2+"-"+var+"-ratio.pdf"); 
}

