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
#include "tdrstyle.C"
#include "CMS_lumi.C"


void rootMacro_GetFakeRate_JustOneIWant()
{
  setTDRStyle(true);
  gStyle->SetPalette(1);

  TFile infile ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TauFakeRate/FINAL_SingleMu_MedIsoMu2_TauDM_ZSKIM_SEP2_TauFakeRate_Add3Bin_v6.root");
  TFile infileWZ ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TauFakeRate/FINAL_WZ3L1Nu_MedIsoMu2_TauDM_ZSKIM_SEP2_TauFakeRate_Add3Bin_v6.root");
  TFile infileZZ ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TauFakeRate/FINAL_ZZTo4LAmac_MedIsoMu2_TauDM_ZSKIM_SEP2_TauFakeRate_Add3Bin_v6.root");

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TAUFAKERATES_Add3Bin_v6.root", "RECREATE");
  TFile *outFileUP = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TAUFAKERATES_UP_Add3Bin_v6.root", "RECREATE");
  TFile *outFileDOWN = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TAUFAKERATES_DOWN_Add3Bin_v6.root", "RECREATE");

  TH2F* EtavsPtTauMedIsoWZ_ = (TH2F*)infileWZ.Get("EtavsPtTauMedIso");
  TH2F* EtavsPtTauMedIsoZZ_ = (TH2F*)infileZZ.Get("EtavsPtTauMedIso");
  TH2F* EtavsPtTauMedIso_ = (TH2F*)infile.Get("EtavsPtTauMedIso");
  TH2F* EtavsPtTauDMFind_ = (TH2F*)infile.Get("EtavsPtTauDMFind");
  TH1F* TauMedIsoPt_ = (TH1F*)infile.Get("TauMedIsoPt");
  TH1F* TauDMFindPt_ = (TH1F*)infile.Get("TauDMFindPt");

  TH2F* EtavsPtTauMedIsoWZDM0_ = (TH2F*)infileWZ.Get("EtavsPtTauMedIsoDM0");
  TH2F* EtavsPtTauMedIsoZZDM0_ = (TH2F*)infileZZ.Get("EtavsPtTauMedIsoDM0");
  TH2F* EtavsPtTauMedIsoDM0_ = (TH2F*)infile.Get("EtavsPtTauMedIsoDM0");
  TH2F* EtavsPtTauDMFindDM0_ = (TH2F*)infile.Get("EtavsPtTauDMFindDM0");
  TH1F* TauMedIsoPtDM0_ = (TH1F*)infile.Get("TauMedIsoPtDM0");
  TH1F* TauDMFindPtDM0_ = (TH1F*)infile.Get("TauDMFindPtDM0");

  TH2F* EtavsPtTauMedIsoWZDM1_ = (TH2F*)infileWZ.Get("EtavsPtTauMedIsoDM1");
  TH2F* EtavsPtTauMedIsoZZDM1_ = (TH2F*)infileZZ.Get("EtavsPtTauMedIsoDM1");
  TH2F* EtavsPtTauMedIsoDM1_ = (TH2F*)infile.Get("EtavsPtTauMedIsoDM1");
  TH2F* EtavsPtTauDMFindDM1_ = (TH2F*)infile.Get("EtavsPtTauDMFindDM1");
  TH1F* TauMedIsoPtDM1_ = (TH1F*)infile.Get("TauMedIsoPtDM1");
  TH1F* TauDMFindPtDM1_ = (TH1F*)infile.Get("TauDMFindPtDM1");

  TH2F* EtavsPtTauMedIsoWZDM10_ = (TH2F*)infileWZ.Get("EtavsPtTauMedIsoDM10");
  TH2F* EtavsPtTauMedIsoZZDM10_ = (TH2F*)infileZZ.Get("EtavsPtTauMedIsoDM10");
  TH2F* EtavsPtTauMedIsoDM10_ = (TH2F*)infile.Get("EtavsPtTauMedIsoDM10");
  TH2F* EtavsPtTauDMFindDM10_ = (TH2F*)infile.Get("EtavsPtTauDMFindDM10");
  TH1F* TauMedIsoPtDM10_ = (TH1F*)infile.Get("TauMedIsoPtDM10");
  TH1F* TauDMFindPtDM10_ = (TH1F*)infile.Get("TauDMFindPtDM10");

  TGraphAsymmErrors* FinalFakeRateDMtoMedIsoPt_ = new TGraphAsymmErrors(30);
  FinalFakeRateDMtoMedIsoPt_->Divide(TauMedIsoPt_, TauDMFindPt_);
  FinalFakeRateDMtoMedIsoPt_->SetName("FakeRateDMtoMedIsoPt");
  FinalFakeRateDMtoMedIsoPt_->SetMarkerSize(.07);
  FinalFakeRateDMtoMedIsoPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateDMtoMedIsoPt_->SetTitle("Fake Rate (# PFTau + DMFind + MedIso / # PFTau + DMFind)");
  FinalFakeRateDMtoMedIsoPt_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMtoMedIsoPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateDMtoMedIsoPt_->SetLineWidth(3);

  TGraphAsymmErrors* FinalFakeRateDMtoMedIsoPtDM0_ = new TGraphAsymmErrors(30);
  FinalFakeRateDMtoMedIsoPtDM0_->Divide(TauMedIsoPtDM0_, TauDMFindPtDM0_);
  FinalFakeRateDMtoMedIsoPtDM0_->SetName("FakeRateDMtoMedIsoPtDM0");
  FinalFakeRateDMtoMedIsoPtDM0_->SetMarkerSize(.07);
  FinalFakeRateDMtoMedIsoPtDM0_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateDMtoMedIsoPtDM0_->SetTitle("Fake Rate (# PFTau + DMFind + MedIso / # PFTau + DMFind)");
  FinalFakeRateDMtoMedIsoPtDM0_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMtoMedIsoPtDM0_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateDMtoMedIsoPtDM0_->SetLineWidth(3);

  TGraphAsymmErrors* FinalFakeRateDMtoMedIsoPtDM1_ = new TGraphAsymmErrors(30);
  FinalFakeRateDMtoMedIsoPtDM1_->Divide(TauMedIsoPtDM1_, TauDMFindPtDM1_);
  FinalFakeRateDMtoMedIsoPtDM1_->SetName("FakeRateDMtoMedIsoPtDM1");
  FinalFakeRateDMtoMedIsoPtDM1_->SetMarkerSize(.07);
  FinalFakeRateDMtoMedIsoPtDM1_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateDMtoMedIsoPtDM1_->SetTitle("Fake Rate (# PFTau + DMFind + MedIso / # PFTau + DMFind)");
  FinalFakeRateDMtoMedIsoPtDM1_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMtoMedIsoPtDM1_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateDMtoMedIsoPtDM1_->SetLineWidth(3);

  TGraphAsymmErrors* FinalFakeRateDMtoMedIsoPtDM10_ = new TGraphAsymmErrors(30);
  FinalFakeRateDMtoMedIsoPtDM10_->Divide(TauMedIsoPtDM10_, TauDMFindPtDM10_);
  FinalFakeRateDMtoMedIsoPtDM10_->SetName("FakeRateDMtoMedIsoPtDM10");
  FinalFakeRateDMtoMedIsoPtDM10_->SetMarkerSize(.07);
  FinalFakeRateDMtoMedIsoPtDM10_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateDMtoMedIsoPtDM10_->SetTitle("Fake Rate (# PFTau + DMFind + MedIso / # PFTau + DMFind)");
  FinalFakeRateDMtoMedIsoPtDM10_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMtoMedIsoPtDM10_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateDMtoMedIsoPtDM10_->SetLineWidth(3);


  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPt = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtCanvas","",600,600);
  TH2F* FinalFakeRateDMtoMedIsoOnlyEtavsPt_ = (TH2F*)EtavsPtTauMedIso_->Clone();

  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0 = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0Canvas","",600,600);
  TH2F* FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_ = (TH2F*)EtavsPtTauMedIsoDM0_->Clone();

  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1 = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1Canvas","",600,600);
  TH2F* FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_ = (TH2F*)EtavsPtTauMedIsoDM1_->Clone();

  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10 = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10Canvas","",600,600);
  TH2F* FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_ = (TH2F*)EtavsPtTauMedIsoDM10_->Clone();

  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Add(EtavsPtTauMedIsoWZ_, -1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Add(EtavsPtTauMedIsoZZ_, -1.0);

  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->Add(EtavsPtTauMedIsoWZDM0_, -1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->Add(EtavsPtTauMedIsoZZDM0_, -1.0);

  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->Add(EtavsPtTauMedIsoWZDM1_, -1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->Add(EtavsPtTauMedIsoZZDM1_, -1.0);

  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->Add(EtavsPtTauMedIsoWZDM10_, -1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->Add(EtavsPtTauMedIsoZZDM10_, -1.0);

  for (int i=1; i < FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetXaxis()->GetNbins()+1; i++)
  {
    for (int j=1; j < FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetYaxis()->GetNbins()+1; j++)
    {
      if (FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetBinContent(i,j) < 0)
        FinalFakeRateDMtoMedIsoOnlyEtavsPt_->SetBinContent(i,j, 0.0);
      if (FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->GetBinContent(i,j) < 0)
        FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->SetBinContent(i,j, 0.0);
      if (FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->GetBinContent(i,j) < 0)
        FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->SetBinContent(i,j, 0.0);
      if (FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->GetBinContent(i,j) < 0)
        FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->SetBinContent(i,j, 0.0);

    }//for j
  }//for i


  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Divide(EtavsPtTauDMFind_);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->Divide(EtavsPtTauDMFindDM0_);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->Divide(EtavsPtTauDMFindDM1_);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->Divide(EtavsPtTauDMFindDM10_);


  for (int i=1; i < EtavsPtTauMedIso_->GetXaxis()->GetNbins()+1; i++)
  {
    for (int j=1; j < EtavsPtTauMedIso_->GetYaxis()->GetNbins()+1; j++)
    {
      double P = EtavsPtTauMedIso_->GetBinContent(i,j);
      double N = EtavsPtTauDMFind_->GetBinContent(i,j), F = N-P;
      if (N > 0)
        FinalFakeRateDMtoMedIsoOnlyEtavsPt_->SetBinError(i,j, pow( (P*F) / (N*N*N), 0.5) );
      std::cout << "P= " << P << "\tN=" << N << "\tF=" << F << std::endl;
      std::cout << "(P*F) / (N*N*N)=" << (P*F) / (N*N*N) << "\tpow( (P*F) / (N*N*N), 0.5)=" << pow( (P*F) / (N*N*N), 0.5) << std::endl;
    }//for j
  }//fori

  for (int i=1; i < EtavsPtTauMedIsoDM0_->GetXaxis()->GetNbins()+1; i++)
  { 
    for (int j=1; j < EtavsPtTauMedIsoDM0_->GetYaxis()->GetNbins()+1; j++)
    { 
      double P = EtavsPtTauMedIsoDM0_->GetBinContent(i,j); 
      double N = EtavsPtTauDMFindDM0_->GetBinContent(i,j), F = N-P;
      if (N > 0)
        FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->SetBinError(i,j, pow( (P*F) / (N*N*N), 0.5) );
      std::cout << "P= " << P << "\tN=" << N << "\tF=" << F << std::endl;
      std::cout << "(P*F) / (N*N*N)=" << (P*F) / (N*N*N) << "\tpow( (P*F) / (N*N*N), 0.5)=" << pow( (P*F) / (N*N*N), 0.5) << std::endl;
    }//for j
  }//fori

  for (int i=1; i < EtavsPtTauMedIsoDM1_->GetXaxis()->GetNbins()+1; i++)
  { 
    for (int j=1; j < EtavsPtTauMedIsoDM1_->GetYaxis()->GetNbins()+1; j++)
    { 
      double P = EtavsPtTauMedIsoDM1_->GetBinContent(i,j); 
      double N = EtavsPtTauDMFindDM1_->GetBinContent(i,j), F = N-P;
      if (N > 0)
        FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->SetBinError(i,j, pow( (P*F) / (N*N*N), 0.5) );
      std::cout << "P= " << P << "\tN=" << N << "\tF=" << F << std::endl;
      std::cout << "(P*F) / (N*N*N)=" << (P*F) / (N*N*N) << "\tpow( (P*F) / (N*N*N), 0.5)=" << pow( (P*F) / (N*N*N), 0.5) << std::endl;
    }//for j
  }//fori

  for (int i=1; i < EtavsPtTauMedIsoDM10_->GetXaxis()->GetNbins()+1; i++)
  { 
    for (int j=1; j < EtavsPtTauMedIsoDM10_->GetYaxis()->GetNbins()+1; j++)
    { 
      double P = EtavsPtTauMedIsoDM10_->GetBinContent(i,j); 
      double N = EtavsPtTauDMFindDM10_->GetBinContent(i,j), F = N-P;
      if (N > 0)
        FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->SetBinError(i,j, pow( (P*F) / (N*N*N), 0.5) );
      std::cout << "P= " << P << "\tN=" << N << "\tF=" << F << std::endl;
      std::cout << "(P*F) / (N*N*N)=" << (P*F) / (N*N*N) << "\tpow( (P*F) / (N*N*N), 0.5)=" << pow( (P*F) / (N*N*N), 0.5) << std::endl;
    }//for j
  }//fori

  FinalFakeRateDMtoMedIsoOnlyEtavsPt->SetFillColor(0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt->SetFillStyle(0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetYaxis()->SetLabelOffset(0.007);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->SetName("FakeRateDMFindEtavsPt");
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetYaxis()->SetTitle("|#eta|");
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetYaxis()->SetTitleOffset(1.5);

  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0->SetFillColor(0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0->SetFillStyle(0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->GetYaxis()->SetLabelOffset(0.007);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->SetName("FakeRateDMFindEtavsPtDM0");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->GetXaxis()->SetTitle("p_{T}(#tau) DM0");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->GetYaxis()->SetTitle("|#eta|");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->GetYaxis()->SetTitleOffset(1.5);

  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1->SetFillColor(0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1->SetFillStyle(0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->GetYaxis()->SetLabelOffset(0.007);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->SetName("FakeRateDMFindEtavsPtDM1");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->GetXaxis()->SetTitle("p_{T}(#tau) DM1");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->GetYaxis()->SetTitle("|#eta|");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->GetYaxis()->SetTitleOffset(1.5);

  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10->SetFillColor(0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10->SetFillStyle(0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->GetYaxis()->SetLabelOffset(0.007);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->SetName("FakeRateDMFindEtavsPtDM10");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->GetXaxis()->SetTitle("p_{T}(#tau) DM10");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->GetYaxis()->SetTitle("|#eta|");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->GetYaxis()->SetTitleOffset(1.5);

  outFile->cd();
  gStyle->SetPalette(1);
  writeExtraText = true;
  lumi_13TeV = "35.9 fb^{-1}";

  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->SetName("FinalFakeRateDMtoMedIsoOnlyEtavsPt");
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Write();
  FinalFakeRateDMtoMedIsoOnlyEtavsPt->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->SetStats(false);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->SetMarkerSize(1);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette4 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetListOfFunctions()->FindObject("palette");
  palette4->SetX1NDC(0.88);
  palette4->SetX2NDC(0.92);
  palette4->SetY1NDC(0.1);
  palette4->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPt, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt->Write();

  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->SetName("FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->Write();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->SetStats(false);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->SetMarkerSize(1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette4 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->GetListOfFunctions()->FindObject("palette");
  palette4->SetX1NDC(0.88);
  palette4->SetX2NDC(0.92);
  palette4->SetY1NDC(0.1);
  palette4->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0->Write();

  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->SetName("FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->Write();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->SetStats(false);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->SetMarkerSize(1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette4 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->GetListOfFunctions()->FindObject("palette");
  palette4->SetX1NDC(0.88);
  palette4->SetX2NDC(0.92);
  palette4->SetY1NDC(0.1);
  palette4->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1->Write();

  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->SetName("FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->Write();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->SetStats(false);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->SetMarkerSize(1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette4 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->GetListOfFunctions()->FindObject("palette");
  palette4->SetX1NDC(0.88);
  palette4->SetX2NDC(0.92);
  palette4->SetY1NDC(0.1);
  palette4->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10->Write();

  TCanvas *FinalFakeRateDMtoMedIsoOnlyPt = new TCanvas("FinalFakeRateDMtoMedIsoOnlyPtCanvas","",600,600);
  FinalFakeRateDMtoMedIsoPt_->Write();
  FinalFakeRateDMtoMedIsoOnlyPt->cd();
  FinalFakeRateDMtoMedIsoPt_->Draw();
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyPt, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyPt->Write();

  TCanvas *FinalFakeRateDMtoMedIsoOnlyPtDM0 = new TCanvas("FinalFakeRateDMtoMedIsoOnlyPtDM0Canvas","",600,600);
  FinalFakeRateDMtoMedIsoPtDM0_->Write();
  FinalFakeRateDMtoMedIsoOnlyPtDM0->cd();
  FinalFakeRateDMtoMedIsoPtDM0_->Draw();
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyPtDM0, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyPtDM0->Write();

  TCanvas *FinalFakeRateDMtoMedIsoOnlyPtDM1 = new TCanvas("FinalFakeRateDMtoMedIsoOnlyPtDM1Canvas","",600,600);
  FinalFakeRateDMtoMedIsoPtDM1_->Write();
  FinalFakeRateDMtoMedIsoOnlyPtDM1->cd();
  FinalFakeRateDMtoMedIsoPtDM1_->Draw();
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyPtDM1, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyPtDM1->Write();

  TCanvas *FinalFakeRateDMtoMedIsoOnlyPtDM10 = new TCanvas("FinalFakeRateDMtoMedIsoOnlyPtDM10Canvas","",600,600);
  FinalFakeRateDMtoMedIsoPtDM10_->Write();
  FinalFakeRateDMtoMedIsoOnlyPtDM10->cd();
  FinalFakeRateDMtoMedIsoPtDM10_->Draw();
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyPtDM10, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyPtDM10->Write();

  outFile->Close();

  TH2F *FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_ = (TH2F*)FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Clone();
  TH2F *FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_ = (TH2F*)FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Clone();
  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPtUP = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtUPCanvas","",600,600);
  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWNCanvas","",600,600);

  TH2F *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UP_ = (TH2F*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->Clone();
  TH2F *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN_ = (TH2F*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0_->Clone();
  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UP = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UPCanvas","",600,600);
  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWNCanvas","",600,600);
  
  TH2F *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UP_ = (TH2F*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->Clone();
  TH2F *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN_ = (TH2F*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1_->Clone();
  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UP = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UPCanvas","",600,600);
  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWNCanvas","",600,600);

  TH2F *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UP_ = (TH2F*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->Clone();
  TH2F *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN_ = (TH2F*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10_->Clone();
  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UP = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UPCanvas","",600,600);
  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWNCanvas","",600,600);


  for (int i=1; i < EtavsPtTauMedIso_->GetXaxis()->GetNbins()+1; i++)
  {
    for (int j=1; j < EtavsPtTauMedIso_->GetYaxis()->GetNbins()+1; j++)
    {
      FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->SetBinContent(i,j, FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->GetBinContent(i,j) + FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->GetBinError(i,j) );
      FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UP_->SetBinContent(i,j, FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UP_->GetBinContent(i,j) + FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UP_->GetBinError(i,j) );
      FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UP_->SetBinContent(i,j, FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UP_->GetBinContent(i,j) + FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UP_->GetBinError(i,j) );
      FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UP_->SetBinContent(i,j, FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UP_->GetBinContent(i,j) + FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UP_->GetBinError(i,j) );
      if ( (FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->GetBinContent(i,j) - FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->GetBinError(i,j)) < 0)
        FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->SetBinContent(i,j, .00001);
      else
        FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->SetBinContent(i,j, FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->GetBinContent(i,j) - FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->GetBinError(i,j) );

      if ( (FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN_->GetBinContent(i,j) - FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN_->GetBinError(i,j)) < 0)
        FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN_->SetBinContent(i,j, .00001);
      else
        FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN_->SetBinContent(i,j, FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN_->GetBinContent(i,j) - FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN_->GetBinError(i,j) );

      if ( (FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN_->GetBinContent(i,j) - FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN_->GetBinError(i,j)) < 0)
        FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN_->SetBinContent(i,j, .00001);
      else
        FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN_->SetBinContent(i,j, FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN_->GetBinContent(i,j) - FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN_->GetBinError(i,j) );

      if ( (FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN_->GetBinContent(i,j) - FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN_->GetBinError(i,j)) < 0)
        FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN_->SetBinContent(i,j, .00001);
      else
        FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN_->SetBinContent(i,j, FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN_->GetBinContent(i,j) - FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN_->GetBinError(i,j) );
    }//for j
  }//for i

  outFileUP->cd();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->Write();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtUP->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->SetStats(false);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->SetMarkerSize(1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette5 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->GetListOfFunctions()->FindObject("palette");
  palette5->SetX1NDC(0.88);
  palette5->SetX2NDC(0.92);
  palette5->SetY1NDC(0.1);
  palette5->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPtUP, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtUP->Write();

  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UP_->Write();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UP->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UP_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UP_->SetStats(false);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UP_->SetMarkerSize(1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UP_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette5 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UP_->GetListOfFunctions()->FindObject("palette");
  palette5->SetX1NDC(0.88);
  palette5->SetX2NDC(0.92);
  palette5->SetY1NDC(0.1);
  palette5->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UP, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0UP->Write();


  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UP_->Write();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UP->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UP_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UP_->SetStats(false);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UP_->SetMarkerSize(1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UP_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette5 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UP_->GetListOfFunctions()->FindObject("palette");
  palette5->SetX1NDC(0.88);
  palette5->SetX2NDC(0.92);
  palette5->SetY1NDC(0.1);
  palette5->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UP, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1UP->Write();


  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UP_->Write();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UP->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UP_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UP_->SetStats(false);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UP_->SetMarkerSize(1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UP_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette5 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UP_->GetListOfFunctions()->FindObject("palette");
  palette5->SetX1NDC(0.88);
  palette5->SetX2NDC(0.92);
  palette5->SetY1NDC(0.1);
  palette5->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UP, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10UP->Write();
  outFileUP->Close();





  outFileDOWN->cd();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->Write();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->SetStats(false);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->SetMarkerSize(1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette6 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->GetListOfFunctions()->FindObject("palette");
  palette6->SetX1NDC(0.88);
  palette6->SetX2NDC(0.92);
  palette6->SetY1NDC(0.1);
  palette6->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN->SetLogx();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN->Write();

  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN_->Write();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN_->SetStats(false);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN_->SetMarkerSize(1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette6 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN_->GetListOfFunctions()->FindObject("palette");
  palette6->SetX1NDC(0.88);
  palette6->SetX2NDC(0.92);
  palette6->SetY1NDC(0.1);
  palette6->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN->SetLogx();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0DOWN->Write();

  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN_->Write();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN_->SetStats(false);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN_->SetMarkerSize(1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette6 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN_->GetListOfFunctions()->FindObject("palette");
  palette6->SetX1NDC(0.88);
  palette6->SetX2NDC(0.92);
  palette6->SetY1NDC(0.1);
  palette6->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN->SetLogx();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1DOWN->Write();

  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN_->Write();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN_->SetStats(false);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN_->SetMarkerSize(1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette6 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN_->GetListOfFunctions()->FindObject("palette");
  palette6->SetX1NDC(0.88);
  palette6->SetX2NDC(0.92);
  palette6->SetY1NDC(0.1);
  palette6->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN->SetLogx();
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10DOWN->Write();

  outFileDOWN->Close();

  FinalFakeRateDMtoMedIsoOnlyEtavsPt->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRates/TauFakeRateDMtoMedIsoEtavsPt.png");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM0->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRates/TauFakeRateDMtoMedIsoEtavsPtDM0.png");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM1->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRates/TauFakeRateDMtoMedIsoEtavsPtDM1.png");
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDM10->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRates/TauFakeRateDMtoMedIsoEtavsPtDM10.png");
  FinalFakeRateDMtoMedIsoOnlyEtavsPt->cd();
  gPad->SetLogx(true);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRates/TauFakeRateDMtoMedIsoEtavsPtLog.png");
  FinalFakeRateDMtoMedIsoOnlyPt->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRates/TauFakeRateDMtoMedIsoPt.png");
  FinalFakeRateDMtoMedIsoOnlyPt->SetLogy(true);
  FinalFakeRateDMtoMedIsoOnlyPt->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRates/TauFakeRateDMtoMedIsoPtLog.png");

cout << "end" << endl;

}//rootMacro_BBA_combine
