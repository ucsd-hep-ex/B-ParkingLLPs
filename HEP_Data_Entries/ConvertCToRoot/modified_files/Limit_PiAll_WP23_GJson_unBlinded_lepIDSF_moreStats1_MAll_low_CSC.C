TFile * output_root = new TFile("./roots/Limit_PiAll_WP23_GJson_unBlinded_lepIDSF_moreStats1_MAll_low_CSC.root", "RECREATE");
void Limit_PiAll_WP23_GJson_unBlinded_lepIDSF_moreStats1_MAll_low_CSC()
{
//=========Macro generated from canvas: c/c
//=========  (Mon Jun 23 11:07:37 2025) by ROOT version 6.12/07
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
   0.0001616275,
   0.000126644,
   0.0001200192,
   0.0001230911,
   0.000225288,
   0.0003770115,
   0.0005830821,
   0.00112314,
   0.02049084,
   0.05940197};
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
   0.0004132962,
   0.0001102606,
   8.639528e-05,
   8.187591e-05,
   8.397154e-05,
   0.000154253,
   0.0002581369,
   0.0003992319,
   0.0007690051,
   0.01402992,
   0.04067208,
   0.08947288,
   0.03086387,
   0.001691704,
   0.0008782543,
   0.0005889041,
   0.0003510091,
   0.0001932536,
   0.0001884307,
   0.0001993365,
   0.0002524673,
   0.0009280426};
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
   0.0006687911,
   0.0001799267,
   0.0001416188,
   0.0001339579,
   0.0001376196,
   0.0002511624,
   0.0004210383,
   0.0006502894,
   0.001250377,
   0.0229338,
   0.06651305};
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
   0.01967416,
   0.0006860281,
   0.0003560107,
   0.000277976,
   0.0002388459,
   0.0002829087,
   0.0004041625,
   0.0005549853,
   0.0008205996,
   0.003280295,
   0.00611186};
   TGraph *graph_4 = new TGraph(11,Graph3_fx4,Graph3_fy4);
   graph_4->SetName("Graph3");
   graph_4->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_4->SetFillStyle(1000);
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
   0.0138382,
   0.0004816936,
   0.0002486469,
   0.0001941454,
   0.0001697462,
   0.0002084431,
   0.0003001124,
   0.0004133597,
   0.0006130456,
   0.002446907,
   0.004579792,
   0.008231367,
   0.004417855,
   0.001108443,
   0.0007474462,
   0.0005459313,
   0.0003844005,
   0.0003330989,
   0.0003932105,
   0.000516366,
   0.001016907,
   0.02884954};
   TGraph *graph_5 = new TGraph(22,Graph4_fx5,Graph4_fy5);
   graph_5->SetName("Graph4");
   graph_5->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");

   ci = 1180;
   color = new TColor(ci, 0, 0, 0, " ", 0.15);
   graph_5->SetFillColor(ci);
   graph_5->SetFillStyle(3001);
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
   0.02184263,
   0.0007620427,
   0.0003959148,
   0.0003055837,
   0.0002612939,
   0.0003055053,
   0.0004359933,
   0.0005978195,
   0.0008864416,
   0.003528967,
   0.006585723};
   TGraph *graph_6 = new TGraph(11,Graph5_fx6,Graph5_fy6);
   graph_6->SetName("Graph5");
   graph_6->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_6->SetFillStyle(1000);
   graph_6->SetLineWidth(3);
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
   graph_6->SetHistogram(Graph_Graph6);
   
   graph_6->Draw("l ");
   
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
   0.1668904,
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
   TGraph *graph_7 = new TGraph(11,Graph6_fx7,Graph6_fy7);
   graph_7->SetName("Graph6");
   graph_7->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_7->SetFillStyle(1000);

   ci = TColor::GetColor("#009900");
   graph_7->SetLineColor(ci);
   graph_7->SetLineStyle(7);
   graph_7->SetLineWidth(3);
   
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
   graph_7->SetHistogram(Graph_Graph7);
   
   graph_7->Draw("l");
   
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
   0.1184042,
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
   0.002150114,
   0.001075235,
   0.0003169286,
   0.0002450235,
   0.000207907,
   0.0001912109,
   0.0003367458,
   0.0005240766,
   0.0009227552,
   0.003038145,
   0.2420617};
   TGraph *graph_8 = new TGraph(22,Graph7_fx8,Graph7_fy8);
   graph_8->SetName("Graph7");
   graph_8->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");

   ci = 1181;
   color = new TColor(ci, 0, 0.6, 0, " ", 0.15);
   graph_8->SetFillColor(ci);
   graph_8->SetFillStyle(3001);

   ci = TColor::GetColor("#009900");
   graph_8->SetLineColor(ci);
   graph_8->SetLineWidth(2);
   
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
   graph_8->SetHistogram(Graph_Graph8);
   
   graph_8->Draw("f ");
   
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
   0.1848805,
   0.00229242,
   0.0007149164,
   0.0004114896,
   0.0002661638,
   0.0001526714,
   0.0001667422,
   0.0001963669,
   0.0002537562,
   0.0008630107,
   0.001721335};
   TGraph *graph_9 = new TGraph(11,Graph8_fx9,Graph8_fy9);
   graph_9->SetName("Graph8");
   graph_9->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_9->SetFillStyle(1000);

   ci = TColor::GetColor("#009900");
   graph_9->SetLineColor(ci);
   graph_9->SetLineWidth(3);

   ci = TColor::GetColor("#009900");
   graph_9->SetMarkerColor(ci);
   graph_9->SetMarkerStyle(31);
   
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
   0.2023736,
   0.015227,
   0.00362437,
   0.001073687,
   0.0001663627,
   0.0001261876,
   0.0001217081,
   0.0001312999,
   0.0003060026,
   0.000581385};
   TGraph *graph_10 = new TGraph(10,Graph9_fx10,Graph9_fy10);
   graph_10->SetName("Graph9");
   graph_10->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_10->SetFillStyle(1000);

   ci = TColor::GetColor("#cc6600");
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
   0.155214,
   0.01225483,
   0.002670384,
   0.0007591302,
   0.0001180298,
   9.028913e-05,
   8.737744e-05,
   9.504496e-05,
   0.0002222366,
   0.0004222351,
   0.0007922707,
   0.0004169989,
   0.0001794496,
   0.0001668256,
   0.0001739716,
   0.0002320124,
   0.001514503,
   0.004881249,
   0.01977916,
   0.2854605};
   TGraph *graph_11 = new TGraph(20,Graph10_fx11,Graph10_fy11);
   graph_11->SetName("Graph10");
   graph_11->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");

   ci = 1182;
   color = new TColor(ci, 0.8, 0.4, 0, " ", 0.15);
   graph_11->SetFillColor(ci);
   graph_11->SetFillStyle(3001);

   ci = TColor::GetColor("#cc6600");
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
   0.2052437,
   0.01605241,
   0.003920934,
   0.001185631,
   0.0001830231,
   0.0001377936,
   0.0001326833,
   0.000143025,
   0.0003335654,
   0.0006330129};
   TGraph *graph_12 = new TGraph(10,Graph11_fx12,Graph11_fy12);
   graph_12->SetName("Graph11");
   graph_12->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_12->SetFillStyle(1000);

   ci = TColor::GetColor("#cc6600");
   graph_12->SetLineColor(ci);
   graph_12->SetLineWidth(3);

   ci = TColor::GetColor("#cc6600");
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
   graph_12->SetHistogram(Graph_Graph12);
   
   graph_12->Draw("l ");
   
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
   0.001416872,
   0.0005360164,
   9.276276e-05,
   6.620748e-05,
   6.100381e-05,
   6.255002e-05,
   0.0001250842,
   0.0002226542};
   TGraph *graph_13 = new TGraph(10,Graph12_fx13,Graph12_fy13);
   graph_13->SetName("Graph12");
   graph_13->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_13->SetFillStyle(1000);

   ci = TColor::GetColor("#990000");
   graph_13->SetLineColor(ci);
   graph_13->SetLineStyle(7);
   graph_13->SetLineWidth(3);
   
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
   graph_13->SetHistogram(Graph_Graph13);
   
   graph_13->Draw("l");
   
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
   0.003325994,
   0.001017209,
   0.0003848201,
   6.65968e-05,
   4.792607e-05,
   4.451856e-05,
   4.579391e-05,
   9.230149e-05,
   0.0001640553,
   0.0002980925,
   0.0001674644,
   8.374282e-05,
   8.167273e-05,
   8.916729e-05,
   0.0001271501,
   0.0007646309,
   0.002021177,
   0.00656817,
   0.07664596};
   TGraph *graph_14 = new TGraph(20,Graph13_fx14,Graph13_fy14);
   graph_14->SetName("Graph13");
   graph_14->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");

   ci = 1183;
   color = new TColor(ci, 0.6, 0, 0, " ", 0.15);
   graph_14->SetFillColor(ci);
   graph_14->SetFillStyle(3001);

   ci = TColor::GetColor("#990000");
   graph_14->SetLineColor(ci);
   graph_14->SetLineWidth(2);
   
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
   graph_14->SetHistogram(Graph_Graph14);
   
   graph_14->Draw("f ");
   
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
   0.05980177,
   0.005114187,
   0.001570247,
   0.0005924384,
   0.0001018158,
   7.193903e-05,
   6.618546e-05,
   6.786806e-05,
   0.0001357662,
   0.0002421693};
   TGraph *graph_15 = new TGraph(10,Graph14_fx15,Graph14_fy15);
   graph_15->SetName("Graph14");
   graph_15->SetTitle(";#Phi proper decay length [mm];95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi);");
   graph_15->SetFillStyle(1000);

   ci = TColor::GetColor("#990000");
   graph_15->SetLineColor(ci);
   graph_15->SetLineWidth(3);

   ci = TColor::GetColor("#990000");
   graph_15->SetMarkerColor(ci);
   graph_15->SetMarkerStyle(31);
   
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
   graph_15->SetHistogram(Graph_Graph15);
   
   graph_15->Draw("l ");
   
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
Graph_Graph13->Write();
Graph_Graph14->Write();
Graph_Graph15->Write();
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
graph_13->Write();
graph_14->Write();
graph_15->Write();

}