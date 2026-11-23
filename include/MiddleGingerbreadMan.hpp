#ifndef MIDDLEGINGERBREADMAN_HPP
#define MIDDLEGINGERBREADMAN_HPP

#include "GingerbreadMan.hpp"

class MiddleGingerbreadMan : public GingerbreadMan {
public:
    MiddleGingerbreadMan(
        std::string name,
        Element type,
        int damage,
        int defense,
        int health,
        float critDamage = 0.5f,
        int critTime = 3,
        int avoidTime = 5
    );
    void criticalBuff();
};
#endif
