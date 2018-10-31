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

void LookAtToys() { 

  TFile *f = new TFile("/home/kyletos/Downloads/higgsCombineTest.GenerateOnly.mH7.88888.root");
  f.cd("toys");
  RooDataSet *ds2 = (RooDataSet*)gDirectory->Get("toy_2")
  RooDataSet *ds3 = (RooDataSet*)gDirectory->Get("toy_3")
  RooDataSet *ds4 = (RooDataSet*)gDirectory->Get("toy_4")
  RooDataSet *ds5 = (RooDataSet*)gDirectory->Get("toy_5")
  

  TFile *f = new TFile("../Downloads/mmmt_mm_parametric.root");
  RooWorkspace *w = (RooWorkspace*)f->Get("w");
  RooRealVar *y = (RooRealVar*)w->var("y");
  RooAbsPdf *pdf_PP = (RooAbsPdf*)w->pdf("bg_PP_y");
  RooArgSet *args = (RooArgSet*)pdf_PP->getVariables();
  args->setRealValue("lambda_conty1_PP_y",-0.022377359071031);
  args->setRealValue("erfScale_erf1_PP_y",0.055854375141331514);
  args->setRealValue("erfShift_erf1_PP_y",55.28135840843543);
  yFrame_PP = y.frame()
  ds2->plotOn(yFrame_PP, ROOT.Range(0,1200), ROOT.RooFit.Name("data"))
  pdf_PP->plotOn(yFrame_PP, ROOT.RooFit.LineWidth(2), ROOT.RooFit.Range(0,1200), ROOT.RooFit.Name("Erf"))



}//LookAtToys
