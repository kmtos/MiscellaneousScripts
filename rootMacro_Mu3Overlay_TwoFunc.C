#include <string.h>
#include "TChain.h"
#include "TFile.h"
#include "TH1.h"
#include "TTree.h"
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

void GetFormatAndDraw(TFile &infile, TFile *outFile, TLegend *leg, string legName, const Color_t, TCanvas& cLargestPt, TCanvas& cClosestdR, TCanvas& cMu3Iso, int canvasQuadrant, TCanvas &cPtLargestvsIso, TCanvas &cPtvsIsoNoRel, double scale, bool firstFile);

void rootMacro_TESTMu3Overlay_TwoFunctions()
{

  gStyle->SetOptStat(kFALSE);
  gStyle->SetEndErrorSize(7);

  //Old DMs
  TFile infileTT     ("/home/kyletos/Downloads/TriggerOutput/FINAL_TT_NoMuTauHad_FineBin_OCT21.root");
  //TFile infileWJ     ("/home/kyletos/Downloads/TriggerOutput/FINAL_WJ_NoMuTauHad_FineBin_OCT21.root");
  TFile infileDY     ("/home/kyletos/Downloads/TriggerOutput/FINAL_DY_NoMuTauHad_FineBin_OCT21.root");
  TFile infileSig    ("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_Sig125.root");
  TFile infileSigBig ("/home/kyletos/Downloads/TriggerOutput/OutputHistograms_Sig750.root");

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/CombinedPlots/comb_Mu3Overlay_XSecNorm_FineBin_OCT24.root", "RECREATE");

  ///////////////////////
  // Total Overal Plots
  ///////////////////////
  TCanvas Mu3PtLargestCanvasTOT_("Mu3PtLargestCanvasTOT","",600,600);
  TCanvas ClosetsdRCanvasTOT_("ClosetsdRCanvasTOT" ,"",600,600);
  TCanvas Mu3IsoCanvasTOT_("Mu3IsoCanvasTOT","",600,600);
  TCanvas Mu3PtvsIsoNoRelCanvasTOT_("Mu3PtvsIsoNoRelCanvasTOT","",600,600);
  Mu3PtvsIsoNoRelCanvasTOT_.Divide(2,3);
  TCanvas Mu3PtLargestvsIsoCanvasTOT_("Mu3PtLargestvsIsoCanvasTOT","",600,600);
  Mu3PtLargestvsIsoCanvasTOT_.Divide(2,3);

  Mu3PtLargestCanvasTOT_.SetGrid(1,1);
  ClosetsdRCanvasTOT_.SetGrid(1,1);
  Mu3IsoCanvasTOT_.SetGrid(1,1);

  Mu3PtLargestCanvasTOT_.SetLogy();
  ClosetsdRCanvasTOT_.SetLogy();
  Mu3IsoCanvasTOT_.SetLogy();
/*
  Mu3PtLargestCanvasTOT_.SetLogx();
  ClosetsdRCanvasTOT_.SetLogx();
  Mu3IsoCanvasTOT_.SetLogx();
*/

  leg = new TLegend(0.1,0.7,0.25,0.9);

  std::cout << "Bar   Scale(831.76*20,000.0/37,081,058)  =  " << 831.76*20000.0/37081058.0  << std::endl;
  std::cout << "WJets   Scale(61,526.7*20,000.0/47,737,675)= " << 61526.7*20000.0/47737675.0  << std::endl;
  std::cout << "DY m=50 Scale(1921.8*3*20,000.0/55,663,144)=  " << 1921.8*3*20000.0/55663144.0  << std::endl;
  std::cout << "mH=125  Scale(48.90*20,000.0/1000.0)=  " << 48.90*20000.0/1000.0  << std::endl;
  std::cout << "mH=750  Scale(0.4969*20,000.0/1000.0)= " << 0.4969*20000.0/1000.0  << std::endl;

  double scaleTT = 831.76*20000.0/37081058.0, scaleWJ = 61526.7*20000.0/47737675.0, scaleDY = 1921.8*3*20000.0/55663144.0, scaleH125a9 =  48.90*20000.0/1000.0, scaleH750a9 = 0.4969*20000.0/1000.0;
  string TTName = "TT", DYName = "DY" , WJName = "WJ", H125a9Name = "H125a9", H750a9Name = "H750a9";
  
 
  GetFormatAndDraw(infileTT, outFile, leg, TTName, kBlue+1, Mu3PtLargestCanvasTOT_, ClosetsdRCanvasTOT_, Mu3IsoCanvasTOT_, 1, Mu3PtLargestvsIsoCanvasTOT_, Mu3PtvsIsoNoRelCanvasTOT_, scaleTT, true);
  GetFormatAndDraw(infileDY, outFile, leg, DYName, kRed+1,  Mu3PtLargestCanvasTOT_, ClosetsdRCanvasTOT_, Mu3IsoCanvasTOT_, 2, Mu3PtLargestvsIsoCanvasTOT_, Mu3PtvsIsoNoRelCanvasTOT_, scaleDY, false);

cout << "Histograms Drawn" << endl;

  outFile->cd();
  Mu3PtLargestCanvasTOT_.Write();
  ClosetsdRCanvasTOT_.Write();
  Mu3IsoCanvasTOT_.Write();

  Mu3PtLargestvsIsoCanvasTOT_.Write();
  Mu3PtvsIsoNoRelCanvasTOT_.Write();
  outFile->Write();
  outFile->Close();
cout << "end" << endl;


}//rootMacro_TESTMu3Overlay_TwoFunctions


