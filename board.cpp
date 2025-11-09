#include "board.hpp"

int printBoard(u64 board) {
    if (!board) { return 1; }

    u64 shift = 1ull;
    std::size_t r;
    std::size_t c;

    for (r = numRows; r > 0; --r) {
        for (c = 0; c < numCols; ++c) {
            std::size_t square = getSquare(r - 1, c);

            if ((shift << square) & board) {
                std::printf(" 1");
            } else {
                std::printf(" 0");
            }
        }
        std::printf("\n");
    }

    return 0;
}
