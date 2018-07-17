//////////////////////////////////////////////////////////////////////////
//
// 'MULTIDIMENSIONAL MODELS' RooFit tutorial macro #308
// 
// Making 2/3 dimensional plots of p.d.f.s and datasets
//
//
//
// 07/2008 - Wouter Verkerke 
// 
/////////////////////////////////////////////////////////////////////////

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooConstVar.h"
#include "RooGaussian.h"
#include "RooProdPdf.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TH1.h"
#include "RooPlot.h"
using namespace RooFit ;


void roofit_tutorial_03()
{

  // C r e a t e   2 D   m o d e l   a n d   d a t a s e t
  // -----------------------------------------------------

  // Create observables
  RooRealVar x("x","x",-5,5) ;
  RooRealVar y("y","y",-5,5) ;

  // Create parameters
  RooRealVar a0("a0","a0",-0.5,-5,5) ;
  RooRealVar a1("a1","a1",-0.5,-1,1) ;
  RooRealVar sigma("sigma","width of gaussian",1.5) ;

  // Create interpreted function f(y) = a0 - a1*sqrt(10*abs(y))
  RooFormulaVar fy("fy","a0+a1*(y)",RooArgSet(y,a0,a1)) ;

  // Create gauss(x,f(y),s)
  RooGaussian model("model","Gaussian with shifting mean",x,fy,sigma) ;

  RooRealVar b0("b0","b0",-0.2);
 
  //  RooExponential();
  RooExponential model_exp("model_exp","model_exp",y,b0);
  RooProdPdf mxy("mxy","(model)*(model_exp)",RooArgSet(model,model_exp)); // from slide 78 of ppt

  // Sample dataset from gauss(x,y)
  RooDataSet* data = model.generate(RooArgSet(x,y),10000) ;
 

  RooDataSet* newdata = mxy.generate(RooArgSet(x,y),10000);

  // M a k e   2 D   p l o t s   o f   d a t a   a n d   m o d e l
  // -------------------------------------------------------------

  // Create and fill ROOT 2D histogram (20x20 bins) with contents of dataset
  //TH2D* hh_data = data->createHistogram("hh_data",x,Binning(20),YVar(y,Binning(20))) ;
  TH1* hh_data = data->createHistogram("x,y",20,20) ;

  // Create and fill ROOT 2D histogram (50x50 bins) with sampling of pdf
  //TH2D* hh_pdf = model.createHistogram("hh_model",x,Binning(50),YVar(y,Binning(50))) ;
  TH1* hh_pdf = model.createHistogram("x,y",50,50) ;
  hh_pdf->SetLineColor(kRed) ;

  TH1* hh_datanew = newdata->createHistogram("x,y",20,20);
  TH1* hh_pdfnew = mxy.createHistogram("x,y",50,50);
  hh_pdfnew->SetLineColor(kBlue);

  // C r e a t e   3 D   m o d e l   a n d   d a t a s e t
  // -----------------------------------------------------

  // Create observables
  RooRealVar z("z","z",-5,5) ;

  RooGaussian gz("gz","gz",z,RooConst(0),RooConst(2)) ;
  RooProdPdf model3("model3","model3",RooArgSet(model,gz)) ;

  RooDataSet* data3 = model3.generate(RooArgSet(x,y,z),10000) ;

  RooProdPdf mxy3("mxy3","mxy3",RooArgSet(mxy,gz));
  RooDataSet* data3new = mxy3.generate(RooArgSet(x,y,z),10000);
  
  // M a k e   3 D   p l o t s   o f   d a t a   a n d   m o d e l
  // -------------------------------------------------------------

  // TAKEN FROM RF315 AND MODIFIED

  // M a r g i n a l i z e   m ( x , y )   t o   m ( x )                                            
  // ----------------------------------------------------                                           

  // modelx(x) = Int model(x,y) dy                                                                  
  RooAbsPdf* mxyprojection = mxy.createProjection(y) ;


  // Sample 1000 events from modelx                                                                 
  RooAbsData* projectiondata = mxyprojection->generateBinned(x,15000) ;

  // Fit modelx to toy data                                                                         
  mxyprojection->fitTo(*projectiondata,Verbose()) ;

  // Plot modelx over data                                                                          
  RooPlot* frame = x.frame(40) ;
  projectiondata->plotOn(frame) ;
  mxyprojection->plotOn(frame) ;

  // Make 2D histogram of model(x,y)                                                                
  TH1* hhprojection = mxyprojection.createHistogram("x,y") ;
  hhprojection->SetLineColor(kBlue) ;

  TCanvas *c9 = new TCanvas("rf315_thirdtutorialplots","rf315_thirdtutorialplots",800,400);
  c9->Divide(2);
  c9->cd(1) ; gPad->SetLeftMargin(0.20) ; hh_pdfnew->GetZaxis()->SetTitleOffset(2.5) ; hh_pdfnew->Draw("surf");
  c9->cd(2) ; gPad->SetLeftMargin(0.15) ; frame->GetYaxis()->SetTitleOffset(1.4) ; frame->Draw();
  //c9->cd(2) ; gPad->SetLeftMargin(0.20) ; hhprojection->GetZaxis()->SetTitleOffset(2.5) ; hhprojection->Draw("surf") ;



}
