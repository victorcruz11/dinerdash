#include "Inspector.h"

Inspector::Inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger) : Client(x, y, width, height, sprite, burger) {
}

Inspector::~Inspector() {
}

void Inspector::tick() {
    patience--;
    redness = redness + 0.06;
    burger->setY(y);
    if (patience == 0) {
        isLeaving = true;
        left++;
        money = money / 2; // Deduct half of earnings for the bad review
    }
    if (nextClient != nullptr) {
        nextClient->tick();
    }
}
