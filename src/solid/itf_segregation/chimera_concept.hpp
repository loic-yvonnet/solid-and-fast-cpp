#ifndef CHIMERA_HPP
#define CHIMERA_HPP

template <typename T>
concept chimera = requires(T griffin) {
    griffin.fly();
    griffin.roar();
    griffin.sleep();
    griffin.hunt();
    griffin.run();
};

#endif