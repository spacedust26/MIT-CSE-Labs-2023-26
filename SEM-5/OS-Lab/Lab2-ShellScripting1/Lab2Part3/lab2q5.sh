# Write a shell script that takes two sorted numeric files as input and produces a singlesorted numeric file without any duplicate contents.

sort -n -u $1 $2 -o $3

#./script.sh t1.txt t2.txt t3.txt