#include "Item.h"
#include<iostream>
#include<string>

#include <fstream>

	//Init
	Item::Item(){
		this->name = "";
		this->type = "";
		this->level = -1;
		this->money = -1;
		this->health = 0;
		this->Attack = 0;
		this->defend = 0;
		this->critical_percent = 0;
		id = 0;
		this->description = "";
	}


	Item::Item(std::string newName, std::string newType, int newLevel, int newMoney, int newHealth, int newAttack, int newDefend, int newCritical_percent, std::string newDescription, int newID) {

		this->name = newName;
		this->type = newType;
		this->level = newLevel;
		this->money = newMoney;
		this->health = newHealth;
		this->Attack = newAttack;
		this->defend = newDefend;
		this->critical_percent = newCritical_percent;
		this->id = newID;
		this->description = newDescription;
	}

	//Getters
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
		return Attack;
	}
	int Item::getDefend() const {
		return defend;
	}
	int Item::getCritical_percent() const {
		return critical_percent;
	}
	std::string Item::getDescription() const {
		return description;
	}
	int Item::getID() const {
		return id;
	}

	//Setters
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
		this->Attack = newAttack;
	}
	void Item::setDefend(int newDefend) {
		this->defend = newDefend;
	}
	void Item::setCritical_percent(int newCritical_percent) {
		this->critical_percent = newCritical_percent;
	}
	void Item::setDescription(std::string newDescription) {
		this->description = newDescription;
	}
	void Item::setID(int newID) {
		this->id = newID;
	}

	//Other methods
	void Item::deleteItem() {
		delete this;
	}
