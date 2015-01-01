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
    bool loadFiles(string pathforthefont,string MenuTexturePath,string howToPlayImagePath);
    Sprite menuGFX;
    Texture menuTexture;
    Texture howToPlay;
    Sprite howToPlaySprite;
    Font font;
    Text options[MAX_NUMBER_OF_ITEMS];
    bool isActive;
    int selected;
    bool TutorialIsPresant;
    void moveUp();
    void moveDown();
};
#endif /* defined(__Pickin__Sticks__MainMenu__) */
