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

  Target = TFile::Open( "/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/FINAL_Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G.root", "RECREATE" );
  FileList = new TList();
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_100.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_101.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_102.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_103.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_104.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_105.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_106.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_107.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_108.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_109.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_10.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_110.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_111.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_112.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_113.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_114.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_115.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_116.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_117.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_118.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_119.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_11.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_120.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_121.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_122.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_123.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_124.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_125.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_126.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_127.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_128.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_129.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_12.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_130.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_131.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_132.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_133.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_134.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_135.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_136.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_137.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_138.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_139.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_13.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_140.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_141.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_142.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_143.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_144.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_145.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_146.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_147.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_148.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_149.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_14.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_150.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_151.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_152.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_153.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_154.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_155.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_156.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_157.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_158.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_159.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_15.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_160.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_161.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_162.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_163.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_164.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_165.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_166.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_167.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_168.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_169.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_16.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_170.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_171.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_172.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_173.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_174.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_175.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_176.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_177.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_178.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_179.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_17.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_180.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_181.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_182.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_183.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_184.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_185.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_186.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_187.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_188.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_189.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_18.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_190.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_191.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_192.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_193.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_194.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_195.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_196.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_197.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_198.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_199.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_19.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_1.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_200.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_20.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_21.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_22.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_23.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_24.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_25.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_26.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_27.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_28.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_29.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_2.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_30.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_31.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_32.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_33.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_34.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_35.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_36.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_37.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_38.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_39.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_3.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_40.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_41.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_42.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_43.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_44.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_45.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_46.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_47.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_48.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_49.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_4.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_50.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_51.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_52.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_53.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_54.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_55.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_56.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_57.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_58.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_59.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_5.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_60.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_61.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_62.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_63.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_64.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_65.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_66.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_67.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_68.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_69.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_6.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_70.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_71.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_72.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_73.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_74.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_75.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_76.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_77.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_78.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_79.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_7.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_80.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_81.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_82.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_83.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_84.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_85.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_86.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_87.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_88.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_89.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_8.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_90.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_91.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_92.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_93.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_94.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_95.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_96.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_97.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_98.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_99.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G/Upsilon_Mu45_CJ_NoIsoDiTau_JUN22_G_9.root") );

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
