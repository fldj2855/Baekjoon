#!/bin/bash

for i in {1..50}; do
A=`../1655 < ./$i.in`
B=`cat ./$i.out`
if [[ $A != $B ]]; then
    echo 'wrong case' $i
fi
echo 
done