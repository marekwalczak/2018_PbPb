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

  float TnP_point1 = 1.2;
  float TnP_point2 = 1.8; // 1.8
  float TnP_point3 = 2.1;
  
  TLine *l_TnP_0 = new TLine(0, 1.0, 0, 8);
  TLine *l_TnP_1 =  new TLine(TnP_point1, 1.0, TnP_point1, 8);
  TLine *l_TnP_m1 = new TLine(-1*TnP_point1, 1.0, -1*TnP_point1, 8);
  TLine *l_TnP_2 =  new TLine(TnP_point2, 1.0, TnP_point2, 8);
  TLine *l_TnP_m2 = new TLine(-1*TnP_point2, 1.0, -1*TnP_point2, 8);
  TLine *l_TnP_3 =  new TLine(TnP_point3, 1.0, TnP_point3, 8);
  TLine *l_TnP_m3 = new TLine(-1*TnP_point3, 1.0, -1*TnP_point3, 8);
  TLine *l_TnP_4 =  new TLine(2.4, 1.0, 2.4, 8);
  TLine *l_TnP_m4 = new TLine(-1*2.4, 1.0, -1*2.4, 8);
 
   float start = 1.0;
   float increment = 1.0;

   TLine *b_TnP_0 = new TLine(-2.4, start, 2.4, start);
   start = start + increment;
   TLine *b_TnP_1 = new TLine(-2.4, start, 2.4, start);
   start = start + increment;
   TLine *b_TnP_2 = new TLine(-2.4, start, 2.4, start);
   start = start + increment;
   TLine *b_TnP_3 = new TLine(-2.4, start, 2.4, start);
   start = start + increment;
   TLine *b_TnP_4 = new TLine(-2.4, start, 2.4, start);
   start = start + increment;
   TLine *b_TnP_5 = new TLine(-2.4, start, 2.4, start);
   start = start + increment;
   TLine *b_TnP_6 = new TLine(-2.4, start, 2.4, start);
   start = start + increment;
   TLine *b_TnP_7 = new TLine(-2.4, start, 2.4, start);
   start = start + increment;





// extended SOFT ID for ANDRE

/*  
  const Int_t nPts = 10;
Double_t mEta[nPts] = {-2.4, -1.7,  -1.3, -1.3, -1.0, 1.0, 1.3,  1.3, 1.7, 2.4};
Double_t mPt[nPts]   = { 1.0,   1.0,  1.53,  2.1,  3.3, 3.3, 2.1, 1.53, 1.0, 1.0};
*/


  float point_Andre_ID_1eta = 1.0;
  float point_Andre_ID_1pT = 3.3;
  
  float point_Andre_ID_2eta = 1.3;
  float point_Andre_ID_2pT = 2.1;

  float point_Andre_ID_3eta = 1.3;
  float point_Andre_ID_3pT = 1.53;

  float point_Andre_ID_4eta = 1.7;
  float point_Andre_ID_4pT = 1.0;
  
  TLine *l813 = new TLine(-0.3, point_Andre_ID_1pT, 0.3, point_Andre_ID_1pT);
  TLine *l813b = new TLine(0.3, point_Andre_ID_1pT, 0.3, point_Andre_ID_1pT);
  TLine *l813c = new TLine(0.3, point_Andre_ID_1pT, point_Andre_ID_1eta, point_Andre_ID_1pT);
  TLine *l814 = new  TLine(point_Andre_ID_1eta, point_Andre_ID_1pT, point_Andre_ID_2eta, point_Andre_ID_2pT);
  TLine *l815 = new  TLine(point_Andre_ID_2eta, point_Andre_ID_2pT, point_Andre_ID_3eta, point_Andre_ID_3pT);
  TLine *l816 = new  TLine(point_Andre_ID_3eta, point_Andre_ID_3pT, point_Andre_ID_4eta, point_Andre_ID_4pT);
  TLine *l817 = new  TLine(point_Andre_ID_4eta, point_Andre_ID_4pT, 2.4, point_Andre_ID_4pT);
  TLine *l818 = new  TLine(2.4, point_Andre_ID_4pT, 2.4, 8.0);
  TLine *l823b = new TLine(-0.3, point_Andre_ID_1pT, -0.3, point_Andre_ID_1pT);
  TLine *l823c = new TLine(-0.3, point_Andre_ID_1pT, -1*point_Andre_ID_1eta, point_Andre_ID_1pT);
  TLine *l824 = new  TLine(-1*point_Andre_ID_1eta, point_Andre_ID_1pT, -1*point_Andre_ID_2eta, point_Andre_ID_2pT);
  TLine *l825 = new  TLine(-1*point_Andre_ID_2eta, point_Andre_ID_2pT, -1*point_Andre_ID_3eta, point_Andre_ID_3pT);
  TLine *l826 = new  TLine(-1*point_Andre_ID_3eta, point_Andre_ID_3pT, -1*point_Andre_ID_4eta, point_Andre_ID_4pT);
  TLine *l827 = new  TLine(-1*point_Andre_ID_4eta, point_Andre_ID_4pT, -2.4, point_Andre_ID_4pT);
  TLine *l828 = new  TLine(-2.4, point_Andre_ID_4pT, -2.4, 8.0);
  
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


