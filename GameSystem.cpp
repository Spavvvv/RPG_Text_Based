﻿#include "GameSystem.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <vector>
#include <map>
#include <sstream>

int UPPER_DUNGEON_LEVEL = 5;
int LOWER_DUNGEON_LEVEL = 1;


GameSystem::GameSystem() {
	player = new Player(0, 0, 0, 0);
	shop = new Shop();
	Dungeon_level = 1;
}

void GameSystem::mainMenu() {
	std::cout << "1. New Game" << '\n';
	std::cout << "2. Load Game" << '\n';
	std::cout << "3. About" << '\n';
	std::cout << "4. Exit" << '\n';

	std::string input;

	std::cout << "Your option: ";

	std::cin >> input;

	//validate the input 
	if (input.length() == 1 && stoi(input) > 0 && stoi(input) < 5) {
		if (input == "1") {
			newGame();
		}
		else if (input == "2") {
			loadGame();
		}
		else if (input == "3") {
			std::cout << "first version of the game, but we're not sure if the second version is exist or not... \n";
			author();
		}
		else if (input == "4") {
			exit();
		}
	}
	else {
		std::cout << "Invalid option !" << '\n';
		mainMenu();
	}

	//clear the std::cin and the cin buffer if the player doing some tricks to destroy the program
	//fk tester, btw
	clearCin();
}

bool GameSystem::readText(std::string filePath) {
	std::ifstream file(filePath);
	if (file.is_open()) {
		std::string line;
		while (getline(file, line)) {
			std::cout << line << '\n';
		}
		//std::cout << "\x1B[2J\x1B[H";
		file.close();
		return true;
	}
	else {
		std::cout << "Error !!!" << '\n';
		return false;
	}

}

void GameSystem::newGame() {
	std::cout << "Hello Stranger !" << '\n';
	std::cout << "\x1B[2J\x1B[H";
	std::cout << "What should we call you ?" << '\n';
	std::cout << "Your name (without space): ";

	//setting some basic information of the player 
	std::string name;
	std::cin >> name;
	player->setName(name);

	//set the level information
	Dungeon_level = LOWER_DUNGEON_LEVEL;

	std::cout << "Let's start your journey," << player->getName() << '\n';
	readText("text\\introduce.txt");
	genMonster();
	play();
}

void GameSystem::level_Up() {
	while (player->getExperience() >= 100) {
		player->setMaxHealth(player->getMaxHealth() + 20);
		player->setHealth(player->getMaxHealth());
		player->setAttack(player->getAttack() + 5);
		player->setDefend(player->getDefend() + 5);
		player->setLevel(player->getLevel() + 1);
		player->setCritical(player->getCritical() + 0);			//Hehe :D
		player->setExperience(player->getExperience() - 100);

		//inform player that level up
		std::cout << "LEVEL UP !!!" << '\n';
	}
}

