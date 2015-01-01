//
//  MainMenu.cpp
//  Pickin' Sticks
//
//  Created by Alex on 12/1/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#include "MainMenu.h"
void MainMenu::draw(RenderWindow &win){
    win.draw(menuGFX);
    for(unsigned int i = 0; i < MAX_NUMBER_OF_ITEMS; i++ ){
        
        win.draw(options[i]);
    }
    
}

void MainMenu::moveUp(){
    if(selected > 0){
        options[selected].setColor(Color::White);
        selected--;
        options[selected].setColor(Color::Red);
    }else {
        options[selected].setColor(Color::White);
        selected = MAX_NUMBER_OF_ITEMS - 1;
        options[selected].setColor(Color::Red);
    }
    
}
void MainMenu::moveDown(){
    if(selected < MAX_NUMBER_OF_ITEMS - 1){
        options[selected].setColor(Color::White);
        selected++;
        options[selected].setColor(Color::Red);
    }else {
        options[selected].setColor(Color::White);
        selected = 0;
        options[selected].setColor(Color::Red);
    }
    
}



bool MainMenu::loadFiles(string pathforthefont,string MenuTexturePath,string howToPlayImagePath){
    if(!menuTexture.loadFromFile(MenuTexturePath)){
        cout << "Error While Loading the Menu Texture From Path " <<  MenuTexturePath << endl << "Exiting" << endl;
        return false;
    }
    if(!font.loadFromFile(pathforthefont)){
        cout << "Error while loadting the file " << pathforthefont << endl;
        return false;
    }
    if(!howToPlay.loadFromFile(howToPlayImagePath)){
        cout << "Error while loadting the file " << howToPlayImagePath << endl;
        return false;
    }
    menuGFX.setTexture(menuTexture);
    isActive = true;
    howToPlaySprite.setTexture(howToPlay);
    
    options[0].setFont(font);
    options[0].setString("Play");
    options[0].setColor(sf::Color::Red);
    options[0].setPosition(600/2 - options[0].getScale().x/2, 500/2 - options[0].getScale().y/2);
    
    options[1].setFont(font);
    options[1].setString("How to play");
    options[1].setColor(sf::Color::White);
    options[1].setPosition(600/2 - - options[0].getScale().x/2, (500/2 -  options[1].getScale().y)+ 50);
    
    options[2].setFont(font);
    options[2].setString("Exit");
    options[2].setColor(sf::Color::White);
    options[2].setPosition(600/2 - - options[0].getScale().x/2, (500/2 -  options[1].getScale().y)+ 100);
    
    selected = 0;
    
    
    
    return true;
}

