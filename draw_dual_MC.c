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


void draw_dual_MC(){

  system("mkdir plots_MC_comparison_noCuts");

cout << endl << "******* opening files *******" << endl;

TFile* f2 = new TFile("plots_ana_coh1s_mine_noCuts/plots.root","read");
TFile* f1 = new TFile("plots_ana_coh1s_official_noCuts/plots.root","read");

          
cout << endl << "******* making histos *******" << endl << endl;


//*************** QQ MASS *******************//
  TH1F *histo_QQ_M = (TH1F *)f1->Get("histo_QQ_M");
  TH1F *histo_QQ_M_2 = (TH1F *)f2->Get("histo_QQ_M");  
    
  //histo_QQ_M->Scale(1./(histo_QQ_M->Integral()));
  //histo_QQ_M_2->Scale(1./(histo_QQ_M_2->Integral()));
  
  TCanvas *c3 = new TCanvas("c3","c3",1000,600);
  //gPad -> SetLogy(1);  
  
  histo_QQ_M->GetXaxis()->SetRangeUser(2,5);
 // histo_QQ_M->GetYaxis()->SetRangeUser(0,.4);
  histo_QQ_M->GetXaxis()->SetTitleOffset(1.2);
  histo_QQ_M->GetYaxis()->SetTitleOffset(1.22);
 
  histo_QQ_M->GetXaxis()->SetTitle("QQ mass");
  
  //histo_QQ_M->SetMarkerStyle(8);
  //histo_QQ_M->SetMarkerColor(kRed);
  histo_QQ_M->SetLineColor(kRed);
  histo_QQ_M->SetLineWidth(2);
  histo_QQ_M_2->SetLineColor(kBlue);
  histo_QQ_M_2->SetLineWidth(2);
  histo_QQ_M_2->SetLineStyle(1);

  histo_QQ_M->Draw("");
  histo_QQ_M_2->Draw("hist same");

  histo_QQ_M->SetStats(0); // gets rid of anoying stat box

  TLegend *l3 = new TLegend(0.55,0.70,0.75,0.80,NULL,"brNDC");
  l3->AddEntry(histo_QQ_M,"Official","l");
  l3->AddEntry(histo_QQ_M_2,"Marek","l");
  l3->SetFillColor(10);
  l3->Draw();

  c3->Update();
  c3->SaveAs("plots_MC_comparison_noCuts/QQ_M.pdf");


//*************** QQ RAPIDITY *******************//
  TH1F *histo_QQ_rap = (TH1F *)f1->Get("histo_QQ_rap");
  TH1F *histo_QQ_rap_2 = (TH1F *)f2->Get("histo_QQ_rap");   
    
  //histo_QQ_rap->Scale(1./(histo_QQ_rap->Integral()));
  //histo_QQ_rap_2->Scale(1./(histo_QQ_rap_2->Integral()));
  
  TCanvas *c4 = new TCanvas("c4","c4",1000,600);
  //d1->SetLogy();

  histo_QQ_rap->GetXaxis()->SetRangeUser(-3,3);
//  histo_QQ_rap->GetYaxis()->SetRangeUser(0,600);
  histo_QQ_rap->GetXaxis()->SetTitleOffset(1.2);
  histo_QQ_rap->GetYaxis()->SetTitleOffset(1.22);
 
  histo_QQ_rap->GetXaxis()->SetTitle("QQ y");

  //histo_QQ_rap->SetMarkerStyle(8);
  //histo_QQ_rap->SetMarkerColor(kRed);
  histo_QQ_rap->SetLineColor(kRed);
  histo_QQ_rap->SetLineWidth(2);
  histo_QQ_rap_2->SetLineColor(kBlue);
  histo_QQ_rap_2->SetLineWidth(2);

  histo_QQ_rap->Draw("");
  histo_QQ_rap_2->Draw("hist same");

  histo_QQ_rap->SetStats(0); // gets rid of anoying stat box

  TLegend *l4 = new TLegend(0.30,0.70,0.50,0.80,NULL,"brNDC");
  l4->AddEntry(histo_QQ_rap,"Official","l");
  l4->AddEntry(histo_QQ_rap_2,"Marek","l");
  l4->SetFillColor(10);
  l4->Draw();

  c4->Update();
  c4->SaveAs("plots_MC_comparison_noCuts/QQ_rap.pdf");

//*************** QQ pT *******************//
  TH1F *histo_QQ_pT = (TH1F *)f1->Get("histo_QQ_pT");
  TH1F *histo_QQ_pT_2 = (TH1F *)f2->Get("histo_QQ_pT");
    
  //histo_QQ_pT->Scale(1./(histo_QQ_pT->Integral()));
  //histo_QQ_pT_2->Scale(1./(histo_QQ_pT_2->Integral()));
  
  int reb5=4;
  histo_QQ_pT->Rebin(reb5);
  histo_QQ_pT_2->Rebin(reb5);

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

  histo_QQ_pT->Draw("");
  histo_QQ_pT_2->Draw("hist same");

  histo_QQ_pT->SetStats(0); // gets rid of anoying stat box

  TLegend *l5 = new TLegend(0.50,0.70,0.70,0.80,NULL,"brNDC");
  l5->AddEntry(histo_QQ_pT,"Official","l");
  l5->AddEntry(histo_QQ_pT_2,"Marek","l");
  l5->SetFillColor(10);
  l5->Draw();

  c5->Update();
  c5->SaveAs("plots_MC_comparison_noCuts/QQ_pT.pdf");

//*************** HF PLUS *******************//
  TH1F *histo_HF_energy_Pl = (TH1F *)f1->Get("histo_HF_energy_Pl");
  TH1F *histo_HF_energy_Pl_2 = (TH1F *)f2->Get("histo_HF_energy_Pl");
    
  //histo_HF_energy_Pl->Scale(1./(histo_HF_energy_Pl->Integral()));
  //histo_HF_energy_Pl_2->Scale(1./(histo_HF_energy_Pl_2->Integral()));
  
  TCanvas *c8 = new TCanvas("c8","c8",1000,600);
  //d1->SetLogy();

  histo_HF_energy_Pl->GetXaxis()->SetRangeUser(0,8);
 // histo_HF_energy_Pl->GetYaxis()->SetRangeUser(0,0.15);
  histo_HF_energy_Pl->GetXaxis()->SetTitleOffset(1.2);
  histo_HF_energy_Pl->GetYaxis()->SetTitleOffset(1.22);
 
  histo_HF_energy_Pl->GetXaxis()->SetTitle("HF+");

  //histo_HF_energy_Pl->SetMarkerStyle(8);
  //histo_HF_energy_Pl->SetMarkerColor(kRed);
  histo_HF_energy_Pl->SetLineColor(kRed);
  histo_HF_energy_Pl->SetLineWidth(2);
  histo_HF_energy_Pl_2->SetLineColor(kBlue);
  histo_HF_energy_Pl_2->SetLineWidth(2);

  histo_HF_energy_Pl->Draw("");
  histo_HF_energy_Pl_2->Draw("hist same");

  histo_HF_energy_Pl->SetStats(0); // gets rid of anoying stat box

  TLegend *l8 = new TLegend(0.50,0.70,0.70,0.80,NULL,"brNDC");
  l8->AddEntry(histo_HF_energy_Pl,"Official","l");
  l8->AddEntry(histo_HF_energy_Pl_2,"Marek","l");
  l8->SetFillColor(10);
  l8->Draw();

  c8->Update();
  c8->SaveAs("plots_MC_comparison_noCuts/HF_pl.pdf");


//*************** HF MINUS *******************//
  TH1F *histo_HF_energy_Min = (TH1F *)f1->Get("histo_HF_energy_Min");
  TH1F *histo_HF_energy_Min_2 = (TH1F *)f2->Get("histo_HF_energy_Min");
    
  //histo_HF_energy_Min->Scale(1./(histo_HF_energy_Min->Integral()));
  //histo_HF_energy_Min_2->Scale(1./(histo_HF_energy_Min_2->Integral()));
  
  TCanvas *c9 = new TCanvas("c9","c9",1000,600);
  //d1->SetLogy();

  histo_HF_energy_Min->GetXaxis()->SetRangeUser(0,8);
  //histo_HF_energy_Min->GetYaxis()->SetRangeUser(0,0.15);
  histo_HF_energy_Min->GetXaxis()->SetTitleOffset(1.2);
  histo_HF_energy_Min->GetYaxis()->SetTitleOffset(1.22);
 
  histo_HF_energy_Min->GetXaxis()->SetTitle("HF-");

  //histo_HF_energy_Min->SetMarkerStyle(8);
  //histo_HF_energy_Min->SetMarkerColor(kRed);
  histo_HF_energy_Min->SetLineColor(kRed);
  histo_HF_energy_Min->SetLineWidth(2);
  histo_HF_energy_Min_2->SetLineColor(kBlue);
  histo_HF_energy_Min_2->SetLineWidth(2);

  histo_HF_energy_Min->Draw("");
  histo_HF_energy_Min_2->Draw("hist same");

  histo_HF_energy_Min->SetStats(0); // gets rid of anoying stat box

  TLegend *l9 = new TLegend(0.50,0.70,0.70,0.80,NULL,"brNDC");
  l9->AddEntry(histo_HF_energy_Min,"Official","l");
  l9->AddEntry(histo_HF_energy_Min_2,"Marek","l");
  l9->SetFillColor(10);
  l9->Draw();

  c9->Update();
  c9->SaveAs("plots_MC_comparison_noCuts/HF_min.pdf");


//*************** MUON pT *******************//
  TH1F *histo_mu_pT = (TH1F *)f1->Get("histo_mu_pT");
  TH1F *histo_mu_pT_2 = (TH1F *)f2->Get("histo_mu_pT");
    
  //histo_mu_pT->Scale(1./(histo_mu_pT->Integral()));
  //histo_mu_pT_2->Scale(1./(histo_mu_pT_2->Integral()));
  
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

  histo_mu_pT->Draw("");
  histo_mu_pT_2->Draw("hist same");

  histo_mu_pT->SetStats(0); // gets rid of anoying stat box

  TLegend *l10 = new TLegend(0.50,0.70,0.70,0.80,NULL,"brNDC");
  l10->AddEntry(histo_mu_pT,"Official","l");
  l10->AddEntry(histo_mu_pT_2,"Marek","l");
  l10->SetFillColor(10);
  l10->Draw();

  c10->Update();
  c10->SaveAs("plots_MC_comparison_noCuts/mu_pT.pdf");


//*************** MUON rap *******************//
  TH1F *histo_mu_rap = (TH1F *)f1->Get("histo_mu_rap");
  TH1F *histo_mu_rap_2 = (TH1F *)f2->Get("histo_mu_rap");
    
  //histo_mu_rap->Scale(1./(histo_mu_rap->Integral()));
  //histo_mu_rap_2->Scale(1./(histo_mu_rap_2->Integral()));
  
  TCanvas *c11 = new TCanvas("c11","c11",1000,600);
  //d1->SetLogy();

  histo_mu_rap->GetXaxis()->SetRangeUser(-3,3);
 // histo_mu_rap->GetYaxis()->SetRangeUser(0,0.1);
  histo_mu_rap->GetXaxis()->SetTitleOffset(1.2);
  histo_mu_rap->GetYaxis()->SetTitleOffset(1.22);
 
  histo_mu_rap->GetXaxis()->SetTitle("mu rap");

  //histo_mu_rap->SetMarkerStyle(8);
  //histo_mu_rap->SetMarkerColor(kRed);
  histo_mu_rap->SetLineColor(kRed);
  histo_mu_rap->SetLineWidth(2);
  histo_mu_rap_2->SetLineColor(kBlue);
  histo_mu_rap_2->SetLineWidth(2);

  histo_mu_rap->Draw("");
  histo_mu_rap_2->Draw("hist same");

  histo_mu_rap->SetStats(0); // gets rid of anoying stat box

  TLegend *l11 = new TLegend(0.50,0.70,0.70,0.80,NULL,"brNDC");
  l11->AddEntry(histo_mu_rap,"Official","l");
  l11->AddEntry(histo_mu_rap_2,"Marek","l");
  l11->SetFillColor(10);
  l11->Draw();

  c11->Update();
  c11->SaveAs("plots_MC_comparison_noCuts/mu_rap.pdf");




//*************** QQ RAPIDITY GEN *******************//
  TH1F *histo_QQ_rap_Gen = (TH1F *)f1->Get("histo_QQ_rap_Gen");
  TH1F *histo_QQ_rap_Gen_2 = (TH1F *)f2->Get("histo_QQ_rap_Gen");   
    
  //histo_QQ_rap_Gen->Scale(1./(histo_QQ_rap_Gen->Integral()));
  //histo_QQ_rap_Gen_2->Scale(1./(histo_QQ_rap_Gen_2->Integral()));
  
  TCanvas *cG4 = new TCanvas("cG4","cG4",1000,600);
  //d1->SetLogy();

  histo_QQ_rap_Gen->GetXaxis()->SetRangeUser(-3,3);
//  histo_QQ_rap_Gen->GetYaxis()->SetRangeUser(0,600);
  histo_QQ_rap_Gen->GetXaxis()->SetTitleOffset(1.2);
  histo_QQ_rap_Gen->GetYaxis()->SetTitleOffset(1.22);
 
  histo_QQ_rap_Gen->GetXaxis()->SetTitle("QQ y");

  //histo_QQ_rap_Gen->SetMarkerStyle(8);
  //histo_QQ_rap_Gen->SetMarkerColor(kRed);
  histo_QQ_rap_Gen->SetLineColor(kRed);
  histo_QQ_rap_Gen->SetLineWidth(3);
  histo_QQ_rap_Gen_2->SetLineColor(kBlue);
  histo_QQ_rap_Gen_2->SetLineWidth(1);

  histo_QQ_rap_Gen->Draw("");
  histo_QQ_rap_Gen_2->Draw("hist same");

  histo_QQ_rap_Gen->SetStats(0); // gets rid of anoying stat box

  TLegend *lG4 = new TLegend(0.30,0.70,0.50,0.80,NULL,"brNDC");
  lG4->AddEntry(histo_QQ_rap_Gen,"Official","l");
  lG4->AddEntry(histo_QQ_rap_Gen_2,"Marek","l");
  lG4->SetFillColor(10);
  lG4->Draw();

  cG4->Update();
  cG4->SaveAs("plots_MC_comparison_noCuts/QQ_rap_Gen.pdf");


//*************** QQ pT GEN *******************//
  TH1F *histo_QQ_pT_Gen = (TH1F *)f1->Get("histo_QQ_pT_Gen");
  TH1F *histo_QQ_pT_Gen_2 = (TH1F *)f2->Get("histo_QQ_pT_Gen");   
    
  //histo_QQ_pT_Gen->Scale(1./(histo_QQ_pT_Gen->Integral()));
  //histo_QQ_pT_Gen_2->Scale(1./(histo_QQ_pT_Gen_2->Integral()));
  
  TCanvas *cG3 = new TCanvas("cG3","cG3",1000,600);
  //d1->SetLogy();

  histo_QQ_pT_Gen->GetXaxis()->SetRangeUser(-3,3);
//  histo_QQ_pT_Gen->GetYaxis()->SetRangeUser(0,600);
  histo_QQ_pT_Gen->GetXaxis()->SetTitleOffset(1.2);
  histo_QQ_pT_Gen->GetYaxis()->SetTitleOffset(1.22);
 
  histo_QQ_pT_Gen->GetXaxis()->SetTitle("QQ y");

  //histo_QQ_pT_Gen->SetMarkerStyle(8);
  //histo_QQ_pT_Gen->SetMarkerColor(kRed);
  histo_QQ_pT_Gen->SetLineColor(kRed);
  histo_QQ_pT_Gen->SetLineWidth(3);
  histo_QQ_pT_Gen_2->SetLineColor(kBlue);
  histo_QQ_pT_Gen_2->SetLineWidth(1);

  histo_QQ_pT_Gen->Draw("");
  histo_QQ_pT_Gen_2->Draw("hist same");

  histo_QQ_pT_Gen->SetStats(0); // gets rid of anoying stat box

  TLegend *lG3 = new TLegend(0.30,0.70,0.50,0.80,NULL,"brNDC");
  lG3->AddEntry(histo_QQ_pT_Gen,"Official","l");
  lG3->AddEntry(histo_QQ_pT_Gen_2,"Marek","l");
  lG3->SetFillColor(10);
  lG3->Draw();

  cG3->Update();
  cG3->SaveAs("plots_MC_comparison_noCuts/QQ_pT_Gen.pdf");




cout << endl << "******* THE END *******" << endl << endl;


}














