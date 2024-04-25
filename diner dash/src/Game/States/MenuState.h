#pragma once

#include "State.h"
#include "Button.h"

class MenuState : public State {
private:
	ofImage img1;
	Button *startButton;
	string s = "Pickup ingredients by pressing 'e'";
	string e = "Serve clients by pressing 's'";
	string u = "To remove the last added ingredient press 'u'";

public:
	MenuState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
