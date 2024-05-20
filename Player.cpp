#include "Player.h"

#include <random>

#include "iostream"

#include "GameSystem.h"

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

int Player::getHealth() const{
	int additionalHealth = 0;
	for (int i = 0; i < Box.size(); i++) {
		additionalHealth += Box[i]->getHealth();
	}
	return health + additionalHealth;
}

int Player::getAttack() const{
	int additionalAttack = 0;
	for (int i = 0; i < Box.size(); i++) {
		additionalAttack += Box[i]->getAttack();
	}
	return Attack + additionalAttack;
}

int Player::getDefend() const{
	int additionalDefend = 0;
	for (int i = 0; i < Box.size(); i++) {
		additionalDefend += Box[i]->getDefend();
	}
	return defend + additionalDefend;
}

int Player::getCritical() const{
	int additionalCrit = 0;
	for (int i = 0; i < Box.size(); i++) {
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
	for (int i = 0; i < Box.size(); i++) {
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
			Equip(option);
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
		if (hasWeapon == true) {
			unEquip("Weapon");
		}
	}
	else if (Bag[index]->getType() == "Armor") {
		if (hasArmor == true) {
			unEquip("Armor");
		}
	}
	else if (Bag[index]->getType() == "Helmet") {
		if (hasHelmet == true) {
			unEquip("Helmet");
		}
	}
	else {
		if (hasRing == true) {
			unEquip("Ring");
		}
	}

	//Eqiup the item
	Box.push_back(Bag[index]);


	//delete the item out of the bag
	delete Bag[index];
	Bag.erase(Bag.begin() + index);
}

void Player::unEquip(std::string type) {
	for (int i = 0; i < Box.size(); i++) {
		if (Box[i]->getType() == type) {
			Bag.push_back(Box[i]);

			//delete the item out of the equipment box
			delete Box[i];
			Box.erase(Box.begin() + i);

			break;
		}
	}
}


//methods for consumable items
void Player::useItem(int index) {
	if (Bag[index]->getType() == "Healing") {
		if (isUsingHealing == true) {
			std::cout << "U can use that more than one time !!! \n";
		}
	}
	else if (Bag[index]->getType() == "Boosting") {
		if (isUsingBoosting == true) {
			std::cout << "U can use that more than one time !!! \n";
		}
	}
	
	Box.push_back(Bag[index]);
}