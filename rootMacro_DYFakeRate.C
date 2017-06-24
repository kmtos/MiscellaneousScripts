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


void rootMacro_DYFakeRate()
{

  gStyle->SetOptStat(kFALSE);
  gStyle->SetEndErrorSize(7);

  TFile infile ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/FINAL_DY_FakeRate_Inv81to101_NoTauSelection_NoMinMu3Obj_JUN13_ReqRemovedMuon.root");
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/combHist_DY_FakeRate_Inv81to101_NoTauSelection_NoMinMu3Obj_JUN13_ReqRemovedMuon.root", "RECREATE");

cout << "Files Created" << endl;
  // 
  TCanvas* TauLooseIsoEtaCanvas = (TCanvas*)infile.Get("TauLooseIsoEta");
  TCanvas* TauMedIsoEtaCanvas = (TCanvas*)infile.Get("TauMedIsoEta");
  TCanvas* TauTightIsoEtaCanvas = (TCanvas*)infile.Get("TauTightIsoEta");
  TCanvas* TauDMFindEtaCanvas = (TCanvas*)infile.Get("TauDMFindEta");
  TCanvas* JetEtaCanvas = (TCanvas*)infile.Get("JetEta");

  TCanvas* TauLooseIsoPtCanvas = (TCanvas*)infile.Get("TauLooseIsoPt");
  TCanvas* TauMedIsoPtCanvas = (TCanvas*)infile.Get("TauMedIsoPt");
  TCanvas* TauTightIsoPtCanvas = (TCanvas*)infile.Get("TauTightIsoPt");
  TCanvas* TauDMFindPtCanvas = (TCanvas*)infile.Get("TauDMFindPt");
  TCanvas* JetPtCanvas = (TCanvas*)infile.Get("JetPt");

  TCanvas* OneProngDMEtaCanvas = (TCanvas*)infile.Get("OneProngDMEta");
  TCanvas* OneProngOnePizDMEtaCanvas = (TCanvas*)infile.Get("OneProngOnePizDMEta");
  TCanvas* OneProngTwoPizDMEtaCanvas = (TCanvas*)infile.Get("OneProngTwoPizDMEta");
  TCanvas* ThreeProngDMEtaCanvas = (TCanvas*)infile.Get("ThreeProngDMEta");
  TCanvas* OneProngDMPtCanvas = (TCanvas*)infile.Get("OneProngDMPt");
  TCanvas* OneProngOnePizDMPtCanvas = (TCanvas*)infile.Get("OneProngOnePizDMPt");
  TCanvas* OneProngTwoPizDMPtCanvas = (TCanvas*)infile.Get("OneProngTwoPizDMPt");
  TCanvas* ThreeProngDMPtCanvas = (TCanvas*)infile.Get("ThreeProngDMPt");

  TCanvas* OneProngMedIsoEtaCanvas = (TCanvas*)infile.Get("OneProngMedIsoEta");
  TCanvas* OneProngOnePizMedIsoEtaCanvas = (TCanvas*)infile.Get("OneProngOnePizMedIsoEta");
  TCanvas* OneProngTwoPizMedIsoEtaCanvas = (TCanvas*)infile.Get("OneProngTwoPizMedIsoEta");
  TCanvas* ThreeProngMedIsoEtaCanvas = (TCanvas*)infile.Get("ThreeProngMedIsoEta");
  TCanvas* OneProngMedIsoPtCanvas = (TCanvas*)infile.Get("OneProngMedIsoPt");
  TCanvas* OneProngOnePizMedIsoPtCanvas = (TCanvas*)infile.Get("OneProngOnePizMedIsoPt");
  TCanvas* OneProngTwoPizMedIsoPtCanvas = (TCanvas*)infile.Get("OneProngTwoPizMedIsoPt");
  TCanvas* ThreeProngMedIsoPtCanvas = (TCanvas*)infile.Get("ThreeProngMedIsoPt");

cout << "Got Canvases" << endl;

// Getting the histograms for the DM New
  TH1F* TauLooseIsoEta_ = (TH1F*)TauLooseIsoEtaCanvas->GetPrimitive("TauLooseIsoEta");
std::cout << "check1" << std::endl;
  TH1F* TauMedIsoEta_ = (TH1F*)TauMedIsoEtaCanvas->GetPrimitive("TauMedIsoEta");
  TH1F* TauTightIsoEta_ = (TH1F*)TauTightIsoEtaCanvas->GetPrimitive("TauTightIsoEta");
  TH1F* TauDMFindEta_ = (TH1F*)TauDMFindEtaCanvas->GetPrimitive("TauDMFindEta");
  TH1F* JetEta_ = (TH1F*)JetEtaCanvas->GetPrimitive("JetEta");
  
  TH1F* TauLooseIsoPt_ = (TH1F*)TauLooseIsoPtCanvas->GetPrimitive("TauLooseIsoPt");
  TH1F* TauMedIsoPt_ = (TH1F*)TauMedIsoPtCanvas->GetPrimitive("TauMedIsoPt");
  TH1F* TauTightIsoPt_ = (TH1F*)TauTightIsoPtCanvas->GetPrimitive("TauTightIsoPt");
  TH1F* TauDMFindPt_ = (TH1F*)TauDMFindPtCanvas->GetPrimitive("TauDMFindPt");
  TH1F* JetPt_ = (TH1F*)JetPtCanvas->GetPrimitive("JetPt");

  TH1F* OneProngDMEta_ = (TH1F*)OneProngDMEtaCanvas->GetPrimitive("OneProngDMEta");
  TH1F* OneProngOnePizDMEta_ = (TH1F*)OneProngOnePizDMEtaCanvas->GetPrimitive("OneProngOnePizDMEta");
  TH1F* OneProngTwoPizDMEta_ = (TH1F*)OneProngTwoPizDMEtaCanvas->GetPrimitive("OneProngTwoPizDMEta");
  TH1F* ThreeProngDMEta_ = (TH1F*)ThreeProngDMEtaCanvas->GetPrimitive("ThreeProngDMEta");
  TH1F* OneProngDMPt_ = (TH1F*)OneProngDMPtCanvas->GetPrimitive("OneProngDMPt");
  TH1F* OneProngOnePizDMPt_ = (TH1F*)OneProngOnePizDMPtCanvas->GetPrimitive("OneProngOnePizDMPt");
  TH1F* OneProngTwoPizDMPt_ = (TH1F*)OneProngTwoPizDMPtCanvas->GetPrimitive("OneProngTwoPizDMPt");
  TH1F* ThreeProngDMPt_ = (TH1F*)ThreeProngDMPtCanvas->GetPrimitive("ThreeProngDMPt");

  TH1F* OneProngMedIsoEta_ = (TH1F*)OneProngMedIsoEtaCanvas->GetPrimitive("OneProngMedIsoEta");
  TH1F* OneProngOnePizMedIsoEta_ = (TH1F*)OneProngOnePizMedIsoEtaCanvas->GetPrimitive("OneProngOnePizMedIsoEta");
  TH1F* OneProngTwoPizMedIsoEta_ = (TH1F*)OneProngTwoPizMedIsoEtaCanvas->GetPrimitive("OneProngTwoPizMedIsoEta");
  TH1F* ThreeProngMedIsoEta_ = (TH1F*)ThreeProngMedIsoEtaCanvas->GetPrimitive("ThreeProngMedIsoEta");
  TH1F* OneProngMedIsoPt_ = (TH1F*)OneProngMedIsoPtCanvas->GetPrimitive("OneProngMedIsoPt");
  TH1F* OneProngOnePizMedIsoPt_ = (TH1F*)OneProngOnePizMedIsoPtCanvas->GetPrimitive("OneProngOnePizMedIsoPt");
  TH1F* OneProngTwoPizMedIsoPt_ = (TH1F*)OneProngTwoPizMedIsoPtCanvas->GetPrimitive("OneProngTwoPizMedIsoPt");
  TH1F* ThreeProngMedIsoPt_ = (TH1F*)ThreeProngMedIsoPtCanvas->GetPrimitive("ThreeProngMedIsoPt");

std::cout << "Declaring TGraph" << std::endl;
  // To divide histograms for efficiency with Old Gen Matching New DM's
  TGraphAsymmErrors* FinalFakeRateLooseIsoPt_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateMedIsoPt_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateTightIsoPt_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateDMFindPt_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalFakeRateLooseIsoEta_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateMedIsoEta_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateTightIsoEta_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateDMFindEta_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalFakeRateOneProngDMEta_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngOnePizDMEta_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngTwoPizDMEta_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateThreeProngDMEta_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngDMPt_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngOnePizDMPt_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngTwoPizDMPt_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateThreeProngDMPt_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalFakeRateOneProngMedIsoEta_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngOnePizMedIsoEta_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngTwoPizMedIsoEta_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateThreeProngMedIsoEta_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngMedIsoPt_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngOnePizMedIsoPt_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngTwoPizMedIsoPt_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateThreeProngMedIsoPt_ = new TGraphAsymmErrors(30);

std::cout << "Dividing" << std::endl;
  //Divide
  FinalFakeRateLooseIsoEta_->Divide(TauLooseIsoEta_, JetEta_ );
  FinalFakeRateMedIsoEta_->Divide(TauMedIsoEta_, JetEta_ );
  FinalFakeRateTightIsoEta_->Divide(TauTightIsoEta_, JetEta_ );
  FinalFakeRateDMFindEta_->Divide(TauDMFindEta_, JetEta_ );

  FinalFakeRateLooseIsoPt_->Divide(TauLooseIsoPt_, JetPt_ );
  FinalFakeRateMedIsoPt_->Divide(TauMedIsoPt_, JetPt_ );
  FinalFakeRateTightIsoPt_->Divide(TauTightIsoPt_, JetPt_ );
  FinalFakeRateDMFindPt_->Divide(TauDMFindPt_, JetPt_ );

  FinalFakeRateOneProngDMEta_->Divide(OneProngDMEta_, JetEta_);
  FinalFakeRateOneProngOnePizDMEta_->Divide(OneProngOnePizDMEta_, JetEta_);
  FinalFakeRateOneProngTwoPizDMEta_->Divide(OneProngTwoPizDMEta_, JetEta_);
  FinalFakeRateThreeProngDMEta_->Divide(ThreeProngDMEta_, JetEta_);
  FinalFakeRateOneProngDMPt_->Divide(OneProngDMPt_, JetPt_);
  FinalFakeRateOneProngOnePizDMPt_->Divide(OneProngOnePizDMPt_, JetPt_);
  FinalFakeRateOneProngTwoPizDMPt_->Divide(OneProngTwoPizDMPt_, JetPt_);
  FinalFakeRateThreeProngDMPt_->Divide(ThreeProngDMPt_, JetPt_);

  FinalFakeRateOneProngMedIsoEta_->Divide(OneProngMedIsoEta_, JetEta_);
  FinalFakeRateOneProngOnePizMedIsoEta_->Divide(OneProngOnePizMedIsoEta_, JetEta_);
  FinalFakeRateOneProngTwoPizMedIsoEta_->Divide(OneProngTwoPizMedIsoEta_, JetEta_);
  FinalFakeRateThreeProngMedIsoEta_->Divide(ThreeProngMedIsoEta_, JetEta_);
  FinalFakeRateOneProngMedIsoPt_->Divide(OneProngMedIsoPt_, JetPt_);
  FinalFakeRateOneProngOnePizMedIsoPt_->Divide(OneProngOnePizMedIsoPt_, JetPt_);
  FinalFakeRateOneProngTwoPizMedIsoPt_->Divide(OneProngTwoPizMedIsoPt_, JetPt_);
  FinalFakeRateThreeProngMedIsoPt_->Divide(ThreeProngMedIsoPt_, JetPt_);

std::cout << "Formatting" << std::endl;
  //Formatting Pt
  FinalFakeRateLooseIsoPt_->SetName("FakeRateLooseIsoPt");
  FinalFakeRateMedIsoPt_->SetName("FakeRateMedIsoPt");
  FinalFakeRateTightIsoPt_->SetName("FakeRateTightIsoPt");
  FinalFakeRateDMFindPt_->SetName("FakeRateDMFindPt");

  FinalFakeRateLooseIsoPt_->SetMarkerSize(.07);
  FinalFakeRateMedIsoPt_->SetMarkerSize(.07);
  FinalFakeRateTightIsoPt_->SetMarkerSize(.07);
  FinalFakeRateDMFindPt_->SetMarkerSize(.07);

  FinalFakeRateLooseIsoPt_->GetXaxis()->SetTitle("p_{T} of events with a Cleaned Jet");
  FinalFakeRateMedIsoPt_->GetXaxis()->SetTitle("p_{T} of events with a Cleaned Jet");
  FinalFakeRateTightIsoPt_->GetXaxis()->SetTitle("p_{T} of events with a Cleaned Jet");
  FinalFakeRateDMFindPt_->GetXaxis()->SetTitle("p_{T} of events with a Cleaned Jet");

  FinalFakeRateLooseIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Loose Iso + DMFind / # ak4PFJet)");
  FinalFakeRateMedIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + DMFind / # ak4PFJet)");
  FinalFakeRateTightIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Tight Iso + DMFind / # ak4PFJet)");
  FinalFakeRateDMFindPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + DMFind / # ak4PFJet)");

  FinalFakeRateLooseIsoPt_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateMedIsoPt_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateTightIsoPt_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMFindPt_->GetYaxis()->SetTitleOffset(1.5);

  FinalFakeRateLooseIsoPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateMedIsoPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateTightIsoPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateDMFindPt_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalFakeRateLooseIsoPt_->SetLineWidth(3);
  FinalFakeRateMedIsoPt_->SetLineWidth(3);
  FinalFakeRateTightIsoPt_->SetLineWidth(3);
  FinalFakeRateDMFindPt_->SetLineWidth(3);

  FinalFakeRateLooseIsoPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateMedIsoPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateTightIsoPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateDMFindPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");

  //Formatting Eta
  FinalFakeRateLooseIsoEta_->SetName("FakeRateLooseIsoEta");
  FinalFakeRateMedIsoEta_->SetName("FakeRateMedIsoEta");
  FinalFakeRateTightIsoEta_->SetName("FakeRateTightIsoEta");
  FinalFakeRateDMFindEta_->SetName("FakeRateDMFindEta");

  FinalFakeRateLooseIsoEta_->SetMarkerSize(.07);
  FinalFakeRateMedIsoEta_->SetMarkerSize(.07);
  FinalFakeRateTightIsoEta_->SetMarkerSize(.07);
  FinalFakeRateDMFindEta_->SetMarkerSize(.07);
  
  FinalFakeRateLooseIsoEta_->GetXaxis()->SetTitle("#eta of events with a Cleaned Jet");
  FinalFakeRateMedIsoEta_->GetXaxis()->SetTitle("#eta of events with a Cleaned Jet");
  FinalFakeRateTightIsoEta_->GetXaxis()->SetTitle("#eta of events with a Cleaned Jet");
  FinalFakeRateDMFindEta_->GetXaxis()->SetTitle("#eta of events with a Cleaned Jet");
  
  FinalFakeRateLooseIsoEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Loose Iso + DMFind / # ak4PFJet)");
  FinalFakeRateMedIsoEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + DMFind / # ak4PFJet)");
  FinalFakeRateTightIsoEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Tight Iso + DMFind / # ak4PFJet)");
  FinalFakeRateDMFindEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + DMFind / # ak4PFJet)");
  
  FinalFakeRateLooseIsoEta_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateMedIsoEta_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateTightIsoEta_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMFindEta_->GetYaxis()->SetTitleOffset(1.5);

  FinalFakeRateLooseIsoEta_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateMedIsoEta_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateTightIsoEta_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateDMFindEta_->GetYaxis()->SetRangeUser(0.0, 1.0);
  
  FinalFakeRateLooseIsoEta_->SetLineWidth(3);
  FinalFakeRateMedIsoEta_->SetLineWidth(3);
  FinalFakeRateTightIsoEta_->SetLineWidth(3);
  FinalFakeRateDMFindEta_->SetLineWidth(3);

  FinalFakeRateLooseIsoEta_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateMedIsoEta_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateTightIsoEta_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateDMFindEta_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  
  // Formatting Decay Mode + by DM
  FinalFakeRateOneProngDMEta_->SetName("FakeRateOneProngDMFindEta");
  FinalFakeRateOneProngOnePizDMEta_->SetName("FakeRateOneProngOnePizDMFindEta");
  FinalFakeRateOneProngTwoPizDMEta_->SetName("FakeRateOneProngTwoPizDMFindEta");
  FinalFakeRateThreeProngDMEta_->SetName("FakeRateThreeProngDMFindEta");
  FinalFakeRateOneProngDMPt_->SetName("FakeRateOneProngDMFindPt");
  FinalFakeRateOneProngOnePizDMPt_->SetName("FakeRateOneProngOnePizDMFindPt");
  FinalFakeRateOneProngTwoPizDMPt_->SetName("FakeRateOneProngTwoPizDMFindPt");
  FinalFakeRateThreeProngDMPt_->SetName("FakeRateThreeProngDMFindPt");
  
  FinalFakeRateOneProngMedIsoEta_->SetName("FakeRateOneProngMedIsoEta");
  FinalFakeRateOneProngOnePizMedIsoEta_->SetName("FakeRateOneProngOnePizMedIsoEta");
  FinalFakeRateOneProngTwoPizMedIsoEta_->SetName("FakeRateOneProngTwoPizMedIsoEta");
  FinalFakeRateThreeProngMedIsoEta_->SetName("FakeRateThreeProngMedIsoEta");
  FinalFakeRateOneProngMedIsoPt_->SetName("FakeRateOneProngMedIsoPt");
  FinalFakeRateOneProngOnePizMedIsoPt_->SetName("FakeRateOneProngOnePizMedIsoPt");
  FinalFakeRateOneProngTwoPizMedIsoPt_->SetName("FakeRateOneProngTwoPizMedIsoPt");
  FinalFakeRateThreeProngMedIsoPt_->SetName("FakeRateThreeProngMedIsoPt");

  FinalFakeRateOneProngDMEta_->SetMarkerSize(.07);
  FinalFakeRateOneProngOnePizDMEta_->SetMarkerSize(.07);
  FinalFakeRateOneProngTwoPizDMEta_->SetMarkerSize(.07);
  FinalFakeRateThreeProngDMEta_->SetMarkerSize(.07);
  FinalFakeRateOneProngDMPt_->SetMarkerSize(.07);
  FinalFakeRateOneProngOnePizDMPt_->SetMarkerSize(.07);
  FinalFakeRateOneProngTwoPizDMPt_->SetMarkerSize(.07);
  FinalFakeRateThreeProngDMPt_->SetMarkerSize(.07);

  FinalFakeRateOneProngMedIsoEta_->SetMarkerSize(.07);
  FinalFakeRateOneProngOnePizMedIsoEta_->SetMarkerSize(.07);
  FinalFakeRateOneProngTwoPizMedIsoEta_->SetMarkerSize(.07);
  FinalFakeRateThreeProngMedIsoEta_->SetMarkerSize(.07);
  FinalFakeRateOneProngMedIsoPt_->SetMarkerSize(.07);
  FinalFakeRateOneProngOnePizMedIsoPt_->SetMarkerSize(.07);
  FinalFakeRateOneProngTwoPizMedIsoPt_->SetMarkerSize(.07);
  FinalFakeRateThreeProngMedIsoPt_->SetMarkerSize(.07);

  FinalFakeRateOneProngDMEta_->GetXaxis()->SetTitle("#eta of events with a Cleaned Jet");
  FinalFakeRateOneProngOnePizDMEta_->GetXaxis()->SetTitle("#eta of events with a Cleaned Jet");
  FinalFakeRateOneProngTwoPizDMEta_->GetXaxis()->SetTitle("#eta of events with a Cleaned Jet");
  FinalFakeRateThreeProngDMEta_->GetXaxis()->SetTitle("#eta of events with a Cleaned Jet");
  FinalFakeRateOneProngDMPt_->GetXaxis()->SetTitle("p_{T} of events with a Cleaned Jet");
  FinalFakeRateOneProngOnePizDMPt_->GetXaxis()->SetTitle("p_{T} of events with a Cleaned Jet");
  FinalFakeRateOneProngTwoPizDMPt_->GetXaxis()->SetTitle("p_{T} of events with a Cleaned Jet");
  FinalFakeRateThreeProngDMPt_->GetXaxis()->SetTitle("p_{T} of events with a Cleaned Jet");
  
  FinalFakeRateOneProngMedIsoEta_->GetXaxis()->SetTitle("#eta of events with a Cleaned Jet");
  FinalFakeRateOneProngOnePizMedIsoEta_->GetXaxis()->SetTitle("#eta of events with a Cleaned Jet");
  FinalFakeRateOneProngTwoPizMedIsoEta_->GetXaxis()->SetTitle("#eta of events with a Cleaned Jet");
  FinalFakeRateThreeProngMedIsoEta_->GetXaxis()->SetTitle("#eta of events with a Cleaned Jet");
  FinalFakeRateOneProngMedIsoPt_->GetXaxis()->SetTitle("p_{T} of events with a Cleaned Jet");
  FinalFakeRateOneProngOnePizMedIsoPt_->GetXaxis()->SetTitle("p_{T} of events with a Cleaned Jet");
  FinalFakeRateOneProngTwoPizMedIsoPt_->GetXaxis()->SetTitle("p_{T} of events with a Cleaned Jet");
  FinalFakeRateThreeProngMedIsoPt_->GetXaxis()->SetTitle("p_{T} of events with a Cleaned Jet");

  FinalFakeRateOneProngDMEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-} / # ak4PFJet)");
  FinalFakeRateOneProngOnePizDMEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},1#pi^{0} / # ak4PFJet)");
  FinalFakeRateOneProngTwoPizDMEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},2#pi^{0} / # ak4PFJet)");
  FinalFakeRateThreeProngDMEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 3#pi^{+-} / # ak4PFJet)");
  FinalFakeRateOneProngDMPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-} / # ak4PFJet)");
  FinalFakeRateOneProngOnePizDMPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},1#pi^{0} / # ak4PFJet)");
  FinalFakeRateOneProngTwoPizDMPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},2#pi^{0} / # ak4PFJet)");
  FinalFakeRateThreeProngDMPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 3#pi^{+-} / # ak4PFJet)");

  FinalFakeRateOneProngMedIsoEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-} / # ak4PFJet)");
  FinalFakeRateOneProngOnePizMedIsoEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},1#pi^{0} / # ak4PFJet)");
  FinalFakeRateOneProngTwoPizMedIsoEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},2#pi^{0} / # ak4PFJet)");
  FinalFakeRateThreeProngMedIsoEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 3#pi^{+-} / # ak4PFJet)");
  FinalFakeRateOneProngMedIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-} / # ak4PFJet)");
  FinalFakeRateOneProngOnePizMedIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},1#pi^{0} / # ak4PFJet)");
  FinalFakeRateOneProngTwoPizMedIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},2#pi^{0} / # ak4PFJet)");
  FinalFakeRateThreeProngMedIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 3#pi^{+-} / # ak4PFJet)");

  FinalFakeRateOneProngDMEta_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngOnePizDMEta_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngTwoPizDMEta_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateThreeProngDMEta_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngDMPt_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngOnePizDMPt_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngTwoPizDMPt_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateThreeProngDMPt_->GetXaxis()->SetTitleOffset(1.5);

  FinalFakeRateOneProngMedIsoEta_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngOnePizMedIsoEta_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngTwoPizMedIsoEta_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateThreeProngMedIsoEta_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngMedIsoPt_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngOnePizMedIsoPt_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngTwoPizMedIsoPt_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateThreeProngMedIsoPt_->GetXaxis()->SetTitleOffset(1.5);

  FinalFakeRateOneProngDMEta_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngOnePizDMEta_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngTwoPizDMEta_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateThreeProngDMEta_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngDMPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngOnePizDMPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngTwoPizDMPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateThreeProngDMPt_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalFakeRateOneProngMedIsoEta_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngOnePizMedIsoEta_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngTwoPizMedIsoEta_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateThreeProngMedIsoEta_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngMedIsoPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngOnePizMedIsoPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngTwoPizMedIsoPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateThreeProngMedIsoPt_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalFakeRateOneProngDMEta_->SetLineWidth(3);
  FinalFakeRateOneProngOnePizDMEta_->SetLineWidth(3);
  FinalFakeRateOneProngTwoPizDMEta_->SetLineWidth(3);
  FinalFakeRateThreeProngDMEta_->SetLineWidth(3);
  FinalFakeRateOneProngDMPt_->SetLineWidth(3);
  FinalFakeRateOneProngOnePizDMPt_->SetLineWidth(3);
  FinalFakeRateOneProngTwoPizDMPt_->SetLineWidth(3);
  FinalFakeRateThreeProngDMPt_->SetLineWidth(3);

  FinalFakeRateOneProngMedIsoEta_->SetLineWidth(3);
  FinalFakeRateOneProngOnePizMedIsoEta_->SetLineWidth(3);
  FinalFakeRateOneProngTwoPizMedIsoEta_->SetLineWidth(3);
  FinalFakeRateThreeProngMedIsoEta_->SetLineWidth(3);
  FinalFakeRateOneProngMedIsoPt_->SetLineWidth(3);
  FinalFakeRateOneProngOnePizMedIsoPt_->SetLineWidth(3);
  FinalFakeRateOneProngTwoPizMedIsoPt_->SetLineWidth(3);
  FinalFakeRateThreeProngMedIsoPt_->SetLineWidth(3);

  FinalFakeRateOneProngDMEta_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngOnePizDMEta_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngTwoPizDMEta_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateThreeProngDMEta_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngDMPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngOnePizDMPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngTwoPizDMPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateThreeProngDMPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");

  FinalFakeRateOneProngMedIsoEta_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngOnePizMedIsoEta_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngTwoPizMedIsoEta_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateThreeProngMedIsoEta_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngMedIsoPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngOnePizMedIsoPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngTwoPizMedIsoPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateThreeProngMedIsoPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");



