#include "BurningSpiceCookie.hpp"

BurningSpiceCookie::BurningSpiceCookie()
    : FrontGingerbreadMan("Burning Spice Cookie", Element::Fire,
                          200, 100, 1000, 0.5, 3, 5) {
}

void BurningSpiceCookie::levelUp() {
    ++level;
    damage += 200;
    critDamage += 0.05;
    health += 150;
    currHealth = health;
}

int BurningSpiceCookie::attack(Element enemyType) {
    float crit = 0;

    if (countCritTime()) {
        crit = critDamage;
    }

    float bonus = elementalAttack(enemyType);
    int finalDamage = (1 + crit + bonus) * damage + 50;

    defenseBuff();
    return finalDamage;
}