#include "Shop.h"
#include "Item.h"
#include "Equipment.h"
#include "Consumable.h"
#include "Player.h"


Shop::Shop() { // Generates all items
    //std::cout << EquipmentsInStock.capacity()
    Equipment* equipment_01 = new Equipment("Old_Sword", "Weapon", 1, 50, 0, 5, 0, 0, "+5_Attack", 101, 100);
    EquipmentsInStock.emplace_back(equipment_01);
    Equipment* equipment_02 = new Equipment("Old_Helmet", "Helmet", 1, 50, 0, 0, 5, 0, "+5_Defend. But old", 121, 100);
    EquipmentsInStock.emplace_back(equipment_02);
    Equipment* equipment_03 = new Equipment("Old_Ring", "Ring", 1, 50, 0, 0, 0, 4, "4_percent_is_gonna_be huge,_right?", 131, 100);
    EquipmentsInStock.emplace_back(equipment_03);


    Consumable* consumable_01 = new Consumable("Health_Potion", "Healing", 1, 3, 50, 0, 0, 0, "Heal", 140, 1);
    Consumable* consumable_02 = new Consumable("Large Health Potion", "Healing", 1, 6, 100, 0, 0, 0, "Heal a large amount of Health", 170, 1);
    Consumable* consumable_03 = new Consumable("Attack Potion", "Boosting", 1, 15, 0, 5, 0, 0, "+5 Attack for your next fight", 200, 1);
    Consumable* consumable_04 = new Consumable("Defend Potion", "Boosting", 1, 15, 0, 0, 5, 0, "+5 Defend for your next fight", 210, 1);
    Consumable* consumable_05 = new Consumable("Crit Potion", "Boosting", 1, 15, 0, 0, 0, 4, "+4 Critical Chance for your next fight", 220, 1);
    Consumable* consumable_06 = new Consumable("Health Potion", "Boosting", 1, 15, 25, 0, 0, 0, "+25 Max Health for your next fight", 230, 1);
    Consumable* consumable_07 = new Consumable("Enhance Stone", "Enhance", 1, 15, 0, 0, 0, 0, "Boost the chance of enhancement", 240, 1);


    EquipmentsInStock.emplace_back(equipment_01);
    EquipmentsInStock.emplace_back(equipment_02);
    EquipmentsInStock.emplace_back(equipment_03);
    ConsumablesInStock.emplace_back(consumable_01);
    ConsumablesInStock.emplace_back(consumable_02);
    ConsumablesInStock.emplace_back(consumable_03);
    ConsumablesInStock.emplace_back(consumable_04);
    ConsumablesInStock.emplace_back(consumable_05);
    ConsumablesInStock.emplace_back(consumable_06);
    ConsumablesInStock.emplace_back(consumable_07);


    /*EquipmentsInStock.emplace_back(new Equipment("Old Sword", "Weapon", 1, 50, 0, 5, 0, 0, "+5 Attack", 101, 100));
    EquipmentsInStock.emplace_back(new Equipment("Old Helmet", "Helmet", 1, 50, 0, 0, 5, 0, "+5 Defend. But old", 121, 100));
    EquipmentsInStock.emplace_back(new Equipment("Old Ring", "Ring", 1, 50, 0, 0, 0, 4, "4 percent is gonna be huge, right?", 131, 100));
    ConsumablesInStock.emplace_back(new Consumable("Small Health Potion", "Healing", 1, 3, 50, 0, 0, 0, "Heal a small amount of Health", 140, 0));
    ConsumablesInStock.emplace_back(new Consumable("Large Health Potion", "Healing", 1, 6, 100, 0, 0, 0, "Heal a large amount of Health", 170, 0));
    ConsumablesInStock.emplace_back(new Consumable("Attack Potion", "Boosting", 1, 15, 0, 5, 0, 0, "+5 Attack for your next fight", 200, 1));
    ConsumablesInStock.emplace_back(new Consumable("Defend Potion", "Boosting", 1, 15, 0, 0, 5, 0, "+5 Defend for your next fight", 210, 1));
    ConsumablesInStock.emplace_back(new Consumable("Crit Potion", "Boosting", 1, 15, 0, 0, 0, 4, "+4 Critical Chance for your next fight", 220, 1));
    ConsumablesInStock.emplace_back(new Consumable("Health Potion", "Boosting", 1, 15, 25, 0, 0, 0, "+25 Max Health for your next fight", 230, 1));
    ConsumablesInStock.emplace_back(new Consumable("Enhance Stone", "Enhance", 1, 15, 0, 0, 0, 0, "Boost the chance of enhancement", 240, 0));*/
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

Shop::~Shop() {
    if (EquipmentsInStock.empty() == false) {
        for (int i = 0; i < EquipmentsInStock.size(); i++) {
            delete EquipmentsInStock[i];
        }

        EquipmentsInStock.clear();
    }

    if (ConsumablesInStock.empty() == false) {
        for (int i = 0; i < ConsumablesInStock.size(); i++) {
            delete ConsumablesInStock[i];
        }

        ConsumablesInStock.clear();
    }

}