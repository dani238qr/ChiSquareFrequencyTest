#!/bin/bash

max=100000
for i in `seq 2 $max`
do
    echo -n "$(( ( RANDOM % 2 ) ))" >> shell_dataset.txt
done