// original SoftID


  float point_SoftID_1eta = 1.0;
  float point_SoftID_1pT = 3.3;
  
  float point_SoftID_2eta = 1.4;
  float point_SoftID_2pT = 2.1;

  float point_SoftID_3eta = 1.4;
  float point_SoftID_3pT = 1.4;

  float point_SoftID_4eta = 1.7;
  float point_SoftID_4pT = 1.0;
  

  
  TLine *l713 = new TLine(-0.3, 3.3, 0.3, 3.3);
  TLine *l713b = new TLine(0.3, 3.3, 0.3, 3.3);
  TLine *l713c = new TLine(0.3, point_SoftID_1pT, point_SoftID_1eta, point_SoftID_1pT);
  TLine *l714 = new  TLine(point_SoftID_1eta, point_SoftID_1pT, point_SoftID_2eta, point_SoftID_2pT);
  TLine *l715 = new  TLine(point_SoftID_2eta, point_SoftID_2pT, point_SoftID_3eta, point_SoftID_3pT);
  TLine *l716 = new  TLine(point_SoftID_3eta, point_SoftID_3pT, point_SoftID_4eta, point_SoftID_4pT);
  TLine *l717 = new  TLine(point_SoftID_4eta, point_SoftID_4pT, 2.4, point_SoftID_4pT);
  TLine *l718 = new  TLine(2.4, point_SoftID_4pT, 2.4, 8.0);
  TLine *l723b = new TLine(-0.3, point_SoftID_1pT, -0.3, point_SoftID_1pT);
  TLine *l723c = new TLine(-0.3, point_SoftID_1pT, -1*point_SoftID_1eta, point_SoftID_1pT);
  TLine *l724 = new  TLine(-1*point_SoftID_1eta, point_SoftID_1pT, -1*point_SoftID_2eta, point_SoftID_2pT);
  TLine *l725 = new  TLine(-1*point_SoftID_2eta, point_SoftID_2pT, -1*point_SoftID_3eta, point_SoftID_3pT);
  TLine *l726 = new  TLine(-1*point_SoftID_3eta, point_SoftID_3pT, -1*point_SoftID_4eta, point_SoftID_4pT);
  TLine *l727 = new  TLine(-1*point_SoftID_4eta, point_SoftID_4pT, -2.4, point_SoftID_4pT);
  TLine *l728 = new  TLine(-2.4, point_SoftID_4pT, -2.4, 8.0);
  
  l713->SetLineColor(kMagenta);
  l713->SetLineWidth(2);
  l713b->SetLineColor(kMagenta);
  l713b->SetLineWidth(2);
  l713c->SetLineColor(kMagenta);
  l713c->SetLineWidth(2);
  l714->SetLineColor(kMagenta);
  l714->SetLineWidth(2);
  l715->SetLineColor(kMagenta);
  l715->SetLineWidth(2);
  l716->SetLineColor(kMagenta);
  l716->SetLineWidth(2);
  l717->SetLineColor(kMagenta);
  l717->SetLineWidth(2);
  l718->SetLineColor(kMagenta);
  l718->SetLineWidth(2);
  l723b->SetLineColor(kMagenta);
  l723b->SetLineWidth(2);
  l723c->SetLineColor(kMagenta);
  l723c->SetLineWidth(2);
  l724->SetLineColor(kMagenta);
  l724->SetLineWidth(2);
  l725->SetLineColor(kMagenta);
  l725->SetLineWidth(2);
  l726->SetLineColor(kMagenta);
  l726->SetLineWidth(2);
  l727->SetLineColor(kMagenta);
  l727->SetLineWidth(2);
  l728->SetLineColor(kMagenta);
  l728->SetLineWidth(2);

  
  l713->SetLineColor(kMagenta);
  l713->SetLineStyle(3);
  l713b->SetLineColor(kMagenta);
  l713b->SetLineStyle(3);
  l713c->SetLineColor(kMagenta);
  l713c->SetLineStyle(3);
  l714->SetLineColor(kMagenta);
  l714->SetLineStyle(3);
  l715->SetLineColor(kMagenta);
  l715->SetLineStyle(3);
  l716->SetLineColor(kMagenta);
  l716->SetLineStyle(3);
  l717->SetLineColor(kMagenta);
  l717->SetLineStyle(3);
  l718->SetLineColor(kMagenta);
  l718->SetLineStyle(3);
  l723b->SetLineColor(kMagenta);
  l723b->SetLineStyle(3);
  l723c->SetLineColor(kMagenta);
  l723c->SetLineStyle(3);
  l724->SetLineColor(kMagenta);
  l724->SetLineStyle(3);
  l725->SetLineColor(kMagenta);
  l725->SetLineStyle(3);
  l726->SetLineColor(kMagenta);
  l726->SetLineStyle(3);
  l727->SetLineColor(kMagenta);
  l727->SetLineStyle(3);
  l728->SetLineColor(kMagenta);
  l728->SetLineStyle(3);





