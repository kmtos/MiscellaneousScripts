ZZ#include <string.h>
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
  TFile infileTT("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_TTBar_SignalRegion_MAR22.root");
  TFile infileQCD1000toInf("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_QCD_1000toInf_SignalRegion_MAR22.root");
  TFile infileQCD800to1000("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_QCD_800to1000_SignalRegion_MAR22.root");
  TFile infileQCD600to800("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_QCD_600to800_SignalRegion_MAR22.root");
  TFile infileQCD470to600("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_QCD_470to600_SignalRegion_MAR22.root");
  TFile infileQCD300to470("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_QCD_300to470_SignalRegion_MAR22.root");
  TFile infileQCD170to300("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_QCD_170to300_SignalRegion_MAR22.root");
  TFile infileQCD120to170("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_QCD_120to170_SignalRegion_MAR22.root");
  TFile infileQCD80to120("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_QCD_80to120_SignalRegion_MAR22.root");
  TFile infileQCD50to80("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_QCD_50to80_SignalRegion_MAR22.root");
  TFile infileQCD30to50("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_QCD_30to50_SignalRegion_MAR22.root");
  TFile infileQCD20to30("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_QCD_20to30_SignalRegion_MAR22.root");
  TFile infileQCD15to20("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_QCD_15to20_SignalRegion_MAR22.root");
  TFile infileDYH("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_DYHighMass_SignalRegion_MAR22.root");
  TFile infileDYL("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_DYLowMass_SignalRegion_MAR22.root");

  TFile infileH125a19("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_SignalH125a19_SignalRegion_MAR22.root");
  TFile infileH125a9("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_SignalH125a9_SignalRegion_MAR22.root");
  TFile infileH125a5("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_SignalH125a5_SignalRegion_MAR22.root");
  TFile infileH750a9("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MassDiTau/FINAL_SignalH750a9_SignalRegion_MAR22.root");

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/comb_SignalRegion_MAR22.root", "RECREATE");

  ofstream infoFile;
  infoFile.open ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion_MAR22.txt");


cout << "Files Created" << endl;

  ////////////////
  // TTJets
  ////////////////
  TCanvas *TauMuTauHaddRCanvasTT = (TCanvas*)infileTT.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasTT = (TCanvas*)infileTT.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasTT = (TCanvas*)infileTT.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasTT = (TCanvas*)infileTT.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasTT = (TCanvas*)infileTT.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasTT = (TCanvas*)infileTT.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasTT = (TCanvas*)infileTT.Get("PCSVBDisc");
  TCanvas *SumHTCanvasTT = (TCanvas*)infileTT.Get("SumHT");
  TCanvas *IsoRawCanvasTT = (TCanvas*)infileTT.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasTT = (TCanvas*)infileTT.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasTT = (TCanvas*)infileTT.Get("IsoRawCutBased");
  TCanvas *NEventsCutsCanvasTT = (TCanvas*)infileTT.Get("NEventsCuts");

  ////////////////
  // QCD15to20
  ////////////////
  TCanvas *TauMuTauHaddRCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("PCSVBDisc");
  TCanvas *SumHTCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("SumHT");
  TCanvas *IsoRawCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasQCD15to20 = (TCanvas*)infileTT.Get("IsoRawCutBased");
  TCanvas *NEventsCutsCanvasQCD15to20 = (TCanvas*)infileQCD15to20.Get("NEventsCuts");

  ////////////////
  // QCD20to30
  ////////////////
  TCanvas *TauMuTauHaddRCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("PCSVBDisc");
  TCanvas *SumHTCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("SumHT");
  TCanvas *IsoRawCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasQCD20to30 = (TCanvas*)infileTT.Get("IsoRawCutBased");
  TCanvas *NEventsCutsCanvasQCD20to30 = (TCanvas*)infileQCD20to30.Get("NEventsCuts");

  ////////////////
  // QCD30to50
  ////////////////
  TCanvas *TauMuTauHaddRCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("PCSVBDisc");
  TCanvas *SumHTCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("SumHT");
  TCanvas *IsoRawCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasQCD30to50 = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasQCD30to50 = (TCanvas*)infileQCD30to50.Get("NEventsCuts");

  ////////////////
  // QCD50to80
  ////////////////
  TCanvas *TauMuTauHaddRCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("PCSVBDisc");
  TCanvas *SumHTCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("SumHT");
  TCanvas *IsoRawCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasQCD50to80 = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasQCD50to80 = (TCanvas*)infileQCD50to80.Get("NEventsCuts");

  ////////////////
  // QCD80to120
  ////////////////
  TCanvas *TauMuTauHaddRCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("PCSVBDisc");
  TCanvas *SumHTCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("SumHT");
  TCanvas *IsoRawCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasQCD80to120 = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasQCD80to120 = (TCanvas*)infileQCD80to120.Get("NEventsCuts");

  ////////////////
  // QCD120to170
  ////////////////
  TCanvas *TauMuTauHaddRCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("PCSVBDisc");
  TCanvas *SumHTCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("SumHT");
  TCanvas *IsoRawCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasQCD120to170 = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasQCD120to170 = (TCanvas*)infileQCD120to170.Get("NEventsCuts");

  ////////////////
  // QCD170to300
  ////////////////
  TCanvas *TauMuTauHaddRCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("PCSVBDisc");
  TCanvas *SumHTCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("SumHT");
  TCanvas *IsoRawCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasQCD170to300 = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasQCD170to300 = (TCanvas*)infileQCD170to300.Get("NEventsCuts");

  ////////////////
  // QCD300to470
  ////////////////
  TCanvas *TauMuTauHaddRCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("PCSVBDisc");
  TCanvas *SumHTCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("SumHT");
  TCanvas *IsoRawCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasQCD300to470 = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasQCD300to470 = (TCanvas*)infileQCD300to470.Get("NEventsCuts");

  ////////////////
  // QCD470to600
  ////////////////
  TCanvas *TauMuTauHaddRCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("PCSVBDisc");
  TCanvas *SumHTCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("SumHT");
  TCanvas *IsoRawCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasQCD470to600 = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasQCD470to600 = (TCanvas*)infileQCD470to600.Get("NEventsCuts");

  ////////////////
  // QCD600to800
  ////////////////
  TCanvas *TauMuTauHaddRCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("PCSVBDisc");
  TCanvas *SumHTCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("SumHT");
  TCanvas *IsoRawCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasQCD600to800 = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasQCD600to800 = (TCanvas*)infileQCD600to800.Get("NEventsCuts");

  ////////////////
  // QCD800to1000
  ////////////////
  TCanvas *TauMuTauHaddRCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("PCSVBDisc");
  TCanvas *SumHTCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("SumHT");
  TCanvas *IsoRawCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasQCD800to1000 = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasQCD800to1000 = (TCanvas*)infileQCD800to1000.Get("NEventsCuts");

  ////////////////
  // QCD1000toInf
  ////////////////
  TCanvas *TauMuTauHaddRCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("PCSVBDisc");
  TCanvas *SumHTCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("SumHT");
  TCanvas *IsoRawCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasQCD1000toInf = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasQCD1000toInf = (TCanvas*)infileQCD1000toInf.Get("NEventsCuts");

  ////////////////
  // DYH
  ////////////////
  TCanvas *TauMuTauHaddRCanvasDYH = (TCanvas*)infileDYH.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasDYH = (TCanvas*)infileDYH.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasDYH = (TCanvas*)infileDYH.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasDYH = (TCanvas*)infileDYH.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasDYH = (TCanvas*)infileDYH.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasDYH = (TCanvas*)infileDYH.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasDYH = (TCanvas*)infileDYH.Get("PCSVBDisc");
  TCanvas *SumHTCanvasDYH = (TCanvas*)infileDYH.Get("SumHT");
  TCanvas *IsoRawCanvasDYH = (TCanvas*)infileDYH.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasDYH = (TCanvas*)infileDYH.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasDYH = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasDYH = (TCanvas*)infileDYH.Get("NEventsCuts");

  ////////////////
  // DYL
  ////////////////
  TCanvas *TauMuTauHaddRCanvasDYL = (TCanvas*)infileDYL.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasDYL = (TCanvas*)infileDYL.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasDYL = (TCanvas*)infileDYL.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasDYL = (TCanvas*)infileDYL.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasDYL = (TCanvas*)infileDYL.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasDYL = (TCanvas*)infileDYL.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasDYL = (TCanvas*)infileDYL.Get("PCSVBDisc");
  TCanvas *SumHTCanvasDYL = (TCanvas*)infileDYL.Get("SumHT");
  TCanvas *IsoRawCanvasDYL = (TCanvas*)infileDYL.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasDYL = (TCanvas*)infileDYL.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasDYL = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasDYL = (TCanvas*)infileDYL.Get("NEventsCuts");

  ////////////////
  // H125a19
  ////////////////
  TCanvas *TauMuTauHaddRCanvasH125a19 = (TCanvas*)infileH125a19.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasH125a19 = (TCanvas*)infileH125a19.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasH125a19 = (TCanvas*)infileH125a19.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasH125a19 = (TCanvas*)infileH125a19.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasH125a19 = (TCanvas*)infileH125a19.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasH125a19 = (TCanvas*)infileH125a19.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasH125a19 = (TCanvas*)infileH125a19.Get("PCSVBDisc");
  TCanvas *SumHTCanvasH125a19 = (TCanvas*)infileH125a19.Get("SumHT");
  TCanvas *IsoRawCanvasH125a19 = (TCanvas*)infileH125a19.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasH125a19 = (TCanvas*)infileH125a19.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasH125a19 = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasH125a19 = (TCanvas*)infileH125a19.Get("NEventsCuts");

  ////////////////
  // H125a9
  ////////////////
  TCanvas *TauMuTauHaddRCanvasH125a9 = (TCanvas*)infileH125a9.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasH125a9 = (TCanvas*)infileH125a9.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasH125a9 = (TCanvas*)infileH125a9.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasH125a9 = (TCanvas*)infileH125a9.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasH125a9 = (TCanvas*)infileH125a9.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasH125a9 = (TCanvas*)infileH125a9.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasH125a9 = (TCanvas*)infileH125a9.Get("PCSVBDisc");
  TCanvas *SumHTCanvasH125a9 = (TCanvas*)infileH125a9.Get("SumHT");
  TCanvas *IsoRawCanvasH125a9 = (TCanvas*)infileH125a9.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasH125a9 = (TCanvas*)infileH125a9.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasH125a9 = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasH125a9 = (TCanvas*)infileH125a9.Get("NEventsCuts");

  ////////////////
  // H125a5
  ////////////////
  TCanvas *TauMuTauHaddRCanvasH125a5 = (TCanvas*)infileH125a5.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasH125a5 = (TCanvas*)infileH125a5.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasH125a5 = (TCanvas*)infileH125a5.Get("MassDiTau");
  TCanvas *PtTauMuCanvasH125a5 = (TCanvas*)infileH125a5.Get("PtTauMu");
  TCanvas *PtOverMassMu1Mu2CanvasH125a5 = (TCanvas*)infileH125a5.Get("PtOverMassMu1Mu2");
  TCanvas *PtMu1Mu2CanvasH125a5 = (TCanvas*)infileH125a5.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasH125a5 = (TCanvas*)infileH125a5.Get("PCSVBDisc");
  TCanvas *SumHTCanvasH125a5 = (TCanvas*)infileH125a5.Get("SumHT");
  TCanvas *IsoRawCanvasH125a5 = (TCanvas*)infileH125a9.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasH125a5 = (TCanvas*)infileH125a5.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasH125a5 = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasH125a5 = (TCanvas*)infileH125a5.Get("NEventsCuts");

  ////////////////
  // H750a9
  ////////////////
  TCanvas *TauMuTauHaddRCanvasH750a9 = (TCanvas*)infileH750a9.Get("TauMuTauHaddR");
  TCanvas *MassDiMuRECOCanvasH750a9 = (TCanvas*)infileH750a9.Get("MassDiMuRECO");
  TCanvas *MassDiTauCanvasH750a9 = (TCanvas*)infileH750a9.Get("MassDiTau");
  TCanvas *PtOverMassMu1Mu2CanvasH750a9 = (TCanvas*)infileH750a9.Get("PtOverMassMu1Mu2");
  TCanvas *PtTauMuCanvasH750a9 = (TCanvas*)infileH750a9.Get("PtTauMu");
  TCanvas *PtMu1Mu2CanvasH750a9 = (TCanvas*)infileH750a9.Get("PtMu1Mu2");
  TCanvas *PCSVBDiscCanvasH750a9 = (TCanvas*)infileH750a9.Get("PCSVBDisc");
  TCanvas *SumHTCanvasH750a9 = (TCanvas*)infileH750a9.Get("SumHT");
  TCanvas *IsoRawCanvasH750a9 = (TCanvas*)infileH750a9.Get("IsoRaw");
  TCanvas *RelIsoRawCanvasH750a9 = (TCanvas*)infileH750a9.Get("RelIsoRaw");
  TCanvas *IsoRawCutBasedCanvasH750a9 = (TCanvas*)infileTT.Get("IsoRawCutBased");

  TCanvas *NEventsCutsCanvasH750a9 = (TCanvas*)infileH750a9.Get("NEventsCuts");

