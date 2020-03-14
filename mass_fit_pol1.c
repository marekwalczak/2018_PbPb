#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
//#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooAbsReal.h"
#include "RooPlot.h"
#include "TCanvas.h"
#include "TAxis.h"
using namespace RooFit ;
void setTDRStyle() {
  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

  // For the canvas * * * * *

  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); //Height of canvas
  tdrStyle->SetCanvasDefW(600); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);

  // For the Pad * * * * *

  tdrStyle->SetPadBorderMode(0);
  // tdrStyle->SetPadBorderSize(Width_t size = 1);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

  // For the frame * * * * *

  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(3);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);

  // For the histo * * * * *

  // tdrStyle->SetHistFillColor(1);
  // tdrStyle->SetHistFillStyle(0);
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(1);
  // tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
  // tdrStyle->SetNumberContours(Int_t number = 20);

  tdrStyle->SetEndErrorSize(2);
  //tdrStyle->SetErrorMarker(20);
  tdrStyle->SetErrorX(0.);
  
  tdrStyle->SetMarkerStyle(20);

  //For the fit/function * * * * *

  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(2);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

  //For the date * * * * *

  tdrStyle->SetOptDate(0);
  // tdrStyle->SetDateX(Float_t x = 0.01);
  // tdrStyle->SetDateY(Float_t y = 0.01);

  // For the statistics box * * * * *

  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.01);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(0);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.15);
  // tdrStyle->SetStatStyle(Style_t style = 1001);
  // tdrStyle->SetStatX(Float_t x = 0);
  // tdrStyle->SetStatY(Float_t y = 0);

  // Margins * * * * *

  tdrStyle->SetPadTopMargin(0.05);
  tdrStyle->SetPadBottomMargin(0.13);
  tdrStyle->SetPadLeftMargin(0.13);
  tdrStyle->SetPadRightMargin(0.05);

  // For the Global title * * * * *

  tdrStyle->SetOptTitle(0); // REMOVED
  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);
  // tdrStyle->SetTitleH(0); // Set the height of the title box
  // tdrStyle->SetTitleW(0); // Set the width of the title box
  // tdrStyle->SetTitleX(0); // Set the position of the title box
  // tdrStyle->SetTitleY(0.985); // Set the position of the title box
  // tdrStyle->SetTitleStyle(Style_t style = 1001);
  // tdrStyle->SetTitleBorderSize(2);

  // For the axis titles * * * * *

  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // tdrStyle->SetTitleYSize(Float_t size = 0.02);
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(0.7);
  // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

  // For the axis labels * * * * *

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.04, "XYZ");

  // For the axis * * * * *

  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

  // Change for log plots * * * * *

  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

  // Postscript options:
  // tdrStyle->SetPaperSize(15.,15.);
  // tdrStyle->SetLineScalePS(Float_t scale = 3);
  // tdrStyle->SetLineStyleString(Int_t i, const char* text);
  // tdrStyle->SetHeaderPS(const char* header);
  // tdrStyle->SetTitlePS(const char* pstitle);

  // tdrStyle->SetBarOffset(Float_t baroff = 0.5);
  // tdrStyle->SetBarWidth(Float_t barwidth = 0.5);
  // tdrStyle->SetPaintTextFormat(const char* format = "g");
  // tdrStyle->SetPalette(Int_t ncolors = 0, Int_t* colors = 0);
  // tdrStyle->SetTimeOffset(Double_t toffset);
  // tdrStyle->SetHistMinimumZero(kTRUE);

  // personnal additions * * * * *
  tdrStyle->cd();

}


