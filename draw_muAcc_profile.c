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
void draw_muAcc_profile(){

system("mkdir plots/Acc");

cout << endl << "******* opening files *******" << endl;

TFile* f1 = new TFile("plots/plots.root","read");
TFile* f2 = new TFile("plots/plots.root","read");





          
cout << endl << "******* making histos *******" << endl << endl;



  
  float point1eta = 1.0;
  float point1pT = 3.3;

  float point2eta = 1.4;
  float point2pT = 2.1;

  float point3eta = 1.6;
  float point3pT = point2pT;

  float point4eta = 2.1;
  float point4pT = 1.1;

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


//    Double_t mEta[nPts] = {-2.4, -1.7, -1.4, -1.39999, -1.0, 1.0, 1.39999, 1.4, 1.7, 2.4};
 //   Double_t mPt[nPts]   = { 1.1,   1.1,  1.4,          2.1,  3.3, 3.3,         2.1, 1.4, 1.1, 1.1};

  float point_shuai_1eta = 1.0;
  float point_shuai_1pT = 3.3;
  
  float point_shuai_2eta = 1.4;
  float point_shuai_2pT = 2.1;

  float point_shuai_3eta = 1.4;
  float point_shuai_3pT = 1.4;

  float point_shuai_4eta = 1.7;
  float point_shuai_4pT = 1.1;
  
  TLine *l813 = new TLine(-0.3, point_shuai_1pT, 0.3, point_shuai_1pT);
  TLine *l813b = new TLine(0.3, point_shuai_1pT, 0.3, point_shuai_1pT);
  TLine *l813c = new TLine(0.3, point_shuai_1pT, point_shuai_1eta, point_shuai_1pT);
  TLine *l814 = new  TLine(point_shuai_1eta, point_shuai_1pT, point_shuai_2eta, point_shuai_2pT);
  TLine *l815 = new  TLine(point_shuai_2eta, point_shuai_2pT, point_shuai_3eta, point_shuai_3pT);
  TLine *l816 = new  TLine(point_shuai_3eta, point_shuai_3pT, point_shuai_4eta, point_shuai_4pT);
  TLine *l817 = new  TLine(point_shuai_4eta, point_shuai_4pT, 2.4, point_shuai_4pT);
  TLine *l818 = new  TLine(2.4, point_shuai_4pT, 2.4, 8.0);
  TLine *l823b = new TLine(-0.3, point_shuai_1pT, -0.3, point_shuai_1pT);
  TLine *l823c = new TLine(-0.3, point_shuai_1pT, -1*point_shuai_1eta, point_shuai_1pT);
  TLine *l824 = new  TLine(-1*point_shuai_1eta, point_shuai_1pT, -1*point_shuai_2eta, point_shuai_2pT);
  TLine *l825 = new  TLine(-1*point_shuai_2eta, point_shuai_2pT, -1*point_shuai_3eta, point_shuai_3pT);
  TLine *l826 = new  TLine(-1*point_shuai_3eta, point_shuai_3pT, -1*point_shuai_4eta, point_shuai_4pT);
  TLine *l827 = new  TLine(-1*point_shuai_4eta, point_shuai_4pT, -2.4, point_shuai_4pT);
  TLine *l828 = new  TLine(-2.4, point_shuai_4pT, -2.4, 8.0);
  
  l813->SetLineColor(kBlack);
  l813->SetLineWidth(2);
  l813b->SetLineColor(kBlack);
  l813b->SetLineWidth(2);
  l813c->SetLineColor(kBlack);
  l813c->SetLineWidth(2);
  l814->SetLineColor(kBlack);
  l814->SetLineWidth(2);
  l815->SetLineColor(kBlack);
  l815->SetLineWidth(2);
  l816->SetLineColor(kBlack);
  l816->SetLineWidth(2);
  l817->SetLineColor(kBlack);
  l817->SetLineWidth(2);
  l818->SetLineColor(kBlack);
  l818->SetLineWidth(2);
  l823b->SetLineColor(kBlack);
  l823b->SetLineWidth(2);
  l823c->SetLineColor(kBlack);
  l823c->SetLineWidth(2);
  l824->SetLineColor(kBlack);
  l824->SetLineWidth(2);
  l825->SetLineColor(kBlack);
  l825->SetLineWidth(2);
  l826->SetLineColor(kBlack);
  l826->SetLineWidth(2);
  l827->SetLineColor(kBlack);
  l827->SetLineWidth(2);
  l828->SetLineColor(kBlack);
  l828->SetLineWidth(2);

  
  l813->SetLineColor(kBlack);
  l813->SetLineStyle(2);
  l813b->SetLineColor(kBlack);
  l813b->SetLineStyle(2);
  l813c->SetLineColor(kBlack);
  l813c->SetLineStyle(2);
  l814->SetLineColor(kBlack);
  l814->SetLineStyle(2);
  l815->SetLineColor(kBlack);
  l815->SetLineStyle(2);
  l816->SetLineColor(kBlack);
  l816->SetLineStyle(2);
  l817->SetLineColor(kBlack);
  l817->SetLineStyle(2);
  l818->SetLineColor(kBlack);
  l818->SetLineStyle(2);
  l823b->SetLineColor(kBlack);
  l823b->SetLineStyle(2);
  l823c->SetLineColor(kBlack);
  l823c->SetLineStyle(2);
  l824->SetLineColor(kBlack);
  l824->SetLineStyle(2);
  l825->SetLineColor(kBlack);
  l825->SetLineStyle(2);
  l826->SetLineColor(kBlack);
  l826->SetLineStyle(2);
  l827->SetLineColor(kBlack);
  l827->SetLineStyle(2);
  l828->SetLineColor(kBlack);
  l828->SetLineStyle(2);



  float point_guillaume_1eta = 1.1;
  float point_guillaume_1pT = 3.3;
  
  float point_guillaume_2eta = 1.4;
  float point_guillaume_2pT = 2.1;

  float point_guillaume_3eta = 1.55;
  float point_guillaume_3pT = 2.1;

  float point_guillaume_4eta = 2.2;
  float point_guillaume_4pT = 1.2;
  
  TLine *l713 = new TLine(-0.3, 3.4, 0.3, 3.4);
  TLine *l713b = new TLine(0.3, 3.4, 0.3, 3.4);
  TLine *l713c = new TLine(0.3, point_guillaume_1pT, point_guillaume_1eta, point_guillaume_1pT);
  TLine *l714 = new  TLine(point_guillaume_1eta, point_guillaume_1pT, point_guillaume_2eta, point_guillaume_2pT);
  TLine *l715 = new  TLine(point_guillaume_2eta, point_guillaume_2pT, point_guillaume_3eta, point_guillaume_3pT);
  TLine *l716 = new  TLine(point_guillaume_3eta, point_guillaume_3pT, point_guillaume_4eta, point_guillaume_4pT);
  TLine *l717 = new  TLine(point_guillaume_4eta, point_guillaume_4pT, 2.4, point_guillaume_4pT);
  TLine *l718 = new  TLine(2.4, point_guillaume_4pT, 2.4, 8.0);
  TLine *l723b = new TLine(-0.3, point_guillaume_1pT, -0.3, point_guillaume_1pT);
  TLine *l723c = new TLine(-0.3, point_guillaume_1pT, -1*point_guillaume_1eta, point_guillaume_1pT);
  TLine *l724 = new  TLine(-1*point_guillaume_1eta, point_guillaume_1pT, -1*point_guillaume_2eta, point_guillaume_2pT);
  TLine *l725 = new  TLine(-1*point_guillaume_2eta, point_guillaume_2pT, -1*point_guillaume_3eta, point_guillaume_3pT);
  TLine *l726 = new  TLine(-1*point_guillaume_3eta, point_guillaume_3pT, -1*point_guillaume_4eta, point_guillaume_4pT);
  TLine *l727 = new  TLine(-1*point_guillaume_4eta, point_guillaume_4pT, -2.4, point_guillaume_4pT);
  TLine *l728 = new  TLine(-2.4, point_guillaume_4pT, -2.4, 8.0);
  
  l713->SetLineColor(kGreen);
  l713->SetLineWidth(2);
  l713b->SetLineColor(kGreen);
  l713b->SetLineWidth(2);
  l713c->SetLineColor(kGreen);
  l713c->SetLineWidth(2);
  l714->SetLineColor(kGreen);
  l714->SetLineWidth(2);
  l715->SetLineColor(kGreen);
  l715->SetLineWidth(2);
  l716->SetLineColor(kGreen);
  l716->SetLineWidth(2);
  l717->SetLineColor(kGreen);
  l717->SetLineWidth(2);
  l718->SetLineColor(kGreen);
  l718->SetLineWidth(2);
  l723b->SetLineColor(kGreen);
  l723b->SetLineWidth(2);
  l723c->SetLineColor(kGreen);
  l723c->SetLineWidth(2);
  l724->SetLineColor(kGreen);
  l724->SetLineWidth(2);
  l725->SetLineColor(kGreen);
  l725->SetLineWidth(2);
  l726->SetLineColor(kGreen);
  l726->SetLineWidth(2);
  l727->SetLineColor(kGreen);
  l727->SetLineWidth(2);
  l728->SetLineColor(kGreen);
  l728->SetLineWidth(2);

  
  l713->SetLineColor(kGreen);
  l713->SetLineStyle(3);
  l713b->SetLineColor(kGreen);
  l713b->SetLineStyle(3);
  l713c->SetLineColor(kGreen);
  l713c->SetLineStyle(3);
  l714->SetLineColor(kGreen);
  l714->SetLineStyle(3);
  l715->SetLineColor(kGreen);
  l715->SetLineStyle(3);
  l716->SetLineColor(kGreen);
  l716->SetLineStyle(3);
  l717->SetLineColor(kGreen);
  l717->SetLineStyle(3);
  l718->SetLineColor(kGreen);
  l718->SetLineStyle(3);
  l723b->SetLineColor(kGreen);
  l723b->SetLineStyle(3);
  l723c->SetLineColor(kGreen);
  l723c->SetLineStyle(3);
  l724->SetLineColor(kGreen);
  l724->SetLineStyle(3);
  l725->SetLineColor(kGreen);
  l725->SetLineStyle(3);
  l726->SetLineColor(kGreen);
  l726->SetLineStyle(3);
  l727->SetLineColor(kGreen);
  l727->SetLineStyle(3);
  l728->SetLineColor(kGreen);
  l728->SetLineStyle(3);





  TH2F *sp_mu_pT_mu_rap_Acc_543 = (TH2F *)f1->Get("sp_mu_pT_mu_rap_Acc");
  TH2F *sp_mu_pT_mu_rap_Acc_123 = (TH2F *)f2->Get("sp_mu_pT_mu_rap_Acc");








system("rm -r plots/Acc_2");
system("mkdir plots/Acc_2");




//*************** SP - MUON pT vs rap *******************//


  TCanvas *c543 = new TCanvas("c543","c543",1000,600);
  c543->SetLogz();
  
  sp_mu_pT_mu_rap_Acc_543->GetXaxis()->SetRangeUser(-4,4);
  sp_mu_pT_mu_rap_Acc_543->GetYaxis()->SetRangeUser(0,8);
  sp_mu_pT_mu_rap_Acc_543->GetXaxis()->SetTitleOffset(1.2);
  sp_mu_pT_mu_rap_Acc_543->GetYaxis()->SetTitleOffset(1.22);
 
  //sp_mu_pT_mu_rap_Acc_543->GetXaxis()->SetTitle("mu rap");

  //sp_mu_pT_mu_rap_Acc_543->SetMarkerStyle(8);
  //sp_mu_pT_mu_rap_Acc_543->SetMarkerColor(kRed);
  sp_mu_pT_mu_rap_Acc_543->SetLineColor(kRed);
  sp_mu_pT_mu_rap_Acc_543->SetLineWidth(4);

  sp_mu_pT_mu_rap_Acc_543->Draw("colz");

  sp_mu_pT_mu_rap_Acc_543->SetStats(0); // gets rid of anoying stat box

  TLegend *l543 = new TLegend(0.1,0.80,0.22,0.90,NULL,"brNDC");
  l543->AddEntry(sp_mu_pT_mu_rap_Acc_543,"Reco / Gen", "");
  l543->SetFillColor(10);
  l543->Draw();


  c543->Update();
  c543->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc_0proc.pdf");




  for (int i=1;i<sp_mu_pT_mu_rap_Acc_543->GetNbinsX();i++){
    for (int j=1;j<sp_mu_pT_mu_rap_Acc_543->GetNbinsY();j++){
      if(sp_mu_pT_mu_rap_Acc_543->GetBinContent(i,j) < 0.01) sp_mu_pT_mu_rap_Acc_543->SetBinContent(i,j,0);
    }
  }


  c543->Update();
  c543->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc_1proc.pdf");




  for (int i=1;i<sp_mu_pT_mu_rap_Acc_543->GetNbinsX();i++){
    for (int j=1;j<sp_mu_pT_mu_rap_Acc_543->GetNbinsY();j++){
      if(sp_mu_pT_mu_rap_Acc_543->GetBinContent(i,j) < 0.02) sp_mu_pT_mu_rap_Acc_543->SetBinContent(i,j,0);
    }
  }


  c543->Update();
  c543->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc_2proc.pdf");





 for (int i=1;i<sp_mu_pT_mu_rap_Acc_543->GetNbinsX();i++){
    for (int j=1;j<sp_mu_pT_mu_rap_Acc_543->GetNbinsY();j++){
      if(sp_mu_pT_mu_rap_Acc_543->GetBinContent(i,j) < 0.05) sp_mu_pT_mu_rap_Acc_543->SetBinContent(i,j,0);
    }
  }


  c543->Update();
  c543->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc_5proc.pdf");



  for (int i=1;i<sp_mu_pT_mu_rap_Acc_543->GetNbinsX();i++){
    for (int j=1;j<sp_mu_pT_mu_rap_Acc_543->GetNbinsY();j++){
      if(sp_mu_pT_mu_rap_Acc_543->GetBinContent(i,j) < 0.1) sp_mu_pT_mu_rap_Acc_543->SetBinContent(i,j,0);
    }
  }





  c543->Update();
  c543->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc_10proc.pdf");










//*************** SP - MUON pT vs rap *******************//

  TCanvas *c123 = new TCanvas("c123","c123",1000,600);
  c123->SetLogz();
  
  sp_mu_pT_mu_rap_Acc_123->GetXaxis()->SetRangeUser(-4,4);
  sp_mu_pT_mu_rap_Acc_123->GetYaxis()->SetRangeUser(0,8);
  sp_mu_pT_mu_rap_Acc_123->GetXaxis()->SetTitleOffset(1.2);
  sp_mu_pT_mu_rap_Acc_123->GetYaxis()->SetTitleOffset(1.22);
 
  //sp_mu_pT_mu_rap_Acc_123->GetXaxis()->SetTitle("mu rap");

  //sp_mu_pT_mu_rap_Acc_123->SetMarkerStyle(8);
  //sp_mu_pT_mu_rap_Acc_123->SetMarkerColor(kRed);
  sp_mu_pT_mu_rap_Acc_123->SetLineColor(kRed);
  sp_mu_pT_mu_rap_Acc_123->SetLineWidth(4);

  sp_mu_pT_mu_rap_Acc_123->Draw("colz");

  sp_mu_pT_mu_rap_Acc_123->SetStats(0); // gets rid of anoying stat box

  TLegend *l123 = new TLegend(0.1,0.70,0.22,0.90,NULL,"brNDC");
  l123->AddEntry(sp_mu_pT_mu_rap_Acc_123,"Reco / Gen", "");
  l123->AddEntry(l913,"Marek", "l");
  l123->AddEntry(l813,"Shuai", "l");
  l123->AddEntry(l713,"AN2018_316", "l");
  l123->SetFillColor(10);
  l123->Draw();



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



    l813->DrawClone("same");
    l813b->DrawClone("same");
    l813c->DrawClone("same");
    l814->DrawClone("same");
    l815->DrawClone("same");
    l816->DrawClone("same");
    l817->DrawClone("same");
    l818->DrawClone("same");
    l823b->DrawClone("same");
    l823c->DrawClone("same");
    l824->DrawClone("same");
    l825->DrawClone("same");
    l826->DrawClone("same");
    l827->DrawClone("same");
    l828->DrawClone("same");



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






  c123->Update();
  c123->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc_profile_0proc.pdf");




  for (int i=1;i<sp_mu_pT_mu_rap_Acc_123->GetNbinsX();i++){
    for (int j=1;j<sp_mu_pT_mu_rap_Acc_123->GetNbinsY();j++){
      if(sp_mu_pT_mu_rap_Acc_123->GetBinContent(i,j) < 0.01) sp_mu_pT_mu_rap_Acc_123->SetBinContent(i,j,0);
    }
  }


  c123->Update();
  c123->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc_profile_1proc.pdf");




  for (int i=1;i<sp_mu_pT_mu_rap_Acc_123->GetNbinsX();i++){
    for (int j=1;j<sp_mu_pT_mu_rap_Acc_123->GetNbinsY();j++){
      if(sp_mu_pT_mu_rap_Acc_123->GetBinContent(i,j) < 0.02) sp_mu_pT_mu_rap_Acc_123->SetBinContent(i,j,0);
    }
  }


  c123->Update();
  c123->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc_profile_2proc.pdf");





 for (int i=1;i<sp_mu_pT_mu_rap_Acc_123->GetNbinsX();i++){
    for (int j=1;j<sp_mu_pT_mu_rap_Acc_123->GetNbinsY();j++){
      if(sp_mu_pT_mu_rap_Acc_123->GetBinContent(i,j) < 0.05) sp_mu_pT_mu_rap_Acc_123->SetBinContent(i,j,0);
    }
  }


    
  c123->Update();
  c123->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc_profile_5proc.pdf");



  for (int i=1;i<sp_mu_pT_mu_rap_Acc_123->GetNbinsX();i++){
    for (int j=1;j<sp_mu_pT_mu_rap_Acc_123->GetNbinsY();j++){
      if(sp_mu_pT_mu_rap_Acc_123->GetBinContent(i,j) < 0.1) sp_mu_pT_mu_rap_Acc_123->SetBinContent(i,j,0);
    }
  }





  c123->Update();
  c123->SaveAs("plots/Acc_2/sp_mu_pT_mu_rap_Acc_profile_10proc.pdf");



cout << endl << "******* THE END *******" << endl << endl;


}

