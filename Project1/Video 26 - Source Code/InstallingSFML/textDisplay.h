//
//  textDisplay.h
//  InstallingSFML
//
//  Created by Blank Blank on 2015-08-12.
//  Copyright (c) 2015 Blank Blank. All rights reserved.
//

#ifndef __InstallingSFML__textDisplay__
#define __InstallingSFML__textDisplay__

#include "entity.h"

class textDisplay: public entity
{
public:
    float movementSpeed = 2;
    string myString = "Default";
    int counter = 0;
    int lifeTime = 100;
    bool destroy = false;
    
    textDisplay();
    void update();
    //void updateMovement();
};

#endif /* defined(__InstallingSFML__textDisplay__) */
