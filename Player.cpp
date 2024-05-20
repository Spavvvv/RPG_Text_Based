#include "Player.h"

#include <random>

#include "iostream"

#include "GameSystem.h"

#include "Consumable.h"

//Init
Player::Player(bool isChoosenOne, bool isJew, bool isAdmin, bool isVip, int money)
	: Character(), isChoosenOne(false), isJew(false), isAdmin(false), isVip(false), money(0) {

	for (int i = 0; i < 6; i++) {
		Box[i] = nullptr;
		isEquip[i] = false;
	}

}

//getter
bool Player::getChoosen() const {
	return isChoosenOne;
}
bool Player::getJew() const {
	return isJew;
}
bool Player::getAdmin() const {
	return isAdmin;
}
bool Player::getVip() const {
	return isVip;
}
int Player::getMoney() const {
	return money;
}
std::vector<Item*> Player::getBag() const {
	return Bag;
}

int Player::getHealth() const{
	int additionalHealth = 0;
	for (int i = 0; i < 6; i++) {
		additionalHealth += Box[i]->getHealth();
	}
	return health + additionalHealth;
}

int Player::getAttack() const{
	int additionalAttack = 0;
	for (int i = 0; i < 6; i++) {
		additionalAttack += Box[i]->getAttack();
	}
	return Attack + additionalAttack;
}

int Player::getDefend() const{
	int additionalDefend = 0;
	for (int i = 0; i < 6; i++) {
		additionalDefend += Box[i]->getDefend();
	}
	return defend + additionalDefend;
}

int Player::getCritical() const{
	int additionalCrit = 0;
	for (int i = 0; i < 6;  i++) {
		additionalCrit += Box[i]->getCritical_percent();
	}
	return critical_percent + additionalCrit;
}

//setter
void Player::setChoosen(bool isChoosen_) {
	isChoosenOne = isChoosen_;
}
void Player::setJew(bool isJew_) {
	isJew = isJew_;
}
void Player::setAdmin(bool isAdmin_) {
	isAdmin = isAdmin_;
}
void Player::setVip(bool isVip_) {
	isVip = isVip_;
}
void Player::setMoney(int money_) {
	money = money_;
}
void Player::setBag(Item* item) {
	Bag.push_back(item);
}
//other methods
int Player::attack() {

	//random critical change of player
	std::mt19937_64 rng{ std::random_device {} () };
	std::uniform_int_distribution<std::size_t> distribution(1, 100);

	int random = distribution(rng);
	int dmg = 0;

	//calculate the attack damage, hasn't add vip properties yet !
	if (random <= critical_percent) {
		dmg = Attack * 2;
	}
	else {
		dmg = Attack;
	}
	
	int additionalAtk = 0;
	for (int i = 0; i < 6; i++) {
		additionalAtk += Box[i]->getCritical_percent();
	}
	return dmg + additionalAtk;
}

//method for open the bag
void Player::openBag() {
	for (int i = 0; i < Bag.size(); i++) {
		std::cout << i + 1 << ". " << Bag[i]->getName() << '\n';
	}

	int option;
	std::cout << "Your Option: ";
	std::cin >> option;

	if (option > 0 && option <= Bag.size()) {
		if (option % 2 == 1) {
			int equipmentOption;
			std::cout << "1. Equip" << std::endl << "2. Enhance" << std::endl;
			std::cin >> equipmentOption;
			if (equipmentOption == 1) Equip(option);
			else if (equipmentOption == 2) {} //ENhance function
		}
		else {
			useItem(option);
		}
	}
	
}

bool Player::run(int monsterLevel) {

	//Basic running way of user, haven't calcualte the Items and the Vip properties yet
	if (level - monsterLevel >= 5) {
		return true;
	}
	else {
		return false;
	}

	return false;
}

//methods for equipable items

void Player::Equip(int index) {
	//check if the new equipment item type is wearing or not 
	if (Bag[index]->getType() == "Weapon") {
		if (isEquip[0] == true) {
			unEquip("Weapon");
		}
		Box[0] = Bag[index];
		Bag[index] = nullptr;
	}
	else if (Bag[index]->getType() == "Armor") {
		if (isEquip[1] == true) {
			unEquip("Armor");
		}
		Box[1] = Bag[index];
		Bag[index] = nullptr;
	}
	else if (Bag[index]->getType() == "Helmet") {
		if (isEquip[2] == true) {
			unEquip("Helmet");
		}
		Box[2] = Bag[index];
		Bag[index] = nullptr;
	}
	else {
		if (isEquip[3] == true) {
			unEquip("Ring");
		}
		Box[3] = Bag[index];
		Bag[index] = nullptr;
	}

	//delete the item out of the bag
	//delete Bag[index];
	Bag.erase(Bag.begin() + index);
}

void Player::unEquip(std::string type) {
	for (int i = 0; i < 4; i++) {
		if (Box[i]->getType() == type) {
			Bag.push_back(Box[i]);

			//delete the item out of the equipment box
			delete Box[i];
			break;
		}
	}
}


//methods for consumable items
void Player::useItem(int index) {
	if (Bag[index]->getType() == "Healing") {
		if (health + Bag[index]->getHealth() < getMaxHealth()) {
			health += Bag[index]->getHealth();
		}
		else {
			health = getMaxHealth();
		}

		delete Bag[index];
		Bag.erase(Bag.begin() + index);
	}

	if (Bag[index]->getType() == "Boosting") {
		if (isEquip[5] == true) {
			std::cout << "U can use that more than one time !!! \n";
		}
		else {
			Box[5] = Bag[index];
			Bag[index] = nullptr;
		}
	}
}

void Player::expire() {
	if (isEquip[5] == true) {
		Consumable* consumable = dynamic_cast<Consumable*>(Box[5]);
		if (consumable->getDuration() == 0) {
			Box[5] = nullptr;
		}
		consumable->setDuration(consumable->getDuration() - 1);
	}
}