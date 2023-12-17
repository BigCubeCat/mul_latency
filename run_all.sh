#!/bin/bash

./main.py 10000
gcc -O1 main.c -o exe

COUNT_RUNS=10

for ((j=1; j < COUNT_RUNS; j++))
do
  for ((i=1; i < COUNT_RUNS; i++))
  do
    ./exe i j
  done
done

