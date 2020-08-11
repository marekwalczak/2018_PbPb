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


void pT_spectrum(){

  system("mkdir pT_spectrum");
  system("cp pT_spectrum.c pT_spectrum/");

cout << "******* opening files *******" << endl;



TFile* f1 = new TFile("plots_data_30mupt60_80m90/plots.root","read"); // bkg 1
TFile* f2 = new TFile("plots_data_30mupt60_107m120/plots.root","read"); // bkg 2
TFile* f3 = new TFile("plots_data_30mupt60_98m106/plots.root","read"); // signal

// set the number of the signal events from the inv mass fit
float N_ups1s = 302;
  
  
cout << endl << "******* getting histos *******" << endl << endl;

  
  TH1F *histo_QQ_pT_bkg1 = (TH1F *)f1->Get("histo_QQ_pT"); // c11
  histo_QQ_pT_bkg1->Sumw2();
  histo_QQ_pT_bkg1->Rebin(2);
  float N_bkg1 = histo_QQ_pT_bkg1->GetEntries();
  
  TH1F *histo_QQ_pT_bkg2 = (TH1F *)f2->Get("histo_QQ_pT"); // c11
  histo_QQ_pT_bkg2->Sumw2();
  histo_QQ_pT_bkg2->Rebin(2);
  float N_bkg2 = histo_QQ_pT_bkg2->GetEntries();

  TH1F *histo_QQ_pT_sig = (TH1F *)f3->Get("histo_QQ_pT"); // c11
  histo_QQ_pT_sig->Sumw2();
  histo_QQ_pT_sig->Rebin(2);
  float N_sig = histo_QQ_pT_sig->GetEntries();
 
  cout << "N_bkg1 = " << N_bkg1 << endl;
  cout << "N_bkg2 = " << N_bkg2 << endl;
  cout << "N_sig  = " << N_sig << endl;
  

  cout << endl << "bkg contr from 1st bkg: " << N_bkg1/(N_bkg1+N_bkg2)*(N_sig-N_ups1s) << endl;
  cout         << "bkg contr from 2nd bkg: " << N_bkg2/(N_bkg1+N_bkg2)*(N_sig-N_ups1s) << endl;
  cout << "N_sig - N_ups1s: " << N_sig - N_ups1s << endl;
  cout << "sum of bkgs: " << N_bkg1/(N_bkg1+N_bkg2)*(N_sig-N_ups1s) + N_bkg2/(N_bkg1+N_bkg2)*(N_sig-N_ups1s) << endl;

  cout << endl;
	

	
	TCanvas *c11 = new TCanvas("c11","c11",1000,600);
    TFile* outFile = new TFile("pT_spectrum/plots.root","RECREATE");

	//c11->SetLogy();


    histo_QQ_pT_bkg1->GetXaxis()->SetRangeUser(0,4);
    histo_QQ_pT_bkg2->GetXaxis()->SetRangeUser(0,4);
    histo_QQ_pT_sig->GetXaxis()->SetRangeUser(0,4);
  
	histo_QQ_pT_sig->SetLineWidth(2);
	histo_QQ_pT_bkg1->SetLineWidth(2);
	histo_QQ_pT_bkg2->SetLineWidth(2);
	
	histo_QQ_pT_bkg1->Draw("");
	c11->SaveAs("./pT_spectrum/histo_QQ_pT_bkg1.pdf"); 
    histo_QQ_pT_bkg1->Write("histo_QQ_pT_bkg1");
    
	histo_QQ_pT_bkg2->Draw("");
	c11->SaveAs("./pT_spectrum/histo_QQ_pT_bkg2.pdf"); 
	histo_QQ_pT_bkg2->Write("histo_QQ_pT_bkg2");


    histo_QQ_pT_bkg1->Scale(1/(N_bkg1+N_bkg2)*(N_sig-N_ups1s));
    histo_QQ_pT_bkg2->Scale(1/(N_bkg1+N_bkg2)*(N_sig-N_ups1s));


	histo_QQ_pT_bkg1->Draw("");
	c11->SaveAs("./pT_spectrum/histo_QQ_pT_bkg1_scaled.pdf"); 
	histo_QQ_pT_bkg1->Write("histo_QQ_pT_bkg1_scaled");

	histo_QQ_pT_bkg2->Draw("");
	c11->SaveAs("./pT_spectrum/histo_QQ_pT_bkg2_scaled.pdf"); 
	histo_QQ_pT_bkg2->Write("histo_QQ_pT_bkg2_scaled");
  
  
  
	histo_QQ_pT_sig->Draw("");
	c11->SaveAs("./pT_spectrum/histo_QQ_pT_sig.pdf"); 
	histo_QQ_pT_sig->Write("histo_QQ_pT_sig");


    histo_QQ_pT_sig->Add(histo_QQ_pT_bkg1,-1);
    
    
	histo_QQ_pT_sig->Draw("");
	c11->SaveAs("./pT_spectrum/histo_QQ_pT_sig_min_bkg1.pdf"); 
	histo_QQ_pT_sig->Write("histo_QQ_pT_sig_min_bkg1");


    histo_QQ_pT_sig->Add(histo_QQ_pT_bkg2,-1);
    
    
	histo_QQ_pT_sig->Draw("");
	c11->SaveAs("./pT_spectrum/histo_QQ_pT_sig_min_bkg1and2.pdf"); 
	histo_QQ_pT_sig->Write("histo_QQ_pT_sig_min_bkg1and2");
	
	c11->SetLogy();
	c11->SaveAs("./pT_spectrum/histo_QQ_pT_sig_min_bkg1and2_log.pdf"); 
	

	
    outFile->Close();
    
TFile* ff = new TFile("pT_spectrum/plots.root","read");



//*************** QQ pT BKG and sig *******************//
  TH1F *histo_QQ_pT = (TH1F *)ff->Get("histo_QQ_pT_bkg1");
  TH1F *histo_QQ_pT_2 = (TH1F *)ff->Get("histo_QQ_pT_bkg2");
  TH1F *histo_QQ_pT_sig1 = (TH1F *)ff->Get("histo_QQ_pT_sig");

  histo_QQ_pT->Scale(1./(histo_QQ_pT->Integral()));
  histo_QQ_pT_2->Scale(1./(histo_QQ_pT_2->Integral()));
  histo_QQ_pT_sig1->Scale(1./(histo_QQ_pT_sig1->Integral()));

  //histo_QQ_pT_sig1->Rebin(2);
  //histo_QQ_pT->Rebin(2);
  //histo_QQ_pT_2->Rebin(2);

  TCanvas *c5 = new TCanvas("c5","c5",1000,600);

  histo_QQ_pT->GetXaxis()->SetRangeUser(0,2);
 // histo_QQ_pT->GetYaxis()->SetRangeUser(0,0.2);
  histo_QQ_pT->GetXaxis()->SetTitleOffset(1.2);
  histo_QQ_pT->GetYaxis()->SetTitleOffset(1.22);
 
  histo_QQ_pT->GetXaxis()->SetTitle("QQ p_{T} [GeV]");

  histo_QQ_pT->SetMarkerStyle(8);
  histo_QQ_pT->SetMarkerColor(kRed);
  histo_QQ_pT->SetLineColor(kRed);
  histo_QQ_pT->SetLineWidth(2);
  histo_QQ_pT_2->SetMarkerStyle(8);
  histo_QQ_pT_2->SetMarkerColor(kGreen);
  histo_QQ_pT_2->SetLineColor(kGreen);
  histo_QQ_pT_2->SetLineWidth(2);
  histo_QQ_pT_sig1->SetMarkerStyle(8);
  histo_QQ_pT_sig1->SetMarkerColor(kBlue);
  histo_QQ_pT_sig1->SetLineColor(kBlue);
  histo_QQ_pT_sig1->SetLineWidth(2);


  histo_QQ_pT->Draw("");
  histo_QQ_pT_2->Draw("same");
  histo_QQ_pT_sig1->Draw("same");

  histo_QQ_pT->SetStats(0); // gets rid of anoying stat box

  TLegend *l5 = new TLegend(0.50,0.70,0.70,0.80,NULL,"brNDC");
  l5->AddEntry(histo_QQ_pT,"bkg 1","l");
  l5->AddEntry(histo_QQ_pT_2,"bkg 2","l");
  l5->AddEntry(histo_QQ_pT_sig1,"signal","l");
  l5->SetFillColor(10);
  l5->Draw();

  c5->Update();
  c5->SaveAs("./pT_spectrum/bkg1_vs_bkg2_norm.pdf");
    
  c5->SetLogy();
  c5->Update();
  c5->SaveAs("./pT_spectrum/bkg1_vs_bkg2_log_norm.pdf");
    
    
    
    
//*************** QQ pT BKG and sig unnormalized *******************//
  TH1F *histo3_QQ_pT = (TH1F *)ff->Get("histo_QQ_pT_bkg1");
  TH1F *histo3_QQ_pT_2 = (TH1F *)ff->Get("histo_QQ_pT_bkg2");
  TH1F *histo3_QQ_pT_sig1 = (TH1F *)ff->Get("histo_QQ_pT_sig");

  //histo3_QQ_pT->Scale(1./(histo3_QQ_pT->Integral()));
  //histo3_QQ_pT_2->Scale(1./(histo3_QQ_pT_2->Integral()));
  //histo3_QQ_pT_sig1->Scale(1./(histo3_QQ_pT_sig1->Integral()));

  //histo3_QQ_pT_sig1->Rebin(2);
  //histo3_QQ_pT->Rebin(2);
  //histo3_QQ_pT_2->Rebin(2);

  TCanvas *c7 = new TCanvas("c7","c7",1000,600);

  histo3_QQ_pT->GetXaxis()->SetRangeUser(0,2);
 // histo3_QQ_pT->GetYaxis()->SetRangeUser(0,0.2);
  histo3_QQ_pT->GetXaxis()->SetTitleOffset(1.2);
  histo3_QQ_pT->GetYaxis()->SetTitleOffset(1.22);
 
  histo3_QQ_pT->GetXaxis()->SetTitle("QQ p_{T} [GeV]");

  histo3_QQ_pT->SetMarkerStyle(8);
  histo3_QQ_pT->SetMarkerColor(kRed);
  histo3_QQ_pT->SetLineColor(kRed);
  histo3_QQ_pT->SetLineWidth(2);
  histo3_QQ_pT_2->SetMarkerStyle(8);
  histo3_QQ_pT_2->SetMarkerColor(kGreen);
  histo3_QQ_pT_2->SetLineColor(kGreen);
  histo3_QQ_pT_2->SetLineWidth(2);
  histo3_QQ_pT_sig1->SetMarkerStyle(8);
  histo3_QQ_pT_sig1->SetMarkerColor(kBlue);
  histo3_QQ_pT_sig1->SetLineColor(kBlue);
  histo3_QQ_pT_sig1->SetLineWidth(2);


  histo3_QQ_pT->Draw("");
  histo3_QQ_pT_2->Draw("same");
  histo3_QQ_pT_sig1->Draw("same");

  histo3_QQ_pT->SetStats(0); // gets rid of anoying stat box

  TLegend *l7 = new TLegend(0.50,0.70,0.70,0.80,NULL,"brNDC");
  l7->AddEntry(histo3_QQ_pT,"bkg 1","l");
  l7->AddEntry(histo3_QQ_pT_2,"bkg 2","l");
  l7->AddEntry(histo3_QQ_pT_sig1,"signal","l");
  l7->SetFillColor(10);
  l7->Draw();

  c7->Update();
  c7->SaveAs("./pT_spectrum/bkg1_vs_bkg2.pdf");
    
  c7->SetLogy();
  c7->Update();
  c7->SaveAs("./pT_spectrum/bkg1_vs_bkg2_log.pdf");

  

//*************** QQ pT SIG steps *******************//
  TH1F *histo2_QQ_pT = (TH1F *)ff->Get("histo_QQ_pT_sig_min_bkg1");
  TH1F *histo2_QQ_pT_2 = (TH1F *)ff->Get("histo_QQ_pT_sig_min_bkg1and2");
  TH1F *histo2_QQ_pT_sig1 = (TH1F *)ff->Get("histo_QQ_pT_sig");

  histo2_QQ_pT->Scale(1./(histo2_QQ_pT->Integral()));
  histo2_QQ_pT_2->Scale(1./(histo2_QQ_pT_2->Integral()));
  histo2_QQ_pT_sig1->Scale(1./(histo2_QQ_pT_sig1->Integral()));

  //histo2_QQ_pT_sig1->Rebin(2);
  //histo2_QQ_pT->Rebin(2);
  //histo2_QQ_pT_2->Rebin(2);

  TCanvas *c6 = new TCanvas("c6","c6",1000,600);

  histo2_QQ_pT->GetXaxis()->SetRangeUser(0,2);
 // histo2_QQ_pT->GetYaxis()->SetRangeUser(0,0.2);
  histo2_QQ_pT->GetXaxis()->SetTitleOffset(1.2);
  histo2_QQ_pT->GetYaxis()->SetTitleOffset(1.22);
 
  histo2_QQ_pT->GetXaxis()->SetTitle("QQ p_{T} [GeV]");

  histo2_QQ_pT->SetMarkerStyle(8);
  histo2_QQ_pT->SetMarkerColor(kRed);
  histo2_QQ_pT->SetLineColor(kRed);
  histo2_QQ_pT->SetLineWidth(2);
  histo2_QQ_pT_2->SetMarkerStyle(8);
  histo2_QQ_pT_2->SetMarkerColor(kGreen);
  histo2_QQ_pT_2->SetLineColor(kGreen);
  histo2_QQ_pT_2->SetLineWidth(2);
  histo2_QQ_pT_sig1->SetMarkerStyle(8);
  histo2_QQ_pT_sig1->SetMarkerColor(kBlue);
  histo2_QQ_pT_sig1->SetLineColor(kBlue);
  histo2_QQ_pT_sig1->SetLineWidth(2);

  histo2_QQ_pT_sig1->Draw("");
  histo2_QQ_pT->Draw("same");
  histo2_QQ_pT_2->Draw("same");

  histo2_QQ_pT->SetStats(0); // gets rid of anoying stat box

  TLegend *l6 = new TLegend(0.50,0.70,0.70,0.80,NULL,"brNDC");
  l6->AddEntry(histo2_QQ_pT_sig1,"signal","l");
  l6->AddEntry(histo2_QQ_pT,"sig - bkg 1","l");
  l6->AddEntry(histo2_QQ_pT_2,"sig - bkg 1 & 2","l");
  l6->SetFillColor(10);
  l6->Draw();

  c6->Update();
  c6->SaveAs("./pT_spectrum/sig_steps_norm.pdf");
    
  c6->SetLogy();
  c6->Update();
  c6->SaveAs("./pT_spectrum/sig_steps_log_norm.pdf");
    

  



//*************** QQ pT SIG steps norm *******************//
  TH1F *histo4_QQ_pT = (TH1F *)ff->Get("histo_QQ_pT_sig_min_bkg1");
  TH1F *histo4_QQ_pT_2 = (TH1F *)ff->Get("histo_QQ_pT_sig_min_bkg1and2");
  TH1F *histo4_QQ_pT_sig1 = (TH1F *)ff->Get("histo_QQ_pT_sig");

  //histo4_QQ_pT->Scale(1./(histo4_QQ_pT->Integral()));
  //histo4_QQ_pT_2->Scale(1./(histo4_QQ_pT_2->Integral()));
  //histo4_QQ_pT_sig1->Scale(1./(histo4_QQ_pT_sig1->Integral()));

  //histo4_QQ_pT_sig1->Rebin(2);
  //histo4_QQ_pT->Rebin(2);
  //histo4_QQ_pT_2->Rebin(2);

  TCanvas *c8 = new TCanvas("c8","c8",1000,600);

  histo4_QQ_pT->GetXaxis()->SetRangeUser(0,2);
 // histo4_QQ_pT->GetYaxis()->SetRangeUser(0,0.2);
  histo4_QQ_pT->GetXaxis()->SetTitleOffset(1.2);
  histo4_QQ_pT->GetYaxis()->SetTitleOffset(1.22);
 
  histo4_QQ_pT->GetXaxis()->SetTitle("QQ p_{T} [GeV]");

  histo4_QQ_pT->SetMarkerStyle(8);
  histo4_QQ_pT->SetMarkerColor(kRed);
  histo4_QQ_pT->SetLineColor(kRed);
  histo4_QQ_pT->SetLineWidth(2);
  histo4_QQ_pT_2->SetMarkerStyle(8);
  histo4_QQ_pT_2->SetMarkerColor(kGreen);
  histo4_QQ_pT_2->SetLineColor(kGreen);
  histo4_QQ_pT_2->SetLineWidth(2);
  histo4_QQ_pT_sig1->SetMarkerStyle(8);
  histo4_QQ_pT_sig1->SetMarkerColor(kBlue);
  histo4_QQ_pT_sig1->SetLineColor(kBlue);
  histo4_QQ_pT_sig1->SetLineWidth(2);

  histo4_QQ_pT_sig1->Draw("");
  histo4_QQ_pT->Draw("same");
  histo4_QQ_pT_2->Draw("same");

  histo4_QQ_pT->SetStats(0); // gets rid of anoying stat box

  TLegend *l8 = new TLegend(0.50,0.70,0.70,0.80,NULL,"brNDC");
  l8->AddEntry(histo4_QQ_pT_sig1,"signal","l");
  l8->AddEntry(histo4_QQ_pT,"sig - bkg 1","l");
  l8->AddEntry(histo4_QQ_pT_2,"sig - bkg 1 & 2","l");
  l8->SetFillColor(10);
  l8->Draw();

  c8->Update();
  c8->SaveAs("./pT_spectrum/sig_steps.pdf");
    
  c8->SetLogy();
  c8->Update();
  c8->SaveAs("./pT_spectrum/sig_steps_log.pdf");
    




}







