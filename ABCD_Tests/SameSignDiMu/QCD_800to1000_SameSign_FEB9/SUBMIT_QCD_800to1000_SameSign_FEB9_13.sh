#!/bin/bash

export SCRAM_ARCH=slc6_amd64_gcc481
cd /afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src
eval `scramv1 runtime -sh`
cd -
source /afs/cern.ch/cms/caf/setup.sh
cp /afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_800to1000_SameSign_FEB9/skimCheck_cfg_Single_QCD_800to1000_SameSign_FEB9_13.py .
cmsRun skimCheck_cfg_Single_QCD_800to1000_SameSign_FEB9_13.py
rm skimCheck_cfg_Single_QCD_800to1000_SameSign_FEB9_13.py 
exit 0
