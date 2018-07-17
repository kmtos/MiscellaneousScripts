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

double PropogateErrors(double val1, double val2, double err1, double err2);

void rootMacro_CompareTwoRegionsData()
{
  setTDRStyle(true);
  gStyle->SetPalette(1);


  //Old DMs
  TFile infileEstimateFromD("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_SingleMu_AntiMedIsoMu2_TauDMAntiMedIso_MAY1_CFromD_1CombBin.root");
  TFile infileEstimateFromD_UP("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_SingleMu_AntiMedIsoMu2_TauDMAntiMedIso_MAY1_CFromD_1CombBin_UP.root");
  TFile infileEstimateFromD_DOWN("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_SingleMu_AntiMedIsoMu2_TauDMAntiMedIso_MAY1_CFromD_1CombBin_DOWN.root");
  TFile infileRegionItself("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_SingleMu_AntiMedIsoMu2_TauDMMedIso_MAY1_RegionCItself_1CombBin.root");

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimateData_DatatoData_CFromD_MAY1_1CombBin.root", "RECREATE");

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
  TH1F *EtaFakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("EtaFakeWeight");
  TH1F *DRFakeWeightEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("DRFakeWeight");
  TH1F *DiMuInvMassFakeWeightZoomEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomEstimateFromD_->Rebin(10);
  TH1F *TauVisMassEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("TauVisMass");
  TH1F *TauVisMassZoomEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("TauVisMassZoom");

  TH1F *DiMuInvMassFakeWeightEstimateFromD_DOWN_ = (TH1F*)infileEstimateFromD_DOWN.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuInvMassFakeWeightEstimateFromD_UP_ = (TH1F*)infileEstimateFromD_UP.Get("DiMuInvMassFakeWeight");

  InvMassTauMuMu1EstimateFromD_->SetLineColor(kRed);
  InvMassTauMuMu2EstimateFromD_->SetLineColor(kRed);
  DiMuInvMassFakeWeightEstimateFromD_->SetLineColor(kRed);
  DiMuDiTauInvMassFakeWeightEstimateFromD_->SetLineColor(kRed);
  DiTauInvMassFakeWeightEstimateFromD_->SetLineColor(kRed);
  PtMu1FakeWeightEstimateFromD_->SetLineColor(kRed);
  PtMu2FakeWeightEstimateFromD_->SetLineColor(kRed);
  EtaFakeWeightEstimateFromD_->SetLineColor(kRed);
  DRFakeWeightEstimateFromD_->SetLineColor(kRed);
  DiMuInvMassFakeWeightZoomEstimateFromD_->SetLineColor(kRed);
  TauVisMassEstimateFromD_->SetLineColor(kRed);
  TauVisMassZoomEstimateFromD_->SetLineColor(kRed);

  InvMassTauMuMu1EstimateFromD_->SetFillColor(kRed);
  InvMassTauMuMu2EstimateFromD_->SetFillColor(kRed);
  DiMuInvMassFakeWeightEstimateFromD_->SetFillColor(kRed);
  DiMuDiTauInvMassFakeWeightEstimateFromD_->SetFillColor(kRed);
  DiTauInvMassFakeWeightEstimateFromD_->SetFillColor(kRed);
  PtMu1FakeWeightEstimateFromD_->SetFillColor(kRed);
  PtMu2FakeWeightEstimateFromD_->SetFillColor(kRed);
  EtaFakeWeightEstimateFromD_->SetFillColor(kRed);
  DRFakeWeightEstimateFromD_->SetFillColor(kRed);
  DiMuInvMassFakeWeightZoomEstimateFromD_->SetFillColor(kRed);
  TauVisMassEstimateFromD_->SetFillColor(kRed);
  TauVisMassZoomEstimateFromD_->SetFillColor(kRed);

  InvMassTauMuMu1EstimateFromD_->SetMarkerColor(kRed);
  InvMassTauMuMu2EstimateFromD_->SetMarkerColor(kRed);
  DiMuInvMassFakeWeightEstimateFromD_->SetMarkerColor(kRed);
  DiMuDiTauInvMassFakeWeightEstimateFromD_->SetMarkerColor(kRed);
  DiTauInvMassFakeWeightEstimateFromD_->SetMarkerColor(kRed);
  PtMu1FakeWeightEstimateFromD_->SetMarkerColor(kRed);
  PtMu2FakeWeightEstimateFromD_->SetMarkerColor(kRed);
  EtaFakeWeightEstimateFromD_->SetMarkerColor(kRed);
  DRFakeWeightEstimateFromD_->SetMarkerColor(kRed);
  DiMuInvMassFakeWeightZoomEstimateFromD_->SetMarkerColor(kRed);
  TauVisMassEstimateFromD_->SetMarkerColor(kRed);
  TauVisMassZoomEstimateFromD_->SetMarkerColor(kRed);

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
  TH1F *EtaFakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("EtaFakeWeight");
  TH1F *DRFakeWeightRegionItself_ = (TH1F*)infileRegionItself.Get("DRFakeWeight");
  TH1F *DiMuInvMassFakeWeightZoomRegionItself_ = (TH1F*)infileRegionItself.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomRegionItself_->Rebin(10);
  TH1F *TauVisMassRegionItself_ = (TH1F*)infileRegionItself.Get("TauVisMass");
  TH1F *TauVisMassZoomRegionItself_ = (TH1F*)infileRegionItself.Get("TauVisMassZoom");

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
  TCanvas *EtaFakeWeightCanvas = new TCanvas ("EtaFakeWeightCanvas","",600,600);
  TCanvas *DRFakeWeightCanvas = new TCanvas ("DRFakeWeightCanvas","",600,600);
  TCanvas *DiMuInvMassFakeWeightZoomCanvas = new TCanvas ("DiMuInvMassFakeWeightZoomCanvas","",600,600);
  TCanvas *TauVisMassCanvas = new TCanvas ("TauVisMassCanvas","",600,600);
  TCanvas *TauVisMassZoomCanvas = new TCanvas ("TauVisMassZoomCanvas","",600,600);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting the cms_lumi Styling
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  writeExtraText = true;
  lumi_13TeV = "35.9 fb^{-1}";

cout << "Cms_lumi run" << endl;

  stringstream InvMassTauMuMu1YTitle;
  InvMassTauMuMu1YTitle << fixed;
  InvMassTauMuMu1YTitle.precision(2);
  InvMassTauMuMu1YTitle << "Events / " << InvMassTauMuMu1EstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream InvMassTauMuMu2YTitle;
  InvMassTauMuMu2YTitle << fixed;
  InvMassTauMuMu2YTitle.precision(2);
  InvMassTauMuMu2YTitle << "Events / " << InvMassTauMuMu2EstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream DiMuInvMassFakeWeightYTitle;
  DiMuInvMassFakeWeightYTitle << fixed;
  DiMuInvMassFakeWeightYTitle.precision(2);
  DiMuInvMassFakeWeightYTitle << "Events / " << DiMuInvMassFakeWeightEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream DiMuDiTauInvMassFakeWeightYTitle;
  DiMuDiTauInvMassFakeWeightYTitle << fixed;
  DiMuDiTauInvMassFakeWeightYTitle.precision(2);
  DiMuDiTauInvMassFakeWeightYTitle << "Events / " << DiMuDiTauInvMassFakeWeightEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream DiTauInvMassFakeWeightYTitle;
  DiTauInvMassFakeWeightYTitle << fixed;
  DiTauInvMassFakeWeightYTitle.precision(2);
  DiTauInvMassFakeWeightYTitle << "Events / " << DiTauInvMassFakeWeightEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream PtMu1FakeWeightYTitle;
  PtMu1FakeWeightYTitle << fixed;
  PtMu1FakeWeightYTitle.precision(2);
  PtMu1FakeWeightYTitle << "Events / " << PtMu1FakeWeightEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream PtMu2FakeWeightYTitle;
  PtMu2FakeWeightYTitle << fixed;
  PtMu2FakeWeightYTitle.precision(2);
  PtMu2FakeWeightYTitle << "Events / " << PtMu2FakeWeightEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream EtaFakeWeightYTitle;
  EtaFakeWeightYTitle << fixed;
  EtaFakeWeightYTitle.precision(2);
  EtaFakeWeightYTitle << "Events / " << EtaFakeWeightEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream DRFakeWeightYTitle;
  DRFakeWeightYTitle << fixed;
  DRFakeWeightYTitle.precision(2);
  DRFakeWeightYTitle << "Events / " << DRFakeWeightEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream TauVisMassYTitle;
  TauVisMassYTitle << fixed;
  TauVisMassYTitle.precision(2);
  TauVisMassYTitle << "Events / " << TauVisMassEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream TauVisMassZoomYTitle;
  TauVisMassZoomYTitle << fixed;
  TauVisMassZoomYTitle.precision(2);
  TauVisMassZoomYTitle << "Events / " << TauVisMassZoomEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream DiMuInvMassFakeWeightZoomYTitle;
  DiMuInvMassFakeWeightZoomYTitle << fixed;
  DiMuInvMassFakeWeightZoomYTitle.precision(2);
  DiMuInvMassFakeWeightZoomYTitle << "Events / " << DiMuInvMassFakeWeightZoomEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";
  std::cout << DiMuInvMassFakeWeightZoomYTitle.str().c_str() << std::endl;

  TLegend *legend = new TLegend(0.7,0.5,0.95,0.7) ;
  legend->SetTextFont(42);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->AddEntry(InvMassTauMuMu1EstimateFromD_ ,"Estimate of Region C From D", "le");
  legend->AddEntry(InvMassTauMuMu1RegionItself_, "Observed", "le");


  outFile->cd();
  InvMassTauMuMu1Canvas->cd();
  InvMassTauMuMu1EstimateFromD_->GetYaxis()->SetTitle(  InvMassTauMuMu1YTitle.str().c_str() );
//  InvMassTauMuMu1EstimateFromD_->GetYaxis()->SetTitleOffset(2);
//  InvMassTauMuMu1EstimateFromD_->SetTitle("Estimate Region C From D");

  InvMassTauMuMu1EstimateFromD_->Draw();
CMS_lumi(  InvMassTauMuMu1Canvas, 4, 11);
//  InvMassTauMuMu1Canvas->cd(2);
//  InvMassTauMuMu1RegionItself_->SetTitle("Region B Data");
  InvMassTauMuMu1RegionItself_->Draw("SAME");
  legend->Draw();
  InvMassTauMuMu1Canvas->Write();

  InvMassTauMuMu2Canvas->cd();
  InvMassTauMuMu2EstimateFromD_->GetYaxis()->SetTitle(  InvMassTauMuMu2YTitle.str().c_str() );
//  InvMassTauMuMu2EstimateFromD_->GetYaxis()->SetTitleOffset(2);
//  InvMassTauMuMu2EstimateFromD_->SetTitle("Estimate Region C From D");

  InvMassTauMuMu2EstimateFromD_->Draw();
CMS_lumi(  InvMassTauMuMu2Canvas, 4, 11);
//  InvMassTauMuMu2Canvas->cd(2);
//  InvMassTauMuMu2RegionItself_->SetTitle("Region B Data");
  InvMassTauMuMu2RegionItself_->Draw("SAME");
  legend->Draw();
  InvMassTauMuMu2Canvas->Write();

  DiMuInvMassFakeWeightCanvas->cd();
  DiMuInvMassFakeWeightEstimateFromD_->GetYaxis()->SetTitle(  DiMuInvMassFakeWeightYTitle.str().c_str() );
//  DiMuInvMassFakeWeightEstimateFromD_->GetYaxis()->SetTitleOffset(2);
//  DiMuInvMassFakeWeightEstimateFromD_->SetTitle("Estimate Region C From D");
  DiMuInvMassFakeWeightEstimateFromD_->GetXaxis()->SetTitle("m(#mu_{1},#mu_{2}) GeV");
  DiMuInvMassFakeWeightEstimateFromD_->Draw();
CMS_lumi(  DiMuInvMassFakeWeightCanvas, 4, 11);
//  DiMuInvMassFakeWeightCanvas->cd(2);
//  DiMuInvMassFakeWeightRegionItself_->SetTitle("Region B Data");
  DiMuInvMassFakeWeightRegionItself_->Draw("SAME");
  legend->Draw();
  DiMuInvMassFakeWeightCanvas->Write();

  DiMuDiTauInvMassFakeWeightCanvas->cd();
  DiMuDiTauInvMassFakeWeightEstimateFromD_->GetYaxis()->SetTitle(  DiMuDiTauInvMassFakeWeightYTitle.str().c_str() );
//  DiMuDiTauInvMassFakeWeightEstimateFromD_->GetYaxis()->SetTitleOffset(2);
//  DiMuDiTauInvMassFakeWeightEstimateFromD_->SetTitle("Estimate Region C From D");

  DiMuDiTauInvMassFakeWeightEstimateFromD_->Draw();
CMS_lumi(  DiMuDiTauInvMassFakeWeightCanvas, 4, 11);
//  DiMuDiTauInvMassFakeWeightCanvas->cd(2);
//  DiMuDiTauInvMassFakeWeightRegionItself_->SetTitle("Region B Data");
  DiMuDiTauInvMassFakeWeightRegionItself_->Draw("SAME");
  legend->Draw();
  DiMuDiTauInvMassFakeWeightCanvas->Write();

  DiTauInvMassFakeWeightCanvas->cd();
  DiTauInvMassFakeWeightEstimateFromD_->GetYaxis()->SetTitle(  DiTauInvMassFakeWeightYTitle.str().c_str() );
//  DiTauInvMassFakeWeightEstimateFromD_->GetYaxis()->SetTitleOffset(2);
//  DiTauInvMassFakeWeightEstimateFromD_->SetTitle("Estimate Region C From D");

  DiTauInvMassFakeWeightEstimateFromD_->Draw();
CMS_lumi(  DiTauInvMassFakeWeightCanvas, 4, 11);
//  DiTauInvMassFakeWeightCanvas->cd(2);
//  DiTauInvMassFakeWeightRegionItself_->SetTitle("Region B Data");
  DiTauInvMassFakeWeightRegionItself_->Draw("SAME");
  legend->Draw();
  DiTauInvMassFakeWeightCanvas->Write();

  PtMu1FakeWeightCanvas->cd();
  PtMu1FakeWeightEstimateFromD_->GetYaxis()->SetTitle(  PtMu1FakeWeightYTitle.str().c_str() );
//  PtMu1FakeWeightEstimateFromD_->GetYaxis()->SetTitleOffset(2);
//  PtMu1FakeWeightEstimateFromD_->SetTitle("Estimate Region C From D");

  PtMu1FakeWeightEstimateFromD_->Draw();
CMS_lumi(  PtMu1FakeWeightCanvas, 4, 11);
//  PtMu1FakeWeightCanvas->cd(2);
//  PtMu1FakeWeightRegionItself_->SetTitle("Region B Data");
  PtMu1FakeWeightRegionItself_->Draw("SAME");
  legend->Draw();
  PtMu1FakeWeightCanvas->Write();

  PtMu2FakeWeightCanvas->cd();
  PtMu2FakeWeightEstimateFromD_->GetYaxis()->SetTitle(  PtMu2FakeWeightYTitle.str().c_str() );
//  PtMu2FakeWeightEstimateFromD_->GetYaxis()->SetTitleOffset(2);
//  PtMu2FakeWeightEstimateFromD_->SetTitle("Estimate Region C From D");

  PtMu2FakeWeightEstimateFromD_->Draw();
CMS_lumi(  PtMu2FakeWeightCanvas, 4, 11);
//  PtMu2FakeWeightCanvas->cd(2);
//  PtMu2FakeWeightRegionItself_->SetTitle("Region B Data");
  PtMu2FakeWeightRegionItself_->Draw("SAME");
  legend->Draw();
  PtMu2FakeWeightCanvas->Write();

  EtaFakeWeightCanvas->cd();
  EtaFakeWeightEstimateFromD_->GetYaxis()->SetTitle(  EtaFakeWeightYTitle.str().c_str() );
//  EtaFakeWeightEstimateFromD_->GetYaxis()->SetTitleOffset(2);
//  EtaFakeWeightEstimateFromD_->SetTitle("Estimate Region C From D");

  EtaFakeWeightEstimateFromD_->Draw();
CMS_lumi(  EtaFakeWeightCanvas, 4, 11);
//  EtaFakeWeightCanvas->cd(2);
//  EtaFakeWeightRegionItself_->SetTitle("Region B Data");
  EtaFakeWeightRegionItself_->Draw("SAME");
  legend->Draw();
  EtaFakeWeightCanvas->Write();

  DRFakeWeightCanvas->cd();
  DRFakeWeightEstimateFromD_->GetYaxis()->SetTitle(  DRFakeWeightYTitle.str().c_str() );
//  DRFakeWeightEstimateFromD_->GetYaxis()->SetTitleOffset(2);
//  DRFakeWeightEstimateFromD_->SetTitle("Estimate Region C From D");

  DRFakeWeightEstimateFromD_->Draw();
CMS_lumi(  DRFakeWeightCanvas, 4, 11);
//  DRFakeWeightCanvas->cd(2);
//  DRFakeWeightRegionItself_->SetTitle("Region B Data");
  DRFakeWeightRegionItself_->Draw("SAME");
  legend->Draw();
  DRFakeWeightCanvas->Write();

  DiMuInvMassFakeWeightZoomCanvas->cd();
  DiMuInvMassFakeWeightZoomEstimateFromD_->GetYaxis()->SetTitle(  DiMuInvMassFakeWeightZoomYTitle.str().c_str() );
//  DiMuInvMassFakeWeightZoomEstimateFromD_->GetYaxis()->SetTitleOffset(2);
//  DiMuInvMassFakeWeightZoomEstimateFromD_->SetTitle("Estimate Region C From D");
  DiMuInvMassFakeWeightZoomEstimateFromD_->GetXaxis()->SetTitle("m(#mu_{1},#mu_{2}) GeV");
  DiMuInvMassFakeWeightZoomEstimateFromD_->Draw();
CMS_lumi(  DiMuInvMassFakeWeightZoomCanvas, 4, 11);
//  DiMuInvMassFakeWeightZoomCanvas->cd(2);
//  DiMuInvMassFakeWeightZoomRegionItself_->SetTitle("Region B Data");
  DiMuInvMassFakeWeightZoomRegionItself_->Draw("SAME");
  legend->Draw();
  DiMuInvMassFakeWeightZoomCanvas->Write();

  TauVisMassCanvas->cd();
  TauVisMassEstimateFromD_->GetYaxis()->SetTitle(  TauVisMassYTitle.str().c_str() );
//  TauVisMassEstimateFromD_->GetYaxis()->SetTitleOffset(2);
//  TauVisMassEstimateFromD_->SetTitle("Estimate Region C From D");

  TauVisMassEstimateFromD_->Draw();
CMS_lumi(  TauVisMassCanvas, 4, 11);
//  TauVisMassCanvas->cd(2);
//  TauVisMassRegionItself_->SetTitle("Region B Data");
  TauVisMassRegionItself_->Draw("SAME");
  legend->Draw();
  TauVisMassCanvas->Write();

  TauVisMassZoomCanvas->cd();
  TauVisMassZoomEstimateFromD_->GetYaxis()->SetTitle(  TauVisMassZoomYTitle.str().c_str() );
//  TauVisMassZoomEstimateFromD_->GetYaxis()->SetTitleOffset(2);
//  TauVisMassZoomEstimateFromD_->SetTitle("Estimate Region C From D");

  TauVisMassZoomEstimateFromD_->Draw();
CMS_lumi(  TauVisMassZoomCanvas, 4, 11);
//  TauVisMassZoomCanvas->cd(2);
//  TauVisMassZoomRegionItself_->SetTitle("Region B Data");
  TauVisMassZoomRegionItself_->Draw("SAME");
  legend->Draw();
  TauVisMassZoomCanvas->Write();

  TCanvas *ratioCanvas = new TCanvas("ratioCanvas", "", 600, 600);
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

  plotpad->cd();
  for (int i=1; i < DiMuInvMassFakeWeightRegionItself_->GetXaxis()->GetNbins(); i++)
  {
    DiMuInvMassFakeWeightEstimateFromD_->SetBinError(i, pow(DiMuInvMassFakeWeightEstimateFromD_->GetBinContent(i), 0.5) );
    double vNum = DiMuInvMassFakeWeightEstimateFromD_->GetBinContent(i), vNumUp = DiMuInvMassFakeWeightEstimateFromD_DOWN_->GetBinContent(i), vNumDown = DiMuInvMassFakeWeightEstimateFromD_UP_->GetBinContent(i);
    double ey_low  = pow( vNum + (vNumDown-vNum)*(vNumDown-vNum), 0.5) ;
    double ey_high = pow( vNum + (vNumUp  -vNum)*(vNumUp  -vNum), 0.5) ;
std::cout << "\nPREV ERROR:" << DiMuInvMassFakeWeightEstimateFromD_->GetBinError(i) << "\tDiffHigh=" << vNumDown-vNum << "\tDiffHigh=" << vNumUp-vNum << endl;
std::cout <<   "Next ERROR:" << ey_low << "\tcontent=" << vNum <<endl;
    DiMuInvMassFakeWeightEstimateFromD_->SetBinError(i,ey_high);
  }//for i
  DiMuInvMassFakeWeightEstimateFromD_->GetXaxis()->SetLabelOffset(999);
  DiMuInvMassFakeWeightEstimateFromD_->SetStats(0);
  DiMuInvMassFakeWeightEstimateFromD_->GetYaxis()->SetTitle("Events");
  DiMuInvMassFakeWeightEstimateFromD_->GetYaxis()->SetTitleSize(0.05);
  DiMuInvMassFakeWeightEstimateFromD_->GetYaxis()->SetTitleOffset(0.2);
  DiMuInvMassFakeWeightEstimateFromD_->GetYaxis()->SetNdivisions(503);
  DiMuInvMassFakeWeightEstimateFromD_->Draw("P E");
  DiMuInvMassFakeWeightRegionItself_->Draw("SAME P E");
  CMS_lumi( plotpad, 4, 11);
  legend->Draw("SAME");

  ratiopad->cd();
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

  for (int i = 0; i <= DiMuInvMassFakeWeightEstimateFromD_->GetNbinsX()+2; i++)
  {
    ratiostaterr->SetBinContent(i, 1.0);
    if (DiMuInvMassFakeWeightEstimateFromD_->GetBinContent(i) > 1e-6)
    {
      double binerror = DiMuInvMassFakeWeightEstimateFromD_->GetBinError(i) / DiMuInvMassFakeWeightEstimateFromD_->GetBinContent(i);
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
  for (int i=1; i < DiMuInvMassFakeWeightRegionItself_->GetXaxis()->GetNbins(); i++)
  {
    if (DiMuInvMassFakeWeightEstimateFromD_->GetBinContent(i) > 0)
    { 
      double vNum = num->GetBinContent(i), vNumUp = DiMuInvMassFakeWeightEstimateFromD_DOWN_->GetBinContent(i), vNumDown = DiMuInvMassFakeWeightEstimateFromD_UP_->GetBinContent(i);
      double vDen = DiMuInvMassFakeWeightEstimateFromD_->GetBinContent(i), wNum = num->GetBinWidth(i+1), wDen = num->GetBinWidth(i+1);
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
  graph->Set(npoints);
  graph->Draw("0P SAME");

  ratioCanvas->Write();  
  outFile->Write();
  outFile->Close();
}//rootMacro_BBA_combine

double PropogateErrors(double val1, double val2, double err1, double err2)
{
  return pow( err1*err1/val1/val1 + err2*err2/val2/val2, 0.5);
}