bool GameSystem::saveGame() {
	//Take the savefile location when the savefile has the .save 
	std::string fileSaveLocation = "save\\saveFile.save";
	std::ofstream fileSave(fileSaveLocation);

	if (!fileSave.is_open()) {
		std::cout << "Error in Saving !!!" << '\n';
		return false;
	}
	else {
		//save some basic informations
		fileSave << player->getName() << '\n';
		fileSave << player->getHealth() << " ";
		fileSave << player->getMaxHealth() << " ";
		fileSave << player->getAttack() << " ";
		fileSave << player->getDefend() << " ";
		fileSave << player->getLevel() << " ";
		fileSave << player->getExperience() << " ";
		fileSave << player->getCritical() << " ";

		//special information
		fileSave << player->getChoosen() << " ";
		fileSave << player->getJew() << " ";
		fileSave << player->getVip() << " ";
		fileSave << player->getAdmin() << '\n';

		//money, yeah, actually, because it's money so.. y'all know, it should have a separate line.. 
		// idk but maybe it'll give me some lucky like.. tomorrow, i may pick up some of them.
		fileSave << player->getMoney() << '\n';

		//save the equipment and the plag that mark the equipment
		for (int i = 0; i < 6; i++) {
			if(i<5)
				fileSave << player->getIsEquip(i) << " ";
			else 
				fileSave << player->getIsEquip(i);
		}

		fileSave << '\n';

		//save the dungeon level 
		fileSave << Dungeon_level << '\n';

		for (int i = 0; i < 6; i++) {
			if (player->getIsEquip(i) == true) {
				fileSave << player->getEquipmentBox(i)->getName() << " ";
				fileSave << player->getEquipmentBox(i)->getType() << " ";
				fileSave << player->getEquipmentBox(i)->getLevel() << " ";
				fileSave << player->getEquipmentBox(i)->getMoney() << " ";
				fileSave << player->getEquipmentBox(i)->getHealth() << " ";
				fileSave << player->getEquipmentBox(i)->getAttack() << " ";
				fileSave << player->getEquipmentBox(i)->getDefend() << " ";
				fileSave << player->getEquipmentBox(i)->getCritical_percent() << " ";
				fileSave << player->getEquipmentBox(i)->getDescription() << " ";
				fileSave << player->getEquipmentBox(i)->getID() << " ";
				if (i >= 0 && i < 4) {
					fileSave << dynamic_cast<Equipment*>(player->getEquipmentBox(i))->getDurability() << " ";
				}
				else {
					fileSave << dynamic_cast<Consumable*>(player->getEquipmentBox(i))->getDuration() << " ";
				}
				fileSave << '\n';
			}
		}

		fileSave << '\n';
		//---------------------SAVE THE BAG @@--------------------------------

		if (player->getBagSize() != 0) {
			for (int i = 0; i < player->getBagSize(); i++) {
				fileSave << player->getBag(i)->getName() << " ";
				fileSave << player->getBag(i)->getType() << " ";
				fileSave << player->getBag(i)->getLevel() << " ";
				fileSave << player->getBag(i)->getMoney() << " ";
				fileSave << player->getBag(i)->getHealth() << " ";
				fileSave << player->getBag(i)->getAttack() << " ";
				fileSave << player->getBag(i)->getDefend() << " ";
				fileSave << player->getBag(i)->getCritical_percent() << " ";
				fileSave << player->getBag(i)->getDescription() << " ";
				fileSave << player->getBag(i)->getID() << " ";
				if (player->getBag(i)->getType() == "Helmet" || player->getBag(i)->getType() == "Armor" || player->getBag(i)->getType() == "Ring" || player->getBag(i)->getType() == "Weapon") {
					fileSave << dynamic_cast<Equipment*>(player->getBag(i))->getDurability() << " ";
				}
				else {
					fileSave << dynamic_cast<Consumable*>(player->getBag(i))->getDuration() << " ";
				}
				fileSave << '\n';
			}
		}

		//close the file
		fileSave.close();

		//return true to inform that saving is complete
		return true;
	}
	return true;
}

