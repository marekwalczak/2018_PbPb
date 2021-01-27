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

//#include "/Users/marekwalczak/Data/2018PbPb/Onia_UPCtrig_1DM/ReadTree.C"
//#include "/Users/marekwalczak/Data/2018PbPb/Onia_UPCtrig_xDM_1/ReadTree.C"

//#include "/Users/marekwalczak/Data/2018PbPb/MC_gg_2M_xDM/ReadTree.C"
#include "/Users/marekwalczak/Data/2018PbPb/MC_gg_2M_xDM_official/ReadTree.C"

//#include "/Users/marekwalczak/Data/2018PbPb/MC_coh_1S_05M_xDM/ReadTree.C"
//#include "/Users/marekwalczak/Data/2018PbPb/MC_coh_1S_05M_xDM_official/ReadTree.C"

//#include "/Users/marekwalczak/Data/2018PbPb/MC_coh_2S_05M_xDM/ReadTree.C"
//#include "/Users/marekwalczak/Data/2018PbPb/MC_coh_2S_05M_xDM_official/ReadTree.C"

//#include "/Users/marekwalczak/Data/2018PbPb/MC_coh_3S_05M_xDM/ReadTree.C"
//#include "/Users/marekwalczak/Data/2018PbPb/MC_coh_3S_05M_xDM_official/ReadTree.C"

//#include "/Users/marekwalczak/Data/2018PbPb/MC_incoh_1S_05M_xDM/ReadTree.C"
//#include "/Users/marekwalczak/Data/2018PbPb/MC_incoh_1S_05M_xDM_official/ReadTree.C"

//#include "/Users/marekwalczak/Data/2018PbPb/MC_incoh_2S_05M_xDM/ReadTree.C"
//#include "/Users/marekwalczak/Data/2018PbPb/MC_incoh_2S_05M_xDM_official/ReadTree.C"

//#include "/Users/marekwalczak/Data/2018PbPb/MC_incoh_3S_05M_xDM/ReadTree.C"
//#include "/Users/marekwalczak/Data/2018PbPb/MC_incoh_3S_05M_xDM_official/ReadTree.C"

//#include "/Users/marekwalczak/Data/2018PbPb/pythia/ReadTree.C"





