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
	int Attack;
	int defend;
	int crititcal_percent;
	std::string description;

	//Id for spawn easily
	int id;

public:
	//Init
	Item(int newID);
	Item(std::string, std::string, int, int, int, int, int, int, int, string);
	~Item();

	//Getters
	std::string getName() const;
	std::string getType() const;
	int getLevel() const;
	int getMoney() const;
	int getHealth() const;
	int getAttack() const;
	int getDefend() const;
	int getCritical_percent() const;
	int getID() const;
	std::string getDescription() const;

	//Setters
	void setName(std::string);
	void setType(std::string);
	void setLevel(int);
	void setMoney(int);
	void setHealth(int);
	void setAttack(int);
	void setDefend(int);
	void setCritical_percent(int);
	void setID(int);
	void setDescription(std::string);

	//Other methods
	void deleteItem();
};

