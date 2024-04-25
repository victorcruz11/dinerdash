#include "Player.h"

Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em) : Entity(x, y, width, height, sprite){

    vector<ofImage> chefAnimframes;
    ofImage temp;
    this->burger = new Burger(ofGetWidth()-110, 100, 100, 50);
    temp.cropFrom(sprite, 30,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 159,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 287, 3,67,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 31,129,66,120);
    chefAnimframes.push_back(temp);
    this->chefAnim = new Animation(50, chefAnimframes);
    this->entityManager = em;
    
}
void Player::tick(){
chefAnim->tick();
    if(facing == "left"){
        x -= speed;
        if (x < 0) {
            x = 0;
        }
    } else if(facing == "right"){
        x += speed;
        if (x + width > ofGetWidth()) {
            x = ofGetWidth() - width;
        }
    }
}

void Player::render(){
    StoveCounter* sc = getActiveStoveCounter();
    BaseCounter *ac = getActiveCounter();
    if (ac != nullptr) {
        ac->showItem();
    }
    if (sc != nullptr) {
        stoveCounter = sc->getCounter();
        sc->cookPatty();
    }
    ofSetColor(256, 256, 256);
    ofImage currentFrame = chefAnim->getCurrentFrame();
    if (facing == "left") {
        currentFrame.mirror(false, true);
    }
    currentFrame.draw(x, y, width, height);
    burger->render();
}

void Player::keyPressed(int key){
    if(key == OF_KEY_LEFT){
        facing = "left";
    } else if (key == OF_KEY_RIGHT) {
        facing = "right";
    }
    if(key == 'e'){
        StoveCounter* sc = getActiveStoveCounter();
        BaseCounter* ac = getActiveCounter();
        if(ac != nullptr){
            Item* item = ac->getItem();
            if(dynamic_cast<BaseCounter*>(ac) != NULL && item != nullptr && item->name != "patty"){
                    burger->addIngredient(item);

            }
        }
        if(sc != nullptr){
            Item* item = sc->getItem();
            if(dynamic_cast<StoveCounter*>(sc) != NULL && item != nullptr){
                if(sc->getCounter() == 50)
                {
                    burger->addIngredient(item);
                    sc->setCounter(0);
            }
        }
    }
    else if(key == 'u'){
        burger->removeLastIngredient();
    }
}
BaseCounter* Player::getActiveCounter(){
    for(Entity* e:entityManager->entities){
        BaseCounter* c = dynamic_cast<BaseCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}

void Player::keyReleased(int key) {
    if(key == OF_KEY_LEFT || key == OF_KEY_RIGHT){
        facing = "";
    }
}
void Player::mousePressed(int x, int y, int button) {
}

void Player::setFacing(string facing){ this->facing = facing; }

StoveCounter* Player::getActiveStoveCounter(){
    for(Entity* e:entityManager->entities){
        StoveCounter* c = dynamic_cast<StoveCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}