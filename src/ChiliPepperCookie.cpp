#include "ChiliPepperCookie.hpp"

ChiliPepperCookie::ChiliPepperCookie()
    : MiddleGingerbreadMan("Chili Pepper Cookie", Element::Fire,
                           200, 100, 700, 0.8f, 7, 3) {
}

void ChiliPepperCookie::levelUp() {
    GingerbreadMan::levelUp();
    criticalBuff();
}

int ChiliPepperCookie::attack(Element enemyType) {
    const float crit = countCritTime() ? critDamage : 0.0f;
    const int healthRatio = currHealth / health;
    return static_cast<int>((1 + crit + healthRatio + elementalAttack(enemyType)) * damage);
}
