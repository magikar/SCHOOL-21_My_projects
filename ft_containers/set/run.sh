#!/bin/bash
if [ -z $1 ]
then
clang++ -Wall -Wextra -std=c++98   main.cpp -o set && ./set
elif [ $1 = "leak" ]
then
clang++ -Wall -Wextra -std=c++98   -D LEAKS=1 main.cpp -o set && ./set
elif [ $1 = "std" ]
then
clang++ -Wall -Wextra -std=c++98   -D CHECK=1 main.cpp -o set && ./set
fi

# clang++ main.cpp -o vector && ./vector