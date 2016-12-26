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


void MergeRootFiles_TT() {
  // Prepare the files to me merged
  // in an interactive ROOT session, edit the file names
  // Target and FileList, then
  // root > .L MergeRootFiles_TT.C
  // root > MergeRootFiles_TT()

  Target = TFile::Open( "/home/kyletos/Downloads/TriggerOutput/FINAL_WJ_NewMVA_.root", "RECREATE" );
  FileList = new TList();
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_100.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_101.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_102.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_103.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_104.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_105.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_106.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_107.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_108.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_109.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_10.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_110.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_111.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_112.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_113.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_114.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_115.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_116.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_117.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_118.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_119.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_11.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_120.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_121.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_122.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_123.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_124.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_125.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_126.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_127.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_128.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_129.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_12.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_130.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_131.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_132.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_133.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_134.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_135.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_136.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_137.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_138.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_139.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_13.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_140.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_141.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_142.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_143.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_144.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_145.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_146.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_147.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_148.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_149.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_14.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_150.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_151.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_152.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_153.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_154.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_155.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_156.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_157.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_158.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_159.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_15.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_160.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_161.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_162.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_163.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_164.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_165.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_166.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_167.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_168.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_169.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_16.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_170.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_171.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_172.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_173.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_174.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_175.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_176.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_177.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_178.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_179.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_17.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_180.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_181.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_182.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_183.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_184.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_185.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_186.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_187.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_188.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_189.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_18.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_190.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_191.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_192.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_193.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_194.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_195.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_196.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_197.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_198.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_199.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_19.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_1.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_200.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_20.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_21.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_22.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_23.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_24.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_25.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_26.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_27.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_28.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_29.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_2.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_30.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_31.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_32.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_33.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_34.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_35.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_36.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_37.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_38.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_39.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_3.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_40.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_41.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_42.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_43.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_44.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_45.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_46.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_47.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_48.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_49.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_4.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_50.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_51.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_52.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_53.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_54.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_55.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_56.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_57.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_58.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_59.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_5.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_60.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_61.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_62.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_63.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_64.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_65.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_66.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_67.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_68.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_69.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_6.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_70.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_71.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_72.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_73.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_74.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_75.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_76.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_77.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_78.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_79.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_7.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_80.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_81.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_82.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_83.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_84.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_85.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_86.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_87.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_88.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_89.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_8.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_90.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_91.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_92.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_93.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_94.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_95.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_96.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_97.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_98.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_99.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/FakeRate/WJ_NewMVA_SKIM_BTag_NOV21/WJ_NewMVA_SKIM_BTag_NOV21_9.root") );

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
      TH2 *h1 = (TH2*)obj;
      // loop over all source files and add the content of the
      // correspondant histogram to the one pointed to by "h1"
      TFile *nextsource = (TFile*)sourcelist->After( first_source );
      while ( nextsource ) 
      {
        // make sure we are at the correct directory level by cd'ing to path
        nextsource->cd( path );
        TKey *key2 = (TKey*)gDirectory->GetListOfKeys()->FindObject(h1->GetName());
        if (key2) 
        { 
          TH2 *h2 = (TH2*)key2->ReadObj();
          h1->Add( h2 );
          delete h2;
        }//if key 2
        nextsource = (TFile*)sourcelist->After( nextsource );
      }//while
    }//if TH1
    else if ( obj->IsA()->InheritsFrom( TH1::Class() ) ) 
    {
      // descendant of TH1 -> merge it
      //      cout << "Merging histogram " << obj->GetName() << endl;
      TH1 *h1 = (TH1*)obj;
      // loop over all source files and add the content of the
      // correspondant histogram to the one pointed to by "h1"
      TFile *nextsource = (TFile*)sourcelist->After( first_source );
      while ( nextsource ) 
      {
        // make sure we are at the correct directory level by cd'ing to path
        nextsource->cd( path );
        TKey *key2 = (TKey*)gDirectory->GetListOfKeys()->FindObject(h1->GetName());
        if (key2) 
 	{
          TH1 *h2 = (TH1*)key2->ReadObj();
          h1->Add( h2 );
          delete h2;
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
