#!/bin/bash

for i in /home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL*;
do
  name=${i##*SIG_}
  massTEMP=${name%%_*}
  mass=${massTEMP##*a}
  sed -i "s|FILENAME|$i|g" signalfitVoigt.C
  sed -i "s|OUTPUTNAME|${i##*FINAL_}|g" signalfitVoigt.C
  sed -i "s|IMAGENAME|${name%.root}|g" signalfitVoigt.C
  sed -i "s|, AMASS|, ${mass}|g" signalfitVoigt.C
  root -l .x signalfitVoigt.C > /home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/Voigtian_Reduced/Output_${name%.root}.out
  sed -i "s|$i|FILENAME|g" signalfitVoigt.C
  sed -i "s|${i##*FINAL_}|OUTPUTNAME|g" signalfitVoigt.C
  sed -i "s|${name%.root}|IMAGENAME|g" signalfitVoigt.C
  sed -i "s|, ${mass}|, AMASS|g" signalfitVoigt.C

done
