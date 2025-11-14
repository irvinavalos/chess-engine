#include "chessboard.hpp"

u64 CBoard::generatePawnAttack(u64 board, BBoard::Color color) {
    u64 pawnAttack;
    switch (color) {
    case BBoard::Color::WHITE:
        pawnAttack = BBoard::whitePawnAnyAttack(board);
    case BBoard::Color::BLACK:
        pawnAttack = BBoard::blackPawnAnyAttack(board);
    }
    return pawnAttack;
}

void CBoard::initPawnAttacks() {
    for (auto i = 0; i < 64; ++i) {
        u64 board = 0ull;
        BBoard::setSquare(board, static_cast<BBoard::Square>(i));
        pawnAttacks[BBoard::Color::WHITE][i] =
            generatePawnAttack(board, BBoard::Color::WHITE);
        pawnAttacks[BBoard::Color::BLACK][i] =
            generatePawnAttack(board, BBoard::Color::BLACK);
    }
}
