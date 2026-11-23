#include "Character.hpp"
using namespace std;

Character::Character(string name, int damage, int defense, int health, int critTime, int avoidTime)
    :name(name),
     damage(damage),
     defense(defense),
     health(health),
     currHealth(health),
     level(1),
     critTime(critTime),
     avoidTime(avoidTime),
     currCritTime(0),
     currAvoidTime(0){
     }


     
string Character::getName()const{
        return name;
}

int Character::getlevel() const{
    return level;
}

int Character::getDamage() const{
    return damage;
}

int Character::getDefense() const{
    return defense;
}

int Character::getHealth() const{
    return health;
}

int Character::getCurrHealth() const{
    return currHealth;
}

int Character::getCritTime() const{
    return critTime;
}

int Character::getAvoidTime() const{
    return avoidTime;
}

bool Character::countCritTime(){
    this->currCritTime+=1;
    if (this->currCritTime == this->critTime)
    {
        this->currCritTime = 0;
        return true;
    }
    return false;
}

bool Character::countAvoidTime(){
    this->currAvoidTime+=1;
    if(this->currAvoidTime==this->currAvoidTime)
    {
        this->currAvoidTime=0;
        return true;
    }
    return false;

}

