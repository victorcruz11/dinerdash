#include "LoseState.h"

LoseState:: LoseState(){
    loser1.load("images/loser.png");
    buttonRestart.load("images/restart.png");
    sound.load("failSound.wav");
    sound.play();
    buttonRestart.crop(130,124,596,582);
    restartButton = new Button(ofGetWidth()* 0.5 - 64, ofGetHeight() / 2 + 112, 120, 200, buttonRestart);

    
}

void LoseState::tick() {
    restartButton->tick();
    if(restartButton->wasPressed()){
        setNextState("Menu");
        setFinished(true);
    }
}

void LoseState::render() {
    ofSetColor(255);
    loser1.draw(0,0,ofGetWidth(),ofGetHeight());
    if ((ofGetMouseX() >= restartButton->getX() && ofGetMouseY() >= restartButton->getY()) && (ofGetMouseX() <= restartButton->getX() + restartButton->getWidth() && ofGetMouseY() <= restartButton->getY() + restartButton->getHeight())){
        ofSetColor(187,18,193);
        restartButton->render();
    }
    else{
        ofSetColor(222,181,225);
        restartButton->render();
    }
}

void LoseState::mousePressed(int x, int y, int button){
    restartButton->mousePressed(x, y);
}

void LoseState::keyPressed(int key){

}
void LoseState::reset(){
    setFinished(false);
    setNextState("");
    restartButton->reset();
}