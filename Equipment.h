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
	Equipment(std::string newName, std::string newType, int newLevel, int newMoney, int newHealth, int newAttack, int newDefend, int newCritical_percent, int newID);

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
