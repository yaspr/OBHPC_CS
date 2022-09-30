#!/bin/bash

#
input_csv="x86_64_insnlist.csv"

mem_dir="x86_mem"
arith_dir="x86_arith"
branch_dir="x86_branch"

#
echo "# Creating directories: "$mem_dir", "$arith_dir", "$branch_dir
mkdir -p $mem_dir $arith_dir $branch_dir

#
grep -i "memory" $input_csv > $mem_dir"/mem.csv"

#
grep -vi -e "memory" -e "jump" $input_csv > $arith_dir"/arith.csv"

#
grep -i "jump" $input_csv > $branch_dir"/branch.csv"

#Total number of instructions
total=$( wc -l $input_csv | cut -d' ' -f1 )
total=$(( $total - 1 ))

echo $total > "total_num_x86_instructions.dat"

#
total_mem=$( wc -l $mem_dir"/mem.csv" | cut -d' ' -f1 )
total_mem=$(( $total_mem - 1))

echo $total_mem > $mem_dir"/total_num_x86_mem_instructions.dat"

#
total_arith=$( wc -l $arith_dir"/arith.csv" | cut -d' ' -f1 )
total_arith=$(( $total_arith - 1))

echo $total_arith > $arith_dir"/total_num_x86_arith_instructions.dat"

#
total_branch=$( wc -l $branch_dir"/branch.csv" | cut -d' ' -f1 )
total_branch=$(( $total_branch - 1))

echo $total_branch > $branch_dir"/total_num_x86_branch_instructions.dat"

#
grep -i "sse" $mem_dir"/mem.csv" > $mem_dir"/sse.csv"
grep -i "avx" $mem_dir"/mem.csv" | grep -iv "avx512" > $mem_dir"/avx.csv"
grep -i "avx512" $mem_dir"/mem.csv" > $mem_dir"/avx512.csv"

#
grep -i "sse" $arith_dir"/arith.csv" > $arith_dir"/sse.csv"
grep -i "avx" $arith_dir"/arith.csv" | grep -iv "avx512" > $arith_dir"/avx.csv"
grep -i "avx512" $arith_dir"/arith.csv" > $arith_dir"/avx512.csv"

#
echo "# Number of instructions with implicit operands: "$( cut -d';' -f14 $input_csv | sort -n | uniq )

#
echo "# Number of 64-bit instructions: "$( grep -i "DATASZ_64" $input_csv | wc -l ) 

