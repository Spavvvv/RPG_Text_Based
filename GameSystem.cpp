#include "GameSystem.h"

#include <iostream>

//enum class menuOption {
//	New_Game,
//
//};

void GameSystem::mainMenu() {
	std::cout << "1. New Game" << '\n';
	std::cout << "2. Load Game" << '\n';
	std::cout << "3. About" << '\n';
	std::cout << "4. Exit" << '\n';

	int choice;
	std::cout << "Your choice: ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		newGame();
		break;
	case 2:
		loadGame();
		break;
	default:
		break;
	}

}

void GameSystem::newGame() {
	std::cout << "Hello Stranger !" << '\n';
	std::cout << "\x1B[2J\x1B[H";
	std::cout << "What should we call you ?" << '\n';
}

void GameSystem::play() {
}
