#include "Shop.h"
#include "Item.h"
#include "Equipment.h"
#include "Consumable.h"
#include "Player.h"


Shop::Shop() { // Generates all items
    EquipmentsInStock.emplace_back(new Equipment("Old Sword", "Weapon", 1, 50, 0, 5, 0, 0, "+5 Attack. The most basic weapon for an adventurer, essential for early grind", 101, 100));
    EquipmentsInStock.emplace_back(new Equipment("Old Armor", "Armor", 1, 50, 25, 0, 0, 0, "+25 Max Health. Gives you a tiny bit of HP. Bulk up soldier!", 111, 100));
    EquipmentsInStock.emplace_back(new Equipment("Old Helmet", "Helmet", 1, 50, 0, 0, 5, 0, "+5 Defend. Protects you from incoming damages, withstand more attacks from regular monsters", 121, 100));
    EquipmentsInStock.emplace_back(new Equipment("Old Ring", "Ring", 1, 50, 0, 0, 0, 4, "+4 Crit Chance. Crit Chance! Yay!! 4 percent is surely gonna be huge, right?", 131, 100));
    ConsumablesInStock.emplace_back(new Consumable("Small Health Potion", "Healing", 1, 3, 50, 0, 0, 0, "Heal a small amount of Health", 140, 0));
    ConsumablesInStock.emplace_back(new Consumable("Large Health Potion", "Healing", 1, 6, 100, 0, 0, 0, "Heal a large amount of Health", 170, 0));
    ConsumablesInStock.emplace_back(new Consumable("Attack Potion", "Boosting", 1, 15, 0, 5, 0, 0, "+5 Attack for your next fight", 200, 1));
    ConsumablesInStock.emplace_back(new Consumable("Defend Potion", "Boosting", 1, 15, 0, 0, 5, 0, "+5 Defend for your next fight", 210, 1));
    ConsumablesInStock.emplace_back(new Consumable("Crit Potion", "Boosting", 1, 15, 0, 0, 0, 4, "+4 Critical Chance for your next fight", 220, 1));
    ConsumablesInStock.emplace_back(new Consumable("Health Potion", "Boosting", 1, 15, 25, 0, 0, 0, "+25 Max Health for your next fight", 230, 1));
    ConsumablesInStock.emplace_back(new Consumable("Enhance Stone", "Enhance", 1, 15, 0, 0, 0, 0, "Boost the chance of successful enhancement", 240, 0));
}

void Shop::shopping(Player* player) {
    int option;
    std::cout << "Welcome to the shop! Fancy any of these?" << std::endl;
    for (int i = 0; i < EquipmentsInStock.size(); i++) { // Shows all equipments
        std::cout << i + 1 << ". " << EquipmentsInStock[i]->getName() << std::endl << "Type: " << EquipmentsInStock[i]->getType() << std::endl << EquipmentsInStock[i]->getDescription() << std::endl << "Price: " << EquipmentsInStock[i]->getMoney() << std::endl;
    }
    for (int i = 0; i < ConsumablesInStock.size(); i++) { // Shows all consumables
        std::cout << i + 5 << ". " << ConsumablesInStock[i]->getName() << std::endl << "Type: " << ConsumablesInStock[i]->getType() << std::endl << ConsumablesInStock[i]->getDescription() << std::endl << "Price: " << ConsumablesInStock[i]->getMoney() << std::endl;
    }
    std::cout << "Your money: " << player->getMoney() << std::endl;
    std::cout << "1. Buy something" << std::endl << "2. Exit" << std::endl;
    std::cin >> option;
    if (option == 1) buy(player);
}
void Shop::buy(Player* player) {
    int item, amount;
    std::cout << "Type the number before the name of the item you want to buy." << std::endl; //
    std::cin >> item;
    std::cout << "How many of it do you want to buy?" << std::endl;
    std::cin >> amount;
    if (item < 5) {
        for (int j = 0; j < amount; j++) {
            player->setBag(EquipmentsInStock[item - 1]);
        }
    }
    else if (item >= 5) {
        for (int j = 0; j < amount; j++) {
            player->setBag(ConsumablesInStock[item - 5]);
        }
    }
    shopping(player);
}