#include "FrontGingerbreadMan.hpp"

#include <utility>

FrontGingerbreadMan::FrontGingerbreadMan(
    std::string name, Element type, int damage, int defense, int health,
    float critDamage, int critTime, int avoidTime)
    : GingerbreadMan(std::move(name), type, Position::Front, damage, defense,
                     health, critDamage, critTime, avoidTime) {
}

void FrontGingerbreadMan::defenseBuff() {
    if (defense > damage) {
        defense += 50;
    }
}
