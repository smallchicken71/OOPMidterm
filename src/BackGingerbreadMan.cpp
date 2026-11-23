#include "BackGingerbreadMan.hpp"

#include <utility>

BackGingerbreadMan::BackGingerbreadMan(
    std::string name, Element type, int damage, int defense, int health,
    float critDamage, int critTime, int avoidTime)
    : GingerbreadMan(name, type, Position::Back, damage, defense,
                     health, critDamage, critTime, avoidTime) {
}

void BackGingerbreadMan::keepHealingBuff() {
    if (currHealth < health) {
        ++currHealth;
    }
}
