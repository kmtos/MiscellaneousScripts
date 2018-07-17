#include <string.h>
#include <math.h>
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
#include "tdrstyle.C"
#include "CMS_lumi.C"


void rootMacro_FakeRateErrorCheck()
{
std::cout << "check0" << std::endl;
  setTDRStyle(true);
std::cout << "check0.1" << std::endl;
  gStyle->SetPalette(1);

std::cout << "check1" << std::endl;
  TFile infile ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/FINAL_MiniAOD_SingleMu_MedIsoMu2_TauDM_ZSKIM_JAN9_RegionB_Mass81to101_dR0p0to0p5.root");
std::cout << "check2" << std::endl;
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/TAUFAKERATES_FINAL_MiniAOD_SingleMu_MedIsoMu2_TauDM_ZSKIM_JAN9_RegionB_Mass81to101_dR0p0to0p5.root", "RECREATE");

cout << "Files Created" << endl;

  TCanvas* EtavsPtTauLooseIsoCanvas = (TCanvas*)infile.Get("EtavsPtTauLooseIso");
  TCanvas* EtavsPtTauMedIsoCanvas = (TCanvas*)infile.Get("EtavsPtTauMedIso");
  TCanvas* EtavsPtTauTightIsoCanvas = (TCanvas*)infile.Get("EtavsPtTauTightIso");
  TCanvas* EtavsPtTauDMFindCanvas = (TCanvas*)infile.Get("EtavsPtTauDMFind");
  TCanvas* EtavsPtJetCanvas = (TCanvas*)infile.Get("EtavsPtJet");
  TCanvas* EtavsPtJetSoftMuonCanvas = (TCanvas*)infile.Get("EtavsPtJetSoftMuon");
  TCanvas* EtavsPtJetSoftMuon_noMuCanvas = (TCanvas*)infile.Get("EtavsPtJetSoftMuon_noMu");

  TCanvas* TauLooseIsoEtaCanvas = (TCanvas*)infile.Get("TauLooseIsoEta");
  TCanvas* TauMedIsoEtaCanvas = (TCanvas*)infile.Get("TauMedIsoEta");
  TCanvas* TauTightIsoEtaCanvas = (TCanvas*)infile.Get("TauTightIsoEta");
  TCanvas* TauDMFindEtaCanvas = (TCanvas*)infile.Get("TauDMFindEta");
  TCanvas* JetEtaCanvas = (TCanvas*)infile.Get("JetEta");
  TCanvas* JetEtaWithSoftMuonCanvas = (TCanvas*)infile.Get("JetEtaWithSoftMuon");
  TCanvas* JetEtaWithSoftMuon_noMuCanvas = (TCanvas*)infile.Get("JetEtaWithSoftMuon_noMu");

  TCanvas* TauLooseIsoPtCanvas = (TCanvas*)infile.Get("TauLooseIsoPt");
  TCanvas* TauMedIsoPtCanvas = (TCanvas*)infile.Get("TauMedIsoPt");
  TCanvas* TauTightIsoPtCanvas = (TCanvas*)infile.Get("TauTightIsoPt");
  TCanvas* TauDMFindPtCanvas = (TCanvas*)infile.Get("TauDMFindPt");
  TCanvas* JetPtCanvas = (TCanvas*)infile.Get("JetPt");
  TCanvas* JetPtWithSoftMuonCanvas = (TCanvas*)infile.Get("JetPtWithSoftMuon");
  TCanvas* JetPtWithSoftMuon_noMuCanvas = (TCanvas*)infile.Get("JetPtWithSoftMuon_noMu");

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
  TH2F* EtavsPtTauLooseIso_ = (TH2F*)EtavsPtTauLooseIsoCanvas->GetPrimitive("EtavsPtTauLooseIso");
  TH2F* EtavsPtTauMedIso_ = (TH2F*)EtavsPtTauMedIsoCanvas->GetPrimitive("EtavsPtTauMedIso");
  TH2F* EtavsPtTauTightIso_ = (TH2F*)EtavsPtTauTightIsoCanvas->GetPrimitive("EtavsPtTauTightIso");
  TH2F* EtavsPtTauDMFind_ = (TH2F*)EtavsPtTauDMFindCanvas->GetPrimitive("EtavsPtTauDMFind");
  TH2F* EtavsPtJet_ = (TH2F*)EtavsPtJetCanvas->GetPrimitive("EtavsPtJet");
  TH2F* EtavsPtJetSoftMuon_ = (TH2F*)EtavsPtJetSoftMuonCanvas->GetPrimitive("EtavsPtJetSoftMuon");
  TH2F* EtavsPtJetSoftMuon_noMu_ = (TH2F*)EtavsPtJetSoftMuon_noMuCanvas->GetPrimitive("EtavsPtJetSoftMuon_noMu");

  TH1F* TauLooseIsoEta_ = (TH1F*)TauLooseIsoEtaCanvas->GetPrimitive("TauLooseIsoEta");
  TH1F* TauMedIsoEta_ = (TH1F*)TauMedIsoEtaCanvas->GetPrimitive("TauMedIsoEta");
  TH1F* TauTightIsoEta_ = (TH1F*)TauTightIsoEtaCanvas->GetPrimitive("TauTightIsoEta");
  TH1F* TauDMFindEta_ = (TH1F*)TauDMFindEtaCanvas->GetPrimitive("TauDMFindEta");
  TH1F* JetEta_ = (TH1F*)JetEtaCanvas->GetPrimitive("JetEta");
  TH1F* JetEtaWithSoftMuon_ = (TH1F*)JetEtaWithSoftMuonCanvas->GetPrimitive("JetEtaWithSoftMuon");
  TH1F* JetEtaWithSoftMuon_noMu_ = (TH1F*)JetEtaWithSoftMuon_noMuCanvas->GetPrimitive("JetEtaWithSoftMuon_noMu");
  
  TH1F* TauLooseIsoPt_ = (TH1F*)TauLooseIsoPtCanvas->GetPrimitive("TauLooseIsoPt");
  TH1F* TauMedIsoPt_ = (TH1F*)TauMedIsoPtCanvas->GetPrimitive("TauMedIsoPt");
  TH1F* TauTightIsoPt_ = (TH1F*)TauTightIsoPtCanvas->GetPrimitive("TauTightIsoPt");
  TH1F* TauDMFindPt_ = (TH1F*)TauDMFindPtCanvas->GetPrimitive("TauDMFindPt");
  TH1F* JetPt_ = (TH1F*)JetPtCanvas->GetPrimitive("JetPt");
  TH1F* JetPtWithSoftMuon_ = (TH1F*)JetPtWithSoftMuonCanvas->GetPrimitive("JetPtWithSoftMuon");
  TH1F* JetPtWithSoftMuon_noMu_ = (TH1F*)JetPtWithSoftMuon_noMuCanvas->GetPrimitive("JetPtWithSoftMuon_noMu");

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
  // No Soft Mu Requirement
  TGraphAsymmErrors* FinalFakeRateLooseIsoPt_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateMedIsoPt_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateTightIsoPt_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateDMFindPt_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateDMtoMedIsoPt_ = new TGraphAsymmErrors(30);

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

  // No Soft Mu Requirement
  TGraphAsymmErrors* FinalFakeRateLooseIsoPtWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateMedIsoPtWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateTightIsoPtWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateDMFindPtWithSoftMuon_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalFakeRateLooseIsoEtaWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateMedIsoEtaWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateTightIsoEtaWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateDMFindEtaWithSoftMuon_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalFakeRateOneProngDMEtaWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateThreeProngDMEtaWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngDMPtWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngOnePizDMPtWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateThreeProngDMPtWithSoftMuon_ = new TGraphAsymmErrors(30);
  
  TGraphAsymmErrors* FinalFakeRateOneProngMedIsoEtaWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngMedIsoPtWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateThreeProngMedIsoPtWithSoftMuon_ = new TGraphAsymmErrors(30);

  // No Soft Mu Requirement
  TGraphAsymmErrors* FinalFakeRateLooseIsoPtWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateMedIsoPtWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateTightIsoPtWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateDMFindPtWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalFakeRateLooseIsoEtaWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateMedIsoEtaWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateTightIsoEtaWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateDMFindEtaWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);

  TGraphAsymmErrors* FinalFakeRateOneProngDMEtaWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateThreeProngDMEtaWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngDMPtWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngOnePizDMPtWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateThreeProngDMPtWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  
  TGraphAsymmErrors* FinalFakeRateOneProngMedIsoEtaWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngMedIsoPtWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);
  TGraphAsymmErrors* FinalFakeRateThreeProngMedIsoPtWithSoftMuon_noMu_ = new TGraphAsymmErrors(30);

  TCanvas *FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu = new TCanvas("FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMuCanvas","",600,600);
  TCanvas *FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu = new TCanvas("FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMuCanvas","",600,600);
  TCanvas *FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu = new TCanvas("FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMuCanvas","",600,600);
  TCanvas *FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu = new TCanvas("FinalFakeRateDMFindEtavsPtWithSoftMuon_noMuCanvas","",600,600);
 
  TH2F* FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu_ = (TH2F*)EtavsPtTauLooseIso_->Clone();
  TH2F* FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu_ = (TH2F*)EtavsPtTauMedIso_->Clone();
  TH2F* FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu_ = (TH2F*)EtavsPtTauTightIso_->Clone();
  TH2F* FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu_ = (TH2F*)EtavsPtTauDMFind_->Clone();
 
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu_->Divide(EtavsPtJetSoftMuon_noMu_);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu_->Divide(EtavsPtJetSoftMuon_noMu_);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu_->Divide(EtavsPtJetSoftMuon_noMu_);
  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu_->Divide(EtavsPtJetSoftMuon_noMu_);

  TCanvas *FinalFakeRateLooseIsoEtavsPtWithSoftMuon = new TCanvas("FinalFakeRateLooseIsoEtavsPtWithSoftMuonCanvas","",600,600);
  TCanvas *FinalFakeRateMedIsoEtavsPtWithSoftMuon = new TCanvas("FinalFakeRateMedIsoEtavsPtWithSoftMuonCanvas","",600,600);
  TCanvas *FinalFakeRateTightIsoEtavsPtWithSoftMuon = new TCanvas("FinalFakeRateTightIsoEtavsPtWithSoftMuonCanvas","",600,600);
  TCanvas *FinalFakeRateDMFindEtavsPtWithSoftMuon = new TCanvas("FinalFakeRateDMFindEtavsPtWithSoftMuonCanvas","",600,600);

  TH2F* FinalFakeRateLooseIsoEtavsPtWithSoftMuon_ = (TH2F*)EtavsPtTauLooseIso_->Clone();
  TH2F* FinalFakeRateMedIsoEtavsPtWithSoftMuon_ = (TH2F*)EtavsPtTauMedIso_->Clone();
  TH2F* FinalFakeRateTightIsoEtavsPtWithSoftMuon_ = (TH2F*)EtavsPtTauTightIso_->Clone();
  TH2F* FinalFakeRateDMFindEtavsPtWithSoftMuon_ = (TH2F*)EtavsPtTauDMFind_->Clone();

  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_->Divide(EtavsPtJetSoftMuon_);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_->Divide(EtavsPtJetSoftMuon_);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_->Divide(EtavsPtJetSoftMuon_);
  FinalFakeRateDMFindEtavsPtWithSoftMuon_->Divide(EtavsPtJetSoftMuon_);

  TCanvas *FinalFakeRateLooseIsoEtavsPt = new TCanvas("FinalFakeRateLooseIsoEtavsPtCanvas","",600,600);
  TCanvas *FinalFakeRateMedIsoEtavsPt = new TCanvas("FinalFakeRateMedIsoEtavsPtCanvas","",600,600);
  TCanvas *FinalFakeRateTightIsoEtavsPt = new TCanvas("FinalFakeRateTightIsoEtavsPtCanvas","",600,600);
  TCanvas *FinalFakeRateDMFindEtavsPt = new TCanvas("FinalFakeRateDMFindEtavsPtCanvas","",600,600);
  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPt = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtCanvas","",600,600);

  TH2F* FinalFakeRateLooseIsoEtavsPt_ = (TH2F*)EtavsPtTauLooseIso_->Clone();
  TH2F* FinalFakeRateMedIsoEtavsPt_ = (TH2F*)EtavsPtTauMedIso_->Clone();
  TH2F* FinalFakeRateTightIsoEtavsPt_ = (TH2F*)EtavsPtTauTightIso_->Clone();
  TH2F* FinalFakeRateDMFindEtavsPt_ = (TH2F*)EtavsPtTauDMFind_->Clone();
  TH2F* FinalFakeRateDMtoMedIsoOnlyEtavsPt_ = (TH2F*)EtavsPtTauMedIso_->Clone();

  FinalFakeRateLooseIsoEtavsPt_->Divide(EtavsPtJet_);
  FinalFakeRateMedIsoEtavsPt_->Divide(EtavsPtJet_);
  FinalFakeRateTightIsoEtavsPt_->Divide(EtavsPtJet_);
  FinalFakeRateDMFindEtavsPt_->Divide(EtavsPtJet_);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Divide(EtavsPtTauDMFind_);

