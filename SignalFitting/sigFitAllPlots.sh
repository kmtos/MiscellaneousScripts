#!/bin/bash

for i in /home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/FINAL*;
do
  name=${i##*SIG_}
  massTEMP=${name%%_*}
  mass=${massTEMP##*a}
  sed -i "s|FILENAME|$i|g" signalfit.C
  sed -i "s|OUTPUTNAME|${i##*FINAL_}|g" signalfit.C
  sed -i "s|IMAGENAME|${name%.root}|g" signalfit.C
  sed -i "s|, AMASS|, ${mass}|g" signalfit.C
  root -l .x signalfit.C > /home/kyletos/Downloads/RootFiles/ABCD_Tests/ShapeDifferences/Output_${name%.root}.out
  sed -i "s|$i|FILENAME|g" signalfit.C
  sed -i "s|${i##*FINAL_}|OUTPUTNAME|g" signalfit.C
  sed -i "s|${name%.root}|IMAGENAME|g" signalfit.C
  sed -i "s|, ${mass}|, AMASS|g" signalfit.C

done
