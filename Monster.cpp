#include "Monster.h"
void Undead::display(){
		std::cout << "Name:  "<< getName() << "\n";
		std::cout << "Health: " << getHealth() << "\n";
		std::cout << "Attack: " << getAttack() << "\n";
		std::cout << "--------------------------\n";
	}
void Dragon::display() {
	std::cout << "Name:  " << getName() << "\n";
	std::cout << "Health: " << getHealth() << "\n";
	std::cout << "Attack: " << getAttack() << "\n";
	std::cout << "--------------------------\n";
}

void Manh::display(){
		std::cout << "Name:  "<< getName() << "\n";
		std::cout << "Health: " << getHealth() << "\n";
		std::cout << "Attack: " << getAttack() << "\n";
		std::cout << "--------------------------\n";
	}
void displayInfoMonster(Basic_monster& type) {

	/*for (const auto& monster:type) {
		monster->display();
	}
	std::cout << "" << std::endl;*/
}


bool Undead::curse() {
	return false;
}
bool Dragon::hailH() {
	return false;
}
bool Manh::loser() {
	return false;
}

int Undead::attack() {
	return Attack;
};
int Dragon::attack() {
	return Attack;
}
int Manh::attack() {
	return Attack;
}
int Undead::gethealth() {
	return health;
}
int Dragon::gethealth() {
	return health;
}
int Manh::gethealth() {
	return health;
}
void Undead::sethealth(int health) {
	this->health = health;
}
void Dragon::sethealth(int health) {
	this->health = health;
}
void Manh::sethealth(int health) {
	this->health = health;
}
