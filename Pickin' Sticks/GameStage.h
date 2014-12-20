//
//  GameStage.h
//  Pickin' Sticks
//
//  Created by Alex on 12/19/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#ifndef __Pickin__Sticks__GameStage__
#define __Pickin__Sticks__GameStage__

#include <stdio.h>
#include "Environment.h"
#include "System.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class GameStage{
public:
    bool init(string envBackgroundPath);
    void run();
    void pause(); // for future use if I add a pause menu
    void Exit();
    Enviroment env;
    
    
    
    
private:
    System sys;
    
};
#endif /* defined(__Pickin__Sticks__GameStage__) */
