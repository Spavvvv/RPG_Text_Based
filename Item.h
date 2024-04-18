#pragma once
#include<iostream>
#include <string>

class Item {
protected:
	//Basic Stats of the Items
	std::string name;
	std::string type;
	int level;
	int money;
	int health;
	int attack;
	int defend;

	//Id for spawn easily
	int id;

public:
	//Init
	Item(int newID);

	//Setter
	std::string getName() const;
	std::string getType() const;
	int getLevel() const;
	int getMoney() const;
	int getHealth() const;
	int getAttack() const;
	int getDefend() const;
	//Getter
	void setName();
	void setType();
	void setLevel();
	void setMoney();
	void setHealth();
	void setAttack();
	void setDefend();

	//Other methods
	void deleteItem();
};

