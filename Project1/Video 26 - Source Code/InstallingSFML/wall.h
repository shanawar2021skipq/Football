//
//  wall.h
//  InstallingSFML
//
//  Created by Blank Blank on 2015-08-12.
//  Copyright (c) 2015 Blank Blank. All rights reserved.
//

#ifndef __InstallingSFML__wall__
#define __InstallingSFML__wall__

#include "entity.h"

class wall: public entity
{
public:
    bool destructable = false;
    int hp = 50;
    bool destroy = false;

    wall();
    void update();
};


#endif /* defined(__InstallingSFML__wall__) */
