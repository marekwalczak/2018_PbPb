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




void analyze(){

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
  

  
  		   double mu_pT_cut_low = 0;
		   double mu_pT_cut_high = 100.0;
		   double QQ_pT_cut_low = 0.0;
		   double QQ_pT_cut_high = 100.0;
		   double m_cut_low = -9.2;
		   double m_cut_high = 999.7;
		   double aco_low = -1;
		   double aco_high = 10.075;
  
  
  bool isMC = true;
  TString dirname = "plots_Acceptance_mu0_noTrig/";



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

   //TFile* file1 = new TFile("/Users/marekwalczak/Data/2018PbPb/pythia/Pythia_jpsi_200files.root","read");   
  
  
  
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

	double Gen_mupl_pT;
	double Gen_mupl_rap;
	double Gen_mumi_pT;
	double Gen_mumi_rap;
	
	double Gen_QQ_pT;
	double Gen_QQ_rap;
	double Gen_QQ_M;

	
	Int_t Gen_mupl_charge;
	Int_t Gen_mumi_charge;

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

	double mupl_pT;
	double mupl_rap;
	double mumi_pT;
	double mumi_rap;

   	double m_min = 9.0; // 
    double m_max = 11.0; //   
	
	
	double mupl_Phi;
	double mumi_Phi;


	double aco;
	
	int evts=0;
	
	int mupl_idx=-1;
	int mumi_idx=-1;

	int Gen_mupl_idx=-1;
	int Gen_mumi_idx=-1;

    // soft mu ID
    bool TMOneStaTight_mupl;
    bool TMOneStaTight_mumi;
    
    int nTrkWMea_mupl=0;
    int nTrkWMea_mumi=0;
    
    int nPixWMea_mupl=0;
    int nPixWMea_mumi=0;
    
    bool highPurity_mupl;
    bool highPurity_mumi;
	     
	double dxy_mupl=0;
	double dxy_mumi=0;
	
	double dz_mupl=0;
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

  TH1F* histo_HF_energy_Min = new TH1F("histo_HF_energy_Min","HF-_LeadingTower_energy; HF-_LeadingTower_energy [GeV];events ",300,0,30);

  TH1F* histo_HF_energy_Pl = new TH1F("histo_HF_energy_Pl","HF+_LeadingTower_energy; HF+_LeadingTower_energy [GeV];events ",300,0,30);

  TH2F* sp_HF = new TH2F("sp_HF","HF+ vs HF-; HF-_LeadingTower [GeV]; HF+_LeadingTower [GeV]",300,0,30,300,0,30);
  TH2F* sp_QQ_Ntrk_QQ_size = new TH2F("sp_QQ_Ntrk_QQ_size","QQ_size vs QQ_Ntrk; QQ_Ntrk; QQ_size",20,0,20,20,0,20);
  TH2F* sp_Ntracks_QQ_size = new TH2F("sp_Ntracks_QQ_size","QQ_size vs Ntracks; Ntracks; QQ_size",20,0,20,20,0,20);
  TH2F* sp_Ntracks_QQ_Ntrk = new TH2F("sp_Ntracks_QQ_Ntrk","QQ_Ntrk vs Ntracks; Ntracks; QQ_Ntrk",20,0,20,20,0,20);

  TH2F* sp_HFm_QQ_pT = new TH2F("sp_HFm_QQ_pT","HF- vs QQ rap; QQ rap; HF-_LeadingTower [GeV]",300,0,30,300,0,30);
  TH2F* sp_HFp_QQ_pT = new TH2F("sp_HFp_QQ_pT","HF+ vs QQ rap; QQ rap; HF+_LeadingTower [GeV]",300,0,30,300,0,30);


  TH2F* sp_QQ_pT_QQ_rap = new TH2F("sp_QQ_pT_QQ_rap","QQ_pT vs QQ_rap; rapidity; pT",100,-10,10,200,0,8);
  TH2F* sp_QQ_pT_QQ_rap_Gen = new TH2F("sp_QQ_pT_QQ_rap_Gen","QQ_pT vs QQ_rap; rapidity; pT",100,-10,10,200,0,8);
  TH2F* sp_QQ_pT_QQ_rap_Reco_Gen = new TH2F("sp_QQ_pT_QQ_rap_Reco_Gen","QQ_pT vs QQ_rap; rapidity; pT",100,-10,10,200,0,8);
  TH2F* sp_QQ_pT_QQ_rap_Acc = new TH2F("sp_QQ_pT_QQ_rap_Acc","QQ_pT vs QQ_rap; rapidity; pT",100,-10,10,200,0,8);

  TH2F* sp_mu_pT_mu_rap = new TH2F("sp_mu_pT_mu_rap","mu_pT vs mu_rap; rapidity; pT",100,-10,10,200,0,10);
  TH2F* sp_mu_pT_mu_rap_Gen = new TH2F("sp_mu_pT_mu_rap_Gen","mu_pT vs mu_rap; rapidity; pT",100,-10,10,200,0,10);
  TH2F* sp_mu_pT_mu_rap_Reco_Gen = new TH2F("sp_mu_pT_mu_rap_Reco_Gen","mu_pT vs mu_rap; rapidity; pT",100,-10,10,200,0,10);
  TH2F* sp_mu_pT_mu_rap_Acc = new TH2F("sp_mu_pT_mu_rap_Acc","Acc: mu_pT vs mu_rap; rapidity; pT",100,-10,10,200,0,10);

  TH2F* sp_QQ_pT_Aco = new TH2F("sp_QQ_pT_Aco","dimuon pT vs Acoplanarity; Acoplanarity; dimuon pT",200,0.0,1.0,200,0,5);


  TH1F* histo_QQ_size = new TH1F("histo_QQ_size","QQ_size; QQ_size;events ",20,0,20);
  TH1F* histo_QQ_Ntrk = new TH1F("histo_QQ_Ntrk","QQ_Ntrk; QQ_Ntrk;events ",20,0,20);
  TH1F* histo_Ntracks = new TH1F("histo_Ntracks","Ntracks; Ntracks;events ",20,0,20);

  TH1F* histo_QQ_M = new TH1F("histo_QQ_M","Mass; Mass; events",100,8,12);

  TH1F* histo_QQ_pT = new TH1F("histo_QQ_pT","QQ_pT; QQ_pT [GeV]; events ",320,0,8);
  TH1F* histo_QQ_pT_Gen = new TH1F("histo_QQ_pT_Gen","QQ_pT; QQ_pT [GeV]; events ",320,0,8);
  TH1F* histo_QQ_pT_Reco_Gen = new TH1F("histo_QQ_pT_Reco_Gen","QQ_pT; QQ_pT [GeV]; events ",320,0,8);
  TH1F* histo_QQ_pT_Acc = new TH1F("histo_QQ_pT_Acc","QQ_pT; QQ_pT [GeV]; events ",320,0,8);
  TH1F* histo_QQ_pT2 = new TH1F("histo_QQ_pT2","QQ_pT2; QQ_pT2 [GeV^[2]]; events ",250,0,25);

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

  TH2F* sp_mupl_pT_mumi_pT = new TH2F("sp_mupl_pT_mumi_pT","sp_mupl_pT_mumi_pT; mupl_pT; mumi_pT",200,0,10,200,0,10);
  TH2F* sp_mupl_rap_mumi_rap = new TH2F("sp_mupl_rap_mumi_rap","sp_mupl_rap_mumi_rap; mupl_rap; mumi_rap",100,-5,5,100,-5,5);




  ofstream textfile;
  system("rm -r plots");
  system("mkdir plots");
  system("cp analyze.c plots/");
  textfile.open ("plots/m_pT_y.txt");
  
	int Ntrk_count=0;
	int QQ_size_count=0;
	int Ntracks_count=0;
  
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
                                        

  //for (Long64_t i=0; i<1000; i++) {
  for (Long64_t i=0; i<nentries; i++) {
  //if (i==14771) break;
     myTree_1->GetEntry(i);

		Long64_t ientry = tree->LoadTree(i); // ...
		if (ientry < 0) break; // ...
  			if (i%10000==0) cout << "-> Processing event # " << i << endl;


/*          OLD Gen Lvl STUFF:

            // assuming, that in MC on Gen level there is always one dimuon (what is true)
            if (isMC) {
            
			TLorentzVector *Gen_QQ_4mom = (TLorentzVector*)tree->Gen_QQ_4mom->At(0);
			TLorentzVector *Gen_mupl_4mom = (TLorentzVector*)tree->Gen_QQ_mupl_4mom->At(0);
			TLorentzVector *Gen_mumi_4mom = (TLorentzVector*)tree->Gen_QQ_mumi_4mom->At(0);

			QQ_rap_Gen = Gen_QQ_4mom->Rapidity();
			QQ_pT_Gen = Gen_QQ_4mom->Pt();
			
			mupl_pT_Gen = Gen_mupl_4mom->Pt();
			mupl_rap_Gen = Gen_mupl_4mom->Rapidity();
			mumi_pT_Gen = Gen_mumi_4mom->Pt();
			mumi_rap_Gen = Gen_mumi_4mom->Rapidity();


            histo_QQ_pT_Gen->Fill(QQ_pT_Gen);
            histo_QQ_rap_Gen->Fill(QQ_rap_Gen);
            sp_QQ_pT_QQ_rap_Gen->Fill(QQ_rap_Gen, QQ_pT_Gen);
            histo_mu_rap_Gen->Fill(mupl_rap_Gen);
            histo_mu_rap_Gen->Fill(mumi_rap_Gen);
            sp_mu_pT_mu_rap_Gen->Fill(mumi_rap_Gen, mumi_pT_Gen);
            sp_mu_pT_mu_rap_Gen->Fill(mupl_rap_Gen, mupl_pT_Gen);
            
            }

*/

//          New Gen Lvl STUFF:

            // assuming, that in MC on Gen level there is always one dimuon (what is true)
        if (isMC) {
		


		  if (tree->Gen_mu_charge[0]==1) {
		  mupl_idx = 0;
		  mumi_idx = 1;
		  
		  } else if (tree->Gen_mu_charge[0]==-1) {
		  mupl_idx = 1;
		  mumi_idx = 0;
		  
		  } else cout << endl << "-> something is wrong with the Gen lvl charges!" << endl;
		  
		  		  
		  TLorentzVector *Gen_mupl_4mom = (TLorentzVector*)tree->Gen_mu_4mom->At(mupl_idx);
     	  TLorentzVector *Gen_mumi_4mom = (TLorentzVector*)tree->Gen_mu_4mom->At(mumi_idx);

     	  	Gen_mupl_pT = Gen_mupl_4mom->Pt();
			Gen_mupl_rap = Gen_mupl_4mom->Rapidity();
			Gen_mumi_pT = Gen_mumi_4mom->Pt();
			Gen_mumi_rap = Gen_mumi_4mom->Rapidity();
			Gen_mupl_charge = tree->Gen_mu_charge[mupl_idx];
			Gen_mumi_charge = tree->Gen_mu_charge[mumi_idx];
		  
		  //if (i%10000==0) cout << "Gen_mupl_charge: " << Gen_mupl_charge << ", Gen_mumi_charge: " << Gen_mumi_charge << endl;
		  //if (i%10000==0) cout << "Gen_mupl_pT: "  << Gen_mupl_pT << ", Gen_mumi_pT: " << Gen_mumi_pT << endl;     	  
		  //if (i%10000==0) cout << "Gen_mupl_rap: "  << Gen_mupl_rap << ", Gen_mumi_rap: " << Gen_mumi_rap << endl;     	  

		  TLorentzVector Gen_QQ_4mom = *Gen_mupl_4mom + *Gen_mumi_4mom;
		  
		  Gen_QQ_rap = Gen_QQ_4mom.Rapidity();
		  //if (i%1000==0) cout << "Gen_QQ_Eta: "  << Gen_QQ_Eta << endl;
		  Gen_QQ_pT = Gen_QQ_4mom.Pt();
		  //if (i%10000==0) cout << "Gen_QQ_pT: "  << Gen_QQ_pT << endl;
		  Gen_QQ_M = Gen_QQ_4mom.M();
		  //if (i%10000==0) cout << "Gen_QQ_M: "  << Gen_QQ_M << endl;     	  

            histo_QQ_pT_Gen->Fill(Gen_QQ_pT);
            histo_QQ_rap_Gen->Fill(Gen_QQ_rap);
            sp_QQ_pT_QQ_rap_Gen->Fill(Gen_QQ_rap, Gen_QQ_pT);
            histo_mu_rap_Gen->Fill(Gen_mupl_rap);
            histo_mu_rap_Gen->Fill(Gen_mumi_rap);
            histo_mu_pT_Gen->Fill(Gen_mupl_pT);
            histo_mu_pT_Gen->Fill(Gen_mumi_pT);
            sp_mu_pT_mu_rap_Gen->Fill(Gen_mumi_rap, Gen_mumi_pT);
            sp_mu_pT_mu_rap_Gen->Fill(Gen_mupl_rap, Gen_mupl_pT);

        } // is MC

/*		
*         _ _                               _                   
*        | (_)                             | |                  
*      __| |_ _ __ ___  _   _  ___  _ __   | | ___   ___  _ __  
*     / _` | | '_ ` _ \| | | |/ _ \| '_ \  | |/ _ \ / _ \| '_ \ 
*    | (_| | | | | | | | |_| | (_) | | | | | | (_) | (_) | |_) |
*     \__,_|_|_| |_| |_|\__,_|\___/|_| |_| |_|\___/ \___/| .__/ 
*                                                        | |    
* 		                                                 |_|    
*/

		nsize  = tree->Reco_QQ_size; //get the size
		if (nsize!=1) continue; // Gen lvl events are saved for MC (above) even if no Reco information is present
		
		//for (int m=0; m<nsize; m++) { // loops over all dimuons		
		  //if (nsize==1) { // only events with exactly one dimuon
		  int m=0; // uncomment with above only (now not used)

			QQ_Ntrk = tree->Reco_QQ_Ntrk;
			Ntracks = tree->Ntracks;
			sign = tree->Reco_QQ_sign[m];
			QQ_trig = tree->Reco_QQ_trig[m];
			HLTrig = tree->HLTriggers;
			TLorentzVector *QQ_4mom = (TLorentzVector*)tree->Reco_QQ_4mom->At(m);
			TVector3 *QQ_vtx = (TVector3*)tree->Reco_QQ_vtx->At(m);


			invmass = QQ_4mom->M();
			QQ_pT = QQ_4mom->Pt();
			QQ_rap = QQ_4mom->Rapidity();
			QQ_vtx_z = QQ_vtx->z();
			QQ_vtx_x = QQ_vtx->x();
			QQ_vtx_y = QQ_vtx->y();	
			QQ_Phi = QQ_4mom->Phi();

/*          OLD SINGLE MUON STUFF:

			TLorentzVector *mupl_4mom = (TLorentzVector*)tree->Reco_QQ_mupl_4mom->At(m);
			TLorentzVector *mumi_4mom = (TLorentzVector*)tree->Reco_QQ_mumi_4mom->At(m);

			mupl_pT = mupl_4mom->Pt();
			mupl_rap = mupl_4mom->Rapidity();
			mumi_pT = mumi_4mom->Pt();
			mumi_rap = mumi_4mom->Rapidity();
			
			mupl_Phi = mupl_4mom->Phi();
			mumi_Phi = mumi_4mom->Phi();
			aco = abs(1 -abs(mupl_Phi - mumi_Phi)/pi);

*/        

//        NEW SINGLE MUON STUFF

     	  mupl_idx  = tree->Reco_QQ_mupl_idx[m];
     	  mumi_idx  = tree->Reco_QQ_mumi_idx[m];
     	  TLorentzVector *mupl_4mom = (TLorentzVector*)tree->Reco_mu_4mom->At(mupl_idx);
     	  TLorentzVector *mumi_4mom = (TLorentzVector*)tree->Reco_mu_4mom->At(mumi_idx);

     	  	mupl_pT = mupl_4mom->Pt();
			mupl_rap = mupl_4mom->Rapidity();
			mumi_pT = mumi_4mom->Pt();
			mumi_rap = mumi_4mom->Rapidity();
			
			if (mupl_pT == mumi_pT && mupl_rap == mumi_rap) continue; // 3 events in the data passed with identical mupl and mimi
			
			
			mupl_Phi = mupl_4mom->Phi();
			mumi_Phi = mumi_4mom->Phi();
			aco = abs(1 -abs(mupl_Phi - mumi_Phi)/pi);
			
			
	// soft mu ID
    TMOneStaTight_mupl = tree->Reco_mu_TMOneStaTight[mupl_idx];
    TMOneStaTight_mumi = tree->Reco_mu_TMOneStaTight[mumi_idx];
    
    nTrkWMea_mupl = tree->Reco_mu_nTrkWMea[mupl_idx];
    nTrkWMea_mumi = tree->Reco_mu_nTrkWMea[mumi_idx];
    
    nPixWMea_mupl = tree->Reco_mu_nPixWMea[mupl_idx];
    nPixWMea_mumi = tree->Reco_mu_nPixWMea[mumi_idx];
    
    highPurity_mupl = tree->Reco_mu_highPurity[mupl_idx];
    highPurity_mumi = tree->Reco_mu_highPurity[mumi_idx];
	     
	dxy_mupl = abs(tree->Reco_mu_dxy[mupl_idx]);
	dxy_mumi = abs(tree->Reco_mu_dxy[mumi_idx]);
	
	dz_mupl = abs(tree->Reco_mu_dz[mupl_idx]);
	dz_mumi = abs(tree->Reco_mu_dz[mumi_idx]);    

    // test
    //if (i%100000==0 ) cout << endl << "Processing event # " << i << "TMOneStaTight_mupl: " << TMOneStaTight_mupl << ", :TMOneStaTight_mumi" << TMOneStaTight_mumi << endl << ", nTrkWMea_mupl:" << nTrkWMea_mupl << ", :nTrkWMea_mumi" << nTrkWMea_mumi << endl  << ", nPixWMea_mupl:"  << nPixWMea_mupl << ", nPixWMea_mumi:" << nPixWMea_mumi << endl  << ", highPurity_mupl:"  << highPurity_mupl << endl  << ", highPurity_mumi:"  << highPurity_mumi << ", dxy_mupl:" << dxy_mupl << endl  << ", dxy_mumi:"  << dxy_mumi << ", dxy_mumi:" << dxy_mumi << endl << ", dz_mupl:" << dz_mupl << endl  << ", dz_mumi:"  << dz_mumi << endl << endl;



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



                      
           // RAPIDITY BINS:
           // abs(QQ_rap)<0.7 && 
           // abs(QQ_rap)>0.7 && abs(QQ_rap)<1.4 && 
           // abs(QQ_rap)>1.4 && 
        
					
		   /*
		   mu_pT_cut_low = ;
		   mu_pT_cut_high = ;
		   QQ_pT_cut_low = ;
		   QQ_pT_cut_high = ;
		   */
		   //invmass>10 && invmass<11 && //( (mupl_pT<mu_pT_cut_high || mumi_pT<mu_pT_cut_high) ){//
		   
		   
     	  // cuts:  (((QQ_trig&8)==8) && ((HLTrig&8)==8)) {   aco>aco_low && aco<aco_high && invmass>m_cut_low && invmass<m_cut_high && mupl_pT>mu_pT_cut_low && mumi_pT>mu_pT_cut_low && mupl_pT<mu_pT_cut_high && mumi_pT<mu_pT_cut_high && QQ_pT>QQ_pT_cut_low && QQ_pT<QQ_pT_cut_high   &&    mupl_rap > -2.4 && mupl_rap < 2.4 && mumi_rap > -2.4 && mumi_rap < 2.4 &&  
          if (  1==1   ){
         
          // soft muon: (1==1){//
          if  ( (TMOneStaTight_mupl>0 && TMOneStaTight_mumi>0 && nTrkWMea_mupl>5 && nTrkWMea_mumi>5 && nPixWMea_mupl>0 && nPixWMea_mumi>0 && highPurity_mupl==true && highPurity_mumi==true && dxy_mupl<0.3 && dxy_mumi<0.3 && dz_mupl<20 && dz_mumi<20) ){

          // acceptance:
         if (1==1){// ( ( abs(mupl_rap) < 2.4 && ( abs(mupl_pT) > 3.35 || ( abs(mupl_rap) > 0.3 && abs(mupl_pT) > 3.25) ||  (abs(mupl_pT) > (-2.25*abs(mupl_rap) + 5.5) && abs(mupl_rap) > 2.35) || (abs(mupl_pT) > (-4.75*abs(mupl_rap) + 10.9) &&  abs(mupl_pT) > 1.4)) ) &&
              //( abs(mumi_rap) < 2.4 && ( abs(mumi_pT) > 3.35 || ( abs(mumi_rap) > 0.3 && abs(mumi_pT) > 3.25) ||  (abs(mumi_pT) > (-2.25*abs(mumi_rap) + 5.5) && abs(mumi_rap) > 2.35) || (abs(mumi_pT) > (-4.75*abs(mumi_rap) + 10.9) &&  abs(mumi_pT) > 1.4)) ) ) {



          histo_QQ_size->Fill(nsize);
          sp_QQ_Ntrk_QQ_size->Fill(*QQ_Ntrk, nsize);
          sp_Ntracks_QQ_size->Fill(Ntracks, nsize);

          evts++;
		  
		  ///////    fills m_pT_y.txt file:    /////////
          textfile << invmass << " " << QQ_pT << " " << QQ_rap << endl;
          
          histo_QQ_M->Fill(invmass);
          
          histo_QQ_trig->Fill(QQ_trig);
          histo_HLTrig->Fill(HLTrig);
          sp_QQ_trig_HLTrig->Fill(QQ_trig, HLTrig);
          
    	  //////     mass cut for some histos:    ///////////
          
          //if (invmass > m_min && invmass < m_max) {
          
          
          histo_HF_energy_Min->Fill(HadEnergy_HF_Minus);
          histo_HF_energy_Pl->Fill(HadEnergy_HF_Plus);
          sp_HF->Fill(HadEnergy_HF_Minus, HadEnergy_HF_Plus);
          sp_HFm_QQ_pT->Fill(HadEnergy_HF_Minus, QQ_pT);
          sp_HFp_QQ_pT->Fill(HadEnergy_HF_Plus, QQ_pT);

          sp_Ntracks_QQ_Ntrk->Fill(Ntracks, *QQ_Ntrk);
          
          
          histo_QQ_pT->Fill(QQ_pT);
          histo_QQ_pT2->Fill(QQ_pT*QQ_pT);
          histo_QQ_vtx_z->Fill(QQ_vtx_z);
          histo_QQ_rap->Fill(QQ_rap);

          histo_QQ_Ntrk->Fill(*QQ_Ntrk);
          histo_Ntracks->Fill(Ntracks);
          
          histo_mu_pT->Fill(mupl_pT);
          histo_mu_pT->Fill(mumi_pT);
          
          histo_mu_rap->Fill(mupl_rap);
          histo_mu_rap->Fill(mumi_rap);
          
          sp_QQ_pT_QQ_rap->Fill(QQ_rap, QQ_pT);

          sp_mu_pT_mu_rap->Fill(mumi_rap, mumi_pT);
          sp_mu_pT_mu_rap->Fill(mupl_rap, mupl_pT);


        if (isMC) {
          histo_QQ_pT_Reco_Gen->Fill(Gen_QQ_pT);
          histo_QQ_rap_Reco_Gen->Fill(Gen_QQ_rap);

          histo_mu_pT_Reco_Gen->Fill(Gen_mupl_pT);
          histo_mu_pT_Reco_Gen->Fill(Gen_mumi_pT);
          
          histo_mu_rap_Reco_Gen->Fill(Gen_mupl_rap);
          histo_mu_rap_Reco_Gen->Fill(Gen_mumi_rap);

          sp_QQ_pT_QQ_rap_Reco_Gen->Fill(Gen_QQ_rap, Gen_QQ_pT);

          sp_mu_pT_mu_rap_Reco_Gen->Fill(Gen_mumi_rap, Gen_mumi_pT);
          sp_mu_pT_mu_rap_Reco_Gen->Fill(Gen_mupl_rap, Gen_mupl_pT);
          
                  }


          histo_aco->Fill(aco);
          histo_mu_Phi->Fill(mupl_Phi);
          histo_mu_Phi->Fill(mumi_Phi);
          histo_QQ_Phi->Fill(QQ_Phi);
          sp_QQ_pT_Aco->Fill(aco,QQ_pT);
          sp_mupl_rap_mumi_rap->Fill(mumi_rap,mupl_rap);
          sp_mupl_pT_mumi_pT->Fill(mumi_pT,mupl_pT);



         // } // mass window selection
          
          			} // acceptance
          			} // cuts  
          			} // soft muon ID
			      	//} // dimuon loop OR selection of exactly one dimuon
   } // loop over i (entries)

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
  
  if (isMC) {
  
    histo_QQ_rap_Acc->Divide(histo_QQ_rap_Reco_Gen, histo_QQ_rap_Gen, 1, 1);
    sp_QQ_pT_QQ_rap_Acc->Divide(sp_QQ_pT_QQ_rap_Reco_Gen, sp_QQ_pT_QQ_rap_Gen, 1, 1);
    histo_mu_pT_Acc->Divide(histo_mu_pT_Reco_Gen, histo_mu_pT_Gen, 1, 1);
    histo_mu_rap_Acc->Divide(histo_mu_rap_Reco_Gen, histo_mu_rap_Gen, 1, 1);
    sp_mu_pT_mu_rap_Acc->Divide(sp_mu_pT_mu_rap_Reco_Gen, sp_mu_pT_mu_rap_Gen, 1, 1);
    histo_QQ_pT_Acc->Divide(histo_QQ_pT_Reco_Gen, histo_QQ_pT_Gen, 1, 1);


    histo_QQ_rap_Reco_Gen->Write();
    sp_QQ_pT_QQ_rap_Reco_Gen->Write();
    histo_mu_pT_Reco_Gen->Write();
    histo_mu_rap_Reco_Gen->Write();
    sp_mu_pT_mu_rap_Reco_Gen->Write();
    histo_QQ_pT_Reco_Gen->Write();

    sp_QQ_pT_QQ_rap_Gen->Write();
    sp_QQ_pT_QQ_rap_Acc->Write();
    sp_mu_pT_mu_rap_Gen->Write();
    sp_mu_pT_mu_rap_Acc->Write();
    histo_mu_pT_Gen->Write();
    histo_mu_pT_Acc->Write();
    histo_mu_rap_Gen->Write();
    histo_mu_rap_Acc->Write();
    histo_QQ_rap_Gen->Write();
    histo_QQ_rap_Acc->Write();
    histo_QQ_pT_Gen->Write();
    histo_QQ_pT_Acc->Write();
  }
  
          histo_HF_energy_Min->Write();
          histo_HF_energy_Pl->Write();
          sp_HF->Write();
          sp_QQ_Ntrk_QQ_size->Write();
          sp_Ntracks_QQ_size->Write();
          sp_Ntracks_QQ_Ntrk->Write();
          histo_QQ_size->Write();
          histo_QQ_Ntrk->Write();
          histo_Ntracks->Write();
          histo_QQ_M->Write();
          histo_QQ_pT->Write();
          histo_QQ_pT2->Write();
          histo_QQ_vtx_z->Write();
          histo_mu_pT->Write();
          histo_QQ_rap->Write();
          sp_QQ_pT_QQ_rap->Write();
          histo_mu_rap->Write();
          sp_mu_pT_mu_rap->Write();
          histo_aco->Write();
          histo_mu_Phi->Write();
          histo_QQ_Phi->Write();
          histo_QQ_trig->Write();
          histo_HLTrig->Write();
          sp_QQ_trig_HLTrig->Write();
          sp_HFm_QQ_pT->Write();
          sp_HFp_QQ_pT->Write();
          sp_QQ_pT_Aco->Write();

          sp_mupl_rap_mumi_rap->Write();
          sp_mupl_pT_mumi_pT->Write();


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
 
        /////  drawing codes:  //////
        system("root -l -b -q draw.c");
        if (isMC) system("root -l -b -q draw_Gen.c");
        //system("root -l -b -q FitMass.c");
        //system("root -l -b -q mass_fit.c > plots/roofit.txt");
        

   system("root -l -b -q DrawHisto_QQ_m.c");
   system("root -l -b -q DrawHisto_QQ_pT.c");
   system("root -l -b -q DrawHisto_QQ_rap.c");
   system("root -l -b -q DrawHisto_mu_pT.c");
   system("root -l -b -q DrawHisto_mu_rap.c");
   system("awk '{print $1}' plots/m_pT_y.txt > plots/m.txt");
        
        
   system("rm -r " + dirname);
   system("mv plots " + dirname);

      
  cout << endl << "******* finished and saved *******" << endl;

   return 0;
   
   }
