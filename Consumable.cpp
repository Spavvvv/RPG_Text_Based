#include"Item.h"
#include"Consumable.h"
#include<iostream>
#include<string>

//Init
  //Consumable::Consumable(std::string newName, std::string newType, int newLevel, int newMoney, int newHealth, int newAttack, int newDefend, int newCritical_percent, std::string newDescription, int newID, int newDuration)
  //    : Item(newName, newType, newLevel, newMoney, newHealth, newAttack, newDefend, newCritical_percent, newDescription,newID), duration(newDuration) {}
//Getter
int Consumable::getDuration() {
    return duration;
}
//Setter
void Consumable::setDuration(int newDuration) {
    this->duration = newDuration;
}
//Others
