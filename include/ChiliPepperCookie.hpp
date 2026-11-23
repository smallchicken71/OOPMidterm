#ifndef CHILIPEPPERCOOKIE_HPP
#define CHILIPEPPERCOOKIE_HPP

#include "MiddleGingerbreadMan.hpp"

class ChiliPepperCookie final : public MiddleGingerbreadMan {
public:
    ChiliPepperCookie();

    void levelUp() override;
    int attack(Element enemyType) override;
};

#endif
