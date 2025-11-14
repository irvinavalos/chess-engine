#pragma once

#include "bitboard.hpp"
#include <array>

class CBoard {
private:
    u64 generatePawnAttack(u64 board, BBoard::Color color);

public:
    std::array<std::array<u64, 64>, 2> pawnAttacks;

    CBoard() { initPawnAttacks(); };

    void initPawnAttacks();
};
