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
    getQuantity();
    getDuration();
    //Setter
    setQuantity();
    setDuration();
    //Others
    use();

}