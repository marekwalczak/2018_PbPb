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

  system("rm -r plots/pdf");

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
  //histo_QQ_M->Rebin(4);
  
  
  TH1F *histo_QQ_pT = (TH1F *)f1->Get("histo_QQ_pT"); // c11

  TH1F *histo_QQ_pT2 = (TH1F *)f1->Get("histo_QQ_pT2"); // c12
  TH1F *histo_QQ_vtx_z = (TH1F *)f1->Get("histo_QQ_vtx_z"); // c13



  TH1F *histo_QQ_rap = (TH1F *)f1->Get("histo_QQ_rap"); // c14


  
  TH2F* sp_QQ_pT_QQ_rap = (TH2F *)f1->Get("sp_QQ_pT_QQ_rap"); // c19





  TH2F* sp_mu_pT_mu_rap = (TH2F *)f1->Get("sp_mu_pT_mu_rap"); // c22



  TH1F *histo_mu_pT = (TH1F *)f1->Get("histo_mu_pT"); // c15
  TH1F *histo_mu_rap = (TH1F *)f1->Get("histo_mu_rap"); // c16
  TH2F *sp_QQ_pT_Aco = (TH2F *)f1->Get("sp_QQ_pT_Aco"); // c88

          
          
  TH1F *histo_aco = (TH1F *)f1->Get("histo_aco"); // c27
  TH1F* histo_mu_Phi = (TH1F *)f1->Get("histo_mu_Phi"); // c28
  TH1F* histo_QQ_Phi = (TH1F *)f1->Get("histo_QQ_Phi"); // c29

  TH2F *sp_mupl_rap_mumi_rap = (TH2F *)f1->Get("sp_mupl_rap_mumi_rap"); // c89
  TH2F *sp_mupl_pT_mumi_pT = (TH2F *)f1->Get("sp_mupl_pT_mumi_pT"); // c90


  
  cout << endl << "******* saving histos *******" << endl << endl;
  
	TCanvas *c1 = new TCanvas("c1","c1",1000,600);
	histo_HF_energy_Min->SetStats(0); // gets rid of anoying stat box
	histo_HF_energy_Min->SetLineWidth(4);
	//histo_HF_energy_Min->SetLineColor(kViolet);
	histo_HF_energy_Min->Draw("");
	c1->SaveAs("./plots/pdf/histo_HF_energy_Min.pdf"); 

	TCanvas *c2 = new TCanvas("c2","c2",1000,600);
	histo_HF_energy_Pl->SetStats(0); // gets rid of anoying stat box
	histo_HF_energy_Pl->SetLineWidth(4);
	histo_HF_energy_Pl->Draw("");
	c2->SaveAs("./plots/pdf/histo_HF_energy_Pl.pdf"); 
	
	TCanvas *c3 = new TCanvas("c3","c3",1000,1000);
	sp_HF->SetStats(0); // gets rid of anoying stat box
	sp_HF->Draw("colz");
	c3->SaveAs("./plots/pdf/sp_HF.pdf"); 
	
	TCanvas *c4 = new TCanvas("c4","c4",1000,1000);
	sp_QQ_Ntrk_QQ_size->SetStats(0); // gets rid of anoying stat box
	sp_QQ_Ntrk_QQ_size->Draw("colz");
	c4->SaveAs("./plots/pdf/sp_QQ_Ntrk_QQ_size.pdf"); 
	
	TCanvas *c5 = new TCanvas("c5","c5",1000,1000);
	sp_Ntracks_QQ_size->SetStats(0); // gets rid of anoying stat box
	sp_Ntracks_QQ_size->Draw("colz");
	c5->SaveAs("./plots/pdf/sp_Ntracks_QQ_size.pdf"); 
	
	TCanvas *c6 = new TCanvas("c6","c6",1000,1000);
	sp_Ntracks_QQ_Ntrk->SetStats(0); // gets rid of anoying stat box
	sp_Ntracks_QQ_Ntrk->Draw("colz");
	c6->SaveAs("./plots/pdf/sp_Ntracks_QQ_Ntrk.pdf"); 
	
	TCanvas *c7 = new TCanvas("c7","c7",1000,600);
	histo_QQ_size->SetStats(0); // gets rid of anoying stat box
	histo_QQ_size->SetLineWidth(4);
	histo_QQ_size->Draw("");
	c7->SaveAs("./plots/pdf/histo_QQ_size.pdf"); 
	
	TCanvas *c8 = new TCanvas("c8","c8",1000,600);
	histo_QQ_Ntrk->SetStats(0); // gets rid of anoying stat box
	histo_QQ_Ntrk->SetLineWidth(4);
	histo_QQ_Ntrk->Draw("");
	c8->SaveAs("./plots/pdf/histo_QQ_Ntrk.pdf"); 
	
	TCanvas *c9 = new TCanvas("c9","c9",1000,600);
	histo_Ntracks->SetStats(0); // gets rid of anoying stat box
	histo_Ntracks->SetLineWidth(4);
	histo_Ntracks->Draw("");
	c9->SaveAs("./plots/pdf/histo_Ntracks.pdf"); 
	
	TCanvas *c10 = new TCanvas("c10","c10",1000,600);
	histo_QQ_M->SetStats(0); // gets rid of anoying stat box
	histo_QQ_M->SetLineWidth(4);
	histo_QQ_M->SetTitle("dimuon invariant mass distribution");
	//histo_QQ_M->GetXaxis()->SetTitleOffset(1.2);
	histo_QQ_M->GetXaxis()->SetTitle("M_{#mu#mu}");
	histo_QQ_M->Draw("");
	c10->SaveAs("./plots/pdf/histo_QQ_M.pdf"); 
	
	TCanvas *c11 = new TCanvas("c11","c11",1000,600);
	histo_QQ_pT->SetStats(0); // gets rid of anoying stat box
	histo_QQ_pT->SetLineWidth(4);
	histo_QQ_pT->SetTitle("dimuon transverse momenta distribution");
	histo_QQ_pT->GetXaxis()->SetRangeUser(0,4);
	histo_QQ_pT->GetXaxis()->SetTitleOffset(1.2);
	histo_QQ_pT->GetXaxis()->SetTitle("p^{#mu#mu}_{T}");
	histo_QQ_pT->Draw("");
	c11->SaveAs("./plots/pdf/histo_QQ_pT.pdf"); 
	c11->SetLogy();
	histo_QQ_pT->Draw("");
	c11->SaveAs("./plots/pdf/histo_QQ_pT_log.pdf"); 

	TCanvas *c12 = new TCanvas("c12","c12",1000,600);
	histo_QQ_pT2->SetStats(0); // gets rid of anoying stat box
	histo_QQ_pT2->SetLineWidth(4);
	histo_QQ_pT2->Draw("");
	c12->SaveAs("./plots/pdf/histo_QQ_pT2.pdf"); 
	
	TCanvas *c13 = new TCanvas("c13","c13",1000,600);
	histo_QQ_vtx_z->SetStats(0); // gets rid of anoying stat box
	histo_QQ_vtx_z->SetLineWidth(4);
	histo_QQ_vtx_z->Draw("");
	c13->SaveAs("./plots/pdf/histo_QQ_vtx_z.pdf"); 
	
	TCanvas *c14 = new TCanvas("c14","c14",1000,600);
	histo_QQ_rap->SetLineWidth(4);
	histo_QQ_rap->SetTitle("dimuon rapidity distribution");
	histo_QQ_rap->GetXaxis()->SetRangeUser(-4,4);
	histo_QQ_rap->GetXaxis()->SetTitle("rapidity");
	histo_QQ_rap->Draw("");
	c14->SaveAs("./plots/pdf/histo_QQ_rap.pdf"); 

	TCanvas *c15 = new TCanvas("c15","c15",1000,600);
	histo_mu_pT->SetStats(0); // gets rid of anoying stat box
	histo_mu_pT->SetLineWidth(4);
	//histo_mu_pT->GetXaxis()->SetRangeUser(0,3);
	histo_mu_pT->SetTitle("distribution of muon transverse momenta");
	histo_mu_pT->GetXaxis()->SetTitleOffset(1.2);
	histo_mu_pT->GetXaxis()->SetTitle("p^{#mu}_{T}");
	histo_mu_pT->GetYaxis()->SetTitle("muons");
	histo_mu_pT->Draw("");
	c15->SaveAs("./plots/pdf/histo_mu_pT.pdf"); 
	
	TCanvas *c16 = new TCanvas("c16","c16",1000,600);
	histo_mu_rap->SetStats(0); // gets rid of anoying stat box
	histo_mu_rap->SetLineWidth(4);
	histo_mu_rap->GetXaxis()->SetRangeUser(-3,3);
	histo_mu_rap->SetTitle("distribution of muon rapidity");
	histo_mu_rap->GetXaxis()->SetTitle("muon rapidity");
	histo_mu_rap->GetYaxis()->SetTitle("muons");
	histo_mu_rap->Draw("");
	c16->SaveAs("./plots/pdf/histo_mu_rap.pdf"); 
    
	TCanvas *c19 = new TCanvas("c19","c19",1000,600);
	sp_QQ_pT_QQ_rap->SetStats(0); // gets rid of anoying stat box
	sp_QQ_pT_QQ_rap->Draw("colz");
	c19->SaveAs("./plots/pdf/sp_QQ_pT_QQ_rap.pdf"); 
	
	
	
	
	
	
	
	
  float point1eta = 1.0;
  float point1pT = 3.3;

  float point2eta = 1.4;
  float point2pT = 2.1;

  float point3eta = 1.6;
  float point3pT = point2pT;

  float point4eta = 2.1;
  float point4pT = 1.2;

  TLine *l913 = new TLine(-0.3, point1pT, 0.3, point1pT);
  TLine *l913b = new TLine(0.3, point1pT, 0.3, point1pT);
  TLine *l913c = new TLine(0.3, point1pT, point1eta, point1pT);
  TLine *l914 = new  TLine(point1eta, point1pT, point2eta, point2pT);
  TLine *l915 = new  TLine(point2eta, point2pT, point3eta, point3pT);
  TLine *l916 = new  TLine(point3eta, point3pT, point4eta, point4pT);
  TLine *l917 = new  TLine(point4eta, point4pT, 2.4, point4pT);
  TLine *l918 = new  TLine(2.4, point4pT, 2.4, 8.0);
  TLine *l923b = new TLine(-0.3, point1pT, -0.3, point1pT);
  TLine *l923c = new TLine(-0.3, point1pT, -1*point1eta, point1pT);
  TLine *l924 = new  TLine(-1*point1eta, point1pT, -1*point2eta, point2pT);
  TLine *l925 = new  TLine(-1*point2eta, point2pT, -1*point3eta, point3pT);
  TLine *l926 = new  TLine(-1*point3eta, point3pT, -1*point4eta, point4pT);
  TLine *l927 = new  TLine(-1*point4eta, point4pT, -2.4, point4pT);
  TLine *l928 = new  TLine(-2.4, point4pT, -2.4, 8.0);
  
  l913->SetLineColor(kRed);
  l913->SetLineWidth(2);
  l913b->SetLineColor(kRed);
  l913b->SetLineWidth(2);
  l913c->SetLineColor(kRed);
  l913c->SetLineWidth(2);
  l914->SetLineColor(kRed);
  l914->SetLineWidth(2);
  l915->SetLineColor(kRed);
  l915->SetLineWidth(2);
  l916->SetLineColor(kRed);
  l916->SetLineWidth(2);
  l917->SetLineColor(kRed);
  l917->SetLineWidth(2);
  l918->SetLineColor(kRed);
  l918->SetLineWidth(2);
  l923b->SetLineColor(kRed);
  l923b->SetLineWidth(2);
  l923c->SetLineColor(kRed);
  l923c->SetLineWidth(2);
  l924->SetLineColor(kRed);
  l924->SetLineWidth(2);
  l925->SetLineColor(kRed);
  l925->SetLineWidth(2);
  l926->SetLineColor(kRed);
  l926->SetLineWidth(2);
  l927->SetLineColor(kRed);
  l927->SetLineWidth(2);
  l928->SetLineColor(kRed);
  l928->SetLineWidth(2);
	
	
	
	
  float point_ShuaiNEW_1eta = 1.0;
  float point_ShuaiNEW_1pT = 3.3;
  
  float point_ShuaiNEW_2eta = 1.4;
  float point_ShuaiNEW_2pT = 2.1;

  float point_ShuaiNEW_3eta = 1.4;
  float point_ShuaiNEW_3pT = 1.4;

  float point_ShuaiNEW_4eta = 1.7;
  float point_ShuaiNEW_4pT = 1.0;
  
  TLine *l713 = new TLine(-0.3, 3.3, 0.3, 3.3);
  TLine *l713b = new TLine(0.3, 3.3, 0.3, 3.3);
  TLine *l713c = new TLine(0.3, point_ShuaiNEW_1pT, point_ShuaiNEW_1eta, point_ShuaiNEW_1pT);
  TLine *l714 = new  TLine(point_ShuaiNEW_1eta, point_ShuaiNEW_1pT, point_ShuaiNEW_2eta, point_ShuaiNEW_2pT);
  TLine *l715 = new  TLine(point_ShuaiNEW_2eta, point_ShuaiNEW_2pT, point_ShuaiNEW_3eta, point_ShuaiNEW_3pT);
  TLine *l716 = new  TLine(point_ShuaiNEW_3eta, point_ShuaiNEW_3pT, point_ShuaiNEW_4eta, point_ShuaiNEW_4pT);
  TLine *l717 = new  TLine(point_ShuaiNEW_4eta, point_ShuaiNEW_4pT, 2.4, point_ShuaiNEW_4pT);
  TLine *l718 = new  TLine(2.4, point_ShuaiNEW_4pT, 2.4, 8.0);
  TLine *l723b = new TLine(-0.3, point_ShuaiNEW_1pT, -0.3, point_ShuaiNEW_1pT);
  TLine *l723c = new TLine(-0.3, point_ShuaiNEW_1pT, -1*point_ShuaiNEW_1eta, point_ShuaiNEW_1pT);
  TLine *l724 = new  TLine(-1*point_ShuaiNEW_1eta, point_ShuaiNEW_1pT, -1*point_ShuaiNEW_2eta, point_ShuaiNEW_2pT);
  TLine *l725 = new  TLine(-1*point_ShuaiNEW_2eta, point_ShuaiNEW_2pT, -1*point_ShuaiNEW_3eta, point_ShuaiNEW_3pT);
  TLine *l726 = new  TLine(-1*point_ShuaiNEW_3eta, point_ShuaiNEW_3pT, -1*point_ShuaiNEW_4eta, point_ShuaiNEW_4pT);
  TLine *l727 = new  TLine(-1*point_ShuaiNEW_4eta, point_ShuaiNEW_4pT, -2.4, point_ShuaiNEW_4pT);
  TLine *l728 = new  TLine(-2.4, point_ShuaiNEW_4pT, -2.4, 8.0);
  
  l713->SetLineColor(kBlack);
  l713->SetLineWidth(2);
  l713b->SetLineColor(kBlack);
  l713b->SetLineWidth(2);
  l713c->SetLineColor(kBlack);
  l713c->SetLineWidth(2);
  l714->SetLineColor(kBlack);
  l714->SetLineWidth(2);
  l715->SetLineColor(kBlack);
  l715->SetLineWidth(2);
  l716->SetLineColor(kBlack);
  l716->SetLineWidth(2);
  l717->SetLineColor(kBlack);
  l717->SetLineWidth(2);
  l718->SetLineColor(kBlack);
  l718->SetLineWidth(2);
  l723b->SetLineColor(kBlack);
  l723b->SetLineWidth(2);
  l723c->SetLineColor(kBlack);
  l723c->SetLineWidth(2);
  l724->SetLineColor(kBlack);
  l724->SetLineWidth(2);
  l725->SetLineColor(kBlack);
  l725->SetLineWidth(2);
  l726->SetLineColor(kBlack);
  l726->SetLineWidth(2);
  l727->SetLineColor(kBlack);
  l727->SetLineWidth(2);
  l728->SetLineColor(kBlack);
  l728->SetLineWidth(2);

  
  l713->SetLineColor(kBlack);
  l713->SetLineStyle(3);
  l713b->SetLineColor(kBlack);
  l713b->SetLineStyle(3);
  l713c->SetLineColor(kBlack);
  l713c->SetLineStyle(3);
  l714->SetLineColor(kBlack);
  l714->SetLineStyle(3);
  l715->SetLineColor(kBlack);
  l715->SetLineStyle(3);
  l716->SetLineColor(kBlack);
  l716->SetLineStyle(3);
  l717->SetLineColor(kBlack);
  l717->SetLineStyle(3);
  l718->SetLineColor(kBlack);
  l718->SetLineStyle(3);
  l723b->SetLineColor(kBlack);
  l723b->SetLineStyle(3);
  l723c->SetLineColor(kBlack);
  l723c->SetLineStyle(3);
  l724->SetLineColor(kBlack);
  l724->SetLineStyle(3);
  l725->SetLineColor(kBlack);
  l725->SetLineStyle(3);
  l726->SetLineColor(kBlack);
  l726->SetLineStyle(3);
  l727->SetLineColor(kBlack);
  l727->SetLineStyle(3);
  l728->SetLineColor(kBlack);
  l728->SetLineStyle(3);

	
	
	
	
	
	TCanvas *c22 = new TCanvas("c22","c22",1000,600);
	sp_mu_pT_mu_rap->SetStats(0); // gets rid of anoying stat box
	sp_mu_pT_mu_rap->Draw("colz");
	c22->SaveAs("./plots/pdf/sp_mu_pT_mu_rap.pdf"); 
	
    l913->DrawClone("same");
    l913b->DrawClone("same");
    l913c->DrawClone("same");
    l914->DrawClone("same");
    l915->DrawClone("same");
    l916->DrawClone("same");
    l917->DrawClone("same");
    l918->DrawClone("same");
    l923b->DrawClone("same");
    l923c->DrawClone("same");
    l924->DrawClone("same");
    l925->DrawClone("same");
    l926->DrawClone("same");
    l927->DrawClone("same");
    l928->DrawClone("same");
    
	c22->SaveAs("./plots/pdf/sp_mu_pT_mu_rap_profile.pdf"); 


    l713->DrawClone("same");
    l713b->DrawClone("same");
    l713c->DrawClone("same");
    l714->DrawClone("same");
    l715->DrawClone("same");
    l716->DrawClone("same");
    l717->DrawClone("same");
    l718->DrawClone("same");
    l723b->DrawClone("same");
    l723c->DrawClone("same");
    l724->DrawClone("same");
    l725->DrawClone("same");
    l726->DrawClone("same");
    l727->DrawClone("same");
    l728->DrawClone("same");
    
	c22->SaveAs("./plots/pdf/sp_mu_pT_mu_rap_profile2.pdf"); 








	
	TCanvas *c88 = new TCanvas("c88","c88",1000,600);
	sp_QQ_pT_Aco->SetStats(0); // gets rid of anoying stat box
	sp_QQ_pT_Aco->SetTitle("dimuon p_{T} vs acoplanarity");
	sp_QQ_pT_Aco->GetXaxis()->SetTitle("A");
	sp_QQ_pT_Aco->GetYaxis()->SetTitle("p^{#mu#mu}_{T}");
	sp_QQ_pT_Aco->GetXaxis()->SetRangeUser(0,0.4);
	sp_QQ_pT_Aco->GetYaxis()->SetRangeUser(0,3);
	sp_QQ_pT_Aco->Draw("colz");
	c88->SaveAs("./plots/pdf/sp_QQ_pT_Aco.pdf"); 




	TCanvas *c27 = new TCanvas("c27","c27",1000,600);
	histo_aco->SetStats(0); // gets rid of anoying stat box
	histo_aco->SetLineWidth(4);
	histo_aco->GetXaxis()->SetRangeUser(0,0.4);
	histo_aco->SetTitle("acoplanarity distribution");
	histo_aco->GetXaxis()->SetTitle("acoplanarity");
	histo_aco->GetYaxis()->SetTitle("events");
	histo_aco->Draw("");
	c27->SaveAs("./plots/pdf/histo_aco.pdf"); 
	c27->SetLogy();
	c27->SaveAs("./plots/pdf/histo_aco_log.pdf"); 


	TCanvas *c28 = new TCanvas("c28","c28",1000,600);
	histo_mu_Phi->SetStats(0); // gets rid of anoying stat box
	histo_mu_Phi->Rebin(2);	
	histo_mu_Phi->SetLineWidth(4);
	histo_mu_Phi->SetTitle("#phi_{#mu} distribution");
	histo_mu_Phi->GetXaxis()->SetTitle("#phi_{#mu}");
	histo_mu_Phi->Draw("");
	c28->SaveAs("./plots/pdf/histo_mu_Phi.pdf"); 

	
	TCanvas *c29 = new TCanvas("c29","c29",1000,600);
	histo_QQ_Phi->SetStats(0); // gets rid of anoying stat box
	histo_QQ_Phi->SetLineWidth(4);
	histo_QQ_Phi->SetTitle("#phi_{#mu#mu} distribution");
	histo_QQ_Phi->GetXaxis()->SetTitle("#phi_{#mu#mu}");
	histo_QQ_Phi->Draw("");
	c29->SaveAs("./plots/pdf/histo_QQ_Phi.pdf"); 


	TCanvas *c89 = new TCanvas("c89","c89",1000,1000);

	sp_mupl_rap_mumi_rap->SetStats(0); // gets rid of anoying stat box
	//sp_mupl_rap_mumi_rap->SetTitle("normalised acoplanarity distribution");
	//sp_mupl_rap_mumi_rap->GetXaxis()->SetTitle("acoplanarity");
	//sp_mupl_rap_mumi_rap->GetYaxis()->SetTitle("dimuon pT");
	//sp_mupl_rap_mumi_rap->GetXaxis()->SetRangeUser(0,0.4);
	//sp_mupl_rap_mumi_rap->GetYaxis()->SetRangeUser(0,3);
	c89 -> SetRightMargin(0.125);
	sp_mupl_rap_mumi_rap->Draw("colz");
	c89->SaveAs("./plots/pdf/sp_mupl_rap_mumi_rap.pdf"); 



	TCanvas *c90 = new TCanvas("c90","c90",1000,1000);
	sp_mupl_pT_mumi_pT->SetStats(0); // gets rid of anoying stat box
	//sp_mupl_pT_mumi_pT->SetTitle("normalised acoplanarity distribution");
	//sp_mupl_pT_mumi_pT->GetXaxis()->SetTitle("acoplanarity");
	//sp_mupl_pT_mumi_pT->GetYaxis()->SetTitle("dimuon pT");
	//sp_mupl_pT_mumi_pT->GetXaxis()->SetRangeUser(0,0.4);
	//sp_mupl_pT_mumi_pT->GetYaxis()->SetRangeUser(0,3);
	c90 -> SetRightMargin(0.125);
	//sp_mupl_pT_mumi_pT->GetXaxis()->SetTitleOffset(2.0);
	sp_mupl_pT_mumi_pT->Draw("colz");
	c90->SaveAs("./plots/pdf/sp_mupl_pT_mumi_pT.pdf"); 



	
	cout << endl << "******* THE END *******" << endl << endl;


}



















