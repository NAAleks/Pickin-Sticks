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
    
    sys.create(600,500,60,name,Style::Close);
    if(!env.load(resourcePath() + "back.png")){
        return false;
    }
    if(!Menu.loadFiles(resourcePath() + "arial.ttf",  resourcePath() + "MenuBackGround.png")){
        return false;
    }
    return true;
}
void Game::run(){
    
    while(sys.window.isOpen()){
        while(sys.window.pollEvent(event)){
            switch (event.type){
                case Event::Closed:
                    sys.window.close();
                    break;
                case Event::KeyPressed:
                    if(event.key.code == Keyboard::Key::Down){
                    Menu.moveDown();
                    }else  if(event.key.code == Keyboard::Key::Up){
                        Menu.moveUp();
                    }
                    
                    break;
                default:
                    
                    break;
                    
            }
        
        
        
        }
        
        
        
        sys.window.clear();
        
        env.draw(sys.window);
        Menu.draw(sys.window);
        sys.window.display();
    }
}