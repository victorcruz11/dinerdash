//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "BaseCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"

class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0;
        std::vector<ofImage> people;
        int money =0;
        bool winState = false;
        bool served=false;

    public:
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        ofImage floor;
        ofImage table;
        ofImage chair1;
        ofImage chair2;
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void generateInspector();
        void serveClient();
        void tick();
        void render();
        void setup();
        void keyPressed(int key);
        int getMoney(){return money;}
};