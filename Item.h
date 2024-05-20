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

	// Id for spawn easily, the CONSUMABLE ID will be even number
	// The Equipment ID will be odd number
	int id;

public:
	//Init
	Item();
	Item(std::string, std::string, int, int, int, int, int, int, int, std::string);
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

	//Special operator in the item class, idk if we gonna use it or not..
	Item& operator=(const Item& item) {
		if (this == &item) {
			return *this;
		}
		else {
			name = item.name;
			type = item.type;
			level = item.level;
			money = item.money;
			health = item.health;
			Attack = item.Attack;
			defend = item.defend;
			crititcal_percent = item.crititcal_percent;
			description = item.description;
			id = item.id;
			return *this;
		}
	}
};

