#!/bin/bash

export SCRAM_ARCH=slc6_amd64_gcc481
cd /afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src
eval `scramv1 runtime -sh`
cd -
source /afs/cern.ch/cms/caf/setup.sh
cp /afs/cern.ch/user/k/ktos/GroupDir/CMSSW_8_0_17/src/AnalyzerGeneratorRecoVariousFunctions/Analyzer/BSUB/QCD_470to600_SameSign_FEB9/skimCheck_cfg_Single_QCD_470to600_SameSign_FEB9_22.py .
cmsRun skimCheck_cfg_Single_QCD_470to600_SameSign_FEB9_22.py
rm skimCheck_cfg_Single_QCD_470to600_SameSign_FEB9_22.py 
exit 0