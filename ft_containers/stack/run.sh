#!/bin/bash
if [ -z $1 ]
then
clang++ -Wall -Wextra -std=c++98   main.cpp -o stack && ./stack
elif [ $1 = "leak" ]
then
clang++ -Wall -Wextra -std=c++98   -D LEAKS=1 main.cpp -o stack && ./stack
elif [ $1 = "std" ]
then
clang++ -Wall -Wextra -std=c++98   -D CHECK=1 main.cpp -o stack && ./stack
fi

# clang++ main.cpp -o stack && ./stack