#!/bin/bash


folder="error"
array=($(ls $folder | grep ".s$"))


for File in "${array[@]}"
do

	echo FILE: $File

	valgrind ../a.out $folder/$File
	echo  "" #newline

done
