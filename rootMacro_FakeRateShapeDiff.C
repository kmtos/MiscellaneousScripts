#include "TCanvas.h"
#include "TPaveText.h"
#include "TAxis.h"
#include "TH1.h"
#include <iostream>
#include <fstream>


void rootMacro_FakeRateShapeDiff()
{

  RooWorkspace w1("w1");

  TFile *fC = TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/FINAL_MiniAOD_SingleMu_MedIsoMu2_TauDMAntiMedIso_FEB8_AFromB_FakeRateCENTRAL.root");
  TFile *fU = TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/FINAL_MiniAOD_SingleMu_MedIsoMu2_TauDMAntiMedIso_FEB8_AFromB_FakeRateUP.root");
  TFile *fD = TFile::Open("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/FINAL_MiniAOD_SingleMu_MedIsoMu2_TauDMAntiMedIso_FEB8_AFromB_FakeRateDOWN.root");

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/FINALPLOTS_MiniAOD_SingleMu_MedIsoMu2_TauDMAntiMedIso_FEB8_AFromB.root", "RECREATE");

  TH1F* hC = (TH1F*)fC->Get("DiMuInvMassFakeWeight");
  TH1F* hU = (TH1F*)fU->Get("DiMuInvMassFakeWeight");
  TH1F* hD = (TH1F*)fD->Get("DiMuInvMassFakeWeight");

  hC->SetTitle("Central");
  hU->SetTitle("Fake Rate Eff. Up");
  hD->SetTitle("Fake Rate Eff. Down");

  hC->SetName("DiMuInvMass_Central");
  hU->SetName("DiMuInvMass_Up");
  hD->SetName("DiMuInvMass_Down");

  hC->SetAxisRange(4,30);
  hU->SetAxisRange(4,30);
  hD->SetAxisRange(4,30);

  string  hCYTitle = "Events / " + std::to_string(hC->GetXaxis()->GetBinWidth(3) ) + " GeV/c";
  hC->GetYaxis()->SetTitle(hCYTitle.c_str() );
  string  hUYTitle = "Events / " + std::to_string(hU->GetXaxis()->GetBinWidth(3) ) + " GeV/c";
  hU->GetYaxis()->SetTitle(hUYTitle.c_str() );
  string  hDYTitle = "Events / " + std::to_string(hD->GetXaxis()->GetBinWidth(3) ) + " GeV/c";
  hD->GetYaxis()->SetTitle(hDYTitle.c_str() );
  
  TCanvas *cC = new TCanvas("DiMuInvMass_Central", "", 600, 600);
  TCanvas *cU = new TCanvas("DiMuInvMass_Up", "", 600, 600);
  TCanvas *cD = new TCanvas("DiMuInvMass_Down", "", 600, 600);

  outFile->cd();

  cC->cd();
  hC->Draw();
  cC->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/DiMuInvMass_Central.png");
  cC->Write();

  cU->cd();
  hU->Draw();
  cU->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/DiMuInvMass_Up.png");
  cU->Write();

  cD->cd();
  hD->Draw();
  cD->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/DiMuInvMass_Down.png");
  cD->Write();

  TCanvas *cCZ = new TCanvas("DiMuInvMassZoom_Central", "", 600, 600);
  TCanvas *cUZ = new TCanvas("DiMuInvMassZoom_Up", "", 600, 600);
  TCanvas *cDZ = new TCanvas("DiMuInvMassZoom_Down", "", 600, 600);

  hC->SetAxisRange(4,30);
  hU->SetAxisRange(4,30);
  hD->SetAxisRange(4,30);

  cCZ->cd();
  hC->Draw();
  cCZ->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/DiMuInvMassZoom_Central.png");
  cCZ->Write();

  cUZ->cd();
  hU->Draw();
  cUZ->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/DiMuInvMassZoom_Up.png");
  cUZ->Write();

  cDZ->cd();
  hD->Draw();
  cDZ->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/DiMuInvMassZoom_Down.png");
  cDZ->Write();

 
  TCanvas *cCR = new TCanvas("DiMuInvMassRebin_Central", "", 600, 600);
  TCanvas *cUR = new TCanvas("DiMuInvMassRebin_Up", "", 600, 600);
  TCanvas *cDR = new TCanvas("DiMuInvMassRebin_Down", "", 600, 600);

  hC->Rebin(6);
  hD->Rebin(6);
  hU->Rebin(6);
 
  hC->SetAxisRange(4,30);
  hU->SetAxisRange(4,30);
  hD->SetAxisRange(4,30);

  string  hCYTitleNew = "Events / " + std::to_string(hC->GetXaxis()->GetBinWidth(3) ) + " GeV/c";
  hC->GetYaxis()->SetTitle(hCYTitleNew.c_str() );
  string  hUYTitleNew = "Events / " + std::to_string(hU->GetXaxis()->GetBinWidth(3) ) + " GeV/c";
  hU->GetYaxis()->SetTitle(hUYTitleNew.c_str() );
  string  hDYTitleNew = "Events / " + std::to_string(hD->GetXaxis()->GetBinWidth(3) ) + " GeV/c";
  hD->GetYaxis()->SetTitle(hDYTitleNew.c_str() );

  cCR->cd();
  hC->Draw();
  cCR->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/DiMuInvMassRebin_Central.png");
  cCR->Write();

  cUR->cd();
  hU->Draw();
  cUR->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/DiMuInvMassRebin_Up.png");
  cUR->Write();

  cDR->cd();
  hD->Draw();
  cDR->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/DiMuInvMassRebin_Down.png");
  cDR->Write();

  TCanvas *cCMR = new TCanvas("DiMuInvMassRebinMore_Central", "", 600, 600);
  TCanvas *cUMR = new TCanvas("DiMuInvMassRebinMore_Up", "", 600, 600);
  TCanvas *cDMR = new TCanvas("DiMuInvMassRebinMore_Down", "", 600, 600);

  hC->Rebin(2);
  hD->Rebin(2);
  hU->Rebin(2);

  hC->SetAxisRange(4,30);
  hU->SetAxisRange(4,30);
  hD->SetAxisRange(4,30);

  string  hCYTitleNewer = "Events / " + std::to_string(hC->GetXaxis()->GetBinWidth(3) ) + " GeV/c";
  hC->GetYaxis()->SetTitle(hCYTitleNewer.c_str() );
  string  hUYTitleNewer = "Events / " + std::to_string(hU->GetXaxis()->GetBinWidth(3) ) + " GeV/c";
  hU->GetYaxis()->SetTitle(hUYTitleNewer.c_str() );
  string  hDYTitleNewer = "Events / " + std::to_string(hD->GetXaxis()->GetBinWidth(3) ) + " GeV/c";
  hD->GetYaxis()->SetTitle(hDYTitleNewer.c_str() );
  
  cCMR->cd();
  hC->Draw();
  cCMR->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/DiMuInvMassRebinMore_Central.png");
  cCMR->Write();
  
  cUMR->cd();
  hU->Draw();
  cUMR->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/DiMuInvMassRebinMore_Up.png");
  cUMR->Write();

  cDMR->cd();
  hD->Draw();
  cDMR->SaveAs("/home/kyletos/Downloads/RootFiles/ABCD_Tests/FakeRateShapeDifference/DiMuInvMassRebinMore_Down.png");
  cDMR->Write();


  outFile->Close();

}//rootMacro