cout << "Got Canvases" << endl;

  //////////////////////////////
  // Getting the TT Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRTT_ = (TH1F*)TauMuTauHaddRCanvasTT->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOTT_ = (TH1F*)MassDiMuRECOCanvasTT->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauTT_ = (TH1F*)MassDiTauCanvasTT->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2TT_ = (TH1F*)PtOverMassMu1Mu2CanvasTT->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuTT_  = (TH1F*)PtTauMuCanvasTT->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2TT_  = (TH1F*)PtMu1Mu2CanvasTT->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscTT_ = (TH1F*)PCSVBDiscCanvasTT->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTTT_     = (TH1F*)SumHTCanvasTT->GetPrimitive("SumHT");
  TH1F*  IsoRawTT_    = (TH1F*)IsoRawCanvasTT->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawTT_    = (TH1F*)RelIsoRawCanvasTT->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedTT_    = (TH1F*)IsoRawCutBasedCanvasTT->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsTT_ = (TH1F*)NEventsCutsCanvasTT->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the QCD15to20 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRQCD15to20_ = (TH1F*)TauMuTauHaddRCanvasQCD15to20->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOQCD15to20_ = (TH1F*)MassDiMuRECOCanvasQCD15to20->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauQCD15to20_ = (TH1F*)MassDiTauCanvasQCD15to20->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2QCD15to20_ = (TH1F*)PtOverMassMu1Mu2CanvasQCD15to20->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuQCD15to20_  = (TH1F*)PtTauMuCanvasQCD15to20->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2QCD15to20_  = (TH1F*)PtMu1Mu2CanvasQCD15to20->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscQCD15to20_ = (TH1F*)PCSVBDiscCanvasQCD15to20->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTQCD15to20_     = (TH1F*)SumHTCanvasQCD15to20->GetPrimitive("SumHT");
  TH1F*  IsoRawQCD15to20_    = (TH1F*)IsoRawCanvasQCD15to20->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawQCD15to20_    = (TH1F*)RelIsoRawCanvasQCD15to20->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedQCD15to20_    = (TH1F*)IsoRawCutBasedCanvasQCD15to20->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsQCD15to20_ = (TH1F*)NEventsCutsCanvasQCD15to20->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the QCD20to30 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRQCD20to30_ = (TH1F*)TauMuTauHaddRCanvasQCD20to30->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOQCD20to30_ = (TH1F*)MassDiMuRECOCanvasQCD20to30->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauQCD20to30_ = (TH1F*)MassDiTauCanvasQCD20to30->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2QCD20to30_ = (TH1F*)PtOverMassMu1Mu2CanvasQCD20to30->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuQCD20to30_  = (TH1F*)PtTauMuCanvasQCD20to30->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2QCD20to30_  = (TH1F*)PtMu1Mu2CanvasQCD20to30->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscQCD20to30_ = (TH1F*)PCSVBDiscCanvasQCD20to30->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTQCD20to30_     = (TH1F*)SumHTCanvasQCD20to30->GetPrimitive("SumHT");
  TH1F*  IsoRawQCD20to30_    = (TH1F*)IsoRawCanvasQCD20to30->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawQCD20to30_    = (TH1F*)RelIsoRawCanvasQCD20to30->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedQCD20to30_    = (TH1F*)IsoRawCutBasedCanvasQCD20to30->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsQCD20to30_ = (TH1F*)NEventsCutsCanvasQCD20to30->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the QCD30to50 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRQCD30to50_ = (TH1F*)TauMuTauHaddRCanvasQCD30to50->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOQCD30to50_ = (TH1F*)MassDiMuRECOCanvasQCD30to50->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauQCD30to50_ = (TH1F*)MassDiTauCanvasQCD30to50->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2QCD30to50_ = (TH1F*)PtOverMassMu1Mu2CanvasQCD30to50->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuQCD30to50_  = (TH1F*)PtTauMuCanvasQCD30to50->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2QCD30to50_  = (TH1F*)PtMu1Mu2CanvasQCD30to50->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscQCD30to50_ = (TH1F*)PCSVBDiscCanvasQCD30to50->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTQCD30to50_     = (TH1F*)SumHTCanvasQCD30to50->GetPrimitive("SumHT");
  TH1F*  IsoRawQCD30to50_    = (TH1F*)IsoRawCanvasQCD30to50->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawQCD30to50_    = (TH1F*)RelIsoRawCanvasQCD30to50->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedQCD30to50_    = (TH1F*)IsoRawCutBasedCanvasQCD30to50->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsQCD30to50_ = (TH1F*)NEventsCutsCanvasQCD30to50->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the QCD50to80 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRQCD50to80_ = (TH1F*)TauMuTauHaddRCanvasQCD50to80->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOQCD50to80_ = (TH1F*)MassDiMuRECOCanvasQCD50to80->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauQCD50to80_ = (TH1F*)MassDiTauCanvasQCD50to80->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2QCD50to80_ = (TH1F*)PtOverMassMu1Mu2CanvasQCD50to80->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuQCD50to80_  = (TH1F*)PtTauMuCanvasQCD50to80->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2QCD50to80_  = (TH1F*)PtMu1Mu2CanvasQCD50to80->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscQCD50to80_ = (TH1F*)PCSVBDiscCanvasQCD50to80->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTQCD50to80_     = (TH1F*)SumHTCanvasQCD50to80->GetPrimitive("SumHT");
  TH1F*  IsoRawQCD50to80_    = (TH1F*)IsoRawCanvasQCD50to80->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawQCD50to80_    = (TH1F*)RelIsoRawCanvasQCD50to80->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedQCD50to80_    = (TH1F*)IsoRawCutBasedCanvasQCD50to80->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsQCD50to80_ = (TH1F*)NEventsCutsCanvasQCD50to80->GetPrimitive("NEventsCuts");


  //////////////////////////////
  // Getting the QCD80to120 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRQCD80to120_ = (TH1F*)TauMuTauHaddRCanvasQCD80to120->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOQCD80to120_ = (TH1F*)MassDiMuRECOCanvasQCD80to120->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauQCD80to120_ = (TH1F*)MassDiTauCanvasQCD80to120->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2QCD80to120_ = (TH1F*)PtOverMassMu1Mu2CanvasQCD80to120->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuQCD80to120_  = (TH1F*)PtTauMuCanvasQCD80to120->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2QCD80to120_  = (TH1F*)PtMu1Mu2CanvasQCD80to120->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscQCD80to120_ = (TH1F*)PCSVBDiscCanvasQCD80to120->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTQCD80to120_     = (TH1F*)SumHTCanvasQCD80to120->GetPrimitive("SumHT");
  TH1F*  IsoRawQCD80to120_    = (TH1F*)IsoRawCanvasQCD80to120->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawQCD80to120_    = (TH1F*)RelIsoRawCanvasQCD80to120->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedQCD80to120_    = (TH1F*)IsoRawCutBasedCanvasQCD80to120->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsQCD80to120_ = (TH1F*)NEventsCutsCanvasQCD80to120->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the QCD120to170 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRQCD120to170_ = (TH1F*)TauMuTauHaddRCanvasQCD120to170->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOQCD120to170_ = (TH1F*)MassDiMuRECOCanvasQCD120to170->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauQCD120to170_ = (TH1F*)MassDiTauCanvasQCD120to170->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2QCD120to170_ = (TH1F*)PtOverMassMu1Mu2CanvasQCD120to170->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuQCD120to170_  = (TH1F*)PtTauMuCanvasQCD120to170->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2QCD120to170_  = (TH1F*)PtMu1Mu2CanvasQCD120to170->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscQCD120to170_ = (TH1F*)PCSVBDiscCanvasQCD120to170->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTQCD120to170_     = (TH1F*)SumHTCanvasQCD120to170->GetPrimitive("SumHT");
  TH1F*  IsoRawQCD120to170_    = (TH1F*)IsoRawCanvasQCD120to170->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawQCD120to170_    = (TH1F*)RelIsoRawCanvasQCD120to170->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedQCD120to170_    = (TH1F*)IsoRawCutBasedCanvasQCD120to170->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsQCD120to170_ = (TH1F*)NEventsCutsCanvasQCD120to170->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the QCD170to300 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRQCD170to300_ = (TH1F*)TauMuTauHaddRCanvasQCD170to300->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOQCD170to300_ = (TH1F*)MassDiMuRECOCanvasQCD170to300->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauQCD170to300_ = (TH1F*)MassDiTauCanvasQCD170to300->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2QCD170to300_ = (TH1F*)PtOverMassMu1Mu2CanvasQCD170to300->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuQCD170to300_  = (TH1F*)PtTauMuCanvasQCD170to300->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2QCD170to300_  = (TH1F*)PtMu1Mu2CanvasQCD170to300->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscQCD170to300_ = (TH1F*)PCSVBDiscCanvasQCD170to300->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTQCD170to300_     = (TH1F*)SumHTCanvasQCD170to300->GetPrimitive("SumHT");
  TH1F*  IsoRawQCD170to300_    = (TH1F*)IsoRawCanvasQCD170to300->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawQCD170to300_    = (TH1F*)RelIsoRawCanvasQCD170to300->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedQCD170to300_    = (TH1F*)IsoRawCutBasedCanvasQCD170to300->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsQCD170to300_ = (TH1F*)NEventsCutsCanvasQCD170to300->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the QCD300to470 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRQCD300to470_ = (TH1F*)TauMuTauHaddRCanvasQCD300to470->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOQCD300to470_ = (TH1F*)MassDiMuRECOCanvasQCD300to470->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauQCD300to470_ = (TH1F*)MassDiTauCanvasQCD300to470->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2QCD300to470_ = (TH1F*)PtOverMassMu1Mu2CanvasQCD300to470->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuQCD300to470_  = (TH1F*)PtTauMuCanvasQCD300to470->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2QCD300to470_  = (TH1F*)PtMu1Mu2CanvasQCD300to470->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscQCD300to470_ = (TH1F*)PCSVBDiscCanvasQCD300to470->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTQCD300to470_     = (TH1F*)SumHTCanvasQCD300to470->GetPrimitive("SumHT");
  TH1F*  IsoRawQCD300to470_    = (TH1F*)IsoRawCanvasQCD300to470->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawQCD300to470_    = (TH1F*)RelIsoRawCanvasQCD300to470->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedQCD300to470_    = (TH1F*)IsoRawCutBasedCanvasQCD300to470->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsQCD300to470_ = (TH1F*)NEventsCutsCanvasQCD300to470->GetPrimitive("NEventsCuts");


  //////////////////////////////
  // Getting the QCD470to600 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRQCD470to600_ = (TH1F*)TauMuTauHaddRCanvasQCD470to600->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOQCD470to600_ = (TH1F*)MassDiMuRECOCanvasQCD470to600->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauQCD470to600_ = (TH1F*)MassDiTauCanvasQCD470to600->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2QCD470to600_ = (TH1F*)PtOverMassMu1Mu2CanvasQCD470to600->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuQCD470to600_  = (TH1F*)PtTauMuCanvasQCD470to600->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2QCD470to600_  = (TH1F*)PtMu1Mu2CanvasQCD470to600->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscQCD470to600_ = (TH1F*)PCSVBDiscCanvasQCD470to600->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTQCD470to600_     = (TH1F*)SumHTCanvasQCD470to600->GetPrimitive("SumHT");
  TH1F*  IsoRawQCD470to600_    = (TH1F*)IsoRawCanvasQCD470to600->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawQCD470to600_    = (TH1F*)RelIsoRawCanvasQCD470to600->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedQCD470to600_    = (TH1F*)IsoRawCutBasedCanvasQCD470to600->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsQCD470to600_ = (TH1F*)NEventsCutsCanvasQCD470to600->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the QCD600to800 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRQCD600to800_ = (TH1F*)TauMuTauHaddRCanvasQCD600to800->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOQCD600to800_ = (TH1F*)MassDiMuRECOCanvasQCD600to800->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauQCD600to800_ = (TH1F*)MassDiTauCanvasQCD600to800->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2QCD600to800_ = (TH1F*)PtOverMassMu1Mu2CanvasQCD600to800->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuQCD600to800_  = (TH1F*)PtTauMuCanvasQCD600to800->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2QCD600to800_  = (TH1F*)PtMu1Mu2CanvasQCD600to800->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscQCD600to800_ = (TH1F*)PCSVBDiscCanvasQCD600to800->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTQCD600to800_     = (TH1F*)SumHTCanvasQCD600to800->GetPrimitive("SumHT");
  TH1F*  IsoRawQCD600to800_    = (TH1F*)IsoRawCanvasQCD600to800->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawQCD600to800_    = (TH1F*)RelIsoRawCanvasQCD600to800->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedQCD600to800_    = (TH1F*)IsoRawCutBasedCanvasQCD600to800->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsQCD600to800_ = (TH1F*)NEventsCutsCanvasQCD600to800->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the QCD800to1000 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRQCD800to1000_ = (TH1F*)TauMuTauHaddRCanvasQCD800to1000->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOQCD800to1000_ = (TH1F*)MassDiMuRECOCanvasQCD800to1000->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauQCD800to1000_ = (TH1F*)MassDiTauCanvasQCD800to1000->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2QCD800to1000_ = (TH1F*)PtOverMassMu1Mu2CanvasQCD800to1000->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuQCD800to1000_  = (TH1F*)PtTauMuCanvasQCD800to1000->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2QCD800to1000_  = (TH1F*)PtMu1Mu2CanvasQCD800to1000->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscQCD800to1000_ = (TH1F*)PCSVBDiscCanvasQCD800to1000->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTQCD800to1000_     = (TH1F*)SumHTCanvasQCD800to1000->GetPrimitive("SumHT");
  TH1F*  IsoRawQCD800to1000_    = (TH1F*)IsoRawCanvasQCD800to1000->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawQCD800to1000_    = (TH1F*)RelIsoRawCanvasQCD800to1000->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedQCD800to1000_    = (TH1F*)IsoRawCutBasedCanvasQCD800to1000->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsQCD800to1000_ = (TH1F*)NEventsCutsCanvasQCD800to1000->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the QCD1000toInf Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRQCD1000toInf_ = (TH1F*)TauMuTauHaddRCanvasQCD1000toInf->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOQCD1000toInf_ = (TH1F*)MassDiMuRECOCanvasQCD1000toInf->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauQCD1000toInf_ = (TH1F*)MassDiTauCanvasQCD1000toInf->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2QCD1000toInf_ = (TH1F*)PtOverMassMu1Mu2CanvasQCD1000toInf->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuQCD1000toInf_  = (TH1F*)PtTauMuCanvasQCD1000toInf->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2QCD1000toInf_  = (TH1F*)PtMu1Mu2CanvasQCD1000toInf->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscQCD1000toInf_ = (TH1F*)PCSVBDiscCanvasQCD1000toInf->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTQCD1000toInf_     = (TH1F*)SumHTCanvasQCD1000toInf->GetPrimitive("SumHT");
  TH1F*  IsoRawQCD1000toInf_    = (TH1F*)IsoRawCanvasQCD1000toInf->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawQCD1000toInf_    = (TH1F*)RelIsoRawCanvasQCD1000toInf->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedQCD1000toInf_    = (TH1F*)IsoRawCutBasedCanvasQCD1000toInf->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsQCD1000toInf_ = (TH1F*)NEventsCutsCanvasQCD1000toInf->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the DYH Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRDYH_ = (TH1F*)TauMuTauHaddRCanvasDYH->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECODYH_ = (TH1F*)MassDiMuRECOCanvasDYH->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauDYH_ = (TH1F*)MassDiTauCanvasDYH->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2DYH_ = (TH1F*)PtOverMassMu1Mu2CanvasDYH->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuDYH_  = (TH1F*)PtTauMuCanvasDYH->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2DYH_  = (TH1F*)PtMu1Mu2CanvasDYH->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscDYH_ = (TH1F*)PCSVBDiscCanvasDYH->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTDYH_     = (TH1F*)SumHTCanvasDYH->GetPrimitive("SumHT");
  TH1F*  IsoRawDYH_    = (TH1F*)IsoRawCanvasDYH->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawDYH_    = (TH1F*)RelIsoRawCanvasDYH->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedDYH_    = (TH1F*)IsoRawCutBasedCanvasDYH->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsDYH_ = (TH1F*)NEventsCutsCanvasDYH->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the DYL Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRDYL_ = (TH1F*)TauMuTauHaddRCanvasDYL->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECODYL_ = (TH1F*)MassDiMuRECOCanvasDYL->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauDYL_ = (TH1F*)MassDiTauCanvasDYL->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2DYL_ = (TH1F*)PtOverMassMu1Mu2CanvasDYL->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuDYL_  = (TH1F*)PtTauMuCanvasDYL->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2DYL_  = (TH1F*)PtMu1Mu2CanvasDYL->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscDYL_ = (TH1F*)PCSVBDiscCanvasDYL->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTDYL_     = (TH1F*)SumHTCanvasDYL->GetPrimitive("SumHT");
  TH1F*  IsoRawDYL_    = (TH1F*)IsoRawCanvasDYL->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawDYL_    = (TH1F*)RelIsoRawCanvasDYL->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedDYL_    = (TH1F*)IsoRawCutBasedCanvasDYL->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsDYL_ = (TH1F*)NEventsCutsCanvasDYL->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the H125a19 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRH125a19_ = (TH1F*)TauMuTauHaddRCanvasH125a19->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOH125a19_ = (TH1F*)MassDiMuRECOCanvasH125a19->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauH125a19_ = (TH1F*)MassDiTauCanvasH125a19->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2H125a19_ = (TH1F*)PtOverMassMu1Mu2CanvasH125a19->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuH125a19_  = (TH1F*)PtTauMuCanvasH125a19->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2H125a19_  = (TH1F*)PtMu1Mu2CanvasH125a19->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscH125a19_ = (TH1F*)PCSVBDiscCanvasH125a19->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTH125a19_     = (TH1F*)SumHTCanvasH125a19->GetPrimitive("SumHT");
  TH1F*  IsoRawH125a19_    = (TH1F*)IsoRawCanvasH125a19->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawH125a19_    = (TH1F*)RelIsoRawCanvasH125a19->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedH125a19_    = (TH1F*)IsoRawCutBasedCanvasH125a19->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsH125a19_ = (TH1F*)NEventsCutsCanvasH125a19->GetPrimitive("NEventsCuts");


  //////////////////////////////
  // Getting the H125a9 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRH125a9_ = (TH1F*)TauMuTauHaddRCanvasH125a9->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOH125a9_ = (TH1F*)MassDiMuRECOCanvasH125a9->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauH125a9_ = (TH1F*)MassDiTauCanvasH125a9->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2H125a9_ = (TH1F*)PtOverMassMu1Mu2CanvasH125a9->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuH125a9_  = (TH1F*)PtTauMuCanvasH125a9->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2H125a9_  = (TH1F*)PtMu1Mu2CanvasH125a9->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscH125a9_ = (TH1F*)PCSVBDiscCanvasH125a9->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTH125a9_     = (TH1F*)SumHTCanvasH125a9->GetPrimitive("SumHT");
  TH1F*  IsoRawH125a9_    = (TH1F*)IsoRawCanvasH125a9->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawH125a9_    = (TH1F*)RelIsoRawCanvasH125a9->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedH125a9_    = (TH1F*)IsoRawCutBasedCanvasH125a9->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsH125a9_ = (TH1F*)NEventsCutsCanvasH125a9->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the H125a5 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRH125a5_ = (TH1F*)TauMuTauHaddRCanvasH125a5->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOH125a5_ = (TH1F*)MassDiMuRECOCanvasH125a5->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauH125a5_ = (TH1F*)MassDiTauCanvasH125a5->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2H125a5_ = (TH1F*)PtOverMassMu1Mu2CanvasH125a5->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuH125a5_  = (TH1F*)PtTauMuCanvasH125a5->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2H125a5_  = (TH1F*)PtMu1Mu2CanvasH125a5->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscH125a5_ = (TH1F*)PCSVBDiscCanvasH125a5->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTH125a5_     = (TH1F*)SumHTCanvasH125a5->GetPrimitive("SumHT");
  TH1F*  IsoRawH125a5_    = (TH1F*)IsoRawCanvasH125a5->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawH125a5_    = (TH1F*)RelIsoRawCanvasH125a5->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedH125a5_    = (TH1F*)IsoRawCutBasedCanvasH125a5->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsH125a5_ = (TH1F*)NEventsCutsCanvasH125a5->GetPrimitive("NEventsCuts");

  //////////////////////////////
  // Getting the H750a9 Histograms
  //////////////////////////////
  TH1F*  TauMuTauHaddRH750a9_ = (TH1F*)TauMuTauHaddRCanvasH750a9->GetPrimitive("TauMuTauHaddR");
  TH1F*  MassDiMuRECOH750a9_ = (TH1F*)MassDiMuRECOCanvasH750a9->GetPrimitive("MassDiMuRECO");
  TH1F*  MassDiTauH750a9_ = (TH1F*)MassDiTauCanvasH750a9->GetPrimitive("MassDiTau");
  TH1F*  PtOverMassMu1Mu2H750a9_ = (TH1F*)PtOverMassMu1Mu2CanvasH750a9->GetPrimitive("PtOverMassMu1Mu2");
  TH1F*  PtTauMuH750a9_  = (TH1F*)PtTauMuCanvasH750a9->GetPrimitive("PtTauMu");
  TH1F*  PtMu1Mu2H750a9_  = (TH1F*)PtMu1Mu2CanvasH750a9->GetPrimitive("PtMu1Mu2");
  TH1F*  PCSVBDiscH750a9_ = (TH1F*)PCSVBDiscCanvasH750a9->GetPrimitive("PCSVBDisc");
  TH1F*  SumHTH750a9_     = (TH1F*)SumHTCanvasH750a9->GetPrimitive("SumHT");
  TH1F*  IsoRawH750a9_    = (TH1F*)IsoRawCanvasH750a9->GetPrimitive("IsoRaw");
  TH1F*  RelIsoRawH750a9_    = (TH1F*)RelIsoRawCanvasH750a9->GetPrimitive("RelIsoRaw");
  TH1F*  IsoRawCutBasedH750a9_    = (TH1F*)IsoRawCutBasedCanvasH750a9->GetPrimitive("IsoRawCutBased");

  TH1F*  NEventsCutsH750a9_ = (TH1F*)NEventsCutsCanvasH750a9->GetPrimitive("NEventsCuts");


cout << "Histograms assigned." << endl; 

  //////////////////////////////
  //  Scaling xsec calculations
  //////////////////////////////
  double scale_DYH = 1921.8 * 3 * 20000.0 / 94714489.0 ;
  double scale_DYL = 1861   * 20000.0 /  15916404.0;
  double scale_TT  = 831.76 * 20000.0 /  38288417.0 ;
  double scale_QCD1000toInf = 10.4305 * 0.15544 * 20000.0 / 3884666.0 ;
  double scale_QCD800to1000 = 32.3486 * 0.14552 * 20000.0 / 3953740.0 ;
  double scale_QCD600to800  = 187.109 * 0.13412 * 20000.0 / 3874566.0 ;
  double scale_QCD470to600  = 645.528 * 0.12242 * 20000.0 / 3606911.0 ;
  double scale_QCD300to470  = 7820.25 * 0.10196 * 20000.0 / 7486452.0 ;
  double scale_QCD170to300  = 117989.0  * 0.07335 * 20000.0 / 7806467.0 ;
  double scale_QCD120to170  = 469797.0  * 0.05362 * 20000.0 / 7925929.0 ;
  double scale_QCD80to120   = 2758420.0 * 0.03844 * 20000.0 / 13870432.0;
  double scale_QCD50to80    = 19222500.0 * 0.02276 * 20000.0 / 20383957.0 ;
  double scale_QCD30to50    = 139803000.0 * 0.01182 * 20000.0 / 27765359.0 ; 
  double scale_QCD20to30    = 558528000.0 * 0.0053 * 20000.0 / 31565787.0 ; 
  double scale_QCD15to20    = 1273190000.0 * 0.003 * 20000.0 / 4617630.0 ;
  double scale_H125a19 = 48.90 * 20000.0 /  300000.0 ;
  double scale_H125a9  = 48.90 * 20000.0 /  292460.0 ;
  double scale_H125a5  = 48.90 * 20000.0 /  297366.0 ;
  double scale_H750a9  = 0.4969 * 20000.0/  300000.0 ;

///////////////////////////////////////////
// Scaling HIstograms that are NEventsCuts
///////////////////////////////////////////
  TauMuTauHaddRH750a9_->Scale(scale_H750a9);
  MassDiMuRECOH750a9_->Scale(scale_H750a9);
  MassDiTauH750a9_->Scale(scale_H750a9);
  PtOverMassMu1Mu2H750a9_->Scale(scale_H750a9);
  PtTauMuH750a9_->Scale(scale_H750a9);
  PtMu1Mu2H750a9_->Scale(scale_H750a9);
  PCSVBDiscH750a9_->Scale(scale_H750a9);
  SumHTH750a9_->Scale(scale_H750a9);
  IsoRawH750a9_->Scale(scale_H750a9);
  RelIsoRawH750a9_->Scale(scale_H750a9);
  IsoRawCutBasedH750a9_->Scale(scale_H750a9);

  TauMuTauHaddRH125a9_->Scale(scale_H125a9);
  MassDiMuRECOH125a9_->Scale(scale_H125a9);
  MassDiTauH125a9_->Scale(scale_H125a9);
  PtOverMassMu1Mu2H125a9_->Scale(scale_H125a9);
  PtTauMuH125a9_->Scale(scale_H125a9);
  PtMu1Mu2H125a9_->Scale(scale_H125a9);
  PCSVBDiscH125a9_->Scale(scale_H125a9);
  SumHTH125a9_->Scale(scale_H125a9);
  IsoRawH125a9_->Scale(scale_H125a9);
  RelIsoRawH125a9_->Scale(scale_H125a9);
  IsoRawCutBasedH125a9_->Scale(scale_H125a9);

  TauMuTauHaddRH125a5_->Scale(scale_H125a5);
  MassDiMuRECOH125a5_->Scale(scale_H125a5);
  MassDiTauH125a5_->Scale(scale_H125a5);
  PtOverMassMu1Mu2H125a5_->Scale(scale_H125a5);
  PtTauMuH125a5_->Scale(scale_H125a5);
  PtMu1Mu2H125a5_->Scale(scale_H125a5);
  PCSVBDiscH125a5_->Scale(scale_H125a5);
  SumHTH125a5_->Scale(scale_H125a5);
  IsoRawH125a5_->Scale(scale_H125a5);
  RelIsoRawH125a5_->Scale(scale_H125a5);
  IsoRawCutBasedH125a5_->Scale(scale_H125a5);

  TauMuTauHaddRH125a19_->Scale(scale_H125a19);
  MassDiMuRECOH125a19_->Scale(scale_H125a19);
  MassDiTauH125a19_->Scale(scale_H125a19);
  PtOverMassMu1Mu2H125a19_->Scale(scale_H125a19);
  PtTauMuH125a19_->Scale(scale_H125a19);
  PtMu1Mu2H125a19_->Scale(scale_H125a19);
  PCSVBDiscH125a19_->Scale(scale_H125a19);
  SumHTH125a19_->Scale(scale_H125a19);
  IsoRawH125a19_->Scale(scale_H125a19);
  RelIsoRawH125a19_->Scale(scale_H125a19);
  IsoRawCutBasedH125a19_->Scale(scale_H125a19);

  TauMuTauHaddRDYH_->Scale(scale_DYH);
  MassDiMuRECODYH_->Scale(scale_DYH);
  MassDiTauDYH_->Scale(scale_DYH);
  PtOverMassMu1Mu2DYH_->Scale(scale_DYH);
  PtTauMuDYH_->Scale(scale_DYH);
  PtMu1Mu2DYH_->Scale(scale_DYH);
  PCSVBDiscDYH_->Scale(scale_DYH);
  SumHTDYH_->Scale(scale_DYH);
  IsoRawDYH_->Scale(scale_DYH);
  RelIsoRawDYH_->Scale(scale_DYH);
  IsoRawCutBasedDYH_->Scale(scale_DYH);

  TauMuTauHaddRDYL_->Scale(scale_DYL);
  MassDiMuRECODYL_->Scale(scale_DYL);
  MassDiTauDYL_->Scale(scale_DYL);
  PtOverMassMu1Mu2DYL_->Scale(scale_DYL);
  PtTauMuDYL_->Scale(scale_DYL);
  PtMu1Mu2DYL_->Scale(scale_DYL);
  PCSVBDiscDYL_->Scale(scale_DYL);
  SumHTDYL_->Scale(scale_DYL);
  IsoRawDYL_->Scale(scale_DYL);
  RelIsoRawDYL_->Scale(scale_DYL);
  IsoRawCutBasedDYL_->Scale(scale_DYL);

  TauMuTauHaddRTT_->Scale(scale_TT);
  MassDiMuRECOTT_->Scale(scale_TT);
  MassDiTauTT_->Scale(scale_TT);
  PtOverMassMu1Mu2TT_->Scale(scale_TT);
  PtTauMuTT_->Scale(scale_TT);
  PtMu1Mu2TT_->Scale(scale_TT);
  PCSVBDiscTT_->Scale(scale_TT);
  SumHTTT_->Scale(scale_TT);
  IsoRawTT_->Scale(scale_TT);
  RelIsoRawTT_->Scale(scale_TT);
  IsoRawCutBasedTT_->Scale(scale_TT);

  TauMuTauHaddRQCD1000toInf_->Scale(scale_QCD1000toInf);
  MassDiMuRECOQCD1000toInf_->Scale(scale_QCD1000toInf);
  MassDiTauQCD1000toInf_->Scale(scale_QCD1000toInf);
  PtOverMassMu1Mu2QCD1000toInf_->Scale(scale_QCD1000toInf);
  PtTauMuQCD1000toInf_->Scale(scale_QCD1000toInf);
  PtMu1Mu2QCD1000toInf_->Scale(scale_QCD1000toInf);
  PCSVBDiscQCD1000toInf_->Scale(scale_QCD1000toInf);
  SumHTQCD1000toInf_->Scale(scale_QCD1000toInf);
  IsoRawQCD1000toInf_->Scale(scale_QCD1000toInf);
  RelIsoRawQCD1000toInf_->Scale(scale_QCD1000toInf);
  IsoRawCutBasedQCD1000toInf_->Scale(scale_QCD1000toInf);

  TauMuTauHaddRQCD120to170_->Scale(scale_QCD120to170);
  MassDiMuRECOQCD120to170_->Scale(scale_QCD120to170);
  MassDiTauQCD120to170_->Scale(scale_QCD120to170);
  PtOverMassMu1Mu2QCD120to170_->Scale(scale_QCD120to170);
  PtTauMuQCD120to170_->Scale(scale_QCD120to170);
  PtMu1Mu2QCD120to170_->Scale(scale_QCD120to170);
  PCSVBDiscQCD120to170_->Scale(scale_QCD120to170);
  SumHTQCD120to170_->Scale(scale_QCD120to170);
  IsoRawQCD120to170_->Scale(scale_QCD120to170);
  RelIsoRawQCD120to170_->Scale(scale_QCD120to170);
  IsoRawCutBasedQCD120to170_->Scale(scale_QCD120to170);

  TauMuTauHaddRQCD15to20_->Scale(scale_QCD15to20);
  MassDiMuRECOQCD15to20_->Scale(scale_QCD15to20);
  MassDiTauQCD15to20_->Scale(scale_QCD15to20);
  PtOverMassMu1Mu2QCD15to20_->Scale(scale_QCD15to20);
  PtTauMuQCD15to20_->Scale(scale_QCD15to20);
  PtMu1Mu2QCD15to20_->Scale(scale_QCD15to20);
  PCSVBDiscQCD15to20_->Scale(scale_QCD15to20);
  SumHTQCD15to20_->Scale(scale_QCD15to20);
  IsoRawQCD15to20_->Scale(scale_QCD15to20);
  RelIsoRawQCD15to20_->Scale(scale_QCD15to20);
  IsoRawCutBasedQCD15to20_->Scale(scale_QCD15to20);

  TauMuTauHaddRQCD170to300_->Scale(scale_QCD170to300);
  MassDiMuRECOQCD170to300_->Scale(scale_QCD170to300);
  MassDiTauQCD170to300_->Scale(scale_QCD170to300);
  PtOverMassMu1Mu2QCD170to300_->Scale(scale_QCD170to300);
  PtTauMuQCD170to300_->Scale(scale_QCD170to300);
  PtMu1Mu2QCD170to300_->Scale(scale_QCD170to300);
  PCSVBDiscQCD170to300_->Scale(scale_QCD170to300);
  SumHTQCD170to300_->Scale(scale_QCD170to300);
  IsoRawQCD170to300_->Scale(scale_QCD170to300);
  RelIsoRawQCD170to300_->Scale(scale_QCD170to300);
  IsoRawCutBasedQCD170to300_->Scale(scale_QCD170to300);

  TauMuTauHaddRQCD20to30_->Scale(scale_QCD20to30);
  MassDiMuRECOQCD20to30_->Scale(scale_QCD20to30);
  MassDiTauQCD20to30_->Scale(scale_QCD20to30);
  PtOverMassMu1Mu2QCD20to30_->Scale(scale_QCD20to30);
  PtTauMuQCD20to30_->Scale(scale_QCD20to30);
  PtMu1Mu2QCD20to30_->Scale(scale_QCD20to30);
  PCSVBDiscQCD20to30_->Scale(scale_QCD20to30);
  SumHTQCD20to30_->Scale(scale_QCD20to30);
  IsoRawQCD20to30_->Scale(scale_QCD20to30);
  RelIsoRawQCD20to30_->Scale(scale_QCD20to30);
  IsoRawCutBasedQCD20to30_->Scale(scale_QCD20to30);

  TauMuTauHaddRQCD300to470_->Scale(scale_QCD300to470);
  MassDiMuRECOQCD300to470_->Scale(scale_QCD300to470);
  MassDiTauQCD300to470_->Scale(scale_QCD300to470);
  PtOverMassMu1Mu2QCD300to470_->Scale(scale_QCD300to470);
  PtTauMuQCD300to470_->Scale(scale_QCD300to470);
  PtMu1Mu2QCD300to470_->Scale(scale_QCD300to470);
  PCSVBDiscQCD300to470_->Scale(scale_QCD300to470);
  SumHTQCD300to470_->Scale(scale_QCD300to470);
  IsoRawQCD300to470_->Scale(scale_QCD300to470);
  RelIsoRawQCD300to470_->Scale(scale_QCD300to470);
  IsoRawCutBasedQCD300to470_->Scale(scale_QCD300to470);

  TauMuTauHaddRQCD30to50_->Scale(scale_QCD30to50);
  MassDiMuRECOQCD30to50_->Scale(scale_QCD30to50);
  MassDiTauQCD30to50_->Scale(scale_QCD30to50);
  PtOverMassMu1Mu2QCD30to50_->Scale(scale_QCD30to50);
  PtTauMuQCD30to50_->Scale(scale_QCD30to50);
  PtMu1Mu2QCD30to50_->Scale(scale_QCD30to50);
  PCSVBDiscQCD30to50_->Scale(scale_QCD30to50);
  SumHTQCD30to50_->Scale(scale_QCD30to50);
  IsoRawQCD30to50_->Scale(scale_QCD30to50);
  RelIsoRawQCD30to50_->Scale(scale_QCD30to50);
  IsoRawCutBasedQCD30to50_->Scale(scale_QCD30to50);

  TauMuTauHaddRQCD470to600_->Scale(scale_QCD470to600);
  MassDiMuRECOQCD470to600_->Scale(scale_QCD470to600);
  MassDiTauQCD470to600_->Scale(scale_QCD470to600);
  PtOverMassMu1Mu2QCD470to600_->Scale(scale_QCD470to600);
  PtTauMuQCD470to600_->Scale(scale_QCD470to600);
  PtMu1Mu2QCD470to600_->Scale(scale_QCD470to600);
  PCSVBDiscQCD470to600_->Scale(scale_QCD470to600);
  SumHTQCD470to600_->Scale(scale_QCD470to600);
  IsoRawQCD470to600_->Scale(scale_QCD470to600);
  RelIsoRawQCD470to600_->Scale(scale_QCD470to600);
  IsoRawCutBasedQCD470to600_->Scale(scale_QCD470to600);

  TauMuTauHaddRQCD50to80_->Scale(scale_QCD50to80);
  MassDiMuRECOQCD50to80_->Scale(scale_QCD50to80);
  MassDiTauQCD50to80_->Scale(scale_QCD50to80);
  PtOverMassMu1Mu2QCD50to80_->Scale(scale_QCD50to80);
  PtTauMuQCD50to80_->Scale(scale_QCD50to80);
  PtMu1Mu2QCD50to80_->Scale(scale_QCD50to80);
  PCSVBDiscQCD50to80_->Scale(scale_QCD50to80);
  SumHTQCD50to80_->Scale(scale_QCD50to80);
  IsoRawQCD50to80_->Scale(scale_QCD50to80);
  RelIsoRawQCD50to80_->Scale(scale_QCD50to80);
  IsoRawCutBasedQCD50to80_->Scale(scale_QCD50to80);

  TauMuTauHaddRQCD600to800_->Scale(scale_QCD600to800);
  MassDiMuRECOQCD600to800_->Scale(scale_QCD600to800);
  MassDiTauQCD600to800_->Scale(scale_QCD600to800);
  PtOverMassMu1Mu2QCD600to800_->Scale(scale_QCD600to800);
  PtTauMuQCD600to800_->Scale(scale_QCD600to800);
  PtMu1Mu2QCD600to800_->Scale(scale_QCD600to800);
  PCSVBDiscQCD600to800_->Scale(scale_QCD600to800);
  SumHTQCD600to800_->Scale(scale_QCD600to800);
  IsoRawQCD600to800_->Scale(scale_QCD600to800);
  RelIsoRawQCD600to800_->Scale(scale_QCD600to800);
  IsoRawCutBasedQCD600to800_->Scale(scale_QCD600to800);

  TauMuTauHaddRQCD800to1000_->Scale(scale_QCD800to1000);
  MassDiMuRECOQCD800to1000_->Scale(scale_QCD800to1000);
  MassDiTauQCD800to1000_->Scale(scale_QCD800to1000);
  PtOverMassMu1Mu2QCD800to1000_->Scale(scale_QCD800to1000);
  PtTauMuQCD800to1000_->Scale(scale_QCD800to1000);
  PtMu1Mu2QCD800to1000_->Scale(scale_QCD800to1000);
  PCSVBDiscQCD800to1000_->Scale(scale_QCD800to1000);
  SumHTQCD800to1000_->Scale(scale_QCD800to1000);
  IsoRawQCD800to1000_->Scale(scale_QCD800to1000);
  RelIsoRawQCD800to1000_->Scale(scale_QCD800to1000);
  IsoRawCutBasedQCD800to1000_->Scale(scale_QCD800to1000);

  TauMuTauHaddRQCD80to120_->Scale(scale_QCD80to120);
  MassDiMuRECOQCD80to120_->Scale(scale_QCD80to120);
  MassDiTauQCD80to120_->Scale(scale_QCD80to120);
  PtOverMassMu1Mu2QCD80to120_->Scale(scale_QCD80to120);
  PtTauMuQCD80to120_->Scale(scale_QCD80to120);
  PtMu1Mu2QCD80to120_->Scale(scale_QCD80to120);
  PCSVBDiscQCD80to120_->Scale(scale_QCD80to120);
  SumHTQCD80to120_->Scale(scale_QCD80to120);
  IsoRawQCD80to120_->Scale(scale_QCD80to120);
  RelIsoRawQCD80to120_->Scale(scale_QCD80to120);
  IsoRawCutBasedQCD80to120_->Scale(scale_QCD80to120);

