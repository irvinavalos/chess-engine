#include "chessboard.hpp"

int main(void) {
    auto board = CBoard();
    BBoard::printBoard(board.pawnAttacks[BBoard::Color::WHITE][11]);
    return 0;
}
