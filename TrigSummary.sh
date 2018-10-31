# .bashrc

for file in *; do
  #echo "$file"
  string1=${file:7}
  string2=${string1%%.*}
  tar -vxf ${file}
done

sumTotal=0
sumPassed=0
sumPreMuonsVisited=0
sumPreMuonsPassed=0
sumPreMuonsFailed=0

sumMuonsIDdxydzVisited=0
sumMuonsIDdxydzPassed=0
sumMuonsIDdxydzFailed=0
sumMuonsIDdxydzError=0

sumTrigMuMatcherVisited=0
sumTrigMuMatcherPassed=0
sumTrigMuMatcherFailed=0
sumTrigMuMatcherError=0

sumMassVisited=0
sumMassPassed=0
sumMassFailed=0
sumMassError=0

sumMu2IsoVisited=0
sumMu2IsoPassed=0
sumMu2IsoFailed=0
sumMu2IsoError=0

sumDiMuSigndRSelectorVisited=0
sumDiMuSigndRSelectorPassed=0
sumDiMuSigndRSelectorFailed=0
sumDiMuSigndRSelectorError=0

summuHadTauDMSelectorVisited=0
summuHadTauDMSelectorPassed=0
summuHadTauDMSelectorFailed=0
summuHadTauDMSelectorError=0

sumMu3Visited=0
sumMu3Passed=0
sumMu3Failed=0
sumMu3Error=0

summuHadTauDMIsoSelectorVisited=0
summuHadTauDMIsoSelectorPassed=0
summuHadTauDMIsoSelectorFailed=0
summuHadTauDMIsoSelectorError=0

