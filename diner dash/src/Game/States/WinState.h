#include "State.h"
#include "Button.h"

class WinState : public State {
    private:
        ofImage img1;
        Button *restartButton;
        string w = "YOU WIN!!";
        string r = "If you wish to restart the game, press the restart button.";
    public:
        WinState();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void reset();
}