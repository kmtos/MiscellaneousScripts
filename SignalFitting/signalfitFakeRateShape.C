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
void signalfitFakeRateShape()
{

  RooWorkspace w1("w1");

  TFile *filesignal = TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/FINALPLOTS_MiniAOD_SingleMu_MedIsoMu2_TauDMAntiMedIso_FEB8_AFromB.root");
  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/Fit_MiniAOD_SingleMu_MedIsoMu2_TauDMAntiMedIso_FEB8_AFromB.root", "RECREATE");

  TCanvas* c1 = (TCanvas*)filesignal->Get("DiMuInvMass_Central");
  TCanvas* c2 = (TCanvas*)filesignal->Get("DiMuInvMass_Up");
  TCanvas* c3 = (TCanvas*)filesignal->Get("DiMuInvMass_Down");

  TH1F* hC = (TH1F*)c1->GetPrimitive("DiMuInvMass_Central");
  TH1F* hU = (TH1F*)c2->GetPrimitive("DiMuInvMass_Up");
  TH1F* hD = (TH1F*)c3->GetPrimitive("DiMuInvMass_Down");

std::cout << "Get histograms" << std::endl;
  // --- Observable ---
  RooRealVar xU("xU","InvMass",4,30); 
  RooRealVar xD("xD","InvMass",4,30); 
  RooRealVar xC("xC","InvMass",4,30); 
std::cout << " check-1" << std::endl;

std::cout << hC->InheritsFrom(TH1F::Class())  << " " << hU->InheritsFrom(TH1F::Class()) << " " << hD->InheritsFrom(TH1F::Class()) << std::endl;

  // --- Assign histogram dataset to x ---
  RooDataHist *dataC = new RooDataHist("dataC","dataset",xC,hC) ;
  RooDataHist *dataU = new RooDataHist("dataU","dataset",xU,hU) ;
  RooDataHist *dataD = new RooDataHist("dataD","dataset",xD,hD) ;

  TCanvas *cC = new TCanvas("cC","",800,400) ;
  TCanvas *cU = new TCanvas("cU","",800,400) ;
  TCanvas *cD = new TCanvas("cD","",800,400) ;
  RooPlot* xframeC = xC.frame();
  RooPlot* xframeU = xU.frame();
  RooPlot* xframeD = xD.frame();
  
  dataC->plotOn(xframeC);
  dataD->plotOn(xframeD);
  dataU->plotOn(xframeU);

std::cout << "Done with Data" << std::endl;
///////////////////////////////
// Signal 
///////////////////////////////
  RooRealVar mean1C("mean1C","mean1 of Central gaussian", 9.46, 9.3, 9.5) ;
  RooRealVar sigma1C("sigma1C","width of Central gaussian",.1,0.01,1) ;
  RooRealVar mean2C("mean2C","mean2 of Central gaussian", 10.023, 9.85, 10.15) ;
  RooRealVar sigma2C("sigma2C","width of Central gaussian",.1,0.01,1) ;
  RooRealVar mean3C("mean3C","mean3 of Central gaussian", 10.3, 10.15, 10.45) ;
  RooRealVar sigma3C("sigma3C","width of Central gaussian",.1,0.01,1) ;

  RooRealVar mean1D("mean1D","mean1 of Down gaussian", 9.46, 9.3, 9.5) ;
  RooRealVar sigma1D("sigma1D","width of Down gaussian",.1,0.01,1) ;
  RooRealVar mean2D("mean2D","mean2 of Down gaussian", 10.023, 9.85, 10.15) ;
  RooRealVar sigma2D("sigma2D","width of Down gaussian",.1,0.01,1) ;
  RooRealVar mean3D("mean3D","mean3 of Down gaussian", 10.3, 10.15, 10.45) ;
  RooRealVar sigma3D("sigma3D","width of Down gaussian",.1,0.01,1) ;

  RooRealVar mean1U("mean1U","mean1 of Up gaussian", 9.46, 9.3, 9.5) ;
  RooRealVar sigma1U("sigma1U","width of UP gaussian",.1,0.01,1) ;
  RooRealVar mean2U("mean2U","mean2 of Up gaussian", 10.023, 9.85, 10.15) ;
  RooRealVar sigma2U("sigma2U","width of UP gaussian",.1,0.01,1) ;
  RooRealVar mean3U("mean3U","mean3 of Up gaussian", 10.3, 10.15, 10.45) ;
  RooRealVar sigma3U("sigma3U","width of UP gaussian",.1,0.01,1) ;

  xframeC->SetTitle("Fake Rate Eff Central");
  xframeU->SetTitle("Fake Rate Eff Up");
  xframeD->SetTitle("Fake Rate Eff Down");
  RooGaussian *gauss1U = new RooGaussian("gauss1D","gaussian PDF",xU,mean1U,sigma1U) ;
  RooGaussian *gauss1D = new RooGaussian("gauss1U","gaussian PDF",xD,mean1D,sigma1D) ;
  RooGaussian *gauss1C = new RooGaussian("gauss1C","gaussian PDF",xC,mean1C,sigma1C) ;

  RooGaussian *gauss2U = new RooGaussian("gauss2D","gaussian PDF",xU,mean2U,sigma2U) ;
  RooGaussian *gauss2D = new RooGaussian("gauss2U","gaussian PDF",xD,mean2D,sigma2D) ;
  RooGaussian *gauss2C = new RooGaussian("gauss2C","gaussian PDF",xC,mean2C,sigma2C) ;

  RooGaussian *gauss3U = new RooGaussian("gauss3D","gaussian PDF",xU,mean3U,sigma3U) ;
  RooGaussian *gauss3D = new RooGaussian("gauss3U","gaussian PDF",xD,mean3D,sigma3D) ;
  RooGaussian *gauss3C = new RooGaussian("gauss3C","gaussian PDF",xC,mean3C,sigma3C) ;

  RooRealVar ratioG1U("ratioG1U","",.1,0,1);
  RooRealVar ratioG1D("ratioG1D","",.1,0,1);
  RooRealVar ratioG1C("ratioG1C","",.1,0,1);
  
  RooRealVar ratioG2U("ratioG2U","",.1,0,1);
  RooRealVar ratioG2D("ratioG2D","",.1,0,1);
  RooRealVar ratioG2C("ratioG2C","",.1,0,1);

  RooRealVar ratioG3U("ratioG3U","",.1,0,1);
  RooRealVar ratioG3D("ratioG3D","",.1,0,1);
  RooRealVar ratioG3C("ratioG3C","",.1,0,1);

  RooAddPdf sigC("sigC","Signal Central",RooArgList(*gauss1C,*gauss2C,*gauss3C), RooArgList(ratioG1C,ratioG2C,ratioG3C), true); 
  RooAddPdf sigD("sigD","Signal Down"   ,RooArgList(*gauss1D,*gauss2D,*gauss3D), RooArgList(ratioG1D,ratioG2D,ratioG3D), true); 
  RooAddPdf sigU("sigU","Signal Up"     ,RooArgList(*gauss1U,*gauss2U,*gauss3U), RooArgList(ratioG1U,ratioG2U,ratioG3U), true); 

std::cout << "Done with signal" << std::endl;

///////////////////////////////
// Backgroound
///////////////////////////////
  RooRealVar a1C("a1C","a",-.5, -2, 2) ;
  RooRealVar a2C("a2C","a",-1.5 -2, 2) ;
  RooExponential exp1C("exp1C","exponential",xC,a1C) ;
  RooExponential exp2C("exp2C","exponential",xC,a2C) ;
  RooRealVar ratioX1C("ratioX1C","",.1,0,1);
  RooRealVar ratioX2C("ratioX2C","",.1,0,1);
  RooAddPdf bkgC("bkgC","Background Central",RooArgList(exp1C,exp2C), RooArgList(ratioX1C, ratioX2C), true);

  RooRealVar a1U("a1U","a",-.5, -2, 2) ;
  RooRealVar a2U("a2U","a",-1.5,-2, 2) ;
  RooExponential exp1U("exp1U","exponential",xU,a1U) ;
  RooExponential exp2U("exp2U","exponential",xU,a2U) ;
  RooRealVar ratioX1U("ratioX1U","",.1,0,1);
  RooRealVar ratioX2U("ratioX2U","",.1,0,1);
  RooAddPdf bkgU("bkgU","Background Up",RooArgList(exp1U,exp2U), RooArgList(ratioX1U, ratioX2U), true);

  RooRealVar a1D("a1D","a",-.5, -2, 2) ;
  RooRealVar a2D("a2D","a",-1.5,-2, 2) ;
  RooExponential exp1D("exp1D","exponential",xD,a1D) ;
  RooExponential exp2D("exp2D","exponential",xD,a2D) ;
  RooRealVar ratioX1D("ratioX1D","",.1,0,1);
  RooRealVar ratioX2D("ratioX2D","",.1,0,1);
  RooAddPdf bkgD("bkgD","Background Down",RooArgList(exp1D,exp2D), RooArgList(ratioX1D, ratioX2D), true);

std::cout << "Done wit Background" << std::endl;
///////////////////////////////////
// Total Model
///////////////////////////////////
  RooRealVar ratioSigU("ratioSigU","",.1,0,1);
  RooRealVar ratioBakU("ratioBakU","",.1,0,1);

  RooRealVar ratioSigC("ratioSigC","",.1,0,1);
  RooRealVar ratioBakC("ratioBakC","",.1,0,1);

  RooRealVar ratioBakD("ratioBakD","",.1,0,1);
  RooRealVar ratioSigD("ratioSigD","",.1,0,1);

  RooAddPdf  *modelU = new RooAddPdf("modelU","g1+g2+g3+e1+e2",RooArgList(bkgU,sigU), RooArgList(ratioBakU,ratioSigU), true) ;
  RooAddPdf  *modelC = new RooAddPdf("modelC","g1+g2+g3+e1+e2",RooArgList(bkgC,sigC), RooArgList(ratioBakC,ratioSigC), true) ;
  RooAddPdf  *modelD = new RooAddPdf("modelD","g1+g2+g3+e1+e2",RooArgList(bkgD,sigD), RooArgList(ratioBakD,ratioSigD), true) ;

  RooFitResult *rU, *rC, *rD;
  rU = modelU->fitTo(*dataU, SumW2Error(kTRUE));
  rD = modelD->fitTo(*dataD, SumW2Error(kTRUE));
  rC = modelC->fitTo(*dataC, SumW2Error(kTRUE));

std::cout << "Done with Fitting" << std::endl;

///////////////////////////////////
// Plotting
///////////////////////////////////
  modelC->plotOn(xframeC,LineColor(kGreen+2));
  modelD->plotOn(xframeD,LineColor(kGreen+2));
  modelU->plotOn(xframeU,LineColor(kGreen+2));

  sigC.plotOn(xframeC, LineColor(kBlue));
  sigD.plotOn(xframeD, LineColor(kBlue));
  sigU.plotOn(xframeU, LineColor(kBlue));

  exp1C.plotOn(xframeC, LineColor(kRed-2));
  exp2C.plotOn(xframeC, LineColor(kRed+2));
  exp1D.plotOn(xframeD, LineColor(kRed-2));
  exp2D.plotOn(xframeD, LineColor(kRed+2));
  exp1U.plotOn(xframeU, LineColor(kRed-2));
  exp2U.plotOn(xframeU, LineColor(kRed+2));

std::cout << "Done with Plotting" << std::endl;

//  RooChi2Var chi2("chi2","chi2", *model,*data);
//  Double_t val = chi2.getVal() ;
//  std::cout << "nBins= " << data->numEntries() << std::endl;
//  std::cout << "largestValueBin=" << largestValueBin << "largestValue= " << largestValue << std::endl;
//  std::cout << "sumFilledBins= " << sumFilledBins << std::endl;
//  std::cout << "lowest non-empty bin from peak= " << lowerBin << std::endl;
//  std::cout << "largest non-empty bin from peak= " << upperBin << std::endl;
//  std::cout << "nPara= " << model->getParameters(data)->selectByAttrib("Constant",kFALSE)->getSize() << std::endl;
//  std::cout << "chi square result: " << xframe1->chiSquare() << std::endl;
//  std::cout << "chi2.getVal()= " << val << std::endl;
//  std::cout << "chi2.getVal() / chi square result= " << val / xframe1->chiSquare() << std::endl;
//
//  stringstream nBinsLine, chi2GetValLine, chi2Line, nParamsLine;
//  nBinsLine << "nBins: " << data->numEntries();
//  chi2GetValLine << "chi2: " << val;
//  chi2Line << "RedChi2: " <<  xframe1->chiSquare();
//  nParamsLine << "nParamFit: " << model->getParameters(data)->selectByAttrib("Constant",kFALSE)->getSize();
//  TPaveText *pt = new TPaveText(.8,.8,.95,.95, "brNDC");
//  pt->AddText(nBinsLine.str().c_str() );
//  pt->AddText(nParamsLine.str().c_str() );
//  pt->AddText(chi2Line.str().c_str() );
//  pt->AddText(chi2GetValLine.str().c_str() );
  outFile->cd();
  cU->Update(); 
  xframeU->Draw() ;
  cU->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/Fit_DiMuMass_Up.png");
  cU->Write();

  cD->Update(); 
  xframeD->Draw() ;
  cD->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/Fit_DiMuMass_Down.png");
  cD->Write();

  cC->Update(); 
  xframeC->Draw() ;
  cC->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/Fit_DiMuMass_Central.png");
  cC->Write();

//  pt->Draw();
  outFile->Close();
  w1.Print();

}
