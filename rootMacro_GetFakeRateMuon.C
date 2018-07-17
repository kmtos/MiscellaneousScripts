#include "tdrstyle.C"
#include "CMS_lumi.C"
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


void rootMacro_GetFakeRateMuon()
{

  setTDRStyle(true);
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);

  TFile infile ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/GetRates/FINAL_MiniAOD_SingleMu_Mu1Only_ZSKIM_FEB8.root");
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MUONFAKERATES_FINAL_MiniAOD_SingleMu_Mu1Only_ZSKIM_FEB8_NoDiBoson.root", "RECREATE");
  TFile infileWZ ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/GetRates/FINAL_MiniAOD_WZ3L1Nu_Mu1Only_ZSKIM_FEB8.root");
  TFile infileZZ ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/GetRates/FINAL_MiniAOD_ZZTo4LAmac_Mu1Only_ZSKIM_FEB8.root");
  

cout << "Files Created" << endl;

  TH2F* EtavsPtMuonIso_ = (TH2F*)infile.Get("EtavsPtMuonIso");
  TH2F* EtavsPtMuonNoIso_ = (TH2F*)infile.Get("EtavsPtMuonNoIso");

  TH1F* MuonIsoEta_ = (TH1F*)infile.Get("MuonIsoEta");
  TH1F* MuonNoIsoEta_ = (TH1F*)infile.Get("MuonNoIsoEta");

  TH1F* MuonIsoPt_ = (TH1F*)infile.Get("MuonIsoPt");
  TH1F* MuonNoIsoPt_ = (TH1F*)infile.Get("MuonNoIsoPt");


  TH2F* EtavsPtMuonIsoWZ_ = (TH2F*)infileWZ.Get("EtavsPtMuonIso");
  TH2F* EtavsPtMuonNoIsoWZ_ = (TH2F*)infileWZ.Get("EtavsPtMuonNoIso");

  TH1F* MuonIsoEtaWZ_ = (TH1F*)infileWZ.Get("MuonIsoEta");
  TH1F* MuonNoIsoEtaWZ_ = (TH1F*)infileWZ.Get("MuonNoIsoEta");

  TH1F* MuonIsoPtWZ_ = (TH1F*)infileWZ.Get("MuonIsoPt");
  TH1F* MuonNoIsoPtWZ_ = (TH1F*)infileWZ.Get("MuonNoIsoPt");

  TH2F* EtavsPtMuonIsoZZ_ = (TH2F*)infileZZ.Get("EtavsPtMuonIso");
  TH2F* EtavsPtMuonNoIsoZZ_ = (TH2F*)infileZZ.Get("EtavsPtMuonNoIso");

  TH1F* MuonIsoEtaZZ_ = (TH1F*)infileZZ.Get("MuonIsoEta");
  TH1F* MuonNoIsoEtaZZ_ = (TH1F*)infileZZ.Get("MuonNoIsoEta");

  TH1F* MuonIsoPtZZ_ = (TH1F*)infileZZ.Get("MuonIsoPt");
  TH1F* MuonNoIsoPtZZ_ = (TH1F*)infileZZ.Get("MuonNoIsoPt");

cout << "Got Canvases" << endl;

