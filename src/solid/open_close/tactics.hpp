#ifndef TACTICS_HPP
#define TACTICS_HPP

#include "maneuverable.hpp"

constexpr void ambush(maneuverable auto& unit1, maneuverable auto& unit2) noexcept {
    unit1.turn_left();
    unit1.go_straight();

    unit2.turn_right();
    unit2.go_straight();
}

#endif