// TRGIGGER !!!!!

  float point_TRG_0eta = 0.3;
  float point_TRG_0pT = 3.45;
    
  float point_TRG_1eta = 1.1;
  float point_TRG_1pT = 3.3;

  float point_TRG_2eta = 1.45;
  float point_TRG_2pT = 2.15;

  float point_TRG_3eta = 1.65;
  float point_TRG_3pT = point_TRG_2pT;

  float point_TRG_4eta = 2.1;
  float point_TRG_4pT = 1.2;


  TLine *l910a = new TLine(-1*point_TRG_0eta, point_TRG_0pT, -1*point_TRG_0eta, point_TRG_1pT);
  TLine *l910b = new TLine(point_TRG_0eta, point_TRG_0pT, point_TRG_0eta, point_TRG_1pT);
  
  TLine *l913 = new TLine(-1*point_TRG_0eta, point_TRG_0pT, point_TRG_0eta, point_TRG_0pT);
  TLine *l913b = new TLine(point_TRG_0eta, point_TRG_1pT, point_TRG_0eta, point_TRG_1pT);
  TLine *l913c = new TLine(point_TRG_0eta, point_TRG_1pT, point_TRG_1eta, point_TRG_1pT);
  TLine *l914 = new  TLine(point_TRG_1eta, point_TRG_1pT, point_TRG_2eta, point_TRG_2pT);
  TLine *l915 = new  TLine(point_TRG_2eta, point_TRG_2pT, point_TRG_3eta, point_TRG_3pT);
  TLine *l916 = new  TLine(point_TRG_3eta, point_TRG_3pT, point_TRG_4eta, point_TRG_4pT);
  TLine *l917 = new  TLine(point_TRG_4eta, point_TRG_4pT, 2.4, point_TRG_4pT);
  TLine *l918 = new  TLine(2.4, point_TRG_4pT, 2.4, 8.0);
  TLine *l923b = new TLine(-1*point_TRG_0eta, point_TRG_1pT, -1*point_TRG_0eta, point_TRG_1pT);
  TLine *l923c = new TLine(-1*point_TRG_0eta, point_TRG_1pT, -1*point_TRG_1eta, point_TRG_1pT);
  TLine *l924 = new  TLine(-1*point_TRG_1eta, point_TRG_1pT, -1*point_TRG_2eta, point_TRG_2pT);
  TLine *l925 = new  TLine(-1*point_TRG_2eta, point_TRG_2pT, -1*point_TRG_3eta, point_TRG_3pT);
  TLine *l926 = new  TLine(-1*point_TRG_3eta, point_TRG_3pT, -1*point_TRG_4eta, point_TRG_4pT);
  TLine *l927 = new  TLine(-1*point_TRG_4eta, point_TRG_4pT, -2.4, point_TRG_4pT);
  TLine *l928 = new  TLine(-2.4, point_TRG_4pT, -2.4, 8.0);
  
  l913->SetLineColor(kRed);
  l913->SetLineWidth(2);
  l910a->SetLineColor(kRed);
  l910a->SetLineWidth(2);
  l910b->SetLineColor(kRed);
  l910b->SetLineWidth(2);
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






 
  
  
  cout << endl << "******* making histos *******" << endl << endl;

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

  TLegend *l123 = new TLegend(0.1,0.75,0.25,0.90,NULL,"brNDC");
  l123->AddEntry(sp_mu_pT_mu_rap_Acc_123,"Reco / Gen", "");
  l123->AddEntry(l813,"SoftID for Andre", "l");
  l123->AddEntry(l713,"SoftID", "l");
  l123->AddEntry(l913,"SoftID -> TRG", "l");
