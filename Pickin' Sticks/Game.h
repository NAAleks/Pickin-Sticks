//
//  Game.h
//  Pickin' Sticks
//
//  Created by Alex on 11/30/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#ifndef __Pickin__Sticks__Game__
#define __Pickin__Sticks__Game__

#include <stdio.h>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "System.h"
#include "MainMenu.h"
#include "Environment.h"
using namespace std;
using namespace sf;
class Game{
public:
    Game(string name);
    string name;
    bool Init();
    void run();
    System sys;
    Event event;
    Enviroment env;
    MainMenu Menu;
    
};

#endif /* defined(__Pickin__Sticks__Game__) */
