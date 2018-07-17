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

#include "/home/kyletos/Downloads/RootFiles/StandardPlots.C"


void MergeRootfile( TDirectory *target, TList *sourcelist );


void SettingStyleFiles() { 
  // Prepare the files to me merged
  // in an interactive ROOT session, edit the file names
  // Target and FileList, then
  // root > .L MergeRootFiles_200.C
  // root > MergeRootFiles_200()

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/Formatted_SAMPLENAME.root", "RECREATE" );
  TFile *inFile = TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DIR_NAME/FINAL_SAMPLENAME.root");
  setTDRStyle(true);

  TIter next(inFile->GetListOfKeys());
  TKey *key;
  outFile->cd();
  while ((key = (TKey*)next())) 
  {
    TClass *cl = gROOT->GetClass(key->GetClassName());
    if (!cl->InheritsFrom("TCanvas")) continue;
    TCanvas *canv_ = (TCanvas*)key->ReadObj();

    TObject *obj;
    TIter next(canv_->GetListOfPrimitives());
    while ((obj=next()) ) 
    {
      if (obj->InheritsFrom("TH1")) 
      {
        cout << obj->GetName() << std::endl;
        TH1F* hist_ = (TH1F*)canv_->GetPrimitive(obj->GetName() );
        string name = obj->GetName();
        name += "Canvas";
        TCanvas *outcanv =  new TCanvas(name.c_str(),"",600,600);
        SetCanvas(outcanv, outcanv->GetWw(),outcanv->GetWh() );
        SetHist1D(hist_, kBlack, kBlack, kWhite, 1.0, hist_->GetXaxis()->GetTitle(), hist_->GetYaxis()->GetTitle());
        outcanv->cd();
	hist_->Draw();
        CMS_lumi(outcanv, 4, 33, true, true, true);
        outcanv->Write();
        delete outcanv;
      }//if
    }//while obj
  }//while key
  outFile->Close();
}//SettingStyleFiles
