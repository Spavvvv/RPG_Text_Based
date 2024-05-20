#pragma once

#include <string>

#include <vector>

#include "Item.h"

//-------------------------------------Character Class--------------------------------------

class Character {  
protected:
	std::string name;
	int health;
	int maxHealth;
	int Attack;
	int defend;
	int level;
	int experience;
	int critical_percent;
public:
	//init
	Character();

	Character(std::string, int, int , int, int, int, int);

	//setter
	void setName(std::string name_);
	void setHealth(int health_);
	void setMaxHealth(int max_health_);
	void setAttack(int Attack_);
	void setDefend(int defend_);
	void setLevel(int level_);
	void setExperience(int experience_);
	void setCritical(int critical_);

	//getter
	std::string getName() const;
	int getHealth() const;
	int getMaxHealth() const;
	int getAttack() const;
	int getDefend() const;
	int getLevel() const;
	int getExperience() const;
	int getCritical() const;

	//other methods
	virtual int attack();
};