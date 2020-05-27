#!/bin/bash


folder="error"
array=($(ls $folder | grep ".s$"))


for File in "${array[@]}"
do

	echo FILE: $File

	valgrind ./asm $folder/$File
	echo  "" #newline

done
