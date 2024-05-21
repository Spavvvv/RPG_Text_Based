#include"Item.h"
#include"Consumable.h"
#include<iostream>
#include<string>

//Init
  Consumable::Consumable(std::string, std::string, int, int, int, int, int, int, std::string, int, int)
      : Item(name, type, level, money, health, Attack, defend, critical_percent, description, id), duration(0) {};
//Getter
int Consumable::getDuration() {
    return duration;
}
//Setter
void Consumable::setDuration(int newDuration) {
    this->duration = newDuration;
}
//Others
