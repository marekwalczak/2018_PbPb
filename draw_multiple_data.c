#include "TStyle.h"
#include <memory>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <TTree.h>
#include <TLorentzVector.h>
#include <TClonesArray.h>
#include "TFile.h"


void draw_multiple_data(){

  system("mkdir plots_comparison");

cout << endl << "******* opening files *******" << endl;

TFile* f1 = new TFile("plots_data_92m97_qqpT04/plots.root","read");
TFile* f2 = new TFile("plots_data_92m97_04qqpT12/plots.root","read");
TFile* f3 = new TFile("plots_data_92m97_12qqpT/plots.root","read");

 bool norm = true;
          
cout << endl << "******* making histos *******" << endl << endl;





//*************** QQ MASS *******************//
  TH1F *histo_QQ_M = (TH1F *)f1->Get("histo_QQ_M");
  TH1F *histo_QQ_M_2 = (TH1F *)f2->Get("histo_QQ_M");  
  TH1F *histo_QQ_M_3 = (TH1F *)f3->Get("histo_QQ_M");  
    
  if (norm == true) histo_QQ_M->Scale(1./(histo_QQ_M->Integral()));
  if (norm == true) histo_QQ_M_2->Scale(1./(histo_QQ_M_2->Integral()));
  if (norm == true) histo_QQ_M_3->Scale(1./(histo_QQ_M_3->Integral()));

  TCanvas *c3 = new TCanvas("c3","c3",1000,600);
  //gPad -> SetLogy(1);  
  
  histo_QQ_M->GetXaxis()->SetRangeUser(8,12);
  histo_QQ_M->GetXaxis()->SetTitleOffset(1.2);
  histo_QQ_M->GetYaxis()->SetTitleOffset(1.22);
 
  histo_QQ_M->GetXaxis()->SetTitle("QQ mass");
  
  //histo_QQ_M->SetMarkerStyle(8);
  //histo_QQ_M->SetMarkerColor(kRed);
  histo_QQ_M->SetLineColor(kRed);
  histo_QQ_M->SetLineWidth(2);
  histo_QQ_M->SetMinimum(0.0);
  if (norm == true) histo_QQ_M->GetYaxis()->SetRangeUser(0,.04);
  
  histo_QQ_M_2->SetLineColor(kBlue);
  histo_QQ_M_2->SetLineWidth(2);
  histo_QQ_M_2->SetLineStyle(1);
  
  histo_QQ_M_3->SetLineColor(kGreen);
  histo_QQ_M_3->SetLineWidth(2);
  histo_QQ_M_3->SetLineStyle(1);  
  
  histo_QQ_M->Draw("hist");
  histo_QQ_M_2->Draw("hist same");
  histo_QQ_M_3->Draw("hist same");

  histo_QQ_M->SetStats(0); // gets rid of anoying stat box

  TLegend *l3 = new TLegend(0.55,0.70,0.75,0.85,NULL,"brNDC");
  l3->AddEntry(histo_QQ_M,"case 1","l");
  l3->AddEntry(histo_QQ_M_2,"case 2","l");
  l3->AddEntry(histo_QQ_M_3,"case 3","l");
  l3->SetFillColor(10);
  l3->Draw();

  c3->Update();
  c3->SaveAs("plots_comparison/QQ_M.pdf");





//*************** QQ RAPIDITY *******************//
  TH1F *histo_QQ_rap = (TH1F *)f1->Get("histo_QQ_rap");
  TH1F *histo_QQ_rap_2 = (TH1F *)f2->Get("histo_QQ_rap");   
  TH1F *histo_QQ_rap_3 = (TH1F *)f3->Get("histo_QQ_rap");   
    
  if (norm == true) histo_QQ_rap->Scale(1./(histo_QQ_rap->Integral()));
  if (norm == true) histo_QQ_rap_2->Scale(1./(histo_QQ_rap_2->Integral()));
  if (norm == true) histo_QQ_rap_3->Scale(1./(histo_QQ_rap_3->Integral()));
  
  TCanvas *c4 = new TCanvas("c4","c4",1000,600);
  //d1->SetLogy();

  histo_QQ_rap->GetXaxis()->SetRangeUser(-3,3);
  if (norm == true) histo_QQ_rap->GetYaxis()->SetRangeUser(0,0.1);
  histo_QQ_rap->GetXaxis()->SetTitleOffset(1.2);
  histo_QQ_rap->GetYaxis()->SetTitleOffset(1.22);
 
  histo_QQ_rap->GetXaxis()->SetTitle("QQ rap");

  //histo_QQ_rap->SetMarkerStyle(8);
  //histo_QQ_rap->SetMarkerColor(kRed);
  histo_QQ_rap->SetLineColor(kRed);
  histo_QQ_rap->SetLineWidth(2);
  histo_QQ_rap_2->SetLineColor(kBlue);
  histo_QQ_rap_2->SetLineWidth(2);

  histo_QQ_rap_3->SetLineColor(kGreen);
  histo_QQ_rap_3->SetLineWidth(2);

  histo_QQ_rap->Draw("hist");
  histo_QQ_rap_2->Draw("hist same");
  histo_QQ_rap_3->Draw("hist same");

  histo_QQ_rap->SetStats(0); // gets rid of anoying stat box

  TLegend *l4 = new TLegend(0.10,0.75,0.30,0.9,NULL,"brNDC");
  l4->AddEntry(histo_QQ_rap,"case 1","l");
  l4->AddEntry(histo_QQ_rap_2,"case 2","l");
  l4->AddEntry(histo_QQ_rap_3,"case 3","l");
  l4->SetFillColor(10);
  l4->Draw();

  c4->Update();
  c4->SaveAs("plots_comparison/QQ_rap.pdf");





//*************** QQ pT *******************//
  TH1F *histo_QQ_pT = (TH1F *)f1->Get("histo_QQ_pT");
  TH1F *histo_QQ_pT_2 = (TH1F *)f2->Get("histo_QQ_pT");
  TH1F *histo_QQ_pT_3 = (TH1F *)f3->Get("histo_QQ_pT");
    
  if (norm == true) histo_QQ_pT->Scale(1./(histo_QQ_pT->Integral()));
  if (norm == true) histo_QQ_pT_2->Scale(1./(histo_QQ_pT_2->Integral()));
  if (norm == true) histo_QQ_pT_3->Scale(1./(histo_QQ_pT_3->Integral()));
  
  int reb5=1;
  histo_QQ_pT->Rebin(reb5);
  histo_QQ_pT_2->Rebin(reb5);
  histo_QQ_pT_3->Rebin(reb5);

  TCanvas *c5 = new TCanvas("c5","c5",1000,600);
  //d1->SetLogy();

  histo_QQ_pT->GetXaxis()->SetRangeUser(0,8);
 // histo_QQ_pT->GetYaxis()->SetRangeUser(0,0.2);
  histo_QQ_pT->GetXaxis()->SetTitleOffset(1.2);
  histo_QQ_pT->GetYaxis()->SetTitleOffset(1.22);
 
  histo_QQ_pT->GetXaxis()->SetTitle("QQ p_{T} [GeV]");

  //histo_QQ_pT->SetMarkerStyle(8);
  //histo_QQ_pT->SetMarkerColor(kRed);
  histo_QQ_pT->SetLineColor(kRed);
  histo_QQ_pT->SetLineWidth(2);
  histo_QQ_pT_2->SetLineColor(kBlue);
  histo_QQ_pT_2->SetLineWidth(2);
  histo_QQ_pT_3->SetLineColor(kGreen);
  histo_QQ_pT_3->SetLineWidth(2);

  histo_QQ_pT->Draw("hist");
  histo_QQ_pT_2->Draw("hist same");
  histo_QQ_pT_3->Draw("hist same");

  histo_QQ_pT->SetStats(0); // gets rid of anoying stat box

  TLegend *l5 = new TLegend(0.50,0.70,0.70,0.85,NULL,"brNDC");
  l5->AddEntry(histo_QQ_pT,"case 1","l");
  l5->AddEntry(histo_QQ_pT_2,"case 2","l");
  l5->AddEntry(histo_QQ_pT_3,"case 3","l");
  l5->SetFillColor(10);
  l5->Draw();

  c5->Update();
  c5->SaveAs("plots_comparison/QQ_pT.pdf");





//*************** HF PLUS *******************//
  TH1F *histo_HF_energy_Pl = (TH1F *)f1->Get("histo_HF_energy_Pl");
  TH1F *histo_HF_energy_Pl_2 = (TH1F *)f2->Get("histo_HF_energy_Pl");
  TH1F *histo_HF_energy_Pl_3 = (TH1F *)f3->Get("histo_HF_energy_Pl");
    
  if (norm == true) histo_HF_energy_Pl->Scale(1./(histo_HF_energy_Pl->Integral()));
  if (norm == true) histo_HF_energy_Pl_2->Scale(1./(histo_HF_energy_Pl_2->Integral()));
  if (norm == true) histo_HF_energy_Pl_3->Scale(1./(histo_HF_energy_Pl_3->Integral()));
  
  TCanvas *c8 = new TCanvas("c8","c8",1000,600);
  //d1->SetLogy();

  histo_HF_energy_Pl->GetXaxis()->SetRangeUser(0,8);
  if (norm == true) histo_HF_energy_Pl->GetYaxis()->SetRangeUser(0,0.1);
  histo_HF_energy_Pl->GetXaxis()->SetTitleOffset(1.2);
  histo_HF_energy_Pl->GetYaxis()->SetTitleOffset(1.22);
 
  histo_HF_energy_Pl->GetXaxis()->SetTitle("HF+");

  //histo_HF_energy_Pl->SetMarkerStyle(8);
  //histo_HF_energy_Pl->SetMarkerColor(kRed);
  histo_HF_energy_Pl->SetLineColor(kRed);
  histo_HF_energy_Pl->SetLineWidth(2);
  histo_HF_energy_Pl_2->SetLineColor(kBlue);
  histo_HF_energy_Pl_2->SetLineWidth(2);
  histo_HF_energy_Pl_3->SetLineColor(kGreen);
  histo_HF_energy_Pl_3->SetLineWidth(2);

  histo_HF_energy_Pl->Draw("hist");
  histo_HF_energy_Pl_2->Draw("hist same");
  histo_HF_energy_Pl_3->Draw("hist same");

  histo_HF_energy_Pl->SetStats(0); // gets rid of anoying stat box

  TLegend *l8 = new TLegend(0.70,0.70,0.90,0.85,NULL,"brNDC");
  l8->AddEntry(histo_HF_energy_Pl,"case 1","l");
  l8->AddEntry(histo_HF_energy_Pl_2,"case 2","l");
  l8->AddEntry(histo_HF_energy_Pl_3,"case 3","l");
  l8->SetFillColor(10);
  l8->Draw();

  c8->Update();
  c8->SaveAs("plots_comparison/HF_pl.pdf");





//*************** HF MINUS *******************//
  TH1F *histo_HF_energy_Min = (TH1F *)f1->Get("histo_HF_energy_Min");
  TH1F *histo_HF_energy_Min_2 = (TH1F *)f2->Get("histo_HF_energy_Min");
  TH1F *histo_HF_energy_Min_3 = (TH1F *)f3->Get("histo_HF_energy_Min");
    
  if (norm == true) histo_HF_energy_Min->Scale(1./(histo_HF_energy_Min->Integral()));
  if (norm == true) histo_HF_energy_Min_2->Scale(1./(histo_HF_energy_Min_2->Integral()));
  if (norm == true) histo_HF_energy_Min_3->Scale(1./(histo_HF_energy_Min_3->Integral()));
  
  TCanvas *c9 = new TCanvas("c9","c9",1000,600);
  //d1->SetLogy();

  histo_HF_energy_Min->GetXaxis()->SetRangeUser(0,8);
  if (norm == true) histo_HF_energy_Min->GetYaxis()->SetRangeUser(0,0.1);
  histo_HF_energy_Min->GetXaxis()->SetTitleOffset(1.2);
  histo_HF_energy_Min->GetYaxis()->SetTitleOffset(1.22);
 
  histo_HF_energy_Min->GetXaxis()->SetTitle("HF-");

  //histo_HF_energy_Min->SetMarkerStyle(8);
  //histo_HF_energy_Min->SetMarkerColor(kRed);
  histo_HF_energy_Min->SetLineColor(kRed);
  histo_HF_energy_Min->SetLineWidth(2);
  histo_HF_energy_Min_2->SetLineColor(kBlue);
  histo_HF_energy_Min_2->SetLineWidth(2);
  histo_HF_energy_Min_3->SetLineColor(kGreen);
  histo_HF_energy_Min_3->SetLineWidth(2);

  histo_HF_energy_Min->Draw("hist");
  histo_HF_energy_Min_2->Draw("hist same");
  histo_HF_energy_Min_3->Draw("hist same");

  histo_HF_energy_Min->SetStats(0); // gets rid of anoying stat box

  TLegend *l9 = new TLegend(0.70,0.70,0.90,0.85,NULL,"brNDC");
  l9->AddEntry(histo_HF_energy_Min,"case 1","l");
  l9->AddEntry(histo_HF_energy_Min_2,"case 2","l");
  l9->AddEntry(histo_HF_energy_Min_3,"case 3","l");
  l9->SetFillColor(10);
  l9->Draw();

  c9->Update();
  c9->SaveAs("plots_comparison/HF_min.pdf");





//*************** MUON pT *******************//
  TH1F *histo_mu_pT = (TH1F *)f1->Get("histo_mu_pT");
  TH1F *histo_mu_pT_2 = (TH1F *)f2->Get("histo_mu_pT");
  TH1F *histo_mu_pT_3 = (TH1F *)f3->Get("histo_mu_pT");
    
  if (norm == true) histo_mu_pT->Scale(1./(histo_mu_pT->Integral()));
  if (norm == true) histo_mu_pT_2->Scale(1./(histo_mu_pT_2->Integral()));
  if (norm == true) histo_mu_pT_3->Scale(1./(histo_mu_pT_3->Integral()));
  
  
  int reb10=2;
  histo_mu_pT->Rebin(reb10);
  histo_mu_pT_2->Rebin(reb10);
  histo_mu_pT_3->Rebin(reb10);

  
  
  TCanvas *c10 = new TCanvas("c10","c10",1000,600);
  //d1->SetLogy();

  histo_mu_pT->GetXaxis()->SetRangeUser(0,8);
 // histo_mu_pT->GetYaxis()->SetRangeUser(0,0.3);
  histo_mu_pT->GetXaxis()->SetTitleOffset(1.2);
  histo_mu_pT->GetYaxis()->SetTitleOffset(1.22);
 
  histo_mu_pT->GetXaxis()->SetTitle("mu pT");

  //histo_mu_pT->SetMarkerStyle(8);
  //histo_mu_pT->SetMarkerColor(kRed);
  histo_mu_pT->SetLineColor(kRed);
  histo_mu_pT->SetLineWidth(2);
  histo_mu_pT_2->SetLineColor(kBlue);
  histo_mu_pT_2->SetLineWidth(2);
  histo_mu_pT_3->SetLineColor(kGreen);
  histo_mu_pT_3->SetLineWidth(2);

  histo_mu_pT->Draw("hist");
  histo_mu_pT_2->Draw("hist same");
  histo_mu_pT_3->Draw("hist same");

  histo_mu_pT->SetStats(0); // gets rid of anoying stat box

  TLegend *l10 = new TLegend(0.10,0.70,0.30,0.85,NULL,"brNDC");
  l10->AddEntry(histo_mu_pT,"case 1","l");
  l10->AddEntry(histo_mu_pT_2,"case 2","l");
  l10->AddEntry(histo_mu_pT_3,"case 3","l");
  l10->SetFillColor(10);
  l10->Draw();

  c10->Update();
  c10->SaveAs("plots_comparison/mu_pT.pdf");





//*************** MUON rap *******************//
  TH1F *histo_mu_rap = (TH1F *)f1->Get("histo_mu_rap");
  TH1F *histo_mu_rap_2 = (TH1F *)f2->Get("histo_mu_rap");
  TH1F *histo_mu_rap_3 = (TH1F *)f3->Get("histo_mu_rap");
    
  if (norm == true) histo_mu_rap->Scale(1./(histo_mu_rap->Integral()));
  if (norm == true) histo_mu_rap_2->Scale(1./(histo_mu_rap_2->Integral()));
  if (norm == true) histo_mu_rap_3->Scale(1./(histo_mu_rap_3->Integral()));
  
  int reb11=1;
  histo_mu_rap->Rebin(reb11);
  histo_mu_rap_2->Rebin(reb11);
  histo_mu_rap_3->Rebin(reb11);

  
  TCanvas *c11 = new TCanvas("c11","c11",1000,600);
  //d1->SetLogy();

  histo_mu_rap->GetXaxis()->SetRangeUser(-3,3);
  if (norm == true) histo_mu_rap->GetYaxis()->SetRangeUser(0,0.1);
  histo_mu_rap->GetXaxis()->SetTitleOffset(1.2);
  histo_mu_rap->GetYaxis()->SetTitleOffset(1.22);
 
  histo_mu_rap->GetXaxis()->SetTitle("mu rap");

  //histo_mu_rap->SetMarkerStyle(8);
  //histo_mu_rap->SetMarkerColor(kRed);
  histo_mu_rap->SetLineColor(kRed);
  histo_mu_rap->SetLineWidth(2);
  
  histo_mu_rap_2->SetLineColor(kBlue);
  histo_mu_rap_2->SetLineWidth(2);

  histo_mu_rap_3->SetLineColor(kGreen);
  histo_mu_rap_3->SetLineWidth(2);
  
  histo_mu_rap->Draw("hist");
  histo_mu_rap_2->Draw("hist same");
  histo_mu_rap_3->Draw("hist same");

  histo_mu_rap->SetStats(0); // gets rid of anoying stat box

  TLegend *l11 = new TLegend(0.50,0.70,0.70,0.85,NULL,"brNDC");
  l11->AddEntry(histo_mu_rap,"case 1","l");
  l11->AddEntry(histo_mu_rap_2,"case 2","l");
  l11->AddEntry(histo_mu_rap_3,"case 3","l");
  l11->SetFillColor(10);
  l11->Draw();

  c11->Update();
  c11->SaveAs("plots_comparison/mu_rap.pdf");




//*************** MUON Phi *******************//
  TH1F *histo_mu_Phi = (TH1F *)f1->Get("histo_mu_Phi");
  TH1F *histo_mu_Phi_2 = (TH1F *)f2->Get("histo_mu_Phi");
  TH1F *histo_mu_Phi_3 = (TH1F *)f3->Get("histo_mu_Phi");
    
  if (norm == true) histo_mu_Phi->Scale(1./(histo_mu_Phi->Integral()));
  if (norm == true) histo_mu_Phi_2->Scale(1./(histo_mu_Phi_2->Integral()));
  if (norm == true) histo_mu_Phi_3->Scale(1./(histo_mu_Phi_3->Integral()));
  
  int reb12=2;
  histo_mu_Phi->Rebin(reb12);
  histo_mu_Phi_2->Rebin(reb12);
  histo_mu_Phi_3->Rebin(reb12);
  
  TCanvas *c12 = new TCanvas("c12","c12",1000,600);
  //d1->SetLogy();

  histo_mu_Phi->GetXaxis()->SetRangeUser(-4,4);
  if (norm == true) histo_mu_Phi->GetYaxis()->SetRangeUser(0,0.06);
  histo_mu_Phi->GetXaxis()->SetTitleOffset(1.2);
  histo_mu_Phi->GetYaxis()->SetTitleOffset(1.22);
 
  histo_mu_Phi->GetXaxis()->SetTitle("mu Phi");

  //histo_mu_Phi->SetMarkerStyle(8);
  //histo_mu_Phi->SetMarkerColor(kRed);
  histo_mu_Phi->SetLineColor(kRed);
  histo_mu_Phi->SetLineWidth(2);
  histo_mu_Phi_2->SetLineColor(kBlue);
  histo_mu_Phi_2->SetLineWidth(2);

  histo_mu_Phi_3->SetLineColor(kGreen);
  histo_mu_Phi_3->SetLineWidth(2);
  
  
  histo_mu_Phi->Draw("hist");
  histo_mu_Phi_2->Draw("hist same");
  histo_mu_Phi_3->Draw("hist same");

  histo_mu_Phi->SetStats(0); // gets rid of anoying stat box

  TLegend *l12 = new TLegend(0.50,0.70,0.70,0.85,NULL,"brNDC");
  l12->AddEntry(histo_mu_Phi,"case 1","l");
  l12->AddEntry(histo_mu_Phi_2,"case 2","l");
  l12->AddEntry(histo_mu_Phi_3,"case 3","l");
  l12->SetFillColor(10);
  l12->Draw();

  c12->Update();
  c12->SaveAs("plots_comparison/mu_Phi.pdf");



cout << endl << "******* THE END *******" << endl << endl;


}














