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

void rootMacro_Get2DTNP_AllTnP()
{
  setTDRStyle(true);
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TNP/TNP_LowMuPt_EFFICIENCIES.root", "RECREATE");

  //DY ISO
  TFile f_MC_DY_ISO("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TNP/TnP_Muon_Iso_MC_DY_IsoMu24_pt26.root");
  TFile f_Data_DY_ISO("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TNP/TnP_Muon_Iso_RunAll_DY_IsoMu24_pt26.root");
  double errMC_DY_ISO[3][4], errData_DY_ISO[3][4];
  errMC_DY_ISO[0][0] = .02;
  errMC_DY_ISO[0][1] = .01;
  errMC_DY_ISO[0][2] = .008;
  errMC_DY_ISO[0][3] = .03;
  errMC_DY_ISO[1][0] = .008;
  errMC_DY_ISO[1][1] = .008;
  errMC_DY_ISO[1][2] = .003;
  errMC_DY_ISO[1][3] = .04;
  errMC_DY_ISO[2][0] = .002;
  errMC_DY_ISO[2][1] = .003;
  errMC_DY_ISO[2][2] = .001;
  errMC_DY_ISO[2][3] = .003;

  errData_DY_ISO[0][0] = .01;
  errData_DY_ISO[0][1] = .01;
  errData_DY_ISO[0][2] = .004;
  errData_DY_ISO[0][3] = .006;
  errData_DY_ISO[1][0] = .004;
  errData_DY_ISO[1][1] = .003;
  errData_DY_ISO[1][2] = .002;
  errData_DY_ISO[1][3] = .003;
  errData_DY_ISO[2][0] = .002;
  errData_DY_ISO[2][1] = .002;
  errData_DY_ISO[2][2] = .0008;
  errData_DY_ISO[2][3] = .0001;

  TCanvas *C_MC_DY_ISO = (TCanvas*)f_MC_DY_ISO.Get("tpTree/Iso_LooseID/fit_eff_plots/abseta_pt_PLOT_Loose_pass");
  TCanvas *C_Data_DY_ISO = (TCanvas*)f_Data_DY_ISO.Get("tpTree/Iso_LooseID/fit_eff_plots/abseta_pt_PLOT_Loose_pass");

  TH2F *h_MC_DY_ISO = (TH2F*)C_MC_DY_ISO->GetPrimitive("abseta_pt_PLOT_Loose_pass");
  TH2F *h_Data_DY_ISO = (TH2F*)C_Data_DY_ISO->GetPrimitive("abseta_pt_PLOT_Loose_pass");

  for (int i=1; i <=4; i++)
  {
    for (int j=1; j<=3; j++)
    {
      h_MC_DY_ISO->SetBinError(i, j, errMC_DY_ISO[j-1][i-1] );
      h_Data_DY_ISO->SetBinError(i, j, errData_DY_ISO[j-1][i-1] );
    }//for
  }//for i


  // DY ID  
  TFile f_MC_DY_ID("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TNP/TnP_Muon_ID_MC_DY_IsoMu24_pt26.root");
  TFile f_Data_DY_ID("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TNP/TnP_Muon_ID_RunAll_DY_IsoMu24_pt26.root");
  double errMC_DY_ID[3][4], errData_DY_ID[3][4];
  errMC_DY_ID[0][0] = .03;
  errMC_DY_ID[0][1] = .03;
  errMC_DY_ID[0][2] = .02;
  errMC_DY_ID[0][3] = .2;
  errMC_DY_ID[1][0] = .004;
  errMC_DY_ID[1][1] = .004;
  errMC_DY_ID[1][2] = .0006;
  errMC_DY_ID[1][3] = .008;
  errMC_DY_ID[2][0] = .001;
  errMC_DY_ID[2][1] = .001;
  errMC_DY_ID[2][2] = .0007;
  errMC_DY_ID[2][3] = .002;

  errData_DY_ID[0][0] = .02;
  errData_DY_ID[0][1] = .05;
  errData_DY_ID[0][2] = .008;
  errData_DY_ID[0][3] = .02;
  errData_DY_ID[1][0] = .008;
  errData_DY_ID[1][1] = .01;
  errData_DY_ID[1][2] = .002;
  errData_DY_ID[1][3] = .002;
  errData_DY_ID[2][0] = .004;
  errData_DY_ID[2][1] = .1;
  errData_DY_ID[2][2] = .001;
  errData_DY_ID[2][3] = .004;
  
  TCanvas *C_MC_DY_ID = (TCanvas*)f_MC_DY_ID.Get("tpTree/Loose_pt_eta/fit_eff_plots/abseta_pt_PLOT");
  TCanvas *C_Data_DY_ID = (TCanvas*)f_Data_DY_ID.Get("tpTree/Loose_pt_eta/fit_eff_plots/abseta_pt_PLOT");

  TH2F *h_MC_DY_ID = (TH2F*)C_MC_DY_ID->GetPrimitive("abseta_pt_PLOT");
  TH2F *h_Data_DY_ID = (TH2F*)C_Data_DY_ID->GetPrimitive("abseta_pt_PLOT");

  for (int i=1; i <=4; i++)
  {
    for (int j=1; j<=3; j++)
    { 
      h_MC_DY_ID->SetBinError(i, j, errMC_DY_ID[j-1][i-1] );
      h_Data_DY_ID->SetBinError(i, j, errData_DY_ID[j-1][i-1] );
    }//for
  }//for i

  // Jpsi ID
  TFile f_MC_Jpsi_ID("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TNP/TnP_Muon_ID_MC_Jpsi_tag_Mu7p5_Track2_tagPtgt9p0.root");
  TFile f_Data_Jpsi_ID("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TNP/TnP_Muon_ID_RunAll_Jpsi_tag_Mu7p5_Track2_tagPtgt9p0.root");
  double errMC_Jpsi_ID[3][4], errData_Jpsi_ID[3][4];
  errMC_Jpsi_ID[0][0] = .0006;
  errMC_Jpsi_ID[0][1] = .001;
  errMC_Jpsi_ID[0][2] = .0003;
  errMC_Jpsi_ID[0][3] = .0005;
  errMC_Jpsi_ID[1][0] = .0008;
  errMC_Jpsi_ID[1][1] = .002;
  errMC_Jpsi_ID[1][2] = .001;
  errMC_Jpsi_ID[1][3] = .002;
  errMC_Jpsi_ID[2][0] = .0009;
  errMC_Jpsi_ID[2][1] = .002;
  errMC_Jpsi_ID[2][2] = .001;
  errMC_Jpsi_ID[2][3] = .002;
  
  errData_Jpsi_ID[0][0] = .0007;
  errData_Jpsi_ID[0][1] = .001;
  errData_Jpsi_ID[0][2] = .0009;
  errData_Jpsi_ID[0][3] = .004;
  errData_Jpsi_ID[1][0] = .002;
  errData_Jpsi_ID[1][1] = .004;
  errData_Jpsi_ID[1][2] = .003;
  errData_Jpsi_ID[1][3] = .01;
  errData_Jpsi_ID[2][0] = .003;
  errData_Jpsi_ID[2][1] = .007;
  errData_Jpsi_ID[2][2] = .006;
  errData_Jpsi_ID[2][3] = .02;

  TCanvas *C_MC_Jpsi_ID = (TCanvas*)f_MC_Jpsi_ID.Get("tpTree/Loose_pt_eta/fit_eff_plots/abseta_pt_PLOT");
  TCanvas *C_Data_Jpsi_ID = (TCanvas*)f_Data_Jpsi_ID.Get("tpTree/Loose_pt_eta/fit_eff_plots/abseta_pt_PLOT");

  TH2F *h_MC_Jpsi_ID = (TH2F*)C_MC_Jpsi_ID->GetPrimitive("abseta_pt_PLOT");
  TH2F *h_Data_Jpsi_ID = (TH2F*)C_Data_Jpsi_ID->GetPrimitive("abseta_pt_PLOT");

  for (int i=1; i <=4; i++)
  {
    for (int j=1; j<=3; j++)
    { 
      cout << "(" << i << "," << j << ")= " << errMC_Jpsi_ID[j-1][i-1] << "  bin Val=" << h_MC_Jpsi_ID->GetBinContent(i, j) << std::endl;
      h_MC_Jpsi_ID->SetBinError(i, j, errMC_Jpsi_ID[j-1][i-1] );
      h_Data_Jpsi_ID->SetBinError(i, j, errData_Jpsi_ID[j-1][i-1] );
    }//for
  }//for i

////////////////////////////
// Declaring Canvases
////////////////////////////
  TCanvas *EtavsPtLooseISODatatoMCCanvas = new TCanvas("EtavsPtLooseISODatatoMCCanvas", "", 600, 600);
  TCanvas *EtavsPtLooseIDDatatoMCCanvas = new TCanvas("EtavsPtLooseIDDatatoMCCanvas", "", 600, 600);
  TCanvas *EtavsPtLooseIDDatatoMCCanvas_DY = new TCanvas("EtavsPtLooseIDDatatoMCCanvas_DY", "", 600, 600);
  TCanvas *EtavsPtLooseIDDatatoMCCanvas_Jpsi = new TCanvas("EtavsPtLooseIDDatatoMCCanvas_Jpsi", "", 600, 600);
  TH2F *h_ID_Final = (TH2F*)h_MC_Jpsi_ID->Clone(); 
 
  outFile->cd();
  h_MC_Jpsi_ID->Write();
  h_Data_Jpsi_ID->Write();
  h_MC_DY_ID->Write();
  h_Data_DY_ID->Write();
  h_MC_DY_ISO->Write();
  h_Data_DY_ISO->Write();
  
  h_Data_DY_ISO->Divide(h_MC_DY_ISO );
  h_Data_DY_ID->Divide(h_MC_DY_ID );
  h_Data_Jpsi_ID->Divide(h_MC_Jpsi_ID );

  for (int i=1; i <=4; i++)
  {
    for (int j=1; j<=3; j++)
    {
      h_Data_DY_ISO->SetBinError( i,j, PropogateErrors(h_MC_DY_ISO->GetBinContent(i,j), h_Data_DY_ISO->GetBinContent(i,j), errMC_DY_ISO[j-1][i-1], errData_DY_ISO[j-1][i-1]) );
      h_Data_DY_ID->SetBinError(  i,j, PropogateErrors(h_MC_DY_ID->GetBinContent(i,j), h_Data_DY_ID->GetBinContent(i,j), errMC_DY_ID[j-1][i-1], errData_DY_ID[j-1][i-1]) );
      h_Data_Jpsi_ID->SetBinError(i,j, PropogateErrors(h_MC_Jpsi_ID->GetBinContent(i,j), h_Data_Jpsi_ID->GetBinContent(i,j), errMC_Jpsi_ID[j-1][i-1], errData_Jpsi_ID[j-1][i-1]) );

      std::cout << "DY=" << h_Data_DY_ID->GetBinContent(i,j) << "\tJpsi=" << h_Data_Jpsi_ID->GetBinContent(i,j) << std::endl;
    }//for
  }//for i

  h_Data_DY_ISO->SetName("hist_EtavsPtLooseISO_DatatoMC");
  h_Data_DY_ID->SetName("hist_EtavsPtLooseID_DatatoMC_DY");
  h_Data_Jpsi_ID->SetName("hist_EtavsPtLooseID_DatatoMC_Jpsi");
  h_ID_Final->SetName("hist_EtavsPtLooseID_DatatoMC");
  
  h_Data_DY_ISO->SetMarkerSize(1.5);
  h_Data_DY_ID->SetMarkerSize(1.5);
  h_Data_Jpsi_ID->SetMarkerSize(1.5);
  h_ID_Final->SetMarkerSize(1.5);

  for (int i=1; i<=4; i++)
  {
    for (int j=1; j<=3; j++)
    {
      if (j < 3)
      {
        h_ID_Final->SetBinContent(i,j, h_Data_Jpsi_ID->GetBinContent(i,j) );
        h_ID_Final->SetBinError(i,j, h_Data_Jpsi_ID->GetBinError(i,j) );
      }//if
      else
      {
        h_ID_Final->SetBinContent(i,j, h_Data_DY_ID->GetBinContent(i,j) );
        h_ID_Final->SetBinError(i,j, h_Data_DY_ID->GetBinError(i,j) );
      }//else
    }//for
  }//for i

  EtavsPtLooseISODatatoMCCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  h_Data_DY_ISO->GetZaxis()->SetRangeUser(0.9, 1.1);
  h_Data_DY_ISO->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette1 = (TPaletteAxis*)h_Data_DY_ISO->GetListOfFunctions()->FindObject("palette");
  palette1->SetX1NDC(0.88);
  palette1->SetX2NDC(0.92);
  palette1->SetY1NDC(0.1);
  palette1->SetY2NDC(0.97);
  

  EtavsPtLooseIDDatatoMCCanvas_DY->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  h_Data_DY_ID->GetZaxis()->SetRangeUser(0.9, 1.1);
  h_Data_DY_ID->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette2 = (TPaletteAxis*)h_Data_DY_ID->GetListOfFunctions()->FindObject("palette");
  palette2->SetX1NDC(0.88);
  palette2->SetX2NDC(0.92);
  palette2->SetY1NDC(0.1);
  palette2->SetY2NDC(0.97);
  
  EtavsPtLooseIDDatatoMCCanvas_Jpsi->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  h_Data_Jpsi_ID->GetZaxis()->SetRangeUser(0.9, 1.1);
  h_Data_Jpsi_ID->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette3 = (TPaletteAxis*)h_Data_Jpsi_ID->GetListOfFunctions()->FindObject("palette");
  palette3->SetX1NDC(0.88);
  palette3->SetX2NDC(0.92);
  palette3->SetY1NDC(0.1);
  palette3->SetY2NDC(0.97);
  
  EtavsPtLooseIDDatatoMCCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  h_ID_Final->GetZaxis()->SetRangeUser(0.9, 1.1);
  h_ID_Final->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette4 = (TPaletteAxis*)h_ID_Final->FindObject("palette");
  palette4->SetX1NDC(0.88);
  palette4->SetX2NDC(0.92);
  palette4->SetY1NDC(0.1);
  palette4->SetY2NDC(0.97);

  writeExtraText = true;
  lumi_13TeV = "35.9 fb^{-1}";

  CMS_lumi(EtavsPtLooseISODatatoMCCanvas, 4, 11);
  CMS_lumi(EtavsPtLooseIDDatatoMCCanvas_DY, 4, 11);
  CMS_lumi(EtavsPtLooseIDDatatoMCCanvas_Jpsi, 4, 11);
  CMS_lumi(EtavsPtLooseIDDatatoMCCanvas, 4, 11);

  h_Data_DY_ISO->Write();
  h_Data_DY_ID->Write();
  h_Data_Jpsi_ID->Write();
  h_ID_Final->Write();
  EtavsPtLooseISODatatoMCCanvas->Write();
  EtavsPtLooseIDDatatoMCCanvas_DY->Write();
  EtavsPtLooseIDDatatoMCCanvas_Jpsi->Write();
  EtavsPtLooseIDDatatoMCCanvas->Write();
  outFile->Close();
  EtavsPtLooseISODatatoMCCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/TagAndProbe/EtavsPtLooseISODatatoMC_Final.pdf");
  EtavsPtLooseIDDatatoMCCanvas_DY->SaveAs("/home/kyletos/Desktop/NewPlots/TagAndProbe/EtavsPtLooseIDDatatoMC_DY.pdf");
  EtavsPtLooseIDDatatoMCCanvas_Jpsi->SaveAs("/home/kyletos/Desktop/NewPlots/TagAndProbe/EtavsPtLooseIDDatatoMC_Jpsi.pdf");
  EtavsPtLooseIDDatatoMCCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/TagAndProbe/EtavsPtLooseIDDatatoMC_Final.pdf");

  TH2F *h_ISO_UP  = (TH2F*)h_Data_DY_ISO->Clone();
  TH2F *h_ISO_DOWN  = (TH2F*)h_Data_DY_ISO->Clone();

  TH2F *h_DY_ID_DOWN = (TH2F*)h_Data_DY_ID->Clone();
  TH2F *h_Jpsi_ID_DOWN = (TH2F*)h_Data_Jpsi_ID->Clone();
  TH2F *h_ID_DOWN = (TH2F*)h_ID_Final->Clone();

  TH2F *h_DY_ID_UP = (TH2F*)h_Data_DY_ID->Clone();
  TH2F *h_Jpsi_ID_UP = (TH2F*)h_Data_Jpsi_ID->Clone();
  TH2F *h_ID_UP = (TH2F*)h_ID_Final->Clone();
 
  for (int i=1; i <=4; i++)
  { 
    for (int j=1; j<=3; j++)
    {
      h_ID_UP->SetBinContent(i,j,      h_ID_UP->GetBinContent(i,j)      + h_ID_UP->GetBinError(i,j) );  
      h_ISO_UP->SetBinContent(i,j,     h_ISO_UP->GetBinContent(i,j)     + h_ISO_UP->GetBinError(i,j) );
      h_DY_ID_UP->SetBinContent(i,j,   h_DY_ID_UP->GetBinContent(i,j)   + h_DY_ID_UP->GetBinError(i,j) );
      h_Jpsi_ID_UP->SetBinContent(i,j, h_Jpsi_ID_UP->GetBinContent(i,j) + h_Jpsi_ID_UP->GetBinError(i,j) );
 
      h_ID_DOWN->SetBinContent(i,j,      h_ID_DOWN->GetBinContent(i,j)      - h_ID_DOWN->GetBinError(i,j) );
      h_ISO_DOWN->SetBinContent(i,j,     h_ISO_DOWN->GetBinContent(i,j)     - h_ISO_DOWN->GetBinError(i,j) );
      h_DY_ID_DOWN->SetBinContent(i,j,   h_DY_ID_DOWN->GetBinContent(i,j)   - h_DY_ID_DOWN->GetBinError(i,j) );
      h_Jpsi_ID_DOWN->SetBinContent(i,j, h_Jpsi_ID_DOWN->GetBinContent(i,j) - h_Jpsi_ID_DOWN->GetBinError(i,j) );
    }//for j
  }//for i  

  TFile *outFile_IDUP    = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TNP/TNP_LowMuPt_EFFICIENCIES_IDUP.root", "RECREATE");
  TFile *outFile_IDDOWN  = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TNP/TNP_LowMuPt_EFFICIENCIES_IDDOWN.root", "RECREATE");
  TFile *outFile_ISOUP   = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TNP/TNP_LowMuPt_EFFICIENCIES_ISOUP.root", "RECREATE");
  TFile *outFile_ISODOWN = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TNP/TNP_LowMuPt_EFFICIENCIES_ISODOWN.root", "RECREATE"); 

  outFile_ISOUP->cd();
  h_ISO_UP->Write();
  h_Data_DY_ID->Write();
  h_Data_Jpsi_ID->Write();
  h_ID_Final->Write();
  outFile_ISOUP->Close();

  outFile_ISODOWN->cd();
  h_ISO_DOWN->Write();
  h_Data_DY_ID->Write();
  h_Data_Jpsi_ID->Write();
  h_ID_Final->Write();
  outFile_ISODOWN->Close();

  outFile_IDUP->cd();
  h_Data_DY_ISO->Write();
  h_ID_UP->Write();
  h_DY_ID_UP->Write();
  h_Jpsi_ID_UP->Write();
  outFile_IDUP->Close();

  outFile_IDDOWN->cd();
  h_Data_DY_ISO->Write();
  h_ID_DOWN->Write();
  h_DY_ID_DOWN->Write();
  h_Jpsi_ID_DOWN->Write();
  outFile_IDDOWN->Close();


}//main


double PropogateErrors(double val1, double val2, double err1, double err2)
{
  return pow( err1*err1/val1/val1 + err2*err2/val2/val2, 0.5);
}//PropogateErrors



