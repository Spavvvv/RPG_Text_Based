#pragma once

#include "Character.h"

enum class Basic_Monster {
	Globin,
	Spyder,
	Khoi
};



class Monster : public Character {
public:
	void attack();
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
