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


//#include "/Users/marekwalczak/Data/2018PbPb/MC_coh_1S_05M_xDM/ReadTree.C"
#include "/Users/marekwalczak/Data/2018PbPb/MC_coh_1S_05M_xDM_official/ReadTree.C"



void draw_dual_MC_from_files.c(){

  system("mkdir plots_MC_comparison");

// not working at all now



cout << endl << "******* opening files *******" << endl;

   //TFile* f1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_coh_1S_05M_xDM/MC_coh_1S_05M_xDM.root","read");
   TFile* f1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_coh_1S_05M_xDM_official/MC_coh_1S_05M_xDM_official.root","read");

    TTree* myTree_1 = (TTree*)file1->Get("hionia/myTree"); // use for MC and data
	ReadTree *tree = new ReadTree(myTree_1);

	Long64_t nentries = tree->fChain->GetEntries(); // get the entries from tree
	cout << endl << "nentries: " << nentries << endl;
 
  // fChain->SetBranchAddress("Reco_QQ_4mom", &Reco_QQ_4mom, &b_Reco_QQ_4mom);


cout << endl << "******* making histos *******" << endl << endl;


//*************** QQ MASS *******************//



  TH1F *histo_QQ_M = (TH1F *)f1->Get("histo_QQ_M");
  //TH1F *histo_QQ_M_2 = (TH1F *)f2->Get("histo_QQ_M");  
    
  //histo_QQ_M->Scale(1./(histo_QQ_M->Integral()));
  //histo_QQ_M_2->Scale(1./(histo_QQ_M_2->Integral()));
  
  TCanvas *c3 = new TCanvas("c3","c3",1000,600);
  //gPad -> SetLogy(1);  
  
  histo_QQ_M->GetXaxis()->SetRangeUser(2,5);
 // histo_QQ_M->GetYaxis()->SetRangeUser(0,.4);
  histo_QQ_M->GetXaxis()->SetTitleOffset(1.2);
  histo_QQ_M->GetYaxis()->SetTitleOffset(1.22);
 
  histo_QQ_M->GetXaxis()->SetTitle("QQ mass");
  
  //histo_QQ_M->SetMarkerStyle(8);
  //histo_QQ_M->SetMarkerColor(kRed);
  histo_QQ_M->SetLineColor(kRed);
  histo_QQ_M->SetLineWidth(2);
 // histo_QQ_M_2->SetLineColor(kBlue);
 // histo_QQ_M_2->SetLineWidth(2);
 // histo_QQ_M_2->SetLineStyle(1);

  histo_QQ_M->Draw("");
 // histo_QQ_M_2->Draw("hist same");

  histo_QQ_M->SetStats(0); // gets rid of anoying stat box

  TLegend *l3 = new TLegend(0.55,0.70,0.75,0.80,NULL,"brNDC");
  l3->AddEntry(histo_QQ_M,"Official","l");
  //l3->AddEntry(histo_QQ_M_2,"Marek","l");
  l3->SetFillColor(10);
  l3->Draw();

  c3->Update();
  c3->SaveAs("plots_MC_comparison/QQ_M_reco.pdf");





cout << endl << "******* THE END *******" << endl << endl;


}














