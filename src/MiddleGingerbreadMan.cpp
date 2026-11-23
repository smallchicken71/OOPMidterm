#include "MiddleGingerbreadMan.hpp"

#include <utility>

MiddleGingerbreadMan::MiddleGingerbreadMan(
    std::string name, Element type, int damage, int defense, int health,
    float critDamage, int critTime, int avoidTime)
    : GingerbreadMan(std::move(name), type, Position::Middle, damage, defense,
                     health, critDamage, critTime, avoidTime) {
}

void MiddleGingerbreadMan::criticalBuff() {
    if (critDamage < 0.5f) {
        critDamage = 0.5f;
    }
}
