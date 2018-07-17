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

void rootMacro_DiMu_ExtraPlots_DisplayAllRegions()
{
  setTDRStyle(true);
  gStyle->SetPalette(1);


  //Old DMs
  TFile infileRegionA("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Stack_DiMu_ExtraPlots_MCOverlay_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileRegionB("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Stack_DiMu_ExtraPlots_MCOverlay_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileRegionC("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Stack_DiMu_ExtraPlots_MCOverlay_AntiMedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileRegionD("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Stack_DiMu_ExtraPlots_MCOverlay_AntiMedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileh125a9A("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a9_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh125a9B("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMAntiMedIso/FINAL_MiniAOD_SIG_h125a9_MedIsoMu2_TauDMAntiMedIso_FEB8.root");
  TFile infileh125a9C("/home/kyletos/Downloads/RootFiles/ABCD_Tests/AntiMedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a9_AntiMedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh125a9D("/home/kyletos/Downloads/RootFiles/ABCD_Tests/AntiMedIsoMu2_TauDMAntiMedIso/FINAL_MiniAOD_SIG_h125a9_AntiMedIsoMu2_TauDMAntiMedIso_FEB8.root");


  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Stack_DiMu_ExtraPlots_MCOverlay_AllRegions_FEB8.root", "RECREATE");

cout << "Files Created" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Canvases
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////
  // RegionC
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasRegionC = (TCanvas*)infileRegionC.Get("NMedIsoTausWithMu3Canvas");
  TCanvas *InvMassTauHadMu3CanvasRegionC = (TCanvas*)infileRegionC.Get("InvMassTauHadMu3Canvas");
  TCanvas *PtTauHadMu3CanvasRegionC = (TCanvas*)infileRegionC.Get("PtTauHadMu3Canvas");
  TCanvas *InvMassMu1TauMuCanvasRegionC = (TCanvas*)infileRegionC.Get("InvMassMu1TauMuCanvas");
  TCanvas *InvMassMu2TauMuCanvasRegionC = (TCanvas*)infileRegionC.Get("InvMassMu2TauMuCanvas");
  TCanvas *InvMassFullRangeCanvasRegionC = (TCanvas*)infileRegionC.Get("InvMassFullRangeCanvas");
  TCanvas *InvMassDiMuBarrBarrCanvasRegionC = (TCanvas*)infileRegionC.Get("InvMassDiMuBarrBarrCanvas");
  TCanvas *InvMassDiMuBarrEndcCanvasRegionC = (TCanvas*)infileRegionC.Get("InvMassDiMuBarrEndcCanvas");
  TCanvas *InvMassDiMuEndcEndcCanvasRegionC = (TCanvas*)infileRegionC.Get("InvMassDiMuEndcEndcCanvas");
  TCanvas *Mu1PtCanvasRegionC = (TCanvas*)infileRegionC.Get("Mu1PtCanvas");
  TCanvas *Mu2PtCanvasRegionC = (TCanvas*)infileRegionC.Get("Mu2PtCanvas");
  TCanvas *DiMuPtCanvasRegionC = (TCanvas*)infileRegionC.Get("DiMuPtCanvas");
  TCanvas *Mu1EtaCanvasRegionC = (TCanvas*)infileRegionC.Get("Mu1EtaCanvas");
  TCanvas *Mu2EtaCanvasRegionC = (TCanvas*)infileRegionC.Get("Mu2EtaCanvas");
  TCanvas *DiTauEtaCanvasRegionC = (TCanvas*)infileRegionC.Get("DiTauEtaCanvas");
  TCanvas *DiTauPhiCanvasRegionC = (TCanvas*)infileRegionC.Get("DiTauPhiCanvas");
  TCanvas *DiMuEtaCanvasRegionC = (TCanvas*)infileRegionC.Get("DiMuEtaCanvas");
  TCanvas *DiMudRCanvasRegionC = (TCanvas*)infileRegionC.Get("DiMudRCanvas");
  TCanvas *DiMuPhiCanvasRegionC = (TCanvas*)infileRegionC.Get("DiMuPhiCanvas");
  TCanvas *EtMETCanvasRegionC = (TCanvas*)infileRegionC.Get("EtMETCanvas");
  TCanvas *DiTauDiMuMassCanvasRegionC = (TCanvas*)infileRegionC.Get("DiTauDiMuMassCanvas");
  TCanvas *DiMuDiTauDeltaPhiCanvasRegionC = (TCanvas*)infileRegionC.Get("DiMuDiTauDeltaPhiCanvas");
  TCanvas *METDiTauDeltaPhiCanvasRegionC = (TCanvas*)infileRegionC.Get("METDiMuDeltaPhiCanvas");
  TCanvas *METDiMuDeltaPhiCanvasRegionC = (TCanvas*)infileRegionC.Get("METDiMuDeltaPhiCanvas");
  TCanvas *DiTaudRCanvasRegionC = (TCanvas*)infileRegionC.Get("DiTaudRCanvas");
  TCanvas *DiTauMassSmallerdRCanvasRegionC = (TCanvas*)infileRegionC.Get("DiTauMassSmallerdRCanvas");
  TCanvas *ZMassdRCanvasRegionC = (TCanvas*)infileRegionC.Get("ZMassdRCanvas");

  ////////////////
  // RegionA
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasRegionA = (TCanvas*)infileRegionA.Get("NMedIsoTausWithMu3Canvas");
  TCanvas *InvMassTauHadMu3CanvasRegionA = (TCanvas*)infileRegionA.Get("InvMassTauHadMu3Canvas");
  TCanvas *PtTauHadMu3CanvasRegionA = (TCanvas*)infileRegionA.Get("PtTauHadMu3Canvas");
  TCanvas *InvMassMu1TauMuCanvasRegionA = (TCanvas*)infileRegionA.Get("InvMassMu1TauMuCanvas");
  TCanvas *InvMassMu2TauMuCanvasRegionA = (TCanvas*)infileRegionA.Get("InvMassMu2TauMuCanvas");
  TCanvas *InvMassFullRangeCanvasRegionA = (TCanvas*)infileRegionA.Get("InvMassFullRangeCanvas");
  TCanvas *InvMassDiMuBarrBarrCanvasRegionA = (TCanvas*)infileRegionA.Get("InvMassDiMuBarrBarrCanvas");
  TCanvas *InvMassDiMuBarrEndcCanvasRegionA = (TCanvas*)infileRegionA.Get("InvMassDiMuBarrEndcCanvas");
  TCanvas *InvMassDiMuEndcEndcCanvasRegionA = (TCanvas*)infileRegionA.Get("InvMassDiMuEndcEndcCanvas");
  TCanvas *Mu1PtCanvasRegionA = (TCanvas*)infileRegionA.Get("Mu1PtCanvas");
  TCanvas *Mu2PtCanvasRegionA = (TCanvas*)infileRegionA.Get("Mu2PtCanvas");
  TCanvas *DiMuPtCanvasRegionA = (TCanvas*)infileRegionA.Get("DiMuPtCanvas");
  TCanvas *Mu1EtaCanvasRegionA = (TCanvas*)infileRegionA.Get("Mu1EtaCanvas");
  TCanvas *Mu2EtaCanvasRegionA = (TCanvas*)infileRegionA.Get("Mu2EtaCanvas");
  TCanvas *DiTauEtaCanvasRegionA = (TCanvas*)infileRegionA.Get("DiTauEtaCanvas");
  TCanvas *DiTauPhiCanvasRegionA = (TCanvas*)infileRegionA.Get("DiTauPhiCanvas");
  TCanvas *DiMuEtaCanvasRegionA = (TCanvas*)infileRegionA.Get("DiMuEtaCanvas");
  TCanvas *DiMudRCanvasRegionA = (TCanvas*)infileRegionA.Get("DiMudRCanvas");
  TCanvas *DiMuPhiCanvasRegionA = (TCanvas*)infileRegionA.Get("DiMuPhiCanvas");
  TCanvas *EtMETCanvasRegionA = (TCanvas*)infileRegionA.Get("EtMETCanvas");
  TCanvas *DiTauDiMuMassCanvasRegionA = (TCanvas*)infileRegionA.Get("DiTauDiMuMassCanvas");
  TCanvas *DiMuDiTauDeltaPhiCanvasRegionA = (TCanvas*)infileRegionA.Get("DiMuDiTauDeltaPhiCanvas");
  TCanvas *METDiTauDeltaPhiCanvasRegionA = (TCanvas*)infileRegionA.Get("METDiMuDeltaPhiCanvas");
  TCanvas *METDiMuDeltaPhiCanvasRegionA = (TCanvas*)infileRegionA.Get("METDiMuDeltaPhiCanvas");
  TCanvas *DiTaudRCanvasRegionA = (TCanvas*)infileRegionA.Get("DiTaudRCanvas");
  TCanvas *DiTauMassSmallerdRCanvasRegionA = (TCanvas*)infileRegionA.Get("DiTauMassSmallerdRCanvas");
  TCanvas *ZMassdRCanvasRegionA = (TCanvas*)infileRegionA.Get("ZMassdRCanvas");

  ////////////////
  // RegionB
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasRegionB = (TCanvas*)infileRegionB.Get("NMedIsoTausWithMu3Canvas");
  TCanvas *InvMassTauHadMu3CanvasRegionB = (TCanvas*)infileRegionB.Get("InvMassTauHadMu3Canvas");
  TCanvas *PtTauHadMu3CanvasRegionB = (TCanvas*)infileRegionB.Get("PtTauHadMu3Canvas");
  TCanvas *InvMassMu1TauMuCanvasRegionB = (TCanvas*)infileRegionB.Get("InvMassMu1TauMuCanvas");
  TCanvas *InvMassMu2TauMuCanvasRegionB = (TCanvas*)infileRegionB.Get("InvMassMu2TauMuCanvas");
  TCanvas *InvMassFullRangeCanvasRegionB = (TCanvas*)infileRegionB.Get("InvMassFullRangeCanvas");
  TCanvas *InvMassDiMuBarrBarrCanvasRegionB = (TCanvas*)infileRegionB.Get("InvMassDiMuBarrBarrCanvas");
  TCanvas *InvMassDiMuBarrEndcCanvasRegionB = (TCanvas*)infileRegionB.Get("InvMassDiMuBarrEndcCanvas");
  TCanvas *InvMassDiMuEndcEndcCanvasRegionB = (TCanvas*)infileRegionB.Get("InvMassDiMuEndcEndcCanvas");
  TCanvas *Mu1PtCanvasRegionB = (TCanvas*)infileRegionB.Get("Mu1PtCanvas");
  TCanvas *Mu2PtCanvasRegionB = (TCanvas*)infileRegionB.Get("Mu2PtCanvas");
  TCanvas *DiMuPtCanvasRegionB = (TCanvas*)infileRegionB.Get("DiMuPtCanvas");
  TCanvas *Mu1EtaCanvasRegionB = (TCanvas*)infileRegionB.Get("Mu1EtaCanvas");
  TCanvas *Mu2EtaCanvasRegionB = (TCanvas*)infileRegionB.Get("Mu2EtaCanvas");
  TCanvas *DiTauEtaCanvasRegionB = (TCanvas*)infileRegionB.Get("DiTauEtaCanvas");
  TCanvas *DiTauPhiCanvasRegionB = (TCanvas*)infileRegionB.Get("DiTauPhiCanvas");
  TCanvas *DiMuEtaCanvasRegionB = (TCanvas*)infileRegionB.Get("DiMuEtaCanvas");
  TCanvas *DiMudRCanvasRegionB = (TCanvas*)infileRegionB.Get("DiMudRCanvas");
  TCanvas *DiMuPhiCanvasRegionB = (TCanvas*)infileRegionB.Get("DiMuPhiCanvas");
  TCanvas *EtMETCanvasRegionB = (TCanvas*)infileRegionB.Get("EtMETCanvas");
  TCanvas *DiTauDiMuMassCanvasRegionB = (TCanvas*)infileRegionB.Get("DiTauDiMuMassCanvas");
  TCanvas *DiMuDiTauDeltaPhiCanvasRegionB = (TCanvas*)infileRegionB.Get("DiMuDiTauDeltaPhiCanvas");
  TCanvas *METDiTauDeltaPhiCanvasRegionB = (TCanvas*)infileRegionB.Get("METDiMuDeltaPhiCanvas");
  TCanvas *METDiMuDeltaPhiCanvasRegionB = (TCanvas*)infileRegionB.Get("METDiMuDeltaPhiCanvas");
  TCanvas *DiTaudRCanvasRegionB = (TCanvas*)infileRegionB.Get("DiTaudRCanvas");
  TCanvas *DiTauMassSmallerdRCanvasRegionB = (TCanvas*)infileRegionB.Get("DiTauMassSmallerdRCanvas");
  TCanvas *ZMassdRCanvasRegionB = (TCanvas*)infileRegionB.Get("ZMassdRCanvas");

  ////////////////
  // RegionD
  ////////////////
  TCanvas *NMedIsoTausWithMu3CanvasRegionD = (TCanvas*)infileRegionD.Get("NMedIsoTausWithMu3Canvas");
  TCanvas *InvMassTauHadMu3CanvasRegionD = (TCanvas*)infileRegionD.Get("InvMassTauHadMu3Canvas");
  TCanvas *PtTauHadMu3CanvasRegionD = (TCanvas*)infileRegionD.Get("PtTauHadMu3Canvas");
  TCanvas *InvMassMu1TauMuCanvasRegionD = (TCanvas*)infileRegionD.Get("InvMassMu1TauMuCanvas");
  TCanvas *InvMassMu2TauMuCanvasRegionD = (TCanvas*)infileRegionD.Get("InvMassMu2TauMuCanvas");
  TCanvas *InvMassFullRangeCanvasRegionD = (TCanvas*)infileRegionD.Get("InvMassFullRangeCanvas");
  TCanvas *InvMassDiMuBarrBarrCanvasRegionD = (TCanvas*)infileRegionD.Get("InvMassDiMuBarrBarrCanvas");
  TCanvas *InvMassDiMuBarrEndcCanvasRegionD = (TCanvas*)infileRegionD.Get("InvMassDiMuBarrEndcCanvas");
  TCanvas *InvMassDiMuEndcEndcCanvasRegionD = (TCanvas*)infileRegionD.Get("InvMassDiMuEndcEndcCanvas");
  TCanvas *Mu1PtCanvasRegionD = (TCanvas*)infileRegionD.Get("Mu1PtCanvas");
  TCanvas *Mu2PtCanvasRegionD = (TCanvas*)infileRegionD.Get("Mu2PtCanvas");
  TCanvas *DiMuPtCanvasRegionD = (TCanvas*)infileRegionD.Get("DiMuPtCanvas");
  TCanvas *Mu1EtaCanvasRegionD = (TCanvas*)infileRegionD.Get("Mu1EtaCanvas");
  TCanvas *Mu2EtaCanvasRegionD = (TCanvas*)infileRegionD.Get("Mu2EtaCanvas");
  TCanvas *DiTauEtaCanvasRegionD = (TCanvas*)infileRegionD.Get("DiTauEtaCanvas");
  TCanvas *DiTauPhiCanvasRegionD = (TCanvas*)infileRegionD.Get("DiTauPhiCanvas");
  TCanvas *DiMuEtaCanvasRegionD = (TCanvas*)infileRegionD.Get("DiMuEtaCanvas");
  TCanvas *DiMudRCanvasRegionD = (TCanvas*)infileRegionD.Get("DiMudRCanvas");
  TCanvas *DiMuPhiCanvasRegionD = (TCanvas*)infileRegionD.Get("DiMuPhiCanvas");
  TCanvas *EtMETCanvasRegionD = (TCanvas*)infileRegionD.Get("EtMETCanvas");
  TCanvas *DiTauDiMuMassCanvasRegionD = (TCanvas*)infileRegionD.Get("DiTauDiMuMassCanvas");
  TCanvas *DiMuDiTauDeltaPhiCanvasRegionD = (TCanvas*)infileRegionD.Get("DiMuDiTauDeltaPhiCanvas");
  TCanvas *METDiTauDeltaPhiCanvasRegionD = (TCanvas*)infileRegionD.Get("METDiMuDeltaPhiCanvas");
  TCanvas *METDiMuDeltaPhiCanvasRegionD = (TCanvas*)infileRegionD.Get("METDiMuDeltaPhiCanvas");
  TCanvas *DiTaudRCanvasRegionD = (TCanvas*)infileRegionD.Get("DiTaudRCanvas");
  TCanvas *DiTauMassSmallerdRCanvasRegionD = (TCanvas*)infileRegionD.Get("DiTauMassSmallerdRCanvas");
  TCanvas *ZMassdRCanvasRegionD = (TCanvas*)infileRegionD.Get("ZMassdRCanvas");

cout << "Got Canvases" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Histograms fromm the Canvases
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ////////////////
  // RegionC
  ////////////////
  THStack *NMedIsoTausWithMu3RegionC_ = (THStack*)NMedIsoTausWithMu3CanvasRegionC->GetPrimitive("NMedIsoTausWithMu3Stack");
  THStack *InvMassTauHadMu3RegionC_ = (THStack*)InvMassTauHadMu3CanvasRegionC->GetPrimitive("InvMassTauHadMu3Stack");
  THStack *PtTauHadMu3RegionC_ = (THStack*)PtTauHadMu3CanvasRegionC->GetPrimitive("PtTauHadMu3Stack");
  THStack *InvMassMu1TauMuRegionC_ = (THStack*)InvMassMu1TauMuCanvasRegionC->GetPrimitive("InvMassMu1TauMuStack");
  THStack *InvMassMu2TauMuRegionC_ = (THStack*)InvMassMu2TauMuCanvasRegionC->GetPrimitive("InvMassMu2TauMuStack");
  THStack *InvMassFullRangeRegionC_ = (THStack*)InvMassFullRangeCanvasRegionC->GetPrimitive("InvMassFullRangeStack");
  THStack *InvMassDiMuBarrBarrRegionC_ = (THStack*)InvMassDiMuBarrBarrCanvasRegionC->GetPrimitive("InvMassDiMuBarrBarrStack");
  THStack *InvMassDiMuBarrEndcRegionC_ = (THStack*)InvMassDiMuBarrEndcCanvasRegionC->GetPrimitive("InvMassDiMuBarrEndcStack");
  THStack *InvMassDiMuEndcEndcRegionC_ = (THStack*)InvMassDiMuEndcEndcCanvasRegionC->GetPrimitive("InvMassDiMuEndcEndcStack");
  THStack *Mu1PtRegionC_ = (THStack*)Mu1PtCanvasRegionC->GetPrimitive("Mu1PtStack");
  THStack *Mu2PtRegionC_ = (THStack*)Mu2PtCanvasRegionC->GetPrimitive("Mu2PtStack");
  THStack *DiMuPtRegionC_ = (THStack*)DiMuPtCanvasRegionC->GetPrimitive("DiMuPtStack");
  THStack *Mu1EtaRegionC_ = (THStack*)Mu1EtaCanvasRegionC->GetPrimitive("Mu1EtaStack");
  THStack *Mu2EtaRegionC_ = (THStack*)Mu2EtaCanvasRegionC->GetPrimitive("Mu2EtaStack");
  THStack *DiTauEtaRegionC_ = (THStack*)DiTauEtaCanvasRegionC->GetPrimitive("DiTauEtaStack");
  THStack *DiTauPhiRegionC_ = (THStack*)DiTauPhiCanvasRegionC->GetPrimitive("DiTauPhiStack");
  THStack *DiMuEtaRegionC_ = (THStack*)DiMuEtaCanvasRegionC->GetPrimitive("DiMuEtaStack");
  THStack *DiMudRRegionC_ = (THStack*)DiMudRCanvasRegionC->GetPrimitive("DiMudRStack");
  THStack *DiMuPhiRegionC_ = (THStack*)DiMuPhiCanvasRegionC->GetPrimitive("DiMuPhiStack");
  THStack *EtMETRegionC_ = (THStack*)EtMETCanvasRegionC->GetPrimitive("EtMETStack");
  THStack *DiTauDiMuMassRegionC_ = (THStack*)DiTauDiMuMassCanvasRegionC->GetPrimitive("DiTauDiMuMassStack");
  THStack *DiMuDiTauDeltaPhiRegionC_ = (THStack*)DiMuDiTauDeltaPhiCanvasRegionC->GetPrimitive("DiMuDiTauDeltaPhiStack");
  THStack *METDiTauDeltaPhiRegionC_ = (THStack*)METDiMuDeltaPhiCanvasRegionC->GetPrimitive("METDiMuDeltaPhiStack");
  THStack *METDiMuDeltaPhiRegionC_ = (THStack*)METDiMuDeltaPhiCanvasRegionC->GetPrimitive("METDiMuDeltaPhiStack");
  THStack *DiTaudRRegionC_ = (THStack*)DiTaudRCanvasRegionC->GetPrimitive("DiTaudRStack");
  THStack *DiTauMassSmallerdRRegionC_ = (THStack*)DiTauMassSmallerdRCanvasRegionC->GetPrimitive("DiTauMassSmallerdRStack");
  THStack *ZMassdRRegionC_ = (THStack*)ZMassdRCanvasRegionC->GetPrimitive("ZMassdRStack");

  ////////////////
  // RegionA
  ////////////////
  THStack *NMedIsoTausWithMu3RegionA_ = (THStack*)NMedIsoTausWithMu3CanvasRegionA->GetPrimitive("NMedIsoTausWithMu3Stack");
  THStack *InvMassTauHadMu3RegionA_ = (THStack*)InvMassTauHadMu3CanvasRegionA->GetPrimitive("InvMassTauHadMu3Stack");
  THStack *PtTauHadMu3RegionA_ = (THStack*)PtTauHadMu3CanvasRegionA->GetPrimitive("PtTauHadMu3Stack");
  THStack *InvMassMu1TauMuRegionA_ = (THStack*)InvMassMu1TauMuCanvasRegionA->GetPrimitive("InvMassMu1TauMuStack");
  THStack *InvMassMu2TauMuRegionA_ = (THStack*)InvMassMu2TauMuCanvasRegionA->GetPrimitive("InvMassMu2TauMuStack");
  THStack *InvMassFullRangeRegionA_ = (THStack*)InvMassFullRangeCanvasRegionA->GetPrimitive("InvMassFullRangeStack");
  THStack *InvMassDiMuBarrBarrRegionA_ = (THStack*)InvMassDiMuBarrBarrCanvasRegionA->GetPrimitive("InvMassDiMuBarrBarrStack");
  THStack *InvMassDiMuBarrEndcRegionA_ = (THStack*)InvMassDiMuBarrEndcCanvasRegionA->GetPrimitive("InvMassDiMuBarrEndcStack");
  THStack *InvMassDiMuEndcEndcRegionA_ = (THStack*)InvMassDiMuEndcEndcCanvasRegionA->GetPrimitive("InvMassDiMuEndcEndcStack");
  THStack *Mu1PtRegionA_ = (THStack*)Mu1PtCanvasRegionA->GetPrimitive("Mu1PtStack");
  THStack *Mu2PtRegionA_ = (THStack*)Mu2PtCanvasRegionA->GetPrimitive("Mu2PtStack");
  THStack *DiMuPtRegionA_ = (THStack*)DiMuPtCanvasRegionA->GetPrimitive("DiMuPtStack");
  THStack *Mu1EtaRegionA_ = (THStack*)Mu1EtaCanvasRegionA->GetPrimitive("Mu1EtaStack");
  THStack *Mu2EtaRegionA_ = (THStack*)Mu2EtaCanvasRegionA->GetPrimitive("Mu2EtaStack");
  THStack *DiTauEtaRegionA_ = (THStack*)DiTauEtaCanvasRegionA->GetPrimitive("DiTauEtaStack");
  THStack *DiTauPhiRegionA_ = (THStack*)DiTauPhiCanvasRegionA->GetPrimitive("DiTauPhiStack");
  THStack *DiMuEtaRegionA_ = (THStack*)DiMuEtaCanvasRegionA->GetPrimitive("DiMuEtaStack");
  THStack *DiMudRRegionA_ = (THStack*)DiMudRCanvasRegionA->GetPrimitive("DiMudRStack");
  THStack *DiMuPhiRegionA_ = (THStack*)DiMuPhiCanvasRegionA->GetPrimitive("DiMuPhiStack");
  THStack *EtMETRegionA_ = (THStack*)EtMETCanvasRegionA->GetPrimitive("EtMETStack");
  THStack *DiTauDiMuMassRegionA_ = (THStack*)DiTauDiMuMassCanvasRegionA->GetPrimitive("DiTauDiMuMassStack");
  THStack *DiMuDiTauDeltaPhiRegionA_ = (THStack*)DiMuDiTauDeltaPhiCanvasRegionA->GetPrimitive("DiMuDiTauDeltaPhiStack");
  THStack *METDiTauDeltaPhiRegionA_ = (THStack*)METDiMuDeltaPhiCanvasRegionA->GetPrimitive("METDiMuDeltaPhiStack");
  THStack *METDiMuDeltaPhiRegionA_ = (THStack*)METDiMuDeltaPhiCanvasRegionA->GetPrimitive("METDiMuDeltaPhiStack");
  THStack *DiTaudRRegionA_ = (THStack*)DiTaudRCanvasRegionA->GetPrimitive("DiTaudRStack");
  THStack *DiTauMassSmallerdRRegionA_ = (THStack*)DiTauMassSmallerdRCanvasRegionA->GetPrimitive("DiTauMassSmallerdRStack");
  THStack *ZMassdRRegionA_ = (THStack*)ZMassdRCanvasRegionA->GetPrimitive("ZMassdRStack");

  ////////////////
  // RegionB
  ////////////////
  THStack *NMedIsoTausWithMu3RegionB_ = (THStack*)NMedIsoTausWithMu3CanvasRegionB->GetPrimitive("NMedIsoTausWithMu3Stack");
  THStack *InvMassTauHadMu3RegionB_ = (THStack*)InvMassTauHadMu3CanvasRegionB->GetPrimitive("InvMassTauHadMu3Stack");
  THStack *PtTauHadMu3RegionB_ = (THStack*)PtTauHadMu3CanvasRegionB->GetPrimitive("PtTauHadMu3Stack");
  THStack *InvMassMu1TauMuRegionB_ = (THStack*)InvMassMu1TauMuCanvasRegionB->GetPrimitive("InvMassMu1TauMuStack");
  THStack *InvMassMu2TauMuRegionB_ = (THStack*)InvMassMu2TauMuCanvasRegionB->GetPrimitive("InvMassMu2TauMuStack");
  THStack *InvMassFullRangeRegionB_ = (THStack*)InvMassFullRangeCanvasRegionB->GetPrimitive("InvMassFullRangeStack");
  THStack *InvMassDiMuBarrBarrRegionB_ = (THStack*)InvMassDiMuBarrBarrCanvasRegionB->GetPrimitive("InvMassDiMuBarrBarrStack");
  THStack *InvMassDiMuBarrEndcRegionB_ = (THStack*)InvMassDiMuBarrEndcCanvasRegionB->GetPrimitive("InvMassDiMuBarrEndcStack");
  THStack *InvMassDiMuEndcEndcRegionB_ = (THStack*)InvMassDiMuEndcEndcCanvasRegionB->GetPrimitive("InvMassDiMuEndcEndcStack");
  THStack *Mu1PtRegionB_ = (THStack*)Mu1PtCanvasRegionB->GetPrimitive("Mu1PtStack");
  THStack *Mu2PtRegionB_ = (THStack*)Mu2PtCanvasRegionB->GetPrimitive("Mu2PtStack");
  THStack *DiMuPtRegionB_ = (THStack*)DiMuPtCanvasRegionB->GetPrimitive("DiMuPtStack");
  THStack *Mu1EtaRegionB_ = (THStack*)Mu1EtaCanvasRegionB->GetPrimitive("Mu1EtaStack");
  THStack *Mu2EtaRegionB_ = (THStack*)Mu2EtaCanvasRegionB->GetPrimitive("Mu2EtaStack");
  THStack *DiTauEtaRegionB_ = (THStack*)DiTauEtaCanvasRegionB->GetPrimitive("DiTauEtaStack");
  THStack *DiTauPhiRegionB_ = (THStack*)DiTauPhiCanvasRegionB->GetPrimitive("DiTauPhiStack");
  THStack *DiMuEtaRegionB_ = (THStack*)DiMuEtaCanvasRegionB->GetPrimitive("DiMuEtaStack");
  THStack *DiMudRRegionB_ = (THStack*)DiMudRCanvasRegionB->GetPrimitive("DiMudRStack");
  THStack *DiMuPhiRegionB_ = (THStack*)DiMuPhiCanvasRegionB->GetPrimitive("DiMuPhiStack");
  THStack *EtMETRegionB_ = (THStack*)EtMETCanvasRegionB->GetPrimitive("EtMETStack");
  THStack *DiTauDiMuMassRegionB_ = (THStack*)DiTauDiMuMassCanvasRegionB->GetPrimitive("DiTauDiMuMassStack");
  THStack *DiMuDiTauDeltaPhiRegionB_ = (THStack*)DiMuDiTauDeltaPhiCanvasRegionB->GetPrimitive("DiMuDiTauDeltaPhiStack");
  THStack *METDiTauDeltaPhiRegionB_ = (THStack*)METDiMuDeltaPhiCanvasRegionB->GetPrimitive("METDiMuDeltaPhiStack");
  THStack *METDiMuDeltaPhiRegionB_ = (THStack*)METDiMuDeltaPhiCanvasRegionB->GetPrimitive("METDiMuDeltaPhiStack");
  THStack *DiTaudRRegionB_ = (THStack*)DiTaudRCanvasRegionB->GetPrimitive("DiTaudRStack");
  THStack *DiTauMassSmallerdRRegionB_ = (THStack*)DiTauMassSmallerdRCanvasRegionB->GetPrimitive("DiTauMassSmallerdRStack");
  THStack *ZMassdRRegionB_ = (THStack*)ZMassdRCanvasRegionB->GetPrimitive("ZMassdRStack");

  ////////////////
  // RegionD
  ////////////////
  THStack *NMedIsoTausWithMu3RegionD_ = (THStack*)NMedIsoTausWithMu3CanvasRegionD->GetPrimitive("NMedIsoTausWithMu3Stack");
  THStack *InvMassTauHadMu3RegionD_ = (THStack*)InvMassTauHadMu3CanvasRegionD->GetPrimitive("InvMassTauHadMu3Stack");
  THStack *PtTauHadMu3RegionD_ = (THStack*)PtTauHadMu3CanvasRegionD->GetPrimitive("PtTauHadMu3Stack");
  THStack *InvMassMu1TauMuRegionD_ = (THStack*)InvMassMu1TauMuCanvasRegionD->GetPrimitive("InvMassMu1TauMuStack");
  THStack *InvMassMu2TauMuRegionD_ = (THStack*)InvMassMu2TauMuCanvasRegionD->GetPrimitive("InvMassMu2TauMuStack");
  THStack *InvMassFullRangeRegionD_ = (THStack*)InvMassFullRangeCanvasRegionD->GetPrimitive("InvMassFullRangeStack");
  THStack *InvMassDiMuBarrBarrRegionD_ = (THStack*)InvMassDiMuBarrBarrCanvasRegionD->GetPrimitive("InvMassDiMuBarrBarrStack");
  THStack *InvMassDiMuBarrEndcRegionD_ = (THStack*)InvMassDiMuBarrEndcCanvasRegionD->GetPrimitive("InvMassDiMuBarrEndcStack");
  THStack *InvMassDiMuEndcEndcRegionD_ = (THStack*)InvMassDiMuEndcEndcCanvasRegionD->GetPrimitive("InvMassDiMuEndcEndcStack");
  THStack *Mu1PtRegionD_ = (THStack*)Mu1PtCanvasRegionD->GetPrimitive("Mu1PtStack");
  THStack *Mu2PtRegionD_ = (THStack*)Mu2PtCanvasRegionD->GetPrimitive("Mu2PtStack");
  THStack *DiMuPtRegionD_ = (THStack*)DiMuPtCanvasRegionD->GetPrimitive("DiMuPtStack");
  THStack *Mu1EtaRegionD_ = (THStack*)Mu1EtaCanvasRegionD->GetPrimitive("Mu1EtaStack");
  THStack *Mu2EtaRegionD_ = (THStack*)Mu2EtaCanvasRegionD->GetPrimitive("Mu2EtaStack");
  THStack *DiTauEtaRegionD_ = (THStack*)DiTauEtaCanvasRegionD->GetPrimitive("DiTauEtaStack");
  THStack *DiTauPhiRegionD_ = (THStack*)DiTauPhiCanvasRegionD->GetPrimitive("DiTauPhiStack");
  THStack *DiMuEtaRegionD_ = (THStack*)DiMuEtaCanvasRegionD->GetPrimitive("DiMuEtaStack");
  THStack *DiMudRRegionD_ = (THStack*)DiMudRCanvasRegionD->GetPrimitive("DiMudRStack");
  THStack *DiMuPhiRegionD_ = (THStack*)DiMuPhiCanvasRegionD->GetPrimitive("DiMuPhiStack");
  THStack *EtMETRegionD_ = (THStack*)EtMETCanvasRegionD->GetPrimitive("EtMETStack");
  THStack *DiTauDiMuMassRegionD_ = (THStack*)DiTauDiMuMassCanvasRegionD->GetPrimitive("DiTauDiMuMassStack");
  THStack *DiMuDiTauDeltaPhiRegionD_ = (THStack*)DiMuDiTauDeltaPhiCanvasRegionD->GetPrimitive("DiMuDiTauDeltaPhiStack");
  THStack *METDiTauDeltaPhiRegionD_ = (THStack*)METDiMuDeltaPhiCanvasRegionD->GetPrimitive("METDiMuDeltaPhiStack");
  THStack *METDiMuDeltaPhiRegionD_ = (THStack*)METDiMuDeltaPhiCanvasRegionD->GetPrimitive("METDiMuDeltaPhiStack");
  THStack *DiTaudRRegionD_ = (THStack*)DiTaudRCanvasRegionD->GetPrimitive("DiTaudRStack");
  THStack *DiTauMassSmallerdRRegionD_ = (THStack*)DiTauMassSmallerdRCanvasRegionD->GetPrimitive("DiTauMassSmallerdRStack");
  THStack *ZMassdRRegionD_ = (THStack*)ZMassdRCanvasRegionD->GetPrimitive("ZMassdRStack");

cout << "Got Histograms from Canvases" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the signal to overlay
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////
  // h125a9A
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a9A_ = (TH1F*)infileh125a9A.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a9A_ = (TH1F*)infileh125a9A.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a9A_ = (TH1F*)infileh125a9A.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh125a9A_ = (TH1F*)infileh125a9A.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh125a9A_ = (TH1F*)infileh125a9A.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh125a9A_ = (TH1F*)infileh125a9A.Get("InvMassFullRange");
  InvMassFullRangeh125a9A_->Rebin(10);
  TH1F *InvMassDiMuBarrBarrh125a9A_ = (TH1F*)infileh125a9A.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a9A_ = (TH1F*)infileh125a9A.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a9A_ = (TH1F*)infileh125a9A.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a9A_ = (TH1F*)infileh125a9A.Get("Mu1Pt");
  TH1F *Mu2Pth125a9A_ = (TH1F*)infileh125a9A.Get("Mu2Pt");
  TH1F *DiMuPth125a9A_ = (TH1F*)infileh125a9A.Get("DiMuPt");
  TH1F *Mu1Etah125a9A_ = (TH1F*)infileh125a9A.Get("Mu1Eta");
  TH1F *Mu2Etah125a9A_ = (TH1F*)infileh125a9A.Get("Mu2Eta");
  TH1F *DiTauEtah125a9A_ = (TH1F*)infileh125a9A.Get("DiTauEta");
  TH1F *DiTauPhih125a9A_ = (TH1F*)infileh125a9A.Get("DiTauPhi");
  TH1F *DiMuEtah125a9A_ = (TH1F*)infileh125a9A.Get("DiMuEta");
  TH1F *DiMudRh125a9A_ = (TH1F*)infileh125a9A.Get("DiMudR");
  TH1F *DiMuPhih125a9A_ = (TH1F*)infileh125a9A.Get("DiMuPhi");
  TH1F *EtMETh125a9A_ = (TH1F*)infileh125a9A.Get("EtMET");
  TH1F *DiTauDiMuMassh125a9A_ = (TH1F*)infileh125a9A.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a9A_ = (TH1F*)infileh125a9A.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a9A_ = (TH1F*)infileh125a9A.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a9A_ = (TH1F*)infileh125a9A.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a9A_ = (TH1F*)infileh125a9A.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a9A_ = (TH1F*)infileh125a9A.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh125a9A_ = (TH1F*)infileh125a9A.Get("ZMassdR");

  ////////////////
  // h125a9B
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a9B_ = (TH1F*)infileh125a9B.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a9B_ = (TH1F*)infileh125a9B.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a9B_ = (TH1F*)infileh125a9B.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh125a9B_ = (TH1F*)infileh125a9B.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh125a9B_ = (TH1F*)infileh125a9B.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh125a9B_ = (TH1F*)infileh125a9B.Get("InvMassFullRange");
  InvMassFullRangeh125a9B_->Rebin(10);
  TH1F *InvMassDiMuBarrBarrh125a9B_ = (TH1F*)infileh125a9B.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a9B_ = (TH1F*)infileh125a9B.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a9B_ = (TH1F*)infileh125a9B.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a9B_ = (TH1F*)infileh125a9B.Get("Mu1Pt");
  TH1F *Mu2Pth125a9B_ = (TH1F*)infileh125a9B.Get("Mu2Pt");
  TH1F *DiMuPth125a9B_ = (TH1F*)infileh125a9B.Get("DiMuPt");
  TH1F *Mu1Etah125a9B_ = (TH1F*)infileh125a9B.Get("Mu1Eta");
  TH1F *Mu2Etah125a9B_ = (TH1F*)infileh125a9B.Get("Mu2Eta");
  TH1F *DiTauEtah125a9B_ = (TH1F*)infileh125a9B.Get("DiTauEta");
  TH1F *DiTauPhih125a9B_ = (TH1F*)infileh125a9B.Get("DiTauPhi");
  TH1F *DiMuEtah125a9B_ = (TH1F*)infileh125a9B.Get("DiMuEta");
  TH1F *DiMudRh125a9B_ = (TH1F*)infileh125a9B.Get("DiMudR");
  TH1F *DiMuPhih125a9B_ = (TH1F*)infileh125a9B.Get("DiMuPhi");
  TH1F *EtMETh125a9B_ = (TH1F*)infileh125a9B.Get("EtMET");
  TH1F *DiTauDiMuMassh125a9B_ = (TH1F*)infileh125a9B.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a9B_ = (TH1F*)infileh125a9B.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a9B_ = (TH1F*)infileh125a9B.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a9B_ = (TH1F*)infileh125a9B.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a9B_ = (TH1F*)infileh125a9B.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a9B_ = (TH1F*)infileh125a9B.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh125a9B_ = (TH1F*)infileh125a9B.Get("ZMassdR");

  ////////////////
  // h125a9C
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a9C_ = (TH1F*)infileh125a9C.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a9C_ = (TH1F*)infileh125a9C.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a9C_ = (TH1F*)infileh125a9C.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh125a9C_ = (TH1F*)infileh125a9C.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh125a9C_ = (TH1F*)infileh125a9C.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh125a9C_ = (TH1F*)infileh125a9C.Get("InvMassFullRange");
  InvMassFullRangeh125a9C_->Rebin(10);
  TH1F *InvMassDiMuBarrBarrh125a9C_ = (TH1F*)infileh125a9C.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a9C_ = (TH1F*)infileh125a9C.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a9C_ = (TH1F*)infileh125a9C.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a9C_ = (TH1F*)infileh125a9C.Get("Mu1Pt");
  TH1F *Mu2Pth125a9C_ = (TH1F*)infileh125a9C.Get("Mu2Pt");
  TH1F *DiMuPth125a9C_ = (TH1F*)infileh125a9C.Get("DiMuPt");
  TH1F *Mu1Etah125a9C_ = (TH1F*)infileh125a9C.Get("Mu1Eta");
  TH1F *Mu2Etah125a9C_ = (TH1F*)infileh125a9C.Get("Mu2Eta");
  TH1F *DiTauEtah125a9C_ = (TH1F*)infileh125a9C.Get("DiTauEta");
  TH1F *DiTauPhih125a9C_ = (TH1F*)infileh125a9C.Get("DiTauPhi");
  TH1F *DiMuEtah125a9C_ = (TH1F*)infileh125a9C.Get("DiMuEta");
  TH1F *DiMudRh125a9C_ = (TH1F*)infileh125a9C.Get("DiMudR");
  TH1F *DiMuPhih125a9C_ = (TH1F*)infileh125a9C.Get("DiMuPhi");
  TH1F *EtMETh125a9C_ = (TH1F*)infileh125a9C.Get("EtMET");
  TH1F *DiTauDiMuMassh125a9C_ = (TH1F*)infileh125a9C.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a9C_ = (TH1F*)infileh125a9C.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a9C_ = (TH1F*)infileh125a9C.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a9C_ = (TH1F*)infileh125a9C.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a9C_ = (TH1F*)infileh125a9C.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a9C_ = (TH1F*)infileh125a9C.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh125a9C_ = (TH1F*)infileh125a9C.Get("ZMassdR");

  ////////////////
  // h125a9D
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a9D_ = (TH1F*)infileh125a9D.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a9D_ = (TH1F*)infileh125a9D.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a9D_ = (TH1F*)infileh125a9D.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh125a9D_ = (TH1F*)infileh125a9D.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh125a9D_ = (TH1F*)infileh125a9D.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh125a9D_ = (TH1F*)infileh125a9D.Get("InvMassFullRange");
  InvMassFullRangeh125a9D_->Rebin(10);
  TH1F *InvMassDiMuBarrBarrh125a9D_ = (TH1F*)infileh125a9D.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a9D_ = (TH1F*)infileh125a9D.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a9D_ = (TH1F*)infileh125a9D.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a9D_ = (TH1F*)infileh125a9D.Get("Mu1Pt");
  TH1F *Mu2Pth125a9D_ = (TH1F*)infileh125a9D.Get("Mu2Pt");
  TH1F *DiMuPth125a9D_ = (TH1F*)infileh125a9D.Get("DiMuPt");
  TH1F *Mu1Etah125a9D_ = (TH1F*)infileh125a9D.Get("Mu1Eta");
  TH1F *Mu2Etah125a9D_ = (TH1F*)infileh125a9D.Get("Mu2Eta");
  TH1F *DiTauEtah125a9D_ = (TH1F*)infileh125a9D.Get("DiTauEta");
  TH1F *DiTauPhih125a9D_ = (TH1F*)infileh125a9D.Get("DiTauPhi");
  TH1F *DiMuEtah125a9D_ = (TH1F*)infileh125a9D.Get("DiMuEta");
  TH1F *DiMudRh125a9D_ = (TH1F*)infileh125a9D.Get("DiMudR");
  TH1F *DiMuPhih125a9D_ = (TH1F*)infileh125a9D.Get("DiMuPhi");
  TH1F *EtMETh125a9D_ = (TH1F*)infileh125a9D.Get("EtMET");
  TH1F *DiTauDiMuMassh125a9D_ = (TH1F*)infileh125a9D.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a9D_ = (TH1F*)infileh125a9D.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a9D_ = (TH1F*)infileh125a9D.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a9D_ = (TH1F*)infileh125a9D.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a9D_ = (TH1F*)infileh125a9D.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a9D_ = (TH1F*)infileh125a9D.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh125a9D_ = (TH1F*)infileh125a9D.Get("ZMassdR");

  ////////////////
  // h125a9A
  ////////////////
  NMedIsoTausWithMu3h125a9A_->SetLineColor(kGreen+2);
  InvMassTauHadMu3h125a9A_->SetLineColor(kGreen+2);
  PtTauHadMu3h125a9A_->SetLineColor(kGreen+2);
  InvMassMu1TauMuh125a9A_->SetLineColor(kGreen+2);
  InvMassMu2TauMuh125a9A_->SetLineColor(kGreen+2);
  InvMassFullRangeh125a9A_->SetLineColor(kGreen+2);
  InvMassDiMuBarrBarrh125a9A_->SetLineColor(kGreen+2);
  InvMassDiMuBarrEndch125a9A_->SetLineColor(kGreen+2);
  InvMassDiMuEndcEndch125a9A_->SetLineColor(kGreen+2);
  Mu1Pth125a9A_->SetLineColor(kGreen+2);
  Mu2Pth125a9A_->SetLineColor(kGreen+2);
  DiMuPth125a9A_->SetLineColor(kGreen+2);
  Mu1Etah125a9A_->SetLineColor(kGreen+2);
  Mu2Etah125a9A_->SetLineColor(kGreen+2);
  DiTauEtah125a9A_->SetLineColor(kGreen+2);
  DiTauPhih125a9A_->SetLineColor(kGreen+2);
  DiMuEtah125a9A_->SetLineColor(kGreen+2);
  DiMudRh125a9A_->SetLineColor(kGreen+2);
  DiMuPhih125a9A_->SetLineColor(kGreen+2);
  EtMETh125a9A_->SetLineColor(kGreen+2);
  DiTauDiMuMassh125a9A_->SetLineColor(kGreen+2);
  DiMuDiTauDeltaPhih125a9A_->SetLineColor(kGreen+2);
  METDiTauDeltaPhih125a9A_->SetLineColor(kGreen+2);
  METDiMuDeltaPhih125a9A_->SetLineColor(kGreen+2);
  DiTaudRh125a9A_->SetLineColor(kGreen+2);
  DiTauMassSmallerdRh125a9A_->SetLineColor(kGreen+2);
  ZMassdRh125a9A_->SetLineColor(kGreen+2);

  NMedIsoTausWithMu3h125a9B_->SetLineColor(kGreen+2);
  InvMassTauHadMu3h125a9B_->SetLineColor(kGreen+2);
  PtTauHadMu3h125a9B_->SetLineColor(kGreen+2);
  InvMassMu1TauMuh125a9B_->SetLineColor(kGreen+2);
  InvMassMu2TauMuh125a9B_->SetLineColor(kGreen+2);
  InvMassFullRangeh125a9B_->SetLineColor(kGreen+2);
  InvMassDiMuBarrBarrh125a9B_->SetLineColor(kGreen+2);
  InvMassDiMuBarrEndch125a9B_->SetLineColor(kGreen+2);
  InvMassDiMuEndcEndch125a9B_->SetLineColor(kGreen+2);
  Mu1Pth125a9B_->SetLineColor(kGreen+2);
  Mu2Pth125a9B_->SetLineColor(kGreen+2);
  DiMuPth125a9B_->SetLineColor(kGreen+2);
  Mu1Etah125a9B_->SetLineColor(kGreen+2);
  Mu2Etah125a9B_->SetLineColor(kGreen+2);
  DiTauEtah125a9B_->SetLineColor(kGreen+2);
  DiTauPhih125a9B_->SetLineColor(kGreen+2);
  DiMuEtah125a9B_->SetLineColor(kGreen+2);
  DiMudRh125a9B_->SetLineColor(kGreen+2);
  DiMuPhih125a9B_->SetLineColor(kGreen+2);
  EtMETh125a9B_->SetLineColor(kGreen+2);
  DiTauDiMuMassh125a9B_->SetLineColor(kGreen+2);
  DiMuDiTauDeltaPhih125a9B_->SetLineColor(kGreen+2);
  METDiTauDeltaPhih125a9B_->SetLineColor(kGreen+2);
  METDiMuDeltaPhih125a9B_->SetLineColor(kGreen+2);
  DiTaudRh125a9B_->SetLineColor(kGreen+2);
  DiTauMassSmallerdRh125a9B_->SetLineColor(kGreen+2);
  ZMassdRh125a9B_->SetLineColor(kGreen+2);

  NMedIsoTausWithMu3h125a9C_->SetLineColor(kGreen+2);
  InvMassTauHadMu3h125a9C_->SetLineColor(kGreen+2);
  PtTauHadMu3h125a9C_->SetLineColor(kGreen+2);
  InvMassMu1TauMuh125a9C_->SetLineColor(kGreen+2);
  InvMassMu2TauMuh125a9C_->SetLineColor(kGreen+2);
  InvMassFullRangeh125a9C_->SetLineColor(kGreen+2);
  InvMassDiMuBarrBarrh125a9C_->SetLineColor(kGreen+2);
  InvMassDiMuBarrEndch125a9C_->SetLineColor(kGreen+2);
  InvMassDiMuEndcEndch125a9C_->SetLineColor(kGreen+2);
  Mu1Pth125a9C_->SetLineColor(kGreen+2);
  Mu2Pth125a9C_->SetLineColor(kGreen+2);
  DiMuPth125a9C_->SetLineColor(kGreen+2);
  Mu1Etah125a9C_->SetLineColor(kGreen+2);
  Mu2Etah125a9C_->SetLineColor(kGreen+2);
  DiTauEtah125a9C_->SetLineColor(kGreen+2);
  DiTauPhih125a9C_->SetLineColor(kGreen+2);
  DiMuEtah125a9C_->SetLineColor(kGreen+2);
  DiMudRh125a9C_->SetLineColor(kGreen+2);
  DiMuPhih125a9C_->SetLineColor(kGreen+2);
  EtMETh125a9C_->SetLineColor(kGreen+2);
  DiTauDiMuMassh125a9C_->SetLineColor(kGreen+2);
  DiMuDiTauDeltaPhih125a9C_->SetLineColor(kGreen+2);
  METDiTauDeltaPhih125a9C_->SetLineColor(kGreen+2);
  METDiMuDeltaPhih125a9C_->SetLineColor(kGreen+2);
  DiTaudRh125a9C_->SetLineColor(kGreen+2);
  DiTauMassSmallerdRh125a9C_->SetLineColor(kGreen+2);
  ZMassdRh125a9C_->SetLineColor(kGreen+2);

  NMedIsoTausWithMu3h125a9D_->SetLineColor(kGreen+2);
  InvMassTauHadMu3h125a9D_->SetLineColor(kGreen+2);
  PtTauHadMu3h125a9D_->SetLineColor(kGreen+2);
  InvMassMu1TauMuh125a9D_->SetLineColor(kGreen+2);
  InvMassMu2TauMuh125a9D_->SetLineColor(kGreen+2);
  InvMassFullRangeh125a9D_->SetLineColor(kGreen+2);
  InvMassDiMuBarrBarrh125a9D_->SetLineColor(kGreen+2);
  InvMassDiMuBarrEndch125a9D_->SetLineColor(kGreen+2);
  InvMassDiMuEndcEndch125a9D_->SetLineColor(kGreen+2);
  Mu1Pth125a9D_->SetLineColor(kGreen+2);
  Mu2Pth125a9D_->SetLineColor(kGreen+2);
  DiMuPth125a9D_->SetLineColor(kGreen+2);
  Mu1Etah125a9D_->SetLineColor(kGreen+2);
  Mu2Etah125a9D_->SetLineColor(kGreen+2);
  DiTauEtah125a9D_->SetLineColor(kGreen+2);
  DiTauPhih125a9D_->SetLineColor(kGreen+2);
  DiMuEtah125a9D_->SetLineColor(kGreen+2);
  DiMudRh125a9D_->SetLineColor(kGreen+2);
  DiMuPhih125a9D_->SetLineColor(kGreen+2);
  EtMETh125a9D_->SetLineColor(kGreen+2);
  DiTauDiMuMassh125a9D_->SetLineColor(kGreen+2);
  DiMuDiTauDeltaPhih125a9D_->SetLineColor(kGreen+2);
  METDiTauDeltaPhih125a9D_->SetLineColor(kGreen+2);
  METDiMuDeltaPhih125a9D_->SetLineColor(kGreen+2);
  DiTaudRh125a9D_->SetLineColor(kGreen+2);
  DiTauMassSmallerdRh125a9D_->SetLineColor(kGreen+2);
  ZMassdRh125a9D_->SetLineColor(kGreen+2);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the QCD Combined Canvas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *NMedIsoTausWithMu3CanvasAll = new TCanvas ("NMedIsoTausWithMu3CanvasAll","",600,600); 
  TCanvas *InvMassTauHadMu3CanvasAll = new TCanvas ("InvMassTauHadMu3CanvasAll","",600,600); 
  TCanvas *PtTauHadMu3CanvasAll = new TCanvas ("PtTauHadMu3CanvasAll","",600,600); 
  TCanvas *InvMassMu1TauMuCanvasAll = new TCanvas ("InvMassMu1TauMuCanvasAll","",600,600); 
  TCanvas *InvMassMu2TauMuCanvasAll = new TCanvas ("InvMassMu2TauMuCanvasAll","",600,600); 
  TCanvas *InvMassFullRangeCanvasAll = new TCanvas ("InvMassFullRangeCanvasAll","",600,600); 
  TCanvas *InvMassDiMuBarrBarrCanvasAll = new TCanvas ("InvMassDiMuBarrBarrCanvasAll","",600,600); 
  TCanvas *InvMassDiMuBarrEndcCanvasAll = new TCanvas ("InvMassDiMuBarrEndcCanvasAll","",600,600); 
  TCanvas *InvMassDiMuEndcEndcCanvasAll = new TCanvas ("InvMassDiMuEndcEndcCanvasAll","",600,600); 
  TCanvas *Mu1PtCanvasAll = new TCanvas ("Mu1PtCanvasAll","",600,600); 
  TCanvas *Mu2PtCanvasAll = new TCanvas ("Mu2PtCanvasAll","",600,600); 
  TCanvas *DiMuPtCanvasAll = new TCanvas ("DiMuPtCanvasAll","",600,600); 
  TCanvas *Mu1EtaCanvasAll = new TCanvas ("Mu1EtaCanvasAll","",600,600); 
  TCanvas *Mu2EtaCanvasAll = new TCanvas ("Mu2EtaCanvasAll","",600,600); 
  TCanvas *DiTauEtaCanvasAll = new TCanvas ("DiTauEtaCanvasAll","",600,600); 
  TCanvas *DiTauPhiCanvasAll = new TCanvas ("DiTauPhiCanvasAll","",600,600); 
  TCanvas *DiMuEtaCanvasAll = new TCanvas ("DiMuEtaCanvasAll","",600,600); 
  TCanvas *DiMudRCanvasAll = new TCanvas ("DiMudRCanvasAll","",600,600); 
  TCanvas *DiMuPhiCanvasAll = new TCanvas ("DiMuPhiCanvasAll","",600,600); 
  TCanvas *EtMETCanvasAll = new TCanvas ("EtMETCanvasAll","",600,600); 
  TCanvas *DiTauDiMuMassCanvasAll = new TCanvas ("DiTauDiMuMassCanvasAll","",600,600); 
  TCanvas *DiMuDiTauDeltaPhiCanvasAll = new TCanvas ("DiMuDiTauDeltaPhiCanvasAll","",600,600); 
  TCanvas *METDiTauDeltaPhiCanvasAll = new TCanvas ("METDiTauDeltaPhiCanvasAll","",600,600); 
  TCanvas *METDiMuDeltaPhiCanvasAll = new TCanvas ("METDiMuDeltaPhiCanvasAll","",600,600); 
  TCanvas *DiTaudRCanvasAll = new TCanvas ("DiTaudRCanvasAll","",600,600); 
  TCanvas *DiTauMassSmallerdRCanvasAll = new TCanvas ("DiTauMassSmallerdRCanvasAll","",600,600); 
  TCanvas *ZMassdRCanvasAll = new TCanvas ("ZMassdRCanvasAll","",600,600); 


  NMedIsoTausWithMu3CanvasAll->Divide(2,2);
  InvMassTauHadMu3CanvasAll->Divide(2,2);
  PtTauHadMu3CanvasAll->Divide(2,2);
  InvMassMu1TauMuCanvasAll->Divide(2,2);
  InvMassMu2TauMuCanvasAll->Divide(2,2);
  InvMassFullRangeCanvasAll->Divide(2,2);
  InvMassDiMuBarrBarrCanvasAll->Divide(2,2);
  InvMassDiMuBarrEndcCanvasAll->Divide(2,2);
  InvMassDiMuEndcEndcCanvasAll->Divide(2,2);
  Mu1PtCanvasAll->Divide(2,2);
  Mu2PtCanvasAll->Divide(2,2);
  DiMuPtCanvasAll->Divide(2,2);
  Mu1EtaCanvasAll->Divide(2,2);
  Mu2EtaCanvasAll->Divide(2,2);
  DiTauEtaCanvasAll->Divide(2,2);
  DiTauPhiCanvasAll->Divide(2,2);
  DiMuEtaCanvasAll->Divide(2,2);
  DiMudRCanvasAll->Divide(2,2);
  DiMuPhiCanvasAll->Divide(2,2);
  EtMETCanvasAll->Divide(2,2);
  DiTauDiMuMassCanvasAll->Divide(2,2);
  DiMuDiTauDeltaPhiCanvasAll->Divide(2,2);
  METDiTauDeltaPhiCanvasAll->Divide(2,2);
  METDiMuDeltaPhiCanvasAll->Divide(2,2);
  DiTaudRCanvasAll->Divide(2,2);
  DiTauMassSmallerdRCanvasAll->Divide(2,2);
  ZMassdRCanvasAll->Divide(2,2);

  TH1F *EtMETST_ = new TH1F ("EtMETST","",10,0,10);
  TH1F *EtMETTT_ = new TH1F ("EtMETTT","",10,0,10);
  TH1F *EtMETQCD_ = new TH1F ("EtMETQCD","",10,0,10);
  TH1F *EtMETDiBoson_ = new TH1F ("EtMETDiBoson","",10,0,10);
  TH1F *EtMETDY_ = new TH1F ("EtMETDY","",10,0,10);
  EtMETST_->SetFillColor(kViolet-3);
  EtMETTT_->SetFillColor(kRed);
  EtMETQCD_->SetFillColor(kViolet+2);
  EtMETDiBoson_->SetFillColor(kPink+1);
  EtMETDY_->SetFillColor(kGray);
  
  TLegend *legend = new TLegend(0.7,0.5,0.95,0.7) ;
  legend->SetTextFont(42);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->AddEntry(EtMETST_ ,"ST", "f");
  legend->AddEntry(EtMETQCD_ ,"QCD", "f");
  legend->AddEntry(EtMETDiBoson_ ,"DiBoson", "f");
  legend->AddEntry(EtMETDY_ ,"DY", "f");
  legend->AddEntry(EtMETTT_ ,"TT", "f");
  legend->AddEntry(EtMETh125a9D_ ,"h125a9D", "f");

  NMedIsoTausWithMu3CanvasAll->cd(1);
  NMedIsoTausWithMu3RegionA_->Draw("hist");
  NMedIsoTausWithMu3h125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  NMedIsoTausWithMu3CanvasAll->cd(2);
  NMedIsoTausWithMu3RegionB_->Draw("hist");
  NMedIsoTausWithMu3h125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  NMedIsoTausWithMu3CanvasAll->cd(3);
  NMedIsoTausWithMu3RegionC_->Draw("hist");
  NMedIsoTausWithMu3h125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  NMedIsoTausWithMu3CanvasAll->cd(4);
  NMedIsoTausWithMu3RegionD_->Draw("hist");
  NMedIsoTausWithMu3h125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassTauHadMu3CanvasAll->cd(1);
  InvMassTauHadMu3RegionA_->Draw("hist");
  InvMassTauHadMu3h125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassTauHadMu3CanvasAll->cd(2);
  InvMassTauHadMu3RegionB_->Draw("hist");
  InvMassTauHadMu3h125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassTauHadMu3CanvasAll->cd(3);
  InvMassTauHadMu3RegionC_->Draw("hist");
  InvMassTauHadMu3h125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassTauHadMu3CanvasAll->cd(4);
  InvMassTauHadMu3RegionD_->Draw("hist");
  InvMassTauHadMu3h125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");

  PtTauHadMu3CanvasAll->cd(1);
  PtTauHadMu3RegionA_->Draw("hist");
  PtTauHadMu3h125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  PtTauHadMu3CanvasAll->cd(2);
  PtTauHadMu3RegionB_->Draw("hist");
  PtTauHadMu3h125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  PtTauHadMu3CanvasAll->cd(3);
  PtTauHadMu3RegionC_->Draw("hist");
  PtTauHadMu3h125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  PtTauHadMu3CanvasAll->cd(4);
  PtTauHadMu3RegionD_->Draw("hist");
  PtTauHadMu3h125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassMu1TauMuCanvasAll->cd(1);
  InvMassMu1TauMuRegionA_->Draw("hist");
  InvMassMu1TauMuh125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassMu1TauMuCanvasAll->cd(2);
  InvMassMu1TauMuRegionB_->Draw("hist");
  InvMassMu1TauMuh125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassMu1TauMuCanvasAll->cd(3);
  InvMassMu1TauMuRegionC_->Draw("hist");
  InvMassMu1TauMuh125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
//  InvMassMu1TauMuCanvasAll->cd(4);
//  InvMassMu1TauMuRegionD_->Draw("hist");
//  InvMassMu1TauMuh125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
//  InvMassMu2TauMuCanvasAll->cd(1);
//  InvMassMu2TauMuRegionA_->Draw("hist");
//  InvMassMu2TauMuh125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
//  InvMassMu2TauMuCanvasAll->cd(2);
//  InvMassMu2TauMuRegionB_->Draw("hist");
//  InvMassMu2TauMuh125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
//  InvMassMu2TauMuCanvasAll->cd(3);
//  InvMassMu2TauMuRegionC_->Draw("hist");
//  InvMassMu2TauMuh125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
//  InvMassMu2TauMuCanvasAll->cd(4);
//  InvMassMu2TauMuRegionD_->Draw("hist");
//  InvMassMu2TauMuh125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassFullRangeCanvasAll->cd(1);
  InvMassFullRangeRegionA_->Draw("hist");
  InvMassFullRangeh125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassFullRangeCanvasAll->cd(2);
  InvMassFullRangeRegionB_->Draw("hist");
  InvMassFullRangeh125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassFullRangeCanvasAll->cd(3);
  InvMassFullRangeRegionC_->Draw("hist");
  InvMassFullRangeh125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassFullRangeCanvasAll->cd(4);
  InvMassFullRangeRegionD_->Draw("hist");
  InvMassFullRangeh125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassDiMuBarrBarrCanvasAll->cd(1);
  InvMassDiMuBarrBarrRegionA_->Draw("hist");
  InvMassDiMuBarrBarrh125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassDiMuBarrBarrCanvasAll->cd(2);
  InvMassDiMuBarrBarrRegionB_->Draw("hist");
  InvMassDiMuBarrBarrh125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassDiMuBarrBarrCanvasAll->cd(3);
  InvMassDiMuBarrBarrRegionC_->Draw("hist");
  InvMassDiMuBarrBarrh125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassDiMuBarrBarrCanvasAll->cd(4);
  InvMassDiMuBarrBarrRegionD_->Draw("hist");
  InvMassDiMuBarrBarrh125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassDiMuBarrEndcCanvasAll->cd(1);
  InvMassDiMuBarrEndcRegionA_->Draw("hist");
  InvMassDiMuBarrEndch125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassDiMuBarrEndcCanvasAll->cd(2);
  InvMassDiMuBarrEndcRegionB_->Draw("hist");
  InvMassDiMuBarrEndch125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassDiMuBarrEndcCanvasAll->cd(3);
  InvMassDiMuBarrEndcRegionC_->Draw("hist");
  InvMassDiMuBarrEndch125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassDiMuBarrEndcCanvasAll->cd(4);
  InvMassDiMuBarrEndcRegionD_->Draw("hist");
  InvMassDiMuBarrEndch125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassDiMuEndcEndcCanvasAll->cd(1);
  InvMassDiMuEndcEndcRegionA_->Draw("hist");
  InvMassDiMuEndcEndch125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassDiMuEndcEndcCanvasAll->cd(2);
  InvMassDiMuEndcEndcRegionB_->Draw("hist");
  InvMassDiMuEndcEndch125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassDiMuEndcEndcCanvasAll->cd(3);
  InvMassDiMuEndcEndcRegionC_->Draw("hist");
  InvMassDiMuEndcEndch125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  InvMassDiMuEndcEndcCanvasAll->cd(4);
  InvMassDiMuEndcEndcRegionD_->Draw("hist");
  InvMassDiMuEndcEndch125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu1PtCanvasAll->cd(1);
  Mu1PtRegionA_->Draw("hist");
  Mu1Pth125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu1PtCanvasAll->cd(2);
  Mu1PtRegionB_->Draw("hist");
  Mu1Pth125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu1PtCanvasAll->cd(3);
  Mu1PtRegionC_->Draw("hist");
  Mu1Pth125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu1PtCanvasAll->cd(4);
  Mu1PtRegionD_->Draw("hist");
  Mu1Pth125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu2PtCanvasAll->cd(1);
  Mu2PtRegionA_->Draw("hist");
  Mu2Pth125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu2PtCanvasAll->cd(2);
  Mu2PtRegionB_->Draw("hist");
  Mu2Pth125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu2PtCanvasAll->cd(3);
  Mu2PtRegionC_->Draw("hist");
  Mu2Pth125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu2PtCanvasAll->cd(4);
  Mu2PtRegionD_->Draw("hist");
  Mu2Pth125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuPtCanvasAll->cd(1);
  DiMuPtRegionA_->Draw("hist");
  DiMuPth125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuPtCanvasAll->cd(2);
  DiMuPtRegionB_->Draw("hist");
  DiMuPth125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuPtCanvasAll->cd(3);
  DiMuPtRegionC_->Draw("hist");
  DiMuPth125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuPtCanvasAll->cd(4);
  DiMuPtRegionD_->Draw("hist");
  DiMuPth125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu1EtaCanvasAll->cd(1);
  Mu1EtaRegionA_->Draw("hist");
  Mu1Etah125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu1EtaCanvasAll->cd(2);
  Mu1EtaRegionB_->Draw("hist");
  Mu1Etah125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu1EtaCanvasAll->cd(3);
  Mu1EtaRegionC_->Draw("hist");
  Mu1Etah125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu1EtaCanvasAll->cd(4);
  Mu1EtaRegionD_->Draw("hist");
  Mu1Etah125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu2EtaCanvasAll->cd(1);
  Mu2EtaRegionA_->Draw("hist");
  Mu2Etah125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu2EtaCanvasAll->cd(2);
  Mu2EtaRegionB_->Draw("hist");
  Mu2Etah125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu2EtaCanvasAll->cd(3);
  Mu2EtaRegionC_->Draw("hist");
  Mu2Etah125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  Mu2EtaCanvasAll->cd(4);
  Mu2EtaRegionD_->Draw("hist");
  Mu2Etah125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauEtaCanvasAll->cd(1);
  DiTauEtaRegionA_->Draw("hist");
  DiTauEtah125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauEtaCanvasAll->cd(2);
  DiTauEtaRegionB_->Draw("hist");
  DiTauEtah125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauEtaCanvasAll->cd(3);
  DiTauEtaRegionC_->Draw("hist");
  DiTauEtah125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauEtaCanvasAll->cd(4);
  DiTauEtaRegionD_->Draw("hist");
  DiTauEtah125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauPhiCanvasAll->cd(1);
  DiTauPhiRegionA_->Draw("hist");
  DiTauPhih125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauPhiCanvasAll->cd(2);
  DiTauPhiRegionB_->Draw("hist");
  DiTauPhih125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauPhiCanvasAll->cd(3);
  DiTauPhiRegionC_->Draw("hist");
  DiTauPhih125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauPhiCanvasAll->cd(4);
  DiTauPhiRegionD_->Draw("hist");
  DiTauPhih125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuEtaCanvasAll->cd(1);
  DiMuEtaRegionA_->Draw("hist");
  DiMuEtah125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuEtaCanvasAll->cd(2);
  DiMuEtaRegionB_->Draw("hist");
  DiMuEtah125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuEtaCanvasAll->cd(3);
  DiMuEtaRegionC_->Draw("hist");
  DiMuEtah125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuEtaCanvasAll->cd(4);
  DiMuEtaRegionD_->Draw("hist");
  DiMuEtah125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMudRCanvasAll->cd(1);
  DiMudRRegionA_->Draw("hist");
  DiMudRh125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMudRCanvasAll->cd(2);
  DiMudRRegionB_->Draw("hist");
  DiMudRh125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMudRCanvasAll->cd(3);
  DiMudRRegionC_->Draw("hist");
  DiMudRh125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMudRCanvasAll->cd(4);
  DiMudRRegionD_->Draw("hist");
  DiMudRh125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuPhiCanvasAll->cd(1);
  DiMuPhiRegionA_->Draw("hist");
  DiMuPhih125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuPhiCanvasAll->cd(2);
  DiMuPhiRegionB_->Draw("hist");
  DiMuPhih125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuPhiCanvasAll->cd(3);
  DiMuPhiRegionC_->Draw("hist");
  DiMuPhih125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuPhiCanvasAll->cd(4);
  DiMuPhiRegionD_->Draw("hist");
  DiMuPhih125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  EtMETCanvasAll->cd(1);
  EtMETRegionA_->Draw("hist");
  EtMETh125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  EtMETCanvasAll->cd(2);
  EtMETRegionB_->Draw("hist");
  EtMETh125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  EtMETCanvasAll->cd(3);
  EtMETRegionC_->Draw("hist");
  EtMETh125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  EtMETCanvasAll->cd(4);
  EtMETRegionD_->Draw("hist");
  EtMETh125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauDiMuMassCanvasAll->cd(1);
  DiTauDiMuMassRegionA_->Draw("hist");
  DiTauDiMuMassh125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauDiMuMassCanvasAll->cd(2);
  DiTauDiMuMassRegionB_->Draw("hist");
  DiTauDiMuMassh125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauDiMuMassCanvasAll->cd(3);
  DiTauDiMuMassRegionC_->Draw("hist");
  DiTauDiMuMassh125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauDiMuMassCanvasAll->cd(4);
  DiTauDiMuMassRegionD_->Draw("hist");
  DiTauDiMuMassh125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuDiTauDeltaPhiCanvasAll->cd(1);
  DiMuDiTauDeltaPhiRegionA_->Draw("hist");
  DiMuDiTauDeltaPhih125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuDiTauDeltaPhiCanvasAll->cd(2);
  DiMuDiTauDeltaPhiRegionB_->Draw("hist");
  DiMuDiTauDeltaPhih125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuDiTauDeltaPhiCanvasAll->cd(3);
  DiMuDiTauDeltaPhiRegionC_->Draw("hist");
  DiMuDiTauDeltaPhih125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiMuDiTauDeltaPhiCanvasAll->cd(4);
  DiMuDiTauDeltaPhiRegionD_->Draw("hist");
  DiMuDiTauDeltaPhih125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  METDiTauDeltaPhiCanvasAll->cd(1);
  METDiTauDeltaPhiRegionA_->Draw("hist");
  METDiTauDeltaPhih125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  METDiTauDeltaPhiCanvasAll->cd(2);
  METDiTauDeltaPhiRegionB_->Draw("hist");
  METDiTauDeltaPhih125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  METDiTauDeltaPhiCanvasAll->cd(3);
  METDiTauDeltaPhiRegionC_->Draw("hist");
  METDiTauDeltaPhih125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  METDiTauDeltaPhiCanvasAll->cd(4);
  METDiTauDeltaPhiRegionD_->Draw("hist");
  METDiTauDeltaPhih125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  METDiMuDeltaPhiCanvasAll->cd(1);
  METDiMuDeltaPhiRegionA_->Draw("hist");
  METDiMuDeltaPhih125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  METDiMuDeltaPhiCanvasAll->cd(2);
  METDiMuDeltaPhiRegionB_->Draw("hist");
  METDiMuDeltaPhih125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  METDiMuDeltaPhiCanvasAll->cd(3);
  METDiMuDeltaPhiRegionC_->Draw("hist");
  METDiMuDeltaPhih125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  METDiMuDeltaPhiCanvasAll->cd(4);
  METDiMuDeltaPhiRegionD_->Draw("hist");
  METDiMuDeltaPhih125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTaudRCanvasAll->cd(1);
  DiTaudRRegionA_->Draw("hist");
  DiTaudRh125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTaudRCanvasAll->cd(2);
  DiTaudRRegionB_->Draw("hist");
  DiTaudRh125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTaudRCanvasAll->cd(3);
  DiTaudRRegionC_->Draw("hist");
  DiTaudRh125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTaudRCanvasAll->cd(4);
  DiTaudRRegionD_->Draw("hist");
  DiTaudRh125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauMassSmallerdRCanvasAll->cd(1);
  DiTauMassSmallerdRRegionA_->Draw("hist");
  DiTauMassSmallerdRh125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauMassSmallerdRCanvasAll->cd(2);
  DiTauMassSmallerdRRegionB_->Draw("hist");
  DiTauMassSmallerdRh125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauMassSmallerdRCanvasAll->cd(3);
  DiTauMassSmallerdRRegionC_->Draw("hist");
  DiTauMassSmallerdRh125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  DiTauMassSmallerdRCanvasAll->cd(4);
  DiTauMassSmallerdRRegionD_->Draw("hist");
  DiTauMassSmallerdRh125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");
  ZMassdRCanvasAll->cd(1);
  ZMassdRRegionA_->Draw("hist");
  ZMassdRh125a9A_->Draw("HIST SAME");
  legend->Draw("SAME");
  ZMassdRCanvasAll->cd(2);
  ZMassdRRegionB_->Draw("hist");
  ZMassdRh125a9B_->Draw("HIST SAME");
  legend->Draw("SAME");
  ZMassdRCanvasAll->cd(3);
  ZMassdRRegionC_->Draw("hist");
  ZMassdRh125a9C_->Draw("HIST SAME");
  legend->Draw("SAME");
  ZMassdRCanvasAll->cd(4);
  ZMassdRRegionD_->Draw("hist");
  ZMassdRh125a9D_->Draw("HIST SAME");
  legend->Draw("SAME");


  outFile->cd();

  NMedIsoTausWithMu3CanvasAll->Write();
  InvMassTauHadMu3CanvasAll->Write();
  PtTauHadMu3CanvasAll->Write();
  InvMassMu1TauMuCanvasAll->Write();
//  InvMassMu2TauMuCanvasAll->Write();
  InvMassFullRangeCanvasAll->Write();
  InvMassDiMuBarrBarrCanvasAll->Write();
  InvMassDiMuBarrEndcCanvasAll->Write();
  InvMassDiMuEndcEndcCanvasAll->Write();
  Mu1PtCanvasAll->Write();
  Mu2PtCanvasAll->Write();
  DiMuPtCanvasAll->Write();
  Mu1EtaCanvasAll->Write();
  Mu2EtaCanvasAll->Write();
  DiTauEtaCanvasAll->Write();
  DiTauPhiCanvasAll->Write();
  DiMuEtaCanvasAll->Write();
  DiMudRCanvasAll->Write();
  DiMuPhiCanvasAll->Write();
  EtMETCanvasAll->Write();
  DiTauDiMuMassCanvasAll->Write();
  DiMuDiTauDeltaPhiCanvasAll->Write();
  METDiTauDeltaPhiCanvasAll->Write();
  METDiMuDeltaPhiCanvasAll->Write();
  DiTaudRCanvasAll->Write();
  DiTauMassSmallerdRCanvasAll->Write();
  ZMassdRCanvasAll->Write();

 
  outFile->Write();
  outFile->Close();




}
