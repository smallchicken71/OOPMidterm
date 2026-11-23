#ifndef BACKGINGERBREADMAN_HPP
#define BACKGINGERBREADMAN_HPP

#include "GingerbreadMan.hpp"

class BackGingerbreadMan : public GingerbreadMan {
public:
    BackGingerbreadMan(
        std::string name,
        Element type,
        int damage,
        int defense,
        int health,
        float critDamage = 0.5f,
        int critTime = 3,
        int avoidTime = 5
    );
    void keepHealingBuff();
};
#endif
