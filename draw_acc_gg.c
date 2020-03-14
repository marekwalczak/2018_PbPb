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

//#include "/Users/marekwalczak/Science/Data/2016pPb_Iraq/ReadTree.C"

// draws normalized distributions
void draw_acc(){

system("mkdir res");

cout << endl << "******* opening files *******" << endl;

TFile* f1 = new TFile("plots/plots.root","read");

          
cout << endl << "******* making histos *******" << endl << endl;


  //*************** QQ RAPIDITY *******************//
  TH1F *histo_QQ_rap = (TH1F *)f1->Get("histo_QQ_rap");
  TH1F *histo_QQ_rap_Gen = (TH1F *)f1->Get("histo_QQ_rap_Gen");   

  
  TCanvas *c1 = new TCanvas("c1","c1",1000,600);
  //d1->SetLogy();

  histo_QQ_rap->GetXaxis()->SetRangeUser(-5, 5);
  histo_QQ_rap->GetYaxis()->SetRangeUser(0, 8000); // zmianiłem
  histo_QQ_rap->GetXaxis()->SetTitleOffset(1.2);
  histo_QQ_rap->GetYaxis()->SetTitleOffset(1.22);
 
  histo_QQ_rap->GetXaxis()->SetTitle("QQ rap");

  //histo_QQ_rap->SetMarkerStyle(8);
  //histo_QQ_rap->SetMarkerColor(kRed);
  histo_QQ_rap->SetLineColor(kRed);
  histo_QQ_rap->SetLineWidth(4);
  histo_QQ_rap_Gen->SetLineColor(kBlue);
  histo_QQ_rap_Gen->SetLineWidth(4);

  histo_QQ_rap->Draw("");
  histo_QQ_rap_Gen->Draw("hist same");

  histo_QQ_rap->SetStats(0); // gets rid of anoying stat box

  TLegend *l1 = new TLegend(0.15,0.70,0.35,0.80,NULL,"brNDC");
  l1->AddEntry(histo_QQ_rap,"Reco, ex cuts","l");
  l1->AddEntry(histo_QQ_rap_Gen,"Gen","l");
  l1->SetFillColor(10);
  l1->Draw();

  c1->Update();
  c1->SaveAs("plots/Acc_QQ_rap.png");


//*************** MUON rap *******************//
  TH1F *histo_mu_rap = (TH1F *)f1->Get("histo_mu_rap");
  TH1F *histo_mu_rap_Gen = (TH1F *)f1->Get("histo_mu_rap_Gen");

  
  TCanvas *c2 = new TCanvas("c2","c2",1000,600);
  //d1->SetLogy();

  histo_mu_rap->GetXaxis()->SetRangeUser(-5,5);
  histo_mu_rap->GetYaxis()->SetRangeUser(0,10000);  // adjust
  histo_mu_rap->GetXaxis()->SetTitleOffset(1.2);
  histo_mu_rap->GetYaxis()->SetTitleOffset(1.22);
 
  histo_mu_rap->GetXaxis()->SetTitle("mu rap");

  //histo_mu_rap->SetMarkerStyle(8);
  //histo_mu_rap->SetMarkerColor(kRed);
  histo_mu_rap->SetLineColor(kRed);
  histo_mu_rap->SetLineWidth(4);
  histo_mu_rap_Gen->SetLineColor(kBlue);
  histo_mu_rap_Gen->SetLineWidth(4);

  histo_mu_rap->Draw("");
  histo_mu_rap_Gen->Draw("hist same");

  histo_mu_rap->SetStats(0); // gets rid of anoying stat box

  TLegend *l2 = new TLegend(0.15,0.70,0.35,0.80,NULL,"brNDC");
  l2->AddEntry(histo_mu_rap,"Reco, ex cuts","l");
  l2->AddEntry(histo_mu_rap_Gen,"Gen","l");
  l2->SetFillColor(10);
  l2->Draw();

  c2->Update();
  c2->SaveAs("plots/Acc_mu_rap.png");


//*************** SP - QQ pT vs rap *******************//
  TH2F *sp_QQ_pT_QQ_rap = (TH2F *)f1->Get("sp_QQ_pT_QQ_rap");
  TH2F *sp_QQ_pT_QQ_rap_Gen = (TH2F *)f1->Get("sp_QQ_pT_QQ_rap_Gen");

  TCanvas *c3 = new TCanvas("c3","c3",1000,600);
  //d1->SetLogy();

 // sp_QQ_pT_QQ_rap->GetXaxis()->SetRangeUser(-5,5);
 // sp_QQ_pT_QQ_rap->GetYaxis()->SetRangeUser(0,500);
  sp_QQ_pT_QQ_rap->GetXaxis()->SetTitleOffset(1.2);
  sp_QQ_pT_QQ_rap->GetYaxis()->SetTitleOffset(1.22);
 
  //sp_QQ_pT_QQ_rap->GetXaxis()->SetTitle("mu rap");

  //sp_QQ_pT_QQ_rap->SetMarkerStyle(8);
  //sp_QQ_pT_QQ_rap->SetMarkerColor(kRed);
  sp_QQ_pT_QQ_rap->SetLineColor(kRed);
  sp_QQ_pT_QQ_rap->SetLineWidth(4);
  sp_QQ_pT_QQ_rap_Gen->SetLineColor(kBlue);
  sp_QQ_pT_QQ_rap_Gen->SetLineWidth(4);

  sp_QQ_pT_QQ_rap->Draw("colz");
  sp_QQ_pT_QQ_rap_Gen->Draw("same");

  sp_QQ_pT_QQ_rap->SetStats(0); // gets rid of anoying stat box

  TLegend *l3 = new TLegend(0.15,0.70,0.35,0.80,NULL,"brNDC");
  l3->AddEntry(sp_QQ_pT_QQ_rap,"Reco, ex cuts","l");
  l3->AddEntry(sp_QQ_pT_QQ_rap_Gen,"Gen","l");
  l3->SetFillColor(10);
  l3->Draw();

  c3->Update();
  c3->SaveAs("plots/Acc_sp_QQ_pT_QQ_rap.png");


//*************** SP - MUON pT vs rap *******************//
  TH2F *sp_mu_pT_mu_rap = (TH2F *)f1->Get("sp_mu_pT_mu_rap");
  TH2F *sp_mu_pT_mu_rap_Gen = (TH2F *)f1->Get("sp_mu_pT_mu_rap_Gen");

  TCanvas *c4 = new TCanvas("c4","c4",1000,600);
  //d1->SetLogy();

 // sp_mu_pT_mu_rap->GetXaxis()->SetRangeUser(-5,5);
 // sp_mu_pT_mu_rap->GetYaxis()->SetRangeUser(0,500);
  sp_mu_pT_mu_rap->GetXaxis()->SetTitleOffset(1.2);
  sp_mu_pT_mu_rap->GetYaxis()->SetTitleOffset(1.22);
 
  //sp_mu_pT_mu_rap->GetXaxis()->SetTitle("mu rap");

  //sp_mu_pT_mu_rap->SetMarkerStyle(8);
  //sp_mu_pT_mu_rap->SetMarkerColor(kRed);
  sp_mu_pT_mu_rap->SetLineColor(kRed);
  sp_mu_pT_mu_rap->SetLineWidth(4);
  sp_mu_pT_mu_rap_Gen->SetLineColor(kBlue);
  sp_mu_pT_mu_rap_Gen->SetLineWidth(4);

  sp_mu_pT_mu_rap->Draw("colz");
  sp_mu_pT_mu_rap_Gen->Draw("same");

  sp_mu_pT_mu_rap->SetStats(0); // gets rid of anoying stat box

  TLegend *l4 = new TLegend(0.15,0.70,0.35,0.80,NULL,"brNDC");
  l4->AddEntry(sp_mu_pT_mu_rap,"Reco, ex cuts","l");
  l4->AddEntry(sp_mu_pT_mu_rap_Gen,"Gen","l");
  l4->SetFillColor(10);
  l4->Draw();

  c4->Update();
  c4->SaveAs("plots/Acc_sp_mu_pT_mu_rap.png");


  //*************** QQ pT *******************//
  TH1F *histo_QQ_pT = (TH1F *)f1->Get("histo_QQ_pT");
  TH1F *histo_QQ_pT_Gen = (TH1F *)f1->Get("histo_QQ_pT_Gen");   

  
  TCanvas *c5 = new TCanvas("c5","c5",1000,600);
  //d1->SetLogy();

  histo_QQ_pT->GetXaxis()->SetRangeUser(-5,2);
  histo_QQ_pT->GetYaxis()->SetRangeUser(0,50000); // adjust
  histo_QQ_pT->GetXaxis()->SetTitleOffset(1.2);
  histo_QQ_pT->GetYaxis()->SetTitleOffset(1.22);
 
  histo_QQ_pT->GetXaxis()->SetTitle("QQ pT");

  //histo_QQ_pT->SetMarkerStyle(8);
  //histo_QQ_pT->SetMarkerColor(kRed);
  histo_QQ_pT->SetLineColor(kRed);
  histo_QQ_pT->SetLineWidth(4);
  histo_QQ_pT_Gen->SetLineColor(kBlue);
  histo_QQ_pT_Gen->SetLineWidth(4);

  histo_QQ_pT->Draw("");
  histo_QQ_pT_Gen->Draw("hist same");

  histo_QQ_pT->SetStats(0); // gets rid of anoying stat box

  TLegend *l5 = new TLegend(0.15,0.70,0.35,0.80,NULL,"brNDC");
  l5->AddEntry(histo_QQ_pT,"Reco, ex cuts","l");
  l5->AddEntry(histo_QQ_pT_Gen,"Gen","l");
  l5->SetFillColor(10);
  l5->Draw();

  c5->Update();
  c5->SaveAs("plots/Acc_QQ_pT.png");



cout << endl << "******* THE END *******" << endl << endl;


}














