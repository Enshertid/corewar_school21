#!/bin/bash

folder="files"
path="./$folder"
array=($(ls $path | grep ".s$"))

validf="/home/user/aa/asm/champs/$folder/valid.txt"
error="/home/user/aa/asm/champs/$folder/errors.txt"

touch $validf
touch $error

# for ELEMENT in ${array[@]}
# do
# echo File: $ELEMENT.
# done

for FileToCheck in "${array[@]}"
do
	need_check=$(cat $validf | grep "$FileToCheck" | wc -l)
	if [ "$need_check" -eq "0" ]
	then
		echo $FileToCheck
		valgrind ./asm $path/$FileToCheck
		sleep 2
		clear
		# my=$(./asm $path/$FileToCheck)
		# notmy=$(./asm1 $path/FileToCheck)
		# if [ "$my" == "$notmy" ]
		# 	then
		# 		echo "$file1 $file2     $num: идентичны."
		# 	else
		# 		echo "$path/$file1 $path/$file2 $num: имеют различия."
		# 		echo "$file1 $file2" >> $save1
		# fi
		# echo "$file1 $file2" >> $save
	fi
done
