//macro to add histogram files
//NOTE: This macro is kept for back compatibility only.
//Use instead the executable $ROOTSYS/bin/hadd
//
//This macro will add histograms from a list of root files and write them
//to a target root file. The target file is newly created and must not be
//identical to one of the source files.
//
//Author: Sven A. Schmidt, sven.schmidt@cern.ch
//Date:  13.2.2001

//This code is based on the hadd.C example by Rene Brun and Dirk Geppert,
//which had a problem with directories more than one level deep.
//(see macro hadd_old.C for this previous implementation).
//
//The macro from Sven has been enhanced by
//  Anne-Sylvie Nicollerat <Anne-Sylvie.Nicollerat@cern.ch>
// to automatically add Trees (via a chain of trees).
//
//To use this macro, modify the file names in function hadd.
//
//NB: This macro is provided as a tutorial.
//   Use $ROOTSYS/bin/hadd to merge many histogram files



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

void MergeRootfile( TDirectory *target, TList *sourcelist );


void MergeRootFiles_1000() { 
  // Prepare the files to me merged
  // in an interactive ROOT session, edit the file names
  // Target and FileList, then
  // root > .L MergeRootFiles_200.C
  // root > MergeRootFiles_200()

  Target = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/FINAL_MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates.root", "RECREATE" );
  FileList = new TList();
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_1.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_10.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_100.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_101.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_102.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_103.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_104.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_105.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_106.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_107.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_108.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_109.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_11.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_110.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_111.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_112.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_113.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_114.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_115.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_116.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_117.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_118.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_119.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_12.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_120.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_121.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_122.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_123.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_124.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_125.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_126.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_127.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_128.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_129.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_13.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_130.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_131.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_132.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_133.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_134.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_135.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_136.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_137.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_138.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_139.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_14.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_140.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_141.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_142.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_143.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_144.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_145.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_146.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_147.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_148.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_149.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_15.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_150.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_151.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_152.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_153.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_154.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_155.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_156.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_157.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_158.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_159.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_16.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_160.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_161.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_162.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_163.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_164.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_165.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_166.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_167.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_168.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_169.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_17.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_170.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_171.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_172.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_173.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_174.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_175.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_176.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_177.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_178.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_179.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_18.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_180.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_181.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_182.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_183.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_184.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_185.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_186.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_187.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_188.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_189.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_19.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_190.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_191.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_192.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_193.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_194.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_195.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_196.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_197.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_198.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_199.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_2.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_20.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_200.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_201.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_202.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_203.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_204.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_205.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_206.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_207.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_208.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_209.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_21.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_210.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_211.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_212.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_213.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_214.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_215.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_216.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_217.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_218.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_219.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_22.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_220.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_221.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_222.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_223.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_224.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_225.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_226.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_227.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_228.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_229.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_23.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_230.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_231.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_232.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_233.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_234.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_235.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_236.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_237.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_238.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_239.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_24.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_240.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_241.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_242.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_243.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_244.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_245.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_246.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_247.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_248.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_249.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_25.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_250.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_251.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_252.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_253.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_254.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_255.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_256.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_257.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_258.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_259.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_26.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_260.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_261.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_262.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_263.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_264.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_265.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_266.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_267.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_268.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_269.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_27.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_270.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_271.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_272.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_273.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_274.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_275.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_276.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_277.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_278.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_279.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_28.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_280.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_281.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_282.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_283.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_284.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_285.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_286.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_287.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_288.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_289.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_29.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_290.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_291.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_292.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_293.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_294.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_295.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_296.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_297.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_298.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_299.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_3.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_30.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_300.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_301.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_302.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_303.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_304.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_305.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_306.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_307.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_308.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_309.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_31.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_310.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_311.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_312.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_313.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_314.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_315.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_316.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_317.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_318.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_319.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_32.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_320.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_321.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_322.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_323.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_324.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_325.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_326.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_327.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_328.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_329.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_33.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_330.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_331.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_332.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_333.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_334.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_335.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_336.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_337.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_338.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_339.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_34.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_340.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_341.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_342.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_343.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_344.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_345.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_346.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_347.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_348.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_349.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_35.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_350.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_351.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_352.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_353.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_354.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_355.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_356.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_357.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_358.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_359.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_36.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_360.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_361.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_362.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_363.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_364.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_365.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_366.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_367.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_368.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_369.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_37.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_370.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_371.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_372.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_373.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_374.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_375.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_376.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_377.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_378.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_379.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_38.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_380.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_381.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_382.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_383.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_384.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_385.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_386.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_387.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_388.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_389.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_39.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_390.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_391.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_392.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_393.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_394.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_395.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_396.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_397.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_398.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_399.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_4.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_40.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_400.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_401.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_402.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_403.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_404.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_405.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_406.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_407.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_408.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_409.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_41.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_410.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_411.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_412.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_413.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_414.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_415.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_416.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_417.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_418.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_419.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_42.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_420.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_421.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_422.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_423.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_424.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_425.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_426.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_427.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_428.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_429.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_43.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_430.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_431.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_432.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_433.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_434.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_435.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_436.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_437.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_438.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_439.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_44.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_440.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_441.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_442.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_443.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_444.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_445.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_446.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_447.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_448.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_449.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_45.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_450.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_451.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_452.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_453.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_454.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_455.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_456.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_457.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_458.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_459.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_46.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_460.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_461.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_462.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_463.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_464.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_465.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_466.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_467.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_468.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_469.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_47.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_470.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_471.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_472.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_473.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_474.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_475.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_476.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_477.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_478.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_479.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_48.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_480.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_481.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_482.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_483.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_484.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_485.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_486.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_487.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_488.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_489.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_49.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_490.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_491.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_492.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_493.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_494.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_495.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_496.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_497.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_498.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_499.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_5.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_50.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_500.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_501.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_502.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_503.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_504.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_505.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_506.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_507.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_508.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_509.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_51.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_510.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_511.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_512.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_513.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_514.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_515.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_516.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_517.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_518.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_519.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_52.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_520.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_521.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_522.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_523.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_524.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_525.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_526.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_527.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_528.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_529.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_53.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_530.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_531.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_532.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_533.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_534.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_535.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_536.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_537.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_538.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_539.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_54.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_540.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_541.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_542.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_543.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_544.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_545.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_546.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_547.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_548.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_549.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_55.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_550.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_551.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_552.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_553.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_554.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_555.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_556.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_557.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_558.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_559.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_56.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_560.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_561.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_562.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_563.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_564.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_565.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_566.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_567.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_568.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_569.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_57.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_570.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_571.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_572.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_573.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_574.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_575.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_576.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_577.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_578.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_579.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_58.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_580.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_581.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_582.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_583.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_584.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_585.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_586.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_587.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_588.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_589.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_59.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_590.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_591.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_592.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_593.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_594.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_595.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_596.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_597.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_598.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_599.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_6.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_60.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_600.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_601.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_602.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_603.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_604.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_605.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_606.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_607.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_608.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_609.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_61.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_610.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_611.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_612.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_613.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_614.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_615.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_616.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_617.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_618.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_619.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_62.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_620.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_621.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_622.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_623.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_624.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_625.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_626.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_627.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_628.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_629.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_63.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_630.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_631.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_632.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_633.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_634.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_635.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_636.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_637.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_638.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_639.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_64.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_640.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_641.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_642.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_643.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_644.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_645.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_646.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_647.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_648.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_649.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_65.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_650.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_651.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_652.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_653.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_654.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_655.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_656.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_657.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_658.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_659.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_66.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_660.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_661.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_662.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_663.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_664.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_665.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_666.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_667.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_668.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_669.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_67.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_670.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_671.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_672.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_673.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_674.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_675.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_676.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_677.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_678.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_679.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_68.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_680.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_681.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_682.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_683.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_684.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_685.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_686.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_687.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_688.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_689.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_69.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_690.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_691.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_692.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_693.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_694.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_695.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_696.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_697.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_698.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_699.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_7.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_70.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_700.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_701.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_702.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_703.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_704.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_705.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_706.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_707.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_708.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_709.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_71.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_710.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_711.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_712.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_713.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_714.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_715.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_716.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_717.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_718.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_719.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_72.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_720.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_721.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_722.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_723.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_724.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_725.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_726.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_727.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_728.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_729.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_73.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_730.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_731.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_732.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_733.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_734.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_735.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_736.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_737.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_738.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_739.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_74.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_740.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_741.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_742.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_743.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_744.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_745.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_746.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_747.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_748.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_749.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_75.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_750.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_751.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_752.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_753.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_754.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_755.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_756.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_757.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_758.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_759.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_76.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_760.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_761.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_762.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_763.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_764.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_765.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_766.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_767.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_768.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_769.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_77.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_770.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_771.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_772.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_773.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_774.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_775.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_776.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_777.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_778.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_779.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_78.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_780.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_781.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_782.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_783.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_784.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_785.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_786.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_787.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_788.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_789.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_79.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_790.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_791.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_792.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_793.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_794.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_795.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_796.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_797.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_798.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_799.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_8.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_80.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_800.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_801.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_802.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_803.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_804.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_805.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_806.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_807.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_808.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_809.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_81.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_810.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_811.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_812.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_813.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_814.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_815.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_816.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_817.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_818.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_819.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_82.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_820.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_821.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_822.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_823.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_824.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_825.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_826.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_827.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_828.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_829.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_83.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_830.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_831.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_832.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_833.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_834.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_835.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_836.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_837.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_838.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_839.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_84.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_840.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_841.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_842.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_843.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_844.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_845.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_846.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_847.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_848.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_849.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_85.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_850.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_851.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_852.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_853.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_854.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_855.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_856.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_857.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_858.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_859.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_86.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_860.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_861.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_862.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_863.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_864.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_865.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_866.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_867.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_868.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_869.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_87.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_870.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_871.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_872.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_873.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_874.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_875.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_876.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_877.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_878.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_879.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_88.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_880.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_881.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_882.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_883.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_884.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_885.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_886.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_887.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_888.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_889.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_89.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_890.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_891.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_892.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_893.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_894.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_895.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_896.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_897.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_898.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_899.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_9.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_90.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_900.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_901.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_902.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_903.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_904.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_905.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_906.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_907.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_908.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_909.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_91.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_910.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_911.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_912.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_913.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_914.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_915.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_916.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_917.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_918.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_919.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_92.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_920.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_921.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_922.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_923.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_924.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_925.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_926.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_927.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_928.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_929.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_93.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_930.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_931.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_932.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_933.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_934.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_935.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_936.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_937.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_938.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_939.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_94.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_940.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_941.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_942.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_943.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_944.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_945.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_946.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_947.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_948.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_949.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_95.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_950.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_951.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_952.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_953.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_954.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_955.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_956.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_957.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_958.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_959.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_96.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_960.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_961.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_962.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_963.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_964.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_965.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_966.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_967.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_968.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_969.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_97.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_970.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_971.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_972.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_973.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_975.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_976.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_977.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_978.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_979.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_98.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_980.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_981.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_982.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_983.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_984.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_985.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_986.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_987.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_988.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_989.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_99.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_990.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_991.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_992.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_993.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_994.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_995.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_996.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_997.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_998.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_999.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/GetRates/MiniAOD_SingleMu1_DiMu_TauDM_Mass7p5to12_NOV27_GetRates_Plots_1000.root") );

  MergeRootfile( Target, FileList );

}

