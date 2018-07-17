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

void MergeRootfile( TDirectory *target, TList *sourcelist );


void SavingHistograms() { 
  // Prepare the files to me merged
  // in an interactive ROOT session, edit the file names
  // Target and FileList, then
  // root > .L MergeRootFiles_200.C
  // root > MergeRootFiles_200()

  gStyle->SetOptStat(111100);
  gStyle->SetStatY(0.5);
  gStyle->SetStatX(0.5);
  gStyle->SetStatW(0.2);
  gStyle->SetStatH(0.2); 
  TFile *inFile = TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/DIR_NAME.root");

  TIter next(inFile->GetListOfKeys());
  TKey *key;
  while ((key = (TKey*)next())) 
  {
    TClass *cl = gROOT->GetClass(key->GetClassName());
    if (!cl->InheritsFrom("TCanvas")) continue;
    TCanvas *canv_ = (TCanvas*)key->ReadObj();


    TObject *obj;
    TIter next(canv_->GetListOfPrimitives());
    while ((obj=next()) ) 
    {
      if (obj->InheritsFrom("TPad")) 
      {
        cout << obj->GetName() << std::endl;
        TH1F* hist_ = (TH1F*)canv_->GetPrimitive(obj->GetName() );
        string name = obj->GetName();
        name += "Canvas";
        TCanvas *outcanv =  new TCanvas(name.c_str(),"",600,600);
        outcanv->cd();
	hist_->Draw();
        TImage *img = TImage::Create();
	string imgName = "/home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/Plots/DIR_NAME/";
        imgName += obj->GetName();
        imgName += ".png";
        std::cout << "imgName=" << imgName.c_str() << std::endl;
        img->FromPad(outcanv);
        img->WriteImage(imgName.c_str() );
        delete outcanv;
        delete img;
      }//if
    }//while obj
  }//while key
}//SavingHistograms
