#include "Item.h"
#include<iostream>
#include<string>

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
