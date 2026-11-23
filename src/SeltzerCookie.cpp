#include "SeltzerCookie.hpp"

SeltzerCookie::SeltzerCookie()
    : BackGingerbreadMan("Seltzer Cookie", Element::Water,
                         100, 400, 700, 0.8, 2, 3) {
}

bool SeltzerCookie::attacked(int incomingDamage) {
    double defenseMultiplier = 1 + level / 100.0;
    int realDamage = incomingDamage - defense * defenseMultiplier;

    // 算完傷害後先回血，再判斷閃避和扣血。
    keepHealingBuff();

    if (countAvoidTime()) {
        return true;
    }

    if (realDamage <= 0) {
        return true;
    }

    currHealth -= realDamage;
    return false;
}