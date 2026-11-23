#include "SilverbellCookie.hpp"

SilverbellCookie::SilverbellCookie()
    : BackGingerbreadMan("Silverbell Cookie", Element::Plant,
                         200, 150, 900, 0.8, 3, 8) {
}

void SilverbellCookie::levelUp() {
    ++level;
    damage += 150;
    defense += 50;
    health += 100;
    currHealth = health;

    keepHealingBuff();
}

bool SilverbellCookie::attacked(int incomingDamage) {
    int realDamage = double(incomingDamage - defense * (1 + level / 100.0));

    if (countAvoidTime()) {
        return true;
    }

    if (realDamage <= 0) {
        return true;
    }

    currHealth -= realDamage;
    return false;
}