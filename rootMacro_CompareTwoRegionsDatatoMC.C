#include <math.h>
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
#include "iostream"
#include "fstream"
#include "TMath.h"
#include "tdrstyle.C"
#include "CMS_lumi.C"

void rootMacro_CompareTwoRegionsDatatoMC()
{
  setTDRStyle(true);
  gStyle->SetPalette(1);


  //Old DMs
  TFile infileDYL("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_DYLowMass_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileDYH("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_DYHighMass_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileJPsi("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_JPsi_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileQCD_1000toInf("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_QCD_1000toInf_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileQCD_120to170("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_QCD_120to170_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileQCD_15to20("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_QCD_15to20_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileQCD_170to300("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_QCD_170to300_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileQCD_20to30("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_QCD_20to30_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileQCD_300to470("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_QCD_300to470_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileQCD_30to50("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_QCD_30to50_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileQCD_470to600("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_QCD_470to600_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileQCD_50to80("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_QCD_50to80_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileQCD_600to800("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_QCD_600to800_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileQCD_800to1000("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_QCD_800to1000_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileQCD_80to120("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_QCD_80to120_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh125a11("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h125a11_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh125a13("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h125a13_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh125a15("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h125a15_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh125a17("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h125a17_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh125a19("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h125a19_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh125a21("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h125a21_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh125a5("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h125a5_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh125a7("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h125a7_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh125a9("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h125a9_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh300a11("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h300a11_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh300a13("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h300a13_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh300a15("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h300a15_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh300a17("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h300a17_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh300a19("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h300a19_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh300a21("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h300a21_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh300a5("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h300a5_MedIsoMu2_TauDMAntiMedIso_FEB8.root  ");
////  TFile infileh300a7("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h300a7_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh300a9("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h300a9_MedIsoMu2_TauDMAntiMedIso_FEB8.root  ");
////  TFile infileh750a11("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h750a11_MedIsoMu2_TauDMAntiMedIso_FEB8.root ");
////  TFile infileh750a13("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h750a13_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh750a15("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h750a15_MedIsoMu2_TauDMAntiMedIso_FEB8.root ");
////  TFile infileh750a17("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h750a17_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh750a19("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h750a19_MedIsoMu2_TauDMAntiMedIso_FEB8.root  ");
////  TFile infileh750a21("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h750a21_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh750a5("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h750a5_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh750a7("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h750a7_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
////  TFile infileh750a9("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SIG_h750a9_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileST_sch("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_ST_sch_4l_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileST_tch_top("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_ST_tch_top_pythia8_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileST_tWIncl_top("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_ST_tW_incl_8M1_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileST_tWIncl_antitop("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_ST_tW_incl_8M1_antitop_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileST_tch_antitop("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_ST_tch_antitop_pythia8_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileTTAmca("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_TTJetsAmca_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileUp("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_Upsilon_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileWJAmac("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_WJAmac_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileWZ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_WZ3L1Nu_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileZZ2L2Nu("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_ZZTo2L2Nu_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileZZ2L2Q("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_ZZTo2L2Q_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileZZ4LAmac("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_ZZTo4LAmac_MedIsoMu2_TauDMAntiMedIso_FEB8.root ");
 
  TFile infileEstimateFromD("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate/FINAL_MiniAOD_SingleMu_AntiMedIsoMu2_TauDMAntiMedIso_FEB8_BFromD.root");

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateEstimate_MCOverlay_FEB8_BFromD.root", "RECREATE");

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
  TH1F *DRNoWeightingEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomEstimateFromD_->Rebin(30);
  TH1F *TauVisMassEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("TauVisMass");
  TH1F *TauVisMassZoomEstimateFromD_ = (TH1F*)infileEstimateFromD.Get("TauVisMassZoom");

  ////////////////
  // TTAmca
  ////////////////
  TH1F *InvMassTauMuMu1TTAmca_ = (TH1F*)infileTTAmca.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2TTAmca_ = (TH1F*)infileTTAmca.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightTTAmca_ = (TH1F*)infileTTAmca.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightTTAmca_ = (TH1F*)infileTTAmca.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightTTAmca_ = (TH1F*)infileTTAmca.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightTTAmca_ = (TH1F*)infileTTAmca.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightTTAmca_ = (TH1F*)infileTTAmca.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightTTAmca_ = (TH1F*)infileTTAmca.Get("EtaFakeWeight");
  TH1F *DRFakeWeightTTAmca_ = (TH1F*)infileTTAmca.Get("DRFakeWeight");
  TH1F *DRNoWeightingTTAmca_ = (TH1F*)infileTTAmca.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomTTAmca_ = (TH1F*)infileTTAmca.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomTTAmca_->Rebin(30);
  TH1F *TauVisMassTTAmca_ = (TH1F*)infileTTAmca.Get("TauVisMass");
  TH1F *TauVisMassZoomTTAmca_ = (TH1F*)infileTTAmca.Get("TauVisMassZoom");

  ////////////////
  // DYL
  ////////////////
  TH1F *InvMassTauMuMu1DYL_ = (TH1F*)infileDYL.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2DYL_ = (TH1F*)infileDYL.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightDYL_ = (TH1F*)infileDYL.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightDYL_ = (TH1F*)infileDYL.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightDYL_ = (TH1F*)infileDYL.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightDYL_ = (TH1F*)infileDYL.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightDYL_ = (TH1F*)infileDYL.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightDYL_ = (TH1F*)infileDYL.Get("EtaFakeWeight");
  TH1F *DRFakeWeightDYL_ = (TH1F*)infileDYL.Get("DRFakeWeight");
  TH1F *DRNoWeightingDYL_ = (TH1F*)infileDYL.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomDYL_ = (TH1F*)infileDYL.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomDYL_->Rebin(30);
  TH1F *TauVisMassDYL_ = (TH1F*)infileDYL.Get("TauVisMass");
  TH1F *TauVisMassZoomDYL_ = (TH1F*)infileDYL.Get("TauVisMassZoom");

  ////////////////
  // DYH
  ////////////////
  TH1F *InvMassTauMuMu1DYH_ = (TH1F*)infileDYH.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2DYH_ = (TH1F*)infileDYH.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightDYH_ = (TH1F*)infileDYH.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightDYH_ = (TH1F*)infileDYH.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightDYH_ = (TH1F*)infileDYH.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightDYH_ = (TH1F*)infileDYH.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightDYH_ = (TH1F*)infileDYH.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightDYH_ = (TH1F*)infileDYH.Get("EtaFakeWeight");
  TH1F *DRFakeWeightDYH_ = (TH1F*)infileDYH.Get("DRFakeWeight");
  TH1F *DRNoWeightingDYH_ = (TH1F*)infileDYH.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomDYH_ = (TH1F*)infileDYH.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomDYH_->Rebin(30);
  TH1F *TauVisMassDYH_ = (TH1F*)infileDYH.Get("TauVisMass");
  TH1F *TauVisMassZoomDYH_ = (TH1F*)infileDYH.Get("TauVisMassZoom");

  ////////////////
  // QCD_1000toInf
  ////////////////
  TH1F *InvMassTauMuMu1QCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2QCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("EtaFakeWeight");
  TH1F *DRFakeWeightQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DRFakeWeight");
  TH1F *DRNoWeightingQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomQCD_1000toInf_->Rebin(30);
  TH1F *TauVisMassQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("TauVisMass");
  TH1F *TauVisMassZoomQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("TauVisMassZoom");

  ////////////////
  // QCD_120to170
  ////////////////
  TH1F *InvMassTauMuMu1QCD_120to170_ = (TH1F*)infileQCD_120to170.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2QCD_120to170_ = (TH1F*)infileQCD_120to170.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("EtaFakeWeight");
  TH1F *DRFakeWeightQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DRFakeWeight");
  TH1F *DRNoWeightingQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomQCD_120to170_->Rebin(30);
  TH1F *TauVisMassQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("TauVisMass");
  TH1F *TauVisMassZoomQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("TauVisMassZoom");

  ////////////////
  // QCD_15to20
  ////////////////
  TH1F *InvMassTauMuMu1QCD_15to20_ = (TH1F*)infileQCD_15to20.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2QCD_15to20_ = (TH1F*)infileQCD_15to20.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("EtaFakeWeight");
  TH1F *DRFakeWeightQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DRFakeWeight");
  TH1F *DRNoWeightingQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomQCD_15to20_->Rebin(30);
  TH1F *TauVisMassQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("TauVisMass");
  TH1F *TauVisMassZoomQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("TauVisMassZoom");

  ////////////////
  // QCD_170to300
  ////////////////
  TH1F *InvMassTauMuMu1QCD_170to300_ = (TH1F*)infileQCD_170to300.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2QCD_170to300_ = (TH1F*)infileQCD_170to300.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("EtaFakeWeight");
  TH1F *DRFakeWeightQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DRFakeWeight");
  TH1F *DRNoWeightingQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomQCD_170to300_->Rebin(30);
  TH1F *TauVisMassQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("TauVisMass");
  TH1F *TauVisMassZoomQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("TauVisMassZoom");

  ////////////////
  // QCD_20to30
  ////////////////
  TH1F *InvMassTauMuMu1QCD_20to30_ = (TH1F*)infileQCD_20to30.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2QCD_20to30_ = (TH1F*)infileQCD_20to30.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("EtaFakeWeight");
  TH1F *DRFakeWeightQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DRFakeWeight");
  TH1F *DRNoWeightingQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomQCD_20to30_->Rebin(30);
  TH1F *TauVisMassQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("TauVisMass");
  TH1F *TauVisMassZoomQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("TauVisMassZoom");

  ////////////////
  // QCD_300to470
  ////////////////
  TH1F *InvMassTauMuMu1QCD_300to470_ = (TH1F*)infileQCD_300to470.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2QCD_300to470_ = (TH1F*)infileQCD_300to470.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("EtaFakeWeight");
  TH1F *DRFakeWeightQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DRFakeWeight");
  TH1F *DRNoWeightingQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomQCD_300to470_->Rebin(30);
  TH1F *TauVisMassQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("TauVisMass");
  TH1F *TauVisMassZoomQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("TauVisMassZoom");

  ////////////////
  // QCD_30to50
  ////////////////
  TH1F *InvMassTauMuMu1QCD_30to50_ = (TH1F*)infileQCD_30to50.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2QCD_30to50_ = (TH1F*)infileQCD_30to50.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("EtaFakeWeight");
  TH1F *DRFakeWeightQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DRFakeWeight");
  TH1F *DRNoWeightingQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomQCD_30to50_->Rebin(30);
  TH1F *TauVisMassQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("TauVisMass");
  TH1F *TauVisMassZoomQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("TauVisMassZoom");

  ////////////////
  // QCD_470to600
  ////////////////
  TH1F *InvMassTauMuMu1QCD_470to600_ = (TH1F*)infileQCD_470to600.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2QCD_470to600_ = (TH1F*)infileQCD_470to600.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("EtaFakeWeight");
  TH1F *DRFakeWeightQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DRFakeWeight");
  TH1F *DRNoWeightingQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomQCD_470to600_->Rebin(30);
  TH1F *TauVisMassQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("TauVisMass");
  TH1F *TauVisMassZoomQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("TauVisMassZoom");

  ////////////////
  // QCD_50to80
  ////////////////
  TH1F *InvMassTauMuMu1QCD_50to80_ = (TH1F*)infileQCD_50to80.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2QCD_50to80_ = (TH1F*)infileQCD_50to80.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("EtaFakeWeight");
  TH1F *DRFakeWeightQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DRFakeWeight");
  TH1F *DRNoWeightingQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomQCD_50to80_->Rebin(30);
  TH1F *TauVisMassQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("TauVisMass");
  TH1F *TauVisMassZoomQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("TauVisMassZoom");

  ////////////////
  // QCD_600to800
  ////////////////
  TH1F *InvMassTauMuMu1QCD_600to800_ = (TH1F*)infileQCD_600to800.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2QCD_600to800_ = (TH1F*)infileQCD_600to800.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("EtaFakeWeight");
  TH1F *DRFakeWeightQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DRFakeWeight");
  TH1F *DRNoWeightingQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomQCD_600to800_->Rebin(30);
  TH1F *TauVisMassQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("TauVisMass");
  TH1F *TauVisMassZoomQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("TauVisMassZoom");

  ////////////////
  // QCD_800to1000
  ////////////////
  TH1F *InvMassTauMuMu1QCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2QCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("EtaFakeWeight");
  TH1F *DRFakeWeightQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DRFakeWeight");
  TH1F *DRNoWeightingQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomQCD_800to1000_->Rebin(30);
  TH1F *TauVisMassQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("TauVisMass");
  TH1F *TauVisMassZoomQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("TauVisMassZoom");

  ////////////////
  // QCD_80to120
  ////////////////
  TH1F *InvMassTauMuMu1QCD_80to120_ = (TH1F*)infileQCD_80to120.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2QCD_80to120_ = (TH1F*)infileQCD_80to120.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("EtaFakeWeight");
  TH1F *DRFakeWeightQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DRFakeWeight");
  TH1F *DRNoWeightingQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomQCD_80to120_->Rebin(30);
  TH1F *TauVisMassQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("TauVisMass");
  TH1F *TauVisMassZoomQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("TauVisMassZoom");

  ////////////////
//  // h125a11
  ////////////////
//  TH1F *InvMassTauMuMu1h125a11_ = (TH1F*)infileh125a11.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h125a11_ = (TH1F*)infileh125a11.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth125a11_ = (TH1F*)infileh125a11.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth125a11_ = (TH1F*)infileh125a11.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth125a11_ = (TH1F*)infileh125a11.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth125a11_ = (TH1F*)infileh125a11.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth125a11_ = (TH1F*)infileh125a11.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth125a11_ = (TH1F*)infileh125a11.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth125a11_ = (TH1F*)infileh125a11.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh125a11_ = (TH1F*)infileh125a11.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh125a11_ = (TH1F*)infileh125a11.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh125a11_->Rebin(30);
//  TH1F *TauVisMassh125a11_ = (TH1F*)infileh125a11.Get("TauVisMass");
//  TH1F *TauVisMassZoomh125a11_ = (TH1F*)infileh125a11.Get("TauVisMassZoom");

  ////////////////
//  // h125a13
  ////////////////
//  TH1F *InvMassTauMuMu1h125a13_ = (TH1F*)infileh125a13.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h125a13_ = (TH1F*)infileh125a13.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth125a13_ = (TH1F*)infileh125a13.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth125a13_ = (TH1F*)infileh125a13.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth125a13_ = (TH1F*)infileh125a13.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth125a13_ = (TH1F*)infileh125a13.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth125a13_ = (TH1F*)infileh125a13.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth125a13_ = (TH1F*)infileh125a13.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth125a13_ = (TH1F*)infileh125a13.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh125a13_ = (TH1F*)infileh125a13.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh125a13_ = (TH1F*)infileh125a13.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh125a13_->Rebin(30);
//  TH1F *TauVisMassh125a13_ = (TH1F*)infileh125a13.Get("TauVisMass");
//  TH1F *TauVisMassZoomh125a13_ = (TH1F*)infileh125a13.Get("TauVisMassZoom");

  ////////////////
//  // h125a15
  ////////////////
//  TH1F *InvMassTauMuMu1h125a15_ = (TH1F*)infileh125a15.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h125a15_ = (TH1F*)infileh125a15.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth125a15_ = (TH1F*)infileh125a15.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth125a15_ = (TH1F*)infileh125a15.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth125a15_ = (TH1F*)infileh125a15.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth125a15_ = (TH1F*)infileh125a15.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth125a15_ = (TH1F*)infileh125a15.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth125a15_ = (TH1F*)infileh125a15.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth125a15_ = (TH1F*)infileh125a15.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh125a15_ = (TH1F*)infileh125a15.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh125a15_ = (TH1F*)infileh125a15.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh125a15_->Rebin(30);
//  TH1F *TauVisMassh125a15_ = (TH1F*)infileh125a15.Get("TauVisMass");
//  TH1F *TauVisMassZoomh125a15_ = (TH1F*)infileh125a15.Get("TauVisMassZoom");

  ////////////////
//  // h125a17
  ////////////////
//  TH1F *InvMassTauMuMu1h125a17_ = (TH1F*)infileh125a17.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h125a17_ = (TH1F*)infileh125a17.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth125a17_ = (TH1F*)infileh125a17.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth125a17_ = (TH1F*)infileh125a17.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth125a17_ = (TH1F*)infileh125a17.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth125a17_ = (TH1F*)infileh125a17.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth125a17_ = (TH1F*)infileh125a17.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth125a17_ = (TH1F*)infileh125a17.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth125a17_ = (TH1F*)infileh125a17.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh125a17_ = (TH1F*)infileh125a17.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh125a17_ = (TH1F*)infileh125a17.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh125a17_->Rebin(30);
//  TH1F *TauVisMassh125a17_ = (TH1F*)infileh125a17.Get("TauVisMass");
//  TH1F *TauVisMassZoomh125a17_ = (TH1F*)infileh125a17.Get("TauVisMassZoom");

  ////////////////
//  // h125a19
  ////////////////
//  TH1F *InvMassTauMuMu1h125a19_ = (TH1F*)infileh125a19.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h125a19_ = (TH1F*)infileh125a19.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth125a19_ = (TH1F*)infileh125a19.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth125a19_ = (TH1F*)infileh125a19.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth125a19_ = (TH1F*)infileh125a19.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth125a19_ = (TH1F*)infileh125a19.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth125a19_ = (TH1F*)infileh125a19.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth125a19_ = (TH1F*)infileh125a19.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth125a19_ = (TH1F*)infileh125a19.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh125a19_ = (TH1F*)infileh125a19.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh125a19_ = (TH1F*)infileh125a19.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh125a19_->Rebin(30);
//  TH1F *TauVisMassh125a19_ = (TH1F*)infileh125a19.Get("TauVisMass");
//  TH1F *TauVisMassZoomh125a19_ = (TH1F*)infileh125a19.Get("TauVisMassZoom");

  ////////////////
//  // h125a21
  ////////////////
//  TH1F *InvMassTauMuMu1h125a21_ = (TH1F*)infileh125a21.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h125a21_ = (TH1F*)infileh125a21.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth125a21_ = (TH1F*)infileh125a21.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth125a21_ = (TH1F*)infileh125a21.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth125a21_ = (TH1F*)infileh125a21.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth125a21_ = (TH1F*)infileh125a21.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth125a21_ = (TH1F*)infileh125a21.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth125a21_ = (TH1F*)infileh125a21.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth125a21_ = (TH1F*)infileh125a21.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh125a21_ = (TH1F*)infileh125a21.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh125a21_ = (TH1F*)infileh125a21.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh125a21_->Rebin(30);
//  TH1F *TauVisMassh125a21_ = (TH1F*)infileh125a21.Get("TauVisMass");
//  TH1F *TauVisMassZoomh125a21_ = (TH1F*)infileh125a21.Get("TauVisMassZoom");

  ////////////////
//  // h125a5
  ////////////////
//  TH1F *InvMassTauMuMu1h125a5_ = (TH1F*)infileh125a5.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h125a5_ = (TH1F*)infileh125a5.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth125a5_ = (TH1F*)infileh125a5.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth125a5_ = (TH1F*)infileh125a5.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth125a5_ = (TH1F*)infileh125a5.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth125a5_ = (TH1F*)infileh125a5.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth125a5_ = (TH1F*)infileh125a5.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth125a5_ = (TH1F*)infileh125a5.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth125a5_ = (TH1F*)infileh125a5.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh125a5_ = (TH1F*)infileh125a5.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh125a5_ = (TH1F*)infileh125a5.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh125a5_->Rebin(30);
//  TH1F *TauVisMassh125a5_ = (TH1F*)infileh125a5.Get("TauVisMass");
//  TH1F *TauVisMassZoomh125a5_ = (TH1F*)infileh125a5.Get("TauVisMassZoom");

  ////////////////
//  // h125a7
  ////////////////
//  TH1F *InvMassTauMuMu1h125a7_ = (TH1F*)infileh125a7.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h125a7_ = (TH1F*)infileh125a7.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth125a7_ = (TH1F*)infileh125a7.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth125a7_ = (TH1F*)infileh125a7.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth125a7_ = (TH1F*)infileh125a7.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth125a7_ = (TH1F*)infileh125a7.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth125a7_ = (TH1F*)infileh125a7.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth125a7_ = (TH1F*)infileh125a7.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth125a7_ = (TH1F*)infileh125a7.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh125a7_ = (TH1F*)infileh125a7.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh125a7_ = (TH1F*)infileh125a7.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh125a7_->Rebin(30);
//  TH1F *TauVisMassh125a7_ = (TH1F*)infileh125a7.Get("TauVisMass");
//  TH1F *TauVisMassZoomh125a7_ = (TH1F*)infileh125a7.Get("TauVisMassZoom");

  ////////////////
//  // h125a9
  ////////////////
//  TH1F *InvMassTauMuMu1h125a9_ = (TH1F*)infileh125a9.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h125a9_ = (TH1F*)infileh125a9.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth125a9_ = (TH1F*)infileh125a9.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth125a9_ = (TH1F*)infileh125a9.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth125a9_ = (TH1F*)infileh125a9.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth125a9_ = (TH1F*)infileh125a9.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth125a9_ = (TH1F*)infileh125a9.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth125a9_ = (TH1F*)infileh125a9.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth125a9_ = (TH1F*)infileh125a9.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh125a9_ = (TH1F*)infileh125a9.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh125a9_ = (TH1F*)infileh125a9.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh125a9_->Rebin(30);
//  TH1F *TauVisMassh125a9_ = (TH1F*)infileh125a9.Get("TauVisMass");
//  TH1F *TauVisMassZoomh125a9_ = (TH1F*)infileh125a9.Get("TauVisMassZoom");

  ////////////////
//  // h300a11
  ////////////////
//  TH1F *InvMassTauMuMu1h300a11_ = (TH1F*)infileh300a11.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h300a11_ = (TH1F*)infileh300a11.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth300a11_ = (TH1F*)infileh300a11.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth300a11_ = (TH1F*)infileh300a11.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth300a11_ = (TH1F*)infileh300a11.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth300a11_ = (TH1F*)infileh300a11.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth300a11_ = (TH1F*)infileh300a11.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth300a11_ = (TH1F*)infileh300a11.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth300a11_ = (TH1F*)infileh300a11.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh300a11_ = (TH1F*)infileh300a11.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh300a11_ = (TH1F*)infileh300a11.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh300a11_->Rebin(30);
//  TH1F *TauVisMassh300a11_ = (TH1F*)infileh300a11.Get("TauVisMass");
//  TH1F *TauVisMassZoomh300a11_ = (TH1F*)infileh300a11.Get("TauVisMassZoom");

  ////////////////
//  // h300a13
  ////////////////
//  TH1F *InvMassTauMuMu1h300a13_ = (TH1F*)infileh300a13.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h300a13_ = (TH1F*)infileh300a13.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth300a13_ = (TH1F*)infileh300a13.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth300a13_ = (TH1F*)infileh300a13.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth300a13_ = (TH1F*)infileh300a13.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth300a13_ = (TH1F*)infileh300a13.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth300a13_ = (TH1F*)infileh300a13.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth300a13_ = (TH1F*)infileh300a13.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth300a13_ = (TH1F*)infileh300a13.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh300a13_ = (TH1F*)infileh300a13.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh300a13_ = (TH1F*)infileh300a13.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh300a13_->Rebin(30);
//  TH1F *TauVisMassh300a13_ = (TH1F*)infileh300a13.Get("TauVisMass");
//  TH1F *TauVisMassZoomh300a13_ = (TH1F*)infileh300a13.Get("TauVisMassZoom");

  ////////////////
//  // h300a15
  ////////////////
//  TH1F *InvMassTauMuMu1h300a15_ = (TH1F*)infileh300a15.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h300a15_ = (TH1F*)infileh300a15.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth300a15_ = (TH1F*)infileh300a15.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth300a15_ = (TH1F*)infileh300a15.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth300a15_ = (TH1F*)infileh300a15.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth300a15_ = (TH1F*)infileh300a15.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth300a15_ = (TH1F*)infileh300a15.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth300a15_ = (TH1F*)infileh300a15.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth300a15_ = (TH1F*)infileh300a15.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh300a15_ = (TH1F*)infileh300a15.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh300a15_ = (TH1F*)infileh300a15.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh300a15_->Rebin(30);
//  TH1F *TauVisMassh300a15_ = (TH1F*)infileh300a15.Get("TauVisMass");
//  TH1F *TauVisMassZoomh300a15_ = (TH1F*)infileh300a15.Get("TauVisMassZoom");

  ////////////////
//  // h300a17
  ////////////////
//  TH1F *InvMassTauMuMu1h300a17_ = (TH1F*)infileh300a17.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h300a17_ = (TH1F*)infileh300a17.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth300a17_ = (TH1F*)infileh300a17.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth300a17_ = (TH1F*)infileh300a17.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth300a17_ = (TH1F*)infileh300a17.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth300a17_ = (TH1F*)infileh300a17.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth300a17_ = (TH1F*)infileh300a17.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth300a17_ = (TH1F*)infileh300a17.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth300a17_ = (TH1F*)infileh300a17.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh300a17_ = (TH1F*)infileh300a17.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh300a17_ = (TH1F*)infileh300a17.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh300a17_->Rebin(30);
//  TH1F *TauVisMassh300a17_ = (TH1F*)infileh300a17.Get("TauVisMass");
//  TH1F *TauVisMassZoomh300a17_ = (TH1F*)infileh300a17.Get("TauVisMassZoom");

  ////////////////
//  // h300a19
  ////////////////
//  TH1F *InvMassTauMuMu1h300a19_ = (TH1F*)infileh300a19.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h300a19_ = (TH1F*)infileh300a19.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth300a19_ = (TH1F*)infileh300a19.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth300a19_ = (TH1F*)infileh300a19.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth300a19_ = (TH1F*)infileh300a19.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth300a19_ = (TH1F*)infileh300a19.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth300a19_ = (TH1F*)infileh300a19.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth300a19_ = (TH1F*)infileh300a19.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth300a19_ = (TH1F*)infileh300a19.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh300a19_ = (TH1F*)infileh300a19.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh300a19_ = (TH1F*)infileh300a19.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh300a19_->Rebin(30);
//  TH1F *TauVisMassh300a19_ = (TH1F*)infileh300a19.Get("TauVisMass");
//  TH1F *TauVisMassZoomh300a19_ = (TH1F*)infileh300a19.Get("TauVisMassZoom");

  ////////////////
//  // h300a21
  ////////////////
//  TH1F *InvMassTauMuMu1h300a21_ = (TH1F*)infileh300a21.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h300a21_ = (TH1F*)infileh300a21.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth300a21_ = (TH1F*)infileh300a21.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth300a21_ = (TH1F*)infileh300a21.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth300a21_ = (TH1F*)infileh300a21.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth300a21_ = (TH1F*)infileh300a21.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth300a21_ = (TH1F*)infileh300a21.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth300a21_ = (TH1F*)infileh300a21.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth300a21_ = (TH1F*)infileh300a21.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh300a21_ = (TH1F*)infileh300a21.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh300a21_ = (TH1F*)infileh300a21.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh300a21_->Rebin(30);
//  TH1F *TauVisMassh300a21_ = (TH1F*)infileh300a21.Get("TauVisMass");
//  TH1F *TauVisMassZoomh300a21_ = (TH1F*)infileh300a21.Get("TauVisMassZoom");

  ////////////////
//  // h300a5
  ////////////////
//  TH1F *InvMassTauMuMu1h300a5_ = (TH1F*)infileh300a5.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h300a5_ = (TH1F*)infileh300a5.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth300a5_ = (TH1F*)infileh300a5.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth300a5_ = (TH1F*)infileh300a5.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth300a5_ = (TH1F*)infileh300a5.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth300a5_ = (TH1F*)infileh300a5.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth300a5_ = (TH1F*)infileh300a5.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth300a5_ = (TH1F*)infileh300a5.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth300a5_ = (TH1F*)infileh300a5.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh300a5_ = (TH1F*)infileh300a5.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh300a5_ = (TH1F*)infileh300a5.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh300a5_->Rebin(30);
//  TH1F *TauVisMassh300a5_ = (TH1F*)infileh300a5.Get("TauVisMass");
//  TH1F *TauVisMassZoomh300a5_ = (TH1F*)infileh300a5.Get("TauVisMassZoom");

  ////////////////
//  // h300a7
  ////////////////
//  TH1F *InvMassTauMuMu1h300a7_ = (TH1F*)infileh300a7.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h300a7_ = (TH1F*)infileh300a7.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth300a7_ = (TH1F*)infileh300a7.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth300a7_ = (TH1F*)infileh300a7.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth300a7_ = (TH1F*)infileh300a7.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth300a7_ = (TH1F*)infileh300a7.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth300a7_ = (TH1F*)infileh300a7.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth300a7_ = (TH1F*)infileh300a7.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth300a7_ = (TH1F*)infileh300a7.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh300a7_ = (TH1F*)infileh300a7.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh300a7_ = (TH1F*)infileh300a7.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh300a7_->Rebin(30);
//  TH1F *TauVisMassh300a7_ = (TH1F*)infileh300a7.Get("TauVisMass");
//  TH1F *TauVisMassZoomh300a7_ = (TH1F*)infileh300a7.Get("TauVisMassZoom");

  ////////////////
//  // h300a9
  ////////////////
//  TH1F *InvMassTauMuMu1h300a9_ = (TH1F*)infileh300a9.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h300a9_ = (TH1F*)infileh300a9.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth300a9_ = (TH1F*)infileh300a9.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth300a9_ = (TH1F*)infileh300a9.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth300a9_ = (TH1F*)infileh300a9.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth300a9_ = (TH1F*)infileh300a9.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth300a9_ = (TH1F*)infileh300a9.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth300a9_ = (TH1F*)infileh300a9.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth300a9_ = (TH1F*)infileh300a9.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh300a9_ = (TH1F*)infileh300a9.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh300a9_ = (TH1F*)infileh300a9.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh300a9_->Rebin(30);
//  TH1F *TauVisMassh300a9_ = (TH1F*)infileh300a9.Get("TauVisMass");
//  TH1F *TauVisMassZoomh300a9_ = (TH1F*)infileh300a9.Get("TauVisMassZoom");

  ////////////////
//  // h750a11
  ////////////////
//  TH1F *InvMassTauMuMu1h750a11_ = (TH1F*)infileh750a11.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h750a11_ = (TH1F*)infileh750a11.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth750a11_ = (TH1F*)infileh750a11.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth750a11_ = (TH1F*)infileh750a11.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth750a11_ = (TH1F*)infileh750a11.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth750a11_ = (TH1F*)infileh750a11.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth750a11_ = (TH1F*)infileh750a11.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth750a11_ = (TH1F*)infileh750a11.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth750a11_ = (TH1F*)infileh750a11.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh750a11_ = (TH1F*)infileh750a11.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh750a11_ = (TH1F*)infileh750a11.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh750a11_->Rebin(30);
//  TH1F *TauVisMassh750a11_ = (TH1F*)infileh750a11.Get("TauVisMass");
//  TH1F *TauVisMassZoomh750a11_ = (TH1F*)infileh750a11.Get("TauVisMassZoom");

  ////////////////
//  // h750a13
  ////////////////
//  TH1F *InvMassTauMuMu1h750a13_ = (TH1F*)infileh750a13.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h750a13_ = (TH1F*)infileh750a13.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth750a13_ = (TH1F*)infileh750a13.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth750a13_ = (TH1F*)infileh750a13.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth750a13_ = (TH1F*)infileh750a13.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth750a13_ = (TH1F*)infileh750a13.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth750a13_ = (TH1F*)infileh750a13.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth750a13_ = (TH1F*)infileh750a13.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth750a13_ = (TH1F*)infileh750a13.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh750a13_ = (TH1F*)infileh750a13.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh750a13_ = (TH1F*)infileh750a13.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh750a13_->Rebin(30);
//  TH1F *TauVisMassh750a13_ = (TH1F*)infileh750a13.Get("TauVisMass");
//  TH1F *TauVisMassZoomh750a13_ = (TH1F*)infileh750a13.Get("TauVisMassZoom");

  ////////////////
//  // h750a15
  ////////////////
//  TH1F *InvMassTauMuMu1h750a15_ = (TH1F*)infileh750a15.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h750a15_ = (TH1F*)infileh750a15.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth750a15_ = (TH1F*)infileh750a15.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth750a15_ = (TH1F*)infileh750a15.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth750a15_ = (TH1F*)infileh750a15.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth750a15_ = (TH1F*)infileh750a15.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth750a15_ = (TH1F*)infileh750a15.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth750a15_ = (TH1F*)infileh750a15.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth750a15_ = (TH1F*)infileh750a15.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh750a15_ = (TH1F*)infileh750a15.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh750a15_ = (TH1F*)infileh750a15.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh750a15_->Rebin(30);
//  TH1F *TauVisMassh750a15_ = (TH1F*)infileh750a15.Get("TauVisMass");
//  TH1F *TauVisMassZoomh750a15_ = (TH1F*)infileh750a15.Get("TauVisMassZoom");

  ////////////////
//  // h750a17
  ////////////////
//  TH1F *InvMassTauMuMu1h750a17_ = (TH1F*)infileh750a17.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h750a17_ = (TH1F*)infileh750a17.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth750a17_ = (TH1F*)infileh750a17.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth750a17_ = (TH1F*)infileh750a17.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth750a17_ = (TH1F*)infileh750a17.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth750a17_ = (TH1F*)infileh750a17.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth750a17_ = (TH1F*)infileh750a17.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth750a17_ = (TH1F*)infileh750a17.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth750a17_ = (TH1F*)infileh750a17.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh750a17_ = (TH1F*)infileh750a17.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh750a17_ = (TH1F*)infileh750a17.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh750a17_->Rebin(30);
//  TH1F *TauVisMassh750a17_ = (TH1F*)infileh750a17.Get("TauVisMass");
//  TH1F *TauVisMassZoomh750a17_ = (TH1F*)infileh750a17.Get("TauVisMassZoom");

  ////////////////
//  // h750a19
  ////////////////
//  TH1F *InvMassTauMuMu1h750a19_ = (TH1F*)infileh750a19.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h750a19_ = (TH1F*)infileh750a19.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth750a19_ = (TH1F*)infileh750a19.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth750a19_ = (TH1F*)infileh750a19.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth750a19_ = (TH1F*)infileh750a19.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth750a19_ = (TH1F*)infileh750a19.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth750a19_ = (TH1F*)infileh750a19.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth750a19_ = (TH1F*)infileh750a19.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth750a19_ = (TH1F*)infileh750a19.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh750a19_ = (TH1F*)infileh750a19.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh750a19_ = (TH1F*)infileh750a19.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh750a19_->Rebin(30);
//  TH1F *TauVisMassh750a19_ = (TH1F*)infileh750a19.Get("TauVisMass");
//  TH1F *TauVisMassZoomh750a19_ = (TH1F*)infileh750a19.Get("TauVisMassZoom");

  ////////////////
//  // h750a21
  ////////////////
//  TH1F *InvMassTauMuMu1h750a21_ = (TH1F*)infileh750a21.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h750a21_ = (TH1F*)infileh750a21.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth750a21_ = (TH1F*)infileh750a21.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth750a21_ = (TH1F*)infileh750a21.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth750a21_ = (TH1F*)infileh750a21.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth750a21_ = (TH1F*)infileh750a21.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth750a21_ = (TH1F*)infileh750a21.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth750a21_ = (TH1F*)infileh750a21.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth750a21_ = (TH1F*)infileh750a21.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh750a21_ = (TH1F*)infileh750a21.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh750a21_ = (TH1F*)infileh750a21.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh750a21_->Rebin(30);
//  TH1F *TauVisMassh750a21_ = (TH1F*)infileh750a21.Get("TauVisMass");
//  TH1F *TauVisMassZoomh750a21_ = (TH1F*)infileh750a21.Get("TauVisMassZoom");

  ////////////////
//  // h750a5
  ////////////////
//  TH1F *InvMassTauMuMu1h750a5_ = (TH1F*)infileh750a5.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h750a5_ = (TH1F*)infileh750a5.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth750a5_ = (TH1F*)infileh750a5.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth750a5_ = (TH1F*)infileh750a5.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth750a5_ = (TH1F*)infileh750a5.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth750a5_ = (TH1F*)infileh750a5.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth750a5_ = (TH1F*)infileh750a5.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth750a5_ = (TH1F*)infileh750a5.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth750a5_ = (TH1F*)infileh750a5.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh750a5_ = (TH1F*)infileh750a5.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh750a5_ = (TH1F*)infileh750a5.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh750a5_->Rebin(30);
//  TH1F *TauVisMassh750a5_ = (TH1F*)infileh750a5.Get("TauVisMass");
//  TH1F *TauVisMassZoomh750a5_ = (TH1F*)infileh750a5.Get("TauVisMassZoom");

  ////////////////
//  // h750a7
  ////////////////
//  TH1F *InvMassTauMuMu1h750a7_ = (TH1F*)infileh750a7.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h750a7_ = (TH1F*)infileh750a7.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth750a7_ = (TH1F*)infileh750a7.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth750a7_ = (TH1F*)infileh750a7.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth750a7_ = (TH1F*)infileh750a7.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth750a7_ = (TH1F*)infileh750a7.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth750a7_ = (TH1F*)infileh750a7.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth750a7_ = (TH1F*)infileh750a7.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth750a7_ = (TH1F*)infileh750a7.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh750a7_ = (TH1F*)infileh750a7.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh750a7_ = (TH1F*)infileh750a7.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh750a7_->Rebin(30);
//  TH1F *TauVisMassh750a7_ = (TH1F*)infileh750a7.Get("TauVisMass");
//  TH1F *TauVisMassZoomh750a7_ = (TH1F*)infileh750a7.Get("TauVisMassZoom");

  ////////////////
//  // h750a9
  ////////////////
//  TH1F *InvMassTauMuMu1h750a9_ = (TH1F*)infileh750a9.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2h750a9_ = (TH1F*)infileh750a9.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeighth750a9_ = (TH1F*)infileh750a9.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeighth750a9_ = (TH1F*)infileh750a9.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeighth750a9_ = (TH1F*)infileh750a9.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeighth750a9_ = (TH1F*)infileh750a9.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeighth750a9_ = (TH1F*)infileh750a9.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeighth750a9_ = (TH1F*)infileh750a9.Get("EtaFakeWeight");
//  TH1F *DRFakeWeighth750a9_ = (TH1F*)infileh750a9.Get("DRFakeWeight");
//  TH1F *DRNoWeightingh750a9_ = (TH1F*)infileh750a9.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomh750a9_ = (TH1F*)infileh750a9.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomh750a9_->Rebin(30);
//  TH1F *TauVisMassh750a9_ = (TH1F*)infileh750a9.Get("TauVisMass");
//  TH1F *TauVisMassZoomh750a9_ = (TH1F*)infileh750a9.Get("TauVisMassZoom");


  ////////////////
  ////////////////

//  ////////////////
//  ////////////////
//
//  ////////////////
//  ////////////////
//
//  ////////////////
//  ////////////////
//
//  ////////////////
//  ////////////////
//
//  ////////////////
//  ////////////////
//
  ////////////////
  // ST_sch
  ////////////////
  TH1F *InvMassTauMuMu1ST_sch_ = (TH1F*)infileST_sch.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2ST_sch_ = (TH1F*)infileST_sch.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightST_sch_ = (TH1F*)infileST_sch.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightST_sch_ = (TH1F*)infileST_sch.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightST_sch_ = (TH1F*)infileST_sch.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightST_sch_ = (TH1F*)infileST_sch.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightST_sch_ = (TH1F*)infileST_sch.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightST_sch_ = (TH1F*)infileST_sch.Get("EtaFakeWeight");
  TH1F *DRFakeWeightST_sch_ = (TH1F*)infileST_sch.Get("DRFakeWeight");
  TH1F *DRNoWeightingST_sch_ = (TH1F*)infileST_sch.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomST_sch_ = (TH1F*)infileST_sch.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomST_sch_->Rebin(30);
  TH1F *TauVisMassST_sch_ = (TH1F*)infileST_sch.Get("TauVisMass");
  TH1F *TauVisMassZoomST_sch_ = (TH1F*)infileST_sch.Get("TauVisMassZoom");

  ////////////////
//  // ST_tch_top
  ////////////////
//  TH1F *InvMassTauMuMu1ST_tch_top_ = (TH1F*)infileST_tch_top.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2ST_tch_top_ = (TH1F*)infileST_tch_top.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeightST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeightST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeightST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeightST_tch_top_ = (TH1F*)infileST_tch_top.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeightST_tch_top_ = (TH1F*)infileST_tch_top.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeightST_tch_top_ = (TH1F*)infileST_tch_top.Get("EtaFakeWeight");
//  TH1F *DRFakeWeightST_tch_top_ = (TH1F*)infileST_tch_top.Get("DRFakeWeight");
//  TH1F *DRNoWeightingST_tch_top_ = (TH1F*)infileST_tch_top.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomST_tch_top_->Rebin(30);
//  TH1F *TauVisMassST_tch_top_ = (TH1F*)infileST_tch_top.Get("TauVisMass");
//  TH1F *TauVisMassZoomST_tch_top_ = (TH1F*)infileST_tch_top.Get("TauVisMassZoom");

  ////////////////
//  // ST_tWNoHad_top
  ////////////////
//  TH1F *InvMassTauMuMu1ST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2ST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeightST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeightST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeightST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeightST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeightST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeightST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("EtaFakeWeight");
//  TH1F *DRFakeWeightST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DRFakeWeight");
//  TH1F *DRNoWeightingST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomST_tWNoHad_top_->Rebin(30);
//  TH1F *TauVisMassST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("TauVisMass");
//  TH1F *TauVisMassZoomST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("TauVisMassZoom");

  ////////////////
  // ST_tWIncl_top
  ////////////////
  TH1F *InvMassTauMuMu1ST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2ST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("EtaFakeWeight");
  TH1F *DRFakeWeightST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DRFakeWeight");
  TH1F *DRNoWeightingST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomST_tWIncl_top_->Rebin(30);
  TH1F *TauVisMassST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("TauVisMass");
  TH1F *TauVisMassZoomST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("TauVisMassZoom");

  ////////////////
  // ST_tWIncl_antitop
  ////////////////
  TH1F *InvMassTauMuMu1ST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2ST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("EtaFakeWeight");
  TH1F *DRFakeWeightST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DRFakeWeight");
  TH1F *DRNoWeightingST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomST_tWIncl_antitop_->Rebin(30);
  TH1F *TauVisMassST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("TauVisMass");
  TH1F *TauVisMassZoomST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("TauVisMassZoom");

  ////////////////
  // ST_tch_antitop
  ////////////////
  TH1F *InvMassTauMuMu1ST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2ST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("EtaFakeWeight");
  TH1F *DRFakeWeightST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DRFakeWeight");
  TH1F *DRNoWeightingST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomST_tch_antitop_->Rebin(30);
  TH1F *TauVisMassST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("TauVisMass");
  TH1F *TauVisMassZoomST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("TauVisMassZoom");

  ////////////////
  // ST_tch_top
  ////////////////
  TH1F *InvMassTauMuMu1ST_tch_top_ = (TH1F*)infileST_tch_top.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2ST_tch_top_ = (TH1F*)infileST_tch_top.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightST_tch_top_ = (TH1F*)infileST_tch_top.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightST_tch_top_ = (TH1F*)infileST_tch_top.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightST_tch_top_ = (TH1F*)infileST_tch_top.Get("EtaFakeWeight");
  TH1F *DRFakeWeightST_tch_top_ = (TH1F*)infileST_tch_top.Get("DRFakeWeight");
  TH1F *DRNoWeightingST_tch_top_ = (TH1F*)infileST_tch_top.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomST_tch_top_->Rebin(30);
  TH1F *TauVisMassST_tch_top_ = (TH1F*)infileST_tch_top.Get("TauVisMass");
  TH1F *TauVisMassZoomST_tch_top_ = (TH1F*)infileST_tch_top.Get("TauVisMassZoom");

  ////////////////
  // Up
  ////////////////
  TH1F *InvMassTauMuMu1Up_ = (TH1F*)infileUp.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2Up_ = (TH1F*)infileUp.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightUp_ = (TH1F*)infileUp.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightUp_ = (TH1F*)infileUp.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightUp_ = (TH1F*)infileUp.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightUp_ = (TH1F*)infileUp.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightUp_ = (TH1F*)infileUp.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightUp_ = (TH1F*)infileUp.Get("EtaFakeWeight");
  TH1F *DRFakeWeightUp_ = (TH1F*)infileUp.Get("DRFakeWeight");
  TH1F *DRNoWeightingUp_ = (TH1F*)infileUp.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomUp_ = (TH1F*)infileUp.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomUp_->Rebin(30);
  TH1F *TauVisMassUp_ = (TH1F*)infileUp.Get("TauVisMass");
  TH1F *TauVisMassZoomUp_ = (TH1F*)infileUp.Get("TauVisMassZoom");

//  ////////////////
//  // VV
  ////////////////
//  TH1F *InvMassTauMuMu1VV_ = (TH1F*)infileVV.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2VV_ = (TH1F*)infileVV.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeightVV_ = (TH1F*)infileVV.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeightVV_ = (TH1F*)infileVV.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeightVV_ = (TH1F*)infileVV.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeightVV_ = (TH1F*)infileVV.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeightVV_ = (TH1F*)infileVV.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeightVV_ = (TH1F*)infileVV.Get("EtaFakeWeight");
//  TH1F *DRFakeWeightVV_ = (TH1F*)infileVV.Get("DRFakeWeight");
//  TH1F *DRNoWeightingVV_ = (TH1F*)infileVV.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomVV_ = (TH1F*)infileVV.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomVV_->Rebin(30);
//  TH1F *TauVisMassVV_ = (TH1F*)infileVV.Get("TauVisMass");
//  TH1F *TauVisMassZoomVV_ = (TH1F*)infileVV.Get("TauVisMassZoom");

  ////////////////
  // WJAmac
  ////////////////
  TH1F *InvMassTauMuMu1WJAmac_ = (TH1F*)infileWJAmac.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2WJAmac_ = (TH1F*)infileWJAmac.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightWJAmac_ = (TH1F*)infileWJAmac.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightWJAmac_ = (TH1F*)infileWJAmac.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightWJAmac_ = (TH1F*)infileWJAmac.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightWJAmac_ = (TH1F*)infileWJAmac.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightWJAmac_ = (TH1F*)infileWJAmac.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightWJAmac_ = (TH1F*)infileWJAmac.Get("EtaFakeWeight");
  TH1F *DRFakeWeightWJAmac_ = (TH1F*)infileWJAmac.Get("DRFakeWeight");
  TH1F *DRNoWeightingWJAmac_ = (TH1F*)infileWJAmac.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomWJAmac_ = (TH1F*)infileWJAmac.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomWJAmac_->Rebin(30);
  TH1F *TauVisMassWJAmac_ = (TH1F*)infileWJAmac.Get("TauVisMass");
  TH1F *TauVisMassZoomWJAmac_ = (TH1F*)infileWJAmac.Get("TauVisMassZoom");

  ////////////////
//  // WJMad
//  ////////////////
//  TH1F *InvMassTauMuMu1WJMad_ = (TH1F*)infileWJMad.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2WJMad_ = (TH1F*)infileWJMad.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeightWJMad_ = (TH1F*)infileWJMad.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeightWJMad_ = (TH1F*)infileWJMad.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeightWJMad_ = (TH1F*)infileWJMad.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeightWJMad_ = (TH1F*)infileWJMad.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeightWJMad_ = (TH1F*)infileWJMad.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeightWJMad_ = (TH1F*)infileWJMad.Get("EtaFakeWeight");
//  TH1F *DRFakeWeightWJMad_ = (TH1F*)infileWJMad.Get("DRFakeWeight");
//  TH1F *DRNoWeightingWJMad_ = (TH1F*)infileWJMad.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomWJMad_ = (TH1F*)infileWJMad.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomWJMad_->Rebin(30);
//  TH1F *TauVisMassWJMad_ = (TH1F*)infileWJMad.Get("TauVisMass");
//  TH1F *TauVisMassZoomWJMad_ = (TH1F*)infileWJMad.Get("TauVisMassZoom");
//
  ////////////////
  // WZ
  ////////////////
  TH1F *InvMassTauMuMu1WZ_ = (TH1F*)infileWZ.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2WZ_ = (TH1F*)infileWZ.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightWZ_ = (TH1F*)infileWZ.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightWZ_ = (TH1F*)infileWZ.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightWZ_ = (TH1F*)infileWZ.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightWZ_ = (TH1F*)infileWZ.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightWZ_ = (TH1F*)infileWZ.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightWZ_ = (TH1F*)infileWZ.Get("EtaFakeWeight");
  TH1F *DRFakeWeightWZ_ = (TH1F*)infileWZ.Get("DRFakeWeight");
  TH1F *DRNoWeightingWZ_ = (TH1F*)infileWZ.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomWZ_ = (TH1F*)infileWZ.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomWZ_->Rebin(30);
  TH1F *TauVisMassWZ_ = (TH1F*)infileWZ.Get("TauVisMass");
  TH1F *TauVisMassZoomWZ_ = (TH1F*)infileWZ.Get("TauVisMassZoom");

  ////////////////
  // ZZ2L2Nu
  ////////////////
  TH1F *InvMassTauMuMu1ZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2ZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("EtaFakeWeight");
  TH1F *DRFakeWeightZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DRFakeWeight");
  TH1F *DRNoWeightingZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomZZ2L2Nu_->Rebin(30);
  TH1F *TauVisMassZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("TauVisMass");
  TH1F *TauVisMassZoomZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("TauVisMassZoom");

  ////////////////
  // ZZ2L2Q
  ////////////////
  TH1F *InvMassTauMuMu1ZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2ZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("EtaFakeWeight");
  TH1F *DRFakeWeightZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DRFakeWeight");
  TH1F *DRNoWeightingZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomZZ2L2Q_->Rebin(30);
  TH1F *TauVisMassZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("TauVisMass");
  TH1F *TauVisMassZoomZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("TauVisMassZoom");

  ////////////////
  // ZZ4LAmac
  ////////////////
  TH1F *InvMassTauMuMu1ZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2ZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("EtaFakeWeight");
  TH1F *DRFakeWeightZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DRFakeWeight");
  TH1F *DRNoWeightingZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomZZ4LAmac_->Rebin(30);
  TH1F *TauVisMassZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("TauVisMass");
  TH1F *TauVisMassZoomZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("TauVisMassZoom");

//  ////////////////
//  // ZZ4LPowh
//  ////////////////
//  TH1F *InvMassTauMuMu1ZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("InvMassTauMuMu1");
//  TH1F *InvMassTauMuMu2ZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("InvMassTauMuMu2");
//  TH1F *DiMuInvMassFakeWeightZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DiMuInvMassFakeWeight");
//  TH1F *DiMuDiTauInvMassFakeWeightZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DiMuDiTauInvMassFakeWeight");
//  TH1F *DiTauInvMassFakeWeightZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DiTauInvMassFakeWeight");
//  TH1F *PtMu1FakeWeightZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("PtMu1FakeWeight");
//  TH1F *PtMu2FakeWeightZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("PtMu2FakeWeight");
//  TH1F *EtaFakeWeightZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("EtaFakeWeight");
//  TH1F *DRFakeWeightZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DRFakeWeight");
//  TH1F *DRNoWeightingZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DRNoWeighting");
//  TH1F *DiMuInvMassFakeWeightZoomZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DiMuInvMassFakeWeightZoom");
//  DiMuInvMassFakeWeightZoomZZ4LPowh_->Rebin(30);
//  TH1F *TauVisMassZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("TauVisMass");
//  TH1F *TauVisMassZoomZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("TauVisMassZoom");
//
//
  ////////////////
  // JPsi
  ////////////////
  TH1F *InvMassTauMuMu1JPsi_ = (TH1F*)infileJPsi.Get("InvMassTauMuMu1");
  TH1F *InvMassTauMuMu2JPsi_ = (TH1F*)infileJPsi.Get("InvMassTauMuMu2");
  TH1F *DiMuInvMassFakeWeightJPsi_ = (TH1F*)infileJPsi.Get("DiMuInvMassFakeWeight");
  TH1F *DiMuDiTauInvMassFakeWeightJPsi_ = (TH1F*)infileJPsi.Get("DiMuDiTauInvMassFakeWeight");
  TH1F *DiTauInvMassFakeWeightJPsi_ = (TH1F*)infileJPsi.Get("DiTauInvMassFakeWeight");
  TH1F *PtMu1FakeWeightJPsi_ = (TH1F*)infileJPsi.Get("PtMu1FakeWeight");
  TH1F *PtMu2FakeWeightJPsi_ = (TH1F*)infileJPsi.Get("PtMu2FakeWeight");
  TH1F *EtaFakeWeightJPsi_ = (TH1F*)infileJPsi.Get("EtaFakeWeight");
  TH1F *DRFakeWeightJPsi_ = (TH1F*)infileJPsi.Get("DRFakeWeight");
  TH1F *DRNoWeightingJPsi_ = (TH1F*)infileJPsi.Get("DRNoWeighting");
  TH1F *DiMuInvMassFakeWeightZoomJPsi_ = (TH1F*)infileJPsi.Get("DiMuInvMassFakeWeightZoom");
  DiMuInvMassFakeWeightZoomJPsi_->Rebin(30);
  TH1F *TauVisMassJPsi_ = (TH1F*)infileJPsi.Get("TauVisMass");
  TH1F *TauVisMassZoomJPsi_ = (TH1F*)infileJPsi.Get("TauVisMassZoom");

cout << "Got Histograms from Canvases" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the QCD Combined Canvas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *InvMassTauMuMu1CanvasQCD = new TCanvas ("InvMassTauMuMu1CanvasQCD","",600,600); 
  TCanvas *InvMassTauMuMu2CanvasQCD = new TCanvas ("InvMassTauMuMu2CanvasQCD","",600,600); 
  TCanvas *DiMuInvMassFakeWeightCanvasQCD = new TCanvas ("DiMuInvMassFakeWeightCanvasQCD","",600,600); 
  TCanvas *DiMuDiTauInvMassFakeWeightCanvasQCD = new TCanvas ("DiMuDiTauInvMassFakeWeightCanvasQCD","",600,600); 
  TCanvas *DiTauInvMassFakeWeightCanvasQCD = new TCanvas ("DiTauInvMassFakeWeightCanvasQCD","",600,600); 
  TCanvas *PtMu1FakeWeightCanvasQCD = new TCanvas ("PtMu1FakeWeightCanvasQCD","",600,600); 
  TCanvas *PtMu2FakeWeightCanvasQCD = new TCanvas ("PtMu2FakeWeightCanvasQCD","",600,600); 
  TCanvas *EtaFakeWeightCanvasQCD = new TCanvas ("EtaFakeWeightCanvasQCD","",600,600); 
  TCanvas *DRFakeWeightCanvasQCD = new TCanvas ("DRFakeWeightCanvasQCD","",600,600); 
  TCanvas *DRNoWeightingCanvasQCD = new TCanvas ("DRNoWeightingCanvasQCD","",600,600); 
  TCanvas *DiMuInvMassFakeWeightZoomCanvasQCD = new TCanvas ("DiMuInvMassFakeWeightZoomCanvasQCD","",600,600); 
  TCanvas *TauVisMassCanvasQCD = new TCanvas ("TauVisMassCanvasQCD","",600,600); 
  TCanvas *TauVisMassZoomCanvasQCD = new TCanvas ("TauVisMassZoomCanvasQCD","",600,600); 

  TH1F *InvMassTauMuMu1QCD_ = new TH1F ("InvMassTauMuMu1QCD","", InvMassTauMuMu1QCD_15to20_->GetNbinsX(), InvMassTauMuMu1QCD_15to20_->GetXaxis()->GetXmin(),  InvMassTauMuMu1QCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *InvMassTauMuMu2QCD_ = new TH1F ("InvMassTauMuMu2QCD","",InvMassTauMuMu2QCD_15to20_->GetNbinsX(), InvMassTauMuMu2QCD_15to20_->GetXaxis()->GetXmin(),  InvMassTauMuMu2QCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DiMuInvMassFakeWeightQCD_ = new TH1F ("DiMuInvMassFakeWeightQCD","",DiMuInvMassFakeWeightQCD_15to20_->GetNbinsX(), DiMuInvMassFakeWeightQCD_15to20_->GetXaxis()->GetXmin(),  DiMuInvMassFakeWeightQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DiMuDiTauInvMassFakeWeightQCD_ = new TH1F ("DiMuDiTauInvMassFakeWeightQCD","",DiMuDiTauInvMassFakeWeightQCD_15to20_->GetNbinsX(), DiMuDiTauInvMassFakeWeightQCD_15to20_->GetXaxis()->GetXmin(),  DiMuDiTauInvMassFakeWeightQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DiTauInvMassFakeWeightQCD_ = new TH1F ("DiTauInvMassFakeWeightQCD","",DiTauInvMassFakeWeightQCD_15to20_->GetNbinsX(), DiTauInvMassFakeWeightQCD_15to20_->GetXaxis()->GetXmin(),  DiTauInvMassFakeWeightQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *PtMu1FakeWeightQCD_ = new TH1F ("PtMu1FakeWeightQCD","",PtMu1FakeWeightQCD_15to20_->GetNbinsX(), PtMu1FakeWeightQCD_15to20_->GetXaxis()->GetXmin(),  PtMu1FakeWeightQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *PtMu2FakeWeightQCD_ = new TH1F ("PtMu2FakeWeightQCD","",PtMu2FakeWeightQCD_15to20_->GetNbinsX(), PtMu2FakeWeightQCD_15to20_->GetXaxis()->GetXmin(),  PtMu2FakeWeightQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *EtaFakeWeightQCD_ = new TH1F ("EtaFakeWeightQCD","",EtaFakeWeightQCD_15to20_->GetNbinsX(), EtaFakeWeightQCD_15to20_->GetXaxis()->GetXmin(),  EtaFakeWeightQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DRFakeWeightQCD_ = new TH1F ("DRFakeWeightQCD","",DRFakeWeightQCD_15to20_->GetNbinsX(), DRFakeWeightQCD_15to20_->GetXaxis()->GetXmin(),  DRFakeWeightQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DRNoWeightingQCD_ = new TH1F ("DRNoWeightingQCD","",DRNoWeightingQCD_15to20_->GetNbinsX(), DRNoWeightingQCD_15to20_->GetXaxis()->GetXmin(),  DRNoWeightingQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DiMuInvMassFakeWeightZoomQCD_ = new TH1F ("DiMuInvMassFakeWeightZoomQCD","",DiMuInvMassFakeWeightZoomQCD_15to20_->GetNbinsX(), DiMuInvMassFakeWeightZoomQCD_15to20_->GetXaxis()->GetXmin(),  DiMuInvMassFakeWeightZoomQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *TauVisMassQCD_ = new TH1F ("TauVisMassQCD","",TauVisMassQCD_15to20_->GetNbinsX(), TauVisMassQCD_15to20_->GetXaxis()->GetXmin(),  TauVisMassQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *TauVisMassZoomQCD_ = new TH1F ("TauVisMassZoomQCD","",TauVisMassZoomQCD_15to20_->GetNbinsX(), TauVisMassZoomQCD_15to20_->GetXaxis()->GetXmin(),  TauVisMassZoomQCD_15to20_->GetXaxis()->GetXmax() );


  InvMassTauMuMu1CanvasQCD->cd();
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD_15to20_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD_20to30_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD_30to50_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD_50to80_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD_80to120_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD_120to170_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD_170to300_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD_300to470_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD_470to600_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD_600to800_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD_800to1000_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD_1000toInf_);

  InvMassTauMuMu2CanvasQCD->cd();
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD_15to20_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD_20to30_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD_30to50_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD_50to80_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD_80to120_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD_120to170_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD_170to300_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD_300to470_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD_470to600_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD_600to800_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD_800to1000_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD_1000toInf_);

  DiMuInvMassFakeWeightCanvasQCD->cd();
  DiMuInvMassFakeWeightQCD_->Add(DiMuInvMassFakeWeightQCD_15to20_);
  DiMuInvMassFakeWeightQCD_->Add(DiMuInvMassFakeWeightQCD_20to30_);
  DiMuInvMassFakeWeightQCD_->Add(DiMuInvMassFakeWeightQCD_30to50_);
  DiMuInvMassFakeWeightQCD_->Add(DiMuInvMassFakeWeightQCD_50to80_);
  DiMuInvMassFakeWeightQCD_->Add(DiMuInvMassFakeWeightQCD_80to120_);
  DiMuInvMassFakeWeightQCD_->Add(DiMuInvMassFakeWeightQCD_120to170_);
  DiMuInvMassFakeWeightQCD_->Add(DiMuInvMassFakeWeightQCD_170to300_);
  DiMuInvMassFakeWeightQCD_->Add(DiMuInvMassFakeWeightQCD_300to470_);
  DiMuInvMassFakeWeightQCD_->Add(DiMuInvMassFakeWeightQCD_470to600_);
  DiMuInvMassFakeWeightQCD_->Add(DiMuInvMassFakeWeightQCD_600to800_);
  DiMuInvMassFakeWeightQCD_->Add(DiMuInvMassFakeWeightQCD_800to1000_);
  DiMuInvMassFakeWeightQCD_->Add(DiMuInvMassFakeWeightQCD_1000toInf_);

  DiMuDiTauInvMassFakeWeightCanvasQCD->cd();
  DiMuDiTauInvMassFakeWeightQCD_->Add(DiMuDiTauInvMassFakeWeightQCD_15to20_);
  DiMuDiTauInvMassFakeWeightQCD_->Add(DiMuDiTauInvMassFakeWeightQCD_20to30_);
  DiMuDiTauInvMassFakeWeightQCD_->Add(DiMuDiTauInvMassFakeWeightQCD_30to50_);
  DiMuDiTauInvMassFakeWeightQCD_->Add(DiMuDiTauInvMassFakeWeightQCD_50to80_);
  DiMuDiTauInvMassFakeWeightQCD_->Add(DiMuDiTauInvMassFakeWeightQCD_80to120_);
  DiMuDiTauInvMassFakeWeightQCD_->Add(DiMuDiTauInvMassFakeWeightQCD_120to170_);
  DiMuDiTauInvMassFakeWeightQCD_->Add(DiMuDiTauInvMassFakeWeightQCD_170to300_);
  DiMuDiTauInvMassFakeWeightQCD_->Add(DiMuDiTauInvMassFakeWeightQCD_300to470_);
  DiMuDiTauInvMassFakeWeightQCD_->Add(DiMuDiTauInvMassFakeWeightQCD_470to600_);
  DiMuDiTauInvMassFakeWeightQCD_->Add(DiMuDiTauInvMassFakeWeightQCD_600to800_);
  DiMuDiTauInvMassFakeWeightQCD_->Add(DiMuDiTauInvMassFakeWeightQCD_800to1000_);
  DiMuDiTauInvMassFakeWeightQCD_->Add(DiMuDiTauInvMassFakeWeightQCD_1000toInf_);

  DiTauInvMassFakeWeightCanvasQCD->cd();
  DiTauInvMassFakeWeightQCD_->Add(DiTauInvMassFakeWeightQCD_15to20_);
  DiTauInvMassFakeWeightQCD_->Add(DiTauInvMassFakeWeightQCD_20to30_);
  DiTauInvMassFakeWeightQCD_->Add(DiTauInvMassFakeWeightQCD_30to50_);
  DiTauInvMassFakeWeightQCD_->Add(DiTauInvMassFakeWeightQCD_50to80_);
  DiTauInvMassFakeWeightQCD_->Add(DiTauInvMassFakeWeightQCD_80to120_);
  DiTauInvMassFakeWeightQCD_->Add(DiTauInvMassFakeWeightQCD_120to170_);
  DiTauInvMassFakeWeightQCD_->Add(DiTauInvMassFakeWeightQCD_170to300_);
  DiTauInvMassFakeWeightQCD_->Add(DiTauInvMassFakeWeightQCD_300to470_);
  DiTauInvMassFakeWeightQCD_->Add(DiTauInvMassFakeWeightQCD_470to600_);
  DiTauInvMassFakeWeightQCD_->Add(DiTauInvMassFakeWeightQCD_600to800_);
  DiTauInvMassFakeWeightQCD_->Add(DiTauInvMassFakeWeightQCD_800to1000_);
  DiTauInvMassFakeWeightQCD_->Add(DiTauInvMassFakeWeightQCD_1000toInf_);

  PtMu1FakeWeightCanvasQCD->cd();
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD_15to20_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD_20to30_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD_30to50_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD_50to80_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD_80to120_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD_120to170_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD_170to300_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD_300to470_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD_470to600_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD_600to800_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD_800to1000_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD_1000toInf_);

  PtMu2FakeWeightCanvasQCD->cd();
  PtMu2FakeWeightQCD_->Add(PtMu2FakeWeightQCD_15to20_);
  PtMu2FakeWeightQCD_->Add(PtMu2FakeWeightQCD_20to30_);
  PtMu2FakeWeightQCD_->Add(PtMu2FakeWeightQCD_30to50_);
  PtMu2FakeWeightQCD_->Add(PtMu2FakeWeightQCD_50to80_);
  PtMu2FakeWeightQCD_->Add(PtMu2FakeWeightQCD_80to120_);
  PtMu2FakeWeightQCD_->Add(PtMu2FakeWeightQCD_120to170_);
  PtMu2FakeWeightQCD_->Add(PtMu2FakeWeightQCD_170to300_);
  PtMu2FakeWeightQCD_->Add(PtMu2FakeWeightQCD_300to470_);
  PtMu2FakeWeightQCD_->Add(PtMu2FakeWeightQCD_470to600_);
  PtMu2FakeWeightQCD_->Add(PtMu2FakeWeightQCD_600to800_);
  PtMu2FakeWeightQCD_->Add(PtMu2FakeWeightQCD_800to1000_);
  PtMu2FakeWeightQCD_->Add(PtMu2FakeWeightQCD_1000toInf_);

  EtaFakeWeightCanvasQCD->cd();
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD_15to20_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD_20to30_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD_30to50_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD_50to80_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD_80to120_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD_120to170_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD_170to300_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD_300to470_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD_470to600_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD_600to800_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD_800to1000_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD_1000toInf_);

  DRFakeWeightCanvasQCD->cd();
  DRFakeWeightQCD_->Add(DRFakeWeightQCD_15to20_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD_20to30_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD_30to50_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD_50to80_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD_80to120_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD_120to170_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD_170to300_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD_300to470_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD_470to600_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD_600to800_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD_800to1000_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD_1000toInf_);

  DRNoWeightingCanvasQCD->cd();
  DRNoWeightingQCD_->Add(DRNoWeightingQCD_15to20_);
  DRNoWeightingQCD_->Add(DRNoWeightingQCD_20to30_);
  DRNoWeightingQCD_->Add(DRNoWeightingQCD_30to50_);
  DRNoWeightingQCD_->Add(DRNoWeightingQCD_50to80_);
  DRNoWeightingQCD_->Add(DRNoWeightingQCD_80to120_);
  DRNoWeightingQCD_->Add(DRNoWeightingQCD_120to170_);
  DRNoWeightingQCD_->Add(DRNoWeightingQCD_170to300_);
  DRNoWeightingQCD_->Add(DRNoWeightingQCD_300to470_);
  DRNoWeightingQCD_->Add(DRNoWeightingQCD_470to600_);
  DRNoWeightingQCD_->Add(DRNoWeightingQCD_600to800_);
  DRNoWeightingQCD_->Add(DRNoWeightingQCD_800to1000_);
  DRNoWeightingQCD_->Add(DRNoWeightingQCD_1000toInf_);

  DiMuInvMassFakeWeightZoomCanvasQCD->cd();
  DiMuInvMassFakeWeightZoomQCD_->Add(DiMuInvMassFakeWeightZoomQCD_15to20_);
  DiMuInvMassFakeWeightZoomQCD_->Add(DiMuInvMassFakeWeightZoomQCD_20to30_);
  DiMuInvMassFakeWeightZoomQCD_->Add(DiMuInvMassFakeWeightZoomQCD_30to50_);
  DiMuInvMassFakeWeightZoomQCD_->Add(DiMuInvMassFakeWeightZoomQCD_50to80_);
  DiMuInvMassFakeWeightZoomQCD_->Add(DiMuInvMassFakeWeightZoomQCD_80to120_);
  DiMuInvMassFakeWeightZoomQCD_->Add(DiMuInvMassFakeWeightZoomQCD_120to170_);
  DiMuInvMassFakeWeightZoomQCD_->Add(DiMuInvMassFakeWeightZoomQCD_170to300_);
  DiMuInvMassFakeWeightZoomQCD_->Add(DiMuInvMassFakeWeightZoomQCD_300to470_);
  DiMuInvMassFakeWeightZoomQCD_->Add(DiMuInvMassFakeWeightZoomQCD_470to600_);
  DiMuInvMassFakeWeightZoomQCD_->Add(DiMuInvMassFakeWeightZoomQCD_600to800_);
  DiMuInvMassFakeWeightZoomQCD_->Add(DiMuInvMassFakeWeightZoomQCD_800to1000_);
  DiMuInvMassFakeWeightZoomQCD_->Add(DiMuInvMassFakeWeightZoomQCD_1000toInf_);

  TauVisMassCanvasQCD->cd();
  TauVisMassQCD_->Add(TauVisMassQCD_15to20_);
  TauVisMassQCD_->Add(TauVisMassQCD_20to30_);
  TauVisMassQCD_->Add(TauVisMassQCD_30to50_);
  TauVisMassQCD_->Add(TauVisMassQCD_50to80_);
  TauVisMassQCD_->Add(TauVisMassQCD_80to120_);
  TauVisMassQCD_->Add(TauVisMassQCD_120to170_);
  TauVisMassQCD_->Add(TauVisMassQCD_170to300_);
  TauVisMassQCD_->Add(TauVisMassQCD_300to470_);
  TauVisMassQCD_->Add(TauVisMassQCD_470to600_);
  TauVisMassQCD_->Add(TauVisMassQCD_600to800_);
  TauVisMassQCD_->Add(TauVisMassQCD_800to1000_);
  TauVisMassQCD_->Add(TauVisMassQCD_1000toInf_);

  TauVisMassZoomCanvasQCD->cd();
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD_15to20_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD_20to30_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD_30to50_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD_50to80_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD_80to120_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD_120to170_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD_170to300_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD_300to470_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD_470to600_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD_600to800_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD_800to1000_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD_1000toInf_);

  outFile->cd();
  TDirectory *QCDCombined = outFile->mkdir("QCDCombined");
  QCDCombined->cd();
  InvMassTauMuMu1QCD_->Write();
  InvMassTauMuMu2QCD_->Write();
  DiMuInvMassFakeWeightQCD_->Write();
  DiMuDiTauInvMassFakeWeightQCD_->Write();
  DiTauInvMassFakeWeightQCD_->Write();
  PtMu1FakeWeightQCD_->Write();
  PtMu2FakeWeightQCD_->Write();
  EtaFakeWeightQCD_->Write();
  DRFakeWeightQCD_->Write();
  DRNoWeightingQCD_->Write();
  DiMuInvMassFakeWeightZoomQCD_->Write();
  TauVisMassQCD_->Write();
  TauVisMassZoomQCD_->Write();

cout << "Combined QCD" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the DY Combined Canvas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *InvMassTauMuMu1CanvasDY = new TCanvas ("InvMassTauMuMu1CanvasDY","",600,600); 
  TCanvas *InvMassTauMuMu2CanvasDY = new TCanvas ("InvMassTauMuMu2CanvasDY","",600,600); 
  TCanvas *DiMuInvMassFakeWeightCanvasDY = new TCanvas ("DiMuInvMassFakeWeightCanvasDY","",600,600); 
  TCanvas *DiMuDiTauInvMassFakeWeightCanvasDY = new TCanvas ("DiMuDiTauInvMassFakeWeightCanvasDY","",600,600); 
  TCanvas *DiTauInvMassFakeWeightCanvasDY = new TCanvas ("DiTauInvMassFakeWeightCanvasDY","",600,600); 
  TCanvas *PtMu1FakeWeightCanvasDY = new TCanvas ("PtMu1FakeWeightCanvasDY","",600,600); 
  TCanvas *PtMu2FakeWeightCanvasDY = new TCanvas ("PtMu2FakeWeightCanvasDY","",600,600); 
  TCanvas *EtaFakeWeightCanvasDY = new TCanvas ("EtaFakeWeightCanvasDY","",600,600); 
  TCanvas *DRFakeWeightCanvasDY = new TCanvas ("DRFakeWeightCanvasDY","",600,600); 
  TCanvas *DRNoWeightingCanvasDY = new TCanvas ("DRNoWeightingCanvasDY","",600,600); 
  TCanvas *DiMuInvMassFakeWeightZoomCanvasDY = new TCanvas ("DiMuInvMassFakeWeightZoomCanvasDY","",600,600); 
  TCanvas *TauVisMassCanvasDY = new TCanvas ("TauVisMassCanvasDY","",600,600); 
  TCanvas *TauVisMassZoomCanvasDY = new TCanvas ("TauVisMassZoomCanvasDY","",600,600); 

  TH1F *InvMassTauMuMu1DY_ = new TH1F ("InvMassTauMuMu1DY","", InvMassTauMuMu1DYL_->GetNbinsX(), InvMassTauMuMu1DYL_->GetXaxis()->GetXmin(), InvMassTauMuMu1DYL_->GetXaxis()->GetXmax() );
  TH1F *InvMassTauMuMu2DY_ = new TH1F ("InvMassTauMuMu2DY","",InvMassTauMuMu2DYL_->GetNbinsX(), InvMassTauMuMu2DYL_->GetXaxis()->GetXmin(), InvMassTauMuMu2DYL_->GetXaxis()->GetXmax() );
  TH1F *DiMuInvMassFakeWeightDY_ = new TH1F ("DiMuInvMassFakeWeightDY","",DiMuInvMassFakeWeightDYL_->GetNbinsX(), DiMuInvMassFakeWeightDYL_->GetXaxis()->GetXmin(), DiMuInvMassFakeWeightDYL_->GetXaxis()->GetXmax() );
  TH1F *DiMuDiTauInvMassFakeWeightDY_ = new TH1F ("DiMuDiTauInvMassFakeWeightDY","",DiMuDiTauInvMassFakeWeightDYL_->GetNbinsX(), DiMuDiTauInvMassFakeWeightDYL_->GetXaxis()->GetXmin(), DiMuDiTauInvMassFakeWeightDYL_->GetXaxis()->GetXmax() );
  TH1F *DiTauInvMassFakeWeightDY_ = new TH1F ("DiTauInvMassFakeWeightDY","",DiTauInvMassFakeWeightDYL_->GetNbinsX(), DiTauInvMassFakeWeightDYL_->GetXaxis()->GetXmin(), DiTauInvMassFakeWeightDYL_->GetXaxis()->GetXmax() );
  TH1F *PtMu1FakeWeightDY_ = new TH1F ("PtMu1FakeWeightDY","",PtMu1FakeWeightDYL_->GetNbinsX(), PtMu1FakeWeightDYL_->GetXaxis()->GetXmin(), PtMu1FakeWeightDYL_->GetXaxis()->GetXmax() );
  TH1F *PtMu2FakeWeightDY_ = new TH1F ("PtMu2FakeWeightDY","",PtMu2FakeWeightDYL_->GetNbinsX(), PtMu2FakeWeightDYL_->GetXaxis()->GetXmin(), PtMu2FakeWeightDYL_->GetXaxis()->GetXmax() );
  TH1F *EtaFakeWeightDY_ = new TH1F ("EtaFakeWeightDY","",EtaFakeWeightDYL_->GetNbinsX(), EtaFakeWeightDYL_->GetXaxis()->GetXmin(), EtaFakeWeightDYL_->GetXaxis()->GetXmax() );
  TH1F *DRFakeWeightDY_ = new TH1F ("DRFakeWeightDY","",DRFakeWeightDYL_->GetNbinsX(), DRFakeWeightDYL_->GetXaxis()->GetXmin(), DRFakeWeightDYL_->GetXaxis()->GetXmax() );
  TH1F *DRNoWeightingDY_ = new TH1F ("DRNoWeightingDY","",DRNoWeightingDYL_->GetNbinsX(), DRNoWeightingDYL_->GetXaxis()->GetXmin(), DRNoWeightingDYL_->GetXaxis()->GetXmax() );
  TH1F *DiMuInvMassFakeWeightZoomDY_ = new TH1F ("DiMuInvMassFakeWeightZoomDY","",DiMuInvMassFakeWeightZoomDYL_->GetNbinsX(), DiMuInvMassFakeWeightZoomDYL_->GetXaxis()->GetXmin(), DiMuInvMassFakeWeightZoomDYL_->GetXaxis()->GetXmax() );
  TH1F *TauVisMassDY_ = new TH1F ("TauVisMassDY","",TauVisMassDYL_->GetNbinsX(), TauVisMassDYL_->GetXaxis()->GetXmin(), TauVisMassDYL_->GetXaxis()->GetXmax() );
  TH1F *TauVisMassZoomDY_ = new TH1F ("TauVisMassZoomDY","",TauVisMassZoomDYL_->GetNbinsX(), TauVisMassZoomDYL_->GetXaxis()->GetXmin(), TauVisMassZoomDYL_->GetXaxis()->GetXmax() );

  InvMassTauMuMu1CanvasDY->cd();
  InvMassTauMuMu1DY_->Add(InvMassTauMuMu1DYL_);
  InvMassTauMuMu1DY_->Add(InvMassTauMuMu1DYH_);
  InvMassTauMuMu1DY_->Add(InvMassTauMuMu1Up_);
  InvMassTauMuMu1DY_->Add(InvMassTauMuMu1JPsi_);

  InvMassTauMuMu2CanvasDY->cd();
  InvMassTauMuMu2DY_->Add(InvMassTauMuMu2DYL_);
  InvMassTauMuMu2DY_->Add(InvMassTauMuMu2DYH_);
  InvMassTauMuMu2DY_->Add(InvMassTauMuMu2Up_);
  InvMassTauMuMu2DY_->Add(InvMassTauMuMu2JPsi_);

  DiMuInvMassFakeWeightCanvasDY->cd();
  DiMuInvMassFakeWeightDY_->Add(DiMuInvMassFakeWeightDYL_);
  DiMuInvMassFakeWeightDY_->Add(DiMuInvMassFakeWeightDYH_);
  DiMuInvMassFakeWeightDY_->Add(DiMuInvMassFakeWeightUp_);
  DiMuInvMassFakeWeightDY_->Add(DiMuInvMassFakeWeightJPsi_);

  DiMuDiTauInvMassFakeWeightCanvasDY->cd();
  DiMuDiTauInvMassFakeWeightDY_->Add(DiMuDiTauInvMassFakeWeightDYL_);
  DiMuDiTauInvMassFakeWeightDY_->Add(DiMuDiTauInvMassFakeWeightDYH_);
  DiMuDiTauInvMassFakeWeightDY_->Add(DiMuDiTauInvMassFakeWeightUp_);
  DiMuDiTauInvMassFakeWeightDY_->Add(DiMuDiTauInvMassFakeWeightJPsi_);

  DiTauInvMassFakeWeightCanvasDY->cd();
  DiTauInvMassFakeWeightDY_->Add(DiTauInvMassFakeWeightDYL_);
  DiTauInvMassFakeWeightDY_->Add(DiTauInvMassFakeWeightDYH_);
  DiTauInvMassFakeWeightDY_->Add(DiTauInvMassFakeWeightUp_);
  DiTauInvMassFakeWeightDY_->Add(DiTauInvMassFakeWeightJPsi_);

  PtMu1FakeWeightCanvasDY->cd();
  PtMu1FakeWeightDY_->Add(PtMu1FakeWeightDYL_);
  PtMu1FakeWeightDY_->Add(PtMu1FakeWeightDYH_);
  PtMu1FakeWeightDY_->Add(PtMu1FakeWeightUp_);
  PtMu1FakeWeightDY_->Add(PtMu1FakeWeightJPsi_);

  PtMu2FakeWeightCanvasDY->cd();
  PtMu2FakeWeightDY_->Add(PtMu2FakeWeightDYL_);
  PtMu2FakeWeightDY_->Add(PtMu2FakeWeightDYH_);
  PtMu2FakeWeightDY_->Add(PtMu2FakeWeightUp_);
  PtMu2FakeWeightDY_->Add(PtMu2FakeWeightJPsi_);

  EtaFakeWeightCanvasDY->cd();
  EtaFakeWeightDY_->Add(EtaFakeWeightDYL_);
  EtaFakeWeightDY_->Add(EtaFakeWeightDYH_);
  EtaFakeWeightDY_->Add(EtaFakeWeightUp_);
  EtaFakeWeightDY_->Add(EtaFakeWeightJPsi_);

  DRFakeWeightCanvasDY->cd();
  DRFakeWeightDY_->Add(DRFakeWeightDYL_);
  DRFakeWeightDY_->Add(DRFakeWeightDYH_);
  DRFakeWeightDY_->Add(DRFakeWeightUp_);
  DRFakeWeightDY_->Add(DRFakeWeightJPsi_);

  DRNoWeightingCanvasDY->cd();
  DRNoWeightingDY_->Add(DRNoWeightingDYL_);
  DRNoWeightingDY_->Add(DRNoWeightingDYH_);
  DRNoWeightingDY_->Add(DRNoWeightingUp_);
  DRNoWeightingDY_->Add(DRNoWeightingJPsi_);

  DiMuInvMassFakeWeightZoomCanvasDY->cd();
  DiMuInvMassFakeWeightZoomDY_->Add(DiMuInvMassFakeWeightZoomDYL_);
  DiMuInvMassFakeWeightZoomDY_->Add(DiMuInvMassFakeWeightZoomDYH_);
  DiMuInvMassFakeWeightZoomDY_->Add(DiMuInvMassFakeWeightZoomUp_);
  DiMuInvMassFakeWeightZoomDY_->Add(DiMuInvMassFakeWeightZoomJPsi_);

  TauVisMassCanvasDY->cd();
  TauVisMassDY_->Add(TauVisMassDYL_);
  TauVisMassDY_->Add(TauVisMassDYH_);
  TauVisMassDY_->Add(TauVisMassUp_);
  TauVisMassDY_->Add(TauVisMassJPsi_);

  TauVisMassZoomCanvasDY->cd();
  TauVisMassZoomDY_->Add(TauVisMassZoomDYL_);
  TauVisMassZoomDY_->Add(TauVisMassZoomDYH_);
  TauVisMassZoomDY_->Add(TauVisMassZoomUp_);
  TauVisMassZoomDY_->Add(TauVisMassZoomJPsi_);

  outFile->cd();
  TDirectory *DYCombined = outFile->mkdir("DYCombined");
  DYCombined->cd();
  InvMassTauMuMu1DY_->Write();
  InvMassTauMuMu2DY_->Write();
  DiMuInvMassFakeWeightDY_->Write();
  DiMuDiTauInvMassFakeWeightDY_->Write();
  DiTauInvMassFakeWeightDY_->Write();
  PtMu1FakeWeightDY_->Write();
  PtMu2FakeWeightDY_->Write();
  EtaFakeWeightDY_->Write();
  DRFakeWeightDY_->Write();
  DRNoWeightingDY_->Write();
  DiMuInvMassFakeWeightZoomDY_->Write();
  TauVisMassDY_->Write();
  TauVisMassZoomDY_->Write();

cout << "Combined DY" << endl;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the ST Combined Canvas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *InvMassTauMuMu1CanvasST = new TCanvas ("InvMassTauMuMu1CanvasST","",600,600); 
  TCanvas *InvMassTauMuMu2CanvasST = new TCanvas ("InvMassTauMuMu2CanvasST","",600,600); 
  TCanvas *DiMuInvMassFakeWeightCanvasST = new TCanvas ("DiMuInvMassFakeWeightCanvasST","",600,600); 
  TCanvas *DiMuDiTauInvMassFakeWeightCanvasST = new TCanvas ("DiMuDiTauInvMassFakeWeightCanvasST","",600,600); 
  TCanvas *DiTauInvMassFakeWeightCanvasST = new TCanvas ("DiTauInvMassFakeWeightCanvasST","",600,600); 
  TCanvas *PtMu1FakeWeightCanvasST = new TCanvas ("PtMu1FakeWeightCanvasST","",600,600); 
  TCanvas *PtMu2FakeWeightCanvasST = new TCanvas ("PtMu2FakeWeightCanvasST","",600,600); 
  TCanvas *EtaFakeWeightCanvasST = new TCanvas ("EtaFakeWeightCanvasST","",600,600); 
  TCanvas *DRFakeWeightCanvasST = new TCanvas ("DRFakeWeightCanvasST","",600,600); 
  TCanvas *DRNoWeightingCanvasST = new TCanvas ("DRNoWeightingCanvasST","",600,600); 
  TCanvas *DiMuInvMassFakeWeightZoomCanvasST = new TCanvas ("DiMuInvMassFakeWeightZoomCanvasST","",600,600); 
  TCanvas *TauVisMassCanvasST = new TCanvas ("TauVisMassCanvasST","",600,600); 
  TCanvas *TauVisMassZoomCanvasST = new TCanvas ("TauVisMassZoomCanvasST","",600,600); 

  TH1F *InvMassTauMuMu1ST_ = new TH1F ("InvMassTauMuMu1ST","", InvMassTauMuMu1ST_sch_->GetNbinsX(), InvMassTauMuMu1ST_sch_->GetXaxis()->GetXmin(),  InvMassTauMuMu1ST_sch_->GetXaxis()->GetXmax() );
  TH1F *InvMassTauMuMu2ST_ = new TH1F ("InvMassTauMuMu2ST","",InvMassTauMuMu2ST_sch_->GetNbinsX(), InvMassTauMuMu2ST_sch_->GetXaxis()->GetXmin(),  InvMassTauMuMu2ST_sch_->GetXaxis()->GetXmax() );
  TH1F *DiMuInvMassFakeWeightST_ = new TH1F ("DiMuInvMassFakeWeightST","",DiMuInvMassFakeWeightST_sch_->GetNbinsX(), DiMuInvMassFakeWeightST_sch_->GetXaxis()->GetXmin(),  DiMuInvMassFakeWeightST_sch_->GetXaxis()->GetXmax() );
  TH1F *DiMuDiTauInvMassFakeWeightST_ = new TH1F ("DiMuDiTauInvMassFakeWeightST","",DiMuDiTauInvMassFakeWeightST_sch_->GetNbinsX(), DiMuDiTauInvMassFakeWeightST_sch_->GetXaxis()->GetXmin(),  DiMuDiTauInvMassFakeWeightST_sch_->GetXaxis()->GetXmax() );
  TH1F *DiTauInvMassFakeWeightST_ = new TH1F ("DiTauInvMassFakeWeightST","",DiTauInvMassFakeWeightST_sch_->GetNbinsX(), DiTauInvMassFakeWeightST_sch_->GetXaxis()->GetXmin(),  DiTauInvMassFakeWeightST_sch_->GetXaxis()->GetXmax() );
  TH1F *PtMu1FakeWeightST_ = new TH1F ("PtMu1FakeWeightST","",PtMu1FakeWeightST_sch_->GetNbinsX(), PtMu1FakeWeightST_sch_->GetXaxis()->GetXmin(),  PtMu1FakeWeightST_sch_->GetXaxis()->GetXmax() );
  TH1F *PtMu2FakeWeightST_ = new TH1F ("PtMu2FakeWeightST","",PtMu2FakeWeightST_sch_->GetNbinsX(), PtMu2FakeWeightST_sch_->GetXaxis()->GetXmin(),  PtMu2FakeWeightST_sch_->GetXaxis()->GetXmax() );
  TH1F *EtaFakeWeightST_ = new TH1F ("EtaFakeWeightST","",EtaFakeWeightST_sch_->GetNbinsX(), EtaFakeWeightST_sch_->GetXaxis()->GetXmin(),  EtaFakeWeightST_sch_->GetXaxis()->GetXmax() );
  TH1F *DRFakeWeightST_ = new TH1F ("DRFakeWeightST","",DRFakeWeightST_sch_->GetNbinsX(), DRFakeWeightST_sch_->GetXaxis()->GetXmin(),  DRFakeWeightST_sch_->GetXaxis()->GetXmax() );
  TH1F *DRNoWeightingST_ = new TH1F ("DRNoWeightingST","",DRNoWeightingST_sch_->GetNbinsX(), DRNoWeightingST_sch_->GetXaxis()->GetXmin(),  DRNoWeightingST_sch_->GetXaxis()->GetXmax() );
  TH1F *DiMuInvMassFakeWeightZoomST_ = new TH1F ("DiMuInvMassFakeWeightZoomST","",DiMuInvMassFakeWeightZoomST_sch_->GetNbinsX(), DiMuInvMassFakeWeightZoomST_sch_->GetXaxis()->GetXmin(),  DiMuInvMassFakeWeightZoomST_sch_->GetXaxis()->GetXmax() );
  TH1F *TauVisMassST_ = new TH1F ("TauVisMassST","",TauVisMassST_sch_->GetNbinsX(), TauVisMassST_sch_->GetXaxis()->GetXmin(),  TauVisMassST_sch_->GetXaxis()->GetXmax() );
  TH1F *TauVisMassZoomST_ = new TH1F ("TauVisMassZoomST","",TauVisMassZoomST_sch_->GetNbinsX(), TauVisMassZoomST_sch_->GetXaxis()->GetXmin(),  TauVisMassZoomST_sch_->GetXaxis()->GetXmax() );


  InvMassTauMuMu1CanvasST->cd();
  InvMassTauMuMu1ST_->Add(InvMassTauMuMu1ST_sch_);
//  InvMassTauMuMu1ST_->Add(InvMassTauMuMu1ST_tch_top_);
//  InvMassTauMuMu1ST_->Add(InvMassTauMuMu1ST_tWNoHad_top_);
  InvMassTauMuMu1ST_->Add(InvMassTauMuMu1ST_tWIncl_antitop_);
  InvMassTauMuMu1ST_->Add(InvMassTauMuMu1ST_tWIncl_top_);
  InvMassTauMuMu1ST_->Add(InvMassTauMuMu1ST_tch_antitop_);
  InvMassTauMuMu1ST_->Add(InvMassTauMuMu1ST_tch_top_);

  InvMassTauMuMu2CanvasST->cd();
  InvMassTauMuMu2ST_->Add(InvMassTauMuMu2ST_sch_);
//  InvMassTauMuMu2ST_->Add(InvMassTauMuMu2ST_tch_top_);
//  InvMassTauMuMu2ST_->Add(InvMassTauMuMu2ST_tWNoHad_top_);
  InvMassTauMuMu2ST_->Add(InvMassTauMuMu2ST_tWIncl_antitop_);
  InvMassTauMuMu2ST_->Add(InvMassTauMuMu2ST_tWIncl_top_);
  InvMassTauMuMu2ST_->Add(InvMassTauMuMu2ST_tch_antitop_);
  InvMassTauMuMu2ST_->Add(InvMassTauMuMu2ST_tch_top_);

  DiMuInvMassFakeWeightCanvasST->cd();
  DiMuInvMassFakeWeightST_->Add(DiMuInvMassFakeWeightST_sch_);
//  DiMuInvMassFakeWeightST_->Add(DiMuInvMassFakeWeightST_tch_top_);
//  DiMuInvMassFakeWeightST_->Add(DiMuInvMassFakeWeightST_tWNoHad_top_);
  DiMuInvMassFakeWeightST_->Add(DiMuInvMassFakeWeightST_tWIncl_antitop_);
  DiMuInvMassFakeWeightST_->Add(DiMuInvMassFakeWeightST_tWIncl_top_);
  DiMuInvMassFakeWeightST_->Add(DiMuInvMassFakeWeightST_tch_antitop_);
  DiMuInvMassFakeWeightST_->Add(DiMuInvMassFakeWeightST_tch_top_);

  DiMuDiTauInvMassFakeWeightCanvasST->cd();
  DiMuDiTauInvMassFakeWeightST_->Add(DiMuDiTauInvMassFakeWeightST_sch_);
//  DiMuDiTauInvMassFakeWeightST_->Add(DiMuDiTauInvMassFakeWeightST_tch_top_);
//  DiMuDiTauInvMassFakeWeightST_->Add(DiMuDiTauInvMassFakeWeightST_tWNoHad_top_);
  DiMuDiTauInvMassFakeWeightST_->Add(DiMuDiTauInvMassFakeWeightST_tWIncl_antitop_);
  DiMuDiTauInvMassFakeWeightST_->Add(DiMuDiTauInvMassFakeWeightST_tWIncl_top_);
  DiMuDiTauInvMassFakeWeightST_->Add(DiMuDiTauInvMassFakeWeightST_tch_antitop_);
  DiMuDiTauInvMassFakeWeightST_->Add(DiMuDiTauInvMassFakeWeightST_tch_top_);

  DiTauInvMassFakeWeightCanvasST->cd();
  DiTauInvMassFakeWeightST_->Add(DiTauInvMassFakeWeightST_sch_);
//  DiTauInvMassFakeWeightST_->Add(DiTauInvMassFakeWeightST_tch_top_);
//  DiTauInvMassFakeWeightST_->Add(DiTauInvMassFakeWeightST_tWNoHad_top_);
  DiTauInvMassFakeWeightST_->Add(DiTauInvMassFakeWeightST_tWIncl_antitop_);
  DiTauInvMassFakeWeightST_->Add(DiTauInvMassFakeWeightST_tWIncl_top_);
  DiTauInvMassFakeWeightST_->Add(DiTauInvMassFakeWeightST_tch_antitop_);
  DiTauInvMassFakeWeightST_->Add(DiTauInvMassFakeWeightST_tch_top_);

  PtMu1FakeWeightCanvasST->cd();
  PtMu1FakeWeightST_->Add(PtMu1FakeWeightST_sch_);
//  PtMu1FakeWeightST_->Add(PtMu1FakeWeightST_tch_top_);
//  PtMu1FakeWeightST_->Add(PtMu1FakeWeightST_tWNoHad_top_);
  PtMu1FakeWeightST_->Add(PtMu1FakeWeightST_tWIncl_antitop_);
  PtMu1FakeWeightST_->Add(PtMu1FakeWeightST_tWIncl_top_);
  PtMu1FakeWeightST_->Add(PtMu1FakeWeightST_tch_antitop_);
  PtMu1FakeWeightST_->Add(PtMu1FakeWeightST_tch_top_);

  PtMu2FakeWeightCanvasST->cd();
  PtMu2FakeWeightST_->Add(PtMu2FakeWeightST_sch_);
//  PtMu2FakeWeightST_->Add(PtMu2FakeWeightST_tch_top_);
//  PtMu2FakeWeightST_->Add(PtMu2FakeWeightST_tWNoHad_top_);
  PtMu2FakeWeightST_->Add(PtMu2FakeWeightST_tWIncl_antitop_);
  PtMu2FakeWeightST_->Add(PtMu2FakeWeightST_tWIncl_top_);
  PtMu2FakeWeightST_->Add(PtMu2FakeWeightST_tch_antitop_);
  PtMu2FakeWeightST_->Add(PtMu2FakeWeightST_tch_top_);

  EtaFakeWeightCanvasST->cd();
  EtaFakeWeightST_->Add(EtaFakeWeightST_sch_);
//  EtaFakeWeightST_->Add(EtaFakeWeightST_tch_top_);
//  EtaFakeWeightST_->Add(EtaFakeWeightST_tWNoHad_top_);
  EtaFakeWeightST_->Add(EtaFakeWeightST_tWIncl_antitop_);
  EtaFakeWeightST_->Add(EtaFakeWeightST_tWIncl_top_);
  EtaFakeWeightST_->Add(EtaFakeWeightST_tch_antitop_);
  EtaFakeWeightST_->Add(EtaFakeWeightST_tch_top_);

  DRFakeWeightCanvasST->cd();
  DRFakeWeightST_->Add(DRFakeWeightST_sch_);
//  DRFakeWeightST_->Add(DRFakeWeightST_tch_top_);
//  DRFakeWeightST_->Add(DRFakeWeightST_tWNoHad_top_);
  DRFakeWeightST_->Add(DRFakeWeightST_tWIncl_antitop_);
  DRFakeWeightST_->Add(DRFakeWeightST_tWIncl_top_);
  DRFakeWeightST_->Add(DRFakeWeightST_tch_antitop_);
  DRFakeWeightST_->Add(DRFakeWeightST_tch_top_);

  DRNoWeightingCanvasST->cd();
  DRNoWeightingST_->Add(DRNoWeightingST_sch_);
//  DRNoWeightingST_->Add(DRNoWeightingST_tch_top_);
//  DRNoWeightingST_->Add(DRNoWeightingST_tWNoHad_top_);
  DRNoWeightingST_->Add(DRNoWeightingST_tWIncl_antitop_);
  DRNoWeightingST_->Add(DRNoWeightingST_tWIncl_top_);
  DRNoWeightingST_->Add(DRNoWeightingST_tch_antitop_);
  DRNoWeightingST_->Add(DRNoWeightingST_tch_top_);

  DiMuInvMassFakeWeightZoomCanvasST->cd();
  DiMuInvMassFakeWeightZoomST_->Add(DiMuInvMassFakeWeightZoomST_sch_);
//  DiMuInvMassFakeWeightZoomST_->Add(DiMuInvMassFakeWeightZoomST_tch_top_);
//  DiMuInvMassFakeWeightZoomST_->Add(DiMuInvMassFakeWeightZoomST_tWNoHad_top_);
  DiMuInvMassFakeWeightZoomST_->Add(DiMuInvMassFakeWeightZoomST_tWIncl_antitop_);
  DiMuInvMassFakeWeightZoomST_->Add(DiMuInvMassFakeWeightZoomST_tWIncl_top_);
  DiMuInvMassFakeWeightZoomST_->Add(DiMuInvMassFakeWeightZoomST_tch_antitop_);
  DiMuInvMassFakeWeightZoomST_->Add(DiMuInvMassFakeWeightZoomST_tch_top_);

  TauVisMassCanvasST->cd();
  TauVisMassST_->Add(TauVisMassST_sch_);
//  TauVisMassST_->Add(TauVisMassST_tch_top_);
//  TauVisMassST_->Add(TauVisMassST_tWNoHad_top_);
  TauVisMassST_->Add(TauVisMassST_tWIncl_antitop_);
  TauVisMassST_->Add(TauVisMassST_tWIncl_top_);
  TauVisMassST_->Add(TauVisMassST_tch_antitop_);
  TauVisMassST_->Add(TauVisMassST_tch_top_);

  TauVisMassZoomCanvasST->cd();
  TauVisMassZoomST_->Add(TauVisMassZoomST_sch_);
//  TauVisMassZoomST_->Add(TauVisMassZoomST_tch_top_);
//  TauVisMassZoomST_->Add(TauVisMassZoomST_tWNoHad_top_);
  TauVisMassZoomST_->Add(TauVisMassZoomST_tWIncl_antitop_);
  TauVisMassZoomST_->Add(TauVisMassZoomST_tWIncl_top_);
  TauVisMassZoomST_->Add(TauVisMassZoomST_tch_antitop_);
  TauVisMassZoomST_->Add(TauVisMassZoomST_tch_top_);

  outFile->cd();
  TDirectory *STCombined = outFile->mkdir("STCombined");
  STCombined->cd();
  InvMassTauMuMu1ST_->Write();
  InvMassTauMuMu2ST_->Write();
  DiMuInvMassFakeWeightST_->Write();
  DiMuDiTauInvMassFakeWeightST_->Write();
  DiTauInvMassFakeWeightST_->Write();
  PtMu1FakeWeightST_->Write();
  PtMu2FakeWeightST_->Write();
  EtaFakeWeightST_->Write();
  DRFakeWeightST_->Write();
  DRNoWeightingST_->Write();
  DiMuInvMassFakeWeightZoomST_->Write();
  TauVisMassST_->Write();
  TauVisMassZoomST_->Write();

  std::cout << "ST Done" << std::endl;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the DiBoson Combined Canvas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *InvMassTauMuMu1CanvasDiBoson = new TCanvas ("InvMassTauMuMu1CanvasDiBoson","",600,600); 
  TCanvas *InvMassTauMuMu2CanvasDiBoson = new TCanvas ("InvMassTauMuMu2CanvasDiBoson","",600,600); 
  TCanvas *DiMuInvMassFakeWeightCanvasDiBoson = new TCanvas ("DiMuInvMassFakeWeightCanvasDiBoson","",600,600); 
  TCanvas *DiMuDiTauInvMassFakeWeightCanvasDiBoson = new TCanvas ("DiMuDiTauInvMassFakeWeightCanvasDiBoson","",600,600); 
  TCanvas *DiTauInvMassFakeWeightCanvasDiBoson = new TCanvas ("DiTauInvMassFakeWeightCanvasDiBoson","",600,600); 
  TCanvas *PtMu1FakeWeightCanvasDiBoson = new TCanvas ("PtMu1FakeWeightCanvasDiBoson","",600,600); 
  TCanvas *PtMu2FakeWeightCanvasDiBoson = new TCanvas ("PtMu2FakeWeightCanvasDiBoson","",600,600); 
  TCanvas *EtaFakeWeightCanvasDiBoson = new TCanvas ("EtaFakeWeightCanvasDiBoson","",600,600); 
  TCanvas *DRFakeWeightCanvasDiBoson = new TCanvas ("DRFakeWeightCanvasDiBoson","",600,600); 
  TCanvas *DRNoWeightingCanvasDiBoson = new TCanvas ("DRNoWeightingCanvasDiBoson","",600,600); 
  TCanvas *DiMuInvMassFakeWeightZoomCanvasDiBoson = new TCanvas ("DiMuInvMassFakeWeightZoomCanvasDiBoson","",600,600); 
  TCanvas *TauVisMassCanvasDiBoson = new TCanvas ("TauVisMassCanvasDiBoson","",600,600); 
  TCanvas *TauVisMassZoomCanvasDiBoson = new TCanvas ("TauVisMassZoomCanvasDiBoson","",600,600); 

  TH1F *InvMassTauMuMu1DiBoson_ = new TH1F ("InvMassTauMuMu1DiBoson","", InvMassTauMuMu1WJAmac_->GetNbinsX(), InvMassTauMuMu1WJAmac_->GetXaxis()->GetXmin(), InvMassTauMuMu1WJAmac_->GetXaxis()->GetXmax() );
  TH1F *InvMassTauMuMu2DiBoson_ = new TH1F ("InvMassTauMuMu2DiBoson","",InvMassTauMuMu2WJAmac_->GetNbinsX(), InvMassTauMuMu2WJAmac_->GetXaxis()->GetXmin(), InvMassTauMuMu2WJAmac_->GetXaxis()->GetXmax() );
  TH1F *DiMuInvMassFakeWeightDiBoson_ = new TH1F ("DiMuInvMassFakeWeightDiBoson","",DiMuInvMassFakeWeightWJAmac_->GetNbinsX(), DiMuInvMassFakeWeightWJAmac_->GetXaxis()->GetXmin(), DiMuInvMassFakeWeightWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DiMuDiTauInvMassFakeWeightDiBoson_ = new TH1F ("DiMuDiTauInvMassFakeWeightDiBoson","",DiMuDiTauInvMassFakeWeightWJAmac_->GetNbinsX(), DiMuDiTauInvMassFakeWeightWJAmac_->GetXaxis()->GetXmin(), DiMuDiTauInvMassFakeWeightWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DiTauInvMassFakeWeightDiBoson_ = new TH1F ("DiTauInvMassFakeWeightDiBoson","",DiTauInvMassFakeWeightWJAmac_->GetNbinsX(), DiTauInvMassFakeWeightWJAmac_->GetXaxis()->GetXmin(), DiTauInvMassFakeWeightWJAmac_->GetXaxis()->GetXmax() );
  TH1F *PtMu1FakeWeightDiBoson_ = new TH1F ("PtMu1FakeWeightDiBoson","",PtMu1FakeWeightWJAmac_->GetNbinsX(), PtMu1FakeWeightWJAmac_->GetXaxis()->GetXmin(), PtMu1FakeWeightWJAmac_->GetXaxis()->GetXmax() );
  TH1F *PtMu2FakeWeightDiBoson_ = new TH1F ("PtMu2FakeWeightDiBoson","",PtMu2FakeWeightWJAmac_->GetNbinsX(), PtMu2FakeWeightWJAmac_->GetXaxis()->GetXmin(), PtMu2FakeWeightWJAmac_->GetXaxis()->GetXmax() );
  TH1F *EtaFakeWeightDiBoson_ = new TH1F ("EtaFakeWeightDiBoson","",EtaFakeWeightWJAmac_->GetNbinsX(), EtaFakeWeightWJAmac_->GetXaxis()->GetXmin(), EtaFakeWeightWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DRFakeWeightDiBoson_ = new TH1F ("DRFakeWeightDiBoson","",DRFakeWeightWJAmac_->GetNbinsX(), DRFakeWeightWJAmac_->GetXaxis()->GetXmin(), DRFakeWeightWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DRNoWeightingDiBoson_ = new TH1F ("DRNoWeightingDiBoson","",DRNoWeightingWJAmac_->GetNbinsX(), DRNoWeightingWJAmac_->GetXaxis()->GetXmin(), DRNoWeightingWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DiMuInvMassFakeWeightZoomDiBoson_ = new TH1F ("DiMuInvMassFakeWeightZoomDiBoson","",DiMuInvMassFakeWeightZoomWJAmac_->GetNbinsX(), DiMuInvMassFakeWeightZoomWJAmac_->GetXaxis()->GetXmin(), DiMuInvMassFakeWeightZoomWJAmac_->GetXaxis()->GetXmax() );
  TH1F *TauVisMassDiBoson_ = new TH1F ("TauVisMassDiBoson","",TauVisMassWJAmac_->GetNbinsX(), TauVisMassWJAmac_->GetXaxis()->GetXmin(), TauVisMassWJAmac_->GetXaxis()->GetXmax() );
  TH1F *TauVisMassZoomDiBoson_ = new TH1F ("TauVisMassZoomDiBoson","",TauVisMassZoomWJAmac_->GetNbinsX(), TauVisMassZoomWJAmac_->GetXaxis()->GetXmin(), TauVisMassZoomWJAmac_->GetXaxis()->GetXmax() );


  InvMassTauMuMu1CanvasDiBoson->cd();
//  InvMassTauMuMu1DiBoson_->Add(InvMassTauMuMu1VV_);
  InvMassTauMuMu1DiBoson_->Add(InvMassTauMuMu1WZ_);
  InvMassTauMuMu1DiBoson_->Add(InvMassTauMuMu1ZZ2L2Nu_);
  InvMassTauMuMu1DiBoson_->Add(InvMassTauMuMu1ZZ2L2Q_);
  InvMassTauMuMu1DiBoson_->Add(InvMassTauMuMu1ZZ4LAmac_);

  InvMassTauMuMu2CanvasDiBoson->cd();
//  InvMassTauMuMu2DiBoson_->Add(InvMassTauMuMu2VV_);
  InvMassTauMuMu2DiBoson_->Add(InvMassTauMuMu2WZ_);
  InvMassTauMuMu2DiBoson_->Add(InvMassTauMuMu2ZZ2L2Nu_);
  InvMassTauMuMu2DiBoson_->Add(InvMassTauMuMu2ZZ2L2Q_);
  InvMassTauMuMu2DiBoson_->Add(InvMassTauMuMu2ZZ4LAmac_);

  DiMuInvMassFakeWeightCanvasDiBoson->cd();
//  DiMuInvMassFakeWeightDiBoson_->Add(DiMuInvMassFakeWeightVV_);
  DiMuInvMassFakeWeightDiBoson_->Add(DiMuInvMassFakeWeightWZ_);
  DiMuInvMassFakeWeightDiBoson_->Add(DiMuInvMassFakeWeightZZ2L2Nu_);
  DiMuInvMassFakeWeightDiBoson_->Add(DiMuInvMassFakeWeightZZ2L2Q_);
  DiMuInvMassFakeWeightDiBoson_->Add(DiMuInvMassFakeWeightZZ4LAmac_);

  DiMuDiTauInvMassFakeWeightCanvasDiBoson->cd();
//  DiMuDiTauInvMassFakeWeightDiBoson_->Add(DiMuDiTauInvMassFakeWeightVV_);
  DiMuDiTauInvMassFakeWeightDiBoson_->Add(DiMuDiTauInvMassFakeWeightWZ_);
  DiMuDiTauInvMassFakeWeightDiBoson_->Add(DiMuDiTauInvMassFakeWeightZZ2L2Nu_);
  DiMuDiTauInvMassFakeWeightDiBoson_->Add(DiMuDiTauInvMassFakeWeightZZ2L2Q_);
  DiMuDiTauInvMassFakeWeightDiBoson_->Add(DiMuDiTauInvMassFakeWeightZZ4LAmac_);

  DiTauInvMassFakeWeightCanvasDiBoson->cd();
//  DiTauInvMassFakeWeightDiBoson_->Add(DiTauInvMassFakeWeightVV_);
  DiTauInvMassFakeWeightDiBoson_->Add(DiTauInvMassFakeWeightWZ_);
  DiTauInvMassFakeWeightDiBoson_->Add(DiTauInvMassFakeWeightZZ2L2Nu_);
  DiTauInvMassFakeWeightDiBoson_->Add(DiTauInvMassFakeWeightZZ2L2Q_);
  DiTauInvMassFakeWeightDiBoson_->Add(DiTauInvMassFakeWeightZZ4LAmac_);

  PtMu1FakeWeightCanvasDiBoson->cd();
//  PtMu1FakeWeightDiBoson_->Add(PtMu1FakeWeightVV_);
  PtMu1FakeWeightDiBoson_->Add(PtMu1FakeWeightWZ_);
  PtMu1FakeWeightDiBoson_->Add(PtMu1FakeWeightZZ2L2Nu_);
  PtMu1FakeWeightDiBoson_->Add(PtMu1FakeWeightZZ2L2Q_);
  PtMu1FakeWeightDiBoson_->Add(PtMu1FakeWeightZZ4LAmac_);

  PtMu2FakeWeightCanvasDiBoson->cd();
//  PtMu2FakeWeightDiBoson_->Add(PtMu2FakeWeightVV_);
  PtMu2FakeWeightDiBoson_->Add(PtMu2FakeWeightWZ_);
  PtMu2FakeWeightDiBoson_->Add(PtMu2FakeWeightZZ2L2Nu_);
  PtMu2FakeWeightDiBoson_->Add(PtMu2FakeWeightZZ2L2Q_);
  PtMu2FakeWeightDiBoson_->Add(PtMu2FakeWeightZZ4LAmac_);

  EtaFakeWeightCanvasDiBoson->cd();
//  EtaFakeWeightDiBoson_->Add(EtaFakeWeightVV_);
  EtaFakeWeightDiBoson_->Add(EtaFakeWeightWZ_);
  EtaFakeWeightDiBoson_->Add(EtaFakeWeightZZ2L2Nu_);
  EtaFakeWeightDiBoson_->Add(EtaFakeWeightZZ2L2Q_);
  EtaFakeWeightDiBoson_->Add(EtaFakeWeightZZ4LAmac_);

  DRFakeWeightCanvasDiBoson->cd();
//  DRFakeWeightDiBoson_->Add(DRFakeWeightVV_);
  DRFakeWeightDiBoson_->Add(DRFakeWeightWZ_);
  DRFakeWeightDiBoson_->Add(DRFakeWeightZZ2L2Nu_);
  DRFakeWeightDiBoson_->Add(DRFakeWeightZZ2L2Q_);
  DRFakeWeightDiBoson_->Add(DRFakeWeightZZ4LAmac_);

  DRNoWeightingCanvasDiBoson->cd();
//  DRNoWeightingDiBoson_->Add(DRNoWeightingVV_);
  DRNoWeightingDiBoson_->Add(DRNoWeightingWZ_);
  DRNoWeightingDiBoson_->Add(DRNoWeightingZZ2L2Nu_);
  DRNoWeightingDiBoson_->Add(DRNoWeightingZZ2L2Q_);
  DRNoWeightingDiBoson_->Add(DRNoWeightingZZ4LAmac_);

  DiMuInvMassFakeWeightZoomCanvasDiBoson->cd();
//  DiMuInvMassFakeWeightZoomDiBoson_->Add(DiMuInvMassFakeWeightZoomVV_);
  DiMuInvMassFakeWeightZoomDiBoson_->Add(DiMuInvMassFakeWeightZoomWZ_);
  DiMuInvMassFakeWeightZoomDiBoson_->Add(DiMuInvMassFakeWeightZoomZZ2L2Nu_);
  DiMuInvMassFakeWeightZoomDiBoson_->Add(DiMuInvMassFakeWeightZoomZZ2L2Q_);
  DiMuInvMassFakeWeightZoomDiBoson_->Add(DiMuInvMassFakeWeightZoomZZ4LAmac_);

  TauVisMassCanvasDiBoson->cd();
//  TauVisMassDiBoson_->Add(TauVisMassVV_);
  TauVisMassDiBoson_->Add(TauVisMassWZ_);
  TauVisMassDiBoson_->Add(TauVisMassZZ2L2Nu_);
  TauVisMassDiBoson_->Add(TauVisMassZZ2L2Q_);
  TauVisMassDiBoson_->Add(TauVisMassZZ4LAmac_);

  TauVisMassZoomCanvasDiBoson->cd();
//  TauVisMassZoomDiBoson_->Add(TauVisMassZoomVV_);
  TauVisMassZoomDiBoson_->Add(TauVisMassZoomWZ_);
  TauVisMassZoomDiBoson_->Add(TauVisMassZoomZZ2L2Nu_);
  TauVisMassZoomDiBoson_->Add(TauVisMassZoomZZ2L2Q_);
  TauVisMassZoomDiBoson_->Add(TauVisMassZoomZZ4LAmac_);

  outFile->cd();
  TDirectory *DiBosonCombined = outFile->mkdir("DiBosonCombined");
  DiBosonCombined->cd();
  InvMassTauMuMu1DiBoson_->Write();
  InvMassTauMuMu2DiBoson_->Write();
  DiMuInvMassFakeWeightDiBoson_->Write();
  DiMuDiTauInvMassFakeWeightDiBoson_->Write();
  DiTauInvMassFakeWeightDiBoson_->Write();
  PtMu1FakeWeightDiBoson_->Write();
  PtMu2FakeWeightDiBoson_->Write();
  EtaFakeWeightDiBoson_->Write();
  DRFakeWeightDiBoson_->Write();
  DRNoWeightingDiBoson_->Write();
  DiMuInvMassFakeWeightZoomDiBoson_->Write();
  TauVisMassDiBoson_->Write();
  TauVisMassZoomDiBoson_->Write();

cout << "Combined DiBoson" << endl;


  outFile->cd();
  TDirectory *TTAmcaCombined = outFile->mkdir("TTAmcaCombined");
  TTAmcaCombined->cd();
  InvMassTauMuMu1TTAmca_->Write();
  InvMassTauMuMu2TTAmca_->Write();
  DiMuInvMassFakeWeightTTAmca_->Write();
  DiMuDiTauInvMassFakeWeightTTAmca_->Write();
  DiTauInvMassFakeWeightTTAmca_->Write();
  PtMu1FakeWeightTTAmca_->Write();
  PtMu2FakeWeightTTAmca_->Write();
  EtaFakeWeightTTAmca_->Write();
  DRFakeWeightTTAmca_->Write();
  DRNoWeightingTTAmca_->Write();
  DiMuInvMassFakeWeightZoomTTAmca_->Write();
  TauVisMassTTAmca_->Write();
  TauVisMassZoomTTAmca_->Write();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting Fill Colors
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  InvMassTauMuMu1h125a11_->SetLineColor(kGray+1);
//  InvMassTauMuMu2h125a11_->SetLineColor(kGray+1);
//  DiMuInvMassFakeWeighth125a11_->SetLineColor(kGray+1);
//  DiMuDiTauInvMassFakeWeighth125a11_->SetLineColor(kGray+1);
//  DiTauInvMassFakeWeighth125a11_->SetLineColor(kGray+1);
//  PtMu1FakeWeighth125a11_->SetLineColor(kGray+1);
//  PtMu2FakeWeighth125a11_->SetLineColor(kGray+1);
//  EtaFakeWeighth125a11_->SetLineColor(kGray+1);
//  DRFakeWeighth125a11_->SetLineColor(kGray+1);
//  DRNoWeightingh125a11_->SetLineColor(kGray+1);
//  DiMuInvMassFakeWeightZoomh125a11_->SetLineColor(kGray+1);
//  TauVisMassh125a11_->SetLineColor(kGray+1);
//  TauVisMassZoomh125a11_->SetLineColor(kGray+1);

  ////////////////
//  // h125a13
  ////////////////
//  InvMassTauMuMu1h125a13_->SetLineColor(kGreen);
//  InvMassTauMuMu2h125a13_->SetLineColor(kGreen);
//  DiMuInvMassFakeWeighth125a13_->SetLineColor(kGreen);
//  DiMuDiTauInvMassFakeWeighth125a13_->SetLineColor(kGreen);
//  DiTauInvMassFakeWeighth125a13_->SetLineColor(kGreen);
//  PtMu1FakeWeighth125a13_->SetLineColor(kGreen);
//  PtMu2FakeWeighth125a13_->SetLineColor(kGreen);
//  EtaFakeWeighth125a13_->SetLineColor(kGreen);
//  DRFakeWeighth125a13_->SetLineColor(kGreen);
//  DRNoWeightingh125a13_->SetLineColor(kGreen);
//  DiMuInvMassFakeWeightZoomh125a13_->SetLineColor(kGreen);
//  TauVisMassh125a13_->SetLineColor(kGreen);
//  TauVisMassZoomh125a13_->SetLineColor(kGreen);

  ////////////////
//  // h125a15
  ////////////////
//  InvMassTauMuMu1h125a15_->SetLineColor(kTeal-1);
//  InvMassTauMuMu2h125a15_->SetLineColor(kTeal-1);
//  DiMuInvMassFakeWeighth125a15_->SetLineColor(kTeal-1);
//  DiMuDiTauInvMassFakeWeighth125a15_->SetLineColor(kTeal-1);
//  DiTauInvMassFakeWeighth125a15_->SetLineColor(kTeal-1);
//  PtMu1FakeWeighth125a15_->SetLineColor(kTeal-1);
//  PtMu2FakeWeighth125a15_->SetLineColor(kTeal-1);
//  EtaFakeWeighth125a15_->SetLineColor(kTeal-1);
//  DRFakeWeighth125a15_->SetLineColor(kTeal-1);
//  DRNoWeightingh125a15_->SetLineColor(kTeal-1);
//  DiMuInvMassFakeWeightZoomh125a15_->SetLineColor(kTeal-1);
//  TauVisMassh125a15_->SetLineColor(kTeal-1);
//  TauVisMassZoomh125a15_->SetLineColor(kTeal-1);

  ////////////////
//  // h125a17
  ////////////////
//  InvMassTauMuMu1h125a17_->SetLineColor(kCyan);
//  InvMassTauMuMu2h125a17_->SetLineColor(kCyan);
//  DiMuInvMassFakeWeighth125a17_->SetLineColor(kCyan);
//  DiMuDiTauInvMassFakeWeighth125a17_->SetLineColor(kCyan);
//  DiTauInvMassFakeWeighth125a17_->SetLineColor(kCyan);
//  PtMu1FakeWeighth125a17_->SetLineColor(kCyan);
//  PtMu2FakeWeighth125a17_->SetLineColor(kCyan);
//  EtaFakeWeighth125a17_->SetLineColor(kCyan);
//  DRFakeWeighth125a17_->SetLineColor(kCyan);
//  DRNoWeightingh125a17_->SetLineColor(kCyan);
//  DiMuInvMassFakeWeightZoomh125a17_->SetLineColor(kCyan);
//  TauVisMassh125a17_->SetLineColor(kCyan);
//  TauVisMassZoomh125a17_->SetLineColor(kCyan);

  ////////////////
//  // h125a19
  ////////////////
//  InvMassTauMuMu1h125a19_->SetLineColor(kAzure+3);
//  InvMassTauMuMu2h125a19_->SetLineColor(kAzure+3);
//  DiMuInvMassFakeWeighth125a19_->SetLineColor(kAzure+3);
//  DiMuDiTauInvMassFakeWeighth125a19_->SetLineColor(kAzure+3);
//  DiTauInvMassFakeWeighth125a19_->SetLineColor(kAzure+3);
//  PtMu1FakeWeighth125a19_->SetLineColor(kAzure+3);
//  PtMu2FakeWeighth125a19_->SetLineColor(kAzure+3);
//  EtaFakeWeighth125a19_->SetLineColor(kAzure+3);
//  DRFakeWeighth125a19_->SetLineColor(kAzure+3);
//  DRNoWeightingh125a19_->SetLineColor(kAzure+3);
//  DiMuInvMassFakeWeightZoomh125a19_->SetLineColor(kAzure+3);
//  TauVisMassh125a19_->SetLineColor(kAzure+3);
//  TauVisMassZoomh125a19_->SetLineColor(kAzure+3);

  ////////////////
//  // h125a21
  ////////////////
//  InvMassTauMuMu1h125a21_->SetLineColor(kBlue);
//  InvMassTauMuMu2h125a21_->SetLineColor(kBlue);
//  DiMuInvMassFakeWeighth125a21_->SetLineColor(kBlue);
//  DiMuDiTauInvMassFakeWeighth125a21_->SetLineColor(kBlue);
//  DiTauInvMassFakeWeighth125a21_->SetLineColor(kBlue);
//  PtMu1FakeWeighth125a21_->SetLineColor(kBlue);
//  PtMu2FakeWeighth125a21_->SetLineColor(kBlue);
//  EtaFakeWeighth125a21_->SetLineColor(kBlue);
//  DRFakeWeighth125a21_->SetLineColor(kBlue);
//  DRNoWeightingh125a21_->SetLineColor(kBlue);
//  DiMuInvMassFakeWeightZoomh125a21_->SetLineColor(kBlue);
//  TauVisMassh125a21_->SetLineColor(kBlue);
//  TauVisMassZoomh125a21_->SetLineColor(kBlue);

  ////////////////
//  // h125a5
  ////////////////
//  InvMassTauMuMu1h125a5_->SetLineColor(kSpring-7);
//  InvMassTauMuMu2h125a5_->SetLineColor(kSpring-7);
//  DiMuInvMassFakeWeighth125a5_->SetLineColor(kSpring-7);
//  DiMuDiTauInvMassFakeWeighth125a5_->SetLineColor(kSpring-7);
//  DiTauInvMassFakeWeighth125a5_->SetLineColor(kSpring-7);
//  PtMu1FakeWeighth125a5_->SetLineColor(kSpring-7);
//  PtMu2FakeWeighth125a5_->SetLineColor(kSpring-7);
//  EtaFakeWeighth125a5_->SetLineColor(kSpring-7);
//  DRFakeWeighth125a5_->SetLineColor(kSpring-7);
//  DRNoWeightingh125a5_->SetLineColor(kSpring-7);
//  DiMuInvMassFakeWeightZoomh125a5_->SetLineColor(kSpring-7);
//  TauVisMassh125a5_->SetLineColor(kSpring-7);
//  TauVisMassZoomh125a5_->SetLineColor(kSpring-7);

  ////////////////
//  // h125a7
  ////////////////
//  InvMassTauMuMu1h125a7_->SetLineColor(kYellow+1);
//  InvMassTauMuMu2h125a7_->SetLineColor(kYellow+1);
//  DiMuInvMassFakeWeighth125a7_->SetLineColor(kYellow+1);
//  DiMuDiTauInvMassFakeWeighth125a7_->SetLineColor(kYellow+1);
//  DiTauInvMassFakeWeighth125a7_->SetLineColor(kYellow+1);
//  PtMu1FakeWeighth125a7_->SetLineColor(kYellow+1);
//  PtMu2FakeWeighth125a7_->SetLineColor(kYellow+1);
//  EtaFakeWeighth125a7_->SetLineColor(kYellow+1);
//  DRFakeWeighth125a7_->SetLineColor(kYellow+1);
//  DRNoWeightingh125a7_->SetLineColor(kYellow+1);
//  DiMuInvMassFakeWeightZoomh125a7_->SetLineColor(kYellow+1);
//  TauVisMassh125a7_->SetLineColor(kYellow+1);
//  TauVisMassZoomh125a7_->SetLineColor(kYellow+1);

  ////////////////
//  // h125a9
  ////////////////
//  InvMassTauMuMu1h125a9_->SetLineColor(kOrange+9);
//  InvMassTauMuMu2h125a9_->SetLineColor(kOrange+9);
//  DiMuInvMassFakeWeighth125a9_->SetLineColor(kOrange+9);
//  DiMuDiTauInvMassFakeWeighth125a9_->SetLineColor(kOrange+9);
//  DiTauInvMassFakeWeighth125a9_->SetLineColor(kOrange+9);
//  PtMu1FakeWeighth125a9_->SetLineColor(kOrange+9);
//  PtMu2FakeWeighth125a9_->SetLineColor(kOrange+9);
//  EtaFakeWeighth125a9_->SetLineColor(kOrange+9);
//  DRFakeWeighth125a9_->SetLineColor(kOrange+9);
//  DRNoWeightingh125a9_->SetLineColor(kOrange+9);
//  DiMuInvMassFakeWeightZoomh125a9_->SetLineColor(kOrange+9);
//  TauVisMassh125a9_->SetLineColor(kOrange+9);
//  TauVisMassZoomh125a9_->SetLineColor(kOrange+9);

  ////////////////
//  // h300a11
  ////////////////
//  InvMassTauMuMu1h300a11_->SetLineColor(kGray+1);
//  InvMassTauMuMu2h300a11_->SetLineColor(kGray+1);
//  DiMuInvMassFakeWeighth300a11_->SetLineColor(kGray+1);
//  DiMuDiTauInvMassFakeWeighth300a11_->SetLineColor(kGray+1);
//  DiTauInvMassFakeWeighth300a11_->SetLineColor(kGray+1);
//  PtMu1FakeWeighth300a11_->SetLineColor(kGray+1);
//  PtMu2FakeWeighth300a11_->SetLineColor(kGray+1);
//  EtaFakeWeighth300a11_->SetLineColor(kGray+1);
//  DRFakeWeighth300a11_->SetLineColor(kGray+1);
//  DRNoWeightingh300a11_->SetLineColor(kGray+1);
//  DiMuInvMassFakeWeightZoomh300a11_->SetLineColor(kGray+1);
//  TauVisMassh300a11_->SetLineColor(kGray+1);
//  TauVisMassZoomh300a11_->SetLineColor(kGray+1);

  ////////////////
//  // h300a13
  ////////////////
//  InvMassTauMuMu1h300a13_->SetLineColor(kGreen);
//  InvMassTauMuMu2h300a13_->SetLineColor(kGreen);
//  DiMuInvMassFakeWeighth300a13_->SetLineColor(kGreen);
//  DiMuDiTauInvMassFakeWeighth300a13_->SetLineColor(kGreen);
//  DiTauInvMassFakeWeighth300a13_->SetLineColor(kGreen);
//  PtMu1FakeWeighth300a13_->SetLineColor(kGreen);
//  PtMu2FakeWeighth300a13_->SetLineColor(kGreen);
//  EtaFakeWeighth300a13_->SetLineColor(kGreen);
//  DRFakeWeighth300a13_->SetLineColor(kGreen);
//  DRNoWeightingh300a13_->SetLineColor(kGreen);
//  DiMuInvMassFakeWeightZoomh300a13_->SetLineColor(kGreen);
//  TauVisMassh300a13_->SetLineColor(kGreen);
//  TauVisMassZoomh300a13_->SetLineColor(kGreen);

  ////////////////
//  // h300a15
  ////////////////
//  InvMassTauMuMu1h300a15_->SetLineColor(kTeal-1);
//  InvMassTauMuMu2h300a15_->SetLineColor(kTeal-1);
//  DiMuInvMassFakeWeighth300a15_->SetLineColor(kTeal-1);
//  DiMuDiTauInvMassFakeWeighth300a15_->SetLineColor(kTeal-1);
//  DiTauInvMassFakeWeighth300a15_->SetLineColor(kTeal-1);
//  PtMu1FakeWeighth300a15_->SetLineColor(kTeal-1);
//  PtMu2FakeWeighth300a15_->SetLineColor(kTeal-1);
//  EtaFakeWeighth300a15_->SetLineColor(kTeal-1);
//  DRFakeWeighth300a15_->SetLineColor(kTeal-1);
//  DRNoWeightingh300a15_->SetLineColor(kTeal-1);
//  DiMuInvMassFakeWeightZoomh300a15_->SetLineColor(kTeal-1);
//  TauVisMassh300a15_->SetLineColor(kTeal-1);
//  TauVisMassZoomh300a15_->SetLineColor(kTeal-1);

  ////////////////
//  // h300a17
  ////////////////
//  InvMassTauMuMu1h300a17_->SetLineColor(kCyan);
//  InvMassTauMuMu2h300a17_->SetLineColor(kCyan);
//  DiMuInvMassFakeWeighth300a17_->SetLineColor(kCyan);
//  DiMuDiTauInvMassFakeWeighth300a17_->SetLineColor(kCyan);
//  DiTauInvMassFakeWeighth300a17_->SetLineColor(kCyan);
//  PtMu1FakeWeighth300a17_->SetLineColor(kCyan);
//  PtMu2FakeWeighth300a17_->SetLineColor(kCyan);
//  EtaFakeWeighth300a17_->SetLineColor(kCyan);
//  DRFakeWeighth300a17_->SetLineColor(kCyan);
//  DRNoWeightingh300a17_->SetLineColor(kCyan);
//  DiMuInvMassFakeWeightZoomh300a17_->SetLineColor(kCyan);
//  TauVisMassh300a17_->SetLineColor(kCyan);
//  TauVisMassZoomh300a17_->SetLineColor(kCyan);

  ////////////////
//  // h300a19
  ////////////////
//  InvMassTauMuMu1h300a19_->SetLineColor(kAzure+3);
//  InvMassTauMuMu2h300a19_->SetLineColor(kAzure+3);
//  DiMuInvMassFakeWeighth300a19_->SetLineColor(kAzure+3);
//  DiMuDiTauInvMassFakeWeighth300a19_->SetLineColor(kAzure+3);
//  DiTauInvMassFakeWeighth300a19_->SetLineColor(kAzure+3);
//  PtMu1FakeWeighth300a19_->SetLineColor(kAzure+3);
//  PtMu2FakeWeighth300a19_->SetLineColor(kAzure+3);
//  EtaFakeWeighth300a19_->SetLineColor(kAzure+3);
//  DRFakeWeighth300a19_->SetLineColor(kAzure+3);
//  DRNoWeightingh300a19_->SetLineColor(kAzure+3);
//  DiMuInvMassFakeWeightZoomh300a19_->SetLineColor(kAzure+3);
//  TauVisMassh300a19_->SetLineColor(kAzure+3);
//  TauVisMassZoomh300a19_->SetLineColor(kAzure+3);

  ////////////////
//  // h300a21
  ////////////////
//  InvMassTauMuMu1h300a21_->SetLineColor(kBlue);
//  InvMassTauMuMu2h300a21_->SetLineColor(kBlue);
//  DiMuInvMassFakeWeighth300a21_->SetLineColor(kBlue);
//  DiMuDiTauInvMassFakeWeighth300a21_->SetLineColor(kBlue);
//  DiTauInvMassFakeWeighth300a21_->SetLineColor(kBlue);
//  PtMu1FakeWeighth300a21_->SetLineColor(kBlue);
//  PtMu2FakeWeighth300a21_->SetLineColor(kBlue);
//  EtaFakeWeighth300a21_->SetLineColor(kBlue);
//  DRFakeWeighth300a21_->SetLineColor(kBlue);
//  DRNoWeightingh300a21_->SetLineColor(kBlue);
//  DiMuInvMassFakeWeightZoomh300a21_->SetLineColor(kBlue);
//  TauVisMassh300a21_->SetLineColor(kBlue);
//  TauVisMassZoomh300a21_->SetLineColor(kBlue);

  ////////////////
//  // h300a5
  ////////////////
//  InvMassTauMuMu1h300a5_->SetLineColor(kSpring-7);
//  InvMassTauMuMu2h300a5_->SetLineColor(kSpring-7);
//  DiMuInvMassFakeWeighth300a5_->SetLineColor(kSpring-7);
//  DiMuDiTauInvMassFakeWeighth300a5_->SetLineColor(kSpring-7);
//  DiTauInvMassFakeWeighth300a5_->SetLineColor(kSpring-7);
//  PtMu1FakeWeighth300a5_->SetLineColor(kSpring-7);
//  PtMu2FakeWeighth300a5_->SetLineColor(kSpring-7);
//  EtaFakeWeighth300a5_->SetLineColor(kSpring-7);
//  DRFakeWeighth300a5_->SetLineColor(kSpring-7);
//  DRNoWeightingh300a5_->SetLineColor(kSpring-7);
//  DiMuInvMassFakeWeightZoomh300a5_->SetLineColor(kSpring-7);
//  TauVisMassh300a5_->SetLineColor(kSpring-7);
//  TauVisMassZoomh300a5_->SetLineColor(kSpring-7);

  ////////////////
//  // h300a7
  ////////////////
//  InvMassTauMuMu1h300a7_->SetLineColor(kYellow+1);
//  InvMassTauMuMu2h300a7_->SetLineColor(kYellow+1);
//  DiMuInvMassFakeWeighth300a7_->SetLineColor(kYellow+1);
//  DiMuDiTauInvMassFakeWeighth300a7_->SetLineColor(kYellow+1);
//  DiTauInvMassFakeWeighth300a7_->SetLineColor(kYellow+1);
//  PtMu1FakeWeighth300a7_->SetLineColor(kYellow+1);
//  PtMu2FakeWeighth300a7_->SetLineColor(kYellow+1);
//  EtaFakeWeighth300a7_->SetLineColor(kYellow+1);
//  DRFakeWeighth300a7_->SetLineColor(kYellow+1);
//  DRNoWeightingh300a7_->SetLineColor(kYellow+1);
//  DiMuInvMassFakeWeightZoomh300a7_->SetLineColor(kYellow+1);
//  TauVisMassh300a7_->SetLineColor(kYellow+1);
//  TauVisMassZoomh300a7_->SetLineColor(kYellow+1);

  ////////////////
//  // h300a9
  ////////////////
//  InvMassTauMuMu1h300a9_->SetLineColor(kOrange+9);
//  InvMassTauMuMu2h300a9_->SetLineColor(kOrange+9);
//  DiMuInvMassFakeWeighth300a9_->SetLineColor(kOrange+9);
//  DiMuDiTauInvMassFakeWeighth300a9_->SetLineColor(kOrange+9);
//  DiTauInvMassFakeWeighth300a9_->SetLineColor(kOrange+9);
//  PtMu1FakeWeighth300a9_->SetLineColor(kOrange+9);
//  PtMu2FakeWeighth300a9_->SetLineColor(kOrange+9);
//  EtaFakeWeighth300a9_->SetLineColor(kOrange+9);
//  DRFakeWeighth300a9_->SetLineColor(kOrange+9);
//  DRNoWeightingh300a9_->SetLineColor(kOrange+9);
//  DiMuInvMassFakeWeightZoomh300a9_->SetLineColor(kOrange+9);
//  TauVisMassh300a9_->SetLineColor(kOrange+9);
//  TauVisMassZoomh300a9_->SetLineColor(kOrange+9);

  ////////////////
//  // h750a11
  ////////////////
//  InvMassTauMuMu1h750a11_->SetLineColor(kGray+1);
//  InvMassTauMuMu2h750a11_->SetLineColor(kGray+1);
//  DiMuInvMassFakeWeighth750a11_->SetLineColor(kGray+1);
//  DiMuDiTauInvMassFakeWeighth750a11_->SetLineColor(kGray+1);
//  DiTauInvMassFakeWeighth750a11_->SetLineColor(kGray+1);
//  PtMu1FakeWeighth750a11_->SetLineColor(kGray+1);
//  PtMu2FakeWeighth750a11_->SetLineColor(kGray+1);
//  EtaFakeWeighth750a11_->SetLineColor(kGray+1);
//  DRFakeWeighth750a11_->SetLineColor(kGray+1);
//  DRNoWeightingh750a11_->SetLineColor(kGray+1);
//  DiMuInvMassFakeWeightZoomh750a11_->SetLineColor(kGray+1);
//  TauVisMassh750a11_->SetLineColor(kGray+1);
//  TauVisMassZoomh750a11_->SetLineColor(kGray+1);

  ////////////////
//  // h750a13
  ////////////////
//  InvMassTauMuMu1h750a13_->SetLineColor(kGreen);
//  InvMassTauMuMu2h750a13_->SetLineColor(kGreen);
//  DiMuInvMassFakeWeighth750a13_->SetLineColor(kGreen);
//  DiMuDiTauInvMassFakeWeighth750a13_->SetLineColor(kGreen);
//  DiTauInvMassFakeWeighth750a13_->SetLineColor(kGreen);
//  PtMu1FakeWeighth750a13_->SetLineColor(kGreen);
//  PtMu2FakeWeighth750a13_->SetLineColor(kGreen);
//  EtaFakeWeighth750a13_->SetLineColor(kGreen);
//  DRFakeWeighth750a13_->SetLineColor(kGreen);
//  DRNoWeightingh750a13_->SetLineColor(kGreen);
//  DiMuInvMassFakeWeightZoomh750a13_->SetLineColor(kGreen);
//  TauVisMassh750a13_->SetLineColor(kGreen);
//  TauVisMassZoomh750a13_->SetLineColor(kGreen);

  ////////////////
//  // h750a15
  ////////////////
//  InvMassTauMuMu1h750a15_->SetLineColor(kTeal-1);
//  InvMassTauMuMu2h750a15_->SetLineColor(kTeal-1);
//  DiMuInvMassFakeWeighth750a15_->SetLineColor(kTeal-1);
//  DiMuDiTauInvMassFakeWeighth750a15_->SetLineColor(kTeal-1);
//  DiTauInvMassFakeWeighth750a15_->SetLineColor(kTeal-1);
//  PtMu1FakeWeighth750a15_->SetLineColor(kTeal-1);
//  PtMu2FakeWeighth750a15_->SetLineColor(kTeal-1);
//  EtaFakeWeighth750a15_->SetLineColor(kTeal-1);
//  DRFakeWeighth750a15_->SetLineColor(kTeal-1);
//  DRNoWeightingh750a15_->SetLineColor(kTeal-1);
//  DiMuInvMassFakeWeightZoomh750a15_->SetLineColor(kTeal-1);
//  TauVisMassh750a15_->SetLineColor(kTeal-1);
//  TauVisMassZoomh750a15_->SetLineColor(kTeal-1);

  ////////////////
//  // h750a17
  ////////////////
//  InvMassTauMuMu1h750a17_->SetLineColor(kCyan);
//  InvMassTauMuMu2h750a17_->SetLineColor(kCyan);
//  DiMuInvMassFakeWeighth750a17_->SetLineColor(kCyan);
//  DiMuDiTauInvMassFakeWeighth750a17_->SetLineColor(kCyan);
//  DiTauInvMassFakeWeighth750a17_->SetLineColor(kCyan);
//  PtMu1FakeWeighth750a17_->SetLineColor(kCyan);
//  PtMu2FakeWeighth750a17_->SetLineColor(kCyan);
//  EtaFakeWeighth750a17_->SetLineColor(kCyan);
//  DRFakeWeighth750a17_->SetLineColor(kCyan);
//  DRNoWeightingh750a17_->SetLineColor(kCyan);
//  DiMuInvMassFakeWeightZoomh750a17_->SetLineColor(kCyan);
//  TauVisMassh750a17_->SetLineColor(kCyan);
//  TauVisMassZoomh750a17_->SetLineColor(kCyan);

  ////////////////
//  // h750a19
  ////////////////
//  InvMassTauMuMu1h750a19_->SetLineColor(kAzure+3);
//  InvMassTauMuMu2h750a19_->SetLineColor(kAzure+3);
//  DiMuInvMassFakeWeighth750a19_->SetLineColor(kAzure+3);
//  DiMuDiTauInvMassFakeWeighth750a19_->SetLineColor(kAzure+3);
//  DiTauInvMassFakeWeighth750a19_->SetLineColor(kAzure+3);
//  PtMu1FakeWeighth750a19_->SetLineColor(kAzure+3);
//  PtMu2FakeWeighth750a19_->SetLineColor(kAzure+3);
//  EtaFakeWeighth750a19_->SetLineColor(kAzure+3);
//  DRFakeWeighth750a19_->SetLineColor(kAzure+3);
//  DRNoWeightingh750a19_->SetLineColor(kAzure+3);
//  DiMuInvMassFakeWeightZoomh750a19_->SetLineColor(kAzure+3);
//  TauVisMassh750a19_->SetLineColor(kAzure+3);
//  TauVisMassZoomh750a19_->SetLineColor(kAzure+3);

  ////////////////
//  // h750a21
  ////////////////
//  InvMassTauMuMu1h750a21_->SetLineColor(kBlue);
//  InvMassTauMuMu2h750a21_->SetLineColor(kBlue);
//  DiMuInvMassFakeWeighth750a21_->SetLineColor(kBlue);
//  DiMuDiTauInvMassFakeWeighth750a21_->SetLineColor(kBlue);
//  DiTauInvMassFakeWeighth750a21_->SetLineColor(kBlue);
//  PtMu1FakeWeighth750a21_->SetLineColor(kBlue);
//  PtMu2FakeWeighth750a21_->SetLineColor(kBlue);
//  EtaFakeWeighth750a21_->SetLineColor(kBlue);
//  DRFakeWeighth750a21_->SetLineColor(kBlue);
//  DRNoWeightingh750a21_->SetLineColor(kBlue);
//  DiMuInvMassFakeWeightZoomh750a21_->SetLineColor(kBlue);
//  TauVisMassh750a21_->SetLineColor(kBlue);
//  TauVisMassZoomh750a21_->SetLineColor(kBlue);

  ////////////////
//  // h750a5
  ////////////////
//  InvMassTauMuMu1h750a5_->SetLineColor(kSpring-7);
//  InvMassTauMuMu2h750a5_->SetLineColor(kSpring-7);
//  DiMuInvMassFakeWeighth750a5_->SetLineColor(kSpring-7);
//  DiMuDiTauInvMassFakeWeighth750a5_->SetLineColor(kSpring-7);
//  DiTauInvMassFakeWeighth750a5_->SetLineColor(kSpring-7);
//  PtMu1FakeWeighth750a5_->SetLineColor(kSpring-7);
//  PtMu2FakeWeighth750a5_->SetLineColor(kSpring-7);
//  EtaFakeWeighth750a5_->SetLineColor(kSpring-7);
//  DRFakeWeighth750a5_->SetLineColor(kSpring-7);
//  DRNoWeightingh750a5_->SetLineColor(kSpring-7);
//  DiMuInvMassFakeWeightZoomh750a5_->SetLineColor(kSpring-7);
//  TauVisMassh750a5_->SetLineColor(kSpring-7);
//  TauVisMassZoomh750a5_->SetLineColor(kSpring-7);

  ////////////////
//  // h750a7
  ////////////////
//  InvMassTauMuMu1h750a7_->SetLineColor(kYellow+1);
//  InvMassTauMuMu2h750a7_->SetLineColor(kYellow+1);
//  DiMuInvMassFakeWeighth750a7_->SetLineColor(kYellow+1);
//  DiMuDiTauInvMassFakeWeighth750a7_->SetLineColor(kYellow+1);
//  DiTauInvMassFakeWeighth750a7_->SetLineColor(kYellow+1);
//  PtMu1FakeWeighth750a7_->SetLineColor(kYellow+1);
//  PtMu2FakeWeighth750a7_->SetLineColor(kYellow+1);
//  EtaFakeWeighth750a7_->SetLineColor(kYellow+1);
//  DRFakeWeighth750a7_->SetLineColor(kYellow+1);
//  DRNoWeightingh750a7_->SetLineColor(kYellow+1);
//  DiMuInvMassFakeWeightZoomh750a7_->SetLineColor(kYellow+1);
//  TauVisMassh750a7_->SetLineColor(kYellow+1);
//  TauVisMassZoomh750a7_->SetLineColor(kYellow+1);

  ////////////////
//  // h750a9
  ////////////////
//  InvMassTauMuMu1h750a9_->SetLineColor(kOrange+9);
//  InvMassTauMuMu2h750a9_->SetLineColor(kOrange+9);
//  DiMuInvMassFakeWeighth750a9_->SetLineColor(kOrange+9);
//  DiMuDiTauInvMassFakeWeighth750a9_->SetLineColor(kOrange+9);
//  DiTauInvMassFakeWeighth750a9_->SetLineColor(kOrange+9);
//  PtMu1FakeWeighth750a9_->SetLineColor(kOrange+9);
//  PtMu2FakeWeighth750a9_->SetLineColor(kOrange+9);
//  EtaFakeWeighth750a9_->SetLineColor(kOrange+9);
//  DRFakeWeighth750a9_->SetLineColor(kOrange+9);
//  DRNoWeightingh750a9_->SetLineColor(kOrange+9);
//  DiMuInvMassFakeWeightZoomh750a9_->SetLineColor(kOrange+9);
//  TauVisMassh750a9_->SetLineColor(kOrange+9);
//  TauVisMassZoomh750a9_->SetLineColor(kOrange+9);

  ////////////////
  // QCD
  ////////////////
  InvMassTauMuMu1QCD_->SetLineColor(kViolet+2);
  InvMassTauMuMu2QCD_->SetLineColor(kViolet+2);
  DiMuInvMassFakeWeightQCD_->SetLineColor(kViolet+2);
  DiMuDiTauInvMassFakeWeightQCD_->SetLineColor(kViolet+2);
  DiTauInvMassFakeWeightQCD_->SetLineColor(kViolet+2);
  PtMu1FakeWeightQCD_->SetLineColor(kViolet+2);
  PtMu2FakeWeightQCD_->SetLineColor(kViolet+2);
  EtaFakeWeightQCD_->SetLineColor(kViolet+2);
  DRFakeWeightQCD_->SetLineColor(kViolet+2);
  DRNoWeightingQCD_->SetLineColor(kViolet+2);
  DiMuInvMassFakeWeightZoomQCD_->SetLineColor(kViolet+2);
  TauVisMassQCD_->SetLineColor(kViolet+2);
  TauVisMassZoomQCD_->SetLineColor(kViolet+2);

  ////////////////
  // DiBoson
  ////////////////
  InvMassTauMuMu1DiBoson_->SetLineColor(kPink+1);
  InvMassTauMuMu2DiBoson_->SetLineColor(kPink+1);
  DiMuInvMassFakeWeightDiBoson_->SetLineColor(kPink+1);
  DiMuDiTauInvMassFakeWeightDiBoson_->SetLineColor(kPink+1);
  DiTauInvMassFakeWeightDiBoson_->SetLineColor(kPink+1);
  PtMu1FakeWeightDiBoson_->SetLineColor(kPink+1);
  PtMu2FakeWeightDiBoson_->SetLineColor(kPink+1);
  EtaFakeWeightDiBoson_->SetLineColor(kPink+1);
  DRFakeWeightDiBoson_->SetLineColor(kPink+1);
  DRNoWeightingDiBoson_->SetLineColor(kPink+1);
  DiMuInvMassFakeWeightZoomDiBoson_->SetLineColor(kPink+1);
  TauVisMassDiBoson_->SetLineColor(kPink+1);
  TauVisMassZoomDiBoson_->SetLineColor(kPink+1);

  ////////////////
  // ST
  ////////////////
  InvMassTauMuMu1ST_->SetLineColor(kViolet-3);
  InvMassTauMuMu2ST_->SetLineColor(kViolet-3);
  DiMuInvMassFakeWeightST_->SetLineColor(kViolet-3);
  DiMuDiTauInvMassFakeWeightST_->SetLineColor(kViolet-3);
  DiTauInvMassFakeWeightST_->SetLineColor(kViolet-3);
  PtMu1FakeWeightST_->SetLineColor(kViolet-3);
  PtMu2FakeWeightST_->SetLineColor(kViolet-3);
  EtaFakeWeightST_->SetLineColor(kViolet-3);
  DRFakeWeightST_->SetLineColor(kViolet-3);
  DRNoWeightingST_->SetLineColor(kViolet-3);
  DiMuInvMassFakeWeightZoomST_->SetLineColor(kViolet-3);
  TauVisMassST_->SetLineColor(kViolet-3);
  TauVisMassZoomST_->SetLineColor(kViolet-3);

  ////////////////
  // DY
  ////////////////
  InvMassTauMuMu1DY_->SetLineColor(kGray);
  InvMassTauMuMu2DY_->SetLineColor(kGray);
  DiMuInvMassFakeWeightDY_->SetLineColor(kGray);
  DiMuDiTauInvMassFakeWeightDY_->SetLineColor(kGray);
  DiTauInvMassFakeWeightDY_->SetLineColor(kGray);
  PtMu1FakeWeightDY_->SetLineColor(kGray);
  PtMu2FakeWeightDY_->SetLineColor(kGray);
  EtaFakeWeightDY_->SetLineColor(kGray);
  DRFakeWeightDY_->SetLineColor(kGray);
  DRNoWeightingDY_->SetLineColor(kGray);
  DiMuInvMassFakeWeightZoomDY_->SetLineColor(kGray);
  TauVisMassDY_->SetLineColor(kGray);
  TauVisMassZoomDY_->SetLineColor(kGray);

  ////////////////
  ////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting Fill Color
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////
  // QCD
  ////////////////
  InvMassTauMuMu1TTAmca_->SetFillColor(kRed);
  InvMassTauMuMu2TTAmca_->SetFillColor(kRed);
  DiMuInvMassFakeWeightTTAmca_->SetFillColor(kRed);
  DiMuDiTauInvMassFakeWeightTTAmca_->SetFillColor(kRed);
  DiTauInvMassFakeWeightTTAmca_->SetFillColor(kRed);
  PtMu1FakeWeightTTAmca_->SetFillColor(kRed);
  PtMu2FakeWeightTTAmca_->SetFillColor(kRed);
  EtaFakeWeightTTAmca_->SetFillColor(kRed);
  DRFakeWeightTTAmca_->SetFillColor(kRed);
  DRNoWeightingTTAmca_->SetFillColor(kRed);
  DiMuInvMassFakeWeightZoomTTAmca_->SetFillColor(kRed);
  TauVisMassTTAmca_->SetFillColor(kRed);
  TauVisMassZoomTTAmca_->SetFillColor(kRed);

  ////////////////
  // QCD
  ////////////////
  InvMassTauMuMu1QCD_->SetFillColor(kViolet+2);
  InvMassTauMuMu2QCD_->SetFillColor(kViolet+2);
  DiMuInvMassFakeWeightQCD_->SetFillColor(kViolet+2);
  DiMuDiTauInvMassFakeWeightQCD_->SetFillColor(kViolet+2);
  DiTauInvMassFakeWeightQCD_->SetFillColor(kViolet+2);
  PtMu1FakeWeightQCD_->SetFillColor(kViolet+2);
  PtMu2FakeWeightQCD_->SetFillColor(kViolet+2);
  EtaFakeWeightQCD_->SetFillColor(kViolet+2);
  DRFakeWeightQCD_->SetFillColor(kViolet+2);
  DRNoWeightingQCD_->SetFillColor(kViolet+2);
  DiMuInvMassFakeWeightZoomQCD_->SetFillColor(kViolet+2);
  TauVisMassQCD_->SetFillColor(kViolet+2);
  TauVisMassZoomQCD_->SetFillColor(kViolet+2);

  ////////////////
  // DiBoson
  ////////////////
  InvMassTauMuMu1DiBoson_->SetFillColor(kPink+1);
  InvMassTauMuMu2DiBoson_->SetFillColor(kPink+1);
  DiMuInvMassFakeWeightDiBoson_->SetFillColor(kPink+1);
  DiMuDiTauInvMassFakeWeightDiBoson_->SetFillColor(kPink+1);
  DiTauInvMassFakeWeightDiBoson_->SetFillColor(kPink+1);
  PtMu1FakeWeightDiBoson_->SetFillColor(kPink+1);
  PtMu2FakeWeightDiBoson_->SetFillColor(kPink+1);
  EtaFakeWeightDiBoson_->SetFillColor(kPink+1);
  DRFakeWeightDiBoson_->SetFillColor(kPink+1);
  DRNoWeightingDiBoson_->SetFillColor(kPink+1);
  DiMuInvMassFakeWeightZoomDiBoson_->SetFillColor(kPink+1);
  TauVisMassDiBoson_->SetFillColor(kPink+1);
  TauVisMassZoomDiBoson_->SetFillColor(kPink+1);

  ////////////////
  // ST
  ////////////////
  InvMassTauMuMu1ST_->SetFillColor(kViolet-3);
  InvMassTauMuMu2ST_->SetFillColor(kViolet-3);
  DiMuInvMassFakeWeightST_->SetFillColor(kViolet-3);
  DiMuDiTauInvMassFakeWeightST_->SetFillColor(kViolet-3);
  DiTauInvMassFakeWeightST_->SetFillColor(kViolet-3);
  PtMu1FakeWeightST_->SetFillColor(kViolet-3);
  PtMu2FakeWeightST_->SetFillColor(kViolet-3);
  EtaFakeWeightST_->SetFillColor(kViolet-3);
  DRFakeWeightST_->SetFillColor(kViolet-3);
  DRNoWeightingST_->SetFillColor(kViolet-3);
  DiMuInvMassFakeWeightZoomST_->SetFillColor(kViolet-3);
  TauVisMassST_->SetFillColor(kViolet-3);
  TauVisMassZoomST_->SetFillColor(kViolet-3);


  ////////////////
  // DY
  ////////////////
  InvMassTauMuMu1DY_->SetFillColor(kGray);
  InvMassTauMuMu2DY_->SetFillColor(kGray);
  DiMuInvMassFakeWeightDY_->SetFillColor(kGray);
  DiMuDiTauInvMassFakeWeightDY_->SetFillColor(kGray);
  DiTauInvMassFakeWeightDY_->SetFillColor(kGray);
  PtMu1FakeWeightDY_->SetFillColor(kGray);
  PtMu2FakeWeightDY_->SetFillColor(kGray);
  EtaFakeWeightDY_->SetFillColor(kGray);
  DRFakeWeightDY_->SetFillColor(kGray);
  DRNoWeightingDY_->SetFillColor(kGray);
  DiMuInvMassFakeWeightZoomDY_->SetFillColor(kGray);
  TauVisMassDY_->SetFillColor(kGray);
  TauVisMassZoomDY_->SetFillColor(kGray);

  ////////////////
  // DY
  ////////////////
  InvMassTauMuMu1DY_->SetFillColor(kGray);
  InvMassTauMuMu2DY_->SetFillColor(kGray);
  DiMuInvMassFakeWeightDY_->SetFillColor(kGray);
  DiMuDiTauInvMassFakeWeightDY_->SetFillColor(kGray);
  DiTauInvMassFakeWeightDY_->SetFillColor(kGray);
  PtMu1FakeWeightDY_->SetFillColor(kGray);
  PtMu2FakeWeightDY_->SetFillColor(kGray);
  EtaFakeWeightDY_->SetFillColor(kGray);
  DRFakeWeightDY_->SetFillColor(kGray);
  DRNoWeightingDY_->SetFillColor(kGray);
  DiMuInvMassFakeWeightZoomDY_->SetFillColor(kGray);
  TauVisMassDY_->SetFillColor(kGray);
  TauVisMassZoomDY_->SetFillColor(kGray);

cout << "Set Colors" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Making the stack
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  THStack *InvMassTauMuMu1Stack = new THStack ("InvMassTauMuMu1Stack","");
  THStack *InvMassTauMuMu2Stack = new THStack ("InvMassTauMuMu2Stack","");
  THStack *DiMuInvMassFakeWeightStack = new THStack ("DiMuInvMassFakeWeightStack","");
  THStack *DiMuDiTauInvMassFakeWeightStack = new THStack ("DiMuDiTauInvMassFakeWeightStack","");
  THStack *DiTauInvMassFakeWeightStack = new THStack ("DiMuDiTauInvMassFakeWeightStack","");
  THStack *PtMu1FakeWeightStack = new THStack ("PtMu1FakeWeightStack","");
  THStack *PtMu2FakeWeightStack = new THStack ("PtMu2FakeWeightStack","");
  THStack *EtaFakeWeightStack = new THStack ("EtaFakeWeightStack","");
  THStack *DRFakeWeightStack = new THStack ("DRFakeWeightStack","");
  THStack *DRNoWeightingStack = new THStack ("DRNoWeightingStack","");
  THStack *DiMuInvMassFakeWeightZoomStack = new THStack ("DiMuInvMassFakeWeightZoomStack","");
  THStack *TauVisMassStack = new THStack ("TauVisMassStack","");
  THStack *TauVisMassZoomStack = new THStack ("TauVisMassZoomStack","");
 
//  InvMassTauMuMu1Stack->Add(InvMassTauMuMu1QCD_);
  InvMassTauMuMu1Stack->Add(InvMassTauMuMu1ST_);
  InvMassTauMuMu1Stack->Add(InvMassTauMuMu1DiBoson_);
  InvMassTauMuMu1Stack->Add(InvMassTauMuMu1DY_);
  InvMassTauMuMu1Stack->Add(InvMassTauMuMu1TTAmca_);

//  InvMassTauMuMu2Stack->Add(InvMassTauMuMu2QCD_);
  InvMassTauMuMu2Stack->Add(InvMassTauMuMu2ST_);
  InvMassTauMuMu2Stack->Add(InvMassTauMuMu2DiBoson_);
  InvMassTauMuMu2Stack->Add(InvMassTauMuMu2DY_);
  InvMassTauMuMu2Stack->Add(InvMassTauMuMu2TTAmca_);

//  DiMuInvMassFakeWeightStack->Add(DiMuInvMassFakeWeightQCD_);
  DiMuInvMassFakeWeightStack->Add(DiMuInvMassFakeWeightST_);
  DiMuInvMassFakeWeightStack->Add(DiMuInvMassFakeWeightDiBoson_);
  DiMuInvMassFakeWeightStack->Add(DiMuInvMassFakeWeightDY_);
  DiMuInvMassFakeWeightStack->Add(DiMuInvMassFakeWeightTTAmca_);

//  DiMuDiTauInvMassFakeWeightStack->Add(DiMuDiTauInvMassFakeWeightQCD_);
  DiMuDiTauInvMassFakeWeightStack->Add(DiMuDiTauInvMassFakeWeightST_);
  DiMuDiTauInvMassFakeWeightStack->Add(DiMuDiTauInvMassFakeWeightDiBoson_);
  DiMuDiTauInvMassFakeWeightStack->Add(DiMuDiTauInvMassFakeWeightDY_);
  DiMuDiTauInvMassFakeWeightStack->Add(DiMuDiTauInvMassFakeWeightTTAmca_);

//  DiTauInvMassFakeWeightStack->Add(DiTauInvMassFakeWeightQCD_);
  DiTauInvMassFakeWeightStack->Add(DiTauInvMassFakeWeightST_);
  DiTauInvMassFakeWeightStack->Add(DiTauInvMassFakeWeightDiBoson_);
  DiTauInvMassFakeWeightStack->Add(DiTauInvMassFakeWeightDY_);
  DiTauInvMassFakeWeightStack->Add(DiTauInvMassFakeWeightTTAmca_);

//  PtMu1FakeWeightStack->Add(PtMu1FakeWeightQCD_);
  PtMu1FakeWeightStack->Add(PtMu1FakeWeightST_);
  PtMu1FakeWeightStack->Add(PtMu1FakeWeightDiBoson_);
  PtMu1FakeWeightStack->Add(PtMu1FakeWeightDY_);
  PtMu1FakeWeightStack->Add(PtMu1FakeWeightTTAmca_);

//  PtMu2FakeWeightStack->Add(PtMu2FakeWeightQCD_);
  PtMu2FakeWeightStack->Add(PtMu2FakeWeightST_);
  PtMu2FakeWeightStack->Add(PtMu2FakeWeightDiBoson_);
  PtMu2FakeWeightStack->Add(PtMu2FakeWeightDY_);
  PtMu2FakeWeightStack->Add(PtMu2FakeWeightTTAmca_);

//  EtaFakeWeightStack->Add(EtaFakeWeightQCD_);
  EtaFakeWeightStack->Add(EtaFakeWeightST_);
  EtaFakeWeightStack->Add(EtaFakeWeightDiBoson_);
  EtaFakeWeightStack->Add(EtaFakeWeightDY_);
  EtaFakeWeightStack->Add(EtaFakeWeightTTAmca_);

//  DRFakeWeightStack->Add(DRFakeWeightQCD_);
  DRFakeWeightStack->Add(DRFakeWeightST_);
  DRFakeWeightStack->Add(DRFakeWeightDiBoson_);
  DRFakeWeightStack->Add(DRFakeWeightDY_);
  DRFakeWeightStack->Add(DRFakeWeightTTAmca_);

//  DRNoWeightingStack->Add(DRNoWeightingQCD_);
  DRNoWeightingStack->Add(DRNoWeightingST_);
  DRNoWeightingStack->Add(DRNoWeightingDiBoson_);
  DRNoWeightingStack->Add(DRNoWeightingDY_);
  DRNoWeightingStack->Add(DRNoWeightingTTAmca_);

//  DiMuInvMassFakeWeightZoomStack->Add(DiMuInvMassFakeWeightZoomQCD_);
  DiMuInvMassFakeWeightZoomStack->Add(DiMuInvMassFakeWeightZoomST_);
  DiMuInvMassFakeWeightZoomStack->Add(DiMuInvMassFakeWeightZoomDiBoson_);
  DiMuInvMassFakeWeightZoomStack->Add(DiMuInvMassFakeWeightZoomDY_);
  DiMuInvMassFakeWeightZoomStack->Add(DiMuInvMassFakeWeightZoomTTAmca_);

//  TauVisMassStack->Add(TauVisMassQCD_);
  TauVisMassStack->Add(TauVisMassST_);
  TauVisMassStack->Add(TauVisMassDiBoson_);
  TauVisMassStack->Add(TauVisMassDY_);
  TauVisMassStack->Add(TauVisMassTTAmca_);

//  TauVisMassZoomStack->Add(TauVisMassZoomQCD_);
  TauVisMassZoomStack->Add(TauVisMassZoomST_);
  TauVisMassZoomStack->Add(TauVisMassZoomDiBoson_);
  TauVisMassZoomStack->Add(TauVisMassZoomDY_);
  TauVisMassZoomStack->Add(TauVisMassZoomTTAmca_);

cout << "Created and Added Stacks" << endl;
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
  TCanvas *DRNoWeightingCanvas = new TCanvas ("DRNoWeightingCanvas","",600,600);
  TCanvas *DiMuInvMassFakeWeightZoomCanvas = new TCanvas ("DiMuInvMassFakeWeightZoomCanvas","",600,600);
  TCanvas *TauVisMassCanvas = new TCanvas ("TauVisMassCanvas","",600,600);
  TCanvas *TauVisMassZoomCanvas = new TCanvas ("TauVisMassZoomCanvas","",600,600);

  InvMassTauMuMu1Canvas->Divide(2,1);
  InvMassTauMuMu2Canvas->Divide(2,1);
  DiMuInvMassFakeWeightCanvas->Divide(2,1);
  DiMuDiTauInvMassFakeWeightCanvas->Divide(2,1);
  DiTauInvMassFakeWeightCanvas->Divide(2,1);
  PtMu1FakeWeightCanvas->Divide(2,1);
  PtMu2FakeWeightCanvas->Divide(2,1);
  EtaFakeWeightCanvas->Divide(2,1);
  DRFakeWeightCanvas->Divide(2,1);
  DRNoWeightingCanvas->Divide(2,1);
  DiMuInvMassFakeWeightZoomCanvas->Divide(2,1);
  TauVisMassCanvas->Divide(2,1);
  TauVisMassZoomCanvas->Divide(2,1);

  TPad *InvMassTauMuMu1PlotPad = new TPad ("InvMassTauMuMu1PlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassTauMuMu2PlotPad = new TPad ("InvMassTauMuMu2PlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuInvMassFakeWeightPlotPad = new TPad ("DiMuInvMassFakeWeightPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuDiTauInvMassFakeWeightPlotPad = new TPad ("DiMuDiTauInvMassFakeWeightPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauInvMassFakeWeightPlotPad = new TPad ("DiMuDiTauInvMassFakeWeightPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *PtMu1FakeWeightPlotPad = new TPad ("PtMu1FakeWeightPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *PtMu2FakeWeightPlotPad = new TPad ("PtMu2FakeWeightPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *EtaFakeWeightPlotPad = new TPad ("EtaFakeWeightPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DRFakeWeightPlotPad = new TPad ("DRFakeWeightPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DRNoWeightingPlotPad = new TPad ("DRNoWeightingPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuInvMassFakeWeightZoomPlotPad = new TPad ("DiMuInvMassFakeWeightZoomPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *TauVisMassPlotPad = new TPad ("TauVisMassPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *TauVisMassZoomPlotPad = new TPad ("TauVisMassZoomPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);

//  InvMassTauMuMu1PlotPad->SetBottomMargin(0.04);
//  InvMassTauMuMu2PlotPad->SetBottomMargin(0.04);
//  DiMuInvMassFakeWeightPlotPad->SetBottomMargin(0.04);
//  DiMuDiTauInvMassFakeWeightPlotPad->SetBottomMargin(0.04);
//  DiTauInvMassFakeWeightPlotPad->SetBottomMargin(0.04);
//  PtMu1FakeWeightPlotPad->SetBottomMargin(0.04);
//  PtMu2FakeWeightPlotPad->SetBottomMargin(0.04);
//  EtaFakeWeightPlotPad->SetBottomMargin(0.04);
//  DRFakeWeightPlotPad->SetBottomMargin(0.04);
//  DRNoWeightingPlotPad->SetBottomMargin(0.04);
//  DiMuInvMassFakeWeightZoomPlotPad->SetBottomMargin(0.04);
//  TauVisMassPlotPad->SetBottomMargin(0.04);
//  TauVisMassZoomPlotPad->SetBottomMargin(0.04);
  
//  InvMassTauMuMu1PlotPad->SetRightMargin(0.03);
//  InvMassTauMuMu2PlotPad->SetRightMargin(0.03);
//  DiMuInvMassFakeWeightPlotPad->SetRightMargin(0.03);
//  DiMuDiTauInvMassFakeWeightPlotPad->SetRightMargin(0.03);
//  DiTauInvMassFakeWeightPlotPad->SetRightMargin(0.03);
//  PtMu1FakeWeightPlotPad->SetRightMargin(0.03);
//  PtMu2FakeWeightPlotPad->SetRightMargin(0.03);
//  EtaFakeWeightPlotPad->SetRightMargin(0.03);
//  DRFakeWeightPlotPad->SetRightMargin(0.03);
//  DRNoWeightingPlotPad->SetRightMargin(0.03);
//  DiMuInvMassFakeWeightZoomPlotPad->SetRightMargin(0.03);
//  TauVisMassPlotPad->SetRightMargin(0.03);
//  TauVisMassZoomPlotPad->SetRightMargin(0.03);
  
  InvMassTauMuMu1Canvas->cd(2);
  InvMassTauMuMu1PlotPad->Draw();
  InvMassTauMuMu2Canvas->cd(2);
  InvMassTauMuMu2PlotPad->Draw();
  DiMuInvMassFakeWeightCanvas->cd(2);
  DiMuInvMassFakeWeightPlotPad->Draw();
  DiMuDiTauInvMassFakeWeightCanvas->cd(2);
  DiMuDiTauInvMassFakeWeightPlotPad->Draw();
  DiTauInvMassFakeWeightCanvas->cd(2);
  DiTauInvMassFakeWeightPlotPad->Draw();
  PtMu1FakeWeightCanvas->cd(2);
  PtMu1FakeWeightPlotPad->Draw();
  PtMu2FakeWeightCanvas->cd(2);
  PtMu2FakeWeightPlotPad->Draw();
  EtaFakeWeightCanvas->cd(2);
  EtaFakeWeightPlotPad->Draw();
  DRFakeWeightCanvas->cd(2);
  DRFakeWeightPlotPad->Draw();
  DRNoWeightingCanvas->cd(2);
  DRNoWeightingPlotPad->Draw();
  DiMuInvMassFakeWeightZoomCanvas->cd(2);
  DiMuInvMassFakeWeightZoomPlotPad->Draw();
  TauVisMassCanvas->cd(2);
  TauVisMassPlotPad->Draw();
  TauVisMassZoomCanvas->cd(2);
  TauVisMassZoomPlotPad->Draw();
  
  InvMassTauMuMu1PlotPad->SetLogy(true);
  InvMassTauMuMu2PlotPad->SetLogy(true);
  DiMuInvMassFakeWeightPlotPad->SetLogy(true);
  DiMuDiTauInvMassFakeWeightPlotPad->SetLogy(true);
  DiTauInvMassFakeWeightPlotPad->SetLogy(true);
  PtMu1FakeWeightPlotPad->SetLogy(true);
  PtMu2FakeWeightPlotPad->SetLogy(true);
  EtaFakeWeightPlotPad->SetLogy(true);
  DRFakeWeightPlotPad->SetLogy(true);
  DRNoWeightingPlotPad->SetLogy(true);
  DiMuInvMassFakeWeightZoomPlotPad->SetLogy(true);
  TauVisMassPlotPad->SetLogy(true);
  TauVisMassZoomPlotPad->SetLogy(true);
  
  InvMassTauMuMu1PlotPad->SetLogx(false);
  InvMassTauMuMu2PlotPad->SetLogx(false);
  DiMuInvMassFakeWeightPlotPad->SetLogx(false);
  DiMuDiTauInvMassFakeWeightPlotPad->SetLogx(false);
  DiTauInvMassFakeWeightPlotPad->SetLogx(false);
  PtMu1FakeWeightPlotPad->SetLogx(false);
  PtMu2FakeWeightPlotPad->SetLogx(false);
  EtaFakeWeightPlotPad->SetLogx(false);
  DRFakeWeightPlotPad->SetLogx(false);
  DRNoWeightingPlotPad->SetLogx(false);
  DiMuInvMassFakeWeightZoomPlotPad->SetLogx(false);
  TauVisMassPlotPad->SetLogx(false);
  TauVisMassZoomPlotPad->SetLogx(false);
  
cout << "Created the Output Pads" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Legends
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TLegend *legend = new TLegend(0.7,0.5,0.95,0.7) ;
  legend->SetTextFont(42);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);

  legend->SetHeader("Estimate Region B From D Data");
  legend->AddEntry(TauVisMassTTAmca_ ,"TT", "f");
  legend->AddEntry(TauVisMassDY_ ,"DY", "f");
  legend->AddEntry(TauVisMassDiBoson_ ,"DiBoson", "f");
  legend->AddEntry(TauVisMassST_ ,"ST", "f");
  legend->AddEntry(TauVisMassEstimateFromD_, "Data Estimate", "le");
//  legend->AddEntry(TauVisMassQCD_ ,"QCD", "f");
//  legend->AddEntry(TauVisMassh125a9_ ,"h125a9", "f");

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Drawing the stacks
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  stringstream InvMassTauMuMu1StackYTitle;
  InvMassTauMuMu1StackYTitle << fixed;
  InvMassTauMuMu1StackYTitle.precision(2);
  InvMassTauMuMu1StackYTitle << "Events / " << InvMassTauMuMu1EstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream InvMassTauMuMu2StackYTitle;
  InvMassTauMuMu2StackYTitle << fixed;
  InvMassTauMuMu2StackYTitle.precision(2);
  InvMassTauMuMu2StackYTitle << "Events / " << InvMassTauMuMu2EstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream DiMuInvMassFakeWeightStackYTitle;
  DiMuInvMassFakeWeightStackYTitle << fixed;
  DiMuInvMassFakeWeightStackYTitle.precision(2);
  DiMuInvMassFakeWeightStackYTitle << "Events / " << DiMuInvMassFakeWeightEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream DiMuDiTauInvMassFakeWeightStackYTitle;
  DiMuDiTauInvMassFakeWeightStackYTitle << fixed;
  DiMuDiTauInvMassFakeWeightStackYTitle.precision(2);
  DiMuDiTauInvMassFakeWeightStackYTitle << "Events / " << DiMuDiTauInvMassFakeWeightEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream DiTauInvMassFakeWeightStackYTitle;
  DiTauInvMassFakeWeightStackYTitle << fixed;
  DiTauInvMassFakeWeightStackYTitle.precision(2);
  DiTauInvMassFakeWeightStackYTitle << "Events / " << DiTauInvMassFakeWeightEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream PtMu1FakeWeightStackYTitle;
  PtMu1FakeWeightStackYTitle << fixed;
  PtMu1FakeWeightStackYTitle.precision(2);
  PtMu1FakeWeightStackYTitle << "Events / " << PtMu1FakeWeightEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream PtMu2FakeWeightStackYTitle;
  PtMu2FakeWeightStackYTitle << fixed;
  PtMu2FakeWeightStackYTitle.precision(2);
  PtMu2FakeWeightStackYTitle << "Events / " << PtMu2FakeWeightEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream EtaFakeWeightStackYTitle;
  EtaFakeWeightStackYTitle << fixed;
  EtaFakeWeightStackYTitle.precision(2);
  EtaFakeWeightStackYTitle << "Events / " << EtaFakeWeightEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

std::cout << "chceck1" << std::endl;
  stringstream DRFakeWeightStackYTitle;
  DRFakeWeightStackYTitle << fixed;
  DRFakeWeightStackYTitle.precision(2);
  DRFakeWeightStackYTitle << "Events / " << DRFakeWeightEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream TauVisMassStackYTitle;
  TauVisMassStackYTitle << fixed;
  TauVisMassStackYTitle.precision(2);
  TauVisMassStackYTitle << "Events / " << TauVisMassEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream TauVisMassZoomStackYTitle;
  TauVisMassZoomStackYTitle << fixed;
  TauVisMassZoomStackYTitle.precision(2);
  TauVisMassZoomStackYTitle << "Events / " << TauVisMassZoomEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";

  stringstream DiMuInvMassFakeWeightZoomStackYTitle;
  DiMuInvMassFakeWeightZoomStackYTitle << fixed;
  DiMuInvMassFakeWeightZoomStackYTitle.precision(2);
  DiMuInvMassFakeWeightZoomStackYTitle << "Events / " << DiMuInvMassFakeWeightZoomEstimateFromD_->GetXaxis()->GetBinWidth(3) << " GeV";


  InvMassTauMuMu1PlotPad->cd();
  InvMassTauMuMu1Stack->Draw("hist");
//  InvMassTauMuMu1h125a9_->Scale(1.0/35.0);
//  InvMassTauMuMu1h125a9_->SetLineColor(kGreen+3);
//  InvMassTauMuMu1h125a9_->Draw("HIST SAME");
  InvMassTauMuMu1Stack->GetXaxis()->SetTitle(InvMassTauMuMu1TTAmca_->GetXaxis()->GetTitle() );
  InvMassTauMuMu1Stack->GetXaxis()->SetLabelSize(0.05);
//  InvMassTauMuMu1Stack->GetYaxis()->SetTitle(InvMassTauMuMu1StackYTitle.str().c_str() );
////  InvMassTauMuMu1Stack->GetYaxis()->SetTitleSize(0.21);
//  InvMassTauMuMu1Stack->GetYaxis()->SetLabelSize(0.05);
//  InvMassTauMuMu1Stack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  InvMassTauMuMu2PlotPad->cd();
  InvMassTauMuMu2Stack->Draw("hist");
//  InvMassTauMuMu2h125a9_->Scale(1.0/35.0);
//  InvMassTauMuMu2h125a9_->SetLineColor(kGreen+3);
//  InvMassTauMuMu2h125a9_->Draw("HIST SAME");
  InvMassTauMuMu2Stack->GetXaxis()->SetTitle(InvMassTauMuMu2TTAmca_->GetXaxis()->GetTitle() );
  InvMassTauMuMu2Stack->GetXaxis()->SetLabelSize(0.05);
//  InvMassTauMuMu2Stack->GetYaxis()->SetTitle(InvMassTauMuMu2StackYTitle.str().c_str() );
////  InvMassTauMuMu2Stack->GetYaxis()->SetTitleSize(0.21);
//  InvMassTauMuMu2Stack->GetYaxis()->SetLabelSize(0.05);
//  InvMassTauMuMu2Stack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DiMuInvMassFakeWeightPlotPad->cd();
  DiMuInvMassFakeWeightStack->Draw("hist");
//  DiMuInvMassFakeWeighth125a9_->Scale(1.0/35.0);
//  DiMuInvMassFakeWeighth125a9_->SetLineColor(kGreen+3);
//  DiMuInvMassFakeWeighth125a9_->Draw("HIST SAME");
  DiMuInvMassFakeWeightStack->GetXaxis()->SetTitle(DiMuInvMassFakeWeightTTAmca_->GetXaxis()->GetTitle() );
  DiMuInvMassFakeWeightStack->GetXaxis()->SetLabelSize(0.05);
//  DiMuInvMassFakeWeightStack->GetYaxis()->SetTitle(DiMuInvMassFakeWeightStackYTitle.str().c_str() );
////  DiMuInvMassFakeWeightStack->GetYaxis()->SetTitleSize(0.21);
//  DiMuInvMassFakeWeightStack->GetYaxis()->SetLabelSize(0.05);
//  DiMuInvMassFakeWeightStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DiMuDiTauInvMassFakeWeightPlotPad->cd();
  DiMuDiTauInvMassFakeWeightStack->Draw("hist");
//  DiMuDiTauInvMassFakeWeighth125a9_->Scale(1.0/35.0);
//  DiMuDiTauInvMassFakeWeighth125a9_->SetLineColor(kGreen+3);
//  DiMuDiTauInvMassFakeWeighth125a9_->Draw("HIST SAME");
  DiMuDiTauInvMassFakeWeightStack->GetXaxis()->SetTitle(DiMuDiTauInvMassFakeWeightTTAmca_->GetXaxis()->GetTitle() );
  DiMuDiTauInvMassFakeWeightStack->GetXaxis()->SetLabelSize(0.05);
//  DiMuDiTauInvMassFakeWeightStack->GetYaxis()->SetTitle(DiMuDiTauInvMassFakeWeightStackYTitle.str().c_str() );
////  DiMuDiTauInvMassFakeWeightStack->GetYaxis()->SetTitleSize(0.21);
//  DiMuDiTauInvMassFakeWeightStack->GetYaxis()->SetLabelSize(0.05);
//  DiMuDiTauInvMassFakeWeightStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DiTauInvMassFakeWeightPlotPad->cd();
  DiTauInvMassFakeWeightStack->Draw("hist");
//  DiTauInvMassFakeWeighth125a9_->Scale(1.0/35.0);
//  DiTauInvMassFakeWeighth125a9_->SetLineColor(kGreen+3);
//  DiTauInvMassFakeWeighth125a9_->Draw("HIST SAME");
  DiTauInvMassFakeWeightStack->GetXaxis()->SetTitle(DiTauInvMassFakeWeightTTAmca_->GetXaxis()->GetTitle() );
  DiTauInvMassFakeWeightStack->GetXaxis()->SetLabelSize(0.05);
//  DiTauInvMassFakeWeightStack->GetYaxis()->SetTitle(DiTauInvMassFakeWeightStackYTitle.str().c_str() );
////  DiTauInvMassFakeWeightStack->GetYaxis()->SetTitleSize(0.21);
//  DiTauInvMassFakeWeightStack->GetYaxis()->SetLabelSize(0.05);
//  DiTauInvMassFakeWeightStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  PtMu1FakeWeightPlotPad->cd();
  PtMu1FakeWeightStack->Draw("hist");
//  PtMu1FakeWeighth125a9_->Scale(1.0/35.0);
//  PtMu1FakeWeighth125a9_->SetLineColor(kGreen+3);
//  PtMu1FakeWeighth125a9_->Draw("HIST SAME");
  PtMu1FakeWeightStack->GetXaxis()->SetTitle(PtMu1FakeWeightTTAmca_->GetXaxis()->GetTitle() );
  PtMu1FakeWeightStack->GetXaxis()->SetLabelSize(0.05);
//  PtMu1FakeWeightStack->GetYaxis()->SetTitle(PtMu1FakeWeightStackYTitle.str().c_str() );
////  PtMu1FakeWeightStack->GetYaxis()->SetTitleSize(0.21);
//  PtMu1FakeWeightStack->GetYaxis()->SetLabelSize(0.05);
//  PtMu1FakeWeightStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  PtMu2FakeWeightPlotPad->cd();
  PtMu2FakeWeightStack->Draw("hist");
//  PtMu2FakeWeighth125a9_->Scale(1.0/35.0);
//  PtMu2FakeWeighth125a9_->SetLineColor(kGreen+3);
//  PtMu2FakeWeighth125a9_->Draw("HIST SAME");
  PtMu2FakeWeightStack->GetXaxis()->SetTitle(PtMu2FakeWeightTTAmca_->GetXaxis()->GetTitle() );
  PtMu2FakeWeightStack->GetXaxis()->SetLabelSize(0.05);
//  PtMu2FakeWeightStack->GetYaxis()->SetTitle(PtMu2FakeWeightStackYTitle.str().c_str() );
////  PtMu2FakeWeightStack->GetYaxis()->SetTitleSize(0.21);
//  PtMu2FakeWeightStack->GetYaxis()->SetLabelSize(0.05);
//  PtMu2FakeWeightStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  EtaFakeWeightPlotPad->cd();
  EtaFakeWeightStack->Draw("hist");
//  EtaFakeWeighth125a9_->Scale(1.0/35.0);
//  EtaFakeWeighth125a9_->SetLineColor(kGreen+3);
//  EtaFakeWeighth125a9_->Draw("HIST SAME");
  EtaFakeWeightStack->GetXaxis()->SetTitle(EtaFakeWeightTTAmca_->GetXaxis()->GetTitle() );
  EtaFakeWeightStack->GetXaxis()->SetLabelSize(0.05);
//  EtaFakeWeightStack->GetYaxis()->SetTitle(EtaFakeWeightStackYTitle.str().c_str() );
////  EtaFakeWeightStack->GetYaxis()->SetTitleSize(0.21);
//  EtaFakeWeightStack->GetYaxis()->SetLabelSize(0.05);
//  EtaFakeWeightStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DRFakeWeightPlotPad->cd();
  DRFakeWeightStack->Draw("hist");
//  DRFakeWeighth125a9_->Scale(1.0/35.0);
//  DRFakeWeighth125a9_->SetLineColor(kGreen+3);
//  DRFakeWeighth125a9_->Draw("HIST SAME");
  DRFakeWeightStack->GetXaxis()->SetTitle(DRFakeWeightTTAmca_->GetXaxis()->GetTitle() );
  DRFakeWeightStack->GetXaxis()->SetLabelSize(0.05);
//  DRFakeWeightStack->GetYaxis()->SetTitle(DRFakeWeightStackYTitle.str().c_str() );
////  DRFakeWeightStack->GetYaxis()->SetTitleSize(0.21);
//  DRFakeWeightStack->GetYaxis()->SetLabelSize(0.05);
//  DRFakeWeightStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DRNoWeightingPlotPad->cd();
  DRNoWeightingStack->Draw("hist");
//  DRNoWeightingh125a9_->Scale(1.0/35.0);
//  DRNoWeightingh125a9_->SetLineColor(kGreen+3);
//  DRNoWeightingh125a9_->Draw("HIST SAME");
  DRNoWeightingStack->GetXaxis()->SetTitle(DRNoWeightingTTAmca_->GetXaxis()->GetTitle() );
  DRNoWeightingStack->GetXaxis()->SetLabelSize(0.05);
//  DRNoWeightingStack->GetYaxis()->SetTitle(DRNoWeightingStackYTitle.str().c_str() );
////  DRNoWeightingStack->GetYaxis()->SetTitleSize(0.21);
//  DRNoWeightingStack->GetYaxis()->SetLabelSize(0.05);
//  DRNoWeightingStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DiMuInvMassFakeWeightZoomPlotPad->cd();
  DiMuInvMassFakeWeightZoomStack->Draw("hist");
//  DiMuInvMassFakeWeightZoomh125a9_->Scale(1.0/35.0);
//  DiMuInvMassFakeWeightZoomh125a9_->SetLineColor(kGreen+3);
//  DiMuInvMassFakeWeightZoomh125a9_->Draw("HIST SAME");
  DiMuInvMassFakeWeightZoomStack->GetXaxis()->SetTitle(DiMuInvMassFakeWeightZoomTTAmca_->GetXaxis()->GetTitle() );
  DiMuInvMassFakeWeightZoomStack->GetXaxis()->SetLabelSize(0.05);
//  DiMuInvMassFakeWeightZoomStack->GetYaxis()->SetTitle(DiMuInvMassFakeWeightZoomStackYTitle.str().c_str() );
////  DiMuInvMassFakeWeightZoomStack->GetYaxis()->SetTitleSize(0.21);
//  DiMuInvMassFakeWeightZoomStack->GetYaxis()->SetLabelSize(0.05);
//  DiMuInvMassFakeWeightZoomStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  TauVisMassPlotPad->cd();
  TauVisMassStack->Draw("hist");
//  TauVisMassh125a9_->Scale(1.0/35.0);
//  TauVisMassh125a9_->SetLineColor(kGreen+3);
//  TauVisMassh125a9_->Draw("HIST SAME");
  TauVisMassStack->GetXaxis()->SetTitle(TauVisMassTTAmca_->GetXaxis()->GetTitle() );
  TauVisMassStack->GetXaxis()->SetLabelSize(0.05);
//  TauVisMassStack->GetYaxis()->SetTitle(TauVisMassStackYTitle.str().c_str() );
////  TauVisMassStack->GetYaxis()->SetTitleSize(0.21);
//  TauVisMassStack->GetYaxis()->SetLabelSize(0.05);
//  TauVisMassStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  TauVisMassZoomPlotPad->cd();
  TauVisMassZoomStack->Draw("hist");
//  TauVisMassZoomh125a9_->Scale(1.0/35.0);
//  TauVisMassZoomh125a9_->SetLineColor(kGreen+3);
//  TauVisMassZoomh125a9_->Draw("HIST SAME");
  TauVisMassZoomStack->GetXaxis()->SetTitle(TauVisMassZoomTTAmca_->GetXaxis()->GetTitle() );
  TauVisMassZoomStack->GetXaxis()->SetLabelSize(0.05);
//  TauVisMassZoomStack->GetYaxis()->SetTitle(TauVisMassZoomStackYTitle.str().c_str() );
////  TauVisMassZoomStack->GetYaxis()->SetTitleSize(0.21 );
//  TauVisMassZoomStack->GetYaxis()->SetLabelSize(0.05);
//  TauVisMassZoomStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();

cout << "Stacks Drawn" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting the cms_lumi Styling
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  writeExtraText = true;
  lumi_13TeV = "35.9 fb^{-1}";
  CMS_lumi(InvMassTauMuMu1PlotPad, 4, 11);
  CMS_lumi(InvMassTauMuMu2PlotPad, 4, 11);
  CMS_lumi(DiMuInvMassFakeWeightPlotPad, 4, 11);
  CMS_lumi(DiMuDiTauInvMassFakeWeightPlotPad, 4, 11);
  CMS_lumi(DiTauInvMassFakeWeightPlotPad, 4, 11);
  CMS_lumi(PtMu1FakeWeightPlotPad, 4, 11);
  CMS_lumi(PtMu2FakeWeightPlotPad, 4, 11);
  CMS_lumi(EtaFakeWeightPlotPad, 4, 11);
  CMS_lumi(DRFakeWeightPlotPad, 4, 11);
  CMS_lumi(DRNoWeightingPlotPad, 4, 11);
  CMS_lumi(DiMuInvMassFakeWeightZoomPlotPad, 4, 11);
  CMS_lumi(TauVisMassPlotPad, 4, 11);
  CMS_lumi(TauVisMassZoomPlotPad, 4, 11);

cout << "Cms_lumi run" << endl;

  outFile->cd();
  InvMassTauMuMu1Canvas->cd();
//  InvMassTauMuMu1Stack->SetTitle("Estimate Region B From D  Data");
  InvMassTauMuMu1Stack->GetYaxis()->SetTitle(  InvMassTauMuMu1StackYTitle.str().c_str() );
  InvMassTauMuMu1Stack->GetYaxis()->SetTitleOffset(2);
  InvMassTauMuMu1Stack->Draw("hist");
  CMS_lumi(  InvMassTauMuMu1Canvas, 4, 11);
//  InvMassTauMuMu1Canvas->cd(2);
//  InvMassTauMuMu1Stack->SetTitle("MC in RegionC");
  InvMassTauMuMu1EstimateFromD_->Draw("SAME");
  legend->Draw();
  InvMassTauMuMu1Canvas->Write();

  InvMassTauMuMu2Canvas->cd();
//  InvMassTauMuMu2Stack->SetTitle("Estimate Region B From D  Data");
  InvMassTauMuMu2Stack->GetYaxis()->SetTitle(  InvMassTauMuMu2StackYTitle.str().c_str() );
  InvMassTauMuMu2Stack->GetYaxis()->SetTitleOffset(2);
  InvMassTauMuMu2Stack->Draw("hist");
  CMS_lumi(  InvMassTauMuMu2Canvas, 4, 11);
//  InvMassTauMuMu2Canvas->cd(2);
//  InvMassTauMuMu2Stack->SetTitle("MC in RegionC");
  InvMassTauMuMu2EstimateFromD_->Draw("SAME");
  legend->Draw();
  InvMassTauMuMu2Canvas->Write();

  DiMuInvMassFakeWeightCanvas->cd();
//  DiMuInvMassFakeWeightStack->SetTitle("Estimate Region B From D  Data");
  DiMuInvMassFakeWeightStack->GetYaxis()->SetTitle(  DiMuInvMassFakeWeightStackYTitle.str().c_str() );
  DiMuInvMassFakeWeightStack->GetYaxis()->SetTitleOffset(2);
  DiMuInvMassFakeWeightStack->Draw("hist");
  CMS_lumi(  DiMuInvMassFakeWeightCanvas, 4, 11);
//  DiMuInvMassFakeWeightCanvas->cd(2);
//  DiMuInvMassFakeWeightStack->SetTitle("MC in RegionC");
  DiMuInvMassFakeWeightEstimateFromD_->Draw("SAME");
  legend->Draw();
  DiMuInvMassFakeWeightCanvas->Write();

  DiMuDiTauInvMassFakeWeightCanvas->cd();
//  DiMuDiTauInvMassFakeWeightStack->SetTitle("Estimate Region B From D  Data");
  DiMuDiTauInvMassFakeWeightStack->GetYaxis()->SetTitle(  DiMuDiTauInvMassFakeWeightStackYTitle.str().c_str() );
  DiMuDiTauInvMassFakeWeightStack->GetYaxis()->SetTitleOffset(2);
  DiMuDiTauInvMassFakeWeightStack->Draw("hist");
  CMS_lumi(  DiMuDiTauInvMassFakeWeightCanvas, 4, 11);
//  DiMuDiTauInvMassFakeWeightCanvas->cd(2);
//  DiMuDiTauInvMassFakeWeightStack->SetTitle("MC in RegionC");
  DiMuDiTauInvMassFakeWeightEstimateFromD_->Draw("SAME");
  legend->Draw();
  DiMuDiTauInvMassFakeWeightCanvas->Write();

  DiTauInvMassFakeWeightCanvas->cd();
//  DiTauInvMassFakeWeightStack->SetTitle("Estimate Region B From D  Data");
  DiTauInvMassFakeWeightStack->GetYaxis()->SetTitle(  DiTauInvMassFakeWeightStackYTitle.str().c_str() );
  DiTauInvMassFakeWeightStack->GetYaxis()->SetTitleOffset(2);
  DiTauInvMassFakeWeightStack->Draw("hist");
  CMS_lumi(  DiTauInvMassFakeWeightCanvas, 4, 11);
//  DiTauInvMassFakeWeightCanvas->cd(2);
//  DiTauInvMassFakeWeightStack->SetTitle("MC in RegionC");
  DiTauInvMassFakeWeightEstimateFromD_->Draw("SAME");
  legend->Draw();
  DiTauInvMassFakeWeightCanvas->Write();

  PtMu1FakeWeightCanvas->cd();
//  PtMu1FakeWeightStack->SetTitle("Estimate Region B From D  Data");
  PtMu1FakeWeightStack->GetYaxis()->SetTitle(  PtMu1FakeWeightStackYTitle.str().c_str() );
  PtMu1FakeWeightStack->GetYaxis()->SetTitleOffset(2);
  PtMu1FakeWeightStack->Draw("hist");
  CMS_lumi(  PtMu1FakeWeightCanvas, 4, 11);
//  PtMu1FakeWeightCanvas->cd(2);
//  PtMu1FakeWeightStack->SetTitle("MC in RegionC");
  PtMu1FakeWeightEstimateFromD_->Draw("SAME");
  legend->Draw();
  PtMu1FakeWeightCanvas->Write();

  PtMu2FakeWeightCanvas->cd();
//  PtMu2FakeWeightStack->SetTitle("Estimate Region B From D  Data");
  PtMu2FakeWeightStack->GetYaxis()->SetTitle(  PtMu2FakeWeightStackYTitle.str().c_str() );
  PtMu2FakeWeightStack->GetYaxis()->SetTitleOffset(2);
  PtMu2FakeWeightStack->Draw("hist");
  CMS_lumi(  PtMu2FakeWeightCanvas, 4, 11);
//  PtMu2FakeWeightCanvas->cd(2);
//  PtMu2FakeWeightStack->SetTitle("MC in RegionC");
  PtMu2FakeWeightEstimateFromD_->Draw("SAME");
  legend->Draw();
  PtMu2FakeWeightCanvas->Write();

  EtaFakeWeightCanvas->cd();
//  EtaFakeWeightStack->SetTitle("Estimate Region B From D  Data");
  EtaFakeWeightStack->GetYaxis()->SetTitle(  EtaFakeWeightStackYTitle.str().c_str() );
  EtaFakeWeightStack->GetYaxis()->SetTitleOffset(2);
  EtaFakeWeightStack->Draw("hist");
  CMS_lumi(  EtaFakeWeightCanvas, 4, 11);
//  EtaFakeWeightCanvas->cd(2);
//  EtaFakeWeightStack->SetTitle("MC in RegionC");
  EtaFakeWeightEstimateFromD_->Draw("SAME");
  legend->Draw();
  EtaFakeWeightCanvas->Write();

  DRFakeWeightCanvas->cd();
//  DRFakeWeightStack->SetTitle("Estimate Region B From D  Data");
  DRFakeWeightStack->GetYaxis()->SetTitle(  DRFakeWeightStackYTitle.str().c_str() );
  DRFakeWeightStack->GetYaxis()->SetTitleOffset(2);
  DRFakeWeightStack->Draw("hist");
  CMS_lumi(  DRFakeWeightCanvas, 4, 11);
//  DRFakeWeightCanvas->cd(2);
//  DRFakeWeightStack->SetTitle("MC in RegionC");
  DRFakeWeightEstimateFromD_->Draw("SAME");
  legend->Draw();
  DRFakeWeightCanvas->Write();

  DiMuInvMassFakeWeightZoomCanvas->cd();
//  DiMuInvMassFakeWeightZoomStack->SetTitle("Estimate Region B From D  Data");
  DiMuInvMassFakeWeightZoomStack->GetYaxis()->SetTitle(  DiMuInvMassFakeWeightZoomStackYTitle.str().c_str() );
//  DiMuInvMassFakeWeightZoomStack->GetYaxis()->SetTitleOffset(2);
  DiMuInvMassFakeWeightZoomStack->GetXaxis()->SetTitle("m(#mu_{1},#mu_{2}) GeV");
  DiMuInvMassFakeWeightZoomStack->Draw("hist");
  CMS_lumi(  DiMuInvMassFakeWeightZoomCanvas, 4, 11);
//  DiMuInvMassFakeWeightZoomCanvas->cd(2);
//  DiMuInvMassFakeWeightZoomStack->SetTitle("MC in RegionC");
  DiMuInvMassFakeWeightZoomEstimateFromD_->Draw("SAME");
  legend->Draw();
  DiMuInvMassFakeWeightZoomCanvas->Write();

  TauVisMassCanvas->cd();
//  TauVisMassStack->SetTitle("Estimate Region B From D  Data");
  TauVisMassStack->GetYaxis()->SetTitle(  TauVisMassStackYTitle.str().c_str() );
  TauVisMassStack->GetYaxis()->SetTitleOffset(2);
  TauVisMassStack->Draw("hist");
  CMS_lumi(  TauVisMassCanvas, 4, 11);
//  TauVisMassCanvas->cd(2);
//  TauVisMassStack->SetTitle("MC in RegionC");
  TauVisMassEstimateFromD_->Draw("SAME");
  legend->Draw();
  TauVisMassCanvas->Write();

  TauVisMassZoomCanvas->cd();
//  TauVisMassZoomStack->SetTitle("Estimate Region B From D  Data");
  TauVisMassZoomStack->GetYaxis()->SetTitle(  TauVisMassZoomStackYTitle.str().c_str() );
  TauVisMassZoomStack->GetYaxis()->SetTitleOffset(2);
  TauVisMassZoomStack->Draw("hist");
  CMS_lumi(  TauVisMassZoomCanvas, 4, 11);
//  TauVisMassZoomCanvas->cd(2);
//  TauVisMassZoomStack->SetTitle("MC in RegionC");
  TauVisMassZoomEstimateFromD_->Draw("SAME");
  legend->Draw();
  TauVisMassZoomCanvas->Write();




  outFile->Write();
  outFile->Close();
cout << "end" << endl;

}//rootMacro_BBA_combine
