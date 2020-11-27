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

system("rm -r plots/Acc_2");
system("mkdir plots/Acc_2");

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
  c2->SaveAs("plots/Acc_2/mu_rap_Gen_vs_Reco.pdf");





//************* MUON rap Acc **************//

  TH1F *histo_mu_rap_Acc = (TH1F *)f1->Get("histo_mu_rap_Acc");

  TCanvas *c2_2 = new TCanvas("c2_2","c2_2",1000,600);
  //d1->SetLogy();
  
  histo_mu_rap_Acc->GetXaxis()->SetRangeUser(-7,7);
  histo_mu_rap_Acc->GetYaxis()->SetRangeUser(0,0.7);  // adjust
  histo_mu_rap_Acc->GetXaxis()->SetTitleOffset(1.2);
  histo_mu_rap_Acc->GetYaxis()->SetTitleOffset(1.22);
  
  histo_mu_rap_Acc->GetXaxis()->SetTitle("mu rap");
  
  //histo_mu_rap->SetMarkerStyle(8);
  //histo_mu_rap->SetMarkerColor(kRed);
  histo_mu_rap_Acc->SetLineColor(kGreen);
  histo_mu_rap_Acc->SetLineWidth(6);

  
  histo_mu_rap_Acc->Draw("");
  
  histo_mu_rap_Acc->SetStats(0); // gets rid of anoying stat box
  
  TLegend *l2_2 = new TLegend(0.15,0.70,0.35,0.80,NULL,"brNDC");
  l2_2->AddEntry(histo_mu_rap_Acc,"Reco / Gen","l");
  l2_2->SetFillColor(10);
  l2_2->Draw();
  
  c2_2->Update();
  c2_2->SaveAs("plots/Acc_2/mu_rap_Acc.pdf");
  
  
  
  
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
  c2_2_1->SaveAs("plots/Acc_2/mu_pT_Gen_vs_Reco.pdf");





//************* MUON pT Acc **************//

  TH1F *histo_mu_pT_Acc = (TH1F *)f1->Get("histo_mu_pT_Acc");
  TCanvas *c2_3_2 = new TCanvas("c2_3_2","c2_3_2",1000,600);
  //c2_3_2->SetLogy();
  
  histo_mu_pT_Acc->GetXaxis()->SetRangeUser(1,7);
  histo_mu_pT_Acc->GetYaxis()->SetRangeUser(0,1);  // adjust
  histo_mu_pT_Acc->GetXaxis()->SetTitleOffset(1.2);
  histo_mu_pT_Acc->GetYaxis()->SetTitleOffset(1.22);
  
  histo_mu_pT_Acc->GetXaxis()->SetTitle("mu pT");
  
  //histo_mu_rap->SetMarkerStyle(8);
  //histo_mu_rap->SetMarkerColor(kRed);
  histo_mu_pT_Acc->SetLineColor(kGreen);
  histo_mu_pT_Acc->SetLineWidth(6);

  
  histo_mu_pT_Acc->Draw("");
  
  histo_mu_pT_Acc->SetStats(0); // gets rid of anoying stat box
  
  TLegend *l2_3_2 = new TLegend(0.15,0.70,0.35,0.80,NULL,"brNDC");
  l2_3_2->AddEntry(histo_mu_pT_Acc,"Reco / Gen","l");
  l2_3_2->SetFillColor(10);
  l2_3_2->Draw();
  
  c2_3_2->Update();
  c2_3_2->SaveAs("plots/Acc_2/mu_pT_Acc.pdf");
  
  
  


  
  
//*************** SP - QQ pT vs rap *******************//
  TH2F *sp_QQ_pT_QQ_rap_Acc = (TH2F *)f1->Get("sp_QQ_pT_QQ_rap_Acc");

  TCanvas *c3 = new TCanvas("c3","c3",1000,600);
  c3->SetLogz();
  
  sp_QQ_pT_QQ_rap_Acc->GetXaxis()->SetRangeUser(-7,7);
  sp_QQ_pT_QQ_rap_Acc->GetYaxis()->SetRangeUser(0,1.5);
  sp_QQ_pT_QQ_rap_Acc->GetXaxis()->SetTitleOffset(1.2);
  sp_QQ_pT_QQ_rap_Acc->GetYaxis()->SetTitleOffset(1.22);
 
  sp_QQ_pT_QQ_rap_Acc->GetXaxis()->SetTitle("QQ rap");
  sp_QQ_pT_QQ_rap_Acc->GetYaxis()->SetTitle("QQ pT");


  sp_QQ_pT_QQ_rap_Acc->SetLineColor(kRed);
  sp_QQ_pT_QQ_rap_Acc->SetLineWidth(4);

  sp_QQ_pT_QQ_rap_Acc->Draw("colz");

  sp_QQ_pT_QQ_rap_Acc->SetStats(0); // gets rid of anoying stat box

  TLegend *l3 = new TLegend(0.1,0.80,0.25,0.90,NULL,"brNDC");
  l3->AddEntry(sp_QQ_pT_QQ_rap_Acc, "Reco / Gen", "");
  l3->SetFillColor(10);
  l3->Draw();

  c3->Update();
  c3->SaveAs("plots/Acc_2/sp_QQ_pT_QQ_rap_Acc.pdf");





