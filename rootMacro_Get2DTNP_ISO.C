#include "tdrstyle.C"
#include "CMS_lumi.C"
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


void rootMacro_Get2DTNP_ISO()
{

  setTDRStyle(true);
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);

  TFile *outFile = new TFile("/home/kyletos/Downloads/RootFiles/ABCD_Tests/TNP_JPsi_ISO_EFFICIENCIES_UP.root", "RECREATE");
 
////////////////////////////////
// Loose
////////////////////////////////
  double effLooseBD[3][4], effLooseEF[3][4], effLooseGH[3][4], effLooseMC[3][4], errLooseBD[3][4], errLooseEF[3][4], errLooseGH[3][4], errLooseMC[3][4];

  // Run BD Set Values
  effLooseBD[0][0] = .276;
  effLooseBD[0][1] = .307;
  effLooseBD[0][2] = .354;
  effLooseBD[0][3] = .374;

  effLooseBD[1][0] = .249;
  effLooseBD[1][1] = .275;
  effLooseBD[1][2] = .330;
  effLooseBD[1][3] = .348;

  effLooseBD[2][0] = .221;
  effLooseBD[2][1] = .247;
  effLooseBD[2][2] = .300;
  effLooseBD[2][3] = .34;

  errLooseBD[0][0] = .0008;
  errLooseBD[0][1] = .002;
  errLooseBD[0][2] = .001;
  errLooseBD[0][3] = .004;

  errLooseBD[1][0] = .002;
  errLooseBD[1][1] = .003;
  errLooseBD[1][2] = .002;
  errLooseBD[1][3] = .008;

  errLooseBD[2][0] = .003;
  errLooseBD[2][1] = .005;
  errLooseBD[2][2] = .004;
  errLooseBD[2][3] = .02;

  // SEttin EF Values
  effLooseEF[0][0] = .279;
  effLooseEF[0][1] = .317;
  effLooseEF[0][2] = .366;
  effLooseEF[0][3] = .392;

  effLooseEF[1][0] = .258;
  effLooseEF[1][1] = .274;
  effLooseEF[1][2] = .347;
  effLooseEF[1][3] = .38;

  effLooseEF[2][0] = .231;
  effLooseEF[2][1] = .26;
  effLooseEF[2][2] = .34;
  effLooseEF[2][3] = .32;

  errLooseEF[0][0] = .002;
  errLooseEF[0][1] = .004;
  errLooseEF[0][2] = .003;
  errLooseEF[0][3] = .009;

  errLooseEF[1][0] = .004;
  errLooseEF[1][1] = .007;
  errLooseEF[1][2] = .005;
  errLooseEF[1][3] = .02;

  errLooseEF[2][0] = .006;
  errLooseEF[2][1] = .01;
  errLooseEF[2][2] = .01;
  errLooseEF[2][3] = .04;

  //Setting GH values
  effLooseGH[0][0] = .281;
  effLooseGH[0][1] = .315;
  effLooseGH[0][2] = .375;
  effLooseGH[0][3] = .419;

  effLooseGH[1][0] = .259;
  effLooseGH[1][1] = .2855;
  effLooseGH[1][2] = .355;
  effLooseGH[1][3] = .38;

  effLooseGH[2][0] = .23;
  effLooseGH[2][1] = .257;
  effLooseGH[2][2] = .346;
  effLooseGH[2][3] = .35;

  errLooseGH[0][0] = .001;
  errLooseGH[0][1] = .003;
  errLooseGH[0][2] = .002;
  errLooseGH[0][3] = .006;

  errLooseGH[1][0] = .003;
  errLooseGH[1][1] = .0005;
  errLooseGH[1][2] = .004;
  errLooseGH[1][3] = .01;

  errLooseGH[2][0] = .005;
  errLooseGH[2][1] = .009;
  errLooseGH[2][2] = .007;
  errLooseGH[2][3] = .02;

  // Run MC Set Values
  effLooseMC[0][0] = .532;
  effLooseMC[0][1] = .564;
  effLooseMC[0][2] = .643;
  effLooseMC[0][3] = .687;

  effLooseMC[1][0] = .610;
  effLooseMC[1][1] = .648;
  effLooseMC[1][2] = .716;
  effLooseMC[1][3] = .74;

  effLooseMC[2][0] = .624;
  effLooseMC[2][1] = .65;
  effLooseMC[2][2] = .720;
  effLooseMC[2][3] = .76;

  errLooseMC[0][0] = .002;
  errLooseMC[0][1] = .003;
  errLooseMC[0][2] = .002;
  errLooseMC[0][3] = .006;

  errLooseMC[1][0] = .004;
  errLooseMC[1][1] = .007;
  errLooseMC[1][2] = .005;
  errLooseMC[1][3] = .01;

  errLooseMC[2][0] = .008;
  errLooseMC[2][1] = .01;
  errLooseMC[2][2] = .009;
  errLooseMC[2][3] = .02;

