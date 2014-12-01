//
//  System.h
//  Pickin' Sticks
//
//  Created by Alex on 11/30/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#ifndef __Pickin__Sticks__System__
#define __Pickin__Sticks__System__

#include <stdio.h>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class System{
public:
    int width;
    int height;
    int framerate;
    Uint32 flags;
    string title;
    RenderWindow window;
    void create(int width , int height , int framerate , string title);
    void create(int width , int height , int framerate , string title, Uint32 flags);
    System();
    
};
#endif /* defined(__Pickin__Sticks__System__) */
