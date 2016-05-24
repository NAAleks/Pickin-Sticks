//
//  GameOver.cpp
//  Pickin' Sticks
//
//  Created by Alex on 5/23/16.
//  Copyright © 2016 Alex. All rights reserved.
//

#include "GameOver.hpp"
#include <iostream>
#include "ResourcePath.hpp"

bool GameOver::init(String imgPath) {
    if(!Screen.loadFromFile(imgPath)){
        return false;
    }
    if(!f.loadFromFile(resourcePath() + "Arial.ttf")){
        cout << "Error Font" << endl;
        return false; 
    }
    SS.setTexture(Screen);
    
    
    
    
    return true;

}


void GameOver::run(RenderWindow &win,int h,int hs) {
    YourScore.setFont(f);
    HighScore.setFont(f);
    
    YourScore.setString("Your Score: " + to_string(h));
    HighScore.setString("High Score: " + to_string(hs));
    
    YourScore.setPosition(100, 70 );
    HighScore.setPosition(300, 70);
    YourScore.setColor(Color::White);
    HighScore.setColor(Color::White);
    Event e;
    while(true){
        win.pollEvent(e);
    win.clear();
        
        win.draw(SS);
        win.draw(YourScore);
        win.draw(HighScore);
    win.display();
        if(e.key.code == Keyboard::Key::Space){
            
            break;
            
        }
    }
    
    

}