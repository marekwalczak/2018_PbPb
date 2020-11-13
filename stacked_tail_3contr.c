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



// ALICE Collaboration, nucleon dissociation
Double_t ALICEtail(Double_t *x, Double_t *par) {
   return par[0] * x[0] * pow((1.0 + ( par[1] / par[2]) * pow(x[0], 2) ), -par[2]); 
   //return par*x[0]*pow((1.0 + ( 1.8 / 3.6)*pow(x[0], 2) ), -3.6);
}

/// IN PROGRESS (ADDING TAIL) - still not added

void stacked_tail_3contr() {


    // signal dirname:
    TString dirname = "pT_spectrum_bkg1-sig-bkg2_sum630";


    TFile* f1 = new TFile(dirname + "/plots.root","read"); 
    TFile* f3 = new TFile("plots_MCc1s_30mupt60_binning/plots.root","read"); // MC
    TFile* f4 = new TFile("res_MCi1s_aco0075/plots.root","read"); // MC

    TH1F *histo_Data = (TH1F *)f1->Get("histo_QQ_pT_sig_min_bkg1and2");
    TH1F *histo_MC_CohUps = (TH1F *)f3->Get("histo_QQ_pT");
    TH1F *histo_MC_IncohUps = (TH1F *)f4->Get("histo_QQ_pT");


    int rebin =8;
    int number_of_bins = 160/rebin;
    
    histo_Data->Rebin(rebin);
    histo_MC_CohUps->Rebin(rebin);
    histo_MC_IncohUps->Rebin(rebin);
    
    
    float count_data  = 0;
    float count_gg    = 0;
    float count_coh   = 0;
    float count_incoh = 0;
    float tail_count_data  = 0;
    float all_data  = 0;

    for (int i = 1; i <= number_of_bins; i++) {
      all_data += histo_Data->GetBinContent(i);
    }


    float all_coh   =  histo_MC_CohUps->GetEntries();
    float all_incoh =  histo_MC_IncohUps->GetEntries();
    

    float from = 0.4;
    float to   = 2.0;
    

       // see the binning of the histos !!!
    int start = static_cast<int>((from * (40/rebin)) + 1);
    int stop  = static_cast<int>(to * (40/rebin));
    
    for (int i = start; i <= stop; i++) {
      count_data += histo_Data->GetBinContent(i);
    }
    
    for (int i=start; i <= stop; i++) {
      count_coh += histo_MC_CohUps->GetBinContent(i);
    }
    
    for (int i=start; i <= stop; i++) {
      count_incoh += histo_MC_IncohUps->GetBinContent(i);
    }


    float tail_from = 1.2;
    float tail_to   = 2.0;
    
       // see the binning of the histos !!!
    int tail_start = static_cast<int>((tail_from * (40/rebin)) + 1);
    int tail_stop  = static_cast<int>(tail_to * (40/rebin));
 
    for (int i = tail_start; i <= tail_stop; i++) {
      tail_count_data += histo_Data->GetBinContent(i);
    }
    



// **** ALICE ***** //
   // create a TF1 with the range from 1 to 4 and 2 parameters
   TF1 *fitAlice = new TF1( "fitAlice", ALICEtail, 1.2, 3.0, 3 );
   fitAlice->SetNpx(400); // Set the number of points used to draw the function
   fitAlice->SetLineWidth(4);
  // fitAlice->SetLineColor(kMagenta);

   // Try without starting values for the parameters
   // This defaults to 1 for each param.
   // this results in an ok fit for the polynomial function
   
   
   fitAlice->FixParameter(2, 1.79);
   fitAlice->FixParameter(3, 3.58);
   
  // fitAlice->SetParLimits(2, 1.0 , 2.0);
  // fitAlice->SetParLimits(3, 3.0 , 4.0);
   
  //histo_Data->Fit("fitAlice","0");
   histo_Data->Fit( "fitAlice", "RQ+" ); // V instead of Q gives terminal output , "ep"

   Double_t parA[3];
   fitAlice->GetParameters(parA);

   TF1 *FcnAlice = new TF1("FcnAlice", ALICEtail, 0, 4, 3 );
   FcnAlice->SetParameters(parA);
   
   float tailAlice_all = FcnAlice->Integral(0, 4.0 ) / (histo_Data->GetBinWidth(1) * rebin) ;
   cout << "Integral of fitted FcnAlice for the whole range is : " << tailAlice_all << endl;

   float tailAlice = FcnAlice->Integral(from, to) / (histo_Data->GetBinWidth(1) * rebin) ;
   cout << "Integral of fitted FcnAlice for given range of incoh region is : " << tailAlice << endl;
   

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


    cout << "All tailAlice: "  <<  all_tailAlice << ", in given range: " << count_tailAlice << ", given bin: "  << histo_tail->GetBinContent(50) << endl;










    cout << endl << "The range of tail is from " << tail_from << " to " << tail_to << endl;
    cout << "All data :	"  <<  all_data  << ",	in given range: " << tail_count_data   << endl << endl;




    cout << endl;
    cout << "The range is from " << from << " to " << to << endl << endl;
    cout << "All data :	"  <<  all_data  << ",	in given range: " << count_data  << ",	given bin:	"  << histo_Data->GetBinContent(1)        << endl;
    cout << "All coh  :	"  <<  all_coh   << ",	in given range: " << count_coh   << ",	given bin:	"  << histo_MC_CohUps->GetBinContent(1)   << endl;
    cout << "All incoh:	"  <<  all_incoh << ",	in given range: " << count_incoh << ",	given bin:	"  << histo_MC_IncohUps->GetBinContent(1) << endl;
    cout << endl;

   
   float fract_incoh = count_incoh / all_incoh;
   float tot_inc = count_data / fract_incoh;
   float tot_coh = all_data  - tot_inc;
   
   
   cout << endl << "For the pT range from " << from << " to " << to << ":" << endl;
   cout << "Data:   " << count_data << endl;
   cout << "Fraction of incoh events in this range is: " << fract_incoh << endl;
   cout << "So the total number of incoh events is:    " << tot_inc << endl;
   cout << "So the total number of coh events is  :    " << tot_coh << endl;
   cout << "And the total number of data events is:    " << all_data << endl;

   THStack *hs = new THStack("hs"," ;QQ pT;events");
   double content = 0;
   
   histo_MC_CohUps->Scale(tot_coh/(histo_MC_CohUps->Integral()));
   TH1F *h1 = new TH1F("h1","test hstack", number_of_bins, 0, 4);
  // fill a histo, normal methods failed here :/
  for (int i=1; i<=number_of_bins; i++)
  {
   content = histo_MC_CohUps->GetBinContent(i);
   h1->SetBinContent(i, content);
  }
   h1->SetFillColor(kRed);
   hs->Add(h1);
   
   
   histo_MC_IncohUps->Scale(tot_inc/(histo_MC_IncohUps->Integral()));
   TH1F *h2 = new TH1F("h2","test hstack", number_of_bins, 0, 4);
  // fill a histo, normal methods failed here :/
  for (int i=1; i<=number_of_bins; i++)
  {
   content = histo_MC_IncohUps->GetBinContent(i);
   h2->SetBinContent(i, content);
  }
   h2->SetFillColor(kBlue);
   hs->Add(h2);


   TH1F *h4 = new TH1F("h4","test hstack", number_of_bins, 0, 4);
  // fill a histo, normal methods failed here :/
  for (int i=1; i<=number_of_bins; i++)
  {
   content = histo_tail->GetBinContent(i);
   h4->SetBinContent(i, content);
  }
   h4->SetFillColor(kCyan);
   //hs->Add(h4);




   hs->SetMinimum(-15);
   hs->SetMaximum(600);





   TCanvas *cs = new TCanvas("cs","cs",10,10,900,600);


        
/*

   TH1F* histo_QQ_pT = new TH1F("histo_QQ_pT","QQ_pT; QQ_pT [GeV]; events ",number_of_bins,0,4);
   histo_QQ_pT =cs->DrawFrame(0.,0.,1.,1.);
   histo_QQ_pT->SetXTitle("x");           
   cs->Modified();       
*/

   float uncert = 0;
   TText T; 
   T.SetTextFont(42); 
   T.SetTextAlign(21);
  // hs->GetYaxis()->SetRangeUser(0,700);
   hs->Draw(); 
   T.DrawTextNDC(.5,.95,"sideband subtracted signal");

   TH1F *hd = new TH1F("hd","data", number_of_bins, 0, 4);
  // fill a histo, normal methods failed here :/
  for (int i=1; i<=number_of_bins; i++)
  {
   content = histo_Data->GetBinContent(i);
   hd->SetBinContent(i, content);
   uncert = histo_Data->GetBinError(i);
   hd->SetBinError(i, uncert);
  }
  
  hd->SetMarkerStyle(20);
  hd->SetMarkerSize(1.0);
  hd->SetMarkerColor(kBlack);
  hd->SetLineColor(kBlack);
 // hs->Draw("same"); 
  hd->Draw("same, E0");
  

  TLegend *l3 = new TLegend(0.6,0.7,0.8,0.85,NULL,"brNDC");
  l3->AddEntry(h1, Form("Incoherent : %.0f",tot_inc), "");
  l3->AddEntry(h1, Form("Coherent   : %.0f",tot_coh), "");
  //l3->SetFillColor(10);
  l3->Draw();
  
   cs->Update();

   cs->SaveAs(dirname + "/stacked_pT.pdf");
   
  system("mkdir signal_stacked");
   
   cs->SaveAs("signal_stacked/" + dirname + ".pdf");


   
}










