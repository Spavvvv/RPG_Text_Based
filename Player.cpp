#include "Player.h"

Player::Player() : Character(), isChoosenOne(false), isJew(false), isAdmin(false), isVip(false), saveTimes(0) {

}

void Player::attack() {

}

//getter
int Player::getSaveTimes() const {
	return saveTimes;
}