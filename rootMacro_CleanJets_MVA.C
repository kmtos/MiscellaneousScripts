#include <string.h>
#include "TChain.h"
#include "TFile.h"
#include "TH1.h"
#include "TTree.h"
#include "TKey.h"
#include "Riostream.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TGraphAsymmErrors.h"
#include "TGraph.h"
#include "TMultiGraph.h"


void rootMacro_CleanJets_MVA()
{

  gStyle->SetOptStat(kFALSE);
  gStyle->SetEndErrorSize(7);


  //New DMs
  TFile infileCJNew("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/ggH125a9_NewDecayIDCJ_NewDM_OverDM_ak5_JUL14/ggH125a9_NewDecayIDCJ_NewDM_OverDM_ak5_JUL14_Plots.root");
  TFile infileRECONew("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/ggH125a9_NewDecayIDRECO_NewDM_OverDM_ak5_JUL14/ggH125a9_NewDecayIDRECO_NewDM_OverDM_ak5_JUL14_Plots.root");
  TFile infileKyleNew("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/ggH125a9_OldDecayID_NewDMFind_OverDM_ak5_JUL14/ggH125a9_OldDecayID_NewDMFind_OverDM_ak5_JUL14_Plots.root");
  TFile infileDY("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/DYJetsToLL_M-50_300000Events_NewDM_MVA_JUL7/DYJetsToLL_M-50_300000Events_NewDM_MVA_JUL7_Plots.root");
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/CombinedPlots/combHist_CleanJets_h125a9_NewDM_MVA_ak5.root", "RECREATE");

/*
  //Old DMs
  TFile infileCJNew("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/ggH125a9_NewDecayIDCJ_OldDM_OverDM_ak5_JUL14/ggH125a9_NewDecayIDCJ_OldDM_OverDM_ak5_JUL14_Plots.root");
  TFile infileRECONew("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/ggH125a9_NewDecayIDRECO_OldDM_OverDM_ak5_JUL14/ggH125a9_NewDecayIDRECO_OldDM_OverDM_ak5_JUL14_Plots.root");
  TFile infileKyleNew("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/ggH125a9_OldDecayID_OldDMFind_OverDM_MVA_ak5_JUL14/ggH125a9_OldDecayID_OldDMFind_OverDM_MVA_ak5_JUL14_Plots.root");
  TFile infileDY("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/DYJetsToLL_M-50_300000Events_OldDM_MVA_JUL7/DYJetsToLL_M-50_300000Events_OldDM_MVA_JUL7_Plots.root");
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/CombinedPlots/combHist_CleanJets_h125a9_OldDM_MVA_ak5.root", "RECREATE");
*/
cout << "Files Created" << endl;

  // CJ/RECO Comparison histograms
  TCanvas *MatchedLooseIsoCJPtMVACanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedLooseIsoCJPtMVA");
  TCanvas *MatchedLooseIsoRECOPtMVACanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedLooseIsoRECOPtMVA");
  TCanvas *MatchedMedIsoCJPtMVACanvasRachNew     = (TCanvas*)infileCJNew.Get("MatchedMedIsoCJPtMVA");
  TCanvas *MatchedMedIsoRECOPtMVACanvasRachNew   = (TCanvas*)infileRECONew.Get("MatchedMedIsoRECOPtMVA");
  TCanvas *MatchedTightIsoCJPtMVACanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedTightIsoCJPtMVA");
  TCanvas *MatchedTightIsoRECOPtMVACanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedTightIsoRECOPtMVA");
  TCanvas *MatchedCJPtMVACanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedCJPtMVA");
  TCanvas *MatchedRECOPtMVACanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedRECOPtMVA");
  
  TCanvas *MatchedLooseIsoCJdRMVACanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedLooseIsoCJdRMVA");
  TCanvas *MatchedLooseIsoRECOdRMVACanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedLooseIsoRECOdRMVA");
  TCanvas *MatchedMedIsoCJdRMVACanvasRachNew     = (TCanvas*)infileCJNew.Get("MatchedMedIsoCJdRMVA");
  TCanvas *MatchedMedIsoRECOdRMVACanvasRachNew   = (TCanvas*)infileRECONew.Get("MatchedMedIsoRECOdRMVA");
  TCanvas *MatchedTightIsoCJdRMVACanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedTightIsoCJdRMVA");
  TCanvas *MatchedTightIsoRECOdRMVACanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedTightIsoRECOdRMVA");
  TCanvas *MatchedCJdRMVACanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedCJdRMVA");
  TCanvas *MatchedRECOdRMVACanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedRECOdRMVA");

  TCanvas *MatchedLooseIsoCJPtGenMVACanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedLooseIsoCJPtGenMVA");
  TCanvas *MatchedLooseIsoRECOPtGenMVACanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedLooseIsoRECOPtGenMVA");
  TCanvas *MatchedMedIsoCJPtGenMVACanvasRachNew     = (TCanvas*)infileCJNew.Get("MatchedMedIsoCJPtGenMVA");
  TCanvas *MatchedMedIsoRECOPtGenMVACanvasRachNew   = (TCanvas*)infileRECONew.Get("MatchedMedIsoRECOPtGenMVA");
  TCanvas *MatchedTightIsoCJPtGenMVACanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedTightIsoCJPtGenMVA");
  TCanvas *MatchedTightIsoRECOPtGenMVACanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedTightIsoRECOPtGenMVA");
  TCanvas *MatchedCJPtGenMVACanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedCJPtGenMVA");
  TCanvas *MatchedRECOPtGenMVACanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedRECOPtGenMVA");

  // Kyle Gen Matching New DM 
  TCanvas *MatchedLooseIsoCJPtCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedLooseIsoCJPt");
  TCanvas *MatchedLooseIsoRECOPtCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedLooseIsoRECOPt");
  TCanvas *MatchedMedIsoCJPtCanvasKyleNew     = (TCanvas*)infileKyleNew.Get("MatchedMedIsoCJPt");
  TCanvas *MatchedMedIsoRECOPtCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedMedIsoRECOPt");
  TCanvas *MatchedTightIsoCJPtCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedTightIsoCJPt");
  TCanvas *MatchedTightIsoRECOPtCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedTightIsoRECOPt");
  TCanvas *MatchedCJPtCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedCJPt");
  TCanvas *MatchedRECOPtCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedRECOPt");

  TCanvas *MatchedLooseIsoCJdRCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedLooseIsoCJdR");
  TCanvas *MatchedLooseIsoRECOdRCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedLooseIsoRECOdR");
  TCanvas *MatchedMedIsoCJdRCanvasKyleNew     = (TCanvas*)infileKyleNew.Get("MatchedMedIsoCJdR");
  TCanvas *MatchedMedIsoRECOdRCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedMedIsoRECOdR");
  TCanvas *MatchedTightIsoCJdRCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedTightIsoCJdR");
  TCanvas *MatchedTightIsoRECOdRCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedTightIsoRECOdR");
  TCanvas *MatchedCJdRCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedCJdR");
  TCanvas *MatchedRECOdRCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedRECOdR");

  TCanvas *MatchedLooseIsoCJPtGenCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedLooseIsoCJPtGen");
  TCanvas *MatchedLooseIsoRECOPtGenCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedLooseIsoRECOPtGen");
  TCanvas *MatchedMedIsoCJPtGenCanvasKyleNew     = (TCanvas*)infileKyleNew.Get("MatchedMedIsoCJPtGen");
  TCanvas *MatchedMedIsoRECOPtGenCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedMedIsoRECOPtGen");
  TCanvas *MatchedTightIsoCJPtGenCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedTightIsoCJPtGen");
  TCanvas *MatchedTightIsoRECOPtGenCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedTightIsoRECOPtGen");
  TCanvas *MatchedCJPtGenCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedCJPtGen");
  TCanvas *MatchedRECOPtGenCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedRECOPtGen");

  // DY
  TCanvas *MatchedLooseIsoRECOPtCanvasDY = (TCanvas*)infileDY.Get("MatchedLooseIsoRECOPt");
  TCanvas *MatchedMedIsoRECOPtCanvasDY   = (TCanvas*)infileDY.Get("MatchedMedIsoRECOPt");
  TCanvas *MatchedTightIsoRECOPtCanvasDY = (TCanvas*)infileDY.Get("MatchedTightIsoRECOPt");
  TCanvas *MatchedRECOPtCanvasDY = (TCanvas*)infileDY.Get("MatchedRECOPt");

  TCanvas *MatchedLooseIsoRECOdRCanvasDY = (TCanvas*)infileDY.Get("MatchedLooseIsoRECOdR");
  TCanvas *MatchedMedIsoRECOdRCanvasDY   = (TCanvas*)infileDY.Get("MatchedMedIsoRECOdR");
  TCanvas *MatchedTightIsoRECOdRCanvasDY = (TCanvas*)infileDY.Get("MatchedTightIsoRECOdR");
  TCanvas *MatchedRECOdRCanvasDY = (TCanvas*)infileDY.Get("MatchedRECOdR");

  TCanvas *MatchedLooseIsoRECOPtGenCanvasDY = (TCanvas*)infileDY.Get("MatchedLooseIsoRECOPtGen");
  TCanvas *MatchedMedIsoRECOPtGenCanvasDY   = (TCanvas*)infileDY.Get("MatchedMedIsoRECOPtGen");
  TCanvas *MatchedTightIsoRECOPtGenCanvasDY = (TCanvas*)infileDY.Get("MatchedTightIsoRECOPtGen");
  TCanvas *MatchedRECOPtGenCanvasDY = (TCanvas*)infileDY.Get("MatchedRECOPtGen");

cout << "Got Canvases" << endl;

  // Getting the histograms for the New gen matching and DM New
  TH1F* MatchedLooseIsoCJPtMVARachNew_   = (TH1F*)MatchedLooseIsoCJPtMVACanvasRachNew->GetPrimitive("MatchedLooseIsoCJPtMVA");
  TH1F* MatchedLooseIsoRECOPtMVARachNew_ = (TH1F*)MatchedLooseIsoRECOPtMVACanvasRachNew->GetPrimitive("MatchedLooseIsoRECOPtMVA");
  TH1F* MatchedMedIsoCJPtMVARachNew_     = (TH1F*)MatchedMedIsoCJPtMVACanvasRachNew->GetPrimitive("MatchedMedIsoCJPtMVA");
  TH1F* MatchedMedIsoRECOPtMVARachNew_   = (TH1F*)MatchedMedIsoRECOPtMVACanvasRachNew->GetPrimitive("MatchedMedIsoRECOPtMVA");
  TH1F* MatchedTightIsoCJPtMVARachNew_   = (TH1F*)MatchedTightIsoCJPtMVACanvasRachNew->GetPrimitive("MatchedTightIsoCJPtMVA");
  TH1F* MatchedTightIsoRECOPtMVARachNew_ = (TH1F*)MatchedTightIsoRECOPtMVACanvasRachNew->GetPrimitive("MatchedTightIsoRECOPtMVA");
  TH1F* MatchedCJPtMVARachNew_   = (TH1F*)MatchedCJPtMVACanvasRachNew->GetPrimitive("MatchedCJPtMVA");
  TH1F* MatchedRECOPtMVARachNew_ = (TH1F*)MatchedRECOPtMVACanvasRachNew->GetPrimitive("MatchedRECOPtMVA");

  TH1F* MatchedLooseIsoCJdRMVARachNew_   = (TH1F*)MatchedLooseIsoCJdRMVACanvasRachNew->GetPrimitive("MatchedLooseIsoCJdRMVA");
  TH1F* MatchedLooseIsoRECOdRMVARachNew_ = (TH1F*)MatchedLooseIsoRECOdRMVACanvasRachNew->GetPrimitive("MatchedLooseIsoRECOdRMVA");
  TH1F* MatchedMedIsoCJdRMVARachNew_     = (TH1F*)MatchedMedIsoCJdRMVACanvasRachNew->GetPrimitive("MatchedMedIsoCJdRMVA");
  TH1F* MatchedMedIsoRECOdRMVARachNew_   = (TH1F*)MatchedMedIsoRECOdRMVACanvasRachNew->GetPrimitive("MatchedMedIsoRECOdRMVA");
  TH1F* MatchedTightIsoCJdRMVARachNew_   = (TH1F*)MatchedTightIsoCJdRMVACanvasRachNew->GetPrimitive("MatchedTightIsoCJdRMVA");
  TH1F* MatchedTightIsoRECOdRMVARachNew_ = (TH1F*)MatchedTightIsoRECOdRMVACanvasRachNew->GetPrimitive("MatchedTightIsoRECOdRMVA");
  TH1F* MatchedCJdRMVARachNew_   = (TH1F*)MatchedCJdRMVACanvasRachNew->GetPrimitive("MatchedCJdRMVA");
  TH1F* MatchedRECOdRMVARachNew_ = (TH1F*)MatchedRECOdRMVACanvasRachNew->GetPrimitive("MatchedRECOdRMVA");

  TH1F* MatchedLooseIsoCJPtGenMVARachNew_   = (TH1F*)MatchedLooseIsoCJPtGenMVACanvasRachNew->GetPrimitive("MatchedLooseIsoCJPtGenMVA");
  TH1F* MatchedLooseIsoRECOPtGenMVARachNew_ = (TH1F*)MatchedLooseIsoRECOPtGenMVACanvasRachNew->GetPrimitive("MatchedLooseIsoRECOPtGenMVA");
  TH1F* MatchedMedIsoCJPtGenMVARachNew_     = (TH1F*)MatchedMedIsoCJPtGenMVACanvasRachNew->GetPrimitive("MatchedMedIsoCJPtGenMVA");
  TH1F* MatchedMedIsoRECOPtGenMVARachNew_   = (TH1F*)MatchedMedIsoRECOPtGenMVACanvasRachNew->GetPrimitive("MatchedMedIsoRECOPtGenMVA");
  TH1F* MatchedTightIsoCJPtGenMVARachNew_   = (TH1F*)MatchedTightIsoCJPtGenMVACanvasRachNew->GetPrimitive("MatchedTightIsoCJPtGenMVA");
  TH1F* MatchedTightIsoRECOPtGenMVARachNew_ = (TH1F*)MatchedTightIsoRECOPtGenMVACanvasRachNew->GetPrimitive("MatchedTightIsoRECOPtGenMVA");
  TH1F* MatchedCJPtGenMVARachNew_   = (TH1F*)MatchedCJPtGenMVACanvasRachNew->GetPrimitive("MatchedCJPtGenMVA");
  TH1F* MatchedRECOPtGenMVARachNew_ = (TH1F*)MatchedRECOPtGenMVACanvasRachNew->GetPrimitive("MatchedRECOPtGenMVA");

// Getting the histograms for the DM New
  TH1F* MatchedLooseIsoCJPtKyleNew_   = (TH1F*)MatchedLooseIsoCJPtCanvasKyleNew->GetPrimitive("MatchedLooseIsoCJPt");
  TH1F* MatchedLooseIsoRECOPtKyleNew_ = (TH1F*)MatchedLooseIsoRECOPtCanvasKyleNew->GetPrimitive("MatchedLooseIsoRECOPt");
  TH1F* MatchedMedIsoCJPtKyleNew_     = (TH1F*)MatchedMedIsoCJPtCanvasKyleNew->GetPrimitive("MatchedMedIsoCJPt");
  TH1F* MatchedMedIsoRECOPtKyleNew_   = (TH1F*)MatchedMedIsoRECOPtCanvasKyleNew->GetPrimitive("MatchedMedIsoRECOPt");
  TH1F* MatchedTightIsoCJPtKyleNew_   = (TH1F*)MatchedTightIsoCJPtCanvasKyleNew->GetPrimitive("MatchedTightIsoCJPt");
  TH1F* MatchedTightIsoRECOPtKyleNew_ = (TH1F*)MatchedTightIsoRECOPtCanvasKyleNew->GetPrimitive("MatchedTightIsoRECOPt");
  TH1F* MatchedCJPtKyleNew_   = (TH1F*)MatchedCJPtCanvasKyleNew->GetPrimitive("MatchedCJPt");
  TH1F* MatchedRECOPtKyleNew_ = (TH1F*)MatchedRECOPtCanvasKyleNew->GetPrimitive("MatchedRECOPt");

  TH1F* MatchedLooseIsoCJdRKyleNew_   = (TH1F*)MatchedLooseIsoCJdRCanvasKyleNew->GetPrimitive("MatchedLooseIsoCJdR");
  TH1F* MatchedLooseIsoRECOdRKyleNew_ = (TH1F*)MatchedLooseIsoRECOdRCanvasKyleNew->GetPrimitive("MatchedLooseIsoRECOdR");
  TH1F* MatchedMedIsoCJdRKyleNew_     = (TH1F*)MatchedMedIsoCJdRCanvasKyleNew->GetPrimitive("MatchedMedIsoCJdR");
  TH1F* MatchedMedIsoRECOdRKyleNew_   = (TH1F*)MatchedMedIsoRECOdRCanvasKyleNew->GetPrimitive("MatchedMedIsoRECOdR");
  TH1F* MatchedTightIsoCJdRKyleNew_   = (TH1F*)MatchedTightIsoCJdRCanvasKyleNew->GetPrimitive("MatchedTightIsoCJdR");
  TH1F* MatchedTightIsoRECOdRKyleNew_ = (TH1F*)MatchedTightIsoRECOdRCanvasKyleNew->GetPrimitive("MatchedTightIsoRECOdR");
  TH1F* MatchedCJdRKyleNew_   = (TH1F*)MatchedCJdRCanvasKyleNew->GetPrimitive("MatchedCJdR");
  TH1F* MatchedRECOdRKyleNew_ = (TH1F*)MatchedRECOdRCanvasKyleNew->GetPrimitive("MatchedRECOdR");

  TH1F* MatchedLooseIsoCJPtGenKyleNew_   = (TH1F*)MatchedLooseIsoCJPtGenCanvasKyleNew->GetPrimitive("MatchedLooseIsoCJPtGen");
  TH1F* MatchedLooseIsoRECOPtGenKyleNew_ = (TH1F*)MatchedLooseIsoRECOPtGenCanvasKyleNew->GetPrimitive("MatchedLooseIsoRECOPtGen");
  TH1F* MatchedMedIsoCJPtGenKyleNew_     = (TH1F*)MatchedMedIsoCJPtGenCanvasKyleNew->GetPrimitive("MatchedMedIsoCJPtGen");
  TH1F* MatchedMedIsoRECOPtGenKyleNew_   = (TH1F*)MatchedMedIsoRECOPtGenCanvasKyleNew->GetPrimitive("MatchedMedIsoRECOPtGen");
  TH1F* MatchedTightIsoCJPtGenKyleNew_   = (TH1F*)MatchedTightIsoCJPtGenCanvasKyleNew->GetPrimitive("MatchedTightIsoCJPtGen");
  TH1F* MatchedTightIsoRECOPtGenKyleNew_ = (TH1F*)MatchedTightIsoRECOPtGenCanvasKyleNew->GetPrimitive("MatchedTightIsoRECOPtGen");
  TH1F* MatchedCJPtGenKyleNew_   = (TH1F*)MatchedCJPtGenCanvasKyleNew->GetPrimitive("MatchedCJPtGen");
  TH1F* MatchedRECOPtGenKyleNew_ = (TH1F*)MatchedRECOPtGenCanvasKyleNew->GetPrimitive("MatchedRECOPtGen");

// Getting the histograms for the DM New
  TH1F* MatchedLooseIsoRECOPtDY_ = (TH1F*)MatchedLooseIsoRECOPtCanvasDY->GetPrimitive("MatchedLooseIsoRECOPt");
  TH1F* MatchedMedIsoRECOPtDY_   = (TH1F*)MatchedMedIsoRECOPtCanvasDY->GetPrimitive("MatchedMedIsoRECOPt");
  TH1F* MatchedTightIsoRECOPtDY_ = (TH1F*)MatchedTightIsoRECOPtCanvasDY->GetPrimitive("MatchedTightIsoRECOPt");
  TH1F* MatchedRECOPtDY_ = (TH1F*)MatchedRECOPtCanvasDY->GetPrimitive("MatchedRECOPt");

  TH1F* MatchedLooseIsoRECOdRDY_ = (TH1F*)MatchedLooseIsoRECOdRCanvasDY->GetPrimitive("MatchedLooseIsoRECOdR");
  TH1F* MatchedMedIsoRECOdRDY_   = (TH1F*)MatchedMedIsoRECOdRCanvasDY->GetPrimitive("MatchedMedIsoRECOdR");
  TH1F* MatchedTightIsoRECOdRDY_ = (TH1F*)MatchedTightIsoRECOdRCanvasDY->GetPrimitive("MatchedTightIsoRECOdR");
  TH1F* MatchedRECOdRDY_ = (TH1F*)MatchedRECOdRCanvasDY->GetPrimitive("MatchedRECOdR");

  TH1F* MatchedLooseIsoRECOPtGenDY_ = (TH1F*)MatchedLooseIsoRECOPtGenCanvasDY->GetPrimitive("MatchedLooseIsoRECOPtGen");
  TH1F* MatchedMedIsoRECOPtGenDY_   = (TH1F*)MatchedMedIsoRECOPtGenCanvasDY->GetPrimitive("MatchedMedIsoRECOPtGen");
  TH1F* MatchedTightIsoRECOPtGenDY_ = (TH1F*)MatchedTightIsoRECOPtGenCanvasDY->GetPrimitive("MatchedTightIsoRECOPtGen");
  TH1F* MatchedRECOPtGenDY_ = (TH1F*)MatchedRECOPtGenCanvasDY->GetPrimitive("MatchedRECOPtGen");

cout << "Histograms assigned." << endl; 

  TCanvas LoosePtCanvas("LoosePtCanvas","",600,600);
  TCanvas MedPtCanvas("MedPtCanvas","",600,600);
  TCanvas TightPtCanvas("TightPtCanvas","",600,600);
  TCanvas DMPtCanvas("DMPtCanvas","",600,600);

  TCanvas LoosedRCanvas("LoosedRCanvas","",600,600);
  TCanvas MeddRCanvas("MeddRCanvas","",600,600);
  TCanvas TightdRCanvas("TightdRCanvas","",600,600);
  TCanvas DMdRCanvas("DMdRCanvas","",600,600);

  TCanvas LoosePtGenCanvas("LoosePtGenCanvas","",600,600);
  TCanvas MedPtGenCanvas("MedPtGenCanvas","",600,600);
  TCanvas TightPtGenCanvas("TightPtGenCanvas","",600,600);
  TCanvas DMPtGenCanvas("DMPtGenCanvas","",600,600);

  TCanvas LoosePtNewGenMatchCanvas("LoosePtNewGenMatchCanvas","",600,600);
  TCanvas MedPtNewGenMatchCanvas("MedPtNewGenMatchCanvas","",600,600);
  TCanvas TightPtNewGenMatchCanvas("TightPtNewGenMatchCanvas","",600,600);
  TCanvas DMPtNewGenMatchCanvas("DMPtNewGenMatchCanvas","",600,600);

  TCanvas LoosedRNewGenMatchCanvas("LoosedRNewGenMatchCanvas","",600,600);
  TCanvas MeddRNewGenMatchCanvas("MeddRNewGenMatchCanvas","",600,600);
  TCanvas TightdRNewGenMatchCanvas("TightdRNewGenMatchCanvas","",600,600);
  TCanvas DMdRNewGenMatchCanvas("DMdRNewGenMatchCanvas","",600,600);

  TCanvas LoosePtGenNewGenMatchCanvas("LoosePtGenNewGenMatchCanvas","",600,600);
  TCanvas MedPtGenNewGenMatchCanvas("MedPtGenNewGenMatchCanvas","",600,600);
  TCanvas TightPtGenNewGenMatchCanvas("TightPtGenNewGenMatchCanvas","",600,600);
  TCanvas DMPtGenNewGenMatchCanvas("DMPtGenNewGenMatchCanvas","",600,600);

  LoosePtCanvas.SetGrid(1,1);
  MedPtCanvas.SetGrid(1,1);
  TightPtCanvas.SetGrid(1,1);
  DMPtCanvas.SetGrid(1,1);
  
  LoosedRCanvas.SetGrid(1,1);
  MeddRCanvas.SetGrid(1,1);
  TightdRCanvas.SetGrid(1,1);
  DMdRCanvas.SetGrid(1,1);
  
  LoosePtGenCanvas.SetGrid(1,1);
  MedPtGenCanvas.SetGrid(1,1);
  TightPtGenCanvas.SetGrid(1,1);
  DMPtGenCanvas.SetGrid(1,1);

  LoosePtNewGenMatchCanvas.SetGrid(1,1);
  MedPtNewGenMatchCanvas.SetGrid(1,1);
  TightPtNewGenMatchCanvas.SetGrid(1,1);
  DMPtNewGenMatchCanvas.SetGrid(1,1);
 
  LoosedRNewGenMatchCanvas.SetGrid(1,1);
  MeddRNewGenMatchCanvas.SetGrid(1,1);
  TightdRNewGenMatchCanvas.SetGrid(1,1);
  DMdRNewGenMatchCanvas.SetGrid(1,1);
 
  LoosePtGenNewGenMatchCanvas.SetGrid(1,1);
  MedPtGenNewGenMatchCanvas.SetGrid(1,1);
  TightPtGenNewGenMatchCanvas.SetGrid(1,1);
  DMPtGenNewGenMatchCanvas.SetGrid(1,1);

cout << "Canvases created" << endl;

  // To  divide histograms for efficiency with new Gen Matching New DM's
  TGraphAsymmErrors* FinalEffLooseIsoRECOPtMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOPtMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOPtMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffRECOPtMVARachNew_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoCJPtMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoCJPtMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoCJPtMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffCJPtMVARachNew_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoRECOdRMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOdRMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOdRMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffRECOdRMVARachNew_ = new TGraphAsymmErrors(30);
  
  TGraphAsymmErrors* FinalEffLooseIsoCJdRMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoCJdRMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoCJdRMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffCJdRMVARachNew_ = new TGraphAsymmErrors(30);
  
  TGraphAsymmErrors* FinalEffLooseIsoRECOPtGenMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOPtGenMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOPtGenMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffRECOPtGenMVARachNew_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoCJPtGenMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoCJPtGenMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoCJPtGenMVARachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffCJPtGenMVARachNew_ = new TGraphAsymmErrors(30);

  // To divide histograms for efficiency with Old Gen Matching New DM's
  TGraphAsymmErrors* FinalEffLooseIsoRECOPtKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOPtKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOPtKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffRECOPtKyleNew_ = new TGraphAsymmErrors(30);
  
  TGraphAsymmErrors* FinalEffLooseIsoCJPtKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoCJPtKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoCJPtKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffCJPtKyleNew_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoRECOdRKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOdRKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOdRKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffRECOdRKyleNew_ = new TGraphAsymmErrors(30);
  
  TGraphAsymmErrors* FinalEffLooseIsoCJdRKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoCJdRKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoCJdRKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffCJdRKyleNew_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoRECOPtGenKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOPtGenKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOPtGenKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffRECOPtGenKyleNew_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoCJPtGenKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoCJPtGenKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoCJPtGenKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffCJPtGenKyleNew_ = new TGraphAsymmErrors(30);

  // To divide histograms for efficiency with Old Gen Matching New DM's
  TGraphAsymmErrors* FinalEffLooseIsoRECOPtDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOPtDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOPtDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffRECOPtDY_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoRECOdRDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOdRDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOdRDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffRECOdRDY_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoRECOPtGenDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOPtGenDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOPtGenDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffRECOPtGenDY_ = new TGraphAsymmErrors(30);

  // To divide histograms for efficiency with new Gen Matching New DM's
  FinalEffLooseIsoRECOPtMVARachNew_->Divide(MatchedLooseIsoRECOPtMVARachNew_, MatchedRECOPtMVARachNew_);
  FinalEffMedIsoRECOPtMVARachNew_->Divide(MatchedMedIsoRECOPtMVARachNew_,     MatchedRECOPtMVARachNew_);
  FinalEffTightIsoRECOPtMVARachNew_->Divide(MatchedTightIsoRECOPtMVARachNew_, MatchedRECOPtMVARachNew_);
  FinalEffLooseIsoCJPtMVARachNew_->Divide(MatchedLooseIsoCJPtMVARachNew_, MatchedCJPtMVARachNew_);
  FinalEffMedIsoCJPtMVARachNew_->Divide(MatchedMedIsoCJPtMVARachNew_,     MatchedCJPtMVARachNew_);
  FinalEffTightIsoCJPtMVARachNew_->Divide(MatchedTightIsoCJPtMVARachNew_, MatchedCJPtMVARachNew_);

  FinalEffLooseIsoRECOdRMVARachNew_->Divide(MatchedLooseIsoRECOdRMVARachNew_, MatchedRECOdRMVARachNew_);
  FinalEffMedIsoRECOdRMVARachNew_->Divide(MatchedMedIsoRECOdRMVARachNew_,     MatchedRECOdRMVARachNew_);
  FinalEffTightIsoRECOdRMVARachNew_->Divide(MatchedTightIsoRECOdRMVARachNew_, MatchedRECOdRMVARachNew_);
  FinalEffLooseIsoCJdRMVARachNew_->Divide(MatchedLooseIsoCJdRMVARachNew_, MatchedCJdRMVARachNew_);
  FinalEffMedIsoCJdRMVARachNew_->Divide(MatchedMedIsoCJdRMVARachNew_,     MatchedCJdRMVARachNew_);
  FinalEffTightIsoCJdRMVARachNew_->Divide(MatchedTightIsoCJdRMVARachNew_, MatchedCJdRMVARachNew_);

  FinalEffLooseIsoRECOPtGenMVARachNew_->Divide(MatchedLooseIsoRECOPtGenMVARachNew_, MatchedRECOPtGenMVARachNew_);
  FinalEffMedIsoRECOPtGenMVARachNew_->Divide(MatchedMedIsoRECOPtGenMVARachNew_,     MatchedRECOPtGenMVARachNew_);
  FinalEffTightIsoRECOPtGenMVARachNew_->Divide(MatchedTightIsoRECOPtGenMVARachNew_, MatchedRECOPtGenMVARachNew_);
  FinalEffLooseIsoCJPtGenMVARachNew_->Divide(MatchedLooseIsoCJPtGenMVARachNew_, MatchedCJPtGenMVARachNew_);
  FinalEffMedIsoCJPtGenMVARachNew_->Divide(MatchedMedIsoCJPtGenMVARachNew_,     MatchedCJPtGenMVARachNew_);
  FinalEffTightIsoCJPtGenMVARachNew_->Divide(MatchedTightIsoCJPtGenMVARachNew_, MatchedCJPtGenMVARachNew_);
  
  // To divide histograms for efficiency with OLD Gen Matching New DM's 
  FinalEffLooseIsoRECOPtKyleNew_->Divide(MatchedLooseIsoRECOPtKyleNew_, MatchedRECOPtKyleNew_);
  FinalEffMedIsoRECOPtKyleNew_->Divide(MatchedMedIsoRECOPtKyleNew_,     MatchedRECOPtKyleNew_);
  FinalEffTightIsoRECOPtKyleNew_->Divide(MatchedTightIsoRECOPtKyleNew_, MatchedRECOPtKyleNew_);
  FinalEffLooseIsoCJPtKyleNew_->Divide(MatchedLooseIsoCJPtKyleNew_, MatchedCJPtKyleNew_);
  FinalEffMedIsoCJPtKyleNew_->Divide(MatchedMedIsoCJPtKyleNew_,     MatchedCJPtKyleNew_);
  FinalEffTightIsoCJPtKyleNew_->Divide(MatchedTightIsoCJPtKyleNew_, MatchedCJPtKyleNew_);

  FinalEffLooseIsoRECOdRKyleNew_->Divide(MatchedLooseIsoRECOdRKyleNew_, MatchedRECOdRKyleNew_);
  FinalEffMedIsoRECOdRKyleNew_->Divide(MatchedMedIsoRECOdRKyleNew_,     MatchedRECOdRKyleNew_);
  FinalEffTightIsoRECOdRKyleNew_->Divide(MatchedTightIsoRECOdRKyleNew_, MatchedRECOdRKyleNew_);
  FinalEffLooseIsoCJdRKyleNew_->Divide(MatchedLooseIsoCJdRKyleNew_, MatchedCJdRKyleNew_);
  FinalEffMedIsoCJdRKyleNew_->Divide(MatchedMedIsoCJdRKyleNew_,     MatchedCJdRKyleNew_);
  FinalEffTightIsoCJdRKyleNew_->Divide(MatchedTightIsoCJdRKyleNew_, MatchedCJdRKyleNew_);

  FinalEffLooseIsoRECOPtGenKyleNew_->Divide(MatchedLooseIsoRECOPtGenKyleNew_, MatchedRECOPtGenKyleNew_);
  FinalEffMedIsoRECOPtGenKyleNew_->Divide(MatchedMedIsoRECOPtGenKyleNew_,     MatchedRECOPtGenKyleNew_);
  FinalEffTightIsoRECOPtGenKyleNew_->Divide(MatchedTightIsoRECOPtGenKyleNew_, MatchedRECOPtGenKyleNew_);
  FinalEffLooseIsoCJPtGenKyleNew_->Divide(MatchedLooseIsoCJPtGenKyleNew_, MatchedCJPtGenKyleNew_);
  FinalEffMedIsoCJPtGenKyleNew_->Divide(MatchedMedIsoCJPtGenKyleNew_,     MatchedCJPtGenKyleNew_);
  FinalEffTightIsoCJPtGenKyleNew_->Divide(MatchedTightIsoCJPtGenKyleNew_, MatchedCJPtGenKyleNew_);

  // To divide histograms for efficiency with OLD Gen Matching New DM's 
  FinalEffLooseIsoRECOPtDY_->Divide(MatchedLooseIsoRECOPtDY_, MatchedRECOPtDY_);
  FinalEffMedIsoRECOPtDY_->Divide(MatchedMedIsoRECOPtDY_,     MatchedRECOPtDY_);
  FinalEffTightIsoRECOPtDY_->Divide(MatchedTightIsoRECOPtDY_, MatchedRECOPtDY_);

  FinalEffLooseIsoRECOdRDY_->Divide(MatchedLooseIsoRECOdRDY_, MatchedRECOdRDY_);
  FinalEffMedIsoRECOdRDY_->Divide(MatchedMedIsoRECOdRDY_,     MatchedRECOdRDY_);
  FinalEffTightIsoRECOdRDY_->Divide(MatchedTightIsoRECOdRDY_, MatchedRECOdRDY_);

  FinalEffLooseIsoRECOPtGenDY_->Divide(MatchedLooseIsoRECOPtGenDY_, MatchedRECOPtGenDY_);
  FinalEffMedIsoRECOPtGenDY_->Divide(MatchedMedIsoRECOPtGenDY_,     MatchedRECOPtGenDY_);
  FinalEffTightIsoRECOPtGenDY_->Divide(MatchedTightIsoRECOPtGenDY_, MatchedRECOPtGenDY_);

  //Set Colors for New Gen Matching New DM's
  FinalEffLooseIsoCJPtMVARachNew_->SetMarkerColor(kBlue+1);
  FinalEffLooseIsoRECOPtMVARachNew_->SetMarkerColor(kGreen+1);
  FinalEffMedIsoCJPtMVARachNew_->SetMarkerColor(kBlue+1);
  FinalEffMedIsoRECOPtMVARachNew_->SetMarkerColor(kGreen+1);
  FinalEffTightIsoCJPtMVARachNew_->SetMarkerColor(kBlue+1);
  FinalEffTightIsoRECOPtMVARachNew_->SetMarkerColor(kGreen+1);
  FinalEffCJPtMVARachNew_->SetMarkerColor(kBlue+1);
  FinalEffRECOPtMVARachNew_->SetMarkerColor(kGreen+1);

  FinalEffLooseIsoCJPtMVARachNew_->SetMarkerSize(.07);
  FinalEffLooseIsoRECOPtMVARachNew_->SetMarkerSize(.07);
  FinalEffMedIsoCJPtMVARachNew_->SetMarkerSize(.07);
  FinalEffMedIsoRECOPtMVARachNew_->SetMarkerSize(.07);
  FinalEffTightIsoCJPtMVARachNew_->SetMarkerSize(.07);
  FinalEffTightIsoRECOPtMVARachNew_->SetMarkerSize(.07);
  FinalEffCJPtMVARachNew_->SetMarkerSize(.07);
  FinalEffRECOPtMVARachNew_->SetMarkerSize(.07);

  FinalEffLooseIsoCJPtMVARachNew_->SetLineColor(kBlue+1);
  FinalEffLooseIsoRECOPtMVARachNew_->SetLineColor(kGreen+1);
  FinalEffMedIsoCJPtMVARachNew_->SetLineColor(kBlue+1);
  FinalEffMedIsoRECOPtMVARachNew_->SetLineColor(kGreen+1);
  FinalEffTightIsoCJPtMVARachNew_->SetLineColor(kBlue+1);
  FinalEffTightIsoRECOPtMVARachNew_->SetLineColor(kGreen+1);
  FinalEffCJPtMVARachNew_->SetLineColor(kBlue+1);
  FinalEffRECOPtMVARachNew_->SetLineColor(kGreen+1);

  FinalEffLooseIsoCJPtMVARachNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffLooseIsoRECOPtMVARachNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffMedIsoCJPtMVARachNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffMedIsoRECOPtMVARachNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffTightIsoCJPtMVARachNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffTightIsoRECOPtMVARachNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffCJPtMVARachNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffRECOPtMVARachNew_->GetXaxis()->SetTitle("p_{T}");

  FinalEffLooseIsoCJPtMVARachNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffLooseIsoRECOPtMVARachNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffMedIsoCJPtMVARachNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffMedIsoRECOPtMVARachNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffTightIsoCJPtMVARachNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");
  FinalEffTightIsoRECOPtMVARachNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");

  FinalEffLooseIsoCJPtMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffLooseIsoRECOPtMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoCJPtMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOPtMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoCJPtMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOPtMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffCJPtMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffRECOPtMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoCJPtMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffLooseIsoRECOPtMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoCJPtMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOPtMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoCJPtMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOPtMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffCJPtMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffRECOPtMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoCJPtMVARachNew_->SetLineWidth(3);
  FinalEffLooseIsoRECOPtMVARachNew_->SetLineWidth(3);
  FinalEffMedIsoCJPtMVARachNew_->SetLineWidth(3);
  FinalEffMedIsoRECOPtMVARachNew_->SetLineWidth(3);
  FinalEffTightIsoCJPtMVARachNew_->SetLineWidth(3);
  FinalEffTightIsoRECOPtMVARachNew_->SetLineWidth(3);
  FinalEffCJPtMVARachNew_->SetLineWidth(3);
  FinalEffRECOPtMVARachNew_->SetLineWidth(3);


  FinalEffLooseIsoCJdRMVARachNew_->SetMarkerColor(kBlue+1);
  FinalEffLooseIsoRECOdRMVARachNew_->SetMarkerColor(kGreen+1);
  FinalEffMedIsoCJdRMVARachNew_->SetMarkerColor(kBlue+1);
  FinalEffMedIsoRECOdRMVARachNew_->SetMarkerColor(kGreen+1);
  FinalEffTightIsoCJdRMVARachNew_->SetMarkerColor(kBlue+1);
  FinalEffTightIsoRECOdRMVARachNew_->SetMarkerColor(kGreen+1);
  FinalEffCJdRMVARachNew_->SetMarkerColor(kBlue+1);
  FinalEffRECOdRMVARachNew_->SetMarkerColor(kGreen+1);

  FinalEffLooseIsoCJdRMVARachNew_->SetMarkerSize(.07);
  FinalEffLooseIsoRECOdRMVARachNew_->SetMarkerSize(.07);
  FinalEffMedIsoCJdRMVARachNew_->SetMarkerSize(.07);
  FinalEffMedIsoRECOdRMVARachNew_->SetMarkerSize(.07);
  FinalEffTightIsoCJdRMVARachNew_->SetMarkerSize(.07);
  FinalEffTightIsoRECOdRMVARachNew_->SetMarkerSize(.07);
  FinalEffCJdRMVARachNew_->SetMarkerSize(.07);
  FinalEffRECOdRMVARachNew_->SetMarkerSize(.07);

  FinalEffLooseIsoCJdRMVARachNew_->SetLineColor(kBlue+1);
  FinalEffLooseIsoRECOdRMVARachNew_->SetLineColor(kGreen+1);
  FinalEffMedIsoCJdRMVARachNew_->SetLineColor(kBlue+1);
  FinalEffMedIsoRECOdRMVARachNew_->SetLineColor(kGreen+1);
  FinalEffTightIsoCJdRMVARachNew_->SetLineColor(kBlue+1);
  FinalEffTightIsoRECOdRMVARachNew_->SetLineColor(kGreen+1);
  FinalEffCJdRMVARachNew_->SetLineColor(kBlue+1);
  FinalEffRECOdRMVARachNew_->SetLineColor(kGreen+1);

  FinalEffLooseIsoCJdRMVARachNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffLooseIsoRECOdRMVARachNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffMedIsoCJdRMVARachNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffMedIsoRECOdRMVARachNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffTightIsoCJdRMVARachNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffTightIsoRECOdRMVARachNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffCJdRMVARachNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffRECOdRMVARachNew_->GetXaxis()->SetTitle("#DeltaR");

  FinalEffLooseIsoCJdRMVARachNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffLooseIsoRECOdRMVARachNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffMedIsoCJdRMVARachNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffMedIsoRECOdRMVARachNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffTightIsoCJdRMVARachNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");
  FinalEffTightIsoRECOdRMVARachNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");

  FinalEffLooseIsoCJdRMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffLooseIsoRECOdRMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoCJdRMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOdRMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoCJdRMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOdRMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffCJdRMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffRECOdRMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoCJdRMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffLooseIsoRECOdRMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoCJdRMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOdRMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoCJdRMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOdRMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffCJdRMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffRECOdRMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoCJdRMVARachNew_->SetLineWidth(3);
  FinalEffLooseIsoRECOdRMVARachNew_->SetLineWidth(3);
  FinalEffMedIsoCJdRMVARachNew_->SetLineWidth(3);
  FinalEffMedIsoRECOdRMVARachNew_->SetLineWidth(3);
  FinalEffTightIsoCJdRMVARachNew_->SetLineWidth(3);
  FinalEffTightIsoRECOdRMVARachNew_->SetLineWidth(3);
  FinalEffCJdRMVARachNew_->SetLineWidth(3);
  FinalEffRECOdRMVARachNew_->SetLineWidth(3);


  
  FinalEffLooseIsoCJPtGenMVARachNew_->SetMarkerColor(kBlue+1);
  FinalEffLooseIsoRECOPtGenMVARachNew_->SetMarkerColor(kGreen+1);
  FinalEffMedIsoCJPtGenMVARachNew_->SetMarkerColor(kBlue+1);
  FinalEffMedIsoRECOPtGenMVARachNew_->SetMarkerColor(kGreen+1);
  FinalEffTightIsoCJPtGenMVARachNew_->SetMarkerColor(kBlue+1);
  FinalEffTightIsoRECOPtGenMVARachNew_->SetMarkerColor(kGreen+1);
  FinalEffCJPtGenMVARachNew_->SetMarkerColor(kBlue+1);
  FinalEffRECOPtGenMVARachNew_->SetMarkerColor(kGreen+1);

  FinalEffLooseIsoCJPtGenMVARachNew_->SetMarkerSize(.07);
  FinalEffLooseIsoRECOPtGenMVARachNew_->SetMarkerSize(.07);
  FinalEffMedIsoCJPtGenMVARachNew_->SetMarkerSize(.07);
  FinalEffMedIsoRECOPtGenMVARachNew_->SetMarkerSize(.07);
  FinalEffTightIsoCJPtGenMVARachNew_->SetMarkerSize(.07);
  FinalEffTightIsoRECOPtGenMVARachNew_->SetMarkerSize(.07);
  FinalEffCJPtGenMVARachNew_->SetMarkerSize(.07);
  FinalEffRECOPtGenMVARachNew_->SetMarkerSize(.07);

  FinalEffLooseIsoCJPtGenMVARachNew_->SetLineColor(kBlue+1);
  FinalEffLooseIsoRECOPtGenMVARachNew_->SetLineColor(kGreen+1);
  FinalEffMedIsoCJPtGenMVARachNew_->SetLineColor(kBlue+1);
  FinalEffMedIsoRECOPtGenMVARachNew_->SetLineColor(kGreen+1);
  FinalEffTightIsoCJPtGenMVARachNew_->SetLineColor(kBlue+1);
  FinalEffTightIsoRECOPtGenMVARachNew_->SetLineColor(kGreen+1);
  FinalEffCJPtGenMVARachNew_->SetLineColor(kBlue+1);
  FinalEffRECOPtGenMVARachNew_->SetLineColor(kGreen+1);

  FinalEffLooseIsoCJPtGenMVARachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffLooseIsoRECOPtGenMVARachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffMedIsoCJPtGenMVARachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffMedIsoRECOPtGenMVARachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffTightIsoCJPtGenMVARachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffTightIsoRECOPtGenMVARachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffCJPtGenMVARachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffRECOPtGenMVARachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");

  FinalEffLooseIsoCJPtGenMVARachNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffLooseIsoRECOPtGenMVARachNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffMedIsoCJPtGenMVARachNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffMedIsoRECOPtGenMVARachNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffTightIsoCJPtGenMVARachNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");
  FinalEffTightIsoRECOPtGenMVARachNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");
 
  FinalEffLooseIsoCJPtGenMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffLooseIsoRECOPtGenMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoCJPtGenMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOPtGenMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoCJPtGenMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOPtGenMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffCJPtGenMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffRECOPtGenMVARachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoCJPtGenMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffLooseIsoRECOPtGenMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoCJPtGenMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOPtGenMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoCJPtGenMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOPtGenMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffCJPtGenMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffRECOPtGenMVARachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoCJPtGenMVARachNew_->SetLineWidth(3);
  FinalEffLooseIsoRECOPtGenMVARachNew_->SetLineWidth(3);
  FinalEffMedIsoCJPtGenMVARachNew_->SetLineWidth(3);
  FinalEffMedIsoRECOPtGenMVARachNew_->SetLineWidth(3);
  FinalEffTightIsoCJPtGenMVARachNew_->SetLineWidth(3);
  FinalEffTightIsoRECOPtGenMVARachNew_->SetLineWidth(3);
  FinalEffCJPtGenMVARachNew_->SetLineWidth(3);
  FinalEffRECOPtGenMVARachNew_->SetLineWidth(3);



  //Set Colors for New Gen Matching New DM's
  FinalEffLooseIsoCJPtKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffLooseIsoRECOPtKyleNew_->SetMarkerColor(kRed+1);
  FinalEffMedIsoCJPtKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffMedIsoRECOPtKyleNew_->SetMarkerColor(kRed+1);
  FinalEffTightIsoCJPtKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffTightIsoRECOPtKyleNew_->SetMarkerColor(kRed+1);
  FinalEffCJPtKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffRECOPtKyleNew_->SetMarkerColor(kRed+1);

  FinalEffLooseIsoCJPtKyleNew_->SetMarkerSize(.07);
  FinalEffLooseIsoRECOPtKyleNew_->SetMarkerSize(.07);
  FinalEffMedIsoCJPtKyleNew_->SetMarkerSize(.07);
  FinalEffMedIsoRECOPtKyleNew_->SetMarkerSize(.07);
  FinalEffTightIsoCJPtKyleNew_->SetMarkerSize(.07);
  FinalEffTightIsoRECOPtKyleNew_->SetMarkerSize(.07);
  FinalEffCJPtKyleNew_->SetMarkerSize(.07);
  FinalEffRECOPtKyleNew_->SetMarkerSize(.07);

  FinalEffLooseIsoCJPtKyleNew_->SetLineColor(kViolet-5);
  FinalEffLooseIsoRECOPtKyleNew_->SetLineColor(kRed+1);
  FinalEffMedIsoCJPtKyleNew_->SetLineColor(kViolet-5);
  FinalEffMedIsoRECOPtKyleNew_->SetLineColor(kRed+1);
  FinalEffTightIsoCJPtKyleNew_->SetLineColor(kViolet-5);
  FinalEffTightIsoRECOPtKyleNew_->SetLineColor(kRed+1);
  FinalEffCJPtKyleNew_->SetLineColor(kViolet-5);
  FinalEffRECOPtKyleNew_->SetLineColor(kRed+1);

  FinalEffLooseIsoCJPtKyleNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffLooseIsoRECOPtKyleNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffMedIsoCJPtKyleNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffMedIsoRECOPtKyleNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffTightIsoCJPtKyleNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffTightIsoRECOPtKyleNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffCJPtKyleNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffRECOPtKyleNew_->GetXaxis()->SetTitle("p_{T}");

  FinalEffLooseIsoCJPtKyleNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffLooseIsoRECOPtKyleNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffMedIsoCJPtKyleNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffMedIsoRECOPtKyleNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffTightIsoCJPtKyleNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");
  FinalEffTightIsoRECOPtKyleNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");
  
  FinalEffLooseIsoCJPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffLooseIsoRECOPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoCJPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoCJPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffCJPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffRECOPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoCJPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffLooseIsoRECOPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoCJPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoCJPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffCJPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffRECOPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  
  FinalEffLooseIsoCJPtKyleNew_->SetLineWidth(3);
  FinalEffLooseIsoRECOPtKyleNew_->SetLineWidth(3);
  FinalEffMedIsoCJPtKyleNew_->SetLineWidth(3);
  FinalEffMedIsoRECOPtKyleNew_->SetLineWidth(3);
  FinalEffTightIsoCJPtKyleNew_->SetLineWidth(3);
  FinalEffTightIsoRECOPtKyleNew_->SetLineWidth(3);
  FinalEffCJPtKyleNew_->SetLineWidth(3);
  FinalEffRECOPtKyleNew_->SetLineWidth(3);



  FinalEffLooseIsoCJdRKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffLooseIsoRECOdRKyleNew_->SetMarkerColor(kRed+1);
  FinalEffMedIsoCJdRKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffMedIsoRECOdRKyleNew_->SetMarkerColor(kRed+1);
  FinalEffTightIsoCJdRKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffTightIsoRECOdRKyleNew_->SetMarkerColor(kRed+1);
  FinalEffCJdRKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffRECOdRKyleNew_->SetMarkerColor(kRed+1);

  FinalEffLooseIsoCJdRKyleNew_->SetMarkerSize(.07);
  FinalEffLooseIsoRECOdRKyleNew_->SetMarkerSize(.07);
  FinalEffMedIsoCJdRKyleNew_->SetMarkerSize(.07);
  FinalEffMedIsoRECOdRKyleNew_->SetMarkerSize(.07);
  FinalEffTightIsoCJdRKyleNew_->SetMarkerSize(.07);
  FinalEffTightIsoRECOdRKyleNew_->SetMarkerSize(.07);
  FinalEffCJdRKyleNew_->SetMarkerSize(.07);
  FinalEffRECOdRKyleNew_->SetMarkerSize(.07);

  FinalEffLooseIsoCJdRKyleNew_->SetLineColor(kViolet-5);
  FinalEffLooseIsoRECOdRKyleNew_->SetLineColor(kRed+1);
  FinalEffMedIsoCJdRKyleNew_->SetLineColor(kViolet-5);
  FinalEffMedIsoRECOdRKyleNew_->SetLineColor(kRed+1);
  FinalEffTightIsoCJdRKyleNew_->SetLineColor(kViolet-5);
  FinalEffTightIsoRECOdRKyleNew_->SetLineColor(kRed+1);
  FinalEffCJdRKyleNew_->SetLineColor(kViolet-5);
  FinalEffRECOdRKyleNew_->SetLineColor(kRed+1);

  FinalEffLooseIsoCJdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffLooseIsoRECOdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffMedIsoCJdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffMedIsoRECOdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffTightIsoCJdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffTightIsoRECOdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffCJdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffRECOdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  
  FinalEffLooseIsoCJdRKyleNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffLooseIsoRECOdRKyleNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffMedIsoCJdRKyleNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffMedIsoRECOdRKyleNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffTightIsoCJdRKyleNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");
  FinalEffTightIsoRECOdRKyleNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");

  FinalEffLooseIsoCJdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffLooseIsoRECOdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoCJdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoCJdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffCJdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffRECOdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoCJdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffLooseIsoRECOdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoCJdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoCJdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffCJdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffRECOdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoCJdRKyleNew_->SetLineWidth(3);
  FinalEffLooseIsoRECOdRKyleNew_->SetLineWidth(3);
  FinalEffMedIsoCJdRKyleNew_->SetLineWidth(3);
  FinalEffMedIsoRECOdRKyleNew_->SetLineWidth(3);
  FinalEffTightIsoCJdRKyleNew_->SetLineWidth(3);
  FinalEffTightIsoRECOdRKyleNew_->SetLineWidth(3);
  FinalEffCJdRKyleNew_->SetLineWidth(3);
  FinalEffRECOdRKyleNew_->SetLineWidth(3);




  FinalEffLooseIsoCJPtGenKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffLooseIsoRECOPtGenKyleNew_->SetMarkerColor(kRed+1);
  FinalEffMedIsoCJPtGenKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffMedIsoRECOPtGenKyleNew_->SetMarkerColor(kRed+1);
  FinalEffTightIsoCJPtGenKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffTightIsoRECOPtGenKyleNew_->SetMarkerColor(kRed+1);
  FinalEffCJPtGenKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffRECOPtGenKyleNew_->SetMarkerColor(kRed+1);

  FinalEffLooseIsoCJPtGenKyleNew_->SetMarkerSize(.07);
  FinalEffLooseIsoRECOPtGenKyleNew_->SetMarkerSize(.07);
  FinalEffMedIsoCJPtGenKyleNew_->SetMarkerSize(.07);
  FinalEffMedIsoRECOPtGenKyleNew_->SetMarkerSize(.07);
  FinalEffTightIsoCJPtGenKyleNew_->SetMarkerSize(.07);
  FinalEffTightIsoRECOPtGenKyleNew_->SetMarkerSize(.07);
  FinalEffCJPtGenKyleNew_->SetMarkerSize(.07);
  FinalEffRECOPtGenKyleNew_->SetMarkerSize(.07);

  FinalEffLooseIsoCJPtGenKyleNew_->SetLineColor(kViolet-5);
  FinalEffLooseIsoRECOPtGenKyleNew_->SetLineColor(kRed+1);
  FinalEffMedIsoCJPtGenKyleNew_->SetLineColor(kViolet-5);
  FinalEffMedIsoRECOPtGenKyleNew_->SetLineColor(kRed+1);
  FinalEffTightIsoCJPtGenKyleNew_->SetLineColor(kViolet-5);
  FinalEffTightIsoRECOPtGenKyleNew_->SetLineColor(kRed+1);
  FinalEffCJPtGenKyleNew_->SetLineColor(kViolet-5);
  FinalEffRECOPtGenKyleNew_->SetLineColor(kRed+1);

  FinalEffLooseIsoCJPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffLooseIsoRECOPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffMedIsoCJPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffMedIsoRECOPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffTightIsoCJPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffTightIsoRECOPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffCJPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffRECOPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  
  FinalEffLooseIsoCJPtGenKyleNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffLooseIsoRECOPtGenKyleNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffMedIsoCJPtGenKyleNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffMedIsoRECOPtGenKyleNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffTightIsoCJPtGenKyleNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");
  FinalEffTightIsoRECOPtGenKyleNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");

  FinalEffLooseIsoCJPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffLooseIsoRECOPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoCJPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoCJPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffCJPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffRECOPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoCJPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffLooseIsoRECOPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoCJPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoCJPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffCJPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffRECOPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoCJPtGenKyleNew_->SetLineWidth(3);
  FinalEffLooseIsoRECOPtGenKyleNew_->SetLineWidth(3);
  FinalEffMedIsoCJPtGenKyleNew_->SetLineWidth(3);
  FinalEffMedIsoRECOPtGenKyleNew_->SetLineWidth(3);
  FinalEffTightIsoCJPtGenKyleNew_->SetLineWidth(3);
  FinalEffTightIsoRECOPtGenKyleNew_->SetLineWidth(3);
  FinalEffCJPtGenKyleNew_->SetLineWidth(3);
  FinalEffRECOPtGenKyleNew_->SetLineWidth(3);

  //Set Colors for New Gen Matching New DM's
  FinalEffLooseIsoRECOPtDY_->SetMarkerColor(kBlack);
  FinalEffMedIsoRECOPtDY_->SetMarkerColor(kBlack);
  FinalEffTightIsoRECOPtDY_->SetMarkerColor(kBlack);
  FinalEffRECOPtDY_->SetMarkerColor(kBlack);

  FinalEffLooseIsoRECOPtDY_->SetMarkerSize(.07);
  FinalEffMedIsoRECOPtDY_->SetMarkerSize(.07);
  FinalEffTightIsoRECOPtDY_->SetMarkerSize(.07);
  FinalEffRECOPtDY_->SetMarkerSize(.07);

  FinalEffLooseIsoRECOPtDY_->SetLineColor(kBlack);
  FinalEffMedIsoRECOPtDY_->SetLineColor(kBlack);
  FinalEffTightIsoRECOPtDY_->SetLineColor(kBlack);
  FinalEffRECOPtDY_->SetLineColor(kBlack);

  FinalEffLooseIsoRECOPtDY_->GetXaxis()->SetTitle("p_{T}");
  FinalEffMedIsoRECOPtDY_->GetXaxis()->SetTitle("p_{T}");
  FinalEffTightIsoRECOPtDY_->GetXaxis()->SetTitle("p_{T}");
  FinalEffRECOPtDY_->GetXaxis()->SetTitle("p_{T}");

  FinalEffLooseIsoRECOPtDY_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffMedIsoRECOPtDY_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffTightIsoRECOPtDY_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");

  FinalEffLooseIsoRECOPtDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOPtDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOPtDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffRECOPtDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoRECOPtDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOPtDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOPtDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffRECOPtDY_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoRECOPtDY_->SetLineWidth(3);
  FinalEffMedIsoRECOPtDY_->SetLineWidth(3);
  FinalEffTightIsoRECOPtDY_->SetLineWidth(3);
  FinalEffRECOPtDY_->SetLineWidth(3);



  FinalEffLooseIsoRECOdRDY_->SetMarkerColor(kBlack);
  FinalEffMedIsoRECOdRDY_->SetMarkerColor(kBlack);
  FinalEffTightIsoRECOdRDY_->SetMarkerColor(kBlack);
  FinalEffRECOdRDY_->SetMarkerColor(kBlack);
  
  FinalEffLooseIsoRECOdRDY_->SetMarkerSize(.07);
  FinalEffMedIsoRECOdRDY_->SetMarkerSize(.07);
  FinalEffTightIsoRECOdRDY_->SetMarkerSize(.07);
  FinalEffRECOdRDY_->SetMarkerSize(.07);
  
  FinalEffLooseIsoRECOdRDY_->SetLineColor(kBlack);
  FinalEffMedIsoRECOdRDY_->SetLineColor(kBlack);
  FinalEffTightIsoRECOdRDY_->SetLineColor(kBlack);
  FinalEffRECOdRDY_->SetLineColor(kBlack);

  FinalEffLooseIsoRECOdRDY_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffMedIsoRECOdRDY_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffTightIsoRECOdRDY_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffRECOdRDY_->GetXaxis()->SetTitle("#DeltaR");

  FinalEffLooseIsoRECOdRDY_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffMedIsoRECOdRDY_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffTightIsoRECOdRDY_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");

  FinalEffLooseIsoRECOdRDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOdRDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOdRDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffRECOdRDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoRECOdRDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOdRDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOdRDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffRECOdRDY_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoRECOdRDY_->SetLineWidth(3);
  FinalEffMedIsoRECOdRDY_->SetLineWidth(3);
  FinalEffTightIsoRECOdRDY_->SetLineWidth(3);
  FinalEffRECOdRDY_->SetLineWidth(3);



  FinalEffLooseIsoRECOPtGenDY_->SetMarkerColor(kBlack);
  FinalEffMedIsoRECOPtGenDY_->SetMarkerColor(kBlack);
  FinalEffTightIsoRECOPtGenDY_->SetMarkerColor(kBlack);
  FinalEffRECOPtGenDY_->SetMarkerColor(kBlack);
  
  FinalEffLooseIsoRECOPtGenDY_->SetMarkerSize(.07);
  FinalEffMedIsoRECOPtGenDY_->SetMarkerSize(.07);
  FinalEffTightIsoRECOPtGenDY_->SetMarkerSize(.07);
  FinalEffRECOPtGenDY_->SetMarkerSize(.07);
  
  FinalEffLooseIsoRECOPtGenDY_->SetLineColor(kBlack);
  FinalEffMedIsoRECOPtGenDY_->SetLineColor(kBlack);
  FinalEffTightIsoRECOPtGenDY_->SetLineColor(kBlack);
  FinalEffRECOPtGenDY_->SetLineColor(kBlack);

  FinalEffLooseIsoRECOPtGenDY_->GetXaxis()->SetTitle("Gen Visilbe P_{T}");
  FinalEffMedIsoRECOPtGenDY_->GetXaxis()->SetTitle("Gen Visilbe P_{T}");
  FinalEffTightIsoRECOPtGenDY_->GetXaxis()->SetTitle("Gen Visilbe P_{T}");
  FinalEffRECOPtGenDY_->GetXaxis()->SetTitle("Gen Visilbe P_{T}");

  FinalEffLooseIsoRECOPtGenDY_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DM Findng + GM / GM)");
  FinalEffMedIsoRECOPtGenDY_->GetYaxis()->SetTitle("#epsilon (Med Iso + DM Findng + GM / GM)");
  FinalEffTightIsoRECOPtGenDY_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DM Findng + GM / GM)");

  FinalEffLooseIsoRECOPtGenDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOPtGenDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOPtGenDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffRECOPtGenDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoRECOPtGenDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOPtGenDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOPtGenDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffRECOPtGenDY_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoRECOPtGenDY_->SetLineWidth(3);
  FinalEffMedIsoRECOPtGenDY_->SetLineWidth(3);
  FinalEffTightIsoRECOPtGenDY_->SetLineWidth(3);
  FinalEffRECOPtGenDY_->SetLineWidth(3);

