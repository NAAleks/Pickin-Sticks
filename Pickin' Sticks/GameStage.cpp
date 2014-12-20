

#include "GameStage.h"


bool GameStage::init(string envBackgroundPath,string envFontPath,string envStickTexturePath, string PlayerSpritePath){
    if(!env.load(envBackgroundPath,envFontPath,envStickTexturePath)){
        cout << "Failed to load File form " << envBackgroundPath << endl;
        return false;
    }
    if(!player.init(PlayerSpritePath, 32, 48, 0, 0)){
        return false;
    }
    
    
    
    return true;
}
void GameStage::run(RenderWindow &win, Event &event){
    isActive = true;
    int xmovement = 0;
    int ymovement = 0;
    while (isActive) {
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
                case Event::Closed:
                    isActive = false;
                    win.close();
                    break;
                default:
                    break;
            }
            
            
        }
        //Controll Check
        if(Keyboard::isKeyPressed(Keyboard::Up)){
            ymovement--;
            cout << "Moving" << endl;
        }else  if(Keyboard::isKeyPressed(Keyboard::Down)){
            ymovement++;
            cout << "Moving" << endl;

        }
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            xmovement++;
            cout << "Moving" << endl;

        }else  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            xmovement--;
            cout << "Moving" << endl;

        }
        
        
        
        win.clear();
        env.draw(win);
        player.update(win);
        player.move(xmovement, ymovement);
        win.display();
        
    }
    
    
}
