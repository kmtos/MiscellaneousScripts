#include <string.h>
#include "TChain.h"
#include "TFile.h"
#include "TH1.h"
#include "TKey.h"
#include "Riostream.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "iostream"
#include "fstream"
#include "TMath.h"
#include "tdrstyle.C"
#include "CMS_lumi.C"

void rootMacro_DiMu_ExtraPlots_SignalOverlyOnly()
{
  setTDRStyle(true);
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);

  //Old DMs
  TFile infileh125a11("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a11_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh125a13("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a13_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh125a15("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a15_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh125a17("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a17_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh125a19("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a19_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh125a21("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a21_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh125a5("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a5_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh125a7("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a7_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh125a9("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a9_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh300a11("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a11_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh300a13("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a13_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh300a15("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a15_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh300a17("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a17_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh300a19("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a19_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh300a21("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a21_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh300a5("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a5_AntiMedIsoMu2_TauDMMedIso_JAN9.root  ");
  TFile infileh300a7("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a7_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh300a9("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a9_AntiMedIsoMu2_TauDMMedIso_JAN9.root  ");
  TFile infileh750a11("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a11_AntiMedIsoMu2_TauDMMedIso_JAN9.root ");
  TFile infileh750a13("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a13_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh750a15("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a15_AntiMedIsoMu2_TauDMMedIso_JAN9.root ");
  TFile infileh750a17("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a17_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh750a19("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a19_AntiMedIsoMu2_TauDMMedIso_JAN9.root  ");
  TFile infileh750a21("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a21_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh750a5("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a5_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh750a7("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a7_AntiMedIsoMu2_TauDMMedIso_JAN9.root");
  TFile infileh750a9("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a9_AntiMedIsoMu2_TauDMMedIso_JAN9.root");




  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/SignalMCOverlay_DiMu_ExtraPlots_AntiMedIsoMu2_TauDMMedIso_JAN9.root", "RECREATE");

cout << "Files Created" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Canvases
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ////////////////
  // h125a11
  ////////////////
  TCanvas *NMedIsoTausWithMu3Canvash125a11 = (TCanvas*)infileh125a11.Get("NMedIsoTausWithMu3");
  TCanvas *InvMassTauHadMu3Canvash125a11 = (TCanvas*)infileh125a11.Get("InvMassTauHadMu3");
  TCanvas *PtTauHadMu3Canvash125a11 = (TCanvas*)infileh125a11.Get("PtTauHadMu3");
  TCanvas *InvMassMu2TauMuCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a11 = (TCanvas*)infileh125a11.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a11 = (TCanvas*)infileh125a11.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a11 = (TCanvas*)infileh125a11.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash125a11 = (TCanvas*)infileh125a11.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a11 = (TCanvas*)infileh125a11.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a11 = (TCanvas*)infileh125a11.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a11 = (TCanvas*)infileh125a11.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash125a11 = (TCanvas*)infileh125a11.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash125a11 = (TCanvas*)infileh125a11.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a11 = (TCanvas*)infileh125a11.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a11 = (TCanvas*)infileh125a11.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a11 = (TCanvas*)infileh125a11.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a13 = (TCanvas*)infileh125a13.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a13 = (TCanvas*)infileh125a13.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a13 = (TCanvas*)infileh125a13.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash125a13 = (TCanvas*)infileh125a13.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a13 = (TCanvas*)infileh125a13.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a13 = (TCanvas*)infileh125a13.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a13 = (TCanvas*)infileh125a13.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash125a13 = (TCanvas*)infileh125a13.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash125a13 = (TCanvas*)infileh125a13.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a13 = (TCanvas*)infileh125a13.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a13 = (TCanvas*)infileh125a13.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a13 = (TCanvas*)infileh125a13.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a15 = (TCanvas*)infileh125a15.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a15 = (TCanvas*)infileh125a15.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a15 = (TCanvas*)infileh125a15.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash125a15 = (TCanvas*)infileh125a15.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a15 = (TCanvas*)infileh125a15.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a15 = (TCanvas*)infileh125a15.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a15 = (TCanvas*)infileh125a15.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash125a15 = (TCanvas*)infileh125a15.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash125a15 = (TCanvas*)infileh125a15.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a15 = (TCanvas*)infileh125a15.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a15 = (TCanvas*)infileh125a15.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a15 = (TCanvas*)infileh125a15.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a17 = (TCanvas*)infileh125a17.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a17 = (TCanvas*)infileh125a17.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a17 = (TCanvas*)infileh125a17.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash125a17 = (TCanvas*)infileh125a17.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a17 = (TCanvas*)infileh125a17.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a17 = (TCanvas*)infileh125a17.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a17 = (TCanvas*)infileh125a17.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash125a17 = (TCanvas*)infileh125a17.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash125a17 = (TCanvas*)infileh125a17.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a17 = (TCanvas*)infileh125a17.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a17 = (TCanvas*)infileh125a17.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a17 = (TCanvas*)infileh125a17.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a19 = (TCanvas*)infileh125a19.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a19 = (TCanvas*)infileh125a19.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a19 = (TCanvas*)infileh125a19.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash125a19 = (TCanvas*)infileh125a19.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a19 = (TCanvas*)infileh125a19.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a19 = (TCanvas*)infileh125a19.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a19 = (TCanvas*)infileh125a19.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash125a19 = (TCanvas*)infileh125a19.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash125a19 = (TCanvas*)infileh125a19.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a19 = (TCanvas*)infileh125a19.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a19 = (TCanvas*)infileh125a19.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a19 = (TCanvas*)infileh125a19.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a21 = (TCanvas*)infileh125a21.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a21 = (TCanvas*)infileh125a21.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a21 = (TCanvas*)infileh125a21.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash125a21 = (TCanvas*)infileh125a21.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a21 = (TCanvas*)infileh125a21.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a21 = (TCanvas*)infileh125a21.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a21 = (TCanvas*)infileh125a21.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash125a21 = (TCanvas*)infileh125a21.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash125a21 = (TCanvas*)infileh125a21.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a21 = (TCanvas*)infileh125a21.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a21 = (TCanvas*)infileh125a21.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a21 = (TCanvas*)infileh125a21.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a5 = (TCanvas*)infileh125a5.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a5 = (TCanvas*)infileh125a5.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a5 = (TCanvas*)infileh125a5.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash125a5 = (TCanvas*)infileh125a5.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a5 = (TCanvas*)infileh125a5.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a5 = (TCanvas*)infileh125a5.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a5 = (TCanvas*)infileh125a5.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash125a5 = (TCanvas*)infileh125a5.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash125a5 = (TCanvas*)infileh125a5.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a5 = (TCanvas*)infileh125a5.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a5 = (TCanvas*)infileh125a5.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a5 = (TCanvas*)infileh125a5.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a7 = (TCanvas*)infileh125a7.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a7 = (TCanvas*)infileh125a7.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a7 = (TCanvas*)infileh125a7.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash125a7 = (TCanvas*)infileh125a7.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a7 = (TCanvas*)infileh125a7.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a7 = (TCanvas*)infileh125a7.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a7 = (TCanvas*)infileh125a7.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash125a7 = (TCanvas*)infileh125a7.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash125a7 = (TCanvas*)infileh125a7.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a7 = (TCanvas*)infileh125a7.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a7 = (TCanvas*)infileh125a7.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a7 = (TCanvas*)infileh125a7.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash125a9 = (TCanvas*)infileh125a9.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash125a9 = (TCanvas*)infileh125a9.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash125a9 = (TCanvas*)infileh125a9.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash125a9 = (TCanvas*)infileh125a9.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash125a9 = (TCanvas*)infileh125a9.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash125a9 = (TCanvas*)infileh125a9.Get("DiMuEta");
  TCanvas *DiMudRCanvash125a9 = (TCanvas*)infileh125a9.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash125a9 = (TCanvas*)infileh125a9.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash125a9 = (TCanvas*)infileh125a9.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash125a9 = (TCanvas*)infileh125a9.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash125a9 = (TCanvas*)infileh125a9.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash125a9 = (TCanvas*)infileh125a9.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a11 = (TCanvas*)infileh300a11.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a11 = (TCanvas*)infileh300a11.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a11 = (TCanvas*)infileh300a11.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash300a11 = (TCanvas*)infileh300a11.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a11 = (TCanvas*)infileh300a11.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a11 = (TCanvas*)infileh300a11.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a11 = (TCanvas*)infileh300a11.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash300a11 = (TCanvas*)infileh300a11.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash300a11 = (TCanvas*)infileh300a11.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a11 = (TCanvas*)infileh300a11.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a11 = (TCanvas*)infileh300a11.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a11 = (TCanvas*)infileh300a11.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a13 = (TCanvas*)infileh300a13.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a13 = (TCanvas*)infileh300a13.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a13 = (TCanvas*)infileh300a13.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash300a13 = (TCanvas*)infileh300a13.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a13 = (TCanvas*)infileh300a13.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a13 = (TCanvas*)infileh300a13.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a13 = (TCanvas*)infileh300a13.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash300a13 = (TCanvas*)infileh300a13.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash300a13 = (TCanvas*)infileh300a13.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a13 = (TCanvas*)infileh300a13.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a13 = (TCanvas*)infileh300a13.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a13 = (TCanvas*)infileh300a13.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a15 = (TCanvas*)infileh300a15.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a15 = (TCanvas*)infileh300a15.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a15 = (TCanvas*)infileh300a15.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash300a15 = (TCanvas*)infileh300a15.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a15 = (TCanvas*)infileh300a15.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a15 = (TCanvas*)infileh300a15.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a15 = (TCanvas*)infileh300a15.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash300a15 = (TCanvas*)infileh300a15.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash300a15 = (TCanvas*)infileh300a15.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a15 = (TCanvas*)infileh300a15.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a15 = (TCanvas*)infileh300a15.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a15 = (TCanvas*)infileh300a15.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a17 = (TCanvas*)infileh300a17.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a17 = (TCanvas*)infileh300a17.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a17 = (TCanvas*)infileh300a17.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash300a17 = (TCanvas*)infileh300a17.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a17 = (TCanvas*)infileh300a17.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a17 = (TCanvas*)infileh300a17.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a17 = (TCanvas*)infileh300a17.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash300a17 = (TCanvas*)infileh300a17.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash300a17 = (TCanvas*)infileh300a17.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a17 = (TCanvas*)infileh300a17.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a17 = (TCanvas*)infileh300a17.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a17 = (TCanvas*)infileh300a17.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a19 = (TCanvas*)infileh300a19.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a19 = (TCanvas*)infileh300a19.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a19 = (TCanvas*)infileh300a19.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash300a19 = (TCanvas*)infileh300a19.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a19 = (TCanvas*)infileh300a19.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a19 = (TCanvas*)infileh300a19.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a19 = (TCanvas*)infileh300a19.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash300a19 = (TCanvas*)infileh300a19.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash300a19 = (TCanvas*)infileh300a19.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a19 = (TCanvas*)infileh300a19.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a19 = (TCanvas*)infileh300a19.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a19 = (TCanvas*)infileh300a19.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a21 = (TCanvas*)infileh300a21.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a21 = (TCanvas*)infileh300a21.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a21 = (TCanvas*)infileh300a21.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash300a21 = (TCanvas*)infileh300a21.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a21 = (TCanvas*)infileh300a21.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a21 = (TCanvas*)infileh300a21.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a21 = (TCanvas*)infileh300a21.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash300a21 = (TCanvas*)infileh300a21.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash300a21 = (TCanvas*)infileh300a21.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a21 = (TCanvas*)infileh300a21.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a21 = (TCanvas*)infileh300a21.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a21 = (TCanvas*)infileh300a21.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a5 = (TCanvas*)infileh300a5.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a5 = (TCanvas*)infileh300a5.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a5 = (TCanvas*)infileh300a5.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash300a5 = (TCanvas*)infileh300a5.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a5 = (TCanvas*)infileh300a5.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a5 = (TCanvas*)infileh300a5.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a5 = (TCanvas*)infileh300a5.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash300a5 = (TCanvas*)infileh300a5.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash300a5 = (TCanvas*)infileh300a5.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a5 = (TCanvas*)infileh300a5.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a5 = (TCanvas*)infileh300a5.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a5 = (TCanvas*)infileh300a5.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a7 = (TCanvas*)infileh300a7.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a7 = (TCanvas*)infileh300a7.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a7 = (TCanvas*)infileh300a7.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash300a7 = (TCanvas*)infileh300a7.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a7 = (TCanvas*)infileh300a7.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a7 = (TCanvas*)infileh300a7.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a7 = (TCanvas*)infileh300a7.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash300a7 = (TCanvas*)infileh300a7.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash300a7 = (TCanvas*)infileh300a7.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a7 = (TCanvas*)infileh300a7.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a7 = (TCanvas*)infileh300a7.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a7 = (TCanvas*)infileh300a7.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash300a9 = (TCanvas*)infileh300a9.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash300a9 = (TCanvas*)infileh300a9.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash300a9 = (TCanvas*)infileh300a9.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash300a9 = (TCanvas*)infileh300a9.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash300a9 = (TCanvas*)infileh300a9.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash300a9 = (TCanvas*)infileh300a9.Get("DiMuEta");
  TCanvas *DiMudRCanvash300a9 = (TCanvas*)infileh300a9.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash300a9 = (TCanvas*)infileh300a9.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash300a9 = (TCanvas*)infileh300a9.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash300a9 = (TCanvas*)infileh300a9.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash300a9 = (TCanvas*)infileh300a9.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash300a9 = (TCanvas*)infileh300a9.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a11 = (TCanvas*)infileh750a11.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a11 = (TCanvas*)infileh750a11.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a11 = (TCanvas*)infileh750a11.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash750a11 = (TCanvas*)infileh750a11.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a11 = (TCanvas*)infileh750a11.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a11 = (TCanvas*)infileh750a11.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a11 = (TCanvas*)infileh750a11.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash750a11 = (TCanvas*)infileh750a11.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash750a11 = (TCanvas*)infileh750a11.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a11 = (TCanvas*)infileh750a11.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a11 = (TCanvas*)infileh750a11.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a11 = (TCanvas*)infileh750a11.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a13 = (TCanvas*)infileh750a13.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a13 = (TCanvas*)infileh750a13.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a13 = (TCanvas*)infileh750a13.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash750a13 = (TCanvas*)infileh750a13.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a13 = (TCanvas*)infileh750a13.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a13 = (TCanvas*)infileh750a13.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a13 = (TCanvas*)infileh750a13.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash750a13 = (TCanvas*)infileh750a13.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash750a13 = (TCanvas*)infileh750a13.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a13 = (TCanvas*)infileh750a13.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a13 = (TCanvas*)infileh750a13.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a13 = (TCanvas*)infileh750a13.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a15 = (TCanvas*)infileh750a15.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a15 = (TCanvas*)infileh750a15.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a15 = (TCanvas*)infileh750a15.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash750a15 = (TCanvas*)infileh750a15.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a15 = (TCanvas*)infileh750a15.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a15 = (TCanvas*)infileh750a15.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a15 = (TCanvas*)infileh750a15.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash750a15 = (TCanvas*)infileh750a15.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash750a15 = (TCanvas*)infileh750a15.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a15 = (TCanvas*)infileh750a15.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a15 = (TCanvas*)infileh750a15.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a15 = (TCanvas*)infileh750a15.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a17 = (TCanvas*)infileh750a17.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a17 = (TCanvas*)infileh750a17.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a17 = (TCanvas*)infileh750a17.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash750a17 = (TCanvas*)infileh750a17.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a17 = (TCanvas*)infileh750a17.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a17 = (TCanvas*)infileh750a17.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a17 = (TCanvas*)infileh750a17.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash750a17 = (TCanvas*)infileh750a17.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash750a17 = (TCanvas*)infileh750a17.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a17 = (TCanvas*)infileh750a17.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a17 = (TCanvas*)infileh750a17.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a17 = (TCanvas*)infileh750a17.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a19 = (TCanvas*)infileh750a19.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a19 = (TCanvas*)infileh750a19.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a19 = (TCanvas*)infileh750a19.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash750a19 = (TCanvas*)infileh750a19.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a19 = (TCanvas*)infileh750a19.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a19 = (TCanvas*)infileh750a19.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a19 = (TCanvas*)infileh750a19.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash750a19 = (TCanvas*)infileh750a19.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash750a19 = (TCanvas*)infileh750a19.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a19 = (TCanvas*)infileh750a19.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a19 = (TCanvas*)infileh750a19.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a19 = (TCanvas*)infileh750a19.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a21 = (TCanvas*)infileh750a21.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a21 = (TCanvas*)infileh750a21.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a21 = (TCanvas*)infileh750a21.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash750a21 = (TCanvas*)infileh750a21.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a21 = (TCanvas*)infileh750a21.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a21 = (TCanvas*)infileh750a21.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a21 = (TCanvas*)infileh750a21.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash750a21 = (TCanvas*)infileh750a21.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash750a21 = (TCanvas*)infileh750a21.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a21 = (TCanvas*)infileh750a21.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a21 = (TCanvas*)infileh750a21.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a21 = (TCanvas*)infileh750a21.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a5 = (TCanvas*)infileh750a5.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a5 = (TCanvas*)infileh750a5.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a5 = (TCanvas*)infileh750a5.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash750a5 = (TCanvas*)infileh750a5.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a5 = (TCanvas*)infileh750a5.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a5 = (TCanvas*)infileh750a5.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a5 = (TCanvas*)infileh750a5.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash750a5 = (TCanvas*)infileh750a5.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash750a5 = (TCanvas*)infileh750a5.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a5 = (TCanvas*)infileh750a5.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a5 = (TCanvas*)infileh750a5.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a5 = (TCanvas*)infileh750a5.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a7 = (TCanvas*)infileh750a7.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a7 = (TCanvas*)infileh750a7.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a7 = (TCanvas*)infileh750a7.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash750a7 = (TCanvas*)infileh750a7.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a7 = (TCanvas*)infileh750a7.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a7 = (TCanvas*)infileh750a7.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a7 = (TCanvas*)infileh750a7.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash750a7 = (TCanvas*)infileh750a7.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash750a7 = (TCanvas*)infileh750a7.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a7 = (TCanvas*)infileh750a7.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a7 = (TCanvas*)infileh750a7.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a7 = (TCanvas*)infileh750a7.Get("METDiTauDeltaPhi");
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
  TCanvas *InvMassMu2TauMuCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassMu2TauMu");
  TCanvas *InvMassMu1TauMuCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassMu1TauMu");
  TCanvas *InvMassFullRangeCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassFullRange");
  TCanvas *InvMassDiMuBarrBarrCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassDiMuBarrBarr");
  TCanvas *InvMassDiMuBarrEndcCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassDiMuBarrEndc");
  TCanvas *InvMassDiMuEndcEndcCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassDiMuEndcEndc");
  TCanvas *Mu1PtCanvash750a9 = (TCanvas*)infileh750a9.Get("Mu1Pt");
  TCanvas *Mu2PtCanvash750a9 = (TCanvas*)infileh750a9.Get("Mu2Pt");
  TCanvas *DiMuPtCanvash750a9 = (TCanvas*)infileh750a9.Get("DiMuPt");
  TCanvas *InvMassDiMuBarrOverCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassDiMuBarrOver");
  TCanvas *InvMassDiMuEndcOverCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassDiMuEndcOver");
  TCanvas *DiTauEtaCanvash750a9 = (TCanvas*)infileh750a9.Get("DiTauEta");
  TCanvas *DiTauPhiCanvash750a9 = (TCanvas*)infileh750a9.Get("DiTauPhi");
  TCanvas *DiMuEtaCanvash750a9 = (TCanvas*)infileh750a9.Get("DiMuEta");
  TCanvas *DiMudRCanvash750a9 = (TCanvas*)infileh750a9.Get("DiMudR");
  TCanvas *InvMassDiMuOverOverCanvash750a9 = (TCanvas*)infileh750a9.Get("InvMassDiMuOverOver");
  TCanvas *EtMETCanvash750a9 = (TCanvas*)infileh750a9.Get("EtMET");
  TCanvas *DiTauDiMuMassCanvash750a9 = (TCanvas*)infileh750a9.Get("DiTauDiMuMass");
  TCanvas *DiMuDiTauDeltaPhiCanvash750a9 = (TCanvas*)infileh750a9.Get("DiMuDiTauDeltaPhi");
  TCanvas *METDiTauDeltaPhiCanvash750a9 = (TCanvas*)infileh750a9.Get("METDiTauDeltaPhi");
  TCanvas *METDiMuDeltaPhiCanvash750a9 = (TCanvas*)infileh750a9.Get("METDiMuDeltaPhi");
  TCanvas *DiTaudRCanvash750a9 = (TCanvas*)infileh750a9.Get("DiTaudR");
  TCanvas *DiTauMassSmallerdRCanvash750a9 = (TCanvas*)infileh750a9.Get("DiTauMassSmallerdR");
  TCanvas *HighestCSVInclJetCanvash750a9 = (TCanvas*)infileh750a9.Get("HighestCSVInclJet");

cout << "Got Canvases" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Histograms fromm the Canvases
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ////////////////
  // h125a11
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a11_ = (TH1F*)NMedIsoTausWithMu3Canvash125a11->GetPrimitive("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a11_ = (TH1F*)InvMassTauHadMu3Canvash125a11->GetPrimitive("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a11_ = (TH1F*)PtTauHadMu3Canvash125a11->GetPrimitive("PtTauHadMu3");
  TH1F *InvMassMu2TauMuh125a11_ = (TH1F*)InvMassMu2TauMuCanvash125a11->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh125a11_ = (TH1F*)InvMassMu1TauMuCanvash125a11->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh125a11_ = (TH1F*)InvMassFullRangeCanvash125a11->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a11_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a11->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a11_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a11->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a11_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a11->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a11_ = (TH1F*)Mu1PtCanvash125a11->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a11_ = (TH1F*)Mu2PtCanvash125a11->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a11_ = (TH1F*)DiMuPtCanvash125a11->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh125a11_ = (TH1F*)InvMassDiMuBarrOverCanvash125a11->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh125a11_ = (TH1F*)InvMassDiMuEndcOverCanvash125a11->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah125a11_ = (TH1F*)DiTauEtaCanvash125a11->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a11_ = (TH1F*)DiTauPhiCanvash125a11->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a11_ = (TH1F*)DiMuEtaCanvash125a11->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a11_ = (TH1F*)DiMudRCanvash125a11->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh125a11_ = (TH1F*)InvMassDiMuOverOverCanvash125a11->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh125a11_ = (TH1F*)EtMETCanvash125a11->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a11_ = (TH1F*)DiTauDiMuMassCanvash125a11->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a11_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a11->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a11_ = (TH1F*)METDiTauDeltaPhiCanvash125a11->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh125a13_ = (TH1F*)InvMassMu2TauMuCanvash125a13->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh125a13_ = (TH1F*)InvMassMu1TauMuCanvash125a13->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh125a13_ = (TH1F*)InvMassFullRangeCanvash125a13->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a13_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a13->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a13_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a13->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a13_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a13->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a13_ = (TH1F*)Mu1PtCanvash125a13->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a13_ = (TH1F*)Mu2PtCanvash125a13->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a13_ = (TH1F*)DiMuPtCanvash125a13->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh125a13_ = (TH1F*)InvMassDiMuBarrOverCanvash125a13->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh125a13_ = (TH1F*)InvMassDiMuEndcOverCanvash125a13->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah125a13_ = (TH1F*)DiTauEtaCanvash125a13->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a13_ = (TH1F*)DiTauPhiCanvash125a13->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a13_ = (TH1F*)DiMuEtaCanvash125a13->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a13_ = (TH1F*)DiMudRCanvash125a13->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh125a13_ = (TH1F*)InvMassDiMuOverOverCanvash125a13->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh125a13_ = (TH1F*)EtMETCanvash125a13->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a13_ = (TH1F*)DiTauDiMuMassCanvash125a13->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a13_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a13->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a13_ = (TH1F*)METDiTauDeltaPhiCanvash125a13->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh125a15_ = (TH1F*)InvMassMu2TauMuCanvash125a15->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh125a15_ = (TH1F*)InvMassMu1TauMuCanvash125a15->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh125a15_ = (TH1F*)InvMassFullRangeCanvash125a15->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a15_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a15->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a15_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a15->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a15_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a15->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a15_ = (TH1F*)Mu1PtCanvash125a15->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a15_ = (TH1F*)Mu2PtCanvash125a15->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a15_ = (TH1F*)DiMuPtCanvash125a15->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh125a15_ = (TH1F*)InvMassDiMuBarrOverCanvash125a15->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh125a15_ = (TH1F*)InvMassDiMuEndcOverCanvash125a15->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah125a15_ = (TH1F*)DiTauEtaCanvash125a15->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a15_ = (TH1F*)DiTauPhiCanvash125a15->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a15_ = (TH1F*)DiMuEtaCanvash125a15->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a15_ = (TH1F*)DiMudRCanvash125a15->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh125a15_ = (TH1F*)InvMassDiMuOverOverCanvash125a15->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh125a15_ = (TH1F*)EtMETCanvash125a15->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a15_ = (TH1F*)DiTauDiMuMassCanvash125a15->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a15_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a15->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a15_ = (TH1F*)METDiTauDeltaPhiCanvash125a15->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh125a17_ = (TH1F*)InvMassMu2TauMuCanvash125a17->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh125a17_ = (TH1F*)InvMassMu1TauMuCanvash125a17->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh125a17_ = (TH1F*)InvMassFullRangeCanvash125a17->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a17_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a17->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a17_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a17->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a17_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a17->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a17_ = (TH1F*)Mu1PtCanvash125a17->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a17_ = (TH1F*)Mu2PtCanvash125a17->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a17_ = (TH1F*)DiMuPtCanvash125a17->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh125a17_ = (TH1F*)InvMassDiMuBarrOverCanvash125a17->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh125a17_ = (TH1F*)InvMassDiMuEndcOverCanvash125a17->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah125a17_ = (TH1F*)DiTauEtaCanvash125a17->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a17_ = (TH1F*)DiTauPhiCanvash125a17->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a17_ = (TH1F*)DiMuEtaCanvash125a17->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a17_ = (TH1F*)DiMudRCanvash125a17->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh125a17_ = (TH1F*)InvMassDiMuOverOverCanvash125a17->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh125a17_ = (TH1F*)EtMETCanvash125a17->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a17_ = (TH1F*)DiTauDiMuMassCanvash125a17->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a17_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a17->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a17_ = (TH1F*)METDiTauDeltaPhiCanvash125a17->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh125a19_ = (TH1F*)InvMassMu2TauMuCanvash125a19->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh125a19_ = (TH1F*)InvMassMu1TauMuCanvash125a19->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh125a19_ = (TH1F*)InvMassFullRangeCanvash125a19->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a19_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a19->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a19_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a19->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a19_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a19->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a19_ = (TH1F*)Mu1PtCanvash125a19->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a19_ = (TH1F*)Mu2PtCanvash125a19->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a19_ = (TH1F*)DiMuPtCanvash125a19->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh125a19_ = (TH1F*)InvMassDiMuBarrOverCanvash125a19->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh125a19_ = (TH1F*)InvMassDiMuEndcOverCanvash125a19->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah125a19_ = (TH1F*)DiTauEtaCanvash125a19->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a19_ = (TH1F*)DiTauPhiCanvash125a19->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a19_ = (TH1F*)DiMuEtaCanvash125a19->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a19_ = (TH1F*)DiMudRCanvash125a19->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh125a19_ = (TH1F*)InvMassDiMuOverOverCanvash125a19->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh125a19_ = (TH1F*)EtMETCanvash125a19->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a19_ = (TH1F*)DiTauDiMuMassCanvash125a19->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a19_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a19->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a19_ = (TH1F*)METDiTauDeltaPhiCanvash125a19->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh125a21_ = (TH1F*)InvMassMu2TauMuCanvash125a21->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh125a21_ = (TH1F*)InvMassMu1TauMuCanvash125a21->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh125a21_ = (TH1F*)InvMassFullRangeCanvash125a21->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a21_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a21->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a21_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a21->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a21_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a21->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a21_ = (TH1F*)Mu1PtCanvash125a21->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a21_ = (TH1F*)Mu2PtCanvash125a21->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a21_ = (TH1F*)DiMuPtCanvash125a21->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh125a21_ = (TH1F*)InvMassDiMuBarrOverCanvash125a21->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh125a21_ = (TH1F*)InvMassDiMuEndcOverCanvash125a21->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah125a21_ = (TH1F*)DiTauEtaCanvash125a21->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a21_ = (TH1F*)DiTauPhiCanvash125a21->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a21_ = (TH1F*)DiMuEtaCanvash125a21->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a21_ = (TH1F*)DiMudRCanvash125a21->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh125a21_ = (TH1F*)InvMassDiMuOverOverCanvash125a21->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh125a21_ = (TH1F*)EtMETCanvash125a21->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a21_ = (TH1F*)DiTauDiMuMassCanvash125a21->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a21_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a21->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a21_ = (TH1F*)METDiTauDeltaPhiCanvash125a21->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh125a5_ = (TH1F*)InvMassMu2TauMuCanvash125a5->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh125a5_ = (TH1F*)InvMassMu1TauMuCanvash125a5->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh125a5_ = (TH1F*)InvMassFullRangeCanvash125a5->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a5_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a5->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a5_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a5->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a5_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a5->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a5_ = (TH1F*)Mu1PtCanvash125a5->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a5_ = (TH1F*)Mu2PtCanvash125a5->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a5_ = (TH1F*)DiMuPtCanvash125a5->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh125a5_ = (TH1F*)InvMassDiMuBarrOverCanvash125a5->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh125a5_ = (TH1F*)InvMassDiMuEndcOverCanvash125a5->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah125a5_ = (TH1F*)DiTauEtaCanvash125a5->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a5_ = (TH1F*)DiTauPhiCanvash125a5->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a5_ = (TH1F*)DiMuEtaCanvash125a5->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a5_ = (TH1F*)DiMudRCanvash125a5->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh125a5_ = (TH1F*)InvMassDiMuOverOverCanvash125a5->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh125a5_ = (TH1F*)EtMETCanvash125a5->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a5_ = (TH1F*)DiTauDiMuMassCanvash125a5->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a5_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a5->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a5_ = (TH1F*)METDiTauDeltaPhiCanvash125a5->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh125a7_ = (TH1F*)InvMassMu2TauMuCanvash125a7->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh125a7_ = (TH1F*)InvMassMu1TauMuCanvash125a7->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh125a7_ = (TH1F*)InvMassFullRangeCanvash125a7->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a7_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a7->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a7_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a7->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a7_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a7->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a7_ = (TH1F*)Mu1PtCanvash125a7->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a7_ = (TH1F*)Mu2PtCanvash125a7->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a7_ = (TH1F*)DiMuPtCanvash125a7->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh125a7_ = (TH1F*)InvMassDiMuBarrOverCanvash125a7->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh125a7_ = (TH1F*)InvMassDiMuEndcOverCanvash125a7->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah125a7_ = (TH1F*)DiTauEtaCanvash125a7->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a7_ = (TH1F*)DiTauPhiCanvash125a7->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a7_ = (TH1F*)DiMuEtaCanvash125a7->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a7_ = (TH1F*)DiMudRCanvash125a7->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh125a7_ = (TH1F*)InvMassDiMuOverOverCanvash125a7->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh125a7_ = (TH1F*)EtMETCanvash125a7->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a7_ = (TH1F*)DiTauDiMuMassCanvash125a7->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a7_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a7->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a7_ = (TH1F*)METDiTauDeltaPhiCanvash125a7->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh125a9_ = (TH1F*)InvMassMu2TauMuCanvash125a9->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh125a9_ = (TH1F*)InvMassMu1TauMuCanvash125a9->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh125a9_ = (TH1F*)InvMassFullRangeCanvash125a9->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh125a9_ = (TH1F*)InvMassDiMuBarrBarrCanvash125a9->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a9_ = (TH1F*)InvMassDiMuBarrEndcCanvash125a9->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a9_ = (TH1F*)InvMassDiMuEndcEndcCanvash125a9->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a9_ = (TH1F*)Mu1PtCanvash125a9->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth125a9_ = (TH1F*)Mu2PtCanvash125a9->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth125a9_ = (TH1F*)DiMuPtCanvash125a9->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh125a9_ = (TH1F*)InvMassDiMuBarrOverCanvash125a9->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh125a9_ = (TH1F*)InvMassDiMuEndcOverCanvash125a9->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah125a9_ = (TH1F*)DiTauEtaCanvash125a9->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih125a9_ = (TH1F*)DiTauPhiCanvash125a9->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah125a9_ = (TH1F*)DiMuEtaCanvash125a9->GetPrimitive("DiMuEta");
  TH1F *DiMudRh125a9_ = (TH1F*)DiMudRCanvash125a9->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh125a9_ = (TH1F*)InvMassDiMuOverOverCanvash125a9->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh125a9_ = (TH1F*)EtMETCanvash125a9->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh125a9_ = (TH1F*)DiTauDiMuMassCanvash125a9->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a9_ = (TH1F*)DiMuDiTauDeltaPhiCanvash125a9->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a9_ = (TH1F*)METDiTauDeltaPhiCanvash125a9->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh300a11_ = (TH1F*)InvMassMu2TauMuCanvash300a11->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh300a11_ = (TH1F*)InvMassMu1TauMuCanvash300a11->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh300a11_ = (TH1F*)InvMassFullRangeCanvash300a11->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a11_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a11->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a11_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a11->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a11_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a11->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a11_ = (TH1F*)Mu1PtCanvash300a11->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a11_ = (TH1F*)Mu2PtCanvash300a11->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a11_ = (TH1F*)DiMuPtCanvash300a11->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh300a11_ = (TH1F*)InvMassDiMuBarrOverCanvash300a11->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh300a11_ = (TH1F*)InvMassDiMuEndcOverCanvash300a11->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah300a11_ = (TH1F*)DiTauEtaCanvash300a11->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a11_ = (TH1F*)DiTauPhiCanvash300a11->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a11_ = (TH1F*)DiMuEtaCanvash300a11->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a11_ = (TH1F*)DiMudRCanvash300a11->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh300a11_ = (TH1F*)InvMassDiMuOverOverCanvash300a11->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh300a11_ = (TH1F*)EtMETCanvash300a11->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a11_ = (TH1F*)DiTauDiMuMassCanvash300a11->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a11_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a11->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a11_ = (TH1F*)METDiTauDeltaPhiCanvash300a11->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh300a13_ = (TH1F*)InvMassMu2TauMuCanvash300a13->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh300a13_ = (TH1F*)InvMassMu1TauMuCanvash300a13->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh300a13_ = (TH1F*)InvMassFullRangeCanvash300a13->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a13_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a13->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a13_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a13->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a13_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a13->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a13_ = (TH1F*)Mu1PtCanvash300a13->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a13_ = (TH1F*)Mu2PtCanvash300a13->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a13_ = (TH1F*)DiMuPtCanvash300a13->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh300a13_ = (TH1F*)InvMassDiMuBarrOverCanvash300a13->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh300a13_ = (TH1F*)InvMassDiMuEndcOverCanvash300a13->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah300a13_ = (TH1F*)DiTauEtaCanvash300a13->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a13_ = (TH1F*)DiTauPhiCanvash300a13->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a13_ = (TH1F*)DiMuEtaCanvash300a13->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a13_ = (TH1F*)DiMudRCanvash300a13->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh300a13_ = (TH1F*)InvMassDiMuOverOverCanvash300a13->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh300a13_ = (TH1F*)EtMETCanvash300a13->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a13_ = (TH1F*)DiTauDiMuMassCanvash300a13->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a13_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a13->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a13_ = (TH1F*)METDiTauDeltaPhiCanvash300a13->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh300a15_ = (TH1F*)InvMassMu2TauMuCanvash300a15->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh300a15_ = (TH1F*)InvMassMu1TauMuCanvash300a15->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh300a15_ = (TH1F*)InvMassFullRangeCanvash300a15->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a15_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a15->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a15_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a15->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a15_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a15->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a15_ = (TH1F*)Mu1PtCanvash300a15->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a15_ = (TH1F*)Mu2PtCanvash300a15->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a15_ = (TH1F*)DiMuPtCanvash300a15->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh300a15_ = (TH1F*)InvMassDiMuBarrOverCanvash300a15->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh300a15_ = (TH1F*)InvMassDiMuEndcOverCanvash300a15->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah300a15_ = (TH1F*)DiTauEtaCanvash300a15->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a15_ = (TH1F*)DiTauPhiCanvash300a15->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a15_ = (TH1F*)DiMuEtaCanvash300a15->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a15_ = (TH1F*)DiMudRCanvash300a15->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh300a15_ = (TH1F*)InvMassDiMuOverOverCanvash300a15->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh300a15_ = (TH1F*)EtMETCanvash300a15->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a15_ = (TH1F*)DiTauDiMuMassCanvash300a15->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a15_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a15->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a15_ = (TH1F*)METDiTauDeltaPhiCanvash300a15->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh300a17_ = (TH1F*)InvMassMu2TauMuCanvash300a17->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh300a17_ = (TH1F*)InvMassMu1TauMuCanvash300a17->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh300a17_ = (TH1F*)InvMassFullRangeCanvash300a17->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a17_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a17->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a17_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a17->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a17_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a17->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a17_ = (TH1F*)Mu1PtCanvash300a17->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a17_ = (TH1F*)Mu2PtCanvash300a17->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a17_ = (TH1F*)DiMuPtCanvash300a17->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh300a17_ = (TH1F*)InvMassDiMuBarrOverCanvash300a17->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh300a17_ = (TH1F*)InvMassDiMuEndcOverCanvash300a17->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah300a17_ = (TH1F*)DiTauEtaCanvash300a17->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a17_ = (TH1F*)DiTauPhiCanvash300a17->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a17_ = (TH1F*)DiMuEtaCanvash300a17->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a17_ = (TH1F*)DiMudRCanvash300a17->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh300a17_ = (TH1F*)InvMassDiMuOverOverCanvash300a17->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh300a17_ = (TH1F*)EtMETCanvash300a17->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a17_ = (TH1F*)DiTauDiMuMassCanvash300a17->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a17_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a17->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a17_ = (TH1F*)METDiTauDeltaPhiCanvash300a17->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh300a19_ = (TH1F*)InvMassMu2TauMuCanvash300a19->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh300a19_ = (TH1F*)InvMassMu1TauMuCanvash300a19->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh300a19_ = (TH1F*)InvMassFullRangeCanvash300a19->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a19_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a19->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a19_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a19->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a19_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a19->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a19_ = (TH1F*)Mu1PtCanvash300a19->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a19_ = (TH1F*)Mu2PtCanvash300a19->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a19_ = (TH1F*)DiMuPtCanvash300a19->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh300a19_ = (TH1F*)InvMassDiMuBarrOverCanvash300a19->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh300a19_ = (TH1F*)InvMassDiMuEndcOverCanvash300a19->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah300a19_ = (TH1F*)DiTauEtaCanvash300a19->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a19_ = (TH1F*)DiTauPhiCanvash300a19->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a19_ = (TH1F*)DiMuEtaCanvash300a19->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a19_ = (TH1F*)DiMudRCanvash300a19->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh300a19_ = (TH1F*)InvMassDiMuOverOverCanvash300a19->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh300a19_ = (TH1F*)EtMETCanvash300a19->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a19_ = (TH1F*)DiTauDiMuMassCanvash300a19->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a19_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a19->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a19_ = (TH1F*)METDiTauDeltaPhiCanvash300a19->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh300a21_ = (TH1F*)InvMassMu2TauMuCanvash300a21->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh300a21_ = (TH1F*)InvMassMu1TauMuCanvash300a21->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh300a21_ = (TH1F*)InvMassFullRangeCanvash300a21->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a21_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a21->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a21_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a21->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a21_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a21->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a21_ = (TH1F*)Mu1PtCanvash300a21->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a21_ = (TH1F*)Mu2PtCanvash300a21->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a21_ = (TH1F*)DiMuPtCanvash300a21->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh300a21_ = (TH1F*)InvMassDiMuBarrOverCanvash300a21->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh300a21_ = (TH1F*)InvMassDiMuEndcOverCanvash300a21->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah300a21_ = (TH1F*)DiTauEtaCanvash300a21->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a21_ = (TH1F*)DiTauPhiCanvash300a21->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a21_ = (TH1F*)DiMuEtaCanvash300a21->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a21_ = (TH1F*)DiMudRCanvash300a21->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh300a21_ = (TH1F*)InvMassDiMuOverOverCanvash300a21->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh300a21_ = (TH1F*)EtMETCanvash300a21->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a21_ = (TH1F*)DiTauDiMuMassCanvash300a21->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a21_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a21->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a21_ = (TH1F*)METDiTauDeltaPhiCanvash300a21->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh300a5_ = (TH1F*)InvMassMu2TauMuCanvash300a5->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh300a5_ = (TH1F*)InvMassMu1TauMuCanvash300a5->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh300a5_ = (TH1F*)InvMassFullRangeCanvash300a5->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a5_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a5->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a5_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a5->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a5_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a5->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a5_ = (TH1F*)Mu1PtCanvash300a5->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a5_ = (TH1F*)Mu2PtCanvash300a5->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a5_ = (TH1F*)DiMuPtCanvash300a5->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh300a5_ = (TH1F*)InvMassDiMuBarrOverCanvash300a5->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh300a5_ = (TH1F*)InvMassDiMuEndcOverCanvash300a5->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah300a5_ = (TH1F*)DiTauEtaCanvash300a5->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a5_ = (TH1F*)DiTauPhiCanvash300a5->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a5_ = (TH1F*)DiMuEtaCanvash300a5->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a5_ = (TH1F*)DiMudRCanvash300a5->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh300a5_ = (TH1F*)InvMassDiMuOverOverCanvash300a5->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh300a5_ = (TH1F*)EtMETCanvash300a5->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a5_ = (TH1F*)DiTauDiMuMassCanvash300a5->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a5_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a5->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a5_ = (TH1F*)METDiTauDeltaPhiCanvash300a5->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh300a7_ = (TH1F*)InvMassMu2TauMuCanvash300a7->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh300a7_ = (TH1F*)InvMassMu1TauMuCanvash300a7->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh300a7_ = (TH1F*)InvMassFullRangeCanvash300a7->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a7_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a7->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a7_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a7->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a7_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a7->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a7_ = (TH1F*)Mu1PtCanvash300a7->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a7_ = (TH1F*)Mu2PtCanvash300a7->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a7_ = (TH1F*)DiMuPtCanvash300a7->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh300a7_ = (TH1F*)InvMassDiMuBarrOverCanvash300a7->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh300a7_ = (TH1F*)InvMassDiMuEndcOverCanvash300a7->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah300a7_ = (TH1F*)DiTauEtaCanvash300a7->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a7_ = (TH1F*)DiTauPhiCanvash300a7->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a7_ = (TH1F*)DiMuEtaCanvash300a7->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a7_ = (TH1F*)DiMudRCanvash300a7->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh300a7_ = (TH1F*)InvMassDiMuOverOverCanvash300a7->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh300a7_ = (TH1F*)EtMETCanvash300a7->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a7_ = (TH1F*)DiTauDiMuMassCanvash300a7->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a7_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a7->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a7_ = (TH1F*)METDiTauDeltaPhiCanvash300a7->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh300a9_ = (TH1F*)InvMassMu2TauMuCanvash300a9->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh300a9_ = (TH1F*)InvMassMu1TauMuCanvash300a9->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh300a9_ = (TH1F*)InvMassFullRangeCanvash300a9->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh300a9_ = (TH1F*)InvMassDiMuBarrBarrCanvash300a9->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a9_ = (TH1F*)InvMassDiMuBarrEndcCanvash300a9->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a9_ = (TH1F*)InvMassDiMuEndcEndcCanvash300a9->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a9_ = (TH1F*)Mu1PtCanvash300a9->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth300a9_ = (TH1F*)Mu2PtCanvash300a9->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth300a9_ = (TH1F*)DiMuPtCanvash300a9->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh300a9_ = (TH1F*)InvMassDiMuBarrOverCanvash300a9->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh300a9_ = (TH1F*)InvMassDiMuEndcOverCanvash300a9->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah300a9_ = (TH1F*)DiTauEtaCanvash300a9->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih300a9_ = (TH1F*)DiTauPhiCanvash300a9->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah300a9_ = (TH1F*)DiMuEtaCanvash300a9->GetPrimitive("DiMuEta");
  TH1F *DiMudRh300a9_ = (TH1F*)DiMudRCanvash300a9->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh300a9_ = (TH1F*)InvMassDiMuOverOverCanvash300a9->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh300a9_ = (TH1F*)EtMETCanvash300a9->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh300a9_ = (TH1F*)DiTauDiMuMassCanvash300a9->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a9_ = (TH1F*)DiMuDiTauDeltaPhiCanvash300a9->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a9_ = (TH1F*)METDiTauDeltaPhiCanvash300a9->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh750a11_ = (TH1F*)InvMassMu2TauMuCanvash750a11->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh750a11_ = (TH1F*)InvMassMu1TauMuCanvash750a11->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh750a11_ = (TH1F*)InvMassFullRangeCanvash750a11->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a11_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a11->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a11_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a11->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a11_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a11->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a11_ = (TH1F*)Mu1PtCanvash750a11->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a11_ = (TH1F*)Mu2PtCanvash750a11->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a11_ = (TH1F*)DiMuPtCanvash750a11->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh750a11_ = (TH1F*)InvMassDiMuBarrOverCanvash750a11->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh750a11_ = (TH1F*)InvMassDiMuEndcOverCanvash750a11->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah750a11_ = (TH1F*)DiTauEtaCanvash750a11->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a11_ = (TH1F*)DiTauPhiCanvash750a11->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a11_ = (TH1F*)DiMuEtaCanvash750a11->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a11_ = (TH1F*)DiMudRCanvash750a11->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh750a11_ = (TH1F*)InvMassDiMuOverOverCanvash750a11->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh750a11_ = (TH1F*)EtMETCanvash750a11->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a11_ = (TH1F*)DiTauDiMuMassCanvash750a11->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a11_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a11->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a11_ = (TH1F*)METDiTauDeltaPhiCanvash750a11->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh750a13_ = (TH1F*)InvMassMu2TauMuCanvash750a13->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh750a13_ = (TH1F*)InvMassMu1TauMuCanvash750a13->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh750a13_ = (TH1F*)InvMassFullRangeCanvash750a13->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a13_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a13->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a13_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a13->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a13_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a13->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a13_ = (TH1F*)Mu1PtCanvash750a13->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a13_ = (TH1F*)Mu2PtCanvash750a13->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a13_ = (TH1F*)DiMuPtCanvash750a13->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh750a13_ = (TH1F*)InvMassDiMuBarrOverCanvash750a13->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh750a13_ = (TH1F*)InvMassDiMuEndcOverCanvash750a13->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah750a13_ = (TH1F*)DiTauEtaCanvash750a13->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a13_ = (TH1F*)DiTauPhiCanvash750a13->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a13_ = (TH1F*)DiMuEtaCanvash750a13->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a13_ = (TH1F*)DiMudRCanvash750a13->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh750a13_ = (TH1F*)InvMassDiMuOverOverCanvash750a13->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh750a13_ = (TH1F*)EtMETCanvash750a13->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a13_ = (TH1F*)DiTauDiMuMassCanvash750a13->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a13_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a13->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a13_ = (TH1F*)METDiTauDeltaPhiCanvash750a13->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh750a15_ = (TH1F*)InvMassMu2TauMuCanvash750a15->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh750a15_ = (TH1F*)InvMassMu1TauMuCanvash750a15->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh750a15_ = (TH1F*)InvMassFullRangeCanvash750a15->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a15_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a15->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a15_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a15->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a15_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a15->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a15_ = (TH1F*)Mu1PtCanvash750a15->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a15_ = (TH1F*)Mu2PtCanvash750a15->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a15_ = (TH1F*)DiMuPtCanvash750a15->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh750a15_ = (TH1F*)InvMassDiMuBarrOverCanvash750a15->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh750a15_ = (TH1F*)InvMassDiMuEndcOverCanvash750a15->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah750a15_ = (TH1F*)DiTauEtaCanvash750a15->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a15_ = (TH1F*)DiTauPhiCanvash750a15->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a15_ = (TH1F*)DiMuEtaCanvash750a15->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a15_ = (TH1F*)DiMudRCanvash750a15->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh750a15_ = (TH1F*)InvMassDiMuOverOverCanvash750a15->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh750a15_ = (TH1F*)EtMETCanvash750a15->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a15_ = (TH1F*)DiTauDiMuMassCanvash750a15->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a15_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a15->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a15_ = (TH1F*)METDiTauDeltaPhiCanvash750a15->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh750a17_ = (TH1F*)InvMassMu2TauMuCanvash750a17->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh750a17_ = (TH1F*)InvMassMu1TauMuCanvash750a17->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh750a17_ = (TH1F*)InvMassFullRangeCanvash750a17->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a17_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a17->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a17_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a17->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a17_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a17->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a17_ = (TH1F*)Mu1PtCanvash750a17->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a17_ = (TH1F*)Mu2PtCanvash750a17->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a17_ = (TH1F*)DiMuPtCanvash750a17->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh750a17_ = (TH1F*)InvMassDiMuBarrOverCanvash750a17->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh750a17_ = (TH1F*)InvMassDiMuEndcOverCanvash750a17->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah750a17_ = (TH1F*)DiTauEtaCanvash750a17->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a17_ = (TH1F*)DiTauPhiCanvash750a17->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a17_ = (TH1F*)DiMuEtaCanvash750a17->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a17_ = (TH1F*)DiMudRCanvash750a17->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh750a17_ = (TH1F*)InvMassDiMuOverOverCanvash750a17->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh750a17_ = (TH1F*)EtMETCanvash750a17->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a17_ = (TH1F*)DiTauDiMuMassCanvash750a17->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a17_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a17->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a17_ = (TH1F*)METDiTauDeltaPhiCanvash750a17->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh750a19_ = (TH1F*)InvMassMu2TauMuCanvash750a19->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh750a19_ = (TH1F*)InvMassMu1TauMuCanvash750a19->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh750a19_ = (TH1F*)InvMassFullRangeCanvash750a19->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a19_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a19->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a19_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a19->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a19_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a19->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a19_ = (TH1F*)Mu1PtCanvash750a19->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a19_ = (TH1F*)Mu2PtCanvash750a19->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a19_ = (TH1F*)DiMuPtCanvash750a19->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh750a19_ = (TH1F*)InvMassDiMuBarrOverCanvash750a19->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh750a19_ = (TH1F*)InvMassDiMuEndcOverCanvash750a19->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah750a19_ = (TH1F*)DiTauEtaCanvash750a19->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a19_ = (TH1F*)DiTauPhiCanvash750a19->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a19_ = (TH1F*)DiMuEtaCanvash750a19->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a19_ = (TH1F*)DiMudRCanvash750a19->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh750a19_ = (TH1F*)InvMassDiMuOverOverCanvash750a19->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh750a19_ = (TH1F*)EtMETCanvash750a19->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a19_ = (TH1F*)DiTauDiMuMassCanvash750a19->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a19_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a19->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a19_ = (TH1F*)METDiTauDeltaPhiCanvash750a19->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh750a21_ = (TH1F*)InvMassMu2TauMuCanvash750a21->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh750a21_ = (TH1F*)InvMassMu1TauMuCanvash750a21->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh750a21_ = (TH1F*)InvMassFullRangeCanvash750a21->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a21_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a21->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a21_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a21->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a21_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a21->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a21_ = (TH1F*)Mu1PtCanvash750a21->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a21_ = (TH1F*)Mu2PtCanvash750a21->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a21_ = (TH1F*)DiMuPtCanvash750a21->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh750a21_ = (TH1F*)InvMassDiMuBarrOverCanvash750a21->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh750a21_ = (TH1F*)InvMassDiMuEndcOverCanvash750a21->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah750a21_ = (TH1F*)DiTauEtaCanvash750a21->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a21_ = (TH1F*)DiTauPhiCanvash750a21->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a21_ = (TH1F*)DiMuEtaCanvash750a21->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a21_ = (TH1F*)DiMudRCanvash750a21->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh750a21_ = (TH1F*)InvMassDiMuOverOverCanvash750a21->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh750a21_ = (TH1F*)EtMETCanvash750a21->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a21_ = (TH1F*)DiTauDiMuMassCanvash750a21->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a21_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a21->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a21_ = (TH1F*)METDiTauDeltaPhiCanvash750a21->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh750a5_ = (TH1F*)InvMassMu2TauMuCanvash750a5->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh750a5_ = (TH1F*)InvMassMu1TauMuCanvash750a5->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh750a5_ = (TH1F*)InvMassFullRangeCanvash750a5->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a5_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a5->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a5_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a5->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a5_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a5->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a5_ = (TH1F*)Mu1PtCanvash750a5->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a5_ = (TH1F*)Mu2PtCanvash750a5->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a5_ = (TH1F*)DiMuPtCanvash750a5->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh750a5_ = (TH1F*)InvMassDiMuBarrOverCanvash750a5->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh750a5_ = (TH1F*)InvMassDiMuEndcOverCanvash750a5->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah750a5_ = (TH1F*)DiTauEtaCanvash750a5->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a5_ = (TH1F*)DiTauPhiCanvash750a5->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a5_ = (TH1F*)DiMuEtaCanvash750a5->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a5_ = (TH1F*)DiMudRCanvash750a5->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh750a5_ = (TH1F*)InvMassDiMuOverOverCanvash750a5->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh750a5_ = (TH1F*)EtMETCanvash750a5->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a5_ = (TH1F*)DiTauDiMuMassCanvash750a5->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a5_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a5->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a5_ = (TH1F*)METDiTauDeltaPhiCanvash750a5->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh750a7_ = (TH1F*)InvMassMu2TauMuCanvash750a7->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh750a7_ = (TH1F*)InvMassMu1TauMuCanvash750a7->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh750a7_ = (TH1F*)InvMassFullRangeCanvash750a7->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a7_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a7->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a7_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a7->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a7_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a7->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a7_ = (TH1F*)Mu1PtCanvash750a7->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a7_ = (TH1F*)Mu2PtCanvash750a7->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a7_ = (TH1F*)DiMuPtCanvash750a7->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh750a7_ = (TH1F*)InvMassDiMuBarrOverCanvash750a7->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh750a7_ = (TH1F*)InvMassDiMuEndcOverCanvash750a7->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah750a7_ = (TH1F*)DiTauEtaCanvash750a7->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a7_ = (TH1F*)DiTauPhiCanvash750a7->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a7_ = (TH1F*)DiMuEtaCanvash750a7->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a7_ = (TH1F*)DiMudRCanvash750a7->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh750a7_ = (TH1F*)InvMassDiMuOverOverCanvash750a7->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh750a7_ = (TH1F*)EtMETCanvash750a7->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a7_ = (TH1F*)DiTauDiMuMassCanvash750a7->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a7_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a7->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a7_ = (TH1F*)METDiTauDeltaPhiCanvash750a7->GetPrimitive("METDiTauDeltaPhi");
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
  TH1F *InvMassMu2TauMuh750a9_ = (TH1F*)InvMassMu2TauMuCanvash750a9->GetPrimitive("InvMassMu2TauMu");
  TH1F *InvMassMu1TauMuh750a9_ = (TH1F*)InvMassMu1TauMuCanvash750a9->GetPrimitive("InvMassMu1TauMu");
  TH1F *InvMassFullRangeh750a9_ = (TH1F*)InvMassFullRangeCanvash750a9->GetPrimitive("InvMassFullRange");
  TH1F *InvMassDiMuBarrBarrh750a9_ = (TH1F*)InvMassDiMuBarrBarrCanvash750a9->GetPrimitive("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a9_ = (TH1F*)InvMassDiMuBarrEndcCanvash750a9->GetPrimitive("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a9_ = (TH1F*)InvMassDiMuEndcEndcCanvash750a9->GetPrimitive("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a9_ = (TH1F*)Mu1PtCanvash750a9->GetPrimitive("Mu1Pt");
  TH1F *Mu2Pth750a9_ = (TH1F*)Mu2PtCanvash750a9->GetPrimitive("Mu2Pt");
  TH1F *DiMuPth750a9_ = (TH1F*)DiMuPtCanvash750a9->GetPrimitive("DiMuPt");
  TH1F *InvMassDiMuBarrOverh750a9_ = (TH1F*)InvMassDiMuBarrOverCanvash750a9->GetPrimitive("InvMassDiMuBarrOver");
  TH1F *InvMassDiMuEndcOverh750a9_ = (TH1F*)InvMassDiMuEndcOverCanvash750a9->GetPrimitive("InvMassDiMuEndcOver");
  TH1F *DiTauEtah750a9_ = (TH1F*)DiTauEtaCanvash750a9->GetPrimitive("DiTauEta");
  TH1F *DiTauPhih750a9_ = (TH1F*)DiTauPhiCanvash750a9->GetPrimitive("DiTauPhi");
  TH1F *DiMuEtah750a9_ = (TH1F*)DiMuEtaCanvash750a9->GetPrimitive("DiMuEta");
  TH1F *DiMudRh750a9_ = (TH1F*)DiMudRCanvash750a9->GetPrimitive("DiMudR");
  TH1F *InvMassDiMuOverOverh750a9_ = (TH1F*)InvMassDiMuOverOverCanvash750a9->GetPrimitive("InvMassDiMuOverOver");
  TH1F *EtMETh750a9_ = (TH1F*)EtMETCanvash750a9->GetPrimitive("EtMET");
  TH1F *DiTauDiMuMassh750a9_ = (TH1F*)DiTauDiMuMassCanvash750a9->GetPrimitive("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a9_ = (TH1F*)DiMuDiTauDeltaPhiCanvash750a9->GetPrimitive("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a9_ = (TH1F*)METDiTauDeltaPhiCanvash750a9->GetPrimitive("METDiTauDeltaPhi");
  TH1F *METDiMuDeltaPhih750a9_ = (TH1F*)METDiMuDeltaPhiCanvash750a9->GetPrimitive("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a9_ = (TH1F*)DiTaudRCanvash750a9->GetPrimitive("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a9_ = (TH1F*)DiTauMassSmallerdRCanvash750a9->GetPrimitive("DiTauMassSmallerdR");
  TH1F *HighestCSVInclJeth750a9_ = (TH1F*)HighestCSVInclJetCanvash750a9->GetPrimitive("HighestCSVInclJet");

cout << "Got Histograms from Canvases" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting Fill Colors
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  NMedIsoTausWithMu3h125a11_->SetLineColor(kGray+1);
  InvMassTauHadMu3h125a11_->SetLineColor(kGray+1);
  PtTauHadMu3h125a11_->SetLineColor(kGray+1);
  InvMassMu2TauMuh125a11_->SetLineColor(kGray+1);
  InvMassMu1TauMuh125a11_->SetLineColor(kGray+1);
  InvMassFullRangeh125a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrBarrh125a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrEndch125a11_->SetLineColor(kGray+1);
  InvMassDiMuEndcEndch125a11_->SetLineColor(kGray+1);
  Mu1Pth125a11_->SetLineColor(kGray+1);
  Mu2Pth125a11_->SetLineColor(kGray+1);
  DiMuPth125a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrOverh125a11_->SetLineColor(kGray+1);
  InvMassDiMuEndcOverh125a11_->SetLineColor(kGray+1);
  DiTauEtah125a11_->SetLineColor(kGray+1);
  DiTauPhih125a11_->SetLineColor(kGray+1);
  DiMuEtah125a11_->SetLineColor(kGray+1);
  DiMudRh125a11_->SetLineColor(kGray+1);
  InvMassDiMuOverOverh125a11_->SetLineColor(kGray+1);
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
  InvMassMu2TauMuh125a13_->SetLineColor(kGreen);
  InvMassMu1TauMuh125a13_->SetLineColor(kGreen);
  InvMassFullRangeh125a13_->SetLineColor(kGreen);
  InvMassDiMuBarrBarrh125a13_->SetLineColor(kGreen);
  InvMassDiMuBarrEndch125a13_->SetLineColor(kGreen);
  InvMassDiMuEndcEndch125a13_->SetLineColor(kGreen);
  Mu1Pth125a13_->SetLineColor(kGreen);
  Mu2Pth125a13_->SetLineColor(kGreen);
  DiMuPth125a13_->SetLineColor(kGreen);
  InvMassDiMuBarrOverh125a13_->SetLineColor(kGreen);
  InvMassDiMuEndcOverh125a13_->SetLineColor(kGreen);
  DiTauEtah125a13_->SetLineColor(kGreen);
  DiTauPhih125a13_->SetLineColor(kGreen);
  DiMuEtah125a13_->SetLineColor(kGreen);
  DiMudRh125a13_->SetLineColor(kGreen);
  InvMassDiMuOverOverh125a13_->SetLineColor(kGreen);
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
  InvMassMu2TauMuh125a15_->SetLineColor(kTeal-1);
  InvMassMu1TauMuh125a15_->SetLineColor(kTeal-1);
  InvMassFullRangeh125a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrBarrh125a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrEndch125a15_->SetLineColor(kTeal-1);
  InvMassDiMuEndcEndch125a15_->SetLineColor(kTeal-1);
  Mu1Pth125a15_->SetLineColor(kTeal-1);
  Mu2Pth125a15_->SetLineColor(kTeal-1);
  DiMuPth125a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrOverh125a15_->SetLineColor(kTeal-1);
  InvMassDiMuEndcOverh125a15_->SetLineColor(kTeal-1);
  DiTauEtah125a15_->SetLineColor(kTeal-1);
  DiTauPhih125a15_->SetLineColor(kTeal-1);
  DiMuEtah125a15_->SetLineColor(kTeal-1);
  DiMudRh125a15_->SetLineColor(kTeal-1);
  InvMassDiMuOverOverh125a15_->SetLineColor(kTeal-1);
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
  InvMassMu2TauMuh125a17_->SetLineColor(kCyan);
  InvMassMu1TauMuh125a17_->SetLineColor(kCyan);
  InvMassFullRangeh125a17_->SetLineColor(kCyan);
  InvMassDiMuBarrBarrh125a17_->SetLineColor(kCyan);
  InvMassDiMuBarrEndch125a17_->SetLineColor(kCyan);
  InvMassDiMuEndcEndch125a17_->SetLineColor(kCyan);
  Mu1Pth125a17_->SetLineColor(kCyan);
  Mu2Pth125a17_->SetLineColor(kCyan);
  DiMuPth125a17_->SetLineColor(kCyan);
  InvMassDiMuBarrOverh125a17_->SetLineColor(kCyan);
  InvMassDiMuEndcOverh125a17_->SetLineColor(kCyan);
  DiTauEtah125a17_->SetLineColor(kCyan);
  DiTauPhih125a17_->SetLineColor(kCyan);
  DiMuEtah125a17_->SetLineColor(kCyan);
  DiMudRh125a17_->SetLineColor(kCyan);
  InvMassDiMuOverOverh125a17_->SetLineColor(kCyan);
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
  InvMassMu2TauMuh125a19_->SetLineColor(kAzure+3);
  InvMassMu1TauMuh125a19_->SetLineColor(kAzure+3);
  InvMassFullRangeh125a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrBarrh125a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrEndch125a19_->SetLineColor(kAzure+3);
  InvMassDiMuEndcEndch125a19_->SetLineColor(kAzure+3);
  Mu1Pth125a19_->SetLineColor(kAzure+3);
  Mu2Pth125a19_->SetLineColor(kAzure+3);
  DiMuPth125a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrOverh125a19_->SetLineColor(kAzure+3);
  InvMassDiMuEndcOverh125a19_->SetLineColor(kAzure+3);
  DiTauEtah125a19_->SetLineColor(kAzure+3);
  DiTauPhih125a19_->SetLineColor(kAzure+3);
  DiMuEtah125a19_->SetLineColor(kAzure+3);
  DiMudRh125a19_->SetLineColor(kAzure+3);
  InvMassDiMuOverOverh125a19_->SetLineColor(kAzure+3);
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
  InvMassMu2TauMuh125a21_->SetLineColor(kBlue);
  InvMassMu1TauMuh125a21_->SetLineColor(kBlue);
  InvMassFullRangeh125a21_->SetLineColor(kBlue);
  InvMassDiMuBarrBarrh125a21_->SetLineColor(kBlue);
  InvMassDiMuBarrEndch125a21_->SetLineColor(kBlue);
  InvMassDiMuEndcEndch125a21_->SetLineColor(kBlue);
  Mu1Pth125a21_->SetLineColor(kBlue);
  Mu2Pth125a21_->SetLineColor(kBlue);
  DiMuPth125a21_->SetLineColor(kBlue);
  InvMassDiMuBarrOverh125a21_->SetLineColor(kBlue);
  InvMassDiMuEndcOverh125a21_->SetLineColor(kBlue);
  DiTauEtah125a21_->SetLineColor(kBlue);
  DiTauPhih125a21_->SetLineColor(kBlue);
  DiMuEtah125a21_->SetLineColor(kBlue);
  DiMudRh125a21_->SetLineColor(kBlue);
  InvMassDiMuOverOverh125a21_->SetLineColor(kBlue);
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
  InvMassMu2TauMuh125a5_->SetLineColor(kSpring-7);
  InvMassMu1TauMuh125a5_->SetLineColor(kSpring-7);
  InvMassFullRangeh125a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrBarrh125a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrEndch125a5_->SetLineColor(kSpring-7);
  InvMassDiMuEndcEndch125a5_->SetLineColor(kSpring-7);
  Mu1Pth125a5_->SetLineColor(kSpring-7);
  Mu2Pth125a5_->SetLineColor(kSpring-7);
  DiMuPth125a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrOverh125a5_->SetLineColor(kSpring-7);
  InvMassDiMuEndcOverh125a5_->SetLineColor(kSpring-7);
  DiTauEtah125a5_->SetLineColor(kSpring-7);
  DiTauPhih125a5_->SetLineColor(kSpring-7);
  DiMuEtah125a5_->SetLineColor(kSpring-7);
  DiMudRh125a5_->SetLineColor(kSpring-7);
  InvMassDiMuOverOverh125a5_->SetLineColor(kSpring-7);
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
  InvMassMu2TauMuh125a7_->SetLineColor(kYellow+1);
  InvMassMu1TauMuh125a7_->SetLineColor(kYellow+1);
  InvMassFullRangeh125a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrBarrh125a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrEndch125a7_->SetLineColor(kYellow+1);
  InvMassDiMuEndcEndch125a7_->SetLineColor(kYellow+1);
  Mu1Pth125a7_->SetLineColor(kYellow+1);
  Mu2Pth125a7_->SetLineColor(kYellow+1);
  DiMuPth125a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrOverh125a7_->SetLineColor(kYellow+1);
  InvMassDiMuEndcOverh125a7_->SetLineColor(kYellow+1);
  DiTauEtah125a7_->SetLineColor(kYellow+1);
  DiTauPhih125a7_->SetLineColor(kYellow+1);
  DiMuEtah125a7_->SetLineColor(kYellow+1);
  DiMudRh125a7_->SetLineColor(kYellow+1);
  InvMassDiMuOverOverh125a7_->SetLineColor(kYellow+1);
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
  InvMassMu2TauMuh125a9_->SetLineColor(kOrange+9);
  InvMassMu1TauMuh125a9_->SetLineColor(kOrange+9);
  InvMassFullRangeh125a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrBarrh125a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrEndch125a9_->SetLineColor(kOrange+9);
  InvMassDiMuEndcEndch125a9_->SetLineColor(kOrange+9);
  Mu1Pth125a9_->SetLineColor(kOrange+9);
  Mu2Pth125a9_->SetLineColor(kOrange+9);
  DiMuPth125a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrOverh125a9_->SetLineColor(kOrange+9);
  InvMassDiMuEndcOverh125a9_->SetLineColor(kOrange+9);
  DiTauEtah125a9_->SetLineColor(kOrange+9);
  DiTauPhih125a9_->SetLineColor(kOrange+9);
  DiMuEtah125a9_->SetLineColor(kOrange+9);
  DiMudRh125a9_->SetLineColor(kOrange+9);
  InvMassDiMuOverOverh125a9_->SetLineColor(kOrange+9);
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
  InvMassMu2TauMuh300a11_->SetLineColor(kGray+1);
  InvMassMu1TauMuh300a11_->SetLineColor(kGray+1);
  InvMassFullRangeh300a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrBarrh300a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrEndch300a11_->SetLineColor(kGray+1);
  InvMassDiMuEndcEndch300a11_->SetLineColor(kGray+1);
  Mu1Pth300a11_->SetLineColor(kGray+1);
  Mu2Pth300a11_->SetLineColor(kGray+1);
  DiMuPth300a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrOverh300a11_->SetLineColor(kGray+1);
  InvMassDiMuEndcOverh300a11_->SetLineColor(kGray+1);
  DiTauEtah300a11_->SetLineColor(kGray+1);
  DiTauPhih300a11_->SetLineColor(kGray+1);
  DiMuEtah300a11_->SetLineColor(kGray+1);
  DiMudRh300a11_->SetLineColor(kGray+1);
  InvMassDiMuOverOverh300a11_->SetLineColor(kGray+1);
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
  InvMassMu2TauMuh300a13_->SetLineColor(kGreen);
  InvMassMu1TauMuh300a13_->SetLineColor(kGreen);
  InvMassFullRangeh300a13_->SetLineColor(kGreen);
  InvMassDiMuBarrBarrh300a13_->SetLineColor(kGreen);
  InvMassDiMuBarrEndch300a13_->SetLineColor(kGreen);
  InvMassDiMuEndcEndch300a13_->SetLineColor(kGreen);
  Mu1Pth300a13_->SetLineColor(kGreen);
  Mu2Pth300a13_->SetLineColor(kGreen);
  DiMuPth300a13_->SetLineColor(kGreen);
  InvMassDiMuBarrOverh300a13_->SetLineColor(kGreen);
  InvMassDiMuEndcOverh300a13_->SetLineColor(kGreen);
  DiTauEtah300a13_->SetLineColor(kGreen);
  DiTauPhih300a13_->SetLineColor(kGreen);
  DiMuEtah300a13_->SetLineColor(kGreen);
  DiMudRh300a13_->SetLineColor(kGreen);
  InvMassDiMuOverOverh300a13_->SetLineColor(kGreen);
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
  InvMassMu2TauMuh300a15_->SetLineColor(kTeal-1);
  InvMassMu1TauMuh300a15_->SetLineColor(kTeal-1);
  InvMassFullRangeh300a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrBarrh300a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrEndch300a15_->SetLineColor(kTeal-1);
  InvMassDiMuEndcEndch300a15_->SetLineColor(kTeal-1);
  Mu1Pth300a15_->SetLineColor(kTeal-1);
  Mu2Pth300a15_->SetLineColor(kTeal-1);
  DiMuPth300a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrOverh300a15_->SetLineColor(kTeal-1);
  InvMassDiMuEndcOverh300a15_->SetLineColor(kTeal-1);
  DiTauEtah300a15_->SetLineColor(kTeal-1);
  DiTauPhih300a15_->SetLineColor(kTeal-1);
  DiMuEtah300a15_->SetLineColor(kTeal-1);
  DiMudRh300a15_->SetLineColor(kTeal-1);
  InvMassDiMuOverOverh300a15_->SetLineColor(kTeal-1);
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
  InvMassMu2TauMuh300a17_->SetLineColor(kCyan);
  InvMassMu1TauMuh300a17_->SetLineColor(kCyan);
  InvMassFullRangeh300a17_->SetLineColor(kCyan);
  InvMassDiMuBarrBarrh300a17_->SetLineColor(kCyan);
  InvMassDiMuBarrEndch300a17_->SetLineColor(kCyan);
  InvMassDiMuEndcEndch300a17_->SetLineColor(kCyan);
  Mu1Pth300a17_->SetLineColor(kCyan);
  Mu2Pth300a17_->SetLineColor(kCyan);
  DiMuPth300a17_->SetLineColor(kCyan);
  InvMassDiMuBarrOverh300a17_->SetLineColor(kCyan);
  InvMassDiMuEndcOverh300a17_->SetLineColor(kCyan);
  DiTauEtah300a17_->SetLineColor(kCyan);
  DiTauPhih300a17_->SetLineColor(kCyan);
  DiMuEtah300a17_->SetLineColor(kCyan);
  DiMudRh300a17_->SetLineColor(kCyan);
  InvMassDiMuOverOverh300a17_->SetLineColor(kCyan);
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
  InvMassMu2TauMuh300a19_->SetLineColor(kAzure+3);
  InvMassMu1TauMuh300a19_->SetLineColor(kAzure+3);
  InvMassFullRangeh300a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrBarrh300a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrEndch300a19_->SetLineColor(kAzure+3);
  InvMassDiMuEndcEndch300a19_->SetLineColor(kAzure+3);
  Mu1Pth300a19_->SetLineColor(kAzure+3);
  Mu2Pth300a19_->SetLineColor(kAzure+3);
  DiMuPth300a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrOverh300a19_->SetLineColor(kAzure+3);
  InvMassDiMuEndcOverh300a19_->SetLineColor(kAzure+3);
  DiTauEtah300a19_->SetLineColor(kAzure+3);
  DiTauPhih300a19_->SetLineColor(kAzure+3);
  DiMuEtah300a19_->SetLineColor(kAzure+3);
  DiMudRh300a19_->SetLineColor(kAzure+3);
  InvMassDiMuOverOverh300a19_->SetLineColor(kAzure+3);
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
  InvMassMu2TauMuh300a21_->SetLineColor(kBlue);
  InvMassMu1TauMuh300a21_->SetLineColor(kBlue);
  InvMassFullRangeh300a21_->SetLineColor(kBlue);
  InvMassDiMuBarrBarrh300a21_->SetLineColor(kBlue);
  InvMassDiMuBarrEndch300a21_->SetLineColor(kBlue);
  InvMassDiMuEndcEndch300a21_->SetLineColor(kBlue);
  Mu1Pth300a21_->SetLineColor(kBlue);
  Mu2Pth300a21_->SetLineColor(kBlue);
  DiMuPth300a21_->SetLineColor(kBlue);
  InvMassDiMuBarrOverh300a21_->SetLineColor(kBlue);
  InvMassDiMuEndcOverh300a21_->SetLineColor(kBlue);
  DiTauEtah300a21_->SetLineColor(kBlue);
  DiTauPhih300a21_->SetLineColor(kBlue);
  DiMuEtah300a21_->SetLineColor(kBlue);
  DiMudRh300a21_->SetLineColor(kBlue);
  InvMassDiMuOverOverh300a21_->SetLineColor(kBlue);
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
  InvMassMu2TauMuh300a5_->SetLineColor(kSpring-7);
  InvMassMu1TauMuh300a5_->SetLineColor(kSpring-7);
  InvMassFullRangeh300a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrBarrh300a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrEndch300a5_->SetLineColor(kSpring-7);
  InvMassDiMuEndcEndch300a5_->SetLineColor(kSpring-7);
  Mu1Pth300a5_->SetLineColor(kSpring-7);
  Mu2Pth300a5_->SetLineColor(kSpring-7);
  DiMuPth300a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrOverh300a5_->SetLineColor(kSpring-7);
  InvMassDiMuEndcOverh300a5_->SetLineColor(kSpring-7);
  DiTauEtah300a5_->SetLineColor(kSpring-7);
  DiTauPhih300a5_->SetLineColor(kSpring-7);
  DiMuEtah300a5_->SetLineColor(kSpring-7);
  DiMudRh300a5_->SetLineColor(kSpring-7);
  InvMassDiMuOverOverh300a5_->SetLineColor(kSpring-7);
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
  InvMassMu2TauMuh300a7_->SetLineColor(kYellow+1);
  InvMassMu1TauMuh300a7_->SetLineColor(kYellow+1);
  InvMassFullRangeh300a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrBarrh300a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrEndch300a7_->SetLineColor(kYellow+1);
  InvMassDiMuEndcEndch300a7_->SetLineColor(kYellow+1);
  Mu1Pth300a7_->SetLineColor(kYellow+1);
  Mu2Pth300a7_->SetLineColor(kYellow+1);
  DiMuPth300a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrOverh300a7_->SetLineColor(kYellow+1);
  InvMassDiMuEndcOverh300a7_->SetLineColor(kYellow+1);
  DiTauEtah300a7_->SetLineColor(kYellow+1);
  DiTauPhih300a7_->SetLineColor(kYellow+1);
  DiMuEtah300a7_->SetLineColor(kYellow+1);
  DiMudRh300a7_->SetLineColor(kYellow+1);
  InvMassDiMuOverOverh300a7_->SetLineColor(kYellow+1);
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
  InvMassMu2TauMuh300a9_->SetLineColor(kOrange+9);
  InvMassMu1TauMuh300a9_->SetLineColor(kOrange+9);
  InvMassFullRangeh300a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrBarrh300a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrEndch300a9_->SetLineColor(kOrange+9);
  InvMassDiMuEndcEndch300a9_->SetLineColor(kOrange+9);
  Mu1Pth300a9_->SetLineColor(kOrange+9);
  Mu2Pth300a9_->SetLineColor(kOrange+9);
  DiMuPth300a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrOverh300a9_->SetLineColor(kOrange+9);
  InvMassDiMuEndcOverh300a9_->SetLineColor(kOrange+9);
  DiTauEtah300a9_->SetLineColor(kOrange+9);
  DiTauPhih300a9_->SetLineColor(kOrange+9);
  DiMuEtah300a9_->SetLineColor(kOrange+9);
  DiMudRh300a9_->SetLineColor(kOrange+9);
  InvMassDiMuOverOverh300a9_->SetLineColor(kOrange+9);
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
  InvMassMu2TauMuh750a11_->SetLineColor(kGray+1);
  InvMassMu1TauMuh750a11_->SetLineColor(kGray+1);
  InvMassFullRangeh750a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrBarrh750a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrEndch750a11_->SetLineColor(kGray+1);
  InvMassDiMuEndcEndch750a11_->SetLineColor(kGray+1);
  Mu1Pth750a11_->SetLineColor(kGray+1);
  Mu2Pth750a11_->SetLineColor(kGray+1);
  DiMuPth750a11_->SetLineColor(kGray+1);
  InvMassDiMuBarrOverh750a11_->SetLineColor(kGray+1);
  InvMassDiMuEndcOverh750a11_->SetLineColor(kGray+1);
  DiTauEtah750a11_->SetLineColor(kGray+1);
  DiTauPhih750a11_->SetLineColor(kGray+1);
  DiMuEtah750a11_->SetLineColor(kGray+1);
  DiMudRh750a11_->SetLineColor(kGray+1);
  InvMassDiMuOverOverh750a11_->SetLineColor(kGray+1);
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
  InvMassMu2TauMuh750a13_->SetLineColor(kGreen);
  InvMassMu1TauMuh750a13_->SetLineColor(kGreen);
  InvMassFullRangeh750a13_->SetLineColor(kGreen);
  InvMassDiMuBarrBarrh750a13_->SetLineColor(kGreen);
  InvMassDiMuBarrEndch750a13_->SetLineColor(kGreen);
  InvMassDiMuEndcEndch750a13_->SetLineColor(kGreen);
  Mu1Pth750a13_->SetLineColor(kGreen);
  Mu2Pth750a13_->SetLineColor(kGreen);
  DiMuPth750a13_->SetLineColor(kGreen);
  InvMassDiMuBarrOverh750a13_->SetLineColor(kGreen);
  InvMassDiMuEndcOverh750a13_->SetLineColor(kGreen);
  DiTauEtah750a13_->SetLineColor(kGreen);
  DiTauPhih750a13_->SetLineColor(kGreen);
  DiMuEtah750a13_->SetLineColor(kGreen);
  DiMudRh750a13_->SetLineColor(kGreen);
  InvMassDiMuOverOverh750a13_->SetLineColor(kGreen);
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
  InvMassMu2TauMuh750a15_->SetLineColor(kTeal-1);
  InvMassMu1TauMuh750a15_->SetLineColor(kTeal-1);
  InvMassFullRangeh750a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrBarrh750a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrEndch750a15_->SetLineColor(kTeal-1);
  InvMassDiMuEndcEndch750a15_->SetLineColor(kTeal-1);
  Mu1Pth750a15_->SetLineColor(kTeal-1);
  Mu2Pth750a15_->SetLineColor(kTeal-1);
  DiMuPth750a15_->SetLineColor(kTeal-1);
  InvMassDiMuBarrOverh750a15_->SetLineColor(kTeal-1);
  InvMassDiMuEndcOverh750a15_->SetLineColor(kTeal-1);
  DiTauEtah750a15_->SetLineColor(kTeal-1);
  DiTauPhih750a15_->SetLineColor(kTeal-1);
  DiMuEtah750a15_->SetLineColor(kTeal-1);
  DiMudRh750a15_->SetLineColor(kTeal-1);
  InvMassDiMuOverOverh750a15_->SetLineColor(kTeal-1);
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
  InvMassMu2TauMuh750a17_->SetLineColor(kCyan);
  InvMassMu1TauMuh750a17_->SetLineColor(kCyan);
  InvMassFullRangeh750a17_->SetLineColor(kCyan);
  InvMassDiMuBarrBarrh750a17_->SetLineColor(kCyan);
  InvMassDiMuBarrEndch750a17_->SetLineColor(kCyan);
  InvMassDiMuEndcEndch750a17_->SetLineColor(kCyan);
  Mu1Pth750a17_->SetLineColor(kCyan);
  Mu2Pth750a17_->SetLineColor(kCyan);
  DiMuPth750a17_->SetLineColor(kCyan);
  InvMassDiMuBarrOverh750a17_->SetLineColor(kCyan);
  InvMassDiMuEndcOverh750a17_->SetLineColor(kCyan);
  DiTauEtah750a17_->SetLineColor(kCyan);
  DiTauPhih750a17_->SetLineColor(kCyan);
  DiMuEtah750a17_->SetLineColor(kCyan);
  DiMudRh750a17_->SetLineColor(kCyan);
  InvMassDiMuOverOverh750a17_->SetLineColor(kCyan);
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
  InvMassMu2TauMuh750a19_->SetLineColor(kAzure+3);
  InvMassMu1TauMuh750a19_->SetLineColor(kAzure+3);
  InvMassFullRangeh750a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrBarrh750a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrEndch750a19_->SetLineColor(kAzure+3);
  InvMassDiMuEndcEndch750a19_->SetLineColor(kAzure+3);
  Mu1Pth750a19_->SetLineColor(kAzure+3);
  Mu2Pth750a19_->SetLineColor(kAzure+3);
  DiMuPth750a19_->SetLineColor(kAzure+3);
  InvMassDiMuBarrOverh750a19_->SetLineColor(kAzure+3);
  InvMassDiMuEndcOverh750a19_->SetLineColor(kAzure+3);
  DiTauEtah750a19_->SetLineColor(kAzure+3);
  DiTauPhih750a19_->SetLineColor(kAzure+3);
  DiMuEtah750a19_->SetLineColor(kAzure+3);
  DiMudRh750a19_->SetLineColor(kAzure+3);
  InvMassDiMuOverOverh750a19_->SetLineColor(kAzure+3);
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
  InvMassMu2TauMuh750a21_->SetLineColor(kBlue);
  InvMassMu1TauMuh750a21_->SetLineColor(kBlue);
  InvMassFullRangeh750a21_->SetLineColor(kBlue);
  InvMassDiMuBarrBarrh750a21_->SetLineColor(kBlue);
  InvMassDiMuBarrEndch750a21_->SetLineColor(kBlue);
  InvMassDiMuEndcEndch750a21_->SetLineColor(kBlue);
  Mu1Pth750a21_->SetLineColor(kBlue);
  Mu2Pth750a21_->SetLineColor(kBlue);
  DiMuPth750a21_->SetLineColor(kBlue);
  InvMassDiMuBarrOverh750a21_->SetLineColor(kBlue);
  InvMassDiMuEndcOverh750a21_->SetLineColor(kBlue);
  DiTauEtah750a21_->SetLineColor(kBlue);
  DiTauPhih750a21_->SetLineColor(kBlue);
  DiMuEtah750a21_->SetLineColor(kBlue);
  DiMudRh750a21_->SetLineColor(kBlue);
  InvMassDiMuOverOverh750a21_->SetLineColor(kBlue);
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
  InvMassMu2TauMuh750a5_->SetLineColor(kSpring-7);
  InvMassMu1TauMuh750a5_->SetLineColor(kSpring-7);
  InvMassFullRangeh750a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrBarrh750a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrEndch750a5_->SetLineColor(kSpring-7);
  InvMassDiMuEndcEndch750a5_->SetLineColor(kSpring-7);
  Mu1Pth750a5_->SetLineColor(kSpring-7);
  Mu2Pth750a5_->SetLineColor(kSpring-7);
  DiMuPth750a5_->SetLineColor(kSpring-7);
  InvMassDiMuBarrOverh750a5_->SetLineColor(kSpring-7);
  InvMassDiMuEndcOverh750a5_->SetLineColor(kSpring-7);
  DiTauEtah750a5_->SetLineColor(kSpring-7);
  DiTauPhih750a5_->SetLineColor(kSpring-7);
  DiMuEtah750a5_->SetLineColor(kSpring-7);
  DiMudRh750a5_->SetLineColor(kSpring-7);
  InvMassDiMuOverOverh750a5_->SetLineColor(kSpring-7);
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
  InvMassMu2TauMuh750a7_->SetLineColor(kYellow+1);
  InvMassMu1TauMuh750a7_->SetLineColor(kYellow+1);
  InvMassFullRangeh750a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrBarrh750a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrEndch750a7_->SetLineColor(kYellow+1);
  InvMassDiMuEndcEndch750a7_->SetLineColor(kYellow+1);
  Mu1Pth750a7_->SetLineColor(kYellow+1);
  Mu2Pth750a7_->SetLineColor(kYellow+1);
  DiMuPth750a7_->SetLineColor(kYellow+1);
  InvMassDiMuBarrOverh750a7_->SetLineColor(kYellow+1);
  InvMassDiMuEndcOverh750a7_->SetLineColor(kYellow+1);
  DiTauEtah750a7_->SetLineColor(kYellow+1);
  DiTauPhih750a7_->SetLineColor(kYellow+1);
  DiMuEtah750a7_->SetLineColor(kYellow+1);
  DiMudRh750a7_->SetLineColor(kYellow+1);
  InvMassDiMuOverOverh750a7_->SetLineColor(kYellow+1);
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
  InvMassMu2TauMuh750a9_->SetLineColor(kOrange+9);
  InvMassMu1TauMuh750a9_->SetLineColor(kOrange+9);
  InvMassFullRangeh750a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrBarrh750a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrEndch750a9_->SetLineColor(kOrange+9);
  InvMassDiMuEndcEndch750a9_->SetLineColor(kOrange+9);
  Mu1Pth750a9_->SetLineColor(kOrange+9);
  Mu2Pth750a9_->SetLineColor(kOrange+9);
  DiMuPth750a9_->SetLineColor(kOrange+9);
  InvMassDiMuBarrOverh750a9_->SetLineColor(kOrange+9);
  InvMassDiMuEndcOverh750a9_->SetLineColor(kOrange+9);
  DiTauEtah750a9_->SetLineColor(kOrange+9);
  DiTauPhih750a9_->SetLineColor(kOrange+9);
  DiMuEtah750a9_->SetLineColor(kOrange+9);
  DiMudRh750a9_->SetLineColor(kOrange+9);
  InvMassDiMuOverOverh750a9_->SetLineColor(kOrange+9);
  EtMETh750a9_->SetLineColor(kOrange+9);
  DiTauDiMuMassh750a9_->SetLineColor(kOrange+9);
  DiMuDiTauDeltaPhih750a9_->SetLineColor(kOrange+9);
  METDiTauDeltaPhih750a9_->SetLineColor(kOrange+9);
  METDiMuDeltaPhih750a9_->SetLineColor(kOrange+9);
  DiTaudRh750a9_->SetLineColor(kOrange+9);
  DiTauMassSmallerdRh750a9_->SetLineColor(kOrange+9);
  HighestCSVInclJeth750a9_->SetLineColor(kOrange+9);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the output plots
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *NMedIsoTausWithMu3Canvash125 = new TCanvas ("NMedIsoTausWithMu3Canvash125","",600,600);
  TCanvas *InvMassTauHadMu3Canvash125 = new TCanvas ("InvMassTauHadMu3Canvash125","",600,600);
  TCanvas *PtTauHadMu3Canvash125 = new TCanvas ("PtTauHadMu3Canvash125","",600,600);
  TCanvas *InvMassMu1TauMuCanvash125 = new TCanvas ("InvMassMu1TauMuCanvash125","",600,600);
  TCanvas *InvMassFullRangeCanvash125 = new TCanvas ("InvMassFullRangeCanvash125","",600,600);
  TCanvas *InvMassMu2TauMuCanvash125 = new TCanvas ("InvMassMu2TauMuCanvash125","",600,600);
  TCanvas *InvMassDiMuBarrBarrCanvash125 = new TCanvas ("InvMassDiMuBarrBarrCanvash125","",600,600);
  TCanvas *InvMassDiMuBarrEndcCanvash125 = new TCanvas ("InvMassDiMuBarrEndcCanvash125","",600,600);
  TCanvas *InvMassDiMuEndcEndcCanvash125 = new TCanvas ("InvMassDiMuEndcEndcCanvash125","",600,600);
  TCanvas *Mu1PtCanvash125 = new TCanvas ("Mu1PtCanvash125","",600,600);
  TCanvas *Mu2PtCanvash125 = new TCanvas ("Mu2PtCanvash125","",600,600);
  TCanvas *DiMuPtCanvash125 = new TCanvas ("DiMuPtCanvash125","",600,600);
  TCanvas *InvMassDiMuBarrOverCanvash125 = new TCanvas ("InvMassDiMuBarrOverCanvash125","",600,600);
  TCanvas *InvMassDiMuEndcOverCanvash125 = new TCanvas ("InvMassDiMuEndcOverCanvash125","",600,600);
  TCanvas *DiTauEtaCanvash125 = new TCanvas ("DiTauEtaCanvash125","",600,600);
  TCanvas *DiTauPhiCanvash125 = new TCanvas ("DiTauPhiCanvash125","",600,600);
  TCanvas *DiMuEtaCanvash125 = new TCanvas ("DiMuEtaCanvash125","",600,600);
  TCanvas *DiMudRCanvash125 = new TCanvas ("DiMudRCanvash125","",600,600);
  TCanvas *InvMassDiMuOverOverCanvash125 = new TCanvas ("InvMassDiMuOverOverCanvash125","",600,600);
  TCanvas *EtMETCanvash125 = new TCanvas ("EtMETCanvash125","",600,600);
  TCanvas *DiTauDiMuMassCanvash125 = new TCanvas ("DiTauDiMuMassCanvash125","",600,600);
  TCanvas *DiMuDiTauDeltaPhiCanvash125 = new TCanvas ("DiMuDiTauDeltaPhiCanvash125","",600,600);
  TCanvas *METDiTauDeltaPhiCanvash125 = new TCanvas ("METDiTauDeltaPhiCanvash125","",600,600);
  TCanvas *METDiMuDeltaPhiCanvash125 = new TCanvas ("METDiMuDeltaPhiCanvash125","",600,600);
  TCanvas *DiTaudRCanvash125 = new TCanvas ("DiTaudRCanvash125","",600,600);
  TCanvas *DiTauMassSmallerdRCanvash125 = new TCanvas ("DiTauMassSmallerdRCanvash125","",600,600);
  TCanvas *HighestCSVInclJetCanvash125 = new TCanvas ("HighestCSVInclJetCanvash125","",600,600);

  TPad *NMedIsoTausWithMu3PlotPadh125 = new TPad ("NMedIsoTausWithMu3PlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassTauHadMu3PlotPadh125 = new TPad ("InvMassTauHadMu3PlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *PtTauHadMu3PlotPadh125 = new TPad ("PtTauHadMu3PlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassMu1TauMuPlotPadh125 = new TPad ("InvMassMu1TauMuPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassFullRangePlotPadh125 = new TPad ("InvMassFullRangePlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassMu2TauMuPlotPadh125 = new TPad ("InvMassMu2TauMuPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuBarrBarrPlotPadh125 = new TPad ("InvMassDiMuBarrBarrPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuBarrEndcPlotPadh125 = new TPad ("InvMassDiMuBarrEndcPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuEndcEndcPlotPadh125 = new TPad ("InvMassDiMuEndcEndcPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *Mu1PtPlotPadh125 = new TPad ("Mu1PtPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *Mu2PtPlotPadh125 = new TPad ("Mu2PtPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuPtPlotPadh125 = new TPad ("DiMuPtPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuBarrOverPlotPadh125 = new TPad ("InvMassDiMuBarrOverPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuEndcOverPlotPadh125 = new TPad ("InvMassDiMuEndcOverPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauEtaPlotPadh125 = new TPad ("DiTauEtaPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauPhiPlotPadh125 = new TPad ("DiTauPhiPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuEtaPlotPadh125 = new TPad ("DiMuEtaPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMudRPlotPadh125 = new TPad ("DiMudRPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuOverOverPlotPadh125 = new TPad ("InvMassDiMuOverOverPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *EtMETPlotPadh125 = new TPad ("EtMETPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauDiMuMassPlotPadh125 = new TPad ("DiTauDiMuMassPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuDiTauDeltaPhiPlotPadh125 = new TPad ("DiMuDiTauDeltaPhiPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *METDiTauDeltaPhiPlotPadh125 = new TPad ("METDiTauDeltaPhiPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *METDiMuDeltaPhiPlotPadh125 = new TPad ("METDiMuDeltaPhiPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTaudRPlotPadh125 = new TPad ("DiTaudRPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauMassSmallerdRPlotPadh125 = new TPad ("DiTauMassSmallerdRPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *HighestCSVInclJetPlotPadh125 = new TPad ("HighestCSVInclJetPlotPadh125", "top pad", 0.0, 0.21, 1.0, 1.0);

//  NMedIsoTausWithMu3PlotPadh125->SetBottomMargin(0.04);
//  InvMassTauHadMu3PlotPadh125->SetBottomMargin(0.04);
//  PtTauHadMu3PlotPadh125->SetBottomMargin(0.04);
//  InvMassMu2TauMuPlotPadh125->SetBottomMargin(0.04);
//  InvMassMu1TauMuPlotPadh125->SetBottomMargin(0.04);
//  InvMassFullRangePlotPadh125->SetBottomMargin(0.04);
//  InvMassDiMuBarrBarrPlotPadh125->SetBottomMargin(0.04);
//  InvMassDiMuBarrEndcPlotPadh125->SetBottomMargin(0.04);
//  InvMassDiMuEndcEndcPlotPadh125->SetBottomMargin(0.04);
//  Mu1PtPlotPadh125->SetBottomMargin(0.04);
//  Mu2PtPlotPadh125->SetBottomMargin(0.04);
//  DiMuPtPlotPadh125->SetBottomMargin(0.04);
//  InvMassDiMuBarrOverPlotPadh125->SetBottomMargin(0.04);
//  InvMassDiMuEndcOverPlotPadh125->SetBottomMargin(0.04);
//  DiTauEtaPlotPadh125->SetBottomMargin(0.04);
//  DiTauPhiPlotPadh125->SetBottomMargin(0.04);
//  DiMuEtaPlotPadh125->SetBottomMargin(0.04);
//  DiMudRPlotPadh125->SetBottomMargin(0.04);
//  InvMassDiMuOverOverPlotPadh125->SetBottomMargin(0.04);
//  EtMETPlotPadh125->SetBottomMargin(0.04);
//  DiTauDiMuMassPlotPadh125->SetBottomMargin(0.04);
//  DiMuDiTauDeltaPhiPlotPadh125->SetBottomMargin(0.04);
//  METDiTauDeltaPhiPlotPadh125->SetBottomMargin(0.04);
//  METDiMuDeltaPhiPlotPadh125->SetBottomMargin(0.04);
//  DiTaudRPlotPadh125->SetBottomMargin(0.04);
//  DiTauMassSmallerdRPlotPadh125->SetBottomMargin(0.04);
//  HighestCSVInclJetPlotPadh125->SetBottomMargin(0.04);
  
  NMedIsoTausWithMu3PlotPadh125->SetRightMargin(0.03);
  InvMassTauHadMu3PlotPadh125->SetRightMargin(0.03);
  PtTauHadMu3PlotPadh125->SetRightMargin(0.03);
  InvMassMu2TauMuPlotPadh125->SetRightMargin(0.03);
  InvMassMu1TauMuPlotPadh125->SetRightMargin(0.03);
  InvMassFullRangePlotPadh125->SetRightMargin(0.03);
  InvMassDiMuBarrBarrPlotPadh125->SetRightMargin(0.03);
  InvMassDiMuBarrEndcPlotPadh125->SetRightMargin(0.03);
  InvMassDiMuEndcEndcPlotPadh125->SetRightMargin(0.03);
  Mu1PtPlotPadh125->SetRightMargin(0.03);
  Mu2PtPlotPadh125->SetRightMargin(0.03);
  DiMuPtPlotPadh125->SetRightMargin(0.03);
  InvMassDiMuBarrOverPlotPadh125->SetRightMargin(0.03);
  InvMassDiMuEndcOverPlotPadh125->SetRightMargin(0.03);
  DiTauEtaPlotPadh125->SetRightMargin(0.03);
  DiTauPhiPlotPadh125->SetRightMargin(0.03);
  DiMuEtaPlotPadh125->SetRightMargin(0.03);
  DiMudRPlotPadh125->SetRightMargin(0.03);
  InvMassDiMuOverOverPlotPadh125->SetRightMargin(0.03);
  EtMETPlotPadh125->SetRightMargin(0.03);
  DiTauDiMuMassPlotPadh125->SetRightMargin(0.03);
  DiMuDiTauDeltaPhiPlotPadh125->SetRightMargin(0.03);
  METDiTauDeltaPhiPlotPadh125->SetRightMargin(0.03);
  METDiMuDeltaPhiPlotPadh125->SetRightMargin(0.03);
  DiTaudRPlotPadh125->SetRightMargin(0.03);
  DiTauMassSmallerdRPlotPadh125->SetRightMargin(0.03);
  HighestCSVInclJetPlotPadh125->SetRightMargin(0.03);
  
  NMedIsoTausWithMu3Canvash125->cd();
  NMedIsoTausWithMu3PlotPadh125->Draw();
  InvMassTauHadMu3Canvash125->cd();
  InvMassTauHadMu3PlotPadh125->Draw();
  PtTauHadMu3Canvash125->cd();
  PtTauHadMu3PlotPadh125->Draw();
  InvMassMu2TauMuCanvash125->cd();
  InvMassMu2TauMuPlotPadh125->Draw();
  InvMassMu1TauMuCanvash125->cd();
  InvMassMu1TauMuPlotPadh125->Draw();
  InvMassFullRangeCanvash125->cd();
  InvMassFullRangePlotPadh125->Draw();
  InvMassDiMuBarrBarrCanvash125->cd();
  InvMassDiMuBarrBarrPlotPadh125->Draw();
  InvMassDiMuBarrEndcCanvash125->cd();
  InvMassDiMuBarrEndcPlotPadh125->Draw();
  InvMassDiMuEndcEndcCanvash125->cd();
  InvMassDiMuEndcEndcPlotPadh125->Draw();
  Mu1PtCanvash125->cd();
  Mu1PtPlotPadh125->Draw();
  Mu2PtCanvash125->cd();
  Mu2PtPlotPadh125->Draw();
  DiMuPtCanvash125->cd();
  DiMuPtPlotPadh125->Draw();
  InvMassDiMuBarrOverCanvash125->cd();
  InvMassDiMuBarrOverPlotPadh125->Draw();
  InvMassDiMuEndcOverCanvash125->cd();
  InvMassDiMuEndcOverPlotPadh125->Draw();
  DiTauEtaCanvash125->cd();
  DiTauEtaPlotPadh125->Draw();
  DiTauPhiCanvash125->cd();
  DiTauPhiPlotPadh125->Draw();
  DiMuEtaCanvash125->cd();
  DiMuEtaPlotPadh125->Draw();
  DiMudRCanvash125->cd();
  DiMudRPlotPadh125->Draw();
  InvMassDiMuOverOverCanvash125->cd();
  InvMassDiMuOverOverPlotPadh125->Draw();
  EtMETCanvash125->cd();
  EtMETPlotPadh125->Draw();
  DiTauDiMuMassCanvash125->cd();
  DiTauDiMuMassPlotPadh125->Draw();
  DiMuDiTauDeltaPhiCanvash125->cd();
  DiMuDiTauDeltaPhiPlotPadh125->Draw();
  METDiTauDeltaPhiCanvash125->cd();
  METDiTauDeltaPhiPlotPadh125->Draw();
  METDiMuDeltaPhiCanvash125->cd();
  METDiMuDeltaPhiPlotPadh125->Draw();
  DiTaudRCanvash125->cd();
  DiTaudRPlotPadh125->Draw();
  DiTauMassSmallerdRCanvash125->cd();
  DiTauMassSmallerdRPlotPadh125->Draw();
  HighestCSVInclJetCanvash125->cd();
  HighestCSVInclJetPlotPadh125->Draw();
  
  NMedIsoTausWithMu3PlotPadh125->SetLogy(true);
  InvMassTauHadMu3PlotPadh125->SetLogy(true);
  PtTauHadMu3PlotPadh125->SetLogy(true);
  InvMassMu2TauMuPlotPadh125->SetLogy(true);
  InvMassMu1TauMuPlotPadh125->SetLogy(true);
  InvMassFullRangePlotPadh125->SetLogy(true);
  InvMassDiMuBarrBarrPlotPadh125->SetLogy(true);
  InvMassDiMuBarrEndcPlotPadh125->SetLogy(true);
  InvMassDiMuEndcEndcPlotPadh125->SetLogy(true);
  Mu1PtPlotPadh125->SetLogy(true);
  Mu2PtPlotPadh125->SetLogy(true);
  DiMuPtPlotPadh125->SetLogy(true);
  InvMassDiMuBarrOverPlotPadh125->SetLogy(true);
  InvMassDiMuEndcOverPlotPadh125->SetLogy(true);
  DiTauEtaPlotPadh125->SetLogy(true);
  DiTauPhiPlotPadh125->SetLogy(true);
  DiMuEtaPlotPadh125->SetLogy(true);
  DiMudRPlotPadh125->SetLogy(true);
  InvMassDiMuOverOverPlotPadh125->SetLogy(true);
  EtMETPlotPadh125->SetLogy(true);
  DiTauDiMuMassPlotPadh125->SetLogy(true);
  DiMuDiTauDeltaPhiPlotPadh125->SetLogy(true);
  METDiTauDeltaPhiPlotPadh125->SetLogy(true);
  METDiMuDeltaPhiPlotPadh125->SetLogy(true);
  DiTaudRPlotPadh125->SetLogy(true);
  DiTauMassSmallerdRPlotPadh125->SetLogy(true);
  HighestCSVInclJetPlotPadh125->SetLogy(true);
  
  NMedIsoTausWithMu3PlotPadh125->SetLogx(false);
  InvMassTauHadMu3PlotPadh125->SetLogx(false);
  PtTauHadMu3PlotPadh125->SetLogx(false);
  InvMassMu2TauMuPlotPadh125->SetLogx(false);
  InvMassMu1TauMuPlotPadh125->SetLogx(false);
  InvMassFullRangePlotPadh125->SetLogx(false);
  InvMassDiMuBarrBarrPlotPadh125->SetLogx(false);
  InvMassDiMuBarrEndcPlotPadh125->SetLogx(false);
  InvMassDiMuEndcEndcPlotPadh125->SetLogx(false);
  Mu1PtPlotPadh125->SetLogx(false);
  Mu2PtPlotPadh125->SetLogx(false);
  DiMuPtPlotPadh125->SetLogx(false);
  InvMassDiMuBarrOverPlotPadh125->SetLogx(false);
  InvMassDiMuEndcOverPlotPadh125->SetLogx(false);
  DiTauEtaPlotPadh125->SetLogx(false);
  DiTauPhiPlotPadh125->SetLogx(false);
  DiMuEtaPlotPadh125->SetLogx(false);
  DiMudRPlotPadh125->SetLogx(false);
  InvMassDiMuOverOverPlotPadh125->SetLogx(false);
  EtMETPlotPadh125->SetLogx(false);
  DiTauDiMuMassPlotPadh125->SetLogx(false);
  DiMuDiTauDeltaPhiPlotPadh125->SetLogx(false);
  METDiTauDeltaPhiPlotPadh125->SetLogx(false);
  METDiMuDeltaPhiPlotPadh125->SetLogx(false);
  DiTaudRPlotPadh125->SetLogx(false);
  DiTauMassSmallerdRPlotPadh125->SetLogx(false);
  HighestCSVInclJetPlotPadh125->SetLogx(false);
 
  
cout << "Created the Output Pads" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Legends
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  legend = new TLegend(0.7,0.5,0.95,0.575) ;
  legend->SetTextFont(42);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
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
// Drawing the stateerr and the data
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  NMedIsoTausWithMu3PlotPadh125->cd();
  NMedIsoTausWithMu3h125a5_->Draw("HIST");
  NMedIsoTausWithMu3h125a7_->Draw("HIST SAME");
  NMedIsoTausWithMu3h125a9_->Draw("HIST SAME");
  NMedIsoTausWithMu3h125a11_->Draw("HIST SAME");
  NMedIsoTausWithMu3h125a13_->Draw("HIST SAME");
  NMedIsoTausWithMu3h125a15_->Draw("HIST SAME");
  NMedIsoTausWithMu3h125a17_->Draw("HIST SAME");
  NMedIsoTausWithMu3h125a19_->Draw("HIST SAME");
  NMedIsoTausWithMu3h125a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassTauHadMu3PlotPadh125->cd();
  InvMassTauHadMu3h125a5_->Draw("HIST");
  InvMassTauHadMu3h125a7_->Draw("HIST SAME");
  InvMassTauHadMu3h125a9_->Draw("HIST SAME");
  InvMassTauHadMu3h125a11_->Draw("HIST SAME");
  InvMassTauHadMu3h125a13_->Draw("HIST SAME");
  InvMassTauHadMu3h125a15_->Draw("HIST SAME");
  InvMassTauHadMu3h125a17_->Draw("HIST SAME");
  InvMassTauHadMu3h125a19_->Draw("HIST SAME");
  InvMassTauHadMu3h125a21_->Draw("HIST SAME");
  legend->Draw();

  PtTauHadMu3PlotPadh125->cd();
  PtTauHadMu3h125a5_->Draw("HIST");
  PtTauHadMu3h125a7_->Draw("HIST SAME");
  PtTauHadMu3h125a9_->Draw("HIST SAME");
  PtTauHadMu3h125a11_->Draw("HIST SAME");
  PtTauHadMu3h125a13_->Draw("HIST SAME");
  PtTauHadMu3h125a15_->Draw("HIST SAME");
  PtTauHadMu3h125a17_->Draw("HIST SAME");
  PtTauHadMu3h125a19_->Draw("HIST SAME");
  PtTauHadMu3h125a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassMu2TauMuPlotPadh125->cd();
  InvMassMu2TauMuh125a5_->Draw("HIST");
  InvMassMu2TauMuh125a7_->Draw("HIST SAME");
  InvMassMu2TauMuh125a9_->Draw("HIST SAME");
  InvMassMu2TauMuh125a11_->Draw("HIST SAME");
  InvMassMu2TauMuh125a13_->Draw("HIST SAME");
  InvMassMu2TauMuh125a15_->Draw("HIST SAME");
  InvMassMu2TauMuh125a17_->Draw("HIST SAME");
  InvMassMu2TauMuh125a19_->Draw("HIST SAME");
  InvMassMu2TauMuh125a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassMu1TauMuPlotPadh125->cd();
  InvMassMu1TauMuh125a5_->Draw("HIST");
  InvMassMu1TauMuh125a7_->Draw("HIST SAME");
  InvMassMu1TauMuh125a9_->Draw("HIST SAME");
  InvMassMu1TauMuh125a11_->Draw("HIST SAME");
  InvMassMu1TauMuh125a13_->Draw("HIST SAME");
  InvMassMu1TauMuh125a15_->Draw("HIST SAME");
  InvMassMu1TauMuh125a17_->Draw("HIST SAME");
  InvMassMu1TauMuh125a19_->Draw("HIST SAME");
  InvMassMu1TauMuh125a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassFullRangePlotPadh125->cd();
  InvMassFullRangeh125a5_->Draw("HIST");
  InvMassFullRangeh125a7_->Draw("HIST SAME");
  InvMassFullRangeh125a9_->Draw("HIST SAME");
  InvMassFullRangeh125a11_->Draw("HIST SAME");
  InvMassFullRangeh125a13_->Draw("HIST SAME");
  InvMassFullRangeh125a15_->Draw("HIST SAME");
  InvMassFullRangeh125a17_->Draw("HIST SAME");
  InvMassFullRangeh125a19_->Draw("HIST SAME");
  InvMassFullRangeh125a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuBarrBarrPlotPadh125->cd();
  InvMassDiMuBarrBarrh125a5_->Draw("HIST");
  InvMassDiMuBarrBarrh125a7_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh125a9_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh125a11_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh125a13_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh125a15_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh125a17_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh125a19_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh125a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuBarrEndcPlotPadh125->cd();
  InvMassDiMuBarrEndch125a5_->Draw("HIST");
  InvMassDiMuBarrEndch125a7_->Draw("HIST SAME");
  InvMassDiMuBarrEndch125a9_->Draw("HIST SAME");
  InvMassDiMuBarrEndch125a11_->Draw("HIST SAME");
  InvMassDiMuBarrEndch125a13_->Draw("HIST SAME");
  InvMassDiMuBarrEndch125a15_->Draw("HIST SAME");
  InvMassDiMuBarrEndch125a17_->Draw("HIST SAME");
  InvMassDiMuBarrEndch125a19_->Draw("HIST SAME");
  InvMassDiMuBarrEndch125a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuEndcEndcPlotPadh125->cd();
  InvMassDiMuEndcEndch125a5_->Draw("HIST");
  InvMassDiMuEndcEndch125a7_->Draw("HIST SAME");
  InvMassDiMuEndcEndch125a9_->Draw("HIST SAME");
  InvMassDiMuEndcEndch125a11_->Draw("HIST SAME");
  InvMassDiMuEndcEndch125a13_->Draw("HIST SAME");
  InvMassDiMuEndcEndch125a15_->Draw("HIST SAME");
  InvMassDiMuEndcEndch125a17_->Draw("HIST SAME");
  InvMassDiMuEndcEndch125a19_->Draw("HIST SAME");
  InvMassDiMuEndcEndch125a21_->Draw("HIST SAME");
  legend->Draw();

  Mu1PtPlotPadh125->cd();
  Mu1Pth125a5_->Draw("HIST");
  Mu1Pth125a7_->Draw("HIST SAME");
  Mu1Pth125a9_->Draw("HIST SAME");
  Mu1Pth125a11_->Draw("HIST SAME");
  Mu1Pth125a13_->Draw("HIST SAME");
  Mu1Pth125a15_->Draw("HIST SAME");
  Mu1Pth125a17_->Draw("HIST SAME");
  Mu1Pth125a19_->Draw("HIST SAME");
  Mu1Pth125a21_->Draw("HIST SAME");
  legend->Draw();

  Mu2PtPlotPadh125->cd();
  Mu2Pth125a5_->Draw("HIST");
  Mu2Pth125a7_->Draw("HIST SAME");
  Mu2Pth125a9_->Draw("HIST SAME");
  Mu2Pth125a11_->Draw("HIST SAME");
  Mu2Pth125a13_->Draw("HIST SAME");
  Mu2Pth125a15_->Draw("HIST SAME");
  Mu2Pth125a17_->Draw("HIST SAME");
  Mu2Pth125a19_->Draw("HIST SAME");
  Mu2Pth125a21_->Draw("HIST SAME");

  DiMuPtPlotPadh125->cd();
  DiMuPth125a5_->Draw("HIST");
  DiMuPth125a7_->Draw("HIST SAME");
  DiMuPth125a9_->Draw("HIST SAME");
  DiMuPth125a11_->Draw("HIST SAME");
  DiMuPth125a13_->Draw("HIST SAME");
  DiMuPth125a15_->Draw("HIST SAME");
  DiMuPth125a17_->Draw("HIST SAME");
  DiMuPth125a19_->Draw("HIST SAME");
  DiMuPth125a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuBarrOverPlotPadh125->cd();
  InvMassDiMuBarrOverh125a5_->Draw("HIST");
  InvMassDiMuBarrOverh125a7_->Draw("HIST SAME");
  InvMassDiMuBarrOverh125a9_->Draw("HIST SAME");
  InvMassDiMuBarrOverh125a11_->Draw("HIST SAME");
  InvMassDiMuBarrOverh125a13_->Draw("HIST SAME");
  InvMassDiMuBarrOverh125a15_->Draw("HIST SAME");
  InvMassDiMuBarrOverh125a17_->Draw("HIST SAME");
  InvMassDiMuBarrOverh125a19_->Draw("HIST SAME");
  InvMassDiMuBarrOverh125a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuEndcOverPlotPadh125->cd();
  InvMassDiMuEndcOverh125a5_->Draw("HIST");
  InvMassDiMuEndcOverh125a7_->Draw("HIST SAME");
  InvMassDiMuEndcOverh125a9_->Draw("HIST SAME");
  InvMassDiMuEndcOverh125a11_->Draw("HIST SAME");
  InvMassDiMuEndcOverh125a13_->Draw("HIST SAME");
  InvMassDiMuEndcOverh125a15_->Draw("HIST SAME");
  InvMassDiMuEndcOverh125a17_->Draw("HIST SAME");
  InvMassDiMuEndcOverh125a19_->Draw("HIST SAME");
  InvMassDiMuEndcOverh125a21_->Draw("HIST SAME");

  DiTauEtaPlotPadh125->cd();
  DiTauEtah125a5_->Draw("HIST");
  DiTauEtah125a7_->Draw("HIST SAME");
  DiTauEtah125a9_->Draw("HIST SAME");
  DiTauEtah125a11_->Draw("HIST SAME");
  DiTauEtah125a13_->Draw("HIST SAME");
  DiTauEtah125a15_->Draw("HIST SAME");
  DiTauEtah125a17_->Draw("HIST SAME");
  DiTauEtah125a19_->Draw("HIST SAME");
  DiTauEtah125a21_->Draw("HIST SAME");
  legend->Draw();

  DiTauPhiPlotPadh125->cd();
  DiTauPhih125a5_->Draw("HIST");
  DiTauPhih125a7_->Draw("HIST SAME");
  DiTauPhih125a9_->Draw("HIST SAME");
  DiTauPhih125a11_->Draw("HIST SAME");
  DiTauPhih125a13_->Draw("HIST SAME");
  DiTauPhih125a15_->Draw("HIST SAME");
  DiTauPhih125a17_->Draw("HIST SAME");
  DiTauPhih125a19_->Draw("HIST SAME");
  DiTauPhih125a21_->Draw("HIST SAME");
  legend->Draw();

  DiMuEtaPlotPadh125->cd();
  DiMuEtah125a5_->Draw("HIST");
  DiMuEtah125a7_->Draw("HIST SAME");
  DiMuEtah125a9_->Draw("HIST SAME");
  DiMuEtah125a11_->Draw("HIST SAME");
  DiMuEtah125a13_->Draw("HIST SAME");
  DiMuEtah125a15_->Draw("HIST SAME");
  DiMuEtah125a17_->Draw("HIST SAME");
  DiMuEtah125a19_->Draw("HIST SAME");
  DiMuEtah125a21_->Draw("HIST SAME");
  legend->Draw();

  DiMudRPlotPadh125->cd();
  DiMudRh125a5_->Draw("HIST");
  DiMudRh125a7_->Draw("HIST SAME");
  DiMudRh125a9_->Draw("HIST SAME");
  DiMudRh125a11_->Draw("HIST SAME");
  DiMudRh125a13_->Draw("HIST SAME");
  DiMudRh125a15_->Draw("HIST SAME");
  DiMudRh125a17_->Draw("HIST SAME");
  DiMudRh125a19_->Draw("HIST SAME");
  DiMudRh125a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuOverOverPlotPadh125->cd();
  InvMassDiMuOverOverh125a5_->Draw("HIST");
  InvMassDiMuOverOverh125a7_->Draw("HIST SAME");
  InvMassDiMuOverOverh125a9_->Draw("HIST SAME");
  InvMassDiMuOverOverh125a11_->Draw("HIST SAME");
  InvMassDiMuOverOverh125a13_->Draw("HIST SAME");
  InvMassDiMuOverOverh125a15_->Draw("HIST SAME");
  InvMassDiMuOverOverh125a17_->Draw("HIST SAME");
  InvMassDiMuOverOverh125a19_->Draw("HIST SAME");
  InvMassDiMuOverOverh125a21_->Draw("HIST SAME");
  legend->Draw();

  EtMETPlotPadh125->cd();
  EtMETh125a5_->Draw("HIST");
  EtMETh125a7_->Draw("HIST SAME");
  EtMETh125a9_->Draw("HIST SAME");
  EtMETh125a11_->Draw("HIST SAME");
  EtMETh125a13_->Draw("HIST SAME");
  EtMETh125a15_->Draw("HIST SAME");
  EtMETh125a17_->Draw("HIST SAME");
  EtMETh125a19_->Draw("HIST SAME");
  EtMETh125a21_->Draw("HIST SAME");
  legend->Draw();

  DiTauDiMuMassPlotPadh125->cd();
  DiTauDiMuMassh125a5_->Draw("HIST");
  DiTauDiMuMassh125a7_->Draw("HIST SAME");
  DiTauDiMuMassh125a9_->Draw("HIST SAME");
  DiTauDiMuMassh125a11_->Draw("HIST SAME");
  DiTauDiMuMassh125a13_->Draw("HIST SAME");
  DiTauDiMuMassh125a15_->Draw("HIST SAME");
  DiTauDiMuMassh125a17_->Draw("HIST SAME");
  DiTauDiMuMassh125a19_->Draw("HIST SAME");
  DiTauDiMuMassh125a21_->Draw("HIST SAME");
  legend->Draw();

  DiMuDiTauDeltaPhiPlotPadh125->cd();
  DiMuDiTauDeltaPhih125a5_->Draw("HIST");
  DiMuDiTauDeltaPhih125a7_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih125a9_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih125a11_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih125a13_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih125a15_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih125a17_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih125a19_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih125a21_->Draw("HIST SAME");
  legend->Draw();

  METDiTauDeltaPhiPlotPadh125->cd();
  METDiTauDeltaPhih125a5_->Draw("HIST");
  METDiTauDeltaPhih125a7_->Draw("HIST SAME");
  METDiTauDeltaPhih125a9_->Draw("HIST SAME");
  METDiTauDeltaPhih125a11_->Draw("HIST SAME");
  METDiTauDeltaPhih125a13_->Draw("HIST SAME");
  METDiTauDeltaPhih125a15_->Draw("HIST SAME");
  METDiTauDeltaPhih125a17_->Draw("HIST SAME");
  METDiTauDeltaPhih125a19_->Draw("HIST SAME");
  METDiTauDeltaPhih125a21_->Draw("HIST SAME");
  legend->Draw();

  METDiMuDeltaPhiPlotPadh125->cd();
  METDiMuDeltaPhih125a5_->Draw("HIST");
  METDiMuDeltaPhih125a7_->Draw("HIST SAME");
  METDiMuDeltaPhih125a9_->Draw("HIST SAME");
  METDiMuDeltaPhih125a11_->Draw("HIST SAME");
  METDiMuDeltaPhih125a13_->Draw("HIST SAME");
  METDiMuDeltaPhih125a15_->Draw("HIST SAME");
  METDiMuDeltaPhih125a17_->Draw("HIST SAME");
  METDiMuDeltaPhih125a19_->Draw("HIST SAME");
  METDiMuDeltaPhih125a21_->Draw("HIST SAME");
  legend->Draw();

  DiTaudRPlotPadh125->cd();
  DiTaudRh125a5_->Draw("HIST");
  DiTaudRh125a7_->Draw("HIST SAME");
  DiTaudRh125a9_->Draw("HIST SAME");
  DiTaudRh125a11_->Draw("HIST SAME");
  DiTaudRh125a13_->Draw("HIST SAME");
  DiTaudRh125a15_->Draw("HIST SAME");
  DiTaudRh125a17_->Draw("HIST SAME");
  DiTaudRh125a19_->Draw("HIST SAME");
  DiTaudRh125a21_->Draw("HIST SAME");
  legend->Draw();

  DiTauMassSmallerdRPlotPadh125->cd();
  DiTauMassSmallerdRh125a5_->Draw("HIST");
  DiTauMassSmallerdRh125a7_->Draw("HIST SAME");
  DiTauMassSmallerdRh125a9_->Draw("HIST SAME");
  DiTauMassSmallerdRh125a11_->Draw("HIST SAME");
  DiTauMassSmallerdRh125a13_->Draw("HIST SAME");
  DiTauMassSmallerdRh125a15_->Draw("HIST SAME");
  DiTauMassSmallerdRh125a17_->Draw("HIST SAME");
  DiTauMassSmallerdRh125a19_->Draw("HIST SAME");
  DiTauMassSmallerdRh125a21_->Draw("HIST SAME");
  legend->Draw();

  HighestCSVInclJetPlotPadh125->cd();
  HighestCSVInclJeth125a5_->Draw("HIST");
  HighestCSVInclJeth125a7_->Draw("HIST SAME");
  HighestCSVInclJeth125a9_->Draw("HIST SAME");
  HighestCSVInclJeth125a11_->Draw("HIST SAME");
  HighestCSVInclJeth125a13_->Draw("HIST SAME");
  HighestCSVInclJeth125a15_->Draw("HIST SAME");
  HighestCSVInclJeth125a17_->Draw("HIST SAME");
  HighestCSVInclJeth125a19_->Draw("HIST SAME");
  HighestCSVInclJeth125a21_->Draw("HIST SAME");
  legend->Draw();

cout << "Got StatErr" << endl;

  TCanvas *NMedIsoTausWithMu3Canvash300 = new TCanvas ("NMedIsoTausWithMu3Canvash300","",600,600);
  TCanvas *InvMassTauHadMu3Canvash300 = new TCanvas ("InvMassTauHadMu3Canvash300","",600,600);
  TCanvas *PtTauHadMu3Canvash300 = new TCanvas ("PtTauHadMu3Canvash300","",600,600);
  TCanvas *InvMassMu2TauMuCanvash300 = new TCanvas ("InvMassMu2TauMuCanvash300","",600,600);
  TCanvas *InvMassFullRangeCanvash300 = new TCanvas ("InvMassFullRangeCanvash300","",600,600);
  TCanvas *InvMassMu1TauMuCanvash300 = new TCanvas ("InvMassMu1TauMuCanvash300","",600,600);
  TCanvas *InvMassDiMuBarrBarrCanvash300 = new TCanvas ("InvMassDiMuBarrBarrCanvash300","",600,600);
  TCanvas *InvMassDiMuBarrEndcCanvash300 = new TCanvas ("InvMassDiMuBarrEndcCanvash300","",600,600);
  TCanvas *InvMassDiMuEndcEndcCanvash300 = new TCanvas ("InvMassDiMuEndcEndcCanvash300","",600,600);
  TCanvas *Mu1PtCanvash300 = new TCanvas ("Mu1PtCanvash300","",600,600);
  TCanvas *Mu2PtCanvash300 = new TCanvas ("Mu2PtCanvash300","",600,600);
  TCanvas *DiMuPtCanvash300 = new TCanvas ("DiMuPtCanvash300","",600,600);
  TCanvas *InvMassDiMuBarrOverCanvash300 = new TCanvas ("InvMassDiMuBarrOverCanvash300","",600,600);
  TCanvas *InvMassDiMuEndcOverCanvash300 = new TCanvas ("InvMassDiMuEndcOverCanvash300","",600,600);
  TCanvas *DiTauEtaCanvash300 = new TCanvas ("DiTauEtaCanvash300","",600,600);
  TCanvas *DiTauPhiCanvash300 = new TCanvas ("DiTauPhiCanvash300","",600,600);
  TCanvas *DiMuEtaCanvash300 = new TCanvas ("DiMuEtaCanvash300","",600,600);
  TCanvas *DiMudRCanvash300 = new TCanvas ("DiMudRCanvash300","",600,600);
  TCanvas *InvMassDiMuOverOverCanvash300 = new TCanvas ("InvMassDiMuOverOverCanvash300","",600,600);
  TCanvas *EtMETCanvash300 = new TCanvas ("EtMETCanvash300","",600,600);
  TCanvas *DiTauDiMuMassCanvash300 = new TCanvas ("DiTauDiMuMassCanvash300","",600,600);
  TCanvas *DiMuDiTauDeltaPhiCanvash300 = new TCanvas ("DiMuDiTauDeltaPhiCanvash300","",600,600);
  TCanvas *METDiTauDeltaPhiCanvash300 = new TCanvas ("METDiTauDeltaPhiCanvash300","",600,600);
  TCanvas *METDiMuDeltaPhiCanvash300 = new TCanvas ("METDiMuDeltaPhiCanvash300","",600,600);
  TCanvas *DiTaudRCanvash300 = new TCanvas ("DiTaudRCanvash300","",600,600);
  TCanvas *DiTauMassSmallerdRCanvash300 = new TCanvas ("DiTauMassSmallerdRCanvash300","",600,600);
  TCanvas *HighestCSVInclJetCanvash300 = new TCanvas ("HighestCSVInclJetCanvash300","",600,600);

  TPad *NMedIsoTausWithMu3PlotPadh300 = new TPad ("NMedIsoTausWithMu3PlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassTauHadMu3PlotPadh300 = new TPad ("InvMassTauHadMu3PlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *PtTauHadMu3PlotPadh300 = new TPad ("PtTauHadMu3PlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassMu2TauMuPlotPadh300 = new TPad ("InvMassMu2TauMuPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassFullRangePlotPadh300 = new TPad ("InvMassFullRangePlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassMu1TauMuPlotPadh300 = new TPad ("InvMassMu1TauMuPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuBarrBarrPlotPadh300 = new TPad ("InvMassDiMuBarrBarrPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuBarrEndcPlotPadh300 = new TPad ("InvMassDiMuBarrEndcPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuEndcEndcPlotPadh300 = new TPad ("InvMassDiMuEndcEndcPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *Mu1PtPlotPadh300 = new TPad ("Mu1PtPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *Mu2PtPlotPadh300 = new TPad ("Mu2PtPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuPtPlotPadh300 = new TPad ("DiMuPtPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuBarrOverPlotPadh300 = new TPad ("InvMassDiMuBarrOverPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuEndcOverPlotPadh300 = new TPad ("InvMassDiMuEndcOverPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauEtaPlotPadh300 = new TPad ("DiTauEtaPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauPhiPlotPadh300 = new TPad ("DiTauPhiPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuEtaPlotPadh300 = new TPad ("DiMuEtaPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMudRPlotPadh300 = new TPad ("DiMudRPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuOverOverPlotPadh300 = new TPad ("InvMassDiMuOverOverPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *EtMETPlotPadh300 = new TPad ("EtMETPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauDiMuMassPlotPadh300 = new TPad ("DiTauDiMuMassPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuDiTauDeltaPhiPlotPadh300 = new TPad ("DiMuDiTauDeltaPhiPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *METDiTauDeltaPhiPlotPadh300 = new TPad ("METDiTauDeltaPhiPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *METDiMuDeltaPhiPlotPadh300 = new TPad ("METDiMuDeltaPhiPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTaudRPlotPadh300 = new TPad ("DiTaudRPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauMassSmallerdRPlotPadh300 = new TPad ("DiTauMassSmallerdRPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *HighestCSVInclJetPlotPadh300 = new TPad ("HighestCSVInclJetPlotPadh300", "top pad", 0.0, 0.21, 1.0, 1.0);

//  NMedIsoTausWithMu3PlotPadh300->SetBottomMargin(0.04);
//  InvMassTauHadMu3PlotPadh300->SetBottomMargin(0.04);
//  PtTauHadMu3PlotPadh300->SetBottomMargin(0.04);
//  InvMassMu2TauMuPlotPadh300->SetBottomMargin(0.04);
//  InvMassMu1TauMuPlotPadh300->SetBottomMargin(0.04);
//  InvMassFullRangePlotPadh300->SetBottomMargin(0.04);
//  InvMassDiMuBarrBarrPlotPadh300->SetBottomMargin(0.04);
//  InvMassDiMuBarrEndcPlotPadh300->SetBottomMargin(0.04);
//  InvMassDiMuEndcEndcPlotPadh300->SetBottomMargin(0.04);
//  Mu1PtPlotPadh300->SetBottomMargin(0.04);
//  Mu2PtPlotPadh300->SetBottomMargin(0.04);
//  DiMuPtPlotPadh300->SetBottomMargin(0.04);
//  InvMassDiMuBarrOverPlotPadh300->SetBottomMargin(0.04);
//  InvMassDiMuEndcOverPlotPadh300->SetBottomMargin(0.04);
//  DiTauEtaPlotPadh300->SetBottomMargin(0.04);
//  DiTauPhiPlotPadh300->SetBottomMargin(0.04);
//  DiMuEtaPlotPadh300->SetBottomMargin(0.04);
//  DiMudRPlotPadh300->SetBottomMargin(0.04);
//  InvMassDiMuOverOverPlotPadh300->SetBottomMargin(0.04);
//  EtMETPlotPadh300->SetBottomMargin(0.04);
//  DiTauDiMuMassPlotPadh300->SetBottomMargin(0.04);
//  DiMuDiTauDeltaPhiPlotPadh300->SetBottomMargin(0.04);
//  METDiTauDeltaPhiPlotPadh300->SetBottomMargin(0.04);
//  METDiMuDeltaPhiPlotPadh300->SetBottomMargin(0.04);
//  DiTaudRPlotPadh300->SetBottomMargin(0.04);
//  DiTauMassSmallerdRPlotPadh300->SetBottomMargin(0.04);
//  HighestCSVInclJetPlotPadh300->SetBottomMargin(0.04);
  
  NMedIsoTausWithMu3PlotPadh300->SetRightMargin(0.03);
  InvMassTauHadMu3PlotPadh300->SetRightMargin(0.03);
  PtTauHadMu3PlotPadh300->SetRightMargin(0.03);
  InvMassMu2TauMuPlotPadh300->SetRightMargin(0.03);
  InvMassMu1TauMuPlotPadh300->SetRightMargin(0.03);
  InvMassFullRangePlotPadh300->SetRightMargin(0.03);
  InvMassDiMuBarrBarrPlotPadh300->SetRightMargin(0.03);
  InvMassDiMuBarrEndcPlotPadh300->SetRightMargin(0.03);
  InvMassDiMuEndcEndcPlotPadh300->SetRightMargin(0.03);
  Mu1PtPlotPadh300->SetRightMargin(0.03);
  Mu2PtPlotPadh300->SetRightMargin(0.03);
  DiMuPtPlotPadh300->SetRightMargin(0.03);
  InvMassDiMuBarrOverPlotPadh300->SetRightMargin(0.03);
  InvMassDiMuEndcOverPlotPadh300->SetRightMargin(0.03);
  DiTauEtaPlotPadh300->SetRightMargin(0.03);
  DiTauPhiPlotPadh300->SetRightMargin(0.03);
  DiMuEtaPlotPadh300->SetRightMargin(0.03);
  DiMudRPlotPadh300->SetRightMargin(0.03);
  InvMassDiMuOverOverPlotPadh300->SetRightMargin(0.03);
  EtMETPlotPadh300->SetRightMargin(0.03);
  DiTauDiMuMassPlotPadh300->SetRightMargin(0.03);
  DiMuDiTauDeltaPhiPlotPadh300->SetRightMargin(0.03);
  METDiTauDeltaPhiPlotPadh300->SetRightMargin(0.03);
  METDiMuDeltaPhiPlotPadh300->SetRightMargin(0.03);
  DiTaudRPlotPadh300->SetRightMargin(0.03);
  DiTauMassSmallerdRPlotPadh300->SetRightMargin(0.03);
  HighestCSVInclJetPlotPadh300->SetRightMargin(0.03);
  
  NMedIsoTausWithMu3Canvash300->cd();
  NMedIsoTausWithMu3PlotPadh300->Draw();
  InvMassTauHadMu3Canvash300->cd();
  InvMassTauHadMu3PlotPadh300->Draw();
  PtTauHadMu3Canvash300->cd();
  PtTauHadMu3PlotPadh300->Draw();
  InvMassMu2TauMuCanvash300->cd();
  InvMassMu2TauMuPlotPadh300->Draw();
  InvMassMu1TauMuCanvash300->cd();
  InvMassMu1TauMuPlotPadh300->Draw();
  InvMassFullRangeCanvash300->cd();
  InvMassFullRangePlotPadh300->Draw();
  InvMassDiMuBarrBarrCanvash300->cd();
  InvMassDiMuBarrBarrPlotPadh300->Draw();
  InvMassDiMuBarrEndcCanvash300->cd();
  InvMassDiMuBarrEndcPlotPadh300->Draw();
  InvMassDiMuEndcEndcCanvash300->cd();
  InvMassDiMuEndcEndcPlotPadh300->Draw();
  Mu1PtCanvash300->cd();
  Mu1PtPlotPadh300->Draw();
  Mu2PtCanvash300->cd();
  Mu2PtPlotPadh300->Draw();
  DiMuPtCanvash300->cd();
  DiMuPtPlotPadh300->Draw();
  InvMassDiMuBarrOverCanvash300->cd();
  InvMassDiMuBarrOverPlotPadh300->Draw();
  InvMassDiMuEndcOverCanvash300->cd();
  InvMassDiMuEndcOverPlotPadh300->Draw();
  DiTauEtaCanvash300->cd();
  DiTauEtaPlotPadh300->Draw();
  DiTauPhiCanvash300->cd();
  DiTauPhiPlotPadh300->Draw();
  DiMuEtaCanvash300->cd();
  DiMuEtaPlotPadh300->Draw();
  DiMudRCanvash300->cd();
  DiMudRPlotPadh300->Draw();
  InvMassDiMuOverOverCanvash300->cd();
  InvMassDiMuOverOverPlotPadh300->Draw();
  EtMETCanvash300->cd();
  EtMETPlotPadh300->Draw();
  DiTauDiMuMassCanvash300->cd();
  DiTauDiMuMassPlotPadh300->Draw();
  DiMuDiTauDeltaPhiCanvash300->cd();
  DiMuDiTauDeltaPhiPlotPadh300->Draw();
  METDiTauDeltaPhiCanvash300->cd();
  METDiTauDeltaPhiPlotPadh300->Draw();
  METDiMuDeltaPhiCanvash300->cd();
  METDiMuDeltaPhiPlotPadh300->Draw();
  DiTaudRCanvash300->cd();
  DiTaudRPlotPadh300->Draw();
  DiTauMassSmallerdRCanvash300->cd();
  DiTauMassSmallerdRPlotPadh300->Draw();
  HighestCSVInclJetCanvash300->cd();
  HighestCSVInclJetPlotPadh300->Draw();

  NMedIsoTausWithMu3PlotPadh300->SetLogy(true);
  InvMassTauHadMu3PlotPadh300->SetLogy(true);
  PtTauHadMu3PlotPadh300->SetLogy(true);
  InvMassMu2TauMuPlotPadh300->SetLogy(true);
  InvMassMu1TauMuPlotPadh300->SetLogy(true);
  InvMassFullRangePlotPadh300->SetLogy(true);
  InvMassDiMuBarrBarrPlotPadh300->SetLogy(true);
  InvMassDiMuBarrEndcPlotPadh300->SetLogy(true);
  InvMassDiMuEndcEndcPlotPadh300->SetLogy(true);
  Mu1PtPlotPadh300->SetLogy(true);
  Mu2PtPlotPadh300->SetLogy(true);
  DiMuPtPlotPadh300->SetLogy(true);
  InvMassDiMuBarrOverPlotPadh300->SetLogy(true);
  InvMassDiMuEndcOverPlotPadh300->SetLogy(true);
  DiTauEtaPlotPadh300->SetLogy(true);
  DiTauPhiPlotPadh300->SetLogy(true);
  DiMuEtaPlotPadh300->SetLogy(true);
  DiMudRPlotPadh300->SetLogy(true);
  InvMassDiMuOverOverPlotPadh300->SetLogy(true);
  EtMETPlotPadh300->SetLogy(true);
  DiTauDiMuMassPlotPadh300->SetLogy(true);
  DiMuDiTauDeltaPhiPlotPadh300->SetLogy(true);
  METDiTauDeltaPhiPlotPadh300->SetLogy(true);
  METDiMuDeltaPhiPlotPadh300->SetLogy(true);
  DiTaudRPlotPadh300->SetLogy(true);
  DiTauMassSmallerdRPlotPadh300->SetLogy(true);
  HighestCSVInclJetPlotPadh300->SetLogy(true);
  
  NMedIsoTausWithMu3PlotPadh300->SetLogx(false);
  InvMassTauHadMu3PlotPadh300->SetLogx(false);
  PtTauHadMu3PlotPadh300->SetLogx(false);
  InvMassMu2TauMuPlotPadh300->SetLogx(false);
  InvMassMu1TauMuPlotPadh300->SetLogx(false);
  InvMassFullRangePlotPadh300->SetLogx(false);
  InvMassDiMuBarrBarrPlotPadh300->SetLogx(false);
  InvMassDiMuBarrEndcPlotPadh300->SetLogx(false);
  InvMassDiMuEndcEndcPlotPadh300->SetLogx(false);
  Mu1PtPlotPadh300->SetLogx(false);
  Mu2PtPlotPadh300->SetLogx(false);
  DiMuPtPlotPadh300->SetLogx(false);
  InvMassDiMuBarrOverPlotPadh300->SetLogx(false);
  InvMassDiMuEndcOverPlotPadh300->SetLogx(false);
  DiTauEtaPlotPadh300->SetLogx(false);
  DiTauPhiPlotPadh300->SetLogx(false);
  DiMuEtaPlotPadh300->SetLogx(false);
  DiMudRPlotPadh300->SetLogx(false);
  InvMassDiMuOverOverPlotPadh300->SetLogx(false);
  EtMETPlotPadh300->SetLogx(false);
  DiTauDiMuMassPlotPadh300->SetLogx(false);
  DiMuDiTauDeltaPhiPlotPadh300->SetLogx(false);
  METDiTauDeltaPhiPlotPadh300->SetLogx(false);
  METDiMuDeltaPhiPlotPadh300->SetLogx(false);
  DiTaudRPlotPadh300->SetLogx(false);
  DiTauMassSmallerdRPlotPadh300->SetLogx(false);
  HighestCSVInclJetPlotPadh300->SetLogx(false);
 
  
cout << "Created the Output Pads" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Legends
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  legend = new TLegend(0.7,0.5,0.95,0.7) ;
  legend->SetTextFont(42);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->AddEntry(EtMETh300a5_ ,"h300a5", "f");
  legend->AddEntry(EtMETh300a7_ ,"h300a7", "f");
  legend->AddEntry(EtMETh300a9_ ,"h300a9", "f");
  legend->AddEntry(EtMETh300a11_ ,"h300a11", "f");
  legend->AddEntry(EtMETh300a13_ ,"h300a13", "f");
  legend->AddEntry(EtMETh300a15_ ,"h300a15", "f");
  legend->AddEntry(EtMETh300a17_ ,"h300a17", "f");
  legend->AddEntry(EtMETh300a19_ ,"h300a19", "f");
  legend->AddEntry(EtMETh300a21_ ,"h300a21", "f");


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Drawing the stateerr and the data
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  NMedIsoTausWithMu3PlotPadh300->cd();
  NMedIsoTausWithMu3h300a5_->Draw("HIST");
  NMedIsoTausWithMu3h300a7_->Draw("HIST SAME");
  NMedIsoTausWithMu3h300a9_->Draw("HIST SAME");
  NMedIsoTausWithMu3h300a11_->Draw("HIST SAME");
  NMedIsoTausWithMu3h300a13_->Draw("HIST SAME");
  NMedIsoTausWithMu3h300a15_->Draw("HIST SAME");
  NMedIsoTausWithMu3h300a17_->Draw("HIST SAME");
  NMedIsoTausWithMu3h300a19_->Draw("HIST SAME");
  NMedIsoTausWithMu3h300a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassTauHadMu3PlotPadh300->cd();
  InvMassTauHadMu3h300a5_->Draw("HIST");
  InvMassTauHadMu3h300a7_->Draw("HIST SAME");
  InvMassTauHadMu3h300a9_->Draw("HIST SAME");
  InvMassTauHadMu3h300a11_->Draw("HIST SAME");
  InvMassTauHadMu3h300a13_->Draw("HIST SAME");
  InvMassTauHadMu3h300a15_->Draw("HIST SAME");
  InvMassTauHadMu3h300a17_->Draw("HIST SAME");
  InvMassTauHadMu3h300a19_->Draw("HIST SAME");
  InvMassTauHadMu3h300a21_->Draw("HIST SAME");
  legend->Draw();

  PtTauHadMu3PlotPadh300->cd();
  PtTauHadMu3h300a5_->Draw("HIST");
  PtTauHadMu3h300a7_->Draw("HIST SAME");
  PtTauHadMu3h300a9_->Draw("HIST SAME");
  PtTauHadMu3h300a11_->Draw("HIST SAME");
  PtTauHadMu3h300a13_->Draw("HIST SAME");
  PtTauHadMu3h300a15_->Draw("HIST SAME");
  PtTauHadMu3h300a17_->Draw("HIST SAME");
  PtTauHadMu3h300a19_->Draw("HIST SAME");
  PtTauHadMu3h300a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassMu2TauMuPlotPadh300->cd();
  InvMassMu2TauMuh300a5_->Draw("HIST");
  InvMassMu2TauMuh300a7_->Draw("HIST SAME");
  InvMassMu2TauMuh300a9_->Draw("HIST SAME");
  InvMassMu2TauMuh300a11_->Draw("HIST SAME");
  InvMassMu2TauMuh300a13_->Draw("HIST SAME");
  InvMassMu2TauMuh300a15_->Draw("HIST SAME");
  InvMassMu2TauMuh300a17_->Draw("HIST SAME");
  InvMassMu2TauMuh300a19_->Draw("HIST SAME");
  InvMassMu2TauMuh300a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassMu1TauMuPlotPadh300->cd();
  InvMassMu1TauMuh300a5_->Draw("HIST");
  InvMassMu1TauMuh300a7_->Draw("HIST SAME");
  InvMassMu1TauMuh300a9_->Draw("HIST SAME");
  InvMassMu1TauMuh300a11_->Draw("HIST SAME");
  InvMassMu1TauMuh300a13_->Draw("HIST SAME");
  InvMassMu1TauMuh300a15_->Draw("HIST SAME");
  InvMassMu1TauMuh300a17_->Draw("HIST SAME");
  InvMassMu1TauMuh300a19_->Draw("HIST SAME");
  InvMassMu1TauMuh300a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassFullRangePlotPadh300->cd();
  InvMassFullRangeh300a5_->Draw("HIST");
  InvMassFullRangeh300a7_->Draw("HIST SAME");
  InvMassFullRangeh300a9_->Draw("HIST SAME");
  InvMassFullRangeh300a11_->Draw("HIST SAME");
  InvMassFullRangeh300a13_->Draw("HIST SAME");
  InvMassFullRangeh300a15_->Draw("HIST SAME");
  InvMassFullRangeh300a17_->Draw("HIST SAME");
  InvMassFullRangeh300a19_->Draw("HIST SAME");
  InvMassFullRangeh300a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuBarrBarrPlotPadh300->cd();
  InvMassDiMuBarrBarrh300a5_->Draw("HIST");
  InvMassDiMuBarrBarrh300a7_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh300a9_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh300a11_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh300a13_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh300a15_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh300a17_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh300a19_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh300a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuBarrEndcPlotPadh300->cd();
  InvMassDiMuBarrEndch300a5_->Draw("HIST");
  InvMassDiMuBarrEndch300a7_->Draw("HIST SAME");
  InvMassDiMuBarrEndch300a9_->Draw("HIST SAME");
  InvMassDiMuBarrEndch300a11_->Draw("HIST SAME");
  InvMassDiMuBarrEndch300a13_->Draw("HIST SAME");
  InvMassDiMuBarrEndch300a15_->Draw("HIST SAME");
  InvMassDiMuBarrEndch300a17_->Draw("HIST SAME");
  InvMassDiMuBarrEndch300a19_->Draw("HIST SAME");
  InvMassDiMuBarrEndch300a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuEndcEndcPlotPadh300->cd();
  InvMassDiMuEndcEndch300a5_->Draw("HIST");
  InvMassDiMuEndcEndch300a7_->Draw("HIST SAME");
  InvMassDiMuEndcEndch300a9_->Draw("HIST SAME");
  InvMassDiMuEndcEndch300a11_->Draw("HIST SAME");
  InvMassDiMuEndcEndch300a13_->Draw("HIST SAME");
  InvMassDiMuEndcEndch300a15_->Draw("HIST SAME");
  InvMassDiMuEndcEndch300a17_->Draw("HIST SAME");
  InvMassDiMuEndcEndch300a19_->Draw("HIST SAME");
  InvMassDiMuEndcEndch300a21_->Draw("HIST SAME");
  legend->Draw();

  Mu1PtPlotPadh300->cd();
  Mu1Pth300a5_->Draw("HIST");
  Mu1Pth300a7_->Draw("HIST SAME");
  Mu1Pth300a9_->Draw("HIST SAME");
  Mu1Pth300a11_->Draw("HIST SAME");
  Mu1Pth300a13_->Draw("HIST SAME");
  Mu1Pth300a15_->Draw("HIST SAME");
  Mu1Pth300a17_->Draw("HIST SAME");
  Mu1Pth300a19_->Draw("HIST SAME");
  Mu1Pth300a21_->Draw("HIST SAME");
  legend->Draw();

  Mu2PtPlotPadh300->cd();
  Mu2Pth300a5_->Draw("HIST");
  Mu2Pth300a7_->Draw("HIST SAME");
  Mu2Pth300a9_->Draw("HIST SAME");
  Mu2Pth300a11_->Draw("HIST SAME");
  Mu2Pth300a13_->Draw("HIST SAME");
  Mu2Pth300a15_->Draw("HIST SAME");
  Mu2Pth300a17_->Draw("HIST SAME");
  Mu2Pth300a19_->Draw("HIST SAME");
  Mu2Pth300a21_->Draw("HIST SAME");

  DiMuPtPlotPadh300->cd();
  DiMuPth300a5_->Draw("HIST");
  DiMuPth300a7_->Draw("HIST SAME");
  DiMuPth300a9_->Draw("HIST SAME");
  DiMuPth300a11_->Draw("HIST SAME");
  DiMuPth300a13_->Draw("HIST SAME");
  DiMuPth300a15_->Draw("HIST SAME");
  DiMuPth300a17_->Draw("HIST SAME");
  DiMuPth300a19_->Draw("HIST SAME");
  DiMuPth300a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuBarrOverPlotPadh300->cd();
  InvMassDiMuBarrOverh300a5_->Draw("HIST");
  InvMassDiMuBarrOverh300a7_->Draw("HIST SAME");
  InvMassDiMuBarrOverh300a9_->Draw("HIST SAME");
  InvMassDiMuBarrOverh300a11_->Draw("HIST SAME");
  InvMassDiMuBarrOverh300a13_->Draw("HIST SAME");
  InvMassDiMuBarrOverh300a15_->Draw("HIST SAME");
  InvMassDiMuBarrOverh300a17_->Draw("HIST SAME");
  InvMassDiMuBarrOverh300a19_->Draw("HIST SAME");
  InvMassDiMuBarrOverh300a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuEndcOverPlotPadh300->cd();
  InvMassDiMuEndcOverh300a5_->Draw("HIST");
  InvMassDiMuEndcOverh300a7_->Draw("HIST SAME");
  InvMassDiMuEndcOverh300a9_->Draw("HIST SAME");
  InvMassDiMuEndcOverh300a11_->Draw("HIST SAME");
  InvMassDiMuEndcOverh300a13_->Draw("HIST SAME");
  InvMassDiMuEndcOverh300a15_->Draw("HIST SAME");
  InvMassDiMuEndcOverh300a17_->Draw("HIST SAME");
  InvMassDiMuEndcOverh300a19_->Draw("HIST SAME");
  InvMassDiMuEndcOverh300a21_->Draw("HIST SAME");

  DiTauEtaPlotPadh300->cd();
  DiTauEtah300a5_->Draw("HIST");
  DiTauEtah300a7_->Draw("HIST SAME");
  DiTauEtah300a9_->Draw("HIST SAME");
  DiTauEtah300a11_->Draw("HIST SAME");
  DiTauEtah300a13_->Draw("HIST SAME");
  DiTauEtah300a15_->Draw("HIST SAME");
  DiTauEtah300a17_->Draw("HIST SAME");
  DiTauEtah300a19_->Draw("HIST SAME");
  DiTauEtah300a21_->Draw("HIST SAME");
  legend->Draw();

  DiTauPhiPlotPadh300->cd();
  DiTauPhih300a5_->Draw("HIST");
  DiTauPhih300a7_->Draw("HIST SAME");
  DiTauPhih300a9_->Draw("HIST SAME");
  DiTauPhih300a11_->Draw("HIST SAME");
  DiTauPhih300a13_->Draw("HIST SAME");
  DiTauPhih300a15_->Draw("HIST SAME");
  DiTauPhih300a17_->Draw("HIST SAME");
  DiTauPhih300a19_->Draw("HIST SAME");
  DiTauPhih300a21_->Draw("HIST SAME");
  legend->Draw();

  DiMuEtaPlotPadh300->cd();
  DiMuEtah300a5_->Draw("HIST");
  DiMuEtah300a7_->Draw("HIST SAME");
  DiMuEtah300a9_->Draw("HIST SAME");
  DiMuEtah300a11_->Draw("HIST SAME");
  DiMuEtah300a13_->Draw("HIST SAME");
  DiMuEtah300a15_->Draw("HIST SAME");
  DiMuEtah300a17_->Draw("HIST SAME");
  DiMuEtah300a19_->Draw("HIST SAME");
  DiMuEtah300a21_->Draw("HIST SAME");
  legend->Draw();

  DiMudRPlotPadh300->cd();
  DiMudRh300a5_->Draw("HIST");
  DiMudRh300a7_->Draw("HIST SAME");
  DiMudRh300a9_->Draw("HIST SAME");
  DiMudRh300a11_->Draw("HIST SAME");
  DiMudRh300a13_->Draw("HIST SAME");
  DiMudRh300a15_->Draw("HIST SAME");
  DiMudRh300a17_->Draw("HIST SAME");
  DiMudRh300a19_->Draw("HIST SAME");
  DiMudRh300a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuOverOverPlotPadh300->cd();
  InvMassDiMuOverOverh300a5_->Draw("HIST");
  InvMassDiMuOverOverh300a7_->Draw("HIST SAME");
  InvMassDiMuOverOverh300a9_->Draw("HIST SAME");
  InvMassDiMuOverOverh300a11_->Draw("HIST SAME");
  InvMassDiMuOverOverh300a13_->Draw("HIST SAME");
  InvMassDiMuOverOverh300a15_->Draw("HIST SAME");
  InvMassDiMuOverOverh300a17_->Draw("HIST SAME");
  InvMassDiMuOverOverh300a19_->Draw("HIST SAME");
  InvMassDiMuOverOverh300a21_->Draw("HIST SAME");
  legend->Draw();

  EtMETPlotPadh300->cd();
  EtMETh300a5_->Draw("HIST");
  EtMETh300a7_->Draw("HIST SAME");
  EtMETh300a9_->Draw("HIST SAME");
  EtMETh300a11_->Draw("HIST SAME");
  EtMETh300a13_->Draw("HIST SAME");
  EtMETh300a15_->Draw("HIST SAME");
  EtMETh300a17_->Draw("HIST SAME");
  EtMETh300a19_->Draw("HIST SAME");
  EtMETh300a21_->Draw("HIST SAME");
  legend->Draw();

  DiTauDiMuMassPlotPadh300->cd();
  DiTauDiMuMassh300a5_->Draw("HIST");
  DiTauDiMuMassh300a7_->Draw("HIST SAME");
  DiTauDiMuMassh300a9_->Draw("HIST SAME");
  DiTauDiMuMassh300a11_->Draw("HIST SAME");
  DiTauDiMuMassh300a13_->Draw("HIST SAME");
  DiTauDiMuMassh300a15_->Draw("HIST SAME");
  DiTauDiMuMassh300a17_->Draw("HIST SAME");
  DiTauDiMuMassh300a19_->Draw("HIST SAME");
  DiTauDiMuMassh300a21_->Draw("HIST SAME");
  legend->Draw();

  DiMuDiTauDeltaPhiPlotPadh300->cd();
  DiMuDiTauDeltaPhih300a5_->Draw("HIST");
  DiMuDiTauDeltaPhih300a7_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih300a9_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih300a11_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih300a13_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih300a15_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih300a17_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih300a19_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih300a21_->Draw("HIST SAME");
  legend->Draw();

  METDiTauDeltaPhiPlotPadh300->cd();
  METDiTauDeltaPhih300a5_->Draw("HIST");
  METDiTauDeltaPhih300a7_->Draw("HIST SAME");
  METDiTauDeltaPhih300a9_->Draw("HIST SAME");
  METDiTauDeltaPhih300a11_->Draw("HIST SAME");
  METDiTauDeltaPhih300a13_->Draw("HIST SAME");
  METDiTauDeltaPhih300a15_->Draw("HIST SAME");
  METDiTauDeltaPhih300a17_->Draw("HIST SAME");
  METDiTauDeltaPhih300a19_->Draw("HIST SAME");
  METDiTauDeltaPhih300a21_->Draw("HIST SAME");
  legend->Draw();

  METDiMuDeltaPhiPlotPadh300->cd();
  METDiMuDeltaPhih300a5_->Draw("HIST");
  METDiMuDeltaPhih300a7_->Draw("HIST SAME");
  METDiMuDeltaPhih300a9_->Draw("HIST SAME");
  METDiMuDeltaPhih300a11_->Draw("HIST SAME");
  METDiMuDeltaPhih300a13_->Draw("HIST SAME");
  METDiMuDeltaPhih300a15_->Draw("HIST SAME");
  METDiMuDeltaPhih300a17_->Draw("HIST SAME");
  METDiMuDeltaPhih300a19_->Draw("HIST SAME");
  METDiMuDeltaPhih300a21_->Draw("HIST SAME");
  legend->Draw();

  DiTaudRPlotPadh300->cd();
  DiTaudRh300a5_->Draw("HIST");
  DiTaudRh300a7_->Draw("HIST SAME");
  DiTaudRh300a9_->Draw("HIST SAME");
  DiTaudRh300a11_->Draw("HIST SAME");
  DiTaudRh300a13_->Draw("HIST SAME");
  DiTaudRh300a15_->Draw("HIST SAME");
  DiTaudRh300a17_->Draw("HIST SAME");
  DiTaudRh300a19_->Draw("HIST SAME");
  DiTaudRh300a21_->Draw("HIST SAME");
  legend->Draw();

  DiTauMassSmallerdRPlotPadh300->cd();
  DiTauMassSmallerdRh300a5_->Draw("HIST");
  DiTauMassSmallerdRh300a7_->Draw("HIST SAME");
  DiTauMassSmallerdRh300a9_->Draw("HIST SAME");
  DiTauMassSmallerdRh300a11_->Draw("HIST SAME");
  DiTauMassSmallerdRh300a13_->Draw("HIST SAME");
  DiTauMassSmallerdRh300a15_->Draw("HIST SAME");
  DiTauMassSmallerdRh300a17_->Draw("HIST SAME");
  DiTauMassSmallerdRh300a19_->Draw("HIST SAME");
  DiTauMassSmallerdRh300a21_->Draw("HIST SAME");
  legend->Draw();

  HighestCSVInclJetPlotPadh300->cd();
  HighestCSVInclJeth300a5_->Draw("HIST");
  HighestCSVInclJeth300a7_->Draw("HIST SAME");
  HighestCSVInclJeth300a9_->Draw("HIST SAME");
  HighestCSVInclJeth300a11_->Draw("HIST SAME");
  HighestCSVInclJeth300a13_->Draw("HIST SAME");
  HighestCSVInclJeth300a15_->Draw("HIST SAME");
  HighestCSVInclJeth300a17_->Draw("HIST SAME");
  HighestCSVInclJeth300a19_->Draw("HIST SAME");
  HighestCSVInclJeth300a21_->Draw("HIST SAME");
  legend->Draw();

  TCanvas *NMedIsoTausWithMu3Canvash750 = new TCanvas ("NMedIsoTausWithMu3Canvash750","",600,600);
  TCanvas *InvMassTauHadMu3Canvash750 = new TCanvas ("InvMassTauHadMu3Canvash750","",600,600);
  TCanvas *PtTauHadMu3Canvash750 = new TCanvas ("PtTauHadMu3Canvash750","",600,600);
  TCanvas *InvMassMu1TauMuCanvash750 = new TCanvas ("InvMassMu1TauMuCanvash750","",600,600);
  TCanvas *InvMassMu2TauMuCanvash750 = new TCanvas ("InvMassMu2TauMuCanvash750","",600,600);
  TCanvas *InvMassFullRangeCanvash750 = new TCanvas ("InvMassFullRangeCanvash750","",600,600);
  TCanvas *InvMassDiMuBarrBarrCanvash750 = new TCanvas ("InvMassDiMuBarrBarrCanvash750","",600,600);
  TCanvas *InvMassDiMuBarrEndcCanvash750 = new TCanvas ("InvMassDiMuBarrEndcCanvash750","",600,600);
  TCanvas *InvMassDiMuEndcEndcCanvash750 = new TCanvas ("InvMassDiMuEndcEndcCanvash750","",600,600);
  TCanvas *Mu1PtCanvash750 = new TCanvas ("Mu1PtCanvash750","",600,600);
  TCanvas *Mu2PtCanvash750 = new TCanvas ("Mu2PtCanvash750","",600,600);
  TCanvas *DiMuPtCanvash750 = new TCanvas ("DiMuPtCanvash750","",600,600);
  TCanvas *InvMassDiMuBarrOverCanvash750 = new TCanvas ("InvMassDiMuBarrOverCanvash750","",600,600);
  TCanvas *InvMassDiMuEndcOverCanvash750 = new TCanvas ("InvMassDiMuEndcOverCanvash750","",600,600);
  TCanvas *DiTauEtaCanvash750 = new TCanvas ("DiTauEtaCanvash750","",600,600);
  TCanvas *DiTauPhiCanvash750 = new TCanvas ("DiTauPhiCanvash750","",600,600);
  TCanvas *DiMuEtaCanvash750 = new TCanvas ("DiMuEtaCanvash750","",600,600);
  TCanvas *DiMudRCanvash750 = new TCanvas ("DiMudRCanvash750","",600,600);
  TCanvas *InvMassDiMuOverOverCanvash750 = new TCanvas ("InvMassDiMuOverOverCanvash750","",600,600);
  TCanvas *EtMETCanvash750 = new TCanvas ("EtMETCanvash750","",600,600);
  TCanvas *DiTauDiMuMassCanvash750 = new TCanvas ("DiTauDiMuMassCanvash750","",600,600);
  TCanvas *DiMuDiTauDeltaPhiCanvash750 = new TCanvas ("DiMuDiTauDeltaPhiCanvash750","",600,600);
  TCanvas *METDiTauDeltaPhiCanvash750 = new TCanvas ("METDiTauDeltaPhiCanvash750","",600,600);
  TCanvas *METDiMuDeltaPhiCanvash750 = new TCanvas ("METDiMuDeltaPhiCanvash750","",600,600);
  TCanvas *DiTaudRCanvash750 = new TCanvas ("DiTaudRCanvash750","",600,600);
  TCanvas *DiTauMassSmallerdRCanvash750 = new TCanvas ("DiTauMassSmallerdRCanvash750","",600,600);
  TCanvas *HighestCSVInclJetCanvash750 = new TCanvas ("HighestCSVInclJetCanvash750","",600,600);

  TPad *NMedIsoTausWithMu3PlotPadh750 = new TPad ("NMedIsoTausWithMu3PlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassTauHadMu3PlotPadh750 = new TPad ("InvMassTauHadMu3PlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *PtTauHadMu3PlotPadh750 = new TPad ("PtTauHadMu3PlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassMu1TauMuPlotPadh750 = new TPad ("InvMassMu1TauMuPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassMu2TauMuPlotPadh750 = new TPad ("InvMassMu2TauMuPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassFullRangePlotPadh750 = new TPad ("InvMassFullRangePlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuBarrBarrPlotPadh750 = new TPad ("InvMassDiMuBarrBarrPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuBarrEndcPlotPadh750 = new TPad ("InvMassDiMuBarrEndcPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuEndcEndcPlotPadh750 = new TPad ("InvMassDiMuEndcEndcPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *Mu1PtPlotPadh750 = new TPad ("Mu1PtPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *Mu2PtPlotPadh750 = new TPad ("Mu2PtPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuPtPlotPadh750 = new TPad ("DiMuPtPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuBarrOverPlotPadh750 = new TPad ("InvMassDiMuBarrOverPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuEndcOverPlotPadh750 = new TPad ("InvMassDiMuEndcOverPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauEtaPlotPadh750 = new TPad ("DiTauEtaPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauPhiPlotPadh750 = new TPad ("DiTauPhiPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuEtaPlotPadh750 = new TPad ("DiMuEtaPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMudRPlotPadh750 = new TPad ("DiMudRPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *InvMassDiMuOverOverPlotPadh750 = new TPad ("InvMassDiMuOverOverPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *EtMETPlotPadh750 = new TPad ("EtMETPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauDiMuMassPlotPadh750 = new TPad ("DiTauDiMuMassPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiMuDiTauDeltaPhiPlotPadh750 = new TPad ("DiMuDiTauDeltaPhiPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *METDiTauDeltaPhiPlotPadh750 = new TPad ("METDiTauDeltaPhiPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *METDiMuDeltaPhiPlotPadh750 = new TPad ("METDiMuDeltaPhiPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTaudRPlotPadh750 = new TPad ("DiTaudRPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *DiTauMassSmallerdRPlotPadh750 = new TPad ("DiTauMassSmallerdRPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);
  TPad *HighestCSVInclJetPlotPadh750 = new TPad ("HighestCSVInclJetPlotPadh750", "top pad", 0.0, 0.21, 1.0, 1.0);

//  NMedIsoTausWithMu3PlotPadh750->SetBottomMargin(0.04);
//  InvMassTauHadMu3PlotPadh750->SetBottomMargin(0.04);
//  PtTauHadMu3PlotPadh750->SetBottomMargin(0.04);
//  InvMassMu2TauMuPlotPadh750->SetBottomMargin(0.04);
//  InvMassMu1TauMuPlotPadh750->SetBottomMargin(0.04);
//  InvMassFullRangePlotPadh750->SetBottomMargin(0.04);
//  InvMassDiMuBarrBarrPlotPadh750->SetBottomMargin(0.04);
//  InvMassDiMuBarrEndcPlotPadh750->SetBottomMargin(0.04);
//  InvMassDiMuEndcEndcPlotPadh750->SetBottomMargin(0.04);
//  Mu1PtPlotPadh750->SetBottomMargin(0.04);
//  Mu2PtPlotPadh750->SetBottomMargin(0.04);
//  DiMuPtPlotPadh750->SetBottomMargin(0.04);
//  InvMassDiMuBarrOverPlotPadh750->SetBottomMargin(0.04);
//  InvMassDiMuEndcOverPlotPadh750->SetBottomMargin(0.04);
//  DiTauEtaPlotPadh750->SetBottomMargin(0.04);
//  DiTauPhiPlotPadh750->SetBottomMargin(0.04);
//  DiMuEtaPlotPadh750->SetBottomMargin(0.04);
//  DiMudRPlotPadh750->SetBottomMargin(0.04);
//  InvMassDiMuOverOverPlotPadh750->SetBottomMargin(0.04);
//  EtMETPlotPadh750->SetBottomMargin(0.04);
//  DiTauDiMuMassPlotPadh750->SetBottomMargin(0.04);
//  DiMuDiTauDeltaPhiPlotPadh750->SetBottomMargin(0.04);
//  METDiTauDeltaPhiPlotPadh750->SetBottomMargin(0.04);
//  METDiMuDeltaPhiPlotPadh750->SetBottomMargin(0.04);
//  DiTaudRPlotPadh750->SetBottomMargin(0.04);
//  DiTauMassSmallerdRPlotPadh750->SetBottomMargin(0.04);
//  HighestCSVInclJetPlotPadh750->SetBottomMargin(0.04);
  
  NMedIsoTausWithMu3PlotPadh750->SetRightMargin(0.03);
  InvMassTauHadMu3PlotPadh750->SetRightMargin(0.03);
  PtTauHadMu3PlotPadh750->SetRightMargin(0.03);
  InvMassMu2TauMuPlotPadh750->SetRightMargin(0.03);
  InvMassMu1TauMuPlotPadh750->SetRightMargin(0.03);
  InvMassFullRangePlotPadh750->SetRightMargin(0.03);
  InvMassDiMuBarrBarrPlotPadh750->SetRightMargin(0.03);
  InvMassDiMuBarrEndcPlotPadh750->SetRightMargin(0.03);
  InvMassDiMuEndcEndcPlotPadh750->SetRightMargin(0.03);
  Mu1PtPlotPadh750->SetRightMargin(0.03);
  Mu2PtPlotPadh750->SetRightMargin(0.03);
  DiMuPtPlotPadh750->SetRightMargin(0.03);
  InvMassDiMuBarrOverPlotPadh750->SetRightMargin(0.03);
  InvMassDiMuEndcOverPlotPadh750->SetRightMargin(0.03);
  DiTauEtaPlotPadh750->SetRightMargin(0.03);
  DiTauPhiPlotPadh750->SetRightMargin(0.03);
  DiMuEtaPlotPadh750->SetRightMargin(0.03);
  DiMudRPlotPadh750->SetRightMargin(0.03);
  InvMassDiMuOverOverPlotPadh750->SetRightMargin(0.03);
  EtMETPlotPadh750->SetRightMargin(0.03);
  DiTauDiMuMassPlotPadh750->SetRightMargin(0.03);
  DiMuDiTauDeltaPhiPlotPadh750->SetRightMargin(0.03);
  METDiTauDeltaPhiPlotPadh750->SetRightMargin(0.03);
  METDiMuDeltaPhiPlotPadh750->SetRightMargin(0.03);
  DiTaudRPlotPadh750->SetRightMargin(0.03);
  DiTauMassSmallerdRPlotPadh750->SetRightMargin(0.03);
  HighestCSVInclJetPlotPadh750->SetRightMargin(0.03);
  
  NMedIsoTausWithMu3Canvash750->cd();
  NMedIsoTausWithMu3PlotPadh750->Draw();
  InvMassTauHadMu3Canvash750->cd();
  InvMassTauHadMu3PlotPadh750->Draw();
  PtTauHadMu3Canvash750->cd();
  PtTauHadMu3PlotPadh750->Draw();
  InvMassMu2TauMuCanvash750->cd();
  InvMassMu2TauMuPlotPadh750->Draw();
  InvMassMu1TauMuCanvash750->cd();
  InvMassMu1TauMuPlotPadh750->Draw();
  InvMassFullRangeCanvash750->cd();
  InvMassFullRangePlotPadh750->Draw();
  InvMassDiMuBarrBarrCanvash750->cd();
  InvMassDiMuBarrBarrPlotPadh750->Draw();
  InvMassDiMuBarrEndcCanvash750->cd();
  InvMassDiMuBarrEndcPlotPadh750->Draw();
  InvMassDiMuEndcEndcCanvash750->cd();
  InvMassDiMuEndcEndcPlotPadh750->Draw();
  Mu1PtCanvash750->cd();
  Mu1PtPlotPadh750->Draw();
  Mu2PtCanvash750->cd();
  Mu2PtPlotPadh750->Draw();
  DiMuPtCanvash750->cd();
  DiMuPtPlotPadh750->Draw();
  InvMassDiMuBarrOverCanvash750->cd();
  InvMassDiMuBarrOverPlotPadh750->Draw();
  InvMassDiMuEndcOverCanvash750->cd();
  InvMassDiMuEndcOverPlotPadh750->Draw();
  DiTauEtaCanvash750->cd();
  DiTauEtaPlotPadh750->Draw();
  DiTauPhiCanvash750->cd();
  DiTauPhiPlotPadh750->Draw();
  DiMuEtaCanvash750->cd();
  DiMuEtaPlotPadh750->Draw();
  DiMudRCanvash750->cd();
  DiMudRPlotPadh750->Draw();
  InvMassDiMuOverOverCanvash750->cd();
  InvMassDiMuOverOverPlotPadh750->Draw();
  EtMETCanvash750->cd();
  EtMETPlotPadh750->Draw();
  DiTauDiMuMassCanvash750->cd();
  DiTauDiMuMassPlotPadh750->Draw();
  DiMuDiTauDeltaPhiCanvash750->cd();
  DiMuDiTauDeltaPhiPlotPadh750->Draw();
  METDiTauDeltaPhiCanvash750->cd();
  METDiTauDeltaPhiPlotPadh750->Draw();
  METDiMuDeltaPhiCanvash750->cd();
  METDiMuDeltaPhiPlotPadh750->Draw();
  DiTaudRCanvash750->cd();
  DiTaudRPlotPadh750->Draw();
  DiTauMassSmallerdRCanvash750->cd();
  DiTauMassSmallerdRPlotPadh750->Draw();
  HighestCSVInclJetCanvash750->cd();
  HighestCSVInclJetPlotPadh750->Draw();
  
  NMedIsoTausWithMu3PlotPadh750->SetLogy(true);
  InvMassTauHadMu3PlotPadh750->SetLogy(true);
  PtTauHadMu3PlotPadh750->SetLogy(true);
  InvMassMu2TauMuPlotPadh750->SetLogy(true);
  InvMassMu1TauMuPlotPadh750->SetLogy(true);
  InvMassFullRangePlotPadh750->SetLogy(true);
  InvMassDiMuBarrBarrPlotPadh750->SetLogy(true);
  InvMassDiMuBarrEndcPlotPadh750->SetLogy(true);
  InvMassDiMuEndcEndcPlotPadh750->SetLogy(true);
  Mu1PtPlotPadh750->SetLogy(true);
  Mu2PtPlotPadh750->SetLogy(true);
  DiMuPtPlotPadh750->SetLogy(true);
  InvMassDiMuBarrOverPlotPadh750->SetLogy(true);
  InvMassDiMuEndcOverPlotPadh750->SetLogy(true);
  DiTauEtaPlotPadh750->SetLogy(true);
  DiTauPhiPlotPadh750->SetLogy(true);
  DiMuEtaPlotPadh750->SetLogy(true);
  DiMudRPlotPadh750->SetLogy(true);
  InvMassDiMuOverOverPlotPadh750->SetLogy(true);
  EtMETPlotPadh750->SetLogy(true);
  DiTauDiMuMassPlotPadh750->SetLogy(true);
  DiMuDiTauDeltaPhiPlotPadh750->SetLogy(true);
  METDiTauDeltaPhiPlotPadh750->SetLogy(true);
  METDiMuDeltaPhiPlotPadh750->SetLogy(true);
  DiTaudRPlotPadh750->SetLogy(true);
  DiTauMassSmallerdRPlotPadh750->SetLogy(true);
  HighestCSVInclJetPlotPadh750->SetLogy(true);
  
  NMedIsoTausWithMu3PlotPadh750->SetLogx(false);
  InvMassTauHadMu3PlotPadh750->SetLogx(false);
  PtTauHadMu3PlotPadh750->SetLogx(false);
  InvMassMu2TauMuPlotPadh750->SetLogx(false);
  InvMassMu1TauMuPlotPadh750->SetLogx(false);
  InvMassFullRangePlotPadh750->SetLogx(false);
  InvMassDiMuBarrBarrPlotPadh750->SetLogx(false);
  InvMassDiMuBarrEndcPlotPadh750->SetLogx(false);
  InvMassDiMuEndcEndcPlotPadh750->SetLogx(false);
  Mu1PtPlotPadh750->SetLogx(false);
  Mu2PtPlotPadh750->SetLogx(false);
  DiMuPtPlotPadh750->SetLogx(false);
  InvMassDiMuBarrOverPlotPadh750->SetLogx(false);
  InvMassDiMuEndcOverPlotPadh750->SetLogx(false);
  DiTauEtaPlotPadh750->SetLogx(false);
  DiTauPhiPlotPadh750->SetLogx(false);
  DiMuEtaPlotPadh750->SetLogx(false);
  DiMudRPlotPadh750->SetLogx(false);
  InvMassDiMuOverOverPlotPadh750->SetLogx(false);
  EtMETPlotPadh750->SetLogx(false);
  DiTauDiMuMassPlotPadh750->SetLogx(false);
  DiMuDiTauDeltaPhiPlotPadh750->SetLogx(false);
  METDiTauDeltaPhiPlotPadh750->SetLogx(false);
  METDiMuDeltaPhiPlotPadh750->SetLogx(false);
  DiTaudRPlotPadh750->SetLogx(false);
  DiTauMassSmallerdRPlotPadh750->SetLogx(false);
  HighestCSVInclJetPlotPadh750->SetLogx(false);
 
  
cout << "Created the Output Pads" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Legends
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  legend = new TLegend(0.7,0.5,0.95,0.7) ;
  legend->SetTextFont(42);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->AddEntry(EtMETh750a5_ ,"h750a5", "f");
  legend->AddEntry(EtMETh750a7_ ,"h750a7", "f");
  legend->AddEntry(EtMETh750a9_ ,"h750a9", "f");
  legend->AddEntry(EtMETh750a11_ ,"h750a11", "f");
  legend->AddEntry(EtMETh750a13_ ,"h750a13", "f");
  legend->AddEntry(EtMETh750a15_ ,"h750a15", "f");
  legend->AddEntry(EtMETh750a17_ ,"h750a17", "f");
  legend->AddEntry(EtMETh750a19_ ,"h750a19", "f");
  legend->AddEntry(EtMETh750a21_ ,"h750a21", "f");


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Drawing the stateerr and the data
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  NMedIsoTausWithMu3PlotPadh750->cd();
cout << "NMedIsoTausWithMu3h750a5_->GetxAxis()->GetTitle()=" << NMedIsoTausWithMu3h750a5_->GetXaxis()->GetTitle() << endl;
  NMedIsoTausWithMu3h750a5_->Draw("HIST");
  NMedIsoTausWithMu3h750a7_->Draw("HIST SAME");
  NMedIsoTausWithMu3h750a9_->Draw("HIST SAME");
  NMedIsoTausWithMu3h750a11_->Draw("HIST SAME");
  NMedIsoTausWithMu3h750a13_->Draw("HIST SAME");
  NMedIsoTausWithMu3h750a15_->Draw("HIST SAME");
  NMedIsoTausWithMu3h750a17_->Draw("HIST SAME");
  NMedIsoTausWithMu3h750a19_->Draw("HIST SAME");
  NMedIsoTausWithMu3h750a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassTauHadMu3PlotPadh750->cd();
  InvMassTauHadMu3h750a5_->Draw("HIST");
  InvMassTauHadMu3h750a7_->Draw("HIST SAME");
  InvMassTauHadMu3h750a9_->Draw("HIST SAME");
  InvMassTauHadMu3h750a11_->Draw("HIST SAME");
  InvMassTauHadMu3h750a13_->Draw("HIST SAME");
  InvMassTauHadMu3h750a15_->Draw("HIST SAME");
  InvMassTauHadMu3h750a17_->Draw("HIST SAME");
  InvMassTauHadMu3h750a19_->Draw("HIST SAME");
  InvMassTauHadMu3h750a21_->Draw("HIST SAME");
  legend->Draw();

  PtTauHadMu3PlotPadh750->cd();
  PtTauHadMu3h750a5_->Draw("HIST");
  PtTauHadMu3h750a7_->Draw("HIST SAME");
  PtTauHadMu3h750a9_->Draw("HIST SAME");
  PtTauHadMu3h750a11_->Draw("HIST SAME");
  PtTauHadMu3h750a13_->Draw("HIST SAME");
  PtTauHadMu3h750a15_->Draw("HIST SAME");
  PtTauHadMu3h750a17_->Draw("HIST SAME");
  PtTauHadMu3h750a19_->Draw("HIST SAME");
  PtTauHadMu3h750a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassMu2TauMuPlotPadh750->cd();
  InvMassMu2TauMuh750a5_->Draw("HIST");
  InvMassMu2TauMuh750a7_->Draw("HIST SAME");
  InvMassMu2TauMuh750a9_->Draw("HIST SAME");
  InvMassMu2TauMuh750a11_->Draw("HIST SAME");
  InvMassMu2TauMuh750a13_->Draw("HIST SAME");
  InvMassMu2TauMuh750a15_->Draw("HIST SAME");
  InvMassMu2TauMuh750a17_->Draw("HIST SAME");
  InvMassMu2TauMuh750a19_->Draw("HIST SAME");
  InvMassMu2TauMuh750a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassMu1TauMuPlotPadh750->cd();
  InvMassMu1TauMuh750a5_->Draw("HIST");
  InvMassMu1TauMuh750a7_->Draw("HIST SAME");
  InvMassMu1TauMuh750a9_->Draw("HIST SAME");
  InvMassMu1TauMuh750a11_->Draw("HIST SAME");
  InvMassMu1TauMuh750a13_->Draw("HIST SAME");
  InvMassMu1TauMuh750a15_->Draw("HIST SAME");
  InvMassMu1TauMuh750a17_->Draw("HIST SAME");
  InvMassMu1TauMuh750a19_->Draw("HIST SAME");
  InvMassMu1TauMuh750a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassFullRangePlotPadh750->cd();
  InvMassFullRangeh750a5_->Draw("HIST");
  InvMassFullRangeh750a7_->Draw("HIST SAME");
  InvMassFullRangeh750a9_->Draw("HIST SAME");
  InvMassFullRangeh750a11_->Draw("HIST SAME");
  InvMassFullRangeh750a13_->Draw("HIST SAME");
  InvMassFullRangeh750a15_->Draw("HIST SAME");
  InvMassFullRangeh750a17_->Draw("HIST SAME");
  InvMassFullRangeh750a19_->Draw("HIST SAME");
  InvMassFullRangeh750a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuBarrBarrPlotPadh750->cd();
  InvMassDiMuBarrBarrh750a5_->Draw("HIST");
  InvMassDiMuBarrBarrh750a7_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh750a9_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh750a11_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh750a13_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh750a15_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh750a17_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh750a19_->Draw("HIST SAME");
  InvMassDiMuBarrBarrh750a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuBarrEndcPlotPadh750->cd();
  InvMassDiMuBarrEndch750a5_->Draw("HIST");
  InvMassDiMuBarrEndch750a7_->Draw("HIST SAME");
  InvMassDiMuBarrEndch750a9_->Draw("HIST SAME");
  InvMassDiMuBarrEndch750a11_->Draw("HIST SAME");
  InvMassDiMuBarrEndch750a13_->Draw("HIST SAME");
  InvMassDiMuBarrEndch750a15_->Draw("HIST SAME");
  InvMassDiMuBarrEndch750a17_->Draw("HIST SAME");
  InvMassDiMuBarrEndch750a19_->Draw("HIST SAME");
  InvMassDiMuBarrEndch750a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuEndcEndcPlotPadh750->cd();
  InvMassDiMuEndcEndch750a5_->Draw("HIST");
  InvMassDiMuEndcEndch750a7_->Draw("HIST SAME");
  InvMassDiMuEndcEndch750a9_->Draw("HIST SAME");
  InvMassDiMuEndcEndch750a11_->Draw("HIST SAME");
  InvMassDiMuEndcEndch750a13_->Draw("HIST SAME");
  InvMassDiMuEndcEndch750a15_->Draw("HIST SAME");
  InvMassDiMuEndcEndch750a17_->Draw("HIST SAME");
  InvMassDiMuEndcEndch750a19_->Draw("HIST SAME");
  InvMassDiMuEndcEndch750a21_->Draw("HIST SAME");
  legend->Draw();

  Mu1PtPlotPadh750->cd();
  Mu1Pth750a5_->Draw("HIST");
  Mu1Pth750a7_->Draw("HIST SAME");
  Mu1Pth750a9_->Draw("HIST SAME");
  Mu1Pth750a11_->Draw("HIST SAME");
  Mu1Pth750a13_->Draw("HIST SAME");
  Mu1Pth750a15_->Draw("HIST SAME");
  Mu1Pth750a17_->Draw("HIST SAME");
  Mu1Pth750a19_->Draw("HIST SAME");
  Mu1Pth750a21_->Draw("HIST SAME");
  legend->Draw();

  Mu2PtPlotPadh750->cd();
  Mu2Pth750a5_->Draw("HIST");
  Mu2Pth750a7_->Draw("HIST SAME");
  Mu2Pth750a9_->Draw("HIST SAME");
  Mu2Pth750a11_->Draw("HIST SAME");
  Mu2Pth750a13_->Draw("HIST SAME");
  Mu2Pth750a15_->Draw("HIST SAME");
  Mu2Pth750a17_->Draw("HIST SAME");
  Mu2Pth750a19_->Draw("HIST SAME");
  Mu2Pth750a21_->Draw("HIST SAME");

  DiMuPtPlotPadh750->cd();
  DiMuPth750a5_->Draw("HIST");
  DiMuPth750a7_->Draw("HIST SAME");
  DiMuPth750a9_->Draw("HIST SAME");
  DiMuPth750a11_->Draw("HIST SAME");
  DiMuPth750a13_->Draw("HIST SAME");
  DiMuPth750a15_->Draw("HIST SAME");
  DiMuPth750a17_->Draw("HIST SAME");
  DiMuPth750a19_->Draw("HIST SAME");
  DiMuPth750a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuBarrOverPlotPadh750->cd();
  InvMassDiMuBarrOverh750a5_->Draw("HIST");
  InvMassDiMuBarrOverh750a7_->Draw("HIST SAME");
  InvMassDiMuBarrOverh750a9_->Draw("HIST SAME");
  InvMassDiMuBarrOverh750a11_->Draw("HIST SAME");
  InvMassDiMuBarrOverh750a13_->Draw("HIST SAME");
  InvMassDiMuBarrOverh750a15_->Draw("HIST SAME");
  InvMassDiMuBarrOverh750a17_->Draw("HIST SAME");
  InvMassDiMuBarrOverh750a19_->Draw("HIST SAME");
  InvMassDiMuBarrOverh750a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuEndcOverPlotPadh750->cd();
  InvMassDiMuEndcOverh750a5_->Draw("HIST");
  InvMassDiMuEndcOverh750a7_->Draw("HIST SAME");
  InvMassDiMuEndcOverh750a9_->Draw("HIST SAME");
  InvMassDiMuEndcOverh750a11_->Draw("HIST SAME");
  InvMassDiMuEndcOverh750a13_->Draw("HIST SAME");
  InvMassDiMuEndcOverh750a15_->Draw("HIST SAME");
  InvMassDiMuEndcOverh750a17_->Draw("HIST SAME");
  InvMassDiMuEndcOverh750a19_->Draw("HIST SAME");
  InvMassDiMuEndcOverh750a21_->Draw("HIST SAME");
  legend->Draw();

  DiTauEtaPlotPadh750->cd();
  DiTauEtah750a5_->Draw("HIST");
  DiTauEtah750a7_->Draw("HIST SAME");
  DiTauEtah750a9_->Draw("HIST SAME");
  DiTauEtah750a11_->Draw("HIST SAME");
  DiTauEtah750a13_->Draw("HIST SAME");
  DiTauEtah750a15_->Draw("HIST SAME");
  DiTauEtah750a17_->Draw("HIST SAME");
  DiTauEtah750a19_->Draw("HIST SAME");
  DiTauEtah750a21_->Draw("HIST SAME");
  legend->Draw();

  DiTauPhiPlotPadh750->cd();
  DiTauPhih750a5_->Draw("HIST");
  DiTauPhih750a7_->Draw("HIST SAME");
  DiTauPhih750a9_->Draw("HIST SAME");
  DiTauPhih750a11_->Draw("HIST SAME");
  DiTauPhih750a13_->Draw("HIST SAME");
  DiTauPhih750a15_->Draw("HIST SAME");
  DiTauPhih750a17_->Draw("HIST SAME");
  DiTauPhih750a19_->Draw("HIST SAME");
  DiTauPhih750a21_->Draw("HIST SAME");
  legend->Draw();

  DiMuEtaPlotPadh750->cd();
  DiMuEtah750a5_->Draw("HIST");
  DiMuEtah750a7_->Draw("HIST SAME");
  DiMuEtah750a9_->Draw("HIST SAME");
  DiMuEtah750a11_->Draw("HIST SAME");
  DiMuEtah750a13_->Draw("HIST SAME");
  DiMuEtah750a15_->Draw("HIST SAME");
  DiMuEtah750a17_->Draw("HIST SAME");
  DiMuEtah750a19_->Draw("HIST SAME");
  DiMuEtah750a21_->Draw("HIST SAME");
  legend->Draw();

  DiMudRPlotPadh750->cd();
  DiMudRh750a5_->Draw("HIST");
  DiMudRh750a7_->Draw("HIST SAME");
  DiMudRh750a9_->Draw("HIST SAME");
  DiMudRh750a11_->Draw("HIST SAME");
  DiMudRh750a13_->Draw("HIST SAME");
  DiMudRh750a15_->Draw("HIST SAME");
  DiMudRh750a17_->Draw("HIST SAME");
  DiMudRh750a19_->Draw("HIST SAME");
  DiMudRh750a21_->Draw("HIST SAME");
  legend->Draw();

  InvMassDiMuOverOverPlotPadh750->cd();
  InvMassDiMuOverOverh750a5_->Draw("HIST");
  InvMassDiMuOverOverh750a7_->Draw("HIST SAME");
  InvMassDiMuOverOverh750a9_->Draw("HIST SAME");
  InvMassDiMuOverOverh750a11_->Draw("HIST SAME");
  InvMassDiMuOverOverh750a13_->Draw("HIST SAME");
  InvMassDiMuOverOverh750a15_->Draw("HIST SAME");
  InvMassDiMuOverOverh750a17_->Draw("HIST SAME");
  InvMassDiMuOverOverh750a19_->Draw("HIST SAME");
  InvMassDiMuOverOverh750a21_->Draw("HIST SAME");
  legend->Draw();

  EtMETPlotPadh750->cd();
  EtMETh750a5_->Draw("HIST");
  EtMETh750a7_->Draw("HIST SAME");
  EtMETh750a9_->Draw("HIST SAME");
  EtMETh750a11_->Draw("HIST SAME");
  EtMETh750a13_->Draw("HIST SAME");
  EtMETh750a15_->Draw("HIST SAME");
  EtMETh750a17_->Draw("HIST SAME");
  EtMETh750a19_->Draw("HIST SAME");
  EtMETh750a21_->Draw("HIST SAME");
  legend->Draw();

  DiTauDiMuMassPlotPadh750->cd();
  DiTauDiMuMassh750a5_->Draw("HIST");
  DiTauDiMuMassh750a7_->Draw("HIST SAME");
  DiTauDiMuMassh750a9_->Draw("HIST SAME");
  DiTauDiMuMassh750a11_->Draw("HIST SAME");
  DiTauDiMuMassh750a13_->Draw("HIST SAME");
  DiTauDiMuMassh750a15_->Draw("HIST SAME");
  DiTauDiMuMassh750a17_->Draw("HIST SAME");
  DiTauDiMuMassh750a19_->Draw("HIST SAME");
  DiTauDiMuMassh750a21_->Draw("HIST SAME");
  legend->Draw();

  DiMuDiTauDeltaPhiPlotPadh750->cd();
  DiMuDiTauDeltaPhih750a5_->Draw("HIST");
  DiMuDiTauDeltaPhih750a7_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih750a9_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih750a11_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih750a13_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih750a15_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih750a17_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih750a19_->Draw("HIST SAME");
  DiMuDiTauDeltaPhih750a21_->Draw("HIST SAME");
  legend->Draw();

  METDiTauDeltaPhiPlotPadh750->cd();
  METDiTauDeltaPhih750a5_->Draw("HIST");
  METDiTauDeltaPhih750a7_->Draw("HIST SAME");
  METDiTauDeltaPhih750a9_->Draw("HIST SAME");
  METDiTauDeltaPhih750a11_->Draw("HIST SAME");
  METDiTauDeltaPhih750a13_->Draw("HIST SAME");
  METDiTauDeltaPhih750a15_->Draw("HIST SAME");
  METDiTauDeltaPhih750a17_->Draw("HIST SAME");
  METDiTauDeltaPhih750a19_->Draw("HIST SAME");
  METDiTauDeltaPhih750a21_->Draw("HIST SAME");
  legend->Draw();

  METDiMuDeltaPhiPlotPadh750->cd();
  METDiMuDeltaPhih750a5_->Draw("HIST");
  METDiMuDeltaPhih750a7_->Draw("HIST SAME");
  METDiMuDeltaPhih750a9_->Draw("HIST SAME");
  METDiMuDeltaPhih750a11_->Draw("HIST SAME");
  METDiMuDeltaPhih750a13_->Draw("HIST SAME");
  METDiMuDeltaPhih750a15_->Draw("HIST SAME");
  METDiMuDeltaPhih750a17_->Draw("HIST SAME");
  METDiMuDeltaPhih750a19_->Draw("HIST SAME");
  METDiMuDeltaPhih750a21_->Draw("HIST SAME");
  legend->Draw();

  DiTaudRPlotPadh750->cd();
  DiTaudRh750a5_->Draw("HIST");
  DiTaudRh750a7_->Draw("HIST SAME");
  DiTaudRh750a9_->Draw("HIST SAME");
  DiTaudRh750a11_->Draw("HIST SAME");
  DiTaudRh750a13_->Draw("HIST SAME");
  DiTaudRh750a15_->Draw("HIST SAME");
  DiTaudRh750a17_->Draw("HIST SAME");
  DiTaudRh750a19_->Draw("HIST SAME");
  DiTaudRh750a21_->Draw("HIST SAME");
  legend->Draw();

  DiTauMassSmallerdRPlotPadh750->cd();
  DiTauMassSmallerdRh750a5_->Draw("HIST");
  DiTauMassSmallerdRh750a7_->Draw("HIST SAME");
  DiTauMassSmallerdRh750a9_->Draw("HIST SAME");
  DiTauMassSmallerdRh750a11_->Draw("HIST SAME");
  DiTauMassSmallerdRh750a13_->Draw("HIST SAME");
  DiTauMassSmallerdRh750a15_->Draw("HIST SAME");
  DiTauMassSmallerdRh750a17_->Draw("HIST SAME");
  DiTauMassSmallerdRh750a19_->Draw("HIST SAME");
  DiTauMassSmallerdRh750a21_->Draw("HIST SAME");
  legend->Draw();

  HighestCSVInclJetPlotPadh750->cd();
  HighestCSVInclJeth750a5_->Draw("HIST");
  HighestCSVInclJeth750a7_->Draw("HIST SAME");
  HighestCSVInclJeth750a9_->Draw("HIST SAME");
  HighestCSVInclJeth750a11_->Draw("HIST SAME");
  HighestCSVInclJeth750a13_->Draw("HIST SAME");
  HighestCSVInclJeth750a15_->Draw("HIST SAME");
  HighestCSVInclJeth750a17_->Draw("HIST SAME");
  HighestCSVInclJeth750a19_->Draw("HIST SAME");
  HighestCSVInclJeth750a21_->Draw("HIST SAME");
  legend->Draw();


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting the cms_lumi Styling
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  writeExtraText = true;
  lumi_13TeV = "35.9 fb^{-1}";
  CMS_lumi(NMedIsoTausWithMu3PlotPadh125, 4, 11);
  CMS_lumi(InvMassTauHadMu3PlotPadh125, 4, 11);
  CMS_lumi(PtTauHadMu3PlotPadh125, 4, 11);
  CMS_lumi(InvMassMu2TauMuPlotPadh125, 4, 11);
  CMS_lumi(InvMassMu1TauMuPlotPadh125, 4, 11);
  CMS_lumi(InvMassFullRangePlotPadh125, 4, 11);
  CMS_lumi(InvMassDiMuBarrBarrPlotPadh125, 4, 11);
  CMS_lumi(InvMassDiMuBarrEndcPlotPadh125, 4, 11);
  CMS_lumi(InvMassDiMuEndcEndcPlotPadh125, 4, 11);
  CMS_lumi(Mu1PtPlotPadh125, 4, 11);
  CMS_lumi(Mu2PtPlotPadh125, 4, 11);
  CMS_lumi(DiMuPtPlotPadh125, 4, 11);
  CMS_lumi(InvMassDiMuBarrOverPlotPadh125, 4, 11);
  CMS_lumi(InvMassDiMuEndcOverPlotPadh125, 4, 11);
  CMS_lumi(DiTauEtaPlotPadh125, 4, 11);
  CMS_lumi(DiTauPhiPlotPadh125, 4, 11);
  CMS_lumi(DiMuEtaPlotPadh125, 4, 11);
  CMS_lumi(DiMudRPlotPadh125, 4, 11);
  CMS_lumi(InvMassDiMuOverOverPlotPadh125, 4, 11);
  CMS_lumi(EtMETPlotPadh125, 4, 11);
  CMS_lumi(DiTauDiMuMassPlotPadh125, 4, 11);
  CMS_lumi(DiMuDiTauDeltaPhiPlotPadh125, 4, 11);
  CMS_lumi(METDiTauDeltaPhiPlotPadh125, 4, 11);
  CMS_lumi(METDiMuDeltaPhiPlotPadh125, 4, 11);
  CMS_lumi(DiTaudRPlotPadh125, 4, 11);
  CMS_lumi(DiTauMassSmallerdRPlotPadh125, 4, 11);
  CMS_lumi(HighestCSVInclJetPlotPadh125, 4, 11);

  CMS_lumi(NMedIsoTausWithMu3PlotPadh300, 4, 11);
  CMS_lumi(InvMassTauHadMu3PlotPadh300, 4, 11);
  CMS_lumi(PtTauHadMu3PlotPadh300, 4, 11);
  CMS_lumi(InvMassMu2TauMuPlotPadh300, 4, 11);
  CMS_lumi(InvMassMu1TauMuPlotPadh300, 4, 11);
  CMS_lumi(InvMassFullRangePlotPadh300, 4, 11);
  CMS_lumi(InvMassDiMuBarrBarrPlotPadh300, 4, 11);
  CMS_lumi(InvMassDiMuBarrEndcPlotPadh300, 4, 11);
  CMS_lumi(InvMassDiMuEndcEndcPlotPadh300, 4, 11);
  CMS_lumi(Mu1PtPlotPadh300, 4, 11);
  CMS_lumi(Mu2PtPlotPadh300, 4, 11);
  CMS_lumi(DiMuPtPlotPadh300, 4, 11);
  CMS_lumi(InvMassDiMuBarrOverPlotPadh300, 4, 11);
  CMS_lumi(InvMassDiMuEndcOverPlotPadh300, 4, 11);
  CMS_lumi(DiTauEtaPlotPadh300, 4, 11);
  CMS_lumi(DiTauPhiPlotPadh300, 4, 11);
  CMS_lumi(DiMuEtaPlotPadh300, 4, 11);
  CMS_lumi(DiMudRPlotPadh300, 4, 11);
  CMS_lumi(InvMassDiMuOverOverPlotPadh300, 4, 11);
  CMS_lumi(EtMETPlotPadh300, 4, 11);
  CMS_lumi(DiTauDiMuMassPlotPadh300, 4, 11);
  CMS_lumi(DiMuDiTauDeltaPhiPlotPadh300, 4, 11);
  CMS_lumi(METDiTauDeltaPhiPlotPadh300, 4, 11);
  CMS_lumi(METDiMuDeltaPhiPlotPadh300, 4, 11);
  CMS_lumi(DiTaudRPlotPadh300, 4, 11);
  CMS_lumi(DiTauMassSmallerdRPlotPadh300, 4, 11);
  CMS_lumi(HighestCSVInclJetPlotPadh300, 4, 11);
  

  CMS_lumi(NMedIsoTausWithMu3PlotPadh750, 4, 11);
  CMS_lumi(InvMassTauHadMu3PlotPadh750, 4, 11);
  CMS_lumi(PtTauHadMu3PlotPadh750, 4, 11);
  CMS_lumi(InvMassMu2TauMuPlotPadh750, 4, 11);
  CMS_lumi(InvMassMu1TauMuPlotPadh750, 4, 11);
  CMS_lumi(InvMassFullRangePlotPadh750, 4, 11);
  CMS_lumi(InvMassDiMuBarrBarrPlotPadh750, 4, 11);
  CMS_lumi(InvMassDiMuBarrEndcPlotPadh750, 4, 11);
  CMS_lumi(InvMassDiMuEndcEndcPlotPadh750, 4, 11);
  CMS_lumi(Mu1PtPlotPadh750, 4, 11);
  CMS_lumi(Mu2PtPlotPadh750, 4, 11);
  CMS_lumi(DiMuPtPlotPadh750, 4, 11);
  CMS_lumi(InvMassDiMuBarrOverPlotPadh750, 4, 11);
  CMS_lumi(InvMassDiMuEndcOverPlotPadh750, 4, 11);
  CMS_lumi(DiTauEtaPlotPadh750, 4, 11);
  CMS_lumi(DiTauPhiPlotPadh750, 4, 11);
  CMS_lumi(DiMuEtaPlotPadh750, 4, 11);
  CMS_lumi(DiMudRPlotPadh750, 4, 11);
  CMS_lumi(InvMassDiMuOverOverPlotPadh750, 4, 11);
  CMS_lumi(EtMETPlotPadh750, 4, 11);
  CMS_lumi(DiTauDiMuMassPlotPadh750, 4, 11);
  CMS_lumi(DiMuDiTauDeltaPhiPlotPadh750, 4, 11);
  CMS_lumi(METDiTauDeltaPhiPlotPadh750, 4, 11);
  CMS_lumi(METDiMuDeltaPhiPlotPadh750, 4, 11);
  CMS_lumi(DiTaudRPlotPadh750, 4, 11);
  CMS_lumi(DiTauMassSmallerdRPlotPadh750, 4, 11);
  CMS_lumi(HighestCSVInclJetPlotPadh750, 4, 11);

cout << "Cms_lumi run" << endl;

  outFile->cd();

  NMedIsoTausWithMu3Canvash125->cd();
  NMedIsoTausWithMu3Canvash125->Draw();
  NMedIsoTausWithMu3Canvash125->Write();

  InvMassTauHadMu3Canvash125->cd();
  InvMassTauHadMu3Canvash125->Draw();
  InvMassTauHadMu3Canvash125->Write();

  PtTauHadMu3Canvash125->cd();
  PtTauHadMu3Canvash125->Draw();
  PtTauHadMu3Canvash125->Write();

  InvMassMu2TauMuCanvash125->cd();
  InvMassMu2TauMuCanvash125->Draw();
  InvMassMu2TauMuCanvash125->Write();

  InvMassMu1TauMuCanvash125->cd();
  InvMassMu1TauMuCanvash125->Draw();
  InvMassMu1TauMuCanvash125->Write();

  InvMassFullRangeCanvash125->cd();
  InvMassFullRangeCanvash125->Draw();
  InvMassFullRangeCanvash125->Write();

  InvMassDiMuBarrBarrCanvash125->cd();
  InvMassDiMuBarrBarrCanvash125->Draw();
  InvMassDiMuBarrBarrCanvash125->Write();

  InvMassDiMuBarrEndcCanvash125->cd();
  InvMassDiMuBarrEndcCanvash125->Draw();
  InvMassDiMuBarrEndcCanvash125->Write();

  InvMassDiMuEndcEndcCanvash125->cd();
  InvMassDiMuEndcEndcCanvash125->Draw();
  InvMassDiMuEndcEndcCanvash125->Write();

  Mu1PtCanvash125->cd();
  Mu1PtCanvash125->Draw();
  Mu1PtCanvash125->Write();

  Mu2PtCanvash125->cd();
  Mu2PtCanvash125->Draw();
  Mu2PtCanvash125->Write();

  DiMuPtCanvash125->cd();
  DiMuPtCanvash125->Draw();
  DiMuPtCanvash125->Write();

  InvMassDiMuBarrOverCanvash125->cd();
  InvMassDiMuBarrOverCanvash125->Draw();
  InvMassDiMuBarrOverCanvash125->Write();

  InvMassDiMuEndcOverCanvash125->cd();
  InvMassDiMuEndcOverCanvash125->Draw();
  InvMassDiMuEndcOverCanvash125->Write();

  DiTauEtaCanvash125->cd();
  DiTauEtaCanvash125->Draw();
  DiTauEtaCanvash125->Write();

  DiTauPhiCanvash125->cd();
  DiTauPhiCanvash125->Draw();
  DiTauPhiCanvash125->Write();

  DiMuEtaCanvash125->cd();
  DiMuEtaCanvash125->Draw();
  DiMuEtaCanvash125->Write();

  DiMudRCanvash125->cd();
  DiMudRCanvash125->Draw();
  DiMudRCanvash125->Write();

  InvMassDiMuOverOverCanvash125->cd();
  InvMassDiMuOverOverCanvash125->Draw();
  InvMassDiMuOverOverCanvash125->Write();

  EtMETCanvash125->cd();
  EtMETCanvash125->Draw();
  EtMETCanvash125->Write();

  DiTauDiMuMassCanvash125->cd();
  DiTauDiMuMassCanvash125->Draw();
  DiTauDiMuMassCanvash125->Write();

  DiMuDiTauDeltaPhiCanvash125->cd();
  DiMuDiTauDeltaPhiCanvash125->Draw();
  DiMuDiTauDeltaPhiCanvash125->Write();

  METDiTauDeltaPhiCanvash125->cd();
  METDiTauDeltaPhiCanvash125->Draw();
  METDiTauDeltaPhiCanvash125->Write();

  METDiMuDeltaPhiCanvash125->cd();
  METDiMuDeltaPhiCanvash125->Draw();
  METDiMuDeltaPhiCanvash125->Write();

  DiTaudRCanvash125->cd();
  DiTaudRCanvash125->Draw();
  DiTaudRCanvash125->Write();

  DiTauMassSmallerdRCanvash125->cd();
  DiTauMassSmallerdRCanvash125->Draw();
  DiTauMassSmallerdRCanvash125->Write();

  HighestCSVInclJetCanvash125->cd();
  HighestCSVInclJetCanvash125->Draw();
  HighestCSVInclJetCanvash125->Write();


  NMedIsoTausWithMu3Canvash300->cd();
  NMedIsoTausWithMu3Canvash300->Draw();
  NMedIsoTausWithMu3Canvash300->Write();

  InvMassTauHadMu3Canvash300->cd();
  InvMassTauHadMu3Canvash300->Draw();
  InvMassTauHadMu3Canvash300->Write();

  PtTauHadMu3Canvash300->cd();
  PtTauHadMu3Canvash300->Draw();
  PtTauHadMu3Canvash300->Write();

  InvMassMu1TauMuCanvash300->cd();
  InvMassMu1TauMuCanvash300->Draw();
  InvMassMu1TauMuCanvash300->Write();

  InvMassMu2TauMuCanvash300->cd();
  InvMassMu2TauMuCanvash300->Draw();
  InvMassMu2TauMuCanvash300->Write();

  InvMassFullRangeCanvash300->cd();
  InvMassFullRangeCanvash300->Draw();
  InvMassFullRangeCanvash300->Write();

  InvMassDiMuBarrBarrCanvash300->cd();
  InvMassDiMuBarrBarrCanvash300->Draw();
  InvMassDiMuBarrBarrCanvash300->Write();

  InvMassDiMuBarrEndcCanvash300->cd();
  InvMassDiMuBarrEndcCanvash300->Draw();
  InvMassDiMuBarrEndcCanvash300->Write();

  InvMassDiMuEndcEndcCanvash300->cd();
  InvMassDiMuEndcEndcCanvash300->Draw();
  InvMassDiMuEndcEndcCanvash300->Write();

  Mu1PtCanvash300->cd();
  Mu1PtCanvash300->Draw();
  Mu1PtCanvash300->Write();

  Mu2PtCanvash300->cd();
  Mu2PtCanvash300->Draw();
  Mu2PtCanvash300->Write();

  DiMuPtCanvash300->cd();
  DiMuPtCanvash300->Draw();
  DiMuPtCanvash300->Write();

  InvMassDiMuBarrOverCanvash300->cd();
  InvMassDiMuBarrOverCanvash300->Draw();
  InvMassDiMuBarrOverCanvash300->Write();

  InvMassDiMuEndcOverCanvash300->cd();
  InvMassDiMuEndcOverCanvash300->Draw();
  InvMassDiMuEndcOverCanvash300->Write();

  DiTauEtaCanvash300->cd();
  DiTauEtaCanvash300->Draw();
  DiTauEtaCanvash300->Write();

  DiTauPhiCanvash300->cd();
  DiTauPhiCanvash300->Draw();
  DiTauPhiCanvash300->Write();

  DiMuEtaCanvash300->cd();
  DiMuEtaCanvash300->Draw();
  DiMuEtaCanvash300->Write();

  DiMudRCanvash300->cd();
  DiMudRCanvash300->Draw();
  DiMudRCanvash300->Write();

  InvMassDiMuOverOverCanvash300->cd();
  InvMassDiMuOverOverCanvash300->Draw();
  InvMassDiMuOverOverCanvash300->Write();

  EtMETCanvash300->cd();
  EtMETCanvash300->Draw();
  EtMETCanvash300->Write();

  DiTauDiMuMassCanvash300->cd();
  DiTauDiMuMassCanvash300->Draw();
  DiTauDiMuMassCanvash300->Write();

  DiMuDiTauDeltaPhiCanvash300->cd();
  DiMuDiTauDeltaPhiCanvash300->Draw();
  DiMuDiTauDeltaPhiCanvash300->Write();

  METDiTauDeltaPhiCanvash300->cd();
  METDiTauDeltaPhiCanvash300->Draw();
  METDiTauDeltaPhiCanvash300->Write();

  METDiMuDeltaPhiCanvash300->cd();
  METDiMuDeltaPhiCanvash300->Draw();
  METDiMuDeltaPhiCanvash300->Write();

  DiTaudRCanvash300->cd();
  DiTaudRCanvash300->Draw();
  DiTaudRCanvash300->Write();

  DiTauMassSmallerdRCanvash300->cd();
  DiTauMassSmallerdRCanvash300->Draw();
  DiTauMassSmallerdRCanvash300->Write();

  HighestCSVInclJetCanvash300->cd();
  HighestCSVInclJetCanvash300->Draw();
  HighestCSVInclJetCanvash300->Write();


  NMedIsoTausWithMu3Canvash750->cd();
  NMedIsoTausWithMu3Canvash750->Draw();
  NMedIsoTausWithMu3Canvash750->Write();

  InvMassTauHadMu3Canvash750->cd();
  InvMassTauHadMu3Canvash750->Draw();
  InvMassTauHadMu3Canvash750->Write();

  PtTauHadMu3Canvash750->cd();
  PtTauHadMu3Canvash750->Draw();
  PtTauHadMu3Canvash750->Write();

  InvMassMu2TauMuCanvash750->cd();
  InvMassMu2TauMuCanvash750->Draw();
  InvMassMu2TauMuCanvash750->Write();

  InvMassMu1TauMuCanvash750->cd();
  InvMassMu1TauMuCanvash750->Draw();
  InvMassMu1TauMuCanvash750->Write();

  InvMassFullRangeCanvash750->cd();
  InvMassFullRangeCanvash750->Draw();
  InvMassFullRangeCanvash750->Write();

  InvMassDiMuBarrBarrCanvash750->cd();
  InvMassDiMuBarrBarrCanvash750->Draw();
  InvMassDiMuBarrBarrCanvash750->Write();

  InvMassDiMuBarrEndcCanvash750->cd();
  InvMassDiMuBarrEndcCanvash750->Draw();
  InvMassDiMuBarrEndcCanvash750->Write();

  InvMassDiMuEndcEndcCanvash750->cd();
  InvMassDiMuEndcEndcCanvash750->Draw();
  InvMassDiMuEndcEndcCanvash750->Write();

  Mu1PtCanvash750->cd();
  Mu1PtCanvash750->Draw();
  Mu1PtCanvash750->Write();

  Mu2PtCanvash750->cd();
  Mu2PtCanvash750->Draw();
  Mu2PtCanvash750->Write();

  DiMuPtCanvash750->cd();
  DiMuPtCanvash750->Draw();
  DiMuPtCanvash750->Write();

  InvMassDiMuBarrOverCanvash750->cd();
  InvMassDiMuBarrOverCanvash750->Draw();
  InvMassDiMuBarrOverCanvash750->Write();

  InvMassDiMuEndcOverCanvash750->cd();
  InvMassDiMuEndcOverCanvash750->Draw();
  InvMassDiMuEndcOverCanvash750->Write();

  DiTauEtaCanvash750->cd();
  DiTauEtaCanvash750->Draw();
  DiTauEtaCanvash750->Write();

  DiTauPhiCanvash750->cd();
  DiTauPhiCanvash750->Draw();
  DiTauPhiCanvash750->Write();

  DiMuEtaCanvash750->cd();
  DiMuEtaCanvash750->Draw();
  DiMuEtaCanvash750->Write();

  DiMudRCanvash750->cd();
  DiMudRCanvash750->Draw();
  DiMudRCanvash750->Write();

  InvMassDiMuOverOverCanvash750->cd();
  InvMassDiMuOverOverCanvash750->Draw();
  InvMassDiMuOverOverCanvash750->Write();

  EtMETCanvash750->cd();
  EtMETCanvash750->Draw();
  EtMETCanvash750->Write();

  DiTauDiMuMassCanvash750->cd();
  DiTauDiMuMassCanvash750->Draw();
  DiTauDiMuMassCanvash750->Write();

  DiMuDiTauDeltaPhiCanvash750->cd();
  DiMuDiTauDeltaPhiCanvash750->Draw();
  DiMuDiTauDeltaPhiCanvash750->Write();

  METDiTauDeltaPhiCanvash750->cd();
  METDiTauDeltaPhiCanvash750->Draw();
  METDiTauDeltaPhiCanvash750->Write();

  METDiMuDeltaPhiCanvash750->cd();
  METDiMuDeltaPhiCanvash750->Draw();
  METDiMuDeltaPhiCanvash750->Write();

  DiTaudRCanvash750->cd();
  DiTaudRCanvash750->Draw();
  DiTaudRCanvash750->Write();

  DiTauMassSmallerdRCanvash750->cd();
  DiTauMassSmallerdRCanvash750->Draw();
  DiTauMassSmallerdRCanvash750->Write();

  HighestCSVInclJetCanvash750->cd();
  HighestCSVInclJetCanvash750->Draw();
  HighestCSVInclJetCanvash750->Write();

  TCanvas *NMedIsoTausWithMu3Canvas = new TCanvas ("NMedIsoTausWithMu3Canvas","",600,600);
  TCanvas *InvMassTauHadMu3Canvas = new TCanvas ("InvMassTauHadMu3Canvas","",600,600);
  TCanvas *PtTauHadMu3Canvas = new TCanvas ("PtTauHadMu3Canvas","",600,600);
  TCanvas *InvMassMu1TauMuCanvas = new TCanvas ("InvMassMu1TauMuCanvas","",600,600);
  TCanvas *InvMassMu2TauMuCanvas = new TCanvas ("InvMassMu2TauMuCanvas","",600,600);
  TCanvas *InvMassFullRangeCanvas = new TCanvas ("InvMassFullRangeCanvas","",600,600);
  TCanvas *InvMassDiMuBarrBarrCanvas = new TCanvas ("InvMassDiMuBarrBarrCanvas","",600,600);
  TCanvas *InvMassDiMuBarrEndcCanvas = new TCanvas ("InvMassDiMuBarrEndcCanvas","",600,600);
  TCanvas *InvMassDiMuEndcEndcCanvas = new TCanvas ("InvMassDiMuEndcEndcCanvas","",600,600);
  TCanvas *Mu1PtCanvas = new TCanvas ("Mu1PtCanvas","",600,600);
  TCanvas *Mu2PtCanvas = new TCanvas ("Mu2PtCanvas","",600,600);
  TCanvas *DiMuPtCanvas = new TCanvas ("DiMuPtCanvas","",600,600);
  TCanvas *InvMassDiMuBarrOverCanvas = new TCanvas ("InvMassDiMuBarrOverCanvas","",600,600);
  TCanvas *InvMassDiMuEndcOverCanvas = new TCanvas ("InvMassDiMuEndcOverCanvas","",600,600);
  TCanvas *DiTauEtaCanvas = new TCanvas ("DiTauEtaCanvas","",600,600);
  TCanvas *DiTauPhiCanvas = new TCanvas ("DiTauPhiCanvas","",600,600);
  TCanvas *DiMuEtaCanvas = new TCanvas ("DiMuEtaCanvas","",600,600);
  TCanvas *DiMudRCanvas = new TCanvas ("DiMudRCanvas","",600,600);
  TCanvas *InvMassDiMuOverOverCanvas = new TCanvas ("InvMassDiMuOverOverCanvas","",600,600);
  TCanvas *EtMETCanvas = new TCanvas ("EtMETCanvas","",600,600);
  TCanvas *DiTauDiMuMassCanvas = new TCanvas ("DiTauDiMuMassCanvas","",600,600);
  TCanvas *DiMuDiTauDeltaPhiCanvas = new TCanvas ("DiMuDiTauDeltaPhiCanvas","",600,600);
  TCanvas *METDiTauDeltaPhiCanvas = new TCanvas ("METDiTauDeltaPhiCanvas","",600,600);
  TCanvas *METDiMuDeltaPhiCanvas = new TCanvas ("METDiMuDeltaPhiCanvas","",600,600);
  TCanvas *DiTaudRCanvas = new TCanvas ("DiTaudRCanvas","",600,600);
  TCanvas *DiTauMassSmallerdRCanvas = new TCanvas ("DiTauMassSmallerdRCanvas","",600,600);
  TCanvas *HighestCSVInclJetCanvas = new TCanvas ("HighestCSVInclJetCanvas","",600,600);

  NMedIsoTausWithMu3Canvas->Divide(3,1);
  InvMassTauHadMu3Canvas->Divide(3,1);
  PtTauHadMu3Canvas->Divide(3,1);
  InvMassMu1TauMuCanvas->Divide(3,1);
  InvMassMu2TauMuCanvas->Divide(3,1);
  InvMassFullRangeCanvas->Divide(3,1);
  InvMassDiMuBarrBarrCanvas->Divide(3,1);
  InvMassDiMuBarrEndcCanvas->Divide(3,1);
  InvMassDiMuEndcEndcCanvas->Divide(3,1);
  Mu1PtCanvas->Divide(3,1);
  Mu2PtCanvas->Divide(3,1);
  DiMuPtCanvas->Divide(3,1);
  InvMassDiMuBarrOverCanvas->Divide(3,1);
  InvMassDiMuEndcOverCanvas->Divide(3,1);
  DiTauEtaCanvas->Divide(3,1);
  DiTauPhiCanvas->Divide(3,1);
  DiMuEtaCanvas->Divide(3,1);
  DiMudRCanvas->Divide(3,1);
  InvMassDiMuOverOverCanvas->Divide(3,1);
  EtMETCanvas->Divide(3,1);
  DiTauDiMuMassCanvas->Divide(3,1);
  DiMuDiTauDeltaPhiCanvas->Divide(3,1);
  METDiTauDeltaPhiCanvas->Divide(3,1);
  METDiMuDeltaPhiCanvas->Divide(3,1);
  DiTaudRCanvas->Divide(3,1);
  DiTauMassSmallerdRCanvas->Divide(3,1);
  HighestCSVInclJetCanvas->Divide(3,1);

  NMedIsoTausWithMu3Canvas->cd(1);
  NMedIsoTausWithMu3Canvash125->DrawClonePad();
  NMedIsoTausWithMu3Canvas->cd(2);
  NMedIsoTausWithMu3Canvash300->DrawClonePad();
  NMedIsoTausWithMu3Canvas->cd(3);
  NMedIsoTausWithMu3Canvash750->DrawClonePad();
  NMedIsoTausWithMu3Canvas->Draw();
  NMedIsoTausWithMu3Canvas->Write();

  InvMassTauHadMu3Canvas->cd(1);
  InvMassTauHadMu3Canvash125->DrawClonePad();
  InvMassTauHadMu3Canvas->cd(2);
  InvMassTauHadMu3Canvash300->DrawClonePad();
  InvMassTauHadMu3Canvas->cd(3);
  InvMassTauHadMu3Canvash750->DrawClonePad();
  InvMassTauHadMu3Canvas->Draw();
  InvMassTauHadMu3Canvas->Write();

  PtTauHadMu3Canvas->cd(1);
  PtTauHadMu3Canvash125->DrawClonePad();
  PtTauHadMu3Canvas->cd(2);
  PtTauHadMu3Canvash300->DrawClonePad();
  PtTauHadMu3Canvas->cd(3);
  PtTauHadMu3Canvash750->DrawClonePad();
  PtTauHadMu3Canvas->Draw();
  PtTauHadMu3Canvas->Write();

  InvMassMu1TauMuCanvas->cd(1);
  InvMassMu1TauMuCanvash125->DrawClonePad();
  InvMassMu1TauMuCanvas->cd(2);
  InvMassMu1TauMuCanvash300->DrawClonePad();
  InvMassMu1TauMuCanvas->cd(3);
  InvMassMu1TauMuCanvash750->DrawClonePad();
  InvMassMu1TauMuCanvas->Draw();
  InvMassMu1TauMuCanvas->Write();

  InvMassMu2TauMuCanvas->cd(1);
  InvMassMu2TauMuCanvash125->DrawClonePad();
  InvMassMu2TauMuCanvas->cd(2);
  InvMassMu2TauMuCanvash300->DrawClonePad();
  InvMassMu2TauMuCanvas->cd(3);
  InvMassMu2TauMuCanvash750->DrawClonePad();
  InvMassMu2TauMuCanvas->Draw();
  InvMassMu2TauMuCanvas->Write();

  InvMassFullRangeCanvas->cd(1);
  InvMassFullRangeCanvash125->DrawClonePad();
  InvMassFullRangeCanvas->cd(2);
  InvMassFullRangeCanvash300->DrawClonePad();
  InvMassFullRangeCanvas->cd(3);
  InvMassFullRangeCanvash750->DrawClonePad();
  InvMassFullRangeCanvas->Draw();
  InvMassFullRangeCanvas->Write();

  InvMassDiMuBarrBarrCanvas->cd(1);
  InvMassDiMuBarrBarrCanvash125->DrawClonePad();
  InvMassDiMuBarrBarrCanvas->cd(2);
  InvMassDiMuBarrBarrCanvash300->DrawClonePad();
  InvMassDiMuBarrBarrCanvas->cd(3);
  InvMassDiMuBarrBarrCanvash750->DrawClonePad();
  InvMassDiMuBarrBarrCanvas->Draw();
  InvMassDiMuBarrBarrCanvas->Write();

  InvMassDiMuBarrEndcCanvas->cd(1);
  InvMassDiMuBarrEndcCanvash125->DrawClonePad();
  InvMassDiMuBarrEndcCanvas->cd(2);
  InvMassDiMuBarrEndcCanvash300->DrawClonePad();
  InvMassDiMuBarrEndcCanvas->cd(3);
  InvMassDiMuBarrEndcCanvash750->DrawClonePad();
  InvMassDiMuBarrEndcCanvas->Draw();
  InvMassDiMuBarrEndcCanvas->Write();

  InvMassDiMuEndcEndcCanvas->cd(1);
  InvMassDiMuEndcEndcCanvash125->DrawClonePad();
  InvMassDiMuEndcEndcCanvas->cd(2);
  InvMassDiMuEndcEndcCanvash300->DrawClonePad();
  InvMassDiMuEndcEndcCanvas->cd(3);
  InvMassDiMuEndcEndcCanvash750->DrawClonePad();
  InvMassDiMuEndcEndcCanvas->Draw();
  InvMassDiMuEndcEndcCanvas->Write();

  Mu1PtCanvas->cd(1);
  Mu1PtCanvash125->DrawClonePad();
  Mu1PtCanvas->cd(2);
  Mu1PtCanvash300->DrawClonePad();
  Mu1PtCanvas->cd(3);
  Mu1PtCanvash750->DrawClonePad();
  Mu1PtCanvas->Draw();
  Mu1PtCanvas->Write();

  Mu2PtCanvas->cd(1);
  Mu2PtCanvash125->DrawClonePad();
  Mu2PtCanvas->cd(2);
  Mu2PtCanvash300->DrawClonePad();
  Mu2PtCanvas->cd(3);
  Mu2PtCanvash750->DrawClonePad();
  Mu2PtCanvas->Draw();
  Mu2PtCanvas->Write();

  DiMuPtCanvas->cd(1);
  DiMuPtCanvash125->DrawClonePad();
  DiMuPtCanvas->cd(2);
  DiMuPtCanvash300->DrawClonePad();
  DiMuPtCanvas->cd(3);
  DiMuPtCanvash750->DrawClonePad();
  DiMuPtCanvas->Draw();
  DiMuPtCanvas->Write();

  InvMassDiMuBarrOverCanvas->cd(1);
  InvMassDiMuBarrOverCanvash125->DrawClonePad();
  InvMassDiMuBarrOverCanvas->cd(2);
  InvMassDiMuBarrOverCanvash300->DrawClonePad();
  InvMassDiMuBarrOverCanvas->cd(3);
  InvMassDiMuBarrOverCanvash750->DrawClonePad();
  InvMassDiMuBarrOverCanvas->Draw();
  InvMassDiMuBarrOverCanvas->Write();

  InvMassDiMuEndcOverCanvas->cd(1);
  InvMassDiMuEndcOverCanvash125->DrawClonePad();
  InvMassDiMuEndcOverCanvas->cd(2);
  InvMassDiMuEndcOverCanvash300->DrawClonePad();
  InvMassDiMuEndcOverCanvas->cd(3);
  InvMassDiMuEndcOverCanvash750->DrawClonePad();
  InvMassDiMuEndcOverCanvas->Draw();
  InvMassDiMuEndcOverCanvas->Write();

  DiTauEtaCanvas->cd(1);
  DiTauEtaCanvash125->DrawClonePad();
  DiTauEtaCanvas->cd(2);
  DiTauEtaCanvash300->DrawClonePad();
  DiTauEtaCanvas->cd(3);
  DiTauEtaCanvash750->DrawClonePad();
  DiTauEtaCanvas->Draw();
  DiTauEtaCanvas->Write();

  DiTauPhiCanvas->cd(1);
  DiTauPhiCanvash125->DrawClonePad();
  DiTauPhiCanvas->cd(2);
  DiTauPhiCanvash300->DrawClonePad();
  DiTauPhiCanvas->cd(3);
  DiTauPhiCanvash750->DrawClonePad();
  DiTauPhiCanvas->Draw();
  DiTauPhiCanvas->Write();

  DiMuEtaCanvas->cd(1);
  DiMuEtaCanvash125->DrawClonePad();
  DiMuEtaCanvas->cd(2);
  DiMuEtaCanvash300->DrawClonePad();
  DiMuEtaCanvas->cd(3);
  DiMuEtaCanvash750->DrawClonePad();
  DiMuEtaCanvas->Draw();
  DiMuEtaCanvas->Write();

  DiMudRCanvas->cd(1);
  DiMudRCanvash125->DrawClonePad();
  DiMudRCanvas->cd(2);
  DiMudRCanvash300->DrawClonePad();
  DiMudRCanvas->cd(3);
  DiMudRCanvash750->DrawClonePad();
  DiMudRCanvas->Draw();
  DiMudRCanvas->Write();

  InvMassDiMuOverOverCanvas->cd(1);
  InvMassDiMuOverOverCanvash125->DrawClonePad();
  InvMassDiMuOverOverCanvas->cd(2);
  InvMassDiMuOverOverCanvash300->DrawClonePad();
  InvMassDiMuOverOverCanvas->cd(3);
  InvMassDiMuOverOverCanvash750->DrawClonePad();
  InvMassDiMuOverOverCanvas->Draw();
  InvMassDiMuOverOverCanvas->Write();

  EtMETCanvas->cd(1);
  EtMETCanvash125->DrawClonePad();
  EtMETCanvas->cd(2);
  EtMETCanvash300->DrawClonePad();
  EtMETCanvas->cd(3);
  EtMETCanvash750->DrawClonePad();
  EtMETCanvas->Draw();
  EtMETCanvas->Write();

  DiTauDiMuMassCanvas->cd(1);
  DiTauDiMuMassCanvash125->DrawClonePad();
  DiTauDiMuMassCanvas->cd(2);
  DiTauDiMuMassCanvash300->DrawClonePad();
  DiTauDiMuMassCanvas->cd(3);
  DiTauDiMuMassCanvash750->DrawClonePad();
  DiTauDiMuMassCanvas->Draw();
  DiTauDiMuMassCanvas->Write();

  DiMuDiTauDeltaPhiCanvas->cd(1);
  DiMuDiTauDeltaPhiCanvash125->DrawClonePad();
  DiMuDiTauDeltaPhiCanvas->cd(2);
  DiMuDiTauDeltaPhiCanvash300->DrawClonePad();
  DiMuDiTauDeltaPhiCanvas->cd(3);
  DiMuDiTauDeltaPhiCanvash750->DrawClonePad();
  DiMuDiTauDeltaPhiCanvas->Draw();
  DiMuDiTauDeltaPhiCanvas->Write();

  METDiTauDeltaPhiCanvas->cd(1);
  METDiTauDeltaPhiCanvash125->DrawClonePad();
  METDiTauDeltaPhiCanvas->cd(2);
  METDiTauDeltaPhiCanvash300->DrawClonePad();
  METDiTauDeltaPhiCanvas->cd(3);
  METDiTauDeltaPhiCanvash750->DrawClonePad();
  METDiTauDeltaPhiCanvas->Draw();
  METDiTauDeltaPhiCanvas->Write();

  METDiMuDeltaPhiCanvas->cd(1);
  METDiMuDeltaPhiCanvash125->DrawClonePad();
  METDiMuDeltaPhiCanvas->cd(2);
  METDiMuDeltaPhiCanvash300->DrawClonePad();
  METDiMuDeltaPhiCanvas->cd(3);
  METDiMuDeltaPhiCanvash750->DrawClonePad();
  METDiMuDeltaPhiCanvas->Draw();
  METDiMuDeltaPhiCanvas->Write();

  DiTaudRCanvas->cd(1);
  DiTaudRCanvash125->DrawClonePad();
  DiTaudRCanvas->cd(2);
  DiTaudRCanvash300->DrawClonePad();
  DiTaudRCanvas->cd(3);
  DiTaudRCanvash750->DrawClonePad();
  DiTaudRCanvas->Draw();
  DiTaudRCanvas->Write();

  DiTauMassSmallerdRCanvas->cd(1);
  DiTauMassSmallerdRCanvash125->DrawClonePad();
  DiTauMassSmallerdRCanvas->cd(2);
  DiTauMassSmallerdRCanvash300->DrawClonePad();
  DiTauMassSmallerdRCanvas->cd(3);
  DiTauMassSmallerdRCanvash750->DrawClonePad();
  DiTauMassSmallerdRCanvas->Draw();
  DiTauMassSmallerdRCanvas->Write();

  HighestCSVInclJetCanvas->cd(1);
  HighestCSVInclJetCanvash125->DrawClonePad();
  HighestCSVInclJetCanvas->cd(2);
  HighestCSVInclJetCanvash300->DrawClonePad();
  HighestCSVInclJetCanvas->cd(3);
  HighestCSVInclJetCanvash750->DrawClonePad();
  HighestCSVInclJetCanvas->Draw();
  HighestCSVInclJetCanvas->Write();


  TCanvas *DiMuMassAllEtaRegionsCanvas = new TCanvas ("DiMuMassAllEtaRegionsCanvas","",600,600);
  DiMuMassAllEtaRegionsCanvas->cd();
  InvMassDiMuBarrBarrh125a9_->SetLineColor(kBlack);
  InvMassDiMuBarrEndch125a9_->SetLineColor(kBlue);
  InvMassDiMuEndcEndch125a9_->SetLineColor(kRed);
  InvMassDiMuBarrOverh125a9_->SetLineColor(kGreen);
  InvMassDiMuEndcOverh125a9_->SetLineColor(kYellow);
  InvMassDiMuOverOverh125a9_->SetLineColor(kCyan+2);
  InvMassDiMuBarrBarrh125a9_->Draw();
  InvMassDiMuBarrEndch125a9_->Draw("SAME");
  InvMassDiMuEndcEndch125a9_->Draw("SAME");
  InvMassDiMuBarrOverh125a9_->Draw("SAME");
  InvMassDiMuEndcOverh125a9_->Draw("SAME");
  InvMassDiMuOverOverh125a9_->Draw("SAME");
  legend1 = new TLegend(0.7,0.5,0.95,0.575) ;
  legend1->SetTextFont(42);
  legend1->SetBorderSize(0);
  legend1->SetFillColor(0);
  legend1->AddEntry(InvMassDiMuBarrBarrh125a9_, "BB", "f");
  legend1->AddEntry(InvMassDiMuBarrEndch125a9_, "BE", "f");
  legend1->AddEntry(InvMassDiMuEndcEndch125a9_, "EE", "f");
  legend1->AddEntry(InvMassDiMuBarrOverh125a9_, "BO", "f");
  legend1->AddEntry(InvMassDiMuEndcOverh125a9_, "EO", "f");
  legend1->AddEntry(InvMassDiMuOverOverh125a9_, "OO", "f");
  legend1->Draw();
  DiMuMassAllEtaRegionsCanvas->Draw();
  DiMuMassAllEtaRegionsCanvas->Write();

  outFile->Write();
  outFile->Close();

cout << "end" << endl;

}//rootMacro_BBA_combine
