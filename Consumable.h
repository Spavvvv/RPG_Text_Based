#pragma once
#include<iostream>

#include<string>

#include "Item.h"

class Consumable : public Item {
private:
    int duration;
public:
    //Init
    Consumable(std::string newName, std::string newType, int newLevel, int newMoney, int newHealth, int newAttack, int newDefend, int newCritical_percent, int newID, int newDuration) : Item(std::string newName, std::string newType, int newLevel, int newMoney, int newHealth, int newAttack, int newDefend, int newCritical_percent, int newID)
    //Getter
    int getDuration();
    //Setter
    void setDuration(int);
    //Others
   // void use();
};