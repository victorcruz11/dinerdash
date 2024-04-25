#pragma once

#include "BaseCounter.h"

class StoveCounter : public BaseCounter
{
private:
    int delay;
    int ticks;

    bool isItemCooking;
    bool isItemCooked;

public:
    StoveCounter(int x, int y, int width, int height, Item *item, ofImage sprite, int delay);
    void tick();
    void render();

    bool itemCooked();
    bool isCooking();
    void startCooking();
    void clear();
};
