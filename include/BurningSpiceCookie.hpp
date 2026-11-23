#ifndef BURNINGSPICECOOKIE_HPP
#define BURNINGSPICECOOKIE_HPP

#include "FrontGingerbreadMan.hpp"

class BurningSpiceCookie final : public FrontGingerbreadMan {
public:
    BurningSpiceCookie();

    void levelUp() override;
    int attack(Element enemyType) override;
};

#endif
