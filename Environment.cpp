#include "Environment.h"
Enviroment::Enviroment(){
    
}

bool Enviroment:: load(string backgroundTexturePath,string fontPath,string StickTexturePath){
    if(!backgroundTexture.loadFromFile(backgroundTexturePath)){
        cout << "Error While Loading the Texture from " << backgroundTexturePath << endl << "EXITING" << endl;
        return false;
    }

    if(!font.loadFromFile(fontPath)){
        cout << "Error While Loading the Texture from " << fontPath << endl << "EXITING" << endl;
        return false;
    }
    if(!StickTexture.loadFromFile(StickTexturePath)){
        cout << "Error While Loading the Texture from " << StickTexturePath << endl << "EXITING" << endl;
        return false;
    }
    backgroundTexture.setRepeated(true);
    StickSprite.setPosition(100, 100);
    background.setTexture(backgroundTexture);
    StickSprite.setTexture(StickTexture);
    scoreDisplay.setString(&"Score:" [ score]);
    scoreDisplay.setFont(font);
    scoreDisplay.setScale(.5, .5);
    return true;
}
void Enviroment::spawnAStick(int w,int h){
    int xLimit = w - StickSprite.getGlobalBounds().width;
    int yLimit = h - StickSprite.getGlobalBounds().height;
    int x = rand() % xLimit;
    int y = rand() % yLimit;
    StickSprite.setPosition(x, y);
}
void Enviroment::draw(RenderWindow &win){
    scoreDisplay.setString("Score:" + to_string(score));
    win.draw(background);
    win.draw(StickSprite);
    win.draw(scoreDisplay);
}