#pragma once

#include "Character.h"

#include <string>

enum class Basic_Monster {
	Globin,
	Spyder,
	Khoi
};



class Monster : public Character {
public:
	Monster() : Character() {}

	Monster(std::string name, int health, int Attack, int defend, int level, int experience, int critical_percent) : Character(name, health, Attack, defend, level, experience, critical_percent) {}

	//methods
	virtual int attack();
	virtual void display();
 	virtual int health();
};


class Undead : public Monster {
private:
	bool isHoly;

public:
	//Init
	Undead(std::string name, int health, int Attack, int defend, int level, int experience, int critical_percent, bool isHoly) : Monster(name, health, Attack, defend, level, experience, critical_percent), isHoly(false) {}


	//methods
	int attack();
	int health();

	static bool curse();

	void display();
};

class Manh : public Monster {
private:
	bool isJew;

public:
	//Init
	Manh(std::string name, int health, int Attack, int defend, int level, int experience, int critical_percent, bool isJew) : Monster(name, health, Attack, defend, level, experience, critical_percent), isJew(false) {}

	//methods
	int attack();
	int health();

	static bool hailH();

	void display();

};

class Dragon : public Monster {
private:
	bool isChoosen;

public:
	//Init
	Dragon(std::string name, int health, int Attack, int defend, int level, int experience, int critical_percent, bool isChoosen) : Monster(name, health, Attack, defend, level, experience, critical_percent), isChoosen(false) {}

	//Methods
	int attack();
	int health();

	static bool loser();

	void display();
};
