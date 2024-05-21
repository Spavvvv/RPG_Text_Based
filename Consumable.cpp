#include"Item.h"
#include"Consumable.h"
#include<iostream>
#include<string>

//Init
  Consumable::Consumable(std::string name, std::string type, int level, int money, int health, int Attack, int defend, int critical_percent, std::string description, int id, int duration)
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
