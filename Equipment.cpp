#include"Item.h"
#include"Equipment.h"
#include<iostream>
#include<string>

Equipment::Equipment() : Item(int newID) {
    this->durability = 100;
    this->isWearing = false;
}

  //Getters
int Equipment::getDurability() const {
    return durability;
}
bool Equipment::getIsWearing() const {
    return isWearing;
}

  //Setters
void Equipment::setDurability(int newDurability) {
    this->durability = newDurability;
}
void Equipment::setIsWearing(bool newIsWearing) {
    this->isWearing = newIsWearing;
}

  //Other functions
void Equipment::equip() {
    setIsWearing(true);
}
void Equipment::unequip() {
    setIsWearing(false);
}
void Equipment::breakItem() {
    int choice;
    std::cout << "This will permanently delete the item. Do you still wish to proceed? (No undo)" << std::endl << "1. Yes" << std::endl << "2. No" << std::endl;
    std::cin >> choice;
    if (choice == 1) {
        Item::deleteItem();
    }
}
void Equipment::deleteItem() {
    delete this;
}