#include"Item.h"
#include"Consumable.h"
#include<iostream>
#include<string>

//Init
Consumable::Consumable() : Item(int newID) {
    this->quantity = 0;
    this->duration = 0;
}
//Getter
int Consumable::getQuantity() {
    return quantity;
}
int Consumable::getDuration() {
    return duration;
}
//Setter
void Consumable::setQuantity(int newQuantity) {
    this->quantity = newQuantity;
}
void Consumable::setDuration(int newDuration) {
    this->duration = newDuration;
}
//Others
void Consumable::use() {
    setQuantity(quantity - 1);
}