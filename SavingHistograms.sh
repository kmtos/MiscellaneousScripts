# .bashrc
#parse arguments
if [ $# -ne 2 ]
    then
    echo "Usage: ./generate.sh dirname file_string" 
    exit 0
fi
dir_name=$1
file_string=$2
for i in /home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/*.root; 
do
  echo $i
  dirLs="$(ls $i | grep "$file_string")"
  if [ -z "$dirLs" ]; then
    echo "SKIPPED"
    continue
  fi
  echo "$dirLs" | while IFS= read -r line
  do
    file_name=${line##*/}
    sample_name=${file_name%%.root}
    mkdir /home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/Plots/${sample_name}
    echo "file_name=$file_name"
    sed -i -e "s|DIR_NAME|$sample_name|g" -e "s|FILENAME|$file_name|g" SavingHistograms.C
    root -l .x SavingHistograms.C
    sed -i -e "s|$sample_name|DIR_NAME|g" -e "s|$file_name|FILENAME|g" SavingHistograms.C
  done
echo ""
done


