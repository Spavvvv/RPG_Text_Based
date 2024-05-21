#include"Item.h"
#include"Equipment.h"
#include<iostream>
#include<string>

Equipment::Equipment(std::string newName, std::string newType, int newLevel, int newMoney, int newHealth, int newMaxHealth, int newAttack, int newDefend, int newCritical_percent, int newID, std::string newDescription, int newDurability) : Item(newName, newType, newLevel, newMoney, newHealth, newMaxHealth, newAttack, newDefend, newCritical_percent, newID, newDescription), durability(newDurability) {}

  //Getters
int Equipment::getDurability() const {
    return durability;
}

  //Setters
void Equipment::setDurability(int newDurability) {
    this->durability = newDurability;
}


  //Other functions
void Equipment::breakItem() {
    int choice;
    std::cout << "This will permanently delete the item. Do you still wish to proceed? (No undo)" << std::endl << "1. Yes" << std::endl << "2. No" << std::endl;
    std::cin >> choice;
    if (choice == 1) {
        Item::deleteItem();
    }
}