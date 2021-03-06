
#include <iostream>
#include "TLatex.h"
#include "TString.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TFile.h"
#include "TH2F.h"
#include "TStyle.h"
#include "TEventList.h"
#include "TCut.h"
#include "TVirtualPad.h"
#include "CMS/tdrStyle.C"
#include "CMS/CMS_lumi.C"

void DrawHisto_mu_pT(){
  cout << "YellowPlot: Starting macro" << endl;
  cout << "YellowPlot: Setting styles..." << endl;

  // Henceforth, this macro will use only CMS TDR style macro.
  // Margins, fonts, can be handled by adjusting this
  // style macro.  Leave some of the parameters that are typically fiddled with below


  setTDRStyle();



  TString inFileName = "plots/plots.root";
  cout << "YellowPlot: Opening histogram file: " << inFileName << endl;

  TFile *inf = new TFile(inFileName,"READ");
  TH1F* pTHisto = (TH1F*) inf->Get("histo_mu_pT");
  
  
  
  if (pTHisto==0x0) { 
    cout << "Histogram not found in the input file." << endl;
    return;
  }
  cout << pTHisto->GetName() << ", " << pTHisto->GetNbinsX() << endl;
  
  // Set up the styles of the histogram
  pTHisto->GetYaxis()->SetTitleOffset(2);
  pTHisto->GetYaxis()->SetTitleSize(0.04);
  pTHisto->GetXaxis()->SetTitleOffset(1.25);
  pTHisto->GetXaxis()->SetTitleSize(0.045);
  //pTHisto->Rebin(4);

  // Set up the Canvas
  TCanvas* yellowPlot = new TCanvas("yellowPlot","yellowPlot",600,600);
  //yellowPlot->SetLogx();
  //yellowPlot->SetLogy();
  cout << pTHisto->GetName() << ", " << pTHisto->GetNbinsX() << endl;

  // Draw histograms
  cout << "Drawing histogram: " << pTHisto->GetEntries() << " entries"<< endl;
  pTHisto->GetXaxis()->SetRangeUser(2.5,6.5);
  //pTHisto->GetYaxis()->SetRangeUser(0,1700);
  pTHisto->GetXaxis()->SetTitleFont(42);
  pTHisto->GetYaxis()->SetTitleFont(42);
  pTHisto->GetXaxis()->SetTitle("p^{#mu}_{T} [GeV]");
  pTHisto->GetYaxis()->SetTitle("Number of muons");
  pTHisto->SetFillColor(kYellow);
  pTHisto->SetLineWidth(2);
  pTHisto->SetLineColor(kBlue+1);
  pTHisto->Draw(""); 


  //
  // Options to be used with the CMS_lumi macro
  //
  double entries = pTHisto->GetEntries();
  writeExtraText = false;       // if extra text
  extraText      = Form("%g muons", entries);  // default extra text is "Preliminary"
  
  //
  // iPeriod options: 99 for pPb 5.02 TeV, 101 for PbPb 2011, 102 for pp 2013
  //
  // iPeriod 99 will give sqrt(s) = 5.02 TeV, but the collision and luminosity need
  // to be changed.

  int iPeriod      = 99;     
  lumiTextOffset   = 0.3; // default 0.28
  
  //lumi_5TeV = "pp, ~20 pb^{-1} lumi";
  lumi_5TeV = "PbPb data"; // , 1621,60 #mub^{-1}

  // Call the CMS_lumi macro to draw:
  // CMS preliminary, aligned on the right and justified (iPos=33, third argument)
  // integrated luminosity (drawn on top left, out of frame, or use lumiTextOffset)
  // center of mass energy (drawn on top right, out of frame, or use lumiTextOffset)
  
  CMS_lumi(yellowPlot,iPeriod,33);

  // Note, the code for putting the CMS logo is only used
  // in the style macro if one does not write CMS preliminary.
  // For writing both, one needs to put one of them by hand.
  // This is a copy-paste of the code to insert the CMS logo, changing it to
  // a color logo. Needs to have the CMS-Color.gif file in the same directory.
  float H = gPad->GetWh();
  float W = gPad->GetWw();
  float l = gPad->GetLeftMargin();
  float t = gPad->GetTopMargin();
  float r = gPad->GetRightMargin();
  float b = gPad->GetBottomMargin();
  float posX_ =   l + 0.025*(1-l-r)*W/H;
  float posY_ = 1-t - 0.025*(1-t-b);
  float xl_0 = posX_ + 0.1;
  float yl_0 = posY_ - 0.1;
  float xl_1 = posX_ + 0.1*H/W + 0.1;
  float yl_1 = posY_;

  /*
  TASImage* CMS_logo = new TASImage("CMS-Color.gif");
  TPad* pad_logo = new TPad("logo","logo", xl_0, yl_0, xl_1, yl_1 );
  pad_logo->Draw();
  pad_logo->cd();
  CMS_logo->Draw("X");
  pad_logo->Modified();
  yellowPlot->cd();
  
  // Booking the TLatex class and set the parameters
  // CMS Preliminary (not used anymore) left as a dummy
  // Each of the peaks is done with a call to DrawLatex, which
  // makes a copy of the TLatex class style, so the style should
  // be set with the first TLatex instance, and that style will 
  // be inherited by each of the copies.

  TLatex* latex = new TLatex(0.62,0.88,"CMS Preliminary");
  latex->SetNDC();
  latex->SetTextColor(kBlack);
  latex->SetTextFont(42);
  */
  
  yellowPlot->SaveAs("plots/Histo_mu_pT.pdf"); 

  
  
}
