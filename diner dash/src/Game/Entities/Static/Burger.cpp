//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->pattyCount = 0;
    this->cheeseCount = 0;
    this->lettuceCount = 0;
    this->tomatoCount = 0;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);
}
void Burger::removeLastIngredient(){
    if(!ingredients.empty()){
        ingredients.pop_back();
    }
}

void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x-5,y-(counter * 10)+55,width*0.70,height*0.70);
        counter++;
    }
}

void Burger::clear(){
    ingredients.clear();
}

bool Burger::equals(Burger* other) {
    if (ingredients.size() != other->ingredients.size()) { //primero verifica si son del mismo tamaño
        return false;
    }
    int i = 0;
    int j = 0;
    bool foundTopBun = false;
    bool foundBottomBun = false;
    while (i < ingredients.size() && j < other->ingredients.size()) {
        Item* thisItem = ingredients[i];
        Item* otherItem = other->ingredients[j];
        if (thisItem->name == otherItem->name) { //si son iguales y son los top o bottom bun update que se encontraron
            if (thisItem->name == "topBun") {
                foundTopBun = true;
            } 
            else if (thisItem->name == "bottomBun") {
                foundBottomBun = true;
            }
            i++;
            j++;
        } 
        else if (thisItem->name == "topBun" && !foundTopBun) { //si no son iguales los dos items, pero es el top bun, update que se encontro
            foundTopBun = true;
            i++;
        } 
        else if (thisItem->name == "bottomBun" && !foundBottomBun) { // si no son iguales pero es el bottom bun update que se encontro
            foundBottomBun = true;
            i++;
        } 
        else {
            return false; // si no son iguales y no son buns, return false
        }
    }
    if (i < ingredients.size() || j < other->ingredients.size()) {
        return false;
    }
    return true; //si no se cumplio ninguno de los statements anteriores, entonces son iguales
}