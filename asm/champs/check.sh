#!/bin/bash

filesDir="files"
myCors="myCors"
origCors="origCors"
asmFiles=($(ls $filesDir | grep ".s$"))


mkdir -p $myCors
mkdir -p $origCors


for file in "${asmFiles[@]}"
do
	fileName=${file%.*}

	corName=${fileName}.cor

	../a.out $filesDir/$file
	mv $filesDir/$corName $myCors/

	./asm1 $filesDir/$file > /dev/null
	mv $filesDir/$corName $origCors/

	myCor=$myCors/$corName
	origCor=$origCors/$corName

	if cmp -s "$myCor" "$origCor"
		then
			printf "%-35s\t\t\033[32mOK\033[0m\n" "$corName"
		else
			printf "%-35s\t\t\033[31mKO\033[0m\n" "$corName"
	fi
done
