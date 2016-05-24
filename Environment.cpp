#include "Environment.h"

Enviroment::Enviroment(){
    
}

bool Enviroment:: load(string backgroundTexturePath,string fontPath,string StickTexturePath,string obsPath){
    if(!backgroundTexture.loadFromFile(backgroundTexturePath)){
        cout << "Error While Loading the Texture from " << backgroundTexturePath << endl << "EXITING" << endl;
        return false;
    }
    if(!Otexture.loadFromFile(obsPath)){
        cout << "Error While Loading the Texture from " << obsPath << endl << "EXITING" << endl;
        return false;
    }
    if(!font.loadFromFile(fontPath)){
        cout << "Error While Loading the Texture from " << fontPath << endl << "EXITING" << endl;
        return false;
    }

    if(!StickTexture.loadFromFile(StickTexturePath)){
        cout << "Error While Loading the Texture from " << StickTexturePath << endl << "EXITING" << endl;
        return false;
    }
    // TODO:
    // Fix the issuse where the obsticale might be drown over the stick
    // Fix the issuse where the player's width and height should be taken into the account when generating the obsticale
    
    backgroundTexture.setRepeated(true);
    StickSprite.setPosition(100, 100);
    background.setTexture(backgroundTexture);
    StickSprite.setTexture(StickTexture);
    Osprite.setTexture(Otexture);
    Osprite.setScale(.08, .08);
    scoreDisplay.setString(&"Score:" [ score]);
    scoreDisplay.setFont(font);
    scoreDisplay.setScale(.5, .5);
    return true;
}
void Enviroment::spawnAStick(int w,int h){
    int xLimit = w - StickSprite.getGlobalBounds().width;
    int yLimit = h - StickSprite.getGlobalBounds().height;
    int x = rand() % xLimit;
    int y = rand() % yLimit;
    StickSprite.setPosition(x, y);
}
bool Enviroment::checkBoundries(Sprite a, Sprite b,int x, int y){
    

    if(a.getGlobalBounds().intersects(b.getGlobalBounds())){
        return true;
    }
    
    
    
    return false;
}
void Enviroment::spawnObstricles(int w,int h,Player player,int count){
    if (count > 20) {
        count = 20;
        
    }
    obs.clear();
    for (int i = 0; i < count; i++) {
    int xLimit = w - Osprite.getGlobalBounds().width;
    int yLimit = h - Osprite.getGlobalBounds().height;
    
    int x = rand() % xLimit;
        while (x > player.sprite.getPosition().x && x < player.sprite.getPosition().x + player.sprite.getGlobalBounds().width + 10 ){
           x = rand() % xLimit;
        }
    int y = rand() % yLimit;
        while (y > player.sprite.getPosition().y && y < player.sprite.getPosition().y + player.sprite.getGlobalBounds().width + 10 ){
            y = rand() % xLimit;
        }

     Osprite.setPosition(x, y);
    while( checkBoundries(player.sprite, Osprite, x, y) || checkBoundries(StickSprite, Osprite, x, y)){
        x = rand() % xLimit;
        y = rand() % yLimit;
        Osprite.setPosition(x, y);
    }
        
   
        
    obs.push_back(Osprite);
    }
    
}
void Enviroment::draw(RenderWindow &win){
    scoreDisplay.setString("Score:" + to_string(score));
    win.draw(background);
    win.draw(StickSprite);
    if(!obs.empty()){
    for (unsigned int i = 0; i < obs.size();i++){
        win.draw(obs.at(i));
    }
    }
    win.draw(scoreDisplay);
}