# .bashrc

for file in *; do
  #echo "$file"
  string1=${file:7}
  string2=${string1%%.*}
  tar -vxf ${file}
done

sumTotal=0
sumPassed=0
sumMuonIWantVisited=0
sumMuonIWantPassed=0
sumMuonIWantFailed=0

sumHighestPtVisited=0
sumHighestPtPassed=0
sumHighestPtFailed=0

sumMu1Mu2Visited=0
sumMu1Mu2Passed=0
sumMu1Mu2Failed=0

sumMassVisited=0
sumMassPassed=0
sumMassFailed=0

sumIsolationVisited=0
sumIsolationPassed=0
sumIsolationFailed=0

sumPtEtaCutVisited=0
sumPtEtaCutPassed=0
sumPtEtaCutFailed=0

sumMu3Visited=0
sumMu3Passed=0
sumMu3Failed=0

sumMu3IDVisited=0
sumMu3IDPassed=0
sumMu3IDFailed=0
  
sumMu45SelectorVisited=0
sumMu45SelectorPassed=0
sumMu45SelectorFailed=0

sumTauMuonPtSelectorVisited=0
sumTauMuonPtSelectorPassed=0
sumTauMuonPtSelectorFailed=0

for file in *stdout*; do
  countString=$(grep "TrigReport Events total =" $file)
  string11=${countString#*= }
  string12=${string11% passed*}
  sumTotal=$((sumTotal+string12))
  string21=${countString#*passed = }
  string22=${string21% failed*}
  sumPassed=$((sumPassed+string22))

  MuonIWantString=$(grep -m 1 " MuonIWant" $file)
  MuonIWantVisited=$(echo $MuonIWantString | cut -d " " -f 4)
  MuonIWantPassed=$(echo $MuonIWantString | cut -d " " -f 5)
  MuonIWantFailed=$(echo $MuonIWantString | cut -d " " -f 6)
  sumMuonIWantVisited=$((sumMuonIWantVisited+MuonIWantVisited))
  sumMuonIWantPassed=$((sumMuonIWantPassed+MuonIWantPassed))
  sumMuonIWantFailed=$((sumMuonIWantFailed+MuonIWantFailed))

  HighestPtString=$(grep -m 1 " HighestPtAndMuonOppositeSignDRSelector" $file)
  HighestPtVisited=$(echo $HighestPtString | cut -d " " -f 4)
  HighestPtPassed=$(echo $HighestPtString | cut -d " " -f 5)
  HighestPtFailed=$(echo $HighestPtString | cut -d " " -f 6)
  sumHighestPtVisited=$((sumHighestPtVisited+HighestPtVisited))
  sumHighestPtPassed=$((sumHighestPtPassed+HighestPtPassed))
  sumHighestPtFailed=$((sumHighestPtFailed+HighestPtFailed))
  
  Mu1Mu2String=$(grep -m 1 " Mu1Mu2PtRankMuonID" $file)
  Mu1Mu2Visited=$(echo $Mu1Mu2String | cut -d " " -f 4)
  Mu1Mu2Passed=$(echo $Mu1Mu2String | cut -d " " -f 5)
  Mu1Mu2Failed=$(echo $Mu1Mu2String | cut -d " " -f 6)
  sumMu1Mu2Visited=$((sumMu1Mu2Visited+Mu1Mu2Visited))
  sumMu1Mu2Passed=$((sumMu1Mu2Passed+Mu1Mu2Passed))
  sumMu1Mu2Failed=$((sumMu1Mu2Failed+Mu1Mu2Failed))

  MassString=$(grep -m 1 " Mu1Mu2MassSelection" $file)
  MassVisited=$(echo $MassString | cut -d " " -f 4)
  MassPassed=$(echo $MassString | cut -d " " -f 5)
  MassFailed=$(echo $MassString | cut -d " " -f 6)
  sumMassVisited=$((sumMassVisited+MassVisited))
  sumMassPassed=$((sumMassPassed+MassPassed))
  sumMassFailed=$((sumMassFailed+MassFailed))

  IsolationString=$(grep -m 1 " Isolation" $file)
  IsolationVisited=$(echo $IsolationString | cut -d " " -f 4)
  IsolationPassed=$(echo $IsolationString | cut -d " " -f 5)
  IsolationFailed=$(echo $IsolationString | cut -d " " -f 6)
  sumIsolationVisited=$((sumIsolationVisited+IsolationVisited))
  sumIsolationPassed=$((sumIsolationPassed+IsolationPassed))
  sumIsolationFailed=$((sumIsolationFailed+IsolationFailed))

  PtEtaCutString=$(grep -m 1 " PtEtaCut" $file)
  PtEtaCutVisited=$(echo $PtEtaCutString | cut -d " " -f 4)
  PtEtaCutPassed=$(echo $PtEtaCutString | cut -d " " -f 5)
  PtEtaCutFailed=$(echo $PtEtaCutString | cut -d " " -f 6)
  sumPtEtaCutVisited=$((sumPtEtaCutVisited+PtEtaCutVisited))
  sumPtEtaCutPassed=$((sumPtEtaCutPassed+PtEtaCutPassed))
  sumPtEtaCutFailed=$((sumPtEtaCutFailed+PtEtaCutFailed))

  Mu3String=$(grep -m 1 " Mu3" $file)
  Mu3Visited=$(echo $Mu3String | cut -d " " -f 4)
  Mu3Passed=$(echo $Mu3String | cut -d " " -f 5)
  Mu3Failed=$(echo $Mu3String | cut -d " " -f 6)
  sumMu3Visited=$((sumMu3Visited+Mu3Visited))
  sumMu3Passed=$((sumMu3Passed+Mu3Passed))
  sumMu3Failed=$((sumMu3Failed+Mu3Failed))

  Mu3IDString=$(grep -m 1 " Mu3ID" $file)
  Mu3IDVisited=$(echo $Mu3IDString | cut -d " " -f 4)
  Mu3IDPassed=$(echo $Mu3IDString | cut -d " " -f 5)
  Mu3IDFailed=$(echo $Mu3IDString | cut -d " " -f 6)
  sumMu3IDVisited=$((sumMu3IDVisited+Mu3IDVisited))
  sumMu3IDPassed=$((sumMu3IDPassed+Mu3IDPassed))
  sumMu3IDFailed=$((sumMu3IDFailed+Mu3IDFailed))

  Mu45SelectorString=$(grep -m 1 " Mu45Selector" $file)
  Mu45SelectorVisited=$(echo $Mu45SelectorString | cut -d " " -f 4)
  Mu45SelectorPassed=$(echo $Mu45SelectorString | cut -d " " -f 5)
  Mu45SelectorFailed=$(echo $Mu45SelectorString | cut -d " " -f 6)
  sumMu45SelectorVisited=$((sumMu45SelectorVisited+Mu45SelectorVisited))
  sumMu45SelectorPassed=$((sumMu45SelectorPassed+Mu45SelectorPassed))
  sumMu45SelectorFailed=$((sumMu45SelectorFailed+Mu45SelectorFailed))

 TauMuonPtSelectorString=$(grep -m 1 " tauMuonPtSelector" $file)
 TauMuonPtSelectorVisited=$(echo $TauMuonPtSelectorString | cut -d " " -f 4)
 TauMuonPtSelectorPassed=$(echo $TauMuonPtSelectorString | cut -d " " -f 5)
 TauMuonPtSelectorFailed=$(echo $TauMuonPtSelectorString | cut -d " " -f 6)
 sumTauMuonPtSelectorVisited=$((sumTauMuonPtSelectorVisited+TauMuonPtSelectorVisited))
 sumTauMuonPtSelectorPassed=$((sumTauMuonPtSelectorPassed+TauMuonPtSelectorPassed))
 sumTauMuonPtSelectorFailed=$((sumTauMuonPtSelectorFailed+TauMuonPtSelectorFailed))

done
echo "SumTotal= $sumTotal   sumPassed= $sumPassed"
echo "Visited= $sumMuonIWantVisited  Passed= $sumMuonIWantPassed  Failed= $sumMuonIWantFailed : MuonIWant"
echo "Visited= $sumHighestPtVisited  Passed= $sumHighestPtPassed  Failed= $sumHighestPtFailed : HighestPtAndMuonOppositeSignDRSelector"
echo "Visited= $sumMu1Mu2Visited   Passed= $sumMu1Mu2Passed   Failed= $sumMu1Mu2Failed : Mu1Mu2PtRankMuonID"
echo "Visited= $sumMassVisited   Passed= $sumMassPassed   Failed= $sumMassFailed : Mu1Mu2MassSelection"
echo "Visited= $sumIsolationVisited   Passed= $sumIsolationPassed   Failed= $sumIsolationFailed : Isolation"
echo "Visited= $sumIsolationVisited   Passed= $sumIsolationPassed   Failed= $sumIsolationFailed : Isolation"
echo "Visited= $sumPtEtaCutVisited    Passed= $sumPtEtaCutPassed    Failed= $sumPtEtaCutFailed : PtEtaCut"
echo "Visited= $sumMu45SelectorVisited    Passed= $sumMu45SelectorPassed    Failed= $sumMu45SelectorFailed : Mu45Selector"
echo "Visited= $sumMu3Visited    Passed= $sumMu3Passed    Failed= $sumMu3Failed : Mu3"
echo "Visited= $sumMu3IDVisited    Passed= $sumMu3IDPassed    Failed= $sumMu3IDFailed : Mu3ID"
echo "Visited= $sumTauMuonPtSelectorVisited    Passed= $sumTauMuonPtSelectorPassed    Failed= $sumTauMuonPtSelectorFailed : TauMuonPtSelector"



