#pragma once

#include "Character.h"

class Player : public Character {
private:
	bool isChoosenOne;
	bool isJew;
	bool isAdmin;
	bool isVip;

	int saveTimes;

	std::vector<Item*> Bag;

public:
	//Init
	Player();

	//Getter
	int getSaveTimes() const;
	bool getChoosen() const;
	bool getJew() const;
	bool getAdmin() const;
	bool getVip() const;

	//Setter
	void setSaveTimes(int saveTimes_);
	void setChoosen(bool);
	void setJew(bool);
	void setAdmin(bool);
	void setVip(bool);


	//Other methods
	void attack();

	void run();

	void adminPanel();

};