void mass_fit_pol1(const float hbcut=2.0, const float ptcut=1.00)
{

  setTDRStyle();
  gROOT->LoadMacro("CMS_lumi.C"); 
  //writeExtraText= false;
  gStyle->SetStatFormat("5.2g");
  gStyle->SetFitFormat("5.2g");

 TString flatfile="mass_fit/m_trig1.txt";
// TString flatfile="m_trig4.txt";
 //  TString flatfile="data_pos_8-12.txt";



  RooRealVar* mMuMu = new RooRealVar("mMuMu","#mu^{+}#mu^{-} mass",8,12,"GeV");
  RooRealVar* mMuMuFull = new RooRealVar("mMuMuFull","Dimuon mass",8,12,"GeV");
  
  // fit to the background * * * * *

//    RooRealVar* mdimucoef1 = new RooRealVar("dimuon p0","dimuon p0",0.0,-50000.0,50000.0);
//  RooRealVar* mdimucoef1 = new RooRealVar("dimuon p0","dimuon p0",-0.0562);//fix freom MC
  RooRealVar* mdimucoef1 = new RooRealVar("dimuon p0","dimuon p0", 0.0, -1.0, 1.0); // 
  RooRealVar* mdimucoef2 = new RooRealVar("dimuon p1","dimuon p1", 0.0,-20000.0,20000.0); // 
  //  RooRealVar* mdimucoef2 = new RooRealVar("dimuon p1","dimuon p1",-2.832);
  RooRealVar* mdimucoef3 = new RooRealVar("dimuon p2","dimuon p2", 0.0,-30000.0,30000.0);

  RooRealVar* cbcoefalpha = new RooRealVar("Crystal Ball alpha","Crystal Ball alpha",1.,0.,5.);
  RooRealVar* cbcoefn = new RooRealVar("Crystal Ball n","Crystal Ball n",1.,0.,10.);

  // fit to the upsilon resonances * * * * *

   RooRealVar* ups1smdimucoef1 = new RooRealVar("Upsilon(1S) mass","Upsilon(1S) mass", 9.0, 9.9);
//    RooRealVar* ups1smdimucoef1 = new RooRealVar("Upsilon(1S) mass","Upsilon(1S) mass",9.452);//MC fixed
//   RooRealVar* ups1smdimucoef1 = new RooRealVar("Upsilon(1S) mass","Upsilon(1S) mass",9.46);//PDG fixed
//   RooRealVar* ups1smdimucoef2 = new RooRealVar("Upsilon(1S) width","Upsilon(1S) width",0.095,0.0475,0.1425);
   RooRealVar* ups1smdimucoef2 = new RooRealVar("Upsilon(1S) width","Upsilon(1S) width", 0.05, 0.3);
//   RooRealVar* ups1smdimucoef2 = new RooRealVar("Upsilon(1S) width","Upsilon(1S) width",0.075,0.0375,0.1125);
// RooRealVar* ups1smdimucoef2 = new RooRealVar("Upsilon(1S) width","Upsilon(1S) width",0.15);


  RooRealVar* ups2smdimucoef1 = new RooRealVar("Upsilon(2S) mass","Upsilon(2S) mass",10.022);//MC fixed
//  RooRealVar* ups2smdimucoef1 = new RooRealVar("Upsilon(2S) mass","Upsilon(2S) mass",10.023);//PDG fixed
  //  RooRealVar* ups2smdimucoef1 = new RooRealVar("Upsilon(2S) mass","Upsilon(2S) mass",10.,9.8,10.2);
  RooRealVar* ups2smdimucoef2 = new RooRealVar("Upsilon(2S) width","Upsilon(2S) width",0.092);//from MC
  //  RooRealVar* ups2smdimucoef2 = new RooRealVar("Upsilon(2S) width","Upsilon(2S) width",0.1,0.01,1.0);
//  RooRealVar* ups3smdimucoef1 = new RooRealVar("Upsilon(3S) mass","Upsilon(3S) mass",10.35);//PDG value
  RooRealVar* ups3smdimucoef1 = new RooRealVar("Upsilon(3S) mass","Upsilon(3S) mass",10.351);//MC fixed value
  //  RooRealVar* ups3smdimucoef1 = new RooRealVar("Upsilon(3S) mass","Upsilon(3S) mass",10.4,10.2,10.5);
  RooRealVar* ups3smdimucoef2 = new RooRealVar("Upsilon(3S) width","Upsilon(3S) width",0.090);//MC fixed
  //  RooRealVar* ups3smdimucoef2 = new RooRealVar("Upsilon(3S) width","Upsilon(3S) width",0.1,0.01,1.0);


//    RooRealVar* nmm = new RooRealVar("N(dimuon events)","number of signal events",167.0);
//    RooRealVar* nmm = new RooRealVar("N(dimuon events)","number of signal events",103.0);
  RooRealVar* nmm = new RooRealVar("N(dimuon events)","number of signal events",28000.0,20000.0,1000000.0); 
  /*  RooRealVar* nu1s = new RooRealVar("N(Upsilon(1S))","number of Upsilon 1S",35.0); 
      RooRealVar* nu2s = new RooRealVar("N(Upsilon(2S))","number of Upsilon 2S",17.0);
      RooRealVar* nu3s = new RooRealVar("N(Upsilon(3S))","number of Upsilon 3S",12.0);*/
  RooRealVar* nu1s = new RooRealVar("N(Upsilon(1S))","number of Upsilon 1S", 900.0 ,400.0,1200.0);
  RooRealVar* nu2s = new RooRealVar("N(Upsilon(2S))","number of Upsilon 2S",500,0.0,1000.0);
  RooRealVar* nu3s = new RooRealVar("N(Upsilon(3S))","number of Upsilon 3S",300.0,0.0,1000.0);


  /*RooRealVar* nu1s = new RooRealVar("N(Upsilon(1S))","number of Upsilon 1S",50.0,0.0,1000.0); 
    RooRealVar* nu2s = new RooRealVar("N(Upsilon(2S))","number of Upsilon 2S",50.0,0.0,1000.0);
    RooRealVar* nu3s = new RooRealVar("N(Upsilon(3S))","number of Upsilon 3S",50.0,0.0,1000.0);*/

  // my attempt * * * * *
  RooRealVar* width2 = new RooRealVar("width2","ratio Upsilon(2S) mass", 1.0595);    // scale width 2s/1s mass
  RooRealVar* width3 = new RooRealVar("width3","ratio Upsilon(3S) mass", 1.0946);  // scale width 3s/1s mass
  RooFormulaVar width2s("width2s", "@0*@1", RooArgList(*ups1smdimucoef2, *width2));       // for 2s/1s ratio fix
  RooFormulaVar width3s("width3s", "@0*@1", RooArgList(*ups1smdimucoef2, *width3));     // for 3s/1s ratio fix
  // RooFormulaVar meanup3s("meanup3s", "@0*@1", RooArgList(*nu2s, *delm3));        // for 3s/2s ratio fix

  // my attempt width according to delta of mass* * * * *
  RooRealVar* delm2 = new RooRealVar("delm2","difference Upsilon(2S) mass",0.563);
  RooRealVar* delm3 = new RooRealVar("delm3","difference Upsilon(2S) mass",0.8952);
  RooFormulaVar meanup2s("meanup2s", "@0+@1", RooArgList(*ups1smdimucoef1, *delm2));
  RooFormulaVar meanup3s("meanup3s", "@0+@1", RooArgList(*ups1smdimucoef1, *delm3));

  // my attempt width according to ratio of mass* * * * *
  RooRealVar* ratiom2 = new RooRealVar("N2onN1S","ratio Upsilon(2S) mass",0.31,0.0,1.0);    // for 2s/1s ratio fix
  RooRealVar* ratiom3 = new RooRealVar("N3onN1S","ratio Upsilon(3S) mass",0.21,0.0,1.0);  // for 3s/1s ratio fix
  //  RooRealVar* delm3 = new RooRealVar("delm3","ratio Upsilon(3S) mass",0.79);    // for 3s/2s ratio fix
  RooFormulaVar up2sto1s("up2sto1s", "@0*@1", RooArgList(*nu1s, *ratiom2));       // for 2s/1s ratio fix
  RooFormulaVar up3sto1s("up3sto1s", "@0*@1", RooArgList(*nu1s, *ratiom3));     // for 3s/1s ratio fix
  // RooFormulaVar meanup3s("meanup3s", "@0*@1", RooArgList(*nu2s, *delm3));        // for 3s/2s ratio fix
  // fitting background with jjhollar's function * * * * *

  //RooPolynomial* mm = new RooPolynomial("mm shape","mm shape", *mMuMu, RooArgList(*mdimucoef1, *mdimucoef2),2);

  RooGaussian* ups1 = new RooGaussian("ups1s sigpeak","ups1s sigpeak", *mMuMu,*ups1smdimucoef1,*ups1smdimucoef2);
//  RooGaussian* ups2 = new RooGaussian("ups2s sigpeak","ups2s sigpeak", *mMuMu,*ups2smdimucoef1,*ups2smdimucoef2);
//  RooGaussian* ups3 = new RooGaussian("ups3s sigpeak","ups3s sigpeak", *mMuMu,*ups3smdimucoef1,*ups3smdimucoef2);
//  RooGaussian* ups2 = new RooGaussian("ups2s sigpeak","ups2s sigpeak", *mMuMu,*ups2smdimucoef1,width2s);//scale width
//  RooGaussian* ups3 = new RooGaussian("ups3s sigpeak","ups3s sigpeak", *mMuMu,*ups3smdimucoef1,width3s);//scale width
  RooGaussian* ups2 = new RooGaussian("ups2s sigpeak","ups2s sigpeak", *mMuMu,meanup2s,width2s);// width and mass free
  RooGaussian* ups3 = new RooGaussian("ups3s sigpeak","ups3s sigpeak", *mMuMu,meanup3s,width3s);//width and mass free

  //  RooCBShape* ups1 = new RooCBShape("ups1s sigpeak","ups1s sigpeak", *mMuMu,*ups1smdimucoef1,*ups1smdimucoef2,*cbcoefalpha,*cbcoefn);
  //  RooCBShape* ups2 = new RooCBShape("ups2s sigpeak","ups2s sigpeak", *mMuMu,*ups2smdimucoef1,*ups2smdimucoef2,*cbcoefalpha,*cbcoefn);
  // RooCBShape* ups3 = new RooCBShape("ups3s sigpeak","ups3s sigpeak", *mMuMu,*ups3smdimucoef1,*ups3smdimucoef2,*cbcoefalpha,*cbcoefn);

  // my fitting function * * * * *

   
  //  RooPolynomial* mm = new RooPolynomial("mm shape","mm shape", *mMuMu, RooArgList(*mdimucoef1, *mdimucoef2));
  // RooChebychev* mm = new RooChebychev("mm shape","mm shape", *mMuMu, RooArgList(*mdimucoef1, *mdimucoef2));
  //  RooChebychev* mm = new RooChebychev("mm shape","mm shape", *mMuMu, RooArgList(*mdimucoef1, *mdimucoef2, *mdimucoef3));

    RooPolynomial mm("mm shape","mm shape", *mMuMu, RooArgList(*mdimucoef1));//, *mdimucoef2, *mdimucoef3));

   // --- Build polynomial background PDF ---
   // Define shape parameters
   RooRealVar poly_c1("poly_c1", "coefficient of x^1 term", 0.0, -1.0, 0.0); // 0.0, -10000.0, 10000.0
   RooRealVar poly_c2("poly_c2", "coefficient of x^2 term", 0.0, 0, 1.0); // 0.0, -10000.0, 10000.0
   // Define cubic polynomial PDF
   //RooPolynomial mm("background", "quadratic polynomial", *mMuMu, RooArgList(poly_c1, poly_c2) );


   RooRealVar lambda("lambda", "slope", -1.0, -500.0, 500.0);
  // RooExponential mm("expo", "exponential PDF", *mMuMu, lambda);



//    RooAddPdf* totshape = new RooAddPdf("totshape","total PDF",RooArgList(*mm),RooArgList(*nmm)); 
    RooAddPdf* totshape = new RooAddPdf("totshape","total PDF",RooArgList(*ups1,*ups2,*ups3,mm),RooArgList(*nu1s,*nu2s,*nu3s,*nmm));        //ratio free
// RooAddPdf* totshape = new RooAddPdf("totshape","total PDF",RooArgList(*ups1,*ups2,*mm),RooArgList(*nu1s,*nu2s,*nmm));        //yield variable
//    RooAddPdf* totshape = new RooAddPdf("totshape","total PDF",RooArgList(*ups1,*ups2,*mm),RooArgList(*nu1s,up2sto1s,*nmm));  //two peak
//    RooAddPdf* totshape = new RooAddPdf("totshape","total PDF",RooArgList(*ups1,*ups2,*ups3,*mm),RooArgList(*nu1s,up2sto1s,up3sto1s,*nmm));  //ratio variable
  //    RooAddPdf* totshape = new RooAddPdf("totshape","total PDF",RooArgList(*ups1,*ups2,*ups3,*mm),RooArgList(*nu1s,*nu2s,meanup3s,*nmm));    //3s/2s ratio fix

  RooDataSet *datatmp = 0;
  datatmp = RooDataSet::read(flatfile,RooArgList(*mMuMu));
  //datatmpfull = RooDataSet::read(flatfile,RooArgList(*mMuMuFull));

  
	
  //  RooDataHist *datatmpfull= new RooDataHist("data","dataset with x",*mMuMuFull,hh) ;

  //  RooFitResult* fitres = 0;
  //  fitres = totshape->fitTo(*datatmp,"er","","8,12");
  //  fitres = totshape->fitTo(*datatmp,"er");
  //  fitres->Print();
  
  RooFitResult *fitres = totshape->fitTo(*datatmp,RooFit::FitOptions("MHTER"));
  fitres->Print();
  //totshape->createIntegral(mMuMu);
  //mMuMu->setRange("signal",8,9.12);
  

 
  // drawing things * * * * *

  TCanvas *c = new TCanvas("Dilepton signal","Dilepton signal",1000,600);
  //  c->Divide(2,1);
  c->cd();
  RooPlot* xframe = mMuMu->frame() ;
  xframe->SetMaximum(15);
  //  xframe->GetYaxis()->SetTitle("Events/0.05 GeV");
  xframe->GetYaxis()->SetTitle("Events/0.08 GeV");
  datatmp->plotOn(xframe,RooFit::Binning(50));//for 0.05 binning
  //  totshape->plotOn(xframe);
  //  mm-plotOn(xframe,LineColor(kRed),LineStyle(kDashed));
  //  mm->plotOn(xframe);

  TLegend *leg1=new TLegend(0.7, 0.75, 0.95, 0.90);
  leg1->SetFillColor(0);
  leg1->SetBorderSize(0);
  leg1->SetFillStyle(0);
  leg1->SetTextFont(43);
  leg1->SetTextSize(24);
  //leg1->AddEntry(xframe->findObject("ups1"),"Y(nS) #rightarrow ","l");
  //leg1->AddEntry(xframe->findObject("mm"),"QED #gamma #gamma #rightarrow  #gamma #gamma","l");

  totshape->plotOn(xframe,RooFit::Components(*ups1),RooFit::LineColor(kRed),RooFit::LineStyle(kDashed),RooFit::LineWidth(1), RooFit::Name("upsilon1s"));
  totshape->plotOn(xframe,RooFit::Components(*ups2),RooFit::LineColor(kRed),RooFit::LineStyle(kDashed),RooFit::LineWidth(1));
  totshape->plotOn(xframe,RooFit::Components(*ups3),RooFit::LineColor(kRed),RooFit::LineStyle(kDashed),RooFit::LineWidth(1));
  totshape->plotOn(xframe,RooFit::Components(mm),RooFit::LineColor(kBlue),RooFit::LineStyle(kDashed),RooFit::Name("qed"));
  totshape->plotOn(xframe,RooFit::Name("model"),RooFit::Name("tot"));
  totshape->paramOn(xframe, Layout(0.15, 0.35, 0.7) ); // parameter box
  xframe->getAttText()->SetTextSize(0.022); // size of text in par box

  leg1->AddEntry(xframe->findObject("tot"),"Total ","l");
  leg1->AddEntry(xframe->findObject("upsilon1s"),"Y(nS) #rightarrow #mu^{+}#mu^{-}","l");
  leg1->AddEntry(xframe->findObject("qed"),"QED #gamma #gamma #rightarrow #mu^{+}#mu^{-}","l");

   //TPaveText *pt = new TPaveText(0.4996151,0.6804895,0.9491917,0.951049,"BRNDC");
   TPaveText *pt = new TPaveText(0.65,0.65,0.95,0.95,"BRNDC");
   pt->SetName("totshape_paramBox");
   pt->SetBorderSize(1);
   pt->SetFillColor(0);
   pt->SetTextAlign(12);
   pt->SetTextSize(0.04);
//   TText *text = pt->AddText("N(Upsilon(1S)) =  19.2 #pm 6.2");
//   text = pt->AddText("N(Upsilon(2S)) =  16.2 #pm 6.0");
//   text = pt->AddText("N(Upsilon(3S)) =  5.7 #pm 4.6");
//   text = pt->AddText("N(dimuon events) =  171 #pm 15");
   TText *text = pt->AddText("N(Y(1S)) =  20.2 #pm 6.7");
   text = pt->AddText("N(Y(2S)) =  15.7 #pm 6.1");
   text = pt->AddText("N(Y(3S)) =  6.5 #pm 4.9");
   text = pt->AddText("N(QED) =  170 #pm 17");
   text = pt->AddText("Y(1S) mass =  9.40 #pm 0.02");
   text = pt->AddText("Y(1S) width =  0.07 #pm 0.03");
//   pt->Draw();

  // printing the graphic * * * * *
  // Double_t chi2 = xframe->chiSquare(6);
  //TPaveLabel *t1 = new TPaveLabel(0.2,0.75,0.3,0.8,Form("#chi^{2}/ndf=%0.2f",chi2),"NDC");
  TPaveLabel *t1 = new TPaveLabel(0.1921241,0.8693957,0.2923628,0.920078,"#chi^{2}/ndf = 3.4/6","NDC");
  t1->SetFillColor(kWhite);
  t1->SetTextColor(kRed);
  t1->SetBorderSize(0);
  t1->SetTextSize(1.0);
  //xframe->addObject(t1);
 // xframe->addObject(pt);
  xframe->addObject(leg1);

  xframe->Draw() ;
  cout << "redrax axis"<<endl;

  gPad->RedrawAxis("g");

  double chi2 = xframe->chiSquare("model","data");
  cout<<"chi2/ndoff: "<<chi2<<endl;
  cout<<" Fit chi square/dof = "<<xframe->chiSquare(6)<<endl;
 
//  cout<<" Fit chi square/dof = "<<xframe->chiSquare(6)<<endl;
  cout<<"meanup2s:      "<<meanup2s.getVal()<<endl;
  cout<<"meanup3s:      "<<meanup3s.getVal()<<endl;
  cout<<"total shape:   "<<totshape->getVal()<<endl;

  RooRealVar x("x","x",8,12) ;
  RooArgSet nset(x);
  mMuMu->setRange("signal",9.12,10.64);
  //bool writeExtraText = true;
  // CMS_lumi(c, 1 ,1);
  RooAbsReal* intPdf = mm.createIntegral(*mMuMu,NormSet(*mMuMu),Range("signal")) ;
  //RooAbsReal* intPdf = mm->createIntegral(*mMuMu,Range("signal")) ;
  cout<<"integral:  "<<(nmm->getVal()*intPdf->getVal())<<endl;
  //c->SaveAs("datafit_pol1.gif");
  c->SaveAs("datafit_test.pdf");

}














