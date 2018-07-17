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


void MergeRootFiles_Upsilon() {
  // Prepare the files to me merged
  // in an interactive ROOT session, edit the file names
  // Target and FileList, then
  // root > .L MergeRootFiles_Upsilon.C
  // root > MergeRootFiles_Upsilon()

  Target = TFile::Open( "/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/FINAL_Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB.root", "RECREATE" );
  FileList = new TList();
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_100.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_101.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_102.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_103.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_104.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_105.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_106.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_107.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_108.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_109.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_10.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_110.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_111.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_112.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_113.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_114.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_115.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_116.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_117.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_118.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_119.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_11.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_120.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_121.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_122.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_123.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_124.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_125.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_126.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_127.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_128.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_129.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_12.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_130.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_131.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_132.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_133.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_134.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_135.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_136.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_137.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_138.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_139.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_13.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_140.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_141.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_142.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_143.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_144.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_145.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_146.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_147.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_148.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_149.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_14.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_150.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_151.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_152.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_153.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_154.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_155.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_156.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_157.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_158.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_159.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_15.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_160.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_161.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_162.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_163.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_164.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_165.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_166.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_167.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_168.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_169.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_16.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_170.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_171.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_172.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_173.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_174.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_175.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_176.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_177.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_178.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_179.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_17.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_180.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_181.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_182.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_183.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_184.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_185.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_186.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_187.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_188.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_189.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_18.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_190.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_191.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_192.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_193.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_194.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_195.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_196.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_197.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_198.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_199.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_19.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_1.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_200.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_20.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_21.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_22.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_23.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_24.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_25.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_26.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_27.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_28.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_29.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_2.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_30.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_31.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_32.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_33.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_34.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_35.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_36.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_37.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_38.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_39.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_3.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_40.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_41.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_42.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_43.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_44.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_45.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_46.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_47.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_48.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_49.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_4.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_50.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_51.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_52.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_53.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_54.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_55.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_56.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_57.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_58.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_59.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_5.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_60.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_61.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_62.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_63.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_64.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_65.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_66.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_67.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_68.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_69.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_6.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_70.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_71.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_72.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_73.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_74.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_75.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_76.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_77.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_78.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_79.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_7.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_80.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_81.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_82.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_83.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_84.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_85.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_86.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_87.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_88.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_89.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_8.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_90.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_91.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_92.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_93.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_94.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_95.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_96.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_97.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_98.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_99.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB/Upsilon_Mu51_NoIsoDiTau_JUL19_G_RegionB_9.root") );

  MergeRootfile( Target, FileList );

}

void MergeRootfile( TDirectory *target, TList *sourcelist ) {

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
