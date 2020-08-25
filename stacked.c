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

    TFile* f1 = new TFile("pT_spectrum_bkg1-sig-bkg2s2s3_sum688/plots.root","read"); 
    TFile* f3 = new TFile("plots_MCc1s_30mupt60_official/plots.root","read"); 
    TFile* f4 = new TFile("plots_MCi1s_30mupt60_official/plots.root","read"); 

    TH1F *histo_Data = (TH1F *)f1->Get("histo_QQ_pT_sig_min_bkg1and2");
    TH1F *histo_MC_CohUps = (TH1F *)f3->Get("histo_QQ_pT");
    TH1F *histo_MC_IncohUps = (TH1F *)f4->Get("histo_QQ_pT");


   

    float count_data  = 0;
    float count_gg    = 0;
    float count_coh   = 0;
    float count_incoh = 0;

    float all_data  = 0;
    for (int i = 1; i <= number_of_bins; i++) {
      all_data += histo_Data->GetBinContent(i);
    }


    float all_coh   =  histo_MC_CohUps->GetEntries();
    float all_incoh =  histo_MC_IncohUps->GetEntries();
    

    float from = 0.3;
    float to   = 4.0;
    

 
       // see the binning of the histos !!!
    int start = static_cast<int>((from * 25) + 1);
    int stop  = static_cast<int>(to * 25);
    
    for (int i = start; i <= stop; i++) {
      count_data += histo_Data->GetBinContent(i);
    }
    for (int i=start; i <= stop; i++) {
      count_coh += histo_MC_CohUps->GetBinContent(i);
    }
    
    for (int i=start; i <= stop; i++) {
      count_incoh += histo_MC_IncohUps->GetBinContent(i);
    }

    cout << endl;
    cout << "The range is from " << from << " to " << to << endl << endl;
    cout << "All data :	"  <<  all_data  << ",	in given range: " << count_data  << ",	given bin:	"  << histo_Data->GetBinContent(1)        << endl;
    cout << "All coh  :	"  <<  all_coh   << ",	in given range: " << count_coh   << ",	given bin:	"  << histo_MC_CohUps->GetBinContent(1)   << endl;
    cout << "All incoh:	"  <<  all_incoh << ",	in given range: " << count_incoh << ",	given bin:	"  << histo_MC_IncohUps->GetBinContent(1) << endl;
    cout << endl;

   
   float fract_incoh = count_incoh / all_incoh;
   float tot_inc = count_data / fract_incoh;
   float tot_coh = all_data  - tot_inc;
   
   
   cout << endl << "For the pT range from " << from << " to " << to << ":" << endl;
   cout << "Data:   " << count_data << endl;
   cout << "Fraction of incoh events in this range is: " << fract_incoh << endl;
   cout << "So the total number of incoh events is:    " << tot_inc << endl;
   cout << "So the total number of coh events is  :    " << tot_coh << endl;
   cout << "And the total number of data events is:    " << all_data << endl;

   THStack *hs = new THStack("hs"," ;QQ pT;events");
   double content = 0;
   
   histo_MC_CohUps->Scale(tot_coh/(histo_MC_CohUps->Integral()));
   TH1F *h1 = new TH1F("h1","test hstack", number_of_bins, 0, 4);
  // fill a histo, normal methods failed here :/
  for (int i=1; i<=number_of_bins; i++)
  {
   content = histo_MC_CohUps->GetBinContent(i);
   h1->SetBinContent(i, content);
  }
   h1->SetFillColor(kRed);
   hs->Add(h1);
   
   
   histo_MC_IncohUps->Scale(tot_inc/(histo_MC_IncohUps->Integral()));
   TH1F *h2 = new TH1F("h2","test hstack", number_of_bins, 0, 4);
  // fill a histo, normal methods failed here :/
  for (int i=1; i<=number_of_bins; i++)
  {
   content = histo_MC_IncohUps->GetBinContent(i);
   h2->SetBinContent(i, content);
  }
   h2->SetFillColor(kBlue);
   hs->Add(h2);

   hs->SetMaximum(-15);
   hs->SetMaximum(300);






   TCanvas *cs = new TCanvas("cs","cs",10,10,900,600);


        
/*

   TH1F* histo_QQ_pT = new TH1F("histo_QQ_pT","QQ_pT; QQ_pT [GeV]; events ",number_of_bins,0,4);
   histo_QQ_pT =cs->DrawFrame(0.,0.,1.,1.);
   histo_QQ_pT->SetXTitle("x");           
   cs->Modified();       
*/


   TText T; 
   T.SetTextFont(42); 
   T.SetTextAlign(21);
  // hs->GetYaxis()->SetRangeUser(0,700);
   hs->Draw(); 
   T.DrawTextNDC(.5,.95,"sideband subtracted signal");

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
 // hs->Draw("same"); 
  hd->Draw("same, E0");
  
   cs->Update();

   cs->SaveAs("sideband_stacked.pdf");
  
  

   
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