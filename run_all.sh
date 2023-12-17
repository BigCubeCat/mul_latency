#!/bin/bash

./main.py $2
gcc -O1 main.c -o exe

for ((j=1; j < $1; j++))
do
  ./exe 123 321
done

sum=0
count=0

while read num; do
    sum=$((sum+num))
    count=$((count+1))
done < result.txt


echo $sum
echo $count
echo $(echo "scale=2; $sum/$count" | bc)

