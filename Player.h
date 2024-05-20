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
	std::vector<Item*> Box;

	//money
	int money;

	//properties for detect if player has equip items or not
	bool hasWeapon;	
	bool hasArmor;
	bool hasHelmet;
	bool hasRing;
public:
	//Init
	Player(bool isChoosenOne, bool isJew, bool isAdmin, bool isVip, int money, bool hasWeapon, bool hasArmor, bool hasHelmet, bool hasRing) 
		: Character(), isChoosenOne(false), isJew(false), isAdmin(false) , isVip(false), money(0), hasWeapon(false), hasArmor(false), hasHelmet(false), hasRing(false) {};

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

	//method for open the bag
	void openBag();

	//methods for equipable items
	void checkEquip(int index, std::string type);

	void Equip(int index);

	void unEquip(std::string type);

	//methods for consumable items
	void useItem();

	bool run(int monsterLevel);

	static bool run();

	void adminPanel();

};
