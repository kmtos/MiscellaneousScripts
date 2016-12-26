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

void rootMacro_FakeRateInfo_Single()
{

  gStyle->SetOptStat(kFALSE);
  gStyle->SetEndErrorSize(7);

  TFile infile   ("/home/kyletos/Downloads/RootFiles/FakeRate/FinalFiles/FINAL_DY_New_VariousHTBDisc_SEP20.root");

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/CombinedPlots/comb_FakeRateInfo_NewHT_VariousHTBDisc_SEP20.root", "RECREATE");

  ofstream infoFile;
  infoFile.open ("/home/kyletos/Downloads/RootFiles/CombinedPlots/FakeRateInfo_Single_NewHT_VariousHTBDisc_SEP20.txt");


cout << "Files Created" << endl;

  ////////////////
  // DY
  ////////////////
  TCanvas *MatchedLooseIsoCJPtCanvas   = (TCanvas*)infile.Get("MatchedLooseIsoCJPt");
  TCanvas *MatchedMedIsoCJPtCanvas     = (TCanvas*)infile.Get("MatchedMedIsoCJPt");
  TCanvas *MatchedTightIsoCJPtCanvas   = (TCanvas*)infile.Get("MatchedTightIsoCJPt");
  TCanvas *MatchedDMFindCJPtCanvas     = (TCanvas*)infile.Get("MatchedDMFindCJPt");
  TCanvas *MatchedCJPtCanvas   = (TCanvas*)infile.Get("MatchedCJPt");
  
  ////////////////
  //NEvents Files
  ////////////////
  TCanvas *NEventsCanvas   = (TCanvas*)infile.Get("NEvents");
  TCanvas *NEventsCutsCanvas   = (TCanvas*)infile.Get("NEventsCuts");

cout << "Got Canvases" << endl;

  //////////////////////////////
  // Getting the DY Histograms
  //////////////////////////////
  TH1F* MatchedLooseIsoCJPt_   = (TH1F*)MatchedLooseIsoCJPtCanvas->GetPrimitive("MatchedLooseIsoCJPt");
  TH1F* MatchedMedIsoCJPt_     = (TH1F*)MatchedMedIsoCJPtCanvas->GetPrimitive("MatchedMedIsoCJPt");
  TH1F* MatchedTightIsoCJPt_   = (TH1F*)MatchedTightIsoCJPtCanvas->GetPrimitive("MatchedTightIsoCJPt");
  TH1F* MatchedDMFindCJPt_     = (TH1F*)MatchedDMFindCJPtCanvas->GetPrimitive("MatchedDMFindCJPt");
  TH1F* MatchedCJPt_   = (TH1F*)MatchedCJPtCanvas->GetPrimitive("MatchedCJPt");

  //////////////////////////////
  // NEvents Histograms
  ///////////////////////////
  TH1F* NEvents_   = (TH1F*)NEventsCanvas->GetPrimitive("NEvents");
  TH1F* NEventsCuts_   = (TH1F*)NEventsCutsCanvas->GetPrimitive("NEventsCuts");

  ///////////////////////////
  // GenMatchType Histograms
  ///////////////////////////
  TH1F* GenMatchTypeDY_   = (TH1F*)GenMatchTypeDYCanvas->GetPrimitive("GenMatchType");

  ///////////////////////////
  // GenMatchType Histograms
  ///////////////////////////
  TH1F* GenMatchPDGIDDY_   = (TH1F*)GenMatchPDGIDDYCanvas->GetPrimitive("GenMatchPDGID");

  //////////////////////////////////
  // Canvases for overlaid histos
  //////////////////////////////////
  
  // For Lepton Particles
  TH1F* MatchedTauMuPtLeptonDY_   = (TH1F*)MatchedTauMuPtLeptonDYCanvas->GetPrimitive("MatchedTauMuPtLepton");
  TH1F* MatchedTauHadPtLeptonDY_   = (TH1F*)MatchedTauHadPtLeptonDYCanvas->GetPrimitive("MatchedTauHadPtLepton");
  TH1F* MatchedTauHadEtaLeptonDY_   = (TH1F*)MatchedTauHadEtaLeptonDYCanvas->GetPrimitive("MatchedTauHadEtaLepton");
  TH1F* MatchedHTLeptonDY_   = (TH1F*)MatchedHTLeptonDYCanvas->GetPrimitive("MatchedHTLepton");
  TH1F* MatchedBDiscCSVLeptonDY_   = (TH1F*)MatchedBDiscCSVLeptonDYCanvas->GetPrimitive("MatchedBDiscCSVLepton");

  // For Jet Particles
  TH1F* MatchedTauMuPtJetDY_   = (TH1F*)MatchedTauMuPtJetDYCanvas->GetPrimitive("MatchedTauMuPtJet");
  TH1F* MatchedTauHadPtJetDY_   = (TH1F*)MatchedTauHadPtJetDYCanvas->GetPrimitive("MatchedTauHadPtJet");
  TH1F* MatchedTauHadEtaJetDY_   = (TH1F*)MatchedTauHadEtaJetDYCanvas->GetPrimitive("MatchedTauHadEtaJet");
  TH1F* MatchedHTJetDY_   = (TH1F*)MatchedHTJetDYCanvas->GetPrimitive("MatchedHTJet");
  TH1F* MatchedBDiscCSVJetDY_   = (TH1F*)MatchedBDiscCSVJetDYCanvas->GetPrimitive("MatchedBDiscCSVJet");

cout << "Histograms assigned." << endl; 

  ////////////////////////////
  // Getting DYJets Numbers
  ////////////////////////////
  double Loose  = MatchedLooseIsoCJPt_->GetEntries();
  double Med    = MatchedMedIsoCJPt_->GetEntries();  
  double Tight  = MatchedTightIsoCJPt_->GetEntries();
  double DMFind = MatchedDMFindCJPt_->GetEntries();
  double GenMat = MatchedCJPt_->GetEntries();
  
  ///////////////////////////////////
  // Getting Starting Event Number   
  ///////////////////////////////////
  double Total = NEvents_->GetBinContent(1);

  double CutNRemovedMu =NEventsCuts_->GetBinContent(1), LepBD1 = NEventsCuts_->GetBinContent(2), LepBD1Med = NEventsCuts_->GetBinContent(3);
  double LepBD2 = NEventsCuts_->GetBinContent(4), LepBD2Med = NEventsCuts_->GetBinContent(5), LepHT1 = NEventsCuts_->GetBinContent(6);
  double LepHT1Med = NEventsCuts_->GetBinContent(7), LepHT2 = NEventsCuts_->GetBinContent(8), LepHT2Med = NEventsCuts_->GetBinContent(9);
  double JetBD1 = NEventsCuts_->GetBinContent(10), JetBD1Med = NEventsCuts_->GetBinContent(11);
  double JetBD2 = NEventsCuts_->GetBinContent(12), JetBD2Med = NEventsCuts_->GetBinContent(13), JetHT1 = NEventsCuts_->GetBinContent(14);
  double JetHT1Med = NEventsCuts_->GetBinContent(15), JetHT2 = NEventsCuts_->GetBinContent(16), JetHT2Med = NEventsCuts_->GetBinContent(17);
  double NJet = NEventsCuts_->GetBinContent(18), NLep = NEventsCuts_->GetBinContent(19), NLepJet = NEventsCuts_->GetBinContent(20);

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //  Scaling xsec calculations | values from https://twiki.cern.ch/twiki/bin/viewauth/CMS/SummaryTable1G25ns#TTbar
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  double 50_xsec = 1997000 * 20 / 103955830; // 103955830 is from Mengyao's skm summary: http://hep.ucdavis.edu/mengyao/38
//  double TTNew_xsec = 822330 * 20 / ;
//  double WJNew_xsec = 61526700 * 20 / ;

  //////////////////////////
  // Cut Info
  //////////////////////////
  infoFile << "################################################\n## Cut Info for New DM No MVA \n################################################\n" << endl;
  infoFile << "nEvents with RemovedMuon: DY= " << CutNRemovedMu <<  std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(19) << "\t\t\t: DY= " << NLep  << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(2)  << "\t\t: DY= "   << LepBD1 << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(3)  << "\t: DY= "     << LepBD1Med << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(4)  << "\t\t: DY= "   << LepBD2  << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(5)  << "\t: DY= "     << LepBD2Med << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(6)  << "\t\t: DY= "   << LepHT1 << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(7)  << "\t: DY= "     << LepHT1Med << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(8)  << "\t\t: DY= "   << LepHT2 << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(9)  << "\t: DY= "     << LepHT2Med << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(18) << "\t\t\t: DY= " << NJet << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(10) << "\t\t: DY= "   << JetBD1 << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(11) << "\t: DY= "     << JetBD1Med << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(12) << "\t\t: DY= "   << JetBD2 << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(13) << "\t: DY= "     << JetBD2Med << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(14) << "\t\t: DY= "   << JetHT1 << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(15) << "\t: DY= "     << JetHT1Med << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(16) << "\t\t: DY= "   << JetHT2 << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(17) << "\t: DY= "     << JetHT2Med << std::endl;
  infoFile << NEventsCuts_->GetXaxis()->GetBinLabel(18) << "\t\t\t: DY= " << NJet << std::endl;





  //////////////////////////
  // Writing DY information
  //////////////////////////
  infoFile << "\n\n\n############################################\n## Drell-Yan M-50 \n#############################################\n" << endl;
  infoFile << "Normalized with (xsec in fb) * (expected data in fb) / (number of events processed) = 1997000 * 20 / 103955830 = " << 50_xsec << std::endl;
  infoFile << "Removed Muon= " << GenMat * 50_xsec << endl;
  infoFile << "Loose= " << Loose * 50_xsec << endl;
  infoFile << "Med=   " << Med   * 50_xsec << endl;
  infoFile << "Tight= " << Tight * 50_xsec << endl;

cout << "end" << endl;

}//rootMacro_BBA_combine