/*

void stacked() {






   THStack *hs = new THStack("hs","");
   
   TH1F *h1 = new TH1F("h1","test hstack",10,-4,4);
   h1->FillRandom("gaus",20000);
   h1->SetFillColor(kRed);
   hs->Add(h1);
   
   TH1F *h2 = new TH1F("h2","test hstack",10,-4,4);
   h2->FillRandom("gaus",15000);
   h2->SetFillColor(kBlue);
   hs->Add(h2);
   
   TH1F *h3 = new TH1F("h3","test hstack",10,-4,4);
   h3->FillRandom("gaus",10000);
   h3->SetFillColor(kGreen);
   hs->Add(h3);
   
   TCanvas *cs = new TCanvas("cs","cs",10,10,700,900);
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
   cs->Divide(2,2);
   cs->cd(1); hs->Draw(); T.DrawTextNDC(.5,.95,"Default drawing option");
   cs->cd(2); hs->Draw("nostack"); T.DrawTextNDC(.5,.95,"Option \"nostack\"");
   cs->cd(3); hs->Draw("nostackb"); T.DrawTextNDC(.5,.95,"Option \"nostackb\"");
   cs->cd(4); hs->Draw("lego1"); T.DrawTextNDC(.5,.95,"Option \"lego1\"");
   
   
   return cs;
   
}

*/




