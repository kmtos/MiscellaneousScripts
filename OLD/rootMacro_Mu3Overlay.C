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
#include "iostream"
#include "fstream"
#include "TMath.h"

void rootMacro_Mu3Overlay()
{

  gStyle->SetOptStat(kFALSE);
  gStyle->SetEndErrorSize(7);

  //Old DMs
  TFile infileTT     ("/home/kyletos/Downloads/TriggerOutput/FINAL_TT_NoMuTauHad_FineBin_OCT21.root");
  TFile infileWJ     ("/home/kyletos/Downloads/TriggerOutput/FINAL_WJ_NoMuTauHad_FineBin_OCT21.root");
  TFile infileDY     ("/home/kyletos/Downloads/TriggerOutput/FINAL_DY_NoMuTauHad_FineBin_OCT21.root");
  TFile infileSig    ("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_Sig125.root");
  TFile infileSigBig ("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_Sig750.root");

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/CombinedPlots/comb_Mu3Overlay_XSecNorm_FineBin_OCT24.root", "RECREATE");

cout << "Files Created" << endl;

  ////////////////
  // TTJets
  ////////////////
  infileTT.cd("Mu3Analyzer");
  TH1F*  Mu3PtTT_ = (TH1F*)gDirectory->Get("Mu3Pt");
  TH1F*  Mu3PtLargestTT_ = (TH1F*)gDirectory->Get("Mu3PtLargest");
  TH1F*  PfCandSizeTT_ = (TH1F*)gDirectory->Get("PfCandSize");
  TH1F*  DRMu3Mu1TT_ = (TH1F*)gDirectory->Get("DRMu3Mu1");
  TH1F*  DRMu3Mu2TT_ = (TH1F*)gDirectory->Get("DRMu3Mu2");
  TH1F*  ClosetsdRTT_ = (TH1F*)gDirectory->Get("ClosetsdR");
  TH1F*  Mu3IsoTT_ = (TH1F*)gDirectory->Get("Mu3Iso");
  TH2F*  PtMu3vsIsoLargestPtTT_ = (TH2F*)gDirectory->Get("PtMu3vsIsoLargestPt");  
  TH2F*  PtMu3vsIsoTT_ = (TH2F*)gDirectory->Get("PtMu3vsIso");
  TH2F*  PtMu3vsIsoNoRelTT_ = (TH2F*)gDirectory->Get("PtMu3vsIsoNoRel");


  ////////////////
  // WJ
  ////////////////
  infileWJ.cd("Mu3Analyzer");
  TH1F*  Mu3PtWJ_ = (TH1F*)gDirectory->Get("Mu3Pt");
  TH1F*  Mu3PtLargestWJ_ = (TH1F*)gDirectory->Get("Mu3PtLargest");
  TH1F*  PfCandSizeWJ_ = (TH1F*)gDirectory->Get("PfCandSize");
  TH1F*  DRMu3Mu1WJ_ = (TH1F*)gDirectory->Get("DRMu3Mu1");
  TH1F*  DRMu3Mu2WJ_ = (TH1F*)gDirectory->Get("DRMu3Mu2");
  TH1F*  ClosetsdRWJ_ = (TH1F*)gDirectory->Get("ClosetsdR");
  TH1F*  Mu3IsoWJ_ = (TH1F*)gDirectory->Get("Mu3Iso");
  TH2F*  PtMu3vsIsoLargestPtWJ_ = (TH2F*)gDirectory->Get("PtMu3vsIsoLargestPt");
  TH2F*  PtMu3vsIsoWJ_ = (TH2F*)gDirectory->Get("PtMu3vsIso");
  TH2F*  PtMu3vsIsoNoRelWJ_ = (TH2F*)gDirectory->Get("PtMu3vsIsoNoRel");

  ////////////////
  // DY
  ////////////////
  infileDY.cd("Mu3Analyzer");
  TH1F*  Mu3PtDY_ = (TH1F*)gDirectory->Get("Mu3Pt");
  TH1F*  Mu3PtLargestDY_ = (TH1F*)gDirectory->Get("Mu3PtLargest");
  TH1F*  PfCandSizeDY_ = (TH1F*)gDirectory->Get("PfCandSize");
  TH1F*  DRMu3Mu1DY_ = (TH1F*)gDirectory->Get("DRMu3Mu1");
  TH1F*  DRMu3Mu2DY_ = (TH1F*)gDirectory->Get("DRMu3Mu2");
  TH1F*  ClosetsdRDY_ = (TH1F*)gDirectory->Get("ClosetsdR");
  TH1F*  Mu3IsoDY_ = (TH1F*)gDirectory->Get("Mu3Iso");
  TH2F*  PtMu3vsIsoLargestPtDY_ = (TH2F*)gDirectory->Get("PtMu3vsIsoLargestPt");
  TH2F*  PtMu3vsIsoDY_ = (TH2F*)gDirectory->Get("PtMu3vsIso");
  TH2F*  PtMu3vsIsoNoRelDY_ = (TH2F*)gDirectory->Get("PtMu3vsIsoNoRel");

  ////////////////
  // Sig
  ////////////////
  infileSig.cd("Mu3Analyzer");
  TH1F*  Mu3PtSig_ = (TH1F*)gDirectory->Get("Mu3Pt");
  TH1F*  Mu3PtLargestSig_ = (TH1F*)gDirectory->Get("Mu3PtLargest");
  TH1F*  PfCandSizeSig_ = (TH1F*)gDirectory->Get("PfCandSize");
  TH1F*  DRMu3Mu1Sig_ = (TH1F*)gDirectory->Get("DRMu3Mu1");
  TH1F*  DRMu3Mu2Sig_ = (TH1F*)gDirectory->Get("DRMu3Mu2");
  TH1F*  ClosetsdRSig_ = (TH1F*)gDirectory->Get("ClosetsdR");
  TH1F*  Mu3IsoSig_ = (TH1F*)gDirectory->Get("Mu3Iso");
  TH2F*  PtMu3vsIsoLargestPtSig_ = (TH2F*)gDirectory->Get("PtMu3vsIsoLargestPt");
  TH2F*  PtMu3vsIsoSig_ = (TH2F*)gDirectory->Get("PtMu3vsIso");
  TH2F*  PtMu3vsIsoNoRelSig_ = (TH2F*)gDirectory->Get("PtMu3vsIsoNoRel");

  ////////////////
  // SigBig
  ////////////////
  infileSigBig.cd("Mu3Analyzer");
  TH1F*  Mu3PtSigBig_ = (TH1F*)gDirectory->Get("Mu3Pt");
  TH1F*  Mu3PtLargestSigBig_ = (TH1F*)gDirectory->Get("Mu3PtLargest");
  TH1F*  PfCandSizeSigBig_ = (TH1F*)gDirectory->Get("PfCandSize");
  TH1F*  DRMu3Mu1SigBig_ = (TH1F*)gDirectory->Get("DRMu3Mu1");
  TH1F*  DRMu3Mu2SigBig_ = (TH1F*)gDirectory->Get("DRMu3Mu2");
  TH1F*  ClosetsdRSigBig_ = (TH1F*)gDirectory->Get("ClosetsdR");
  TH1F*  Mu3IsoSigBig_ = (TH1F*)gDirectory->Get("Mu3Iso");
  TH2F*  PtMu3vsIsoLargestPtSigBig_ = (TH2F*)gDirectory->Get("PtMu3vsIsoLargestPt");
  TH2F*  PtMu3vsIsoSigBig_ = (TH2F*)gDirectory->Get("PtMu3vsIso");
  TH2F*  PtMu3vsIsoNoRelSigBig_ = (TH2F*)gDirectory->Get("PtMu3vsIsoNoRel");

cout << "Histograms assigned." << endl; 

  ///////////////////////
  // Total Overal Plots
  ///////////////////////
  TCanvas Mu3PtCanvasTOT_("Mu3PtCanvasTOT","",600,600);
  TCanvas Mu3PtLargestCanvasTOT_("Mu3PtLargestCanvasTOT","",600,600);
  TCanvas PfCandSizeCanvasTOT_("PfCandSizeCanvasTOT","",600,600);
  TCanvas DRMu3Mu1CanvasTOT_("DRMu3Mu1CanvasTOT","",600,600);
  TCanvas DRMu3Mu2CanvasTOT_("DRMu3Mu2CanvasTOT","",600,600);
  TCanvas ClosetsdRCanvasTOT_("ClosetsdRCanvasTOT" ,"",600,600);
  TCanvas Mu3IsoCanvasTOT_("Mu3IsoCanvasTOT","",600,600);
  TCanvas Mu3PtvsIsoCanvasTOT_("Mu3PtvsIsoCanvasTOT","",600,600);
  Mu3PtvsIsoCanvasTOT_.Divide(2,3);
  TCanvas Mu3PtvsIsoNoRelCanvasTOT_("Mu3PtvsIsoNoRelCanvasTOT","",600,600);
  Mu3PtvsIsoNoRelCanvasTOT_.Divide(2,3);
  TCanvas Mu3PtLargestvsIsoCanvasTOT_("Mu3PtLargestvsIsoCanvasTOT","",600,600);
  Mu3PtLargestvsIsoCanvasTOT_.Divide(2,3);

  Mu3PtCanvasTOT_.SetGrid(1,1);
  Mu3PtLargestCanvasTOT_.SetGrid(1,1);
  PfCandSizeCanvasTOT_.SetGrid(1,1);
  DRMu3Mu1CanvasTOT_.SetGrid(1,1);
  DRMu3Mu2CanvasTOT_.SetGrid(1,1);
  ClosetsdRCanvasTOT_.SetGrid(1,1);
  Mu3IsoCanvasTOT_.SetGrid(1,1);

  Mu3PtCanvasTOT_.SetLogy();
  Mu3PtLargestCanvasTOT_.SetLogy();
  PfCandSizeCanvasTOT_.SetLogy();
  DRMu3Mu1CanvasTOT_.SetLogy();
  DRMu3Mu2CanvasTOT_.SetLogy();
  ClosetsdRCanvasTOT_.SetLogy();
  Mu3IsoCanvasTOT_.SetLogy();
/*
  Mu3PtCanvasTOT_.SetLogx();
  Mu3PtLargestCanvasTOT_.SetLogx();
  PfCandSizeCanvasTOT_.SetLogx();
  DRMu3Mu1CanvasTOT_.SetLogx();
  DRMu3Mu2CanvasTOT_.SetLogx();
  ClosetsdRCanvasTOT_.SetLogx();
  Mu3IsoCanvasTOT_.SetLogx();
*/
cout << "Final Canvases created" << endl;

  std::cout << "TTBar   Scale(831.76*20,000.0/37,081,058)  =  " << 831.76*20000.0/37081058.0  << std::endl;
  std::cout << "WJets   Scale(61,526.7*20,000.0/47,737,675)= " << 61526.7*20000.0/47737675.0  << std::endl;
  std::cout << "DY m=50 Scale(1921.8*3*20,000.0/55,663,144)=  " << 1921.8*3*20000.0/55663144.0  << std::endl;
  std::cout << "mH=125  Scale(48.90*20,000.0/1000.0)=  " << 48.90*20000.0/1000.0  << std::endl;
  std::cout << "mH=750  Scale(0.4969*20,000.0/1000.0)= " << 0.4969*20000.0/1000.0  << std::endl;

  Mu3PtTT_->Scale(831.76*20000.0/37081058.0);
  Mu3PtLargestTT_->Scale(831.76*20000.0/37081058.0);
  PfCandSizeTT_->Scale(831.76*20000.0/37081058.0);
  DRMu3Mu1TT_->Scale(831.76*20000.0/37081058.0);
  DRMu3Mu2TT_->Scale(831.76*20000.0/37081058.0);
  ClosetsdRTT_->Scale(831.76*20000.0/37081058.0);
  Mu3IsoTT_->Scale(831.76*20000.0/37081058.0);
  
  Mu3PtWJ_->Scale(61526.7*20000.0/47737675.0);
  Mu3PtLargestWJ_->Scale(61526.7*20000.0/47737675.0);
  PfCandSizeWJ_->Scale(61526.7*20000.0/47737675.0);
  DRMu3Mu1WJ_->Scale(61526.7*20000.0/47737675.0);
  DRMu3Mu2WJ_->Scale(61526.7*20000.0/47737675.0);
  ClosetsdRWJ_->Scale(61526.7*20000.0/47737675.0);
  Mu3IsoWJ_->Scale(61526.7*20000.0/47737675.0);
  
  Mu3PtDY_->Scale(1921.8*3*20000.0/55663144.0);
  Mu3PtLargestDY_->Scale(1921.8*3*20000.0/55663144.0);
  PfCandSizeDY_->Scale(1921.8*3*20000.0/55663144.0);
  DRMu3Mu1DY_->Scale(1921.8*3*20000.0/55663144.0);
  DRMu3Mu2DY_->Scale(1921.8*3*20000.0/55663144.0);
  ClosetsdRDY_->Scale(1921.8*3*20000.0/55663144.0);
  Mu3IsoDY_->Scale(1921.8*3*20000.0/55663144.0);
  
  Mu3PtSig_->Scale(48.90*20000.0/1000.0);
  Mu3PtLargestSig_->Scale(48.90*20000.0/1000.0);
  PfCandSizeSig_->Scale(48.90*20000.0/1000.0);
  DRMu3Mu1Sig_->Scale(48.90*20000.0/1000.0);
  DRMu3Mu2Sig_->Scale(48.90*20000.0/1000.0);
  ClosetsdRSig_->Scale(48.90*20000.0/1000.0);
  Mu3IsoSig_->Scale(48.90*20000.0/1000.0);
  
  Mu3PtSigBig_->Scale(0.4969*20000.0/1000.0);
  Mu3PtLargestSigBig_->Scale(0.4969*20000.0/1000.0);
  PfCandSizeSigBig_->Scale(0.4969*20000.0/1000.0);
  DRMu3Mu1SigBig_->Scale(0.4969*20000.0/1000.0);
  DRMu3Mu2SigBig_->Scale(0.4969*20000.0/1000.0);
  ClosetsdRSigBig_->Scale(0.4969*20000.0/1000.0);
  Mu3IsoSigBig_->Scale(0.4969*20000.0/1000.0);


cout << "Histograms scaled" << endl;

  //////////////////////////////////
  // TT TGraphErrors from TH1
  //////////////////////////////////
  TGraphAsymmErrors* FinalMu3PtTT_ = new TGraphAsymmErrors(Mu3PtTT_);
  TGraphAsymmErrors* FinalMu3PtLargestTT_ = new TGraphAsymmErrors(Mu3PtLargestTT_);
  TGraphAsymmErrors* FinalPfCandSizeTT_ = new TGraphAsymmErrors(PfCandSizeTT_);
  TGraphAsymmErrors* FinalDRMu3Mu1TT_ = new TGraphAsymmErrors(DRMu3Mu1TT_);
  TGraphAsymmErrors* FinalDRMu3Mu2TT_ = new TGraphAsymmErrors(DRMu3Mu2TT_);
  TGraphAsymmErrors* FinalClosetsdRTT_ = new TGraphAsymmErrors(ClosetsdRTT_);
  TGraphAsymmErrors* FinalMu3IsoTT_ = new TGraphAsymmErrors(Mu3IsoTT_);

  //////////////////////////////////
  // WJ TGraphErrors from TH1
  //////////////////////////////////
  TGraphAsymmErrors* FinalMu3PtWJ_ = new TGraphAsymmErrors(Mu3PtWJ_);
  TGraphAsymmErrors* FinalMu3PtLargestWJ_ = new TGraphAsymmErrors(Mu3PtLargestWJ_);
  TGraphAsymmErrors* FinalPfCandSizeWJ_ = new TGraphAsymmErrors(PfCandSizeWJ_);
  TGraphAsymmErrors* FinalDRMu3Mu1WJ_ = new TGraphAsymmErrors(DRMu3Mu1WJ_);
  TGraphAsymmErrors* FinalDRMu3Mu2WJ_ = new TGraphAsymmErrors(DRMu3Mu2WJ_);
  TGraphAsymmErrors* FinalClosetsdRWJ_ = new TGraphAsymmErrors(ClosetsdRWJ_);
  TGraphAsymmErrors* FinalMu3IsoWJ_ = new TGraphAsymmErrors(Mu3IsoWJ_);

  //////////////////////////////////
  // DY TGraphErrors from TH1
  //////////////////////////////////
  TGraphAsymmErrors* FinalMu3PtDY_ = new TGraphAsymmErrors(Mu3PtDY_);
  TGraphAsymmErrors* FinalMu3PtLargestDY_ = new TGraphAsymmErrors(Mu3PtLargestDY_);
  TGraphAsymmErrors* FinalPfCandSizeDY_ = new TGraphAsymmErrors(PfCandSizeDY_);
  TGraphAsymmErrors* FinalDRMu3Mu1DY_ = new TGraphAsymmErrors(DRMu3Mu1DY_);
  TGraphAsymmErrors* FinalDRMu3Mu2DY_ = new TGraphAsymmErrors(DRMu3Mu2DY_);
  TGraphAsymmErrors* FinalClosetsdRDY_ = new TGraphAsymmErrors(ClosetsdRDY_);
  TGraphAsymmErrors* FinalMu3IsoDY_ = new TGraphAsymmErrors(Mu3IsoDY_);

  //////////////////////////////////
  // Sig TGraphErrors from TH1
  //////////////////////////////////
  TGraphAsymmErrors* FinalMu3PtSig_ = new TGraphAsymmErrors(Mu3PtSig_);
  TGraphAsymmErrors* FinalMu3PtLargestSig_ = new TGraphAsymmErrors(Mu3PtLargestSig_);
  TGraphAsymmErrors* FinalPfCandSizeSig_ = new TGraphAsymmErrors(PfCandSizeSig_);
  TGraphAsymmErrors* FinalDRMu3Mu1Sig_ = new TGraphAsymmErrors(DRMu3Mu1Sig_);
  TGraphAsymmErrors* FinalDRMu3Mu2Sig_ = new TGraphAsymmErrors(DRMu3Mu2Sig_);
  TGraphAsymmErrors* FinalClosetsdRSig_ = new TGraphAsymmErrors(ClosetsdRSig_);
  TGraphAsymmErrors* FinalMu3IsoSig_ = new TGraphAsymmErrors(Mu3IsoSig_);

  //////////////////////////////////
  // SigBig TGraphErrors from TH1
  //////////////////////////////////
  TGraphAsymmErrors* FinalMu3PtSigBig_ = new TGraphAsymmErrors(Mu3PtSigBig_);
  TGraphAsymmErrors* FinalMu3PtLargestSigBig_ = new TGraphAsymmErrors(Mu3PtLargestSigBig_);
  TGraphAsymmErrors* FinalPfCandSizeSigBig_ = new TGraphAsymmErrors(PfCandSizeSigBig_);
  TGraphAsymmErrors* FinalDRMu3Mu1SigBig_ = new TGraphAsymmErrors(DRMu3Mu1SigBig_);
  TGraphAsymmErrors* FinalDRMu3Mu2SigBig_ = new TGraphAsymmErrors(DRMu3Mu2SigBig_);
  TGraphAsymmErrors* FinalClosetsdRSigBig_ = new TGraphAsymmErrors(ClosetsdRSigBig_);
  TGraphAsymmErrors* FinalMu3IsoSigBig_ = new TGraphAsymmErrors(Mu3IsoSigBig_);

  // Setting colors
  FinalMu3PtTT_->SetMarkerColor(kBlue+1);
  FinalMu3PtLargestTT_->SetMarkerColor(kBlue+1);
  FinalPfCandSizeTT_->SetMarkerColor(kBlue+1);
  FinalDRMu3Mu1TT_->SetMarkerColor(kBlue+1);
  FinalDRMu3Mu2TT_->SetMarkerColor(kBlue+1);
  FinalClosetsdRTT_->SetMarkerColor(kBlue+1);
  FinalMu3IsoTT_->SetMarkerColor(kBlue+1);

  FinalMu3PtWJ_->SetMarkerColor(kRed+1);
  FinalMu3PtLargestWJ_->SetMarkerColor(kRed+1);
  FinalPfCandSizeWJ_->SetMarkerColor(kRed+1);
  FinalDRMu3Mu1WJ_->SetMarkerColor(kRed+1);
  FinalDRMu3Mu2WJ_->SetMarkerColor(kRed+1);
  FinalClosetsdRWJ_->SetMarkerColor(kRed+1);
  FinalMu3IsoWJ_->SetMarkerColor(kRed+1);

  FinalMu3PtDY_->SetMarkerColor(kGreen+1);
  FinalMu3PtLargestDY_->SetMarkerColor(kGreen+1);
  FinalPfCandSizeDY_->SetMarkerColor(kGreen+1);
  FinalDRMu3Mu1DY_->SetMarkerColor(kGreen+1);
  FinalDRMu3Mu2DY_->SetMarkerColor(kGreen+1);
  FinalClosetsdRDY_->SetMarkerColor(kGreen+1);
  FinalMu3IsoDY_->SetMarkerColor(kGreen+1);

  FinalMu3PtSig_->SetMarkerColor(kBlack);
  FinalMu3PtLargestSig_->SetMarkerColor(kBlack);
  FinalPfCandSizeSig_->SetMarkerColor(kBlack);
  FinalDRMu3Mu1Sig_->SetMarkerColor(kBlack);
  FinalDRMu3Mu2Sig_->SetMarkerColor(kBlack);
  FinalClosetsdRSig_->SetMarkerColor(kBlack);
  FinalMu3IsoSig_->SetMarkerColor(kBlack);

  FinalMu3PtSigBig_->SetMarkerColor(kViolet-2);
  FinalMu3PtLargestSigBig_->SetMarkerColor(kViolet-2);
  FinalPfCandSizeSigBig_->SetMarkerColor(kViolet-2);
  FinalDRMu3Mu1SigBig_->SetMarkerColor(kViolet-2);
  FinalDRMu3Mu2SigBig_->SetMarkerColor(kViolet-2);
  FinalClosetsdRSigBig_->SetMarkerColor(kViolet-2);
  FinalMu3IsoSigBig_->SetMarkerColor(kViolet-2);

  //Setting Marker Size
  FinalMu3PtTT_->SetMarkerSize(.07);
  FinalMu3PtLargestTT_->SetMarkerSize(.07);
  FinalPfCandSizeTT_->SetMarkerSize(.07);
  FinalDRMu3Mu1TT_->SetMarkerSize(.07);
  FinalDRMu3Mu2TT_->SetMarkerSize(.07);
  FinalClosetsdRTT_->SetMarkerSize(.07);
  FinalMu3IsoTT_->SetMarkerSize(.07);
  
  FinalMu3PtWJ_->SetMarkerSize(.07);
  FinalMu3PtLargestWJ_->SetMarkerSize(.07);
  FinalPfCandSizeWJ_->SetMarkerSize(.07);
  FinalDRMu3Mu1WJ_->SetMarkerSize(.07);
  FinalDRMu3Mu2WJ_->SetMarkerSize(.07);
  FinalClosetsdRWJ_->SetMarkerSize(.07);
  FinalMu3IsoWJ_->SetMarkerSize(.07);
  
  FinalMu3PtDY_->SetMarkerSize(.07);
  FinalMu3PtLargestDY_->SetMarkerSize(.07);
  FinalPfCandSizeDY_->SetMarkerSize(.07);
  FinalDRMu3Mu1DY_->SetMarkerSize(.07);
  FinalDRMu3Mu2DY_->SetMarkerSize(.07);
  FinalClosetsdRDY_->SetMarkerSize(.07);
  FinalMu3IsoDY_->SetMarkerSize(.07);
  
  FinalMu3PtSig_->SetMarkerSize(.07);
  FinalMu3PtLargestSig_->SetMarkerSize(.07);
  FinalPfCandSizeSig_->SetMarkerSize(.07);
  FinalDRMu3Mu1Sig_->SetMarkerSize(.07);
  FinalDRMu3Mu2Sig_->SetMarkerSize(.07);
  FinalClosetsdRSig_->SetMarkerSize(.07);
  FinalMu3IsoSig_->SetMarkerSize(.07);
  
  FinalMu3PtSigBig_->SetMarkerSize(.07);
  FinalMu3PtLargestSigBig_->SetMarkerSize(.07);
  FinalPfCandSizeSigBig_->SetMarkerSize(.07);
  FinalDRMu3Mu1SigBig_->SetMarkerSize(.07);
  FinalDRMu3Mu2SigBig_->SetMarkerSize(.07);
  FinalClosetsdRSigBig_->SetMarkerSize(.07);
  FinalMu3IsoSigBig_->SetMarkerSize(.07);

  //Set line Color
  FinalMu3PtTT_->SetLineColor(kBlue+1);
  FinalMu3PtLargestTT_->SetLineColor(kBlue+1);
  FinalPfCandSizeTT_->SetLineColor(kBlue+1);
  FinalDRMu3Mu1TT_->SetLineColor(kBlue+1);
  FinalDRMu3Mu2TT_->SetLineColor(kBlue+1);
  FinalClosetsdRTT_->SetLineColor(kBlue+1);
  FinalMu3IsoTT_->SetLineColor(kBlue+1);

  FinalMu3PtWJ_->SetLineColor(kRed+1);
  FinalMu3PtLargestWJ_->SetLineColor(kRed+1);
  FinalPfCandSizeWJ_->SetLineColor(kRed+1);
  FinalDRMu3Mu1WJ_->SetLineColor(kRed+1);
  FinalDRMu3Mu2WJ_->SetLineColor(kRed+1);
  FinalClosetsdRWJ_->SetLineColor(kRed+1);
  FinalMu3IsoWJ_->SetLineColor(kRed+1);

  FinalMu3PtDY_->SetLineColor(kGreen+1);
  FinalMu3PtLargestDY_->SetLineColor(kGreen+1);
  FinalPfCandSizeDY_->SetLineColor(kGreen+1);
  FinalDRMu3Mu1DY_->SetLineColor(kGreen+1);
  FinalDRMu3Mu2DY_->SetLineColor(kGreen+1);
  FinalClosetsdRDY_->SetLineColor(kGreen+1);
  FinalMu3IsoDY_->SetLineColor(kGreen+1);

  FinalMu3PtSig_->SetLineColor(kBlack);
  FinalMu3PtLargestSig_->SetLineColor(kBlack);
  FinalPfCandSizeSig_->SetLineColor(kBlack);
  FinalDRMu3Mu1Sig_->SetLineColor(kBlack);
  FinalDRMu3Mu2Sig_->SetLineColor(kBlack);
  FinalClosetsdRSig_->SetLineColor(kBlack);
  FinalMu3IsoSig_->SetLineColor(kBlack);

  FinalMu3PtSigBig_->SetLineColor(kViolet-2);
  FinalMu3PtLargestSigBig_->SetLineColor(kViolet-2);
  FinalPfCandSizeSigBig_->SetLineColor(kViolet-2);
  FinalDRMu3Mu1SigBig_->SetLineColor(kViolet-2);
  FinalDRMu3Mu2SigBig_->SetLineColor(kViolet-2);
  FinalClosetsdRSigBig_->SetLineColor(kViolet-2);
  FinalMu3IsoSigBig_->SetLineColor(kViolet-2);

  //Set Titles
  FinalMu3PtTT_->GetXaxis()->SetTitle("Mu3 p_{T}");
  FinalMu3PtLargestTT_->GetXaxis()->SetTitle("Largest Mu3 p_{T}");
  FinalPfCandSizeTT_->GetXaxis()->SetTitle("# of PFCand in #DeltaR < 0.4 of Mu3");
  FinalDRMu3Mu1TT_->GetXaxis()->SetTitle("#DeltaR(Mu1, Mu3)");
  FinalDRMu3Mu2TT_->GetXaxis()->SetTitle("#DeltaR(Mu3, Mu2)");
  FinalClosetsdRTT_->GetXaxis()->SetTitle("#DeltaR(Mu3, closest Mu1 or Mu2)");
  FinalMu3IsoTT_->GetXaxis()->SetTitle("Relative Iso in cone < .4 of Mu3");

  FinalMu3PtWJ_->GetXaxis()->SetTitle("Mu3 p_{T}");
  FinalMu3PtLargestWJ_->GetXaxis()->SetTitle("Largest Mu3 p_{T}");
  FinalPfCandSizeWJ_->GetXaxis()->SetTitle("# of PFCand in #DeltaR < 0.4 of Mu3");
  FinalDRMu3Mu1WJ_->GetXaxis()->SetTitle("#DeltaR(Mu1, Mu3)");
  FinalDRMu3Mu2WJ_->GetXaxis()->SetTitle("#DeltaR(Mu3, Mu2)");
  FinalClosetsdRWJ_->GetXaxis()->SetTitle("#DeltaR(Mu3, closest Mu1 or Mu2)");
  FinalMu3IsoWJ_->GetXaxis()->SetTitle("Relative Iso in cone < .4 of Mu3");

  FinalMu3PtDY_->GetXaxis()->SetTitle("Mu3 p_{T}");
  FinalMu3PtLargestDY_->GetXaxis()->SetTitle("Largest Mu3 p_{T}");
  FinalPfCandSizeDY_->GetXaxis()->SetTitle("# of PFCand in #DeltaR < 0.4 of Mu3");
  FinalDRMu3Mu1DY_->GetXaxis()->SetTitle("#DeltaR(Mu1, Mu3)");
  FinalDRMu3Mu2DY_->GetXaxis()->SetTitle("#DeltaR(Mu3, Mu2)");
  FinalClosetsdRDY_->GetXaxis()->SetTitle("#DeltaR(Mu3, closest Mu1 or Mu2)");
  FinalMu3IsoDY_->GetXaxis()->SetTitle("Relative Iso in cone < .4 of Mu3");

  FinalMu3PtSig_->GetXaxis()->SetTitle("Mu3 p_{T}");
  FinalMu3PtLargestSig_->GetXaxis()->SetTitle("Largest Mu3 p_{T}");
  FinalPfCandSizeSig_->GetXaxis()->SetTitle("# of PFCand in #DeltaR < 0.4 of Mu3");
  FinalDRMu3Mu1Sig_->GetXaxis()->SetTitle("#DeltaR(Mu1, Mu3)");
  FinalDRMu3Mu2Sig_->GetXaxis()->SetTitle("#DeltaR(Mu2, Mu3)");
  FinalClosetsdRSig_->GetXaxis()->SetTitle("#DeltaR(Mu3, closest Mu1 or Mu2)");
  FinalMu3IsoSig_->GetXaxis()->SetTitle("Relative Iso in cone < .4 of Mu3");

  FinalMu3PtSigBig_->GetXaxis()->SetTitle("Mu3 p_{T}");
  FinalMu3PtLargestSigBig_->GetXaxis()->SetTitle("Largest Mu3 p_{T}");
  FinalPfCandSizeSigBig_->GetXaxis()->SetTitle("# of PFCand in #DeltaR < 0.4 of Mu3");
  FinalDRMu3Mu1SigBig_->GetXaxis()->SetTitle("#DeltaR(Mu1, Mu3)");
  FinalDRMu3Mu2SigBig_->GetXaxis()->SetTitle("#DeltaR(Mu3, Mu2)");
  FinalClosetsdRSigBig_->GetXaxis()->SetTitle("#DeltaR(Mu3, closest Mu1 or Mu2)");
  FinalMu3IsoSigBig_->GetXaxis()->SetTitle("Relative Iso in cone < .4 of Mu3");

  //Set Titles
  FinalMu3PtTT_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalMu3PtLargestTT_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalPfCandSizeTT_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalDRMu3Mu1TT_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalDRMu3Mu2TT_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalClosetsdRTT_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalMu3IsoTT_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  
  FinalMu3PtWJ_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalMu3PtLargestWJ_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalPfCandSizeWJ_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalDRMu3Mu1WJ_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalDRMu3Mu2WJ_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalClosetsdRWJ_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalMu3IsoWJ_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  
  FinalMu3PtDY_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalMu3PtLargestDY_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalPfCandSizeDY_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalDRMu3Mu1DY_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalDRMu3Mu2DY_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalClosetsdRDY_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalMu3IsoDY_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  
  FinalMu3PtSig_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalMu3PtLargestSig_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalPfCandSizeSig_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalDRMu3Mu1Sig_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalDRMu3Mu2Sig_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalClosetsdRSig_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalMu3IsoSig_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");

  FinalMu3PtSigBig_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalMu3PtLargestSigBig_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalPfCandSizeSigBig_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalDRMu3Mu1SigBig_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalDRMu3Mu2SigBig_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalClosetsdRSigBig_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalMu3IsoSigBig_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");

  //Set Line Width
  FinalMu3PtTT_->SetLineWidth(2);
  FinalMu3PtLargestTT_->SetLineWidth(2);
  FinalPfCandSizeTT_->SetLineWidth(2);
  FinalDRMu3Mu1TT_->SetLineWidth(2);
  FinalDRMu3Mu2TT_->SetLineWidth(2);
  FinalClosetsdRTT_->SetLineWidth(2);
  FinalMu3IsoTT_->SetLineWidth(2);
  
  FinalMu3PtWJ_->SetLineWidth(2);
  FinalMu3PtLargestWJ_->SetLineWidth(2);
  FinalPfCandSizeWJ_->SetLineWidth(2);
  FinalDRMu3Mu1WJ_->SetLineWidth(2);
  FinalDRMu3Mu2WJ_->SetLineWidth(2);
  FinalClosetsdRWJ_->SetLineWidth(2);
  FinalMu3IsoWJ_->SetLineWidth(2);
  
  FinalMu3PtDY_->SetLineWidth(2);
  FinalMu3PtLargestDY_->SetLineWidth(2);
  FinalPfCandSizeDY_->SetLineWidth(2);
  FinalDRMu3Mu1DY_->SetLineWidth(2);
  FinalDRMu3Mu2DY_->SetLineWidth(2);
  FinalClosetsdRDY_->SetLineWidth(2);
  FinalMu3IsoDY_->SetLineWidth(2);

  FinalMu3PtSig_->SetLineWidth(2);
  FinalMu3PtLargestSig_->SetLineWidth(2);
  FinalPfCandSizeSig_->SetLineWidth(2);
  FinalDRMu3Mu1Sig_->SetLineWidth(2);
  FinalDRMu3Mu2Sig_->SetLineWidth(2);
  FinalClosetsdRSig_->SetLineWidth(2);
  FinalMu3IsoSig_->SetLineWidth(2);

  FinalMu3PtSigBig_->SetLineWidth(2);
  FinalMu3PtLargestSigBig_->SetLineWidth(2);
  FinalPfCandSizeSigBig_->SetLineWidth(2);
  FinalDRMu3Mu1SigBig_->SetLineWidth(2);
  FinalDRMu3Mu2SigBig_->SetLineWidth(2);
  FinalClosetsdRSigBig_->SetLineWidth(2);
  FinalMu3IsoSigBig_->SetLineWidth(2);

  PtMu3vsIsoLargestPtTT_->SetTitle("TTBar");
  PtMu3vsIsoTT_->SetTitle("TTBar");
  PtMu3vsIsoNoRelTT_->SetTitle("TTBar");
  PtMu3vsIsoLargestPtWJ_->SetTitle("WJets");
  PtMu3vsIsoWJ_->SetTitle("WJets");
  PtMu3vsIsoNoRelWJ_->SetTitle("WJets");
  PtMu3vsIsoLargestPtDY_->SetTitle("DY M=50");
  PtMu3vsIsoDY_->SetTitle("DY M=50");
  PtMu3vsIsoNoRelDY_->SetTitle("DY M=50");
  PtMu3vsIsoLargestPtSig_->SetTitle("M_{h} = 125");
  PtMu3vsIsoSig_->SetTitle("M_{h} = 125");
  PtMu3vsIsoNoRelSig_->SetTitle("M_{h} = 125");
  PtMu3vsIsoLargestPtSigBig_->SetTitle("M_{h} = 750");
  PtMu3vsIsoSigBig_->SetTitle("M_{h} = 750");
  PtMu3vsIsoNoRelSigBig_->SetTitle("M_{h} = 750");

cout << "Attributes set." << endl;  

  //Making the Legend
  leg = new TLegend(0.1,0.7,0.25,0.9);
  leg->AddEntry(FinalMu3PtTT_, "TTbar","L");
  leg->AddEntry(FinalMu3PtDY_, "DY","L");
  leg->AddEntry(FinalMu3PtWJ_, "WJets","L");
  leg->AddEntry(FinalMu3PtSig_,"Signal H125","L");
  leg->AddEntry(FinalMu3PtSigBig_,"Signal H750","L");

  //Drawing all of the Overlaid Lepton Matched HIstograms
  Mu3PtCanvasTOT_.cd();
  FinalMu3PtTT_->Draw();
  FinalMu3PtWJ_->Draw("SAME");
  FinalMu3PtDY_->Draw("SAME");
  FinalMu3PtSig_->Draw("SAME");
  FinalMu3PtSigBig_->Draw("SAME");
  leg->Draw();

  Mu3PtLargestCanvasTOT_.cd();
  FinalMu3PtLargestTT_->Draw();
  FinalMu3PtLargestWJ_->Draw("SAME");
  FinalMu3PtLargestDY_->Draw("SAME");
  FinalMu3PtLargestSig_->Draw("SAME");
  FinalMu3PtLargestSigBig_->Draw("SAME");
  leg->Draw();

  PfCandSizeCanvasTOT_.cd();
  FinalPfCandSizeTT_->Draw();
  FinalPfCandSizeWJ_->Draw("SAME");
  FinalPfCandSizeDY_->Draw("SAME");
  FinalPfCandSizeSig_->Draw("SAME");
  FinalPfCandSizeSigBig_->Draw("SAME");
  leg->Draw();

  DRMu3Mu1CanvasTOT_.cd();
  FinalDRMu3Mu1TT_->Draw();
  FinalDRMu3Mu1WJ_->Draw("SAME");
  FinalDRMu3Mu1DY_->Draw("SAME");
  FinalDRMu3Mu1Sig_->Draw("SAME");
  FinalDRMu3Mu1SigBig_->Draw("SAME");
  leg->Draw();

  DRMu3Mu2CanvasTOT_.cd();
  FinalDRMu3Mu2TT_->Draw();
  FinalDRMu3Mu2WJ_->Draw("SAME");
  FinalDRMu3Mu2DY_->Draw("SAME");
  FinalDRMu3Mu2Sig_->Draw("SAME");
  FinalDRMu3Mu2SigBig_->Draw("SAME");
  leg->Draw();

  ClosetsdRCanvasTOT_.cd();
  FinalClosetsdRTT_->Draw();
  FinalClosetsdRWJ_->Draw("SAME");
  FinalClosetsdRDY_->Draw("SAME");
  FinalClosetsdRSig_->Draw("SAME");
  FinalClosetsdRSigBig_->Draw("SAME");
  leg->Draw();

  Mu3IsoCanvasTOT_.cd();
  FinalMu3IsoTT_->Draw();
  FinalMu3IsoWJ_->Draw("SAME");
  FinalMu3IsoDY_->Draw("SAME");
  FinalMu3IsoSig_->Draw("SAME");
  FinalMu3IsoSigBig_->Draw("SAME");
  leg->Draw();

  Mu3PtvsIsoCanvasTOT_.cd(1);
  PtMu3vsIsoTT_->Draw("COLZ");
  Mu3PtvsIsoCanvasTOT_.cd(2);
  PtMu3vsIsoWJ_->Draw("COLZ");
  Mu3PtvsIsoCanvasTOT_.cd(3);
  PtMu3vsIsoDY_->Draw("COLZ");
  Mu3PtvsIsoCanvasTOT_.cd(4);
  PtMu3vsIsoSig_->Draw("COLZ");
  Mu3PtvsIsoCanvasTOT_.cd(5);
  PtMu3vsIsoSigBig_->Draw("COLZ");

  Mu3PtvsIsoNoRelCanvasTOT_.cd(1);
  PtMu3vsIsoNoRelTT_->Draw("COLZ");
  Mu3PtvsIsoNoRelCanvasTOT_.cd(2);
  PtMu3vsIsoNoRelWJ_->Draw("COLZ");
  Mu3PtvsIsoNoRelCanvasTOT_.cd(3);
  PtMu3vsIsoNoRelDY_->Draw("COLZ");
  Mu3PtvsIsoNoRelCanvasTOT_.cd(4);
  PtMu3vsIsoNoRelSig_->Draw("COLZ");
  Mu3PtvsIsoNoRelCanvasTOT_.cd(5);
  PtMu3vsIsoNoRelSigBig_->Draw("COLZ");

  Mu3PtLargestvsIsoCanvasTOT_.cd(1);
  PtMu3vsIsoLargestPtTT_->Draw("COLZ");
  Mu3PtLargestvsIsoCanvasTOT_.cd(2);
  PtMu3vsIsoLargestPtWJ_->Draw("COLZ");
  Mu3PtLargestvsIsoCanvasTOT_.cd(3);
  PtMu3vsIsoLargestPtDY_->Draw("COLZ");
  Mu3PtLargestvsIsoCanvasTOT_.cd(4);
  PtMu3vsIsoLargestPtSig_->Draw("COLZ");
  Mu3PtLargestvsIsoCanvasTOT_.cd(5);
  PtMu3vsIsoLargestPtSigBig_->Draw("COLZ");

cout << "Histograms Drawn" << endl;

  outFile->cd();
  Mu3PtCanvasTOT_.Write();
  Mu3PtLargestCanvasTOT_.Write();
  PfCandSizeCanvasTOT_.Write();
  DRMu3Mu1CanvasTOT_.Write();
  DRMu3Mu2CanvasTOT_.Write();
  ClosetsdRCanvasTOT_.Write();
  Mu3IsoCanvasTOT_.Write();

  Mu3PtLargestvsIsoCanvasTOT_.Write();
  Mu3PtvsIsoCanvasTOT_.Write();
  Mu3PtvsIsoNoRelCanvasTOT_.Write();
  outFile->Write();
  outFile->Close();
cout << "end" << endl;

}//rootMacro_BBA_combine
