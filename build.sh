#!/usr/bin/sh

clang++ -std=c++20 -Wall -Wextra -Wpedantic -Iinclude src/bitboard.cpp src/chessboard.cpp src/main.cpp -o main && ./main