for file in *stdout*; do
  countString=$(grep "TrigReport Events total =" $file)
  string11=${countString#*= }
  string12=${string11% passed*}
  sumTotal=$((sumTotal+string12))
  string21=${countString#*passed = }
  string22=${string21% failed*}
  sumPassed=$((sumPassed+string22))

  PreMuonsString=$(grep -m 1 " PreMuons" $file)
  PreMuonsVisited=$(echo $PreMuonsString | cut -d " " -f 4)
  PreMuonsPassed=$(echo $PreMuonsString | cut -d " " -f 5)
  PreMuonsFailed=$(echo $PreMuonsString | cut -d " " -f 6)
  PreMuonsError=$(echo $PreMuonsString | cut -d " " -f 7)
  sumPreMuonsVisited=$((sumPreMuonsVisited+PreMuonsVisited))
  sumPreMuonsPassed=$((sumPreMuonsPassed+PreMuonsPassed))
  sumPreMuonsFailed=$((sumPreMuonsFailed+PreMuonsFailed))
  sumPreMuonsError=$((sumPreMuonsError+PreMuonsError))

  MuonsIDdxydzString=$(grep -m 1 " MuonsIDdxydz" $file)
  MuonsIDdxydzVisited=$(echo $MuonsIDdxydzString | cut -d " " -f 4)
  MuonsIDdxydzPassed=$(echo $MuonsIDdxydzString | cut -d " " -f 5)
  MuonsIDdxydzFailed=$(echo $MuonsIDdxydzString | cut -d " " -f 6)
  MuonsIDdxydzError=$(echo $MuonsIDdxydzString | cut -d " " -f 7)
  sumMuonsIDdxydzVisited=$((sumMuonsIDdxydzVisited+MuonsIDdxydzVisited))
  sumMuonsIDdxydzPassed=$((sumMuonsIDdxydzPassed+MuonsIDdxydzPassed))
  sumMuonsIDdxydzFailed=$((sumMuonsIDdxydzFailed+MuonsIDdxydzFailed))
  sumMuonsIDdxydzError=$((sumMuonsIDdxydzError+MuonsIDdxydzError))
  
  TrigMuMatcherString=$(grep -m 1 " TrigMuMatcher" $file)
  TrigMuMatcherVisited=$(echo $TrigMuMatcherString | cut -d " " -f 4)
  TrigMuMatcherPassed=$(echo $TrigMuMatcherString | cut -d " " -f 5)
  TrigMuMatcherFailed=$(echo $TrigMuMatcherString | cut -d " " -f 6)
  TrigMuMatcherError=$(echo $TrigMuMatcherString | cut -d " " -f 7)
  sumTrigMuMatcherVisited=$((sumTrigMuMatcherVisited+TrigMuMatcherVisited))
  sumTrigMuMatcherPassed=$((sumTrigMuMatcherPassed+TrigMuMatcherPassed))
  sumTrigMuMatcherFailed=$((sumTrigMuMatcherFailed+TrigMuMatcherFailed))
  sumTrigMuMatcherError=$((sumTrigMuMatcherError+TrigMuMatcherError))

  MassString=$(grep -m 1 " InvMassCut" $file)
  MassVisited=$(echo $MassString | cut -d " " -f 4)
  MassPassed=$(echo $MassString | cut -d " " -f 5)
  MassFailed=$(echo $MassString | cut -d " " -f 6)
  MassError=$(echo $MassString | cut -d " " -f 7)
  sumMassVisited=$((sumMassVisited+MassVisited))
  sumMassPassed=$((sumMassPassed+MassPassed))
  sumMassFailed=$((sumMassFailed+MassFailed))
  sumMassError=$((sumMassError+MassError))

  Mu2IsoString=$(grep -m 1 " Mu2Iso" $file)
  Mu2IsoVisited=$(echo $Mu2IsoString | cut -d " " -f 4)
  Mu2IsoPassed=$(echo $Mu2IsoString | cut -d " " -f 5)
  Mu2IsoFailed=$(echo $Mu2IsoString | cut -d " " -f 6)
  Mu2IsoError=$(echo $Mu2IsoString | cut -d " " -f 7)
  sumMu2IsoVisited=$((sumMu2IsoVisited+Mu2IsoVisited))
  sumMu2IsoPassed=$((sumMu2IsoPassed+Mu2IsoPassed))
  sumMu2IsoFailed=$((sumMu2IsoFailed+Mu2IsoFailed))
  sumMu2IsoError=$((sumMu2IsoError+Mu2IsoError))

  DiMuSigndRSelectorString=$(grep -m 1 " DiMuSigndRSelector" $file)
  DiMuSigndRSelectorVisited=$(echo $DiMuSigndRSelectorString | cut -d " " -f 4)
  DiMuSigndRSelectorPassed=$(echo $DiMuSigndRSelectorString | cut -d " " -f 5)
  DiMuSigndRSelectorFailed=$(echo $DiMuSigndRSelectorString | cut -d " " -f 6)
  DiMuSigndRSelectorError=$(echo $DiMuSigndRSelectorString | cut -d " " -f 7)
  sumDiMuSigndRSelectorVisited=$((sumDiMuSigndRSelectorVisited+DiMuSigndRSelectorVisited))
  sumDiMuSigndRSelectorPassed=$((sumDiMuSigndRSelectorPassed+DiMuSigndRSelectorPassed))
  sumDiMuSigndRSelectorFailed=$((sumDiMuSigndRSelectorFailed+DiMuSigndRSelectorFailed))
  sumDiMuSigndRSelectorError=$((sumDiMuSigndRSelectorError+DiMuSigndRSelectorError))

  muHadTauDMSelectorString=$(grep -m 1 " muHadTauDMSelector" $file)
  muHadTauDMSelectorVisited=$(echo $muHadTauDMSelectorString | cut -d " " -f 4)
  muHadTauDMSelectorPassed=$(echo $muHadTauDMSelectorString | cut -d " " -f 5)
  muHadTauDMSelectorFailed=$(echo $muHadTauDMSelectorString | cut -d " " -f 6)
  muHadTauDMSelectorError=$(echo $muHadTauDMSelectorString | cut -d " " -f 7)
  summuHadTauDMSelectorVisited=$((summuHadTauDMSelectorVisited+muHadTauDMSelectorVisited))
  summuHadTauDMSelectorPassed=$((summuHadTauDMSelectorPassed+muHadTauDMSelectorPassed))
  summuHadTauDMSelectorFailed=$((summuHadTauDMSelectorFailed+muHadTauDMSelectorFailed))
  summuHadTauDMSelectorError=$((summuHadTauDMSelectorError+muHadTauDMSelectorError))

  Mu3String=$(grep -m 1 " Mu3" $file)
  Mu3Visited=$(echo $Mu3String | cut -d " " -f 4)
  Mu3Passed=$(echo $Mu3String | cut -d " " -f 5)
  Mu3Failed=$(echo $Mu3String | cut -d " " -f 6)
  Mu3Error=$(echo $Mu3String | cut -d " " -f 7)
  sumMu3Visited=$((sumMu3Visited+Mu3Visited))
  sumMu3Passed=$((sumMu3Passed+Mu3Passed))
  sumMu3Failed=$((sumMu3Failed+Mu3Failed))
  sumMu3Error=$((sumMu3Error+Mu3Error))

  muHadTauDMIsoSelectorString=$(grep -m 1 " muHadTauDMIsoSelector" $file)
  muHadTauDMIsoSelectorVisited=$(echo $muHadTauDMIsoSelectorString | cut -d " " -f 4)
  muHadTauDMIsoSelectorPassed=$(echo $muHadTauDMIsoSelectorString | cut -d " " -f 5)
  muHadTauDMIsoSelectorFailed=$(echo $muHadTauDMIsoSelectorString | cut -d " " -f 6)
  muHadTauDMIsoSelectorError=$(echo $muHadTauDMIsoSelectorString | cut -d " " -f 7)
  summuHadTauDMIsoSelectorVisited=$((summuHadTauDMIsoSelectorVisited+muHadTauDMIsoSelectorVisited))
  summuHadTauDMIsoSelectorPassed=$((summuHadTauDMIsoSelectorPassed+muHadTauDMIsoSelectorPassed))
  summuHadTauDMIsoSelectorFailed=$((summuHadTauDMIsoSelectorFailed+muHadTauDMIsoSelectorFailed))
  summuHadTauDMIsoSelectorError=$((summuHadTauDMIsoSelectorError+muHadTauDMIsoSelectorError))

done
echo "SumTotal= $sumTotal   sumPassed= $sumPassed"
echo "Visited= $sumPreMuonsVisited  Passed= $sumPreMuonsPassed  Failed= $sumPreMuonsFailed  Error= $sumPreMuonsError : PreMuons"
echo "Visited= $sumMuonsIDdxydzVisited  Passed= $sumMuonsIDdxydzPassed  Failed= $sumMuonsIDdxydzFailed  Error= $sumMuonsIDdxydzError : MuonsIDdxydz"
echo "Visited= $sumTrigMuMatcherVisited   Passed= $sumTrigMuMatcherPassed   Failed= $sumTrigMuMatcherFailed  Error= $sumTrigMuMatcherError : TrigMuMatcher"
echo "Visited= $sumMassVisited   Passed= $sumMassPassed   Failed= $sumMassFailed  Error= $sumMassError : InvMassCut"
echo "Visited= $sumMu2IsoVisited   Passed= $sumMu2IsoPassed   Failed= $sumMu2IsoFailed  Error= $sumMu2IsoError : Mu2Iso"
echo "Visited= $sumDiMuSigndRSelectorVisited   Passed= $sumDiMuSigndRSelectorPassed   Failed= $sumDiMuSigndRSelectorFailed  Error= $sumDiMuSigndRSelectorError : DiMuSigndRSelector"
echo "Visited= $sumMu3Visited    Passed= $sumMu3Passed    Failed= $sumMu3Failed  Error= $sumMu3Error : Mu3"
echo "Visited= $summuHadTauDMSelectorVisited    Passed= $summuHadTauDMSelectorPassed   Failed= $summuHadTauDMSelectorFailed  Error= $summuHadTauDMSelectorError : muHadTauDMSelector"
echo "Visited= $summuHadTauDMIsoSelectorVisited    Passed= $summuHadTauDMIsoSelectorPassed   Failed= $summuHadTauDMIsoSelectorFailed  Error= $summuHadTauDMIsoSelectorError : muHadTauDMIsoSelector"