std::cout << " error" << std::endl;
  for (int i=1; i < EtavsPtTauMedIso_->GetXaxis()->GetNbins(); i++)
  {
    for (int j=1; j < EtavsPtTauMedIso_->GetYaxis()->GetNbins(); j++)
    {
      double numError = EtavsPtTauMedIso_->GetBinError(i,j);
      double denError = EtavsPtTauDMFind_->GetBinError(i,j);
      double binError = FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetBinError(i,j);
      double numContent = EtavsPtTauMedIso_->GetBinContent(i,j);
      double denContent = EtavsPtTauDMFind_->GetBinContent(i,j);
      double binContent = FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetBinContent(i,j);
      double calError = pow(((numError / numContent) * (numError / numContent)) + ((denError / denContent) * (denError / denContent)), 0.5);
      std::cout << "\nnumError=" << numError << "\tnumContent=" << numContent << "\ndenError=" << denError << "\tdenContent=" << denContent << "\nbinError=" << binError  
   	        << "\tbinContent=" << binContent << "\t (binError / binContent)=" << binError / binContent << "\ncalError=" << calError << std::endl;
    }//for j
  }//fori

  FinalFakeRateLooseIsoEtavsPt->SetFillStyle(0);
  FinalFakeRateMedIsoEtavsPt->SetFillStyle(0);
  FinalFakeRateTightIsoEtavsPt->SetFillStyle(0);
  FinalFakeRateDMFindEtavsPt->SetFillStyle(0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt->SetFillStyle(0);

  FinalFakeRateLooseIsoEtavsPt->SetFillColor(0);
  FinalFakeRateMedIsoEtavsPt->SetFillColor(0);
  FinalFakeRateTightIsoEtavsPt->SetFillColor(0);
  FinalFakeRateDMFindEtavsPt->SetFillColor(0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt->SetFillColor(0);
 
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon->SetFillStyle(0);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon->SetFillStyle(0);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon->SetFillStyle(0);
  FinalFakeRateDMFindEtavsPtWithSoftMuon->SetFillStyle(0);

  FinalFakeRateLooseIsoEtavsPtWithSoftMuon->SetFillColor(0);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon->SetFillColor(0);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon->SetFillColor(0);
  FinalFakeRateDMFindEtavsPtWithSoftMuon->SetFillColor(0);

  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu->SetFillStyle(0);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu->SetFillStyle(0);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu->SetFillStyle(0);
  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu->SetFillStyle(0);

  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu->SetFillColor(0);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu->SetFillColor(0);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu->SetFillColor(0);
  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu->SetFillColor(0);

  FinalFakeRateLooseIsoEtavsPt_->GetYaxis()->SetLabelOffset(0.007);
  FinalFakeRateMedIsoEtavsPt_->GetYaxis()->SetLabelOffset(0.007);
  FinalFakeRateTightIsoEtavsPt_->GetYaxis()->SetLabelOffset(0.007);
  FinalFakeRateDMFindEtavsPt_->GetYaxis()->SetLabelOffset(0.007);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetYaxis()->SetLabelOffset(0.007);

  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_->GetYaxis()->SetLabelOffset(0.007);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_->GetYaxis()->SetLabelOffset(0.007);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_->GetYaxis()->SetLabelOffset(0.007);
  FinalFakeRateDMFindEtavsPtWithSoftMuon_->GetYaxis()->SetLabelOffset(0.007);
  
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu_->GetYaxis()->SetLabelOffset(0.007);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu_->GetYaxis()->SetLabelOffset(0.007);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu_->GetYaxis()->SetLabelOffset(0.007);
  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu_->GetYaxis()->SetLabelOffset(0.007);
 
std::cout << "Dividing" << std::endl;
  //Divide
  FinalFakeRateLooseIsoEta_->Divide(TauLooseIsoEta_, JetEta_ );
  FinalFakeRateMedIsoEta_->Divide(TauMedIsoEta_, JetEta_ );
  FinalFakeRateTightIsoEta_->Divide(TauTightIsoEta_, JetEta_ );
  FinalFakeRateDMFindEta_->Divide(TauDMFindEta_, JetEta_ );

std::cout << "check1" << std::endl;
  FinalFakeRateLooseIsoPt_->Divide(TauLooseIsoPt_, JetPt_ );
  FinalFakeRateMedIsoPt_->Divide(TauMedIsoPt_, JetPt_ );
  FinalFakeRateTightIsoPt_->Divide(TauTightIsoPt_, JetPt_ );
  FinalFakeRateDMFindPt_->Divide(TauDMFindPt_, JetPt_ );
  FinalFakeRateDMtoMedIsoPt_->Divide(TauMedIsoPt_, TauDMFindPt_);

std::cout << "check2" << std::endl;
  FinalFakeRateOneProngDMEta_->Divide(OneProngDMEta_, JetEta_);
  FinalFakeRateOneProngOnePizDMEta_->Divide(OneProngOnePizDMEta_, JetEta_);
  FinalFakeRateOneProngTwoPizDMEta_->Divide(OneProngTwoPizDMEta_, JetEta_);
  FinalFakeRateThreeProngDMEta_->Divide(ThreeProngDMEta_, JetEta_);
  FinalFakeRateOneProngDMPt_->Divide(OneProngDMPt_, JetPt_);
  FinalFakeRateOneProngOnePizDMPt_->Divide(OneProngOnePizDMPt_, JetPt_);
  FinalFakeRateOneProngTwoPizDMPt_->Divide(OneProngTwoPizDMPt_, JetPt_);
  FinalFakeRateThreeProngDMPt_->Divide(ThreeProngDMPt_, JetPt_);

std::cout << "check3" << std::endl;
  FinalFakeRateOneProngMedIsoEta_->Divide(OneProngMedIsoEta_, JetEta_);
  FinalFakeRateOneProngOnePizMedIsoEta_->Divide(OneProngOnePizMedIsoEta_, JetEta_);
  FinalFakeRateOneProngTwoPizMedIsoEta_->Divide(OneProngTwoPizMedIsoEta_, JetEta_);
  FinalFakeRateThreeProngMedIsoEta_->Divide(ThreeProngMedIsoEta_, JetEta_);
  FinalFakeRateOneProngMedIsoPt_->Divide(OneProngMedIsoPt_, JetPt_);
  FinalFakeRateOneProngOnePizMedIsoPt_->Divide(OneProngOnePizMedIsoPt_, JetPt_);
  FinalFakeRateOneProngTwoPizMedIsoPt_->Divide(OneProngTwoPizMedIsoPt_, JetPt_);
  FinalFakeRateThreeProngMedIsoPt_->Divide(ThreeProngMedIsoPt_, JetPt_);

std::cout << "check4" << std::endl;
  //Divide
  FinalFakeRateLooseIsoEtaWithSoftMuon_->Divide(TauLooseIsoEta_, JetEtaWithSoftMuon_ );
  FinalFakeRateMedIsoEtaWithSoftMuon_->Divide(TauMedIsoEta_, JetEtaWithSoftMuon_ );
  FinalFakeRateTightIsoEtaWithSoftMuon_->Divide(TauTightIsoEta_, JetEtaWithSoftMuon_ );
  FinalFakeRateDMFindEtaWithSoftMuon_->Divide(TauDMFindEta_, JetEtaWithSoftMuon_ );
std::cout << "check5" << std::endl;

  FinalFakeRateLooseIsoPtWithSoftMuon_->Divide(TauLooseIsoPt_, JetPtWithSoftMuon_ );
  FinalFakeRateMedIsoPtWithSoftMuon_->Divide(TauMedIsoPt_, JetPtWithSoftMuon_ );
  FinalFakeRateTightIsoPtWithSoftMuon_->Divide(TauTightIsoPt_, JetPtWithSoftMuon_ );
  FinalFakeRateDMFindPtWithSoftMuon_->Divide(TauDMFindPt_, JetPtWithSoftMuon_ );
std::cout << "check6" << std::endl;

  FinalFakeRateOneProngDMEtaWithSoftMuon_->Divide(OneProngDMEta_, JetEtaWithSoftMuon_ );
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_->Divide(OneProngOnePizDMEta_, JetEtaWithSoftMuon_ );
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_->Divide(OneProngTwoPizDMEta_, JetEtaWithSoftMuon_ );
  FinalFakeRateThreeProngDMEtaWithSoftMuon_->Divide(ThreeProngDMEta_, JetEtaWithSoftMuon_ );
  FinalFakeRateOneProngDMPtWithSoftMuon_->Divide(OneProngDMPt_, JetPtWithSoftMuon_ );
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_->Divide(OneProngOnePizDMPt_, JetPtWithSoftMuon_ );
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_->Divide(OneProngTwoPizDMPt_, JetPtWithSoftMuon_ );
  FinalFakeRateThreeProngDMPtWithSoftMuon_->Divide(ThreeProngDMPt_, JetPtWithSoftMuon_ );
std::cout << "check7" << std::endl;
  
  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_->Divide(OneProngMedIsoEta_, JetEtaWithSoftMuon_ );
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_->Divide(OneProngOnePizMedIsoEta_, JetEtaWithSoftMuon_ );
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_->Divide(OneProngTwoPizMedIsoEta_, JetEtaWithSoftMuon_ );
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_->Divide(ThreeProngMedIsoEta_, JetEtaWithSoftMuon_ );
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_->Divide(OneProngMedIsoPt_, JetPtWithSoftMuon_ );
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_->Divide(OneProngOnePizMedIsoPt_, JetPtWithSoftMuon_ );
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_->Divide(OneProngTwoPizMedIsoPt_, JetPtWithSoftMuon_ );
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_->Divide(ThreeProngMedIsoPt_, JetPtWithSoftMuon_ );
std::cout << "check8" << std::endl;

  //Divide
  FinalFakeRateLooseIsoEtaWithSoftMuon_noMu_->Divide(TauLooseIsoEta_, JetEtaWithSoftMuon_noMu_ );
  FinalFakeRateMedIsoEtaWithSoftMuon_noMu_->Divide(TauMedIsoEta_, JetEtaWithSoftMuon_noMu_ );
  FinalFakeRateTightIsoEtaWithSoftMuon_noMu_->Divide(TauTightIsoEta_, JetEtaWithSoftMuon_noMu_ );
  FinalFakeRateDMFindEtaWithSoftMuon_noMu_->Divide(TauDMFindEta_, JetEtaWithSoftMuon_noMu_ );
std::cout << "check9" << std::endl;

  FinalFakeRateLooseIsoPtWithSoftMuon_noMu_->Divide(TauLooseIsoPt_, JetPtWithSoftMuon_noMu_ );
std::cout << "check9.1" << std::endl;
  FinalFakeRateMedIsoPtWithSoftMuon_noMu_->Divide(TauMedIsoPt_, JetPtWithSoftMuon_noMu_ );
std::cout << "check9.2" << std::endl;
cout << "TauLooseIsoPt_->GetXaxis()->GetNbins()=" << TauLooseIsoPt_->GetXaxis()->GetNbins() << "\tJetPtWithSoftMuon_noMu_->GetXaxis()->GetNbins()=" << JetPtWithSoftMuon_noMu_->GetXaxis()->GetNbins() << endl;
cout << "TauLooseIsoPt_->GetXaxis()->GetXmax()=" << TauLooseIsoPt_->GetXaxis()->GetXmax() << "\tJetPtWithSoftMuon_noMu_->GetXaxis()->GetXmax()=" << JetPtWithSoftMuon_noMu_->GetXaxis()->GetXmax() << endl;
cout << "TauLooseIsoPt_->GetXaxis()->GetXmin()=" << TauLooseIsoPt_->GetXaxis()->GetXmin() << "\tJetPtWithSoftMuon_noMu_->GetXaxis()->GetXmin()=" << JetPtWithSoftMuon_noMu_->GetXaxis()->GetXmin() << endl;
  FinalFakeRateTightIsoPtWithSoftMuon_noMu_->Divide(TauTightIsoPt_, JetPtWithSoftMuon_noMu_ );
cout << "TauDMFindPt_->GetXaxis()->GetNbins()=" << TauDMFindPt_->GetXaxis()->GetNbins() << "\tJetPtWithSoftMuon_noMu_->GetXaxis()->GetNbins()=" << JetPtWithSoftMuon_noMu_->GetXaxis()->GetNbins() << endl;
cout << "TauDMFindPt_->GetXaxis()->GetXmax()=" << TauDMFindPt_->GetXaxis()->GetXmax() << "\tJetPtWithSoftMuon_noMu_->GetXaxis()->GetXmax()=" << JetPtWithSoftMuon_noMu_->GetXaxis()->GetXmax() << endl;
cout << "TauDMFindPt_->GetXaxis()->GetXmin()=" << TauDMFindPt_->GetXaxis()->GetXmin() << "\tJetPtWithSoftMuon_noMu_->GetXaxis()->GetXmin()=" << JetPtWithSoftMuon_noMu_->GetXaxis()->GetXmin() << endl;

cout << "check9.3" << std::endl;
  FinalFakeRateDMFindPtWithSoftMuon_noMu_->Divide(TauDMFindPt_, JetPtWithSoftMuon_noMu_ );
std::cout << "check10" << std::endl;

  FinalFakeRateOneProngDMEtaWithSoftMuon_noMu_->Divide(OneProngDMEta_, JetEtaWithSoftMuon_noMu_ );
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_noMu_->Divide(OneProngOnePizDMEta_, JetEtaWithSoftMuon_noMu_ );
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_noMu_->Divide(OneProngTwoPizDMEta_, JetEtaWithSoftMuon_noMu_ );
  FinalFakeRateThreeProngDMEtaWithSoftMuon_noMu_->Divide(ThreeProngDMEta_, JetEtaWithSoftMuon_noMu_ );
  FinalFakeRateOneProngDMPtWithSoftMuon_noMu_->Divide(OneProngDMPt_, JetPtWithSoftMuon_noMu_ );
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_noMu_->Divide(OneProngOnePizDMPt_, JetPtWithSoftMuon_noMu_ );
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_noMu_->Divide(OneProngTwoPizDMPt_, JetPtWithSoftMuon_noMu_ );
  FinalFakeRateThreeProngDMPtWithSoftMuon_noMu_->Divide(ThreeProngDMPt_, JetPtWithSoftMuon_noMu_ );
std::cout << "check11" << std::endl;

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_noMu_->Divide(OneProngMedIsoEta_, JetEtaWithSoftMuon_noMu_ );
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_noMu_->Divide(OneProngOnePizMedIsoEta_, JetEtaWithSoftMuon_noMu_ );
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_noMu_->Divide(OneProngTwoPizMedIsoEta_, JetEtaWithSoftMuon_noMu_ );
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_noMu_->Divide(ThreeProngMedIsoEta_, JetEtaWithSoftMuon_noMu_ );
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_noMu_->Divide(OneProngMedIsoPt_, JetPtWithSoftMuon_noMu_ );
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_noMu_->Divide(OneProngOnePizMedIsoPt_, JetPtWithSoftMuon_noMu_ );
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_noMu_->Divide(OneProngTwoPizMedIsoPt_, JetPtWithSoftMuon_noMu_ );
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_noMu_->Divide(ThreeProngMedIsoPt_, JetPtWithSoftMuon_noMu_ );

std::cout << "Formatting" << std::endl;
  //Formatting  2D HIstograms With SoftMuon Removed
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu_->SetName("FakeRateLooseIsoEtavsPtWithSoftMuon_noMu");
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu_->SetName("FakeRateMedIsoEtavsPtWithSoftMuon_noMu");
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu_->SetName("FakeRateTightIsoEtavsPtWithSoftMuon_noMu");
  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu_->SetName("FakeRateDMFindEtavsPtWithSoftMuon_noMu");

  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) with p_{T}(#mu) removed");
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) with p_{T}(#mu) removed");
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) with p_{T}(#mu) removed");
  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) with p_{T}(#mu) removed");

  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("#eta with #mu removed");
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("#eta with #mu removed");
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("#eta with #mu removed");
  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("#eta with #mu removed");

  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu_->GetYaxis()->SetTitleOffset(1.5);

  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu_->SetTitle("Fake Rate (# PFTau + Loose Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu_->SetTitle("Fake Rate (# PFTau +  Med Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu_->SetTitle("Fake Rate (# PFTau +  Tight Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu_->SetTitle("Fake Rate (# PFTau + DMFind / #  ak4PFJet with a Soft Muon)");

  //Formatting  2D HIstograms with Soft Muon
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_->SetName("FakeRateLooseIsoEtavsPtWithSoftMuon");
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_->SetName("FakeRateMedIsoEtavsPtWithSoftMuon");
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_->SetName("FakeRateTightIsoEtavsPtWithSoftMuon");
  FinalFakeRateDMFindEtavsPtWithSoftMuon_->SetName("FakeRateDMFindEtavsPtWithSoftMuon");
 
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) with #mu");
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) with #mu");
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) with #mu");
  FinalFakeRateDMFindEtavsPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) with #mu");
 
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_->GetYaxis()->SetTitle("#eta with #mu");
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_->GetYaxis()->SetTitle("#eta with #mu");
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_->GetYaxis()->SetTitle("#eta with #mu");
  FinalFakeRateDMFindEtavsPtWithSoftMuon_->GetYaxis()->SetTitle("#eta with #mu");
 
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMFindEtavsPtWithSoftMuon_->GetYaxis()->SetTitleOffset(1.5);
 
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_->SetTitle("Fake Rate (# PFTau + Loose Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_->SetTitle("Fake Rate (# PFTau +  Med Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_->SetTitle("Fake Rate (# PFTau +  Tight Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateDMFindEtavsPtWithSoftMuon_->SetTitle("Fake Rate (# PFTau + DMFind / #  ak4PFJet with a Soft Muon)");


  //Formatting  2D HIstograms with Soft Muon
  FinalFakeRateLooseIsoEtavsPt_->SetName("FakeRateLooseIsoEtavsPt");
  FinalFakeRateMedIsoEtavsPt_->SetName("FakeRateMedIsoEtavsPt");
  FinalFakeRateTightIsoEtavsPt_->SetName("FakeRateTightIsoEtavsPt");
  FinalFakeRateDMFindEtavsPt_->SetName("FakeRateDMFindEtavsPt");
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->SetName("FakeRateDMFindEtavsPt");

  FinalFakeRateLooseIsoEtavsPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateMedIsoEtavsPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateTightIsoEtavsPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateDMFindEtavsPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetXaxis()->SetTitle("p_{T}(#tau)");

  FinalFakeRateLooseIsoEtavsPt_->GetYaxis()->SetTitle("#eta");
  FinalFakeRateMedIsoEtavsPt_->GetYaxis()->SetTitle("#eta");
  FinalFakeRateTightIsoEtavsPt_->GetYaxis()->SetTitle("#eta");
  FinalFakeRateDMFindEtavsPt_->GetYaxis()->SetTitle("#eta");
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetYaxis()->SetTitle("#eta");

  FinalFakeRateLooseIsoEtavsPt_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateMedIsoEtavsPt_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateTightIsoEtavsPt_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMFindEtavsPt_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetYaxis()->SetTitleOffset(1.5);

  FinalFakeRateLooseIsoEtavsPt_->SetTitle("Fake Rate (# PFTau + Loose Iso + DMFind / #  ak4PFJet)");
  FinalFakeRateMedIsoEtavsPt_->SetTitle("Fake Rate (# PFTau +  Med Iso + DMFind / #  ak4PFJet)");
  FinalFakeRateTightIsoEtavsPt_->SetTitle("Fake Rate (# PFTau +  Tight Iso + DMFind / #  ak4PFJet)");
  FinalFakeRateDMFindEtavsPt_->SetTitle("Fake Rate (# PFTau + DMFind / #  ak4PFJet)");
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->SetTitle("Fake Rate (# PFTau + MedIso + DMFind / # PFTau + DMFind)");


  //Formatting Pt
  FinalFakeRateLooseIsoPt_->SetName("FakeRateLooseIsoPt");
  FinalFakeRateMedIsoPt_->SetName("FakeRateMedIsoPt");
  FinalFakeRateTightIsoPt_->SetName("FakeRateTightIsoPt");
  FinalFakeRateDMFindPt_->SetName("FakeRateDMFindPt");
  FinalFakeRateDMtoMedIsoPt_->SetName("FakeRateDMtoMedIsoPt");

  FinalFakeRateLooseIsoPt_->SetMarkerSize(.07);
  FinalFakeRateMedIsoPt_->SetMarkerSize(.07);
  FinalFakeRateTightIsoPt_->SetMarkerSize(.07);
  FinalFakeRateDMFindPt_->SetMarkerSize(.07);
  FinalFakeRateDMtoMedIsoPt_->SetMarkerSize(.07);

  FinalFakeRateLooseIsoPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateMedIsoPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateTightIsoPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateDMFindPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateDMtoMedIsoPt_->GetXaxis()->SetTitle("p_{T}(#tau)");

  FinalFakeRateLooseIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Loose Iso + DMFind / #  ak4PFJet)");
  FinalFakeRateMedIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + DMFind / #  ak4PFJet)");
  FinalFakeRateTightIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Tight Iso + DMFind / #  ak4PFJet)");
  FinalFakeRateDMFindPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + DMFind / #  ak4PFJet)");
  FinalFakeRateDMtoMedIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + DMtoMedIso / #  ak4PFJet)");

  FinalFakeRateLooseIsoPt_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateMedIsoPt_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateTightIsoPt_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMFindPt_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMtoMedIsoPt_->GetYaxis()->SetTitleOffset(1.5);

  FinalFakeRateLooseIsoPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateMedIsoPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateTightIsoPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateDMFindPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateDMtoMedIsoPt_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalFakeRateLooseIsoPt_->SetLineWidth(3);
  FinalFakeRateMedIsoPt_->SetLineWidth(3);
  FinalFakeRateTightIsoPt_->SetLineWidth(3);
  FinalFakeRateDMFindPt_->SetLineWidth(3);
  FinalFakeRateDMtoMedIsoPt_->SetLineWidth(3);

  FinalFakeRateLooseIsoPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateMedIsoPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateTightIsoPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateDMFindPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateDMtoMedIsoPt_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");

  FinalFakeRateLooseIsoPtWithSoftMuon_->SetName("FakeRateLooseIsoPtWithSoftMuon");
  FinalFakeRateMedIsoPtWithSoftMuon_->SetName("FakeRateMedIsoPtWithSoftMuon");
  FinalFakeRateTightIsoPtWithSoftMuon_->SetName("FakeRateTightIsoPtWithSoftMuon");
  FinalFakeRateDMFindPtWithSoftMuon_->SetName("FakeRateDMFindPtWithSoftMuon");

  FinalFakeRateLooseIsoPtWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateMedIsoPtWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateTightIsoPtWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateDMFindPtWithSoftMuon_->SetMarkerSize(.07);

  FinalFakeRateLooseIsoPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) with #mu");
  FinalFakeRateMedIsoPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) with #mu");
  FinalFakeRateTightIsoPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) with #mu");
  FinalFakeRateDMFindPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) with #mu");

  FinalFakeRateLooseIsoPtWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Loose Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateMedIsoPtWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateTightIsoPtWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Tight Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateDMFindPtWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + DMFind / #  ak4PFJet with a Soft Muon)");

  FinalFakeRateLooseIsoPtWithSoftMuon_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateMedIsoPtWithSoftMuon_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateTightIsoPtWithSoftMuon_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMFindPtWithSoftMuon_->GetYaxis()->SetTitleOffset(1.5);

  FinalFakeRateLooseIsoPtWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateMedIsoPtWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateTightIsoPtWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateDMFindPtWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalFakeRateLooseIsoPtWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateMedIsoPtWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateTightIsoPtWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateDMFindPtWithSoftMuon_->SetLineWidth(3);

  FinalFakeRateLooseIsoPtWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateMedIsoPtWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateTightIsoPtWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateDMFindPtWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");

  FinalFakeRateLooseIsoPtWithSoftMuon_noMu_->SetName("FakeRateLooseIsoPtWithSoftMuon_noMu");
  FinalFakeRateMedIsoPtWithSoftMuon_noMu_->SetName("FakeRateMedIsoPtWithSoftMuon_noMu");
  FinalFakeRateTightIsoPtWithSoftMuon_noMu_->SetName("FakeRateTightIsoPtWithSoftMuon_noMu");
  FinalFakeRateDMFindPtWithSoftMuon_noMu_->SetName("FakeRateDMFindPtWithSoftMuon_noMu");

  FinalFakeRateLooseIsoPtWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateMedIsoPtWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateTightIsoPtWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateDMFindPtWithSoftMuon_noMu_->SetMarkerSize(.07);

  FinalFakeRateLooseIsoPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) with #mu removed");
  FinalFakeRateMedIsoPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) with #mu removed");
  FinalFakeRateTightIsoPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) with #mu removed");
  FinalFakeRateDMFindPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) with #mu removed");

  FinalFakeRateLooseIsoPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Loose Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateMedIsoPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateTightIsoPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Tight Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateDMFindPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + DMFind / #  ak4PFJet with a Soft Muon)");

  FinalFakeRateLooseIsoPtWithSoftMuon_noMu_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateMedIsoPtWithSoftMuon_noMu_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateTightIsoPtWithSoftMuon_noMu_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMFindPtWithSoftMuon_noMu_->GetYaxis()->SetTitleOffset(1.5);

  FinalFakeRateLooseIsoPtWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateMedIsoPtWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateTightIsoPtWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateDMFindPtWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalFakeRateLooseIsoPtWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateMedIsoPtWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateTightIsoPtWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateDMFindPtWithSoftMuon_noMu_->SetLineWidth(3);

  FinalFakeRateLooseIsoPtWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateMedIsoPtWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateTightIsoPtWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateDMFindPtWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");


  //Formatting Eta
  FinalFakeRateLooseIsoEta_->SetName("FakeRateLooseIsoEta");
  FinalFakeRateMedIsoEta_->SetName("FakeRateMedIsoEta");
  FinalFakeRateTightIsoEta_->SetName("FakeRateTightIsoEta");
  FinalFakeRateDMFindEta_->SetName("FakeRateDMFindEta");

  FinalFakeRateLooseIsoEta_->SetMarkerSize(.07);
  FinalFakeRateMedIsoEta_->SetMarkerSize(.07);
  FinalFakeRateTightIsoEta_->SetMarkerSize(.07);
  FinalFakeRateDMFindEta_->SetMarkerSize(.07);
  
  FinalFakeRateLooseIsoEta_->GetXaxis()->SetTitle("#eta");
  FinalFakeRateMedIsoEta_->GetXaxis()->SetTitle("#eta");
  FinalFakeRateTightIsoEta_->GetXaxis()->SetTitle("#eta");
  FinalFakeRateDMFindEta_->GetXaxis()->SetTitle("#eta");
  
  FinalFakeRateLooseIsoEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Loose Iso + DMFind / #  ak4PFJet with SoftMu)");
  FinalFakeRateMedIsoEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + DMFind / #  ak4PFJet with SoftMu)");
  FinalFakeRateTightIsoEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Tight Iso + DMFind / #  ak4PFJet with SoftMu)");
  FinalFakeRateDMFindEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + DMFind / #  ak4PFJet with SoftMu)");
  
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

  FinalFakeRateLooseIsoEtaWithSoftMuon_->SetName("FakeRateLooseIsoEtaWithSoftMuon");
  FinalFakeRateMedIsoEtaWithSoftMuon_->SetName("FakeRateMedIsoEtaWithSoftMuon");
  FinalFakeRateTightIsoEtaWithSoftMuon_->SetName("FakeRateTightIsoEtaWithSoftMuon");
  FinalFakeRateDMFindEtaWithSoftMuon_->SetName("FakeRateDMFindEtaWithSoftMuon");

  FinalFakeRateLooseIsoEtaWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateMedIsoEtaWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateTightIsoEtaWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateDMFindEtaWithSoftMuon_->SetMarkerSize(.07);

  FinalFakeRateLooseIsoEtaWithSoftMuon_->GetXaxis()->SetTitle("#eta with #mu");
  FinalFakeRateMedIsoEtaWithSoftMuon_->GetXaxis()->SetTitle("#eta with #mu");
  FinalFakeRateTightIsoEtaWithSoftMuon_->GetXaxis()->SetTitle("#eta with #mu");
  FinalFakeRateDMFindEtaWithSoftMuon_->GetXaxis()->SetTitle("#eta with #mu");

  FinalFakeRateLooseIsoEtaWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Loose Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateMedIsoEtaWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateTightIsoEtaWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Tight Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateDMFindEtaWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + DMFind / #  ak4PFJet with a Soft Muon)");

  FinalFakeRateLooseIsoEtaWithSoftMuon_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateMedIsoEtaWithSoftMuon_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateTightIsoEtaWithSoftMuon_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMFindEtaWithSoftMuon_->GetYaxis()->SetTitleOffset(1.5);

  FinalFakeRateLooseIsoEtaWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateMedIsoEtaWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateTightIsoEtaWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateDMFindEtaWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalFakeRateLooseIsoEtaWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateMedIsoEtaWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateTightIsoEtaWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateDMFindEtaWithSoftMuon_->SetLineWidth(3);

  FinalFakeRateLooseIsoEtaWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateMedIsoEtaWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateTightIsoEtaWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateDMFindEtaWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");

  FinalFakeRateLooseIsoEtaWithSoftMuon_noMu_->SetName("FakeRateLooseIsoEtaWithSoftMuon_noMu");
  FinalFakeRateMedIsoEtaWithSoftMuon_noMu_->SetName("FakeRateMedIsoEtaWithSoftMuon_noMu");
  FinalFakeRateTightIsoEtaWithSoftMuon_noMu_->SetName("FakeRateTightIsoEtaWithSoftMuon_noMu");
  FinalFakeRateDMFindEtaWithSoftMuon_noMu_->SetName("FakeRateDMFindEtaWithSoftMuon_noMu");

  FinalFakeRateLooseIsoEtaWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateMedIsoEtaWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateTightIsoEtaWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateDMFindEtaWithSoftMuon_noMu_->SetMarkerSize(.07);

  FinalFakeRateLooseIsoEtaWithSoftMuon_noMu_->GetXaxis()->SetTitle("#eta with #mu removed");
  FinalFakeRateMedIsoEtaWithSoftMuon_noMu_->GetXaxis()->SetTitle("#eta with #mu removed");
  FinalFakeRateTightIsoEtaWithSoftMuon_noMu_->GetXaxis()->SetTitle("#eta with #mu removed");
  FinalFakeRateDMFindEtaWithSoftMuon_noMu_->GetXaxis()->SetTitle("#eta with #mu removed");

  FinalFakeRateLooseIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Loose Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateMedIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateTightIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Tight Iso + DMFind / #  ak4PFJet with a Soft Muon)");
  FinalFakeRateDMFindEtaWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + DMFind / #  ak4PFJet with a Soft Muon)");

  FinalFakeRateLooseIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateMedIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateTightIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMFindEtaWithSoftMuon_noMu_->GetYaxis()->SetTitleOffset(1.5);

  FinalFakeRateLooseIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateMedIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateTightIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateDMFindEtaWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalFakeRateLooseIsoEtaWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateMedIsoEtaWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateTightIsoEtaWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateDMFindEtaWithSoftMuon_noMu_->SetLineWidth(3);

  FinalFakeRateLooseIsoEtaWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateMedIsoEtaWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateTightIsoEtaWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateDMFindEtaWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  
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

  FinalFakeRateOneProngDMEtaWithSoftMuon_->SetName("FakeRateOneProngDMFindEtaWithSoftMuon");
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_->SetName("FakeRateOneProngOnePizDMFindEtaWithSoftMuon");
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_->SetName("FakeRateOneProngTwoPizDMFindEtaWithSoftMuon");
  FinalFakeRateThreeProngDMEtaWithSoftMuon_->SetName("FakeRateThreeProngDMFindEtaWithSoftMuon");
  FinalFakeRateOneProngDMPtWithSoftMuon_->SetName("FakeRateOneProngDMFindPtWithSoftMuon");
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_->SetName("FakeRateOneProngOnePizDMFindPtWithSoftMuon");
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_->SetName("FakeRateOneProngTwoPizDMFindPtWithSoftMuon");
  FinalFakeRateThreeProngDMPtWithSoftMuon_->SetName("FakeRateThreeProngDMFindPtWithSoftMuon");

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_->SetName("FakeRateOneProngMedIsoEtaWithSoftMuon");
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_->SetName("FakeRateOneProngOnePizMedIsoEtaWithSoftMuon");
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_->SetName("FakeRateOneProngTwoPizMedIsoEtaWithSoftMuon");
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_->SetName("FakeRateThreeProngMedIsoEtaWithSoftMuon");
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_->SetName("FakeRateOneProngMedIsoPtWithSoftMuon");
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_->SetName("FakeRateOneProngOnePizMedIsoPtWithSoftMuon");
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_->SetName("FakeRateOneProngTwoPizMedIsoPtWithSoftMuon");
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_->SetName("FakeRateThreeProngMedIsoPtWithSoftMuon");

  FinalFakeRateOneProngDMEtaWithSoftMuon_noMu_->SetName("FakeRateOneProngDMFindEtaWithSoftMuon_noMu");
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_noMu_->SetName("FakeRateOneProngOnePizDMFindEtaWithSoftMuon_noMu");
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_noMu_->SetName("FakeRateOneProngTwoPizDMFindEtaWithSoftMuon_noMu");
  FinalFakeRateThreeProngDMEtaWithSoftMuon_noMu_->SetName("FakeRateThreeProngDMFindEtaWithSoftMuon_noMu");
  FinalFakeRateOneProngDMPtWithSoftMuon_noMu_->SetName("FakeRateOneProngDMFindPtWithSoftMuon_noMu");
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_noMu_->SetName("FakeRateOneProngOnePizDMFindPtWithSoftMuon_noMu");
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_noMu_->SetName("FakeRateOneProngTwoPizDMFindPtWithSoftMuon_noMu");
  FinalFakeRateThreeProngDMPtWithSoftMuon_noMu_->SetName("FakeRateThreeProngDMFindPtWithSoftMuon_noMu");

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_noMu_->SetName("FakeRateOneProngMedIsoEtaWithSoftMuon_noMu");
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_noMu_->SetName("FakeRateOneProngOnePizMedIsoEtaWithSoftMuon_noMu");
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_noMu_->SetName("FakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_noMu");
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_noMu_->SetName("FakeRateThreeProngMedIsoEtaWithSoftMuon_noMu");
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_noMu_->SetName("FakeRateOneProngMedIsoPtWithSoftMuon_noMu");
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_noMu_->SetName("FakeRateOneProngOnePizMedIsoPtWithSoftMuon_noMu");
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_noMu_->SetName("FakeRateOneProngTwoPizMedIsoPtWithSoftMuon_noMu");
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_noMu_->SetName("FakeRateThreeProngMedIsoPtWithSoftMuon_noMu");

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

  FinalFakeRateOneProngDMEtaWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateThreeProngDMEtaWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateOneProngDMPtWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateThreeProngDMPtWithSoftMuon_->SetMarkerSize(.07);

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_->SetMarkerSize(.07);
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_->SetMarkerSize(.07);

  FinalFakeRateOneProngDMEtaWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateThreeProngDMEtaWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateOneProngDMPtWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateThreeProngDMPtWithSoftMuon_noMu_->SetMarkerSize(.07);

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_noMu_->SetMarkerSize(.07);
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_noMu_->SetMarkerSize(.07);

  FinalFakeRateOneProngDMEta_->GetXaxis()->SetTitle("#eta");
  FinalFakeRateOneProngOnePizDMEta_->GetXaxis()->SetTitle("#eta");
  FinalFakeRateOneProngTwoPizDMEta_->GetXaxis()->SetTitle("#eta");
  FinalFakeRateThreeProngDMEta_->GetXaxis()->SetTitle("#eta");
  FinalFakeRateOneProngDMPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateOneProngOnePizDMPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateOneProngTwoPizDMPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateThreeProngDMPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  
  FinalFakeRateOneProngMedIsoEta_->GetXaxis()->SetTitle("#eta");
  FinalFakeRateOneProngOnePizMedIsoEta_->GetXaxis()->SetTitle("#eta");
  FinalFakeRateOneProngTwoPizMedIsoEta_->GetXaxis()->SetTitle("#eta");
  FinalFakeRateThreeProngMedIsoEta_->GetXaxis()->SetTitle("#eta");
  FinalFakeRateOneProngMedIsoPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateOneProngOnePizMedIsoPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateOneProngTwoPizMedIsoPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateThreeProngMedIsoPt_->GetXaxis()->SetTitle("p_{T}(#tau)");

  FinalFakeRateOneProngDMEtaWithSoftMuon_->GetXaxis()->SetTitle("#eta of events with a Soft Muon");
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_->GetXaxis()->SetTitle("#eta of events with a Soft Muon");
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_->GetXaxis()->SetTitle("#eta of events with a Soft Muon");
  FinalFakeRateThreeProngDMEtaWithSoftMuon_->GetXaxis()->SetTitle("#eta of events with a Soft Muon");
  FinalFakeRateOneProngDMPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon");
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon");
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon");
  FinalFakeRateThreeProngDMPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon");

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_->GetXaxis()->SetTitle("#eta of events with a Soft Muon");
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_->GetXaxis()->SetTitle("#eta of events with a Soft Muon");
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_->GetXaxis()->SetTitle("#eta of events with a Soft Muon");
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_->GetXaxis()->SetTitle("#eta of events with a Soft Muon");
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon");
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon");
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon");
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon");

  FinalFakeRateOneProngDMEtaWithSoftMuon_noMu_->GetXaxis()->SetTitle("#eta of events with a Soft Muon Removed");
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_noMu_->GetXaxis()->SetTitle("#eta of events with a Soft Muon Removed");
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_noMu_->GetXaxis()->SetTitle("#eta of events with a Soft Muon Removed");
  FinalFakeRateThreeProngDMEtaWithSoftMuon_noMu_->GetXaxis()->SetTitle("#eta of events with a Soft Muon Removed");
  FinalFakeRateOneProngDMPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon Removed");
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon Removed");
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon Removed");
  FinalFakeRateThreeProngDMPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon Removed");

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_noMu_->GetXaxis()->SetTitle("#eta of events with a Soft Muon Removed");
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_noMu_->GetXaxis()->SetTitle("#eta of events with a Soft Muon Removed");
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_noMu_->GetXaxis()->SetTitle("#eta of events with a Soft Muon Removed");
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_noMu_->GetXaxis()->SetTitle("#eta of events with a Soft Muon Removed");
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon Removed");
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon Removed");
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon Removed");
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_noMu_->GetXaxis()->SetTitle("p_{T}(#tau) of events with a Soft Muon Removed");

  FinalFakeRateOneProngDMEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-} / #  ak4PFJet)");
  FinalFakeRateOneProngOnePizDMEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},1#pi^{0} / #  ak4PFJet)");
  FinalFakeRateOneProngTwoPizDMEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},2#pi^{0} / #  ak4PFJet)");
  FinalFakeRateThreeProngDMEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 3#pi^{+-} / #  ak4PFJet)");
  FinalFakeRateOneProngDMPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-} / #  ak4PFJet)");
  FinalFakeRateOneProngOnePizDMPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},1#pi^{0} / #  ak4PFJet)");
  FinalFakeRateOneProngTwoPizDMPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},2#pi^{0} / #  ak4PFJet)");
  FinalFakeRateThreeProngDMPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 3#pi^{+-} / #  ak4PFJet)");

  FinalFakeRateOneProngMedIsoEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-} / #  ak4PFJet)");
  FinalFakeRateOneProngOnePizMedIsoEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},1#pi^{0} / #  ak4PFJet)");
  FinalFakeRateOneProngTwoPizMedIsoEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},2#pi^{0} / #  ak4PFJet)");
  FinalFakeRateThreeProngMedIsoEta_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 3#pi^{+-} / #  ak4PFJet)");
  FinalFakeRateOneProngMedIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-} / #  ak4PFJet)");
  FinalFakeRateOneProngOnePizMedIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},1#pi^{0} / #  ak4PFJet)");
  FinalFakeRateOneProngTwoPizMedIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},2#pi^{0} / #  ak4PFJet)");
  FinalFakeRateThreeProngMedIsoPt_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 3#pi^{+-} / #  ak4PFJet)");

  FinalFakeRateOneProngDMEtaWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},1#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},2#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateThreeProngDMEtaWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 3#pi^{+-} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngDMPtWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},1#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},2#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateThreeProngDMPtWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 3#pi^{+-} / #  ak4PFJet with SoftMu)");

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},1#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},2#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 3#pi^{+-} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},1#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},2#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 3#pi^{+-} / #  ak4PFJet with SoftMu)");

  FinalFakeRateOneProngDMEtaWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},1#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},2#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateThreeProngDMEtaWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 3#pi^{+-} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngDMPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},1#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 1#pi^{+-},2#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateThreeProngDMPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + 3#pi^{+-} / #  ak4PFJet with SoftMu)");

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},1#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},2#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 3#pi^{+-} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},1#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 1#pi^{+-},2#pi^{0} / #  ak4PFJet with SoftMu)");
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_noMu_->GetYaxis()->SetTitle("Fake Rate (# PFTau + Med Iso + 3#pi^{+-} / #  ak4PFJet with SoftMu)");

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

  FinalFakeRateOneProngDMEtaWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateThreeProngDMEtaWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngDMPtWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateThreeProngDMPtWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_->GetXaxis()->SetTitleOffset(1.5);

  FinalFakeRateOneProngDMEtaWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateThreeProngDMEtaWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngDMPtWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateThreeProngDMPtWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_noMu_->GetXaxis()->SetTitleOffset(1.5);

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

  FinalFakeRateOneProngDMEtaWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateThreeProngDMEtaWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngDMPtWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateThreeProngDMPtWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalFakeRateOneProngDMEtaWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateThreeProngDMEtaWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngDMPtWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateThreeProngDMPtWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_noMu_->GetYaxis()->SetRangeUser(0.0, 1.0);

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

  FinalFakeRateOneProngDMEtaWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateThreeProngDMEtaWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateOneProngDMPtWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateThreeProngDMPtWithSoftMuon_->SetLineWidth(3);

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_->SetLineWidth(3);
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_->SetLineWidth(3);

  FinalFakeRateOneProngDMEtaWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateThreeProngDMEtaWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateOneProngDMPtWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateThreeProngDMPtWithSoftMuon_noMu_->SetLineWidth(3);

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_noMu_->SetLineWidth(3);
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_noMu_->SetLineWidth(3);

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

  FinalFakeRateOneProngDMEtaWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateThreeProngDMEtaWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngDMPtWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateThreeProngDMPtWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");

  FinalFakeRateOneProngDMEtaWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateThreeProngDMEtaWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngDMPtWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateThreeProngDMPtWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");

  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_noMu_->SetTitle("Fake Rate: 81 < M(#mu_{1}#mu_{2}) < 101");