//////////////////////
// Getting Cut Counts
////////////////////// 
  // Declare Bin counts for TT
  double TT_Total = scale_TT*NEventsCutsTT_->GetBinContent(1), TT_BD0p5 = scale_TT*NEventsCutsTT_->GetBinContent(2), TT_BD0p75 = scale_TT*NEventsCutsTT_->GetBinContent(3);
  double TT_BD0p9 = scale_TT*NEventsCutsTT_->GetBinContent(4);
  double TT_ = scale_TT*NEventsCutsTT_->GetBinContent(5), TT_HT300 = scale_TT*NEventsCutsTT_->GetBinContent(6), TT_HT400 = scale_TT*NEventsCutsTT_->GetBinContent(7);
  double TT_HT300_BD0p75 = scale_TT*NEventsCutsTT_->GetBinContent(8), TT_HT400_BD0p5 = scale_TT*NEventsCutsTT_->GetBinContent(9), TT_IsoRaw0p5 = scale_TT*NEventsCutsTT_->GetBinContent(10); 
  double TT_IsoRaw1p0 = scale_TT*NEventsCutsTT_->GetBinContent(11), TT_TightIso = scale_TT*NEventsCutsTT_->GetBinContent(12), TT_VTightIso = scale_TT*NEventsCutsTT_->GetBinContent(13);

  // Declare Bin counts for QCD15to20
  double QCD15to20_Total = scale_QCD15to20*NEventsCutsQCD15to20_->GetBinContent(1), QCD15to20_BD0p5 = scale_QCD15to20*NEventsCutsQCD15to20_->GetBinContent(2); 
  double QCD15to20_BD0p75 = scale_QCD15to20*NEventsCutsQCD15to20_->GetBinContent(3), QCD15to20_BD0p9 = scale_QCD15to20*NEventsCutsQCD15to20_->GetBinContent(4);
  double QCD15to20_ = scale_QCD15to20*NEventsCutsQCD15to20_->GetBinContent(5), QCD15to20_HT300 = scale_QCD15to20*NEventsCutsQCD15to20_->GetBinContent(6);
  double QCD15to20_HT400 = scale_QCD15to20*NEventsCutsQCD15to20_->GetBinContent(7), QCD15to20_HT300_BD0p75 = scale_QCD15to20*NEventsCutsQCD15to20_->GetBinContent(8); 
  double QCD15to20_HT400_BD0p5 = scale_QCD15to20*NEventsCutsQCD15to20_->GetBinContent(9), QCD15to20_IsoRaw0p5 = scale_QCD15to20*NEventsCutsQCD15to20_->GetBinContent(10);
  double QCD15to20_IsoRaw1p0 = scale_QCD15to20*NEventsCutsQCD15to20_->GetBinContent(11), QCD15to20_TightIso = scale_QCD15to20*NEventsCutsQCD15to20_->GetBinContent(12); 
  double QCD15to20_VTightIso = scale_QCD15to20*NEventsCutsQCD15to20_->GetBinContent(13);

  // Declare Bin counts for QCD20to30
  double QCD20to30_Total = scale_QCD20to30*NEventsCutsQCD20to30_->GetBinContent(1), QCD20to30_BD0p5 = scale_QCD20to30*NEventsCutsQCD20to30_->GetBinContent(2); 
  double QCD20to30_BD0p75 = scale_QCD20to30*NEventsCutsQCD20to30_->GetBinContent(3), QCD20to30_BD0p9 = scale_QCD20to30*NEventsCutsQCD20to30_->GetBinContent(4);
  double QCD20to30_ = scale_QCD20to30*NEventsCutsQCD20to30_->GetBinContent(5), QCD20to30_HT300 = scale_QCD20to30*NEventsCutsQCD20to30_->GetBinContent(6);
  double QCD20to30_HT400 = scale_QCD20to30*NEventsCutsQCD20to30_->GetBinContent(7), QCD20to30_HT300_BD0p75 = scale_QCD20to30*NEventsCutsQCD20to30_->GetBinContent(8); 
  double QCD20to30_HT400_BD0p5 = scale_QCD20to30*NEventsCutsQCD20to30_->GetBinContent(9), QCD20to30_IsoRaw0p5 = scale_QCD20to30*NEventsCutsQCD20to30_->GetBinContent(10);
  double QCD20to30_IsoRaw1p0 = scale_QCD20to30*NEventsCutsQCD20to30_->GetBinContent(11), QCD20to30_TightIso = scale_QCD20to30*NEventsCutsQCD20to30_->GetBinContent(12); 
  double QCD20to30_VTightIso = scale_QCD20to30*NEventsCutsQCD20to30_->GetBinContent(13);

  // Declare Bin counts for QCD30to50
  double QCD30to50_Total = scale_QCD30to50*NEventsCutsQCD30to50_->GetBinContent(1), QCD30to50_BD0p5 = scale_QCD30to50*NEventsCutsQCD30to50_->GetBinContent(2); 
  double QCD30to50_BD0p75 = scale_QCD30to50*NEventsCutsQCD30to50_->GetBinContent(3), QCD30to50_BD0p9 = scale_QCD30to50*NEventsCutsQCD30to50_->GetBinContent(4);
  double QCD30to50_ = scale_QCD30to50*NEventsCutsQCD30to50_->GetBinContent(5), QCD30to50_HT300 = scale_QCD30to50*NEventsCutsQCD30to50_->GetBinContent(6);
  double QCD30to50_HT400 = scale_QCD30to50*NEventsCutsQCD30to50_->GetBinContent(7), QCD30to50_HT300_BD0p75 = scale_QCD30to50*NEventsCutsQCD30to50_->GetBinContent(8); 
  double QCD30to50_HT400_BD0p5 = scale_QCD30to50*NEventsCutsQCD30to50_->GetBinContent(9), QCD30to50_IsoRaw0p5 = scale_QCD30to50*NEventsCutsQCD30to50_->GetBinContent(10);
  double QCD30to50_IsoRaw1p0 = scale_QCD30to50*NEventsCutsQCD30to50_->GetBinContent(11), QCD30to50_TightIso = scale_QCD30to50*NEventsCutsQCD30to50_->GetBinContent(12); 
  double QCD30to50_VTightIso = scale_QCD30to50*NEventsCutsQCD30to50_->GetBinContent(13);

  // Declare Bin counts for QCD50to80
  double QCD50to80_Total = scale_QCD50to80*NEventsCutsQCD50to80_->GetBinContent(1), QCD50to80_BD0p5 = scale_QCD50to80*NEventsCutsQCD50to80_->GetBinContent(2); 
  double QCD50to80_BD0p75 = scale_QCD50to80*NEventsCutsQCD50to80_->GetBinContent(3), QCD50to80_BD0p9 = scale_QCD50to80*NEventsCutsQCD50to80_->GetBinContent(4);
  double QCD50to80_ = scale_QCD50to80*NEventsCutsQCD50to80_->GetBinContent(5), QCD50to80_HT300 = scale_QCD50to80*NEventsCutsQCD50to80_->GetBinContent(6);
  double QCD50to80_HT400 = scale_QCD50to80*NEventsCutsQCD50to80_->GetBinContent(7), QCD50to80_HT300_BD0p75 = scale_QCD50to80*NEventsCutsQCD50to80_->GetBinContent(8); 
  double QCD50to80_HT400_BD0p5 = scale_QCD50to80*NEventsCutsQCD50to80_->GetBinContent(9), QCD50to80_IsoRaw0p5 = scale_QCD50to80*NEventsCutsQCD50to80_->GetBinContent(10);
  double QCD50to80_IsoRaw1p0 = scale_QCD50to80*NEventsCutsQCD50to80_->GetBinContent(11), QCD50to80_TightIso = scale_QCD50to80*NEventsCutsQCD50to80_->GetBinContent(12); 
  double QCD50to80_VTightIso = scale_QCD50to80*NEventsCutsQCD50to80_->GetBinContent(13);

  // Declare Bin counts for QCD80to120
  double QCD80to120_Total = scale_QCD80to120*NEventsCutsQCD80to120_->GetBinContent(1), QCD80to120_BD0p5 = scale_QCD80to120*NEventsCutsQCD80to120_->GetBinContent(2); 
  double QCD80to120_BD0p75 = scale_QCD80to120*NEventsCutsQCD80to120_->GetBinContent(3), QCD80to120_BD0p9 = scale_QCD80to120*NEventsCutsQCD80to120_->GetBinContent(4);
  double QCD80to120_ = scale_QCD80to120*NEventsCutsQCD80to120_->GetBinContent(5), QCD80to120_HT300 = scale_QCD80to120*NEventsCutsQCD80to120_->GetBinContent(6);
  double QCD80to120_HT400 = scale_QCD80to120*NEventsCutsQCD80to120_->GetBinContent(7), QCD80to120_HT300_BD0p75 = scale_QCD80to120*NEventsCutsQCD80to120_->GetBinContent(8); 
  double QCD80to120_HT400_BD0p5 = scale_QCD80to120*NEventsCutsQCD80to120_->GetBinContent(9), QCD80to120_IsoRaw0p5 = scale_QCD80to120*NEventsCutsQCD80to120_->GetBinContent(10);
  double QCD80to120_IsoRaw1p0 = scale_QCD80to120*NEventsCutsQCD80to120_->GetBinContent(11), QCD80to120_TightIso = scale_QCD80to120*NEventsCutsQCD80to120_->GetBinContent(12); 
  double QCD80to120_VTightIso = scale_QCD80to120*NEventsCutsQCD80to120_->GetBinContent(13);

  // Declare Bin counts for QCD120to170
  double QCD120to170_Total = scale_QCD120to170*NEventsCutsQCD120to170_->GetBinContent(1), QCD120to170_BD0p5 = scale_QCD120to170*NEventsCutsQCD120to170_->GetBinContent(2); 
  double QCD120to170_BD0p75 = scale_QCD120to170*NEventsCutsQCD120to170_->GetBinContent(3), QCD120to170_BD0p9 = scale_QCD120to170*NEventsCutsQCD120to170_->GetBinContent(4);
  double QCD120to170_ = scale_QCD120to170*NEventsCutsQCD120to170_->GetBinContent(5), QCD120to170_HT300 = scale_QCD120to170*NEventsCutsQCD120to170_->GetBinContent(6);
  double QCD120to170_HT400 = scale_QCD120to170*NEventsCutsQCD120to170_->GetBinContent(7), QCD120to170_HT300_BD0p75 = scale_QCD120to170*NEventsCutsQCD120to170_->GetBinContent(8); 
  double QCD120to170_HT400_BD0p5 = scale_QCD120to170*NEventsCutsQCD120to170_->GetBinContent(9), QCD120to170_IsoRaw0p5 = scale_QCD120to170*NEventsCutsQCD120to170_->GetBinContent(10);
  double QCD120to170_IsoRaw1p0 = scale_QCD120to170*NEventsCutsQCD120to170_->GetBinContent(11), QCD120to170_TightIso = scale_QCD120to170*NEventsCutsQCD120to170_->GetBinContent(12); 
  double QCD120to170_VTightIso = scale_QCD120to170*NEventsCutsQCD120to170_->GetBinContent(13);

  // Declare Bin counts for QCD170to300
  double QCD170to300_Total = scale_QCD170to300*NEventsCutsQCD170to300_->GetBinContent(1), QCD170to300_BD0p5 = scale_QCD170to300*NEventsCutsQCD170to300_->GetBinContent(2); 
  double QCD170to300_BD0p75 = scale_QCD170to300*NEventsCutsQCD170to300_->GetBinContent(3), QCD170to300_BD0p9 = scale_QCD170to300*NEventsCutsQCD170to300_->GetBinContent(4);
  double QCD170to300_ = scale_QCD170to300*NEventsCutsQCD170to300_->GetBinContent(5), QCD170to300_HT300 = scale_QCD170to300*NEventsCutsQCD170to300_->GetBinContent(6);
  double QCD170to300_HT400 = scale_QCD170to300*NEventsCutsQCD170to300_->GetBinContent(7), QCD170to300_HT300_BD0p75 = scale_QCD170to300*NEventsCutsQCD170to300_->GetBinContent(8); 
  double QCD170to300_HT400_BD0p5 = scale_QCD170to300*NEventsCutsQCD170to300_->GetBinContent(9), QCD170to300_IsoRaw0p5 = scale_QCD170to300*NEventsCutsQCD170to300_->GetBinContent(10);
  double QCD170to300_IsoRaw1p0 = scale_QCD170to300*NEventsCutsQCD170to300_->GetBinContent(11), QCD170to300_TightIso = scale_QCD170to300*NEventsCutsQCD170to300_->GetBinContent(12); 
  double QCD170to300_VTightIso = scale_QCD170to300*NEventsCutsQCD170to300_->GetBinContent(13);

  // Declare Bin counts for QCD300to470
  double QCD300to470_Total = scale_QCD300to470*NEventsCutsQCD300to470_->GetBinContent(1), QCD300to470_BD0p5 = scale_QCD300to470*NEventsCutsQCD300to470_->GetBinContent(2); 
  double QCD300to470_BD0p75 = scale_QCD300to470*NEventsCutsQCD300to470_->GetBinContent(3), QCD300to470_BD0p9 = scale_QCD300to470*NEventsCutsQCD300to470_->GetBinContent(4);
  double QCD300to470_ = scale_QCD300to470*NEventsCutsQCD300to470_->GetBinContent(5), QCD300to470_HT300 = scale_QCD300to470*NEventsCutsQCD300to470_->GetBinContent(6);
  double QCD300to470_HT400 = scale_QCD300to470*NEventsCutsQCD300to470_->GetBinContent(7), QCD300to470_HT300_BD0p75 = scale_QCD300to470*NEventsCutsQCD300to470_->GetBinContent(8); 
  double QCD300to470_HT400_BD0p5 = scale_QCD300to470*NEventsCutsQCD300to470_->GetBinContent(9), QCD300to470_IsoRaw0p5 = scale_QCD300to470*NEventsCutsQCD300to470_->GetBinContent(10);
  double QCD300to470_IsoRaw1p0 = scale_QCD300to470*NEventsCutsQCD300to470_->GetBinContent(11), QCD300to470_TightIso = scale_QCD300to470*NEventsCutsQCD300to470_->GetBinContent(12); 
  double QCD300to470_VTightIso = scale_QCD300to470*NEventsCutsQCD300to470_->GetBinContent(13);

  // Declare Bin counts for QCD470to600
  double QCD470to600_Total = scale_QCD470to600*NEventsCutsQCD470to600_->GetBinContent(1), QCD470to600_BD0p5 = scale_QCD470to600*NEventsCutsQCD470to600_->GetBinContent(2); 
  double QCD470to600_BD0p75 = scale_QCD470to600*NEventsCutsQCD470to600_->GetBinContent(3), QCD470to600_BD0p9 = scale_QCD470to600*NEventsCutsQCD470to600_->GetBinContent(4);
  double QCD470to600_ = scale_QCD470to600*NEventsCutsQCD470to600_->GetBinContent(5), QCD470to600_HT300 = scale_QCD470to600*NEventsCutsQCD470to600_->GetBinContent(6);
  double QCD470to600_HT400 = scale_QCD470to600*NEventsCutsQCD470to600_->GetBinContent(7), QCD470to600_HT300_BD0p75 = scale_QCD470to600*NEventsCutsQCD470to600_->GetBinContent(8); 
  double QCD470to600_HT400_BD0p5 = scale_QCD470to600*NEventsCutsQCD470to600_->GetBinContent(9), QCD470to600_IsoRaw0p5 = scale_QCD470to600*NEventsCutsQCD470to600_->GetBinContent(10);
  double QCD470to600_IsoRaw1p0 = scale_QCD470to600*NEventsCutsQCD470to600_->GetBinContent(11), QCD470to600_TightIso = scale_QCD470to600*NEventsCutsQCD470to600_->GetBinContent(12); 
  double QCD470to600_VTightIso = scale_QCD470to600*NEventsCutsQCD470to600_->GetBinContent(13);

  // Declare Bin counts for QCD600to800
  double QCD600to800_Total = scale_QCD600to800*NEventsCutsQCD600to800_->GetBinContent(1), QCD600to800_BD0p5 = scale_QCD600to800*NEventsCutsQCD600to800_->GetBinContent(2); 
  double QCD600to800_BD0p75 = scale_QCD600to800*NEventsCutsQCD600to800_->GetBinContent(3), QCD600to800_BD0p9 = scale_QCD600to800*NEventsCutsQCD600to800_->GetBinContent(4);
  double QCD600to800_ = scale_QCD600to800*NEventsCutsQCD600to800_->GetBinContent(5), QCD600to800_HT300 = scale_QCD600to800*NEventsCutsQCD600to800_->GetBinContent(6);
  double QCD600to800_HT400 = scale_QCD600to800*NEventsCutsQCD600to800_->GetBinContent(7), QCD600to800_HT300_BD0p75 = scale_QCD600to800*NEventsCutsQCD600to800_->GetBinContent(8); 
  double QCD600to800_HT400_BD0p5 = scale_QCD600to800*NEventsCutsQCD600to800_->GetBinContent(9), QCD600to800_IsoRaw0p5 = scale_QCD600to800*NEventsCutsQCD600to800_->GetBinContent(10);
  double QCD600to800_IsoRaw1p0 = scale_QCD600to800*NEventsCutsQCD600to800_->GetBinContent(11), QCD600to800_TightIso = scale_QCD600to800*NEventsCutsQCD600to800_->GetBinContent(12); 
  double QCD600to800_VTightIso = scale_QCD600to800*NEventsCutsQCD600to800_->GetBinContent(13);

  // Declare Bin counts for QCD800to1000
  double QCD800to1000_Total = scale_QCD800to1000*NEventsCutsQCD800to1000_->GetBinContent(1), QCD800to1000_BD0p5 = scale_QCD800to1000*NEventsCutsQCD800to1000_->GetBinContent(2); 
  double QCD800to1000_BD0p75 = scale_QCD800to1000*NEventsCutsQCD800to1000_->GetBinContent(3), QCD800to1000_BD0p9 = scale_QCD800to1000*NEventsCutsQCD800to1000_->GetBinContent(4);
  double QCD800to1000_ = scale_QCD800to1000*NEventsCutsQCD800to1000_->GetBinContent(5), QCD800to1000_HT300 = scale_QCD800to1000*NEventsCutsQCD800to1000_->GetBinContent(6);
  double QCD800to1000_HT400 = scale_QCD800to1000*NEventsCutsQCD800to1000_->GetBinContent(7), QCD800to1000_HT300_BD0p75 = scale_QCD800to1000*NEventsCutsQCD800to1000_->GetBinContent(8); 
  double QCD800to1000_HT400_BD0p5 = scale_QCD800to1000*NEventsCutsQCD800to1000_->GetBinContent(9), QCD800to1000_IsoRaw0p5 = scale_QCD800to1000*NEventsCutsQCD800to1000_->GetBinContent(10);
  double QCD800to1000_IsoRaw1p0 = scale_QCD800to1000*NEventsCutsQCD800to1000_->GetBinContent(11), QCD800to1000_TightIso = scale_QCD800to1000*NEventsCutsQCD800to1000_->GetBinContent(12); 
  double QCD800to1000_VTightIso = scale_QCD800to1000*NEventsCutsQCD800to1000_->GetBinContent(13);

  // Declare Bin counts for QCD1000toInf
  double QCD1000toInf_Total = scale_QCD1000toInf*NEventsCutsQCD1000toInf_->GetBinContent(1), QCD1000toInf_BD0p5 = scale_QCD1000toInf*NEventsCutsQCD1000toInf_->GetBinContent(2); 
  double QCD1000toInf_BD0p75 = scale_QCD1000toInf*NEventsCutsQCD1000toInf_->GetBinContent(3), QCD1000toInf_BD0p9 = scale_QCD1000toInf*NEventsCutsQCD1000toInf_->GetBinContent(4);
  double QCD1000toInf_ = scale_QCD1000toInf*NEventsCutsQCD1000toInf_->GetBinContent(5), QCD1000toInf_HT300 = scale_QCD1000toInf*NEventsCutsQCD1000toInf_->GetBinContent(6);
  double QCD1000toInf_HT400 = scale_QCD1000toInf*NEventsCutsQCD1000toInf_->GetBinContent(7), QCD1000toInf_HT300_BD0p75 = scale_QCD1000toInf*NEventsCutsQCD1000toInf_->GetBinContent(8);
  double QCD1000toInf_HT400_BD0p5 = scale_QCD1000toInf*NEventsCutsQCD1000toInf_->GetBinContent(9), QCD1000toInf_IsoRaw0p5 = scale_QCD1000toInf*NEventsCutsQCD1000toInf_->GetBinContent(10); 
  double QCD1000toInf_IsoRaw1p0 = scale_QCD1000toInf*NEventsCutsQCD1000toInf_->GetBinContent(11), QCD1000toInf_TightIso = scale_QCD1000toInf*NEventsCutsQCD1000toInf_->GetBinContent(12);
  double QCD1000toInf_VTightIso = scale_QCD1000toInf*NEventsCutsQCD1000toInf_->GetBinContent(13);

  // Declare Bin counts for DYH
  double DYH_Total = scale_DYH*NEventsCutsDYH_->GetBinContent(1), DYH_BD0p5 = scale_DYH*NEventsCutsDYH_->GetBinContent(2), DYH_BD0p75 = scale_DYH*NEventsCutsDYH_->GetBinContent(3);
  double DYH_BD0p9 = scale_DYH*NEventsCutsDYH_->GetBinContent(4);
  double DYH_ = scale_DYH*NEventsCutsDYH_->GetBinContent(5), DYH_HT300 = scale_DYH*NEventsCutsDYH_->GetBinContent(6), DYH_HT400 = scale_DYH*NEventsCutsDYH_->GetBinContent(7);
  double DYH_HT300_BD0p75 = scale_DYH*NEventsCutsDYH_->GetBinContent(8), DYH_HT400_BD0p5 = scale_DYH*NEventsCutsDYH_->GetBinContent(9), DYH_IsoRaw0p5 = scale_DYH*NEventsCutsDYH_->GetBinContent(10);
  double DYH_IsoRaw1p0 = scale_DYH*NEventsCutsDYH_->GetBinContent(11), DYH_TightIso = scale_DYH*NEventsCutsDYH_->GetBinContent(12), DYH_VTightIso = scale_DYH*NEventsCutsDYH_->GetBinContent(13);

  // Declare Bin counts for DYL
  double DYL_Total = scale_DYL*NEventsCutsDYL_->GetBinContent(1), DYL_BD0p5 = scale_DYL*NEventsCutsDYL_->GetBinContent(2), DYL_BD0p75 = scale_DYL*NEventsCutsDYL_->GetBinContent(3);
  double DYL_BD0p9 = scale_DYL*NEventsCutsDYL_->GetBinContent(4);
  double DYL_ = scale_DYL*NEventsCutsDYL_->GetBinContent(5), DYL_HT300 = scale_DYL*NEventsCutsDYL_->GetBinContent(6), DYL_HT400 = scale_DYL*NEventsCutsDYL_->GetBinContent(7);
  double DYL_HT300_BD0p75 = scale_DYL*NEventsCutsDYL_->GetBinContent(8), DYL_HT400_BD0p5 = scale_DYL*NEventsCutsDYL_->GetBinContent(9), DYL_IsoRaw0p5 = scale_DYL*NEventsCutsDYL_->GetBinContent(10); 
  double DYL_IsoRaw1p0 = scale_DYL*NEventsCutsDYL_->GetBinContent(11), DYL_TightIso = scale_DYL*NEventsCutsDYL_->GetBinContent(12), DYL_VTightIso = scale_DYL*NEventsCutsDYL_->GetBinContent(13);

  // Declare Bin counts for H125a19
  double H125a19_Total = scale_H125a19*NEventsCutsH125a19_->GetBinContent(1), H125a19_BD0p5 = scale_H125a19*NEventsCutsH125a19_->GetBinContent(2);
  double H125a19_BD0p75 = scale_H125a19*NEventsCutsH125a19_->GetBinContent(3), H125a19_BD0p9 = scale_H125a19*NEventsCutsH125a19_->GetBinContent(4);
  double H125a19_ = scale_H125a19*NEventsCutsH125a19_->GetBinContent(5), H125a19_HT300 = scale_H125a19*NEventsCutsH125a19_->GetBinContent(6);
  double H125a19_HT400 = scale_H125a19*NEventsCutsH125a19_->GetBinContent(7), H125a19_HT300_BD0p75 = scale_H125a19*NEventsCutsH125a19_->GetBinContent(8);
  double H125a19_HT400_BD0p5 = scale_H125a19*NEventsCutsH125a19_->GetBinContent(9), H125a19_IsoRaw0p5 = scale_H125a19*NEventsCutsH125a19_->GetBinContent(10); 
  double H125a19_IsoRaw1p0 = scale_H125a19*NEventsCutsH125a19_->GetBinContent(11), H125a19_TightIso = scale_H125a19*NEventsCutsH125a19_->GetBinContent(12);
  double H125a19_VTightIso = scale_H125a19*NEventsCutsH125a19_->GetBinContent(13);

  // Declare Bin counts for H125a9
  double H125a9_Total = scale_H125a9*NEventsCutsH125a9_->GetBinContent(1), H125a9_BD0p5 = scale_H125a9*NEventsCutsH125a9_->GetBinContent(2);
  double H125a9_BD0p75 = scale_H125a9*NEventsCutsH125a9_->GetBinContent(3), H125a9_BD0p9 = scale_H125a9*NEventsCutsH125a9_->GetBinContent(4);
  double H125a9_ = scale_H125a9*NEventsCutsH125a9_->GetBinContent(5), H125a9_HT300 = scale_H125a9*NEventsCutsH125a9_->GetBinContent(6);
  double H125a9_HT400 = scale_H125a9*NEventsCutsH125a9_->GetBinContent(7), H125a9_HT300_BD0p75 = scale_H125a9*NEventsCutsH125a9_->GetBinContent(8);
  double H125a9_HT400_BD0p5 = scale_H125a9*NEventsCutsH125a9_->GetBinContent(9), H125a9_IsoRaw0p5 = scale_H125a9*NEventsCutsH125a9_->GetBinContent(10); 
  double H125a9_IsoRaw1p0 = scale_H125a9*NEventsCutsH125a9_->GetBinContent(11), H125a9_TightIso = scale_H125a9*NEventsCutsH125a9_->GetBinContent(12);
  double H125a9_VTightIso = scale_H125a9*NEventsCutsH125a9_->GetBinContent(13);

  // Declare Bin counts for H125a5
  double H125a5_Total = scale_H125a5*NEventsCutsH125a5_->GetBinContent(1), H125a5_BD0p5 = scale_H125a5*NEventsCutsH125a5_->GetBinContent(2);
  double H125a5_BD0p75 = scale_H125a5*NEventsCutsH125a5_->GetBinContent(3), H125a5_BD0p9 = scale_H125a5*NEventsCutsH125a5_->GetBinContent(4);
  double H125a5_ = scale_H125a5*NEventsCutsH125a5_->GetBinContent(5), H125a5_HT300 = scale_H125a5*NEventsCutsH125a5_->GetBinContent(6);
  double H125a5_HT400 = scale_H125a5*NEventsCutsH125a5_->GetBinContent(7), H125a5_HT300_BD0p75 = scale_H125a5*NEventsCutsH125a5_->GetBinContent(8);
  double H125a5_HT400_BD0p5 = scale_H125a5*NEventsCutsH125a5_->GetBinContent(9), H125a5_IsoRaw0p5 = scale_H125a5*NEventsCutsH125a5_->GetBinContent(10); 
  double H125a5_IsoRaw1p0 = scale_H125a5*NEventsCutsH125a5_->GetBinContent(11), H125a5_TightIso = scale_H125a5*NEventsCutsH125a5_->GetBinContent(12); 
  double H125a5_VTightIso = scale_H125a5*NEventsCutsH125a5_->GetBinContent(13);

  // Declare Bin counts for H750a9
  double H750a9_Total = scale_H750a9*NEventsCutsH750a9_->GetBinContent(1), H750a9_BD0p5 = scale_H750a9*NEventsCutsH750a9_->GetBinContent(2);
  double H750a9_BD0p75 = scale_H750a9*NEventsCutsH750a9_->GetBinContent(3),  H750a9_BD0p9 = scale_H750a9*NEventsCutsH750a9_->GetBinContent(4);
  double H750a9_ = scale_H750a9*NEventsCutsH750a9_->GetBinContent(5), H750a9_HT300 = scale_H750a9*NEventsCutsH750a9_->GetBinContent(6);
  double H750a9_HT400 = scale_H750a9*NEventsCutsH750a9_->GetBinContent(7), H750a9_HT300_BD0p75 = scale_H750a9*NEventsCutsH750a9_->GetBinContent(8);
  double H750a9_HT400_BD0p5 = scale_H750a9*NEventsCutsH750a9_->GetBinContent(9), H750a9_IsoRaw0p5 = scale_H750a9*NEventsCutsH750a9_->GetBinContent(10); 
  double H750a9_IsoRaw1p0 = scale_H750a9*NEventsCutsH750a9_->GetBinContent(11), H750a9_TightIso = scale_H750a9*NEventsCutsH750a9_->GetBinContent(12);
  double H750a9_VTightIso = scale_H750a9*NEventsCutsH750a9_->GetBinContent(13);

  // Getting combined QCD events counts
  double QCD_Total = QCD15to20_Total + QCD20to30_Total + QCD30to50_Total + QCD50to80_Total + QCD80to120_Total + QCD120to170_Total + QCD170to300_Total + QCD300to470_Total + QCD470to600_Total + QCD600to800_Total + QCD800to1000_Total + QCD1000toInf_Total;
  double QCD_BD0p5 = QCD15to20_Total + QCD20to30_Total + QCD30to50_Total + QCD50to80_Total + QCD80to120_Total + QCD120to170_Total + QCD170to300_Total + QCD300to470_Total + QCD470to600_Total + QCD600to800_Total + QCD800to1000_Total + QCD1000toInf_Total;
  double QCD_BD0p75 =QCD15to20_Total + QCD20to30_Total + QCD30to50_Total + QCD50to80_Total + QCD80to120_Total + QCD120to170_Total + QCD170to300_Total + QCD300to470_Total + QCD470to600_Total + QCD600to800_Total + QCD800to1000_Total + QCD1000toInf_Total;
  double QCD_BD0p9 = QCD15to20_Total + QCD20to30_Total + QCD30to50_Total + QCD50to80_Total + QCD80to120_Total + QCD120to170_Total + QCD170to300_Total + QCD300to470_Total + QCD470to600_Total + QCD600to800_Total + QCD800to1000_Total + QCD1000toInf_Total;
