#include "bitboard.hpp"

namespace {
    u64 shiftNortheast(u64 board) { return (board << 9) & ~FILE_A; }

    u64 shiftNorthwest(u64 board) { return (board << 7) & ~FILE_H; }

    u64 shiftSoutheast(u64 board) { return (board >> 7) & ~FILE_A; }

    u64 shiftSouthwest(u64 board) { return (board >> 9) & ~FILE_H; }

    u64 pawnEastAttack(u64 board, BBoard::Color color) {
        switch (color) {
        case BBoard::Color::WHITE:
            return shiftNortheast(board);
        case BBoard::Color::BLACK:
            return shiftSoutheast(board);
        }
    }

    u64 pawnWestAttack(u64 board, BBoard::Color color) {
        switch (color) {
        case BBoard::Color::WHITE:
            return shiftNorthwest(board);
        case BBoard::Color::BLACK:
            return shiftSouthwest(board);
        }
    }
} // namespace

BBoard::Square BBoard::getSquare(std::size_t row, std::size_t column) {
    return static_cast<Square>(MAX_COLS * row + column);
}

void BBoard::printBoard(u64 board) {
    std::printf("--------------------------------------------\n\n");
    for (std::size_t i = 8; i > 0; --i) {
        std::printf("\t%lu  ", i);
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
    std::printf("\n\t    a b c d e f g h\n\n");
    std::printf("  Board: 0x%llx\n\n", board);
}

void BBoard::setSquare(u64 &board, BBoard::Square square) {
    board |= (1ull << square);
}

u64 BBoard::whitePawnAnyAttack(u64 board) {
    return pawnWestAttack(board, BBoard::Color::WHITE) |
           pawnEastAttack(board, BBoard::Color::WHITE);
}

u64 BBoard::whitePawnDoubleAttack(u64 board) {
    return pawnWestAttack(board, BBoard::Color::WHITE) &
           pawnEastAttack(board, BBoard::Color::WHITE);
}

u64 BBoard::whitePawnSingleAttack(u64 board) {
    return pawnWestAttack(board, BBoard::Color::WHITE) ^
           pawnEastAttack(board, BBoard::Color::WHITE);
}

u64 BBoard::blackPawnAnyAttack(u64 board) {
    return pawnWestAttack(board, BBoard::Color::BLACK) |
           pawnEastAttack(board, BBoard::Color::BLACK);
}

u64 BBoard::blackPawnDoubleAttack(u64 board) {
    return pawnWestAttack(board, BBoard::Color::BLACK) &
           pawnEastAttack(board, BBoard::Color::BLACK);
}

u64 BBoard::blackPawnSingleAttack(u64 board) {
    return pawnWestAttack(board, BBoard::Color::BLACK) ^
           pawnEastAttack(board, BBoard::Color::BLACK);
}
