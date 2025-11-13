#!/usr/bin/sh

clang++ -std=c++20 -Wall -Wextra -Wpedantic -Iinclude src/board.cpp src/main.cpp -o main && ./main