//  double QCD_ =  QCD15to20_Total + QCD20to30_Total + QCD30to50_Total + QCD50to80_Total + QCD80to120_Total + QCD120to170_Total + QCD170to300_Total + QCD300to470_Total + QCD470to600_Total + QCD600to800_Total + QCD800to1000_Total + QCD1000toInf_Total;
  double QCD_HT300 = QCD15to20_Total + QCD20to30_Total + QCD30to50_Total + QCD50to80_Total + QCD80to120_Total + QCD120to170_Total + QCD170to300_Total + QCD300to470_Total + QCD470to600_Total + QCD600to800_Total + QCD800to1000_Total + QCD1000toInf_Total;
  double QCD_HT400 = QCD15to20_Total + QCD20to30_Total + QCD30to50_Total + QCD50to80_Total + QCD80to120_Total + QCD120to170_Total + QCD170to300_Total + QCD300to470_Total + QCD470to600_Total + QCD600to800_Total + QCD800to1000_Total + QCD1000toInf_Total;
  double QCD_HT300_BD0p75 = QCD15to20_Total + QCD20to30_Total + QCD30to50_Total + QCD50to80_Total + QCD80to120_Total + QCD120to170_Total + QCD170to300_Total + QCD300to470_Total + QCD470to600_Total + QCD600to800_Total + QCD800to1000_Total + QCD1000toInf_Total;
  double QCD_HT400_BD0p5 =  QCD15to20_Total + QCD20to30_Total + QCD30to50_Total + QCD50to80_Total + QCD80to120_Total + QCD120to170_Total + QCD170to300_Total + QCD300to470_Total + QCD470to600_Total + QCD600to800_Total + QCD800to1000_Total + QCD1000toInf_Total;
  double QCD_IsoRaw0p5 =  QCD15to20_Total + QCD20to30_Total + QCD30to50_Total + QCD50to80_Total + QCD80to120_Total + QCD120to170_Total + QCD170to300_Total + QCD300to470_Total + QCD470to600_Total + QCD600to800_Total + QCD800to1000_Total + QCD1000toInf_Total;
  double QCD_IsoRaw1p0 =  QCD15to20_Total + QCD20to30_Total + QCD30to50_Total + QCD50to80_Total + QCD80to120_Total + QCD120to170_Total + QCD170to300_Total + QCD300to470_Total + QCD470to600_Total + QCD600to800_Total + QCD800to1000_Total + QCD1000toInf_Total;
  double QCD_TightIso =  QCD15to20_Total + QCD20to30_Total + QCD30to50_Total + QCD50to80_Total + QCD80to120_Total + QCD120to170_Total + QCD170to300_Total + QCD300to470_Total + QCD470to600_Total + QCD600to800_Total + QCD800to1000_Total + QCD1000toInf_Total;
  double QCD_VTightIso = QCD15to20_Total + QCD20to30_Total + QCD30to50_Total + QCD50to80_Total + QCD80to120_Total + QCD120to170_Total + QCD170to300_Total + QCD300to470_Total + QCD470to600_Total + QCD600to800_Total + QCD800to1000_Total + QCD1000toInf_Total;


  //////////////////////////
  // Cut Info
  //////////////////////////
  infoFile << "################################################\n## Cut Info for New DM No MVA \n################################################\n" << endl;
  infoFile << NEventsCutsTT_->GetXaxis()->GetBinLabel(1) << "\t: DYHigh= " << DYH_Total << "\tDYLow= " << DYL_Total << "\tQCD= " << QCD_Total << "\tTT= " << TT_Total <<  "\tH125a19= " << H125a19_Total << "\tH125a9= " << H125a9_Total << "\tH125a5= " << H125a5_Total << "\tH750a9= " << H750a9_Total << std::endl;
  infoFile << NEventsCutsTT_->GetXaxis()->GetBinLabel(2) << "\t: DYHigh= " << DYH_BD0p5 << "\tDYLow= " << DYL_BD0p5 << "\tQCD= " << QCD_BD0p5 << "\tTT= " << TT_BD0p5 <<  "\tH125a19= " << H125a19_BD0p5 << "\tH125a9= " << H125a9_BD0p5 << "\tH125a5= " << H125a5_BD0p5 << "\tH750a9= " << H750a9_BD0p5 << std::endl;
  infoFile << NEventsCutsTT_->GetXaxis()->GetBinLabel(3) << "\t: DYHigh= " << DYH_BD0p75 << "\tDYLow= " << DYL_BD0p75 << "\tQCD= " << QCD_BD0p75 << "\tTT= " << TT_BD0p75 << "\tH125a19= " << H125a19_BD0p75 << "\tH125a9= " << H125a9_BD0p75 << "\tH125a5= " << H125a5_BD0p75 << "\tH750a9= " << H750a9_BD0p75 << std::endl;
  infoFile << NEventsCutsTT_->GetXaxis()->GetBinLabel(4) << "\t: DYHigh= " << DYH_BD0p9 << "\tDYLow= " << DYL_BD0p9 << "\tQCD= " << QCD_BD0p9 << "\tTT= " << TT_BD0p9 << "\tH125a19= " << H125a19_BD0p9 << "\tH125a9= " << H125a9_BD0p9 << "\tH125a5= " << H125a5_BD0p9 << "\tH750a9= " << H750a9_BD0p9 << std::endl;
//  infoFile << NEventsCutsTT_->GetXaxis()->GetBinLabel(5) << "\t: DYHigh= " << DYH_Total << "\tDYLow= " << DYL_Total << "\tQCD= " << QCD_Total << "\tTT= " << TT_Total << "\tH125a19= " << H125a19_Total << "\tH125a9= " << H125a9_Total << "\tH125a5= " << H125a5_Total << "\tH750a9= " << H750a9_Total << std::endl;
  infoFile << NEventsCutsTT_->GetXaxis()->GetBinLabel(6) << "\t: DYHigh= " << DYH_HT300 << "\tDYLow= " << DYL_HT300 << "\tQCD= " << QCD_HT300 << "\tTT= " << TT_HT300 <<  "\tH125a19= " << H125a19_HT300 << "\tH125a9= " << H125a9_HT300 << "\tH125a5= " << H125a5_HT300 << "\tH750a9= " << H750a9_HT300 << std::endl;
  infoFile << NEventsCutsTT_->GetXaxis()->GetBinLabel(7) << "\t: DYHigh= " << DYH_HT400 << "\tDYLow= " << DYL_HT400 << "\tQCD= " << QCD_HT400 << "\tTT= " << TT_HT400 <<  "\tH125a19= " << H125a19_HT400 << "\tH125a9= " << H125a9_HT400 << "\tH125a5= " << H125a5_HT400 << "\tH750a9= " << H750a9_HT400 << std::endl;
  infoFile << NEventsCutsTT_->GetXaxis()->GetBinLabel(8) << "\t: DYHigh= " << DYH_HT300_BD0p75 << "\tDYLow= " << DYL_HT300_BD0p75 << "\tQCD= " << QCD_HT300_BD0p75 << "\tTT= " << TT_HT300_BD0p75 << "\tH125a19= " << H125a19_HT300_BD0p75 << "\tH125a9= " << H125a9_HT300_BD0p75 << "\tH125a5= " << H125a5_HT300_BD0p75 << "\tH750a9= " << H750a9_HT300_BD0p75 << std::endl;
  infoFile << NEventsCutsTT_->GetXaxis()->GetBinLabel(9) << "\t: DYHigh= " << DYH_HT400_BD0p5 << "\tDYLow= " << DYL_HT400_BD0p5 << "\tQCD= " << QCD_HT400_BD0p5 << "\tTT= " << TT_HT400_BD0p5 << "\tH125a19= " << H125a19_HT400_BD0p5 << "\tH125a9= " << H125a9_HT400_BD0p5 << "\tH125a5= " << H125a5_HT400_BD0p5 << "\tH750a9= " << H750a9_HT400_BD0p5 << std::endl;
  infoFile << NEventsCutsTT_->GetXaxis()->GetBinLabel(10) << "\t: DYHigh= " << DYH_IsoRaw0p5 << "\tDYLow= " << DYL_IsoRaw0p5 << "\tQCD= " << QCD_IsoRaw0p5 << "\tTT= " << TT_IsoRaw0p5 << "\tH125a19= " << H125a19_IsoRaw0p5 << "\tH125a9= " << H125a9_IsoRaw0p5 << "\tH125a5= " << H125a5_IsoRaw0p5 << "\tH750a9= " << H750a9_IsoRaw0p5 << std::endl;
  infoFile << NEventsCutsTT_->GetXaxis()->GetBinLabel(11) << "\t: DYHigh= " << DYH_IsoRaw1p0 << "\tDYLow= " << DYL_IsoRaw1p0 << "\tQCD= " << QCD_IsoRaw1p0 << "\tTT= " << TT_IsoRaw1p0 << "\tH125a19= " << H125a19_IsoRaw1p0 << "\tH125a9= " << H125a9_IsoRaw1p0 << "\tH125a5= " << H125a5_IsoRaw1p0 << "\tH750a9= " << H750a9_IsoRaw1p0 << std::endl;
  infoFile << NEventsCutsTT_->GetXaxis()->GetBinLabel(12) << "\t: DYHigh= " << DYH_TightIso << "\tDYLow= " << DYL_TightIso << "\tQCD= " << QCD_TightIso << "\tTT= " << TT_TightIso << "\tH125a19= " << H125a19_TightIso << "\tH125a9= " << H125a9_TightIso << "\tH125a5= " << H125a5_TightIso << "\tH750a9= " << H750a9_TightIso << std::endl;
  infoFile << NEventsCutsTT_->GetXaxis()->GetBinLabel(13) << "\t: DYHigh= " << DYH_VTightIso << "\tDYLow= " << DYL_VTightIso << "\tQCD= " << QCD_VTightIso << "\tTT= " << TT_VTightIso << "\tH125a19= " << H125a19_VTightIso << "\tH125a9= " << H125a9_VTightIso << "\tH125a5= " << H125a5_VTightIso << "\tH750a9= " << H750a9_VTightIso << std::endl;

