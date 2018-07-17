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

void rootMacro_OverlayABCD()
{

  gStyle->SetOptStat(kFALSE);
  gStyle->SetEndErrorSize(7);

  //Old DMs
  TFile infileMCNoIso("/home/kyletos/Downloads/RootFiles/ABCD_Tests/NoIsoDiTau/comb_NoIsoDiTau_SEP4_SmallBin.root");
  TFile infileMCSig("/home/kyletos/Downloads/RootFiles/ABCD_Tests/SignalRegion/comb_SignalRegion_SEP4_SmallBin.root");
  TFile infileData("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/FINAL_AllEra_NoIsoDiTau_SEP4.root");

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/OverlaidDataAndMC_FakeRateEstimates_All_SEP4.root", "RECREATE");

cout << "Files Created" << endl;

  ////////////////
  // MCNoIsoJets
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasMCNoIso = (TCanvas*)infileMCNoIso.Get("InvMassTauMuMu1Canvas");
  TCanvas *InvMassTauMuMu2CanvasMCNoIso = (TCanvas*)infileMCNoIso.Get("InvMassTauMuMu2Canvas");
  TCanvas *InvMassFakeWeightCanvasMCNoIso = (TCanvas*)infileMCNoIso.Get("InvMassFakeWeightCanvas");
  TCanvas *PtMu1FakeWeightCanvasMCNoIso = (TCanvas*)infileMCNoIso.Get("PtMu1FakeWeightCanvas");
  TCanvas *EtaFakeWeightCanvasMCNoIso = (TCanvas*)infileMCNoIso.Get("EtaFakeWeightCanvas");
  TCanvas *DRFakeWeightCanvasMCNoIso = (TCanvas*)infileMCNoIso.Get("DRFakeWeightCanvas");
  TCanvas *InvMassFakeWeightZoomCanvasMCNoIso = (TCanvas*)infileMCNoIso.Get("InvMassFakeWeightZoomCanvas");
  TCanvas *TauVisMassZoomCanvasMCNoIso = (TCanvas*)infileMCNoIso.Get("TauVisMassZoomCanvas");

  ////////////////
  // MCSigJets
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasMCSig = (TCanvas*)infileMCSig.Get("InvMassTauMuMu1Canvas");
  TCanvas *InvMassTauMuMu2CanvasMCSig = (TCanvas*)infileMCSig.Get("InvMassTauMuMu2Canvas");
  TCanvas *InvMassFakeWeightCanvasMCSig = (TCanvas*)infileMCSig.Get("InvMassFakeWeightCanvas");
  TCanvas *PtMu1FakeWeightCanvasMCSig = (TCanvas*)infileMCSig.Get("PtMu1FakeWeightCanvas");
  TCanvas *EtaFakeWeightCanvasMCSig = (TCanvas*)infileMCSig.Get("EtaFakeWeightCanvas");
  TCanvas *DRFakeWeightCanvasMCSig = (TCanvas*)infileMCSig.Get("DRFakeWeightCanvas");
  TCanvas *InvMassFakeWeightZoomCanvasMCSig = (TCanvas*)infileMCSig.Get("InvMassFakeWeightZoomCanvas");
  TCanvas *TauVisMassZoomCanvasMCSig = (TCanvas*)infileMCSig.Get("TauVisMassZoomCanvas");

  ////////////////
  // Data
  ////////////////
  TCanvas *InvMassTauMuMu1CanvasData = (TCanvas*)infileData.Get("InvMassTauMuMu1");
  TCanvas *InvMassTauMuMu2CanvasData = (TCanvas*)infileData.Get("InvMassTauMuMu2");
  TCanvas *InvMassFakeWeightCanvasData = (TCanvas*)infileData.Get("InvMassFakeWeight");
  TCanvas *PtMu1FakeWeightCanvasData = (TCanvas*)infileData.Get("PtMu1FakeWeight");
  TCanvas *EtaFakeWeightCanvasData = (TCanvas*)infileData.Get("EtaFakeWeight");
  TCanvas *DRFakeWeightCanvasData = (TCanvas*)infileData.Get("DRFakeWeight");
  TCanvas *InvMassFakeWeightZoomCanvasData = (TCanvas*)infileData.Get("InvMassFakeWeightZoom");
  TCanvas *TauVisMassCanvasData = (TCanvas*)infileData.Get("TauVisMass");
  TCanvas *TauVisMassZoomCanvasData = (TCanvas*)infileData.Get("TauVisMassZoom");

cout << "Got Canvases" << endl;

  //////////////////////////////
  // Getting the MCNoIso Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1MCNoIso_ = (TH1F*)InvMassTauMuMu1CanvasMCNoIso->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2MCNoIso_ = (TH1F*)InvMassTauMuMu2CanvasMCNoIso->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightMCNoIso_ = (TH1F*)InvMassFakeWeightCanvasMCNoIso->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightMCNoIso_ = (TH1F*)PtMu1FakeWeightCanvasMCNoIso->GetPrimitive("PtMu1FakeWeight");
  TH1F*  EtaFakeWeightMCNoIso_  = (TH1F*)EtaFakeWeightCanvasMCNoIso->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightMCNoIso_ = (TH1F*)DRFakeWeightCanvasMCNoIso->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomMCNoIso_     = (TH1F*)InvMassFakeWeightZoomCanvasMCNoIso->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  TauVisMassZoomMCNoIso_    = (TH1F*)TauVisMassZoomCanvasMCNoIso->GetPrimitive("TauVisMassZoom");

  //////////////////////////////
  // Getting the MCSig Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1MCSig_ = (TH1F*)InvMassTauMuMu1CanvasMCSig->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2MCSig_ = (TH1F*)InvMassTauMuMu2CanvasMCSig->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightMCSig_ = (TH1F*)InvMassFakeWeightCanvasMCSig->GetPrimitive("InvMassFakeWeight");
  TH1F*  PtMu1FakeWeightMCSig_ = (TH1F*)PtMu1FakeWeightCanvasMCSig->GetPrimitive("PtMu1FakeWeight");
  TH1F*  EtaFakeWeightMCSig_  = (TH1F*)EtaFakeWeightCanvasMCSig->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightMCSig_ = (TH1F*)DRFakeWeightCanvasMCSig->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomMCSig_     = (TH1F*)InvMassFakeWeightZoomCanvasMCSig->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  TauVisMassZoomMCSig_    = (TH1F*)TauVisMassZoomCanvasMCSig->GetPrimitive("TauVisMassZoom");

  // Getting the Data Histograms
  //////////////////////////////
  TH1F*  InvMassTauMuMu1Data_ = (TH1F*)InvMassTauMuMu1CanvasData->GetPrimitive("InvMassTauMuMu1");
  TH1F*  InvMassTauMuMu2Data_ = (TH1F*)InvMassTauMuMu2CanvasData->GetPrimitive("InvMassTauMuMu2");
  TH1F*  InvMassFakeWeightData_ = (TH1F*)InvMassFakeWeightCanvasData->GetPrimitive("InvMassFakeWeight");
std::cout << InvMassFakeWeightData_ << std::endl;
  TH1F*  PtMu1FakeWeightData_ = (TH1F*)PtMu1FakeWeightCanvasData->GetPrimitive("PtMu1FakeWeight");
  TH1F*  EtaFakeWeightData_  = (TH1F*)EtaFakeWeightCanvasData->GetPrimitive("EtaFakeWeight");
  TH1F*  DRFakeWeightData_ = (TH1F*)DRFakeWeightCanvasData->GetPrimitive("DRFakeWeight");
  TH1F*  InvMassFakeWeightZoomData_     = (TH1F*)InvMassFakeWeightZoomCanvasData->GetPrimitive("InvMassFakeWeightZoom");
  TH1F*  TauVisMassZoomData_    = (TH1F*)TauVisMassZoomCanvasData->GetPrimitive("TauVisMassZoom");

cout << "Histograms assigned." << endl; 

//  std::cout << "Int(InvMassTauMuMu1Data_)=" << InvMassTauMuMu1Data_->Integral() << "\nINT(InvMassTauMuMu2Data_)=" << InvMassTauMuMu2Data_->Integral() << "\nInt(InvMassFakeWeightData_)=" << InvMassFakeWeightData_->Integral() << "\nINT(PtMu1FakeWeightData_)=" << PtMu1FakeWeightData_->Integral() << "\nINT(EtaFakeWeightData_)=" << EtaFakeWeightData_->Integral() << "\nINT(DRFakeWeightData_)=" << DRFakeWeightData_->Integral() << std::endl;

/////////////////////////////
// Prepping the output plots
/////////////////////////////
  TCanvas InvMassTauMuMu1Canvas("InvMassTauMuMu1","",600,600);
  TCanvas InvMassTauMuMu2Canvas("InvMassTauMuMu2","",600,600);
  TCanvas InvMassFakeWeightCanvas("InvMassFakeWeight","",600,600);
  TCanvas PtMu1FakeWeightCanvas("PtMu1FakeWeight","",600,600);
  TCanvas EtaFakeWeightCanvas("EtaFakeWeight","",600,600);
  TCanvas DRFakeWeightCanvas("DRFakeWeight","",600,600);
  TCanvas InvMassFakeWeightZoomCanvas("InvMassFakeWeightZoom","",600,600);
  TCanvas TauVisMassCanvas("TauVisMass","",600,600);
  TCanvas TauVisMassZoomCanvas("TauVisMassZoom","",600,600);

  InvMassTauMuMu1Canvas.SetGrid(1,1);
  InvMassTauMuMu2Canvas.SetGrid(1,1);
  InvMassFakeWeightCanvas.SetGrid(1,1);
  PtMu1FakeWeightCanvas.SetGrid(1,1);
  EtaFakeWeightCanvas.SetGrid(1,1);
  DRFakeWeightCanvas.SetGrid(1,1);
  InvMassFakeWeightZoomCanvas.SetGrid(1,1);
  TauVisMassCanvas.SetGrid(1,1);
  TauVisMassZoomCanvas.SetGrid(1,1);

  InvMassTauMuMu1Canvas.Divide(2,1);
  InvMassTauMuMu2Canvas.Divide(2,1);
  InvMassFakeWeightCanvas.Divide(2,1);
  PtMu1FakeWeightCanvas.Divide(2,1);
  EtaFakeWeightCanvas.Divide(2,1);
  DRFakeWeightCanvas.Divide(2,1);
  InvMassFakeWeightZoomCanvas.Divide(2,1);
  TauVisMassCanvas.Divide(2,1);
  TauVisMassZoomCanvas.Divide(2,1);
std::cout << "check1" << std::endl;

  // Making the TLegend
  leg = new TLegend(0.1,0.7,0.25,0.9);
  leg->AddEntry(InvMassTauMuMu1MCNoIso_, "MC", "L" );

  //Drawing all of the Overlaid Lepton Matched HIstograms
  InvMassTauMuMu1Canvas.cd(1);
  InvMassTauMuMu1MCNoIso_->SetTitle("NoIsodiTau");
  InvMassTauMuMu1MCNoIso_->Draw();
  InvMassTauMuMu1Data_->SetLineColor(kRed);
  InvMassTauMuMu1Data_->SetMarkerColor(kRed);
  InvMassTauMuMu1Data_->Draw("SAME");
  InvMassTauMuMu1Canvas.cd(2);
  InvMassTauMuMu1MCSig_->SetTitle("SignalRegion");
  InvMassTauMuMu1MCSig_->Draw();
  InvMassTauMuMu1Data_->SetLineColor(kRed);
  InvMassTauMuMu1Data_->SetMarkerColor(kRed);
  InvMassTauMuMu1Data_->Draw("SAME"); 
  leg->AddEntry(InvMassTauMuMu1Data_, "Data", "L" );
  leg->Draw(); 
std::cout << "check2" << std::endl;
  
  InvMassTauMuMu2Canvas.cd(1);
  InvMassTauMuMu2MCNoIso_->SetTitle("NoIsodiTau");
  InvMassTauMuMu2MCNoIso_->Draw();
  InvMassTauMuMu2Data_->SetLineColor(kRed);
  InvMassTauMuMu2Data_->SetMarkerColor(kRed);
  InvMassTauMuMu2Data_->Draw("SAME");
  InvMassTauMuMu2Canvas.cd(2);
  InvMassTauMuMu2MCSig_->SetTitle("SignalRegion");
  InvMassTauMuMu2MCSig_->Draw();
  InvMassTauMuMu2Data_->SetLineColor(kRed);
  InvMassTauMuMu2Data_->SetMarkerColor(kRed);
  InvMassTauMuMu2Data_->Draw("SAME");
  leg->Draw();
std::cout << "check3" << std::endl;

//  InvMassFakeWeightCanvas.cd(1);
//  InvMassFakeWeightMCNoIso_->SetTitle("NoIsodiTau");
//  InvMassFakeWeightMCNoIso_->Draw();
//  InvMassFakeWeightData_->SetLineColor(kRed);
//  InvMassFakeWeightData_->SetMarkerColor(kRed);
//  InvMassFakeWeightData_->Draw("SAME");
//  InvMassFakeWeightCanvas.cd(2);
//  InvMassFakeWeightMCSig_->SetTitle("SignalRegion");
//  InvMassFakeWeightMCSig_->Draw();
//  InvMassFakeWeightData_->SetLineColor(kRed);
//  InvMassFakeWeightData_->SetMarkerColor(kRed);
//  InvMassFakeWeightData_->Draw("SAME");
//  leg->Draw();

std::cout << "check14" << std::endl;
  InvMassFakeWeightCanvas.cd();
std::cout << "check24" << std::endl;
  InvMassFakeWeightCanvas.cd(1);
std::cout << "check34" << std::endl;
  InvMassFakeWeightMCNoIso_->SetTitle("NoIsodiTau");
std::cout << "check44" << std::endl;
  InvMassFakeWeightMCNoIso_->Draw();
std::cout << "check54" << std::endl;
  InvMassFakeWeightData_->SetLineColor(kRed);
std::cout << "check64" << std::endl;
  InvMassFakeWeightData_->SetMarkerColor(kRed);
std::cout << "check74" << std::endl;
  InvMassFakeWeightData_->Draw("SAME");
std::cout << "check84" << std::endl;
  InvMassFakeWeightCanvas.cd(2);
std::cout << "check94" << std::endl;
  InvMassFakeWeightMCSig_->SetTitle("SignalRegion");
std::cout << "check104" << std::endl;
  InvMassFakeWeightMCSig_->Draw();
std::cout << "check114" << std::endl;
  InvMassFakeWeightData_->SetLineColor(kRed);
std::cout << "check124" << std::endl;
  InvMassFakeWeightData_->SetMarkerColor(kRed);
std::cout << "check134" << std::endl;
  InvMassFakeWeightData_->Draw("SAME");
std::cout << "check144" << std::endl;
  leg->Draw();
std::cout << "check5" << std::endl;

  PtMu1FakeWeightCanvas.cd();
  PtMu1FakeWeightCanvas.cd(1);
  PtMu1FakeWeightMCNoIso_->SetTitle("NoIsodiTau");
  PtMu1FakeWeightMCNoIso_->Draw();
  PtMu1FakeWeightData_->SetLineColor(kRed);
  PtMu1FakeWeightData_->SetMarkerColor(kRed);
  PtMu1FakeWeightData_->Draw("SAME");
  PtMu1FakeWeightCanvas.cd(2);
  PtMu1FakeWeightMCSig_->SetTitle("SignalRegion");
  PtMu1FakeWeightMCSig_->Draw();
  PtMu1FakeWeightData_->SetLineColor(kRed);
  PtMu1FakeWeightData_->SetMarkerColor(kRed);
  PtMu1FakeWeightData_->Draw("SAME");
  leg->Draw();

std::cout << "check6" << std::endl;
  EtaFakeWeightCanvas.cd();
  EtaFakeWeightCanvas.cd(1);
  EtaFakeWeightMCNoIso_->SetTitle("NoIsodiTau");
  EtaFakeWeightMCNoIso_->Draw();
  EtaFakeWeightData_->SetLineColor(kRed);
  EtaFakeWeightData_->SetMarkerColor(kRed);
  EtaFakeWeightData_->Draw("SAME");
  EtaFakeWeightCanvas.cd(2);
  EtaFakeWeightMCSig_->SetTitle("SignalRegion");
  EtaFakeWeightMCSig_->Draw();
  EtaFakeWeightData_->SetLineColor(kRed);
  EtaFakeWeightData_->SetMarkerColor(kRed);
  EtaFakeWeightData_->Draw("SAME");
  leg->Draw();
std::cout << "check7" << std::endl;

  DRFakeWeightCanvas.cd();
  DRFakeWeightCanvas.cd(1);
  DRFakeWeightMCNoIso_->SetTitle("NoIsodiTau");
  DRFakeWeightMCNoIso_->Draw();
  DRFakeWeightData_->SetLineColor(kRed);
  DRFakeWeightData_->SetMarkerColor(kRed);
  DRFakeWeightData_->Draw("SAME");
  DRFakeWeightCanvas.cd(2);
  DRFakeWeightMCSig_->SetTitle("SignalRegion");
  DRFakeWeightMCSig_->Draw();
  DRFakeWeightData_->SetLineColor(kRed);
  DRFakeWeightData_->SetMarkerColor(kRed);
  DRFakeWeightData_->Draw("SAME");
  leg->Draw();
std::cout << "check8" << std::endl;

  InvMassFakeWeightZoomCanvas.cd();
  InvMassFakeWeightZoomCanvas.cd(1);
  InvMassFakeWeightZoomMCNoIso_->SetTitle("NoIsodiTau");
  InvMassFakeWeightZoomMCNoIso_->Draw();
  InvMassFakeWeightZoomData_->SetLineColor(kRed);
  InvMassFakeWeightZoomData_->SetMarkerColor(kRed);
  InvMassFakeWeightZoomData_->Draw("SAME");
  InvMassFakeWeightZoomCanvas.cd(2);
  InvMassFakeWeightZoomMCSig_->SetTitle("SignalRegion");
  InvMassFakeWeightZoomMCSig_->Draw();
  InvMassFakeWeightZoomData_->SetLineColor(kRed);
  InvMassFakeWeightZoomData_->SetMarkerColor(kRed);
  InvMassFakeWeightZoomData_->Draw("SAME");
  leg->Draw();

std::cout << "check9" << std::endl;
  TauVisMassZoomCanvas.cd();
  TauVisMassZoomCanvas.cd(1);
  TauVisMassZoomMCNoIso_->SetTitle("NoIsodiTau");
  TauVisMassZoomMCNoIso_->Draw();
  TauVisMassZoomData_->SetLineColor(kRed);
  TauVisMassZoomData_->SetMarkerColor(kRed);
  TauVisMassZoomData_->Draw("SAME");
  TauVisMassZoomCanvas.cd(2);
  TauVisMassZoomMCSig_->SetTitle("SignalRegion");
  TauVisMassZoomMCSig_->Draw();
  TauVisMassZoomData_->SetLineColor(kRed);
  TauVisMassZoomData_->SetMarkerColor(kRed);
  TauVisMassZoomData_->Draw("SAME");
  leg->Draw();

std::cout << "check10" << std::endl;

//////////////////////////////////
// Setting the Titles for Clarity
//////////////////////////////////

  outFile->cd();

  InvMassTauMuMu1Canvas.Write();
  InvMassTauMuMu2Canvas.Write();
  InvMassFakeWeightCanvas.Write();
  PtMu1FakeWeightCanvas.Write();
  EtaFakeWeightCanvas.Write();
  DRFakeWeightCanvas.Write();
  InvMassFakeWeightZoomCanvas.Write();
  TauVisMassCanvas.Write();
  TauVisMassZoomCanvas.Write();

  outFile->Write();
  outFile->Close();
cout << "end" << endl;

}//rootMacro_BBA_combine
