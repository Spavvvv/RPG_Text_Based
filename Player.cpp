#include "Player.h"

#include <random>

#include "iostream"

#include "GameSystem.h"

#include "Consumable.h"

//Init

Player::Player() : Character (){
	isChoosenOne = false;
	isAdmin = false;
	isJew = false;
	isVip = false;
	money = 0;

	for (int c = 0; c < 6; c++) {
		isEquip[c] = false;
		Box[c] = nullptr;
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
		if(isEquip[i] == true)
		additionalHealth += Box[i]->getHealth();
	}
	return health + additionalHealth;
}

int Player::getAttack() const{
	int additionalAttack = 0;
	for (int i = 0; i < 6; i++) {
		if (isEquip[i] == true)
		additionalAttack += Box[i]->getAttack();
	}
	return Attack + additionalAttack;
}

int Player::getDefend() const{
	int additionalDefend = 0;
	for (int i = 0; i < 6; i++) {
		if (isEquip[i] == true)
		additionalDefend += Box[i]->getDefend();
	}
	return defend + additionalDefend;
}

int Player::getCritical() const{
	int additionalCrit = 0;
	for (int i = 0; i < 6;  i++) {
		if (isEquip[i] == true) {
			additionalCrit += Box[i]->getCritical_percent();
		}
	}
	return critical_percent + additionalCrit;
}

