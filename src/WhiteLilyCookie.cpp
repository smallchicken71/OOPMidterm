#include "WhiteLilyCookie.hpp"

WhiteLilyCookie::WhiteLilyCookie()
    : MiddleGingerbreadMan("White Lily Cookie", Element::Plant,
                           100, 100, 1500, 0.2, 2, 5) {
}

int WhiteLilyCookie::attack(Element enemyType) {
    float crit = 0;

    if (countCritTime()) {
        crit = critDamage;
    }

    float bonus = elementalAttack(enemyType);

    // 爆擊時，額外加上目前血量乘以爆擊加成。
    int finalDamage = (1 + crit + bonus) * damage + crit * currHealth;
    return finalDamage;
}

bool WhiteLilyCookie::attacked(int incomingDamage) {
    int realDamage = incomingDamage - (defense + damage);

    // 算完本次傷害後，才更新爆擊加成。
    criticalBuff();

    if (countAvoidTime()) {
        return true;
    }

    if (realDamage <= 0) {
        return true;
    }

    currHealth -= realDamage;
    return false;
}