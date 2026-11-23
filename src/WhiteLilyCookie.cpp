#include "WhiteLilyCookie.hpp"

WhiteLilyCookie::WhiteLilyCookie()
    : MiddleGingerbreadMan("White Lily Cookie", Element::Plant,
                           100, 100, 1500, 0.2, 2, 5) {
}

int WhiteLilyCookie::attack(Element enemyType) {
    const float crit = countCritTime() ? critDamage : 0.0f;
    return static_cast<int>((1 + crit + elementalAttack(enemyType)) * damage + crit * currHealth);
}

bool WhiteLilyCookie::attacked(int incomingDamage) {
    const int realDamage = incomingDamage - (defense + damage);
    criticalBuff();
    return applyDamage(realDamage);
}
