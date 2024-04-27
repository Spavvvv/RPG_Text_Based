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
	std::string fileSaveLocation = "save\\save" + std::to_string(player->getSaveTimes()) + ".save";
	std::ofstream fileSave(fileSaveLocation);

	if (!fileSave.is_open()) {
		std::cout << "Error !!!" << '\n';
		return false;
	}
	else {
		//save some basic informations
		fileSave << player->getName() << '\n';
		fileSave << player->getHealth() << '\n';
		fileSave << player->getAttack() << '\n';
		fileSave << player->getDefend() << '\n';
		fileSave << player->getLevel() << '\n';
		fileSave << player->getExperience() << '\n';
		fileSave << player->getCritical() << '\n';
		fileSave << player->getSaveTimes() << '\n';
		
		//special information
		fileSave << player->getChoosen() << '\n';
		fileSave << player->getJew() << '\n';
		fileSave << player->getVip() << '\n';
		fileSave << player->getAdmin() << '\n';

		//change the save times
		player->setSaveTimes(player->getSaveTimes() + 1);

		//close the file
		fileSave.close();

		//return true to inform that saving is complete
		return true;
	}
	return true;
}

bool GameSystem::loadGame() {
	std::ifstream loadFile;
	std::string loadPath = "save\\";
}

void GameSystem::play() {
	
}