////////////////////////////////
// Medium2016
////////////////////////////////
  double effMedium2016BD[3][4], effMedium2016EF[3][4], effMedium2016GH[3][4], effMedium2016MC[3][4], errMedium2016BD[3][4], errMedium2016EF[3][4], errMedium2016GH[3][4], errMedium2016MC[3][4];

  // Run BD Set Values
  effMedium2016BD[0][0] = .2755;
  effMedium2016BD[0][1] = .306;
  effMedium2016BD[0][2] = .354;
  effMedium2016BD[0][3] = .373;

  effMedium2016BD[1][0] = .249;
  effMedium2016BD[1][1] = .275;
  effMedium2016BD[1][2] = .330;
  effMedium2016BD[1][3] = .345;

  effMedium2016BD[2][0] = .221;
  effMedium2016BD[2][1] = .246;
  effMedium2016BD[2][2] = .301;
  effMedium2016BD[2][3] = .34;

  errMedium2016BD[0][0] = .0008;
  errMedium2016BD[0][1] = .002;
  errMedium2016BD[0][2] = .001;
  errMedium2016BD[0][3] = .004;

  errMedium2016BD[1][0] = .002;
  errMedium2016BD[1][1] = .003;
  errMedium2016BD[1][2] = .002;
  errMedium2016BD[1][3] = .008;

  errMedium2016BD[2][0] = .003;
  errMedium2016BD[2][1] = .005;
  errMedium2016BD[2][2] = .004;
  errMedium2016BD[2][3] = .02;

  // SEttin EF Values
  effMedium2016EF[0][0] = .279;
  effMedium2016EF[0][1] = .316;
  effMedium2016EF[0][2] = .367;
  effMedium2016EF[0][3] = .39;

  effMedium2016EF[1][0] = .258;
  effMedium2016EF[1][1] = .271;
  effMedium2016EF[1][2] = .346;
  effMedium2016EF[1][3] = .38;

  effMedium2016EF[2][0] = .232;
  effMedium2016EF[2][1] = .261;
  effMedium2016EF[2][2] = .336;
  effMedium2016EF[2][3] = .3;

  errMedium2016EF[0][0] = .002;
  errMedium2016EF[0][1] = .004;
  errMedium2016EF[0][2] = .003;
  errMedium2016EF[0][3] = .01;

  errMedium2016EF[1][0] = .004;
  errMedium2016EF[1][1] = .007;
  errMedium2016EF[1][2] = .005;
  errMedium2016EF[1][3] = .02;

  errMedium2016EF[2][0] = .006;
  errMedium2016EF[2][1] = .01;
  errMedium2016EF[2][2] = .01;
  errMedium2016EF[2][3] = .06;

  //Setting GH values
  effMedium2016GH[0][0] = .281;
  effMedium2016GH[0][1] = .314;
  effMedium2016GH[0][2] = .375;
  effMedium2016GH[0][3] = .418;

  effMedium2016GH[1][0] = .259;
  effMedium2016GH[1][1] = .286;
  effMedium2016GH[1][2] = .354;
  effMedium2016GH[1][3] = .38;

  effMedium2016GH[2][0] = .230;
  effMedium2016GH[2][1] = .255;
  effMedium2016GH[2][2] = .346;
  effMedium2016GH[2][3] = .36;

  errMedium2016GH[0][0] = .001;
  errMedium2016GH[0][1] = .003;
  errMedium2016GH[0][2] = .002;
  errMedium2016GH[0][3] = .005;

  errMedium2016GH[1][0] = .003;
  errMedium2016GH[1][1] = .005;
  errMedium2016GH[1][2] = .004;
  errMedium2016GH[1][3] = .01;

  errMedium2016GH[2][0] = .005;
  errMedium2016GH[2][1] = .0009;
  errMedium2016GH[2][2] = .007;
  errMedium2016GH[2][3] = .02;

  // Run MC Set Values
  effMedium2016MC[0][0] = .532;
  effMedium2016MC[0][1] = .564;
  effMedium2016MC[0][2] = .643;
  effMedium2016MC[0][3] = .687;

  effMedium2016MC[1][0] = .611;
  effMedium2016MC[1][1] = .647;
  effMedium2016MC[1][2] = .716;
  effMedium2016MC[1][3] = .74;

  effMedium2016MC[2][0] = .624;
  effMedium2016MC[2][1] = .65;
  effMedium2016MC[2][2] = .721;
  effMedium2016MC[2][3] = .77;

  errMedium2016MC[0][0] = .002;
  errMedium2016MC[0][1] = .003;
  errMedium2016MC[0][2] = .002;
  errMedium2016MC[0][3] = .006;

  errMedium2016MC[1][0] = .004;
  errMedium2016MC[1][1] = .007;
  errMedium2016MC[1][2] = .005;
  errMedium2016MC[1][3] = .01;

  errMedium2016MC[2][0] = .008;
  errMedium2016MC[2][1] = .01;
  errMedium2016MC[2][2] = .009;
  errMedium2016MC[2][3] = .02;

////////////////////////////////
// Medium
////////////////////////////////
  double effMediumBD[3][4], effMediumEF[3][4], effMediumGH[3][4], effMediumMC[3][4], errMediumBD[3][4], errMediumEF[3][4], errMediumGH[3][4], errMediumMC[3][4];

  // Run BD Set Values
  effMediumBD[0][0] = .2755;
  effMediumBD[0][1] = .306;
  effMediumBD[0][2] = .354;
  effMediumBD[0][3] = .372;

  effMediumBD[1][0] = .249;
  effMediumBD[1][1] = .275;
  effMediumBD[1][2] = .330;
  effMediumBD[1][3] = .345;

  effMediumBD[2][0] = .221;
  effMediumBD[2][1] = .246;
  effMediumBD[2][2] = .301;
  effMediumBD[2][3] = .34;

  errMediumBD[0][0] = .0008;
  errMediumBD[0][1] = .002;
  errMediumBD[0][2] = .001;
  errMediumBD[0][3] = .004;

  errMediumBD[1][0] = .002;
  errMediumBD[1][1] = .003;
  errMediumBD[1][2] = .002;
  errMediumBD[1][3] = .008;

  errMediumBD[2][0] = .003;
  errMediumBD[2][1] = .005;
  errMediumBD[2][2] = .004;
  errMediumBD[2][3] = .02;

  // SEttin EF Values
  effMediumEF[0][0] = .279;
  effMediumEF[0][1] = .316;
  effMediumEF[0][2] = .366;
  effMediumEF[0][3] = .394;

  effMediumEF[1][0] = .258;
  effMediumEF[1][1] = .271;
  effMediumEF[1][2] = .346;
  effMediumEF[1][3] = .38;

  effMediumEF[2][0] = .233;
  effMediumEF[2][1] = .26;
  effMediumEF[2][2] = .336;
  effMediumEF[2][3] = .30;

  errMediumEF[0][0] = .002;
  errMediumEF[0][1] = .004;
  errMediumEF[0][2] = .003;
  errMediumEF[0][3] = .009;

  errMediumEF[1][0] = .004;
  errMediumEF[1][1] = .07;
  errMediumEF[1][2] = .005;
  errMediumEF[1][3] = .02;

  errMediumEF[2][0] = .006;
  errMediumEF[2][1] = .01;
  errMediumEF[2][2] = .01;
  errMediumEF[2][3] = .04;

  //Setting GH values
  effMediumGH[0][0] = .281;
  effMediumGH[0][1] = .314;
  effMediumGH[0][2] = .375;
  effMediumGH[0][3] = .418;

  effMediumGH[1][0] = .259;
  effMediumGH[1][1] = .286;
  effMediumGH[1][2] = .354;
  effMediumGH[1][3] = .38;

  effMediumGH[2][0] = .23;
  effMediumGH[2][1] = .255;
  effMediumGH[2][2] = .346;
  effMediumGH[2][3] = .36;

  errMediumGH[0][0] = .001;
  errMediumGH[0][1] = .003;
  errMediumGH[0][2] = .002;
  errMediumGH[0][3] = .006;

  errMediumGH[1][0] = .003;
  errMediumGH[1][1] = .005;
  errMediumGH[1][2] = .004;
  errMediumGH[1][3] = .01;

  errMediumGH[2][0] = .005;
  errMediumGH[2][1] = .009;
  errMediumGH[2][2] = .007;
  errMediumGH[2][3] = .02;

  // Run MC Set Values
  effMediumMC[0][0] = .532;
  effMediumMC[0][1] = .564;
  effMediumMC[0][2] = .643;
  effMediumMC[0][3] = .687;

  effMediumMC[1][0] = .611;
  effMediumMC[1][1] = .674;
  effMediumMC[1][2] = .716;
  effMediumMC[1][3] = .74;

  effMediumMC[2][0] = .624;
  effMediumMC[2][1] = .65;
  effMediumMC[2][2] = .721;
  effMediumMC[2][3] = .77;

  errMediumMC[0][0] = .002;
  errMediumMC[0][1] = .003;
  errMediumMC[0][2] = .002;
  errMediumMC[0][3] = .006;

  errMediumMC[1][0] = .004;
  errMediumMC[1][1] = .007;
  errMediumMC[1][2] = .005;
  errMediumMC[1][3] = .01;

  errMediumMC[2][0] = .008;
  errMediumMC[2][1] = .01;
  errMediumMC[2][2] = .009;
  errMediumMC[2][3] = .02;




