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
	Item(std::string, std::string, int, int, int, int, int, int,);
	~Item();

	//Getters
	std::string getName() const;
	std::string getType() const;
	int getLevel() const;
	int getMoney() const;
	int getHealth() const;
	int getAttack() const;
	int getDefend() const;
	int getID() const;

	//Setters
	void setName(std::string);
	void setType(std::string);
	void setLevel(int);
	void setMoney(int);
	void setHealth(int);
	void setAttack(int);
	void setDefend(int);
	void setID(int);

	//Other methods
	void deleteItem();
};

