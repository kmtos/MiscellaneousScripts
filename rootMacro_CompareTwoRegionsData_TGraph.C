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
#include "TAxis.h"
#include "tdrstyle.C"
#include "CMS_lumi.C"

double PropogateErrors(double val1, double val2, double err1, double err2);

void rootMacro_CompareTwoRegionsData_TGraph()
{
  setTDRStyle(true);
  gStyle->SetPalette(1);


  //Old DMs
  TFile infileEstimateFromD("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_SingleMu_AntiMedIsoMu2_TauDMAntiMedIso_SEP2_CFromD_Add3Bin_v4.root");
  TFile infileEstimateFromD_UP("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_SingleMu_AntiMedIsoMu2_TauDMAntiMedIso_SEP2_CFromDUP_Add3Bin_v4.root");
  TFile infileEstimateFromD_DOWN("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_SingleMu_AntiMedIsoMu2_TauDMAntiMedIso_SEP2_CFromDDOWN_Add3Bin_v4.root");
  TFile infileRegionItself("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_SingleMu_AntiMedIsoMu2_TauDMMedIso_SEP2_CItself_Add3Bin_v4.root");

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimateData_DatatoData_CFromD_SEP2_Add3Bin_v4.root", "RECREATE");

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
  TH1F *PtTauFakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("PtTauFakeWeight");
  TH1F *PtTauDM0FakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("PtTauDM0FakeWeight");
  TH1F *PtTauDM1FakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("PtTauDM1FakeWeight");
  TH1F *PtTauDM10FakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("PtTauDM10FakeWeight");
  TH1F *EtaFakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("EtaFakeWeight");
  TH1F *DRFakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("DRFakeWeight");
  TH1F *PtTauDM0FakeRateBinningEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("PtTauDM0FakeRateBinning");
  TH1F *PtTauDM1FakeRateBinningEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("PtTauDM1FakeRateBinning");
  TH1F *PtTauDM10FakeRateBinningEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("PtTauDM10FakeRateBinning");

  TH1F *DiMuInvMassFakeWeightEstimateFromD_DOWN_ = (TH1F*)infileEstimateFromD_DOWN.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightEstimateFromD_DOWN_ = (TH1F*)infileEstimateFromD_DOWN.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightEstimateFromD_DOWN_ = (TH1F*)infileEstimateFromD_DOWN.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightEstimateFromD_DOWN_ = (TH1F*)infileEstimateFromD_DOWN.Get("PtMu1FakeWeight");
  TH1F *PtMu3FakeWeightEstimateFromD_DOWN_ = (TH1F*)infileEstimateFromD_DOWN.Get("PtMu3FakeWeight");
  TH1F *PtTauFakeWeightEstimateFromD_DOWN_ = (TH1F*)infileEstimateFromD_DOWN.Get("PtTauFakeWeight");
  TH1F *PtTauDM0FakeWeightEstimateFromD_DOWN_ = (TH1F*)infileEstimateFromD_DOWN.Get("PtTauDM0FakeWeight");
  TH1F *PtTauDM1FakeWeightEstimateFromD_DOWN_ = (TH1F*)infileEstimateFromD_DOWN.Get("PtTauDM1FakeWeight");
  TH1F *PtTauDM10FakeWeightEstimateFromD_DOWN_ = (TH1F*)infileEstimateFromD_DOWN.Get("PtTauDM10FakeWeight");
  TH1F *EtaFakeWeightEstimateFromD_DOWN_ = (TH1F*)infileEstimateFromD_DOWN.Get("EtaFakeWeight");
  TH1F *PtTauDM0FakeRateBinningEstimateFromD_DOWN_ = (TH1F*)infileEstimateFromD_DOWN.Get("PtTauDM0FakeRateBinning");
  TH1F *PtTauDM1FakeRateBinningEstimateFromD_DOWN_ = (TH1F*)infileEstimateFromD_DOWN.Get("PtTauDM1FakeRateBinning");
  TH1F *PtTauDM10FakeRateBinningEstimateFromD_DOWN_ = (TH1F*)infileEstimateFromD_DOWN.Get("PtTauDM10FakeRateBinning");

  TH1F *DiMuInvMassFakeWeightEstimateFromD_UP_ = (TH1F*)infileEstimateFromD_UP.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightEstimateFromD_UP_ = (TH1F*)infileEstimateFromD_UP.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightEstimateFromD_UP_ = (TH1F*)infileEstimateFromD_UP.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightEstimateFromD_UP_ = (TH1F*)infileEstimateFromD_UP.Get("PtMu1FakeWeight");
  TH1F *PtMu3FakeWeightEstimateFromD_UP_ = (TH1F*)infileEstimateFromD_UP.Get("PtMu3FakeWeight");
  TH1F *PtTauFakeWeightEstimateFromD_UP_ = (TH1F*)infileEstimateFromD_UP.Get("PtTauFakeWeight");
  TH1F *PtTauDM0FakeWeightEstimateFromD_UP_ = (TH1F*)infileEstimateFromD_UP.Get("PtTauDM0FakeWeight");
  TH1F *PtTauDM1FakeWeightEstimateFromD_UP_ = (TH1F*)infileEstimateFromD_UP.Get("PtTauDM1FakeWeight");
  TH1F *PtTauDM10FakeWeightEstimateFromD_UP_ = (TH1F*)infileEstimateFromD_UP.Get("PtTauDM10FakeWeight");
  TH1F *EtaFakeWeightEstimateFromD_UP_ = (TH1F*)infileEstimateFromD_UP.Get("EtaFakeWeight");
  TH1F *PtTauDM0FakeRateBinningEstimateFromD_UP_ = (TH1F*)infileEstimateFromD_UP.Get("PtTauDM0FakeRateBinning");
  TH1F *PtTauDM1FakeRateBinningEstimateFromD_UP_ = (TH1F*)infileEstimateFromD_UP.Get("PtTauDM1FakeRateBinning");
  TH1F *PtTauDM10FakeRateBinningEstimateFromD_UP_ = (TH1F*)infileEstimateFromD_UP.Get("PtTauDM10FakeRateBinning");


  InvMassTauMuMu1EstimateFromD_->SetLineColor(kRed);
  InvMassTauMuMu2EstimateFromD_->SetLineColor(kRed);
  DiMuInvMassFakeWeightEstimateFromD_->SetLineColor(kRed);
  DiMuDiTauInvMassFakeWeightEstimateFromD_->SetLineColor(kRed);
  DiTauInvMassFakeWeightEstimateFromD_->SetLineColor(kRed);
  PtMu1FakeWeightEstimateFromD_->SetLineColor(kRed);
  PtMu2FakeWeightEstimateFromD_->SetLineColor(kRed);
  PtMu3FakeWeightEstimateFromD_->SetLineColor(kRed);
  PtTauFakeWeightEstimateFromD_->SetLineColor(kRed);
  PtTauDM0FakeWeightEstimateFromD_->SetLineColor(kRed);
  PtTauDM1FakeWeightEstimateFromD_->SetLineColor(kRed);
  PtTauDM10FakeWeightEstimateFromD_->SetLineColor(kRed);
  EtaFakeWeightEstimateFromD_->SetLineColor(kRed);
  DRFakeWeightEstimateFromD_->SetLineColor(kRed);
  PtTauDM0FakeRateBinningEstimateFromD_->SetLineColor(kRed);
  PtTauDM1FakeRateBinningEstimateFromD_->SetLineColor(kRed);
  PtTauDM10FakeRateBinningEstimateFromD_->SetLineColor(kRed);

  InvMassTauMuMu1EstimateFromD_->SetFillColor(kRed);
  InvMassTauMuMu2EstimateFromD_->SetFillColor(kRed);
  DiMuInvMassFakeWeightEstimateFromD_->SetFillColor(kRed);
  DiMuDiTauInvMassFakeWeightEstimateFromD_->SetFillColor(kRed);
  DiTauInvMassFakeWeightEstimateFromD_->SetFillColor(kRed);
  PtMu1FakeWeightEstimateFromD_->SetFillColor(kRed);
  PtMu2FakeWeightEstimateFromD_->SetFillColor(kRed);
  PtMu3FakeWeightEstimateFromD_->SetFillColor(kRed);
  PtTauFakeWeightEstimateFromD_->SetFillColor(kRed);
  PtTauDM0FakeWeightEstimateFromD_->SetFillColor(kRed);
  PtTauDM1FakeWeightEstimateFromD_->SetFillColor(kRed);
  PtTauDM10FakeWeightEstimateFromD_->SetFillColor(kRed);
  EtaFakeWeightEstimateFromD_->SetFillColor(kRed);
  DRFakeWeightEstimateFromD_->SetFillColor(kRed);
  PtTauDM0FakeRateBinningEstimateFromD_->SetFillColor(kRed);
  PtTauDM1FakeRateBinningEstimateFromD_->SetFillColor(kRed);
  PtTauDM10FakeRateBinningEstimateFromD_->SetFillColor(kRed);

  InvMassTauMuMu1EstimateFromD_->SetMarkerColor(kRed);
  InvMassTauMuMu2EstimateFromD_->SetMarkerColor(kRed);
  DiMuInvMassFakeWeightEstimateFromD_->SetMarkerColor(kRed);
  DiMuDiTauInvMassFakeWeightEstimateFromD_->SetMarkerColor(kRed);
  DiTauInvMassFakeWeightEstimateFromD_->SetMarkerColor(kRed);
  PtMu1FakeWeightEstimateFromD_->SetMarkerColor(kRed);
  PtMu2FakeWeightEstimateFromD_->SetMarkerColor(kRed);
  PtMu3FakeWeightEstimateFromD_->SetMarkerColor(kRed);
  PtTauFakeWeightEstimateFromD_->SetMarkerColor(kRed);
  PtTauDM0FakeWeightEstimateFromD_->SetMarkerColor(kRed);
  PtTauDM1FakeWeightEstimateFromD_->SetMarkerColor(kRed);
  PtTauDM10FakeWeightEstimateFromD_->SetMarkerColor(kRed);
  EtaFakeWeightEstimateFromD_->SetMarkerColor(kRed);
  DRFakeWeightEstimateFromD_->SetMarkerColor(kRed);
  PtTauDM0FakeRateBinningEstimateFromD_->SetMarkerColor(kRed);
  PtTauDM1FakeRateBinningEstimateFromD_->SetMarkerColor(kRed);
  PtTauDM10FakeRateBinningEstimateFromD_->SetMarkerColor(kRed);

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
  TH1F *PtTauFakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("PtTauFakeWeight");
  TH1F *PtTauDM0FakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("PtTauDM0FakeWeight");
  TH1F *PtTauDM1FakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("PtTauDM1FakeWeight");
  TH1F *PtTauDM10FakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("PtTauDM10FakeWeight");
  TH1F *EtaFakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("EtaFakeWeight");
  TH1F *DRFakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("DRFakeWeight");
  TH1F *PtTauDM0FakeRateBinningRegionItself_ = (TH1F*)infileRegionItself.Get("PtTauDM0FakeRateBinning");
  TH1F *PtTauDM1FakeRateBinningRegionItself_ = (TH1F*)infileRegionItself.Get("PtTauDM1FakeRateBinning");
  TH1F *PtTauDM10FakeRateBinningRegionItself_ = (TH1F*)infileRegionItself.Get("PtTauDM10FakeRateBinning");

cout << "Got Histograms from Canvases" << endl;
  outFile->cd();

cout << "Set Colors" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the output plots
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *InvMassTauMuMu1Canvas = new TCanvas ("InvMassTauMuMu1Canvas","",600,600);
  TCanvas *InvMassTauMuMu2Canvas = new TCanvas ("InvMassTauMuMu2Canvas","",600,600);
  TCanvas *DiMuInvMassFakeWeightCanvas = new TCanvas ("DiMuInvMassFakeWeightCanvas","",600,600);
  TCanvas *DiMuDiTauInvMassFakeWeightCanvas = new TCanvas ("DiMuDiTauInvMassFakeWeightCanvas","",600,600);
  TCanvas *DiTauInvMassFakeWeightCanvas = new TCanvas ("DiTauInvMassFakeWeightCanvas","",600,600);
  TCanvas *PtMu1FakeWeightCanvas = new TCanvas ("PtMu1FakeWeightCanvas","",600,600);
  TCanvas *PtMu2FakeWeightCanvas = new TCanvas ("PtMu2FakeWeightCanvas","",600,600);
  TCanvas *PtMu3FakeWeightCanvas = new TCanvas ("PtMu3FakeWeightCanvas","",600,600);
  TCanvas *PtTauFakeWeightCanvas = new TCanvas ("PtTauFakeWeightCanvas","",600,600);
  TCanvas *PtTauDM0FakeWeightCanvas = new TCanvas ("PtTauDM0FakeWeightCanvas","",600,600);
  TCanvas *PtTauDM1FakeWeightCanvas = new TCanvas ("PtTauDM1FakeWeightCanvas","",600,600);
  TCanvas *PtTauDM10FakeWeightCanvas = new TCanvas ("PtTauDM10FakeWeightCanvas","",600,600);
  TCanvas *EtaFakeWeightCanvas = new TCanvas ("EtaFakeWeightCanvas","",600,600);
  TCanvas *DRFakeWeightCanvas = new TCanvas ("DRFakeWeightCanvas","",600,600);
  TCanvas *PtTauDM0FakeRateBinningCanvas = new TCanvas ("PtTauDM0FakeRateBinningCanvas","",600,600);
  TCanvas *PtTauDM1FakeRateBinningCanvas = new TCanvas ("PtTauDM1FakeRateBinningCanvas","",600,600);
  TCanvas *PtTauDM10FakeRateBinningCanvas = new TCanvas ("PtTauDM10FakeRateBinningCanvas","",600,600);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting the cms_lumi Styling
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  writeExtraText = true;
  lumi_13TeV = "35.9 fb^{-1}";

  TLegend *legend = new TLegend(0.7,0.5,0.95,0.7) ;
  legend->SetTextFont(42);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->AddEntry(InvMassTauMuMu1EstimateFromD_ ,"Estimate of Region C From D", "le");
  legend->AddEntry(InvMassTauMuMu1RegionItself_, "Observed", "le");


cout << "Cms_lumi run" << endl;

////////////////////////////////
// Ratio DiMuDi
///////////////////////////////
  TCanvas *DiMuRatioCanvas = new TCanvas("DiMuRatioCanvas", "", 800, 600);
  DiMuRatioCanvas->cd();
  TPad *DiMuplotpad = new TPad("DiMuplotpad", "top pad", 0.0, 0.21, 1.0, 1.0);
  DiMuplotpad->SetBottomMargin(0.04);
  DiMuplotpad->SetRightMargin(0.03);
  DiMuplotpad->Draw();
  TPad *DiMuratiopad = new TPad("DiMuratiopad", "bottom pad", 0.0, 0.0, 1.0, 0.21);
  DiMuratiopad->SetTopMargin(0.06);
  DiMuratiopad->SetRightMargin(0.03);
  DiMuratiopad->SetBottomMargin(0.5);
  DiMuratiopad->SetLeftMargin(0.16);
  DiMuratiopad->SetTickx(1);
  DiMuratiopad->SetTicky(1);
  DiMuratiopad->Draw();
  TMultiGraph *DiMumg = new TMultiGraph();
  TGraphAsymmErrors *DiMuCItselfgraph = new TGraphAsymmErrors();//DiMuInvMassFakeWeightEstimateFromD_->GetNbinsX());
  TGraphAsymmErrors *DiMuFromDgraph   = new TGraphAsymmErrors();//DiMuInvMassFakeWeightEstimateFromD_->GetNbinsX());
  DiMuFromDgraph->SetMarkerColor(kRed);
  DiMuFromDgraph->SetLineColor(kRed);
  int npoints = 0;
  DiMuplotpad->cd();
  for (int i=1; i < DiMuInvMassFakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (DiMuInvMassFakeWeightEstimateFromD_->GetBinContent(i) > 0)
    {
      double vDen = DiMuInvMassFakeWeightEstimateFromD_->GetBinContent(i), vDenUp = DiMuInvMassFakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = DiMuInvMassFakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) ;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) ;
      std::cout << "\n\nPREV ERROR:" << DiMuInvMassFakeWeightEstimateFromD_->GetBinError(i) << "\tDiffHigh=" << vDenDown-vDen << "\tDiffHigh=" << vDenUp-vDen << endl;
      std::cout << " vDenUp=" << vDenUp << " vDen=" << vDen << " vDenDown=" << vDenDown << std::endl;
      std::cout << "(vDenDown-vDen)*(vDenDown-vDen)=" << (vDenDown-vDen)*(vDenDown-vDen) << "  vDen + (vDenDown-vDen)*(vDenDown-vDen)=" << vDen + (vDenDown-vDen)*(vDenDown-vDen) << std::endl;
      std::cout << "(vDenUp  -vDen)*(vDenUp  -vDen)=" << (vDenUp  -vDen)*(vDenUp  -vDen) << "  vDen + (vDenUp  -vDen)*(vDenUp  -vDen)=" << vDen + (vDenUp  -vDen)*(vDenUp  -vDen) << std::endl;
      std::cout <<   "Before Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      ey_low = pow( (ey_low*ey_low) + DiMuInvMassFakeWeightEstimateFromD_->GetBinContent(i) , 0.5);
      std::cout <<   "After  Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      double binWidth = DiMuInvMassFakeWeightRegionItself_->GetBinWidth(i) /2.0;
      if (i ==1)
        binWidth = 0;
      DiMuCItselfgraph->SetPoint(npoints, DiMuInvMassFakeWeightEstimateFromD_->GetBinCenter(i), DiMuInvMassFakeWeightRegionItself_->GetBinContent(i));
      DiMuCItselfgraph->SetPointEXlow(npoints,  binWidth);
      DiMuCItselfgraph->SetPointEXhigh(npoints, binWidth);
      DiMuCItselfgraph->SetPointEYlow(npoints,  pow(DiMuInvMassFakeWeightRegionItself_->GetBinContent(i), 0.5) );
      DiMuCItselfgraph->SetPointEYhigh(npoints, pow(DiMuInvMassFakeWeightRegionItself_->GetBinContent(i), 0.5) );
      DiMuFromDgraph->SetPoint(npoints, DiMuInvMassFakeWeightEstimateFromD_->GetBinCenter(i), DiMuInvMassFakeWeightEstimateFromD_->GetBinContent(i));
      DiMuFromDgraph->SetPointEXlow(npoints,  binWidth);
      DiMuFromDgraph->SetPointEXhigh(npoints, binWidth);
      DiMuFromDgraph->SetPointEYlow(npoints,  ey_low );
      DiMuFromDgraph->SetPointEYhigh(npoints, ey_high);
    }//if
    else
    {
      DiMuFromDgraph->SetPoint(npoints, num->GetBinCenter(i), 0);
      DiMuFromDgraph->SetPointEXlow(npoints,  0);
      DiMuFromDgraph->SetPointEXhigh(npoints, 0);
      DiMuFromDgraph->SetPointEYlow(npoints,  0);
      DiMuFromDgraph->SetPointEYhigh(npoints, 0);
      DiMuCItselfgraph->SetPointEXlow(npoints,  0);
      DiMuCItselfgraph->SetPointEXhigh(npoints, 0);
      DiMuCItselfgraph->SetPointEYlow(npoints,  0);
      DiMuCItselfgraph->SetPointEYhigh(npoints, 0);
    }//ekse
    npoints++;
  }//for i
  DiMumg->Add(DiMuFromDgraph);
  DiMumg->Add(DiMuCItselfgraph);
  DiMumg->Draw("AP");
  DiMumg->GetXaxis()->SetLimits(0.,30.0);
  DiMumg->GetXaxis()->SetLabelOffset(999);
  DiMumg->GetYaxis()->SetTitle("Events");
  DiMumg->GetYaxis()->SetTitleSize(0.05);
  DiMumg->GetYaxis()->SetTitleOffset(0.2);
  CMS_lumi( DiMuplotpad, 4, 11);
  legend->Draw("SAME");

  DiMuratiopad->cd();
  TH1F *ratiostaterr = (TH1F*)DiMuInvMassFakeWeightRegionItself_->Clone();
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

  for (int i = 0; i <= DiMuInvMassFakeWeightEstimateFromD_->GetNbinsX()+1; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (DiMuInvMassFakeWeightEstimateFromD_->GetBinContent(i) > 1e-6)
    {
      double binerror = DiMuInvMassFakeWeightRegionItself_->GetBinError(i) / DiMuInvMassFakeWeightRegionItself_->GetBinContent(i);
      ratiostaterr->SetBinError(i, binerror);
    }//if
    else
      ratiostaterr->SetBinError(i, 999.);
  }//for

  ratiostaterr->SetXTitle("m(#mu_{1},#mu_{2}) GeV");
  ratiostaterr->Draw("e2");
  TLine *ratiounity = new TLine(2.5,1,30,1);
  ratiounity->SetLineStyle(2);
  ratiounity->Draw("SAME");
  TH1F *num = (TH1F*)DiMuInvMassFakeWeightRegionItself_->Clone();
  num->SetMarkerStyle(20);
  num->SetMarkerSize(1.);
  num->SetLineColor(kBlack);
  TGraphAsymmErrors *graph = new TGraphAsymmErrors(num->GetNbinsX());
  int npoints = 0;
  for (int i=1; i < DiMuInvMassFakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (DiMuInvMassFakeWeightEstimateFromD_->GetBinContent(i) > 0)
    { 
      double vNum = num->GetBinContent(i), vDenUp = DiMuInvMassFakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = DiMuInvMassFakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double vDen = DiMuInvMassFakeWeightEstimateFromD_->GetBinContent(i), wNum = num->GetBinWidth(i+1), wDen = num->GetBinWidth(i+1);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) / vDen;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) / vDen;
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
  graph->Set(npoints);
  graph->Draw("0P SAME");

  DiMuRatioCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRateEstimates/DiMuMassEstimate.png");
  DiMuRatioCanvas->Write();  

