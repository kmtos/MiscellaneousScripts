#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooArgusBG.h"
#include "RooRealVar.h"
#include "RooDataSet.h"

#include "RooGaussian.h"
#include "RooCBShape.h"
#include "RooExponential.h"
#include "RooBreitWigner.h"

#include "RooConstVar.h"
#include "RooDataHist.h"
#include "RooFitResult.h"
#include "RooMinuit.h"
#include "RooPlot.h"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TAxis.h"
#include "TH1.h"
#include <iostream>
#include <fstream>

/*

See http://hadron.physics.fsu.edu/~skpark/document/ROOT/jdhaas_RooFit.pdf for info on the p.d.f. types and their addition.

*/

using namespace RooFit ;
void signalfit()
{

  RooWorkspace w1("w1");

  TFile *filesignal = TFile::Open("FILENAME");
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/Fit_OUTPUTNAME", "RECREATE");

  TH1F* hist = (TH1F*)filesignal->Get("InvMassFullRange");
//  hist->Rebin(2);

  int sumFilledBins = 0, largestValueBin = -1;
  double largestValue = 0;
  for (int i=1; i <=hist->GetNbinsX(); i++)
  {
    if (hist->GetBinContent(i) != 0)
      sumFilledBins++;
    if (hist->GetBinContent(i) > largestValue)
    {
      largestValueBin = i;
      largestValue = hist->GetBinContent(i);
    }//if
  }//for i 

  int lowerBin = -1, upperBin = -1;
  for (int i = largestValueBin; i > 0; i--)
  {
    if (hist->GetBinContent(i) == 0)
      break;
    lowerBin = i;
  }//for
  for (int i = largestValueBin; i <= hist->GetNbinsX(); i++)
  {
    if (hist->GetBinContent(i) == 0)
      break;
    upperBin = i;
  }//for

  // --- Observable ---
//  RooRealVar x("x","InvMass",2,25);
  RooRealVar x("x","InvMass", 8.825, AMASS.175);//hist->GetBinLowEdge(lowerBin), hist->GetBinLowEdge(upperBin)+hist->GetBinWidth(upperBin));
  
  // --- Assign histogram dataset to x ---
  RooDataHist *data = new RooDataHist("data","dataset",x,hist) ;
  TCanvas *c = new TCanvas("c","c",800,400) ;
  RooPlot* xframe1 = x.frame();
  data->plotOn(xframe1);

///////////////////////////////
// Gaussian
///////////////////////////////
  RooRealVar mean("mean","mean of gaussian", AMASS,3,23) ;
  RooRealVar sigma("sigma","width of gaussian",.35,0.01,1) ;
  xframe1->SetTitle("Gaussian");
  RooGaussian *model = new RooGaussian("model","gaussian PDF",x,mean,sigma) ;

/////////////////////////////////
//// Voigtian
/////////////////////////////////
//  RooRealVar mean("mean","mean of gaussian", AMASS,3,23) ;
//  RooRealVar sigma("sigma","width of gaussian",.35,0.01,1) ;
//  RooRealVar width("width","width",5.0, 0.000001, 120.0);
//  RooVoigtian *model = new RooVoigtian("model","gauss",x,mean,width,sigma);
//  xframe1->SetTitle("Voigtian");


/////////////////////////////////
////  Crystal Ball
/////////////////////////////////
//  RooRealVar mean("mean","mean", AMASS,3,23) ;
//  RooRealVar sigma("sigma","sigma",0.35,.01,1.0);
//  RooRealVar a("a","a",1.0,0.0,10.0);
//  RooRealVar n("n","n",1.0,0.0,10.0);
//  RooCBShape *model = new RooCBShape("model","cb",x,mean,sigma,a,n);
//  xframe1->SetTitle("Crystal Ball");

/////////////////////////////////
//// Double Crystal Ball
/////////////////////////////////
//  RooRealVar mean("mean","mean", AMASS, AMASS*.9, AMASS*1.1) ;
//  RooRealVar sigma("sigma","sigma",0.35,.01,1.0);
//  RooRealVar a1("a1","a1",1.3,0.0,5.0);
//  RooRealVar n1("n1","n1",5.1,0.0,10.0);
//
//  RooRealVar mean2("mean2","mean2", AMASS, AMASS*.9, AMASS*1.1);
//  RooRealVar sigma2("sigma2","sigma2",0.35,0.001,1);
//  RooRealVar a2("a2","a2",-1,-5.0,0.0);
//  RooRealVar n2("n2","n2",5.1,0.0,50.0);
//
//  RooCBShape cb1("cb1","cb1",x,mean,sigma,a1,n1);
//  RooRealVar cbsig("cbsig","cbsig",.1,0,1);
//
//  RooCBShape cb2("cb2","cb2",x,mean2,sigma2,a2,n2);
//  RooRealVar cb2sig("cb2sig","cb2sig",.1,0,1);
//  xframe1->SetTitle("Double Crystal Ball");
//
//  RooAddPdf *model = new RooAddPdf("model","cb1 vs cb2",RooArgList(cb1,cb2),RooArgList(cbsig,cb2sig), true);

  RooFitResult* r;
  r = model->fitTo(*data, SumW2Error(kTRUE));
  model->plotOn(xframe1,LineColor(kGreen+2));

  RooChi2Var chi2("chi2","chi2", *model,*data);
  Double_t val = chi2.getVal() ;
  std::cout << "nBins= " << data->numEntries() << std::endl;
  std::cout << "largestValueBin=" << largestValueBin << "largestValue= " << largestValue << std::endl;
  std::cout << "sumFilledBins= " << sumFilledBins << std::endl;
  std::cout << "lowest non-empty bin from peak= " << lowerBin << std::endl;
  std::cout << "largest non-empty bin from peak= " << upperBin << std::endl;
  std::cout << "nPara= " << model->getParameters(data)->selectByAttrib("Constant",kFALSE)->getSize() << std::endl;
  std::cout << "chi square result: " << xframe1->chiSquare() << std::endl;
  std::cout << "chi2.getVal()= " << val << std::endl;
  std::cout << "chi2.getVal() / chi square result= " << val / xframe1->chiSquare() << std::endl;

  stringstream nBinsLine, chi2GetValLine, chi2Line, nParamsLine;
  nBinsLine << "nBins: " << data->numEntries();
  chi2GetValLine << "chi2: " << val;
  chi2Line << "RedChi2: " <<  xframe1->chiSquare();
  nParamsLine << "nParamFit: " << model->getParameters(data)->selectByAttrib("Constant",kFALSE)->getSize();
  TPaveText *pt = new TPaveText(.8,.8,.95,.95, "brNDC");
  pt->AddText(nBinsLine.str().c_str() );
  pt->AddText(nParamsLine.str().c_str() );
  pt->AddText(chi2Line.str().c_str() );
  pt->AddText(chi2GetValLine.str().c_str() );
  c->Update(); 
  xframe1->Draw() ;
  outFile->cd();
  pt->Draw();
  c->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/IMAGENAME.png");
  c->Write();
  outFile->Close();
  w1.Print();

}
