#include "maneuverable.hpp"
#include "tactics.hpp"
#include "tank.hpp"
#include "helicopter.hpp"

void apply_tactics() {
    helicopter helico;
    tank panzer;

    ambush(helico, panzer);
}