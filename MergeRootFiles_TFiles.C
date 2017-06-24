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


void MergeRootFiles_TFiles() {
  // Prepare the files to me merged
  // in an interactive ROOT session, edit the file names
  // Target and FileList, then
  // root > .L MergeRootFiles_TFiles.C
  // root > MergeRootFiles_TFiles()

  Target = TFile::Open( "/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/FINAL_TriggerPlots_DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31.root", "RECREATE" );
  FileList = new TList();
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_100.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_101.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_102.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_103.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_104.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_105.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_106.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_107.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_108.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_109.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_10.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_110.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_111.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_112.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_113.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_114.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_115.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_116.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_117.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_118.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_119.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_11.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_120.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_121.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_122.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_123.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_124.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_125.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_126.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_127.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_128.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_129.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_12.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_130.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_131.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_132.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_133.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_134.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_135.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_136.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_137.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_138.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_139.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_13.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_140.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_141.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_142.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_143.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_144.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_145.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_146.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_147.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_148.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_149.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_14.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_150.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_151.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_152.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_153.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_154.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_155.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_156.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_157.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_158.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_159.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_15.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_160.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_161.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_162.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_163.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_164.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_165.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_166.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_167.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_168.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_169.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_16.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_170.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_171.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_172.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_173.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_174.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_175.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_176.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_177.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_178.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_179.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_17.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_180.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_181.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_182.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_183.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_184.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_185.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_186.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_187.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_188.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_189.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_18.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_190.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_191.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_192.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_193.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_194.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_195.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_196.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_197.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_198.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_199.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_19.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_1.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_200.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_20.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_21.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_22.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_23.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_24.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_25.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_26.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_27.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_28.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_29.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_2.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_30.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_31.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_32.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_33.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_34.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_35.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_36.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_37.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_38.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_39.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_3.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_40.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_41.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_42.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_43.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_44.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_45.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_46.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_47.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_48.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_49.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_4.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_50.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_51.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_52.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_53.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_54.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_55.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_56.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_57.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_58.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_59.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_5.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_60.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_61.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_62.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_63.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_64.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_65.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_66.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_67.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_68.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_69.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_6.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_70.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_71.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_72.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_73.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_74.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_75.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_76.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_77.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_78.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_79.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_7.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_80.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_81.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_82.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_83.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_84.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_85.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_86.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_87.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_88.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_89.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_8.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_90.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_91.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_92.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_93.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_94.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_95.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_96.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_97.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_98.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_99.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateDY/DY_FakeRate_Inv81to101_DiTauDMOnly_MAY31/TFiles/RegionB_Tfile_9.root") );

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
