//
// Created by joshu on 11/4/2020.
//
#pragma once

#include "Entity.h"
#include "Item.h"

class Burger {
  private:
    int x, y, width, height;
    vector<Item *> ingredients;
    int amount = 0;
    int counter = 1;
    int found=0;
    int pattyCount;
    int cheeseCount;
    int lettuceCount;
    int tomatoCount;

  public:
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    void removeLastIngredient();
    void render();
    void clear();
    bool equals(Burger* other);
    void setY(int y) {
        this->y = y;
    }
    void setX(int x){
        this->x = x;
    }
    stack<Item*> getIngredientsStack(){
        return ingredients;
    }
    int getPattyCount() {return pattyCount;}
    int getLettuceCount() {return lettuceCount;}
    int getCheeseCount() {return cheeseCount;}
    int getTomatoCount() {return tomatoCount;}
};
