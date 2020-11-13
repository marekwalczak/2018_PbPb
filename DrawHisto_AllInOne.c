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


void DrawHisto_AllInOne(){

system("mkdir AllInOne");

bool save=1;

cout << "******* opening files *******" << endl;


    TFile* f1 = new TFile("plots_data_92m97/plots.root","read"); 
    TFile* f2 = new TFile("plots_MCgg_30mupt_92m97_binning_upd/plots.root","read"); 
    TFile* f3 = new TFile("plots_MCc1s_30mupt60_binning/plots.root","read"); 
    TFile* f4 = new TFile("plots_MCi1s_30mupt60_binning/plots.root","read"); 


/***
 *                           _                        _ _         
 *                          | |                      (_) |        
 *      __ _  ___ ___  _ __ | | __ _ _ __   __ _ _ __ _| |_ _   _ 
 *     / _` |/ __/ _ \| '_ \| |/ _` | '_ \ / _` | '__| | __| | | |
 *    | (_| | (_| (_) | |_) | | (_| | | | | (_| | |  | | |_| |_| |
 *     \__,_|\___\___/| .__/|_|\__,_|_| |_|\__,_|_|  |_|\__|\__, |
 *                    | |                                    __/ |
 *                    |_|                                   |___/ 
 */


cout << "******* Acoplanarity... *******" << endl;

    TH1F *histo_Data_aco = (TH1F *)f1->Get("histo_aco");
    TH1F *histo_MC_gg_aco = (TH1F *)f2->Get("histo_aco");
    TH1F *histo_MC_CohUps_aco = (TH1F *)f3->Get("histo_aco");
    TH1F *histo_MC_IncohUps_aco = (TH1F *)f4->Get("histo_aco");

  // normalize
  histo_Data_aco->Scale(1./(histo_Data_aco->Integral()));
  histo_MC_gg_aco->Scale( 1./(histo_MC_gg_aco->Integral()) );
  histo_MC_CohUps_aco->Scale( 1. / (histo_MC_CohUps_aco->Integral()) );
  histo_MC_IncohUps_aco->Scale( 1. / (histo_MC_IncohUps_aco->Integral()) );


 
  int reb_c1 = 1;

  histo_Data_aco->Rebin(reb_c1);
  histo_MC_gg_aco->Rebin(reb_c1);
  histo_MC_CohUps_aco->Rebin(reb_c1);
  histo_MC_IncohUps_aco->Rebin(reb_c1);


  TCanvas *c1 = new TCanvas("c1","c1",1000,600);
  c1->SetLogy();

  histo_Data_aco->SetLineStyle(1);
  histo_Data_aco->SetLineWidth(2);
  histo_Data_aco->SetLineColor(kBlack);

  histo_MC_gg_aco->SetLineStyle(1);
  histo_MC_gg_aco->SetLineWidth(4);
  histo_MC_gg_aco->SetLineColor(kGreen);

  histo_MC_gg_aco->SetStats(0); // gets rid of anoying stat box
  histo_MC_gg_aco->SetTitle("normalised acoplanarity distribution");
  histo_MC_gg_aco->GetXaxis()->SetTitle("acoplanarity");
  histo_MC_gg_aco->GetYaxis()->SetTitle("a.u.");
  histo_MC_gg_aco->GetXaxis()->SetRangeUser(0,1);
  histo_MC_gg_aco->Draw("Hist");



  histo_MC_CohUps_aco->SetLineStyle(1);
  histo_MC_CohUps_aco->SetLineWidth(4);
  histo_MC_CohUps_aco->SetLineColor(kBlue);
  histo_MC_CohUps_aco->Draw("same, Hist");

  histo_MC_IncohUps_aco->SetLineStyle(1);
  histo_MC_IncohUps_aco->SetLineWidth(4);
  histo_MC_IncohUps_aco->SetLineColor(kRed);
  histo_MC_IncohUps_aco->Draw("same, Hist");
  
    histo_Data_aco->Draw("same, E0");


  TLegend *l1 = new TLegend(0.60,0.70,0.9,0.9,NULL,"brNDC");
  //l1->AddEntry(histo_Data_aco,"acoplanarity","");
  l1->AddEntry(histo_Data_aco,"Data","l");
  l1->AddEntry(histo_MC_gg_aco,"MC #gamma#gamma background","l");
  l1->AddEntry(histo_MC_CohUps_aco,"MC coherent #Upsilon(1S)","l");
  l1->AddEntry(histo_MC_IncohUps_aco,"MC incoherent #Upsilon(1S)","l");
  l1->SetFillColor(10);
  l1->Draw();


  
  c1->Update();
  c1->SaveAs("AllInOne/aco.pdf");
    
  
  /***
 *                                       _____ 
 *                                      |_   _|
 *     _ __ ___  _   _  ___  _ __    _ __ | |  
 *    | '_ ` _ \| | | |/ _ \| '_ \  | '_ \| |  
 *    | | | | | | |_| | (_) | | | | | |_) | |  
 *    |_| |_| |_|\__,_|\___/|_| |_| | .__/\_/  
 *                                  | |        
 *                                  |_|        
 */
  
cout << "******* muon pT... *******" << endl;




    TH1F *histo_Data_mu_pT = (TH1F *)f1->Get("histo_mu_pT");
    TH1F *histo_MC_gg_mu_pT = (TH1F *)f2->Get("histo_mu_pT");
    TH1F *histo_MC_CohUps_mu_pT = (TH1F *)f3->Get("histo_mu_pT");
    TH1F *histo_MC_IncohUps_mu_pT = (TH1F *)f4->Get("histo_mu_pT");

  // normalize
  histo_Data_mu_pT->Scale(1./(histo_Data_mu_pT->Integral()));
  histo_MC_gg_mu_pT->Scale( 1./(histo_MC_gg_mu_pT->Integral()) );
  histo_MC_CohUps_mu_pT->Scale( 1. / (histo_MC_CohUps_mu_pT->Integral()) );
  histo_MC_IncohUps_mu_pT->Scale( 1. / (histo_MC_IncohUps_mu_pT->Integral()) );


 
  int reb_c2 = 2;

  histo_Data_mu_pT->Rebin(reb_c2);
  histo_MC_gg_mu_pT->Rebin(reb_c2);
  histo_MC_CohUps_mu_pT->Rebin(reb_c2);
  histo_MC_IncohUps_mu_pT->Rebin(reb_c2);


  TCanvas *c2 = new TCanvas("c2","c2",1000,600);
  //c2->SetLogy();

  histo_Data_mu_pT->SetLineStyle(1);
  histo_Data_mu_pT->SetLineWidth(2);
  histo_Data_mu_pT->SetLineColor(kBlack);

  histo_MC_gg_mu_pT->SetLineStyle(1);
  histo_MC_gg_mu_pT->SetLineWidth(4);
  histo_MC_gg_mu_pT->SetLineColor(kGreen);

  histo_MC_gg_mu_pT->SetStats(0); // gets rid of anoying stat box
  histo_MC_gg_mu_pT->SetTitle("normalised acoplanarity distribution");
  histo_MC_gg_mu_pT->GetXaxis()->SetTitle("acoplanarity");
  histo_MC_gg_mu_pT->GetYaxis()->SetTitle("a.u.");
  histo_MC_gg_mu_pT->GetXaxis()->SetRangeUser(0,8);
  histo_MC_gg_mu_pT->Draw("Hist");



  histo_MC_CohUps_mu_pT->SetLineStyle(1);
  histo_MC_CohUps_mu_pT->SetLineWidth(4);
  histo_MC_CohUps_mu_pT->SetLineColor(kBlue);
  histo_MC_CohUps_mu_pT->Draw("same, Hist");

  histo_MC_IncohUps_mu_pT->SetLineStyle(1);
  histo_MC_IncohUps_mu_pT->SetLineWidth(4);
  histo_MC_IncohUps_mu_pT->SetLineColor(kRed);
  histo_MC_IncohUps_mu_pT->Draw("same, Hist");
  
    histo_Data_mu_pT->Draw("same, E0");


  TLegend *l2 = new TLegend(0.60,0.70,0.9,0.9,NULL,"brNDC");
  //l2->AddEntry(histo_Data_mu_pT,"acoplanarity","");
  l2->AddEntry(histo_Data_mu_pT,"Data","l");
  l2->AddEntry(histo_MC_gg_mu_pT,"MC #gamma#gamma background","l");
  l2->AddEntry(histo_MC_CohUps_mu_pT,"MC coherent #Upsilon(1S)","l");
  l2->AddEntry(histo_MC_IncohUps_mu_pT,"MC incoherent #Upsilon(1S)","l");
  l2->SetFillColor(10);
  l2->Draw();


  
  c2->Update();
  c2->SaveAs("AllInOne/mu_pT.pdf");




  
/***
 *                                                   
 *                                                   
 *     _ __ ___  _   _  ___  _ __    _ __ __ _ _ __  
 *    | '_ ` _ \| | | |/ _ \| '_ \  | '__/ _` | '_ \ 
 *    | | | | | | |_| | (_) | | | | | | | (_| | |_) |
 *    |_| |_| |_|\__,_|\___/|_| |_| |_|  \__,_| .__/ 
 *                                            | |    
 *                                            |_|    
 */
 
cout << "******* muon rap... *******" << endl;

  
/***
 *         _ _                                   _____ 
 *        | (_)                                 |_   _|
 *      __| |_ _ __ ___  _   _  ___  _ __    _ __ | |  
 *     / _` | | '_ ` _ \| | | |/ _ \| '_ \  | '_ \| |  
 *    | (_| | | | | | | | |_| | (_) | | | | | |_) | |  
 *     \__,_|_|_| |_| |_|\__,_|\___/|_| |_| | .__/\_/  
 *                                          | |        
 *                                          |_|        
 */  
  
cout << "******* dimuon pT.. *******" << endl;
/***
 *         _ _                                               
 *        | (_)                                              
 *      __| |_ _ __ ___  _   _  ___  _ __    _ __ __ _ _ __  
 *     / _` | | '_ ` _ \| | | |/ _ \| '_ \  | '__/ _` | '_ \ 
 *    | (_| | | | | | | | |_| | (_) | | | | | | | (_| | |_) |
 *     \__,_|_|_| |_| |_|\__,_|\___/|_| |_| |_|  \__,_| .__/ 
 *                                                    | |    
 *                                                    |_|    
 */  
cout << "******* dimuon rap... *******" << endl;

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
cout << "******* END *******" << endl;



}