////////////////////////////////
// Ratio DiTauDi
///////////////////////////////
  TCanvas *DiTauRatioCanvas = new TCanvas("DiTauRatioCanvas", "", 800, 600);
  DiTauRatioCanvas->cd();
  TPad *DiTauplotpad = new TPad("DiTauplotpad", "top pad", 0.0, 0.21, 1.0, 1.0);
  DiTauplotpad->SetBottomMargin(0.04);
  DiTauplotpad->SetRightMargin(0.03);
  DiTauplotpad->Draw();
  TPad *DiTauratiopad = new TPad("DiTauratiopad", "bottom pad", 0.0, 0.0, 1.0, 0.21);
  DiTauratiopad->SetTopMargin(0.06);
  DiTauratiopad->SetRightMargin(0.03);
  DiTauratiopad->SetBottomMargin(0.5);
  DiTauratiopad->SetLeftMargin(0.16);
  DiTauratiopad->SetTickx(1);
  DiTauratiopad->SetTicky(1);
  DiTauratiopad->Draw();
  TMultiGraph *DiTaumg = new TMultiGraph();
  TGraphAsymmErrors *DiTauCItselfgraph = new TGraphAsymmErrors(DiTauInvMassFakeWeightEstimateFromD_->GetNbinsX());
  TGraphAsymmErrors *DiTauFromDgraph   = new TGraphAsymmErrors(DiTauInvMassFakeWeightEstimateFromD_->GetNbinsX());
  DiTauFromDgraph->SetMarkerColor(kRed);
  DiTauFromDgraph->SetLineColor(kRed);
  int npoints = 0;
  DiTauplotpad->cd();
  for (int i=1; i < DiTauInvMassFakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (DiTauInvMassFakeWeightEstimateFromD_->GetBinContent(i) > 0)
    {
      double vDen = DiTauInvMassFakeWeightEstimateFromD_->GetBinContent(i), vDenUp = DiTauInvMassFakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = DiTauInvMassFakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) ;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) ;
      std::cout << "\n\nPREV ERROR:" << DiTauInvMassFakeWeightEstimateFromD_->GetBinError(i) << "\tDiffHigh=" << vDenDown-vDen << "\tDiffHigh=" << vDenUp-vDen << endl;
      std::cout << " vDenUp=" << vDenUp << " vDen=" << vDen << " vDenDown=" << vDenDown << std::endl;
      std::cout << "(vDenDown-vDen)*(vDenDown-vDen)=" << (vDenDown-vDen)*(vDenDown-vDen) << "  vDen + (vDenDown-vDen)*(vDenDown-vDen)=" << vDen + (vDenDown-vDen)*(vDenDown-vDen) << std::endl;
      std::cout << "(vDenUp  -vDen)*(vDenUp  -vDen)=" << (vDenUp  -vDen)*(vDenUp  -vDen) << "  vDen + (vDenUp  -vDen)*(vDenUp  -vDen)=" << vDen + (vDenUp  -vDen)*(vDenUp  -vDen) << std::endl;
      std::cout <<   "Before Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      ey_low = pow( (ey_low*ey_low) + DiTauInvMassFakeWeightEstimateFromD_->GetBinContent(i) , 0.5);
      std::cout <<   "After  Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      double binWidth = DiTauInvMassFakeWeightRegionItself_->GetBinWidth(i) /2.0;
      if (i ==1)
        binWidth = 0;
      DiTauCItselfgraph->SetPoint(npoints, DiTauInvMassFakeWeightEstimateFromD_->GetBinCenter(i), DiTauInvMassFakeWeightRegionItself_->GetBinContent(i));
      DiTauCItselfgraph->SetPointEXlow(npoints,  binWidth);
      DiTauCItselfgraph->SetPointEXhigh(npoints, binWidth);
      DiTauCItselfgraph->SetPointEYlow(npoints,  pow(DiTauInvMassFakeWeightRegionItself_->GetBinContent(i), 0.5) );
      DiTauCItselfgraph->SetPointEYhigh(npoints, pow(DiTauInvMassFakeWeightRegionItself_->GetBinContent(i), 0.5) );
      DiTauFromDgraph->SetPoint(npoints, DiTauInvMassFakeWeightEstimateFromD_->GetBinCenter(i), DiTauInvMassFakeWeightEstimateFromD_->GetBinContent(i));
      DiTauFromDgraph->SetPointEXlow(npoints,  binWidth);
      DiTauFromDgraph->SetPointEXhigh(npoints, binWidth);
      DiTauFromDgraph->SetPointEYlow(npoints,  ey_low );
      DiTauFromDgraph->SetPointEYhigh(npoints, ey_high);
    }//if
    else
    {
      DiTauFromDgraph->SetPoint(npoints, num->GetBinCenter(i), 0);
      DiTauFromDgraph->SetPointEXlow(npoints,  0);
      DiTauFromDgraph->SetPointEXhigh(npoints, 0);
      DiTauFromDgraph->SetPointEYlow(npoints,  0);
      DiTauFromDgraph->SetPointEYhigh(npoints, 0);
      DiTauCItselfgraph->SetPointEXlow(npoints,  0);
      DiTauCItselfgraph->SetPointEXhigh(npoints, 0);
      DiTauCItselfgraph->SetPointEYlow(npoints,  0);
      DiTauCItselfgraph->SetPointEYhigh(npoints, 0);
    }//ekse
    npoints++;
  }//for i
  DiTaumg->Add(DiTauFromDgraph);
  DiTaumg->Add(DiTauCItselfgraph);
  DiTaumg->Draw("AP");
  DiTaumg->GetXaxis()->SetLimits(0.,30.0);
  DiTaumg->GetXaxis()->SetLabelOffset(999);
  DiTaumg->GetYaxis()->SetTitle("Events");
  DiTaumg->GetYaxis()->SetTitleSize(0.05);
  DiTaumg->GetYaxis()->SetTitleOffset(0.2);
  CMS_lumi( DiTauplotpad, 4, 11);
  legend->Draw("SAME");

  DiTauratiopad->cd();
  TH1F *ratiostaterr = (TH1F*)DiTauInvMassFakeWeightRegionItself_->Clone();
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

  for (int i = 0; i <= DiTauInvMassFakeWeightEstimateFromD_->GetNbinsX()+1; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (DiTauInvMassFakeWeightEstimateFromD_->GetBinContent(i) > 1e-6)
    {
      double binerror = DiTauInvMassFakeWeightRegionItself_->GetBinError(i) / DiTauInvMassFakeWeightRegionItself_->GetBinContent(i);
      ratiostaterr->SetBinError(i, binerror);
    }//if
    else
      ratiostaterr->SetBinError(i, 999.);
  }//for

  ratiostaterr->SetXTitle("m(#tau_{H},#tau_{#mu}) GeV");
  ratiostaterr->Draw("e2");
  TLine *ratiounity = new TLine(2.5,1,30,1);
  ratiounity->SetLineStyle(2);
  ratiounity->Draw("SAME");
  TH1F *num = (TH1F*)DiTauInvMassFakeWeightRegionItself_->Clone();
  num->SetMarkerStyle(20);
  num->SetMarkerSize(1.);
  num->SetLineColor(kBlack);
  TGraphAsymmErrors *graph = new TGraphAsymmErrors(num->GetNbinsX());
  int npoints = 0;
  for (int i=1; i < DiTauInvMassFakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (DiTauInvMassFakeWeightEstimateFromD_->GetBinContent(i) > 0)
    { 
      double vNum = num->GetBinContent(i), vDenUp = DiTauInvMassFakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = DiTauInvMassFakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double vDen = DiTauInvMassFakeWeightEstimateFromD_->GetBinContent(i), wNum = num->GetBinWidth(i+1), wDen = num->GetBinWidth(i+1);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) / vDen;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) / vDen;
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
  graph->Set(npoints);
  graph->Draw("0P SAME");

  DiTauRatioCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRateEstimates/DiTauMassEstimate.png");
  DiTauRatioCanvas->Write();  

