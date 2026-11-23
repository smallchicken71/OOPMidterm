#include "MillennialTreeCookie.hpp"

MillennialTreeCookie::MillennialTreeCookie()
    : FrontGingerbreadMan("Millennial Tree Cookie", Element::Plant,
                          200, 100, 1000) {
}

void MillennialTreeCookie::levelUp() {
    ++level;
    damage += 150;
    defense += 150;
    health += 150;
    currHealth = health;
}

int MillennialTreeCookie::attack(Element enemyType) {
    float crit = 0;

    if (countCritTime()) {
        crit = critDamage;
    }

    // 先轉成 float，讓半血時算出 0.5。
    float currentHealth = currHealth;
    float healthRatio = currentHealth / health;
    float bonus = elementalAttack(enemyType);

    int finalDamage = (1 + crit + healthRatio + bonus) * damage;
    return finalDamage;
}

bool MillennialTreeCookie::attacked(int incomingDamage) {
    float currentHealth = currHealth;
    float healthRatio = currentHealth / health;
    int realDamage = incomingDamage - defense * (1 + healthRatio);

    // 先用現在的防禦力計算本次傷害，再執行 buff。
    defenseBuff();

    if (countAvoidTime()) {
        return true;
    }

    if (realDamage <= 0) {
        return true;
    }

    currHealth -= realDamage;
    return false;
}