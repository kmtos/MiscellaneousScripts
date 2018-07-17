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

  TFile infile ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/GetRates/FINAL_SingleMu_MedIsoMu2_TauDM_ZSKIM_MAY1_TauFakeRate.root");
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TAUFAKERATES.root", "RECREATE");
  TFile *outFileUP = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TAUFAKERATES_UP.root", "RECREATE");
  TFile *outFileDOWN = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TAUFAKERATES_DOWN.root", "RECREATE");
  TFile infileWZ ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/GetRates/FINAL_WZ3L1Nu_MedIsoMu2_TauDM_ZSKIM_MAY1_TauFakeRate.root");
  TFile infileZZ ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/GetRates/FINAL_ZZTo4LAmac_MedIsoMu2_TauDM_ZSKIM_MAY1_TauFakeRate.root");

  TH2F* EtavsPtTauMedIsoWZ_ = (TH2F*)infileWZ.Get("EtavsPtTauMedIso");
  TH2F* EtavsPtTauMedIsoZZ_ = (TH2F*)infileZZ.Get("EtavsPtTauMedIso");
  TH2F* EtavsPtTauMedIso_ = (TH2F*)infile.Get("EtavsPtTauMedIso");
  TH2F* EtavsPtTauDMFind_ = (TH2F*)infile.Get("EtavsPtTauDMFind");
  TH1F* TauMedIsoPt_ = (TH1F*)infile.Get("TauMedIsoPt");
  TH1F* TauDMFindPt_ = (TH1F*)infile.Get("TauDMFindPt");

  TGraphAsymmErrors* FinalFakeRateDMtoMedIsoPt_ = new TGraphAsymmErrors(30);
  FinalFakeRateDMtoMedIsoPt_->Divide(TauMedIsoPt_, TauDMFindPt_);
  FinalFakeRateDMtoMedIsoPt_->SetName("FakeRateDMtoMedIsoPt");
  FinalFakeRateDMtoMedIsoPt_->SetMarkerSize(.07);
  FinalFakeRateDMtoMedIsoPt_->GetXaxis()->SetTitle("p_{T}(#tau)");
  FinalFakeRateDMtoMedIsoPt_->SetTitle("Fake Rate (# PFTau + DMFind + MedIso / # PFTau + DMFind)");
  FinalFakeRateDMtoMedIsoPt_->GetYaxis()->SetTitleOffset(1.5);
  FinalFakeRateDMtoMedIsoPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateDMtoMedIsoPt_->SetLineWidth(3);


  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPt = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtCanvas","",600,600);
  TH2F* FinalFakeRateDMtoMedIsoOnlyEtavsPt_ = (TH2F*)EtavsPtTauMedIso_->Clone();

  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Add(EtavsPtTauMedIsoWZ_, -1.0);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Add(EtavsPtTauMedIsoZZ_, -1.0);

  for (int i=1; i < FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetXaxis()->GetNbins(); i++)
  {
    for (int j=1; j < FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetYaxis()->GetNbins(); j++)
    {
      if (FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetBinContent(i,j) < 0)
        FinalFakeRateDMtoMedIsoOnlyEtavsPt_->SetBinContent(i,j, 0.0);
    }//for j
  }//for i


  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Divide(EtavsPtTauDMFind_);


  for (int i=1; i < EtavsPtTauMedIso_->GetXaxis()->GetNbins(); i++)
  {
    for (int j=1; j < EtavsPtTauMedIso_->GetYaxis()->GetNbins(); j++)
    {
      double P = EtavsPtTauMedIso_->GetBinContent(i,j);
      double N = EtavsPtTauDMFind_->GetBinContent(i,j), F = N-P;
      if (N > 0)
        FinalFakeRateDMtoMedIsoOnlyEtavsPt_->SetBinError(i,j, pow( (P*F) / (N*N*N), 0.5) );
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
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->SetTitle("Fake Rate (# PFTau + MedIso + DMFind / # PFTau + DMFind)");

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
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->SetMarkerSize(1.5);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette4 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPt_->GetListOfFunctions()->FindObject("palette");
  palette4->SetX1NDC(0.88);
  palette4->SetX2NDC(0.92);
  palette4->SetY1NDC(0.1);
  palette4->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPt, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt->Write();

  TCanvas *FinalFakeRateDMtoMedIsoOnlyPt = new TCanvas("FinalFakeRateDMtoMedIsoOnlyPtCanvas","",600,600);
  FinalFakeRateDMtoMedIsoPt_->Write();
  FinalFakeRateDMtoMedIsoOnlyPt->cd();
  FinalFakeRateDMtoMedIsoPt_->Draw();
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyPt, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyPt->Write();
  outFile->Close();

  TH2F *FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_ = (TH2F*)FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Clone();
  TH2F *FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_ = (TH2F*)FinalFakeRateDMtoMedIsoOnlyEtavsPt_->Clone();
  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPtUP = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtUPCanvas","",600,600);
  TCanvas *FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN = new TCanvas("FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWNCanvas","",600,600);

  for (int i=1; i < EtavsPtTauMedIso_->GetXaxis()->GetNbins()+1; i++)
  {
    for (int j=1; j < EtavsPtTauMedIso_->GetYaxis()->GetNbins()+1; j++)
    {
      FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->SetBinContent(i,j, FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->GetBinContent(i,j) + FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->GetBinError(i,j) );
      FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->SetBinContent(i,j, FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->GetBinContent(i,j) - FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->GetBinError(i,j) );
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
  FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->SetMarkerSize(1.5);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette5 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPtUP_->GetListOfFunctions()->FindObject("palette");
  palette5->SetX1NDC(0.88);
  palette5->SetX2NDC(0.92);
  palette5->SetY1NDC(0.1);
  palette5->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPtUP, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtUP->Write();
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
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->SetMarkerSize(1.5);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette6 = (TPaletteAxis*)FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN_->GetListOfFunctions()->FindObject("palette");
  palette6->SetX1NDC(0.88);
  palette6->SetX2NDC(0.92);
  palette6->SetY1NDC(0.1);
  palette6->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN, 4, 11);
  FinalFakeRateDMtoMedIsoOnlyEtavsPtDOWN->Write();
  outFileDOWN->Close();

  FinalFakeRateDMtoMedIsoOnlyEtavsPt->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRates/TauFakeRateDMtoMedIsoEtavsPt.png");
  FinalFakeRateDMtoMedIsoOnlyEtavsPt->cd();
  gPad->SetLogx(true);
  FinalFakeRateDMtoMedIsoOnlyEtavsPt->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRates/TauFakeRateDMtoMedIsoEtavsPtLog.png");
  FinalFakeRateDMtoMedIsoOnlyPt->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRates/TauFakeRateDMtoMedIsoPt.png");
  FinalFakeRateDMtoMedIsoOnlyPt->SetLogy(true);
  FinalFakeRateDMtoMedIsoOnlyPt->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRates/TauFakeRateDMtoMedIsoPtLog.png");

cout << "end" << endl;

}//rootMacro_BBA_combine
