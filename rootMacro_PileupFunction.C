#include <string.h>
#include "TChain.h"
#include "TFile.h"
#include "TH1.h"
#include "TKey.h"
#include "Riostream.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TGraphAsymmErrors.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "iostream"
#include "fstream"
#include "TMath.h"

void rootMacro_PileupFunction()
{

  gStyle->SetOptStat(kFALSE);
  gStyle->SetEndErrorSize(7);

  //Old DMs
  TFile infile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/PileUpData_72660.root");

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/PileupWeights_72660.root", "RECREATE");

cout << "Files Created" << endl;
  std::vector<double> pileupMC = {1.78653e-05 ,2.56602e-05 ,5.27857e-05 ,8.88954e-05 ,0.000109362 ,0.000140973 ,0.000240998 ,0.00071209 ,0.00130121 ,0.00245255 ,0.00502589 ,0.00919534 ,0.0146697 ,0.0204126 ,0.0267586 ,0.0337697 ,0.0401478 ,0.0450159 ,0.0490577 ,0.0524855 ,0.0548159 ,0.0559937 ,0.0554468 ,0.0537687 ,0.0512055 ,0.0476713 ,0.0435312 ,0.0393107 ,0.0349812 ,0.0307413 ,0.0272425 ,0.0237115 ,0.0208329 ,0.0182459 ,0.0160712 ,0.0142498 ,0.012804 ,0.011571 ,0.010547 ,0.00959489 ,0.00891718 ,0.00829292 ,0.0076195 ,0.0069806 ,0.0062025 ,0.00546581 ,0.00484127 ,0.00407168 ,0.00337681 ,0.00269893 ,0.00212473 ,0.00160208 ,0.00117884 ,0.000859662 ,0.000569085 ,0.000365431 ,0.000243565 ,0.00015688 ,9.88128e-05 ,6.53783e-05 ,3.73924e-05 ,2.61382e-05 ,2.0307e-05 ,1.73032e-05 ,1.435e-05 ,1.36486e-05 ,1.35555e-05 ,1.37491e-05 ,1.34255e-05 ,1.33987e-05 ,1.34061e-05 ,1.34211e-05 ,1.34177e-05 ,1.32959e-05 ,1.33287e-05};

  //////////////////////////////
  // Getting the  Histograms
  //////////////////////////////
  TH1F*  pileup_ = (TH1F*)infile.Get("pileup");
  pileup_->Scale(1/pileup_->Integral() );
cout << "Histograms assigned." << endl; 

/////////////////////////////
// Prepping the output plots
/////////////////////////////
  TH1F* pileupWeight_ = new TH1F("PileupWeights"    , "PileupWeights (Data/MC);# of Verticies", 75, 0, 75);
  for (int i = 0; i < 75; i++)
  {
    std::cout << pileupMC[i] << std::endl;
    std::cout << pileup_ << std::endl;
    std::cout << pileup_->GetBinContent(i) <<  std::endl;
    pileupWeight_->SetBinContent(i, pileup_->GetBinContent(i) / pileupMC[i] );
    std::cout << "pileupWeight=" << pileup_->GetBinContent(i) / pileupMC[i] << "\tMC=" << pileupMC[i] << "\tData=" << pileup_->GetBinContent(i) << std::endl;
  }//for i 

//////////////////////////////////
// Setting the Titles for Clarity
//////////////////////////////////

cout << "Histograms Drawn" << endl;

  outFile->cd();

  pileupWeight_->Write();

  outFile->Write();
  outFile->Close();
cout << "end" << endl;

}//rootMacro_BBA_combine
