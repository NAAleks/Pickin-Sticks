//
//  GameOver.hpp
//  Pickin' Sticks
//
//  Created by Alex on 5/23/16.
//  Copyright © 2016 Alex. All rights reserved.
//

#ifndef GameOver_hpp
#define GameOver_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class GameOver{
public:
    Texture Screen;
    Sprite SS;
    Font f;
    Text HighScore;
    Text YourScore; 
    void run(RenderWindow &win,int s,int hs);
    bool init(String imgPath);
    
    
    
};


#endif /* GameOver_hpp */
