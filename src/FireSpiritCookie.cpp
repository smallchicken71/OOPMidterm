#include "FireSpiritCookie.hpp"

FireSpiritCookie::FireSpiritCookie()
    : BackGingerbreadMan("Fire Spirit Cookie", Element::Fire,
                         500, 40, 200, 0.5, 2, 7) {
}

void FireSpiritCookie::levelUp() {
    ++level;
    damage += 100;
    critDamage += 0.1;
    health += 10;
    currHealth = health;

    keepHealingBuff();
}

