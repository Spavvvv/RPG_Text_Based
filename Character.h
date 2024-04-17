#pragma once

#include <string>

#include <vector>

#include "Item.h"

//-------------------------------------Character Class--------------------------------------

class Character {  
private:
	std::string name;
	int health;
	int attack;
	int defend;
	int level;
	int experience;
	int critical_percent;
public:
	//init
	Character();

	//setter

	//getter
};

//-------------------------------------Monster Class--------------------------------------

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

//-------------------------------------Player Class--------------------------------------
class Player : public Monster {
private:
	bool isChoosenOne;
	bool isJew;
	bool isAdmin;
	bool isVip;

	std::vector<Item*> Bag;

public:
	//Init
	Player();

	//Getter

	//Setter

	//Other methods
	void attack();

	void run();

	void adminPanel();

};

//-------------------------------------Encounter NPC Class--------------------------------------