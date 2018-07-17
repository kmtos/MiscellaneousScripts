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


void rootMacro_Integrate()
{

  gStyle->SetOptStat(kFALSE);
  gStyle->SetEndErrorSize(7);

  TFile infile ("/home/kyletos/Downloads/RootFiles/ABCD_Tests/WeightedFakeRate/FINAL_AllEra_NoIsoDiTau_JUL19_DiMuMassgt4.root");
  
  TCanvas* InvMassTauMuMu1Canvas = (TCanvas*)infile.Get("InvMassTauMuMu1");
  TCanvas* InvMassTauMuMu2Canvas = (TCanvas*)infile.Get("InvMassTauMuMu2");
  TCanvas* InvMassFakeWeightCanvas = (TCanvas*)infile.Get("InvMassFakeWeight");
  TCanvas* PtMu1FakeWeightCanvas = (TCanvas*)infile.Get("PtMu1FakeWeight");
  TCanvas* PtMu2FakeWeightCanvas = (TCanvas*)infile.Get("PtMu2FakeWeight");
  TCanvas* EtaFakeWeightCanvas = (TCanvas*)infile.Get("EtaFakeWeight");
  TCanvas* DRFakeWeightCanvas = (TCanvas*)infile.Get("DRFakeWeight");
  TCanvas* InvMassFakeWeightZoomCanvas = (TCanvas*)infile.Get("InvMassFakeWeightZoom");
  TCanvas* TauVisMassCanvas = (TCanvas*)infile.Get("TauVisMass");

  TH1F* InvMassTauMuMu1_   = (TH1F*)InvMassTauMuMu1Canvas->GetPrimitive("InvMassTauMuMu1");
  TH1F* InvMassTauMuMu2_   = (TH1F*)InvMassTauMuMu2Canvas->GetPrimitive("InvMassTauMuMu2");
  TH1F* InvMassFakeWeight_   = (TH1F*)InvMassFakeWeightCanvas->GetPrimitive("InvMassFakeWeight");
  TH1F* PtMu1FakeWeight_   = (TH1F*)PtMu1FakeWeightCanvas->GetPrimitive("PtMu1FakeWeight");
  TH1F* PtMu2FakeWeight_   = (TH1F*)PtMu2FakeWeightCanvas->GetPrimitive("PtMu2FakeWeight");
  TH1F* EtaFakeWeight_   = (TH1F*)EtaFakeWeightCanvas->GetPrimitive("EtaFakeWeight");
  TH1F* DRFakeWeight_   = (TH1F*)DRFakeWeightCanvas->GetPrimitive("DRFakeWeight");
  TH1F* InvMassFakeWeightZoom_   = (TH1F*)InvMassFakeWeightZoomCanvas->GetPrimitive("InvMassFakeWeightZoom");
  TH1F* TauVisMass_   = (TH1F*)TauVisMassCanvas->GetPrimitive("TauVisMass");

  std::cout << "Int(InvMassTauMuMu1_)=" << InvMassTauMuMu1_->Integral() << "\nINT(InvMassTauMuMu2)=" << InvMassTauMuMu2_->Integral() << "\nInt(InvMassFakeWeight_)=" << InvMassFakeWeight_->Integral() << "\nINT(PtMu1FakeWeight_)=" << PtMu1FakeWeight_->Integral() << "\nInt(PtMu2FakeWeight_)=" << PtMu2FakeWeight_->Integral() << "\nINT(EtaFakeWeight_)=" << EtaFakeWeight_->Integral() << "\nINT(DRFakeWeight_)=" << DRFakeWeight_->Integral() << "\nINT(TauVisMass_)=" << TauVisMass_->Integral() << std::endl;


}//rootMacro_Integrate
