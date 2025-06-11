void Limit_PiAll_WP23_GJson_unBlinded_lepIDSF_moreStats1_MAll_low_CSC()
{
//=========Macro generated from canvas: c/c
//=========  (Thu Apr 10 13:28:46 2025) by ROOT version 6.12/07
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
   8.504487e-05,
   6.694326e-05,
   6.31541e-05,
   6.477041e-05,
   0.0001180125,
   0.0001974906,
   0.0003061347,
   0.0005883572,
   0.01073414,
   0.0311178};
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
   0.0002184659,
   5.822957e-05,
   4.566801e-05,
   4.308309e-05,
   4.43478e-05,
   8.080224e-05,
   0.0001352203,
   0.000208842,
   0.0004013714,
   0.007349586,
   0.02130612,
   0.04848297,
   0.01672429,
   0.0009166877,
   0.000476972,
   0.0003092738,
   0.0001848097,
   0.000101948,
   9.940392e-05,
   0.0001051012,
   0.0001335208,
   0.0004905577};
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
   0.0003535098,
   9.50602e-05,
   7.474385e-05,
   7.058961e-05,
   7.260844e-05,
   0.0001320806,
   0.0002210785,
   0.0003412264,
   0.0006553876,
   0.01196361,
   0.03468654};
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
   0.01172053,
   0.0004086893,
   0.0002120871,
   0.0001655991,
   0.000142288,
   0.0001692169,
   0.0002417448,
   0.0003319559,
   0.0004928138,
   0.001966015,
   0.003670521};
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
   0.008243859,
   0.0002869606,
   0.000148127,
   0.0001156586,
   0.0001011231,
   0.0001246766,
   0.0001795085,
   0.0002472448,
   0.0003681666,
   0.001475471,
   0.002750426,
   0.004943405,
   0.0026478,
   0.0006637146,
   0.0004483967,
   0.0003275056,
   0.0002292479,
   0.0001984374,
   0.0002342479,
   0.000307616,
   0.0006058047,
   0.0171866};
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
   0.01300549,
   0.0004542322,
   0.0002354062,
   0.0001818855,
   0.0001558317,
   0.0001827021,
   0.000260607,
   0.0003581758,
   0.0005313645,
   0.002117444,
   0.003952334};
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
   0.1284648,
   0.001658268,
   0.0005209152,
   0.000300488,
   0.000194848,
   0.0001114295,
   0.0001213664,
   0.0001427346,
   0.0001842367,
   0.0006243096,
   0.001244721};
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
   0.09114227,
   0.001172447,
   0.0003657598,
   0.0002117208,
   0.0001391908,
   8.274242e-05,
   9.081369e-05,
   0.0001066328,
   0.0001376378,
   0.0004664031,
   0.0009298945,
   0.001676373,
   0.0008408112,
   0.0002481274,
   0.0001922329,
   0.0001634545,
   0.0001500717,
   0.0002686319,
   0.0004214615,
   0.0007430889,
   0.002444849,
   0.1868404};
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
   0.142611,
   0.001842572,
   0.0005770993,
   0.0003301334,
   0.0002118171,
   0.0001200985,
   0.0001307092,
   0.0001536953,
   0.0001983758,
   0.000672332,
   0.00134275};
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
   0.1544136,
   0.01161835,
   0.002765436,
   0.0008174595,
   0.0001269362,
   9.628216e-05,
   9.286457e-05,
   0.0001001832,
   0.0002334825,
   0.0004436025};
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
   0.1184302,
   0.00935056,
   0.002037534,
   0.0005779695,
   9.021274e-05,
   6.865921e-05,
   6.678042e-05,
   7.228185e-05,
   0.0001690126,
   0.000322684,
   0.0006045104,
   0.0003181736,
   0.000136922,
   0.0001272896,
   0.0001323579,
   0.0001770276,
   0.001156336,
   0.00372445,
   0.01509169,
   0.21781};
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
   0.1560975,
   0.01222211,
   0.002991558,
   0.0009030197,
   0.0001393591,
   0.0001051255,
   0.0001012238,
   0.0001091139,
   0.0002540477,
   0.0004827307};
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
   0.04958823,
   0.004237514,
   0.001297026,
   0.0004895218,
   8.475679e-05,
   6.116065e-05,
   5.672001e-05,
   5.86643e-05,
   0.0001215192,
   0.0002192719};
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
   Graph_Graph13->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph13->GetXaxis()->SetTitleFont(42);
   Graph_Graph13->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph13->GetYaxis()->SetLabelFont(42);
   Graph_Graph13->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph13->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph13->GetYaxis()->SetTitleOffset(0.95);
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
   0.03572023,
   0.003042222,
   0.000931169,
   0.0003496926,
   6.064477e-05,
   4.390883e-05,
   4.105831e-05,
   4.267341e-05,
   8.854349e-05,
   0.0001605326,
   0.0002944382,
   0.000163176,
   7.947592e-05,
   7.729406e-05,
   8.383302e-05,
   0.0001182034,
   0.0006983061,
   0.001850217,
   0.006027951,
   0.07034262};
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
   Graph_Graph14->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph14->GetXaxis()->SetTitleFont(42);
   Graph_Graph14->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph14->GetYaxis()->SetLabelFont(42);
   Graph_Graph14->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph14->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph14->GetYaxis()->SetTitleOffset(0.95);
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
   0.05487602,
   0.00468945,
   0.001436712,
   0.0005403296,
   9.369865e-05,
   6.70293e-05,
   6.19299e-05,
   6.407117e-05,
   0.0001319916,
   0.0002382951};
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
   Graph_Graph15->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph15->GetXaxis()->SetTitleFont(42);
   Graph_Graph15->GetYaxis()->SetTitle("95 % CL Upper Limit on #bf{#it{#Beta}}(B #rightarrow K#Phi)");
   Graph_Graph15->GetYaxis()->SetLabelFont(42);
   Graph_Graph15->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph15->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph15->GetYaxis()->SetTitleOffset(0.95);
   Graph_Graph15->GetYaxis()->SetTitleFont(42);
   Graph_Graph15->GetZaxis()->SetLabelFont(42);
   Graph_Graph15->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph15->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph15->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph15);
   
   graph->Draw("l ");
   
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
   entry=leg->AddEntry("Graph3","M_{#Phi} = 0.5","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph6","M_{#Phi} = 1.0 GeV","l");

   ci = TColor::GetColor("#009900");
   entry->SetLineColor(ci);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph9","M_{#Phi} = 2.0 GeV","l");

   ci = TColor::GetColor("#cc6600");
   entry->SetLineColor(ci);
   entry->SetLineStyle(7);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph12","M_{#Phi} = 3.0 GeV","l");

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
   
   leg = new TLegend(0.5,0.65,0.925,0.75,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.04);
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
   TLatex *   tex = new TLatex(0.2,0.7,"#Phi #rightarrow  #pi^{+}#pi^{-}   ");
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
}
