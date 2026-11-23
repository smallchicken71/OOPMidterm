#include "GingerbreadMan.hpp"

#include <utility>

GingerbreadMan::GingerbreadMan(std::string name, Element type, Position pos,
                               int damage, int defense, int health,
                               float critDamage, int critTime, int avoidTime)
    : Character(name, damage, defense, health, critTime, avoidTime),
      type(type),
      pos(pos),
      critDamage(critDamage) {
}

void GingerbreadMan::levelUp() {
    level+=1;
    damage += 100;
    defense += 100;
    health += 100;
    currHealth = health;
}

int GingerbreadMan::attack(Element enemyType) {
    float crit =0.0f;
    if(countCritTime()){
        crit = critDamage;
    }
    return static_cast<int>((1 + crit + elementalAttack(enemyType)) * damage);
}

float GingerbreadMan::elementalAttack(Element enemyType) {
    if (type == Element::Water && enemyType == Element::Fire) {
        return 0.5f;
    }

    if (type == Element::Fire && enemyType == Element::Plant) {
        return 0.7f;
    }

    if (type == Element::Plant && enemyType == Element::Water) {
        return 0.3f;
    }

    return 0.0f;
}

bool GingerbreadMan::attacked(int incomingDamage) {
    return applyDamage(incomingDamage - defense);
}

bool GingerbreadMan::applyDamage(int realDamage) {
    if (countAvoidTime() || realDamage <= 0) {
        return true;
    }

    currHealth -= realDamage;
    return false;
}

std::vector<Position> GingerbreadMan::getInteractPositions() const {
    switch (pos) {
    case Position::Front:
        return {Position::Front};
    case Position::Middle:
        return {Position::Front, Position::Middle};
    case Position::Back:
        return {Position::Middle, Position::Back};
    }

    return {};
}

Element GingerbreadMan::getElementType() const {
    return type;
}

Position GingerbreadMan::getPosition() const {
    return pos;
}

float GingerbreadMan::getCritDamage() const {
    return critDamage;
}
