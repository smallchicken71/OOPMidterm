#include "SeaFairyCookie.hpp"

SeaFairyCookie::SeaFairyCookie()
    : MiddleGingerbreadMan("Sea Fairy Cookie", Element::Water,
                           200, 300, 1000, 0.3, 3, 5) {
}

void SeaFairyCookie::levelUp() {
    ++level;
    damage += 100;
    defense += 200;
    health += 140;
    currHealth = health;

    criticalBuff();
}

int SeaFairyCookie::attack(Element enemyType) {
    const float crit = countCritTime() ? critDamage : 0.0f;
    return static_cast<int>((1 + crit + elementalAttack(enemyType)) * damage + crit * defense);
}