////////////////////////////////
// Ratio DiMuDiTauDi
///////////////////////////////
  TCanvas *DiMuDiTauRatioCanvas = new TCanvas("DiMuDiTauRatioCanvas", "", 800, 600);
  DiMuDiTauRatioCanvas->cd();
  TPad *DiMuDiTauplotpad = new TPad("DiMuDiTauplotpad", "top pad", 0.0, 0.21, 1.0, 1.0);
  DiMuDiTauplotpad->SetBottomMargin(0.04);
  DiMuDiTauplotpad->SetRightMargin(0.03);
  DiMuDiTauplotpad->Draw();
  TPad *DiMuDiTauratiopad = new TPad("DiMuDiTauratiopad", "bottom pad", 0.0, 0.0, 1.0, 0.21);
  DiMuDiTauratiopad->SetTopMargin(0.06);
  DiMuDiTauratiopad->SetRightMargin(0.03);
  DiMuDiTauratiopad->SetBottomMargin(0.5);
  DiMuDiTauratiopad->SetLeftMargin(0.16);
  DiMuDiTauratiopad->SetTickx(1);
  DiMuDiTauratiopad->SetTicky(1);
  DiMuDiTauratiopad->Draw();
  TMultiGraph *DiMuDiTaumg = new TMultiGraph();
  TGraphAsymmErrors *DiMuDiTauCItselfgraph = new TGraphAsymmErrors(DiMuDiTauInvMassFakeWeightEstimateFromD_->GetNbinsX());
  TGraphAsymmErrors *DiMuDiTauFromDgraph   = new TGraphAsymmErrors(DiMuDiTauInvMassFakeWeightEstimateFromD_->GetNbinsX());
  DiMuDiTauFromDgraph->SetMarkerColor(kRed);
  DiMuDiTauFromDgraph->SetLineColor(kRed);
  int npoints = 0;
  DiMuDiTauplotpad->cd();
  for (int i=1; i < DiMuDiTauInvMassFakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (DiMuDiTauInvMassFakeWeightEstimateFromD_->GetBinContent(i) > 0)
    {
      double vDen = DiMuDiTauInvMassFakeWeightEstimateFromD_->GetBinContent(i), vDenUp = DiMuDiTauInvMassFakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = DiMuDiTauInvMassFakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) ;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) ;
      std::cout << "\n\nPREV ERROR:" << DiMuDiTauInvMassFakeWeightEstimateFromD_->GetBinError(i) << "\tDiffHigh=" << vDenDown-vDen << "\tDiffHigh=" << vDenUp-vDen << endl;
      std::cout << " vDenUp=" << vDenUp << " vDen=" << vDen << " vDenDown=" << vDenDown << std::endl;
      std::cout << "(vDenDown-vDen)*(vDenDown-vDen)=" << (vDenDown-vDen)*(vDenDown-vDen) << "  vDen + (vDenDown-vDen)*(vDenDown-vDen)=" << vDen + (vDenDown-vDen)*(vDenDown-vDen) << std::endl;
      std::cout << "(vDenUp  -vDen)*(vDenUp  -vDen)=" << (vDenUp  -vDen)*(vDenUp  -vDen) << "  vDen + (vDenUp  -vDen)*(vDenUp  -vDen)=" << vDen + (vDenUp  -vDen)*(vDenUp  -vDen) << std::endl;
      std::cout <<   "Before Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      ey_low = pow( (ey_low*ey_low) + DiMuDiTauInvMassFakeWeightEstimateFromD_->GetBinContent(i) , 0.5);
      std::cout <<   "After  Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      double binWidth = DiMuDiTauInvMassFakeWeightRegionItself_->GetBinWidth(i) /2.0;
      if (i ==1)
        binWidth = 0;
      DiMuDiTauCItselfgraph->SetPoint(npoints, DiMuDiTauInvMassFakeWeightEstimateFromD_->GetBinCenter(i), DiMuDiTauInvMassFakeWeightRegionItself_->GetBinContent(i));
      DiMuDiTauCItselfgraph->SetPointEXlow(npoints,  binWidth);
      DiMuDiTauCItselfgraph->SetPointEXhigh(npoints, binWidth);
      DiMuDiTauCItselfgraph->SetPointEYlow(npoints,  pow(DiMuDiTauInvMassFakeWeightRegionItself_->GetBinContent(i), 0.5) );
      DiMuDiTauCItselfgraph->SetPointEYhigh(npoints, pow(DiMuDiTauInvMassFakeWeightRegionItself_->GetBinContent(i), 0.5) );
      DiMuDiTauFromDgraph->SetPoint(npoints, DiMuDiTauInvMassFakeWeightEstimateFromD_->GetBinCenter(i), DiMuDiTauInvMassFakeWeightEstimateFromD_->GetBinContent(i));
      DiMuDiTauFromDgraph->SetPointEXlow(npoints,  binWidth);
      DiMuDiTauFromDgraph->SetPointEXhigh(npoints, binWidth);
      DiMuDiTauFromDgraph->SetPointEYlow(npoints,  ey_low );
      DiMuDiTauFromDgraph->SetPointEYhigh(npoints, ey_high);
    }//if
    else
    {
      DiMuDiTauFromDgraph->SetPoint(npoints, num->GetBinCenter(i), 0);
      DiMuDiTauFromDgraph->SetPointEXlow(npoints,  0);
      DiMuDiTauFromDgraph->SetPointEXhigh(npoints, 0);
      DiMuDiTauFromDgraph->SetPointEYlow(npoints,  0);
      DiMuDiTauFromDgraph->SetPointEYhigh(npoints, 0);
      DiMuDiTauCItselfgraph->SetPointEXlow(npoints,  0);
      DiMuDiTauCItselfgraph->SetPointEXhigh(npoints, 0);
      DiMuDiTauCItselfgraph->SetPointEYlow(npoints,  0);
      DiMuDiTauCItselfgraph->SetPointEYhigh(npoints, 0);
    }//ekse
    npoints++;
  }//for i
  DiMuDiTaumg->Add(DiMuDiTauFromDgraph);
  DiMuDiTaumg->Add(DiMuDiTauCItselfgraph);
  DiMuDiTaumg->Draw("AP");
  DiMuDiTaumg->GetXaxis()->SetLimits(0.,300.0);
  DiMuDiTaumg->GetXaxis()->SetLabelOffset(999);
  DiMuDiTaumg->GetYaxis()->SetTitle("Events");
  DiMuDiTaumg->GetYaxis()->SetTitleSize(0.05);
  DiMuDiTaumg->GetYaxis()->SetTitleOffset(0.2);
  CMS_lumi( DiMuDiTauplotpad, 4, 11);
  legend->Draw("SAME");

  DiMuDiTauratiopad->cd();
  TH1F *ratiostaterr = (TH1F*)DiMuDiTauInvMassFakeWeightRegionItself_->Clone();
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

  for (int i = 0; i <= DiMuDiTauInvMassFakeWeightEstimateFromD_->GetNbinsX()+1; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (DiMuDiTauInvMassFakeWeightEstimateFromD_->GetBinContent(i) > 1e-6)
    {
      double binerror = DiMuDiTauInvMassFakeWeightRegionItself_->GetBinError(i) / DiMuDiTauInvMassFakeWeightRegionItself_->GetBinContent(i);
      ratiostaterr->SetBinError(i, binerror);
    }//if
    else
      ratiostaterr->SetBinError(i, 999.);
  }//for

  ratiostaterr->SetXTitle("m(#mu_{1},#mu_{2},#tau_{#mu}#tau_{H}) GeV");
  ratiostaterr->Draw("e2");
  TLine *ratiounity = new TLine(2.5,1,30,1);
  ratiounity->SetLineStyle(2);
  ratiounity->Draw("SAME");
  TH1F *num = (TH1F*)DiMuDiTauInvMassFakeWeightRegionItself_->Clone();
  num->SetMarkerStyle(20);
  num->SetMarkerSize(1.);
  num->SetLineColor(kBlack);
  TGraphAsymmErrors *graph = new TGraphAsymmErrors(num->GetNbinsX());
  int npoints = 0;
  for (int i=1; i < DiMuDiTauInvMassFakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (DiMuDiTauInvMassFakeWeightEstimateFromD_->GetBinContent(i) > 0)
    { 
      double vNum = num->GetBinContent(i), vDenUp = DiMuDiTauInvMassFakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = DiMuDiTauInvMassFakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double vDen = DiMuDiTauInvMassFakeWeightEstimateFromD_->GetBinContent(i), wNum = num->GetBinWidth(i+1), wDen = num->GetBinWidth(i+1);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) / vDen;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) / vDen;
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
  graph->Set(npoints);
  graph->Draw("0P SAME");

  DiMuDiTauRatioCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRateEstimates/DiMuDiTauMassEstimate.png");
  DiMuDiTauRatioCanvas->Write();  


////////////////////////////////
// Ratio EtaMu1Di
///////////////////////////////
  TCanvas *EtaMu1RatioCanvas = new TCanvas("EtaMu1RatioCanvas", "", 800, 600);
  EtaMu1RatioCanvas->cd();
  TPad *EtaMu1plotpad = new TPad("EtaMu1plotpad", "top pad", 0.0, 0.21, 1.0, 1.0);
  EtaMu1plotpad->SetBottomMargin(0.04);
  EtaMu1plotpad->SetRightMargin(0.03);
  EtaMu1plotpad->Draw();
  TPad *EtaMu1ratiopad = new TPad("EtaMu1ratiopad", "bottom pad", 0.0, 0.0, 1.0, 0.21);
  EtaMu1ratiopad->SetTopMargin(0.06);
  EtaMu1ratiopad->SetRightMargin(0.03);
  EtaMu1ratiopad->SetBottomMargin(0.5);
  EtaMu1ratiopad->SetLeftMargin(0.16);
  EtaMu1ratiopad->SetTickx(1);
  EtaMu1ratiopad->SetTicky(1);
  EtaMu1ratiopad->Draw();
  TMultiGraph *EtaMu1mg = new TMultiGraph();
  TGraphAsymmErrors *EtaMu1CItselfgraph = new TGraphAsymmErrors(EtaFakeWeightEstimateFromD_->GetNbinsX());
  TGraphAsymmErrors *EtaMu1FromDgraph   = new TGraphAsymmErrors(EtaFakeWeightEstimateFromD_->GetNbinsX());
  EtaMu1FromDgraph->SetMarkerColor(kRed);
  EtaMu1FromDgraph->SetLineColor(kRed);
  int npoints = 0;
  EtaMu1plotpad->cd();
  for (int i=1; i < EtaFakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (EtaFakeWeightEstimateFromD_->GetBinContent(i) > 0)
    {
      double vDen = EtaFakeWeightEstimateFromD_->GetBinContent(i), vDenUp = EtaFakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = EtaFakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) ;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) ;
      std::cout << "\n\nPREV ERROR:" << EtaFakeWeightEstimateFromD_->GetBinError(i) << "\tDiffHigh=" << vDenDown-vDen << "\tDiffHigh=" << vDenUp-vDen << endl;
      std::cout << " vDenUp=" << vDenUp << " vDen=" << vDen << " vDenDown=" << vDenDown << std::endl;
      std::cout << "(vDenDown-vDen)*(vDenDown-vDen)=" << (vDenDown-vDen)*(vDenDown-vDen) << "  vDen + (vDenDown-vDen)*(vDenDown-vDen)=" << vDen + (vDenDown-vDen)*(vDenDown-vDen) << std::endl;
      std::cout << "(vDenUp  -vDen)*(vDenUp  -vDen)=" << (vDenUp  -vDen)*(vDenUp  -vDen) << "  vDen + (vDenUp  -vDen)*(vDenUp  -vDen)=" << vDen + (vDenUp  -vDen)*(vDenUp  -vDen) << std::endl;
      std::cout <<   "Before Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      ey_low = pow( (ey_low*ey_low) + EtaFakeWeightEstimateFromD_->GetBinContent(i) , 0.5);
      std::cout <<   "After  Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      double binWidth = EtaFakeWeightRegionItself_->GetBinWidth(i) /2.0;
      if (i ==1)
        binWidth = 0;
      EtaMu1CItselfgraph->SetPoint(npoints, EtaFakeWeightEstimateFromD_->GetBinCenter(i), EtaFakeWeightRegionItself_->GetBinContent(i));
      EtaMu1CItselfgraph->SetPointEXlow(npoints,  binWidth);
      EtaMu1CItselfgraph->SetPointEXhigh(npoints, binWidth);
      EtaMu1CItselfgraph->SetPointEYlow(npoints,  pow(EtaFakeWeightRegionItself_->GetBinContent(i), 0.5) );
      EtaMu1CItselfgraph->SetPointEYhigh(npoints, pow(EtaFakeWeightRegionItself_->GetBinContent(i), 0.5) );
      EtaMu1FromDgraph->SetPoint(npoints, EtaFakeWeightEstimateFromD_->GetBinCenter(i), EtaFakeWeightEstimateFromD_->GetBinContent(i));
      EtaMu1FromDgraph->SetPointEXlow(npoints,  binWidth);
      EtaMu1FromDgraph->SetPointEXhigh(npoints, binWidth);
      EtaMu1FromDgraph->SetPointEYlow(npoints,  ey_low );
      EtaMu1FromDgraph->SetPointEYhigh(npoints, ey_high);
    }//if
    else
    {
      EtaMu1FromDgraph->SetPoint(npoints, num->GetBinCenter(i), 0);
      EtaMu1FromDgraph->SetPointEXlow(npoints,  0);
      EtaMu1FromDgraph->SetPointEXhigh(npoints, 0);
      EtaMu1FromDgraph->SetPointEYlow(npoints,  0);
      EtaMu1FromDgraph->SetPointEYhigh(npoints, 0);
      EtaMu1CItselfgraph->SetPointEXlow(npoints,  0);
      EtaMu1CItselfgraph->SetPointEXhigh(npoints, 0);
      EtaMu1CItselfgraph->SetPointEYlow(npoints,  0);
      EtaMu1CItselfgraph->SetPointEYhigh(npoints, 0);
    }//ekse
    npoints++;
  }//for i
  EtaMu1mg->Add(EtaMu1FromDgraph);
  EtaMu1mg->Add(EtaMu1CItselfgraph);
  EtaMu1mg->Draw("AP");
  EtaMu1mg->GetXaxis()->SetLimits(-2.4,2.4);
  EtaMu1mg->GetXaxis()->SetLabelOffset(999);
  EtaMu1mg->GetYaxis()->SetTitle("Events");
  EtaMu1mg->GetYaxis()->SetTitleSize(0.05);
  EtaMu1mg->GetYaxis()->SetTitleOffset(0.2);
  CMS_lumi( EtaMu1plotpad, 4, 11);
  legend->Draw("SAME");

  EtaMu1ratiopad->cd();
  TH1F *ratiostaterr = (TH1F*)EtaFakeWeightRegionItself_->Clone();
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

  for (int i = 0; i <= EtaFakeWeightEstimateFromD_->GetNbinsX()+1; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (EtaFakeWeightEstimateFromD_->GetBinContent(i) > 1e-6)
    {
      double binerror = EtaFakeWeightRegionItself_->GetBinError(i) / EtaFakeWeightRegionItself_->GetBinContent(i);
      ratiostaterr->SetBinError(i, binerror);
    }//if
    else
      ratiostaterr->SetBinError(i, 999.);
  }//for

  ratiostaterr->SetXTitle("#eta(#mu_{1}) GeV");
  ratiostaterr->Draw("e2");
  TLine *ratiounity = new TLine(2.5,1,30,1);
  ratiounity->SetLineStyle(2);
  ratiounity->Draw("SAME");
  TH1F *num = (TH1F*)EtaFakeWeightRegionItself_->Clone();
  num->SetMarkerStyle(20);
  num->SetMarkerSize(1.);
  num->SetLineColor(kBlack);
  TGraphAsymmErrors *graph = new TGraphAsymmErrors(num->GetNbinsX());
  int npoints = 0;
  for (int i=1; i < EtaFakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (EtaFakeWeightEstimateFromD_->GetBinContent(i) > 0)
    { 
      double vNum = num->GetBinContent(i), vDenUp = EtaFakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = EtaFakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double vDen = EtaFakeWeightEstimateFromD_->GetBinContent(i), wNum = num->GetBinWidth(i+1), wDen = num->GetBinWidth(i+1);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) / vDen;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) / vDen;
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
  graph->Set(npoints);
  graph->Draw("0P SAME");

  EtaMu1RatioCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRateEstimates/EtaMu1Estimate.png");
  EtaMu1RatioCanvas->Write();  
  
