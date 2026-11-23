#ifndef MILLENNIALTREECOOKIE_HPP
#define MILLENNIALTREECOOKIE_HPP

#include "FrontGingerbreadMan.hpp"

class MillennialTreeCookie final : public FrontGingerbreadMan {
public:
    MillennialTreeCookie();

    void levelUp() override;
    int attack(Element enemyType) override;
    bool attacked(int incomingDamage) override;
};

#endif
