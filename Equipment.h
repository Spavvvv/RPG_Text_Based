#pragma once
#include<iostream>

#include<string>

#include "Item.h"

class Equipment: public Item {
private:
  int durability;
  bool isWearing;
public:
  //Init
	Equipment(std::string, std::string, int, int, int, int, int, int, int, int, std::string, int, bool);

	Equipment(std::string, std::string, int, int, int, int, int, int, std::string, int, int, bool)
		: Item(name, type, level, money, health, Attack, defend, critical_percent, description, id), durability(0), isWearing(false) {};
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