cout << "Attributes set." << endl;  

  leg = new TLegend(0.1,0.7,0.25,0.9);
  leg->AddEntry(FinalEffLooseIsoRECOPtGenDY_,   "Drell Yan Z-TT","L");
  leg->AddEntry(FinalEffRECOPtGenMVARachNew_, "No  CJ,New Gen","L");
  leg->AddEntry(FinalEffRECOPtGenKyleNew_, "No  CJ,Old Gen","L");
  leg->AddEntry(FinalEffCJPtGenMVARachNew_,   "Yes CJ,New Gen","L");
  leg->AddEntry(FinalEffCJPtGenKyleNew_,   "Yes CJ,Old Gen","L");

  legMatch = new TLegend(0.1,0.7,0.25,0.9);
  legMatch->AddEntry(FinalEffRECOPtGenMVARachNew_, "No  CJ,New Gen","L");
  legMatch->AddEntry(FinalEffCJPtGenMVARachNew_,   "Yes CJ,New Gen","L");



  LoosePtCanvas.cd();
  FinalEffLooseIsoRECOPtDY_->Draw();
  FinalEffLooseIsoCJPtMVARachNew_->Draw("SAME");
  FinalEffLooseIsoRECOPtMVARachNew_->Draw("SAME");
  FinalEffLooseIsoCJPtKyleNew_->Draw("SAME");
  FinalEffLooseIsoRECOPtKyleNew_->Draw("SAME");
  leg->Draw();

  LoosePtNewGenMatchCanvas.cd();
  FinalEffLooseIsoRECOPtDY_->Draw();
  FinalEffLooseIsoCJPtMVARachNew_->Draw("SAME");
  FinalEffLooseIsoRECOPtMVARachNew_->Draw("SAME");
  legMatch->Draw();

  MedPtCanvas.cd();
  FinalEffMedIsoRECOPtDY_->Draw();
  FinalEffMedIsoCJPtMVARachNew_->Draw("SAME");
  FinalEffMedIsoRECOPtMVARachNew_->Draw("SAME");
  FinalEffMedIsoCJPtKyleNew_->Draw("SAME");
  FinalEffMedIsoRECOPtKyleNew_->Draw("SAME");
  leg->Draw();

  MedPtNewGenMatchCanvas.cd();
  FinalEffMedIsoRECOPtDY_->Draw();
  FinalEffMedIsoCJPtMVARachNew_->Draw("SAME");
  FinalEffMedIsoRECOPtMVARachNew_->Draw("SAME");
  legMatch->Draw();
  

  TightPtCanvas.cd();
  FinalEffTightIsoRECOPtDY_->Draw();
  FinalEffTightIsoCJPtMVARachNew_->Draw("SAME");
  FinalEffTightIsoRECOPtMVARachNew_->Draw("SAME");
  FinalEffTightIsoCJPtKyleNew_->Draw("SAME");
  FinalEffTightIsoRECOPtKyleNew_->Draw("SAME");
  leg->Draw();

  TightPtNewGenMatchCanvas.cd();
  FinalEffTightIsoRECOPtDY_->Draw();
  FinalEffTightIsoCJPtMVARachNew_->Draw("SAME");
  FinalEffTightIsoRECOPtMVARachNew_->Draw("SAME");
  legMatch->Draw();
  

  DMPtCanvas.cd();
  FinalEffRECOPtDY_->Draw();
  FinalEffCJPtMVARachNew_->Draw("SAME");
  FinalEffRECOPtMVARachNew_->Draw("SAME");
  FinalEffCJPtKyleNew_->Draw("SAME");
  FinalEffRECOPtKyleNew_->Draw("SAME");
  leg->Draw();

  DMPtNewGenMatchCanvas.cd();
  FinalEffRECOPtDY_->Draw();
  FinalEffCJPtMVARachNew_->Draw("SAME");
  FinalEffRECOPtMVARachNew_->Draw("SAME");
  legMatch->Draw();
  


  LoosedRCanvas.cd();
  FinalEffLooseIsoCJdRMVARachNew_->Draw();
  FinalEffLooseIsoRECOdRMVARachNew_->Draw("SAME");
  FinalEffLooseIsoCJdRKyleNew_->Draw("SAME");
  FinalEffLooseIsoRECOdRKyleNew_->Draw("SAME");
  FinalEffLooseIsoRECOdRDY_->Draw("SAME");
  leg->Draw();

  LoosedRNewGenMatchCanvas.cd();
  FinalEffLooseIsoCJdRMVARachNew_->Draw();
  FinalEffLooseIsoRECOdRMVARachNew_->Draw("SAME");
  FinalEffLooseIsoRECOdRDY_->Draw("SAME");
  legMatch->Draw();
  
 
  MeddRCanvas.cd();
  FinalEffMedIsoCJdRMVARachNew_->Draw();
  FinalEffMedIsoRECOdRMVARachNew_->Draw("SAME");
  FinalEffMedIsoCJdRKyleNew_->Draw("SAME");
  FinalEffMedIsoRECOdRKyleNew_->Draw("SAME");
  FinalEffMedIsoRECOdRDY_->Draw("SAME");
  leg->Draw();
 
  MeddRNewGenMatchCanvas.cd();
  FinalEffMedIsoCJdRMVARachNew_->Draw();
  FinalEffMedIsoRECOdRMVARachNew_->Draw("SAME");
  FinalEffMedIsoRECOdRDY_->Draw("SAME");
  legMatch->Draw();
 
  TightdRCanvas.cd();
  FinalEffTightIsoCJdRMVARachNew_->Draw();
  FinalEffTightIsoRECOdRMVARachNew_->Draw("SAME");
  FinalEffTightIsoCJdRKyleNew_->Draw("SAME");
  FinalEffTightIsoRECOdRKyleNew_->Draw("SAME");
  FinalEffTightIsoRECOdRDY_->Draw("SAME");
  leg->Draw();

  TightdRNewGenMatchCanvas.cd();
  FinalEffTightIsoCJdRMVARachNew_->Draw();
  FinalEffTightIsoRECOdRMVARachNew_->Draw("SAME");
  FinalEffTightIsoRECOdRDY_->Draw("SAME");
  legMatch->Draw();

  DMdRCanvas.cd();
  FinalEffCJdRMVARachNew_->Draw();
  FinalEffRECOdRMVARachNew_->Draw("SAME");
  FinalEffCJdRKyleNew_->Draw("SAME");
  FinalEffRECOdRKyleNew_->Draw("SAME");
  FinalEffRECOdRDY_->Draw("SAME");
  leg->Draw();

  DMdRNewGenMatchCanvas.cd();
  FinalEffCJdRMVARachNew_->Draw();
  FinalEffRECOdRMVARachNew_->Draw("SAME");
  FinalEffRECOdRDY_->Draw("SAME");
  legMatch->Draw();
 
  LoosePtGenCanvas.cd();
  FinalEffLooseIsoRECOPtGenDY_->Draw();
  FinalEffLooseIsoCJPtGenMVARachNew_->Draw("SAME");
  FinalEffLooseIsoRECOPtGenMVARachNew_->Draw("SAME");
  FinalEffLooseIsoCJPtGenKyleNew_->Draw("SAME");
  FinalEffLooseIsoRECOPtGenKyleNew_->Draw("SAME");
  leg->Draw();

  LoosePtGenNewGenMatchCanvas.cd();
  FinalEffLooseIsoRECOPtGenDY_->Draw();
  FinalEffLooseIsoCJPtGenMVARachNew_->Draw("SAME");
  FinalEffLooseIsoRECOPtGenMVARachNew_->Draw("SAME");
  legMatch->Draw();
 
  MedPtGenCanvas.cd();
  FinalEffMedIsoRECOPtGenDY_->Draw();
  FinalEffMedIsoCJPtGenMVARachNew_->Draw("SAME");
  FinalEffMedIsoRECOPtGenMVARachNew_->Draw("SAME");
  FinalEffMedIsoCJPtGenKyleNew_->Draw("SAME");
  FinalEffMedIsoRECOPtGenKyleNew_->Draw("SAME");
  leg->Draw();

  MedPtGenNewGenMatchCanvas.cd();
  FinalEffMedIsoRECOPtGenDY_->Draw();
  FinalEffMedIsoCJPtGenMVARachNew_->Draw("SAME");
  FinalEffMedIsoRECOPtGenMVARachNew_->Draw("SAME");
  legMatch->Draw();
 
  TightPtGenCanvas.cd();
  FinalEffTightIsoRECOPtGenDY_->Draw();
  FinalEffTightIsoCJPtGenMVARachNew_->Draw("SAME");
  FinalEffTightIsoRECOPtGenMVARachNew_->Draw("SAME");
  FinalEffTightIsoCJPtGenKyleNew_->Draw("SAME");
  FinalEffTightIsoRECOPtGenKyleNew_->Draw("SAME");
  leg->Draw("SAME");

  TightPtGenNewGenMatchCanvas.cd();
  FinalEffTightIsoRECOPtGenDY_->Draw();
  FinalEffTightIsoCJPtGenMVARachNew_->Draw("SAME");
  FinalEffTightIsoRECOPtGenMVARachNew_->Draw("SAME");
  legMatch->Draw("SAME");

  DMPtGenCanvas.cd();
  FinalEffRECOPtGenDY_->Draw();
  FinalEffCJPtGenMVARachNew_->Draw("SAME");
  FinalEffRECOPtGenMVARachNew_->Draw("SAME");
  FinalEffCJPtGenKyleNew_->Draw("SAME");
  FinalEffRECOPtGenKyleNew_->Draw("SAME");
  leg->Draw("SAME");

  DMPtGenNewGenMatchCanvas.cd();
  FinalEffRECOPtGenDY_->Draw();
  FinalEffCJPtGenMVARachNew_->Draw("SAME");
  FinalEffRECOPtGenMVARachNew_->Draw("SAME");
  legMatch->Draw();

 
