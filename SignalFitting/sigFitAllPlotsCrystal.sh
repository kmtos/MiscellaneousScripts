#!/bin/bash

for i in /home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL*;
do
  name=${i##*SIG_}
  massTEMP=${name%%_*}
  mass=${massTEMP##*a}
  sed -i "s|FILENAME|$i|g" signalfitCrystal.C
  sed -i "s|OUTPUTNAME|${i##*FINAL_}|g" signalfitCrystal.C
  sed -i "s|IMAGENAME|${name%.root}|g" signalfitCrystal.C
  sed -i "s|, AMASS|, ${mass}|g" signalfitCrystal.C
  root -l .x signalfitCrystal.C > /home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/CrystalBall_Reduced/Output_${name%.root}.out
  sed -i "s|$i|FILENAME|g" signalfitCrystal.C
  sed -i "s|${i##*FINAL_}|OUTPUTNAME|g" signalfitCrystal.C
  sed -i "s|${name%.root}|IMAGENAME|g" signalfitCrystal.C
  sed -i "s|, ${mass}|, AMASS|g" signalfitCrystal.C

done
