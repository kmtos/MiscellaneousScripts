#include <string.h>
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TKey.h"
#include "Riostream.h"

#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TGraphAsymmErrors.h"
#include "TMultiGraph.h"

TList *FileList;
TFile *Target;

void CombineShapeFiles(TDirectory *target, TList *sourcelist );

void rootMacro_CombineShapePlots()
{
  Target = TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_AllSIG_AllShapes_FEB8_RegionB.root", "RECREATE" );
  FileList = new TList();
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h125a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h300a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a11_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a13_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a15_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a17_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a19_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a21_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a5_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a7_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_Central.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_IDUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISODOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_ISOUP.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupDOWN.root"));
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL_MiniAOD_SIG_h750a9_MedIsoMu2_TauDMAntiMedIso_FEB8_RegionB_PileupUP.root"));

  CombineShapeFiles( Target, FileList );
}//






void CombineShapeFiles( TDirectory *target, TList *sourcelist )
{
  TString path( (char*)strstr( target->GetPath(), ":" ) );
  path.Remove( 0, 2 );
  TFile *inFile = (TFile*)sourcelist->First();
  TH1F* hist = (TH1F*)inFile->Get("InvMassFullRange");
  string nameFirst = inFile->GetName();
  int posSIG = nameFirst.find("SIG");
  string nameTemp = nameFirst.substr(posSIG);
  string nameFinal = nameTemp.substr(0, nameTemp.length()-5);
  hist->SetName(nameFinal.c_str()); 
  target->cd();
  hist->Write();
  TFile *nextsource = (TFile*)sourcelist->After( inFile);
  while (nextsource)
  {
    TH1F *hist2 = (TH1F*)nextsource->Get("InvMassFullRange");
    string nameFirst2 = nextsource->GetName();
    cout << nameFirst2 << endl;
    int posSIG2 = nameFirst2.find("SIG");
    string nameTemp2 = nameFirst2.substr(posSIG2); 
    string nameFinal2 = nameTemp2.substr(0, nameTemp2.length()-5);
    hist2->SetName(nameFinal2.c_str()); 
    hist2->Write();
    nextsource = (TFile*)sourcelist->After( nextsource );
    cout << hist2->GetName() << endl;
  }//while
    
  
}//CombineShapeFiles

