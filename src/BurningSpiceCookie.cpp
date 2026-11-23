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
    const float crit = countCritTime() ? critDamage : 0.0f;
    const int finalDamage = static_cast<int>((1 + crit + elementalAttack(enemyType)) * damage + 50);
    defenseBuff();
    return finalDamage;
}
