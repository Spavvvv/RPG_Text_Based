#pragma once
#include<iostream>

#include<string>

#include "Item.h"

class Equipment: public Item {
private:
  int durability;
public:
  //Init
	Equipment(std::string, std::string, int, int, int, int, int, int, int, int, std::string, int);

	Equipment(std::string, std::string, int, int, int, int, int, int, std::string, int, int)
		: Item(name, type, level, money, health, Attack, defend, critical_percent, description, id), durability(0) {};

  //Getters
	int getDurability() const;

  //Setters
	void setDurability(int);

  //Other functions
	void equip();
	void unequip();
	void breakItem();
};
