#include "Player.h"


bool Player::init(string SpriteSheetpath,int w,int h,int x, int y){
    if(!texture.loadFromFile(SpriteSheetpath)){
        cout << "Error while loading file from " << SpriteSheetpath << endl;
        return false;
    }
    sprite.setTexture(texture);
    
    
    return true;
}
void Player::move(int x, int y){
    sprite.setPosition(sprite.getPosition().x + x,sprite.getPosition().y + y );
}
void Player::update(RenderWindow &win){
    
    win.draw(sprite);
    
}