// Getting the histograms for the DM New
//  TH2F* EtavsPtMuonIso_ = (TH2F*)EtavsPtMuonIsoCanvas->GetPrimitive("EtavsPtMuonIso");
//  TH2F* EtavsPtMuonNoIso_ = (TH2F*)EtavsPtMuonNoIsoCanvas->GetPrimitive("EtavsPtMuonNoIso");
//
//  TH1F* MuonIsoEta_ = (TH1F*)MuonIsoEtaCanvas->GetPrimitive("MuonIsoEta");
//  TH1F* MuonNoIsoEta_ = (TH1F*)MuonNoIsoEtaCanvas->GetPrimitive("MuonNoIsoEta");
//  
//  TH1F* MuonIsoPt_ = (TH1F*)MuonIsoPtCanvas->GetPrimitive("MuonIsoPt");
//  TH1F* MuonNoIsoPt_ = (TH1F*)MuonNoIsoPtCanvas->GetPrimitive("MuonNoIsoPt");
//
//  TH2F* EtavsPtMuonIsoWZ_ = (TH2F*)EtavsPtMuonIsoCanvasWZ->GetPrimitive("EtavsPtMuonIso");
//  TH2F* EtavsPtMuonNoIsoWZ_ = (TH2F*)EtavsPtMuonNoIsoCanvasWZ->GetPrimitive("EtavsPtMuonNoIso");
//  
//  TH1F* MuonIsoEtaWZ_ = (TH1F*)MuonIsoEtaCanvasWZ->GetPrimitive("MuonIsoEta");
//  TH1F* MuonNoIsoEtaWZ_ = (TH1F*)MuonNoIsoEtaCanvasWZ->GetPrimitive("MuonNoIsoEta");
//
//  TH1F* MuonIsoPtWZ_ = (TH1F*)MuonIsoPtCanvasWZ->GetPrimitive("MuonIsoPt");
//  TH1F* MuonNoIsoPtWZ_ = (TH1F*)MuonNoIsoPtCanvasWZ->GetPrimitive("MuonNoIsoPt");
//
//  TH2F* EtavsPtMuonIsoZZ_ = (TH2F*)EtavsPtMuonIsoCanvasZZ->GetPrimitive("EtavsPtMuonIso");
//  TH2F* EtavsPtMuonNoIsoZZ23_ = (TH2F*)EtavsPtMuonNoIsoCanvasZZ->GetPrimitive("EtavsPtMuonNoIso");
//  
//  TH1F* MuonIsoEtaZZ_ = (TH1F*)MuonIsoEtaCanvasZZ->GetPrimitive("MuonIsoEta");
//  TH1F* MuonNoIsoEtaZZ_ = (TH1F*)MuonNoIsoEtaCanvasZZ->GetPrimitive("MuonNoIsoEta");
//
//  TH1F* MuonIsoPtZZ_ = (TH1F*)MuonIsoPtCanvasZZ->GetPrimitive("MuonIsoPt");
//  TH1F* MuonNoIsoPtZZ_ = (TH1F*)MuonNoIsoPtCanvasZZ->GetPrimitive("MuonNoIsoPt");

std::cout << "Declaring TGraph" << std::endl;

  EtavsPtMuonIso_->Add(  EtavsPtMuonIsoWZ_, -1.0);
  EtavsPtMuonNoIso_->Add(  EtavsPtMuonNoIsoWZ_, -1.0);

  MuonIsoEta_->Add(  MuonIsoEtaWZ_, -1.0);
  MuonNoIsoEta_->Add(  MuonNoIsoEtaWZ_, -1.0);

//  for (int i=1; i < MuonIsoPt_->GetXaxis()->GetNbins(); i++)
//  {
//    std::cout << "\nNum=" << MuonIsoPt_->GetBinContent(i) << "\tDen=" << MuonNoIsoPt_->GetBinContent(i) << std::endl;
//    std::cout << "\nWZ =" << MuonIsoPtWZ_->GetBinContent(i) << "\tWZ =" << MuonNoIsoPtWZ_->GetBinContent(i) << std::endl;
//    std::cout << "\nZZ =" << MuonIsoPtZZ_->GetBinContent(i) << "\tZZ =" << MuonNoIsoPtZZ_->GetBinContent(i) << std::endl;
//  }//for i
  MuonIsoPt_->Add(  MuonIsoPtWZ_, -1.0);
  MuonNoIsoPt_->Add(  MuonNoIsoPtWZ_, -1.0);

  std::cout << "AFter" << std::endl;

  EtavsPtMuonIso_->Add(  EtavsPtMuonIsoZZ_, -1.0);
  EtavsPtMuonNoIso_->Add(  EtavsPtMuonNoIsoZZ_, -1.0);

  MuonIsoEta_->Add(  MuonIsoEtaZZ_, -1.0);
  MuonNoIsoEta_->Add(  MuonNoIsoEtaZZ_, -1.0);

  MuonIsoPt_->Add(  MuonIsoPtZZ_, -1.0);
  MuonNoIsoPt_->Add(  MuonNoIsoPtZZ_, -1.0);
  for (int i=1; i < MuonIsoPt_->GetXaxis()->GetNbins(); i++)
  {
    std::cout << "\nNum=" << MuonIsoPt_->GetBinContent(i) << "\tDen=" << MuonNoIsoPt_->GetBinContent(i) << std::endl;
    std::cout << "\nWZ =" << MuonIsoPtWZ_->GetBinContent(i) << "\tWZ =" << MuonNoIsoPtWZ_->GetBinContent(i) << std::endl;
    std::cout << "\nZZ =" << MuonIsoPtZZ_->GetBinContent(i) << "\tZZ =" << MuonNoIsoPtZZ_->GetBinContent(i) << std::endl;
    if (MuonIsoPt_->GetBinContent(i) < 0)
      MuonIsoPt_->SetBinContent(i, 0.0);
    if (MuonNoIsoPt_->GetBinContent(i) < 0)
      MuonNoIsoPt_->SetBinContent(i, 0.0);
    
  }//for i
  for (int i=1; i < EtavsPtMuonNoIso_->GetXaxis()->GetNbins(); i++)
  {
    for (int j=1; j < EtavsPtMuonNoIso_->GetYaxis()->GetNbins(); j++)
    {
      if (MuonIsoPt_->GetBinContent(i,j) < 0)
        MuonIsoPt_->SetBinContent(i, j, 0.0);
      if (MuonNoIsoPt_->GetBinContent(i) < 0)
        MuonNoIsoPt_->SetBinContent(i, j, 0.0);
    }//forj
  }//for i      

  outFile->cd();
  EtavsPtMuonIso_->Write();
  EtavsPtMuonNoIso_->Write();

  MuonIsoEta_->Write();
  MuonNoIsoEta_->Write();

  MuonIsoPt_->Write();
  MuonNoIsoPt_->Write();

  EtavsPtMuonIso_->Write();
  EtavsPtMuonNoIso_->Write();

  MuonIsoEta_->Write();
  MuonNoIsoEta_->Write();

  MuonIsoPt_->Write();
  MuonNoIsoPt_->Write();


  // No Soft Mu Requirement