//  l123->AddEntry(l613,"hybridSoftID", "l");
//  l123->AddEntry(l513,"SoftID - Marek", "l");
  l123->SetFillColor(10);
  l123->Draw();


    l910a->DrawClone("same");
    l910b->DrawClone("same");
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

/*
    l_TnP_0->DrawClone("same");
    l_TnP_1->DrawClone("same");
    l_TnP_m1->DrawClone("same");
    l_TnP_2->DrawClone("same");
    l_TnP_m2->DrawClone("same");
    l_TnP_3->DrawClone("same");
    l_TnP_m3->DrawClone("same");
    l_TnP_4->DrawClone("same");
    l_TnP_m4->DrawClone("same");


    b_TnP_0->DrawClone("same");
    b_TnP_1->DrawClone("same");
    b_TnP_2->DrawClone("same");
    b_TnP_3->DrawClone("same");
    b_TnP_4->DrawClone("same");
    b_TnP_5->DrawClone("same");
    b_TnP_6->DrawClone("same");
    b_TnP_7->DrawClone("same");

*/


/*


    l613->DrawClone("same");
    l613b->DrawClone("same");
    l613c->DrawClone("same");
    l614->DrawClone("same");
    l615->DrawClone("same");
    l616->DrawClone("same");
    l617->DrawClone("same");
    l618->DrawClone("same");
    l623b->DrawClone("same");
    l623c->DrawClone("same");
    l624->DrawClone("same");
    l625->DrawClone("same");
    l626->DrawClone("same");
    l627->DrawClone("same");
    l628->DrawClone("same");





    l513->DrawClone("same");
    l513b->DrawClone("same");
    l513c->DrawClone("same");
    l514->DrawClone("same");
    l515->DrawClone("same");
    l516->DrawClone("same");
    l517->DrawClone("same");
    l518->DrawClone("same");
    l523b->DrawClone("same");
    l523c->DrawClone("same");
    l524->DrawClone("same");
    l525->DrawClone("same");
    l526->DrawClone("same");
    l527->DrawClone("same");
    l528->DrawClone("same");
*/





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





























