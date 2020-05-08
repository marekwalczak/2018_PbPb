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

          
cout << endl << "******* making histos *******" << endl << endl;



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



  TLine *l13 = new TLine(-0.3, 3.35, 0.3, 3.35);
  
  TLine *l13b = new TLine(0.3, 3.35, 0.3, 3.25);
  TLine *l13c = new TLine(0.3, 3.25, 1.0, 3.25);
  TLine *l14 = new TLine(1.0, 3.25, 1.4, 2.35);
  TLine *l15 = new TLine(1.4, 2.35, 1.8, 2.35);
  TLine *l16 = new TLine(1.8, 2.35, 2.0, 1.4);
  TLine *l17 = new TLine(2.0, 1.4, 2.4, 1.4);
  TLine *l18 = new TLine(2.4, 1.4, 2.4, 6.5);
  
  TLine *l23b = new TLine(-0.3, 3.35, -0.3, 3.25);
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





//*************** SP - MUON pT vs rap profile *******************//
  TH2F *sp_mu_pT_mu_rap_Acc = (TH2F *)f1->Get("sp_mu_pT_mu_rap_Acc");

  TCanvas *c4 = new TCanvas("c4","c4",1000,600);
  c4->SetLogz();
  
  sp_mu_pT_mu_rap_Acc->GetXaxis()->SetRangeUser(-7,7);
  sp_mu_pT_mu_rap_Acc->GetYaxis()->SetRangeUser(1,6.5);
  sp_mu_pT_mu_rap_Acc->GetXaxis()->SetTitleOffset(1.2);
  sp_mu_pT_mu_rap_Acc->GetYaxis()->SetTitleOffset(1.22);
 
  //sp_mu_pT_mu_rap_Acc->GetXaxis()->SetTitle("mu rap");

  //sp_mu_pT_mu_rap_Acc->SetMarkerStyle(8);
  //sp_mu_pT_mu_rap_Acc->SetMarkerColor(kRed);
  sp_mu_pT_mu_rap_Acc->SetLineColor(kRed);
  sp_mu_pT_mu_rap_Acc->SetLineWidth(2);

  sp_mu_pT_mu_rap_Acc->Draw("colz");

  sp_mu_pT_mu_rap_Acc->SetStats(0); // gets rid of anoying stat box

  TLegend *leg4 = new TLegend(0.1,0.80,0.25,0.90,NULL,"brNDC");
  leg4->AddEntry(sp_mu_pT_mu_rap_Acc,"Reco / Gen", "");
  leg4->SetFillColor(10);
  leg4->Draw();

/*
    l9->DrawClone("same");
    l10->DrawClone("same");
    l11->DrawClone("same");
    l12->DrawClone("same");
    l_10->DrawClone("same");
    l_11->DrawClone("same");
    l_12->DrawClone("same");
*/

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

  c4->Update();
  c4->SaveAs("plots/Acc/sp_mu_pT_mu_rap_Acc_Profile.png");




//*************** SP - MUON pT vs rap 10% *******************//



  for (int i=1;i<sp_mu_pT_mu_rap_Acc->GetNbinsX();i++){
    for (int j=1;j<sp_mu_pT_mu_rap_Acc->GetNbinsY();j++){
      if(sp_mu_pT_mu_rap_Acc->GetBinContent(i,j) < 0.1) sp_mu_pT_mu_rap_Acc->SetBinContent(i,j,0);
    }
  }




  TCanvas *c5 = new TCanvas("c5","c5",1000,600);
  c5->SetLogz();
  
  sp_mu_pT_mu_rap_Acc->GetXaxis()->SetRangeUser(-7,7);
  sp_mu_pT_mu_rap_Acc->GetYaxis()->SetRangeUser(1,6.5);
  sp_mu_pT_mu_rap_Acc->GetXaxis()->SetTitleOffset(1.2);
  sp_mu_pT_mu_rap_Acc->GetYaxis()->SetTitleOffset(1.22);
 
  //sp_mu_pT_mu_rap_Acc->GetXaxis()->SetTitle("mu rap");

  //sp_mu_pT_mu_rap_Acc->SetMarkerStyle(8);
  //sp_mu_pT_mu_rap_Acc->SetMarkerColor(kRed);
  sp_mu_pT_mu_rap_Acc->SetLineColor(kRed);
  sp_mu_pT_mu_rap_Acc->SetLineWidth(2);

  sp_mu_pT_mu_rap_Acc->Draw("colz");

  sp_mu_pT_mu_rap_Acc->SetStats(0); // gets rid of anoying stat box

  TLegend *leg5 = new TLegend(0.1,0.80,0.25,0.90,NULL,"brNDC");
  leg5->AddEntry(sp_mu_pT_mu_rap_Acc,"Reco / Gen", "");
  leg5->SetFillColor(10);
  leg5->Draw();

/*
    l9->DrawClone("same");
    l10->DrawClone("same");
    l11->DrawClone("same");
    l12->DrawClone("same");
    l_10->DrawClone("same");
    l_11->DrawClone("same");
    l_12->DrawClone("same");
*/


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
    
    
    
  c5->Update();
  c5->SaveAs("plots/Acc/sp_mu_pT_mu_rap_Acc_Profile_10%.png");









cout << endl << "******* THE END *******" << endl << endl;


}














