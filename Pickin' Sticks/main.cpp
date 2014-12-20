#include "Game.h"

#include "ResourcePath.hpp"

int main(int, char const**)
{
    Game game("Pickin' Sticks");
    if(!game.Init()){
        cout << "Error While Initiliizing the Game :( " << endl;
        return 0;
    }
    
    game.run();
    

    return 0;
}