//  TGraphAsymmErrors* FinalFakeRateMuonPt_ = new TGraphAsymmErrors(30);
//  TGraphAsymmErrors* FinalFakeRateMuonEta_ = new TGraphAsymmErrors(30);
  TCanvas *FinalFakeRateMuonEtavsPtCanvas = new TCanvas("FinalFakeRateMuonEtavsPtCanvas","",600,600);
  TCanvas *FinalFakeRateMuonEtaCanvas = new TCanvas("FinalFakeRateMuonEtaCanvas","",600,600);
  TCanvas *FinalFakeRateMuonPtCanvas = new TCanvas("FinalFakeRateMuonPtCanvas","",600,600);

  TH2F* FinalFakeRateMuonEtavsPt_ = (TH2F*)EtavsPtMuonIso_->Clone();
  TH1F* FinalFakeRateMuonPt_ = (TH1F*)MuonIsoPt_->Clone();
  TH1F* FinalFakeRateMuonEta_ = (TH1F*)MuonIsoEta_->Clone();

  FinalFakeRateMuonEtavsPt_->Divide(EtavsPtMuonNoIso_);
  FinalFakeRateMuonEtavsPtCanvas->SetFillStyle(0);
  FinalFakeRateMuonEtavsPtCanvas->SetFillColor(0);
  FinalFakeRateMuonEtavsPt_->GetYaxis()->SetLabelOffset(0.007);
  
  for (int i=1; i <=EtavsPtMuonNoIso_->GetXaxis()->GetNbins(); i++)
  {
    for (int j=1; j <=EtavsPtMuonNoIso_->GetYaxis()->GetNbins(); j++)
    {
      double P = EtavsPtMuonIso_->GetBinContent(i,j);
      double N = EtavsPtMuonNoIso_->GetBinContent(i,j), F = N-P;
      
      if (N > 0)
        FinalFakeRateMuonEtavsPt_->SetBinError(i,j, pow( (P*F) / (N*N*N), 0.5) );
      std::cout << "FinalFakeRateMuonEtavsPt_->GetBinContent(i,j)=" << FinalFakeRateMuonEtavsPt_->GetBinContent(i,j) << std::endl;
      if (FinalFakeRateMuonEtavsPt_->GetBinContent(i,j) < 0)
        FinalFakeRateMuonEtavsPt_->SetBinContent(i,j,0);
      std::cout << "P= " << P << "\tN=" << N << "\tF=" << F << std::endl;
      std::cout << "(P*F) / (N*N*N)=" << (P*F) / (N*N*N) << "\tpow( (P*F) / (N*N*N), 0.5)=" << pow( (P*F) / (N*N*N), 0.5) << std::endl;
    }//for j
  }//fori

  for (int i=1; i < MuonIsoPt_->GetXaxis()->GetNbins(); i++)
  {
    double P = MuonIsoPt_->GetBinContent(i);
    double N = MuonNoIsoPt_->GetBinContent(i), F = N-P;
    if (N > 0)
      FinalFakeRateMuonPt_->SetBinError(i, pow( (P*F) / (N*N*N), 0.5) );
  }//for    
  
  for (int i=1; i < MuonIsoEta_->GetXaxis()->GetNbins(); i++)
  {
    double P = MuonIsoEta_->GetBinContent(i);
    double N = MuonNoIsoEta_->GetBinContent(i), F = N-P;
    if (N > 0)
      FinalFakeRateMuonEta_->SetBinError(i, pow( (P*F) / (N*N*N), 0.5) );
  }//for    
 
