#!/bin/bash

#champs=(-ls ~/curcus42_ensh/corewar/champs/*.cor)

#champs=( %ls ~/curcus42_ensh/corewar/champs/*.cor  )


champs=( $(ls dut_cor_files/*.cor) )
#dumps=(500 1000 1500 2000 2500 3000 3500 4000 4500 5000 5500 6000 6500 7000
#7500 8000 8500 9000 10000 11000 12000 13000 14000 15000 16000 17000 18000
#19000 20000 20500 21000 21500 22000 22500 23000 24000)
dumps=(20000 20500 21000 21500 22000 22500 23000 24000)
current_champ=dut_cor_files/jumper.cor
first=1.txt
second=2.txt*
for j in ${champs[@]}
do
  for i in ${dumps[@]}
  do
  ./corewar $current_champ $j -dump $i > 1.txt
  ./orig_cor $current_champ $j -d $i > 2.txt
  name=$j
  du=$i
  if ! diff -q $first $second &>/dev/null; then
    echo $name : $du == KO
    exit 1
  else
    echo $name : $du == OK
  fi
  done
done
for j in ${champs[@]}
do
  ./corewar $current_champ $j > 1.txt
  ./orig_cor $current_champ $j > 2.txt
  name=$j
  if ! diff -q $first $second &>/dev/null; then
    echo $name == KO
    exit 1
  else
    echo $name == OK
  fi
done
exit 0

#./corewar dut_cor_files/jumper.cor dut_cor_files/jumper.cor
# dut_cor_files/jumper.cor -dump 24000 > 1.txt
#./orig_cor dut_cor_files/jumper.cor dut_cor_files/jumper.cor
# dut_cor_files/jumper.cor -d 24000 > 2.txt
#diff 1.txt 2.txt