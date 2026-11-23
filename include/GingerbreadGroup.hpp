#ifndef GINGERBREADGROUP_HPP
#define GINGERBREADGROUP_HPP

#include <cstddef>
#include <string>
#include <vector>
#include "GingerbreadMan.hpp"

class GingerbreadGroup {
private:
    std::vector<GingerbreadMan> queue;
    int maxSize;
    std::size_t currIndex = 0;

    void checkIndex(int index) const;
    void resetIndexIfNeeded();

public:
    GingerbreadGroup(int maxSize);

    std::vector<int> attack(std::vector<Element>& types);
    void attacked(std::vector<float>& damages);

    void addGingerbreadMan(const GingerbreadMan& gingerbreadMan);
    void replaceGingerbreadMan(int index, const GingerbreadMan& gingerbreadMan);

    void sortByHealth();
    void sortByDamage();
    void sortByDefense();

    int countCombatPower();
    void removeDeadGingerbreadMan();
    void removeGingerbreadMan(std::string name);
    void removeGingerbreadMan(Element element);
    GingerbreadMan getGingerbreadMan(int index);
};

#endif