void analyze_muAcc(){

/*                       _    __ _ _      
*                       | |  / _(_) |     
*     _ __ ___  __ _  __| | | |_ _| | ___ 
*    | '__/ _ \/ _` |/ _` | |  _| | |/ _ \
*    | | |  __/ (_| | (_| | | | | | |  __/
*    |_|  \___|\__,_|\__,_| |_| |_|_|\___|
*                                         
*/                                        

  cout << endl << "******* opening files *******" << endl;
  
/********************* when changing the input file change the ReadTree.C file above ************************/
  
  bool isMC = true;




  // TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/Onia_UPCtrig_1DM/Onia_UPCtrig_1DM.root","read");
   //TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/Onia_UPCtrig_xDM_1/Onia_UPCtrig_xDM_1.root","read");

   //TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_gg_2M_xDM/MC_gg_2M_xDM.root","read");
   TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_gg_2M_xDM_official/MC_gg_2M_xDM_official.root","read");

  // TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_coh_1S_05M_xDM/MC_coh_1S_05M_xDM.root","read");
  // TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_coh_1S_05M_xDM_official/MC_coh_1S_05M_xDM_official.root","read");
   
   
   //TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_coh_2S_05M_xDM/MC_coh_2S_05M_xDM.root","read");
   //TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_coh_2S_05M_xDM_official/MC_coh_2S_05M_xDM_official.root","read");

   //TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_coh_3S_05M_xDM/MC_coh_3S_05M_xDM.root","read");
   //TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_coh_3S_05M_xDM_official/MC_coh_3S_05M_xDM_official.root","read");

   //TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_incoh_1S_05M_xDM/MC_incoh_1S_05M_xDM.root","read");
   //TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_incoh_1S_05M_xDM_official/MC_incoh_1S_05M_xDM_official.root","read");

   //TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_incoh_2S_05M_xDM/MC_incoh_2S_05M_xDM.root","read");
   //TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_incoh_2S_05M_xDM_official/MC_incoh_2S_05M_xDM_official.root","read");

   //TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_incoh_3S_05M_xDM/MC_incoh_3S_05M_xDM.root","read");   
   //TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/MC_incoh_3S_05M_xDM_official/MC_incoh_3S_05M_xDM_official.root","read");   

  // TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/pythia/Pythia_jpsi_200files.root","read");   
  
  
  
    //TTree* myTree_1 = (TTree*)file1->Get("myTree"); // some files don't have hionia folder....
    TTree* myTree_1 = (TTree*)file1->Get("hionia/myTree"); // use for MC and data
	ReadTree *tree = new ReadTree(myTree_1);

	Long64_t nentries = tree->fChain->GetEntries(); // get the entries from tree
	cout << endl << "nentries: " << nentries << endl;
 
 
 
/*        _           _                                  _       _     _           
*        | |         | |                                (_)     | |   | |          
*      __| | ___  ___| | __ _ _ __ ___  __   ____ _ _ __ _  __ _| |__ | | ___  ___ 
*     / _` |/ _ \/ __| |/ _` | '__/ _ \ \ \ / / _` | '__| |/ _` | '_ \| |/ _ \/ __|
*    | (_| |  __/ (__| | (_| | | |  __/  \ V / (_| | |  | | (_| | |_) | |  __/\__ \
*     \__,_|\___|\___|_|\__,_|_|  \___|   \_/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/
*                                                                                  
*/                                                                                 

    double pi  = 3.14159;

	double Gen_mu_pT;
	double Gen_mu_rap;
	double Gen_mumi_pT;
	double Gen_mumi_rap;
	
	double Gen_QQ_pT;
	double Gen_QQ_rap;
	double Gen_QQ_M;

	
	////Int_t Gen_mu_charge;
/////Int_t Gen_mumi_charge;

	double invmass;
	double QQ_rap;
	double QQ_pT;
	int nsize;
	int *QQ_Ntrk;
	Int_t Ntracks;
	int sign;
	
	ULong64_t QQ_trig;
	ULong64_t HLTrig;
	
	double QQ_vtx_z;
	double QQ_vtx_x;
	double QQ_vtx_y;
	double QQ_rap_Gen;
	double QQ_pT_Gen;
	double QQ_Phi;

	double mu_pT;
	double mu_rap;
	double mumi_pT;
	double mumi_rap;

   	double m_min = 9.0; // 
    double m_max = 11.0; //   
	
	
	double mu_Phi;
	double mumi_Phi;


	double aco;
	
	int evts=0;
	
	int mu_idx=-1;
	int mumi_idx=-1;

	int Gen_mu_idx=-1;
	int Gen_mumi_idx=-1;

	int Gen_mu_size=-1;
	int Reco_mu_size=-1;


    int Gen_mu_charge=0;
    int mu_charge=0;
    
    
    int Reco_co = 0;
    int Gen_co = 0;
    int Gen_Reco_co = 0;
    int Gen_mu_whichRec=0;
    int index_finder = 0;
    
    // trigger for muons
    int mu_trig;
    
    // soft mu ID
    bool TMOneStaTight_mu;
    bool TMOneStaTight_mumi;
    
    int nTrkWMea_mu=0;
    int nTrkWMea_mumi=0;
    
    int nPixWMea_mu=0;
    int nPixWMea_mumi=0;
    
    bool highPurity_mu;
    bool highPurity_mumi;
	     
	double dxy_mu=0;
	double dxy_mumi=0;
	
	double dz_mu=0;
	double dz_mumi=0;    

	
  // get branches
  Float_t HadEnergy_HF_Minus;
  myTree_1->SetBranchAddress("HadEnergy_HF_Minus", &HadEnergy_HF_Minus);
   
  Float_t HadEnergy_HF_Plus;
  myTree_1->SetBranchAddress("HadEnergy_HF_Plus", &HadEnergy_HF_Plus);
 
/*                        _         _     _     _            
*                        | |       | |   (_)   | |           
*      ___ _ __ ___  __ _| |_ ___  | |__  _ ___| |_ ___  ___ 
*     / __| '__/ _ \/ _` | __/ _ \ | '_ \| / __| __/ _ \/ __|
*    | (__| | |  __/ (_| | ||  __/ | | | | \__ \ || (_) \__ \
*     \___|_|  \___|\__,_|\__\___| |_| |_|_|___/\__\___/|___/
*                                                            
*/                                                           

  TH1F* histo_HF_energy_Min = new TH1F("histo_HF_energy_Min","HF-_LeadingTower_energy; HF-_LeadingTower_energy [GeV];events ",100,0,10);

  TH1F* histo_HF_energy_Pl = new TH1F("histo_HF_energy_Pl","HF+_LeadingTower_energy; HF+_LeadingTower_energy [GeV];events ",100,0,10);

  TH2F* sp_HF = new TH2F("sp_HF","HF+ vs HF-; HF-_LeadingTower [GeV]; HF+_LeadingTower [GeV]",100,0,10,100,0,10);
  TH2F* sp_QQ_Ntrk_QQ_size = new TH2F("sp_QQ_Ntrk_QQ_size","QQ_size vs QQ_Ntrk; QQ_Ntrk; QQ_size",20,0,20,20,0,20);
  TH2F* sp_Ntracks_QQ_size = new TH2F("sp_Ntracks_QQ_size","QQ_size vs Ntracks; Ntracks; QQ_size",20,0,20,20,0,20);
  TH2F* sp_Ntracks_QQ_Ntrk = new TH2F("sp_Ntracks_QQ_Ntrk","QQ_Ntrk vs Ntracks; Ntracks; QQ_Ntrk",20,0,20,20,0,20);

  TH2F* sp_QQ_pT_QQ_rap = new TH2F("sp_QQ_pT_QQ_rap","QQ_pT vs QQ_rap; rapidity; pT",100,-10,10,100,0,4);
  TH2F* sp_QQ_pT_QQ_rap_Gen = new TH2F("sp_QQ_pT_QQ_rap_Gen","QQ_pT vs QQ_rap; rapidity; pT",100,-10,10,100,0,4);
  TH2F* sp_QQ_pT_QQ_rap_Reco_Gen = new TH2F("sp_QQ_pT_QQ_rap_Reco_Gen","QQ_pT vs QQ_rap; rapidity; pT",100,-10,10,100,0,4);
  TH2F* sp_QQ_pT_QQ_rap_Acc = new TH2F("sp_QQ_pT_QQ_rap_Acc","QQ_pT vs QQ_rap; rapidity; pT",100,-10,10,100,0,4);

  TH2F* sp_mu_pT_mu_rap = new TH2F("sp_mu_pT_mu_rap","mu_pT vs mu_rap; rapidity; pT",400,-10,10,200,0,10);
  TH2F* sp_mu_pT_mu_rap_Gen = new TH2F("sp_mu_pT_mu_rap_Gen","mu_pT vs mu_rap; rapidity; pT",400,-10,10,200,0,10);
  TH2F* sp_mu_pT_mu_rap_Reco_Gen = new TH2F("sp_mu_pT_mu_rap_Reco_Gen","mu_pT vs mu_rap; rapidity; pT",400,-10,10,200,0,10);
  TH2F* sp_mu_pT_mu_rap_Acc = new TH2F("sp_mu_pT_mu_rap_Acc","Acc: mu_pT vs mu_rap; rapidity; pT",400,-10,10,200,0,10);

  TH1F* histo_QQ_size = new TH1F("histo_QQ_size","QQ_size; QQ_size;events ",20,0,20);
  TH1F* histo_QQ_Ntrk = new TH1F("histo_QQ_Ntrk","QQ_Ntrk; QQ_Ntrk;events ",20,0,20);
  TH1F* histo_Ntracks = new TH1F("histo_Ntracks","Ntracks; Ntracks;events ",20,0,20);

  TH1F* histo_QQ_M = new TH1F("histo_QQ_M","Mass; Mass; events",100,8,12);

  TH1F* histo_QQ_pT = new TH1F("histo_QQ_pT","QQ_pT; QQ_pT [GeV]; events ",100,0,4);
  TH1F* histo_QQ_pT_Gen = new TH1F("histo_QQ_pT_Gen","QQ_pT; QQ_pT [GeV]; events ",100,0,4);
  TH1F* histo_QQ_pT_Reco_Gen = new TH1F("histo_QQ_pT_Reco_Gen","QQ_pT; QQ_pT [GeV]; events ",100,0,4);
  TH1F* histo_QQ_pT_Acc = new TH1F("histo_QQ_pT_Acc","QQ_pT; QQ_pT [GeV]; events ",100,0,4);
  TH1F* histo_QQ_pT2 = new TH1F("histo_QQ_pT2","QQ_pT2; QQ_pT2 [GeV^[2]]; events ",200,0,10);

  TH1F* histo_QQ_rap = new TH1F("histo_QQ_rap","QQ_rap; QQ_rap; events ",100,-10,10);
  TH1F* histo_QQ_rap_Gen = new TH1F("histo_QQ_rap_Gen","QQ_rap_Gen; QQ_rap_Gen; events ",100,-10,10);
  TH1F* histo_QQ_rap_Reco_Gen = new TH1F("histo_QQ_rap_Reco_Gen","QQ_rap_Gen; QQ_rap_Gen; events ",100,-10,10);
  TH1F* histo_QQ_rap_Acc = new TH1F("histo_QQ_rap_Acc","QQ_rap_Acc; QQ_rap_Acc; events ",100,-10,10);
  
  TH1F* histo_QQ_vtx_z = new TH1F("histo_QQ_vtx_z","QQ_vtx_z; QQ_vtx_z; events ",100,-50,50);
  TH1F* histo_QQ_Phi = new TH1F("histo_QQ_Phi","QQ_Phi; QQ_Phi; events ",100,-4,4);


  TH1F* histo_mu_pT = new TH1F("histo_mu_pT","mu_pT; mu_pT [GeV]; muons ",200,0,10);
  TH1F* histo_mu_pT_Gen = new TH1F("histo_mu_pT_Gen","mu_pT; mu_pT [GeV]; muons ",200,0,10);
  TH1F* histo_mu_pT_Reco_Gen = new TH1F("histo_mu_pT_Reco_Gen","mu_pT; mu_pT [GeV]; muons ",200,0,10);
  TH1F* histo_mu_pT_Acc = new TH1F("histo_mu_pT_Acc","mu_pT; mu_pT [GeV]; muons ",200,0,10);
  
  TH1F* histo_mu_rap = new TH1F("histo_mu_rap","mu_rap; mu_rap; muons ",100,-10,10);
  TH1F* histo_mu_rap_Gen = new TH1F("histo_mu_rap_Gen","mu_rap; mu_rap; muons ",100,-10,10);
  TH1F* histo_mu_rap_Reco_Gen = new TH1F("histo_mu_rap_Reco_Gen","mu_rap; mu_rap; muons ",100,-10,10);
  TH1F* histo_mu_rap_Acc = new TH1F("histo_mu_rap_Acc","mu_rap; mu_rap; muons ",100,-10,10);
  
  TH1F* histo_mu_Phi = new TH1F("histo_mu_Phi","mu_Phi; mu_Phi; events ",100,-4,4);

  TH1F* histo_aco = new TH1F("histo_aco", "histo_aco; acoplanarity; events", 110, 0.0, 1.1);

  TH1F* histo_QQ_trig = new TH1F("histo_QQ_trig", "histo_QQ_trig; Reco_Q_trig; events", 10, 0.0, 10);
  TH1F* histo_HLTrig = new TH1F("histo_HLTrig", "histo_HLTrig; HLTrig; events", 10, 0.0, 10);
  TH2F* sp_QQ_trig_HLTrig = new TH2F("sp_QQ_trig_HLTrig","Reco_QQ_trig vs HLTrig; HLTrig; Reco_QQ_trig", 10, 0, 10, 10, 0, 10);





  ofstream textfile;
  system("rm -r plots");
  system("mkdir plots");
  system("cp analyze_muAcc.c plots/");
  
	int Ntrk_count=0;
	int QQ_size_count=0;
	int Ntracks_count=0;
 
 
 
   TString dirname = "muAcc_gg_TRG_corrected_acctest/";

 
  
	cout << endl << "******* filling the histos *******" << endl << endl;

/*                     _        _             _                   
*                     | |      (_)           | |                  
*     _ __   ___ _ __ | |_ _ __ _  ___  ___  | | ___   ___  _ __  
*    | '_ \ / _ \ '_ \| __| '__| |/ _ \/ __| | |/ _ \ / _ \| '_ \ 
*    | | | |  __/ | | | |_| |  | |  __/\__ \ | | (_) | (_) | |_) |
*    |_| |_|\___|_| |_|\__|_|  |_|\___||___/ |_|\___/ \___/| .__/ 
*                                                          | |    
* 		                                                   |_|    
*/ 
                 
                 
                 
                                        

  //for (Long64_t i=0; i<100; i++) {
  for (Long64_t i=0; i<nentries; i++) {
  //if (i==14771) break;
     myTree_1->GetEntry(i);

		Long64_t ientry = tree->LoadTree(i); // ...
		if (ientry < 0) break; // ...
  			if (i%10000==0) cout << "-> Processing event # " << i << endl;




/***
 *     _____              _       _   _                   
 *    |  __ \            | |     | | | |                  
 *    | |  \/ ___ _ __   | |_   _| | | | ___   ___  _ __  
 *    | | __ / _ \ '_ \  | \ \ / / | | |/ _ \ / _ \| '_ \ 
 *    | |_\ \  __/ | | | | |\ V /| | | | (_) | (_) | |_) |
 *     \____/\___|_| |_| |_| \_/ |_| |_|\___/ \___/| .__/ 
 *                                                 | |    
 *                                                 |_|    
 */ 
 
 //        Gen Lvl STUFF:

		  Gen_mu_size = tree->Gen_mu_size;
          for (int G_mu=0; G_mu<Gen_mu_size; G_mu++) { // loops over Gen muons		
		  		  
		    TLorentzVector *Gen_mu_4mom = (TLorentzVector*)tree->Gen_mu_4mom->At(G_mu);
     	  	Gen_mu_pT = Gen_mu_4mom->Pt();
			Gen_mu_rap = Gen_mu_4mom->Rapidity();
			
            histo_mu_pT_Gen->Fill(Gen_mu_pT);
            histo_mu_rap_Gen->Fill(Gen_mu_rap);
            sp_mu_pT_mu_rap_Gen->Fill(Gen_mu_rap, Gen_mu_pT);
 }
 
 
 
 
 
/***
 *    ______                 _       _   _                   
 *    | ___ \               | |     | | | |                  
 *    | |_/ /___  ___ ___   | |_   _| | | | ___   ___  _ __  
 *    |    // _ \/ __/ _ \  | \ \ / / | | |/ _ \ / _ \| '_ \ 
 *    | |\ \  __/ (_| (_) | | |\ V /| | | | (_) | (_) | |_) |
 *    \_| \_\___|\___\___/  |_| \_/ |_| |_|\___/ \___/| .__/ 
 *                                                    | |    
 *                                                    |_|    
 */

 
	Reco_mu_size  = tree->Reco_mu_size; //get the size
        
	if (Reco_mu_size==0) continue;

	HLTrig = tree->HLTriggers;

    for (int Reco_mu=0; Reco_mu<Reco_mu_size; Reco_mu++) { // loops over all Reco muons		


     	  TLorentzVector *mu_4mom = (TLorentzVector*)tree->Reco_mu_4mom->At(Reco_mu);

     	  	mu_pT = mu_4mom->Pt();
			mu_rap = mu_4mom->Rapidity();
	

/*                         _              _           _   _             
*                         | |            | |         | | (_)            
*      _____   _____ _ __ | |_   ___  ___| | ___  ___| |_ _  ___  _ __  
*     / _ \ \ / / _ \ '_ \| __| / __|/ _ \ |/ _ \/ __| __| |/ _ \| '_ \ 
*    |  __/\ V /  __/ | | | |_  \__ \  __/ |  __/ (__| |_| | (_) | | | |
*     \___| \_/ \___|_| |_|\__| |___/\___|_|\___|\___|\__|_|\___/|_| |_|
*                                                                       
*/                                                                       


//       TRIGGER SELECTION:
//       ((HLTrig&1)==1)   1 - HLT_HIUPC_DoubleMu0_NotMBHF2AND_MaxPixelTrack_v1
//       ((HLTrig&2)==2)   2 - HLT_HIUPC_DoubleMu0_NotMBHF2AND_v1
//       ((HLTrig&4)==4)   3 - HLT_HIUPC_SingleMu0_NotMBHF2AND_MaxPixelTrack_v1
//       ((HLTrig&8)==8)   4 - HLT_HIUPC_SingleMu0_NotMBHF2AND_v1
//       ((HLTrig&16)==16) 5 - HLT_HIUPC_SingleMuOpen_NotMBHF2AND_MaxPixelTrack_v1
//       ((HLTrig&32)==32) 6 - HLT_HIUPC_SingleMuOpen_NotMBHF2AND_v1


          mu_trig = tree->Reco_mu_trig[Reco_mu];


// // mu_rap > -2.4 && mu_rap < 2.4  && //  
   if ( 1==1 ){ // ((mu_trig&32)==32) 
          
          // soft mu ID
          TMOneStaTight_mu = tree->Reco_mu_TMOneStaTight[Reco_mu];
          nTrkWMea_mu = tree->Reco_mu_nTrkWMea[Reco_mu];
          nPixWMea_mu = tree->Reco_mu_nPixWMea[Reco_mu];
          highPurity_mu = tree->Reco_mu_highPurity[Reco_mu];
          dxy_mu = abs(tree->Reco_mu_dxy[Reco_mu]);
          dz_mu = abs(tree->Reco_mu_dz[Reco_mu]);
          
          if ( (TMOneStaTight_mu>0 && nTrkWMea_mu>5 && nPixWMea_mu>0 && highPurity_mu==true && dxy_mu<0.3 && dz_mu<20) ){

             histo_mu_pT->Fill(mu_pT);
             histo_mu_rap->Fill(mu_rap);
             sp_mu_pT_mu_rap->Fill(mu_rap, mu_pT);

     	  	 mu_charge = tree->Reco_mu_charge[Reco_mu];

             Gen_Reco_co = 0;
             for (int G_mu=0; G_mu<Gen_mu_size; G_mu++) { // loops over Gen muons	
                
                Gen_mu_whichRec = tree->Gen_mu_whichRec[G_mu];
                if ( Gen_mu_whichRec!=Reco_mu) continue;
                
                Gen_mu_charge = tree->Gen_mu_charge[G_mu];
                if ( Gen_mu_charge!=mu_charge) cout << "             ->  charges different !!!!" << ", Gen_mu_pT: " << Gen_mu_pT << ", Gen_mu_rap: " << Gen_mu_rap << ", mu_pT: " << mu_pT << ", mu_rap: " << mu_rap << endl;

		        TLorentzVector *Gen_mu_4mom = (TLorentzVector*)tree->Gen_mu_4mom->At(G_mu);
     	  	    Gen_mu_pT = Gen_mu_4mom->Pt();
			    Gen_mu_rap = Gen_mu_4mom->Rapidity();
			    
                Gen_Reco_co++;

// SOFT ID acceptance test
/*
                if  ( ! ( (abs(Gen_mu_rap) < 2.4)    &&  ( ( Gen_mu_pT > 3.3)     ||  ( (Gen_mu_pT > (-4.0*abs(Gen_mu_rap) + 7.3)) && (Gen_mu_pT > 2.1) )    ||  ( (abs(Gen_mu_rap) > 1.3) && (Gen_mu_pT < 2.1) && (Gen_mu_pT > 1.53))  ||  ( (Gen_mu_pT > (-1.325*abs(Gen_mu_rap) + 3.2525)) &&  (Gen_mu_pT > 1.0) && (Gen_mu_pT <= 1.53) )  )   ) ) { 
                    break;
                     }


// TRG acceptance test
/*
                if  ( ! ( (abs(Gen_mu_rap) < 2.4)    &&  ( (Gen_mu_pT > 3.45) || (abs(Gen_mu_rap)>0.3 &&  abs(Gen_mu_rap)<1.1 &&  Gen_mu_pT>3.3 )    ||  ( (Gen_mu_pT > ((-1.15/0.35)*abs(Gen_mu_rap) + 6.91429)) && (Gen_mu_pT > 2.15) )    ||  ( (abs(Gen_mu_rap) > 1.45) && (abs(Gen_mu_rap) < 1.65) && (Gen_mu_pT > 2.15))  ||  ( (Gen_mu_pT > ((-0.95/0.45)*abs(Gen_mu_rap) + 5.63333)) &&  (Gen_mu_pT > 1.2) && (Gen_mu_pT <= 2.15) )  )   ) ) { 
                    break;
                     }
*/


                histo_mu_pT_Reco_Gen->Fill(Gen_mu_pT);
                histo_mu_rap_Reco_Gen->Fill(Gen_mu_rap);
                sp_mu_pT_mu_rap_Reco_Gen->Fill(Gen_mu_rap, Gen_mu_pT);
                break;
            }//  Gen muon loop
                
            if (Gen_Reco_co==0) cout << "             ->  no Gen muon found " << ", Gen_mu_pT: " << Gen_mu_pT << ", Gen_mu_rap: " << Gen_mu_rap << ", mu_pT: " << mu_pT << ", mu_rap: " << mu_rap << endl;
            if (Gen_Reco_co>1) cout << "             ->  more then one Gen muon found " << ", Gen_mu_pT: " << Gen_mu_pT << ", Gen_mu_rap: " << Gen_mu_rap << ", mu_pT: " << mu_pT << ", mu_rap: " << mu_rap << endl;
            
      } // soft
             } // acceptance and trigger
             } // Reco muon loop
             } // nentries loop


/*                          _     _     _                                      
*                          | |   (_)   | |                                     
*     ___  __ ___   _____  | |__  _ ___| |_ ___   __ _ _ __ __ _ _ __ ___  ___ 
*    / __|/ _` \ \ / / _ \ | '_ \| / __| __/ _ \ / _` | '__/ _` | '_ ` _ \/ __|
*    \__ \ (_| |\ V /  __/ | | | | \__ \ || (_) | (_| | | | (_| | | | | | \__ \
*    |___/\__,_| \_/ \___| |_| |_|_|___/\__\___/ \__, |_|  \__,_|_| |_| |_|___/
*                                                 __/ |                        
*                                                |___/                         
*/

  cout << endl << "******* opening output file and saving histos *******" << endl;

  //system("mkdir plots");
  TFile* outFile = new TFile("plots/plots.root","RECREATE");
  

    histo_mu_pT_Acc->Divide(histo_mu_pT_Reco_Gen, histo_mu_pT_Gen, 1, 1);
    histo_mu_rap_Acc->Divide(histo_mu_rap_Reco_Gen, histo_mu_rap_Gen, 1, 1);
    sp_mu_pT_mu_rap_Acc->Divide(sp_mu_pT_mu_rap_Reco_Gen, sp_mu_pT_mu_rap_Gen, 1, 1);

    histo_mu_pT->Write();
    histo_mu_pT_Gen->Write();
    histo_mu_pT_Reco_Gen->Write();
    histo_mu_pT_Acc->Write();

    histo_mu_rap->Write();
    histo_mu_rap_Gen->Write();
    histo_mu_rap_Reco_Gen->Write();
    histo_mu_rap_Acc->Write();

    sp_mu_pT_mu_rap->Write();
    sp_mu_pT_mu_rap_Gen->Write();
    sp_mu_pT_mu_rap_Reco_Gen->Write();
    sp_mu_pT_mu_rap_Acc->Write();

    outFile->Close();
          
    textfile.close();
   
/*
 *                          _                         _                               _       _       
 *                         | |                       | |                             | |     | |      
 *       ___ _ __ ___  __ _| |_ ___    __ _ _ __   __| |  ___  __ ___   _____   _ __ | | ___ | |_ ___ 
 *      / __| '__/ _ \/ _` | __/ _ \  / _` | '_ \ / _` | / __|/ _` \ \ / / _ \ | '_ \| |/ _ \| __/ __|
 *     | (__| | |  __/ (_| | ||  __/ | (_| | | | | (_| | \__ \ (_| |\ V /  __/ | |_) | | (_) | |_\__ \
 *      \___|_|  \___|\__,_|\__\___|  \__,_|_| |_|\__,_| |___/\__,_| \_/ \___| | .__/|_|\___/ \__|___/
 *                                                                             | |                    
 *                                                                             |_|                    
 */   
 
 system("root -l -b -q draw_muAcc.c");
 system("root -l -b -q draw_muAcc_profile.c");

   system("rm -r " + dirname);
   system("mv plots " + dirname);
      
  cout << endl << "******* finished and saved *******" << endl;

   return 0;
   
   }
