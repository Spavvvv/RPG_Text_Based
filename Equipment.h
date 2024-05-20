#pragma once
#include<iostream>

#include<string>

#include "Item.h"

class Equipment: public Item {
private:
  int durability;
  bool isWearing;
  void deleteItem();
public:
  //Init
	Equipment::Equipment(std::string newName, std::string newType, int newLevel, int newMoney, int newHealth, int newAttack, int newDefend, int newCritical_percent, int newID);

  //Getters
int getDurability() const;
bool getIsWearing() const;

  //Setters
void setDurability(int);
void setIsWearing(bool);

  //Other functions
void equip();
void unequip();
void breakItem();
};