////////////////////////////////
// Ratio PtMu1Di
///////////////////////////////
  TCanvas *PtMu1RatioCanvas = new TCanvas("PtMu1RatioCanvas", "", 800, 600);
  PtMu1RatioCanvas->cd();
  TPad *PtMu1plotpad = new TPad("PtMu1plotpad", "top pad", 0.0, 0.21, 1.0, 1.0);
  PtMu1plotpad->SetBottomMargin(0.04);
  PtMu1plotpad->SetRightMargin(0.03);
  PtMu1plotpad->Draw();
  TPad *PtMu1ratiopad = new TPad("PtMu1ratiopad", "bottom pad", 0.0, 0.0, 1.0, 0.21);
  PtMu1ratiopad->SetTopMargin(0.06);
  PtMu1ratiopad->SetRightMargin(0.03);
  PtMu1ratiopad->SetBottomMargin(0.5);
  PtMu1ratiopad->SetLeftMargin(0.16);
  PtMu1ratiopad->SetTickx(1);
  PtMu1ratiopad->SetTicky(1);
  PtMu1ratiopad->Draw();
  TMultiGraph *PtMu1mg = new TMultiGraph();
  TGraphAsymmErrors *PtMu1CItselfgraph = new TGraphAsymmErrors(PtMu1FakeWeightEstimateFromD_->GetNbinsX());
  TGraphAsymmErrors *PtMu1FromDgraph   = new TGraphAsymmErrors(PtMu1FakeWeightEstimateFromD_->GetNbinsX());
  PtMu1FromDgraph->SetMarkerColor(kRed);
  PtMu1FromDgraph->SetLineColor(kRed);
  int npoints = 0;
  PtMu1plotpad->cd();
  for (int i=1; i < PtMu1FakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtMu1FakeWeightEstimateFromD_->GetBinContent(i) > 0)
    {
      double vDen = PtMu1FakeWeightEstimateFromD_->GetBinContent(i), vDenUp = PtMu1FakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = PtMu1FakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) ;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) ;
      std::cout << "\n\nPREV ERROR:" << PtMu1FakeWeightEstimateFromD_->GetBinError(i) << "\tDiffHigh=" << vDenDown-vDen << "\tDiffHigh=" << vDenUp-vDen << endl;
      std::cout << " vDenUp=" << vDenUp << " vDen=" << vDen << " vDenDown=" << vDenDown << std::endl;
      std::cout << "(vDenDown-vDen)*(vDenDown-vDen)=" << (vDenDown-vDen)*(vDenDown-vDen) << "  vDen + (vDenDown-vDen)*(vDenDown-vDen)=" << vDen + (vDenDown-vDen)*(vDenDown-vDen) << std::endl;
      std::cout << "(vDenUp  -vDen)*(vDenUp  -vDen)=" << (vDenUp  -vDen)*(vDenUp  -vDen) << "  vDen + (vDenUp  -vDen)*(vDenUp  -vDen)=" << vDen + (vDenUp  -vDen)*(vDenUp  -vDen) << std::endl;
      std::cout <<   "Before Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      ey_low = pow( (ey_low*ey_low) + PtMu1FakeWeightEstimateFromD_->GetBinContent(i) , 0.5);
      std::cout <<   "After  Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      double binWidth = PtMu1FakeWeightRegionItself_->GetBinWidth(i) /2.0;
      if (i ==1)
        binWidth = 0;
      PtMu1CItselfgraph->SetPoint(npoints, PtMu1FakeWeightEstimateFromD_->GetBinCenter(i), PtMu1FakeWeightRegionItself_->GetBinContent(i));
      PtMu1CItselfgraph->SetPointEXlow(npoints,  binWidth);
      PtMu1CItselfgraph->SetPointEXhigh(npoints, binWidth);
      PtMu1CItselfgraph->SetPointEYlow(npoints,  pow(PtMu1FakeWeightRegionItself_->GetBinContent(i), 0.5) );
      PtMu1CItselfgraph->SetPointEYhigh(npoints, pow(PtMu1FakeWeightRegionItself_->GetBinContent(i), 0.5) );
      PtMu1FromDgraph->SetPoint(npoints, PtMu1FakeWeightEstimateFromD_->GetBinCenter(i), PtMu1FakeWeightEstimateFromD_->GetBinContent(i));
      PtMu1FromDgraph->SetPointEXlow(npoints,  binWidth);
      PtMu1FromDgraph->SetPointEXhigh(npoints, binWidth);
      PtMu1FromDgraph->SetPointEYlow(npoints,  ey_low );
      PtMu1FromDgraph->SetPointEYhigh(npoints, ey_high);
    }//if
    else
    {
      PtMu1FromDgraph->SetPoint(npoints, num->GetBinCenter(i), 0);
      PtMu1FromDgraph->SetPointEXlow(npoints,  0);
      PtMu1FromDgraph->SetPointEXhigh(npoints, 0);
      PtMu1FromDgraph->SetPointEYlow(npoints,  0);
      PtMu1FromDgraph->SetPointEYhigh(npoints, 0);
      PtMu1CItselfgraph->SetPointEXlow(npoints,  0);
      PtMu1CItselfgraph->SetPointEXhigh(npoints, 0);
      PtMu1CItselfgraph->SetPointEYlow(npoints,  0);
      PtMu1CItselfgraph->SetPointEYhigh(npoints, 0);
    }//ekse
    npoints++;
  }//for i
  PtMu1mg->Add(PtMu1FromDgraph);
  PtMu1mg->Add(PtMu1CItselfgraph);
  PtMu1mg->Draw("AP");
  PtMu1mg->GetXaxis()->SetLimits(0.0,300.0);
  PtMu1mg->GetXaxis()->SetLabelOffset(999);
  PtMu1mg->GetYaxis()->SetTitle("Events");
  PtMu1mg->GetYaxis()->SetTitleSize(0.05);
  PtMu1mg->GetYaxis()->SetTitleOffset(0.2);
  CMS_lumi( PtMu1plotpad, 4, 11);
  legend->Draw("SAME");

  PtMu1ratiopad->cd();
  TH1F *ratiostaterr = (TH1F*)PtMu1FakeWeightRegionItself_->Clone();
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

  for (int i = 0; i <= PtMu1FakeWeightEstimateFromD_->GetNbinsX()+1; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (PtMu1FakeWeightEstimateFromD_->GetBinContent(i) > 1e-6)
    {
      double binerror = PtMu1FakeWeightRegionItself_->GetBinError(i) / PtMu1FakeWeightRegionItself_->GetBinContent(i);
      ratiostaterr->SetBinError(i, binerror);
    }//if
    else
      ratiostaterr->SetBinError(i, 999.);
  }//for

  ratiostaterr->SetXTitle("p_{T}(#mu_{1}) GeV");
  ratiostaterr->Draw("e2");
  TLine *ratiounity = new TLine(2.5,1,30,1);
  ratiounity->SetLineStyle(2);
  ratiounity->Draw("SAME");
  TH1F *num = (TH1F*)PtMu1FakeWeightRegionItself_->Clone();
  num->SetMarkerStyle(20);
  num->SetMarkerSize(1.);
  num->SetLineColor(kBlack);
  TGraphAsymmErrors *graph = new TGraphAsymmErrors(num->GetNbinsX());
  int npoints = 0;
  for (int i=1; i < PtMu1FakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtMu1FakeWeightEstimateFromD_->GetBinContent(i) > 0)
    { 
      double vNum = num->GetBinContent(i), vDenUp = PtMu1FakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = PtMu1FakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double vDen = PtMu1FakeWeightEstimateFromD_->GetBinContent(i), wNum = num->GetBinWidth(i+1), wDen = num->GetBinWidth(i+1);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) / vDen;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) / vDen;
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
  graph->Set(npoints);
  graph->Draw("0P SAME");

  PtMu1RatioCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRateEstimates/PtMu1Estimate.png");
  PtMu1RatioCanvas->Write();  


////////////////////////////////
// Ratio PtMu3Di
///////////////////////////////
  TCanvas *PtMu3RatioCanvas = new TCanvas("PtMu3RatioCanvas", "", 800, 600);
  PtMu3RatioCanvas->cd();
  TPad *PtMu3plotpad = new TPad("PtMu3plotpad", "top pad", 0.0, 0.21, 1.0, 1.0);
  PtMu3plotpad->SetBottomMargin(0.04);
  PtMu3plotpad->SetRightMargin(0.03);
  PtMu3plotpad->Draw();
  TPad *PtMu3ratiopad = new TPad("PtMu3ratiopad", "bottom pad", 0.0, 0.0, 1.0, 0.21);
  PtMu3ratiopad->SetTopMargin(0.06);
  PtMu3ratiopad->SetRightMargin(0.03);
  PtMu3ratiopad->SetBottomMargin(0.5);
  PtMu3ratiopad->SetLeftMargin(0.16);
  PtMu3ratiopad->SetTickx(1);
  PtMu3ratiopad->SetTicky(1);
  PtMu3ratiopad->Draw();
  TMultiGraph *PtMu3mg = new TMultiGraph();
  TGraphAsymmErrors *PtMu3CItselfgraph = new TGraphAsymmErrors(PtMu3FakeWeightEstimateFromD_->GetNbinsX());
  TGraphAsymmErrors *PtMu3FromDgraph   = new TGraphAsymmErrors(PtMu3FakeWeightEstimateFromD_->GetNbinsX());
  PtMu3FromDgraph->SetMarkerColor(kRed);
  PtMu3FromDgraph->SetLineColor(kRed);
  int npoints = 0;
  PtMu3plotpad->cd();
  for (int i=1; i < PtMu3FakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtMu3FakeWeightEstimateFromD_->GetBinContent(i) > 0)
    {
      double vDen = PtMu3FakeWeightEstimateFromD_->GetBinContent(i), vDenUp = PtMu3FakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = PtMu3FakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) ;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) ;
      std::cout << "\n\nPREV ERROR:" << PtMu3FakeWeightEstimateFromD_->GetBinError(i) << "\tDiffHigh=" << vDenDown-vDen << "\tDiffHigh=" << vDenUp-vDen << endl;
      std::cout << " vDenUp=" << vDenUp << " vDen=" << vDen << " vDenDown=" << vDenDown << std::endl;
      std::cout << "(vDenDown-vDen)*(vDenDown-vDen)=" << (vDenDown-vDen)*(vDenDown-vDen) << "  vDen + (vDenDown-vDen)*(vDenDown-vDen)=" << vDen + (vDenDown-vDen)*(vDenDown-vDen) << std::endl;
      std::cout << "(vDenUp  -vDen)*(vDenUp  -vDen)=" << (vDenUp  -vDen)*(vDenUp  -vDen) << "  vDen + (vDenUp  -vDen)*(vDenUp  -vDen)=" << vDen + (vDenUp  -vDen)*(vDenUp  -vDen) << std::endl;
      std::cout <<   "Before Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      ey_low = pow( (ey_low*ey_low) + PtMu3FakeWeightEstimateFromD_->GetBinContent(i) , 0.5);
      std::cout <<   "After  Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      double binWidth = PtMu3FakeWeightRegionItself_->GetBinWidth(i) /2.0;
      if (i ==1)
        binWidth = 0;
      PtMu3CItselfgraph->SetPoint(npoints, PtMu3FakeWeightEstimateFromD_->GetBinCenter(i), PtMu3FakeWeightRegionItself_->GetBinContent(i));
      PtMu3CItselfgraph->SetPointEXlow(npoints,  binWidth);
      PtMu3CItselfgraph->SetPointEXhigh(npoints, binWidth);
      PtMu3CItselfgraph->SetPointEYlow(npoints,  pow(PtMu3FakeWeightRegionItself_->GetBinContent(i), 0.5) );
      PtMu3CItselfgraph->SetPointEYhigh(npoints, pow(PtMu3FakeWeightRegionItself_->GetBinContent(i), 0.5) );
      PtMu3FromDgraph->SetPoint(npoints, PtMu3FakeWeightEstimateFromD_->GetBinCenter(i), PtMu3FakeWeightEstimateFromD_->GetBinContent(i));
      PtMu3FromDgraph->SetPointEXlow(npoints,  binWidth);
      PtMu3FromDgraph->SetPointEXhigh(npoints, binWidth);
      PtMu3FromDgraph->SetPointEYlow(npoints,  ey_low );
      PtMu3FromDgraph->SetPointEYhigh(npoints, ey_high);
    }//if
    else
    {
      PtMu3FromDgraph->SetPoint(npoints, num->GetBinCenter(i), 0);
      PtMu3FromDgraph->SetPointEXlow(npoints,  0);
      PtMu3FromDgraph->SetPointEXhigh(npoints, 0);
      PtMu3FromDgraph->SetPointEYlow(npoints,  0);
      PtMu3FromDgraph->SetPointEYhigh(npoints, 0);
      PtMu3CItselfgraph->SetPointEXlow(npoints,  0);
      PtMu3CItselfgraph->SetPointEXhigh(npoints, 0);
      PtMu3CItselfgraph->SetPointEYlow(npoints,  0);
      PtMu3CItselfgraph->SetPointEYhigh(npoints, 0);
    }//ekse
    npoints++;
  }//for i
  PtMu3mg->Add(PtMu3FromDgraph);
  PtMu3mg->Add(PtMu3CItselfgraph);
  PtMu3mg->Draw("AP");
  PtMu3mg->GetXaxis()->SetLimits(0.,150.0);
  PtMu3mg->GetXaxis()->SetLabelOffset(999);
  PtMu3mg->GetYaxis()->SetTitle("Events");
  PtMu3mg->GetYaxis()->SetTitleSize(0.05);
  PtMu3mg->GetYaxis()->SetTitleOffset(0.2);
  CMS_lumi( PtMu3plotpad, 4, 11);
  legend->Draw("SAME");

  PtMu3ratiopad->cd();
  TH1F *ratiostaterr = (TH1F*)PtMu3FakeWeightRegionItself_->Clone();
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

  for (int i = 0; i <= PtMu3FakeWeightEstimateFromD_->GetNbinsX()+1; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (PtMu3FakeWeightEstimateFromD_->GetBinContent(i) > 1e-6)
    {
      double binerror = PtMu3FakeWeightRegionItself_->GetBinError(i) / PtMu3FakeWeightRegionItself_->GetBinContent(i);
      ratiostaterr->SetBinError(i, binerror);
    }//if
    else
      ratiostaterr->SetBinError(i, 999.);
  }//for

  ratiostaterr->SetXTitle("p_{T}(#tau_{#mu}) GeV");
  ratiostaterr->Draw("e2");
  TLine *ratiounity = new TLine(2.5,1,30,1);
  ratiounity->SetLineStyle(2);
  ratiounity->Draw("SAME");
  TH1F *num = (TH1F*)PtMu3FakeWeightRegionItself_->Clone();
  num->SetMarkerStyle(20);
  num->SetMarkerSize(1.);
  num->SetLineColor(kBlack);
  TGraphAsymmErrors *graph = new TGraphAsymmErrors(num->GetNbinsX());
  int npoints = 0;
  for (int i=1; i < PtMu3FakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtMu3FakeWeightEstimateFromD_->GetBinContent(i) > 0)
    { 
      double vNum = num->GetBinContent(i), vDenUp = PtMu3FakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = PtMu3FakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double vDen = PtMu3FakeWeightEstimateFromD_->GetBinContent(i), wNum = num->GetBinWidth(i+1), wDen = num->GetBinWidth(i+1);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) / vDen;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) / vDen;
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
  graph->Set(npoints);
  graph->Draw("0P SAME");

  PtMu3RatioCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRateEstimates/PtMu3Estimate.png");
  PtMu3RatioCanvas->Write();  

