#include "bitboard.hpp"

BBoard::Square BBoard::getSquare(std::size_t row, std::size_t column) {
    return static_cast<Square>(MAX_COLS * row + column);
}

void BBoard::printBoard(u64 board) {
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

void BBoard::setSquare(u64 &board, BBoard::Square square) {
    board |= (1ull << square);
}

u64 BBoard::shiftNortheast(u64 board) { return (board << 9) & ~FILE_A; }

u64 BBoard::shiftNorthwest(u64 board) { return (board << 7) & ~FILE_H; }

u64 BBoard::whitePawnEastAttack(u64 board) { return shiftNortheast(board); }

u64 BBoard::whitePawnWestAttack(u64 board) { return shiftNorthwest(board); }

u64 BBoard::whitePawnAnyAttack(u64 board) {
    return whitePawnWestAttack(board) | whitePawnEastAttack(board);
}

u64 BBoard::whitePawnDoubleAttack(u64 board) {
    return whitePawnWestAttack(board) & whitePawnEastAttack(board);
}

u64 BBoard::whitePawnSingleAttack(u64 board) {
    return whitePawnWestAttack(board) ^ whitePawnEastAttack(board);
}
