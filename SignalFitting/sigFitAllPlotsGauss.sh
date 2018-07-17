#!/bin/bash

for i in /home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL*;
do
  name=${i##*SIG_}
  massTEMP=${name%%_*}
  mass=${massTEMP##*a}
  sed -i "s|FILENAME|$i|g" signalfitGauss.C
  sed -i "s|OUTPUTNAME|${i##*FINAL_}|g" signalfitGauss.C
  sed -i "s|IMAGENAME|${name%.root}|g" signalfitGauss.C
  sed -i "s|, AMASS|, ${mass}|g" signalfitGauss.C
  root -l .x signalfitGauss.C > /home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/Gaussian_Reduced/Output_${name%.root}.out
  sed -i "s|$i|FILENAME|g" signalfitGauss.C
  sed -i "s|${i##*FINAL_}|OUTPUTNAME|g" signalfitGauss.C
  sed -i "s|${name%.root}|IMAGENAME|g" signalfitGauss.C
  sed -i "s|, ${mass}|, AMASS|g" signalfitGauss.C

done
