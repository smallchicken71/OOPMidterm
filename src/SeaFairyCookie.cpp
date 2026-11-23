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
    float crit = 0;

    if (countCritTime()) {
        crit = critDamage;
    }

    float bonus = elementalAttack(enemyType);

    // 爆擊時，額外加上防禦力乘以爆擊加成。
    int finalDamage = (1 + crit + bonus) * damage + crit * defense;
    return finalDamage;
}