void MergeRootfile( TDirectory *target, TList *sourcelist ) 
{
  //  cout << "Target path: " << target->GetPath() << endl;
  TString path( (char*)strstr( target->GetPath(), ":" ) );
  path.Remove( 0, 2 );

  TFile *first_source = (TFile*)sourcelist->First();
  first_source->cd( path );
  TDirectory *current_sourcedir = gDirectory;
  //gain time, do not add the objects in the list in memory
  Bool_t status = TH1::AddDirectoryStatus();
  TH1::AddDirectory(kFALSE);

  // loop over all keys in this directory
  TChain *globChain = 0;
  TIter nextkey( current_sourcedir->GetListOfKeys() );
  TKey *key, *oldkey=0;
  while ( (key = (TKey*)nextkey())) 
  {
    //keep only the highest cycle number for each key
    if (oldkey && !strcmp(oldkey->GetName(),key->GetName())) continue;

    // read object from first source file
    first_source->cd( path );
    TObject *obj = key->ReadObj();

    if ( obj->IsA()->InheritsFrom( TDirectory::Class() ) ) 
    {
      // it's a subdirectory
      cout << "Found subdirectory " << obj->GetName() << endl;
      // create a new subdir of same name and title in the target file
      target->cd();
      TDirectory *newdir = target->mkdir( obj->GetName(), obj->GetTitle() );

      // newdir is now the starting point of another round of merging
      // newdir still knows its depth within the target file via
      // GetPath(), so we can still figure out where we are in the recursion
      MergeRootfile( newdir, sourcelist );
    }//if
    else if ( obj->IsA()->InheritsFrom( TCanvas::Class() ) )
    {
      std::cout <<"CANVAS" << std::endl;
      TCanvas *c = (TCanvas*)obj;
      std::cout << "Name: " << c->GetName() << std::endl;
      TH1F *h1 = (TH1F*)c->GetPrimitive(c->GetName() );
      int iter = 1;
      if (h1)
      {
        // loop over all source files and add the content of the
        // correspondant histogram to the one pointed to by "h1"
        TFile *nextsource = (TFile*)sourcelist->After( first_source );
        while ( nextsource ) 
        {
  	  iter++;
          // make sure we are at the correct directory level by cd'ing to path
          nextsource->cd( path );
          TKey *key2 = (TKey*)gDirectory->GetListOfKeys()->FindObject(h1->GetName());
          if (key2) 
 	  { 
            TCanvas *c1 = (TCanvas*)key2->ReadObj();
            std::cout << "\titer= " << iter << " \tName: " << c->GetName() << std::endl;
            TH1F *h2 = (TH1F*)c1->GetPrimitive(c1->GetName() );
            h1->Add( h2 );
	    delete h2;
            //delete h2;
          }//if
          nextsource = (TFile*)sourcelist->After( nextsource );
        }// while
      }//h1
    }//if Canvas
    else if ( obj->IsA()->InheritsFrom( TH2::Class() ) ) 
    {    
      // descendant of TH1 -> merge it
      //      cout << "Merging histogram " << obj->GetName() << endl;
      TH2 *h21 = (TH2*)obj;
      // loop over all source files and add the content of the
      // correspondant histogram to the one pointed to by "h21"
      TFile *nextsource = (TFile*)sourcelist->After( first_source );
      while ( nextsource ) 
      {
        // make sure we are at the correct directory level by cd'ing to path
        nextsource->cd( path );
        TKey *key2 = (TKey*)gDirectory->GetListOfKeys()->FindObject(h21->GetName());
        if (key2) 
        { 
          TH2 *h22 = (TH2*)key2->ReadObj();
          h21->Add( h22 );
          delete h22;
        }//if key 2
        nextsource = (TFile*)sourcelist->After( nextsource );
      }//while
    }//if TH1
    else if ( obj->IsA()->InheritsFrom( TH1::Class() ) ) 
    {
      // descendant of TH1 -> merge it
      //      cout << "Merging histogram " << obj->GetName() << endl;
      TH1 *h11 = (TH1*)obj;
      // loop over all source files and add the content of the
      // correspondant histogram to the one pointed to by "h1"
      TFile *nextsource = (TFile*)sourcelist->After( first_source );
      while ( nextsource ) 
      {
        // make sure we are at the correct directory level by cd'ing to path
        nextsource->cd( path );
        TKey *key2 = (TKey*)gDirectory->GetListOfKeys()->FindObject(h11->GetName());
        if (key2) 
 	{
          TH1 *h12 = (TH1*)key2->ReadObj();
          h11->Add( h12 );
          delete h12;
        }//if key 2
        nextsource = (TFile*)sourcelist->After( nextsource );
      }//while
    }//if TH1
    else {

      // object is of no type that we know or can handle
      cout << "Unknown object type, name: " << obj->GetName() << " title: " << obj->GetTitle() << "\t inherits from:" << obj->ClassName() << endl;
    }

    // now write the merged histogram (which is "in" obj) to the target file
    // note that this will just store obj in the current directory level,
    // which is not persistent until the complete directory itself is stored
    // by "target->Write()" below
    if ( obj ) {
      target->cd();

      //!!if the object is a tree, it is stored in globChain...
      if(obj->IsA()->InheritsFrom( TTree::Class() ))
        globChain->Merge(target->GetFile(),0,"keep");
      else
        obj->Write( key->GetName() );
    }

  } // while ( ( TKey *key = (TKey*)nextkey() ) )

  // save modifications to target file
  target->SaveSelf(kTRUE);
  TH1::AddDirectory(status);
}