std::cout << "Dividing" << std::endl;
  //Divide
  FinalFakeRateMuonEta_->Divide(MuonIsoEta_, MuonNoIsoEta_ );
 std::cout << "check1" << std::endl;
  FinalFakeRateMuonPt_->Divide(MuonIsoPt_, MuonNoIsoPt_ );
std::cout << "check2" << std::endl;

  //Formatting  2D HIstograms with Soft Muon
  FinalFakeRateMuonEtavsPt_->SetName("FinalFakeRateMuonEtavsPt");
  FinalFakeRateMuonEtavsPt_->GetXaxis()->SetTitle("p_{T}(#mu_{3})");
  FinalFakeRateMuonEtavsPt_->GetYaxis()->SetTitle("|#eta|");
  FinalFakeRateMuonEtavsPt_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateMuonEtavsPt_->SetTitle("Fake Rate Muon: 81 < M(#mu_{1}#mu_{2}) < 101");

  //Formatting Pt
  FinalFakeRateMuonPtCanvas->cd();
  FinalFakeRateMuonPt_->SetName("FakeRateMuonPt");
  FinalFakeRateMuonPt_->SetMarkerSize(.07);
  FinalFakeRateMuonPt_->GetXaxis()->SetTitle("p_{T}(#mu)");
  FinalFakeRateMuonPt_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateMuonPt_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateMuonPt_->SetLineWidth(3);
  FinalFakeRateMuonPt_->SetTitle("Fake Rate Muon: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateMuonPt_->Draw();

  //Formatting Eta
  FinalFakeRateMuonEtaCanvas->cd();
  FinalFakeRateMuonEta_->SetName("FakeRateMuonEta");
  FinalFakeRateMuonEta_->SetMarkerSize(.07);
  FinalFakeRateMuonEta_->GetXaxis()->SetTitle("#eta(#mu)");
  FinalFakeRateMuonEta_->GetYaxis()->SetTitleOffset(.9);
  FinalFakeRateMuonEta_->GetYaxis()->SetRangeUser(0.0, 1.0);
  FinalFakeRateMuonEta_->SetLineWidth(3);
  FinalFakeRateMuonEta_->SetTitle("Fake Rate Muon: 81 < M(#mu_{1}#mu_{2}) < 101");
  FinalFakeRateMuonEta_->Draw();

cout << "Attributes set." << endl;  

  //Writing
  outFile->cd();

//  writeExtraText = true;
//  lumi_13TeV = "35.9 fb^{-1}";
//  CMS_lumi(  EtavsPtMuonIsoCanvas, 4, 11);
//  EtavsPtMuonIsoCanvas->Write();
//  CMS_lumi(  EtavsPtMuonNoIsoCanvas, 4, 11);
//  EtavsPtMuonNoIsoCanvas->Write();
//
//  CMS_lumi(  MuonIsoEtaCanvas, 4, 11);
//  MuonIsoEtaCanvas->Write();
//  CMS_lumi(  MuonNoIsoEtaCanvas, 4, 11);
//  MuonNoIsoEtaCanvas->Write();
//
//  CMS_lumi(  MuonIsoPtCanvas, 4, 11);
//  MuonIsoPtCanvas->Write();
//  CMS_lumi(  MuonNoIsoPtCanvas, 4, 11);
//  MuonNoIsoPtCanvas->Write();
  writeExtraText = true;
  lumi_13TeV = "35.9 fb^{-1}";

  FinalFakeRateMuonEtaCanvas->cd();
  FinalFakeRateMuonEta_->Draw();
  CMS_lumi(  FinalFakeRateMuonEtaCanvas, 4, 11);
  FinalFakeRateMuonEtaCanvas->Write();

  FinalFakeRateMuonPtCanvas->cd();
  FinalFakeRateMuonPt_->Draw();
  CMS_lumi(  FinalFakeRateMuonPtCanvas, 4, 11);
  FinalFakeRateMuonPtCanvas->Write();


  FinalFakeRateMuonEtavsPtCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  FinalFakeRateMuonEtavsPt_->SetStats(false);
  FinalFakeRateMuonEtavsPt_->SetMarkerSize(.56);
  FinalFakeRateMuonEtavsPt_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette = (TPaletteAxis*)FinalFakeRateMuonEtavsPt_->GetListOfFunctions()->FindObject("palette");
  palette->SetX1NDC(0.88);
  palette->SetX2NDC(0.92);
  palette->SetY1NDC(0.1);
  palette->SetY2NDC(0.97);
  CMS_lumi(  FinalFakeRateMuonEtavsPtCanvas, 4, 11);
  FinalFakeRateMuonEtavsPtCanvas->Write();

 
  outFile->Write();
  outFile->Close();

cout << "end" << endl;

}//rootMacro_BBA_combine
