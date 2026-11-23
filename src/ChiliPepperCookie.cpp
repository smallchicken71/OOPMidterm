#include "ChiliPepperCookie.hpp"

ChiliPepperCookie::ChiliPepperCookie()
    :MiddleGingerbreadMan("Chili Pepper Cookie",Element::Fire,200,100,700,0.8,7,3){

}


void ChiliPepperCookie::levelUp(){
    level+=1;
    damage+=100;
    defense+=100;
    health+=100;
    currHealth=health;
    criticalBuff();
}

int ChiliPepperCookie::attack(Element enemyType){
      float crit = 0;

    if (countCritTime()) {
        crit = critDamage;
    }
    float healthraratio=(1.0*currHealth)/ health;
    float bonus = elementalAttack(enemyType);
    int finalDamage = (1 + crit + healthraratio + bonus) * damage;
    return finalDamage;
}

bool ChiliPepperCookie::attacked(int incomingDamage){
    int realDamage = incomingDamage - defense;
    if (countAvoidTime()) {
        return true;
    }

    if (realDamage <= 0) {
        return true;
    }

    currHealth -= realDamage;
    return false;
}