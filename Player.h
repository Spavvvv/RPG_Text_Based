#pragma once

#include "Character.h"

const int PLAYER_MAX_HEALTH = 999;
const int PLAYER_MAX_ATTACK = 999;
const int PLAYER_MAX_DEFEND = 999;
const int PLAYER_MAX_CRITICAL = 100;
const int PLAYER_MAX_EXPERIENCE = 1000;
const int PLAYER_MAX_LEVEL = 99;


class Player : public Character {
private:
	//special properties
	bool isChoosenOne;
	bool isJew;
	bool isAdmin;
	bool isVip;

	//User Bag
	std::vector<Item*> Bag;

	//money
	int money;

public:
	//Init
	Player() : Character() {};

	//Getter
	bool getChoosen() const;
	bool getJew() const;
	bool getAdmin() const;
	bool getVip() const;
	int getMoney() const;

	//Setter
	void setChoosen(bool);
	void setJew(bool);
	void setAdmin(bool);
	void setVip(bool);
	void setMoney(int);

	//Other methods
	int attack();

	//methods for equipable items
	static bool Equip();

	static bool unEquip();


	//methods for consumable items
	static bool useItem();



	bool run(int monsterLevel);

	void run();

	void adminPanel();

};
