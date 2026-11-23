#ifndef WHITELILYCOOKIE_HPP
#define WHITELILYCOOKIE_HPP

#include "MiddleGingerbreadMan.hpp"

class WhiteLilyCookie final : public MiddleGingerbreadMan {
public:
    WhiteLilyCookie();
    int attack(Element enemyType) override;
    bool attacked(int incomingDamage) override;
};

#endif