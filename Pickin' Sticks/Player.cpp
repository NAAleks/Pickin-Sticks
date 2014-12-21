#include "Player.h"


bool Player::init(string SpriteSheetpath,int w,int h,int x, int y){
    if(!texture.loadFromFile(SpriteSheetpath)){
        cout << "Error while loading file from " << SpriteSheetpath << endl;
        return false;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(x,y,w,h));
    spriteWidth = w;
    spriteHeight = h;
    
    return true;
}
void Player::move(int x, int y,int direction, float speed){
    sprite.setPosition(sprite.getPosition().x + (x * speed),sprite.getPosition().y + (y * speed) );
    sprite.setTextureRect(IntRect(0,0 + spriteHeight * direction,spriteWidth,spriteHeight));
//    cout << "The Direction is " << direction << " And the sprite Y cordinate is " << 0 + (spriteHeight * direction) << endl;

}
void Player::update(RenderWindow &win){
   
    win.draw(sprite);
    
}
int Player::checkForCollision(RenderWindow &win,vector<Sprite> otherObjects){
    if(sprite.getPosition().x < 0){
        return 1;
    }
    
    
    
    return 0;
}
int Player::checkForCollision(RenderWindow &win){
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
    
//    cout << "Player X: " << sprite.getPosition().x + sprite.getTextureRect().width << " And Y: " <<sprite.getPosition().y << endl;
    
    if(sprite.getPosition().x < 0 && sprite.getPosition().y < 0){
        return 5;
    }
    else if(sprite.getPosition().x + spriteWidth >= win.getSize().x && sprite.getPosition().y < 0){
        return 6;
    }
    else if(sprite.getPosition().x < 0 && sprite.getPosition().y + spriteHeight  >= win.getSize().y){
        return 7;
    }
    else if(sprite.getPosition().x + spriteWidth  >= win.getSize().x && sprite.getPosition().y + spriteHeight  > win.getSize().y){
        return 8;
    }
    
    
    if(sprite.getPosition().x < 0){
        return 1;
    }else if(sprite.getPosition().x + sprite.getTextureRect().width  >= win.getSize().x){
        return 2;
    }else if(sprite.getPosition().y < 0){
        return 4;
    }else if(sprite.getPosition().y + sprite.getTextureRect().height  >= win.getSize().y){
        return 3;
    }
    
    
    
    return 0;
}