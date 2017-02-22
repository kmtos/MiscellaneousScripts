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


void MergeRootFiles_55() {
  // Prepare the files to me merged
  // in an interactive ROOT session, edit the file names
  // Target and FileList, then
  // root > .L MergeRootFiles_55.C
  // root > MergeRootFiles_55()

  Target = TFile::Open( "/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/FINAL_QCD_300to470_SameSignDiMu_FEB9.root", "RECREATE" );
  FileList = new TList();
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_10.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_11.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_12.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_13.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_14.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_15.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_16.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_17.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_18.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_19.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_1.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_20.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_21.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_22.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_23.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_24.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_25.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_26.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_27.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_28.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_29.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_2.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_30.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_31.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_32.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_33.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_34.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_35.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_36.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_37.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_38.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_39.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_3.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_40.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_41.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_42.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_43.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_44.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_45.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_46.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_47.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_48.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_49.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_4.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_50.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_51.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_52.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_53.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_54.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_55.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_5.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_6.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_7.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_8.root") );
  FileList->Add( TFile::Open("/afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_300to470_SameSign_FEB9/QCD_300to470_SameSign_FEB9_9.root") );

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
