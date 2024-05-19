#include "Monster.h"

Monster::Monster(std::string, int, int, int, int, int, int) : name(""), health(0), attack(0), defend(0), level(1), experience(50), critical_percent(0) {

}


void Monster::setName(std::string name_) {
	name = name_;
}
void Monster::setHealth(int health_) {
	health = health_;
}
void Monster::setAttack(int Attack_) {
	Attack = Attack_;
}
void Monster::setDefend(int defend_) {
	defend = defend_;
}
void Monster::setLevel(int level_) {
	level = level_;
}
void Monster::setExperience(int experience_) {
	experience = experience_;
}
std::string Monster::getName() const {
	return name;
}
int Monster::getHealth() const {
	return health;
}
int Monster::getAttack() const {
	return Attack;
}
int Monster::getDefend() const {
	return defend;
}
int Monster::getLevel() const {
	return level;
}
int Monster::getExperience() const {
	return experience;
}

int attack() {

	int random = distribution(rng);
	int dmg = 0;
	dmg = Attack;
	return dmg;
};
void Undead::attack(int attack) {
	this->attack = attack;
}
int Undead::attack() {
	return attack;
}
void Undead::health(int health) {
	this->health = health;
}
int Undead::health() {
	return health;
}
void Dragon::attack(int attack) {
	this->attack = attack;
}
int Dragon::attack() {
	return attack;
}
void Dragon::health(int health) {
	this->health = health;
}
int Dragon::health() {
	return health;
}
void Manh::attack(int attack) {
	this->attack = attack;
}
int Manh::attack() {
	return attack;
}
void Manh::health(int health) {
	this->health = health;
}
int Manh::health() {
	return health;
}
bool Undead::curse() {
	return true;
}
bool Manh::hailH() {
	return true;
}
bool Dragon::loser() {
	return true;
}	
void display() {
	if (bool Undead::curse() == false) {
		cout << "Ineffective!!" << endl;
	}
	else {
		cout << "The monster has" << getHealth() << "left" << endl;
	}
	
}
