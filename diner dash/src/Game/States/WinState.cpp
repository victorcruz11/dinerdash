#include "WinState.h"

WinState::WinState(){
    string text = "Restart";
    restartButton = new Button (ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64,50,"Restart");
}

void WinState::tick(){
    restartButton->tick();
    if(restartButton->wasPressed()){
        setNextState("Menu");
        setFinished(true);
    }
}

void WinState::render(){
    ofBackground(0);
    ofImage bgImage;
    bgImage.load("images/Win.jpg");
    ofSetColor(225);
    bgImage.draw(0,0, ofGetWidth(), ofGetHeight());
    restartButton->render();
    ofDrawBitmapString(w, ofGetWidth()/2 - w.length()*4, ofGetHeight()/2 + 100);
    ofDrawBitmapString(r, ofGetWidth()/2 - r.length()*4, ofGetHeight()/2 + 125);
}

void WinState::keyPressed(int key){}

void WinState::mousePressed(int x, int y, int button){
    restartButton->mousePressed(x,y);
}

void WinState::reset(){
    setFinished(false);
    setNextState("");
    restartButton->reset();
}