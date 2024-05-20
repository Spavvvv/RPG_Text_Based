#pragma once
#include<iostream>

#include<string>

#include "Item.h"

class Consumable : public Item {
private:
    int duration;
public:
    //Init
    Consumable(std::string, std::string, int, int, int, int, int, int, int, int, std::string, int);
    //Getter
    int getDuration();
    //Setter
    void setDuration(int);
    //Others
   // void use();
};