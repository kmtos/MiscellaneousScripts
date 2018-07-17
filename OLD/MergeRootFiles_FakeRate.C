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


void MergeRootFiles_FakeRate() {
  // Prepare the files to me merged
  // in an interactive ROOT session, edit the file names
  // Target and FileList, then
  // root > .L MergeRootFiles_FakeRate.C
  // root > MergeRootFiles_FakeRate()

  Target = TFile::Open( "/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/FINAL_NoIsoDiTau_SEP4_H_v3.root", "RECREATE" );
  FileList = new TList();
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_100.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_101.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_102.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_103.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_104.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_105.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_106.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_107.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_108.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_109.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_10.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_110.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_111.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_112.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_113.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_114.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_115.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_116.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_117.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_118.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_119.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_11.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_120.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_121.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_122.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_123.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_124.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_125.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_126.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_127.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_128.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_129.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_12.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_130.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_131.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_132.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_133.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_134.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_135.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_136.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_137.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_138.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_139.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_13.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_140.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_141.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_142.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_143.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_144.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_145.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_146.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_147.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_148.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_149.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_14.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_150.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_151.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_152.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_153.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_154.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_155.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_156.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_157.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_158.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_159.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_15.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_160.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_161.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_162.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_163.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_164.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_165.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_166.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_167.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_168.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_169.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_16.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_170.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_171.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_172.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_173.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_174.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_175.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_176.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_177.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_178.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_179.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_17.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_180.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_181.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_182.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_183.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_184.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_185.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_186.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_187.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_188.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_189.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_18.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_190.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_191.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_192.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_193.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_194.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_195.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_196.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_197.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_198.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_199.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_19.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_1.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_200.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_20.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_21.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_22.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_23.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_24.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_25.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_26.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_27.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_28.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_29.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_2.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_30.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_31.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_32.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_33.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_34.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_35.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_36.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_37.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_38.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_39.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_3.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_40.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_41.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_42.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_43.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_44.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_45.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_46.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_47.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_48.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_49.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_4.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_50.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_51.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_52.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_53.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_54.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_55.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_56.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_57.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_58.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_59.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_5.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_60.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_61.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_62.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_63.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_64.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_65.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_66.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_67.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_68.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_69.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_6.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_70.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_71.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_72.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_73.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_74.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_75.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_76.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_77.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_78.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_79.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_7.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_80.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_81.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_82.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_83.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_84.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_85.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_86.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_87.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_88.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_89.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_8.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_90.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_91.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_92.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_93.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_94.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_95.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_96.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_97.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_98.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_99.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/NoIsoDiTau_SEP4_H_v3/NoIsoDiTau_SEP4_H_v3_Plots_9.root") );

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
