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


void rootMacro_GetTH2DBinBalues()
{

  gStyle->SetOptStat(kFALSE);
  gStyle->SetEndErrorSize(7);

  TFile infile ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/COMBINED_NoIsoDiTau_JUL19_RegionB.root");

  TCanvas* FinalFakeRateLooseIsoEtavsPtCanvas = (TCanvas*)infile.Get("FinalFakeRateLooseIsoEtavsPtCanvas");
  TCanvas* FinalFakeRateMedIsoEtavsPtCanvas = (TCanvas*)infile.Get("FinalFakeRateMedIsoEtavsPtCanvas");
  TCanvas* FinalFakeRateTightIsoEtavsPtCanvas = (TCanvas*)infile.Get("FinalFakeRateTightIsoEtavsPtCanvas");
  TCanvas* FinalFakeRateDMFindEtavsPtCanvas = (TCanvas*)infile.Get("FinalFakeRateDMFindEtavsPtCanvas");

  TH2F* FinalFakeRateLooseIsoEtavsPt_ = (TH2F*)FinalFakeRateLooseIsoEtavsPtCanvas->GetPrimitive("FakeRateLooseIsoEtavsPt");
  TH2F* FinalFakeRateMedIsoEtavsPt_ = (TH2F*)FinalFakeRateMedIsoEtavsPtCanvas->GetPrimitive("FakeRateMedIsoEtavsPt");
  TH2F* FinalFakeRateTightIsoEtavsPt_ = (TH2F*)FinalFakeRateTightIsoEtavsPtCanvas->GetPrimitive("FakeRateTightIsoEtavsPt");
  TH2F* FinalFakeRateDMFindEtavsPt_ = (TH2F*)FinalFakeRateDMFindEtavsPtCanvas->GetPrimitive("FakeRateDMFindEtavsPt");

  int xBins = FinalFakeRateLooseIsoEtavsPt_->GetNbinsX()+1;
  int yBins = FinalFakeRateLooseIsoEtavsPt_->GetNbinsY()+1;
  std::cout << "JetPt FakeRates: xBins=" << xBins << "  yBins=" << yBins << std::endl;

  std::cout << "FinalFakeRateLooseIsoEtavsPt" << std::endl;
  for (int x=1; x < xBins; x++)
  {
    for (int y=1; y < yBins; y++)
      std::cout << "x=" << x << "  y=" << y << "  Value=" << FinalFakeRateLooseIsoEtavsPt_->GetBinContent(x,y) << " yCenter=" << FinalFakeRateLooseIsoEtavsPt_->GetXaxis()->GetBinCenter(x) << " yCenter=" << FinalFakeRateLooseIsoEtavsPt_->GetYaxis()->GetBinCenter(y) << std::endl;
  }//for

  std::cout << "FinalFakeRateMedIsoEtavsPt" << std::endl;
  for (int x=1; x < xBins; x++)
  { 
    for (int y=1; y < yBins; y++)
      std::cout << "x=" << x << "  y=" << y << "  Value=" << FinalFakeRateMedIsoEtavsPt_->GetBinContent(x,y) << std::endl;
  }//for

  std::cout << "FinalFakeRateTightIsoEtavsPt" << std::endl;
  for (int x=1; x < xBins; x++)
  { 
    for (int y=1; y < yBins; y++)
      std::cout << "x=" << x << "  y=" << y << "  Value=" << FinalFakeRateTightIsoEtavsPt_->GetBinContent(x,y) << std::endl;
  }//for

  std::cout << "FinalFakeRateDMFindEtavsPt" << std::endl;
  for (int x=1; x < xBins; x++)
  { 
    for (int y=1; y < yBins; y++)
      std::cout << "x=" << x << "  y=" << y << "  Value=" << FinalFakeRateDMFindEtavsPt_->GetBinContent(x,y) << std::endl;
  }//for

  TCanvas* FinalFakeRateLooseIsoEtavsPtWithSoftMuonCanvas = (TCanvas*)infile.Get("FinalFakeRateLooseIsoEtavsPtWithSoftMuonCanvas");
  TCanvas* FinalFakeRateMedIsoEtavsPtWithSoftMuonCanvas = (TCanvas*)infile.Get("FinalFakeRateMedIsoEtavsPtWithSoftMuonCanvas");
  TCanvas* FinalFakeRateTightIsoEtavsPtWithSoftMuonCanvas = (TCanvas*)infile.Get("FinalFakeRateTightIsoEtavsPtWithSoftMuonCanvas");
  TCanvas* FinalFakeRateDMFindEtavsPtWithSoftMuonCanvas = (TCanvas*)infile.Get("FinalFakeRateDMFindEtavsPtWithSoftMuonCanvas");

  TH2F* FinalFakeRateLooseIsoEtavsPtWithSoftMuon_ = (TH2F*)FinalFakeRateLooseIsoEtavsPtWithSoftMuonCanvas->GetPrimitive("FakeRateLooseIsoEtavsPtWithSoftMuon");
  TH2F* FinalFakeRateMedIsoEtavsPtWithSoftMuon_ = (TH2F*)FinalFakeRateMedIsoEtavsPtWithSoftMuonCanvas->GetPrimitive("FakeRateMedIsoEtavsPtWithSoftMuon");
  TH2F* FinalFakeRateTightIsoEtavsPtWithSoftMuon_ = (TH2F*)FinalFakeRateTightIsoEtavsPtWithSoftMuonCanvas->GetPrimitive("FakeRateTightIsoEtavsPtWithSoftMuon");
  TH2F* FinalFakeRateDMFindEtavsPtWithSoftMuon_ = (TH2F*)FinalFakeRateDMFindEtavsPtWithSoftMuonCanvas->GetPrimitive("FakeRateDMFindEtavsPtWithSoftMuon");

  std::cout << "JetPtWithSoftMuon FakeRates: xBins=" << xBins << "  yBins=" << yBins << std::endl;

  std::cout << "FinalFakeRateLooseIsoEtavsPtWithSoftMuon" << std::endl;
  for (int x=1; x < xBins; x++)
  {
    for (int y=1; y < yBins; y++)
      std::cout << "x=" << x << "  y=" << y << "  Value=" << FinalFakeRateLooseIsoEtavsPtWithSoftMuon_->GetBinContent(x,y) << std::endl;
  }//for

  std::cout << "FinalFakeRateMedIsoEtavsPtWithSoftMuon" << std::endl;
  for (int x=1; x < xBins; x++)
  {
    for (int y=1; y < yBins; y++)
      std::cout << "x=" << x << "  y=" << y << "  Value=" << FinalFakeRateMedIsoEtavsPtWithSoftMuon_->GetBinContent(x,y) << std::endl;
  }//for

  std::cout << "FinalFakeRateTightIsoEtavsPtWithSoftMuon" << std::endl;
  for (int x=1; x < xBins; x++)
  {
    for (int y=1; y < yBins; y++)
      std::cout << "x=" << x << "  y=" << y << "  Value=" << FinalFakeRateTightIsoEtavsPtWithSoftMuon_->GetBinContent(x,y) << std::endl;
  }//for

  std::cout << "FinalFakeRateDMFindEtavsPtWithSoftMuon" << std::endl;
  for (int x=1; x < xBins; x++)
  {
    for (int y=1; y < yBins; y++)
      std::cout << "x=" << x << "  y=" << y << "  Value=" << FinalFakeRateDMFindEtavsPtWithSoftMuon_->GetBinContent(x,y) << std::endl;
  }//for

  TCanvas* FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMuCanvas = (TCanvas*)infile.Get("FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMuCanvas");
  TCanvas* FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMuCanvas = (TCanvas*)infile.Get("FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMuCanvas");
  TCanvas* FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMuCanvas = (TCanvas*)infile.Get("FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMuCanvas");
  TCanvas* FinalFakeRateDMFindEtavsPtWithSoftMuon_noMuCanvas = (TCanvas*)infile.Get("FinalFakeRateDMFindEtavsPtWithSoftMuon_noMuCanvas");

  TH2F* FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu_ = (TH2F*)FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMuCanvas->GetPrimitive("FakeRateLooseIsoEtavsPtWithSoftMuon_noMu");
  TH2F* FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu_ = (TH2F*)FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMuCanvas->GetPrimitive("FakeRateMedIsoEtavsPtWithSoftMuon_noMu");
  TH2F* FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu_ = (TH2F*)FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMuCanvas->GetPrimitive("FakeRateTightIsoEtavsPtWithSoftMuon_noMu");
  TH2F* FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu_ = (TH2F*)FinalFakeRateDMFindEtavsPtWithSoftMuon_noMuCanvas->GetPrimitive("FakeRateDMFindEtavsPtWithSoftMuon_noMu");

  std::cout << "JetPtWithSoftMuon_noMu FakeRates: xBins=" << xBins << "  yBins=" << yBins << std::endl;
  
  std::cout << "FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu" << std::endl;
  for (int x=1; x < xBins; x++)
  { 
    for (int y=1; y < yBins; y++)
      std::cout << "x=" << x << "  y=" << y << "  Value=" << FinalFakeRateLooseIsoEtavsPtWithSoftMuon_noMu_->GetBinContent(x,y) << std::endl;
  }//for
  
  std::cout << "FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu" << std::endl;
  for (int x=1; x < xBins; x++)
  { 
    for (int y=1; y < yBins; y++)
      std::cout << "x=" << x << "  y=" << y << "  Value=" << FinalFakeRateMedIsoEtavsPtWithSoftMuon_noMu_->GetBinContent(x,y) << std::endl;
  }//for
  
  std::cout << "FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu" << std::endl;
  for (int x=1; x < xBins; x++)
  { 
    for (int y=1; y < yBins; y++)
      std::cout << "x=" << x << "  y=" << y << "  Value=" << FinalFakeRateTightIsoEtavsPtWithSoftMuon_noMu_->GetBinContent(x,y) << std::endl;
  }//for

  std::cout << "FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu" << std::endl;
  for (int x=1; x < xBins; x++)
  {
    for (int y=1; y < yBins; y++)
      std::cout << "x=" << x << "  y=" << y << "  Value=" << FinalFakeRateDMFindEtavsPtWithSoftMuon_noMu_->GetBinContent(x,y) << std::endl;
  }//for


}
