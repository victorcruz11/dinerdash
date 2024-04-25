#pragma once
#include "MenuState.h"

MenuState::MenuState() {
	string text = "Start";
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Start");
}

void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
    ofBackground(0); // set the background color to black
    // load background image
    ofImage bgImage;
    bgImage.load("images/Burger.jpg");
	ofSetColor(225);
    bgImage.draw(0, 0, ofGetWidth(), ofGetHeight()); // draw image to cover the entire screen
    startButton->render();
    // draw strings in the center of the screen
    ofDrawBitmapString(s, ofGetWidth()/2 - s.length()*4, ofGetHeight()/2 + 100);
    ofDrawBitmapString(e, ofGetWidth()/2 - e.length()*4, ofGetHeight()/2 + 125);
	ofDrawBitmapString(u, ofGetWidth()/2 - u.length()*4, ofGetHeight()/2 + 150);

}



void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}