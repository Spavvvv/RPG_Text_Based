#include"Item.h"
#include"Equipment.h"
#include<iostream>
#include<string>

Equipment::Equipment(std::string, std::string, int, int, int, int, int, int, std::string, int, int)
    : Item(name, type, level, money, health, Attack, defend, critical_percent, description, id), durability(0) {};
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