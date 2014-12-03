//
//  MainMenu.h
//  Pickin' Sticks
//
//  Created by Alex on 12/1/14.
//

#ifndef __Pickin__Sticks__MainMenu__
#define __Pickin__Sticks__MainMenu__

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#define MAX_NUMBER_OF_ITEMS 3
class MainMenu{
public:
    void draw(RenderWindow &win);
    bool loadFiles(string pathforthefont,string MenuTexturePath);
    Sprite menuGFX;
    Texture menuTexture;
    Font font;
    Text options[MAX_NUMBER_OF_ITEMS];
    bool isActive;
    int selected;
    void moveUp();
    void moveDown();
    void select();
};
#endif /* defined(__Pickin__Sticks__MainMenu__) */
