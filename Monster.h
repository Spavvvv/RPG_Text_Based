#pragma once

#include "Character.h"

enum class Basic_Monster {
	Globin,
	Spyder,
	Khoi
};



class Monster : public Character {
public:
	int attack();
};


class Undead : public Monster {
private:
	bool isHoly;

public:
	//Init
	Undead() : Monster() {}


	//methods
	int attack();
};

class Manh : public Monster {
private:
	bool isJew;

public:
	//Init
	Manh() : Monster() {}

	//methods
	int attack();

};

class Dragon : public Monster {
private:
	bool isChoosen;

public:
	//Init
	Dragon() : Monster() {}

	//Methods
	int attack();
};
