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

void rootMacro_ABCD()
{

  gStyle->SetOptStat(kFALSE);
  gStyle->SetEndErrorSize(7);

  //Old DMs
  TFile infileTT("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_TTBar_SignalRegion_SEP4_SmallBin.root");
  TFile infileQCD1000toInf("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_QCD_1000toInf_SignalRegion_SEP4_SmallBin.root");
  TFile infileQCD800to1000("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_QCD_800to1000_SignalRegion_SEP4_SmallBin.root");
  TFile infileQCD600to800("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_QCD_600to800_SignalRegion_SEP4_SmallBin.root");
  TFile infileQCD470to600("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_QCD_470to600_SignalRegion_SEP4_SmallBin.root");
  TFile infileQCD300to470("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_QCD_300to470_SignalRegion_SEP4_SmallBin.root");
  TFile infileQCD170to300("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_QCD_170to300_SignalRegion_SEP4_SmallBin.root");
  TFile infileQCD120to170("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_QCD_120to170_SignalRegion_SEP4_SmallBin.root");
  TFile infileQCD80to120("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_QCD_80to120_SignalRegion_SEP4_SmallBin.root");
  TFile infileQCD50to80("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_QCD_50to80_SignalRegion_SEP4_SmallBin.root");
  TFile infileQCD30to50("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_QCD_30to50_SignalRegion_SEP4_SmallBin.root");
  TFile infileQCD20to30("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_QCD_20to30_SignalRegion_SEP4_SmallBin.root");
  TFile infileQCD15to20("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_QCD_15to20_SignalRegion_SEP4_SmallBin.root");
  TFile infileDYH("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_DYHighMass_SignalRegion_SEP4_SmallBin.root");
  TFile infileDYL("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_DYLowMass_SignalRegion_SEP4_SmallBin.root");

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/comb_SignalRegion_SEP4_SmallBin.root", "RECREATE");

  ofstream infoFile;
  infoFile.open ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/SignalRegion_SEP4_SmallBin.txt");


cout << "Files Created" << endl;

  ////////////////
  // TTJets
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasTT = (TCanvas*)infileTT.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasTT = (TCanvas*)infileTT.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasTT = (TCanvas*)infileTT.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasTT = (TCanvas*)infileTT.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasTT = (TCanvas*)infileTT.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasTT = (TCanvas*)infileTT.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasTT = (TCanvas*)infileTT.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasTT = (TCanvas*)infileTT.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasTT = (TCanvas*)infileTT.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasTT = (TCanvas*)infileTT.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasTT = (TCanvas*)infileTT.Get("TauVisMassZoom");

  ////////////////
  // QCD15to20
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("TauVisMassZoom");

  ////////////////
  // QCD20to30
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("TauVisMassZoom");

  ////////////////
  // QCD30to50
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("TauVisMassZoom");


  ////////////////
  // QCD50to80
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("TauVisMassZoom");


  ////////////////
  // QCD80to120
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("TauVisMassZoom");


  ////////////////
  // QCD120to170
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("TauVisMassZoom");


  ////////////////
  // QCD170to300
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("TauVisMassZoom");


  ////////////////
  // QCD300to470
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("TauVisMassZoom");


  ////////////////
  // QCD470to600
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("TauVisMassZoom");


  ////////////////
  // QCD600to800
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("TauVisMassZoom");


  ////////////////
  // QCD800to1000
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("TauVisMassZoom");


  ////////////////
  // QCD1000toInf
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("TauVisMassZoom");


  ////////////////
  // DYH
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasDYH = (TCanvas*)infileDYH.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasDYH = (TCanvas*)infileDYH.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasDYH = (TCanvas*)infileDYH.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasDYH = (TCanvas*)infileDYH.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasDYH = (TCanvas*)infileDYH.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasDYH = (TCanvas*)infileDYH.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasDYH = (TCanvas*)infileDYH.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasDYH = (TCanvas*)infileDYH.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasDYH = (TCanvas*)infileDYH.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasDYH = (TCanvas*)infileDYH.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasDYH = (TCanvas*)infileDYH.Get("TauVisMassZoom");


  ////////////////
  // DYL
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasDYL = (TCanvas*)infileDYL.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasDYL = (TCanvas*)infileDYL.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasDYL = (TCanvas*)infileDYL.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasDYL = (TCanvas*)infileDYL.Get("PtMu1FakeWeight");
  TCanvas *GenWeightsCanvasDYL = (TCanvas*)infileDYL.Get("GenWeights");
  TCanvas *EtaFakeWeightCanvasDYL = (TCanvas*)infileDYL.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasDYL = (TCanvas*)infileDYL.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasDYL = (TCanvas*)infileDYL.Get("InvMassFakeWeightZoom");
  TCanvas *DRFakeWeightZoomCanvasDYL = (TCanvas*)infileDYL.Get("DRFakeWeightZoom");
  TCanvas *PileupWeightsCanvasDYL = (TCanvas*)infileDYL.Get("PileupWeights");
  TCanvas *TauVisMassZoomCanvasDYL = (TCanvas*)infileDYL.Get("TauVisMassZoom");


cout << "Got Canvases" << endl;

  //////////////////////////////
  // Getting the TT Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1TT_ = (TH1F*)InvMassTauMuMu1CanvasTT->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2TT_ = (TH1F*)InvMassTauMuMu2CanvasTT->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightTT_ = (TH1F*)InvMassFakeWeightCanvasTT->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightTT_ = (TH1F*)PtMu1FakeWeightCanvasTT->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsTT_  = (TH1F*)GenWeightsCanvasTT->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightTT_  = (TH1F*)EtaFakeWeightCanvasTT->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightTT_ = (TH1F*)DRFakeWeightCanvasTT->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomTT_     = (TH1F*)InvMassFakeWeightZoomCanvasTT->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomTT_    = (TH1F*)DRFakeWeightZoomCanvasTT->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsTT_    = (TH1F*)PileupWeightsCanvasTT->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomTT_    = (TH1F*)TauVisMassZoomCanvasTT->GetPrimitive("TauVisMassZoom");

  //////////////////////////////
  // Getting the QCD15to20 Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1QCD15to20_ = (TH1F*)InvMassTauMuMu1CanvasQCD15to20->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2QCD15to20_ = (TH1F*)InvMassTauMuMu2CanvasQCD15to20->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightQCD15to20_ = (TH1F*)InvMassFakeWeightCanvasQCD15to20->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightQCD15to20_ = (TH1F*)PtMu1FakeWeightCanvasQCD15to20->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsQCD15to20_  = (TH1F*)GenWeightsCanvasQCD15to20->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightQCD15to20_  = (TH1F*)EtaFakeWeightCanvasQCD15to20->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightQCD15to20_ = (TH1F*)DRFakeWeightCanvasQCD15to20->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomQCD15to20_     = (TH1F*)InvMassFakeWeightZoomCanvasQCD15to20->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomQCD15to20_    = (TH1F*)DRFakeWeightZoomCanvasQCD15to20->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsQCD15to20_    = (TH1F*)PileupWeightsCanvasQCD15to20->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomQCD15to20_    = (TH1F*)TauVisMassZoomCanvasQCD15to20->GetPrimitive("TauVisMassZoom");


  //////////////////////////////
  // Getting the QCD20to30 Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1QCD20to30_ = (TH1F*)InvMassTauMuMu1CanvasQCD20to30->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2QCD20to30_ = (TH1F*)InvMassTauMuMu2CanvasQCD20to30->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightQCD20to30_ = (TH1F*)InvMassFakeWeightCanvasQCD20to30->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightQCD20to30_ = (TH1F*)PtMu1FakeWeightCanvasQCD20to30->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsQCD20to30_  = (TH1F*)GenWeightsCanvasQCD20to30->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightQCD20to30_  = (TH1F*)EtaFakeWeightCanvasQCD20to30->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightQCD20to30_ = (TH1F*)DRFakeWeightCanvasQCD20to30->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomQCD20to30_     = (TH1F*)InvMassFakeWeightZoomCanvasQCD20to30->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomQCD20to30_    = (TH1F*)DRFakeWeightZoomCanvasQCD20to30->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsQCD20to30_    = (TH1F*)PileupWeightsCanvasQCD20to30->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomQCD20to30_    = (TH1F*)TauVisMassZoomCanvasQCD20to30->GetPrimitive("TauVisMassZoom");


  //////////////////////////////
  // Getting the QCD30to50 Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1QCD30to50_ = (TH1F*)InvMassTauMuMu1CanvasQCD30to50->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2QCD30to50_ = (TH1F*)InvMassTauMuMu2CanvasQCD30to50->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightQCD30to50_ = (TH1F*)InvMassFakeWeightCanvasQCD30to50->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightQCD30to50_ = (TH1F*)PtMu1FakeWeightCanvasQCD30to50->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsQCD30to50_  = (TH1F*)GenWeightsCanvasQCD30to50->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightQCD30to50_  = (TH1F*)EtaFakeWeightCanvasQCD30to50->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightQCD30to50_ = (TH1F*)DRFakeWeightCanvasQCD30to50->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomQCD30to50_     = (TH1F*)InvMassFakeWeightZoomCanvasQCD30to50->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomQCD30to50_    = (TH1F*)DRFakeWeightZoomCanvasQCD30to50->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsQCD30to50_    = (TH1F*)PileupWeightsCanvasQCD30to50->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomQCD30to50_    = (TH1F*)TauVisMassZoomCanvasQCD30to50->GetPrimitive("TauVisMassZoom");


  //////////////////////////////
  // Getting the QCD50to80 Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1QCD50to80_ = (TH1F*)InvMassTauMuMu1CanvasQCD50to80->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2QCD50to80_ = (TH1F*)InvMassTauMuMu2CanvasQCD50to80->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightQCD50to80_ = (TH1F*)InvMassFakeWeightCanvasQCD50to80->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightQCD50to80_ = (TH1F*)PtMu1FakeWeightCanvasQCD50to80->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsQCD50to80_  = (TH1F*)GenWeightsCanvasQCD50to80->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightQCD50to80_  = (TH1F*)EtaFakeWeightCanvasQCD50to80->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightQCD50to80_ = (TH1F*)DRFakeWeightCanvasQCD50to80->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomQCD50to80_     = (TH1F*)InvMassFakeWeightZoomCanvasQCD50to80->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomQCD50to80_    = (TH1F*)DRFakeWeightZoomCanvasQCD50to80->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsQCD50to80_    = (TH1F*)PileupWeightsCanvasQCD50to80->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomQCD50to80_    = (TH1F*)TauVisMassZoomCanvasQCD50to80->GetPrimitive("TauVisMassZoom");



  //////////////////////////////
  // Getting the QCD80to120 Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1QCD80to120_ = (TH1F*)InvMassTauMuMu1CanvasQCD80to120->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2QCD80to120_ = (TH1F*)InvMassTauMuMu2CanvasQCD80to120->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightQCD80to120_ = (TH1F*)InvMassFakeWeightCanvasQCD80to120->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightQCD80to120_ = (TH1F*)PtMu1FakeWeightCanvasQCD80to120->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsQCD80to120_  = (TH1F*)GenWeightsCanvasQCD80to120->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightQCD80to120_  = (TH1F*)EtaFakeWeightCanvasQCD80to120->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightQCD80to120_ = (TH1F*)DRFakeWeightCanvasQCD80to120->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomQCD80to120_     = (TH1F*)InvMassFakeWeightZoomCanvasQCD80to120->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomQCD80to120_    = (TH1F*)DRFakeWeightZoomCanvasQCD80to120->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsQCD80to120_    = (TH1F*)PileupWeightsCanvasQCD80to120->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomQCD80to120_    = (TH1F*)TauVisMassZoomCanvasQCD80to120->GetPrimitive("TauVisMassZoom");


  //////////////////////////////
  // Getting the QCD120to170 Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1QCD120to170_ = (TH1F*)InvMassTauMuMu1CanvasQCD120to170->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2QCD120to170_ = (TH1F*)InvMassTauMuMu2CanvasQCD120to170->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightQCD120to170_ = (TH1F*)InvMassFakeWeightCanvasQCD120to170->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightQCD120to170_ = (TH1F*)PtMu1FakeWeightCanvasQCD120to170->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsQCD120to170_  = (TH1F*)GenWeightsCanvasQCD120to170->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightQCD120to170_  = (TH1F*)EtaFakeWeightCanvasQCD120to170->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightQCD120to170_ = (TH1F*)DRFakeWeightCanvasQCD120to170->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomQCD120to170_     = (TH1F*)InvMassFakeWeightZoomCanvasQCD120to170->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomQCD120to170_    = (TH1F*)DRFakeWeightZoomCanvasQCD120to170->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsQCD120to170_    = (TH1F*)PileupWeightsCanvasQCD120to170->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomQCD120to170_    = (TH1F*)TauVisMassZoomCanvasQCD120to170->GetPrimitive("TauVisMassZoom");


  //////////////////////////////
  // Getting the QCD170to300 Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1QCD170to300_ = (TH1F*)InvMassTauMuMu1CanvasQCD170to300->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2QCD170to300_ = (TH1F*)InvMassTauMuMu2CanvasQCD170to300->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightQCD170to300_ = (TH1F*)InvMassFakeWeightCanvasQCD170to300->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightQCD170to300_ = (TH1F*)PtMu1FakeWeightCanvasQCD170to300->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsQCD170to300_  = (TH1F*)GenWeightsCanvasQCD170to300->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightQCD170to300_  = (TH1F*)EtaFakeWeightCanvasQCD170to300->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightQCD170to300_ = (TH1F*)DRFakeWeightCanvasQCD170to300->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomQCD170to300_     = (TH1F*)InvMassFakeWeightZoomCanvasQCD170to300->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomQCD170to300_    = (TH1F*)DRFakeWeightZoomCanvasQCD170to300->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsQCD170to300_    = (TH1F*)PileupWeightsCanvasQCD170to300->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomQCD170to300_    = (TH1F*)TauVisMassZoomCanvasQCD170to300->GetPrimitive("TauVisMassZoom");


  //////////////////////////////
  // Getting the QCD300to470 Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1QCD300to470_ = (TH1F*)InvMassTauMuMu1CanvasQCD300to470->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2QCD300to470_ = (TH1F*)InvMassTauMuMu2CanvasQCD300to470->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightQCD300to470_ = (TH1F*)InvMassFakeWeightCanvasQCD300to470->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightQCD300to470_ = (TH1F*)PtMu1FakeWeightCanvasQCD300to470->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsQCD300to470_  = (TH1F*)GenWeightsCanvasQCD300to470->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightQCD300to470_  = (TH1F*)EtaFakeWeightCanvasQCD300to470->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightQCD300to470_ = (TH1F*)DRFakeWeightCanvasQCD300to470->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomQCD300to470_     = (TH1F*)InvMassFakeWeightZoomCanvasQCD300to470->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomQCD300to470_    = (TH1F*)DRFakeWeightZoomCanvasQCD300to470->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsQCD300to470_    = (TH1F*)PileupWeightsCanvasQCD300to470->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomQCD300to470_    = (TH1F*)TauVisMassZoomCanvasQCD300to470->GetPrimitive("TauVisMassZoom");



  //////////////////////////////
  // Getting the QCD470to600 Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1QCD470to600_ = (TH1F*)InvMassTauMuMu1CanvasQCD470to600->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2QCD470to600_ = (TH1F*)InvMassTauMuMu2CanvasQCD470to600->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightQCD470to600_ = (TH1F*)InvMassFakeWeightCanvasQCD470to600->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightQCD470to600_ = (TH1F*)PtMu1FakeWeightCanvasQCD470to600->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsQCD470to600_  = (TH1F*)GenWeightsCanvasQCD470to600->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightQCD470to600_  = (TH1F*)EtaFakeWeightCanvasQCD470to600->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightQCD470to600_ = (TH1F*)DRFakeWeightCanvasQCD470to600->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomQCD470to600_     = (TH1F*)InvMassFakeWeightZoomCanvasQCD470to600->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomQCD470to600_    = (TH1F*)DRFakeWeightZoomCanvasQCD470to600->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsQCD470to600_    = (TH1F*)PileupWeightsCanvasQCD470to600->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomQCD470to600_    = (TH1F*)TauVisMassZoomCanvasQCD470to600->GetPrimitive("TauVisMassZoom");


  //////////////////////////////
  // Getting the QCD600to800 Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1QCD600to800_ = (TH1F*)InvMassTauMuMu1CanvasQCD600to800->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2QCD600to800_ = (TH1F*)InvMassTauMuMu2CanvasQCD600to800->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightQCD600to800_ = (TH1F*)InvMassFakeWeightCanvasQCD600to800->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightQCD600to800_ = (TH1F*)PtMu1FakeWeightCanvasQCD600to800->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsQCD600to800_  = (TH1F*)GenWeightsCanvasQCD600to800->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightQCD600to800_  = (TH1F*)EtaFakeWeightCanvasQCD600to800->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightQCD600to800_ = (TH1F*)DRFakeWeightCanvasQCD600to800->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomQCD600to800_     = (TH1F*)InvMassFakeWeightZoomCanvasQCD600to800->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomQCD600to800_    = (TH1F*)DRFakeWeightZoomCanvasQCD600to800->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsQCD600to800_    = (TH1F*)PileupWeightsCanvasQCD600to800->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomQCD600to800_    = (TH1F*)TauVisMassZoomCanvasQCD600to800->GetPrimitive("TauVisMassZoom");


  //////////////////////////////
  // Getting the QCD800to1000 Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1QCD800to1000_ = (TH1F*)InvMassTauMuMu1CanvasQCD800to1000->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2QCD800to1000_ = (TH1F*)InvMassTauMuMu2CanvasQCD800to1000->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightQCD800to1000_ = (TH1F*)InvMassFakeWeightCanvasQCD800to1000->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightQCD800to1000_ = (TH1F*)PtMu1FakeWeightCanvasQCD800to1000->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsQCD800to1000_  = (TH1F*)GenWeightsCanvasQCD800to1000->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightQCD800to1000_  = (TH1F*)EtaFakeWeightCanvasQCD800to1000->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightQCD800to1000_ = (TH1F*)DRFakeWeightCanvasQCD800to1000->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomQCD800to1000_     = (TH1F*)InvMassFakeWeightZoomCanvasQCD800to1000->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomQCD800to1000_    = (TH1F*)DRFakeWeightZoomCanvasQCD800to1000->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsQCD800to1000_    = (TH1F*)PileupWeightsCanvasQCD800to1000->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomQCD800to1000_    = (TH1F*)TauVisMassZoomCanvasQCD800to1000->GetPrimitive("TauVisMassZoom");


  //////////////////////////////
  // Getting the QCD1000toInf Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1QCD1000toInf_ = (TH1F*)InvMassTauMuMu1CanvasQCD1000toInf->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2QCD1000toInf_ = (TH1F*)InvMassTauMuMu2CanvasQCD1000toInf->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightQCD1000toInf_ = (TH1F*)InvMassFakeWeightCanvasQCD1000toInf->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightQCD1000toInf_ = (TH1F*)PtMu1FakeWeightCanvasQCD1000toInf->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsQCD1000toInf_  = (TH1F*)GenWeightsCanvasQCD1000toInf->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightQCD1000toInf_  = (TH1F*)EtaFakeWeightCanvasQCD1000toInf->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightQCD1000toInf_ = (TH1F*)DRFakeWeightCanvasQCD1000toInf->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomQCD1000toInf_     = (TH1F*)InvMassFakeWeightZoomCanvasQCD1000toInf->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomQCD1000toInf_    = (TH1F*)DRFakeWeightZoomCanvasQCD1000toInf->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsQCD1000toInf_    = (TH1F*)PileupWeightsCanvasQCD1000toInf->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomQCD1000toInf_    = (TH1F*)TauVisMassZoomCanvasQCD1000toInf->GetPrimitive("TauVisMassZoom");


  //////////////////////////////
  // Getting the DYH Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1DYH_ = (TH1F*)InvMassTauMuMu1CanvasDYH->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2DYH_ = (TH1F*)InvMassTauMuMu2CanvasDYH->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightDYH_ = (TH1F*)InvMassFakeWeightCanvasDYH->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightDYH_ = (TH1F*)PtMu1FakeWeightCanvasDYH->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsDYH_  = (TH1F*)GenWeightsCanvasDYH->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightDYH_  = (TH1F*)EtaFakeWeightCanvasDYH->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightDYH_ = (TH1F*)DRFakeWeightCanvasDYH->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomDYH_     = (TH1F*)InvMassFakeWeightZoomCanvasDYH->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomDYH_    = (TH1F*)DRFakeWeightZoomCanvasDYH->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsDYH_    = (TH1F*)PileupWeightsCanvasDYH->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomDYH_    = (TH1F*)TauVisMassZoomCanvasDYH->GetPrimitive("TauVisMassZoom");


  //////////////////////////////
  // Getting the DYL Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1DYL_ = (TH1F*)InvMassTauMuMu1CanvasDYL->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2DYL_ = (TH1F*)InvMassTauMuMu2CanvasDYL->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightDYL_ = (TH1F*)InvMassFakeWeightCanvasDYL->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightDYL_ = (TH1F*)PtMu1FakeWeightCanvasDYL->GetPrimitive("PtMu1FakeWeight");
  TH1F*  GenWeightsDYL_  = (TH1F*)GenWeightsCanvasDYL->GetPrimitive("GenWeights");
  TH1F*  EtaFakeWeightDYL_  = (TH1F*)EtaFakeWeightCanvasDYL->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightDYL_ = (TH1F*)DRFakeWeightCanvasDYL->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomDYL_     = (TH1F*)InvMassFakeWeightZoomCanvasDYL->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  DRFakeWeightZoomDYL_    = (TH1F*)DRFakeWeightZoomCanvasDYL->GetPrimitive("DRFakeWeightZoom");
  TH1F*  PileupWeightsDYL_    = (TH1F*)PileupWeightsCanvasDYL->GetPrimitive("PileupWeights");
  TH1F*  TauVisMassZoomDYL_    = (TH1F*)TauVisMassZoomCanvasDYL->GetPrimitive("TauVisMassZoom");


cout << "Histograms assigned." << endl; 

  //////////////////////////////
  //  Scaling xsec calculations
  //////////////////////////////
////  double scale_DYH = 1921.8 * 3 * 28452.9 / 104597742.0 ;
//  double scale_DYL = 1861   * 28452.9 /  15916404.0;
//  double scale_TT  = 831.76 * 28452.9 /  38288417.0 ;
//  double scale_QCD1000toInf = 10.4305 * 0.15544 * 28452.9 / 3884666.0 ;
//  double scale_QCD800to1000 = 32.3486 * 0.14552 * 28452.9 / 3854555.0 ;
//  double scale_QCD600to800  = 187.109 * 0.13412 * 28452.9 /  3962231.0 ;
//  double scale_QCD470to600  = 645.528 * 0.12242 * 28452.9 /  3864287.0 ;
//  double scale_QCD300to470  = 7820.25 * 0.10196 * 28452.9 /  7327247.0 ;
//  double scale_QCD170to300  = 117989.0  * 0.07335 * 28452.9 /  7806467.0 ;
//  double scale_QCD120to170  = 469797.0  * 0.05362 * 28452.9 / 7574667.0 ;
//  double scale_QCD80to120   = 2758420.0 * 0.03844 * 28452.9 / 13581013.0 ;
//  double scale_QCD50to80    = 19222500.0 * 0.02276 * 28452.9 /  20383957.0 ;
//  double scale_QCD30to50    = 139803000.0 * 0.01182 * 28452.9 /  28384842.0 ; 
//  double scale_QCD20to30    = 558528000.0 * 0.0053 * 28452.9 /  30892710.0 ; 
//  double scale_QCD15to20    = 1273190000.0 * 0.003 * 28452.9 /  4617630.0 ;

//std::cout << "DYH=" << scale_DYH << "\tnEvents=" << EtaFakeWeightDYH_->GetEntries() << "\nDYL=" << scale_DYL << "\tnEvents=" << EtaFakeWeightDYL_->GetEntries() << "\nscale_TT=" << scale_TT << "\tnEvents=" << EtaFakeWeightTT_->GetEntries() << "\nscale_QCD1000toInf=" << scale_QCD1000toInf << "\tnEvents=" << EtaFakeWeightQCD1000toInf_->GetEntries() << "\nscale_QCD800to1000=" << scale_QCD800to1000 << "\tnEvents=" << EtaFakeWeightQCD800to1000_->GetEntries() << "\nscale_QCD600to800=" << scale_QCD600to800 << "\tnEvents=" << EtaFakeWeightQCD600to800_->GetEntries() << "\nscale_QCD470to600=" << scale_QCD470to600 << "\tnEvents=" << EtaFakeWeightQCD470to600_->GetEntries() << "\nscale_QCD300to470=" << scale_QCD300to470 << "\tnEvents=" << EtaFakeWeightQCD300to470_->GetEntries() << "\nscale_QCD170to300=" << scale_QCD170to300 << "\tnEvents=" << EtaFakeWeightQCD170to300_->GetEntries() << "\nscale_QCD120to170=" << scale_QCD120to170 << "\tnEvents=" << EtaFakeWeightQCD120to170_->GetEntries() << "\nscale_QCD80to120=" << scale_QCD80to120   << "\tnEvents=" << EtaFakeWeightQCD80to120_->GetEntries() << "\nscale_QCD50to80=" << scale_QCD50to80 << "\tnEvents=" << EtaFakeWeightQCD50to80_->GetEntries() << "\nscale_QCD30to50=" << scale_QCD30to50 << "\tnEvents=" << EtaFakeWeightQCD30to50_->GetEntries() << "\nscale_QCD20to30=" << scale_QCD20to30 << "\tnEvents=" << EtaFakeWeightQCD20to30_->GetEntries() << "\nscale_QCD15to20=" << scale_QCD15to20 << "\tnEvents=" << EtaFakeWeightQCD15to20_->GetEntries() << std::endl;
//
/////////////////////////////////////////////
//// Scaling HIstograms that are 
/////////////////////////////////////////////
//  InvMassTauMuMu1DYH_->Scale(scale_DYH);
//  InvMassTauMuMu2DYH_->Scale(scale_DYH);
//  InvMassFakeWeightDYH_->Scale(scale_DYH);
//  PtMu1FakeWeightDYH_->Scale(scale_DYH);
//  GenWeightsDYH_->Scale(scale_DYH);
//  EtaFakeWeightDYH_->Scale(scale_DYH);
//  DRFakeWeightDYH_->Scale(scale_DYH);
//  InvMassFakeWeightDYH_->Scale(scale_DYH);
//  DRFakeWeightZoomDYH_->Scale(scale_DYH);
//  PileupWeightsDYH_->Scale(scale_DYH);
//  TauVisMassZoomDYH_->Scale(scale_DYH);
//
//  InvMassTauMuMu1DYH_->Sumw2();
//  InvMassTauMuMu2DYH_->Sumw2();
//  InvMassFakeWeightDYH_->Sumw2();
//  PtMu1FakeWeightDYH_->Sumw2();
//  GenWeightsDYH_->Sumw2();
//  EtaFakeWeightDYH_->Sumw2();
//  DRFakeWeightDYH_->Sumw2();
//  InvMassFakeWeightDYH_->Sumw2();
//  DRFakeWeightZoomDYH_->Sumw2();
//  PileupWeightsDYH_->Sumw2();
//  TauVisMassZoomDYH_->Sumw2();
//
//  InvMassTauMuMu1DYL_->Scale(scale_DYL);
//  InvMassTauMuMu2DYL_->Scale(scale_DYL);
//  InvMassFakeWeightDYL_->Scale(scale_DYL);
//  PtMu1FakeWeightDYL_->Scale(scale_DYL);
//  GenWeightsDYL_->Scale(scale_DYL);
//  EtaFakeWeightDYL_->Scale(scale_DYL);
//  DRFakeWeightDYL_->Scale(scale_DYL);
//  InvMassFakeWeightDYL_->Scale(scale_DYL);
//  DRFakeWeightZoomDYL_->Scale(scale_DYL);
//  PileupWeightsDYL_->Scale(scale_DYL);
//  TauVisMassZoomDYL_->Scale(scale_DYL);
//
//  InvMassTauMuMu1DYL_->Sumw2();
//  InvMassTauMuMu2DYL_->Sumw2();
//  InvMassFakeWeightDYL_->Sumw2();
//  PtMu1FakeWeightDYL_->Sumw2();
//  GenWeightsDYL_->Sumw2();
//  EtaFakeWeightDYL_->Sumw2();
//  DRFakeWeightDYL_->Sumw2();
//  InvMassFakeWeightDYL_->Sumw2();
//  DRFakeWeightZoomDYL_->Sumw2();
//  PileupWeightsDYL_->Sumw2();
//  TauVisMassZoomDYL_->Sumw2();
//
//  InvMassTauMuMu1TT_->Scale(scale_TT);
//  InvMassTauMuMu2TT_->Scale(scale_TT);
//  InvMassFakeWeightTT_->Scale(scale_TT);
//  PtMu1FakeWeightTT_->Scale(scale_TT);
//  GenWeightsTT_->Scale(scale_TT);
//  EtaFakeWeightTT_->Scale(scale_TT);
//  DRFakeWeightTT_->Scale(scale_TT);
//  InvMassFakeWeightTT_->Scale(scale_TT);
//  DRFakeWeightZoomTT_->Scale(scale_TT);
//  PileupWeightsTT_->Scale(scale_TT);
//  TauVisMassZoomTT_->Scale(scale_TT);
//
//  InvMassTauMuMu1TT_->Sumw2();
//  InvMassTauMuMu2TT_->Sumw2();
//  InvMassFakeWeightTT_->Sumw2();
//  PtMu1FakeWeightTT_->Sumw2();
//  GenWeightsTT_->Sumw2();
//  EtaFakeWeightTT_->Sumw2();
//  DRFakeWeightTT_->Sumw2();
//  InvMassFakeWeightTT_->Sumw2();
//  DRFakeWeightZoomTT_->Sumw2();
//  PileupWeightsTT_->Sumw2();
//  TauVisMassZoomTT_->Sumw2();
//
//  InvMassTauMuMu1QCD1000toInf_->Scale(scale_QCD1000toInf);
//  InvMassTauMuMu2QCD1000toInf_->Scale(scale_QCD1000toInf);
//  InvMassFakeWeightQCD1000toInf_->Scale(scale_QCD1000toInf);
//  PtMu1FakeWeightQCD1000toInf_->Scale(scale_QCD1000toInf);
//  GenWeightsQCD1000toInf_->Scale(scale_QCD1000toInf);
//  EtaFakeWeightQCD1000toInf_->Scale(scale_QCD1000toInf);
//  DRFakeWeightQCD1000toInf_->Scale(scale_QCD1000toInf);
//  InvMassFakeWeightQCD1000toInf_->Scale(scale_QCD1000toInf);
//  DRFakeWeightZoomQCD1000toInf_->Scale(scale_QCD1000toInf);
//  PileupWeightsQCD1000toInf_->Scale(scale_QCD1000toInf);
//  TauVisMassZoomQCD1000toInf_->Scale(scale_QCD1000toInf);
//
//  InvMassTauMuMu1QCD1000toInf_->Sumw2();
//  InvMassTauMuMu2QCD1000toInf_->Sumw2();
//  InvMassFakeWeightQCD1000toInf_->Sumw2();
//  PtMu1FakeWeightQCD1000toInf_->Sumw2();
//  GenWeightsQCD1000toInf_->Sumw2();
//  EtaFakeWeightQCD1000toInf_->Sumw2();
//  DRFakeWeightQCD1000toInf_->Sumw2();
//  InvMassFakeWeightQCD1000toInf_->Sumw2();
//  DRFakeWeightZoomQCD1000toInf_->Sumw2();
//  PileupWeightsQCD1000toInf_->Sumw2();
//  TauVisMassZoomQCD1000toInf_->Sumw2();
//
//  InvMassTauMuMu1QCD120to170_->Scale(scale_QCD120to170);
//  InvMassTauMuMu2QCD120to170_->Scale(scale_QCD120to170);
//  InvMassFakeWeightQCD120to170_->Scale(scale_QCD120to170);
//  PtMu1FakeWeightQCD120to170_->Scale(scale_QCD120to170);
//  GenWeightsQCD120to170_->Scale(scale_QCD120to170);
//  EtaFakeWeightQCD120to170_->Scale(scale_QCD120to170);
//  DRFakeWeightQCD120to170_->Scale(scale_QCD120to170);
//  InvMassFakeWeightQCD120to170_->Scale(scale_QCD120to170);
//  DRFakeWeightZoomQCD120to170_->Scale(scale_QCD120to170);
//  PileupWeightsQCD120to170_->Scale(scale_QCD120to170);
//  TauVisMassZoomQCD120to170_->Scale(scale_QCD120to170);
//
//  InvMassTauMuMu1QCD120to170_->Sumw2();
//  InvMassTauMuMu2QCD120to170_->Sumw2();
//  InvMassFakeWeightQCD120to170_->Sumw2();
//  PtMu1FakeWeightQCD120to170_->Sumw2();
//  GenWeightsQCD120to170_->Sumw2();
//  EtaFakeWeightQCD120to170_->Sumw2();
//  DRFakeWeightQCD120to170_->Sumw2();
//  InvMassFakeWeightQCD120to170_->Sumw2();
//  DRFakeWeightZoomQCD120to170_->Sumw2();
//  PileupWeightsQCD120to170_->Sumw2();
//  TauVisMassZoomQCD120to170_->Sumw2();
//
//  InvMassTauMuMu1QCD15to20_->Scale(scale_QCD15to20);
//  InvMassTauMuMu2QCD15to20_->Scale(scale_QCD15to20);
//  InvMassFakeWeightQCD15to20_->Scale(scale_QCD15to20);
//  PtMu1FakeWeightQCD15to20_->Scale(scale_QCD15to20);
//  GenWeightsQCD15to20_->Scale(scale_QCD15to20);
//  EtaFakeWeightQCD15to20_->Scale(scale_QCD15to20);
//  DRFakeWeightQCD15to20_->Scale(scale_QCD15to20);
//  InvMassFakeWeightQCD15to20_->Scale(scale_QCD15to20);
//  DRFakeWeightZoomQCD15to20_->Scale(scale_QCD15to20);
//  PileupWeightsQCD15to20_->Scale(scale_QCD15to20);
//  TauVisMassZoomQCD15to20_->Scale(scale_QCD15to20);
//
//  InvMassTauMuMu1QCD15to20_->Sumw2();
//  InvMassTauMuMu2QCD15to20_->Sumw2();
//  InvMassFakeWeightQCD15to20_->Sumw2();
//  PtMu1FakeWeightQCD15to20_->Sumw2();
//  GenWeightsQCD15to20_->Sumw2();
//  EtaFakeWeightQCD15to20_->Sumw2();
//  DRFakeWeightQCD15to20_->Sumw2();
//  InvMassFakeWeightQCD15to20_->Sumw2();
//  DRFakeWeightZoomQCD15to20_->Sumw2();
//  PileupWeightsQCD15to20_->Sumw2();
//  TauVisMassZoomQCD15to20_->Sumw2();
//
//  InvMassTauMuMu1QCD170to300_->Scale(scale_QCD170to300);
//  InvMassTauMuMu2QCD170to300_->Scale(scale_QCD170to300);
//  InvMassFakeWeightQCD170to300_->Scale(scale_QCD170to300);
//  PtMu1FakeWeightQCD170to300_->Scale(scale_QCD170to300);
//  GenWeightsQCD170to300_->Scale(scale_QCD170to300);
//  EtaFakeWeightQCD170to300_->Scale(scale_QCD170to300);
//  DRFakeWeightQCD170to300_->Scale(scale_QCD170to300);
//  InvMassFakeWeightQCD170to300_->Scale(scale_QCD170to300);
//  DRFakeWeightZoomQCD170to300_->Scale(scale_QCD170to300);
//  PileupWeightsQCD170to300_->Scale(scale_QCD170to300);
//  TauVisMassZoomQCD170to300_->Scale(scale_QCD170to300);
//
//  InvMassTauMuMu1QCD170to300_->Sumw2();
//  InvMassTauMuMu2QCD170to300_->Sumw2();
//  InvMassFakeWeightQCD170to300_->Sumw2();
//  PtMu1FakeWeightQCD170to300_->Sumw2();
//  GenWeightsQCD170to300_->Sumw2();
//  EtaFakeWeightQCD170to300_->Sumw2();
//  DRFakeWeightQCD170to300_->Sumw2();
//  InvMassFakeWeightQCD170to300_->Sumw2();
//  DRFakeWeightZoomQCD170to300_->Sumw2();
//  PileupWeightsQCD170to300_->Sumw2();
//  TauVisMassZoomQCD170to300_->Sumw2();
//
//  InvMassTauMuMu1QCD20to30_->Scale(scale_QCD20to30);
//  InvMassTauMuMu2QCD20to30_->Scale(scale_QCD20to30);
//  InvMassFakeWeightQCD20to30_->Scale(scale_QCD20to30);
//  PtMu1FakeWeightQCD20to30_->Scale(scale_QCD20to30);
//  GenWeightsQCD20to30_->Scale(scale_QCD20to30);
//  EtaFakeWeightQCD20to30_->Scale(scale_QCD20to30);
//  DRFakeWeightQCD20to30_->Scale(scale_QCD20to30);
//  InvMassFakeWeightQCD20to30_->Scale(scale_QCD20to30);
//  DRFakeWeightZoomQCD20to30_->Scale(scale_QCD20to30);
//  PileupWeightsQCD20to30_->Scale(scale_QCD20to30);
//  TauVisMassZoomQCD20to30_->Scale(scale_QCD20to30);
//
//  InvMassTauMuMu1QCD20to30_->Sumw2();
//  InvMassTauMuMu2QCD20to30_->Sumw2();
//  InvMassFakeWeightQCD20to30_->Sumw2();
//  PtMu1FakeWeightQCD20to30_->Sumw2();
//  GenWeightsQCD20to30_->Sumw2();
//  EtaFakeWeightQCD20to30_->Sumw2();
//  DRFakeWeightQCD20to30_->Sumw2();
//  InvMassFakeWeightQCD20to30_->Sumw2();
//  DRFakeWeightZoomQCD20to30_->Sumw2();
//  PileupWeightsQCD20to30_->Sumw2();
//  TauVisMassZoomQCD20to30_->Sumw2();
//
//  InvMassTauMuMu1QCD300to470_->Scale(scale_QCD300to470);
//  InvMassTauMuMu2QCD300to470_->Scale(scale_QCD300to470);
//  InvMassFakeWeightQCD300to470_->Scale(scale_QCD300to470);
//  PtMu1FakeWeightQCD300to470_->Scale(scale_QCD300to470);
//  GenWeightsQCD300to470_->Scale(scale_QCD300to470);
//  EtaFakeWeightQCD300to470_->Scale(scale_QCD300to470);
//  DRFakeWeightQCD300to470_->Scale(scale_QCD300to470);
//  InvMassFakeWeightQCD300to470_->Scale(scale_QCD300to470);
//  DRFakeWeightZoomQCD300to470_->Scale(scale_QCD300to470);
//  PileupWeightsQCD300to470_->Scale(scale_QCD300to470);
//  TauVisMassZoomQCD300to470_->Scale(scale_QCD300to470);
//
//  InvMassTauMuMu1QCD300to470_->Sumw2();
//  InvMassTauMuMu2QCD300to470_->Sumw2();
//  InvMassFakeWeightQCD300to470_->Sumw2();
//  PtMu1FakeWeightQCD300to470_->Sumw2();
//  GenWeightsQCD300to470_->Sumw2();
//  EtaFakeWeightQCD300to470_->Sumw2();
//  DRFakeWeightQCD300to470_->Sumw2();
//  InvMassFakeWeightQCD300to470_->Sumw2();
//  DRFakeWeightZoomQCD300to470_->Sumw2();
//  PileupWeightsQCD300to470_->Sumw2();
//  TauVisMassZoomQCD300to470_->Sumw2();
//
//  InvMassTauMuMu1QCD30to50_->Scale(scale_QCD30to50);
//  InvMassTauMuMu2QCD30to50_->Scale(scale_QCD30to50);
//  InvMassFakeWeightQCD30to50_->Scale(scale_QCD30to50);
//  PtMu1FakeWeightQCD30to50_->Scale(scale_QCD30to50);
//  GenWeightsQCD30to50_->Scale(scale_QCD30to50);
//  EtaFakeWeightQCD30to50_->Scale(scale_QCD30to50);
//  DRFakeWeightQCD30to50_->Scale(scale_QCD30to50);
//  InvMassFakeWeightQCD30to50_->Scale(scale_QCD30to50);
//  DRFakeWeightZoomQCD30to50_->Scale(scale_QCD30to50);
//  PileupWeightsQCD30to50_->Scale(scale_QCD30to50);
//  TauVisMassZoomQCD30to50_->Scale(scale_QCD30to50);
//
//  InvMassTauMuMu1QCD30to50_->Sumw2();
//  InvMassTauMuMu2QCD30to50_->Sumw2();
//  InvMassFakeWeightQCD30to50_->Sumw2();
//  PtMu1FakeWeightQCD30to50_->Sumw2();
//  GenWeightsQCD30to50_->Sumw2();
//  EtaFakeWeightQCD30to50_->Sumw2();
//  DRFakeWeightQCD30to50_->Sumw2();
//  InvMassFakeWeightQCD30to50_->Sumw2();
//  DRFakeWeightZoomQCD30to50_->Sumw2();
//  PileupWeightsQCD30to50_->Sumw2();
//  TauVisMassZoomQCD30to50_->Sumw2();
//
//  InvMassTauMuMu1QCD470to600_->Scale(scale_QCD470to600);
//  InvMassTauMuMu2QCD470to600_->Scale(scale_QCD470to600);
//  InvMassFakeWeightQCD470to600_->Scale(scale_QCD470to600);
//  PtMu1FakeWeightQCD470to600_->Scale(scale_QCD470to600);
//  GenWeightsQCD470to600_->Scale(scale_QCD470to600);
//  EtaFakeWeightQCD470to600_->Scale(scale_QCD470to600);
//  DRFakeWeightQCD470to600_->Scale(scale_QCD470to600);
//  InvMassFakeWeightQCD470to600_->Scale(scale_QCD470to600);
//  DRFakeWeightZoomQCD470to600_->Scale(scale_QCD470to600);
//  PileupWeightsQCD470to600_->Scale(scale_QCD470to600);
//  TauVisMassZoomQCD470to600_->Scale(scale_QCD470to600);
//
//  InvMassTauMuMu1QCD470to600_->Sumw2();
//  InvMassTauMuMu2QCD470to600_->Sumw2();
//  InvMassFakeWeightQCD470to600_->Sumw2();
//  PtMu1FakeWeightQCD470to600_->Sumw2();
//  GenWeightsQCD470to600_->Sumw2();
//  EtaFakeWeightQCD470to600_->Sumw2();
//  DRFakeWeightQCD470to600_->Sumw2();
//  InvMassFakeWeightQCD470to600_->Sumw2();
//  DRFakeWeightZoomQCD470to600_->Sumw2();
//  PileupWeightsQCD470to600_->Sumw2();
//  TauVisMassZoomQCD470to600_->Sumw2();
//
//  InvMassTauMuMu1QCD50to80_->Scale(scale_QCD50to80);
//  InvMassTauMuMu2QCD50to80_->Scale(scale_QCD50to80);
//  InvMassFakeWeightQCD50to80_->Scale(scale_QCD50to80);
//  PtMu1FakeWeightQCD50to80_->Scale(scale_QCD50to80);
//  GenWeightsQCD50to80_->Scale(scale_QCD50to80);
//  EtaFakeWeightQCD50to80_->Scale(scale_QCD50to80);
//  DRFakeWeightQCD50to80_->Scale(scale_QCD50to80);
//  InvMassFakeWeightQCD50to80_->Scale(scale_QCD50to80);
//  DRFakeWeightZoomQCD50to80_->Scale(scale_QCD50to80);
//  PileupWeightsQCD50to80_->Scale(scale_QCD50to80);
//  TauVisMassZoomQCD50to80_->Scale(scale_QCD50to80);
//
//  InvMassTauMuMu1QCD50to80_->Sumw2();
//  InvMassTauMuMu2QCD50to80_->Sumw2();
//  InvMassFakeWeightQCD50to80_->Sumw2();
//  PtMu1FakeWeightQCD50to80_->Sumw2();
//  GenWeightsQCD50to80_->Sumw2();
//  EtaFakeWeightQCD50to80_->Sumw2();
//  DRFakeWeightQCD50to80_->Sumw2();
//  InvMassFakeWeightQCD50to80_->Sumw2();
//  DRFakeWeightZoomQCD50to80_->Sumw2();
//  PileupWeightsQCD50to80_->Sumw2();
//  TauVisMassZoomQCD50to80_->Sumw2();
//
//  InvMassTauMuMu1QCD600to800_->Scale(scale_QCD600to800);
//  InvMassTauMuMu2QCD600to800_->Scale(scale_QCD600to800);
//  InvMassFakeWeightQCD600to800_->Scale(scale_QCD600to800);
//  PtMu1FakeWeightQCD600to800_->Scale(scale_QCD600to800);
//  GenWeightsQCD600to800_->Scale(scale_QCD600to800);
//  EtaFakeWeightQCD600to800_->Scale(scale_QCD600to800);
//  DRFakeWeightQCD600to800_->Scale(scale_QCD600to800);
//  InvMassFakeWeightQCD600to800_->Scale(scale_QCD600to800);
//  DRFakeWeightZoomQCD600to800_->Scale(scale_QCD600to800);
//  PileupWeightsQCD600to800_->Scale(scale_QCD600to800);
//  TauVisMassZoomQCD600to800_->Scale(scale_QCD600to800);
//
//  InvMassTauMuMu1QCD600to800_->Sumw2();
//  InvMassTauMuMu2QCD600to800_->Sumw2();
//  InvMassFakeWeightQCD600to800_->Sumw2();
//  PtMu1FakeWeightQCD600to800_->Sumw2();
//  GenWeightsQCD600to800_->Sumw2();
//  EtaFakeWeightQCD600to800_->Sumw2();
//  DRFakeWeightQCD600to800_->Sumw2();
//  InvMassFakeWeightQCD600to800_->Sumw2();
//  DRFakeWeightZoomQCD600to800_->Sumw2();
//  PileupWeightsQCD600to800_->Sumw2();
//  TauVisMassZoomQCD600to800_->Sumw2();
//
//  InvMassTauMuMu1QCD800to1000_->Scale(scale_QCD800to1000);
//  InvMassTauMuMu2QCD800to1000_->Scale(scale_QCD800to1000);
//  InvMassFakeWeightQCD800to1000_->Scale(scale_QCD800to1000);
//  PtMu1FakeWeightQCD800to1000_->Scale(scale_QCD800to1000);
//  GenWeightsQCD800to1000_->Scale(scale_QCD800to1000);
//  EtaFakeWeightQCD800to1000_->Scale(scale_QCD800to1000);
//  DRFakeWeightQCD800to1000_->Scale(scale_QCD800to1000);
//  InvMassFakeWeightQCD800to1000_->Scale(scale_QCD800to1000);
//  DRFakeWeightZoomQCD800to1000_->Scale(scale_QCD800to1000);
//  PileupWeightsQCD800to1000_->Scale(scale_QCD800to1000);
//  TauVisMassZoomQCD800to1000_->Scale(scale_QCD800to1000);
//
//  InvMassTauMuMu1QCD800to1000_->Sumw2();
//  InvMassTauMuMu2QCD800to1000_->Sumw2();
//  InvMassFakeWeightQCD800to1000_->Sumw2();
//  PtMu1FakeWeightQCD800to1000_->Sumw2();
//  GenWeightsQCD800to1000_->Sumw2();
//  EtaFakeWeightQCD800to1000_->Sumw2();
//  DRFakeWeightQCD800to1000_->Sumw2();
//  InvMassFakeWeightQCD800to1000_->Sumw2();
//  DRFakeWeightZoomQCD800to1000_->Sumw2();
//  PileupWeightsQCD800to1000_->Sumw2();
//  TauVisMassZoomQCD800to1000_->Sumw2();
//
//  InvMassTauMuMu1QCD80to120_->Scale(scale_QCD80to120);
//  InvMassTauMuMu2QCD80to120_->Scale(scale_QCD80to120);
//  InvMassFakeWeightQCD80to120_->Scale(scale_QCD80to120);
//  PtMu1FakeWeightQCD80to120_->Scale(scale_QCD80to120);
//  GenWeightsQCD80to120_->Scale(scale_QCD80to120);
//  EtaFakeWeightQCD80to120_->Scale(scale_QCD80to120);
//  DRFakeWeightQCD80to120_->Scale(scale_QCD80to120);
//  InvMassFakeWeightQCD80to120_->Scale(scale_QCD80to120);
//  DRFakeWeightZoomQCD80to120_->Scale(scale_QCD80to120);
//  PileupWeightsQCD80to120_->Scale(scale_QCD80to120);
//  TauVisMassZoomQCD80to120_->Scale(scale_QCD80to120);
//
//  InvMassTauMuMu1QCD80to120_->Sumw2();
//  InvMassTauMuMu2QCD80to120_->Sumw2();
//  InvMassFakeWeightQCD80to120_->Sumw2();
//  PtMu1FakeWeightQCD80to120_->Sumw2();
//  GenWeightsQCD80to120_->Sumw2();
//  EtaFakeWeightQCD80to120_->Sumw2();
//  DRFakeWeightQCD80to120_->Sumw2();
//  InvMassFakeWeightQCD80to120_->Sumw2();
//  DRFakeWeightZoomQCD80to120_->Sumw2();
//  PileupWeightsQCD80to120_->Sumw2();
//  TauVisMassZoomQCD80to120_->Sumw2();

/////////////////////////////
// Prepping the output plots
/////////////////////////////
  TCanvas InvMassTauMuMu1Canvas("InvMassTauMuMu1Canvas","",600,600);
  TCanvas InvMassTauMuMu2Canvas("InvMassTauMuMu2Canvas","",600,600);
  TCanvas InvMassFakeWeightCanvas("InvMassFakeWeightCanvas","",600,600);
  TCanvas PtMu1FakeWeightCanvas("PtMu1FakeWeightCanvas","",600,600);
  TCanvas GenWeightsCanvas("GenWeightsCanvas","",600,600);
  TCanvas EtaFakeWeightCanvas("EtaFakeWeightCanvas","",600,600);
  TCanvas DRFakeWeightCanvas("DRFakeWeightCanvas","",600,600);
  TCanvas InvMassFakeWeightZoomCanvas("InvMassFakeWeightZoomCanvas","",600,600);
  TCanvas DRFakeWeightZoomCanvas("DRFakeWeightZoomCanvas","",600,600);
  TCanvas PileupWeightsCanvas("PileupWeightsCanvas","",600,600);
  TCanvas TauVisMassZoomCanvas("TauVisMassZoomCanvas","",600,600);

  InvMassTauMuMu1Canvas.SetGrid(1,1);
  InvMassTauMuMu2Canvas.SetGrid(1,1);
  InvMassFakeWeightCanvas.SetGrid(1,1);
  PtMu1FakeWeightCanvas.SetGrid(1,1);
  GenWeightsCanvas.SetGrid(1,1);
  EtaFakeWeightCanvas.SetGrid(1,1);
  DRFakeWeightCanvas.SetGrid(1,1);
  InvMassFakeWeightZoomCanvas.SetGrid(1,1);
  DRFakeWeightZoomCanvas.SetGrid(1,1);
  PileupWeightsCanvas.SetGrid(1,1);
  TauVisMassZoomCanvas.SetGrid(1,1);

  ////////////////
  // QCD combined
  ////////////////
  TCanvas InvMassTauMuMu1CanvasQCD("InvMassTauMuMu1Canvas","",600,600);
  TCanvas InvMassTauMuMu2CanvasQCD("InvMassTauMuMu2Canvas","",600,600);
  TCanvas InvMassFakeWeightCanvasQCD("InvMassFakeWeightCanvas","",600,600);
  TCanvas PtMu1FakeWeightCanvasQCD("PtMu1FakeWeightCanvas","",600,600);
  TCanvas GenWeightsCanvasQCD("GenWeightsCanvas","",600,600);
  TCanvas EtaFakeWeightCanvasQCD("EtaFakeWeightCanvas","",600,600);
  TCanvas DRFakeWeightCanvasQCD("DRFakeWeightCanvas","",600,600);
  TCanvas InvMassFakeWeightZoomCanvasQCD("InvMassFakeWeightZoomCanvas","",600,600);
  TCanvas DRFakeWeightZoomCanvasQCD("DRFakeWeightZoomCanvas","",600,600);
  TCanvas PileupWeightsCanvasQCD("PileupWeightsCanvas","",600,600);
  TCanvas TauVisMassZoomCanvasQCD("TauVisMassZoomCanvas","",600,600);


  TH1F*  InvMassTauMuMu1QCD_ = new TH1F("InvMassTauMuMu1","", InvMassTauMuMu1QCD15to20_->GetNbinsX(), 0, InvMassTauMuMu1QCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  InvMassTauMuMu2QCD_ = new TH1F("InvMassTauMuMu2","", InvMassTauMuMu2QCD15to20_->GetNbinsX(), 0, InvMassTauMuMu2QCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  InvMassFakeWeightQCD_ = new TH1F("InvMassFakeWeight","", InvMassFakeWeightQCD15to20_->GetNbinsX(), 0, InvMassFakeWeightQCD15to20_->GetXaxis()->GetXmax() ); 
  TH1F*  PtMu1FakeWeightQCD_ = new TH1F("PtMu1FakeWeight","", PtMu1FakeWeightQCD15to20_->GetNbinsX(), 0, PtMu1FakeWeightQCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  GenWeightsQCD_  = new TH1F("GenWeights","", GenWeightsQCD15to20_->GetNbinsX(), 0, GenWeightsQCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  EtaFakeWeightQCD_  = new TH1F("EtaFakeWeight","", EtaFakeWeightQCD15to20_->GetNbinsX(), 0, EtaFakeWeightQCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  DRFakeWeightQCD_ = new TH1F("DRFakeWeight","", DRFakeWeightQCD15to20_->GetNbinsX(), 0, DRFakeWeightQCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  InvMassFakeWeightZoomQCD_     = new TH1F("InvMassFakeWeightZoom","", InvMassFakeWeightZoomQCD15to20_->GetNbinsX(), 0, InvMassFakeWeightZoomQCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  DRFakeWeightZoomQCD_    = new TH1F("DRFakeWeightZoom","", DRFakeWeightZoomQCD15to20_->GetNbinsX(), 0, DRFakeWeightZoomQCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  PileupWeightsQCD_    = new TH1F("PileupWeights","", PileupWeightsQCD15to20_->GetNbinsX(), 0, PileupWeightsQCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  TauVisMassZoomQCD_    = new TH1F("TauVisMassZoom","", TauVisMassZoomQCD15to20_->GetNbinsX(), 0, TauVisMassZoomQCD15to20_->GetXaxis()->GetXmax() );


  InvMassTauMuMu1CanvasQCD.cd();
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD15to20_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD20to30_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD30to50_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD50to80_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD80to120_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD120to170_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD170to300_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD300to470_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD470to600_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD600to800_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD800to1000_);
  InvMassTauMuMu1QCD_->Add(InvMassTauMuMu1QCD1000toInf_);

  InvMassTauMuMu2CanvasQCD.cd();
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD15to20_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD20to30_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD30to50_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD50to80_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD80to120_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD120to170_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD170to300_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD300to470_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD470to600_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD600to800_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD800to1000_);
  InvMassTauMuMu2QCD_->Add(InvMassTauMuMu2QCD1000toInf_);

  InvMassFakeWeightCanvasQCD.cd();
  InvMassFakeWeightQCD_->Add(InvMassFakeWeightQCD15to20_);
  InvMassFakeWeightQCD_->Add(InvMassFakeWeightQCD20to30_);
  InvMassFakeWeightQCD_->Add(InvMassFakeWeightQCD30to50_);
  InvMassFakeWeightQCD_->Add(InvMassFakeWeightQCD50to80_);
  InvMassFakeWeightQCD_->Add(InvMassFakeWeightQCD80to120_);
  InvMassFakeWeightQCD_->Add(InvMassFakeWeightQCD120to170_);
  InvMassFakeWeightQCD_->Add(InvMassFakeWeightQCD170to300_);
  InvMassFakeWeightQCD_->Add(InvMassFakeWeightQCD300to470_);
  InvMassFakeWeightQCD_->Add(InvMassFakeWeightQCD470to600_);
  InvMassFakeWeightQCD_->Add(InvMassFakeWeightQCD600to800_);
  InvMassFakeWeightQCD_->Add(InvMassFakeWeightQCD800to1000_);
  InvMassFakeWeightQCD_->Add(InvMassFakeWeightQCD1000toInf_);

  PtMu1FakeWeightCanvasQCD.cd();
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD15to20_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD20to30_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD30to50_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD50to80_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD80to120_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD120to170_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD170to300_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD300to470_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD470to600_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD600to800_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD800to1000_);
  PtMu1FakeWeightQCD_->Add(PtMu1FakeWeightQCD1000toInf_);

  GenWeightsCanvasQCD.cd();
  GenWeightsQCD_->Add(GenWeightsQCD15to20_);
  GenWeightsQCD_->Add(GenWeightsQCD20to30_);
  GenWeightsQCD_->Add(GenWeightsQCD30to50_);
  GenWeightsQCD_->Add(GenWeightsQCD50to80_);
  GenWeightsQCD_->Add(GenWeightsQCD80to120_);
  GenWeightsQCD_->Add(GenWeightsQCD120to170_);
  GenWeightsQCD_->Add(GenWeightsQCD170to300_);
  GenWeightsQCD_->Add(GenWeightsQCD300to470_);
  GenWeightsQCD_->Add(GenWeightsQCD470to600_);
  GenWeightsQCD_->Add(GenWeightsQCD600to800_);
  GenWeightsQCD_->Add(GenWeightsQCD800to1000_);
  GenWeightsQCD_->Add(GenWeightsQCD1000toInf_);

  EtaFakeWeightCanvasQCD.cd();
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD15to20_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD20to30_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD30to50_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD50to80_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD80to120_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD120to170_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD170to300_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD300to470_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD470to600_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD600to800_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD800to1000_);
  EtaFakeWeightQCD_->Add(EtaFakeWeightQCD1000toInf_);


  DRFakeWeightCanvasQCD.cd();
  DRFakeWeightQCD_->Add(DRFakeWeightQCD15to20_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD20to30_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD30to50_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD50to80_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD80to120_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD120to170_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD170to300_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD300to470_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD470to600_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD600to800_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD800to1000_);
  DRFakeWeightQCD_->Add(DRFakeWeightQCD1000toInf_);

  InvMassFakeWeightZoomCanvasQCD.cd();
  InvMassFakeWeightZoomQCD_->Add(InvMassFakeWeightZoomQCD15to20_);
  InvMassFakeWeightZoomQCD_->Add(InvMassFakeWeightZoomQCD20to30_);
  InvMassFakeWeightZoomQCD_->Add(InvMassFakeWeightZoomQCD30to50_);
  InvMassFakeWeightZoomQCD_->Add(InvMassFakeWeightZoomQCD50to80_);
  InvMassFakeWeightZoomQCD_->Add(InvMassFakeWeightZoomQCD80to120_);
  InvMassFakeWeightZoomQCD_->Add(InvMassFakeWeightZoomQCD120to170_);
  InvMassFakeWeightZoomQCD_->Add(InvMassFakeWeightZoomQCD170to300_);
  InvMassFakeWeightZoomQCD_->Add(InvMassFakeWeightZoomQCD300to470_);
  InvMassFakeWeightZoomQCD_->Add(InvMassFakeWeightZoomQCD470to600_);
  InvMassFakeWeightZoomQCD_->Add(InvMassFakeWeightZoomQCD600to800_);
  InvMassFakeWeightZoomQCD_->Add(InvMassFakeWeightZoomQCD800to1000_);
  InvMassFakeWeightZoomQCD_->Add(InvMassFakeWeightZoomQCD1000toInf_);

  DRFakeWeightZoomCanvasQCD.cd();
  DRFakeWeightZoomQCD_->Add(DRFakeWeightZoomQCD15to20_);
  DRFakeWeightZoomQCD_->Add(DRFakeWeightZoomQCD20to30_);
  DRFakeWeightZoomQCD_->Add(DRFakeWeightZoomQCD30to50_);
  DRFakeWeightZoomQCD_->Add(DRFakeWeightZoomQCD50to80_);
  DRFakeWeightZoomQCD_->Add(DRFakeWeightZoomQCD80to120_);
  DRFakeWeightZoomQCD_->Add(DRFakeWeightZoomQCD120to170_);
  DRFakeWeightZoomQCD_->Add(DRFakeWeightZoomQCD170to300_);
  DRFakeWeightZoomQCD_->Add(DRFakeWeightZoomQCD300to470_);
  DRFakeWeightZoomQCD_->Add(DRFakeWeightZoomQCD470to600_);
  DRFakeWeightZoomQCD_->Add(DRFakeWeightZoomQCD600to800_);
  DRFakeWeightZoomQCD_->Add(DRFakeWeightZoomQCD800to1000_);
  DRFakeWeightZoomQCD_->Add(DRFakeWeightZoomQCD1000toInf_);

  PileupWeightsCanvasQCD.cd();
  PileupWeightsQCD_->Add(PileupWeightsQCD15to20_);
  PileupWeightsQCD_->Add(PileupWeightsQCD20to30_);
  PileupWeightsQCD_->Add(PileupWeightsQCD30to50_);
  PileupWeightsQCD_->Add(PileupWeightsQCD50to80_);
  PileupWeightsQCD_->Add(PileupWeightsQCD80to120_);
  PileupWeightsQCD_->Add(PileupWeightsQCD120to170_);
  PileupWeightsQCD_->Add(PileupWeightsQCD170to300_);
  PileupWeightsQCD_->Add(PileupWeightsQCD300to470_);
  PileupWeightsQCD_->Add(PileupWeightsQCD470to600_);
  PileupWeightsQCD_->Add(PileupWeightsQCD600to800_);
  PileupWeightsQCD_->Add(PileupWeightsQCD800to1000_);
  PileupWeightsQCD_->Add(PileupWeightsQCD1000toInf_);

  TauVisMassZoomCanvasQCD.cd();
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD15to20_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD20to30_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD30to50_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD50to80_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD80to120_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD120to170_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD170to300_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD300to470_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD470to600_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD600to800_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD800to1000_);
  TauVisMassZoomQCD_->Add(TauVisMassZoomQCD1000toInf_);


  // Adding all the background together
  InvMassTauMuMu1TT_->Add(InvMassTauMuMu1DYH_);
  InvMassTauMuMu1TT_->Add(InvMassTauMuMu1DYL_);
  InvMassTauMuMu1TT_->Add(InvMassTauMuMu1QCD_);
  
  InvMassTauMuMu2TT_->Add(InvMassTauMuMu2DYH_);
  InvMassTauMuMu2TT_->Add(InvMassTauMuMu2DYL_);
  InvMassTauMuMu2TT_->Add(InvMassTauMuMu2QCD_);
  
  InvMassFakeWeightTT_->Add(InvMassFakeWeightDYH_);
  InvMassFakeWeightTT_->Add(InvMassFakeWeightDYL_);
  InvMassFakeWeightTT_->Add(InvMassFakeWeightQCD_);
  
  PtMu1FakeWeightTT_->Add(PtMu1FakeWeightDYH_);
  PtMu1FakeWeightTT_->Add(PtMu1FakeWeightDYL_);
  PtMu1FakeWeightTT_->Add(PtMu1FakeWeightQCD_);
  
  GenWeightsTT_->Add(GenWeightsDYH_);
  GenWeightsTT_->Add(GenWeightsDYL_);
  GenWeightsTT_->Add(GenWeightsQCD_);
  
  EtaFakeWeightTT_->Add(EtaFakeWeightDYH_);
  EtaFakeWeightTT_->Add(EtaFakeWeightDYL_);
  EtaFakeWeightTT_->Add(EtaFakeWeightQCD_);
  
  DRFakeWeightTT_->Add(DRFakeWeightDYH_);
  DRFakeWeightTT_->Add(DRFakeWeightDYL_);
  DRFakeWeightTT_->Add(DRFakeWeightQCD_);
  
  InvMassFakeWeightZoomTT_->Add(InvMassFakeWeightZoomDYH_);
  InvMassFakeWeightZoomTT_->Add(InvMassFakeWeightZoomDYL_);
  InvMassFakeWeightZoomTT_->Add(InvMassFakeWeightZoomQCD_);
  
  DRFakeWeightZoomTT_->Add(DRFakeWeightZoomDYH_);
  DRFakeWeightZoomTT_->Add(DRFakeWeightZoomDYL_);
  DRFakeWeightZoomTT_->Add(DRFakeWeightZoomQCD_);
  
  PileupWeightsTT_->Add(PileupWeightsDYH_);
  PileupWeightsTT_->Add(PileupWeightsDYL_);
  PileupWeightsTT_->Add(PileupWeightsQCD_);
  
  TauVisMassZoomTT_->Add(TauVisMassZoomDYH_);
  TauVisMassZoomTT_->Add(TauVisMassZoomDYL_);
  TauVisMassZoomTT_->Add(TauVisMassZoomQCD_);

  //Drawing all of the Overlaid Lepton Matched HIstograms
  InvMassTauMuMu1Canvas.cd();
  InvMassTauMuMu1TT_->Draw();
  
  InvMassTauMuMu2Canvas.cd();
  InvMassTauMuMu2TT_->Draw();

  InvMassFakeWeightCanvas.cd();
  InvMassFakeWeightTT_->Draw();

  PtMu1FakeWeightCanvas.cd();
  PtMu1FakeWeightTT_->Draw();

  GenWeightsCanvas.cd();
  GenWeightsTT_->Draw();

  EtaFakeWeightCanvas.cd();
  EtaFakeWeightTT_->Draw();

  DRFakeWeightCanvas.cd();
  DRFakeWeightTT_->Draw();

  InvMassFakeWeightZoomCanvas.cd();
  InvMassFakeWeightZoomTT_->Draw();

  DRFakeWeightZoomCanvas.cd();
  DRFakeWeightZoomTT_->Draw();

  PileupWeightsCanvas.cd();
  PileupWeightsTT_->Draw();

  TauVisMassZoomCanvas.cd();
  TauVisMassZoomTT_->Draw();


//////////////////////////////////
// Setting the Titles for Clarity
//////////////////////////////////
  InvMassTauMuMu1Canvas.SetTitle("SignalRegion");
  InvMassTauMuMu2Canvas.SetTitle("SignalRegion");
  InvMassFakeWeightCanvas.SetTitle("SignalRegion");
  PtMu1FakeWeightCanvas.SetTitle("SignalRegion");
  GenWeightsCanvas.SetTitle("SignalRegion");
  EtaFakeWeightCanvas.SetTitle("SignalRegion");
  DRFakeWeightCanvas.SetTitle("SignalRegion");
  InvMassFakeWeightZoomCanvas.SetTitle("SignalRegion");
  DRFakeWeightZoomCanvas.SetTitle("SignalRegion");
  PileupWeightsCanvas.SetTitle("SignalRegion");
  TauVisMassZoomCanvas.SetTitle("SignalRegion");

cout << "Histograms Drawn" << endl;

  outFile->cd();

  InvMassTauMuMu1Canvas.Write();
  InvMassTauMuMu2Canvas.Write();
  InvMassFakeWeightCanvas.Write();
  PtMu1FakeWeightCanvas.Write();
  GenWeightsCanvas.Write();
  EtaFakeWeightCanvas.Write();
  DRFakeWeightCanvas.Write();
  InvMassFakeWeightZoomCanvas.Write();
  DRFakeWeightZoomCanvas.Write();
  PileupWeightsCanvas.Write();
  TauVisMassZoomCanvas.Write();

  outFile->Write();
  outFile->Close();
cout << "end" << endl;

}//rootMacro_BBA_combine
