#pragma once
#include<iostream>

#include<string>

#include "Item.h"

class Consumable : public Item {
private:
    int quantity;
    int duration;
public:
    //Init
    Consumable();
    //Getter
    int getQuantity();
    int getDuration();
    //Setter
    void setQuantity(int);
    void setDuration(int);
    //Others
    void use();
};