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
void draw_muAcc(){

system("mkdir plots/Acc");

cout << endl << "******* opening files *******" << endl;

TFile* f1 = new TFile("plots/plots.root","read");

          
cout << endl << "******* making histos *******" << endl << endl;





//*************** MUON rap *******************//
  TH1F *histo_mu_rap_Reco_Gen = (TH1F *)f1->Get("histo_mu_rap_Reco_Gen");
  TH1F *histo_mu_rap_Gen = (TH1F *)f1->Get("histo_mu_rap_Gen");
  
  
  TCanvas *c2 = new TCanvas("c2","c2",1000,600);
  //d1->SetLogy();
  
  histo_mu_rap_Gen->GetXaxis()->SetRangeUser(-7,7);
  //histo_mu_rap->GetYaxis()->SetRangeUser(0,10000);  // adjust
  histo_mu_rap_Gen->GetXaxis()->SetTitleOffset(1.2);
  histo_mu_rap_Gen->GetYaxis()->SetTitleOffset(1.22);
  
  histo_mu_rap_Gen->GetXaxis()->SetTitle("mu rap");
  
  //histo_mu_rap_Reco_Gen->SetMarkerStyle(8);
  //histo_mu_rap_Reco_Gen->SetMarkerColor(kRed);
  histo_mu_rap_Reco_Gen->SetLineColor(kRed);
  histo_mu_rap_Reco_Gen->SetLineWidth(6);
  histo_mu_rap_Gen->SetLineColor(kBlue);
  histo_mu_rap_Gen->SetLineWidth(6);
  
  histo_mu_rap_Gen->Draw("");
  histo_mu_rap_Reco_Gen->Draw("hist same");
  
  histo_mu_rap_Gen->SetStats(0); // gets rid of anoying stat box
  
  TLegend *l2 = new TLegend(0.15,0.70,0.30,0.85,NULL,"brNDC");
  l2->AddEntry(histo_mu_rap_Gen,"Gen","l");
  l2->AddEntry(histo_mu_rap_Reco_Gen,"Reco","l");
  l2->SetFillColor(10);
  l2->Draw();
  
  c2->Update();
  c2->SaveAs("plots/Acc/mu_rap_Gen_vs_Reco.pdf");





//************* MUON rap Acc **************//

  TH1F *histo_mu_rap_Acc = (TH1F *)f1->Get("histo_mu_rap_Acc");

  TCanvas *c2_2 = new TCanvas("c2_2","c2_2",1000,600);
  //d1->SetLogy();
  
  histo_mu_rap_Acc->GetXaxis()->SetRangeUser(-7,7);
  histo_mu_rap_Acc->GetYaxis()->SetRangeUser(0,0.9);  // adjust
  histo_mu_rap_Acc->GetXaxis()->SetTitleOffset(1.2);
  histo_mu_rap_Acc->GetYaxis()->SetTitleOffset(1.22);
  
  histo_mu_rap_Acc->GetXaxis()->SetTitle("mu rap");
  
  histo_mu_rap_Acc->SetLineColor(kGreen);
  histo_mu_rap_Acc->SetLineWidth(6);

  
  histo_mu_rap_Acc->Draw("");
  
  histo_mu_rap_Acc->SetStats(0); // gets rid of anoying stat box
  
  TLegend *l2_2 = new TLegend(0.15,0.70,0.35,0.80,NULL,"brNDC");
  l2_2->AddEntry(histo_mu_rap_Acc,"Reco / Gen","l");
  l2_2->SetFillColor(10);
  l2_2->Draw();
  
  c2_2->Update();
  c2_2->SaveAs("plots/Acc/mu_rap_Acc.pdf");
  
  
  
  
//*************** MUON pT *******************//
  TH1F *histo_mu_pT_Reco_Gen = (TH1F *)f1->Get("histo_mu_pT_Reco_Gen");
  TH1F *histo_mu_pT_Gen = (TH1F *)f1->Get("histo_mu_pT_Gen");
  
  
  TCanvas *c2_2_1 = new TCanvas("c2_2_1","c2_2_1",1000,600);
  //d1->SetLogy();
  
  histo_mu_pT_Gen->GetXaxis()->SetRangeUser(1,7);
  //histo_mu_pT_Reco_Gen->GetYaxis()->SetRangeUser(0,10000);  // adjust
  histo_mu_pT_Gen->GetXaxis()->SetTitleOffset(1.2);
  histo_mu_pT_Gen->GetYaxis()->SetTitleOffset(1.22);
  
  histo_mu_pT_Gen->GetXaxis()->SetTitle("mu pT");
  
  //histo_mu_pT_Reco_Gen->SetMarkerStyle(8);
  //histo_mu_pT_Reco_Gen->SetMarkerColor(kRed);
  histo_mu_pT_Reco_Gen->SetLineColor(kRed);
  histo_mu_pT_Reco_Gen->SetLineWidth(6);
  histo_mu_pT_Gen->SetLineColor(kBlue);
  histo_mu_pT_Gen->SetLineWidth(6);
  
  histo_mu_pT_Gen->Draw("");
  histo_mu_pT_Reco_Gen->Draw("hist same");
  
  histo_mu_pT_Gen->SetStats(0); // gets rid of anoying stat box
  
  TLegend *l2_2_1 = new TLegend(0.15,0.70,0.30,0.85,NULL,"brNDC");
  l2_2_1->AddEntry(histo_mu_pT_Gen,"Gen","l");
  l2_2_1->AddEntry(histo_mu_pT_Reco_Gen,"Reco","l");
  l2_2_1->SetFillColor(10);
  l2_2_1->Draw();
  
  c2_2_1->Update();
  c2_2_1->SaveAs("plots/Acc/mu_pT_Gen_vs_Reco.pdf");





//************* MUON pT Acc **************//

  TH1F *histo_mu_pT_Acc = (TH1F *)f1->Get("histo_mu_pT_Acc");
  TCanvas *c2_3_2 = new TCanvas("c2_3_2","c2_3_2",1000,600);
  //c2_3_2->SetLogy();
  
  histo_mu_pT_Acc->GetXaxis()->SetRangeUser(1,7);
  histo_mu_pT_Acc->GetYaxis()->SetRangeUser(0,1);  // adjust
  histo_mu_pT_Acc->GetXaxis()->SetTitleOffset(1.2);
  histo_mu_pT_Acc->GetYaxis()->SetTitleOffset(1.22);
  
  histo_mu_pT_Acc->GetXaxis()->SetTitle("mu pT");
  

  histo_mu_pT_Acc->SetLineColor(kGreen);
  histo_mu_pT_Acc->SetLineWidth(6);

  
  histo_mu_pT_Acc->Draw("");
  
  histo_mu_pT_Acc->SetStats(0); // gets rid of anoying stat box
  
  TLegend *l2_3_2 = new TLegend(0.15,0.70,0.35,0.80,NULL,"brNDC");
  l2_3_2->AddEntry(histo_mu_pT_Acc,"Reco / Gen","l");
  l2_3_2->SetFillColor(10);
  l2_3_2->Draw();
  
  c2_3_2->Update();
  c2_3_2->SaveAs("plots/Acc/mu_pT_Acc.pdf");
  
  
  


//*************** SP - MUON pT vs rap ACC *******************//
  TH2F *sp_mu_pT_mu_rap_Acc = (TH2F *)f1->Get("sp_mu_pT_mu_rap_Acc");

  TCanvas *c4 = new TCanvas("c4","c4",1000,600);
  c4->SetLogz();
  
  sp_mu_pT_mu_rap_Acc->GetXaxis()->SetRangeUser(-7,7);
  sp_mu_pT_mu_rap_Acc->GetYaxis()->SetRangeUser(1,6.5);
  sp_mu_pT_mu_rap_Acc->GetXaxis()->SetTitleOffset(1.2);
  sp_mu_pT_mu_rap_Acc->GetYaxis()->SetTitleOffset(1.22);
 
  //sp_mu_pT_mu_rap_Acc->GetXaxis()->SetTitle("mu rap");

  //sp_mu_pT_mu_rap_Acc->SetMarkerStyle(8);
  //sp_mu_pT_mu_rap_Acc->SetMarkerColor(kRed);
  sp_mu_pT_mu_rap_Acc->SetLineColor(kRed);
  sp_mu_pT_mu_rap_Acc->SetLineWidth(4);

  sp_mu_pT_mu_rap_Acc->Draw("colz");

  sp_mu_pT_mu_rap_Acc->SetStats(0); // gets rid of anoying stat box

  TLegend *l4 = new TLegend(0.1,0.80,0.25,0.90,NULL,"brNDC");
  l4->AddEntry(sp_mu_pT_mu_rap_Acc,"Reco / Gen", "");
  l4->SetFillColor(10);
  l4->Draw();


  c4->Update();
  c4->SaveAs("plots/Acc/sp_mu_pT_mu_rap_Acc.pdf");


//*************** SP - MUON pT vs rap Gen *******************//
  TH2F *sp_mu_pT_mu_rap_Gen = (TH2F *)f1->Get("sp_mu_pT_mu_rap_Gen");

  TCanvas *c5 = new TCanvas("c5","c5",1000,600);
  c5->SetLogz();
  
  sp_mu_pT_mu_rap_Gen->GetXaxis()->SetRangeUser(-7,7);
  sp_mu_pT_mu_rap_Gen->GetYaxis()->SetRangeUser(0,8);
  sp_mu_pT_mu_rap_Gen->GetXaxis()->SetTitleOffset(1.2);
  sp_mu_pT_mu_rap_Gen->GetYaxis()->SetTitleOffset(1.22);
 
  //sp_mu_pT_mu_rap_Gen->GetXaxis()->SetTitle("mu rap");

  //sp_mu_pT_mu_rap_Gen->SetMarkerStyle(8);
  //sp_mu_pT_mu_rap_Gen->SetMarkerColor(kRed);
  sp_mu_pT_mu_rap_Gen->SetLineColor(kRed);
  sp_mu_pT_mu_rap_Gen->SetLineWidth(4);

  sp_mu_pT_mu_rap_Gen->Draw("colz");

  sp_mu_pT_mu_rap_Gen->SetStats(0); // gets rid of anoying stat box

  TLegend *l5 = new TLegend(0.1,0.80,0.25,0.90,NULL,"brNDC");
  l5->AddEntry(sp_mu_pT_mu_rap_Gen,"Gen", "");
  l5->SetFillColor(10);
  l5->Draw();


  c5->Update();
  c5->SaveAs("plots/Acc/sp_mu_pT_mu_rap_Gen.pdf");


//*************** SP - MUON pT vs rap *******************//
  TH2F *sp_mu_pT_mu_rap = (TH2F *)f1->Get("sp_mu_pT_mu_rap");

  TCanvas *c6 = new TCanvas("c6","c6",1000,600);
  c6->SetLogz();
  
  sp_mu_pT_mu_rap->GetXaxis()->SetRangeUser(-7,7);
  sp_mu_pT_mu_rap->GetYaxis()->SetRangeUser(1,6.5);
  sp_mu_pT_mu_rap->GetXaxis()->SetTitleOffset(1.2);
  sp_mu_pT_mu_rap->GetYaxis()->SetTitleOffset(1.22);
 
  //sp_mu_pT_mu_rap->GetXaxis()->SetTitle("mu rap");

  //sp_mu_pT_mu_rap->SetMarkerStyle(8);
  //sp_mu_pT_mu_rap->SetMarkerColor(kRed);
  sp_mu_pT_mu_rap->SetLineColor(kRed);
  sp_mu_pT_mu_rap->SetLineWidth(4);

  sp_mu_pT_mu_rap->Draw("colz");

  sp_mu_pT_mu_rap->SetStats(0); // gets rid of anoying stat box

  TLegend *l6 = new TLegend(0.1,0.80,0.25,0.90,NULL,"brNDC");
  l6->AddEntry(sp_mu_pT_mu_rap,"Reco", "");
  l6->SetFillColor(10);
  l6->Draw();


  c6->Update();
  c6->SaveAs("plots/Acc/sp_mu_pT_mu_rap.pdf");


//*************** SP - MUON pT vs rap *******************//
  TH2F *sp_mu_pT_mu_rap_Reco_Gen = (TH2F *)f1->Get("sp_mu_pT_mu_rap_Reco_Gen");

  TCanvas *c7 = new TCanvas("c7","c7",1000,600);
  c7->SetLogz();
  
  sp_mu_pT_mu_rap_Reco_Gen->GetXaxis()->SetRangeUser(-7,7);
  sp_mu_pT_mu_rap_Reco_Gen->GetYaxis()->SetRangeUser(1,6.5);
  sp_mu_pT_mu_rap_Reco_Gen->GetXaxis()->SetTitleOffset(1.2);
  sp_mu_pT_mu_rap_Reco_Gen->GetYaxis()->SetTitleOffset(1.22);
 
  //sp_mu_pT_mu_rap_Reco_Gen->GetXaxis()->SetTitle("mu rap");

  //sp_mu_pT_mu_rap_Reco_Gen->SetMarkerStyle(8);
  //sp_mu_pT_mu_rap_Reco_Gen->SetMarkerColor(kRed);
  sp_mu_pT_mu_rap_Reco_Gen->SetLineColor(kRed);
  sp_mu_pT_mu_rap_Reco_Gen->SetLineWidth(4);

  sp_mu_pT_mu_rap_Reco_Gen->Draw("colz");

  sp_mu_pT_mu_rap_Reco_Gen->SetStats(0); // gets rid of anoying stat box

  TLegend *l7 = new TLegend(0.1,0.80,0.25,0.90,NULL,"brNDC");
  l7->AddEntry(sp_mu_pT_mu_rap_Reco_Gen,"Gen from Reco", "");
  l7->SetFillColor(10);
  l7->Draw();


  c7->Update();
  c7->SaveAs("plots/Acc/sp_mu_pT_mu_rap_Reco_Gen.pdf");




cout << endl << "******* THE END *******" << endl << endl;


}














