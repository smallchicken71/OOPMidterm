#include "Character.hpp"

#include <utility>

Character::Character(std::string name, int damage, int defense, int health,
                     int critTime, int avoidTime)
    : name(std::move(name)),
      level(1),
      damage(damage),
      defense(defense),
      health(health),
      currHealth(health),
      critTime(critTime),
      avoidTime(avoidTime),
      currCritTime(0),
      currAvoidTime(0) {
}

std::string Character::getName() const {
    return name;
}

int Character::getlevel() const {
    return level;
}

int Character::getDamage() const {
    return damage;
}

int Character::getDefense() const {
    return defense;
}

int Character::getHealth() const {
    return health;
}

int Character::getCurrHealth() const {
    return currHealth;
}

int Character::getCritTime() const {
    return critTime;
}

int Character::getAvoidTime() const {
    return avoidTime;
}

bool Character::countCritTime() {
    if (++currCritTime == critTime) {
        currCritTime = 0;
        return true;
    }

    return false;
}

bool Character::countAvoidTime() {
    if (++currAvoidTime == avoidTime) {
        currAvoidTime = 0;
        return true;
    }

    return false;
}
