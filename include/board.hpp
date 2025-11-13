#pragma once

#include <cstdio>
#include <memory>

typedef unsigned long long u64;

constexpr std::size_t MAX_COLS = 8;

constexpr u64 A_FILE = 0x0101010101010101;
constexpr u64 H_FILE = 0x8080808080808080;
constexpr u64 RANK_8 = 0xff00000000000000;
constexpr u64 RANK_1 = 0x00000000000000ff;

namespace Board {
    // clang-format off
    enum Square {
        a1, b1, c1, d1, e1, f1, g1, h1,
        a2, b2, c2, d2, e2, f2, g2, h2,
        a3, b3, c3, d3, e3, f3, g3, h3,
        a4, b4, c4, d4, e4, f4, g4, h4,
        a5, b5, c5, d5, e5, f5, g5, h5,
        a6, b6, c6, d6, e6, f6, g6, h6,
        a7, b7, c7, d7, e7, f7, g7, h7,
        a8, b8, c8, d8, e8, f8, g8, h8
    };
    // clang-format on

    Square getSquare(std::size_t row, std::size_t column);

    void printBoard(u64 board);

    void setSquare(u64 &board, Square square);

} // namespace Board