void GameSystem::loadGame() {
	std::string loadPath = "save\\saveFile.save";		//access the save file location

	std::ifstream loadFile(loadPath);

	if (!loadFile.is_open()) {
		std::cout << "No savefile found !!!" << '\n';
		mainMenu();
	}
	else {

		//------------------LOAD THE PLAYER INFORMATION----------------------

		std::string line;
		getline(loadFile, line);
		//set player name
		player->setName(line);

		//set other information
		getline(loadFile, line);
		int count = 0;
		std::string temp = "";
		for (int i = 0; i < line.size(); i++) {
			if (line[i] != ' ') {
				temp += line[i];
			}
			else {
				switch (count)
				{
				case 0:
					player->setHealth(stoi(temp));
					temp = "";
					count++;
					break;
				case 1:
					player->setMaxHealth(stoi(temp));
					temp = "";
					count++;
					break;
				case 2:
					player->setAttack(stoi(temp));
					temp = "";
					count++;
					break;
				case 3:
					player->setDefend(stoi(temp));
					temp = "";
					count++;
					break;
				case 4:
					player->setLevel(stoi(temp));
					temp = "";
					count++;
					break;
				case 5:
					player->setCritical(stoi(temp));
					temp = "";
					count++;
					break;
				case 6:
					player->setChoosen(stoi(temp));
					temp = "";
					count++;
					break;
				case 7:
					player->setJew(stoi(temp));
					temp = "";
					count++;
					break;
				case 8:
					player->setVip(stoi(temp));
					temp = "";
					count++;
					break;
				case 9:
					player->setAdmin(stoi(temp));
					temp = "";
					count++;
					break;
				default:
					break;
				}
			}
		}

		line = "";
		count++;

		//set the money
		getline(loadFile, line);
		player->setMoney(stoi(line));


		//---------------LOAD THE FLAG OF EQUIPMENT BOX-------------------
		getline(loadFile, line);

		player->setIsEquip(0, line[0] - '0');
		player->setIsEquip(1, line[2] - '0');
		player->setIsEquip(2, line[4] - '0');
		player->setIsEquip(3, line[6] - '0');
		player->setIsEquip(4, line[8] - '0');
		player->setIsEquip(5, line[10] - '0');

		//--------------------LOAD THE LEVEL INFORMATION----------------------
		getline(loadFile, line);
		Dungeon_level = stoi(line);

		//validate the level information
		if (Dungeon_level > UPPER_DUNGEON_LEVEL) {
			Dungeon_level = UPPER_DUNGEON_LEVEL;
		}
		else if (Dungeon_level < LOWER_DUNGEON_LEVEL) {
			Dungeon_level = LOWER_DUNGEON_LEVEL;
		}

		//line = "";

		//-----------------LOAD THE EQUIPMENT BOX INFORMATION--------------------
		for (int c = 0; c < 6; c++) {
			if (line.empty() == false) {
				getline(loadFile, line);
				std::stringstream ss(line);
				//std::cout << line << '\n';
				std::string name, type;
				int level, money, health, attack, defend, critical, id, durability;
				std::string description;

				ss >> name >> type >> level >> money >> health >> attack >> defend >> critical >> description >> id >> durability;
				if (c >= 0 && c < 4) {
					Equipment* equipment = new Equipment(name, type, level, money, health, attack, defend, critical, description, id, durability);

					player->setEquipmentBox(c, equipment);
					equipment = nullptr;
					delete equipment;
				}
				else {
					Consumable* consumable = new Consumable(name, type, level, money, health, attack, defend, critical, description, id, durability);
					player->setEquipmentBox(c, consumable);
					consumable = nullptr;
					delete consumable;
				}
			}
			else {
				break;
			}
		}
		//-----------------------------LOAD THE BAG -----------------------------
		//getline(loadFile, line);
		while (getline(loadFile, line)) {
			std::stringstream ss(line);
			std::string name, type;
			int level, money, health, attack, defend, critical, id, durability;
			std::string description;

			ss >> name >> type >> level >> money >> health >> attack >> defend >> critical >> description >> id >> durability;
			if (type == "Helmet" || type == "Weapon" || type == "Ring" || type == "Armor") {
				Equipment* equipment = new Equipment(name, type, level, money, health, attack, defend, critical, description, id, durability);

				player->setBag(equipment);
				equipment = nullptr;
				delete equipment;
			}
			else {
				Consumable* consumable = new Consumable(name, type, level, money, health, attack, defend, critical, description, id, durability);
				player->setBag(consumable);
				consumable = nullptr;
				delete consumable;
			}
		}
			clearCin();
			// After loaded the game data sucessfully, let's play game
			genMonster();
			play();
	}
}

void GameSystem::encounter() {
		if (player->getChoosen() == false) {
			player->setChoosen(true);
			std::cout << "Hmm, you has been to be a Choosen person... \n";
		}
		else if(player->getJew() == false){
			player->setJew(true);
			std::cout << "Haha, I love you... A famous painter said =]]]] \n";
		}
}

