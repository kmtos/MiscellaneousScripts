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

  Target = TFile::Open( "/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/FINAL_Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange.root", "RECREATE" );
  FileList = new TList();
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_100.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_101.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_102.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_103.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_104.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_105.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_106.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_107.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_108.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_109.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_10.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_110.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_111.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_112.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_113.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_114.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_115.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_116.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_117.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_118.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_119.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_11.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_120.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_121.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_122.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_123.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_124.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_125.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_126.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_127.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_128.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_129.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_12.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_130.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_131.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_132.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_133.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_134.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_135.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_136.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_137.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_138.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_139.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_13.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_140.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_141.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_142.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_143.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_144.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_145.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_146.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_147.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_148.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_149.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_14.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_150.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_151.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_152.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_153.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_154.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_155.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_156.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_157.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_158.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_159.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_15.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_160.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_161.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_162.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_163.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_164.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_165.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_166.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_167.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_168.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_169.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_16.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_170.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_171.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_172.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_173.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_174.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_175.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_176.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_177.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_178.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_179.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_17.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_180.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_181.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_182.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_183.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_184.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_185.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_186.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_187.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_188.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_189.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_18.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_190.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_191.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_192.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_193.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_194.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_195.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_196.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_197.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_198.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_199.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_19.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_1.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_200.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_20.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_21.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_22.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_23.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_24.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_25.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_26.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_27.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_28.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_29.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_2.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_30.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_31.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_32.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_33.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_34.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_35.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_36.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_37.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_38.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_39.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_3.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_40.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_41.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_42.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_43.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_44.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_45.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_46.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_47.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_48.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_49.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_4.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_50.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_51.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_52.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_53.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_54.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_55.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_56.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_57.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_58.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_59.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_5.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_60.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_61.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_62.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_63.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_64.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_65.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_66.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_67.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_68.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_69.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_6.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_70.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_71.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_72.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_73.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_74.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_75.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_76.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_77.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_78.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_79.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_7.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_80.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_81.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_82.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_83.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_84.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_85.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_86.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_87.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_88.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_89.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_8.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_90.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_91.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_92.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_93.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_94.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_95.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_96.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_97.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_98.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_99.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/Upsilon/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange/Upsilon_NoIsoDiTau_NoTauSelec_NoTrigSelec_NewSubFilter_APR26_SmallRange_9.root") );

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
