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


void MergeRootFiles_DY() {
  // Prepare the files to me merged
  // in an interactive ROOT session, edit the file names
  // Target and FileList, then
  // root > .L MergeRootFiles_DY.C
  // root > MergeRootFiles_DY()

  Target = TFile::Open( "/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/FINAL_DY_NewMVA_BDScan_DEC20.root", "RECREATE" );
  FileList = new TList();
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_100.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_101.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_102.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_103.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_104.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_105.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_106.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_107.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_108.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_109.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_10.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_110.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_111.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_112.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_113.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_114.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_115.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_116.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_117.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_118.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_119.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_11.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_120.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_121.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_122.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_123.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_124.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_125.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_126.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_127.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_128.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_129.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_12.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_130.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_131.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_132.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_133.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_134.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_135.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_136.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_137.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_138.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_139.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_13.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_140.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_141.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_142.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_143.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_144.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_145.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_146.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_147.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_148.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_149.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_14.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_150.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_151.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_152.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_153.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_154.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_155.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_156.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_157.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_158.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_159.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_15.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_160.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_161.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_162.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_163.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_164.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_165.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_166.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_167.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_168.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_169.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_16.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_170.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_171.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_172.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_173.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_174.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_175.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_176.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_177.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_178.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_179.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_17.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_180.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_181.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_182.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_183.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_184.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_185.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_186.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_187.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_188.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_189.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_18.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_190.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_191.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_192.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_193.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_194.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_195.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_196.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_197.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_198.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_199.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_19.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_1.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_200.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_20.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_21.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_22.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_23.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_24.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_25.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_26.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_27.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_28.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_29.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_2.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_30.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_31.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_32.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_33.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_34.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_35.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_36.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_37.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_38.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_39.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_3.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_40.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_41.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_42.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_43.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_44.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_45.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_46.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_47.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_48.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_49.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_4.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_50.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_51.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_52.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_53.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_54.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_55.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_56.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_57.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_58.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_59.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_5.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_60.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_61.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_62.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_63.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_64.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_65.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_66.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_67.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_68.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_69.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_6.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_70.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_71.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_72.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_73.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_74.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_75.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_76.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_77.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_78.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_79.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_7.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_80.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_81.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_82.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_83.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_84.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_85.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_86.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_87.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_88.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_89.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_8.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_90.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_91.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_92.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_93.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_94.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_95.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_96.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_97.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_98.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_99.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/DY_NewMVA_BDScan_DEC20/DY_NewMVA_BDScan_DEC20_9.root") );

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
