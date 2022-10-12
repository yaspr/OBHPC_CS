#!/bin/bash

# Compiling the programs
echo "# Compiling programs"
gcc p2.c -o p2
gcc p3.c -o p3

# Running the programs
echo "# Executing programs"
echo -en "\t"
./p2 10 10

if [ $? -ne 0 ]
then
    echo "### ERROR executing p2"
    exit 1
fi

echo -en "\t"
./p3 10 10

if [ $? -ne 0 ]
then
    echo "### ERROR executing p3"
    exit 2
fi

echo "# Done executing programs"

echo

# Reading number of elements
n=$( head -n 1 c_f32.dat )

# Reading the elements
declare -a array_f32=(`tail -n1 c_f32.dat`)
declare -a array_f64=(`tail -n1 c_f64.dat`)

echo "# Calculating deltas"
rm -f "delta_f64_f32.dat"

# Comparing the generated results
for (( i=0; i < $n; i++ ));
do
    delta=$( echo "${array_f64[$i]} - ${array_f32[$i]}" | bc )
    
    #echo -e "\t${array_f64[$i]} - ${array_f32[$i]} = "$delta
    printf "%.16lf - %.6f = %.16lf\n" ${array_f64[$i]} ${array_f32[$i]} $delta
    
    if [ $( echo "$delta < 0.0" | bc ) -eq 1 ]  
    then
	delta=$( echo "$delta * -1.0" | bc )
    fi
    
    #echo $delta >> delta_f64_f32.dat
done
