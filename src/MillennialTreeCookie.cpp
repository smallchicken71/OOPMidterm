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
    const float crit = countCritTime() ? critDamage : 0.0f;
    const int healthRatio = currHealth / health;
    return static_cast<int>((1 + crit + healthRatio + elementalAttack(enemyType)) * damage);
}

bool MillennialTreeCookie::attacked(int incomingDamage) {
    const int healthRatio = currHealth / health;
    const int realDamage = incomingDamage - defense * (1 + healthRatio);
    defenseBuff();
    return applyDamage(realDamage);
}
