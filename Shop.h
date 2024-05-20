#pragma once

#include <vector>

#include "Item.h"

#include "Equipment.h"

#include "Consumable.h"

#include "Player.h"

//enum class WeaponType {
//	Sword,
//	Shield,
//	Shoe,
//	Ring,
//	Axe,
//	Bow
//};

//enum class Consumable_Items {
//	Potion,				// healing 
//	Red_Blue,			// legend Item of bach khoa university, increase the attack 
//	Purge,				// increase the success of Running
//	Resistance,			// increase the defend of player
//	Tear_Of_Lucky		// Increasing Lucky and the Critical Rate
//};

class Shop {
private:
	std::vector<Equipment*> EquipmentsInStock;
	std::vector<Consumable*> ConsumablesInStock;

//	int money;
public:
	//Init
	Shop();

	//getter

	//setter

	//other methods
	bool Buy();

	bool Sell();

	static bool Enhance();
	void menuShop();
	void Shopping(Player* player);

	//For those who paid for the game, thanks
	bool Cheat_Code();

};