/*
  TLine *l9 = new TLine(-1.2, 3.25, 1.2, 3.25);
  TLine *l10 = new TLine(1.2, 3.25, 2.1, 1.4);
  TLine *l11 = new TLine(2.1, 1.4, 2.4, 1.4);
  TLine *l12 = new TLine(2.4, 1.4, 2.4, 6.5);
  TLine *l_10 = new TLine(-1.2, 3.25, -2.1, 1.4);
  TLine *l_11 = new TLine(-2.1, 1.4, -2.4, 1.4);
  TLine *l_12 = new TLine(-2.4, 1.4, -2.4, 6.5);


  l9->SetLineColor(kRed+1);
  l9->SetLineWidth(2);
  l10->SetLineColor(kRed+1);
  l10->SetLineWidth(2);
  l11->SetLineColor(kRed+1);
  l11->SetLineWidth(2);
  l12->SetLineColor(kRed+1);
  l12->SetLineWidth(2);
  l_10->SetLineColor(kRed+1);
  l_10->SetLineWidth(2);
  l_11->SetLineColor(kRed+1);
  l_11->SetLineWidth(2);
  l_12->SetLineColor(kRed+1);
  l_12->SetLineWidth(2);



  TLine *l13 = new TLine(-0.3, point1pT5, 0.3, point1pT5);
  
  TLine *l13b = new TLine(0.3, point1pT5, 0.3, 3.25);
  TLine *l13c = new TLine(0.3, 3.25, 1.0, 3.25);
  TLine *l14 = new TLine(1.0, 3.25, 1.4, 2.35);
  TLine *l15 = new TLine(1.4, 2.35, 1.8, 2.35);
  TLine *l16 = new TLine(1.8, 2.35, 2.0, 1.4);
  TLine *l17 = new TLine(2.0, 1.4, 2.4, 1.4);
  TLine *l18 = new TLine(2.4, 1.4, 2.4, 6.5);
  
  TLine *l23b = new TLine(-0.3, point1pT5, -0.3, 3.25);
  TLine *l23c = new TLine(-0.3, 3.25, -1.0, 3.25);
  TLine *l24 = new TLine(-1.0, 3.25, -1.4, 2.35);
  TLine *l25 = new TLine(-1.4, 2.35, -1.8, 2.35);
  TLine *l26 = new TLine(-1.8, 2.35, -2.0, 1.4);
  TLine *l27 = new TLine(-2.0, 1.4, -2.4, 1.4);
  TLine *l28 = new TLine(-2.4, 1.4, -2.4, 6.5);
  
  
  l13->SetLineColor(kRed);
  l13->SetLineWidth(2);
  l13b->SetLineColor(kRed);
  l13b->SetLineWidth(2);
  l13c->SetLineColor(kRed);
  l13c->SetLineWidth(2);
  l14->SetLineColor(kRed);
  l14->SetLineWidth(2);
  l15->SetLineColor(kRed);
  l15->SetLineWidth(2);
  l16->SetLineColor(kRed);
  l16->SetLineWidth(2);
  l17->SetLineColor(kRed);
  l17->SetLineWidth(2);
  l18->SetLineColor(kRed);
  l18->SetLineWidth(2);
  l23b->SetLineColor(kRed);
  l23b->SetLineWidth(2);
  l23c->SetLineColor(kRed);
  l23c->SetLineWidth(2);
  l24->SetLineColor(kRed);
  l24->SetLineWidth(2);
  l25->SetLineColor(kRed);
  l25->SetLineWidth(2);
  l26->SetLineColor(kRed);
  l26->SetLineWidth(2);
  l27->SetLineColor(kRed);
  l27->SetLineWidth(2);
  l28->SetLineColor(kRed);
  l28->SetLineWidth(2);


    l9->DrawClone("same");
    l10->DrawClone("same");
    l11->DrawClone("same");
    l12->DrawClone("same");
    l_10->DrawClone("same");
    l_11->DrawClone("same");
    l_12->DrawClone("same");


    l13->DrawClone("same");
    l13b->DrawClone("same");
    l13c->DrawClone("same");
    l14->DrawClone("same");
    l15->DrawClone("same");
    l16->DrawClone("same");
    l17->DrawClone("same");
    l18->DrawClone("same");
    l23b->DrawClone("same");
    l23c->DrawClone("same");
    l24->DrawClone("same");
    l25->DrawClone("same");
    l26->DrawClone("same");
    l27->DrawClone("same");
    l28->DrawClone("same");

*/












