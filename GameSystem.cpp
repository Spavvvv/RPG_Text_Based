#include "GameSystem.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <vector>
#include <map>


int UPPER_DUNGEON_LEVEL = 5;
int LOWER_DUNGEON_LEVEL = 1;


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
			author();
		}
		else if (input == "4") {
			exit();
		}
		else {
			std::cout << "Invalid option !" << '\n';
			mainMenu();
		}
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
		std::cout << "\x1B[2J\x1B[H";
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
	play();
}

void GameSystem::level_Up() {
	while (player->getExperience() >= 100) {
		player->setHealth(player->getHealth() + 20);
		player->setAttack(player->getAttack() + 5);
		player->setDefend(player->getDefend() + 5);
		player->setLevel(player->getLevel() + 1);
		player->setCritical(player->getCritical() + 0);			//Hehe :D
		player->setExperience(player->getExperience() - 100);

		//inform player that level up
		std::cout << "Level Up !!!" << 'n';
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
		fileSave << player->getHealth();
		fileSave << player->getAttack();
		fileSave << player->getDefend();
		fileSave << player->getLevel();
		fileSave << player->getExperience();
		fileSave << player->getCritical();
		
		//special information
		fileSave << player->getChoosen();
		fileSave << player->getJew();
		fileSave << player->getVip();
		fileSave << player->getAdmin() << '\n';

		//money, yeah, actually, because it's money so.. y'all know, it should have a separate line.. 
		// idk but maybe it'll give me some lucky like.. tomorrow, i may pick up some of them.
		fileSave << player->getMoney();

		//save the dungeon level 
		fileSave << Dungeon_level;

		//close the file
		fileSave.close();

		//return true to inform that saving is complete
		return true;
	}
	return true;
}

bool GameSystem::loadGame() {
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
		for (int index = 0; index < line.size(); index++) {
			switch (index)
			{
			case 1:
				player->setHealth(line[index] - '0');
				break;
			case 2:
				player->setAttack(line[index] - '0');
				break;
			case 3:
				player->setDefend(line[index] - '0');
				break;
			case 4:
				player->setLevel(line[index] - '0');
				break;
			case 5:
				player->setExperience(line[index] - '0');
				break;
			case 6:
				player->setCritical(line[index] - '0');
				break;
			case 7:
				player->setChoosen(line[index] - '0');
				break;
			case 8:
				player->setJew(line[index] - '0');
				break;
			case 9:
				player->setVip(line[index] - '0');
				break;
			case 10:
				player->setAdmin(line[index] - '0');
				break;
			case 11:
				player->setMoney(line[index] - '0');
				break;
			default:
				break;
			}
		}

		//--------------------------------------------------------------------
		
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
	}
	// After loaded the game data sucessfully, let's play game
	play();

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
		{50, 49, 1},	//level 3
		{30, 60, 10},	//level 4
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
	std::uniform_int_distribution <std::size_t> distribution(0, 100);
	
	//generate monster
	int total_monster = static_cast<int>(level_map[Dungeon_level]);

	int percentage = 0;
	while (total_monster > 0) {
		percentage = distribution(rng);
		if (percentage < probabilities[Dungeon_level].first_class) {
			monster.push_back(&(Monster("Goblin", 50, 10, 10, player->getLevel(), 10, 0)));
		}
		else if (percentage < probabilities[Dungeon_level].second_class && percentage > probabilities[Dungeon_level].first_class) {
			monster.push_back(&(Monster("Khoi", 40, 20, 20, player->getLevel(), 20, 20)));
		}
		else { 

			//If player are unlucky =]]]]
			if (Dungeon_level == 3)
				monster.push_back(&(Undead("Undead", 300, 100, 80, player->getLevel(), 500, 80, false)));


			//it's 10% right now, comeon, it's not our false =]]]]
			else if (Dungeon_level == 4) {
				monster.push_back(&(Dragon("Dragon", 500, 150, 100, player->getLevel(), 1000, 80, false)));
			}


			//wellcome to the hell, n**** =]]]]]]]
			else {
				if (Dungeon_level == 5) {
					monster.push_back(&(Undead("Undead", PLAYER_MAX_HEALTH, PLAYER_MAX_ATTACK, PLAYER_MAX_DEFEND, PLAYER_MAX_LEVEL, 1, PLAYER_MAX_CRITICAL, false)));
					monster.push_back(&(Dragon("Dragon", PLAYER_MAX_HEALTH, PLAYER_MAX_ATTACK, PLAYER_MAX_DEFEND, PLAYER_MAX_LEVEL, 1, PLAYER_MAX_CRITICAL, false)));
					monster.push_back(&(Manh("Hitler", PLAYER_MAX_HEALTH, PLAYER_MAX_ATTACK, PLAYER_MAX_DEFEND, PLAYER_MAX_LEVEL, 1, PLAYER_MAX_CRITICAL, false)));
				}
				total_monster -= 2;
			}
		}
		total_monster--;
	}
}

