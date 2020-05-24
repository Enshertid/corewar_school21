#!/bin/bash
./corewar dut_cor_files/jumper dut_cor_files/jumper dut_cor_files/jumper -dump 24000 > 1.txt
./orig_cor dut_cor_files/jumper dut_cor_files/jumper dut_cor_files/jumper -dump 24000 > 2.txt
diff 1.txt 2.txt