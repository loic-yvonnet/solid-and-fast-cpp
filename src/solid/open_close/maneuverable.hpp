#ifndef MANEUVERABLE_HPP
#define MANEUVERABLE_HPP

template <typename T>
concept maneuverable = requires(T unit) {
    unit.go_straight();
    unit.turn_right();
    unit.turn_left();
};

#endif