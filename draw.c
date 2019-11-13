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



void draw(){

  system("mkdir plots/pdf");

cout << "******* opening files *******" << endl;

TFile* f1 = new TFile("plots/plots.root","read");


cout << endl << "******* getting histos *******" << endl << endl;

  TH1F *histo_HF_energy_Min = (TH1F *)f1->Get("histo_HF_energy_Min"); // c1
  TH1F *histo_HF_energy_Pl = (TH1F *)f1->Get("histo_HF_energy_Pl"); // c2
  TH2F *sp_HF = (TH2F *)f1->Get("sp_HF"); // c3
  TH2F *sp_QQ_Ntrk_QQ_size = (TH2F *)f1->Get("sp_QQ_Ntrk_QQ_size"); // c4
  TH2F *sp_Ntracks_QQ_size = (TH2F *)f1->Get("sp_Ntracks_QQ_size"); // c5
  TH2F *sp_Ntracks_QQ_Ntrk = (TH2F *)f1->Get("sp_Ntracks_QQ_Ntrk"); // c6

  TH1F *histo_QQ_size = (TH1F *)f1->Get("histo_QQ_size"); // c7
  TH1F *histo_QQ_Ntrk = (TH1F *)f1->Get("histo_QQ_Ntrk"); // c8
  TH1F *histo_Ntracks = (TH1F *)f1->Get("histo_Ntracks"); // c9
  TH1F *histo_QQ_M = (TH1F *)f1->Get("histo_QQ_M"); // c10
  histo_QQ_M->Rebin(4);
  
  
  TH1F *histo_QQ_pT = (TH1F *)f1->Get("histo_QQ_pT"); // c11

  TH1F *histo_QQ_pT2 = (TH1F *)f1->Get("histo_QQ_pT2"); // c12
  TH1F *histo_QQ_vtx_z = (TH1F *)f1->Get("histo_QQ_vtx_z"); // c13



  TH1F *histo_QQ_rap = (TH1F *)f1->Get("histo_QQ_rap"); // c14


  
  TH2F* sp_QQ_pT_QQ_rap = (TH2F *)f1->Get("sp_QQ_pT_QQ_rap"); // c19


 // TH2F* sp_mu_pT_mu_rap = (TH2F *)f1->Get("sp_mu_pT_mu_rap"); // c22



 // TH1F *histo_mu_pT = (TH1F *)f1->Get("histo_mu_pT"); // c15
 // TH1F *histo_mu_rap = (TH1F *)f1->Get("histo_mu_rap"); // c16

          
  TH1F *histo_aco = (TH1F *)f1->Get("histo_aco"); // c27
 // TH1F* histo_mu_Phi = (TH1F *)f1->Get("histo_mu_Phi"); // c28
  TH1F* histo_QQ_Phi = (TH1F *)f1->Get("histo_QQ_Phi"); // c29


  
  cout << endl << "******* saving histos *******" << endl << endl;
  
	TCanvas *c1 = new TCanvas("c1","c1",1000,600);
	histo_HF_energy_Min->SetLineWidth(2);
	//histo_HF_energy_Min->SetLineColor(kViolet);
	histo_HF_energy_Min->Draw("");
	c1->SaveAs("./plots/pdf/histo_HF_energy_Min.pdf"); 

	TCanvas *c2 = new TCanvas("c2","c2",1000,600);
	histo_HF_energy_Pl->SetLineWidth(2);
	histo_HF_energy_Pl->Draw("");
	c2->SaveAs("./plots/pdf/histo_HF_energy_Pl.pdf"); 
	
	TCanvas *c3 = new TCanvas("c3","c3",1000,1000);
	sp_HF->Draw("colz");
	c3->SaveAs("./plots/pdf/sp_HF.pdf"); 
	
	TCanvas *c4 = new TCanvas("c4","c4",1000,1000);
	sp_QQ_Ntrk_QQ_size->Draw("colz");
	c4->SaveAs("./plots/pdf/sp_QQ_Ntrk_QQ_size.pdf"); 
	
	TCanvas *c5 = new TCanvas("c5","c5",1000,1000);
	sp_Ntracks_QQ_size->Draw("colz");
	c5->SaveAs("./plots/pdf/sp_Ntracks_QQ_size.pdf"); 
	
	TCanvas *c6 = new TCanvas("c6","c6",1000,1000);
	sp_Ntracks_QQ_Ntrk->Draw("colz");
	c6->SaveAs("./plots/pdf/sp_Ntracks_QQ_Ntrk.pdf"); 
	
	TCanvas *c7 = new TCanvas("c7","c7",1000,600);
	histo_QQ_size->SetLineWidth(2);
	histo_QQ_size->Draw("");
	c7->SaveAs("./plots/pdf/histo_QQ_size.pdf"); 
	
	TCanvas *c8 = new TCanvas("c8","c8",1000,600);
	histo_QQ_Ntrk->SetLineWidth(2);
	histo_QQ_Ntrk->Draw("");
	c8->SaveAs("./plots/pdf/histo_QQ_Ntrk.pdf"); 
	
	TCanvas *c9 = new TCanvas("c9","c9",1000,600);
	histo_Ntracks->SetLineWidth(2);
	histo_Ntracks->Draw("");
	c9->SaveAs("./plots/pdf/histo_Ntracks.pdf"); 
	
	TCanvas *c10 = new TCanvas("c10","c10",1000,600);
	histo_QQ_M->SetLineWidth(2);
	histo_QQ_M->Draw("");
	c10->SaveAs("./plots/pdf/histo_QQ_M.pdf"); 
	
	TCanvas *c11 = new TCanvas("c11","c11",1000,600);
	histo_QQ_pT->SetLineWidth(2);
	histo_QQ_pT->Draw("");
	c11->SaveAs("./plots/pdf/histo_QQ_pT.pdf"); 
	
	TCanvas *c12 = new TCanvas("c12","c12",1000,600);
	histo_QQ_pT2->SetLineWidth(2);
	histo_QQ_pT2->Draw("");
	c12->SaveAs("./plots/pdf/histo_QQ_pT2.pdf"); 
	
	TCanvas *c13 = new TCanvas("c13","c13",1000,600);
	histo_QQ_vtx_z->SetLineWidth(2);
	histo_QQ_vtx_z->Draw("");
	c13->SaveAs("./plots/pdf/histo_QQ_vtx_z.pdf"); 
	
	TCanvas *c14 = new TCanvas("c14","c14",1000,600);
	histo_QQ_rap->SetLineWidth(2);
	histo_QQ_rap->Draw("");
	c14->SaveAs("./plots/pdf/histo_QQ_rap.pdf"); 
	/*
	TCanvas *c15 = new TCanvas("c15","c15",1000,600);
	histo_mu_pT->SetLineWidth(2);
	histo_mu_pT->Draw("");
	c15->SaveAs("./plots/pdf/histo_mu_pT.pdf"); 
	
	TCanvas *c16 = new TCanvas("c16","c16",1000,600);
	histo_mu_rap->SetLineWidth(2);
	histo_mu_rap->Draw("");
	c16->SaveAs("./plots/pdf/histo_mu_rap.pdf"); 
    
	TCanvas *c19 = new TCanvas("c19","c19",1000,600);
	sp_QQ_pT_QQ_rap->Draw("colz");
	c19->SaveAs("./plots/pdf/sp_QQ_pT_QQ_rap.pdf"); 
	TCanvas *c22 = new TCanvas("c22","c22",1000,600);
	sp_mu_pT_mu_rap->Draw("colz");
	c22->SaveAs("./plots/pdf/sp_mu_pT_mu_rap.pdf"); 
	*/
	
	
	TCanvas *c27 = new TCanvas("c27","c27",1000,600);
	histo_aco->SetLineWidth(2);
	histo_aco->Draw("");
	c27->SaveAs("./plots/pdf/histo_aco.pdf"); 
	
	/*
	TCanvas *c28 = new TCanvas("c28","c28",1000,600);
	histo_mu_Phi->SetLineWidth(2);
	histo_mu_Phi->Draw("");
	c28->SaveAs("./plots/pdf/histo_mu_Phi.pdf"); 
	*/
	
	TCanvas *c29 = new TCanvas("c29","c29",1000,600);
	histo_QQ_Phi->SetLineWidth(2);
	histo_QQ_Phi->Draw("");
	c29->SaveAs("./plots/pdf/histo_QQ_Phi.pdf"); 

/*

  // for MC: will crash for data

  TH1F* histo_QQ_rap_Gen = (TH1F *)f1->Get("histo_QQ_rap_Gen"); // c17
  TH1F* histo_QQ_rap_Acc = (TH1F *)f1->Get("histo_QQ_rap_Acc"); // c18
  TH2F* sp_QQ_pT_QQ_rap_Gen = (TH2F *)f1->Get("sp_QQ_pT_QQ_rap_Gen"); // c20
  TH2F* sp_QQ_pT_QQ_rap_Acc = (TH2F *)f1->Get("sp_QQ_pT_QQ_rap_Acc"); // c21
  TH1F* histo_QQ_pT_Gen = (TH1F *)f1->Get("histo_QQ_pT_Gen"); // c11b
  TH1F* histo_QQ_pT_Acc = (TH1F *)f1->Get("histo_QQ_pT_Acc"); // c11c
  TH2F* sp_mu_pT_mu_rap_Gen = (TH2F *)f1->Get("sp_mu_pT_mu_rap_Gen"); // c23
  TH2F* sp_mu_pT_mu_rap_Acc = (TH2F *)f1->Get("sp_mu_pT_mu_rap_Acc"); // c24
  TH1F* histo_mu_rap_Gen = (TH1F *)f1->Get("histo_mu_rap_Gen"); // c25
  TH1F* histo_mu_rap_Acc = (TH1F *)f1->Get("histo_mu_rap_Acc"); // c26  

  double acc = 0;
  // get the ave acc
  for (int i=1; i<=100; i++)
  {
   acc += histo_mu_rap_Acc->GetBinContent(i);
  }
  acc /= 48;
   cout << endl << endl << "ave acc: " << acc << endl << endl;


  double gen = 0;
  // get the ave acc
  for (int i=27; i<75; i++)
  {
   gen += histo_mu_rap_Gen->GetBinContent(i);
  }
   cout << endl << endl << "gen for -2.4 < |eta| < 2.4: " << gen << endl << endl;

  double rap = 0;
  // get the ave acc
  for (int i=27; i<75; i++)
  {
   rap += histo_mu_rap->GetBinContent(i);
  }
   cout << endl << endl << "rap for -2.4 < |eta| < 2.4: " << rap << endl << endl;

   cout << endl << endl << "rap / gen : " << rap/gen << endl << endl;
   cout << endl << endl << "bin 0 : " << histo_mu_rap_Gen->GetBinContent(0) << endl << endl;
   cout << endl << endl << "bin 1 : " << histo_mu_rap_Gen->GetBinContent(3) << endl << endl;
   cout << endl << endl << "bin 99 : " << histo_mu_rap_Gen->GetBinContent(99) << endl << endl;
   cout << endl << endl << "bin 100 : " << histo_mu_rap_Gen->GetBinContent(100) << endl << endl;
   cout << endl << endl << "bin 50 : " << histo_mu_rap_Gen->GetBinContent(50) << endl << endl;


  
	TCanvas *c17 = new TCanvas("c17","c17",1000,600);
	histo_QQ_rap_Gen->SetLineWidth(2);
	histo_QQ_rap_Gen->Draw("");
	c17->SaveAs("./plots/pdf/histo_QQ_rap_Gen.pdf"); 
	
	TCanvas *c18 = new TCanvas("c18","c18",1000,600);
	histo_QQ_rap_Acc->SetLineWidth(2);
	histo_QQ_rap_Acc->Draw("");
	c18->SaveAs("./plots/pdf/histo_QQ_rap_Acc.pdf"); 
	
	
	TCanvas *c20 = new TCanvas("c20","c20",1000,600);
	sp_QQ_pT_QQ_rap_Gen->Draw("colz");
	c20->SaveAs("./plots/pdf/sp_QQ_pT_QQ_rap_Gen.pdf"); 
	
	TCanvas *c11b = new TCanvas("c11b","c11b",1000,600);
	histo_QQ_pT_Gen->SetLineWidth(2);
	histo_QQ_pT_Gen->Draw("");
	c11b->SaveAs("./plots/pdf/histo_QQ_pT_Gen.pdf"); 
	
	TCanvas *c11c = new TCanvas("c11c","c11c",1000,600);
	histo_QQ_pT_Acc->SetLineWidth(2);
	histo_QQ_pT_Acc->Draw("");
	c11c->SaveAs("./plots/pdf/histo_QQ_pT_Acc.pdf"); 

	TCanvas *c21 = new TCanvas("c21","c21",1000,600);
	sp_QQ_pT_QQ_rap_Acc->Draw("colz");
	c21->SaveAs("./plots/pdf/sp_QQ_pT_QQ_rap_Acc.pdf"); 

	TCanvas *c23 = new TCanvas("c23","c23",1000,600);
	sp_mu_pT_mu_rap_Gen->Draw("colz");
	c23->SaveAs("./plots/pdf/sp_mu_pT_mu_rap_Gen.pdf"); 
	
	TCanvas *c24 = new TCanvas("c24","c24",1000,600);
	sp_mu_pT_mu_rap_Acc->Draw("colz");
	c24->SaveAs("./plots/pdf/sp_mu_pT_mu_rap_Acc.pdf"); 
	
	TCanvas *c25 = new TCanvas("c25","c25",1000,600);
	histo_mu_rap_Gen->SetLineWidth(2);
	histo_mu_rap_Gen->Draw("");
	c25->SaveAs("./plots/pdf/histo_mu_rap_Gen.pdf"); 
	
	TCanvas *c26 = new TCanvas("c26","c26",1000,600);
	histo_mu_rap_Acc->SetLineWidth(2);
	histo_mu_rap_Acc->Draw("");
	
	c26->SaveAs("./plots/pdf/histo_mu_rap_Acc.pdf"); 
	*/
	
	cout << endl << "******* THE END *******" << endl << endl;


}



















