#pragma once

#include "Character.h"

enum class Basic_Monster {
	Globin,
	Spyder,
	Khoi
};



class Monster : public Character {
public:
	Monster() : Character() {}

	//methods
	virtual int attack();
};


class Undead : public Monster {
private:
	bool isHoly;

public:
	//Init
	Undead() : Monster(), isHoly(false) {}


	//methods
	int attack();

	static bool curse();
};

class Manh : public Monster {
private:
	bool isJew;

public:
	//Init
	Manh() : Monster(), isJew(false) {}

	//methods
	int attack();

	static bool hailH();

};

class Dragon : public Monster {
private:
	bool isChoosen;

public:
	//Init
	Dragon() : Monster(), isChoosen(false) {}

	//Methods
	int attack();

	static bool loser();
};
