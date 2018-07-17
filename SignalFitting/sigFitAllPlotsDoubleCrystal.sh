#!/bin/bash

for i in /home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL*;
do
  name=${i##*SIG_}
  massTEMP=${name%%_*}
  mass=${massTEMP##*a}
  sed -i "s|FILENAME|$i|g" signalfitDoubleCrystal.C
  sed -i "s|OUTPUTNAME|${i##*FINAL_}|g" signalfitDoubleCrystal.C
  sed -i "s|IMAGENAME|${name%.root}|g" signalfitDoubleCrystal.C
  sed -i "s|, AMASS|, ${mass}|g" signalfitDoubleCrystal.C
  root -l .x signalfitDoubleCrystal.C > /home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/DoubleCrystalBall_Reduced/Output_${name%.root}.out
  sed -i "s|$i|FILENAME|g" signalfitDoubleCrystal.C
  sed -i "s|${i##*FINAL_}|OUTPUTNAME|g" signalfitDoubleCrystal.C
  sed -i "s|${name%.root}|IMAGENAME|g" signalfitDoubleCrystal.C
  sed -i "s|, ${mass}|, AMASS|g" signalfitDoubleCrystal.C

done
