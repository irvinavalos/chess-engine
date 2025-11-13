#pragma once

#include "bitboard.hpp"
#include <array>

class CBoard {
    std::array<u64, 128> pawnAttacks;
};
