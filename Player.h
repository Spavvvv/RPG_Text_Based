#pragma once

#include "Character.h"

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
	Player();

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

	void adminPanel();

};
