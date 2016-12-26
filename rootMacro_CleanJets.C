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


void rootMacro_CleanJets()
{

  gStyle->SetOptStat(kFALSE);
  gStyle->SetEndErrorSize(7);

/*
  //New DMs
  TFile infileCJNew("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/ggH125a9_NewDecayIDCJ_NewDM_OverDM_ak5_JUL14/ggH125a9_NewDecayIDCJ_NewDM_OverDM_ak5_JUL14_Plots.root");
  TFile infileRECONew("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/ggH125a9_NewDecayIDRECO_NewDM_OverDM_ak5_JUL14/ggH125a9_NewDecayIDRECO_NewDM_OverDM_ak5_JUL14_Plots.root");
  TFile infileKyleNew("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/ggH125a9_OldDecayID_NewDMFind_OverDM_ak5_JUL14/ggH125a9_OldDecayID_NewDMFind_OverDM_ak5_JUL14_Plots.root");
  TFile infileDY("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/DYJetsToLL_M-50_300000Events_NewDM_JUL7/DYJetsToLL_M-50_300000Events_NewDM_JUL7_Plots.root");
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/CombinedPlots/combHist_CleanJets_h125a9_NewDM_ak5.root", "RECREATE");
*/

  //Old DMs
  TFile infileCJNew("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/ggH125a9_NewDecayIDCJ_OldDM_OverDM_JUL14/ggH125a9_NewDecayIDCJ_OldDM_OverDM_JUL14_Plots.root");
  TFile infileRECONew("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/ggH125a9_NewDecayIDRECO_OldDM_OverDM_JUL14/ggH125a9_NewDecayIDRECO_OldDM_OverDM_JUL14_Plots.root");
  TFile infileKyleNew("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/ggH125a9_OldDecayID_OldDMFind_OverDM_JUL14/ggH125a9_OldDecayID_OldDMFind_OverDM_JUL14_Plots.root");
  TFile infileDY("/home/kyletos/Downloads/RootFiles/AnalyzerDirectories/DYJetsToLL_M-50_300000Events_OldDM_JUL7/DYJetsToLL_M-50_300000Events_OldDM_JUL7_Plots.root");
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/CombinedPlots/combHist_CleanJets_h125a9_OldDM.root", "RECREATE");

cout << "Files Created" << endl;

  // CJ/RECO Comparison histograms
  TCanvas *MatchedLooseIsoCJPtCanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedLooseIsoCJPt");
  TCanvas *MatchedLooseIsoRECOPtCanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedLooseIsoRECOPt");
  TCanvas *MatchedMedIsoCJPtCanvasRachNew     = (TCanvas*)infileCJNew.Get("MatchedMedIsoCJPt");
  TCanvas *MatchedMedIsoRECOPtCanvasRachNew   = (TCanvas*)infileRECONew.Get("MatchedMedIsoRECOPt");
  TCanvas *MatchedTightIsoCJPtCanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedTightIsoCJPt");
  TCanvas *MatchedTightIsoRECOPtCanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedTightIsoRECOPt");
  TCanvas *MatchedDMFindCJPtCanvasRachNew     = (TCanvas*)infileCJNew.Get("MatchedDMFindCJPt");
  TCanvas *MatchedDMFindRECOPtCanvasRachNew   = (TCanvas*)infileRECONew.Get("MatchedDMFindRECOPt");
  TCanvas *MatchedCJPtCanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedCJPt");
  TCanvas *MatchedRECOPtCanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedRECOPt");
  
  TCanvas *MatchedLooseIsoCJdRCanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedLooseIsoCJdR");
  TCanvas *MatchedLooseIsoRECOdRCanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedLooseIsoRECOdR");
  TCanvas *MatchedMedIsoCJdRCanvasRachNew     = (TCanvas*)infileCJNew.Get("MatchedMedIsoCJdR");
  TCanvas *MatchedMedIsoRECOdRCanvasRachNew   = (TCanvas*)infileRECONew.Get("MatchedMedIsoRECOdR");
  TCanvas *MatchedTightIsoCJdRCanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedTightIsoCJdR");
  TCanvas *MatchedTightIsoRECOdRCanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedTightIsoRECOdR");
  TCanvas *MatchedDMFindCJdRCanvasRachNew     = (TCanvas*)infileCJNew.Get("MatchedDMFindCJdR");
  TCanvas *MatchedDMFindRECOdRCanvasRachNew   = (TCanvas*)infileRECONew.Get("MatchedDMFindRECOdR");
  TCanvas *MatchedCJdRCanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedCJdR");
  TCanvas *MatchedRECOdRCanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedRECOdR");

  TCanvas *MatchedLooseIsoCJPtGenCanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedLooseIsoCJPtGen");
  TCanvas *MatchedLooseIsoRECOPtGenCanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedLooseIsoRECOPtGen");
  TCanvas *MatchedMedIsoCJPtGenCanvasRachNew     = (TCanvas*)infileCJNew.Get("MatchedMedIsoCJPtGen");
  TCanvas *MatchedMedIsoRECOPtGenCanvasRachNew   = (TCanvas*)infileRECONew.Get("MatchedMedIsoRECOPtGen");
  TCanvas *MatchedTightIsoCJPtGenCanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedTightIsoCJPtGen");
  TCanvas *MatchedTightIsoRECOPtGenCanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedTightIsoRECOPtGen");
  TCanvas *MatchedDMFindCJPtGenCanvasRachNew     = (TCanvas*)infileCJNew.Get("MatchedDMFindCJPtGen");
  TCanvas *MatchedDMFindRECOPtGenCanvasRachNew   = (TCanvas*)infileRECONew.Get("MatchedDMFindRECOPtGen");
  TCanvas *MatchedCJPtGenCanvasRachNew   = (TCanvas*)infileCJNew.Get("MatchedCJPtGen");
  TCanvas *MatchedRECOPtGenCanvasRachNew = (TCanvas*)infileRECONew.Get("MatchedRECOPtGen");

  // Kyle Gen Matching New DM 
  TCanvas *MatchedLooseIsoCJPtCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedLooseIsoCJPt");
  TCanvas *MatchedLooseIsoRECOPtCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedLooseIsoRECOPt");
  TCanvas *MatchedMedIsoCJPtCanvasKyleNew     = (TCanvas*)infileKyleNew.Get("MatchedMedIsoCJPt");
  TCanvas *MatchedMedIsoRECOPtCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedMedIsoRECOPt");
  TCanvas *MatchedTightIsoCJPtCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedTightIsoCJPt");
  TCanvas *MatchedTightIsoRECOPtCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedTightIsoRECOPt");
  TCanvas *MatchedDMFindCJPtCanvasKyleNew     = (TCanvas*)infileKyleNew.Get("MatchedDMFindCJPt");
  TCanvas *MatchedDMFindRECOPtCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedDMFindRECOPt");
  TCanvas *MatchedCJPtCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedCJPt");
  TCanvas *MatchedRECOPtCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedRECOPt");

  TCanvas *MatchedLooseIsoCJdRCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedLooseIsoCJdR");
  TCanvas *MatchedLooseIsoRECOdRCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedLooseIsoRECOdR");
  TCanvas *MatchedMedIsoCJdRCanvasKyleNew     = (TCanvas*)infileKyleNew.Get("MatchedMedIsoCJdR");
  TCanvas *MatchedMedIsoRECOdRCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedMedIsoRECOdR");
  TCanvas *MatchedTightIsoCJdRCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedTightIsoCJdR");
  TCanvas *MatchedTightIsoRECOdRCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedTightIsoRECOdR");
  TCanvas *MatchedDMFindCJdRCanvasKyleNew     = (TCanvas*)infileKyleNew.Get("MatchedDMFindCJdR");
  TCanvas *MatchedDMFindRECOdRCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedDMFindRECOdR");
  TCanvas *MatchedCJdRCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedCJdR");
  TCanvas *MatchedRECOdRCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedRECOdR");

  TCanvas *MatchedLooseIsoCJPtGenCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedLooseIsoCJPtGen");
  TCanvas *MatchedLooseIsoRECOPtGenCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedLooseIsoRECOPtGen");
  TCanvas *MatchedMedIsoCJPtGenCanvasKyleNew     = (TCanvas*)infileKyleNew.Get("MatchedMedIsoCJPtGen");
  TCanvas *MatchedMedIsoRECOPtGenCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedMedIsoRECOPtGen");
  TCanvas *MatchedTightIsoCJPtGenCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedTightIsoCJPtGen");
  TCanvas *MatchedTightIsoRECOPtGenCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedTightIsoRECOPtGen");
  TCanvas *MatchedDMFindCJPtGenCanvasKyleNew     = (TCanvas*)infileKyleNew.Get("MatchedDMFindCJPtGen");
  TCanvas *MatchedDMFindRECOPtGenCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedDMFindRECOPtGen");
  TCanvas *MatchedCJPtGenCanvasKyleNew   = (TCanvas*)infileKyleNew.Get("MatchedCJPtGen");
  TCanvas *MatchedRECOPtGenCanvasKyleNew = (TCanvas*)infileKyleNew.Get("MatchedRECOPtGen");

  // DY
  TCanvas *MatchedLooseIsoRECOPtCanvasDY = (TCanvas*)infileDY.Get("MatchedLooseIsoRECOPt");
  TCanvas *MatchedMedIsoRECOPtCanvasDY   = (TCanvas*)infileDY.Get("MatchedMedIsoRECOPt");
  TCanvas *MatchedTightIsoRECOPtCanvasDY = (TCanvas*)infileDY.Get("MatchedTightIsoRECOPt");
  TCanvas *MatchedDMFindRECOPtCanvasDY   = (TCanvas*)infileDY.Get("MatchedDMFindRECOPt");
  TCanvas *MatchedRECOPtCanvasDY = (TCanvas*)infileDY.Get("MatchedRECOPt");

  TCanvas *MatchedLooseIsoRECOdRCanvasDY = (TCanvas*)infileDY.Get("MatchedLooseIsoRECOdR");
  TCanvas *MatchedMedIsoRECOdRCanvasDY   = (TCanvas*)infileDY.Get("MatchedMedIsoRECOdR");
  TCanvas *MatchedTightIsoRECOdRCanvasDY = (TCanvas*)infileDY.Get("MatchedTightIsoRECOdR");
  TCanvas *MatchedDMFindRECOdRCanvasDY   = (TCanvas*)infileDY.Get("MatchedDMFindRECOdR");
  TCanvas *MatchedRECOdRCanvasDY = (TCanvas*)infileDY.Get("MatchedRECOdR");

  TCanvas *MatchedLooseIsoRECOPtGenCanvasDY = (TCanvas*)infileDY.Get("MatchedLooseIsoRECOPtGen");
  TCanvas *MatchedMedIsoRECOPtGenCanvasDY   = (TCanvas*)infileDY.Get("MatchedMedIsoRECOPtGen");
  TCanvas *MatchedTightIsoRECOPtGenCanvasDY = (TCanvas*)infileDY.Get("MatchedTightIsoRECOPtGen");
  TCanvas *MatchedDMFindRECOPtGenCanvasDY   = (TCanvas*)infileDY.Get("MatchedDMFindRECOPtGen");
  TCanvas *MatchedRECOPtGenCanvasDY = (TCanvas*)infileDY.Get("MatchedRECOPtGen");

cout << "Got Canvases" << endl;

  // Getting the histograms for the New gen matching and DM New
  TH1F* MatchedLooseIsoCJPtRachNew_   = (TH1F*)MatchedLooseIsoCJPtCanvasRachNew->GetPrimitive("MatchedLooseIsoCJPt");
  TH1F* MatchedLooseIsoRECOPtRachNew_ = (TH1F*)MatchedLooseIsoRECOPtCanvasRachNew->GetPrimitive("MatchedLooseIsoRECOPt");
  TH1F* MatchedMedIsoCJPtRachNew_     = (TH1F*)MatchedMedIsoCJPtCanvasRachNew->GetPrimitive("MatchedMedIsoCJPt");
  TH1F* MatchedMedIsoRECOPtRachNew_   = (TH1F*)MatchedMedIsoRECOPtCanvasRachNew->GetPrimitive("MatchedMedIsoRECOPt");
  TH1F* MatchedTightIsoCJPtRachNew_   = (TH1F*)MatchedTightIsoCJPtCanvasRachNew->GetPrimitive("MatchedTightIsoCJPt");
  TH1F* MatchedTightIsoRECOPtRachNew_ = (TH1F*)MatchedTightIsoRECOPtCanvasRachNew->GetPrimitive("MatchedTightIsoRECOPt");
  TH1F* MatchedDMFindCJPtRachNew_     = (TH1F*)MatchedDMFindCJPtCanvasRachNew->GetPrimitive("MatchedDMFindCJPt");
  TH1F* MatchedDMFindRECOPtRachNew_   = (TH1F*)MatchedDMFindRECOPtCanvasRachNew->GetPrimitive("MatchedDMFindRECOPt");
  TH1F* MatchedCJPtRachNew_   = (TH1F*)MatchedCJPtCanvasRachNew->GetPrimitive("MatchedCJPt");
  TH1F* MatchedRECOPtRachNew_ = (TH1F*)MatchedRECOPtCanvasRachNew->GetPrimitive("MatchedRECOPt");

  TH1F* MatchedLooseIsoCJdRRachNew_   = (TH1F*)MatchedLooseIsoCJdRCanvasRachNew->GetPrimitive("MatchedLooseIsoCJdR");
  TH1F* MatchedLooseIsoRECOdRRachNew_ = (TH1F*)MatchedLooseIsoRECOdRCanvasRachNew->GetPrimitive("MatchedLooseIsoRECOdR");
  TH1F* MatchedMedIsoCJdRRachNew_     = (TH1F*)MatchedMedIsoCJdRCanvasRachNew->GetPrimitive("MatchedMedIsoCJdR");
  TH1F* MatchedMedIsoRECOdRRachNew_   = (TH1F*)MatchedMedIsoRECOdRCanvasRachNew->GetPrimitive("MatchedMedIsoRECOdR");
  TH1F* MatchedTightIsoCJdRRachNew_   = (TH1F*)MatchedTightIsoCJdRCanvasRachNew->GetPrimitive("MatchedTightIsoCJdR");
  TH1F* MatchedTightIsoRECOdRRachNew_ = (TH1F*)MatchedTightIsoRECOdRCanvasRachNew->GetPrimitive("MatchedTightIsoRECOdR");
  TH1F* MatchedDMFindCJdRRachNew_     = (TH1F*)MatchedDMFindCJdRCanvasRachNew->GetPrimitive("MatchedDMFindCJdR");
  TH1F* MatchedDMFindRECOdRRachNew_   = (TH1F*)MatchedDMFindRECOdRCanvasRachNew->GetPrimitive("MatchedDMFindRECOdR");
  TH1F* MatchedCJdRRachNew_   = (TH1F*)MatchedCJdRCanvasRachNew->GetPrimitive("MatchedCJdR");
  TH1F* MatchedRECOdRRachNew_ = (TH1F*)MatchedRECOdRCanvasRachNew->GetPrimitive("MatchedRECOdR");

  TH1F* MatchedLooseIsoCJPtGenRachNew_   = (TH1F*)MatchedLooseIsoCJPtGenCanvasRachNew->GetPrimitive("MatchedLooseIsoCJPtGen");
  TH1F* MatchedLooseIsoRECOPtGenRachNew_ = (TH1F*)MatchedLooseIsoRECOPtGenCanvasRachNew->GetPrimitive("MatchedLooseIsoRECOPtGen");
  TH1F* MatchedMedIsoCJPtGenRachNew_     = (TH1F*)MatchedMedIsoCJPtGenCanvasRachNew->GetPrimitive("MatchedMedIsoCJPtGen");
  TH1F* MatchedMedIsoRECOPtGenRachNew_   = (TH1F*)MatchedMedIsoRECOPtGenCanvasRachNew->GetPrimitive("MatchedMedIsoRECOPtGen");
  TH1F* MatchedTightIsoCJPtGenRachNew_   = (TH1F*)MatchedTightIsoCJPtGenCanvasRachNew->GetPrimitive("MatchedTightIsoCJPtGen");
  TH1F* MatchedTightIsoRECOPtGenRachNew_ = (TH1F*)MatchedTightIsoRECOPtGenCanvasRachNew->GetPrimitive("MatchedTightIsoRECOPtGen");
  TH1F* MatchedDMFindCJPtGenRachNew_     = (TH1F*)MatchedDMFindCJPtGenCanvasRachNew->GetPrimitive("MatchedDMFindCJPtGen");
  TH1F* MatchedDMFindRECOPtGenRachNew_   = (TH1F*)MatchedDMFindRECOPtGenCanvasRachNew->GetPrimitive("MatchedDMFindRECOPtGen");
  TH1F* MatchedCJPtGenRachNew_   = (TH1F*)MatchedCJPtGenCanvasRachNew->GetPrimitive("MatchedCJPtGen");
  TH1F* MatchedRECOPtGenRachNew_ = (TH1F*)MatchedRECOPtGenCanvasRachNew->GetPrimitive("MatchedRECOPtGen");
  
// Getting the histograms for the DM New
  TH1F* MatchedLooseIsoCJPtKyleNew_   = (TH1F*)MatchedLooseIsoCJPtCanvasKyleNew->GetPrimitive("MatchedLooseIsoCJPt");
  TH1F* MatchedLooseIsoRECOPtKyleNew_ = (TH1F*)MatchedLooseIsoRECOPtCanvasKyleNew->GetPrimitive("MatchedLooseIsoRECOPt");
  TH1F* MatchedMedIsoCJPtKyleNew_     = (TH1F*)MatchedMedIsoCJPtCanvasKyleNew->GetPrimitive("MatchedMedIsoCJPt");
  TH1F* MatchedMedIsoRECOPtKyleNew_   = (TH1F*)MatchedMedIsoRECOPtCanvasKyleNew->GetPrimitive("MatchedMedIsoRECOPt");
  TH1F* MatchedTightIsoCJPtKyleNew_   = (TH1F*)MatchedTightIsoCJPtCanvasKyleNew->GetPrimitive("MatchedTightIsoCJPt");
  TH1F* MatchedTightIsoRECOPtKyleNew_ = (TH1F*)MatchedTightIsoRECOPtCanvasKyleNew->GetPrimitive("MatchedTightIsoRECOPt");
  TH1F* MatchedDMFindCJPtKyleNew_     = (TH1F*)MatchedDMFindCJPtCanvasKyleNew->GetPrimitive("MatchedDMFindCJPt");
  TH1F* MatchedDMFindRECOPtKyleNew_   = (TH1F*)MatchedDMFindRECOPtCanvasKyleNew->GetPrimitive("MatchedDMFindRECOPt");
  TH1F* MatchedCJPtKyleNew_   = (TH1F*)MatchedCJPtCanvasKyleNew->GetPrimitive("MatchedCJPt");
  TH1F* MatchedRECOPtKyleNew_ = (TH1F*)MatchedRECOPtCanvasKyleNew->GetPrimitive("MatchedRECOPt");

  TH1F* MatchedLooseIsoCJdRKyleNew_   = (TH1F*)MatchedLooseIsoCJdRCanvasKyleNew->GetPrimitive("MatchedLooseIsoCJdR");
  TH1F* MatchedLooseIsoRECOdRKyleNew_ = (TH1F*)MatchedLooseIsoRECOdRCanvasKyleNew->GetPrimitive("MatchedLooseIsoRECOdR");
  TH1F* MatchedMedIsoCJdRKyleNew_     = (TH1F*)MatchedMedIsoCJdRCanvasKyleNew->GetPrimitive("MatchedMedIsoCJdR");
  TH1F* MatchedMedIsoRECOdRKyleNew_   = (TH1F*)MatchedMedIsoRECOdRCanvasKyleNew->GetPrimitive("MatchedMedIsoRECOdR");
  TH1F* MatchedTightIsoCJdRKyleNew_   = (TH1F*)MatchedTightIsoCJdRCanvasKyleNew->GetPrimitive("MatchedTightIsoCJdR");
  TH1F* MatchedTightIsoRECOdRKyleNew_ = (TH1F*)MatchedTightIsoRECOdRCanvasKyleNew->GetPrimitive("MatchedTightIsoRECOdR");
  TH1F* MatchedDMFindCJdRKyleNew_     = (TH1F*)MatchedDMFindCJdRCanvasKyleNew->GetPrimitive("MatchedDMFindCJdR");
  TH1F* MatchedDMFindRECOdRKyleNew_   = (TH1F*)MatchedDMFindRECOdRCanvasKyleNew->GetPrimitive("MatchedDMFindRECOdR");
  TH1F* MatchedCJdRKyleNew_   = (TH1F*)MatchedCJdRCanvasKyleNew->GetPrimitive("MatchedCJdR");
  TH1F* MatchedRECOdRKyleNew_ = (TH1F*)MatchedRECOdRCanvasKyleNew->GetPrimitive("MatchedRECOdR");

  TH1F* MatchedLooseIsoCJPtGenKyleNew_   = (TH1F*)MatchedLooseIsoCJPtGenCanvasKyleNew->GetPrimitive("MatchedLooseIsoCJPtGen");
  TH1F* MatchedLooseIsoRECOPtGenKyleNew_ = (TH1F*)MatchedLooseIsoRECOPtGenCanvasKyleNew->GetPrimitive("MatchedLooseIsoRECOPtGen");
  TH1F* MatchedMedIsoCJPtGenKyleNew_     = (TH1F*)MatchedMedIsoCJPtGenCanvasKyleNew->GetPrimitive("MatchedMedIsoCJPtGen");
  TH1F* MatchedMedIsoRECOPtGenKyleNew_   = (TH1F*)MatchedMedIsoRECOPtGenCanvasKyleNew->GetPrimitive("MatchedMedIsoRECOPtGen");
  TH1F* MatchedTightIsoCJPtGenKyleNew_   = (TH1F*)MatchedTightIsoCJPtGenCanvasKyleNew->GetPrimitive("MatchedTightIsoCJPtGen");
  TH1F* MatchedTightIsoRECOPtGenKyleNew_ = (TH1F*)MatchedTightIsoRECOPtGenCanvasKyleNew->GetPrimitive("MatchedTightIsoRECOPtGen");
  TH1F* MatchedDMFindCJPtGenKyleNew_     = (TH1F*)MatchedDMFindCJPtGenCanvasKyleNew->GetPrimitive("MatchedDMFindCJPtGen");
  TH1F* MatchedDMFindRECOPtGenKyleNew_   = (TH1F*)MatchedDMFindRECOPtGenCanvasKyleNew->GetPrimitive("MatchedDMFindRECOPtGen");
  TH1F* MatchedCJPtGenKyleNew_   = (TH1F*)MatchedCJPtGenCanvasKyleNew->GetPrimitive("MatchedCJPtGen");
  TH1F* MatchedRECOPtGenKyleNew_ = (TH1F*)MatchedRECOPtGenCanvasKyleNew->GetPrimitive("MatchedRECOPtGen");

// Getting the histograms for the DM New
  TH1F* MatchedLooseIsoRECOPtDY_ = (TH1F*)MatchedLooseIsoRECOPtCanvasDY->GetPrimitive("MatchedLooseIsoRECOPt");
  TH1F* MatchedMedIsoRECOPtDY_   = (TH1F*)MatchedMedIsoRECOPtCanvasDY->GetPrimitive("MatchedMedIsoRECOPt");
  TH1F* MatchedTightIsoRECOPtDY_ = (TH1F*)MatchedTightIsoRECOPtCanvasDY->GetPrimitive("MatchedTightIsoRECOPt");
  TH1F* MatchedDMFindRECOPtDY_   = (TH1F*)MatchedDMFindRECOPtCanvasDY->GetPrimitive("MatchedDMFindRECOPt");
  TH1F* MatchedRECOPtDY_ = (TH1F*)MatchedRECOPtCanvasDY->GetPrimitive("MatchedRECOPt");

  TH1F* MatchedLooseIsoRECOdRDY_ = (TH1F*)MatchedLooseIsoRECOdRCanvasDY->GetPrimitive("MatchedLooseIsoRECOdR");
  TH1F* MatchedMedIsoRECOdRDY_   = (TH1F*)MatchedMedIsoRECOdRCanvasDY->GetPrimitive("MatchedMedIsoRECOdR");
  TH1F* MatchedTightIsoRECOdRDY_ = (TH1F*)MatchedTightIsoRECOdRCanvasDY->GetPrimitive("MatchedTightIsoRECOdR");
  TH1F* MatchedDMFindRECOdRDY_   = (TH1F*)MatchedDMFindRECOdRCanvasDY->GetPrimitive("MatchedDMFindRECOdR");
  TH1F* MatchedRECOdRDY_ = (TH1F*)MatchedRECOdRCanvasDY->GetPrimitive("MatchedRECOdR");

  TH1F* MatchedLooseIsoRECOPtGenDY_ = (TH1F*)MatchedLooseIsoRECOPtGenCanvasDY->GetPrimitive("MatchedLooseIsoRECOPtGen");
  TH1F* MatchedMedIsoRECOPtGenDY_   = (TH1F*)MatchedMedIsoRECOPtGenCanvasDY->GetPrimitive("MatchedMedIsoRECOPtGen");
  TH1F* MatchedTightIsoRECOPtGenDY_ = (TH1F*)MatchedTightIsoRECOPtGenCanvasDY->GetPrimitive("MatchedTightIsoRECOPtGen");
  TH1F* MatchedDMFindRECOPtGenDY_   = (TH1F*)MatchedDMFindRECOPtGenCanvasDY->GetPrimitive("MatchedDMFindRECOPtGen");
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
  TGraphAsymmErrors* FinalEffLooseIsoRECOPtRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOPtRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOPtRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindRECOPtRachNew_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoCJPtRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoCJPtRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoCJPtRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindCJPtRachNew_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoRECOdRRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOdRRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOdRRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindRECOdRRachNew_ = new TGraphAsymmErrors(30);
  
  TGraphAsymmErrors* FinalEffLooseIsoCJdRRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoCJdRRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoCJdRRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindCJdRRachNew_ = new TGraphAsymmErrors(30);
  
  TGraphAsymmErrors* FinalEffLooseIsoRECOPtGenRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOPtGenRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOPtGenRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindRECOPtGenRachNew_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoCJPtGenRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoCJPtGenRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoCJPtGenRachNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindCJPtGenRachNew_ = new TGraphAsymmErrors(30);

  // To divide histograms for efficiency with Old Gen Matching New DM's
  TGraphAsymmErrors* FinalEffLooseIsoRECOPtKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOPtKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOPtKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindRECOPtKyleNew_ = new TGraphAsymmErrors(30);
  
  TGraphAsymmErrors* FinalEffLooseIsoCJPtKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoCJPtKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoCJPtKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindCJPtKyleNew_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoRECOdRKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOdRKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOdRKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindRECOdRKyleNew_ = new TGraphAsymmErrors(30);
  
  TGraphAsymmErrors* FinalEffLooseIsoCJdRKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoCJdRKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoCJdRKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindCJdRKyleNew_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoRECOPtGenKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOPtGenKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOPtGenKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindRECOPtGenKyleNew_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoCJPtGenKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoCJPtGenKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoCJPtGenKyleNew_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindCJPtGenKyleNew_ = new TGraphAsymmErrors(30);

  // To divide histograms for efficiency with Old Gen Matching New DM's
  TGraphAsymmErrors* FinalEffLooseIsoRECOPtDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOPtDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOPtDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindRECOPtDY_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoRECOdRDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOdRDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOdRDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindRECOdRDY_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalEffLooseIsoRECOPtGenDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffMedIsoRECOPtGenDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffTightIsoRECOPtGenDY_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalEffDMFindRECOPtGenDY_ = new TGraphAsymmErrors(30);

  // To divide histograms for efficiency with new Gen Matching New DM's
  FinalEffLooseIsoRECOPtRachNew_->Divide(MatchedLooseIsoRECOPtRachNew_, MatchedRECOPtRachNew_);
  FinalEffMedIsoRECOPtRachNew_->Divide(MatchedMedIsoRECOPtRachNew_,     MatchedRECOPtRachNew_);
  FinalEffTightIsoRECOPtRachNew_->Divide(MatchedTightIsoRECOPtRachNew_, MatchedRECOPtRachNew_);
  FinalEffDMFindRECOPtRachNew_->Divide(MatchedDMFindRECOPtRachNew_,     MatchedRECOPtRachNew_);
  FinalEffLooseIsoCJPtRachNew_->Divide(MatchedLooseIsoCJPtRachNew_, MatchedCJPtRachNew_);
  FinalEffMedIsoCJPtRachNew_->Divide(MatchedMedIsoCJPtRachNew_,     MatchedCJPtRachNew_);
  FinalEffTightIsoCJPtRachNew_->Divide(MatchedTightIsoCJPtRachNew_, MatchedCJPtRachNew_);
  FinalEffDMFindCJPtRachNew_->Divide(MatchedDMFindCJPtRachNew_,     MatchedCJPtRachNew_);

  FinalEffLooseIsoRECOdRRachNew_->Divide(MatchedLooseIsoRECOdRRachNew_, MatchedRECOdRRachNew_);
  FinalEffMedIsoRECOdRRachNew_->Divide(MatchedMedIsoRECOdRRachNew_,     MatchedRECOdRRachNew_);
  FinalEffTightIsoRECOdRRachNew_->Divide(MatchedTightIsoRECOdRRachNew_, MatchedRECOdRRachNew_);
  FinalEffDMFindRECOdRRachNew_->Divide(MatchedDMFindRECOdRRachNew_,     MatchedRECOdRRachNew_);
  FinalEffLooseIsoCJdRRachNew_->Divide(MatchedLooseIsoCJdRRachNew_, MatchedCJdRRachNew_);
  FinalEffMedIsoCJdRRachNew_->Divide(MatchedMedIsoCJdRRachNew_,     MatchedCJdRRachNew_);
  FinalEffTightIsoCJdRRachNew_->Divide(MatchedTightIsoCJdRRachNew_, MatchedCJdRRachNew_);
  FinalEffDMFindCJdRRachNew_->Divide(MatchedDMFindCJdRRachNew_,     MatchedCJdRRachNew_);

  FinalEffLooseIsoRECOPtGenRachNew_->Divide(MatchedLooseIsoRECOPtGenRachNew_, MatchedRECOPtGenRachNew_);
  FinalEffMedIsoRECOPtGenRachNew_->Divide(MatchedMedIsoRECOPtGenRachNew_,     MatchedRECOPtGenRachNew_);
  FinalEffTightIsoRECOPtGenRachNew_->Divide(MatchedTightIsoRECOPtGenRachNew_, MatchedRECOPtGenRachNew_);
  FinalEffDMFindRECOPtGenRachNew_->Divide(MatchedDMFindRECOPtGenRachNew_,     MatchedRECOPtGenRachNew_);
  FinalEffLooseIsoCJPtGenRachNew_->Divide(MatchedLooseIsoCJPtGenRachNew_, MatchedCJPtGenRachNew_);
  FinalEffMedIsoCJPtGenRachNew_->Divide(MatchedMedIsoCJPtGenRachNew_,     MatchedCJPtGenRachNew_);
  FinalEffTightIsoCJPtGenRachNew_->Divide(MatchedTightIsoCJPtGenRachNew_, MatchedCJPtGenRachNew_);
  FinalEffDMFindCJPtGenRachNew_->Divide(MatchedDMFindCJPtGenRachNew_,     MatchedCJPtGenRachNew_);
  
  // To divide histograms for efficiency with OLD Gen Matching New DM's 
  FinalEffLooseIsoRECOPtKyleNew_->Divide(MatchedLooseIsoRECOPtKyleNew_, MatchedRECOPtKyleNew_);
  FinalEffMedIsoRECOPtKyleNew_->Divide(MatchedMedIsoRECOPtKyleNew_,     MatchedRECOPtKyleNew_);
  FinalEffTightIsoRECOPtKyleNew_->Divide(MatchedTightIsoRECOPtKyleNew_, MatchedRECOPtKyleNew_);
  FinalEffDMFindRECOPtKyleNew_->Divide(MatchedDMFindRECOPtKyleNew_,     MatchedRECOPtKyleNew_);
  FinalEffLooseIsoCJPtKyleNew_->Divide(MatchedLooseIsoCJPtKyleNew_, MatchedCJPtKyleNew_);
  FinalEffMedIsoCJPtKyleNew_->Divide(MatchedMedIsoCJPtKyleNew_,     MatchedCJPtKyleNew_);
  FinalEffTightIsoCJPtKyleNew_->Divide(MatchedTightIsoCJPtKyleNew_, MatchedCJPtKyleNew_);
  FinalEffDMFindCJPtKyleNew_->Divide(MatchedDMFindCJPtKyleNew_,     MatchedCJPtKyleNew_);

  FinalEffLooseIsoRECOdRKyleNew_->Divide(MatchedLooseIsoRECOdRKyleNew_, MatchedRECOdRKyleNew_);
  FinalEffMedIsoRECOdRKyleNew_->Divide(MatchedMedIsoRECOdRKyleNew_,     MatchedRECOdRKyleNew_);
  FinalEffTightIsoRECOdRKyleNew_->Divide(MatchedTightIsoRECOdRKyleNew_, MatchedRECOdRKyleNew_);
  FinalEffDMFindRECOdRKyleNew_->Divide(MatchedDMFindRECOdRKyleNew_,     MatchedRECOdRKyleNew_);
  FinalEffLooseIsoCJdRKyleNew_->Divide(MatchedLooseIsoCJdRKyleNew_, MatchedCJdRKyleNew_);
  FinalEffMedIsoCJdRKyleNew_->Divide(MatchedMedIsoCJdRKyleNew_,     MatchedCJdRKyleNew_);
  FinalEffTightIsoCJdRKyleNew_->Divide(MatchedTightIsoCJdRKyleNew_, MatchedCJdRKyleNew_);
  FinalEffDMFindCJdRKyleNew_->Divide(MatchedDMFindCJdRKyleNew_,     MatchedCJdRKyleNew_);

  FinalEffLooseIsoRECOPtGenKyleNew_->Divide(MatchedLooseIsoRECOPtGenKyleNew_, MatchedRECOPtGenKyleNew_);
  FinalEffMedIsoRECOPtGenKyleNew_->Divide(MatchedMedIsoRECOPtGenKyleNew_,     MatchedRECOPtGenKyleNew_);
  FinalEffTightIsoRECOPtGenKyleNew_->Divide(MatchedTightIsoRECOPtGenKyleNew_, MatchedRECOPtGenKyleNew_);
  FinalEffDMFindRECOPtGenKyleNew_->Divide(MatchedDMFindRECOPtGenKyleNew_,     MatchedRECOPtGenKyleNew_);
  FinalEffLooseIsoCJPtGenKyleNew_->Divide(MatchedLooseIsoCJPtGenKyleNew_, MatchedCJPtGenKyleNew_);
  FinalEffMedIsoCJPtGenKyleNew_->Divide(MatchedMedIsoCJPtGenKyleNew_,     MatchedCJPtGenKyleNew_);
  FinalEffTightIsoCJPtGenKyleNew_->Divide(MatchedTightIsoCJPtGenKyleNew_, MatchedCJPtGenKyleNew_);
  FinalEffDMFindCJPtGenKyleNew_->Divide(MatchedDMFindCJPtGenKyleNew_,     MatchedCJPtGenKyleNew_);

  // To divide histograms for efficiency with OLD Gen Matching New DM's 
  FinalEffLooseIsoRECOPtDY_->Divide(MatchedLooseIsoRECOPtDY_, MatchedRECOPtDY_);
  FinalEffMedIsoRECOPtDY_->Divide(MatchedMedIsoRECOPtDY_,     MatchedRECOPtDY_);
  FinalEffTightIsoRECOPtDY_->Divide(MatchedTightIsoRECOPtDY_, MatchedRECOPtDY_);
  FinalEffDMFindRECOPtDY_->Divide(MatchedDMFindRECOPtDY_,     MatchedRECOPtDY_);

  FinalEffLooseIsoRECOdRDY_->Divide(MatchedLooseIsoRECOdRDY_, MatchedRECOdRDY_);
  FinalEffMedIsoRECOdRDY_->Divide(MatchedMedIsoRECOdRDY_,     MatchedRECOdRDY_);
  FinalEffTightIsoRECOdRDY_->Divide(MatchedTightIsoRECOdRDY_, MatchedRECOdRDY_);
  FinalEffDMFindRECOdRDY_->Divide(MatchedDMFindRECOdRDY_,     MatchedRECOdRDY_);

  FinalEffLooseIsoRECOPtGenDY_->Divide(MatchedLooseIsoRECOPtGenDY_, MatchedRECOPtGenDY_);
  FinalEffMedIsoRECOPtGenDY_->Divide(MatchedMedIsoRECOPtGenDY_,     MatchedRECOPtGenDY_);
  FinalEffTightIsoRECOPtGenDY_->Divide(MatchedTightIsoRECOPtGenDY_, MatchedRECOPtGenDY_);
  FinalEffDMFindRECOPtGenDY_->Divide(MatchedDMFindRECOPtGenDY_,     MatchedRECOPtGenDY_);

  //Set Colors for New Gen Matching New DM's
  FinalEffLooseIsoCJPtRachNew_->SetMarkerColor(kBlue+1);
  FinalEffLooseIsoRECOPtRachNew_->SetMarkerColor(kGreen+1);
  FinalEffMedIsoCJPtRachNew_->SetMarkerColor(kBlue+1);
  FinalEffMedIsoRECOPtRachNew_->SetMarkerColor(kGreen+1);
  FinalEffTightIsoCJPtRachNew_->SetMarkerColor(kBlue+1);
  FinalEffTightIsoRECOPtRachNew_->SetMarkerColor(kGreen+1);
  FinalEffDMFindCJPtRachNew_->SetMarkerColor(kBlue+1);
  FinalEffDMFindRECOPtRachNew_->SetMarkerColor(kGreen+1);

  FinalEffLooseIsoCJPtRachNew_->SetMarkerSize(.07);
  FinalEffLooseIsoRECOPtRachNew_->SetMarkerSize(.07);
  FinalEffMedIsoCJPtRachNew_->SetMarkerSize(.07);
  FinalEffMedIsoRECOPtRachNew_->SetMarkerSize(.07);
  FinalEffTightIsoCJPtRachNew_->SetMarkerSize(.07);
  FinalEffTightIsoRECOPtRachNew_->SetMarkerSize(.07);
  FinalEffDMFindCJPtRachNew_->SetMarkerSize(.07);
  FinalEffDMFindRECOPtRachNew_->SetMarkerSize(.07);

  FinalEffLooseIsoCJPtRachNew_->SetLineColor(kBlue+1);
  FinalEffLooseIsoRECOPtRachNew_->SetLineColor(kGreen+1);
  FinalEffMedIsoCJPtRachNew_->SetLineColor(kBlue+1);
  FinalEffMedIsoRECOPtRachNew_->SetLineColor(kGreen+1);
  FinalEffTightIsoCJPtRachNew_->SetLineColor(kBlue+1);
  FinalEffTightIsoRECOPtRachNew_->SetLineColor(kGreen+1);
  FinalEffDMFindCJPtRachNew_->SetLineColor(kBlue+1);
  FinalEffDMFindRECOPtRachNew_->SetLineColor(kGreen+1);

  FinalEffLooseIsoCJPtRachNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffLooseIsoRECOPtRachNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffMedIsoCJPtRachNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffMedIsoRECOPtRachNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffTightIsoCJPtRachNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffTightIsoRECOPtRachNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffDMFindCJPtRachNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffDMFindRECOPtRachNew_->GetXaxis()->SetTitle("p_{T}");

  FinalEffLooseIsoCJPtRachNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffLooseIsoRECOPtRachNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffMedIsoCJPtRachNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffMedIsoRECOPtRachNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffTightIsoCJPtRachNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffTightIsoRECOPtRachNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffDMFindCJPtRachNew_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");
  FinalEffDMFindRECOPtRachNew_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");

  FinalEffLooseIsoCJPtRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffLooseIsoRECOPtRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoCJPtRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOPtRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoCJPtRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOPtRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindCJPtRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindRECOPtRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoCJPtRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffLooseIsoRECOPtRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoCJPtRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOPtRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoCJPtRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOPtRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindCJPtRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindRECOPtRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoCJPtRachNew_->SetLineWidth(3);
  FinalEffLooseIsoRECOPtRachNew_->SetLineWidth(3);
  FinalEffMedIsoCJPtRachNew_->SetLineWidth(3);
  FinalEffMedIsoRECOPtRachNew_->SetLineWidth(3);
  FinalEffTightIsoCJPtRachNew_->SetLineWidth(3);
  FinalEffTightIsoRECOPtRachNew_->SetLineWidth(3);
  FinalEffDMFindCJPtRachNew_->SetLineWidth(3);
  FinalEffDMFindRECOPtRachNew_->SetLineWidth(3);


  FinalEffLooseIsoCJdRRachNew_->SetMarkerColor(kBlue+1);
  FinalEffLooseIsoRECOdRRachNew_->SetMarkerColor(kGreen+1);
  FinalEffMedIsoCJdRRachNew_->SetMarkerColor(kBlue+1);
  FinalEffMedIsoRECOdRRachNew_->SetMarkerColor(kGreen+1);
  FinalEffTightIsoCJdRRachNew_->SetMarkerColor(kBlue+1);
  FinalEffTightIsoRECOdRRachNew_->SetMarkerColor(kGreen+1);
  FinalEffDMFindCJdRRachNew_->SetMarkerColor(kBlue+1);
  FinalEffDMFindRECOdRRachNew_->SetMarkerColor(kGreen+1);

  FinalEffLooseIsoCJdRRachNew_->SetMarkerSize(.07);
  FinalEffLooseIsoRECOdRRachNew_->SetMarkerSize(.07);
  FinalEffMedIsoCJdRRachNew_->SetMarkerSize(.07);
  FinalEffMedIsoRECOdRRachNew_->SetMarkerSize(.07);
  FinalEffTightIsoCJdRRachNew_->SetMarkerSize(.07);
  FinalEffTightIsoRECOdRRachNew_->SetMarkerSize(.07);
  FinalEffDMFindCJdRRachNew_->SetMarkerSize(.07);
  FinalEffDMFindRECOdRRachNew_->SetMarkerSize(.07);

  FinalEffLooseIsoCJdRRachNew_->SetLineColor(kBlue+1);
  FinalEffLooseIsoRECOdRRachNew_->SetLineColor(kGreen+1);
  FinalEffMedIsoCJdRRachNew_->SetLineColor(kBlue+1);
  FinalEffMedIsoRECOdRRachNew_->SetLineColor(kGreen+1);
  FinalEffTightIsoCJdRRachNew_->SetLineColor(kBlue+1);
  FinalEffTightIsoRECOdRRachNew_->SetLineColor(kGreen+1);
  FinalEffDMFindCJdRRachNew_->SetLineColor(kBlue+1);
  FinalEffDMFindRECOdRRachNew_->SetLineColor(kGreen+1);

  FinalEffLooseIsoCJdRRachNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffLooseIsoRECOdRRachNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffMedIsoCJdRRachNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffMedIsoRECOdRRachNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffTightIsoCJdRRachNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffTightIsoRECOdRRachNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffDMFindCJdRRachNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffDMFindRECOdRRachNew_->GetXaxis()->SetTitle("#DeltaR");

  FinalEffLooseIsoCJdRRachNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffLooseIsoRECOdRRachNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffMedIsoCJdRRachNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffMedIsoRECOdRRachNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffTightIsoCJdRRachNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffTightIsoRECOdRRachNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffDMFindCJdRRachNew_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");
  FinalEffDMFindRECOdRRachNew_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");

  FinalEffLooseIsoCJdRRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffLooseIsoRECOdRRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoCJdRRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOdRRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoCJdRRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOdRRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindCJdRRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindRECOdRRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoCJdRRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffLooseIsoRECOdRRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoCJdRRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOdRRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoCJdRRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOdRRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindCJdRRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindRECOdRRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoCJdRRachNew_->SetLineWidth(3);
  FinalEffLooseIsoRECOdRRachNew_->SetLineWidth(3);
  FinalEffMedIsoCJdRRachNew_->SetLineWidth(3);
  FinalEffMedIsoRECOdRRachNew_->SetLineWidth(3);
  FinalEffTightIsoCJdRRachNew_->SetLineWidth(3);
  FinalEffTightIsoRECOdRRachNew_->SetLineWidth(3);
  FinalEffDMFindCJdRRachNew_->SetLineWidth(3);
  FinalEffDMFindRECOdRRachNew_->SetLineWidth(3);


  
  FinalEffLooseIsoCJPtGenRachNew_->SetMarkerColor(kBlue+1);
  FinalEffLooseIsoRECOPtGenRachNew_->SetMarkerColor(kGreen+1);
  FinalEffMedIsoCJPtGenRachNew_->SetMarkerColor(kBlue+1);
  FinalEffMedIsoRECOPtGenRachNew_->SetMarkerColor(kGreen+1);
  FinalEffTightIsoCJPtGenRachNew_->SetMarkerColor(kBlue+1);
  FinalEffTightIsoRECOPtGenRachNew_->SetMarkerColor(kGreen+1);
  FinalEffDMFindCJPtGenRachNew_->SetMarkerColor(kBlue+1);
  FinalEffDMFindRECOPtGenRachNew_->SetMarkerColor(kGreen+1);

  FinalEffLooseIsoCJPtGenRachNew_->SetMarkerSize(.07);
  FinalEffLooseIsoRECOPtGenRachNew_->SetMarkerSize(.07);
  FinalEffMedIsoCJPtGenRachNew_->SetMarkerSize(.07);
  FinalEffMedIsoRECOPtGenRachNew_->SetMarkerSize(.07);
  FinalEffTightIsoCJPtGenRachNew_->SetMarkerSize(.07);
  FinalEffTightIsoRECOPtGenRachNew_->SetMarkerSize(.07);
  FinalEffDMFindCJPtGenRachNew_->SetMarkerSize(.07);
  FinalEffDMFindRECOPtGenRachNew_->SetMarkerSize(.07);

  FinalEffLooseIsoCJPtGenRachNew_->SetLineColor(kBlue+1);
  FinalEffLooseIsoRECOPtGenRachNew_->SetLineColor(kGreen+1);
  FinalEffMedIsoCJPtGenRachNew_->SetLineColor(kBlue+1);
  FinalEffMedIsoRECOPtGenRachNew_->SetLineColor(kGreen+1);
  FinalEffTightIsoCJPtGenRachNew_->SetLineColor(kBlue+1);
  FinalEffTightIsoRECOPtGenRachNew_->SetLineColor(kGreen+1);
  FinalEffDMFindCJPtGenRachNew_->SetLineColor(kBlue+1);
  FinalEffDMFindRECOPtGenRachNew_->SetLineColor(kGreen+1);

  FinalEffLooseIsoCJPtGenRachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffLooseIsoRECOPtGenRachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffMedIsoCJPtGenRachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffMedIsoRECOPtGenRachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffTightIsoCJPtGenRachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffTightIsoRECOPtGenRachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffDMFindCJPtGenRachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffDMFindRECOPtGenRachNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");

  FinalEffLooseIsoCJPtGenRachNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffLooseIsoRECOPtGenRachNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffMedIsoCJPtGenRachNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffMedIsoRECOPtGenRachNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffTightIsoCJPtGenRachNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffTightIsoRECOPtGenRachNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffDMFindCJPtGenRachNew_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");
  FinalEffDMFindRECOPtGenRachNew_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");
 
  FinalEffLooseIsoCJPtGenRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffLooseIsoRECOPtGenRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoCJPtGenRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOPtGenRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoCJPtGenRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOPtGenRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindCJPtGenRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindRECOPtGenRachNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoCJPtGenRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffLooseIsoRECOPtGenRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoCJPtGenRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOPtGenRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoCJPtGenRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOPtGenRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindCJPtGenRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindRECOPtGenRachNew_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoCJPtGenRachNew_->SetLineWidth(3);
  FinalEffLooseIsoRECOPtGenRachNew_->SetLineWidth(3);
  FinalEffMedIsoCJPtGenRachNew_->SetLineWidth(3);
  FinalEffMedIsoRECOPtGenRachNew_->SetLineWidth(3);
  FinalEffTightIsoCJPtGenRachNew_->SetLineWidth(3);
  FinalEffTightIsoRECOPtGenRachNew_->SetLineWidth(3);
  FinalEffDMFindCJPtGenRachNew_->SetLineWidth(3);
  FinalEffDMFindRECOPtGenRachNew_->SetLineWidth(3);



  //Set Colors for New Gen Matching New DM's
  FinalEffLooseIsoCJPtKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffLooseIsoRECOPtKyleNew_->SetMarkerColor(kRed+1);
  FinalEffMedIsoCJPtKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffMedIsoRECOPtKyleNew_->SetMarkerColor(kRed+1);
  FinalEffTightIsoCJPtKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffTightIsoRECOPtKyleNew_->SetMarkerColor(kRed+1);
  FinalEffDMFindCJPtKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffDMFindRECOPtKyleNew_->SetMarkerColor(kRed+1);

  FinalEffLooseIsoCJPtKyleNew_->SetMarkerSize(.07);
  FinalEffLooseIsoRECOPtKyleNew_->SetMarkerSize(.07);
  FinalEffMedIsoCJPtKyleNew_->SetMarkerSize(.07);
  FinalEffMedIsoRECOPtKyleNew_->SetMarkerSize(.07);
  FinalEffTightIsoCJPtKyleNew_->SetMarkerSize(.07);
  FinalEffTightIsoRECOPtKyleNew_->SetMarkerSize(.07);
  FinalEffDMFindCJPtKyleNew_->SetMarkerSize(.07);
  FinalEffDMFindRECOPtKyleNew_->SetMarkerSize(.07);

  FinalEffLooseIsoCJPtKyleNew_->SetLineColor(kViolet-5);
  FinalEffLooseIsoRECOPtKyleNew_->SetLineColor(kRed+1);
  FinalEffMedIsoCJPtKyleNew_->SetLineColor(kViolet-5);
  FinalEffMedIsoRECOPtKyleNew_->SetLineColor(kRed+1);
  FinalEffTightIsoCJPtKyleNew_->SetLineColor(kViolet-5);
  FinalEffTightIsoRECOPtKyleNew_->SetLineColor(kRed+1);
  FinalEffDMFindCJPtKyleNew_->SetLineColor(kViolet-5);
  FinalEffDMFindRECOPtKyleNew_->SetLineColor(kRed+1);

  FinalEffLooseIsoCJPtKyleNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffLooseIsoRECOPtKyleNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffMedIsoCJPtKyleNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffMedIsoRECOPtKyleNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffTightIsoCJPtKyleNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffTightIsoRECOPtKyleNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffDMFindCJPtKyleNew_->GetXaxis()->SetTitle("p_{T}");
  FinalEffDMFindRECOPtKyleNew_->GetXaxis()->SetTitle("p_{T}");

  FinalEffLooseIsoCJPtKyleNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffLooseIsoRECOPtKyleNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffMedIsoCJPtKyleNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffMedIsoRECOPtKyleNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffTightIsoCJPtKyleNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffTightIsoRECOPtKyleNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffDMFindCJPtKyleNew_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");
  FinalEffDMFindRECOPtKyleNew_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");
  
  FinalEffLooseIsoCJPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffLooseIsoRECOPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoCJPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoCJPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindCJPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindRECOPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoCJPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffLooseIsoRECOPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoCJPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoCJPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindCJPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindRECOPtKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  
  FinalEffLooseIsoCJPtKyleNew_->SetLineWidth(3);
  FinalEffLooseIsoRECOPtKyleNew_->SetLineWidth(3);
  FinalEffMedIsoCJPtKyleNew_->SetLineWidth(3);
  FinalEffMedIsoRECOPtKyleNew_->SetLineWidth(3);
  FinalEffTightIsoCJPtKyleNew_->SetLineWidth(3);
  FinalEffTightIsoRECOPtKyleNew_->SetLineWidth(3);
  FinalEffDMFindCJPtKyleNew_->SetLineWidth(3);
  FinalEffDMFindRECOPtKyleNew_->SetLineWidth(3);



  FinalEffLooseIsoCJdRKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffLooseIsoRECOdRKyleNew_->SetMarkerColor(kRed+1);
  FinalEffMedIsoCJdRKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffMedIsoRECOdRKyleNew_->SetMarkerColor(kRed+1);
  FinalEffTightIsoCJdRKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffTightIsoRECOdRKyleNew_->SetMarkerColor(kRed+1);
  FinalEffDMFindCJdRKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffDMFindRECOdRKyleNew_->SetMarkerColor(kRed+1);

  FinalEffLooseIsoCJdRKyleNew_->SetMarkerSize(.07);
  FinalEffLooseIsoRECOdRKyleNew_->SetMarkerSize(.07);
  FinalEffMedIsoCJdRKyleNew_->SetMarkerSize(.07);
  FinalEffMedIsoRECOdRKyleNew_->SetMarkerSize(.07);
  FinalEffTightIsoCJdRKyleNew_->SetMarkerSize(.07);
  FinalEffTightIsoRECOdRKyleNew_->SetMarkerSize(.07);
  FinalEffDMFindCJdRKyleNew_->SetMarkerSize(.07);
  FinalEffDMFindRECOdRKyleNew_->SetMarkerSize(.07);

  FinalEffLooseIsoCJdRKyleNew_->SetLineColor(kViolet-5);
  FinalEffLooseIsoRECOdRKyleNew_->SetLineColor(kRed+1);
  FinalEffMedIsoCJdRKyleNew_->SetLineColor(kViolet-5);
  FinalEffMedIsoRECOdRKyleNew_->SetLineColor(kRed+1);
  FinalEffTightIsoCJdRKyleNew_->SetLineColor(kViolet-5);
  FinalEffTightIsoRECOdRKyleNew_->SetLineColor(kRed+1);
  FinalEffDMFindCJdRKyleNew_->SetLineColor(kViolet-5);
  FinalEffDMFindRECOdRKyleNew_->SetLineColor(kRed+1);

  FinalEffLooseIsoCJdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffLooseIsoRECOdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffMedIsoCJdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffMedIsoRECOdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffTightIsoCJdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffTightIsoRECOdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffDMFindCJdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffDMFindRECOdRKyleNew_->GetXaxis()->SetTitle("#DeltaR");
  
  FinalEffLooseIsoCJdRKyleNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffLooseIsoRECOdRKyleNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffMedIsoCJdRKyleNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffMedIsoRECOdRKyleNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffTightIsoCJdRKyleNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffTightIsoRECOdRKyleNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffDMFindCJdRKyleNew_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");
  FinalEffDMFindRECOdRKyleNew_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");

  FinalEffLooseIsoCJdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffLooseIsoRECOdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoCJdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoCJdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindCJdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindRECOdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoCJdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffLooseIsoRECOdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoCJdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoCJdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindCJdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindRECOdRKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoCJdRKyleNew_->SetLineWidth(3);
  FinalEffLooseIsoRECOdRKyleNew_->SetLineWidth(3);
  FinalEffMedIsoCJdRKyleNew_->SetLineWidth(3);
  FinalEffMedIsoRECOdRKyleNew_->SetLineWidth(3);
  FinalEffTightIsoCJdRKyleNew_->SetLineWidth(3);
  FinalEffTightIsoRECOdRKyleNew_->SetLineWidth(3);
  FinalEffDMFindCJdRKyleNew_->SetLineWidth(3);
  FinalEffDMFindRECOdRKyleNew_->SetLineWidth(3);




  FinalEffLooseIsoCJPtGenKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffLooseIsoRECOPtGenKyleNew_->SetMarkerColor(kRed+1);
  FinalEffMedIsoCJPtGenKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffMedIsoRECOPtGenKyleNew_->SetMarkerColor(kRed+1);
  FinalEffTightIsoCJPtGenKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffTightIsoRECOPtGenKyleNew_->SetMarkerColor(kRed+1);
  FinalEffDMFindCJPtGenKyleNew_->SetMarkerColor(kViolet-5);
  FinalEffDMFindRECOPtGenKyleNew_->SetMarkerColor(kRed+1);

  FinalEffLooseIsoCJPtGenKyleNew_->SetMarkerSize(.07);
  FinalEffLooseIsoRECOPtGenKyleNew_->SetMarkerSize(.07);
  FinalEffMedIsoCJPtGenKyleNew_->SetMarkerSize(.07);
  FinalEffMedIsoRECOPtGenKyleNew_->SetMarkerSize(.07);
  FinalEffTightIsoCJPtGenKyleNew_->SetMarkerSize(.07);
  FinalEffTightIsoRECOPtGenKyleNew_->SetMarkerSize(.07);
  FinalEffDMFindCJPtGenKyleNew_->SetMarkerSize(.07);
  FinalEffDMFindRECOPtGenKyleNew_->SetMarkerSize(.07);

  FinalEffLooseIsoCJPtGenKyleNew_->SetLineColor(kViolet-5);
  FinalEffLooseIsoRECOPtGenKyleNew_->SetLineColor(kRed+1);
  FinalEffMedIsoCJPtGenKyleNew_->SetLineColor(kViolet-5);
  FinalEffMedIsoRECOPtGenKyleNew_->SetLineColor(kRed+1);
  FinalEffTightIsoCJPtGenKyleNew_->SetLineColor(kViolet-5);
  FinalEffTightIsoRECOPtGenKyleNew_->SetLineColor(kRed+1);
  FinalEffDMFindCJPtGenKyleNew_->SetLineColor(kViolet-5);
  FinalEffDMFindRECOPtGenKyleNew_->SetLineColor(kRed+1);

  FinalEffLooseIsoCJPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffLooseIsoRECOPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffMedIsoCJPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffMedIsoRECOPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffTightIsoCJPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffTightIsoRECOPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffDMFindCJPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  FinalEffDMFindRECOPtGenKyleNew_->GetXaxis()->SetTitle("Gen Visible p_{T}");
  
  FinalEffLooseIsoCJPtGenKyleNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffLooseIsoRECOPtGenKyleNew_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffMedIsoCJPtGenKyleNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffMedIsoRECOPtGenKyleNew_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffTightIsoCJPtGenKyleNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffTightIsoRECOPtGenKyleNew_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffDMFindCJPtGenKyleNew_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");
  FinalEffDMFindRECOPtGenKyleNew_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");

  FinalEffLooseIsoCJPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffLooseIsoRECOPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoCJPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoCJPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindCJPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindRECOPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoCJPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffLooseIsoRECOPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoCJPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoCJPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindCJPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindRECOPtGenKyleNew_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoCJPtGenKyleNew_->SetLineWidth(3);
  FinalEffLooseIsoRECOPtGenKyleNew_->SetLineWidth(3);
  FinalEffMedIsoCJPtGenKyleNew_->SetLineWidth(3);
  FinalEffMedIsoRECOPtGenKyleNew_->SetLineWidth(3);
  FinalEffTightIsoCJPtGenKyleNew_->SetLineWidth(3);
  FinalEffTightIsoRECOPtGenKyleNew_->SetLineWidth(3);
  FinalEffDMFindCJPtGenKyleNew_->SetLineWidth(3);
  FinalEffDMFindRECOPtGenKyleNew_->SetLineWidth(3);

  //Set Colors for New Gen Matching New DM's
  FinalEffLooseIsoRECOPtDY_->SetMarkerColor(kBlack);
  FinalEffMedIsoRECOPtDY_->SetMarkerColor(kBlack);
  FinalEffTightIsoRECOPtDY_->SetMarkerColor(kBlack);
  FinalEffDMFindRECOPtDY_->SetMarkerColor(kBlack);

  FinalEffLooseIsoRECOPtDY_->SetMarkerSize(.07);
  FinalEffMedIsoRECOPtDY_->SetMarkerSize(.07);
  FinalEffTightIsoRECOPtDY_->SetMarkerSize(.07);
  FinalEffDMFindRECOPtDY_->SetMarkerSize(.07);

  FinalEffLooseIsoRECOPtDY_->SetLineColor(kBlack);
  FinalEffMedIsoRECOPtDY_->SetLineColor(kBlack);
  FinalEffTightIsoRECOPtDY_->SetLineColor(kBlack);
  FinalEffDMFindRECOPtDY_->SetLineColor(kBlack);

  FinalEffLooseIsoRECOPtDY_->GetXaxis()->SetTitle("p_{T}");
  FinalEffMedIsoRECOPtDY_->GetXaxis()->SetTitle("p_{T}");
  FinalEffTightIsoRECOPtDY_->GetXaxis()->SetTitle("p_{T}");
  FinalEffDMFindRECOPtDY_->GetXaxis()->SetTitle("p_{T}");

  FinalEffLooseIsoRECOPtDY_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffMedIsoRECOPtDY_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffTightIsoRECOPtDY_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffDMFindRECOPtDY_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");

  FinalEffLooseIsoRECOPtDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOPtDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOPtDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindRECOPtDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoRECOPtDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOPtDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOPtDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindRECOPtDY_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoRECOPtDY_->SetLineWidth(3);
  FinalEffMedIsoRECOPtDY_->SetLineWidth(3);
  FinalEffTightIsoRECOPtDY_->SetLineWidth(3);
  FinalEffDMFindRECOPtDY_->SetLineWidth(3);



  FinalEffLooseIsoRECOdRDY_->SetMarkerColor(kBlack);
  FinalEffMedIsoRECOdRDY_->SetMarkerColor(kBlack);
  FinalEffTightIsoRECOdRDY_->SetMarkerColor(kBlack);
  FinalEffDMFindRECOdRDY_->SetMarkerColor(kBlack);
  
  FinalEffLooseIsoRECOdRDY_->SetMarkerSize(.07);
  FinalEffMedIsoRECOdRDY_->SetMarkerSize(.07);
  FinalEffTightIsoRECOdRDY_->SetMarkerSize(.07);
  FinalEffDMFindRECOdRDY_->SetMarkerSize(.07);
  
  FinalEffLooseIsoRECOdRDY_->SetLineColor(kBlack);
  FinalEffMedIsoRECOdRDY_->SetLineColor(kBlack);
  FinalEffTightIsoRECOdRDY_->SetLineColor(kBlack);
  FinalEffDMFindRECOdRDY_->SetLineColor(kBlack);

  FinalEffLooseIsoRECOdRDY_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffMedIsoRECOdRDY_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffTightIsoRECOdRDY_->GetXaxis()->SetTitle("#DeltaR");
  FinalEffDMFindRECOdRDY_->GetXaxis()->SetTitle("#DeltaR");

  FinalEffLooseIsoRECOdRDY_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffMedIsoRECOdRDY_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffTightIsoRECOdRDY_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffDMFindRECOdRDY_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");

  FinalEffLooseIsoRECOdRDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOdRDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOdRDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindRECOdRDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoRECOdRDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOdRDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOdRDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindRECOdRDY_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoRECOdRDY_->SetLineWidth(3);
  FinalEffMedIsoRECOdRDY_->SetLineWidth(3);
  FinalEffTightIsoRECOdRDY_->SetLineWidth(3);
  FinalEffDMFindRECOdRDY_->SetLineWidth(3);



  FinalEffLooseIsoRECOPtGenDY_->SetMarkerColor(kBlack);
  FinalEffMedIsoRECOPtGenDY_->SetMarkerColor(kBlack);
  FinalEffTightIsoRECOPtGenDY_->SetMarkerColor(kBlack);
  FinalEffDMFindRECOPtGenDY_->SetMarkerColor(kBlack);
  
  FinalEffLooseIsoRECOPtGenDY_->SetMarkerSize(.07);
  FinalEffMedIsoRECOPtGenDY_->SetMarkerSize(.07);
  FinalEffTightIsoRECOPtGenDY_->SetMarkerSize(.07);
  FinalEffDMFindRECOPtGenDY_->SetMarkerSize(.07);
  
  FinalEffLooseIsoRECOPtGenDY_->SetLineColor(kBlack);
  FinalEffMedIsoRECOPtGenDY_->SetLineColor(kBlack);
  FinalEffTightIsoRECOPtGenDY_->SetLineColor(kBlack);
  FinalEffDMFindRECOPtGenDY_->SetLineColor(kBlack);

  FinalEffLooseIsoRECOPtGenDY_->GetXaxis()->SetTitle("Gen Visilbe P_{T}");
  FinalEffMedIsoRECOPtGenDY_->GetXaxis()->SetTitle("Gen Visilbe P_{T}");
  FinalEffTightIsoRECOPtGenDY_->GetXaxis()->SetTitle("Gen Visilbe P_{T}");
  FinalEffDMFindRECOPtGenDY_->GetXaxis()->SetTitle("Gen Visilbe P_{T}");

  FinalEffLooseIsoRECOPtGenDY_->GetYaxis()->SetTitle("#epsilon (Loose Iso + DMFinding + GM / GM)");
  FinalEffMedIsoRECOPtGenDY_->GetYaxis()->SetTitle("#epsilon (Med Iso + DMFinding + GM / GM)");
  FinalEffTightIsoRECOPtGenDY_->GetYaxis()->SetTitle("#epsilon (Tight Iso + DMFinding + GM / GM)");
  FinalEffDMFindRECOPtGenDY_->GetYaxis()->SetTitle("#epsilon (DMFinding + GM / GM)");

  FinalEffLooseIsoRECOPtGenDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffMedIsoRECOPtGenDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffTightIsoRECOPtGenDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");
  FinalEffDMFindRECOPtGenDY_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 9 GeV");

  FinalEffLooseIsoRECOPtGenDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffMedIsoRECOPtGenDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffTightIsoRECOPtGenDY_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalEffDMFindRECOPtGenDY_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalEffLooseIsoRECOPtGenDY_->SetLineWidth(3);
  FinalEffMedIsoRECOPtGenDY_->SetLineWidth(3);
  FinalEffTightIsoRECOPtGenDY_->SetLineWidth(3);
  FinalEffDMFindRECOPtGenDY_->SetLineWidth(3);

cout << "Attributes set." << endl;  

  leg = new TLegend(0.1,0.7,0.25,0.9);
  leg->AddEntry(FinalEffLooseIsoRECOPtGenDY_,   "Drell Yan Z-TT","L");
  leg->AddEntry(FinalEffDMFindRECOPtGenRachNew_, "No  CJ,New Gen","L");
  leg->AddEntry(FinalEffDMFindRECOPtGenKyleNew_, "No  CJ,Old Gen","L");
  leg->AddEntry(FinalEffDMFindCJPtGenRachNew_,   "Yes CJ,New Gen","L");
  leg->AddEntry(FinalEffDMFindCJPtGenKyleNew_,   "Yes CJ,Old Gen","L");

  legMatch = new TLegend(0.1,0.7,0.25,0.9);
  legMatch->AddEntry(FinalEffDMFindRECOPtGenRachNew_, "No  CJ,New Gen","L");
  legMatch->AddEntry(FinalEffDMFindCJPtGenRachNew_,   "Yes CJ,New Gen","L");



  LoosePtCanvas.cd();
  FinalEffLooseIsoRECOPtDY_->Draw();
  FinalEffLooseIsoCJPtRachNew_->Draw("SAME");
  FinalEffLooseIsoRECOPtRachNew_->Draw("SAME");
  FinalEffLooseIsoCJPtKyleNew_->Draw("SAME");
  FinalEffLooseIsoRECOPtKyleNew_->Draw("SAME");
  leg->Draw();

  LoosePtNewGenMatchCanvas.cd();
  FinalEffLooseIsoRECOPtDY_->Draw();
  FinalEffLooseIsoCJPtRachNew_->Draw("SAME");
  FinalEffLooseIsoRECOPtRachNew_->Draw("SAME");
  legMatch->Draw();

  MedPtCanvas.cd();
  FinalEffMedIsoRECOPtDY_->Draw();
  FinalEffMedIsoCJPtRachNew_->Draw("SAME");
  FinalEffMedIsoRECOPtRachNew_->Draw("SAME");
  FinalEffMedIsoCJPtKyleNew_->Draw("SAME");
  FinalEffMedIsoRECOPtKyleNew_->Draw("SAME");
  leg->Draw();

  MedPtNewGenMatchCanvas.cd();
  FinalEffMedIsoRECOPtDY_->Draw();
  FinalEffMedIsoCJPtRachNew_->Draw("SAME");
  FinalEffMedIsoRECOPtRachNew_->Draw("SAME");
  legMatch->Draw();
  

  TightPtCanvas.cd();
  FinalEffTightIsoRECOPtDY_->Draw();
  FinalEffTightIsoCJPtRachNew_->Draw("SAME");
  FinalEffTightIsoRECOPtRachNew_->Draw("SAME");
  FinalEffTightIsoCJPtKyleNew_->Draw("SAME");
  FinalEffTightIsoRECOPtKyleNew_->Draw("SAME");
  leg->Draw();

  TightPtNewGenMatchCanvas.cd();
  FinalEffTightIsoRECOPtDY_->Draw();
  FinalEffTightIsoCJPtRachNew_->Draw("SAME");
  FinalEffTightIsoRECOPtRachNew_->Draw("SAME");
  legMatch->Draw();
  

  DMPtCanvas.cd();
  FinalEffDMFindRECOPtDY_->Draw();
  FinalEffDMFindCJPtRachNew_->Draw("SAME");
  FinalEffDMFindRECOPtRachNew_->Draw("SAME");
  FinalEffDMFindCJPtKyleNew_->Draw("SAME");
  FinalEffDMFindRECOPtKyleNew_->Draw("SAME");
  leg->Draw();

  DMPtNewGenMatchCanvas.cd();
  FinalEffDMFindRECOPtDY_->Draw();
  FinalEffDMFindCJPtRachNew_->Draw("SAME");
  FinalEffDMFindRECOPtRachNew_->Draw("SAME");
  legMatch->Draw();
  


  LoosedRCanvas.cd();
  FinalEffLooseIsoCJdRRachNew_->Draw();
  FinalEffLooseIsoRECOdRRachNew_->Draw("SAME");
  FinalEffLooseIsoCJdRKyleNew_->Draw("SAME");
  FinalEffLooseIsoRECOdRKyleNew_->Draw("SAME");
  FinalEffLooseIsoRECOdRDY_->Draw("SAME");
  leg->Draw();

  LoosedRNewGenMatchCanvas.cd();
  FinalEffLooseIsoCJdRRachNew_->Draw();
  FinalEffLooseIsoRECOdRRachNew_->Draw("SAME");
  FinalEffLooseIsoRECOdRDY_->Draw("SAME");
  legMatch->Draw();
  
 
  MeddRCanvas.cd();
  FinalEffMedIsoCJdRRachNew_->Draw();
  FinalEffMedIsoRECOdRRachNew_->Draw("SAME");
  FinalEffMedIsoCJdRKyleNew_->Draw("SAME");
  FinalEffMedIsoRECOdRKyleNew_->Draw("SAME");
  FinalEffMedIsoRECOdRDY_->Draw("SAME");
  leg->Draw();
 
  MeddRNewGenMatchCanvas.cd();
  FinalEffMedIsoCJdRRachNew_->Draw();
  FinalEffMedIsoRECOdRRachNew_->Draw("SAME");
  FinalEffMedIsoRECOdRDY_->Draw("SAME");
  legMatch->Draw();
 
  TightdRCanvas.cd();
  FinalEffTightIsoCJdRRachNew_->Draw();
  FinalEffTightIsoRECOdRRachNew_->Draw("SAME");
  FinalEffTightIsoCJdRKyleNew_->Draw("SAME");
  FinalEffTightIsoRECOdRKyleNew_->Draw("SAME");
  FinalEffTightIsoRECOdRDY_->Draw("SAME");
  leg->Draw();

  TightdRNewGenMatchCanvas.cd();
  FinalEffTightIsoCJdRRachNew_->Draw();
  FinalEffTightIsoRECOdRRachNew_->Draw("SAME");
  FinalEffTightIsoRECOdRDY_->Draw("SAME");
  legMatch->Draw();

  DMdRCanvas.cd();
  FinalEffDMFindCJdRRachNew_->Draw();
  FinalEffDMFindRECOdRRachNew_->Draw("SAME");
  FinalEffDMFindCJdRKyleNew_->Draw("SAME");
  FinalEffDMFindRECOdRKyleNew_->Draw("SAME");
  FinalEffDMFindRECOdRDY_->Draw("SAME");
  leg->Draw();

  DMdRNewGenMatchCanvas.cd();
  FinalEffDMFindCJdRRachNew_->Draw();
  FinalEffDMFindRECOdRRachNew_->Draw("SAME");
  FinalEffDMFindRECOdRDY_->Draw("SAME");
  legMatch->Draw();
 
  LoosePtGenCanvas.cd();
  FinalEffLooseIsoRECOPtGenDY_->Draw();
  FinalEffLooseIsoCJPtGenRachNew_->Draw("SAME");
  FinalEffLooseIsoRECOPtGenRachNew_->Draw("SAME");
  FinalEffLooseIsoCJPtGenKyleNew_->Draw("SAME");
  FinalEffLooseIsoRECOPtGenKyleNew_->Draw("SAME");
  leg->Draw();

  LoosePtGenNewGenMatchCanvas.cd();
  FinalEffLooseIsoRECOPtGenDY_->Draw();
  FinalEffLooseIsoCJPtGenRachNew_->Draw("SAME");
  FinalEffLooseIsoRECOPtGenRachNew_->Draw("SAME");
  legMatch->Draw();
 
  MedPtGenCanvas.cd();
  FinalEffMedIsoRECOPtGenDY_->Draw();
  FinalEffMedIsoCJPtGenRachNew_->Draw("SAME");
  FinalEffMedIsoRECOPtGenRachNew_->Draw("SAME");
  FinalEffMedIsoCJPtGenKyleNew_->Draw("SAME");
  FinalEffMedIsoRECOPtGenKyleNew_->Draw("SAME");
  leg->Draw();

  MedPtGenNewGenMatchCanvas.cd();
  FinalEffMedIsoRECOPtGenDY_->Draw();
  FinalEffMedIsoCJPtGenRachNew_->Draw("SAME");
  FinalEffMedIsoRECOPtGenRachNew_->Draw("SAME");
  legMatch->Draw();
 
  TightPtGenCanvas.cd();
  FinalEffTightIsoRECOPtGenDY_->Draw();
  FinalEffTightIsoCJPtGenRachNew_->Draw("SAME");
  FinalEffTightIsoRECOPtGenRachNew_->Draw("SAME");
  FinalEffTightIsoCJPtGenKyleNew_->Draw("SAME");
  FinalEffTightIsoRECOPtGenKyleNew_->Draw("SAME");
  leg->Draw("SAME");

  TightPtGenNewGenMatchCanvas.cd();
  FinalEffTightIsoRECOPtGenDY_->Draw();
  FinalEffTightIsoCJPtGenRachNew_->Draw("SAME");
  FinalEffTightIsoRECOPtGenRachNew_->Draw("SAME");
  legMatch->Draw("SAME");

  DMPtGenCanvas.cd();
  FinalEffDMFindRECOPtGenDY_->Draw();
  FinalEffDMFindCJPtGenRachNew_->Draw("SAME");
  FinalEffDMFindRECOPtGenRachNew_->Draw("SAME");
  FinalEffDMFindCJPtGenKyleNew_->Draw("SAME");
  FinalEffDMFindRECOPtGenKyleNew_->Draw("SAME");
  leg->Draw("SAME");

  DMPtGenNewGenMatchCanvas.cd();
  FinalEffDMFindRECOPtGenDY_->Draw();
  FinalEffDMFindCJPtGenRachNew_->Draw("SAME");
  FinalEffDMFindRECOPtGenRachNew_->Draw("SAME");
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

  MatchedCJPtCanvasRachNew->Write();
  MatchedRECOPtCanvasRachNew->Write();
  MatchedCJdRCanvasRachNew->Write();
  MatchedRECOdRCanvasRachNew->Write();
  MatchedCJPtGenCanvasRachNew->Write();
  MatchedRECOPtGenCanvasRachNew->Write();

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
