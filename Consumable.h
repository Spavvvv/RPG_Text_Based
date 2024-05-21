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

    Consumable(std::string name, std::string type, int, int, int, int, int, int, std::string description, int, int);

   // Consumable(std::string, std::string, int, int, int, int, int, int, int, int, std::string, int);

    //Getter
    int getDuration();
    //Setter
    void setDuration(int);
    //Others
   // void use();
};