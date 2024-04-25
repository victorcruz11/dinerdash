#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    delete burger;
}
void Client::render(){
    burger->render();
    ofSetColor (255,255,255);
    ofSetColor(255,255-redness,255-redness);
    sprite.draw(x, y, width, height);
    ofSetColor (255,255,255);
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    redness = redness + 0.06;
    burger->setY(y);
    if(patience == 0){
        isLeaving = true;
        left ++;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger, bool activated) {
    if (isLeaving){
        return 0;
        }
    if (this->burger->equals(burger)) {
        isLeaving = true;
        burger->clear();//borra el hamburger si es igual a uno de los clientes
        return 10; //añade $10 si se entrego
    } else if (nextClient != nullptr) {
        return nextClient->serve(burger);
    }
    if(activated){
        isServed=true;
        int totalPrice= (burger->getCheeseCount() *3) + (burger->getLettuceCount() * 2) + (burger->getPattyCount() * 4) + (burger->getTomatoCount() * 2) + 2;
    }
    burger->clear();//borra el hamburger si no se entrego
    return 0;//si no se entrego, no añadas $ al total
    
}