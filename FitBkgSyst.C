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

void FitBkgSyst() { 
  gStyle->SetOptFit(1);
  TFile f("../Downloads/CombineFitDiagnostics750.root");
  TCanvas c;
  c.cd()
  TH1 *H = (TH1*)f.Get("h1");
  H->Fit("gaus","");
  H->Draw();
  
  TFile *outFile = new TFile("/home/kyletos/Downloads/BiasStudy750.root", "RECREATE");
  outFile->cd();
  H->Write();
  c.Write();
  outFile->Write();
  outFile ->Close();

}//LookAtToys
