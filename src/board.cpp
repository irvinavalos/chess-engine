#include "board.hpp"

Board::Square Board::getSquare(std::size_t row, std::size_t column) {
    return static_cast<Square>(MAX_COLS * row + column);
}

void Board::printBoard(u64 board) {
    for (std::size_t i = 8; i > 0; --i) {
        std::printf("%lu  ", i);
        for (std::size_t j = 0; j < 8; ++j) {
            auto s = getSquare(i - 1, j);
            if (board & (1ull << s)) {
                std::printf(" X");
            } else {
                std::printf(" 0");
            }
        }
        std::printf("\n");
    }
    std::printf("\n    a b c d e f g h\n\n");
    std::printf(" Board: 0x%llu\n", board);
}

void Board::setSquare(u64 &board, Board::Square square) {
    board |= (1ull << square);
}
