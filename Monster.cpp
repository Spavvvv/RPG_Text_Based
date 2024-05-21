#include "Monster.h"
#include "Player.h"

void Monster::display() {
	std::cout << "Name: " << name;
	std::cout << '\n';
	std::cout << "Health: " << health;
	std::cout << '\n';
	std::cout << "Attack: " << Attack;
	std::cout << '\n';
	std::cout << "Defend: " << defend;
	std::cout << '\n';
	std::cout << "Level: " << level;
	std::cout << '\n';
	std::cout << "Experience: " << experience;
	std::cout << '\n';
}


void Undead::sieuUndead(bool check) {
	if (check) {
		this->health = PLAYER_MAX_HEALTH;
	}
}
void Dragon::sieuDragon(bool check) {
	if (check) {
		this->defend = PLAYER_MAX_DEFEND;
	}
}
void Manh::sieuManh(bool check) {
	if (check) {
		this->Attack = PLAYER_MAX_ATTACK;
		this->critical_percent = PLAYER_MAX_CRITICAL;
	}
}
