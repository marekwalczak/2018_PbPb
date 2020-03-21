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
void draw_Gen(){

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
  l1->AddEntry(histo_QQ_rap,"Reco","l");
  l1->AddEntry(histo_QQ_rap_Gen,"Gen","l");
  l1->SetFillColor(10);
  l1->Draw();
  
  c1->Update();
  c1->SaveAs("plots/QQ_rap_Gen_vs_Reco.pdf");
  
  
  
  
  
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
  l5->AddEntry(histo_QQ_pT,"Reco","l");
  l5->AddEntry(histo_QQ_pT_Gen,"Gen","l");
  l5->SetFillColor(10);
  l5->Draw();

  c5->Update();
  c5->SaveAs("plots/QQ_pT_Gen_vs_Reco.pdf");




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
  l2->AddEntry(histo_mu_rap,"Reco","l");
  l2->AddEntry(histo_mu_rap_Gen,"Gen","l");
  l2->SetFillColor(10);
  l2->Draw();
  
  c2->Update();
  c2->SaveAs("plots/mu_rap_Gen_vs_Reco.pdf");





//************* MUON rap Acc **************//

  TH1F *histo_mu_rap_Acc = (TH1F *)f1->Get("histo_mu_rap_Acc");

  TCanvas *c2_2 = new TCanvas("c2_2","c2_2",1000,600);
  //d1->SetLogy();
  
  histo_mu_rap_Acc->GetXaxis()->SetRangeUser(-5,5);
  histo_mu_rap_Acc->GetYaxis()->SetRangeUser(0,10000);  // adjust
  histo_mu_rap_Acc->GetXaxis()->SetTitleOffset(1.2);
  histo_mu_rap_Acc->GetYaxis()->SetTitleOffset(1.22);
  
  histo_mu_rap_Acc->GetXaxis()->SetTitle("mu rap");
  
  //histo_mu_rap->SetMarkerStyle(8);
  //histo_mu_rap->SetMarkerColor(kRed);
  histo_mu_rap_Acc->SetLineColor(kGreen);
  histo_mu_rap_Acc->SetLineWidth(4);

  
  histo_mu_rap_Acc->Draw("");
  
  histo_mu_rap_Acc->SetStats(0); // gets rid of anoying stat box
  
  TLegend *l2 = new TLegend(0.15,0.70,0.35,0.80,NULL,"brNDC");
  l2->AddEntry(histo_mu_rap_Acc,"Acceptance","l");
  l2->SetFillColor(10);
  l2->Draw();
  
  c2_2->Update();
  c2_2->SaveAs("plots/mu_rap_Acc.pdf");
  
  
  
//************* MUON pT Acc **************//

  TH1F *histo_mu_pT_Acc = (TH1F *)f1->Get("histo_mu_pT_Acc");

  TCanvas *c2_3 = new TCanvas("c2_3","c2_3",1000,600);
  //d1->SetLogy();
  
  histo_mu_pT_Acc->GetXaxis()->SetRangeUser(-5,5);
  histo_mu_pT_Acc->GetYaxis()->SetRangeUser(0,10000);  // adjust
  histo_mu_pT_Acc->GetXaxis()->SetTitleOffset(1.2);
  histo_mu_pT_Acc->GetYaxis()->SetTitleOffset(1.22);
  
  histo_mu_pT_Acc->GetXaxis()->SetTitle("mu pT");
  
  //histo_mu_rap->SetMarkerStyle(8);
  //histo_mu_rap->SetMarkerColor(kRed);
  histo_mu_pT_Acc->SetLineColor(kGreen);
  histo_mu_pT_Acc->SetLineWidth(4);

  
  histo_mu_pT_Acc->Draw("");
  
  histo_mu_pT_Acc->SetStats(0); // gets rid of anoying stat box
  
  TLegend *l2 = new TLegend(0.15,0.70,0.35,0.80,NULL,"brNDC");
  l2->AddEntry(histo_mu_pT_Acc,"Acceptance","l");
  l2->SetFillColor(10);
  l2->Draw();
  
  c2_3->Update();
  c2_3->SaveAs("plots/mu_pT_Acc.pdf");
  
  
  
  

  
  
//*************** SP - QQ pT vs rap *******************//
  TH2F *sp_QQ_pT_QQ_rap_Acc = (TH2F *)f1->Get("sp_QQ_pT_QQ_rap_Acc");

  TCanvas *c3 = new TCanvas("c3","c3",1000,600);
  c3->SetLogz();


  sp_QQ_pT_QQ_rap_Acc->GetXaxis()->SetTitleOffset(1.2);
  sp_QQ_pT_QQ_rap_Acc->GetYaxis()->SetTitleOffset(1.22);
 
  sp_QQ_pT_QQ_rap_Acc->GetXaxis()->SetTitle("QQ rap");
  sp_QQ_pT_QQ_rap_Acc->GetYaxis()->SetTitle("QQ pT");


  sp_QQ_pT_QQ_rap_Acc->SetLineColor(kRed);
  sp_QQ_pT_QQ_rap_Acc->SetLineWidth(4);

  sp_QQ_pT_QQ_rap_Acc->Draw("colz");

  sp_QQ_pT_QQ_rap_Acc->SetStats(0); // gets rid of anoying stat box

  TLegend *l3 = new TLegend(0.15,0.70,0.35,0.80,NULL,"brNDC");
  l3->AddEntry(sp_QQ_pT_QQ_rap_Acc,"Acceptance","l");
  l3->SetFillColor(10);
  l3->Draw();

  c3->Update();
  c3->SaveAs("plots/sp_QQ_pT_QQ_rap_Acc.pdf");





//*************** SP - MUON pT vs rap *******************//
  TH2F *sp_mu_pT_mu_rap = (TH2F *)f1->Get("sp_mu_pT_mu_rap");

  TCanvas *c4 = new TCanvas("c4","c4",1000,600);
  c4->SetLogz();

 // sp_mu_pT_mu_rap->GetXaxis()->SetRangeUser(-5,5);
 // sp_mu_pT_mu_rap->GetYaxis()->SetRangeUser(0,500);
  sp_mu_pT_mu_rap->GetXaxis()->SetTitleOffset(1.2);
  sp_mu_pT_mu_rap->GetYaxis()->SetTitleOffset(1.22);
 
  //sp_mu_pT_mu_rap->GetXaxis()->SetTitle("mu rap");

  //sp_mu_pT_mu_rap->SetMarkerStyle(8);
  //sp_mu_pT_mu_rap->SetMarkerColor(kRed);
  sp_mu_pT_mu_rap->SetLineColor(kRed);
  sp_mu_pT_mu_rap->SetLineWidth(4);

  sp_mu_pT_mu_rap->Draw("colz");

  sp_mu_pT_mu_rap->SetStats(0); // gets rid of anoying stat box

  TLegend *l4 = new TLegend(0.15,0.70,0.35,0.80,NULL,"brNDC");
  l4->AddEntry(sp_mu_pT_mu_rap,"Acceptance");
  l4->SetFillColor(10);
  l4->Draw();

  c4->Update();
  c4->SaveAs("plots/sp_mu_pT_mu_rap_Acc.pdf");




cout << endl << "******* THE END *******" << endl << endl;


}














