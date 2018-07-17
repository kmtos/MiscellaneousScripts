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

void TTreeSum() {

  TFile f("/home/kyletos/Downloads/FINAL_DYH_MASS60to120_RegionD.root");
  TTree *tree = (TTree*)f.Get("lumiTree/LumiTree");
  TH1F *h = new TH1F("h", "", 2000000, -10000000, 10000000);
  tree->Draw("summedWeights>>h");
  float summedWeights;
  tree->SetBranchAddress("summedWeights", &summedWeights);
  Long64_t nentries = tree->GetEntries();
  double sum = 0;
  for (Long64_t i = 0; i < nentries; i++) 
  {  
    tree->GetEntry(i);
    cout << fixed<< "summedWeights=" << summedWeights << endl;
    sum += summedWeights;
  }//for

  cout << fixed << "\n\nSUM=" << sum << endl;
}



