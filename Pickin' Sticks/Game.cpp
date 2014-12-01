//
//  Game.cpp
//  Pickin' Sticks
//
//  Created by Alex on 11/30/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#include "Game.h"
#include "ResourcePath.hpp"
#include "System.h"
Game::Game(string name){
    name = name;
    
    
    
}
bool Game::Init() {
    
    sys.create(700,600,60,name,Style::Close);
    env.load(resourcePath() + "back.png");
    
    return true;
}
void Game::run(){
    
    while(sys.window.isOpen()){
        while(sys.window.pollEvent(event)){
            switch (event.type){
                case Event::Closed:
                    sys.window.close();
                    break;
                default:
                    
                    break;
                    
            }
        
        
        
        }
        
        
        
        sys.window.clear();
        
        env.draw(sys.window);
        
        sys.window.display();
    }
}