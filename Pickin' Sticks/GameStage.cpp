

#include "GameStage.h"
#include <SFML/System.hpp>

bool GameStage::init(string envBackgroundPath,string envFontPath,string envStickTexturePath, string PlayerSpritePath){
    if(!env.load(envBackgroundPath,envFontPath,envStickTexturePath)){
        cout << "Failed to load File form " << envBackgroundPath << endl;
        return false;
    }
    if(!player.init(PlayerSpritePath, 32, 48, 0, 0)){
        cout << "Failed to load File form " << PlayerSpritePath << endl;
        return false;
    }
    
    
    
    return true;
}
void GameStage::run(RenderWindow &win, Event &event){
    isActive = true;
    int xmovement = 0;
    int ymovement = 0;
    int direction = 0;
    clock.restart().asMilliseconds();
    deltaTime = clock.restart();
    AnimationClock.restart();
    
    while (isActive) {
        if(deltaTime.asMilliseconds() >= 1000/60){
        xmovement = 0;
        
        ymovement = 0;
        while (win.pollEvent(event)) {
            switch (event.type) {
                case Event::KeyPressed:
                    switch (event.key.code) { // input Switch Statement
                        case Keyboard::Key::Escape:
                            isActive = false;
                            break;
                        default:
                            break;
                    }
                    break;
                case Event::KeyReleased:
                    player.xSprite = 1;
                    break;
                case Event::Closed:
                    isActive = false;
                    win.close();
                    break;
                default:
                    break;
            }
            
            
            
        }
        //Controll Check
        int playerCollision = player.checkForCollision(win);
//        cout << "Collidion number is " << playerCollision << endl;
        /*
         return value cheat sheet for Player::CheckFroCollision
         0 - no collision
         
         1 - something is colliding with the left side of the player   of the player
         
         2 - something is colliding with the right side of the player  of the player
         
         3 - something is colliding with the bottom side of the player of the player
         
         4 - something is colliding with the top side of the player    of the player
         
         5 - something is colliding with the top and the left side     of the player
         
         6 - something is colliding with the top and the right side    of the player
         
         7 - something is colliding with the bottom and the left side  of the player
         
         8 - something is colliding with the bottom and the right side of the player
         
         */
        if(Keyboard::isKeyPressed(Keyboard::Down) && playerCollision !=3 && playerCollision !=7 && playerCollision !=8){
            ymovement++;
            direction = 0;
            
        }else if(Keyboard::isKeyPressed(Keyboard::Up) && playerCollision !=4 && playerCollision !=5 && playerCollision !=6){
            ymovement--;
            direction = 1;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Right) && playerCollision !=2 && playerCollision !=6 && playerCollision !=8){
            xmovement++;
            direction = 3;
            
        }else  if(Keyboard::isKeyPressed(Keyboard::Left) && playerCollision !=1 && playerCollision !=5 && playerCollision !=7){
            xmovement--;
            direction = 2;
            
            
        }
            if(player.checkForCollisionWithObject(env.StickSprite)){
                env.spawnAStick(win.getSize().x,win.getSize().y);
                env.score++;
            }
        win.clear();
        env.draw(win);
        player.update(win);
       
        player.move(xmovement, ymovement,direction,2,AnimationClock,deltaTime,env.score);
        
        win.display();
        deltaTime = clock.restart();
        cout << "Delta Time is " << deltaTime.asMilliseconds() <<endl;
    }
        deltaTime = clock.getElapsedTime();
    }
    
    
}
