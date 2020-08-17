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





void stacked() {


    int number_of_bins = 100;

    TFile* f1 = new TFile("pT_spectrum_bkg1-sig-bkg2_sum688/plots.root","read"); 
    TFile* f3 = new TFile("plots_MCc1s_30mupt60_official/plots.root","read"); 
    TFile* f4 = new TFile("plots_MCi1s_30mupt60_official/plots.root","read"); 

    TH1F *histo_Data = (TH1F *)f1->Get("histo_QQ_pT_sig_min_bkg1and2");
    TH1F *histo_MC_CohUps = (TH1F *)f3->Get("histo_QQ_pT");
    TH1F *histo_MC_IncohUps = (TH1F *)f4->Get("histo_QQ_pT");




   THStack *hs = new THStack("hs","");
   double content = 0;
   
   histo_MC_CohUps->Scale(540./(histo_MC_CohUps->Integral()));
   TH1F *h1 = new TH1F("h1","test hstack", number_of_bins, 0, 4);
  // fill a histo, normal methods failed here :/
  for (int i=1; i<=number_of_bins; i++)
  {
   content = histo_MC_CohUps->GetBinContent(i);
   h1->SetBinContent(i, content);
  }
   h1->SetFillColor(kRed);
   hs->Add(h1);
   h1->GetYaxis()->SetRangeUser(0,700);
   
   
   histo_MC_IncohUps->Scale(140./(histo_MC_IncohUps->Integral()));
   TH1F *h2 = new TH1F("h2","test hstack", number_of_bins, 0, 4);
  // fill a histo, normal methods failed here :/
  for (int i=1; i<=number_of_bins; i++)
  {
   content = histo_MC_IncohUps->GetBinContent(i);
   h2->SetBinContent(i, content);
  }
   h2->SetFillColor(kBlue);
   hs->Add(h2);



   TCanvas *cs = new TCanvas("cs","cs",10,10,700,900);
   
   
   
    
   
   TText T; 
   T.SetTextFont(42); 
   T.SetTextAlign(21);
  // hs->GetYaxis()->SetRangeUser(0,700);
   hs->Draw(); 
   T.DrawTextNDC(.5,.95,"Default drawing option");

   TH1F *hd = new TH1F("hd","data", number_of_bins, 0, 4);
  // fill a histo, normal methods failed here :/
  for (int i=1; i<=number_of_bins; i++)
  {
   content = histo_Data->GetBinContent(i);
   hd->SetBinContent(i, content);
  }
  
  hd->SetMarkerStyle(20);
  hd->SetMarkerSize(1.0);
  hd->SetMarkerColor(kBlack);
  hd->SetLineColor(kBlack);
  hd->Draw("E0");
   hs->Draw("same"); 
 
   return cs;
   
}










/*

void stacked() {






   THStack *hs = new THStack("hs","");
   
   TH1F *h1 = new TH1F("h1","test hstack",10,-4,4);
   h1->FillRandom("gaus",20000);
   h1->SetFillColor(kRed);
   hs->Add(h1);
   
   TH1F *h2 = new TH1F("h2","test hstack",10,-4,4);
   h2->FillRandom("gaus",15000);
   h2->SetFillColor(kBlue);
   hs->Add(h2);
   
   TH1F *h3 = new TH1F("h3","test hstack",10,-4,4);
   h3->FillRandom("gaus",10000);
   h3->SetFillColor(kGreen);
   hs->Add(h3);
   
   TCanvas *cs = new TCanvas("cs","cs",10,10,700,900);
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
   cs->Divide(2,2);
   cs->cd(1); hs->Draw(); T.DrawTextNDC(.5,.95,"Default drawing option");
   cs->cd(2); hs->Draw("nostack"); T.DrawTextNDC(.5,.95,"Option \"nostack\"");
   cs->cd(3); hs->Draw("nostackb"); T.DrawTextNDC(.5,.95,"Option \"nostackb\"");
   cs->cd(4); hs->Draw("lego1"); T.DrawTextNDC(.5,.95,"Option \"lego1\"");
   
   
   return cs;
   
}

*/