////////////////////////////////
// Ratio PtTauDi
///////////////////////////////
  TCanvas *PtTauRatioCanvas = new TCanvas("PtTauRatioCanvas", "", 800, 600);
  PtTauRatioCanvas->cd();
  TPad *PtTauplotpad = new TPad("PtTauplotpad", "top pad", 0.0, 0.21, 1.0, 1.0);
  PtTauplotpad->SetBottomMargin(0.04);
  PtTauplotpad->SetRightMargin(0.03);
  PtTauplotpad->Draw();
  TPad *PtTauratiopad = new TPad("PtTauratiopad", "bottom pad", 0.0, 0.0, 1.0, 0.21);
  PtTauratiopad->SetTopMargin(0.06);
  PtTauratiopad->SetRightMargin(0.03);
  PtTauratiopad->SetBottomMargin(0.5);
  PtTauratiopad->SetLeftMargin(0.16);
  PtTauratiopad->SetTickx(1);
  PtTauratiopad->SetTicky(1);
  PtTauratiopad->Draw();
  TMultiGraph *PtTaumg = new TMultiGraph();
  TGraphAsymmErrors *PtTauCItselfgraph = new TGraphAsymmErrors(PtTauFakeWeightEstimateFromD_->GetNbinsX());
  TGraphAsymmErrors *PtTauFromDgraph   = new TGraphAsymmErrors(PtTauFakeWeightEstimateFromD_->GetNbinsX());
  PtTauFromDgraph->SetMarkerColor(kRed);
  PtTauFromDgraph->SetLineColor(kRed);
  int npoints = 0;
  PtTauplotpad->cd();
  for (int i=1; i < PtTauFakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtTauFakeWeightEstimateFromD_->GetBinContent(i) > 0)
    {
      double vDen = PtTauFakeWeightEstimateFromD_->GetBinContent(i), vDenUp = PtTauFakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = PtTauFakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) ;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) ;
      std::cout << "\n\nPREV ERROR:" << PtTauFakeWeightEstimateFromD_->GetBinError(i) << "\tDiffHigh=" << vDenDown-vDen << "\tDiffHigh=" << vDenUp-vDen << endl;
      std::cout << " vDenUp=" << vDenUp << " vDen=" << vDen << " vDenDown=" << vDenDown << std::endl;
      std::cout << "(vDenDown-vDen)*(vDenDown-vDen)=" << (vDenDown-vDen)*(vDenDown-vDen) << "  vDen + (vDenDown-vDen)*(vDenDown-vDen)=" << vDen + (vDenDown-vDen)*(vDenDown-vDen) << std::endl;
      std::cout << "(vDenUp  -vDen)*(vDenUp  -vDen)=" << (vDenUp  -vDen)*(vDenUp  -vDen) << "  vDen + (vDenUp  -vDen)*(vDenUp  -vDen)=" << vDen + (vDenUp  -vDen)*(vDenUp  -vDen) << std::endl;
      std::cout <<   "Before Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      ey_low = pow( (ey_low*ey_low) + PtTauFakeWeightEstimateFromD_->GetBinContent(i) , 0.5);
      std::cout <<   "After  Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      double binWidth = PtTauFakeWeightRegionItself_->GetBinWidth(i) /2.0;
      if (i ==1)
        binWidth = 0;
      PtTauCItselfgraph->SetPoint(npoints, PtTauFakeWeightEstimateFromD_->GetBinCenter(i), PtTauFakeWeightRegionItself_->GetBinContent(i));
      PtTauCItselfgraph->SetPointEXlow(npoints,  binWidth);
      PtTauCItselfgraph->SetPointEXhigh(npoints, binWidth);
      PtTauCItselfgraph->SetPointEYlow(npoints,  pow(PtTauFakeWeightRegionItself_->GetBinContent(i), 0.5) );
      PtTauCItselfgraph->SetPointEYhigh(npoints, pow(PtTauFakeWeightRegionItself_->GetBinContent(i), 0.5) );
      PtTauFromDgraph->SetPoint(npoints, PtTauFakeWeightEstimateFromD_->GetBinCenter(i), PtTauFakeWeightEstimateFromD_->GetBinContent(i));
      PtTauFromDgraph->SetPointEXlow(npoints,  binWidth);
      PtTauFromDgraph->SetPointEXhigh(npoints, binWidth);
      PtTauFromDgraph->SetPointEYlow(npoints,  ey_low );
      PtTauFromDgraph->SetPointEYhigh(npoints, ey_high);
    }//if
    else
    {
      PtTauFromDgraph->SetPoint(npoints, num->GetBinCenter(i), 0);
      PtTauFromDgraph->SetPointEXlow(npoints,  0);
      PtTauFromDgraph->SetPointEXhigh(npoints, 0);
      PtTauFromDgraph->SetPointEYlow(npoints,  0);
      PtTauFromDgraph->SetPointEYhigh(npoints, 0);
      PtTauCItselfgraph->SetPointEXlow(npoints,  0);
      PtTauCItselfgraph->SetPointEXhigh(npoints, 0);
      PtTauCItselfgraph->SetPointEYlow(npoints,  0);
      PtTauCItselfgraph->SetPointEYhigh(npoints, 0);
    }//ekse
    npoints++;
  }//for i
  PtTaumg->Add(PtTauFromDgraph);
  PtTaumg->Add(PtTauCItselfgraph);
  PtTaumg->Draw("AP");
  PtTaumg->GetXaxis()->SetLimits(10.,150.0);
  PtTaumg->GetXaxis()->SetLabelOffset(999);
  PtTaumg->GetYaxis()->SetTitle("Events");
  PtTaumg->GetYaxis()->SetTitleSize(0.05);
  PtTaumg->GetYaxis()->SetTitleOffset(0.2);
  CMS_lumi( PtTauplotpad, 4, 11);
  legend->Draw("SAME");

  PtTauratiopad->cd();
  TH1F *ratiostaterr = (TH1F*)PtTauFakeWeightRegionItself_->Clone();
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

  for (int i = 0; i <= PtTauFakeWeightEstimateFromD_->GetNbinsX()+1; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (PtTauFakeWeightEstimateFromD_->GetBinContent(i) > 1e-6)
    {
      double binerror = PtTauFakeWeightRegionItself_->GetBinError(i) / PtTauFakeWeightRegionItself_->GetBinContent(i);
      ratiostaterr->SetBinError(i, binerror);
    }//if
    else
      ratiostaterr->SetBinError(i, 999.);
  }//for

  ratiostaterr->SetXTitle("p_{T}(#tau_{H}) GeV");
  ratiostaterr->Draw("e2");
  TLine *ratiounity = new TLine(2.5,1,30,1);
  ratiounity->SetLineStyle(2);
  ratiounity->Draw("SAME");
  TH1F *num = (TH1F*)PtTauFakeWeightRegionItself_->Clone();
  num->SetMarkerStyle(20);
  num->SetMarkerSize(1.);
  num->SetLineColor(kBlack);
  TGraphAsymmErrors *graph = new TGraphAsymmErrors(num->GetNbinsX());
  int npoints = 0;
  for (int i=1; i < PtTauFakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtTauFakeWeightEstimateFromD_->GetBinContent(i) > 0)
    { 
      double vNum = num->GetBinContent(i), vDenUp = PtTauFakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = PtTauFakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double vDen = PtTauFakeWeightEstimateFromD_->GetBinContent(i), wNum = num->GetBinWidth(i+1), wDen = num->GetBinWidth(i+1);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) / vDen;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) / vDen;
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
  graph->Set(npoints);
  graph->Draw("0P SAME");

  PtTauRatioCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRateEstimates/PtTauEstimate.png");
  PtTauRatioCanvas->Write();  

////////////////////////////////
// Ratio PtTauDM0Di
///////////////////////////////
  TCanvas *PtTauDM0RatioCanvas = new TCanvas("PtTauDM0RatioCanvas", "", 800, 600);
  PtTauDM0RatioCanvas->cd();
  TPad *PtTauDM0plotpad = new TPad("PtTauDM0plotpad", "top pad", 0.0, 0.21, 1.0, 1.0);
  PtTauDM0plotpad->SetBottomMargin(0.04);
  PtTauDM0plotpad->SetRightMargin(0.03);
  PtTauDM0plotpad->Draw();
  TPad *PtTauDM0ratiopad = new TPad("PtTauDM0ratiopad", "bottom pad", 0.0, 0.0, 1.0, 0.21);
  PtTauDM0ratiopad->SetTopMargin(0.06);
  PtTauDM0ratiopad->SetRightMargin(0.03);
  PtTauDM0ratiopad->SetBottomMargin(0.5);
  PtTauDM0ratiopad->SetLeftMargin(0.16);
  PtTauDM0ratiopad->SetTickx(1);
  PtTauDM0ratiopad->SetTicky(1);
  PtTauDM0ratiopad->Draw();
  TMultiGraph *PtTauDM0mg = new TMultiGraph();
  TGraphAsymmErrors *PtTauDM0CItselfgraph = new TGraphAsymmErrors(PtTauDM0FakeWeightEstimateFromD_->GetNbinsX());
  TGraphAsymmErrors *PtTauDM0FromDgraph   = new TGraphAsymmErrors(PtTauDM0FakeWeightEstimateFromD_->GetNbinsX());
  PtTauDM0FromDgraph->SetMarkerColor(kRed);
  PtTauDM0FromDgraph->SetLineColor(kRed);
  int npoints = 0;
  PtTauDM0plotpad->cd();
  for (int i=1; i < PtTauDM0FakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtTauDM0FakeWeightEstimateFromD_->GetBinContent(i) > 0)
    {
      double vDen = PtTauDM0FakeWeightEstimateFromD_->GetBinContent(i), vDenUp = PtTauDM0FakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = PtTauDM0FakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) ;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) ;
      std::cout << "\n\nPREV ERROR:" << PtTauDM0FakeWeightEstimateFromD_->GetBinError(i) << "\tDiffHigh=" << vDenDown-vDen << "\tDiffHigh=" << vDenUp-vDen << endl;
      std::cout << " vDenUp=" << vDenUp << " vDen=" << vDen << " vDenDown=" << vDenDown << std::endl;
      std::cout << "(vDenDown-vDen)*(vDenDown-vDen)=" << (vDenDown-vDen)*(vDenDown-vDen) << "  vDen + (vDenDown-vDen)*(vDenDown-vDen)=" << vDen + (vDenDown-vDen)*(vDenDown-vDen) << std::endl;
      std::cout << "(vDenUp  -vDen)*(vDenUp  -vDen)=" << (vDenUp  -vDen)*(vDenUp  -vDen) << "  vDen + (vDenUp  -vDen)*(vDenUp  -vDen)=" << vDen + (vDenUp  -vDen)*(vDenUp  -vDen) << std::endl;
      std::cout <<   "Before Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      ey_low = pow( (ey_low*ey_low) + PtTauDM0FakeWeightEstimateFromD_->GetBinContent(i) , 0.5);
      std::cout <<   "After  Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      double binWidth = PtTauDM0FakeWeightRegionItself_->GetBinWidth(i) /2.0;
      if (i ==1)
        binWidth = 0;
      PtTauDM0CItselfgraph->SetPoint(npoints, PtTauDM0FakeWeightEstimateFromD_->GetBinCenter(i), PtTauDM0FakeWeightRegionItself_->GetBinContent(i));
      PtTauDM0CItselfgraph->SetPointEXlow(npoints,  binWidth);
      PtTauDM0CItselfgraph->SetPointEXhigh(npoints, binWidth);
      PtTauDM0CItselfgraph->SetPointEYlow(npoints,  pow(PtTauDM0FakeWeightRegionItself_->GetBinContent(i), 0.5) );
      PtTauDM0CItselfgraph->SetPointEYhigh(npoints, pow(PtTauDM0FakeWeightRegionItself_->GetBinContent(i), 0.5) );
      PtTauDM0FromDgraph->SetPoint(npoints, PtTauDM0FakeWeightEstimateFromD_->GetBinCenter(i), PtTauDM0FakeWeightEstimateFromD_->GetBinContent(i));
      PtTauDM0FromDgraph->SetPointEXlow(npoints,  binWidth);
      PtTauDM0FromDgraph->SetPointEXhigh(npoints, binWidth);
      PtTauDM0FromDgraph->SetPointEYlow(npoints,  ey_low );
      PtTauDM0FromDgraph->SetPointEYhigh(npoints, ey_high);
    }//if
    else
    {
      PtTauDM0FromDgraph->SetPoint(npoints, num->GetBinCenter(i), 0);
      PtTauDM0FromDgraph->SetPointEXlow(npoints,  0);
      PtTauDM0FromDgraph->SetPointEXhigh(npoints, 0);
      PtTauDM0FromDgraph->SetPointEYlow(npoints,  0);
      PtTauDM0FromDgraph->SetPointEYhigh(npoints, 0);
      PtTauDM0CItselfgraph->SetPointEXlow(npoints,  0);
      PtTauDM0CItselfgraph->SetPointEXhigh(npoints, 0);
      PtTauDM0CItselfgraph->SetPointEYlow(npoints,  0);
      PtTauDM0CItselfgraph->SetPointEYhigh(npoints, 0);
    }//ekse
    npoints++;
  }//for i
  PtTauDM0mg->Add(PtTauDM0FromDgraph);
  PtTauDM0mg->Add(PtTauDM0CItselfgraph);
  PtTauDM0mg->Draw("AP");
  PtTauDM0mg->GetXaxis()->SetLimits(0.,150.0);
  PtTauDM0mg->GetXaxis()->SetLabelOffset(999);
  PtTauDM0mg->GetYaxis()->SetTitle("Events");
  PtTauDM0mg->GetYaxis()->SetTitleSize(0.05);
  PtTauDM0mg->GetYaxis()->SetTitleOffset(0.2);
  CMS_lumi( PtTauDM0plotpad, 4, 11);
  legend->Draw("SAME");

  PtTauDM0ratiopad->cd();
  TH1F *ratiostaterr = (TH1F*)PtTauDM0FakeWeightRegionItself_->Clone();
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

  for (int i = 0; i <= PtTauDM0FakeWeightEstimateFromD_->GetNbinsX()+1; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (PtTauDM0FakeWeightEstimateFromD_->GetBinContent(i) > 1e-6)
    {
      double binerror = PtTauDM0FakeWeightRegionItself_->GetBinError(i) / PtTauDM0FakeWeightRegionItself_->GetBinContent(i);
      ratiostaterr->SetBinError(i, binerror);
    }//if
    else
      ratiostaterr->SetBinError(i, 999.);
  }//for

  ratiostaterr->SetXTitle("p_{T}(#tau_{H}) DM0 GeV");
  ratiostaterr->Draw("e2");
  TLine *ratiounity = new TLine(2.5,1,30,1);
  ratiounity->SetLineStyle(2);
  ratiounity->Draw("SAME");
  TH1F *num = (TH1F*)PtTauDM0FakeWeightRegionItself_->Clone();
  num->SetMarkerStyle(20);
  num->SetMarkerSize(1.);
  num->SetLineColor(kBlack);
  TGraphAsymmErrors *graph = new TGraphAsymmErrors(num->GetNbinsX());
  int npoints = 0;
  for (int i=1; i < PtTauDM0FakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtTauDM0FakeWeightEstimateFromD_->GetBinContent(i) > 0)
    { 
      double vNum = num->GetBinContent(i), vDenUp = PtTauDM0FakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = PtTauDM0FakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double vDen = PtTauDM0FakeWeightEstimateFromD_->GetBinContent(i), wNum = num->GetBinWidth(i+1), wDen = num->GetBinWidth(i+1);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) / vDen;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) / vDen;
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
  graph->Set(npoints);
  graph->Draw("0P SAME");

  PtTauDM0RatioCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRateEstimates/PtTauDM0Estimate.png");
  PtTauDM0RatioCanvas->Write();  

