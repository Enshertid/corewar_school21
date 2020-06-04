#!/bin/bash


folder="valid"
path="./$folder"
champs="./champs"
##path="/Users/ssoraka/Desktop/days/corewar/material/work/42-corewar/tests/vm/$folder"
tests=($(ls $champs | grep ".cor$"))

save="/Users/enshertid/curcus42_ensh/corewar/checker/$folder/$folder.txt"
save1="/Users/enshertid/curcus42_ensh/corewar/checker/$folder/errors.txt"

##rm -rf $save
##rm -rf $save1

touch $save
touch $save1

##number=(1 20 50 80 150 200 600 800 1400 2400 3000 4400 4450 5000 8000 10000 15000 20000)
number=(1000 5000 10000 15000 18000)

for file1 in "${tests[@]}"
do
	for file2 in "${tests[@]}"
	do
		need_check=$(cat $save | grep "$file1 $file2" | wc -l)
		if [ "$need_check" -eq "0" ]
		then
			echo "_$file1 $file2"
			for c in ${!number[@]}
			do
				num="${number[$c]}"

				my=$(./corewar -d $num $champs/$file1 $champs/$file2)
				notmy=$(./corewar1 -d $num $champs/$file1 $champs/$file2)
				if [ "$my" == "$notmy" ]
				then
					echo "$file1 $file2	$num: идентичны."
				else
					echo "$champs/$file1 $champs/$file2	$num: имеют различия."
					echo "$file1 $file2" >> $save1
				fi
			done
			echo "$file1 $file2" >> $save
		fi
	done
done
