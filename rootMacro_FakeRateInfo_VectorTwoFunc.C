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
#include <vector>

void GetFormatAndDrawBack(TFile &infile, TFile *outFile, TLegend *leg, string legName, const Color_t color, std::vector<TCanvas*> &CanvasArray, double scale, bool firstFile, int Cuts[], int Counts[], string labels[], int quadrant, string tauDM);

void GetFormatAndDrawSign(TFile &infile, TFile *outFile, TLegend *leg, string legName, const Color_t color, std::vector<TCanvas*> &CanvasArray, double scale, bool firstFile, int Cuts[], int Counts[], string labels[], int quadrant, string tauDM);

void rootMacro_FakeRateInfo_VectorTwoFunc()
{

  gStyle->SetOptStat(kFALSE);
  gStyle->SetEndErrorSize(7);

  //Old DMs
  TFile infileTTNew   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_TT_New_BDScan_DEC20.root");
  TFile infileTTNewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_TT_NewMVA_BDScan_DEC20.root");
  TFile infileTTOld   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_TT_Old_BDScan_DEC20.root");
  TFile infileTTOldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_TT_OldMVA_BDScan_DEC20.root");

  TFile infileWJNew   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_WJ_New_BDScan_DEC20.root");
  TFile infileWJNewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_WJ_NewMVA_BDScan_DEC20.root");
  TFile infileWJOld   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_WJ_Old_BDScan_DEC20.root");
  TFile infileWJOldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_WJ_OldMVA_BDScan_DEC20.root");

  TFile infileDYNew   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_DY_New_BDScan_DEC20.root");
  TFile infileDYNewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_DY_NewMVA_BDScan_DEC20.root");
  TFile infileDYOld   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_DY_Old_BDScan_DEC20.root");
  TFile infileDYOldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_DY_OldMVA_BDScan_DEC20.root");

  TFile infileDYLowNew   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_DYLow_New_BDScan_DEC20.root");
  TFile infileDYLowNewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_DYLow_NewMVA_BDScan_DEC20.root");
  TFile infileDYLowOld   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_DYLow_Old_BDScan_DEC20.root");
  TFile infileDYLowOldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_DYLow_OldMVA_BDScan_DEC20.root");
   
  TFile infileWZNew   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_WZ_New_BDScan_DEC20.root");
  TFile infileWZNewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_WZ_NewMVA_BDScan_DEC20.root");
  TFile infileWZOld   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_WZ_Old_BDScan_DEC20.root");
  TFile infileWZOldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_WZ_OldMVA_BDScan_DEC20.root");

  TFile infileZZNew   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_ZZ_New_BDScan_DEC20.root");
  TFile infileZZNewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_ZZ_NewMVA_BDScan_DEC20.root");
  TFile infileZZOld   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_ZZ_Old_BDScan_DEC20.root");
  TFile infileZZOldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_ZZ_OldMVA_BDScan_DEC20.root");

  TFile infileH125a19New   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125a19_New_BDScan_DEC20.root");
  TFile infileH125a19NewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125a19_NewMVA_BDScan_DEC20.root");
  TFile infileH125a19Old   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125a19_Old_BDScan_DEC20.root");
  TFile infileH125a19OldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125a19_OldMVA_BDScan_DEC20.root");

  TFile infileH125a9New   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125a9_New_BDScan_DEC20.root");
  TFile infileH125a9NewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125a9_NewMVA_BDScan_DEC20.root");
  TFile infileH125a9Old   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125a9_Old_BDScan_DEC20.root");
  TFile infileH125a9OldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125a9_OldMVA_BDScan_DEC20.root");

  TFile infileH125a5New   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125a5_New_BDScan_DEC20.root");
  TFile infileH125a5NewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125a5_NewMVA_BDScan_DEC20.root");
  TFile infileH125a5Old   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125a5_Old_BDScan_DEC20.root");
  TFile infileH125a5OldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H125a5_OldMVA_BDScan_DEC20.root");

  TFile infileH750a9New   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H750a9_New_BDScan_DEC20.root");
  TFile infileH750a9NewMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H750a9_NewMVA_BDScan_DEC20.root");
  TFile infileH750a9Old   ("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H750a9_Old_BDScan_DEC20.root");
  TFile infileH750a9OldMVA("/home/kyletos/Downloads/RootFiles/SkimStudies/Analyzed/FINAL_H750a9_OldMVA_BDScan_DEC20.root");


  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/CombinedPlots/comb_FakeRateInfo_BDScan_DEC20.root", "RECREATE");

  ofstream infoFile;
  infoFile.open ("/home/kyletos/Downloads/RootFiles/CombinedPlots/FakeRateInfo_BDScan_DEC20.txt");

  //////////////////////////////
  //  Scaling xsec calculations
  //////////////////////////////
  double scaleDY50 = 1921.8 * 3 * 20000.0 / 55371812, scaleDYLow = 1861 * 20000.0 / 30915886 , scaleTT = 831.76 * 20000.0 / 35178887, scaleWJ = 61526.7 * 20000.0 / 47737675;
  double scaleZZ = 1.256 * 20000.0 / 10367601, scaleWZ = 5.26 * 20000.0 / 1960761, scaleH125a19 = 48.90 * 20000.0 / 283980,  scaleH750a9 = 0.4969 * 20000.0/ 265025;
  double scaleH125a5= 48.90 * 20000.0 / 297366, scaleH125a9= 48.90 * 20000.0 / 300000;
  
  std::cout << "SCALE" << std::endl;
  std::cout << "DY50= " << scaleDY50 << std::endl;
  std::cout << "DY10= " << scaleDYLow << std::endl;
  std::cout << "TT  = " << scaleTT << std::endl;
  std::cout << "WJ  = " << scaleWJ << std::endl;
  std::cout << "ZZ  = " << scaleZZ << std::endl;
  std::cout << "WZ  = " << scaleWZ << std::endl;
  std::cout << "H125a19= " << scaleH125a19 << std::endl;
  std::cout << "H125a9 = " << scaleH125a9 << std::endl;
  std::cout << "H125a5 = " << scaleH125a5 << std::endl;
  std::cout << "H759a9 = " << scaleH750a9 << std::endl;

  std::vector<TCanvas*> CanvasArray;

  CanvasArray.push_back(new TCanvas("TauHadPtLeptonCanvas","",600,600) );
  CanvasArray.push_back(new TCanvas("TauMuPtLeptonCanvas","",600,600) );
  CanvasArray.push_back(new TCanvas("TauHadEtaLeptonCanvas","",600,600) );
  CanvasArray.push_back(new TCanvas("HTLeptonCanvas","",600,600) );
  CanvasArray.push_back(new TCanvas("BDiscCSVLeptonCanvas","",600,600) );

  CanvasArray[0]->SetGrid(1,1);
  CanvasArray[1]->SetGrid(1,1);
  CanvasArray[2]->SetGrid(1,1);
  CanvasArray[3]->SetGrid(1,1);
  CanvasArray[4]->SetGrid(1,1);

  CanvasArray[0]->Divide(2,2);
  CanvasArray[1]->Divide(2,2);
  CanvasArray[2]->Divide(2,2);
  CanvasArray[3]->Divide(2,2);
  CanvasArray[4]->Divide(2,2);

  CanvasArray.push_back(new TCanvas("TauHadPtJetCanvas","",600,600) );
  CanvasArray.push_back(new TCanvas("TauMuPtJetCanvas","",600,600) );
  CanvasArray.push_back(new TCanvas("TauHadEtaJetCanvas","",600,600) );
  CanvasArray.push_back(new TCanvas("HTJetCanvas","",600,600) );
  CanvasArray.push_back(new TCanvas("BDiscCSVJetCanvas","",600,600) );

  CanvasArray[5]->SetGrid(1,1);
  CanvasArray[6]->SetGrid(1,1);
  CanvasArray[7]->SetGrid(1,1);
  CanvasArray[8]->SetGrid(1,1);
  CanvasArray[9]->SetGrid(1,1);

  CanvasArray[5]->Divide(2,2);
  CanvasArray[6]->Divide(2,2);
  CanvasArray[7]->Divide(2,2);
  CanvasArray[8]->Divide(2,2);
  CanvasArray[9]->Divide(2,2);

  CanvasArray.push_back(new TCanvas("MassDiLepGENCanvas","",600,600) );
  CanvasArray.push_back(new TCanvas("MassDiLepRECOCanvas","",600,600) );
  CanvasArray.push_back(new TCanvas("Mu3LargestPtMatchCanvas","",600,600) );
  CanvasArray.push_back(new TCanvas("Mu3PtMatchCanvas","",600,600) );
  CanvasArray.push_back(new TCanvas("PtOverMassMu1Mu2Canvas","",600,600) );
  CanvasArray.push_back(new TCanvas("PtMu1Mu2Canvas","",600,600) );

  CanvasArray[10]->SetGrid(1,1);
  CanvasArray[11]->SetGrid(1,1);
  CanvasArray[12]->SetGrid(1,1);
  CanvasArray[13]->SetGrid(1,1);
  CanvasArray[14]->SetGrid(1,1);
  CanvasArray[15]->SetGrid(1,1);

  CanvasArray[10]->Divide(2,2);
  CanvasArray[11]->Divide(2,2);
  CanvasArray[12]->Divide(2,2);
  CanvasArray[13]->Divide(2,2);
  CanvasArray[14]->Divide(2,2);
  CanvasArray[15]->Divide(2,2);

  TCanvas OldSigToBackCanvas("OldSigToBackCanvas","",600,600);
  TCanvas OldMVASigToBackCanvas("OldMVASigToBackCanvas","",600,600);
  TCanvas NewSigToBackCanvas("NewSigToBackCanvas","",600,600);
  TCanvas NewMVASigToBackCanvas("NewMVASigToBackCanvas","",600,600);
  TCanvas TotalSigToBackCanvas("TotalSigToBackCanvas","",600,600);

  OldSigToBackCanvas.SetGrid(1,1);
  OldMVASigToBackCanvas.SetGrid(1,1);
  NewSigToBackCanvas.SetGrid(1,1);
  NewMVASigToBackCanvas.SetGrid(1,1);
  TotalSigToBackCanvas.SetGrid(1,1);
  TotalSigToBackCanvas.Divide(2,2);

  legNewMVA = new TLegend(0.1,0.7,0.25,0.9);
  legNew = new TLegend(0.1,0.7,0.25,0.9);
  legOldMVA = new TLegend(0.1,0.7,0.25,0.9);
  legOld = new TLegend(0.1,0.7,0.25,0.9);

  string TTName = "TT", DYName = "DY" , DYLowName = "DYLow", WJName = "WJ", H125a19Name = "H125a19", H125a9Name = "H125a9", H125a5Name = "H125a5", H750a9Name = "H750a9", WZName = "WZ", ZZName = "ZZ";
  string  NewMVA = "NewMVA", New = "New", OldMVA = "OldMVA", Old = "Old";

  int CutDYNewMVA[22], CutDYLowNewMVA[22], CutTTNewMVA[22], CutWJNewMVA[22],  CutWZNewMVA[22], CutZZNewMVA[22], CutH125a19NewMVA[22], CutH125a9NewMVA[22], CutH125a5NewMVA[22], CutH750a9NewMVA[22];
  int CutDYNew[22], CutDYLowNew[22], CutTTNew[22], CutWJNew[22], CutWZNew[22], CutZZNew[22], CutH125a19New[22], CutH125a9New[22], CutH125a5New[22], CutH750a9New[22];
  int CutDYOldMVA[22], CutDYLowOldMVA[22], CutTTOldMVA[22], CutWJOldMVA[22], CutWZOldMVA[22], CutZZOldMVA[22], CutH125a19OldMVA[22], CutH125a9OldMVA[22], CutH125a5OldMVA[22], CutH750a9OldMVA[22];
  int CutDYOld[22], CutDYLowOld[22], CutTTOld[22], CutWJOld[22], CutWZOld[22], CutZZOld[22], CutH125a19Old[22], CutH125a9Old[22], CutH125a5Old[22], CutH750a9Old[22];

  int CountDYNewMVA[5], CountDYLowNewMVA[5], CountTTNewMVA[5], CountWJNewMVA[5], CountWZNewMVA[5], CountZZNewMVA[5], CountH125a19NewMVA[5], CountH125a9NewMVA[5], CountH125a5NewMVA[5], CountH750a9NewMVA[5];
  int CountDYNew[5], CountDYLowNew[5], CountTTNew[5], CountWJNew[5], CountWZNew[5], CountZZNew[5], CountH125a19New[5], CountH125a9New[5], CountH125a5New[5], CountH750a9New[5]; 
  int CountDYOldMVA[5], CountDYLowOldMVA[5], CountTTOldMVA[5], CountWJOldMVA[5], CountWZOldMVA[5], CountZZOldMVA[5], CountH125a19OldMVA[5], CountH125a9OldMVA[5], CountH125a5OldMVA[5], CountH750a9OldMVA[5];
  int CountDYOld[5], CountDYLowOld[5], CountTTOld[5], CountWJOld[5], CountWZOld[5], CountZZOld[5], CountH125a19Old[5], CountH125a9Old[5], CountH125a5Old[5], CountH750a9Old[5]; 
  
  string CutLabelsBack[22], CutLabelsSig[11];

  for (int i=0; i < 11; i++)
    CutLabelsSig[i] = "";
  //Initialize Arrays
  for (int i=0;i < 22; i++)
  {
    CutDYNewMVA[i] = -1;
    CutDYNew[i] = -1;
    CutDYOldMVA[i] = -1;
    CutDYOld[i] = -1;
    CutTTNewMVA[i] = -1;
    CutTTNew[i] = -1;
    CutTTOldMVA[i] = -1;
    CutTTOld[i] = -1;
    CutWJNewMVA[i] = -1;
    CutWJNew[i] = -1;
    CutWJOldMVA[i] = -1;
    CutWJOld[i] = -1;
    CutWZNewMVA[i] = -1;
    CutWZNew[i] = -1;
    CutWZOldMVA[i] = -1;
    CutWZOld[i] = -1;
    CutZZNewMVA[i] = -1;
    CutZZNew[i] = -1;
    CutZZOldMVA[i] = -1;
    CutZZOld[i] = -1;
    CutDYLowNewMVA[i] = -1;
    CutDYLowNew[i] = -1;
    CutDYLowOldMVA[i] = -1;
    CutDYLowOld[i] = -1;
    CutH125a19NewMVA[i] = -1;
    CutH125a19New[i] = -1;
    CutH125a19OldMVA[i] = -1;
    CutH125a19Old[i] = -1;
    CutH125a9NewMVA[i] = -1;
    CutH125a9New[i] = -1;
    CutH125a9OldMVA[i] = -1;
    CutH125a9Old[i] = -1;
    CutH125a5NewMVA[i] = -1;
    CutH125a5New[i] = -1;
    CutH125a5OldMVA[i] = -1;
    CutH125a5Old[i] = -1;
    CutH750a9NewMVA[i] = -1;
    CutH750a9New[i] = -1;
    CutH750a9OldMVA[i] = -1;
    CutH750a9Old[i] = -1;
    CutLabelsBack[i] = "";
  }//for

  //Initialize Arrays
  for (int i=0; i < 5; i++)
  {
    CountDYNewMVA[i] = -1;
    CountDYNew[i] = -1;
    CountDYOldMVA[i] = -1;
    CountDYOld[i] = -1; 
    CountTTNewMVA[i] = -1;
    CountTTNew[i] = -1;
    CountTTOldMVA[i] = -1;
    CountTTOld[i] = -1;
    CountWJNewMVA[i] = -1;
    CountWJNew[i] = -1;
    CountWJOldMVA[i] = -1;
    CountWJOld[i] = -1;
    CountWZNewMVA[i] = -1;
    CountWZNew[i] = -1;
    CountWZOldMVA[i] = -1;
    CountWZOld[i] = -1;
    CountZZNewMVA[i] = -1;
    CountZZNew[i] = -1;
    CountZZOldMVA[i] = -1;
    CountZZOld[i] = -1;
    CountDYLowNewMVA[i] = -1;
    CountDYLowNew[i] = -1;
    CountDYLowOldMVA[i] = -1;
    CountDYLowOld[i] = -1;
    CountH125a19NewMVA[i] = -1;
    CountH125a19New[i] = -1;
    CountH125a19OldMVA[i] = -1;
    CountH125a19Old[i] = -1;
    CountH125a9NewMVA[i] = -1;
    CountH125a9New[i] = -1;
    CountH125a9OldMVA[i] = -1;
    CountH125a9Old[i] = -1;
    CountH125a5NewMVA[i] = -1;
    CountH125a5New[i] = -1;
    CountH125a5OldMVA[i] = -1;
    CountH125a5Old[i] = -1;
    CountH750a9NewMVA[i] = -1;
    CountH750a9New[i] = -1;
    CountH750a9OldMVA[i] = -1;
    CountH750a9Old[i] = -1;
  }//for


  std::cout << "\nNewMVA" << std::endl;
  GetFormatAndDrawBack(infileTTNewMVA, outFile, legNewMVA, TTName, kBlue+1, CanvasArray, scaleTT, true, CutTTNewMVA, CountTTNewMVA, CutLabelsBack, 1, NewMVA);
  GetFormatAndDrawBack(infileDYNewMVA, outFile, legNewMVA, DYName, kRed, CanvasArray, scaleDY50, false, CutDYNewMVA, CountDYNewMVA, CutLabelsBack, 1, NewMVA);
  GetFormatAndDrawBack(infileDYLowNewMVA, outFile, legNewMVA, DYLowName, kYellow-1, CanvasArray, scaleDYLow, false, CutDYLowNewMVA, CountDYLowNewMVA, CutLabelsBack, 1, NewMVA);
  GetFormatAndDrawBack(infileWJNewMVA, outFile, legNewMVA, WJName, kGreen+1, CanvasArray, scaleWJ, false, CutWJNewMVA, CountWJNewMVA, CutLabelsBack, 1, NewMVA);
  GetFormatAndDrawBack(infileWZNewMVA, outFile, legNewMVA, WZName, kCyan, CanvasArray, scaleWZ, false, CutWZNewMVA, CountWZNewMVA, CutLabelsBack, 1, NewMVA);
  GetFormatAndDrawBack(infileZZNewMVA, outFile, legNewMVA, ZZName, kOrange+1, CanvasArray, scaleZZ, false, CutZZNewMVA, CountZZNewMVA, CutLabelsBack, 1, NewMVA);
  GetFormatAndDrawSign(infileH125a19NewMVA, outFile, legNewMVA, H125a19Name, kBlack, CanvasArray, scaleH125a19, false, CutH125a19NewMVA, CountH125a19NewMVA, CutLabelsSig, 1, NewMVA);
  GetFormatAndDrawSign(infileH125a9NewMVA, outFile, legNewMVA, H125a9Name, kGray+1, CanvasArray, scaleH125a9, false, CutH125a9NewMVA, CountH125a9NewMVA, CutLabelsSig, 1, NewMVA);
  GetFormatAndDrawSign(infileH125a5NewMVA, outFile, legNewMVA, H125a5Name, kYellow+2, CanvasArray, scaleH125a5, false, CutH125a5NewMVA, CountH125a5NewMVA, CutLabelsSig, 1, NewMVA);
  GetFormatAndDrawSign(infileH750a9NewMVA, outFile, legNewMVA, H750a9Name, kViolet+1, CanvasArray, scaleH750a9, false, CutH750a9NewMVA, CountH750a9NewMVA, CutLabelsSig, 1, NewMVA);

  std::cout << "\nNew" << std::endl;
  GetFormatAndDrawBack(infileTTNew, outFile, legNew, TTName, kBlue+1, CanvasArray, scaleTT, false, CutTTNew, CountTTNew, CutLabelsBack, 2, New);
  GetFormatAndDrawBack(infileDYNew, outFile, legNew, DYName, kRed, CanvasArray, scaleDY50, false, CutDYNew, CountDYNew, CutLabelsBack, 2, New);
  GetFormatAndDrawBack(infileDYLowNew, outFile, legNew, DYLowName, kYellow-1, CanvasArray, scaleDYLow, false, CutDYLowNew, CountDYLowNew, CutLabelsBack, 2, New);
  GetFormatAndDrawBack(infileWJNew, outFile, legNew, WJName, kGreen+1, CanvasArray, scaleWJ, false, CutWJNew, CountWJNew, CutLabelsBack, 2, New);
  GetFormatAndDrawBack(infileWZNew, outFile, legNew, WZName, kCyan, CanvasArray, scaleWZ, false, CutWZNew, CountWZNew, CutLabelsBack, 2, New);
  GetFormatAndDrawBack(infileZZNew, outFile, legNew, ZZName, kOrange+1, CanvasArray, scaleZZ, false, CutZZNew, CountZZNew, CutLabelsBack, 2, New);
  GetFormatAndDrawSign(infileH125a19New, outFile, legNew, H125a19Name, kBlack, CanvasArray, scaleH125a19, false, CutH125a19New, CountH125a19New, CutLabelsSig, 2, New);
  GetFormatAndDrawSign(infileH125a9New, outFile, legNew, H125a9Name, kGray+1, CanvasArray, scaleH125a9, false, CutH125a9New, CountH125a9New, CutLabelsSig, 2, New);
  GetFormatAndDrawSign(infileH125a5New, outFile, legNew, H125a5Name, kYellow+2, CanvasArray, scaleH125a5, false, CutH125a5New, CountH125a5New, CutLabelsSig, 2, New);
  GetFormatAndDrawSign(infileH750a9New, outFile, legNew, H750a9Name, kViolet+1, CanvasArray, scaleH750a9, false, CutH750a9New, CountH750a9New, CutLabelsSig, 2, New);

  std::cout << "\nOldMVA" << std::endl;
  GetFormatAndDrawBack(infileTTOldMVA, outFile, legOldMVA, TTName, kBlue+1, CanvasArray, scaleTT, false, CutTTOldMVA, CountTTOldMVA, CutLabelsBack, 3, OldMVA);
  GetFormatAndDrawBack(infileDYOldMVA, outFile, legOldMVA, DYName, kRed, CanvasArray, scaleDY50, false, CutDYOldMVA, CountDYOldMVA, CutLabelsBack, 3, OldMVA);
  GetFormatAndDrawBack(infileDYLowOldMVA, outFile, legOldMVA, DYLowName, kYellow-1, CanvasArray, scaleDYLow, false, CutDYLowOldMVA, CountDYLowOldMVA, CutLabelsBack, 3, OldMVA);
  GetFormatAndDrawBack(infileWJOldMVA, outFile, legOldMVA, WJName, kGreen+1, CanvasArray, scaleWJ, false, CutWJOldMVA, CountWJOldMVA, CutLabelsBack, 3, OldMVA);
  GetFormatAndDrawBack(infileWZOldMVA, outFile, legOldMVA, WZName, kCyan, CanvasArray, scaleWZ, false, CutWZOldMVA, CountWZOldMVA, CutLabelsBack, 3, OldMVA);
  GetFormatAndDrawBack(infileZZOldMVA, outFile, legOldMVA, ZZName, kOrange+1, CanvasArray, scaleZZ, false, CutZZOldMVA, CountZZOldMVA, CutLabelsBack, 3, OldMVA);
  GetFormatAndDrawSign(infileH125a19OldMVA, outFile, legOldMVA, H125a19Name, kBlack, CanvasArray, scaleH125a19, false, CutH125a19OldMVA, CountH125a19OldMVA, CutLabelsSig, 3, OldMVA);
  GetFormatAndDrawSign(infileH125a9OldMVA, outFile, legOldMVA, H125a9Name, kGray+1, CanvasArray, scaleH125a9, false, CutH125a9OldMVA, CountH125a9OldMVA, CutLabelsSig, 3, OldMVA);
  GetFormatAndDrawSign(infileH125a5OldMVA, outFile, legOldMVA, H125a5Name, kYellow+2, CanvasArray, scaleH125a5, false, CutH125a5OldMVA, CountH125a5OldMVA, CutLabelsSig, 3, OldMVA);
  GetFormatAndDrawSign(infileH750a9OldMVA, outFile, legOldMVA, H750a9Name, kViolet+1, CanvasArray, scaleH750a9, false, CutH750a9OldMVA, CountH750a9OldMVA, CutLabelsSig, 3, OldMVA);

  std::cout << "\nOld" << std::endl;
  GetFormatAndDrawBack(infileTTOld, outFile, legOld, TTName, kBlue+1, CanvasArray, scaleTT, false, CutTTOld, CountTTOld, CutLabelsBack, 4, Old);
  GetFormatAndDrawBack(infileDYOld, outFile, legOld, DYName, kRed, CanvasArray, scaleDY50, false, CutDYOld, CountDYOld, CutLabelsBack, 4, Old);
  GetFormatAndDrawBack(infileDYLowOld, outFile, legOld, DYLowName, kYellow-1, CanvasArray, scaleDYLow, false, CutDYLowOld, CountDYLowOld, CutLabelsBack, 4, Old);
  GetFormatAndDrawBack(infileWJOld, outFile, legOld, WJName, kGreen+1, CanvasArray, scaleWJ, false, CutWJOld, CountWJOld, CutLabelsBack, 4, Old);
  GetFormatAndDrawBack(infileWZOld, outFile, legOld, WZName, kCyan, CanvasArray, scaleWZ, false, CutWZOld, CountWZOld, CutLabelsBack, 4, Old);
  GetFormatAndDrawBack(infileZZOld, outFile, legOld, ZZName, kOrange+1, CanvasArray, scaleZZ, false, CutZZOld, CountZZOld, CutLabelsBack, 4, Old);
  GetFormatAndDrawSign(infileH125a19Old, outFile, legOld, H125a19Name, kBlack, CanvasArray, scaleH125a19, false, CutH125a19Old, CountH125a19Old, CutLabelsSig, 4, Old);
  GetFormatAndDrawSign(infileH125a9Old, outFile, legOld, H125a9Name, kGray+1, CanvasArray, scaleH125a9, false, CutH125a9Old, CountH125a9Old, CutLabelsSig, 4, Old);
  GetFormatAndDrawSign(infileH125a5Old, outFile, legOld, H125a5Name, kYellow+2, CanvasArray, scaleH125a5, false, CutH125a5Old, CountH125a5Old, CutLabelsSig, 4, Old);
  GetFormatAndDrawSign(infileH750a9Old, outFile, legOld, H750a9Name, kViolet+1, CanvasArray, scaleH750a9, false, CutH750a9Old, CountH750a9Old, CutLabelsSig, 4, Old);

std::cout << "Formatting and Drawing done. Writing cut output." << std::endl;

  ///////////
  // scaling
  ///////////
  for (int i=0; i < 5; i++)
  {
    CountDYNewMVA[i] = CountDYNewMVA[i] * scaleDY50;
    CountDYNew[i] = CountDYNew[i] * scaleDY50;
    CountDYOldMVA[i] = CountDYOldMVA[i] * scaleDY50;
    CountDYOld[i] = CountDYOld[i] * scaleDY50;

    CountTTNewMVA[i] = CountTTNewMVA[i] * scaleTT;
    CountTTNew[i] = CountTTNew[i] * scaleTT;
    CountTTOldMVA[i] = CountTTOldMVA[i] * scaleTT;
    CountTTOld[i] = CountTTOld[i] * scaleTT;

    CountWJNewMVA[i] = CountWJNewMVA[i] * scaleWJ;
    CountWJNew[i] = CountWJNew[i] * scaleWJ;
    CountWJOldMVA[i] = CountWJOldMVA[i] * scaleWJ;
    CountWJOld[i] = CountWJOld[i] * scaleWJ;

    CountWZNewMVA[i] = CountWZNewMVA[i] * scaleWZ;
    CountWZNew[i] = CountWZNew[i] * scaleWZ;
    CountWZOldMVA[i] = CountWZOldMVA[i] * scaleWZ;
    CountWZOld[i] = CountWZOld[i] * scaleWZ;

    CountZZNewMVA[i] = CountZZNewMVA[i] * scaleZZ;
    CountZZNew[i] = CountZZNew[i] * scaleZZ;
    CountZZOldMVA[i] = CountZZOldMVA[i] * scaleZZ;
    CountZZOld[i] = CountZZOld[i] * scaleZZ;

    CountDYLowNewMVA[i] = CountDYLowNewMVA[i] * scaleDYLow;
    CountDYLowNew[i] = CountDYLowNew[i] * scaleDYLow;
    CountDYLowOldMVA[i] = CountDYLowOldMVA[i] * scaleDYLow;
    CountDYLowOld[i] = CountDYLowOld[i] * scaleDYLow;

    CountH125a19NewMVA[i] = CountH125a19NewMVA[i] * scaleH125a19;
    CountH125a19New[i] = CountH125a19New[i] * scaleH125a19;
    CountH125a19OldMVA[i] = CountH125a19OldMVA[i] * scaleH125a19;
    CountH125a19Old[i] = CountH125a19Old[i] * scaleH125a19;

    CountH125a9NewMVA[i] = CountH125a9NewMVA[i] * scaleH125a9;
    CountH125a9New[i] = CountH125a9New[i] * scaleH125a9;
    CountH125a9OldMVA[i] = CountH125a9OldMVA[i] * scaleH125a9;
    CountH125a9Old[i] = CountH125a9Old[i] * scaleH125a9;

    CountH125a5NewMVA[i] = CountH125a5NewMVA[i] * scaleH125a5;
    CountH125a5New[i] = CountH125a5New[i] * scaleH125a5;
    CountH125a5OldMVA[i] = CountH125a5OldMVA[i] * scaleH125a5;
    CountH125a5Old[i] = CountH125a5Old[i] * scaleH125a5;

    CountH750a9NewMVA[i] = CountH750a9NewMVA[i] * scaleH750a9;
    CountH750a9New[i] = CountH750a9New[i] * scaleH750a9;
    CountH750a9OldMVA[i] = CountH750a9OldMVA[i] * scaleH750a9;
    CountH750a9Old[i] = CountH750a9Old[i] * scaleH750a9;
  }//for

  for (int i=0; i < 22; i++)
  {
    CutDYNewMVA[i] = CutDYNewMVA[i] * scaleDY50;
    CutDYNew[i] = CutDYNew[i] * scaleDY50;
    CutDYOldMVA[i] = CutDYOldMVA[i] * scaleDY50;
    CutDYOld[i] = CutDYOld[i] * scaleDY50;

    CutTTNewMVA[i] = CutTTNewMVA[i] * scaleTT;
    CutTTNew[i] = CutTTNew[i] * scaleTT;
    CutTTOldMVA[i] = CutTTOldMVA[i] * scaleTT;
    CutTTOld[i] = CutTTOld[i] * scaleTT;

    CutWJNewMVA[i] = CutWJNewMVA[i] * scaleWJ;
    CutWJNew[i] = CutWJNew[i] * scaleWJ;
    CutWJOldMVA[i] = CutWJOldMVA[i] * scaleWJ;
    CutWJOld[i] = CutWJOld[i] * scaleWJ;

    CutWZNewMVA[i] = CutWZNewMVA[i] * scaleWZ;
    CutWZNew[i] = CutWZNew[i] * scaleWZ;
    CutWZOldMVA[i] = CutWZOldMVA[i] * scaleWZ;
    CutWZOld[i] = CutWZOld[i] * scaleWZ;

    CutZZNewMVA[i] = CutZZNewMVA[i] * scaleZZ;
    CutZZNew[i] = CutZZNew[i] * scaleZZ;
    CutZZOldMVA[i] = CutZZOldMVA[i] * scaleZZ;
    CutZZOld[i] = CutZZOld[i] * scaleZZ;

    CutDYLowNewMVA[i] = CutDYLowNewMVA[i] * scaleDYLow;
    CutDYLowNew[i] = CutDYLowNew[i] * scaleDYLow;
    CutDYLowOldMVA[i] = CutDYLowOldMVA[i] * scaleDYLow;
    CutDYLowOld[i] = CutDYLowOld[i] * scaleDYLow;

    CutH125a19NewMVA[i] = CutH125a19NewMVA[i] * scaleH125a19;
    CutH125a19New[i] = CutH125a19New[i] * scaleH125a19;
    CutH125a19OldMVA[i] = CutH125a19OldMVA[i] * scaleH125a19;
    CutH125a19Old[i] = CutH125a19Old[i] * scaleH125a19;

    CutH125a9NewMVA[i] = CutH125a9NewMVA[i] * scaleH125a9;
    CutH125a9New[i] = CutH125a9New[i] * scaleH125a9;
    CutH125a9OldMVA[i] = CutH125a9OldMVA[i] * scaleH125a9;
    CutH125a9Old[i] = CutH125a9Old[i] * scaleH125a9;

    CutH125a5NewMVA[i] = CutH125a5NewMVA[i] * scaleH125a5;
    CutH125a5New[i] = CutH125a5New[i] * scaleH125a5;
    CutH125a5OldMVA[i] = CutH125a5OldMVA[i] * scaleH125a5;
    CutH125a5Old[i] = CutH125a5Old[i] * scaleH125a5;

    CutH750a9NewMVA[i] = CutH750a9NewMVA[i] * scaleH750a9;
    CutH750a9New[i] = CutH750a9New[i] * scaleH750a9;
    CutH750a9OldMVA[i] = CutH750a9OldMVA[i] * scaleH750a9;
    CutH750a9Old[i] = CutH750a9Old[i] * scaleH750a9;
  }//for


  /////////////////////////////////
  // Writing Output New + MVA
  /////////////////////////////////
  infoFile << "################################################\n## Cut Info for New DM + MVA \n################################################" << endl;
  infoFile << "nEvents with RemovedMuon: DY= " << CutDYNewMVA[0] << "\tDYLow= " << CutDYLowNewMVA[0] << "\tTT= " << CutTTNewMVA[0] << "\tWJ= " << CutWJNewMVA[0] << "\tWZ= " << CutWZNewMVA[0] << "\tZZ= " << CutZZNewMVA[0] << "\tH125a19= " << CutH125a19NewMVA[0] << "\tH125a9= " << CutH125a9NewMVA[0] << "\tH125a5= " << CutH125a5NewMVA[0] << "\tH750a9= " << CutH750a9NewMVA[0] << std::endl;
  infoFile << CutLabelsBack[18] << "\t: DY= " << CutDYNewMVA[18] << "\tDY10-50= " << CutDYLowNewMVA[18] << "\tTT= " << CutTTNewMVA[18] << "\tWJ= " << CutWJNewMVA[18] << "\tWZ= " << CutWZNewMVA[18] << "\tZZ= " << CutZZNewMVA[18] << std::endl;	
  infoFile << CutLabelsBack[1] << "\t: DY= " << CutDYNewMVA[1] << "\tDY10-50= " << CutDYLowNewMVA[1] << "\tTT= " << CutTTNewMVA[1] << "\tWJ= " << CutWJNewMVA[1] << "\tWZ= " << CutWZNewMVA[1] << "\tZZ= " << CutZZNewMVA[1] << std::endl;	
  infoFile << CutLabelsBack[2] << "\t: DY= " << CutDYNewMVA[2] << "\tDY10-50= " << CutDYLowNewMVA[2] << "\tTT= " << CutTTNewMVA[2] << "\tWJ= " << CutWJNewMVA[2] << "\tWZ= " << CutWZNewMVA[2] << "\tZZ= " << CutZZNewMVA[2] << std::endl;
  infoFile << CutLabelsBack[3] << "\t: DY= " << CutDYNewMVA[3] << "\tDY10-50= " << CutDYLowNewMVA[3] << "\tTT= " << CutTTNewMVA[3] << "\tWJ= " << CutWJNewMVA[3] << "\tWZ= " << CutWZNewMVA[3] << "\tZZ= " << CutZZNewMVA[3] << std::endl;
  infoFile << CutLabelsBack[4] << "\t: DY= " << CutDYNewMVA[4] << "\tDY10-50= " << CutDYLowNewMVA[4] << "\tTT= " << CutTTNewMVA[4] << "\tWJ= " << CutWJNewMVA[4] << "\tWZ= " << CutWZNewMVA[4] << "\tZZ= " << CutZZNewMVA[4] << std::endl;
  infoFile << CutLabelsBack[5] << "\t: DY= " << CutDYNewMVA[5] << "\tDY10-50= " << CutDYLowNewMVA[5] << "\tTT= " << CutTTNewMVA[5] << "\tWJ= " << CutWJNewMVA[5] << "\tWZ= " << CutWZNewMVA[5] << "\tZZ= " << CutZZNewMVA[5] << std::endl;
  infoFile << CutLabelsBack[6] << "\t: DY= " << CutDYNewMVA[6] << "\tDY10-50= " << CutDYLowNewMVA[6] << "\tTT= " << CutTTNewMVA[6] << "\tWJ= " << CutWJNewMVA[6] << "\tWZ= " << CutWZNewMVA[6] << "\tZZ= " << CutZZNewMVA[6] << std::endl;
  infoFile << CutLabelsBack[7] << "\t: DY= " << CutDYNewMVA[7] << "\tDY10-50= " << CutDYLowNewMVA[7] << "\tTT= " << CutTTNewMVA[7] << "\tWJ= " << CutWJNewMVA[7] << "\tWZ= " << CutWZNewMVA[7] << "\tZZ= " << CutZZNewMVA[7] << std::endl;
  infoFile << CutLabelsBack[8] << "\t: DY= " << CutDYNewMVA[8] << "\tDY10-50= " << CutDYLowNewMVA[8] << "\tTT= " << CutTTNewMVA[8] << "\tWJ= " << CutWJNewMVA[8] << "\tWZ= " << CutWZNewMVA[8] << "\tZZ= " << CutZZNewMVA[8] << std::endl;
  infoFile << CutLabelsBack[17] << "\t: DY= " << CutDYNewMVA[17] << "\tDY10-50= " << CutDYLowNewMVA[17] << "\tTT= " << CutTTNewMVA[17] << "\tWJ= " << CutWJNewMVA[17] << "\tWZ= " << CutWZNewMVA[17] << "\tZZ= " << CutZZNewMVA[17] << std::endl;	
  infoFile << CutLabelsBack[9] << "\t: DY= " << CutDYNewMVA[9] << "\tDY10-50= " << CutDYLowNewMVA[9] << "\tTT= " << CutTTNewMVA[9] << "\tWJ= " << CutWJNewMVA[9] << "\tWZ= " << CutWZNewMVA[9] << "\tZZ= " << CutZZNewMVA[9] << "\tH125a19= " << CutH125a19NewMVA[1] << "\tH125a9= " << CutH125a9NewMVA[1] << "\tH125a5= " << CutH125a5NewMVA[1] << "\tH750a9= " << CutH750a9NewMVA[1] << std::endl;
  infoFile << CutLabelsBack[10] << "\t: DY= " << CutDYNewMVA[10] << "\tDY10-50= " << CutDYLowNewMVA[10] << "\tTT= " << CutTTNewMVA[10] << "\tWJ= " << CutWJNewMVA[10] << "\tWZ= " << CutWZNewMVA[10] << "\tZZ= " << CutZZNewMVA[10] << "\tH125a19= " << CutH125a19NewMVA[2] << "\tH125a9= " << CutH125a9NewMVA[2] << "\tH125a5= " << CutH125a5NewMVA[2] << "\tH750a9= " << CutH750a9NewMVA[2] << std::endl;
  infoFile << CutLabelsBack[11] << "\t: DY= " << CutDYNewMVA[11] << "\tDY10-50= " << CutDYLowNewMVA[11] << "\tTT= " << CutTTNewMVA[11] << "\tWJ= " << CutWJNewMVA[11] << "\tWZ= " << CutWZNewMVA[11] << "\tZZ= " << CutZZNewMVA[11] << "\tH125a19= " << CutH125a19NewMVA[3] << "\tH125a9= " << CutH125a9NewMVA[3] << "\tH125a5= " << CutH125a5NewMVA[3] << "\tH750a9= " << CutH750a9NewMVA[3] << std::endl;
  infoFile << CutLabelsBack[12] << "\t: DY= " << CutDYNewMVA[12] << "\tDY10-50= " << CutDYLowNewMVA[12] << "\tTT= " << CutTTNewMVA[12] << "\tWJ= " << CutWJNewMVA[12] << "\tWZ= " << CutWZNewMVA[12] << "\tZZ= " << CutZZNewMVA[12] << "\tH125a19= " << CutH125a19NewMVA[4] << "\tH125a9= " << CutH125a9NewMVA[4] << "\tH125a5= " << CutH125a5NewMVA[4] << "\tH750a9= " << CutH750a9NewMVA[4] << std::endl;
  infoFile << CutLabelsBack[13] << "\t: DY= " << CutDYNewMVA[13] << "\tDY10-50= " << CutDYLowNewMVA[13] << "\tTT= " << CutTTNewMVA[13] << "\tWJ= " << CutWJNewMVA[13] << "\tWZ= " << CutWZNewMVA[13] << "\tZZ= " << CutZZNewMVA[13] << "\tH125a19= " << CutH125a19NewMVA[5] << "\tH125a9= " << CutH125a9NewMVA[5] << "\tH125a5= " << CutH125a5NewMVA[5] << "\tH750a9= " << CutH750a9NewMVA[5] << std::endl;	
  infoFile << CutLabelsBack[14] << "\t: DY= " << CutDYNewMVA[14] << "\tDY10-50= " << CutDYLowNewMVA[14] << "\tTT= " << CutTTNewMVA[14] << "\tWJ= " << CutWJNewMVA[14] << "\tWZ= " << CutWZNewMVA[14] << "\tZZ= " << CutZZNewMVA[14] << "\tH125a19= " << CutH125a19NewMVA[6] << "\tH125a9= " << CutH125a9NewMVA[6] << "\tH125a5= " << CutH125a5NewMVA[6] << "\tH750a9= " << CutH750a9NewMVA[6] << std::endl;	
  infoFile << CutLabelsBack[15] << "\t: DY= " << CutDYNewMVA[15] << "\tDY10-50= " << CutDYLowNewMVA[15] << "\tTT= " << CutTTNewMVA[15] << "\tWJ= " << CutWJNewMVA[15] << "\tWZ= " << CutWZNewMVA[15] << "\tZZ= " << CutZZNewMVA[15] << "\tH125a19= " << CutH125a19NewMVA[7] << "\tH125a9= " << CutH125a9NewMVA[7] << "\tH125a5= " << CutH125a5NewMVA[7] << "\tH750a9= " << CutH750a9NewMVA[7] << std::endl;	
  infoFile << CutLabelsBack[16] << "\t: DY= " << CutDYNewMVA[16] << "\tDY10-50= " << CutDYLowNewMVA[16] << "\tTT= " << CutTTNewMVA[16] << "\tWJ= " << CutWJNewMVA[16] << "\tWZ= " << CutWZNewMVA[16] << "\tZZ= " << CutZZNewMVA[16] << "\tH125a19= " << CutH125a19NewMVA[8] << "\tH125a9= " << CutH125a9NewMVA[8] << "\tH125a5= " << CutH125a5NewMVA[8] << "\tH750a9= " << CutH750a9NewMVA[8] << std::endl;
  infoFile << CutLabelsBack[16] << "\t: DY= " << CutDYNewMVA[16] << "\tDY10-50= " << CutDYLowNewMVA[16] << "\tTT= " << CutTTNewMVA[16] << "\tWJ= " << CutWJNewMVA[16] << "\tWZ= " << CutWZNewMVA[16] << "\tZZ= " << CutZZNewMVA[16] << "\tH125a19= " << CutH125a19NewMVA[8] << "\tH125a9= " << CutH125a9NewMVA[8] << "\tH125a5= " << CutH125a5NewMVA[8] << "\tH750a9= " << CutH750a9NewMVA[8] << std::endl;
  infoFile << CutLabelsBack[20] << "\t: DY= " << CutDYNewMVA[20] << "\tDY10-50= " << CutDYLowNewMVA[20] << "\tTT= " << CutTTNewMVA[20] << "\tWJ= " << CutWJNewMVA[20] << "\tWZ= " << CutWZNewMVA[20] << "\tZZ= " << CutZZNewMVA[20] << "\tH125a19= " << CutH125a19NewMVA[9] << "\tH125a9= " << CutH125a9NewMVA[9] << "\tH125a5= " << CutH125a5NewMVA[9] << "\tH750a9= " << CutH750a9NewMVA[9] << std::endl;
  infoFile << CutLabelsBack[21] << "\t: DY= " << CutDYNewMVA[21] << "\tDY10-50= " << CutDYLowNewMVA[21] << "\tTT= " << CutTTNewMVA[21] << "\tWJ= " << CutWJNewMVA[21] << "\tWZ= " << CutWZNewMVA[21] << "\tZZ= " << CutZZNewMVA[21] << "\tH125a19= " << CutH125a19NewMVA[0] << "\tH125a9= " << CutH125a9NewMVA[0] << "\tH125a5= " << CutH125a5NewMVA[0] << "\tH750a9= " << CutH750a9NewMVA[0] << std::endl;

  /////////////////////////////////
  // Writing Output New 
  /////////////////////////////////
  infoFile << "################################################\n## Cut Info for New DM  \n################################################" << endl;
  infoFile << "nEvents with RemovedMuon: DY= " << CutDYNew[0] << "\tTT= " << "\tDYLow= " << CutDYLowNew[0] << CutTTNew[0] << "\tWJ= " << CutWJNew[0] << "\tWZ= " << CutWZNew[0] << "\tZZ= " << CutZZNew[0] << "\tH125a19= " << CutH125a19New[0] << "\tH125a9= " << CutH125a9New[0] << "\tH125a5= " << CutH125a5New[0] << "\tH750a9= " << CutH750a9New[0] << std::endl;
  infoFile << CutLabelsBack[18] << "\t: DY= " << CutDYNew[18] << "\tDY10-50= " << CutDYLowNew[18] << "\tTT= " << CutTTNew[18] << "\tWJ= " << CutWJNew[18] << "\tWZ= " << CutWZNew[18] << "\tZZ= " << CutZZNew[18] << std::endl;	
  infoFile << CutLabelsBack[1] << "\t: DY= " << CutDYNew[1] << "\tDY10-50= " << CutDYLowNew[1] << "\tTT= " << CutTTNew[1] << "\tWJ= " << CutWJNew[1] << "\tWZ= " << CutWZNew[1] << "\tZZ= " << CutZZNew[1] << std::endl;	
  infoFile << CutLabelsBack[2] << "\t: DY= " << CutDYNew[2] << "\tDY10-50= " << CutDYLowNew[2] << "\tTT= " << CutTTNew[2] << "\tWJ= " << CutWJNew[2] << "\tWZ= " << CutWZNew[2] << "\tZZ= " << CutZZNew[2] << std::endl;
  infoFile << CutLabelsBack[3] << "\t: DY= " << CutDYNew[3] << "\tDY10-50= " << CutDYLowNew[3] << "\tTT= " << CutTTNew[3] << "\tWJ= " << CutWJNew[3] << "\tWZ= " << CutWZNew[3] << "\tZZ= " << CutZZNew[3] << std::endl;
  infoFile << CutLabelsBack[4] << "\t: DY= " << CutDYNew[4] << "\tDY10-50= " << CutDYLowNew[4] << "\tTT= " << CutTTNew[4] << "\tWJ= " << CutWJNew[4] << "\tWZ= " << CutWZNew[4] << "\tZZ= " << CutZZNew[4] << std::endl;
  infoFile << CutLabelsBack[5] << "\t: DY= " << CutDYNew[5] << "\tDY10-50= " << CutDYLowNew[5] << "\tTT= " << CutTTNew[5] << "\tWJ= " << CutWJNew[5] << "\tWZ= " << CutWZNew[5] << "\tZZ= " << CutZZNew[5] << std::endl;
  infoFile << CutLabelsBack[6] << "\t: DY= " << CutDYNew[6] << "\tDY10-50= " << CutDYLowNew[6] << "\tTT= " << CutTTNew[6] << "\tWJ= " << CutWJNew[6] << "\tWZ= " << CutWZNew[6] << "\tZZ= " << CutZZNew[6] << std::endl;
  infoFile << CutLabelsBack[7] << "\t: DY= " << CutDYNew[7] << "\tDY10-50= " << CutDYLowNew[7] << "\tTT= " << CutTTNew[7] << "\tWJ= " << CutWJNew[7] << "\tWZ= " << CutWZNew[7] << "\tZZ= " << CutZZNew[7] << std::endl;
  infoFile << CutLabelsBack[8] << "\t: DY= " << CutDYNew[8] << "\tDY10-50= " << CutDYLowNew[8] << "\tTT= " << CutTTNew[8] << "\tWJ= " << CutWJNew[8] << "\tWZ= " << CutWZNew[8] << "\tZZ= " << CutZZNew[8] << std::endl;
  infoFile << CutLabelsBack[17] << "\t: DY= " << CutDYNew[17] << "\tDY10-50= " << CutDYLowNew[17] << "\tTT= " << CutTTNew[17] << "\tWJ= " << CutWJNew[17] << "\tWZ= " << CutWZNew[17] << "\tZZ= " << CutZZNew[17] << std::endl;	
  infoFile << CutLabelsBack[9] << "\t: DY= " << CutDYNew[9] << "\tDY10-50= " << CutDYLowNew[9] << "\tTT= " << CutTTNew[9] << "\tWJ= " << CutWJNew[9] << "\tWZ= " << CutWZNew[9] << "\tZZ= " << CutZZNew[9] << "\tH125a19= " << CutH125a19New[1] << "\tH125a9= " << CutH125a9New[1] << "\tH125a5= " << CutH125a5New[1] << "\tH750a9= " << CutH750a9New[1] << std::endl;
  infoFile << CutLabelsBack[10] << "\t: DY= " << CutDYNew[10] << "\tDY10-50= " << CutDYLowNew[10] << "\tTT= " << CutTTNew[10] << "\tWJ= " << CutWJNew[10] << "\tWZ= " << CutWZNew[10] << "\tZZ= " << CutZZNew[10] << "\tH125a19= " << CutH125a19New[2] << "\tH125a9= " << CutH125a9New[2] << "\tH125a5= " << CutH125a5New[2] << "\tH750a9= " << CutH750a9New[2] << std::endl;
  infoFile << CutLabelsBack[11] << "\t: DY= " << CutDYNew[11] << "\tDY10-50= " << CutDYLowNew[11] << "\tTT= " << CutTTNew[11] << "\tWJ= " << CutWJNew[11] << "\tWZ= " << CutWZNew[11] << "\tZZ= " << CutZZNew[11] << "\tH125a19= " << CutH125a19New[3] << "\tH125a9= " << CutH125a9New[3] << "\tH125a5= " << CutH125a5New[3] << "\tH750a9= " << CutH750a9New[3] << std::endl;
  infoFile << CutLabelsBack[12] << "\t: DY= " << CutDYNew[12] << "\tDY10-50= " << CutDYLowNew[12] << "\tTT= " << CutTTNew[12] << "\tWJ= " << CutWJNew[12] << "\tWZ= " << CutWZNew[12] << "\tZZ= " << CutZZNew[12] << "\tH125a19= " << CutH125a19New[4] << "\tH125a9= " << CutH125a9New[4] << "\tH125a5= " << CutH125a5New[4] << "\tH750a9= " << CutH750a9New[4] << std::endl;
  infoFile << CutLabelsBack[13] << "\t: DY= " << CutDYNew[13] << "\tDY10-50= " << CutDYLowNew[13] << "\tTT= " << CutTTNew[13] << "\tWJ= " << CutWJNew[13] << "\tWZ= " << CutWZNew[13] << "\tZZ= " << CutZZNew[13] << "\tH125a19= " << CutH125a19New[5] << "\tH125a9= " << CutH125a9New[5] << "\tH125a5= " << CutH125a5New[5] << "\tH750a9= " << CutH750a9New[5] << std::endl;	
  infoFile << CutLabelsBack[14] << "\t: DY= " << CutDYNew[14] << "\tDY10-50= " << CutDYLowNew[14] << "\tTT= " << CutTTNew[14] << "\tWJ= " << CutWJNew[14] << "\tWZ= " << CutWZNew[14] << "\tZZ= " << CutZZNew[14] << "\tH125a19= " << CutH125a19New[6] << "\tH125a9= " << CutH125a9New[6] << "\tH125a5= " << CutH125a5New[6] << "\tH750a9= " << CutH750a9New[6] << std::endl;	
  infoFile << CutLabelsBack[15] << "\t: DY= " << CutDYNew[15] << "\tDY10-50= " << CutDYLowNew[15] << "\tTT= " << CutTTNew[15] << "\tWJ= " << CutWJNew[15] << "\tWZ= " << CutWZNew[15] << "\tZZ= " << CutZZNew[15] << "\tH125a19= " << CutH125a19New[7] << "\tH125a9= " << CutH125a9New[7] << "\tH125a5= " << CutH125a5New[7] << "\tH750a9= " << CutH750a9New[7] << std::endl;	
  infoFile << CutLabelsBack[16] << "\t: DY= " << CutDYNew[16] << "\tDY10-50= " << CutDYLowNew[16] << "\tTT= " << CutTTNew[16] << "\tWJ= " << CutWJNew[16] << "\tWZ= " << CutWZNew[16] << "\tZZ= " << CutZZNew[16] << "\tH125a19= " << CutH125a19New[8] << "\tH125a9= " << CutH125a9New[8] << "\tH125a5= " << CutH125a5New[8] << "\tH750a9= " << CutH750a9New[8] << std::endl;
  infoFile << CutLabelsBack[20] << "\t: DY= " << CutDYNew[20] << "\tDY10-50= " << CutDYLowNew[20] << "\tTT= " << CutTTNew[20] << "\tWJ= " << CutWJNew[20] << "\tWZ= " << CutWZNew[20] << "\tZZ= " << CutZZNew[20] << "\tH125a19= " << CutH125a19New[9] << "\tH125a9= " << CutH125a9New[9] << "\tH125a5= " << CutH125a5New[9] << "\tH750a9= " << CutH750a9New[9] << std::endl;
  infoFile << CutLabelsBack[21] << "\t: DY= " << CutDYNew[21] << "\tDY10-50= " << CutDYLowNew[21] << "\tTT= " << CutTTNew[21] << "\tWJ= " << CutWJNew[21] << "\tWZ= " << CutWZNew[21] << "\tZZ= " << CutZZNew[21] << "\tH125a19= " << CutH125a19New[0] << "\tH125a9= " << CutH125a9New[0] << "\tH125a5= " << CutH125a5New[0] << "\tH750a9= " << CutH750a9New[0] << std::endl;

  /////////////////////////////////
  // Writing Output Old + MVA
  /////////////////////////////////
  infoFile << "################################################\n## Cut Info for Old DM + MVA \n################################################" << endl;
  infoFile << "nEvents with RemovedMuon: DY= " << CutDYOldMVA[0] << "\tDYLow= " << CutDYLowOldMVA[0] << "\tTT= " << CutTTOldMVA[0] << "\tWJ= " << CutWJOldMVA[0] << "\tWZ= " << CutWZOldMVA[0] << "\tZZ= " << CutZZOldMVA[0] << "\tH125a19= " << CutH125a19OldMVA[0] << "\tH125a9= " << CutH125a9OldMVA[0] << "\tH125a5= " << CutH125a5OldMVA[0] << "\tH750a9= " << CutH750a9OldMVA[0] << std::endl;
  infoFile << CutLabelsBack[18] << "\t: DY= " << CutDYOldMVA[18] << "\tDY10-50= " << CutDYLowOldMVA[18] << "\tTT= " << CutTTOldMVA[18] << "\tWJ= " << CutWJOldMVA[18] << "\tWZ= " << CutWZOldMVA[18] << "\tZZ= " << CutZZOldMVA[18] << std::endl;	
  infoFile << CutLabelsBack[1] << "\t: DY= " << CutDYOldMVA[1] << "\tDY10-50= " << CutDYLowOldMVA[1] << "\tTT= " << CutTTOldMVA[1] << "\tWJ= " << CutWJOldMVA[1] << "\tWZ= " << CutWZOldMVA[1] << "\tZZ= " << CutZZOldMVA[1] << std::endl;	
  infoFile << CutLabelsBack[2] << "\t: DY= " << CutDYOldMVA[2] << "\tDY10-50= " << CutDYLowOldMVA[2] << "\tTT= " << CutTTOldMVA[2] << "\tWJ= " << CutWJOldMVA[2] << "\tWZ= " << CutWZOldMVA[2] << "\tZZ= " << CutZZOldMVA[2] << std::endl;
  infoFile << CutLabelsBack[3] << "\t: DY= " << CutDYOldMVA[3] << "\tDY10-50= " << CutDYLowOldMVA[3] << "\tTT= " << CutTTOldMVA[3] << "\tWJ= " << CutWJOldMVA[3] << "\tWZ= " << CutWZOldMVA[3] << "\tZZ= " << CutZZOldMVA[3] << std::endl;
  infoFile << CutLabelsBack[4] << "\t: DY= " << CutDYOldMVA[4] << "\tDY10-50= " << CutDYLowOldMVA[4] << "\tTT= " << CutTTOldMVA[4] << "\tWJ= " << CutWJOldMVA[4] << "\tWZ= " << CutWZOldMVA[4] << "\tZZ= " << CutZZOldMVA[4] << std::endl;
  infoFile << CutLabelsBack[5] << "\t: DY= " << CutDYOldMVA[5] << "\tDY10-50= " << CutDYLowOldMVA[5] << "\tTT= " << CutTTOldMVA[5] << "\tWJ= " << CutWJOldMVA[5] << "\tWZ= " << CutWZOldMVA[5] << "\tZZ= " << CutZZOldMVA[5] << std::endl;
  infoFile << CutLabelsBack[6] << "\t: DY= " << CutDYOldMVA[6] << "\tDY10-50= " << CutDYLowOldMVA[6] << "\tTT= " << CutTTOldMVA[6] << "\tWJ= " << CutWJOldMVA[6] << "\tWZ= " << CutWZOldMVA[6] << "\tZZ= " << CutZZOldMVA[6] << std::endl;
  infoFile << CutLabelsBack[7] << "\t: DY= " << CutDYOldMVA[7] << "\tDY10-50= " << CutDYLowOldMVA[7] << "\tTT= " << CutTTOldMVA[7] << "\tWJ= " << CutWJOldMVA[7] << "\tWZ= " << CutWZOldMVA[7] << "\tZZ= " << CutZZOldMVA[7] << std::endl;
  infoFile << CutLabelsBack[8] << "\t: DY= " << CutDYOldMVA[8] << "\tDY10-50= " << CutDYLowOldMVA[8] << "\tTT= " << CutTTOldMVA[8] << "\tWJ= " << CutWJOldMVA[8] << "\tWZ= " << CutWZOldMVA[8] << "\tZZ= " << CutZZOldMVA[8] << std::endl;
  infoFile << CutLabelsBack[17] << "\t: DY= " << CutDYOldMVA[17] << "\tDY10-50= " << CutDYLowOldMVA[17] << "\tTT= " << CutTTOldMVA[17] << "\tWJ= " << CutWJOldMVA[17] << "\tWZ= " << CutWZOldMVA[17] << "\tZZ= " << CutZZOldMVA[17] << std::endl;	
  infoFile << CutLabelsBack[9] << "\t: DY= " << CutDYOldMVA[9] << "\tDY10-50= " << CutDYLowOldMVA[9] << "\tTT= " << CutTTOldMVA[9] << "\tWJ= " << CutWJOldMVA[9] << "\tWZ= " << CutWZOldMVA[9] << "\tZZ= " << CutZZOldMVA[9] << "\tH125a19= " << CutH125a19OldMVA[1] << "\tH125a9= " << CutH125a9OldMVA[1] << "\tH125a5= " << CutH125a5OldMVA[1] << "\tH750a9= " << CutH750a9OldMVA[1] << std::endl;
  infoFile << CutLabelsBack[10] << "\t: DY= " << CutDYOldMVA[10] << "\tDY10-50= " << CutDYLowOldMVA[10] << "\tTT= " << CutTTOldMVA[10] << "\tWJ= " << CutWJOldMVA[10] << "\tWZ= " << CutWZOldMVA[10] << "\tZZ= " << CutZZOldMVA[10] << "\tH125a19= " << CutH125a19OldMVA[2] << "\tH125a9= " << CutH125a9OldMVA[2] << "\tH125a5= " << CutH125a5OldMVA[2] << "\tH750a9= " << CutH750a9OldMVA[2] << std::endl;
  infoFile << CutLabelsBack[11] << "\t: DY= " << CutDYOldMVA[11] << "\tDY10-50= " << CutDYLowOldMVA[11] << "\tTT= " << CutTTOldMVA[11] << "\tWJ= " << CutWJOldMVA[11] << "\tWZ= " << CutWZOldMVA[11] << "\tZZ= " << CutZZOldMVA[11] << "\tH125a19= " << CutH125a19OldMVA[3] << "\tH125a9= " << CutH125a9OldMVA[3] << "\tH125a5= " << CutH125a5OldMVA[3] << "\tH750a9= " << CutH750a9OldMVA[3] << std::endl;
  infoFile << CutLabelsBack[12] << "\t: DY= " << CutDYOldMVA[12] << "\tDY10-50= " << CutDYLowOldMVA[12] << "\tTT= " << CutTTOldMVA[12] << "\tWJ= " << CutWJOldMVA[12] << "\tWZ= " << CutWZOldMVA[12] << "\tZZ= " << CutZZOldMVA[12] << "\tH125a19= " << CutH125a19OldMVA[4] << "\tH125a9= " << CutH125a9OldMVA[4] << "\tH125a5= " << CutH125a5OldMVA[4] << "\tH750a9= " << CutH750a9OldMVA[4] << std::endl;
  infoFile << CutLabelsBack[13] << "\t: DY= " << CutDYOldMVA[13] << "\tDY10-50= " << CutDYLowOldMVA[13] << "\tTT= " << CutTTOldMVA[13] << "\tWJ= " << CutWJOldMVA[13] << "\tWZ= " << CutWZOldMVA[13] << "\tZZ= " << CutZZOldMVA[13] << "\tH125a19= " << CutH125a19OldMVA[5] << "\tH125a9= " << CutH125a9OldMVA[5] << "\tH125a5= " << CutH125a5OldMVA[5] << "\tH750a9= " << CutH750a9OldMVA[5] << std::endl;	
  infoFile << CutLabelsBack[14] << "\t: DY= " << CutDYOldMVA[14] << "\tDY10-50= " << CutDYLowOldMVA[14] << "\tTT= " << CutTTOldMVA[14] << "\tWJ= " << CutWJOldMVA[14] << "\tWZ= " << CutWZOldMVA[14] << "\tZZ= " << CutZZOldMVA[14] << "\tH125a19= " << CutH125a19OldMVA[6] << "\tH125a9= " << CutH125a9OldMVA[6] << "\tH125a5= " << CutH125a5OldMVA[6] << "\tH750a9= " << CutH750a9OldMVA[6] << std::endl;	
  infoFile << CutLabelsBack[15] << "\t: DY= " << CutDYOldMVA[15] << "\tDY10-50= " << CutDYLowOldMVA[15] << "\tTT= " << CutTTOldMVA[15] << "\tWJ= " << CutWJOldMVA[15] << "\tWZ= " << CutWZOldMVA[15] << "\tZZ= " << CutZZOldMVA[15] << "\tH125a19= " << CutH125a19OldMVA[7] << "\tH125a9= " << CutH125a9OldMVA[7] << "\tH125a5= " << CutH125a5OldMVA[7] << "\tH750a9= " << CutH750a9OldMVA[7] << std::endl;	
  infoFile << CutLabelsBack[16] << "\t: DY= " << CutDYOldMVA[16] << "\tDY10-50= " << CutDYLowOldMVA[16] << "\tTT= " << CutTTOldMVA[16] << "\tWJ= " << CutWJOldMVA[16] << "\tWZ= " << CutWZOldMVA[16] << "\tZZ= " << CutZZOldMVA[16] << "\tH125a19= " << CutH125a19OldMVA[8] << "\tH125a9= " << CutH125a9OldMVA[8] << "\tH125a5= " << CutH125a5OldMVA[8] << "\tH750a9= " << CutH750a9OldMVA[8] << std::endl;
  infoFile << CutLabelsBack[20] << "\t: DY= " << CutDYOldMVA[20] << "\tDY10-50= " << CutDYLowOldMVA[20] << "\tTT= " << CutTTOldMVA[20] << "\tWJ= " << CutWJOldMVA[20] << "\tWZ= " << CutWZOldMVA[20] << "\tZZ= " << CutZZOldMVA[20] << "\tH125a19= " << CutH125a19OldMVA[9] << "\tH125a9= " << CutH125a9OldMVA[9] << "\tH125a5= " << CutH125a5OldMVA[9] << "\tH750a9= " << CutH750a9OldMVA[9] << std::endl;
  infoFile << CutLabelsBack[21] << "\t: DY= " << CutDYOldMVA[21] << "\tDY10-50= " << CutDYLowOldMVA[21] << "\tTT= " << CutTTOldMVA[21] << "\tWJ= " << CutWJOldMVA[21] << "\tWZ= " << CutWZOldMVA[21] << "\tZZ= " << CutZZOldMVA[21] << "\tH125a19= " << CutH125a19OldMVA[0] << "\tH125a9= " << CutH125a9OldMVA[0] << "\tH125a5= " << CutH125a5OldMVA[0] << "\tH750a9= " << CutH750a9OldMVA[0] << std::endl;

  /////////////////////////////////
  // Writing Output Old 
  /////////////////////////////////
  infoFile << "################################################\n## Cut Info for Old DM \n################################################" << endl;
  infoFile << "nEvents with RemovedMuon: DY= " << CutDYOld[0] << "\tDYLow= " << CutDYLowOld[0] << "\tTT= " << CutTTOld[0] << "\tWJ= " << CutWJOld[0] << "\tWZ= " << CutWZOld[0] << "\tZZ= " << CutZZOld[0] << "\tH125a19= " << CutH125a19Old[0] << "\tH125a9= " << CutH125a9Old[0] << "\tH125a5= " << CutH125a5Old[0] << "\tH750a9= " << CutH750a9Old[0] << std::endl;
  infoFile << CutLabelsBack[18] << "\t: DY= " << CutDYOld[18] << "\tDY10-50= " << CutDYLowOld[18] << "\tTT= " << CutTTOld[18] << "\tWJ= " << CutWJOld[18] << "\tWZ= " << CutWZOld[18] << "\tZZ= " << CutZZOld[18] << std::endl;	
  infoFile << CutLabelsBack[1] << "\t: DY= " << CutDYOld[1] << "\tDY10-50= " << CutDYLowOld[1] << "\tTT= " << CutTTOld[1] << "\tWJ= " << CutWJOld[1] << "\tWZ= " << CutWZOld[1] << "\tZZ= " << CutZZOld[1] << std::endl;	
  infoFile << CutLabelsBack[2] << "\t: DY= " << CutDYOld[2] << "\tDY10-50= " << CutDYLowOld[2] << "\tTT= " << CutTTOld[2] << "\tWJ= " << CutWJOld[2] << "\tWZ= " << CutWZOld[2] << "\tZZ= " << CutZZOld[2] << std::endl;
  infoFile << CutLabelsBack[3] << "\t: DY= " << CutDYOld[3] << "\tDY10-50= " << CutDYLowOld[3] << "\tTT= " << CutTTOld[3] << "\tWJ= " << CutWJOld[3] << "\tWZ= " << CutWZOld[3] << "\tZZ= " << CutZZOld[3] << std::endl;
  infoFile << CutLabelsBack[4] << "\t: DY= " << CutDYOld[4] << "\tDY10-50= " << CutDYLowOld[4] << "\tTT= " << CutTTOld[4] << "\tWJ= " << CutWJOld[4] << "\tWZ= " << CutWZOld[4] << "\tZZ= " << CutZZOld[4] << std::endl;
  infoFile << CutLabelsBack[5] << "\t: DY= " << CutDYOld[5] << "\tDY10-50= " << CutDYLowOld[5] << "\tTT= " << CutTTOld[5] << "\tWJ= " << CutWJOld[5] << "\tWZ= " << CutWZOld[5] << "\tZZ= " << CutZZOld[5] << std::endl;
  infoFile << CutLabelsBack[6] << "\t: DY= " << CutDYOld[6] << "\tDY10-50= " << CutDYLowOld[6] << "\tTT= " << CutTTOld[6] << "\tWJ= " << CutWJOld[6] << "\tWZ= " << CutWZOld[6] << "\tZZ= " << CutZZOld[6] << std::endl;
  infoFile << CutLabelsBack[7] << "\t: DY= " << CutDYOld[7] << "\tDY10-50= " << CutDYLowOld[7] << "\tTT= " << CutTTOld[7] << "\tWJ= " << CutWJOld[7] << "\tWZ= " << CutWZOld[7] << "\tZZ= " << CutZZOld[7] << std::endl;
  infoFile << CutLabelsBack[8] << "\t: DY= " << CutDYOld[8] << "\tDY10-50= " << CutDYLowOld[8] << "\tTT= " << CutTTOld[8] << "\tWJ= " << CutWJOld[8] << "\tWZ= " << CutWZOld[8] << "\tZZ= " << CutZZOld[8] << std::endl;
  infoFile << CutLabelsBack[17] << "\t: DY= " << CutDYOld[17] << "\tDY10-50= " << CutDYLowOld[17] << "\tTT= " << CutTTOld[17] << "\tWJ= " << CutWJOld[17] << "\tWZ= " << CutWZOld[17] << "\tZZ= " << CutZZOld[17] << std::endl;	
  infoFile << CutLabelsBack[9] << "\t: DY= " << CutDYOld[9] << "\tDY10-50= " << CutDYLowOld[9] << "\tTT= " << CutTTOld[9] << "\tWJ= " << CutWJOld[9] << "\tWZ= " << CutWZOld[9] << "\tZZ= " << CutZZOld[9] << "\tH125a19= " << CutH125a19Old[1] << "\tH125a9= " << CutH125a9Old[1] << "\tH125a5= " << CutH125a5Old[1] << "\tH750a9= " << CutH750a9Old[1] << std::endl;
  infoFile << CutLabelsBack[10] << "\t: DY= " << CutDYOld[10] << "\tDY10-50= " << CutDYLowOld[10] << "\tTT= " << CutTTOld[10] << "\tWJ= " << CutWJOld[10] << "\tWZ= " << CutWZOld[10] << "\tZZ= " << CutZZOld[10] << "\tH125a19= " << CutH125a19Old[2] << "\tH125a9= " << CutH125a9Old[2] << "\tH125a5= " << CutH125a5Old[2] << "\tH750a9= " << CutH750a9Old[2] << std::endl;
  infoFile << CutLabelsBack[11] << "\t: DY= " << CutDYOld[11] << "\tDY10-50= " << CutDYLowOld[11] << "\tTT= " << CutTTOld[11] << "\tWJ= " << CutWJOld[11] << "\tWZ= " << CutWZOld[11] << "\tZZ= " << CutZZOld[11] << "\tH125a19= " << CutH125a19Old[3] << "\tH125a9= " << CutH125a9Old[3] << "\tH125a5= " << CutH125a5Old[3] << "\tH750a9= " << CutH750a9Old[3] << std::endl;
  infoFile << CutLabelsBack[12] << "\t: DY= " << CutDYOld[12] << "\tDY10-50= " << CutDYLowOld[12] << "\tTT= " << CutTTOld[12] << "\tWJ= " << CutWJOld[12] << "\tWZ= " << CutWZOld[12] << "\tZZ= " << CutZZOld[12] << "\tH125a19= " << CutH125a19Old[4] << "\tH125a9= " << CutH125a9Old[4] << "\tH125a5= " << CutH125a5Old[4] << "\tH750a9= " << CutH750a9Old[4] << std::endl;
  infoFile << CutLabelsBack[13] << "\t: DY= " << CutDYOld[13] << "\tDY10-50= " << CutDYLowOld[13] << "\tTT= " << CutTTOld[13] << "\tWJ= " << CutWJOld[13] << "\tWZ= " << CutWZOld[13] << "\tZZ= " << CutZZOld[13] << "\tH125a19= " << CutH125a19Old[5] << "\tH125a9= " << CutH125a9Old[5] << "\tH125a5= " << CutH125a5Old[5] << "\tH750a9= " << CutH750a9Old[5] << std::endl;	
  infoFile << CutLabelsBack[14] << "\t: DY= " << CutDYOld[14] << "\tDY10-50= " << CutDYLowOld[14] << "\tTT= " << CutTTOld[14] << "\tWJ= " << CutWJOld[14] << "\tWZ= " << CutWZOld[14] << "\tZZ= " << CutZZOld[14] << "\tH125a19= " << CutH125a19Old[6] << "\tH125a9= " << CutH125a9Old[6] << "\tH125a5= " << CutH125a5Old[6] << "\tH750a9= " << CutH750a9Old[6] << std::endl;	
  infoFile << CutLabelsBack[15] << "\t: DY= " << CutDYOld[15] << "\tDY10-50= " << CutDYLowOld[15] << "\tTT= " << CutTTOld[15] << "\tWJ= " << CutWJOld[15] << "\tWZ= " << CutWZOld[15] << "\tZZ= " << CutZZOld[15] << "\tH125a19= " << CutH125a19Old[7] << "\tH125a9= " << CutH125a9Old[7] << "\tH125a5= " << CutH125a5Old[7] << "\tH750a9= " << CutH750a9Old[7] << std::endl;	
  infoFile << CutLabelsBack[16] << "\t: DY= " << CutDYOld[16] << "\tDY10-50= " << CutDYLowOld[16] << "\tTT= " << CutTTOld[16] << "\tWJ= " << CutWJOld[16] << "\tWZ= " << CutWZOld[16] << "\tZZ= " << CutZZOld[16] << "\tH125a19= " << CutH125a19Old[8] << "\tH125a9= " << CutH125a9Old[8] << "\tH125a5= " << CutH125a5Old[8] << "\tH750a9= " << CutH750a9Old[8] << std::endl;
  infoFile << CutLabelsBack[20] << "\t: DY= " << CutDYOld[20] << "\tDY10-50= " << CutDYLowOld[20] << "\tTT= " << CutTTOld[20] << "\tWJ= " << CutWJOld[20] << "\tWZ= " << CutWZOld[20] << "\tZZ= " << CutZZOld[20] << "\tH125a19= " << CutH125a19Old[9] << "\tH125a9= " << CutH125a9Old[9] << "\tH125a5= " << CutH125a5Old[9] << "\tH750a9= " << CutH750a9Old[9] << std::endl;
  infoFile << CutLabelsBack[21] << "\t: DY= " << CutDYOld[21] << "\tDY10-50= " << CutDYLowOld[21] << "\tTT= " << CutTTOld[21] << "\tWJ= " << CutWJOld[21] << "\tWZ= " << CutWZOld[21] << "\tZZ= " << CutZZOld[21] << "\tH125a19= " << CutH125a19Old[0] << "\tH125a9= " << CutH125a9Old[0] << "\tH125a5= " << CutH125a5Old[0] << "\tH750a9= " << CutH750a9Old[0] << std::endl;

std::cout << "Writing Tau DM output." << std::endl;


  //////////////////////////
  // Writing TT information
  //////////////////////////
  infoFile << "\n############################################\n## TTbar || Total Number of Events:\n## NewMVA= " << CountTTNewMVA[4] << "\tNew= " << CountTTNew[4] << "\tOldMVA= ";
  infoFile << CountTTOldMVA[4] << "\tOld= " << CountTTOld[4] << "\n#############################################" << endl;
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountTTNew[3] << "\t\t| " << CountTTNewMVA[0] << "\t\t| " << CountTTNew[0] << "\t\t| " << CountTTOldMVA[0] << "\t\t| " << CountTTOld[0] << endl;
  infoFile << "Med:   | " << CountTTNew[3] << "\t\t| " << CountTTNewMVA[1] << "\t\t| " << CountTTNew[1] << "\t\t| " << CountTTOldMVA[1] << "\t\t| " << CountTTOld[1] << endl; 
  infoFile << "Tight: | " << CountTTNew[3] << "\t\t| " << CountTTNewMVA[2] << "\t\t| " << CountTTNew[2] << "\t\t| " << CountTTOldMVA[2] << "\t\t| " << CountTTOld[2] << endl;


  //////////////////////////
  // Writing DY information
  //////////////////////////
  infoFile << "\n############################################\n## DY m = 50 || Total Number of Events:\n## NewMVA= " << CountDYNewMVA[4] << "\tNew= " << CountDYNew[4] << "\tOldMVA= ";
  infoFile << CountDYOldMVA[4] << "\tOld= " << CountDYOld[4] << "\n#############################################" << endl; 
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountDYNew[3] << "\t\t| " << CountDYNewMVA[0] << "\t\t| " << CountDYNew[0] << "\t\t| " << CountDYOldMVA[0] << "\t\t| " << CountDYOld[0] << endl;
  infoFile << "Med:   | " << CountDYNew[3] << "\t\t| " << CountDYNewMVA[1] << "\t\t| " << CountDYNew[1] << "\t\t| " << CountDYOldMVA[1] << "\t\t| " << CountDYOld[1] << endl; 
  infoFile << "Tight: | " << CountDYNew[3] << "\t\t| " << CountDYNewMVA[2] << "\t\t| " << CountDYNew[2] << "\t\t| " << CountDYOldMVA[2] << "\t\t| " << CountDYOld[2] << endl;


  //////////////////////////
  // Writing DYLow information
  //////////////////////////
  infoFile << "\n############################################\n## DY m = 10-50 || Total Number of Events:\n## NewMVA= " << CountDYLowNewMVA[4] << "\tNew= " << CountDYLowNew[4] << "\tOldMVA= ";
  infoFile << CountDYLowOldMVA[4] << "\tOld= " << CountDYLowOld[4] << "\n#############################################" << endl;
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountDYLowNew[3] << "\t\t| " << CountDYLowNewMVA[0] << "\t\t| " << CountDYLowNew[0] << "\t\t| " << CountDYLowOldMVA[0] << "\t\t| " << CountDYLowOld[0] << endl;
  infoFile << "Med:   | " << CountDYLowNew[3] << "\t\t| " << CountDYLowNewMVA[1] << "\t\t| " << CountDYLowNew[1] << "\t\t| " << CountDYLowOldMVA[1] << "\t\t| " << CountDYLowOld[1] << endl;
  infoFile << "Tight: | " << CountDYLowNew[3] << "\t\t| " << CountDYLowNewMVA[2] << "\t\t| " << CountDYLowNew[2] << "\t\t| " << CountDYLowOldMVA[2] << "\t\t| " << CountDYLowOld[2] << endl;

  //////////////////////////
  // Writing WJ information
  //////////////////////////
  infoFile << "\n############################################\n## WJ || Total Number of Events:\n## NewMVA= " << CountWJNewMVA[4] << "\tNew= " << CountWJNew[4] << "\tOldMVA= ";
  infoFile << CountWJOldMVA[4] << "\tOld= " << CountWJOld[4] << "\n#############################################" << endl; 
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountWJNew[3] << "\t\t| " << CountWJNewMVA[0] << "\t\t| " << CountWJNew[0] << "\t\t| " << CountWJOldMVA[0] << "\t\t| " << CountWJOld[0] << endl;
  infoFile << "Med:   | " << CountWJNew[3] << "\t\t| " << CountWJNewMVA[1] << "\t\t| " << CountWJNew[1] << "\t\t| " << CountWJOldMVA[1] << "\t\t| " << CountWJOld[1] << endl; 
  infoFile << "Tight: | " << CountWJNew[3] << "\t\t| " << CountWJNewMVA[2] << "\t\t| " << CountWJNew[2] << "\t\t| " << CountWJOldMVA[2] << "\t\t| " << CountWJOld[2] << endl;

  //////////////////////////
  // Writing WZ information
  //////////////////////////
  infoFile << "\n############################################\n## WZ || Total Number of Events:\n## NewMVA= " << CountWZNewMVA[4] << "\tNew= " << CountWZNew[4] << "\tOldMVA= ";
  infoFile << CountWZOldMVA[4] << "\tOld= " << CountWZOld[4] << "\n#############################################" << endl; 
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountWZNew[3] << "\t\t| " << CountWZNewMVA[0] << "\t\t| " << CountWZNew[0] << "\t\t| " << CountWZOldMVA[0] << "\t\t| " << CountWZOld[0] << endl;
  infoFile << "Med:   | " << CountWZNew[3] << "\t\t| " << CountWZNewMVA[1] << "\t\t| " << CountWZNew[1] << "\t\t| " << CountWZOldMVA[1] << "\t\t| " << CountWZOld[1] << endl; 
  infoFile << "Tight: | " << CountWZNew[3] << "\t\t| " << CountWZNewMVA[2] << "\t\t| " << CountWZNew[2] << "\t\t| " << CountWZOldMVA[2] << "\t\t| " << CountWZOld[2] << endl;

  //////////////////////////
  // Writing ZZ information
  //////////////////////////
  infoFile << "\n############################################\n## ZZ || Total Number of Events:\n## NewMVA= " << CountZZNewMVA[4] << "\tNew= " << CountZZNew[4] << "\tOldMVA= ";
  infoFile << CountZZOldMVA[4] << "\tOld= " << CountZZOld[4] << "\n#############################################" << endl; 
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountZZNew[3] << "\t\t| " << CountZZNewMVA[0] << "\t\t| " << CountZZNew[0] << "\t\t| " << CountZZOldMVA[0] << "\t\t| " << CountZZOld[0] << endl;
  infoFile << "Med:   | " << CountZZNew[3] << "\t\t| " << CountZZNewMVA[1] << "\t\t| " << CountZZNew[1] << "\t\t| " << CountZZOldMVA[1] << "\t\t| " << CountZZOld[1] << endl; 
  infoFile << "Tight: | " << CountZZNew[3] << "\t\t| " << CountZZNewMVA[2] << "\t\t| " << CountZZNew[2] << "\t\t| " << CountZZOldMVA[2] << "\t\t| " << CountZZOld[2] << endl;

  //////////////////////////
  // Writing H125a19 information
  //////////////////////////
  infoFile << "\n############################################\n## H125a19 || Total Number of Events:\n## NewMVA= " << CountH125a19NewMVA[4] << "\tNew= " << CountH125a19New[4] << "\tOldMVA= ";
  infoFile << CountH125a19OldMVA[4] << "\tOld= " << CountH125a19Old[4] << "\n#############################################" << endl; 
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH125a19New[3] << "\t\t| " << CountH125a19NewMVA[0] << "\t\t| " << CountH125a19New[0] << "\t\t| " << CountH125a19OldMVA[0] << "\t\t| " << CountH125a19Old[0] << endl;
  infoFile << "Med:   | " << CountH125a19New[3] << "\t\t| " << CountH125a19NewMVA[1] << "\t\t| " << CountH125a19New[1] << "\t\t| " << CountH125a19OldMVA[1] << "\t\t| " << CountH125a19Old[1] << endl; 
  infoFile << "Tight: | " << CountH125a19New[3] << "\t\t| " << CountH125a19NewMVA[2] << "\t\t| " << CountH125a19New[2] << "\t\t| " << CountH125a19OldMVA[2] << "\t\t| " << CountH125a19Old[2] << endl;

  //////////////////////////
  // Writing H125a9 information
  //////////////////////////
  infoFile << "\n############################################\n## H125a9 || Total Number of Events:\n## NewMVA= " << CountH125a9NewMVA[4] << "\tNew= " << CountH125a9New[4] << "\tOldMVA= ";
  infoFile << CountH125a9OldMVA[4] << "\tOld= " << CountH125a9Old[4] << "\n#############################################" << endl; 
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH125a9New[3] << "\t\t| " << CountH125a9NewMVA[0] << "\t\t| " << CountH125a9New[0] << "\t\t| " << CountH125a9OldMVA[0] << "\t\t| " << CountH125a9Old[0] << endl;
  infoFile << "Med:   | " << CountH125a9New[3] << "\t\t| " << CountH125a9NewMVA[1] << "\t\t| " << CountH125a9New[1] << "\t\t| " << CountH125a9OldMVA[1] << "\t\t| " << CountH125a9Old[1] << endl; 
  infoFile << "Tight: | " << CountH125a9New[3] << "\t\t| " << CountH125a9NewMVA[2] << "\t\t| " << CountH125a9New[2] << "\t\t| " << CountH125a9OldMVA[2] << "\t\t| " << CountH125a9Old[2] << endl;
  
  //////////////////////////
  // Writing H125a5 information
  //////////////////////////
  infoFile << "\n############################################\n## H125a5 || Total Number of Events:\n## NewMVA= " << CountH125a5NewMVA[4] << "\tNew= " << CountH125a5New[4] << "\tOldMVA= ";
  infoFile << CountH125a5OldMVA[4] << "\tOld= " << CountH125a5Old[4] << "\n#############################################" << endl; 
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH125a5New[3] << "\t\t| " << CountH125a5NewMVA[0] << "\t\t| " << CountH125a5New[0] << "\t\t| " << CountH125a5OldMVA[0] << "\t\t| " << CountH125a5Old[0] << endl;
  infoFile << "Med:   | " << CountH125a5New[3] << "\t\t| " << CountH125a5NewMVA[1] << "\t\t| " << CountH125a5New[1] << "\t\t| " << CountH125a5OldMVA[1] << "\t\t| " << CountH125a5Old[1] << endl; 
  infoFile << "Tight: | " << CountH125a5New[3] << "\t\t| " << CountH125a5NewMVA[2] << "\t\t| " << CountH125a5New[2] << "\t\t| " << CountH125a5OldMVA[2] << "\t\t| " << CountH125a5Old[2] << endl;

  //////////////////////////
  // Writing H750a9 information
  //////////////////////////
  infoFile << "\n############################################\n## H750a9 || Total Number of Events:\n## NewMVA= " << CountH750a9NewMVA[4] << "\tNew= " << CountH750a9New[4] << "\tOldMVA= ";
  infoFile << CountH750a9OldMVA[4] << "\tOld= " << CountH750a9Old[4] << "\n#############################################" << endl; 
  infoFile << "Numbers of Events:" << endl;
  infoFile << "       | Removed Mu \t| New+MVA \t| New \t\t| Old+MVA \t| Old" << endl;
  infoFile << "Loose: | " << CountH750a9New[3] << "\t\t| " << CountH750a9NewMVA[0] << "\t\t| " << CountH750a9New[0] << "\t\t| " << CountH750a9OldMVA[0] << "\t\t| " << CountH750a9Old[0] << endl;
  infoFile << "Med:   | " << CountH750a9New[3] << "\t\t| " << CountH750a9NewMVA[1] << "\t\t| " << CountH750a9New[1] << "\t\t| " << CountH750a9OldMVA[1] << "\t\t| " << CountH750a9Old[1] << endl; 
  infoFile << "Tight: | " << CountH750a9New[3] << "\t\t| " << CountH750a9NewMVA[2] << "\t\t| " << CountH750a9New[2] << "\t\t| " << CountH750a9OldMVA[2] << "\t\t| " << CountH750a9Old[2] << endl;

std::cout << "Done writing output. Now plotting Signal to Background." << std::endl;

/////////////////////////////////////////////
// ALL SIG TO BACKGROUND PLOTS
////////////////////////////////////////////
  double backSum1Old = CutDYOld[1] + CutDYLowOld[1] + CutTTOld[1] + CutWZOld[1] + CutZZOld[1] + CutWJOld[1] + CutDYOld[10] + CutDYLowOld[10] + CutTTOld[10] + CutWZOld[10] + CutZZOld[10] + CutWJOld[10];
  double backSum2Old = CutDYOld[2] + CutDYLowOld[2] + CutTTOld[2] + CutWZOld[2] + CutZZOld[2] + CutWJOld[2] + CutDYOld[11] + CutDYLowOld[11] + CutTTOld[11] + CutWZOld[11] + CutZZOld[11] + CutWJOld[11];
  double backSum3Old = CutDYOld[3] + CutDYLowOld[3] + CutTTOld[3] + CutWZOld[1] + CutZZOld[3] + CutWJOld[3] + CutDYOld[12] + CutDYLowOld[12] + CutTTOld[12] + CutWZOld[12] + CutZZOld[12] + CutWJOld[12];
  double backSum4Old = CutDYOld[4] + CutDYLowOld[4] + CutTTOld[4] + CutWZOld[4] + CutZZOld[4] + CutWJOld[4] + CutDYOld[13] + CutDYLowOld[13] + CutTTOld[13] + CutWZOld[13] + CutZZOld[13] + CutWJOld[13];
  double backSum5Old = CutDYOld[5] + CutDYLowOld[5] + CutTTOld[5] + CutWZOld[5] + CutZZOld[5] + CutWJOld[5] + CutDYOld[14] + CutDYLowOld[14] + CutTTOld[14] + CutWZOld[14] + CutZZOld[14] + CutWJOld[14];
  double backSum6Old = CutDYOld[6] + CutDYLowOld[6] + CutTTOld[6] + CutWZOld[6] + CutZZOld[6] + CutWJOld[6] + CutDYOld[15] + CutDYLowOld[15] + CutTTOld[15] + CutWZOld[15] + CutZZOld[15] + CutWJOld[15];
  double backSum7Old = CutDYOld[7] + CutDYLowOld[7] + CutTTOld[7] + CutWZOld[7] + CutZZOld[7] + CutWJOld[7] + CutDYOld[16] + CutDYLowOld[16] + CutTTOld[16] + CutWZOld[16] + CutZZOld[16] + CutWJOld[16];
  double backSum8Old = CutDYOld[8] + CutDYLowOld[8] + CutTTOld[8] + CutWZOld[8] + CutZZOld[8] + CutWJOld[8] + CutDYOld[17] + CutDYLowOld[17] + CutTTOld[17] + CutWZOld[17] + CutZZOld[17] + CutWJOld[17];
  double backSum10Old = CutDYOld[21] + CutDYLowOld[21] + CutTTOld[21] + CutWZOld[21] + CutZZOld[21] + CutWJOld[21];
  double backSum9Old = CutDYOld[20] + CutDYLowOld[20] + CutTTOld[20] + CutWZOld[20] + CutZZOld[20] + CutWJOld[20];


  double backSum1OldMVA = CutDYOldMVA[1] + CutDYLowOldMVA[1] + CutTTOldMVA[1] + CutWZOldMVA[1] + CutZZOldMVA[1] + CutWJOldMVA[1] + CutDYOldMVA[10] + CutDYLowOldMVA[10] + CutTTOldMVA[10] + CutWZOldMVA[10] + CutZZOldMVA[10] + CutWJOldMVA[10];
  double backSum2OldMVA = CutDYOldMVA[2] + CutDYLowOldMVA[2] + CutTTOldMVA[2] + CutWZOldMVA[2] + CutZZOldMVA[2] + CutWJOldMVA[2] + CutDYOldMVA[11] + CutDYLowOldMVA[11] + CutTTOldMVA[11] + CutWZOldMVA[11] + CutZZOldMVA[11] + CutWJOldMVA[11];
  double backSum3OldMVA = CutDYOldMVA[3] + CutDYLowOldMVA[3] + CutTTOldMVA[3] + CutWZOldMVA[1] + CutZZOldMVA[3] + CutWJOldMVA[3] + CutDYOldMVA[12] + CutDYLowOldMVA[12] + CutTTOldMVA[12] + CutWZOldMVA[12] + CutZZOldMVA[12] + CutWJOldMVA[12];
  double backSum4OldMVA = CutDYOldMVA[4] + CutDYLowOldMVA[4] + CutTTOldMVA[4] + CutWZOldMVA[4] + CutZZOldMVA[4] + CutWJOldMVA[4] + CutDYOldMVA[13] + CutDYLowOldMVA[13] + CutTTOldMVA[13] + CutWZOldMVA[13] + CutZZOldMVA[13] + CutWJOldMVA[13];
  double backSum5OldMVA = CutDYOldMVA[5] + CutDYLowOldMVA[5] + CutTTOldMVA[5] + CutWZOldMVA[5] + CutZZOldMVA[5] + CutWJOldMVA[5] + CutDYOldMVA[14] + CutDYLowOldMVA[14] + CutTTOldMVA[14] + CutWZOldMVA[14] + CutZZOldMVA[14] + CutWJOldMVA[14];
  double backSum6OldMVA = CutDYOldMVA[6] + CutDYLowOldMVA[6] + CutTTOldMVA[6] + CutWZOldMVA[6] + CutZZOldMVA[6] + CutWJOldMVA[6] + CutDYOldMVA[15] + CutDYLowOldMVA[15] + CutTTOldMVA[15] + CutWZOldMVA[15] + CutZZOldMVA[15] + CutWJOldMVA[15];
  double backSum7OldMVA = CutDYOldMVA[7] + CutDYLowOldMVA[7] + CutTTOldMVA[7] + CutWZOldMVA[7] + CutZZOldMVA[7] + CutWJOldMVA[7] + CutDYOldMVA[16] + CutDYLowOldMVA[16] + CutTTOldMVA[16] + CutWZOldMVA[16] + CutZZOldMVA[16] + CutWJOldMVA[16];
  double backSum8OldMVA = CutDYOldMVA[8] + CutDYLowOldMVA[8] + CutTTOldMVA[8] + CutWZOldMVA[8] + CutZZOldMVA[8] + CutWJOldMVA[8] + CutDYOldMVA[17] + CutDYLowOldMVA[17] + CutTTOldMVA[17] + CutWZOldMVA[17] + CutZZOldMVA[17] + CutWJOldMVA[17];
  double backSum10OldMVA = CutDYOldMVA[21] + CutDYLowOldMVA[21] + CutTTOldMVA[21] + CutWZOldMVA[21] + CutZZOldMVA[21] + CutWJOldMVA[21];
  double backSum9OldMVA = CutDYOldMVA[20] + CutDYLowOldMVA[20] + CutTTOldMVA[20] + CutWZOldMVA[20] + CutZZOldMVA[20] + CutWJOldMVA[20];

  double backSum1New = CutDYNew[1] + CutDYLowNew[1] + CutTTNew[1] + CutWZNew[1] + CutZZNew[1] + CutWJNew[1] + CutDYNew[10] + CutDYLowNew[10] + CutTTNew[10] + CutWZNew[10] + CutZZNew[10] + CutWJNew[10];
  double backSum2New = CutDYNew[2] + CutDYLowNew[2] + CutTTNew[2] + CutWZNew[2] + CutZZNew[2] + CutWJNew[2] + CutDYNew[11] + CutDYLowNew[11] + CutTTNew[11] + CutWZNew[11] + CutZZNew[11] + CutWJNew[11];
  double backSum3New = CutDYNew[3] + CutDYLowNew[3] + CutTTNew[3] + CutWZNew[1] + CutZZNew[3] + CutWJNew[3] + CutDYNew[12] + CutDYLowNew[12] + CutTTNew[12] + CutWZNew[12] + CutZZNew[12] + CutWJNew[12];
  double backSum4New = CutDYNew[4] + CutDYLowNew[4] + CutTTNew[4] + CutWZNew[4] + CutZZNew[4] + CutWJNew[4] + CutDYNew[13] + CutDYLowNew[13] + CutTTNew[13] + CutWZNew[13] + CutZZNew[13] + CutWJNew[13];
  double backSum5New = CutDYNew[5] + CutDYLowNew[5] + CutTTNew[5] + CutWZNew[5] + CutZZNew[5] + CutWJNew[5] + CutDYNew[14] + CutDYLowNew[14] + CutTTNew[14] + CutWZNew[14] + CutZZNew[14] + CutWJNew[14];
  double backSum6New = CutDYNew[6] + CutDYLowNew[6] + CutTTNew[6] + CutWZNew[6] + CutZZNew[6] + CutWJNew[6] + CutDYNew[15] + CutDYLowNew[15] + CutTTNew[15] + CutWZNew[15] + CutZZNew[15] + CutWJNew[15];
  double backSum7New = CutDYNew[7] + CutDYLowNew[7] + CutTTNew[7] + CutWZNew[7] + CutZZNew[7] + CutWJNew[7] + CutDYNew[16] + CutDYLowNew[16] + CutTTNew[16] + CutWZNew[16] + CutZZNew[16] + CutWJNew[16];
  double backSum8New = CutDYNew[8] + CutDYLowNew[8] + CutTTNew[8] + CutWZNew[8] + CutZZNew[8] + CutWJNew[8] + CutDYNew[17] + CutDYLowNew[17] + CutTTNew[17] + CutWZNew[17] + CutZZNew[17] + CutWJNew[17];
  double backSum10New = CutDYNew[21] + CutDYLowNew[21] + CutTTNew[21] + CutWZNew[21] + CutZZNew[21] + CutWJNew[21];
  double backSum9New = CutDYNew[20] + CutDYLowNew[20] + CutTTNew[20] + CutWZNew[20] + CutZZNew[20] + CutWJNew[20];

  double backSum1NewMVA = CutDYNewMVA[1] + CutDYLowNewMVA[1] + CutTTNewMVA[1] + CutWZNewMVA[1] + CutZZNewMVA[1] + CutWJNewMVA[1] + CutDYNewMVA[10] + CutDYLowNewMVA[10] + CutTTNewMVA[10] + CutWZNewMVA[10] + CutZZNewMVA[10] + CutWJNewMVA[10];
  double backSum2NewMVA = CutDYNewMVA[2] + CutDYLowNewMVA[2] + CutTTNewMVA[2] + CutWZNewMVA[2] + CutZZNewMVA[2] + CutWJNewMVA[2] + CutDYNewMVA[11] + CutDYLowNewMVA[11] + CutTTNewMVA[11] + CutWZNewMVA[11] + CutZZNewMVA[11] + CutWJNewMVA[11];
  double backSum3NewMVA = CutDYNewMVA[3] + CutDYLowNewMVA[3] + CutTTNewMVA[3] + CutWZNewMVA[1] + CutZZNewMVA[3] + CutWJNewMVA[3] + CutDYNewMVA[12] + CutDYLowNewMVA[12] + CutTTNewMVA[12] + CutWZNewMVA[12] + CutZZNewMVA[12] + CutWJNewMVA[12];
  double backSum4NewMVA = CutDYNewMVA[4] + CutDYLowNewMVA[4] + CutTTNewMVA[4] + CutWZNewMVA[4] + CutZZNewMVA[4] + CutWJNewMVA[4] + CutDYNewMVA[13] + CutDYLowNewMVA[13] + CutTTNewMVA[13] + CutWZNewMVA[13] + CutZZNewMVA[13] + CutWJNewMVA[13];
  double backSum5NewMVA = CutDYNewMVA[5] + CutDYLowNewMVA[5] + CutTTNewMVA[5] + CutWZNewMVA[5] + CutZZNewMVA[5] + CutWJNewMVA[5] + CutDYNewMVA[14] + CutDYLowNewMVA[14] + CutTTNewMVA[14] + CutWZNewMVA[14] + CutZZNewMVA[14] + CutWJNewMVA[14];
  double backSum6NewMVA = CutDYNewMVA[6] + CutDYLowNewMVA[6] + CutTTNewMVA[6] + CutWZNewMVA[6] + CutZZNewMVA[6] + CutWJNewMVA[6] + CutDYNewMVA[15] + CutDYLowNewMVA[15] + CutTTNewMVA[15] + CutWZNewMVA[15] + CutZZNewMVA[15] + CutWJNewMVA[15];
  double backSum7NewMVA = CutDYNewMVA[7] + CutDYLowNewMVA[7] + CutTTNewMVA[7] + CutWZNewMVA[7] + CutZZNewMVA[7] + CutWJNewMVA[7] + CutDYNewMVA[16] + CutDYLowNewMVA[16] + CutTTNewMVA[16] + CutWZNewMVA[16] + CutZZNewMVA[16] + CutWJNewMVA[16];
  double backSum8NewMVA = CutDYNewMVA[8] + CutDYLowNewMVA[8] + CutTTNewMVA[8] + CutWZNewMVA[8] + CutZZNewMVA[8] + CutWJNewMVA[8] + CutDYNewMVA[17] + CutDYLowNewMVA[17] + CutTTNewMVA[17] + CutWZNewMVA[17] + CutZZNewMVA[17] + CutWJNewMVA[17];
  double backSum10NewMVA = CutDYNewMVA[21] + CutDYLowNewMVA[21] + CutTTNewMVA[21] + CutWZNewMVA[21] + CutZZNewMVA[21] + CutWJNewMVA[21];
  double backSum9NewMVA = CutDYNewMVA[20] + CutDYLowNewMVA[20] + CutTTNewMVA[20] + CutWZNewMVA[20] + CutZZNewMVA[20] + CutWJNewMVA[20];


  //////////////////////////
  // H125 a19 4 tau DM's
  //////////////////////////
  TH1F* OldH125a19ToBack_    = new TH1F("OldH125a19ToBack","", 10, -.5, 9.5);
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      OldH125a19ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  OldH125a19ToBack_->SetBinContent(1, CutH125a19Old[1] / TMath::Sqrt(CutH125a19Old[1] + backSum1Old) );
  OldH125a19ToBack_->SetBinContent(2, CutH125a19Old[2] / TMath::Sqrt(CutH125a19Old[2] + backSum2Old) );
  OldH125a19ToBack_->SetBinContent(3, CutH125a19Old[3] / TMath::Sqrt(CutH125a19Old[3] + backSum3Old) );
  OldH125a19ToBack_->SetBinContent(4, CutH125a19Old[4] / TMath::Sqrt(CutH125a19Old[4] + backSum4Old) );
  OldH125a19ToBack_->SetBinContent(5, CutH125a19Old[5] / TMath::Sqrt(CutH125a19Old[5] + backSum5Old) );
  OldH125a19ToBack_->SetBinContent(6, CutH125a19Old[6] / TMath::Sqrt(CutH125a19Old[6] + backSum6Old) );
  OldH125a19ToBack_->SetBinContent(7, CutH125a19Old[7] / TMath::Sqrt(CutH125a19Old[7] + backSum7Old) );
  OldH125a19ToBack_->SetBinContent(8, CutH125a19Old[8] / TMath::Sqrt(CutH125a19Old[8] + backSum8Old) );
  OldH125a19ToBack_->SetBinContent(9, CutH125a19Old[9] / TMath::Sqrt(CutH125a19Old[9] + backSum9Old) );
  OldH125a19ToBack_->SetBinContent(10, CutH125a19Old[0] / TMath::Sqrt(CutH125a19Old[0] + backSum10Old) );
  OldH125a19ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* OldMVAH125a19ToBack_    = new TH1F("OldMVAH125a19ToBack","", 10, -.5, 9.5);
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      OldMVAH125a19ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  OldMVAH125a19ToBack_->SetBinContent(1,CutH125a19OldMVA[1]/TMath::Sqrt(CutH125a19OldMVA[1]+ backSum1OldMVA) );
  OldMVAH125a19ToBack_->SetBinContent(2,CutH125a19OldMVA[2]/TMath::Sqrt(CutH125a19OldMVA[2]+ backSum2OldMVA) );
  OldMVAH125a19ToBack_->SetBinContent(3,CutH125a19OldMVA[3]/TMath::Sqrt(CutH125a19OldMVA[3]+ backSum3OldMVA) );
  OldMVAH125a19ToBack_->SetBinContent(4,CutH125a19OldMVA[4]/TMath::Sqrt(CutH125a19OldMVA[4]+ backSum4OldMVA) );
  OldMVAH125a19ToBack_->SetBinContent(5,CutH125a19OldMVA[5]/TMath::Sqrt(CutH125a19OldMVA[5]+ backSum5OldMVA) );
  OldMVAH125a19ToBack_->SetBinContent(6,CutH125a19OldMVA[6]/TMath::Sqrt(CutH125a19OldMVA[6]+ backSum6OldMVA) );
  OldMVAH125a19ToBack_->SetBinContent(7,CutH125a19OldMVA[7]/TMath::Sqrt(CutH125a19OldMVA[7]+ backSum7OldMVA) );
  OldMVAH125a19ToBack_->SetBinContent(8,CutH125a19OldMVA[8]/TMath::Sqrt(CutH125a19OldMVA[8]+ backSum8OldMVA) );
  OldMVAH125a19ToBack_->SetBinContent(9,CutH125a19OldMVA[9]/TMath::Sqrt(CutH125a19OldMVA[9]+ backSum9OldMVA) );
  OldMVAH125a19ToBack_->SetBinContent(10,CutH125a19OldMVA[0]/TMath::Sqrt(CutH125a19OldMVA[0]+ backSum10OldMVA) );
  OldMVAH125a19ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewH125a19ToBack_    = new TH1F("NewH125a19ToBack","", 10, -.5, 9.5); 
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      NewH125a19ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  NewH125a19ToBack_->SetBinContent(1,CutH125a19New[1]/TMath::Sqrt(CutH125a19New[1] + backSum1New) );
  NewH125a19ToBack_->SetBinContent(2,CutH125a19New[2]/TMath::Sqrt(CutH125a19New[2] + backSum2New) );
  NewH125a19ToBack_->SetBinContent(3,CutH125a19New[3]/TMath::Sqrt(CutH125a19New[3] + backSum3New) );
  NewH125a19ToBack_->SetBinContent(4,CutH125a19New[4]/TMath::Sqrt(CutH125a19New[4] + backSum4New) );
  NewH125a19ToBack_->SetBinContent(5,CutH125a19New[5]/TMath::Sqrt(CutH125a19New[5] + backSum5New) );
  NewH125a19ToBack_->SetBinContent(6,CutH125a19New[6]/TMath::Sqrt(CutH125a19New[6] + backSum6New) );
  NewH125a19ToBack_->SetBinContent(7,CutH125a19New[7]/TMath::Sqrt(CutH125a19New[7] + backSum7New) );
  NewH125a19ToBack_->SetBinContent(8,CutH125a19New[8]/TMath::Sqrt(CutH125a19New[8] + backSum8New) );
  NewH125a19ToBack_->SetBinContent(9,CutH125a19New[9]/TMath::Sqrt(CutH125a19New[9] + backSum9New) );
  NewH125a19ToBack_->SetBinContent(10,CutH125a19New[0]/TMath::Sqrt(CutH125a19New[0]+ backSum10New) );
  NewH125a19ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewMVAH125a19ToBack_ = new TH1F("NewMVAH125a19ToBack","", 10, -.5, 9.5); 
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      NewMVAH125a19ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  NewMVAH125a19ToBack_->SetBinContent(1,CutH125a19NewMVA[1]/TMath::Sqrt(CutH125a19NewMVA[1]+ backSum1NewMVA) );
  NewMVAH125a19ToBack_->SetBinContent(2,CutH125a19NewMVA[2]/TMath::Sqrt(CutH125a19NewMVA[2]+ backSum2NewMVA) );
  NewMVAH125a19ToBack_->SetBinContent(3,CutH125a19NewMVA[3]/TMath::Sqrt(CutH125a19NewMVA[3]+ backSum3NewMVA) );
  NewMVAH125a19ToBack_->SetBinContent(4,CutH125a19NewMVA[4]/TMath::Sqrt(CutH125a19NewMVA[4]+ backSum4NewMVA) );
  NewMVAH125a19ToBack_->SetBinContent(5,CutH125a19NewMVA[5]/TMath::Sqrt(CutH125a19NewMVA[5]+ backSum5NewMVA) );
  NewMVAH125a19ToBack_->SetBinContent(6,CutH125a19NewMVA[6]/TMath::Sqrt(CutH125a19NewMVA[6]+ backSum6NewMVA) );
  NewMVAH125a19ToBack_->SetBinContent(7,CutH125a19NewMVA[7]/TMath::Sqrt(CutH125a19NewMVA[7]+ backSum7NewMVA) );
  NewMVAH125a19ToBack_->SetBinContent(8,CutH125a19NewMVA[8]/TMath::Sqrt(CutH125a19NewMVA[8]+ backSum8NewMVA) );
  NewMVAH125a19ToBack_->SetBinContent(9,CutH125a19NewMVA[9]/TMath::Sqrt(CutH125a19NewMVA[9]+ backSum9NewMVA) );
  NewMVAH125a19ToBack_->SetBinContent(10,CutH125a19NewMVA[0]/TMath::Sqrt(CutH125a19NewMVA[0]+ backSum10NewMVA) );
  NewMVAH125a19ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");


  //////////////////////////
  // H125 a9 4 tau DM's
  //////////////////////////
  TH1F* OldH125a9ToBack_    = new TH1F("OldH125a9ToBack","", 10, -.5, 9.5);
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      OldH125a9ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  OldH125a9ToBack_->SetBinContent(1, CutH125a9Old[1] / TMath::Sqrt(CutH125a9Old[1] + backSum1Old) );
  OldH125a9ToBack_->SetBinContent(2, CutH125a9Old[2] / TMath::Sqrt(CutH125a9Old[2] + backSum2Old) );
  OldH125a9ToBack_->SetBinContent(3, CutH125a9Old[3] / TMath::Sqrt(CutH125a9Old[3] + backSum3Old) );
  OldH125a9ToBack_->SetBinContent(4, CutH125a9Old[4] / TMath::Sqrt(CutH125a9Old[4] + backSum4Old) );
  OldH125a9ToBack_->SetBinContent(5, CutH125a9Old[5] / TMath::Sqrt(CutH125a9Old[5] + backSum5Old) );
  OldH125a9ToBack_->SetBinContent(6, CutH125a9Old[6] / TMath::Sqrt(CutH125a9Old[6] + backSum6Old) );
  OldH125a9ToBack_->SetBinContent(7, CutH125a9Old[7] / TMath::Sqrt(CutH125a9Old[7] + backSum7Old) );
  OldH125a9ToBack_->SetBinContent(8, CutH125a9Old[8] / TMath::Sqrt(CutH125a9Old[8] + backSum8Old) );
  OldH125a9ToBack_->SetBinContent(9, CutH125a9Old[9] / TMath::Sqrt(CutH125a9Old[9] + backSum9Old) );
  OldH125a9ToBack_->SetBinContent(10, CutH125a9Old[0] / TMath::Sqrt(CutH125a9Old[0] + backSum10Old) );
  OldH125a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* OldMVAH125a9ToBack_    = new TH1F("OldMVAH125a9ToBack","", 10, -.5, 9.5);
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      OldMVAH125a9ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  OldMVAH125a9ToBack_->SetBinContent(1, CutH125a9OldMVA[1] / TMath::Sqrt(CutH125a9OldMVA[1] + backSum1OldMVA) );
  OldMVAH125a9ToBack_->SetBinContent(2, CutH125a9OldMVA[2] / TMath::Sqrt(CutH125a9OldMVA[2] + backSum2OldMVA) );
  OldMVAH125a9ToBack_->SetBinContent(3, CutH125a9OldMVA[3] / TMath::Sqrt(CutH125a9OldMVA[3] + backSum3OldMVA) );
  OldMVAH125a9ToBack_->SetBinContent(4, CutH125a9OldMVA[4] / TMath::Sqrt(CutH125a9OldMVA[4] + backSum4OldMVA) );
  OldMVAH125a9ToBack_->SetBinContent(5, CutH125a9OldMVA[5] / TMath::Sqrt(CutH125a9OldMVA[5] + backSum5OldMVA) );
  OldMVAH125a9ToBack_->SetBinContent(6, CutH125a9OldMVA[6] / TMath::Sqrt(CutH125a9OldMVA[6] + backSum6OldMVA) );
  OldMVAH125a9ToBack_->SetBinContent(7, CutH125a9OldMVA[7] / TMath::Sqrt(CutH125a9OldMVA[7] + backSum7OldMVA) );
  OldMVAH125a9ToBack_->SetBinContent(8, CutH125a9OldMVA[8] / TMath::Sqrt(CutH125a9OldMVA[8] + backSum8OldMVA) );
  OldMVAH125a9ToBack_->SetBinContent(9, CutH125a9OldMVA[9] / TMath::Sqrt(CutH125a9OldMVA[9] + backSum9OldMVA) );
  OldMVAH125a9ToBack_->SetBinContent(10, CutH125a9OldMVA[0] / TMath::Sqrt(CutH125a9OldMVA[0] + backSum10OldMVA) );
  OldMVAH125a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewH125a9ToBack_    = new TH1F("NewH125a9ToBack","", 10, -.5, 9.5);
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      NewH125a9ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  NewH125a9ToBack_->SetBinContent(1, CutH125a9New[1] / TMath::Sqrt(CutH125a9New[1] + backSum1New) );
  NewH125a9ToBack_->SetBinContent(2, CutH125a9New[2] / TMath::Sqrt(CutH125a9New[2] + backSum2New) );
  NewH125a9ToBack_->SetBinContent(3, CutH125a9New[3] / TMath::Sqrt(CutH125a9New[3] + backSum3New) );
  NewH125a9ToBack_->SetBinContent(4, CutH125a9New[4] / TMath::Sqrt(CutH125a9New[4] + backSum4New) );
  NewH125a9ToBack_->SetBinContent(5, CutH125a9New[5] / TMath::Sqrt(CutH125a9New[5] + backSum5New) );
  NewH125a9ToBack_->SetBinContent(6, CutH125a9New[6] / TMath::Sqrt(CutH125a9New[6] + backSum6New) );
  NewH125a9ToBack_->SetBinContent(7, CutH125a9New[7] / TMath::Sqrt(CutH125a9New[7] + backSum7New) );
  NewH125a9ToBack_->SetBinContent(8, CutH125a9New[8] / TMath::Sqrt(CutH125a9New[8] + backSum8New) );
  NewH125a9ToBack_->SetBinContent(9, CutH125a9New[9] / TMath::Sqrt(CutH125a9New[9] + backSum9New) );
  NewH125a9ToBack_->SetBinContent(10, CutH125a9New[0] / TMath::Sqrt(CutH125a9New[0] + backSum10New) );
  NewH125a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewMVAH125a9ToBack_    = new TH1F("NewMVAH125a9ToBack","", 10, -.5, 9.5);
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      NewMVAH125a9ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  NewMVAH125a9ToBack_->SetBinContent(1, CutH125a9NewMVA[1] / TMath::Sqrt(CutH125a9NewMVA[1] + backSum1NewMVA) );
  NewMVAH125a9ToBack_->SetBinContent(2, CutH125a9NewMVA[2] / TMath::Sqrt(CutH125a9NewMVA[2] + backSum2NewMVA) );
  NewMVAH125a9ToBack_->SetBinContent(3, CutH125a9NewMVA[3] / TMath::Sqrt(CutH125a9NewMVA[3] + backSum3NewMVA) );
  NewMVAH125a9ToBack_->SetBinContent(4, CutH125a9NewMVA[4] / TMath::Sqrt(CutH125a9NewMVA[4] + backSum4NewMVA) );
  NewMVAH125a9ToBack_->SetBinContent(5, CutH125a9NewMVA[5] / TMath::Sqrt(CutH125a9NewMVA[5] + backSum5NewMVA) );
  NewMVAH125a9ToBack_->SetBinContent(6, CutH125a9NewMVA[6] / TMath::Sqrt(CutH125a9NewMVA[6] + backSum6NewMVA) );
  NewMVAH125a9ToBack_->SetBinContent(7, CutH125a9NewMVA[7] / TMath::Sqrt(CutH125a9NewMVA[7] + backSum7NewMVA) );
  NewMVAH125a9ToBack_->SetBinContent(8, CutH125a9NewMVA[8] / TMath::Sqrt(CutH125a9NewMVA[8] + backSum8NewMVA) );
  NewMVAH125a9ToBack_->SetBinContent(9, CutH125a9NewMVA[9] / TMath::Sqrt(CutH125a9NewMVA[9] + backSum9NewMVA) );
  NewMVAH125a9ToBack_->SetBinContent(10, CutH125a9NewMVA[0] / TMath::Sqrt(CutH125a9NewMVA[0] + backSum10NewMVA) );
  NewMVAH125a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  //////////////////////////
  // H125 a5 4 tau DM's
  //////////////////////////
  TH1F* OldH125a5ToBack_    = new TH1F("OldH125a5ToBack","", 10, -.5, 9.5);
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      OldH125a5ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  OldH125a5ToBack_->SetBinContent(1, CutH125a5Old[1] / TMath::Sqrt(CutH125a5Old[1] + backSum1Old) );
  OldH125a5ToBack_->SetBinContent(2, CutH125a5Old[2] / TMath::Sqrt(CutH125a5Old[2] + backSum2Old) );
  OldH125a5ToBack_->SetBinContent(3, CutH125a5Old[3] / TMath::Sqrt(CutH125a5Old[3] + backSum3Old) );
  OldH125a5ToBack_->SetBinContent(4, CutH125a5Old[4] / TMath::Sqrt(CutH125a5Old[4] + backSum4Old) );
  OldH125a5ToBack_->SetBinContent(5, CutH125a5Old[5] / TMath::Sqrt(CutH125a5Old[5] + backSum5Old) );
  OldH125a5ToBack_->SetBinContent(6, CutH125a5Old[6] / TMath::Sqrt(CutH125a5Old[6] + backSum6Old) );
  OldH125a5ToBack_->SetBinContent(7, CutH125a5Old[7] / TMath::Sqrt(CutH125a5Old[7] + backSum7Old) );
  OldH125a5ToBack_->SetBinContent(8, CutH125a5Old[8] / TMath::Sqrt(CutH125a5Old[8] + backSum8Old) );
  OldH125a5ToBack_->SetBinContent(9, CutH125a5Old[9] / TMath::Sqrt(CutH125a5Old[9] + backSum9Old) );
  OldH125a5ToBack_->SetBinContent(10, CutH125a5Old[0] / TMath::Sqrt(CutH125a5Old[0] + backSum10Old) );
  OldH125a5ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* OldMVAH125a5ToBack_    = new TH1F("OldMVAH125a5ToBack","", 10, -.5, 9.5);
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      OldMVAH125a5ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  OldMVAH125a5ToBack_->SetBinContent(1, CutH125a5OldMVA[1] / TMath::Sqrt(CutH125a5OldMVA[1] + backSum1OldMVA) );
  OldMVAH125a5ToBack_->SetBinContent(2, CutH125a5OldMVA[2] / TMath::Sqrt(CutH125a5OldMVA[2] + backSum2OldMVA) );
  OldMVAH125a5ToBack_->SetBinContent(3, CutH125a5OldMVA[3] / TMath::Sqrt(CutH125a5OldMVA[3] + backSum3OldMVA) );
  OldMVAH125a5ToBack_->SetBinContent(4, CutH125a5OldMVA[4] / TMath::Sqrt(CutH125a5OldMVA[4] + backSum4OldMVA) );
  OldMVAH125a5ToBack_->SetBinContent(5, CutH125a5OldMVA[5] / TMath::Sqrt(CutH125a5OldMVA[5] + backSum5OldMVA) );
  OldMVAH125a5ToBack_->SetBinContent(6, CutH125a5OldMVA[6] / TMath::Sqrt(CutH125a5OldMVA[6] + backSum6OldMVA) );
  OldMVAH125a5ToBack_->SetBinContent(7, CutH125a5OldMVA[7] / TMath::Sqrt(CutH125a5OldMVA[7] + backSum7OldMVA) );
  OldMVAH125a5ToBack_->SetBinContent(8, CutH125a5OldMVA[8] / TMath::Sqrt(CutH125a5OldMVA[8] + backSum8OldMVA) );
  OldMVAH125a5ToBack_->SetBinContent(9, CutH125a5OldMVA[9] / TMath::Sqrt(CutH125a5OldMVA[9] + backSum9OldMVA) );
  OldMVAH125a5ToBack_->SetBinContent(10, CutH125a5OldMVA[0] / TMath::Sqrt(CutH125a5OldMVA[0] + backSum10OldMVA) );
  OldMVAH125a5ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewH125a5ToBack_    = new TH1F("NewH125a5ToBack","", 10, -.5, 9.5);
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      NewH125a5ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[0].c_str() );
  NewH125a5ToBack_->SetBinContent(1, CutH125a5New[1] / TMath::Sqrt(CutH125a5New[1] + backSum1New) );
  NewH125a5ToBack_->SetBinContent(2, CutH125a5New[2] / TMath::Sqrt(CutH125a5New[2] + backSum2New) );
  NewH125a5ToBack_->SetBinContent(3, CutH125a5New[3] / TMath::Sqrt(CutH125a5New[3] + backSum3New) );
  NewH125a5ToBack_->SetBinContent(4, CutH125a5New[4] / TMath::Sqrt(CutH125a5New[4] + backSum4New) );
  NewH125a5ToBack_->SetBinContent(5, CutH125a5New[5] / TMath::Sqrt(CutH125a5New[5] + backSum5New) );
  NewH125a5ToBack_->SetBinContent(6, CutH125a5New[6] / TMath::Sqrt(CutH125a5New[6] + backSum6New) );
  NewH125a5ToBack_->SetBinContent(7, CutH125a5New[7] / TMath::Sqrt(CutH125a5New[7] + backSum7New) );
  NewH125a5ToBack_->SetBinContent(8, CutH125a5New[8] / TMath::Sqrt(CutH125a5New[8] + backSum8New) );
  NewH125a5ToBack_->SetBinContent(9, CutH125a5New[9] / TMath::Sqrt(CutH125a5New[9] + backSum9New) );
  NewH125a5ToBack_->SetBinContent(10, CutH125a5New[0] / TMath::Sqrt(CutH125a5New[0] + backSum10New) );
  NewH125a5ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewMVAH125a5ToBack_    = new TH1F("NewMVAH125a5ToBack","", 10, -.5, 9.5);
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      NewMVAH125a5ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  NewMVAH125a5ToBack_->SetBinContent(1, CutH125a5NewMVA[1] / TMath::Sqrt(CutH125a5NewMVA[1] + backSum1NewMVA) );
  NewMVAH125a5ToBack_->SetBinContent(2, CutH125a5NewMVA[2] / TMath::Sqrt(CutH125a5NewMVA[2] + backSum2NewMVA) );
  NewMVAH125a5ToBack_->SetBinContent(3, CutH125a5NewMVA[3] / TMath::Sqrt(CutH125a5NewMVA[3] + backSum3NewMVA) );
  NewMVAH125a5ToBack_->SetBinContent(4, CutH125a5NewMVA[4] / TMath::Sqrt(CutH125a5NewMVA[4] + backSum4NewMVA) );
  NewMVAH125a5ToBack_->SetBinContent(5, CutH125a5NewMVA[5] / TMath::Sqrt(CutH125a5NewMVA[5] + backSum5NewMVA) );
  NewMVAH125a5ToBack_->SetBinContent(6, CutH125a5NewMVA[6] / TMath::Sqrt(CutH125a5NewMVA[6] + backSum6NewMVA) );
  NewMVAH125a5ToBack_->SetBinContent(7, CutH125a5NewMVA[7] / TMath::Sqrt(CutH125a5NewMVA[7] + backSum7NewMVA) );
  NewMVAH125a5ToBack_->SetBinContent(8, CutH125a5NewMVA[8] / TMath::Sqrt(CutH125a5NewMVA[8] + backSum8NewMVA) );
  NewMVAH125a5ToBack_->SetBinContent(9, CutH125a5NewMVA[9] / TMath::Sqrt(CutH125a5NewMVA[9] + backSum9NewMVA) );
  NewMVAH125a5ToBack_->SetBinContent(10, CutH125a5NewMVA[0] / TMath::Sqrt(CutH125a5NewMVA[0] + backSum10NewMVA) );
  NewMVAH125a5ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  //////////////////////////
  // H750 a9 4 tau DM's
  //////////////////////////
  TH1F* OldH750a9ToBack_    = new TH1F("OldH750a9ToBack","", 10, -.5, 9.5);
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      OldH750a9ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  OldH750a9ToBack_->SetBinContent(1, CutH750a9Old[1] / TMath::Sqrt(CutH750a9Old[1] + backSum1Old) );
  OldH750a9ToBack_->SetBinContent(2, CutH750a9Old[2] / TMath::Sqrt(CutH750a9Old[2] + backSum2Old) );
  OldH750a9ToBack_->SetBinContent(3, CutH750a9Old[3] / TMath::Sqrt(CutH750a9Old[3] + backSum3Old) );
  OldH750a9ToBack_->SetBinContent(4, CutH750a9Old[4] / TMath::Sqrt(CutH750a9Old[4] + backSum4Old) );
  OldH750a9ToBack_->SetBinContent(5, CutH750a9Old[5] / TMath::Sqrt(CutH750a9Old[5] + backSum5Old) );
  OldH750a9ToBack_->SetBinContent(6, CutH750a9Old[6] / TMath::Sqrt(CutH750a9Old[6] + backSum6Old) );
  OldH750a9ToBack_->SetBinContent(7, CutH750a9Old[7] / TMath::Sqrt(CutH750a9Old[7] + backSum7Old) );
  OldH750a9ToBack_->SetBinContent(8, CutH750a9Old[8] / TMath::Sqrt(CutH750a9Old[8] + backSum8Old) );
  OldH750a9ToBack_->SetBinContent(9, CutH750a9Old[9] / TMath::Sqrt(CutH750a9Old[9] + backSum9Old) );
  OldH750a9ToBack_->SetBinContent(10, CutH750a9Old[0] / TMath::Sqrt(CutH750a9Old[0] + backSum10Old) );
  OldH750a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* OldMVAH750a9ToBack_    = new TH1F("OldMVAH750a9ToBack","", 10, -.5, 9.5);
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      OldMVAH750a9ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  OldMVAH750a9ToBack_->SetBinContent(1, CutH750a9OldMVA[1] / TMath::Sqrt(CutH750a9OldMVA[1] + backSum1OldMVA) );
  OldMVAH750a9ToBack_->SetBinContent(2, CutH750a9OldMVA[2] / TMath::Sqrt(CutH750a9OldMVA[2] + backSum2OldMVA) );
  OldMVAH750a9ToBack_->SetBinContent(3, CutH750a9OldMVA[3] / TMath::Sqrt(CutH750a9OldMVA[3] + backSum3OldMVA) );
  OldMVAH750a9ToBack_->SetBinContent(4, CutH750a9OldMVA[4] / TMath::Sqrt(CutH750a9OldMVA[4] + backSum4OldMVA) );
  OldMVAH750a9ToBack_->SetBinContent(5, CutH750a9OldMVA[5] / TMath::Sqrt(CutH750a9OldMVA[5] + backSum5OldMVA) );
  OldMVAH750a9ToBack_->SetBinContent(6, CutH750a9OldMVA[6] / TMath::Sqrt(CutH750a9OldMVA[6] + backSum6OldMVA) );
  OldMVAH750a9ToBack_->SetBinContent(7, CutH750a9OldMVA[7] / TMath::Sqrt(CutH750a9OldMVA[7] + backSum7OldMVA) );
  OldMVAH750a9ToBack_->SetBinContent(8, CutH750a9OldMVA[8] / TMath::Sqrt(CutH750a9OldMVA[8] + backSum8OldMVA) );
  OldMVAH750a9ToBack_->SetBinContent(9, CutH750a9OldMVA[9] / TMath::Sqrt(CutH750a9OldMVA[9] + backSum9OldMVA) );
  OldMVAH750a9ToBack_->SetBinContent(10, CutH750a9OldMVA[0] / TMath::Sqrt(CutH750a9OldMVA[0] + backSum10OldMVA) );
  OldMVAH750a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewH750a9ToBack_    = new TH1F("NewH750a9ToBack","", 10, -.5, 9.5);
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      NewH750a9ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  NewH750a9ToBack_->SetBinContent(1, CutH750a9New[1] / TMath::Sqrt(CutH750a9New[1] + backSum1New) );
  NewH750a9ToBack_->SetBinContent(2, CutH750a9New[2] / TMath::Sqrt(CutH750a9New[2] + backSum2New) );
  NewH750a9ToBack_->SetBinContent(3, CutH750a9New[3] / TMath::Sqrt(CutH750a9New[3] + backSum3New) );
  NewH750a9ToBack_->SetBinContent(4, CutH750a9New[4] / TMath::Sqrt(CutH750a9New[4] + backSum4New) );
  NewH750a9ToBack_->SetBinContent(5, CutH750a9New[5] / TMath::Sqrt(CutH750a9New[5] + backSum5New) );
  NewH750a9ToBack_->SetBinContent(6, CutH750a9New[6] / TMath::Sqrt(CutH750a9New[6] + backSum6New) );
  NewH750a9ToBack_->SetBinContent(7, CutH750a9New[7] / TMath::Sqrt(CutH750a9New[7] + backSum7New) );
  NewH750a9ToBack_->SetBinContent(8, CutH750a9New[8] / TMath::Sqrt(CutH750a9New[8] + backSum8New) );
  NewH750a9ToBack_->SetBinContent(9, CutH750a9New[9] / TMath::Sqrt(CutH750a9New[9] + backSum9New) );
  NewH750a9ToBack_->SetBinContent(10, CutH750a9New[0] / TMath::Sqrt(CutH750a9New[0] + backSum10New) );
  NewH750a9ToBack_->GetYaxis()->SetTitle("S / sqrt (S + B)");

  TH1F* NewMVAH750a9ToBack_    = new TH1F("NewMVAH750a9ToBack","", 10, -.5, 9.5);
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(1, CutLabelsSig[1].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(2, CutLabelsSig[2].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(3, CutLabelsSig[3].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(4, CutLabelsSig[4].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(5, CutLabelsSig[5].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(6, CutLabelsSig[6].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(7, CutLabelsSig[7].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(8, CutLabelsSig[8].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(9, CutLabelsSig[9].c_str() );
      NewMVAH750a9ToBack_->GetXaxis()->SetBinLabel(10, CutLabelsSig[10].c_str() );
  NewMVAH750a9ToBack_->SetBinContent(1, CutH750a9NewMVA[1] / TMath::Sqrt(CutH750a9NewMVA[1] + backSum1NewMVA) );
  NewMVAH750a9ToBack_->SetBinContent(2, CutH750a9NewMVA[2] / TMath::Sqrt(CutH750a9NewMVA[2] + backSum2NewMVA) );
  NewMVAH750a9ToBack_->SetBinContent(3, CutH750a9NewMVA[3] / TMath::Sqrt(CutH750a9NewMVA[3] + backSum3NewMVA) );
  NewMVAH750a9ToBack_->SetBinContent(4, CutH750a9NewMVA[4] / TMath::Sqrt(CutH750a9NewMVA[4] + backSum4NewMVA) );
  NewMVAH750a9ToBack_->SetBinContent(5, CutH750a9NewMVA[5] / TMath::Sqrt(CutH750a9NewMVA[5] + backSum5NewMVA) );
  NewMVAH750a9ToBack_->SetBinContent(6, CutH750a9NewMVA[6] / TMath::Sqrt(CutH750a9NewMVA[6] + backSum6NewMVA) );
  NewMVAH750a9ToBack_->SetBinContent(7, CutH750a9NewMVA[7] / TMath::Sqrt(CutH750a9NewMVA[7] + backSum7NewMVA) );
  NewMVAH750a9ToBack_->SetBinContent(8, CutH750a9NewMVA[8] / TMath::Sqrt(CutH750a9NewMVA[8] + backSum8NewMVA) );
  NewMVAH750a9ToBack_->SetBinContent(9, CutH750a9NewMVA[9] / TMath::Sqrt(CutH750a9NewMVA[9] + backSum9NewMVA) );
  NewMVAH750a9ToBack_->SetBinContent(10, CutH750a9NewMVA[0] / TMath::Sqrt(CutH750a9NewMVA[0] + backSum10NewMVA) );
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

  CanvasArray[10]->Write();
  CanvasArray[11]->Write();
  CanvasArray[12]->Write();
  CanvasArray[13]->Write();
  CanvasArray[14]->Write();
  CanvasArray[15]->Write();

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

  legToBack = new TLegend(0.1,0.7,0.25,0.9);
  legToBack->AddEntry(OldH125a19ToBack_, "H125a19","L");
  legToBack->AddEntry(OldH125a9ToBack_, "H125a9","L");
  legToBack->AddEntry(OldH125a5ToBack_, "H125a5","L");
  legToBack->AddEntry(OldH750a9ToBack_, "H750a9","L");

  OldSigToBackCanvas.cd();
  OldH125a19ToBack_->Draw();
  OldH125a9ToBack_->Draw("SAME");
  OldH125a5ToBack_->Draw("SAME");
  OldH750a9ToBack_->Draw("SAME");  
  legToBack->Draw();
  OldSigToBackCanvas.Write();

  OldMVASigToBackCanvas.cd();
  OldMVAH125a19ToBack_->Draw();
  OldMVAH125a9ToBack_->Draw("SAME");
  OldMVAH125a5ToBack_->Draw("SAME");
  OldMVAH750a9ToBack_->Draw("SAME");
  legToBack->Draw();
  OldMVASigToBackCanvas.Write();

  NewSigToBackCanvas.cd();
  NewH125a19ToBack_->Draw();
  NewH125a9ToBack_->Draw("SAME");
  NewH125a5ToBack_->Draw("SAME");
  NewH750a9ToBack_->Draw("SAME");
  legToBack->Draw();
  NewSigToBackCanvas.Write();

  NewMVASigToBackCanvas.cd();
  NewMVAH125a19ToBack_->Draw();
  NewMVAH125a9ToBack_->Draw("SAME");
  NewMVAH125a5ToBack_->Draw("SAME");
  NewMVAH750a9ToBack_->Draw("SAME");
  legToBack->Draw();
  NewMVASigToBackCanvas.Write();

  TotalSigToBackCanvas.cd(1);
  NewMVAH125a19ToBack_->SetTitle("NewMVA");
  NewMVAH125a19ToBack_->Draw();
  NewMVAH125a9ToBack_->Draw("SAME");
  NewMVAH125a5ToBack_->Draw("SAME");
  NewMVAH750a9ToBack_->Draw("SAME");
  legToBack->Draw();
  TotalSigToBackCanvas.cd(2);
  NewH125a19ToBack_->SetTitle("New");
  NewH125a19ToBack_->Draw();
  NewH125a9ToBack_->Draw("SAME");
  NewH125a5ToBack_->Draw("SAME");
  NewH750a9ToBack_->Draw("SAME");
  legToBack->Draw();
  TotalSigToBackCanvas.cd(3);
  OldMVAH125a19ToBack_->SetTitle("OldMVA");
  OldMVAH125a19ToBack_->Draw();
  OldMVAH125a9ToBack_->Draw("SAME");
  OldMVAH125a5ToBack_->Draw("SAME");
  OldMVAH750a9ToBack_->Draw("SAME");
  legToBack->Draw();
  TotalSigToBackCanvas.cd(4);
  OldH125a19ToBack_->SetTitle("Old");
  OldH125a19ToBack_->Draw();
  OldH125a9ToBack_->Draw("SAME");
  OldH125a5ToBack_->Draw("SAME");
  OldH750a9ToBack_->Draw("SAME");
  legToBack->Draw();

  TotalSigToBackCanvas.Write();
  for (int i=0; i < 8;i++)
  {
    std::cout << "NewMVAH125a19 bin #" << i << "= " << NewMVAH125a19ToBack_->GetBinContent(i) << std::endl;
    std::cout << "NewMVAH125a9 bin #" << i << "= " << NewMVAH125a9ToBack_->GetBinContent(i) << std::endl;
    std::cout << "NewMVAH125a5 bin #" << i << "= " << NewMVAH125a5ToBack_->GetBinContent(i) << std::endl;
    std::cout << "NewMVAH750a9 bin #" << i << "= " << NewMVAH750a9ToBack_->GetBinContent(i) << std::endl;
    std::cout << "NewH125a19 bin #" << i << "= " << NewH125a19ToBack_->GetBinContent(i) << std::endl;
    std::cout << "NewH125a9 bin #" << i << "= " << NewH125a9ToBack_->GetBinContent(i) << std::endl;
    std::cout << "NewH125a5 bin #" << i << "= " << NewH125a5ToBack_->GetBinContent(i) << std::endl;
    std::cout << "NewH750a9 bin #" << i << "= " << NewH750a9ToBack_->GetBinContent(i) << std::endl;
    std::cout << "OldMVAH125a19 bin #" << i << "= " << OldMVAH125a19ToBack_->GetBinContent(i) << std::endl;
    std::cout << "OldMVAH125a9 bin #" << i << "= " << OldMVAH125a9ToBack_->GetBinContent(i) << std::endl;
    std::cout << "OldMVAH125a5 bin #" << i << "= " << OldMVAH125a5ToBack_->GetBinContent(i) << std::endl;
    std::cout << "OldMVAH750a9 bin #" << i << "= " << OldMVAH750a9ToBack_->GetBinContent(i) << std::endl;
    std::cout << "OldH125a19 bin #" << i << "= " << OldH125a19ToBack_->GetBinContent(i) << std::endl;
    std::cout << "OldH125a9 bin #" << i << "= " << OldH125a9ToBack_->GetBinContent(i) << std::endl;
    std::cout << "OldH125a5 bin #" << i << "= " << OldH125a5ToBack_->GetBinContent(i) << std::endl;
    std::cout << "OldH750a9 bin #" << i << "= " << OldH750a9ToBack_->GetBinContent(i) << std::endl;
  }//for 
    
  
  outFile->Write();
  outFile->Close();

}//rootMacro_FakeRateInfo

void GetFormatAndDrawBack(TFile &infile, TFile *outFile, TLegend *leg, string legName, const Color_t color, std::vector<TCanvas*> &CanvasArray, double scale, bool firstFile, int Cuts[], int Counts[], string labels[], int quadrant, string tauDM)
{

  std::cout << "FILE: " << legName << std::endl;

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
  TCanvas *Mu3PtMatchCanvas   = (TCanvas*)infile.Get("Mu3PtMatch");
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
  TH1F* Mu3PtMatch_   = (TH1F*)Mu3PtMatchCanvas->GetPrimitive("Mu3PtMatch");
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
  Cuts[5] = NEventsCuts_->GetBinContent(6);
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
  Cuts[17] = NEventsCuts_->GetBinContent(18);
  Cuts[18] = NEventsCuts_->GetBinContent(19);
  Cuts[19] = NEventsCuts_->GetBinContent(20);
  Cuts[20] = NEventsCuts_->GetBinContent(21);
  Cuts[21] = NEventsCuts_->GetBinContent(22);

  //Saving label names
  labels[0] = NEventsCuts_->GetXaxis()->GetBinLabel(1);
  labels[1] = NEventsCuts_->GetXaxis()->GetBinLabel(2);
  labels[2] = NEventsCuts_->GetXaxis()->GetBinLabel(3);
  labels[3] = NEventsCuts_->GetXaxis()->GetBinLabel(4);
  labels[4] = NEventsCuts_->GetXaxis()->GetBinLabel(5);
  labels[5] = NEventsCuts_->GetXaxis()->GetBinLabel(6);
  labels[6] = NEventsCuts_->GetXaxis()->GetBinLabel(7);
  labels[7] = NEventsCuts_->GetXaxis()->GetBinLabel(8);
  labels[8] = NEventsCuts_->GetXaxis()->GetBinLabel(9);
  labels[9] = NEventsCuts_->GetXaxis()->GetBinLabel(10);
  labels[10] = NEventsCuts_->GetXaxis()->GetBinLabel(11);
  labels[11] = NEventsCuts_->GetXaxis()->GetBinLabel(12);
  labels[12] = NEventsCuts_->GetXaxis()->GetBinLabel(13);
  labels[13] = NEventsCuts_->GetXaxis()->GetBinLabel(14);
  labels[14] = NEventsCuts_->GetXaxis()->GetBinLabel(15);
  labels[15] = NEventsCuts_->GetXaxis()->GetBinLabel(16);
  labels[16] = NEventsCuts_->GetXaxis()->GetBinLabel(17);
  labels[17] = NEventsCuts_->GetXaxis()->GetBinLabel(18);
  labels[18] = NEventsCuts_->GetXaxis()->GetBinLabel(19);
  labels[19] = NEventsCuts_->GetXaxis()->GetBinLabel(20);
  labels[20] = NEventsCuts_->GetXaxis()->GetBinLabel(21);
  labels[21] = NEventsCuts_->GetXaxis()->GetBinLabel(22);

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

  MatchedTauMuPtLepton_->SetTitle(tauDM.c_str() );
  MatchedTauHadPtLepton_->SetTitle(tauDM.c_str() );
  MatchedTauHadEtaLepton_->SetTitle(tauDM.c_str() );
  MatchedHTLepton_->SetTitle(tauDM.c_str() );
  MatchedBDiscCSVLepton_->SetTitle(tauDM.c_str() );
  MatchedTauMuPtJet_->SetTitle(tauDM.c_str() );
  MatchedTauHadPtJet_->SetTitle(tauDM.c_str() );
  MatchedTauHadEtaJet_->SetTitle(tauDM.c_str() );
  MatchedHTJet_->SetTitle(tauDM.c_str() );
  MatchedBDiscCSVJet_->SetTitle(tauDM.c_str() );

  MassDiLepGEN_->SetLineColor(color);
  MassDiLepRECO_->SetLineColor(color);
  Mu3LargestPtMatch_->SetLineColor(color);
  Mu3PtMatch_->SetLineColor(color);
  PtOverMassMu1Mu2_->SetLineColor(color);
  PtMu1Mu2_->SetLineColor(color);

  MassDiLepGEN_->SetTitle(tauDM.c_str() );
  MassDiLepRECO_->SetTitle(tauDM.c_str() );
  Mu3LargestPtMatch_->SetTitle(tauDM.c_str() );
  Mu3PtMatch_->SetTitle(tauDM.c_str() );
  PtOverMassMu1Mu2_->SetTitle(tauDM.c_str() );
  PtMu1Mu2_->SetTitle(tauDM.c_str() );

  MatchedTauMuPtLepton_->Scale(scale);
  MatchedTauHadPtLepton_->Scale(scale);
  MatchedTauHadEtaLepton_->Scale(scale);
  MatchedHTLepton_->Scale(scale);
  MatchedBDiscCSVLepton_->Scale(scale);
  MatchedTauMuPtJet_->Scale(scale);
  MatchedTauHadPtJet_->Scale(scale);
  MatchedTauHadEtaJet_->Scale(scale);
  MatchedHTJet_->Scale(scale);
  MatchedBDiscCSVJet_->Scale(scale);
  
  MassDiLepGEN_->Scale(scale);
  MassDiLepRECO_->Scale(scale);
  Mu3LargestPtMatch_->Scale(scale);
  Mu3PtMatch_->Scale(scale);
  PtOverMassMu1Mu2_->Scale(scale);
  PtMu1Mu2_->Scale(scale);


  leg->AddEntry(MatchedTauHadPtLepton_, legName.c_str(),"L");

  //Drawing all of the Overlaid Lepton Matched HIstograms
  if (firstFile)
  {
    CanvasArray[0]->cd(quadrant );
    if (MatchedTauHadPtLepton_->GetEntries() != 0)
      MatchedTauHadPtLepton_->Draw();
    else 
      MatchedTauHadPtLepton_->Draw();
    leg->Draw();
  
    CanvasArray[1]->cd(quadrant );
    if (MatchedTauMuPtLepton_->GetEntries() != 0)
      MatchedTauMuPtLepton_->Draw();
    else
      MatchedTauMuPtLepton_->Draw();
    leg->Draw();
   
    CanvasArray[2]->cd(quadrant );
    if (MatchedTauHadEtaLepton_->GetEntries() != 0)
      MatchedTauHadEtaLepton_->Draw();
    else
      MatchedTauHadEtaLepton_->Draw();
    leg->Draw();
    
    CanvasArray[3]->cd(quadrant );
    if (MatchedHTLepton_->GetEntries() != 0)
      MatchedHTLepton_->Draw();
    else
      MatchedHTLepton_->Draw();
    leg->Draw();
    
    CanvasArray[4]->cd(quadrant );
    if (MatchedBDiscCSVLepton_->GetEntries() != 0)
      MatchedBDiscCSVLepton_->Draw();
    else
      MatchedBDiscCSVLepton_->Draw();
    leg->Draw();
    
    CanvasArray[6]->cd(quadrant );
    if (MatchedTauMuPtJet_->GetEntries() != 0)
      MatchedTauMuPtJet_->Draw();
    else
      MatchedTauMuPtJet_->Draw();
    leg->Draw();
    
    CanvasArray[7]->cd(quadrant );
    if (MatchedTauHadEtaJet_->GetEntries() != 0) 
      MatchedTauHadEtaJet_->Draw();
    else
      MatchedTauHadEtaJet_->Draw();
    leg->Draw();
  
    CanvasArray[8]->cd(quadrant );
    if (MatchedHTJet_->GetEntries() != 0)
      MatchedHTJet_->Draw();
    else
      MatchedHTJet_->Draw();
    leg->Draw();
    
    CanvasArray[9]->cd(quadrant );
    if (MatchedBDiscCSVJet_->GetEntries() != 0) 
      MatchedBDiscCSVJet_->Draw();
    else
      MatchedBDiscCSVJet_->Draw();
    leg->Draw();
    
    CanvasArray[10]->cd(quadrant );
    if (MassDiLepGEN_->GetEntries() != 0) 
      MassDiLepGEN_->Draw();
    else
      MassDiLepGEN_->Draw();
    leg->Draw();
    
    CanvasArray[11]->cd(quadrant );
    if (MassDiLepRECO_->GetEntries() != 0)
      MassDiLepRECO_->Draw();
    else
      MassDiLepRECO_->Draw();
    leg->Draw();
    
    CanvasArray[12]->cd(quadrant );
    if (Mu3LargestPtMatch_->GetEntries() != 0)
      Mu3LargestPtMatch_->Draw();
    else
      Mu3LargestPtMatch_->Draw();
    leg->Draw();
    
    CanvasArray[13]->cd(quadrant );
    if (Mu3PtMatch_->GetEntries() != 0)
      Mu3PtMatch_->Draw();
    else
      Mu3PtMatch_->Draw();
    leg->Draw();
    
    CanvasArray[14]->cd(quadrant );
    if (PtOverMassMu1Mu2_->GetEntries() != 0)
      PtOverMassMu1Mu2_->Draw();
    else
      PtOverMassMu1Mu2_->Draw();
    leg->Draw();
    
    CanvasArray[15]->cd(quadrant );
    if (PtMu1Mu2_->GetEntries() != 0)
      PtMu1Mu2_->Draw();
    else
      PtMu1Mu2_->Draw();
    leg->Draw();
  }//if firstFile 
  else
  {
    CanvasArray[0]->cd(quadrant );
    if (MatchedTauHadPtLepton_->GetEntries() != 0)
      MatchedTauHadPtLepton_->Draw("SAME");
    else
      MatchedTauHadPtLepton_->Draw("SAME");
    leg->Draw();

    CanvasArray[1]->cd(quadrant );
    if (MatchedTauMuPtLepton_->GetEntries() != 0)
      MatchedTauMuPtLepton_->Draw("SAME");
    else
      MatchedTauMuPtLepton_->Draw("SAME");
    leg->Draw();

    CanvasArray[2]->cd(quadrant );
    if (MatchedTauHadEtaLepton_->GetEntries() != 0)
      MatchedTauHadEtaLepton_->Draw("SAME");
    else
      MatchedTauHadEtaLepton_->Draw("SAME");
    leg->Draw();

    CanvasArray[3]->cd(quadrant );
    if (MatchedHTLepton_->GetEntries() != 0)
      MatchedHTLepton_->Draw("SAME");
    else
      MatchedHTLepton_->Draw("SAME");
    leg->Draw();

    CanvasArray[4]->cd(quadrant );
    if (MatchedBDiscCSVLepton_->GetEntries() != 0)
      MatchedBDiscCSVLepton_->Draw("SAME");
    else
      MatchedBDiscCSVLepton_->Draw("SAME");
    leg->Draw();

    CanvasArray[5]->cd(quadrant );
    if (MatchedTauHadPtJet_->GetEntries() != 0)
      MatchedTauHadPtJet_->Draw("SAME");
    else
      MatchedTauHadPtJet_->Draw("SAME");
    leg->Draw();

    CanvasArray[6]->cd(quadrant );
    if (MatchedTauMuPtJet_->GetEntries() != 0)
      MatchedTauMuPtJet_->Draw("SAME");
    else
      MatchedTauMuPtJet_->Draw("SAME");
    leg->Draw();

    CanvasArray[7]->cd(quadrant );
    if (MatchedTauHadEtaJet_->GetEntries() != 0)
      MatchedTauHadEtaJet_->Draw("SAME");
    else
      MatchedTauHadEtaJet_->Draw("SAME");
    leg->Draw();

    CanvasArray[8]->cd(quadrant );
    if (MatchedHTJet_->GetEntries() != 0)
      MatchedHTJet_->Draw("SAME");
    else
      MatchedHTJet_->Draw("SAME");
    leg->Draw();

    CanvasArray[9]->cd(quadrant );
    if (MatchedBDiscCSVJet_->GetEntries() != 0)
      MatchedBDiscCSVJet_->Draw("SAME");
    else
      MatchedBDiscCSVJet_->Draw("SAME");
    leg->Draw();
    
    CanvasArray[10]->cd(quadrant );
    if (MassDiLepGEN_->GetEntries() != 0) 
      MassDiLepGEN_->Draw("SAME");
    else
      MassDiLepGEN_->Draw("SAME");
    leg->Draw();
    
    CanvasArray[11]->cd(quadrant );
    if (MassDiLepRECO_->GetEntries() != 0)
      MassDiLepRECO_->Draw("SAME");
    else
      MassDiLepRECO_->Draw("SAME");
    leg->Draw();
    
    CanvasArray[12]->cd(quadrant );
    if (Mu3LargestPtMatch_->GetEntries() != 0)
      Mu3LargestPtMatch_->Draw("SAME");
    else
      Mu3LargestPtMatch_->Draw("SAME");
    leg->Draw();
    
    CanvasArray[13]->cd(quadrant );
    if (Mu3PtMatch_->GetEntries() != 0)
      Mu3PtMatch_->Draw("SAME");
    else
      Mu3PtMatch_->Draw("SAME");
    leg->Draw();
    
    CanvasArray[14]->cd(quadrant );
    if (PtOverMassMu1Mu2_->GetEntries() != 0)
      PtOverMassMu1Mu2_->Draw("SAME");
    else
      PtOverMassMu1Mu2_->Draw("SAME");
    leg->Draw();
    
    CanvasArray[15]->cd(quadrant );
    if (PtMu1Mu2_->GetEntries() != 0)
      PtMu1Mu2_->Draw("SAME");
    else
      PtMu1Mu2_->Draw("SAME");
    leg->Draw();
  
  }//else

cout << "Histograms Drawn" << endl;

  outFile->cd();
  string nameGMType = GenMatchType_->GetName();
  nameGMType += legName;
  GenMatchType_->SetName(nameGMType.c_str() );
  GenMatchType_->Write();
  GenMatchPDGID_->Write("SAME");
  
cout << "end" << endl;

}//rootMacro_BBA_combine





void GetFormatAndDrawSign(TFile &infile, TFile *outFile, TLegend *leg, string legName, const Color_t color, std::vector<TCanvas*> &CanvasArray, double scale, bool firstFile, int Cuts[], int Counts[], string labels[], int quadrant, string tauDM)
{
std::cout << "FILE: " << legName << std::endl;
  ////////////////
  // Canvases
  ////////////////
  TCanvas *MatchedLooseIsoCJPtCanvas   = (TCanvas*)infile.Get("MatchedLooseIsoCJPt");
  TCanvas *MatchedMedIsoCJPtCanvas     = (TCanvas*)infile.Get("MatchedMedIsoCJPt");
  TCanvas *MatchedTightIsoCJPtCanvas   = (TCanvas*)infile.Get("MatchedTightIsoCJPt");
  TCanvas *MatchedCJPtCanvas   = (TCanvas*)infile.Get("MatchedCJPt");
  TCanvas *NEventsCanvas   = (TCanvas*)infile.Get("NEvents");
  TCanvas *NEventsCutsCanvas   = (TCanvas*)infile.Get("NEventsCuts");
  TCanvas *MatchedTauMuPtCanvas   = (TCanvas*)infile.Get("MatchedTauMuPt");
  TCanvas *MatchedTauHadPtCanvas   = (TCanvas*)infile.Get("MatchedTauHadPt");
  TCanvas *MatchedTauHadEtaCanvas   = (TCanvas*)infile.Get("MatchedTauHadEta");
  TCanvas *MatchedHTCanvas   = (TCanvas*)infile.Get("MatchedHT");
  TCanvas *MatchedBDiscCSVCanvas   = (TCanvas*)infile.Get("MatchedBDiscCSV");

  TCanvas *MassDiLepGENCanvas   = (TCanvas*)infile.Get("MassDiLepGEN");
  TCanvas *MassDiLepRECOCanvas   = (TCanvas*)infile.Get("MassDiLepRECO");
  TCanvas *Mu3LargestPtMatchCanvas   = (TCanvas*)infile.Get("Mu3LargestPtMatch");
  TCanvas *Mu3PtMatchCanvas   = (TCanvas*)infile.Get("Mu3PtMatch");
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
  TH1F* MatchedTauMuPt_   = (TH1F*)MatchedTauMuPtCanvas->GetPrimitive("MatchedTauMuPt");
  TH1F* MatchedTauHadPt_   = (TH1F*)MatchedTauHadPtCanvas->GetPrimitive("MatchedTauHadPt");
  TH1F* MatchedTauHadEta_   = (TH1F*)MatchedTauHadEtaCanvas->GetPrimitive("MatchedTauHadEta");
  TH1F* MatchedHT_   = (TH1F*)MatchedHTCanvas->GetPrimitive("MatchedHT");
  TH1F* MatchedBDiscCSV_   = (TH1F*)MatchedBDiscCSVCanvas->GetPrimitive("MatchedBDiscCSV");

  TH1F* MassDiLepGEN_   = (TH1F*)MassDiLepGENCanvas->GetPrimitive("MassDiLepGEN");
  TH1F* MassDiLepRECO_   = (TH1F*)MassDiLepRECOCanvas->GetPrimitive("MassDiLepRECO");
  TH1F* Mu3LargestPtMatch_   = (TH1F*)Mu3LargestPtMatchCanvas->GetPrimitive("Mu3LargestPtMatch");
  TH1F* Mu3PtMatch_   = (TH1F*)Mu3PtMatchCanvas->GetPrimitive("Mu3PtMatch");
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
  Cuts[5] = NEventsCuts_->GetBinContent(6);
  Cuts[6] = NEventsCuts_->GetBinContent(7);
  Cuts[7] = NEventsCuts_->GetBinContent(8);
  Cuts[8] = NEventsCuts_->GetBinContent(9);
  Cuts[9] = NEventsCuts_->GetBinContent(10);
  Cuts[10] = NEventsCuts_->GetBinContent(11);

  //Saving label names
  labels[0] = NEventsCuts_->GetXaxis()->GetBinLabel(1);
  labels[1] = NEventsCuts_->GetXaxis()->GetBinLabel(2);
  labels[2] = NEventsCuts_->GetXaxis()->GetBinLabel(3);
  labels[3] = NEventsCuts_->GetXaxis()->GetBinLabel(4);
  labels[4] = NEventsCuts_->GetXaxis()->GetBinLabel(5);
  labels[5] = NEventsCuts_->GetXaxis()->GetBinLabel(6);
  labels[6] = NEventsCuts_->GetXaxis()->GetBinLabel(7);
  labels[7] = NEventsCuts_->GetXaxis()->GetBinLabel(8);
  labels[8] = NEventsCuts_->GetXaxis()->GetBinLabel(9);
  labels[9] = NEventsCuts_->GetXaxis()->GetBinLabel(10);
  labels[10] = NEventsCuts_->GetXaxis()->GetBinLabel(11); 

  //Setting Color for Overlaid  Matched histograms
  MatchedTauMuPt_->SetLineColor(color);
  MatchedTauHadPt_->SetLineColor(color);
  MatchedTauHadEta_->SetLineColor(color);
  MatchedHT_->SetLineColor(color);
  MatchedBDiscCSV_->SetLineColor(color);

  MatchedTauMuPt_->SetTitle(tauDM.c_str() );
  MatchedTauHadPt_->SetTitle(tauDM.c_str() );
  MatchedTauHadEta_->SetTitle(tauDM.c_str() );
  MatchedHT_->SetTitle(tauDM.c_str() );
  MatchedBDiscCSV_->SetTitle(tauDM.c_str() );

  MassDiLepGEN_->SetLineColor(color);
  MassDiLepRECO_->SetLineColor(color);
  Mu3LargestPtMatch_->SetLineColor(color);
  Mu3PtMatch_->SetLineColor(color);
  PtOverMassMu1Mu2_->SetLineColor(color);
  PtMu1Mu2_->SetLineColor(color);

  MassDiLepGEN_->SetTitle(tauDM.c_str() );
  MassDiLepRECO_->SetTitle(tauDM.c_str() );
  Mu3LargestPtMatch_->SetTitle(tauDM.c_str() );
  Mu3PtMatch_->SetTitle(tauDM.c_str() );
  PtOverMassMu1Mu2_->SetTitle(tauDM.c_str() );

  MatchedTauMuPt_->Scale(scale);
  MatchedTauHadPt_->Scale(scale);
  MatchedTauHadEta_->Scale(scale);
  MatchedHT_->Scale(scale);
  MatchedBDiscCSV_->Scale(scale);

  MassDiLepGEN_->Scale(scale);
  MassDiLepRECO_->Scale(scale);
  Mu3LargestPtMatch_->Scale(scale);
  Mu3PtMatch_->Scale(scale);
  PtOverMassMu1Mu2_->Scale(scale);
  PtMu1Mu2_->Scale(scale);

  leg->AddEntry(MatchedTauHadPt_, legName.c_str(),"L");

  std::cout << "File: " << legName << std::endl;
  //Drawing all of the Overlaid  Matched HIstograms
  if (firstFile)
  {
    CanvasArray[0]->cd(quadrant );
    if (MatchedTauHadPt_->GetEntries() != 0)
      MatchedTauHadPt_->Draw();
    else 
      MatchedTauHadPt_->Draw();
    leg->Draw();
  
    CanvasArray[1]->cd(quadrant );
    if (MatchedTauMuPt_->GetEntries() != 0)
      MatchedTauMuPt_->Draw();
    else
      MatchedTauMuPt_->Draw();
    leg->Draw();
   
    CanvasArray[2]->cd(quadrant );
    if (MatchedTauHadEta_->GetEntries() != 0)
      MatchedTauHadEta_->Draw();
    else
      MatchedTauHadEta_->Draw();
    leg->Draw();
    
    CanvasArray[3]->cd(quadrant );
    if (MatchedHT_->GetEntries() != 0)
      MatchedHT_->Draw();
    else
      MatchedHT_->Draw();
    leg->Draw();
    
    CanvasArray[4]->cd(quadrant );
    if (MatchedBDiscCSV_->GetEntries() != 0)
      MatchedBDiscCSV_->Draw();
    else
      MatchedBDiscCSV_->Draw();
    leg->Draw();

    CanvasArray[5]->cd(quadrant );
    if (MatchedTauHadPt_->GetEntries() != 0)
      MatchedTauHadPt_->Draw();
    else
      MatchedTauHadPt_->Draw();
    leg->Draw();
    
    CanvasArray[6]->cd(quadrant );
    if (MatchedTauMuPt_->GetEntries() != 0)
      MatchedTauMuPt_->Draw();
    else
      MatchedTauMuPt_->Draw();
    leg->Draw();
    
    CanvasArray[7]->cd(quadrant );
    if (MatchedTauHadEta_->GetEntries() != 0) 
      MatchedTauHadEta_->Draw();
    else
      MatchedTauHadEta_->Draw();
    leg->Draw();
  
    CanvasArray[8]->cd(quadrant );
    if (MatchedHT_->GetEntries() != 0)
      MatchedHT_->Draw();
    else
      MatchedHT_->Draw();
    leg->Draw();
    
    CanvasArray[9]->cd(quadrant );
    if (MatchedBDiscCSV_->GetEntries() != 0) 
      MatchedBDiscCSV_->Draw();
    else
      MatchedBDiscCSV_->Draw();
    leg->Draw();

    CanvasArray[10]->cd(quadrant );
    if (MassDiLepGEN_->GetEntries() != 0)
      MassDiLepGEN_->Draw();
    else
      MassDiLepGEN_->Draw();
    leg->Draw();

    CanvasArray[11]->cd(quadrant );
    if (MassDiLepRECO_->GetEntries() != 0)
      MassDiLepRECO_->Draw();
    else
      MassDiLepRECO_->Draw();
    leg->Draw();

    CanvasArray[12]->cd(quadrant );
    if (Mu3LargestPtMatch_->GetEntries() != 0)
      Mu3LargestPtMatch_->Draw();
    else
      Mu3LargestPtMatch_->Draw();
    leg->Draw();

    CanvasArray[13]->cd(quadrant );
    if (Mu3PtMatch_->GetEntries() != 0)
      Mu3PtMatch_->Draw();
    else
      Mu3PtMatch_->Draw();
    leg->Draw();

    CanvasArray[14]->cd(quadrant );
    if (PtOverMassMu1Mu2_->GetEntries() != 0)
      PtOverMassMu1Mu2_->Draw();
    else
      PtOverMassMu1Mu2_->Draw();
    leg->Draw();
    
    CanvasArray[15]->cd(quadrant );
    if (PtMu1Mu2_->GetEntries() != 0)
      PtMu1Mu2_->Draw();
    else
      PtMu1Mu2_->Draw();
    leg->Draw();

  }//if firstFile 
  else
  {
    CanvasArray[0]->cd(quadrant );
    if (MatchedTauHadPt_->GetEntries() != 0)
      MatchedTauHadPt_->Draw("SAME");
    else
      MatchedTauHadPt_->Draw("SAME");
    leg->Draw();

    CanvasArray[1]->cd(quadrant );
    if (MatchedTauMuPt_->GetEntries() != 0)
      MatchedTauMuPt_->Draw("SAME");
    else
      MatchedTauMuPt_->Draw("SAME");
    leg->Draw();

    CanvasArray[2]->cd(quadrant );
    if (MatchedTauHadEta_->GetEntries() != 0)
      MatchedTauHadEta_->Draw("SAME");
    else
      MatchedTauHadEta_->Draw("SAME");
    leg->Draw();

    CanvasArray[3]->cd(quadrant );
    if (MatchedHT_->GetEntries() != 0)
      MatchedHT_->Draw("SAME");
    else
      MatchedHT_->Draw("SAME");
    leg->Draw();

    CanvasArray[4]->cd(quadrant );
    if (MatchedBDiscCSV_->GetEntries() != 0)
      MatchedBDiscCSV_->Draw("SAME");
    else
      MatchedBDiscCSV_->Draw("SAME");
    leg->Draw();

    CanvasArray[5]->cd(quadrant );
    if (MatchedTauHadPt_->GetEntries() != 0)
      MatchedTauHadPt_->Draw("SAME");
    else
      MatchedTauHadPt_->Draw("SAME");
    leg->Draw();

    CanvasArray[6]->cd(quadrant );
    if (MatchedTauMuPt_->GetEntries() != 0)
      MatchedTauMuPt_->Draw("SAME");
    else
      MatchedTauMuPt_->Draw("SAME");
    leg->Draw();

    CanvasArray[7]->cd(quadrant );
    if (MatchedTauHadEta_->GetEntries() != 0)
      MatchedTauHadEta_->Draw("SAME");
    else
      MatchedTauHadEta_->Draw("SAME");
    leg->Draw();

    CanvasArray[8]->cd(quadrant );
    if (MatchedHT_->GetEntries() != 0)
      MatchedHT_->Draw("SAME");
    else
      MatchedHT_->Draw("SAME");
    leg->Draw();

    CanvasArray[9]->cd(quadrant );
    if (MatchedBDiscCSV_->GetEntries() != 0)
      MatchedBDiscCSV_->Draw("SAME");
    else
      MatchedBDiscCSV_->Draw("SAME");
    leg->Draw();

    
    CanvasArray[10]->cd(quadrant );
    if (MassDiLepGEN_->GetEntries() != 0) 
      MassDiLepGEN_->Draw("SAME");
    else
      MassDiLepGEN_->Draw("SAME");
    leg->Draw();
    
    CanvasArray[11]->cd(quadrant );
    if (MassDiLepRECO_->GetEntries() != 0)
      MassDiLepRECO_->Draw("SAME");
    else
      MassDiLepRECO_->Draw("SAME");
    leg->Draw();
    
    CanvasArray[12]->cd(quadrant );
    if (Mu3LargestPtMatch_->GetEntries() != 0)
      Mu3LargestPtMatch_->Draw("SAME");
    else
      Mu3LargestPtMatch_->Draw("SAME");
    leg->Draw();
    
    CanvasArray[13]->cd(quadrant );
    if (Mu3PtMatch_->GetEntries() != 0)
      Mu3PtMatch_->Draw("SAME");
    else
      Mu3PtMatch_->Draw("SAME");
    leg->Draw();
    
    CanvasArray[14]->cd(quadrant );
    if (PtOverMassMu1Mu2_->GetEntries() != 0)
      PtOverMassMu1Mu2_->Draw("SAME");
    else
      PtOverMassMu1Mu2_->Draw("SAME");
    leg->Draw();
    
    CanvasArray[15]->cd(quadrant );
    if (PtMu1Mu2_->GetEntries() != 0)
      PtMu1Mu2_->Draw("SAME");
    else
      PtMu1Mu2_->Draw("SAME");
    leg->Draw();
  }//else

cout << "Histograms Drawn" << endl;
cout << "end" << endl;

}//rootMacro_BBA_combine

