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

// linear background function
Double_t background(Double_t *x, Double_t *par) {
   //return par[0] + par[1]*x[0] + par[2]*x[0]*x[0];
   return par[0] + par[1]*x[0];
   //return TMath::Exp(par[0]+(par[1]*x[0])) + par[2];
}

// ALICE Collaboration, nucleon dissociation
Double_t ALICEtail(Double_t *x, Double_t *par) {
   return par[0] * x[0] * pow((1.0 + ( par[1] / par[2]) * pow(x[0], 2) ), -par[2]); 
   //return par*x[0]*pow((1.0 + ( 1.8 / 3.6)*pow(x[0], 2) ), -3.6);
}

void fit_pT_multi(){

    cout << endl << "******* opening files *******" << endl;

    TFile* f1 = new TFile("plots_data_30mupt60_92m97/plots.root","read"); 
//    TFile* f1 = new TFile("pT_spectrum_bkg1-sig-bkg2s2s3_sum688/plots.root","read"); 
    TFile* f2 = new TFile("plots_MCgg_30mupt60_92m97/plots.root","read"); 
    TFile* f3 = new TFile("plots_MCc1s_30mupt60_official/plots.root","read"); 
    TFile* f4 = new TFile("plots_MCi1s_30mupt60_official/plots.root","read"); 

    TH1F *histo_Data = (TH1F *)f1->Get("histo_QQ_pT");
    TH1F *histo_MC_gg = (TH1F *)f2->Get("histo_QQ_pT");
    TH1F *histo_MC_CohUps = (TH1F *)f3->Get("histo_QQ_pT");
    TH1F *histo_MC_IncohUps = (TH1F *)f4->Get("histo_QQ_pT");

    int number_of_bins = 100;
    float all_data  =  histo_Data->GetEntries();
    float all_gg    =  histo_MC_gg->GetEntries();
    float all_coh   =  histo_MC_CohUps->GetEntries();
    float all_incoh =  histo_MC_IncohUps->GetEntries();

    float count_data  = 0;
    float count_gg    = 0;
    float count_coh   = 0;
    float count_incoh = 0;

    // range for the incoh ups extraction
    float from = 0.5;
    float to   = 2.0;
    
    // see the binning of the histos !!!
    int start = static_cast<int>((from * 25) + 1);
    int stop  = static_cast<int>(to * 25);
    
    for (int i = start; i <= stop; i++) {
      count_data += histo_Data->GetBinContent(i);
    }

    for (int i=start; i <= stop; i++) {
      count_gg += histo_MC_gg->GetBinContent(i);
    }

    for (int i=start; i <= stop; i++) {
      count_coh += histo_MC_CohUps->GetBinContent(i);
    }
    
    for (int i=start; i <= stop; i++) {
      count_incoh += histo_MC_IncohUps->GetBinContent(i);
    }

    float fract_incoh = count_incoh / all_incoh;
    cout << endl;
    cout << "The range is from " << from << " to " << to << endl << endl;
    cout << "All data : "  <<  all_data  << ", in given range: " << count_data  << ", given bin: "  << histo_Data->GetBinContent(1)        << endl;
    cout << "All gg   : "  <<  all_gg    << ", in given range: " << count_gg    << ", given bin: "  << histo_MC_gg->GetBinContent(1)       << endl;
    cout << "All coh  : "  <<  all_coh   << ", in given range: " << count_coh   << ", given bin: "  << histo_MC_CohUps->GetBinContent(1)   << endl;
    cout << "All incoh: "  <<  all_incoh << ", in given range: " << count_incoh << ", given bin: "  << histo_MC_IncohUps->GetBinContent(1) << endl;
    cout << endl;


/*
   // create a TF1 with the range from 1 to 4 and 2 parameters
   TF1 *fitFcn = new TF1( "fitFcn", background, 1, 4, 2 );
   fitFcn->SetNpx(400); // Set the number of points used to draw the function
   fitFcn->SetLineWidth(4);
   fitFcn->SetLineColor(kOrange);

   // Try without starting values for the parameters
   // This defaults to 1 for each param.
   // this results in an ok fit for the polynomial function
   fitFcn->SetParameters( 1., 1.);
   //histo_Data->Fit("fitFcn","0");
   histo_Data->Fit( "fitFcn", "RQ+" ); // V instead of Q gives terminal output , "ep"

   Double_t par[2];
   fitFcn->GetParameters(par);

   TF1 *Fcn = new TF1("Fcn", background, 0, 4, 2 );
   Fcn->SetParameters(par);
   float tail = Fcn->Integral(from, to) / histo_Data->GetBinWidth(1);
   cout << "Integral of fitted Fcn for given range: " << tail << endl;
   float tail_all = Fcn->Integral(0, - par[0] / par[1] ) / histo_Data->GetBinWidth(1);
   cout << "Integral of fitted Fcn for the whole range: " << tail_all << endl;
*/



// **** ALICE ***** //
   // create a TF1 with the range from 1 to 4 and 2 parameters
   TF1 *fitAlice = new TF1( "fitAlice", ALICEtail, 1, 4, 3 );
   fitAlice->SetNpx(400); // Set the number of points used to draw the function
   fitAlice->SetLineWidth(4);
   fitAlice->SetLineColor(kMagenta);

   // Try without starting values for the parameters
   // This defaults to 1 for each param.
   // this results in an ok fit for the polynomial function
   fitAlice->FixParameter(2, 1.8);
   fitAlice->FixParameter(3, 3.6);
  //histo_Data->Fit("fitAlice","0");
   histo_Data->Fit( "fitAlice", "RQ+" ); // V instead of Q gives terminal output , "ep"

   Double_t parA[3];
   fitAlice->GetParameters(parA);

   TF1 *FcnAlice = new TF1("FcnAlice", ALICEtail, 0, 4, 3 );
   FcnAlice->SetParameters(parA);
   
   float tailAlice_all = FcnAlice->Integral(0, 4.0 ) / histo_Data->GetBinWidth(1);
   cout << "Integral of fitted FcnAlice for the whole range: " << tailAlice_all << endl;

   float tailAlice = FcnAlice->Integral(from, to) / histo_Data->GetBinWidth(1);
   cout << "Integral of fitted FcnAlice for given range: " << tailAlice << endl;
   

  TH1F* histo_tail = new TH1F("histo_tail","QQ_pT; QQ_pT [GeV]; events ",number_of_bins,0,4);

  for (int i=1; i<=number_of_bins; i++)
  {
   float x=histo_tail->GetBinCenter(i);
   float y=FcnAlice->Eval(x);
   histo_tail->SetBinContent(i, y);
  }
  
    
    float count_tailAlice = 0;

     for (int i=start; i <= stop; i++) {
     count_tailAlice += histo_tail->GetBinContent(i);
    }

    float all_tailAlice = 0.0;
    
     for (int i=0; i <= number_of_bins; i++) {
     all_tailAlice += histo_tail->GetBinContent(i);
    }


    cout << "All tailAlice: "  <<  all_tailAlice << ", in given range: " << count_tailAlice << ", given bin: "  << histo_tail->GetBinContent(1) << endl;

// **** ALICE ***** //


// ***** FIT BY MAREK ****** //

   float tot_inc = (count_data - count_tailAlice - count_gg) / (count_incoh/all_incoh);
   cout << endl << "For the pT range from " << from << " to " << to << ":" << endl;
   cout << "Data: " << count_data << endl;
   cout << "gg:   " << count_gg << endl;
   cout << "Tail: " << count_tailAlice << endl;
   cout << "Remaining : " << (count_data - count_tailAlice - count_gg) << " would be incoh events" << endl; 
   cout << "Fraction of incoh events in this range is: " << count_incoh/all_incoh << endl;
   cout << "So the total number of incoh events is:    " << tot_inc << endl;


  double ups_from_fit = 688;
  double coh_fit_MC = ups_from_fit * 93.733 / (93.733 + 41.135);
  double incoh_fit_MC = ups_from_fit * 41.135 / (93.733 + 41.135);
  
//histo_Data->Scale(1./(histo_Data->Integral()));
  histo_MC_gg->Scale( (all_data - ups_from_fit ) / all_gg );
  histo_MC_CohUps->Scale( coh_fit_MC / all_coh );
  histo_MC_IncohUps->Scale( incoh_fit_MC / all_incoh );
  

// ***** FIT BY MAREK ****** //





  TH1F* histo_res = new TH1F("histo_res","QQ_pT; QQ_pT [GeV]; events ",number_of_bins,0,4);

  histo_res->Add(histo_MC_gg, 1);
  histo_res->Add(histo_MC_CohUps, 1);
  histo_res->Add(histo_MC_IncohUps, 1);
  histo_res->Add(histo_tail, 1);



  int reb = 1;
  histo_Data->Rebin(reb);
  histo_MC_gg->Rebin(reb);
  histo_MC_CohUps->Rebin(reb);
  histo_MC_IncohUps->Rebin(reb);

  
  cout << endl << endl;
  TCanvas *c1 = new TCanvas("c1","c1",1000,600);
  c1->SetLogy();

  histo_Data->GetXaxis()->SetTitle("p_{T} [GeV]");
  histo_Data->GetYaxis()->SetTitle("dimuons");
  histo_Data->GetXaxis()->SetTitleOffset(1.25);
  histo_Data->GetYaxis()->SetTitleOffset(1.5);
  histo_Data->GetXaxis()->SetRangeUser(0,4);
  //histo_Data->GetYaxis()->SetRangeUser(0,10);


  histo_Data->SetMarkerStyle(20);
  histo_Data->SetMarkerSize(1.0);
  histo_Data->SetMarkerColor(kBlack);
  histo_Data->SetLineColor(kBlack);
  
  //histo_Data->SetLineStyle(1);
  //histo_Data->SetLineWidth(4);
  //histo_Data->SetLineColor(kBlack);
  histo_Data->SetTitle("dimuon p_{T} distribution");
  histo_Data->Draw("E0");

  histo_MC_gg->SetLineStyle(1);
  histo_MC_gg->SetLineWidth(4);
  histo_MC_gg->SetLineColor(kGreen);

  histo_MC_gg->Draw("same, Hist");

  histo_MC_CohUps->SetLineStyle(1);
  histo_MC_CohUps->SetLineWidth(4);
  histo_MC_CohUps->SetLineColor(kBlue);
  histo_MC_CohUps->Draw("same, Hist");

  histo_MC_IncohUps->SetLineStyle(1);
  histo_MC_IncohUps->SetLineWidth(4);
  histo_MC_IncohUps->SetLineColor(kRed);
  histo_MC_IncohUps->Draw("same, Hist");
  //Fcn->Draw("same");
  
  //FcnAlice->Draw("same");


  histo_tail->SetLineStyle(1);
  histo_tail->SetLineWidth(4);
  histo_tail->SetLineColor(kCyan);
  histo_tail->Draw("same, Hist");
  
  

  histo_res->SetLineStyle(1);
  histo_res->SetLineWidth(4);
  histo_res->SetLineColor(kBlack);
  histo_res->Draw("same, Hist");
  
  
  histo_Data->SetStats(0);

  TLegend *l1 = new TLegend(0.6,0.5,0.8,0.8,NULL,"brNDC");
  //l1->AddEntry(histo_Data,"p_{T}^{2}","");
  l1->AddEntry(histo_Data,"Data","p");
  l1->AddEntry(histo_MC_gg,"MC #gamma#gamma","l");
  l1->AddEntry(histo_MC_CohUps,"MC coh #Upsilon","l");
  l1->AddEntry(histo_MC_IncohUps,"MC incoh #Upsilon","l");
  l1->AddEntry(histo_tail,"Tail","l");
  l1->AddEntry(histo_res,"Sum","l");
  l1->SetFillColor(10);
  l1->Draw();


  c1->Update();
  c1->SaveAs("pT_multi.pdf");
  
  
   THStack *hs = new THStack("hs","");
   double content = 0;
   
   
   TH1F *h1 = new TH1F("h1","test hstack", number_of_bins, 0, 4);
  // fill a histo, normal methods failed here :/
  for (int i=1; i<=number_of_bins; i++)
  {
   content = histo_MC_CohUps->GetBinContent(i);
   h1->SetBinContent(i, content);
  }
   h1->SetFillColor(kBlue);
   hs->Add(h1);
   
   TH1F *h2 = new TH1F("h2","test hstack", number_of_bins, 0, 4);
  // fill a histo, normal methods failed here :/
  for (int i=1; i<=number_of_bins; i++)
  {
   content = histo_MC_IncohUps->GetBinContent(i);
   h2->SetBinContent(i, content);
  }
   h2->SetFillColor(kRed);
   hs->Add(h2);
   
   TH1F *h3 = new TH1F("h3","test hstack", number_of_bins, 0, 4);
  // fill a histo, normal methods failed here :/
  for (int i=1; i<=number_of_bins; i++)
  {
   content = histo_MC_gg->GetBinContent(i);
   h3->SetBinContent(i, content);
  }
   h3->SetFillColor(kGreen);
   hs->Add(h3);
   
   TCanvas *cs = new TCanvas("cs","cs",10,10,1000,600);
   cs->SetLogy();
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
   hs->SetTitle("dimuon p_{T} distribution");

   hs->Draw(); 
   hs->GetXaxis()->SetTitle("p_{T} [GeV]");
   hs->GetYaxis()->SetTitle("dimuons");
   cs->Modified();  
  
  
   //T.DrawTextNDC(.5 ,.95 , "dimuon pT distribution");
   //histo_Data->Draw("E0");

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
  hd->Draw("same, E0");
  
  TLegend *l2 = new TLegend(0.6,0.5,0.8,0.7,NULL,"brNDC");
  //l2->AddEntry(histo_Data,"p_{T}^{2}","");
  l2->AddEntry(histo_Data,"Data","p");
  l2->AddEntry(histo_MC_gg,"MC #gamma#gamma","l");
  l2->AddEntry(histo_MC_CohUps,"MC coh #Upsilon","l");
  l2->AddEntry(histo_MC_IncohUps,"MC incoh #Upsilon","l");
  //l2->AddEntry(histo_res,"Sum","l");
  l2->SetFillColor(10);
  l2->Draw();



cout << "******* END *******" << endl << endl;

}