void GameSystem::genMonster() {
	
	//It will random monsters each floor.
	//the probability of level 1 is 90 - 10 - 0		total monster is 5 - Goblin - Khoi
	//the probability of level 2 is 70 - 30 - 0		total monster is 8 - Spider - Khoi 
	//the probability of level 3 is 50 - 49 - 1		total monster is 10 - Khoi - Khoi - Boss
	//the probability of level 4 is 30 - 60 - 10	total monster is 15 - Khoi - Khoi - Boss
	//the probability of level 5 is 0 - 0 - 100		total monster is 3 Boss - Boss - Boss (=]]])
	
	//first class monster will have base statistic <= player statistic
	//second class monster stronger, but not too much, it's from 10 - 30 % stronger, but ofcourse, lower HP.
	//boss statistic -> 100 to 200% stronger than player if they don't have special attribute, hahaha =]]]


	//create a struct for data of level distribution for monsters
	struct levelDistribution {
		int first_class;
		int second_class;
		int boss;
	};


	//create a vector to contain the data of level distribution
	std::vector<levelDistribution> probabilities = {
		{90, 10, 0},	//level 1
		{70, 30, 0},	//level 2
		{50, 50, 0},	//level 3
		{30, 67, 3},	//level 4
		{0, 0, 100}		//level 5
	};

	//Define number of monsters for each level using enum class
	const enum class Monster_Level {
		MONSTER_LEVEL_1 = 5, 
		MONSTER_LEVEL_2 = 8,
		MONSTER_LEVEL_3 = 10,
		MONSTER_LEVEL_4 = 15,
		MONSTER_LEVEL_5 = 3
	};

	//using std::map to map an integer to monster_level
	std::map<int, Monster_Level> level_map = {
		{1, Monster_Level::MONSTER_LEVEL_1},
		{2, Monster_Level::MONSTER_LEVEL_2},
		{3, Monster_Level::MONSTER_LEVEL_3},
		{4, Monster_Level::MONSTER_LEVEL_4},
		{5, Monster_Level::MONSTER_LEVEL_5},
	};

	//random generate engine based on the uniform distribution
	std::mt19937_64 rng{ std::random_device{} () };
	std::uniform_int_distribution <std::size_t> distribution(1, 100);
	
	//generate monster
	int total_monster = static_cast<int>(level_map[Dungeon_level]);

	//std::cout << total_monster << '\n';

	int percentage = 0;
	while (total_monster > 0) {
		percentage = distribution(rng);
		if (percentage < probabilities[Dungeon_level - 1].first_class) {
			Monster* monster_ = new Monster("Goblin", 50, 50, 25, 5, player->getLevel(), 20, 10, 10);
			monster.push_back(monster_);
			total_monster --;
		}
		else if (percentage < 100 - probabilities[Dungeon_level - 1].boss && percentage > probabilities[Dungeon_level - 1].first_class) {
			Monster* monster_ = new Monster("Khoi", 70, 70, 30, 20, player->getLevel(), 40, 20, 20);
			monster.push_back(monster_);
			total_monster--;
		}
		else { 
			//If player are unlucky =]]]]
			if (Dungeon_level == 3) {
				Undead* undead = new Undead("Undead", 250, 250, 40, 75, player->getLevel(), 200, 30, 60);
				monster.push_back(undead);
				total_monster--;
			}

			//it's 10% right now, comeon, it's not our false =]]]]
			else if (Dungeon_level == 4) {
				Dragon* dragon = new Dragon("Dragon", 400, 400, 45, 45, player->getLevel(), 300, 30, 60);
				monster.push_back(dragon);
				total_monster--;
			}


			//wellcome to the hell, n**** =]]]]]]]
			else if(Dungeon_level == 5) {
					Undead* undead = new Undead("Undead", 250, 250, 40, 75, player->getLevel(), 0, 30, 0);
					undead->sieuUndead(player->getChoosen());
					monster.push_back(undead);
					Dragon* dragon = new Dragon("Dragon", 400, 400, 45, 45, player->getLevel(), 0, 30, 0);
					dragon->sieuDragon(player->getChoosen());
					monster.push_back(dragon);
					Manh* manh = new Manh("Hitler", 400, 400, 85, 55, player->getLevel(), 0, 75, 0);
					manh->sieuManh(player->getJew());
					monster.push_back(manh);
					total_monster -= 3;
			}
		}
	}

	////std::cout << monster.size() << '\n';
	//for(int i = 0; i < monster.size(); i++) {
	//	std::cout << monster[i]->getName() << '\n';
	//}
}

