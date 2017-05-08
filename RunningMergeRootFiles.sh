# .bashrc

sed -i "s|DYHighMass|DYLowMass|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C  

sed -i "s|DYLowMass|QCD_1000toInf|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C 

sed -i "s|QCD_1000toInf|QCD_120to170|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|QCD_120to170|QCD_15to20|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|QCD_15to20|QCD_170to300|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|QCD_170to300|QCD_20to30|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|QCD_20to30|QCD_300to470|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|QCD_300to470|QCD_30to50|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|QCD_30to50|QCD_470to600|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|QCD_470to600|QCD_50to80|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|QCD_50to80|QCD_600to800|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|QCD_600to800|QCD_800to1000|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|QCD_800to1000|QCD_80to120|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|QCD_80to120|TTBar|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|TTBar|SignalH125a19|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|SignalH125a19|SignalH125a9|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|SignalH125a9|SignalH125a5|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|SignalH125a5|SignalH750a9|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C

sed -i "s|SignalH750a9|DYHighMass|g" MergeRootFiles_200.C
root -l .x MergeRootFiles_200.C




#DYLowMass
#QCD_1000toInf
#QCD_120to170
#QCD_15to20
#QCD_170to300
#QCD_20to30
#QCD_300to470
#QCD_30to50
#QCD_470to600
#QCD_50to80
#QCD_600to800
#QCD_800to1000
#QCD_80to120
#SignalH125a19
#SignalH125a5
#SignalH125a9
#SignalH750a9
#TTBar
#DYHighMass
