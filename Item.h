#pragma once

#include <string>

class Item {
private:
	//Basic Stats of the Items
	std::string name;
	int level;

	int attack;
	int defend;
	int reliability;

	//Other sepcial attribute of the Items
	bool is_Consumable;
	bool is_Holy;
	bool is_Bleeding;
	int number;

	//Id for spawn easily
	int id;

public:
	//Init
	Item();

	//Setter

	//Getter

	//Other methods
	bool Use();

	bool Equip();

	bool Unequip();
};

