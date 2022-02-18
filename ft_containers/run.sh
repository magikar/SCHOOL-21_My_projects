#!/bin/bash
if [ -z $1 ]
then
clang++ main.cpp -o a.out && ./a.out ab
elif [ $1 = "leak" ]
then
clang++ -D LEAKS=1 main.cpp -o a.out && ./a.out ab
elif [ $1 = "std" ]
then
clang++ -D CHECK=1 main.cpp -o a.out && ./a.out ab
fi

# clang++ main.cpp -o vector && ./vector