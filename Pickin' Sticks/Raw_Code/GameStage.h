

#ifndef __Pickin__Sticks__GameStage__
#define __Pickin__Sticks__GameStage__

#include <stdio.h>
#include "Environment.h"
#include "System.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;
using namespace std;
class GameStage{
public:
    bool init(string envBackgroundPath,string envFontPath,string envStickTexturePath, string PlayerSpritePath);
    void run(RenderWindow &win, Event &event);
    void pause(); // for future use if I add a pause menu  [Never Used this in the end because the MainMenu does act like a pause menu]
    void Exit();
    Enviroment env;
    bool isActive;
    Player player;
    Clock clock;
    Time deltaTime;
    Clock AnimationClock;
private:
    System sys;
    
};
#endif /* defined(__Pickin__Sticks__GameStage__) */
