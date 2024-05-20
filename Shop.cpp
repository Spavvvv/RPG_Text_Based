#include "Shop.h"
#include "Item.h"
#include "Equipment.h"
#include "Consumable.h"


Shop::Shop() {
    EquipmentsInStock.emplace_back("Old Sword", "Weapon", 1, 50, 0, 0, 5, 0, 0, 101, "The most basic weapon for an adventurer, essential for early grind", 100, false);
    EquipmentsInStock.emplace_back("Old Armor", "Armor", 1, 50, 0, 25, 0, 0, 0, 121, "Gives you a tiny bit of HP. Bulk up soldier!", 100, false);
    EquipmentsInStock.emplace_back("Old Helmet", "Helmet", 1, 50, 0, 0, 0, 5, 0, 141, "Protects you from incoming damages, withstand more attacks from regular monsters", 100, false);
    EquipmentsInStock.emplace_back("Old Ring", "Ring", 1, 50, 0, 0, 0, 0, 4, 161, "Crit Chance! Yay!! 4 percent is surely gonna be huge, right?", 100, false);
    ConsumablesInStock.emplace_back("Small Health Potion", "Healing", 1, 3, 50, 0, 0, 0, 0, 181, "Heal a small amount of Health", 0);
    ConsumablesInStock.emplace_back("Large Health Potion", "Healing", 1, 6, 100, 0, 0, 0, 0, 182, "Heal a large amount of Health", 0);
    ConsumablesInStock.emplace_back("Attack Potion", "Boosting", 1, 15, 0, 0, 5, 0, 0, 201, "Boost 5 Attack for your next fight", 1);
    ConsumablesInStock.emplace_back("Defend Potion", "Boosting", 1, 15, 0, 0, 0, 5, 0, 202, "Boost 5 Defend for your next fight", 1);
    ConsumablesInStock.emplace_back("Crit Potion", "Boosting", 1, 15, 0, 0, 0, 0, 4, 203, "Boost 4 Critical Chance for your next fight", 1);
    ConsumablesInStock.emplace_back("Max Health Potion", "Boosting", 1, 15, 0, 25, 0, 0, 0, 204, "Boost 25 Max Health for your next fight", 1);
}

