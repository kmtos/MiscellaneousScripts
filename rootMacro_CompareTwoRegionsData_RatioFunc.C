#include <math.h>
#include <string.h>
#include "TChain.h"
#include "TFile.h"
#include "TH1.h"
#include "TKey.h"
#include "Riostream.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TGraphAsymmErrors.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "iostream"
#include "fstream"
#include "TMath.h"
#include "tdrstyle.C"
#include "CMS_lumi.C"

void GetRatioPlot(TFile *outFile, TH1F *Obs, TH1F *Est, TH1F *EstUP, TH1F *EstDOWN, int rebin, string canvName, string xTitle);

void rootMacro_CompareTwoRegionsData_RatioFunc()
{
  setTDRStyle(true);
  gStyle->SetPalette(1);


  //Old DMs
  TFile infileEstimateFromD("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_SingleMu_AntiMedIsoMu2_TauDMAntiMedIso_AUG2_CFromD.root");
  TFile infileEstimateFromDUP("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_SingleMu_AntiMedIsoMu2_TauDMAntiMedIso_AUG2_TauFakeRateUP.root");
  TFile infileEstimateFromDDOWN("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_SingleMu_AntiMedIsoMu2_TauDMAntiMedIso_AUG2_TauFakeRateDOWN.root");
  TFile infileRegionItself("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_SingleMu_AntiMedIsoMu2_TauDMMedIso_AUG2_CItself.root");

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimateData_DatatoData_CFromD_AUG2.root", "RECREATE");

cout << "Files Created" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Canvases
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ////////////////
  // EstimateFromD
  ////////////////
  TH1F *InvMassTauMuMu1EstimateFromD_ = (TH1F*)infileEstimateFromD.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2EstimateFromD_ = (TH1F*)infileEstimateFromD.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("PtMu2FakeWeight");
  TH1F *PtMu3FakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("PtMu3FakeWeight");
  TH1F *EtaFakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("EtaFakeWeight");
  TH1F *DRFakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("DRFakeWeight");
  TH1F *DiMuInvMassFakeWeightZoomEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("DiMuInvMassFakeWeightZoom");
  TH1F *TauVisMassEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("TauVisMass");
  TH1F *TauVisMassZoomEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("TauVisMassZoom");

  ////////////////
  // RegionItself
  ////////////////
  TH1F *InvMassTauMuMu1RegionItself_ = (TH1F*)infileRegionItself.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2RegionItself_ = (TH1F*)infileRegionItself.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("PtMu2FakeWeight");
  TH1F *PtMu3FakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("PtMu3FakeWeight");
  TH1F *EtaFakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("EtaFakeWeight");
  TH1F *DRFakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("DRFakeWeight");
  TH1F *DiMuInvMassFakeWeightZoomRegionItself_ = (TH1F*)infileRegionItself.Get("DiMuInvMassFakeWeightZoom");
  TH1F *TauVisMassRegionItself_ = (TH1F*)infileRegionItself.Get("TauVisMass");
  TH1F *TauVisMassZoomRegionItself_ = (TH1F*)infileRegionItself.Get("TauVisMassZoom");

  ////////////////
  // EstimateFromDUP
  ////////////////
  TH1F *InvMassTauMuMu1EstimateFromDUP_ = (TH1F*)infileEstimateFromDUP.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2EstimateFromDUP_ = (TH1F*)infileEstimateFromDUP.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightEstimateFromDUP_ = (TH1F*)infileEstimateFromDUP.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightEstimateFromDUP_ = (TH1F*)infileEstimateFromDUP.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightEstimateFromDUP_ = (TH1F*)infileEstimateFromDUP.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightEstimateFromDUP_ = (TH1F*)infileEstimateFromDUP.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightEstimateFromDUP_ = (TH1F*)infileEstimateFromDUP.Get("PtMu2FakeWeight");
  TH1F *PtMu3FakeWeightEstimateFromDUP_ = (TH1F*)infileEstimateFromDUP.Get("PtMu3FakeWeight");
  TH1F *EtaFakeWeightEstimateFromDUP_ = (TH1F*)infileEstimateFromDUP.Get("EtaFakeWeight");
  TH1F *DRFakeWeightEstimateFromDUP_ = (TH1F*)infileEstimateFromDUP.Get("DRFakeWeight");
  TH1F *DiMuInvMassFakeWeightZoomEstimateFromDUP_ = (TH1F*)infileEstimateFromDUP.Get("DiMuInvMassFakeWeightZoom");
  TH1F *TauVisMassEstimateFromDUP_ = (TH1F*)infileEstimateFromDUP.Get("TauVisMass");
  TH1F *TauVisMassZoomEstimateFromDUP_ = (TH1F*)infileEstimateFromDUP.Get("TauVisMassZoom");

  ////////////////
  // EstimateFromDDOWN
  ////////////////
  TH1F *InvMassTauMuMu1EstimateFromDDOWN_ = (TH1F*)infileEstimateFromDDOWN.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2EstimateFromDDOWN_ = (TH1F*)infileEstimateFromDDOWN.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightEstimateFromDDOWN_ = (TH1F*)infileEstimateFromDDOWN.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightEstimateFromDDOWN_ = (TH1F*)infileEstimateFromDDOWN.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightEstimateFromDDOWN_ = (TH1F*)infileEstimateFromDDOWN.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightEstimateFromDDOWN_ = (TH1F*)infileEstimateFromDDOWN.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightEstimateFromDDOWN_ = (TH1F*)infileEstimateFromDDOWN.Get("PtMu2FakeWeight");
  TH1F *PtMu3FakeWeightEstimateFromDDOWN_ = (TH1F*)infileEstimateFromDDOWN.Get("PtMu3FakeWeight");
  TH1F *EtaFakeWeightEstimateFromDDOWN_ = (TH1F*)infileEstimateFromDDOWN.Get("EtaFakeWeight");
  TH1F *DRFakeWeightEstimateFromDDOWN_ = (TH1F*)infileEstimateFromDDOWN.Get("DRFakeWeight");
  TH1F *DiMuInvMassFakeWeightZoomEstimateFromDDOWN_ = (TH1F*)infileEstimateFromDDOWN.Get("DiMuInvMassFakeWeightZoom");
  TH1F *TauVisMassEstimateFromDDOWN_ = (TH1F*)infileEstimateFromDDOWN.Get("TauVisMass");
  TH1F *TauVisMassZoomEstimateFromDDOWN_ = (TH1F*)infileEstimateFromDDOWN.Get("TauVisMassZoom");
cout << "Got Histograms from Canvases" << endl;
  outFile->cd();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the output plots
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GetRatioPlot( outFile, InvMassTauMuMu1RegionItself_, InvMassTauMuMu1EstimateFromD_, InvMassTauMuMu1EstimateFromDUP_, InvMassTauMuMu1EstimateFromDDOWN_, 1, 
//               "InvMassTauMuMu1RegionItselfCanvas", "M(#tau_{#mu} #mu_{1})" );
// GetRatioPlot( outFile, InvMassTauMuMu2RegionItself_, InvMassTauMuMu2EstimateFromD_, InvMassTauMuMu2EstimateFromDUP_, InvMassTauMuMu2EstimateFromDDOWN_, 1, 
//               "InvMassTauMuMu2RegionItselfCanvas", "M(#tau_{#mu} #mu_{2})" );
// GetRatioPlot( outFile, DiMuInvMassFakeWeightRegionItself_, DiMuInvMassFakeWeightEstimateFromD_, DiMuInvMassFakeWeightEstimateFromDUP_, DiMuInvMassFakeWeightEstimateFromDDOWN_, 1, 
//               "DiMuInvMassFakeWeightRegionItselfCanvas",   "M(#mu_{2} #mu_{2})"  );
//std::cout << "check 3"  << std::endl;
 GetRatioPlot( outFile, DiMuDiTauInvMassFakeWeightRegionItself_, DiMuDiTauInvMassFakeWeightEstimateFromD_, DiMuDiTauInvMassFakeWeightEstimateFromDUP_, DiMuDiTauInvMassFakeWeightEstimateFromDDOWN_, 3,                "DiMuDiTauInvMassFakeWeightRegionItselfCanvas", "M(#mu_{1}#mu_{2}#tau_{H}#tau_{#mu})" );
// GetRatioPlot( outFile, DiTauInvMassFakeWeightRegionItself_, DiTauInvMassFakeWeightEstimateFromD_, DiTauInvMassFakeWeightEstimateFromDUP_, DiTauInvMassFakeWeightEstimateFromDDOWN_, 3, 
//               "DiTauInvMassFakeWeightRegionItselfCanvas", "M(#tau_{H}#tau_{#mu})" );
//std::cout << "check 5"  << std::endl;
// GetRatioPlot( outFile, PtMu1FakeWeightRegionItself_, PtMu1FakeWeightEstimateFromD_, PtMu1FakeWeightEstimateFromDUP_, PtMu1FakeWeightEstimateFromDDOWN_, 1, 
//               "PtMu1FakeWeightRegionItselfCanvas", "p_{T}(#mu_{1}");
//std::cout << "check 6"  << std::endl;
// GetRatioPlot( outFile, PtMu2FakeWeightRegionItself_, PtMu2FakeWeightEstimateFromD_, PtMu2FakeWeightEstimateFromDUP_, PtMu2FakeWeightEstimateFromDDOWN_, 1,
//               " PtMu2FakeWeightRegionItselfCanvas", "p_{T}(#mu_{2}");
//std::cout << "check 7"  << std::endl;
// GetRatioPlot( outFile, PtMu3FakeWeightRegionItself_, PtMu3FakeWeightEstimateFromD_, PtMu3FakeWeightEstimateFromDUP_, PtMu3FakeWeightEstimateFromDDOWN_, 1,
//               "PtMu3FakeWeightRegionItselfCanvas", "p_{T}(#tau_{#mu}");
//std::cout << "check 8"  << std::endl;
// GetRatioPlot( outFile, EtaFakeWeightRegionItself_, EtaFakeWeightEstimateFromD_, EtaFakeWeightEstimateFromDUP_, EtaFakeWeightEstimateFromDDOWN_, 1,
//               "EtaFakeWeightRegionItselfCanvas", "#eta(#mu_{1})");
//std::cout << "check 9"  << std::endl;
// GetRatioPlot( outFile, DRFakeWeightRegionItself_, DRFakeWeightEstimateFromD_, DRFakeWeightEstimateFromDUP_, DRFakeWeightEstimateFromDDOWN_, 1,
//               "DRFakeWeightRegionItselfCanvas", "#DeltaR(#mu_{1}#mu_{2}");
//std::cout << "check 10"  << std::endl;
// GetRatioPlot( outFile, DiMuInvMassFakeWeightZoomRegionItself, DiMuInvMassFakeWeightZoomEstimateFromD, DiMuInvMassFakeWeightZoomEstimateFromDUP, DiMuInvMassFakeWeightZoomEstimateFromDDOWN, 10, 
//               "DiMuInvMassFakeWeightZoomRegionItselfCanvas",  "M(#mu_{2} #mu_{2})"  );
//std::cout << "check 11"  << std::endl;
// GetRatioPlot( outFile, TauVisMassRegionItself_, TauVisMassEstimateFromD_, TauVisMassEstimateFromDUP_, TauVisMassEstimateFromDDOWN_, 1,
//               "TauVisMassRegionItselfCanvas", "M(#tau_{H}#tau_{#mu})" );
//std::cout << "check 12"  << std::endl;
// GetRatioPlot( outFile, TauVisMassZoomRegionItself_, TauVisMassZoomEstimateFromD_, TauVisMassZoomEstimateFromDUP_, TauVisMassZoomEstimateFromDDOWN_, 1,
//               "TauVisMassZoomRegionItselfCanvas", "M(#tau_{H}#tau_{#mu})" );


}

void GetRatioPlot(TFile *outFile, TH1F *Obs, TH1F *Est, TH1F *EstUP, TH1F *EstDOWN, int rebin, string canvName, string xTitle)
{
  std::cout << "Est Name=" << Est->GetName() << std::endl;
  std::cout << "Obs Name=" << Obs->GetName() << std::endl;
  Est->SetLineColor(kRed);
  Est->SetFillColor(kRed);
  Est->SetMarkerColor(kRed);

  if (rebin > 1)
  {
    Est->Rebin(rebin);
    Obs->Rebin(rebin);
    EstDOWN->Rebin(rebin);
    EstUP->Rebin(rebin);
  }//if rebin

  writeExtraText = true;
  lumi_13TeV = "35.9 fb^{-1}";
  stringstream yTitle;
  yTitle << fixed;
  yTitle.precision(2);
  yTitle << "Events / " << Est->GetXaxis()->GetBinWidth(3) << " GeV";
  Est->GetYaxis()->SetTitle(yTitle.str().c_str() );
  Est->GetXaxis()->SetTitle(xTitle.c_str() );
  TLegend *legend = new TLegend(0.7,0.5,0.95,0.7) ;
  legend->SetTextFont(42);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->AddEntry(Est ,"Estimate of Region C From D", "le");
  legend->AddEntry(Obs, "Observed", "le");
  std::cout << "yTitle=" << yTitle.str().c_str() << std::endl;

  TCanvas *ratioCanvas = new TCanvas(canvName.c_str(), "", 600, 600);
  ratioCanvas->cd();
  TPad *plotpad = new TPad("plotpad", "top pad", 0.0, 0.21, 1.0, 1.0);
  plotpad->SetBottomMargin(0.04);
  plotpad->SetRightMargin(0.03);
  plotpad->Draw();
  TPad *ratiopad = new TPad("ratiopad", "bottom pad", 0.0, 0.0, 1.0, 0.21);
  ratiopad->SetTopMargin(0.06);
  ratiopad->SetRightMargin(0.03);
  ratiopad->SetBottomMargin(0.5);
  ratiopad->SetLeftMargin(0.16);
  ratiopad->SetTickx(1);
  ratiopad->SetTicky(1);
  ratiopad->Draw();

  ///////////////////////////
  // Plot Pad Creation
  ///////////////////////////
  for (int i=1; i < Obs->GetXaxis()->GetNbins(); i++)
  {
    Est->SetBinError(i, pow(Est->GetBinContent(i), 0.5) );
    double vNum = Est->GetBinContent(i), vNumDown = EstDOWN->GetBinContent(i), vNumUp = EstUP->GetBinContent(i);
    double ey_low  = pow( vNum + (vNumDown-vNum)*(vNumDown-vNum), 0.5) ;
    double ey_high = pow( vNum + (vNumUp  -vNum)*(vNumUp  -vNum), 0.5) ;
std::cout << "\nPREV ERROR:" << Est->GetBinError(i) << "\tDiffDOWN=" << vNum-vNumDown << "\tDiffLOW=" << vNumUp-vNum << endl;
std::cout <<   "Next ERROR:" << ey_low << "\tcontent=" << vNum <<endl;
    Est->SetBinError(i,ey_high);
  }//for i

std::cout << "CHECK 1" << std::endl;
  Est->GetXaxis()->SetLabelOffset(999);
  Est->SetStats(0);
  Est->GetYaxis()->SetTitle("Events");
  Est->GetYaxis()->SetTitleSize(0.05);
  Est->GetYaxis()->SetTitleOffset(0.2);
  Est->GetYaxis()->SetNdivisions(503);
  Est->Draw("P E");
std::cout << "CHECK 1.1" << std::endl;
  Obs->Draw("SAME P E");
std::cout << "CHECK 1.2" << std::endl;
  CMS_lumi( plotpad, 4, 11);
std::cout << "CHECK 1.3" << std::endl;
  legend->Draw("SAME");
std::cout << "CHECK 1.4" << std::endl;

  /////////////////////////// 
  // ratio pad Creatioin
  ///////////////////////////
  ratiopad->cd();
std::cout << "CHECK 1.5" << std::endl;
  TH1F *ratiostaterr = (TH1F*)Obs->Clone();
std::cout << "CHECK 1.6" << std::endl;
  ratiostaterr->SetStats(0);
  ratiostaterr->SetTitle("");
  ratiostaterr->GetYaxis()->SetTitle("Obs / Exp");
  ratiostaterr->SetMaximum(1.5);
  ratiostaterr->SetMinimum(0.5);
  ratiostaterr->SetMarkerSize(0);
  ratiostaterr->SetFillColor(kGray+3);
  ratiostaterr->SetFillStyle(3013);
  ratiostaterr->GetXaxis()->SetLabelSize(0.19);
  ratiostaterr->GetXaxis()->SetTitleSize(0.21);
  ratiostaterr->GetXaxis()->SetTitleOffset(1.0);
  ratiostaterr->GetXaxis()->SetLabelOffset(0.03);
  ratiostaterr->GetYaxis()->SetLabelSize(0.19);
  ratiostaterr->GetYaxis()->SetLabelOffset(0.006);
  ratiostaterr->GetYaxis()->SetTitleSize(0.21);
  ratiostaterr->GetYaxis()->SetTitleOffset(0.2);
  ratiostaterr->GetYaxis()->SetNdivisions(503);

std::cout << "CHECK 2" << std::endl;
  for (int i = 0; i <= Obs->GetNbinsX()+2; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (Obs->GetBinContent(i) > 1e-6)
    {
      double binerror = Obs->GetBinError(i) / Obs->GetBinContent(i);
      ratiostaterr->SetBinError(i, binerror);
    }//if
    else
      ratiostaterr->SetBinError(i, 999.);
  }//for

std::cout << "CHECK 3" << std::endl;
  ratiostaterr->SetXTitle(xTitle.c_str() );
  ratiostaterr->Draw("e2");
  TLine *ratiounity = new TLine(2.5,1,30,1);
  ratiounity->SetLineStyle(2);
  ratiounity->Draw("SAME");
  TH1F *num = (TH1F*)num->Clone();
  num->SetMarkerStyle(20);
  num->SetMarkerSize(1.);
  num->SetLineColor(kBlack);
  TGraphAsymmErrors *graph = new TGraphAsymmErrors(num->GetNbinsX());
  int npoints = 0;
std::cout << "CHECK 4" << std::endl;
  for (int i=1; i < num->GetXaxis()->GetNbins(); i++)
  {
    if (Est->GetBinContent(i) > 0)
    {
      double vNum = num->GetBinContent(i), vNumDown = EstDOWN->GetBinContent(i), vNumUp = EstUP->GetBinContent(i);
      double vDen = Est->GetBinContent(i);
      double ey_low  = pow( vNum + (vNumDown-vNum)*(vNumDown-vNum), 0.5) / vNum;
      double ey_high = pow( vNum + (vNumUp  -vNum)*(vNumUp  -vNum), 0.5) / vNum;
      graph->SetPoint(npoints, num->GetBinCenter(i), vNum / vDen);
      graph->SetPointEXlow(npoints,  0);
      graph->SetPointEXhigh(npoints, 0);
      graph->SetPointEYlow(npoints,  ey_low );
      graph->SetPointEYhigh(npoints, ey_high);
    }//if
    else
    {
      graph->SetPoint(npoints, num->GetBinCenter(i), 0);
      graph->SetPointEXlow(npoints,  0);
      graph->SetPointEXhigh(npoints, 0);
      graph->SetPointEYlow(npoints,  0);
      graph->SetPointEYhigh(npoints, 0);
    }//ekse
    npoints += 1;
  }//for i
std::cout << "CHECK 5" << std::endl;
  graph->Set(npoints);
std::cout << "CHECK 6" << std::endl;
  graph->Draw("0P SAME");
std::cout << "CHECK 7" << std::endl;

  ratioCanvas->Write();
}