cout << "Attributes set." << endl;  

  //Writing
  outFile->cd();

  CMS_lumi(  EtavsPtTauLooseIsoCanvas, 4, 11);
  EtavsPtTauLooseIsoCanvas->Write();
  CMS_lumi(  EtavsPtTauMedIsoCanvas, 4, 11);
  EtavsPtTauMedIsoCanvas->Write();
  CMS_lumi(  EtavsPtTauTightIsoCanvas, 4, 11);
  EtavsPtTauTightIsoCanvas->Write();
  CMS_lumi(  EtavsPtTauDMFindCanvas, 4, 11);
  EtavsPtTauDMFindCanvas->Write();
  CMS_lumi(  EtavsPtJetCanvas, 4, 11);
  EtavsPtJetCanvas->Write();
  CMS_lumi(  EtavsPtJetSoftMuonCanvas, 4, 11);
  EtavsPtJetSoftMuonCanvas->Write();
  CMS_lumi(  EtavsPtJetSoftMuon_noMuCanvas, 4, 11);
  EtavsPtJetSoftMuon_noMuCanvas->Write();

  CMS_lumi(  TauLooseIsoEtaCanvas, 4, 11);
  TauLooseIsoEtaCanvas->Write();
  CMS_lumi(  TauMedIsoEtaCanvas, 4, 11);
  TauMedIsoEtaCanvas->Write();
  CMS_lumi(  TauTightIsoEtaCanvas, 4, 11);
  TauTightIsoEtaCanvas->Write();
  CMS_lumi(  TauDMFindEtaCanvas, 4, 11);
  TauDMFindEtaCanvas->Write();
  CMS_lumi(  JetEtaCanvas, 4, 11);
  JetEtaCanvas->Write();
  CMS_lumi(  JetEtaWithSoftMuonCanvas, 4, 11);
  JetEtaWithSoftMuonCanvas->Write();
  CMS_lumi(  JetEtaWithSoftMuon_noMuCanvas, 4, 11);
  JetEtaWithSoftMuon_noMuCanvas->Write();

  CMS_lumi(  TauLooseIsoPtCanvas, 4, 11);
  TauLooseIsoPtCanvas->Write();
  CMS_lumi(  TauMedIsoPtCanvas, 4, 11);
  TauMedIsoPtCanvas->Write();
  CMS_lumi(  TauTightIsoPtCanvas, 4, 11);
  TauTightIsoPtCanvas->Write();
  CMS_lumi(  TauDMFindPtCanvas, 4, 11);
  TauDMFindPtCanvas->Write();
  CMS_lumi(  JetPtCanvas, 4, 11);
  JetPtCanvas->Write();
  CMS_lumi(  JetPtWithSoftMuonCanvas, 4, 11);
  JetPtWithSoftMuonCanvas->Write();
  CMS_lumi(  JetPtWithSoftMuon_noMuCanvas, 4, 11);
  JetPtWithSoftMuon_noMuCanvas->Write();

  CMS_lumi(  OneProngDMEtaCanvas, 4, 11);
  OneProngDMEtaCanvas->Write();
  CMS_lumi(  OneProngOnePizDMEtaCanvas, 4, 11);
  OneProngOnePizDMEtaCanvas->Write();
  CMS_lumi(  OneProngTwoPizDMEtaCanvas, 4, 11);
  OneProngTwoPizDMEtaCanvas->Write();
  CMS_lumi(  ThreeProngDMEtaCanvas, 4, 11);
  ThreeProngDMEtaCanvas->Write();
  CMS_lumi(  OneProngDMPtCanvas, 4, 11);
  OneProngDMPtCanvas->Write();
  CMS_lumi(  OneProngOnePizDMPtCanvas, 4, 11);
  OneProngOnePizDMPtCanvas->Write();
  CMS_lumi(  OneProngTwoPizDMPtCanvas, 4, 11);
  OneProngTwoPizDMPtCanvas->Write();
  CMS_lumi(  ThreeProngDMPtCanvas, 4, 11);
  ThreeProngDMPtCanvas->Write();
  
  CMS_lumi(  OneProngMedIsoEtaCanvas, 4, 11);
  OneProngMedIsoEtaCanvas->Write();
  CMS_lumi(  OneProngOnePizMedIsoEtaCanvas, 4, 11);
  OneProngOnePizMedIsoEtaCanvas->Write();
  CMS_lumi(  OneProngTwoPizMedIsoEtaCanvas, 4, 11);
  OneProngTwoPizMedIsoEtaCanvas->Write();
  CMS_lumi(  ThreeProngMedIsoEtaCanvas, 4, 11);
  ThreeProngMedIsoEtaCanvas->Write();
  CMS_lumi(  OneProngMedIsoPtCanvas, 4, 11);
  OneProngMedIsoPtCanvas->Write();
  CMS_lumi(  OneProngOnePizMedIsoPtCanvas, 4, 11);
  OneProngOnePizMedIsoPtCanvas->Write();
  CMS_lumi(  OneProngTwoPizMedIsoPtCanvas, 4, 11);
  OneProngTwoPizMedIsoPtCanvas->Write();
  CMS_lumi(  ThreeProngMedIsoPtCanvas, 4, 11);
  ThreeProngMedIsoPtCanvas->Write();


  FinalFakeRateLooseIsoEtavsPt->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateLooseIsoEtavsPt_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateLooseIsoEtavsPt_->SetStats(false);
  FinalFakeRateLooseIsoEtavsPt_->SetMarkerSize(.56);
  FinalFakeRateLooseIsoEtavsPt_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette = (TPaletteAxis*)FinalFakeRateLooseIsoEtavsPt_->GetListOfFunctions()->FindObject("palette");
  palette->SetX1NDC(0.88);
  palette->SetX2NDC(0.92);
  palette->SetY1NDC(0.1);
  palette->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateLooseIsoEtavsPt, 4, 11);
  FinalFakeRateLooseIsoEtavsPt->Write();

  FinalFakeRateMedIsoEtavsPt->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateMedIsoEtavsPt_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateMedIsoEtavsPt_->SetStats(false);
  FinalFakeRateMedIsoEtavsPt_->SetMarkerSize(.56);
  FinalFakeRateMedIsoEtavsPt_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette1 = (TPaletteAxis*)FinalFakeRateMedIsoEtavsPt_->GetListOfFunctions()->FindObject("palette");
  palette1->SetX1NDC(0.88);
  palette1->SetX2NDC(0.92);
  palette1->SetY1NDC(0.1);
  palette1->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateMedIsoEtavsPt, 4, 11);
  FinalFakeRateMedIsoEtavsPt->Write();

  FinalFakeRateTightIsoEtavsPt->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateTightIsoEtavsPt_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateTightIsoEtavsPt_->SetStats(false);
  FinalFakeRateTightIsoEtavsPt_->SetMarkerSize(.56);
  FinalFakeRateTightIsoEtavsPt_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette2 = (TPaletteAxis*)FinalFakeRateTightIsoEtavsPt_->GetListOfFunctions()->FindObject("palette");
  palette2->SetX1NDC(0.88);
  palette2->SetX2NDC(0.92);
  palette2->SetY1NDC(0.1);
  palette2->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateTightIsoEtavsPt, 4, 11);
  FinalFakeRateTightIsoEtavsPt->Write();

  FinalFakeRateDMFindEtavsPt->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateDMFindEtavsPt_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateDMFindEtavsPt_->SetStats(false);
  FinalFakeRateDMFindEtavsPt_->SetMarkerSize(.56);
  FinalFakeRateDMFindEtavsPt_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette3 = (TPaletteAxis*)FinalFakeRateDMFindEtavsPt_->GetListOfFunctions()->FindObject("palette");
  palette3->SetX1NDC(0.88);
  palette3->SetX2NDC(0.92);
  palette3->SetY1NDC(0.1);
  palette3->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMFindEtavsPt, 4, 11);
  FinalFakeRateDMFindEtavsPt->Write();
  
  FinalFakeRateLooseIsoPt_->Write();
  FinalFakeRateMedIsoPt_->Write();
  FinalFakeRateTightIsoPt_->Write();
  FinalFakeRateDMFindPt_->Write();
  FinalFakeRateDMtoMedIsoPt_->Write();
  
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

  FinalFakeRateLooseIsoEtavsPtWithSoftMuon->cd();
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_->Draw("COLZTEXT E");
  CMS_lumi(  FinalFakeRateLooseIsoEtavsPtWithSoftMuon, 4, 11);
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon->Write();
  FinalFakeRateMedIsoEtavsPtWithSoftMuon->cd();
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_->Draw("COLZTEXT E");
  CMS_lumi(  FinalFakeRateMedIsoEtavsPtWithSoftMuon, 4, 11);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon->Write();
  FinalFakeRateTightIsoEtavsPtWithSoftMuon->cd();
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_->Draw("COLZTEXT E");
  CMS_lumi(  FinalFakeRateTightIsoEtavsPtWithSoftMuon, 4, 11);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon->Write();
  FinalFakeRateDMFindEtavsPtWithSoftMuon->cd();
  FinalFakeRateDMFindEtavsPtWithSoftMuon_->Draw("COLZTEXT E");
  CMS_lumi(  FinalFakeRateDMFindEtavsPtWithSoftMuon, 4, 11);
  FinalFakeRateDMFindEtavsPtWithSoftMuon->Write();

  FinalFakeRateLooseIsoPtWithSoftMuon_->Write();
  FinalFakeRateMedIsoPtWithSoftMuon_->Write();
  FinalFakeRateTightIsoPtWithSoftMuon_->Write();
  FinalFakeRateDMFindPtWithSoftMuon_->Write();

  FinalFakeRateLooseIsoEtaWithSoftMuon_->Write();
  FinalFakeRateMedIsoEtaWithSoftMuon_->Write();
  FinalFakeRateTightIsoEtaWithSoftMuon_->Write();
  FinalFakeRateDMFindEtaWithSoftMuon_->Write();

  FinalFakeRateOneProngDMEtaWithSoftMuon_->Write();
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_->Write();
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_->Write();
  FinalFakeRateThreeProngDMEtaWithSoftMuon_->Write();
  FinalFakeRateOneProngDMPtWithSoftMuon_->Write();
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_->Write();
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_->Write();
  FinalFakeRateThreeProngDMPtWithSoftMuon_->Write();
  
  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_->Write();
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_->Write();
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_->Write();
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_->Write();
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_->Write();
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_->Write();
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_->Write();
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_->Write();

  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu->cd();
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu_->Draw("COLZTEXT E");
  CMS_lumi(  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu, 4, 11);
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu->Write();
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu->cd();
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu_->Draw("COLZTEXT E");
  CMS_lumi(  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu, 4, 11);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu->Write();
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu->cd();
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu_->Draw("COLZTEXT E");
  CMS_lumi(  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu, 4, 11);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu->Write();
  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu->cd();
  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu_->Draw("COLZTEXT E");
  CMS_lumi(  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu, 4, 11);
  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu->Write();

  FinalFakeRateLooseIsoPtWithSoftMuon_noMu_->Write();
  FinalFakeRateMedIsoPtWithSoftMuon_noMu_->Write();
  FinalFakeRateTightIsoPtWithSoftMuon_noMu_->Write();
  FinalFakeRateDMFindPtWithSoftMuon_noMu_->Write();

  FinalFakeRateLooseIsoEtaWithSoftMuon_noMu_->Write();
  FinalFakeRateMedIsoEtaWithSoftMuon_noMu_->Write();
  FinalFakeRateTightIsoEtaWithSoftMuon_noMu_->Write();
  FinalFakeRateDMFindEtaWithSoftMuon_noMu_->Write();

  FinalFakeRateOneProngDMEtaWithSoftMuon_noMu_->Write();
  FinalFakeRateOneProngOnePizDMEtaWithSoftMuon_noMu_->Write();
  FinalFakeRateOneProngTwoPizDMEtaWithSoftMuon_noMu_->Write();
  FinalFakeRateThreeProngDMEtaWithSoftMuon_noMu_->Write();
  FinalFakeRateOneProngDMPtWithSoftMuon_noMu_->Write();
  FinalFakeRateOneProngOnePizDMPtWithSoftMuon_noMu_->Write();
  FinalFakeRateOneProngTwoPizDMPtWithSoftMuon_noMu_->Write();
  FinalFakeRateThreeProngDMPtWithSoftMuon_noMu_->Write();
  
  FinalFakeRateOneProngMedIsoEtaWithSoftMuon_noMu_->Write();
  FinalFakeRateOneProngOnePizMedIsoEtaWithSoftMuon_noMu_->Write();
  FinalFakeRateOneProngTwoPizMedIsoEtaWithSoftMuon_noMu_->Write();
  FinalFakeRateThreeProngMedIsoEtaWithSoftMuon_noMu_->Write();
  FinalFakeRateOneProngMedIsoPtWithSoftMuon_noMu_->Write();
  FinalFakeRateOneProngOnePizMedIsoPtWithSoftMuon_noMu_->Write();
  FinalFakeRateOneProngTwoPizMedIsoPtWithSoftMuon_noMu_->Write();
  FinalFakeRateThreeProngMedIsoPtWithSoftMuon_noMu_->Write();

  //Same without, with, and with removed Mu plots
  TCanvas *COMB_FakeRatePtDMFind_ = new TCanvas("COMB_FakeRatePtDMFind","",600,600);
  TCanvas *COMB_FakeRatePtMedIso_ = new TCanvas("COMB_FakeRatePtMedIso","",600,600);
  TCanvas *COMB_FakeRatePtLooseIso_ = new TCanvas("COMB_FakeRatePtLooseIso","",600,600);
  TCanvas *COMB_FakeRatePtTightIso_ = new TCanvas("COMB_FakeRatePtTightIso","",600,600);

  COMB_FakeRatePtDMFind_->Divide(3,1);
  COMB_FakeRatePtDMFind_->cd(1);
  FinalFakeRateDMFindPt_->Draw();
  COMB_FakeRatePtDMFind_->cd(2);
  FinalFakeRateDMFindPtWithSoftMuon_->Draw();
  COMB_FakeRatePtDMFind_->cd(3);
  FinalFakeRateDMFindPtWithSoftMuon_noMu_->Draw();
  CMS_lumi(  COMB_FakeRatePtDMFind_, 4, 11);
  COMB_FakeRatePtDMFind_->Write();

  COMB_FakeRatePtLooseIso_->Divide(3,1);
  COMB_FakeRatePtLooseIso_->cd(1);
  FinalFakeRateLooseIsoPt_->Draw();
  COMB_FakeRatePtLooseIso_->cd(2);
  FinalFakeRateLooseIsoPtWithSoftMuon_->Draw();
  COMB_FakeRatePtLooseIso_->cd(3);
  FinalFakeRateLooseIsoPtWithSoftMuon_noMu_->Draw();
  CMS_lumi(  COMB_FakeRatePtLooseIso_, 4, 11);
  COMB_FakeRatePtLooseIso_->Write();

  COMB_FakeRatePtMedIso_->Divide(3,1);
  COMB_FakeRatePtMedIso_->cd(1);
  FinalFakeRateMedIsoPt_->Draw();
  COMB_FakeRatePtMedIso_->cd(2);
  FinalFakeRateMedIsoPtWithSoftMuon_->Draw();
  COMB_FakeRatePtMedIso_->cd(3);
  FinalFakeRateMedIsoPtWithSoftMuon_noMu_->Draw();
  CMS_lumi(  COMB_FakeRatePtMedIso_, 4, 11);
  COMB_FakeRatePtMedIso_->Write();

  COMB_FakeRatePtTightIso_->Divide(3,1);
  COMB_FakeRatePtTightIso_->cd(1);
  FinalFakeRateTightIsoPt_->Draw();
  COMB_FakeRatePtTightIso_->cd(2);
  FinalFakeRateTightIsoPtWithSoftMuon_->Draw();
  COMB_FakeRatePtTightIso_->cd(3);
  FinalFakeRateTightIsoPtWithSoftMuon_noMu_->Draw();
  CMS_lumi(  COMB_FakeRatePtTightIso_, 4, 11);
  COMB_FakeRatePtTightIso_->Write();

  TCanvas *COMB_FakeRateEtaDMFind_ = new TCanvas("COMB_FakeRateEtaDMFind","",600,600);
  TCanvas *COMB_FakeRateEtaMedIso_ = new TCanvas("COMB_FakeRateEtaMedIso","",600,600);
  TCanvas *COMB_FakeRateEtaLooseIso_ = new TCanvas("COMB_FakeRateEtaLooseIso","",600,600);
  TCanvas *COMB_FakeRateEtaTightIso_ = new TCanvas("COMB_FakeRateEtaTightIso","",600,600);

  COMB_FakeRateEtaDMFind_->Divide(3,1);
  COMB_FakeRateEtaDMFind_->cd(1);
  FinalFakeRateDMFindEta_->Draw();
  COMB_FakeRateEtaDMFind_->cd(2);
  FinalFakeRateDMFindEtaWithSoftMuon_->Draw();
  COMB_FakeRateEtaDMFind_->cd(3);
  FinalFakeRateDMFindEtaWithSoftMuon_noMu_->Draw();
  CMS_lumi(  COMB_FakeRateEtaDMFind_, 4, 11);
  COMB_FakeRateEtaDMFind_->Write();
  
  COMB_FakeRateEtaLooseIso_->Divide(3,1);
  COMB_FakeRateEtaLooseIso_->cd(1);
  FinalFakeRateLooseIsoEta_->Draw();
  COMB_FakeRateEtaLooseIso_->cd(2);
  FinalFakeRateLooseIsoEtaWithSoftMuon_->Draw();
  COMB_FakeRateEtaLooseIso_->cd(3);
  FinalFakeRateLooseIsoEtaWithSoftMuon_noMu_->Draw();
  CMS_lumi(  COMB_FakeRateEtaLooseIso_, 4, 11);
  COMB_FakeRateEtaLooseIso_->Write();
  
  COMB_FakeRateEtaMedIso_->Divide(3,1);
  COMB_FakeRateEtaMedIso_->cd(1);
  FinalFakeRateMedIsoEta_->Draw();
  COMB_FakeRateEtaMedIso_->cd(2);
  FinalFakeRateMedIsoEtaWithSoftMuon_->Draw();
  COMB_FakeRateEtaMedIso_->cd(3);
  FinalFakeRateMedIsoEtaWithSoftMuon_noMu_->Draw();
  CMS_lumi(  COMB_FakeRateEtaMedIso_, 4, 11);
  COMB_FakeRateEtaMedIso_->Write();
  
  COMB_FakeRateEtaTightIso_->Divide(3,1);
  COMB_FakeRateEtaTightIso_->cd(1);
  FinalFakeRateTightIsoEta_->Draw();
  COMB_FakeRateEtaTightIso_->cd(2);
  FinalFakeRateTightIsoEtaWithSoftMuon_->Draw();
  COMB_FakeRateEtaTightIso_->cd(3);
  FinalFakeRateTightIsoEtaWithSoftMuon_noMu_->Draw();
  CMS_lumi(  COMB_FakeRateEtaTightIso_, 4, 11);
  COMB_FakeRateEtaTightIso_->Write();

  TCanvas *COMB_FakeRateEtavsPtDMFind_ = new TCanvas("COMB_FakeRateEtavsPtDMFind","",600,600);
  TCanvas *COMB_FakeRateEtavsPtMedIso_ = new TCanvas("COMB_FakeRateEtavsPtMedIso","",600,600);
  TCanvas *COMB_FakeRateEtavsPtLooseIso_ = new TCanvas("COMB_FakeRateEtavsPtLooseIso","",600,600);
  TCanvas *COMB_FakeRateEtavsPtTightIso_ = new TCanvas("COMB_FakeRateEtavsPtTightIso","",600,600);
  
  COMB_FakeRateEtavsPtDMFind_->Divide(3,1);
  COMB_FakeRateEtavsPtDMFind_->cd(1);
  FinalFakeRateDMFindEtavsPt_->Draw("COLZTEXT E");
  COMB_FakeRateEtavsPtDMFind_->cd(2);
  FinalFakeRateDMFindEtavsPtWithSoftMuon_->Draw("COLZTEXT E");
  COMB_FakeRateEtavsPtDMFind_->cd(3);
  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu_->Draw("COLZTEXT E");
  CMS_lumi(  COMB_FakeRateEtavsPtDMFind_, 4, 11);
  COMB_FakeRateEtavsPtDMFind_->Write();
  
  COMB_FakeRateEtavsPtLooseIso_->Divide(3,1);
  COMB_FakeRateEtavsPtLooseIso_->cd(1);
  FinalFakeRateLooseIsoEtavsPt_->Draw("COLZTEXT E");
  COMB_FakeRateEtavsPtLooseIso_->cd(2);
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_->Draw("COLZTEXT E");
  COMB_FakeRateEtavsPtLooseIso_->cd(3);
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu_->Draw("COLZTEXT E");
  CMS_lumi(  COMB_FakeRateEtavsPtLooseIso_, 4, 11);
  COMB_FakeRateEtavsPtLooseIso_->Write();
  
  COMB_FakeRateEtavsPtMedIso_->Divide(3,1);
  COMB_FakeRateEtavsPtMedIso_->cd(1);
  FinalFakeRateMedIsoEtavsPt_->Draw("COLZTEXT E");
  COMB_FakeRateEtavsPtMedIso_->cd(2);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_->Draw("COLZTEXT E");
  COMB_FakeRateEtavsPtMedIso_->cd(3);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu_->Draw("COLZTEXT E");
  CMS_lumi(  COMB_FakeRateEtavsPtMedIso_, 4, 11);
  COMB_FakeRateEtavsPtMedIso_->Write();
  
  COMB_FakeRateEtavsPtTightIso_->Divide(3,1);
  COMB_FakeRateEtavsPtTightIso_->cd(1);
  FinalFakeRateTightIsoEtavsPt_->Draw("COLZTEXT E");
  COMB_FakeRateEtavsPtTightIso_->cd(2);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_->Draw("COLZTEXT E");
  COMB_FakeRateEtavsPtTightIso_->cd(3);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu_->Draw("COLZTEXT E");
  CMS_lumi(  COMB_FakeRateEtavsPtTightIso_, 4, 11);
  COMB_FakeRateEtavsPtTightIso_->Write();


  //Combination plots for all Isolation Requirements
  TCanvas *COMBAllIso_FakeRatePt_ = new TCanvas("COMBAllIso_FakeRatePt","",600,600);
  TCanvas *COMBAllIso_FakeRatePtWithSoftMuon_noMu_ = new TCanvas("COMBAllIso_FakeRatePtWithSoftMuon_noMu","",600,600);
  TCanvas *COMBAllIso_FakeRatePtWithSoftMuon_ = new TCanvas("COMBAllIso_FakeRatePtWithSoftMuon","",600,600);

  COMBAllIso_FakeRatePt_->Divide(2,2);
  COMBAllIso_FakeRatePt_->cd(1);
  FinalFakeRateDMFindPt_->Draw();
  COMBAllIso_FakeRatePt_->cd(2);
  FinalFakeRateLooseIsoPt_->Draw();
  COMBAllIso_FakeRatePt_->cd(3);
  FinalFakeRateMedIsoPt_->Draw();
  COMBAllIso_FakeRatePt_->cd(4);
  FinalFakeRateTightIsoPt_->Draw();
  CMS_lumi(  COMBAllIso_FakeRatePt_, 4, 11);
  COMBAllIso_FakeRatePt_->Write();
 
  COMBAllIso_FakeRatePtWithSoftMuon_->Divide(2,2);
  COMBAllIso_FakeRatePtWithSoftMuon_->cd(1);
  FinalFakeRateDMFindPtWithSoftMuon_->Draw();
  COMBAllIso_FakeRatePtWithSoftMuon_->cd(2);
  FinalFakeRateLooseIsoPtWithSoftMuon_->Draw();
  COMBAllIso_FakeRatePtWithSoftMuon_->cd(3);
  FinalFakeRateMedIsoPtWithSoftMuon_->Draw();
  COMBAllIso_FakeRatePtWithSoftMuon_->cd(4);
  FinalFakeRateTightIsoPtWithSoftMuon_->Draw();
  CMS_lumi(  COMBAllIso_FakeRatePtWithSoftMuon_, 4, 11);
  COMBAllIso_FakeRatePtWithSoftMuon_->Write();

  COMBAllIso_FakeRatePtWithSoftMuon_noMu_->Divide(2,2);
  COMBAllIso_FakeRatePtWithSoftMuon_noMu_->cd(1);
  FinalFakeRateDMFindPtWithSoftMuon_noMu_->Draw();
  COMBAllIso_FakeRatePtWithSoftMuon_noMu_->cd(2);
  FinalFakeRateLooseIsoPtWithSoftMuon_noMu_->Draw();
  COMBAllIso_FakeRatePtWithSoftMuon_noMu_->cd(3);
  FinalFakeRateMedIsoPtWithSoftMuon_noMu_->Draw();
  COMBAllIso_FakeRatePtWithSoftMuon_noMu_->cd(4);
  FinalFakeRateTightIsoPtWithSoftMuon_noMu_->Draw();
  CMS_lumi(  COMBAllIso_FakeRatePtWithSoftMuon_noMu_, 4, 11);
  COMBAllIso_FakeRatePtWithSoftMuon_noMu_->Write();


  TCanvas *COMBAllIso_FakeRateEta_ = new TCanvas("COMBAllIso_FakeRateEta","",600,600);
  TCanvas *COMBAllIso_FakeRateEtaWithSoftMuon_noMu_ = new TCanvas("COMBAllIso_FakeRateEtaWithSoftMuon_noMu","",600,600);
  TCanvas *COMBAllIso_FakeRateEtaWithSoftMuon_ = new TCanvas("COMBAllIso_FakeRateEtaWithSoftMuon","",600,600);

  COMBAllIso_FakeRateEta_->Divide(2,2);
  COMBAllIso_FakeRateEta_->cd(1);
  FinalFakeRateDMFindEta_->Draw();
  COMBAllIso_FakeRateEta_->cd(2);
  FinalFakeRateLooseIsoEta_->Draw();
  COMBAllIso_FakeRateEta_->cd(3);
  FinalFakeRateMedIsoEta_->Draw();
  COMBAllIso_FakeRateEta_->cd(4);
  FinalFakeRateTightIsoEta_->Draw();
  CMS_lumi(  COMBAllIso_FakeRateEta_, 4, 11);
  COMBAllIso_FakeRateEta_->Write();
  
  COMBAllIso_FakeRateEtaWithSoftMuon_->Divide(2,2);
  COMBAllIso_FakeRateEtaWithSoftMuon_->cd(1);
  FinalFakeRateDMFindEtaWithSoftMuon_->Draw();
  COMBAllIso_FakeRateEtaWithSoftMuon_->cd(2);
  FinalFakeRateLooseIsoEtaWithSoftMuon_->Draw();
  COMBAllIso_FakeRateEtaWithSoftMuon_->cd(3);
  FinalFakeRateMedIsoEtaWithSoftMuon_->Draw();
  COMBAllIso_FakeRateEtaWithSoftMuon_->cd(4);
  FinalFakeRateTightIsoEtaWithSoftMuon_->Draw();
  CMS_lumi(  COMBAllIso_FakeRateEtaWithSoftMuon_, 4, 11);
  COMBAllIso_FakeRateEtaWithSoftMuon_->Write();

  COMBAllIso_FakeRateEtaWithSoftMuon_noMu_->Divide(2,2);
  COMBAllIso_FakeRateEtaWithSoftMuon_noMu_->cd(1);
  FinalFakeRateDMFindEtaWithSoftMuon_noMu_->Draw();
  COMBAllIso_FakeRateEtaWithSoftMuon_noMu_->cd(2);
  FinalFakeRateLooseIsoEtaWithSoftMuon_noMu_->Draw();
  COMBAllIso_FakeRateEtaWithSoftMuon_noMu_->cd(3);
  FinalFakeRateMedIsoEtaWithSoftMuon_noMu_->Draw();
  COMBAllIso_FakeRateEtaWithSoftMuon_noMu_->cd(4);
  FinalFakeRateTightIsoEtaWithSoftMuon_noMu_->Draw();
  CMS_lumi(  COMBAllIso_FakeRateEtaWithSoftMuon_noMu_, 4, 11);
  COMBAllIso_FakeRateEtaWithSoftMuon_noMu_->Write();

  TCanvas *COMBAllIso_FakeRateEtavsPt_ = new TCanvas("COMBAllIso_FakeRateEtavsPt","",600,600);
  TCanvas *COMBAllIso_FakeRateEtavsPtWithSoftMuon_noMu_ = new TCanvas("COMBAllIso_FakeRateEtavsPtWithSoftMuon_noMu","",600,600);
  TCanvas *COMBAllIso_FakeRateEtavsPtWithSoftMuon_ = new TCanvas("COMBAllIso_FakeRateEtavsPtWithSoftMuon","",600,600);

  COMBAllIso_FakeRateEtavsPt_->Divide(2,2);
  COMBAllIso_FakeRateEtavsPt_->cd(1);
  FinalFakeRateDMFindEtavsPt_->Draw("COLZTEXT E");
  COMBAllIso_FakeRateEtavsPt_->cd(2);
  FinalFakeRateLooseIsoEtavsPt_->Draw("COLZTEXT E");
  COMBAllIso_FakeRateEtavsPt_->cd(3);
  FinalFakeRateMedIsoEtavsPt_->Draw("COLZTEXT E");
  COMBAllIso_FakeRateEtavsPt_->cd(4);
  FinalFakeRateTightIsoEtavsPt_->Draw("COLZTEXT E");
  CMS_lumi(  COMBAllIso_FakeRateEtavsPt_, 4, 11);
  COMBAllIso_FakeRateEtavsPt_->Write();
  
  COMBAllIso_FakeRateEtavsPtWithSoftMuon_->Divide(2,2);
  COMBAllIso_FakeRateEtavsPtWithSoftMuon_->cd(1);
  FinalFakeRateDMFindEtavsPtWithSoftMuon_->Draw("COLZTEXT E");
  COMBAllIso_FakeRateEtavsPtWithSoftMuon_->cd(2);
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_->Draw("COLZTEXT E");
  COMBAllIso_FakeRateEtavsPtWithSoftMuon_->cd(3);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_->Draw("COLZTEXT E");
  COMBAllIso_FakeRateEtavsPtWithSoftMuon_->cd(4);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_->Draw("COLZTEXT E");
  CMS_lumi(  COMBAllIso_FakeRateEtavsPtWithSoftMuon_, 4, 11);
  COMBAllIso_FakeRateEtavsPtWithSoftMuon_->Write();

  COMBAllIso_FakeRateEtavsPtWithSoftMuon_noMu_->Divide(2,2);
  COMBAllIso_FakeRateEtavsPtWithSoftMuon_noMu_->cd(1);
  FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu_->Draw("COLZTEXT E");
  COMBAllIso_FakeRateEtavsPtWithSoftMuon_noMu_->cd(2);
  FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu_->Draw("COLZTEXT E");
  COMBAllIso_FakeRateEtavsPtWithSoftMuon_noMu_->cd(3);
  FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu_->Draw("COLZTEXT E");
  COMBAllIso_FakeRateEtavsPtWithSoftMuon_noMu_->cd(4);
  FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu_->Draw("COLZTEXT E");
  CMS_lumi(  COMBAllIso_FakeRateEtavsPtWithSoftMuon_noMu_, 4, 11);
  COMBAllIso_FakeRateEtavsPtWithSoftMuon_noMu_->Write();

  gStyle->SetPalette(1);

  FinalFakeRateDMtoMedIsoOnlyEtavsPt->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->SetStats(false);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->SetMarkerSize(.56);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette4 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetListOfFunctions()->FindObject("palette");
  palette4->SetX1NDC(0.88);
  palette4->SetX2NDC(0.92);
cout << "end" << endl;

}//rootMacro_BBA_combine
