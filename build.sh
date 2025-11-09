#!/usr/bin/sh

clang++ -std=c++20 -Wall -Wextra -Wpedantic board.cpp main.cpp -o main && ./main
