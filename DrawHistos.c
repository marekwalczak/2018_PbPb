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

void DrawHistos() {

  cout << endl << "******* running scripts *******" << endl;


   system("root -l -b -q DrawHisto_QQ_m.c");
   system("root -l -b -q DrawHisto_QQ_pT.c");
   system("root -l -b -q DrawHisto_QQ_rap.c");
   system("root -l -b -q DrawHisto_mu_pT.c");
   system("root -l -b -q DrawHisto_mu_rap.c");
        
      
  cout << endl << "******* finished *******" << endl;

   return 0;
   
  }

