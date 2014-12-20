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
    
    background.setTexture(backgroundTexture);
    
    return true;
}

void Enviroment::draw(RenderWindow &win){
    win.draw(background);
}