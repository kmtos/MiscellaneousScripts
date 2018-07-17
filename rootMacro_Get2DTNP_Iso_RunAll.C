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

double PropogateErrors(double val1, double val2, double err1, double err2);

void rootMacro_Get2DTNP_Iso_RunAll()
{
  setTDRStyle(true);
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);

  double errMC[3][4], errData[3][4];

  // Run BD Set Values
  errMC[0][0] = .02;
  errMC[0][1] = .01;
  errMC[0][2] = .003;
  errMC[0][3] = .008;
  errMC[1][0] = .005;
  errMC[1][1] = .006;
  errMC[1][2] = .002;
  errMC[1][3] = .004;
  errMC[2][0] = .002;
  errMC[2][1] = .003;
  errMC[2][2] = .001;
  errMC[2][3] = .002;

  errData[0][0] = .01;
  errData[0][1] = .01;
  errData[0][2] = .004;
  errData[0][3] = .006;
  errData[1][0] = .004;
  errData[1][1] = .004;
  errData[1][2] = .002;
  errData[1][3] = .002;
  errData[2][0] = .002;
  errData[2][1] = .002;
  errData[2][2] = .0008;
  errData[2][3] = .001;

  TFile f_MC("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/FinalBinSizes/TnP_Muon_Iso_MC_DY_IsoMu24_pt.root");
  TFile f_Data("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/FinalBinSizes/TnP_Muon_Iso_RunAll_DY_IsoMu24_pt.root");
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TnP/TNP_DY_IsoMu24_pt_Iso_EFFICIENCIES.root", "RECREATE");

  TCanvas *C_MC = (TCanvas*)f_MC.Get("tpTree/Iso_LooseID/fit_eff_plots/abseta_pt_PLOT_Loose_pass");
  TCanvas *C_Data = (TCanvas*)f_Data.Get("tpTree/Iso_LooseID/fit_eff_plots/abseta_pt_PLOT_Loose_pass");

  TH2F *h_MC = (TH2F*)C_MC->GetPrimitive("abseta_pt_PLOT_Loose_pass");
  TH2F *h_Data = (TH2F*)C_Data->GetPrimitive("abseta_pt_PLOT_Loose_pass");

 
 
////////////////////////////
// Declaring Canvases
////////////////////////////
  TCanvas *EtavsPtLooseIsoDatatoMCCanvas = new TCanvas("EtavsPtLooseIsoDatatoMCCanvas", "", 600, 600);
  h_Data->Divide(h_MC);
  for (int i=0; i <=2; i++)
  {
    for (int j=0; j<=3; j++)
      h_Data->SetBinError(i,j, PropogateErrors(h_MC->GetBinContent(i,j), h_Data->GetBinContent(i,j), errMC[i][j], errData[i][j]) );
  }//for i
  h_Data->SetName("EtavsPtLooseIsoDatatoMC");
  h_Data->SetMarkerSize(1.5);

  EtavsPtLooseIsoDatatoMCCanvas->cd();
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

  CMS_lumi(EtavsPtLooseIsoDatatoMCCanvas, 4, 11);

  outFile->cd();
  EtavsPtLooseIsoDatatoMCCanvas->Write();
  outFile->Close();
  EtavsPtLooseIsoDatatoMCCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/TagAndProbe/EtavsPtLooseIsoDatatoMC_DY.pdf");
}


double PropogateErrors(double val1, double val2, double err1, double err2)
{
  return pow( err1*err1/val1/val1 + err2*err2/val2/val2, 0.5);
}//PropogateErrors



