import string
import numpy as np
import csv
import pandas as pd
import sys
from collections import defaultdict
pd.set_option('display.max_columns', 100000000000)
pd.set_option('display.max_rows', 1000000000000)

df_Dev = pd.read_csv('/home/kyletos/Downloads/RootFiles/ABCD_Tests/EventComparisons/CSV_Files/events_125_15_regionA.csv',header=0)
df_Kyl = pd.read_csv('/home/kyletos/Downloads/RootFiles/ABCD_Tests/EventComparisons/CSV_Files/MiniAOD_SIG_h125a15_MedIsoMu2_TauDMMedIso_AUG2_Central_HKinFit_EventList.csv', header=0)

df_Dev["total_ID"] = df_Dev["run"].astype(str) + "_" + df_Dev["lumi"].astype(str) + "_" + df_Dev["event"].astype(str)
df_Kyl["total_ID"] = df_Kyl["run"].astype(str) + "_" + df_Kyl["lumi"].astype(str) + "_" + df_Kyl["event"].astype(str) 

df_Dev["In_Kyl"] = False
df_Kyl["In_Dev"] = False

DevMatchedToKylTup = []
KylMatchedToDevTup = []

sumK = 0
for rowK in df_Kyl.itertuples():
  sumK += 1
  for rowD in df_Dev.itertuples():
    if getattr(rowK, "total_ID") == getattr(rowD, "total_ID"):
      print (sumK, "\t", getattr(rowK, "total_ID"), "  ", getattr(rowD, "total_ID"))
      KylMatchedToDevTup.append( (rowK[0], rowD[0]) )
      break

sumK = 0
for rowD in df_Dev.itertuples():
  sumK += 1
  for rowK in df_Kyl.itertuples():
    if getattr(rowK, "total_ID") == getattr(rowD, "total_ID"):
      print (sumK, "\t", getattr(rowK, "total_ID"), "  ", getattr(rowD, "total_ID"))
      DevMatchedToKylTup.append( (rowK[0], rowD[0]) )
      break


for i in KylMatchedToDevTup:
  print ("\n", i[0], df_Kyl.loc[i[0], 'total_ID'])
  print (i[1], df_Dev.loc[i[1], 'total_ID'])
  df_Kyl.loc[ i[0], 'InDev'] = True

for i in DevMatchedToKylTup:
  df_Dev.loc[ i[1], 'InKyl'] = True

df_Dev.to_csv("/home/kyletos/Downloads/RootFiles/ABCD_Tests/EventComparisons/DevinAll.csv", encoding='utf-8', index=False)
df_Kyl.to_csv("/home/kyletos/Downloads/RootFiles/ABCD_Tests/EventComparisons/KyleAll.csv", encoding='utf-8', index=False)

DevOnly  = df_Dev[ df_Dev['InKyl'] == False]
KyleOnly = df_Kyl[ df_Kyl['InDev'] == False]

DevOnly.to_csv("/home/kyletos/Downloads/RootFiles/ABCD_Tests/EventComparisons/DevinOnly.csv", encoding='utf-8', index=False)
KyleOnly.to_csv("/home/kyletos/Downloads/RootFiles/ABCD_Tests/EventComparisons/KyleOnly.csv", encoding='utf-8', index=False)





#df_DevLeft  = pd.merge(df_Kyl, df_Dev, on=["total_ID"], how="left",  indicator="BOTH")
#df_KylRight = pd.merge(df_Kyl, df_Dev, on=["total_ID"], how="right", indicator="BOTH")
#
#df_all = df_DevLeft.merge(df_KylRight, on=["total_ID"], how="left",  indicator="True")
#print(df_all.head(2) )
#DevOnly = df_DevLeft[ df_DevLeft["BOTH"] == "left_only"]
#KyleOnly = df_KylRight[ df_KylRight["BOTH"] == "left_only"]
#

