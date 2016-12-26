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


void MergeRootFiles_WJ() {
  // Prepare the files to me merged
  // in an interactive ROOT session, edit the file names
  // Target and FileList, then
  // root > .L MergeRootFiles_WJ.C
  // root > MergeRootFiles_WJ()

  Target = TFile::Open( "/home/kyletos/Downloads/TriggerOutput/FINAL_WJ_NoMuTauHad_FineBin_OCT21.root", "RECREATE" );
  FileList = new TList();
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_100.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_101.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_102.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_103.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_104.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_105.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_106.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_107.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_108.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_109.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_10.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_110.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_111.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_112.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_113.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_114.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_115.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_116.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_117.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_118.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_119.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_11.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_120.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_121.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_122.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_123.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_124.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_125.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_126.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_127.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_128.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_129.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_12.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_130.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_131.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_132.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_133.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_134.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_135.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_136.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_137.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_138.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_139.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_13.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_140.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_141.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_142.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_143.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_144.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_145.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_146.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_147.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_148.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_149.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_14.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_150.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_151.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_152.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_153.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_154.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_155.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_156.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_157.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_158.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_159.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_15.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_160.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_161.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_162.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_163.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_164.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_165.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_166.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_167.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_168.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_169.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_16.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_170.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_171.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_172.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_173.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_174.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_175.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_176.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_177.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_178.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_179.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_17.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_180.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_181.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_182.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_183.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_184.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_185.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_186.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_187.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_188.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_189.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_18.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_190.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_191.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_192.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_193.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_194.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_195.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_196.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_197.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_198.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_199.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_19.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_1.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_200.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_20.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_21.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_22.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_23.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_24.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_25.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_26.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_27.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_28.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_29.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_2.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_30.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_31.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_32.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_33.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_34.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_35.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_36.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_37.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_38.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_39.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_3.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_40.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_41.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_42.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_43.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_44.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_45.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_46.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_47.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_48.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_49.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_4.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_50.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_51.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_52.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_53.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_54.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_55.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_56.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_57.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_58.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_59.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_5.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_60.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_61.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_62.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_63.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_64.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_65.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_66.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_67.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_68.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_69.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_6.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_70.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_71.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_72.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_73.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_74.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_75.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_76.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_77.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_78.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_79.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_7.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_80.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_81.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_82.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_83.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_84.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_85.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_86.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_87.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_88.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_89.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_8.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_90.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_91.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_92.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_93.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_94.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_95.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_96.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_97.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_98.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_99.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_WJ_Fine/OutputHistograms_9.root") );

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
