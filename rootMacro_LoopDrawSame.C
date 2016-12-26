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


void root_OverlayFancy() {
  // Prepare the files to me merged
  // in an interactive ROOT session, edit the file names
  // Target and FileList, then
  // root > .L root_OverlayFancy.C
  // root > root_OverlayFancy()

  Target = TFile::Open( "/home/kyletos/Downloads/TriggerOutput/FINAL_DY_NoMuTauHad_OCT21.root", "RECREATE" );
  FileList = new TList();
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_DY_Big/OutputHistograms_100.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_DY_Big/OutputHistograms_101.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_DY_Big/OutputHistograms_102.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_DY_Big/OutputHistograms_103.root") );
  FileList->Add( TFile::Open("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_DY_Big/OutputHistograms_99.root") );

  MergeRootfile( Target, FileList );

}

void MergeRootfile( TDirectory *target, TList *sourcelist) 
{
  TString colors[20] = ["kBlack","kBlue","kRed+1","kGreen+1","kGray","kViolet-2","kYellow-7","kOrange+8","kAzure+8","kPink-9"];
  //  cout << "Target path: " << target->GetPath() << endl;
  TString path( (char*)strstr( target->GetPath(), ":" ) );
  path.Remove( 0, 2 );
  TFile *first_source = (TFile*)sourcelist->First();
  first_source->cd( path );
  TDirectory *current_sourcedir = gDirectory;
  Bool_t status = TH1::AddDirectoryStatus();
  TH1::AddDirectory(kFALSE);

  // loop over all keys in this directory
  TChain *globChain = 0;
  TIter nextkey( current_sourcedir->GetListOfKeys() );
  TKey *key, *oldkey=0;
  while ( (key = (TKey*)nextkey())) 
  {
    TCanvas canvas("canvas","",600,600);
    if (oldkey && !strcmp(oldkey->GetName(),key->GetName())) continue;
    // read object from first source file
    first_source->cd( path );
    TObject *obj = key->ReadObj();

    if ( obj->IsA()->InheritsFrom( TDirectory::Class() ) ) 
    {
      cout << "Found subdirectory " << obj->GetName() << endl;
      target->cd();
      TDirectory *newdir = target->mkdir( obj->GetName(), obj->GetTitle() );
      // newdir is now the starting point of another round of merging newdir still knows its depth within the target file via GetPath(), so we can still figure out where we are in the recursion
      MergeRootfile( newdir, sourcelist );
    }//if
    else if ( obj->IsA()->InheritsFrom( TCanvas::Class() ) )
    {
      TCanvas *c = (TCanvas*)obj;
      std::cout << "CANVAS:   Name= " << c->GetName() << std::endl;
      TH1F *h1 = (TH1F*)c->GetPrimitive(c->GetName() );
      int count = 0;
      if (h1)
      {
        h1->SetLineColor(colors[count] );
        h1->SetMarkerColor(colors[count] );
	canvas.cd();
 	h1->Draw();
        TLegend *leg = new TLegend(0.1,0.7,0.25,0.9);
        leg->AddEntry(h1, h1->GetName() ,"L");
        // loop over all source files and add the content of the correspondant histogram to the one pointed to by "h1"
        TFile *nextsource = (TFile*)sourcelist->After( first_source );
        while ( nextsource ) 
        {
          // make sure we are at the correct directory level by cd'ing to path
          nextsource->cd( path );
          TKey *key2 = (TKey*)gDirectory->GetListOfKeys()->FindObject(h1->GetName());
          if (key2) 
 	  {	
	    count++;
            TCanvas *c1 = (TCanvas*)key2->ReadObj();
            TH1F *h2 = (TH1F*)c1->GetPrimitive(c1->GetName() );
            h2->SetLineColor(colors[count] );
	    h2->SetMarkerColor(colors[count] );
	    h2->Draw("SAME");
            leg->AddEntry(h2, h2->GetName() ,"L");
	    delete h2;
            //delete h2;
          }//if
          nextsource = (TFile*)sourcelist->After( nextsource );
        }// while
	leg->Draw();
      }//h1
    }//if Canvas
    else if ( obj->IsA()->InheritsFrom( TH1::Class() ) ) 
    {
      // descendant of TH1 -> merge it
      //      cout << "Merging histogram " << obj->GetName() << endl;
      TH1 *h1 = (TH1*)obj;
      // loop over all source files and add the content of the
      // correspondant histogram to the one pointed to by "h1"
      int count = 0;
      h1->SetLineColor(colors[count] );
      h1->SetMarkerColor(colors[count] );
      canvas.cd();
      h1->Draw();
      TLegend *leg = new TLegend(0.1,0.7,0.25,0.9);
      leg->AddEntry(h1, h1->GetName() ,"L");
      TFile *nextsource = (TFile*)sourcelist->After( first_source );
      while ( nextsource ) 
      {
	count++;
        // make sure we are at the correct directory level by cd'ing to path
        nextsource->cd( path );
        TKey *key2 = (TKey*)gDirectory->GetListOfKeys()->FindObject(h1->GetName());
        if (key2) 
 	{
          TH1 *h2 = (TH1*)key2->ReadObj();
          h2->SetLineColor(colors[count] );
          h2->SetMarkerColor(colors[count] );
	  h2->Draw("SAME");
          leg->AddEntry(h2, h2->GetName() ,"L");
        }//if key 2
        nextsource = (TFile*)sourcelist->After( nextsource );
      }//while
      leg->Draw();
    }//if TH1
    else 
      cout << "Unknown object type, name: " << obj->GetName() << " title: " << obj->GetTitle() << "\t inherits from:" << obj->ClassName() << endl;

    // now write the merged histogram (which is "in" obj) to the target file
    // note that this will just store obj in the current directory level,
    // which is not persistent until the complete directory itself is stored
    // by "target->Write()" below
    if ( obj ) 
    {
      target->cd();
      canvas.Write( key->GetName() );
    }//
    canvas.Close();
  } // while ( ( TKey *key = (TKey*)nextkey() ) )

  // save modifications to target file
  target->SaveSelf(kTRUE);
  TH1::AddDirectory(status);
}
