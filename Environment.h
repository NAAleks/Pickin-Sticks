//
//  Environment.h
//  Pickin' Sticks
//
//  Created by Alex on 11/30/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#ifndef __Pickin__Sticks__Environment__
#define __Pickin__Sticks__Environment__

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class Enviroment{
public:
    bool load(string backgroundTexturePath,string fontPath,string StickTexturePath);
    void draw(RenderWindow &win);
    Enviroment();
    Sprite StickSprite;
    Text score;
    Font font;
private:
    Texture backgroundTexture;
    Sprite background;
    Texture StickTexture;
    
};
#endif /* defined(__Pickin__Sticks__Environment__) */
