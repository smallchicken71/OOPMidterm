#include "SeltzerCookie.hpp"

SeltzerCookie::SeltzerCookie()
    : BackGingerbreadMan("Seltzer Cookie", Element::Water,
                         100, 400, 700, 0.8, 2, 3) {
}

bool SeltzerCookie::attacked(int incomingDamage) {
    const int realDamage = static_cast<int>(incomingDamage - defense * (1 + level / 100.0));
    keepHealingBuff();
    return applyDamage(realDamage);
}
