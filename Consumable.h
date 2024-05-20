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
    //Getter
    int getDuration();
    //Setter
    void setDuration(int);
    //Others
   // void use();
};