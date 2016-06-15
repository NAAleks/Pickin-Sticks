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
#include "Player.h"
using namespace sf;
using namespace std;
class Enviroment{
public:
    bool load(string backgroundTexturePath,string fontPath,string StickTexturePath,string obsPath);
    void draw(RenderWindow &win);
    void spawnAStick(int w, int h);
    Enviroment();
    Sprite StickSprite;
    Text scoreDisplay;
    Font font;
    int score;
    Sprite Osprite;
    void spawnObstricles(int w,int h,Player player,int count);
    vector<Sprite> obs;
    Texture Otexture; 
private:
    Texture backgroundTexture;
    Sprite background;
    Texture StickTexture;
    bool checkBoundries(Sprite a, Sprite b,int x, int y);
    
    
};
#endif /* defined(__Pickin__Sticks__Environment__) */
