#pragma once

#include "Character.h"

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
