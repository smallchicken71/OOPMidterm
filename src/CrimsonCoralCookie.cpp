#include "CrimsonCoralCookie.hpp"

CrimsonCoralCookie::CrimsonCoralCookie()
    : FrontGingerbreadMan("Crimson Coral Cookie", Element::Water,
                          200, 500, 100, 0.5, 3, 10) {
}

int CrimsonCoralCookie::attack(Element enemyType) {
    const float crit = countCritTime() ? critDamage : 0.0f;
    const int finalDamage = static_cast<int>((1 + crit + elementalAttack(enemyType)) * damage + defense + health);
    defenseBuff();
    return finalDamage;
}
