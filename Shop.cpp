#include "Shop.h"
#include "Item.h"
#include "Equipment.h"
#include "Consumable.h"
Shop::menuShop() {
    EquipmentsInStock.emplace_back("Old Sword", "Weapon", 1, 50, 0, 5, 0, 0, 101, "The most basic weapon for an adventurer, essential for early grind", 100, false);
    EquipmentsInStock.emplace_back("Old Armor", "Armor", 1, 50, 25, 0, 0, 0, 121, "Gives you a tiny bit of HP. Bulk up soldier!", 100, false);
    EquipmentsInStock.emplace_back("Old Helmet", "Helmet", 1, 50, 0, 0, 5, 0, 141, "Protects you from incoming damages, withstand more attacks from regular monsters", 100, false);
    EquipmentsInStock.emplace_back("Scratched Ring", "Ring", 1, 50, 0, 0, 0, 4, 161, "Crit Chance! Yay!! 4 percent is surely gonna be huge, right?", 100, false);
    ConsumablesInStock.emplace_back();
}