void GetFormatAndDraw(TFile &infile, TFile *outFile, TLegend *leg, string legName, const Color_t color, TCanvas& cLargestPt, TCanvas& cClosestdR, TCanvas& cMu3Iso, int canvasQuadrant, TCanvas &cPtLargestvsIso, TCanvas &cPtvsIsoNoRel, double scale, bool firstFile)
{
  infile.cd("Mu3Analyzer");
  TH1F*  Mu3PtLargest_ = (TH1F*)gDirectory->Get("Mu3PtLargest");
  TH1F*  ClosetsdR_ = (TH1F*)gDirectory->Get("ClosetsdR");
  TH1F*  Mu3Iso_ = (TH1F*)gDirectory->Get("Mu3Iso");
  TH2F*  PtMu3vsIsoLargestPt_ = (TH2F*)gDirectory->Get("PtMu3vsIsoLargestPt");  
  TH2F*  PtMu3vsIsoNoRel_ = (TH2F*)gDirectory->Get("PtMu3vsIsoNoRel");

cout << "Histograms assigned." << endl; 

  Mu3PtLargest_->Scale(scale );
  ClosetsdR_->Scale(scale );
  Mu3Iso_->Scale(scale );
  
cout << "Histograms scaled" << endl;

  //////////////////////////////////
  //  TGraphErrors from TH1
  //////////////////////////////////
  TGraphAsymmErrors* FinalMu3PtLargest_ = new TGraphAsymmErrors(Mu3PtLargest_);
  TGraphAsymmErrors* FinalClosetsdR_ = new TGraphAsymmErrors(ClosetsdR_);
  TGraphAsymmErrors* FinalMu3Iso_ = new TGraphAsymmErrors(Mu3Iso_);

  // Setting colors
  FinalMu3PtLargest_->SetMarkerColor(color);
  FinalClosetsdR_->SetMarkerColor(color);
  FinalMu3Iso_->SetMarkerColor(color);

  //Setting Marker Size
  FinalMu3PtLargest_->SetMarkerSize(.07);
  FinalClosetsdR_->SetMarkerSize(.07);
  FinalMu3Iso_->SetMarkerSize(.07);
  
  //Set line Color
  FinalMu3PtLargest_->SetLineColor(color);
  FinalClosetsdR_->SetLineColor(color);
  FinalMu3Iso_->SetLineColor(color);

  //Set Titles
  FinalMu3PtLargest_->GetXaxis()->SetTitle("Largest Mu3 p_{T}");
  FinalClosetsdR_->GetXaxis()->SetTitle("#DeltaR(Mu3, closest Mu1 or Mu2)");
  FinalMu3Iso_->GetXaxis()->SetTitle("Relative Iso in cone < .4 of Mu3");

  //Set Titles
  FinalMu3PtLargest_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalClosetsdR_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  FinalMu3Iso_->SetTitle("Mu1 tight, Mu2 loose, Mu1 p_{T} > 45, Mu2 p_{T} > 15, #DeltaR(Mu1,Mu2) < 1.5, Mu1,Mu2 Iso < 1.5");
  
  //Set Line Width
  FinalMu3PtLargest_->SetLineWidth(2);
  FinalClosetsdR_->SetLineWidth(2);
  FinalMu3Iso_->SetLineWidth(2);
  
cout << "Attributes set." << endl;  

  //Making the Legend
  leg->AddEntry(FinalMu3PtLargest_, legName.c_str(),"L");

  //Drawing all of the Overlaid Lepton Matched HIstograms
  cLargestPt.cd();
  if (firstFile)
    FinalMu3PtLargest_->Draw();
  else
    FinalMu3PtLargest_->Draw("SAME");
  leg->Draw();

  cClosestdR.cd();
  if (firstFile)
    FinalClosetsdR_->Draw();
  else
    FinalClosetsdR_->Draw("SAME");
  leg->Draw();

  cMu3Iso.cd();
  if (firstFile)
    FinalMu3Iso_->Draw();
  else
    FinalMu3Iso_->Draw("SAME");
  leg->Draw();

  cPtvsIsoNoRel.cd(canvasQuadrant);
  PtMu3vsIsoNoRel_->Draw("COLZ");

  cPtLargestvsIso.cd(canvasQuadrant);
  PtMu3vsIsoLargestPt_->Draw("COLZ");

cout << "Histograms Drawn" << endl;

}//rootMacro_BBA_combine