////////////////////////////////
// Ratio PtTauDM1Di
///////////////////////////////
  TCanvas *PtTauDM1RatioCanvas = new TCanvas("PtTauDM1RatioCanvas", "", 800, 600);
  PtTauDM1RatioCanvas->cd();
  TPad *PtTauDM1plotpad = new TPad("PtTauDM1plotpad", "top pad", 0.0, 0.21, 1.0, 1.0);
  PtTauDM1plotpad->SetBottomMargin(0.04);
  PtTauDM1plotpad->SetRightMargin(0.03);
  PtTauDM1plotpad->Draw();
  TPad *PtTauDM1ratiopad = new TPad("PtTauDM1ratiopad", "bottom pad", 0.0, 0.0, 1.0, 0.21);
  PtTauDM1ratiopad->SetTopMargin(0.06);
  PtTauDM1ratiopad->SetRightMargin(0.03);
  PtTauDM1ratiopad->SetBottomMargin(0.5);
  PtTauDM1ratiopad->SetLeftMargin(0.16);
  PtTauDM1ratiopad->SetTickx(1);
  PtTauDM1ratiopad->SetTicky(1);
  PtTauDM1ratiopad->Draw();
  TMultiGraph *PtTauDM1mg = new TMultiGraph();
  TGraphAsymmErrors *PtTauDM1CItselfgraph = new TGraphAsymmErrors(PtTauDM1FakeWeightEstimateFromD_->GetNbinsX());
  TGraphAsymmErrors *PtTauDM1FromDgraph   = new TGraphAsymmErrors(PtTauDM1FakeWeightEstimateFromD_->GetNbinsX());
  PtTauDM1FromDgraph->SetMarkerColor(kRed);
  PtTauDM1FromDgraph->SetLineColor(kRed);
  int npoints = 0;
  PtTauDM1plotpad->cd();
  for (int i=1; i < PtTauDM1FakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtTauDM1FakeWeightEstimateFromD_->GetBinContent(i) > 0)
    {
      double vDen = PtTauDM1FakeWeightEstimateFromD_->GetBinContent(i), vDenUp = PtTauDM1FakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = PtTauDM1FakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) ;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) ;
      std::cout << "\n\nPREV ERROR:" << PtTauDM1FakeWeightEstimateFromD_->GetBinError(i) << "\tDiffHigh=" << vDenDown-vDen << "\tDiffHigh=" << vDenUp-vDen << endl;
      std::cout << " vDenUp=" << vDenUp << " vDen=" << vDen << " vDenDown=" << vDenDown << std::endl;
      std::cout << "(vDenDown-vDen)*(vDenDown-vDen)=" << (vDenDown-vDen)*(vDenDown-vDen) << "  vDen + (vDenDown-vDen)*(vDenDown-vDen)=" << vDen + (vDenDown-vDen)*(vDenDown-vDen) << std::endl;
      std::cout << "(vDenUp  -vDen)*(vDenUp  -vDen)=" << (vDenUp  -vDen)*(vDenUp  -vDen) << "  vDen + (vDenUp  -vDen)*(vDenUp  -vDen)=" << vDen + (vDenUp  -vDen)*(vDenUp  -vDen) << std::endl;
      std::cout <<   "Before Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      ey_low = pow( (ey_low*ey_low) + PtTauDM1FakeWeightEstimateFromD_->GetBinContent(i) , 0.5);
      std::cout <<   "After  Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      double binWidth = PtTauDM1FakeWeightRegionItself_->GetBinWidth(i) /2.0;
      if (i ==1)
        binWidth = 0;
      PtTauDM1CItselfgraph->SetPoint(npoints, PtTauDM1FakeWeightEstimateFromD_->GetBinCenter(i), PtTauDM1FakeWeightRegionItself_->GetBinContent(i));
      PtTauDM1CItselfgraph->SetPointEXlow(npoints,  binWidth);
      PtTauDM1CItselfgraph->SetPointEXhigh(npoints, binWidth);
      PtTauDM1CItselfgraph->SetPointEYlow(npoints,  pow(PtTauDM1FakeWeightRegionItself_->GetBinContent(i), 0.5) );
      PtTauDM1CItselfgraph->SetPointEYhigh(npoints, pow(PtTauDM1FakeWeightRegionItself_->GetBinContent(i), 0.5) );
      PtTauDM1FromDgraph->SetPoint(npoints, PtTauDM1FakeWeightEstimateFromD_->GetBinCenter(i), PtTauDM1FakeWeightEstimateFromD_->GetBinContent(i));
      PtTauDM1FromDgraph->SetPointEXlow(npoints,  binWidth);
      PtTauDM1FromDgraph->SetPointEXhigh(npoints, binWidth);
      PtTauDM1FromDgraph->SetPointEYlow(npoints,  ey_low );
      PtTauDM1FromDgraph->SetPointEYhigh(npoints, ey_high);
    }//if
    else
    {
      PtTauDM1FromDgraph->SetPoint(npoints, num->GetBinCenter(i), 0);
      PtTauDM1FromDgraph->SetPointEXlow(npoints,  0);
      PtTauDM1FromDgraph->SetPointEXhigh(npoints, 0);
      PtTauDM1FromDgraph->SetPointEYlow(npoints,  0);
      PtTauDM1FromDgraph->SetPointEYhigh(npoints, 0);
      PtTauDM1CItselfgraph->SetPointEXlow(npoints,  0);
      PtTauDM1CItselfgraph->SetPointEXhigh(npoints, 0);
      PtTauDM1CItselfgraph->SetPointEYlow(npoints,  0);
      PtTauDM1CItselfgraph->SetPointEYhigh(npoints, 0);
    }//ekse
    npoints++;
  }//for i
  PtTauDM1mg->Add(PtTauDM1FromDgraph);
  PtTauDM1mg->Add(PtTauDM1CItselfgraph);
  PtTauDM1mg->Draw("AP");
  PtTauDM1mg->GetXaxis()->SetLimits(0.,150.0);
  PtTauDM1mg->GetXaxis()->SetLabelOffset(999);
  PtTauDM1mg->GetYaxis()->SetTitle("Events");
  PtTauDM1mg->GetYaxis()->SetTitleSize(0.05);
  PtTauDM1mg->GetYaxis()->SetTitleOffset(0.2);
  CMS_lumi( PtTauDM1plotpad, 4, 11);
  legend->Draw("SAME");

  PtTauDM1ratiopad->cd();
  TH1F *ratiostaterr = (TH1F*)PtTauDM1FakeWeightRegionItself_->Clone();
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

  for (int i = 0; i <= PtTauDM1FakeWeightEstimateFromD_->GetNbinsX()+1; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (PtTauDM1FakeWeightEstimateFromD_->GetBinContent(i) > 1e-6)
    {
      double binerror = PtTauDM1FakeWeightRegionItself_->GetBinError(i) / PtTauDM1FakeWeightRegionItself_->GetBinContent(i);
      ratiostaterr->SetBinError(i, binerror);
    }//if
    else
      ratiostaterr->SetBinError(i, 999.);
  }//for

  ratiostaterr->SetXTitle("p_{T}(#tau_{H}) DM1 GeV");
  ratiostaterr->Draw("e2");
  TLine *ratiounity = new TLine(2.5,1,30,1);
  ratiounity->SetLineStyle(2);
  ratiounity->Draw("SAME");
  TH1F *num = (TH1F*)PtTauDM1FakeWeightRegionItself_->Clone();
  num->SetMarkerStyle(20);
  num->SetMarkerSize(1.);
  num->SetLineColor(kBlack);
  TGraphAsymmErrors *graph = new TGraphAsymmErrors(num->GetNbinsX());
  int npoints = 0;
  for (int i=1; i < PtTauDM1FakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtTauDM1FakeWeightEstimateFromD_->GetBinContent(i) > 0)
    { 
      double vNum = num->GetBinContent(i), vDenUp = PtTauDM1FakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = PtTauDM1FakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double vDen = PtTauDM1FakeWeightEstimateFromD_->GetBinContent(i), wNum = num->GetBinWidth(i+1), wDen = num->GetBinWidth(i+1);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) / vDen;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) / vDen;
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
  graph->Set(npoints);
  graph->Draw("0P SAME");

  PtTauDM1RatioCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRateEstimates/PtTauDM1Estimate.png");
  PtTauDM1RatioCanvas->Write();  

////////////////////////////////
// Ratio PtTauDM10Di
///////////////////////////////
  TCanvas *PtTauDM10RatioCanvas = new TCanvas("PtTauDM10RatioCanvas", "", 800, 600);
  PtTauDM10RatioCanvas->cd();
  TPad *PtTauDM10plotpad = new TPad("PtTauDM10plotpad", "top pad", 0.0, 0.21, 1.0, 1.0);
  PtTauDM10plotpad->SetBottomMargin(0.04);
  PtTauDM10plotpad->SetRightMargin(0.03);
  PtTauDM10plotpad->Draw();
  TPad *PtTauDM10ratiopad = new TPad("PtTauDM10ratiopad", "bottom pad", 0.0, 0.0, 1.0, 0.21);
  PtTauDM10ratiopad->SetTopMargin(0.06);
  PtTauDM10ratiopad->SetRightMargin(0.03);
  PtTauDM10ratiopad->SetBottomMargin(0.5);
  PtTauDM10ratiopad->SetLeftMargin(0.16);
  PtTauDM10ratiopad->SetTickx(1);
  PtTauDM10ratiopad->SetTicky(1);
  PtTauDM10ratiopad->Draw();
  TMultiGraph *PtTauDM10mg = new TMultiGraph();
  TGraphAsymmErrors *PtTauDM10CItselfgraph = new TGraphAsymmErrors(PtTauDM10FakeWeightEstimateFromD_->GetNbinsX());
  TGraphAsymmErrors *PtTauDM10FromDgraph   = new TGraphAsymmErrors(PtTauDM10FakeWeightEstimateFromD_->GetNbinsX());
  PtTauDM10FromDgraph->SetMarkerColor(kRed);
  PtTauDM10FromDgraph->SetLineColor(kRed);
  int npoints = 0;
  PtTauDM10plotpad->cd();
  for (int i=1; i < PtTauDM10FakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtTauDM10FakeWeightEstimateFromD_->GetBinContent(i) > 0)
    {
      double vDen = PtTauDM10FakeWeightEstimateFromD_->GetBinContent(i), vDenUp = PtTauDM10FakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = PtTauDM10FakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) ;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) ;
      std::cout << "\n\nPREV ERROR:" << PtTauDM10FakeWeightEstimateFromD_->GetBinError(i) << "\tDiffHigh=" << vDenDown-vDen << "\tDiffHigh=" << vDenUp-vDen << endl;
      std::cout << " vDenUp=" << vDenUp << " vDen=" << vDen << " vDenDown=" << vDenDown << std::endl;
      std::cout << "(vDenDown-vDen)*(vDenDown-vDen)=" << (vDenDown-vDen)*(vDenDown-vDen) << "  vDen + (vDenDown-vDen)*(vDenDown-vDen)=" << vDen + (vDenDown-vDen)*(vDenDown-vDen) << std::endl;
      std::cout << "(vDenUp  -vDen)*(vDenUp  -vDen)=" << (vDenUp  -vDen)*(vDenUp  -vDen) << "  vDen + (vDenUp  -vDen)*(vDenUp  -vDen)=" << vDen + (vDenUp  -vDen)*(vDenUp  -vDen) << std::endl;
      std::cout <<   "Before Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      ey_low = pow( (ey_low*ey_low) + PtTauDM10FakeWeightEstimateFromD_->GetBinContent(i) , 0.5);
      std::cout <<   "After  Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      double binWidth = PtTauDM10FakeWeightRegionItself_->GetBinWidth(i) /2.0;
      if (i ==1)
        continue;
//        binWidth = 0;
      PtTauDM10CItselfgraph->SetPoint(npoints, PtTauDM10FakeWeightEstimateFromD_->GetBinCenter(i), PtTauDM10FakeWeightRegionItself_->GetBinContent(i));
      PtTauDM10CItselfgraph->SetPointEXlow(npoints,  binWidth);
      PtTauDM10CItselfgraph->SetPointEXhigh(npoints, binWidth);
      PtTauDM10CItselfgraph->SetPointEYlow(npoints,  pow(PtTauDM10FakeWeightRegionItself_->GetBinContent(i), 0.5) );
      PtTauDM10CItselfgraph->SetPointEYhigh(npoints, pow(PtTauDM10FakeWeightRegionItself_->GetBinContent(i), 0.5) );
      PtTauDM10FromDgraph->SetPoint(npoints, PtTauDM10FakeWeightEstimateFromD_->GetBinCenter(i), PtTauDM10FakeWeightEstimateFromD_->GetBinContent(i));
      PtTauDM10FromDgraph->SetPointEXlow(npoints,  binWidth);
      PtTauDM10FromDgraph->SetPointEXhigh(npoints, binWidth);
      PtTauDM10FromDgraph->SetPointEYlow(npoints,  ey_low );
      PtTauDM10FromDgraph->SetPointEYhigh(npoints, ey_high);
    }//if
    else
    {
      PtTauDM10FromDgraph->SetPoint(npoints, num->GetBinCenter(i), 0);
      PtTauDM10FromDgraph->SetPointEXlow(npoints,  0);
      PtTauDM10FromDgraph->SetPointEXhigh(npoints, 0);
      PtTauDM10FromDgraph->SetPointEYlow(npoints,  0);
      PtTauDM10FromDgraph->SetPointEYhigh(npoints, 0);
      PtTauDM10CItselfgraph->SetPointEXlow(npoints,  0);
      PtTauDM10CItselfgraph->SetPointEXhigh(npoints, 0);
      PtTauDM10CItselfgraph->SetPointEYlow(npoints,  0);
      PtTauDM10CItselfgraph->SetPointEYhigh(npoints, 0);
    }//ekse
    npoints++;
  }//for i
  PtTauDM10mg->Add(PtTauDM10FromDgraph);
  PtTauDM10mg->Add(PtTauDM10CItselfgraph);
  PtTauDM10mg->Draw("0P SAME");
  PtTauDM10mg->GetXaxis()->SetLimits(0.,150.0);
  PtTauDM10mg->GetXaxis()->SetLabelOffset(999);
  PtTauDM10mg->GetYaxis()->SetTitle("Events");
  PtTauDM10mg->GetYaxis()->SetTitleSize(0.05);
  PtTauDM10mg->GetYaxis()->SetTitleOffset(0.2);
  CMS_lumi( PtTauDM10plotpad, 4, 11);
  legend->Draw("SAME");

  PtTauDM10ratiopad->cd();
  TH1F *ratiostaterr = (TH1F*)PtTauDM10FakeWeightRegionItself_->Clone();
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

  for (int i = 0; i <= PtTauDM10FakeWeightEstimateFromD_->GetNbinsX()+1; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (PtTauDM10FakeWeightEstimateFromD_->GetBinContent(i) > 1e-6)
    {
      double binerror = PtTauDM10FakeWeightRegionItself_->GetBinError(i) / PtTauDM10FakeWeightRegionItself_->GetBinContent(i);
      ratiostaterr->SetBinError(i, binerror);
    }//if
    else
      ratiostaterr->SetBinError(i, 999.);
  }//for

  ratiostaterr->SetXTitle("p_{T}(#tau_{H}) DM10 GeV");
  ratiostaterr->Draw("e2");
  TLine *ratiounity = new TLine(2.5,1,30,1);
  ratiounity->SetLineStyle(2);
  ratiounity->Draw("SAME");
  TH1F *num = (TH1F*)PtTauDM10FakeWeightRegionItself_->Clone();
  num->SetMarkerStyle(20);
  num->SetMarkerSize(1.);
  num->SetLineColor(kBlack);
  TGraphAsymmErrors *graph = new TGraphAsymmErrors(num->GetNbinsX());
  int npoints = 0;
  for (int i=1; i < PtTauDM10FakeWeightRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtTauDM10FakeWeightEstimateFromD_->GetBinContent(i) > 0)
    { 
      double vNum = num->GetBinContent(i), vDenUp = PtTauDM10FakeWeightEstimateFromD_UP_->GetBinContent(i), vDenDown = PtTauDM10FakeWeightEstimateFromD_DOWN_->GetBinContent(i);
      double vDen = PtTauDM10FakeWeightEstimateFromD_->GetBinContent(i), wNum = num->GetBinWidth(i+1), wDen = num->GetBinWidth(i+1);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) / vDen;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) / vDen;
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
  graph->Set(npoints);
  graph->Draw("0P SAME");

  PtTauDM10RatioCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRateEstimates/PtTauDM10Estimate.png");
  PtTauDM10RatioCanvas->Write();  

