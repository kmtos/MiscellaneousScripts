#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooWorkspace.h"
#include "RooPlot.h"
#include "TCanvas.h"
#include "TAxis.h"
using namespace RooFit ;


void  rooFit_workspace()
{


RooWorkspace w("w",kTRUE) ;
w.factory("Gaussian::gauss(mes[5.20,5.30],mean[5.28,5.2,5.3],width[0.0027,0.001,1])");
w.factory("ArgusBG::argus(mes,5.291,argpar[-20,-100,-1])") ;
w.factory("SUM::sum(nsig[200,0,10000]*gauss,nbkg[800,0,10000]*argus)") ;

// --- Generate a toyMC sample from composite PDF ---
RooDataSet *data = w::sum.generate(w::mes,2000) ;

// --- Perform extended ML fit of composite PDF to toy data ---
w::sum.fitTo(*data) ;

// --- Plot toy data and composite PDF overlaid ---
RooPlot* mesframe = w::mes.frame() ;
data->plotOn(mesframe) ;
w::sum.plotOn(mesframe) ;
w::sum.plotOn(mesframe,Components(w::argus),LineStyle(kDashed)) ;

mesframe->Draw()  ;

}//rooFit
