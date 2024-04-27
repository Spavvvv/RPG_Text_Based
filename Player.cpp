#include "Player.h"

#include <random>



Player::Player() : Character(), isChoosenOne(false), isJew(false), isAdmin(false), isVip(false), saveTimes(0) {

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

int Player::getSaveTimes() const {
	return saveTimes;
}

//setter
void Player::setSaveTimes(int saveTimes_) {
	saveTimes = saveTimes_;
}
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


//other methods

int Player::attack() {

	//random critical change of player
	std::mt19937_64 rng{ std::random_device {} () };
	std::uniform_int_distribution<std::size_t> distribution(1, 100);

	int random = distribution(rng);
	int dmg = 0;

	if (random <= critical_percent) {
		dmg = Attack * 2;
	}
	else {
		dmg = Attack;
	}
	return dmg;
}

bool Player::run(int monsterPlayer) {
	if (level - monsterPlayer >= 5) {
		return true;
	}
	else {
		return false;
	}
	return false;
}