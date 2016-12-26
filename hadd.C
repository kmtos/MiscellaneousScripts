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


void hadd() {
  // Prepare the files to me merged
  // in an interactive ROOT session, edit the file names
  // Target and FileList, then
  // root > .L hadd.C
  // root > hadd()

  Target = TFile::Open( "FINAL_DY_NewMVA_VariousHTBDisc_SEP20.root", "RECREATE" );

  FileList = new TList();
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_100.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_32.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_55.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_78.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_10.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_33.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_56.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_79.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_11.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_34.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_57.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_7.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_12.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_35.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_58.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_80.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_13.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_36.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_59.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_81.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_14.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_37.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_5.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_82.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_15.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_38.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_60.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_83.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_16.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_39.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_61.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_84.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_17.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_3.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_62.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_85.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_18.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_40.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_63.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_86.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_19.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_41.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_64.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_87.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_1.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_42.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_65.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_88.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_20.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_43.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_66.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_89.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_21.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_44.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_67.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_8.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_22.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_45.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_68.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_90.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_23.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_46.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_69.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_91.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_24.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_47.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_6.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_92.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_25.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_48.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_70.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_93.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_26.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_49.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_71.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_94.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_27.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_4.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_72.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_95.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_28.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_50.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_73.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_96.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_29.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_51.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_74.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_97.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_2.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_52.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_75.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_98.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_30.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_53.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_76.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_99.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_31.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_54.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_77.root") );
  FileList->Add( TFile::Open("DY_Trig_CJ_NewMVA_Plots_Single_VariousHTBDisc_SEP20_9.root") );

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

    if ( obj->IsA()->InheritsFrom( TCanvas::Class() ) )
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
