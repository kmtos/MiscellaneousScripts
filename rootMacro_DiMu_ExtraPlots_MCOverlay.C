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

void rootMacro_DiMu_ExtraPlots_MCOverlay()
{
  setTDRStyle(true);
  gStyle->SetPalette(1);


  //Old DMs
  TFile infileDYL("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_DYLowMass_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileDYH("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_DYHighMass_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileJPsi("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_JPsi_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileQCD_1000toInf("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_QCD_1000toInf_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileQCD_120to170("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_QCD_120to170_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileQCD_15to20("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_QCD_15to20_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileQCD_170to300("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_QCD_170to300_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileQCD_20to30("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_QCD_20to30_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileQCD_300to470("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_QCD_300to470_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileQCD_30to50("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_QCD_30to50_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileQCD_470to600("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_QCD_470to600_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileQCD_50to80("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_QCD_50to80_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileQCD_600to800("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_QCD_600to800_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileQCD_800to1000("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_QCD_800to1000_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileQCD_80to120("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_QCD_80to120_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh125a11("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a11_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh125a13("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a13_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh125a15("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a15_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh125a17("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a17_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh125a19("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a19_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh125a21("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a21_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh125a5("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a5_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh125a7("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a7_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh125a9("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h125a9_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh300a11("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a11_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh300a13("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a13_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh300a15("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a15_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh300a17("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a17_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh300a19("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a19_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh300a21("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a21_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh300a5("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a5_MedIsoMu2_TauDMMedIso_FEB8.root  ");
  TFile infileh300a7("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a7_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh300a9("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h300a9_MedIsoMu2_TauDMMedIso_FEB8.root  ");
  TFile infileh750a11("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a11_MedIsoMu2_TauDMMedIso_FEB8.root ");
  TFile infileh750a13("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a13_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh750a15("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a15_MedIsoMu2_TauDMMedIso_FEB8.root ");
  TFile infileh750a17("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a17_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh750a19("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a19_MedIsoMu2_TauDMMedIso_FEB8.root  ");
  TFile infileh750a21("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a21_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh750a5("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a5_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh750a7("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a7_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileh750a9("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_SIG_h750a9_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileST_sch("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_ST_sch_4l_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileST_tWIncl_top("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_ST_tW_incl_8M1_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileST_tWIncl_antitop("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_ST_tW_incl_8M1_antitop_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileST_tch_antitop("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_ST_tch_antitop_pythia8_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileST_tch_top("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_ST_tch_top_pythia8_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileTT("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_TTJetsAmca_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileUp("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_Upsilon_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileWJAmac("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_WJAmac_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileWZ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_WZ3L1Nu_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileZZ2L2Nu("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_ZZTo2L2Nu_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileZZ2L2Q("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_ZZTo2L2Q_MedIsoMu2_TauDMMedIso_FEB8.root");
  TFile infileZZ4LAmac("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MedIsoMu2_TauDMMedIso/FINAL_MiniAOD_ZZTo4LAmac_MedIsoMu2_TauDMMedIso_FEB8.root ");


  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Stack_DiMu_ExtraPlots_MCOverlay_MedIsoMu2_TauDMMedIso_FEB8.root", "RECREATE");

cout << "Files Created" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Canvases
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////
  // TT
  ////////////////
  TH1F *NMedIsoTausWithMu3TT_ = (TH1F*)infileTT.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3TT_ = (TH1F*)infileTT.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3TT_ = (TH1F*)infileTT.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuTT_ = (TH1F*)infileTT.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuTT_ = (TH1F*)infileTT.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeTT_ = (TH1F*)infileTT.Get("InvMassFullRange");
  InvMassTauHadMu3TT_->Rebin(3);
  InvMassFullRangeTT_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrTT_ = (TH1F*)infileTT.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcTT_ = (TH1F*)infileTT.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcTT_ = (TH1F*)infileTT.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtTT_ = (TH1F*)infileTT.Get("Mu1Pt");
  TH1F *Mu2PtTT_ = (TH1F*)infileTT.Get("Mu2Pt");
  TH1F *DiMuPtTT_ = (TH1F*)infileTT.Get("DiMuPt");
  TH1F *Mu1EtaTT_ = (TH1F*)infileTT.Get("Mu1Eta");
  TH1F *Mu2EtaTT_ = (TH1F*)infileTT.Get("Mu2Eta");
  TH1F *DiTauEtaTT_ = (TH1F*)infileTT.Get("DiTauEta");
  TH1F *DiTauPhiTT_ = (TH1F*)infileTT.Get("DiTauPhi");
  TH1F *DiMuEtaTT_ = (TH1F*)infileTT.Get("DiMuEta");
  TH1F *DiMudRTT_ = (TH1F*)infileTT.Get("DiMudR");
  TH1F *DiMuPhiTT_ = (TH1F*)infileTT.Get("DiMuPhi");
  TH1F *EtMETTT_ = (TH1F*)infileTT.Get("EtMET");
  TH1F *DiTauDiMuMassTT_ = (TH1F*)infileTT.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiTT_ = (TH1F*)infileTT.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiTT_ = (TH1F*)infileTT.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiTT_ = (TH1F*)infileTT.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRTT_ = (TH1F*)infileTT.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRTT_ = (TH1F*)infileTT.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRTT_ = (TH1F*)infileTT.Get("ZMassdR");

  ////////////////
  // DYL
  ////////////////
  TH1F *NMedIsoTausWithMu3DYL_ = (TH1F*)infileDYL.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3DYL_ = (TH1F*)infileDYL.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3DYL_ = (TH1F*)infileDYL.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuDYL_ = (TH1F*)infileDYL.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuDYL_ = (TH1F*)infileDYL.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeDYL_ = (TH1F*)infileDYL.Get("InvMassFullRange");
  InvMassTauHadMu3DYL_->Rebin(3);
  InvMassFullRangeDYL_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrDYL_ = (TH1F*)infileDYL.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcDYL_ = (TH1F*)infileDYL.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcDYL_ = (TH1F*)infileDYL.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtDYL_ = (TH1F*)infileDYL.Get("Mu1Pt");
  TH1F *Mu2PtDYL_ = (TH1F*)infileDYL.Get("Mu2Pt");
  TH1F *DiMuPtDYL_ = (TH1F*)infileDYL.Get("DiMuPt");
  TH1F *Mu1EtaDYL_ = (TH1F*)infileDYL.Get("Mu1Eta");
  TH1F *Mu2EtaDYL_ = (TH1F*)infileDYL.Get("Mu2Eta");
  TH1F *DiTauEtaDYL_ = (TH1F*)infileDYL.Get("DiTauEta");
  TH1F *DiTauPhiDYL_ = (TH1F*)infileDYL.Get("DiTauPhi");
  TH1F *DiMuEtaDYL_ = (TH1F*)infileDYL.Get("DiMuEta");
  TH1F *DiMudRDYL_ = (TH1F*)infileDYL.Get("DiMudR");
  TH1F *DiMuPhiDYL_ = (TH1F*)infileDYL.Get("DiMuPhi");
  TH1F *EtMETDYL_ = (TH1F*)infileDYL.Get("EtMET");
  TH1F *DiTauDiMuMassDYL_ = (TH1F*)infileDYL.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiDYL_ = (TH1F*)infileDYL.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiDYL_ = (TH1F*)infileDYL.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiDYL_ = (TH1F*)infileDYL.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRDYL_ = (TH1F*)infileDYL.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRDYL_ = (TH1F*)infileDYL.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRDYL_ = (TH1F*)infileDYL.Get("ZMassdR");

  ////////////////
  // DYH
  ////////////////
  TH1F *NMedIsoTausWithMu3DYH_ = (TH1F*)infileDYH.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3DYH_ = (TH1F*)infileDYH.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3DYH_ = (TH1F*)infileDYH.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuDYH_ = (TH1F*)infileDYH.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuDYH_ = (TH1F*)infileDYH.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeDYH_ = (TH1F*)infileDYH.Get("InvMassFullRange");
  InvMassTauHadMu3DYH_->Rebin(3);
  InvMassFullRangeDYH_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrDYH_ = (TH1F*)infileDYH.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcDYH_ = (TH1F*)infileDYH.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcDYH_ = (TH1F*)infileDYH.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtDYH_ = (TH1F*)infileDYH.Get("Mu1Pt");
  TH1F *Mu2PtDYH_ = (TH1F*)infileDYH.Get("Mu2Pt");
  TH1F *DiMuPtDYH_ = (TH1F*)infileDYH.Get("DiMuPt");
  TH1F *Mu1EtaDYH_ = (TH1F*)infileDYH.Get("Mu1Eta");
  TH1F *Mu2EtaDYH_ = (TH1F*)infileDYH.Get("Mu2Eta");
  TH1F *DiTauEtaDYH_ = (TH1F*)infileDYH.Get("DiTauEta");
  TH1F *DiTauPhiDYH_ = (TH1F*)infileDYH.Get("DiTauPhi");
  TH1F *DiMuEtaDYH_ = (TH1F*)infileDYH.Get("DiMuEta");
  TH1F *DiMudRDYH_ = (TH1F*)infileDYH.Get("DiMudR");
  TH1F *DiMuPhiDYH_ = (TH1F*)infileDYH.Get("DiMuPhi");
  TH1F *EtMETDYH_ = (TH1F*)infileDYH.Get("EtMET");
  TH1F *DiTauDiMuMassDYH_ = (TH1F*)infileDYH.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiDYH_ = (TH1F*)infileDYH.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiDYH_ = (TH1F*)infileDYH.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiDYH_ = (TH1F*)infileDYH.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRDYH_ = (TH1F*)infileDYH.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRDYH_ = (TH1F*)infileDYH.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRDYH_ = (TH1F*)infileDYH.Get("ZMassdR");

  ////////////////
  // QCD_1000toInf
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("InvMassFullRange");
  InvMassTauHadMu3QCD_1000toInf_->Rebin(3);
  InvMassFullRangeQCD_1000toInf_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("Mu1Pt");
  TH1F *Mu2PtQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("Mu2Pt");
  TH1F *DiMuPtQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DiMuPt");
  TH1F *Mu1EtaQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("Mu1Eta");
  TH1F *Mu2EtaQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("Mu2Eta");
  TH1F *DiTauEtaQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DiTauEta");
  TH1F *DiTauPhiQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DiTauPhi");
  TH1F *DiMuEtaQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DiMuEta");
  TH1F *DiMudRQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DiMudR");
  TH1F *DiMuPhiQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DiMuPhi");
  TH1F *EtMETQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("EtMET");
  TH1F *DiTauDiMuMassQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRQCD_1000toInf_ = (TH1F*)infileQCD_1000toInf.Get("ZMassdR");

  ////////////////
  // QCD_120to170
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_120to170_ = (TH1F*)infileQCD_120to170.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_120to170_ = (TH1F*)infileQCD_120to170.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_120to170_ = (TH1F*)infileQCD_120to170.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("InvMassFullRange");
  InvMassTauHadMu3QCD_120to170_->Rebin(3);
  InvMassFullRangeQCD_120to170_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("Mu1Pt");
  TH1F *Mu2PtQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("Mu2Pt");
  TH1F *DiMuPtQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DiMuPt");
  TH1F *Mu1EtaQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("Mu1Eta");
  TH1F *Mu2EtaQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("Mu2Eta");
  TH1F *DiTauEtaQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DiTauEta");
  TH1F *DiTauPhiQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DiTauPhi");
  TH1F *DiMuEtaQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DiMuEta");
  TH1F *DiMudRQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DiMudR");
  TH1F *DiMuPhiQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DiMuPhi");
  TH1F *EtMETQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("EtMET");
  TH1F *DiTauDiMuMassQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRQCD_120to170_ = (TH1F*)infileQCD_120to170.Get("ZMassdR");

  ////////////////
  // QCD_15to20
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_15to20_ = (TH1F*)infileQCD_15to20.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_15to20_ = (TH1F*)infileQCD_15to20.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_15to20_ = (TH1F*)infileQCD_15to20.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("InvMassFullRange");
  InvMassTauHadMu3QCD_15to20_->Rebin(3);
  InvMassFullRangeQCD_15to20_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("Mu1Pt");
  TH1F *Mu2PtQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("Mu2Pt");
  TH1F *DiMuPtQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DiMuPt");
  TH1F *Mu1EtaQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("Mu1Eta");
  TH1F *Mu2EtaQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("Mu2Eta");
  TH1F *DiTauEtaQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DiTauEta");
  TH1F *DiTauPhiQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DiTauPhi");
  TH1F *DiMuEtaQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DiMuEta");
  TH1F *DiMudRQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DiMudR");
  TH1F *DiMuPhiQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DiMuPhi");
  TH1F *EtMETQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("EtMET");
  TH1F *DiTauDiMuMassQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRQCD_15to20_ = (TH1F*)infileQCD_15to20.Get("ZMassdR");

  ////////////////
  // QCD_170to300
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_170to300_ = (TH1F*)infileQCD_170to300.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_170to300_ = (TH1F*)infileQCD_170to300.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_170to300_ = (TH1F*)infileQCD_170to300.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("InvMassFullRange");
  InvMassTauHadMu3QCD_170to300_->Rebin(3);
  InvMassFullRangeQCD_170to300_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("Mu1Pt");
  TH1F *Mu2PtQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("Mu2Pt");
  TH1F *DiMuPtQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DiMuPt");
  TH1F *Mu1EtaQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("Mu1Eta");
  TH1F *Mu2EtaQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("Mu2Eta");
  TH1F *DiTauEtaQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DiTauEta");
  TH1F *DiTauPhiQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DiTauPhi");
  TH1F *DiMuEtaQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DiMuEta");
  TH1F *DiMudRQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DiMudR");
  TH1F *DiMuPhiQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DiMuPhi");
  TH1F *EtMETQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("EtMET");
  TH1F *DiTauDiMuMassQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRQCD_170to300_ = (TH1F*)infileQCD_170to300.Get("ZMassdR");

  ////////////////
  // QCD_20to30
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_20to30_ = (TH1F*)infileQCD_20to30.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_20to30_ = (TH1F*)infileQCD_20to30.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_20to30_ = (TH1F*)infileQCD_20to30.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("InvMassFullRange");
  InvMassTauHadMu3QCD_20to30_->Rebin(3);
  InvMassFullRangeQCD_20to30_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("Mu1Pt");
  TH1F *Mu2PtQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("Mu2Pt");
  TH1F *DiMuPtQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DiMuPt");
  TH1F *Mu1EtaQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("Mu1Eta");
  TH1F *Mu2EtaQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("Mu2Eta");
  TH1F *DiTauEtaQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DiTauEta");
  TH1F *DiTauPhiQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DiTauPhi");
  TH1F *DiMuEtaQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DiMuEta");
  TH1F *DiMudRQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DiMudR");
  TH1F *DiMuPhiQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DiMuPhi");
  TH1F *EtMETQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("EtMET");
  TH1F *DiTauDiMuMassQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRQCD_20to30_ = (TH1F*)infileQCD_20to30.Get("ZMassdR");

  ////////////////
  // QCD_300to470
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_300to470_ = (TH1F*)infileQCD_300to470.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_300to470_ = (TH1F*)infileQCD_300to470.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_300to470_ = (TH1F*)infileQCD_300to470.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("InvMassFullRange");
  InvMassTauHadMu3QCD_300to470_->Rebin(3);
  InvMassFullRangeQCD_300to470_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("Mu1Pt");
  TH1F *Mu2PtQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("Mu2Pt");
  TH1F *DiMuPtQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DiMuPt");
  TH1F *Mu1EtaQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("Mu1Eta");
  TH1F *Mu2EtaQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("Mu2Eta");
  TH1F *DiTauEtaQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DiTauEta");
  TH1F *DiTauPhiQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DiTauPhi");
  TH1F *DiMuEtaQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DiMuEta");
  TH1F *DiMudRQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DiMudR");
  TH1F *DiMuPhiQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DiMuPhi");
  TH1F *EtMETQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("EtMET");
  TH1F *DiTauDiMuMassQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRQCD_300to470_ = (TH1F*)infileQCD_300to470.Get("ZMassdR");

  ////////////////
  // QCD_30to50
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_30to50_ = (TH1F*)infileQCD_30to50.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_30to50_ = (TH1F*)infileQCD_30to50.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_30to50_ = (TH1F*)infileQCD_30to50.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("InvMassFullRange");
  InvMassTauHadMu3QCD_30to50_->Rebin(3);
  InvMassFullRangeQCD_30to50_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("Mu1Pt");
  TH1F *Mu2PtQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("Mu2Pt");
  TH1F *DiMuPtQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DiMuPt");
  TH1F *Mu1EtaQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("Mu1Eta");
  TH1F *Mu2EtaQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("Mu2Eta");
  TH1F *DiTauEtaQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DiTauEta");
  TH1F *DiTauPhiQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DiTauPhi");
  TH1F *DiMuEtaQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DiMuEta");
  TH1F *DiMudRQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DiMudR");
  TH1F *DiMuPhiQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DiMuPhi");
  TH1F *EtMETQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("EtMET");
  TH1F *DiTauDiMuMassQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRQCD_30to50_ = (TH1F*)infileQCD_30to50.Get("ZMassdR");

  ////////////////
  // QCD_470to600
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_470to600_ = (TH1F*)infileQCD_470to600.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_470to600_ = (TH1F*)infileQCD_470to600.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_470to600_ = (TH1F*)infileQCD_470to600.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("InvMassFullRange");
  InvMassTauHadMu3QCD_470to600_->Rebin(3);
  InvMassFullRangeQCD_470to600_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("Mu1Pt");
  TH1F *Mu2PtQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("Mu2Pt");
  TH1F *DiMuPtQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DiMuPt");
  TH1F *Mu1EtaQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("Mu1Eta");
  TH1F *Mu2EtaQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("Mu2Eta");
  TH1F *DiTauEtaQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DiTauEta");
  TH1F *DiTauPhiQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DiTauPhi");
  TH1F *DiMuEtaQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DiMuEta");
  TH1F *DiMudRQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DiMudR");
  TH1F *DiMuPhiQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DiMuPhi");
  TH1F *EtMETQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("EtMET");
  TH1F *DiTauDiMuMassQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRQCD_470to600_ = (TH1F*)infileQCD_470to600.Get("ZMassdR");

  ////////////////
  // QCD_50to80
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_50to80_ = (TH1F*)infileQCD_50to80.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_50to80_ = (TH1F*)infileQCD_50to80.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_50to80_ = (TH1F*)infileQCD_50to80.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("InvMassFullRange");
  InvMassTauHadMu3QCD_50to80_->Rebin(3);
  InvMassFullRangeQCD_50to80_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("Mu1Pt");
  TH1F *Mu2PtQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("Mu2Pt");
  TH1F *DiMuPtQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DiMuPt");
  TH1F *Mu1EtaQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("Mu1Eta");
  TH1F *Mu2EtaQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("Mu2Eta");
  TH1F *DiTauEtaQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DiTauEta");
  TH1F *DiTauPhiQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DiTauPhi");
  TH1F *DiMuEtaQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DiMuEta");
  TH1F *DiMudRQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DiMudR");
  TH1F *DiMuPhiQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DiMuPhi");
  TH1F *EtMETQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("EtMET");
  TH1F *DiTauDiMuMassQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRQCD_50to80_ = (TH1F*)infileQCD_50to80.Get("ZMassdR");

  ////////////////
  // QCD_600to800
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_600to800_ = (TH1F*)infileQCD_600to800.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_600to800_ = (TH1F*)infileQCD_600to800.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_600to800_ = (TH1F*)infileQCD_600to800.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("InvMassFullRange");
  InvMassTauHadMu3QCD_600to800_->Rebin(3);
  InvMassFullRangeQCD_600to800_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("Mu1Pt");
  TH1F *Mu2PtQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("Mu2Pt");
  TH1F *DiMuPtQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DiMuPt");
  TH1F *Mu1EtaQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("Mu1Eta");
  TH1F *Mu2EtaQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("Mu2Eta");
  TH1F *DiTauEtaQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DiTauEta");
  TH1F *DiTauPhiQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DiTauPhi");
  TH1F *DiMuEtaQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DiMuEta");
  TH1F *DiMudRQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DiMudR");
  TH1F *DiMuPhiQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DiMuPhi");
  TH1F *EtMETQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("EtMET");
  TH1F *DiTauDiMuMassQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRQCD_600to800_ = (TH1F*)infileQCD_600to800.Get("ZMassdR");

  ////////////////
  // QCD_800to1000
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("InvMassFullRange");
  InvMassTauHadMu3QCD_800to1000_->Rebin(3);
  InvMassFullRangeQCD_800to1000_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("Mu1Pt");
  TH1F *Mu2PtQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("Mu2Pt");
  TH1F *DiMuPtQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DiMuPt");
  TH1F *Mu1EtaQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("Mu1Eta");
  TH1F *Mu2EtaQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("Mu2Eta");
  TH1F *DiTauEtaQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DiTauEta");
  TH1F *DiTauPhiQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DiTauPhi");
  TH1F *DiMuEtaQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DiMuEta");
  TH1F *DiMudRQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DiMudR");
  TH1F *DiMuPhiQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DiMuPhi");
  TH1F *EtMETQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("EtMET");
  TH1F *DiTauDiMuMassQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRQCD_800to1000_ = (TH1F*)infileQCD_800to1000.Get("ZMassdR");

  ////////////////
  // QCD_80to120
  ////////////////
  TH1F *NMedIsoTausWithMu3QCD_80to120_ = (TH1F*)infileQCD_80to120.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3QCD_80to120_ = (TH1F*)infileQCD_80to120.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3QCD_80to120_ = (TH1F*)infileQCD_80to120.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("InvMassFullRange");
  InvMassTauHadMu3QCD_80to120_->Rebin(3);
  InvMassFullRangeQCD_80to120_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("Mu1Pt");
  TH1F *Mu2PtQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("Mu2Pt");
  TH1F *DiMuPtQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DiMuPt");
  TH1F *Mu1EtaQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("Mu1Eta");
  TH1F *Mu2EtaQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("Mu2Eta");
  TH1F *DiTauEtaQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DiTauEta");
  TH1F *DiTauPhiQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DiTauPhi");
  TH1F *DiMuEtaQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DiMuEta");
  TH1F *DiMudRQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DiMudR");
  TH1F *DiMuPhiQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DiMuPhi");
  TH1F *EtMETQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("EtMET");
  TH1F *DiTauDiMuMassQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRQCD_80to120_ = (TH1F*)infileQCD_80to120.Get("ZMassdR");

  ////////////////
  // h125a11
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a11_ = (TH1F*)infileh125a11.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a11_ = (TH1F*)infileh125a11.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a11_ = (TH1F*)infileh125a11.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh125a11_ = (TH1F*)infileh125a11.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh125a11_ = (TH1F*)infileh125a11.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh125a11_ = (TH1F*)infileh125a11.Get("InvMassFullRange");
  InvMassTauHadMu3h125a11_->Rebin(3);
  InvMassFullRangeh125a11_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh125a11_ = (TH1F*)infileh125a11.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a11_ = (TH1F*)infileh125a11.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a11_ = (TH1F*)infileh125a11.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a11_ = (TH1F*)infileh125a11.Get("Mu1Pt");
  TH1F *Mu2Pth125a11_ = (TH1F*)infileh125a11.Get("Mu2Pt");
  TH1F *DiMuPth125a11_ = (TH1F*)infileh125a11.Get("DiMuPt");
  TH1F *Mu1Etah125a11_ = (TH1F*)infileh125a11.Get("Mu1Eta");
  TH1F *Mu2Etah125a11_ = (TH1F*)infileh125a11.Get("Mu2Eta");
  TH1F *DiTauEtah125a11_ = (TH1F*)infileh125a11.Get("DiTauEta");
  TH1F *DiTauPhih125a11_ = (TH1F*)infileh125a11.Get("DiTauPhi");
  TH1F *DiMuEtah125a11_ = (TH1F*)infileh125a11.Get("DiMuEta");
  TH1F *DiMudRh125a11_ = (TH1F*)infileh125a11.Get("DiMudR");
  TH1F *DiMuPhih125a11_ = (TH1F*)infileh125a11.Get("DiMuPhi");
  TH1F *EtMETh125a11_ = (TH1F*)infileh125a11.Get("EtMET");
  TH1F *DiTauDiMuMassh125a11_ = (TH1F*)infileh125a11.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a11_ = (TH1F*)infileh125a11.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a11_ = (TH1F*)infileh125a11.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a11_ = (TH1F*)infileh125a11.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a11_ = (TH1F*)infileh125a11.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a11_ = (TH1F*)infileh125a11.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh125a11_ = (TH1F*)infileh125a11.Get("ZMassdR");

  ////////////////
  // h125a13
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a13_ = (TH1F*)infileh125a13.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a13_ = (TH1F*)infileh125a13.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a13_ = (TH1F*)infileh125a13.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh125a13_ = (TH1F*)infileh125a13.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh125a13_ = (TH1F*)infileh125a13.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh125a13_ = (TH1F*)infileh125a13.Get("InvMassFullRange");
  InvMassTauHadMu3h125a13_->Rebin(3);
  InvMassFullRangeh125a13_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh125a13_ = (TH1F*)infileh125a13.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a13_ = (TH1F*)infileh125a13.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a13_ = (TH1F*)infileh125a13.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a13_ = (TH1F*)infileh125a13.Get("Mu1Pt");
  TH1F *Mu2Pth125a13_ = (TH1F*)infileh125a13.Get("Mu2Pt");
  TH1F *DiMuPth125a13_ = (TH1F*)infileh125a13.Get("DiMuPt");
  TH1F *Mu1Etah125a13_ = (TH1F*)infileh125a13.Get("Mu1Eta");
  TH1F *Mu2Etah125a13_ = (TH1F*)infileh125a13.Get("Mu2Eta");
  TH1F *DiTauEtah125a13_ = (TH1F*)infileh125a13.Get("DiTauEta");
  TH1F *DiTauPhih125a13_ = (TH1F*)infileh125a13.Get("DiTauPhi");
  TH1F *DiMuEtah125a13_ = (TH1F*)infileh125a13.Get("DiMuEta");
  TH1F *DiMudRh125a13_ = (TH1F*)infileh125a13.Get("DiMudR");
  TH1F *DiMuPhih125a13_ = (TH1F*)infileh125a13.Get("DiMuPhi");
  TH1F *EtMETh125a13_ = (TH1F*)infileh125a13.Get("EtMET");
  TH1F *DiTauDiMuMassh125a13_ = (TH1F*)infileh125a13.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a13_ = (TH1F*)infileh125a13.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a13_ = (TH1F*)infileh125a13.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a13_ = (TH1F*)infileh125a13.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a13_ = (TH1F*)infileh125a13.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a13_ = (TH1F*)infileh125a13.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh125a13_ = (TH1F*)infileh125a13.Get("ZMassdR");

  ////////////////
  // h125a15
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a15_ = (TH1F*)infileh125a15.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a15_ = (TH1F*)infileh125a15.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a15_ = (TH1F*)infileh125a15.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh125a15_ = (TH1F*)infileh125a15.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh125a15_ = (TH1F*)infileh125a15.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh125a15_ = (TH1F*)infileh125a15.Get("InvMassFullRange");
  InvMassTauHadMu3h125a15_->Rebin(3);
  InvMassFullRangeh125a15_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh125a15_ = (TH1F*)infileh125a15.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a15_ = (TH1F*)infileh125a15.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a15_ = (TH1F*)infileh125a15.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a15_ = (TH1F*)infileh125a15.Get("Mu1Pt");
  TH1F *Mu2Pth125a15_ = (TH1F*)infileh125a15.Get("Mu2Pt");
  TH1F *DiMuPth125a15_ = (TH1F*)infileh125a15.Get("DiMuPt");
  TH1F *Mu1Etah125a15_ = (TH1F*)infileh125a15.Get("Mu1Eta");
  TH1F *Mu2Etah125a15_ = (TH1F*)infileh125a15.Get("Mu2Eta");
  TH1F *DiTauEtah125a15_ = (TH1F*)infileh125a15.Get("DiTauEta");
  TH1F *DiTauPhih125a15_ = (TH1F*)infileh125a15.Get("DiTauPhi");
  TH1F *DiMuEtah125a15_ = (TH1F*)infileh125a15.Get("DiMuEta");
  TH1F *DiMudRh125a15_ = (TH1F*)infileh125a15.Get("DiMudR");
  TH1F *DiMuPhih125a15_ = (TH1F*)infileh125a15.Get("DiMuPhi");
  TH1F *EtMETh125a15_ = (TH1F*)infileh125a15.Get("EtMET");
  TH1F *DiTauDiMuMassh125a15_ = (TH1F*)infileh125a15.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a15_ = (TH1F*)infileh125a15.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a15_ = (TH1F*)infileh125a15.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a15_ = (TH1F*)infileh125a15.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a15_ = (TH1F*)infileh125a15.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a15_ = (TH1F*)infileh125a15.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh125a15_ = (TH1F*)infileh125a15.Get("ZMassdR");

  ////////////////
  // h125a17
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a17_ = (TH1F*)infileh125a17.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a17_ = (TH1F*)infileh125a17.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a17_ = (TH1F*)infileh125a17.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh125a17_ = (TH1F*)infileh125a17.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh125a17_ = (TH1F*)infileh125a17.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh125a17_ = (TH1F*)infileh125a17.Get("InvMassFullRange");
  InvMassTauHadMu3h125a17_->Rebin(3);
  InvMassFullRangeh125a17_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh125a17_ = (TH1F*)infileh125a17.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a17_ = (TH1F*)infileh125a17.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a17_ = (TH1F*)infileh125a17.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a17_ = (TH1F*)infileh125a17.Get("Mu1Pt");
  TH1F *Mu2Pth125a17_ = (TH1F*)infileh125a17.Get("Mu2Pt");
  TH1F *DiMuPth125a17_ = (TH1F*)infileh125a17.Get("DiMuPt");
  TH1F *Mu1Etah125a17_ = (TH1F*)infileh125a17.Get("Mu1Eta");
  TH1F *Mu2Etah125a17_ = (TH1F*)infileh125a17.Get("Mu2Eta");
  TH1F *DiTauEtah125a17_ = (TH1F*)infileh125a17.Get("DiTauEta");
  TH1F *DiTauPhih125a17_ = (TH1F*)infileh125a17.Get("DiTauPhi");
  TH1F *DiMuEtah125a17_ = (TH1F*)infileh125a17.Get("DiMuEta");
  TH1F *DiMudRh125a17_ = (TH1F*)infileh125a17.Get("DiMudR");
  TH1F *DiMuPhih125a17_ = (TH1F*)infileh125a17.Get("DiMuPhi");
  TH1F *EtMETh125a17_ = (TH1F*)infileh125a17.Get("EtMET");
  TH1F *DiTauDiMuMassh125a17_ = (TH1F*)infileh125a17.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a17_ = (TH1F*)infileh125a17.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a17_ = (TH1F*)infileh125a17.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a17_ = (TH1F*)infileh125a17.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a17_ = (TH1F*)infileh125a17.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a17_ = (TH1F*)infileh125a17.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh125a17_ = (TH1F*)infileh125a17.Get("ZMassdR");

  ////////////////
  // h125a19
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a19_ = (TH1F*)infileh125a19.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a19_ = (TH1F*)infileh125a19.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a19_ = (TH1F*)infileh125a19.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh125a19_ = (TH1F*)infileh125a19.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh125a19_ = (TH1F*)infileh125a19.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh125a19_ = (TH1F*)infileh125a19.Get("InvMassFullRange");
  InvMassTauHadMu3h125a19_->Rebin(3);
  InvMassFullRangeh125a19_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh125a19_ = (TH1F*)infileh125a19.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a19_ = (TH1F*)infileh125a19.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a19_ = (TH1F*)infileh125a19.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a19_ = (TH1F*)infileh125a19.Get("Mu1Pt");
  TH1F *Mu2Pth125a19_ = (TH1F*)infileh125a19.Get("Mu2Pt");
  TH1F *DiMuPth125a19_ = (TH1F*)infileh125a19.Get("DiMuPt");
  TH1F *Mu1Etah125a19_ = (TH1F*)infileh125a19.Get("Mu1Eta");
  TH1F *Mu2Etah125a19_ = (TH1F*)infileh125a19.Get("Mu2Eta");
  TH1F *DiTauEtah125a19_ = (TH1F*)infileh125a19.Get("DiTauEta");
  TH1F *DiTauPhih125a19_ = (TH1F*)infileh125a19.Get("DiTauPhi");
  TH1F *DiMuEtah125a19_ = (TH1F*)infileh125a19.Get("DiMuEta");
  TH1F *DiMudRh125a19_ = (TH1F*)infileh125a19.Get("DiMudR");
  TH1F *DiMuPhih125a19_ = (TH1F*)infileh125a19.Get("DiMuPhi");
  TH1F *EtMETh125a19_ = (TH1F*)infileh125a19.Get("EtMET");
  TH1F *DiTauDiMuMassh125a19_ = (TH1F*)infileh125a19.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a19_ = (TH1F*)infileh125a19.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a19_ = (TH1F*)infileh125a19.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a19_ = (TH1F*)infileh125a19.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a19_ = (TH1F*)infileh125a19.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a19_ = (TH1F*)infileh125a19.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh125a19_ = (TH1F*)infileh125a19.Get("ZMassdR");

  ////////////////
  // h125a21
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a21_ = (TH1F*)infileh125a21.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a21_ = (TH1F*)infileh125a21.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a21_ = (TH1F*)infileh125a21.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh125a21_ = (TH1F*)infileh125a21.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh125a21_ = (TH1F*)infileh125a21.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh125a21_ = (TH1F*)infileh125a21.Get("InvMassFullRange");
  InvMassTauHadMu3h125a21_->Rebin(3);
  InvMassFullRangeh125a21_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh125a21_ = (TH1F*)infileh125a21.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a21_ = (TH1F*)infileh125a21.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a21_ = (TH1F*)infileh125a21.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a21_ = (TH1F*)infileh125a21.Get("Mu1Pt");
  TH1F *Mu2Pth125a21_ = (TH1F*)infileh125a21.Get("Mu2Pt");
  TH1F *DiMuPth125a21_ = (TH1F*)infileh125a21.Get("DiMuPt");
  TH1F *Mu1Etah125a21_ = (TH1F*)infileh125a21.Get("Mu1Eta");
  TH1F *Mu2Etah125a21_ = (TH1F*)infileh125a21.Get("Mu2Eta");
  TH1F *DiTauEtah125a21_ = (TH1F*)infileh125a21.Get("DiTauEta");
  TH1F *DiTauPhih125a21_ = (TH1F*)infileh125a21.Get("DiTauPhi");
  TH1F *DiMuEtah125a21_ = (TH1F*)infileh125a21.Get("DiMuEta");
  TH1F *DiMudRh125a21_ = (TH1F*)infileh125a21.Get("DiMudR");
  TH1F *DiMuPhih125a21_ = (TH1F*)infileh125a21.Get("DiMuPhi");
  TH1F *EtMETh125a21_ = (TH1F*)infileh125a21.Get("EtMET");
  TH1F *DiTauDiMuMassh125a21_ = (TH1F*)infileh125a21.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a21_ = (TH1F*)infileh125a21.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a21_ = (TH1F*)infileh125a21.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a21_ = (TH1F*)infileh125a21.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a21_ = (TH1F*)infileh125a21.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a21_ = (TH1F*)infileh125a21.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh125a21_ = (TH1F*)infileh125a21.Get("ZMassdR");

  ////////////////
  // h125a5
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a5_ = (TH1F*)infileh125a5.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a5_ = (TH1F*)infileh125a5.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a5_ = (TH1F*)infileh125a5.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh125a5_ = (TH1F*)infileh125a5.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh125a5_ = (TH1F*)infileh125a5.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh125a5_ = (TH1F*)infileh125a5.Get("InvMassFullRange");
  InvMassTauHadMu3h125a5_->Rebin(3);
  InvMassFullRangeh125a5_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh125a5_ = (TH1F*)infileh125a5.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a5_ = (TH1F*)infileh125a5.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a5_ = (TH1F*)infileh125a5.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a5_ = (TH1F*)infileh125a5.Get("Mu1Pt");
  TH1F *Mu2Pth125a5_ = (TH1F*)infileh125a5.Get("Mu2Pt");
  TH1F *DiMuPth125a5_ = (TH1F*)infileh125a5.Get("DiMuPt");
  TH1F *Mu1Etah125a5_ = (TH1F*)infileh125a5.Get("Mu1Eta");
  TH1F *Mu2Etah125a5_ = (TH1F*)infileh125a5.Get("Mu2Eta");
  TH1F *DiTauEtah125a5_ = (TH1F*)infileh125a5.Get("DiTauEta");
  TH1F *DiTauPhih125a5_ = (TH1F*)infileh125a5.Get("DiTauPhi");
  TH1F *DiMuEtah125a5_ = (TH1F*)infileh125a5.Get("DiMuEta");
  TH1F *DiMudRh125a5_ = (TH1F*)infileh125a5.Get("DiMudR");
  TH1F *DiMuPhih125a5_ = (TH1F*)infileh125a5.Get("DiMuPhi");
  TH1F *EtMETh125a5_ = (TH1F*)infileh125a5.Get("EtMET");
  TH1F *DiTauDiMuMassh125a5_ = (TH1F*)infileh125a5.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a5_ = (TH1F*)infileh125a5.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a5_ = (TH1F*)infileh125a5.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a5_ = (TH1F*)infileh125a5.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a5_ = (TH1F*)infileh125a5.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a5_ = (TH1F*)infileh125a5.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh125a5_ = (TH1F*)infileh125a5.Get("ZMassdR");

  ////////////////
  // h125a7
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a7_ = (TH1F*)infileh125a7.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a7_ = (TH1F*)infileh125a7.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a7_ = (TH1F*)infileh125a7.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh125a7_ = (TH1F*)infileh125a7.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh125a7_ = (TH1F*)infileh125a7.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh125a7_ = (TH1F*)infileh125a7.Get("InvMassFullRange");
  InvMassTauHadMu3h125a7_->Rebin(3);
  InvMassFullRangeh125a7_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh125a7_ = (TH1F*)infileh125a7.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a7_ = (TH1F*)infileh125a7.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a7_ = (TH1F*)infileh125a7.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a7_ = (TH1F*)infileh125a7.Get("Mu1Pt");
  TH1F *Mu2Pth125a7_ = (TH1F*)infileh125a7.Get("Mu2Pt");
  TH1F *DiMuPth125a7_ = (TH1F*)infileh125a7.Get("DiMuPt");
  TH1F *Mu1Etah125a7_ = (TH1F*)infileh125a7.Get("Mu1Eta");
  TH1F *Mu2Etah125a7_ = (TH1F*)infileh125a7.Get("Mu2Eta");
  TH1F *DiTauEtah125a7_ = (TH1F*)infileh125a7.Get("DiTauEta");
  TH1F *DiTauPhih125a7_ = (TH1F*)infileh125a7.Get("DiTauPhi");
  TH1F *DiMuEtah125a7_ = (TH1F*)infileh125a7.Get("DiMuEta");
  TH1F *DiMudRh125a7_ = (TH1F*)infileh125a7.Get("DiMudR");
  TH1F *DiMuPhih125a7_ = (TH1F*)infileh125a7.Get("DiMuPhi");
  TH1F *EtMETh125a7_ = (TH1F*)infileh125a7.Get("EtMET");
  TH1F *DiTauDiMuMassh125a7_ = (TH1F*)infileh125a7.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a7_ = (TH1F*)infileh125a7.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a7_ = (TH1F*)infileh125a7.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a7_ = (TH1F*)infileh125a7.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a7_ = (TH1F*)infileh125a7.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a7_ = (TH1F*)infileh125a7.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh125a7_ = (TH1F*)infileh125a7.Get("ZMassdR");

  ////////////////
  // h125a9
  ////////////////
  TH1F *NMedIsoTausWithMu3h125a9_ = (TH1F*)infileh125a9.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h125a9_ = (TH1F*)infileh125a9.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h125a9_ = (TH1F*)infileh125a9.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh125a9_ = (TH1F*)infileh125a9.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh125a9_ = (TH1F*)infileh125a9.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh125a9_ = (TH1F*)infileh125a9.Get("InvMassFullRange");
  InvMassTauHadMu3h125a9_->Rebin(3);
  InvMassFullRangeh125a9_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh125a9_ = (TH1F*)infileh125a9.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch125a9_ = (TH1F*)infileh125a9.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch125a9_ = (TH1F*)infileh125a9.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth125a9_ = (TH1F*)infileh125a9.Get("Mu1Pt");
  TH1F *Mu2Pth125a9_ = (TH1F*)infileh125a9.Get("Mu2Pt");
  TH1F *DiMuPth125a9_ = (TH1F*)infileh125a9.Get("DiMuPt");
  TH1F *Mu1Etah125a9_ = (TH1F*)infileh125a9.Get("Mu1Eta");
  TH1F *Mu2Etah125a9_ = (TH1F*)infileh125a9.Get("Mu2Eta");
  TH1F *DiTauEtah125a9_ = (TH1F*)infileh125a9.Get("DiTauEta");
  TH1F *DiTauPhih125a9_ = (TH1F*)infileh125a9.Get("DiTauPhi");
  TH1F *DiMuEtah125a9_ = (TH1F*)infileh125a9.Get("DiMuEta");
  TH1F *DiMudRh125a9_ = (TH1F*)infileh125a9.Get("DiMudR");
  TH1F *DiMuPhih125a9_ = (TH1F*)infileh125a9.Get("DiMuPhi");
  TH1F *EtMETh125a9_ = (TH1F*)infileh125a9.Get("EtMET");
  TH1F *DiTauDiMuMassh125a9_ = (TH1F*)infileh125a9.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih125a9_ = (TH1F*)infileh125a9.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih125a9_ = (TH1F*)infileh125a9.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih125a9_ = (TH1F*)infileh125a9.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh125a9_ = (TH1F*)infileh125a9.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh125a9_ = (TH1F*)infileh125a9.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh125a9_ = (TH1F*)infileh125a9.Get("ZMassdR");

  ////////////////
  // h300a11
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a11_ = (TH1F*)infileh300a11.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a11_ = (TH1F*)infileh300a11.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a11_ = (TH1F*)infileh300a11.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh300a11_ = (TH1F*)infileh300a11.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh300a11_ = (TH1F*)infileh300a11.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh300a11_ = (TH1F*)infileh300a11.Get("InvMassFullRange");
  InvMassTauHadMu3h300a11_->Rebin(3);
  InvMassFullRangeh300a11_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh300a11_ = (TH1F*)infileh300a11.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a11_ = (TH1F*)infileh300a11.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a11_ = (TH1F*)infileh300a11.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a11_ = (TH1F*)infileh300a11.Get("Mu1Pt");
  TH1F *Mu2Pth300a11_ = (TH1F*)infileh300a11.Get("Mu2Pt");
  TH1F *DiMuPth300a11_ = (TH1F*)infileh300a11.Get("DiMuPt");
  TH1F *Mu1Etah300a11_ = (TH1F*)infileh300a11.Get("Mu1Eta");
  TH1F *Mu2Etah300a11_ = (TH1F*)infileh300a11.Get("Mu2Eta");
  TH1F *DiTauEtah300a11_ = (TH1F*)infileh300a11.Get("DiTauEta");
  TH1F *DiTauPhih300a11_ = (TH1F*)infileh300a11.Get("DiTauPhi");
  TH1F *DiMuEtah300a11_ = (TH1F*)infileh300a11.Get("DiMuEta");
  TH1F *DiMudRh300a11_ = (TH1F*)infileh300a11.Get("DiMudR");
  TH1F *DiMuPhih300a11_ = (TH1F*)infileh300a11.Get("DiMuPhi");
  TH1F *EtMETh300a11_ = (TH1F*)infileh300a11.Get("EtMET");
  TH1F *DiTauDiMuMassh300a11_ = (TH1F*)infileh300a11.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a11_ = (TH1F*)infileh300a11.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a11_ = (TH1F*)infileh300a11.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a11_ = (TH1F*)infileh300a11.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a11_ = (TH1F*)infileh300a11.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a11_ = (TH1F*)infileh300a11.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh300a11_ = (TH1F*)infileh300a11.Get("ZMassdR");

  ////////////////
  // h300a13
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a13_ = (TH1F*)infileh300a13.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a13_ = (TH1F*)infileh300a13.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a13_ = (TH1F*)infileh300a13.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh300a13_ = (TH1F*)infileh300a13.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh300a13_ = (TH1F*)infileh300a13.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh300a13_ = (TH1F*)infileh300a13.Get("InvMassFullRange");
  InvMassTauHadMu3h300a13_->Rebin(3);
  InvMassFullRangeh300a13_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh300a13_ = (TH1F*)infileh300a13.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a13_ = (TH1F*)infileh300a13.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a13_ = (TH1F*)infileh300a13.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a13_ = (TH1F*)infileh300a13.Get("Mu1Pt");
  TH1F *Mu2Pth300a13_ = (TH1F*)infileh300a13.Get("Mu2Pt");
  TH1F *DiMuPth300a13_ = (TH1F*)infileh300a13.Get("DiMuPt");
  TH1F *Mu1Etah300a13_ = (TH1F*)infileh300a13.Get("Mu1Eta");
  TH1F *Mu2Etah300a13_ = (TH1F*)infileh300a13.Get("Mu2Eta");
  TH1F *DiTauEtah300a13_ = (TH1F*)infileh300a13.Get("DiTauEta");
  TH1F *DiTauPhih300a13_ = (TH1F*)infileh300a13.Get("DiTauPhi");
  TH1F *DiMuEtah300a13_ = (TH1F*)infileh300a13.Get("DiMuEta");
  TH1F *DiMudRh300a13_ = (TH1F*)infileh300a13.Get("DiMudR");
  TH1F *DiMuPhih300a13_ = (TH1F*)infileh300a13.Get("DiMuPhi");
  TH1F *EtMETh300a13_ = (TH1F*)infileh300a13.Get("EtMET");
  TH1F *DiTauDiMuMassh300a13_ = (TH1F*)infileh300a13.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a13_ = (TH1F*)infileh300a13.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a13_ = (TH1F*)infileh300a13.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a13_ = (TH1F*)infileh300a13.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a13_ = (TH1F*)infileh300a13.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a13_ = (TH1F*)infileh300a13.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh300a13_ = (TH1F*)infileh300a13.Get("ZMassdR");

  ////////////////
  // h300a15
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a15_ = (TH1F*)infileh300a15.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a15_ = (TH1F*)infileh300a15.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a15_ = (TH1F*)infileh300a15.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh300a15_ = (TH1F*)infileh300a15.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh300a15_ = (TH1F*)infileh300a15.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh300a15_ = (TH1F*)infileh300a15.Get("InvMassFullRange");
  InvMassTauHadMu3h300a15_->Rebin(3);
  InvMassFullRangeh300a15_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh300a15_ = (TH1F*)infileh300a15.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a15_ = (TH1F*)infileh300a15.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a15_ = (TH1F*)infileh300a15.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a15_ = (TH1F*)infileh300a15.Get("Mu1Pt");
  TH1F *Mu2Pth300a15_ = (TH1F*)infileh300a15.Get("Mu2Pt");
  TH1F *DiMuPth300a15_ = (TH1F*)infileh300a15.Get("DiMuPt");
  TH1F *Mu1Etah300a15_ = (TH1F*)infileh300a15.Get("Mu1Eta");
  TH1F *Mu2Etah300a15_ = (TH1F*)infileh300a15.Get("Mu2Eta");
  TH1F *DiTauEtah300a15_ = (TH1F*)infileh300a15.Get("DiTauEta");
  TH1F *DiTauPhih300a15_ = (TH1F*)infileh300a15.Get("DiTauPhi");
  TH1F *DiMuEtah300a15_ = (TH1F*)infileh300a15.Get("DiMuEta");
  TH1F *DiMudRh300a15_ = (TH1F*)infileh300a15.Get("DiMudR");
  TH1F *DiMuPhih300a15_ = (TH1F*)infileh300a15.Get("DiMuPhi");
  TH1F *EtMETh300a15_ = (TH1F*)infileh300a15.Get("EtMET");
  TH1F *DiTauDiMuMassh300a15_ = (TH1F*)infileh300a15.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a15_ = (TH1F*)infileh300a15.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a15_ = (TH1F*)infileh300a15.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a15_ = (TH1F*)infileh300a15.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a15_ = (TH1F*)infileh300a15.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a15_ = (TH1F*)infileh300a15.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh300a15_ = (TH1F*)infileh300a15.Get("ZMassdR");

  ////////////////
  // h300a17
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a17_ = (TH1F*)infileh300a17.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a17_ = (TH1F*)infileh300a17.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a17_ = (TH1F*)infileh300a17.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh300a17_ = (TH1F*)infileh300a17.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh300a17_ = (TH1F*)infileh300a17.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh300a17_ = (TH1F*)infileh300a17.Get("InvMassFullRange");
  InvMassTauHadMu3h300a17_->Rebin(3);
  InvMassFullRangeh300a17_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh300a17_ = (TH1F*)infileh300a17.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a17_ = (TH1F*)infileh300a17.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a17_ = (TH1F*)infileh300a17.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a17_ = (TH1F*)infileh300a17.Get("Mu1Pt");
  TH1F *Mu2Pth300a17_ = (TH1F*)infileh300a17.Get("Mu2Pt");
  TH1F *DiMuPth300a17_ = (TH1F*)infileh300a17.Get("DiMuPt");
  TH1F *Mu1Etah300a17_ = (TH1F*)infileh300a17.Get("Mu1Eta");
  TH1F *Mu2Etah300a17_ = (TH1F*)infileh300a17.Get("Mu2Eta");
  TH1F *DiTauEtah300a17_ = (TH1F*)infileh300a17.Get("DiTauEta");
  TH1F *DiTauPhih300a17_ = (TH1F*)infileh300a17.Get("DiTauPhi");
  TH1F *DiMuEtah300a17_ = (TH1F*)infileh300a17.Get("DiMuEta");
  TH1F *DiMudRh300a17_ = (TH1F*)infileh300a17.Get("DiMudR");
  TH1F *DiMuPhih300a17_ = (TH1F*)infileh300a17.Get("DiMuPhi");
  TH1F *EtMETh300a17_ = (TH1F*)infileh300a17.Get("EtMET");
  TH1F *DiTauDiMuMassh300a17_ = (TH1F*)infileh300a17.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a17_ = (TH1F*)infileh300a17.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a17_ = (TH1F*)infileh300a17.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a17_ = (TH1F*)infileh300a17.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a17_ = (TH1F*)infileh300a17.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a17_ = (TH1F*)infileh300a17.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh300a17_ = (TH1F*)infileh300a17.Get("ZMassdR");

  ////////////////
  // h300a19
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a19_ = (TH1F*)infileh300a19.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a19_ = (TH1F*)infileh300a19.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a19_ = (TH1F*)infileh300a19.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh300a19_ = (TH1F*)infileh300a19.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh300a19_ = (TH1F*)infileh300a19.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh300a19_ = (TH1F*)infileh300a19.Get("InvMassFullRange");
  InvMassTauHadMu3h300a19_->Rebin(3);
  InvMassFullRangeh300a19_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh300a19_ = (TH1F*)infileh300a19.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a19_ = (TH1F*)infileh300a19.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a19_ = (TH1F*)infileh300a19.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a19_ = (TH1F*)infileh300a19.Get("Mu1Pt");
  TH1F *Mu2Pth300a19_ = (TH1F*)infileh300a19.Get("Mu2Pt");
  TH1F *DiMuPth300a19_ = (TH1F*)infileh300a19.Get("DiMuPt");
  TH1F *Mu1Etah300a19_ = (TH1F*)infileh300a19.Get("Mu1Eta");
  TH1F *Mu2Etah300a19_ = (TH1F*)infileh300a19.Get("Mu2Eta");
  TH1F *DiTauEtah300a19_ = (TH1F*)infileh300a19.Get("DiTauEta");
  TH1F *DiTauPhih300a19_ = (TH1F*)infileh300a19.Get("DiTauPhi");
  TH1F *DiMuEtah300a19_ = (TH1F*)infileh300a19.Get("DiMuEta");
  TH1F *DiMudRh300a19_ = (TH1F*)infileh300a19.Get("DiMudR");
  TH1F *DiMuPhih300a19_ = (TH1F*)infileh300a19.Get("DiMuPhi");
  TH1F *EtMETh300a19_ = (TH1F*)infileh300a19.Get("EtMET");
  TH1F *DiTauDiMuMassh300a19_ = (TH1F*)infileh300a19.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a19_ = (TH1F*)infileh300a19.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a19_ = (TH1F*)infileh300a19.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a19_ = (TH1F*)infileh300a19.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a19_ = (TH1F*)infileh300a19.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a19_ = (TH1F*)infileh300a19.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh300a19_ = (TH1F*)infileh300a19.Get("ZMassdR");

  ////////////////
  // h300a21
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a21_ = (TH1F*)infileh300a21.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a21_ = (TH1F*)infileh300a21.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a21_ = (TH1F*)infileh300a21.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh300a21_ = (TH1F*)infileh300a21.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh300a21_ = (TH1F*)infileh300a21.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh300a21_ = (TH1F*)infileh300a21.Get("InvMassFullRange");
  InvMassTauHadMu3h300a21_->Rebin(3);
  InvMassFullRangeh300a21_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh300a21_ = (TH1F*)infileh300a21.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a21_ = (TH1F*)infileh300a21.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a21_ = (TH1F*)infileh300a21.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a21_ = (TH1F*)infileh300a21.Get("Mu1Pt");
  TH1F *Mu2Pth300a21_ = (TH1F*)infileh300a21.Get("Mu2Pt");
  TH1F *DiMuPth300a21_ = (TH1F*)infileh300a21.Get("DiMuPt");
  TH1F *Mu1Etah300a21_ = (TH1F*)infileh300a21.Get("Mu1Eta");
  TH1F *Mu2Etah300a21_ = (TH1F*)infileh300a21.Get("Mu2Eta");
  TH1F *DiTauEtah300a21_ = (TH1F*)infileh300a21.Get("DiTauEta");
  TH1F *DiTauPhih300a21_ = (TH1F*)infileh300a21.Get("DiTauPhi");
  TH1F *DiMuEtah300a21_ = (TH1F*)infileh300a21.Get("DiMuEta");
  TH1F *DiMudRh300a21_ = (TH1F*)infileh300a21.Get("DiMudR");
  TH1F *DiMuPhih300a21_ = (TH1F*)infileh300a21.Get("DiMuPhi");
  TH1F *EtMETh300a21_ = (TH1F*)infileh300a21.Get("EtMET");
  TH1F *DiTauDiMuMassh300a21_ = (TH1F*)infileh300a21.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a21_ = (TH1F*)infileh300a21.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a21_ = (TH1F*)infileh300a21.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a21_ = (TH1F*)infileh300a21.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a21_ = (TH1F*)infileh300a21.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a21_ = (TH1F*)infileh300a21.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh300a21_ = (TH1F*)infileh300a21.Get("ZMassdR");

  ////////////////
  // h300a5
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a5_ = (TH1F*)infileh300a5.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a5_ = (TH1F*)infileh300a5.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a5_ = (TH1F*)infileh300a5.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh300a5_ = (TH1F*)infileh300a5.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh300a5_ = (TH1F*)infileh300a5.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh300a5_ = (TH1F*)infileh300a5.Get("InvMassFullRange");
  InvMassTauHadMu3h300a5_->Rebin(3);
  InvMassFullRangeh300a5_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh300a5_ = (TH1F*)infileh300a5.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a5_ = (TH1F*)infileh300a5.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a5_ = (TH1F*)infileh300a5.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a5_ = (TH1F*)infileh300a5.Get("Mu1Pt");
  TH1F *Mu2Pth300a5_ = (TH1F*)infileh300a5.Get("Mu2Pt");
  TH1F *DiMuPth300a5_ = (TH1F*)infileh300a5.Get("DiMuPt");
  TH1F *Mu1Etah300a5_ = (TH1F*)infileh300a5.Get("Mu1Eta");
  TH1F *Mu2Etah300a5_ = (TH1F*)infileh300a5.Get("Mu2Eta");
  TH1F *DiTauEtah300a5_ = (TH1F*)infileh300a5.Get("DiTauEta");
  TH1F *DiTauPhih300a5_ = (TH1F*)infileh300a5.Get("DiTauPhi");
  TH1F *DiMuEtah300a5_ = (TH1F*)infileh300a5.Get("DiMuEta");
  TH1F *DiMudRh300a5_ = (TH1F*)infileh300a5.Get("DiMudR");
  TH1F *DiMuPhih300a5_ = (TH1F*)infileh300a5.Get("DiMuPhi");
  TH1F *EtMETh300a5_ = (TH1F*)infileh300a5.Get("EtMET");
  TH1F *DiTauDiMuMassh300a5_ = (TH1F*)infileh300a5.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a5_ = (TH1F*)infileh300a5.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a5_ = (TH1F*)infileh300a5.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a5_ = (TH1F*)infileh300a5.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a5_ = (TH1F*)infileh300a5.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a5_ = (TH1F*)infileh300a5.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh300a5_ = (TH1F*)infileh300a5.Get("ZMassdR");

  ////////////////
  // h300a7
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a7_ = (TH1F*)infileh300a7.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a7_ = (TH1F*)infileh300a7.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a7_ = (TH1F*)infileh300a7.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh300a7_ = (TH1F*)infileh300a7.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh300a7_ = (TH1F*)infileh300a7.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh300a7_ = (TH1F*)infileh300a7.Get("InvMassFullRange");
  InvMassTauHadMu3h300a7_->Rebin(3);
  InvMassFullRangeh300a7_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh300a7_ = (TH1F*)infileh300a7.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a7_ = (TH1F*)infileh300a7.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a7_ = (TH1F*)infileh300a7.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a7_ = (TH1F*)infileh300a7.Get("Mu1Pt");
  TH1F *Mu2Pth300a7_ = (TH1F*)infileh300a7.Get("Mu2Pt");
  TH1F *DiMuPth300a7_ = (TH1F*)infileh300a7.Get("DiMuPt");
  TH1F *Mu1Etah300a7_ = (TH1F*)infileh300a7.Get("Mu1Eta");
  TH1F *Mu2Etah300a7_ = (TH1F*)infileh300a7.Get("Mu2Eta");
  TH1F *DiTauEtah300a7_ = (TH1F*)infileh300a7.Get("DiTauEta");
  TH1F *DiTauPhih300a7_ = (TH1F*)infileh300a7.Get("DiTauPhi");
  TH1F *DiMuEtah300a7_ = (TH1F*)infileh300a7.Get("DiMuEta");
  TH1F *DiMudRh300a7_ = (TH1F*)infileh300a7.Get("DiMudR");
  TH1F *DiMuPhih300a7_ = (TH1F*)infileh300a7.Get("DiMuPhi");
  TH1F *EtMETh300a7_ = (TH1F*)infileh300a7.Get("EtMET");
  TH1F *DiTauDiMuMassh300a7_ = (TH1F*)infileh300a7.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a7_ = (TH1F*)infileh300a7.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a7_ = (TH1F*)infileh300a7.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a7_ = (TH1F*)infileh300a7.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a7_ = (TH1F*)infileh300a7.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a7_ = (TH1F*)infileh300a7.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh300a7_ = (TH1F*)infileh300a7.Get("ZMassdR");

  ////////////////
  // h300a9
  ////////////////
  TH1F *NMedIsoTausWithMu3h300a9_ = (TH1F*)infileh300a9.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h300a9_ = (TH1F*)infileh300a9.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h300a9_ = (TH1F*)infileh300a9.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh300a9_ = (TH1F*)infileh300a9.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh300a9_ = (TH1F*)infileh300a9.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh300a9_ = (TH1F*)infileh300a9.Get("InvMassFullRange");
  InvMassTauHadMu3h300a9_->Rebin(3);
  InvMassFullRangeh300a9_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh300a9_ = (TH1F*)infileh300a9.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch300a9_ = (TH1F*)infileh300a9.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch300a9_ = (TH1F*)infileh300a9.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth300a9_ = (TH1F*)infileh300a9.Get("Mu1Pt");
  TH1F *Mu2Pth300a9_ = (TH1F*)infileh300a9.Get("Mu2Pt");
  TH1F *DiMuPth300a9_ = (TH1F*)infileh300a9.Get("DiMuPt");
  TH1F *Mu1Etah300a9_ = (TH1F*)infileh300a9.Get("Mu1Eta");
  TH1F *Mu2Etah300a9_ = (TH1F*)infileh300a9.Get("Mu2Eta");
  TH1F *DiTauEtah300a9_ = (TH1F*)infileh300a9.Get("DiTauEta");
  TH1F *DiTauPhih300a9_ = (TH1F*)infileh300a9.Get("DiTauPhi");
  TH1F *DiMuEtah300a9_ = (TH1F*)infileh300a9.Get("DiMuEta");
  TH1F *DiMudRh300a9_ = (TH1F*)infileh300a9.Get("DiMudR");
  TH1F *DiMuPhih300a9_ = (TH1F*)infileh300a9.Get("DiMuPhi");
  TH1F *EtMETh300a9_ = (TH1F*)infileh300a9.Get("EtMET");
  TH1F *DiTauDiMuMassh300a9_ = (TH1F*)infileh300a9.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih300a9_ = (TH1F*)infileh300a9.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih300a9_ = (TH1F*)infileh300a9.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih300a9_ = (TH1F*)infileh300a9.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh300a9_ = (TH1F*)infileh300a9.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh300a9_ = (TH1F*)infileh300a9.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh300a9_ = (TH1F*)infileh300a9.Get("ZMassdR");

  ////////////////
  // h750a11
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a11_ = (TH1F*)infileh750a11.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a11_ = (TH1F*)infileh750a11.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a11_ = (TH1F*)infileh750a11.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh750a11_ = (TH1F*)infileh750a11.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh750a11_ = (TH1F*)infileh750a11.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh750a11_ = (TH1F*)infileh750a11.Get("InvMassFullRange");
  InvMassTauHadMu3h750a11_->Rebin(3);
  InvMassFullRangeh750a11_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh750a11_ = (TH1F*)infileh750a11.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a11_ = (TH1F*)infileh750a11.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a11_ = (TH1F*)infileh750a11.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a11_ = (TH1F*)infileh750a11.Get("Mu1Pt");
  TH1F *Mu2Pth750a11_ = (TH1F*)infileh750a11.Get("Mu2Pt");
  TH1F *DiMuPth750a11_ = (TH1F*)infileh750a11.Get("DiMuPt");
  TH1F *Mu1Etah750a11_ = (TH1F*)infileh750a11.Get("Mu1Eta");
  TH1F *Mu2Etah750a11_ = (TH1F*)infileh750a11.Get("Mu2Eta");
  TH1F *DiTauEtah750a11_ = (TH1F*)infileh750a11.Get("DiTauEta");
  TH1F *DiTauPhih750a11_ = (TH1F*)infileh750a11.Get("DiTauPhi");
  TH1F *DiMuEtah750a11_ = (TH1F*)infileh750a11.Get("DiMuEta");
  TH1F *DiMudRh750a11_ = (TH1F*)infileh750a11.Get("DiMudR");
  TH1F *DiMuPhih750a11_ = (TH1F*)infileh750a11.Get("DiMuPhi");
  TH1F *EtMETh750a11_ = (TH1F*)infileh750a11.Get("EtMET");
  TH1F *DiTauDiMuMassh750a11_ = (TH1F*)infileh750a11.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a11_ = (TH1F*)infileh750a11.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a11_ = (TH1F*)infileh750a11.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a11_ = (TH1F*)infileh750a11.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a11_ = (TH1F*)infileh750a11.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a11_ = (TH1F*)infileh750a11.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh750a11_ = (TH1F*)infileh750a11.Get("ZMassdR");

  ////////////////
  // h750a13
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a13_ = (TH1F*)infileh750a13.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a13_ = (TH1F*)infileh750a13.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a13_ = (TH1F*)infileh750a13.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh750a13_ = (TH1F*)infileh750a13.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh750a13_ = (TH1F*)infileh750a13.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh750a13_ = (TH1F*)infileh750a13.Get("InvMassFullRange");
  InvMassTauHadMu3h750a13_->Rebin(3);
  InvMassFullRangeh750a13_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh750a13_ = (TH1F*)infileh750a13.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a13_ = (TH1F*)infileh750a13.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a13_ = (TH1F*)infileh750a13.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a13_ = (TH1F*)infileh750a13.Get("Mu1Pt");
  TH1F *Mu2Pth750a13_ = (TH1F*)infileh750a13.Get("Mu2Pt");
  TH1F *DiMuPth750a13_ = (TH1F*)infileh750a13.Get("DiMuPt");
  TH1F *Mu1Etah750a13_ = (TH1F*)infileh750a13.Get("Mu1Eta");
  TH1F *Mu2Etah750a13_ = (TH1F*)infileh750a13.Get("Mu2Eta");
  TH1F *DiTauEtah750a13_ = (TH1F*)infileh750a13.Get("DiTauEta");
  TH1F *DiTauPhih750a13_ = (TH1F*)infileh750a13.Get("DiTauPhi");
  TH1F *DiMuEtah750a13_ = (TH1F*)infileh750a13.Get("DiMuEta");
  TH1F *DiMudRh750a13_ = (TH1F*)infileh750a13.Get("DiMudR");
  TH1F *DiMuPhih750a13_ = (TH1F*)infileh750a13.Get("DiMuPhi");
  TH1F *EtMETh750a13_ = (TH1F*)infileh750a13.Get("EtMET");
  TH1F *DiTauDiMuMassh750a13_ = (TH1F*)infileh750a13.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a13_ = (TH1F*)infileh750a13.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a13_ = (TH1F*)infileh750a13.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a13_ = (TH1F*)infileh750a13.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a13_ = (TH1F*)infileh750a13.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a13_ = (TH1F*)infileh750a13.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh750a13_ = (TH1F*)infileh750a13.Get("ZMassdR");

  ////////////////
  // h750a15
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a15_ = (TH1F*)infileh750a15.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a15_ = (TH1F*)infileh750a15.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a15_ = (TH1F*)infileh750a15.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh750a15_ = (TH1F*)infileh750a15.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh750a15_ = (TH1F*)infileh750a15.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh750a15_ = (TH1F*)infileh750a15.Get("InvMassFullRange");
  InvMassTauHadMu3h750a15_->Rebin(3);
  InvMassFullRangeh750a15_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh750a15_ = (TH1F*)infileh750a15.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a15_ = (TH1F*)infileh750a15.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a15_ = (TH1F*)infileh750a15.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a15_ = (TH1F*)infileh750a15.Get("Mu1Pt");
  TH1F *Mu2Pth750a15_ = (TH1F*)infileh750a15.Get("Mu2Pt");
  TH1F *DiMuPth750a15_ = (TH1F*)infileh750a15.Get("DiMuPt");
  TH1F *Mu1Etah750a15_ = (TH1F*)infileh750a15.Get("Mu1Eta");
  TH1F *Mu2Etah750a15_ = (TH1F*)infileh750a15.Get("Mu2Eta");
  TH1F *DiTauEtah750a15_ = (TH1F*)infileh750a15.Get("DiTauEta");
  TH1F *DiTauPhih750a15_ = (TH1F*)infileh750a15.Get("DiTauPhi");
  TH1F *DiMuEtah750a15_ = (TH1F*)infileh750a15.Get("DiMuEta");
  TH1F *DiMudRh750a15_ = (TH1F*)infileh750a15.Get("DiMudR");
  TH1F *DiMuPhih750a15_ = (TH1F*)infileh750a15.Get("DiMuPhi");
  TH1F *EtMETh750a15_ = (TH1F*)infileh750a15.Get("EtMET");
  TH1F *DiTauDiMuMassh750a15_ = (TH1F*)infileh750a15.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a15_ = (TH1F*)infileh750a15.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a15_ = (TH1F*)infileh750a15.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a15_ = (TH1F*)infileh750a15.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a15_ = (TH1F*)infileh750a15.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a15_ = (TH1F*)infileh750a15.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh750a15_ = (TH1F*)infileh750a15.Get("ZMassdR");

  ////////////////
  // h750a17
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a17_ = (TH1F*)infileh750a17.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a17_ = (TH1F*)infileh750a17.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a17_ = (TH1F*)infileh750a17.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh750a17_ = (TH1F*)infileh750a17.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh750a17_ = (TH1F*)infileh750a17.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh750a17_ = (TH1F*)infileh750a17.Get("InvMassFullRange");
  InvMassTauHadMu3h750a17_->Rebin(3);
  InvMassFullRangeh750a17_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh750a17_ = (TH1F*)infileh750a17.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a17_ = (TH1F*)infileh750a17.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a17_ = (TH1F*)infileh750a17.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a17_ = (TH1F*)infileh750a17.Get("Mu1Pt");
  TH1F *Mu2Pth750a17_ = (TH1F*)infileh750a17.Get("Mu2Pt");
  TH1F *DiMuPth750a17_ = (TH1F*)infileh750a17.Get("DiMuPt");
  TH1F *Mu1Etah750a17_ = (TH1F*)infileh750a17.Get("Mu1Eta");
  TH1F *Mu2Etah750a17_ = (TH1F*)infileh750a17.Get("Mu2Eta");
  TH1F *DiTauEtah750a17_ = (TH1F*)infileh750a17.Get("DiTauEta");
  TH1F *DiTauPhih750a17_ = (TH1F*)infileh750a17.Get("DiTauPhi");
  TH1F *DiMuEtah750a17_ = (TH1F*)infileh750a17.Get("DiMuEta");
  TH1F *DiMudRh750a17_ = (TH1F*)infileh750a17.Get("DiMudR");
  TH1F *DiMuPhih750a17_ = (TH1F*)infileh750a17.Get("DiMuPhi");
  TH1F *EtMETh750a17_ = (TH1F*)infileh750a17.Get("EtMET");
  TH1F *DiTauDiMuMassh750a17_ = (TH1F*)infileh750a17.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a17_ = (TH1F*)infileh750a17.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a17_ = (TH1F*)infileh750a17.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a17_ = (TH1F*)infileh750a17.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a17_ = (TH1F*)infileh750a17.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a17_ = (TH1F*)infileh750a17.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh750a17_ = (TH1F*)infileh750a17.Get("ZMassdR");

  ////////////////
  // h750a19
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a19_ = (TH1F*)infileh750a19.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a19_ = (TH1F*)infileh750a19.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a19_ = (TH1F*)infileh750a19.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh750a19_ = (TH1F*)infileh750a19.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh750a19_ = (TH1F*)infileh750a19.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh750a19_ = (TH1F*)infileh750a19.Get("InvMassFullRange");
  InvMassTauHadMu3h750a19_->Rebin(3);
  InvMassFullRangeh750a19_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh750a19_ = (TH1F*)infileh750a19.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a19_ = (TH1F*)infileh750a19.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a19_ = (TH1F*)infileh750a19.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a19_ = (TH1F*)infileh750a19.Get("Mu1Pt");
  TH1F *Mu2Pth750a19_ = (TH1F*)infileh750a19.Get("Mu2Pt");
  TH1F *DiMuPth750a19_ = (TH1F*)infileh750a19.Get("DiMuPt");
  TH1F *Mu1Etah750a19_ = (TH1F*)infileh750a19.Get("Mu1Eta");
  TH1F *Mu2Etah750a19_ = (TH1F*)infileh750a19.Get("Mu2Eta");
  TH1F *DiTauEtah750a19_ = (TH1F*)infileh750a19.Get("DiTauEta");
  TH1F *DiTauPhih750a19_ = (TH1F*)infileh750a19.Get("DiTauPhi");
  TH1F *DiMuEtah750a19_ = (TH1F*)infileh750a19.Get("DiMuEta");
  TH1F *DiMudRh750a19_ = (TH1F*)infileh750a19.Get("DiMudR");
  TH1F *DiMuPhih750a19_ = (TH1F*)infileh750a19.Get("DiMuPhi");
  TH1F *EtMETh750a19_ = (TH1F*)infileh750a19.Get("EtMET");
  TH1F *DiTauDiMuMassh750a19_ = (TH1F*)infileh750a19.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a19_ = (TH1F*)infileh750a19.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a19_ = (TH1F*)infileh750a19.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a19_ = (TH1F*)infileh750a19.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a19_ = (TH1F*)infileh750a19.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a19_ = (TH1F*)infileh750a19.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh750a19_ = (TH1F*)infileh750a19.Get("ZMassdR");

  ////////////////
  // h750a21
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a21_ = (TH1F*)infileh750a21.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a21_ = (TH1F*)infileh750a21.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a21_ = (TH1F*)infileh750a21.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh750a21_ = (TH1F*)infileh750a21.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh750a21_ = (TH1F*)infileh750a21.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh750a21_ = (TH1F*)infileh750a21.Get("InvMassFullRange");
  InvMassTauHadMu3h750a21_->Rebin(3);
  InvMassFullRangeh750a21_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh750a21_ = (TH1F*)infileh750a21.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a21_ = (TH1F*)infileh750a21.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a21_ = (TH1F*)infileh750a21.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a21_ = (TH1F*)infileh750a21.Get("Mu1Pt");
  TH1F *Mu2Pth750a21_ = (TH1F*)infileh750a21.Get("Mu2Pt");
  TH1F *DiMuPth750a21_ = (TH1F*)infileh750a21.Get("DiMuPt");
  TH1F *Mu1Etah750a21_ = (TH1F*)infileh750a21.Get("Mu1Eta");
  TH1F *Mu2Etah750a21_ = (TH1F*)infileh750a21.Get("Mu2Eta");
  TH1F *DiTauEtah750a21_ = (TH1F*)infileh750a21.Get("DiTauEta");
  TH1F *DiTauPhih750a21_ = (TH1F*)infileh750a21.Get("DiTauPhi");
  TH1F *DiMuEtah750a21_ = (TH1F*)infileh750a21.Get("DiMuEta");
  TH1F *DiMudRh750a21_ = (TH1F*)infileh750a21.Get("DiMudR");
  TH1F *DiMuPhih750a21_ = (TH1F*)infileh750a21.Get("DiMuPhi");
  TH1F *EtMETh750a21_ = (TH1F*)infileh750a21.Get("EtMET");
  TH1F *DiTauDiMuMassh750a21_ = (TH1F*)infileh750a21.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a21_ = (TH1F*)infileh750a21.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a21_ = (TH1F*)infileh750a21.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a21_ = (TH1F*)infileh750a21.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a21_ = (TH1F*)infileh750a21.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a21_ = (TH1F*)infileh750a21.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh750a21_ = (TH1F*)infileh750a21.Get("ZMassdR");

  ////////////////
  // h750a5
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a5_ = (TH1F*)infileh750a5.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a5_ = (TH1F*)infileh750a5.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a5_ = (TH1F*)infileh750a5.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh750a5_ = (TH1F*)infileh750a5.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh750a5_ = (TH1F*)infileh750a5.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh750a5_ = (TH1F*)infileh750a5.Get("InvMassFullRange");
  InvMassTauHadMu3h750a5_->Rebin(3);
  InvMassFullRangeh750a5_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh750a5_ = (TH1F*)infileh750a5.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a5_ = (TH1F*)infileh750a5.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a5_ = (TH1F*)infileh750a5.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a5_ = (TH1F*)infileh750a5.Get("Mu1Pt");
  TH1F *Mu2Pth750a5_ = (TH1F*)infileh750a5.Get("Mu2Pt");
  TH1F *DiMuPth750a5_ = (TH1F*)infileh750a5.Get("DiMuPt");
  TH1F *Mu1Etah750a5_ = (TH1F*)infileh750a5.Get("Mu1Eta");
  TH1F *Mu2Etah750a5_ = (TH1F*)infileh750a5.Get("Mu2Eta");
  TH1F *DiTauEtah750a5_ = (TH1F*)infileh750a5.Get("DiTauEta");
  TH1F *DiTauPhih750a5_ = (TH1F*)infileh750a5.Get("DiTauPhi");
  TH1F *DiMuEtah750a5_ = (TH1F*)infileh750a5.Get("DiMuEta");
  TH1F *DiMudRh750a5_ = (TH1F*)infileh750a5.Get("DiMudR");
  TH1F *DiMuPhih750a5_ = (TH1F*)infileh750a5.Get("DiMuPhi");
  TH1F *EtMETh750a5_ = (TH1F*)infileh750a5.Get("EtMET");
  TH1F *DiTauDiMuMassh750a5_ = (TH1F*)infileh750a5.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a5_ = (TH1F*)infileh750a5.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a5_ = (TH1F*)infileh750a5.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a5_ = (TH1F*)infileh750a5.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a5_ = (TH1F*)infileh750a5.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a5_ = (TH1F*)infileh750a5.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh750a5_ = (TH1F*)infileh750a5.Get("ZMassdR");

  ////////////////
  // h750a7
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a7_ = (TH1F*)infileh750a7.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a7_ = (TH1F*)infileh750a7.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a7_ = (TH1F*)infileh750a7.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh750a7_ = (TH1F*)infileh750a7.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh750a7_ = (TH1F*)infileh750a7.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh750a7_ = (TH1F*)infileh750a7.Get("InvMassFullRange");
  InvMassTauHadMu3h750a7_->Rebin(3);
  InvMassFullRangeh750a7_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh750a7_ = (TH1F*)infileh750a7.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a7_ = (TH1F*)infileh750a7.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a7_ = (TH1F*)infileh750a7.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a7_ = (TH1F*)infileh750a7.Get("Mu1Pt");
  TH1F *Mu2Pth750a7_ = (TH1F*)infileh750a7.Get("Mu2Pt");
  TH1F *DiMuPth750a7_ = (TH1F*)infileh750a7.Get("DiMuPt");
  TH1F *Mu1Etah750a7_ = (TH1F*)infileh750a7.Get("Mu1Eta");
  TH1F *Mu2Etah750a7_ = (TH1F*)infileh750a7.Get("Mu2Eta");
  TH1F *DiTauEtah750a7_ = (TH1F*)infileh750a7.Get("DiTauEta");
  TH1F *DiTauPhih750a7_ = (TH1F*)infileh750a7.Get("DiTauPhi");
  TH1F *DiMuEtah750a7_ = (TH1F*)infileh750a7.Get("DiMuEta");
  TH1F *DiMudRh750a7_ = (TH1F*)infileh750a7.Get("DiMudR");
  TH1F *DiMuPhih750a7_ = (TH1F*)infileh750a7.Get("DiMuPhi");
  TH1F *EtMETh750a7_ = (TH1F*)infileh750a7.Get("EtMET");
  TH1F *DiTauDiMuMassh750a7_ = (TH1F*)infileh750a7.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a7_ = (TH1F*)infileh750a7.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a7_ = (TH1F*)infileh750a7.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a7_ = (TH1F*)infileh750a7.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a7_ = (TH1F*)infileh750a7.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a7_ = (TH1F*)infileh750a7.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh750a7_ = (TH1F*)infileh750a7.Get("ZMassdR");

  ////////////////
  // h750a9
  ////////////////
  TH1F *NMedIsoTausWithMu3h750a9_ = (TH1F*)infileh750a9.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3h750a9_ = (TH1F*)infileh750a9.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3h750a9_ = (TH1F*)infileh750a9.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuh750a9_ = (TH1F*)infileh750a9.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuh750a9_ = (TH1F*)infileh750a9.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeh750a9_ = (TH1F*)infileh750a9.Get("InvMassFullRange");
  InvMassTauHadMu3h750a9_->Rebin(3);
  InvMassFullRangeh750a9_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrh750a9_ = (TH1F*)infileh750a9.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndch750a9_ = (TH1F*)infileh750a9.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndch750a9_ = (TH1F*)infileh750a9.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1Pth750a9_ = (TH1F*)infileh750a9.Get("Mu1Pt");
  TH1F *Mu2Pth750a9_ = (TH1F*)infileh750a9.Get("Mu2Pt");
  TH1F *DiMuPth750a9_ = (TH1F*)infileh750a9.Get("DiMuPt");
  TH1F *Mu1Etah750a9_ = (TH1F*)infileh750a9.Get("Mu1Eta");
  TH1F *Mu2Etah750a9_ = (TH1F*)infileh750a9.Get("Mu2Eta");
  TH1F *DiTauEtah750a9_ = (TH1F*)infileh750a9.Get("DiTauEta");
  TH1F *DiTauPhih750a9_ = (TH1F*)infileh750a9.Get("DiTauPhi");
  TH1F *DiMuEtah750a9_ = (TH1F*)infileh750a9.Get("DiMuEta");
  TH1F *DiMudRh750a9_ = (TH1F*)infileh750a9.Get("DiMudR");
  TH1F *DiMuPhih750a9_ = (TH1F*)infileh750a9.Get("DiMuPhi");
  TH1F *EtMETh750a9_ = (TH1F*)infileh750a9.Get("EtMET");
  TH1F *DiTauDiMuMassh750a9_ = (TH1F*)infileh750a9.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhih750a9_ = (TH1F*)infileh750a9.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhih750a9_ = (TH1F*)infileh750a9.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhih750a9_ = (TH1F*)infileh750a9.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRh750a9_ = (TH1F*)infileh750a9.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRh750a9_ = (TH1F*)infileh750a9.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRh750a9_ = (TH1F*)infileh750a9.Get("ZMassdR");


  ////////////////
  ////////////////

//  ////////////////
//  // TTDiLep
//  ////////////////
//  TH1F *NMedIsoTausWithMu3TTDiLep_ = (TH1F*)infileTTDiLep.Get("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3TTDiLep_ = (TH1F*)infileTTDiLep.Get("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3TTDiLep_ = (TH1F*)infileTTDiLep.Get("PtTauHadMu3");
//  TH1F *InvMassMu1TauMuTTDiLep_ = (TH1F*)infileTTDiLep.Get("InvMassMu1TauMu");
//  TH1F *InvMassMu2TauMuTTDiLep_ = (TH1F*)infileTTDiLep.Get("InvMassMu2TauMu");
//  TH1F *InvMassFullRangeTTDiLep_ = (TH1F*)infileTTDiLep.Get("InvMassFullRange");
//  InvMassFullRangeTTDiLep_->Rebin(3);
//  InvMassFullRangeTTDiLep_->Rebin(5);
//  TH1F *InvMassDiMuBarrBarrTTDiLep_ = (TH1F*)infileTTDiLep.Get("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcTTDiLep_ = (TH1F*)infileTTDiLep.Get("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcTTDiLep_ = (TH1F*)infileTTDiLep.Get("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtTTDiLep_ = (TH1F*)infileTTDiLep.Get("Mu1Pt");
//  TH1F *Mu2PtTTDiLep_ = (TH1F*)infileTTDiLep.Get("Mu2Pt");
//  TH1F *DiMuPtTTDiLep_ = (TH1F*)infileTTDiLep.Get("DiMuPt");
//  TH1F *Mu1EtaTTDiLep_ = (TH1F*)infileTTDiLep.Get("Mu1Eta");
//  TH1F *Mu2EtaTTDiLep_ = (TH1F*)infileTTDiLep.Get("Mu2Eta");
//  TH1F *DiTauEtaTTDiLep_ = (TH1F*)infileTTDiLep.Get("DiTauEta");
//  TH1F *DiTauPhiTTDiLep_ = (TH1F*)infileTTDiLep.Get("DiTauPhi");
//  TH1F *DiMuEtaTTDiLep_ = (TH1F*)infileTTDiLep.Get("DiMuEta");
//  TH1F *DiMudRTTDiLep_ = (TH1F*)infileTTDiLep.Get("DiMudR");
//  TH1F *DiMuPhiTTDiLep_ = (TH1F*)infileTTDiLep.Get("DiMuPhi");
//  TH1F *EtMETTTDiLep_ = (TH1F*)infileTTDiLep.Get("EtMET");
//  TH1F *DiTauDiMuMassTTDiLep_ = (TH1F*)infileTTDiLep.Get("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiTTDiLep_ = (TH1F*)infileTTDiLep.Get("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiTTDiLep_ = (TH1F*)infileTTDiLep.Get("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiTTDiLep_ = (TH1F*)infileTTDiLep.Get("METDiMuDeltaPhi");
//  TH1F *DiTaudRTTDiLep_ = (TH1F*)infileTTDiLep.Get("DiTaudR");
//  TH1F *DiTauMassSmallerdRTTDiLep_ = (TH1F*)infileTTDiLep.Get("DiTauMassSmallerdR");
//  TH1F *ZMassdRTTDiLep_ = (TH1F*)infileTTDiLep.Get("ZMassdR");
//
//  ////////////////
//  // TTBarSingLep
//  ////////////////
//  TH1F *NMedIsoTausWithMu3TTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3TTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3TTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("PtTauHadMu3");
//  TH1F *InvMassMu1TauMuTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("InvMassMu1TauMu");
//  TH1F *InvMassMu2TauMuTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("InvMassMu2TauMu");
//  TH1F *InvMassFullRangeTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("InvMassFullRange");
//  InvMassFullRangeTTBarSingLep_->Rebin(3);
//  InvMassFullRangeTTBarSingLep_->Rebin(5);
//  TH1F *InvMassDiMuBarrBarrTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("Mu1Pt");
//  TH1F *Mu2PtTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("Mu2Pt");
//  TH1F *DiMuPtTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("DiMuPt");
//  TH1F *Mu1EtaTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("Mu1Eta");
//  TH1F *Mu2EtaTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("Mu2Eta");
//  TH1F *DiTauEtaTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("DiTauEta");
//  TH1F *DiTauPhiTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("DiTauPhi");
//  TH1F *DiMuEtaTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("DiMuEta");
//  TH1F *DiMudRTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("DiMudR");
//  TH1F *DiMuPhiTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("DiMuPhi");
//  TH1F *EtMETTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("EtMET");
//  TH1F *DiTauDiMuMassTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("METDiMuDeltaPhi");
//  TH1F *DiTaudRTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("DiTaudR");
//  TH1F *DiTauMassSmallerdRTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("DiTauMassSmallerdR");
//  TH1F *ZMassdRTTBarSingLep_ = (TH1F*)infileTTBarSingLep.Get("ZMassdR");
//
//  ////////////////
//  // TTSingLep
//  ////////////////
//  TH1F *NMedIsoTausWithMu3TTSingLep_ = (TH1F*)infileTTSingLep.Get("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3TTSingLep_ = (TH1F*)infileTTSingLep.Get("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3TTSingLep_ = (TH1F*)infileTTSingLep.Get("PtTauHadMu3");
//  TH1F *InvMassMu1TauMuTTSingLep_ = (TH1F*)infileTTSingLep.Get("InvMassMu1TauMu");
//  TH1F *InvMassMu2TauMuTTSingLep_ = (TH1F*)infileTTSingLep.Get("InvMassMu2TauMu");
//  TH1F *InvMassFullRangeTTSingLep_ = (TH1F*)infileTTSingLep.Get("InvMassFullRange");
//  InvMassFullRangeTTSingLep_->Rebin(3);
//  InvMassFullRangeTTSingLep_->Rebin(5);
//  TH1F *InvMassDiMuBarrBarrTTSingLep_ = (TH1F*)infileTTSingLep.Get("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcTTSingLep_ = (TH1F*)infileTTSingLep.Get("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcTTSingLep_ = (TH1F*)infileTTSingLep.Get("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtTTSingLep_ = (TH1F*)infileTTSingLep.Get("Mu1Pt");
//  TH1F *Mu2PtTTSingLep_ = (TH1F*)infileTTSingLep.Get("Mu2Pt");
//  TH1F *DiMuPtTTSingLep_ = (TH1F*)infileTTSingLep.Get("DiMuPt");
//  TH1F *Mu1EtaTTSingLep_ = (TH1F*)infileTTSingLep.Get("Mu1Eta");
//  TH1F *Mu2EtaTTSingLep_ = (TH1F*)infileTTSingLep.Get("Mu2Eta");
//  TH1F *DiTauEtaTTSingLep_ = (TH1F*)infileTTSingLep.Get("DiTauEta");
//  TH1F *DiTauPhiTTSingLep_ = (TH1F*)infileTTSingLep.Get("DiTauPhi");
//  TH1F *DiMuEtaTTSingLep_ = (TH1F*)infileTTSingLep.Get("DiMuEta");
//  TH1F *DiMudRTTSingLep_ = (TH1F*)infileTTSingLep.Get("DiMudR");
//  TH1F *DiMuPhiTTSingLep_ = (TH1F*)infileTTSingLep.Get("DiMuPhi");
//  TH1F *EtMETTTSingLep_ = (TH1F*)infileTTSingLep.Get("EtMET");
//  TH1F *DiTauDiMuMassTTSingLep_ = (TH1F*)infileTTSingLep.Get("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiTTSingLep_ = (TH1F*)infileTTSingLep.Get("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiTTSingLep_ = (TH1F*)infileTTSingLep.Get("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiTTSingLep_ = (TH1F*)infileTTSingLep.Get("METDiMuDeltaPhi");
//  TH1F *DiTaudRTTSingLep_ = (TH1F*)infileTTSingLep.Get("DiTaudR");
//  TH1F *DiTauMassSmallerdRTTSingLep_ = (TH1F*)infileTTSingLep.Get("DiTauMassSmallerdR");
//  TH1F *ZMassdRTTSingLep_ = (TH1F*)infileTTSingLep.Get("ZMassdR");
//
//  ////////////////
//  // TTJetsMad
//  ////////////////
//  TH1F *NMedIsoTausWithMu3TTJetsMad_ = (TH1F*)infileTTJetsMad.Get("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3TTJetsMad_ = (TH1F*)infileTTJetsMad.Get("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3TTJetsMad_ = (TH1F*)infileTTJetsMad.Get("PtTauHadMu3");
//  TH1F *InvMassMu1TauMuTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("InvMassMu1TauMu");
//  TH1F *InvMassMu2TauMuTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("InvMassMu2TauMu");
//  TH1F *InvMassFullRangeTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("InvMassFullRange");
//  InvMassFullRangeTTJetsMad_->Rebin(3);
//  InvMassFullRangeTTJetsMad_->Rebin(5);
//  TH1F *InvMassDiMuBarrBarrTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("Mu1Pt");
//  TH1F *Mu2PtTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("Mu2Pt");
//  TH1F *DiMuPtTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("DiMuPt");
//  TH1F *Mu1EtaTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("Mu1Eta");
//  TH1F *Mu2EtaTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("Mu2Eta");
//  TH1F *DiTauEtaTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("DiTauEta");
//  TH1F *DiTauPhiTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("DiTauPhi");
//  TH1F *DiMuEtaTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("DiMuEta");
//  TH1F *DiMudRTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("DiMudR");
//  TH1F *DiMuPhiTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("DiMuPhi");
//  TH1F *EtMETTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("EtMET");
//  TH1F *DiTauDiMuMassTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("METDiMuDeltaPhi");
//  TH1F *DiTaudRTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("DiTaudR");
//  TH1F *DiTauMassSmallerdRTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("DiTauMassSmallerdR");
//  TH1F *ZMassdRTTJetsMad_ = (TH1F*)infileTTJetsMad.Get("ZMassdR");
//
//  ////////////////
//  // TTJetsAmac
//  ////////////////
//  TH1F *NMedIsoTausWithMu3TTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3TTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3TTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("PtTauHadMu3");
//  TH1F *InvMassMu1TauMuTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("InvMassMu1TauMu");
//  TH1F *InvMassMu2TauMuTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("InvMassMu2TauMu");
//  TH1F *InvMassFullRangeTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("InvMassFullRange");
//  InvMassFullRangeTTJetsAmac_->Rebin(3);
//  InvMassFullRangeTTJetsAmac_->Rebin(5);
//  TH1F *InvMassDiMuBarrBarrTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("Mu1Pt");
//  TH1F *Mu2PtTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("Mu2Pt");
//  TH1F *DiMuPtTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("DiMuPt");
//  TH1F *Mu1EtaTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("Mu1Eta");
//  TH1F *Mu2EtaTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("Mu2Eta");
//  TH1F *DiTauEtaTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("DiTauEta");
//  TH1F *DiTauPhiTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("DiTauPhi");
//  TH1F *DiMuEtaTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("DiMuEta");
//  TH1F *DiMudRTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("DiMudR");
//  TH1F *DiMuPhiTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("DiMuPhi");
//  TH1F *EtMETTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("EtMET");
//  TH1F *DiTauDiMuMassTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("METDiMuDeltaPhi");
//  TH1F *DiTaudRTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("DiTaudR");
//  TH1F *DiTauMassSmallerdRTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("DiTauMassSmallerdR");
//  TH1F *ZMassdRTTJetsAmac_ = (TH1F*)infileTTJetsAmac.Get("ZMassdR");
//
  ////////////////
  // ST_sch
  ////////////////
  TH1F *NMedIsoTausWithMu3ST_sch_ = (TH1F*)infileST_sch.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3ST_sch_ = (TH1F*)infileST_sch.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3ST_sch_ = (TH1F*)infileST_sch.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuST_sch_ = (TH1F*)infileST_sch.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuST_sch_ = (TH1F*)infileST_sch.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeST_sch_ = (TH1F*)infileST_sch.Get("InvMassFullRange");
  InvMassTauHadMu3ST_sch_->Rebin(3);
  InvMassFullRangeST_sch_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrST_sch_ = (TH1F*)infileST_sch.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcST_sch_ = (TH1F*)infileST_sch.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcST_sch_ = (TH1F*)infileST_sch.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtST_sch_ = (TH1F*)infileST_sch.Get("Mu1Pt");
  TH1F *Mu2PtST_sch_ = (TH1F*)infileST_sch.Get("Mu2Pt");
  TH1F *DiMuPtST_sch_ = (TH1F*)infileST_sch.Get("DiMuPt");
  TH1F *Mu1EtaST_sch_ = (TH1F*)infileST_sch.Get("Mu1Eta");
  TH1F *Mu2EtaST_sch_ = (TH1F*)infileST_sch.Get("Mu2Eta");
  TH1F *DiTauEtaST_sch_ = (TH1F*)infileST_sch.Get("DiTauEta");
  TH1F *DiTauPhiST_sch_ = (TH1F*)infileST_sch.Get("DiTauPhi");
  TH1F *DiMuEtaST_sch_ = (TH1F*)infileST_sch.Get("DiMuEta");
  TH1F *DiMudRST_sch_ = (TH1F*)infileST_sch.Get("DiMudR");
  TH1F *DiMuPhiST_sch_ = (TH1F*)infileST_sch.Get("DiMuPhi");
  TH1F *EtMETST_sch_ = (TH1F*)infileST_sch.Get("EtMET");
  TH1F *DiTauDiMuMassST_sch_ = (TH1F*)infileST_sch.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiST_sch_ = (TH1F*)infileST_sch.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiST_sch_ = (TH1F*)infileST_sch.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiST_sch_ = (TH1F*)infileST_sch.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRST_sch_ = (TH1F*)infileST_sch.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRST_sch_ = (TH1F*)infileST_sch.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRST_sch_ = (TH1F*)infileST_sch.Get("ZMassdR");

  ////////////////
//  // ST_tWNoHad_antitop
  ////////////////
//  TH1F *NMedIsoTausWithMu3ST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3ST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3ST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("PtTauHadMu3");
//  TH1F *InvMassMu1TauMuST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("InvMassMu1TauMu");
//  TH1F *InvMassMu2TauMuST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("InvMassMu2TauMu");
//  TH1F *InvMassFullRangeST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("InvMassFullRange");
//  InvMassFullRangeST_tWNoHad_antitop_->Rebin(3);
//  InvMassFullRangeST_tWNoHad_antitop_->Rebin(5);
//  TH1F *InvMassDiMuBarrBarrST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("Mu1Pt");
//  TH1F *Mu2PtST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("Mu2Pt");
//  TH1F *DiMuPtST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("DiMuPt");
//  TH1F *Mu1EtaST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("Mu1Eta");
//  TH1F *Mu2EtaST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("Mu2Eta");
//  TH1F *DiTauEtaST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("DiTauEta");
//  TH1F *DiTauPhiST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("DiTauPhi");
//  TH1F *DiMuEtaST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("DiMuEta");
//  TH1F *DiMudRST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("DiMudR");
//  TH1F *DiMuPhiST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("DiMuPhi");
//  TH1F *EtMETST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("EtMET");
//  TH1F *DiTauDiMuMassST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("METDiMuDeltaPhi");
//  TH1F *DiTaudRST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("DiTaudR");
//  TH1F *DiTauMassSmallerdRST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("DiTauMassSmallerdR");
//  TH1F *ZMassdRST_tWNoHad_antitop_ = (TH1F*)infileST_tWNoHad_antitop.Get("ZMassdR");

  ////////////////
//  // ST_tWNoHad_top
  ////////////////
//  TH1F *NMedIsoTausWithMu3ST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3ST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3ST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("PtTauHadMu3");
//  TH1F *InvMassMu1TauMuST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("InvMassMu1TauMu");
//  TH1F *InvMassMu2TauMuST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("InvMassMu2TauMu");
//  TH1F *InvMassFullRangeST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("InvMassFullRange");
//  InvMassFullRangeST_tWNoHad_top_->Rebin(3);
//  InvMassFullRangeST_tWNoHad_top_->Rebin(5);
//  TH1F *InvMassDiMuBarrBarrST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("Mu1Pt");
//  TH1F *Mu2PtST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("Mu2Pt");
//  TH1F *DiMuPtST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DiMuPt");
//  TH1F *Mu1EtaST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("Mu1Eta");
//  TH1F *Mu2EtaST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("Mu2Eta");
//  TH1F *DiTauEtaST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DiTauEta");
//  TH1F *DiTauPhiST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DiTauPhi");
//  TH1F *DiMuEtaST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DiMuEta");
//  TH1F *DiMudRST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DiMudR");
//  TH1F *DiMuPhiST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DiMuPhi");
//  TH1F *EtMETST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("EtMET");
//  TH1F *DiTauDiMuMassST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("METDiMuDeltaPhi");
//  TH1F *DiTaudRST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DiTaudR");
//  TH1F *DiTauMassSmallerdRST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("DiTauMassSmallerdR");
//  TH1F *ZMassdRST_tWNoHad_top_ = (TH1F*)infileST_tWNoHad_top.Get("ZMassdR");

  ////////////////
  // ST_tWIncl_top
  ////////////////
  TH1F *NMedIsoTausWithMu3ST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3ST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3ST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("InvMassFullRange");
  InvMassTauHadMu3ST_tWIncl_top_->Rebin(3);
  InvMassFullRangeST_tWIncl_top_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("Mu1Pt");
  TH1F *Mu2PtST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("Mu2Pt");
  TH1F *DiMuPtST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DiMuPt");
  TH1F *Mu1EtaST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("Mu1Eta");
  TH1F *Mu2EtaST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("Mu2Eta");
  TH1F *DiTauEtaST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DiTauEta");
  TH1F *DiTauPhiST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DiTauPhi");
  TH1F *DiMuEtaST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DiMuEta");
  TH1F *DiMudRST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DiMudR");
  TH1F *DiMuPhiST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DiMuPhi");
  TH1F *EtMETST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("EtMET");
  TH1F *DiTauDiMuMassST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRST_tWIncl_top_ = (TH1F*)infileST_tWIncl_top.Get("ZMassdR");

  ////////////////
  // ST_tWIncl_antitop
  ////////////////
  TH1F *NMedIsoTausWithMu3ST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3ST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3ST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("InvMassFullRange");
  InvMassTauHadMu3ST_tWIncl_antitop_->Rebin(3);
  InvMassFullRangeST_tWIncl_antitop_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("Mu1Pt");
  TH1F *Mu2PtST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("Mu2Pt");
  TH1F *DiMuPtST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DiMuPt");
  TH1F *Mu1EtaST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("Mu1Eta");
  TH1F *Mu2EtaST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("Mu2Eta");
  TH1F *DiTauEtaST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DiTauEta");
  TH1F *DiTauPhiST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DiTauPhi");
  TH1F *DiMuEtaST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DiMuEta");
  TH1F *DiMudRST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DiMudR");
  TH1F *DiMuPhiST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DiMuPhi");
  TH1F *EtMETST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("EtMET");
  TH1F *DiTauDiMuMassST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRST_tWIncl_antitop_ = (TH1F*)infileST_tWIncl_antitop.Get("ZMassdR");

  ////////////////
  // ST_tch_antitop
  ////////////////
  TH1F *NMedIsoTausWithMu3ST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3ST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3ST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("InvMassFullRange");
  InvMassTauHadMu3ST_tch_antitop_->Rebin(3);
  InvMassFullRangeST_tch_antitop_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("Mu1Pt");
  TH1F *Mu2PtST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("Mu2Pt");
  TH1F *DiMuPtST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DiMuPt");
  TH1F *Mu1EtaST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("Mu1Eta");
  TH1F *Mu2EtaST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("Mu2Eta");
  TH1F *DiTauEtaST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DiTauEta");
  TH1F *DiTauPhiST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DiTauPhi");
  TH1F *DiMuEtaST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DiMuEta");
  TH1F *DiMudRST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DiMudR");
  TH1F *DiMuPhiST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DiMuPhi");
  TH1F *EtMETST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("EtMET");
  TH1F *DiTauDiMuMassST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRST_tch_antitop_ = (TH1F*)infileST_tch_antitop.Get("ZMassdR");

  ////////////////
  // ST_tch_top
  ////////////////
  TH1F *NMedIsoTausWithMu3ST_tch_top_ = (TH1F*)infileST_tch_top.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3ST_tch_top_ = (TH1F*)infileST_tch_top.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3ST_tch_top_ = (TH1F*)infileST_tch_top.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuST_tch_top_ = (TH1F*)infileST_tch_top.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuST_tch_top_ = (TH1F*)infileST_tch_top.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeST_tch_top_ = (TH1F*)infileST_tch_top.Get("InvMassFullRange");
  InvMassTauHadMu3ST_tch_top_->Rebin(3);
  InvMassFullRangeST_tch_top_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrST_tch_top_ = (TH1F*)infileST_tch_top.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcST_tch_top_ = (TH1F*)infileST_tch_top.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcST_tch_top_ = (TH1F*)infileST_tch_top.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtST_tch_top_ = (TH1F*)infileST_tch_top.Get("Mu1Pt");
  TH1F *Mu2PtST_tch_top_ = (TH1F*)infileST_tch_top.Get("Mu2Pt");
  TH1F *DiMuPtST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiMuPt");
  TH1F *Mu1EtaST_tch_top_ = (TH1F*)infileST_tch_top.Get("Mu1Eta");
  TH1F *Mu2EtaST_tch_top_ = (TH1F*)infileST_tch_top.Get("Mu2Eta");
  TH1F *DiTauEtaST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiTauEta");
  TH1F *DiTauPhiST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiTauPhi");
  TH1F *DiMuEtaST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiMuEta");
  TH1F *DiMudRST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiMudR");
  TH1F *DiMuPhiST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiMuPhi");
  TH1F *EtMETST_tch_top_ = (TH1F*)infileST_tch_top.Get("EtMET");
  TH1F *DiTauDiMuMassST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiST_tch_top_ = (TH1F*)infileST_tch_top.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiST_tch_top_ = (TH1F*)infileST_tch_top.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRST_tch_top_ = (TH1F*)infileST_tch_top.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRST_tch_top_ = (TH1F*)infileST_tch_top.Get("ZMassdR");

  ////////////////
  // Up
  ////////////////
  TH1F *NMedIsoTausWithMu3Up_ = (TH1F*)infileUp.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3Up_ = (TH1F*)infileUp.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3Up_ = (TH1F*)infileUp.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuUp_ = (TH1F*)infileUp.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuUp_ = (TH1F*)infileUp.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeUp_ = (TH1F*)infileUp.Get("InvMassFullRange");
  InvMassTauHadMu3Up_->Rebin(3);
  InvMassFullRangeUp_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrUp_ = (TH1F*)infileUp.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcUp_ = (TH1F*)infileUp.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcUp_ = (TH1F*)infileUp.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtUp_ = (TH1F*)infileUp.Get("Mu1Pt");
  TH1F *Mu2PtUp_ = (TH1F*)infileUp.Get("Mu2Pt");
  TH1F *DiMuPtUp_ = (TH1F*)infileUp.Get("DiMuPt");
  TH1F *Mu1EtaUp_ = (TH1F*)infileUp.Get("Mu1Eta");
  TH1F *Mu2EtaUp_ = (TH1F*)infileUp.Get("Mu2Eta");
  TH1F *DiTauEtaUp_ = (TH1F*)infileUp.Get("DiTauEta");
  TH1F *DiTauPhiUp_ = (TH1F*)infileUp.Get("DiTauPhi");
  TH1F *DiMuEtaUp_ = (TH1F*)infileUp.Get("DiMuEta");
  TH1F *DiMudRUp_ = (TH1F*)infileUp.Get("DiMudR");
  TH1F *DiMuPhiUp_ = (TH1F*)infileUp.Get("DiMuPhi");
  TH1F *EtMETUp_ = (TH1F*)infileUp.Get("EtMET");
  TH1F *DiTauDiMuMassUp_ = (TH1F*)infileUp.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiUp_ = (TH1F*)infileUp.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiUp_ = (TH1F*)infileUp.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiUp_ = (TH1F*)infileUp.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRUp_ = (TH1F*)infileUp.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRUp_ = (TH1F*)infileUp.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRUp_ = (TH1F*)infileUp.Get("ZMassdR");

//  ////////////////
//  // VV
  ////////////////
//  TH1F *NMedIsoTausWithMu3VV_ = (TH1F*)infileVV.Get("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3VV_ = (TH1F*)infileVV.Get("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3VV_ = (TH1F*)infileVV.Get("PtTauHadMu3");
//  TH1F *InvMassMu1TauMuVV_ = (TH1F*)infileVV.Get("InvMassMu1TauMu");
//  TH1F *InvMassMu2TauMuVV_ = (TH1F*)infileVV.Get("InvMassMu2TauMu");
//  TH1F *InvMassFullRangeVV_ = (TH1F*)infileVV.Get("InvMassFullRange");
//  InvMassFullRangeVV_->Rebin(3);
//  InvMassFullRangeVV_->Rebin(5);
//  TH1F *InvMassDiMuBarrBarrVV_ = (TH1F*)infileVV.Get("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcVV_ = (TH1F*)infileVV.Get("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcVV_ = (TH1F*)infileVV.Get("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtVV_ = (TH1F*)infileVV.Get("Mu1Pt");
//  TH1F *Mu2PtVV_ = (TH1F*)infileVV.Get("Mu2Pt");
//  TH1F *DiMuPtVV_ = (TH1F*)infileVV.Get("DiMuPt");
//  TH1F *Mu1EtaVV_ = (TH1F*)infileVV.Get("Mu1Eta");
//  TH1F *Mu2EtaVV_ = (TH1F*)infileVV.Get("Mu2Eta");
//  TH1F *DiTauEtaVV_ = (TH1F*)infileVV.Get("DiTauEta");
//  TH1F *DiTauPhiVV_ = (TH1F*)infileVV.Get("DiTauPhi");
//  TH1F *DiMuEtaVV_ = (TH1F*)infileVV.Get("DiMuEta");
//  TH1F *DiMudRVV_ = (TH1F*)infileVV.Get("DiMudR");
//  TH1F *DiMuPhiVV_ = (TH1F*)infileVV.Get("DiMuPhi");
//  TH1F *EtMETVV_ = (TH1F*)infileVV.Get("EtMET");
//  TH1F *DiTauDiMuMassVV_ = (TH1F*)infileVV.Get("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiVV_ = (TH1F*)infileVV.Get("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiVV_ = (TH1F*)infileVV.Get("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiVV_ = (TH1F*)infileVV.Get("METDiMuDeltaPhi");
//  TH1F *DiTaudRVV_ = (TH1F*)infileVV.Get("DiTaudR");
//  TH1F *DiTauMassSmallerdRVV_ = (TH1F*)infileVV.Get("DiTauMassSmallerdR");
//  TH1F *ZMassdRVV_ = (TH1F*)infileVV.Get("ZMassdR");

  ////////////////
  // WJAmac
  ////////////////
  TH1F *NMedIsoTausWithMu3WJAmac_ = (TH1F*)infileWJAmac.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3WJAmac_ = (TH1F*)infileWJAmac.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3WJAmac_ = (TH1F*)infileWJAmac.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuWJAmac_ = (TH1F*)infileWJAmac.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuWJAmac_ = (TH1F*)infileWJAmac.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeWJAmac_ = (TH1F*)infileWJAmac.Get("InvMassFullRange");
  InvMassTauHadMu3WJAmac_->Rebin(3);
  InvMassFullRangeWJAmac_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrWJAmac_ = (TH1F*)infileWJAmac.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcWJAmac_ = (TH1F*)infileWJAmac.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcWJAmac_ = (TH1F*)infileWJAmac.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtWJAmac_ = (TH1F*)infileWJAmac.Get("Mu1Pt");
  TH1F *Mu2PtWJAmac_ = (TH1F*)infileWJAmac.Get("Mu2Pt");
  TH1F *DiMuPtWJAmac_ = (TH1F*)infileWJAmac.Get("DiMuPt");
  TH1F *Mu1EtaWJAmac_ = (TH1F*)infileWJAmac.Get("Mu1Eta");
  TH1F *Mu2EtaWJAmac_ = (TH1F*)infileWJAmac.Get("Mu2Eta");
  TH1F *DiTauEtaWJAmac_ = (TH1F*)infileWJAmac.Get("DiTauEta");
  TH1F *DiTauPhiWJAmac_ = (TH1F*)infileWJAmac.Get("DiTauPhi");
  TH1F *DiMuEtaWJAmac_ = (TH1F*)infileWJAmac.Get("DiMuEta");
  TH1F *DiMudRWJAmac_ = (TH1F*)infileWJAmac.Get("DiMudR");
  TH1F *DiMuPhiWJAmac_ = (TH1F*)infileWJAmac.Get("DiMuPhi");
  TH1F *EtMETWJAmac_ = (TH1F*)infileWJAmac.Get("EtMET");
  TH1F *DiTauDiMuMassWJAmac_ = (TH1F*)infileWJAmac.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiWJAmac_ = (TH1F*)infileWJAmac.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiWJAmac_ = (TH1F*)infileWJAmac.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiWJAmac_ = (TH1F*)infileWJAmac.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRWJAmac_ = (TH1F*)infileWJAmac.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRWJAmac_ = (TH1F*)infileWJAmac.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRWJAmac_ = (TH1F*)infileWJAmac.Get("ZMassdR");

  ////////////////
//  // WJMad
//  ////////////////
//  TH1F *NMedIsoTausWithMu3WJMad_ = (TH1F*)infileWJMad.Get("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3WJMad_ = (TH1F*)infileWJMad.Get("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3WJMad_ = (TH1F*)infileWJMad.Get("PtTauHadMu3");
//  TH1F *InvMassMu1TauMuWJMad_ = (TH1F*)infileWJMad.Get("InvMassMu1TauMu");
//  TH1F *InvMassMu2TauMuWJMad_ = (TH1F*)infileWJMad.Get("InvMassMu2TauMu");
//  TH1F *InvMassFullRangeWJMad_ = (TH1F*)infileWJMad.Get("InvMassFullRange");
//  InvMassFullRangeWJMad_->Rebin(3);
//  InvMassFullRangeWJMad_->Rebin(5);
//  TH1F *InvMassDiMuBarrBarrWJMad_ = (TH1F*)infileWJMad.Get("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcWJMad_ = (TH1F*)infileWJMad.Get("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcWJMad_ = (TH1F*)infileWJMad.Get("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtWJMad_ = (TH1F*)infileWJMad.Get("Mu1Pt");
//  TH1F *Mu2PtWJMad_ = (TH1F*)infileWJMad.Get("Mu2Pt");
//  TH1F *DiMuPtWJMad_ = (TH1F*)infileWJMad.Get("DiMuPt");
//  TH1F *Mu1EtaWJMad_ = (TH1F*)infileWJMad.Get("Mu1Eta");
//  TH1F *Mu2EtaWJMad_ = (TH1F*)infileWJMad.Get("Mu2Eta");
//  TH1F *DiTauEtaWJMad_ = (TH1F*)infileWJMad.Get("DiTauEta");
//  TH1F *DiTauPhiWJMad_ = (TH1F*)infileWJMad.Get("DiTauPhi");
//  TH1F *DiMuEtaWJMad_ = (TH1F*)infileWJMad.Get("DiMuEta");
//  TH1F *DiMudRWJMad_ = (TH1F*)infileWJMad.Get("DiMudR");
//  TH1F *DiMuPhiWJMad_ = (TH1F*)infileWJMad.Get("DiMuPhi");
//  TH1F *EtMETWJMad_ = (TH1F*)infileWJMad.Get("EtMET");
//  TH1F *DiTauDiMuMassWJMad_ = (TH1F*)infileWJMad.Get("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiWJMad_ = (TH1F*)infileWJMad.Get("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiWJMad_ = (TH1F*)infileWJMad.Get("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiWJMad_ = (TH1F*)infileWJMad.Get("METDiMuDeltaPhi");
//  TH1F *DiTaudRWJMad_ = (TH1F*)infileWJMad.Get("DiTaudR");
//  TH1F *DiTauMassSmallerdRWJMad_ = (TH1F*)infileWJMad.Get("DiTauMassSmallerdR");
//  TH1F *ZMassdRWJMad_ = (TH1F*)infileWJMad.Get("ZMassdR");
//
  ////////////////
  // WZ
  ////////////////
  TH1F *NMedIsoTausWithMu3WZ_ = (TH1F*)infileWZ.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3WZ_ = (TH1F*)infileWZ.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3WZ_ = (TH1F*)infileWZ.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuWZ_ = (TH1F*)infileWZ.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuWZ_ = (TH1F*)infileWZ.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeWZ_ = (TH1F*)infileWZ.Get("InvMassFullRange");
  InvMassTauHadMu3WZ_->Rebin(3);
  InvMassFullRangeWZ_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrWZ_ = (TH1F*)infileWZ.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcWZ_ = (TH1F*)infileWZ.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcWZ_ = (TH1F*)infileWZ.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtWZ_ = (TH1F*)infileWZ.Get("Mu1Pt");
  TH1F *Mu2PtWZ_ = (TH1F*)infileWZ.Get("Mu2Pt");
  TH1F *DiMuPtWZ_ = (TH1F*)infileWZ.Get("DiMuPt");
  TH1F *Mu1EtaWZ_ = (TH1F*)infileWZ.Get("Mu1Eta");
  TH1F *Mu2EtaWZ_ = (TH1F*)infileWZ.Get("Mu2Eta");
  TH1F *DiTauEtaWZ_ = (TH1F*)infileWZ.Get("DiTauEta");
  TH1F *DiTauPhiWZ_ = (TH1F*)infileWZ.Get("DiTauPhi");
  TH1F *DiMuEtaWZ_ = (TH1F*)infileWZ.Get("DiMuEta");
  TH1F *DiMudRWZ_ = (TH1F*)infileWZ.Get("DiMudR");
  TH1F *DiMuPhiWZ_ = (TH1F*)infileWZ.Get("DiMuPhi");
  TH1F *EtMETWZ_ = (TH1F*)infileWZ.Get("EtMET");
  TH1F *DiTauDiMuMassWZ_ = (TH1F*)infileWZ.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiWZ_ = (TH1F*)infileWZ.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiWZ_ = (TH1F*)infileWZ.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiWZ_ = (TH1F*)infileWZ.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRWZ_ = (TH1F*)infileWZ.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRWZ_ = (TH1F*)infileWZ.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRWZ_ = (TH1F*)infileWZ.Get("ZMassdR");

  ////////////////
  // ZZ2L2Nu
  ////////////////
  TH1F *NMedIsoTausWithMu3ZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3ZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3ZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("InvMassFullRange");
  InvMassTauHadMu3ZZ2L2Nu_->Rebin(3);
  InvMassFullRangeZZ2L2Nu_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("Mu1Pt");
  TH1F *Mu2PtZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("Mu2Pt");
  TH1F *DiMuPtZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DiMuPt");
  TH1F *Mu1EtaZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("Mu1Eta");
  TH1F *Mu2EtaZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("Mu2Eta");
  TH1F *DiTauEtaZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DiTauEta");
  TH1F *DiTauPhiZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DiTauPhi");
  TH1F *DiMuEtaZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DiMuEta");
  TH1F *DiMudRZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DiMudR");
  TH1F *DiMuPhiZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DiMuPhi");
  TH1F *EtMETZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("EtMET");
  TH1F *DiTauDiMuMassZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRZZ2L2Nu_ = (TH1F*)infileZZ2L2Nu.Get("ZMassdR");

  ////////////////
  // ZZ2L2Q
  ////////////////
  TH1F *NMedIsoTausWithMu3ZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3ZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3ZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("InvMassFullRange");
  InvMassTauHadMu3ZZ2L2Q_->Rebin(3);
  InvMassFullRangeZZ2L2Q_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("Mu1Pt");
  TH1F *Mu2PtZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("Mu2Pt");
  TH1F *DiMuPtZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DiMuPt");
  TH1F *Mu1EtaZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("Mu1Eta");
  TH1F *Mu2EtaZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("Mu2Eta");
  TH1F *DiTauEtaZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DiTauEta");
  TH1F *DiTauPhiZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DiTauPhi");
  TH1F *DiMuEtaZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DiMuEta");
  TH1F *DiMudRZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DiMudR");
  TH1F *DiMuPhiZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DiMuPhi");
  TH1F *EtMETZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("EtMET");
  TH1F *DiTauDiMuMassZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRZZ2L2Q_ = (TH1F*)infileZZ2L2Q.Get("ZMassdR");

  ////////////////
  // ZZ4LAmac
  ////////////////
  TH1F *NMedIsoTausWithMu3ZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3ZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3ZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("InvMassFullRange");
  InvMassTauHadMu3ZZ4LAmac_->Rebin(3);
  InvMassFullRangeZZ4LAmac_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("Mu1Pt");
  TH1F *Mu2PtZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("Mu2Pt");
  TH1F *DiMuPtZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DiMuPt");
  TH1F *Mu1EtaZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("Mu1Eta");
  TH1F *Mu2EtaZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("Mu2Eta");
  TH1F *DiTauEtaZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DiTauEta");
  TH1F *DiTauPhiZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DiTauPhi");
  TH1F *DiMuEtaZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DiMuEta");
  TH1F *DiMudRZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DiMudR");
  TH1F *DiMuPhiZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DiMuPhi");
  TH1F *EtMETZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("EtMET");
  TH1F *DiTauDiMuMassZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRZZ4LAmac_ = (TH1F*)infileZZ4LAmac.Get("ZMassdR");

//  ////////////////
//  // ZZ4LPowh
//  ////////////////
//  TH1F *NMedIsoTausWithMu3ZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("NMedIsoTausWithMu3");
//  TH1F *InvMassTauHadMu3ZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("InvMassTauHadMu3");
//  TH1F *PtTauHadMu3ZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("PtTauHadMu3");
//  TH1F *InvMassMu1TauMuZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("InvMassMu1TauMu");
//  TH1F *InvMassMu2TauMuZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("InvMassMu2TauMu");
//  TH1F *InvMassFullRangeZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("InvMassFullRange");
//  InvMassFullRangeZZ4LPowh_->Rebin(3);
//  InvMassFullRangeZZ4LPowh_->Rebin(5);
//  TH1F *InvMassDiMuBarrBarrZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("InvMassDiMuBarrBarr");
//  TH1F *InvMassDiMuBarrEndcZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("InvMassDiMuBarrEndc");
//  TH1F *InvMassDiMuEndcEndcZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("InvMassDiMuEndcEndc");
//  TH1F *Mu1PtZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("Mu1Pt");
//  TH1F *Mu2PtZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("Mu2Pt");
//  TH1F *DiMuPtZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DiMuPt");
//  TH1F *Mu1EtaZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("Mu1Eta");
//  TH1F *Mu2EtaZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("Mu2Eta");
//  TH1F *DiTauEtaZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DiTauEta");
//  TH1F *DiTauPhiZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DiTauPhi");
//  TH1F *DiMuEtaZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DiMuEta");
//  TH1F *DiMudRZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DiMudR");
//  TH1F *DiMuPhiZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DiMuPhi");
//  TH1F *EtMETZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("EtMET");
//  TH1F *DiTauDiMuMassZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DiTauDiMuMass");
//  TH1F *DiMuDiTauDeltaPhiZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DiMuDiTauDeltaPhi");
//  TH1F *METDiTauDeltaPhiZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("METDiMuDeltaPhi");
//  TH1F *METDiMuDeltaPhiZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("METDiMuDeltaPhi");
//  TH1F *DiTaudRZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DiTaudR");
//  TH1F *DiTauMassSmallerdRZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("DiTauMassSmallerdR");
//  TH1F *ZMassdRZZ4LPowh_ = (TH1F*)infileZZ4LPowh.Get("ZMassdR");
//
//
  ////////////////
  // JPsi
  ////////////////
  TH1F *NMedIsoTausWithMu3JPsi_ = (TH1F*)infileJPsi.Get("NMedIsoTausWithMu3");
  TH1F *InvMassTauHadMu3JPsi_ = (TH1F*)infileJPsi.Get("InvMassTauHadMu3");
  TH1F *PtTauHadMu3JPsi_ = (TH1F*)infileJPsi.Get("PtTauHadMu3");
  TH1F *InvMassMu1TauMuJPsi_ = (TH1F*)infileJPsi.Get("InvMassMu1TauMu");
  TH1F *InvMassMu2TauMuJPsi_ = (TH1F*)infileJPsi.Get("InvMassMu2TauMu");
  TH1F *InvMassFullRangeJPsi_ = (TH1F*)infileJPsi.Get("InvMassFullRange");
  InvMassTauHadMu3JPsi_->Rebin(3);
  InvMassTauHadMu3JPsi_->Rebin(5);
  TH1F *InvMassDiMuBarrBarrJPsi_ = (TH1F*)infileJPsi.Get("InvMassDiMuBarrBarr");
  TH1F *InvMassDiMuBarrEndcJPsi_ = (TH1F*)infileJPsi.Get("InvMassDiMuBarrEndc");
  TH1F *InvMassDiMuEndcEndcJPsi_ = (TH1F*)infileJPsi.Get("InvMassDiMuEndcEndc");
  TH1F *Mu1PtJPsi_ = (TH1F*)infileJPsi.Get("Mu1Pt");
  TH1F *Mu2PtJPsi_ = (TH1F*)infileJPsi.Get("Mu2Pt");
  TH1F *DiMuPtJPsi_ = (TH1F*)infileJPsi.Get("DiMuPt");
  TH1F *Mu1EtaJPsi_ = (TH1F*)infileJPsi.Get("Mu1Eta");
  TH1F *Mu2EtaJPsi_ = (TH1F*)infileJPsi.Get("Mu2Eta");
  TH1F *DiTauEtaJPsi_ = (TH1F*)infileJPsi.Get("DiTauEta");
  TH1F *DiTauPhiJPsi_ = (TH1F*)infileJPsi.Get("DiTauPhi");
  TH1F *DiMuEtaJPsi_ = (TH1F*)infileJPsi.Get("DiMuEta");
  TH1F *DiMudRJPsi_ = (TH1F*)infileJPsi.Get("DiMudR");
  TH1F *DiMuPhiJPsi_ = (TH1F*)infileJPsi.Get("DiMuPhi");
  TH1F *EtMETJPsi_ = (TH1F*)infileJPsi.Get("EtMET");
  TH1F *DiTauDiMuMassJPsi_ = (TH1F*)infileJPsi.Get("DiTauDiMuMass");
  TH1F *DiMuDiTauDeltaPhiJPsi_ = (TH1F*)infileJPsi.Get("DiMuDiTauDeltaPhi");
  TH1F *METDiTauDeltaPhiJPsi_ = (TH1F*)infileJPsi.Get("METDiMuDeltaPhi");
  TH1F *METDiMuDeltaPhiJPsi_ = (TH1F*)infileJPsi.Get("METDiMuDeltaPhi");
  TH1F *DiTaudRJPsi_ = (TH1F*)infileJPsi.Get("DiTaudR");
  TH1F *DiTauMassSmallerdRJPsi_ = (TH1F*)infileJPsi.Get("DiTauMassSmallerdR");
  TH1F *ZMassdRJPsi_ = (TH1F*)infileJPsi.Get("ZMassdR");

cout << "Got Canvases" << endl;


cout << "Got Histograms from Canvases" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the QCD Combined Canvas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *NMedIsoTausWithMu3CanvasQCD = new TCanvas ("NMedIsoTausWithMu3CanvasQCD","",600,600); 
  TCanvas *InvMassTauHadMu3CanvasQCD = new TCanvas ("InvMassTauHadMu3CanvasQCD","",600,600); 
  TCanvas *PtTauHadMu3CanvasQCD = new TCanvas ("PtTauHadMu3CanvasQCD","",600,600); 
  TCanvas *InvMassMu1TauMuCanvasQCD = new TCanvas ("InvMassMu1TauMuCanvasQCD","",600,600); 
  TCanvas *InvMassMu2TauMuCanvasQCD = new TCanvas ("InvMassMu2TauMuCanvasQCD","",600,600); 
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
  TCanvas *ZMassdRCanvasQCD = new TCanvas ("ZMassdRCanvasQCD","",600,600); 

  TH1F *NMedIsoTausWithMu3QCD_ = new TH1F ("NMedIsoTausWithMu3QCD","", NMedIsoTausWithMu3QCD_15to20_->GetNbinsX(), NMedIsoTausWithMu3QCD_15to20_->GetXaxis()->GetXmin(),  NMedIsoTausWithMu3QCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *InvMassTauHadMu3QCD_ = new TH1F ("InvMassTauHadMu3QCD","",InvMassTauHadMu3QCD_15to20_->GetNbinsX(), InvMassTauHadMu3QCD_15to20_->GetXaxis()->GetXmin(),  InvMassTauHadMu3QCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *PtTauHadMu3QCD_ = new TH1F ("PtTauHadMu3QCD","",PtTauHadMu3QCD_15to20_->GetNbinsX(), PtTauHadMu3QCD_15to20_->GetXaxis()->GetXmin(),  PtTauHadMu3QCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *InvMassMu1TauMuQCD_ = new TH1F ("InvMassMu1TauMuQCD","",InvMassMu1TauMuQCD_15to20_->GetNbinsX(), InvMassMu1TauMuQCD_15to20_->GetXaxis()->GetXmin(),  InvMassMu1TauMuQCD_15to20_->GetXaxis()->GetXmax() );
  TH1F *InvMassMu2TauMuQCD_ = new TH1F ("InvMassMu2TauMuQCD","",InvMassMu2TauMuQCD_15to20_->GetNbinsX(), InvMassMu2TauMuQCD_15to20_->GetXaxis()->GetXmin(),  InvMassMu2TauMuQCD_15to20_->GetXaxis()->GetXmax() );
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
  TH1F *ZMassdRQCD_ = new TH1F ("ZMassdRQCD","",ZMassdRQCD_15to20_->GetNbinsX(), ZMassdRQCD_15to20_->GetXaxis()->GetXmin(),  ZMassdRQCD_15to20_->GetXaxis()->GetXmax() );


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

  InvMassMu1TauMuCanvasQCD->cd();
  InvMassMu1TauMuQCD_->Add(InvMassMu1TauMuQCD_15to20_);
  InvMassMu1TauMuQCD_->Add(InvMassMu1TauMuQCD_20to30_);
  InvMassMu1TauMuQCD_->Add(InvMassMu1TauMuQCD_30to50_);
  InvMassMu1TauMuQCD_->Add(InvMassMu1TauMuQCD_50to80_);
  InvMassMu1TauMuQCD_->Add(InvMassMu1TauMuQCD_80to120_);
  InvMassMu1TauMuQCD_->Add(InvMassMu1TauMuQCD_120to170_);
  InvMassMu1TauMuQCD_->Add(InvMassMu1TauMuQCD_170to300_);
  InvMassMu1TauMuQCD_->Add(InvMassMu1TauMuQCD_300to470_);
  InvMassMu1TauMuQCD_->Add(InvMassMu1TauMuQCD_470to600_);
  InvMassMu1TauMuQCD_->Add(InvMassMu1TauMuQCD_600to800_);
  InvMassMu1TauMuQCD_->Add(InvMassMu1TauMuQCD_800to1000_);
  InvMassMu1TauMuQCD_->Add(InvMassMu1TauMuQCD_1000toInf_);

  InvMassMu2TauMuCanvasQCD->cd();
  InvMassMu2TauMuQCD_->Add(InvMassMu2TauMuQCD_15to20_);
  InvMassMu2TauMuQCD_->Add(InvMassMu2TauMuQCD_20to30_);
  InvMassMu2TauMuQCD_->Add(InvMassMu2TauMuQCD_30to50_);
  InvMassMu2TauMuQCD_->Add(InvMassMu2TauMuQCD_50to80_);
  InvMassMu2TauMuQCD_->Add(InvMassMu2TauMuQCD_80to120_);
  InvMassMu2TauMuQCD_->Add(InvMassMu2TauMuQCD_120to170_);
  InvMassMu2TauMuQCD_->Add(InvMassMu2TauMuQCD_170to300_);
  InvMassMu2TauMuQCD_->Add(InvMassMu2TauMuQCD_300to470_);
  InvMassMu2TauMuQCD_->Add(InvMassMu2TauMuQCD_470to600_);
  InvMassMu2TauMuQCD_->Add(InvMassMu2TauMuQCD_600to800_);
  InvMassMu2TauMuQCD_->Add(InvMassMu2TauMuQCD_800to1000_);
  InvMassMu2TauMuQCD_->Add(InvMassMu2TauMuQCD_1000toInf_);

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

  ZMassdRCanvasQCD->cd();
  ZMassdRQCD_->Add(ZMassdRQCD_15to20_);
  ZMassdRQCD_->Add(ZMassdRQCD_20to30_);
  ZMassdRQCD_->Add(ZMassdRQCD_30to50_);
  ZMassdRQCD_->Add(ZMassdRQCD_50to80_);
  ZMassdRQCD_->Add(ZMassdRQCD_80to120_);
  ZMassdRQCD_->Add(ZMassdRQCD_120to170_);
  ZMassdRQCD_->Add(ZMassdRQCD_170to300_);
  ZMassdRQCD_->Add(ZMassdRQCD_300to470_);
  ZMassdRQCD_->Add(ZMassdRQCD_470to600_);
  ZMassdRQCD_->Add(ZMassdRQCD_600to800_);
  ZMassdRQCD_->Add(ZMassdRQCD_800to1000_);
  ZMassdRQCD_->Add(ZMassdRQCD_1000toInf_);


  outFile->cd();
  TDirectory *QCDCombined = outFile->mkdir("QCDCombined");
  QCDCombined->cd();
  NMedIsoTausWithMu3QCD_->Write();
  InvMassTauHadMu3QCD_->Write();
  PtTauHadMu3QCD_->Write();
  InvMassMu1TauMuQCD_->Write();
  InvMassMu2TauMuQCD_->Write();
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
  ZMassdRQCD_->Write();

cout << "Combined QCD" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the DY Combined Canvas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *NMedIsoTausWithMu3CanvasDY = new TCanvas ("NMedIsoTausWithMu3CanvasDY","",600,600); 
  TCanvas *InvMassTauHadMu3CanvasDY = new TCanvas ("InvMassTauHadMu3CanvasDY","",600,600); 
  TCanvas *PtTauHadMu3CanvasDY = new TCanvas ("PtTauHadMu3CanvasDY","",600,600); 
  TCanvas *InvMassMu1TauMuCanvasDY = new TCanvas ("InvMassMu1TauMuCanvasDY","",600,600); 
  TCanvas *InvMassMu2TauMuCanvasDY = new TCanvas ("InvMassMu2TauMuCanvasDY","",600,600); 
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
  TCanvas *ZMassdRCanvasDY = new TCanvas ("ZMassdRCanvasDY","",600,600); 

  TH1F *NMedIsoTausWithMu3DY_ = new TH1F ("NMedIsoTausWithMu3DY","", NMedIsoTausWithMu3DYL_->GetNbinsX(), NMedIsoTausWithMu3DYL_->GetXaxis()->GetXmin(), NMedIsoTausWithMu3DYL_->GetXaxis()->GetXmax() );
  TH1F *InvMassTauHadMu3DY_ = new TH1F ("InvMassTauHadMu3DY","",InvMassTauHadMu3DYL_->GetNbinsX(), InvMassTauHadMu3DYL_->GetXaxis()->GetXmin(), InvMassTauHadMu3DYL_->GetXaxis()->GetXmax() );
  TH1F *PtTauHadMu3DY_ = new TH1F ("PtTauHadMu3DY","",PtTauHadMu3DYL_->GetNbinsX(), PtTauHadMu3DYL_->GetXaxis()->GetXmin(), PtTauHadMu3DYL_->GetXaxis()->GetXmax() );
  TH1F *InvMassMu1TauMuDY_ = new TH1F ("InvMassMu1TauMuDY","",InvMassMu1TauMuDYL_->GetNbinsX(), InvMassMu1TauMuDYL_->GetXaxis()->GetXmin(), InvMassMu1TauMuDYL_->GetXaxis()->GetXmax() );
  TH1F *InvMassMu2TauMuDY_ = new TH1F ("InvMassMu2TauMuDY","",InvMassMu2TauMuDYL_->GetNbinsX(), InvMassMu2TauMuDYL_->GetXaxis()->GetXmin(), InvMassMu2TauMuDYL_->GetXaxis()->GetXmax() );
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
  TH1F *ZMassdRDY_ = new TH1F ("ZMassdRDY","",ZMassdRDYL_->GetNbinsX(), ZMassdRDYL_->GetXaxis()->GetXmin(), ZMassdRDYL_->GetXaxis()->GetXmax() );

  NMedIsoTausWithMu3CanvasDY->cd();
  NMedIsoTausWithMu3DY_->Add(NMedIsoTausWithMu3DYL_);
  NMedIsoTausWithMu3DY_->Add(NMedIsoTausWithMu3DYH_);
  NMedIsoTausWithMu3DY_->Add(NMedIsoTausWithMu3Up_);
  NMedIsoTausWithMu3DY_->Add(NMedIsoTausWithMu3JPsi_);

  InvMassTauHadMu3CanvasDY->cd();
  InvMassTauHadMu3DY_->Add(InvMassTauHadMu3DYL_);
  InvMassTauHadMu3DY_->Add(InvMassTauHadMu3DYH_);
  InvMassTauHadMu3DY_->Add(InvMassTauHadMu3Up_);
  InvMassTauHadMu3DY_->Add(InvMassTauHadMu3JPsi_);

  PtTauHadMu3CanvasDY->cd();
  PtTauHadMu3DY_->Add(PtTauHadMu3DYL_);
  PtTauHadMu3DY_->Add(PtTauHadMu3DYH_);
  PtTauHadMu3DY_->Add(PtTauHadMu3Up_);
  PtTauHadMu3DY_->Add(PtTauHadMu3JPsi_);

  InvMassMu1TauMuCanvasDY->cd();
  InvMassMu1TauMuDY_->Add(InvMassMu1TauMuDYL_);
  InvMassMu1TauMuDY_->Add(InvMassMu1TauMuDYH_);
  InvMassMu1TauMuDY_->Add(InvMassMu1TauMuUp_);
  InvMassMu1TauMuDY_->Add(InvMassMu1TauMuJPsi_);

  InvMassMu2TauMuCanvasDY->cd();
  InvMassMu2TauMuDY_->Add(InvMassMu2TauMuDYL_);
  InvMassMu2TauMuDY_->Add(InvMassMu2TauMuDYH_);
  InvMassMu2TauMuDY_->Add(InvMassMu2TauMuUp_);
  InvMassMu2TauMuDY_->Add(InvMassMu2TauMuJPsi_);

  InvMassFullRangeCanvasDY->cd();
  InvMassFullRangeDY_->Add(InvMassFullRangeDYL_);
  InvMassFullRangeDY_->Add(InvMassFullRangeDYH_);
  InvMassFullRangeDY_->Add(InvMassFullRangeUp_);
  InvMassFullRangeDY_->Add(InvMassFullRangeJPsi_);

  InvMassDiMuBarrBarrCanvasDY->cd();
  InvMassDiMuBarrBarrDY_->Add(InvMassDiMuBarrBarrDYL_);
  InvMassDiMuBarrBarrDY_->Add(InvMassDiMuBarrBarrDYH_);
  InvMassDiMuBarrBarrDY_->Add(InvMassDiMuBarrBarrUp_);
  InvMassDiMuBarrBarrDY_->Add(InvMassDiMuBarrBarrJPsi_);

  InvMassDiMuBarrEndcCanvasDY->cd();
  InvMassDiMuBarrEndcDY_->Add(InvMassDiMuBarrEndcDYL_);
  InvMassDiMuBarrEndcDY_->Add(InvMassDiMuBarrEndcDYH_);
  InvMassDiMuBarrEndcDY_->Add(InvMassDiMuBarrEndcUp_);
  InvMassDiMuBarrEndcDY_->Add(InvMassDiMuBarrEndcJPsi_);

  InvMassDiMuEndcEndcCanvasDY->cd();
  InvMassDiMuEndcEndcDY_->Add(InvMassDiMuEndcEndcDYL_);
  InvMassDiMuEndcEndcDY_->Add(InvMassDiMuEndcEndcDYH_);
  InvMassDiMuEndcEndcDY_->Add(InvMassDiMuEndcEndcUp_);
  InvMassDiMuEndcEndcDY_->Add(InvMassDiMuEndcEndcJPsi_);

  Mu1PtCanvasDY->cd();
  Mu1PtDY_->Add(Mu1PtDYL_);
  Mu1PtDY_->Add(Mu1PtDYH_);
  Mu1PtDY_->Add(Mu1PtUp_);
  Mu1PtDY_->Add(Mu1PtJPsi_);

  Mu2PtCanvasDY->cd();
  Mu2PtDY_->Add(Mu2PtDYL_);
  Mu2PtDY_->Add(Mu2PtDYH_);
  Mu2PtDY_->Add(Mu2PtUp_);
  Mu2PtDY_->Add(Mu2PtJPsi_);

  DiMuPtCanvasDY->cd();
  DiMuPtDY_->Add(DiMuPtDYL_);
  DiMuPtDY_->Add(DiMuPtDYH_);
  DiMuPtDY_->Add(DiMuPtUp_);
  DiMuPtDY_->Add(DiMuPtJPsi_);

  Mu1EtaCanvasDY->cd();
  Mu1EtaDY_->Add(Mu1EtaDYL_);
  Mu1EtaDY_->Add(Mu1EtaDYH_);
  Mu1EtaDY_->Add(Mu1EtaUp_);
  Mu1EtaDY_->Add(Mu1EtaJPsi_);

  Mu2EtaCanvasDY->cd();
  Mu2EtaDY_->Add(Mu2EtaDYL_);
  Mu2EtaDY_->Add(Mu2EtaDYH_);
  Mu2EtaDY_->Add(Mu2EtaUp_);
  Mu2EtaDY_->Add(Mu2EtaJPsi_);

  DiTauEtaCanvasDY->cd();
  DiTauEtaDY_->Add(DiTauEtaDYL_);
  DiTauEtaDY_->Add(DiTauEtaDYH_);
  DiTauEtaDY_->Add(DiTauEtaUp_);
  DiTauEtaDY_->Add(DiTauEtaJPsi_);

  DiTauPhiCanvasDY->cd();
  DiTauPhiDY_->Add(DiTauPhiDYL_);
  DiTauPhiDY_->Add(DiTauPhiDYH_);
  DiTauPhiDY_->Add(DiTauPhiUp_);
  DiTauPhiDY_->Add(DiTauPhiJPsi_);

  DiMuEtaCanvasDY->cd();
  DiMuEtaDY_->Add(DiMuEtaDYL_);
  DiMuEtaDY_->Add(DiMuEtaDYH_);
  DiMuEtaDY_->Add(DiMuEtaUp_);
  DiMuEtaDY_->Add(DiMuEtaJPsi_);

  DiMudRCanvasDY->cd();
  DiMudRDY_->Add(DiMudRDYL_);
  DiMudRDY_->Add(DiMudRDYH_);
  DiMudRDY_->Add(DiMudRUp_);
  DiMudRDY_->Add(DiMudRJPsi_);

  DiMuPhiCanvasDY->cd();
  DiMuPhiDY_->Add(DiMuPhiDYL_);
  DiMuPhiDY_->Add(DiMuPhiDYH_);
  DiMuPhiDY_->Add(DiMuPhiUp_);
  DiMuPhiDY_->Add(DiMuPhiJPsi_);

  EtMETCanvasDY->cd();
  EtMETDY_->Add(EtMETDYL_);
  EtMETDY_->Add(EtMETDYH_);
  EtMETDY_->Add(EtMETUp_);
  EtMETDY_->Add(EtMETJPsi_);

  DiTauDiMuMassCanvasDY->cd();
  DiTauDiMuMassDY_->Add(DiTauDiMuMassDYL_);
  DiTauDiMuMassDY_->Add(DiTauDiMuMassDYH_);
  DiTauDiMuMassDY_->Add(DiTauDiMuMassUp_);
  DiTauDiMuMassDY_->Add(DiTauDiMuMassJPsi_);

  DiMuDiTauDeltaPhiCanvasDY->cd();
  DiMuDiTauDeltaPhiDY_->Add(DiMuDiTauDeltaPhiDYL_);
  DiMuDiTauDeltaPhiDY_->Add(DiMuDiTauDeltaPhiDYH_);
  DiMuDiTauDeltaPhiDY_->Add(DiMuDiTauDeltaPhiUp_);
  DiMuDiTauDeltaPhiDY_->Add(DiMuDiTauDeltaPhiJPsi_);

  METDiTauDeltaPhiCanvasDY->cd();
  METDiTauDeltaPhiDY_->Add(METDiTauDeltaPhiDYL_);
  METDiTauDeltaPhiDY_->Add(METDiTauDeltaPhiDYH_);
  METDiTauDeltaPhiDY_->Add(METDiTauDeltaPhiUp_);
  METDiTauDeltaPhiDY_->Add(METDiTauDeltaPhiJPsi_);

  METDiMuDeltaPhiCanvasDY->cd();
  METDiMuDeltaPhiDY_->Add(METDiMuDeltaPhiDYL_);
  METDiMuDeltaPhiDY_->Add(METDiMuDeltaPhiDYH_);
  METDiMuDeltaPhiDY_->Add(METDiMuDeltaPhiUp_);
  METDiMuDeltaPhiDY_->Add(METDiMuDeltaPhiJPsi_);


  DiTaudRCanvasDY->cd();
  DiTaudRDY_->Add(DiTaudRDYL_);
  DiTaudRDY_->Add(DiTaudRDYH_);
  DiTaudRDY_->Add(DiTaudRUp_);
  DiTaudRDY_->Add(DiTaudRJPsi_);

  DiTauMassSmallerdRCanvasDY->cd();
  DiTauMassSmallerdRDY_->Add(DiTauMassSmallerdRDYL_);
  DiTauMassSmallerdRDY_->Add(DiTauMassSmallerdRDYH_);
  DiTauMassSmallerdRDY_->Add(DiTauMassSmallerdRUp_);
  DiTauMassSmallerdRDY_->Add(DiTauMassSmallerdRJPsi_);

  ZMassdRCanvasDY->cd();
  ZMassdRDY_->Add(ZMassdRDYL_);
  ZMassdRDY_->Add(ZMassdRDYH_);
  ZMassdRDY_->Add(ZMassdRUp_);
  ZMassdRDY_->Add(ZMassdRJPsi_);

  outFile->cd();
  TDirectory *DYCombined = outFile->mkdir("DYCombined");
  DYCombined->cd();
  NMedIsoTausWithMu3DY_->Write();
  InvMassTauHadMu3DY_->Write();
  PtTauHadMu3DY_->Write();
  InvMassMu1TauMuDY_->Write();
  InvMassMu2TauMuDY_->Write();
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
  ZMassdRDY_->Write();

cout << "Combined DY" << endl;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the ST Combined Canvas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *NMedIsoTausWithMu3CanvasST = new TCanvas ("NMedIsoTausWithMu3CanvasST","",600,600); 
  TCanvas *InvMassTauHadMu3CanvasST = new TCanvas ("InvMassTauHadMu3CanvasST","",600,600); 
  TCanvas *PtTauHadMu3CanvasST = new TCanvas ("PtTauHadMu3CanvasST","",600,600); 
  TCanvas *InvMassMu1TauMuCanvasST = new TCanvas ("InvMassMu1TauMuCanvasST","",600,600); 
  TCanvas *InvMassMu2TauMuCanvasST = new TCanvas ("InvMassMu2TauMuCanvasST","",600,600); 
  TCanvas *InvMassFullRangeCanvasST = new TCanvas ("InvMassFullRangeCanvasST","",600,600); 
  TCanvas *InvMassDiMuBarrBarrCanvasST = new TCanvas ("InvMassDiMuBarrBarrCanvasST","",600,600); 
  TCanvas *InvMassDiMuBarrEndcCanvasST = new TCanvas ("InvMassDiMuBarrEndcCanvasST","",600,600); 
  TCanvas *InvMassDiMuEndcEndcCanvasST = new TCanvas ("InvMassDiMuEndcEndcCanvasST","",600,600); 
  TCanvas *Mu1PtCanvasST = new TCanvas ("Mu1PtCanvasST","",600,600); 
  TCanvas *Mu2PtCanvasST = new TCanvas ("Mu2PtCanvasST","",600,600); 
  TCanvas *DiMuPtCanvasST = new TCanvas ("DiMuPtCanvasST","",600,600); 
  TCanvas *Mu1EtaCanvasST = new TCanvas ("Mu1EtaCanvasST","",600,600); 
  TCanvas *Mu2EtaCanvasST = new TCanvas ("Mu2EtaCanvasST","",600,600); 
  TCanvas *DiTauEtaCanvasST = new TCanvas ("DiTauEtaCanvasST","",600,600); 
  TCanvas *DiTauPhiCanvasST = new TCanvas ("DiTauPhiCanvasST","",600,600); 
  TCanvas *DiMuEtaCanvasST = new TCanvas ("DiMuEtaCanvasST","",600,600); 
  TCanvas *DiMudRCanvasST = new TCanvas ("DiMudRCanvasST","",600,600); 
  TCanvas *DiMuPhiCanvasST = new TCanvas ("DiMuPhiCanvasST","",600,600); 
  TCanvas *EtMETCanvasST = new TCanvas ("EtMETCanvasST","",600,600); 
  TCanvas *DiTauDiMuMassCanvasST = new TCanvas ("DiTauDiMuMassCanvasST","",600,600); 
  TCanvas *DiMuDiTauDeltaPhiCanvasST = new TCanvas ("DiMuDiTauDeltaPhiCanvasST","",600,600); 
  TCanvas *METDiTauDeltaPhiCanvasST = new TCanvas ("METDiTauDeltaPhiCanvasST","",600,600); 
  TCanvas *METDiMuDeltaPhiCanvasST = new TCanvas ("METDiMuDeltaPhiCanvasST","",600,600); 
  TCanvas *DiTaudRCanvasST = new TCanvas ("DiTaudRCanvasST","",600,600); 
  TCanvas *DiTauMassSmallerdRCanvasST = new TCanvas ("DiTauMassSmallerdRCanvasST","",600,600); 
  TCanvas *ZMassdRCanvasST = new TCanvas ("ZMassdRCanvasST","",600,600); 

  TH1F *NMedIsoTausWithMu3ST_ = new TH1F ("NMedIsoTausWithMu3ST","", NMedIsoTausWithMu3ST_sch_->GetNbinsX(), NMedIsoTausWithMu3ST_sch_->GetXaxis()->GetXmin(),  NMedIsoTausWithMu3ST_sch_->GetXaxis()->GetXmax() );
  TH1F *InvMassTauHadMu3ST_ = new TH1F ("InvMassTauHadMu3ST","",InvMassTauHadMu3ST_sch_->GetNbinsX(), InvMassTauHadMu3ST_sch_->GetXaxis()->GetXmin(),  InvMassTauHadMu3ST_sch_->GetXaxis()->GetXmax() );
  TH1F *PtTauHadMu3ST_ = new TH1F ("PtTauHadMu3ST","",PtTauHadMu3ST_sch_->GetNbinsX(), PtTauHadMu3ST_sch_->GetXaxis()->GetXmin(),  PtTauHadMu3ST_sch_->GetXaxis()->GetXmax() );
  TH1F *InvMassMu1TauMuST_ = new TH1F ("InvMassMu1TauMuST","",InvMassMu1TauMuST_sch_->GetNbinsX(), InvMassMu1TauMuST_sch_->GetXaxis()->GetXmin(),  InvMassMu1TauMuST_sch_->GetXaxis()->GetXmax() );
  TH1F *InvMassMu2TauMuST_ = new TH1F ("InvMassMu2TauMuST","",InvMassMu2TauMuST_sch_->GetNbinsX(), InvMassMu2TauMuST_sch_->GetXaxis()->GetXmin(),  InvMassMu2TauMuST_sch_->GetXaxis()->GetXmax() );
  TH1F *InvMassFullRangeST_ = new TH1F ("InvMassFullRangeST","",InvMassFullRangeST_sch_->GetNbinsX(), InvMassFullRangeST_sch_->GetXaxis()->GetXmin(),  InvMassFullRangeST_sch_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuBarrBarrST_ = new TH1F ("InvMassDiMuBarrBarrST","",InvMassDiMuBarrBarrST_sch_->GetNbinsX(), InvMassDiMuBarrBarrST_sch_->GetXaxis()->GetXmin(),  InvMassDiMuBarrBarrST_sch_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuBarrEndcST_ = new TH1F ("InvMassDiMuBarrEndcST","",InvMassDiMuBarrEndcST_sch_->GetNbinsX(), InvMassDiMuBarrEndcST_sch_->GetXaxis()->GetXmin(),  InvMassDiMuBarrEndcST_sch_->GetXaxis()->GetXmax() );
  TH1F *InvMassDiMuEndcEndcST_ = new TH1F ("InvMassDiMuEndcEndcST","",InvMassDiMuEndcEndcST_sch_->GetNbinsX(), InvMassDiMuEndcEndcST_sch_->GetXaxis()->GetXmin(),  InvMassDiMuEndcEndcST_sch_->GetXaxis()->GetXmax() );
  TH1F *Mu1PtST_ = new TH1F ("Mu1PtST","",Mu1PtST_sch_->GetNbinsX(), Mu1PtST_sch_->GetXaxis()->GetXmin(),  Mu1PtST_sch_->GetXaxis()->GetXmax() );
  TH1F *Mu2PtST_ = new TH1F ("Mu2PtST","",Mu2PtST_sch_->GetNbinsX(), Mu2PtST_sch_->GetXaxis()->GetXmin(),  Mu2PtST_sch_->GetXaxis()->GetXmax() );
  TH1F *DiMuPtST_ = new TH1F ("DiMuPtST","",DiMuPtST_sch_->GetNbinsX(), DiMuPtST_sch_->GetXaxis()->GetXmin(),  DiMuPtST_sch_->GetXaxis()->GetXmax() );
  TH1F *Mu1EtaST_ = new TH1F ("Mu1EtaST","",Mu1EtaST_sch_->GetNbinsX(), Mu1EtaST_sch_->GetXaxis()->GetXmin(),  Mu1EtaST_sch_->GetXaxis()->GetXmax() );
  TH1F *Mu2EtaST_ = new TH1F ("Mu2EtaST","",Mu2EtaST_sch_->GetNbinsX(), Mu2EtaST_sch_->GetXaxis()->GetXmin(),  Mu2EtaST_sch_->GetXaxis()->GetXmax() );
  TH1F *DiTauEtaST_ = new TH1F ("DiTauEtaST","",DiTauEtaST_sch_->GetNbinsX(), DiTauEtaST_sch_->GetXaxis()->GetXmin(),  DiTauEtaST_sch_->GetXaxis()->GetXmax() );
  TH1F *DiTauPhiST_ = new TH1F ("DiTauPhiST","",DiTauPhiST_sch_->GetNbinsX(), DiTauPhiST_sch_->GetXaxis()->GetXmin(),  DiTauPhiST_sch_->GetXaxis()->GetXmax() );
  TH1F *DiMuEtaST_ = new TH1F ("DiMuEtaST","",DiMuEtaST_sch_->GetNbinsX(), DiMuEtaST_sch_->GetXaxis()->GetXmin(),  DiMuEtaST_sch_->GetXaxis()->GetXmax() );
  TH1F *DiMudRST_ = new TH1F ("DiMudRST","",DiMudRST_sch_->GetNbinsX(), DiMudRST_sch_->GetXaxis()->GetXmin(),  DiMudRST_sch_->GetXaxis()->GetXmax() );
  TH1F *DiMuPhiST_ = new TH1F ("DiMuPhiST","",DiMuPhiST_sch_->GetNbinsX(), DiMuPhiST_sch_->GetXaxis()->GetXmin(),  DiMuPhiST_sch_->GetXaxis()->GetXmax() );
  TH1F *EtMETST_ = new TH1F ("EtMETST","",EtMETST_sch_->GetNbinsX(), EtMETST_sch_->GetXaxis()->GetXmin(),  EtMETST_sch_->GetXaxis()->GetXmax() );
  TH1F *DiTauDiMuMassST_ = new TH1F ("DiTauDiMuMassST","",DiTauDiMuMassST_sch_->GetNbinsX(), DiTauDiMuMassST_sch_->GetXaxis()->GetXmin(),  DiTauDiMuMassST_sch_->GetXaxis()->GetXmax() );
  TH1F *DiMuDiTauDeltaPhiST_ = new TH1F ("DiMuDiTauDeltaPhiST","",DiMuDiTauDeltaPhiST_sch_->GetNbinsX(), DiMuDiTauDeltaPhiST_sch_->GetXaxis()->GetXmin(),  DiMuDiTauDeltaPhiST_sch_->GetXaxis()->GetXmax() );
  TH1F *METDiTauDeltaPhiST_ = new TH1F ("METDiTauDeltaPhiST","",METDiTauDeltaPhiST_sch_->GetNbinsX(), METDiTauDeltaPhiST_sch_->GetXaxis()->GetXmin(),  METDiTauDeltaPhiST_sch_->GetXaxis()->GetXmax() );
  TH1F *METDiMuDeltaPhiST_ = new TH1F ("METDiMuDeltaPhiST","",METDiMuDeltaPhiST_sch_->GetNbinsX(), METDiMuDeltaPhiST_sch_->GetXaxis()->GetXmin(),  METDiMuDeltaPhiST_sch_->GetXaxis()->GetXmax() );
  TH1F *DiTaudRST_ = new TH1F ("DiTaudRST","",DiTaudRST_sch_->GetNbinsX(), DiTaudRST_sch_->GetXaxis()->GetXmin(),  DiTaudRST_sch_->GetXaxis()->GetXmax() );
  TH1F *DiTauMassSmallerdRST_ = new TH1F ("DiTauMassSmallerdRST","",DiTauMassSmallerdRST_sch_->GetNbinsX(), DiTauMassSmallerdRST_sch_->GetXaxis()->GetXmin(),  DiTauMassSmallerdRST_sch_->GetXaxis()->GetXmax() );
  TH1F *ZMassdRST_ = new TH1F ("ZMassdRST","",ZMassdRST_sch_->GetNbinsX(), ZMassdRST_sch_->GetXaxis()->GetXmin(),  ZMassdRST_sch_->GetXaxis()->GetXmax() );


  NMedIsoTausWithMu3CanvasST->cd();
  NMedIsoTausWithMu3ST_->Add(NMedIsoTausWithMu3ST_sch_);
//  NMedIsoTausWithMu3ST_->Add(NMedIsoTausWithMu3ST_tWNoHad_antitop_);
//  NMedIsoTausWithMu3ST_->Add(NMedIsoTausWithMu3ST_tWNoHad_top_);
  NMedIsoTausWithMu3ST_->Add(NMedIsoTausWithMu3ST_tWIncl_antitop_);
  NMedIsoTausWithMu3ST_->Add(NMedIsoTausWithMu3ST_tWIncl_top_);
  NMedIsoTausWithMu3ST_->Add(NMedIsoTausWithMu3ST_tch_antitop_);
  NMedIsoTausWithMu3ST_->Add(NMedIsoTausWithMu3ST_tch_top_);

  InvMassTauHadMu3CanvasST->cd();
  InvMassTauHadMu3ST_->Add(InvMassTauHadMu3ST_sch_);
//  InvMassTauHadMu3ST_->Add(InvMassTauHadMu3ST_tWNoHad_antitop_);
//  InvMassTauHadMu3ST_->Add(InvMassTauHadMu3ST_tWNoHad_top_);
  InvMassTauHadMu3ST_->Add(InvMassTauHadMu3ST_tWIncl_antitop_);
  InvMassTauHadMu3ST_->Add(InvMassTauHadMu3ST_tWIncl_top_);
  InvMassTauHadMu3ST_->Add(InvMassTauHadMu3ST_tch_antitop_);
  InvMassTauHadMu3ST_->Add(InvMassTauHadMu3ST_tch_top_);

  PtTauHadMu3CanvasST->cd();
  PtTauHadMu3ST_->Add(PtTauHadMu3ST_sch_);
//  PtTauHadMu3ST_->Add(PtTauHadMu3ST_tWNoHad_antitop_);
//  PtTauHadMu3ST_->Add(PtTauHadMu3ST_tWNoHad_top_);
  PtTauHadMu3ST_->Add(PtTauHadMu3ST_tWIncl_antitop_);
  PtTauHadMu3ST_->Add(PtTauHadMu3ST_tWIncl_top_);
  PtTauHadMu3ST_->Add(PtTauHadMu3ST_tch_antitop_);
  PtTauHadMu3ST_->Add(PtTauHadMu3ST_tch_top_);

  InvMassMu1TauMuCanvasST->cd();
  InvMassMu1TauMuST_->Add(InvMassMu1TauMuST_sch_);
//  InvMassMu1TauMuST_->Add(InvMassMu1TauMuST_tWNoHad_antitop_);
//  InvMassMu1TauMuST_->Add(InvMassMu1TauMuST_tWNoHad_top_);
  InvMassMu1TauMuST_->Add(InvMassMu1TauMuST_tWIncl_antitop_);
  InvMassMu1TauMuST_->Add(InvMassMu1TauMuST_tWIncl_top_);
  InvMassMu1TauMuST_->Add(InvMassMu1TauMuST_tch_antitop_);
  InvMassMu1TauMuST_->Add(InvMassMu1TauMuST_tch_top_);

  InvMassMu2TauMuCanvasST->cd();
  InvMassMu2TauMuST_->Add(InvMassMu2TauMuST_sch_);
//  InvMassMu2TauMuST_->Add(InvMassMu2TauMuST_tWNoHad_antitop_);
//  InvMassMu2TauMuST_->Add(InvMassMu2TauMuST_tWNoHad_top_);
  InvMassMu2TauMuST_->Add(InvMassMu2TauMuST_tWIncl_antitop_);
  InvMassMu2TauMuST_->Add(InvMassMu2TauMuST_tWIncl_top_);
  InvMassMu2TauMuST_->Add(InvMassMu2TauMuST_tch_antitop_);
  InvMassMu2TauMuST_->Add(InvMassMu2TauMuST_tch_top_);

  InvMassFullRangeCanvasST->cd();
  InvMassFullRangeST_->Add(InvMassFullRangeST_sch_);
//  InvMassFullRangeST_->Add(InvMassFullRangeST_tWNoHad_antitop_);
//  InvMassFullRangeST_->Add(InvMassFullRangeST_tWNoHad_top_);
  InvMassFullRangeST_->Add(InvMassFullRangeST_tWIncl_antitop_);
  InvMassFullRangeST_->Add(InvMassFullRangeST_tWIncl_top_);
  InvMassFullRangeST_->Add(InvMassFullRangeST_tch_antitop_);
  InvMassFullRangeST_->Add(InvMassFullRangeST_tch_top_);

  InvMassDiMuBarrBarrCanvasST->cd();
  InvMassDiMuBarrBarrST_->Add(InvMassDiMuBarrBarrST_sch_);
//  InvMassDiMuBarrBarrST_->Add(InvMassDiMuBarrBarrST_tWNoHad_antitop_);
//  InvMassDiMuBarrBarrST_->Add(InvMassDiMuBarrBarrST_tWNoHad_top_);
  InvMassDiMuBarrBarrST_->Add(InvMassDiMuBarrBarrST_tWIncl_antitop_);
  InvMassDiMuBarrBarrST_->Add(InvMassDiMuBarrBarrST_tWIncl_top_);
  InvMassDiMuBarrBarrST_->Add(InvMassDiMuBarrBarrST_tch_antitop_);
  InvMassDiMuBarrBarrST_->Add(InvMassDiMuBarrBarrST_tch_top_);

  InvMassDiMuBarrEndcCanvasST->cd();
  InvMassDiMuBarrEndcST_->Add(InvMassDiMuBarrEndcST_sch_);
//  InvMassDiMuBarrEndcST_->Add(InvMassDiMuBarrEndcST_tWNoHad_antitop_);
//  InvMassDiMuBarrEndcST_->Add(InvMassDiMuBarrEndcST_tWNoHad_top_);
  InvMassDiMuBarrEndcST_->Add(InvMassDiMuBarrEndcST_tWIncl_antitop_);
  InvMassDiMuBarrEndcST_->Add(InvMassDiMuBarrEndcST_tWIncl_top_);
  InvMassDiMuBarrEndcST_->Add(InvMassDiMuBarrEndcST_tch_antitop_);
  InvMassDiMuBarrEndcST_->Add(InvMassDiMuBarrEndcST_tch_top_);

  InvMassDiMuEndcEndcCanvasST->cd();
  InvMassDiMuEndcEndcST_->Add(InvMassDiMuEndcEndcST_sch_);
//  InvMassDiMuEndcEndcST_->Add(InvMassDiMuEndcEndcST_tWNoHad_antitop_);
//  InvMassDiMuEndcEndcST_->Add(InvMassDiMuEndcEndcST_tWNoHad_top_);
  InvMassDiMuEndcEndcST_->Add(InvMassDiMuEndcEndcST_tWIncl_antitop_);
  InvMassDiMuEndcEndcST_->Add(InvMassDiMuEndcEndcST_tWIncl_top_);
  InvMassDiMuEndcEndcST_->Add(InvMassDiMuEndcEndcST_tch_antitop_);
  InvMassDiMuEndcEndcST_->Add(InvMassDiMuEndcEndcST_tch_top_);

  Mu1PtCanvasST->cd();
  Mu1PtST_->Add(Mu1PtST_sch_);
//  Mu1PtST_->Add(Mu1PtST_tWNoHad_antitop_);
//  Mu1PtST_->Add(Mu1PtST_tWNoHad_top_);
  Mu1PtST_->Add(Mu1PtST_tWIncl_antitop_);
  Mu1PtST_->Add(Mu1PtST_tWIncl_top_);
  Mu1PtST_->Add(Mu1PtST_tch_antitop_);
  Mu1PtST_->Add(Mu1PtST_tch_top_);

  Mu2PtCanvasST->cd();
  Mu2PtST_->Add(Mu2PtST_sch_);
//  Mu2PtST_->Add(Mu2PtST_tWNoHad_antitop_);
//  Mu2PtST_->Add(Mu2PtST_tWNoHad_top_);
  Mu2PtST_->Add(Mu2PtST_tWIncl_antitop_);
  Mu2PtST_->Add(Mu2PtST_tWIncl_top_);
  Mu2PtST_->Add(Mu2PtST_tch_antitop_);
  Mu2PtST_->Add(Mu2PtST_tch_top_);

  DiMuPtCanvasST->cd();
  DiMuPtST_->Add(DiMuPtST_sch_);
//  DiMuPtST_->Add(DiMuPtST_tWNoHad_antitop_);
//  DiMuPtST_->Add(DiMuPtST_tWNoHad_top_);
  DiMuPtST_->Add(DiMuPtST_tWIncl_antitop_);
  DiMuPtST_->Add(DiMuPtST_tWIncl_top_);
  DiMuPtST_->Add(DiMuPtST_tch_antitop_);
  DiMuPtST_->Add(DiMuPtST_tch_top_);

  Mu1EtaCanvasST->cd();
  Mu1EtaST_->Add(Mu1EtaST_sch_);
//  Mu1EtaST_->Add(Mu1EtaST_tWNoHad_antitop_);
//  Mu1EtaST_->Add(Mu1EtaST_tWNoHad_top_);
  Mu1EtaST_->Add(Mu1EtaST_tWIncl_antitop_);
  Mu1EtaST_->Add(Mu1EtaST_tWIncl_top_);
  Mu1EtaST_->Add(Mu1EtaST_tch_antitop_);
  Mu1EtaST_->Add(Mu1EtaST_tch_top_);

  Mu2EtaCanvasST->cd();
  Mu2EtaST_->Add(Mu2EtaST_sch_);
//  Mu2EtaST_->Add(Mu2EtaST_tWNoHad_antitop_);
//  Mu2EtaST_->Add(Mu2EtaST_tWNoHad_top_);
  Mu2EtaST_->Add(Mu2EtaST_tWIncl_antitop_);
  Mu2EtaST_->Add(Mu2EtaST_tWIncl_top_);
  Mu2EtaST_->Add(Mu2EtaST_tch_antitop_);
  Mu2EtaST_->Add(Mu2EtaST_tch_top_);

  DiTauEtaCanvasST->cd();
  DiTauEtaST_->Add(DiTauEtaST_sch_);
//  DiTauEtaST_->Add(DiTauEtaST_tWNoHad_antitop_);
//  DiTauEtaST_->Add(DiTauEtaST_tWNoHad_top_);
  DiTauEtaST_->Add(DiTauEtaST_tWIncl_antitop_);
  DiTauEtaST_->Add(DiTauEtaST_tWIncl_top_);
  DiTauEtaST_->Add(DiTauEtaST_tch_antitop_);
  DiTauEtaST_->Add(DiTauEtaST_tch_top_);

  DiTauPhiCanvasST->cd();
  DiTauPhiST_->Add(DiTauPhiST_sch_);
//  DiTauPhiST_->Add(DiTauPhiST_tWNoHad_antitop_);
//  DiTauPhiST_->Add(DiTauPhiST_tWNoHad_top_);
  DiTauPhiST_->Add(DiTauPhiST_tWIncl_antitop_);
  DiTauPhiST_->Add(DiTauPhiST_tWIncl_top_);
  DiTauPhiST_->Add(DiTauPhiST_tch_antitop_);
  DiTauPhiST_->Add(DiTauPhiST_tch_top_);

  DiMuEtaCanvasST->cd();
  DiMuEtaST_->Add(DiMuEtaST_sch_);
//  DiMuEtaST_->Add(DiMuEtaST_tWNoHad_antitop_);
//  DiMuEtaST_->Add(DiMuEtaST_tWNoHad_top_);
  DiMuEtaST_->Add(DiMuEtaST_tWIncl_antitop_);
  DiMuEtaST_->Add(DiMuEtaST_tWIncl_top_);
  DiMuEtaST_->Add(DiMuEtaST_tch_antitop_);
  DiMuEtaST_->Add(DiMuEtaST_tch_top_);

  DiMudRCanvasST->cd();
  DiMudRST_->Add(DiMudRST_sch_);
//  DiMudRST_->Add(DiMudRST_tWNoHad_antitop_);
//  DiMudRST_->Add(DiMudRST_tWNoHad_top_);
  DiMudRST_->Add(DiMudRST_tWIncl_antitop_);
  DiMudRST_->Add(DiMudRST_tWIncl_top_);
  DiMudRST_->Add(DiMudRST_tch_antitop_);
  DiMudRST_->Add(DiMudRST_tch_top_);

  DiMuPhiCanvasST->cd();
  DiMuPhiST_->Add(DiMuPhiST_sch_);
//  DiMuPhiST_->Add(DiMuPhiST_tWNoHad_antitop_);
//  DiMuPhiST_->Add(DiMuPhiST_tWNoHad_top_);
  DiMuPhiST_->Add(DiMuPhiST_tWIncl_antitop_);
  DiMuPhiST_->Add(DiMuPhiST_tWIncl_top_);
  DiMuPhiST_->Add(DiMuPhiST_tch_antitop_);
  DiMuPhiST_->Add(DiMuPhiST_tch_top_);

  EtMETCanvasST->cd();
  EtMETST_->Add(EtMETST_sch_);
//  EtMETST_->Add(EtMETST_tWNoHad_antitop_);
//  EtMETST_->Add(EtMETST_tWNoHad_top_);
  EtMETST_->Add(EtMETST_tWIncl_antitop_);
  EtMETST_->Add(EtMETST_tWIncl_top_);
  EtMETST_->Add(EtMETST_tch_antitop_);
  EtMETST_->Add(EtMETST_tch_top_);

  DiTauDiMuMassCanvasST->cd();
  DiTauDiMuMassST_->Add(DiTauDiMuMassST_sch_);
//  DiTauDiMuMassST_->Add(DiTauDiMuMassST_tWNoHad_antitop_);
//  DiTauDiMuMassST_->Add(DiTauDiMuMassST_tWNoHad_top_);
  DiTauDiMuMassST_->Add(DiTauDiMuMassST_tWIncl_antitop_);
  DiTauDiMuMassST_->Add(DiTauDiMuMassST_tWIncl_top_);
  DiTauDiMuMassST_->Add(DiTauDiMuMassST_tch_antitop_);
  DiTauDiMuMassST_->Add(DiTauDiMuMassST_tch_top_);

  DiMuDiTauDeltaPhiCanvasST->cd();
  DiMuDiTauDeltaPhiST_->Add(DiMuDiTauDeltaPhiST_sch_);
//  DiMuDiTauDeltaPhiST_->Add(DiMuDiTauDeltaPhiST_tWNoHad_antitop_);
//  DiMuDiTauDeltaPhiST_->Add(DiMuDiTauDeltaPhiST_tWNoHad_top_);
  DiMuDiTauDeltaPhiST_->Add(DiMuDiTauDeltaPhiST_tWIncl_antitop_);
  DiMuDiTauDeltaPhiST_->Add(DiMuDiTauDeltaPhiST_tWIncl_top_);
  DiMuDiTauDeltaPhiST_->Add(DiMuDiTauDeltaPhiST_tch_antitop_);
  DiMuDiTauDeltaPhiST_->Add(DiMuDiTauDeltaPhiST_tch_top_);

  METDiTauDeltaPhiCanvasST->cd();
  METDiTauDeltaPhiST_->Add(METDiTauDeltaPhiST_sch_);
//  METDiTauDeltaPhiST_->Add(METDiTauDeltaPhiST_tWNoHad_antitop_);
//  METDiTauDeltaPhiST_->Add(METDiTauDeltaPhiST_tWNoHad_top_);
  METDiTauDeltaPhiST_->Add(METDiTauDeltaPhiST_tWIncl_antitop_);
  METDiTauDeltaPhiST_->Add(METDiTauDeltaPhiST_tWIncl_top_);
  METDiTauDeltaPhiST_->Add(METDiTauDeltaPhiST_tch_antitop_);
  METDiTauDeltaPhiST_->Add(METDiTauDeltaPhiST_tch_top_);

  METDiMuDeltaPhiCanvasST->cd();
  METDiMuDeltaPhiST_->Add(METDiMuDeltaPhiST_sch_);
//  METDiMuDeltaPhiST_->Add(METDiMuDeltaPhiST_tWNoHad_antitop_);
//  METDiMuDeltaPhiST_->Add(METDiMuDeltaPhiST_tWNoHad_top_);
  METDiMuDeltaPhiST_->Add(METDiMuDeltaPhiST_tWIncl_antitop_);
  METDiMuDeltaPhiST_->Add(METDiMuDeltaPhiST_tWIncl_top_);
  METDiMuDeltaPhiST_->Add(METDiMuDeltaPhiST_tch_antitop_);
  METDiMuDeltaPhiST_->Add(METDiMuDeltaPhiST_tch_top_);

  DiTaudRCanvasST->cd();
  DiTaudRST_->Add(DiTaudRST_sch_);
//  DiTaudRST_->Add(DiTaudRST_tWNoHad_antitop_);
//  DiTaudRST_->Add(DiTaudRST_tWNoHad_top_);
  DiTaudRST_->Add(DiTaudRST_tWIncl_antitop_);
  DiTaudRST_->Add(DiTaudRST_tWIncl_top_);
  DiTaudRST_->Add(DiTaudRST_tch_antitop_);
  DiTaudRST_->Add(DiTaudRST_tch_top_);

  DiTauMassSmallerdRCanvasST->cd();
  DiTauMassSmallerdRST_->Add(DiTauMassSmallerdRST_sch_);
//  DiTauMassSmallerdRST_->Add(DiTauMassSmallerdRST_tWNoHad_antitop_);
//  DiTauMassSmallerdRST_->Add(DiTauMassSmallerdRST_tWNoHad_top_);
  DiTauMassSmallerdRST_->Add(DiTauMassSmallerdRST_tWIncl_antitop_);
  DiTauMassSmallerdRST_->Add(DiTauMassSmallerdRST_tWIncl_top_);
  DiTauMassSmallerdRST_->Add(DiTauMassSmallerdRST_tch_antitop_);
  DiTauMassSmallerdRST_->Add(DiTauMassSmallerdRST_tch_top_);

  ZMassdRCanvasST->cd();
  ZMassdRST_->Add(ZMassdRST_sch_);
//  ZMassdRST_->Add(ZMassdRST_tWNoHad_antitop_);
//  ZMassdRST_->Add(ZMassdRST_tWNoHad_top_);
  ZMassdRST_->Add(ZMassdRST_tWIncl_antitop_);
  ZMassdRST_->Add(ZMassdRST_tWIncl_top_);
  ZMassdRST_->Add(ZMassdRST_tch_antitop_);
  ZMassdRST_->Add(ZMassdRST_tch_top_);


  outFile->cd();
  TDirectory *STCombined = outFile->mkdir("STCombined");
  STCombined->cd();
  NMedIsoTausWithMu3ST_->Write();
  InvMassTauHadMu3ST_->Write();
  PtTauHadMu3ST_->Write();
  InvMassMu1TauMuST_->Write();
  InvMassMu2TauMuST_->Write();
  InvMassFullRangeST_->Write();
  InvMassDiMuBarrBarrST_->Write();
  InvMassDiMuBarrEndcST_->Write();
  InvMassDiMuEndcEndcST_->Write();
  Mu1PtST_->Write();
  Mu2PtST_->Write();
  DiMuPtST_->Write();
  Mu1EtaST_->Write();
  Mu2EtaST_->Write();
  DiTauEtaST_->Write();
  DiTauPhiST_->Write();
  DiMuEtaST_->Write();
  DiMudRST_->Write();
  DiMuPhiST_->Write();
  EtMETST_->Write();
  DiTauDiMuMassST_->Write();
  DiMuDiTauDeltaPhiST_->Write();
  METDiTauDeltaPhiST_->Write();
  METDiMuDeltaPhiST_->Write();
  DiTaudRST_->Write();
  DiTauMassSmallerdRST_->Write();
  ZMassdRST_->Write();

  std::cout << "ST Done" << std::endl;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the DiBoson Combined Canvas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *NMedIsoTausWithMu3CanvasDiBoson = new TCanvas ("NMedIsoTausWithMu3CanvasDiBoson","",600,600); 
  TCanvas *InvMassTauHadMu3CanvasDiBoson = new TCanvas ("InvMassTauHadMu3CanvasDiBoson","",600,600); 
  TCanvas *PtTauHadMu3CanvasDiBoson = new TCanvas ("PtTauHadMu3CanvasDiBoson","",600,600); 
  TCanvas *InvMassMu1TauMuCanvasDiBoson = new TCanvas ("InvMassMu1TauMuCanvasDiBoson","",600,600); 
  TCanvas *InvMassMu2TauMuCanvasDiBoson = new TCanvas ("InvMassMu2TauMuCanvasDiBoson","",600,600); 
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
  TCanvas *ZMassdRCanvasDiBoson = new TCanvas ("ZMassdRCanvasDiBoson","",600,600); 

  TH1F *NMedIsoTausWithMu3DiBoson_ = new TH1F ("NMedIsoTausWithMu3DiBoson","", NMedIsoTausWithMu3WJAmac_->GetNbinsX(), NMedIsoTausWithMu3WJAmac_->GetXaxis()->GetXmin(), NMedIsoTausWithMu3WJAmac_->GetXaxis()->GetXmax() );
  TH1F *InvMassTauHadMu3DiBoson_ = new TH1F ("InvMassTauHadMu3DiBoson","",InvMassTauHadMu3WJAmac_->GetNbinsX(), InvMassTauHadMu3WJAmac_->GetXaxis()->GetXmin(), InvMassTauHadMu3WJAmac_->GetXaxis()->GetXmax() );
  TH1F *PtTauHadMu3DiBoson_ = new TH1F ("PtTauHadMu3DiBoson","",PtTauHadMu3WJAmac_->GetNbinsX(), PtTauHadMu3WJAmac_->GetXaxis()->GetXmin(), PtTauHadMu3WJAmac_->GetXaxis()->GetXmax() );
  TH1F *InvMassMu1TauMuDiBoson_ = new TH1F ("InvMassMu1TauMuDiBoson","",InvMassMu1TauMuWJAmac_->GetNbinsX(), InvMassMu1TauMuWJAmac_->GetXaxis()->GetXmin(), InvMassMu1TauMuWJAmac_->GetXaxis()->GetXmax() );
  TH1F *InvMassMu2TauMuDiBoson_ = new TH1F ("InvMassMu2TauMuDiBoson","",InvMassMu2TauMuWJAmac_->GetNbinsX(), InvMassMu2TauMuWJAmac_->GetXaxis()->GetXmin(), InvMassMu2TauMuWJAmac_->GetXaxis()->GetXmax() );
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
  TH1F *ZMassdRDiBoson_ = new TH1F ("ZMassdRDiBoson","",ZMassdRWJAmac_->GetNbinsX(), ZMassdRWJAmac_->GetXaxis()->GetXmin(), ZMassdRWJAmac_->GetXaxis()->GetXmax() );


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

  InvMassMu1TauMuCanvasDiBoson->cd();
//  InvMassMu1TauMuDiBoson_->Add(InvMassMu1TauMuVV_);
  InvMassMu1TauMuDiBoson_->Add(InvMassMu1TauMuWZ_);
  InvMassMu1TauMuDiBoson_->Add(InvMassMu1TauMuZZ2L2Nu_);
  InvMassMu1TauMuDiBoson_->Add(InvMassMu1TauMuZZ2L2Q_);
  InvMassMu1TauMuDiBoson_->Add(InvMassMu1TauMuZZ4LAmac_);

  InvMassMu2TauMuCanvasDiBoson->cd();
//  InvMassMu2TauMuDiBoson_->Add(InvMassMu2TauMuVV_);
  InvMassMu2TauMuDiBoson_->Add(InvMassMu2TauMuWZ_);
  InvMassMu2TauMuDiBoson_->Add(InvMassMu2TauMuZZ2L2Nu_);
  InvMassMu2TauMuDiBoson_->Add(InvMassMu2TauMuZZ2L2Q_);
  InvMassMu2TauMuDiBoson_->Add(InvMassMu2TauMuZZ4LAmac_);

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

  ZMassdRCanvasDiBoson->cd();
//  ZMassdRDiBoson_->Add(ZMassdRVV_);
  ZMassdRDiBoson_->Add(ZMassdRWZ_);
  ZMassdRDiBoson_->Add(ZMassdRZZ2L2Nu_);
  ZMassdRDiBoson_->Add(ZMassdRZZ2L2Q_);
  ZMassdRDiBoson_->Add(ZMassdRZZ4LAmac_);

  outFile->cd();
  TDirectory *DiBosonCombined = outFile->mkdir("DiBosonCombined");
  DiBosonCombined->cd();
  NMedIsoTausWithMu3DiBoson_->Write();
  InvMassTauHadMu3DiBoson_->Write();
  PtTauHadMu3DiBoson_->Write();
  InvMassMu1TauMuDiBoson_->Write();
  InvMassMu2TauMuDiBoson_->Write();
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
  ZMassdRDiBoson_->Write();

cout << "Combined DiBoson" << endl;

  outFile->cd();

  outFile->cd();
  TDirectory *TTCombined = outFile->mkdir("TTCombined");
  TTCombined->cd();
  NMedIsoTausWithMu3TT_->Write();
  InvMassTauHadMu3TT_->Write();
  PtTauHadMu3TT_->Write();
  InvMassMu1TauMuTT_->Write();
  InvMassMu2TauMuTT_->Write();
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
  ZMassdRTT_->Write();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting Fill Colors
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  NMedIsoTausWithMu3h125a11_->SetLineColor(kGray+1);
  InvMassTauHadMu3h125a11_->SetLineColor(kGray+1);
  PtTauHadMu3h125a11_->SetLineColor(kGray+1);
  InvMassMu1TauMuh125a11_->SetLineColor(kGray+1);
  InvMassMu2TauMuh125a11_->SetLineColor(kGray+1);
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
  ZMassdRh125a11_->SetLineColor(kGray+1);

  ////////////////
  // h125a13
  ////////////////
  NMedIsoTausWithMu3h125a13_->SetLineColor(kGreen);
  InvMassTauHadMu3h125a13_->SetLineColor(kGreen);
  PtTauHadMu3h125a13_->SetLineColor(kGreen);
  InvMassMu1TauMuh125a13_->SetLineColor(kGreen);
  InvMassMu2TauMuh125a13_->SetLineColor(kGreen);
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
  ZMassdRh125a13_->SetLineColor(kGreen);

  ////////////////
  // h125a15
  ////////////////
  NMedIsoTausWithMu3h125a15_->SetLineColor(kTeal-1);
  InvMassTauHadMu3h125a15_->SetLineColor(kTeal-1);
  PtTauHadMu3h125a15_->SetLineColor(kTeal-1);
  InvMassMu1TauMuh125a15_->SetLineColor(kTeal-1);
  InvMassMu2TauMuh125a15_->SetLineColor(kTeal-1);
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
  ZMassdRh125a15_->SetLineColor(kTeal-1);

  ////////////////
  // h125a17
  ////////////////
  NMedIsoTausWithMu3h125a17_->SetLineColor(kCyan);
  InvMassTauHadMu3h125a17_->SetLineColor(kCyan);
  PtTauHadMu3h125a17_->SetLineColor(kCyan);
  InvMassMu1TauMuh125a17_->SetLineColor(kCyan);
  InvMassMu2TauMuh125a17_->SetLineColor(kCyan);
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
  ZMassdRh125a17_->SetLineColor(kCyan);

  ////////////////
  // h125a19
  ////////////////
  NMedIsoTausWithMu3h125a19_->SetLineColor(kAzure+3);
  InvMassTauHadMu3h125a19_->SetLineColor(kAzure+3);
  PtTauHadMu3h125a19_->SetLineColor(kAzure+3);
  InvMassMu1TauMuh125a19_->SetLineColor(kAzure+3);
  InvMassMu2TauMuh125a19_->SetLineColor(kAzure+3);
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
  ZMassdRh125a19_->SetLineColor(kAzure+3);

  ////////////////
  // h125a21
  ////////////////
  NMedIsoTausWithMu3h125a21_->SetLineColor(kBlue);
  InvMassTauHadMu3h125a21_->SetLineColor(kBlue);
  PtTauHadMu3h125a21_->SetLineColor(kBlue);
  InvMassMu1TauMuh125a21_->SetLineColor(kBlue);
  InvMassMu2TauMuh125a21_->SetLineColor(kBlue);
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
  ZMassdRh125a21_->SetLineColor(kBlue);

  ////////////////
  // h125a5
  ////////////////
  NMedIsoTausWithMu3h125a5_->SetLineColor(kSpring-7);
  InvMassTauHadMu3h125a5_->SetLineColor(kSpring-7);
  PtTauHadMu3h125a5_->SetLineColor(kSpring-7);
  InvMassMu1TauMuh125a5_->SetLineColor(kSpring-7);
  InvMassMu2TauMuh125a5_->SetLineColor(kSpring-7);
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
  ZMassdRh125a5_->SetLineColor(kSpring-7);

  ////////////////
  // h125a7
  ////////////////
  NMedIsoTausWithMu3h125a7_->SetLineColor(kYellow+1);
  InvMassTauHadMu3h125a7_->SetLineColor(kYellow+1);
  PtTauHadMu3h125a7_->SetLineColor(kYellow+1);
  InvMassMu1TauMuh125a7_->SetLineColor(kYellow+1);
  InvMassMu2TauMuh125a7_->SetLineColor(kYellow+1);
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
  ZMassdRh125a7_->SetLineColor(kYellow+1);

  ////////////////
  // h125a9
  ////////////////
  NMedIsoTausWithMu3h125a9_->SetLineColor(kOrange+9);
  InvMassTauHadMu3h125a9_->SetLineColor(kOrange+9);
  PtTauHadMu3h125a9_->SetLineColor(kOrange+9);
  InvMassMu1TauMuh125a9_->SetLineColor(kOrange+9);
  InvMassMu2TauMuh125a9_->SetLineColor(kOrange+9);
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
  ZMassdRh125a9_->SetLineColor(kOrange+9);

  ////////////////
  // h300a11
  ////////////////
  NMedIsoTausWithMu3h300a11_->SetLineColor(kGray+1);
  InvMassTauHadMu3h300a11_->SetLineColor(kGray+1);
  PtTauHadMu3h300a11_->SetLineColor(kGray+1);
  InvMassMu1TauMuh300a11_->SetLineColor(kGray+1);
  InvMassMu2TauMuh300a11_->SetLineColor(kGray+1);
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
  ZMassdRh300a11_->SetLineColor(kGray+1);

  ////////////////
  // h300a13
  ////////////////
  NMedIsoTausWithMu3h300a13_->SetLineColor(kGreen);
  InvMassTauHadMu3h300a13_->SetLineColor(kGreen);
  PtTauHadMu3h300a13_->SetLineColor(kGreen);
  InvMassMu1TauMuh300a13_->SetLineColor(kGreen);
  InvMassMu2TauMuh300a13_->SetLineColor(kGreen);
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
  ZMassdRh300a13_->SetLineColor(kGreen);

  ////////////////
  // h300a15
  ////////////////
  NMedIsoTausWithMu3h300a15_->SetLineColor(kTeal-1);
  InvMassTauHadMu3h300a15_->SetLineColor(kTeal-1);
  PtTauHadMu3h300a15_->SetLineColor(kTeal-1);
  InvMassMu1TauMuh300a15_->SetLineColor(kTeal-1);
  InvMassMu2TauMuh300a15_->SetLineColor(kTeal-1);
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
  ZMassdRh300a15_->SetLineColor(kTeal-1);

  ////////////////
  // h300a17
  ////////////////
  NMedIsoTausWithMu3h300a17_->SetLineColor(kCyan);
  InvMassTauHadMu3h300a17_->SetLineColor(kCyan);
  PtTauHadMu3h300a17_->SetLineColor(kCyan);
  InvMassMu1TauMuh300a17_->SetLineColor(kCyan);
  InvMassMu2TauMuh300a17_->SetLineColor(kCyan);
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
  ZMassdRh300a17_->SetLineColor(kCyan);

  ////////////////
  // h300a19
  ////////////////
  NMedIsoTausWithMu3h300a19_->SetLineColor(kAzure+3);
  InvMassTauHadMu3h300a19_->SetLineColor(kAzure+3);
  PtTauHadMu3h300a19_->SetLineColor(kAzure+3);
  InvMassMu1TauMuh300a19_->SetLineColor(kAzure+3);
  InvMassMu2TauMuh300a19_->SetLineColor(kAzure+3);
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
  ZMassdRh300a19_->SetLineColor(kAzure+3);

  ////////////////
  // h300a21
  ////////////////
  NMedIsoTausWithMu3h300a21_->SetLineColor(kBlue);
  InvMassTauHadMu3h300a21_->SetLineColor(kBlue);
  PtTauHadMu3h300a21_->SetLineColor(kBlue);
  InvMassMu1TauMuh300a21_->SetLineColor(kBlue);
  InvMassMu2TauMuh300a21_->SetLineColor(kBlue);
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
  ZMassdRh300a21_->SetLineColor(kBlue);

  ////////////////
  // h300a5
  ////////////////
  NMedIsoTausWithMu3h300a5_->SetLineColor(kSpring-7);
  InvMassTauHadMu3h300a5_->SetLineColor(kSpring-7);
  PtTauHadMu3h300a5_->SetLineColor(kSpring-7);
  InvMassMu1TauMuh300a5_->SetLineColor(kSpring-7);
  InvMassMu2TauMuh300a5_->SetLineColor(kSpring-7);
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
  ZMassdRh300a5_->SetLineColor(kSpring-7);

  ////////////////
  // h300a7
  ////////////////
  NMedIsoTausWithMu3h300a7_->SetLineColor(kYellow+1);
  InvMassTauHadMu3h300a7_->SetLineColor(kYellow+1);
  PtTauHadMu3h300a7_->SetLineColor(kYellow+1);
  InvMassMu1TauMuh300a7_->SetLineColor(kYellow+1);
  InvMassMu2TauMuh300a7_->SetLineColor(kYellow+1);
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
  ZMassdRh300a7_->SetLineColor(kYellow+1);

  ////////////////
  // h300a9
  ////////////////
  NMedIsoTausWithMu3h300a9_->SetLineColor(kOrange+9);
  InvMassTauHadMu3h300a9_->SetLineColor(kOrange+9);
  PtTauHadMu3h300a9_->SetLineColor(kOrange+9);
  InvMassMu1TauMuh300a9_->SetLineColor(kOrange+9);
  InvMassMu2TauMuh300a9_->SetLineColor(kOrange+9);
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
  ZMassdRh300a9_->SetLineColor(kOrange+9);

  ////////////////
  // h750a11
  ////////////////
  NMedIsoTausWithMu3h750a11_->SetLineColor(kGray+1);
  InvMassTauHadMu3h750a11_->SetLineColor(kGray+1);
  PtTauHadMu3h750a11_->SetLineColor(kGray+1);
  InvMassMu1TauMuh750a11_->SetLineColor(kGray+1);
  InvMassMu2TauMuh750a11_->SetLineColor(kGray+1);
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
  ZMassdRh750a11_->SetLineColor(kGray+1);

  ////////////////
  // h750a13
  ////////////////
  NMedIsoTausWithMu3h750a13_->SetLineColor(kGreen);
  InvMassTauHadMu3h750a13_->SetLineColor(kGreen);
  PtTauHadMu3h750a13_->SetLineColor(kGreen);
  InvMassMu1TauMuh750a13_->SetLineColor(kGreen);
  InvMassMu2TauMuh750a13_->SetLineColor(kGreen);
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
  ZMassdRh750a13_->SetLineColor(kGreen);

  ////////////////
  // h750a15
  ////////////////
  NMedIsoTausWithMu3h750a15_->SetLineColor(kTeal-1);
  InvMassTauHadMu3h750a15_->SetLineColor(kTeal-1);
  PtTauHadMu3h750a15_->SetLineColor(kTeal-1);
  InvMassMu1TauMuh750a15_->SetLineColor(kTeal-1);
  InvMassMu2TauMuh750a15_->SetLineColor(kTeal-1);
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
  ZMassdRh750a15_->SetLineColor(kTeal-1);

  ////////////////
  // h750a17
  ////////////////
  NMedIsoTausWithMu3h750a17_->SetLineColor(kCyan);
  InvMassTauHadMu3h750a17_->SetLineColor(kCyan);
  PtTauHadMu3h750a17_->SetLineColor(kCyan);
  InvMassMu1TauMuh750a17_->SetLineColor(kCyan);
  InvMassMu2TauMuh750a17_->SetLineColor(kCyan);
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
  ZMassdRh750a17_->SetLineColor(kCyan);

  ////////////////
  // h750a19
  ////////////////
  NMedIsoTausWithMu3h750a19_->SetLineColor(kAzure+3);
  InvMassTauHadMu3h750a19_->SetLineColor(kAzure+3);
  PtTauHadMu3h750a19_->SetLineColor(kAzure+3);
  InvMassMu1TauMuh750a19_->SetLineColor(kAzure+3);
  InvMassMu2TauMuh750a19_->SetLineColor(kAzure+3);
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
  ZMassdRh750a19_->SetLineColor(kAzure+3);

  ////////////////
  // h750a21
  ////////////////
  NMedIsoTausWithMu3h750a21_->SetLineColor(kBlue);
  InvMassTauHadMu3h750a21_->SetLineColor(kBlue);
  PtTauHadMu3h750a21_->SetLineColor(kBlue);
  InvMassMu1TauMuh750a21_->SetLineColor(kBlue);
  InvMassMu2TauMuh750a21_->SetLineColor(kBlue);
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
  ZMassdRh750a21_->SetLineColor(kBlue);

  ////////////////
  // h750a5
  ////////////////
  NMedIsoTausWithMu3h750a5_->SetLineColor(kSpring-7);
  InvMassTauHadMu3h750a5_->SetLineColor(kSpring-7);
  PtTauHadMu3h750a5_->SetLineColor(kSpring-7);
  InvMassMu1TauMuh750a5_->SetLineColor(kSpring-7);
  InvMassMu2TauMuh750a5_->SetLineColor(kSpring-7);
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
  ZMassdRh750a5_->SetLineColor(kSpring-7);

  ////////////////
  // h750a7
  ////////////////
  NMedIsoTausWithMu3h750a7_->SetLineColor(kYellow+1);
  InvMassTauHadMu3h750a7_->SetLineColor(kYellow+1);
  PtTauHadMu3h750a7_->SetLineColor(kYellow+1);
  InvMassMu1TauMuh750a7_->SetLineColor(kYellow+1);
  InvMassMu2TauMuh750a7_->SetLineColor(kYellow+1);
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
  ZMassdRh750a7_->SetLineColor(kYellow+1);

  ////////////////
  // h750a9
  ////////////////
  NMedIsoTausWithMu3h750a9_->SetLineColor(kOrange+9);
  InvMassTauHadMu3h750a9_->SetLineColor(kOrange+9);
  PtTauHadMu3h750a9_->SetLineColor(kOrange+9);
  InvMassMu1TauMuh750a9_->SetLineColor(kOrange+9);
  InvMassMu2TauMuh750a9_->SetLineColor(kOrange+9);
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
  ZMassdRh750a9_->SetLineColor(kOrange+9);

  ////////////////
  // QCD
  ////////////////
  NMedIsoTausWithMu3QCD_->SetLineColor(kViolet+2);
  InvMassTauHadMu3QCD_->SetLineColor(kViolet+2);
  PtTauHadMu3QCD_->SetLineColor(kViolet+2);
  InvMassMu1TauMuQCD_->SetLineColor(kViolet+2);
  InvMassMu2TauMuQCD_->SetLineColor(kViolet+2);
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
  ZMassdRQCD_->SetLineColor(kViolet+2);

  ////////////////
  // DiBoson
  ////////////////
  NMedIsoTausWithMu3DiBoson_->SetLineColor(kPink+1);
  InvMassTauHadMu3DiBoson_->SetLineColor(kPink+1);
  PtTauHadMu3DiBoson_->SetLineColor(kPink+1);
  InvMassMu1TauMuDiBoson_->SetLineColor(kPink+1);
  InvMassMu2TauMuDiBoson_->SetLineColor(kPink+1);
  InvMassFullRangeDiBoson_->SetLineColor(kPink+1);
  InvMassDiMuBarrBarrDiBoson_->SetLineColor(kPink+1);
  InvMassDiMuBarrEndcDiBoson_->SetLineColor(kPink+1);
  InvMassDiMuEndcEndcDiBoson_->SetLineColor(kPink+1);
  Mu1PtDiBoson_->SetLineColor(kPink+1);
  Mu2PtDiBoson_->SetLineColor(kPink+1);
  DiMuPtDiBoson_->SetLineColor(kPink+1);
  Mu1EtaDiBoson_->SetLineColor(kPink+1);
  Mu2EtaDiBoson_->SetLineColor(kPink+1);
  DiTauEtaDiBoson_->SetLineColor(kPink+1);
  DiTauPhiDiBoson_->SetLineColor(kPink+1);
  DiMuEtaDiBoson_->SetLineColor(kPink+1);
  DiMudRDiBoson_->SetLineColor(kPink+1);
  DiMuPhiDiBoson_->SetLineColor(kPink+1);
  EtMETDiBoson_->SetLineColor(kPink+1);
  DiTauDiMuMassDiBoson_->SetLineColor(kPink+1);
  DiMuDiTauDeltaPhiDiBoson_->SetLineColor(kPink+1);
  METDiTauDeltaPhiDiBoson_->SetLineColor(kPink+1);
  METDiMuDeltaPhiDiBoson_->SetLineColor(kPink+1);
  DiTaudRDiBoson_->SetLineColor(kPink+1);
  DiTauMassSmallerdRDiBoson_->SetLineColor(kPink+1);
  ZMassdRDiBoson_->SetLineColor(kPink+1);

  ////////////////
  // ST
  ////////////////
  NMedIsoTausWithMu3ST_->SetLineColor(kViolet-3);
  InvMassTauHadMu3ST_->SetLineColor(kViolet-3);
  PtTauHadMu3ST_->SetLineColor(kViolet-3);
  InvMassMu1TauMuST_->SetLineColor(kViolet-3);
  InvMassMu2TauMuST_->SetLineColor(kViolet-3);
  InvMassFullRangeST_->SetLineColor(kViolet-3);
  InvMassDiMuBarrBarrST_->SetLineColor(kViolet-3);
  InvMassDiMuBarrEndcST_->SetLineColor(kViolet-3);
  InvMassDiMuEndcEndcST_->SetLineColor(kViolet-3);
  Mu1PtST_->SetLineColor(kViolet-3);
  Mu2PtST_->SetLineColor(kViolet-3);
  DiMuPtST_->SetLineColor(kViolet-3);
  Mu1EtaST_->SetLineColor(kViolet-3);
  Mu2EtaST_->SetLineColor(kViolet-3);
  DiTauEtaST_->SetLineColor(kViolet-3);
  DiTauPhiST_->SetLineColor(kViolet-3);
  DiMuEtaST_->SetLineColor(kViolet-3);
  DiMudRST_->SetLineColor(kViolet-3);
  DiMuPhiST_->SetLineColor(kViolet-3);
  EtMETST_->SetLineColor(kViolet-3);
  DiTauDiMuMassST_->SetLineColor(kViolet-3);
  DiMuDiTauDeltaPhiST_->SetLineColor(kViolet-3);
  METDiTauDeltaPhiST_->SetLineColor(kViolet-3);
  METDiMuDeltaPhiST_->SetLineColor(kViolet-3);
  DiTaudRST_->SetLineColor(kViolet-3);
  DiTauMassSmallerdRST_->SetLineColor(kViolet-3);
  ZMassdRST_->SetLineColor(kViolet-3);

  ////////////////
  // DY
  ////////////////
  NMedIsoTausWithMu3DY_->SetLineColor(kGray);
  InvMassTauHadMu3DY_->SetLineColor(kGray);
  PtTauHadMu3DY_->SetLineColor(kGray);
  InvMassMu1TauMuDY_->SetLineColor(kGray);
  InvMassMu2TauMuDY_->SetLineColor(kGray);
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
  ZMassdRDY_->SetLineColor(kGray);

  ////////////////
  ////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting Fill Color
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////
  // QCD
  ////////////////
  NMedIsoTausWithMu3TT_->SetFillColor(kRed);
  InvMassTauHadMu3TT_->SetFillColor(kRed);
  PtTauHadMu3TT_->SetFillColor(kRed);
  InvMassMu1TauMuTT_->SetFillColor(kRed);
  InvMassMu2TauMuTT_->SetFillColor(kRed);
  InvMassFullRangeTT_->SetFillColor(kRed);
  InvMassDiMuBarrBarrTT_->SetFillColor(kRed);
  InvMassDiMuBarrEndcTT_->SetFillColor(kRed);
  InvMassDiMuEndcEndcTT_->SetFillColor(kRed);
  Mu1PtTT_->SetFillColor(kRed);
  Mu2PtTT_->SetFillColor(kRed);
  DiMuPtTT_->SetFillColor(kRed);
  Mu1EtaTT_->SetFillColor(kRed);
  Mu2EtaTT_->SetFillColor(kRed);
  DiTauEtaTT_->SetFillColor(kRed);
  DiTauPhiTT_->SetFillColor(kRed);
  DiMuEtaTT_->SetFillColor(kRed);
  DiMudRTT_->SetFillColor(kRed);
  DiMuPhiTT_->SetFillColor(kRed);
  EtMETTT_->SetFillColor(kRed);
  DiTauDiMuMassTT_->SetFillColor(kRed);
  DiMuDiTauDeltaPhiTT_->SetFillColor(kRed);
  METDiTauDeltaPhiTT_->SetFillColor(kRed);
  METDiMuDeltaPhiTT_->SetFillColor(kRed);
  DiTaudRTT_->SetFillColor(kRed);
  DiTauMassSmallerdRTT_->SetFillColor(kRed);
  ZMassdRTT_->SetFillColor(kRed);

  ////////////////
  // QCD
  ////////////////
  NMedIsoTausWithMu3QCD_->SetFillColor(kViolet+2);
  InvMassTauHadMu3QCD_->SetFillColor(kViolet+2);
  PtTauHadMu3QCD_->SetFillColor(kViolet+2);
  InvMassMu1TauMuQCD_->SetFillColor(kViolet+2);
  InvMassMu2TauMuQCD_->SetFillColor(kViolet+2);
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
  ZMassdRQCD_->SetFillColor(kViolet+2);

  ////////////////
  // DiBoson
  ////////////////
  NMedIsoTausWithMu3DiBoson_->SetFillColor(kPink+1);
  InvMassTauHadMu3DiBoson_->SetFillColor(kPink+1);
  PtTauHadMu3DiBoson_->SetFillColor(kPink+1);
  InvMassMu1TauMuDiBoson_->SetFillColor(kPink+1);
  InvMassMu2TauMuDiBoson_->SetFillColor(kPink+1);
  InvMassFullRangeDiBoson_->SetFillColor(kPink+1);
  InvMassDiMuBarrBarrDiBoson_->SetFillColor(kPink+1);
  InvMassDiMuBarrEndcDiBoson_->SetFillColor(kPink+1);
  InvMassDiMuEndcEndcDiBoson_->SetFillColor(kPink+1);
  Mu1PtDiBoson_->SetFillColor(kPink+1);
  Mu2PtDiBoson_->SetFillColor(kPink+1);
  DiMuPtDiBoson_->SetFillColor(kPink+1);
  Mu1EtaDiBoson_->SetFillColor(kPink+1);
  Mu2EtaDiBoson_->SetFillColor(kPink+1);
  DiTauEtaDiBoson_->SetFillColor(kPink+1);
  DiTauPhiDiBoson_->SetFillColor(kPink+1);
  DiMuEtaDiBoson_->SetFillColor(kPink+1);
  DiMudRDiBoson_->SetFillColor(kPink+1);
  DiMuPhiDiBoson_->SetFillColor(kPink+1);
  EtMETDiBoson_->SetFillColor(kPink+1);
  DiTauDiMuMassDiBoson_->SetFillColor(kPink+1);
  DiMuDiTauDeltaPhiDiBoson_->SetFillColor(kPink+1);
  METDiTauDeltaPhiDiBoson_->SetFillColor(kPink+1);
  METDiMuDeltaPhiDiBoson_->SetFillColor(kPink+1);
  DiTaudRDiBoson_->SetFillColor(kPink+1);
  DiTauMassSmallerdRDiBoson_->SetFillColor(kPink+1);
  ZMassdRDiBoson_->SetFillColor(kPink+1);

  ////////////////
  // ST
  ////////////////
  NMedIsoTausWithMu3ST_->SetFillColor(kViolet-3);
  InvMassTauHadMu3ST_->SetFillColor(kViolet-3);
  PtTauHadMu3ST_->SetFillColor(kViolet-3);
  InvMassMu1TauMuST_->SetFillColor(kViolet-3);
  InvMassMu2TauMuST_->SetFillColor(kViolet-3);
  InvMassFullRangeST_->SetFillColor(kViolet-3);
  InvMassDiMuBarrBarrST_->SetFillColor(kViolet-3);
  InvMassDiMuBarrEndcST_->SetFillColor(kViolet-3);
  InvMassDiMuEndcEndcST_->SetFillColor(kViolet-3);
  Mu1PtST_->SetFillColor(kViolet-3);
  Mu2PtST_->SetFillColor(kViolet-3);
  DiMuPtST_->SetFillColor(kViolet-3);
  Mu1EtaST_->SetFillColor(kViolet-3);
  Mu2EtaST_->SetFillColor(kViolet-3);
  DiTauEtaST_->SetFillColor(kViolet-3);
  DiTauPhiST_->SetFillColor(kViolet-3);
  DiMuEtaST_->SetFillColor(kViolet-3);
  DiMudRST_->SetFillColor(kViolet-3);
  DiMuPhiST_->SetFillColor(kViolet-3);
  EtMETST_->SetFillColor(kViolet-3);
  DiTauDiMuMassST_->SetFillColor(kViolet-3);
  DiMuDiTauDeltaPhiST_->SetFillColor(kViolet-3);
  METDiTauDeltaPhiST_->SetFillColor(kViolet-3);
  METDiMuDeltaPhiST_->SetFillColor(kViolet-3);
  DiTaudRST_->SetFillColor(kViolet-3);
  DiTauMassSmallerdRST_->SetFillColor(kViolet-3);
  ZMassdRST_->SetFillColor(kViolet-3);


  ////////////////
  // DY
  ////////////////
  NMedIsoTausWithMu3DY_->SetFillColor(kGray);
  InvMassTauHadMu3DY_->SetFillColor(kGray);
  PtTauHadMu3DY_->SetFillColor(kGray);
  InvMassMu1TauMuDY_->SetFillColor(kGray);
  InvMassMu2TauMuDY_->SetFillColor(kGray);
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
  ZMassdRDY_->SetFillColor(kGray);

  ////////////////
  // DY
  ////////////////
  NMedIsoTausWithMu3DY_->SetFillColor(kGray);
  InvMassTauHadMu3DY_->SetFillColor(kGray);
  PtTauHadMu3DY_->SetFillColor(kGray);
  InvMassMu1TauMuDY_->SetFillColor(kGray);
  InvMassMu2TauMuDY_->SetFillColor(kGray);
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
  ZMassdRDY_->SetFillColor(kGray);

cout << "Set Colors" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Making the stack
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  THStack *NMedIsoTausWithMu3Stack = new THStack ("NMedIsoTausWithMu3Stack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *InvMassTauHadMu3Stack = new THStack ("InvMassTauHadMu3Stack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *PtTauHadMu3Stack = new THStack ("PtTauHadMu3Stack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *InvMassMu1TauMuStack = new THStack ("InvMassMu1TauMuStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *InvMassMu2TauMuStack = new THStack ("InvMassMu1TauMuStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *InvMassFullRangeStack = new THStack ("InvMassFullRangeStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *InvMassDiMuBarrBarrStack = new THStack ("InvMassDiMuBarrBarrStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *InvMassDiMuBarrEndcStack = new THStack ("InvMassDiMuBarrEndcStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *InvMassDiMuEndcEndcStack = new THStack ("InvMassDiMuEndcEndcStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *Mu1PtStack = new THStack ("Mu1PtStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *Mu2PtStack = new THStack ("Mu2PtStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *DiMuPtStack = new THStack ("DiMuPtStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *Mu1EtaStack = new THStack ("Mu1EtaStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *Mu2EtaStack = new THStack ("Mu2EtaStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *DiTauEtaStack = new THStack ("DiTauEtaStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *DiTauPhiStack = new THStack ("DiTauPhiStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *DiMuEtaStack = new THStack ("DiMuEtaStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *DiMudRStack = new THStack ("DiMudRStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *DiMuPhiStack = new THStack ("DiMuPhiStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *EtMETStack = new THStack ("EtMETStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *DiTauDiMuMassStack = new THStack ("DiTauDiMuMassStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *DiMuDiTauDeltaPhiStack = new THStack ("DiMuDiTauDeltaPhiStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *METDiTauDeltaPhiStack = new THStack ("METDiTauDeltaPhiStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *METDiMuDeltaPhiStack = new THStack ("METDiMuDeltaPhiStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *DiTaudRStack = new THStack ("DiTaudRStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *DiTauMassSmallerdRStack = new THStack ("DiTauMassSmallerdRStack","Iso(#mu_{2}) Iso(#tau#tau)");
  THStack *ZMassdRStack = new THStack ("ZMassdRStack","Iso(#mu_{2}) Iso(#tau#tau)");
 
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3QCD_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3ST_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3DiBoson_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3DY_);
  NMedIsoTausWithMu3Stack->Add(NMedIsoTausWithMu3TT_);

  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3QCD_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3ST_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3DiBoson_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3DY_);
  InvMassTauHadMu3Stack->Add(InvMassTauHadMu3TT_);

  PtTauHadMu3Stack->Add(PtTauHadMu3QCD_);
  PtTauHadMu3Stack->Add(PtTauHadMu3ST_);
  PtTauHadMu3Stack->Add(PtTauHadMu3DiBoson_);
  PtTauHadMu3Stack->Add(PtTauHadMu3DY_);
  PtTauHadMu3Stack->Add(PtTauHadMu3TT_);

  InvMassMu1TauMuStack->Add(InvMassMu1TauMuQCD_);
  InvMassMu1TauMuStack->Add(InvMassMu1TauMuST_);
  InvMassMu1TauMuStack->Add(InvMassMu1TauMuDiBoson_);
  InvMassMu1TauMuStack->Add(InvMassMu1TauMuDY_);
  InvMassMu1TauMuStack->Add(InvMassMu1TauMuTT_);

  InvMassMu2TauMuStack->Add(InvMassMu2TauMuQCD_);
  InvMassMu2TauMuStack->Add(InvMassMu2TauMuST_);
  InvMassMu2TauMuStack->Add(InvMassMu2TauMuDiBoson_);
  InvMassMu2TauMuStack->Add(InvMassMu2TauMuDY_);
  InvMassMu2TauMuStack->Add(InvMassMu2TauMuTT_);

  InvMassFullRangeStack->Add(InvMassFullRangeQCD_);
  InvMassFullRangeStack->Add(InvMassFullRangeST_);
  InvMassFullRangeStack->Add(InvMassFullRangeDiBoson_);
  InvMassFullRangeStack->Add(InvMassFullRangeDY_);
  InvMassFullRangeStack->Add(InvMassFullRangeTT_);

  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrQCD_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrST_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrDiBoson_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrDY_);
  InvMassDiMuBarrBarrStack->Add(InvMassDiMuBarrBarrTT_);

  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndcQCD_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndcST_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndcDiBoson_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndcDY_);
  InvMassDiMuBarrEndcStack->Add(InvMassDiMuBarrEndcTT_);

  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndcQCD_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndcST_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndcDiBoson_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndcDY_);
  InvMassDiMuEndcEndcStack->Add(InvMassDiMuEndcEndcTT_);

  Mu1PtStack->Add(Mu1PtQCD_);
  Mu1PtStack->Add(Mu1PtST_);
  Mu1PtStack->Add(Mu1PtDiBoson_);
  Mu1PtStack->Add(Mu1PtDY_);
  Mu1PtStack->Add(Mu1PtTT_);

  Mu2PtStack->Add(Mu2PtQCD_);
  Mu2PtStack->Add(Mu2PtST_);
  Mu2PtStack->Add(Mu2PtDiBoson_);
  Mu2PtStack->Add(Mu2PtDY_);
  Mu2PtStack->Add(Mu2PtTT_);

  DiMuPtStack->Add(DiMuPtQCD_);
  DiMuPtStack->Add(DiMuPtST_);
  DiMuPtStack->Add(DiMuPtDiBoson_);
  DiMuPtStack->Add(DiMuPtDY_);
  DiMuPtStack->Add(DiMuPtTT_);

  Mu1EtaStack->Add(Mu1EtaQCD_);
  Mu1EtaStack->Add(Mu1EtaST_);
  Mu1EtaStack->Add(Mu1EtaDiBoson_);
  Mu1EtaStack->Add(Mu1EtaDY_);
  Mu1EtaStack->Add(Mu1EtaTT_);

  Mu2EtaStack->Add(Mu2EtaQCD_);
  Mu2EtaStack->Add(Mu2EtaST_);
  Mu2EtaStack->Add(Mu2EtaDiBoson_);
  Mu2EtaStack->Add(Mu2EtaDY_);
  Mu2EtaStack->Add(Mu2EtaTT_);

  DiTauEtaStack->Add(DiTauEtaQCD_);
  DiTauEtaStack->Add(DiTauEtaST_);
  DiTauEtaStack->Add(DiTauEtaDiBoson_);
  DiTauEtaStack->Add(DiTauEtaDY_);
  DiTauEtaStack->Add(DiTauEtaTT_);

  DiTauPhiStack->Add(DiTauPhiQCD_);
  DiTauPhiStack->Add(DiTauPhiST_);
  DiTauPhiStack->Add(DiTauPhiDiBoson_);
  DiTauPhiStack->Add(DiTauPhiDY_);
  DiTauPhiStack->Add(DiTauPhiTT_);

  DiMuEtaStack->Add(DiMuEtaQCD_);
  DiMuEtaStack->Add(DiMuEtaST_);
  DiMuEtaStack->Add(DiMuEtaDiBoson_);
  DiMuEtaStack->Add(DiMuEtaDY_);
  DiMuEtaStack->Add(DiMuEtaTT_);

  DiMudRStack->Add(DiMudRQCD_);
  DiMudRStack->Add(DiMudRST_);
  DiMudRStack->Add(DiMudRDiBoson_);
  DiMudRStack->Add(DiMudRDY_);
  DiMudRStack->Add(DiMudRTT_);

  DiMuPhiStack->Add(DiMuPhiQCD_);
  DiMuPhiStack->Add(DiMuPhiST_);
  DiMuPhiStack->Add(DiMuPhiDiBoson_);
  DiMuPhiStack->Add(DiMuPhiDY_);
  DiMuPhiStack->Add(DiMuPhiTT_);

  EtMETStack->Add(EtMETQCD_);
  EtMETStack->Add(EtMETST_);
  EtMETStack->Add(EtMETDiBoson_);
  EtMETStack->Add(EtMETDY_);
  EtMETStack->Add(EtMETTT_);

  DiTauDiMuMassStack->Add(DiTauDiMuMassQCD_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassST_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassDiBoson_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassDY_);
  DiTauDiMuMassStack->Add(DiTauDiMuMassTT_);

  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhiQCD_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhiST_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhiDiBoson_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhiDY_);
  DiMuDiTauDeltaPhiStack->Add(DiMuDiTauDeltaPhiTT_);

  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhiQCD_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhiST_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhiDiBoson_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhiDY_);
  METDiTauDeltaPhiStack->Add(METDiTauDeltaPhiTT_);

  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhiQCD_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhiST_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhiDiBoson_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhiDY_);
  METDiMuDeltaPhiStack->Add(METDiMuDeltaPhiTT_);


  DiTaudRStack->Add(DiTaudRQCD_);
  DiTaudRStack->Add(DiTaudRST_);
  DiTaudRStack->Add(DiTaudRDiBoson_);
  DiTaudRStack->Add(DiTaudRDY_);
  DiTaudRStack->Add(DiTaudRTT_);

  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRQCD_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRST_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRDiBoson_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRDY_);
  DiTauMassSmallerdRStack->Add(DiTauMassSmallerdRTT_);

  ZMassdRStack->Add(ZMassdRQCD_);
  ZMassdRStack->Add(ZMassdRST_);
  ZMassdRStack->Add(ZMassdRDiBoson_);
  ZMassdRStack->Add(ZMassdRDY_);
  ZMassdRStack->Add(ZMassdRTT_);

cout << "Created and Added Stacks" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prepping the output plots
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
  TCanvas *ZMassdRCanvas = new TCanvas ("ZMassdRCanvas","",600,600);

//  TPad *NMedIsoTausWithMu3PlotPad = new TPad ("NMedIsoTausWithMu3PlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *InvMassTauHadMu3PlotPad = new TPad ("InvMassTauHadMu3PlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *PtTauHadMu3PlotPad = new TPad ("PtTauHadMu3PlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *InvMassMu1TauMuPlotPad = new TPad ("InvMassMu1TauMuPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *InvMassMu2TauMuPlotPad = new TPad ("InvMassMu1TauMuPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *InvMassFullRangePlotPad = new TPad ("InvMassFullRangePlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *InvMassDiMuBarrBarrPlotPad = new TPad ("InvMassDiMuBarrBarrPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *InvMassDiMuBarrEndcPlotPad = new TPad ("InvMassDiMuBarrEndcPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *InvMassDiMuEndcEndcPlotPad = new TPad ("InvMassDiMuEndcEndcPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *Mu1PtPlotPad = new TPad ("Mu1PtPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *Mu2PtPlotPad = new TPad ("Mu2PtPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *DiMuPtPlotPad = new TPad ("DiMuPtPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *Mu1EtaPlotPad = new TPad ("Mu1EtaPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *Mu2EtaPlotPad = new TPad ("Mu2EtaPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *DiTauEtaPlotPad = new TPad ("DiTauEtaPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *DiTauPhiPlotPad = new TPad ("DiTauPhiPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *DiMuEtaPlotPad = new TPad ("DiMuEtaPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *DiMudRPlotPad = new TPad ("DiMudRPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *DiMuPhiPlotPad = new TPad ("DiMuPhiPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *EtMETPlotPad = new TPad ("EtMETPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *DiTauDiMuMassPlotPad = new TPad ("DiTauDiMuMassPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *DiMuDiTauDeltaPhiPlotPad = new TPad ("DiMuDiTauDeltaPhiPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *METDiTauDeltaPhiPlotPad = new TPad ("METDiTauDeltaPhiPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *METDiMuDeltaPhiPlotPad = new TPad ("METDiMuDeltaPhiPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *DiTaudRPlotPad = new TPad ("DiTaudRPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *DiTauMassSmallerdRPlotPad = new TPad ("DiTauMassSmallerdRPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);
//  TPad *ZMassdRPlotPad = new TPad ("ZMassdRPlotPad", "top pad", 0.0, 0.21, 1.0, 1.0);

////  NMedIsoTausWithMu3PlotPad->SetBottomMargin(0.04);
////  InvMassTauHadMu3PlotPad->SetBottomMargin(0.04);
////  PtTauHadMu3PlotPad->SetBottomMargin(0.04);
////  InvMassMu1TauMuPlotPad->SetBottomMargin(0.04);
////  InvMassMu2TauMuPlotPad->SetBottomMargin(0.04);
////  InvMassFullRangePlotPad->SetBottomMargin(0.04);
////  InvMassDiMuBarrBarrPlotPad->SetBottomMargin(0.04);
////  InvMassDiMuBarrEndcPlotPad->SetBottomMargin(0.04);
////  InvMassDiMuEndcEndcPlotPad->SetBottomMargin(0.04);
////  Mu1PtPlotPad->SetBottomMargin(0.04);
////  Mu2PtPlotPad->SetBottomMargin(0.04);
////  DiMuPtPlotPad->SetBottomMargin(0.04);
////  Mu1EtaPlotPad->SetBottomMargin(0.04);
////  Mu2EtaPlotPad->SetBottomMargin(0.04);
////  DiTauEtaPlotPad->SetBottomMargin(0.04);
////  DiTauPhiPlotPad->SetBottomMargin(0.04);
////  DiMuEtaPlotPad->SetBottomMargin(0.04);
////  DiMudRPlotPad->SetBottomMargin(0.04);
////  DiMuPhiPlotPad->SetBottomMargin(0.04);
////  EtMETPlotPad->SetBottomMargin(0.04);
////  DiTauDiMuMassPlotPad->SetBottomMargin(0.04);
////  DiMuDiTauDeltaPhiPlotPad->SetBottomMargin(0.04);
////  METDiTauDeltaPhiPlotPad->SetBottomMargin(0.04);
////  METDiMuDeltaPhiPlotPad->SetBottomMargin(0.04);
////  DiTaudRPlotPad->SetBottomMargin(0.04);
////  DiTauMassSmallerdRPlotPad->SetBottomMargin(0.04);
////  ZMassdRPlotPad->SetBottomMargin(0.04);
  
////  NMedIsoTausWithMu3PlotPad->SetRightMargin(0.03);
////  InvMassTauHadMu3PlotPad->SetRightMargin(0.03);
////  PtTauHadMu3PlotPad->SetRightMargin(0.03);
////  InvMassMu1TauMuPlotPad->SetRightMargin(0.03);
////  InvMassMu2TauMuPlotPad->SetRightMargin(0.03);
////  InvMassFullRangePlotPad->SetRightMargin(0.03);
////  InvMassDiMuBarrBarrPlotPad->SetRightMargin(0.03);
////  InvMassDiMuBarrEndcPlotPad->SetRightMargin(0.03);
////  InvMassDiMuEndcEndcPlotPad->SetRightMargin(0.03);
////  Mu1PtPlotPad->SetRightMargin(0.03);
////  Mu2PtPlotPad->SetRightMargin(0.03);
////  DiMuPtPlotPad->SetRightMargin(0.03);
////  Mu1EtaPlotPad->SetRightMargin(0.03);
////  Mu2EtaPlotPad->SetRightMargin(0.03);
////  DiTauEtaPlotPad->SetRightMargin(0.03);
////  DiTauPhiPlotPad->SetRightMargin(0.03);
////  DiMuEtaPlotPad->SetRightMargin(0.03);
////  DiMudRPlotPad->SetRightMargin(0.03);
////  DiMuPhiPlotPad->SetRightMargin(0.03);
////  EtMETPlotPad->SetRightMargin(0.03);
////  DiTauDiMuMassPlotPad->SetRightMargin(0.03);
////  DiMuDiTauDeltaPhiPlotPad->SetRightMargin(0.03);
////  METDiTauDeltaPhiPlotPad->SetRightMargin(0.03);
////  METDiMuDeltaPhiPlotPad->SetRightMargin(0.03);
////  DiTaudRPlotPad->SetRightMargin(0.03);
////  DiTauMassSmallerdRPlotPad->SetRightMargin(0.03);
////  ZMassdRPlotPad->SetRightMargin(0.03);
  
cout << "Created the Output Pads" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getting the Legends
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TLegend *legend = new TLegend(0.7,0.5,0.95,0.7) ;
  legend->SetTextFont(42);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->AddEntry(EtMETST_ ,"ST", "f");
  legend->AddEntry(EtMETQCD_ ,"QCD", "f");
  legend->AddEntry(EtMETDiBoson_ ,"DiBoson", "f");
  legend->AddEntry(EtMETDY_ ,"DY", "f");
  legend->AddEntry(EtMETTT_ ,"TT", "f");
  legend->AddEntry(EtMETh125a9_ ,"h125a9", "f");


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Drawing the stacks
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  string  NMedIsoTausWithMu3StackYTitle = "Events / " + std::to_string(NMedIsoTausWithMu3TT_->GetXaxis()->GetBinWidth(3) );
  string  InvMassTauHadMu3StackYTitle = "Events / " + std::to_string(InvMassTauHadMu3TT_->GetXaxis()->GetBinWidth(3) );
  string  PtTauHadMu3StackYTitle = "Events / " + std::to_string(PtTauHadMu3TT_->GetXaxis()->GetBinWidth(3) );
  string  InvMassMu1TauMuStackYTitle = "Events / " + std::to_string(InvMassMu1TauMuTT_->GetXaxis()->GetBinWidth(3) );
  string  InvMassMu2TauMuStackYTitle = "Events / " + std::to_string(InvMassMu2TauMuTT_->GetXaxis()->GetBinWidth(3) );
  string  InvMassFullRangeStackYTitle = "Events / " + std::to_string(InvMassFullRangeTT_->GetXaxis()->GetBinWidth(3) );
  string  InvMassDiMuBarrBarrStackYTitle = "Events / " + std::to_string(InvMassDiMuBarrBarrTT_->GetXaxis()->GetBinWidth(3) );
  string  InvMassDiMuBarrEndcStackYTitle = "Events / " + std::to_string(InvMassDiMuBarrBarrTT_->GetXaxis()->GetBinWidth(3) );
  string  InvMassDiMuEndcEndcStackYTitle = "Events / " + std::to_string(InvMassDiMuEndcEndcTT_->GetXaxis()->GetBinWidth(3) );
  string  Mu1PtStackYTitle = "Events / " + std::to_string(Mu1PtTT_->GetXaxis()->GetBinWidth(3) );
  string  Mu2PtStackYTitle = "Events / " + std::to_string(Mu2PtTT_->GetXaxis()->GetBinWidth(3) );
  string  DiMuPtStackYTitle = "Events / " + std::to_string(DiMuPtTT_->GetXaxis()->GetBinWidth(3) );
  string  Mu1EtaStackYTitle = "Events / " + std::to_string(Mu1EtaTT_->GetXaxis()->GetBinWidth(3) );
  string  Mu2EtaStackYTitle = "Events / " + std::to_string(Mu2EtaTT_->GetXaxis()->GetBinWidth(3) );
  string  DiTauEtaStackYTitle = "Events / " + std::to_string(DiTauEtaTT_->GetXaxis()->GetBinWidth(3) );
  string  DiTauPhiStackYTitle = "Events / " + std::to_string(DiTauPhiTT_->GetXaxis()->GetBinWidth(3) );
  string  DiMuEtaStackYTitle = "Events / " + std::to_string(DiMuEtaTT_->GetXaxis()->GetBinWidth(3) );
  string  DiMudRStackYTitle = "Events / " + std::to_string(DiMudRTT_->GetXaxis()->GetBinWidth(3) );
  string  DiMuPhiStackYTitle = "Events / " + std::to_string(DiMuPhiTT_->GetXaxis()->GetBinWidth(3) );
  string  EtMETStackYTitle = "Events / " + std::to_string(EtMETTT_->GetXaxis()->GetBinWidth(3) );
  string  DiTauDiMuMassStackYTitle = "Events / " + std::to_string(DiTauDiMuMassTT_->GetXaxis()->GetBinWidth(3) );
  string  DiMuDiTauDeltaPhiStackYTitle = "Events / " + std::to_string(DiMuDiTauDeltaPhiTT_->GetXaxis()->GetBinWidth(3) );
  string  METDiTauDeltaPhiStackYTitle = "Events / " + std::to_string(METDiTauDeltaPhiTT_->GetXaxis()->GetBinWidth(3) );
  string  METDiMuDeltaPhiStackYTitle = "Events / " + std::to_string(METDiMuDeltaPhiTT_->GetXaxis()->GetBinWidth(3) );
  string  DiTaudRStackYTitle = "Events / " + std::to_string(DiTaudRTT_->GetXaxis()->GetBinWidth(3) );
  string  DiTauMassSmallerdRStackYTitle = "Events / " + std::to_string(DiTauMassSmallerdRTT_->GetXaxis()->GetBinWidth(3) );
  string  ZMassdRStackYTitle = "Events / " + std::to_string(ZMassdRTT_->GetXaxis()->GetBinWidth(3) );

  NMedIsoTausWithMu3Canvas->cd();
  NMedIsoTausWithMu3Stack->Draw("hist");
  NMedIsoTausWithMu3h125a9_->Scale(1.0/35.0*.05151);
  NMedIsoTausWithMu3h125a9_->SetLineColor(kGreen+3);
  NMedIsoTausWithMu3h125a9_->Draw("HIST SAME");
  NMedIsoTausWithMu3Stack->GetXaxis()->SetTitle(NMedIsoTausWithMu3TT_->GetXaxis()->GetTitle() );
  NMedIsoTausWithMu3Stack->GetXaxis()->SetLabelSize(0.05);
  NMedIsoTausWithMu3Stack->GetYaxis()->SetTitle(NMedIsoTausWithMu3StackYTitle.c_str() );
  NMedIsoTausWithMu3Stack->GetYaxis()->SetLabelSize(0.05);
  NMedIsoTausWithMu3Stack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  InvMassTauHadMu3Canvas->cd();
  InvMassTauHadMu3Stack->Draw("hist");
  InvMassTauHadMu3h125a9_->Scale(1.0/35.0*.05151);
  InvMassTauHadMu3h125a9_->SetLineColor(kGreen+3);
  InvMassTauHadMu3h125a9_->Draw("HIST SAME");
  InvMassTauHadMu3Stack->GetXaxis()->SetTitle(InvMassTauHadMu3TT_->GetXaxis()->GetTitle() );
  InvMassTauHadMu3Stack->GetXaxis()->SetLabelSize(0.05);
  InvMassTauHadMu3Stack->GetYaxis()->SetTitle(InvMassTauHadMu3StackYTitle.c_str() );
  InvMassTauHadMu3Stack->GetYaxis()->SetLabelSize(0.05);
  InvMassTauHadMu3Stack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  PtTauHadMu3Canvas->cd();
  PtTauHadMu3Stack->Draw("hist");
  PtTauHadMu3h125a9_->Scale(1.0/35.0*.05151);
  PtTauHadMu3h125a9_->SetLineColor(kGreen+3);
  PtTauHadMu3h125a9_->Draw("HIST SAME");
  PtTauHadMu3Stack->GetXaxis()->SetTitle(PtTauHadMu3TT_->GetXaxis()->GetTitle() );
  PtTauHadMu3Stack->GetXaxis()->SetLabelSize(0.05);
  PtTauHadMu3Stack->GetYaxis()->SetTitle(PtTauHadMu3StackYTitle.c_str() );
  PtTauHadMu3Stack->GetYaxis()->SetLabelSize(0.05);
  PtTauHadMu3Stack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  InvMassMu1TauMuCanvas->cd();
  InvMassMu1TauMuStack->Draw("hist");
  InvMassMu1TauMuh125a9_->Scale(1.0/35.0*.05151);
  InvMassMu1TauMuh125a9_->SetLineColor(kGreen+3);
  InvMassMu1TauMuh125a9_->Draw("HIST SAME");
  InvMassMu1TauMuStack->GetXaxis()->SetTitle(InvMassMu1TauMuTT_->GetXaxis()->GetTitle() );
  InvMassMu1TauMuStack->GetXaxis()->SetLabelSize(0.05);
  InvMassMu1TauMuStack->GetYaxis()->SetTitle(InvMassMu1TauMuStackYTitle.c_str() );
  InvMassMu1TauMuStack->GetYaxis()->SetLabelSize(0.05);
  InvMassMu1TauMuStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  InvMassMu2TauMuCanvas->cd();
  InvMassMu2TauMuStack->Draw("hist");
  InvMassMu2TauMuh125a9_->Scale(1.0/35.0*.05151);
  InvMassMu2TauMuh125a9_->SetLineColor(kGreen+3);
  InvMassMu2TauMuh125a9_->Draw("HIST SAME");
  InvMassMu2TauMuStack->GetXaxis()->SetTitle(InvMassMu2TauMuTT_->GetXaxis()->GetTitle() );
  InvMassMu2TauMuStack->GetXaxis()->SetLabelSize(0.05);
  InvMassMu2TauMuStack->GetYaxis()->SetTitle(InvMassMu2TauMuStackYTitle.c_str() );
  InvMassMu2TauMuStack->GetYaxis()->SetLabelSize(0.05);
  InvMassMu2TauMuStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  InvMassFullRangeCanvas->cd();
  InvMassFullRangeStack->Draw("hist");
  InvMassFullRangeh125a9_->Scale(1.0/35.0*.05151);
  InvMassFullRangeh125a9_->SetLineColor(kGreen+3);
  InvMassFullRangeh125a9_->Draw("HIST SAME");
  InvMassFullRangeStack->GetXaxis()->SetTitle(InvMassFullRangeTT_->GetXaxis()->GetTitle() );
  InvMassFullRangeStack->GetXaxis()->SetLabelSize(0.05);
  InvMassFullRangeStack->GetYaxis()->SetTitle(InvMassFullRangeStackYTitle.c_str() );
  InvMassFullRangeStack->GetYaxis()->SetLabelSize(0.05);
  InvMassFullRangeStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  InvMassDiMuBarrBarrCanvas->cd();
  InvMassDiMuBarrBarrStack->Draw("hist");
  InvMassDiMuBarrBarrh125a9_->Scale(1.0/35.0*.05151);
  InvMassDiMuBarrBarrh125a9_->SetLineColor(kGreen+3);
  InvMassDiMuBarrBarrh125a9_->Draw("HIST SAME");
  InvMassDiMuBarrBarrStack->GetXaxis()->SetTitle(InvMassDiMuBarrBarrTT_->GetXaxis()->GetTitle() );
  InvMassDiMuBarrBarrStack->GetXaxis()->SetLabelSize(0.05);
  InvMassDiMuBarrBarrStack->GetYaxis()->SetTitle(InvMassDiMuBarrBarrStackYTitle.c_str() );
  InvMassDiMuBarrBarrStack->GetYaxis()->SetLabelSize(0.05);
  InvMassDiMuBarrBarrStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  InvMassDiMuBarrEndcCanvas->cd();
  InvMassDiMuBarrEndcStack->Draw("hist");
  InvMassDiMuBarrEndch125a9_->Scale(1.0/35.0*.05151);
  InvMassDiMuBarrEndch125a9_->SetLineColor(kGreen+3);
  InvMassDiMuBarrEndch125a9_->Draw("HIST SAME");
  InvMassDiMuBarrEndcStack->GetXaxis()->SetTitle(InvMassDiMuBarrEndcTT_->GetXaxis()->GetTitle() );
  InvMassDiMuBarrEndcStack->GetXaxis()->SetLabelSize(0.05);
  InvMassDiMuBarrEndcStack->GetYaxis()->SetTitle(InvMassDiMuBarrEndcStackYTitle.c_str() );
  InvMassDiMuBarrEndcStack->GetYaxis()->SetLabelSize(0.05);
  InvMassDiMuBarrEndcStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  InvMassDiMuEndcEndcCanvas->cd();
  InvMassDiMuEndcEndcStack->Draw("hist");
  InvMassDiMuEndcEndch125a9_->Scale(1.0/35.0*.05151);
  InvMassDiMuEndcEndch125a9_->SetLineColor(kGreen+3);
  InvMassDiMuEndcEndch125a9_->Draw("HIST SAME");
  InvMassDiMuEndcEndcStack->GetXaxis()->SetTitle(InvMassDiMuEndcEndcTT_->GetXaxis()->GetTitle() );
  InvMassDiMuEndcEndcStack->GetXaxis()->SetLabelSize(0.05);
  InvMassDiMuEndcEndcStack->GetYaxis()->SetTitle(InvMassDiMuEndcEndcStackYTitle.c_str() );
  InvMassDiMuEndcEndcStack->GetYaxis()->SetLabelSize(0.05);
  InvMassDiMuEndcEndcStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  Mu1PtCanvas->cd();
  Mu1PtStack->Draw("hist");
  Mu1Pth125a9_->Scale(1.0/35.0*.05151);
  Mu1Pth125a9_->SetLineColor(kGreen+3);
  Mu1Pth125a9_->Draw("HIST SAME");
  Mu1PtStack->GetXaxis()->SetTitle(Mu1PtTT_->GetXaxis()->GetTitle() );
  Mu1PtStack->GetXaxis()->SetLabelSize(0.05);
  Mu1PtStack->GetYaxis()->SetTitle(Mu1PtStackYTitle.c_str() );
  Mu1PtStack->GetYaxis()->SetLabelSize(0.05);
  Mu1PtStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  Mu2PtCanvas->cd();
  Mu2PtStack->Draw("hist");
  Mu2Pth125a9_->Scale(1.0/35.0*.05151);
  Mu2Pth125a9_->SetLineColor(kGreen+3);
  Mu2Pth125a9_->Draw("HIST SAME");
  Mu2PtStack->GetXaxis()->SetTitle(Mu2PtTT_->GetXaxis()->GetTitle() );
  Mu2PtStack->GetXaxis()->SetLabelSize(0.05);
  Mu2PtStack->GetYaxis()->SetTitle(Mu2PtStackYTitle.c_str() );
  Mu2PtStack->GetYaxis()->SetLabelSize(0.05);
  Mu2PtStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DiMuPtCanvas->cd();
  DiMuPtStack->Draw("hist");
  DiMuPth125a9_->Scale(1.0/35.0*.05151);
  DiMuPth125a9_->SetLineColor(kGreen+3);
  DiMuPth125a9_->Draw("HIST SAME");
  DiMuPtStack->GetXaxis()->SetTitle(DiMuPtTT_->GetXaxis()->GetTitle() );
  DiMuPtStack->GetXaxis()->SetLabelSize(0.05);
  DiMuPtStack->GetYaxis()->SetTitle(DiMuPtStackYTitle.c_str() );
  DiMuPtStack->GetYaxis()->SetLabelSize(0.05);
  DiMuPtStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  Mu1EtaCanvas->cd();
  Mu1EtaStack->Draw("hist");
  Mu1Etah125a9_->Scale(1.0/35.0*.05151);
  Mu1Etah125a9_->SetLineColor(kGreen+3);
  Mu1Etah125a9_->Draw("HIST SAME");
  Mu1EtaStack->GetXaxis()->SetTitle(Mu1EtaTT_->GetXaxis()->GetTitle() );
  Mu1EtaStack->GetXaxis()->SetLabelSize(0.05);
  Mu1EtaStack->GetYaxis()->SetTitle(Mu1EtaStackYTitle.c_str() );
  Mu1EtaStack->GetYaxis()->SetLabelSize(0.05);
  Mu1EtaStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  Mu2EtaCanvas->cd();
  Mu2EtaStack->Draw("hist");
  Mu2Etah125a9_->Scale(1.0/35.0*.05151);
  Mu2Etah125a9_->SetLineColor(kGreen+3);
  Mu2Etah125a9_->Draw("HIST SAME");
  Mu2EtaStack->GetXaxis()->SetTitle(Mu2EtaTT_->GetXaxis()->GetTitle() );
  Mu2EtaStack->GetXaxis()->SetLabelSize(0.05);
  Mu2EtaStack->GetYaxis()->SetTitle(Mu2EtaStackYTitle.c_str() );
  Mu2EtaStack->GetYaxis()->SetLabelSize(0.05);
  Mu2EtaStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DiTauEtaCanvas->cd();
  DiTauEtaStack->Draw("hist");
  DiTauEtah125a9_->Scale(1.0/35.0*.05151);
  DiTauEtah125a9_->SetLineColor(kGreen+3);
  DiTauEtah125a9_->Draw("HIST SAME");
  DiTauEtaStack->GetXaxis()->SetTitle(DiTauEtaTT_->GetXaxis()->GetTitle() );
  DiTauEtaStack->GetXaxis()->SetLabelSize(0.05);
  DiTauEtaStack->GetYaxis()->SetTitle(DiTauEtaStackYTitle.c_str() );
  DiTauEtaStack->GetYaxis()->SetLabelSize(0.05);
  DiTauEtaStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DiTauPhiCanvas->cd();
  DiTauPhiStack->Draw("hist");
  DiTauPhih125a9_->Scale(1.0/35.0*.05151);
  DiTauPhih125a9_->SetLineColor(kGreen+3);
  DiTauPhih125a9_->Draw("HIST SAME");
  DiTauPhiStack->GetXaxis()->SetTitle(DiTauPhiTT_->GetXaxis()->GetTitle() );
  DiTauPhiStack->GetXaxis()->SetLabelSize(0.05);
  DiTauPhiStack->GetYaxis()->SetTitle(DiTauPhiStackYTitle.c_str() );
  DiTauPhiStack->GetYaxis()->SetLabelSize(0.05);
  DiTauPhiStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DiMuEtaCanvas->cd();
  DiMuEtaStack->Draw("hist");
  DiMuEtah125a9_->Scale(1.0/35.0*.05151);
  DiMuEtah125a9_->SetLineColor(kGreen+3);
  DiMuEtah125a9_->Draw("HIST SAME");
  DiMuEtaStack->GetXaxis()->SetTitle(DiMuEtaTT_->GetXaxis()->GetTitle() );
  DiMuEtaStack->GetXaxis()->SetLabelSize(0.05);
  DiMuEtaStack->GetYaxis()->SetTitle(DiMuEtaStackYTitle.c_str() );
  DiMuEtaStack->GetYaxis()->SetLabelSize(0.05);
  DiMuEtaStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DiMudRCanvas->cd();
  DiMudRStack->Draw("hist");
  DiMudRh125a9_->Scale(1.0/35.0*.05151);
  DiMudRh125a9_->SetLineColor(kGreen+3);
  DiMudRh125a9_->Draw("HIST SAME");
  DiMudRStack->GetXaxis()->SetTitle(DiMudRTT_->GetXaxis()->GetTitle() );
  DiMudRStack->GetXaxis()->SetLabelSize(0.05);
  DiMudRStack->GetYaxis()->SetTitle(DiMudRStackYTitle.c_str() );
  DiMudRStack->GetYaxis()->SetLabelSize(0.05);
  DiMudRStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DiMuPhiCanvas->cd();
  DiMuPhiStack->Draw("hist");
  DiMuPhih125a9_->Scale(1.0/35.0*.05151);
  DiMuPhih125a9_->SetLineColor(kGreen+3);
  DiMuPhih125a9_->Draw("HIST SAME");
  DiMuPhiStack->GetXaxis()->SetTitle(DiMuPhiTT_->GetXaxis()->GetTitle() );
  DiMuPhiStack->GetXaxis()->SetLabelSize(0.05);
  DiMuPhiStack->GetYaxis()->SetTitle(DiMuPhiStackYTitle.c_str() );
  DiMuPhiStack->GetYaxis()->SetLabelSize(0.05);
  DiMuPhiStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  EtMETCanvas->cd();
  EtMETStack->Draw("hist");
  EtMETh125a9_->Scale(1.0/35.0*.05151);
  EtMETh125a9_->SetLineColor(kGreen+3);
  EtMETh125a9_->Draw("HIST SAME");
  EtMETStack->GetXaxis()->SetTitle(EtMETTT_->GetXaxis()->GetTitle() );
  EtMETStack->GetXaxis()->SetLabelSize(0.05);
  EtMETStack->GetYaxis()->SetTitle(EtMETStackYTitle.c_str() );
  EtMETStack->GetYaxis()->SetLabelSize(0.05);
  EtMETStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DiTauDiMuMassCanvas->cd();
  DiTauDiMuMassStack->Draw("hist");
  DiTauDiMuMassh125a9_->Scale(1.0/35.0*.05151);
  DiTauDiMuMassh125a9_->SetLineColor(kGreen+3);
  DiTauDiMuMassh125a9_->Draw("HIST SAME");
  DiTauDiMuMassStack->GetXaxis()->SetTitle(DiTauDiMuMassTT_->GetXaxis()->GetTitle() );
  DiTauDiMuMassStack->GetXaxis()->SetLabelSize(0.05);
  DiTauDiMuMassStack->GetYaxis()->SetTitle(DiTauDiMuMassStackYTitle.c_str() );
  DiTauDiMuMassStack->GetYaxis()->SetLabelSize(0.05);
  DiTauDiMuMassStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DiMuDiTauDeltaPhiCanvas->cd();
  DiMuDiTauDeltaPhiStack->Draw("hist");
  DiMuDiTauDeltaPhih125a9_->Scale(1.0/35.0*.05151);
  DiMuDiTauDeltaPhih125a9_->SetLineColor(kGreen+3);
  DiMuDiTauDeltaPhih125a9_->Draw("HIST SAME");
  DiMuDiTauDeltaPhiStack->GetXaxis()->SetTitle(DiMuDiTauDeltaPhiTT_->GetXaxis()->GetTitle() );
  DiMuDiTauDeltaPhiStack->GetXaxis()->SetLabelSize(0.05);
  DiMuDiTauDeltaPhiStack->GetYaxis()->SetTitle(DiMuDiTauDeltaPhiStackYTitle.c_str() );
  DiMuDiTauDeltaPhiStack->GetYaxis()->SetLabelSize(0.05);
  DiMuDiTauDeltaPhiStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  METDiTauDeltaPhiCanvas->cd();
  METDiTauDeltaPhiStack->Draw("hist");
  METDiTauDeltaPhih125a9_->Scale(1.0/35.0*.05151);
  METDiTauDeltaPhih125a9_->SetLineColor(kGreen+3);
  METDiTauDeltaPhih125a9_->Draw("HIST SAME");
  METDiTauDeltaPhiStack->GetXaxis()->SetTitle(METDiTauDeltaPhiTT_->GetXaxis()->GetTitle() );
  METDiTauDeltaPhiStack->GetXaxis()->SetLabelSize(0.05);
  METDiTauDeltaPhiStack->GetYaxis()->SetTitle(METDiTauDeltaPhiStackYTitle.c_str() );
  METDiTauDeltaPhiStack->GetYaxis()->SetLabelSize(0.05);
  METDiTauDeltaPhiStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  METDiMuDeltaPhiCanvas->cd();
  METDiMuDeltaPhiStack->Draw("hist");
  METDiMuDeltaPhih125a9_->Scale(1.0/35.0*.05151);
  METDiMuDeltaPhih125a9_->SetLineColor(kGreen+3);
  METDiMuDeltaPhih125a9_->Draw("HIST SAME");
  METDiMuDeltaPhiStack->GetXaxis()->SetTitle(METDiMuDeltaPhiTT_->GetXaxis()->GetTitle() );
  METDiMuDeltaPhiStack->GetXaxis()->SetLabelSize(0.05);
  METDiMuDeltaPhiStack->GetYaxis()->SetTitle(METDiMuDeltaPhiStackYTitle.c_str() );
  METDiMuDeltaPhiStack->GetYaxis()->SetLabelSize(0.05);
  METDiMuDeltaPhiStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DiTaudRCanvas->cd();
  DiTaudRStack->Draw("hist");
  DiTaudRh125a9_->Scale(1.0/35.0*.05151);
  DiTaudRh125a9_->SetLineColor(kGreen+3);
  DiTaudRh125a9_->Draw("HIST SAME");
  DiTaudRStack->GetXaxis()->SetTitle(DiTaudRTT_->GetXaxis()->GetTitle() );
  DiTaudRStack->GetXaxis()->SetLabelSize(0.05);
  DiTaudRStack->GetYaxis()->SetTitle(DiTaudRStackYTitle.c_str() );
  DiTaudRStack->GetYaxis()->SetLabelSize(0.05);
  DiTaudRStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  DiTauMassSmallerdRCanvas->cd();
  DiTauMassSmallerdRStack->Draw("hist");
  DiTauMassSmallerdRh125a9_->Scale(1.0/35.0*.05151);
  DiTauMassSmallerdRh125a9_->SetLineColor(kGreen+3);
  DiTauMassSmallerdRh125a9_->Draw("HIST SAME");
  DiTauMassSmallerdRStack->GetXaxis()->SetTitle(DiTauMassSmallerdRTT_->GetXaxis()->GetTitle() );
  DiTauMassSmallerdRStack->GetXaxis()->SetLabelSize(0.05);
  DiTauMassSmallerdRStack->GetYaxis()->SetTitle(DiTauMassSmallerdRStackYTitle.c_str() );
  DiTauMassSmallerdRStack->GetYaxis()->SetLabelSize(0.05);
  DiTauMassSmallerdRStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();
  ZMassdRCanvas->cd();
  ZMassdRStack->Draw("hist");
  ZMassdRh125a9_->Scale(1.0/35.0*.05151);
  ZMassdRh125a9_->SetLineColor(kGreen+3);
  ZMassdRh125a9_->Draw("HIST SAME");
  ZMassdRStack->GetXaxis()->SetTitle(ZMassdRTT_->GetXaxis()->GetTitle() );
  ZMassdRStack->GetXaxis()->SetLabelSize(0.05);
  ZMassdRStack->GetYaxis()->SetTitle(ZMassdRStackYTitle.c_str() );
  ZMassdRStack->GetYaxis()->SetLabelSize(0.05);
  ZMassdRStack->GetYaxis()->SetTitleOffset(.9);
  legend->Draw();

cout << "Stacks Drawn" << endl;
/*
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting the Stack Style
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  NMedIsoTausWithMu3Stack->GetXaxis()->SetTitle(NMedIsoTausWithMu3TT_->GetXaxis()->GetTitle() );
cout << "check1" << endl;
  InvMassTauHadMu3Stack->GetXaxis()->SetTitle(InvMassTauHadMu3TT_->GetXaxis()->GetTitle() );
  PtTauHadMu3Stack->GetXaxis()->SetTitle(PtTauHadMu3TT_->GetXaxis()->GetTitle() );
  InvMassMu1TauMuStack->GetXaxis()->SetTitle(InvMassMu1TauMuTT_->GetXaxis()->GetTitle() );
  InvMassMu2TauMuStack->GetXaxis()->SetTitle(InvMassMu2TauMuTT_->GetXaxis()->GetTitle() );
  InvMassFullRangeStack->GetXaxis()->SetTitle(InvMassFullRangeTT_->GetXaxis()->GetTitle() );
  InvMassDiMuBarrBarrStack->GetXaxis()->SetTitle(InvMassDiMuBarrBarrTT_->GetXaxis()->GetTitle() );
  InvMassDiMuBarrEndcStack->GetXaxis()->SetTitle(InvMassDiMuBarrBarrTT_->GetXaxis()->GetTitle() );
  InvMassDiMuEndcEndcStack->GetXaxis()->SetTitle(InvMassDiMuEndcEndcTT_->GetXaxis()->GetTitle() );
  Mu1PtStack->GetXaxis()->SetTitle(Mu1PtTT_->GetXaxis()->GetTitle() );
  Mu2PtStack->GetXaxis()->SetTitle(Mu2PtTT_->GetXaxis()->GetTitle() );
  DiMuPtStack->GetXaxis()->SetTitle(DiMuPtTT_->GetXaxis()->GetTitle() );
  Mu1EtaStack->GetXaxis()->SetTitle(Mu1EtaTT_->GetXaxis()->GetTitle() );
  Mu2EtaStack->GetXaxis()->SetTitle(Mu2EtaTT_->GetXaxis()->GetTitle() );
  DiTauEtaStack->GetXaxis()->SetTitle(DiTauEtaTT_->GetXaxis()->GetTitle() );
  DiTauPhiStack->GetXaxis()->SetTitle(DiTauPhiTT_->GetXaxis()->GetTitle() );
  DiMuEtaStack->GetXaxis()->SetTitle(DiMuEtaTT_->GetXaxis()->GetTitle() );
  DiMudRStack->GetXaxis()->SetTitle(DiMudRTT_->GetXaxis()->GetTitle() );
  DiMuPhiStack->GetXaxis()->SetTitle(DiMuPhiTT_->GetXaxis()->GetTitle() );
  EtMETStack->GetXaxis()->SetTitle(EtMETTT_->GetXaxis()->GetTitle() );
  DiTauDiMuMassStack->GetXaxis()->SetTitle(DiTauDiMuMassTT_->GetXaxis()->GetTitle() );
  DiMuDiTauDeltaPhiStack->GetXaxis()->SetTitle(DiMuDiTauDeltaPhiTT_->GetXaxis()->GetTitle() );
  METDiTauDeltaPhiStack->GetXaxis()->SetTitle(METDiTauDeltaPhiTT_->GetXaxis()->GetTitle() );
  METDiMuDeltaPhiStack->GetXaxis()->SetTitle(METDiMuDeltaPhiTT_->GetXaxis()->GetTitle() );
  DiTaudRStack->GetXaxis()->SetTitle(DiTaudRTT_->GetXaxis()->GetTitle() );
  DiTauMassSmallerdRStack->GetXaxis()->SetTitle(DiTauMassSmallerdRTT_->GetXaxis()->GetTitle() );
  ZMassdRStack->GetXaxis()->SetTitle(ZMassdRTT_->GetXaxis()->GetTitle() );

  NMedIsoTausWithMu3Stack->GetYaxis()->SetTitle(  NMedIsoTausWithMu3StackYTitle.c_str() );
  InvMassTauHadMu3Stack->GetYaxis()->SetTitle(  InvMassTauHadMu3StackYTitle.c_str() );
  PtTauHadMu3Stack->GetYaxis()->SetTitle(  PtTauHadMu3StackYTitle.c_str() );
  InvMassMu1TauMuStack->GetYaxis()->SetTitle(  InvMassMu1TauMuStackYTitle.c_str() );
  InvMassMu2TauMuStack->GetYaxis()->SetTitle(  InvMassMu2TauMuStackYTitle.c_str() );
  InvMassFullRangeStack->GetYaxis()->SetTitle(  InvMassFullRangeStackYTitle.c_str() );
  InvMassDiMuBarrBarrStack->GetYaxis()->SetTitle(  InvMassDiMuBarrBarrStackYTitle.c_str() );
  InvMassDiMuBarrEndcStack->GetYaxis()->SetTitle(  InvMassDiMuBarrEndcStackYTitle.c_str() );
  InvMassDiMuEndcEndcStack->GetYaxis()->SetTitle(  InvMassDiMuEndcEndcStackYTitle.c_str() );
  Mu1PtStack->GetYaxis()->SetTitle(  Mu1PtStackYTitle.c_str() );
  Mu2PtStack->GetYaxis()->SetTitle(  Mu2PtStackYTitle.c_str() );
  DiMuPtStack->GetYaxis()->SetTitle(  DiMuPtStackYTitle.c_str() );
  Mu1EtaStack->GetYaxis()->SetTitle(  Mu1EtaStackYTitle.c_str() );
  Mu2EtaStack->GetYaxis()->SetTitle(  Mu2EtaStackYTitle.c_str() );
  DiTauEtaStack->GetYaxis()->SetTitle(  DiTauEtaStackYTitle.c_str() );
  DiTauPhiStack->GetYaxis()->SetTitle(  DiTauPhiStackYTitle.c_str() );
  DiMuEtaStack->GetYaxis()->SetTitle(  DiMuEtaStackYTitle.c_str() );
  DiMudRStack->GetYaxis()->SetTitle(  DiMudRStackYTitle.c_str() );
  DiMuPhiStack->GetYaxis()->SetTitle(  DiMuPhiStackYTitle.c_str() );
  EtMETStack->GetYaxis()->SetTitle(  EtMETStackYTitle.c_str() );
  DiTauDiMuMassStack->GetYaxis()->SetTitle(  DiTauDiMuMassStackYTitle.c_str() );
  DiMuDiTauDeltaPhiStack->GetYaxis()->SetTitle(  DiMuDiTauDeltaPhiStackYTitle.c_str() );
  METDiTauDeltaPhiStack->GetYaxis()->SetTitle(  METDiTauDeltaPhiStackYTitle.c_str() );
  METDiMuDeltaPhiStack->GetYaxis()->SetTitle(  METDiMuDeltaPhiStackYTitle.c_str() );
  DiTaudRStack->GetYaxis()->SetTitle(  DiTaudRStackYTitle.c_str() );
  DiTauMassSmallerdRStack->GetYaxis()->SetTitle(  DiTauMassSmallerdRStackYTitle.c_str() );
  ZMassdRStack->GetYaxis()->SetTitle(  ZMassdRStackYTitle.c_str() );

  NMedIsoTausWithMu3Stack->GetYaxis()->SetLabelSize(0.05);
  InvMassTauHadMu3Stack->GetYaxis()->SetLabelSize(0.05);
  PtTauHadMu3Stack->GetYaxis()->SetLabelSize(0.05);
  InvMassMu1TauMuStack->GetYaxis()->SetLabelSize(0.05);
  InvMassMu2TauMuStack->GetYaxis()->SetLabelSize(0.05);
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
  ZMassdRStack->GetYaxis()->SetLabelSize(0.05);
*/
cout << "Stylized the Stacks" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting the cms_lumi Styling
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  writeExtraText = true;
  lumi_13TeV = "35.9 fb^{-1}";
  CMS_lumi(NMedIsoTausWithMu3Canvas, 4, 11);
  CMS_lumi(InvMassTauHadMu3Canvas, 4, 11);
  CMS_lumi(PtTauHadMu3Canvas, 4, 11);
  CMS_lumi(InvMassMu1TauMuCanvas, 4, 11);
  CMS_lumi(InvMassMu2TauMuCanvas, 4, 11);
  CMS_lumi(InvMassFullRangeCanvas, 4, 11);
  CMS_lumi(InvMassDiMuBarrBarrCanvas, 4, 11);
  CMS_lumi(InvMassDiMuBarrEndcCanvas, 4, 11);
  CMS_lumi(InvMassDiMuEndcEndcCanvas, 4, 11);
  CMS_lumi(Mu1PtCanvas, 4, 11);
  CMS_lumi(Mu2PtCanvas, 4, 11);
  CMS_lumi(DiMuPtCanvas, 4, 11);
  CMS_lumi(Mu1EtaCanvas, 4, 11);
  CMS_lumi(Mu2EtaCanvas, 4, 11);
  CMS_lumi(DiTauEtaCanvas, 4, 11);
  CMS_lumi(DiTauPhiCanvas, 4, 11);
  CMS_lumi(DiMuEtaCanvas, 4, 11);
  CMS_lumi(DiMudRCanvas, 4, 11);
  CMS_lumi(DiMuPhiCanvas, 4, 11);
  CMS_lumi(EtMETCanvas, 4, 11);
  CMS_lumi(DiTauDiMuMassCanvas, 4, 11);
  CMS_lumi(DiMuDiTauDeltaPhiCanvas, 4, 11);
  CMS_lumi(METDiTauDeltaPhiCanvas, 4, 11);
  CMS_lumi(METDiMuDeltaPhiCanvas, 4, 11);
  CMS_lumi(DiTaudRCanvas, 4, 11);
  CMS_lumi(DiTauMassSmallerdRCanvas, 4, 11);
  CMS_lumi(ZMassdRCanvas, 4, 11);

cout << "Cms_lumi run" << endl;

  outFile->cd();
  NMedIsoTausWithMu3Canvas->cd();
  NMedIsoTausWithMu3Canvas->Draw();
  NMedIsoTausWithMu3Canvas->Write();

  InvMassTauHadMu3Canvas->cd();
  InvMassTauHadMu3Canvas->Draw();
  InvMassTauHadMu3Canvas->Write();

  PtTauHadMu3Canvas->cd();
  PtTauHadMu3Canvas->Draw();
  PtTauHadMu3Canvas->Write();

  InvMassMu1TauMuCanvas->cd();
  InvMassMu1TauMuCanvas->Draw();
  InvMassMu1TauMuCanvas->Write();

  InvMassMu2TauMuCanvas->cd();
  InvMassMu2TauMuCanvas->Draw();
  InvMassMu2TauMuCanvas->Write();

  InvMassFullRangeCanvas->cd();
  InvMassFullRangeCanvas->Draw();
  InvMassFullRangeCanvas->Write();

  InvMassDiMuBarrBarrCanvas->cd();
  InvMassDiMuBarrBarrCanvas->Draw();
  InvMassDiMuBarrBarrCanvas->Write();

  InvMassDiMuBarrEndcCanvas->cd();
  InvMassDiMuBarrEndcCanvas->Draw();
  InvMassDiMuBarrEndcCanvas->Write();

  InvMassDiMuEndcEndcCanvas->cd();
  InvMassDiMuEndcEndcCanvas->Draw();
  InvMassDiMuEndcEndcCanvas->Write();

  Mu1PtCanvas->cd();
  Mu1PtCanvas->Draw();
  Mu1PtCanvas->Write();

  Mu2PtCanvas->cd();
  Mu2PtCanvas->Draw();
  Mu2PtCanvas->Write();

  DiMuPtCanvas->cd();
  DiMuPtCanvas->Draw();
  DiMuPtCanvas->Write();

  Mu1EtaCanvas->cd();
  Mu1EtaCanvas->Draw();
  Mu1EtaCanvas->Write();

  Mu2EtaCanvas->cd();
  Mu2EtaCanvas->Draw();
  Mu2EtaCanvas->Write();

  DiTauEtaCanvas->cd();
  DiTauEtaCanvas->Draw();
  DiTauEtaCanvas->Write();

  DiTauPhiCanvas->cd();
  DiTauPhiCanvas->Draw();
  DiTauPhiCanvas->Write();

  DiMuEtaCanvas->cd();
  DiMuEtaCanvas->Draw();
  DiMuEtaCanvas->Write();

  DiMudRCanvas->cd();
  DiMudRCanvas->Draw();
  DiMudRCanvas->Write();

  DiMuPhiCanvas->cd();
  DiMuPhiCanvas->Draw();
  DiMuPhiCanvas->Write();

  EtMETCanvas->cd();
  EtMETCanvas->Draw();
  EtMETCanvas->Write();

  DiTauDiMuMassCanvas->cd();
  DiTauDiMuMassCanvas->Draw();
  DiTauDiMuMassCanvas->Write();

  DiMuDiTauDeltaPhiCanvas->cd();
  DiMuDiTauDeltaPhiCanvas->Draw();
  DiMuDiTauDeltaPhiCanvas->Write();

  METDiTauDeltaPhiCanvas->cd();
  METDiTauDeltaPhiCanvas->Draw();
  METDiTauDeltaPhiCanvas->Write();

  METDiMuDeltaPhiCanvas->cd();
  METDiMuDeltaPhiCanvas->Draw();
  METDiMuDeltaPhiCanvas->Write();

  DiTaudRCanvas->cd();
  DiTaudRCanvas->Draw();
  DiTaudRCanvas->Write();

  DiTauMassSmallerdRCanvas->cd();
  DiTauMassSmallerdRCanvas->Draw();
  DiTauMassSmallerdRCanvas->Write();

  ZMassdRCanvas->cd();
  ZMassdRCanvas->Draw();
  ZMassdRCanvas->Write();

  NMedIsoTausWithMu3Stack->Write();
  InvMassTauHadMu3Stack->Write();
  PtTauHadMu3Stack->Write();
  InvMassMu1TauMuStack->Write();
  InvMassMu2TauMuStack->Write();
  InvMassFullRangeStack->Write();
  InvMassDiMuBarrBarrStack->Write();
  InvMassDiMuBarrEndcStack->Write();
  InvMassDiMuEndcEndcStack->Write();
  Mu1PtStack->Write();
  Mu2PtStack->Write();
  DiMuPtStack->Write();
  Mu1EtaStack->Write();
  Mu2EtaStack->Write();
  DiTauEtaStack->Write();
  DiTauPhiStack->Write();
  DiMuEtaStack->Write();
  DiMudRStack->Write();
  DiMuPhiStack->Write();
  EtMETStack->Write();
  DiTauDiMuMassStack->Write();
  DiMuDiTauDeltaPhiStack->Write();
  METDiTauDeltaPhiStack->Write();
  METDiMuDeltaPhiStack->Write();
  DiTaudRStack->Write();
  DiTauMassSmallerdRStack->Write();
  ZMassdRStack->Write();

  outFile->Write();
  outFile->Close();
cout << "end" << endl;

}//rootMacro_BBA_combine
