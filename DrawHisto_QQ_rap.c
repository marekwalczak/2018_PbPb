
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

void DrawHisto_QQ_rap(){
  cout << "YellowPlot: Starting macro" << endl;
  cout << "YellowPlot: Setting styles..." << endl;

  // Henceforth, this macro will use only CMS TDR style macro.
  // Margins, fonts, can be handled by adjusting this
  // style macro.  Leave some of the parameters that are typically fiddled with below


  setTDRStyle();



  TString inFileName = "plots/plots.root";
  cout << "YellowPlot: Opening histogram file: " << inFileName << endl;

  TFile *inf = new TFile(inFileName,"READ");
  TH1F* RapHisto = (TH1F*) inf->Get("histo_QQ_rap");
  
  
  
  if (RapHisto==0x0) { 
    cout << "Histogram not found in the input file." << endl;
    return;
  }
  cout << RapHisto->GetName() << ", " << RapHisto->GetNbinsX() << endl;
  
  // Set up the styles of the histogram
  RapHisto->GetYaxis()->SetTitleOffset(1.5);
  RapHisto->GetYaxis()->SetTitleSize(0.04);
  RapHisto->GetXaxis()->SetTitleSize(0.045);
  //RapHisto->Rebin(4);

  // Set up the Canvas
  TCanvas* yellowPlot = new TCanvas("yellowPlot","yellowPlot",600,600);
  //yellowPlot->SetLogx();
  //yellowPlot->SetLogy();
  cout << RapHisto->GetName() << ", " << RapHisto->GetNbinsX() << endl;

  // Draw histograms
  cout << "Drawing histogram: " << RapHisto->GetEntries() << " entries"<< endl;
  RapHisto->GetXaxis()->SetRangeUser(-3,3);
  //RapHisto->GetYaxis()->SetRangeUser(0,300);
  RapHisto->GetXaxis()->SetTitleFont(42);
  RapHisto->GetYaxis()->SetTitleFont(42);
  RapHisto->GetXaxis()->SetTitle("y");
  RapHisto->GetYaxis()->SetTitle("dimuons");
  RapHisto->SetFillColor(kYellow);
  RapHisto->SetLineWidth(2);
  RapHisto->SetLineColor(kBlue+1);
  RapHisto->Draw(""); 


  //
  // Options to be used with the CMS_lumi macro
  //
  
  double entries = RapHisto->GetEntries();
  writeExtraText = true;       // if extra text
  extraText      = Form("%g events", entries);  // default extra text is "Preliminary"

  int iPeriod      = 99;     
  lumiTextOffset   = 0.3; // default 0.28
  
  //lumi_5TeV = "pp, ~20 pb^{-1} lumi";
  lumi_5TeV = "PbPb, 1621,60 #mub^{-1}";

  CMS_lumi(yellowPlot,iPeriod,33);

  float H = gPad->GetWh();
  float W = gPad->GetWw();
  float l = gPad->GetLeftMargin();
  float t = gPad->GetTopMargin();
  float r = gPad->GetRightMargin();
  float b = gPad->GetBottomMargin();
  float posX_ =   l + 0.025*(1-l-r)*W/H;
  float posY_ = 1-t - 0.025*(1-t-b);
  float xl_0 = posX_;
  float yl_0 = posY_ - 0.1;
  float xl_1 = posX_ + 0.1*H/W;
  float yl_1 = posY_;
  
  /*
  TASImage* CMS_logo = new TASImage("CMS-Color.gif");
  TPad* pad_logo = new TPad("logo","logo", xl_0, yl_0, xl_1, yl_1 );
  pad_logo->Draw();
  pad_logo->cd();
  CMS_logo->Draw("X");
  pad_logo->Modified();
  yellowPlot->cd();
  
  TLatex* latex = new TLatex(0.62,0.88,"CMS Preliminary");
  latex->SetNDC();
  latex->SetTextColor(kBlack);
  latex->SetTextFont(42);
  */
  
   yellowPlot->SaveAs("plots/Histo_QQ_rap.pdf"); 


}