Item* Player::getEquipmentBox(int index) const {
	return Box[index];
}
bool Player::getIsEquip(int index) const {
	return isEquip[index];
}
Item* Player::getBag(int index) const {
	return Bag[index];
}
int Player::getBagSize() const {
	return Bag.size();
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
void Player::setBag(int index, Item* item) {
	Bag[index] = item;
}

void Player::setEquipmentBox(int index,Item* item) {
	if (index >= 0 && index < 6) {
		Box[index] = item;
	}
	else {
		std::cout << "? \n";
	}
}
void Player::setIsEquip(int index, bool variable) {
	if (index >= 0 && index < 6) {
		isEquip[index] = variable;
	}
	else {
		std::cout << "? ?\n";
	}
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
	int additionalCrit = 0;
	for (int i = 0; i < 6; i++) {
		if (isEquip[i] == true) {
			additionalAtk += Box[i]->getAttack();
			additionalCrit += Box[i]->getCritical_percent();
		}
	}
	if (random <= additionalCrit)
		return dmg + additionalAtk * 2;
	else
		return dmg + additionalAtk;
}

void Player::display() {
	std::cout << "Name: " << name << '\n';
	std::cout << "Attack: " << Attack << '\n';
	std::cout << "Defend: " << defend << '\n';
	std::cout << "Health: " << health << '\n';
	std::cout << "Level: " << level << '\n';
	std::cout << "Money: " << money << '\n';
	std::cout << "Experience: " << experience << '\n';
	std::cout << "Critical: " << critical_percent << "%" << '\n';
	std::cout << "--------YOUR EQUIPMENT BOX-------- \n";
	for (int i = 0; i < 4; i++) {
		//std::cout << isEquip[i] << '\n';
		if (isEquip[i] == true) {
			std::cout << i+1 << "." << Box[i]->getName() << '\n';
		}
	}
	std::cout << "--------YOUR BAG-------- \n";
	if (Bag.empty() == false) {
		for (int i = 0; i < Bag.size(); i++) {
			std::cout << i + 1 << "." << Box[i]->getName() << '\n';
		}
	}
}

//method for open the bag
void Player::openBag() {
	if (Bag.empty() == false) {
		for (int i = 0; i < Bag.size(); i++) {
			std::cout << i + 1 << ". " << Bag[i]->getName() << '\n';
		}

		int option;
		std::cout << "Your Option: ";
		std::cin >> option;

		if (option > 0 && option <= Bag.size()) {
			if ((Bag[option - 1]->getType() == "Weapon") || (Bag[option - 1]->getType() == "Ring") || (Bag[option - 1]->getType() == "Armor") || (Bag[option - 1]->getType() == "Helmet")) {
				int equipmentOption;
				std::cout << "1. Equip" << std::endl << "2. Enhance" << std::endl << "3. Sell" << '\n';
				std::cout << "You option: ";
				std::cin >> equipmentOption;
				if (equipmentOption == 1) Equip(option - 1);
				else if (equipmentOption == 2) Enhance(option - 1);
				else Sell(option);
			}
			else {
				useItem(option - 1);
			}
		}
	}
	else {
		std::cout << "There nothing in your bag, poor af ! \n";
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
void Player::Enhance(int item) {
	int chance = 20;
	int EnhanceMoney = 20;
	int stoneItem;
	int stoneNum = 0;
	bool startEnhance = false;
	std::cout << "You are enhancing " << Bag[item - 1]->getName() << " for " << EnhanceMoney << " coins." << std::endl;
	while (!startEnhance) {
		std::cout << "Chances of success is currently " << chance << "%. Do you want to use Enhance Stone?" << std::endl;
		std::cout << "1. Yes" << std::endl << "2. No" << std::endl;
		std::cin >> stoneItem;
		if (stoneItem == 1) {
			std::vector<int> stoneSpot;
			std::cout << "How many stones do you want to use?" << std::endl;
			std::cin >> stoneNum;
			for (int j = 0; j < Bag.size(); j++) {
				if (Bag[j]->getName() == "Enhance Stone") {
					stoneSpot.push_back(j);
				}
			}
			if (stoneSpot.size() < static_cast<unsigned long long>(stoneNum) - 1) {
				std::cout << "You don't have enough Enhance Stone" << std::endl;
			}
			else {
				for (int i = 0; i < stoneNum; i++) {
					chance = chance + (100 - chance) / 6;
					delete Bag[stoneSpot[0]];
					Bag.erase(Bag.begin() + stoneSpot[0]);
					stoneSpot.erase(stoneSpot.begin());
				}
			}
		}
		else {
			startEnhance = true;
		}
	}
	std::mt19937_64 rng{ std::random_device {} () };
	std::uniform_int_distribution<std::size_t> distribution(1, 100);

	int random = distribution(rng);
	if (random > chance) {
		std::cout << "Enhance failed. Try again next time." << std::endl;
	}
	else {
		std::cout << "Enhance succedd!" << std::endl;
		Bag[item]->setMoney(Bag[item]->getMoney() + 60);
		if (Bag[item]->getType() == "Weapon") {
			Bag[item]->setAttack(Bag[item]->getAttack() + 3);
		}
		if (Bag[item]->getType() == "Armor") {
			Bag[item]->setDefend(Bag[item]->getDefend() + 3);
		}
		if (Bag[item]->getType() == "Helmet") {
			Bag[item]->setDefend(Bag[item]->getDefend() + 3);
		}
		if (Bag[item]->getType() == "Ring") {
			Bag[item]->setCritical_percent(Bag[item]->getCritical_percent() + 3);
		}
	}
}
void Player::Sell(int item) {
	int confirmSell;
	std::cout << "Are you sure you want to sell this item? You can't undo once you do this" << std::endl;
	std::cout << "1. Yes" << std::endl << "2. No" << std::endl;
	std::cin >> confirmSell;
	if (confirmSell == 1) {
		// Unequip the item part missing
		setMoney(getMoney() + Bag[item]->getMoney() / 10); //=]]
		delete Bag[item];
		Bag.erase(Bag.begin() + item);
	}
}

//methods for equipable items

void Player::Equip(int index) {
	//check if the new equipment item type is wearing or not 
	if (Bag[index]->getType() == "Weapon") {
		if (isEquip[0] == true) {
			unEquip("Weapon");
		}

		Box[0] = Bag[index];
		isEquip[0] = true;
		Bag[index] = nullptr;
		delete Bag[index];
	}
	else if (Bag[index]->getType() == "Armor") {
		if (isEquip[1] == true) {
			unEquip("Armor");
		}
		
		Box[1] = Bag[index];
		isEquip[1] = true;
		Bag[index] = nullptr;
		delete Bag[index];
	}
	else if (Bag[index]->getType() == "Helmet") {
		if (isEquip[2] == true) {
			unEquip("Helmet");
		}
		
		Box[2] = Bag[index];
		isEquip[2] = true;
		Bag[index] = nullptr;
		delete Bag[index];
	}
	else {
		if (isEquip[3] == true) {
			unEquip("Ring");
		}
		
		Box[3] = Bag[index];
		isEquip[3] = true;
		Bag[index] = nullptr;
		delete Bag[index];
	}

	//delete the item out of the bag
	//delete Bag[index];
	Bag.erase(Bag.begin() + index);
}

void Player::unEquip(std::string type) {
	for (int i = 0; i < 4; i++) {
		if (Box[i]->getType() == type) {
			Bag.push_back(Box[i]);
			isEquip[i] = false;
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
			std::cout << "U can't use that more than one time !!! \n";
		}
		else {
			Box[5] = Bag[index];
			isEquip[5] = true;
			Bag[index] = nullptr;
			delete Bag[index];
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

Player::~Player() {
	if (Bag.empty() == false) {
		for (int i = 0; i < Bag.size(); i++) {
			delete Bag[i];
		}
		Bag.clear();
	}

	for (int i = 0; i < 6; i++) {
		if(Box[i] != nullptr)
		delete Box[i];
	}
}