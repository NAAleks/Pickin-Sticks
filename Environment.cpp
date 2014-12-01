//
//  Environment.cpp
//  Pickin' Sticks
//
//  Created by Alex on 11/30/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#include "Environment.h"
Enviroment::Enviroment(){
    
}

bool Enviroment::load(string texturepath){
    if(!backgroundTexture.loadFromFile(texturepath)){
        cout << "Error While Loading the Texture from " << texturepath << endl << "EXITING" << endl;
        return false;
    }
    backgroundTexture.setRepeated(true);
    
    background.setTexture(backgroundTexture);
    
    return true;
}

void Enviroment::draw(RenderWindow &win){
    win.draw(background);
}