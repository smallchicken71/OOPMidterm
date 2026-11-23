#ifndef SEAFAIRYCOOKIE_HPP
#define SEAFAIRYCOOKIE_HPP

#include "MiddleGingerbreadMan.hpp"

class SeaFairyCookie final : public MiddleGingerbreadMan {
public:
    SeaFairyCookie();

    void levelUp() override;
    int attack(Element enemyType) override;
};

#endif
