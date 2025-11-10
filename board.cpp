#include "board.hpp"

int printBoard(u64 board) {
    std::printf("-------------------------\n");

    u64 shift = 1ull;
    std::size_t r;
    std::size_t c;

    for (r = numRows; r > 0; --r) {
        std::printf("%zu  ", r);
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
    std::printf("\n    a b c d e f g h\n");

    return 0;
}

int shiftBoard(u64 *board, square sq) {
    *board |= (1ull << sq);
    return 0;
}
