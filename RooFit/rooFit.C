#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooProdPdf.h"
#include "RooAddPdf.h"
#include "RooExtendPdf.h"
#include "RooSimultaneous.h"
#include "RooFitResult.h"
#include "RooBinning.h"
#include "RooLandau.h"
#include "RooMinuit.h"
#include "RooGenericPdf.h"
#include "RooGaussModel.h"
#include "RooNumIntConfig.h"
#include "RooFFTConvPdf.h"
#include "RooPlot.h"
#include "RooDataHist.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TH1.h"
using namespace RooFit ;


void  rooFit()
{

  // --- Observable ---
  RooRealVar mes("mes","m_{ES} (GeV)",5.20,5.30) ;
  
  // --- Parameters ---
  RooRealVar sigmean("sigmean","B^{#pm} mass",5.28,5.20,5.30) ;
  RooRealVar sigwidth("sigwidth","B^{#pm} width",0.0027,0.001,1.) ;
  
  // --- Build Gaussian PDF ---
  RooGaussian signal("signal","signal PDF",mes,sigmean,sigwidth) ;

  // --- Build Argus background PDF ---
  RooRealVar argpar("argpar","argus shape parameter",-20.0,-100.,-1.) ;
  RooArgusBG background("background","Argus PDF",mes,RooConst(5.291),argpar) ;
  
  // --- Construct signal+background PDF ---
  RooRealVar nsig("nsig","#signal events",200,0.,10000) ;
  RooRealVar nbkg("nbkg","#background events",800,0.,10000) ;
  RooAddPdf model("model","g+a",RooArgList(signal,background),RooArgList(nsig,nbkg)) ;
  
  // --- Generate a toyMC sample from composite PDF ---
  RooDataSet *data = model.generate(mes,2000) ;
  
  // --- Perform extended ML fit of composite PDF to toy data ---
  model.fitTo(*data) ;
  
  // --- Plot toy data and composite PDF overlaid ---
  RooPlot* mesframe = mes.frame(Bins(10), Title("LL and profileLL in frac") ) ;
  data->plotOn(mesframe) ;
//  model.plotOn(mesframe) ;
//  model.plotOn(mesframe,Components(background),LineStyle(kDashed)) ;




}//rooFit
