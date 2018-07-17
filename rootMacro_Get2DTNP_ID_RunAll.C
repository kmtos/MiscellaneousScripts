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


void rootMacro_Get2DTNP_ID_RunAll()
{
  setTDRStyle(true);
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);

  TFile f_MC("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/FinalBinSizes/TnP_Muon_ID_MC_Jpsi_Mu7p5_Track2_pt.root");
  TFile f_Data("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/FinalBinSizes/TnP_Muon_ID_RunAll_Jpsi_Mu7p5_Track2_pt.root");
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/TNP_Jpsi_Mu7p5_Track2_pt_ID_EFFICIENCIES.root", "RECREATE");

  TCanvas *C_MC = (TCanvas*)f_MC.Get("tpTree/Loose_pt_eta/fit_eff_plots/abseta_pt_PLOT");
  TCanvas *C_Data = (TCanvas*)f_Data.Get("tpTree/Loose_pt_eta/fit_eff_plots/abseta_pt_PLOT");

  TH2F *h_MC = (TH2F*)C_MC->GetPrimitive("abseta_pt_PLOT");
  TH2F *h_Data = (TH2F*)C_Data->GetPrimitive("abseta_pt_PLOT");
 
////////////////////////////
// Declaring Canvases
////////////////////////////
  TCanvas *EtavsPtLooseIDDatatoMCCanvas = new TCanvas("EtavsPtLooseIDDatatoMCCanvas", "", 600, 600);
  h_Data->Divide(h_MC);
  h_Data->SetName("EtavsPtLooseIDDatatoMC");
  h_Data->SetMarkerSize(1.5);

  EtavsPtLooseIDDatatoMCCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  h_Data->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette7 = (TPaletteAxis*)h_Data->GetListOfFunctions()->FindObject("palette");
  palette7->SetX1NDC(0.88);
  palette7->SetX2NDC(0.92);
  palette7->SetY1NDC(0.1);
  palette7->SetY2NDC(0.97);

  writeExtraText = true;
  lumi_13TeV = "35.9 fb^{-1}";

  CMS_lumi(EtavsPtLooseIDDatatoMCCanvas, 4, 11);

  outFile->cd();
  EtavsPtLooseIDDatatoMCCanvas->Write();
  outFile->Close();
  EtavsPtLooseIDDatatoMCCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/TagAndProbe/EtavsPtLooseIDDatatoMC_Jpsi_Mu7p5_Track2.pdf");
}
