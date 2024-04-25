#include "Button.h"
Button::Button(){
   this->xPos = ofGetWidth()/2;
    this->yPos = ofGetHeight()/2;
    this->width = 64;
    this->height = 20; 
}
Button::Button(int xPos, int yPos, int width, int height, string buttonText){
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;
    this->buttonText = buttonText;
}
Button::Button(int xPos, int yPos, int width, int height, ofImage restart){
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;
    this->restart= restart;
}

void Button::reset(){
    pressedCounter = -1;
    pressed = false;
}
void Button::tick(){
    pressedCounter--;
    if(pressedCounter == 0){
        pressed = false;
        pressedCounter = -1;
    }

}

void Button::mousePressed(int x, int y){
    if(xPos + width >= x && x >= xPos &&  yPos + height >= y && y >= yPos){
        pressed = true;
        pressedCounter = 10;
    }
}

void Button::render(){
    restart.draw(ofGetWidth()/2-32, ofGetHeight()/2+128,64,64);
}

bool Button::wasPressed(){
    return pressed;
}
int Button::getX(){
    return xPos;
}
int Button::getY(){
    return yPos;
}
float Button::getWidth(){
    return width;
}
float Button::getHeight(){
    return height;
}