//the process include using items before figting and some other options like running or.. hmm
//idk, i'll add that later
void GameSystem::fighting_Process() {
	std::cout << "1. Show the monster information" << '\n';
	std::cout << "2. Open Bag" << '\n';
	std::cout << "3. Fight" << '\n';
	std::cout << "4. Run \n";
	std::cout << "5. Show your information \n";
	if (player->getAdmin() == true) {
		std::cout << "123. Admin" << '\n';
	}

	std::string choice;
	std::cout << "you choice: ";
	std::cin >> choice;
	int Ichoice = 0;
	
	if (choice.length() == 1 && stoi(choice) > 0 && stoi(choice) < 6) {
		Ichoice = stoi(choice);

		if (Ichoice == 1) {
			monster[0]->display();
		}
		else if (Ichoice == 2) {
			player->openBag();
		}
		else if (Ichoice == 3) {

			std::cout << monster.size() << '\n';

			while (player->getHealth() > 0) {	// the monster always is the first monster of the vector
				int playerDmg = player->attack();
				// The player always attack first, the system of god given to the choosen =]]]]
				if (playerDmg - monster[0]->getDefend() > 0) {
					std::cout << player->getName() << " has attack " << monster[0]->getName() << " with " << playerDmg - monster[0]->getDefend() << " damage\n";
					monster[0]->setHealth(monster[0]->getHealth() - (playerDmg - monster[0]->getDefend()));
				}
				else {
					std::cout << player->getName() << " has attack " << monster[0]->getName() << " with " << 0 << " damage\n";
				}

				//minus the duration if the player is using consumable item
				player->expire();

				//validate if the monster still alive
				if (monster[0]->getHealth() > 0) {
					int monsterDmg = monster[0]->getAttack();
					if (monsterDmg - player->getDefend() > 0) {
						std::cout << monster[0]->getName() << " has attack " << player->getName() << " with " << monsterDmg - player->getDefend() << " damage\n";
						player->setHealth(player->getHealth() - (monsterDmg - player->getDefend()));
					}
					else {
						std::cout << monster[0]->getName() << " has attack " << player->getName() << " with " << 0 << " damage\n";
					}
				}
				else {
					//Clear the monster out of the vector
					std::cout << "Monster died ! \n";
					player->setMoney(player->getMoney() + monster[0]->getMoney());
					player->setExperience(player->getExperience() + monster[0]->getExperience());
					delete monster[0];
					monster.erase(monster.begin());
					break;
				}
			}

			if (player->getHealth() <= 0) {
				//end game, delete player and return to the main menu
				std::cout << "You died ! \n";
				delete player;
				mainMenu();
			}
		}
		else if (Ichoice == 4) {
			//If player has enough condition for running, then let him run ~~"
			if (player->run(monster[0]->getLevel()) == true) {
				std::cout << "Run for your life !!! \n";
				play();
			}

			// If he's not =]]]]
			else {
				std::cout << "you're running nowhere, n**** \n";
				fighting_Process();
			}
		}
		else if(Ichoice == 5) {
			player->display();
		}
		//hmm
		if (Ichoice == 123 && player->getAdmin() == true) {
			monster[0]->setHealth(0);
			monster[0]->setDefend(0);
			std::cout << "Monster health and defend has been set to 0\n";
			fighting_Process();
		}
	}
}


void GameSystem::option() {
	std::cout << "1. Go to next level" << '\n';
	std::cout << "2. Go Shopping..." << '\n';
	std::cout << "3. Open bag" << '\n';
	std::cout << "4. Return to the main menu" << '\n';
	std::cout << "5. Return to the Desktop screen.." << '\n';

	std::string choice;
	
	std::cin >> choice;
	if (choice.length() == 1 && stoi(choice) > 0 && stoi(choice) <= 5) {

		int Ichoice = stoi(choice);
		if (Ichoice == 1) {
			genMonster();
			play();
		}
		else if (Ichoice == 2) {
			//int item, amount;
			shop->shopping(player);
			option();
		}
		else if (Ichoice == 3) {
			player->openBag();
			option();
		}
		else if (Ichoice == 4) {
			saveGame();
			mainMenu();
		}
		else {
			std::cout << "Oh, hmm, actually, i forgot to tell you that choosing this option will not save the process..." << '\n';
			std::cout << "Hehehehehe" << '\n';
			exit();
		}
	}
	else {
		std::cout << "?, are you messing with me ? \n";
		option();
	}
	//clear the std::cin and the cin buffer if the player doing some tricks to destroy the program
	//fk tester, btw
	clearCin();
}

void GameSystem::play() {

	//random of the encounter
	std::mt19937_64 rng{ std::random_device{} () };
	std::uniform_int_distribution <std::size_t> distribution(0, 100);

	int change = 10;		// the lucky number choose by Duy Shitman :>

	while (true) {

		if (change == distribution(rng)) {
			encounter();
		}

		if (monster.empty() != true) {
			std::cout << "Monster detected !" << '\n';
			fighting_Process();

			//consider if the player has enough experience to level up
			if (player->getExperience() >= 100) {
				level_Up();
			}
		}
		if (monster.empty() == true) {
			std::cout << "Level " << Dungeon_level << " cleared !" << '\n';
			Dungeon_level++;
			option();
			break;
		}
	}

}

void GameSystem::exit() {
	std::cout << "Have a good day !" << '\n';
	std::cout << "Well, forgot to tell you that this game don't have auto save =]]]]] \n";
	std::exit(0);
}

void GameSystem::clearCin() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void GameSystem::author() {
	std::cout << "1. Dat dep trai vo dich vu tru khong ai sanh bang ! \n";
	std::cout << "2. Lt.Hoag, ke huy diet moi tro rpg-text-based ! \n";
	std::cout << "3. Duy \n";
}

GameSystem::~GameSystem() {
	delete player;
	delete shop;
	if (monster.empty() == false) {
		for (int i = 0; i < monster.size(); i++) {
			delete monster[i];
		}

		monster.clear();
	}
}