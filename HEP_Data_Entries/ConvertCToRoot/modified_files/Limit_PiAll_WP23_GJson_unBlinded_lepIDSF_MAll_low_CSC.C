TFile * output_root = new TFile("./roots/Limit_PiAll_WP23_GJson_unBlinded_lepIDSF_MAll_low_CSC.root", "RECREATE");
void Limit_PiAll_WP23_GJson_unBlinded_lepIDSF_MAll_low_CSC()
{
//=========Macro generated from canvas: c/c
//=========  (Mon Feb 24 17:00:05 2025) by ROOT version 6.12/07
   TCanvas *c = new TCanvas("c", "c",0,0,800,700);
   c->SetHighLightColor(2);
   c->Range(0.5514414,-6.301154,3.908118,3.700087);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetLogx();
   c->SetLogy();
   c->SetLeftMargin(0.12);
   c->SetRightMargin(0.05);
   c->SetTopMargin(0.07);
   c->SetFrameBorderMode(0);
   c->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1[11] = {
   10,
   30,
   50,
   70,
   100,
   300,
   500,
   700,
   1000,
   3000,
   5000};
   Double_t Graph0_fy1[11] = {
   0.0003172897,
   8.543499e-05,
   6.694326e-05,
   6.31541e-05,
   6.477041e-05,
   0.0001185489,
   0.0001983882,
   0.0003061347,
   0.0005883572,
   0.01073414,
   0.0311178};
   TGraph *graph_1 = new TGraph(11,Graph0_fx1,Graph0_fy1);
   graph_1->SetName("Graph0");
   graph_1->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_1->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   graph_1->SetLineColor(ci);
   graph_1->SetLineStyle(7);
   graph_1->SetLineWidth(3);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,9,5499);
   Graph_Graph1->SetMinimum(5e-06);
   Graph_Graph1->SetMaximum(1000);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleOffset(0.95);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph_1->SetHistogram(Graph_Graph1);
   
   graph_1->Draw("al");
   
   Double_t Graph1_fx2[22] = {
   10,
   30,
   50,
   70,
   100,
   300,
   500,
   700,
   1000,
   3000,
   5000,
   5000,
   3000,
   1000,
   700,
   500,
   300,
   100,
   70,
   50,
   30,
   10};
   Double_t Graph1_fy2[22] = {
   0.0002184659,
   5.828289e-05,
   4.566801e-05,
   4.320547e-05,
   4.43478e-05,
   8.087286e-05,
   0.0001353385,
   0.0002096081,
   0.0004028437,
   0.007349586,
   0.02130612,
   0.04848297,
   0.01672429,
   0.0009166877,
   0.000476972,
   0.000309098,
   0.0001847046,
   0.000101948,
   9.940392e-05,
   0.000105368,
   0.0001334522,
   0.0004905577};
   TGraph *graph_2 = new TGraph(22,Graph1_fx2,Graph1_fy2);
   graph_2->SetName("Graph1");
   graph_2->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");

   ci = 1179;
   color = new TColor(ci, 0, 0, 0.6, " ", 0.15);
   graph_2->SetFillColor(ci);
   graph_2->SetFillStyle(3001);

   ci = TColor::GetColor("#000099");
   graph_2->SetLineColor(ci);
   graph_2->SetLineWidth(2);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","",100,9,5499);
   Graph_Graph2->SetMinimum(5e-06);
   Graph_Graph2->SetMaximum(1000);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph2->SetLineColor(ci);
   Graph_Graph2->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleOffset(0.95);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph_2->SetHistogram(Graph_Graph2);
   
   graph_2->Draw("f ");
   
   Double_t Graph2_fx3[11] = {
   10,
   30,
   50,
   70,
   100,
   300,
   500,
   700,
   1000,
   3000,
   5000};
   Double_t Graph2_fy3[11] = {
   0.0003536759,
   9.50798e-05,
   7.475889e-05,
   7.059815e-05,
   7.26108e-05,
   0.0001321365,
   0.0002211963,
   0.0003414205,
   0.0006557816,
   0.01197229,
   0.03471275};
   TGraph *graph_3 = new TGraph(11,Graph2_fx3,Graph2_fy3);
   graph_3->SetName("Graph2");
   graph_3->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_3->SetFillStyle(1000);

   ci = TColor::GetColor("#000099");
   graph_3->SetLineColor(ci);
   graph_3->SetLineWidth(3);

   ci = TColor::GetColor("#000099");
   graph_3->SetMarkerColor(ci);
   graph_3->SetMarkerStyle(31);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","",100,9,5499);
   Graph_Graph3->SetMinimum(5e-06);
   Graph_Graph3->SetMaximum(1000);
   Graph_Graph3->SetDirectory(0);
   Graph_Graph3->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3->SetLineColor(ci);
   Graph_Graph3->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph3->GetXaxis()->SetLabelFont(42);
   Graph_Graph3->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph3->GetXaxis()->SetTitleFont(42);
   Graph_Graph3->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph3->GetYaxis()->SetLabelFont(42);
   Graph_Graph3->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3->GetYaxis()->SetTitleOffset(0.95);
   Graph_Graph3->GetYaxis()->SetTitleFont(42);
   Graph_Graph3->GetZaxis()->SetLabelFont(42);
   Graph_Graph3->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3->GetZaxis()->SetTitleFont(42);
   graph_3->SetHistogram(Graph_Graph3);
   
   graph_3->Draw("l ");
   
   Double_t Graph3_fx4[11] = {
   10,
   30,
   50,
   70,
   100,
   300,
   500,
   700,
   1000,
   3000,
   5000};
   Double_t Graph3_fy4[11] = {
   0.05703913,
   0.001008817,
   0.0003711517,
   0.0002346617,
   0.000164174,
   0.0001031481,
   0.0001151119,
   0.0001371046,
   0.000178948,
   0.0006190363,
   0.001241078};
   TGraph *graph_4 = new TGraph(11,Graph3_fx4,Graph3_fy4);
   graph_4->SetName("Graph3");
   graph_4->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_4->SetFillStyle(1000);

   ci = TColor::GetColor("#009900");
   graph_4->SetLineColor(ci);
   graph_4->SetLineStyle(7);
   graph_4->SetLineWidth(3);
   
   TH1F *Graph_Graph4 = new TH1F("Graph_Graph4","",100,9,5499);
   Graph_Graph4->SetMinimum(5e-06);
   Graph_Graph4->SetMaximum(1000);
   Graph_Graph4->SetDirectory(0);
   Graph_Graph4->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph4->SetLineColor(ci);
   Graph_Graph4->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph4->GetXaxis()->SetLabelFont(42);
   Graph_Graph4->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph4->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph4->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph4->GetXaxis()->SetTitleFont(42);
   Graph_Graph4->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph4->GetYaxis()->SetLabelFont(42);
   Graph_Graph4->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph4->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph4->GetYaxis()->SetTitleOffset(0.95);
   Graph_Graph4->GetYaxis()->SetTitleFont(42);
   Graph_Graph4->GetZaxis()->SetLabelFont(42);
   Graph_Graph4->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph4->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph4->GetZaxis()->SetTitleFont(42);
   graph_4->SetHistogram(Graph_Graph4);
   
   graph_4->Draw("l");
   
   Double_t Graph4_fx5[22] = {
   10,
   30,
   50,
   70,
   100,
   300,
   500,
   700,
   1000,
   3000,
   5000,
   5000,
   3000,
   1000,
   700,
   500,
   300,
   100,
   70,
   50,
   30,
   10};
   Double_t Graph4_fy5[22] = {
   0.03905426,
   0.0006882048,
   0.0002508174,
   0.0001573912,
   0.0001092823,
   7.324371e-05,
   8.365707e-05,
   0.000100569,
   0.0001320703,
   0.0004624636,
   0.0009271724,
   0.001740724,
   0.0008707218,
   0.0002524173,
   0.0001944876,
   0.000163749,
   0.0001483749,
   0.0002525186,
   0.0003749674,
   0.0005930657,
   0.001575804,
   0.08841486};
   TGraph *graph_5 = new TGraph(22,Graph4_fx5,Graph4_fy5);
   graph_5->SetName("Graph4");
   graph_5->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");

   ci = 1181;
   color = new TColor(ci, 0, 0.6, 0, " ", 0.15);
   graph_5->SetFillColor(ci);
   graph_5->SetFillStyle(3001);

   ci = TColor::GetColor("#009900");
   graph_5->SetLineColor(ci);
   graph_5->SetLineWidth(2);
   
   TH1F *Graph_Graph5 = new TH1F("Graph_Graph5","",100,9,5499);
   Graph_Graph5->SetMinimum(5e-06);
   Graph_Graph5->SetMaximum(1000);
   Graph_Graph5->SetDirectory(0);
   Graph_Graph5->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph5->SetLineColor(ci);
   Graph_Graph5->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph5->GetXaxis()->SetLabelFont(42);
   Graph_Graph5->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph5->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph5->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph5->GetXaxis()->SetTitleFont(42);
   Graph_Graph5->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph5->GetYaxis()->SetLabelFont(42);
   Graph_Graph5->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph5->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph5->GetYaxis()->SetTitleOffset(0.95);
   Graph_Graph5->GetYaxis()->SetTitleFont(42);
   Graph_Graph5->GetZaxis()->SetLabelFont(42);
   Graph_Graph5->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph5->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph5->GetZaxis()->SetTitleFont(42);
   graph_5->SetHistogram(Graph_Graph5);
   
   graph_5->Draw("f ");
   
   Double_t Graph5_fx6[11] = {
   10,
   30,
   50,
   70,
   100,
   300,
   500,
   700,
   1000,
   3000,
   5000};
   Double_t Graph5_fy6[11] = {
   0.06363942,
   0.00112795,
   0.0004154644,
   0.0002631635,
   0.0001831637,
   0.0001117242,
   0.00012403,
   0.0001474669,
   0.0001925677,
   0.0006645272,
   0.001330453};
   TGraph *graph_6 = new TGraph(11,Graph5_fx6,Graph5_fy6);
   graph_6->SetName("Graph5");
   graph_6->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_6->SetFillStyle(1000);

   ci = TColor::GetColor("#009900");
   graph_6->SetLineColor(ci);
   graph_6->SetLineWidth(3);

   ci = TColor::GetColor("#009900");
   graph_6->SetMarkerColor(ci);
   graph_6->SetMarkerStyle(31);
   
   TH1F *Graph_Graph6 = new TH1F("Graph_Graph6","",100,9,5499);
   Graph_Graph6->SetMinimum(5e-06);
   Graph_Graph6->SetMaximum(1000);
   Graph_Graph6->SetDirectory(0);
   Graph_Graph6->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph6->SetLineColor(ci);
   Graph_Graph6->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph6->GetXaxis()->SetLabelFont(42);
   Graph_Graph6->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph6->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph6->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph6->GetXaxis()->SetTitleFont(42);
   Graph_Graph6->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph6->GetYaxis()->SetLabelFont(42);
   Graph_Graph6->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph6->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph6->GetYaxis()->SetTitleOffset(0.95);
   Graph_Graph6->GetYaxis()->SetTitleFont(42);
   Graph_Graph6->GetZaxis()->SetLabelFont(42);
   Graph_Graph6->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph6->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph6->GetZaxis()->SetTitleFont(42);
   graph_6->SetHistogram(Graph_Graph6);
   
   graph_6->Draw("l ");
   
   Double_t Graph6_fx7[10] = {
   30,
   50,
   70,
   100,
   300,
   500,
   700,
   1000,
   3000,
   5000};
   Double_t Graph6_fy7[10] = {
   1.368454,
   0.02525908,
   0.004358912,
   0.00115612,
   0.0001459238,
   0.0001004329,
   9.318849e-05,
   9.756832e-05,
   0.0002188991,
   0.0004130284};
   TGraph *graph_7 = new TGraph(10,Graph6_fx7,Graph6_fy7);
   graph_7->SetName("Graph6");
   graph_7->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_7->SetFillStyle(1000);

   ci = TColor::GetColor("#cc6600");
   graph_7->SetLineColor(ci);
   graph_7->SetLineStyle(7);
   graph_7->SetLineWidth(3);
   
   TH1F *Graph_Graph7 = new TH1F("Graph_Graph7","",100,27,5497);
   Graph_Graph7->SetMinimum(5e-06);
   Graph_Graph7->SetMaximum(1000);
   Graph_Graph7->SetDirectory(0);
   Graph_Graph7->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph7->SetLineColor(ci);
   Graph_Graph7->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph7->GetXaxis()->SetLabelFont(42);
   Graph_Graph7->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph7->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph7->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph7->GetXaxis()->SetTitleFont(42);
   Graph_Graph7->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph7->GetYaxis()->SetLabelFont(42);
   Graph_Graph7->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph7->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph7->GetYaxis()->SetTitleOffset(0.95);
   Graph_Graph7->GetYaxis()->SetTitleFont(42);
   Graph_Graph7->GetZaxis()->SetLabelFont(42);
   Graph_Graph7->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph7->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph7->GetZaxis()->SetTitleFont(42);
   graph_7->SetHistogram(Graph_Graph7);
   
   graph_7->Draw("l");
   
   Double_t Graph7_fx8[20] = {
   30,
   50,
   70,
   100,
   300,
   500,
   700,
   1000,
   3000,
   5000,
   5000,
   3000,
   1000,
   700,
   500,
   300,
   100,
   70,
   50,
   30};
   Double_t Graph7_fy8[20] = {
   0.9489977,
   0.0175167,
   0.00301205,
   0.0007960323,
   0.0001058447,
   7.480364e-05,
   6.98288e-05,
   7.355141e-05,
   0.0001655104,
   0.0003122922,
   0.0005727243,
   0.0003035355,
   0.0001352927,
   0.0001292195,
   0.0001400656,
   0.000205253,
   0.001801289,
   0.006669761,
   0.03844865,
   2.077568};
   TGraph *graph_8 = new TGraph(20,Graph7_fx8,Graph7_fy8);
   graph_8->SetName("Graph7");
   graph_8->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");

   ci = 1182;
   color = new TColor(ci, 0.8, 0.4, 0, " ", 0.15);
   graph_8->SetFillColor(ci);
   graph_8->SetFillStyle(3001);

   ci = TColor::GetColor("#cc6600");
   graph_8->SetLineColor(ci);
   graph_8->SetLineWidth(2);
   
   TH1F *Graph_Graph8 = new TH1F("Graph_Graph8","",100,27,5497);
   Graph_Graph8->SetMinimum(5e-06);
   Graph_Graph8->SetMaximum(1000);
   Graph_Graph8->SetDirectory(0);
   Graph_Graph8->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph8->SetLineColor(ci);
   Graph_Graph8->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph8->GetXaxis()->SetLabelFont(42);
   Graph_Graph8->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph8->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph8->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph8->GetXaxis()->SetTitleFont(42);
   Graph_Graph8->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph8->GetYaxis()->SetLabelFont(42);
   Graph_Graph8->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph8->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph8->GetYaxis()->SetTitleOffset(0.95);
   Graph_Graph8->GetYaxis()->SetTitleFont(42);
   Graph_Graph8->GetZaxis()->SetLabelFont(42);
   Graph_Graph8->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph8->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph8->GetZaxis()->SetTitleFont(42);
   graph_8->SetHistogram(Graph_Graph8);
   
   graph_8->Draw("f ");
   
   Double_t Graph8_fx9[10] = {
   30,
   50,
   70,
   100,
   300,
   500,
   700,
   1000,
   3000,
   5000};
   Double_t Graph8_fy9[10] = {
   1.522307,
   0.02820307,
   0.00486413,
   0.001291804,
   0.0001577994,
   0.0001078274,
   9.987608e-05,
   0.0001049573,
   0.0002350934,
   0.000443565};
   TGraph *graph_9 = new TGraph(10,Graph8_fx9,Graph8_fy9);
   graph_9->SetName("Graph8");
   graph_9->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_9->SetFillStyle(1000);

   ci = TColor::GetColor("#cc6600");
   graph_9->SetLineColor(ci);
   graph_9->SetLineWidth(3);

   ci = TColor::GetColor("#cc6600");
   graph_9->SetMarkerColor(ci);
   graph_9->SetMarkerStyle(31);
   
   TH1F *Graph_Graph9 = new TH1F("Graph_Graph9","",100,27,5497);
   Graph_Graph9->SetMinimum(5e-06);
   Graph_Graph9->SetMaximum(1000);
   Graph_Graph9->SetDirectory(0);
   Graph_Graph9->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph9->SetLineColor(ci);
   Graph_Graph9->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph9->GetXaxis()->SetLabelFont(42);
   Graph_Graph9->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph9->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph9->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph9->GetXaxis()->SetTitleFont(42);
   Graph_Graph9->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph9->GetYaxis()->SetLabelFont(42);
   Graph_Graph9->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph9->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph9->GetYaxis()->SetTitleOffset(0.95);
   Graph_Graph9->GetYaxis()->SetTitleFont(42);
   Graph_Graph9->GetZaxis()->SetLabelFont(42);
   Graph_Graph9->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph9->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph9->GetZaxis()->SetTitleFont(42);
   graph_9->SetHistogram(Graph_Graph9);
   
   graph_9->Draw("l ");
   
   Double_t Graph9_fx10[10] = {
   30,
   50,
   70,
   100,
   300,
   500,
   700,
   1000,
   3000,
   5000};
   Double_t Graph9_fy10[10] = {
   0.02322476,
   0.0024338,
   0.0008641638,
   0.0003782581,
   8.620069e-05,
   6.21875e-05,
   5.732605e-05,
   5.822656e-05,
   0.0001154539,
   0.000206472};
   TGraph *graph_10 = new TGraph(10,Graph9_fx10,Graph9_fy10);
   graph_10->SetName("Graph9");
   graph_10->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_10->SetFillStyle(1000);

   ci = TColor::GetColor("#990000");
   graph_10->SetLineColor(ci);
   graph_10->SetLineStyle(7);
   graph_10->SetLineWidth(3);
   
   TH1F *Graph_Graph10 = new TH1F("Graph_Graph10","",100,27,5497);
   Graph_Graph10->SetMinimum(5e-06);
   Graph_Graph10->SetMaximum(1000);
   Graph_Graph10->SetDirectory(0);
   Graph_Graph10->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph10->SetLineColor(ci);
   Graph_Graph10->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph10->GetXaxis()->SetLabelFont(42);
   Graph_Graph10->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph10->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph10->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph10->GetXaxis()->SetTitleFont(42);
   Graph_Graph10->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph10->GetYaxis()->SetLabelFont(42);
   Graph_Graph10->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph10->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph10->GetYaxis()->SetTitleOffset(0.95);
   Graph_Graph10->GetYaxis()->SetTitleFont(42);
   Graph_Graph10->GetZaxis()->SetLabelFont(42);
   Graph_Graph10->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph10->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph10->GetZaxis()->SetTitleFont(42);
   graph_10->SetHistogram(Graph_Graph10);
   
   graph_10->Draw("l");
   
   Double_t Graph10_fx11[20] = {
   30,
   50,
   70,
   100,
   300,
   500,
   700,
   1000,
   3000,
   5000,
   5000,
   3000,
   1000,
   700,
   500,
   300,
   100,
   70,
   50,
   30};
   Double_t Graph10_fy11[20] = {
   0.01636393,
   0.001714831,
   0.0006067713,
   0.0002655933,
   6.06388e-05,
   4.465172e-05,
   4.095117e-05,
   4.18077e-05,
   8.177398e-05,
   0.0001457427,
   0.0002887726,
   0.0001614743,
   8.097173e-05,
   7.949094e-05,
   8.647994e-05,
   0.0001205607,
   0.0005697428,
   0.001284404,
   0.003607649,
   0.03424118};
   TGraph *graph_11 = new TGraph(20,Graph10_fx11,Graph10_fy11);
   graph_11->SetName("Graph10");
   graph_11->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");

   ci = 1183;
   color = new TColor(ci, 0.6, 0, 0, " ", 0.15);
   graph_11->SetFillColor(ci);
   graph_11->SetFillStyle(3001);

   ci = TColor::GetColor("#990000");
   graph_11->SetLineColor(ci);
   graph_11->SetLineWidth(2);
   
   TH1F *Graph_Graph11 = new TH1F("Graph_Graph11","",100,27,5497);
   Graph_Graph11->SetMinimum(5e-06);
   Graph_Graph11->SetMaximum(1000);
   Graph_Graph11->SetDirectory(0);
   Graph_Graph11->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph11->SetLineColor(ci);
   Graph_Graph11->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph11->GetXaxis()->SetLabelFont(42);
   Graph_Graph11->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph11->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph11->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph11->GetXaxis()->SetTitleFont(42);
   Graph_Graph11->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph11->GetYaxis()->SetLabelFont(42);
   Graph_Graph11->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph11->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph11->GetYaxis()->SetTitleOffset(0.95);
   Graph_Graph11->GetYaxis()->SetTitleFont(42);
   Graph_Graph11->GetZaxis()->SetLabelFont(42);
   Graph_Graph11->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph11->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph11->GetZaxis()->SetTitleFont(42);
   graph_11->SetHistogram(Graph_Graph11);
   
   graph_11->Draw("f ");
   
   Double_t Graph11_fx12[10] = {
   30,
   50,
   70,
   100,
   300,
   500,
   700,
   1000,
   3000,
   5000};
   Double_t Graph11_fy12[10] = {
   0.02583109,
   0.002707741,
   0.0009616778,
   0.000422106,
   9.379203e-05,
   6.76664e-05,
   6.21451e-05,
   6.322936e-05,
   0.0001259123,
   0.0002250129};
   TGraph *graph_12 = new TGraph(10,Graph11_fx12,Graph11_fy12);
   graph_12->SetName("Graph11");
   graph_12->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_12->SetFillStyle(1000);

   ci = TColor::GetColor("#990000");
   graph_12->SetLineColor(ci);
   graph_12->SetLineWidth(3);

   ci = TColor::GetColor("#990000");
   graph_12->SetMarkerColor(ci);
   graph_12->SetMarkerStyle(31);
   
   TH1F *Graph_Graph12 = new TH1F("Graph_Graph12","",100,27,5497);
   Graph_Graph12->SetMinimum(5e-06);
   Graph_Graph12->SetMaximum(1000);
   Graph_Graph12->SetDirectory(0);
   Graph_Graph12->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph12->SetLineColor(ci);
   Graph_Graph12->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph12->GetXaxis()->SetLabelFont(42);
   Graph_Graph12->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph12->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph12->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph12->GetXaxis()->SetTitleFont(42);
   Graph_Graph12->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph12->GetYaxis()->SetLabelFont(42);
   Graph_Graph12->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph12->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph12->GetYaxis()->SetTitleOffset(0.95);
   Graph_Graph12->GetYaxis()->SetTitleFont(42);
   Graph_Graph12->GetZaxis()->SetLabelFont(42);
   Graph_Graph12->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph12->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph12->GetZaxis()->SetTitleFont(42);
   graph_12->SetHistogram(Graph_Graph12);
   
   graph_12->Draw("l ");
   
   TLegend *leg = new TLegend(0.15,0.75,0.5,0.92,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.05);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph0","M_{#Phi} = 0.3 GeV","l");

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph3","M_{#Phi} = 1.0 GeV","l");

   ci = TColor::GetColor("#009900");
   entry->SetLineColor(ci);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph6","M_{#Phi} = 2.0 GeV","l");

   ci = TColor::GetColor("#cc6600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph9","M_{#Phi} = 3.0 GeV","l");

   ci = TColor::GetColor("#990000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   leg = new TLegend(0.5,0.75,0.925,0.92,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.05);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("Graph1","#pm 1 s.d. expected","f");

   ci = 1179;
   color = new TColor(ci, 0, 0, 0.6, " ", 0.15);
   entry->SetFillColor(ci);
   entry->SetFillStyle(3001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph4","#pm 1 s.d. expected","f");

   ci = 1181;
   color = new TColor(ci, 0, 0.6, 0, " ", 0.15);
   entry->SetFillColor(ci);
   entry->SetFillStyle(3001);

   ci = TColor::GetColor("#009900");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph7","#pm 1 s.d. expected","f");

   ci = 1182;
   color = new TColor(ci, 0.8, 0.4, 0, " ", 0.15);
   entry->SetFillColor(ci);
   entry->SetFillStyle(3001);

   ci = TColor::GetColor("#cc6600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph10","#pm 1 s.d. expected","f");

   ci = 1183;
   color = new TColor(ci, 0.6, 0, 0, " ", 0.15);
   entry->SetFillColor(ci);
   entry->SetFillStyle(3001);

   ci = TColor::GetColor("#990000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   leg = new TLegend(0.5,0.65,0.925,0.75,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("Graph","Observed limit","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","Median expected limit","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.2,0.7,"#Phi #rightarrow #pi^{+}#pi^{-}   ");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.955,0.945,"41.6 fb^{-1} (13 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.25,0.94,"CMS");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(61);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.45,0.94,"Preliminary");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(52);
   tex->SetTextSize(0.0456);
   tex->SetLineWidth(2);
   tex->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
   c->SaveAs("Limit_PiAll_WP23_GJson_unBlinded_lepIDSF_MAll_low_CSC.pdf");
   c->SaveAs("Limit_PiAll_WP23_GJson_unBlinded_lepIDSF_MAll_low_CSC.png");

Graph_Graph1->Write();
Graph_Graph2->Write();
Graph_Graph3->Write();
Graph_Graph4->Write();
Graph_Graph5->Write();
Graph_Graph6->Write();
Graph_Graph7->Write();
Graph_Graph8->Write();
Graph_Graph9->Write();
Graph_Graph10->Write();
Graph_Graph11->Write();
Graph_Graph12->Write();
graph_1->Write();
graph_2->Write();
graph_3->Write();
graph_4->Write();
graph_5->Write();
graph_6->Write();
graph_7->Write();
graph_8->Write();
graph_9->Write();
graph_10->Write();
graph_11->Write();
graph_12->Write();

}