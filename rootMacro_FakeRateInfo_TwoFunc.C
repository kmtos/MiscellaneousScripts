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

void GetFormatAndDraw(TFile &infile, TFile *outFile, TLegend *leg, string legName, const Color_t color, TCanvas *CanvasArray, double scale, bool firstFile, int Cuts[19], int Counts[5], string labels[19] );
void rootMacro_FakeRateInfo_TwoFunc()
{

  gStyle->SetOptStat(kFALSE);
  gStyle->SetEndErrorSize(7);

  //Old DMs
  TFile infileTTNew   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_TT_New_InvMass_NOV21.root");
  TFile infileTTNewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_TT_NewMVA_InvMass_NOV21.root");
  TFile infileTTOld   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_TT_Old_InvMass_NOV21.root");
  TFile infileTTOldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_TT_OldMVA_InvMass_NOV21.root");

/*  
  TFile infileWJNew   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_WJ_New_InvMass_NOV21.root");
  TFile infileWJNewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_WJ_NewMVA_InvMass_NOV21.root");
  TFile infileWJOld   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_WJ_Old_InvMass_NOV21.root");
  TFile infileWJOldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_WJ_OldMVA_InvMass_NOV21.root");
*/

  TFile infileDYNew   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_DY_New_InvMass_NOV21.root");
  TFile infileDYNewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_DY_NewMVA_InvMass_NOV21.root");
  TFile infileDYOld   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_DY_Old_InvMass_NOV21.root");
  TFile infileDYOldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_DY_OldMVA_InvMass_NOV21.root");

  TFile infileH125a19New   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125_a19_New_InvMass_NOV29.root");
  TFile infileH125a19NewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125_a19_NewMVA_InvMass_NOV29.root");
  TFile infileH125a19Old   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125_a19_Old_InvMass_NOV29.root");
  TFile infileH125a19OldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125_a19_OldMVA_InvMass_NOV29.root");

  TFile infileH125a9New   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125_a9_New_InvMass_NOV29.root");
  TFile infileH125a9NewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125_a9_NewMVA_InvMass_NOV29.root");
  TFile infileH125a9Old   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125_a9_Old_InvMass_NOV29.root");
  TFile infileH125a9OldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125_a9_OldMVA_InvMass_NOV29.root");

  TFile infileH125a5New   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125_a5_New_InvMass_NOV29.root");
  TFile infileH125a5NewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125_a5_NewMVA_InvMass_NOV29.root");
  TFile infileH125a5Old   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125_a5_Old_InvMass_NOV29.root");
  TFile infileH125a5OldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125_a5_OldMVA_InvMass_NOV29.root");

  TFile infileH750a9New   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H750_a9_New_InvMass_NOV29.root");
  TFile infileH750a9NewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H750_a9_NewMVA_InvMass_NOV29.root");
  TFile infileH750a9Old   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H750_a9_Old_InvMass_NOV29.root");
  TFile infileH750a9OldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H750_a9_OldMVA_InvMass_NOV29.root");


  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/CombinedPlots/comb_FakeRateInfo_InvMass_NOV21.root", "RECREATE");

  ofstream infoFile;
  infoFile.open ("/home/kyletos/Downloads/RootFiles/CombinedPlots/FakeRateInfo_InvMass_NOV21.txt");

  //////////////////////////////
  //  Scaling xsec calculations
  //////////////////////////////
  double scaleDY50 = 1921.8 * 3 * 20000.0 / 55655109, scaleTT = 831.76 * 20000.0 / 36377515, scaleWJ = 61526.7 * 20000.0/ 9871632498173624, scaleH125a19= 48.90 * 20000.0 / 300000;
  double scaleH750a9 = 0.4969 * 20000.0/ 300000, scaleH125a5= 48.90 * 20000.0 / 297366, scaleH125a9= 48.90 * 20000.0 / 300000;

  TCanvas *CanvasArray[10];

  CanvasArray[0] = new TCanvas("TauHadPtLeptonCanvas","",600,600);
  CanvasArray[1] = new TCanvas("TauMuPtLeptonCanvas","",600,600);
  CanvasArray[2] = new TCanvas("TauHadEtaLeptonCanvas","",600,600);
  CanvasArray[3] = new TCanvas("HTLeptonCanvas","",600,600);
  CanvasArray[4] = new TCanvas("BDiscCSVLeptonCanvas","",600,600);
  
  CanvasArray[0]->SetGrid(1,1);
  CanvasArray[1]->SetGrid(1,1);
  CanvasArray[2]->SetGrid(1,1);
  CanvasArray[3]->SetGrid(1,1);
  CanvasArray[4]->SetGrid(1,1);
  
  CanvasArray[5] = new TCanvas("TauHadPtJetCanvas","",600,600);
  CanvasArray[6] = new TCanvas("TauMuPtJetCanvas","",600,600);
  CanvasArray[7] = new TCanvas("TauHadEtaJetCanvas","",600,600);
  CanvasArray[8] = new TCanvas("HTJetCanvas","",600,600);
  CanvasArray[9] = new TCanvas("BDiscCSVJetCanvas","",600,600);
  
  CanvasArray[5]->SetGrid(1,1);
  CanvasArray[6]->SetGrid(1,1);
  CanvasArray[7]->SetGrid(1,1);
  CanvasArray[8]->SetGrid(1,1);
  CanvasArray[9]->SetGrid(1,1);
  
  TCanvas OldSigToBackCanvas("OldSigToBackCanvas","",600,600);
  TCanvas OldMVASigToBackCanvas("OldMVASigToBackCanvas","",600,600);
  TCanvas NewSigToBackCanvas("NewSigToBackCanvas","",600,600);
  TCanvas NewMVASigToBackCanvas("NewMVASigToBackCanvas","",600,600);

  OldSigToBackCanvas.SetGrid(1,1);
  OldMVASigToBackCanvas.SetGrid(1,1);
  NewSigToBackCanvas.SetGrid(1,1);
  NewMVASigToBackCanvas.SetGrid(1,1);

  legNewMVA = new TLegend(0.1,0.7,0.25,0.9);
  legNew = new TLegend(0.1,0.7,0.25,0.9);
  legOldMVA = new TLegend(0.1,0.7,0.25,0.9);
  legOld = new TLegend(0.1,0.7,0.25,0.9);
  string TTName = "TT", DYName = "DY" , WJName = "WJ", H125a19Name = "H125a19", H125a9Name = "H125a9", H125a5Name = "H125a5", H750a9Name = "H750a9";

  int CutDYNewMVA[19], CutTTNewMVA[19], CutWJNewMVA[19], CutH125a19NewMVA[19], CutH125a9NewMVA[19], CutH125a5NewMVA[19], CutH750a9NewMVA[19];
  int CutDYNew[19], CutTTNew[19], CutWJNew[19], CutH125a19New[19], CutH125a9New[19], CutH125a5New[19], CutH750a9New[19];
  int CutDYOldMVA[19], CutTTOldMVA[19], CutWJOldMVA[19], CutH125a19OldMVA[19], CutH125a9OldMVA[19], CutH125a5OldMVA[19], CutH750a9OldMVA[19];
  int CutDYOld[19], CutTTOld[19], CutWJOld[19], CutH125a19Old[19], CutH125a9Old[19], CutH125a5Old[19], CutH750a9Old[19];

  int CountDYNewMVA[5], CountTTNewMVA[5], CountWJNewMVA[5], CountH125a19NewMVA[5], CountH125a9NewMVA[5], CountH125a5NewMVA[5], CountH750a9NewMVA[5];
  int CountDYNew[5], CountTTNew[5], CountWJNew[5], CountH125a19New[5], CountH125a9New[5], CountH125a5New[5], CountH750a9New[5]; 
  int CountDYOldMVA[5], CountTTOldMVA[5], CountWJOldMVA[5], CountH125a19OldMVA[5], CountH125a9OldMVA[5], CountH125a5OldMVA[5], CountH750a9OldMVA[5];
  int CountDYOld[5], CountTTOld[5], CountWJOld[5], CountH125a19Old[5], CountH125a9Old[5], CountH125a5Old[5], CountH750a9Old[5]; 
  
  string CutLabelsBack[19], CutLabelsSig[9];

  std::cout << "NewMVA" << std::endl;
  GetFormatAndDraw(infileTTNewMVA, outFile, legNewMVA, TTName, kBlue+1, *CanvasArray, scaleTT, true, CountTTNewMVA, CutTTNewMVA, CutLabelsBack);
  GetFormatAndDraw(infileDYNewMVA, outFile, legNewMVA, DYName, kRed, *CanvasArray, scaleDY50, false, CountDYNewMVA, CutDYNewMVA, CutLabelsBack);
//  GetFormatAndDraw(infileWJNewMVA, outFile, legNewMVA, WJName, kGreen+1, *CanvasArray, scaleWJ, false, CountWJNewMVA, CutWJNewMVA, CutLabelsBack);
  GetFormatAndDraw(infileH125a19NewMVA, outFile, legNewMVA, H125a19Name, kBlack, *CanvasArray, scaleH125a19, false, CountH125a19NewMVA, CutH125a19NewMVA, CutLabelsSig);
  GetFormatAndDraw(infileH125a9NewMVA, outFile, legNewMVA, H125a9Name, kGray+1, *CanvasArray, scaleH125a9, false, CountH125a9NewMVA, CutH125a9NewMVA, CutLabelsSig);
  GetFormatAndDraw(infileH125a5NewMVA, outFile, legNewMVA, H125a5Name, kYellow+2, *CanvasArray, scaleH125a5, false, CountH125a5NewMVA, CutH125a5NewMVA, CutLabelsSig);
  GetFormatAndDraw(infileH750a9NewMVA, outFile, legNewMVA, H750a9Name, kViolet+1, *CanvasArray, scaleH750a9, false, CountH750a9NewMVA, CutH750a9NewMVA, CutLabelsSig);

  std::cout << "New" << std::endl;
  GetFormatAndDraw(infileTTNew, outFile, legNew, TTName, kBlue+1, *CanvasArray, scaleTT, false, CountTTNew, CutTTNew, CutLabelsBack);
  GetFormatAndDraw(infileDYNew, outFile, legNew, DYName, kRed, *CanvasArray, scaleDY50, false, CountDYNew, CutDYNew, CutLabelsBack);
//  GetFormatAndDraw(infileWJNew, outFile, legNew, WJName, kGreen+1, *CanvasArray, scaleWJ, false, CountWJNew, CutWJNew, CutLabelsBack);
  GetFormatAndDraw(infileH125a19New, outFile, legNew, H125a19Name, kBlack, *CanvasArray, scaleH125a19, false, CountH125a19New, CutH125a19New, CutLabelsSig);
  GetFormatAndDraw(infileH125a9New, outFile, legNew, H125a9Name, kGray+1, *CanvasArray, scaleH125a9, false, CountH125a9New, CutH125a9New, CutLabelsSig);
  GetFormatAndDraw(infileH125a5New, outFile, legNew, H125a5Name, kYellow+2, *CanvasArray, scaleH125a5, false, CountH125a5New, CutH125a5New, CutLabelsSig);
  GetFormatAndDraw(infileH750a9New, outFile, legNew, H750a9Name, kViolet+1, *CanvasArray, scaleH750a9, false, CountH750a9New, CutH750a9New, CutLabelsSig);

  std::cout << "OldMVA" << std::endl;
  GetFormatAndDraw(infileTTOldMVA, outFile, legOldMVA, TTName, kBlue+1, *CanvasArray, scaleTT, false, CountTTOldMVA, CutTTOldMVA, CutLabelsBack);
  GetFormatAndDraw(infileDYOldMVA, outFile, legOldMVA, DYName, kRed, *CanvasArray, scaleDY50, false, CountDYOldMVA, CutDYOldMVA, CutLabelsBack);
//  GetFormatAndDraw(infileWJOldMVA, outFile, legOldMVA, WJName, kGreen+1, *CanvasArray, scaleWJ, false, CountWJOldMVA, CutWJOldMVA, CutLabelsBack);
  GetFormatAndDraw(infileH125a19OldMVA, outFile, legOldMVA, H125a19Name, kBlack, *CanvasArray, scaleH125a19, false, CountH125a19OldMVA, CutH125a19OldMVA, CutLabelsSig);
  GetFormatAndDraw(infileH125a9OldMVA, outFile, legOldMVA, H125a9Name, kGray+1, *CanvasArray, scaleH125a9, false, CountH125a9OldMVA, CutH125a9OldMVA, CutLabelsSig);
  GetFormatAndDraw(infileH125a5OldMVA, outFile, legOldMVA, H125a5Name, kYellow+2, *CanvasArray, scaleH125a5, false, CountH125a5OldMVA, CutH125a5OldMVA, CutLabelsSig);
  GetFormatAndDraw(infileH750a9OldMVA, outFile, legOldMVA, H750a9Name, kViolet+1, *CanvasArray, scaleH750a9, false, CountH750a9OldMVA, CutH750a9OldMVA, CutLabelsSig);

  std::cout << "Old" << std::endl;
  GetFormatAndDraw(infileTTOld, outFile, legOld, TTName, kBlue+1, *CanvasArray, scaleTT, false, CountTTOld, CutTTOld, CutLabelsBack);
  GetFormatAndDraw(infileDYOld, outFile, legOld, DYName, kRed, *CanvasArray, scaleDY50, false, CountDYOld, CutDYOld, CutLabelsBack);
//  GetFormatAndDraw(infileWJOld, outFile, legOld, WJName, kGreen+1, *CanvasArray, scaleWJ, false, CountWJOld, CutWJOld, CutLabelsBack);
  GetFormatAndDraw(infileH125a19Old, outFile, legOld, H125a19Name, kBlack, *CanvasArray, scaleH125a19, false, CountH125a19Old, CutH125a19Old, CutLabelsSig);
  GetFormatAndDraw(infileH125a9Old, outFile, legOld, H125a9Name, kGray+1, *CanvasArray, scaleH125a9, false, CountH125a9Old, CutH125a9Old, CutLabelsSig);
  GetFormatAndDraw(infileH125a5Old, outFile, legOld, H125a5Name, kYellow+2, *CanvasArray, scaleH125a5, false, CountH125a5Old, CutH125a5Old, CutLabelsSig);
  GetFormatAndDraw(infileH750a9Old, outFile, legOld, H750a9Name, kViolet+1, *CanvasArray, scaleH750a9, false, CountH750a9Old, CutH750a9Old, CutLabelsSig);

  /////////////////////////////////
  // Writing Output New + MVA
  /////////////////////////////////
  infoFile << "################################################\n## Cut Info for New DM + MVA \n################################################\n" << endl;
  infoFile << "nEvents with RemovedMuon: DY= " << CutDYNewMVA[0] << "\tTT= " << CutTTNewMVA[0] << "\tWJ= " << CutWJNewMVA[0] << "\tH125a19= " << CutH125a19NewMVA[0] << "\tH125a9= " << CutH125a9NewMVA[0] << "\tH125a5= " << CutH125a5NewMVA[0] << "\tH750a9= " << CutH750a9NewMVA[0] << std::endl;
  infoFile << CutLabelsBack[18] << "\t: DY= " << CutDYNewMVA[18] << "\tTT= " << CutTTNewMVA[18] << "\tWJ= " << CutWJNewMVA[18] << std::endl;
  infoFile << CutLabelsBack[1]  << "\t: DY= " << CutDYNewMVA[1] << "\tTT= " << CutTTNewMVA[1] << "\tWJ= " << CutWJNewMVA[1] << "\tH125a19= " << CutH125a19New[1] << "\tH125a9= " << CutH125a9New[1] << "\tH125a5= " << CutH125a5New[1] << "\tH750a9= " << CutH750a9NewMVA[1] << std::endl;
  infoFile << CutLabelsBack[2]  << "\t: DY= " << CutDYNewMVA[2] << "\tTT= " << CutTTNewMVA[2] << "\tWJ= " << CutWJNewMVA[2] << "\tH125a19= " << CutH125a19New[2] << "\tH125a9= " << CutH125a9New[2] << "\tH125a5= " << CutH125a5New[2] << "\tH750a9= " << CutH750a9NewMVA[2] << std::endl;
  infoFile << CutLabelsBack[3]  << "\t: DY= " << CutDYNewMVA[3] << "\tTT= " << CutTTNewMVA[3] << "\tWJ= " << CutWJNewMVA[3] << "\tH125a19= " << CutH125a19New[3] << "\tH125a9= " << CutH125a9New[3] << "\tH125a5= " << CutH125a5New[3] << "\tH750a9= " << CutH750a9NewMVA[3] << std::endl;
  infoFile << CutLabelsBack[4]  << "\t: DY= " << CutDYNewMVA[4] << "\tTT= " << CutTTNewMVA[4] << "\tWJ= " << CutWJNewMVA[4] << "\tH125a19= " << CutH125a19New[4] << "\tH125a9= " << CutH125a9New[4] << "\tH125a5= " << CutH125a5New[4] << "\tH750a9= " << CutH750a9NewMVA[4] << std::endl;
  infoFile << CutLabelsBack[5]  << "\t: DY= " << CutDYNewMVA[5] << "\tTT= " << CutTTNewMVA[5] << "\tWJ= " << CutWJNewMVA[5] << "\tH125a19= " << CutH125a19New[5] << "\tH125a9= " << CutH125a9New[5] << "\tH125a5= " << CutH125a5New[5] << "\tH750a9= " << CutH750a9NewMVA[5] << std::endl;
  infoFile << CutLabelsBack[6]  << "\t: DY= " << CutDYNewMVA[6] << "\tTT= " << CutTTNewMVA[6] << "\tWJ= " << CutWJNewMVA[6] << "\tH125a19= " << CutH125a19New[6] << "\tH125a9= " << CutH125a9New[6] << "\tH125a5= " << CutH125a5New[6] << "\tH750a9= " << CutH750a9NewMVA[6] << std::endl;
  infoFile << CutLabelsBack[7]  << "\t: DY= " << CutDYNewMVA[7] << "\tTT= " << CutTTNewMVA[7] << "\tWJ= " << CutWJNewMVA[7] << "\tH125a19= " << CutH125a19New[7] << "\tH125a9= " << CutH125a9New[7] << "\tH125a5= " << CutH125a5New[7] << "\tH750a9= " << CutH750a9NewMVA[7] << std::endl;
  infoFile << CutLabelsBack[8]  << "\t: DY= " << CutDYNewMVA[8] << "\tTT= " << CutTTNewMVA[8] << "\tWJ= " << CutWJNewMVA[8] << "\tH125a19= " << CutH125a19New[8] << "\tH125a9= " << CutH125a9New[8] << "\tH125a5= " << CutH125a5New[8] << "\tH750a9= " << CutH750a9NewMVA[8] << std::endl;
  infoFile << CutLabelsBack[17] << "\t: DY= " << CutDYNewMVA[17] << "\tTT= " << CutTTNewMVA[17] << "\tWJ= " << CutWJNewMVA[17] << std::endl;
  infoFile << CutLabelsBack[9] << "\t: DY= " << CutDYNewMVA[9] << "\tTT= " << CutTTNewMVA[9] << "\tWJ= " << CutWJNewMVA[9] << std::endl;
  infoFile << CutLabelsBack[10] << "\t: DY= " << CutDYNewMVA[10] << "\tTT= " << CutTTNewMVA[10] << "\tWJ= " << CutWJNewMVA[10] << std::endl;
  infoFile << CutLabelsBack[11] << "\t: DY= " << CutDYNewMVA[11] << "\tTT= " << CutTTNewMVA[11] << "\tWJ= " << CutWJNewMVA[11] << std::endl;
  infoFile << CutLabelsBack[12] << "\t: DY= " << CutDYNewMVA[12] << "\tTT= " << CutTTNewMVA[12] << "\tWJ= " << CutWJNewMVA[12] << std::endl;
  infoFile << CutLabelsBack[13] << "\t: DY= " << CutDYNewMVA[13] << "\tTT= " << CutTTNewMVA[13] << "\tWJ= " << CutWJNewMVA[13] << std::endl;
  infoFile << CutLabelsBack[14] << "\t: DY= " << CutDYNewMVA[14] << "\tTT= " << CutTTNewMVA[14] << "\tWJ= " << CutWJNewMVA[14] << std::endl;
  infoFile << CutLabelsBack[15] << "\t: DY= " << CutDYNewMVA[15] << "\tTT= " << CutTTNewMVA[15] << "\tWJ= " << CutWJNewMVA[15] << std::endl;
  infoFile << CutLabelsBack[16] << "\t: DY= " << CutDYNewMVA[16] << "\tTT= " << CutTTNewMVA[16] << "\tWJ= " << CutWJNewMVA[16] << std::endl;

  ////////////////////////
  // Writing Output New 
  ///////////////////////
  infoFile << "################################################\n## Cut Info for New DM  \n################################################\n" << endl;
  infoFile << "nEvents with RemovedMuon: DY= " << CutDYNew[0] << "\tTT= " << CutTTNew[0] << "\tWJ= " << CutWJNew[0] << "\tH125a19= " << CutH125a19New[0] << "\tH125a9= " << CutH125a9New[0] << "\tH125a5= " << CutH125a5New[0] << "\tH750a9= " << CutH750a9New[0] << std::endl;
  infoFile << CutLabelsBack[18] << "\t: DY= " << CutDYNew[18] << "\tTT= " << CutTTNew[18] << "\tWJ= " << CutWJNew[18] << std::endl; 
  infoFile << CutLabelsBack[1]  << "\t: DY= " << CutDYNew[1] << "\tTT= " << CutTTNew[1] << "\tWJ= " << CutWJNew[1] << "\tH125a19= " << CutH125a19New[1] << "\tH125a9= " << CutH125a9New[1] << "\tH125a5= " << CutH125a5New[1] << "\tH750a9= " << CutH750a9New[1] << std::endl;
  infoFile << CutLabelsBack[2]  << "\t: DY= " << CutDYNew[2] << "\tTT= " << CutTTNew[2] << "\tWJ= " << CutWJNew[2] << "\tH125a19= " << CutH125a19New[2] << "\tH125a9= " << CutH125a9New[2] << "\tH125a5= " << CutH125a5New[2] << "\tH7i50a9= " << CutH750a9New[2] << std::endl;
  infoFile << CutLabelsBack[3]  << "\t: DY= " << CutDYNew[3] << "\tTT= " << CutTTNew[3] << "\tWJ= " << CutWJNew[3] << "\tH125a19= " << CutH125a19New[3] << "\tH125a9= " << CutH125a9New[3] << "\tH125a5= " << CutH125a5New[3] << "\tH750a9= " << CutH750a9New[3] << std::endl;
  infoFile << CutLabelsBack[4]  << "\t: DY= " << CutDYNew[4] << "\tTT= " << CutTTNew[4] << "\tWJ= " << CutWJNew[4] << "\tH125a19= " << CutH125a19New[4] << "\tH125a9= " << CutH125a9New[4] << "\tH125a5= " << CutH125a5New[4] << "\tH750a9= " << CutH750a9New[4] << std::endl;
  infoFile << CutLabelsBack[5]  << "\t: DY= " << CutDYNew[5] << "\tTT= " << CutTTNew[5] << "\tWJ= " << CutWJNew[5] << "\tH125a19= " << CutH125a19New[5] << "\tH125a9= " << CutH125a9New[5] << "\tH125a5= " << CutH125a5New[5] << "\tH750a9= " << CutH750a9New[5] << std::endl;
  infoFile << CutLabelsBack[6]  << "\t: DY= " << CutDYNew[6] << "\tTT= " << CutTTNew[6] << "\tWJ= " << CutWJNew[6] << "\tH125a19= " << CutH125a19New[6] << "\tH125a9= " << CutH125a9New[6] << "\tH125a5= " << CutH125a5New[6] << "\tH750a9= " << CutH750a9New[6] << std::endl;
  infoFile << CutLabelsBack[7]  << "\t: DY= " << CutDYNew[7] << "\tTT= " << CutTTNew[7] << "\tWJ= " << CutWJNew[7] << "\tH125a19= " << CutH125a19New[7] << "\tH125a9= " << CutH125a9New[7] << "\tH125a5= " << CutH125a5New[7] << "\tH750a9= " << CutH750a9New[7] << std::endl;
  infoFile << CutLabelsBack[8]  << "\t: DY= " << CutDYNew[8] << "\tTT= " << CutTTNew[8] << "\tWJ= " << CutWJNew[8] << "\tH125a19= " << CutH125a19New[8] << "\tH125a9= " << CutH125a9New[8] << "\tH125a5= " << CutH125a5New[8] << "\tH750a9= " << CutH750a9New[8] << std::endl;
  infoFile << CutLabelsBack[17] << "\t: DY= " << CutDYNew[17] << "\tTT= " << CutTTNew[17] << "\tWJ= " << CutWJNew[17] << std::endl;
  infoFile << CutLabelsBack[9] << "\t: DY= " << CutDYNew[9] << "\tTT= " << CutTTNew[9] << "\tWJ= " << CutWJNew[9] << std::endl;
  infoFile << CutLabelsBack[10] << "\t: DY= " << CutDYNew[10] << "\tTT= " << CutTTNew[10] << "\tWJ= " << CutWJNew[10] << std::endl;
  infoFile << CutLabelsBack[11] << "\t: DY= " << CutDYNew[11] << "\tTT= " << CutTTNew[11] << "\tWJ= " << CutWJNew[11] << std::endl;
  infoFile << CutLabelsBack[12] << "\t: DY= " << CutDYNew[12] << "\tTT= " << CutTTNew[12] << "\tWJ= " << CutWJNew[12] << std::endl;
  infoFile << CutLabelsBack[13] << "\t: DY= " << CutDYNew[13] << "\tTT= " << CutTTNew[13] << "\tWJ= " << CutWJNew[13] << std::endl;
  infoFile << CutLabelsBack[14] << "\t: DY= " << CutDYNew[14] << "\tTT= " << CutTTNew[14] << "\tWJ= " << CutWJNew[14] << std::endl;
  infoFile << CutLabelsBack[15] << "\t: DY= " << CutDYNew[15] << "\tTT= " << CutTTNew[15] << "\tWJ= " << CutWJNew[15] << std::endl;
  infoFile << CutLabelsBack[16] << "\t: DY= " << CutDYNew[16] << "\tTT= " << CutTTNew[16] << "\tWJ= " << CutWJNew[16] << std::endl;

  ////////////////////////
  // Writing Output OldMVA 
  ///////////////////////
  infoFile << "################################################\n## Cut Info for OldMVA DM  \n################################################\n" << endl;
  infoFile << "nEvents with RemovedMuon: DY= " << CutDYOldMVA[0] << "\tTT= " << CutTTOldMVA[0] << "\tWJ= " << CutWJOldMVA[0] << "\tH125a19= " << CutH125a19OldMVA[0] << "\tH125a9= " << CutH125a9OldMVA[0] << "\tH125a5= " << CutH125a5OldMVA[0] << "\tH750a9= " << CutH750a9OldMVA[0] << std::endl;
  infoFile << CutLabelsBack[18] << "\t: DY= " << CutDYOldMVA[18] << "\tTT= " << CutTTOldMVA[18] << "\tWJ= " << CutWJOldMVA[18] << std::endl; 
  infoFile << CutLabelsBack[1]  << "\t: DY= " << CutDYOldMVA[1] << "\tTT= " << CutTTOldMVA[1] << "\tWJ= " << CutWJOldMVA[1] << "\tH125a19= " << CutH125a19OldMVA[1] << "\tH125a9= " << CutH125a9OldMVA[1] << "\tH125a5= " << CutH125a5OldMVA[1] << "\tH750a9= " << CutH750a9OldMVA[1] << std::endl;
  infoFile << CutLabelsBack[2]  << "\t: DY= " << CutDYOldMVA[2] << "\tTT= " << CutTTOldMVA[2] << "\tWJ= " << CutWJOldMVA[2] << "\tH125a19= " << CutH125a19OldMVA[2] << "\tH125a9= " << CutH125a9OldMVA[2] << "\tH125a5= " << CutH125a5OldMVA[2] << "\tH7i50a9= " << CutH750a9OldMVA[2] << std::endl;
  infoFile << CutLabelsBack[3]  << "\t: DY= " << CutDYOldMVA[3] << "\tTT= " << CutTTOldMVA[3] << "\tWJ= " << CutWJOldMVA[3] << "\tH125a19= " << CutH125a19OldMVA[3] << "\tH125a9= " << CutH125a9OldMVA[3] << "\tH125a5= " << CutH125a5OldMVA[3] << "\tH750a9= " << CutH750a9OldMVA[3] << std::endl;
  infoFile << CutLabelsBack[4]  << "\t: DY= " << CutDYOldMVA[4] << "\tTT= " << CutTTOldMVA[4] << "\tWJ= " << CutWJOldMVA[4] << "\tH125a19= " << CutH125a19OldMVA[4] << "\tH125a9= " << CutH125a9OldMVA[4] << "\tH125a5= " << CutH125a5OldMVA[4] << "\tH750a9= " << CutH750a9OldMVA[4] << std::endl;
  infoFile << CutLabelsBack[5]  << "\t: DY= " << CutDYOldMVA[5] << "\tTT= " << CutTTOldMVA[5] << "\tWJ= " << CutWJOldMVA[5] << "\tH125a19= " << CutH125a19OldMVA[5] << "\tH125a9= " << CutH125a9OldMVA[5] << "\tH125a5= " << CutH125a5OldMVA[5] << "\tH750a9= " << CutH750a9OldMVA[5] << std::endl;
  infoFile << CutLabelsBack[6]  << "\t: DY= " << CutDYOldMVA[6] << "\tTT= " << CutTTOldMVA[6] << "\tWJ= " << CutWJOldMVA[6] << "\tH125a19= " << CutH125a19OldMVA[6] << "\tH125a9= " << CutH125a9OldMVA[6] << "\tH125a5= " << CutH125a5OldMVA[6] << "\tH750a9= " << CutH750a9OldMVA[6] << std::endl;
  infoFile << CutLabelsBack[7]  << "\t: DY= " << CutDYOldMVA[7] << "\tTT= " << CutTTOldMVA[7] << "\tWJ= " << CutWJOldMVA[7] << "\tH125a19= " << CutH125a19OldMVA[7] << "\tH125a9= " << CutH125a9OldMVA[7] << "\tH125a5= " << CutH125a5OldMVA[7] << "\tH750a9= " << CutH750a9OldMVA[7] << std::endl;
  infoFile << CutLabelsBack[8]  << "\t: DY= " << CutDYOldMVA[8] << "\tTT= " << CutTTOldMVA[8] << "\tWJ= " << CutWJOldMVA[8] << "\tH125a19= " << CutH125a19OldMVA[8] << "\tH125a9= " << CutH125a9OldMVA[8] << "\tH125a5= " << CutH125a5OldMVA[8] << "\tH750a9= " << CutH750a9OldMVA[8] << std::endl;
  infoFile << CutLabelsBack[17] << "\t: DY= " << CutDYOldMVA[17] << "\tTT= " << CutTTOldMVA[17] << "\tWJ= " << CutWJOldMVA[17] << std::endl;
  infoFile << CutLabelsBack[9] << "\t: DY= " << CutDYOldMVA[9] << "\tTT= " << CutTTOldMVA[9] << "\tWJ= " << CutWJOldMVA[9] << std::endl;
  infoFile << CutLabelsBack[10] << "\t: DY= " << CutDYOldMVA[10] << "\tTT= " << CutTTOldMVA[10] << "\tWJ= " << CutWJOldMVA[10] << std::endl;
  infoFile << CutLabelsBack[11] << "\t: DY= " << CutDYOldMVA[11] << "\tTT= " << CutTTOldMVA[11] << "\tWJ= " << CutWJOldMVA[11] << std::endl;
  infoFile << CutLabelsBack[12] << "\t: DY= " << CutDYOldMVA[12] << "\tTT= " << CutTTOldMVA[12] << "\tWJ= " << CutWJOldMVA[12] << std::endl;
  infoFile << CutLabelsBack[13] << "\t: DY= " << CutDYOldMVA[13] << "\tTT= " << CutTTOldMVA[13] << "\tWJ= " << CutWJOldMVA[13] << std::endl;
  infoFile << CutLabelsBack[14] << "\t: DY= " << CutDYOldMVA[14] << "\tTT= " << CutTTOldMVA[14] << "\tWJ= " << CutWJOldMVA[14] << std::endl;
  infoFile << CutLabelsBack[15] << "\t: DY= " << CutDYOldMVA[15] << "\tTT= " << CutTTOldMVA[15] << "\tWJ= " << CutWJOldMVA[15] << std::endl;
  infoFile << CutLabelsBack[16] << "\t: DY= " << CutDYOldMVA[16] << "\tTT= " << CutTTOldMVA[16] << "\tWJ= " << CutWJOldMVA[16] << std::endl;

  ////////////////////////
  // Writing Output Old 
  ///////////////////////
  infoFile << "################################################\n## Cut Info for Old DM  \n################################################\n" << endl;
  infoFile << "nEvents with RemovedMuon: DY= " << CutDYOld[0] << "\tTT= " << CutTTOld[0] << "\tWJ= " << CutWJOld[0] << "\tH125a19= " << CutH125a19Old[0] << "\tH125a9= " << CutH125a9Old[0] << "\tH125a5= " << CutH125a5Old[0] << "\tH750a9= " << CutH750a9Old[0] << std::endl;
  infoFile << CutLabelsBack[18] << "\t: DY= " << CutDYOld[18] << "\tTT= " << CutTTOld[18] << "\tWJ= " << CutWJOld[18] << std::endl; 
  infoFile << CutLabelsBack[1]  << "\t: DY= " << CutDYOld[1] << "\tTT= " << CutTTOld[1] << "\tWJ= " << CutWJOld[1] << "\tH125a19= " << CutH125a19Old[1] << "\tH125a9= " << CutH125a9Old[1] << "\tH125a5= " << CutH125a5Old[1] << "\tH750a9= " << CutH750a9Old[1] << std::endl;
  infoFile << CutLabelsBack[2]  << "\t: DY= " << CutDYOld[2] << "\tTT= " << CutTTOld[2] << "\tWJ= " << CutWJOld[2] << "\tH125a19= " << CutH125a19Old[2] << "\tH125a9= " << CutH125a9Old[2] << "\tH125a5= " << CutH125a5Old[2] << "\tH7i50a9= " << CutH750a9Old[2] << std::endl;
  infoFile << CutLabelsBack[3]  << "\t: DY= " << CutDYOld[3] << "\tTT= " << CutTTOld[3] << "\tWJ= " << CutWJOld[3] << "\tH125a19= " << CutH125a19Old[3] << "\tH125a9= " << CutH125a9Old[3] << "\tH125a5= " << CutH125a5Old[3] << "\tH750a9= " << CutH750a9Old[3] << std::endl;
  infoFile << CutLabelsBack[4]  << "\t: DY= " << CutDYOld[4] << "\tTT= " << CutTTOld[4] << "\tWJ= " << CutWJOld[4] << "\tH125a19= " << CutH125a19Old[4] << "\tH125a9= " << CutH125a9Old[4] << "\tH125a5= " << CutH125a5Old[4] << "\tH750a9= " << CutH750a9Old[4] << std::endl;
  infoFile << CutLabelsBack[5]  << "\t: DY= " << CutDYOld[5] << "\tTT= " << CutTTOld[5] << "\tWJ= " << CutWJOld[5] << "\tH125a19= " << CutH125a19Old[5] << "\tH125a9= " << CutH125a9Old[5] << "\tH125a5= " << CutH125a5Old[5] << "\tH750a9= " << CutH750a9Old[5] << std::endl;
  infoFile << CutLabelsBack[6]  << "\t: DY= " << CutDYOld[6] << "\tTT= " << CutTTOld[6] << "\tWJ= " << CutWJOld[6] << "\tH125a19= " << CutH125a19Old[6] << "\tH125a9= " << CutH125a9Old[6] << "\tH125a5= " << CutH125a5Old[6] << "\tH750a9= " << CutH750a9Old[6] << std::endl;
  infoFile << CutLabelsBack[7]  << "\t: DY= " << CutDYOld[7] << "\tTT= " << CutTTOld[7] << "\tWJ= " << CutWJOld[7] << "\tH125a19= " << CutH125a19Old[7] << "\tH125a9= " << CutH125a9Old[7] << "\tH125a5= " << CutH125a5Old[7] << "\tH750a9= " << CutH750a9Old[7] << std::endl;
  infoFile << CutLabelsBack[8]  << "\t: DY= " << CutDYOld[8] << "\tTT= " << CutTTOld[8] << "\tWJ= " << CutWJOld[8] << "\tH125a19= " << CutH125a19Old[8] << "\tH125a9= " << CutH125a9Old[8] << "\tH125a5= " << CutH125a5Old[8] << "\tH750a9= " << CutH750a9Old[8] << std::endl;
  infoFile << CutLabelsBack[17] << "\t: DY= " << CutDYOld[17] << "\tTT= " << CutTTOld[17] << "\tWJ= " << CutWJOld[17] << std::endl;
  infoFile << CutLabelsBack[9] << "\t: DY= " << CutDYOld[9] << "\tTT= " << CutTTOld[9] << "\tWJ= " << CutWJOld[9] << std::endl;
  infoFile << CutLabelsBack[10] << "\t: DY= " << CutDYOld[10] << "\tTT= " << CutTTOld[10] << "\tWJ= " << CutWJOld[10] << std::endl;
  infoFile << CutLabelsBack[11] << "\t: DY= " << CutDYOld[11] << "\tTT= " << CutTTOld[11] << "\tWJ= " << CutWJOld[11] << std::endl;
  infoFile << CutLabelsBack[12] << "\t: DY= " << CutDYOld[12] << "\tTT= " << CutTTOld[12] << "\tWJ= " << CutWJOld[12] << std::endl;
  infoFile << CutLabelsBack[13] << "\t: DY= " << CutDYOld[13] << "\tTT= " << CutTTOld[13] << "\tWJ= " << CutWJOld[13] << std::endl;
  infoFile << CutLabelsBack[14] << "\t: DY= " << CutDYOld[14] << "\tTT= " << CutTTOld[14] << "\tWJ= " << CutWJOld[14] << std::endl;
  infoFile << CutLabelsBack[15] << "\t: DY= " << CutDYOld[15] << "\tTT= " << CutTTOld[15] << "\tWJ= " << CutWJOld[15] << std::endl;
  infoFile << CutLabelsBack[16] << "\t: DY= " << CutDYOld[16] << "\tTT= " << CutTTOld[16] << "\tWJ= " << CutWJOld[16] << std::endl;

  //////////////////////////
  // Writing TT information
  //////////////////////////
  infoFile << "\n\n\n############################################\n## TTbar || Total Number of Events:\n## NewMVA= " << CountTTNewMVA[4] << "\tNew= " << CountTTNew[4] << "\tOldMVA= ";
  infoFile << CountTTOldMVA[4] << "\tOld= " << CountTTOld[4] << "\n#############################################\n" << endl;
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountTTNew[3] << "\t\t| " << CountTTNewMVA[0] << "\t\t| " << CountTTNew[0] << "\t\t| " << CountTTOldMVA[0] << "\t\t| " << CountTTOld[0] << endl;
  infoFile << "Med:   | " << CountTTNew[3] << "\t\t| " << CountTTNewMVA[1] << "\t\t| " << CountTTNew[1] << "\t\t| " << CountTTOldMVA[1] << "\t\t| " << CountTTOld[1] << endl; 
  infoFile << "Tight: | " << CountTTNew[3] << "\t\t| " << CountTTNewMVA[2] << "\t\t| " << CountTTNew[2] << "\t\t| " << CountTTOldMVA[2] << "\t\t| " << CountTTOld[2] << endl;
  
  infoFile << "\nFraction of Total of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountTTNew[3]/CountTTNew[4] << "\t| " << CountTTNewMVA[0]/CountTTNewMVA[4] << "\t| ";
  infoFile << CountTTNew[0]/CountTTNew[4] << "\t| " << CountTTOldMVA[0]/CountTTOldMVA[4] << "\t| " << CountTTOld[0]/CountTTOld[4] << endl;
  infoFile << "Med:   | " << CountTTNew[3]/CountTTNew[4] << "\t| " << CountTTNewMVA[1]/CountTTNewMVA[4] << "\t| " << CountTTNew[1]/CountTTNew[4];
  infoFile << "\t| " << CountTTOldMVA[1]/CountTTOldMVA[4] << "\t| ";
  infoFile << CountTTOld[1]/CountTTOld[4] << endl;
  infoFile << "Tight: | " << CountTTNew[3]/CountTTNew[4] << "\t| " << CountTTNewMVA[2]/CountTTNewMVA[4] << "\t| " ;
  infoFile << CountTTNew[2]/CountTTNew[4] << "\t| " << CountTTOldMVA[2]/CountTTOldMVA[4] << "\t| " << CountTTOld[2]/CountTTOld[4] << endl;

  infoFile << "\nFraction of Events with a Removed Muon (a.k.a. A Cleaned Jet):" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountTTNew[3]/CountTTNew[3] << "\t\t| " << CountTTNewMVA[0]/CountTTNewMVA[3] << "\t| ";
  infoFile << CountTTNew[0]/CountTTNew[3] << "\t| " << CountTTOldMVA[0]/CountTTOldMVA[3] << "\t| " << CountTTOld[0]/CountTTOld[3] << endl;
  infoFile << "Med:   | " << CountTTNew[3]/CountTTNew[3] << "\t\t| " << CountTTNewMVA[1]/CountTTNewMVA[3] << "\t| ";
  infoFile << CountTTNew[1]/CountTTNew[3] << "\t| " << CountTTOldMVA[1]/CountTTOldMVA[3] << "\t| " << CountTTOld[1]/CountTTOld[3] << endl;
  infoFile << "Tight: | " << CountTTNew[3]/CountTTNew[3] << "\t\t| " << CountTTNewMVA[2]/CountTTNewMVA[3] << "\t| ";
  infoFile << CountTTNew[2]/CountTTNew[3] << "\t| " << CountTTOldMVA[2]/CountTTOldMVA[3] << "\t| " << CountTTOld[2]/CountTTOld[3] << endl;

  //////////////////////////
  // Writing DY information
  //////////////////////////
  infoFile << "\n\n\n############################################\n## DYbar || Total Number of Events:\n## NewMVA= " << CountDYNewMVA[4] << "\tNew= " << CountDYNew[4] << "\tOldMVA= ";
  infoFile << CountDYOldMVA[4] << "\tOld= " << CountDYOld[4] << "\n#############################################\n" << endl; 
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountDYNew[3] << "\t\t| " << CountDYNewMVA[0] << "\t\t| " << CountDYNew[0] << "\t\t| " << CountDYOldMVA[0] << "\t\t| " << CountDYOld[0] << endl;
  infoFile << "Med:   | " << CountDYNew[3] << "\t\t| " << CountDYNewMVA[1] << "\t\t| " << CountDYNew[1] << "\t\t| " << CountDYOldMVA[1] << "\t\t| " << CountDYOld[1] << endl; 
  infoFile << "Tight: | " << CountDYNew[3] << "\t\t| " << CountDYNewMVA[2] << "\t\t| " << CountDYNew[2] << "\t\t| " << CountDYOldMVA[2] << "\t\t| " << CountDYOld[2] << endl;

  infoFile << "\nFraction of Total of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountDYNew[3]/CountDYNew[4] << "\t| " << CountDYNewMVA[0]/CountDYNewMVA[4] << "\t| ";
  infoFile << CountDYNew[0]/CountDYNew[4] << "\t| " << CountDYOldMVA[0]/CountDYOldMVA[4] << "\t| " << CountDYOld[0]/CountDYOld[4] << endl;
  infoFile << "Med:   | " << CountDYNew[3]/CountDYNew[4] << "\t| " << CountDYNewMVA[1]/CountDYNewMVA[4] << "\t| " << CountDYNew[1]/CountDYNew[4]; 
  infoFile << "\t| " << CountDYOldMVA[1]/CountDYOldMVA[4] << "\t| ";
  infoFile << CountDYOld[1]/CountDYOld[4] << endl;
  infoFile << "Tight: | " << CountDYNew[3]/CountDYNew[4] << "\t| " << CountDYNewMVA[2]/CountDYNewMVA[4] << "\t| " ;
  infoFile << CountDYNew[2]/CountDYNew[4] << "\t| " << CountDYOldMVA[2]/CountDYOldMVA[4] << "\t| " << CountDYOld[2]/CountDYOld[4] << endl; 
  
  infoFile << "\nFraction of Events with a Removed Muon (a.k.a. A Cleaned Jet):" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountDYNew[3]/CountDYNew[3] << "\t\t| " << CountDYNewMVA[0]/CountDYNewMVA[3] << "\t| ";
  infoFile << CountDYNew[0]/CountDYNew[3] << "\t| " << CountDYOldMVA[0]/CountDYOldMVA[3] << "\t| " << CountDYOld[0]/CountDYOld[3] << endl; 
  infoFile << "Med:   | " << CountDYNew[3]/CountDYNew[3] << "\t\t| " << CountDYNewMVA[1]/CountDYNewMVA[3] << "\t| ";
  infoFile << CountDYNew[1]/CountDYNew[3] << "\t| " << CountDYOldMVA[1]/CountDYOldMVA[3] << "\t| " << CountDYOld[1]/CountDYOld[3] << endl;
  infoFile << "Tight: | " << CountDYNew[3]/CountDYNew[3] << "\t\t| " << CountDYNewMVA[2]/CountDYNewMVA[3] << "\t| ";
  infoFile << CountDYNew[2]/CountDYNew[3] << "\t| " << CountDYOldMVA[2]/CountDYOldMVA[3] << "\t| " << CountDYOld[2]/CountDYOld[3] << endl; 

/*  //////////////////////////
  // Writing WJ information
  //////////////////////////
  infoFile << "\n\n\n############################################\n## WJbar || Total Number of Events:\n## NewMVA= " << CountWJNewMVA[4] << "\tNew= " << CountWJNew[4] << "\tOldMVA= ";
  infoFile << CountWJOldMVA[4] << "\tOld= " << CountWJOld[4] << "\n#############################################\n" << endl; 
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountWJNew[3] << "\t\t| " << CountWJNewMVA[0] << "\t\t| " << CountWJNew[0] << "\t\t| " << CountWJOldMVA[0] << "\t\t| " << CountWJOld[0] << endl;
  infoFile << "Med:   | " << CountWJNew[3] << "\t\t| " << CountWJNewMVA[1] << "\t\t| " << CountWJNew[1] << "\t\t| " << CountWJOldMVA[1] << "\t\t| " << CountWJOld[1] << endl; 
  infoFile << "Tight: | " << CountWJNew[3] << "\t\t| " << CountWJNewMVA[2] << "\t\t| " << CountWJNew[2] << "\t\t| " << CountWJOldMVA[2] << "\t\t| " << CountWJOld[2] << endl;

  infoFile << "\nFraction of Total of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountWJNew[3]/CountWJNew[4] << "\t| " << CountWJNewMVA[0]/CountWJNewMVA[4] << "\t| ";
  infoFile << CountWJNew[0]/CountWJNew[4] << "\t| " << CountWJOldMVA[0]/CountWJOldMVA[4] << "\t| " << CountWJOld[0]/CountWJOld[4] << endl;
  infoFile << "Med:   | " << CountWJNew[3]/CountWJNew[4] << "\t| " << CountWJNewMVA[1]/CountWJNewMVA[4] << "\t| " << CountWJNew[1]/CountWJNew[4]; 
  infoFile << "\t| " << CountWJOldMVA[1]/CountWJOldMVA[4] << "\t| ";
  infoFile << CountWJOld[1]/CountWJOld[4] << endl;
  infoFile << "Tight: | " << CountWJNew[3]/CountWJNew[4] << "\t| " << CountWJNewMVA[2]/CountWJNewMVA[4] << "\t| " ;
  infoFile << CountWJNew[2]/CountWJNew[4] << "\t| " << CountWJOldMVA[2]/CountWJOldMVA[4] << "\t| " << CountWJOld[2]/CountWJOld[4] << endl; 
  
  infoFile << "\nFraction of Events with a Removed Muon (a.k.a. A Cleaned Jet):" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountWJNew[3]/CountWJNew[3] << "\t\t| " << CountWJNewMVA[0]/CountWJNewMVA[3] << "\t| ";
  infoFile << CountWJNew[0]/CountWJNew[3] << "\t| " << CountWJOldMVA[0]/CountWJOldMVA[3] << "\t| " << CountWJOld[0]/CountWJOld[3] << endl; 
  infoFile << "Med:   | " << CountWJNew[3]/CountWJNew[3] << "\t\t| " << CountWJNewMVA[1]/CountWJNewMVA[3] << "\t| ";
  infoFile << CountWJNew[1]/CountWJNew[3] << "\t| " << CountWJOldMVA[1]/CountWJOldMVA[3] << "\t| " << CountWJOld[1]/CountWJOld[3] << endl;
  infoFile << "Tight: | " << CountWJNew[3]/CountWJNew[3] << "\t\t| " << CountWJNewMVA[2]/CountWJNewMVA[3] << "\t| ";
  infoFile << CountWJNew[2]/CountWJNew[3] << "\t| " << CountWJOldMVA[2]/CountWJOldMVA[3] << "\t| " << CountWJOld[2]/CountWJOld[3] << endl; 
*/

  //////////////////////////
  // Writing H125a19 information
  //////////////////////////
  infoFile << "\n\n\n############################################\n## H125a19bar || Total Number of Events:\n## NewMVA= " << CountH125a19NewMVA[4] << "\tNew= " << CountH125a19New[4] << "\tOldMVA= ";
  infoFile << CountH125a19OldMVA[4] << "\tOld= " << CountH125a19Old[4] << "\n#############################################\n" << endl; 
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH125a19New[3] << "\t\t| " << CountH125a19NewMVA[0] << "\t\t| " << CountH125a19New[0] << "\t\t| " << CountH125a19OldMVA[0] << "\t\t| " << CountH125a19Old[0] << endl;
  infoFile << "Med:   | " << CountH125a19New[3] << "\t\t| " << CountH125a19NewMVA[1] << "\t\t| " << CountH125a19New[1] << "\t\t| " << CountH125a19OldMVA[1] << "\t\t| " << CountH125a19Old[1] << endl; 
  infoFile << "Tight: | " << CountH125a19New[3] << "\t\t| " << CountH125a19NewMVA[2] << "\t\t| " << CountH125a19New[2] << "\t\t| " << CountH125a19OldMVA[2] << "\t\t| " << CountH125a19Old[2] << endl;

  infoFile << "\nFraction of Total of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH125a19New[3]/CountH125a19New[4] << "\t| " << CountH125a19NewMVA[0]/CountH125a19NewMVA[4] << "\t| ";
  infoFile << CountH125a19New[0]/CountH125a19New[4] << "\t| " << CountH125a19OldMVA[0]/CountH125a19OldMVA[4] << "\t| " << CountH125a19Old[0]/CountH125a19Old[4] << endl;
  infoFile << "Med:   | " << CountH125a19New[3]/CountH125a19New[4] << "\t| " << CountH125a19NewMVA[1]/CountH125a19NewMVA[4] << "\t| " << CountH125a19New[1]/CountH125a19New[4]; 
  infoFile << "\t| " << CountH125a19OldMVA[1]/CountH125a19OldMVA[4] << "\t| ";
  infoFile << CountH125a19Old[1]/CountH125a19Old[4] << endl;
  infoFile << "Tight: | " << CountH125a19New[3]/CountH125a19New[4] << "\t| " << CountH125a19NewMVA[2]/CountH125a19NewMVA[4] << "\t| " ;
  infoFile << CountH125a19New[2]/CountH125a19New[4] << "\t| " << CountH125a19OldMVA[2]/CountH125a19OldMVA[4] << "\t| " << CountH125a19Old[2]/CountH125a19Old[4] << endl; 
  
  infoFile << "\nFraction of Events with a Removed Muon (a.k.a. A Cleaned Jet):" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH125a19New[3]/CountH125a19New[3] << "\t\t| " << CountH125a19NewMVA[0]/CountH125a19NewMVA[3] << "\t| ";
  infoFile << CountH125a19New[0]/CountH125a19New[3] << "\t| " << CountH125a19OldMVA[0]/CountH125a19OldMVA[3] << "\t| " << CountH125a19Old[0]/CountH125a19Old[3] << endl; 
  infoFile << "Med:   | " << CountH125a19New[3]/CountH125a19New[3] << "\t\t| " << CountH125a19NewMVA[1]/CountH125a19NewMVA[3] << "\t| ";
  infoFile << CountH125a19New[1]/CountH125a19New[3] << "\t| " << CountH125a19OldMVA[1]/CountH125a19OldMVA[3] << "\t| " << CountH125a19Old[1]/CountH125a19Old[3] << endl;
  infoFile << "Tight: | " << CountH125a19New[3]/CountH125a19New[3] << "\t\t| " << CountH125a19NewMVA[2]/CountH125a19NewMVA[3] << "\t| ";
  infoFile << CountH125a19New[2]/CountH125a19New[3] << "\t| " << CountH125a19OldMVA[2]/CountH125a19OldMVA[3] << "\t| " << CountH125a19Old[2]/CountH125a19Old[3] << endl; 

  //////////////////////////
  // Writing H125a9 information
  //////////////////////////
  infoFile << "\n\n\n############################################\n## H125a9bar || Total Number of Events:\n## NewMVA= " << CountH125a9NewMVA[4] << "\tNew= " << CountH125a9New[4] << "\tOldMVA= ";
  infoFile << CountH125a9OldMVA[4] << "\tOld= " << CountH125a9Old[4] << "\n#############################################\n" << endl; 
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH125a9New[3] << "\t\t| " << CountH125a9NewMVA[0] << "\t\t| " << CountH125a9New[0] << "\t\t| " << CountH125a9OldMVA[0] << "\t\t| " << CountH125a9Old[0] << endl;
  infoFile << "Med:   | " << CountH125a9New[3] << "\t\t| " << CountH125a9NewMVA[1] << "\t\t| " << CountH125a9New[1] << "\t\t| " << CountH125a9OldMVA[1] << "\t\t| " << CountH125a9Old[1] << endl; 
  infoFile << "Tight: | " << CountH125a9New[3] << "\t\t| " << CountH125a9NewMVA[2] << "\t\t| " << CountH125a9New[2] << "\t\t| " << CountH125a9OldMVA[2] << "\t\t| " << CountH125a9Old[2] << endl;

  infoFile << "\nFraction of Total of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH125a9New[3]/CountH125a9New[4] << "\t| " << CountH125a9NewMVA[0]/CountH125a9NewMVA[4] << "\t| ";
  infoFile << CountH125a9New[0]/CountH125a9New[4] << "\t| " << CountH125a9OldMVA[0]/CountH125a9OldMVA[4] << "\t| " << CountH125a9Old[0]/CountH125a9Old[4] << endl;
  infoFile << "Med:   | " << CountH125a9New[3]/CountH125a9New[4] << "\t| " << CountH125a9NewMVA[1]/CountH125a9NewMVA[4] << "\t| " << CountH125a9New[1]/CountH125a9New[4]; 
  infoFile << "\t| " << CountH125a9OldMVA[1]/CountH125a9OldMVA[4] << "\t| ";
  infoFile << CountH125a9Old[1]/CountH125a9Old[4] << endl;
  infoFile << "Tight: | " << CountH125a9New[3]/CountH125a9New[4] << "\t| " << CountH125a9NewMVA[2]/CountH125a9NewMVA[4] << "\t| " ;
  infoFile << CountH125a9New[2]/CountH125a9New[4] << "\t| " << CountH125a9OldMVA[2]/CountH125a9OldMVA[4] << "\t| " << CountH125a9Old[2]/CountH125a9Old[4] << endl; 
  
  infoFile << "\nFraction of Events with a Removed Muon (a.k.a. A Cleaned Jet):" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH125a9New[3]/CountH125a9New[3] << "\t\t| " << CountH125a9NewMVA[0]/CountH125a9NewMVA[3] << "\t| ";
  infoFile << CountH125a9New[0]/CountH125a9New[3] << "\t| " << CountH125a9OldMVA[0]/CountH125a9OldMVA[3] << "\t| " << CountH125a9Old[0]/CountH125a9Old[3] << endl; 
  infoFile << "Med:   | " << CountH125a9New[3]/CountH125a9New[3] << "\t\t| " << CountH125a9NewMVA[1]/CountH125a9NewMVA[3] << "\t| ";
  infoFile << CountH125a9New[1]/CountH125a9New[3] << "\t| " << CountH125a9OldMVA[1]/CountH125a9OldMVA[3] << "\t| " << CountH125a9Old[1]/CountH125a9Old[3] << endl;
  infoFile << "Tight: | " << CountH125a9New[3]/CountH125a9New[3] << "\t\t| " << CountH125a9NewMVA[2]/CountH125a9NewMVA[3] << "\t| ";
  infoFile << CountH125a9New[2]/CountH125a9New[3] << "\t| " << CountH125a9OldMVA[2]/CountH125a9OldMVA[3] << "\t| " << CountH125a9Old[2]/CountH125a9Old[3] << endl; 

  //////////////////////////
  // Writing H125a5 information
  //////////////////////////
  infoFile << "\n\n\n############################################\n## H125a5bar || Total Number of Events:\n## NewMVA= " << CountH125a5NewMVA[4] << "\tNew= " << CountH125a5New[4] << "\tOldMVA= ";
  infoFile << CountH125a5OldMVA[4] << "\tOld= " << CountH125a5Old[4] << "\n#############################################\n" << endl; 
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH125a5New[3] << "\t\t| " << CountH125a5NewMVA[0] << "\t\t| " << CountH125a5New[0] << "\t\t| " << CountH125a5OldMVA[0] << "\t\t| " << CountH125a5Old[0] << endl;
  infoFile << "Med:   | " << CountH125a5New[3] << "\t\t| " << CountH125a5NewMVA[1] << "\t\t| " << CountH125a5New[1] << "\t\t| " << CountH125a5OldMVA[1] << "\t\t| " << CountH125a5Old[1] << endl; 
  infoFile << "Tight: | " << CountH125a5New[3] << "\t\t| " << CountH125a5NewMVA[2] << "\t\t| " << CountH125a5New[2] << "\t\t| " << CountH125a5OldMVA[2] << "\t\t| " << CountH125a5Old[2] << endl;

  infoFile << "\nFraction of Total of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH125a5New[3]/CountH125a5New[4] << "\t| " << CountH125a5NewMVA[0]/CountH125a5NewMVA[4] << "\t| ";
  infoFile << CountH125a5New[0]/CountH125a5New[4] << "\t| " << CountH125a5OldMVA[0]/CountH125a5OldMVA[4] << "\t| " << CountH125a5Old[0]/CountH125a5Old[4] << endl;
  infoFile << "Med:   | " << CountH125a5New[3]/CountH125a5New[4] << "\t| " << CountH125a5NewMVA[1]/CountH125a5NewMVA[4] << "\t| " << CountH125a5New[1]/CountH125a5New[4]; 
  infoFile << "\t| " << CountH125a5OldMVA[1]/CountH125a5OldMVA[4] << "\t| ";
  infoFile << CountH125a5Old[1]/CountH125a5Old[4] << endl;
  infoFile << "Tight: | " << CountH125a5New[3]/CountH125a5New[4] << "\t| " << CountH125a5NewMVA[2]/CountH125a5NewMVA[4] << "\t| " ;
  infoFile << CountH125a5New[2]/CountH125a5New[4] << "\t| " << CountH125a5OldMVA[2]/CountH125a5OldMVA[4] << "\t| " << CountH125a5Old[2]/CountH125a5Old[4] << endl; 
  
  infoFile << "\nFraction of Events with a Removed Muon (a.k.a. A Cleaned Jet):" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH125a5New[3]/CountH125a5New[3] << "\t\t| " << CountH125a5NewMVA[0]/CountH125a5NewMVA[3] << "\t| ";
  infoFile << CountH125a5New[0]/CountH125a5New[3] << "\t| " << CountH125a5OldMVA[0]/CountH125a5OldMVA[3] << "\t| " << CountH125a5Old[0]/CountH125a5Old[3] << endl; 
  infoFile << "Med:   | " << CountH125a5New[3]/CountH125a5New[3] << "\t\t| " << CountH125a5NewMVA[1]/CountH125a5NewMVA[3] << "\t| ";
  infoFile << CountH125a5New[1]/CountH125a5New[3] << "\t| " << CountH125a5OldMVA[1]/CountH125a5OldMVA[3] << "\t| " << CountH125a5Old[1]/CountH125a5Old[3] << endl;
  infoFile << "Tight: | " << CountH125a5New[3]/CountH125a5New[3] << "\t\t| " << CountH125a5NewMVA[2]/CountH125a5NewMVA[3] << "\t| ";
  infoFile << CountH125a5New[2]/CountH125a5New[3] << "\t| " << CountH125a5OldMVA[2]/CountH125a5OldMVA[3] << "\t| " << CountH125a5Old[2]/CountH125a5Old[3] << endl; 

  //////////////////////////
  // Writing H750a9 information
  //////////////////////////
  infoFile << "\n\n\n############################################\n## H750a9bar || Total Number of Events:\n## NewMVA= " << CountH750a9NewMVA[4] << "\tNew= " << CountH750a9New[4] << "\tOldMVA= ";
  infoFile << CountH750a9OldMVA[4] << "\tOld= " << CountH750a9Old[4] << "\n#############################################\n" << endl; 
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH750a9New[3] << "\t\t| " << CountH750a9NewMVA[0] << "\t\t| " << CountH750a9New[0] << "\t\t| " << CountH750a9OldMVA[0] << "\t\t| " << CountH750a9Old[0] << endl;
  infoFile << "Med:   | " << CountH750a9New[3] << "\t\t| " << CountH750a9NewMVA[1] << "\t\t| " << CountH750a9New[1] << "\t\t| " << CountH750a9OldMVA[1] << "\t\t| " << CountH750a9Old[1] << endl; 
  infoFile << "Tight: | " << CountH750a9New[3] << "\t\t| " << CountH750a9NewMVA[2] << "\t\t| " << CountH750a9New[2] << "\t\t| " << CountH750a9OldMVA[2] << "\t\t| " << CountH750a9Old[2] << endl;

  infoFile << "\nFraction of Total of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH750a9New[3]/CountH750a9New[4] << "\t| " << CountH750a9NewMVA[0]/CountH750a9NewMVA[4] << "\t| ";
  infoFile << CountH750a9New[0]/CountH750a9New[4] << "\t| " << CountH750a9OldMVA[0]/CountH750a9OldMVA[4] << "\t| " << CountH750a9Old[0]/CountH750a9Old[4] << endl;
  infoFile << "Med:   | " << CountH750a9New[3]/CountH750a9New[4] << "\t| " << CountH750a9NewMVA[1]/CountH750a9NewMVA[4] << "\t| " << CountH750a9New[1]/CountH750a9New[4]; 
  infoFile << "\t| " << CountH750a9OldMVA[1]/CountH750a9OldMVA[4] << "\t| ";
  infoFile << CountH750a9Old[1]/CountH750a9Old[4] << endl;
  infoFile << "Tight: | " << CountH750a9New[3]/CountH750a9New[4] << "\t| " << CountH750a9NewMVA[2]/CountH750a9NewMVA[4] << "\t| " ;
  infoFile << CountH750a9New[2]/CountH750a9New[4] << "\t| " << CountH750a9OldMVA[2]/CountH750a9OldMVA[4] << "\t| " << CountH750a9Old[2]/CountH750a9Old[4] << endl; 
  
  infoFile << "\nFraction of Events with a Removed Muon (a.k.a. A Cleaned Jet):" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH750a9New[3]/CountH750a9New[3] << "\t\t| " << CountH750a9NewMVA[0]/CountH750a9NewMVA[3] << "\t| ";
  infoFile << CountH750a9New[0]/CountH750a9New[3] << "\t| " << CountH750a9OldMVA[0]/CountH750a9OldMVA[3] << "\t| " << CountH750a9Old[0]/CountH750a9Old[3] << endl; 
  infoFile << "Med:   | " << CountH750a9New[3]/CountH750a9New[3] << "\t\t| " << CountH750a9NewMVA[1]/CountH750a9NewMVA[3] << "\t| ";
  infoFile << CountH750a9New[1]/CountH750a9New[3] << "\t| " << CountH750a9OldMVA[1]/CountH750a9OldMVA[3] << "\t| " << CountH750a9Old[1]/CountH750a9Old[3] << endl;
  infoFile << "Tight: | " << CountH750a9New[3]/CountH750a9New[3] << "\t\t| " << CountH750a9NewMVA[2]/CountH750a9NewMVA[3] << "\t| ";
  infoFile << CountH750a9New[2]/CountH750a9New[3] << "\t| " << CountH750a9OldMVA[2]/CountH750a9OldMVA[3] << "\t| " << CountH750a9Old[2]/CountH750a9Old[3] << endl; 


/////////////////////////////////////////////
// ALL SIG TO BACKGROUND PLOTS
////////////////////////////////////////////

  //////////////////////////
  // H125 a19 4 tau DM's
  //////////////////////////
  TH1F* OldH125a19ToBack_    = new TH1F("OldH125a19ToBack","", 8, -.5, 7.5);
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  OldH125a19ToBack_->SetBinContent(1, CutH125a19Old[1] / TMath::Sqrt(CutH125a19Old[1] + CutDYOld[1] + CutTTOld[1] + CutWJOld[1] + CutDYOld[10] + CutTTOld[10] + CutWJOld[10]) );
  OldH125a19ToBack_->SetBinContent(2, CutH125a19Old[2] / TMath::Sqrt(CutH125a19Old[2] + CutDYOld[2] + CutTTOld[2] + CutWJOld[2] + CutDYOld[11] + CutTTOld[11] + CutWJOld[11]) );
  OldH125a19ToBack_->SetBinContent(3, CutH125a19Old[3] / TMath::Sqrt(CutH125a19Old[3] + CutDYOld[3] + CutTTOld[3] + CutWJOld[3] + CutDYOld[12] + CutTTOld[12] + CutWJOld[12]) );
  OldH125a19ToBack_->SetBinContent(4, CutH125a19Old[4] / TMath::Sqrt(CutH125a19Old[4] + CutDYOld[4] + CutTTOld[4] + CutWJOld[4] + CutDYOld[13] + CutTTOld[13] + CutWJOld[13]) );
  OldH125a19ToBack_->SetBinContent(5, CutH125a19Old[5] / TMath::Sqrt(CutH125a19Old[5] + CutDYOld[5] + CutTTOld[5] + CutWJOld[5] + CutDYOld[14] + CutTTOld[14] + CutWJOld[14]) );
  OldH125a19ToBack_->SetBinContent(6, CutH125a19Old[6] / TMath::Sqrt(CutH125a19Old[6] + CutDYOld[6] + CutTTOld[6] + CutWJOld[6] + CutDYOld[15] + CutTTOld[15] + CutWJOld[15]) );
  OldH125a19ToBack_->SetBinContent(7, CutH125a19Old[7] / TMath::Sqrt(CutH125a19Old[7] + CutDYOld[7] + CutTTOld[7] + CutWJOld[7] + CutDYOld[16] + CutTTOld[16] + CutWJOld[16]) );
  OldH125a19ToBack_->SetBinContent(8, CutH125a19Old[8] / TMath::Sqrt(CutH125a19Old[8] + CutDYOld[8] + CutTTOld[8] + CutWJOld[8] + CutDYOld[17] + CutTTOld[17] + CutWJOld[17]) );
  OldH125a19ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* OldMVAH125a19ToBack_    = new TH1F("OldMVAH125a19ToBack","", 8, -.5, 7.5);
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  OldMVAH125a19ToBack_->SetBinContent(1,CutH125a19OldMVA[1]/TMath::Sqrt(CutH125a19OldMVA[1]+ CutDYOldMVA[1] + CutTTOldMVA[1] + CutWJOldMVA[1] + CutDYOldMVA[10] + CutTTOldMVA[10] + CutWJOldMVA[10]) );
  OldMVAH125a19ToBack_->SetBinContent(2,CutH125a19OldMVA[2]/TMath::Sqrt(CutH125a19OldMVA[2]+ CutDYOldMVA[2] + CutTTOldMVA[2] + CutWJOldMVA[2] + CutDYOldMVA[11] + CutTTOldMVA[11] + CutWJOldMVA[11]) );
  OldMVAH125a19ToBack_->SetBinContent(3,CutH125a19OldMVA[3]/TMath::Sqrt(CutH125a19OldMVA[3]+ CutDYOldMVA[3] + CutTTOldMVA[3] + CutWJOldMVA[3] + CutDYOldMVA[12] + CutTTOldMVA[12] + CutWJOldMVA[12]) );
  OldMVAH125a19ToBack_->SetBinContent(4,CutH125a19OldMVA[4]/TMath::Sqrt(CutH125a19OldMVA[4]+ CutDYOldMVA[4] + CutTTOldMVA[4] + CutWJOldMVA[4] + CutDYOldMVA[13] + CutTTOldMVA[13] + CutWJOldMVA[13]) );
  OldMVAH125a19ToBack_->SetBinContent(5,CutH125a19OldMVA[5]/TMath::Sqrt(CutH125a19OldMVA[5]+ CutDYOldMVA[5] + CutTTOldMVA[5] + CutWJOldMVA[5] + CutDYOldMVA[14] + CutTTOldMVA[14] + CutWJOldMVA[14]) );
  OldMVAH125a19ToBack_->SetBinContent(6,CutH125a19OldMVA[6]/TMath::Sqrt(CutH125a19OldMVA[6]+ CutDYOldMVA[6] + CutTTOldMVA[6] + CutWJOldMVA[6] + CutDYOldMVA[15] + CutTTOldMVA[15] + CutWJOldMVA[15]) );
  OldMVAH125a19ToBack_->SetBinContent(7,CutH125a19OldMVA[7]/TMath::Sqrt(CutH125a19OldMVA[7]+ CutDYOldMVA[7] + CutTTOldMVA[7] + CutWJOldMVA[7] + CutDYOldMVA[16] + CutTTOldMVA[16] + CutWJOldMVA[16]) );
  OldMVAH125a19ToBack_->SetBinContent(8,CutH125a19OldMVA[8]/TMath::Sqrt(CutH125a19OldMVA[8]+ CutDYOldMVA[8] + CutTTOldMVA[8] + CutWJOldMVA[8] + CutDYOldMVA[17] + CutTTOldMVA[17] + CutWJOldMVA[17]) );
  OldMVAH125a19ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewH125a19ToBack_    = new TH1F("NewH125a19ToBack","", 8, -.5, 7.5); 
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  NewH125a19ToBack_->SetBinContent(1,CutH125a19New[1]/TMath::Sqrt(CutH125a19New[1] + CutDYNew[1] + CutTTNew[1] + CutWJNew[1] + CutDYNew[10] + CutTTNew[10] + CutWJNew[10]) );
  NewH125a19ToBack_->SetBinContent(2,CutH125a19New[2]/TMath::Sqrt(CutH125a19New[2] + CutDYNew[2] + CutTTNew[2] + CutWJNew[2] + CutDYNew[11] + CutTTNew[11] + CutWJNew[11]) );
  NewH125a19ToBack_->SetBinContent(3,CutH125a19New[3]/TMath::Sqrt(CutH125a19New[3] + CutDYNew[3] + CutTTNew[3] + CutWJNew[3] + CutDYNew[12] + CutTTNew[12] + CutWJNew[12]) );
  NewH125a19ToBack_->SetBinContent(4,CutH125a19New[4]/TMath::Sqrt(CutH125a19New[4] + CutDYNew[4] + CutTTNew[4] + CutWJNew[4] + CutDYNew[13] + CutTTNew[13] + CutWJNew[13]) );
  NewH125a19ToBack_->SetBinContent(5,CutH125a19New[5]/TMath::Sqrt(CutH125a19New[5] + CutDYNew[5] + CutTTNew[5] + CutWJNew[5] + CutDYNew[14] + CutTTNew[14] + CutWJNew[14]) );
  NewH125a19ToBack_->SetBinContent(6,CutH125a19New[6]/TMath::Sqrt(CutH125a19New[6] + CutDYNew[6] + CutTTNew[6] + CutWJNew[6] + CutDYNew[15] + CutTTNew[15] + CutWJNew[15]) );
  NewH125a19ToBack_->SetBinContent(7,CutH125a19New[7]/TMath::Sqrt(CutH125a19New[7] + CutDYNew[7] + CutTTNew[7] + CutWJNew[7] + CutDYNew[16] + CutTTNew[16] + CutWJNew[16]) );
  NewH125a19ToBack_->SetBinContent(8,CutH125a19New[8]/TMath::Sqrt(CutH125a19New[8] + CutDYNew[8] + CutTTNew[8] + CutWJNew[8] + CutDYNew[17] + CutTTNew[17] + CutWJNew[17]) );
  NewH125a19ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewMVAH125a19ToBack_ = new TH1F("NewMVAH125a19ToBack","", 8, -.5, 7.5); 
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  NewMVAH125a19ToBack_->SetBinContent(1,CutH125a19NewMVA[1]/TMath::Sqrt(CutH125a19NewMVA[1]+ CutDYNewMVA[1] + CutTTNewMVA[1] + CutWJNewMVA[1] + CutDYNewMVA[10] + CutTTNewMVA[10] + CutWJNewMVA[10]) );
  NewMVAH125a19ToBack_->SetBinContent(2,CutH125a19NewMVA[2]/TMath::Sqrt(CutH125a19NewMVA[2]+ CutDYNewMVA[2] + CutTTNewMVA[2] + CutWJNewMVA[2] + CutDYNewMVA[11] + CutTTNewMVA[11] + CutWJNewMVA[11]) );
  NewMVAH125a19ToBack_->SetBinContent(3,CutH125a19NewMVA[3]/TMath::Sqrt(CutH125a19NewMVA[3]+ CutDYNewMVA[3] + CutTTNewMVA[3] + CutWJNewMVA[3] + CutDYNewMVA[12] + CutTTNewMVA[12] + CutWJNewMVA[12]) );
  NewMVAH125a19ToBack_->SetBinContent(4,CutH125a19NewMVA[4]/TMath::Sqrt(CutH125a19NewMVA[4]+ CutDYNewMVA[4] + CutTTNewMVA[4] + CutWJNewMVA[4] + CutDYNewMVA[13] + CutTTNewMVA[13] + CutWJNewMVA[13]) );
  NewMVAH125a19ToBack_->SetBinContent(5,CutH125a19NewMVA[5]/TMath::Sqrt(CutH125a19NewMVA[5]+ CutDYNewMVA[5] + CutTTNewMVA[5] + CutWJNewMVA[5] + CutDYNewMVA[14] + CutTTNewMVA[14] + CutWJNewMVA[14]) );
  NewMVAH125a19ToBack_->SetBinContent(6,CutH125a19NewMVA[6]/TMath::Sqrt(CutH125a19NewMVA[6]+ CutDYNewMVA[6] + CutTTNewMVA[6] + CutWJNewMVA[6] + CutDYNewMVA[15] + CutTTNewMVA[15] + CutWJNewMVA[15]) );
  NewMVAH125a19ToBack_->SetBinContent(7,CutH125a19NewMVA[7]/TMath::Sqrt(CutH125a19NewMVA[7]+ CutDYNewMVA[7] + CutTTNewMVA[7] + CutWJNewMVA[7] + CutDYNewMVA[16] + CutTTNewMVA[16] + CutWJNewMVA[16]) );
  NewMVAH125a19ToBack_->SetBinContent(8,CutH125a19NewMVA[8]/TMath::Sqrt(CutH125a19NewMVA[8]+ CutDYNewMVA[8] + CutTTNewMVA[8] + CutWJNewMVA[8] + CutDYNewMVA[17] + CutTTNewMVA[17] + CutWJNewMVA[17]) );
  NewMVAH125a19ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  //////////////////////////
  // H125 a9 4 tau DM's
  //////////////////////////
  TH1F* OldH125a9ToBack_    = new TH1F("OldH125a9ToBack","", 8, -.5, 7.5);
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  OldH125a9ToBack_->SetBinContent(1, CutH125a9Old[1] / TMath::Sqrt(CutH125a9Old[1] + CutDYOld[1] + CutTTOld[1] + CutWJOld[1] + CutDYOld[10] + CutTTOld[10] + CutWJOld[10]) );
  OldH125a9ToBack_->SetBinContent(2, CutH125a9Old[2] / TMath::Sqrt(CutH125a9Old[2] + CutDYOld[2] + CutTTOld[2] + CutWJOld[2] + CutDYOld[11] + CutTTOld[11] + CutWJOld[11]) );
  OldH125a9ToBack_->SetBinContent(3, CutH125a9Old[3] / TMath::Sqrt(CutH125a9Old[3] + CutDYOld[3] + CutTTOld[3] + CutWJOld[3] + CutDYOld[12] + CutTTOld[12] + CutWJOld[12]) );
  OldH125a9ToBack_->SetBinContent(4, CutH125a9Old[4] / TMath::Sqrt(CutH125a9Old[4] + CutDYOld[4] + CutTTOld[4] + CutWJOld[4] + CutDYOld[13] + CutTTOld[13] + CutWJOld[13]) );
  OldH125a9ToBack_->SetBinContent(5, CutH125a9Old[5] / TMath::Sqrt(CutH125a9Old[5] + CutDYOld[5] + CutTTOld[5] + CutWJOld[5] + CutDYOld[14] + CutTTOld[14] + CutWJOld[14]) );
  OldH125a9ToBack_->SetBinContent(6, CutH125a9Old[6] / TMath::Sqrt(CutH125a9Old[6] + CutDYOld[6] + CutTTOld[6] + CutWJOld[6] + CutDYOld[15] + CutTTOld[15] + CutWJOld[15]) );
  OldH125a9ToBack_->SetBinContent(7, CutH125a9Old[7] / TMath::Sqrt(CutH125a9Old[7] + CutDYOld[7] + CutTTOld[7] + CutWJOld[7] + CutDYOld[16] + CutTTOld[16] + CutWJOld[16]) );
  OldH125a9ToBack_->SetBinContent(8, CutH125a9Old[8] / TMath::Sqrt(CutH125a9Old[8] + CutDYOld[8] + CutTTOld[8] + CutWJOld[8] + CutDYOld[17] + CutTTOld[17] + CutWJOld[17]) );
  OldH125a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* OldMVAH125a9ToBack_    = new TH1F("OldMVAH125a9ToBack","", 8, -.5, 7.5); 
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  OldMVAH125a9ToBack_->SetBinContent(1,CutH125a9OldMVA[1]/TMath::Sqrt(CutH125a9OldMVA[1] + CutDYOldMVA[1] + CutTTOldMVA[1] + CutWJOldMVA[1] + CutDYOldMVA[10] + CutTTOldMVA[10] + CutWJOldMVA[10]) );
  OldMVAH125a9ToBack_->SetBinContent(2,CutH125a9OldMVA[2]/TMath::Sqrt(CutH125a9OldMVA[2] + CutDYOldMVA[2] + CutTTOldMVA[2] + CutWJOldMVA[2] + CutDYOldMVA[11] + CutTTOldMVA[11] + CutWJOldMVA[11]) );
  OldMVAH125a9ToBack_->SetBinContent(3,CutH125a9OldMVA[3]/TMath::Sqrt(CutH125a9OldMVA[3] + CutDYOldMVA[3] + CutTTOldMVA[3] + CutWJOldMVA[3] + CutDYOldMVA[12] + CutTTOldMVA[12] + CutWJOldMVA[12]) );
  OldMVAH125a9ToBack_->SetBinContent(4,CutH125a9OldMVA[4]/TMath::Sqrt(CutH125a9OldMVA[4] + CutDYOldMVA[4] + CutTTOldMVA[4] + CutWJOldMVA[4] + CutDYOldMVA[13] + CutTTOldMVA[13] + CutWJOldMVA[13]) );
  OldMVAH125a9ToBack_->SetBinContent(5,CutH125a9OldMVA[5]/TMath::Sqrt(CutH125a9OldMVA[5] + CutDYOldMVA[5] + CutTTOldMVA[5] + CutWJOldMVA[5] + CutDYOldMVA[14] + CutTTOldMVA[14] + CutWJOldMVA[14]) );
  OldMVAH125a9ToBack_->SetBinContent(6,CutH125a9OldMVA[6]/TMath::Sqrt(CutH125a9OldMVA[6] + CutDYOldMVA[6] + CutTTOldMVA[6] + CutWJOldMVA[6] + CutDYOldMVA[15] + CutTTOldMVA[15] + CutWJOldMVA[15]) );
  OldMVAH125a9ToBack_->SetBinContent(7,CutH125a9OldMVA[7]/TMath::Sqrt(CutH125a9OldMVA[7] + CutDYOldMVA[7] + CutTTOldMVA[7] + CutWJOldMVA[7] + CutDYOldMVA[16] + CutTTOldMVA[16] + CutWJOldMVA[16]) );
  OldMVAH125a9ToBack_->SetBinContent(8,CutH125a9OldMVA[8]/TMath::Sqrt(CutH125a9OldMVA[8] + CutDYOldMVA[8] + CutTTOldMVA[8] + CutWJOldMVA[8] + CutDYOldMVA[17] + CutTTOldMVA[17] + CutWJOldMVA[17]) );
  OldMVAH125a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewH125a9ToBack_    = new TH1F("NewH125a9ToBack","", 8, -.5, 7.5);
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  NewH125a9ToBack_->SetBinContent(1, CutH125a9New[1] / TMath::Sqrt(CutH125a9New[1] + CutDYNew[1] + CutTTNew[1] + CutWJNew[1] + CutDYNew[10] + CutTTNew[10] + CutWJNew[10]) ); 
  NewH125a9ToBack_->SetBinContent(2, CutH125a9New[2] / TMath::Sqrt(CutH125a9New[2] + CutDYNew[2] + CutTTNew[2] + CutWJNew[2] + CutDYNew[11] + CutTTNew[11] + CutWJNew[11]) ); 
  NewH125a9ToBack_->SetBinContent(3, CutH125a9New[3] / TMath::Sqrt(CutH125a9New[3] + CutDYNew[3] + CutTTNew[3] + CutWJNew[3] + CutDYNew[12] + CutTTNew[12] + CutWJNew[12]) ); 
  NewH125a9ToBack_->SetBinContent(4, CutH125a9New[4] / TMath::Sqrt(CutH125a9New[4] + CutDYNew[4] + CutTTNew[4] + CutWJNew[4] + CutDYNew[13] + CutTTNew[13] + CutWJNew[13]) ); 
  NewH125a9ToBack_->SetBinContent(5, CutH125a9New[5] / TMath::Sqrt(CutH125a9New[5] + CutDYNew[5] + CutTTNew[5] + CutWJNew[5] + CutDYNew[14] + CutTTNew[14] + CutWJNew[14]) ); 
  NewH125a9ToBack_->SetBinContent(6, CutH125a9New[6] / TMath::Sqrt(CutH125a9New[6] + CutDYNew[6] + CutTTNew[6] + CutWJNew[6] + CutDYNew[15] + CutTTNew[15] + CutWJNew[15]) ); 
  NewH125a9ToBack_->SetBinContent(7, CutH125a9New[7] / TMath::Sqrt(CutH125a9New[7] + CutDYNew[7] + CutTTNew[7] + CutWJNew[7] + CutDYNew[16] + CutTTNew[16] + CutWJNew[16]) ); 
  NewH125a9ToBack_->SetBinContent(8, CutH125a9New[8] / TMath::Sqrt(CutH125a9New[8] + CutDYNew[8] + CutTTNew[8] + CutWJNew[8] + CutDYNew[17] + CutTTNew[17] + CutWJNew[17]) ); 
  NewH125a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");
  
  TH1F* NewMVAH125a9ToBack_    = new TH1F("NewMVAH125a9ToBack","", 8, -.5, 7.5); 
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  NewMVAH125a9ToBack_->SetBinContent(1,CutH125a9NewMVA[1]/TMath::Sqrt(CutH125a9NewMVA[1] + CutDYNewMVA[1] + CutTTNewMVA[1] + CutWJNewMVA[1] + CutDYNewMVA[10] + CutTTNewMVA[10] + CutWJNewMVA[10]) ); 
  NewMVAH125a9ToBack_->SetBinContent(2,CutH125a9NewMVA[2]/TMath::Sqrt(CutH125a9NewMVA[2] + CutDYNewMVA[2] + CutTTNewMVA[2] + CutWJNewMVA[2] + CutDYNewMVA[11] + CutTTNewMVA[11] + CutWJNewMVA[11]) ); 
  NewMVAH125a9ToBack_->SetBinContent(3,CutH125a9NewMVA[3]/TMath::Sqrt(CutH125a9NewMVA[3] + CutDYNewMVA[3] + CutTTNewMVA[3] + CutWJNewMVA[3] + CutDYNewMVA[12] + CutTTNewMVA[12] + CutWJNewMVA[12]) ); 
  NewMVAH125a9ToBack_->SetBinContent(4,CutH125a9NewMVA[4]/TMath::Sqrt(CutH125a9NewMVA[4] + CutDYNewMVA[4] + CutTTNewMVA[4] + CutWJNewMVA[4] + CutDYNewMVA[13] + CutTTNewMVA[13] + CutWJNewMVA[13]) ); 
  NewMVAH125a9ToBack_->SetBinContent(5,CutH125a9NewMVA[5]/TMath::Sqrt(CutH125a9NewMVA[5] + CutDYNewMVA[5] + CutTTNewMVA[5] + CutWJNewMVA[5] + CutDYNewMVA[14] + CutTTNewMVA[14] + CutWJNewMVA[14]) ); 
  NewMVAH125a9ToBack_->SetBinContent(6,CutH125a9NewMVA[6]/TMath::Sqrt(CutH125a9NewMVA[6] + CutDYNewMVA[6] + CutTTNewMVA[6] + CutWJNewMVA[6] + CutDYNewMVA[15] + CutTTNewMVA[15] + CutWJNewMVA[15]) ); 
  NewMVAH125a9ToBack_->SetBinContent(7,CutH125a9NewMVA[7]/TMath::Sqrt(CutH125a9NewMVA[7] + CutDYNewMVA[7] + CutTTNewMVA[7] + CutWJNewMVA[7] + CutDYNewMVA[16] + CutTTNewMVA[16] + CutWJNewMVA[16]) ); 
  NewMVAH125a9ToBack_->SetBinContent(8,CutH125a9NewMVA[8]/TMath::Sqrt(CutH125a9NewMVA[8] + CutDYNewMVA[8] + CutTTNewMVA[8] + CutWJNewMVA[8] + CutDYNewMVA[17] + CutTTNewMVA[17] + CutWJNewMVA[17]) ); 
  NewMVAH125a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  //////////////////////////
  // H125 a5 4 tau DM's
  //////////////////////////
  TH1F* OldH125a5ToBack_    = new TH1F("OldH125a5ToBack","", 8, -.5, 7.5);
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  OldH125a5ToBack_->SetBinContent(1, CutH125a5Old[1] / TMath::Sqrt(CutH125a5Old[1] + CutDYOld[1] + CutTTOld[1] + CutWJOld[1] + CutDYOld[10] + CutTTOld[10] + CutWJOld[10]) );
  OldH125a5ToBack_->SetBinContent(2, CutH125a5Old[2] / TMath::Sqrt(CutH125a5Old[2] + CutDYOld[2] + CutTTOld[2] + CutWJOld[2] + CutDYOld[11] + CutTTOld[11] + CutWJOld[11]) );
  OldH125a5ToBack_->SetBinContent(3, CutH125a5Old[3] / TMath::Sqrt(CutH125a5Old[3] + CutDYOld[3] + CutTTOld[3] + CutWJOld[3] + CutDYOld[12] + CutTTOld[12] + CutWJOld[12]) );
  OldH125a5ToBack_->SetBinContent(4, CutH125a5Old[4] / TMath::Sqrt(CutH125a5Old[4] + CutDYOld[4] + CutTTOld[4] + CutWJOld[4] + CutDYOld[13] + CutTTOld[13] + CutWJOld[13]) );
  OldH125a5ToBack_->SetBinContent(5, CutH125a5Old[5] / TMath::Sqrt(CutH125a5Old[5] + CutDYOld[5] + CutTTOld[5] + CutWJOld[5] + CutDYOld[14] + CutTTOld[14] + CutWJOld[14]) );
  OldH125a5ToBack_->SetBinContent(6, CutH125a5Old[6] / TMath::Sqrt(CutH125a5Old[6] + CutDYOld[6] + CutTTOld[6] + CutWJOld[6] + CutDYOld[15] + CutTTOld[15] + CutWJOld[15]) );
  OldH125a5ToBack_->SetBinContent(7, CutH125a5Old[7] / TMath::Sqrt(CutH125a5Old[7] + CutDYOld[7] + CutTTOld[7] + CutWJOld[7] + CutDYOld[16] + CutTTOld[16] + CutWJOld[16]) );
  OldH125a5ToBack_->SetBinContent(8, CutH125a5Old[8] / TMath::Sqrt(CutH125a5Old[8] + CutDYOld[8] + CutTTOld[8] + CutWJOld[8] + CutDYOld[17] + CutTTOld[17] + CutWJOld[17]) );
  OldH125a5ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* OldMVAH125a5ToBack_    = new TH1F("OldMVAH125a5ToBack","", 8, -.5, 7.5);
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  OldMVAH125a5ToBack_->SetBinContent(1,CutH125a5OldMVA[1]/TMath::Sqrt(CutH125a5OldMVA[1] + CutDYOldMVA[1] + CutTTOldMVA[1] + CutWJOldMVA[1] + CutDYOldMVA[10] + CutTTOldMVA[10] + CutWJOldMVA[10]) ); 
  OldMVAH125a5ToBack_->SetBinContent(2,CutH125a5OldMVA[2]/TMath::Sqrt(CutH125a5OldMVA[2] + CutDYOldMVA[2] + CutTTOldMVA[2] + CutWJOldMVA[2] + CutDYOldMVA[11] + CutTTOldMVA[11] + CutWJOldMVA[11]) ); 
  OldMVAH125a5ToBack_->SetBinContent(3,CutH125a5OldMVA[3]/TMath::Sqrt(CutH125a5OldMVA[3] + CutDYOldMVA[3] + CutTTOldMVA[3] + CutWJOldMVA[3] + CutDYOldMVA[12] + CutTTOldMVA[12] + CutWJOldMVA[12]) ); 
  OldMVAH125a5ToBack_->SetBinContent(4,CutH125a5OldMVA[4]/TMath::Sqrt(CutH125a5OldMVA[4] + CutDYOldMVA[4] + CutTTOldMVA[4] + CutWJOldMVA[4] + CutDYOldMVA[13] + CutTTOldMVA[13] + CutWJOldMVA[13]) ); 
  OldMVAH125a5ToBack_->SetBinContent(5,CutH125a5OldMVA[5]/TMath::Sqrt(CutH125a5OldMVA[5] + CutDYOldMVA[5] + CutTTOldMVA[5] + CutWJOldMVA[5] + CutDYOldMVA[14] + CutTTOldMVA[14] + CutWJOldMVA[14]) ); 
  OldMVAH125a5ToBack_->SetBinContent(6,CutH125a5OldMVA[6]/TMath::Sqrt(CutH125a5OldMVA[6] + CutDYOldMVA[6] + CutTTOldMVA[6] + CutWJOldMVA[6] + CutDYOldMVA[15] + CutTTOldMVA[15] + CutWJOldMVA[15]) ); 
  OldMVAH125a5ToBack_->SetBinContent(7,CutH125a5OldMVA[7]/TMath::Sqrt(CutH125a5OldMVA[7] + CutDYOldMVA[7] + CutTTOldMVA[7] + CutWJOldMVA[7] + CutDYOldMVA[16] + CutTTOldMVA[16] + CutWJOldMVA[16]) ); 
  OldMVAH125a5ToBack_->SetBinContent(8,CutH125a5OldMVA[8]/TMath::Sqrt(CutH125a5OldMVA[8] + CutDYOldMVA[8] + CutTTOldMVA[8] + CutWJOldMVA[8] + CutDYOldMVA[17] + CutTTOldMVA[17] + CutWJOldMVA[17]) ); 
  OldMVAH125a5ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewH125a5ToBack_    = new TH1F("NewH125a5ToBack","", 8, -.5, 7.5);
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  NewH125a5ToBack_->SetBinContent(1, CutH125a5New[1] / TMath::Sqrt(CutH125a5New[1] + CutDYNew[1] + CutTTNew[1] + CutWJNew[1] + CutDYNew[10] + CutTTNew[10] + CutWJNew[10]) );
  NewH125a5ToBack_->SetBinContent(2, CutH125a5New[2] / TMath::Sqrt(CutH125a5New[2] + CutDYNew[2] + CutTTNew[2] + CutWJNew[2] + CutDYNew[11] + CutTTNew[11] + CutWJNew[11]) );
  NewH125a5ToBack_->SetBinContent(3, CutH125a5New[3] / TMath::Sqrt(CutH125a5New[3] + CutDYNew[3] + CutTTNew[3] + CutWJNew[3] + CutDYNew[12] + CutTTNew[12] + CutWJNew[12]) );
  NewH125a5ToBack_->SetBinContent(4, CutH125a5New[4] / TMath::Sqrt(CutH125a5New[4] + CutDYNew[4] + CutTTNew[4] + CutWJNew[4] + CutDYNew[13] + CutTTNew[13] + CutWJNew[13]) );
  NewH125a5ToBack_->SetBinContent(5, CutH125a5New[5] / TMath::Sqrt(CutH125a5New[5] + CutDYNew[5] + CutTTNew[5] + CutWJNew[5] + CutDYNew[14] + CutTTNew[14] + CutWJNew[14]) );
  NewH125a5ToBack_->SetBinContent(6, CutH125a5New[6] / TMath::Sqrt(CutH125a5New[6] + CutDYNew[6] + CutTTNew[6] + CutWJNew[6] + CutDYNew[15] + CutTTNew[15] + CutWJNew[15]) );
  NewH125a5ToBack_->SetBinContent(7, CutH125a5New[7] / TMath::Sqrt(CutH125a5New[7] + CutDYNew[7] + CutTTNew[7] + CutWJNew[7] + CutDYNew[16] + CutTTNew[16] + CutWJNew[16]) );
  NewH125a5ToBack_->SetBinContent(8, CutH125a5New[8] / TMath::Sqrt(CutH125a5New[8] + CutDYNew[8] + CutTTNew[8] + CutWJNew[8] + CutDYNew[17] + CutTTNew[17] + CutWJNew[17]) );
  NewH125a5ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewMVAH125a5ToBack_    = new TH1F("NewMVAH125a5ToBack","", 8, -.5, 7.5);
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  NewMVAH125a5ToBack_->SetBinContent(1,CutH125a5NewMVA[1]/TMath::Sqrt(CutH125a5NewMVA[1] + CutDYNewMVA[1] + CutTTNewMVA[1] + CutWJNewMVA[1] + CutDYNewMVA[10] + CutTTNewMVA[10] + CutWJNewMVA[10]) );
  NewMVAH125a5ToBack_->SetBinContent(2,CutH125a5NewMVA[2]/TMath::Sqrt(CutH125a5NewMVA[2] + CutDYNewMVA[2] + CutTTNewMVA[2] + CutWJNewMVA[2] + CutDYNewMVA[11] + CutTTNewMVA[11] + CutWJNewMVA[11]) );
  NewMVAH125a5ToBack_->SetBinContent(3,CutH125a5NewMVA[3]/TMath::Sqrt(CutH125a5NewMVA[3] + CutDYNewMVA[3] + CutTTNewMVA[3] + CutWJNewMVA[3] + CutDYNewMVA[12] + CutTTNewMVA[12] + CutWJNewMVA[12]) );
  NewMVAH125a5ToBack_->SetBinContent(4,CutH125a5NewMVA[4]/TMath::Sqrt(CutH125a5NewMVA[4] + CutDYNewMVA[4] + CutTTNewMVA[4] + CutWJNewMVA[4] + CutDYNewMVA[13] + CutTTNewMVA[13] + CutWJNewMVA[13]) );
  NewMVAH125a5ToBack_->SetBinContent(5,CutH125a5NewMVA[5]/TMath::Sqrt(CutH125a5NewMVA[5] + CutDYNewMVA[5] + CutTTNewMVA[5] + CutWJNewMVA[5] + CutDYNewMVA[14] + CutTTNewMVA[14] + CutWJNewMVA[14]) );
  NewMVAH125a5ToBack_->SetBinContent(6,CutH125a5NewMVA[6]/TMath::Sqrt(CutH125a5NewMVA[6] + CutDYNewMVA[6] + CutTTNewMVA[6] + CutWJNewMVA[6] + CutDYNewMVA[15] + CutTTNewMVA[15] + CutWJNewMVA[15]) );
  NewMVAH125a5ToBack_->SetBinContent(7,CutH125a5NewMVA[7]/TMath::Sqrt(CutH125a5NewMVA[7] + CutDYNewMVA[7] + CutTTNewMVA[7] + CutWJNewMVA[7] + CutDYNewMVA[16] + CutTTNewMVA[16] + CutWJNewMVA[16]) );
  NewMVAH125a5ToBack_->SetBinContent(8,CutH125a5NewMVA[8]/TMath::Sqrt(CutH125a5NewMVA[8] + CutDYNewMVA[8] + CutTTNewMVA[8] + CutWJNewMVA[8] + CutDYNewMVA[17] + CutTTNewMVA[17] + CutWJNewMVA[17]) );
  NewMVAH125a5ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  //////////////////////////
  // H750 a9 4 tau DM's
  //////////////////////////
  TH1F* OldH750a9ToBack_    = new TH1F("OldH750a9ToBack","", 8, -.5, 7.5);
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  OldH750a9ToBack_->SetBinContent(1, CutH750a9Old[1] / TMath::Sqrt(CutH750a9Old[1] + CutDYOld[1] + CutTTOld[1] + CutWJOld[1] + CutDYOld[10] + CutTTOld[10] + CutWJOld[10]) );
  OldH750a9ToBack_->SetBinContent(2, CutH750a9Old[2] / TMath::Sqrt(CutH750a9Old[2] + CutDYOld[2] + CutTTOld[2] + CutWJOld[2] + CutDYOld[11] + CutTTOld[11] + CutWJOld[11]) );
  OldH750a9ToBack_->SetBinContent(3, CutH750a9Old[3] / TMath::Sqrt(CutH750a9Old[3] + CutDYOld[3] + CutTTOld[3] + CutWJOld[3] + CutDYOld[12] + CutTTOld[12] + CutWJOld[12]) );
  OldH750a9ToBack_->SetBinContent(4, CutH750a9Old[4] / TMath::Sqrt(CutH750a9Old[4] + CutDYOld[4] + CutTTOld[4] + CutWJOld[4] + CutDYOld[13] + CutTTOld[13] + CutWJOld[13]) );
  OldH750a9ToBack_->SetBinContent(5, CutH750a9Old[5] / TMath::Sqrt(CutH750a9Old[5] + CutDYOld[5] + CutTTOld[5] + CutWJOld[5] + CutDYOld[14] + CutTTOld[14] + CutWJOld[14]) );
  OldH750a9ToBack_->SetBinContent(6, CutH750a9Old[6] / TMath::Sqrt(CutH750a9Old[6] + CutDYOld[6] + CutTTOld[6] + CutWJOld[6] + CutDYOld[15] + CutTTOld[15] + CutWJOld[15]) );
  OldH750a9ToBack_->SetBinContent(7, CutH750a9Old[7] / TMath::Sqrt(CutH750a9Old[7] + CutDYOld[7] + CutTTOld[7] + CutWJOld[7] + CutDYOld[16] + CutTTOld[16] + CutWJOld[16]) );
  OldH750a9ToBack_->SetBinContent(8, CutH750a9Old[8] / TMath::Sqrt(CutH750a9Old[8] + CutDYOld[8] + CutTTOld[8] + CutWJOld[8] + CutDYOld[17] + CutTTOld[17] + CutWJOld[17]) );
  OldH750a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* OldMVAH750a9ToBack_    = new TH1F("OldMVAH750a9ToBack","", 8, -.5, 7.5);
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  OldMVAH750a9ToBack_->SetBinContent(1,CutH750a9OldMVA[1]/TMath::Sqrt(CutH750a9OldMVA[1] + CutDYOldMVA[1] + CutTTOldMVA[1] + CutWJOldMVA[1] + CutDYOldMVA[10] + CutTTOldMVA[10] + CutWJOldMVA[10]) ); 
  OldMVAH750a9ToBack_->SetBinContent(2,CutH750a9OldMVA[2]/TMath::Sqrt(CutH750a9OldMVA[2] + CutDYOldMVA[2] + CutTTOldMVA[2] + CutWJOldMVA[2] + CutDYOldMVA[11] + CutTTOldMVA[11] + CutWJOldMVA[11]) ); 
  OldMVAH750a9ToBack_->SetBinContent(3,CutH750a9OldMVA[3]/TMath::Sqrt(CutH750a9OldMVA[3] + CutDYOldMVA[3] + CutTTOldMVA[3] + CutWJOldMVA[3] + CutDYOldMVA[12] + CutTTOldMVA[12] + CutWJOldMVA[12]) ); 
  OldMVAH750a9ToBack_->SetBinContent(4,CutH750a9OldMVA[4]/TMath::Sqrt(CutH750a9OldMVA[4] + CutDYOldMVA[4] + CutTTOldMVA[4] + CutWJOldMVA[4] + CutDYOldMVA[13] + CutTTOldMVA[13] + CutWJOldMVA[13]) ); 
  OldMVAH750a9ToBack_->SetBinContent(5,CutH750a9OldMVA[5]/TMath::Sqrt(CutH750a9OldMVA[5] + CutDYOldMVA[5] + CutTTOldMVA[5] + CutWJOldMVA[5] + CutDYOldMVA[14] + CutTTOldMVA[14] + CutWJOldMVA[14]) ); 
  OldMVAH750a9ToBack_->SetBinContent(6,CutH750a9OldMVA[6]/TMath::Sqrt(CutH750a9OldMVA[6] + CutDYOldMVA[6] + CutTTOldMVA[6] + CutWJOldMVA[6] + CutDYOldMVA[15] + CutTTOldMVA[15] + CutWJOldMVA[15]) ); 
  OldMVAH750a9ToBack_->SetBinContent(7,CutH750a9OldMVA[7]/TMath::Sqrt(CutH750a9OldMVA[7] + CutDYOldMVA[7] + CutTTOldMVA[7] + CutWJOldMVA[7] + CutDYOldMVA[16] + CutTTOldMVA[16] + CutWJOldMVA[16]) ); 
  OldMVAH750a9ToBack_->SetBinContent(8,CutH750a9OldMVA[8]/TMath::Sqrt(CutH750a9OldMVA[8] + CutDYOldMVA[8] + CutTTOldMVA[8] + CutWJOldMVA[8] + CutDYOldMVA[17] + CutTTOldMVA[17] + CutWJOldMVA[17]) ); 
  OldMVAH750a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewH750a9ToBack_    = new TH1F("NewH750a9ToBack","", 8, -.5, 7.5);
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  NewH750a9ToBack_->SetBinContent(1, CutH750a9New[1] / TMath::Sqrt(CutH750a9New[1] + CutDYNew[1] + CutTTNew[1] + CutWJNew[1] + CutDYNew[10] + CutTTNew[10] + CutWJNew[10]) );
  NewH750a9ToBack_->SetBinContent(2, CutH750a9New[2] / TMath::Sqrt(CutH750a9New[2] + CutDYNew[2] + CutTTNew[2] + CutWJNew[2] + CutDYNew[11] + CutTTNew[11] + CutWJNew[11]) );
  NewH750a9ToBack_->SetBinContent(3, CutH750a9New[3] / TMath::Sqrt(CutH750a9New[3] + CutDYNew[3] + CutTTNew[3] + CutWJNew[3] + CutDYNew[12] + CutTTNew[12] + CutWJNew[12]) );
  NewH750a9ToBack_->SetBinContent(4, CutH750a9New[4] / TMath::Sqrt(CutH750a9New[4] + CutDYNew[4] + CutTTNew[4] + CutWJNew[4] + CutDYNew[13] + CutTTNew[13] + CutWJNew[13]) );
  NewH750a9ToBack_->SetBinContent(5, CutH750a9New[5] / TMath::Sqrt(CutH750a9New[5] + CutDYNew[5] + CutTTNew[5] + CutWJNew[5] + CutDYNew[14] + CutTTNew[14] + CutWJNew[14]) );
  NewH750a9ToBack_->SetBinContent(6, CutH750a9New[6] / TMath::Sqrt(CutH750a9New[6] + CutDYNew[6] + CutTTNew[6] + CutWJNew[6] + CutDYNew[15] + CutTTNew[15] + CutWJNew[15]) );
  NewH750a9ToBack_->SetBinContent(7, CutH750a9New[7] / TMath::Sqrt(CutH750a9New[7] + CutDYNew[7] + CutTTNew[7] + CutWJNew[7] + CutDYNew[16] + CutTTNew[16] + CutWJNew[16]) );
  NewH750a9ToBack_->SetBinContent(8, CutH750a9New[8] / TMath::Sqrt(CutH750a9New[8] + CutDYNew[8] + CutTTNew[8] + CutWJNew[8] + CutDYNew[17] + CutTTNew[17] + CutWJNew[17]) );
  NewH750a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewMVAH750a9ToBack_    = new TH1F("NewMVAH750a9ToBack","", 8, -.5, 7.5);
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
  NewMVAH750a9ToBack_->SetBinContent(1,CutH750a9NewMVA[1]/TMath::Sqrt(CutH750a9NewMVA[1] + CutDYNewMVA[1] + CutTTNewMVA[1] + CutWJNewMVA[1] + CutDYNewMVA[10] + CutTTNewMVA[10] + CutWJNewMVA[10]) );
  NewMVAH750a9ToBack_->SetBinContent(2,CutH750a9NewMVA[2]/TMath::Sqrt(CutH750a9NewMVA[2] + CutDYNewMVA[2] + CutTTNewMVA[2] + CutWJNewMVA[2] + CutDYNewMVA[11] + CutTTNewMVA[11] + CutWJNewMVA[11]) );
  NewMVAH750a9ToBack_->SetBinContent(3,CutH750a9NewMVA[3]/TMath::Sqrt(CutH750a9NewMVA[3] + CutDYNewMVA[3] + CutTTNewMVA[3] + CutWJNewMVA[3] + CutDYNewMVA[12] + CutTTNewMVA[12] + CutWJNewMVA[12]) );
  NewMVAH750a9ToBack_->SetBinContent(4,CutH750a9NewMVA[4]/TMath::Sqrt(CutH750a9NewMVA[4] + CutDYNewMVA[4] + CutTTNewMVA[4] + CutWJNewMVA[4] + CutDYNewMVA[13] + CutTTNewMVA[13] + CutWJNewMVA[13]) );
  NewMVAH750a9ToBack_->SetBinContent(5,CutH750a9NewMVA[5]/TMath::Sqrt(CutH750a9NewMVA[5] + CutDYNewMVA[5] + CutTTNewMVA[5] + CutWJNewMVA[5] + CutDYNewMVA[14] + CutTTNewMVA[14] + CutWJNewMVA[14]) );
  NewMVAH750a9ToBack_->SetBinContent(6,CutH750a9NewMVA[6]/TMath::Sqrt(CutH750a9NewMVA[6] + CutDYNewMVA[6] + CutTTNewMVA[6] + CutWJNewMVA[6] + CutDYNewMVA[15] + CutTTNewMVA[15] + CutWJNewMVA[15]) );
  NewMVAH750a9ToBack_->SetBinContent(7,CutH750a9NewMVA[7]/TMath::Sqrt(CutH750a9NewMVA[7] + CutDYNewMVA[7] + CutTTNewMVA[7] + CutWJNewMVA[7] + CutDYNewMVA[16] + CutTTNewMVA[16] + CutWJNewMVA[16]) );
  NewMVAH750a9ToBack_->SetBinContent(8,CutH750a9NewMVA[8]/TMath::Sqrt(CutH750a9NewMVA[8] + CutDYNewMVA[8] + CutTTNewMVA[8] + CutWJNewMVA[8] + CutDYNewMVA[17] + CutTTNewMVA[17] + CutWJNewMVA[17]) );
  NewMVAH750a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

/////////////////////////
// Writing output Plots
/////////////////////////
  outFile->cd();

  CanvasArray[0]->Write();
  CanvasArray[1]->Write();
  CanvasArray[2]->Write();
  CanvasArray[3]->Write();
  CanvasArray[4]->Write();

  CanvasArray[5]->Write();
  CanvasArray[6]->Write();
  CanvasArray[7]->Write();
  CanvasArray[8]->Write();
  CanvasArray[9]->Write();

  OldH125a19ToBack_->SetLineColor(kBlack);
  OldH125a9ToBack_->SetLineColor(kRed+1);
  OldH125a5ToBack_->SetLineColor(kBlue+1);
  OldH750a9ToBack_->SetLineColor(kGreen+1);
  OldMVAH125a19ToBack_->SetLineColor(kBlack);
  OldMVAH125a9ToBack_->SetLineColor(kRed+1);
  OldMVAH125a5ToBack_->SetLineColor(kBlue+1);
  OldMVAH750a9ToBack_->SetLineColor(kGreen+1);
  NewH125a19ToBack_->SetLineColor(kBlack);
  NewH125a9ToBack_->SetLineColor(kRed+1);
  NewH125a5ToBack_->SetLineColor(kBlue+1);
  NewH750a9ToBack_->SetLineColor(kGreen+1);
  NewMVAH125a19ToBack_->SetLineColor(kBlack);
  NewMVAH125a9ToBack_->SetLineColor(kRed+1);
  NewMVAH125a5ToBack_->SetLineColor(kBlue+1);
  NewMVAH750a9ToBack_->SetLineColor(kGreen+1);

  OldSigToBackCanvas.cd();
  OldH125a19ToBack_->Draw();
  OldH125a9ToBack_->Draw("SAME");
  OldH125a5ToBack_->Draw("SAME");
  OldH750a9ToBack_->Draw("SAME");  
  OldSigToBackCanvas.Write();

  OldMVASigToBackCanvas.cd();
  OldMVAH125a19ToBack_->Draw();
  OldMVAH125a9ToBack_->Draw("SAME");
  OldMVAH125a5ToBack_->Draw("SAME");
  OldMVAH750a9ToBack_->Draw("SAME");
  OldMVASigToBackCanvas.Write();

  NewSigToBackCanvas.cd();
  NewH125a19ToBack_->Draw();
  NewH125a9ToBack_->Draw("SAME");
  NewH125a5ToBack_->Draw("SAME");
  NewH750a9ToBack_->Draw("SAME");
  NewSigToBackCanvas.Write();

  NewMVASigToBackCanvas.cd();
  NewMVAH125a19ToBack_->Draw();
  NewMVAH125a9ToBack_->Draw("SAME");
  NewMVAH125a5ToBack_->Draw("SAME");
  NewMVAH750a9ToBack_->Draw("SAME");
  NewMVASigToBackCanvas.Write();

  outFile->Write();
  outFile->Close();

}//rootMacro_FakeRateInfo
void GetFormatAndDraw(TFile &infile, TFile *outFile, TLegend *leg, string legName, const Color_t color, TCanvas *CanvasArray, double scale, bool firstFile, int Cuts[19], int Counts[5], string labels[19] )
{

  ////////////////
  // Canvases
  ////////////////
  TCanvas *MatchedLooseIsoCJPtCanvas   = (TCanvas*)infile.Get("MatchedLooseIsoCJPt");
  TCanvas *MatchedMedIsoCJPtCanvas     = (TCanvas*)infile.Get("MatchedMedIsoCJPt");
  TCanvas *MatchedTightIsoCJPtCanvas   = (TCanvas*)infile.Get("MatchedTightIsoCJPt");
  TCanvas *MatchedCJPtCanvas   = (TCanvas*)infile.Get("MatchedCJPt");
  TCanvas *NEventsCanvas   = (TCanvas*)infile.Get("NEvents");
  TCanvas *NEventsCutsCanvas   = (TCanvas*)infile.Get("NEventsCuts");
  TCanvas *GenMatchTypeCanvas   = (TCanvas*)infile.Get("GenMatchType");
  TCanvas *GenMatchPDGIDCanvas   = (TCanvas*)infile.Get("GenMatchPDGID");
  TCanvas *MatchedTauMuPtLeptonCanvas   = (TCanvas*)infile.Get("MatchedTauMuPtLepton");
  TCanvas *MatchedTauHadPtLeptonCanvas   = (TCanvas*)infile.Get("MatchedTauHadPtLepton");
  TCanvas *MatchedTauHadEtaLeptonCanvas   = (TCanvas*)infile.Get("MatchedTauHadEtaLepton");
  TCanvas *MatchedHTLeptonCanvas   = (TCanvas*)infile.Get("MatchedHTLepton");
  TCanvas *MatchedBDiscCSVLeptonCanvas   = (TCanvas*)infile.Get("MatchedBDiscCSVLepton");
  TCanvas *MatchedTauMuPtJetCanvas   = (TCanvas*)infile.Get("MatchedTauMuPtJet");
  TCanvas *MatchedTauHadPtJetCanvas   = (TCanvas*)infile.Get("MatchedTauHadPtJet");
  TCanvas *MatchedTauHadEtaJetCanvas   = (TCanvas*)infile.Get("MatchedTauHadEtaJet");
  TCanvas *MatchedHTJetCanvas   = (TCanvas*)infile.Get("MatchedHTJet");
  TCanvas *MatchedBDiscCSVJetCanvas   = (TCanvas*)infile.Get("MatchedBDiscCSVJet");

  TCanvas *MassDiLepGENCanvas   = (TCanvas*)infile.Get("MassDiLepGEN");
  TCanvas *MassDiLepRECOCanvas   = (TCanvas*)infile.Get("MassDiLepRECO");
  TCanvas *Mu3LargestPtMatchCanvas   = (TCanvas*)infile.Get("Mu3LargestPtMatch");
  TCanvas *Mu3MatchCanvas   = (TCanvas*)infile.Get("Mu3Match");
  TCanvas *PtOverMassMu1Mu2Canvas   = (TCanvas*)infile.Get("PtOverMassMu1Mu2");
  TCanvas *PtMu1Mu2Canvas   = (TCanvas*)infile.Get("PtMu1Mu2");


cout << "Got Canvases" << endl;

  //////////////////////////////
  // Getting the  Histograms
  //////////////////////////////
  TH1F* MatchedLooseIsoCJPt_   = (TH1F*)MatchedLooseIsoCJPtCanvas->GetPrimitive("MatchedLooseIsoCJPt");
  TH1F* MatchedMedIsoCJPt_     = (TH1F*)MatchedMedIsoCJPtCanvas->GetPrimitive("MatchedMedIsoCJPt");
  TH1F* MatchedTightIsoCJPt_   = (TH1F*)MatchedTightIsoCJPtCanvas->GetPrimitive("MatchedTightIsoCJPt");
  TH1F* MatchedCJPt_   = (TH1F*)MatchedCJPtCanvas->GetPrimitive("MatchedCJPt");
  TH1F* NEvents_   = (TH1F*)NEventsCanvas->GetPrimitive("NEvents");
  TH1F* NEventsCuts_   = (TH1F*)NEventsCutsCanvas->GetPrimitive("NEventsCuts");
  TH1F* GenMatchType_   = (TH1F*)GenMatchTypeCanvas->GetPrimitive("GenMatchType");
  TH1F* GenMatchPDGID_   = (TH1F*)GenMatchPDGIDCanvas->GetPrimitive("GenMatchPDGID");
  TH1F* MatchedTauMuPtLepton_   = (TH1F*)MatchedTauMuPtLeptonCanvas->GetPrimitive("MatchedTauMuPtLepton");
  TH1F* MatchedTauHadPtLepton_   = (TH1F*)MatchedTauHadPtLeptonCanvas->GetPrimitive("MatchedTauHadPtLepton");
  TH1F* MatchedTauHadEtaLepton_   = (TH1F*)MatchedTauHadEtaLeptonCanvas->GetPrimitive("MatchedTauHadEtaLepton");
  TH1F* MatchedHTLepton_   = (TH1F*)MatchedHTLeptonCanvas->GetPrimitive("MatchedHTLepton");
  TH1F* MatchedBDiscCSVLepton_   = (TH1F*)MatchedBDiscCSVLeptonCanvas->GetPrimitive("MatchedBDiscCSVLepton");
  TH1F* MatchedTauMuPtJet_   = (TH1F*)MatchedTauMuPtJetCanvas->GetPrimitive("MatchedTauMuPtJet");
  TH1F* MatchedTauHadPtJet_   = (TH1F*)MatchedTauHadPtJetCanvas->GetPrimitive("MatchedTauHadPtJet");
  TH1F* MatchedTauHadEtaJet_   = (TH1F*)MatchedTauHadEtaJetCanvas->GetPrimitive("MatchedTauHadEtaJet");
  TH1F* MatchedHTJet_   = (TH1F*)MatchedHTJetCanvas->GetPrimitive("MatchedHTJet");
  TH1F* MatchedBDiscCSVJet_   = (TH1F*)MatchedBDiscCSVJetCanvas->GetPrimitive("MatchedBDiscCSVJet");

  TH1F* MassDiLepGEN_   = (TH1F*)MassDiLepGENCanvas->GetPrimitive("MassDiLepGEN");
  TH1F* MassDiLepRECO_   = (TH1F*)MassDiLepRECOCanvas->GetPrimitive("MassDiLepRECO");
  TH1F* Mu3LargestPtMatch_   = (TH1F*)Mu3LargestPtMatchCanvas->GetPrimitive("Mu3LargestPtMatch");
  TH1F* Mu3Match_   = (TH1F*)Mu3MatchCanvas->GetPrimitive("Mu3Match");
  TH1F* PtOverMassMu1Mu2_   = (TH1F*)PtOverMassMu1Mu2Canvas->GetPrimitive("PtOverMassMu1Mu2");
  TH1F* PtMu1Mu2_   = (TH1F*)PtMu1Mu2Canvas->GetPrimitive("PtMu1Mu2");

cout << "Histograms assigned." << endl; 

  ////////////////////////////
  // Getting Jets Numbers
  ////////////////////////////
  Counts[0]  = MatchedLooseIsoCJPt_->GetEntries();
  Counts[1]  = MatchedMedIsoCJPt_->GetEntries();
  Counts[2]  = MatchedTightIsoCJPt_->GetEntries();
  Counts[3]  = MatchedCJPt_->GetEntries();
  Counts[4]  = NEvents_->GetBinContent(1);

  // Declare Bin counts for 
  Cuts[0] = NEventsCuts_->GetBinContent(1);
  Cuts[1] = NEventsCuts_->GetBinContent(2);
  Cuts[2] = NEventsCuts_->GetBinContent(3);
  Cuts[3] = NEventsCuts_->GetBinContent(4);
  Cuts[4] = NEventsCuts_->GetBinContent(5);
  Cuts[4] = NEventsCuts_->GetBinContent(6);
  Cuts[6] = NEventsCuts_->GetBinContent(7);
  Cuts[7] = NEventsCuts_->GetBinContent(8);
  Cuts[8] = NEventsCuts_->GetBinContent(9);
  Cuts[9] = NEventsCuts_->GetBinContent(10);
  Cuts[10] = NEventsCuts_->GetBinContent(11); 
  Cuts[11] = NEventsCuts_->GetBinContent(12);
  Cuts[12] = NEventsCuts_->GetBinContent(13);
  Cuts[13] = NEventsCuts_->GetBinContent(14);
  Cuts[14] = NEventsCuts_->GetBinContent(15);
  Cuts[15] = NEventsCuts_->GetBinContent(16);
  Cuts[16] = NEventsCuts_->GetBinContent(17);
  Cuts[16] = NEventsCuts_->GetBinContent(18);
  Cuts[17] = NEventsCuts_->GetBinContent(19);

  //Setting Color for Overlaid Lepton Matched histograms
  MatchedTauMuPtLepton_->SetLineColor(color);
  MatchedTauHadPtLepton_->SetLineColor(color);
  MatchedTauHadEtaLepton_->SetLineColor(color);
  MatchedHTLepton_->SetLineColor(color);
  MatchedBDiscCSVLepton_->SetLineColor(color);
  MatchedTauMuPtJet_->SetLineColor(color);
  MatchedTauHadPtJet_->SetLineColor(color);
  MatchedTauHadEtaJet_->SetLineColor(color);
  MatchedHTJet_->SetLineColor(color);
  MatchedBDiscCSVJet_->SetLineColor(color);

  std::cout << "File: " << legName << std::endl;
  //Drawing all of the Overlaid Lepton Matched HIstograms
  if (firstFile)
  {
    CanvasArray[0].cd();
    if (MatchedTauHadPtLepton_->GetEntries() != 0)
      MatchedTauHadPtLepton_->DrawNormalized();
    leg->Draw();
std::cout << "check1" << std::endl;
  
    CanvasArray[1].cd();
    if (MatchedTauMuPtLepton_->GetEntries() != 0)
      MatchedTauMuPtLepton_->DrawNormalized();
    leg->Draw();
std::cout << "check2" << std::endl;
   
    CanvasArray[2].cd();
    if (MatchedTauHadEtaLepton_->GetEntries() != 0)
      MatchedTauHadEtaLepton_->DrawNormalized();
    leg->Draw();
std::cout << "check3" << std::endl;
    
    CanvasArray[3].cd();
    if (MatchedHTLepton_->GetEntries() != 0)
      MatchedHTLepton_->DrawNormalized();
    leg->Draw();
std::cout << "check4" << std::endl;
    
    CanvasArray[4].cd();
    if (MatchedBDiscCSVLepton_->GetEntries() != 0)
      MatchedBDiscCSVLepton_->DrawNormalized();
    leg->Draw();
std::cout << "check5" << std::endl;
    
    CanvasArray[5].cd();
    if (MatchedTauHadPtJet_->GetEntries() != 0)
      MatchedTauHadPtJet_->DrawNormalized();
    leg->Draw();
std::cout << "check6" << std::endl;
    
    CanvasArray[6].cd();
    if (MatchedTauMuPtJet_->GetEntries() != 0)
      MatchedTauMuPtJet_->DrawNormalized();
    leg->Draw();
std::cout << "check7" << std::endl;
    
    CanvasArray[7].cd();
    if (MatchedTauHadEtaJet_->GetEntries() != 0) 
      MatchedTauHadEtaJet_->DrawNormalized();
    leg->Draw();
std::cout << "check8" << std::endl;
  
    CanvasArray[8].cd();
    if (MatchedHTJet_->GetEntries() != 0)
      MatchedHTJet_->DrawNormalized();
    leg->Draw();
std::cout << "check" << std::endl;
    
    CanvasArray[9].cd();
    if (MatchedBDiscCSVJet_->GetEntries() != 0) 
      MatchedBDiscCSVJet_->DrawNormalized();
    leg->Draw();
  }//if firstFile 
  else
  {
    CanvasArray[0].cd();
    if (MatchedTauHadPtLepton_->GetEntries() != 0)
      MatchedTauHadPtLepton_->DrawNormalized("SAME");

    leg->Draw();
    
    CanvasArray[1].cd();
    if (MatchedTauMuPtLepton_->GetEntries() != 0)
      MatchedTauMuPtLepton_->DrawNormalized("SAME");
    leg->Draw();
    
    CanvasArray[2].cd();
    if (MatchedTauHadEtaLepton_->GetEntries() != 0)
      MatchedTauHadEtaLepton_->DrawNormalized("SAME");
    leg->Draw();

    CanvasArray[3].cd();
    if (MatchedHTLepton_->GetEntries() != 0)
      MatchedHTLepton_->DrawNormalized("SAME");
    leg->Draw();
    
    CanvasArray[4].cd();
    if (MatchedBDiscCSVLepton_->GetEntries() != 0)
      MatchedBDiscCSVLepton_->DrawNormalized("SAME");
    leg->Draw();
    
    CanvasArray[5].cd();
    if (MatchedTauHadPtJet_->GetEntries() != 0)
      MatchedTauHadPtJet_->DrawNormalized("SAME");
    leg->Draw();
    
    CanvasArray[6].cd();
    if (MatchedTauMuPtJet_->GetEntries() != 0)
      MatchedTauMuPtJet_->DrawNormalized("SAME");
    leg->Draw();

    CanvasArray[7].cd();
    if (MatchedTauHadEtaJet_->GetEntries() != 0)     
      MatchedTauHadEtaJet_->DrawNormalized("SAME");
    leg->Draw();
    
    CanvasArray[8].cd();
    if (MatchedHTJet_->GetEntries() != 0)
      MatchedHTJet_->DrawNormalized("SAME");
    leg->Draw();
    
    CanvasArray[9].cd();
    if (MatchedBDiscCSVJet_->GetEntries() != 0)     
      MatchedBDiscCSVJet_->DrawNormalized("SAME");
    leg->Draw();
  }//if firstFile 
cout << "Histograms Drawn" << endl;

  outFile->cd();
  string nameGMType = GenMatchType_->GetName();
  nameGMType += legName;
  GenMatchType_->SetName(nameGMType.c_str() );
  GenMatchType_->Write();

  string nameGMPDGID = GenMatchPDGID_->GetName();
  nameGMPDGID += legName;
  GenMatchPDGID_->SetName(nameGMPDGID.c_str() );
  GenMatchPDGID_->Write();
 
  outFile->cd();
  string nameMassGen = MassDiLepGEN_->GetName();
  nameMassGen += legName;
  MassDiLepGEN_->SetName(nameMassGen.c_str() );
  MassDiLepGEN_->Write();

  string nameMassRECO = MassDiLepRECO_->GetName();
  nameMassRECO += legName;
  MassDiLepRECO_->SetName(nameMassRECO.c_str() );
  MassDiLepRECO_->Write();

  outFile->cd();
  string nameMu3LarMatch = Mu3LargestPtMatch_->GetName();
  nameMu3LarMatch += legName;
  Mu3LargestPtMatch_->SetName(nameMu3LarMatch.c_str() );
  Mu3LargestPtMatch_->Write();

  string Mu3Match = Mu3Match_->GetName();
  Mu3Match += legName;
  Mu3Match_->SetName(Mu3Match.c_str() );
  Mu3Match_->Write();

  outFile->cd();
  string namePtOverMass = PtOverMassMu1Mu2_->GetName();
  namePtOverMass += legName;
  PtOverMassMu1Mu2_->SetName(namePtOverMass.c_str() );
  PtOverMassMu1Mu2_->Write();

  string namePtMu1Mu2 = PtMu1Mu2_->GetName();
  namePtMu1Mu2 += legName;
  PtMu1Mu2_->SetName(namePtMu1Mu2.c_str() );
  PtMu1Mu2_->Write();


 
  outFile->Close();
cout << "end" << endl;

}//rootMacro_BBA_combine
