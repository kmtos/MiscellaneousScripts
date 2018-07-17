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
  TFile infileKyleNew("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/TauCJEff/FINAL_H125a5_CJMu3Only_JAN8.root");
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/CombinedPlots/CJEff_H125a5_NewMVA_CJMu3Only.root", "RECREATE");
cout << "Files Created" << endl;

  // CJ/RECO Comparison histograms
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

cout << "Got Canvases" << endl;

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
  
  FinalEffLooseIsoCJPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffLooseIsoRECOPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffMedIsoCJPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffMedIsoRECOPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffTightIsoCJPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffTightIsoRECOPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffCJPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffRECOPtKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");

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

  FinalEffLooseIsoCJdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffLooseIsoRECOdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffMedIsoCJdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffMedIsoRECOdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffTightIsoCJdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffTightIsoRECOdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffCJdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffRECOdRKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");

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

  FinalEffLooseIsoCJPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffLooseIsoRECOPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffMedIsoCJPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffMedIsoRECOPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffTightIsoCJPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffTightIsoRECOPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffCJPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");
  FinalEffRECOPtGenKyleNew_->SetTitle("m_{h} = 125 GeV  |  m_{a1} = 5 GeV");

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

cout << "Attributes set." << endl;  

  leg = new TLegend(0.1,0.7,0.25,0.9);
  leg->AddEntry(FinalEffRECOPtGenKyleNew_, "No  CJ","L");
  leg->AddEntry(FinalEffCJPtGenKyleNew_,   "Yes CJ","L");



  LoosePtCanvas.cd();
  FinalEffLooseIsoCJPtKyleNew_->Draw();
  FinalEffLooseIsoRECOPtKyleNew_->Draw("SAME");
  leg->Draw();

  MedPtCanvas.cd();
  FinalEffMedIsoCJPtKyleNew_->Draw();
  FinalEffMedIsoRECOPtKyleNew_->Draw("SAME");
  leg->Draw();

  TightPtCanvas.cd();
  FinalEffTightIsoCJPtKyleNew_->Draw();
  FinalEffTightIsoRECOPtKyleNew_->Draw("SAME");
  leg->Draw();

  DMPtCanvas.cd();
  FinalEffCJPtKyleNew_->Draw();
  FinalEffRECOPtKyleNew_->Draw("SAME");
  leg->Draw();

  LoosedRCanvas.cd();
  FinalEffLooseIsoCJdRKyleNew_->Draw();
  FinalEffLooseIsoRECOdRKyleNew_->Draw("SAME");
  leg->Draw();

  MeddRCanvas.cd();
  FinalEffMedIsoCJdRKyleNew_->Draw();
  FinalEffMedIsoRECOdRKyleNew_->Draw("SAME");
  leg->Draw();
 
  TightdRCanvas.cd();
  FinalEffTightIsoCJdRKyleNew_->Draw();
  FinalEffTightIsoRECOdRKyleNew_->Draw("SAME");
  leg->Draw();

  DMdRCanvas.cd();
  FinalEffCJdRKyleNew_->Draw();
  FinalEffRECOdRKyleNew_->Draw("SAME");
  leg->Draw();

  LoosePtGenCanvas.cd();
  FinalEffLooseIsoCJPtGenKyleNew_->Draw();
  FinalEffLooseIsoRECOPtGenKyleNew_->Draw("SAME");
  leg->Draw();

  MedPtGenCanvas.cd();
  FinalEffMedIsoCJPtGenKyleNew_->Draw();
  FinalEffMedIsoRECOPtGenKyleNew_->Draw("SAME");
  leg->Draw();
 
  TightPtGenCanvas.cd();
  FinalEffTightIsoCJPtGenKyleNew_->Draw();
  FinalEffTightIsoRECOPtGenKyleNew_->Draw("SAME");
  leg->Draw("SAME");

  DMPtGenCanvas.cd();
  FinalEffCJPtGenKyleNew_->Draw();
  FinalEffRECOPtGenKyleNew_->Draw("SAME");
  leg->Draw("SAME");

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
