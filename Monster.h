#pragma once

#include "Character.h"

#include <string>

	enum class Basic_monster {
	Undead,
	Dragon,
	Goblin
};


class Monster : public Character {

public:

	Monster() : Character() {}

	Monster(std::string name, int health, int Attack, int defend, int level, int experience, int critical_percent) : Character(name, health, Attack, defend, level, experience, critical_percent) {}

	//methods
	virtual int attack() {};
	virtual void display() {};
	virtual int health() {};
};


class Undead : public Monster {
private:
	bool isHoly;

public:
	//Init
	Undead(bool isHoly) : Monster(), isHoly(false) {}

	Undead(std::string name, int health, int Attack, int defend, int level, int experience, int critical_percent, bool isHoly) : Monster(name, health, Attack, defend, level, experience, critical_percent), isHoly(false) {};


	//methods
	int attack();
	int gethealth();
	void sethealth(int health);
	static bool curse();

	void display();
};

class Dragon : public Monster {
private:
	bool isJew;

public:
	//Init
	Dragon(bool isJew) :Monster(), isJew(false) {}

	Dragon(std::string name, int health, int Attack, int defend, int level, int experience, int critical_percent, bool isJew) : Monster(name, health, Attack, defend, level, experience, critical_percent), isJew(false) {}

	//methods
	int attack();
	int gethealth();
	void sethealth(int health);

	static bool hailH();

	void display();

};

class Manh : public Monster {
private:
	bool isChoosen;

public:
	//Init
	Manh(bool isChoosen) : Monster(), isChoosen(false) {}

	Manh(std::string name, int health, int Attack, int defend, int level, int experience, int critical_percent, bool isChoosen) : Monster(name, health, Attack, defend, level, experience, critical_percent), isChoosen(false) {}

	//Methods
	int attack();
	int gethealth();
	void sethealth(int health);

	static bool loser();

	void display();
};