/////////////////////////////
// Prepping the output plots
/////////////////////////////
  TCanvas TauMuTauHaddRCanvas("TauMuTauHaddR","",600,600);
  TCanvas MassDiMuRECOCanvas("MassDiMuRECO","",600,600);
  TCanvas MassDiTauCanvas("MassDiTau","",600,600);
  TCanvas PtOverMassMu1Mu2Canvas("PtOverMassMu1Mu2","",600,600);
  TCanvas PtTauMuCanvas("PtTauMu","",600,600);
  TCanvas PtMu1Mu2Canvas("PtMu1Mu2","",600,600);
  TCanvas PCSVBDiscCanvas("PCSVBDisc","",600,600);
  TCanvas SumHTCanvas("SumHT","",600,600);
  TCanvas IsoRawCanvas("IsoRaw","",600,600);
  TCanvas RelIsoRawCanvas("RelIsoRaw","",600,600);
  TCanvas IsoRawCutBasedCanvas("IsoRawCutBased","",600,600);

  TauMuTauHaddRCanvas.SetGrid(1,1);
  MassDiMuRECOCanvas.SetGrid(1,1);
  MassDiTauCanvas.SetGrid(1,1);
  PtOverMassMu1Mu2Canvas.SetGrid(1,1);
  PtTauMuCanvas.SetGrid(1,1);
  PtMu1Mu2Canvas.SetGrid(1,1);
  PCSVBDiscCanvas.SetGrid(1,1);
  SumHTCanvas.SetGrid(1,1);
  IsoRawCanvas.SetGrid(1,1);
  RelIsoRawCanvas.SetGrid(1,1);
  IsoRawCutBasedCanvas.SetGrid(1,1);

  ////////////////
  // QCD combined
  ////////////////
  TCanvas TauMuTauHaddRCanvasQCD("TauMuTauHaddR","",600,600);
  TCanvas MassDiMuRECOCanvasQCD("MassDiMuRECO","",600,600);
  TCanvas MassDiTauCanvasQCD("MassDiTau","",600,600);
  TCanvas PtOverMassMu1Mu2CanvasQCD("PtOverMassMu1Mu2","",600,600);
  TCanvas PtTauMuCanvasQCD("PtTauMu","",600,600);
  TCanvas PtMu1Mu2CanvasQCD("PtMu1Mu2","",600,600);
  TCanvas PCSVBDiscCanvasQCD("PCSVBDisc","",600,600);
  TCanvas SumHTCanvasQCD("SumHT","",600,600);
  TCanvas IsoRawCanvasQCD("IsoRaw","",600,600);
  TCanvas RelIsoRawCanvasQCD("RelIsoRaw","",600,600);
  TCanvas IsoRawCutBasedCanvasQCD("IsoRawCutBased","",600,600);

  TCanvas NEventsCutsCanvasQCD("NEventsCuts","",600,600);

  TH1F*  TauMuTauHaddRQCD_ = new TH1F("TauMuTauHaddR","", TauMuTauHaddRQCD15to20_->GetNbinsX(), 0, TauMuTauHaddRQCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  MassDiMuRECOQCD_ = new TH1F("MassDiMuRECO","", MassDiMuRECOQCD15to20_->GetNbinsX(), 0, MassDiMuRECOQCD15to20_->GetXaxis()->GetXmax() );
  Float_t bins[] = {0, 1, 2, 3, 4, 20};
  TH1F*  MassDiTauQCD_ = new TH1F("MassDiTau","", sizeof(bins)/sizeof(Float_t) - 1, bins); 
  TH1F*  PtOverMassMu1Mu2QCD_ = new TH1F("PtOverMassMu1Mu2","", PtOverMassMu1Mu2QCD15to20_->GetNbinsX(), 0, PtOverMassMu1Mu2QCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  PtTauMuQCD_  = new TH1F("PtTauMu","", PtTauMuQCD15to20_->GetNbinsX(), 0, PtTauMuQCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  PtMu1Mu2QCD_  = new TH1F("PtMu1Mu2","", PtMu1Mu2QCD15to20_->GetNbinsX(), 0, PtMu1Mu2QCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  PCSVBDiscQCD_ = new TH1F("PCSVBDisc","", PCSVBDiscQCD15to20_->GetNbinsX(), 0, PCSVBDiscQCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  SumHTQCD_     = new TH1F("SumHT","", SumHTQCD15to20_->GetNbinsX(), 0, SumHTQCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  IsoRawQCD_    = new TH1F("IsoRaw","", IsoRawQCD15to20_->GetNbinsX(), 0, IsoRawQCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  RelIsoRawQCD_    = new TH1F("RelIsoRaw","", RelIsoRawQCD15to20_->GetNbinsX(), 0, RelIsoRawQCD15to20_->GetXaxis()->GetXmax() );
  TH1F*  IsoRawCutBasedQCD_    = new TH1F("IsoRawCutBased","", IsoRawCutBasedQCD15to20_->GetNbinsX(), 0, IsoRawCutBasedQCD15to20_->GetXaxis()->GetXmax() );


  TH1F*  NEventsCutsQCD_ = new TH1F("NEventsCuts","", NEventsCutsQCD15to20_->GetNbinsX(), -.5, NEventsCutsQCD15to20_->GetXaxis()->GetXmax() ); 

  TauMuTauHaddRCanvasQCD.cd();
  TauMuTauHaddRQCD_->Add(TauMuTauHaddRQCD15to20_);
  TauMuTauHaddRQCD_->Add(TauMuTauHaddRQCD20to30_);
  TauMuTauHaddRQCD_->Add(TauMuTauHaddRQCD30to50_);
  TauMuTauHaddRQCD_->Add(TauMuTauHaddRQCD50to80_);
  TauMuTauHaddRQCD_->Add(TauMuTauHaddRQCD80to120_);
  TauMuTauHaddRQCD_->Add(TauMuTauHaddRQCD120to170_);
  TauMuTauHaddRQCD_->Add(TauMuTauHaddRQCD170to300_);
  TauMuTauHaddRQCD_->Add(TauMuTauHaddRQCD300to470_);
  TauMuTauHaddRQCD_->Add(TauMuTauHaddRQCD470to600_);
  TauMuTauHaddRQCD_->Add(TauMuTauHaddRQCD600to800_);
  TauMuTauHaddRQCD_->Add(TauMuTauHaddRQCD800to1000_);
  TauMuTauHaddRQCD_->Add(TauMuTauHaddRQCD1000toInf_);

  MassDiMuRECOCanvasQCD.cd();
  MassDiMuRECOQCD_->Add(MassDiMuRECOQCD15to20_);
  MassDiMuRECOQCD_->Add(MassDiMuRECOQCD20to30_);
  MassDiMuRECOQCD_->Add(MassDiMuRECOQCD30to50_);
  MassDiMuRECOQCD_->Add(MassDiMuRECOQCD50to80_);
  MassDiMuRECOQCD_->Add(MassDiMuRECOQCD80to120_);
  MassDiMuRECOQCD_->Add(MassDiMuRECOQCD120to170_);
  MassDiMuRECOQCD_->Add(MassDiMuRECOQCD170to300_);
  MassDiMuRECOQCD_->Add(MassDiMuRECOQCD300to470_);
  MassDiMuRECOQCD_->Add(MassDiMuRECOQCD470to600_);
  MassDiMuRECOQCD_->Add(MassDiMuRECOQCD600to800_);
  MassDiMuRECOQCD_->Add(MassDiMuRECOQCD800to1000_);
  MassDiMuRECOQCD_->Add(MassDiMuRECOQCD1000toInf_);

  MassDiTauCanvasQCD.cd();
  MassDiTauQCD_->Add(MassDiTauQCD15to20_);
  MassDiTauQCD_->Add(MassDiTauQCD20to30_);
  MassDiTauQCD_->Add(MassDiTauQCD30to50_);
  MassDiTauQCD_->Add(MassDiTauQCD50to80_);
  MassDiTauQCD_->Add(MassDiTauQCD80to120_);
  MassDiTauQCD_->Add(MassDiTauQCD120to170_);
  MassDiTauQCD_->Add(MassDiTauQCD170to300_);
  MassDiTauQCD_->Add(MassDiTauQCD300to470_);
  MassDiTauQCD_->Add(MassDiTauQCD470to600_);
  MassDiTauQCD_->Add(MassDiTauQCD600to800_);
  MassDiTauQCD_->Add(MassDiTauQCD800to1000_);
  MassDiTauQCD_->Add(MassDiTauQCD1000toInf_);

  PtOverMassMu1Mu2CanvasQCD.cd();
  PtOverMassMu1Mu2QCD_->Add(PtOverMassMu1Mu2QCD15to20_);
  PtOverMassMu1Mu2QCD_->Add(PtOverMassMu1Mu2QCD20to30_);
  PtOverMassMu1Mu2QCD_->Add(PtOverMassMu1Mu2QCD30to50_);
  PtOverMassMu1Mu2QCD_->Add(PtOverMassMu1Mu2QCD50to80_);
  PtOverMassMu1Mu2QCD_->Add(PtOverMassMu1Mu2QCD80to120_);
  PtOverMassMu1Mu2QCD_->Add(PtOverMassMu1Mu2QCD120to170_);
  PtOverMassMu1Mu2QCD_->Add(PtOverMassMu1Mu2QCD170to300_);
  PtOverMassMu1Mu2QCD_->Add(PtOverMassMu1Mu2QCD300to470_);
  PtOverMassMu1Mu2QCD_->Add(PtOverMassMu1Mu2QCD470to600_);
  PtOverMassMu1Mu2QCD_->Add(PtOverMassMu1Mu2QCD600to800_);
  PtOverMassMu1Mu2QCD_->Add(PtOverMassMu1Mu2QCD800to1000_);
  PtOverMassMu1Mu2QCD_->Add(PtOverMassMu1Mu2QCD1000toInf_);

  PtTauMuCanvasQCD.cd();
  PtTauMuQCD_->Add(PtTauMuQCD15to20_);
  PtTauMuQCD_->Add(PtTauMuQCD20to30_);
  PtTauMuQCD_->Add(PtTauMuQCD30to50_);
  PtTauMuQCD_->Add(PtTauMuQCD50to80_);
  PtTauMuQCD_->Add(PtTauMuQCD80to120_);
  PtTauMuQCD_->Add(PtTauMuQCD120to170_);
  PtTauMuQCD_->Add(PtTauMuQCD170to300_);
  PtTauMuQCD_->Add(PtTauMuQCD300to470_);
  PtTauMuQCD_->Add(PtTauMuQCD470to600_);
  PtTauMuQCD_->Add(PtTauMuQCD600to800_);
  PtTauMuQCD_->Add(PtTauMuQCD800to1000_);
  PtTauMuQCD_->Add(PtTauMuQCD1000toInf_);

  PtMu1Mu2CanvasQCD.cd();
  PtMu1Mu2QCD_->Add(PtMu1Mu2QCD15to20_);
  PtMu1Mu2QCD_->Add(PtMu1Mu2QCD20to30_);
  PtMu1Mu2QCD_->Add(PtMu1Mu2QCD30to50_);
  PtMu1Mu2QCD_->Add(PtMu1Mu2QCD50to80_);
  PtMu1Mu2QCD_->Add(PtMu1Mu2QCD80to120_);
  PtMu1Mu2QCD_->Add(PtMu1Mu2QCD120to170_);
  PtMu1Mu2QCD_->Add(PtMu1Mu2QCD170to300_);
  PtMu1Mu2QCD_->Add(PtMu1Mu2QCD300to470_);
  PtMu1Mu2QCD_->Add(PtMu1Mu2QCD470to600_);
  PtMu1Mu2QCD_->Add(PtMu1Mu2QCD600to800_);
  PtMu1Mu2QCD_->Add(PtMu1Mu2QCD800to1000_);
  PtMu1Mu2QCD_->Add(PtMu1Mu2QCD1000toInf_);


  PCSVBDiscCanvasQCD.cd();
  PCSVBDiscQCD_->Add(PCSVBDiscQCD15to20_);
  PCSVBDiscQCD_->Add(PCSVBDiscQCD20to30_);
  PCSVBDiscQCD_->Add(PCSVBDiscQCD30to50_);
  PCSVBDiscQCD_->Add(PCSVBDiscQCD50to80_);
  PCSVBDiscQCD_->Add(PCSVBDiscQCD80to120_);
  PCSVBDiscQCD_->Add(PCSVBDiscQCD120to170_);
  PCSVBDiscQCD_->Add(PCSVBDiscQCD170to300_);
  PCSVBDiscQCD_->Add(PCSVBDiscQCD300to470_);
  PCSVBDiscQCD_->Add(PCSVBDiscQCD470to600_);
  PCSVBDiscQCD_->Add(PCSVBDiscQCD600to800_);
  PCSVBDiscQCD_->Add(PCSVBDiscQCD800to1000_);
  PCSVBDiscQCD_->Add(PCSVBDiscQCD1000toInf_);

  SumHTCanvasQCD.cd();
  SumHTQCD_->Add(SumHTQCD15to20_);
  SumHTQCD_->Add(SumHTQCD20to30_);
  SumHTQCD_->Add(SumHTQCD30to50_);
  SumHTQCD_->Add(SumHTQCD50to80_);
  SumHTQCD_->Add(SumHTQCD80to120_);
  SumHTQCD_->Add(SumHTQCD120to170_);
  SumHTQCD_->Add(SumHTQCD170to300_);
  SumHTQCD_->Add(SumHTQCD300to470_);
  SumHTQCD_->Add(SumHTQCD470to600_);
  SumHTQCD_->Add(SumHTQCD600to800_);
  SumHTQCD_->Add(SumHTQCD800to1000_);
  SumHTQCD_->Add(SumHTQCD1000toInf_);

  IsoRawCanvasQCD.cd();
  IsoRawQCD_->Add(IsoRawQCD15to20_);
  IsoRawQCD_->Add(IsoRawQCD20to30_);
  IsoRawQCD_->Add(IsoRawQCD30to50_);
  IsoRawQCD_->Add(IsoRawQCD50to80_);
  IsoRawQCD_->Add(IsoRawQCD80to120_);
  IsoRawQCD_->Add(IsoRawQCD120to170_);
  IsoRawQCD_->Add(IsoRawQCD170to300_);
  IsoRawQCD_->Add(IsoRawQCD300to470_);
  IsoRawQCD_->Add(IsoRawQCD470to600_);
  IsoRawQCD_->Add(IsoRawQCD600to800_);
  IsoRawQCD_->Add(IsoRawQCD800to1000_);
  IsoRawQCD_->Add(IsoRawQCD1000toInf_);

  RelIsoRawCanvasQCD.cd();
  RelIsoRawQCD_->Add(RelIsoRawQCD15to20_);
  RelIsoRawQCD_->Add(RelIsoRawQCD20to30_);
  RelIsoRawQCD_->Add(RelIsoRawQCD30to50_);
  RelIsoRawQCD_->Add(RelIsoRawQCD50to80_);
  RelIsoRawQCD_->Add(RelIsoRawQCD80to120_);
  RelIsoRawQCD_->Add(RelIsoRawQCD120to170_);
  RelIsoRawQCD_->Add(RelIsoRawQCD170to300_);
  RelIsoRawQCD_->Add(RelIsoRawQCD300to470_);
  RelIsoRawQCD_->Add(RelIsoRawQCD470to600_);
  RelIsoRawQCD_->Add(RelIsoRawQCD600to800_);
  RelIsoRawQCD_->Add(RelIsoRawQCD800to1000_);
  RelIsoRawQCD_->Add(RelIsoRawQCD1000toInf_);

  IsoRawCutBasedCanvasQCD.cd();
  IsoRawCutBasedQCD_->Add(IsoRawCutBasedQCD15to20_);
  IsoRawCutBasedQCD_->Add(IsoRawCutBasedQCD20to30_);
  IsoRawCutBasedQCD_->Add(IsoRawCutBasedQCD30to50_);
  IsoRawCutBasedQCD_->Add(IsoRawCutBasedQCD50to80_);
  IsoRawCutBasedQCD_->Add(IsoRawCutBasedQCD80to120_);
  IsoRawCutBasedQCD_->Add(IsoRawCutBasedQCD120to170_);
  IsoRawCutBasedQCD_->Add(IsoRawCutBasedQCD170to300_);
  IsoRawCutBasedQCD_->Add(IsoRawCutBasedQCD300to470_);
  IsoRawCutBasedQCD_->Add(IsoRawCutBasedQCD470to600_);
  IsoRawCutBasedQCD_->Add(IsoRawCutBasedQCD600to800_);
  IsoRawCutBasedQCD_->Add(IsoRawCutBasedQCD800to1000_);
  IsoRawCutBasedQCD_->Add(IsoRawCutBasedQCD1000toInf_);

  NEventsCutsCanvasQCD.cd();
  NEventsCutsQCD_->Add(NEventsCutsQCD15to20_);
  NEventsCutsQCD_->Add(NEventsCutsQCD20to30_);
  NEventsCutsQCD_->Add(NEventsCutsQCD30to50_);
  NEventsCutsQCD_->Add(NEventsCutsQCD50to80_);
  NEventsCutsQCD_->Add(NEventsCutsQCD80to120_);
  NEventsCutsQCD_->Add(NEventsCutsQCD120to170_);
  NEventsCutsQCD_->Add(NEventsCutsQCD170to300_);
  NEventsCutsQCD_->Add(NEventsCutsQCD300to470_);
  NEventsCutsQCD_->Add(NEventsCutsQCD470to600_);
  NEventsCutsQCD_->Add(NEventsCutsQCD600to800_);
  NEventsCutsQCD_->Add(NEventsCutsQCD800to1000_);
  NEventsCutsQCD_->Add(NEventsCutsQCD1000toInf_);


//////////////////////
// Summing background 
//////////////////////
  double backSum1 = DYH_Total + DYL_Total + TT_Total + QCD_Total;
  double backSum2 = DYH_BD0p5 + DYL_BD0p5 + TT_BD0p5 + QCD_BD0p5;
  double backSum3 = DYH_BD0p75 + DYL_BD0p75 + TT_BD0p75 + QCD_BD0p75;
  double backSum4 = DYH_BD0p9 + DYL_BD0p9 + TT_BD0p9 + QCD_BD0p9;
//  double backSum5
  double backSum6 = DYH_HT300 + DYL_HT300 + TT_HT300 + QCD_HT300;
  double backSum7 = DYH_HT400 + DYL_HT400 + TT_HT400 + QCD_HT400;
  double backSum8 = DYH_HT300_BD0p75 + DYL_HT300_BD0p75 + TT_HT300_BD0p75 + QCD_HT300_BD0p75;
  double backSum9 = DYH_HT400_BD0p5 + DYL_HT400_BD0p5 + TT_HT400_BD0p5 + QCD_HT400_BD0p5;
  double backSum10 = DYH_IsoRaw0p5 + DYL_IsoRaw0p5 + TT_IsoRaw0p5 + QCD_IsoRaw0p5;
  double backSum11 = DYH_IsoRaw1p0 + DYL_IsoRaw1p0 + TT_IsoRaw1p0 + QCD_IsoRaw1p0;
  double backSum12 = DYH_TightIso + DYL_TightIso + TT_TightIso + QCD_TightIso;
  double backSum13 = DYH_VTightIso + DYL_VTightIso + TT_VTightIso + QCD_VTightIso;

/////////////////////////////////
// Getting weighted QCD backErrr
/////////////////////////////////
  double backErrQCD_Total = QCD15to20_Total*scale_QCD15to20 + QCD20to30_Total*scale_QCD20to30 + QCD30to50_Total*scale_QCD30to50 + QCD50to80_Total*scale_QCD50to80 + QCD80to120_Total*scale_QCD80to120 + QCD120to170_Total*scale_QCD120to170 + QCD170to300_Total*scale_QCD170to300 + QCD300to470_Total*scale_QCD300to470 + QCD470to600_Total*scale_QCD470to600 + QCD600to800_Total*scale_QCD600to800 + QCD800to1000_Total*scale_QCD800to1000 + QCD1000toInf_Total*scale_QCD1000toInf;
  double backErrQCD_BD0p5 = QCD15to20_Total*scale_QCD15to20 + QCD20to30_Total*scale_QCD20to30 + QCD30to50_Total*scale_QCD30to50 + QCD50to80_Total*scale_QCD50to80 + QCD80to120_Total*scale_QCD80to120 + QCD120to170_Total*scale_QCD120to170 + QCD170to300_Total*scale_QCD170to300 + QCD300to470_Total*scale_QCD300to470 + QCD470to600_Total*scale_QCD470to600 + QCD600to800_Total*scale_QCD600to800 + QCD800to1000_Total*scale_QCD800to1000 + QCD1000toInf_Total*scale_QCD1000toInf;
  double backErrQCD_BD0p75 =QCD15to20_Total*scale_QCD15to20 + QCD20to30_Total*scale_QCD20to30 + QCD30to50_Total*scale_QCD30to50 + QCD50to80_Total*scale_QCD50to80 + QCD80to120_Total*scale_QCD80to120 + QCD120to170_Total*scale_QCD120to170 + QCD170to300_Total*scale_QCD170to300 + QCD300to470_Total*scale_QCD300to470 + QCD470to600_Total*scale_QCD470to600 + QCD600to800_Total*scale_QCD600to800 + QCD800to1000_Total*scale_QCD800to1000 + QCD1000toInf_Total*scale_QCD1000toInf;
  double backErrQCD_BD0p9 = QCD15to20_Total*scale_QCD15to20 + QCD20to30_Total*scale_QCD20to30 + QCD30to50_Total*scale_QCD30to50 + QCD50to80_Total*scale_QCD50to80 + QCD80to120_Total*scale_QCD80to120 + QCD120to170_Total*scale_QCD120to170 + QCD170to300_Total*scale_QCD170to300 + QCD300to470_Total*scale_QCD300to470 + QCD470to600_Total*scale_QCD470to600 + QCD600to800_Total*scale_QCD600to800 + QCD800to1000_Total*scale_QCD800to1000 + QCD1000toInf_Total*scale_QCD1000toInf;
//  double backErrQCD_ =  QCD15to20_Total*scale_QCD15to20 + QCD20to30_Total*scale_QCD20to30 + QCD30to50_Total*scale_QCD30to50 + QCD50to80_Total*scale_QCD50to80 + QCD80to120_Total*scale_QCD80to120 + QCD120to170_Total*scale_QCD120to170 + QCD170to300_Total*scale_QCD170to300 + QCD300to470_Total*scale_QCD300to470 + QCD470to600_Total*scale_QCD470to600 + QCD600to800_Total*scale_QCD600to800 + QCD800to1000_Total*scale_QCD800to1000 + QCD1000toInf_Total*scale_QCD1000toInf;
  double backErrQCD_HT300 = QCD15to20_Total*scale_QCD15to20 + QCD20to30_Total*scale_QCD20to30 + QCD30to50_Total*scale_QCD30to50 + QCD50to80_Total*scale_QCD50to80 + QCD80to120_Total*scale_QCD80to120 + QCD120to170_Total*scale_QCD120to170 + QCD170to300_Total*scale_QCD170to300 + QCD300to470_Total*scale_QCD300to470 + QCD470to600_Total*scale_QCD470to600 + QCD600to800_Total*scale_QCD600to800 + QCD800to1000_Total*scale_QCD800to1000 + QCD1000toInf_Total*scale_QCD1000toInf;
  double backErrQCD_HT400 = QCD15to20_Total*scale_QCD15to20 + QCD20to30_Total*scale_QCD20to30 + QCD30to50_Total*scale_QCD30to50 + QCD50to80_Total*scale_QCD50to80 + QCD80to120_Total*scale_QCD80to120 + QCD120to170_Total*scale_QCD120to170 + QCD170to300_Total*scale_QCD170to300 + QCD300to470_Total*scale_QCD300to470 + QCD470to600_Total*scale_QCD470to600 + QCD600to800_Total*scale_QCD600to800 + QCD800to1000_Total*scale_QCD800to1000 + QCD1000toInf_Total*scale_QCD1000toInf;
  double backErrQCD_HT300_BD0p75 = QCD15to20_Total*scale_QCD15to20 + QCD20to30_Total*scale_QCD20to30 + QCD30to50_Total*scale_QCD30to50 + QCD50to80_Total*scale_QCD50to80 + QCD80to120_Total*scale_QCD80to120 + QCD120to170_Total*scale_QCD120to170 + QCD170to300_Total*scale_QCD170to300 + QCD300to470_Total*scale_QCD300to470 + QCD470to600_Total*scale_QCD470to600 + QCD600to800_Total*scale_QCD600to800 + QCD800to1000_Total*scale_QCD800to1000 + QCD1000toInf_Total*scale_QCD1000toInf;
  double backErrQCD_HT400_BD0p5 =  QCD15to20_Total*scale_QCD15to20 + QCD20to30_Total*scale_QCD20to30 + QCD30to50_Total*scale_QCD30to50 + QCD50to80_Total*scale_QCD50to80 + QCD80to120_Total*scale_QCD80to120 + QCD120to170_Total*scale_QCD120to170 + QCD170to300_Total*scale_QCD170to300 + QCD300to470_Total*scale_QCD300to470 + QCD470to600_Total*scale_QCD470to600 + QCD600to800_Total*scale_QCD600to800 + QCD800to1000_Total*scale_QCD800to1000 + QCD1000toInf_Total*scale_QCD1000toInf;
  double backErrQCD_IsoRaw0p5 =  QCD15to20_Total*scale_QCD15to20 + QCD20to30_Total*scale_QCD20to30 + QCD30to50_Total*scale_QCD30to50 + QCD50to80_Total*scale_QCD50to80 + QCD80to120_Total*scale_QCD80to120 + QCD120to170_Total*scale_QCD120to170 + QCD170to300_Total*scale_QCD170to300 + QCD300to470_Total*scale_QCD300to470 + QCD470to600_Total*scale_QCD470to600 + QCD600to800_Total*scale_QCD600to800 + QCD800to1000_Total*scale_QCD800to1000 + QCD1000toInf_Total*scale_QCD1000toInf;
  double backErrQCD_IsoRaw1p0 =  QCD15to20_Total*scale_QCD15to20 + QCD20to30_Total*scale_QCD20to30 + QCD30to50_Total*scale_QCD30to50 + QCD50to80_Total*scale_QCD50to80 + QCD80to120_Total*scale_QCD80to120 + QCD120to170_Total*scale_QCD120to170 + QCD170to300_Total*scale_QCD170to300 + QCD300to470_Total*scale_QCD300to470 + QCD470to600_Total*scale_QCD470to600 + QCD600to800_Total*scale_QCD600to800 + QCD800to1000_Total*scale_QCD800to1000 + QCD1000toInf_Total*scale_QCD1000toInf;
  double backErrQCD_TightIso =  QCD15to20_Total*scale_QCD15to20 + QCD20to30_Total*scale_QCD20to30 + QCD30to50_Total*scale_QCD30to50 + QCD50to80_Total*scale_QCD50to80 + QCD80to120_Total*scale_QCD80to120 + QCD120to170_Total*scale_QCD120to170 + QCD170to300_Total*scale_QCD170to300 + QCD300to470_Total*scale_QCD300to470 + QCD470to600_Total*scale_QCD470to600 + QCD600to800_Total*scale_QCD600to800 + QCD800to1000_Total*scale_QCD800to1000 + QCD1000toInf_Total*scale_QCD1000toInf;
  double backErrQCD_VTightIso = QCD15to20_Total*scale_QCD15to20 + QCD20to30_Total*scale_QCD20to30 + QCD30to50_Total*scale_QCD30to50 + QCD50to80_Total*scale_QCD50to80 + QCD80to120_Total*scale_QCD80to120 + QCD120to170_Total*scale_QCD120to170 + QCD170to300_Total*scale_QCD170to300 + QCD300to470_Total*scale_QCD300to470 + QCD470to600_Total*scale_QCD470to600 + QCD600to800_Total*scale_QCD600to800 + QCD800to1000_Total*scale_QCD800to1000 + QCD1000toInf_Total*scale_QCD1000toInf;

////////////////////////////
// Getting Background Error
////////////////////////////
  double backErr1  = sqrt(DYH_Total*scale_DYH + DYL_Total*scale_DYL + TT_Total*scale_TT + backErrQCD_Total);
  double backErr2  = sqrt(DYH_BD0p5*scale_DYH + DYL_BD0p5*scale_DYL + TT_BD0p5*scale_TT + backErrQCD_BD0p5);
  double backErr3  = sqrt(DYH_BD0p75*scale_DYH + DYL_BD0p75*scale_DYL + TT_BD0p75*scale_TT + backErrQCD_BD0p75);
  double backErr4  = sqrt(DYH_BD0p9*scale_DYH + DYL_BD0p9*scale_DYL + TT_BD0p9*scale_TT + backErrQCD_BD0p9);
//  double backErr5 =
  double backErr6  = sqrt(DYH_HT300*scale_DYH + DYL_HT300*scale_DYL + TT_HT300*scale_TT + backErrQCD_HT300);
  double backErr7  = sqrt(DYH_HT400*scale_DYH + DYL_HT400*scale_DYL + TT_HT400*scale_TT + backErrQCD_HT400);
  double backErr8  = sqrt(DYH_HT300_BD0p75*scale_DYH + DYL_HT300_BD0p75*scale_DYL + TT_HT300_BD0p75*scale_TT + backErrQCD_HT300_BD0p75);
  double backErr9  = sqrt(DYH_HT400_BD0p5*scale_DYH + DYL_HT400_BD0p5*scale_DYL + TT_HT400_BD0p5*scale_TT + backErrQCD_HT400_BD0p5);
  double backErr10 = sqrt(DYH_IsoRaw0p5*scale_DYH + DYL_IsoRaw0p5*scale_DYL + TT_IsoRaw0p5*scale_TT + backErrQCD_IsoRaw0p5);
  double backErr11 = sqrt(DYH_IsoRaw1p0*scale_DYH + DYL_IsoRaw1p0*scale_DYL + TT_IsoRaw1p0*scale_TT + backErrQCD_IsoRaw1p0);
  double backErr12 = sqrt(DYH_TightIso*scale_DYH + DYL_TightIso*scale_DYL + TT_TightIso*scale_TT + backErrQCD_TightIso);
  double backErr13 = sqrt(DYH_VTightIso*scale_DYH + DYL_VTightIso*scale_DYL + TT_VTightIso*scale_TT + backErrQCD_VTightIso);

////////////////////////
// Getting Total error
////////////////////////
  //Error for H125a19
  double err1H125a19 = sqrt( scale_H125a19*H125a19_Total*pow( pow(backSum1 + H125a19_Total,-.5) - H125a19_Total/2*pow(H125a19_Total + backSum1,-1.5),2) + backErr1*pow(H125a19_Total/2*pow(H125a19_Total + backSum1,-1.5),2) );
  double err2H125a19 = sqrt( scale_H125a19*H125a19_BD0p5*pow( pow(backSum2 + H125a19_BD0p5,-.5) - H125a19_BD0p5/2*pow(H125a19_BD0p5 + backSum1,-1.5),2) + backErr2*pow(H125a19_BD0p5/2*pow(H125a19_BD0p5 + backSum2,-1.5),2) );
  double err3H125a19 = sqrt( scale_H125a19*H125a19_BD0p75*pow( pow(backSum3 + H125a19_BD0p75,-.5) - H125a19_BD0p75/2*pow(H125a19_BD0p75 + backSum1,-1.5),2) + backErr3*pow(H125a19_BD0p75/2*pow(H125a19_BD0p75 + backSum3,-1.5),2) );
  double err4H125a19 = sqrt( scale_H125a19*H125a19_BD0p9*pow( pow(backSum4 + H125a19_BD0p9,-.5) - H125a19_BD0p9/2*pow(H125a19_BD0p9 + backSum1,-1.5),2) + backErr4*pow(H125a19_BD0p9/2*pow(H125a19_BD0p9 + backSum4,-1.5),2) );
//  double err5H125a19 = sqrt( scale_H125a19*H125a19_BD0p5*pow( pow(backSum5 + H125a19_BD0p5,-.5) - H125a19_BD0p5/2*pow(H125a19_BD0p5 + backSum1,-1.5),2) + backErr5*pow(H125a19_BD0p5/2*pow(H125a19_BD0p5 + backSum5,-1.5),2) );
  double err6H125a19 = sqrt( scale_H125a19*H125a19_HT300*pow( pow(backSum6 + H125a19_HT300,-.5) - H125a19_HT300/2*pow(H125a19_HT300 + backSum1,-1.5),2) + backErr6*pow(H125a19_HT300/2*pow(H125a19_HT300 + backSum6,-1.5),2) );
  double err7H125a19 = sqrt( scale_H125a19*H125a19_HT400*pow( pow(backSum7 + H125a19_HT400,-.5) - H125a19_HT400/2*pow(H125a19_HT400 + backSum1,-1.5),2) + backErr7*pow(H125a19_HT400/2*pow(H125a19_HT400 + backSum7,-1.5),2) );
  double err8H125a19 = sqrt( scale_H125a19*H125a19_HT300_BD0p75*pow( pow(backSum8 + H125a19_HT300_BD0p75,-.5) - H125a19_HT300_BD0p75/2*pow(H125a19_HT300_BD0p75 + backSum1,-1.5),2) + backErr8*pow(H125a19_HT300_BD0p75/2*pow(H125a19_HT300_BD0p75 + backSum8,-1.5),2) );
  double err9H125a19 = sqrt( scale_H125a19*H125a19_HT400_BD0p5*pow( pow(backSum9 + H125a19_HT400_BD0p5,-.5) - H125a19_HT400_BD0p5/2*pow(H125a19_HT400_BD0p5 + backSum1,-1.5),2) + backErr9*pow(H125a19_HT400_BD0p5/2*pow(H125a19_HT400_BD0p5 + backSum9,-1.5),2) );
  double err10H125a19 = sqrt( scale_H125a19*H125a19_IsoRaw0p5*pow( pow(backSum10 + H125a19_IsoRaw0p5,-.5) - H125a19_IsoRaw0p5/2*pow(H125a19_IsoRaw0p5 + backSum1,-1.5),2) + backErr10*pow(H125a19_IsoRaw0p5/2*pow(H125a19_IsoRaw0p5 + backSum10,-1.5),2) );
  double err11H125a19 = sqrt( scale_H125a19*H125a19_IsoRaw1p0*pow( pow(backSum11 + H125a19_IsoRaw1p0,-.5) - H125a19_IsoRaw1p0/2*pow(H125a19_IsoRaw1p0 + backSum1,-1.5),2) + backErr11*pow(H125a19_IsoRaw1p0/2*pow(H125a19_IsoRaw1p0 + backSum11,-1.5),2) );
  double err12H125a19 = sqrt( scale_H125a19*H125a19_TightIso*pow( pow(backSum12 + H125a19_TightIso,-.5) - H125a19_TightIso/2*pow(H125a19_TightIso + backSum1,-1.5),2) + backErr12*pow(H125a19_TightIso/2*pow(H125a19_TightIso + backSum12,-1.5),2) );
  double err13H125a19 = sqrt( scale_H125a19*H125a19_VTightIso*pow( pow(backSum13 + H125a19_VTightIso,-.5) - H125a19_VTightIso/2*pow(H125a19_VTightIso + backSum1,-1.5),2) + backErr13*pow(H125a19_VTightIso/2*pow(H125a19_VTightIso + backSum13,-1.5),2) );

  //Error for H125a9
  double err1H125a9 = sqrt( scale_H125a9*H125a9_Total*pow( pow(backSum1 + H125a9_Total,-.5) - H125a9_Total/2*pow(H125a9_Total + backSum1,-1.5),2) + backErr1*pow(H125a9_Total/2*pow(H125a9_Total + backSum1,-1.5),2) );
  double err2H125a9 = sqrt( scale_H125a9*H125a9_BD0p5*pow( pow(backSum2 + H125a9_BD0p5,-.5) - H125a9_BD0p5/2*pow(H125a9_BD0p5 + backSum1,-1.5),2) + backErr2*pow(H125a9_BD0p5/2*pow(H125a9_BD0p5 + backSum2,-1.5),2) );
  double err3H125a9 = sqrt( scale_H125a9*H125a9_BD0p75*pow( pow(backSum3 + H125a9_BD0p75,-.5) - H125a9_BD0p75/2*pow(H125a9_BD0p75 + backSum1,-1.5),2) + backErr3*pow(H125a9_BD0p75/2*pow(H125a9_BD0p75 + backSum3,-1.5),2) );
  double err4H125a9 = sqrt( scale_H125a9*H125a9_BD0p9*pow( pow(backSum4 + H125a9_BD0p9,-.5) - H125a9_BD0p9/2*pow(H125a9_BD0p9 + backSum1,-1.5),2) + backErr4*pow(H125a9_BD0p9/2*pow(H125a9_BD0p9 + backSum4,-1.5),2) );
//  double err5H125a9 = sqrt( scale_H125a9*H125a9_BD0p5*pow( pow(backSum5 + H125a9_BD0p5,-.5) - H125a9_BD0p5/2*pow(H125a9_BD0p5 + backSum1,-1.5),2) + backErr5*pow(H125a9_BD0p5/2*pow(H125a9_BD0p5 + backSum5,-1.5),2) );
  double err6H125a9 = sqrt( scale_H125a9*H125a9_HT300*pow( pow(backSum6 + H125a9_HT300,-.5) - H125a9_HT300/2*pow(H125a9_HT300 + backSum1,-1.5),2) + backErr6*pow(H125a9_HT300/2*pow(H125a9_HT300 + backSum6,-1.5),2) );
  double err7H125a9 = sqrt( scale_H125a9*H125a9_HT400*pow( pow(backSum7 + H125a9_HT400,-.5) - H125a9_HT400/2*pow(H125a9_HT400 + backSum1,-1.5),2) + backErr7*pow(H125a9_HT400/2*pow(H125a9_HT400 + backSum7,-1.5),2) );
  double err8H125a9 = sqrt( scale_H125a9*H125a9_HT300_BD0p75*pow( pow(backSum8 + H125a9_HT300_BD0p75,-.5) - H125a9_HT300_BD0p75/2*pow(H125a9_HT300_BD0p75 + backSum1,-1.5),2) + backErr8*pow(H125a9_HT300_BD0p75/2*pow(H125a9_HT300_BD0p75 + backSum8,-1.5),2) );
  double err9H125a9 = sqrt( scale_H125a9*H125a9_HT400_BD0p5*pow( pow(backSum9 + H125a9_HT400_BD0p5,-.5) - H125a9_HT400_BD0p5/2*pow(H125a9_HT400_BD0p5 + backSum1,-1.5),2) + backErr9*pow(H125a9_HT400_BD0p5/2*pow(H125a9_HT400_BD0p5 + backSum9,-1.5),2) );
  double err10H125a9 = sqrt( scale_H125a9*H125a9_IsoRaw0p5*pow( pow(backSum10 + H125a9_IsoRaw0p5,-.5) - H125a9_IsoRaw0p5/2*pow(H125a9_IsoRaw0p5 + backSum1,-1.5),2) + backErr10*pow(H125a9_IsoRaw0p5/2*pow(H125a9_IsoRaw0p5 + backSum10,-1.5),2) );
  double err11H125a9 = sqrt( scale_H125a9*H125a9_IsoRaw1p0*pow( pow(backSum11 + H125a9_IsoRaw1p0,-.5) - H125a9_IsoRaw1p0/2*pow(H125a9_IsoRaw1p0 + backSum1,-1.5),2) + backErr11*pow(H125a9_IsoRaw1p0/2*pow(H125a9_IsoRaw1p0 + backSum11,-1.5),2) );
  double err12H125a9 = sqrt( scale_H125a9*H125a9_TightIso*pow( pow(backSum12 + H125a9_TightIso,-.5) - H125a9_TightIso/2*pow(H125a9_TightIso + backSum1,-1.5),2) + backErr12*pow(H125a9_TightIso/2*pow(H125a9_TightIso + backSum12,-1.5),2) );
  double err13H125a9 = sqrt( scale_H125a9*H125a9_VTightIso*pow( pow(backSum13 + H125a9_VTightIso,-.5) - H125a9_VTightIso/2*pow(H125a9_VTightIso + backSum1,-1.5),2) + backErr13*pow(H125a9_VTightIso/2*pow(H125a9_VTightIso + backSum13,-1.5),2) );

  //Error for H125a5
  double err1H125a5 = sqrt( scale_H125a5*H125a5_Total*pow( pow(backSum1 + H125a5_Total,-.5) - H125a5_Total/2*pow(H125a5_Total + backSum1,-1.5),2) + backErr1*pow(H125a5_Total/2*pow(H125a5_Total + backSum1,-1.5),2) );
  double err2H125a5 = sqrt( scale_H125a5*H125a5_BD0p5*pow( pow(backSum2 + H125a5_BD0p5,-.5) - H125a5_BD0p5/2*pow(H125a5_BD0p5 + backSum1,-1.5),2) + backErr2*pow(H125a5_BD0p5/2*pow(H125a5_BD0p5 + backSum2,-1.5),2) );
  double err3H125a5 = sqrt( scale_H125a5*H125a5_BD0p75*pow( pow(backSum3 + H125a5_BD0p75,-.5) - H125a5_BD0p75/2*pow(H125a5_BD0p75 + backSum1,-1.5),2) + backErr3*pow(H125a5_BD0p75/2*pow(H125a5_BD0p75 + backSum3,-1.5),2) );
  double err4H125a5 = sqrt( scale_H125a5*H125a5_BD0p9*pow( pow(backSum4 + H125a5_BD0p9,-.5) - H125a5_BD0p9/2*pow(H125a5_BD0p9 + backSum1,-1.5),2) + backErr4*pow(H125a5_BD0p9/2*pow(H125a5_BD0p9 + backSum4,-1.5),2) );
//  double err5H125a5 = sqrt( scale_H125a5*H125a5_BD0p5*pow( pow(backSum5 + H125a5_BD0p5,-.5) - H125a5_BD0p5/2*pow(H125a5_BD0p5 + backSum1,-1.5),2) + backErr5*pow(H125a5_BD0p5/2*pow(H125a5_BD0p5 + backSum5,-1.5),2) );
  double err6H125a5 = sqrt( scale_H125a5*H125a5_HT300*pow( pow(backSum6 + H125a5_HT300,-.5) - H125a5_HT300/2*pow(H125a5_HT300 + backSum1,-1.5),2) + backErr6*pow(H125a5_HT300/2*pow(H125a5_HT300 + backSum6,-1.5),2) );
  double err7H125a5 = sqrt( scale_H125a5*H125a5_HT400*pow( pow(backSum7 + H125a5_HT400,-.5) - H125a5_HT400/2*pow(H125a5_HT400 + backSum1,-1.5),2) + backErr7*pow(H125a5_HT400/2*pow(H125a5_HT400 + backSum7,-1.5),2) );
  double err8H125a5 = sqrt( scale_H125a5*H125a5_HT300_BD0p75*pow( pow(backSum8 + H125a5_HT300_BD0p75,-.5) - H125a5_HT300_BD0p75/2*pow(H125a5_HT300_BD0p75 + backSum1,-1.5),2) + backErr8*pow(H125a5_HT300_BD0p75/2*pow(H125a5_HT300_BD0p75 + backSum8,-1.5),2) );
  double err9H125a5 = sqrt( scale_H125a5*H125a5_HT400_BD0p5*pow( pow(backSum9 + H125a5_HT400_BD0p5,-.5) - H125a5_HT400_BD0p5/2*pow(H125a5_HT400_BD0p5 + backSum1,-1.5),2) + backErr9*pow(H125a5_HT400_BD0p5/2*pow(H125a5_HT400_BD0p5 + backSum9,-1.5),2) );
  double err10H125a5 = sqrt( scale_H125a5*H125a5_IsoRaw0p5*pow( pow(backSum10 + H125a5_IsoRaw0p5,-.5) - H125a5_IsoRaw0p5/2*pow(H125a5_IsoRaw0p5 + backSum1,-1.5),2) + backErr10*pow(H125a5_IsoRaw0p5/2*pow(H125a5_IsoRaw0p5 + backSum10,-1.5),2) );
  double err11H125a5 = sqrt( scale_H125a5*H125a5_IsoRaw1p0*pow( pow(backSum11 + H125a5_IsoRaw1p0,-.5) - H125a5_IsoRaw1p0/2*pow(H125a5_IsoRaw1p0 + backSum1,-1.5),2) + backErr11*pow(H125a5_IsoRaw1p0/2*pow(H125a5_IsoRaw1p0 + backSum11,-1.5),2) );
  double err12H125a5 = sqrt( scale_H125a5*H125a5_TightIso*pow( pow(backSum12 + H125a5_TightIso,-.5) - H125a5_TightIso/2*pow(H125a5_TightIso + backSum1,-1.5),2) + backErr12*pow(H125a5_TightIso/2*pow(H125a5_TightIso + backSum12,-1.5),2) );
  double err13H125a5 = sqrt( scale_H125a5*H125a5_VTightIso*pow( pow(backSum13 + H125a5_VTightIso,-.5) - H125a5_VTightIso/2*pow(H125a5_VTightIso + backSum1,-1.5),2) + backErr13*pow(H125a5_VTightIso/2*pow(H125a5_VTightIso + backSum13,-1.5),2) );

  //Error for H750a9
  double err1H750a9 = sqrt( scale_H750a9*H750a9_Total*pow( pow(backSum1 + H750a9_Total,-.5) - H750a9_Total/2*pow(H750a9_Total + backSum1,-1.5),2) + backErr1*pow(H750a9_Total/2*pow(H750a9_Total + backSum1,-1.5),2) );
  double err2H750a9 = sqrt( scale_H750a9*H750a9_BD0p5*pow( pow(backSum2 + H750a9_BD0p5,-.5) - H750a9_BD0p5/2*pow(H750a9_BD0p5 + backSum1,-1.5),2) + backErr2*pow(H750a9_BD0p5/2*pow(H750a9_BD0p5 + backSum2,-1.5),2) );
  double err3H750a9 = sqrt( scale_H750a9*H750a9_BD0p75*pow( pow(backSum3 + H750a9_BD0p75,-.5) - H750a9_BD0p75/2*pow(H750a9_BD0p75 + backSum1,-1.5),2) + backErr3*pow(H750a9_BD0p75/2*pow(H750a9_BD0p75 + backSum3,-1.5),2) );
  double err4H750a9 = sqrt( scale_H750a9*H750a9_BD0p9*pow( pow(backSum4 + H750a9_BD0p9,-.5) - H750a9_BD0p9/2*pow(H750a9_BD0p9 + backSum1,-1.5),2) + backErr4*pow(H750a9_BD0p9/2*pow(H750a9_BD0p9 + backSum4,-1.5),2) );
//  double err5H750a9 = sqrt( scale_H750a9*H750a9_BD0p5*pow( pow(backSum5 + H750a9_BD0p5,-.5) - H750a9_BD0p5/2*pow(H750a9_BD0p5 + backSum1,-1.5),2) + backErr5*pow(H750a9_BD0p5/2*pow(H750a9_BD0p5 + backSum5,-1.5),2) );
  double err6H750a9 = sqrt( scale_H750a9*H750a9_HT300*pow( pow(backSum6 + H750a9_HT300,-.5) - H750a9_HT300/2*pow(H750a9_HT300 + backSum1,-1.5),2) + backErr6*pow(H750a9_HT300/2*pow(H750a9_HT300 + backSum6,-1.5),2) );
  double err7H750a9 = sqrt( scale_H750a9*H750a9_HT400*pow( pow(backSum7 + H750a9_HT400,-.5) - H750a9_HT400/2*pow(H750a9_HT400 + backSum1,-1.5),2) + backErr7*pow(H750a9_HT400/2*pow(H750a9_HT400 + backSum7,-1.5),2) );
  double err8H750a9 = sqrt( scale_H750a9*H750a9_HT300_BD0p75*pow( pow(backSum8 + H750a9_HT300_BD0p75,-.5) - H750a9_HT300_BD0p75/2*pow(H750a9_HT300_BD0p75 + backSum1,-1.5),2) + backErr8*pow(H750a9_HT300_BD0p75/2*pow(H750a9_HT300_BD0p75 + backSum8,-1.5),2) );
  double err9H750a9 = sqrt( scale_H750a9*H750a9_HT400_BD0p5*pow( pow(backSum9 + H750a9_HT400_BD0p5,-.5) - H750a9_HT400_BD0p5/2*pow(H750a9_HT400_BD0p5 + backSum1,-1.5),2) + backErr9*pow(H750a9_HT400_BD0p5/2*pow(H750a9_HT400_BD0p5 + backSum9,-1.5),2) );
  double err10H750a9 = sqrt( scale_H750a9*H750a9_IsoRaw0p5*pow( pow(backSum10 + H750a9_IsoRaw0p5,-.5) - H750a9_IsoRaw0p5/2*pow(H750a9_IsoRaw0p5 + backSum1,-1.5),2) + backErr10*pow(H750a9_IsoRaw0p5/2*pow(H750a9_IsoRaw0p5 + backSum10,-1.5),2) );
  double err11H750a9 = sqrt( scale_H750a9*H750a9_IsoRaw1p0*pow( pow(backSum11 + H750a9_IsoRaw1p0,-.5) - H750a9_IsoRaw1p0/2*pow(H750a9_IsoRaw1p0 + backSum1,-1.5),2) + backErr11*pow(H750a9_IsoRaw1p0/2*pow(H750a9_IsoRaw1p0 + backSum11,-1.5),2) );
  double err12H750a9 = sqrt( scale_H750a9*H750a9_TightIso*pow( pow(backSum12 + H750a9_TightIso,-.5) - H750a9_TightIso/2*pow(H750a9_TightIso + backSum1,-1.5),2) + backErr12*pow(H750a9_TightIso/2*pow(H750a9_TightIso + backSum12,-1.5),2) );
  double err13H750a9 = sqrt( scale_H750a9*H750a9_VTightIso*pow( pow(backSum13 + H750a9_VTightIso,-.5) - H750a9_VTightIso/2*pow(H750a9_VTightIso + backSum1,-1.5),2) + backErr13*pow(H750a9_VTightIso/2*pow(H750a9_VTightIso + backSum13,-1.5),2) );

////////////////////////////////////////////
// Declaring the Signal to background plots
////////////////////////////////////////////
  TCanvas SigToBackCanvas("H125a19ToBackCanvas","",600,600);
  SigToBackCanvas.SetGrid(1,1);

  TH1F* H125a19ToBack_    = new TH1F("H125a19ToBack","", 13, -.5, 12.5);
      H125a19ToBack_->GetXaxis()->SetBinLabel(1, NEventsCutsTT_->GetXaxis()->GetBinLabel(1) );
      H125a19ToBack_->GetXaxis()->SetBinLabel(2, NEventsCutsTT_->GetXaxis()->GetBinLabel(2) );
      H125a19ToBack_->GetXaxis()->SetBinLabel(3, NEventsCutsTT_->GetXaxis()->GetBinLabel(3) );
      H125a19ToBack_->GetXaxis()->SetBinLabel(4, NEventsCutsTT_->GetXaxis()->GetBinLabel(4) );
//      H125a19ToBack_->GetXaxis()->SetBinLabel(5, NEventsCutsTT_->GetXaxis()->GetBinLabel(5) );
      H125a19ToBack_->GetXaxis()->SetBinLabel(6, NEventsCutsTT_->GetXaxis()->GetBinLabel(6));
      H125a19ToBack_->GetXaxis()->SetBinLabel(7, NEventsCutsTT_->GetXaxis()->GetBinLabel(7) );
      H125a19ToBack_->GetXaxis()->SetBinLabel(8, NEventsCutsTT_->GetXaxis()->GetBinLabel(8) );
      H125a19ToBack_->GetXaxis()->SetBinLabel(9, NEventsCutsTT_->GetXaxis()->GetBinLabel(9) );
      H125a19ToBack_->GetXaxis()->SetBinLabel(10, NEventsCutsTT_->GetXaxis()->GetBinLabel(10) );
      H125a19ToBack_->GetXaxis()->SetBinLabel(11, NEventsCutsTT_->GetXaxis()->GetBinLabel(11) );
      H125a19ToBack_->GetXaxis()->SetBinLabel(12, NEventsCutsTT_->GetXaxis()->GetBinLabel(12) );
      H125a19ToBack_->GetXaxis()->SetBinLabel(13, NEventsCutsTT_->GetXaxis()->GetBinLabel(13) );
  H125a19ToBack_->SetBinContent(1, H125a19_BD0p5 / TMath::Sqrt(H125a19_BD0p5 + backSum1) );
  H125a19ToBack_->SetBinContent(2, H125a19_BD0p5 / TMath::Sqrt(H125a19_BD0p5 + backSum2) );
  H125a19ToBack_->SetBinContent(3, H125a19_BD0p5 / TMath::Sqrt(H125a19_BD0p5 + backSum3) );
  H125a19ToBack_->SetBinContent(4, H125a19_BD0p5 / TMath::Sqrt(H125a19_BD0p5 + backSum4) );
//  H125a19ToBack_->SetBinContent(5, H125a19_BD0p5 / TMath::Sqrt(H125a19_BD0p5 + backSum5) );
  H125a19ToBack_->SetBinContent(6, H125a19_BD0p5 / TMath::Sqrt(H125a19_BD0p5 + backSum6) );
  H125a19ToBack_->SetBinContent(7, H125a19_BD0p5 / TMath::Sqrt(H125a19_BD0p5 + backSum7) );
  H125a19ToBack_->SetBinContent(8, H125a19_BD0p5 / TMath::Sqrt(H125a19_BD0p5 + backSum8) );
  H125a19ToBack_->SetBinContent(9, H125a19_BD0p5 / TMath::Sqrt(H125a19_BD0p5 + backSum9) );
  H125a19ToBack_->SetBinContent(10, H125a19_BD0p5 / TMath::Sqrt(H125a19_BD0p5 + backSum10) );
  H125a19ToBack_->SetBinContent(11, H125a19_BD0p5 / TMath::Sqrt(H125a19_BD0p5 + backSum11) );
  H125a19ToBack_->SetBinContent(12, H125a19_BD0p5 / TMath::Sqrt(H125a19_BD0p5 + backSum12) );
  H125a19ToBack_->SetBinContent(13, H125a19_BD0p5 / TMath::Sqrt(H125a19_BD0p5 + backSum13) );
  H125a19ToBack_->SetBinError(1, err1H125a19);
  H125a19ToBack_->SetBinError(2, err2H125a19);
  H125a19ToBack_->SetBinError(3, err3H125a19);
  H125a19ToBack_->SetBinError(4, err4H125a19);
//  H125a19ToBack_->SetBinError(5, err5H125a19);
  H125a19ToBack_->SetBinError(6, err6H125a19);
  H125a19ToBack_->SetBinError(7, err7H125a19);
  H125a19ToBack_->SetBinError(8, err8H125a19);
  H125a19ToBack_->SetBinError(9, err9H125a19);
  H125a19ToBack_->SetBinError(10, err10H125a19);
  H125a19ToBack_->SetBinError(11, err11H125a19);
  H125a19ToBack_->SetBinError(12, err12H125a19);
  H125a19ToBack_->SetBinError(13, err13H125a19);
  H125a19ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* H125a9ToBack_    = new TH1F("H125a9ToBack","", 13, -.5, 12.5);
      H125a9ToBack_->GetXaxis()->SetBinLabel(1, NEventsCutsTT_->GetXaxis()->GetBinLabel(1) );
      H125a9ToBack_->GetXaxis()->SetBinLabel(2, NEventsCutsTT_->GetXaxis()->GetBinLabel(2) );
      H125a9ToBack_->GetXaxis()->SetBinLabel(3, NEventsCutsTT_->GetXaxis()->GetBinLabel(3) );
      H125a9ToBack_->GetXaxis()->SetBinLabel(4, NEventsCutsTT_->GetXaxis()->GetBinLabel(4) );
//      H125a9ToBack_->GetXaxis()->SetBinLabel(5, NEventsCutsTT_->GetXaxis()->GetBinLabel(5) );
      H125a9ToBack_->GetXaxis()->SetBinLabel(6, NEventsCutsTT_->GetXaxis()->GetBinLabel(6));
      H125a9ToBack_->GetXaxis()->SetBinLabel(7, NEventsCutsTT_->GetXaxis()->GetBinLabel(7) );
      H125a9ToBack_->GetXaxis()->SetBinLabel(8, NEventsCutsTT_->GetXaxis()->GetBinLabel(8) );
      H125a9ToBack_->GetXaxis()->SetBinLabel(9, NEventsCutsTT_->GetXaxis()->GetBinLabel(9) );
      H125a9ToBack_->GetXaxis()->SetBinLabel(10, NEventsCutsTT_->GetXaxis()->GetBinLabel(10) );
      H125a9ToBack_->GetXaxis()->SetBinLabel(11, NEventsCutsTT_->GetXaxis()->GetBinLabel(11) );
      H125a9ToBack_->GetXaxis()->SetBinLabel(12, NEventsCutsTT_->GetXaxis()->GetBinLabel(12) );
      H125a9ToBack_->GetXaxis()->SetBinLabel(13, NEventsCutsTT_->GetXaxis()->GetBinLabel(13) );
  H125a9ToBack_->SetBinContent(1, H125a9_BD0p5 / TMath::Sqrt(H125a9_BD0p5 + backSum1) );
  H125a9ToBack_->SetBinContent(2, H125a9_BD0p5 / TMath::Sqrt(H125a9_BD0p5 + backSum2) );
  H125a9ToBack_->SetBinContent(3, H125a9_BD0p5 / TMath::Sqrt(H125a9_BD0p5 + backSum3) );
  H125a9ToBack_->SetBinContent(4, H125a9_BD0p5 / TMath::Sqrt(H125a9_BD0p5 + backSum4) );
//  H125a9ToBack_->SetBinContent(5, H125a9_BD0p5 / TMath::Sqrt(H125a9_BD0p5 + backSum5) );
  H125a9ToBack_->SetBinContent(6, H125a9_BD0p5 / TMath::Sqrt(H125a9_BD0p5 + backSum6) );
  H125a9ToBack_->SetBinContent(7, H125a9_BD0p5 / TMath::Sqrt(H125a9_BD0p5 + backSum7) );
  H125a9ToBack_->SetBinContent(8, H125a9_BD0p5 / TMath::Sqrt(H125a9_BD0p5 + backSum8) );
  H125a9ToBack_->SetBinContent(9, H125a9_BD0p5 / TMath::Sqrt(H125a9_BD0p5 + backSum9) );
  H125a9ToBack_->SetBinContent(10, H125a9_BD0p5 / TMath::Sqrt(H125a9_BD0p5 + backSum10) );
  H125a9ToBack_->SetBinContent(11, H125a9_BD0p5 / TMath::Sqrt(H125a9_BD0p5 + backSum11) );
  H125a9ToBack_->SetBinContent(12, H125a9_BD0p5 / TMath::Sqrt(H125a9_BD0p5 + backSum12) );
  H125a9ToBack_->SetBinContent(13, H125a9_BD0p5 / TMath::Sqrt(H125a9_BD0p5 + backSum13) );
  H125a9ToBack_->SetBinError(1, err1H125a9);
  H125a9ToBack_->SetBinError(2, err2H125a9);
  H125a9ToBack_->SetBinError(3, err3H125a9);
  H125a9ToBack_->SetBinError(4, err4H125a9);
//  H125a9ToBack_->SetBinError(5, err5H125a9);
  H125a9ToBack_->SetBinError(6, err6H125a9);
  H125a9ToBack_->SetBinError(7, err7H125a9);
  H125a9ToBack_->SetBinError(8, err8H125a9);
  H125a9ToBack_->SetBinError(9, err9H125a9);
  H125a9ToBack_->SetBinError(10, err10H125a9);
  H125a9ToBack_->SetBinError(11, err11H125a9);
  H125a9ToBack_->SetBinError(12, err12H125a9);
  H125a9ToBack_->SetBinError(13, err13H125a9);
  H125a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* H125a5ToBack_    = new TH1F("H125a5ToBack","", 13, -.5, 12.5);
      H125a5ToBack_->GetXaxis()->SetBinLabel(1, NEventsCutsTT_->GetXaxis()->GetBinLabel(1) );
      H125a5ToBack_->GetXaxis()->SetBinLabel(2, NEventsCutsTT_->GetXaxis()->GetBinLabel(2) );
      H125a5ToBack_->GetXaxis()->SetBinLabel(3, NEventsCutsTT_->GetXaxis()->GetBinLabel(3) );
      H125a5ToBack_->GetXaxis()->SetBinLabel(4, NEventsCutsTT_->GetXaxis()->GetBinLabel(4) );
//      H125a5ToBack_->GetXaxis()->SetBinLabel(5, NEventsCutsTT_->GetXaxis()->GetBinLabel(5) );
      H125a5ToBack_->GetXaxis()->SetBinLabel(6, NEventsCutsTT_->GetXaxis()->GetBinLabel(6));
      H125a5ToBack_->GetXaxis()->SetBinLabel(7, NEventsCutsTT_->GetXaxis()->GetBinLabel(7) );
      H125a5ToBack_->GetXaxis()->SetBinLabel(8, NEventsCutsTT_->GetXaxis()->GetBinLabel(8) );
      H125a5ToBack_->GetXaxis()->SetBinLabel(9, NEventsCutsTT_->GetXaxis()->GetBinLabel(9) );
      H125a5ToBack_->GetXaxis()->SetBinLabel(10, NEventsCutsTT_->GetXaxis()->GetBinLabel(10) );
      H125a5ToBack_->GetXaxis()->SetBinLabel(11, NEventsCutsTT_->GetXaxis()->GetBinLabel(11) );
      H125a5ToBack_->GetXaxis()->SetBinLabel(12, NEventsCutsTT_->GetXaxis()->GetBinLabel(12) );
      H125a5ToBack_->GetXaxis()->SetBinLabel(13, NEventsCutsTT_->GetXaxis()->GetBinLabel(13) );
  H125a5ToBack_->SetBinContent(1, H125a5_BD0p5 / TMath::Sqrt(H125a5_BD0p5 + backSum1) );
  H125a5ToBack_->SetBinContent(2, H125a5_BD0p5 / TMath::Sqrt(H125a5_BD0p5 + backSum2) );
  H125a5ToBack_->SetBinContent(3, H125a5_BD0p5 / TMath::Sqrt(H125a5_BD0p5 + backSum3) );
  H125a5ToBack_->SetBinContent(4, H125a5_BD0p5 / TMath::Sqrt(H125a5_BD0p5 + backSum4) );
//  H125a5ToBack_->SetBinContent(5, H125a5_BD0p5 / TMath::Sqrt(H125a5_BD0p5 + backSum5) );
  H125a5ToBack_->SetBinContent(6, H125a5_BD0p5 / TMath::Sqrt(H125a5_BD0p5 + backSum6) );
  H125a5ToBack_->SetBinContent(7, H125a5_BD0p5 / TMath::Sqrt(H125a5_BD0p5 + backSum7) );
  H125a5ToBack_->SetBinContent(8, H125a5_BD0p5 / TMath::Sqrt(H125a5_BD0p5 + backSum8) );
  H125a5ToBack_->SetBinContent(9, H125a5_BD0p5 / TMath::Sqrt(H125a5_BD0p5 + backSum9) );
  H125a5ToBack_->SetBinContent(10, H125a5_BD0p5 / TMath::Sqrt(H125a5_BD0p5 + backSum10) );
  H125a5ToBack_->SetBinContent(11, H125a5_BD0p5 / TMath::Sqrt(H125a5_BD0p5 + backSum11) );
  H125a5ToBack_->SetBinContent(12, H125a5_BD0p5 / TMath::Sqrt(H125a5_BD0p5 + backSum12) );
  H125a5ToBack_->SetBinContent(13, H125a5_BD0p5 / TMath::Sqrt(H125a5_BD0p5 + backSum13) );
  H125a5ToBack_->SetBinError(1, err1H125a5);
  H125a5ToBack_->SetBinError(2, err2H125a5);
  H125a5ToBack_->SetBinError(3, err3H125a5);
  H125a5ToBack_->SetBinError(4, err4H125a5);
//  H125a5ToBack_->SetBinError(5, err5H125a5);
  H125a5ToBack_->SetBinError(6, err6H125a5);
  H125a5ToBack_->SetBinError(7, err7H125a5);
  H125a5ToBack_->SetBinError(8, err8H125a5);
  H125a5ToBack_->SetBinError(9, err9H125a5);
  H125a5ToBack_->SetBinError(10, err10H125a5);
  H125a5ToBack_->SetBinError(11, err11H125a5);
  H125a5ToBack_->SetBinError(12, err12H125a5);
  H125a5ToBack_->SetBinError(13, err13H125a5);
  H125a5ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* H750a9ToBack_    = new TH1F("H750a9ToBack","", 13, -.5, 12.5);
      H750a9ToBack_->GetXaxis()->SetBinLabel(1, NEventsCutsTT_->GetXaxis()->GetBinLabel(1) );
      H750a9ToBack_->GetXaxis()->SetBinLabel(2, NEventsCutsTT_->GetXaxis()->GetBinLabel(2) );
      H750a9ToBack_->GetXaxis()->SetBinLabel(3, NEventsCutsTT_->GetXaxis()->GetBinLabel(3) );
      H750a9ToBack_->GetXaxis()->SetBinLabel(4, NEventsCutsTT_->GetXaxis()->GetBinLabel(4) );
//      H750a9ToBack_->GetXaxis()->SetBinLabel(5, NEventsCutsTT_->GetXaxis()->GetBinLabel(5) );
      H750a9ToBack_->GetXaxis()->SetBinLabel(6, NEventsCutsTT_->GetXaxis()->GetBinLabel(6));
      H750a9ToBack_->GetXaxis()->SetBinLabel(7, NEventsCutsTT_->GetXaxis()->GetBinLabel(7) );
      H750a9ToBack_->GetXaxis()->SetBinLabel(8, NEventsCutsTT_->GetXaxis()->GetBinLabel(8) );
      H750a9ToBack_->GetXaxis()->SetBinLabel(9, NEventsCutsTT_->GetXaxis()->GetBinLabel(9) );
      H750a9ToBack_->GetXaxis()->SetBinLabel(10, NEventsCutsTT_->GetXaxis()->GetBinLabel(10) );
      H750a9ToBack_->GetXaxis()->SetBinLabel(11, NEventsCutsTT_->GetXaxis()->GetBinLabel(11) );
      H750a9ToBack_->GetXaxis()->SetBinLabel(12, NEventsCutsTT_->GetXaxis()->GetBinLabel(12) );
      H750a9ToBack_->GetXaxis()->SetBinLabel(13, NEventsCutsTT_->GetXaxis()->GetBinLabel(13) );
  H750a9ToBack_->SetBinContent(1, H750a9_BD0p5 / TMath::Sqrt(H750a9_BD0p5 + backSum1) );
  H750a9ToBack_->SetBinContent(2, H750a9_BD0p5 / TMath::Sqrt(H750a9_BD0p5 + backSum2) );
  H750a9ToBack_->SetBinContent(3, H750a9_BD0p5 / TMath::Sqrt(H750a9_BD0p5 + backSum3) );
  H750a9ToBack_->SetBinContent(4, H750a9_BD0p5 / TMath::Sqrt(H750a9_BD0p5 + backSum4) );
//  H750a9ToBack_->SetBinContent(5, H750a9_BD0p5 / TMath::Sqrt(H750a9_BD0p5 + backSum5) );
  H750a9ToBack_->SetBinContent(6, H750a9_BD0p5 / TMath::Sqrt(H750a9_BD0p5 + backSum6) );
  H750a9ToBack_->SetBinContent(7, H750a9_BD0p5 / TMath::Sqrt(H750a9_BD0p5 + backSum7) );
  H750a9ToBack_->SetBinContent(8, H750a9_BD0p5 / TMath::Sqrt(H750a9_BD0p5 + backSum8) );
  H750a9ToBack_->SetBinContent(9, H750a9_BD0p5 / TMath::Sqrt(H750a9_BD0p5 + backSum9) );
  H750a9ToBack_->SetBinContent(10, H750a9_BD0p5 / TMath::Sqrt(H750a9_BD0p5 + backSum10) );
  H750a9ToBack_->SetBinContent(11, H750a9_BD0p5 / TMath::Sqrt(H750a9_BD0p5 + backSum11) );
  H750a9ToBack_->SetBinContent(12, H750a9_BD0p5 / TMath::Sqrt(H750a9_BD0p5 + backSum12) );
  H750a9ToBack_->SetBinContent(13, H750a9_BD0p5 / TMath::Sqrt(H750a9_BD0p5 + backSum13) );
  H750a9ToBack_->SetBinError(1, err1H750a9);
  H750a9ToBack_->SetBinError(2, err2H750a9);
  H750a9ToBack_->SetBinError(3, err3H750a9);
  H750a9ToBack_->SetBinError(4, err4H750a9);
//  H750a9ToBack_->SetBinError(5, err5H750a9);
  H750a9ToBack_->SetBinError(6, err6H750a9);
  H750a9ToBack_->SetBinError(7, err7H750a9);
  H750a9ToBack_->SetBinError(8, err8H750a9);
  H750a9ToBack_->SetBinError(9, err9H750a9);
  H750a9ToBack_->SetBinError(10, err10H750a9);
  H750a9ToBack_->SetBinError(11, err11H750a9);
  H750a9ToBack_->SetBinError(12, err12H750a9);
  H750a9ToBack_->SetBinError(13, err13H750a9);
  H750a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

////////////////////////////////////////////////////////
//Setting Style for Overlaid S / sqrt(S + B) Histograms
////////////////////////////////////////////////////////
  H125a19ToBack_->SetLineColor(kBlack);
  H125a9ToBack_->SetLineColor(kRed+1);
  H125a5ToBack_->SetLineColor(kBlue+1);
  H750a9ToBack_->SetLineColor(kGreen+1);

  H125a19ToBack_->SetMarkerColor(kBlack);
  H125a9ToBack_->SetMarkerColor(kRed+1);
  H125a5ToBack_->SetMarkerColor(kBlue+1);
  H750a9ToBack_->SetMarkerColor(kGreen+1);

  H125a19ToBack_->SetMarkerStyle(1);
  H125a9ToBack_->SetMarkerStyle(1);
  H125a5ToBack_->SetMarkerStyle(1);
  H750a9ToBack_->SetMarkerStyle(1);

  H125a19ToBack_->SetMarkerSize(20);
  H125a9ToBack_->SetMarkerSize(20);
  H125a5ToBack_->SetMarkerSize(20);
  H750a9ToBack_->SetMarkerSize(20);

  H125a19ToBack_->SetLineWidth(2);
  H125a9ToBack_->SetLineWidth(2);
  H125a5ToBack_->SetLineWidth(2);
  H750a9ToBack_->SetLineWidth(2);

/////////////////////////////////
// Writing Sig to Back Histogram
/////////////////////////////////
  legToBack = new TLegend(0.1,0.7,0.25,0.9);
  legToBack->AddEntry(H125a19ToBack_,"H125a19","L");
  legToBack->AddEntry(H125a9ToBack_, "H125a9", "L");
  legToBack->AddEntry(H125a5ToBack_, "H125a5", "L");
  legToBack->AddEntry(H750a9ToBack_, "H750a9", "L");

  SigToBackCanvas.cd();
  H125a19ToBack_->Draw("E1");
  H125a9ToBack_->Draw("SAME E1");
  H125a5ToBack_->Draw("SAME E1");
  H750a9ToBack_->Draw("SAME E1");
  legToBack->Draw();
  SigToBackCanvas.Write();

////////////////////////////////////////////////////////
//Setting Style for Overlaid Lepton Matched histograms
////////////////////////////////////////////////////////
  TauMuTauHaddRH125a19_->SetLineColor(kBlue+1);
  MassDiMuRECOH125a19_->SetLineColor(kBlue+1);
  MassDiTauH125a19_->SetLineColor(kBlue+1);
  PtOverMassMu1Mu2H125a19_->SetLineColor(kBlue+1);
  PtTauMuH125a19_->SetLineColor(kBlue+1);
  PtMu1Mu2H125a19_->SetLineColor(kBlue+1);
  PCSVBDiscH125a19_->SetLineColor(kBlue+1);
  SumHTH125a19_->SetLineColor(kBlue+1);
  IsoRawH125a19_->SetLineColor(kBlue+1);
  RelIsoRawH125a19_->SetLineColor(kBlue+1);
  IsoRawCutBasedH125a19_->SetLineColor(kBlue+1);

  TauMuTauHaddRH125a9_->SetLineColor(kRed);
  MassDiMuRECOH125a9_->SetLineColor(kRed);
  MassDiTauH125a9_->SetLineColor(kRed);
  PtOverMassMu1Mu2H125a9_->SetLineColor(kRed);
  PtTauMuH125a9_->SetLineColor(kRed);
  PtMu1Mu2H125a9_->SetLineColor(kRed);
  PCSVBDiscH125a9_->SetLineColor(kRed);
  SumHTH125a9_->SetLineColor(kRed);
  IsoRawH125a9_->SetLineColor(kRed);
  RelIsoRawH125a9_->SetLineColor(kRed);
  IsoRawCutBasedH125a9_->SetLineColor(kRed);

  TauMuTauHaddRH125a5_->SetLineColor(kYellow-1);
  MassDiMuRECOH125a5_->SetLineColor(kYellow-1);
  MassDiTauH125a5_->SetLineColor(kYellow-1);
  PtOverMassMu1Mu2H125a5_->SetLineColor(kYellow-1);
  PtTauMuH125a5_->SetLineColor(kYellow-1);
  PtMu1Mu2H125a5_->SetLineColor(kYellow-1);
  PCSVBDiscH125a5_->SetLineColor(kYellow-1);
  SumHTH125a5_->SetLineColor(kYellow-1);
  IsoRawH125a5_->SetLineColor(kYellow-1);
  RelIsoRawH125a5_->SetLineColor(kYellow-1);
  IsoRawCutBasedH125a5_->SetLineColor(kYellow-1);

  TauMuTauHaddRH750a9_->SetLineColor(kGreen+1);
  MassDiMuRECOH750a9_->SetLineColor(kGreen+1);
  MassDiTauH750a9_->SetLineColor(kGreen+1);
  PtOverMassMu1Mu2H750a9_->SetLineColor(kGreen+1);
  PtTauMuH750a9_->SetLineColor(kGreen+1);
  PtMu1Mu2H750a9_->SetLineColor(kGreen+1);
  PCSVBDiscH750a9_->SetLineColor(kGreen+1);
  SumHTH750a9_->SetLineColor(kGreen+1);
  IsoRawH750a9_->SetLineColor(kGreen+1);
  RelIsoRawH750a9_->SetLineColor(kGreen+1);
  IsoRawCutBasedH750a9_->SetLineColor(kGreen+1);

  TauMuTauHaddRDYH_->SetLineColor(kCyan);
  MassDiMuRECODYH_->SetLineColor(kCyan);
  MassDiTauDYH_->SetLineColor(kCyan);
  PtOverMassMu1Mu2DYH_->SetLineColor(kCyan);
  PtTauMuDYH_->SetLineColor(kCyan);
  PtMu1Mu2DYH_->SetLineColor(kCyan);
  PCSVBDiscDYH_->SetLineColor(kCyan);
  SumHTDYH_->SetLineColor(kCyan);
  IsoRawDYH_->SetLineColor(kCyan);
  RelIsoRawDYH_->SetLineColor(kCyan);
  IsoRawCutBasedDYH_->SetLineColor(kCyan);

  TauMuTauHaddRDYL_->SetLineColor(kOrange+1);
  MassDiMuRECODYL_->SetLineColor(kOrange+1);
  MassDiTauDYL_->SetLineColor(kOrange+1);
  PtOverMassMu1Mu2DYL_->SetLineColor(kOrange+1);
  PtTauMuDYL_->SetLineColor(kOrange+1);
  PtMu1Mu2DYL_->SetLineColor(kOrange+1);
  PCSVBDiscDYL_->SetLineColor(kOrange+1);
  SumHTDYL_->SetLineColor(kOrange+1);
  IsoRawDYL_->SetLineColor(kOrange+1);
  RelIsoRawDYL_->SetLineColor(kOrange+1);
  IsoRawCutBasedDYL_->SetLineColor(kOrange+1);

  TauMuTauHaddRTT_->SetLineColor(kBlack);
  MassDiMuRECOTT_->SetLineColor(kBlack);
  MassDiTauTT_->SetLineColor(kBlack);
  PtOverMassMu1Mu2TT_->SetLineColor(kBlack);
  PtTauMuTT_->SetLineColor(kBlack);
  PtMu1Mu2TT_->SetLineColor(kBlack);
  PCSVBDiscTT_->SetLineColor(kBlack);
  SumHTTT_->SetLineColor(kBlack);
  IsoRawTT_->SetLineColor(kBlack);
  RelIsoRawTT_->SetLineColor(kBlack);
  IsoRawCutBasedTT_->SetLineColor(kBlack);


  TauMuTauHaddRQCD_->SetLineColor(kViolet+1);
  MassDiMuRECOQCD_->SetLineColor(kViolet+1);
  MassDiTauQCD_->SetLineColor(kViolet+1);
  PtOverMassMu1Mu2QCD_->SetLineColor(kViolet+1);
  PtTauMuQCD_->SetLineColor(kViolet+1);
  PtMu1Mu2QCD_->SetLineColor(kViolet+1);
  PCSVBDiscQCD_->SetLineColor(kViolet+1);
  SumHTQCD_->SetLineColor(kViolet+1);
  IsoRawQCD_->SetLineColor(kViolet+1);
  RelIsoRawQCD_->SetLineColor(kViolet+1);
  IsoRawCutBasedQCD_->SetLineColor(kViolet+1);
  
  //Making the Legend
  leg = new TLegend(0.1,0.7,0.25,0.9);
  leg->AddEntry(SumHTDYH_, "DY High","L");
  leg->AddEntry(SumHTDYL_, "DY Low","L");
  leg->AddEntry(SumHTQCD_, "QCD","L");
  leg->AddEntry(SumHTTT_,   "TT","L");
  leg->AddEntry(SumHTH750a9_,  "H750a9","L");
  leg->AddEntry(SumHTH125a19_, "H125a19","L");
  leg->AddEntry(SumHTH125a9_,  "H125a9","L");
  leg->AddEntry(SumHTH125a5_,  "H125a5","L");


  //Drawing all of the Overlaid Lepton Matched HIstograms
  TauMuTauHaddRCanvas.cd();
  TauMuTauHaddRTT_->Draw();
  TauMuTauHaddRDYH_->Draw("SAME");
  TauMuTauHaddRDYL_->Draw("SAME");
  TauMuTauHaddRQCD_->Draw("SAME");
  TauMuTauHaddRH125a19_->Draw("SAME");  
  TauMuTauHaddRH125a9_->Draw("SAME");  
  TauMuTauHaddRH125a5_->Draw("SAME");  
  TauMuTauHaddRH750a9_->Draw("SAME");  
  leg->Draw();
  
  MassDiMuRECOCanvas.cd();
  MassDiMuRECOTT_->Draw();
  MassDiMuRECODYH_->Draw("SAME");
  MassDiMuRECODYL_->Draw("SAME");
  MassDiMuRECOQCD_->Draw("SAME");
  MassDiMuRECOH125a19_->Draw("SAME");
  MassDiMuRECOH125a9_->Draw("SAME");
  MassDiMuRECOH125a5_->Draw("SAME");
  MassDiMuRECOH750a9_->Draw("SAME");  
  leg->Draw();

  MassDiTauCanvas.cd();
  MassDiTauTT_->Draw();
  MassDiTauDYH_->Draw("SAME");
  MassDiTauDYL_->Draw("SAME");
  MassDiTauQCD_->Draw("SAME");
  MassDiTauH125a19_->Draw("SAME");
  MassDiTauH125a9_->Draw("SAME");
  MassDiTauH125a5_->Draw("SAME");
  MassDiTauH750a9_->Draw("SAME");  
  leg->Draw();

  PtOverMassMu1Mu2Canvas.cd();
  PtOverMassMu1Mu2TT_->Draw();
  PtOverMassMu1Mu2DYH_->Draw("SAME");
  PtOverMassMu1Mu2DYL_->Draw("SAME");
  PtOverMassMu1Mu2QCD_->Draw("SAME");
  PtOverMassMu1Mu2H125a19_->Draw("SAME");
  PtOverMassMu1Mu2H125a9_->Draw("SAME");
  PtOverMassMu1Mu2H125a5_->Draw("SAME");
  PtOverMassMu1Mu2H750a9_->Draw("SAME");  
  leg->Draw();

  PtTauMuCanvas.cd();
  PtTauMuTT_->Draw();
  PtTauMuDYH_->Draw("SAME");
  PtTauMuDYL_->Draw("SAME");
  PtTauMuQCD_->Draw("SAME");
  PtTauMuH125a19_->Draw("SAME");
  PtTauMuH125a9_->Draw("SAME");
  PtTauMuH125a5_->Draw("SAME");
  PtTauMuH750a9_->Draw("SAME");
  leg->Draw();

  PtMu1Mu2Canvas.cd();
  PtMu1Mu2TT_->Draw();
  PtMu1Mu2DYH_->Draw("SAME");
  PtMu1Mu2DYL_->Draw("SAME");
  PtMu1Mu2QCD_->Draw("SAME");
  PtMu1Mu2H125a19_->Draw("SAME");
  PtMu1Mu2H125a9_->Draw("SAME");
  PtMu1Mu2H125a5_->Draw("SAME");
  PtMu1Mu2H750a9_->Draw("SAME");  
  leg->Draw();

  PCSVBDiscCanvas.cd();
  PCSVBDiscTT_->Draw();
  PCSVBDiscDYH_->Draw("SAME");
  PCSVBDiscDYL_->Draw("SAME");
  PCSVBDiscQCD_->Draw("SAME");
  PCSVBDiscH125a19_->Draw("SAME");
  PCSVBDiscH125a9_->Draw("SAME");
  PCSVBDiscH125a5_->Draw("SAME");
  PCSVBDiscH750a9_->Draw("SAME");  
  leg->Draw();

  SumHTCanvas.cd();
  SumHTTT_->Draw();
  SumHTDYH_->Draw("SAME");
  SumHTDYL_->Draw("SAME");
  SumHTQCD_->Draw("SAME");
  SumHTH125a19_->Draw("SAME");
  SumHTH125a9_->Draw("SAME");
  SumHTH125a5_->Draw("SAME");
  SumHTH750a9_->Draw("SAME");  
  leg->Draw();

  IsoRawCanvas.cd();
  IsoRawTT_->Draw();
  IsoRawDYH_->Draw("SAME");
  IsoRawDYL_->Draw("SAME");
  IsoRawQCD_->Draw("SAME");
  IsoRawH125a19_->Draw("SAME");
  IsoRawH125a9_->Draw("SAME");
  IsoRawH125a5_->Draw("SAME");
  IsoRawH750a9_->Draw("SAME");  
  leg->Draw();

  RelIsoRawCanvas.cd();
  RelIsoRawTT_->Draw();
  RelIsoRawDYH_->Draw("SAME");
  RelIsoRawDYL_->Draw("SAME");
  RelIsoRawQCD_->Draw("SAME");
  RelIsoRawH125a19_->Draw("SAME");
  RelIsoRawH125a9_->Draw("SAME");
  RelIsoRawH125a5_->Draw("SAME");
  RelIsoRawH750a9_->Draw("SAME");
  leg->Draw();

  IsoRawCutBasedCanvas.cd();
  IsoRawCutBasedTT_->Draw();
  IsoRawCutBasedDYH_->Draw("SAME");
  IsoRawCutBasedDYL_->Draw("SAME");
  IsoRawCutBasedQCD_->Draw("SAME");
  IsoRawCutBasedH125a19_->Draw("SAME");
  IsoRawCutBasedH125a9_->Draw("SAME");
  IsoRawCutBasedH125a5_->Draw("SAME");
  IsoRawCutBasedH750a9_->Draw("SAME");
  leg->Draw();


//////////////////////////////////
// Setting the Titles for Clarity
//////////////////////////////////
  TauMuTauHaddRCanvas.SetTitle("SignalRegion");
  MassDiMuRECOCanvas.SetTitle("SignalRegion");
  MassDiTauCanvas.SetTitle("SignalRegion");
  PtOverMassMu1Mu2Canvas.SetTitle("SignalRegion");
  PtTauMuCanvas.SetTitle("SignalRegion");
  PtMu1Mu2Canvas.SetTitle("SignalRegion");
  PCSVBDiscCanvas.SetTitle("SignalRegion");
  SumHTCanvas.SetTitle("SignalRegion");
  IsoRawCanvas.SetTitle("SignalRegion");
  RelIsoRawCanvas.SetTitle("SignalRegion");
  IsoRawCutBasedCanvas.SetTitle("SignalRegion");

  TauMuTauHaddRH125a19_->SetTitle("SignalRegion");
  MassDiMuRECOH125a19_->SetTitle("SignalRegion");
  MassDiTauH125a19_->SetTitle("SignalRegion");
  PtOverMassMu1Mu2H125a19_->SetTitle("SignalRegion");
  PtTauMuH125a19_->SetTitle("SignalRegion");
  PtMu1Mu2H125a19_->SetTitle("SignalRegion");
  PCSVBDiscH125a19_->SetTitle("SignalRegion");
  SumHTH125a19_->SetTitle("SignalRegion");
  IsoRawH125a19_->SetTitle("SignalRegion");
  RelIsoRawH125a19_->SetTitle("SignalRegion");
  IsoRawCutBasedH125a19_->SetTitle("SignalRegion");

  TauMuTauHaddRH125a9_->SetTitle("SignalRegion");
  MassDiMuRECOH125a9_->SetTitle("SignalRegion");
  MassDiTauH125a9_->SetTitle("SignalRegion");
  PtOverMassMu1Mu2H125a9_->SetTitle("SignalRegion");
  PtTauMuH125a9_->SetTitle("SignalRegion");
  PtMu1Mu2H125a9_->SetTitle("SignalRegion");
  PCSVBDiscH125a9_->SetTitle("SignalRegion");
  SumHTH125a9_->SetTitle("SignalRegion");
  IsoRawH125a9_->SetTitle("SignalRegion");
  RelIsoRawH125a9_->SetTitle("SignalRegion");
  IsoRawCutBasedH125a9_->SetTitle("SignalRegion");

  TauMuTauHaddRH125a5_->SetTitle("SignalRegion");
  MassDiMuRECOH125a5_->SetTitle("SignalRegion");
  MassDiTauH125a5_->SetTitle("SignalRegion");
  PtOverMassMu1Mu2H125a5_->SetTitle("SignalRegion");
  PtTauMuH125a5_->SetTitle("SignalRegion");
  PtMu1Mu2H125a5_->SetTitle("SignalRegion");
  PCSVBDiscH125a5_->SetTitle("SignalRegion");
  SumHTH125a5_->SetTitle("SignalRegion");
  IsoRawH125a5_->SetTitle("SignalRegion");
  RelIsoRawH125a5_->SetTitle("SignalRegion");
  IsoRawCutBasedH125a5_->SetTitle("SignalRegion");

  TauMuTauHaddRH750a9_->SetTitle("SignalRegion");
  MassDiMuRECOH750a9_->SetTitle("SignalRegion");
  MassDiTauH750a9_->SetTitle("SignalRegion");
  PtOverMassMu1Mu2H750a9_->SetTitle("SignalRegion");
  PtTauMuH750a9_->SetTitle("SignalRegion");
  PtMu1Mu2H750a9_->SetTitle("SignalRegion");
  PCSVBDiscH750a9_->SetTitle("SignalRegion");
  SumHTH750a9_->SetTitle("SignalRegion");
  IsoRawH750a9_->SetTitle("SignalRegion");
  RelIsoRawH750a9_->SetTitle("SignalRegion");
  IsoRawCutBasedH750a9_->SetTitle("SignalRegion");

  TauMuTauHaddRDYH_->SetTitle("SignalRegion");
  MassDiMuRECODYH_->SetTitle("SignalRegion");
  MassDiTauDYH_->SetTitle("SignalRegion");
  PtOverMassMu1Mu2DYH_->SetTitle("SignalRegion");
  PtTauMuDYH_->SetTitle("SignalRegion");
  PtMu1Mu2DYH_->SetTitle("SignalRegion");
  PCSVBDiscDYH_->SetTitle("SignalRegion");
  SumHTDYH_->SetTitle("SignalRegion");
  IsoRawDYH_->SetTitle("SignalRegion");
  RelIsoRawDYH_->SetTitle("SignalRegion");
  IsoRawCutBasedDYH_->SetTitle("SignalRegion");

  TauMuTauHaddRDYL_->SetTitle("SignalRegion");
  MassDiMuRECODYL_->SetTitle("SignalRegion");
  MassDiTauDYL_->SetTitle("SignalRegion");
  PtOverMassMu1Mu2DYL_->SetTitle("SignalRegion");
  PtTauMuDYL_->SetTitle("SignalRegion");
  PtMu1Mu2DYL_->SetTitle("SignalRegion");
  PCSVBDiscDYL_->SetTitle("SignalRegion");
  SumHTDYL_->SetTitle("SignalRegion");
  IsoRawDYL_->SetTitle("SignalRegion");
  RelIsoRawDYL_->SetTitle("SignalRegion");
  IsoRawCutBasedDYL_->SetTitle("SignalRegion");

  TauMuTauHaddRQCD_->SetTitle("SignalRegion");
  MassDiMuRECOQCD_->SetTitle("SignalRegion");
  MassDiTauQCD_->SetTitle("SignalRegion");
  PtOverMassMu1Mu2QCD_->SetTitle("SignalRegion");
  PtTauMuQCD_->SetTitle("SignalRegion");
  PtMu1Mu2QCD_->SetTitle("SignalRegion");
  PCSVBDiscQCD_->SetTitle("SignalRegion");
  SumHTQCD_->SetTitle("SignalRegion");
  IsoRawQCD_->SetTitle("SignalRegion");
  RelIsoRawQCD_->SetTitle("SignalRegion");
  IsoRawCutBasedQCD_->SetTitle("SignalRegion");

  TauMuTauHaddRTT_->SetTitle("SignalRegion");
  MassDiMuRECOTT_->SetTitle("SignalRegion");
  MassDiTauTT_->SetTitle("SignalRegion");
  PtOverMassMu1Mu2TT_->SetTitle("SignalRegion");
  PtTauMuTT_->SetTitle("SignalRegion");
  PtMu1Mu2TT_->SetTitle("SignalRegion");
  PCSVBDiscTT_->SetTitle("SignalRegion");
  SumHTTT_->SetTitle("SignalRegion");
  IsoRawTT_->SetTitle("SignalRegion");
  RelIsoRawTT_->SetTitle("SignalRegion");
  IsoRawCutBasedTT_->SetTitle("SignalRegion");


cout << "Histograms Drawn" << endl;

  outFile->cd();

  TauMuTauHaddRCanvas.Write();
  MassDiMuRECOCanvas.Write();
  MassDiTauCanvas.Write();
  PtOverMassMu1Mu2Canvas.Write();
  PtTauMuCanvas.Write();
  PtMu1Mu2Canvas.Write();
  PCSVBDiscCanvas.Write();
  SumHTCanvas.Write();
  IsoRawCanvas.Write();
  RelIsoRawCanvas.Write();
  IsoRawCutBasedCanvas.Write();

  outFile->Write();
  outFile->Close();
cout << "end" << endl;

}//rootMacro_BBA_combine