////////////////////////////
// Declaring Canvases
////////////////////////////
  TCanvas *EtavsPtLooseISORunBDCanvas = new TCanvas("EtavsPtLooseISORunBDCanvas", "", 600, 600);
  TCanvas *EtavsPtMedium2016ISORunBDCanvas = new TCanvas("EtavsPtMedium2016ISORunBDCanvas", "", 600, 600);
  TCanvas *EtavsPtMediumISORunBDCanvas = new TCanvas("EtavsPtMediumISORunBDCanvas", "", 600, 600);
 
  TCanvas *EtavsPtLooseISORunEFCanvas = new TCanvas("EtavsPtLooseISORunEFCanvas", "", 600, 600);
  TCanvas *EtavsPtMedium2016ISORunEFCanvas = new TCanvas("EtavsPtMedium2016ISORunEFCanvas", "", 600, 600);
  TCanvas *EtavsPtMediumISORunEFCanvas = new TCanvas("EtavsPtMediumISORunEFCanvas", "", 600, 600);
 
  TCanvas *EtavsPtLooseISORunGHCanvas = new TCanvas("EtavsPtLooseISORunGHCanvas", "", 600, 600);
  TCanvas *EtavsPtMedium2016ISORunGHCanvas = new TCanvas("EtavsPtMedium2016ISORunGHCanvas", "", 600, 600);
  TCanvas *EtavsPtMediumISORunGHCanvas = new TCanvas("EtavsPtMediumISORunGHCanvas", "", 600, 600);
 
  TCanvas *EtavsPtLooseISOMCCanvas = new TCanvas("EtavsPtLooseISOMCCanvas", "", 600, 600);
  TCanvas *EtavsPtMedium2016ISOMCCanvas = new TCanvas("EtavsPtMedium2016ISOMCCanvas", "", 600, 600);
  TCanvas *EtavsPtMediumISOMCCanvas = new TCanvas("EtavsPtMediumISOMCCanvas", "", 600, 600);

  Float_t binsx[] = {3, 5, 10, 15, 20};
  Float_t binsy[] = {0, .9, 1.2, 2.1, 2.4};
  TH2F *EtavsPtLooseISORunBD_ = new TH2F("EtavsPtLooseISORunBD", "Loose ISO Efficiency Run B to D", sizeof(binsx)/sizeof(Float_t) - 1, binsx, sizeof(binsy)/sizeof(Float_t) - 1, binsy);
  TH2F *EtavsPtMedium2016ISORunBD_ = new TH2F("EtavsPtMedium2016ISORunBD", "Medium2016 ISO Efficiency Run B to D", sizeof(binsx)/sizeof(Float_t) - 1, binsx, sizeof(binsy)/sizeof(Float_t) - 1, binsy);
  TH2F *EtavsPtMediumISORunBD_ = new TH2F("EtavsPtMediumISORunBD", "Medium ISO Efficiency Run B to D", sizeof(binsx)/sizeof(Float_t) - 1, binsx, sizeof(binsy)/sizeof(Float_t) - 1, binsy);

  TH2F *EtavsPtLooseISORunEF_ = new TH2F("EtavsPtLooseISORunEF", "Loose ISO Efficiency Run E,F", sizeof(binsx)/sizeof(Float_t) - 1, binsx, sizeof(binsy)/sizeof(Float_t) - 1, binsy);
  TH2F *EtavsPtMedium2016ISORunEF_ = new TH2F("EtavsPtMedium2016ISORunEF", "Medium2016 ISO Efficiency Run E,F", sizeof(binsx)/sizeof(Float_t) - 1, binsx, sizeof(binsy)/sizeof(Float_t) - 1, binsy);
  TH2F *EtavsPtMediumISORunEF_ = new TH2F("EtavsPtMediumISORunEF", "Medium ISO Efficiency Run E,F", sizeof(binsx)/sizeof(Float_t) - 1, binsx, sizeof(binsy)/sizeof(Float_t) - 1, binsy);

  TH2F *EtavsPtLooseISORunGH_ = new TH2F("EtavsPtLooseISORunGH", "Loose ISO Efficiency Run G,H", sizeof(binsx)/sizeof(Float_t) - 1, binsx, sizeof(binsy)/sizeof(Float_t) - 1, binsy);
  TH2F *EtavsPtMedium2016ISORunGH_ = new TH2F("EtavsPtMedium2016ISORunGH", "Medium2016 ISO Efficiency Run G,H", sizeof(binsx)/sizeof(Float_t) - 1, binsx, sizeof(binsy)/sizeof(Float_t) - 1, binsy);
  TH2F *EtavsPtMediumISORunGH_ = new TH2F("EtavsPtMediumISORunGH", "Medium ISO Efficiency Run G,H", sizeof(binsx)/sizeof(Float_t) - 1, binsx, sizeof(binsy)/sizeof(Float_t) - 1, binsy);

  TH2F *EtavsPtLooseISOMC_ = new TH2F("EtavsPtLooseISOMC", "Loose ISO Efficiency", sizeof(binsx)/sizeof(Float_t) - 1, binsx, sizeof(binsy)/sizeof(Float_t) - 1, binsy);
  TH2F *EtavsPtMedium2016ISOMC_ = new TH2F("EtavsPtMedium2016ISOMC", "Medium2016 ISO Efficiency", sizeof(binsx)/sizeof(Float_t) - 1, binsx, sizeof(binsy)/sizeof(Float_t) - 1, binsy);
  TH2F *EtavsPtMediumISOMC_ = new TH2F("EtavsPtMediumISOMC", "Medium ISO Efficiency", sizeof(binsx)/sizeof(Float_t) - 1, binsx, sizeof(binsy)/sizeof(Float_t) - 1, binsy);

  for ( int i = 1; i <=3; i++)
  {
    for (int j = 1; j <=4; j++)
    {
      EtavsPtLooseISORunBD_->SetBinContent(i, j, effLooseBD[i-1][j-1] );
      EtavsPtLooseISORunBD_->SetBinError(i, j, errLooseBD[i-1][j-1] );
      EtavsPtMedium2016ISORunBD_->SetBinContent(i, j, effMedium2016BD[i-1][j-1] );
      EtavsPtMedium2016ISORunBD_->SetBinError(i, j, errMedium2016BD[i-1][j-1] );
      EtavsPtMediumISORunBD_->SetBinContent(i, j, effMediumBD[i-1][j-1] );
      EtavsPtMediumISORunBD_->SetBinError(i, j, errMediumBD[i-1][j-1] );

      EtavsPtLooseISORunEF_->SetBinContent(i, j, effLooseEF[i-1][j-1] );
      EtavsPtLooseISORunEF_->SetBinError(i, j, errLooseEF[i-1][j-1] );
      EtavsPtMedium2016ISORunEF_->SetBinContent(i, j, effMedium2016EF[i-1][j-1] );
      EtavsPtMedium2016ISORunEF_->SetBinError(i, j, errMedium2016EF[i-1][j-1] );
      EtavsPtMediumISORunEF_->SetBinContent(i, j, effMediumEF[i-1][j-1] );
      EtavsPtMediumISORunEF_->SetBinError(i, j, errMediumEF[i-1][j-1] );
      
      EtavsPtLooseISORunGH_->SetBinContent(i, j, effLooseGH[i-1][j-1] );
      EtavsPtLooseISORunGH_->SetBinError(i, j, errLooseGH[i-1][j-1] );
      EtavsPtMedium2016ISORunGH_->SetBinContent(i, j, effMedium2016GH[i-1][j-1] );
      EtavsPtMedium2016ISORunGH_->SetBinError(i, j, errMedium2016GH[i-1][j-1] );
      EtavsPtMediumISORunGH_->SetBinContent(i, j, effMediumGH[i-1][j-1] );
      EtavsPtMediumISORunGH_->SetBinError(i, j, errMediumGH[i-1][j-1] );

      EtavsPtLooseISOMC_->SetBinContent(i, j, effLooseMC[i-1][j-1] );
      EtavsPtLooseISOMC_->SetBinError(i, j, errLooseMC[i-1][j-1] );
      EtavsPtMedium2016ISOMC_->SetBinContent(i, j, effMedium2016MC[i-1][j-1] );
      EtavsPtMedium2016ISOMC_->SetBinError(i, j, errMedium2016MC[i-1][j-1] );
      EtavsPtMediumISOMC_->SetBinContent(i, j, effMediumMC[i-1][j-1] );
      EtavsPtMediumISOMC_->SetBinError(i, j, errMediumMC[i-1][j-1] );
    }//for j
  }//for i

  // Fill Style
  EtavsPtLooseISORunBD_->SetFillStyle(0);
  EtavsPtLooseISORunBD_->SetFillStyle(0);
  EtavsPtMedium2016ISORunBD_->SetFillStyle(0);
  EtavsPtMedium2016ISORunBD_->SetFillStyle(0);
  EtavsPtMediumISORunBD_->SetFillStyle(0);
  EtavsPtMediumISORunBD_->SetFillStyle(0);

  EtavsPtLooseISORunEF_->SetFillStyle(0);
  EtavsPtLooseISORunEF_->SetFillStyle(0);
  EtavsPtMedium2016ISORunEF_->SetFillStyle(0);
  EtavsPtMedium2016ISORunEF_->SetFillStyle(0);
  EtavsPtMediumISORunEF_->SetFillStyle(0);
  EtavsPtMediumISORunEF_->SetFillStyle(0);

  EtavsPtLooseISORunGH_->SetFillStyle(0);
  EtavsPtLooseISORunGH_->SetFillStyle(0);
  EtavsPtMedium2016ISORunGH_->SetFillStyle(0);
  EtavsPtMedium2016ISORunGH_->SetFillStyle(0);
  EtavsPtMediumISORunGH_->SetFillStyle(0);
  EtavsPtMediumISORunGH_->SetFillStyle(0);

  EtavsPtLooseISOMC_->SetFillStyle(0);
  EtavsPtLooseISOMC_->SetFillStyle(0);
  EtavsPtMedium2016ISOMC_->SetFillStyle(0);
  EtavsPtMedium2016ISOMC_->SetFillStyle(0);
  EtavsPtMediumISOMC_->SetFillStyle(0);
  EtavsPtMediumISOMC_->SetFillStyle(0);

  // Fill Color
  EtavsPtLooseISORunBD_->SetFillColor(0);
  EtavsPtLooseISORunBD_->SetFillColor(0);
  EtavsPtMedium2016ISORunBD_->SetFillColor(0);
  EtavsPtMedium2016ISORunBD_->SetFillColor(0);
  EtavsPtMediumISORunBD_->SetFillColor(0);
  EtavsPtMediumISORunBD_->SetFillColor(0);
  
  EtavsPtLooseISORunEF_->SetFillColor(0);
  EtavsPtLooseISORunEF_->SetFillColor(0);
  EtavsPtMedium2016ISORunEF_->SetFillColor(0);
  EtavsPtMedium2016ISORunEF_->SetFillColor(0);
  EtavsPtMediumISORunEF_->SetFillColor(0);
  EtavsPtMediumISORunEF_->SetFillColor(0);
  
  EtavsPtLooseISORunGH_->SetFillColor(0);
  EtavsPtLooseISORunGH_->SetFillColor(0);
  EtavsPtMedium2016ISORunGH_->SetFillColor(0);
  EtavsPtMedium2016ISORunGH_->SetFillColor(0);
  EtavsPtMediumISORunGH_->SetFillColor(0);
  EtavsPtMediumISORunGH_->SetFillColor(0);
  
  EtavsPtLooseISOMC_->SetFillColor(0);
  EtavsPtLooseISOMC_->SetFillColor(0);
  EtavsPtMedium2016ISOMC_->SetFillColor(0);
  EtavsPtMedium2016ISOMC_->SetFillColor(0);
  EtavsPtMediumISOMC_->SetFillColor(0);
  EtavsPtMediumISOMC_->SetFillColor(0);

  // Fill Color
  EtavsPtLooseISORunBD_->SetStats(false);
  EtavsPtLooseISORunBD_->SetStats(false);
  EtavsPtMedium2016ISORunBD_->SetStats(false);
  EtavsPtMedium2016ISORunBD_->SetStats(false);
  EtavsPtMediumISORunBD_->SetStats(false);
  EtavsPtMediumISORunBD_->SetStats(false);

  EtavsPtLooseISORunEF_->SetStats(false);
  EtavsPtLooseISORunEF_->SetStats(false);
  EtavsPtMedium2016ISORunEF_->SetStats(false);
  EtavsPtMedium2016ISORunEF_->SetStats(false);
  EtavsPtMediumISORunEF_->SetStats(false);
  EtavsPtMediumISORunEF_->SetStats(false);

  EtavsPtLooseISORunGH_->SetStats(false);
  EtavsPtLooseISORunGH_->SetStats(false);
  EtavsPtMedium2016ISORunGH_->SetStats(false);
  EtavsPtMedium2016ISORunGH_->SetStats(false);
  EtavsPtMediumISORunGH_->SetStats(false);
  EtavsPtMediumISORunGH_->SetStats(false);

  EtavsPtLooseISOMC_->SetStats(false);
  EtavsPtLooseISOMC_->SetStats(false);
  EtavsPtMedium2016ISOMC_->SetStats(false);
  EtavsPtMedium2016ISOMC_->SetStats(false);
  EtavsPtMediumISOMC_->SetStats(false);
  EtavsPtMediumISOMC_->SetStats(false);

  // Fill Color
  EtavsPtLooseISORunBD_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtLooseISORunBD_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMedium2016ISORunBD_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMedium2016ISORunBD_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMediumISORunBD_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMediumISORunBD_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  
  EtavsPtLooseISORunEF_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtLooseISORunEF_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMedium2016ISORunEF_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMedium2016ISORunEF_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMediumISORunEF_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMediumISORunEF_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");

  EtavsPtLooseISORunGH_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtLooseISORunGH_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMedium2016ISORunGH_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMedium2016ISORunGH_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMediumISORunGH_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMediumISORunGH_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");

  EtavsPtLooseISOMC_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtLooseISOMC_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMedium2016ISOMC_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMedium2016ISOMC_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMediumISOMC_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");
  EtavsPtMediumISOMC_->GetXaxis()->SetTitle("muon p_{T} (GeV/c)");

  // Fill Color
  EtavsPtLooseISORunBD_->GetXaxis()->SetTitleSize(.031);
  EtavsPtLooseISORunBD_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISORunBD_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISORunBD_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMediumISORunBD_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMediumISORunBD_->GetXaxis()->SetTitleSize(.031);

  EtavsPtLooseISORunEF_->GetXaxis()->SetTitleSize(.031);
  EtavsPtLooseISORunEF_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISORunEF_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISORunEF_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMediumISORunEF_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMediumISORunEF_->GetXaxis()->SetTitleSize(.031);

  EtavsPtLooseISORunGH_->GetXaxis()->SetTitleSize(.031);
  EtavsPtLooseISORunGH_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISORunGH_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISORunGH_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMediumISORunGH_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMediumISORunGH_->GetXaxis()->SetTitleSize(.031);

  EtavsPtLooseISOMC_->GetXaxis()->SetTitleSize(.031);
  EtavsPtLooseISOMC_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISOMC_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISOMC_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMediumISOMC_->GetXaxis()->SetTitleSize(.031);
  EtavsPtMediumISOMC_->GetXaxis()->SetTitleSize(.031);

  // Fill Color
  EtavsPtLooseISORunBD_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtLooseISORunBD_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMedium2016ISORunBD_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMedium2016ISORunBD_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMediumISORunBD_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMediumISORunBD_->GetYaxis()->SetTitle("muon |#eta|");

  EtavsPtLooseISORunEF_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtLooseISORunEF_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMedium2016ISORunEF_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMedium2016ISORunEF_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMediumISORunEF_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMediumISORunEF_->GetYaxis()->SetTitle("muon |#eta|");

  EtavsPtLooseISORunGH_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtLooseISORunGH_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMedium2016ISORunGH_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMedium2016ISORunGH_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMediumISORunGH_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMediumISORunGH_->GetYaxis()->SetTitle("muon |#eta|");

  EtavsPtLooseISOMC_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtLooseISOMC_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMedium2016ISOMC_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMedium2016ISOMC_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMediumISOMC_->GetYaxis()->SetTitle("muon |#eta|");
  EtavsPtMediumISOMC_->GetYaxis()->SetTitle("muon |#eta|");

  // Fill Color
  EtavsPtLooseISORunBD_->GetYaxis()->SetTitleSize(.031);
  EtavsPtLooseISORunBD_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISORunBD_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISORunBD_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMediumISORunBD_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMediumISORunBD_->GetYaxis()->SetTitleSize(.031);

  EtavsPtLooseISORunEF_->GetYaxis()->SetTitleSize(.031);
  EtavsPtLooseISORunEF_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISORunEF_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISORunEF_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMediumISORunEF_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMediumISORunEF_->GetYaxis()->SetTitleSize(.031);

  EtavsPtLooseISORunGH_->GetYaxis()->SetTitleSize(.031);
  EtavsPtLooseISORunGH_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISORunGH_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISORunGH_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMediumISORunGH_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMediumISORunGH_->GetYaxis()->SetTitleSize(.031);

  EtavsPtLooseISOMC_->GetYaxis()->SetTitleSize(.031);
  EtavsPtLooseISOMC_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISOMC_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMedium2016ISOMC_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMediumISOMC_->GetYaxis()->SetTitleSize(.031);
  EtavsPtMediumISOMC_->GetYaxis()->SetTitleSize(.031);

  // Fill Color
  EtavsPtLooseISORunBD_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtLooseISORunBD_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMedium2016ISORunBD_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMedium2016ISORunBD_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMediumISORunBD_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMediumISORunBD_->GetYaxis()->SetTitleOffset(1.1);

  EtavsPtLooseISORunEF_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtLooseISORunEF_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMedium2016ISORunEF_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMedium2016ISORunEF_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMediumISORunEF_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMediumISORunEF_->GetYaxis()->SetTitleOffset(1.1);

  EtavsPtLooseISORunGH_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtLooseISORunGH_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMedium2016ISORunGH_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMedium2016ISORunGH_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMediumISORunGH_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMediumISORunGH_->GetYaxis()->SetTitleOffset(1.1);

  EtavsPtLooseISOMC_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtLooseISOMC_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMedium2016ISOMC_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMedium2016ISOMC_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMediumISOMC_->GetYaxis()->SetTitleOffset(1.1);
  EtavsPtMediumISOMC_->GetYaxis()->SetTitleOffset(1.1);

  // Fill Color
  EtavsPtLooseISORunBD_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtLooseISORunBD_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMedium2016ISORunBD_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMedium2016ISORunBD_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMediumISORunBD_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMediumISORunBD_->GetXaxis()->SetTitleOffset(1.5);
  
  EtavsPtLooseISORunEF_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtLooseISORunEF_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMedium2016ISORunEF_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMedium2016ISORunEF_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMediumISORunEF_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMediumISORunEF_->GetXaxis()->SetTitleOffset(1.5);
 
  EtavsPtLooseISORunGH_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtLooseISORunGH_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMedium2016ISORunGH_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMedium2016ISORunGH_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMediumISORunGH_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMediumISORunGH_->GetXaxis()->SetTitleOffset(1.5);
  
  EtavsPtLooseISOMC_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtLooseISOMC_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMedium2016ISOMC_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMedium2016ISOMC_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMediumISOMC_->GetXaxis()->SetTitleOffset(1.5);
  EtavsPtMediumISOMC_->GetXaxis()->SetTitleOffset(1.5);

  EtavsPtLooseISORunBDCanvas->cd();
  EtavsPtLooseISORunBD_->Draw("COLZTEXT E");
  EtavsPtMedium2016ISORunBDCanvas->cd();
  EtavsPtMedium2016ISORunBD_->Draw("COLZTEXT E");
  EtavsPtMediumISORunBDCanvas->cd();
  EtavsPtMediumISORunBD_->Draw("COLZTEXT E");

  EtavsPtLooseISORunEFCanvas->cd();
  EtavsPtLooseISORunEF_->Draw("COLZTEXT E");
  EtavsPtMedium2016ISORunEFCanvas->cd();
  EtavsPtMedium2016ISORunEF_->Draw("COLZTEXT E");
  EtavsPtMediumISORunEFCanvas->cd();
  EtavsPtMediumISORunEF_->Draw("COLZTEXT E");

  EtavsPtLooseISORunGHCanvas->cd();
  EtavsPtLooseISORunGH_->Draw("COLZTEXT E");
  EtavsPtMedium2016ISORunGHCanvas->cd();
  EtavsPtMedium2016ISORunGH_->Draw("COLZTEXT E");
  EtavsPtMediumISORunGHCanvas->cd();
  EtavsPtMediumISORunGH_->Draw("COLZTEXT E");

  EtavsPtLooseISOMCCanvas->cd();
  EtavsPtLooseISOMC_->Draw("COLZTEXT E");
  EtavsPtMedium2016ISOMCCanvas->cd();
  EtavsPtMedium2016ISOMC_->Draw("COLZTEXT E");
  EtavsPtMediumISOMCCanvas->cd();
  EtavsPtMediumISOMC_->Draw("COLZTEXT E");

  writeExtraText = true;
  lumi_13TeV = "35.9 fb^{-1}";

  CMS_lumi(EtavsPtLooseISORunBDCanvas, 4, 11);
  CMS_lumi(EtavsPtMedium2016ISORunBDCanvas, 4, 11);
  CMS_lumi(EtavsPtMediumISORunBDCanvas, 4, 11);

  CMS_lumi(EtavsPtLooseISORunEFCanvas, 4, 11);
  CMS_lumi(EtavsPtMedium2016ISORunEFCanvas, 4, 11);
  CMS_lumi(EtavsPtMediumISORunEFCanvas, 4, 11);

  CMS_lumi(EtavsPtLooseISORunGHCanvas, 4, 11);
  CMS_lumi(EtavsPtMedium2016ISORunGHCanvas, 4, 11);
  CMS_lumi(EtavsPtMediumISORunGHCanvas, 4, 11);

  CMS_lumi(EtavsPtLooseISOMCCanvas, 4, 11);
  CMS_lumi(EtavsPtMedium2016ISOMCCanvas, 4, 11);
  CMS_lumi(EtavsPtMediumISOMCCanvas, 4, 11);

  outFile->cd();
  EtavsPtLooseISORunBDCanvas->Write();
  EtavsPtMedium2016ISORunBDCanvas->Write();
  EtavsPtMediumISORunBDCanvas->Write();
  
  EtavsPtLooseISORunEFCanvas->Write();
  EtavsPtMedium2016ISORunEFCanvas->Write();
  EtavsPtMediumISORunEFCanvas->Write();
  
  EtavsPtLooseISORunGHCanvas->Write();
  EtavsPtMedium2016ISORunGHCanvas->Write();
  EtavsPtMediumISORunGHCanvas->Write();
  
  EtavsPtLooseISOMCCanvas->Write();
  EtavsPtMedium2016ISOMCCanvas->Write();
  EtavsPtMediumISOMCCanvas->Write();


  TCanvas *EtavsPtLooseISORunBDtoMCCanvas = new TCanvas("EtavsPtLooseISORunBDtoMCCanvas", "", 600, 600);
  TCanvas *EtavsPtMedium2016ISORunBDtoMCCanvas = new TCanvas("EtavsPtMedium2016ISORunBDtoMCCanvas", "", 600, 600);
  TCanvas *EtavsPtMediumISORunBDtoMCCanvas = new TCanvas("EtavsPtMediumISORunBDtoMCCanvas", "", 600, 600);

  TCanvas *EtavsPtLooseISORunEFtoMCCanvas = new TCanvas("EtavsPtLooseISORunEFtoMCCanvas", "", 600, 600);
  TCanvas *EtavsPtMedium2016ISORunEFtoMCCanvas = new TCanvas("EtavsPtMedium2016ISORunEFtoMCCanvas", "", 600, 600);
  TCanvas *EtavsPtMediumISORunEFtoMCCanvas = new TCanvas("EtavsPtMediumISORunEFtoMCCanvas", "", 600, 600);

  TCanvas *EtavsPtLooseISORunGHtoMCCanvas = new TCanvas("EtavsPtLooseISORunGHtoMCCanvas", "", 600, 600);
  TCanvas *EtavsPtMedium2016ISORunGHtoMCCanvas = new TCanvas("EtavsPtMedium2016ISORunGHtoMCCanvas", "", 600, 600);
  TCanvas *EtavsPtMediumISORunGHtoMCCanvas = new TCanvas("EtavsPtMediumISORunGHtoMCCanvas", "", 600, 600);

  TH2F *EtavsPtLooseISORunBDtoMC_ = (TH2F*)EtavsPtLooseISORunBD_->Clone();
  TH2F *EtavsPtMedium2016ISORunBDtoMC_ = (TH2F*)EtavsPtMedium2016ISORunBD_->Clone();
  TH2F *EtavsPtMediumISORunBDtoMC_ = (TH2F*)EtavsPtMediumISORunBD_->Clone();

  TH2F *EtavsPtLooseISORunEFtoMC_ = (TH2F*)EtavsPtLooseISORunEF_->Clone();
  TH2F *EtavsPtMedium2016ISORunEFtoMC_ = (TH2F*)EtavsPtMedium2016ISORunEF_->Clone();
  TH2F *EtavsPtMediumISORunEFtoMC_ = (TH2F*)EtavsPtMediumISORunEF_->Clone();

  TH2F *EtavsPtLooseISORunGHtoMC_ = (TH2F*)EtavsPtLooseISORunGH_->Clone();
  TH2F *EtavsPtMedium2016ISORunGHtoMC_ = (TH2F*)EtavsPtMedium2016ISORunGH_->Clone();
  TH2F *EtavsPtMediumISORunGHtoMC_ = (TH2F*)EtavsPtMediumISORunGH_->Clone();

  EtavsPtLooseISORunBDtoMC_->SetName("EtavsPtLooseISORunBDtoMC");
  EtavsPtMedium2016ISORunBDtoMC_->SetName("EtavsPtMedium2016ISORunBDtoMC");
  EtavsPtMediumISORunBDtoMC_->SetName("EtavsPtMediumISORunBDtoMC");

  EtavsPtLooseISORunEFtoMC_->SetName("EtavsPtLooseISORunEFtoMC");
  EtavsPtMedium2016ISORunEFtoMC_->SetName("EtavsPtMedium2016ISORunEFtoMC");
  EtavsPtMediumISORunEFtoMC_->SetName("EtavsPtMediumISORunEFtoMC");

  EtavsPtLooseISORunGHtoMC_->SetName("EtavsPtLooseISORunGHtoMC");
  EtavsPtMedium2016ISORunGHtoMC_->SetName("EtavsPtMedium2016ISORunGHtoMC");
  EtavsPtMediumISORunGHtoMC_->SetName("EtavsPtMediumISORunGHtoMC");

  EtavsPtLooseISORunBDtoMC_->Divide(EtavsPtLooseISOMC_ );
  EtavsPtMedium2016ISORunBDtoMC_->Divide(EtavsPtMedium2016ISOMC_ );
  EtavsPtMediumISORunBDtoMC_->Divide(EtavsPtMediumISOMC_ );
  
  EtavsPtLooseISORunEFtoMC_->Divide(EtavsPtLooseISOMC_ );
  EtavsPtMedium2016ISORunEFtoMC_->Divide(EtavsPtMedium2016ISOMC_ );
  EtavsPtMediumISORunEFtoMC_->Divide(EtavsPtMediumISOMC_ );
  
  EtavsPtLooseISORunGHtoMC_->Divide(EtavsPtLooseISOMC_ );
  EtavsPtMedium2016ISORunGHtoMC_->Divide(EtavsPtMedium2016ISOMC_ );
  EtavsPtMediumISORunGHtoMC_->Divide(EtavsPtMediumISOMC_ );

  for ( int i = 1; i <=3; i++)
  {
    for (int j = 1; j <=4; j++)
    {
      EtavsPtLooseISORunBDtoMC_->SetBinContent(i,j,EtavsPtLooseISORunBDtoMC_->GetBinContent(i,j) + EtavsPtLooseISORunBDtoMC_->GetBinError(i,j) );
      EtavsPtMedium2016ISORunBDtoMC_->SetBinContent(i,j,EtavsPtMedium2016ISORunBDtoMC_->GetBinContent(i,j) + EtavsPtMedium2016ISORunBDtoMC_->GetBinError(i,j) );
      EtavsPtMediumISORunBDtoMC_->SetBinContent(i,j,EtavsPtMediumISORunBDtoMC_->GetBinContent(i,j) + EtavsPtMediumISORunBDtoMC_->GetBinError(i,j) );

      EtavsPtLooseISORunEFtoMC_->SetBinContent(i,j,EtavsPtLooseISORunEFtoMC_->GetBinContent(i,j) + EtavsPtLooseISORunEFtoMC_->GetBinError(i,j) );
      EtavsPtMedium2016ISORunEFtoMC_->SetBinContent(i,j,EtavsPtMedium2016ISORunEFtoMC_->GetBinContent(i,j) + EtavsPtMedium2016ISORunEFtoMC_->GetBinError(i,j) );
      EtavsPtMediumISORunEFtoMC_->SetBinContent(i,j,EtavsPtMediumISORunEFtoMC_->GetBinContent(i,j) + EtavsPtMediumISORunEFtoMC_->GetBinError(i,j) );

      EtavsPtLooseISORunGHtoMC_->SetBinContent(i,j,EtavsPtLooseISORunGHtoMC_->GetBinContent(i,j) + EtavsPtLooseISORunGHtoMC_->GetBinError(i,j) );
      EtavsPtMedium2016ISORunGHtoMC_->SetBinContent(i,j,EtavsPtMedium2016ISORunGHtoMC_->GetBinContent(i,j) + EtavsPtMedium2016ISORunGHtoMC_->GetBinError(i,j) );
      EtavsPtMediumISORunGHtoMC_->SetBinContent(i,j,EtavsPtMediumISORunGHtoMC_->GetBinContent(i,j) + EtavsPtMediumISORunGHtoMC_->GetBinError(i,j) );
    }//for j
  }//for i

  EtavsPtLooseISORunBDtoMCCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  EtavsPtLooseISORunBDtoMC_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette1 = (TPaletteAxis*)EtavsPtLooseISORunBDtoMC_->GetListOfFunctions()->FindObject("palette");
  palette1->SetX1NDC(0.88);
  palette1->SetX2NDC(0.92);
  palette1->SetY1NDC(0.1);
  palette1->SetY2NDC(0.97);

  EtavsPtMedium2016ISORunBDtoMCCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  EtavsPtMedium2016ISORunBDtoMC_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette2 = (TPaletteAxis*)EtavsPtMedium2016ISORunBDtoMC_->GetListOfFunctions()->FindObject("palette");
  palette2->SetX1NDC(0.88);
  palette2->SetX2NDC(0.92);
  palette2->SetY1NDC(0.1);
  palette2->SetY2NDC(0.97);

  EtavsPtMediumISORunBDtoMCCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  EtavsPtMediumISORunBDtoMC_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette3 = (TPaletteAxis*)EtavsPtMediumISORunBDtoMC_->GetListOfFunctions()->FindObject("palette");
  palette3->SetX1NDC(0.88);
  palette3->SetX2NDC(0.92);
  palette3->SetY1NDC(0.1);
  palette3->SetY2NDC(0.97);

  EtavsPtLooseISORunEFtoMCCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  EtavsPtLooseISORunEFtoMC_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette4 = (TPaletteAxis*)EtavsPtLooseISORunEFtoMC_->GetListOfFunctions()->FindObject("palette");
  palette4->SetX1NDC(0.88);
  palette4->SetX2NDC(0.92);
  palette4->SetY1NDC(0.1);
  palette4->SetY2NDC(0.97);

  EtavsPtMedium2016ISORunEFtoMCCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  EtavsPtMedium2016ISORunEFtoMC_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette5 = (TPaletteAxis*)EtavsPtMedium2016ISORunEFtoMC_->GetListOfFunctions()->FindObject("palette");
  palette5->SetX1NDC(0.88);
  palette5->SetX2NDC(0.92);
  palette5->SetY1NDC(0.1);
  palette5->SetY2NDC(0.97);

  EtavsPtMediumISORunEFtoMCCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  EtavsPtMediumISORunEFtoMC_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette6 = (TPaletteAxis*)EtavsPtMediumISORunEFtoMC_->GetListOfFunctions()->FindObject("palette");
  palette6->SetX1NDC(0.88);
  palette6->SetX2NDC(0.92);
  palette6->SetY1NDC(0.1);
  palette6->SetY2NDC(0.97);

  EtavsPtLooseISORunGHtoMCCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  EtavsPtLooseISORunGHtoMC_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette7 = (TPaletteAxis*)EtavsPtLooseISORunGHtoMC_->GetListOfFunctions()->FindObject("palette");
  palette7->SetX1NDC(0.88);
  palette7->SetX2NDC(0.92);
  palette7->SetY1NDC(0.1);
  palette7->SetY2NDC(0.97);

  EtavsPtMedium2016ISORunGHtoMCCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  EtavsPtMedium2016ISORunGHtoMC_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette8 = (TPaletteAxis*)EtavsPtMedium2016ISORunGHtoMC_->GetListOfFunctions()->FindObject("palette");
  palette8->SetX1NDC(0.88);
  palette8->SetX2NDC(0.92);
  palette8->SetY1NDC(0.1);
  palette8->SetY2NDC(0.97);

  EtavsPtMediumISORunGHtoMCCanvas->cd();
  gPad->SetLeftMargin(.1);
  gPad->SetRightMargin(.125);
  gPad->SetTopMargin(.03);
  gPad->SetBottomMargin(.1);
  EtavsPtMediumISORunGHtoMC_->Draw("COLZTEXT E");
  gPad->Update();
  TPaletteAxis *palette9 = (TPaletteAxis*)EtavsPtMediumISORunGHtoMC_->GetListOfFunctions()->FindObject("palette");
  palette9->SetX1NDC(0.88);
  palette9->SetX2NDC(0.92);
  palette9->SetY1NDC(0.1);
  palette9->SetY2NDC(0.97);

  writeExtraText = true;
  lumi_13TeV = "35.9 fb^{-1}";

  CMS_lumi(EtavsPtLooseISORunBDtoMCCanvas, 4, 11);
  CMS_lumi(EtavsPtMedium2016ISORunBDtoMCCanvas, 4, 11);
  CMS_lumi(EtavsPtMediumISORunBDtoMCCanvas, 4, 11);

  CMS_lumi(EtavsPtLooseISORunEFtoMCCanvas, 4, 11);
  CMS_lumi(EtavsPtMedium2016ISORunEFtoMCCanvas, 4, 11);
  CMS_lumi(EtavsPtMediumISORunEFtoMCCanvas, 4, 11);

  CMS_lumi(EtavsPtLooseISORunGHtoMCCanvas, 4, 11);
  CMS_lumi(EtavsPtMedium2016ISORunGHtoMCCanvas, 4, 11);
  CMS_lumi(EtavsPtMediumISORunGHtoMCCanvas, 4, 11);

  outFile->cd();
  EtavsPtLooseISORunBDtoMC_->Write();
  EtavsPtMedium2016ISORunBDtoMC_->Write();
  EtavsPtMediumISORunBDtoMC_->Write();
  
  EtavsPtLooseISORunEFtoMC_->Write();
  EtavsPtMedium2016ISORunEFtoMC_->Write();
  EtavsPtMediumISORunEFtoMC_->Write();
  
  EtavsPtLooseISORunGHtoMC_->Write();
  EtavsPtMedium2016ISORunGHtoMC_->Write();
  EtavsPtMediumISORunGHtoMC_->Write();

  EtavsPtLooseISORunBDtoMCCanvas->Write();
  EtavsPtMedium2016ISORunBDtoMCCanvas->Write();
  EtavsPtMediumISORunBDtoMCCanvas->Write();
  
  EtavsPtLooseISORunEFtoMCCanvas->Write();
  EtavsPtMedium2016ISORunEFtoMCCanvas->Write();
  EtavsPtMediumISORunEFtoMCCanvas->Write();
  
  EtavsPtLooseISORunGHtoMCCanvas->Write();
  EtavsPtMedium2016ISORunGHtoMCCanvas->Write();
  EtavsPtMediumISORunGHtoMCCanvas->Write();


  outFile->Close();
}// 
