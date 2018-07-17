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

void rootMacro_DiMu_ExtraPlots()
{
  setTDRStyle(true);
  gStyle->SetPalette(1);


  //Old DMs
  TFile infileDYL("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_DYLowMass_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileDYH("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_DYHighMass_DiMu_TauDMAntiMedIso_NOV27.root");
//  TFile infileJPsi("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_JPsi_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileQCD_1000toInf("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_QCD_1000toInf_MiniAOD_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileQCD_120to170("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_QCD_120to170_MiniAOD_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileQCD_15to20("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_QCD_15to20_MiniAOD_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileQCD_170to300("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_QCD_170to300_MiniAOD_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileQCD_20to30("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_QCD_20to30_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileQCD_300to470("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_QCD_300to470_MiniAOD_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileQCD_30to50("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_QCD_30to50_MiniAOD_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileQCD_470to600("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_QCD_470to600_MiniAOD_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileQCD_50to80("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_QCD_50to80_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileQCD_600to800("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_QCD_600to800_MiniAOD_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileQCD_800to1000("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_QCD_800to1000_MiniAOD_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileQCD_80to120("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_QCD_80to120_MiniAOD_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh125a11("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h125a11_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh125a13("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h125a13_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh125a15("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h125a15_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh125a17("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h125a17_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh125a19("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h125a19_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh125a21("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h125a21_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh125a5("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h125a5_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh125a7("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h125a7_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh125a9("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h125a9_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh300a11("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h300a11_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh300a13("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h300a13_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh300a15("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h300a15_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh300a17("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h300a17_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh300a19("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h300a19_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh300a21("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h300a21_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh300a5("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h300a5_DiMu_TauDMAntiMedIso_NOV27.root  ");
  TFile infileh300a7("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h300a7_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh300a9("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h300a9_DiMu_TauDMAntiMedIso_NOV27.root  ");
  TFile infileh750a11("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h750a11_DiMu_TauDMAntiMedIso_NOV27.root ");
  TFile infileh750a13("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h750a13_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh750a15("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h750a15_DiMu_TauDMAntiMedIso_NOV27.root ");
  TFile infileh750a17("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h750a17_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh750a19("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h750a19_DiMu_TauDMAntiMedIso_NOV27.root  ");
  TFile infileh750a21("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h750a21_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh750a5("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h750a5_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh750a7("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h750a7_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileh750a9("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SIG_h750a9_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileData1("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SingleMu1_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileData2("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_SingleMu2_DiMu_TauDMAntiMedIso_NOV27.root");
//  TFile infileTTDiLep("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_TTJetsDiLep_DiMu_TauDMAntiMedIso_NOV27.root");
//  TFile infileTTSingLep("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_TTSingLepT_DiMu_TauDMAntiMedIso_NOV27.root");
//  TFile infileTTBarSingLep("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_TTSingLepTBar_DiMu_TauDMAntiMedIso_NOV27.root");
//  TFile infileTTJetsMad("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_TTJetsMadG_DiMu_TauDMAntiMedIso_NOV27.root  ");
//  TFile infileTTJetsAmac("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_TTJetsAmac_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileTT("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_TT_DiMu_TauDMAntiMedIso_NOV27.root");
//  TFile infileUp("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_Upsilon_DiMu_TauDMAntiMedIso_NOV27.root");
//  TFile infileVV("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_VV_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileWJAmac("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_WJAmac_DiMu_TauDMAntiMedIso_NOV27.root");
//  TFile infileWJMad("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_WJMadG_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileWZ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_WZ3L1Nu_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileZZ2L2Nu("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_ZZTo2L2Nu_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileZZ2L2Q("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_ZZTo2L2Q_DiMu_TauDMAntiMedIso_NOV27.root");
  TFile infileZZ4LAmac("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_ZZTo4LAmac_DiMu_TauDMAntiMedIso_NOV27.root ");
//  TFile infileZZ4LPowh("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DiMuIsoAntiTauMedIso/FINAL_MiniAOD_ZZTo4LPowh_DiMu_TauDMAntiMedIso_NOV27.root ");


  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/Stack_DiMu_ExtraPlots_DiMu_TauDMAntiMedIso_NOV27.root", "RECREATE");

cout << "Files Created" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Canvases
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////
  // TT
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasTT = (TCanvas*)infileTT.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasTT = (TCanvas*)infileTT.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasTT = (TCanvas*)infileTT.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasTT = (TCanvas*)infileTT.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasTT = (TCanvas*)infileTT.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasTT = (TCanvas*)infileTT.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasTT = (TCanvas*)infileTT.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasTT = (TCanvas*)infileTT.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasTT = (TCanvas*)infileTT.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasTT = (TCanvas*)infileTT.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasTT = (TCanvas*)infileTT.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasTT = (TCanvas*)infileTT.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasTT = (TCanvas*)infileTT.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasTT = (TCanvas*)infileTT.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasTT = (TCanvas*)infileTT.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasTT = (TCanvas*)infileTT.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasTT = (TCanvas*)infileTT.Get("DiMuEta");
  TCanvas *DiMudRCanvasTT = (TCanvas*)infileTT.Get("DiMudR");
  TCanvas *DiMuPhiCanvasTT = (TCanvas*)infileTT.Get("DiMuPhi");
  TCanvas *EtMETCanvasTT = (TCanvas*)infileTT.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasTT = (TCanvas*)infileTT.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasTT = (TCanvas*)infileTT.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasTT = (TCanvas*)infileTT.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasTT = (TCanvas*)infileTT.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasTT = (TCanvas*)infileTT.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasTT = (TCanvas*)infileTT.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasTT = (TCanvas*)infileTT.Get("HighestCSVInclJet");

  ////////////////
  // DYL
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasDYL = (TCanvas*)infileDYL.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasDYL = (TCanvas*)infileDYL.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasDYL = (TCanvas*)infileDYL.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasDYL = (TCanvas*)infileDYL.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasDYL = (TCanvas*)infileDYL.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasDYL = (TCanvas*)infileDYL.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasDYL = (TCanvas*)infileDYL.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasDYL = (TCanvas*)infileDYL.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasDYL = (TCanvas*)infileDYL.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasDYL = (TCanvas*)infileDYL.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasDYL = (TCanvas*)infileDYL.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasDYL = (TCanvas*)infileDYL.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasDYL = (TCanvas*)infileDYL.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasDYL = (TCanvas*)infileDYL.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasDYL = (TCanvas*)infileDYL.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasDYL = (TCanvas*)infileDYL.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasDYL = (TCanvas*)infileDYL.Get("DiMuEta");
  TCanvas *DiMudRCanvasDYL = (TCanvas*)infileDYL.Get("DiMudR");
  TCanvas *DiMuPhiCanvasDYL = (TCanvas*)infileDYL.Get("DiMuPhi");
  TCanvas *EtMETCanvasDYL = (TCanvas*)infileDYL.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasDYL = (TCanvas*)infileDYL.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasDYL = (TCanvas*)infileDYL.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasDYL = (TCanvas*)infileDYL.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasDYL = (TCanvas*)infileDYL.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasDYL = (TCanvas*)infileDYL.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasDYL = (TCanvas*)infileDYL.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasDYL = (TCanvas*)infileDYL.Get("HighestCSVInclJet");

  ////////////////
  // DYH
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasDYH = (TCanvas*)infileDYH.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasDYH = (TCanvas*)infileDYH.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasDYH = (TCanvas*)infileDYH.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasDYH = (TCanvas*)infileDYH.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasDYH = (TCanvas*)infileDYH.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasDYH = (TCanvas*)infileDYH.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasDYH = (TCanvas*)infileDYH.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasDYH = (TCanvas*)infileDYH.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasDYH = (TCanvas*)infileDYH.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasDYH = (TCanvas*)infileDYH.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasDYH = (TCanvas*)infileDYH.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasDYH = (TCanvas*)infileDYH.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasDYH = (TCanvas*)infileDYH.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasDYH = (TCanvas*)infileDYH.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasDYH = (TCanvas*)infileDYH.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasDYH = (TCanvas*)infileDYH.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasDYH = (TCanvas*)infileDYH.Get("DiMuEta");
  TCanvas *DiMudRCanvasDYH = (TCanvas*)infileDYH.Get("DiMudR");
  TCanvas *DiMuPhiCanvasDYH = (TCanvas*)infileDYH.Get("DiMuPhi");
  TCanvas *EtMETCanvasDYH = (TCanvas*)infileDYH.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasDYH = (TCanvas*)infileDYH.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasDYH = (TCanvas*)infileDYH.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasDYH = (TCanvas*)infileDYH.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasDYH = (TCanvas*)infileDYH.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasDYH = (TCanvas*)infileDYH.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasDYH = (TCanvas*)infileDYH.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasDYH = (TCanvas*)infileDYH.Get("HighestCSVInclJet");

  ////////////////
  // QCD_1000toInf
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("DiMuEta");
  TCanvas *DiMudRCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("DiMudR");
  TCanvas *DiMuPhiCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("DiMuPhi");
  TCanvas *EtMETCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasQCD_1000toInf = (TCanvas*)infileQCD_1000toInf.Get("HighestCSVInclJet");

  ////////////////
  // QCD_120to170
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("DiMuEta");
  TCanvas *DiMudRCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("DiMudR");
  TCanvas *DiMuPhiCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("DiMuPhi");
  TCanvas *EtMETCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasQCD_120to170 = (TCanvas*)infileQCD_120to170.Get("HighestCSVInclJet");

  ////////////////
  // QCD_15to20
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("DiMuEta");
  TCanvas *DiMudRCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("DiMudR");
  TCanvas *DiMuPhiCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("DiMuPhi");
  TCanvas *EtMETCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasQCD_15to20 = (TCanvas*)infileQCD_15to20.Get("HighestCSVInclJet");

  ////////////////
  // QCD_170to300
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("DiMuEta");
  TCanvas *DiMudRCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("DiMudR");
  TCanvas *DiMuPhiCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("DiMuPhi");
  TCanvas *EtMETCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasQCD_170to300 = (TCanvas*)infileQCD_170to300.Get("HighestCSVInclJet");

  ////////////////
  // QCD_20to30
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("DiMuEta");
  TCanvas *DiMudRCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("DiMudR");
  TCanvas *DiMuPhiCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("DiMuPhi");
  TCanvas *EtMETCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasQCD_20to30 = (TCanvas*)infileQCD_20to30.Get("HighestCSVInclJet");

  ////////////////
  // QCD_300to470
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("DiMuEta");
  TCanvas *DiMudRCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("DiMudR");
  TCanvas *DiMuPhiCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("DiMuPhi");
  TCanvas *EtMETCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasQCD_300to470 = (TCanvas*)infileQCD_300to470.Get("HighestCSVInclJet");

  ////////////////
  // QCD_30to50
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("DiMuEta");
  TCanvas *DiMudRCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("DiMudR");
  TCanvas *DiMuPhiCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("DiMuPhi");
  TCanvas *EtMETCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasQCD_30to50 = (TCanvas*)infileQCD_30to50.Get("HighestCSVInclJet");

  ////////////////
  // QCD_470to600
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("DiMuEta");
  TCanvas *DiMudRCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("DiMudR");
  TCanvas *DiMuPhiCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("DiMuPhi");
  TCanvas *EtMETCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasQCD_470to600 = (TCanvas*)infileQCD_470to600.Get("HighestCSVInclJet");

  ////////////////
  // QCD_50to80
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("DiMuEta");
  TCanvas *DiMudRCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("DiMudR");
  TCanvas *DiMuPhiCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("DiMuPhi");
  TCanvas *EtMETCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasQCD_50to80 = (TCanvas*)infileQCD_50to80.Get("HighestCSVInclJet");

  ////////////////
  // QCD_600to800
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("DiMuEta");
  TCanvas *DiMudRCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("DiMudR");
  TCanvas *DiMuPhiCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("DiMuPhi");
  TCanvas *EtMETCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasQCD_600to800 = (TCanvas*)infileQCD_600to800.Get("HighestCSVInclJet");

  ////////////////
  // QCD_800to1000
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("DiMuEta");
  TCanvas *DiMudRCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("DiMudR");
  TCanvas *DiMuPhiCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("DiMuPhi");
  TCanvas *EtMETCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasQCD_800to1000 = (TCanvas*)infileQCD_800to1000.Get("HighestCSVInclJet");

  ////////////////
  // QCD_80to120
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("DiMuEta");
  TCanvas *DiMudRCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("DiMudR");
  TCanvas *DiMuPhiCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("DiMuPhi");
  TCanvas *EtMETCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasQCD_80to120 = (TCanvas*)infileQCD_80to120.Get("HighestCSVInclJet");

  ////////////////
  // h125a11
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash125a11 = (TCanvas*)infileh125a11.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash125a11 = (TCanvas*)infileh125a11.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash125a11 = (TCanvas*)infileh125a11.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a11 = (TCanvas*)infileh125a11.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a11 = (TCanvas*)infileh125a11.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a11 = (TCanvas*)infileh125a11.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash125a11 = (TCanvas*)infileh125a11.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash125a11 = (TCanvas*)infileh125a11.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash125a11 = (TCanvas*)infileh125a11.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a11 = (TCanvas*)infileh125a11.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a11 = (TCanvas*)infileh125a11.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a11 = (TCanvas*)infileh125a11.Get("DiMudR");
  TCanvas *DiMuPhiCanvash125a11 = (TCanvas*)infileh125a11.Get("DiMuPhi");
  TCanvas *EtMETCanvash125a11 = (TCanvas*)infileh125a11.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a11 = (TCanvas*)infileh125a11.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a11 = (TCanvas*)infileh125a11.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a11 = (TCanvas*)infileh125a11.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash125a11 = (TCanvas*)infileh125a11.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash125a11 = (TCanvas*)infileh125a11.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash125a11 = (TCanvas*)infileh125a11.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash125a11 = (TCanvas*)infileh125a11.Get("HighestCSVInclJet");

  ////////////////
  // h125a13
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash125a13 = (TCanvas*)infileh125a13.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash125a13 = (TCanvas*)infileh125a13.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash125a13 = (TCanvas*)infileh125a13.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a13 = (TCanvas*)infileh125a13.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a13 = (TCanvas*)infileh125a13.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a13 = (TCanvas*)infileh125a13.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash125a13 = (TCanvas*)infileh125a13.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash125a13 = (TCanvas*)infileh125a13.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash125a13 = (TCanvas*)infileh125a13.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a13 = (TCanvas*)infileh125a13.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a13 = (TCanvas*)infileh125a13.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a13 = (TCanvas*)infileh125a13.Get("DiMudR");
  TCanvas *DiMuPhiCanvash125a13 = (TCanvas*)infileh125a13.Get("DiMuPhi");
  TCanvas *EtMETCanvash125a13 = (TCanvas*)infileh125a13.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a13 = (TCanvas*)infileh125a13.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a13 = (TCanvas*)infileh125a13.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a13 = (TCanvas*)infileh125a13.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash125a13 = (TCanvas*)infileh125a13.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash125a13 = (TCanvas*)infileh125a13.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash125a13 = (TCanvas*)infileh125a13.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash125a13 = (TCanvas*)infileh125a13.Get("HighestCSVInclJet");

  ////////////////
  // h125a15
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash125a15 = (TCanvas*)infileh125a15.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash125a15 = (TCanvas*)infileh125a15.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash125a15 = (TCanvas*)infileh125a15.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a15 = (TCanvas*)infileh125a15.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a15 = (TCanvas*)infileh125a15.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a15 = (TCanvas*)infileh125a15.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash125a15 = (TCanvas*)infileh125a15.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash125a15 = (TCanvas*)infileh125a15.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash125a15 = (TCanvas*)infileh125a15.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a15 = (TCanvas*)infileh125a15.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a15 = (TCanvas*)infileh125a15.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a15 = (TCanvas*)infileh125a15.Get("DiMudR");
  TCanvas *DiMuPhiCanvash125a15 = (TCanvas*)infileh125a15.Get("DiMuPhi");
  TCanvas *EtMETCanvash125a15 = (TCanvas*)infileh125a15.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a15 = (TCanvas*)infileh125a15.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a15 = (TCanvas*)infileh125a15.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a15 = (TCanvas*)infileh125a15.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash125a15 = (TCanvas*)infileh125a15.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash125a15 = (TCanvas*)infileh125a15.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash125a15 = (TCanvas*)infileh125a15.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash125a15 = (TCanvas*)infileh125a15.Get("HighestCSVInclJet");

  ////////////////
  // h125a17
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash125a17 = (TCanvas*)infileh125a17.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash125a17 = (TCanvas*)infileh125a17.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash125a17 = (TCanvas*)infileh125a17.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a17 = (TCanvas*)infileh125a17.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a17 = (TCanvas*)infileh125a17.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a17 = (TCanvas*)infileh125a17.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash125a17 = (TCanvas*)infileh125a17.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash125a17 = (TCanvas*)infileh125a17.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash125a17 = (TCanvas*)infileh125a17.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a17 = (TCanvas*)infileh125a17.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a17 = (TCanvas*)infileh125a17.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a17 = (TCanvas*)infileh125a17.Get("DiMudR");
  TCanvas *DiMuPhiCanvash125a17 = (TCanvas*)infileh125a17.Get("DiMuPhi");
  TCanvas *EtMETCanvash125a17 = (TCanvas*)infileh125a17.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a17 = (TCanvas*)infileh125a17.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a17 = (TCanvas*)infileh125a17.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a17 = (TCanvas*)infileh125a17.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash125a17 = (TCanvas*)infileh125a17.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash125a17 = (TCanvas*)infileh125a17.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash125a17 = (TCanvas*)infileh125a17.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash125a17 = (TCanvas*)infileh125a17.Get("HighestCSVInclJet");

  ////////////////
  // h125a19
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash125a19 = (TCanvas*)infileh125a19.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash125a19 = (TCanvas*)infileh125a19.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash125a19 = (TCanvas*)infileh125a19.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a19 = (TCanvas*)infileh125a19.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a19 = (TCanvas*)infileh125a19.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a19 = (TCanvas*)infileh125a19.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash125a19 = (TCanvas*)infileh125a19.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash125a19 = (TCanvas*)infileh125a19.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash125a19 = (TCanvas*)infileh125a19.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a19 = (TCanvas*)infileh125a19.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a19 = (TCanvas*)infileh125a19.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a19 = (TCanvas*)infileh125a19.Get("DiMudR");
  TCanvas *DiMuPhiCanvash125a19 = (TCanvas*)infileh125a19.Get("DiMuPhi");
  TCanvas *EtMETCanvash125a19 = (TCanvas*)infileh125a19.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a19 = (TCanvas*)infileh125a19.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a19 = (TCanvas*)infileh125a19.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a19 = (TCanvas*)infileh125a19.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash125a19 = (TCanvas*)infileh125a19.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash125a19 = (TCanvas*)infileh125a19.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash125a19 = (TCanvas*)infileh125a19.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash125a19 = (TCanvas*)infileh125a19.Get("HighestCSVInclJet");

  ////////////////
  // h125a21
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash125a21 = (TCanvas*)infileh125a21.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash125a21 = (TCanvas*)infileh125a21.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash125a21 = (TCanvas*)infileh125a21.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a21 = (TCanvas*)infileh125a21.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a21 = (TCanvas*)infileh125a21.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a21 = (TCanvas*)infileh125a21.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash125a21 = (TCanvas*)infileh125a21.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash125a21 = (TCanvas*)infileh125a21.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash125a21 = (TCanvas*)infileh125a21.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a21 = (TCanvas*)infileh125a21.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a21 = (TCanvas*)infileh125a21.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a21 = (TCanvas*)infileh125a21.Get("DiMudR");
  TCanvas *DiMuPhiCanvash125a21 = (TCanvas*)infileh125a21.Get("DiMuPhi");
  TCanvas *EtMETCanvash125a21 = (TCanvas*)infileh125a21.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a21 = (TCanvas*)infileh125a21.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a21 = (TCanvas*)infileh125a21.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a21 = (TCanvas*)infileh125a21.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash125a21 = (TCanvas*)infileh125a21.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash125a21 = (TCanvas*)infileh125a21.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash125a21 = (TCanvas*)infileh125a21.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash125a21 = (TCanvas*)infileh125a21.Get("HighestCSVInclJet");

  ////////////////
  // h125a5
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash125a5 = (TCanvas*)infileh125a5.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash125a5 = (TCanvas*)infileh125a5.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash125a5 = (TCanvas*)infileh125a5.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a5 = (TCanvas*)infileh125a5.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a5 = (TCanvas*)infileh125a5.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a5 = (TCanvas*)infileh125a5.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash125a5 = (TCanvas*)infileh125a5.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash125a5 = (TCanvas*)infileh125a5.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash125a5 = (TCanvas*)infileh125a5.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a5 = (TCanvas*)infileh125a5.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a5 = (TCanvas*)infileh125a5.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a5 = (TCanvas*)infileh125a5.Get("DiMudR");
  TCanvas *DiMuPhiCanvash125a5 = (TCanvas*)infileh125a5.Get("DiMuPhi");
  TCanvas *EtMETCanvash125a5 = (TCanvas*)infileh125a5.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a5 = (TCanvas*)infileh125a5.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a5 = (TCanvas*)infileh125a5.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a5 = (TCanvas*)infileh125a5.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash125a5 = (TCanvas*)infileh125a5.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash125a5 = (TCanvas*)infileh125a5.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash125a5 = (TCanvas*)infileh125a5.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash125a5 = (TCanvas*)infileh125a5.Get("HighestCSVInclJet");

  ////////////////
  // h125a7
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash125a7 = (TCanvas*)infileh125a7.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash125a7 = (TCanvas*)infileh125a7.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash125a7 = (TCanvas*)infileh125a7.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a7 = (TCanvas*)infileh125a7.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a7 = (TCanvas*)infileh125a7.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a7 = (TCanvas*)infileh125a7.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash125a7 = (TCanvas*)infileh125a7.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash125a7 = (TCanvas*)infileh125a7.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash125a7 = (TCanvas*)infileh125a7.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a7 = (TCanvas*)infileh125a7.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a7 = (TCanvas*)infileh125a7.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a7 = (TCanvas*)infileh125a7.Get("DiMudR");
  TCanvas *DiMuPhiCanvash125a7 = (TCanvas*)infileh125a7.Get("DiMuPhi");
  TCanvas *EtMETCanvash125a7 = (TCanvas*)infileh125a7.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a7 = (TCanvas*)infileh125a7.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a7 = (TCanvas*)infileh125a7.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a7 = (TCanvas*)infileh125a7.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash125a7 = (TCanvas*)infileh125a7.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash125a7 = (TCanvas*)infileh125a7.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash125a7 = (TCanvas*)infileh125a7.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash125a7 = (TCanvas*)infileh125a7.Get("HighestCSVInclJet");

  ////////////////
  // h125a9
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash125a9 = (TCanvas*)infileh125a9.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash125a9 = (TCanvas*)infileh125a9.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash125a9 = (TCanvas*)infileh125a9.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a9 = (TCanvas*)infileh125a9.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a9 = (TCanvas*)infileh125a9.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a9 = (TCanvas*)infileh125a9.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash125a9 = (TCanvas*)infileh125a9.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash125a9 = (TCanvas*)infileh125a9.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash125a9 = (TCanvas*)infileh125a9.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a9 = (TCanvas*)infileh125a9.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a9 = (TCanvas*)infileh125a9.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a9 = (TCanvas*)infileh125a9.Get("DiMudR");
  TCanvas *DiMuPhiCanvash125a9 = (TCanvas*)infileh125a9.Get("DiMuPhi");
  TCanvas *EtMETCanvash125a9 = (TCanvas*)infileh125a9.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a9 = (TCanvas*)infileh125a9.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a9 = (TCanvas*)infileh125a9.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a9 = (TCanvas*)infileh125a9.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash125a9 = (TCanvas*)infileh125a9.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash125a9 = (TCanvas*)infileh125a9.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash125a9 = (TCanvas*)infileh125a9.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash125a9 = (TCanvas*)infileh125a9.Get("HighestCSVInclJet");

  ////////////////
  // h300a11
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash300a11 = (TCanvas*)infileh300a11.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash300a11 = (TCanvas*)infileh300a11.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash300a11 = (TCanvas*)infileh300a11.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a11 = (TCanvas*)infileh300a11.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a11 = (TCanvas*)infileh300a11.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a11 = (TCanvas*)infileh300a11.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash300a11 = (TCanvas*)infileh300a11.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash300a11 = (TCanvas*)infileh300a11.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash300a11 = (TCanvas*)infileh300a11.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a11 = (TCanvas*)infileh300a11.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a11 = (TCanvas*)infileh300a11.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a11 = (TCanvas*)infileh300a11.Get("DiMudR");
  TCanvas *DiMuPhiCanvash300a11 = (TCanvas*)infileh300a11.Get("DiMuPhi");
  TCanvas *EtMETCanvash300a11 = (TCanvas*)infileh300a11.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a11 = (TCanvas*)infileh300a11.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a11 = (TCanvas*)infileh300a11.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a11 = (TCanvas*)infileh300a11.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash300a11 = (TCanvas*)infileh300a11.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash300a11 = (TCanvas*)infileh300a11.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash300a11 = (TCanvas*)infileh300a11.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash300a11 = (TCanvas*)infileh300a11.Get("HighestCSVInclJet");

  ////////////////
  // h300a13
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash300a13 = (TCanvas*)infileh300a13.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash300a13 = (TCanvas*)infileh300a13.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash300a13 = (TCanvas*)infileh300a13.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a13 = (TCanvas*)infileh300a13.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a13 = (TCanvas*)infileh300a13.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a13 = (TCanvas*)infileh300a13.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash300a13 = (TCanvas*)infileh300a13.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash300a13 = (TCanvas*)infileh300a13.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash300a13 = (TCanvas*)infileh300a13.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a13 = (TCanvas*)infileh300a13.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a13 = (TCanvas*)infileh300a13.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a13 = (TCanvas*)infileh300a13.Get("DiMudR");
  TCanvas *DiMuPhiCanvash300a13 = (TCanvas*)infileh300a13.Get("DiMuPhi");
  TCanvas *EtMETCanvash300a13 = (TCanvas*)infileh300a13.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a13 = (TCanvas*)infileh300a13.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a13 = (TCanvas*)infileh300a13.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a13 = (TCanvas*)infileh300a13.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash300a13 = (TCanvas*)infileh300a13.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash300a13 = (TCanvas*)infileh300a13.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash300a13 = (TCanvas*)infileh300a13.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash300a13 = (TCanvas*)infileh300a13.Get("HighestCSVInclJet");

  ////////////////
  // h300a15
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash300a15 = (TCanvas*)infileh300a15.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash300a15 = (TCanvas*)infileh300a15.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash300a15 = (TCanvas*)infileh300a15.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a15 = (TCanvas*)infileh300a15.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a15 = (TCanvas*)infileh300a15.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a15 = (TCanvas*)infileh300a15.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash300a15 = (TCanvas*)infileh300a15.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash300a15 = (TCanvas*)infileh300a15.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash300a15 = (TCanvas*)infileh300a15.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a15 = (TCanvas*)infileh300a15.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a15 = (TCanvas*)infileh300a15.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a15 = (TCanvas*)infileh300a15.Get("DiMudR");
  TCanvas *DiMuPhiCanvash300a15 = (TCanvas*)infileh300a15.Get("DiMuPhi");
  TCanvas *EtMETCanvash300a15 = (TCanvas*)infileh300a15.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a15 = (TCanvas*)infileh300a15.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a15 = (TCanvas*)infileh300a15.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a15 = (TCanvas*)infileh300a15.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash300a15 = (TCanvas*)infileh300a15.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash300a15 = (TCanvas*)infileh300a15.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash300a15 = (TCanvas*)infileh300a15.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash300a15 = (TCanvas*)infileh300a15.Get("HighestCSVInclJet");

  ////////////////
  // h300a17
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash300a17 = (TCanvas*)infileh300a17.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash300a17 = (TCanvas*)infileh300a17.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash300a17 = (TCanvas*)infileh300a17.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a17 = (TCanvas*)infileh300a17.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a17 = (TCanvas*)infileh300a17.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a17 = (TCanvas*)infileh300a17.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash300a17 = (TCanvas*)infileh300a17.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash300a17 = (TCanvas*)infileh300a17.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash300a17 = (TCanvas*)infileh300a17.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a17 = (TCanvas*)infileh300a17.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a17 = (TCanvas*)infileh300a17.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a17 = (TCanvas*)infileh300a17.Get("DiMudR");
  TCanvas *DiMuPhiCanvash300a17 = (TCanvas*)infileh300a17.Get("DiMuPhi");
  TCanvas *EtMETCanvash300a17 = (TCanvas*)infileh300a17.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a17 = (TCanvas*)infileh300a17.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a17 = (TCanvas*)infileh300a17.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a17 = (TCanvas*)infileh300a17.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash300a17 = (TCanvas*)infileh300a17.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash300a17 = (TCanvas*)infileh300a17.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash300a17 = (TCanvas*)infileh300a17.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash300a17 = (TCanvas*)infileh300a17.Get("HighestCSVInclJet");

  ////////////////
  // h300a19
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash300a19 = (TCanvas*)infileh300a19.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash300a19 = (TCanvas*)infileh300a19.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash300a19 = (TCanvas*)infileh300a19.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a19 = (TCanvas*)infileh300a19.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a19 = (TCanvas*)infileh300a19.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a19 = (TCanvas*)infileh300a19.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash300a19 = (TCanvas*)infileh300a19.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash300a19 = (TCanvas*)infileh300a19.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash300a19 = (TCanvas*)infileh300a19.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a19 = (TCanvas*)infileh300a19.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a19 = (TCanvas*)infileh300a19.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a19 = (TCanvas*)infileh300a19.Get("DiMudR");
  TCanvas *DiMuPhiCanvash300a19 = (TCanvas*)infileh300a19.Get("DiMuPhi");
  TCanvas *EtMETCanvash300a19 = (TCanvas*)infileh300a19.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a19 = (TCanvas*)infileh300a19.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a19 = (TCanvas*)infileh300a19.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a19 = (TCanvas*)infileh300a19.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash300a19 = (TCanvas*)infileh300a19.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash300a19 = (TCanvas*)infileh300a19.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash300a19 = (TCanvas*)infileh300a19.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash300a19 = (TCanvas*)infileh300a19.Get("HighestCSVInclJet");

  ////////////////
  // h300a21
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash300a21 = (TCanvas*)infileh300a21.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash300a21 = (TCanvas*)infileh300a21.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash300a21 = (TCanvas*)infileh300a21.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a21 = (TCanvas*)infileh300a21.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a21 = (TCanvas*)infileh300a21.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a21 = (TCanvas*)infileh300a21.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash300a21 = (TCanvas*)infileh300a21.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash300a21 = (TCanvas*)infileh300a21.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash300a21 = (TCanvas*)infileh300a21.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a21 = (TCanvas*)infileh300a21.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a21 = (TCanvas*)infileh300a21.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a21 = (TCanvas*)infileh300a21.Get("DiMudR");
  TCanvas *DiMuPhiCanvash300a21 = (TCanvas*)infileh300a21.Get("DiMuPhi");
  TCanvas *EtMETCanvash300a21 = (TCanvas*)infileh300a21.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a21 = (TCanvas*)infileh300a21.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a21 = (TCanvas*)infileh300a21.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a21 = (TCanvas*)infileh300a21.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash300a21 = (TCanvas*)infileh300a21.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash300a21 = (TCanvas*)infileh300a21.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash300a21 = (TCanvas*)infileh300a21.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash300a21 = (TCanvas*)infileh300a21.Get("HighestCSVInclJet");

  ////////////////
  // h300a5
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash300a5 = (TCanvas*)infileh300a5.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash300a5 = (TCanvas*)infileh300a5.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash300a5 = (TCanvas*)infileh300a5.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a5 = (TCanvas*)infileh300a5.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a5 = (TCanvas*)infileh300a5.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a5 = (TCanvas*)infileh300a5.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash300a5 = (TCanvas*)infileh300a5.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash300a5 = (TCanvas*)infileh300a5.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash300a5 = (TCanvas*)infileh300a5.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a5 = (TCanvas*)infileh300a5.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a5 = (TCanvas*)infileh300a5.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a5 = (TCanvas*)infileh300a5.Get("DiMudR");
  TCanvas *DiMuPhiCanvash300a5 = (TCanvas*)infileh300a5.Get("DiMuPhi");
  TCanvas *EtMETCanvash300a5 = (TCanvas*)infileh300a5.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a5 = (TCanvas*)infileh300a5.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a5 = (TCanvas*)infileh300a5.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a5 = (TCanvas*)infileh300a5.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash300a5 = (TCanvas*)infileh300a5.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash300a5 = (TCanvas*)infileh300a5.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash300a5 = (TCanvas*)infileh300a5.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash300a5 = (TCanvas*)infileh300a5.Get("HighestCSVInclJet");

  ////////////////
  // h300a7
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash300a7 = (TCanvas*)infileh300a7.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash300a7 = (TCanvas*)infileh300a7.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash300a7 = (TCanvas*)infileh300a7.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a7 = (TCanvas*)infileh300a7.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a7 = (TCanvas*)infileh300a7.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a7 = (TCanvas*)infileh300a7.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash300a7 = (TCanvas*)infileh300a7.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash300a7 = (TCanvas*)infileh300a7.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash300a7 = (TCanvas*)infileh300a7.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a7 = (TCanvas*)infileh300a7.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a7 = (TCanvas*)infileh300a7.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a7 = (TCanvas*)infileh300a7.Get("DiMudR");
  TCanvas *DiMuPhiCanvash300a7 = (TCanvas*)infileh300a7.Get("DiMuPhi");
  TCanvas *EtMETCanvash300a7 = (TCanvas*)infileh300a7.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a7 = (TCanvas*)infileh300a7.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a7 = (TCanvas*)infileh300a7.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a7 = (TCanvas*)infileh300a7.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash300a7 = (TCanvas*)infileh300a7.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash300a7 = (TCanvas*)infileh300a7.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash300a7 = (TCanvas*)infileh300a7.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash300a7 = (TCanvas*)infileh300a7.Get("HighestCSVInclJet");

  ////////////////
  // h300a9
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash300a9 = (TCanvas*)infileh300a9.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash300a9 = (TCanvas*)infileh300a9.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash300a9 = (TCanvas*)infileh300a9.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a9 = (TCanvas*)infileh300a9.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a9 = (TCanvas*)infileh300a9.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a9 = (TCanvas*)infileh300a9.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash300a9 = (TCanvas*)infileh300a9.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash300a9 = (TCanvas*)infileh300a9.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash300a9 = (TCanvas*)infileh300a9.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a9 = (TCanvas*)infileh300a9.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a9 = (TCanvas*)infileh300a9.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a9 = (TCanvas*)infileh300a9.Get("DiMudR");
  TCanvas *DiMuPhiCanvash300a9 = (TCanvas*)infileh300a9.Get("DiMuPhi");
  TCanvas *EtMETCanvash300a9 = (TCanvas*)infileh300a9.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a9 = (TCanvas*)infileh300a9.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a9 = (TCanvas*)infileh300a9.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a9 = (TCanvas*)infileh300a9.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash300a9 = (TCanvas*)infileh300a9.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash300a9 = (TCanvas*)infileh300a9.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash300a9 = (TCanvas*)infileh300a9.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash300a9 = (TCanvas*)infileh300a9.Get("HighestCSVInclJet");

  ////////////////
  // h750a11
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash750a11 = (TCanvas*)infileh750a11.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash750a11 = (TCanvas*)infileh750a11.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash750a11 = (TCanvas*)infileh750a11.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a11 = (TCanvas*)infileh750a11.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a11 = (TCanvas*)infileh750a11.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a11 = (TCanvas*)infileh750a11.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash750a11 = (TCanvas*)infileh750a11.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash750a11 = (TCanvas*)infileh750a11.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash750a11 = (TCanvas*)infileh750a11.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a11 = (TCanvas*)infileh750a11.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a11 = (TCanvas*)infileh750a11.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a11 = (TCanvas*)infileh750a11.Get("DiMudR");
  TCanvas *DiMuPhiCanvash750a11 = (TCanvas*)infileh750a11.Get("DiMuPhi");
  TCanvas *EtMETCanvash750a11 = (TCanvas*)infileh750a11.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a11 = (TCanvas*)infileh750a11.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a11 = (TCanvas*)infileh750a11.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a11 = (TCanvas*)infileh750a11.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash750a11 = (TCanvas*)infileh750a11.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash750a11 = (TCanvas*)infileh750a11.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash750a11 = (TCanvas*)infileh750a11.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash750a11 = (TCanvas*)infileh750a11.Get("HighestCSVInclJet");

  ////////////////
  // h750a13
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash750a13 = (TCanvas*)infileh750a13.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash750a13 = (TCanvas*)infileh750a13.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash750a13 = (TCanvas*)infileh750a13.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a13 = (TCanvas*)infileh750a13.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a13 = (TCanvas*)infileh750a13.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a13 = (TCanvas*)infileh750a13.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash750a13 = (TCanvas*)infileh750a13.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash750a13 = (TCanvas*)infileh750a13.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash750a13 = (TCanvas*)infileh750a13.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a13 = (TCanvas*)infileh750a13.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a13 = (TCanvas*)infileh750a13.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a13 = (TCanvas*)infileh750a13.Get("DiMudR");
  TCanvas *DiMuPhiCanvash750a13 = (TCanvas*)infileh750a13.Get("DiMuPhi");
  TCanvas *EtMETCanvash750a13 = (TCanvas*)infileh750a13.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a13 = (TCanvas*)infileh750a13.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a13 = (TCanvas*)infileh750a13.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a13 = (TCanvas*)infileh750a13.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash750a13 = (TCanvas*)infileh750a13.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash750a13 = (TCanvas*)infileh750a13.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash750a13 = (TCanvas*)infileh750a13.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash750a13 = (TCanvas*)infileh750a13.Get("HighestCSVInclJet");

  ////////////////
  // h750a15
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash750a15 = (TCanvas*)infileh750a15.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash750a15 = (TCanvas*)infileh750a15.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash750a15 = (TCanvas*)infileh750a15.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a15 = (TCanvas*)infileh750a15.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a15 = (TCanvas*)infileh750a15.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a15 = (TCanvas*)infileh750a15.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash750a15 = (TCanvas*)infileh750a15.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash750a15 = (TCanvas*)infileh750a15.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash750a15 = (TCanvas*)infileh750a15.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a15 = (TCanvas*)infileh750a15.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a15 = (TCanvas*)infileh750a15.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a15 = (TCanvas*)infileh750a15.Get("DiMudR");
  TCanvas *DiMuPhiCanvash750a15 = (TCanvas*)infileh750a15.Get("DiMuPhi");
  TCanvas *EtMETCanvash750a15 = (TCanvas*)infileh750a15.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a15 = (TCanvas*)infileh750a15.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a15 = (TCanvas*)infileh750a15.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a15 = (TCanvas*)infileh750a15.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash750a15 = (TCanvas*)infileh750a15.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash750a15 = (TCanvas*)infileh750a15.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash750a15 = (TCanvas*)infileh750a15.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash750a15 = (TCanvas*)infileh750a15.Get("HighestCSVInclJet");

  ////////////////
  // h750a17
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash750a17 = (TCanvas*)infileh750a17.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash750a17 = (TCanvas*)infileh750a17.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash750a17 = (TCanvas*)infileh750a17.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a17 = (TCanvas*)infileh750a17.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a17 = (TCanvas*)infileh750a17.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a17 = (TCanvas*)infileh750a17.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash750a17 = (TCanvas*)infileh750a17.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash750a17 = (TCanvas*)infileh750a17.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash750a17 = (TCanvas*)infileh750a17.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a17 = (TCanvas*)infileh750a17.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a17 = (TCanvas*)infileh750a17.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a17 = (TCanvas*)infileh750a17.Get("DiMudR");
  TCanvas *DiMuPhiCanvash750a17 = (TCanvas*)infileh750a17.Get("DiMuPhi");
  TCanvas *EtMETCanvash750a17 = (TCanvas*)infileh750a17.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a17 = (TCanvas*)infileh750a17.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a17 = (TCanvas*)infileh750a17.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a17 = (TCanvas*)infileh750a17.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash750a17 = (TCanvas*)infileh750a17.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash750a17 = (TCanvas*)infileh750a17.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash750a17 = (TCanvas*)infileh750a17.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash750a17 = (TCanvas*)infileh750a17.Get("HighestCSVInclJet");

  ////////////////
  // h750a19
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash750a19 = (TCanvas*)infileh750a19.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash750a19 = (TCanvas*)infileh750a19.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash750a19 = (TCanvas*)infileh750a19.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a19 = (TCanvas*)infileh750a19.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a19 = (TCanvas*)infileh750a19.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a19 = (TCanvas*)infileh750a19.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash750a19 = (TCanvas*)infileh750a19.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash750a19 = (TCanvas*)infileh750a19.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash750a19 = (TCanvas*)infileh750a19.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a19 = (TCanvas*)infileh750a19.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a19 = (TCanvas*)infileh750a19.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a19 = (TCanvas*)infileh750a19.Get("DiMudR");
  TCanvas *DiMuPhiCanvash750a19 = (TCanvas*)infileh750a19.Get("DiMuPhi");
  TCanvas *EtMETCanvash750a19 = (TCanvas*)infileh750a19.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a19 = (TCanvas*)infileh750a19.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a19 = (TCanvas*)infileh750a19.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a19 = (TCanvas*)infileh750a19.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash750a19 = (TCanvas*)infileh750a19.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash750a19 = (TCanvas*)infileh750a19.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash750a19 = (TCanvas*)infileh750a19.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash750a19 = (TCanvas*)infileh750a19.Get("HighestCSVInclJet");

  ////////////////
  // h750a21
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash750a21 = (TCanvas*)infileh750a21.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash750a21 = (TCanvas*)infileh750a21.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash750a21 = (TCanvas*)infileh750a21.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a21 = (TCanvas*)infileh750a21.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a21 = (TCanvas*)infileh750a21.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a21 = (TCanvas*)infileh750a21.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash750a21 = (TCanvas*)infileh750a21.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash750a21 = (TCanvas*)infileh750a21.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash750a21 = (TCanvas*)infileh750a21.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a21 = (TCanvas*)infileh750a21.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a21 = (TCanvas*)infileh750a21.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a21 = (TCanvas*)infileh750a21.Get("DiMudR");
  TCanvas *DiMuPhiCanvash750a21 = (TCanvas*)infileh750a21.Get("DiMuPhi");
  TCanvas *EtMETCanvash750a21 = (TCanvas*)infileh750a21.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a21 = (TCanvas*)infileh750a21.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a21 = (TCanvas*)infileh750a21.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a21 = (TCanvas*)infileh750a21.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash750a21 = (TCanvas*)infileh750a21.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash750a21 = (TCanvas*)infileh750a21.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash750a21 = (TCanvas*)infileh750a21.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash750a21 = (TCanvas*)infileh750a21.Get("HighestCSVInclJet");

  ////////////////
  // h750a5
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash750a5 = (TCanvas*)infileh750a5.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash750a5 = (TCanvas*)infileh750a5.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash750a5 = (TCanvas*)infileh750a5.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a5 = (TCanvas*)infileh750a5.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a5 = (TCanvas*)infileh750a5.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a5 = (TCanvas*)infileh750a5.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash750a5 = (TCanvas*)infileh750a5.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash750a5 = (TCanvas*)infileh750a5.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash750a5 = (TCanvas*)infileh750a5.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a5 = (TCanvas*)infileh750a5.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a5 = (TCanvas*)infileh750a5.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a5 = (TCanvas*)infileh750a5.Get("DiMudR");
  TCanvas *DiMuPhiCanvash750a5 = (TCanvas*)infileh750a5.Get("DiMuPhi");
  TCanvas *EtMETCanvash750a5 = (TCanvas*)infileh750a5.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a5 = (TCanvas*)infileh750a5.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a5 = (TCanvas*)infileh750a5.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a5 = (TCanvas*)infileh750a5.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash750a5 = (TCanvas*)infileh750a5.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash750a5 = (TCanvas*)infileh750a5.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash750a5 = (TCanvas*)infileh750a5.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash750a5 = (TCanvas*)infileh750a5.Get("HighestCSVInclJet");

  ////////////////
  // h750a7
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash750a7 = (TCanvas*)infileh750a7.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash750a7 = (TCanvas*)infileh750a7.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash750a7 = (TCanvas*)infileh750a7.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a7 = (TCanvas*)infileh750a7.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a7 = (TCanvas*)infileh750a7.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a7 = (TCanvas*)infileh750a7.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash750a7 = (TCanvas*)infileh750a7.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash750a7 = (TCanvas*)infileh750a7.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash750a7 = (TCanvas*)infileh750a7.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a7 = (TCanvas*)infileh750a7.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a7 = (TCanvas*)infileh750a7.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a7 = (TCanvas*)infileh750a7.Get("DiMudR");
  TCanvas *DiMuPhiCanvash750a7 = (TCanvas*)infileh750a7.Get("DiMuPhi");
  TCanvas *EtMETCanvash750a7 = (TCanvas*)infileh750a7.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a7 = (TCanvas*)infileh750a7.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a7 = (TCanvas*)infileh750a7.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a7 = (TCanvas*)infileh750a7.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash750a7 = (TCanvas*)infileh750a7.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash750a7 = (TCanvas*)infileh750a7.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash750a7 = (TCanvas*)infileh750a7.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash750a7 = (TCanvas*)infileh750a7.Get("HighestCSVInclJet");

  ////////////////
  // h750a9
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash750a9 = (TCanvas*)infileh750a9.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash750a9 = (TCanvas*)infileh750a9.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash750a9 = (TCanvas*)infileh750a9.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a9 = (TCanvas*)infileh750a9.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a9 = (TCanvas*)infileh750a9.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a9 = (TCanvas*)infileh750a9.Get("DiMuPt");
  TCanvas *Mu1EtaCanvash750a9 = (TCanvas*)infileh750a9.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvash750a9 = (TCanvas*)infileh750a9.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvash750a9 = (TCanvas*)infileh750a9.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a9 = (TCanvas*)infileh750a9.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a9 = (TCanvas*)infileh750a9.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a9 = (TCanvas*)infileh750a9.Get("DiMudR");
  TCanvas *DiMuPhiCanvash750a9 = (TCanvas*)infileh750a9.Get("DiMuPhi");
  TCanvas *EtMETCanvash750a9 = (TCanvas*)infileh750a9.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a9 = (TCanvas*)infileh750a9.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a9 = (TCanvas*)infileh750a9.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a9 = (TCanvas*)infileh750a9.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash750a9 = (TCanvas*)infileh750a9.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash750a9 = (TCanvas*)infileh750a9.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash750a9 = (TCanvas*)infileh750a9.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash750a9 = (TCanvas*)infileh750a9.Get("HighestCSVInclJet");

  ////////////////
  // Data1
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasData1 = (TCanvas*)infileData1.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasData1 = (TCanvas*)infileData1.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasData1 = (TCanvas*)infileData1.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasData1 = (TCanvas*)infileData1.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasData1 = (TCanvas*)infileData1.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasData1 = (TCanvas*)infileData1.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasData1 = (TCanvas*)infileData1.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasData1 = (TCanvas*)infileData1.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasData1 = (TCanvas*)infileData1.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasData1 = (TCanvas*)infileData1.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasData1 = (TCanvas*)infileData1.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasData1 = (TCanvas*)infileData1.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasData1 = (TCanvas*)infileData1.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasData1 = (TCanvas*)infileData1.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasData1 = (TCanvas*)infileData1.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasData1 = (TCanvas*)infileData1.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasData1 = (TCanvas*)infileData1.Get("DiMuEta");
  TCanvas *DiMudRCanvasData1 = (TCanvas*)infileData1.Get("DiMudR");
  TCanvas *DiMuPhiCanvasData1 = (TCanvas*)infileData1.Get("DiMuPhi");
  TCanvas *EtMETCanvasData1 = (TCanvas*)infileData1.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasData1 = (TCanvas*)infileData1.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasData1 = (TCanvas*)infileData1.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasData1 = (TCanvas*)infileData1.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasData1 = (TCanvas*)infileData1.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasData1 = (TCanvas*)infileData1.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasData1 = (TCanvas*)infileData1.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasData1 = (TCanvas*)infileData1.Get("HighestCSVInclJet");

  ////////////////
  // Data2
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasData2 = (TCanvas*)infileData2.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasData2 = (TCanvas*)infileData2.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasData2 = (TCanvas*)infileData2.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasData2 = (TCanvas*)infileData2.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasData2 = (TCanvas*)infileData2.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasData2 = (TCanvas*)infileData2.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasData2 = (TCanvas*)infileData2.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasData2 = (TCanvas*)infileData2.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasData2 = (TCanvas*)infileData2.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasData2 = (TCanvas*)infileData2.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasData2 = (TCanvas*)infileData2.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasData2 = (TCanvas*)infileData2.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasData2 = (TCanvas*)infileData2.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasData2 = (TCanvas*)infileData2.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasData2 = (TCanvas*)infileData2.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasData2 = (TCanvas*)infileData2.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasData2 = (TCanvas*)infileData2.Get("DiMuEta");
  TCanvas *DiMudRCanvasData2 = (TCanvas*)infileData2.Get("DiMudR");
  TCanvas *DiMuPhiCanvasData2 = (TCanvas*)infileData2.Get("DiMuPhi");
  TCanvas *EtMETCanvasData2 = (TCanvas*)infileData2.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasData2 = (TCanvas*)infileData2.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasData2 = (TCanvas*)infileData2.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasData2 = (TCanvas*)infileData2.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasData2 = (TCanvas*)infileData2.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasData2 = (TCanvas*)infileData2.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasData2 = (TCanvas*)infileData2.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasData2 = (TCanvas*)infileData2.Get("HighestCSVInclJet");

//  ////////////////
//  // TTDiLep
//  ////////////////
//  TCanvas *NMedIsoTausWithMu3CanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("NMedIsoTausWithMu3");
//  TCanvas *InvMassTauHadMu3CanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("InvMassTauHadMu3");
//  TCanvas *PtTauHadMu3CanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("PtTauHadMu3");
//  TCanvas *InvMassUpsilonRangeCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("InvMassUpsilonRange");
//  TCanvas *InvMassZPeakRangeCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("InvMassZPeakRange");
//  TCanvas *InvMassFullRangeCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("InvMassFullRange");
//  TCanvas *InvMassDiMuBarrBarrCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("InvMassDiMuBarrBarr");
//  TCanvas *InvMassDiMuBarrEndcCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("InvMassDiMuBarrEndc");
//  TCanvas *InvMassDiMuEndcEndcCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("InvMassDiMuEndcEndc");
//  TCanvas *Mu1PtCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("Mu1Pt");
//  TCanvas *Mu2PtCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("Mu2Pt");
//  TCanvas *DiMuPtCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("DiMuPt");
//  TCanvas *Mu1EtaCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("Mu1Eta");
//  TCanvas *Mu2EtaCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("Mu2Eta");
//  TCanvas *DiTauEtaCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("DiTauEta");
//  TCanvas *DiTauPhiCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("DiTauPhi");
//  TCanvas *DiMuEtaCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("DiMuEta");
//  TCanvas *DiMudRCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("DiMudR");
//  TCanvas *DiMuPhiCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("DiMuPhi");
//  TCanvas *EtMETCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("EtMET");
//  TCanvas *DiTauDiMuMassCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("DiTauDiMuMass");
//  TCanvas *DiMuDiTauDeltaPhiCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("DiMuDiTauDeltaPhi");
//  TCanvas *METDiTauDeltaPhiCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("METDiMuDeltaPhi");
//  TCanvas *METDiMuDeltaPhiCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("METDiMuDeltaPhi");
//  TCanvas *DiTaudRCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("DiTaudR");
//  TCanvas *DiTauMassSmallerdRCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("DiTauMassSmallerdR");
//  TCanvas *HighestCSVInclJetCanvasTTDiLep = (TCanvas*)infileTTDiLep.Get("HighestCSVInclJet");
//
//  ////////////////
//  // TTBarSingLep
//  ////////////////
//  TCanvas *NMedIsoTausWithMu3CanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("NMedIsoTausWithMu3");
//  TCanvas *InvMassTauHadMu3CanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("InvMassTauHadMu3");
//  TCanvas *PtTauHadMu3CanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("PtTauHadMu3");
//  TCanvas *InvMassUpsilonRangeCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("InvMassUpsilonRange");
//  TCanvas *InvMassZPeakRangeCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("InvMassZPeakRange");
//  TCanvas *InvMassFullRangeCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("InvMassFullRange");
//  TCanvas *InvMassDiMuBarrBarrCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("InvMassDiMuBarrBarr");
//  TCanvas *InvMassDiMuBarrEndcCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("InvMassDiMuBarrEndc");
//  TCanvas *InvMassDiMuEndcEndcCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("InvMassDiMuEndcEndc");
//  TCanvas *Mu1PtCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("Mu1Pt");
//  TCanvas *Mu2PtCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("Mu2Pt");
//  TCanvas *DiMuPtCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("DiMuPt");
//  TCanvas *Mu1EtaCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("Mu1Eta");
//  TCanvas *Mu2EtaCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("Mu2Eta");
//  TCanvas *DiTauEtaCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("DiTauEta");
//  TCanvas *DiTauPhiCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("DiTauPhi");
//  TCanvas *DiMuEtaCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("DiMuEta");
//  TCanvas *DiMudRCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("DiMudR");
//  TCanvas *DiMuPhiCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("DiMuPhi");
//  TCanvas *EtMETCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("EtMET");
//  TCanvas *DiTauDiMuMassCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("DiTauDiMuMass");
//  TCanvas *DiMuDiTauDeltaPhiCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("DiMuDiTauDeltaPhi");
//  TCanvas *METDiTauDeltaPhiCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("METDiMuDeltaPhi");
//  TCanvas *METDiMuDeltaPhiCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("METDiMuDeltaPhi");
//  TCanvas *DiTaudRCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("DiTaudR");
//  TCanvas *DiTauMassSmallerdRCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("DiTauMassSmallerdR");
//  TCanvas *HighestCSVInclJetCanvasTTBarSingLep = (TCanvas*)infileTTBarSingLep.Get("HighestCSVInclJet");
//
//  ////////////////
//  // TTSingLep
//  ////////////////
//  TCanvas *NMedIsoTausWithMu3CanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("NMedIsoTausWithMu3");
//  TCanvas *InvMassTauHadMu3CanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("InvMassTauHadMu3");
//  TCanvas *PtTauHadMu3CanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("PtTauHadMu3");
//  TCanvas *InvMassUpsilonRangeCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("InvMassUpsilonRange");
//  TCanvas *InvMassZPeakRangeCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("InvMassZPeakRange");
//  TCanvas *InvMassFullRangeCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("InvMassFullRange");
//  TCanvas *InvMassDiMuBarrBarrCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("InvMassDiMuBarrBarr");
//  TCanvas *InvMassDiMuBarrEndcCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("InvMassDiMuBarrEndc");
//  TCanvas *InvMassDiMuEndcEndcCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("InvMassDiMuEndcEndc");
//  TCanvas *Mu1PtCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("Mu1Pt");
//  TCanvas *Mu2PtCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("Mu2Pt");
//  TCanvas *DiMuPtCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("DiMuPt");
//  TCanvas *Mu1EtaCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("Mu1Eta");
//  TCanvas *Mu2EtaCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("Mu2Eta");
//  TCanvas *DiTauEtaCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("DiTauEta");
//  TCanvas *DiTauPhiCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("DiTauPhi");
//  TCanvas *DiMuEtaCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("DiMuEta");
//  TCanvas *DiMudRCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("DiMudR");
//  TCanvas *DiMuPhiCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("DiMuPhi");
//  TCanvas *EtMETCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("EtMET");
//  TCanvas *DiTauDiMuMassCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("DiTauDiMuMass");
//  TCanvas *DiMuDiTauDeltaPhiCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("DiMuDiTauDeltaPhi");
//  TCanvas *METDiTauDeltaPhiCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("METDiMuDeltaPhi");
//  TCanvas *METDiMuDeltaPhiCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("METDiMuDeltaPhi");
//  TCanvas *DiTaudRCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("DiTaudR");
//  TCanvas *DiTauMassSmallerdRCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("DiTauMassSmallerdR");
//  TCanvas *HighestCSVInclJetCanvasTTSingLep = (TCanvas*)infileTTSingLep.Get("HighestCSVInclJet");
//
//  ////////////////
//  // TTJetsMad
//  ////////////////
//  TCanvas *NMedIsoTausWithMu3CanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("NMedIsoTausWithMu3");
//  TCanvas *InvMassTauHadMu3CanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("InvMassTauHadMu3");
//  TCanvas *PtTauHadMu3CanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("PtTauHadMu3");
//  TCanvas *InvMassUpsilonRangeCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("InvMassUpsilonRange");
//  TCanvas *InvMassZPeakRangeCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("InvMassZPeakRange");
//  TCanvas *InvMassFullRangeCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("InvMassFullRange");
//  TCanvas *InvMassDiMuBarrBarrCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("InvMassDiMuBarrBarr");
//  TCanvas *InvMassDiMuBarrEndcCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("InvMassDiMuBarrEndc");
//  TCanvas *InvMassDiMuEndcEndcCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("InvMassDiMuEndcEndc");
//  TCanvas *Mu1PtCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("Mu1Pt");
//  TCanvas *Mu2PtCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("Mu2Pt");
//  TCanvas *DiMuPtCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("DiMuPt");
//  TCanvas *Mu1EtaCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("Mu1Eta");
//  TCanvas *Mu2EtaCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("Mu2Eta");
//  TCanvas *DiTauEtaCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("DiTauEta");
//  TCanvas *DiTauPhiCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("DiTauPhi");
//  TCanvas *DiMuEtaCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("DiMuEta");
//  TCanvas *DiMudRCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("DiMudR");
//  TCanvas *DiMuPhiCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("DiMuPhi");
//  TCanvas *EtMETCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("EtMET");
//  TCanvas *DiTauDiMuMassCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("DiTauDiMuMass");
//  TCanvas *DiMuDiTauDeltaPhiCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("DiMuDiTauDeltaPhi");
//  TCanvas *METDiTauDeltaPhiCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("METDiMuDeltaPhi");
//  TCanvas *METDiMuDeltaPhiCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("METDiMuDeltaPhi");
//  TCanvas *DiTaudRCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("DiTaudR");
//  TCanvas *DiTauMassSmallerdRCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("DiTauMassSmallerdR");
//  TCanvas *HighestCSVInclJetCanvasTTJetsMad = (TCanvas*)infileTTJetsMad.Get("HighestCSVInclJet");
//
//  ////////////////
//  // TTJetsAmac
//  ////////////////
//  TCanvas *NMedIsoTausWithMu3CanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("NMedIsoTausWithMu3");
//  TCanvas *InvMassTauHadMu3CanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("InvMassTauHadMu3");
//  TCanvas *PtTauHadMu3CanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("PtTauHadMu3");
//  TCanvas *InvMassUpsilonRangeCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("InvMassUpsilonRange");
//  TCanvas *InvMassZPeakRangeCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("InvMassZPeakRange");
//  TCanvas *InvMassFullRangeCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("InvMassFullRange");
//  TCanvas *InvMassDiMuBarrBarrCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("InvMassDiMuBarrBarr");
//  TCanvas *InvMassDiMuBarrEndcCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("InvMassDiMuBarrEndc");
//  TCanvas *InvMassDiMuEndcEndcCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("InvMassDiMuEndcEndc");
//  TCanvas *Mu1PtCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("Mu1Pt");
//  TCanvas *Mu2PtCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("Mu2Pt");
//  TCanvas *DiMuPtCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("DiMuPt");
//  TCanvas *Mu1EtaCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("Mu1Eta");
//  TCanvas *Mu2EtaCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("Mu2Eta");
//  TCanvas *DiTauEtaCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("DiTauEta");
//  TCanvas *DiTauPhiCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("DiTauPhi");
//  TCanvas *DiMuEtaCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("DiMuEta");
//  TCanvas *DiMudRCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("DiMudR");
//  TCanvas *DiMuPhiCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("DiMuPhi");
//  TCanvas *EtMETCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("EtMET");
//  TCanvas *DiTauDiMuMassCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("DiTauDiMuMass");
//  TCanvas *DiMuDiTauDeltaPhiCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("DiMuDiTauDeltaPhi");
//  TCanvas *METDiTauDeltaPhiCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("METDiMuDeltaPhi");
//  TCanvas *METDiMuDeltaPhiCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("METDiMuDeltaPhi");
//  TCanvas *DiTaudRCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("DiTaudR");
//  TCanvas *DiTauMassSmallerdRCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("DiTauMassSmallerdR");
//  TCanvas *HighestCSVInclJetCanvasTTJetsAmac = (TCanvas*)infileTTJetsAmac.Get("HighestCSVInclJet");
//
//  ////////////////
//  // Up
//  ////////////////
//  TCanvas *NMedIsoTausWithMu3CanvasUp = (TCanvas*)infileUp.Get("NMedIsoTausWithMu3");
//  TCanvas *InvMassTauHadMu3CanvasUp = (TCanvas*)infileUp.Get("InvMassTauHadMu3");
//  TCanvas *PtTauHadMu3CanvasUp = (TCanvas*)infileUp.Get("PtTauHadMu3");
//  TCanvas *InvMassUpsilonRangeCanvasUp = (TCanvas*)infileUp.Get("InvMassUpsilonRange");
//  TCanvas *InvMassZPeakRangeCanvasUp = (TCanvas*)infileUp.Get("InvMassZPeakRange");
//  TCanvas *InvMassFullRangeCanvasUp = (TCanvas*)infileUp.Get("InvMassFullRange");
//  TCanvas *InvMassDiMuBarrBarrCanvasUp = (TCanvas*)infileUp.Get("InvMassDiMuBarrBarr");
//  TCanvas *InvMassDiMuBarrEndcCanvasUp = (TCanvas*)infileUp.Get("InvMassDiMuBarrEndc");
//  TCanvas *InvMassDiMuEndcEndcCanvasUp = (TCanvas*)infileUp.Get("InvMassDiMuEndcEndc");
//  TCanvas *Mu1PtCanvasUp = (TCanvas*)infileUp.Get("Mu1Pt");
//  TCanvas *Mu2PtCanvasUp = (TCanvas*)infileUp.Get("Mu2Pt");
//  TCanvas *DiMuPtCanvasUp = (TCanvas*)infileUp.Get("DiMuPt");
//  TCanvas *Mu1EtaCanvasUp = (TCanvas*)infileUp.Get("Mu1Eta");
//  TCanvas *Mu2EtaCanvasUp = (TCanvas*)infileUp.Get("Mu2Eta");
//  TCanvas *DiTauEtaCanvasUp = (TCanvas*)infileUp.Get("DiTauEta");
//  TCanvas *DiTauPhiCanvasUp = (TCanvas*)infileUp.Get("DiTauPhi");
//  TCanvas *DiMuEtaCanvasUp = (TCanvas*)infileUp.Get("DiMuEta");
//  TCanvas *DiMudRCanvasUp = (TCanvas*)infileUp.Get("DiMudR");
//  TCanvas *DiMuPhiCanvasUp = (TCanvas*)infileUp.Get("DiMuPhi");
//  TCanvas *EtMETCanvasUp = (TCanvas*)infileUp.Get("EtMET");
//  TCanvas *DiTauDiMuMassCanvasUp = (TCanvas*)infileUp.Get("DiTauDiMuMass");
//  TCanvas *DiMuDiTauDeltaPhiCanvasUp = (TCanvas*)infileUp.Get("DiMuDiTauDeltaPhi");
//  TCanvas *METDiTauDeltaPhiCanvasUp = (TCanvas*)infileUp.Get("METDiMuDeltaPhi");
//  TCanvas *METDiMuDeltaPhiCanvasUp = (TCanvas*)infileUp.Get("METDiMuDeltaPhi");
//  TCanvas *DiTaudRCanvasUp = (TCanvas*)infileUp.Get("DiTaudR");
//  TCanvas *DiTauMassSmallerdRCanvasUp = (TCanvas*)infileUp.Get("DiTauMassSmallerdR");
//  TCanvas *HighestCSVInclJetCanvasUp = (TCanvas*)infileUp.Get("HighestCSVInclJet");
//
//  ////////////////
//  // VV
  ////////////////
//  TCanvas *NMedIsoTausWithMu3CanvasVV = (TCanvas*)infileVV.Get("NMedIsoTausWithMu3");
//  TCanvas *InvMassTauHadMu3CanvasVV = (TCanvas*)infileVV.Get("InvMassTauHadMu3");
//  TCanvas *PtTauHadMu3CanvasVV = (TCanvas*)infileVV.Get("PtTauHadMu3");
//  TCanvas *InvMassUpsilonRangeCanvasVV = (TCanvas*)infileVV.Get("InvMassUpsilonRange");
//  TCanvas *InvMassZPeakRangeCanvasVV = (TCanvas*)infileVV.Get("InvMassZPeakRange");
//  TCanvas *InvMassFullRangeCanvasVV = (TCanvas*)infileVV.Get("InvMassFullRange");
//  TCanvas *InvMassDiMuBarrBarrCanvasVV = (TCanvas*)infileVV.Get("InvMassDiMuBarrBarr");
//  TCanvas *InvMassDiMuBarrEndcCanvasVV = (TCanvas*)infileVV.Get("InvMassDiMuBarrEndc");
//  TCanvas *InvMassDiMuEndcEndcCanvasVV = (TCanvas*)infileVV.Get("InvMassDiMuEndcEndc");
//  TCanvas *Mu1PtCanvasVV = (TCanvas*)infileVV.Get("Mu1Pt");
//  TCanvas *Mu2PtCanvasVV = (TCanvas*)infileVV.Get("Mu2Pt");
//  TCanvas *DiMuPtCanvasVV = (TCanvas*)infileVV.Get("DiMuPt");
//  TCanvas *Mu1EtaCanvasVV = (TCanvas*)infileVV.Get("Mu1Eta");
//  TCanvas *Mu2EtaCanvasVV = (TCanvas*)infileVV.Get("Mu2Eta");
//  TCanvas *DiTauEtaCanvasVV = (TCanvas*)infileVV.Get("DiTauEta");
//  TCanvas *DiTauPhiCanvasVV = (TCanvas*)infileVV.Get("DiTauPhi");
//  TCanvas *DiMuEtaCanvasVV = (TCanvas*)infileVV.Get("DiMuEta");
//  TCanvas *DiMudRCanvasVV = (TCanvas*)infileVV.Get("DiMudR");
//  TCanvas *DiMuPhiCanvasVV = (TCanvas*)infileVV.Get("DiMuPhi");
//  TCanvas *EtMETCanvasVV = (TCanvas*)infileVV.Get("EtMET");
//  TCanvas *DiTauDiMuMassCanvasVV = (TCanvas*)infileVV.Get("DiTauDiMuMass");
//  TCanvas *DiMuDiTauDeltaPhiCanvasVV = (TCanvas*)infileVV.Get("DiMuDiTauDeltaPhi");
//  TCanvas *METDiTauDeltaPhiCanvasVV = (TCanvas*)infileVV.Get("METDiMuDeltaPhi");
//  TCanvas *METDiMuDeltaPhiCanvasVV = (TCanvas*)infileVV.Get("METDiMuDeltaPhi");
//  TCanvas *DiTaudRCanvasVV = (TCanvas*)infileVV.Get("DiTaudR");
//  TCanvas *DiTauMassSmallerdRCanvasVV = (TCanvas*)infileVV.Get("DiTauMassSmallerdR");
//  TCanvas *HighestCSVInclJetCanvasVV = (TCanvas*)infileVV.Get("HighestCSVInclJet");

  ////////////////
  // WJAmac
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasWJAmac = (TCanvas*)infileWJAmac.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasWJAmac = (TCanvas*)infileWJAmac.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasWJAmac = (TCanvas*)infileWJAmac.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasWJAmac = (TCanvas*)infileWJAmac.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasWJAmac = (TCanvas*)infileWJAmac.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasWJAmac = (TCanvas*)infileWJAmac.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasWJAmac = (TCanvas*)infileWJAmac.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasWJAmac = (TCanvas*)infileWJAmac.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasWJAmac = (TCanvas*)infileWJAmac.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasWJAmac = (TCanvas*)infileWJAmac.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasWJAmac = (TCanvas*)infileWJAmac.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasWJAmac = (TCanvas*)infileWJAmac.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasWJAmac = (TCanvas*)infileWJAmac.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasWJAmac = (TCanvas*)infileWJAmac.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasWJAmac = (TCanvas*)infileWJAmac.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasWJAmac = (TCanvas*)infileWJAmac.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasWJAmac = (TCanvas*)infileWJAmac.Get("DiMuEta");
  TCanvas *DiMudRCanvasWJAmac = (TCanvas*)infileWJAmac.Get("DiMudR");
  TCanvas *DiMuPhiCanvasWJAmac = (TCanvas*)infileWJAmac.Get("DiMuPhi");
  TCanvas *EtMETCanvasWJAmac = (TCanvas*)infileWJAmac.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasWJAmac = (TCanvas*)infileWJAmac.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasWJAmac = (TCanvas*)infileWJAmac.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasWJAmac = (TCanvas*)infileWJAmac.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasWJAmac = (TCanvas*)infileWJAmac.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasWJAmac = (TCanvas*)infileWJAmac.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasWJAmac = (TCanvas*)infileWJAmac.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasWJAmac = (TCanvas*)infileWJAmac.Get("HighestCSVInclJet");

  ////////////////
//  // WJMad
//  ////////////////
//  TCanvas *NMedIsoTausWithMu3CanvasWJMad = (TCanvas*)infileWJMad.Get("NMedIsoTausWithMu3");
//  TCanvas *InvMassTauHadMu3CanvasWJMad = (TCanvas*)infileWJMad.Get("InvMassTauHadMu3");
//  TCanvas *PtTauHadMu3CanvasWJMad = (TCanvas*)infileWJMad.Get("PtTauHadMu3");
//  TCanvas *InvMassUpsilonRangeCanvasWJMad = (TCanvas*)infileWJMad.Get("InvMassUpsilonRange");
//  TCanvas *InvMassZPeakRangeCanvasWJMad = (TCanvas*)infileWJMad.Get("InvMassZPeakRange");
//  TCanvas *InvMassFullRangeCanvasWJMad = (TCanvas*)infileWJMad.Get("InvMassFullRange");
//  TCanvas *InvMassDiMuBarrBarrCanvasWJMad = (TCanvas*)infileWJMad.Get("InvMassDiMuBarrBarr");
//  TCanvas *InvMassDiMuBarrEndcCanvasWJMad = (TCanvas*)infileWJMad.Get("InvMassDiMuBarrEndc");
//  TCanvas *InvMassDiMuEndcEndcCanvasWJMad = (TCanvas*)infileWJMad.Get("InvMassDiMuEndcEndc");
//  TCanvas *Mu1PtCanvasWJMad = (TCanvas*)infileWJMad.Get("Mu1Pt");
//  TCanvas *Mu2PtCanvasWJMad = (TCanvas*)infileWJMad.Get("Mu2Pt");
//  TCanvas *DiMuPtCanvasWJMad = (TCanvas*)infileWJMad.Get("DiMuPt");
//  TCanvas *Mu1EtaCanvasWJMad = (TCanvas*)infileWJMad.Get("Mu1Eta");
//  TCanvas *Mu2EtaCanvasWJMad = (TCanvas*)infileWJMad.Get("Mu2Eta");
//  TCanvas *DiTauEtaCanvasWJMad = (TCanvas*)infileWJMad.Get("DiTauEta");
//  TCanvas *DiTauPhiCanvasWJMad = (TCanvas*)infileWJMad.Get("DiTauPhi");
//  TCanvas *DiMuEtaCanvasWJMad = (TCanvas*)infileWJMad.Get("DiMuEta");
//  TCanvas *DiMudRCanvasWJMad = (TCanvas*)infileWJMad.Get("DiMudR");
//  TCanvas *DiMuPhiCanvasWJMad = (TCanvas*)infileWJMad.Get("DiMuPhi");
//  TCanvas *EtMETCanvasWJMad = (TCanvas*)infileWJMad.Get("EtMET");
//  TCanvas *DiTauDiMuMassCanvasWJMad = (TCanvas*)infileWJMad.Get("DiTauDiMuMass");
//  TCanvas *DiMuDiTauDeltaPhiCanvasWJMad = (TCanvas*)infileWJMad.Get("DiMuDiTauDeltaPhi");
//  TCanvas *METDiTauDeltaPhiCanvasWJMad = (TCanvas*)infileWJMad.Get("METDiMuDeltaPhi");
//  TCanvas *METDiMuDeltaPhiCanvasWJMad = (TCanvas*)infileWJMad.Get("METDiMuDeltaPhi");
//  TCanvas *DiTaudRCanvasWJMad = (TCanvas*)infileWJMad.Get("DiTaudR");
//  TCanvas *DiTauMassSmallerdRCanvasWJMad = (TCanvas*)infileWJMad.Get("DiTauMassSmallerdR");
//  TCanvas *HighestCSVInclJetCanvasWJMad = (TCanvas*)infileWJMad.Get("HighestCSVInclJet");
//
  ////////////////
  // WZ
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasWZ = (TCanvas*)infileWZ.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasWZ = (TCanvas*)infileWZ.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasWZ = (TCanvas*)infileWZ.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasWZ = (TCanvas*)infileWZ.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasWZ = (TCanvas*)infileWZ.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasWZ = (TCanvas*)infileWZ.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasWZ = (TCanvas*)infileWZ.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasWZ = (TCanvas*)infileWZ.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasWZ = (TCanvas*)infileWZ.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasWZ = (TCanvas*)infileWZ.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasWZ = (TCanvas*)infileWZ.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasWZ = (TCanvas*)infileWZ.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasWZ = (TCanvas*)infileWZ.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasWZ = (TCanvas*)infileWZ.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasWZ = (TCanvas*)infileWZ.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasWZ = (TCanvas*)infileWZ.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasWZ = (TCanvas*)infileWZ.Get("DiMuEta");
  TCanvas *DiMudRCanvasWZ = (TCanvas*)infileWZ.Get("DiMudR");
  TCanvas *DiMuPhiCanvasWZ = (TCanvas*)infileWZ.Get("DiMuPhi");
  TCanvas *EtMETCanvasWZ = (TCanvas*)infileWZ.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasWZ = (TCanvas*)infileWZ.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasWZ = (TCanvas*)infileWZ.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasWZ = (TCanvas*)infileWZ.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasWZ = (TCanvas*)infileWZ.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasWZ = (TCanvas*)infileWZ.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasWZ = (TCanvas*)infileWZ.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasWZ = (TCanvas*)infileWZ.Get("HighestCSVInclJet");

  ////////////////
  // ZZ2L2Nu
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("DiMuEta");
  TCanvas *DiMudRCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("DiMudR");
  TCanvas *DiMuPhiCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("DiMuPhi");
  TCanvas *EtMETCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasZZ2L2Nu = (TCanvas*)infileZZ2L2Nu.Get("HighestCSVInclJet");

  ////////////////
  // ZZ2L2Q
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("DiMuEta");
  TCanvas *DiMudRCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("DiMudR");
  TCanvas *DiMuPhiCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("DiMuPhi");
  TCanvas *EtMETCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasZZ2L2Q = (TCanvas*)infileZZ2L2Q.Get("HighestCSVInclJet");

  ////////////////
  // ZZ4LAmac
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3CanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3CanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("PtTauHadMu3");
  TCanvas *InvMassUpsilonRangeCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("InvMassUpsilonRange");
  TCanvas *InvMassZPeakRangeCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("InvMassZPeakRange");
  TCanvas *InvMassFullRangeCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("Mu1Pt");
  TCanvas *Mu2PtCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("Mu2Pt");
  TCanvas *DiMuPtCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("DiMuPt");
  TCanvas *Mu1EtaCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("Mu1Eta");
  TCanvas *Mu2EtaCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("Mu2Eta");
  TCanvas *DiTauEtaCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("DiTauEta");
  TCanvas *DiTauPhiCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("DiMuEta");
  TCanvas *DiMudRCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("DiMudR");
  TCanvas *DiMuPhiCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("DiMuPhi");
  TCanvas *EtMETCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("METDiMuDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvasZZ4LAmac = (TCanvas*)infileZZ4LAmac.Get("HighestCSVInclJet");

//  ////////////////
//  // ZZ4LPowh
//  ////////////////
//  TCanvas *NMedIsoTausWithMu3CanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("NMedIsoTausWithMu3");
//  TCanvas *InvMassTauHadMu3CanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("InvMassTauHadMu3");
//  TCanvas *PtTauHadMu3CanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("PtTauHadMu3");
//  TCanvas *InvMassUpsilonRangeCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("InvMassUpsilonRange");
//  TCanvas *InvMassZPeakRangeCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("InvMassZPeakRange");
//  TCanvas *InvMassFullRangeCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("InvMassFullRange");
//  TCanvas *InvMassDiMuBarrBarrCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("InvMassDiMuBarrBarr");
//  TCanvas *InvMassDiMuBarrEndcCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("InvMassDiMuBarrEndc");
//  TCanvas *InvMassDiMuEndcEndcCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("InvMassDiMuEndcEndc");
//  TCanvas *Mu1PtCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("Mu1Pt");
//  TCanvas *Mu2PtCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("Mu2Pt");
//  TCanvas *DiMuPtCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("DiMuPt");
//  TCanvas *Mu1EtaCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("Mu1Eta");
//  TCanvas *Mu2EtaCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("Mu2Eta");
//  TCanvas *DiTauEtaCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("DiTauEta");
//  TCanvas *DiTauPhiCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("DiTauPhi");
//  TCanvas *DiMuEtaCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("DiMuEta");
//  TCanvas *DiMudRCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("DiMudR");
//  TCanvas *DiMuPhiCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("DiMuPhi");
//  TCanvas *EtMETCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("EtMET");
//  TCanvas *DiTauDiMuMassCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("DiTauDiMuMass");
//  TCanvas *DiMuDiTauDeltaPhiCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("DiMuDiTauDeltaPhi");
//  TCanvas *METDiTauDeltaPhiCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("METDiMuDeltaPhi");
//  TCanvas *METDiMuDeltaPhiCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("METDiMuDeltaPhi");
//  TCanvas *DiTaudRCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("DiTaudR");
//  TCanvas *DiTauMassSmallerdRCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("DiTauMassSmallerdR");
//  TCanvas *HighestCSVInclJetCanvasZZ4LPowh = (TCanvas*)infileZZ4LPowh.Get("HighestCSVInclJet");
//
//
//  ////////////////
//  // JPsi
//  ////////////////
//  TCanvas *NMedIsoTausWithMu3CanvasJPsi = (TCanvas*)infileJPsi.Get("NMedIsoTausWithMu3");
//  TCanvas *InvMassTauHadMu3CanvasJPsi = (TCanvas*)infileJPsi.Get("InvMassTauHadMu3");
//  TCanvas *PtTauHadMu3CanvasJPsi = (TCanvas*)infileJPsi.Get("PtTauHadMu3");
//  TCanvas *InvMassUpsilonRangeCanvasJPsi = (TCanvas*)infileJPsi.Get("InvMassUpsilonRange");
//  TCanvas *InvMassZPeakRangeCanvasJPsi = (TCanvas*)infileJPsi.Get("InvMassZPeakRange");
//  TCanvas *InvMassFullRangeCanvasJPsi = (TCanvas*)infileJPsi.Get("InvMassFullRange");
//  TCanvas *InvMassDiMuBarrBarrCanvasJPsi = (TCanvas*)infileJPsi.Get("InvMassDiMuBarrBarr");
//  TCanvas *InvMassDiMuBarrEndcCanvasJPsi = (TCanvas*)infileJPsi.Get("InvMassDiMuBarrEndc");
//  TCanvas *InvMassDiMuEndcEndcCanvasJPsi = (TCanvas*)infileJPsi.Get("InvMassDiMuEndcEndc");
//  TCanvas *Mu1PtCanvasJPsi = (TCanvas*)infileJPsi.Get("Mu1Pt");
//  TCanvas *Mu2PtCanvasJPsi = (TCanvas*)infileJPsi.Get("Mu2Pt");
//  TCanvas *DiMuPtCanvasJPsi = (TCanvas*)infileJPsi.Get("DiMuPt");
//  TCanvas *Mu1EtaCanvasJPsi = (TCanvas*)infileJPsi.Get("Mu1Eta");
//  TCanvas *Mu2EtaCanvasJPsi = (TCanvas*)infileJPsi.Get("Mu2Eta");
//  TCanvas *DiTauEtaCanvasJPsi = (TCanvas*)infileJPsi.Get("DiTauEta");
//  TCanvas *DiTauPhiCanvasJPsi = (TCanvas*)infileJPsi.Get("DiTauPhi");
//  TCanvas *DiMuEtaCanvasJPsi = (TCanvas*)infileJPsi.Get("DiMuEta");
//  TCanvas *DiMudRCanvasJPsi = (TCanvas*)infileJPsi.Get("DiMudR");
//  TCanvas *DiMuPhiCanvasJPsi = (TCanvas*)infileJPsi.Get("DiMuPhi");
//  TCanvas *EtMETCanvasJPsi = (TCanvas*)infileJPsi.Get("EtMET");
//  TCanvas *DiTauDiMuMassJPsi = (TCanvas*)infileJPsi.Get("DiTauDiMuMass");
//  TCanvas *DiMuDiTauDeltaPhiCanvasJPsi = (TCanvas*)infileJPsi.Get("DiMuDiTauDeltaPhi");
//  TCanvas *METDiTauDeltaPhiCanvasJPsi = (TCanvas*)infileJPsi.Get("METDiMuDeltaPhi");
//  TCanvas *METDiMuDeltaPhiCanvasJPsi = (TCanvas*)infileJPsi.Get("METDiMuDeltaPhi");
//  TCanvas *DiTaudRJPsi = (TCanvas*)infileJPsi.Get("DiTaudR");
//  TCanvas *DiTauMassSmallerdRJPsi = (TCanvas*)infileJPsi.Get("DiTauMassSmallerdR");
//  TCanvas *HighestCSVInclJetJPsi = (TCanvas*)infileJPsi.Get("HighestCSVInclJet");

cout << "Got Canvases" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Histograms fromm the Canvases
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ////////////////
  // TT
  ////////////////
  TH1F *NMedIsoTausWithMu3TT_ = (TH1F*)NMedIsoTausWithMu3CanvasTT->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3TT_ = (TH1F*)InvMassTauHadMu3CanvasTT->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3TT_ = (TH1F*)PtTauHadMu3CanvasTT->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeTT_ = (TH1F*)InvMassUpsilonRangeCanvasTT->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeTT_ = (TH1F*)InvMassZPeakRangeCanvasTT->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeTT_ = (TH1F*)InvMassFullRangeCanvasTT->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrTT_ = (TH1F*)InvMassDiMuBarrBarrCanvasTT->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcTT_ = (TH1F*)InvMassDiMuBarrEndcCanvasTT->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcTT_ = (TH1F*)InvMassDiMuEndcEndcCanvasTT->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtTT_ = (TH1F*)Mu1PtCanvasTT->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtTT_ = (TH1F*)Mu2PtCanvasTT->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtTT_ = (TH1F*)DiMuPtCanvasTT->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaTT_ = (TH1F*)Mu1EtaCanvasTT->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaTT_ = (TH1F*)Mu2EtaCanvasTT->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaTT_ = (TH1F*)DiTauEtaCanvasTT->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiTT_ = (TH1F*)DiTauPhiCanvasTT->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaTT_ = (TH1F*)DiMuEtaCanvasTT->GetPrimitive("DiMuEta");
  TH1F *DiMudRTT_ = (TH1F*)DiMudRCanvasTT->GetPrimitive("DiMudR");
  TH1F *DiMuPhiTT_ = (TH1F*)DiMuPhiCanvasTT->GetPrimitive("DiMuPhi");
  TH1F *EtMETTT_ = (TH1F*)EtMETCanvasTT->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassTT_ = (TH1F*)DiTauDiMuMassCanvasTT->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiTT_ = (TH1F*)DiMuDiTauDeltaPhiCanvasTT->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiTT_ = (TH1F*)METDiMuDeltaPhiCanvasTT->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiTT_ = (TH1F*)METDiMuDeltaPhiCanvasTT->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRTT_ = (TH1F*)DiTaudRCanvasTT->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRTT_ = (TH1F*)DiTauMassSmallerdRCanvasTT->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetTT_ = (TH1F*)HighestCSVInclJetCanvasTT->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // DYL
  ////////////////
  TH1F *NMedIsoTausWithMu3DYL_ = (TH1F*)NMedIsoTausWithMu3CanvasDYL->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3DYL_ = (TH1F*)InvMassTauHadMu3CanvasDYL->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3DYL_ = (TH1F*)PtTauHadMu3CanvasDYL->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeDYL_ = (TH1F*)InvMassUpsilonRangeCanvasDYL->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeDYL_ = (TH1F*)InvMassZPeakRangeCanvasDYL->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeDYL_ = (TH1F*)InvMassFullRangeCanvasDYL->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrDYL_ = (TH1F*)InvMassDiMuBarrBarrCanvasDYL->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcDYL_ = (TH1F*)InvMassDiMuBarrEndcCanvasDYL->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcDYL_ = (TH1F*)InvMassDiMuEndcEndcCanvasDYL->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtDYL_ = (TH1F*)Mu1PtCanvasDYL->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtDYL_ = (TH1F*)Mu2PtCanvasDYL->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtDYL_ = (TH1F*)DiMuPtCanvasDYL->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaDYL_ = (TH1F*)Mu1EtaCanvasDYL->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaDYL_ = (TH1F*)Mu2EtaCanvasDYL->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaDYL_ = (TH1F*)DiTauEtaCanvasDYL->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiDYL_ = (TH1F*)DiTauPhiCanvasDYL->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaDYL_ = (TH1F*)DiMuEtaCanvasDYL->GetPrimitive("DiMuEta");
  TH1F *DiMudRDYL_ = (TH1F*)DiMudRCanvasDYL->GetPrimitive("DiMudR");
  TH1F *DiMuPhiDYL_ = (TH1F*)DiMuPhiCanvasDYL->GetPrimitive("DiMuPhi");
  TH1F *EtMETDYL_ = (TH1F*)EtMETCanvasDYL->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassDYL_ = (TH1F*)DiTauDiMuMassCanvasDYL->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiDYL_ = (TH1F*)DiMuDiTauDeltaPhiCanvasDYL->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiDYL_ = (TH1F*)METDiMuDeltaPhiCanvasDYL->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiDYL_ = (TH1F*)METDiMuDeltaPhiCanvasDYL->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRDYL_ = (TH1F*)DiTaudRCanvasDYL->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRDYL_ = (TH1F*)DiTauMassSmallerdRCanvasDYL->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetDYL_ = (TH1F*)HighestCSVInclJetCanvasDYL->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // DYH
  ////////////////
  TH1F *NMedIsoTausWithMu3DYH_ = (TH1F*)NMedIsoTausWithMu3CanvasDYH->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3DYH_ = (TH1F*)InvMassTauHadMu3CanvasDYH->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3DYH_ = (TH1F*)PtTauHadMu3CanvasDYH->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeDYH_ = (TH1F*)InvMassUpsilonRangeCanvasDYH->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeDYH_ = (TH1F*)InvMassZPeakRangeCanvasDYH->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeDYH_ = (TH1F*)InvMassFullRangeCanvasDYH->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrDYH_ = (TH1F*)InvMassDiMuBarrBarrCanvasDYH->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcDYH_ = (TH1F*)InvMassDiMuBarrEndcCanvasDYH->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcDYH_ = (TH1F*)InvMassDiMuEndcEndcCanvasDYH->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtDYH_ = (TH1F*)Mu1PtCanvasDYH->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtDYH_ = (TH1F*)Mu2PtCanvasDYH->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtDYH_ = (TH1F*)DiMuPtCanvasDYH->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaDYH_ = (TH1F*)Mu1EtaCanvasDYH->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaDYH_ = (TH1F*)Mu2EtaCanvasDYH->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaDYH_ = (TH1F*)DiTauEtaCanvasDYH->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiDYH_ = (TH1F*)DiTauPhiCanvasDYH->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaDYH_ = (TH1F*)DiMuEtaCanvasDYH->GetPrimitive("DiMuEta");
  TH1F *DiMudRDYH_ = (TH1F*)DiMudRCanvasDYH->GetPrimitive("DiMudR");
  TH1F *DiMuPhiDYH_ = (TH1F*)DiMuPhiCanvasDYH->GetPrimitive("DiMuPhi");
  TH1F *EtMETDYH_ = (TH1F*)EtMETCanvasDYH->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassDYH_ = (TH1F*)DiTauDiMuMassCanvasDYH->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiDYH_ = (TH1F*)DiMuDiTauDeltaPhiCanvasDYH->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiDYH_ = (TH1F*)METDiMuDeltaPhiCanvasDYH->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiDYH_ = (TH1F*)METDiMuDeltaPhiCanvasDYH->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRDYH_ = (TH1F*)DiTaudRCanvasDYH->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRDYH_ = (TH1F*)DiTauMassSmallerdRCanvasDYH->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetDYH_ = (TH1F*)HighestCSVInclJetCanvasDYH->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // QCD_1000toInf
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_1000toInf_ = (TH1F*)NMedIsoTausWithMu3CanvasQCD_1000toInf->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_1000toInf_ = (TH1F*)InvMassTauHadMu3CanvasQCD_1000toInf->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_1000toInf_ = (TH1F*)PtTauHadMu3CanvasQCD_1000toInf->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeQCD_1000toInf_ = (TH1F*)InvMassUpsilonRangeCanvasQCD_1000toInf->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeQCD_1000toInf_ = (TH1F*)InvMassZPeakRangeCanvasQCD_1000toInf->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeQCD_1000toInf_ = (TH1F*)InvMassFullRangeCanvasQCD_1000toInf->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrQCD_1000toInf_ = (TH1F*)InvMassDiMuBarrBarrCanvasQCD_1000toInf->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_1000toInf_ = (TH1F*)InvMassDiMuBarrEndcCanvasQCD_1000toInf->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_1000toInf_ = (TH1F*)InvMassDiMuEndcEndcCanvasQCD_1000toInf->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_1000toInf_ = (TH1F*)Mu1PtCanvasQCD_1000toInf->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtQCD_1000toInf_ = (TH1F*)Mu2PtCanvasQCD_1000toInf->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtQCD_1000toInf_ = (TH1F*)DiMuPtCanvasQCD_1000toInf->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaQCD_1000toInf_ = (TH1F*)Mu1EtaCanvasQCD_1000toInf->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaQCD_1000toInf_ = (TH1F*)Mu2EtaCanvasQCD_1000toInf->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaQCD_1000toInf_ = (TH1F*)DiTauEtaCanvasQCD_1000toInf->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiQCD_1000toInf_ = (TH1F*)DiTauPhiCanvasQCD_1000toInf->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaQCD_1000toInf_ = (TH1F*)DiMuEtaCanvasQCD_1000toInf->GetPrimitive("DiMuEta");
  TH1F *DiMudRQCD_1000toInf_ = (TH1F*)DiMudRCanvasQCD_1000toInf->GetPrimitive("DiMudR");
  TH1F *DiMuPhiQCD_1000toInf_ = (TH1F*)DiMuPhiCanvasQCD_1000toInf->GetPrimitive("DiMuPhi");
  TH1F *EtMETQCD_1000toInf_ = (TH1F*)EtMETCanvasQCD_1000toInf->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassQCD_1000toInf_ = (TH1F*)DiTauDiMuMassCanvasQCD_1000toInf->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_1000toInf_ = (TH1F*)DiMuDiTauDeltaPhiCanvasQCD_1000toInf->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_1000toInf_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_1000toInf->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_1000toInf_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_1000toInf->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_1000toInf_ = (TH1F*)DiTaudRCanvasQCD_1000toInf->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_1000toInf_ = (TH1F*)DiTauMassSmallerdRCanvasQCD_1000toInf->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetQCD_1000toInf_ = (TH1F*)HighestCSVInclJetCanvasQCD_1000toInf->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // QCD_120to170
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_120to170_ = (TH1F*)NMedIsoTausWithMu3CanvasQCD_120to170->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_120to170_ = (TH1F*)InvMassTauHadMu3CanvasQCD_120to170->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_120to170_ = (TH1F*)PtTauHadMu3CanvasQCD_120to170->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeQCD_120to170_ = (TH1F*)InvMassUpsilonRangeCanvasQCD_120to170->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeQCD_120to170_ = (TH1F*)InvMassZPeakRangeCanvasQCD_120to170->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeQCD_120to170_ = (TH1F*)InvMassFullRangeCanvasQCD_120to170->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrQCD_120to170_ = (TH1F*)InvMassDiMuBarrBarrCanvasQCD_120to170->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_120to170_ = (TH1F*)InvMassDiMuBarrEndcCanvasQCD_120to170->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_120to170_ = (TH1F*)InvMassDiMuEndcEndcCanvasQCD_120to170->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_120to170_ = (TH1F*)Mu1PtCanvasQCD_120to170->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtQCD_120to170_ = (TH1F*)Mu2PtCanvasQCD_120to170->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtQCD_120to170_ = (TH1F*)DiMuPtCanvasQCD_120to170->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaQCD_120to170_ = (TH1F*)Mu1EtaCanvasQCD_120to170->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaQCD_120to170_ = (TH1F*)Mu2EtaCanvasQCD_120to170->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaQCD_120to170_ = (TH1F*)DiTauEtaCanvasQCD_120to170->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiQCD_120to170_ = (TH1F*)DiTauPhiCanvasQCD_120to170->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaQCD_120to170_ = (TH1F*)DiMuEtaCanvasQCD_120to170->GetPrimitive("DiMuEta");
  TH1F *DiMudRQCD_120to170_ = (TH1F*)DiMudRCanvasQCD_120to170->GetPrimitive("DiMudR");
  TH1F *DiMuPhiQCD_120to170_ = (TH1F*)DiMuPhiCanvasQCD_120to170->GetPrimitive("DiMuPhi");
  TH1F *EtMETQCD_120to170_ = (TH1F*)EtMETCanvasQCD_120to170->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassQCD_120to170_ = (TH1F*)DiTauDiMuMassCanvasQCD_120to170->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_120to170_ = (TH1F*)DiMuDiTauDeltaPhiCanvasQCD_120to170->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_120to170_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_120to170->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_120to170_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_120to170->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_120to170_ = (TH1F*)DiTaudRCanvasQCD_120to170->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_120to170_ = (TH1F*)DiTauMassSmallerdRCanvasQCD_120to170->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetQCD_120to170_ = (TH1F*)HighestCSVInclJetCanvasQCD_120to170->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // QCD_15to20
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_15to20_ = (TH1F*)NMedIsoTausWithMu3CanvasQCD_15to20->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_15to20_ = (TH1F*)InvMassTauHadMu3CanvasQCD_15to20->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_15to20_ = (TH1F*)PtTauHadMu3CanvasQCD_15to20->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeQCD_15to20_ = (TH1F*)InvMassUpsilonRangeCanvasQCD_15to20->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeQCD_15to20_ = (TH1F*)InvMassZPeakRangeCanvasQCD_15to20->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeQCD_15to20_ = (TH1F*)InvMassFullRangeCanvasQCD_15to20->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrQCD_15to20_ = (TH1F*)InvMassDiMuBarrBarrCanvasQCD_15to20->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_15to20_ = (TH1F*)InvMassDiMuBarrEndcCanvasQCD_15to20->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_15to20_ = (TH1F*)InvMassDiMuEndcEndcCanvasQCD_15to20->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_15to20_ = (TH1F*)Mu1PtCanvasQCD_15to20->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtQCD_15to20_ = (TH1F*)Mu2PtCanvasQCD_15to20->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtQCD_15to20_ = (TH1F*)DiMuPtCanvasQCD_15to20->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaQCD_15to20_ = (TH1F*)Mu1EtaCanvasQCD_15to20->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaQCD_15to20_ = (TH1F*)Mu2EtaCanvasQCD_15to20->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaQCD_15to20_ = (TH1F*)DiTauEtaCanvasQCD_15to20->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiQCD_15to20_ = (TH1F*)DiTauPhiCanvasQCD_15to20->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaQCD_15to20_ = (TH1F*)DiMuEtaCanvasQCD_15to20->GetPrimitive("DiMuEta");
  TH1F *DiMudRQCD_15to20_ = (TH1F*)DiMudRCanvasQCD_15to20->GetPrimitive("DiMudR");
  TH1F *DiMuPhiQCD_15to20_ = (TH1F*)DiMuPhiCanvasQCD_15to20->GetPrimitive("DiMuPhi");
  TH1F *EtMETQCD_15to20_ = (TH1F*)EtMETCanvasQCD_15to20->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassQCD_15to20_ = (TH1F*)DiTauDiMuMassCanvasQCD_15to20->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_15to20_ = (TH1F*)DiMuDiTauDeltaPhiCanvasQCD_15to20->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_15to20_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_15to20->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_15to20_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_15to20->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_15to20_ = (TH1F*)DiTaudRCanvasQCD_15to20->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_15to20_ = (TH1F*)DiTauMassSmallerdRCanvasQCD_15to20->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetQCD_15to20_ = (TH1F*)HighestCSVInclJetCanvasQCD_15to20->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // QCD_170to300
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_170to300_ = (TH1F*)NMedIsoTausWithMu3CanvasQCD_170to300->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_170to300_ = (TH1F*)InvMassTauHadMu3CanvasQCD_170to300->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_170to300_ = (TH1F*)PtTauHadMu3CanvasQCD_170to300->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeQCD_170to300_ = (TH1F*)InvMassUpsilonRangeCanvasQCD_170to300->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeQCD_170to300_ = (TH1F*)InvMassZPeakRangeCanvasQCD_170to300->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeQCD_170to300_ = (TH1F*)InvMassFullRangeCanvasQCD_170to300->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrQCD_170to300_ = (TH1F*)InvMassDiMuBarrBarrCanvasQCD_170to300->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_170to300_ = (TH1F*)InvMassDiMuBarrEndcCanvasQCD_170to300->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_170to300_ = (TH1F*)InvMassDiMuEndcEndcCanvasQCD_170to300->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_170to300_ = (TH1F*)Mu1PtCanvasQCD_170to300->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtQCD_170to300_ = (TH1F*)Mu2PtCanvasQCD_170to300->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtQCD_170to300_ = (TH1F*)DiMuPtCanvasQCD_170to300->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaQCD_170to300_ = (TH1F*)Mu1EtaCanvasQCD_170to300->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaQCD_170to300_ = (TH1F*)Mu2EtaCanvasQCD_170to300->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaQCD_170to300_ = (TH1F*)DiTauEtaCanvasQCD_170to300->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiQCD_170to300_ = (TH1F*)DiTauPhiCanvasQCD_170to300->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaQCD_170to300_ = (TH1F*)DiMuEtaCanvasQCD_170to300->GetPrimitive("DiMuEta");
  TH1F *DiMudRQCD_170to300_ = (TH1F*)DiMudRCanvasQCD_170to300->GetPrimitive("DiMudR");
  TH1F *DiMuPhiQCD_170to300_ = (TH1F*)DiMuPhiCanvasQCD_170to300->GetPrimitive("DiMuPhi");
  TH1F *EtMETQCD_170to300_ = (TH1F*)EtMETCanvasQCD_170to300->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassQCD_170to300_ = (TH1F*)DiTauDiMuMassCanvasQCD_170to300->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_170to300_ = (TH1F*)DiMuDiTauDeltaPhiCanvasQCD_170to300->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_170to300_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_170to300->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_170to300_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_170to300->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_170to300_ = (TH1F*)DiTaudRCanvasQCD_170to300->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_170to300_ = (TH1F*)DiTauMassSmallerdRCanvasQCD_170to300->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetQCD_170to300_ = (TH1F*)HighestCSVInclJetCanvasQCD_170to300->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // QCD_20to30
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_20to30_ = (TH1F*)NMedIsoTausWithMu3CanvasQCD_20to30->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_20to30_ = (TH1F*)InvMassTauHadMu3CanvasQCD_20to30->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_20to30_ = (TH1F*)PtTauHadMu3CanvasQCD_20to30->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeQCD_20to30_ = (TH1F*)InvMassUpsilonRangeCanvasQCD_20to30->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeQCD_20to30_ = (TH1F*)InvMassZPeakRangeCanvasQCD_20to30->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeQCD_20to30_ = (TH1F*)InvMassFullRangeCanvasQCD_20to30->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrQCD_20to30_ = (TH1F*)InvMassDiMuBarrBarrCanvasQCD_20to30->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_20to30_ = (TH1F*)InvMassDiMuBarrEndcCanvasQCD_20to30->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_20to30_ = (TH1F*)InvMassDiMuEndcEndcCanvasQCD_20to30->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_20to30_ = (TH1F*)Mu1PtCanvasQCD_20to30->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtQCD_20to30_ = (TH1F*)Mu2PtCanvasQCD_20to30->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtQCD_20to30_ = (TH1F*)DiMuPtCanvasQCD_20to30->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaQCD_20to30_ = (TH1F*)Mu1EtaCanvasQCD_20to30->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaQCD_20to30_ = (TH1F*)Mu2EtaCanvasQCD_20to30->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaQCD_20to30_ = (TH1F*)DiTauEtaCanvasQCD_20to30->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiQCD_20to30_ = (TH1F*)DiTauPhiCanvasQCD_20to30->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaQCD_20to30_ = (TH1F*)DiMuEtaCanvasQCD_20to30->GetPrimitive("DiMuEta");
  TH1F *DiMudRQCD_20to30_ = (TH1F*)DiMudRCanvasQCD_20to30->GetPrimitive("DiMudR");
  TH1F *DiMuPhiQCD_20to30_ = (TH1F*)DiMuPhiCanvasQCD_20to30->GetPrimitive("DiMuPhi");
  TH1F *EtMETQCD_20to30_ = (TH1F*)EtMETCanvasQCD_20to30->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassQCD_20to30_ = (TH1F*)DiTauDiMuMassCanvasQCD_20to30->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_20to30_ = (TH1F*)DiMuDiTauDeltaPhiCanvasQCD_20to30->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_20to30_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_20to30->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_20to30_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_20to30->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_20to30_ = (TH1F*)DiTaudRCanvasQCD_20to30->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_20to30_ = (TH1F*)DiTauMassSmallerdRCanvasQCD_20to30->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetQCD_20to30_ = (TH1F*)HighestCSVInclJetCanvasQCD_20to30->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // QCD_300to470
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_300to470_ = (TH1F*)NMedIsoTausWithMu3CanvasQCD_300to470->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_300to470_ = (TH1F*)InvMassTauHadMu3CanvasQCD_300to470->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_300to470_ = (TH1F*)PtTauHadMu3CanvasQCD_300to470->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeQCD_300to470_ = (TH1F*)InvMassUpsilonRangeCanvasQCD_300to470->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeQCD_300to470_ = (TH1F*)InvMassZPeakRangeCanvasQCD_300to470->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeQCD_300to470_ = (TH1F*)InvMassFullRangeCanvasQCD_300to470->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrQCD_300to470_ = (TH1F*)InvMassDiMuBarrBarrCanvasQCD_300to470->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_300to470_ = (TH1F*)InvMassDiMuBarrEndcCanvasQCD_300to470->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_300to470_ = (TH1F*)InvMassDiMuEndcEndcCanvasQCD_300to470->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_300to470_ = (TH1F*)Mu1PtCanvasQCD_300to470->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtQCD_300to470_ = (TH1F*)Mu2PtCanvasQCD_300to470->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtQCD_300to470_ = (TH1F*)DiMuPtCanvasQCD_300to470->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaQCD_300to470_ = (TH1F*)Mu1EtaCanvasQCD_300to470->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaQCD_300to470_ = (TH1F*)Mu2EtaCanvasQCD_300to470->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaQCD_300to470_ = (TH1F*)DiTauEtaCanvasQCD_300to470->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiQCD_300to470_ = (TH1F*)DiTauPhiCanvasQCD_300to470->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaQCD_300to470_ = (TH1F*)DiMuEtaCanvasQCD_300to470->GetPrimitive("DiMuEta");
  TH1F *DiMudRQCD_300to470_ = (TH1F*)DiMudRCanvasQCD_300to470->GetPrimitive("DiMudR");
  TH1F *DiMuPhiQCD_300to470_ = (TH1F*)DiMuPhiCanvasQCD_300to470->GetPrimitive("DiMuPhi");
  TH1F *EtMETQCD_300to470_ = (TH1F*)EtMETCanvasQCD_300to470->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassQCD_300to470_ = (TH1F*)DiTauDiMuMassCanvasQCD_300to470->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_300to470_ = (TH1F*)DiMuDiTauDeltaPhiCanvasQCD_300to470->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_300to470_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_300to470->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_300to470_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_300to470->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_300to470_ = (TH1F*)DiTaudRCanvasQCD_300to470->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_300to470_ = (TH1F*)DiTauMassSmallerdRCanvasQCD_300to470->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetQCD_300to470_ = (TH1F*)HighestCSVInclJetCanvasQCD_300to470->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // QCD_30to50
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_30to50_ = (TH1F*)NMedIsoTausWithMu3CanvasQCD_30to50->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_30to50_ = (TH1F*)InvMassTauHadMu3CanvasQCD_30to50->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_30to50_ = (TH1F*)PtTauHadMu3CanvasQCD_30to50->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeQCD_30to50_ = (TH1F*)InvMassUpsilonRangeCanvasQCD_30to50->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeQCD_30to50_ = (TH1F*)InvMassZPeakRangeCanvasQCD_30to50->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeQCD_30to50_ = (TH1F*)InvMassFullRangeCanvasQCD_30to50->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrQCD_30to50_ = (TH1F*)InvMassDiMuBarrBarrCanvasQCD_30to50->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_30to50_ = (TH1F*)InvMassDiMuBarrEndcCanvasQCD_30to50->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_30to50_ = (TH1F*)InvMassDiMuEndcEndcCanvasQCD_30to50->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_30to50_ = (TH1F*)Mu1PtCanvasQCD_30to50->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtQCD_30to50_ = (TH1F*)Mu2PtCanvasQCD_30to50->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtQCD_30to50_ = (TH1F*)DiMuPtCanvasQCD_30to50->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaQCD_30to50_ = (TH1F*)Mu1EtaCanvasQCD_30to50->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaQCD_30to50_ = (TH1F*)Mu2EtaCanvasQCD_30to50->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaQCD_30to50_ = (TH1F*)DiTauEtaCanvasQCD_30to50->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiQCD_30to50_ = (TH1F*)DiTauPhiCanvasQCD_30to50->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaQCD_30to50_ = (TH1F*)DiMuEtaCanvasQCD_30to50->GetPrimitive("DiMuEta");
  TH1F *DiMudRQCD_30to50_ = (TH1F*)DiMudRCanvasQCD_30to50->GetPrimitive("DiMudR");
  TH1F *DiMuPhiQCD_30to50_ = (TH1F*)DiMuPhiCanvasQCD_30to50->GetPrimitive("DiMuPhi");
  TH1F *EtMETQCD_30to50_ = (TH1F*)EtMETCanvasQCD_30to50->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassQCD_30to50_ = (TH1F*)DiTauDiMuMassCanvasQCD_30to50->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_30to50_ = (TH1F*)DiMuDiTauDeltaPhiCanvasQCD_30to50->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_30to50_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_30to50->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_30to50_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_30to50->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_30to50_ = (TH1F*)DiTaudRCanvasQCD_30to50->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_30to50_ = (TH1F*)DiTauMassSmallerdRCanvasQCD_30to50->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetQCD_30to50_ = (TH1F*)HighestCSVInclJetCanvasQCD_30to50->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // QCD_470to600
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_470to600_ = (TH1F*)NMedIsoTausWithMu3CanvasQCD_470to600->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_470to600_ = (TH1F*)InvMassTauHadMu3CanvasQCD_470to600->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_470to600_ = (TH1F*)PtTauHadMu3CanvasQCD_470to600->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeQCD_470to600_ = (TH1F*)InvMassUpsilonRangeCanvasQCD_470to600->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeQCD_470to600_ = (TH1F*)InvMassZPeakRangeCanvasQCD_470to600->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeQCD_470to600_ = (TH1F*)InvMassFullRangeCanvasQCD_470to600->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrQCD_470to600_ = (TH1F*)InvMassDiMuBarrBarrCanvasQCD_470to600->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_470to600_ = (TH1F*)InvMassDiMuBarrEndcCanvasQCD_470to600->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_470to600_ = (TH1F*)InvMassDiMuEndcEndcCanvasQCD_470to600->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_470to600_ = (TH1F*)Mu1PtCanvasQCD_470to600->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtQCD_470to600_ = (TH1F*)Mu2PtCanvasQCD_470to600->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtQCD_470to600_ = (TH1F*)DiMuPtCanvasQCD_470to600->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaQCD_470to600_ = (TH1F*)Mu1EtaCanvasQCD_470to600->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaQCD_470to600_ = (TH1F*)Mu2EtaCanvasQCD_470to600->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaQCD_470to600_ = (TH1F*)DiTauEtaCanvasQCD_470to600->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiQCD_470to600_ = (TH1F*)DiTauPhiCanvasQCD_470to600->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaQCD_470to600_ = (TH1F*)DiMuEtaCanvasQCD_470to600->GetPrimitive("DiMuEta");
  TH1F *DiMudRQCD_470to600_ = (TH1F*)DiMudRCanvasQCD_470to600->GetPrimitive("DiMudR");
  TH1F *DiMuPhiQCD_470to600_ = (TH1F*)DiMuPhiCanvasQCD_470to600->GetPrimitive("DiMuPhi");
  TH1F *EtMETQCD_470to600_ = (TH1F*)EtMETCanvasQCD_470to600->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassQCD_470to600_ = (TH1F*)DiTauDiMuMassCanvasQCD_470to600->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_470to600_ = (TH1F*)DiMuDiTauDeltaPhiCanvasQCD_470to600->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_470to600_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_470to600->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_470to600_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_470to600->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_470to600_ = (TH1F*)DiTaudRCanvasQCD_470to600->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_470to600_ = (TH1F*)DiTauMassSmallerdRCanvasQCD_470to600->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetQCD_470to600_ = (TH1F*)HighestCSVInclJetCanvasQCD_470to600->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // QCD_50to80
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_50to80_ = (TH1F*)NMedIsoTausWithMu3CanvasQCD_50to80->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_50to80_ = (TH1F*)InvMassTauHadMu3CanvasQCD_50to80->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_50to80_ = (TH1F*)PtTauHadMu3CanvasQCD_50to80->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeQCD_50to80_ = (TH1F*)InvMassUpsilonRangeCanvasQCD_50to80->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeQCD_50to80_ = (TH1F*)InvMassZPeakRangeCanvasQCD_50to80->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeQCD_50to80_ = (TH1F*)InvMassFullRangeCanvasQCD_50to80->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrQCD_50to80_ = (TH1F*)InvMassDiMuBarrBarrCanvasQCD_50to80->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_50to80_ = (TH1F*)InvMassDiMuBarrEndcCanvasQCD_50to80->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_50to80_ = (TH1F*)InvMassDiMuEndcEndcCanvasQCD_50to80->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_50to80_ = (TH1F*)Mu1PtCanvasQCD_50to80->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtQCD_50to80_ = (TH1F*)Mu2PtCanvasQCD_50to80->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtQCD_50to80_ = (TH1F*)DiMuPtCanvasQCD_50to80->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaQCD_50to80_ = (TH1F*)Mu1EtaCanvasQCD_50to80->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaQCD_50to80_ = (TH1F*)Mu2EtaCanvasQCD_50to80->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaQCD_50to80_ = (TH1F*)DiTauEtaCanvasQCD_50to80->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiQCD_50to80_ = (TH1F*)DiTauPhiCanvasQCD_50to80->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaQCD_50to80_ = (TH1F*)DiMuEtaCanvasQCD_50to80->GetPrimitive("DiMuEta");
  TH1F *DiMudRQCD_50to80_ = (TH1F*)DiMudRCanvasQCD_50to80->GetPrimitive("DiMudR");
  TH1F *DiMuPhiQCD_50to80_ = (TH1F*)DiMuPhiCanvasQCD_50to80->GetPrimitive("DiMuPhi");
  TH1F *EtMETQCD_50to80_ = (TH1F*)EtMETCanvasQCD_50to80->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassQCD_50to80_ = (TH1F*)DiTauDiMuMassCanvasQCD_50to80->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_50to80_ = (TH1F*)DiMuDiTauDeltaPhiCanvasQCD_50to80->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_50to80_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_50to80->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_50to80_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_50to80->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_50to80_ = (TH1F*)DiTaudRCanvasQCD_50to80->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_50to80_ = (TH1F*)DiTauMassSmallerdRCanvasQCD_50to80->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetQCD_50to80_ = (TH1F*)HighestCSVInclJetCanvasQCD_50to80->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // QCD_600to800
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_600to800_ = (TH1F*)NMedIsoTausWithMu3CanvasQCD_600to800->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_600to800_ = (TH1F*)InvMassTauHadMu3CanvasQCD_600to800->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_600to800_ = (TH1F*)PtTauHadMu3CanvasQCD_600to800->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeQCD_600to800_ = (TH1F*)InvMassUpsilonRangeCanvasQCD_600to800->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeQCD_600to800_ = (TH1F*)InvMassZPeakRangeCanvasQCD_600to800->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeQCD_600to800_ = (TH1F*)InvMassFullRangeCanvasQCD_600to800->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrQCD_600to800_ = (TH1F*)InvMassDiMuBarrBarrCanvasQCD_600to800->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_600to800_ = (TH1F*)InvMassDiMuBarrEndcCanvasQCD_600to800->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_600to800_ = (TH1F*)InvMassDiMuEndcEndcCanvasQCD_600to800->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_600to800_ = (TH1F*)Mu1PtCanvasQCD_600to800->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtQCD_600to800_ = (TH1F*)Mu2PtCanvasQCD_600to800->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtQCD_600to800_ = (TH1F*)DiMuPtCanvasQCD_600to800->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaQCD_600to800_ = (TH1F*)Mu1EtaCanvasQCD_600to800->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaQCD_600to800_ = (TH1F*)Mu2EtaCanvasQCD_600to800->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaQCD_600to800_ = (TH1F*)DiTauEtaCanvasQCD_600to800->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiQCD_600to800_ = (TH1F*)DiTauPhiCanvasQCD_600to800->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaQCD_600to800_ = (TH1F*)DiMuEtaCanvasQCD_600to800->GetPrimitive("DiMuEta");
  TH1F *DiMudRQCD_600to800_ = (TH1F*)DiMudRCanvasQCD_600to800->GetPrimitive("DiMudR");
  TH1F *DiMuPhiQCD_600to800_ = (TH1F*)DiMuPhiCanvasQCD_600to800->GetPrimitive("DiMuPhi");
  TH1F *EtMETQCD_600to800_ = (TH1F*)EtMETCanvasQCD_600to800->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassQCD_600to800_ = (TH1F*)DiTauDiMuMassCanvasQCD_600to800->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_600to800_ = (TH1F*)DiMuDiTauDeltaPhiCanvasQCD_600to800->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_600to800_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_600to800->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_600to800_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_600to800->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_600to800_ = (TH1F*)DiTaudRCanvasQCD_600to800->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_600to800_ = (TH1F*)DiTauMassSmallerdRCanvasQCD_600to800->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetQCD_600to800_ = (TH1F*)HighestCSVInclJetCanvasQCD_600to800->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // QCD_800to1000
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_800to1000_ = (TH1F*)NMedIsoTausWithMu3CanvasQCD_800to1000->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_800to1000_ = (TH1F*)InvMassTauHadMu3CanvasQCD_800to1000->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_800to1000_ = (TH1F*)PtTauHadMu3CanvasQCD_800to1000->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeQCD_800to1000_ = (TH1F*)InvMassUpsilonRangeCanvasQCD_800to1000->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeQCD_800to1000_ = (TH1F*)InvMassZPeakRangeCanvasQCD_800to1000->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeQCD_800to1000_ = (TH1F*)InvMassFullRangeCanvasQCD_800to1000->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrQCD_800to1000_ = (TH1F*)InvMassDiMuBarrBarrCanvasQCD_800to1000->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_800to1000_ = (TH1F*)InvMassDiMuBarrEndcCanvasQCD_800to1000->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_800to1000_ = (TH1F*)InvMassDiMuEndcEndcCanvasQCD_800to1000->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_800to1000_ = (TH1F*)Mu1PtCanvasQCD_800to1000->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtQCD_800to1000_ = (TH1F*)Mu2PtCanvasQCD_800to1000->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtQCD_800to1000_ = (TH1F*)DiMuPtCanvasQCD_800to1000->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaQCD_800to1000_ = (TH1F*)Mu1EtaCanvasQCD_800to1000->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaQCD_800to1000_ = (TH1F*)Mu2EtaCanvasQCD_800to1000->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaQCD_800to1000_ = (TH1F*)DiTauEtaCanvasQCD_800to1000->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiQCD_800to1000_ = (TH1F*)DiTauPhiCanvasQCD_800to1000->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaQCD_800to1000_ = (TH1F*)DiMuEtaCanvasQCD_800to1000->GetPrimitive("DiMuEta");
  TH1F *DiMudRQCD_800to1000_ = (TH1F*)DiMudRCanvasQCD_800to1000->GetPrimitive("DiMudR");
  TH1F *DiMuPhiQCD_800to1000_ = (TH1F*)DiMuPhiCanvasQCD_800to1000->GetPrimitive("DiMuPhi");
  TH1F *EtMETQCD_800to1000_ = (TH1F*)EtMETCanvasQCD_800to1000->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassQCD_800to1000_ = (TH1F*)DiTauDiMuMassCanvasQCD_800to1000->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_800to1000_ = (TH1F*)DiMuDiTauDeltaPhiCanvasQCD_800to1000->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_800to1000_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_800to1000->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_800to1000_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_800to1000->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_800to1000_ = (TH1F*)DiTaudRCanvasQCD_800to1000->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_800to1000_ = (TH1F*)DiTauMassSmallerdRCanvasQCD_800to1000->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetQCD_800to1000_ = (TH1F*)HighestCSVInclJetCanvasQCD_800to1000->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // QCD_80to120
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_80to120_ = (TH1F*)NMedIsoTausWithMu3CanvasQCD_80to120->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_80to120_ = (TH1F*)InvMassTauHadMu3CanvasQCD_80to120->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_80to120_ = (TH1F*)PtTauHadMu3CanvasQCD_80to120->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeQCD_80to120_ = (TH1F*)InvMassUpsilonRangeCanvasQCD_80to120->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeQCD_80to120_ = (TH1F*)InvMassZPeakRangeCanvasQCD_80to120->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeQCD_80to120_ = (TH1F*)InvMassFullRangeCanvasQCD_80to120->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrQCD_80to120_ = (TH1F*)InvMassDiMuBarrBarrCanvasQCD_80to120->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_80to120_ = (TH1F*)InvMassDiMuBarrEndcCanvasQCD_80to120->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_80to120_ = (TH1F*)InvMassDiMuEndcEndcCanvasQCD_80to120->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_80to120_ = (TH1F*)Mu1PtCanvasQCD_80to120->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtQCD_80to120_ = (TH1F*)Mu2PtCanvasQCD_80to120->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtQCD_80to120_ = (TH1F*)DiMuPtCanvasQCD_80to120->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaQCD_80to120_ = (TH1F*)Mu1EtaCanvasQCD_80to120->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaQCD_80to120_ = (TH1F*)Mu2EtaCanvasQCD_80to120->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaQCD_80to120_ = (TH1F*)DiTauEtaCanvasQCD_80to120->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiQCD_80to120_ = (TH1F*)DiTauPhiCanvasQCD_80to120->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaQCD_80to120_ = (TH1F*)DiMuEtaCanvasQCD_80to120->GetPrimitive("DiMuEta");
  TH1F *DiMudRQCD_80to120_ = (TH1F*)DiMudRCanvasQCD_80to120->GetPrimitive("DiMudR");
  TH1F *DiMuPhiQCD_80to120_ = (TH1F*)DiMuPhiCanvasQCD_80to120->GetPrimitive("DiMuPhi");
  TH1F *EtMETQCD_80to120_ = (TH1F*)EtMETCanvasQCD_80to120->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassQCD_80to120_ = (TH1F*)DiTauDiMuMassCanvasQCD_80to120->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_80to120_ = (TH1F*)DiMuDiTauDeltaPhiCanvasQCD_80to120->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_80to120_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_80to120->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_80to120_ = (TH1F*)METDiMuDeltaPhiCanvasQCD_80to120->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_80to120_ = (TH1F*)DiTaudRCanvasQCD_80to120->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_80to120_ = (TH1F*)DiTauMassSmallerdRCanvasQCD_80to120->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetQCD_80to120_ = (TH1F*)HighestCSVInclJetCanvasQCD_80to120->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h125a11
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a11_ = (TH1F*)NMedIsoTausWithMu3Canvash125a11->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a11_ = (TH1F*)InvMassTauHadMu3Canvash125a11->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a11_ = (TH1F*)PtTauHadMu3Canvash125a11->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh125a11_ = (TH1F*)InvMassUpsilonRangeCanvash125a11->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh125a11_ = (TH1F*)InvMassZPeakRangeCanvash125a11->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh125a11_ = (TH1F*)InvMassFullRangeCanvash125a11->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a11_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a11->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a11_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a11->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a11_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a11->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a11_ = (TH1F*)Mu1PtCanvash125a11->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a11_ = (TH1F*)Mu2PtCanvash125a11->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a11_ = (TH1F*)DiMuPtCanvash125a11->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah125a11_ = (TH1F*)Mu1EtaCanvash125a11->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah125a11_ = (TH1F*)Mu2EtaCanvash125a11->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah125a11_ = (TH1F*)DiTauEtaCanvash125a11->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a11_ = (TH1F*)DiTauPhiCanvash125a11->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a11_ = (TH1F*)DiMuEtaCanvash125a11->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a11_ = (TH1F*)DiMudRCanvash125a11->GetPrimitive("DiMudR");
  TH1F *DiMuPhih125a11_ = (TH1F*)DiMuPhiCanvash125a11->GetPrimitive("DiMuPhi");
  TH1F *EtMETh125a11_ = (TH1F*)EtMETCanvash125a11->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a11_ = (TH1F*)DiTauDiMuMassCanvash125a11->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a11_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a11->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a11_ = (TH1F*)METDiMuDeltaPhiCanvash125a11->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a11_ = (TH1F*)METDiMuDeltaPhiCanvash125a11->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a11_ = (TH1F*)DiTaudRCanvash125a11->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a11_ = (TH1F*)DiTauMassSmallerdRCanvash125a11->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth125a11_ = (TH1F*)HighestCSVInclJetCanvash125a11->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h125a13
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a13_ = (TH1F*)NMedIsoTausWithMu3Canvash125a13->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a13_ = (TH1F*)InvMassTauHadMu3Canvash125a13->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a13_ = (TH1F*)PtTauHadMu3Canvash125a13->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh125a13_ = (TH1F*)InvMassUpsilonRangeCanvash125a13->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh125a13_ = (TH1F*)InvMassZPeakRangeCanvash125a13->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh125a13_ = (TH1F*)InvMassFullRangeCanvash125a13->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a13_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a13->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a13_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a13->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a13_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a13->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a13_ = (TH1F*)Mu1PtCanvash125a13->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a13_ = (TH1F*)Mu2PtCanvash125a13->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a13_ = (TH1F*)DiMuPtCanvash125a13->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah125a13_ = (TH1F*)Mu1EtaCanvash125a13->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah125a13_ = (TH1F*)Mu2EtaCanvash125a13->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah125a13_ = (TH1F*)DiTauEtaCanvash125a13->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a13_ = (TH1F*)DiTauPhiCanvash125a13->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a13_ = (TH1F*)DiMuEtaCanvash125a13->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a13_ = (TH1F*)DiMudRCanvash125a13->GetPrimitive("DiMudR");
  TH1F *DiMuPhih125a13_ = (TH1F*)DiMuPhiCanvash125a13->GetPrimitive("DiMuPhi");
  TH1F *EtMETh125a13_ = (TH1F*)EtMETCanvash125a13->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a13_ = (TH1F*)DiTauDiMuMassCanvash125a13->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a13_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a13->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a13_ = (TH1F*)METDiMuDeltaPhiCanvash125a13->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a13_ = (TH1F*)METDiMuDeltaPhiCanvash125a13->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a13_ = (TH1F*)DiTaudRCanvash125a13->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a13_ = (TH1F*)DiTauMassSmallerdRCanvash125a13->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth125a13_ = (TH1F*)HighestCSVInclJetCanvash125a13->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h125a15
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a15_ = (TH1F*)NMedIsoTausWithMu3Canvash125a15->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a15_ = (TH1F*)InvMassTauHadMu3Canvash125a15->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a15_ = (TH1F*)PtTauHadMu3Canvash125a15->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh125a15_ = (TH1F*)InvMassUpsilonRangeCanvash125a15->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh125a15_ = (TH1F*)InvMassZPeakRangeCanvash125a15->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh125a15_ = (TH1F*)InvMassFullRangeCanvash125a15->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a15_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a15->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a15_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a15->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a15_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a15->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a15_ = (TH1F*)Mu1PtCanvash125a15->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a15_ = (TH1F*)Mu2PtCanvash125a15->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a15_ = (TH1F*)DiMuPtCanvash125a15->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah125a15_ = (TH1F*)Mu1EtaCanvash125a15->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah125a15_ = (TH1F*)Mu2EtaCanvash125a15->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah125a15_ = (TH1F*)DiTauEtaCanvash125a15->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a15_ = (TH1F*)DiTauPhiCanvash125a15->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a15_ = (TH1F*)DiMuEtaCanvash125a15->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a15_ = (TH1F*)DiMudRCanvash125a15->GetPrimitive("DiMudR");
  TH1F *DiMuPhih125a15_ = (TH1F*)DiMuPhiCanvash125a15->GetPrimitive("DiMuPhi");
  TH1F *EtMETh125a15_ = (TH1F*)EtMETCanvash125a15->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a15_ = (TH1F*)DiTauDiMuMassCanvash125a15->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a15_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a15->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a15_ = (TH1F*)METDiMuDeltaPhiCanvash125a15->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a15_ = (TH1F*)METDiMuDeltaPhiCanvash125a15->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a15_ = (TH1F*)DiTaudRCanvash125a15->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a15_ = (TH1F*)DiTauMassSmallerdRCanvash125a15->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth125a15_ = (TH1F*)HighestCSVInclJetCanvash125a15->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h125a17
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a17_ = (TH1F*)NMedIsoTausWithMu3Canvash125a17->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a17_ = (TH1F*)InvMassTauHadMu3Canvash125a17->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a17_ = (TH1F*)PtTauHadMu3Canvash125a17->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh125a17_ = (TH1F*)InvMassUpsilonRangeCanvash125a17->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh125a17_ = (TH1F*)InvMassZPeakRangeCanvash125a17->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh125a17_ = (TH1F*)InvMassFullRangeCanvash125a17->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a17_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a17->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a17_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a17->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a17_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a17->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a17_ = (TH1F*)Mu1PtCanvash125a17->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a17_ = (TH1F*)Mu2PtCanvash125a17->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a17_ = (TH1F*)DiMuPtCanvash125a17->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah125a17_ = (TH1F*)Mu1EtaCanvash125a17->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah125a17_ = (TH1F*)Mu2EtaCanvash125a17->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah125a17_ = (TH1F*)DiTauEtaCanvash125a17->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a17_ = (TH1F*)DiTauPhiCanvash125a17->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a17_ = (TH1F*)DiMuEtaCanvash125a17->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a17_ = (TH1F*)DiMudRCanvash125a17->GetPrimitive("DiMudR");
  TH1F *DiMuPhih125a17_ = (TH1F*)DiMuPhiCanvash125a17->GetPrimitive("DiMuPhi");
  TH1F *EtMETh125a17_ = (TH1F*)EtMETCanvash125a17->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a17_ = (TH1F*)DiTauDiMuMassCanvash125a17->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a17_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a17->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a17_ = (TH1F*)METDiMuDeltaPhiCanvash125a17->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a17_ = (TH1F*)METDiMuDeltaPhiCanvash125a17->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a17_ = (TH1F*)DiTaudRCanvash125a17->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a17_ = (TH1F*)DiTauMassSmallerdRCanvash125a17->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth125a17_ = (TH1F*)HighestCSVInclJetCanvash125a17->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h125a19
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a19_ = (TH1F*)NMedIsoTausWithMu3Canvash125a19->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a19_ = (TH1F*)InvMassTauHadMu3Canvash125a19->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a19_ = (TH1F*)PtTauHadMu3Canvash125a19->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh125a19_ = (TH1F*)InvMassUpsilonRangeCanvash125a19->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh125a19_ = (TH1F*)InvMassZPeakRangeCanvash125a19->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh125a19_ = (TH1F*)InvMassFullRangeCanvash125a19->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a19_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a19->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a19_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a19->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a19_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a19->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a19_ = (TH1F*)Mu1PtCanvash125a19->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a19_ = (TH1F*)Mu2PtCanvash125a19->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a19_ = (TH1F*)DiMuPtCanvash125a19->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah125a19_ = (TH1F*)Mu1EtaCanvash125a19->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah125a19_ = (TH1F*)Mu2EtaCanvash125a19->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah125a19_ = (TH1F*)DiTauEtaCanvash125a19->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a19_ = (TH1F*)DiTauPhiCanvash125a19->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a19_ = (TH1F*)DiMuEtaCanvash125a19->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a19_ = (TH1F*)DiMudRCanvash125a19->GetPrimitive("DiMudR");
  TH1F *DiMuPhih125a19_ = (TH1F*)DiMuPhiCanvash125a19->GetPrimitive("DiMuPhi");
  TH1F *EtMETh125a19_ = (TH1F*)EtMETCanvash125a19->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a19_ = (TH1F*)DiTauDiMuMassCanvash125a19->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a19_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a19->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a19_ = (TH1F*)METDiMuDeltaPhiCanvash125a19->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a19_ = (TH1F*)METDiMuDeltaPhiCanvash125a19->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a19_ = (TH1F*)DiTaudRCanvash125a19->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a19_ = (TH1F*)DiTauMassSmallerdRCanvash125a19->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth125a19_ = (TH1F*)HighestCSVInclJetCanvash125a19->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h125a21
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a21_ = (TH1F*)NMedIsoTausWithMu3Canvash125a21->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a21_ = (TH1F*)InvMassTauHadMu3Canvash125a21->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a21_ = (TH1F*)PtTauHadMu3Canvash125a21->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh125a21_ = (TH1F*)InvMassUpsilonRangeCanvash125a21->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh125a21_ = (TH1F*)InvMassZPeakRangeCanvash125a21->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh125a21_ = (TH1F*)InvMassFullRangeCanvash125a21->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a21_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a21->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a21_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a21->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a21_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a21->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a21_ = (TH1F*)Mu1PtCanvash125a21->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a21_ = (TH1F*)Mu2PtCanvash125a21->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a21_ = (TH1F*)DiMuPtCanvash125a21->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah125a21_ = (TH1F*)Mu1EtaCanvash125a21->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah125a21_ = (TH1F*)Mu2EtaCanvash125a21->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah125a21_ = (TH1F*)DiTauEtaCanvash125a21->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a21_ = (TH1F*)DiTauPhiCanvash125a21->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a21_ = (TH1F*)DiMuEtaCanvash125a21->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a21_ = (TH1F*)DiMudRCanvash125a21->GetPrimitive("DiMudR");
  TH1F *DiMuPhih125a21_ = (TH1F*)DiMuPhiCanvash125a21->GetPrimitive("DiMuPhi");
  TH1F *EtMETh125a21_ = (TH1F*)EtMETCanvash125a21->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a21_ = (TH1F*)DiTauDiMuMassCanvash125a21->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a21_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a21->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a21_ = (TH1F*)METDiMuDeltaPhiCanvash125a21->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a21_ = (TH1F*)METDiMuDeltaPhiCanvash125a21->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a21_ = (TH1F*)DiTaudRCanvash125a21->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a21_ = (TH1F*)DiTauMassSmallerdRCanvash125a21->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth125a21_ = (TH1F*)HighestCSVInclJetCanvash125a21->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h125a5
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a5_ = (TH1F*)NMedIsoTausWithMu3Canvash125a5->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a5_ = (TH1F*)InvMassTauHadMu3Canvash125a5->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a5_ = (TH1F*)PtTauHadMu3Canvash125a5->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh125a5_ = (TH1F*)InvMassUpsilonRangeCanvash125a5->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh125a5_ = (TH1F*)InvMassZPeakRangeCanvash125a5->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh125a5_ = (TH1F*)InvMassFullRangeCanvash125a5->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a5_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a5->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a5_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a5->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a5_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a5->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a5_ = (TH1F*)Mu1PtCanvash125a5->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a5_ = (TH1F*)Mu2PtCanvash125a5->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a5_ = (TH1F*)DiMuPtCanvash125a5->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah125a5_ = (TH1F*)Mu1EtaCanvash125a5->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah125a5_ = (TH1F*)Mu2EtaCanvash125a5->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah125a5_ = (TH1F*)DiTauEtaCanvash125a5->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a5_ = (TH1F*)DiTauPhiCanvash125a5->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a5_ = (TH1F*)DiMuEtaCanvash125a5->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a5_ = (TH1F*)DiMudRCanvash125a5->GetPrimitive("DiMudR");
  TH1F *DiMuPhih125a5_ = (TH1F*)DiMuPhiCanvash125a5->GetPrimitive("DiMuPhi");
  TH1F *EtMETh125a5_ = (TH1F*)EtMETCanvash125a5->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a5_ = (TH1F*)DiTauDiMuMassCanvash125a5->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a5_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a5->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a5_ = (TH1F*)METDiMuDeltaPhiCanvash125a5->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a5_ = (TH1F*)METDiMuDeltaPhiCanvash125a5->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a5_ = (TH1F*)DiTaudRCanvash125a5->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a5_ = (TH1F*)DiTauMassSmallerdRCanvash125a5->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth125a5_ = (TH1F*)HighestCSVInclJetCanvash125a5->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h125a7
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a7_ = (TH1F*)NMedIsoTausWithMu3Canvash125a7->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a7_ = (TH1F*)InvMassTauHadMu3Canvash125a7->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a7_ = (TH1F*)PtTauHadMu3Canvash125a7->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh125a7_ = (TH1F*)InvMassUpsilonRangeCanvash125a7->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh125a7_ = (TH1F*)InvMassZPeakRangeCanvash125a7->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh125a7_ = (TH1F*)InvMassFullRangeCanvash125a7->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a7_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a7->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a7_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a7->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a7_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a7->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a7_ = (TH1F*)Mu1PtCanvash125a7->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a7_ = (TH1F*)Mu2PtCanvash125a7->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a7_ = (TH1F*)DiMuPtCanvash125a7->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah125a7_ = (TH1F*)Mu1EtaCanvash125a7->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah125a7_ = (TH1F*)Mu2EtaCanvash125a7->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah125a7_ = (TH1F*)DiTauEtaCanvash125a7->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a7_ = (TH1F*)DiTauPhiCanvash125a7->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a7_ = (TH1F*)DiMuEtaCanvash125a7->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a7_ = (TH1F*)DiMudRCanvash125a7->GetPrimitive("DiMudR");
  TH1F *DiMuPhih125a7_ = (TH1F*)DiMuPhiCanvash125a7->GetPrimitive("DiMuPhi");
  TH1F *EtMETh125a7_ = (TH1F*)EtMETCanvash125a7->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a7_ = (TH1F*)DiTauDiMuMassCanvash125a7->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a7_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a7->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a7_ = (TH1F*)METDiMuDeltaPhiCanvash125a7->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a7_ = (TH1F*)METDiMuDeltaPhiCanvash125a7->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a7_ = (TH1F*)DiTaudRCanvash125a7->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a7_ = (TH1F*)DiTauMassSmallerdRCanvash125a7->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth125a7_ = (TH1F*)HighestCSVInclJetCanvash125a7->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h125a9
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a9_ = (TH1F*)NMedIsoTausWithMu3Canvash125a9->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a9_ = (TH1F*)InvMassTauHadMu3Canvash125a9->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a9_ = (TH1F*)PtTauHadMu3Canvash125a9->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh125a9_ = (TH1F*)InvMassUpsilonRangeCanvash125a9->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh125a9_ = (TH1F*)InvMassZPeakRangeCanvash125a9->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh125a9_ = (TH1F*)InvMassFullRangeCanvash125a9->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a9_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a9->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a9_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a9->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a9_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a9->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a9_ = (TH1F*)Mu1PtCanvash125a9->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a9_ = (TH1F*)Mu2PtCanvash125a9->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a9_ = (TH1F*)DiMuPtCanvash125a9->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah125a9_ = (TH1F*)Mu1EtaCanvash125a9->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah125a9_ = (TH1F*)Mu2EtaCanvash125a9->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah125a9_ = (TH1F*)DiTauEtaCanvash125a9->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a9_ = (TH1F*)DiTauPhiCanvash125a9->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a9_ = (TH1F*)DiMuEtaCanvash125a9->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a9_ = (TH1F*)DiMudRCanvash125a9->GetPrimitive("DiMudR");
  TH1F *DiMuPhih125a9_ = (TH1F*)DiMuPhiCanvash125a9->GetPrimitive("DiMuPhi");
  TH1F *EtMETh125a9_ = (TH1F*)EtMETCanvash125a9->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a9_ = (TH1F*)DiTauDiMuMassCanvash125a9->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a9_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a9->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a9_ = (TH1F*)METDiMuDeltaPhiCanvash125a9->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a9_ = (TH1F*)METDiMuDeltaPhiCanvash125a9->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a9_ = (TH1F*)DiTaudRCanvash125a9->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a9_ = (TH1F*)DiTauMassSmallerdRCanvash125a9->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth125a9_ = (TH1F*)HighestCSVInclJetCanvash125a9->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h300a11
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a11_ = (TH1F*)NMedIsoTausWithMu3Canvash300a11->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a11_ = (TH1F*)InvMassTauHadMu3Canvash300a11->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a11_ = (TH1F*)PtTauHadMu3Canvash300a11->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh300a11_ = (TH1F*)InvMassUpsilonRangeCanvash300a11->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh300a11_ = (TH1F*)InvMassZPeakRangeCanvash300a11->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh300a11_ = (TH1F*)InvMassFullRangeCanvash300a11->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a11_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a11->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a11_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a11->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a11_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a11->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a11_ = (TH1F*)Mu1PtCanvash300a11->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a11_ = (TH1F*)Mu2PtCanvash300a11->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a11_ = (TH1F*)DiMuPtCanvash300a11->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah300a11_ = (TH1F*)Mu1EtaCanvash300a11->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah300a11_ = (TH1F*)Mu2EtaCanvash300a11->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah300a11_ = (TH1F*)DiTauEtaCanvash300a11->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a11_ = (TH1F*)DiTauPhiCanvash300a11->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a11_ = (TH1F*)DiMuEtaCanvash300a11->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a11_ = (TH1F*)DiMudRCanvash300a11->GetPrimitive("DiMudR");
  TH1F *DiMuPhih300a11_ = (TH1F*)DiMuPhiCanvash300a11->GetPrimitive("DiMuPhi");
  TH1F *EtMETh300a11_ = (TH1F*)EtMETCanvash300a11->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a11_ = (TH1F*)DiTauDiMuMassCanvash300a11->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a11_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a11->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a11_ = (TH1F*)METDiMuDeltaPhiCanvash300a11->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a11_ = (TH1F*)METDiMuDeltaPhiCanvash300a11->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a11_ = (TH1F*)DiTaudRCanvash300a11->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a11_ = (TH1F*)DiTauMassSmallerdRCanvash300a11->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth300a11_ = (TH1F*)HighestCSVInclJetCanvash300a11->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h300a13
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a13_ = (TH1F*)NMedIsoTausWithMu3Canvash300a13->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a13_ = (TH1F*)InvMassTauHadMu3Canvash300a13->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a13_ = (TH1F*)PtTauHadMu3Canvash300a13->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh300a13_ = (TH1F*)InvMassUpsilonRangeCanvash300a13->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh300a13_ = (TH1F*)InvMassZPeakRangeCanvash300a13->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh300a13_ = (TH1F*)InvMassFullRangeCanvash300a13->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a13_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a13->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a13_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a13->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a13_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a13->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a13_ = (TH1F*)Mu1PtCanvash300a13->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a13_ = (TH1F*)Mu2PtCanvash300a13->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a13_ = (TH1F*)DiMuPtCanvash300a13->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah300a13_ = (TH1F*)Mu1EtaCanvash300a13->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah300a13_ = (TH1F*)Mu2EtaCanvash300a13->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah300a13_ = (TH1F*)DiTauEtaCanvash300a13->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a13_ = (TH1F*)DiTauPhiCanvash300a13->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a13_ = (TH1F*)DiMuEtaCanvash300a13->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a13_ = (TH1F*)DiMudRCanvash300a13->GetPrimitive("DiMudR");
  TH1F *DiMuPhih300a13_ = (TH1F*)DiMuPhiCanvash300a13->GetPrimitive("DiMuPhi");
  TH1F *EtMETh300a13_ = (TH1F*)EtMETCanvash300a13->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a13_ = (TH1F*)DiTauDiMuMassCanvash300a13->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a13_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a13->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a13_ = (TH1F*)METDiMuDeltaPhiCanvash300a13->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a13_ = (TH1F*)METDiMuDeltaPhiCanvash300a13->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a13_ = (TH1F*)DiTaudRCanvash300a13->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a13_ = (TH1F*)DiTauMassSmallerdRCanvash300a13->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth300a13_ = (TH1F*)HighestCSVInclJetCanvash300a13->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h300a15
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a15_ = (TH1F*)NMedIsoTausWithMu3Canvash300a15->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a15_ = (TH1F*)InvMassTauHadMu3Canvash300a15->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a15_ = (TH1F*)PtTauHadMu3Canvash300a15->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh300a15_ = (TH1F*)InvMassUpsilonRangeCanvash300a15->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh300a15_ = (TH1F*)InvMassZPeakRangeCanvash300a15->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh300a15_ = (TH1F*)InvMassFullRangeCanvash300a15->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a15_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a15->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a15_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a15->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a15_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a15->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a15_ = (TH1F*)Mu1PtCanvash300a15->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a15_ = (TH1F*)Mu2PtCanvash300a15->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a15_ = (TH1F*)DiMuPtCanvash300a15->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah300a15_ = (TH1F*)Mu1EtaCanvash300a15->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah300a15_ = (TH1F*)Mu2EtaCanvash300a15->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah300a15_ = (TH1F*)DiTauEtaCanvash300a15->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a15_ = (TH1F*)DiTauPhiCanvash300a15->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a15_ = (TH1F*)DiMuEtaCanvash300a15->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a15_ = (TH1F*)DiMudRCanvash300a15->GetPrimitive("DiMudR");
  TH1F *DiMuPhih300a15_ = (TH1F*)DiMuPhiCanvash300a15->GetPrimitive("DiMuPhi");
  TH1F *EtMETh300a15_ = (TH1F*)EtMETCanvash300a15->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a15_ = (TH1F*)DiTauDiMuMassCanvash300a15->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a15_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a15->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a15_ = (TH1F*)METDiMuDeltaPhiCanvash300a15->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a15_ = (TH1F*)METDiMuDeltaPhiCanvash300a15->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a15_ = (TH1F*)DiTaudRCanvash300a15->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a15_ = (TH1F*)DiTauMassSmallerdRCanvash300a15->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth300a15_ = (TH1F*)HighestCSVInclJetCanvash300a15->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h300a17
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a17_ = (TH1F*)NMedIsoTausWithMu3Canvash300a17->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a17_ = (TH1F*)InvMassTauHadMu3Canvash300a17->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a17_ = (TH1F*)PtTauHadMu3Canvash300a17->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh300a17_ = (TH1F*)InvMassUpsilonRangeCanvash300a17->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh300a17_ = (TH1F*)InvMassZPeakRangeCanvash300a17->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh300a17_ = (TH1F*)InvMassFullRangeCanvash300a17->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a17_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a17->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a17_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a17->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a17_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a17->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a17_ = (TH1F*)Mu1PtCanvash300a17->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a17_ = (TH1F*)Mu2PtCanvash300a17->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a17_ = (TH1F*)DiMuPtCanvash300a17->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah300a17_ = (TH1F*)Mu1EtaCanvash300a17->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah300a17_ = (TH1F*)Mu2EtaCanvash300a17->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah300a17_ = (TH1F*)DiTauEtaCanvash300a17->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a17_ = (TH1F*)DiTauPhiCanvash300a17->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a17_ = (TH1F*)DiMuEtaCanvash300a17->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a17_ = (TH1F*)DiMudRCanvash300a17->GetPrimitive("DiMudR");
  TH1F *DiMuPhih300a17_ = (TH1F*)DiMuPhiCanvash300a17->GetPrimitive("DiMuPhi");
  TH1F *EtMETh300a17_ = (TH1F*)EtMETCanvash300a17->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a17_ = (TH1F*)DiTauDiMuMassCanvash300a17->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a17_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a17->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a17_ = (TH1F*)METDiMuDeltaPhiCanvash300a17->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a17_ = (TH1F*)METDiMuDeltaPhiCanvash300a17->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a17_ = (TH1F*)DiTaudRCanvash300a17->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a17_ = (TH1F*)DiTauMassSmallerdRCanvash300a17->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth300a17_ = (TH1F*)HighestCSVInclJetCanvash300a17->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h300a19
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a19_ = (TH1F*)NMedIsoTausWithMu3Canvash300a19->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a19_ = (TH1F*)InvMassTauHadMu3Canvash300a19->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a19_ = (TH1F*)PtTauHadMu3Canvash300a19->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh300a19_ = (TH1F*)InvMassUpsilonRangeCanvash300a19->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh300a19_ = (TH1F*)InvMassZPeakRangeCanvash300a19->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh300a19_ = (TH1F*)InvMassFullRangeCanvash300a19->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a19_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a19->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a19_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a19->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a19_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a19->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a19_ = (TH1F*)Mu1PtCanvash300a19->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a19_ = (TH1F*)Mu2PtCanvash300a19->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a19_ = (TH1F*)DiMuPtCanvash300a19->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah300a19_ = (TH1F*)Mu1EtaCanvash300a19->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah300a19_ = (TH1F*)Mu2EtaCanvash300a19->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah300a19_ = (TH1F*)DiTauEtaCanvash300a19->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a19_ = (TH1F*)DiTauPhiCanvash300a19->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a19_ = (TH1F*)DiMuEtaCanvash300a19->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a19_ = (TH1F*)DiMudRCanvash300a19->GetPrimitive("DiMudR");
  TH1F *DiMuPhih300a19_ = (TH1F*)DiMuPhiCanvash300a19->GetPrimitive("DiMuPhi");
  TH1F *EtMETh300a19_ = (TH1F*)EtMETCanvash300a19->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a19_ = (TH1F*)DiTauDiMuMassCanvash300a19->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a19_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a19->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a19_ = (TH1F*)METDiMuDeltaPhiCanvash300a19->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a19_ = (TH1F*)METDiMuDeltaPhiCanvash300a19->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a19_ = (TH1F*)DiTaudRCanvash300a19->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a19_ = (TH1F*)DiTauMassSmallerdRCanvash300a19->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth300a19_ = (TH1F*)HighestCSVInclJetCanvash300a19->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h300a21
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a21_ = (TH1F*)NMedIsoTausWithMu3Canvash300a21->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a21_ = (TH1F*)InvMassTauHadMu3Canvash300a21->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a21_ = (TH1F*)PtTauHadMu3Canvash300a21->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh300a21_ = (TH1F*)InvMassUpsilonRangeCanvash300a21->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh300a21_ = (TH1F*)InvMassZPeakRangeCanvash300a21->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh300a21_ = (TH1F*)InvMassFullRangeCanvash300a21->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a21_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a21->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a21_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a21->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a21_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a21->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a21_ = (TH1F*)Mu1PtCanvash300a21->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a21_ = (TH1F*)Mu2PtCanvash300a21->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a21_ = (TH1F*)DiMuPtCanvash300a21->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah300a21_ = (TH1F*)Mu1EtaCanvash300a21->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah300a21_ = (TH1F*)Mu2EtaCanvash300a21->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah300a21_ = (TH1F*)DiTauEtaCanvash300a21->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a21_ = (TH1F*)DiTauPhiCanvash300a21->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a21_ = (TH1F*)DiMuEtaCanvash300a21->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a21_ = (TH1F*)DiMudRCanvash300a21->GetPrimitive("DiMudR");
  TH1F *DiMuPhih300a21_ = (TH1F*)DiMuPhiCanvash300a21->GetPrimitive("DiMuPhi");
  TH1F *EtMETh300a21_ = (TH1F*)EtMETCanvash300a21->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a21_ = (TH1F*)DiTauDiMuMassCanvash300a21->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a21_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a21->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a21_ = (TH1F*)METDiMuDeltaPhiCanvash300a21->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a21_ = (TH1F*)METDiMuDeltaPhiCanvash300a21->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a21_ = (TH1F*)DiTaudRCanvash300a21->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a21_ = (TH1F*)DiTauMassSmallerdRCanvash300a21->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth300a21_ = (TH1F*)HighestCSVInclJetCanvash300a21->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h300a5
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a5_ = (TH1F*)NMedIsoTausWithMu3Canvash300a5->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a5_ = (TH1F*)InvMassTauHadMu3Canvash300a5->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a5_ = (TH1F*)PtTauHadMu3Canvash300a5->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh300a5_ = (TH1F*)InvMassUpsilonRangeCanvash300a5->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh300a5_ = (TH1F*)InvMassZPeakRangeCanvash300a5->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh300a5_ = (TH1F*)InvMassFullRangeCanvash300a5->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a5_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a5->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a5_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a5->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a5_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a5->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a5_ = (TH1F*)Mu1PtCanvash300a5->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a5_ = (TH1F*)Mu2PtCanvash300a5->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a5_ = (TH1F*)DiMuPtCanvash300a5->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah300a5_ = (TH1F*)Mu1EtaCanvash300a5->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah300a5_ = (TH1F*)Mu2EtaCanvash300a5->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah300a5_ = (TH1F*)DiTauEtaCanvash300a5->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a5_ = (TH1F*)DiTauPhiCanvash300a5->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a5_ = (TH1F*)DiMuEtaCanvash300a5->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a5_ = (TH1F*)DiMudRCanvash300a5->GetPrimitive("DiMudR");
  TH1F *DiMuPhih300a5_ = (TH1F*)DiMuPhiCanvash300a5->GetPrimitive("DiMuPhi");
  TH1F *EtMETh300a5_ = (TH1F*)EtMETCanvash300a5->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a5_ = (TH1F*)DiTauDiMuMassCanvash300a5->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a5_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a5->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a5_ = (TH1F*)METDiMuDeltaPhiCanvash300a5->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a5_ = (TH1F*)METDiMuDeltaPhiCanvash300a5->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a5_ = (TH1F*)DiTaudRCanvash300a5->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a5_ = (TH1F*)DiTauMassSmallerdRCanvash300a5->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth300a5_ = (TH1F*)HighestCSVInclJetCanvash300a5->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h300a7
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a7_ = (TH1F*)NMedIsoTausWithMu3Canvash300a7->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a7_ = (TH1F*)InvMassTauHadMu3Canvash300a7->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a7_ = (TH1F*)PtTauHadMu3Canvash300a7->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh300a7_ = (TH1F*)InvMassUpsilonRangeCanvash300a7->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh300a7_ = (TH1F*)InvMassZPeakRangeCanvash300a7->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh300a7_ = (TH1F*)InvMassFullRangeCanvash300a7->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a7_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a7->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a7_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a7->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a7_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a7->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a7_ = (TH1F*)Mu1PtCanvash300a7->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a7_ = (TH1F*)Mu2PtCanvash300a7->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a7_ = (TH1F*)DiMuPtCanvash300a7->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah300a7_ = (TH1F*)Mu1EtaCanvash300a7->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah300a7_ = (TH1F*)Mu2EtaCanvash300a7->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah300a7_ = (TH1F*)DiTauEtaCanvash300a7->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a7_ = (TH1F*)DiTauPhiCanvash300a7->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a7_ = (TH1F*)DiMuEtaCanvash300a7->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a7_ = (TH1F*)DiMudRCanvash300a7->GetPrimitive("DiMudR");
  TH1F *DiMuPhih300a7_ = (TH1F*)DiMuPhiCanvash300a7->GetPrimitive("DiMuPhi");
  TH1F *EtMETh300a7_ = (TH1F*)EtMETCanvash300a7->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a7_ = (TH1F*)DiTauDiMuMassCanvash300a7->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a7_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a7->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a7_ = (TH1F*)METDiMuDeltaPhiCanvash300a7->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a7_ = (TH1F*)METDiMuDeltaPhiCanvash300a7->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a7_ = (TH1F*)DiTaudRCanvash300a7->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a7_ = (TH1F*)DiTauMassSmallerdRCanvash300a7->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth300a7_ = (TH1F*)HighestCSVInclJetCanvash300a7->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h300a9
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a9_ = (TH1F*)NMedIsoTausWithMu3Canvash300a9->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a9_ = (TH1F*)InvMassTauHadMu3Canvash300a9->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a9_ = (TH1F*)PtTauHadMu3Canvash300a9->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh300a9_ = (TH1F*)InvMassUpsilonRangeCanvash300a9->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh300a9_ = (TH1F*)InvMassZPeakRangeCanvash300a9->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh300a9_ = (TH1F*)InvMassFullRangeCanvash300a9->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a9_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a9->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a9_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a9->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a9_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a9->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a9_ = (TH1F*)Mu1PtCanvash300a9->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a9_ = (TH1F*)Mu2PtCanvash300a9->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a9_ = (TH1F*)DiMuPtCanvash300a9->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah300a9_ = (TH1F*)Mu1EtaCanvash300a9->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah300a9_ = (TH1F*)Mu2EtaCanvash300a9->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah300a9_ = (TH1F*)DiTauEtaCanvash300a9->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a9_ = (TH1F*)DiTauPhiCanvash300a9->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a9_ = (TH1F*)DiMuEtaCanvash300a9->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a9_ = (TH1F*)DiMudRCanvash300a9->GetPrimitive("DiMudR");
  TH1F *DiMuPhih300a9_ = (TH1F*)DiMuPhiCanvash300a9->GetPrimitive("DiMuPhi");
  TH1F *EtMETh300a9_ = (TH1F*)EtMETCanvash300a9->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a9_ = (TH1F*)DiTauDiMuMassCanvash300a9->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a9_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a9->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a9_ = (TH1F*)METDiMuDeltaPhiCanvash300a9->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a9_ = (TH1F*)METDiMuDeltaPhiCanvash300a9->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a9_ = (TH1F*)DiTaudRCanvash300a9->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a9_ = (TH1F*)DiTauMassSmallerdRCanvash300a9->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth300a9_ = (TH1F*)HighestCSVInclJetCanvash300a9->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h750a11
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a11_ = (TH1F*)NMedIsoTausWithMu3Canvash750a11->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a11_ = (TH1F*)InvMassTauHadMu3Canvash750a11->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a11_ = (TH1F*)PtTauHadMu3Canvash750a11->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh750a11_ = (TH1F*)InvMassUpsilonRangeCanvash750a11->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh750a11_ = (TH1F*)InvMassZPeakRangeCanvash750a11->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh750a11_ = (TH1F*)InvMassFullRangeCanvash750a11->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a11_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a11->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a11_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a11->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a11_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a11->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a11_ = (TH1F*)Mu1PtCanvash750a11->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a11_ = (TH1F*)Mu2PtCanvash750a11->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a11_ = (TH1F*)DiMuPtCanvash750a11->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah750a11_ = (TH1F*)Mu1EtaCanvash750a11->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah750a11_ = (TH1F*)Mu2EtaCanvash750a11->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah750a11_ = (TH1F*)DiTauEtaCanvash750a11->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a11_ = (TH1F*)DiTauPhiCanvash750a11->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a11_ = (TH1F*)DiMuEtaCanvash750a11->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a11_ = (TH1F*)DiMudRCanvash750a11->GetPrimitive("DiMudR");
  TH1F *DiMuPhih750a11_ = (TH1F*)DiMuPhiCanvash750a11->GetPrimitive("DiMuPhi");
  TH1F *EtMETh750a11_ = (TH1F*)EtMETCanvash750a11->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a11_ = (TH1F*)DiTauDiMuMassCanvash750a11->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a11_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a11->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a11_ = (TH1F*)METDiMuDeltaPhiCanvash750a11->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a11_ = (TH1F*)METDiMuDeltaPhiCanvash750a11->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a11_ = (TH1F*)DiTaudRCanvash750a11->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a11_ = (TH1F*)DiTauMassSmallerdRCanvash750a11->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth750a11_ = (TH1F*)HighestCSVInclJetCanvash750a11->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h750a13
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a13_ = (TH1F*)NMedIsoTausWithMu3Canvash750a13->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a13_ = (TH1F*)InvMassTauHadMu3Canvash750a13->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a13_ = (TH1F*)PtTauHadMu3Canvash750a13->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh750a13_ = (TH1F*)InvMassUpsilonRangeCanvash750a13->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh750a13_ = (TH1F*)InvMassZPeakRangeCanvash750a13->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh750a13_ = (TH1F*)InvMassFullRangeCanvash750a13->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a13_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a13->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a13_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a13->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a13_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a13->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a13_ = (TH1F*)Mu1PtCanvash750a13->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a13_ = (TH1F*)Mu2PtCanvash750a13->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a13_ = (TH1F*)DiMuPtCanvash750a13->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah750a13_ = (TH1F*)Mu1EtaCanvash750a13->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah750a13_ = (TH1F*)Mu2EtaCanvash750a13->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah750a13_ = (TH1F*)DiTauEtaCanvash750a13->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a13_ = (TH1F*)DiTauPhiCanvash750a13->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a13_ = (TH1F*)DiMuEtaCanvash750a13->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a13_ = (TH1F*)DiMudRCanvash750a13->GetPrimitive("DiMudR");
  TH1F *DiMuPhih750a13_ = (TH1F*)DiMuPhiCanvash750a13->GetPrimitive("DiMuPhi");
  TH1F *EtMETh750a13_ = (TH1F*)EtMETCanvash750a13->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a13_ = (TH1F*)DiTauDiMuMassCanvash750a13->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a13_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a13->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a13_ = (TH1F*)METDiMuDeltaPhiCanvash750a13->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a13_ = (TH1F*)METDiMuDeltaPhiCanvash750a13->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a13_ = (TH1F*)DiTaudRCanvash750a13->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a13_ = (TH1F*)DiTauMassSmallerdRCanvash750a13->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth750a13_ = (TH1F*)HighestCSVInclJetCanvash750a13->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h750a15
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a15_ = (TH1F*)NMedIsoTausWithMu3Canvash750a15->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a15_ = (TH1F*)InvMassTauHadMu3Canvash750a15->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a15_ = (TH1F*)PtTauHadMu3Canvash750a15->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh750a15_ = (TH1F*)InvMassUpsilonRangeCanvash750a15->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh750a15_ = (TH1F*)InvMassZPeakRangeCanvash750a15->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh750a15_ = (TH1F*)InvMassFullRangeCanvash750a15->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a15_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a15->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a15_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a15->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a15_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a15->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a15_ = (TH1F*)Mu1PtCanvash750a15->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a15_ = (TH1F*)Mu2PtCanvash750a15->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a15_ = (TH1F*)DiMuPtCanvash750a15->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah750a15_ = (TH1F*)Mu1EtaCanvash750a15->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah750a15_ = (TH1F*)Mu2EtaCanvash750a15->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah750a15_ = (TH1F*)DiTauEtaCanvash750a15->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a15_ = (TH1F*)DiTauPhiCanvash750a15->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a15_ = (TH1F*)DiMuEtaCanvash750a15->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a15_ = (TH1F*)DiMudRCanvash750a15->GetPrimitive("DiMudR");
  TH1F *DiMuPhih750a15_ = (TH1F*)DiMuPhiCanvash750a15->GetPrimitive("DiMuPhi");
  TH1F *EtMETh750a15_ = (TH1F*)EtMETCanvash750a15->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a15_ = (TH1F*)DiTauDiMuMassCanvash750a15->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a15_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a15->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a15_ = (TH1F*)METDiMuDeltaPhiCanvash750a15->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a15_ = (TH1F*)METDiMuDeltaPhiCanvash750a15->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a15_ = (TH1F*)DiTaudRCanvash750a15->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a15_ = (TH1F*)DiTauMassSmallerdRCanvash750a15->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth750a15_ = (TH1F*)HighestCSVInclJetCanvash750a15->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h750a17
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a17_ = (TH1F*)NMedIsoTausWithMu3Canvash750a17->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a17_ = (TH1F*)InvMassTauHadMu3Canvash750a17->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a17_ = (TH1F*)PtTauHadMu3Canvash750a17->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh750a17_ = (TH1F*)InvMassUpsilonRangeCanvash750a17->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh750a17_ = (TH1F*)InvMassZPeakRangeCanvash750a17->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh750a17_ = (TH1F*)InvMassFullRangeCanvash750a17->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a17_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a17->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a17_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a17->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a17_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a17->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a17_ = (TH1F*)Mu1PtCanvash750a17->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a17_ = (TH1F*)Mu2PtCanvash750a17->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a17_ = (TH1F*)DiMuPtCanvash750a17->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah750a17_ = (TH1F*)Mu1EtaCanvash750a17->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah750a17_ = (TH1F*)Mu2EtaCanvash750a17->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah750a17_ = (TH1F*)DiTauEtaCanvash750a17->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a17_ = (TH1F*)DiTauPhiCanvash750a17->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a17_ = (TH1F*)DiMuEtaCanvash750a17->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a17_ = (TH1F*)DiMudRCanvash750a17->GetPrimitive("DiMudR");
  TH1F *DiMuPhih750a17_ = (TH1F*)DiMuPhiCanvash750a17->GetPrimitive("DiMuPhi");
  TH1F *EtMETh750a17_ = (TH1F*)EtMETCanvash750a17->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a17_ = (TH1F*)DiTauDiMuMassCanvash750a17->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a17_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a17->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a17_ = (TH1F*)METDiMuDeltaPhiCanvash750a17->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a17_ = (TH1F*)METDiMuDeltaPhiCanvash750a17->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a17_ = (TH1F*)DiTaudRCanvash750a17->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a17_ = (TH1F*)DiTauMassSmallerdRCanvash750a17->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth750a17_ = (TH1F*)HighestCSVInclJetCanvash750a17->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h750a19
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a19_ = (TH1F*)NMedIsoTausWithMu3Canvash750a19->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a19_ = (TH1F*)InvMassTauHadMu3Canvash750a19->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a19_ = (TH1F*)PtTauHadMu3Canvash750a19->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh750a19_ = (TH1F*)InvMassUpsilonRangeCanvash750a19->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh750a19_ = (TH1F*)InvMassZPeakRangeCanvash750a19->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh750a19_ = (TH1F*)InvMassFullRangeCanvash750a19->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a19_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a19->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a19_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a19->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a19_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a19->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a19_ = (TH1F*)Mu1PtCanvash750a19->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a19_ = (TH1F*)Mu2PtCanvash750a19->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a19_ = (TH1F*)DiMuPtCanvash750a19->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah750a19_ = (TH1F*)Mu1EtaCanvash750a19->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah750a19_ = (TH1F*)Mu2EtaCanvash750a19->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah750a19_ = (TH1F*)DiTauEtaCanvash750a19->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a19_ = (TH1F*)DiTauPhiCanvash750a19->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a19_ = (TH1F*)DiMuEtaCanvash750a19->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a19_ = (TH1F*)DiMudRCanvash750a19->GetPrimitive("DiMudR");
  TH1F *DiMuPhih750a19_ = (TH1F*)DiMuPhiCanvash750a19->GetPrimitive("DiMuPhi");
  TH1F *EtMETh750a19_ = (TH1F*)EtMETCanvash750a19->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a19_ = (TH1F*)DiTauDiMuMassCanvash750a19->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a19_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a19->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a19_ = (TH1F*)METDiMuDeltaPhiCanvash750a19->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a19_ = (TH1F*)METDiMuDeltaPhiCanvash750a19->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a19_ = (TH1F*)DiTaudRCanvash750a19->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a19_ = (TH1F*)DiTauMassSmallerdRCanvash750a19->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth750a19_ = (TH1F*)HighestCSVInclJetCanvash750a19->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h750a21
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a21_ = (TH1F*)NMedIsoTausWithMu3Canvash750a21->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a21_ = (TH1F*)InvMassTauHadMu3Canvash750a21->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a21_ = (TH1F*)PtTauHadMu3Canvash750a21->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh750a21_ = (TH1F*)InvMassUpsilonRangeCanvash750a21->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh750a21_ = (TH1F*)InvMassZPeakRangeCanvash750a21->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh750a21_ = (TH1F*)InvMassFullRangeCanvash750a21->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a21_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a21->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a21_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a21->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a21_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a21->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a21_ = (TH1F*)Mu1PtCanvash750a21->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a21_ = (TH1F*)Mu2PtCanvash750a21->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a21_ = (TH1F*)DiMuPtCanvash750a21->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah750a21_ = (TH1F*)Mu1EtaCanvash750a21->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah750a21_ = (TH1F*)Mu2EtaCanvash750a21->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah750a21_ = (TH1F*)DiTauEtaCanvash750a21->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a21_ = (TH1F*)DiTauPhiCanvash750a21->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a21_ = (TH1F*)DiMuEtaCanvash750a21->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a21_ = (TH1F*)DiMudRCanvash750a21->GetPrimitive("DiMudR");
  TH1F *DiMuPhih750a21_ = (TH1F*)DiMuPhiCanvash750a21->GetPrimitive("DiMuPhi");
  TH1F *EtMETh750a21_ = (TH1F*)EtMETCanvash750a21->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a21_ = (TH1F*)DiTauDiMuMassCanvash750a21->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a21_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a21->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a21_ = (TH1F*)METDiMuDeltaPhiCanvash750a21->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a21_ = (TH1F*)METDiMuDeltaPhiCanvash750a21->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a21_ = (TH1F*)DiTaudRCanvash750a21->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a21_ = (TH1F*)DiTauMassSmallerdRCanvash750a21->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth750a21_ = (TH1F*)HighestCSVInclJetCanvash750a21->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h750a5
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a5_ = (TH1F*)NMedIsoTausWithMu3Canvash750a5->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a5_ = (TH1F*)InvMassTauHadMu3Canvash750a5->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a5_ = (TH1F*)PtTauHadMu3Canvash750a5->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh750a5_ = (TH1F*)InvMassUpsilonRangeCanvash750a5->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh750a5_ = (TH1F*)InvMassZPeakRangeCanvash750a5->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh750a5_ = (TH1F*)InvMassFullRangeCanvash750a5->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a5_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a5->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a5_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a5->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a5_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a5->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a5_ = (TH1F*)Mu1PtCanvash750a5->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a5_ = (TH1F*)Mu2PtCanvash750a5->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a5_ = (TH1F*)DiMuPtCanvash750a5->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah750a5_ = (TH1F*)Mu1EtaCanvash750a5->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah750a5_ = (TH1F*)Mu2EtaCanvash750a5->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah750a5_ = (TH1F*)DiTauEtaCanvash750a5->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a5_ = (TH1F*)DiTauPhiCanvash750a5->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a5_ = (TH1F*)DiMuEtaCanvash750a5->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a5_ = (TH1F*)DiMudRCanvash750a5->GetPrimitive("DiMudR");
  TH1F *DiMuPhih750a5_ = (TH1F*)DiMuPhiCanvash750a5->GetPrimitive("DiMuPhi");
  TH1F *EtMETh750a5_ = (TH1F*)EtMETCanvash750a5->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a5_ = (TH1F*)DiTauDiMuMassCanvash750a5->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a5_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a5->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a5_ = (TH1F*)METDiMuDeltaPhiCanvash750a5->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a5_ = (TH1F*)METDiMuDeltaPhiCanvash750a5->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a5_ = (TH1F*)DiTaudRCanvash750a5->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a5_ = (TH1F*)DiTauMassSmallerdRCanvash750a5->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth750a5_ = (TH1F*)HighestCSVInclJetCanvash750a5->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h750a7
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a7_ = (TH1F*)NMedIsoTausWithMu3Canvash750a7->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a7_ = (TH1F*)InvMassTauHadMu3Canvash750a7->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a7_ = (TH1F*)PtTauHadMu3Canvash750a7->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh750a7_ = (TH1F*)InvMassUpsilonRangeCanvash750a7->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh750a7_ = (TH1F*)InvMassZPeakRangeCanvash750a7->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh750a7_ = (TH1F*)InvMassFullRangeCanvash750a7->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a7_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a7->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a7_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a7->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a7_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a7->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a7_ = (TH1F*)Mu1PtCanvash750a7->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a7_ = (TH1F*)Mu2PtCanvash750a7->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a7_ = (TH1F*)DiMuPtCanvash750a7->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah750a7_ = (TH1F*)Mu1EtaCanvash750a7->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah750a7_ = (TH1F*)Mu2EtaCanvash750a7->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah750a7_ = (TH1F*)DiTauEtaCanvash750a7->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a7_ = (TH1F*)DiTauPhiCanvash750a7->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a7_ = (TH1F*)DiMuEtaCanvash750a7->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a7_ = (TH1F*)DiMudRCanvash750a7->GetPrimitive("DiMudR");
  TH1F *DiMuPhih750a7_ = (TH1F*)DiMuPhiCanvash750a7->GetPrimitive("DiMuPhi");
  TH1F *EtMETh750a7_ = (TH1F*)EtMETCanvash750a7->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a7_ = (TH1F*)DiTauDiMuMassCanvash750a7->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a7_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a7->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a7_ = (TH1F*)METDiMuDeltaPhiCanvash750a7->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a7_ = (TH1F*)METDiMuDeltaPhiCanvash750a7->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a7_ = (TH1F*)DiTaudRCanvash750a7->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a7_ = (TH1F*)DiTauMassSmallerdRCanvash750a7->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth750a7_ = (TH1F*)HighestCSVInclJetCanvash750a7->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // h750a9
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a9_ = (TH1F*)NMedIsoTausWithMu3Canvash750a9->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a9_ = (TH1F*)InvMassTauHadMu3Canvash750a9->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a9_ = (TH1F*)PtTauHadMu3Canvash750a9->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeh750a9_ = (TH1F*)InvMassUpsilonRangeCanvash750a9->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeh750a9_ = (TH1F*)InvMassZPeakRangeCanvash750a9->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeh750a9_ = (TH1F*)InvMassFullRangeCanvash750a9->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a9_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a9->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a9_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a9->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a9_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a9->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a9_ = (TH1F*)Mu1PtCanvash750a9->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a9_ = (TH1F*)Mu2PtCanvash750a9->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a9_ = (TH1F*)DiMuPtCanvash750a9->GetPrimitive("DiMuPt");
  TH1F *Mu1Etah750a9_ = (TH1F*)Mu1EtaCanvash750a9->GetPrimitive("Mu1Eta");
  TH1F *Mu2Etah750a9_ = (TH1F*)Mu2EtaCanvash750a9->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtah750a9_ = (TH1F*)DiTauEtaCanvash750a9->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a9_ = (TH1F*)DiTauPhiCanvash750a9->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a9_ = (TH1F*)DiMuEtaCanvash750a9->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a9_ = (TH1F*)DiMudRCanvash750a9->GetPrimitive("DiMudR");
  TH1F *DiMuPhih750a9_ = (TH1F*)DiMuPhiCanvash750a9->GetPrimitive("DiMuPhi");
  TH1F *EtMETh750a9_ = (TH1F*)EtMETCanvash750a9->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a9_ = (TH1F*)DiTauDiMuMassCanvash750a9->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a9_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a9->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a9_ = (TH1F*)METDiMuDeltaPhiCanvash750a9->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a9_ = (TH1F*)METDiMuDeltaPhiCanvash750a9->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a9_ = (TH1F*)DiTaudRCanvash750a9->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a9_ = (TH1F*)DiTauMassSmallerdRCanvash750a9->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth750a9_ = (TH1F*)HighestCSVInclJetCanvash750a9->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // Data1
  ////////////////
  TH1F *NMedIsoTausWithMu3Data1_ = (TH1F*)NMedIsoTausWithMu3CanvasData1->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3Data1_ = (TH1F*)InvMassTauHadMu3CanvasData1->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3Data1_ = (TH1F*)PtTauHadMu3CanvasData1->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeData1_ = (TH1F*)InvMassUpsilonRangeCanvasData1->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeData1_ = (TH1F*)InvMassZPeakRangeCanvasData1->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeData1_ = (TH1F*)InvMassFullRangeCanvasData1->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrData1_ = (TH1F*)InvMassDiMuBarrBarrCanvasData1->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcData1_ = (TH1F*)InvMassDiMuBarrEndcCanvasData1->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcData1_ = (TH1F*)InvMassDiMuEndcEndcCanvasData1->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtData1_ = (TH1F*)Mu1PtCanvasData1->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtData1_ = (TH1F*)Mu2PtCanvasData1->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtData1_ = (TH1F*)DiMuPtCanvasData1->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaData1_ = (TH1F*)Mu1EtaCanvasData1->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaData1_ = (TH1F*)Mu2EtaCanvasData1->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaData1_ = (TH1F*)DiTauEtaCanvasData1->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiData1_ = (TH1F*)DiTauPhiCanvasData1->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaData1_ = (TH1F*)DiMuEtaCanvasData1->GetPrimitive("DiMuEta");
  TH1F *DiMudRData1_ = (TH1F*)DiMudRCanvasData1->GetPrimitive("DiMudR");
  TH1F *DiMuPhiData1_ = (TH1F*)DiMuPhiCanvasData1->GetPrimitive("DiMuPhi");
  TH1F *EtMETData1_ = (TH1F*)EtMETCanvasData1->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassData1_ = (TH1F*)DiTauDiMuMassCanvasData1->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiData1_ = (TH1F*)DiMuDiTauDeltaPhiCanvasData1->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiData1_ = (TH1F*)METDiMuDeltaPhiCanvasData1->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiData1_ = (TH1F*)METDiMuDeltaPhiCanvasData1->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRData1_ = (TH1F*)DiTaudRCanvasData1->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRData1_ = (TH1F*)DiTauMassSmallerdRCanvasData1->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetData1_ = (TH1F*)HighestCSVInclJetCanvasData1->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // Data2
  ////////////////
  TH1F *NMedIsoTausWithMu3Data2_ = (TH1F*)NMedIsoTausWithMu3CanvasData2->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3Data2_ = (TH1F*)InvMassTauHadMu3CanvasData2->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3Data2_ = (TH1F*)PtTauHadMu3CanvasData2->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeData2_ = (TH1F*)InvMassUpsilonRangeCanvasData2->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeData2_ = (TH1F*)InvMassZPeakRangeCanvasData2->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeData2_ = (TH1F*)InvMassFullRangeCanvasData2->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrData2_ = (TH1F*)InvMassDiMuBarrBarrCanvasData2->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcData2_ = (TH1F*)InvMassDiMuBarrEndcCanvasData2->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcData2_ = (TH1F*)InvMassDiMuEndcEndcCanvasData2->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtData2_ = (TH1F*)Mu1PtCanvasData2->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtData2_ = (TH1F*)Mu2PtCanvasData2->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtData2_ = (TH1F*)DiMuPtCanvasData2->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaData2_ = (TH1F*)Mu1EtaCanvasData2->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaData2_ = (TH1F*)Mu2EtaCanvasData2->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaData2_ = (TH1F*)DiTauEtaCanvasData2->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiData2_ = (TH1F*)DiTauPhiCanvasData2->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaData2_ = (TH1F*)DiMuEtaCanvasData2->GetPrimitive("DiMuEta");
  TH1F *DiMudRData2_ = (TH1F*)DiMudRCanvasData2->GetPrimitive("DiMudR");
  TH1F *DiMuPhiData2_ = (TH1F*)DiMuPhiCanvasData2->GetPrimitive("DiMuPhi");
  TH1F *EtMETData2_ = (TH1F*)EtMETCanvasData2->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassData2_ = (TH1F*)DiTauDiMuMassCanvasData2->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiData2_ = (TH1F*)DiMuDiTauDeltaPhiCanvasData2->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiData2_ = (TH1F*)METDiMuDeltaPhiCanvasData2->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiData2_ = (TH1F*)METDiMuDeltaPhiCanvasData2->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRData2_ = (TH1F*)DiTaudRCanvasData2->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRData2_ = (TH1F*)DiTauMassSmallerdRCanvasData2->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetData2_ = (TH1F*)HighestCSVInclJetCanvasData2->GetPrimitive("HighestCSVInclJet");

//  ////////////////
//  // TTDiLep
//  ////////////////
//  TH1F *NMedIsoTausWithMu3TTDiLep_ = (TH1F*)NMedIsoTausWithMu3CanvasTTDiLep->GetPrimitive("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3TTDiLep_ = (TH1F*)InvMassTauHadMu3CanvasTTDiLep->GetPrimitive("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3TTDiLep_ = (TH1F*)PtTauHadMu3CanvasTTDiLep->GetPrimitive("PtTauHadMu3");
//  TH1F *InvMassUpsilonRangeTTDiLep_ = (TH1F*)InvMassUpsilonRangeCanvasTTDiLep->GetPrimitive("InvMassUpsilonRange");
//  TH1F *InvMassZPeakRangeTTDiLep_ = (TH1F*)InvMassZPeakRangeCanvasTTDiLep->GetPrimitive("InvMassZPeakRange");
//  TH1F *InvMassFullRangeTTDiLep_ = (TH1F*)InvMassFullRangeCanvasTTDiLep->GetPrimitive("InvMassFullRange");
//  TH1F *InvMassDiMuBarrBarrTTDiLep_ = (TH1F*)InvMassDiMuBarrBarrCanvasTTDiLep->GetPrimitive("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcTTDiLep_ = (TH1F*)InvMassDiMuBarrEndcCanvasTTDiLep->GetPrimitive("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcTTDiLep_ = (TH1F*)InvMassDiMuEndcEndcCanvasTTDiLep->GetPrimitive("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtTTDiLep_ = (TH1F*)Mu1PtCanvasTTDiLep->GetPrimitive("Mu1Pt");
//  TH1F *Mu2PtTTDiLep_ = (TH1F*)Mu2PtCanvasTTDiLep->GetPrimitive("Mu2Pt");
//  TH1F *DiMuPtTTDiLep_ = (TH1F*)DiMuPtCanvasTTDiLep->GetPrimitive("DiMuPt");
//  TH1F *Mu1EtaTTDiLep_ = (TH1F*)Mu1EtaCanvasTTDiLep->GetPrimitive("Mu1Eta");
//  TH1F *Mu2EtaTTDiLep_ = (TH1F*)Mu2EtaCanvasTTDiLep->GetPrimitive("Mu2Eta");
//  TH1F *DiTauEtaTTDiLep_ = (TH1F*)DiTauEtaCanvasTTDiLep->GetPrimitive("DiTauEta");
//  TH1F *DiTauPhiTTDiLep_ = (TH1F*)DiTauPhiCanvasTTDiLep->GetPrimitive("DiTauPhi");
//  TH1F *DiMuEtaTTDiLep_ = (TH1F*)DiMuEtaCanvasTTDiLep->GetPrimitive("DiMuEta");
//  TH1F *DiMudRTTDiLep_ = (TH1F*)DiMudRCanvasTTDiLep->GetPrimitive("DiMudR");
//  TH1F *DiMuPhiTTDiLep_ = (TH1F*)DiMuPhiCanvasTTDiLep->GetPrimitive("DiMuPhi");
//  TH1F *EtMETTTDiLep_ = (TH1F*)EtMETCanvasTTDiLep->GetPrimitive("EtMET");
//  TH1F *DiTauDiMuMassTTDiLep_ = (TH1F*)DiTauDiMuMassCanvasTTDiLep->GetPrimitive("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiTTDiLep_ = (TH1F*)DiMuDiTauDeltaPhiCanvasTTDiLep->GetPrimitive("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiTTDiLep_ = (TH1F*)METDiMuDeltaPhiCanvasTTDiLep->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiTTDiLep_ = (TH1F*)METDiMuDeltaPhiCanvasTTDiLep->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *DiTaudRTTDiLep_ = (TH1F*)DiTaudRCanvasTTDiLep->GetPrimitive("DiTaudR");
//  TH1F *DiTauMassSmallerdRTTDiLep_ = (TH1F*)DiTauMassSmallerdRCanvasTTDiLep->GetPrimitive("DiTauMassSmallerdR");
//  TH1F *HighestCSVInclJetTTDiLep_ = (TH1F*)HighestCSVInclJetCanvasTTDiLep->GetPrimitive("HighestCSVInclJet");
//
//  ////////////////
//  // TTSingLep
//  ////////////////
//  TH1F *NMedIsoTausWithMu3TTSingLep_ = (TH1F*)NMedIsoTausWithMu3CanvasTTSingLep->GetPrimitive("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3TTSingLep_ = (TH1F*)InvMassTauHadMu3CanvasTTSingLep->GetPrimitive("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3TTSingLep_ = (TH1F*)PtTauHadMu3CanvasTTSingLep->GetPrimitive("PtTauHadMu3");
//  TH1F *InvMassUpsilonRangeTTSingLep_ = (TH1F*)InvMassUpsilonRangeCanvasTTSingLep->GetPrimitive("InvMassUpsilonRange");
//  TH1F *InvMassZPeakRangeTTSingLep_ = (TH1F*)InvMassZPeakRangeCanvasTTSingLep->GetPrimitive("InvMassZPeakRange");
//  TH1F *InvMassFullRangeTTSingLep_ = (TH1F*)InvMassFullRangeCanvasTTSingLep->GetPrimitive("InvMassFullRange");
//  TH1F *InvMassDiMuBarrBarrTTSingLep_ = (TH1F*)InvMassDiMuBarrBarrCanvasTTSingLep->GetPrimitive("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcTTSingLep_ = (TH1F*)InvMassDiMuBarrEndcCanvasTTSingLep->GetPrimitive("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcTTSingLep_ = (TH1F*)InvMassDiMuEndcEndcCanvasTTSingLep->GetPrimitive("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtTTSingLep_ = (TH1F*)Mu1PtCanvasTTSingLep->GetPrimitive("Mu1Pt");
//  TH1F *Mu2PtTTSingLep_ = (TH1F*)Mu2PtCanvasTTSingLep->GetPrimitive("Mu2Pt");
//  TH1F *DiMuPtTTSingLep_ = (TH1F*)DiMuPtCanvasTTSingLep->GetPrimitive("DiMuPt");
//  TH1F *Mu1EtaTTSingLep_ = (TH1F*)Mu1EtaCanvasTTSingLep->GetPrimitive("Mu1Eta");
//  TH1F *Mu2EtaTTSingLep_ = (TH1F*)Mu2EtaCanvasTTSingLep->GetPrimitive("Mu2Eta");
//  TH1F *DiTauEtaTTSingLep_ = (TH1F*)DiTauEtaCanvasTTSingLep->GetPrimitive("DiTauEta");
//  TH1F *DiTauPhiTTSingLep_ = (TH1F*)DiTauPhiCanvasTTSingLep->GetPrimitive("DiTauPhi");
//  TH1F *DiMuEtaTTSingLep_ = (TH1F*)DiMuEtaCanvasTTSingLep->GetPrimitive("DiMuEta");
//  TH1F *DiMudRTTSingLep_ = (TH1F*)DiMudRCanvasTTSingLep->GetPrimitive("DiMudR");
//  TH1F *DiMuPhiTTSingLep_ = (TH1F*)DiMuPhiCanvasTTSingLep->GetPrimitive("DiMuPhi");
//  TH1F *EtMETTTSingLep_ = (TH1F*)EtMETCanvasTTSingLep->GetPrimitive("EtMET");
//  TH1F *DiTauDiMuMassTTSingLep_ = (TH1F*)DiTauDiMuMassCanvasTTSingLep->GetPrimitive("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiTTSingLep_ = (TH1F*)DiMuDiTauDeltaPhiCanvasTTSingLep->GetPrimitive("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiTTSingLep_ = (TH1F*)METDiMuDeltaPhiCanvasTTSingLep->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiTTSingLep_ = (TH1F*)METDiMuDeltaPhiCanvasTTSingLep->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *DiTaudRTTSingLep_ = (TH1F*)DiTaudRCanvasTTSingLep->GetPrimitive("DiTaudR");
//  TH1F *DiTauMassSmallerdRTTSingLep_ = (TH1F*)DiTauMassSmallerdRCanvasTTSingLep->GetPrimitive("DiTauMassSmallerdR");
//  TH1F *HighestCSVInclJetTTSingLep_ = (TH1F*)HighestCSVInclJetCanvasTTSingLep->GetPrimitive("HighestCSVInclJet");
//
//  ////////////////
//  // TTBarSingLep
//  ////////////////
//  TH1F *NMedIsoTausWithMu3TTBarSingLep_ = (TH1F*)NMedIsoTausWithMu3CanvasTTBarSingLep->GetPrimitive("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3TTBarSingLep_ = (TH1F*)InvMassTauHadMu3CanvasTTBarSingLep->GetPrimitive("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3TTBarSingLep_ = (TH1F*)PtTauHadMu3CanvasTTBarSingLep->GetPrimitive("PtTauHadMu3");
//  TH1F *InvMassUpsilonRangeTTBarSingLep_ = (TH1F*)InvMassUpsilonRangeCanvasTTBarSingLep->GetPrimitive("InvMassUpsilonRange");
//  TH1F *InvMassZPeakRangeTTBarSingLep_ = (TH1F*)InvMassZPeakRangeCanvasTTBarSingLep->GetPrimitive("InvMassZPeakRange");
//  TH1F *InvMassFullRangeTTBarSingLep_ = (TH1F*)InvMassFullRangeCanvasTTBarSingLep->GetPrimitive("InvMassFullRange");
//  TH1F *InvMassDiMuBarrBarrTTBarSingLep_ = (TH1F*)InvMassDiMuBarrBarrCanvasTTBarSingLep->GetPrimitive("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcTTBarSingLep_ = (TH1F*)InvMassDiMuBarrEndcCanvasTTBarSingLep->GetPrimitive("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcTTBarSingLep_ = (TH1F*)InvMassDiMuEndcEndcCanvasTTBarSingLep->GetPrimitive("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtTTBarSingLep_ = (TH1F*)Mu1PtCanvasTTBarSingLep->GetPrimitive("Mu1Pt");
//  TH1F *Mu2PtTTBarSingLep_ = (TH1F*)Mu2PtCanvasTTBarSingLep->GetPrimitive("Mu2Pt");
//  TH1F *DiMuPtTTBarSingLep_ = (TH1F*)DiMuPtCanvasTTBarSingLep->GetPrimitive("DiMuPt");
//  TH1F *Mu1EtaTTBarSingLep_ = (TH1F*)Mu1EtaCanvasTTBarSingLep->GetPrimitive("Mu1Eta");
//  TH1F *Mu2EtaTTBarSingLep_ = (TH1F*)Mu2EtaCanvasTTBarSingLep->GetPrimitive("Mu2Eta");
//  TH1F *DiTauEtaTTBarSingLep_ = (TH1F*)DiTauEtaCanvasTTBarSingLep->GetPrimitive("DiTauEta");
//  TH1F *DiTauPhiTTBarSingLep_ = (TH1F*)DiTauPhiCanvasTTBarSingLep->GetPrimitive("DiTauPhi");
//  TH1F *DiMuEtaTTBarSingLep_ = (TH1F*)DiMuEtaCanvasTTBarSingLep->GetPrimitive("DiMuEta");
//  TH1F *DiMudRTTBarSingLep_ = (TH1F*)DiMudRCanvasTTBarSingLep->GetPrimitive("DiMudR");
//  TH1F *DiMuPhiTTBarSingLep_ = (TH1F*)DiMuPhiCanvasTTBarSingLep->GetPrimitive("DiMuPhi");
//  TH1F *EtMETTTBarSingLep_ = (TH1F*)EtMETCanvasTTBarSingLep->GetPrimitive("EtMET");
//  TH1F *DiTauDiMuMassTTBarSingLep_ = (TH1F*)DiTauDiMuMassCanvasTTBarSingLep->GetPrimitive("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiTTBarSingLep_ = (TH1F*)DiMuDiTauDeltaPhiCanvasTTBarSingLep->GetPrimitive("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiTTBarSingLep_ = (TH1F*)METDiMuDeltaPhiCanvasTTBarSingLep->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiTTBarSingLep_ = (TH1F*)METDiMuDeltaPhiCanvasTTBarSingLep->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *DiTaudRTTBarSingLep_ = (TH1F*)DiTaudRCanvasTTBarSingLep->GetPrimitive("DiTaudR");
//  TH1F *DiTauMassSmallerdRTTBarSingLep_ = (TH1F*)DiTauMassSmallerdRCanvasTTBarSingLep->GetPrimitive("DiTauMassSmallerdR");
//  TH1F *HighestCSVInclJetTTBarSingLep_ = (TH1F*)HighestCSVInclJetCanvasTTBarSingLep->GetPrimitive("HighestCSVInclJet");
//
//  ////////////////
//  // TTJetsMad
//  ////////////////
//  TH1F *NMedIsoTausWithMu3TTJetsMad_ = (TH1F*)NMedIsoTausWithMu3CanvasTTJetsMad->GetPrimitive("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3TTJetsMad_ = (TH1F*)InvMassTauHadMu3CanvasTTJetsMad->GetPrimitive("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3TTJetsMad_ = (TH1F*)PtTauHadMu3CanvasTTJetsMad->GetPrimitive("PtTauHadMu3");
//  TH1F *InvMassUpsilonRangeTTJetsMad_ = (TH1F*)InvMassUpsilonRangeCanvasTTJetsMad->GetPrimitive("InvMassUpsilonRange");
//  TH1F *InvMassZPeakRangeTTJetsMad_ = (TH1F*)InvMassZPeakRangeCanvasTTJetsMad->GetPrimitive("InvMassZPeakRange");
//  TH1F *InvMassFullRangeTTJetsMad_ = (TH1F*)InvMassFullRangeCanvasTTJetsMad->GetPrimitive("InvMassFullRange");
//  TH1F *InvMassDiMuBarrBarrTTJetsMad_ = (TH1F*)InvMassDiMuBarrBarrCanvasTTJetsMad->GetPrimitive("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcTTJetsMad_ = (TH1F*)InvMassDiMuBarrEndcCanvasTTJetsMad->GetPrimitive("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcTTJetsMad_ = (TH1F*)InvMassDiMuEndcEndcCanvasTTJetsMad->GetPrimitive("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtTTJetsMad_ = (TH1F*)Mu1PtCanvasTTJetsMad->GetPrimitive("Mu1Pt");
//  TH1F *Mu2PtTTJetsMad_ = (TH1F*)Mu2PtCanvasTTJetsMad->GetPrimitive("Mu2Pt");
//  TH1F *DiMuPtTTJetsMad_ = (TH1F*)DiMuPtCanvasTTJetsMad->GetPrimitive("DiMuPt");
//  TH1F *Mu1EtaTTJetsMad_ = (TH1F*)Mu1EtaCanvasTTJetsMad->GetPrimitive("Mu1Eta");
//  TH1F *Mu2EtaTTJetsMad_ = (TH1F*)Mu2EtaCanvasTTJetsMad->GetPrimitive("Mu2Eta");
//  TH1F *DiTauEtaTTJetsMad_ = (TH1F*)DiTauEtaCanvasTTJetsMad->GetPrimitive("DiTauEta");
//  TH1F *DiTauPhiTTJetsMad_ = (TH1F*)DiTauPhiCanvasTTJetsMad->GetPrimitive("DiTauPhi");
//  TH1F *DiMuEtaTTJetsMad_ = (TH1F*)DiMuEtaCanvasTTJetsMad->GetPrimitive("DiMuEta");
//  TH1F *DiMudRTTJetsMad_ = (TH1F*)DiMudRCanvasTTJetsMad->GetPrimitive("DiMudR");
//  TH1F *DiMuPhiTTJetsMad_ = (TH1F*)DiMuPhiCanvasTTJetsMad->GetPrimitive("DiMuPhi");
//  TH1F *EtMETTTJetsMad_ = (TH1F*)EtMETCanvasTTJetsMad->GetPrimitive("EtMET");
//  TH1F *DiTauDiMuMassTTJetsMad_ = (TH1F*)DiTauDiMuMassCanvasTTJetsMad->GetPrimitive("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiTTJetsMad_ = (TH1F*)DiMuDiTauDeltaPhiCanvasTTJetsMad->GetPrimitive("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiTTJetsMad_ = (TH1F*)METDiMuDeltaPhiCanvasTTJetsMad->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiTTJetsMad_ = (TH1F*)METDiMuDeltaPhiCanvasTTJetsMad->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *DiTaudRTTJetsMad_ = (TH1F*)DiTaudRCanvasTTJetsMad->GetPrimitive("DiTaudR");
//  TH1F *DiTauMassSmallerdRTTJetsMad_ = (TH1F*)DiTauMassSmallerdRCanvasTTJetsMad->GetPrimitive("DiTauMassSmallerdR");
//  TH1F *HighestCSVInclJetTTJetsMad_ = (TH1F*)HighestCSVInclJetCanvasTTJetsMad->GetPrimitive("HighestCSVInclJet");
//
//  ////////////////
//  // TTJetsAmac
//  ////////////////
//  TH1F *NMedIsoTausWithMu3TTJetsAmac_ = (TH1F*)NMedIsoTausWithMu3CanvasTTJetsAmac->GetPrimitive("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3TTJetsAmac_ = (TH1F*)InvMassTauHadMu3CanvasTTJetsAmac->GetPrimitive("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3TTJetsAmac_ = (TH1F*)PtTauHadMu3CanvasTTJetsAmac->GetPrimitive("PtTauHadMu3");
//  TH1F *InvMassUpsilonRangeTTJetsAmac_ = (TH1F*)InvMassUpsilonRangeCanvasTTJetsAmac->GetPrimitive("InvMassUpsilonRange");
//  TH1F *InvMassZPeakRangeTTJetsAmac_ = (TH1F*)InvMassZPeakRangeCanvasTTJetsAmac->GetPrimitive("InvMassZPeakRange");
//  TH1F *InvMassFullRangeTTJetsAmac_ = (TH1F*)InvMassFullRangeCanvasTTJetsAmac->GetPrimitive("InvMassFullRange");
//  TH1F *InvMassDiMuBarrBarrTTJetsAmac_ = (TH1F*)InvMassDiMuBarrBarrCanvasTTJetsAmac->GetPrimitive("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcTTJetsAmac_ = (TH1F*)InvMassDiMuBarrEndcCanvasTTJetsAmac->GetPrimitive("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcTTJetsAmac_ = (TH1F*)InvMassDiMuEndcEndcCanvasTTJetsAmac->GetPrimitive("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtTTJetsAmac_ = (TH1F*)Mu1PtCanvasTTJetsAmac->GetPrimitive("Mu1Pt");
//  TH1F *Mu2PtTTJetsAmac_ = (TH1F*)Mu2PtCanvasTTJetsAmac->GetPrimitive("Mu2Pt");
//  TH1F *DiMuPtTTJetsAmac_ = (TH1F*)DiMuPtCanvasTTJetsAmac->GetPrimitive("DiMuPt");
//  TH1F *Mu1EtaTTJetsAmac_ = (TH1F*)Mu1EtaCanvasTTJetsAmac->GetPrimitive("Mu1Eta");
//  TH1F *Mu2EtaTTJetsAmac_ = (TH1F*)Mu2EtaCanvasTTJetsAmac->GetPrimitive("Mu2Eta");
//  TH1F *DiTauEtaTTJetsAmac_ = (TH1F*)DiTauEtaCanvasTTJetsAmac->GetPrimitive("DiTauEta");
//  TH1F *DiTauPhiTTJetsAmac_ = (TH1F*)DiTauPhiCanvasTTJetsAmac->GetPrimitive("DiTauPhi");
//  TH1F *DiMuEtaTTJetsAmac_ = (TH1F*)DiMuEtaCanvasTTJetsAmac->GetPrimitive("DiMuEta");
//  TH1F *DiMudRTTJetsAmac_ = (TH1F*)DiMudRCanvasTTJetsAmac->GetPrimitive("DiMudR");
//  TH1F *DiMuPhiTTJetsAmac_ = (TH1F*)DiMuPhiCanvasTTJetsAmac->GetPrimitive("DiMuPhi");
//  TH1F *EtMETTTJetsAmac_ = (TH1F*)EtMETCanvasTTJetsAmac->GetPrimitive("EtMET");
//  TH1F *DiTauDiMuMassTTJetsAmac_ = (TH1F*)DiTauDiMuMassCanvasTTJetsAmac->GetPrimitive("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiTTJetsAmac_ = (TH1F*)DiMuDiTauDeltaPhiCanvasTTJetsAmac->GetPrimitive("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiTTJetsAmac_ = (TH1F*)METDiMuDeltaPhiCanvasTTJetsAmac->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiTTJetsAmac_ = (TH1F*)METDiMuDeltaPhiCanvasTTJetsAmac->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *DiTaudRTTJetsAmac_ = (TH1F*)DiTaudRCanvasTTJetsAmac->GetPrimitive("DiTaudR");
//  TH1F *DiTauMassSmallerdRTTJetsAmac_ = (TH1F*)DiTauMassSmallerdRCanvasTTJetsAmac->GetPrimitive("DiTauMassSmallerdR");
//  TH1F *HighestCSVInclJetTTJetsAmac_ = (TH1F*)HighestCSVInclJetCanvasTTJetsAmac->GetPrimitive("HighestCSVInclJet");
//
//  ////////////////
//  // Up
//  ////////////////
//  TH1F *NMedIsoTausWithMu3Up_ = (TH1F*)NMedIsoTausWithMu3CanvasUp->GetPrimitive("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3Up_ = (TH1F*)InvMassTauHadMu3CanvasUp->GetPrimitive("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3Up_ = (TH1F*)PtTauHadMu3CanvasUp->GetPrimitive("PtTauHadMu3");
//  TH1F *InvMassUpsilonRangeUp_ = (TH1F*)InvMassUpsilonRangeCanvasUp->GetPrimitive("InvMassUpsilonRange");
//  TH1F *InvMassZPeakRangeUp_ = (TH1F*)InvMassZPeakRangeCanvasUp->GetPrimitive("InvMassZPeakRange");
//  TH1F *InvMassFullRangeUp_ = (TH1F*)InvMassFullRangeCanvasUp->GetPrimitive("InvMassFullRange");
//  TH1F *InvMassDiMuBarrBarrUp_ = (TH1F*)InvMassDiMuBarrBarrCanvasUp->GetPrimitive("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcUp_ = (TH1F*)InvMassDiMuBarrEndcCanvasUp->GetPrimitive("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcUp_ = (TH1F*)InvMassDiMuEndcEndcCanvasUp->GetPrimitive("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtUp_ = (TH1F*)Mu1PtCanvasUp->GetPrimitive("Mu1Pt");
//  TH1F *Mu2PtUp_ = (TH1F*)Mu2PtCanvasUp->GetPrimitive("Mu2Pt");
//  TH1F *DiMuPtUp_ = (TH1F*)DiMuPtCanvasUp->GetPrimitive("DiMuPt");
//  TH1F *Mu1EtaUp_ = (TH1F*)Mu1EtaCanvasUp->GetPrimitive("Mu1Eta");
//  TH1F *Mu2EtaUp_ = (TH1F*)Mu2EtaCanvasUp->GetPrimitive("Mu2Eta");
//  TH1F *DiTauEtaUp_ = (TH1F*)DiTauEtaCanvasUp->GetPrimitive("DiTauEta");
//  TH1F *DiTauPhiUp_ = (TH1F*)DiTauPhiCanvasUp->GetPrimitive("DiTauPhi");
//  TH1F *DiMuEtaUp_ = (TH1F*)DiMuEtaCanvasUp->GetPrimitive("DiMuEta");
//  TH1F *DiMudRUp_ = (TH1F*)DiMudRCanvasUp->GetPrimitive("DiMudR");
//  TH1F *DiMuPhiUp_ = (TH1F*)DiMuPhiCanvasUp->GetPrimitive("DiMuPhi");
//  TH1F *EtMETUp_ = (TH1F*)EtMETCanvasUp->GetPrimitive("EtMET");
//  TH1F *DiTauDiMuMassUp_ = (TH1F*)DiTauDiMuMassCanvasUp->GetPrimitive("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiUp_ = (TH1F*)DiMuDiTauDeltaPhiCanvasUp->GetPrimitive("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiUp_ = (TH1F*)METDiMuDeltaPhiCanvasUp->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiUp_ = (TH1F*)METDiMuDeltaPhiCanvasUp->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *DiTaudRUp_ = (TH1F*)DiTaudRCanvasUp->GetPrimitive("DiTaudR");
//  TH1F *DiTauMassSmallerdRUp_ = (TH1F*)DiTauMassSmallerdRCanvasUp->GetPrimitive("DiTauMassSmallerdR");
//  TH1F *HighestCSVInclJetUp_ = (TH1F*)HighestCSVInclJetCanvasUp->GetPrimitive("HighestCSVInclJet");
//
//  ////////////////
//  // VV
  ////////////////
//  TH1F *NMedIsoTausWithMu3VV_ = (TH1F*)NMedIsoTausWithMu3CanvasVV->GetPrimitive("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3VV_ = (TH1F*)InvMassTauHadMu3CanvasVV->GetPrimitive("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3VV_ = (TH1F*)PtTauHadMu3CanvasVV->GetPrimitive("PtTauHadMu3");
//  TH1F *InvMassUpsilonRangeVV_ = (TH1F*)InvMassUpsilonRangeCanvasVV->GetPrimitive("InvMassUpsilonRange");
//  TH1F *InvMassZPeakRangeVV_ = (TH1F*)InvMassZPeakRangeCanvasVV->GetPrimitive("InvMassZPeakRange");
//  TH1F *InvMassFullRangeVV_ = (TH1F*)InvMassFullRangeCanvasVV->GetPrimitive("InvMassFullRange");
//  TH1F *InvMassDiMuBarrBarrVV_ = (TH1F*)InvMassDiMuBarrBarrCanvasVV->GetPrimitive("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcVV_ = (TH1F*)InvMassDiMuBarrEndcCanvasVV->GetPrimitive("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcVV_ = (TH1F*)InvMassDiMuEndcEndcCanvasVV->GetPrimitive("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtVV_ = (TH1F*)Mu1PtCanvasVV->GetPrimitive("Mu1Pt");
//  TH1F *Mu2PtVV_ = (TH1F*)Mu2PtCanvasVV->GetPrimitive("Mu2Pt");
//  TH1F *DiMuPtVV_ = (TH1F*)DiMuPtCanvasVV->GetPrimitive("DiMuPt");
//  TH1F *Mu1EtaVV_ = (TH1F*)Mu1EtaCanvasVV->GetPrimitive("Mu1Eta");
//  TH1F *Mu2EtaVV_ = (TH1F*)Mu2EtaCanvasVV->GetPrimitive("Mu2Eta");
//  TH1F *DiTauEtaVV_ = (TH1F*)DiTauEtaCanvasVV->GetPrimitive("DiTauEta");
//  TH1F *DiTauPhiVV_ = (TH1F*)DiTauPhiCanvasVV->GetPrimitive("DiTauPhi");
//  TH1F *DiMuEtaVV_ = (TH1F*)DiMuEtaCanvasVV->GetPrimitive("DiMuEta");
//  TH1F *DiMudRVV_ = (TH1F*)DiMudRCanvasVV->GetPrimitive("DiMudR");
//  TH1F *DiMuPhiVV_ = (TH1F*)DiMuPhiCanvasVV->GetPrimitive("DiMuPhi");
//  TH1F *EtMETVV_ = (TH1F*)EtMETCanvasVV->GetPrimitive("EtMET");
//  TH1F *DiTauDiMuMassVV_ = (TH1F*)DiTauDiMuMassCanvasVV->GetPrimitive("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiVV_ = (TH1F*)DiMuDiTauDeltaPhiCanvasVV->GetPrimitive("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiVV_ = (TH1F*)METDiMuDeltaPhiCanvasVV->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiVV_ = (TH1F*)METDiMuDeltaPhiCanvasVV->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *DiTaudRVV_ = (TH1F*)DiTaudRCanvasVV->GetPrimitive("DiTaudR");
//  TH1F *DiTauMassSmallerdRVV_ = (TH1F*)DiTauMassSmallerdRCanvasVV->GetPrimitive("DiTauMassSmallerdR");
//  TH1F *HighestCSVInclJetVV_ = (TH1F*)HighestCSVInclJetCanvasVV->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // WJAmac
  ////////////////
  TH1F *NMedIsoTausWithMu3WJAmac_ = (TH1F*)NMedIsoTausWithMu3CanvasWJAmac->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3WJAmac_ = (TH1F*)InvMassTauHadMu3CanvasWJAmac->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3WJAmac_ = (TH1F*)PtTauHadMu3CanvasWJAmac->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeWJAmac_ = (TH1F*)InvMassUpsilonRangeCanvasWJAmac->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeWJAmac_ = (TH1F*)InvMassZPeakRangeCanvasWJAmac->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeWJAmac_ = (TH1F*)InvMassFullRangeCanvasWJAmac->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrWJAmac_ = (TH1F*)InvMassDiMuBarrBarrCanvasWJAmac->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcWJAmac_ = (TH1F*)InvMassDiMuBarrEndcCanvasWJAmac->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcWJAmac_ = (TH1F*)InvMassDiMuEndcEndcCanvasWJAmac->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtWJAmac_ = (TH1F*)Mu1PtCanvasWJAmac->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtWJAmac_ = (TH1F*)Mu2PtCanvasWJAmac->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtWJAmac_ = (TH1F*)DiMuPtCanvasWJAmac->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaWJAmac_ = (TH1F*)Mu1EtaCanvasWJAmac->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaWJAmac_ = (TH1F*)Mu2EtaCanvasWJAmac->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaWJAmac_ = (TH1F*)DiTauEtaCanvasWJAmac->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiWJAmac_ = (TH1F*)DiTauPhiCanvasWJAmac->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaWJAmac_ = (TH1F*)DiMuEtaCanvasWJAmac->GetPrimitive("DiMuEta");
  TH1F *DiMudRWJAmac_ = (TH1F*)DiMudRCanvasWJAmac->GetPrimitive("DiMudR");
  TH1F *DiMuPhiWJAmac_ = (TH1F*)DiMuPhiCanvasWJAmac->GetPrimitive("DiMuPhi");
  TH1F *EtMETWJAmac_ = (TH1F*)EtMETCanvasWJAmac->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassWJAmac_ = (TH1F*)DiTauDiMuMassCanvasWJAmac->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiWJAmac_ = (TH1F*)DiMuDiTauDeltaPhiCanvasWJAmac->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiWJAmac_ = (TH1F*)METDiMuDeltaPhiCanvasWJAmac->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiWJAmac_ = (TH1F*)METDiMuDeltaPhiCanvasWJAmac->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRWJAmac_ = (TH1F*)DiTaudRCanvasWJAmac->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRWJAmac_ = (TH1F*)DiTauMassSmallerdRCanvasWJAmac->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetWJAmac_ = (TH1F*)HighestCSVInclJetCanvasWJAmac->GetPrimitive("HighestCSVInclJet");

//  ////////////////
//  // WJMad
//  ////////////////
//  TH1F *NMedIsoTausWithMu3WJMad_ = (TH1F*)NMedIsoTausWithMu3CanvasWJMad->GetPrimitive("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3WJMad_ = (TH1F*)InvMassTauHadMu3CanvasWJMad->GetPrimitive("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3WJMad_ = (TH1F*)PtTauHadMu3CanvasWJMad->GetPrimitive("PtTauHadMu3");
//  TH1F *InvMassUpsilonRangeWJMad_ = (TH1F*)InvMassUpsilonRangeCanvasWJMad->GetPrimitive("InvMassUpsilonRange");
//  TH1F *InvMassZPeakRangeWJMad_ = (TH1F*)InvMassZPeakRangeCanvasWJMad->GetPrimitive("InvMassZPeakRange");
//  TH1F *InvMassFullRangeWJMad_ = (TH1F*)InvMassFullRangeCanvasWJMad->GetPrimitive("InvMassFullRange");
//  TH1F *InvMassDiMuBarrBarrWJMad_ = (TH1F*)InvMassDiMuBarrBarrCanvasWJMad->GetPrimitive("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcWJMad_ = (TH1F*)InvMassDiMuBarrEndcCanvasWJMad->GetPrimitive("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcWJMad_ = (TH1F*)InvMassDiMuEndcEndcCanvasWJMad->GetPrimitive("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtWJMad_ = (TH1F*)Mu1PtCanvasWJMad->GetPrimitive("Mu1Pt");
//  TH1F *Mu2PtWJMad_ = (TH1F*)Mu2PtCanvasWJMad->GetPrimitive("Mu2Pt");
//  TH1F *DiMuPtWJMad_ = (TH1F*)DiMuPtCanvasWJMad->GetPrimitive("DiMuPt");
//  TH1F *Mu1EtaWJMad_ = (TH1F*)Mu1EtaCanvasWJMad->GetPrimitive("Mu1Eta");
//  TH1F *Mu2EtaWJMad_ = (TH1F*)Mu2EtaCanvasWJMad->GetPrimitive("Mu2Eta");
//  TH1F *DiTauEtaWJMad_ = (TH1F*)DiTauEtaCanvasWJMad->GetPrimitive("DiTauEta");
//  TH1F *DiTauPhiWJMad_ = (TH1F*)DiTauPhiCanvasWJMad->GetPrimitive("DiTauPhi");
//  TH1F *DiMuEtaWJMad_ = (TH1F*)DiMuEtaCanvasWJMad->GetPrimitive("DiMuEta");
//  TH1F *DiMudRWJMad_ = (TH1F*)DiMudRCanvasWJMad->GetPrimitive("DiMudR");
//  TH1F *DiMuPhiWJMad_ = (TH1F*)DiMuPhiCanvasWJMad->GetPrimitive("DiMuPhi");
//  TH1F *EtMETWJMad_ = (TH1F*)EtMETCanvasWJMad->GetPrimitive("EtMET");
//  TH1F *DiTauDiMuMassWJMad_ = (TH1F*)DiTauDiMuMassCanvasWJMad->GetPrimitive("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiWJMad_ = (TH1F*)DiMuDiTauDeltaPhiCanvasWJMad->GetPrimitive("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiWJMad_ = (TH1F*)METDiMuDeltaPhiCanvasWJMad->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiWJMad_ = (TH1F*)METDiMuDeltaPhiCanvasWJMad->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *DiTaudRWJMad_ = (TH1F*)DiTaudRCanvasWJMad->GetPrimitive("DiTaudR");
//  TH1F *DiTauMassSmallerdRWJMad_ = (TH1F*)DiTauMassSmallerdRCanvasWJMad->GetPrimitive("DiTauMassSmallerdR");
//  TH1F *HighestCSVInclJetWJMad_ = (TH1F*)HighestCSVInclJetCanvasWJMad->GetPrimitive("HighestCSVInclJet");
//
//  ////////////////
  // WZ
  ////////////////
  TH1F *NMedIsoTausWithMu3WZ_ = (TH1F*)NMedIsoTausWithMu3CanvasWZ->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3WZ_ = (TH1F*)InvMassTauHadMu3CanvasWZ->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3WZ_ = (TH1F*)PtTauHadMu3CanvasWZ->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeWZ_ = (TH1F*)InvMassUpsilonRangeCanvasWZ->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeWZ_ = (TH1F*)InvMassZPeakRangeCanvasWZ->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeWZ_ = (TH1F*)InvMassFullRangeCanvasWZ->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrWZ_ = (TH1F*)InvMassDiMuBarrBarrCanvasWZ->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcWZ_ = (TH1F*)InvMassDiMuBarrEndcCanvasWZ->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcWZ_ = (TH1F*)InvMassDiMuEndcEndcCanvasWZ->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtWZ_ = (TH1F*)Mu1PtCanvasWZ->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtWZ_ = (TH1F*)Mu2PtCanvasWZ->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtWZ_ = (TH1F*)DiMuPtCanvasWZ->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaWZ_ = (TH1F*)Mu1EtaCanvasWZ->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaWZ_ = (TH1F*)Mu2EtaCanvasWZ->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaWZ_ = (TH1F*)DiTauEtaCanvasWZ->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiWZ_ = (TH1F*)DiTauPhiCanvasWZ->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaWZ_ = (TH1F*)DiMuEtaCanvasWZ->GetPrimitive("DiMuEta");
  TH1F *DiMudRWZ_ = (TH1F*)DiMudRCanvasWZ->GetPrimitive("DiMudR");
  TH1F *DiMuPhiWZ_ = (TH1F*)DiMuPhiCanvasWZ->GetPrimitive("DiMuPhi");
  TH1F *EtMETWZ_ = (TH1F*)EtMETCanvasWZ->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassWZ_ = (TH1F*)DiTauDiMuMassCanvasWZ->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiWZ_ = (TH1F*)DiMuDiTauDeltaPhiCanvasWZ->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiWZ_ = (TH1F*)METDiMuDeltaPhiCanvasWZ->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiWZ_ = (TH1F*)METDiMuDeltaPhiCanvasWZ->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRWZ_ = (TH1F*)DiTaudRCanvasWZ->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRWZ_ = (TH1F*)DiTauMassSmallerdRCanvasWZ->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetWZ_ = (TH1F*)HighestCSVInclJetCanvasWZ->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // ZZ2L2Nu
  ////////////////
  TH1F *NMedIsoTausWithMu3ZZ2L2Nu_ = (TH1F*)NMedIsoTausWithMu3CanvasZZ2L2Nu->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3ZZ2L2Nu_ = (TH1F*)InvMassTauHadMu3CanvasZZ2L2Nu->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3ZZ2L2Nu_ = (TH1F*)PtTauHadMu3CanvasZZ2L2Nu->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeZZ2L2Nu_ = (TH1F*)InvMassUpsilonRangeCanvasZZ2L2Nu->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeZZ2L2Nu_ = (TH1F*)InvMassZPeakRangeCanvasZZ2L2Nu->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeZZ2L2Nu_ = (TH1F*)InvMassFullRangeCanvasZZ2L2Nu->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrZZ2L2Nu_ = (TH1F*)InvMassDiMuBarrBarrCanvasZZ2L2Nu->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcZZ2L2Nu_ = (TH1F*)InvMassDiMuBarrEndcCanvasZZ2L2Nu->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcZZ2L2Nu_ = (TH1F*)InvMassDiMuEndcEndcCanvasZZ2L2Nu->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtZZ2L2Nu_ = (TH1F*)Mu1PtCanvasZZ2L2Nu->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtZZ2L2Nu_ = (TH1F*)Mu2PtCanvasZZ2L2Nu->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtZZ2L2Nu_ = (TH1F*)DiMuPtCanvasZZ2L2Nu->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaZZ2L2Nu_ = (TH1F*)Mu1EtaCanvasZZ2L2Nu->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaZZ2L2Nu_ = (TH1F*)Mu2EtaCanvasZZ2L2Nu->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaZZ2L2Nu_ = (TH1F*)DiTauEtaCanvasZZ2L2Nu->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiZZ2L2Nu_ = (TH1F*)DiTauPhiCanvasZZ2L2Nu->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaZZ2L2Nu_ = (TH1F*)DiMuEtaCanvasZZ2L2Nu->GetPrimitive("DiMuEta");
  TH1F *DiMudRZZ2L2Nu_ = (TH1F*)DiMudRCanvasZZ2L2Nu->GetPrimitive("DiMudR");
  TH1F *DiMuPhiZZ2L2Nu_ = (TH1F*)DiMuPhiCanvasZZ2L2Nu->GetPrimitive("DiMuPhi");
  TH1F *EtMETZZ2L2Nu_ = (TH1F*)EtMETCanvasZZ2L2Nu->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassZZ2L2Nu_ = (TH1F*)DiTauDiMuMassCanvasZZ2L2Nu->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiZZ2L2Nu_ = (TH1F*)DiMuDiTauDeltaPhiCanvasZZ2L2Nu->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiZZ2L2Nu_ = (TH1F*)METDiMuDeltaPhiCanvasZZ2L2Nu->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiZZ2L2Nu_ = (TH1F*)METDiMuDeltaPhiCanvasZZ2L2Nu->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRZZ2L2Nu_ = (TH1F*)DiTaudRCanvasZZ2L2Nu->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRZZ2L2Nu_ = (TH1F*)DiTauMassSmallerdRCanvasZZ2L2Nu->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetZZ2L2Nu_ = (TH1F*)HighestCSVInclJetCanvasZZ2L2Nu->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // ZZ2L2Q
  ////////////////
  TH1F *NMedIsoTausWithMu3ZZ2L2Q_ = (TH1F*)NMedIsoTausWithMu3CanvasZZ2L2Q->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3ZZ2L2Q_ = (TH1F*)InvMassTauHadMu3CanvasZZ2L2Q->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3ZZ2L2Q_ = (TH1F*)PtTauHadMu3CanvasZZ2L2Q->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeZZ2L2Q_ = (TH1F*)InvMassUpsilonRangeCanvasZZ2L2Q->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeZZ2L2Q_ = (TH1F*)InvMassZPeakRangeCanvasZZ2L2Q->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeZZ2L2Q_ = (TH1F*)InvMassFullRangeCanvasZZ2L2Q->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrZZ2L2Q_ = (TH1F*)InvMassDiMuBarrBarrCanvasZZ2L2Q->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcZZ2L2Q_ = (TH1F*)InvMassDiMuBarrEndcCanvasZZ2L2Q->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcZZ2L2Q_ = (TH1F*)InvMassDiMuEndcEndcCanvasZZ2L2Q->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtZZ2L2Q_ = (TH1F*)Mu1PtCanvasZZ2L2Q->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtZZ2L2Q_ = (TH1F*)Mu2PtCanvasZZ2L2Q->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtZZ2L2Q_ = (TH1F*)DiMuPtCanvasZZ2L2Q->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaZZ2L2Q_ = (TH1F*)Mu1EtaCanvasZZ2L2Q->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaZZ2L2Q_ = (TH1F*)Mu2EtaCanvasZZ2L2Q->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaZZ2L2Q_ = (TH1F*)DiTauEtaCanvasZZ2L2Q->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiZZ2L2Q_ = (TH1F*)DiTauPhiCanvasZZ2L2Q->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaZZ2L2Q_ = (TH1F*)DiMuEtaCanvasZZ2L2Q->GetPrimitive("DiMuEta");
  TH1F *DiMudRZZ2L2Q_ = (TH1F*)DiMudRCanvasZZ2L2Q->GetPrimitive("DiMudR");
  TH1F *DiMuPhiZZ2L2Q_ = (TH1F*)DiMuPhiCanvasZZ2L2Q->GetPrimitive("DiMuPhi");
  TH1F *EtMETZZ2L2Q_ = (TH1F*)EtMETCanvasZZ2L2Q->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassZZ2L2Q_ = (TH1F*)DiTauDiMuMassCanvasZZ2L2Q->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiZZ2L2Q_ = (TH1F*)DiMuDiTauDeltaPhiCanvasZZ2L2Q->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiZZ2L2Q_ = (TH1F*)METDiMuDeltaPhiCanvasZZ2L2Q->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiZZ2L2Q_ = (TH1F*)METDiMuDeltaPhiCanvasZZ2L2Q->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRZZ2L2Q_ = (TH1F*)DiTaudRCanvasZZ2L2Q->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRZZ2L2Q_ = (TH1F*)DiTauMassSmallerdRCanvasZZ2L2Q->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetZZ2L2Q_ = (TH1F*)HighestCSVInclJetCanvasZZ2L2Q->GetPrimitive("HighestCSVInclJet");

  ////////////////
  // ZZ4LAmac
  ////////////////
  TH1F *NMedIsoTausWithMu3ZZ4LAmac_ = (TH1F*)NMedIsoTausWithMu3CanvasZZ4LAmac->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3ZZ4LAmac_ = (TH1F*)InvMassTauHadMu3CanvasZZ4LAmac->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3ZZ4LAmac_ = (TH1F*)PtTauHadMu3CanvasZZ4LAmac->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassUpsilonRangeZZ4LAmac_ = (TH1F*)InvMassUpsilonRangeCanvasZZ4LAmac->GetPrimitive("InvMassUpsilonRange");
  TH1F *InvMassZPeakRangeZZ4LAmac_ = (TH1F*)InvMassZPeakRangeCanvasZZ4LAmac->GetPrimitive("InvMassZPeakRange");
  TH1F *InvMassFullRangeZZ4LAmac_ = (TH1F*)InvMassFullRangeCanvasZZ4LAmac->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrZZ4LAmac_ = (TH1F*)InvMassDiMuBarrBarrCanvasZZ4LAmac->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcZZ4LAmac_ = (TH1F*)InvMassDiMuBarrEndcCanvasZZ4LAmac->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcZZ4LAmac_ = (TH1F*)InvMassDiMuEndcEndcCanvasZZ4LAmac->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1PtZZ4LAmac_ = (TH1F*)Mu1PtCanvasZZ4LAmac->GetPrimitive("Mu1Pt");
  TH1F *Mu2PtZZ4LAmac_ = (TH1F*)Mu2PtCanvasZZ4LAmac->GetPrimitive("Mu2Pt");
  TH1F *DiMuPtZZ4LAmac_ = (TH1F*)DiMuPtCanvasZZ4LAmac->GetPrimitive("DiMuPt");
  TH1F *Mu1EtaZZ4LAmac_ = (TH1F*)Mu1EtaCanvasZZ4LAmac->GetPrimitive("Mu1Eta");
  TH1F *Mu2EtaZZ4LAmac_ = (TH1F*)Mu2EtaCanvasZZ4LAmac->GetPrimitive("Mu2Eta");
  TH1F *DiTauEtaZZ4LAmac_ = (TH1F*)DiTauEtaCanvasZZ4LAmac->GetPrimitive("DiTauEta");
  TH1F *DiTauPhiZZ4LAmac_ = (TH1F*)DiTauPhiCanvasZZ4LAmac->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtaZZ4LAmac_ = (TH1F*)DiMuEtaCanvasZZ4LAmac->GetPrimitive("DiMuEta");
  TH1F *DiMudRZZ4LAmac_ = (TH1F*)DiMudRCanvasZZ4LAmac->GetPrimitive("DiMudR");
  TH1F *DiMuPhiZZ4LAmac_ = (TH1F*)DiMuPhiCanvasZZ4LAmac->GetPrimitive("DiMuPhi");
  TH1F *EtMETZZ4LAmac_ = (TH1F*)EtMETCanvasZZ4LAmac->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassZZ4LAmac_ = (TH1F*)DiTauDiMuMassCanvasZZ4LAmac->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiZZ4LAmac_ = (TH1F*)DiMuDiTauDeltaPhiCanvasZZ4LAmac->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiZZ4LAmac_ = (TH1F*)METDiMuDeltaPhiCanvasZZ4LAmac->GetPrimitive("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiZZ4LAmac_ = (TH1F*)METDiMuDeltaPhiCanvasZZ4LAmac->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRZZ4LAmac_ = (TH1F*)DiTaudRCanvasZZ4LAmac->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRZZ4LAmac_ = (TH1F*)DiTauMassSmallerdRCanvasZZ4LAmac->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJetZZ4LAmac_ = (TH1F*)HighestCSVInclJetCanvasZZ4LAmac->GetPrimitive("HighestCSVInclJet");

  ////////////////
//  // ZZ4LPowh
//  ////////////////
//  TH1F *NMedIsoTausWithMu3ZZ4LPowh_ = (TH1F*)NMedIsoTausWithMu3CanvasZZ4LPowh->GetPrimitive("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3ZZ4LPowh_ = (TH1F*)InvMassTauHadMu3CanvasZZ4LPowh->GetPrimitive("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3ZZ4LPowh_ = (TH1F*)PtTauHadMu3CanvasZZ4LPowh->GetPrimitive("PtTauHadMu3");
//  TH1F *InvMassUpsilonRangeZZ4LPowh_ = (TH1F*)InvMassUpsilonRangeCanvasZZ4LPowh->GetPrimitive("InvMassUpsilonRange");
//  TH1F *InvMassZPeakRangeZZ4LPowh_ = (TH1F*)InvMassZPeakRangeCanvasZZ4LPowh->GetPrimitive("InvMassZPeakRange");
//  TH1F *InvMassFullRangeZZ4LPowh_ = (TH1F*)InvMassFullRangeCanvasZZ4LPowh->GetPrimitive("InvMassFullRange");
//  TH1F *InvMassDiMuBarrBarrZZ4LPowh_ = (TH1F*)InvMassDiMuBarrBarrCanvasZZ4LPowh->GetPrimitive("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcZZ4LPowh_ = (TH1F*)InvMassDiMuBarrEndcCanvasZZ4LPowh->GetPrimitive("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcZZ4LPowh_ = (TH1F*)InvMassDiMuEndcEndcCanvasZZ4LPowh->GetPrimitive("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtZZ4LPowh_ = (TH1F*)Mu1PtCanvasZZ4LPowh->GetPrimitive("Mu1Pt");
//  TH1F *Mu2PtZZ4LPowh_ = (TH1F*)Mu2PtCanvasZZ4LPowh->GetPrimitive("Mu2Pt");
//  TH1F *DiMuPtZZ4LPowh_ = (TH1F*)DiMuPtCanvasZZ4LPowh->GetPrimitive("DiMuPt");
//  TH1F *Mu1EtaZZ4LPowh_ = (TH1F*)Mu1EtaCanvasZZ4LPowh->GetPrimitive("Mu1Eta");
//  TH1F *Mu2EtaZZ4LPowh_ = (TH1F*)Mu2EtaCanvasZZ4LPowh->GetPrimitive("Mu2Eta");
//  TH1F *DiTauEtaZZ4LPowh_ = (TH1F*)DiTauEtaCanvasZZ4LPowh->GetPrimitive("DiTauEta");
//  TH1F *DiTauPhiZZ4LPowh_ = (TH1F*)DiTauPhiCanvasZZ4LPowh->GetPrimitive("DiTauPhi");
//  TH1F *DiMuEtaZZ4LPowh_ = (TH1F*)DiMuEtaCanvasZZ4LPowh->GetPrimitive("DiMuEta");
//  TH1F *DiMudRZZ4LPowh_ = (TH1F*)DiMudRCanvasZZ4LPowh->GetPrimitive("DiMudR");
//  TH1F *DiMuPhiZZ4LPowh_ = (TH1F*)DiMuPhiCanvasZZ4LPowh->GetPrimitive("DiMuPhi");
//  TH1F *EtMETZZ4LPowh_ = (TH1F*)EtMETCanvasZZ4LPowh->GetPrimitive("EtMET");
//  TH1F *DiTauDiMuMassZZ4LPowh_ = (TH1F*)DiTauDiMuMassCanvasZZ4LPowh->GetPrimitive("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiZZ4LPowh_ = (TH1F*)DiMuDiTauDeltaPhiCanvasZZ4LPowh->GetPrimitive("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiZZ4LPowh_ = (TH1F*)METDiMuDeltaPhiCanvasZZ4LPowh->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiZZ4LPowh_ = (TH1F*)METDiMuDeltaPhiCanvasZZ4LPowh->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *DiTaudRZZ4LPowh_ = (TH1F*)DiTaudRCanvasZZ4LPowh->GetPrimitive("DiTaudR");
//  TH1F *DiTauMassSmallerdRZZ4LPowh_ = (TH1F*)DiTauMassSmallerdRCanvasZZ4LPowh->GetPrimitive("DiTauMassSmallerdR");
//  TH1F *HighestCSVInclJetZZ4LPowh_ = (TH1F*)HighestCSVInclJetCanvasZZ4LPowh->GetPrimitive("HighestCSVInclJet");
//
//  ////////////////
//  // JPsi
//  ////////////////
//  TH1F *NMedIsoTausWithMu3JPsi_ = (TH1F*)NMedIsoTausWithMu3CanvasJPsi->GetPrimitive("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3JPsi_ = (TH1F*)InvMassTauHadMu3CanvasJPsi->GetPrimitive("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3JPsi_ = (TH1F*)PtTauHadMu3CanvasJPsi->GetPrimitive("PtTauHadMu3");
//  TH1F *InvMassUpsilonRangeJPsi_ = (TH1F*)InvMassUpsilonRangeCanvasJPsi->GetPrimitive("InvMassUpsilonRange");
//  TH1F *InvMassZPeakRangeJPsi_ = (TH1F*)InvMassZPeakRangeCanvasJPsi->GetPrimitive("InvMassZPeakRange");
//  TH1F *InvMassFullRangeJPsi_ = (TH1F*)InvMassFullRangeCanvasJPsi->GetPrimitive("InvMassFullRange");
//  TH1F *InvMassDiMuBarrBarrJPsi_ = (TH1F*)InvMassDiMuBarrBarrCanvasJPsi->GetPrimitive("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcJPsi_ = (TH1F*)InvMassDiMuBarrEndcCanvasJPsi->GetPrimitive("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcJPsi_ = (TH1F*)InvMassDiMuEndcEndcCanvasJPsi->GetPrimitive("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtJPsi_ = (TH1F*)Mu1PtCanvasJPsi->GetPrimitive("Mu1Pt");
//  TH1F *Mu2PtJPsi_ = (TH1F*)Mu2PtCanvasJPsi->GetPrimitive("Mu2Pt");
//  TH1F *DiMuPtJPsi_ = (TH1F*)DiMuPtCanvasJPsi->GetPrimitive("DiMuPt");
//  TH1F *Mu1EtaJPsi_ = (TH1F*)Mu1EtaCanvasJPsi->GetPrimitive("Mu1Eta");
//  TH1F *Mu2EtaJPsi_ = (TH1F*)Mu2EtaCanvasJPsi->GetPrimitive("Mu2Eta");
//  TH1F *DiTauEtaJPsi_ = (TH1F*)DiTauEtaCanvasJPsi->GetPrimitive("DiTauEta");
//  TH1F *DiTauPhiJPsi_ = (TH1F*)DiTauPhiCanvasJPsi->GetPrimitive("DiTauPhi");
//  TH1F *DiMuEtaJPsi_ = (TH1F*)DiMuEtaCanvasJPsi->GetPrimitive("DiMuEta");
//  TH1F *DiMudRJPsi_ = (TH1F*)DiMudRCanvasJPsi->GetPrimitive("DiMudR");
//  TH1F *DiMuPhiJPsi_ = (TH1F*)DiMuPhiCanvasJPsi->GetPrimitive("DiMuPhi");
//  TH1F *EtMETJPsi_ = (TH1F*)EtMETCanvasJPsi->GetPrimitive("EtMET");
//  TH1F *DiTauDiMuMassJPsi_ = (TH1F*)DiTauDiMuMassCanvasJPsi->GetPrimitive("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiJPsi_ = (TH1F*)DiMuDiTauDeltaPhiCanvasJPsi->GetPrimitive("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiJPsi_ = (TH1F*)METDiMuDeltaPhiCanvasJPsi->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiJPsi_ = (TH1F*)METDiMuDeltaPhiCanvasJPsi->GetPrimitive("METDiMuDeltaPhi");
//  TH1F *DiTaudRJPsi_ = (TH1F*)DiTaudRCanvasJPsi->GetPrimitive("DiTaudR");
//  TH1F *DiTauMassSmallerdRJPsi_ = (TH1F*)DiTauMassSmallerdRCanvasJPsi->GetPrimitive("DiTauMassSmallerdR");
//  TH1F *HighestCSVInclJetJPsi_ = (TH1F*)HighestCSVInclJetCanvasJPsi->GetPrimitive("HighestCSVInclJet");


cout << "Got Histograms from Canvases" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the QCD Combined Canvas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *NMedIsoTausWithMu3CanvasQCD = new TCanvas ("NMedIsoTausWithMu3CanvasQCD","",600,600); 
  TCanvas *InvMassTauHadMu3CanvasQCD = new TCanvas ("InvMassTauHadMu3CanvasQCD","",600,600); 
  TCanvas *PtTauHadMu3CanvasQCD = new TCanvas ("PtTauHadMu3CanvasQCD","",600,600); 
  TCanvas *InvMassUpsilonRangeCanvasQCD = new TCanvas ("InvMassUpsilonRangeCanvasQCD","",600,600); 
  TCanvas *InvMassZPeakRangeCanvasQCD = new TCanvas ("InvMassZPeakRangeCanvasQCD","",600,600); 
  TCanvas *InvMassFullRangeCanvasQCD = new TCanvas ("InvMassFullRangeCanvasQCD","",600,600); 
  TCanvas *InvMassDiMuBarrBarrCanvasQCD = new TCanvas ("InvMassDiMuBarrBarrCanvasQCD","",600,600); 
  TCanvas *InvMassDiMuBarrEndcCanvasQCD = new TCanvas ("InvMassDiMuBarrEndcCanvasQCD","",600,600); 
  TCanvas *InvMassDiMuEndcEndcCanvasQCD = new TCanvas ("InvMassDiMuEndcEndcCanvasQCD","",600,600); 
  TCanvas *Mu1PtCanvasQCD = new TCanvas ("Mu1PtCanvasQCD","",600,600); 
  TCanvas *Mu2PtCanvasQCD = new TCanvas ("Mu2PtCanvasQCD","",600,600); 
  TCanvas *DiMuPtCanvasQCD = new TCanvas ("DiMuPtCanvasQCD","",600,600); 
  TCanvas *Mu1EtaCanvasQCD = new TCanvas ("Mu1EtaCanvasQCD","",600,600); 
  TCanvas *Mu2EtaCanvasQCD = new TCanvas ("Mu2EtaCanvasQCD","",600,600); 
  TCanvas *DiTauEtaCanvasQCD = new TCanvas ("DiTauEtaCanvasQCD","",600,600); 
  TCanvas *DiTauPhiCanvasQCD = new TCanvas ("DiTauPhiCanvasQCD","",600,600); 
  TCanvas *DiMuEtaCanvasQCD = new TCanvas ("DiMuEtaCanvasQCD","",600,600); 
  TCanvas *DiMudRCanvasQCD = new TCanvas ("DiMudRCanvasQCD","",600,600); 
  TCanvas *DiMuPhiCanvasQCD = new TCanvas ("DiMuPhiCanvasQCD","",600,600); 
  TCanvas *EtMETCanvasQCD = new TCanvas ("EtMETCanvasQCD","",600,600); 
  TCanvas *DiTauDiMuMassCanvasQCD = new TCanvas ("DiTauDiMuMassCanvasQCD","",600,600); 
  TCanvas *DiMuDiTauDeltaPhiCanvasQCD = new TCanvas ("DiMuDiTauDeltaPhiCanvasQCD","",600,600); 
  TCanvas *METDiTauDeltaPhiCanvasQCD = new TCanvas ("METDiTauDeltaPhiCanvasQCD","",600,600); 
  TCanvas *METDiMuDeltaPhiCanvasQCD = new TCanvas ("METDiMuDeltaPhiCanvasQCD","",600,600); 
  TCanvas *DiTaudRCanvasQCD = new TCanvas ("DiTaudRCanvasQCD","",600,600); 
  TCanvas *DiTauMassSmallerdRCanvasQCD = new TCanvas ("DiTauMassSmallerdRCanvasQCD","",600,600); 
  TCanvas *HighestCSVInclJetCanvasQCD = new TCanvas ("HighestCSVInclJetCanvasQCD","",600,600); 

  TH1F *NMedIsoTausWithMu3QCD_ = new TH1F ("NMedIsoTausWithMu3QCD","", NMedIsoTausWithMu3QCD_15to20_->GetNbinsX(), NMedIsoTausWithMu3QCD_15to20_->GetXaxis()->GetXmin(),  NMedIsoTausWithMu3QCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *InvMassTauHadMu3QCD_ = new TH1F ("InvMassTauHadMu3QCD","",InvMassTauHadMu3QCD_15to20_->GetNbinsX(), InvMassTauHadMu3QCD_15to20_->GetXaxis()->GetXmin(),  InvMassTauHadMu3QCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *PtTauHadMu3QCD_ = new TH1F ("PtTauHadMu3QCD","",PtTauHadMu3QCD_15to20_->GetNbinsX(), PtTauHadMu3QCD_15to20_->GetXaxis()->GetXmin(),  PtTauHadMu3QCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *InvMassUpsilonRangeQCD_ = new TH1F ("InvMassUpsilonRangeQCD","",InvMassUpsilonRangeQCD_15to20_->GetNbinsX(), InvMassUpsilonRangeQCD_15to20_->GetXaxis()->GetXmin(),  InvMassUpsilonRangeQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *InvMassZPeakRangeQCD_ = new TH1F ("InvMassZPeakRangeQCD","",InvMassZPeakRangeQCD_15to20_->GetNbinsX(), InvMassZPeakRangeQCD_15to20_->GetXaxis()->GetXmin(),  InvMassZPeakRangeQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *InvMassFullRangeQCD_ = new TH1F ("InvMassFullRangeQCD","",InvMassFullRangeQCD_15to20_->GetNbinsX(), InvMassFullRangeQCD_15to20_->GetXaxis()->GetXmin(),  InvMassFullRangeQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuBarrBarrQCD_ = new TH1F ("InvMassDiMuBarrBarrQCD","",InvMassDiMuBarrBarrQCD_15to20_->GetNbinsX(), InvMassDiMuBarrBarrQCD_15to20_->GetXaxis()->GetXmin(),  InvMassDiMuBarrBarrQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuBarrEndcQCD_ = new TH1F ("InvMassDiMuBarrEndcQCD","",InvMassDiMuBarrEndcQCD_15to20_->GetNbinsX(), InvMassDiMuBarrEndcQCD_15to20_->GetXaxis()->GetXmin(),  InvMassDiMuBarrEndcQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuEndcEndcQCD_ = new TH1F ("InvMassDiMuEndcEndcQCD","",InvMassDiMuEndcEndcQCD_15to20_->GetNbinsX(), InvMassDiMuEndcEndcQCD_15to20_->GetXaxis()->GetXmin(),  InvMassDiMuEndcEndcQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *Mu1PtQCD_ = new TH1F ("Mu1PtQCD","",Mu1PtQCD_15to20_->GetNbinsX(), Mu1PtQCD_15to20_->GetXaxis()->GetXmin(),  Mu1PtQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *Mu2PtQCD_ = new TH1F ("Mu2PtQCD","",Mu2PtQCD_15to20_->GetNbinsX(), Mu2PtQCD_15to20_->GetXaxis()->GetXmin(),  Mu2PtQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DiMuPtQCD_ = new TH1F ("DiMuPtQCD","",DiMuPtQCD_15to20_->GetNbinsX(), DiMuPtQCD_15to20_->GetXaxis()->GetXmin(),  DiMuPtQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *Mu1EtaQCD_ = new TH1F ("Mu1EtaQCD","",Mu1EtaQCD_15to20_->GetNbinsX(), Mu1EtaQCD_15to20_->GetXaxis()->GetXmin(),  Mu1EtaQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *Mu2EtaQCD_ = new TH1F ("Mu2EtaQCD","",Mu2EtaQCD_15to20_->GetNbinsX(), Mu2EtaQCD_15to20_->GetXaxis()->GetXmin(),  Mu2EtaQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DiTauEtaQCD_ = new TH1F ("DiTauEtaQCD","",DiTauEtaQCD_15to20_->GetNbinsX(), DiTauEtaQCD_15to20_->GetXaxis()->GetXmin(),  DiTauEtaQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DiTauPhiQCD_ = new TH1F ("DiTauPhiQCD","",DiTauPhiQCD_15to20_->GetNbinsX(), DiTauPhiQCD_15to20_->GetXaxis()->GetXmin(),  DiTauPhiQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DiMuEtaQCD_ = new TH1F ("DiMuEtaQCD","",DiMuEtaQCD_15to20_->GetNbinsX(), DiMuEtaQCD_15to20_->GetXaxis()->GetXmin(),  DiMuEtaQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DiMudRQCD_ = new TH1F ("DiMudRQCD","",DiMudRQCD_15to20_->GetNbinsX(), DiMudRQCD_15to20_->GetXaxis()->GetXmin(),  DiMudRQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DiMuPhiQCD_ = new TH1F ("DiMuPhiQCD","",DiMuPhiQCD_15to20_->GetNbinsX(), DiMuPhiQCD_15to20_->GetXaxis()->GetXmin(),  DiMuPhiQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *EtMETQCD_ = new TH1F ("EtMETQCD","",EtMETQCD_15to20_->GetNbinsX(), EtMETQCD_15to20_->GetXaxis()->GetXmin(),  EtMETQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DiTauDiMuMassQCD_ = new TH1F ("DiTauDiMuMassQCD","",DiTauDiMuMassQCD_15to20_->GetNbinsX(), DiTauDiMuMassQCD_15to20_->GetXaxis()->GetXmin(),  DiTauDiMuMassQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DiMuDiTauDeltaPhiQCD_ = new TH1F ("DiMuDiTauDeltaPhiQCD","",DiMuDiTauDeltaPhiQCD_15to20_->GetNbinsX(), DiMuDiTauDeltaPhiQCD_15to20_->GetXaxis()->GetXmin(),  DiMuDiTauDeltaPhiQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *METDiTauDeltaPhiQCD_ = new TH1F ("METDiTauDeltaPhiQCD","",METDiTauDeltaPhiQCD_15to20_->GetNbinsX(), METDiTauDeltaPhiQCD_15to20_->GetXaxis()->GetXmin(),  METDiTauDeltaPhiQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *METDiMuDeltaPhiQCD_ = new TH1F ("METDiMuDeltaPhiQCD","",METDiMuDeltaPhiQCD_15to20_->GetNbinsX(), METDiMuDeltaPhiQCD_15to20_->GetXaxis()->GetXmin(),  METDiMuDeltaPhiQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DiTaudRQCD_ = new TH1F ("DiTaudRQCD","",DiTaudRQCD_15to20_->GetNbinsX(), DiTaudRQCD_15to20_->GetXaxis()->GetXmin(),  DiTaudRQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *DiTauMassSmallerdRQCD_ = new TH1F ("DiTauMassSmallerdRQCD","",DiTauMassSmallerdRQCD_15to20_->GetNbinsX(), DiTauMassSmallerdRQCD_15to20_->GetXaxis()->GetXmin(),  DiTauMassSmallerdRQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *HighestCSVInclJetQCD_ = new TH1F ("HighestCSVInclJetQCD","",HighestCSVInclJetQCD_15to20_->GetNbinsX(), HighestCSVInclJetQCD_15to20_->GetXaxis()->GetXmin(),  HighestCSVInclJetQCD_15to20_->GetXaxis()->GetXmax() );


  NMedIsoTausWithMu3CanvasQCD->cd();
  NMedIsoTausWithMu3QCD_->Add(NMedIsoTausWithMu3QCD_15to20_);
  NMedIsoTausWithMu3QCD_->Add(NMedIsoTausWithMu3QCD_20to30_);
  NMedIsoTausWithMu3QCD_->Add(NMedIsoTausWithMu3QCD_30to50_);
  NMedIsoTausWithMu3QCD_->Add(NMedIsoTausWithMu3QCD_50to80_);
  NMedIsoTausWithMu3QCD_->Add(NMedIsoTausWithMu3QCD_80to120_);
  NMedIsoTausWithMu3QCD_->Add(NMedIsoTausWithMu3QCD_120to170_);
  NMedIsoTausWithMu3QCD_->Add(NMedIsoTausWithMu3QCD_170to300_);
  NMedIsoTausWithMu3QCD_->Add(NMedIsoTausWithMu3QCD_300to470_);
  NMedIsoTausWithMu3QCD_->Add(NMedIsoTausWithMu3QCD_470to600_);
  NMedIsoTausWithMu3QCD_->Add(NMedIsoTausWithMu3QCD_600to800_);
  NMedIsoTausWithMu3QCD_->Add(NMedIsoTausWithMu3QCD_800to1000_);
  NMedIsoTausWithMu3QCD_->Add(NMedIsoTausWithMu3QCD_1000toInf_);

  InvMassTauHadMu3CanvasQCD->cd();
  InvMassTauHadMu3QCD_->Add(InvMassTauHadMu3QCD_15to20_);
  InvMassTauHadMu3QCD_->Add(InvMassTauHadMu3QCD_20to30_);
  InvMassTauHadMu3QCD_->Add(InvMassTauHadMu3QCD_30to50_);
  InvMassTauHadMu3QCD_->Add(InvMassTauHadMu3QCD_50to80_);
  InvMassTauHadMu3QCD_->Add(InvMassTauHadMu3QCD_80to120_);
  InvMassTauHadMu3QCD_->Add(InvMassTauHadMu3QCD_120to170_);
  InvMassTauHadMu3QCD_->Add(InvMassTauHadMu3QCD_170to300_);
  InvMassTauHadMu3QCD_->Add(InvMassTauHadMu3QCD_300to470_);
  InvMassTauHadMu3QCD_->Add(InvMassTauHadMu3QCD_470to600_);
  InvMassTauHadMu3QCD_->Add(InvMassTauHadMu3QCD_600to800_);
  InvMassTauHadMu3QCD_->Add(InvMassTauHadMu3QCD_800to1000_);
  InvMassTauHadMu3QCD_->Add(InvMassTauHadMu3QCD_1000toInf_);

  PtTauHadMu3CanvasQCD->cd();
  PtTauHadMu3QCD_->Add(PtTauHadMu3QCD_15to20_);
  PtTauHadMu3QCD_->Add(PtTauHadMu3QCD_20to30_);
  PtTauHadMu3QCD_->Add(PtTauHadMu3QCD_30to50_);
  PtTauHadMu3QCD_->Add(PtTauHadMu3QCD_50to80_);
  PtTauHadMu3QCD_->Add(PtTauHadMu3QCD_80to120_);
  PtTauHadMu3QCD_->Add(PtTauHadMu3QCD_120to170_);
  PtTauHadMu3QCD_->Add(PtTauHadMu3QCD_170to300_);
  PtTauHadMu3QCD_->Add(PtTauHadMu3QCD_300to470_);
  PtTauHadMu3QCD_->Add(PtTauHadMu3QCD_470to600_);
  PtTauHadMu3QCD_->Add(PtTauHadMu3QCD_600to800_);
  PtTauHadMu3QCD_->Add(PtTauHadMu3QCD_800to1000_);
  PtTauHadMu3QCD_->Add(PtTauHadMu3QCD_1000toInf_);

  InvMassUpsilonRangeCanvasQCD->cd();
  InvMassUpsilonRangeQCD_->Add(InvMassUpsilonRangeQCD_15to20_);
  InvMassUpsilonRangeQCD_->Add(InvMassUpsilonRangeQCD_20to30_);
  InvMassUpsilonRangeQCD_->Add(InvMassUpsilonRangeQCD_30to50_);
  InvMassUpsilonRangeQCD_->Add(InvMassUpsilonRangeQCD_50to80_);
  InvMassUpsilonRangeQCD_->Add(InvMassUpsilonRangeQCD_80to120_);
  InvMassUpsilonRangeQCD_->Add(InvMassUpsilonRangeQCD_120to170_);
  InvMassUpsilonRangeQCD_->Add(InvMassUpsilonRangeQCD_170to300_);
  InvMassUpsilonRangeQCD_->Add(InvMassUpsilonRangeQCD_300to470_);
  InvMassUpsilonRangeQCD_->Add(InvMassUpsilonRangeQCD_470to600_);
  InvMassUpsilonRangeQCD_->Add(InvMassUpsilonRangeQCD_600to800_);
  InvMassUpsilonRangeQCD_->Add(InvMassUpsilonRangeQCD_800to1000_);
  InvMassUpsilonRangeQCD_->Add(InvMassUpsilonRangeQCD_1000toInf_);

  InvMassZPeakRangeCanvasQCD->cd();
  InvMassZPeakRangeQCD_->Add(InvMassZPeakRangeQCD_15to20_);
  InvMassZPeakRangeQCD_->Add(InvMassZPeakRangeQCD_20to30_);
  InvMassZPeakRangeQCD_->Add(InvMassZPeakRangeQCD_30to50_);
  InvMassZPeakRangeQCD_->Add(InvMassZPeakRangeQCD_50to80_);
  InvMassZPeakRangeQCD_->Add(InvMassZPeakRangeQCD_80to120_);
  InvMassZPeakRangeQCD_->Add(InvMassZPeakRangeQCD_120to170_);
  InvMassZPeakRangeQCD_->Add(InvMassZPeakRangeQCD_170to300_);
  InvMassZPeakRangeQCD_->Add(InvMassZPeakRangeQCD_300to470_);
  InvMassZPeakRangeQCD_->Add(InvMassZPeakRangeQCD_470to600_);
  InvMassZPeakRangeQCD_->Add(InvMassZPeakRangeQCD_600to800_);
  InvMassZPeakRangeQCD_->Add(InvMassZPeakRangeQCD_800to1000_);
  InvMassZPeakRangeQCD_->Add(InvMassZPeakRangeQCD_1000toInf_);

  InvMassFullRangeCanvasQCD->cd();
  InvMassFullRangeQCD_->Add(InvMassFullRangeQCD_15to20_);
  InvMassFullRangeQCD_->Add(InvMassFullRangeQCD_20to30_);
  InvMassFullRangeQCD_->Add(InvMassFullRangeQCD_30to50_);
  InvMassFullRangeQCD_->Add(InvMassFullRangeQCD_50to80_);
  InvMassFullRangeQCD_->Add(InvMassFullRangeQCD_80to120_);
  InvMassFullRangeQCD_->Add(InvMassFullRangeQCD_120to170_);
  InvMassFullRangeQCD_->Add(InvMassFullRangeQCD_170to300_);
  InvMassFullRangeQCD_->Add(InvMassFullRangeQCD_300to470_);
  InvMassFullRangeQCD_->Add(InvMassFullRangeQCD_470to600_);
  InvMassFullRangeQCD_->Add(InvMassFullRangeQCD_600to800_);
  InvMassFullRangeQCD_->Add(InvMassFullRangeQCD_800to1000_);
  InvMassFullRangeQCD_->Add(InvMassFullRangeQCD_1000toInf_);

  InvMassDiMuBarrBarrCanvasQCD->cd();
  InvMassDiMuBarrBarrQCD_->Add(InvMassDiMuBarrBarrQCD_15to20_);
  InvMassDiMuBarrBarrQCD_->Add(InvMassDiMuBarrBarrQCD_20to30_);
  InvMassDiMuBarrBarrQCD_->Add(InvMassDiMuBarrBarrQCD_30to50_);
  InvMassDiMuBarrBarrQCD_->Add(InvMassDiMuBarrBarrQCD_50to80_);
  InvMassDiMuBarrBarrQCD_->Add(InvMassDiMuBarrBarrQCD_80to120_);
  InvMassDiMuBarrBarrQCD_->Add(InvMassDiMuBarrBarrQCD_120to170_);
  InvMassDiMuBarrBarrQCD_->Add(InvMassDiMuBarrBarrQCD_170to300_);
  InvMassDiMuBarrBarrQCD_->Add(InvMassDiMuBarrBarrQCD_300to470_);
  InvMassDiMuBarrBarrQCD_->Add(InvMassDiMuBarrBarrQCD_470to600_);
  InvMassDiMuBarrBarrQCD_->Add(InvMassDiMuBarrBarrQCD_600to800_);
  InvMassDiMuBarrBarrQCD_->Add(InvMassDiMuBarrBarrQCD_800to1000_);
  InvMassDiMuBarrBarrQCD_->Add(InvMassDiMuBarrBarrQCD_1000toInf_);

  InvMassDiMuBarrEndcCanvasQCD->cd();
  InvMassDiMuBarrEndcQCD_->Add(InvMassDiMuBarrEndcQCD_15to20_);
  InvMassDiMuBarrEndcQCD_->Add(InvMassDiMuBarrEndcQCD_20to30_);
  InvMassDiMuBarrEndcQCD_->Add(InvMassDiMuBarrEndcQCD_30to50_);
  InvMassDiMuBarrEndcQCD_->Add(InvMassDiMuBarrEndcQCD_50to80_);
  InvMassDiMuBarrEndcQCD_->Add(InvMassDiMuBarrEndcQCD_80to120_);
  InvMassDiMuBarrEndcQCD_->Add(InvMassDiMuBarrEndcQCD_120to170_);
  InvMassDiMuBarrEndcQCD_->Add(InvMassDiMuBarrEndcQCD_170to300_);
  InvMassDiMuBarrEndcQCD_->Add(InvMassDiMuBarrEndcQCD_300to470_);
  InvMassDiMuBarrEndcQCD_->Add(InvMassDiMuBarrEndcQCD_470to600_);
  InvMassDiMuBarrEndcQCD_->Add(InvMassDiMuBarrEndcQCD_600to800_);
  InvMassDiMuBarrEndcQCD_->Add(InvMassDiMuBarrEndcQCD_800to1000_);
  InvMassDiMuBarrEndcQCD_->Add(InvMassDiMuBarrEndcQCD_1000toInf_);

  InvMassDiMuEndcEndcCanvasQCD->cd();
  InvMassDiMuEndcEndcQCD_->Add(InvMassDiMuEndcEndcQCD_15to20_);
  InvMassDiMuEndcEndcQCD_->Add(InvMassDiMuEndcEndcQCD_20to30_);
  InvMassDiMuEndcEndcQCD_->Add(InvMassDiMuEndcEndcQCD_30to50_);
  InvMassDiMuEndcEndcQCD_->Add(InvMassDiMuEndcEndcQCD_50to80_);
  InvMassDiMuEndcEndcQCD_->Add(InvMassDiMuEndcEndcQCD_80to120_);
  InvMassDiMuEndcEndcQCD_->Add(InvMassDiMuEndcEndcQCD_120to170_);
  InvMassDiMuEndcEndcQCD_->Add(InvMassDiMuEndcEndcQCD_170to300_);
  InvMassDiMuEndcEndcQCD_->Add(InvMassDiMuEndcEndcQCD_300to470_);
  InvMassDiMuEndcEndcQCD_->Add(InvMassDiMuEndcEndcQCD_470to600_);
  InvMassDiMuEndcEndcQCD_->Add(InvMassDiMuEndcEndcQCD_600to800_);
  InvMassDiMuEndcEndcQCD_->Add(InvMassDiMuEndcEndcQCD_800to1000_);
  InvMassDiMuEndcEndcQCD_->Add(InvMassDiMuEndcEndcQCD_1000toInf_);

  Mu1PtCanvasQCD->cd();
  Mu1PtQCD_->Add(Mu1PtQCD_15to20_);
  Mu1PtQCD_->Add(Mu1PtQCD_20to30_);
  Mu1PtQCD_->Add(Mu1PtQCD_30to50_);
  Mu1PtQCD_->Add(Mu1PtQCD_50to80_);
  Mu1PtQCD_->Add(Mu1PtQCD_80to120_);
  Mu1PtQCD_->Add(Mu1PtQCD_120to170_);
  Mu1PtQCD_->Add(Mu1PtQCD_170to300_);
  Mu1PtQCD_->Add(Mu1PtQCD_300to470_);
  Mu1PtQCD_->Add(Mu1PtQCD_470to600_);
  Mu1PtQCD_->Add(Mu1PtQCD_600to800_);
  Mu1PtQCD_->Add(Mu1PtQCD_800to1000_);
  Mu1PtQCD_->Add(Mu1PtQCD_1000toInf_);

  Mu2PtCanvasQCD->cd();
  Mu2PtQCD_->Add(Mu2PtQCD_15to20_);
  Mu2PtQCD_->Add(Mu2PtQCD_20to30_);
  Mu2PtQCD_->Add(Mu2PtQCD_30to50_);
  Mu2PtQCD_->Add(Mu2PtQCD_50to80_);
  Mu2PtQCD_->Add(Mu2PtQCD_80to120_);
  Mu2PtQCD_->Add(Mu2PtQCD_120to170_);
  Mu2PtQCD_->Add(Mu2PtQCD_170to300_);
  Mu2PtQCD_->Add(Mu2PtQCD_300to470_);
  Mu2PtQCD_->Add(Mu2PtQCD_470to600_);
  Mu2PtQCD_->Add(Mu2PtQCD_600to800_);
  Mu2PtQCD_->Add(Mu2PtQCD_800to1000_);
  Mu2PtQCD_->Add(Mu2PtQCD_1000toInf_);

  DiMuPtCanvasQCD->cd();
  DiMuPtQCD_->Add(DiMuPtQCD_15to20_);
  DiMuPtQCD_->Add(DiMuPtQCD_20to30_);
  DiMuPtQCD_->Add(DiMuPtQCD_30to50_);
  DiMuPtQCD_->Add(DiMuPtQCD_50to80_);
  DiMuPtQCD_->Add(DiMuPtQCD_80to120_);
  DiMuPtQCD_->Add(DiMuPtQCD_120to170_);
  DiMuPtQCD_->Add(DiMuPtQCD_170to300_);
  DiMuPtQCD_->Add(DiMuPtQCD_300to470_);
  DiMuPtQCD_->Add(DiMuPtQCD_470to600_);
  DiMuPtQCD_->Add(DiMuPtQCD_600to800_);
  DiMuPtQCD_->Add(DiMuPtQCD_800to1000_);
  DiMuPtQCD_->Add(DiMuPtQCD_1000toInf_);

  Mu1EtaCanvasQCD->cd();
  Mu1EtaQCD_->Add(Mu1EtaQCD_15to20_);
  Mu1EtaQCD_->Add(Mu1EtaQCD_20to30_);
  Mu1EtaQCD_->Add(Mu1EtaQCD_30to50_);
  Mu1EtaQCD_->Add(Mu1EtaQCD_50to80_);
  Mu1EtaQCD_->Add(Mu1EtaQCD_80to120_);
  Mu1EtaQCD_->Add(Mu1EtaQCD_120to170_);
  Mu1EtaQCD_->Add(Mu1EtaQCD_170to300_);
  Mu1EtaQCD_->Add(Mu1EtaQCD_300to470_);
  Mu1EtaQCD_->Add(Mu1EtaQCD_470to600_);
  Mu1EtaQCD_->Add(Mu1EtaQCD_600to800_);
  Mu1EtaQCD_->Add(Mu1EtaQCD_800to1000_);
  Mu1EtaQCD_->Add(Mu1EtaQCD_1000toInf_);

  Mu2EtaCanvasQCD->cd();
  Mu2EtaQCD_->Add(Mu2EtaQCD_15to20_);
  Mu2EtaQCD_->Add(Mu2EtaQCD_20to30_);
  Mu2EtaQCD_->Add(Mu2EtaQCD_30to50_);
  Mu2EtaQCD_->Add(Mu2EtaQCD_50to80_);
  Mu2EtaQCD_->Add(Mu2EtaQCD_80to120_);
  Mu2EtaQCD_->Add(Mu2EtaQCD_120to170_);
  Mu2EtaQCD_->Add(Mu2EtaQCD_170to300_);
  Mu2EtaQCD_->Add(Mu2EtaQCD_300to470_);
  Mu2EtaQCD_->Add(Mu2EtaQCD_470to600_);
  Mu2EtaQCD_->Add(Mu2EtaQCD_600to800_);
  Mu2EtaQCD_->Add(Mu2EtaQCD_800to1000_);
  Mu2EtaQCD_->Add(Mu2EtaQCD_1000toInf_);

  DiTauEtaCanvasQCD->cd();
  DiTauEtaQCD_->Add(DiTauEtaQCD_15to20_);
  DiTauEtaQCD_->Add(DiTauEtaQCD_20to30_);
  DiTauEtaQCD_->Add(DiTauEtaQCD_30to50_);
  DiTauEtaQCD_->Add(DiTauEtaQCD_50to80_);
  DiTauEtaQCD_->Add(DiTauEtaQCD_80to120_);
  DiTauEtaQCD_->Add(DiTauEtaQCD_120to170_);
  DiTauEtaQCD_->Add(DiTauEtaQCD_170to300_);
  DiTauEtaQCD_->Add(DiTauEtaQCD_300to470_);
  DiTauEtaQCD_->Add(DiTauEtaQCD_470to600_);
  DiTauEtaQCD_->Add(DiTauEtaQCD_600to800_);
  DiTauEtaQCD_->Add(DiTauEtaQCD_800to1000_);
  DiTauEtaQCD_->Add(DiTauEtaQCD_1000toInf_);

  DiTauPhiCanvasQCD->cd();
  DiTauPhiQCD_->Add(DiTauPhiQCD_15to20_);
  DiTauPhiQCD_->Add(DiTauPhiQCD_20to30_);
  DiTauPhiQCD_->Add(DiTauPhiQCD_30to50_);
  DiTauPhiQCD_->Add(DiTauPhiQCD_50to80_);
  DiTauPhiQCD_->Add(DiTauPhiQCD_80to120_);
  DiTauPhiQCD_->Add(DiTauPhiQCD_120to170_);
  DiTauPhiQCD_->Add(DiTauPhiQCD_170to300_);
  DiTauPhiQCD_->Add(DiTauPhiQCD_300to470_);
  DiTauPhiQCD_->Add(DiTauPhiQCD_470to600_);
  DiTauPhiQCD_->Add(DiTauPhiQCD_600to800_);
  DiTauPhiQCD_->Add(DiTauPhiQCD_800to1000_);
  DiTauPhiQCD_->Add(DiTauPhiQCD_1000toInf_);

  DiMuEtaCanvasQCD->cd();
  DiMuEtaQCD_->Add(DiMuEtaQCD_15to20_);
  DiMuEtaQCD_->Add(DiMuEtaQCD_20to30_);
  DiMuEtaQCD_->Add(DiMuEtaQCD_30to50_);
  DiMuEtaQCD_->Add(DiMuEtaQCD_50to80_);
  DiMuEtaQCD_->Add(DiMuEtaQCD_80to120_);
  DiMuEtaQCD_->Add(DiMuEtaQCD_120to170_);
  DiMuEtaQCD_->Add(DiMuEtaQCD_170to300_);
  DiMuEtaQCD_->Add(DiMuEtaQCD_300to470_);
  DiMuEtaQCD_->Add(DiMuEtaQCD_470to600_);
  DiMuEtaQCD_->Add(DiMuEtaQCD_600to800_);
  DiMuEtaQCD_->Add(DiMuEtaQCD_800to1000_);
  DiMuEtaQCD_->Add(DiMuEtaQCD_1000toInf_);

  DiMudRCanvasQCD->cd();
  DiMudRQCD_->Add(DiMudRQCD_15to20_);
  DiMudRQCD_->Add(DiMudRQCD_20to30_);
  DiMudRQCD_->Add(DiMudRQCD_30to50_);
  DiMudRQCD_->Add(DiMudRQCD_50to80_);
  DiMudRQCD_->Add(DiMudRQCD_80to120_);
  DiMudRQCD_->Add(DiMudRQCD_120to170_);
  DiMudRQCD_->Add(DiMudRQCD_170to300_);
  DiMudRQCD_->Add(DiMudRQCD_300to470_);
  DiMudRQCD_->Add(DiMudRQCD_470to600_);
  DiMudRQCD_->Add(DiMudRQCD_600to800_);
  DiMudRQCD_->Add(DiMudRQCD_800to1000_);
  DiMudRQCD_->Add(DiMudRQCD_1000toInf_);

  DiMuPhiCanvasQCD->cd();
  DiMuPhiQCD_->Add(DiMuPhiQCD_15to20_);
  DiMuPhiQCD_->Add(DiMuPhiQCD_20to30_);
  DiMuPhiQCD_->Add(DiMuPhiQCD_30to50_);
  DiMuPhiQCD_->Add(DiMuPhiQCD_50to80_);
  DiMuPhiQCD_->Add(DiMuPhiQCD_80to120_);
  DiMuPhiQCD_->Add(DiMuPhiQCD_120to170_);
  DiMuPhiQCD_->Add(DiMuPhiQCD_170to300_);
  DiMuPhiQCD_->Add(DiMuPhiQCD_300to470_);
  DiMuPhiQCD_->Add(DiMuPhiQCD_470to600_);
  DiMuPhiQCD_->Add(DiMuPhiQCD_600to800_);
  DiMuPhiQCD_->Add(DiMuPhiQCD_800to1000_);
  DiMuPhiQCD_->Add(DiMuPhiQCD_1000toInf_);

  EtMETCanvasQCD->cd();
  EtMETQCD_->Add(EtMETQCD_15to20_);
  EtMETQCD_->Add(EtMETQCD_20to30_);
  EtMETQCD_->Add(EtMETQCD_30to50_);
  EtMETQCD_->Add(EtMETQCD_50to80_);
  EtMETQCD_->Add(EtMETQCD_80to120_);
  EtMETQCD_->Add(EtMETQCD_120to170_);
  EtMETQCD_->Add(EtMETQCD_170to300_);
  EtMETQCD_->Add(EtMETQCD_300to470_);
  EtMETQCD_->Add(EtMETQCD_470to600_);
  EtMETQCD_->Add(EtMETQCD_600to800_);
  EtMETQCD_->Add(EtMETQCD_800to1000_);
  EtMETQCD_->Add(EtMETQCD_1000toInf_);

  DiTauDiMuMassCanvasQCD->cd();
  DiTauDiMuMassQCD_->Add(DiTauDiMuMassQCD_15to20_);
  DiTauDiMuMassQCD_->Add(DiTauDiMuMassQCD_20to30_);
  DiTauDiMuMassQCD_->Add(DiTauDiMuMassQCD_30to50_);
  DiTauDiMuMassQCD_->Add(DiTauDiMuMassQCD_50to80_);
  DiTauDiMuMassQCD_->Add(DiTauDiMuMassQCD_80to120_);
  DiTauDiMuMassQCD_->Add(DiTauDiMuMassQCD_120to170_);
  DiTauDiMuMassQCD_->Add(DiTauDiMuMassQCD_170to300_);
  DiTauDiMuMassQCD_->Add(DiTauDiMuMassQCD_300to470_);
  DiTauDiMuMassQCD_->Add(DiTauDiMuMassQCD_470to600_);
  DiTauDiMuMassQCD_->Add(DiTauDiMuMassQCD_600to800_);
  DiTauDiMuMassQCD_->Add(DiTauDiMuMassQCD_800to1000_);
  DiTauDiMuMassQCD_->Add(DiTauDiMuMassQCD_1000toInf_);

  DiMuDiTauDeltaPhiCanvasQCD->cd();
  DiMuDiTauDeltaPhiQCD_->Add(DiMuDiTauDeltaPhiQCD_15to20_);
  DiMuDiTauDeltaPhiQCD_->Add(DiMuDiTauDeltaPhiQCD_20to30_);
  DiMuDiTauDeltaPhiQCD_->Add(DiMuDiTauDeltaPhiQCD_30to50_);
  DiMuDiTauDeltaPhiQCD_->Add(DiMuDiTauDeltaPhiQCD_50to80_);
  DiMuDiTauDeltaPhiQCD_->Add(DiMuDiTauDeltaPhiQCD_80to120_);
  DiMuDiTauDeltaPhiQCD_->Add(DiMuDiTauDeltaPhiQCD_120to170_);
  DiMuDiTauDeltaPhiQCD_->Add(DiMuDiTauDeltaPhiQCD_170to300_);
  DiMuDiTauDeltaPhiQCD_->Add(DiMuDiTauDeltaPhiQCD_300to470_);
  DiMuDiTauDeltaPhiQCD_->Add(DiMuDiTauDeltaPhiQCD_470to600_);
  DiMuDiTauDeltaPhiQCD_->Add(DiMuDiTauDeltaPhiQCD_600to800_);
  DiMuDiTauDeltaPhiQCD_->Add(DiMuDiTauDeltaPhiQCD_800to1000_);
  DiMuDiTauDeltaPhiQCD_->Add(DiMuDiTauDeltaPhiQCD_1000toInf_);

  METDiTauDeltaPhiCanvasQCD->cd();
  METDiTauDeltaPhiQCD_->Add(METDiTauDeltaPhiQCD_15to20_);
  METDiTauDeltaPhiQCD_->Add(METDiTauDeltaPhiQCD_20to30_);
  METDiTauDeltaPhiQCD_->Add(METDiTauDeltaPhiQCD_30to50_);
  METDiTauDeltaPhiQCD_->Add(METDiTauDeltaPhiQCD_50to80_);
  METDiTauDeltaPhiQCD_->Add(METDiTauDeltaPhiQCD_80to120_);
  METDiTauDeltaPhiQCD_->Add(METDiTauDeltaPhiQCD_120to170_);
  METDiTauDeltaPhiQCD_->Add(METDiTauDeltaPhiQCD_170to300_);
  METDiTauDeltaPhiQCD_->Add(METDiTauDeltaPhiQCD_300to470_);
  METDiTauDeltaPhiQCD_->Add(METDiTauDeltaPhiQCD_470to600_);
  METDiTauDeltaPhiQCD_->Add(METDiTauDeltaPhiQCD_600to800_);
  METDiTauDeltaPhiQCD_->Add(METDiTauDeltaPhiQCD_800to1000_);
  METDiTauDeltaPhiQCD_->Add(METDiTauDeltaPhiQCD_1000toInf_);

  METDiMuDeltaPhiCanvasQCD->cd();
  METDiMuDeltaPhiQCD_->Add(METDiMuDeltaPhiQCD_15to20_);
  METDiMuDeltaPhiQCD_->Add(METDiMuDeltaPhiQCD_20to30_);
  METDiMuDeltaPhiQCD_->Add(METDiMuDeltaPhiQCD_30to50_);
  METDiMuDeltaPhiQCD_->Add(METDiMuDeltaPhiQCD_50to80_);
  METDiMuDeltaPhiQCD_->Add(METDiMuDeltaPhiQCD_80to120_);
  METDiMuDeltaPhiQCD_->Add(METDiMuDeltaPhiQCD_120to170_);
  METDiMuDeltaPhiQCD_->Add(METDiMuDeltaPhiQCD_170to300_);
  METDiMuDeltaPhiQCD_->Add(METDiMuDeltaPhiQCD_300to470_);
  METDiMuDeltaPhiQCD_->Add(METDiMuDeltaPhiQCD_470to600_);
  METDiMuDeltaPhiQCD_->Add(METDiMuDeltaPhiQCD_600to800_);
  METDiMuDeltaPhiQCD_->Add(METDiMuDeltaPhiQCD_800to1000_);
  METDiMuDeltaPhiQCD_->Add(METDiMuDeltaPhiQCD_1000toInf_);

  DiTaudRCanvasQCD->cd();
  DiTaudRQCD_->Add(DiTaudRQCD_15to20_);
  DiTaudRQCD_->Add(DiTaudRQCD_20to30_);
  DiTaudRQCD_->Add(DiTaudRQCD_30to50_);
  DiTaudRQCD_->Add(DiTaudRQCD_50to80_);
  DiTaudRQCD_->Add(DiTaudRQCD_80to120_);
  DiTaudRQCD_->Add(DiTaudRQCD_120to170_);
  DiTaudRQCD_->Add(DiTaudRQCD_170to300_);
  DiTaudRQCD_->Add(DiTaudRQCD_300to470_);
  DiTaudRQCD_->Add(DiTaudRQCD_470to600_);
  DiTaudRQCD_->Add(DiTaudRQCD_600to800_);
  DiTaudRQCD_->Add(DiTaudRQCD_800to1000_);
  DiTaudRQCD_->Add(DiTaudRQCD_1000toInf_);

  DiTauMassSmallerdRCanvasQCD->cd();
  DiTauMassSmallerdRQCD_->Add(DiTauMassSmallerdRQCD_15to20_);
  DiTauMassSmallerdRQCD_->Add(DiTauMassSmallerdRQCD_20to30_);
  DiTauMassSmallerdRQCD_->Add(DiTauMassSmallerdRQCD_30to50_);
  DiTauMassSmallerdRQCD_->Add(DiTauMassSmallerdRQCD_50to80_);
  DiTauMassSmallerdRQCD_->Add(DiTauMassSmallerdRQCD_80to120_);
  DiTauMassSmallerdRQCD_->Add(DiTauMassSmallerdRQCD_120to170_);
  DiTauMassSmallerdRQCD_->Add(DiTauMassSmallerdRQCD_170to300_);
  DiTauMassSmallerdRQCD_->Add(DiTauMassSmallerdRQCD_300to470_);
  DiTauMassSmallerdRQCD_->Add(DiTauMassSmallerdRQCD_470to600_);
  DiTauMassSmallerdRQCD_->Add(DiTauMassSmallerdRQCD_600to800_);
  DiTauMassSmallerdRQCD_->Add(DiTauMassSmallerdRQCD_800to1000_);
  DiTauMassSmallerdRQCD_->Add(DiTauMassSmallerdRQCD_1000toInf_);

  HighestCSVInclJetCanvasQCD->cd();
  HighestCSVInclJetQCD_->Add(HighestCSVInclJetQCD_15to20_);
  HighestCSVInclJetQCD_->Add(HighestCSVInclJetQCD_20to30_);
  HighestCSVInclJetQCD_->Add(HighestCSVInclJetQCD_30to50_);
  HighestCSVInclJetQCD_->Add(HighestCSVInclJetQCD_50to80_);
  HighestCSVInclJetQCD_->Add(HighestCSVInclJetQCD_80to120_);
  HighestCSVInclJetQCD_->Add(HighestCSVInclJetQCD_120to170_);
  HighestCSVInclJetQCD_->Add(HighestCSVInclJetQCD_170to300_);
  HighestCSVInclJetQCD_->Add(HighestCSVInclJetQCD_300to470_);
  HighestCSVInclJetQCD_->Add(HighestCSVInclJetQCD_470to600_);
  HighestCSVInclJetQCD_->Add(HighestCSVInclJetQCD_600to800_);
  HighestCSVInclJetQCD_->Add(HighestCSVInclJetQCD_800to1000_);
  HighestCSVInclJetQCD_->Add(HighestCSVInclJetQCD_1000toInf_);


  outFile->cd();
  TDirectory *QCDCombined = outFile->mkdir("QCDCombined");
  QCDCombined->cd();
  NMedIsoTausWithMu3QCD_->Write();
  InvMassTauHadMu3QCD_->Write();
  PtTauHadMu3QCD_->Write();
  InvMassUpsilonRangeQCD_->Write();
  InvMassZPeakRangeQCD_->Write();
  InvMassFullRangeQCD_->Write();
  InvMassDiMuBarrBarrQCD_->Write();
  InvMassDiMuBarrEndcQCD_->Write();
  InvMassDiMuEndcEndcQCD_->Write();
  Mu1PtQCD_->Write();
  Mu2PtQCD_->Write();
  DiMuPtQCD_->Write();
  Mu1EtaQCD_->Write();
  Mu2EtaQCD_->Write();
  DiTauEtaQCD_->Write();
  DiTauPhiQCD_->Write();
  DiMuEtaQCD_->Write();
  DiMudRQCD_->Write();
  DiMuPhiQCD_->Write();
  EtMETQCD_->Write();
  DiTauDiMuMassQCD_->Write();
  DiMuDiTauDeltaPhiQCD_->Write();
  METDiTauDeltaPhiQCD_->Write();
  METDiMuDeltaPhiQCD_->Write();
  DiTaudRQCD_->Write();
  DiTauMassSmallerdRQCD_->Write();
  HighestCSVInclJetQCD_->Write();

cout << "Combined QCD" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the DY Combined Canvas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *NMedIsoTausWithMu3CanvasDY = new TCanvas ("NMedIsoTausWithMu3CanvasDY","",600,600); 
  TCanvas *InvMassTauHadMu3CanvasDY = new TCanvas ("InvMassTauHadMu3CanvasDY","",600,600); 
  TCanvas *PtTauHadMu3CanvasDY = new TCanvas ("PtTauHadMu3CanvasDY","",600,600); 
  TCanvas *InvMassUpsilonRangeCanvasDY = new TCanvas ("InvMassUpsilonRangeCanvasDY","",600,600); 
  TCanvas *InvMassZPeakRangeCanvasDY = new TCanvas ("InvMassZPeakRangeCanvasDY","",600,600); 
  TCanvas *InvMassFullRangeCanvasDY = new TCanvas ("InvMassFullRangeCanvasDY","",600,600); 
  TCanvas *InvMassDiMuBarrBarrCanvasDY = new TCanvas ("InvMassDiMuBarrBarrCanvasDY","",600,600); 
  TCanvas *InvMassDiMuBarrEndcCanvasDY = new TCanvas ("InvMassDiMuBarrEndcCanvasDY","",600,600); 
  TCanvas *InvMassDiMuEndcEndcCanvasDY = new TCanvas ("InvMassDiMuEndcEndcCanvasDY","",600,600); 
  TCanvas *Mu1PtCanvasDY = new TCanvas ("Mu1PtCanvasDY","",600,600); 
  TCanvas *Mu2PtCanvasDY = new TCanvas ("Mu2PtCanvasDY","",600,600); 
  TCanvas *DiMuPtCanvasDY = new TCanvas ("DiMuPtCanvasDY","",600,600); 
  TCanvas *Mu1EtaCanvasDY = new TCanvas ("Mu1EtaCanvasDY","",600,600); 
  TCanvas *Mu2EtaCanvasDY = new TCanvas ("Mu2EtaCanvasDY","",600,600); 
  TCanvas *DiTauEtaCanvasDY = new TCanvas ("DiTauEtaCanvasDY","",600,600); 
  TCanvas *DiTauPhiCanvasDY = new TCanvas ("DiTauPhiCanvasDY","",600,600); 
  TCanvas *DiMuEtaCanvasDY = new TCanvas ("DiMuEtaCanvasDY","",600,600); 
  TCanvas *DiMudRCanvasDY = new TCanvas ("DiMudRCanvasDY","",600,600); 
  TCanvas *DiMuPhiCanvasDY = new TCanvas ("DiMuPhiCanvasDY","",600,600); 
  TCanvas *EtMETCanvasDY = new TCanvas ("EtMETCanvasDY","",600,600); 
  TCanvas *DiTauDiMuMassCanvasDY = new TCanvas ("DiTauDiMuMassCanvasDY","",600,600); 
  TCanvas *DiMuDiTauDeltaPhiCanvasDY = new TCanvas ("DiMuDiTauDeltaPhiCanvasDY","",600,600); 
  TCanvas *METDiTauDeltaPhiCanvasDY = new TCanvas ("METDiTauDeltaPhiCanvasDY","",600,600); 
  TCanvas *METDiMuDeltaPhiCanvasDY = new TCanvas ("METDiMuDeltaPhiCanvasDY","",600,600); 
  TCanvas *DiTaudRCanvasDY = new TCanvas ("DiTaudRCanvasDY","",600,600); 
  TCanvas *DiTauMassSmallerdRCanvasDY = new TCanvas ("DiTauMassSmallerdRCanvasDY","",600,600); 
  TCanvas *HighestCSVInclJetCanvasDY = new TCanvas ("HighestCSVInclJetCanvasDY","",600,600); 

  TH1F *NMedIsoTausWithMu3DY_ = new TH1F ("NMedIsoTausWithMu3DY","", NMedIsoTausWithMu3DYL_->GetNbinsX(), NMedIsoTausWithMu3DYL_->GetXaxis()->GetXmin(), NMedIsoTausWithMu3DYL_->GetXaxis()->GetXmax() );
  TH1F *InvMassTauHadMu3DY_ = new TH1F ("InvMassTauHadMu3DY","",InvMassTauHadMu3DYL_->GetNbinsX(), InvMassTauHadMu3DYL_->GetXaxis()->GetXmin(), InvMassTauHadMu3DYL_->GetXaxis()->GetXmax() );
  TH1F *PtTauHadMu3DY_ = new TH1F ("PtTauHadMu3DY","",PtTauHadMu3DYL_->GetNbinsX(), PtTauHadMu3DYL_->GetXaxis()->GetXmin(), PtTauHadMu3DYL_->GetXaxis()->GetXmax() );
  TH1F *InvMassUpsilonRangeDY_ = new TH1F ("InvMassUpsilonRangeDY","",InvMassUpsilonRangeDYL_->GetNbinsX(), InvMassUpsilonRangeDYL_->GetXaxis()->GetXmin(), InvMassUpsilonRangeDYL_->GetXaxis()->GetXmax() );
  TH1F *InvMassZPeakRangeDY_ = new TH1F ("InvMassZPeakRangeDY","",InvMassZPeakRangeDYL_->GetNbinsX(), InvMassZPeakRangeDYL_->GetXaxis()->GetXmin(), InvMassZPeakRangeDYL_->GetXaxis()->GetXmax() );
  TH1F *InvMassFullRangeDY_ = new TH1F ("InvMassFullRangeDY","",InvMassFullRangeDYL_->GetNbinsX(), InvMassFullRangeDYL_->GetXaxis()->GetXmin(), InvMassFullRangeDYL_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuBarrBarrDY_ = new TH1F ("InvMassDiMuBarrBarrDY","",InvMassDiMuBarrBarrDYL_->GetNbinsX(), InvMassDiMuBarrBarrDYL_->GetXaxis()->GetXmin(), InvMassDiMuBarrBarrDYL_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuBarrEndcDY_ = new TH1F ("InvMassDiMuBarrEndcDY","",InvMassDiMuBarrEndcDYL_->GetNbinsX(), InvMassDiMuBarrEndcDYL_->GetXaxis()->GetXmin(), InvMassDiMuBarrEndcDYL_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuEndcEndcDY_ = new TH1F ("InvMassDiMuEndcEndcDY","",InvMassDiMuEndcEndcDYL_->GetNbinsX(), InvMassDiMuEndcEndcDYL_->GetXaxis()->GetXmin(), InvMassDiMuEndcEndcDYL_->GetXaxis()->GetXmax() );
  TH1F *Mu1PtDY_ = new TH1F ("Mu1PtDY","",Mu1PtDYL_->GetNbinsX(), Mu1PtDYL_->GetXaxis()->GetXmin(), Mu1PtDYL_->GetXaxis()->GetXmax() );
  TH1F *Mu2PtDY_ = new TH1F ("Mu2PtDY","",Mu2PtDYL_->GetNbinsX(), Mu2PtDYL_->GetXaxis()->GetXmin(), Mu2PtDYL_->GetXaxis()->GetXmax() );
  TH1F *DiMuPtDY_ = new TH1F ("DiMuPtDY","",DiMuPtDYL_->GetNbinsX(), DiMuPtDYL_->GetXaxis()->GetXmin(), DiMuPtDYL_->GetXaxis()->GetXmax() );
  TH1F *Mu1EtaDY_ = new TH1F ("Mu1EtaDY","",Mu1EtaDYL_->GetNbinsX(), Mu1EtaDYL_->GetXaxis()->GetXmin(), Mu1EtaDYL_->GetXaxis()->GetXmax() );
  TH1F *Mu2EtaDY_ = new TH1F ("Mu2EtaDY","",Mu2EtaDYL_->GetNbinsX(), Mu2EtaDYL_->GetXaxis()->GetXmin(), Mu2EtaDYL_->GetXaxis()->GetXmax() );
  TH1F *DiTauEtaDY_ = new TH1F ("DiTauEtaDY","",DiTauEtaDYL_->GetNbinsX(), DiTauEtaDYL_->GetXaxis()->GetXmin(), DiTauEtaDYL_->GetXaxis()->GetXmax() );
  TH1F *DiTauPhiDY_ = new TH1F ("DiTauPhiDY","",DiTauPhiDYL_->GetNbinsX(), DiTauPhiDYL_->GetXaxis()->GetXmin(), DiTauPhiDYL_->GetXaxis()->GetXmax() );
  TH1F *DiMuEtaDY_ = new TH1F ("DiMuEtaDY","",DiMuEtaDYL_->GetNbinsX(), DiMuEtaDYL_->GetXaxis()->GetXmin(), DiMuEtaDYL_->GetXaxis()->GetXmax() );
  TH1F *DiMudRDY_ = new TH1F ("DiMudRDY","",DiMudRDYL_->GetNbinsX(), DiMudRDYL_->GetXaxis()->GetXmin(), DiMudRDYL_->GetXaxis()->GetXmax() );
  TH1F *DiMuPhiDY_ = new TH1F ("DiMuPhiDY","",DiMuPhiDYL_->GetNbinsX(), DiMuPhiDYL_->GetXaxis()->GetXmin(), DiMuPhiDYL_->GetXaxis()->GetXmax() );
  TH1F *EtMETDY_ = new TH1F ("EtMETDY","",EtMETDYL_->GetNbinsX(), EtMETDYL_->GetXaxis()->GetXmin(), EtMETDYL_->GetXaxis()->GetXmax() );
  TH1F *DiTauDiMuMassDY_ = new TH1F ("DiTauDiMuMassDY","",DiTauDiMuMassDYL_->GetNbinsX(), DiTauDiMuMassDYL_->GetXaxis()->GetXmin(), DiTauDiMuMassDYL_->GetXaxis()->GetXmax() );
  TH1F *DiMuDiTauDeltaPhiDY_ = new TH1F ("DiMuDiTauDeltaPhiDY","",DiMuDiTauDeltaPhiDYL_->GetNbinsX(), DiMuDiTauDeltaPhiDYL_->GetXaxis()->GetXmin(), DiMuDiTauDeltaPhiDYL_->GetXaxis()->GetXmax() );
  TH1F *METDiTauDeltaPhiDY_ = new TH1F ("METDiTauDeltaPhiDY","",METDiTauDeltaPhiDYL_->GetNbinsX(), METDiTauDeltaPhiDYL_->GetXaxis()->GetXmin(), METDiTauDeltaPhiDYL_->GetXaxis()->GetXmax() );
  TH1F *METDiMuDeltaPhiDY_ = new TH1F ("METDiMuDeltaPhiDY","",METDiMuDeltaPhiDYL_->GetNbinsX(), METDiMuDeltaPhiDYL_->GetXaxis()->GetXmin(), METDiMuDeltaPhiDYL_->GetXaxis()->GetXmax() );
  TH1F *DiTaudRDY_ = new TH1F ("DiTaudRDY","",DiTaudRDYL_->GetNbinsX(), DiTaudRDYL_->GetXaxis()->GetXmin(), DiTaudRDYL_->GetXaxis()->GetXmax() );
  TH1F *DiTauMassSmallerdRDY_ = new TH1F ("DiTauMassSmallerdRDY","",DiTauMassSmallerdRDYL_->GetNbinsX(), DiTauMassSmallerdRDYL_->GetXaxis()->GetXmin(), DiTauMassSmallerdRDYL_->GetXaxis()->GetXmax() );
  TH1F *HighestCSVInclJetDY_ = new TH1F ("HighestCSVInclJetDY","",HighestCSVInclJetDYL_->GetNbinsX(), HighestCSVInclJetDYL_->GetXaxis()->GetXmin(), HighestCSVInclJetDYL_->GetXaxis()->GetXmax() );

  NMedIsoTausWithMu3CanvasDY->cd();
  NMedIsoTausWithMu3DY_->Add(NMedIsoTausWithMu3DYL_);
  NMedIsoTausWithMu3DY_->Add(NMedIsoTausWithMu3DYH_);
//  NMedIsoTausWithMu3DY_->Add(NMedIsoTausWithMu3Up_);
//  NMedIsoTausWithMu3DY_->Add(NMedIsoTausWithMu3JPsi_);

  InvMassTauHadMu3CanvasDY->cd();
  InvMassTauHadMu3DY_->Add(InvMassTauHadMu3DYL_);
  InvMassTauHadMu3DY_->Add(InvMassTauHadMu3DYH_);
//  InvMassTauHadMu3DY_->Add(InvMassTauHadMu3Up_);
//  InvMassTauHadMu3DY_->Add(InvMassTauHadMu3JPsi_);

  PtTauHadMu3CanvasDY->cd();
  PtTauHadMu3DY_->Add(PtTauHadMu3DYL_);
  PtTauHadMu3DY_->Add(PtTauHadMu3DYH_);
//  PtTauHadMu3DY_->Add(PtTauHadMu3Up_);
//  PtTauHadMu3DY_->Add(PtTauHadMu3JPsi_);

  InvMassUpsilonRangeCanvasDY->cd();
  InvMassUpsilonRangeDY_->Add(InvMassUpsilonRangeDYL_);
  InvMassUpsilonRangeDY_->Add(InvMassUpsilonRangeDYH_);
//  InvMassUpsilonRangeDY_->Add(InvMassUpsilonRangeUp_);
//  InvMassUpsilonRangeDY_->Add(InvMassUpsilonRangeJPsi_);

  InvMassZPeakRangeCanvasDY->cd();
  InvMassZPeakRangeDY_->Add(InvMassZPeakRangeDYL_);
  InvMassZPeakRangeDY_->Add(InvMassZPeakRangeDYH_);
//  InvMassZPeakRangeDY_->Add(InvMassZPeakRangeUp_);
//  InvMassZPeakRangeDY_->Add(InvMassZPeakRangeJPsi_);

  InvMassFullRangeCanvasDY->cd();
  InvMassFullRangeDY_->Add(InvMassFullRangeDYL_);
  InvMassFullRangeDY_->Add(InvMassFullRangeDYH_);
//  InvMassFullRangeDY_->Add(InvMassFullRangeUp_);
//  InvMassFullRangeDY_->Add(InvMassFullRangeJPsi_);

  InvMassDiMuBarrBarrCanvasDY->cd();
  InvMassDiMuBarrBarrDY_->Add(InvMassDiMuBarrBarrDYL_);
  InvMassDiMuBarrBarrDY_->Add(InvMassDiMuBarrBarrDYH_);
//  InvMassDiMuBarrBarrDY_->Add(InvMassDiMuBarrBarrUp_);
//  InvMassDiMuBarrBarrDY_->Add(InvMassDiMuBarrBarrJPsi_);

  InvMassDiMuBarrEndcCanvasDY->cd();
  InvMassDiMuBarrEndcDY_->Add(InvMassDiMuBarrEndcDYL_);
  InvMassDiMuBarrEndcDY_->Add(InvMassDiMuBarrEndcDYH_);
//  InvMassDiMuBarrEndcDY_->Add(InvMassDiMuBarrEndcUp_);
//  InvMassDiMuBarrEndcDY_->Add(InvMassDiMuBarrEndcJPsi_);

  InvMassDiMuEndcEndcCanvasDY->cd();
  InvMassDiMuEndcEndcDY_->Add(InvMassDiMuEndcEndcDYL_);
  InvMassDiMuEndcEndcDY_->Add(InvMassDiMuEndcEndcDYH_);
//  InvMassDiMuEndcEndcDY_->Add(InvMassDiMuEndcEndcUp_);
//  InvMassDiMuEndcEndcDY_->Add(InvMassDiMuEndcEndcJPsi_);

  Mu1PtCanvasDY->cd();
  Mu1PtDY_->Add(Mu1PtDYL_);
  Mu1PtDY_->Add(Mu1PtDYH_);
//  Mu1PtDY_->Add(Mu1PtUp_);
//  Mu1PtDY_->Add(Mu1PtJPsi_);

  Mu2PtCanvasDY->cd();
  Mu2PtDY_->Add(Mu2PtDYL_);
  Mu2PtDY_->Add(Mu2PtDYH_);
//  Mu2PtDY_->Add(Mu2PtUp_);
//  Mu2PtDY_->Add(Mu2PtJPsi_);

  DiMuPtCanvasDY->cd();
  DiMuPtDY_->Add(DiMuPtDYL_);
  DiMuPtDY_->Add(DiMuPtDYH_);
//  DiMuPtDY_->Add(DiMuPtUp_);
//  DiMuPtDY_->Add(DiMuPtJPsi_);

  Mu1EtaCanvasDY->cd();
  Mu1EtaDY_->Add(Mu1EtaDYL_);
  Mu1EtaDY_->Add(Mu1EtaDYH_);
//  Mu1EtaDY_->Add(Mu1EtaUp_);
//  Mu1EtaDY_->Add(Mu1EtaJPsi_);

  Mu2EtaCanvasDY->cd();
  Mu2EtaDY_->Add(Mu2EtaDYL_);
  Mu2EtaDY_->Add(Mu2EtaDYH_);
//  Mu2EtaDY_->Add(Mu2EtaUp_);
//  Mu2EtaDY_->Add(Mu2EtaJPsi_);

  DiTauEtaCanvasDY->cd();
  DiTauEtaDY_->Add(DiTauEtaDYL_);
  DiTauEtaDY_->Add(DiTauEtaDYH_);
//  DiTauEtaDY_->Add(DiTauEtaUp_);
//  DiTauEtaDY_->Add(DiTauEtaJPsi_);

  DiTauPhiCanvasDY->cd();
  DiTauPhiDY_->Add(DiTauPhiDYL_);
  DiTauPhiDY_->Add(DiTauPhiDYH_);
//  DiTauPhiDY_->Add(DiTauPhiUp_);
//  DiTauPhiDY_->Add(DiTauPhiJPsi_);

  DiMuEtaCanvasDY->cd();
  DiMuEtaDY_->Add(DiMuEtaDYL_);
  DiMuEtaDY_->Add(DiMuEtaDYH_);
//  DiMuEtaDY_->Add(DiMuEtaUp_);
//  DiMuEtaDY_->Add(DiMuEtaJPsi_);

  DiMudRCanvasDY->cd();
  DiMudRDY_->Add(DiMudRDYL_);
  DiMudRDY_->Add(DiMudRDYH_);
//  DiMudRDY_->Add(DiMudRUp_);
//  DiMudRDY_->Add(DiMudRJPsi_);

  DiMuPhiCanvasDY->cd();
  DiMuPhiDY_->Add(DiMuPhiDYL_);
  DiMuPhiDY_->Add(DiMuPhiDYH_);
//  DiMuPhiDY_->Add(DiMuPhiUp_);
//  DiMuPhiDY_->Add(DiMuPhiJPsi_);

  EtMETCanvasDY->cd();
  EtMETDY_->Add(EtMETDYL_);
  EtMETDY_->Add(EtMETDYH_);
//  EtMETDY_->Add(EtMETUp_);
//  EtMETDY_->Add(EtMETJPsi_);

  DiTauDiMuMassCanvasDY->cd();
  DiTauDiMuMassDY_->Add(DiTauDiMuMassDYL_);
  DiTauDiMuMassDY_->Add(DiTauDiMuMassDYH_);
//  DiTauDiMuMassDY_->Add(DiTauDiMuMassUp_);
//  DiTauDiMuMassDY_->Add(DiTauDiMuMassJPsi_);

  DiMuDiTauDeltaPhiCanvasDY->cd();
  DiMuDiTauDeltaPhiDY_->Add(DiMuDiTauDeltaPhiDYL_);
  DiMuDiTauDeltaPhiDY_->Add(DiMuDiTauDeltaPhiDYH_);
//  DiMuDiTauDeltaPhiDY_->Add(DiMuDiTauDeltaPhiUp_);
//  DiMuDiTauDeltaPhiDY_->Add(DiMuDiTauDeltaPhiJPsi_);

  METDiTauDeltaPhiCanvasDY->cd();
  METDiTauDeltaPhiDY_->Add(METDiTauDeltaPhiDYL_);
  METDiTauDeltaPhiDY_->Add(METDiTauDeltaPhiDYH_);
//  METDiTauDeltaPhiDY_->Add(METDiTauDeltaPhiUp_);
//  METDiTauDeltaPhiDY_->Add(METDiTauDeltaPhiJPsi_);

  METDiMuDeltaPhiCanvasDY->cd();
  METDiMuDeltaPhiDY_->Add(METDiMuDeltaPhiDYL_);
  METDiMuDeltaPhiDY_->Add(METDiMuDeltaPhiDYH_);
//  METDiMuDeltaPhiDY_->Add(METDiMuDeltaPhiUp_);
//  METDiMuDeltaPhiDY_->Add(METDiMuDeltaPhiJPsi_);


  DiTaudRCanvasDY->cd();
  DiTaudRDY_->Add(DiTaudRDYL_);
  DiTaudRDY_->Add(DiTaudRDYH_);
//  DiTaudRDY_->Add(DiTaudRUp_);
//  DiTaudRDY_->Add(DiTaudRJPsi_);

  DiTauMassSmallerdRCanvasDY->cd();
  DiTauMassSmallerdRDY_->Add(DiTauMassSmallerdRDYL_);
  DiTauMassSmallerdRDY_->Add(DiTauMassSmallerdRDYH_);
//  DiTauMassSmallerdRDY_->Add(DiTauMassSmallerdRUp_);
//  DiTauMassSmallerdRDY_->Add(DiTauMassSmallerdRJPsi_);

  HighestCSVInclJetCanvasDY->cd();
  HighestCSVInclJetDY_->Add(HighestCSVInclJetDYL_);
  HighestCSVInclJetDY_->Add(HighestCSVInclJetDYH_);
//  HighestCSVInclJetDY_->Add(HighestCSVInclJetUp_);
//  HighestCSVInclJetDY_->Add(HighestCSVInclJetJPsi_);

  outFile->cd();
  TDirectory *DYCombined = outFile->mkdir("DYCombined");
  DYCombined->cd();
  NMedIsoTausWithMu3DY_->Write();
  InvMassTauHadMu3DY_->Write();
  PtTauHadMu3DY_->Write();
  InvMassUpsilonRangeDY_->Write();
  InvMassZPeakRangeDY_->Write();
  InvMassFullRangeDY_->Write();
  InvMassDiMuBarrBarrDY_->Write();
  InvMassDiMuBarrEndcDY_->Write();
  InvMassDiMuEndcEndcDY_->Write();
  Mu1PtDY_->Write();
  Mu2PtDY_->Write();
  DiMuPtDY_->Write();
  Mu1EtaDY_->Write();
  Mu2EtaDY_->Write();
  DiTauEtaDY_->Write();
  DiTauPhiDY_->Write();
  DiMuEtaDY_->Write();
  DiMudRDY_->Write();
  DiMuPhiDY_->Write();
  EtMETDY_->Write();
  DiTauDiMuMassDY_->Write();
  DiMuDiTauDeltaPhiDY_->Write();
  METDiTauDeltaPhiDY_->Write();
  METDiMuDeltaPhiDY_->Write();
  DiTaudRDY_->Write();
  DiTauMassSmallerdRDY_->Write();
  HighestCSVInclJetDY_->Write();

cout << "Combined DY" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the DiBoson Combined Canvas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *NMedIsoTausWithMu3CanvasDiBoson = new TCanvas ("NMedIsoTausWithMu3CanvasDiBoson","",600,600); 
  TCanvas *InvMassTauHadMu3CanvasDiBoson = new TCanvas ("InvMassTauHadMu3CanvasDiBoson","",600,600); 
  TCanvas *PtTauHadMu3CanvasDiBoson = new TCanvas ("PtTauHadMu3CanvasDiBoson","",600,600); 
  TCanvas *InvMassUpsilonRangeCanvasDiBoson = new TCanvas ("InvMassUpsilonRangeCanvasDiBoson","",600,600); 
  TCanvas *InvMassZPeakRangeCanvasDiBoson = new TCanvas ("InvMassZPeakRangeCanvasDiBoson","",600,600); 
  TCanvas *InvMassFullRangeCanvasDiBoson = new TCanvas ("InvMassFullRangeCanvasDiBoson","",600,600); 
  TCanvas *InvMassDiMuBarrBarrCanvasDiBoson = new TCanvas ("InvMassDiMuBarrBarrCanvasDiBoson","",600,600); 
  TCanvas *InvMassDiMuBarrEndcCanvasDiBoson = new TCanvas ("InvMassDiMuBarrEndcCanvasDiBoson","",600,600); 
  TCanvas *InvMassDiMuEndcEndcCanvasDiBoson = new TCanvas ("InvMassDiMuEndcEndcCanvasDiBoson","",600,600); 
  TCanvas *Mu1PtCanvasDiBoson = new TCanvas ("Mu1PtCanvasDiBoson","",600,600); 
  TCanvas *Mu2PtCanvasDiBoson = new TCanvas ("Mu2PtCanvasDiBoson","",600,600); 
  TCanvas *DiMuPtCanvasDiBoson = new TCanvas ("DiMuPtCanvasDiBoson","",600,600); 
  TCanvas *Mu1EtaCanvasDiBoson = new TCanvas ("Mu1EtaCanvasDiBoson","",600,600); 
  TCanvas *Mu2EtaCanvasDiBoson = new TCanvas ("Mu2EtaCanvasDiBoson","",600,600); 
  TCanvas *DiTauEtaCanvasDiBoson = new TCanvas ("DiTauEtaCanvasDiBoson","",600,600); 
  TCanvas *DiTauPhiCanvasDiBoson = new TCanvas ("DiTauPhiCanvasDiBoson","",600,600); 
  TCanvas *DiMuEtaCanvasDiBoson = new TCanvas ("DiMuEtaCanvasDiBoson","",600,600); 
  TCanvas *DiMudRCanvasDiBoson = new TCanvas ("DiMudRCanvasDiBoson","",600,600); 
  TCanvas *DiMuPhiCanvasDiBoson = new TCanvas ("DiMuPhiCanvasDiBoson","",600,600); 
  TCanvas *EtMETCanvasDiBoson = new TCanvas ("EtMETCanvasDiBoson","",600,600); 
  TCanvas *DiTauDiMuMassCanvasDiBoson = new TCanvas ("DiTauDiMuMassCanvasDiBoson","",600,600); 
  TCanvas *DiMuDiTauDeltaPhiCanvasDiBoson = new TCanvas ("DiMuDiTauDeltaPhiCanvasDiBoson","",600,600); 
  TCanvas *METDiTauDeltaPhiCanvasDiBoson = new TCanvas ("METDiTauDeltaPhiCanvasDiBoson","",600,600); 
  TCanvas *METDiMuDeltaPhiCanvasDiBoson = new TCanvas ("METDiMuDeltaPhiCanvasDiBoson","",600,600); 
  TCanvas *DiTaudRCanvasDiBoson = new TCanvas ("DiTaudRCanvasDiBoson","",600,600); 
  TCanvas *DiTauMassSmallerdRCanvasDiBoson = new TCanvas ("DiTauMassSmallerdRCanvasDiBoson","",600,600); 
  TCanvas *HighestCSVInclJetCanvasDiBoson = new TCanvas ("HighestCSVInclJetCanvasDiBoson","",600,600); 

  TH1F *NMedIsoTausWithMu3DiBoson_ = new TH1F ("NMedIsoTausWithMu3DiBoson","", NMedIsoTausWithMu3WJAmac_->GetNbinsX(), NMedIsoTausWithMu3WJAmac_->GetXaxis()->GetXmin(), NMedIsoTausWithMu3WJAmac_->GetXaxis()->GetXmax() );
  TH1F *InvMassTauHadMu3DiBoson_ = new TH1F ("InvMassTauHadMu3DiBoson","",InvMassTauHadMu3WJAmac_->GetNbinsX(), InvMassTauHadMu3WJAmac_->GetXaxis()->GetXmin(), InvMassTauHadMu3WJAmac_->GetXaxis()->GetXmax() );
  TH1F *PtTauHadMu3DiBoson_ = new TH1F ("PtTauHadMu3DiBoson","",PtTauHadMu3WJAmac_->GetNbinsX(), PtTauHadMu3WJAmac_->GetXaxis()->GetXmin(), PtTauHadMu3WJAmac_->GetXaxis()->GetXmax() );
  TH1F *InvMassUpsilonRangeDiBoson_ = new TH1F ("InvMassUpsilonRangeDiBoson","",InvMassUpsilonRangeWJAmac_->GetNbinsX(), InvMassUpsilonRangeWJAmac_->GetXaxis()->GetXmin(), InvMassUpsilonRangeWJAmac_->GetXaxis()->GetXmax() );
  TH1F *InvMassZPeakRangeDiBoson_ = new TH1F ("InvMassZPeakRangeDiBoson","",InvMassZPeakRangeWJAmac_->GetNbinsX(), InvMassZPeakRangeWJAmac_->GetXaxis()->GetXmin(), InvMassZPeakRangeWJAmac_->GetXaxis()->GetXmax() );
  TH1F *InvMassFullRangeDiBoson_ = new TH1F ("InvMassFullRangeDiBoson","",InvMassFullRangeWJAmac_->GetNbinsX(), InvMassFullRangeWJAmac_->GetXaxis()->GetXmin(), InvMassFullRangeWJAmac_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuBarrBarrDiBoson_ = new TH1F ("InvMassDiMuBarrBarrDiBoson","",InvMassDiMuBarrBarrWJAmac_->GetNbinsX(), InvMassDiMuBarrBarrWJAmac_->GetXaxis()->GetXmin(), InvMassDiMuBarrBarrWJAmac_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuBarrEndcDiBoson_ = new TH1F ("InvMassDiMuBarrEndcDiBoson","",InvMassDiMuBarrEndcWJAmac_->GetNbinsX(), InvMassDiMuBarrEndcWJAmac_->GetXaxis()->GetXmin(), InvMassDiMuBarrEndcWJAmac_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuEndcEndcDiBoson_ = new TH1F ("InvMassDiMuEndcEndcDiBoson","",InvMassDiMuEndcEndcWJAmac_->GetNbinsX(), InvMassDiMuEndcEndcWJAmac_->GetXaxis()->GetXmin(), InvMassDiMuEndcEndcWJAmac_->GetXaxis()->GetXmax() );
  TH1F *Mu1PtDiBoson_ = new TH1F ("Mu1PtDiBoson","",Mu1PtWJAmac_->GetNbinsX(), Mu1PtWJAmac_->GetXaxis()->GetXmin(), Mu1PtWJAmac_->GetXaxis()->GetXmax() );
  TH1F *Mu2PtDiBoson_ = new TH1F ("Mu2PtDiBoson","",Mu2PtWJAmac_->GetNbinsX(), Mu2PtWJAmac_->GetXaxis()->GetXmin(), Mu2PtWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DiMuPtDiBoson_ = new TH1F ("DiMuPtDiBoson","",DiMuPtWJAmac_->GetNbinsX(), DiMuPtWJAmac_->GetXaxis()->GetXmin(), DiMuPtWJAmac_->GetXaxis()->GetXmax() );
  TH1F *Mu1EtaDiBoson_ = new TH1F ("Mu1EtaDiBoson","",Mu1EtaWJAmac_->GetNbinsX(), Mu1EtaWJAmac_->GetXaxis()->GetXmin(), Mu1EtaWJAmac_->GetXaxis()->GetXmax() );
  TH1F *Mu2EtaDiBoson_ = new TH1F ("Mu2EtaDiBoson","",Mu2EtaWJAmac_->GetNbinsX(), Mu2EtaWJAmac_->GetXaxis()->GetXmin(), Mu2EtaWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DiTauEtaDiBoson_ = new TH1F ("DiTauEtaDiBoson","",DiTauEtaWJAmac_->GetNbinsX(), DiTauEtaWJAmac_->GetXaxis()->GetXmin(), DiTauEtaWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DiTauPhiDiBoson_ = new TH1F ("DiTauPhiDiBoson","",DiTauPhiWJAmac_->GetNbinsX(), DiTauPhiWJAmac_->GetXaxis()->GetXmin(), DiTauPhiWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DiMuEtaDiBoson_ = new TH1F ("DiMuEtaDiBoson","",DiMuEtaWJAmac_->GetNbinsX(), DiMuEtaWJAmac_->GetXaxis()->GetXmin(), DiMuEtaWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DiMudRDiBoson_ = new TH1F ("DiMudRDiBoson","",DiMudRWJAmac_->GetNbinsX(), DiMudRWJAmac_->GetXaxis()->GetXmin(), DiMudRWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DiMuPhiDiBoson_ = new TH1F ("DiMuPhiDiBoson","",DiMuPhiWJAmac_->GetNbinsX(), DiMuPhiWJAmac_->GetXaxis()->GetXmin(), DiMuPhiWJAmac_->GetXaxis()->GetXmax() );
  TH1F *EtMETDiBoson_ = new TH1F ("EtMETDiBoson","",EtMETWJAmac_->GetNbinsX(), EtMETWJAmac_->GetXaxis()->GetXmin(), EtMETWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DiTauDiMuMassDiBoson_ = new TH1F ("DiTauDiMuMassDiBoson","",DiTauDiMuMassWJAmac_->GetNbinsX(), DiTauDiMuMassWJAmac_->GetXaxis()->GetXmin(), DiTauDiMuMassWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DiMuDiTauDeltaPhiDiBoson_ = new TH1F ("DiMuDiTauDeltaPhiDiBoson","",DiMuDiTauDeltaPhiWJAmac_->GetNbinsX(), DiMuDiTauDeltaPhiWJAmac_->GetXaxis()->GetXmin(), DiMuDiTauDeltaPhiWJAmac_->GetXaxis()->GetXmax() );
  TH1F *METDiTauDeltaPhiDiBoson_ = new TH1F ("METDiTauDeltaPhiDiBoson","",METDiTauDeltaPhiWJAmac_->GetNbinsX(), METDiTauDeltaPhiWJAmac_->GetXaxis()->GetXmin(), METDiTauDeltaPhiWJAmac_->GetXaxis()->GetXmax() );
  TH1F *METDiMuDeltaPhiDiBoson_ = new TH1F ("METDiMuDeltaPhiDiBoson","",METDiMuDeltaPhiWJAmac_->GetNbinsX(), METDiMuDeltaPhiWJAmac_->GetXaxis()->GetXmin(), METDiMuDeltaPhiWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DiTaudRDiBoson_ = new TH1F ("DiTaudRDiBoson","",DiTaudRWJAmac_->GetNbinsX(), DiTaudRWJAmac_->GetXaxis()->GetXmin(), DiTaudRWJAmac_->GetXaxis()->GetXmax() );
  TH1F *DiTauMassSmallerdRDiBoson_ = new TH1F ("DiTauMassSmallerdRDiBoson","",DiTauMassSmallerdRWJAmac_->GetNbinsX(), DiTauMassSmallerdRWJAmac_->GetXaxis()->GetXmin(), DiTauMassSmallerdRWJAmac_->GetXaxis()->GetXmax() );
  TH1F *HighestCSVInclJetDiBoson_ = new TH1F ("HighestCSVInclJetDiBoson","",HighestCSVInclJetWJAmac_->GetNbinsX(), HighestCSVInclJetWJAmac_->GetXaxis()->GetXmin(), HighestCSVInclJetWJAmac_->GetXaxis()->GetXmax() );


  NMedIsoTausWithMu3CanvasDiBoson->cd();
//  NMedIsoTausWithMu3DiBoson_->Add(NMedIsoTausWithMu3VV_);
  NMedIsoTausWithMu3DiBoson_->Add(NMedIsoTausWithMu3WZ_);
  NMedIsoTausWithMu3DiBoson_->Add(NMedIsoTausWithMu3ZZ2L2Nu_);
  NMedIsoTausWithMu3DiBoson_->Add(NMedIsoTausWithMu3ZZ2L2Q_);
  NMedIsoTausWithMu3DiBoson_->Add(NMedIsoTausWithMu3ZZ4LAmac_);

  InvMassTauHadMu3CanvasDiBoson->cd();
//  InvMassTauHadMu3DiBoson_->Add(InvMassTauHadMu3VV_);
  InvMassTauHadMu3DiBoson_->Add(InvMassTauHadMu3WZ_);
  InvMassTauHadMu3DiBoson_->Add(InvMassTauHadMu3ZZ2L2Nu_);
  InvMassTauHadMu3DiBoson_->Add(InvMassTauHadMu3ZZ2L2Q_);
  InvMassTauHadMu3DiBoson_->Add(InvMassTauHadMu3ZZ4LAmac_);

  PtTauHadMu3CanvasDiBoson->cd();
//  PtTauHadMu3DiBoson_->Add(PtTauHadMu3VV_);
  PtTauHadMu3DiBoson_->Add(PtTauHadMu3WZ_);
  PtTauHadMu3DiBoson_->Add(PtTauHadMu3ZZ2L2Nu_);
  PtTauHadMu3DiBoson_->Add(PtTauHadMu3ZZ2L2Q_);
  PtTauHadMu3DiBoson_->Add(PtTauHadMu3ZZ4LAmac_);

  InvMassUpsilonRangeCanvasDiBoson->cd();
//  InvMassUpsilonRangeDiBoson_->Add(InvMassUpsilonRangeVV_);
  InvMassUpsilonRangeDiBoson_->Add(InvMassUpsilonRangeWZ_);
  InvMassUpsilonRangeDiBoson_->Add(InvMassUpsilonRangeZZ2L2Nu_);
  InvMassUpsilonRangeDiBoson_->Add(InvMassUpsilonRangeZZ2L2Q_);
  InvMassUpsilonRangeDiBoson_->Add(InvMassUpsilonRangeZZ4LAmac_);

  InvMassZPeakRangeCanvasDiBoson->cd();
//  InvMassZPeakRangeDiBoson_->Add(InvMassZPeakRangeVV_);
  InvMassZPeakRangeDiBoson_->Add(InvMassZPeakRangeWZ_);
  InvMassZPeakRangeDiBoson_->Add(InvMassZPeakRangeZZ2L2Nu_);
  InvMassZPeakRangeDiBoson_->Add(InvMassZPeakRangeZZ2L2Q_);
  InvMassZPeakRangeDiBoson_->Add(InvMassZPeakRangeZZ4LAmac_);

  InvMassFullRangeCanvasDiBoson->cd();
//  InvMassFullRangeDiBoson_->Add(InvMassFullRangeVV_);
  InvMassFullRangeDiBoson_->Add(InvMassFullRangeWZ_);
  InvMassFullRangeDiBoson_->Add(InvMassFullRangeZZ2L2Nu_);
  InvMassFullRangeDiBoson_->Add(InvMassFullRangeZZ2L2Q_);
  InvMassFullRangeDiBoson_->Add(InvMassFullRangeZZ4LAmac_);

  InvMassDiMuBarrBarrCanvasDiBoson->cd();
//  InvMassDiMuBarrBarrDiBoson_->Add(InvMassDiMuBarrBarrVV_);
  InvMassDiMuBarrBarrDiBoson_->Add(InvMassDiMuBarrBarrWZ_);
  InvMassDiMuBarrBarrDiBoson_->Add(InvMassDiMuBarrBarrZZ2L2Nu_);
  InvMassDiMuBarrBarrDiBoson_->Add(InvMassDiMuBarrBarrZZ2L2Q_);
  InvMassDiMuBarrBarrDiBoson_->Add(InvMassDiMuBarrBarrZZ4LAmac_);

  InvMassDiMuBarrEndcCanvasDiBoson->cd();
//  InvMassDiMuBarrEndcDiBoson_->Add(InvMassDiMuBarrEndcVV_);
  InvMassDiMuBarrEndcDiBoson_->Add(InvMassDiMuBarrEndcWZ_);
  InvMassDiMuBarrEndcDiBoson_->Add(InvMassDiMuBarrEndcZZ2L2Nu_);
  InvMassDiMuBarrEndcDiBoson_->Add(InvMassDiMuBarrEndcZZ2L2Q_);
  InvMassDiMuBarrEndcDiBoson_->Add(InvMassDiMuBarrEndcZZ4LAmac_);

  InvMassDiMuEndcEndcCanvasDiBoson->cd();
//  InvMassDiMuEndcEndcDiBoson_->Add(InvMassDiMuEndcEndcVV_);
  InvMassDiMuEndcEndcDiBoson_->Add(InvMassDiMuEndcEndcWZ_);
  InvMassDiMuEndcEndcDiBoson_->Add(InvMassDiMuEndcEndcZZ2L2Nu_);
  InvMassDiMuEndcEndcDiBoson_->Add(InvMassDiMuEndcEndcZZ2L2Q_);
  InvMassDiMuEndcEndcDiBoson_->Add(InvMassDiMuEndcEndcZZ4LAmac_);

  Mu1PtCanvasDiBoson->cd();
//  Mu1PtDiBoson_->Add(Mu1PtVV_);
  Mu1PtDiBoson_->Add(Mu1PtWZ_);
  Mu1PtDiBoson_->Add(Mu1PtZZ2L2Nu_);
  Mu1PtDiBoson_->Add(Mu1PtZZ2L2Q_);
  Mu1PtDiBoson_->Add(Mu1PtZZ4LAmac_);

  Mu2PtCanvasDiBoson->cd();
//  Mu2PtDiBoson_->Add(Mu2PtVV_);
  Mu2PtDiBoson_->Add(Mu2PtWZ_);
  Mu2PtDiBoson_->Add(Mu2PtZZ2L2Nu_);
  Mu2PtDiBoson_->Add(Mu2PtZZ2L2Q_);
  Mu2PtDiBoson_->Add(Mu2PtZZ4LAmac_);

  DiMuPtCanvasDiBoson->cd();
//  DiMuPtDiBoson_->Add(DiMuPtVV_);
  DiMuPtDiBoson_->Add(DiMuPtWZ_);
  DiMuPtDiBoson_->Add(DiMuPtZZ2L2Nu_);
  DiMuPtDiBoson_->Add(DiMuPtZZ2L2Q_);
  DiMuPtDiBoson_->Add(DiMuPtZZ4LAmac_);

  Mu1EtaCanvasDiBoson->cd();
//  Mu1EtaDiBoson_->Add(Mu1EtaVV_);
  Mu1EtaDiBoson_->Add(Mu1EtaWZ_);
  Mu1EtaDiBoson_->Add(Mu1EtaZZ2L2Nu_);
  Mu1EtaDiBoson_->Add(Mu1EtaZZ2L2Q_);
  Mu1EtaDiBoson_->Add(Mu1EtaZZ4LAmac_);

  Mu2EtaCanvasDiBoson->cd();
//  Mu2EtaDiBoson_->Add(Mu2EtaVV_);
  Mu2EtaDiBoson_->Add(Mu2EtaWZ_);
  Mu2EtaDiBoson_->Add(Mu2EtaZZ2L2Nu_);
  Mu2EtaDiBoson_->Add(Mu2EtaZZ2L2Q_);
  Mu2EtaDiBoson_->Add(Mu2EtaZZ4LAmac_);

  DiTauEtaCanvasDiBoson->cd();
//  DiTauEtaDiBoson_->Add(DiTauEtaVV_);
  DiTauEtaDiBoson_->Add(DiTauEtaWZ_);
  DiTauEtaDiBoson_->Add(DiTauEtaZZ2L2Nu_);
  DiTauEtaDiBoson_->Add(DiTauEtaZZ2L2Q_);
  DiTauEtaDiBoson_->Add(DiTauEtaZZ4LAmac_);

  DiTauPhiCanvasDiBoson->cd();
//  DiTauPhiDiBoson_->Add(DiTauPhiVV_);
  DiTauPhiDiBoson_->Add(DiTauPhiWZ_);
  DiTauPhiDiBoson_->Add(DiTauPhiZZ2L2Nu_);
  DiTauPhiDiBoson_->Add(DiTauPhiZZ2L2Q_);
  DiTauPhiDiBoson_->Add(DiTauPhiZZ4LAmac_);

  DiMuEtaCanvasDiBoson->cd();
//  DiMuEtaDiBoson_->Add(DiMuEtaVV_);
  DiMuEtaDiBoson_->Add(DiMuEtaWZ_);
  DiMuEtaDiBoson_->Add(DiMuEtaZZ2L2Nu_);
  DiMuEtaDiBoson_->Add(DiMuEtaZZ2L2Q_);
  DiMuEtaDiBoson_->Add(DiMuEtaZZ4LAmac_);

  DiMudRCanvasDiBoson->cd();
//  DiMudRDiBoson_->Add(DiMudRVV_);
  DiMudRDiBoson_->Add(DiMudRWZ_);
  DiMudRDiBoson_->Add(DiMudRZZ2L2Nu_);
  DiMudRDiBoson_->Add(DiMudRZZ2L2Q_);
  DiMudRDiBoson_->Add(DiMudRZZ4LAmac_);

  DiMuPhiCanvasDiBoson->cd();
//  DiMuPhiDiBoson_->Add(DiMuPhiVV_);
  DiMuPhiDiBoson_->Add(DiMuPhiWZ_);
  DiMuPhiDiBoson_->Add(DiMuPhiZZ2L2Nu_);
  DiMuPhiDiBoson_->Add(DiMuPhiZZ2L2Q_);
  DiMuPhiDiBoson_->Add(DiMuPhiZZ4LAmac_);

  EtMETCanvasDiBoson->cd();
//  EtMETDiBoson_->Add(EtMETVV_);
  EtMETDiBoson_->Add(EtMETWZ_);
  EtMETDiBoson_->Add(EtMETZZ2L2Nu_);
  EtMETDiBoson_->Add(EtMETZZ2L2Q_);
  EtMETDiBoson_->Add(EtMETZZ4LAmac_);

  DiTauDiMuMassCanvasDiBoson->cd();
//  DiTauDiMuMassDiBoson_->Add(DiTauDiMuMassVV_);
  DiTauDiMuMassDiBoson_->Add(DiTauDiMuMassWZ_);
  DiTauDiMuMassDiBoson_->Add(DiTauDiMuMassZZ2L2Nu_);
  DiTauDiMuMassDiBoson_->Add(DiTauDiMuMassZZ2L2Q_);
  DiTauDiMuMassDiBoson_->Add(DiTauDiMuMassZZ4LAmac_);

  DiMuDiTauDeltaPhiCanvasDiBoson->cd();
//  DiMuDiTauDeltaPhiDiBoson_->Add(DiMuDiTauDeltaPhiVV_);
  DiMuDiTauDeltaPhiDiBoson_->Add(DiMuDiTauDeltaPhiWZ_);
  DiMuDiTauDeltaPhiDiBoson_->Add(DiMuDiTauDeltaPhiZZ2L2Nu_);
  DiMuDiTauDeltaPhiDiBoson_->Add(DiMuDiTauDeltaPhiZZ2L2Q_);
  DiMuDiTauDeltaPhiDiBoson_->Add(DiMuDiTauDeltaPhiZZ4LAmac_);

  METDiTauDeltaPhiCanvasDiBoson->cd();
//  METDiTauDeltaPhiDiBoson_->Add(METDiTauDeltaPhiVV_);
  METDiTauDeltaPhiDiBoson_->Add(METDiTauDeltaPhiWZ_);
  METDiTauDeltaPhiDiBoson_->Add(METDiTauDeltaPhiZZ2L2Nu_);
  METDiTauDeltaPhiDiBoson_->Add(METDiTauDeltaPhiZZ2L2Q_);
  METDiTauDeltaPhiDiBoson_->Add(METDiTauDeltaPhiZZ4LAmac_);

  METDiMuDeltaPhiCanvasDiBoson->cd();
//  METDiMuDeltaPhiDiBoson_->Add(METDiMuDeltaPhiVV_);
  METDiMuDeltaPhiDiBoson_->Add(METDiMuDeltaPhiWZ_);
  METDiMuDeltaPhiDiBoson_->Add(METDiMuDeltaPhiZZ2L2Nu_);
  METDiMuDeltaPhiDiBoson_->Add(METDiMuDeltaPhiZZ2L2Q_);
  METDiMuDeltaPhiDiBoson_->Add(METDiMuDeltaPhiZZ4LAmac_);


  DiTaudRCanvasDiBoson->cd();
//  DiTaudRDiBoson_->Add(DiTaudRVV_);
  DiTaudRDiBoson_->Add(DiTaudRWZ_);
  DiTaudRDiBoson_->Add(DiTaudRZZ2L2Nu_);
  DiTaudRDiBoson_->Add(DiTaudRZZ2L2Q_);
  DiTaudRDiBoson_->Add(DiTaudRZZ4LAmac_);

  DiTauMassSmallerdRCanvasDiBoson->cd();
//  DiTauMassSmallerdRDiBoson_->Add(DiTauMassSmallerdRVV_);
  DiTauMassSmallerdRDiBoson_->Add(DiTauMassSmallerdRWZ_);
  DiTauMassSmallerdRDiBoson_->Add(DiTauMassSmallerdRZZ2L2Nu_);
  DiTauMassSmallerdRDiBoson_->Add(DiTauMassSmallerdRZZ2L2Q_);
  DiTauMassSmallerdRDiBoson_->Add(DiTauMassSmallerdRZZ4LAmac_);

  HighestCSVInclJetCanvasDiBoson->cd();
//  HighestCSVInclJetDiBoson_->Add(HighestCSVInclJetVV_);
  HighestCSVInclJetDiBoson_->Add(HighestCSVInclJetWZ_);
  HighestCSVInclJetDiBoson_->Add(HighestCSVInclJetZZ2L2Nu_);
  HighestCSVInclJetDiBoson_->Add(HighestCSVInclJetZZ2L2Q_);
  HighestCSVInclJetDiBoson_->Add(HighestCSVInclJetZZ4LAmac_);

  outFile->cd();
  TDirectory *DiBosonCombined = outFile->mkdir("DiBosonCombined");
  DiBosonCombined->cd();
  NMedIsoTausWithMu3DiBoson_->Write();
  InvMassTauHadMu3DiBoson_->Write();
  PtTauHadMu3DiBoson_->Write();
  InvMassUpsilonRangeDiBoson_->Write();
  InvMassZPeakRangeDiBoson_->Write();
  InvMassFullRangeDiBoson_->Write();
  InvMassDiMuBarrBarrDiBoson_->Write();
  InvMassDiMuBarrEndcDiBoson_->Write();
  InvMassDiMuEndcEndcDiBoson_->Write();
  Mu1PtDiBoson_->Write();
  Mu2PtDiBoson_->Write();
  DiMuPtDiBoson_->Write();
  Mu1EtaDiBoson_->Write();
  Mu2EtaDiBoson_->Write();
  DiTauEtaDiBoson_->Write();
  DiTauPhiDiBoson_->Write();
  DiMuEtaDiBoson_->Write();
  DiMudRDiBoson_->Write();
  DiMuPhiDiBoson_->Write();
  EtMETDiBoson_->Write();
  DiTauDiMuMassDiBoson_->Write();
  DiMuDiTauDeltaPhiDiBoson_->Write();
  METDiTauDeltaPhiDiBoson_->Write();
  METDiMuDeltaPhiDiBoson_->Write();
  DiTaudRDiBoson_->Write();
  DiTauMassSmallerdRDiBoson_->Write();
  HighestCSVInclJetDiBoson_->Write();

cout << "Combined DiBoson" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the Data Combined Canvas
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TCanvas *NMedIsoTausWithMu3CanvasData = new TCanvas ("NMedIsoTausWithMu3CanvasData","",600,600); 
  TCanvas *InvMassTauHadMu3CanvasData = new TCanvas ("InvMassTauHadMu3CanvasData","",600,600); 
  TCanvas *PtTauHadMu3CanvasData = new TCanvas ("PtTauHadMu3CanvasData","",600,600); 
  TCanvas *InvMassUpsilonRangeCanvasData = new TCanvas ("InvMassUpsilonRangeCanvasData","",600,600); 
  TCanvas *InvMassZPeakRangeCanvasData = new TCanvas ("InvMassZPeakRangeCanvasData","",600,600); 
  TCanvas *InvMassFullRangeCanvasData = new TCanvas ("InvMassFullRangeCanvasData","",600,600); 
  TCanvas *InvMassDiMuBarrBarrCanvasData = new TCanvas ("InvMassDiMuBarrBarrCanvasData","",600,600); 
  TCanvas *InvMassDiMuBarrEndcCanvasData = new TCanvas ("InvMassDiMuBarrEndcCanvasData","",600,600); 
  TCanvas *InvMassDiMuEndcEndcCanvasData = new TCanvas ("InvMassDiMuEndcEndcCanvasData","",600,600); 
  TCanvas *Mu1PtCanvasData = new TCanvas ("Mu1PtCanvasData","",600,600); 
  TCanvas *Mu2PtCanvasData = new TCanvas ("Mu2PtCanvasData","",600,600); 
  TCanvas *DiMuPtCanvasData = new TCanvas ("DiMuPtCanvasData","",600,600); 
  TCanvas *Mu1EtaCanvasData = new TCanvas ("Mu1EtaCanvasData","",600,600); 
  TCanvas *Mu2EtaCanvasData = new TCanvas ("Mu2EtaCanvasData","",600,600); 
  TCanvas *DiTauEtaCanvasData = new TCanvas ("DiTauEtaCanvasData","",600,600); 
  TCanvas *DiTauPhiCanvasData = new TCanvas ("DiTauPhiCanvasData","",600,600); 
  TCanvas *DiMuEtaCanvasData = new TCanvas ("DiMuEtaCanvasData","",600,600); 
  TCanvas *DiMudRCanvasData = new TCanvas ("DiMudRCanvasData","",600,600); 
  TCanvas *DiMuPhiCanvasData = new TCanvas ("DiMuPhiCanvasData","",600,600); 
  TCanvas *EtMETCanvasData = new TCanvas ("EtMETCanvasData","",600,600); 
  TCanvas *DiTauDiMuMassCanvasData = new TCanvas ("DiTauDiMuMassCanvasData","",600,600); 
  TCanvas *DiMuDiTauDeltaPhiCanvasData = new TCanvas ("DiMuDiTauDeltaPhiCanvasData","",600,600); 
  TCanvas *METDiTauDeltaPhiCanvasData = new TCanvas ("METDiTauDeltaPhiCanvasData","",600,600); 
  TCanvas *METDiMuDeltaPhiCanvasData = new TCanvas ("METDiMuDeltaPhiCanvasData","",600,600); 
  TCanvas *DiTaudRCanvasData = new TCanvas ("DiTaudRCanvasData","",600,600); 
  TCanvas *DiTauMassSmallerdRCanvasData = new TCanvas ("DiTauMassSmallerdRCanvasData","",600,600); 
  TCanvas *HighestCSVInclJetCanvasData = new TCanvas ("HighestCSVInclJetCanvasData","",600,600); 

  TH1F *NMedIsoTausWithMu3Data_ = new TH1F ("NMedIsoTausWithMu3Data","", NMedIsoTausWithMu3Data1_->GetNbinsX(), NMedIsoTausWithMu3Data1_->GetXaxis()->GetXmin(), NMedIsoTausWithMu3Data1_->GetXaxis()->GetXmax() );
  TH1F *InvMassTauHadMu3Data_ = new TH1F ("InvMassTauHadMu3Data","",InvMassTauHadMu3Data1_->GetNbinsX(), InvMassTauHadMu3Data1_->GetXaxis()->GetXmin(), InvMassTauHadMu3Data1_->GetXaxis()->GetXmax() );
  TH1F *PtTauHadMu3Data_ = new TH1F ("PtTauHadMu3Data","",PtTauHadMu3Data1_->GetNbinsX(), PtTauHadMu3Data1_->GetXaxis()->GetXmin(), PtTauHadMu3Data1_->GetXaxis()->GetXmax() );
  TH1F *InvMassUpsilonRangeData_ = new TH1F ("InvMassUpsilonRangeData","",InvMassUpsilonRangeData1_->GetNbinsX(), InvMassUpsilonRangeData1_->GetXaxis()->GetXmin(), InvMassUpsilonRangeData1_->GetXaxis()->GetXmax() );
  TH1F *InvMassZPeakRangeData_ = new TH1F ("InvMassZPeakRangeData","",InvMassZPeakRangeData1_->GetNbinsX(), InvMassZPeakRangeData1_->GetXaxis()->GetXmin(), InvMassZPeakRangeData1_->GetXaxis()->GetXmax() );
  TH1F *InvMassFullRangeData_ = new TH1F ("InvMassFullRangeData","",InvMassFullRangeData1_->GetNbinsX(), InvMassFullRangeData1_->GetXaxis()->GetXmin(), InvMassFullRangeData1_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuBarrBarrData_ = new TH1F ("InvMassDiMuBarrBarrData","",InvMassDiMuBarrBarrData1_->GetNbinsX(), InvMassDiMuBarrBarrData1_->GetXaxis()->GetXmin(), InvMassDiMuBarrBarrData1_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuBarrEndcData_ = new TH1F ("InvMassDiMuBarrEndcData","",InvMassDiMuBarrEndcData1_->GetNbinsX(), InvMassDiMuBarrEndcData1_->GetXaxis()->GetXmin(), InvMassDiMuBarrEndcData1_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuEndcEndcData_ = new TH1F ("InvMassDiMuEndcEndcData","",InvMassDiMuEndcEndcData1_->GetNbinsX(), InvMassDiMuEndcEndcData1_->GetXaxis()->GetXmin(), InvMassDiMuEndcEndcData1_->GetXaxis()->GetXmax() );
  TH1F *Mu1PtData_ = new TH1F ("Mu1PtData","",Mu1PtData1_->GetNbinsX(), Mu1PtData1_->GetXaxis()->GetXmin(), Mu1PtData1_->GetXaxis()->GetXmax() );
  TH1F *Mu2PtData_ = new TH1F ("Mu2PtData","",Mu2PtData1_->GetNbinsX(), Mu2PtData1_->GetXaxis()->GetXmin(), Mu2PtData1_->GetXaxis()->GetXmax() );
  TH1F *DiMuPtData_ = new TH1F ("DiMuPtData","",DiMuPtData1_->GetNbinsX(), DiMuPtData1_->GetXaxis()->GetXmin(), DiMuPtData1_->GetXaxis()->GetXmax() );
  TH1F *Mu1EtaData_ = new TH1F ("Mu1EtaData","",Mu1EtaData1_->GetNbinsX(), Mu1EtaData1_->GetXaxis()->GetXmin(), Mu1EtaData1_->GetXaxis()->GetXmax() );
  TH1F *Mu2EtaData_ = new TH1F ("Mu2EtaData","",Mu2EtaData1_->GetNbinsX(), Mu2EtaData1_->GetXaxis()->GetXmin(), Mu2EtaData1_->GetXaxis()->GetXmax() );
  TH1F *DiTauEtaData_ = new TH1F ("DiTauEtaData","",DiTauEtaData1_->GetNbinsX(), DiTauEtaData1_->GetXaxis()->GetXmin(), DiTauEtaData1_->GetXaxis()->GetXmax() );
  TH1F *DiTauPhiData_ = new TH1F ("DiTauPhiData","",DiTauPhiData1_->GetNbinsX(), DiTauPhiData1_->GetXaxis()->GetXmin(), DiTauPhiData1_->GetXaxis()->GetXmax() );
  TH1F *DiMuEtaData_ = new TH1F ("DiMuEtaData","",DiMuEtaData1_->GetNbinsX(), DiMuEtaData1_->GetXaxis()->GetXmin(), DiMuEtaData1_->GetXaxis()->GetXmax() );
  TH1F *DiMudRData_ = new TH1F ("DiMudRData","",DiMudRData1_->GetNbinsX(), DiMudRData1_->GetXaxis()->GetXmin(), DiMudRData1_->GetXaxis()->GetXmax() );
  TH1F *DiMuPhiData_ = new TH1F ("DiMuPhiData","",DiMuPhiData1_->GetNbinsX(), DiMuPhiData1_->GetXaxis()->GetXmin(), DiMuPhiData1_->GetXaxis()->GetXmax() );
  TH1F *EtMETData_ = new TH1F ("EtMETData","",EtMETData1_->GetNbinsX(), EtMETData1_->GetXaxis()->GetXmin(), EtMETData1_->GetXaxis()->GetXmax() );
  TH1F *DiTauDiMuMassData_ = new TH1F ("DiTauDiMuMassData","",DiTauDiMuMassData1_->GetNbinsX(), DiTauDiMuMassData1_->GetXaxis()->GetXmin(), DiTauDiMuMassData1_->GetXaxis()->GetXmax() );
  TH1F *DiMuDiTauDeltaPhiData_ = new TH1F ("DiMuDiTauDeltaPhiData","",DiMuDiTauDeltaPhiData1_->GetNbinsX(), DiMuDiTauDeltaPhiData1_->GetXaxis()->GetXmin(), DiMuDiTauDeltaPhiData1_->GetXaxis()->GetXmax() );
  TH1F *METDiTauDeltaPhiData_ = new TH1F ("METDiTauDeltaPhiData","",METDiTauDeltaPhiData1_->GetNbinsX(), METDiTauDeltaPhiData1_->GetXaxis()->GetXmin(), METDiTauDeltaPhiData1_->GetXaxis()->GetXmax() );
  TH1F *METDiMuDeltaPhiData_ = new TH1F ("METDiMuDeltaPhiData","",METDiMuDeltaPhiData1_->GetNbinsX(), METDiMuDeltaPhiData1_->GetXaxis()->GetXmin(), METDiMuDeltaPhiData1_->GetXaxis()->GetXmax() );
  TH1F *DiTaudRData_ = new TH1F ("DiTaudRData","",DiTaudRData1_->GetNbinsX(), DiTaudRData1_->GetXaxis()->GetXmin(), DiTaudRData1_->GetXaxis()->GetXmax() );
  TH1F *DiTauMassSmallerdRData_ = new TH1F ("DiTauMassSmallerdRData","",DiTauMassSmallerdRData1_->GetNbinsX(), DiTauMassSmallerdRData1_->GetXaxis()->GetXmin(), DiTauMassSmallerdRData1_->GetXaxis()->GetXmax() );
  TH1F *HighestCSVInclJetData_ = new TH1F ("HighestCSVInclJetData","",HighestCSVInclJetData1_->GetNbinsX(), HighestCSVInclJetData1_->GetXaxis()->GetXmin(), HighestCSVInclJetData1_->GetXaxis()->GetXmax() );


  NMedIsoTausWithMu3CanvasData->cd();
  NMedIsoTausWithMu3Data_->Add(NMedIsoTausWithMu3Data1_);
  NMedIsoTausWithMu3Data_->Add(NMedIsoTausWithMu3Data2_);

  InvMassTauHadMu3CanvasData->cd();
  InvMassTauHadMu3Data_->Add(InvMassTauHadMu3Data1_);
  InvMassTauHadMu3Data_->Add(InvMassTauHadMu3Data2_);

  PtTauHadMu3CanvasData->cd();
  PtTauHadMu3Data_->Add(PtTauHadMu3Data1_);
  PtTauHadMu3Data_->Add(PtTauHadMu3Data2_);

  InvMassUpsilonRangeCanvasData->cd();
  InvMassUpsilonRangeData_->Add(InvMassUpsilonRangeData1_);
  InvMassUpsilonRangeData_->Add(InvMassUpsilonRangeData2_);

  InvMassZPeakRangeCanvasData->cd();
  InvMassZPeakRangeData_->Add(InvMassZPeakRangeData1_);
  InvMassZPeakRangeData_->Add(InvMassZPeakRangeData2_);

  InvMassFullRangeCanvasData->cd();
  InvMassFullRangeData_->Add(InvMassFullRangeData1_);
  InvMassFullRangeData_->Add(InvMassFullRangeData2_);

  InvMassDiMuBarrBarrCanvasData->cd();
  InvMassDiMuBarrBarrData_->Add(InvMassDiMuBarrBarrData1_);
  InvMassDiMuBarrBarrData_->Add(InvMassDiMuBarrBarrData2_);

  InvMassDiMuBarrEndcCanvasData->cd();
  InvMassDiMuBarrEndcData_->Add(InvMassDiMuBarrEndcData1_);
  InvMassDiMuBarrEndcData_->Add(InvMassDiMuBarrEndcData2_);

  InvMassDiMuEndcEndcCanvasData->cd();
  InvMassDiMuEndcEndcData_->Add(InvMassDiMuEndcEndcData1_);
  InvMassDiMuEndcEndcData_->Add(InvMassDiMuEndcEndcData2_);

  Mu1PtCanvasData->cd();
  Mu1PtData_->Add(Mu1PtData1_);
  Mu1PtData_->Add(Mu1PtData2_);

  Mu2PtCanvasData->cd();
  Mu2PtData_->Add(Mu2PtData1_);
  Mu2PtData_->Add(Mu2PtData2_);

  DiMuPtCanvasData->cd();
  DiMuPtData_->Add(DiMuPtData1_);
  DiMuPtData_->Add(DiMuPtData2_);

  Mu1EtaCanvasData->cd();
  Mu1EtaData_->Add(Mu1EtaData1_);
  Mu1EtaData_->Add(Mu1EtaData2_);

  Mu2EtaCanvasData->cd();
  Mu2EtaData_->Add(Mu2EtaData1_);
  Mu2EtaData_->Add(Mu2EtaData2_);

  DiTauEtaCanvasData->cd();
  DiTauEtaData_->Add(DiTauEtaData1_);
  DiTauEtaData_->Add(DiTauEtaData2_);

  DiTauPhiCanvasData->cd();
  DiTauPhiData_->Add(DiTauPhiData1_);
  DiTauPhiData_->Add(DiTauPhiData2_);

  DiMuEtaCanvasData->cd();
  DiMuEtaData_->Add(DiMuEtaData1_);
  DiMuEtaData_->Add(DiMuEtaData2_);

  DiMudRCanvasData->cd();
  DiMudRData_->Add(DiMudRData1_);
  DiMudRData_->Add(DiMudRData2_);

  DiMuPhiCanvasData->cd();
  DiMuPhiData_->Add(DiMuPhiData1_);
  DiMuPhiData_->Add(DiMuPhiData2_);

  EtMETCanvasData->cd();
  EtMETData_->Add(EtMETData1_);
  EtMETData_->Add(EtMETData2_);

  DiTauDiMuMassCanvasData->cd();
  DiTauDiMuMassData_->Add(DiTauDiMuMassData1_);
  DiTauDiMuMassData_->Add(DiTauDiMuMassData2_);

  DiMuDiTauDeltaPhiCanvasData->cd();
  DiMuDiTauDeltaPhiData_->Add(DiMuDiTauDeltaPhiData1_);
  DiMuDiTauDeltaPhiData_->Add(DiMuDiTauDeltaPhiData2_);

  METDiTauDeltaPhiCanvasData->cd();
  METDiTauDeltaPhiData_->Add(METDiTauDeltaPhiData1_);
  METDiTauDeltaPhiData_->Add(METDiTauDeltaPhiData2_);

  METDiMuDeltaPhiCanvasData->cd();
  METDiMuDeltaPhiData_->Add(METDiMuDeltaPhiData1_);
  METDiMuDeltaPhiData_->Add(METDiMuDeltaPhiData2_);


  DiTaudRCanvasData->cd();
  DiTaudRData_->Add(DiTaudRData1_);
  DiTaudRData_->Add(DiTaudRData2_);

  DiTauMassSmallerdRCanvasData->cd();
  DiTauMassSmallerdRData_->Add(DiTauMassSmallerdRData1_);
  DiTauMassSmallerdRData_->Add(DiTauMassSmallerdRData2_);

  HighestCSVInclJetCanvasData->cd();
  HighestCSVInclJetData_->Add(HighestCSVInclJetData1_);
  HighestCSVInclJetData_->Add(HighestCSVInclJetData2_);

  outFile->cd();
  TDirectory *DataCombined = outFile->mkdir("DataCombined");
  DataCombined->cd();
  NMedIsoTausWithMu3Data_->Write();
  InvMassTauHadMu3Data_->Write();
  PtTauHadMu3Data_->Write();
  InvMassUpsilonRangeData_->Write();
  InvMassZPeakRangeData_->Write();
  InvMassFullRangeData_->Write();
  InvMassDiMuBarrBarrData_->Write();
  InvMassDiMuBarrEndcData_->Write();
  InvMassDiMuEndcEndcData_->Write();
  Mu1PtData_->Write();
  Mu2PtData_->Write();
  DiMuPtData_->Write();
  Mu1EtaData_->Write();
  Mu2EtaData_->Write();
  DiTauEtaData_->Write();
  DiTauPhiData_->Write();
  DiMuEtaData_->Write();
  DiMudRData_->Write();
  DiMuPhiData_->Write();
  EtMETData_->Write();
  DiTauDiMuMassData_->Write();
  DiMuDiTauDeltaPhiData_->Write();
  METDiTauDeltaPhiData_->Write();
  METDiMuDeltaPhiData_->Write();
  DiTaudRData_->Write();
  DiTauMassSmallerdRData_->Write();
  HighestCSVInclJetData_->Write();

  outFile->cd();
  TDirectory *TTCombined = outFile->mkdir("TTCombined");
  TTCombined->cd();
  NMedIsoTausWithMu3TT_->Write();
  InvMassTauHadMu3TT_->Write();
  PtTauHadMu3TT_->Write();
  InvMassUpsilonRangeTT_->Write();
  InvMassZPeakRangeTT_->Write();
  InvMassFullRangeTT_->Write();
  InvMassDiMuBarrBarrTT_->Write();
  InvMassDiMuBarrEndcTT_->Write();
  InvMassDiMuEndcEndcTT_->Write();
  Mu1PtTT_->Write();
  Mu2PtTT_->Write();
  DiMuPtTT_->Write();
  Mu1EtaTT_->Write();
  Mu2EtaTT_->Write();
  DiTauEtaTT_->Write();
  DiTauPhiTT_->Write();
  DiMuEtaTT_->Write();
  DiMudRTT_->Write();
  DiMuPhiTT_->Write();
  EtMETTT_->Write();
  DiTauDiMuMassTT_->Write();
  DiMuDiTauDeltaPhiTT_->Write();
  METDiTauDeltaPhiTT_->Write();
  METDiMuDeltaPhiTT_->Write();
  DiTaudRTT_->Write();
  DiTauMassSmallerdRTT_->Write();
  HighestCSVInclJetTT_->Write();

cout << "Combined Data" <<endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting Fill Colors
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  NMedIsoTausWithMu3h125a11_->SetLineColor(kGray+1);
  InvMassTauHadMu3h125a11_->SetLineColor(kGray+1);
  PtTauHadMu3h125a11_->SetLineColor(kGray+1);
  InvMassUpsilonRangeh125a11_->SetLineColor(kGray+1);
  InvMassZPeakRangeh125a11_->SetLineColor(kGray+1);
  InvMassFullRangeh125a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrBarrh125a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrEndch125a11_->SetLineColor(kGray+1);
  InvMassDiMuEndcEndch125a11_->SetLineColor(kGray+1);
  Mu1Pth125a11_->SetLineColor(kGray+1);
  Mu2Pth125a11_->SetLineColor(kGray+1);
  DiMuPth125a11_->SetLineColor(kGray+1);
  Mu1Etah125a11_->SetLineColor(kGray+1);
  Mu2Etah125a11_->SetLineColor(kGray+1);
  DiTauEtah125a11_->SetLineColor(kGray+1);
  DiTauPhih125a11_->SetLineColor(kGray+1);
  DiMuEtah125a11_->SetLineColor(kGray+1);
  DiMudRh125a11_->SetLineColor(kGray+1);
  DiMuPhih125a11_->SetLineColor(kGray+1);
  EtMETh125a11_->SetLineColor(kGray+1);
  DiTauDiMuMassh125a11_->SetLineColor(kGray+1);
  DiMuDiTauDeltaPhih125a11_->SetLineColor(kGray+1);
  METDiTauDeltaPhih125a11_->SetLineColor(kGray+1);
  METDiMuDeltaPhih125a11_->SetLineColor(kGray+1);
  DiTaudRh125a11_->SetLineColor(kGray+1);
  DiTauMassSmallerdRh125a11_->SetLineColor(kGray+1);
  HighestCSVInclJeth125a11_->SetLineColor(kGray+1);

  ////////////////
  // h125a13
  ////////////////
  NMedIsoTausWithMu3h125a13_->SetLineColor(kGreen);
  InvMassTauHadMu3h125a13_->SetLineColor(kGreen);
  PtTauHadMu3h125a13_->SetLineColor(kGreen);
  InvMassUpsilonRangeh125a13_->SetLineColor(kGreen);
  InvMassZPeakRangeh125a13_->SetLineColor(kGreen);
  InvMassFullRangeh125a13_->SetLineColor(kGreen);
  InvMassDiMuBarrBarrh125a13_->SetLineColor(kGreen);
  InvMassDiMuBarrEndch125a13_->SetLineColor(kGreen);
  InvMassDiMuEndcEndch125a13_->SetLineColor(kGreen);
  Mu1Pth125a13_->SetLineColor(kGreen);
  Mu2Pth125a13_->SetLineColor(kGreen);
  DiMuPth125a13_->SetLineColor(kGreen);
  Mu1Etah125a13_->SetLineColor(kGreen);
  Mu2Etah125a13_->SetLineColor(kGreen);
  DiTauEtah125a13_->SetLineColor(kGreen);
  DiTauPhih125a13_->SetLineColor(kGreen);
  DiMuEtah125a13_->SetLineColor(kGreen);
  DiMudRh125a13_->SetLineColor(kGreen);
  DiMuPhih125a13_->SetLineColor(kGreen);
  EtMETh125a13_->SetLineColor(kGreen);
  DiTauDiMuMassh125a13_->SetLineColor(kGreen);
  DiMuDiTauDeltaPhih125a13_->SetLineColor(kGreen);
  METDiTauDeltaPhih125a13_->SetLineColor(kGreen);
  METDiMuDeltaPhih125a13_->SetLineColor(kGreen);
  DiTaudRh125a13_->SetLineColor(kGreen);
  DiTauMassSmallerdRh125a13_->SetLineColor(kGreen);
  HighestCSVInclJeth125a13_->SetLineColor(kGreen);

  ////////////////
  // h125a15
  ////////////////
  NMedIsoTausWithMu3h125a15_->SetLineColor(kTeal-1);
  InvMassTauHadMu3h125a15_->SetLineColor(kTeal-1);
  PtTauHadMu3h125a15_->SetLineColor(kTeal-1);
  InvMassUpsilonRangeh125a15_->SetLineColor(kTeal-1);
  InvMassZPeakRangeh125a15_->SetLineColor(kTeal-1);
  InvMassFullRangeh125a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrBarrh125a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrEndch125a15_->SetLineColor(kTeal-1);
  InvMassDiMuEndcEndch125a15_->SetLineColor(kTeal-1);
  Mu1Pth125a15_->SetLineColor(kTeal-1);
  Mu2Pth125a15_->SetLineColor(kTeal-1);
  DiMuPth125a15_->SetLineColor(kTeal-1);
  Mu1Etah125a15_->SetLineColor(kTeal-1);
  Mu2Etah125a15_->SetLineColor(kTeal-1);
  DiTauEtah125a15_->SetLineColor(kTeal-1);
  DiTauPhih125a15_->SetLineColor(kTeal-1);
  DiMuEtah125a15_->SetLineColor(kTeal-1);
  DiMudRh125a15_->SetLineColor(kTeal-1);
  DiMuPhih125a15_->SetLineColor(kTeal-1);
  EtMETh125a15_->SetLineColor(kTeal-1);
  DiTauDiMuMassh125a15_->SetLineColor(kTeal-1);
  DiMuDiTauDeltaPhih125a15_->SetLineColor(kTeal-1);
  METDiTauDeltaPhih125a15_->SetLineColor(kTeal-1);
  METDiMuDeltaPhih125a15_->SetLineColor(kTeal-1);
  DiTaudRh125a15_->SetLineColor(kTeal-1);
  DiTauMassSmallerdRh125a15_->SetLineColor(kTeal-1);
  HighestCSVInclJeth125a15_->SetLineColor(kTeal-1);

  ////////////////
  // h125a17
  ////////////////
  NMedIsoTausWithMu3h125a17_->SetLineColor(kCyan);
  InvMassTauHadMu3h125a17_->SetLineColor(kCyan);
  PtTauHadMu3h125a17_->SetLineColor(kCyan);
  InvMassUpsilonRangeh125a17_->SetLineColor(kCyan);
  InvMassZPeakRangeh125a17_->SetLineColor(kCyan);
  InvMassFullRangeh125a17_->SetLineColor(kCyan);
  InvMassDiMuBarrBarrh125a17_->SetLineColor(kCyan);
  InvMassDiMuBarrEndch125a17_->SetLineColor(kCyan);
  InvMassDiMuEndcEndch125a17_->SetLineColor(kCyan);
  Mu1Pth125a17_->SetLineColor(kCyan);
  Mu2Pth125a17_->SetLineColor(kCyan);
  DiMuPth125a17_->SetLineColor(kCyan);
  Mu1Etah125a17_->SetLineColor(kCyan);
  Mu2Etah125a17_->SetLineColor(kCyan);
  DiTauEtah125a17_->SetLineColor(kCyan);
  DiTauPhih125a17_->SetLineColor(kCyan);
  DiMuEtah125a17_->SetLineColor(kCyan);
  DiMudRh125a17_->SetLineColor(kCyan);
  DiMuPhih125a17_->SetLineColor(kCyan);
  EtMETh125a17_->SetLineColor(kCyan);
  DiTauDiMuMassh125a17_->SetLineColor(kCyan);
  DiMuDiTauDeltaPhih125a17_->SetLineColor(kCyan);
  METDiTauDeltaPhih125a17_->SetLineColor(kCyan);
  METDiMuDeltaPhih125a17_->SetLineColor(kCyan);
  DiTaudRh125a17_->SetLineColor(kCyan);
  DiTauMassSmallerdRh125a17_->SetLineColor(kCyan);
  HighestCSVInclJeth125a17_->SetLineColor(kCyan);

  ////////////////
  // h125a19
  ////////////////
  NMedIsoTausWithMu3h125a19_->SetLineColor(kAzure+3);
  InvMassTauHadMu3h125a19_->SetLineColor(kAzure+3);
  PtTauHadMu3h125a19_->SetLineColor(kAzure+3);
  InvMassUpsilonRangeh125a19_->SetLineColor(kAzure+3);
  InvMassZPeakRangeh125a19_->SetLineColor(kAzure+3);
  InvMassFullRangeh125a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrBarrh125a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrEndch125a19_->SetLineColor(kAzure+3);
  InvMassDiMuEndcEndch125a19_->SetLineColor(kAzure+3);
  Mu1Pth125a19_->SetLineColor(kAzure+3);
  Mu2Pth125a19_->SetLineColor(kAzure+3);
  DiMuPth125a19_->SetLineColor(kAzure+3);
  Mu1Etah125a19_->SetLineColor(kAzure+3);
  Mu2Etah125a19_->SetLineColor(kAzure+3);
  DiTauEtah125a19_->SetLineColor(kAzure+3);
  DiTauPhih125a19_->SetLineColor(kAzure+3);
  DiMuEtah125a19_->SetLineColor(kAzure+3);
  DiMudRh125a19_->SetLineColor(kAzure+3);
  DiMuPhih125a19_->SetLineColor(kAzure+3);
  EtMETh125a19_->SetLineColor(kAzure+3);
  DiTauDiMuMassh125a19_->SetLineColor(kAzure+3);
  DiMuDiTauDeltaPhih125a19_->SetLineColor(kAzure+3);
  METDiTauDeltaPhih125a19_->SetLineColor(kAzure+3);
  METDiMuDeltaPhih125a19_->SetLineColor(kAzure+3);
  DiTaudRh125a19_->SetLineColor(kAzure+3);
  DiTauMassSmallerdRh125a19_->SetLineColor(kAzure+3);
  HighestCSVInclJeth125a19_->SetLineColor(kAzure+3);

  ////////////////
  // h125a21
  ////////////////
  NMedIsoTausWithMu3h125a21_->SetLineColor(kBlue);
  InvMassTauHadMu3h125a21_->SetLineColor(kBlue);
  PtTauHadMu3h125a21_->SetLineColor(kBlue);
  InvMassUpsilonRangeh125a21_->SetLineColor(kBlue);
  InvMassZPeakRangeh125a21_->SetLineColor(kBlue);
  InvMassFullRangeh125a21_->SetLineColor(kBlue);
  InvMassDiMuBarrBarrh125a21_->SetLineColor(kBlue);
  InvMassDiMuBarrEndch125a21_->SetLineColor(kBlue);
  InvMassDiMuEndcEndch125a21_->SetLineColor(kBlue);
  Mu1Pth125a21_->SetLineColor(kBlue);
  Mu2Pth125a21_->SetLineColor(kBlue);
  DiMuPth125a21_->SetLineColor(kBlue);
  Mu1Etah125a21_->SetLineColor(kBlue);
  Mu2Etah125a21_->SetLineColor(kBlue);
  DiTauEtah125a21_->SetLineColor(kBlue);
  DiTauPhih125a21_->SetLineColor(kBlue);
  DiMuEtah125a21_->SetLineColor(kBlue);
  DiMudRh125a21_->SetLineColor(kBlue);
  DiMuPhih125a21_->SetLineColor(kBlue);
  EtMETh125a21_->SetLineColor(kBlue);
  DiTauDiMuMassh125a21_->SetLineColor(kBlue);
  DiMuDiTauDeltaPhih125a21_->SetLineColor(kBlue);
  METDiTauDeltaPhih125a21_->SetLineColor(kBlue);
  METDiMuDeltaPhih125a21_->SetLineColor(kBlue);
  DiTaudRh125a21_->SetLineColor(kBlue);
  DiTauMassSmallerdRh125a21_->SetLineColor(kBlue);
  HighestCSVInclJeth125a21_->SetLineColor(kBlue);

  ////////////////
  // h125a5
  ////////////////
  NMedIsoTausWithMu3h125a5_->SetLineColor(kSpring-7);
  InvMassTauHadMu3h125a5_->SetLineColor(kSpring-7);
  PtTauHadMu3h125a5_->SetLineColor(kSpring-7);
  InvMassUpsilonRangeh125a5_->SetLineColor(kSpring-7);
  InvMassZPeakRangeh125a5_->SetLineColor(kSpring-7);
  InvMassFullRangeh125a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrBarrh125a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrEndch125a5_->SetLineColor(kSpring-7);
  InvMassDiMuEndcEndch125a5_->SetLineColor(kSpring-7);
  Mu1Pth125a5_->SetLineColor(kSpring-7);
  Mu2Pth125a5_->SetLineColor(kSpring-7);
  DiMuPth125a5_->SetLineColor(kSpring-7);
  Mu1Etah125a5_->SetLineColor(kSpring-7);
  Mu2Etah125a5_->SetLineColor(kSpring-7);
  DiTauEtah125a5_->SetLineColor(kSpring-7);
  DiTauPhih125a5_->SetLineColor(kSpring-7);
  DiMuEtah125a5_->SetLineColor(kSpring-7);
  DiMudRh125a5_->SetLineColor(kSpring-7);
  DiMuPhih125a5_->SetLineColor(kSpring-7);
  EtMETh125a5_->SetLineColor(kSpring-7);
  DiTauDiMuMassh125a5_->SetLineColor(kSpring-7);
  DiMuDiTauDeltaPhih125a5_->SetLineColor(kSpring-7);
  METDiTauDeltaPhih125a5_->SetLineColor(kSpring-7);
  METDiMuDeltaPhih125a5_->SetLineColor(kSpring-7);
  DiTaudRh125a5_->SetLineColor(kSpring-7);
  DiTauMassSmallerdRh125a5_->SetLineColor(kSpring-7);
  HighestCSVInclJeth125a5_->SetLineColor(kSpring-7);

  ////////////////
  // h125a7
  ////////////////
  NMedIsoTausWithMu3h125a7_->SetLineColor(kYellow+1);
  InvMassTauHadMu3h125a7_->SetLineColor(kYellow+1);
  PtTauHadMu3h125a7_->SetLineColor(kYellow+1);
  InvMassUpsilonRangeh125a7_->SetLineColor(kYellow+1);
  InvMassZPeakRangeh125a7_->SetLineColor(kYellow+1);
  InvMassFullRangeh125a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrBarrh125a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrEndch125a7_->SetLineColor(kYellow+1);
  InvMassDiMuEndcEndch125a7_->SetLineColor(kYellow+1);
  Mu1Pth125a7_->SetLineColor(kYellow+1);
  Mu2Pth125a7_->SetLineColor(kYellow+1);
  DiMuPth125a7_->SetLineColor(kYellow+1);
  Mu1Etah125a7_->SetLineColor(kYellow+1);
  Mu2Etah125a7_->SetLineColor(kYellow+1);
  DiTauEtah125a7_->SetLineColor(kYellow+1);
  DiTauPhih125a7_->SetLineColor(kYellow+1);
  DiMuEtah125a7_->SetLineColor(kYellow+1);
  DiMudRh125a7_->SetLineColor(kYellow+1);
  DiMuPhih125a7_->SetLineColor(kYellow+1);
  EtMETh125a7_->SetLineColor(kYellow+1);
  DiTauDiMuMassh125a7_->SetLineColor(kYellow+1);
  DiMuDiTauDeltaPhih125a7_->SetLineColor(kYellow+1);
  METDiTauDeltaPhih125a7_->SetLineColor(kYellow+1);
  METDiMuDeltaPhih125a7_->SetLineColor(kYellow+1);
  DiTaudRh125a7_->SetLineColor(kYellow+1);
  DiTauMassSmallerdRh125a7_->SetLineColor(kYellow+1);
  HighestCSVInclJeth125a7_->SetLineColor(kYellow+1);

  ////////////////
  // h125a9
  ////////////////
  NMedIsoTausWithMu3h125a9_->SetLineColor(kOrange+9);
  InvMassTauHadMu3h125a9_->SetLineColor(kOrange+9);
  PtTauHadMu3h125a9_->SetLineColor(kOrange+9);
  InvMassUpsilonRangeh125a9_->SetLineColor(kOrange+9);
  InvMassZPeakRangeh125a9_->SetLineColor(kOrange+9);
  InvMassFullRangeh125a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrBarrh125a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrEndch125a9_->SetLineColor(kOrange+9);
  InvMassDiMuEndcEndch125a9_->SetLineColor(kOrange+9);
  Mu1Pth125a9_->SetLineColor(kOrange+9);
  Mu2Pth125a9_->SetLineColor(kOrange+9);
  DiMuPth125a9_->SetLineColor(kOrange+9);
  Mu1Etah125a9_->SetLineColor(kOrange+9);
  Mu2Etah125a9_->SetLineColor(kOrange+9);
  DiTauEtah125a9_->SetLineColor(kOrange+9);
  DiTauPhih125a9_->SetLineColor(kOrange+9);
  DiMuEtah125a9_->SetLineColor(kOrange+9);
  DiMudRh125a9_->SetLineColor(kOrange+9);
  DiMuPhih125a9_->SetLineColor(kOrange+9);
  EtMETh125a9_->SetLineColor(kOrange+9);
  DiTauDiMuMassh125a9_->SetLineColor(kOrange+9);
  DiMuDiTauDeltaPhih125a9_->SetLineColor(kOrange+9);
  METDiTauDeltaPhih125a9_->SetLineColor(kOrange+9);
  METDiMuDeltaPhih125a9_->SetLineColor(kOrange+9);
  DiTaudRh125a9_->SetLineColor(kOrange+9);
  DiTauMassSmallerdRh125a9_->SetLineColor(kOrange+9);
  HighestCSVInclJeth125a9_->SetLineColor(kOrange+9);

  ////////////////
  // h300a11
  ////////////////
  NMedIsoTausWithMu3h300a11_->SetLineColor(kGray+1);
  InvMassTauHadMu3h300a11_->SetLineColor(kGray+1);
  PtTauHadMu3h300a11_->SetLineColor(kGray+1);
  InvMassUpsilonRangeh300a11_->SetLineColor(kGray+1);
  InvMassZPeakRangeh300a11_->SetLineColor(kGray+1);
  InvMassFullRangeh300a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrBarrh300a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrEndch300a11_->SetLineColor(kGray+1);
  InvMassDiMuEndcEndch300a11_->SetLineColor(kGray+1);
  Mu1Pth300a11_->SetLineColor(kGray+1);
  Mu2Pth300a11_->SetLineColor(kGray+1);
  DiMuPth300a11_->SetLineColor(kGray+1);
  Mu1Etah300a11_->SetLineColor(kGray+1);
  Mu2Etah300a11_->SetLineColor(kGray+1);
  DiTauEtah300a11_->SetLineColor(kGray+1);
  DiTauPhih300a11_->SetLineColor(kGray+1);
  DiMuEtah300a11_->SetLineColor(kGray+1);
  DiMudRh300a11_->SetLineColor(kGray+1);
  DiMuPhih300a11_->SetLineColor(kGray+1);
  EtMETh300a11_->SetLineColor(kGray+1);
  DiTauDiMuMassh300a11_->SetLineColor(kGray+1);
  DiMuDiTauDeltaPhih300a11_->SetLineColor(kGray+1);
  METDiTauDeltaPhih300a11_->SetLineColor(kGray+1);
  METDiMuDeltaPhih300a11_->SetLineColor(kGray+1);
  DiTaudRh300a11_->SetLineColor(kGray+1);
  DiTauMassSmallerdRh300a11_->SetLineColor(kGray+1);
  HighestCSVInclJeth300a11_->SetLineColor(kGray+1);

  ////////////////
  // h300a13
  ////////////////
  NMedIsoTausWithMu3h300a13_->SetLineColor(kGreen);
  InvMassTauHadMu3h300a13_->SetLineColor(kGreen);
  PtTauHadMu3h300a13_->SetLineColor(kGreen);
  InvMassUpsilonRangeh300a13_->SetLineColor(kGreen);
  InvMassZPeakRangeh300a13_->SetLineColor(kGreen);
  InvMassFullRangeh300a13_->SetLineColor(kGreen);
  InvMassDiMuBarrBarrh300a13_->SetLineColor(kGreen);
  InvMassDiMuBarrEndch300a13_->SetLineColor(kGreen);
  InvMassDiMuEndcEndch300a13_->SetLineColor(kGreen);
  Mu1Pth300a13_->SetLineColor(kGreen);
  Mu2Pth300a13_->SetLineColor(kGreen);
  DiMuPth300a13_->SetLineColor(kGreen);
  Mu1Etah300a13_->SetLineColor(kGreen);
  Mu2Etah300a13_->SetLineColor(kGreen);
  DiTauEtah300a13_->SetLineColor(kGreen);
  DiTauPhih300a13_->SetLineColor(kGreen);
  DiMuEtah300a13_->SetLineColor(kGreen);
  DiMudRh300a13_->SetLineColor(kGreen);
  DiMuPhih300a13_->SetLineColor(kGreen);
  EtMETh300a13_->SetLineColor(kGreen);
  DiTauDiMuMassh300a13_->SetLineColor(kGreen);
  DiMuDiTauDeltaPhih300a13_->SetLineColor(kGreen);
  METDiTauDeltaPhih300a13_->SetLineColor(kGreen);
  METDiMuDeltaPhih300a13_->SetLineColor(kGreen);
  DiTaudRh300a13_->SetLineColor(kGreen);
  DiTauMassSmallerdRh300a13_->SetLineColor(kGreen);
  HighestCSVInclJeth300a13_->SetLineColor(kGreen);

  ////////////////
  // h300a15
  ////////////////
  NMedIsoTausWithMu3h300a15_->SetLineColor(kTeal-1);
  InvMassTauHadMu3h300a15_->SetLineColor(kTeal-1);
  PtTauHadMu3h300a15_->SetLineColor(kTeal-1);
  InvMassUpsilonRangeh300a15_->SetLineColor(kTeal-1);
  InvMassZPeakRangeh300a15_->SetLineColor(kTeal-1);
  InvMassFullRangeh300a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrBarrh300a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrEndch300a15_->SetLineColor(kTeal-1);
  InvMassDiMuEndcEndch300a15_->SetLineColor(kTeal-1);
  Mu1Pth300a15_->SetLineColor(kTeal-1);
  Mu2Pth300a15_->SetLineColor(kTeal-1);
  DiMuPth300a15_->SetLineColor(kTeal-1);
  Mu1Etah300a15_->SetLineColor(kTeal-1);
  Mu2Etah300a15_->SetLineColor(kTeal-1);
  DiTauEtah300a15_->SetLineColor(kTeal-1);
  DiTauPhih300a15_->SetLineColor(kTeal-1);
  DiMuEtah300a15_->SetLineColor(kTeal-1);
  DiMudRh300a15_->SetLineColor(kTeal-1);
  DiMuPhih300a15_->SetLineColor(kTeal-1);
  EtMETh300a15_->SetLineColor(kTeal-1);
  DiTauDiMuMassh300a15_->SetLineColor(kTeal-1);
  DiMuDiTauDeltaPhih300a15_->SetLineColor(kTeal-1);
  METDiTauDeltaPhih300a15_->SetLineColor(kTeal-1);
  METDiMuDeltaPhih300a15_->SetLineColor(kTeal-1);
  DiTaudRh300a15_->SetLineColor(kTeal-1);
  DiTauMassSmallerdRh300a15_->SetLineColor(kTeal-1);
  HighestCSVInclJeth300a15_->SetLineColor(kTeal-1);

  ////////////////
  // h300a17
  ////////////////
  NMedIsoTausWithMu3h300a17_->SetLineColor(kCyan);
  InvMassTauHadMu3h300a17_->SetLineColor(kCyan);
  PtTauHadMu3h300a17_->SetLineColor(kCyan);
  InvMassUpsilonRangeh300a17_->SetLineColor(kCyan);
  InvMassZPeakRangeh300a17_->SetLineColor(kCyan);
  InvMassFullRangeh300a17_->SetLineColor(kCyan);
  InvMassDiMuBarrBarrh300a17_->SetLineColor(kCyan);
  InvMassDiMuBarrEndch300a17_->SetLineColor(kCyan);
  InvMassDiMuEndcEndch300a17_->SetLineColor(kCyan);
  Mu1Pth300a17_->SetLineColor(kCyan);
  Mu2Pth300a17_->SetLineColor(kCyan);
  DiMuPth300a17_->SetLineColor(kCyan);
  Mu1Etah300a17_->SetLineColor(kCyan);
  Mu2Etah300a17_->SetLineColor(kCyan);
  DiTauEtah300a17_->SetLineColor(kCyan);
  DiTauPhih300a17_->SetLineColor(kCyan);
  DiMuEtah300a17_->SetLineColor(kCyan);
  DiMudRh300a17_->SetLineColor(kCyan);
  DiMuPhih300a17_->SetLineColor(kCyan);
  EtMETh300a17_->SetLineColor(kCyan);
  DiTauDiMuMassh300a17_->SetLineColor(kCyan);
  DiMuDiTauDeltaPhih300a17_->SetLineColor(kCyan);
  METDiTauDeltaPhih300a17_->SetLineColor(kCyan);
  METDiMuDeltaPhih300a17_->SetLineColor(kCyan);
  DiTaudRh300a17_->SetLineColor(kCyan);
  DiTauMassSmallerdRh300a17_->SetLineColor(kCyan);
  HighestCSVInclJeth300a17_->SetLineColor(kCyan);

  ////////////////
  // h300a19
  ////////////////
  NMedIsoTausWithMu3h300a19_->SetLineColor(kAzure+3);
  InvMassTauHadMu3h300a19_->SetLineColor(kAzure+3);
  PtTauHadMu3h300a19_->SetLineColor(kAzure+3);
  InvMassUpsilonRangeh300a19_->SetLineColor(kAzure+3);
  InvMassZPeakRangeh300a19_->SetLineColor(kAzure+3);
  InvMassFullRangeh300a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrBarrh300a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrEndch300a19_->SetLineColor(kAzure+3);
  InvMassDiMuEndcEndch300a19_->SetLineColor(kAzure+3);
  Mu1Pth300a19_->SetLineColor(kAzure+3);
  Mu2Pth300a19_->SetLineColor(kAzure+3);
  DiMuPth300a19_->SetLineColor(kAzure+3);
  Mu1Etah300a19_->SetLineColor(kAzure+3);
  Mu2Etah300a19_->SetLineColor(kAzure+3);
  DiTauEtah300a19_->SetLineColor(kAzure+3);
  DiTauPhih300a19_->SetLineColor(kAzure+3);
  DiMuEtah300a19_->SetLineColor(kAzure+3);
  DiMudRh300a19_->SetLineColor(kAzure+3);
  DiMuPhih300a19_->SetLineColor(kAzure+3);
  EtMETh300a19_->SetLineColor(kAzure+3);
  DiTauDiMuMassh300a19_->SetLineColor(kAzure+3);
  DiMuDiTauDeltaPhih300a19_->SetLineColor(kAzure+3);
  METDiTauDeltaPhih300a19_->SetLineColor(kAzure+3);
  METDiMuDeltaPhih300a19_->SetLineColor(kAzure+3);
  DiTaudRh300a19_->SetLineColor(kAzure+3);
  DiTauMassSmallerdRh300a19_->SetLineColor(kAzure+3);
  HighestCSVInclJeth300a19_->SetLineColor(kAzure+3);

  ////////////////
  // h300a21
  ////////////////
  NMedIsoTausWithMu3h300a21_->SetLineColor(kBlue);
  InvMassTauHadMu3h300a21_->SetLineColor(kBlue);
  PtTauHadMu3h300a21_->SetLineColor(kBlue);
  InvMassUpsilonRangeh300a21_->SetLineColor(kBlue);
  InvMassZPeakRangeh300a21_->SetLineColor(kBlue);
  InvMassFullRangeh300a21_->SetLineColor(kBlue);
  InvMassDiMuBarrBarrh300a21_->SetLineColor(kBlue);
  InvMassDiMuBarrEndch300a21_->SetLineColor(kBlue);
  InvMassDiMuEndcEndch300a21_->SetLineColor(kBlue);
  Mu1Pth300a21_->SetLineColor(kBlue);
  Mu2Pth300a21_->SetLineColor(kBlue);
  DiMuPth300a21_->SetLineColor(kBlue);
  Mu1Etah300a21_->SetLineColor(kBlue);
  Mu2Etah300a21_->SetLineColor(kBlue);
  DiTauEtah300a21_->SetLineColor(kBlue);
  DiTauPhih300a21_->SetLineColor(kBlue);
  DiMuEtah300a21_->SetLineColor(kBlue);
  DiMudRh300a21_->SetLineColor(kBlue);
  DiMuPhih300a21_->SetLineColor(kBlue);
  EtMETh300a21_->SetLineColor(kBlue);
  DiTauDiMuMassh300a21_->SetLineColor(kBlue);
  DiMuDiTauDeltaPhih300a21_->SetLineColor(kBlue);
  METDiTauDeltaPhih300a21_->SetLineColor(kBlue);
  METDiMuDeltaPhih300a21_->SetLineColor(kBlue);
  DiTaudRh300a21_->SetLineColor(kBlue);
  DiTauMassSmallerdRh300a21_->SetLineColor(kBlue);
  HighestCSVInclJeth300a21_->SetLineColor(kBlue);

  ////////////////
  // h300a5
  ////////////////
  NMedIsoTausWithMu3h300a5_->SetLineColor(kSpring-7);
  InvMassTauHadMu3h300a5_->SetLineColor(kSpring-7);
  PtTauHadMu3h300a5_->SetLineColor(kSpring-7);
  InvMassUpsilonRangeh300a5_->SetLineColor(kSpring-7);
  InvMassZPeakRangeh300a5_->SetLineColor(kSpring-7);
  InvMassFullRangeh300a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrBarrh300a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrEndch300a5_->SetLineColor(kSpring-7);
  InvMassDiMuEndcEndch300a5_->SetLineColor(kSpring-7);
  Mu1Pth300a5_->SetLineColor(kSpring-7);
  Mu2Pth300a5_->SetLineColor(kSpring-7);
  DiMuPth300a5_->SetLineColor(kSpring-7);
  Mu1Etah300a5_->SetLineColor(kSpring-7);
  Mu2Etah300a5_->SetLineColor(kSpring-7);
  DiTauEtah300a5_->SetLineColor(kSpring-7);
  DiTauPhih300a5_->SetLineColor(kSpring-7);
  DiMuEtah300a5_->SetLineColor(kSpring-7);
  DiMudRh300a5_->SetLineColor(kSpring-7);
  DiMuPhih300a5_->SetLineColor(kSpring-7);
  EtMETh300a5_->SetLineColor(kSpring-7);
  DiTauDiMuMassh300a5_->SetLineColor(kSpring-7);
  DiMuDiTauDeltaPhih300a5_->SetLineColor(kSpring-7);
  METDiTauDeltaPhih300a5_->SetLineColor(kSpring-7);
  METDiMuDeltaPhih300a5_->SetLineColor(kSpring-7);
  DiTaudRh300a5_->SetLineColor(kSpring-7);
  DiTauMassSmallerdRh300a5_->SetLineColor(kSpring-7);
  HighestCSVInclJeth300a5_->SetLineColor(kSpring-7);

  ////////////////
  // h300a7
  ////////////////
  NMedIsoTausWithMu3h300a7_->SetLineColor(kYellow+1);
  InvMassTauHadMu3h300a7_->SetLineColor(kYellow+1);
  PtTauHadMu3h300a7_->SetLineColor(kYellow+1);
  InvMassUpsilonRangeh300a7_->SetLineColor(kYellow+1);
  InvMassZPeakRangeh300a7_->SetLineColor(kYellow+1);
  InvMassFullRangeh300a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrBarrh300a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrEndch300a7_->SetLineColor(kYellow+1);
  InvMassDiMuEndcEndch300a7_->SetLineColor(kYellow+1);
  Mu1Pth300a7_->SetLineColor(kYellow+1);
  Mu2Pth300a7_->SetLineColor(kYellow+1);
  DiMuPth300a7_->SetLineColor(kYellow+1);
  Mu1Etah300a7_->SetLineColor(kYellow+1);
  Mu2Etah300a7_->SetLineColor(kYellow+1);
  DiTauEtah300a7_->SetLineColor(kYellow+1);
  DiTauPhih300a7_->SetLineColor(kYellow+1);
  DiMuEtah300a7_->SetLineColor(kYellow+1);
  DiMudRh300a7_->SetLineColor(kYellow+1);
  DiMuPhih300a7_->SetLineColor(kYellow+1);
  EtMETh300a7_->SetLineColor(kYellow+1);
  DiTauDiMuMassh300a7_->SetLineColor(kYellow+1);
  DiMuDiTauDeltaPhih300a7_->SetLineColor(kYellow+1);
  METDiTauDeltaPhih300a7_->SetLineColor(kYellow+1);
  METDiMuDeltaPhih300a7_->SetLineColor(kYellow+1);
  DiTaudRh300a7_->SetLineColor(kYellow+1);
  DiTauMassSmallerdRh300a7_->SetLineColor(kYellow+1);
  HighestCSVInclJeth300a7_->SetLineColor(kYellow+1);

  ////////////////
  // h300a9
  ////////////////
  NMedIsoTausWithMu3h300a9_->SetLineColor(kOrange+9);
  InvMassTauHadMu3h300a9_->SetLineColor(kOrange+9);
  PtTauHadMu3h300a9_->SetLineColor(kOrange+9);
  InvMassUpsilonRangeh300a9_->SetLineColor(kOrange+9);
  InvMassZPeakRangeh300a9_->SetLineColor(kOrange+9);
  InvMassFullRangeh300a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrBarrh300a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrEndch300a9_->SetLineColor(kOrange+9);
  InvMassDiMuEndcEndch300a9_->SetLineColor(kOrange+9);
  Mu1Pth300a9_->SetLineColor(kOrange+9);
  Mu2Pth300a9_->SetLineColor(kOrange+9);
  DiMuPth300a9_->SetLineColor(kOrange+9);
  Mu1Etah300a9_->SetLineColor(kOrange+9);
  Mu2Etah300a9_->SetLineColor(kOrange+9);
  DiTauEtah300a9_->SetLineColor(kOrange+9);
  DiTauPhih300a9_->SetLineColor(kOrange+9);
  DiMuEtah300a9_->SetLineColor(kOrange+9);
  DiMudRh300a9_->SetLineColor(kOrange+9);
  DiMuPhih300a9_->SetLineColor(kOrange+9);
  EtMETh300a9_->SetLineColor(kOrange+9);
  DiTauDiMuMassh300a9_->SetLineColor(kOrange+9);
  DiMuDiTauDeltaPhih300a9_->SetLineColor(kOrange+9);
  METDiTauDeltaPhih300a9_->SetLineColor(kOrange+9);
  METDiMuDeltaPhih300a9_->SetLineColor(kOrange+9);
  DiTaudRh300a9_->SetLineColor(kOrange+9);
  DiTauMassSmallerdRh300a9_->SetLineColor(kOrange+9);
  HighestCSVInclJeth300a9_->SetLineColor(kOrange+9);

  ////////////////
  // h750a11
  ////////////////
  NMedIsoTausWithMu3h750a11_->SetLineColor(kGray+1);
  InvMassTauHadMu3h750a11_->SetLineColor(kGray+1);
  PtTauHadMu3h750a11_->SetLineColor(kGray+1);
  InvMassUpsilonRangeh750a11_->SetLineColor(kGray+1);
  InvMassZPeakRangeh750a11_->SetLineColor(kGray+1);
  InvMassFullRangeh750a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrBarrh750a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrEndch750a11_->SetLineColor(kGray+1);
  InvMassDiMuEndcEndch750a11_->SetLineColor(kGray+1);
  Mu1Pth750a11_->SetLineColor(kGray+1);
  Mu2Pth750a11_->SetLineColor(kGray+1);
  DiMuPth750a11_->SetLineColor(kGray+1);
  Mu1Etah750a11_->SetLineColor(kGray+1);
  Mu2Etah750a11_->SetLineColor(kGray+1);
  DiTauEtah750a11_->SetLineColor(kGray+1);
  DiTauPhih750a11_->SetLineColor(kGray+1);
  DiMuEtah750a11_->SetLineColor(kGray+1);
  DiMudRh750a11_->SetLineColor(kGray+1);
  DiMuPhih750a11_->SetLineColor(kGray+1);
  EtMETh750a11_->SetLineColor(kGray+1);
  DiTauDiMuMassh750a11_->SetLineColor(kGray+1);
  DiMuDiTauDeltaPhih750a11_->SetLineColor(kGray+1);
  METDiTauDeltaPhih750a11_->SetLineColor(kGray+1);
  METDiMuDeltaPhih750a11_->SetLineColor(kGray+1);
  DiTaudRh750a11_->SetLineColor(kGray+1);
  DiTauMassSmallerdRh750a11_->SetLineColor(kGray+1);
  HighestCSVInclJeth750a11_->SetLineColor(kGray+1);

  ////////////////
  // h750a13
  ////////////////
  NMedIsoTausWithMu3h750a13_->SetLineColor(kGreen);
  InvMassTauHadMu3h750a13_->SetLineColor(kGreen);
  PtTauHadMu3h750a13_->SetLineColor(kGreen);
  InvMassUpsilonRangeh750a13_->SetLineColor(kGreen);
  InvMassZPeakRangeh750a13_->SetLineColor(kGreen);
  InvMassFullRangeh750a13_->SetLineColor(kGreen);
  InvMassDiMuBarrBarrh750a13_->SetLineColor(kGreen);
  InvMassDiMuBarrEndch750a13_->SetLineColor(kGreen);
  InvMassDiMuEndcEndch750a13_->SetLineColor(kGreen);
  Mu1Pth750a13_->SetLineColor(kGreen);
  Mu2Pth750a13_->SetLineColor(kGreen);
  DiMuPth750a13_->SetLineColor(kGreen);
  Mu1Etah750a13_->SetLineColor(kGreen);
  Mu2Etah750a13_->SetLineColor(kGreen);
  DiTauEtah750a13_->SetLineColor(kGreen);
  DiTauPhih750a13_->SetLineColor(kGreen);
  DiMuEtah750a13_->SetLineColor(kGreen);
  DiMudRh750a13_->SetLineColor(kGreen);
  DiMuPhih750a13_->SetLineColor(kGreen);
  EtMETh750a13_->SetLineColor(kGreen);
  DiTauDiMuMassh750a13_->SetLineColor(kGreen);
  DiMuDiTauDeltaPhih750a13_->SetLineColor(kGreen);
  METDiTauDeltaPhih750a13_->SetLineColor(kGreen);
  METDiMuDeltaPhih750a13_->SetLineColor(kGreen);
  DiTaudRh750a13_->SetLineColor(kGreen);
  DiTauMassSmallerdRh750a13_->SetLineColor(kGreen);
  HighestCSVInclJeth750a13_->SetLineColor(kGreen);

  ////////////////
  // h750a15
  ////////////////
  NMedIsoTausWithMu3h750a15_->SetLineColor(kTeal-1);
  InvMassTauHadMu3h750a15_->SetLineColor(kTeal-1);
  PtTauHadMu3h750a15_->SetLineColor(kTeal-1);
  InvMassUpsilonRangeh750a15_->SetLineColor(kTeal-1);
  InvMassZPeakRangeh750a15_->SetLineColor(kTeal-1);
  InvMassFullRangeh750a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrBarrh750a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrEndch750a15_->SetLineColor(kTeal-1);
  InvMassDiMuEndcEndch750a15_->SetLineColor(kTeal-1);
  Mu1Pth750a15_->SetLineColor(kTeal-1);
  Mu2Pth750a15_->SetLineColor(kTeal-1);
  DiMuPth750a15_->SetLineColor(kTeal-1);
  Mu1Etah750a15_->SetLineColor(kTeal-1);
  Mu2Etah750a15_->SetLineColor(kTeal-1);
  DiTauEtah750a15_->SetLineColor(kTeal-1);
  DiTauPhih750a15_->SetLineColor(kTeal-1);
  DiMuEtah750a15_->SetLineColor(kTeal-1);
  DiMudRh750a15_->SetLineColor(kTeal-1);
  DiMuPhih750a15_->SetLineColor(kTeal-1);
  EtMETh750a15_->SetLineColor(kTeal-1);
  DiTauDiMuMassh750a15_->SetLineColor(kTeal-1);
  DiMuDiTauDeltaPhih750a15_->SetLineColor(kTeal-1);
  METDiTauDeltaPhih750a15_->SetLineColor(kTeal-1);
  METDiMuDeltaPhih750a15_->SetLineColor(kTeal-1);
  DiTaudRh750a15_->SetLineColor(kTeal-1);
  DiTauMassSmallerdRh750a15_->SetLineColor(kTeal-1);
  HighestCSVInclJeth750a15_->SetLineColor(kTeal-1);

  ////////////////
  // h750a17
  ////////////////
  NMedIsoTausWithMu3h750a17_->SetLineColor(kCyan);
  InvMassTauHadMu3h750a17_->SetLineColor(kCyan);
  PtTauHadMu3h750a17_->SetLineColor(kCyan);
  InvMassUpsilonRangeh750a17_->SetLineColor(kCyan);
  InvMassZPeakRangeh750a17_->SetLineColor(kCyan);
  InvMassFullRangeh750a17_->SetLineColor(kCyan);
  InvMassDiMuBarrBarrh750a17_->SetLineColor(kCyan);
  InvMassDiMuBarrEndch750a17_->SetLineColor(kCyan);
  InvMassDiMuEndcEndch750a17_->SetLineColor(kCyan);
  Mu1Pth750a17_->SetLineColor(kCyan);
  Mu2Pth750a17_->SetLineColor(kCyan);
  DiMuPth750a17_->SetLineColor(kCyan);
  Mu1Etah750a17_->SetLineColor(kCyan);
  Mu2Etah750a17_->SetLineColor(kCyan);
  DiTauEtah750a17_->SetLineColor(kCyan);
  DiTauPhih750a17_->SetLineColor(kCyan);
  DiMuEtah750a17_->SetLineColor(kCyan);
  DiMudRh750a17_->SetLineColor(kCyan);
  DiMuPhih750a17_->SetLineColor(kCyan);
  EtMETh750a17_->SetLineColor(kCyan);
  DiTauDiMuMassh750a17_->SetLineColor(kCyan);
  DiMuDiTauDeltaPhih750a17_->SetLineColor(kCyan);
  METDiTauDeltaPhih750a17_->SetLineColor(kCyan);
  METDiMuDeltaPhih750a17_->SetLineColor(kCyan);
  DiTaudRh750a17_->SetLineColor(kCyan);
  DiTauMassSmallerdRh750a17_->SetLineColor(kCyan);
  HighestCSVInclJeth750a17_->SetLineColor(kCyan);

  ////////////////
  // h750a19
  ////////////////
  NMedIsoTausWithMu3h750a19_->SetLineColor(kAzure+3);
  InvMassTauHadMu3h750a19_->SetLineColor(kAzure+3);
  PtTauHadMu3h750a19_->SetLineColor(kAzure+3);
  InvMassUpsilonRangeh750a19_->SetLineColor(kAzure+3);
  InvMassZPeakRangeh750a19_->SetLineColor(kAzure+3);
  InvMassFullRangeh750a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrBarrh750a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrEndch750a19_->SetLineColor(kAzure+3);
  InvMassDiMuEndcEndch750a19_->SetLineColor(kAzure+3);
  Mu1Pth750a19_->SetLineColor(kAzure+3);
  Mu2Pth750a19_->SetLineColor(kAzure+3);
  DiMuPth750a19_->SetLineColor(kAzure+3);
  Mu1Etah750a19_->SetLineColor(kAzure+3);
  Mu2Etah750a19_->SetLineColor(kAzure+3);
  DiTauEtah750a19_->SetLineColor(kAzure+3);
  DiTauPhih750a19_->SetLineColor(kAzure+3);
  DiMuEtah750a19_->SetLineColor(kAzure+3);
  DiMudRh750a19_->SetLineColor(kAzure+3);
  DiMuPhih750a19_->SetLineColor(kAzure+3);
  EtMETh750a19_->SetLineColor(kAzure+3);
  DiTauDiMuMassh750a19_->SetLineColor(kAzure+3);
  DiMuDiTauDeltaPhih750a19_->SetLineColor(kAzure+3);
  METDiTauDeltaPhih750a19_->SetLineColor(kAzure+3);
  METDiMuDeltaPhih750a19_->SetLineColor(kAzure+3);
  DiTaudRh750a19_->SetLineColor(kAzure+3);
  DiTauMassSmallerdRh750a19_->SetLineColor(kAzure+3);
  HighestCSVInclJeth750a19_->SetLineColor(kAzure+3);

  ////////////////
  // h750a21
  ////////////////
  NMedIsoTausWithMu3h750a21_->SetLineColor(kBlue);
  InvMassTauHadMu3h750a21_->SetLineColor(kBlue);
  PtTauHadMu3h750a21_->SetLineColor(kBlue);
  InvMassUpsilonRangeh750a21_->SetLineColor(kBlue);
  InvMassZPeakRangeh750a21_->SetLineColor(kBlue);
  InvMassFullRangeh750a21_->SetLineColor(kBlue);
  InvMassDiMuBarrBarrh750a21_->SetLineColor(kBlue);
  InvMassDiMuBarrEndch750a21_->SetLineColor(kBlue);
  InvMassDiMuEndcEndch750a21_->SetLineColor(kBlue);
  Mu1Pth750a21_->SetLineColor(kBlue);
  Mu2Pth750a21_->SetLineColor(kBlue);
  DiMuPth750a21_->SetLineColor(kBlue);
  Mu1Etah750a21_->SetLineColor(kBlue);
  Mu2Etah750a21_->SetLineColor(kBlue);
  DiTauEtah750a21_->SetLineColor(kBlue);
  DiTauPhih750a21_->SetLineColor(kBlue);
  DiMuEtah750a21_->SetLineColor(kBlue);
  DiMudRh750a21_->SetLineColor(kBlue);
  DiMuPhih750a21_->SetLineColor(kBlue);
  EtMETh750a21_->SetLineColor(kBlue);
  DiTauDiMuMassh750a21_->SetLineColor(kBlue);
  DiMuDiTauDeltaPhih750a21_->SetLineColor(kBlue);
  METDiTauDeltaPhih750a21_->SetLineColor(kBlue);
  METDiMuDeltaPhih750a21_->SetLineColor(kBlue);
  DiTaudRh750a21_->SetLineColor(kBlue);
  DiTauMassSmallerdRh750a21_->SetLineColor(kBlue);
  HighestCSVInclJeth750a21_->SetLineColor(kBlue);

  ////////////////
  // h750a5
  ////////////////
  NMedIsoTausWithMu3h750a5_->SetLineColor(kSpring-7);
  InvMassTauHadMu3h750a5_->SetLineColor(kSpring-7);
  PtTauHadMu3h750a5_->SetLineColor(kSpring-7);
  InvMassUpsilonRangeh750a5_->SetLineColor(kSpring-7);
  InvMassZPeakRangeh750a5_->SetLineColor(kSpring-7);
  InvMassFullRangeh750a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrBarrh750a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrEndch750a5_->SetLineColor(kSpring-7);
  InvMassDiMuEndcEndch750a5_->SetLineColor(kSpring-7);
  Mu1Pth750a5_->SetLineColor(kSpring-7);
  Mu2Pth750a5_->SetLineColor(kSpring-7);
  DiMuPth750a5_->SetLineColor(kSpring-7);
  Mu1Etah750a5_->SetLineColor(kSpring-7);
  Mu2Etah750a5_->SetLineColor(kSpring-7);
  DiTauEtah750a5_->SetLineColor(kSpring-7);
  DiTauPhih750a5_->SetLineColor(kSpring-7);
  DiMuEtah750a5_->SetLineColor(kSpring-7);
  DiMudRh750a5_->SetLineColor(kSpring-7);
  DiMuPhih750a5_->SetLineColor(kSpring-7);
  EtMETh750a5_->SetLineColor(kSpring-7);
  DiTauDiMuMassh750a5_->SetLineColor(kSpring-7);
  DiMuDiTauDeltaPhih750a5_->SetLineColor(kSpring-7);
  METDiTauDeltaPhih750a5_->SetLineColor(kSpring-7);
  METDiMuDeltaPhih750a5_->SetLineColor(kSpring-7);
  DiTaudRh750a5_->SetLineColor(kSpring-7);
  DiTauMassSmallerdRh750a5_->SetLineColor(kSpring-7);
  HighestCSVInclJeth750a5_->SetLineColor(kSpring-7);

  ////////////////
  // h750a7
  ////////////////
  NMedIsoTausWithMu3h750a7_->SetLineColor(kYellow+1);
  InvMassTauHadMu3h750a7_->SetLineColor(kYellow+1);
  PtTauHadMu3h750a7_->SetLineColor(kYellow+1);
  InvMassUpsilonRangeh750a7_->SetLineColor(kYellow+1);
  InvMassZPeakRangeh750a7_->SetLineColor(kYellow+1);
  InvMassFullRangeh750a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrBarrh750a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrEndch750a7_->SetLineColor(kYellow+1);
  InvMassDiMuEndcEndch750a7_->SetLineColor(kYellow+1);
  Mu1Pth750a7_->SetLineColor(kYellow+1);
  Mu2Pth750a7_->SetLineColor(kYellow+1);
  DiMuPth750a7_->SetLineColor(kYellow+1);
  Mu1Etah750a7_->SetLineColor(kYellow+1);
  Mu2Etah750a7_->SetLineColor(kYellow+1);
  DiTauEtah750a7_->SetLineColor(kYellow+1);
  DiTauPhih750a7_->SetLineColor(kYellow+1);
  DiMuEtah750a7_->SetLineColor(kYellow+1);
  DiMudRh750a7_->SetLineColor(kYellow+1);
  DiMuPhih750a7_->SetLineColor(kYellow+1);
  EtMETh750a7_->SetLineColor(kYellow+1);
  DiTauDiMuMassh750a7_->SetLineColor(kYellow+1);
  DiMuDiTauDeltaPhih750a7_->SetLineColor(kYellow+1);
  METDiTauDeltaPhih750a7_->SetLineColor(kYellow+1);
  METDiMuDeltaPhih750a7_->SetLineColor(kYellow+1);
  DiTaudRh750a7_->SetLineColor(kYellow+1);
  DiTauMassSmallerdRh750a7_->SetLineColor(kYellow+1);
  HighestCSVInclJeth750a7_->SetLineColor(kYellow+1);

  ////////////////
  // h750a9
  ////////////////
  NMedIsoTausWithMu3h750a9_->SetLineColor(kOrange+9);
  InvMassTauHadMu3h750a9_->SetLineColor(kOrange+9);
  PtTauHadMu3h750a9_->SetLineColor(kOrange+9);
  InvMassUpsilonRangeh750a9_->SetLineColor(kOrange+9);
  InvMassZPeakRangeh750a9_->SetLineColor(kOrange+9);
  InvMassFullRangeh750a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrBarrh750a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrEndch750a9_->SetLineColor(kOrange+9);
  InvMassDiMuEndcEndch750a9_->SetLineColor(kOrange+9);
  Mu1Pth750a9_->SetLineColor(kOrange+9);
  Mu2Pth750a9_->SetLineColor(kOrange+9);
  DiMuPth750a9_->SetLineColor(kOrange+9);
  Mu1Etah750a9_->SetLineColor(kOrange+9);
  Mu2Etah750a9_->SetLineColor(kOrange+9);
  DiTauEtah750a9_->SetLineColor(kOrange+9);
  DiTauPhih750a9_->SetLineColor(kOrange+9);
  DiMuEtah750a9_->SetLineColor(kOrange+9);
  DiMudRh750a9_->SetLineColor(kOrange+9);
  DiMuPhih750a9_->SetLineColor(kOrange+9);
  EtMETh750a9_->SetLineColor(kOrange+9);
  DiTauDiMuMassh750a9_->SetLineColor(kOrange+9);
  DiMuDiTauDeltaPhih750a9_->SetLineColor(kOrange+9);
  METDiTauDeltaPhih750a9_->SetLineColor(kOrange+9);
  METDiMuDeltaPhih750a9_->SetLineColor(kOrange+9);
  DiTaudRh750a9_->SetLineColor(kOrange+9);
  DiTauMassSmallerdRh750a9_->SetLineColor(kOrange+9);
  HighestCSVInclJeth750a9_->SetLineColor(kOrange+9);

  ////////////////
  // QCD
  ////////////////
  NMedIsoTausWithMu3QCD_->SetLineColor(kViolet+2);
  InvMassTauHadMu3QCD_->SetLineColor(kViolet+2);
  PtTauHadMu3QCD_->SetLineColor(kViolet+2);
  InvMassUpsilonRangeQCD_->SetLineColor(kViolet+2);
  InvMassZPeakRangeQCD_->SetLineColor(kViolet+2);
  InvMassFullRangeQCD_->SetLineColor(kViolet+2);
  InvMassDiMuBarrBarrQCD_->SetLineColor(kViolet+2);
  InvMassDiMuBarrEndcQCD_->SetLineColor(kViolet+2);
  InvMassDiMuEndcEndcQCD_->SetLineColor(kViolet+2);
  Mu1PtQCD_->SetLineColor(kViolet+2);
  Mu2PtQCD_->SetLineColor(kViolet+2);
  DiMuPtQCD_->SetLineColor(kViolet+2);
  Mu1EtaQCD_->SetLineColor(kViolet+2);
  Mu2EtaQCD_->SetLineColor(kViolet+2);
  DiTauEtaQCD_->SetLineColor(kViolet+2);
  DiTauPhiQCD_->SetLineColor(kViolet+2);
  DiMuEtaQCD_->SetLineColor(kViolet+2);
  DiMudRQCD_->SetLineColor(kViolet+2);
  DiMuPhiQCD_->SetLineColor(kViolet+2);
  EtMETQCD_->SetLineColor(kViolet+2);
  DiTauDiMuMassQCD_->SetLineColor(kViolet+2);
  DiMuDiTauDeltaPhiQCD_->SetLineColor(kViolet+2);
  METDiTauDeltaPhiQCD_->SetLineColor(kViolet+2);
  METDiMuDeltaPhiQCD_->SetLineColor(kViolet+2);
  DiTaudRQCD_->SetLineColor(kViolet+2);
  DiTauMassSmallerdRQCD_->SetLineColor(kViolet+2);
  HighestCSVInclJetQCD_->SetLineColor(kViolet+2);

  ////////////////
  // DiBoson
  ////////////////
  NMedIsoTausWithMu3DiBoson_->SetLineColor(kPink-9);
  InvMassTauHadMu3DiBoson_->SetLineColor(kPink-9);
  PtTauHadMu3DiBoson_->SetLineColor(kPink-9);
  InvMassUpsilonRangeDiBoson_->SetLineColor(kPink-9);
  InvMassZPeakRangeDiBoson_->SetLineColor(kPink-9);
  InvMassFullRangeDiBoson_->SetLineColor(kPink-9);
  InvMassDiMuBarrBarrDiBoson_->SetLineColor(kPink-9);
  InvMassDiMuBarrEndcDiBoson_->SetLineColor(kPink-9);
  InvMassDiMuEndcEndcDiBoson_->SetLineColor(kPink-9);
  Mu1PtDiBoson_->SetLineColor(kPink-9);
  Mu2PtDiBoson_->SetLineColor(kPink-9);
  DiMuPtDiBoson_->SetLineColor(kPink-9);
  Mu1EtaDiBoson_->SetLineColor(kPink-9);
  Mu2EtaDiBoson_->SetLineColor(kPink-9);
  DiTauEtaDiBoson_->SetLineColor(kPink-9);
  DiTauPhiDiBoson_->SetLineColor(kPink-9);
  DiMuEtaDiBoson_->SetLineColor(kPink-9);
  DiMudRDiBoson_->SetLineColor(kPink-9);
  DiMuPhiDiBoson_->SetLineColor(kPink-9);
  EtMETDiBoson_->SetLineColor(kPink-9);
  DiTauDiMuMassDiBoson_->SetLineColor(kPink-9);
  DiMuDiTauDeltaPhiDiBoson_->SetLineColor(kPink-9);
  METDiTauDeltaPhiDiBoson_->SetLineColor(kPink-9);
  METDiMuDeltaPhiDiBoson_->SetLineColor(kPink-9);
  DiTaudRDiBoson_->SetLineColor(kPink-9);
  DiTauMassSmallerdRDiBoson_->SetLineColor(kPink-9);
  HighestCSVInclJetDiBoson_->SetLineColor(kPink-9);

  ////////////////
  // DY
  ////////////////
  NMedIsoTausWithMu3DY_->SetLineColor(kGray);
  InvMassTauHadMu3DY_->SetLineColor(kGray);
  PtTauHadMu3DY_->SetLineColor(kGray);
  InvMassUpsilonRangeDY_->SetLineColor(kGray);
  InvMassZPeakRangeDY_->SetLineColor(kGray);
  InvMassFullRangeDY_->SetLineColor(kGray);
  InvMassDiMuBarrBarrDY_->SetLineColor(kGray);
  InvMassDiMuBarrEndcDY_->SetLineColor(kGray);
  InvMassDiMuEndcEndcDY_->SetLineColor(kGray);
  Mu1PtDY_->SetLineColor(kGray);
  Mu2PtDY_->SetLineColor(kGray);
  DiMuPtDY_->SetLineColor(kGray);
  Mu1EtaDY_->SetLineColor(kGray);
  Mu2EtaDY_->SetLineColor(kGray);
  DiTauEtaDY_->SetLineColor(kGray);
  DiTauPhiDY_->SetLineColor(kGray);
  DiMuEtaDY_->SetLineColor(kGray);
  DiMudRDY_->SetLineColor(kGray);
  DiMuPhiDY_->SetLineColor(kGray);
  EtMETDY_->SetLineColor(kGray);
  DiTauDiMuMassDY_->SetLineColor(kGray);
  DiMuDiTauDeltaPhiDY_->SetLineColor(kGray);
  METDiTauDeltaPhiDY_->SetLineColor(kGray);
  METDiMuDeltaPhiDY_->SetLineColor(kGray);
  DiTaudRDY_->SetLineColor(kGray);
  DiTauMassSmallerdRDY_->SetLineColor(kGray);
  HighestCSVInclJetDY_->SetLineColor(kGray);

  ////////////////
  // Data
  ////////////////
  NMedIsoTausWithMu3Data_->SetLineColor(kBlack);
  InvMassTauHadMu3Data_->SetLineColor(kBlack);
  PtTauHadMu3Data_->SetLineColor(kBlack);
  InvMassUpsilonRangeData_->SetLineColor(kBlack);
  InvMassZPeakRangeData_->SetLineColor(kBlack);
  InvMassFullRangeData_->SetLineColor(kBlack);
  InvMassDiMuBarrBarrData_->SetLineColor(kBlack);
  InvMassDiMuBarrEndcData_->SetLineColor(kBlack);
  InvMassDiMuEndcEndcData_->SetLineColor(kBlack);
  Mu1PtData_->SetLineColor(kBlack);
  Mu2PtData_->SetLineColor(kBlack);
  DiMuPtData_->SetLineColor(kBlack);
  Mu1EtaData_->SetLineColor(kBlack);
  Mu2EtaData_->SetLineColor(kBlack);
  DiTauEtaData_->SetLineColor(kBlack);
  DiTauPhiData_->SetLineColor(kBlack);
  DiMuEtaData_->SetLineColor(kBlack);
  DiMudRData_->SetLineColor(kBlack);
  DiMuPhiData_->SetLineColor(kBlack);
  EtMETData_->SetLineColor(kBlack);
  DiTauDiMuMassData_->SetLineColor(kBlack);
  DiMuDiTauDeltaPhiData_->SetLineColor(kBlack);
  METDiTauDeltaPhiData_->SetLineColor(kBlack);
  METDiMuDeltaPhiData_->SetLineColor(kBlack);
  DiTaudRData_->SetLineColor(kBlack);
  DiTauMassSmallerdRData_->SetLineColor(kBlack);
  HighestCSVInclJetData_->SetLineColor(kBlack);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting Fill Color
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////
  // QCD
  ////////////////
  NMedIsoTausWithMu3QCD_->SetFillColor(kViolet+2);
  InvMassTauHadMu3QCD_->SetFillColor(kViolet+2);
  PtTauHadMu3QCD_->SetFillColor(kViolet+2);
  InvMassUpsilonRangeQCD_->SetFillColor(kViolet+2);
  InvMassZPeakRangeQCD_->SetFillColor(kViolet+2);
  InvMassFullRangeQCD_->SetFillColor(kViolet+2);
  InvMassDiMuBarrBarrQCD_->SetFillColor(kViolet+2);
  InvMassDiMuBarrEndcQCD_->SetFillColor(kViolet+2);
  InvMassDiMuEndcEndcQCD_->SetFillColor(kViolet+2);
  Mu1PtQCD_->SetFillColor(kViolet+2);
  Mu2PtQCD_->SetFillColor(kViolet+2);
  DiMuPtQCD_->SetFillColor(kViolet+2);
  Mu1EtaQCD_->SetFillColor(kViolet+2);
  Mu2EtaQCD_->SetFillColor(kViolet+2);
  DiTauEtaQCD_->SetFillColor(kViolet+2);
  DiTauPhiQCD_->SetFillColor(kViolet+2);
  DiMuEtaQCD_->SetFillColor(kViolet+2);
  DiMudRQCD_->SetFillColor(kViolet+2);
  DiMuPhiQCD_->SetFillColor(kViolet+2);
  EtMETQCD_->SetFillColor(kViolet+2);
  DiTauDiMuMassQCD_->SetFillColor(kViolet+2);
  DiMuDiTauDeltaPhiQCD_->SetFillColor(kViolet+2);
  METDiTauDeltaPhiQCD_->SetFillColor(kViolet+2);
  METDiMuDeltaPhiQCD_->SetFillColor(kViolet+2);
  DiTaudRQCD_->SetFillColor(kViolet+2);
  DiTauMassSmallerdRQCD_->SetFillColor(kViolet+2);
  HighestCSVInclJetQCD_->SetFillColor(kViolet+2);

  ////////////////
  // DiBoson
  ////////////////
  NMedIsoTausWithMu3DiBoson_->SetFillColor(kPink-9);
  InvMassTauHadMu3DiBoson_->SetFillColor(kPink-9);
  PtTauHadMu3DiBoson_->SetFillColor(kPink-9);
  InvMassUpsilonRangeDiBoson_->SetFillColor(kPink-9);
  InvMassZPeakRangeDiBoson_->SetFillColor(kPink-9);
  InvMassFullRangeDiBoson_->SetFillColor(kPink-9);
  InvMassDiMuBarrBarrDiBoson_->SetFillColor(kPink-9);
  InvMassDiMuBarrEndcDiBoson_->SetFillColor(kPink-9);
  InvMassDiMuEndcEndcDiBoson_->SetFillColor(kPink-9);
  Mu1PtDiBoson_->SetFillColor(kPink-9);
  Mu2PtDiBoson_->SetFillColor(kPink-9);
  DiMuPtDiBoson_->SetFillColor(kPink-9);
  Mu1EtaDiBoson_->SetFillColor(kPink-9);
  Mu2EtaDiBoson_->SetFillColor(kPink-9);
  DiTauEtaDiBoson_->SetFillColor(kPink-9);
  DiTauPhiDiBoson_->SetFillColor(kPink-9);
  DiMuEtaDiBoson_->SetFillColor(kPink-9);
  DiMudRDiBoson_->SetFillColor(kPink-9);
  DiMuPhiDiBoson_->SetFillColor(kPink-9);
  EtMETDiBoson_->SetFillColor(kPink-9);
  DiTauDiMuMassDiBoson_->SetFillColor(kPink-9);
  DiMuDiTauDeltaPhiDiBoson_->SetFillColor(kPink-9);
  METDiTauDeltaPhiDiBoson_->SetFillColor(kPink-9);
  METDiMuDeltaPhiDiBoson_->SetFillColor(kPink-9);
  DiTaudRDiBoson_->SetFillColor(kPink-9);
  DiTauMassSmallerdRDiBoson_->SetFillColor(kPink-9);
  HighestCSVInclJetDiBoson_->SetFillColor(kPink-9);

  ////////////////
  // DY
  ////////////////
  NMedIsoTausWithMu3DY_->SetFillColor(kGray);
  InvMassTauHadMu3DY_->SetFillColor(kGray);
  PtTauHadMu3DY_->SetFillColor(kGray);
  InvMassUpsilonRangeDY_->SetFillColor(kGray);
  InvMassZPeakRangeDY_->SetFillColor(kGray);
  InvMassFullRangeDY_->SetFillColor(kGray);
  InvMassDiMuBarrBarrDY_->SetFillColor(kGray);
  InvMassDiMuBarrEndcDY_->SetFillColor(kGray);
  InvMassDiMuEndcEndcDY_->SetFillColor(kGray);
  Mu1PtDY_->SetFillColor(kGray);
  Mu2PtDY_->SetFillColor(kGray);
  DiMuPtDY_->SetFillColor(kGray);
  Mu1EtaDY_->SetFillColor(kGray);
  Mu2EtaDY_->SetFillColor(kGray);
  DiTauEtaDY_->SetFillColor(kGray);
  DiTauPhiDY_->SetFillColor(kGray);
  DiMuEtaDY_->SetFillColor(kGray);
  DiMudRDY_->SetFillColor(kGray);
  DiMuPhiDY_->SetFillColor(kGray);
  EtMETDY_->SetFillColor(kGray);
  DiTauDiMuMassDY_->SetFillColor(kGray);
  DiMuDiTauDeltaPhiDY_->SetFillColor(kGray);
  METDiTauDeltaPhiDY_->SetFillColor(kGray);
  METDiMuDeltaPhiDY_->SetFillColor(kGray);
  DiTaudRDY_->SetFillColor(kGray);
  DiTauMassSmallerdRDY_->SetFillColor(kGray);
  HighestCSVInclJetDY_->SetFillColor(kGray);

  ////////////////
  // Data
  ////////////////
  NMedIsoTausWithMu3Data_->SetFillColor(kBlack);
  InvMassTauHadMu3Data_->SetFillColor(kBlack);
  PtTauHadMu3Data_->SetFillColor(kBlack);
  InvMassUpsilonRangeData_->SetFillColor(kBlack);
  InvMassZPeakRangeData_->SetFillColor(kBlack);
  InvMassFullRangeData_->SetFillColor(kBlack);
  InvMassDiMuBarrBarrData_->SetFillColor(kBlack);
  InvMassDiMuBarrEndcData_->SetFillColor(kBlack);
  InvMassDiMuEndcEndcData_->SetFillColor(kBlack);
  Mu1PtData_->SetFillColor(kBlack);
  Mu2PtData_->SetFillColor(kBlack);
  DiMuPtData_->SetFillColor(kBlack);
  Mu1EtaData_->SetFillColor(kBlack);
  Mu2EtaData_->SetFillColor(kBlack);
  DiTauEtaData_->SetFillColor(kBlack);
  DiTauPhiData_->SetFillColor(kBlack);
  DiMuEtaData_->SetFillColor(kBlack);
  DiMudRData_->SetFillColor(kBlack);
  DiMuPhiData_->SetFillColor(kBlack);
  EtMETData_->SetFillColor(kBlack);
  DiTauDiMuMassData_->SetFillColor(kBlack);
  DiMuDiTauDeltaPhiData_->SetFillColor(kBlack);
  METDiTauDeltaPhiData_->SetFillColor(kBlack);
  METDiMuDeltaPhiData_->SetFillColor(kBlack);
  DiTaudRData_->SetFillColor(kBlack);
  DiTauMassSmallerdRData_->SetFillColor(kBlack);
  HighestCSVInclJetData_->SetFillColor(kBlack);

cout << "Set Colors" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Making the stack
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  THStack *NMedIsoTausWithMu3Stack = new THStack ("NMedIsoTausWithMu3Stack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *InvMassTauHadMu3Stack = new THStack ("InvMassTauHadMu3Stack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *PtTauHadMu3Stack = new THStack ("PtTauHadMu3Stack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *InvMassUpsilonRangeStack = new THStack ("InvMassUpsilonRangeStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *InvMassZPeakRangeStack = new THStack ("InvMassUpsilonRangeStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *InvMassFullRangeStack = new THStack ("InvMassFullRangeStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *InvMassDiMuBarrBarrStack = new THStack ("InvMassDiMuBarrBarrStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *InvMassDiMuBarrEndcStack = new THStack ("InvMassDiMuBarrEndcStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *InvMassDiMuEndcEndcStack = new THStack ("InvMassDiMuEndcEndcStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *Mu1PtStack = new THStack ("Mu1PtStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *Mu2PtStack = new THStack ("Mu2PtStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *DiMuPtStack = new THStack ("DiMuPtStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *Mu1EtaStack = new THStack ("Mu1EtaStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *Mu2EtaStack = new THStack ("Mu2EtaStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *DiTauEtaStack = new THStack ("DiTauEtaStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *DiTauPhiStack = new THStack ("DiTauPhiStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *DiMuEtaStack = new THStack ("DiMuEtaStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *DiMudRStack = new THStack ("DiMudRStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *DiMuPhiStack = new THStack ("DiMuPhiStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *EtMETStack = new THStack ("EtMETStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *DiTauDiMuMassStack = new THStack ("DiTauDiMuMassStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *DiMuDiTauDeltaPhiStack = new THStack ("DiMuDiTauDeltaPhiStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *METDiTauDeltaPhiStack = new THStack ("METDiTauDeltaPhiStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *METDiMuDeltaPhiStack = new THStack ("METDiMuDeltaPhiStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *DiTaudRStack = new THStack ("DiTaudRStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *DiTauMassSmallerdRStack = new THStack ("DiTauMassSmallerdRStack","Iso(#mu#mu) Iso(#tau#tau)");
  THStack *HighestCSVInclJetStack = new THStack ("HighestCSVInclJetStack","Iso(#mu#mu) Iso(#tau#tau)");
 
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3QCD_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3DiBoson_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3DY_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3TT_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3h125a5_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3h125a7_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3h125a9_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3h125a11_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3h125a13_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3h125a15_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3h125a17_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3h125a19_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3h125a21_);

  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3QCD_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3DiBoson_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3DY_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3TT_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3h125a5_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3h125a7_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3h125a9_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3h125a11_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3h125a13_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3h125a15_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3h125a17_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3h125a19_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3h125a21_);

  PtTauHadMu3Stack->Add(PtTauHadMu3QCD_);
  PtTauHadMu3Stack->Add(PtTauHadMu3DiBoson_);
  PtTauHadMu3Stack->Add(PtTauHadMu3DY_);
  PtTauHadMu3Stack->Add(PtTauHadMu3TT_);
  PtTauHadMu3Stack->Add(PtTauHadMu3h125a5_);
  PtTauHadMu3Stack->Add(PtTauHadMu3h125a7_);
  PtTauHadMu3Stack->Add(PtTauHadMu3h125a9_);
  PtTauHadMu3Stack->Add(PtTauHadMu3h125a11_);
  PtTauHadMu3Stack->Add(PtTauHadMu3h125a13_);
  PtTauHadMu3Stack->Add(PtTauHadMu3h125a15_);
  PtTauHadMu3Stack->Add(PtTauHadMu3h125a17_);
  PtTauHadMu3Stack->Add(PtTauHadMu3h125a19_);
  PtTauHadMu3Stack->Add(PtTauHadMu3h125a21_);

  InvMassUpsilonRangeStack->Add(InvMassUpsilonRangeQCD_);
  InvMassUpsilonRangeStack->Add(InvMassUpsilonRangeDiBoson_);
  InvMassUpsilonRangeStack->Add(InvMassUpsilonRangeDY_);
  InvMassUpsilonRangeStack->Add(InvMassUpsilonRangeTT_);
  InvMassUpsilonRangeStack->Add(InvMassUpsilonRangeh125a5_);
  InvMassUpsilonRangeStack->Add(InvMassUpsilonRangeh125a7_);
  InvMassUpsilonRangeStack->Add(InvMassUpsilonRangeh125a9_);
  InvMassUpsilonRangeStack->Add(InvMassUpsilonRangeh125a11_);
  InvMassUpsilonRangeStack->Add(InvMassUpsilonRangeh125a13_);
  InvMassUpsilonRangeStack->Add(InvMassUpsilonRangeh125a15_);
  InvMassUpsilonRangeStack->Add(InvMassUpsilonRangeh125a17_);
  InvMassUpsilonRangeStack->Add(InvMassUpsilonRangeh125a19_);
  InvMassUpsilonRangeStack->Add(InvMassUpsilonRangeh125a21_);

  InvMassZPeakRangeStack->Add(InvMassZPeakRangeQCD_);
  InvMassZPeakRangeStack->Add(InvMassZPeakRangeDiBoson_);
  InvMassZPeakRangeStack->Add(InvMassZPeakRangeDY_);
  InvMassZPeakRangeStack->Add(InvMassZPeakRangeTT_);
  InvMassZPeakRangeStack->Add(InvMassZPeakRangeh125a5_);
  InvMassZPeakRangeStack->Add(InvMassZPeakRangeh125a7_);
  InvMassZPeakRangeStack->Add(InvMassZPeakRangeh125a9_);
  InvMassZPeakRangeStack->Add(InvMassZPeakRangeh125a11_);
  InvMassZPeakRangeStack->Add(InvMassZPeakRangeh125a13_);
  InvMassZPeakRangeStack->Add(InvMassZPeakRangeh125a15_);
  InvMassZPeakRangeStack->Add(InvMassZPeakRangeh125a17_);
  InvMassZPeakRangeStack->Add(InvMassZPeakRangeh125a19_);
  InvMassZPeakRangeStack->Add(InvMassZPeakRangeh125a21_);

  InvMassFullRangeStack->Add(InvMassFullRangeQCD_);
  InvMassFullRangeStack->Add(InvMassFullRangeDiBoson_);
  InvMassFullRangeStack->Add(InvMassFullRangeDY_);
  InvMassFullRangeStack->Add(InvMassFullRangeTT_);
  InvMassFullRangeStack->Add(InvMassFullRangeh125a5_);
  InvMassFullRangeStack->Add(InvMassFullRangeh125a7_);
  InvMassFullRangeStack->Add(InvMassFullRangeh125a9_);
  InvMassFullRangeStack->Add(InvMassFullRangeh125a11_);
  InvMassFullRangeStack->Add(InvMassFullRangeh125a13_);
  InvMassFullRangeStack->Add(InvMassFullRangeh125a15_);
  InvMassFullRangeStack->Add(InvMassFullRangeh125a17_);
  InvMassFullRangeStack->Add(InvMassFullRangeh125a19_);
  InvMassFullRangeStack->Add(InvMassFullRangeh125a21_);

  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrQCD_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrDiBoson_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrDY_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrTT_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrh125a5_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrh125a7_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrh125a9_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrh125a11_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrh125a13_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrh125a15_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrh125a17_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrh125a19_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrh125a21_);

  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndcQCD_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndcDiBoson_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndcDY_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndcTT_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndch125a5_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndch125a7_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndch125a9_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndch125a11_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndch125a13_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndch125a15_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndch125a17_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndch125a19_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndch125a21_);

  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndcQCD_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndcDiBoson_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndcDY_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndcTT_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndch125a5_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndch125a7_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndch125a9_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndch125a11_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndch125a13_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndch125a15_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndch125a17_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndch125a19_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndch125a21_);

  Mu1PtStack->Add(Mu1PtQCD_);
  Mu1PtStack->Add(Mu1PtDiBoson_);
  Mu1PtStack->Add(Mu1PtDY_);
  Mu1PtStack->Add(Mu1PtTT_);
  Mu1PtStack->Add(Mu1Pth125a5_);
  Mu1PtStack->Add(Mu1Pth125a7_);
  Mu1PtStack->Add(Mu1Pth125a9_);
  Mu1PtStack->Add(Mu1Pth125a11_);
  Mu1PtStack->Add(Mu1Pth125a13_);
  Mu1PtStack->Add(Mu1Pth125a15_);
  Mu1PtStack->Add(Mu1Pth125a17_);
  Mu1PtStack->Add(Mu1Pth125a19_);
  Mu1PtStack->Add(Mu1Pth125a21_);

  Mu2PtStack->Add(Mu2PtQCD_);
  Mu2PtStack->Add(Mu2PtDiBoson_);
  Mu2PtStack->Add(Mu2PtDY_);
  Mu2PtStack->Add(Mu2PtTT_);
  Mu2PtStack->Add(Mu2Pth125a5_);
  Mu2PtStack->Add(Mu2Pth125a7_);
  Mu2PtStack->Add(Mu2Pth125a9_);
  Mu2PtStack->Add(Mu2Pth125a11_);
  Mu2PtStack->Add(Mu2Pth125a13_);
  Mu2PtStack->Add(Mu2Pth125a15_);
  Mu2PtStack->Add(Mu2Pth125a17_);
  Mu2PtStack->Add(Mu2Pth125a19_);
  Mu2PtStack->Add(Mu2Pth125a21_);

  DiMuPtStack->Add(DiMuPtQCD_);
  DiMuPtStack->Add(DiMuPtDiBoson_);
  DiMuPtStack->Add(DiMuPtDY_);
  DiMuPtStack->Add(DiMuPtTT_);
  DiMuPtStack->Add(DiMuPth125a5_);
  DiMuPtStack->Add(DiMuPth125a7_);
  DiMuPtStack->Add(DiMuPth125a9_);
  DiMuPtStack->Add(DiMuPth125a11_);
  DiMuPtStack->Add(DiMuPth125a13_);
  DiMuPtStack->Add(DiMuPth125a15_);
  DiMuPtStack->Add(DiMuPth125a17_);
  DiMuPtStack->Add(DiMuPth125a19_);
  DiMuPtStack->Add(DiMuPth125a21_);

  Mu1EtaStack->Add(Mu1EtaQCD_);
  Mu1EtaStack->Add(Mu1EtaDiBoson_);
  Mu1EtaStack->Add(Mu1EtaDY_);
  Mu1EtaStack->Add(Mu1EtaTT_);
  Mu1EtaStack->Add(Mu1Etah125a5_);
  Mu1EtaStack->Add(Mu1Etah125a7_);
  Mu1EtaStack->Add(Mu1Etah125a9_);
  Mu1EtaStack->Add(Mu1Etah125a11_);
  Mu1EtaStack->Add(Mu1Etah125a13_);
  Mu1EtaStack->Add(Mu1Etah125a15_);
  Mu1EtaStack->Add(Mu1Etah125a17_);
  Mu1EtaStack->Add(Mu1Etah125a19_);
  Mu1EtaStack->Add(Mu1Etah125a21_);

  Mu2EtaStack->Add(Mu2EtaQCD_);
  Mu2EtaStack->Add(Mu2EtaDiBoson_);
  Mu2EtaStack->Add(Mu2EtaDY_);
  Mu2EtaStack->Add(Mu2EtaTT_);
  Mu2EtaStack->Add(Mu2Etah125a5_);
  Mu2EtaStack->Add(Mu2Etah125a7_);
  Mu2EtaStack->Add(Mu2Etah125a9_);
  Mu2EtaStack->Add(Mu2Etah125a11_);
  Mu2EtaStack->Add(Mu2Etah125a13_);
  Mu2EtaStack->Add(Mu2Etah125a15_);
  Mu2EtaStack->Add(Mu2Etah125a17_);
  Mu2EtaStack->Add(Mu2Etah125a19_);
  Mu2EtaStack->Add(Mu2Etah125a21_);

  DiTauEtaStack->Add(DiTauEtaQCD_);
  DiTauEtaStack->Add(DiTauEtaDiBoson_);
  DiTauEtaStack->Add(DiTauEtaDY_);
  DiTauEtaStack->Add(DiTauEtaTT_);
  DiTauEtaStack->Add(DiTauEtah125a5_);
  DiTauEtaStack->Add(DiTauEtah125a7_);
  DiTauEtaStack->Add(DiTauEtah125a9_);
  DiTauEtaStack->Add(DiTauEtah125a11_);
  DiTauEtaStack->Add(DiTauEtah125a13_);
  DiTauEtaStack->Add(DiTauEtah125a15_);
  DiTauEtaStack->Add(DiTauEtah125a17_);
  DiTauEtaStack->Add(DiTauEtah125a19_);
  DiTauEtaStack->Add(DiTauEtah125a21_);

  DiTauPhiStack->Add(DiTauPhiQCD_);
  DiTauPhiStack->Add(DiTauPhiDiBoson_);
  DiTauPhiStack->Add(DiTauPhiDY_);
  DiTauPhiStack->Add(DiTauPhiTT_);
  DiTauPhiStack->Add(DiTauPhih125a5_);
  DiTauPhiStack->Add(DiTauPhih125a7_);
  DiTauPhiStack->Add(DiTauPhih125a9_);
  DiTauPhiStack->Add(DiTauPhih125a11_);
  DiTauPhiStack->Add(DiTauPhih125a13_);
  DiTauPhiStack->Add(DiTauPhih125a15_);
  DiTauPhiStack->Add(DiTauPhih125a17_);
  DiTauPhiStack->Add(DiTauPhih125a19_);
  DiTauPhiStack->Add(DiTauPhih125a21_);

  DiMuEtaStack->Add(DiMuEtaQCD_);
  DiMuEtaStack->Add(DiMuEtaDiBoson_);
  DiMuEtaStack->Add(DiMuEtaDY_);
  DiMuEtaStack->Add(DiMuEtaTT_);
  DiMuEtaStack->Add(DiMuEtah125a5_);
  DiMuEtaStack->Add(DiMuEtah125a7_);
  DiMuEtaStack->Add(DiMuEtah125a9_);
  DiMuEtaStack->Add(DiMuEtah125a11_);
  DiMuEtaStack->Add(DiMuEtah125a13_);
  DiMuEtaStack->Add(DiMuEtah125a15_);
  DiMuEtaStack->Add(DiMuEtah125a17_);
  DiMuEtaStack->Add(DiMuEtah125a19_);
  DiMuEtaStack->Add(DiMuEtah125a21_);

  DiMudRStack->Add(DiMudRQCD_);
  DiMudRStack->Add(DiMudRDiBoson_);
  DiMudRStack->Add(DiMudRDY_);
  DiMudRStack->Add(DiMudRTT_);
  DiMudRStack->Add(DiMudRh125a5_);
  DiMudRStack->Add(DiMudRh125a7_);
  DiMudRStack->Add(DiMudRh125a9_);
  DiMudRStack->Add(DiMudRh125a11_);
  DiMudRStack->Add(DiMudRh125a13_);
  DiMudRStack->Add(DiMudRh125a15_);
  DiMudRStack->Add(DiMudRh125a17_);
  DiMudRStack->Add(DiMudRh125a19_);
  DiMudRStack->Add(DiMudRh125a21_);

  DiMuPhiStack->Add(DiMuPhiQCD_);
  DiMuPhiStack->Add(DiMuPhiDiBoson_);
  DiMuPhiStack->Add(DiMuPhiDY_);
  DiMuPhiStack->Add(DiMuPhiTT_);
  DiMuPhiStack->Add(DiMuPhih125a5_);
  DiMuPhiStack->Add(DiMuPhih125a7_);
  DiMuPhiStack->Add(DiMuPhih125a9_);
  DiMuPhiStack->Add(DiMuPhih125a11_);
  DiMuPhiStack->Add(DiMuPhih125a13_);
  DiMuPhiStack->Add(DiMuPhih125a15_);
  DiMuPhiStack->Add(DiMuPhih125a17_);
  DiMuPhiStack->Add(DiMuPhih125a19_);
  DiMuPhiStack->Add(DiMuPhih125a21_);

  EtMETStack->Add(EtMETQCD_);
  EtMETStack->Add(EtMETDiBoson_);
  EtMETStack->Add(EtMETDY_);
  EtMETStack->Add(EtMETTT_);
  EtMETStack->Add(EtMETh125a5_);
  EtMETStack->Add(EtMETh125a7_);
  EtMETStack->Add(EtMETh125a9_);
  EtMETStack->Add(EtMETh125a11_);
  EtMETStack->Add(EtMETh125a13_);
  EtMETStack->Add(EtMETh125a15_);
  EtMETStack->Add(EtMETh125a17_);
  EtMETStack->Add(EtMETh125a19_);
  EtMETStack->Add(EtMETh125a21_);

  DiTauDiMuMassStack->Add(DiTauDiMuMassQCD_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassDiBoson_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassDY_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassTT_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassh125a5_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassh125a7_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassh125a9_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassh125a11_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassh125a13_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassh125a15_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassh125a17_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassh125a19_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassh125a21_);

  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhiQCD_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhiDiBoson_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhiDY_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhiTT_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhih125a5_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhih125a7_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhih125a9_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhih125a11_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhih125a13_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhih125a15_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhih125a17_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhih125a19_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhih125a21_);

  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhiQCD_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhiDiBoson_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhiDY_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhiTT_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhih125a5_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhih125a7_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhih125a9_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhih125a11_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhih125a13_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhih125a15_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhih125a17_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhih125a19_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhih125a21_);

  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhiQCD_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhiDiBoson_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhiDY_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhiTT_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhih125a5_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhih125a7_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhih125a9_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhih125a11_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhih125a13_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhih125a15_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhih125a17_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhih125a19_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhih125a21_);


  DiTaudRStack->Add(DiTaudRQCD_);
  DiTaudRStack->Add(DiTaudRDiBoson_);
  DiTaudRStack->Add(DiTaudRDY_);
  DiTaudRStack->Add(DiTaudRTT_);
  DiTaudRStack->Add(DiTaudRh125a5_);
  DiTaudRStack->Add(DiTaudRh125a7_);
  DiTaudRStack->Add(DiTaudRh125a9_);
  DiTaudRStack->Add(DiTaudRh125a11_);
  DiTaudRStack->Add(DiTaudRh125a13_);
  DiTaudRStack->Add(DiTaudRh125a15_);
  DiTaudRStack->Add(DiTaudRh125a17_);
  DiTaudRStack->Add(DiTaudRh125a19_);
  DiTaudRStack->Add(DiTaudRh125a21_);

  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRQCD_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRDiBoson_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRDY_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRTT_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRh125a5_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRh125a7_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRh125a9_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRh125a11_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRh125a13_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRh125a15_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRh125a17_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRh125a19_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRh125a21_);

  HighestCSVInclJetStack->Add(HighestCSVInclJetQCD_);
  HighestCSVInclJetStack->Add(HighestCSVInclJetDiBoson_);
  HighestCSVInclJetStack->Add(HighestCSVInclJetDY_);
  HighestCSVInclJetStack->Add(HighestCSVInclJetTT_);
  HighestCSVInclJetStack->Add(HighestCSVInclJeth125a5_);
  HighestCSVInclJetStack->Add(HighestCSVInclJeth125a7_);
  HighestCSVInclJetStack->Add(HighestCSVInclJeth125a9_);
  HighestCSVInclJetStack->Add(HighestCSVInclJeth125a11_);
  HighestCSVInclJetStack->Add(HighestCSVInclJeth125a13_);
  HighestCSVInclJetStack->Add(HighestCSVInclJeth125a15_);
  HighestCSVInclJetStack->Add(HighestCSVInclJeth125a17_);
  HighestCSVInclJetStack->Add(HighestCSVInclJeth125a19_);
  HighestCSVInclJetStack->Add(HighestCSVInclJeth125a17_);

cout << "Created and Added Stacks" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting the Stack Style
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "NMedIsoTausWithMu3TT_->GetXaxis()->GetTitle()=" << NMedIsoTausWithMu3TT_->GetXaxis()->GetTitle() << endl;
  NMedIsoTausWithMu3Stack->GetXaxis()->SetTitle(NMedIsoTausWithMu3TT_->GetXaxis()->GetTitle() );
std::cout << "check1"<< endl;
  InvMassTauHadMu3Stack->GetXaxis()->SetTitle(InvMassTauHadMu3TT_->GetXaxis()->GetTitle() );
std::cout << "check2"<< endl;
  PtTauHadMu3Stack->GetXaxis()->SetTitle(PtTauHadMu3TT_->GetXaxis()->GetTitle() );
std::cout << "check3"<< endl;
  InvMassUpsilonRangeStack->GetXaxis()->SetTitle(InvMassUpsilonRangeTT_->GetXaxis()->GetTitle() );
std::cout << "check4"<< endl;
  InvMassZPeakRangeStack->GetXaxis()->SetTitle(InvMassZPeakRangeTT_->GetXaxis()->GetTitle() );
std::cout << "check5"<< endl;
  InvMassFullRangeStack->GetXaxis()->SetTitle(InvMassFullRangeTT_->GetXaxis()->GetTitle() );
std::cout << "check6"<< endl;
  InvMassDiMuBarrBarrStack->GetXaxis()->SetTitle(InvMassDiMuBarrBarrTT_->GetXaxis()->GetTitle() );
std::cout << "check7"<< endl;
  InvMassDiMuBarrEndcStack->GetXaxis()->SetTitle(InvMassDiMuBarrBarrTT_->GetXaxis()->GetTitle() );
std::cout << "check8"<< endl;
  InvMassDiMuEndcEndcStack->GetXaxis()->SetTitle(InvMassDiMuEndcEndcTT_->GetXaxis()->GetTitle() );
std::cout << "check9"<< endl;
  Mu1PtStack->GetXaxis()->SetTitle(Mu1PtTT_->GetXaxis()->GetTitle() );
std::cout << "check10"<< endl;
  Mu2PtStack->GetXaxis()->SetTitle(Mu2PtTT_->GetXaxis()->GetTitle() );
std::cout << "check11"<< endl;
  DiMuPtStack->GetXaxis()->SetTitle(DiMuPtTT_->GetXaxis()->GetTitle() );
std::cout << "check12"<< endl;
  Mu1EtaStack->GetXaxis()->SetTitle(Mu1EtaTT_->GetXaxis()->GetTitle() );
std::cout << "check13"<< endl;
  Mu2EtaStack->GetXaxis()->SetTitle(Mu2EtaTT_->GetXaxis()->GetTitle() );
std::cout << "check14"<< endl;
  DiTauEtaStack->GetXaxis()->SetTitle(DiTauEtaTT_->GetXaxis()->GetTitle() );
std::cout << "check15"<< endl;
  DiTauPhiStack->GetXaxis()->SetTitle(DiTauPhiTT_->GetXaxis()->GetTitle() );
std::cout << "check16"<< endl;
  DiMuEtaStack->GetXaxis()->SetTitle(DiMuEtaTT_->GetXaxis()->GetTitle() );
std::cout << "check17"<< endl;
  DiMudRStack->GetXaxis()->SetTitle(DiMudRTT_->GetXaxis()->GetTitle() );
std::cout << "check18"<< endl;
  DiMuPhiStack->GetXaxis()->SetTitle(DiMuPhiTT_->GetXaxis()->GetTitle() );
std::cout << "check19"<< endl;
  EtMETStack->GetXaxis()->SetTitle(EtMETTT_->GetXaxis()->GetTitle() );
std::cout << "check20"<< endl;
  DiTauDiMuMassStack->GetXaxis()->SetTitle(DiTauDiMuMassTT_->GetXaxis()->GetTitle() );
std::cout << "check21"<< endl;
  DiMuDiTauDeltaPhiStack->GetXaxis()->SetTitle(DiMuDiTauDeltaPhiTT_->GetXaxis()->GetTitle() );
std::cout << "check22"<< endl;
  METDiTauDeltaPhiStack->GetXaxis()->SetTitle(METDiTauDeltaPhiTT_->GetXaxis()->GetTitle() );
std::cout << "check23"<< endl;
  METDiMuDeltaPhiStack->GetXaxis()->SetTitle(METDiMuDeltaPhiTT_->GetXaxis()->GetTitle() );
std::cout << "check24"<< endl;
  DiTaudRStack->GetXaxis()->SetTitle(DiTaudRTT_->GetXaxis()->GetTitle() );
std::cout << "check25"<< endl;
  DiTauMassSmallerdRStack->GetXaxis()->SetTitle(DiTauMassSmallerdRTT_->GetXaxis()->GetTitle() );
std::cout << "check26"<< endl;
  HighestCSVInclJetStack->GetXaxis()->SetTitle(HighestCSVInclJetTT_->GetXaxis()->GetTitle() );
std::cout << "check27"<< endl;

  NMedIsoTausWithMu3Stack->GetYaxis()->SetTitle(NMedIsoTausWithMu3TT_->GetYaxis()->GetTitle() );
  InvMassTauHadMu3Stack->GetYaxis()->SetTitle(InvMassTauHadMu3TT_->GetYaxis()->GetTitle() );
  PtTauHadMu3Stack->GetYaxis()->SetTitle(PtTauHadMu3TT_->GetYaxis()->GetTitle() );
  InvMassUpsilonRangeStack->GetYaxis()->SetTitle(InvMassUpsilonRangeTT_->GetYaxis()->GetTitle() );
  InvMassZPeakRangeStack->GetYaxis()->SetTitle(InvMassZPeakRangeTT_->GetYaxis()->GetTitle() );
  InvMassFullRangeStack->GetYaxis()->SetTitle(InvMassFullRangeTT_->GetYaxis()->GetTitle() );
  InvMassDiMuBarrBarrStack->GetYaxis()->SetTitle(InvMassDiMuBarrBarrTT_->GetYaxis()->GetTitle() );
  InvMassDiMuBarrEndcStack->GetYaxis()->SetTitle(InvMassDiMuBarrBarrTT_->GetYaxis()->GetTitle() );
  InvMassDiMuEndcEndcStack->GetYaxis()->SetTitle(InvMassDiMuEndcEndcTT_->GetYaxis()->GetTitle() );
  Mu1PtStack->GetYaxis()->SetTitle(Mu1PtTT_->GetYaxis()->GetTitle() );
  Mu2PtStack->GetYaxis()->SetTitle(Mu2PtTT_->GetYaxis()->GetTitle() );
  DiMuPtStack->GetYaxis()->SetTitle(DiMuPtTT_->GetYaxis()->GetTitle() );
  Mu1EtaStack->GetYaxis()->SetTitle(Mu1EtaTT_->GetYaxis()->GetTitle() );
  Mu2EtaStack->GetYaxis()->SetTitle(Mu2EtaTT_->GetYaxis()->GetTitle() );
  DiTauEtaStack->GetYaxis()->SetTitle(DiTauEtaTT_->GetYaxis()->GetTitle() );
  DiTauPhiStack->GetYaxis()->SetTitle(DiTauPhiTT_->GetYaxis()->GetTitle() );
  DiMuEtaStack->GetYaxis()->SetTitle(DiMuEtaTT_->GetYaxis()->GetTitle() );
  DiMudRStack->GetYaxis()->SetTitle(DiMudRTT_->GetYaxis()->GetTitle() );
  DiMuPhiStack->GetYaxis()->SetTitle(DiMuPhiTT_->GetYaxis()->GetTitle() );
  EtMETStack->GetYaxis()->SetTitle(EtMETTT_->GetYaxis()->GetTitle() );
  DiTauDiMuMassStack->GetYaxis()->SetTitle(DiTauDiMuMassTT_->GetYaxis()->GetTitle() );
  DiMuDiTauDeltaPhiStack->GetYaxis()->SetTitle(DiMuDiTauDeltaPhiTT_->GetYaxis()->GetTitle() );
  METDiTauDeltaPhiStack->GetYaxis()->SetTitle(METDiTauDeltaPhiTT_->GetYaxis()->GetTitle() );
  METDiMuDeltaPhiStack->GetYaxis()->SetTitle(METDiMuDeltaPhiTT_->GetYaxis()->GetTitle() );
  DiTaudRStack->GetYaxis()->SetTitle(DiTaudRTT_->GetYaxis()->GetTitle() );
  DiTauMassSmallerdRStack->GetYaxis()->SetTitle(DiTauMassSmallerdRTT_->GetYaxis()->GetTitle() );
  HighestCSVInclJetStack->GetYaxis()->SetTitle(HighestCSVInclJetTT_->GetYaxis()->GetTitle() );

cout << "check 2" << endl;
  NMedIsoTausWithMu3Stack->GetYaxis()->SetLabelSize(0.05);
  InvMassTauHadMu3Stack->GetYaxis()->SetLabelSize(0.05);
  PtTauHadMu3Stack->GetYaxis()->SetLabelSize(0.05);
  InvMassUpsilonRangeStack->GetYaxis()->SetLabelSize(0.05);
  InvMassZPeakRangeStack->GetYaxis()->SetLabelSize(0.05);
  InvMassFullRangeStack->GetYaxis()->SetLabelSize(0.05);
  InvMassDiMuBarrBarrStack->GetYaxis()->SetLabelSize(0.05);
  InvMassDiMuBarrEndcStack->GetYaxis()->SetLabelSize(0.05);
  InvMassDiMuEndcEndcStack->GetYaxis()->SetLabelSize(0.05);
  Mu1PtStack->GetYaxis()->SetLabelSize(0.05);
  Mu2PtStack->GetYaxis()->SetLabelSize(0.05);
  DiMuPtStack->GetYaxis()->SetLabelSize(0.05);
  Mu1EtaStack->GetYaxis()->SetLabelSize(0.05);
  Mu2EtaStack->GetYaxis()->SetLabelSize(0.05);
  DiTauEtaStack->GetYaxis()->SetLabelSize(0.05);
  DiTauPhiStack->GetYaxis()->SetLabelSize(0.05);
  DiMuEtaStack->GetYaxis()->SetLabelSize(0.05);
  DiMudRStack->GetYaxis()->SetLabelSize(0.05);
  DiMuPhiStack->GetYaxis()->SetLabelSize(0.05);
  EtMETStack->GetYaxis()->SetLabelSize(0.05);
  DiTauDiMuMassStack->GetYaxis()->SetLabelSize(0.05);
  DiMuDiTauDeltaPhiStack->GetYaxis()->SetLabelSize(0.05);
  METDiTauDeltaPhiStack->GetYaxis()->SetLabelSize(0.05);
  METDiMuDeltaPhiStack->GetYaxis()->SetLabelSize(0.05);
  DiTaudRStack->GetYaxis()->SetLabelSize(0.05);
  DiTauMassSmallerdRStack->GetYaxis()->SetLabelSize(0.05);
  HighestCSVInclJetStack->GetYaxis()->SetLabelSize(0.05);

cout << "Stylized the Stacks" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the output plots
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *NMedIsoTausWithMu3Canvas = new TCanvas ("NMedIsoTausWithMu3Canvas","",600,600);
  TCanvas *InvMassTauHadMu3Canvas = new TCanvas ("InvMassTauHadMu3Canvas","",600,600);
  TCanvas *PtTauHadMu3Canvas = new TCanvas ("PtTauHadMu3Canvas","",600,600);
  TCanvas *InvMassUpsilonRangeCanvas = new TCanvas ("InvMassUpsilonRangeCanvas","",600,600);
  TCanvas *InvMassZPeakRangeCanvas = new TCanvas ("InvMassUpsilonRangeCanvas","",600,600);
  TCanvas *InvMassFullRangeCanvas = new TCanvas ("InvMassFullRangeCanvas","",600,600);
  TCanvas *InvMassDiMuBarrBarrCanvas = new TCanvas ("InvMassDiMuBarrBarrCanvas","",600,600);
  TCanvas *InvMassDiMuBarrEndcCanvas = new TCanvas ("InvMassDiMuBarrEndcCanvas","",600,600);
  TCanvas *InvMassDiMuEndcEndcCanvas = new TCanvas ("InvMassDiMuEndcEndcCanvas","",600,600);
  TCanvas *Mu1PtCanvas = new TCanvas ("Mu1PtCanvas","",600,600);
  TCanvas *Mu2PtCanvas = new TCanvas ("Mu2PtCanvas","",600,600);
  TCanvas *DiMuPtCanvas = new TCanvas ("DiMuPtCanvas","",600,600);
  TCanvas *Mu1EtaCanvas = new TCanvas ("Mu1EtaCanvas","",600,600);
  TCanvas *Mu2EtaCanvas = new TCanvas ("Mu2EtaCanvas","",600,600);
  TCanvas *DiTauEtaCanvas = new TCanvas ("DiTauEtaCanvas","",600,600);
  TCanvas *DiTauPhiCanvas = new TCanvas ("DiTauPhiCanvas","",600,600);
  TCanvas *DiMuEtaCanvas = new TCanvas ("DiMuEtaCanvas","",600,600);
  TCanvas *DiMudRCanvas = new TCanvas ("DiMudRCanvas","",600,600);
  TCanvas *DiMuPhiCanvas = new TCanvas ("DiMuPhiCanvas","",600,600);
  TCanvas *EtMETCanvas = new TCanvas ("EtMETCanvas","",600,600);
  TCanvas *DiTauDiMuMassCanvas = new TCanvas ("DiTauDiMuMassCanvas","",600,600);
  TCanvas *DiMuDiTauDeltaPhiCanvas = new TCanvas ("DiMuDiTauDeltaPhiCanvas","",600,600);
  TCanvas *METDiTauDeltaPhiCanvas = new TCanvas ("METDiTauDeltaPhiCanvas","",600,600);
  TCanvas *METDiMuDeltaPhiCanvas = new TCanvas ("METDiMuDeltaPhiCanvas","",600,600);
  TCanvas *DiTaudRCanvas = new TCanvas ("DiTaudRCanvas","",600,600);
  TCanvas *DiTauMassSmallerdRCanvas = new TCanvas ("DiTauMassSmallerdRCanvas","",600,600);
  TCanvas *HighestCSVInclJetCanvas = new TCanvas ("HighestCSVInclJetCanvas","",600,600);

  TPad *NMedIsoTausWithMu3PlotPad = new TPad ("NMedIsoTausWithMu3PlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassTauHadMu3PlotPad = new TPad ("InvMassTauHadMu3PlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *PtTauHadMu3PlotPad = new TPad ("PtTauHadMu3PlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassUpsilonRangePlotPad = new TPad ("InvMassUpsilonRangePlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassZPeakRangePlotPad = new TPad ("InvMassUpsilonRangePlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassFullRangePlotPad = new TPad ("InvMassFullRangePlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuBarrBarrPlotPad = new TPad ("InvMassDiMuBarrBarrPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuBarrEndcPlotPad = new TPad ("InvMassDiMuBarrEndcPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuEndcEndcPlotPad = new TPad ("InvMassDiMuEndcEndcPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *Mu1PtPlotPad = new TPad ("Mu1PtPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *Mu2PtPlotPad = new TPad ("Mu2PtPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuPtPlotPad = new TPad ("DiMuPtPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *Mu1EtaPlotPad = new TPad ("Mu1EtaPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *Mu2EtaPlotPad = new TPad ("Mu2EtaPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauEtaPlotPad = new TPad ("DiTauEtaPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauPhiPlotPad = new TPad ("DiTauPhiPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuEtaPlotPad = new TPad ("DiMuEtaPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMudRPlotPad = new TPad ("DiMudRPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuPhiPlotPad = new TPad ("DiMuPhiPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *EtMETPlotPad = new TPad ("EtMETPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauDiMuMassPlotPad = new TPad ("DiTauDiMuMassPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuDiTauDeltaPhiPlotPad = new TPad ("DiMuDiTauDeltaPhiPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *METDiTauDeltaPhiPlotPad = new TPad ("METDiTauDeltaPhiPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *METDiMuDeltaPhiPlotPad = new TPad ("METDiMuDeltaPhiPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTaudRPlotPad = new TPad ("DiTaudRPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauMassSmallerdRPlotPad = new TPad ("DiTauMassSmallerdRPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *HighestCSVInclJetPlotPad = new TPad ("HighestCSVInclJetPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);

  NMedIsoTausWithMu3PlotPad->SetBottomMargin(0.04);
  InvMassTauHadMu3PlotPad->SetBottomMargin(0.04);
  PtTauHadMu3PlotPad->SetBottomMargin(0.04);
  InvMassUpsilonRangePlotPad->SetBottomMargin(0.04);
  InvMassZPeakRangePlotPad->SetBottomMargin(0.04);
  InvMassFullRangePlotPad->SetBottomMargin(0.04);
  InvMassDiMuBarrBarrPlotPad->SetBottomMargin(0.04);
  InvMassDiMuBarrEndcPlotPad->SetBottomMargin(0.04);
  InvMassDiMuEndcEndcPlotPad->SetBottomMargin(0.04);
  Mu1PtPlotPad->SetBottomMargin(0.04);
  Mu2PtPlotPad->SetBottomMargin(0.04);
  DiMuPtPlotPad->SetBottomMargin(0.04);
  Mu1EtaPlotPad->SetBottomMargin(0.04);
  Mu2EtaPlotPad->SetBottomMargin(0.04);
  DiTauEtaPlotPad->SetBottomMargin(0.04);
  DiTauPhiPlotPad->SetBottomMargin(0.04);
  DiMuEtaPlotPad->SetBottomMargin(0.04);
  DiMudRPlotPad->SetBottomMargin(0.04);
  DiMuPhiPlotPad->SetBottomMargin(0.04);
  EtMETPlotPad->SetBottomMargin(0.04);
  DiTauDiMuMassPlotPad->SetBottomMargin(0.04);
  DiMuDiTauDeltaPhiPlotPad->SetBottomMargin(0.04);
  METDiTauDeltaPhiPlotPad->SetBottomMargin(0.04);
  METDiMuDeltaPhiPlotPad->SetBottomMargin(0.04);
  DiTaudRPlotPad->SetBottomMargin(0.04);
  DiTauMassSmallerdRPlotPad->SetBottomMargin(0.04);
  HighestCSVInclJetPlotPad->SetBottomMargin(0.04);
  
  NMedIsoTausWithMu3PlotPad->SetRightMargin(0.03);
  InvMassTauHadMu3PlotPad->SetRightMargin(0.03);
  PtTauHadMu3PlotPad->SetRightMargin(0.03);
  InvMassUpsilonRangePlotPad->SetRightMargin(0.03);
  InvMassZPeakRangePlotPad->SetRightMargin(0.03);
  InvMassFullRangePlotPad->SetRightMargin(0.03);
  InvMassDiMuBarrBarrPlotPad->SetRightMargin(0.03);
  InvMassDiMuBarrEndcPlotPad->SetRightMargin(0.03);
  InvMassDiMuEndcEndcPlotPad->SetRightMargin(0.03);
  Mu1PtPlotPad->SetRightMargin(0.03);
  Mu2PtPlotPad->SetRightMargin(0.03);
  DiMuPtPlotPad->SetRightMargin(0.03);
  Mu1EtaPlotPad->SetRightMargin(0.03);
  Mu2EtaPlotPad->SetRightMargin(0.03);
  DiTauEtaPlotPad->SetRightMargin(0.03);
  DiTauPhiPlotPad->SetRightMargin(0.03);
  DiMuEtaPlotPad->SetRightMargin(0.03);
  DiMudRPlotPad->SetRightMargin(0.03);
  DiMuPhiPlotPad->SetRightMargin(0.03);
  EtMETPlotPad->SetRightMargin(0.03);
  DiTauDiMuMassPlotPad->SetRightMargin(0.03);
  DiMuDiTauDeltaPhiPlotPad->SetRightMargin(0.03);
  METDiTauDeltaPhiPlotPad->SetRightMargin(0.03);
  METDiMuDeltaPhiPlotPad->SetRightMargin(0.03);
  DiTaudRPlotPad->SetRightMargin(0.03);
  DiTauMassSmallerdRPlotPad->SetRightMargin(0.03);
  HighestCSVInclJetPlotPad->SetRightMargin(0.03);
  
  NMedIsoTausWithMu3PlotPad->Draw();
  InvMassTauHadMu3PlotPad->Draw();
  PtTauHadMu3PlotPad->Draw();
  InvMassUpsilonRangePlotPad->Draw();
  InvMassZPeakRangePlotPad->Draw();
  InvMassFullRangePlotPad->Draw();
  InvMassDiMuBarrBarrPlotPad->Draw();
  InvMassDiMuBarrEndcPlotPad->Draw();
  InvMassDiMuEndcEndcPlotPad->Draw();
  Mu1PtPlotPad->Draw();
  Mu2PtPlotPad->Draw();
  DiMuPtPlotPad->Draw();
  Mu1EtaPlotPad->Draw();
  Mu2EtaPlotPad->Draw();
  DiTauEtaPlotPad->Draw();
  DiTauPhiPlotPad->Draw();
  DiMuEtaPlotPad->Draw();
  DiMudRPlotPad->Draw();
  DiMuPhiPlotPad->Draw();
  EtMETPlotPad->Draw();
  DiTauDiMuMassPlotPad->Draw();
  DiMuDiTauDeltaPhiPlotPad->Draw();
  METDiTauDeltaPhiPlotPad->Draw();
  METDiMuDeltaPhiPlotPad->Draw();
  DiTaudRPlotPad->Draw();
  DiTauMassSmallerdRPlotPad->Draw();
  HighestCSVInclJetPlotPad->Draw();
  
  NMedIsoTausWithMu3PlotPad->SetLogy(true);
  InvMassTauHadMu3PlotPad->SetLogy(true);
  PtTauHadMu3PlotPad->SetLogy(true);
  InvMassUpsilonRangePlotPad->SetLogy(true);
  InvMassZPeakRangePlotPad->SetLogy(true);
  InvMassFullRangePlotPad->SetLogy(true);
  InvMassDiMuBarrBarrPlotPad->SetLogy(true);
  InvMassDiMuBarrEndcPlotPad->SetLogy(true);
  InvMassDiMuEndcEndcPlotPad->SetLogy(true);
  Mu1PtPlotPad->SetLogy(true);
  Mu2PtPlotPad->SetLogy(true);
  DiMuPtPlotPad->SetLogy(true);
  Mu1EtaPlotPad->SetLogy(true);
  Mu2EtaPlotPad->SetLogy(true);
  DiTauEtaPlotPad->SetLogy(true);
  DiTauPhiPlotPad->SetLogy(true);
  DiMuEtaPlotPad->SetLogy(true);
  DiMudRPlotPad->SetLogy(true);
  DiMuPhiPlotPad->SetLogy(true);
  EtMETPlotPad->SetLogy(true);
  DiTauDiMuMassPlotPad->SetLogy(true);
  DiMuDiTauDeltaPhiPlotPad->SetLogy(true);
  METDiTauDeltaPhiPlotPad->SetLogy(true);
  METDiMuDeltaPhiPlotPad->SetLogy(true);
  DiTaudRPlotPad->SetLogy(true);
  DiTauMassSmallerdRPlotPad->SetLogy(true);
  HighestCSVInclJetPlotPad->SetLogy(true);
  
  NMedIsoTausWithMu3PlotPad->SetLogx(true);
  InvMassTauHadMu3PlotPad->SetLogx(true);
  PtTauHadMu3PlotPad->SetLogx(true);
  InvMassUpsilonRangePlotPad->SetLogx(true);
  InvMassZPeakRangePlotPad->SetLogx(true);
  InvMassFullRangePlotPad->SetLogx(true);
  InvMassDiMuBarrBarrPlotPad->SetLogx(true);
  InvMassDiMuBarrEndcPlotPad->SetLogx(true);
  InvMassDiMuEndcEndcPlotPad->SetLogx(true);
  Mu1PtPlotPad->SetLogx(true);
  Mu2PtPlotPad->SetLogx(true);
  DiMuPtPlotPad->SetLogx(true);
  Mu1EtaPlotPad->SetLogx(true);
  Mu2EtaPlotPad->SetLogx(true);
  DiTauEtaPlotPad->SetLogx(true);
  DiTauPhiPlotPad->SetLogx(true);
  DiMuEtaPlotPad->SetLogx(true);
  DiMudRPlotPad->SetLogx(true);
  DiMuPhiPlotPad->SetLogx(true);
  EtMETPlotPad->SetLogx(true);
  DiTauDiMuMassPlotPad->SetLogx(true);
  DiMuDiTauDeltaPhiPlotPad->SetLogx(true);
  METDiTauDeltaPhiPlotPad->SetLogx(true);
  METDiMuDeltaPhiPlotPad->SetLogx(true);
  DiTaudRPlotPad->SetLogx(true);
  DiTauMassSmallerdRPlotPad->SetLogx(true);
  HighestCSVInclJetPlotPad->SetLogx(true);
 
  TPad *NMedIsoTausWithMu3RatioPad = new TPad ("NMedIsoTausWithMu3RatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassTauHadMu3RatioPad = new TPad ("InvMassTauHadMu3RatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *PtTauHadMu3RatioPad = new TPad ("PtTauHadMu3RatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassUpsilonRangeRatioPad = new TPad ("InvMassUpsilonRangeRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassZPeakRangeRatioPad = new TPad ("InvMassUpsilonRangeRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassFullRangeRatioPad = new TPad ("InvMassFullRangeRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuBarrBarrRatioPad = new TPad ("InvMassDiMuBarrBarrRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuBarrEndcRatioPad = new TPad ("InvMassDiMuBarrEndcRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuEndcEndcRatioPad = new TPad ("InvMassDiMuEndcEndcRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *Mu1PtRatioPad = new TPad ("Mu1PtRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *Mu2PtRatioPad = new TPad ("Mu2PtRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuPtRatioPad = new TPad ("DiMuPtRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *Mu1EtaRatioPad = new TPad ("Mu1EtaRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *Mu2EtaRatioPad = new TPad ("Mu2EtaRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauEtaRatioPad = new TPad ("DiTauEtaRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauPhiRatioPad = new TPad ("DiTauPhiRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuEtaRatioPad = new TPad ("DiMuEtaRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMudRRatioPad = new TPad ("DiMudRRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuPhiRatioPad = new TPad ("DiMuPhiRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *EtMETRatioPad = new TPad ("EtMETRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauDiMuMassRatioPad = new TPad ("DiTauDiMuMassRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuDiTauDeltaPhiRatioPad = new TPad ("DiMuDiTauDeltaPhiRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *METDiTauDeltaPhiRatioPad = new TPad ("METDiTauDeltaPhiRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *METDiMuDeltaPhiRatioPad = new TPad ("METDiMuDeltaPhiRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTaudRRatioPad = new TPad ("DiTaudRRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauMassSmallerdRRatioPad = new TPad ("DiTauMassSmallerdRRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);
  TPad *HighestCSVInclJetRatioPad = new TPad ("HighestCSVInclJetRatioPad", "bottom pad", 0.0, 0.21, 1.0, 1.0);

  NMedIsoTausWithMu3RatioPad->SetTopMargin(0.06);
  InvMassTauHadMu3RatioPad->SetTopMargin(0.06);
  PtTauHadMu3RatioPad->SetTopMargin(0.06);
  InvMassUpsilonRangeRatioPad->SetTopMargin(0.06);
  InvMassZPeakRangeRatioPad->SetTopMargin(0.06);
  InvMassFullRangeRatioPad->SetTopMargin(0.06);
  InvMassDiMuBarrBarrRatioPad->SetTopMargin(0.06);
  InvMassDiMuBarrEndcRatioPad->SetTopMargin(0.06);
  InvMassDiMuEndcEndcRatioPad->SetTopMargin(0.06);
  Mu1PtRatioPad->SetTopMargin(0.06);
  Mu2PtRatioPad->SetTopMargin(0.06);
  DiMuPtRatioPad->SetTopMargin(0.06);
  Mu1EtaRatioPad->SetTopMargin(0.06);
  Mu2EtaRatioPad->SetTopMargin(0.06);
  DiTauEtaRatioPad->SetTopMargin(0.06);
  DiTauPhiRatioPad->SetTopMargin(0.06);
  DiMuEtaRatioPad->SetTopMargin(0.06);
  DiMudRRatioPad->SetTopMargin(0.06);
  DiMuPhiRatioPad->SetTopMargin(0.06);
  EtMETRatioPad->SetTopMargin(0.06);
  DiTauDiMuMassRatioPad->SetTopMargin(0.06);
  DiMuDiTauDeltaPhiRatioPad->SetTopMargin(0.06);
  METDiTauDeltaPhiRatioPad->SetTopMargin(0.06);
  METDiMuDeltaPhiRatioPad->SetTopMargin(0.06);
  DiTaudRRatioPad->SetTopMargin(0.06);
  DiTauMassSmallerdRRatioPad->SetTopMargin(0.06);
  HighestCSVInclJetRatioPad->SetTopMargin(0.06);
   
  NMedIsoTausWithMu3RatioPad->SetRightMargin(0.03);
  InvMassTauHadMu3RatioPad->SetRightMargin(0.03);
  PtTauHadMu3RatioPad->SetRightMargin(0.03);
  InvMassUpsilonRangeRatioPad->SetRightMargin(0.03);
  InvMassZPeakRangeRatioPad->SetRightMargin(0.03);
  InvMassFullRangeRatioPad->SetRightMargin(0.03);
  InvMassDiMuBarrBarrRatioPad->SetRightMargin(0.03);
  InvMassDiMuBarrEndcRatioPad->SetRightMargin(0.03);
  InvMassDiMuEndcEndcRatioPad->SetRightMargin(0.03);
  Mu1PtRatioPad->SetRightMargin(0.03);
  Mu2PtRatioPad->SetRightMargin(0.03);
  DiMuPtRatioPad->SetRightMargin(0.03);
  Mu1EtaRatioPad->SetRightMargin(0.03);
  Mu2EtaRatioPad->SetRightMargin(0.03);
  DiTauEtaRatioPad->SetRightMargin(0.03);
  DiTauPhiRatioPad->SetRightMargin(0.03);
  DiMuEtaRatioPad->SetRightMargin(0.03);
  DiMudRRatioPad->SetRightMargin(0.03);
  DiMuPhiRatioPad->SetRightMargin(0.03);
  EtMETRatioPad->SetRightMargin(0.03);
  DiTauDiMuMassRatioPad->SetRightMargin(0.03);
  DiMuDiTauDeltaPhiRatioPad->SetRightMargin(0.03);
  METDiTauDeltaPhiRatioPad->SetRightMargin(0.03);
  METDiMuDeltaPhiRatioPad->SetRightMargin(0.03);
  DiTaudRRatioPad->SetRightMargin(0.03);
  DiTauMassSmallerdRRatioPad->SetRightMargin(0.03);
  HighestCSVInclJetRatioPad->SetRightMargin(0.03);
  
  NMedIsoTausWithMu3RatioPad->SetBottomMargin(0.5);
  InvMassTauHadMu3RatioPad->SetBottomMargin(0.5);
  PtTauHadMu3RatioPad->SetBottomMargin(0.5);
  InvMassUpsilonRangeRatioPad->SetBottomMargin(0.5);
  InvMassZPeakRangeRatioPad->SetBottomMargin(0.5);
  InvMassFullRangeRatioPad->SetBottomMargin(0.5);
  InvMassDiMuBarrBarrRatioPad->SetBottomMargin(0.5);
  InvMassDiMuBarrEndcRatioPad->SetBottomMargin(0.5);
  InvMassDiMuEndcEndcRatioPad->SetBottomMargin(0.5);
  Mu1PtRatioPad->SetBottomMargin(0.5);
  Mu2PtRatioPad->SetBottomMargin(0.5);
  DiMuPtRatioPad->SetBottomMargin(0.5);
  Mu1EtaRatioPad->SetBottomMargin(0.5);
  Mu2EtaRatioPad->SetBottomMargin(0.5);
  DiTauEtaRatioPad->SetBottomMargin(0.5);
  DiTauPhiRatioPad->SetBottomMargin(0.5);
  DiMuEtaRatioPad->SetBottomMargin(0.5);
  DiMudRRatioPad->SetBottomMargin(0.5);
  DiMuPhiRatioPad->SetBottomMargin(0.5);
  EtMETRatioPad->SetBottomMargin(0.5);
  DiTauDiMuMassRatioPad->SetBottomMargin(0.5);
  DiMuDiTauDeltaPhiRatioPad->SetBottomMargin(0.5);
  METDiTauDeltaPhiRatioPad->SetBottomMargin(0.5);
  METDiMuDeltaPhiRatioPad->SetBottomMargin(0.5);
  DiTaudRRatioPad->SetBottomMargin(0.5);
  DiTauMassSmallerdRRatioPad->SetBottomMargin(0.5);
  HighestCSVInclJetRatioPad->SetBottomMargin(0.5);
  
  NMedIsoTausWithMu3RatioPad->SetLeftMargin(0.16);
  InvMassTauHadMu3RatioPad->SetLeftMargin(0.16);
  PtTauHadMu3RatioPad->SetLeftMargin(0.16);
  InvMassUpsilonRangeRatioPad->SetLeftMargin(0.16);
  InvMassZPeakRangeRatioPad->SetLeftMargin(0.16);
  InvMassFullRangeRatioPad->SetLeftMargin(0.16);
  InvMassDiMuBarrBarrRatioPad->SetLeftMargin(0.16);
  InvMassDiMuBarrEndcRatioPad->SetLeftMargin(0.16);
  InvMassDiMuEndcEndcRatioPad->SetLeftMargin(0.16);
  Mu1PtRatioPad->SetLeftMargin(0.16);
  Mu2PtRatioPad->SetLeftMargin(0.16);
  DiMuPtRatioPad->SetLeftMargin(0.16);
  Mu1EtaRatioPad->SetLeftMargin(0.16);
  Mu2EtaRatioPad->SetLeftMargin(0.16);
  DiTauEtaRatioPad->SetLeftMargin(0.16);
  DiTauPhiRatioPad->SetLeftMargin(0.16);
  DiMuEtaRatioPad->SetLeftMargin(0.16);
  DiMudRRatioPad->SetLeftMargin(0.16);
  DiMuPhiRatioPad->SetLeftMargin(0.16);
  EtMETRatioPad->SetLeftMargin(0.16);
  DiTauDiMuMassRatioPad->SetLeftMargin(0.16);
  DiMuDiTauDeltaPhiRatioPad->SetLeftMargin(0.16);
  METDiTauDeltaPhiRatioPad->SetLeftMargin(0.16);
  METDiMuDeltaPhiRatioPad->SetLeftMargin(0.16);
  DiTaudRRatioPad->SetLeftMargin(0.16);
  DiTauMassSmallerdRRatioPad->SetLeftMargin(0.16);
  HighestCSVInclJetRatioPad->SetLeftMargin(0.16);
  
  NMedIsoTausWithMu3RatioPad->SetTickx(1);
  InvMassTauHadMu3RatioPad->SetTickx(1);
  PtTauHadMu3RatioPad->SetTickx(1);
  InvMassUpsilonRangeRatioPad->SetTickx(1);
  InvMassZPeakRangeRatioPad->SetTickx(1);
  InvMassFullRangeRatioPad->SetTickx(1);
  InvMassDiMuBarrBarrRatioPad->SetTickx(1);
  InvMassDiMuBarrEndcRatioPad->SetTickx(1);
  InvMassDiMuEndcEndcRatioPad->SetTickx(1);
  Mu1PtRatioPad->SetTickx(1);
  Mu2PtRatioPad->SetTickx(1);
  DiMuPtRatioPad->SetTickx(1);
  Mu1EtaRatioPad->SetTickx(1);
  Mu2EtaRatioPad->SetTickx(1);
  DiTauEtaRatioPad->SetTickx(1);
  DiTauPhiRatioPad->SetTickx(1);
  DiMuEtaRatioPad->SetTickx(1);
  DiMudRRatioPad->SetTickx(1);
  DiMuPhiRatioPad->SetTickx(1);
  EtMETRatioPad->SetTickx(1);
  DiTauDiMuMassRatioPad->SetTickx(1);
  DiMuDiTauDeltaPhiRatioPad->SetTickx(1);
  METDiTauDeltaPhiRatioPad->SetTickx(1);
  METDiMuDeltaPhiRatioPad->SetTickx(1);
  DiTaudRRatioPad->SetTickx(1);
  DiTauMassSmallerdRRatioPad->SetTickx(1);
  HighestCSVInclJetRatioPad->SetTickx(1);
  
  NMedIsoTausWithMu3RatioPad->SetTicky(1);
  InvMassTauHadMu3RatioPad->SetTicky(1);
  PtTauHadMu3RatioPad->SetTicky(1);
  InvMassUpsilonRangeRatioPad->SetTicky(1);
  InvMassZPeakRangeRatioPad->SetTicky(1);
  InvMassFullRangeRatioPad->SetTicky(1);
  InvMassDiMuBarrBarrRatioPad->SetTicky(1);
  InvMassDiMuBarrEndcRatioPad->SetTicky(1);
  InvMassDiMuEndcEndcRatioPad->SetTicky(1);
  Mu1PtRatioPad->SetTicky(1);
  Mu2PtRatioPad->SetTicky(1);
  DiMuPtRatioPad->SetTicky(1);
  Mu1EtaRatioPad->SetTicky(1);
  Mu2EtaRatioPad->SetTicky(1);
  DiTauEtaRatioPad->SetTicky(1);
  DiTauPhiRatioPad->SetTicky(1);
  DiMuEtaRatioPad->SetTicky(1);
  DiMudRRatioPad->SetTicky(1);
  DiMuPhiRatioPad->SetTicky(1);
  EtMETRatioPad->SetTicky(1);
  DiTauDiMuMassRatioPad->SetTicky(1);
  DiMuDiTauDeltaPhiRatioPad->SetTicky(1);
  METDiTauDeltaPhiRatioPad->SetTicky(1);
  METDiMuDeltaPhiRatioPad->SetTicky(1);
  DiTaudRRatioPad->SetTicky(1);
  DiTauMassSmallerdRRatioPad->SetTicky(1);
  HighestCSVInclJetRatioPad->SetTicky(1);
  
  NMedIsoTausWithMu3RatioPad->Draw();
  InvMassTauHadMu3RatioPad->Draw();
  PtTauHadMu3RatioPad->Draw();
  InvMassUpsilonRangeRatioPad->Draw();
  InvMassZPeakRangeRatioPad->Draw();
  InvMassFullRangeRatioPad->Draw();
  InvMassDiMuBarrBarrRatioPad->Draw();
  InvMassDiMuBarrEndcRatioPad->Draw();
  InvMassDiMuEndcEndcRatioPad->Draw();
  Mu1PtRatioPad->Draw();
  Mu2PtRatioPad->Draw();
  DiMuPtRatioPad->Draw();
  Mu1EtaRatioPad->Draw();
  Mu2EtaRatioPad->Draw();
  DiTauEtaRatioPad->Draw();
  DiTauPhiRatioPad->Draw();
  DiMuEtaRatioPad->Draw();
  DiMudRRatioPad->Draw();
  DiMuPhiRatioPad->Draw();
  EtMETRatioPad->Draw();
  DiTauDiMuMassRatioPad->Draw();
  DiMuDiTauDeltaPhiRatioPad->Draw();
  METDiTauDeltaPhiRatioPad->Draw();
  METDiMuDeltaPhiRatioPad->Draw();
  DiTaudRRatioPad->Draw();
  DiTauMassSmallerdRRatioPad->Draw();
  HighestCSVInclJetRatioPad->Draw();
  
  NMedIsoTausWithMu3RatioPad->SetLogx(true);
  InvMassTauHadMu3RatioPad->SetLogx(true);
  PtTauHadMu3RatioPad->SetLogx(true);
  InvMassUpsilonRangeRatioPad->SetLogx(true);
  InvMassZPeakRangeRatioPad->SetLogx(true);
  InvMassFullRangeRatioPad->SetLogx(true);
  InvMassDiMuBarrBarrRatioPad->SetLogx(true);
  InvMassDiMuBarrEndcRatioPad->SetLogx(true);
  InvMassDiMuEndcEndcRatioPad->SetLogx(true);
  Mu1PtRatioPad->SetLogx(true);
  Mu2PtRatioPad->SetLogx(true);
  DiMuPtRatioPad->SetLogx(true);
  Mu1EtaRatioPad->SetLogx(true);
  Mu2EtaRatioPad->SetLogx(true);
  DiTauEtaRatioPad->SetLogx(true);
  DiTauPhiRatioPad->SetLogx(true);
  DiMuEtaRatioPad->SetLogx(true);
  DiMudRRatioPad->SetLogx(true);
  DiMuPhiRatioPad->SetLogx(true);
  EtMETRatioPad->SetLogx(true);
  DiTauDiMuMassRatioPad->SetLogx(true);
  DiMuDiTauDeltaPhiRatioPad->SetLogx(true);
  METDiTauDeltaPhiRatioPad->SetLogx(true);
  METDiMuDeltaPhiRatioPad->SetLogx(true);
  DiTaudRRatioPad->SetLogx(true);
  DiTauMassSmallerdRRatioPad->SetLogx(true);
  HighestCSVInclJetRatioPad->SetLogx(true);
  
cout << "Created the Output Pads" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Legends
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  legend = new TLegend(0.7,0.5,0.95,0.7) ;
  legend->SetTextFont(42);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->AddEntry(EtMETQCD_ ,"QCD", "f");
  legend->AddEntry(EtMETDiBoson_ ,"DiBoson", "f");
  legend->AddEntry(EtMETDY_ ,"DY", "f");
  legend->AddEntry(EtMETTT_ ,"TT", "f");
  legend->AddEntry(EtMETh125a5_ ,"h125a5", "f");
  legend->AddEntry(EtMETh125a7_ ,"h125a7", "f");
  legend->AddEntry(EtMETh125a9_ ,"h125a9", "f");
  legend->AddEntry(EtMETh125a11_ ,"h125a11", "f");
  legend->AddEntry(EtMETh125a13_ ,"h125a13", "f");
  legend->AddEntry(EtMETh125a15_ ,"h125a15", "f");
  legend->AddEntry(EtMETh125a17_ ,"h125a17", "f");
  legend->AddEntry(EtMETh125a19_ ,"h125a19", "f");
  legend->AddEntry(EtMETh125a21_ ,"h125a21", "f");

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Drawing the stacks
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  NMedIsoTausWithMu3PlotPad->cd();
  NMedIsoTausWithMu3Stack->Draw("hist");
  legend->Draw();
  InvMassTauHadMu3PlotPad->cd();
  InvMassTauHadMu3Stack->Draw("hist");
  legend->Draw();
  PtTauHadMu3PlotPad->cd();
  PtTauHadMu3Stack->Draw("hist");
  legend->Draw();
  InvMassUpsilonRangePlotPad->cd();
  InvMassUpsilonRangeStack->Draw("hist");
  legend->Draw();
  InvMassZPeakRangePlotPad->cd();
  InvMassZPeakRangeStack->Draw("hist");
  legend->Draw();
  InvMassFullRangePlotPad->cd();
  InvMassFullRangeStack->Draw("hist");
  legend->Draw();
  InvMassDiMuBarrBarrPlotPad->cd();
  InvMassDiMuBarrBarrStack->Draw("hist");
  legend->Draw();
  InvMassDiMuBarrEndcPlotPad->cd();
  InvMassDiMuBarrEndcStack->Draw("hist");
  legend->Draw();
  InvMassDiMuEndcEndcPlotPad->cd();
  InvMassDiMuEndcEndcStack->Draw("hist");
  legend->Draw();
  Mu1PtPlotPad->cd();
  Mu1PtStack->Draw("hist");
  legend->Draw();
  Mu2PtPlotPad->cd();
  Mu2PtStack->Draw("hist");
  legend->Draw();
  DiMuPtPlotPad->cd();
  DiMuPtStack->Draw("hist");
  legend->Draw();
  Mu1EtaPlotPad->cd();
  Mu1EtaStack->Draw("hist");
  legend->Draw();
  Mu2EtaPlotPad->cd();
  Mu2EtaStack->Draw("hist");
  legend->Draw();
  DiTauEtaPlotPad->cd();
  DiTauEtaStack->Draw("hist");
  legend->Draw();
  DiTauPhiPlotPad->cd();
  DiTauPhiStack->Draw("hist");
  legend->Draw();
  DiMuEtaPlotPad->cd();
  DiMuEtaStack->Draw("hist");
  legend->Draw();
  DiMudRPlotPad->cd();
  DiMudRStack->Draw("hist");
  legend->Draw();
  DiMuPhiPlotPad->cd();
  DiMuPhiStack->Draw("hist");
  legend->Draw();
  EtMETPlotPad->cd();
  EtMETStack->Draw("hist");
  legend->Draw();
  DiTauDiMuMassPlotPad->cd();
  DiTauDiMuMassStack->Draw("hist");
  legend->Draw();
  DiMuDiTauDeltaPhiPlotPad->cd();
  DiMuDiTauDeltaPhiStack->Draw("hist");
  legend->Draw();
  METDiTauDeltaPhiPlotPad->cd();
  METDiTauDeltaPhiStack->Draw("hist");
  legend->Draw();
  METDiMuDeltaPhiPlotPad->cd();
  METDiMuDeltaPhiStack->Draw("hist");
  legend->Draw();
  DiTaudRPlotPad->cd();
  DiTaudRStack->Draw("hist");
  legend->Draw();
  DiTauMassSmallerdRPlotPad->cd();
  DiTauMassSmallerdRStack->Draw("hist");
  legend->Draw();
  HighestCSVInclJetPlotPad->cd();
  HighestCSVInclJetStack->Draw("hist");
  legend->Draw();

cout << "Stacks Drawn" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Staterr
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  NMedIsoTausWithMu3Stack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  InvMassTauHadMu3Stack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  PtTauHadMu3Stack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  InvMassUpsilonRangeStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  InvMassZPeakRangeStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  InvMassFullRangeStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  InvMassDiMuBarrBarrStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  InvMassDiMuBarrEndcStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  InvMassDiMuEndcEndcStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  Mu1PtStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  Mu2PtStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  DiMuPtStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  Mu1EtaStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  Mu2EtaStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  DiTauEtaStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  DiTauPhiStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  DiMuEtaStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  DiMudRStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  DiMuPhiStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  EtMETStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  DiTauDiMuMassStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  DiMuDiTauDeltaPhiStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  METDiTauDeltaPhiStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  METDiMuDeltaPhiStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  DiTaudRStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  DiTauMassSmallerdRStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);
  HighestCSVInclJetStack->GetHistogram()->GetXaxis()->SetLabelOffset(999);

  NMedIsoTausWithMu3Stackerr = (TH1F*)NMedIsoTausWithMu3Stack->GetStack()->Last()->Clone("NMedIsoTausWithMu3Stackerr");
  InvMassTauHadMu3Stackerr = (TH1F*)InvMassTauHadMu3Stack->GetStack()->Last()->Clone("InvMassTauHadMu3Stackerr");
  PtTauHadMu3Stackerr = (TH1F*)PtTauHadMu3Stack->GetStack()->Last()->Clone("PtTauHadMu3Stackerr");
  InvMassUpsilonRangeStackerr = (TH1F*)InvMassUpsilonRangeStack->GetStack()->Last()->Clone("InvMassUpsilonRangeStackerr");
  InvMassZPeakRangeStackerr = (TH1F*)InvMassZPeakRangeStack->GetStack()->Last()->Clone("InvMassZPeakRangeStackerr");
  InvMassFullRangeStackerr = (TH1F*)InvMassFullRangeStack->GetStack()->Last()->Clone("InvMassFullRangeStackerr");
  InvMassDiMuBarrBarrStackerr = (TH1F*)InvMassDiMuBarrBarrStack->GetStack()->Last()->Clone("InvMassDiMuBarrBarrStackerr");
  InvMassDiMuBarrEndcStackerr = (TH1F*)InvMassDiMuBarrEndcStack->GetStack()->Last()->Clone("InvMassDiMuBarrEndcStackerr");
  InvMassDiMuEndcEndcStackerr = (TH1F*)InvMassDiMuEndcEndcStack->GetStack()->Last()->Clone("InvMassDiMuEndcEndcStackerr");
  Mu1PtStackerr = (TH1F*)Mu1PtStack->GetStack()->Last()->Clone("Mu1PtStackerr");
  Mu2PtStackerr = (TH1F*)Mu2PtStack->GetStack()->Last()->Clone("Mu2PtStackerr");
  DiMuPtStackerr = (TH1F*)DiMuPtStack->GetStack()->Last()->Clone("DiMuPtStackerr");
  Mu1EtaStackerr = (TH1F*)Mu1EtaStack->GetStack()->Last()->Clone("Mu1EtaStackerr");
  Mu2EtaStackerr = (TH1F*)Mu2EtaStack->GetStack()->Last()->Clone("Mu2EtaStackerr");
  DiTauEtaStackerr = (TH1F*)DiTauEtaStack->GetStack()->Last()->Clone("DiTauEtaStackerr");
  DiTauPhiStackerr = (TH1F*)DiTauPhiStack->GetStack()->Last()->Clone("DiTauPhiStackerr");
  DiMuEtaStackerr = (TH1F*)DiMuEtaStack->GetStack()->Last()->Clone("DiMuEtaStackerr");
  DiMudRStackerr = (TH1F*)DiMudRStack->GetStack()->Last()->Clone("DiMudRStackerr");
  DiMuPhiStackerr = (TH1F*)DiMuPhiStack->GetStack()->Last()->Clone("DiMuPhiStackerr");
  EtMETStackerr = (TH1F*)EtMETStack->GetStack()->Last()->Clone("EtMETStackerr");
  DiTauDiMuMassStackerr = (TH1F*)DiTauDiMuMassStack->GetStack()->Last()->Clone("DiTauDiMuMassStackerr");
  DiMuDiTauDeltaPhiStackerr = (TH1F*)DiMuDiTauDeltaPhiStack->GetStack()->Last()->Clone("DiMuDiTauDeltaPhiStackerr");
  METDiTauDeltaPhiStackerr = (TH1F*)METDiTauDeltaPhiStack->GetStack()->Last()->Clone("METDiTauDeltaPhiStackerr");
  METDiMuDeltaPhiStackerr = (TH1F*)METDiMuDeltaPhiStack->GetStack()->Last()->Clone("METDiMuDeltaPhiStackerr");
  DiTaudRStackerr = (TH1F*)DiTaudRStack->GetStack()->Last()->Clone("DiTaudRStackerr");
  DiTauMassSmallerdRStackerr = (TH1F*)DiTauMassSmallerdRStack->GetStack()->Last()->Clone("DiTauMassSmallerdRStackerr");
  HighestCSVInclJetStackerr = (TH1F*)HighestCSVInclJetStack->GetStack()->Last()->Clone("HighestCSVInclJetStackerr");

  NMedIsoTausWithMu3Stackerr->SetFillColor(kGray+3);
  InvMassTauHadMu3Stackerr->SetFillColor(kGray+3);
  PtTauHadMu3Stackerr->SetFillColor(kGray+3);
  InvMassUpsilonRangeStackerr->SetFillColor(kGray+3);
  InvMassZPeakRangeStackerr->SetFillColor(kGray+3);
  InvMassFullRangeStackerr->SetFillColor(kGray+3);
  InvMassDiMuBarrBarrStackerr->SetFillColor(kGray+3);
  InvMassDiMuBarrEndcStackerr->SetFillColor(kGray+3);
  InvMassDiMuEndcEndcStackerr->SetFillColor(kGray+3);
  Mu1PtStackerr->SetFillColor(kGray+3);
  Mu2PtStackerr->SetFillColor(kGray+3);
  DiMuPtStackerr->SetFillColor(kGray+3);
  Mu1EtaStackerr->SetFillColor(kGray+3);
  Mu2EtaStackerr->SetFillColor(kGray+3);
  DiTauEtaStackerr->SetFillColor(kGray+3);
  DiTauPhiStackerr->SetFillColor(kGray+3);
  DiMuEtaStackerr->SetFillColor(kGray+3);
  DiMudRStackerr->SetFillColor(kGray+3);
  DiMuPhiStackerr->SetFillColor(kGray+3);
  EtMETStackerr->SetFillColor(kGray+3);
  DiTauDiMuMassStackerr->SetFillColor(kGray+3);
  DiMuDiTauDeltaPhiStackerr->SetFillColor(kGray+3);
  METDiTauDeltaPhiStackerr->SetFillColor(kGray+3);
  METDiMuDeltaPhiStackerr->SetFillColor(kGray+3);
  DiTaudRStackerr->SetFillColor(kGray+3);
  DiTauMassSmallerdRStackerr->SetFillColor(kGray+3);
  HighestCSVInclJetStackerr->SetFillColor(kGray+3);

  NMedIsoTausWithMu3Stackerr->SetLineColor(kGray+3);
  InvMassTauHadMu3Stackerr->SetLineColor(kGray+3);
  PtTauHadMu3Stackerr->SetLineColor(kGray+3);
  InvMassUpsilonRangeStackerr->SetLineColor(kGray+3);
  InvMassZPeakRangeStackerr->SetLineColor(kGray+3);
  InvMassFullRangeStackerr->SetLineColor(kGray+3);
  InvMassDiMuBarrBarrStackerr->SetLineColor(kGray+3);
  InvMassDiMuBarrEndcStackerr->SetLineColor(kGray+3);
  InvMassDiMuEndcEndcStackerr->SetLineColor(kGray+3);
  Mu1PtStackerr->SetLineColor(kGray+3);
  Mu2PtStackerr->SetLineColor(kGray+3);
  DiMuPtStackerr->SetLineColor(kGray+3);
  Mu1EtaStackerr->SetLineColor(kGray+3);
  Mu2EtaStackerr->SetLineColor(kGray+3);
  DiTauEtaStackerr->SetLineColor(kGray+3);
  DiTauPhiStackerr->SetLineColor(kGray+3);
  DiMuEtaStackerr->SetLineColor(kGray+3);
  DiMudRStackerr->SetLineColor(kGray+3);
  DiMuPhiStackerr->SetLineColor(kGray+3);
  EtMETStackerr->SetLineColor(kGray+3);
  DiTauDiMuMassStackerr->SetLineColor(kGray+3);
  DiMuDiTauDeltaPhiStackerr->SetLineColor(kGray+3);
  METDiTauDeltaPhiStackerr->SetLineColor(kGray+3);
  METDiMuDeltaPhiStackerr->SetLineColor(kGray+3);
  DiTaudRStackerr->SetLineColor(kGray+3);
  DiTauMassSmallerdRStackerr->SetLineColor(kGray+3);
  HighestCSVInclJetStackerr->SetLineColor(kGray+3);

  NMedIsoTausWithMu3Stackerr->SetLineWidth(0);
  InvMassTauHadMu3Stackerr->SetLineWidth(0);
  PtTauHadMu3Stackerr->SetLineWidth(0);
  InvMassUpsilonRangeStackerr->SetLineWidth(0);
  InvMassZPeakRangeStackerr->SetLineWidth(0);
  InvMassFullRangeStackerr->SetLineWidth(0);
  InvMassDiMuBarrBarrStackerr->SetLineWidth(0);
  InvMassDiMuBarrEndcStackerr->SetLineWidth(0);
  InvMassDiMuEndcEndcStackerr->SetLineWidth(0);
  Mu1PtStackerr->SetLineWidth(0);
  Mu2PtStackerr->SetLineWidth(0);
  DiMuPtStackerr->SetLineWidth(0);
  Mu1EtaStackerr->SetLineWidth(0);
  Mu2EtaStackerr->SetLineWidth(0);
  DiTauEtaStackerr->SetLineWidth(0);
  DiTauPhiStackerr->SetLineWidth(0);
  DiMuEtaStackerr->SetLineWidth(0);
  DiMudRStackerr->SetLineWidth(0);
  DiMuPhiStackerr->SetLineWidth(0);
  EtMETStackerr->SetLineWidth(0);
  DiTauDiMuMassStackerr->SetLineWidth(0);
  DiMuDiTauDeltaPhiStackerr->SetLineWidth(0);
  METDiTauDeltaPhiStackerr->SetLineWidth(0);
  METDiMuDeltaPhiStackerr->SetLineWidth(0);
  DiTaudRStackerr->SetLineWidth(0);
  DiTauMassSmallerdRStackerr->SetLineWidth(0);
  HighestCSVInclJetStackerr->SetLineWidth(0);

  NMedIsoTausWithMu3Stackerr->SetMarkerSize(0);
  InvMassTauHadMu3Stackerr->SetMarkerSize(0);
  PtTauHadMu3Stackerr->SetMarkerSize(0);
  InvMassUpsilonRangeStackerr->SetMarkerSize(0);
  InvMassZPeakRangeStackerr->SetMarkerSize(0);
  InvMassFullRangeStackerr->SetMarkerSize(0);
  InvMassDiMuBarrBarrStackerr->SetMarkerSize(0);
  InvMassDiMuBarrEndcStackerr->SetMarkerSize(0);
  InvMassDiMuEndcEndcStackerr->SetMarkerSize(0);
  Mu1PtStackerr->SetMarkerSize(0);
  Mu2PtStackerr->SetMarkerSize(0);
  DiMuPtStackerr->SetMarkerSize(0);
  Mu1EtaStackerr->SetMarkerSize(0);
  Mu2EtaStackerr->SetMarkerSize(0);
  DiTauEtaStackerr->SetMarkerSize(0);
  DiTauPhiStackerr->SetMarkerSize(0);
  DiMuEtaStackerr->SetMarkerSize(0);
  DiMudRStackerr->SetMarkerSize(0);
  DiMuPhiStackerr->SetMarkerSize(0);
  EtMETStackerr->SetMarkerSize(0);
  DiTauDiMuMassStackerr->SetMarkerSize(0);
  DiMuDiTauDeltaPhiStackerr->SetMarkerSize(0);
  METDiTauDeltaPhiStackerr->SetMarkerSize(0);
  METDiMuDeltaPhiStackerr->SetMarkerSize(0);
  DiTaudRStackerr->SetMarkerSize(0);
  DiTauMassSmallerdRStackerr->SetMarkerSize(0);
  HighestCSVInclJetStackerr->SetMarkerSize(0);

  NMedIsoTausWithMu3Stackerr->SetFillStyle(3013);
  InvMassTauHadMu3Stackerr->SetFillStyle(3013);
  PtTauHadMu3Stackerr->SetFillStyle(3013);
  InvMassUpsilonRangeStackerr->SetFillStyle(3013);
  InvMassZPeakRangeStackerr->SetFillStyle(3013);
  InvMassFullRangeStackerr->SetFillStyle(3013);
  InvMassDiMuBarrBarrStackerr->SetFillStyle(3013);
  InvMassDiMuBarrEndcStackerr->SetFillStyle(3013);
  InvMassDiMuEndcEndcStackerr->SetFillStyle(3013);
  Mu1PtStackerr->SetFillStyle(3013);
  Mu2PtStackerr->SetFillStyle(3013);
  DiMuPtStackerr->SetFillStyle(3013);
  Mu1EtaStackerr->SetFillStyle(3013);
  Mu2EtaStackerr->SetFillStyle(3013);
  DiTauEtaStackerr->SetFillStyle(3013);
  DiTauPhiStackerr->SetFillStyle(3013);
  DiMuEtaStackerr->SetFillStyle(3013);
  DiMudRStackerr->SetFillStyle(3013);
  DiMuPhiStackerr->SetFillStyle(3013);
  EtMETStackerr->SetFillStyle(3013);
  DiTauDiMuMassStackerr->SetFillStyle(3013);
  DiMuDiTauDeltaPhiStackerr->SetFillStyle(3013);
  METDiTauDeltaPhiStackerr->SetFillStyle(3013);
  METDiMuDeltaPhiStackerr->SetFillStyle(3013);
  DiTaudRStackerr->SetFillStyle(3013);
  DiTauMassSmallerdRStackerr->SetFillStyle(3013);
  HighestCSVInclJetStackerr->SetFillStyle(3013);


cout << "Set Stat Error" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Drawing the stateerr and the data
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  NMedIsoTausWithMu3PlotPad->cd();
  NMedIsoTausWithMu3Stackerr->Draw("e2 same");
  NMedIsoTausWithMu3Data_->Draw("ex0 same");
  legend->Draw();
  InvMassTauHadMu3PlotPad->cd();
  InvMassTauHadMu3Stackerr->Draw("e2 same");
  InvMassTauHadMu3Data_->Draw("ex0 same");
  legend->Draw();
  PtTauHadMu3PlotPad->cd();
  PtTauHadMu3Stackerr->Draw("e2 same");
  PtTauHadMu3Data_->Draw("ex0 same");
  legend->Draw();
  InvMassUpsilonRangePlotPad->cd();
  InvMassUpsilonRangeStackerr->Draw("e2 same");
  InvMassUpsilonRangeData_->Draw("ex0 same");
  legend->Draw();
  InvMassZPeakRangePlotPad->cd();
  InvMassZPeakRangeStackerr->Draw("e2 same");
  InvMassZPeakRangeData_->Draw("ex0 same");
  legend->Draw();
  InvMassFullRangePlotPad->cd();
  InvMassFullRangeStackerr->Draw("e2 same");
  InvMassFullRangeData_->Draw("ex0 same");
  legend->Draw();
  InvMassDiMuBarrBarrPlotPad->cd();
  InvMassDiMuBarrBarrStackerr->Draw("e2 same");
  InvMassDiMuBarrBarrData_->Draw("ex0 same");
  legend->Draw();
  InvMassDiMuBarrEndcPlotPad->cd();
  InvMassDiMuBarrEndcStackerr->Draw("e2 same");
  InvMassDiMuBarrEndcData_->Draw("ex0 same");
  legend->Draw();
  InvMassDiMuEndcEndcPlotPad->cd();
  InvMassDiMuEndcEndcStackerr->Draw("e2 same");
  InvMassDiMuEndcEndcData_->Draw("ex0 same");
  legend->Draw();
  Mu1PtPlotPad->cd();
  Mu1PtStackerr->Draw("e2 same");
  Mu1PtData_->Draw("ex0 same");
  legend->Draw();
  Mu2PtPlotPad->cd();
  Mu2PtStackerr->Draw("e2 same");
  Mu2PtData_->Draw("ex0 same");
  DiMuPtPlotPad->cd();
  legend->Draw();
  DiMuPtStackerr->Draw("e2 same");
  DiMuPtData_->Draw("ex0 same");
  Mu1EtaPlotPad->cd();
  Mu1EtaStackerr->Draw("e2 same");
  Mu1EtaData_->Draw("ex0 same");
  legend->Draw();
  Mu2EtaPlotPad->cd();
  Mu2EtaStackerr->Draw("e2 same");
  Mu2EtaData_->Draw("ex0 same");
  DiTauEtaPlotPad->cd();
  legend->Draw();
  DiTauEtaStackerr->Draw("e2 same");
  DiTauEtaData_->Draw("ex0 same");
  DiTauPhiPlotPad->cd();
  DiTauPhiStackerr->Draw("e2 same");
  DiTauPhiData_->Draw("ex0 same");
  legend->Draw();
  DiMuEtaPlotPad->cd();
  DiMuEtaStackerr->Draw("e2 same");
  DiMuEtaData_->Draw("ex0 same");
  legend->Draw();
  DiMudRPlotPad->cd();
  DiMudRStackerr->Draw("e2 same");
  DiMudRData_->Draw("ex0 same");
  legend->Draw();
  DiMuPhiPlotPad->cd();
  DiMuPhiStackerr->Draw("e2 same");
  DiMuPhiData_->Draw("ex0 same");
  EtMETPlotPad->cd();
  legend->Draw();
  EtMETStackerr->Draw("e2 same");
  EtMETData_->Draw("ex0 same");
  DiTauDiMuMassPlotPad->cd();
  DiTauDiMuMassStackerr->Draw("e2 same");
  DiTauDiMuMassData_->Draw("ex0 same");
  legend->Draw();
  DiMuDiTauDeltaPhiPlotPad->cd();
  DiMuDiTauDeltaPhiStackerr->Draw("e2 same");
  DiMuDiTauDeltaPhiData_->Draw("ex0 same");
  legend->Draw();
  METDiTauDeltaPhiPlotPad->cd();
  METDiTauDeltaPhiStackerr->Draw("e2 same");
  METDiTauDeltaPhiData_->Draw("ex0 same");
  legend->Draw();
  METDiMuDeltaPhiPlotPad->cd();
  METDiMuDeltaPhiStackerr->Draw("e2 same");
  METDiMuDeltaPhiData_->Draw("ex0 same");
  legend->Draw();
  DiTaudRPlotPad->cd();
  DiTaudRStackerr->Draw("e2 same");
  DiTaudRData_->Draw("ex0 same");
  legend->Draw();
  DiTauMassSmallerdRPlotPad->cd();
  DiTauMassSmallerdRStackerr->Draw("e2 same");
  DiTauMassSmallerdRData_->Draw("ex0 same");
  legend->Draw();
  HighestCSVInclJetPlotPad->cd();
  HighestCSVInclJetStackerr->Draw("e2 same");
  HighestCSVInclJetData_->Draw("ex0 same");
  legend->Draw();

cout << "Got StatErr" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting the cms_lumi Styling
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  writeExtraText = true;
  lumi_13TeV = "35.9 fb^{-1}";
  CMS_lumi(NMedIsoTausWithMu3PlotPad, 4, 11);
  CMS_lumi(InvMassTauHadMu3PlotPad, 4, 11);
  CMS_lumi(PtTauHadMu3PlotPad, 4, 11);
  CMS_lumi(InvMassUpsilonRangePlotPad, 4, 11);
  CMS_lumi(InvMassZPeakRangePlotPad, 4, 11);
  CMS_lumi(InvMassFullRangePlotPad, 4, 11);
  CMS_lumi(InvMassDiMuBarrBarrPlotPad, 4, 11);
  CMS_lumi(InvMassDiMuBarrEndcPlotPad, 4, 11);
  CMS_lumi(InvMassDiMuEndcEndcPlotPad, 4, 11);
  CMS_lumi(Mu1PtPlotPad, 4, 11);
  CMS_lumi(Mu2PtPlotPad, 4, 11);
  CMS_lumi(DiMuPtPlotPad, 4, 11);
  CMS_lumi(Mu1EtaPlotPad, 4, 11);
  CMS_lumi(Mu2EtaPlotPad, 4, 11);
  CMS_lumi(DiTauEtaPlotPad, 4, 11);
  CMS_lumi(DiTauPhiPlotPad, 4, 11);
  CMS_lumi(DiMuEtaPlotPad, 4, 11);
  CMS_lumi(DiMudRPlotPad, 4, 11);
  CMS_lumi(DiMuPhiPlotPad, 4, 11);
  CMS_lumi(EtMETPlotPad, 4, 11);
  CMS_lumi(DiTauDiMuMassPlotPad, 4, 11);
  CMS_lumi(DiMuDiTauDeltaPhiPlotPad, 4, 11);
  CMS_lumi(METDiTauDeltaPhiPlotPad, 4, 11);
  CMS_lumi(METDiMuDeltaPhiPlotPad, 4, 11);
  CMS_lumi(DiTaudRPlotPad, 4, 11);
  CMS_lumi(DiTauMassSmallerdRPlotPad, 4, 11);
  CMS_lumi(HighestCSVInclJetPlotPad, 4, 11);

cout << "Cms_lumi run" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting ratio plots
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  NMedIsoTausWithMu3denom = (TH1F*)NMedIsoTausWithMu3Stack->GetStack()->Last()->Clone("NMedIsoTausWithMu3denom");
  InvMassTauHadMu3denom = (TH1F*)InvMassTauHadMu3Stack->GetStack()->Last()->Clone("InvMassTauHadMu3denom");
  PtTauHadMu3denom = (TH1F*)PtTauHadMu3Stack->GetStack()->Last()->Clone("PtTauHadMu3denom");
  InvMassUpsilonRangedenom = (TH1F*)InvMassUpsilonRangeStack->GetStack()->Last()->Clone("InvMassUpsilonRangedenom");
  InvMassZPeakRangedenom = (TH1F*)InvMassZPeakRangeStack->GetStack()->Last()->Clone("InvMassZPeakRangedenom");
  InvMassFullRangedenom = (TH1F*)InvMassFullRangeStack->GetStack()->Last()->Clone("InvMassFullRangedenom");
  InvMassDiMuBarrBarrdenom = (TH1F*)InvMassDiMuBarrBarrStack->GetStack()->Last()->Clone("InvMassDiMuBarrBarrdenom");
  InvMassDiMuBarrEndcdenom = (TH1F*)InvMassDiMuBarrEndcStack->GetStack()->Last()->Clone("InvMassDiMuBarrEndcdenom");
  InvMassDiMuEndcEndcdenom = (TH1F*)InvMassDiMuEndcEndcStack->GetStack()->Last()->Clone("InvMassDiMuEndcEndcdenom");
  Mu1Ptdenom = (TH1F*)Mu1PtStack->GetStack()->Last()->Clone("Mu1Ptdenom");
  Mu2Ptdenom = (TH1F*)Mu2PtStack->GetStack()->Last()->Clone("Mu2Ptdenom");
  DiMuPtdenom = (TH1F*)DiMuPtStack->GetStack()->Last()->Clone("DiMuPtdenom");
  Mu1Etadenom = (TH1F*)Mu1EtaStack->GetStack()->Last()->Clone("Mu1Etadenom");
  Mu2Etadenom = (TH1F*)Mu2EtaStack->GetStack()->Last()->Clone("Mu2Etadenom");
  DiTauEtadenom = (TH1F*)DiTauEtaStack->GetStack()->Last()->Clone("DiTauEtadenom");
  DiTauPhidenom = (TH1F*)DiTauPhiStack->GetStack()->Last()->Clone("DiTauPhidenom");
  DiMuEtadenom = (TH1F*)DiMuEtaStack->GetStack()->Last()->Clone("DiMuEtadenom");
  DiMudRdenom = (TH1F*)DiMudRStack->GetStack()->Last()->Clone("DiMudRdenom");
  DiMuPhidenom = (TH1F*)DiMuPhiStack->GetStack()->Last()->Clone("DiMuPhidenom");
  EtMETdenom = (TH1F*)EtMETStack->GetStack()->Last()->Clone("EtMETdenom");
  DiTauDiMuMassdenom = (TH1F*)DiTauDiMuMassStack->GetStack()->Last()->Clone("DiTauDiMuMassdenom");
  DiMuDiTauDeltaPhidenom = (TH1F*)DiMuDiTauDeltaPhiStack->GetStack()->Last()->Clone("DiMuDiTauDeltaPhidenom");
  METDiTauDeltaPhidenom = (TH1F*)METDiTauDeltaPhiStack->GetStack()->Last()->Clone("METDiTauDeltaPhidenom");
  METDiMuDeltaPhidenom = (TH1F*)METDiMuDeltaPhiStack->GetStack()->Last()->Clone("METDiMuDeltaPhidenom");
  DiTaudRdenom = (TH1F*)DiTaudRStack->GetStack()->Last()->Clone("DiTaudRdenom");
  DiTauMassSmallerdRdenom = (TH1F*)DiTauMassSmallerdRStack->GetStack()->Last()->Clone("DiTauMassSmallerdRdenom");
  HighestCSVInclJetdenom = (TH1F*)HighestCSVInclJetStack->GetStack()->Last()->Clone("HighestCSVInclJetdenom");

  NMedIsoTausWithMu3RatioStatError = (TH1F*)NMedIsoTausWithMu3denom->Clone("NMedIsoTausWithMu3RatioStatError");
  InvMassTauHadMu3RatioStatError = (TH1F*)InvMassTauHadMu3denom->Clone("InvMassTauHadMu3RatioStatError");
  PtTauHadMu3RatioStatError = (TH1F*)PtTauHadMu3denom->Clone("PtTauHadMu3RatioStatError");
  InvMassUpsilonRangeRatioStatError = (TH1F*)InvMassUpsilonRangedenom->Clone("InvMassUpsilonRangeRatioStatError");
  InvMassZPeakRangeRatioStatError = (TH1F*)InvMassZPeakRangedenom->Clone("InvMassZPeakRangeRatioStatError");
  InvMassFullRangeRatioStatError = (TH1F*)InvMassFullRangedenom->Clone("InvMassFullRangeRatioStatError");
  InvMassDiMuBarrBarrRatioStatError = (TH1F*)InvMassDiMuBarrBarrdenom->Clone("InvMassDiMuBarrBarrRatioStatError");
  InvMassDiMuBarrEndcRatioStatError = (TH1F*)InvMassDiMuBarrEndcdenom->Clone("InvMassDiMuBarrEndcRatioStatError");
  InvMassDiMuEndcEndcRatioStatError = (TH1F*)InvMassDiMuEndcEndcdenom->Clone("InvMassDiMuEndcEndcRatioStatError");
  Mu1PtRatioStatError = (TH1F*)Mu1Ptdenom->Clone("Mu1PtRatioStatError");
  Mu2PtRatioStatError = (TH1F*)Mu2Ptdenom->Clone("Mu2PtRatioStatError");
  DiMuPtRatioStatError = (TH1F*)DiMuPtdenom->Clone("DiMuPtRatioStatError");
  Mu1EtaRatioStatError = (TH1F*)Mu1Etadenom->Clone("Mu1EtaRatioStatError");
  Mu2EtaRatioStatError = (TH1F*)Mu2Etadenom->Clone("Mu2EtaRatioStatError");
  DiTauEtaRatioStatError = (TH1F*)DiTauEtadenom->Clone("DiTauEtaRatioStatError");
  DiTauPhiRatioStatError = (TH1F*)DiTauPhidenom->Clone("DiTauPhiRatioStatError");
  DiMuEtaRatioStatError = (TH1F*)DiMuEtadenom->Clone("DiMuEtaRatioStatError");
  DiMudRRatioStatError = (TH1F*)DiMudRdenom->Clone("DiMudRRatioStatError");
  DiMuPhiRatioStatError = (TH1F*)DiMuPhidenom->Clone("DiMuPhiRatioStatError");
  EtMETRatioStatError = (TH1F*)EtMETdenom->Clone("EtMETRatioStatError");
  DiTauDiMuMassRatioStatError = (TH1F*)DiTauDiMuMassdenom->Clone("DiTauDiMuMassRatioStatError");
  DiMuDiTauDeltaPhiRatioStatError = (TH1F*)DiMuDiTauDeltaPhidenom->Clone("DiMuDiTauDeltaPhiRatioStatError");
  METDiTauDeltaPhiRatioStatError = (TH1F*)METDiTauDeltaPhidenom->Clone("METDiTauDeltaPhiRatioStatError");
  METDiMuDeltaPhiRatioStatError = (TH1F*)METDiMuDeltaPhidenom->Clone("METDiMuDeltaPhiRatioStatError");
  DiTaudRRatioStatError = (TH1F*)DiTaudRdenom->Clone("DiTaudRRatioStatError");
  DiTauMassSmallerdRRatioStatError = (TH1F*)DiTauMassSmallerdRdenom->Clone("DiTauMassSmallerdRRatioStatError");
  HighestCSVInclJetRatioStatError = (TH1F*)HighestCSVInclJetdenom->Clone("HighestCSVInclJetRatioStatError");


  NMedIsoTausWithMu3RatioStatError->SetStats(0);
  InvMassTauHadMu3RatioStatError->SetStats(0);
  PtTauHadMu3RatioStatError->SetStats(0);
  InvMassUpsilonRangeRatioStatError->SetStats(0);
  InvMassZPeakRangeRatioStatError->SetStats(0);
  InvMassFullRangeRatioStatError->SetStats(0);
  InvMassDiMuBarrBarrRatioStatError->SetStats(0);
  InvMassDiMuBarrEndcRatioStatError->SetStats(0);
  InvMassDiMuEndcEndcRatioStatError->SetStats(0);
  Mu1PtRatioStatError->SetStats(0);
  Mu2PtRatioStatError->SetStats(0);
  DiMuPtRatioStatError->SetStats(0);
  Mu1EtaRatioStatError->SetStats(0);
  Mu2EtaRatioStatError->SetStats(0);
  DiTauEtaRatioStatError->SetStats(0);
  DiTauPhiRatioStatError->SetStats(0);
  DiMuEtaRatioStatError->SetStats(0);
  DiMudRRatioStatError->SetStats(0);
  DiMuPhiRatioStatError->SetStats(0);
  EtMETRatioStatError->SetStats(0);
  DiTauDiMuMassRatioStatError->SetStats(0);
  DiMuDiTauDeltaPhiRatioStatError->SetStats(0);
  METDiTauDeltaPhiRatioStatError->SetStats(0);
  METDiMuDeltaPhiRatioStatError->SetStats(0);
  DiTaudRRatioStatError->SetStats(0);
  DiTauMassSmallerdRRatioStatError->SetStats(0);
  HighestCSVInclJetRatioStatError->SetStats(0);

  NMedIsoTausWithMu3RatioStatError->SetTitle("");
  InvMassTauHadMu3RatioStatError->SetTitle("");
  PtTauHadMu3RatioStatError->SetTitle("");
  InvMassUpsilonRangeRatioStatError->SetTitle("");
  InvMassZPeakRangeRatioStatError->SetTitle("");
  InvMassFullRangeRatioStatError->SetTitle("");
  InvMassDiMuBarrBarrRatioStatError->SetTitle("");
  InvMassDiMuBarrEndcRatioStatError->SetTitle("");
  InvMassDiMuEndcEndcRatioStatError->SetTitle("");
  Mu1PtRatioStatError->SetTitle("");
  Mu2PtRatioStatError->SetTitle("");
  DiMuPtRatioStatError->SetTitle("");
  Mu1EtaRatioStatError->SetTitle("");
  Mu2EtaRatioStatError->SetTitle("");
  DiTauEtaRatioStatError->SetTitle("");
  DiTauPhiRatioStatError->SetTitle("");
  DiMuEtaRatioStatError->SetTitle("");
  DiMudRRatioStatError->SetTitle("");
  DiMuPhiRatioStatError->SetTitle("");
  EtMETRatioStatError->SetTitle("");
  DiTauDiMuMassRatioStatError->SetTitle("");
  DiMuDiTauDeltaPhiRatioStatError->SetTitle("");
  METDiTauDeltaPhiRatioStatError->SetTitle("");
  METDiMuDeltaPhiRatioStatError->SetTitle("");
  DiTaudRRatioStatError->SetTitle("");
  DiTauMassSmallerdRRatioStatError->SetTitle("");
  HighestCSVInclJetRatioStatError->SetTitle("");

  NMedIsoTausWithMu3RatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  InvMassTauHadMu3RatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  PtTauHadMu3RatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  InvMassUpsilonRangeRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  InvMassZPeakRangeRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  InvMassFullRangeRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  InvMassDiMuBarrBarrRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  InvMassDiMuBarrEndcRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  InvMassDiMuEndcEndcRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  Mu1PtRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  Mu2PtRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  DiMuPtRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  Mu1EtaRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  Mu2EtaRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  DiTauEtaRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  DiTauPhiRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  DiMuEtaRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  DiMudRRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  DiMuPhiRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  EtMETRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  DiTauDiMuMassRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  DiMuDiTauDeltaPhiRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  METDiTauDeltaPhiRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  METDiMuDeltaPhiRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  DiTaudRRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  DiTauMassSmallerdRRatioStatError->GetYaxis()->SetTitle("Obs / Exp");
  HighestCSVInclJetRatioStatError->GetYaxis()->SetTitle("Obs / Exp");

  NMedIsoTausWithMu3RatioStatError->SetMaximum(1.5);
  InvMassTauHadMu3RatioStatError->SetMaximum(1.5);
  PtTauHadMu3RatioStatError->SetMaximum(1.5);
  InvMassUpsilonRangeRatioStatError->SetMaximum(1.5);
  InvMassZPeakRangeRatioStatError->SetMaximum(1.5);
  InvMassFullRangeRatioStatError->SetMaximum(1.5);
  InvMassDiMuBarrBarrRatioStatError->SetMaximum(1.5);
  InvMassDiMuBarrEndcRatioStatError->SetMaximum(1.5);
  InvMassDiMuEndcEndcRatioStatError->SetMaximum(1.5);
  Mu1PtRatioStatError->SetMaximum(1.5);
  Mu2PtRatioStatError->SetMaximum(1.5);
  DiMuPtRatioStatError->SetMaximum(1.5);
  Mu1EtaRatioStatError->SetMaximum(1.5);
  Mu2EtaRatioStatError->SetMaximum(1.5);
  DiTauEtaRatioStatError->SetMaximum(1.5);
  DiTauPhiRatioStatError->SetMaximum(1.5);
  DiMuEtaRatioStatError->SetMaximum(1.5);
  DiMudRRatioStatError->SetMaximum(1.5);
  DiMuPhiRatioStatError->SetMaximum(1.5);
  EtMETRatioStatError->SetMaximum(1.5);
  DiTauDiMuMassRatioStatError->SetMaximum(1.5);
  DiMuDiTauDeltaPhiRatioStatError->SetMaximum(1.5);
  METDiTauDeltaPhiRatioStatError->SetMaximum(1.5);
  METDiMuDeltaPhiRatioStatError->SetMaximum(1.5);
  DiTaudRRatioStatError->SetMaximum(1.5);
  DiTauMassSmallerdRRatioStatError->SetMaximum(1.5);
  HighestCSVInclJetRatioStatError->SetMaximum(1.5);

  NMedIsoTausWithMu3RatioStatError->SetMinimum(.5);
  InvMassTauHadMu3RatioStatError->SetMinimum(.5);
  PtTauHadMu3RatioStatError->SetMinimum(.5);
  InvMassUpsilonRangeRatioStatError->SetMinimum(.5);
  InvMassZPeakRangeRatioStatError->SetMinimum(.5);
  InvMassFullRangeRatioStatError->SetMinimum(.5);
  InvMassDiMuBarrBarrRatioStatError->SetMinimum(.5);
  InvMassDiMuBarrEndcRatioStatError->SetMinimum(.5);
  InvMassDiMuEndcEndcRatioStatError->SetMinimum(.5);
  Mu1PtRatioStatError->SetMinimum(.5);
  Mu2PtRatioStatError->SetMinimum(.5);
  DiMuPtRatioStatError->SetMinimum(.5);
  Mu1EtaRatioStatError->SetMinimum(.5);
  Mu2EtaRatioStatError->SetMinimum(.5);
  DiTauEtaRatioStatError->SetMinimum(.5);
  DiTauPhiRatioStatError->SetMinimum(.5);
  DiMuEtaRatioStatError->SetMinimum(.5);
  DiMudRRatioStatError->SetMinimum(.5);
  DiMuPhiRatioStatError->SetMinimum(.5);
  EtMETRatioStatError->SetMinimum(.5);
  DiTauDiMuMassRatioStatError->SetMinimum(.5);
  DiMuDiTauDeltaPhiRatioStatError->SetMinimum(.5);
  METDiTauDeltaPhiRatioStatError->SetMinimum(.5);
  METDiMuDeltaPhiRatioStatError->SetMinimum(.5);
  DiTaudRRatioStatError->SetMinimum(.5);
  DiTauMassSmallerdRRatioStatError->SetMinimum(.5);
  HighestCSVInclJetRatioStatError->SetMinimum(.5);

  NMedIsoTausWithMu3RatioStatError->SetMarkerSize(0);
  InvMassTauHadMu3RatioStatError->SetMarkerSize(0);
  PtTauHadMu3RatioStatError->SetMarkerSize(0);
  InvMassUpsilonRangeRatioStatError->SetMarkerSize(0);
  InvMassZPeakRangeRatioStatError->SetMarkerSize(0);
  InvMassFullRangeRatioStatError->SetMarkerSize(0);
  InvMassDiMuBarrBarrRatioStatError->SetMarkerSize(0);
  InvMassDiMuBarrEndcRatioStatError->SetMarkerSize(0);
  InvMassDiMuEndcEndcRatioStatError->SetMarkerSize(0);
  Mu1PtRatioStatError->SetMarkerSize(0);
  Mu2PtRatioStatError->SetMarkerSize(0);
  DiMuPtRatioStatError->SetMarkerSize(0);
  Mu1EtaRatioStatError->SetMarkerSize(0);
  Mu2EtaRatioStatError->SetMarkerSize(0);
  DiTauEtaRatioStatError->SetMarkerSize(0);
  DiTauPhiRatioStatError->SetMarkerSize(0);
  DiMuEtaRatioStatError->SetMarkerSize(0);
  DiMudRRatioStatError->SetMarkerSize(0);
  DiMuPhiRatioStatError->SetMarkerSize(0);
  EtMETRatioStatError->SetMarkerSize(0);
  DiTauDiMuMassRatioStatError->SetMarkerSize(0);
  DiMuDiTauDeltaPhiRatioStatError->SetMarkerSize(0);
  METDiTauDeltaPhiRatioStatError->SetMarkerSize(0);
  METDiMuDeltaPhiRatioStatError->SetMarkerSize(0);
  DiTaudRRatioStatError->SetMarkerSize(0);
  DiTauMassSmallerdRRatioStatError->SetMarkerSize(0);
  HighestCSVInclJetRatioStatError->SetMarkerSize(0);

  NMedIsoTausWithMu3RatioStatError->SetFillColor(kGray+3);
  InvMassTauHadMu3RatioStatError->SetFillColor(kGray+3);
  PtTauHadMu3RatioStatError->SetFillColor(kGray+3);
  InvMassUpsilonRangeRatioStatError->SetFillColor(kGray+3);
  InvMassZPeakRangeRatioStatError->SetFillColor(kGray+3);
  InvMassFullRangeRatioStatError->SetFillColor(kGray+3);
  InvMassDiMuBarrBarrRatioStatError->SetFillColor(kGray+3);
  InvMassDiMuBarrEndcRatioStatError->SetFillColor(kGray+3);
  InvMassDiMuEndcEndcRatioStatError->SetFillColor(kGray+3);
  Mu1PtRatioStatError->SetFillColor(kGray+3);
  Mu2PtRatioStatError->SetFillColor(kGray+3);
  DiMuPtRatioStatError->SetFillColor(kGray+3);
  Mu1EtaRatioStatError->SetFillColor(kGray+3);
  Mu2EtaRatioStatError->SetFillColor(kGray+3);
  DiTauEtaRatioStatError->SetFillColor(kGray+3);
  DiTauPhiRatioStatError->SetFillColor(kGray+3);
  DiMuEtaRatioStatError->SetFillColor(kGray+3);
  DiMudRRatioStatError->SetFillColor(kGray+3);
  DiMuPhiRatioStatError->SetFillColor(kGray+3);
  EtMETRatioStatError->SetFillColor(kGray+3);
  DiTauDiMuMassRatioStatError->SetFillColor(kGray+3);
  DiMuDiTauDeltaPhiRatioStatError->SetFillColor(kGray+3);
  METDiTauDeltaPhiRatioStatError->SetFillColor(kGray+3);
  METDiMuDeltaPhiRatioStatError->SetFillColor(kGray+3);
  DiTaudRRatioStatError->SetFillColor(kGray+3);
  DiTauMassSmallerdRRatioStatError->SetFillColor(kGray+3);
  HighestCSVInclJetRatioStatError->SetFillColor(kGray+3);

  NMedIsoTausWithMu3RatioStatError->SetFillStyle(3013);
  InvMassTauHadMu3RatioStatError->SetFillStyle(3013);
  PtTauHadMu3RatioStatError->SetFillStyle(3013);
  InvMassUpsilonRangeRatioStatError->SetFillStyle(3013);
  InvMassZPeakRangeRatioStatError->SetFillStyle(3013);
  InvMassFullRangeRatioStatError->SetFillStyle(3013);
  InvMassDiMuBarrBarrRatioStatError->SetFillStyle(3013);
  InvMassDiMuBarrEndcRatioStatError->SetFillStyle(3013);
  InvMassDiMuEndcEndcRatioStatError->SetFillStyle(3013);
  Mu1PtRatioStatError->SetFillStyle(3013);
  Mu2PtRatioStatError->SetFillStyle(3013);
  DiMuPtRatioStatError->SetFillStyle(3013);
  Mu1EtaRatioStatError->SetFillStyle(3013);
  Mu2EtaRatioStatError->SetFillStyle(3013);
  DiTauEtaRatioStatError->SetFillStyle(3013);
  DiTauPhiRatioStatError->SetFillStyle(3013);
  DiMuEtaRatioStatError->SetFillStyle(3013);
  DiMudRRatioStatError->SetFillStyle(3013);
  DiMuPhiRatioStatError->SetFillStyle(3013);
  EtMETRatioStatError->SetFillStyle(3013);
  DiTauDiMuMassRatioStatError->SetFillStyle(3013);
  DiMuDiTauDeltaPhiRatioStatError->SetFillStyle(3013);
  METDiTauDeltaPhiRatioStatError->SetFillStyle(3013);
  METDiMuDeltaPhiRatioStatError->SetFillStyle(3013);
  DiTaudRRatioStatError->SetFillStyle(3013);
  DiTauMassSmallerdRRatioStatError->SetFillStyle(3013);
  HighestCSVInclJetRatioStatError->SetFillStyle(3013);

  NMedIsoTausWithMu3RatioStatError->GetXaxis()->SetLabelSize(0.19);
  InvMassTauHadMu3RatioStatError->GetXaxis()->SetLabelSize(0.19);
  PtTauHadMu3RatioStatError->GetXaxis()->SetLabelSize(0.19);
  InvMassUpsilonRangeRatioStatError->GetXaxis()->SetLabelSize(0.19);
  InvMassZPeakRangeRatioStatError->GetXaxis()->SetLabelSize(0.19);
  InvMassFullRangeRatioStatError->GetXaxis()->SetLabelSize(0.19);
  InvMassDiMuBarrBarrRatioStatError->GetXaxis()->SetLabelSize(0.19);
  InvMassDiMuBarrEndcRatioStatError->GetXaxis()->SetLabelSize(0.19);
  InvMassDiMuEndcEndcRatioStatError->GetXaxis()->SetLabelSize(0.19);
  Mu1PtRatioStatError->GetXaxis()->SetLabelSize(0.19);
  Mu2PtRatioStatError->GetXaxis()->SetLabelSize(0.19);
  DiMuPtRatioStatError->GetXaxis()->SetLabelSize(0.19);
  Mu1EtaRatioStatError->GetXaxis()->SetLabelSize(0.19);
  Mu2EtaRatioStatError->GetXaxis()->SetLabelSize(0.19);
  DiTauEtaRatioStatError->GetXaxis()->SetLabelSize(0.19);
  DiTauPhiRatioStatError->GetXaxis()->SetLabelSize(0.19);
  DiMuEtaRatioStatError->GetXaxis()->SetLabelSize(0.19);
  DiMudRRatioStatError->GetXaxis()->SetLabelSize(0.19);
  DiMuPhiRatioStatError->GetXaxis()->SetLabelSize(0.19);
  EtMETRatioStatError->GetXaxis()->SetLabelSize(0.19);
  DiTauDiMuMassRatioStatError->GetXaxis()->SetLabelSize(0.19);
  DiMuDiTauDeltaPhiRatioStatError->GetXaxis()->SetLabelSize(0.19);
  METDiTauDeltaPhiRatioStatError->GetXaxis()->SetLabelSize(0.19);
  METDiMuDeltaPhiRatioStatError->GetXaxis()->SetLabelSize(0.19);
  DiTaudRRatioStatError->GetXaxis()->SetLabelSize(0.19);
  DiTauMassSmallerdRRatioStatError->GetXaxis()->SetLabelSize(0.19);
  HighestCSVInclJetRatioStatError->GetXaxis()->SetLabelSize(0.19);

  NMedIsoTausWithMu3RatioStatError->GetXaxis()->SetTitleSize(0.21);
  InvMassTauHadMu3RatioStatError->GetXaxis()->SetTitleSize(0.21);
  PtTauHadMu3RatioStatError->GetXaxis()->SetTitleSize(0.21);
  InvMassUpsilonRangeRatioStatError->GetXaxis()->SetTitleSize(0.21);
  InvMassZPeakRangeRatioStatError->GetXaxis()->SetTitleSize(0.21);
  InvMassFullRangeRatioStatError->GetXaxis()->SetTitleSize(0.21);
  InvMassDiMuBarrBarrRatioStatError->GetXaxis()->SetTitleSize(0.21);
  InvMassDiMuBarrEndcRatioStatError->GetXaxis()->SetTitleSize(0.21);
  InvMassDiMuEndcEndcRatioStatError->GetXaxis()->SetTitleSize(0.21);
  Mu1PtRatioStatError->GetXaxis()->SetTitleSize(0.21);
  Mu2PtRatioStatError->GetXaxis()->SetTitleSize(0.21);
  DiMuPtRatioStatError->GetXaxis()->SetTitleSize(0.21);
  Mu1EtaRatioStatError->GetXaxis()->SetTitleSize(0.21);
  Mu2EtaRatioStatError->GetXaxis()->SetTitleSize(0.21);
  DiTauEtaRatioStatError->GetXaxis()->SetTitleSize(0.21);
  DiTauPhiRatioStatError->GetXaxis()->SetTitleSize(0.21);
  DiMuEtaRatioStatError->GetXaxis()->SetTitleSize(0.21);
  DiMudRRatioStatError->GetXaxis()->SetTitleSize(0.21);
  DiMuPhiRatioStatError->GetXaxis()->SetTitleSize(0.21);
  EtMETRatioStatError->GetXaxis()->SetTitleSize(0.21);
  DiTauDiMuMassRatioStatError->GetXaxis()->SetTitleSize(0.21);
  DiMuDiTauDeltaPhiRatioStatError->GetXaxis()->SetTitleSize(0.21);
  METDiTauDeltaPhiRatioStatError->GetXaxis()->SetTitleSize(0.21);
  METDiMuDeltaPhiRatioStatError->GetXaxis()->SetTitleSize(0.21);
  DiTaudRRatioStatError->GetXaxis()->SetTitleSize(0.21);
  DiTauMassSmallerdRRatioStatError->GetXaxis()->SetTitleSize(0.21);
  HighestCSVInclJetRatioStatError->GetXaxis()->SetTitleSize(0.21);

  NMedIsoTausWithMu3RatioStatError->GetXaxis()->SetTitleOffset(1.0);
  InvMassTauHadMu3RatioStatError->GetXaxis()->SetTitleOffset(1.0);
  PtTauHadMu3RatioStatError->GetXaxis()->SetTitleOffset(1.0);
  InvMassUpsilonRangeRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  InvMassZPeakRangeRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  InvMassFullRangeRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  InvMassDiMuBarrBarrRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  InvMassDiMuBarrEndcRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  InvMassDiMuEndcEndcRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  Mu1PtRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  Mu2PtRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  DiMuPtRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  Mu1EtaRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  Mu2EtaRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  DiTauEtaRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  DiTauPhiRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  DiMuEtaRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  DiMudRRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  DiMuPhiRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  EtMETRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  DiTauDiMuMassRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  DiMuDiTauDeltaPhiRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  METDiTauDeltaPhiRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  METDiMuDeltaPhiRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  DiTaudRRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  DiTauMassSmallerdRRatioStatError->GetXaxis()->SetTitleOffset(1.0);
  HighestCSVInclJetRatioStatError->GetXaxis()->SetTitleOffset(1.0);

  NMedIsoTausWithMu3RatioStatError->GetXaxis()->SetLabelOffset(0.03);
  InvMassTauHadMu3RatioStatError->GetXaxis()->SetLabelOffset(0.03);
  PtTauHadMu3RatioStatError->GetXaxis()->SetLabelOffset(0.03);
  InvMassUpsilonRangeRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  InvMassZPeakRangeRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  InvMassFullRangeRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  InvMassDiMuBarrBarrRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  InvMassDiMuBarrEndcRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  InvMassDiMuEndcEndcRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  Mu1PtRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  Mu2PtRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  DiMuPtRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  Mu1EtaRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  Mu2EtaRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  DiTauEtaRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  DiTauPhiRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  DiMuEtaRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  DiMudRRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  DiMuPhiRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  EtMETRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  DiTauDiMuMassRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  DiMuDiTauDeltaPhiRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  METDiTauDeltaPhiRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  METDiMuDeltaPhiRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  DiTaudRRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  DiTauMassSmallerdRRatioStatError->GetXaxis()->SetLabelOffset(0.03);
  HighestCSVInclJetRatioStatError->GetXaxis()->SetLabelOffset(0.03);

  NMedIsoTausWithMu3RatioStatError->GetYaxis()->SetLabelSize(0.19);
  InvMassTauHadMu3RatioStatError->GetYaxis()->SetLabelSize(0.19);
  PtTauHadMu3RatioStatError->GetYaxis()->SetLabelSize(0.19);
  InvMassUpsilonRangeRatioStatError->GetYaxis()->SetLabelSize(0.19);
  InvMassZPeakRangeRatioStatError->GetYaxis()->SetLabelSize(0.19);
  InvMassFullRangeRatioStatError->GetYaxis()->SetLabelSize(0.19);
  InvMassDiMuBarrBarrRatioStatError->GetYaxis()->SetLabelSize(0.19);
  InvMassDiMuBarrEndcRatioStatError->GetYaxis()->SetLabelSize(0.19);
  InvMassDiMuEndcEndcRatioStatError->GetYaxis()->SetLabelSize(0.19);
  Mu1PtRatioStatError->GetYaxis()->SetLabelSize(0.19);
  Mu2PtRatioStatError->GetYaxis()->SetLabelSize(0.19);
  DiMuPtRatioStatError->GetYaxis()->SetLabelSize(0.19);
  Mu1EtaRatioStatError->GetYaxis()->SetLabelSize(0.19);
  Mu2EtaRatioStatError->GetYaxis()->SetLabelSize(0.19);
  DiTauEtaRatioStatError->GetYaxis()->SetLabelSize(0.19);
  DiTauPhiRatioStatError->GetYaxis()->SetLabelSize(0.19);
  DiMuEtaRatioStatError->GetYaxis()->SetLabelSize(0.19);
  DiMudRRatioStatError->GetYaxis()->SetLabelSize(0.19);
  DiMuPhiRatioStatError->GetYaxis()->SetLabelSize(0.19);
  EtMETRatioStatError->GetYaxis()->SetLabelSize(0.19);
  DiTauDiMuMassRatioStatError->GetYaxis()->SetLabelSize(0.19);
  DiMuDiTauDeltaPhiRatioStatError->GetYaxis()->SetLabelSize(0.19);
  METDiTauDeltaPhiRatioStatError->GetYaxis()->SetLabelSize(0.19);
  METDiMuDeltaPhiRatioStatError->GetYaxis()->SetLabelSize(0.19);
  DiTaudRRatioStatError->GetYaxis()->SetLabelSize(0.19);
  DiTauMassSmallerdRRatioStatError->GetYaxis()->SetLabelSize(0.19);
  HighestCSVInclJetRatioStatError->GetYaxis()->SetLabelSize(0.19);

  NMedIsoTausWithMu3RatioStatError->GetYaxis()->SetLabelOffset(0.006);
  InvMassTauHadMu3RatioStatError->GetYaxis()->SetLabelOffset(0.006);
  PtTauHadMu3RatioStatError->GetYaxis()->SetLabelOffset(0.006);
  InvMassUpsilonRangeRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  InvMassZPeakRangeRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  InvMassFullRangeRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  InvMassDiMuBarrBarrRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  InvMassDiMuBarrEndcRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  InvMassDiMuEndcEndcRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  Mu1PtRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  Mu2PtRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  DiMuPtRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  Mu1EtaRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  Mu2EtaRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  DiTauEtaRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  DiTauPhiRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  DiMuEtaRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  DiMudRRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  DiMuPhiRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  EtMETRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  DiTauDiMuMassRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  DiMuDiTauDeltaPhiRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  METDiTauDeltaPhiRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  METDiMuDeltaPhiRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  DiTaudRRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  DiTauMassSmallerdRRatioStatError->GetYaxis()->SetLabelOffset(0.006);
  HighestCSVInclJetRatioStatError->GetYaxis()->SetLabelOffset(0.006);

  NMedIsoTausWithMu3RatioStatError->GetYaxis()->SetTitleSize(0.21);
  InvMassTauHadMu3RatioStatError->GetYaxis()->SetTitleSize(0.21);
  PtTauHadMu3RatioStatError->GetYaxis()->SetTitleSize(0.21);
  InvMassUpsilonRangeRatioStatError->GetYaxis()->SetTitleSize(0.21);
  InvMassZPeakRangeRatioStatError->GetYaxis()->SetTitleSize(0.21);
  InvMassFullRangeRatioStatError->GetYaxis()->SetTitleSize(0.21);
  InvMassDiMuBarrBarrRatioStatError->GetYaxis()->SetTitleSize(0.21);
  InvMassDiMuBarrEndcRatioStatError->GetYaxis()->SetTitleSize(0.21);
  InvMassDiMuEndcEndcRatioStatError->GetYaxis()->SetTitleSize(0.21);
  Mu1PtRatioStatError->GetYaxis()->SetTitleSize(0.21);
  Mu2PtRatioStatError->GetYaxis()->SetTitleSize(0.21);
  DiMuPtRatioStatError->GetYaxis()->SetTitleSize(0.21);
  Mu1EtaRatioStatError->GetYaxis()->SetTitleSize(0.21);
  Mu2EtaRatioStatError->GetYaxis()->SetTitleSize(0.21);
  DiTauEtaRatioStatError->GetYaxis()->SetTitleSize(0.21);
  DiTauPhiRatioStatError->GetYaxis()->SetTitleSize(0.21);
  DiMuEtaRatioStatError->GetYaxis()->SetTitleSize(0.21);
  DiMudRRatioStatError->GetYaxis()->SetTitleSize(0.21);
  DiMuPhiRatioStatError->GetYaxis()->SetTitleSize(0.21);
  EtMETRatioStatError->GetYaxis()->SetTitleSize(0.21);
  DiTauDiMuMassRatioStatError->GetYaxis()->SetTitleSize(0.21);
  DiMuDiTauDeltaPhiRatioStatError->GetYaxis()->SetTitleSize(0.21);
  METDiTauDeltaPhiRatioStatError->GetYaxis()->SetTitleSize(0.21);
  METDiMuDeltaPhiRatioStatError->GetYaxis()->SetTitleSize(0.21);
  DiTaudRRatioStatError->GetYaxis()->SetTitleSize(0.21);
  DiTauMassSmallerdRRatioStatError->GetYaxis()->SetTitleSize(0.21);
  HighestCSVInclJetRatioStatError->GetYaxis()->SetTitleSize(0.21);

  NMedIsoTausWithMu3RatioStatError->GetYaxis()->SetTitleOffset(0.35);
  InvMassTauHadMu3RatioStatError->GetYaxis()->SetTitleOffset(0.35);
  PtTauHadMu3RatioStatError->GetYaxis()->SetTitleOffset(0.35);
  InvMassUpsilonRangeRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  InvMassZPeakRangeRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  InvMassFullRangeRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  InvMassDiMuBarrBarrRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  InvMassDiMuBarrEndcRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  InvMassDiMuEndcEndcRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  Mu1PtRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  Mu2PtRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  DiMuPtRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  Mu1EtaRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  Mu2EtaRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  DiTauEtaRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  DiTauPhiRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  DiMuEtaRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  DiMudRRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  DiMuPhiRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  EtMETRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  DiTauDiMuMassRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  DiMuDiTauDeltaPhiRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  METDiTauDeltaPhiRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  METDiMuDeltaPhiRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  DiTaudRRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  DiTauMassSmallerdRRatioStatError->GetYaxis()->SetTitleOffset(0.35);
  HighestCSVInclJetRatioStatError->GetYaxis()->SetTitleOffset(0.35);


  NMedIsoTausWithMu3RatioStatError->GetYaxis()->SetNdivisions(503);
  InvMassTauHadMu3RatioStatError->GetYaxis()->SetNdivisions(503);
  PtTauHadMu3RatioStatError->GetYaxis()->SetNdivisions(503);
  InvMassUpsilonRangeRatioStatError->GetYaxis()->SetNdivisions(503);
  InvMassZPeakRangeRatioStatError->GetYaxis()->SetNdivisions(503);
  InvMassFullRangeRatioStatError->GetYaxis()->SetNdivisions(503);
  InvMassDiMuBarrBarrRatioStatError->GetYaxis()->SetNdivisions(503);
  InvMassDiMuBarrEndcRatioStatError->GetYaxis()->SetNdivisions(503);
  InvMassDiMuEndcEndcRatioStatError->GetYaxis()->SetNdivisions(503);
  Mu1PtRatioStatError->GetYaxis()->SetNdivisions(503);
  Mu2PtRatioStatError->GetYaxis()->SetNdivisions(503);
  DiMuPtRatioStatError->GetYaxis()->SetNdivisions(503);
  Mu1EtaRatioStatError->GetYaxis()->SetNdivisions(503);
  Mu2EtaRatioStatError->GetYaxis()->SetNdivisions(503);
  DiTauEtaRatioStatError->GetYaxis()->SetNdivisions(503);
  DiTauPhiRatioStatError->GetYaxis()->SetNdivisions(503);
  DiMuEtaRatioStatError->GetYaxis()->SetNdivisions(503);
  DiMudRRatioStatError->GetYaxis()->SetNdivisions(503);
  DiMuPhiRatioStatError->GetYaxis()->SetNdivisions(503);
  EtMETRatioStatError->GetYaxis()->SetNdivisions(503);
  DiTauDiMuMassRatioStatError->GetYaxis()->SetNdivisions(503);
  DiMuDiTauDeltaPhiRatioStatError->GetYaxis()->SetNdivisions(503);
  METDiTauDeltaPhiRatioStatError->GetYaxis()->SetNdivisions(503);
  METDiMuDeltaPhiRatioStatError->GetYaxis()->SetNdivisions(503);
  DiTaudRRatioStatError->GetYaxis()->SetNdivisions(503);
  DiTauMassSmallerdRRatioStatError->GetYaxis()->SetNdivisions(503);
  HighestCSVInclJetRatioStatError->GetYaxis()->SetNdivisions(503);

cout << "Set Ratio Plot" << endl;
  double binerror;
  for(unsigned int i=0; i < NMedIsoTausWithMu3denom->GetNbinsX()+2; i++)
  {
    NMedIsoTausWithMu3RatioStatError->SetBinContent(i, 1.0);
    if (NMedIsoTausWithMu3denom->GetBinContent(i) > .000001)
    {
      binerror = NMedIsoTausWithMu3denom->GetBinError(i) / NMedIsoTausWithMu3denom->GetBinContent(i);
      NMedIsoTausWithMu3RatioStatError->SetBinError(i, binerror);
    }//if
    else
      NMedIsoTausWithMu3RatioStatError->SetBinError(i, 999.);
  }//for
  NMedIsoTausWithMu3RatioStatError->SetXTitle(NMedIsoTausWithMu3TT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < InvMassTauHadMu3denom->GetNbinsX()+2; i++)
  {
    InvMassTauHadMu3RatioStatError->SetBinContent(i, 1.0);
    if (InvMassTauHadMu3denom->GetBinContent(i) > .000001)
    { 
      binerror = InvMassTauHadMu3denom->GetBinError(i) / InvMassTauHadMu3denom->GetBinContent(i);
      InvMassTauHadMu3RatioStatError->SetBinError(i, binerror);
    }//if
    else
      InvMassTauHadMu3RatioStatError->SetBinError(i, 999.);
  }//for
  InvMassTauHadMu3RatioStatError->SetXTitle(InvMassTauHadMu3TT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < PtTauHadMu3denom->GetNbinsX()+2; i++)
  {
    PtTauHadMu3RatioStatError->SetBinContent(i, 1.0);
    if (PtTauHadMu3denom->GetBinContent(i) > .000001)
    { 
      binerror = PtTauHadMu3denom->GetBinError(i) / PtTauHadMu3denom->GetBinContent(i);
      PtTauHadMu3RatioStatError->SetBinError(i, binerror);
    }//if
    else
      PtTauHadMu3RatioStatError->SetBinError(i, 999.);
  }//for
  PtTauHadMu3RatioStatError->SetXTitle(PtTauHadMu3TT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < InvMassUpsilonRangedenom->GetNbinsX()+2; i++)
  {
    InvMassUpsilonRangeRatioStatError->SetBinContent(i, 1.0);
    if (InvMassUpsilonRangedenom->GetBinContent(i) > .000001)
    { 
      binerror = InvMassUpsilonRangedenom->GetBinError(i) / InvMassUpsilonRangedenom->GetBinContent(i);
      InvMassUpsilonRangeRatioStatError->SetBinError(i, binerror);
    }//if
    else
      InvMassUpsilonRangeRatioStatError->SetBinError(i, 999.);
  }//for
  InvMassUpsilonRangeRatioStatError->SetXTitle(InvMassUpsilonRangeTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < InvMassZPeakRangedenom->GetNbinsX()+2; i++)
  {
    InvMassZPeakRangeRatioStatError->SetBinContent(i, 1.0);
    if (InvMassZPeakRangedenom->GetBinContent(i) > .000001)
    { 
      binerror = InvMassZPeakRangedenom->GetBinError(i) / InvMassZPeakRangedenom->GetBinContent(i);
      InvMassZPeakRangeRatioStatError->SetBinError(i, binerror);
    }//if
    else
      InvMassZPeakRangeRatioStatError->SetBinError(i, 999.);
  }//for
  InvMassZPeakRangeRatioStatError->SetXTitle(InvMassZPeakRangeTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < InvMassFullRangedenom->GetNbinsX()+2; i++)
  {
    InvMassFullRangeRatioStatError->SetBinContent(i, 1.0);
    if (InvMassFullRangedenom->GetBinContent(i) > .000001)
    { 
      binerror = InvMassFullRangedenom->GetBinError(i) / InvMassFullRangedenom->GetBinContent(i);
      InvMassFullRangeRatioStatError->SetBinError(i, binerror);
    }//if
    else
      InvMassFullRangeRatioStatError->SetBinError(i, 999.);
  }//for
  InvMassFullRangeRatioStatError->SetXTitle(InvMassFullRangeTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < InvMassDiMuBarrBarrdenom->GetNbinsX()+2; i++)
  {
    InvMassDiMuBarrBarrRatioStatError->SetBinContent(i, 1.0);
    if (InvMassDiMuBarrBarrdenom->GetBinContent(i) > .000001)
    { 
      binerror = InvMassDiMuBarrBarrdenom->GetBinError(i) / InvMassDiMuBarrBarrdenom->GetBinContent(i);
      InvMassDiMuBarrBarrRatioStatError->SetBinError(i, binerror);
    }//if
    else
      InvMassDiMuBarrBarrRatioStatError->SetBinError(i, 999.);
  }//for
  InvMassDiMuBarrBarrRatioStatError->SetXTitle(InvMassDiMuBarrBarrTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < InvMassDiMuBarrEndcdenom->GetNbinsX()+2; i++)
  {
    InvMassDiMuBarrEndcRatioStatError->SetBinContent(i, 1.0);
    if (InvMassDiMuBarrEndcdenom->GetBinContent(i) > .000001)
    { 
      binerror = InvMassDiMuBarrEndcdenom->GetBinError(i) / InvMassDiMuBarrEndcdenom->GetBinContent(i);
      InvMassDiMuBarrEndcRatioStatError->SetBinError(i, binerror);
    }//if
    else
      InvMassDiMuBarrEndcRatioStatError->SetBinError(i, 999.);
  }//for
  InvMassDiMuBarrEndcRatioStatError->SetXTitle(InvMassDiMuBarrEndcTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < InvMassDiMuEndcEndcdenom->GetNbinsX()+2; i++)
  {
    InvMassDiMuEndcEndcRatioStatError->SetBinContent(i, 1.0);
    if (InvMassDiMuEndcEndcdenom->GetBinContent(i) > .000001)
    { 
      binerror = InvMassDiMuEndcEndcdenom->GetBinError(i) / InvMassDiMuEndcEndcdenom->GetBinContent(i);
      InvMassDiMuEndcEndcRatioStatError->SetBinError(i, binerror);
    }//if
    else
      InvMassDiMuEndcEndcRatioStatError->SetBinError(i, 999.);
  }//for
  InvMassDiMuEndcEndcRatioStatError->SetXTitle(InvMassDiMuEndcEndcTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < Mu1Ptdenom->GetNbinsX()+2; i++)
  {
    Mu1PtRatioStatError->SetBinContent(i, 1.0);
    if (Mu1Ptdenom->GetBinContent(i) > .000001)
    { 
      binerror = Mu1Ptdenom->GetBinError(i) / Mu1Ptdenom->GetBinContent(i);
      Mu1PtRatioStatError->SetBinError(i, binerror);
    }//if
    else
      Mu1PtRatioStatError->SetBinError(i, 999.);
  }//for
  Mu1PtRatioStatError->SetXTitle(Mu1PtTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < Mu2Ptdenom->GetNbinsX()+2; i++)
  {
    Mu2PtRatioStatError->SetBinContent(i, 1.0);
    if (Mu2Ptdenom->GetBinContent(i) > .000001)
    { 
      binerror = Mu2Ptdenom->GetBinError(i) / Mu2Ptdenom->GetBinContent(i);
      Mu2PtRatioStatError->SetBinError(i, binerror);
    }//if
    else
      Mu2PtRatioStatError->SetBinError(i, 999.);
  }//for
  Mu2PtRatioStatError->SetXTitle(Mu2PtTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < DiMuPtdenom->GetNbinsX()+2; i++)
  {
    DiMuPtRatioStatError->SetBinContent(i, 1.0);
    if (DiMuPtdenom->GetBinContent(i) > .000001)
    { 
      binerror = DiMuPtdenom->GetBinError(i) / DiMuPtdenom->GetBinContent(i);
      DiMuPtRatioStatError->SetBinError(i, binerror);
    }//if
    else
      DiMuPtRatioStatError->SetBinError(i, 999.);
  }//for
  DiMuPtRatioStatError->SetXTitle(DiMuPtTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < Mu1Etadenom->GetNbinsX()+2; i++)
  {
    Mu1EtaRatioStatError->SetBinContent(i, 1.0);
    if (Mu1Etadenom->GetBinContent(i) > .000001)
    { 
      binerror = Mu1Etadenom->GetBinError(i) / Mu1Etadenom->GetBinContent(i);
      Mu1EtaRatioStatError->SetBinError(i, binerror);
    }//if
    else
      Mu1EtaRatioStatError->SetBinError(i, 999.);
  }//for
  Mu1EtaRatioStatError->SetXTitle(Mu1EtaTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < Mu2Etadenom->GetNbinsX()+2; i++)
  {
    Mu2EtaRatioStatError->SetBinContent(i, 1.0);
    if (Mu2Etadenom->GetBinContent(i) > .000001)
    { 
      binerror = Mu2Etadenom->GetBinError(i) / Mu2Etadenom->GetBinContent(i);
      Mu2EtaRatioStatError->SetBinError(i, binerror);
    }//if
    else
      Mu2EtaRatioStatError->SetBinError(i, 999.);
  }//for
  Mu2EtaRatioStatError->SetXTitle(Mu2EtaTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < DiTauEtadenom->GetNbinsX()+2; i++)
  {
    DiTauEtaRatioStatError->SetBinContent(i, 1.0);
    if (DiTauEtadenom->GetBinContent(i) > .000001)
    { 
      binerror = DiTauEtadenom->GetBinError(i) / DiTauEtadenom->GetBinContent(i);
      DiTauEtaRatioStatError->SetBinError(i, binerror);
    }//if
    else
      DiTauEtaRatioStatError->SetBinError(i, 999.);
  }//for
  DiTauEtaRatioStatError->SetXTitle(DiTauEtaTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < DiTauPhidenom->GetNbinsX()+2; i++)
  {
    DiTauPhiRatioStatError->SetBinContent(i, 1.0);
    if (DiTauPhidenom->GetBinContent(i) > .000001)
    { 
      binerror = DiTauPhidenom->GetBinError(i) / DiTauPhidenom->GetBinContent(i);
      DiTauPhiRatioStatError->SetBinError(i, binerror);
    }//if
    else
      DiTauPhiRatioStatError->SetBinError(i, 999.);
  }//for
  DiTauPhiRatioStatError->SetXTitle(DiTauPhiTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < DiMuEtadenom->GetNbinsX()+2; i++)
  {
    DiMuEtaRatioStatError->SetBinContent(i, 1.0);
    if (DiMuEtadenom->GetBinContent(i) > .000001)
    { 
      binerror = DiMuEtadenom->GetBinError(i) / DiMuEtadenom->GetBinContent(i);
      DiMuEtaRatioStatError->SetBinError(i, binerror);
    }//if
    else
      DiMuEtaRatioStatError->SetBinError(i, 999.);
  }//for
  DiMuEtaRatioStatError->SetXTitle(DiMuEtaTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < DiMudRdenom->GetNbinsX()+2; i++)
  {
    DiMudRRatioStatError->SetBinContent(i, 1.0);
    if (DiMudRdenom->GetBinContent(i) > .000001)
    { 
      binerror = DiMudRdenom->GetBinError(i) / DiMudRdenom->GetBinContent(i);
      DiMudRRatioStatError->SetBinError(i, binerror);
    }//if
    else
      DiMudRRatioStatError->SetBinError(i, 999.);
  }//for
  DiMudRRatioStatError->SetXTitle(DiMudRTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < DiMuPhidenom->GetNbinsX()+2; i++)
  {
    DiMuPhiRatioStatError->SetBinContent(i, 1.0);
    if (DiMuPhidenom->GetBinContent(i) > .000001)
    { 
      binerror = DiMuPhidenom->GetBinError(i) / DiMuPhidenom->GetBinContent(i);
      DiMuPhiRatioStatError->SetBinError(i, binerror);
    }//if
    else
      DiMuPhiRatioStatError->SetBinError(i, 999.);
  }//for
  DiMuPhiRatioStatError->SetXTitle(DiMuPhiTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < EtMETdenom->GetNbinsX()+2; i++)
  {
    EtMETRatioStatError->SetBinContent(i, 1.0);
    if (EtMETdenom->GetBinContent(i) > .000001)
    { 
      binerror = EtMETdenom->GetBinError(i) / EtMETdenom->GetBinContent(i);
      EtMETRatioStatError->SetBinError(i, binerror);
    }//if
    else
      EtMETRatioStatError->SetBinError(i, 999.);
  }//for
  EtMETRatioStatError->SetXTitle(EtMETTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < DiTauDiMuMassdenom->GetNbinsX()+2; i++)
  {
    DiTauDiMuMassRatioStatError->SetBinContent(i, 1.0);
    if (DiTauDiMuMassdenom->GetBinContent(i) > .000001)
    { 
      binerror = DiTauDiMuMassdenom->GetBinError(i) / DiTauDiMuMassdenom->GetBinContent(i);
      DiTauDiMuMassRatioStatError->SetBinError(i, binerror);
    }//if
    else
      DiTauDiMuMassRatioStatError->SetBinError(i, 999.);
  }//for
  DiTauDiMuMassRatioStatError->SetXTitle(DiTauDiMuMassTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < DiMuDiTauDeltaPhidenom->GetNbinsX()+2; i++)
  {
    DiMuDiTauDeltaPhiRatioStatError->SetBinContent(i, 1.0);
    if (DiMuDiTauDeltaPhidenom->GetBinContent(i) > .000001)
    { 
      binerror = DiMuDiTauDeltaPhidenom->GetBinError(i) / DiMuDiTauDeltaPhidenom->GetBinContent(i);
      DiMuDiTauDeltaPhiRatioStatError->SetBinError(i, binerror);
    }//if
    else
      DiMuDiTauDeltaPhiRatioStatError->SetBinError(i, 999.);
  }//for
  DiMuDiTauDeltaPhiRatioStatError->SetXTitle(DiMuDiTauDeltaPhiTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < METDiTauDeltaPhidenom->GetNbinsX()+2; i++)
  {
    METDiTauDeltaPhiRatioStatError->SetBinContent(i, 1.0);
    if (METDiTauDeltaPhidenom->GetBinContent(i) > .000001)
    { 
      binerror = METDiTauDeltaPhidenom->GetBinError(i) / METDiTauDeltaPhidenom->GetBinContent(i);
      METDiTauDeltaPhiRatioStatError->SetBinError(i, binerror);
    }//if
    else
      METDiTauDeltaPhiRatioStatError->SetBinError(i, 999.);
  }//for
  METDiTauDeltaPhiRatioStatError->SetXTitle(METDiTauDeltaPhiTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < METDiMuDeltaPhidenom->GetNbinsX()+2; i++)
  {
    METDiMuDeltaPhiRatioStatError->SetBinContent(i, 1.0);
    if (METDiMuDeltaPhidenom->GetBinContent(i) > .000001)
    { 
      binerror = METDiMuDeltaPhidenom->GetBinError(i) / METDiMuDeltaPhidenom->GetBinContent(i);
      METDiMuDeltaPhiRatioStatError->SetBinError(i, binerror);
    }//if
    else
      METDiMuDeltaPhiRatioStatError->SetBinError(i, 999.);
  }//for
  METDiMuDeltaPhiRatioStatError->SetXTitle(METDiMuDeltaPhiTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < DiTaudRdenom->GetNbinsX()+2; i++)
  {
    DiTaudRRatioStatError->SetBinContent(i, 1.0);
    if (DiTaudRdenom->GetBinContent(i) > .000001)
    { 
      binerror = DiTaudRdenom->GetBinError(i) / DiTaudRdenom->GetBinContent(i);
      DiTaudRRatioStatError->SetBinError(i, binerror);
    }//if
    else
      DiTaudRRatioStatError->SetBinError(i, 999.);
  }//for
  DiTaudRRatioStatError->SetXTitle(DiTaudRTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < DiTauMassSmallerdRdenom->GetNbinsX()+2; i++)
  {
    DiTauMassSmallerdRRatioStatError->SetBinContent(i, 1.0);
    if (DiTauMassSmallerdRdenom->GetBinContent(i) > .000001)
    { 
      binerror = DiTauMassSmallerdRdenom->GetBinError(i) / DiTauMassSmallerdRdenom->GetBinContent(i);
      DiTauMassSmallerdRRatioStatError->SetBinError(i, binerror);
    }//if
    else
      DiTauMassSmallerdRRatioStatError->SetBinError(i, 999.);
  }//for
  DiTauMassSmallerdRRatioStatError->SetXTitle(DiTauMassSmallerdRTT_->GetXaxis()->GetTitle() );

  for(unsigned int i=0; i < HighestCSVInclJetdenom->GetNbinsX()+2; i++)
  {
    HighestCSVInclJetRatioStatError->SetBinContent(i, 1.0);
    if (HighestCSVInclJetdenom->GetBinContent(i) > .000001)
    { 
      binerror = HighestCSVInclJetdenom->GetBinError(i) / HighestCSVInclJetdenom->GetBinContent(i);
      HighestCSVInclJetRatioStatError->SetBinError(i, binerror);
    }//if
    else
      HighestCSVInclJetRatioStatError->SetBinError(i, 999.);
  }//for
  HighestCSVInclJetRatioStatError->SetXTitle(HighestCSVInclJetTT_->GetXaxis()->GetTitle() );

cout << "Got Bin Errors" << endl;
  TLine *NMedIsoTausWithMu3RatioUnity = new TLine(NMedIsoTausWithMu3denom->GetXaxis()->GetXmin(), 1, NMedIsoTausWithMu3denom->GetXaxis()->GetXmax(), 1);
  TLine *InvMassTauHadMu3RatioUnity = new TLine(InvMassTauHadMu3denom->GetXaxis()->GetXmin(), 1, InvMassTauHadMu3denom->GetXaxis()->GetXmax(), 1);
  TLine *PtTauHadMu3RatioUnity = new TLine(PtTauHadMu3denom->GetXaxis()->GetXmin(), 1, PtTauHadMu3denom->GetXaxis()->GetXmax(), 1);
  TLine *InvMassUpsilonRangeRatioUnity = new TLine(InvMassUpsilonRangedenom->GetXaxis()->GetXmin(), 1, InvMassUpsilonRangedenom->GetXaxis()->GetXmax(), 1);
  TLine *InvMassZPeakRangeRatioUnity = new TLine(InvMassZPeakRangedenom->GetXaxis()->GetXmin(), 1, InvMassZPeakRangedenom->GetXaxis()->GetXmax(), 1);
  TLine *InvMassFullRangeRatioUnity = new TLine(InvMassFullRangedenom->GetXaxis()->GetXmin(), 1, InvMassFullRangedenom->GetXaxis()->GetXmax(), 1);
  TLine *InvMassDiMuBarrBarrRatioUnity = new TLine(InvMassDiMuBarrBarrdenom->GetXaxis()->GetXmin(), 1, InvMassDiMuBarrBarrdenom->GetXaxis()->GetXmax(), 1);
  TLine *InvMassDiMuBarrEndcRatioUnity = new TLine(InvMassDiMuBarrEndcdenom->GetXaxis()->GetXmin(), 1, InvMassDiMuBarrEndcdenom->GetXaxis()->GetXmax(), 1);
  TLine *InvMassDiMuEndcEndcRatioUnity = new TLine(InvMassDiMuEndcEndcdenom->GetXaxis()->GetXmin(), 1, InvMassDiMuEndcEndcdenom->GetXaxis()->GetXmax(), 1);
  TLine *Mu1PtRatioUnity = new TLine(Mu1Ptdenom->GetXaxis()->GetXmin(), 1, Mu1Ptdenom->GetXaxis()->GetXmax(), 1);
  TLine *Mu2PtRatioUnity = new TLine(Mu2Ptdenom->GetXaxis()->GetXmin(), 1, Mu2Ptdenom->GetXaxis()->GetXmax(), 1);
  TLine *DiMuPtRatioUnity = new TLine(DiMuPtdenom->GetXaxis()->GetXmin(), 1, DiMuPtdenom->GetXaxis()->GetXmax(), 1);
  TLine *Mu1EtaRatioUnity = new TLine(Mu1Etadenom->GetXaxis()->GetXmin(), 1, Mu1Etadenom->GetXaxis()->GetXmax(), 1);
  TLine *Mu2EtaRatioUnity = new TLine(Mu2Etadenom->GetXaxis()->GetXmin(), 1, Mu2Etadenom->GetXaxis()->GetXmax(), 1);
  TLine *DiTauEtaRatioUnity = new TLine(DiTauEtadenom->GetXaxis()->GetXmin(), 1, DiTauEtadenom->GetXaxis()->GetXmax(), 1);
  TLine *DiTauPhiRatioUnity = new TLine(DiTauPhidenom->GetXaxis()->GetXmin(), 1, DiTauPhidenom->GetXaxis()->GetXmax(), 1);
  TLine *DiMuEtaRatioUnity = new TLine(DiMuEtadenom->GetXaxis()->GetXmin(), 1, DiMuEtadenom->GetXaxis()->GetXmax(), 1);
  TLine *DiMudRRatioUnity = new TLine(DiMudRdenom->GetXaxis()->GetXmin(), 1, DiMudRdenom->GetXaxis()->GetXmax(), 1);
  TLine *DiMuPhiRatioUnity = new TLine(DiMuPhidenom->GetXaxis()->GetXmin(), 1, DiMuPhidenom->GetXaxis()->GetXmax(), 1);
  TLine *EtMETRatioUnity = new TLine(EtMETdenom->GetXaxis()->GetXmin(), 1, EtMETdenom->GetXaxis()->GetXmax(), 1);
  TLine *DiTauDiMuMassRatioUnity = new TLine(DiTauDiMuMassdenom->GetXaxis()->GetXmin(), 1, DiTauDiMuMassdenom->GetXaxis()->GetXmax(), 1);
  TLine *DiMuDiTauDeltaPhiRatioUnity = new TLine(DiMuDiTauDeltaPhidenom->GetXaxis()->GetXmin(), 1, DiMuDiTauDeltaPhidenom->GetXaxis()->GetXmax(), 1);
  TLine *METDiTauDeltaPhiRatioUnity = new TLine(METDiTauDeltaPhidenom->GetXaxis()->GetXmin(), 1, METDiTauDeltaPhidenom->GetXaxis()->GetXmax(), 1);
  TLine *METDiMuDeltaPhiRatioUnity = new TLine(METDiMuDeltaPhidenom->GetXaxis()->GetXmin(), 1, METDiMuDeltaPhidenom->GetXaxis()->GetXmax(), 1);
  TLine *DiTaudRRatioUnity = new TLine(DiTaudRdenom->GetXaxis()->GetXmin(), 1, DiTaudRdenom->GetXaxis()->GetXmax(), 1);
  TLine *DiTauMassSmallerdRRatioUnity = new TLine(DiTauMassSmallerdRdenom->GetXaxis()->GetXmin(), 1, DiTauMassSmallerdRdenom->GetXaxis()->GetXmax(), 1);
  TLine *HighestCSVInclJetRatioUnity = new TLine(HighestCSVInclJetdenom->GetXaxis()->GetXmin(), 1, HighestCSVInclJetdenom->GetXaxis()->GetXmax(), 1);

  NMedIsoTausWithMu3RatioUnity->SetLineStyle(2);
  InvMassTauHadMu3RatioUnity->SetLineStyle(2);
  PtTauHadMu3RatioUnity->SetLineStyle(2);
  InvMassUpsilonRangeRatioUnity->SetLineStyle(2);
  InvMassZPeakRangeRatioUnity->SetLineStyle(2);
  InvMassFullRangeRatioUnity->SetLineStyle(2);
  InvMassDiMuBarrBarrRatioUnity->SetLineStyle(2);
  InvMassDiMuBarrEndcRatioUnity->SetLineStyle(2);
  InvMassDiMuEndcEndcRatioUnity->SetLineStyle(2);
  Mu1PtRatioUnity->SetLineStyle(2);
  Mu2PtRatioUnity->SetLineStyle(2);
  DiMuPtRatioUnity->SetLineStyle(2);
  Mu1EtaRatioUnity->SetLineStyle(2);
  Mu2EtaRatioUnity->SetLineStyle(2);
  DiTauEtaRatioUnity->SetLineStyle(2);
  DiTauPhiRatioUnity->SetLineStyle(2);
  DiMuEtaRatioUnity->SetLineStyle(2);
  DiMudRRatioUnity->SetLineStyle(2);
  DiMuPhiRatioUnity->SetLineStyle(2);
  EtMETRatioUnity->SetLineStyle(2);
  DiTauDiMuMassRatioUnity->SetLineStyle(2);
  DiMuDiTauDeltaPhiRatioUnity->SetLineStyle(2);
  METDiTauDeltaPhiRatioUnity->SetLineStyle(2);
  METDiMuDeltaPhiRatioUnity->SetLineStyle(2);
  DiTaudRRatioUnity->SetLineStyle(2);
  DiTauMassSmallerdRRatioUnity->SetLineStyle(2);
  HighestCSVInclJetRatioUnity->SetLineStyle(2);

  //Ratio for Data
  NMedIsoTausWithMu3DataRatio = (TH1F*)NMedIsoTausWithMu3Data_->Clone("ratio_NMedIsoTausWithMu3Data");
  InvMassTauHadMu3DataRatio = (TH1F*)InvMassTauHadMu3Data_->Clone("ratio_InvMassTauHadMu3Data");
  PtTauHadMu3DataRatio = (TH1F*)PtTauHadMu3Data_->Clone("ratio_PtTauHadMu3Data");
  InvMassUpsilonRangeDataRatio = (TH1F*)InvMassUpsilonRangeData_->Clone("ratio_InvMassUpsilonRangeData");
  InvMassZPeakRangeDataRatio = (TH1F*)InvMassZPeakRangeData_->Clone("ratio_InvMassZPeakRangeData");
  InvMassFullRangeDataRatio = (TH1F*)InvMassFullRangeData_->Clone("ratio_InvMassFullRangeData");
  InvMassDiMuBarrBarrDataRatio = (TH1F*)InvMassDiMuBarrBarrData_->Clone("ratio_InvMassDiMuBarrBarrData");
  InvMassDiMuBarrEndcDataRatio = (TH1F*)InvMassDiMuBarrEndcData_->Clone("ratio_InvMassDiMuBarrEndcData");
  InvMassDiMuEndcEndcDataRatio = (TH1F*)InvMassDiMuEndcEndcData_->Clone("ratio_InvMassDiMuEndcEndcData");
  Mu1PtDataRatio = (TH1F*)Mu1PtData_->Clone("ratio_Mu1PtData");
  Mu2PtDataRatio = (TH1F*)Mu2PtData_->Clone("ratio_Mu2PtData");
  DiMuPtDataRatio = (TH1F*)DiMuPtData_->Clone("ratio_DiMuPtData");
  Mu1EtaDataRatio = (TH1F*)Mu1EtaData_->Clone("ratio_Mu1EtaData");
  Mu2EtaDataRatio = (TH1F*)Mu2EtaData_->Clone("ratio_Mu2EtaData");
  DiTauEtaDataRatio = (TH1F*)DiTauEtaData_->Clone("ratio_DiTauEtaData");
  DiTauPhiDataRatio = (TH1F*)DiTauPhiData_->Clone("ratio_DiTauPhiData");
  DiMuEtaDataRatio = (TH1F*)DiMuEtaData_->Clone("ratio_DiMuEtaData");
  DiMudRDataRatio = (TH1F*)DiMudRData_->Clone("ratio_DiMudRData");
  DiMuPhiDataRatio = (TH1F*)DiMuPhiData_->Clone("ratio_DiMuPhiData");
  EtMETDataRatio = (TH1F*)EtMETData_->Clone("ratio_EtMETData");
  DiTauDiMuMassDataRatio = (TH1F*)DiTauDiMuMassData_->Clone("ratio_DiTauDiMuMassData");
  DiMuDiTauDeltaPhiDataRatio = (TH1F*)DiMuDiTauDeltaPhiData_->Clone("ratio_DiMuDiTauDeltaPhiData");
  METDiTauDeltaPhiDataRatio = (TH1F*)METDiTauDeltaPhiData_->Clone("ratio_METDiTauDeltaPhiData");
  METDiMuDeltaPhiDataRatio = (TH1F*)METDiMuDeltaPhiData_->Clone("ratio_METDiMuDeltaPhiData");
  DiTaudRDataRatio = (TH1F*)DiTaudRData_->Clone("ratio_DiTaudRData");
  DiTauMassSmallerdRDataRatio = (TH1F*)DiTauMassSmallerdRData_->Clone("ratio_DiTauMassSmallerdRData");
  HighestCSVInclJetDataRatio = (TH1F*)HighestCSVInclJetData_->Clone("ratio_HighestCSVInclJetData");

  double val, err, nVal, nErr, dVal;
  for (unsigned int i=0; i <   NMedIsoTausWithMu3Data_->GetNbinsX(); i++)
  {
    nVal =   NMedIsoTausWithMu3Data_->GetBinContent(i+1);
    nErr =   NMedIsoTausWithMu3Data_->GetBinError(i+1);
    dVal =   NMedIsoTausWithMu3denom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    NMedIsoTausWithMu3DataRatio->SetBinContent(i+1, val);
    NMedIsoTausWithMu3DataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   InvMassTauHadMu3Data_->GetNbinsX(); i++)
  {
    nVal =   InvMassTauHadMu3Data_->GetBinContent(i+1);
    nErr =   InvMassTauHadMu3Data_->GetBinError(i+1);
    dVal =   InvMassTauHadMu3denom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    InvMassTauHadMu3DataRatio->SetBinContent(i+1, val);
    InvMassTauHadMu3DataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   PtTauHadMu3Data_->GetNbinsX(); i++)
  {
    nVal =   PtTauHadMu3Data_->GetBinContent(i+1);
    nErr =   PtTauHadMu3Data_->GetBinError(i+1);
    dVal =   PtTauHadMu3denom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    PtTauHadMu3DataRatio->SetBinContent(i+1, val);
    PtTauHadMu3DataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   InvMassUpsilonRangeData_->GetNbinsX(); i++)
  {
    nVal =   InvMassUpsilonRangeData_->GetBinContent(i+1);
    nErr =   InvMassUpsilonRangeData_->GetBinError(i+1);
    dVal =   InvMassUpsilonRangedenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    InvMassUpsilonRangeDataRatio->SetBinContent(i+1, val);
    InvMassUpsilonRangeDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   InvMassZPeakRangeData_->GetNbinsX(); i++)
  {
    nVal =   InvMassZPeakRangeData_->GetBinContent(i+1);
    nErr =   InvMassZPeakRangeData_->GetBinError(i+1);
    dVal =   InvMassZPeakRangedenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    InvMassZPeakRangeDataRatio->SetBinContent(i+1, val);
    InvMassZPeakRangeDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   InvMassFullRangeData_->GetNbinsX(); i++)
  {
    nVal =   InvMassFullRangeData_->GetBinContent(i+1);
    nErr =   InvMassFullRangeData_->GetBinError(i+1);
    dVal =   InvMassFullRangedenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    InvMassFullRangeDataRatio->SetBinContent(i+1, val);
    InvMassFullRangeDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   InvMassDiMuBarrBarrData_->GetNbinsX(); i++)
  {
    nVal =   InvMassDiMuBarrBarrData_->GetBinContent(i+1);
    nErr =   InvMassDiMuBarrBarrData_->GetBinError(i+1);
    dVal =   InvMassDiMuBarrBarrdenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    InvMassDiMuBarrBarrDataRatio->SetBinContent(i+1, val);
    InvMassDiMuBarrBarrDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   InvMassDiMuBarrEndcData_->GetNbinsX(); i++)
  {
    nVal =   InvMassDiMuBarrEndcData_->GetBinContent(i+1);
    nErr =   InvMassDiMuBarrEndcData_->GetBinError(i+1);
    dVal =   InvMassDiMuBarrEndcdenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    InvMassDiMuBarrEndcDataRatio->SetBinContent(i+1, val);
    InvMassDiMuBarrEndcDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   InvMassDiMuEndcEndcData_->GetNbinsX(); i++)
  {
    nVal =   InvMassDiMuEndcEndcData_->GetBinContent(i+1);
    nErr =   InvMassDiMuEndcEndcData_->GetBinError(i+1);
    dVal =   InvMassDiMuEndcEndcdenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    InvMassDiMuEndcEndcDataRatio->SetBinContent(i+1, val);
    InvMassDiMuEndcEndcDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   Mu1PtData_->GetNbinsX(); i++)
  {
    nVal =   Mu1PtData_->GetBinContent(i+1);
    nErr =   Mu1PtData_->GetBinError(i+1);
    dVal =   Mu1Ptdenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    Mu1PtDataRatio->SetBinContent(i+1, val);
    Mu1PtDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   Mu2PtData_->GetNbinsX(); i++)
  {
    nVal =   Mu2PtData_->GetBinContent(i+1);
    nErr =   Mu2PtData_->GetBinError(i+1);
    dVal =   Mu2Ptdenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    Mu2PtDataRatio->SetBinContent(i+1, val);
    Mu2PtDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   DiMuPtData_->GetNbinsX(); i++)
  {
    nVal =   DiMuPtData_->GetBinContent(i+1);
    nErr =   DiMuPtData_->GetBinError(i+1);
    dVal =   DiMuPtdenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    DiMuPtDataRatio->SetBinContent(i+1, val);
    DiMuPtDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   Mu1EtaData_->GetNbinsX(); i++)
  {
    nVal =   Mu1EtaData_->GetBinContent(i+1);
    nErr =   Mu1EtaData_->GetBinError(i+1);
    dVal =   Mu1Etadenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    Mu1EtaDataRatio->SetBinContent(i+1, val);
    Mu1EtaDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   Mu2EtaData_->GetNbinsX(); i++)
  {
    nVal =   Mu2EtaData_->GetBinContent(i+1);
    nErr =   Mu2EtaData_->GetBinError(i+1);
    dVal =   Mu2Etadenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    Mu2EtaDataRatio->SetBinContent(i+1, val);
    Mu2EtaDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   DiTauEtaData_->GetNbinsX(); i++)
  {
    nVal =   DiTauEtaData_->GetBinContent(i+1);
    nErr =   DiTauEtaData_->GetBinError(i+1);
    dVal =   DiTauEtadenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    DiTauEtaDataRatio->SetBinContent(i+1, val);
    DiTauEtaDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   DiTauPhiData_->GetNbinsX(); i++)
  {
    nVal =   DiTauPhiData_->GetBinContent(i+1);
    nErr =   DiTauPhiData_->GetBinError(i+1);
    dVal =   DiTauPhidenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    DiTauPhiDataRatio->SetBinContent(i+1, val);
    DiTauPhiDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   DiMuEtaData_->GetNbinsX(); i++)
  {
    nVal =   DiMuEtaData_->GetBinContent(i+1);
    nErr =   DiMuEtaData_->GetBinError(i+1);
    dVal =   DiMuEtadenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    DiMuEtaDataRatio->SetBinContent(i+1, val);
    DiMuEtaDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   DiMudRData_->GetNbinsX(); i++)
  {
    nVal =   DiMudRData_->GetBinContent(i+1);
    nErr =   DiMudRData_->GetBinError(i+1);
    dVal =   DiMudRdenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    DiMudRDataRatio->SetBinContent(i+1, val);
    DiMudRDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   DiMuPhiData_->GetNbinsX(); i++)
  {
    nVal =   DiMuPhiData_->GetBinContent(i+1);
    nErr =   DiMuPhiData_->GetBinError(i+1);
    dVal =   DiMuPhidenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    DiMuPhiDataRatio->SetBinContent(i+1, val);
    DiMuPhiDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   EtMETData_->GetNbinsX(); i++)
  {
    nVal =   EtMETData_->GetBinContent(i+1);
    nErr =   EtMETData_->GetBinError(i+1);
    dVal =   EtMETdenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    EtMETDataRatio->SetBinContent(i+1, val);
    EtMETDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   DiTauDiMuMassData_->GetNbinsX(); i++)
  {
    nVal =   DiTauDiMuMassData_->GetBinContent(i+1);
    nErr =   DiTauDiMuMassData_->GetBinError(i+1);
    dVal =   DiTauDiMuMassdenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    DiTauDiMuMassDataRatio->SetBinContent(i+1, val);
    DiTauDiMuMassDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   DiMuDiTauDeltaPhiData_->GetNbinsX(); i++)
  {
    nVal =   DiMuDiTauDeltaPhiData_->GetBinContent(i+1);
    nErr =   DiMuDiTauDeltaPhiData_->GetBinError(i+1);
    dVal =   DiMuDiTauDeltaPhidenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    DiMuDiTauDeltaPhiDataRatio->SetBinContent(i+1, val);
    DiMuDiTauDeltaPhiDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   METDiTauDeltaPhiData_->GetNbinsX(); i++)
  {
    nVal =   METDiTauDeltaPhiData_->GetBinContent(i+1);
    nErr =   METDiTauDeltaPhiData_->GetBinError(i+1);
    dVal =   METDiTauDeltaPhidenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    METDiTauDeltaPhiDataRatio->SetBinContent(i+1, val);
    METDiTauDeltaPhiDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   METDiMuDeltaPhiData_->GetNbinsX(); i++)
  {
    nVal =   METDiMuDeltaPhiData_->GetBinContent(i+1);
    nErr =   METDiMuDeltaPhiData_->GetBinError(i+1);
    dVal =   METDiMuDeltaPhidenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    METDiMuDeltaPhiDataRatio->SetBinContent(i+1, val);
    METDiMuDeltaPhiDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   DiTaudRData_->GetNbinsX(); i++)
  {
    nVal =   DiTaudRData_->GetBinContent(i+1);
    nErr =   DiTaudRData_->GetBinError(i+1);
    dVal =   DiTaudRdenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    DiTaudRDataRatio->SetBinContent(i+1, val);
    DiTaudRDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   DiTauMassSmallerdRData_->GetNbinsX(); i++)
  {
    nVal =   DiTauMassSmallerdRData_->GetBinContent(i+1);
    nErr =   DiTauMassSmallerdRData_->GetBinError(i+1);
    dVal =   DiTauMassSmallerdRdenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    DiTauMassSmallerdRDataRatio->SetBinContent(i+1, val);
    DiTauMassSmallerdRDataRatio->SetBinError(i+1, err);
  }//for

  for (unsigned int i=0; i <   HighestCSVInclJetData_->GetNbinsX(); i++)
  {
    nVal =   HighestCSVInclJetData_->GetBinContent(i+1);
    nErr =   HighestCSVInclJetData_->GetBinError(i+1);
    dVal =   HighestCSVInclJetdenom->GetBinContent(i+1);
    if (dVal > .00001)
    {
      val = nVal/dVal;
      err = nErr/dVal;
    }//if
    else
    {
      val = 0;
      err = 0;
    }//err
    HighestCSVInclJetDataRatio->SetBinContent(i+1, val);
    HighestCSVInclJetDataRatio->SetBinError(i+1, err);
  }//for

cout << "Got Data to MC ratio" << endl;

  outFile->cd();
  NMedIsoTausWithMu3RatioPad->cd();
  NMedIsoTausWithMu3RatioStatError->Draw("e2");
  NMedIsoTausWithMu3RatioUnity->Draw("same");
  NMedIsoTausWithMu3DataRatio->Draw("0P same");
  NMedIsoTausWithMu3Canvas->Draw();
  NMedIsoTausWithMu3Canvas->Write();

  InvMassTauHadMu3RatioPad->cd();
  InvMassTauHadMu3RatioStatError->Draw("e2");
  InvMassTauHadMu3RatioUnity->Draw("same");
  InvMassTauHadMu3DataRatio->Draw("0P same");
  InvMassTauHadMu3Canvas->Draw();
  InvMassTauHadMu3Canvas->Write();

  PtTauHadMu3RatioPad->cd();
  PtTauHadMu3RatioStatError->Draw("e2");
  PtTauHadMu3RatioUnity->Draw("same");
  PtTauHadMu3DataRatio->Draw("0P same");
  PtTauHadMu3Canvas->Draw();
  PtTauHadMu3Canvas->Write();

  InvMassUpsilonRangeRatioPad->cd();
  InvMassUpsilonRangeRatioStatError->Draw("e2");
  InvMassUpsilonRangeRatioUnity->Draw("same");
  InvMassUpsilonRangeDataRatio->Draw("0P same");
  InvMassUpsilonRangeCanvas->Draw();
  InvMassUpsilonRangeCanvas->Write();

  InvMassZPeakRangeRatioPad->cd();
  InvMassZPeakRangeRatioStatError->Draw("e2");
  InvMassZPeakRangeRatioUnity->Draw("same");
  InvMassZPeakRangeDataRatio->Draw("0P same");
  InvMassZPeakRangeCanvas->Draw();
  InvMassZPeakRangeCanvas->Write();

  InvMassFullRangeRatioPad->cd();
  InvMassFullRangeRatioStatError->Draw("e2");
  InvMassFullRangeRatioUnity->Draw("same");
  InvMassFullRangeDataRatio->Draw("0P same");
  InvMassFullRangeCanvas->Draw();
  InvMassFullRangeCanvas->Write();

  InvMassDiMuBarrBarrRatioPad->cd();
  InvMassDiMuBarrBarrRatioStatError->Draw("e2");
  InvMassDiMuBarrBarrRatioUnity->Draw("same");
  InvMassDiMuBarrBarrDataRatio->Draw("0P same");
  InvMassDiMuBarrBarrCanvas->Draw();
  InvMassDiMuBarrBarrCanvas->Write();

  InvMassDiMuBarrEndcRatioPad->cd();
  InvMassDiMuBarrEndcRatioStatError->Draw("e2");
  InvMassDiMuBarrEndcRatioUnity->Draw("same");
  InvMassDiMuBarrEndcDataRatio->Draw("0P same");
  InvMassDiMuBarrEndcCanvas->Draw();
  InvMassDiMuBarrEndcCanvas->Write();

  InvMassDiMuEndcEndcRatioPad->cd();
  InvMassDiMuEndcEndcRatioStatError->Draw("e2");
  InvMassDiMuEndcEndcRatioUnity->Draw("same");
  InvMassDiMuEndcEndcDataRatio->Draw("0P same");
  InvMassDiMuEndcEndcCanvas->Draw();
  InvMassDiMuEndcEndcCanvas->Write();

  Mu1PtRatioPad->cd();
  Mu1PtRatioStatError->Draw("e2");
  Mu1PtRatioUnity->Draw("same");
  Mu1PtDataRatio->Draw("0P same");
  Mu1PtCanvas->Draw();
  Mu1PtCanvas->Write();

  Mu2PtRatioPad->cd();
  Mu2PtRatioStatError->Draw("e2");
  Mu2PtRatioUnity->Draw("same");
  Mu2PtDataRatio->Draw("0P same");
  Mu2PtCanvas->Draw();
  Mu2PtCanvas->Write();

  DiMuPtRatioPad->cd();
  DiMuPtRatioStatError->Draw("e2");
  DiMuPtRatioUnity->Draw("same");
  DiMuPtDataRatio->Draw("0P same");
  DiMuPtCanvas->Draw();
  DiMuPtCanvas->Write();

  Mu1EtaRatioPad->cd();
  Mu1EtaRatioStatError->Draw("e2");
  Mu1EtaRatioUnity->Draw("same");
  Mu1EtaDataRatio->Draw("0P same");
  Mu1EtaCanvas->Draw();
  Mu1EtaCanvas->Write();

  Mu2EtaRatioPad->cd();
  Mu2EtaRatioStatError->Draw("e2");
  Mu2EtaRatioUnity->Draw("same");
  Mu2EtaDataRatio->Draw("0P same");
  Mu2EtaCanvas->Draw();
  Mu2EtaCanvas->Write();

  DiTauEtaRatioPad->cd();
  DiTauEtaRatioStatError->Draw("e2");
  DiTauEtaRatioUnity->Draw("same");
  DiTauEtaDataRatio->Draw("0P same");
  DiTauEtaCanvas->Draw();
  DiTauEtaCanvas->Write();

  DiTauPhiRatioPad->cd();
  DiTauPhiRatioStatError->Draw("e2");
  DiTauPhiRatioUnity->Draw("same");
  DiTauPhiDataRatio->Draw("0P same");
  DiTauPhiCanvas->Draw();
  DiTauPhiCanvas->Write();

  DiMuEtaRatioPad->cd();
  DiMuEtaRatioStatError->Draw("e2");
  DiMuEtaRatioUnity->Draw("same");
  DiMuEtaDataRatio->Draw("0P same");
  DiMuEtaCanvas->Draw();
  DiMuEtaCanvas->Write();

  DiMudRRatioPad->cd();
  DiMudRRatioStatError->Draw("e2");
  DiMudRRatioUnity->Draw("same");
  DiMudRDataRatio->Draw("0P same");
  DiMudRCanvas->Draw();
  DiMudRCanvas->Write();

  DiMuPhiRatioPad->cd();
  DiMuPhiRatioStatError->Draw("e2");
  DiMuPhiRatioUnity->Draw("same");
  DiMuPhiDataRatio->Draw("0P same");
  DiMuPhiCanvas->Draw();
  DiMuPhiCanvas->Write();

  EtMETRatioPad->cd();
  EtMETRatioStatError->Draw("e2");
  EtMETRatioUnity->Draw("same");
  EtMETDataRatio->Draw("0P same");
  EtMETCanvas->Draw();
  EtMETCanvas->Write();

  DiTauDiMuMassRatioPad->cd();
  DiTauDiMuMassRatioStatError->Draw("e2");
  DiTauDiMuMassRatioUnity->Draw("same");
  DiTauDiMuMassDataRatio->Draw("0P same");
  DiTauDiMuMassCanvas->Draw();
  DiTauDiMuMassCanvas->Write();

  DiMuDiTauDeltaPhiRatioPad->cd();
  DiMuDiTauDeltaPhiRatioStatError->Draw("e2");
  DiMuDiTauDeltaPhiRatioUnity->Draw("same");
  DiMuDiTauDeltaPhiDataRatio->Draw("0P same");
  DiMuDiTauDeltaPhiCanvas->Draw();
  DiMuDiTauDeltaPhiCanvas->Write();

  METDiTauDeltaPhiRatioPad->cd();
  METDiTauDeltaPhiRatioStatError->Draw("e2");
  METDiTauDeltaPhiRatioUnity->Draw("same");
  METDiTauDeltaPhiDataRatio->Draw("0P same");
  METDiTauDeltaPhiCanvas->Draw();
  METDiTauDeltaPhiCanvas->Write();

  METDiMuDeltaPhiRatioPad->cd();
  METDiMuDeltaPhiRatioStatError->Draw("e2");
  METDiMuDeltaPhiRatioUnity->Draw("same");
  METDiMuDeltaPhiDataRatio->Draw("0P same");
  METDiMuDeltaPhiCanvas->Draw();
  METDiMuDeltaPhiCanvas->Write();

  DiTaudRRatioPad->cd();
  DiTaudRRatioStatError->Draw("e2");
  DiTaudRRatioUnity->Draw("same");
  DiTaudRDataRatio->Draw("0P same");
  DiTaudRCanvas->Draw();
  DiTaudRCanvas->Write();

  DiTauMassSmallerdRRatioPad->cd();
  DiTauMassSmallerdRRatioStatError->Draw("e2");
  DiTauMassSmallerdRRatioUnity->Draw("same");
  DiTauMassSmallerdRDataRatio->Draw("0P same");
  DiTauMassSmallerdRCanvas->Draw();
  DiTauMassSmallerdRCanvas->Write();

  HighestCSVInclJetRatioPad->cd();
  HighestCSVInclJetRatioStatError->Draw("e2");
  HighestCSVInclJetRatioUnity->Draw("same");
  HighestCSVInclJetDataRatio->Draw("0P same");
  HighestCSVInclJetCanvas->Draw();
  HighestCSVInclJetCanvas->Write();

  outFile->Write();
  outFile->Close();
cout << "end" << endl;

}//rootMacro_BBA_combine
