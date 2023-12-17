#!/bin/bash

./main.py $2
gcc -O1 main.c -o exe

for ((j=1; j < $1; j++))
do
  for ((i=1; i < $1; i++))
  do
    ./exe i j
  done
done

sum=0
count=0

while read num; do
  if ((num < 100)); then
    sum=$((sum+num))
    count=$((count+1))
  fi
done < result.txt

average=$((sum/count))

echo $sum
echo $count
echo $average

