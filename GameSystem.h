#pragma once

#include "Character.h"

#include <vector>

#include "Shop.h"

#include "Player.h"

#include "Monster.h"



class GameSystem {
private:
	Player* player;
	
	std::vector<Monster*> monster;

	int Dungeon_level;

	Shop* Shop;

public:
	void mainMenu();

	void newGame();

	void option();

	void play();

	void genMonster();

	void fighting_Process();

	void level_Up();

	bool saveGame();

	bool loadGame();

	void encounter();

	void exit();

	void clearCin();

	void author();

	bool readText(std::string filePath);

	//For admins
	void admin_panel();
};

