#include"Item.h"
#include"Consumable.h"
#include<iostream>
#include<string>

//Init
  Consumable::Consumable(std::string newName, std::string newType, int newLevel, int newMoney, int newHealth, int newMaxHealth, int newAttack, int newDefend, int newCritical_percent, int newID, std::string newDescription, int newDuration) : Item(newName, newType, newLevel, newMoney, newHealth, newMaxHealth, newAttack, newDefend, newCritical_percent, newID, newDescription), duration(newDuration) {}
//Getter
int Consumable::getDuration() {
    return duration;
}
//Setter
void Consumable::setDuration(int newDuration) {
    this->duration = newDuration;
}
//Others
