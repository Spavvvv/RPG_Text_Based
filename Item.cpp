#include "Item.h"
#include<iostream>
#include<string>

	Item::Item(int newID){
		this->name = "";
		this->type = "";
		this->level = -1;
		this->money = -1;
		this->health = 0;
		this->attack = 0;
		this->defend = 0;
		this->ID = newID;
	}
	Item::Item(std::string newName, std::string newType, int newLevel, int newMoney, int newHealth, int newAttack, int newDefend, int newID){
		this->name = newName;
		this->type = newType;
		this->level = newLevel;
		this->money = newMoney;
		this->health = newHealth;
		this->attack = newAttack;
		this->defend = newDefend;
		this->ID = newID;
	}
	std::string Item::getName() const {
		return name;
	}
	std::string Item::getType() const {
		return type;
	}
	int Item::getLevel() const {
		return level;
	}
	int Item::getMoney() const {
		return money;
	}
	int Item::getHealth() const {
		return health;
	}
	int Item::getAttack() const {
		return attack;
	}
	int Item::getDefend() const {
		return defend;
	}
	int Item::getID() const {
		return ID;
	}
	//Getter
		this->name = newName;
		this->type = newType;
		this->level = newLevel;
		this->money = newMoney;
		this->health = newHealth;
		this->attack = newAttack;
		this->defend = newDefend;
		this->ID = newID;
	void Item::setName(std::string newName) {
		this->name = newName;
	}
	void Item::setType(std::string newType) {
		this->type = newType;
	}
	void Item::setLevel(int newLevel) {
		this->level = newLevel;
	}
	void Item::setMoney(int newMoney) {
		this->money = newMoney;
	}
	void Item::setHealth(int newHealth) {
		this->health = newHealth;
	}
	void Item::setAttack(int newAttack) {
		this->attack = newAttack;
	}
	void Item::setDefend(int newDefend) {
		this->defend = newDefend;
	}
	void Item::setID(int newID) {
		this->ID = newID;
	}

	//Other methods
	void Item::deleteItem() {
		delete this;
	}
