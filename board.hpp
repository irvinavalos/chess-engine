#pragma once

#include <cstdio>
#include "defs.hpp"

inline const std::size_t getSquare(std::size_t row, std::size_t col) {
    return 8 * row + col;
}

int printBoard(u64 board);

int shiftBoard(u64 *board, square sq);
