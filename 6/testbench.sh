#!/bin/zsh

make

echo 'bulid success'

read a
read b

c=`echo "$a $b" | ./6`
p=`echo "$a\n$b" | python testbench.py`

echo $c
echo $p

test $c = $p
echo $?