void Limit_PiAll_WP23_GJson_unBlinded_lepIDSF_moreStats1_MAll_low_CSC()
{
//=========Macro generated from canvas: c/c
//=========  (Wed Apr 23 18:29:54 2025) by ROOT version 6.12/07
   TCanvas *c = new TCanvas("c", "c",0,0,800,700);
   c->SetHighLightColor(2);
   c->Range(0.5514414,-6.530812,3.908118,3.717373);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetLogx();
   c->SetLogy();
   c->SetLeftMargin(0.12);
   c->SetRightMargin(0.05);
   c->SetTopMargin(0.07);
   c->SetBottomMargin(0.12);
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
   0.0006002522,
   0.0001608894,
   0.000126644,
   0.0001194762,
   0.0001225342,
   0.0002232584,
   0.000373615,
   0.0005791513,
   0.001113067,
   0.02030707,
   0.05886922};
   TGraph *graph = new TGraph(11,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   graph->SetLineColor(ci);
   graph->SetLineStyle(7);
   graph->SetLineWidth(3);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,9,5499);
   Graph_Graph1->SetMinimum(5e-06);
   Graph_Graph1->SetMaximum(1000);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   graph->Draw("al");
   
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
   0.0004132962,
   0.0001101598,
   8.639528e-05,
   8.150543e-05,
   8.389821e-05,
   0.0001528633,
   0.0002558113,
   0.0003950912,
   0.0007593228,
   0.01390409,
   0.04030731,
   0.09172095,
   0.03163935,
   0.001734209,
   0.0009023443,
   0.0005850879,
   0.0003496267,
   0.0001928676,
   0.0001880543,
   0.0001988317,
   0.0002525971,
   0.0009280426};
   graph = new TGraph(22,Graph1_fx2,Graph1_fy2);
   graph->SetName("Graph1");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");

   ci = 1179;
   color = new TColor(ci, 0, 0, 0.6, " ", 0.15);
   graph->SetFillColor(ci);
   graph->SetFillStyle(3001);

   ci = TColor::GetColor("#000099");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);
   
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
   Graph_Graph2->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph2);
   
   graph->Draw("f ");
   
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
   0.000668774,
   0.0001798368,
   0.0001414013,
   0.0001335428,
   0.0001373624,
   0.0002498728,
   0.000418239,
   0.0006455383,
   0.001239876,
   0.022633,
   0.06562061};
   graph = new TGraph(11,Graph2_fx3,Graph2_fy3);
   graph->SetName("Graph2");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#000099");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);

   ci = TColor::GetColor("#000099");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(31);
   
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
   Graph_Graph3->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph3->GetXaxis()->SetTitleFont(42);
   Graph_Graph3->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph3->GetYaxis()->SetLabelFont(42);
   Graph_Graph3->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph3->GetYaxis()->SetTitleFont(42);
   Graph_Graph3->GetZaxis()->SetLabelFont(42);
   Graph_Graph3->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph3);
   
   graph->Draw("l ");
   
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
   0.01967416,
   0.0006860281,
   0.0003560107,
   0.000277976,
   0.0002388459,
   0.0002829087,
   0.0004041625,
   0.0005527474,
   0.0008205996,
   0.003280295,
   0.00611186};
   graph = new TGraph(11,Graph3_fx4,Graph3_fy4);
   graph->SetName("Graph3");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph->SetFillStyle(1000);
   graph->SetLineStyle(7);
   graph->SetLineWidth(3);
   
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
   Graph_Graph4->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph4->GetXaxis()->SetTitleFont(42);
   Graph_Graph4->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph4->GetYaxis()->SetLabelFont(42);
   Graph_Graph4->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph4->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph4->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph4->GetYaxis()->SetTitleFont(42);
   Graph_Graph4->GetZaxis()->SetLabelFont(42);
   Graph_Graph4->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph4->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph4->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph4);
   
   graph->Draw("l");
   
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
   0.0138382,
   0.0004816936,
   0.0002486469,
   0.0001941454,
   0.0001697462,
   0.0002084431,
   0.0003001124,
   0.0004129412,
   0.0006130456,
   0.002446907,
   0.004579792,
   0.008231367,
   0.004417855,
   0.001108443,
   0.0007488388,
   0.0005459313,
   0.0003832728,
   0.0003330989,
   0.0003932105,
   0.000516366,
   0.001016907,
   0.02884954};
   graph = new TGraph(22,Graph4_fx5,Graph4_fy5);
   graph->SetName("Graph4");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");

   ci = 1180;
   color = new TColor(ci, 0, 0, 0, " ", 0.15);
   graph->SetFillColor(ci);
   graph->SetFillStyle(3001);
   graph->SetLineWidth(2);
   
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
   Graph_Graph5->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph5->GetXaxis()->SetTitleFont(42);
   Graph_Graph5->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph5->GetYaxis()->SetLabelFont(42);
   Graph_Graph5->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph5->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph5->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph5->GetYaxis()->SetTitleFont(42);
   Graph_Graph5->GetZaxis()->SetLabelFont(42);
   Graph_Graph5->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph5->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph5->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph5);
   
   graph->Draw("f ");
   
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
   0.02183975,
   0.0007619421,
   0.0003958592,
   0.0003055383,
   0.0002612527,
   0.0003054511,
   0.0004359172,
   0.0005977039,
   0.0008862863,
   0.003528967,
   0.006585723};
   graph = new TGraph(11,Graph5_fx6,Graph5_fy6);
   graph->SetName("Graph5");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(31);
   
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
   Graph_Graph6->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph6->GetXaxis()->SetTitleFont(42);
   Graph_Graph6->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph6->GetYaxis()->SetLabelFont(42);
   Graph_Graph6->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph6->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph6->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph6->GetYaxis()->SetTitleFont(42);
   Graph_Graph6->GetZaxis()->SetLabelFont(42);
   Graph_Graph6->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph6->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph6->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph6);
   
   graph->Draw("l ");
   
   Double_t Graph6_fx7[11] = {
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
   Double_t Graph6_fy7[11] = {
   0.1664581,
   0.002071886,
   0.0006468635,
   0.0003736491,
   0.0002435492,
   0.0001411403,
   0.0001543727,
   0.000181932,
   0.0002353223,
   0.0008007414,
   0.001596478};
   graph = new TGraph(11,Graph6_fx7,Graph6_fy7);
   graph->SetName("Graph6");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#009900");
   graph->SetLineColor(ci);
   graph->SetLineStyle(7);
   graph->SetLineWidth(3);
   
   TH1F *Graph_Graph7 = new TH1F("Graph_Graph7","",100,9,5499);
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
   Graph_Graph7->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph7->GetXaxis()->SetTitleFont(42);
   Graph_Graph7->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph7->GetYaxis()->SetLabelFont(42);
   Graph_Graph7->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph7->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph7->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph7->GetYaxis()->SetTitleFont(42);
   Graph_Graph7->GetZaxis()->SetLabelFont(42);
   Graph_Graph7->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph7->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph7->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph7);
   
   graph->Draw("l");
   
   Double_t Graph7_fx8[22] = {
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
   Double_t Graph7_fy8[22] = {
   0.118702,
   0.0014573,
   0.0004541942,
   0.0002632694,
   0.0001739807,
   0.0001043132,
   0.0001149786,
   0.0001355052,
   0.0001752708,
   0.0005936404,
   0.001183571,
   0.00214375,
   0.001075235,
   0.0003169286,
   0.0002450235,
   0.000207907,
   0.0001906484,
   0.0003357751,
   0.0005240766,
   0.0009227552,
   0.003029886,
   0.2427616};
   graph = new TGraph(22,Graph7_fx8,Graph7_fy8);
   graph->SetName("Graph7");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");

   ci = 1181;
   color = new TColor(ci, 0, 0.6, 0, " ", 0.15);
   graph->SetFillColor(ci);
   graph->SetFillStyle(3001);

   ci = TColor::GetColor("#009900");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Graph8 = new TH1F("Graph_Graph8","",100,9,5499);
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
   Graph_Graph8->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph8->GetXaxis()->SetTitleFont(42);
   Graph_Graph8->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph8->GetYaxis()->SetLabelFont(42);
   Graph_Graph8->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph8->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph8->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph8->GetYaxis()->SetTitleFont(42);
   Graph_Graph8->GetZaxis()->SetLabelFont(42);
   Graph_Graph8->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph8->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph8->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph8);
   
   graph->Draw("f ");
   
   Double_t Graph8_fx9[11] = {
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
   Double_t Graph8_fy9[11] = {
   0.1848544,
   0.002292073,
   0.0007148146,
   0.0004114395,
   0.0002661194,
   0.0001526439,
   0.0001667114,
   0.0001963318,
   0.0002537136,
   0.000862858,
   0.001721018};
   graph = new TGraph(11,Graph8_fx9,Graph8_fy9);
   graph->SetName("Graph8");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#009900");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);

   ci = TColor::GetColor("#009900");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(31);
   
   TH1F *Graph_Graph9 = new TH1F("Graph_Graph9","",100,9,5499);
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
   Graph_Graph9->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph9->GetXaxis()->SetTitleFont(42);
   Graph_Graph9->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph9->GetYaxis()->SetLabelFont(42);
   Graph_Graph9->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph9->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph9->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph9->GetYaxis()->SetTitleFont(42);
   Graph_Graph9->GetZaxis()->SetLabelFont(42);
   Graph_Graph9->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph9->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph9->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph9);
   
   graph->Draw("l ");
   
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
   0.2023736,
   0.015227,
   0.00362437,
   0.001071358,
   0.0001663627,
   0.0001261876,
   0.0001217081,
   0.0001312999,
   0.0003060026,
   0.000581385};
   graph = new TGraph(10,Graph9_fx10,Graph9_fy10);
   graph->SetName("Graph9");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#cc6600");
   graph->SetLineColor(ci);
   graph->SetLineStyle(7);
   graph->SetLineWidth(3);
   
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
   Graph_Graph10->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph10->GetXaxis()->SetTitleFont(42);
   Graph_Graph10->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph10->GetYaxis()->SetLabelFont(42);
   Graph_Graph10->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph10->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph10->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph10->GetYaxis()->SetTitleFont(42);
   Graph_Graph10->GetZaxis()->SetLabelFont(42);
   Graph_Graph10->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph10->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph10->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph10);
   
   graph->Draw("l");
   
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
   0.155214,
   0.01225483,
   0.002670384,
   0.0007574835,
   0.0001182328,
   8.998491e-05,
   8.752229e-05,
   9.473242e-05,
   0.0002215082,
   0.0004229093,
   0.0007922707,
   0.0004169989,
   0.0001794496,
   0.0001668256,
   0.0001734686,
   0.0002320124,
   0.001515488,
   0.004881249,
   0.01977916,
   0.2854605};
   graph = new TGraph(20,Graph10_fx11,Graph10_fy11);
   graph->SetName("Graph10");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");

   ci = 1182;
   color = new TColor(ci, 0.8, 0.4, 0, " ", 0.15);
   graph->SetFillColor(ci);
   graph->SetFillStyle(3001);

   ci = TColor::GetColor("#cc6600");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);
   
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
   Graph_Graph11->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph11->GetXaxis()->SetTitleFont(42);
   Graph_Graph11->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph11->GetYaxis()->SetLabelFont(42);
   Graph_Graph11->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph11->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph11->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph11->GetYaxis()->SetTitleFont(42);
   Graph_Graph11->GetZaxis()->SetLabelFont(42);
   Graph_Graph11->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph11->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph11->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph11);
   
   graph->Draw("f ");
   
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
   0.2045836,
   0.01601839,
   0.00392075,
   0.001183498,
   0.0001826452,
   0.0001377785,
   0.0001326645,
   0.0001430053,
   0.0003329556,
   0.0006326704};
   graph = new TGraph(10,Graph11_fx12,Graph11_fy12);
   graph->SetName("Graph11");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#cc6600");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);

   ci = TColor::GetColor("#cc6600");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(31);
   
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
   Graph_Graph12->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph12->GetXaxis()->SetTitleFont(42);
   Graph_Graph12->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph12->GetYaxis()->SetLabelFont(42);
   Graph_Graph12->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph12->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph12->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph12->GetYaxis()->SetTitleFont(42);
   Graph_Graph12->GetZaxis()->SetLabelFont(42);
   Graph_Graph12->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph12->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph12->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph12);
   
   graph->Draw("l ");
   
   Double_t Graph12_fx13[10] = {
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
   Double_t Graph12_fy13[10] = {
   0.05403179,
   0.004617276,
   0.001413257,
   0.0005333889,
   9.23523e-05,
   6.664115e-05,
   6.180299e-05,
   6.392173e-05,
   0.0001324089,
   0.0002389212};
   graph = new TGraph(10,Graph12_fx13,Graph12_fy13);
   graph->SetName("Graph12");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#990000");
   graph->SetLineColor(ci);
   graph->SetLineStyle(7);
   graph->SetLineWidth(3);
   
   TH1F *Graph_Graph13 = new TH1F("Graph_Graph13","",100,27,5497);
   Graph_Graph13->SetMinimum(5e-06);
   Graph_Graph13->SetMaximum(1000);
   Graph_Graph13->SetDirectory(0);
   Graph_Graph13->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph13->SetLineColor(ci);
   Graph_Graph13->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph13->GetXaxis()->SetLabelFont(42);
   Graph_Graph13->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph13->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph13->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph13->GetXaxis()->SetTitleFont(42);
   Graph_Graph13->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph13->GetYaxis()->SetLabelFont(42);
   Graph_Graph13->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph13->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph13->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph13->GetYaxis()->SetTitleFont(42);
   Graph_Graph13->GetZaxis()->SetLabelFont(42);
   Graph_Graph13->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph13->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph13->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph13);
   
   graph->Draw("l");
   
   Double_t Graph13_fx14[20] = {
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
   Double_t Graph13_fy14[20] = {
   0.03892109,
   0.003314863,
   0.001014614,
   0.0003810292,
   6.607947e-05,
   4.784342e-05,
   4.473776e-05,
   4.649775e-05,
   9.647813e-05,
   0.0001749182,
   0.0003208233,
   0.0001777987,
   8.659846e-05,
   8.422078e-05,
   9.134516e-05,
   0.0001287962,
   0.0007608827,
   0.002016021,
   0.00656817,
   0.07664596};
   graph = new TGraph(20,Graph13_fx14,Graph13_fy14);
   graph->SetName("Graph13");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");

   ci = 1183;
   color = new TColor(ci, 0.6, 0, 0, " ", 0.15);
   graph->SetFillColor(ci);
   graph->SetFillStyle(3001);

   ci = TColor::GetColor("#990000");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Graph14 = new TH1F("Graph_Graph14","",100,27,5497);
   Graph_Graph14->SetMinimum(5e-06);
   Graph_Graph14->SetMaximum(1000);
   Graph_Graph14->SetDirectory(0);
   Graph_Graph14->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph14->SetLineColor(ci);
   Graph_Graph14->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph14->GetXaxis()->SetLabelFont(42);
   Graph_Graph14->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph14->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph14->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph14->GetXaxis()->SetTitleFont(42);
   Graph_Graph14->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph14->GetYaxis()->SetLabelFont(42);
   Graph_Graph14->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph14->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph14->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph14->GetYaxis()->SetTitleFont(42);
   Graph_Graph14->GetZaxis()->SetLabelFont(42);
   Graph_Graph14->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph14->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph14->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph14);
   
   graph->Draw("f ");
   
   Double_t Graph14_fx15[10] = {
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
   Double_t Graph14_fy15[10] = {
   0.05979341,
   0.005109714,
   0.00156546,
   0.0005887498,
   0.0001020955,
   7.303566e-05,
   6.747978e-05,
   6.981315e-05,
   0.0001438197,
   0.0002596491};
   graph = new TGraph(10,Graph14_fx15,Graph14_fy15);
   graph->SetName("Graph14");
   graph->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#990000");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);

   ci = TColor::GetColor("#990000");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(31);
   
   TH1F *Graph_Graph15 = new TH1F("Graph_Graph15","",100,27,5497);
   Graph_Graph15->SetMinimum(5e-06);
   Graph_Graph15->SetMaximum(1000);
   Graph_Graph15->SetDirectory(0);
   Graph_Graph15->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph15->SetLineColor(ci);
   Graph_Graph15->GetXaxis()->SetTitle("#Phi proper decay length [mm]");
   Graph_Graph15->GetXaxis()->SetLabelFont(42);
   Graph_Graph15->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph15->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph15->GetXaxis()->SetTitleOffset(0.95);
   Graph_Graph15->GetXaxis()->SetTitleFont(42);
   Graph_Graph15->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph15->GetYaxis()->SetLabelFont(42);
   Graph_Graph15->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph15->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph15->GetYaxis()->SetTitleOffset(1.2);
   Graph_Graph15->GetYaxis()->SetTitleFont(42);
   Graph_Graph15->GetZaxis()->SetLabelFont(42);
   Graph_Graph15->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph15->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph15->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph15);
   
   graph->Draw("l ");
   
   TLegend *leg = new TLegend(0.15,0.7,0.5,0.92,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.055);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph0","m_{#Phi} = 0.3 GeV","l");

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph3","m_{#Phi} = 0.5 GeV","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph6","m_{#Phi} = 1.0 GeV","l");

   ci = TColor::GetColor("#009900");
   entry->SetLineColor(ci);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph9","m_{#Phi} = 2.0 GeV","l");

   ci = TColor::GetColor("#cc6600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph12","m_{#Phi} = 3.0 GeV","l");

   ci = TColor::GetColor("#990000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   leg = new TLegend(0.5,0.7,0.925,0.92,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.055);
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

   ci = 1180;
   color = new TColor(ci, 0, 0, 0, " ", 0.15);
   entry->SetFillColor(ci);
   entry->SetFillStyle(3001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph7","#pm 1 s.d. expected","f");

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
   entry=leg->AddEntry("Graph10","#pm 1 s.d. expected","f");

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
   entry=leg->AddEntry("Graph13","#pm 1 s.d. expected","f");

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
   
   leg = new TLegend(0.4,0.59,0.925,0.69,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.054);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("Graph5","Observed limit","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph3","Median expected limit","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.955,0.94,"41.6 fb^{-1} (13 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.215,0.94,"CMS");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(61);
   tex->SetTextSize(0.055);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.455,0.94,"");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(52);
   tex->SetTextSize(0.055);
   tex->SetLineWidth(2);
   tex->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
   c->SaveAs("Lim.pdf");
}
