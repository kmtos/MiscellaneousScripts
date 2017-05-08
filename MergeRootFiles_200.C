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


void MergeRootFiles_200() {
  // Prepare the files to me merged
  // in an interactive ROOT session, edit the file names
  // Target and FileList, then
  // root > .L MergeRootFiles_200.C
  // root > MergeRootFiles_200()

  Target = TFile::Open( "/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/FINAL_DYHighMass_SignalRegion_MAR22.root", "RECREATE" );
  FileList = new TList();
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_100.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_101.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_102.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_103.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_104.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_105.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_106.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_107.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_108.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_109.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_10.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_110.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_111.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_112.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_113.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_114.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_115.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_116.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_117.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_118.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_119.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_11.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_120.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_121.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_122.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_123.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_124.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_125.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_126.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_127.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_128.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_129.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_12.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_130.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_131.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_132.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_133.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_134.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_135.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_136.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_137.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_138.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_139.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_13.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_140.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_141.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_142.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_143.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_144.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_145.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_146.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_147.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_148.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_149.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_14.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_150.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_151.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_152.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_153.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_154.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_155.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_156.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_157.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_158.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_159.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_15.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_160.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_161.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_162.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_163.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_164.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_165.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_166.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_167.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_168.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_169.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_16.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_170.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_171.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_172.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_173.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_174.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_175.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_176.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_177.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_178.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_179.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_17.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_180.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_181.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_182.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_183.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_184.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_185.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_186.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_187.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_188.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_189.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_18.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_190.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_191.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_192.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_193.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_194.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_195.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_196.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_197.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_198.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_199.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_19.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_1.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_200.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_20.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_21.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_22.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_23.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_24.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_25.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_26.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_27.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_28.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_29.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_2.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_30.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_31.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_32.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_33.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_34.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_35.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_36.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_37.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_38.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_39.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_3.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_40.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_41.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_42.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_43.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_44.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_45.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_46.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_47.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_48.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_49.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_4.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_50.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_51.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_52.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_53.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_54.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_55.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_56.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_57.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_58.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_59.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_5.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_60.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_61.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_62.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_63.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_64.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_65.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_66.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_67.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_68.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_69.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_6.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_70.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_71.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_72.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_73.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_74.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_75.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_76.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_77.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_78.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_79.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_7.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_80.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_81.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_82.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_83.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_84.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_85.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_86.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_87.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_88.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_89.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_8.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_90.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_91.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_92.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_93.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_94.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_95.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_96.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_97.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_98.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_99.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/DYHighMass_SignalRegion_MAR22/DYHighMass_SignalRegion_MAR22_9.root") );

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
