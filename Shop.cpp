#include "Shop.h"
#include "Item.h"
#include "Equipment.h"
#include "Consumable.h"
#include "Player.h"


Shop::Shop() { // Generates all items
    //std::cout << EquipmentsInStock.capacity()
    Equipment* equipment_01 = new Equipment("Old_Sword", "Weapon", 1, 50, 0, 5, 0, 0, "+5_Attack", 101, 100);
    Equipment* equipment_02 = new Equipment("Old_Helmet", "Helmet", 1, 50, 0, 0, 5, 0, "+5_Defend_But_old", 121, 100);
    Equipment* equipment_03 = new Equipment("Old_Ring", "Ring", 1, 50, 0, 0, 0, 4, "4_percent_is_gonna_be huge,_right?", 131, 100);
    Equipment* equipment_04 = new Equipment("Old_Armor", "Armor", 1, 50, 20, 0, 0, 0, "+20_Health", 131, 100);
    Consumable* consumable_01 = new Consumable("Health_Potion", "Healing", 1, 3, 50, 0, 0, 0, "Heal", 140, 1);
    Consumable* consumable_02 = new Consumable("Large_Health_Potion", "Healing", 1, 6, 100, 0, 0, 0, "Heal_a_large_amount_of_Health", 170, 1);
    Consumable* consumable_03 = new Consumable("Attack_Potion", "Boosting", 1, 15, 0, 5, 0, 0, "+5_Attack_for_your_next_fight", 200, 1);
    Consumable* consumable_04 = new Consumable("Defend_Potion", "Boosting", 1, 15, 0, 0, 5, 0, "+5_Defend_for_your_next_fight", 210, 1);
    Consumable* consumable_05 = new Consumable("Crit_Potion", "Boosting", 1, 15, 0, 0, 0, 4, "+4 Critical_Chance_for_your_next_fight", 220, 1);
    Consumable* consumable_06 = new Consumable("Health_Potion", "Boosting", 1, 15, 25, 0, 0, 0, "+25_Max_Health_for_your_next_fight", 230, 1);
    Consumable* consumable_07 = new Consumable("Enhance_Stone", "Enhance", 1, 15, 0, 0, 0, 0, "Boost_the_chance_of_enhancement", 240, 1);


    EquipmentsInStock.push_back(equipment_01);
    EquipmentsInStock.push_back(equipment_02);
    EquipmentsInStock.push_back(equipment_03);
    EquipmentsInStock.push_back(equipment_04);
    ConsumablesInStock.push_back(consumable_01);
    ConsumablesInStock.push_back(consumable_02);
    ConsumablesInStock.push_back(consumable_03);
    ConsumablesInStock.push_back(consumable_04);
    ConsumablesInStock.push_back(consumable_05);
    ConsumablesInStock.push_back(consumable_06);
    ConsumablesInStock.push_back(consumable_07);


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
        if (player->getMoney() - (EquipmentsInStock[item - 1]->getMoney()) * amount < 0) {
            std::cout << "Insufficient funds" << std::endl;
        }
        else {
            for (int j = 0; j < amount; j++) {
                player->setBag(EquipmentsInStock[item - 1]);
                player->setMoney(player->getMoney() - EquipmentsInStock[item - 1]->getMoney());
            }
        }
    }
    else if (item >= 5) {
        if (player->getMoney() - ConsumablesInStock[item - 5]->getMoney() < 0) {
            std::cout << "Insufficient funds" << std::endl;
        }
        else {
            for (int j = 0; j < amount; j++) {
                player->setBag(ConsumablesInStock[item - 5]);
                player->setMoney(player->getMoney() - ConsumablesInStock[item - 5]->getMoney());
            }
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