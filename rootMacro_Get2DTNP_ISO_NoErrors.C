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


void rootMacro_Get2DTNP_ISO_NoErrors()
{
  setTDRStyle(true);
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);

  TFile f_MC("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/ZmumuOutput/TnP_Muon_Iso_MC_DY_IsoMu24.root");
  TFile f_RunBtoD("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/ZmumuOutput/TnP_Muon_Iso_RunBtoD_DY_IsoMu24.root");
  TFile f_RunEF("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/ZmumuOutput/TnP_Muon_Iso_RunEF_DY_IsoMu24.root");
  TFile f_RunGH("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/ZmumuOutput/TnP_Muon_Iso_RunGH_DY_IsoMu24.root");
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/TNP_DY_IsoMu24_ISO_EFFICIENCIES.root", "RECREATE");

//  TFile f_MC("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/JpsiOutput/TnP_Muon_Iso_MC_Jpsi_IsoMu24.root");
//  TFile f_RunBtoD("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/JpsiOutput/TnP_Muon_Iso_RunBtoD_Jpsi_IsoMu24.root");
//  TFile f_RunEF("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/JpsiOutput/TnP_Muon_Iso_RunEF_Jpsi_IsoMu24.root");
//  TFile f_RunGH("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/JpsiOutput/TnP_Muon_Iso_RunGH_Jpsi_IsoMu24.root");
//  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/TNP_Jpsi_IsoMu24_ISO_EFFICIENCIES.root", "RECREATE");

  TCanvas *C_MC = (TCanvas*)f_MC.Get("tpTree/Iso_LooseID/fit_eff_plots/abseta_pt_PLOT_Loose_pass");
  TCanvas *C_RunBtoD = (TCanvas*)f_RunBtoD.Get("tpTree/Iso_LooseID/fit_eff_plots/abseta_pt_PLOT_Loose_pass");
  TCanvas *C_RunEF = (TCanvas*)f_RunEF.Get("tpTree/Iso_LooseID/fit_eff_plots/abseta_pt_PLOT_Loose_pass");
  TCanvas *C_RunGH = (TCanvas*)f_RunGH.Get("tpTree/Iso_LooseID/fit_eff_plots/abseta_pt_PLOT_Loose_pass");

  TH2F *h_MC = (TH2F*)C_MC->GetPrimitive("abseta_pt_PLOT_Loose_pass");
  TH2F *h_RunBtoD = (TH2F*)C_RunBtoD->GetPrimitive("abseta_pt_PLOT_Loose_pass");
  TH2F *h_RunEF = (TH2F*)C_RunEF->GetPrimitive("abseta_pt_PLOT_Loose_pass");
  TH2F *h_RunGH = (TH2F*)C_RunGH->GetPrimitive("abseta_pt_PLOT_Loose_pass");
 
////////////////////////////
// Declaring Canvases
////////////////////////////
  TCanvas *EtavsPtLooseIDRunBDtoMCCanvas = new TCanvas("EtavsPtLooseIDRunBDtoMCCanvas", "", 600, 600);
  TCanvas *EtavsPtLooseIDRunEFtoMCCanvas = new TCanvas("EtavsPtLooseIDRunEFtoMCCanvas", "", 600, 600);
  TCanvas *EtavsPtLooseIDRunGHtoMCCanvas = new TCanvas("EtavsPtLooseIDRunGHtoMCCanvas", "", 600, 600);

  h_RunBtoD->Divide(h_MC);
  h_RunEF->Divide(h_MC);
  h_RunGH->Divide(h_MC);

  h_RunBtoD->SetName("EtavsPtLooseIDRunBDtoMC");
  h_RunEF->SetName("EtavsPtLooseIDRunEFtoMC");
  h_RunGH->SetName("EtavsPtLooseIDRunGHtoMC");
  h_RunBtoD->SetMarkerSize(1.5);
  h_RunEF->SetMarkerSize(1.5);
  h_RunGH->SetMarkerSize(1.5);

  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  h_RunBtoD->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette1 = (TPaletteAxis*)h_RunBtoD->GetListOfFunctions()->FindObject("palette");
  palette1->SetX1NDC(0.88);
  palette1->SetX2NDC(0.92);
  palette1->SetY1NDC(0.1);
  palette1->SetY2NDC(0.97);

  EtavsPtLooseIDRunEFtoMCCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  h_RunEF->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette4 = (TPaletteAxis*)h_RunEF->GetListOfFunctions()->FindObject("palette");
  palette4->SetX1NDC(0.88);
  palette4->SetX2NDC(0.92);
  palette4->SetY1NDC(0.1);
  palette4->SetY2NDC(0.97);

  EtavsPtLooseIDRunGHtoMCCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  h_RunGH->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette7 = (TPaletteAxis*)h_RunGH->GetListOfFunctions()->FindObject("palette");
  palette7->SetX1NDC(0.88);
  palette7->SetX2NDC(0.92);
  palette7->SetY1NDC(0.1);
  palette7->SetY2NDC(0.97);

  writeExtraText = true;
  lumi_13TeV = "35.9 fb^{-1}";

  CMS_lumi(EtavsPtLooseIDRunBDtoMCCanvas, 4, 11);
  CMS_lumi(EtavsPtLooseIDRunEFtoMCCanvas, 4, 11);
  CMS_lumi(EtavsPtLooseIDRunGHtoMCCanvas, 4, 11);

  outFile->cd();
  EtavsPtLooseIDRunBDtoMCCanvas->Write();
  EtavsPtLooseIDRunEFtoMCCanvas->Write();
  EtavsPtLooseIDRunGHtoMCCanvas->Write();
  outFile->Close();
  EtavsPtLooseIDRunBDtoMCCanvas->SaveAs(“EtavsPtLooseIDRunBDtoMC.pdf”);
  EtavsPtLooseIDRunEFtoMCCanvas->SaveAs(“EtavsPtLooseIDRunEFtoMC.pdf”);
  EtavsPtLooseIDRunGHtoMCCanvas->SaveAs(“EtavsPtLooseIDRunGHtoMC.pdf”);

}