//*************** SP - MUON pT vs rap *******************//
  TH2F *sp_mu_pT_mu_rap_Acc = (TH2F *)f1->Get("sp_mu_pT_mu_rap_Acc");

  TCanvas *c4 = new TCanvas("c4","c4",1000,600);
  c4->SetLogz();
  
  sp_mu_pT_mu_rap_Acc->GetXaxis()->SetRangeUser(-4,4);
  sp_mu_pT_mu_rap_Acc->GetYaxis()->SetRangeUser(0,8);
  sp_mu_pT_mu_rap_Acc->GetXaxis()->SetTitleOffset(1.2);
  sp_mu_pT_mu_rap_Acc->GetYaxis()->SetTitleOffset(1.22);
 
  //sp_mu_pT_mu_rap_Acc->GetXaxis()->SetTitle("mu rap");

  //sp_mu_pT_mu_rap_Acc->SetMarkerStyle(8);
  //sp_mu_pT_mu_rap_Acc->SetMarkerColor(kRed);
  sp_mu_pT_mu_rap_Acc->SetLineColor(kRed);
  sp_mu_pT_mu_rap_Acc->SetLineWidth(4);

  sp_mu_pT_mu_rap_Acc->Draw("colz");

  sp_mu_pT_mu_rap_Acc->SetStats(0); // gets rid of anoying stat box

  TLegend *l4 = new TLegend(0.1,0.80,0.22,0.90,NULL,"brNDC");
  l4->AddEntry(sp_mu_pT_mu_rap_Acc,"Reco / Gen", "");
  l4->SetFillColor(10);
  l4->Draw();


  c4->Update();
  c4->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc.pdf");




  for (int i=1;i<sp_mu_pT_mu_rap_Acc->GetNbinsX();i++){
    for (int j=1;j<sp_mu_pT_mu_rap_Acc->GetNbinsY();j++){
      if(sp_mu_pT_mu_rap_Acc->GetBinContent(i,j) < 0.01) sp_mu_pT_mu_rap_Acc->SetBinContent(i,j,0);
    }
  }


  c4->Update();
  c4->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc_1proc.pdf");




  for (int i=1;i<sp_mu_pT_mu_rap_Acc->GetNbinsX();i++){
    for (int j=1;j<sp_mu_pT_mu_rap_Acc->GetNbinsY();j++){
      if(sp_mu_pT_mu_rap_Acc->GetBinContent(i,j) < 0.02) sp_mu_pT_mu_rap_Acc->SetBinContent(i,j,0);
    }
  }


  c4->Update();
  c4->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc_2proc.pdf");





 for (int i=1;i<sp_mu_pT_mu_rap_Acc->GetNbinsX();i++){
    for (int j=1;j<sp_mu_pT_mu_rap_Acc->GetNbinsY();j++){
      if(sp_mu_pT_mu_rap_Acc->GetBinContent(i,j) < 0.05) sp_mu_pT_mu_rap_Acc->SetBinContent(i,j,0);
    }
  }


  c4->Update();
  c4->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc_5proc.pdf");



  for (int i=1;i<sp_mu_pT_mu_rap_Acc->GetNbinsX();i++){
    for (int j=1;j<sp_mu_pT_mu_rap_Acc->GetNbinsY();j++){
      if(sp_mu_pT_mu_rap_Acc->GetBinContent(i,j) < 0.1) sp_mu_pT_mu_rap_Acc->SetBinContent(i,j,0);
    }
  }


  c4->Update();
  c4->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc_10proc.pdf");



cout << endl << "******* THE END *******" << endl << endl;


}














