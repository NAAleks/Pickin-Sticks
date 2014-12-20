//
//  GameStage.cpp
//  Pickin' Sticks
//
//  Created by Alex on 12/19/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#include "GameStage.h"


bool GameStage::init(string envBackgroundPath){
    if(!env.load(envBackgroundPath)){
        return false;
    }
    
    
    
    return true;
}