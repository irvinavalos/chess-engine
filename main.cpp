#include "board.hpp"

int main(void) {
    int res;
    u64 board = 0ull;
    res = shiftBoard(&board, square::a1);
    res = shiftBoard(&board, square::a3);
    res = shiftBoard(&board, square::c1);
    res = shiftBoard(&board, square::c3);
    res = printBoard(board);
    return res;
}
