# .bashrc
#parse arguments
if [ $# -ne 2 ]
    then
    echo "Usage: ./generate.sh dirname file_string" 
    exit 0
fi
dir_name=$1
file_string=$2
for i in /home/kyletos/Downloads/RootFiles/ABCD_Tests/MiniAOD/$dir_name/*; 
do
  echo $i
  dirLs="$(ls $i | grep "$file_string")"
  if [ -z "$dirLs" ]; then
    echo "SKIPPED"
    continue
  fi
  echo "$dirLs" | while IFS= read -r line
  do
    temp=${line#*${dir_name}/}
    file_name=${temp%%.root}
    sample_name=${file_name##FINAL_}
    echo "file_name=$file_name     sample_name=$sample_name"
    sed -i -e "s|SAMPLENAME|$sample_name|g"  -e "s|DIR_NAME|$dir_name|g" -e "s|FILENAME|$file_name|g" SettingStyleFiles.C
    root -l .x SettingStyleFiles.C
    sed -i -e "s|$sample_name|SAMPLENAME|g"  -e "s|$dir_name|DIR_NAME|g" -e "s|$file_name|FILENAME|g" SettingStyleFiles.C
  done
echo ""
done


