#ifndef __Pickin__Sticks__Player__
#define __Pickin__Sticks__Player__

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class Player{
public:
    bool init(string SpriteSheetpath,int w,int h,int x, int y);
    void move(int x,int y,int direction,float speed);
    void update(RenderWindow &win);
    int checkForCollision(RenderWindow &win,vector<Sprite> otherObjects);
    Sprite sprite;
    int checkForCollision(RenderWindow &win);
    int spriteWidth;
    int spriteHeight;
    int speed;
private:
    Texture texture;
    
    
};
#endif /* defined(__Pickin__Sticks__Player__) */
