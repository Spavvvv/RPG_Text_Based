#pragma once
#include<iostream>

#include<string>

#include "Item.h"

class Equipment: public Item {
private:
  int durability;
public:
  //Init
	Equipment();

	Equipment(std::string,std::string, int, int, int, int, int, int, std::string, int, int);

  //Getters
	int getDurability() const;

  //Setters
	void setDurability(int);

  //Other functions
	void equip();
	void unequip();
	void breakItem();
};
