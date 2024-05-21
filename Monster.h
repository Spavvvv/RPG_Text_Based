#pragma once

#include "Character.h"

#include <string>

enum class Basic_monster {
	Khoi,
	Spider,
	Goblin
};


class Monster : public Character {

public:

	Monster() : Character() {}

	Monster(std::string name, int health, int maxHealth, int Attack, int defend, int level, int experience, int critical_percent, int money) : Character(name, health, maxHealth, Attack, defend, level, experience, critical_percent, money) {}

	//methods
	void display();
};


class Undead : public Monster {
private:

public:
	//Init
	Undead(bool isHoly) : Monster() {}

	Undead(std::string name, int health, int maxHealth, int Attack, int defend, int level, int experience, int critical_percent, int money) : Monster(name, health, maxHealth, Attack, defend, level, experience, critical_percent, money) {};


	//methods
	void sieuUndead(bool);
};

class Dragon : public Monster {
private:

public:
	//Init
	Dragon(bool isJew) :Monster() {}

	Dragon(std::string name, int health, int maxHealth, int Attack, int defend, int level, int experience, int critical_percent, int money) : Monster(name, health, maxHealth, Attack, defend, level, experience, critical_percent, money) {}

	//methods
	void sieuDragon(bool);
};

class Manh : public Monster {
private:

public:
	//Init
	Manh(bool isChoosen) : Monster() {}

	Manh(std::string name, int health, int maxHealth, int Attack, int defend, int level, int experience, int critical_percent, int money) : Monster(name, health, maxHealth, Attack, defend, level, experience, critical_percent, money) {}

	//Methods
	void sieuManh(bool);
};
