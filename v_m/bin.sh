#!/bin/bash
./corewar dut_cor_files/jumper.cor dut_cor_files/jumper.cor dut_cor_files/jumper.cor -dump 24000 > 1.txt
./orig_cor dut_cor_files/jumper.cor dut_cor_files/jumper.cor dut_cor_files/jumper.cor -d 24000 > 2.txt
diff 1.txt 2.txt