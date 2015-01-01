//
//  System.cpp
//  Pickin' Sticks
//
//  Created by Alex on 11/30/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#include "System.h"
void System::create(int width , int height , int framerate , string title){
    width = width;
    height = height;
    framerate = framerate;
    title = title;
    window.create(VideoMode(width,height), title);
    
    
    
    
}
void System::create(int width , int height , int framerate , string title, Uint32 flags){
    width = width;
    height = height;
    framerate = framerate;
    title = title;
    flags = flags;
    window.create(VideoMode(width,height), title,flags);
}
System::System(){
    
}