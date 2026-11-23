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
    float crit = 0;  // 先把爆擊加成設為 0

    if (countCritTime()) {
        crit = critDamage;  // 這次有爆擊，才套用爆擊加成
    }

    float bonus = elementalAttack(enemyType);
    int finalDamage = (1 + crit + bonus) * damage;
    return finalDamage;
}

float GingerbreadMan::elementalAttack(Element enemyType) {
    if (type == Element::Water && enemyType == Element::Fire) {
        return 0.5;
    }

    if (type == Element::Fire && enemyType == Element::Plant) {
        return 0.7;
    }

    if (type == Element::Plant && enemyType == Element::Water) {
        return 0.3;
    }

    return 0.0;
}

bool GingerbreadMan::attacked(int incomingDamage) {
    const int realDamage = incomingDamage - defense;
    if(countAvoidTime()){
        return true;
    }
    if (realDamage <= 0) {
        return true;
    }

    currHealth -= realDamage;
    return false;
}

std::vector<Position> GingerbreadMan::getInteractPositions() const {
    if (pos == Position::Front) {
        return {Position::Front};
    }

    if (pos == Position::Middle) {
        return {Position::Front, Position::Middle};
    }

    if (pos == Position::Back) {
        return {Position::Middle, Position::Back};
    }

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

