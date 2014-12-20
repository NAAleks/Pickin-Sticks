//
//  Game.cpp
//  Pickin' Sticks
//
//  Created by Alex on 11/30/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#include "Game.h"
#include "ResourcePath.hpp"

Game::Game(string name){
    name = name;
    
    
    
}
bool Game::Init() {
    
    sys.create(600,500,60,name,Style::Close);
    if(!Menu.loadFiles(resourcePath() + "arial.ttf",  resourcePath() + "MenuBackGround.png", resourcePath() + "HowToPlay.jpg")){
        return false;
    }
    if(!Stage.init(resourcePath() + "Back.png",resourcePath() + "Arial.ttf", resourcePath() + "stick.png", resourcePath() + "Player.png")){
        return false;

    }
    return true;
}
void Game::actionButtonPressed(){
//    cout << "Action Button Pressed" << endl;
    if(Menu.isActive){
        
        switch (Menu.selected) {
            case 0: //if Play is selected
                cout << "Running the Stage" << endl;
                Stage.run(sys.window,event);
                break;
            case 1: //if How to play is selected
                 Menu.TutorialIsPresant = true;
                while(Menu.TutorialIsPresant){
                    while (sys.window.pollEvent(event)){
                        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Key::Escape){
                            Menu.TutorialIsPresant = false;
                        }
                     sys.window.clear();
                    sys.window.draw(Menu.howToPlaySprite);
                    sys.window.display();
                    }
                }
                break;
            case 2: // if Exit is selected
                sys.window.close();
                break;
            default:
                cout << "Something Went Wrong with the Menu Item that you Selected" << endl;
                break;
        }
        
        

        
        
        
    }
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
//                        cout << "You Selected " << (string) Menu.options[Menu.selected].getString() << endl;
                    }else  if(event.key.code == Keyboard::Key::Up){
                        Menu.moveUp();
//                        cout << "You Selected " << (string) Menu.options[Menu.selected].getString() << endl;
                    }else if(event.key.code == Keyboard::Key::Space){
                        actionButtonPressed();
                    }
                    
                    break;
                default:
                    
                    break;
                    
            }
        
        
        
        }
        
        

        
        sys.window.clear();
        
        Menu.draw(sys.window);
        sys.window.display();
    }
}