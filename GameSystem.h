#pragma once

#include "Character.h"

#include <vector>

#include "Shop.h"

class GameSystem {
private:
	Player* player;
	
	std::vector<Monster*> monster;

public:
	void play();

	void fighting_Process();

	void level_Up();

	void saveGame();

	void loadGame();

	void Encounter();

	//For admins
	void admin_panel();
};

