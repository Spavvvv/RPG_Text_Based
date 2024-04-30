#include "GameSystem.h"
#include <iostream>
#include <string>
#include <fstream>

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

	std::string name;
	std::cin >> name;
	player->setName(name);

	std::cout << "Let's start your journey," << player->getName() << '\n';
	readText("text\\introduce.txt");
	play();
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
		fileSave << player->getAdmin();

		//money, yeah, actually, because it's money so.. y'all know, it should have a separate line.. 
		// idk but maybe it'll give me some lucky like.. tomorrow, i'll pick up some of them.
		fileSave << player->getMoney();

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
		std::cout << "Error in loading.. !!!" << '\n';
		std::cout << "Your save file is corrupted or something @@" << '\n';
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
	}
}

void GameSystem::play() {
	
}

