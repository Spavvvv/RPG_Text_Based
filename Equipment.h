#pragma once
#include<iostream>
#include<string>

class Equipment: public Item{
private:
  int durability;
  bool isWearing;
  void breakItem();
public:
  //Init
Equipment();

  //Getters
int getDurability() const;
bool getIsWearing() const;

  //Setters
void setDurability(int);
void setIsWearing(bool);

  //Other functions
void equip();
void unequip();
};
