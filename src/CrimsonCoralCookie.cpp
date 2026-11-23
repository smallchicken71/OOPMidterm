#include "CrimsonCoralCookie.hpp"

CrimsonCoralCookie::CrimsonCoralCookie()
    : FrontGingerbreadMan("Crimson Coral Cookie", Element::Water,
                          200, 500, 100, 0.5, 3, 10) {
}

int CrimsonCoralCookie::attack(Element enemyType) {
    float crit = 0;

    if (countCritTime()) {
        crit = critDamage;
    }

    float bonus = elementalAttack(enemyType);

    // 先用目前的防禦力和最大生命值計算這次傷害。
    int finalDamage = (1 + crit + bonus) * damage + defense + health;

    defenseBuff();
    return finalDamage;
}