#include"Item.h"
#include"Equipment.h"
#include<iostream>
#include<string>

Equipment::Equipment() : Item() {
    durability = 0;
}

Equipment::Equipment(std::string name, std::string type, int level, int money, int health, int Attack, int defend, int critical_percent, std::string description, int id, int durability_)
    : Item(name, type, level, money, health, Attack, defend, critical_percent, description, id), durability(durability_) {}


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