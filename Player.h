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

	//Bringable bag
	std::vector<Item*> Bag;

	//Place that store the item player had equipped
	Item* Box[6];
	bool isEquip[6];

	//money
	int money;


public:
	//Init
	Player(bool isChoosenOne, bool isJew, bool isAdmin, bool isVip, int money) {}

	//Getter
	bool getChoosen() const;
	bool getJew() const;
	bool getAdmin() const;
	bool getVip() const;
	int getMoney() const;
	std::vector<Item*> getBag() const;

	//Setter
	void setChoosen(bool);
	void setJew(bool);
	void setAdmin(bool);
	void setVip(bool);
	void setMoney(int);
	void setBag(Item*);
	//Other methods
	int attack();

	//getter
	int getHealth() const;
	int getAttack() const;
	int getDefend() const;
	int getCritical() const;

	//method for open the bag
	void openBag();

	void Enhance(int);

	void Sell(int);

	void Equip(int index);

	void unEquip(std::string type);

	//methods for consumable items
	void useItem(int index);

	void expire();

	bool run(int monsterLevel);

	void adminPanel();

};
