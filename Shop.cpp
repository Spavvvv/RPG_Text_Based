#include "Shop.h"
#include "Item.h"
#include "Equipment.h"
#include "Consumable.h"
#include "Player.h"


Shop::Shop() {
    EquipmentsInStock.emplace_back("Old Sword", "Weapon", 1, 50, 0, 0, 5, 0, 0, 101, "+5 Attack. The most basic weapon for an adventurer, essential for early grind", 100, false);
    EquipmentsInStock.emplace_back("Old Armor", "Armor", 1, 50, 0, 25, 0, 0, 0, 111, "+25 Max Health. Gives you a tiny bit of HP. Bulk up soldier!", 100, false);
    EquipmentsInStock.emplace_back("Old Helmet", "Helmet", 1, 50, 0, 0, 0, 5, 0, 121, "+5 Defend. Protects you from incoming damages, withstand more attacks from regular monsters", 100, false);
    EquipmentsInStock.emplace_back("Old Ring", "Ring", 1, 50, 0, 0, 0, 0, 4, 131, "+4 Crit Chance. Crit Chance! Yay!! 4 percent is surely gonna be huge, right?", 100, false);
    ConsumablesInStock.emplace_back("Small Health Potion", "Healing", 1, 3, 50, 0, 0, 0, 0, 140, "Heal a small amount of Health", 0);
    ConsumablesInStock.emplace_back("Large Health Potion", "Healing", 1, 6, 100, 0, 0, 0, 0, 170, "Heal a large amount of Health", 0);
    ConsumablesInStock.emplace_back("Attack Potion", "Boosting", 1, 15, 0, 0, 5, 0, 0, 200, "+5 Attack for your next fight", 1);
    ConsumablesInStock.emplace_back("Defend Potion", "Boosting", 1, 15, 0, 0, 0, 5, 0, 210, "+5 Defend for your next fight", 1);
    ConsumablesInStock.emplace_back("Crit Potion", "Boosting", 1, 15, 0, 0, 0, 0, 4, 220, "+4 Critical Chance for your next fight", 1);
    ConsumablesInStock.emplace_back("Max Health Potion", "Boosting", 1, 15, 0, 25, 0, 0, 0, 230, "+25 Max Health for your next fight", 1);
    ConsumablesInStock.emplace_back("Enhance Stone", "Enhance", 1, 15, 0, 0, 0, 0, 0, 240, "Boost the chance of successful enhancement", 0);
}

void Shop::Shopping(int* item, int* amount) {
    std::cout << "Welcome to the shop! Fancy any of these?" << std::endl;
    for (int i = 0; i < EquipmentsInStock.size(); i++) {
        std::cout << i + 1 << ". " << EquipmentsInStock[i]->getName() << std::endl << "Type: " << EquipmentsInStock[i]->getType() << std::endl << EquipmentsInStock[i]->getDescription() << std::endl << "Price: " << EquipmentsInStock[i]->getMoney() << std::endl;
    }
    for (int i = 0; i < ConsumablesInStock.size(); i++) {
        std::cout << i + 5 << ". " << ConsumablesInStock[i]->getName() << std::endl << "Type: " << ConsumablesInStock[i]->getType() << std::endl << ConsumablesInStock[i]->getDescription() << std::endl << "Price: " << ConsumablesInStock[i]->getMoney() << std::endl;
    }
    std::cout << "Type the number before the name of the item you want to buy." << std::endl;
    std::cin >> *item;
    std::cout << "How many of it do you want to buy?" << std::endl;
    std::cin >> *amount;
}
void Shop::Buy(Player* player, int* item, int* amount) {
    if (*item < 5) {
        for (int j = 0; j < *amount; j++) {
            player->setBag(EquipmentsInStock[*item - 1]);
        }
    }
    else if (*item >= 5) {
        for (int j = 0; j < *amount; j++) {
            player->setBag(ConsumablesInStock[*item - 5]);
        }
    }
}