#pragma once
#include<iostream>

#include<string>

#include "Item.h"

class Consumable : public Item {
private:
    int duration;
public:
    //Init
    Consumable(int duration) : Item(), duration(0) {}

    Consumable(std::string, std::string, int, int, int, int, int, int, std::string, int, int)
        : Item(name, type, level, money, health, Attack, defend, critical_percent, description, id), duration(0) {};
    //Getter
    int getDuration();
    //Setter
    void setDuration(int);
    //Others
   // void use();
};