////////////////////////////////
// Ratio PtTauDM0FakeRateBinningDi
///////////////////////////////
  TCanvas *PtTauDM0FakeRateBinningRatioCanvas = new TCanvas("PtTauDM0FakeRateBinningRatioCanvas", "", 800, 600);
  PtTauDM0FakeRateBinningRatioCanvas->cd();
  TPad *PtTauDM0FakeRateBinningplotpad = new TPad("PtTauDM0FakeRateBinningplotpad", "top pad", 0.0, 0.21, 1.0, 1.0);
  PtTauDM0FakeRateBinningplotpad->SetBottomMargin(0.04);
  PtTauDM0FakeRateBinningplotpad->SetRightMargin(0.03);
  PtTauDM0FakeRateBinningplotpad->Draw();
  TPad *PtTauDM0FakeRateBinningratiopad = new TPad("PtTauDM0FakeRateBinningratiopad", "bottom pad", 0.0, 0.0, 1.0, 0.21);
  PtTauDM0FakeRateBinningratiopad->SetTopMargin(0.06);
  PtTauDM0FakeRateBinningratiopad->SetRightMargin(0.03);
  PtTauDM0FakeRateBinningratiopad->SetBottomMargin(0.5);
  PtTauDM0FakeRateBinningratiopad->SetLeftMargin(0.16);
  PtTauDM0FakeRateBinningratiopad->SetTickx(1);
  PtTauDM0FakeRateBinningratiopad->SetTicky(1);
  PtTauDM0FakeRateBinningratiopad->Draw();
  TMultiGraph *PtTauDM0FakeRateBinningmg = new TMultiGraph();
  TGraphAsymmErrors *PtTauDM0FakeRateBinningCItselfgraph = new TGraphAsymmErrors(PtTauDM0FakeRateBinningEstimateFromD_->GetNbinsX());
  TGraphAsymmErrors *PtTauDM0FakeRateBinningFromDgraph   = new TGraphAsymmErrors(PtTauDM0FakeRateBinningEstimateFromD_->GetNbinsX());
  PtTauDM0FakeRateBinningFromDgraph->SetMarkerColor(kRed);
  PtTauDM0FakeRateBinningFromDgraph->SetLineColor(kRed);
  int npoints = 0;
  PtTauDM0FakeRateBinningplotpad->cd();
  for (int i=1; i < PtTauDM0FakeRateBinningRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtTauDM0FakeRateBinningEstimateFromD_->GetBinContent(i) > 0)
    {
      double vDen = PtTauDM0FakeRateBinningEstimateFromD_->GetBinContent(i), vDenUp = PtTauDM0FakeRateBinningEstimateFromD_UP_->GetBinContent(i), vDenDown = PtTauDM0FakeRateBinningEstimateFromD_DOWN_->GetBinContent(i);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) ;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) ;
      std::cout << "\n\nPREV ERROR:" << PtTauDM0FakeRateBinningEstimateFromD_->GetBinError(i) << "\tDiffHigh=" << vDenDown-vDen << "\tDiffHigh=" << vDenUp-vDen << endl;
      std::cout << " vDenUp=" << vDenUp << " vDen=" << vDen << " vDenDown=" << vDenDown << std::endl;
      std::cout << "(vDenDown-vDen)*(vDenDown-vDen)=" << (vDenDown-vDen)*(vDenDown-vDen) << "  vDen + (vDenDown-vDen)*(vDenDown-vDen)=" << vDen + (vDenDown-vDen)*(vDenDown-vDen) << std::endl;
      std::cout << "(vDenUp  -vDen)*(vDenUp  -vDen)=" << (vDenUp  -vDen)*(vDenUp  -vDen) << "  vDen + (vDenUp  -vDen)*(vDenUp  -vDen)=" << vDen + (vDenUp  -vDen)*(vDenUp  -vDen) << std::endl;
      std::cout <<   "Before Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      ey_low = pow( (ey_low*ey_low) + PtTauDM0FakeRateBinningEstimateFromD_->GetBinContent(i) , 0.5);
      std::cout <<   "After  Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      double binWidth = PtTauDM0FakeRateBinningRegionItself_->GetBinWidth(i) /2.0;
      if (i ==1)
        binWidth = 0;
      PtTauDM0FakeRateBinningCItselfgraph->SetPoint(npoints, PtTauDM0FakeRateBinningEstimateFromD_->GetBinCenter(i), PtTauDM0FakeRateBinningRegionItself_->GetBinContent(i));
      PtTauDM0FakeRateBinningCItselfgraph->SetPointEXlow(npoints,  binWidth);
      PtTauDM0FakeRateBinningCItselfgraph->SetPointEXhigh(npoints, binWidth);
      PtTauDM0FakeRateBinningCItselfgraph->SetPointEYlow(npoints,  pow(PtTauDM0FakeRateBinningRegionItself_->GetBinContent(i), 0.5) );
      PtTauDM0FakeRateBinningCItselfgraph->SetPointEYhigh(npoints, pow(PtTauDM0FakeRateBinningRegionItself_->GetBinContent(i), 0.5) );
      PtTauDM0FakeRateBinningFromDgraph->SetPoint(npoints, PtTauDM0FakeRateBinningEstimateFromD_->GetBinCenter(i), PtTauDM0FakeRateBinningEstimateFromD_->GetBinContent(i));
      PtTauDM0FakeRateBinningFromDgraph->SetPointEXlow(npoints,  binWidth);
      PtTauDM0FakeRateBinningFromDgraph->SetPointEXhigh(npoints, binWidth);
      PtTauDM0FakeRateBinningFromDgraph->SetPointEYlow(npoints,  ey_low );
      PtTauDM0FakeRateBinningFromDgraph->SetPointEYhigh(npoints, ey_high);
    }//if
    else
    {
      PtTauDM0FakeRateBinningFromDgraph->SetPoint(npoints, num->GetBinCenter(i), 0);
      PtTauDM0FakeRateBinningFromDgraph->SetPointEXlow(npoints,  0);
      PtTauDM0FakeRateBinningFromDgraph->SetPointEXhigh(npoints, 0);
      PtTauDM0FakeRateBinningFromDgraph->SetPointEYlow(npoints,  0);
      PtTauDM0FakeRateBinningFromDgraph->SetPointEYhigh(npoints, 0);
      PtTauDM0FakeRateBinningCItselfgraph->SetPointEXlow(npoints,  0);
      PtTauDM0FakeRateBinningCItselfgraph->SetPointEXhigh(npoints, 0);
      PtTauDM0FakeRateBinningCItselfgraph->SetPointEYlow(npoints,  0);
      PtTauDM0FakeRateBinningCItselfgraph->SetPointEYhigh(npoints, 0);
    }//ekse
    npoints++;
  }//for i
  PtTauDM0FakeRateBinningmg->Add(PtTauDM0FakeRateBinningFromDgraph);
  PtTauDM0FakeRateBinningmg->Add(PtTauDM0FakeRateBinningCItselfgraph);
  PtTauDM0FakeRateBinningmg->Draw("AP");
  PtTauDM0FakeRateBinningmg->GetXaxis()->SetLimits(0.,150.0);
  PtTauDM0FakeRateBinningmg->GetXaxis()->SetLabelOffset(999);
  PtTauDM0FakeRateBinningmg->GetYaxis()->SetTitle("Events");
  PtTauDM0FakeRateBinningmg->GetYaxis()->SetTitleSize(0.05);
  PtTauDM0FakeRateBinningmg->GetYaxis()->SetTitleOffset(0.2);
  CMS_lumi( PtTauDM0FakeRateBinningplotpad, 4, 11);
  legend->Draw("SAME");

  PtTauDM0FakeRateBinningratiopad->cd();
  TH1F *ratiostaterr = (TH1F*)PtTauDM0FakeRateBinningRegionItself_->Clone();
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

  for (int i = 0; i <= PtTauDM0FakeRateBinningEstimateFromD_->GetNbinsX()+1; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (PtTauDM0FakeRateBinningEstimateFromD_->GetBinContent(i) > 1e-6)
    {
      double binerror = PtTauDM0FakeRateBinningRegionItself_->GetBinError(i) / PtTauDM0FakeRateBinningRegionItself_->GetBinContent(i);
      ratiostaterr->SetBinError(i, binerror);
    }//if
    else
      ratiostaterr->SetBinError(i, 999.);
  }//for

  ratiostaterr->SetXTitle("p_{T}(#tau_{H}) DM0 GeV");
  ratiostaterr->Draw("e2");
  TLine *ratiounity = new TLine(2.5,1,30,1);
  ratiounity->SetLineStyle(2);
  ratiounity->Draw("SAME");
  TH1F *num = (TH1F*)PtTauDM0FakeRateBinningRegionItself_->Clone();
  num->SetMarkerStyle(20);
  num->SetMarkerSize(1.);
  num->SetLineColor(kBlack);
  TGraphAsymmErrors *graph = new TGraphAsymmErrors(num->GetNbinsX());
  int npoints = 0;
  for (int i=1; i < PtTauDM0FakeRateBinningRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtTauDM0FakeRateBinningEstimateFromD_->GetBinContent(i) > 0)
    { 
      double vNum = num->GetBinContent(i), vDenUp = PtTauDM0FakeRateBinningEstimateFromD_UP_->GetBinContent(i), vDenDown = PtTauDM0FakeRateBinningEstimateFromD_DOWN_->GetBinContent(i);
      double vDen = PtTauDM0FakeRateBinningEstimateFromD_->GetBinContent(i), wNum = num->GetBinWidth(i+1), wDen = num->GetBinWidth(i+1);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) / vDen;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) / vDen;
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
  graph->Set(npoints);
  graph->Draw("0P SAME");

  PtTauDM0FakeRateBinningRatioCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRateEstimates/PtTauDM0FakeRateBinningEstimate.png");
  PtTauDM0FakeRateBinningRatioCanvas->Write();  

