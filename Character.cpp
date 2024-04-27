#include "Character.h"

Character::Character() {
	name = "";
	health = 0;
	Attack = 0;
	defend = 0;
	level = 1;
	experience = 0;
	critical_percent = 0;
}

//setter
void Character::setName(std::string name_) {
	name = name_;
}
void Character::setHealth(int health_) {
	health = health_;
}
void Character::setAttack(int Attack_) {
	Attack = Attack_;
}
void Character::setDefend(int defend_) {
	defend = defend_;
}
void Character::setLevel(int level_) {
	level = level_;
}
void Character::setExperience(int experience_) {
	experience = experience_;
}
void Character::setCritical(int critical_) {
	critical_percent = critical_;
}

//getter
std::string Character::getName() const {
	return name;
}
int Character::getHealth() const {
	return health;
}
int Character::getAttack() const {
	return Attack;
}
int Character::getDefend() const {
	return defend;
}
int Character::getLevel() const {
	return level;
}
int Character::getExperience() const {
	return experience;
}
int Character::getCritical() const {
	return critical_percent;
}

//other methods
int attack() {}