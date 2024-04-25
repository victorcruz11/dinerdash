#pragma once
#include "Client.h"
#include "Burger.h"

class Inspector : public Client {
public:
    Inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger);
    ~Inspector();
    void tick() override;
};