//the process include using items before figting and some other options like running or.. hmm
//idk, i'll add that later
void GameSystem::fighting_Process() {
	std::cout << "1. Show the monster information" << '\n';
	std::cout << "2. Using items" << '\n';
	std::cout << "3. Fight" << '\n';
	std::cout << "4. Run (´。＿。｀)";
	if (player->getAdmin() == true) {
		std::cout << "123. Admin" << '\n';
	}

	std::string choice;
	std::cin >> choice;
	int Ichoice = 0;
	
	if (choice.length() == 1 && stoi(choice) > 0 && stoi(choice) < 5) {
		Ichoice = stoi(choice);

		if (Ichoice == 1) {
			monster[0]->display();
		}
		else if (Ichoice == 2) {
			openBag();
		}
		else if (Ichoice == 3) {
			while (player->getHealth()) {	// the monster always is the first monster
											// of the vector
											
			
				// The player always attack first, system of god given to the choosen =]]]]
				std::cout << player->getName() << "has attack " << monster[0]->getName() << "with " << player->attack() << "damage\n";
				monster[0]->setHealth(monster[0]->getHealth() - player->attack());

				//validate if the monster still alive
				if (monster[0]->getHealth() > 0) {
					std::cout << monster[0]->getName() << "has attack " << player->getName() << "with " << monster[0]->attack() << "damage\n";
					player->setHealth(player->getHealth() - monster[0]->attack());
				}
				else {
					//Clear the monster out of the vector
					std::cout << "Monster died ! \n";
					delete monster[0];
					monster.erase(monster.begin());
				}
			}

			if (player->getHealth() < 0) {
				//end game, delete player and return to the main menu
				std::cout << "You died ! \n";
				delete player;
				mainMenu();

			}
		}
		else if (Ichoice == 4) {
			if (player->getLevel() <= monster[0]->getLevel() - 5) {
				std::cout << "Run for your life !!! \n";
				play();
			}
			else {
				std::cout << "you're running nowhere, n**** \n";
				fighting_Process();
			}
		}

		if (Ichoice == 123 && player->getAdmin() == true) {
			monster[0]->setHealth(0);
			std::cout << "Monster health has been set to 0\n";
			fighting_Process();
		}
	}
}


void GameSystem::option() {
	std::cout << "1. Go to next level" << '\n';
	std::cout << "2. Go Shopping..." << '\n';
	std::cout << "3. Return to the main menu" << '\n';
	std::cout << "4. Return to the Desktop screen.." << '\n';

	std::string choice;
	
	std::cin >> choice;
	if (choice.length() == 1 && stoi(choice) > 0 && stoi(choice) < 5) {

		int Ichoice = stoi(choice);
		if (Ichoice == 1) {
			genMonster();
			play();
		}
		else if (Ichoice == 2) {
			Shop* shopping_place = new Shop();
			shopping_place->menuShop();		//menu of the shop, rn, 8_5_24, it's not available yet, but i think soon.
			option();
		}
		else if (Ichoice == 3) {
			saveGame();
			mainMenu();
		}
		else {
			std::cout << "Oh, hmm, actually, i forgot to tell you that choosing this option will not save the process..." << '\n';
			std::cout << "Hehehehehe" << '\n';
			exit();
		}
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
			std::cout << "Level " << Dungeon_level << "cleared !" << '\n';
			Dungeon_level++;
			option();
		}
	}

}

void GameSystem::exit() {
	std::cout << "Have a good day !" << '\n';
	std::cout << "Well, forgot to tell you that this game don't have auto save =]]]]]" << 'n';
	std::exit(0);
}

void GameSystem::clearCin() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}