cout << "Histograms Drawn" << endl;

  outFile->cd();

  LoosePtCanvas.Write();
  MedPtCanvas.Write();
  TightPtCanvas.Write();
  DMPtCanvas.Write();

  LoosedRCanvas.Write();
  MeddRCanvas.Write();
  TightdRCanvas.Write();
  DMdRCanvas.Write();

  LoosePtGenCanvas.Write();
  MedPtGenCanvas.Write();
  TightPtGenCanvas.Write();
  DMPtGenCanvas.Write();

  LoosePtNewGenMatchCanvas.Write();
  MedPtNewGenMatchCanvas.Write();
  TightPtNewGenMatchCanvas.Write();
  DMPtNewGenMatchCanvas.Write();

  LoosedRNewGenMatchCanvas.Write();
  MeddRNewGenMatchCanvas.Write();
  TightdRNewGenMatchCanvas.Write();
  DMdRNewGenMatchCanvas.Write();

  LoosePtGenNewGenMatchCanvas.Write();
  MedPtGenNewGenMatchCanvas.Write();
  TightPtGenNewGenMatchCanvas.Write();
  DMPtGenNewGenMatchCanvas.Write();

  MatchedCJPtMVACanvasRachNew->Write();
  MatchedRECOPtMVACanvasRachNew->Write();
  MatchedCJdRMVACanvasRachNew->Write();
  MatchedRECOdRMVACanvasRachNew->Write();
  MatchedCJPtGenMVACanvasRachNew->Write();
  MatchedRECOPtGenMVACanvasRachNew->Write();

  MatchedCJPtCanvasKyleNew->Write();
  MatchedRECOPtCanvasKyleNew->Write();
  MatchedCJdRCanvasKyleNew->Write();
  MatchedRECOdRCanvasKyleNew->Write();
  MatchedCJPtGenCanvasKyleNew->Write();
  MatchedRECOPtGenCanvasKyleNew->Write();

  outFile->Write();
  outFile->Close();

cout << "end" << endl;

}//rootMacro_BBA_combine
