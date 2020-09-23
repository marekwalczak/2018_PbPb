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


void DrawHisto_aco(){

bool save=1;

cout << "******* opening files *******" << endl;


    TFile* f1 = new TFile("plots_data_30mupt60_92m97/plots.root","read"); 
    TFile* f2 = new TFile("plots_MCgg_30mupt60_92m97/plots.root","read"); 
    TFile* f3 = new TFile("plots_MCc1s_30mupt60_official/plots.root","read"); 
    TFile* f4 = new TFile("plots_MCi1s_30mupt60_official/plots.root","read"); 

    TH1F *histo_Data = (TH1F *)f1->Get("histo_aco");
    TH1F *histo_MC_gg = (TH1F *)f2->Get("histo_aco");
    TH1F *histo_MC_CohUps = (TH1F *)f3->Get("histo_aco");
    TH1F *histo_MC_IncohUps = (TH1F *)f4->Get("histo_aco");


/* scale to given numbers

  double ups_from_fit = 270;
  double coh_fit_MC = ups_from_fit * 93.733 / (93.733 + 41.135);
  double incoh_fit_MC = ups_from_fit * 41.135 / (93.733 + 41.135);
  
//histo_Data->Scale(1./(histo_Data->Integral()));
  histo_MC_gg->Scale( (histo_Data->Integral() - ups_from_fit ) / histo_MC_gg->Integral() );
  histo_MC_CohUps->Scale( coh_fit_MC / histo_MC_CohUps->Integral() );
  histo_MC_IncohUps->Scale( incoh_fit_MC / histo_MC_IncohUps->Integral() );
*/

  // normalize
  histo_Data->Scale(1./(histo_Data->Integral()));
  histo_MC_gg->Scale( 1./(histo_MC_gg->Integral()) );
  histo_MC_CohUps->Scale( 1. / (histo_MC_CohUps->Integral()) );
  histo_MC_IncohUps->Scale( 1. / (histo_MC_IncohUps->Integral()) );


 
  int reb = 1;

  histo_Data->Rebin(reb);
  histo_MC_gg->Rebin(reb);
  histo_MC_CohUps->Rebin(reb);
  histo_MC_IncohUps->Rebin(reb);


  TCanvas *c1 = new TCanvas("c1","c1",1000,600);
  c1->SetLogy();

  histo_Data->SetLineStyle(1);
  histo_Data->SetLineWidth(2);
  histo_Data->SetLineColor(kBlack);
  histo_Data->SetTitle("acoplanarity distribution");

  histo_MC_gg->SetLineStyle(1);
  histo_MC_gg->SetLineWidth(4);
  histo_MC_gg->SetLineColor(kGreen);

  histo_MC_gg->Draw("Hist");

  histo_MC_CohUps->SetLineStyle(1);
  histo_MC_CohUps->SetLineWidth(4);
  histo_MC_CohUps->SetLineColor(kBlue);
  histo_MC_CohUps->Draw("same, Hist");

  histo_MC_IncohUps->SetLineStyle(1);
  histo_MC_IncohUps->SetLineWidth(4);
  histo_MC_IncohUps->SetLineColor(kRed);
  histo_MC_IncohUps->Draw("same, Hist");
  
    histo_Data->Draw("same, E0");

  histo_Data->SetStats(0);

  TLegend *l1 = new TLegend(0.60,0.70,0.9,0.9,NULL,"brNDC");
  //l1->AddEntry(histo_Data,"acoplanarity","");
  l1->AddEntry(histo_Data,"Data","l");
  l1->AddEntry(histo_MC_gg,"MC gg","l");
  l1->AddEntry(histo_MC_CohUps,"MC coh upsilon","l");
  l1->AddEntry(histo_MC_IncohUps,"MC incoh upsilon","l");
  l1->SetFillColor(10);
  l1->Draw();


  
  c1->Update();
  c1->SaveAs("aco.pdf");
    
  
cout << "******* END *******" << endl;


/*
//pT2
  TH1F *hjetfwdjtptData = (TH1F *)f1->Get("hjetfwdjtpt");
  TH1F *hjetfwdjtptMC = (TH1F *)f2->Get("hjetfwdjtpt");

  TH1F *hRatiojetfwdjtpt=new TH1F("hRatiojetfwdjtpt","hRatiojetfwdjtpt",40,0,200);
  hRatiojetfwdjtpt->Divide(hjetfwdjtptData,hjetfwdjtptMC,1,1);

  hjetfwdjtptData->Scale(1./(hjetfwdjtptData->Integral()));
  hjetfwdjtptMC->Scale(1./(hjetfwdjtptMC->Integral()));


*/

//**************CANVAS**************//
/*
  setStyle();


//jetfwdjtpt
  TCanvas *c2 = new TCanvas("c2","c2",600,600);
  c2->SetLogy();

  hjetfwdjtptData->GetXaxis()->SetRangeUser(0,150);
  hjetfwdjtptData->GetXaxis()->SetTitleOffset(1.2);
  hjetfwdjtptData->GetYaxis()->SetTitleOffset(1.22);
 
  hjetfwdjtptData->GetXaxis()->SetTitle("p_{T}^{jet} [GeV]");

  hjetfwdjtptData->SetMarkerStyle(8);
  hjetfwdjtptData->SetMarkerColor(kRed);
  hjetfwdjtptMC->SetLineColor(kBlue);

  hjetfwdjtptData->Draw("p");
  hjetfwdjtptMC->Draw("same");
 
  TLegend *l1 = new TLegend(0.60,0.70,0.85,0.80,NULL,"brNDC");

  l1->AddEntry(hjetfwdjtptData,"p_{T}>20 GeV, |#eta|>3","");
  l1->AddEntry(hjetfwdjtptData,"Data Pbp jet20","p");
  l1->AddEntry(hjetfwdjtptMC,"MC p_{T}^{hat}15","l");
  l1->SetFillColor(10);
  l1->Draw();

  c2->Update();
  if (save) c2->SaveAs("./plots/jetfwdjtpt.png");

*/

}