/*
( 0 < | η | 0.3 & p T > 3.4 GeV ) OR
( 0.3 < | η | 1.1 & p T > 3.3 GeV ) OR
( 1.1 < | η | 1.4 & p T > 7.7 − 4.0 × | η | GeV ) OR
( 1.4 < | η | 1.55 & p T > 2.1 GeV ) OR
( 1.55 < | η | 2.2 & p T > 4.25 − 1.39 × | η | GeV ) OR
( 2.2 < | η | 2.4 & p T > 1.2 GeV )




  float point_hybridSoftID_1eta = 1.1;
  float point_hybridSoftID_1pT = 3.3;
  
  float point_hybridSoftID_2eta = 1.4;
  float point_hybridSoftID_2pT = 2.1;

  float point_hybridSoftID_3eta = 1.55;
  float point_hybridSoftID_3pT = 2.1;

  float point_hybridSoftID_4eta = 2.2;
  float point_hybridSoftID_4pT = 1.2;
  
  TLine *l613 = new TLine(-0.3, 3.4, 0.3, 3.4);
  TLine *l613b = new TLine(0.3, 3.4, 0.3, 3.4);
  TLine *l613c = new TLine(0.3, point_hybridSoftID_1pT, point_hybridSoftID_1eta, point_hybridSoftID_1pT);
  TLine *l614 = new  TLine(point_hybridSoftID_1eta, point_hybridSoftID_1pT, point_hybridSoftID_2eta, point_hybridSoftID_2pT);
  TLine *l615 = new  TLine(point_hybridSoftID_2eta, point_hybridSoftID_2pT, point_hybridSoftID_3eta, point_hybridSoftID_3pT);
  TLine *l616 = new  TLine(point_hybridSoftID_3eta, point_hybridSoftID_3pT, point_hybridSoftID_4eta, point_hybridSoftID_4pT);
  TLine *l617 = new  TLine(point_hybridSoftID_4eta, point_hybridSoftID_4pT, 2.4, point_hybridSoftID_4pT);
  TLine *l618 = new  TLine(2.4, point_hybridSoftID_4pT, 2.4, 8.0);
  TLine *l623b = new TLine(-0.3, point_hybridSoftID_1pT, -0.3, point_hybridSoftID_1pT);
  TLine *l623c = new TLine(-0.3, point_hybridSoftID_1pT, -1*point_hybridSoftID_1eta, point_hybridSoftID_1pT);
  TLine *l624 = new  TLine(-1*point_hybridSoftID_1eta, point_hybridSoftID_1pT, -1*point_hybridSoftID_2eta, point_hybridSoftID_2pT);
  TLine *l625 = new  TLine(-1*point_hybridSoftID_2eta, point_hybridSoftID_2pT, -1*point_hybridSoftID_3eta, point_hybridSoftID_3pT);
  TLine *l626 = new  TLine(-1*point_hybridSoftID_3eta, point_hybridSoftID_3pT, -1*point_hybridSoftID_4eta, point_hybridSoftID_4pT);
  TLine *l627 = new  TLine(-1*point_hybridSoftID_4eta, point_hybridSoftID_4pT, -2.4, point_hybridSoftID_4pT);
  TLine *l628 = new  TLine(-2.4, point_hybridSoftID_4pT, -2.4, 8.0);
  
  l613->SetLineColor(kBlue);
  l613->SetLineWidth(2);
  l613b->SetLineColor(kBlue);
  l613b->SetLineWidth(2);
  l613c->SetLineColor(kBlue);
  l613c->SetLineWidth(2);
  l614->SetLineColor(kBlue);
  l614->SetLineWidth(2);
  l615->SetLineColor(kBlue);
  l615->SetLineWidth(2);
  l616->SetLineColor(kBlue);
  l616->SetLineWidth(2);
  l617->SetLineColor(kBlue);
  l617->SetLineWidth(2);
  l618->SetLineColor(kBlue);
  l618->SetLineWidth(2);
  l623b->SetLineColor(kBlue);
  l623b->SetLineWidth(2);
  l623c->SetLineColor(kBlue);
  l623c->SetLineWidth(2);
  l624->SetLineColor(kBlue);
  l624->SetLineWidth(2);
  l625->SetLineColor(kBlue);
  l625->SetLineWidth(2);
  l626->SetLineColor(kBlue);
  l626->SetLineWidth(2);
  l627->SetLineColor(kBlue);
  l627->SetLineWidth(2);
  l628->SetLineColor(kBlue);
  l628->SetLineWidth(2);


  l613->SetLineColor(kBlue);
  l613->SetLineStyle(4);
  l613b->SetLineColor(kBlue);
  l613b->SetLineStyle(4);
  l613c->SetLineColor(kBlue);
  l613c->SetLineStyle(4);
  l614->SetLineColor(kBlue);
  l614->SetLineStyle(4);
  l615->SetLineColor(kBlue);
  l615->SetLineStyle(4);
  l616->SetLineColor(kBlue);
  l616->SetLineStyle(4);
  l617->SetLineColor(kBlue);
  l617->SetLineStyle(4);
  l618->SetLineColor(kBlue);
  l618->SetLineStyle(4);
  l623b->SetLineColor(kBlue);
  l623b->SetLineStyle(4);
  l623c->SetLineColor(kBlue);
  l623c->SetLineStyle(4);
  l624->SetLineColor(kBlue);
  l624->SetLineStyle(4);
  l625->SetLineColor(kBlue);
  l625->SetLineStyle(4);
  l626->SetLineColor(kBlue);
  l626->SetLineStyle(4);
  l627->SetLineColor(kBlue);
  l627->SetLineStyle(4);
  l628->SetLineColor(kBlue);
  l628->SetLineStyle(4);






  float point_softID_1eta = 1.0;
  float point_softID_1pT = 3.3;
  
  float point_softID_2eta = 1.3;
  float point_softID_2pT = 2.1;

  float point_softID_3eta = 1.3;
  float point_softID_3pT = 1.5;

  float point_softID_4eta = 1.9;
  float point_softID_4pT = 0.9;



  
  TLine *l513 = new TLine(-0.3, 3.3, 0.3, 3.3);
  TLine *l513b = new TLine(0.3, 3.3, 0.3, 3.3);
  TLine *l513c = new TLine(0.3, point_softID_1pT, point_softID_1eta, point_softID_1pT);
  TLine *l514 = new  TLine(point_softID_1eta, point_softID_1pT, point_softID_2eta, point_softID_2pT);
  TLine *l515 = new  TLine(point_softID_2eta, point_softID_2pT, point_softID_3eta, point_softID_3pT);
  TLine *l516 = new  TLine(point_softID_3eta, point_softID_3pT, point_softID_4eta, point_softID_4pT);
  TLine *l517 = new  TLine(point_softID_4eta, point_softID_4pT, 2.4, point_softID_4pT);
  TLine *l518 = new  TLine(2.4, point_softID_4pT, 2.4, 8.0);
  TLine *l523b = new TLine(-0.3, point_softID_1pT, -0.3, point_softID_1pT);
  TLine *l523c = new TLine(-0.3, point_softID_1pT, -1*point_softID_1eta, point_softID_1pT);
  TLine *l524 = new  TLine(-1*point_softID_1eta, point_softID_1pT, -1*point_softID_2eta, point_softID_2pT);
  TLine *l525 = new  TLine(-1*point_softID_2eta, point_softID_2pT, -1*point_softID_3eta, point_softID_3pT);
  TLine *l526 = new  TLine(-1*point_softID_3eta, point_softID_3pT, -1*point_softID_4eta, point_softID_4pT);
  TLine *l527 = new  TLine(-1*point_softID_4eta, point_softID_4pT, -2.4, point_softID_4pT);
  TLine *l528 = new  TLine(-2.4, point_softID_4pT, -2.4, 8.0);
  
  l513->SetLineColor(kCyan);
  l513->SetLineWidth(2);
  l513b->SetLineColor(kCyan);
  l513b->SetLineWidth(2);
  l513c->SetLineColor(kCyan);
  l513c->SetLineWidth(2);
  l514->SetLineColor(kCyan);
  l514->SetLineWidth(2);
  l515->SetLineColor(kCyan);
  l515->SetLineWidth(2);
  l516->SetLineColor(kCyan);
  l516->SetLineWidth(2);
  l517->SetLineColor(kCyan);
  l517->SetLineWidth(2);
  l518->SetLineColor(kCyan);
  l518->SetLineWidth(2);
  l523b->SetLineColor(kCyan);
  l523b->SetLineWidth(2);
  l523c->SetLineColor(kCyan);
  l523c->SetLineWidth(2);
  l524->SetLineColor(kCyan);
  l524->SetLineWidth(2);
  l525->SetLineColor(kCyan);
  l525->SetLineWidth(2);
  l526->SetLineColor(kCyan);
  l526->SetLineWidth(2);
  l527->SetLineColor(kCyan);
  l527->SetLineWidth(2);
  l528->SetLineColor(kCyan);
  l528->SetLineWidth(2);


  l513->SetLineColor(kCyan);
  l513->SetLineStyle(5);
  l513b->SetLineColor(kCyan);
  l513b->SetLineStyle(5);
  l513c->SetLineColor(kCyan);
  l513c->SetLineStyle(5);
  l514->SetLineColor(kCyan);
  l514->SetLineStyle(5);
  l515->SetLineColor(kCyan);
  l515->SetLineStyle(5);
  l516->SetLineColor(kCyan);
  l516->SetLineStyle(5);
  l517->SetLineColor(kCyan);
  l517->SetLineStyle(5);
  l518->SetLineColor(kCyan);
  l518->SetLineStyle(5);
  l523b->SetLineColor(kCyan);
  l523b->SetLineStyle(5);
  l523c->SetLineColor(kCyan);
  l523c->SetLineStyle(5);
  l524->SetLineColor(kCyan);
  l524->SetLineStyle(5);
  l525->SetLineColor(kCyan);
  l525->SetLineStyle(5);
  l526->SetLineColor(kCyan);
  l526->SetLineStyle(5);
  l527->SetLineColor(kCyan);
  l527->SetLineStyle(5);
  l528->SetLineColor(kCyan);
  l528->SetLineStyle(5);







*/