cout << "Attributes set." << endl;  

  //Writing
  outFile->cd();

  TauLooseIsoEtaCanvas->Write();
  TauMedIsoEtaCanvas->Write();
  TauTightIsoEtaCanvas->Write();
  TauDMFindEtaCanvas->Write();
  JetEtaCanvas->Write();

  TauLooseIsoPtCanvas->Write();
  TauMedIsoPtCanvas->Write();
  TauTightIsoPtCanvas->Write();
  TauDMFindPtCanvas->Write();
  JetPtCanvas->Write();

  OneProngDMEtaCanvas->Write();
  OneProngOnePizDMEtaCanvas->Write();
  OneProngTwoPizDMEtaCanvas->Write();
  ThreeProngDMEtaCanvas->Write();
  OneProngDMPtCanvas->Write();
  OneProngOnePizDMPtCanvas->Write();
  OneProngTwoPizDMPtCanvas->Write();
  ThreeProngDMPtCanvas->Write();
  
  OneProngMedIsoEtaCanvas->Write();
  OneProngOnePizMedIsoEtaCanvas->Write();
  OneProngTwoPizMedIsoEtaCanvas->Write();
  ThreeProngMedIsoEtaCanvas->Write();
  OneProngMedIsoPtCanvas->Write();
  OneProngOnePizMedIsoPtCanvas->Write();
  OneProngTwoPizMedIsoPtCanvas->Write();
  ThreeProngMedIsoPtCanvas->Write();

  FinalFakeRateLooseIsoPt_->Write();
  FinalFakeRateMedIsoPt_->Write();
  FinalFakeRateTightIsoPt_->Write();
  FinalFakeRateDMFindPt_->Write();
  
  FinalFakeRateLooseIsoEta_->Write();
  FinalFakeRateMedIsoEta_->Write();
  FinalFakeRateTightIsoEta_->Write();
  FinalFakeRateDMFindEta_->Write();

  FinalFakeRateOneProngDMEta_->Write();
  FinalFakeRateOneProngOnePizDMEta_->Write();
  FinalFakeRateOneProngTwoPizDMEta_->Write();
  FinalFakeRateThreeProngDMEta_->Write();
  FinalFakeRateOneProngDMPt_->Write();
  FinalFakeRateOneProngOnePizDMPt_->Write();
  FinalFakeRateOneProngTwoPizDMPt_->Write();
  FinalFakeRateThreeProngDMPt_->Write();
  
  FinalFakeRateOneProngMedIsoEta_->Write();
  FinalFakeRateOneProngOnePizMedIsoEta_->Write();
  FinalFakeRateOneProngTwoPizMedIsoEta_->Write();
  FinalFakeRateThreeProngMedIsoEta_->Write();
  FinalFakeRateOneProngMedIsoPt_->Write();
  FinalFakeRateOneProngOnePizMedIsoPt_->Write();
  FinalFakeRateOneProngTwoPizMedIsoPt_->Write();
  FinalFakeRateThreeProngMedIsoPt_->Write();

  outFile->Write();
  outFile->Close();

cout << "end" << endl;

}//rootMacro_BBA_combine
