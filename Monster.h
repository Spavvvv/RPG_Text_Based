#pragma once

#include "Character.h"

class Monster : public Character {
public:
	virtual void attack();
};

enum class Basic_Monster {
	Globin,
	Spyder,
	Khoi
};

class Undead : public Monster {
private:
	bool isHoly;

public:
	//Init
	Undead() : Monster() {}


	//methods
	void attack();
};

class Manh : public Monster {
private:
	bool isJew;

public:
	//Init
	Manh() : Monster() {}

	//methods
	void attack();

};

class Dragon : public Monster {
private:
	bool isChoosen;

public:
	//Init
	Dragon() : Monster() {}

	//Methods
	void attack();
};
