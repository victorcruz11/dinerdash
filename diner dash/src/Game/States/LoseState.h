#pragma once
#include "State.h"
#include "Button.h"


class LoseState : public State {
    private:
    Button *restartButton;
    ofImage loser1;
    ofImage buttonRestart;
    ofSoundPlayer sound;

    public:
    void tick();
    void render();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    void reset();
    LoseState();
    
};