////////////////////////////////
// Ratio PtTauDM1FakeRateBinningDi
///////////////////////////////
  TCanvas *PtTauDM1FakeRateBinningRatioCanvas = new TCanvas("PtTauDM1FakeRateBinningRatioCanvas", "", 800, 600);
  PtTauDM1FakeRateBinningRatioCanvas->cd();
  TPad *PtTauDM1FakeRateBinningplotpad = new TPad("PtTauDM1FakeRateBinningplotpad", "top pad", 0.0, 0.21, 1.0, 1.0);
  PtTauDM1FakeRateBinningplotpad->SetBottomMargin(0.04);
  PtTauDM1FakeRateBinningplotpad->SetRightMargin(0.03);
  PtTauDM1FakeRateBinningplotpad->Draw();
  TPad *PtTauDM1FakeRateBinningratiopad = new TPad("PtTauDM1FakeRateBinningratiopad", "bottom pad", 0.0, 0.0, 1.0, 0.21);
  PtTauDM1FakeRateBinningratiopad->SetTopMargin(0.06);
  PtTauDM1FakeRateBinningratiopad->SetRightMargin(0.03);
  PtTauDM1FakeRateBinningratiopad->SetBottomMargin(0.5);
  PtTauDM1FakeRateBinningratiopad->SetLeftMargin(0.16);
  PtTauDM1FakeRateBinningratiopad->SetTickx(1);
  PtTauDM1FakeRateBinningratiopad->SetTicky(1);
  PtTauDM1FakeRateBinningratiopad->Draw();
  TMultiGraph *PtTauDM1FakeRateBinningmg = new TMultiGraph();
  TGraphAsymmErrors *PtTauDM1FakeRateBinningCItselfgraph = new TGraphAsymmErrors(PtTauDM1FakeRateBinningEstimateFromD_->GetNbinsX());
  TGraphAsymmErrors *PtTauDM1FakeRateBinningFromDgraph   = new TGraphAsymmErrors(PtTauDM1FakeRateBinningEstimateFromD_->GetNbinsX());
  PtTauDM1FakeRateBinningFromDgraph->SetMarkerColor(kRed);
  PtTauDM1FakeRateBinningFromDgraph->SetLineColor(kRed);
  int npoints = 0;
  PtTauDM1FakeRateBinningplotpad->cd();
  for (int i=1; i < PtTauDM1FakeRateBinningRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtTauDM1FakeRateBinningEstimateFromD_->GetBinContent(i) > 0)
    {
      double vDen = PtTauDM1FakeRateBinningEstimateFromD_->GetBinContent(i), vDenUp = PtTauDM1FakeRateBinningEstimateFromD_UP_->GetBinContent(i), vDenDown = PtTauDM1FakeRateBinningEstimateFromD_DOWN_->GetBinContent(i);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) ;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) ;
      std::cout << "\n\nPREV ERROR:" << PtTauDM1FakeRateBinningEstimateFromD_->GetBinError(i) << "\tDiffHigh=" << vDenDown-vDen << "\tDiffHigh=" << vDenUp-vDen << endl;
      std::cout << " vDenUp=" << vDenUp << " vDen=" << vDen << " vDenDown=" << vDenDown << std::endl;
      std::cout << "(vDenDown-vDen)*(vDenDown-vDen)=" << (vDenDown-vDen)*(vDenDown-vDen) << "  vDen + (vDenDown-vDen)*(vDenDown-vDen)=" << vDen + (vDenDown-vDen)*(vDenDown-vDen) << std::endl;
      std::cout << "(vDenUp  -vDen)*(vDenUp  -vDen)=" << (vDenUp  -vDen)*(vDenUp  -vDen) << "  vDen + (vDenUp  -vDen)*(vDenUp  -vDen)=" << vDen + (vDenUp  -vDen)*(vDenUp  -vDen) << std::endl;
      std::cout <<   "Before Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      ey_low = pow( (ey_low*ey_low) + PtTauDM1FakeRateBinningEstimateFromD_->GetBinContent(i) , 0.5);
      std::cout <<   "After  Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      double binWidth = PtTauDM1FakeRateBinningRegionItself_->GetBinWidth(i) /2.0;
      if (i ==1)
        binWidth = 0;
      PtTauDM1FakeRateBinningCItselfgraph->SetPoint(npoints, PtTauDM1FakeRateBinningEstimateFromD_->GetBinCenter(i), PtTauDM1FakeRateBinningRegionItself_->GetBinContent(i));
      PtTauDM1FakeRateBinningCItselfgraph->SetPointEXlow(npoints,  binWidth);
      PtTauDM1FakeRateBinningCItselfgraph->SetPointEXhigh(npoints, binWidth);
      PtTauDM1FakeRateBinningCItselfgraph->SetPointEYlow(npoints,  pow(PtTauDM1FakeRateBinningRegionItself_->GetBinContent(i), 0.5) );
      PtTauDM1FakeRateBinningCItselfgraph->SetPointEYhigh(npoints, pow(PtTauDM1FakeRateBinningRegionItself_->GetBinContent(i), 0.5) );
      PtTauDM1FakeRateBinningFromDgraph->SetPoint(npoints, PtTauDM1FakeRateBinningEstimateFromD_->GetBinCenter(i), PtTauDM1FakeRateBinningEstimateFromD_->GetBinContent(i));
      PtTauDM1FakeRateBinningFromDgraph->SetPointEXlow(npoints,  binWidth);
      PtTauDM1FakeRateBinningFromDgraph->SetPointEXhigh(npoints, binWidth);
      PtTauDM1FakeRateBinningFromDgraph->SetPointEYlow(npoints,  ey_low );
      PtTauDM1FakeRateBinningFromDgraph->SetPointEYhigh(npoints, ey_high);
    }//if
    else
    {
      PtTauDM1FakeRateBinningFromDgraph->SetPoint(npoints, num->GetBinCenter(i), 0);
      PtTauDM1FakeRateBinningFromDgraph->SetPointEXlow(npoints,  0);
      PtTauDM1FakeRateBinningFromDgraph->SetPointEXhigh(npoints, 0);
      PtTauDM1FakeRateBinningFromDgraph->SetPointEYlow(npoints,  0);
      PtTauDM1FakeRateBinningFromDgraph->SetPointEYhigh(npoints, 0);
      PtTauDM1FakeRateBinningCItselfgraph->SetPointEXlow(npoints,  0);
      PtTauDM1FakeRateBinningCItselfgraph->SetPointEXhigh(npoints, 0);
      PtTauDM1FakeRateBinningCItselfgraph->SetPointEYlow(npoints,  0);
      PtTauDM1FakeRateBinningCItselfgraph->SetPointEYhigh(npoints, 0);
    }//ekse
    npoints++;
  }//for i
  PtTauDM1FakeRateBinningmg->Add(PtTauDM1FakeRateBinningFromDgraph);
  PtTauDM1FakeRateBinningmg->Add(PtTauDM1FakeRateBinningCItselfgraph);
  PtTauDM1FakeRateBinningmg->Draw("AP");
  PtTauDM1FakeRateBinningmg->GetXaxis()->SetLimits(0.,150.0);
  PtTauDM1FakeRateBinningmg->GetXaxis()->SetLabelOffset(999);
  PtTauDM1FakeRateBinningmg->GetYaxis()->SetTitle("Events");
  PtTauDM1FakeRateBinningmg->GetYaxis()->SetTitleSize(0.05);
  PtTauDM1FakeRateBinningmg->GetYaxis()->SetTitleOffset(0.2);
  CMS_lumi( PtTauDM1FakeRateBinningplotpad, 4, 11);
  legend->Draw("SAME");

  PtTauDM1FakeRateBinningratiopad->cd();
  TH1F *ratiostaterr = (TH1F*)PtTauDM1FakeRateBinningRegionItself_->Clone();
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

  for (int i = 0; i <= PtTauDM1FakeRateBinningEstimateFromD_->GetNbinsX()+1; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (PtTauDM1FakeRateBinningEstimateFromD_->GetBinContent(i) > 1e-6)
    {
      double binerror = PtTauDM1FakeRateBinningRegionItself_->GetBinError(i) / PtTauDM1FakeRateBinningRegionItself_->GetBinContent(i);
      ratiostaterr->SetBinError(i, binerror);
    }//if
    else
      ratiostaterr->SetBinError(i, 999.);
  }//for

  ratiostaterr->SetXTitle("p_{T}(#tau_{H}) DM1 GeV");
  ratiostaterr->Draw("e2");
  TLine *ratiounity = new TLine(2.5,1,30,1);
  ratiounity->SetLineStyle(2);
  ratiounity->Draw("SAME");
  TH1F *num = (TH1F*)PtTauDM1FakeRateBinningRegionItself_->Clone();
  num->SetMarkerStyle(20);
  num->SetMarkerSize(1.);
  num->SetLineColor(kBlack);
  TGraphAsymmErrors *graph = new TGraphAsymmErrors(num->GetNbinsX());
  int npoints = 0;
  for (int i=1; i < PtTauDM1FakeRateBinningRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtTauDM1FakeRateBinningEstimateFromD_->GetBinContent(i) > 0)
    { 
      double vNum = num->GetBinContent(i), vDenUp = PtTauDM1FakeRateBinningEstimateFromD_UP_->GetBinContent(i), vDenDown = PtTauDM1FakeRateBinningEstimateFromD_DOWN_->GetBinContent(i);
      double vDen = PtTauDM1FakeRateBinningEstimateFromD_->GetBinContent(i), wNum = num->GetBinWidth(i+1), wDen = num->GetBinWidth(i+1);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) / vDen;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) / vDen;
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
  graph->Set(npoints);
  graph->Draw("0P SAME");

  PtTauDM1FakeRateBinningRatioCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRateEstimates/PtTauDM1FakeRateBinningEstimate.png");
  PtTauDM1FakeRateBinningRatioCanvas->Write();  

////////////////////////////////
// Ratio PtTauDM10FakeRateBinningDi
///////////////////////////////
  TCanvas *PtTauDM10FakeRateBinningRatioCanvas = new TCanvas("PtTauDM10FakeRateBinningRatioCanvas", "", 800, 600);
  PtTauDM10FakeRateBinningRatioCanvas->cd();
  TPad *PtTauDM10FakeRateBinningplotpad = new TPad("PtTauDM10FakeRateBinningplotpad", "top pad", 0.0, 0.21, 1.0, 1.0);
  PtTauDM10FakeRateBinningplotpad->SetBottomMargin(0.04);
  PtTauDM10FakeRateBinningplotpad->SetRightMargin(0.03);
  PtTauDM10FakeRateBinningplotpad->Draw();
  TPad *PtTauDM10FakeRateBinningratiopad = new TPad("PtTauDM10FakeRateBinningratiopad", "bottom pad", 0.0, 0.0, 1.0, 0.21);
  PtTauDM10FakeRateBinningratiopad->SetTopMargin(0.06);
  PtTauDM10FakeRateBinningratiopad->SetRightMargin(0.03);
  PtTauDM10FakeRateBinningratiopad->SetBottomMargin(0.5);
  PtTauDM10FakeRateBinningratiopad->SetLeftMargin(0.16);
  PtTauDM10FakeRateBinningratiopad->SetTickx(1);
  PtTauDM10FakeRateBinningratiopad->SetTicky(1);
  PtTauDM10FakeRateBinningratiopad->Draw();
  TMultiGraph *PtTauDM10FakeRateBinningmg = new TMultiGraph();
  TGraphAsymmErrors *PtTauDM10FakeRateBinningCItselfgraph = new TGraphAsymmErrors(PtTauDM10FakeRateBinningEstimateFromD_->GetNbinsX());
  TGraphAsymmErrors *PtTauDM10FakeRateBinningFromDgraph   = new TGraphAsymmErrors(PtTauDM10FakeRateBinningEstimateFromD_->GetNbinsX());
  PtTauDM10FakeRateBinningFromDgraph->SetMarkerColor(kRed);
  PtTauDM10FakeRateBinningFromDgraph->SetLineColor(kRed);
  int npoints = 0;
  PtTauDM10FakeRateBinningplotpad->cd();
  for (int i=1; i < PtTauDM10FakeRateBinningRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtTauDM10FakeRateBinningEstimateFromD_->GetBinContent(i) > 0)
    {
      double vDen = PtTauDM10FakeRateBinningEstimateFromD_->GetBinContent(i), vDenUp = PtTauDM10FakeRateBinningEstimateFromD_UP_->GetBinContent(i), vDenDown = PtTauDM10FakeRateBinningEstimateFromD_DOWN_->GetBinContent(i);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) ;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) ;
      std::cout << "\n\nPREV ERROR:" << PtTauDM10FakeRateBinningEstimateFromD_->GetBinError(i) << "\tDiffHigh=" << vDenDown-vDen << "\tDiffHigh=" << vDenUp-vDen << endl;
      std::cout << " vDenUp=" << vDenUp << " vDen=" << vDen << " vDenDown=" << vDenDown << std::endl;
      std::cout << "(vDenDown-vDen)*(vDenDown-vDen)=" << (vDenDown-vDen)*(vDenDown-vDen) << "  vDen + (vDenDown-vDen)*(vDenDown-vDen)=" << vDen + (vDenDown-vDen)*(vDenDown-vDen) << std::endl;
      std::cout << "(vDenUp  -vDen)*(vDenUp  -vDen)=" << (vDenUp  -vDen)*(vDenUp  -vDen) << "  vDen + (vDenUp  -vDen)*(vDenUp  -vDen)=" << vDen + (vDenUp  -vDen)*(vDenUp  -vDen) << std::endl;
      std::cout <<   "Before Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      ey_low = pow( (ey_low*ey_low) + PtTauDM10FakeRateBinningEstimateFromD_->GetBinContent(i) , 0.5);
      std::cout <<   "After  Add Stat: ey_low:" << ey_low << "\tey_high=" << ey_high << "\tcontent=" << vDen <<endl;
      double binWidth = PtTauDM10FakeRateBinningRegionItself_->GetBinWidth(i) /2.0;
      if (i ==1)
        continue;
//        binWidth = 0;
      PtTauDM10FakeRateBinningCItselfgraph->SetPoint(npoints, PtTauDM10FakeRateBinningEstimateFromD_->GetBinCenter(i), PtTauDM10FakeRateBinningRegionItself_->GetBinContent(i));
      PtTauDM10FakeRateBinningCItselfgraph->SetPointEXlow(npoints,  binWidth);
      PtTauDM10FakeRateBinningCItselfgraph->SetPointEXhigh(npoints, binWidth);
      PtTauDM10FakeRateBinningCItselfgraph->SetPointEYlow(npoints,  pow(PtTauDM10FakeRateBinningRegionItself_->GetBinContent(i), 0.5) );
      PtTauDM10FakeRateBinningCItselfgraph->SetPointEYhigh(npoints, pow(PtTauDM10FakeRateBinningRegionItself_->GetBinContent(i), 0.5) );
      PtTauDM10FakeRateBinningFromDgraph->SetPoint(npoints, PtTauDM10FakeRateBinningEstimateFromD_->GetBinCenter(i), PtTauDM10FakeRateBinningEstimateFromD_->GetBinContent(i));
      PtTauDM10FakeRateBinningFromDgraph->SetPointEXlow(npoints,  binWidth);
      PtTauDM10FakeRateBinningFromDgraph->SetPointEXhigh(npoints, binWidth);
      PtTauDM10FakeRateBinningFromDgraph->SetPointEYlow(npoints,  ey_low );
      PtTauDM10FakeRateBinningFromDgraph->SetPointEYhigh(npoints, ey_high);
    }//if
    else
    {
      PtTauDM10FakeRateBinningFromDgraph->SetPoint(npoints, num->GetBinCenter(i), 0);
      PtTauDM10FakeRateBinningFromDgraph->SetPointEXlow(npoints,  0);
      PtTauDM10FakeRateBinningFromDgraph->SetPointEXhigh(npoints, 0);
      PtTauDM10FakeRateBinningFromDgraph->SetPointEYlow(npoints,  0);
      PtTauDM10FakeRateBinningFromDgraph->SetPointEYhigh(npoints, 0);
      PtTauDM10FakeRateBinningCItselfgraph->SetPointEXlow(npoints,  0);
      PtTauDM10FakeRateBinningCItselfgraph->SetPointEXhigh(npoints, 0);
      PtTauDM10FakeRateBinningCItselfgraph->SetPointEYlow(npoints,  0);
      PtTauDM10FakeRateBinningCItselfgraph->SetPointEYhigh(npoints, 0);
    }//ekse
    npoints++;
  }//for i
  PtTauDM10FakeRateBinningmg->Add(PtTauDM10FakeRateBinningFromDgraph);
  PtTauDM10FakeRateBinningmg->Add(PtTauDM10FakeRateBinningCItselfgraph);
  PtTauDM10FakeRateBinningmg->Draw("0P SAME");
  PtTauDM10FakeRateBinningmg->GetXaxis()->SetLimits(0.,150.0);
  PtTauDM10FakeRateBinningmg->GetXaxis()->SetLabelOffset(999);
  PtTauDM10FakeRateBinningmg->GetYaxis()->SetTitle("Events");
  PtTauDM10FakeRateBinningmg->GetYaxis()->SetTitleSize(0.05);
  PtTauDM10FakeRateBinningmg->GetYaxis()->SetTitleOffset(0.2);
  CMS_lumi( PtTauDM10FakeRateBinningplotpad, 4, 11);
  legend->Draw("SAME");

  PtTauDM10FakeRateBinningratiopad->cd();
  TH1F *ratiostaterr = (TH1F*)PtTauDM10FakeRateBinningRegionItself_->Clone();
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

  for (int i = 0; i <= PtTauDM10FakeRateBinningEstimateFromD_->GetNbinsX()+1; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (PtTauDM10FakeRateBinningEstimateFromD_->GetBinContent(i) > 1e-6)
    {
      double binerror = PtTauDM10FakeRateBinningRegionItself_->GetBinError(i) / PtTauDM10FakeRateBinningRegionItself_->GetBinContent(i);
      ratiostaterr->SetBinError(i, binerror);
    }//if
    else
      ratiostaterr->SetBinError(i, 999.);
  }//for

  ratiostaterr->SetXTitle("p_{T}(#tau_{H}) DM10 GeV");
  ratiostaterr->Draw("e2");
  TLine *ratiounity = new TLine(2.5,1,30,1);
  ratiounity->SetLineStyle(2);
  ratiounity->Draw("SAME");
  TH1F *num = (TH1F*)PtTauDM10FakeRateBinningRegionItself_->Clone();
  num->SetMarkerStyle(20);
  num->SetMarkerSize(1.);
  num->SetLineColor(kBlack);
  TGraphAsymmErrors *graph = new TGraphAsymmErrors(num->GetNbinsX());
  int npoints = 0;
  for (int i=1; i < PtTauDM10FakeRateBinningRegionItself_->GetXaxis()->GetNbins()+1; i++)
  {
    if (PtTauDM10FakeRateBinningEstimateFromD_->GetBinContent(i) > 0)
    { 
      double vNum = num->GetBinContent(i), vDenUp = PtTauDM10FakeRateBinningEstimateFromD_UP_->GetBinContent(i), vDenDown = PtTauDM10FakeRateBinningEstimateFromD_DOWN_->GetBinContent(i);
      double vDen = PtTauDM10FakeRateBinningEstimateFromD_->GetBinContent(i), wNum = num->GetBinWidth(i+1), wDen = num->GetBinWidth(i+1);
      double ey_low  = pow( vDen + (vDenDown-vDen)*(vDenDown-vDen), 0.5) / vDen;
      double ey_high = pow( vDen + (vDenUp  -vDen)*(vDenUp  -vDen), 0.5) / vDen;
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
  graph->Set(npoints);
  graph->Draw("0P SAME");

  PtTauDM10FakeRateBinningRatioCanvas->SaveAs("/home/kyletos/Desktop/NewPlots/FakeRateEstimates/PtTauDM10FakeRateBinningEstimate.png");
  PtTauDM10FakeRateBinningRatioCanvas->Write();  


  outFile->Write();
  outFile->Close();
}//rootMacro_BBA_combine

double PropogateErrors(double val1, double val2, double err1, double err2)
{
  return pow( err1*err1/val1/val1 + err2*err2/val2/val2, 0.5);
}
