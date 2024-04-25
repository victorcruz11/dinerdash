#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item *item, ofImage sprite, int delay) : BaseCounter(x, y, width, height, item, sprite)
{
    counterType = CounterTypes::Stove;
    this->delay = delay;
    ticks = 0;

    isItemCooking = false;
    isItemCooked = false;
}

void StoveCounter::tick()
{
    if (isItemCooking)
    {
        ticks++;
    }

    if (ticks == delay)
    {
        isItemCooking = false;
        isItemCooked = true;
    }
}

void StoveCounter::render()
{
    BaseCounter::render();

    if (isItemCooking)
    {
        float percent = (ticks / ((float)delay));
        float rectWidth = 76 * percent;
        ofSetColor(0, 0, 0);
        ofDrawRectangle(x + 10, y + height / 2, 76, 10);
        ofSetColor(0, 255, 0);
        ofDrawRectangle(x + 10, y + height / 2, rectWidth, 10);
        ofSetColor(255, 255, 255);
    }

    if (isItemCooked)
    {
        ofSetColor(0, 0, 255);
        ofDrawRectangle(x + 10, y + height / 2, 76, 10);
    }
}

bool StoveCounter::itemCooked()
{
    return isItemCooked;
}
bool StoveCounter::isCooking()
{
    return isItemCooking;
}
void StoveCounter::startCooking()
{
    isItemCooking = true;
    isItemCooked = false;
}
void StoveCounter::clear()
{
    isItemCooking = false;
    isItemCooked = false;
    ticks = 0;
}
