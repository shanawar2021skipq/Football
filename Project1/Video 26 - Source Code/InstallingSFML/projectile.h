//
//  projectile.h
//  InstallingSFML
//
//  Created by Blank Blank on 2015-08-11.
//  Copyright (c) 2015 Blank Blank. All rights reserved.
//

#ifndef __InstallingSFML__projectile__
#define __InstallingSFML__projectile__

#include "entity.h"

class projectile: public entity
{
public:
    int movementSpeed = 4;
    int attackDamage = 1;
    int lifeTime = 150;
    
    int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
    bool destroy = false;
    int counterLifetime = 0;
    int counterAnimation = 0;
    bool enemyProjectile = false;
    bool randomDirection = false;
    float randomx = 0;
    float randomy = 0;

    projectile();
    void update();
};


#endif /* defined(__InstallingSFML__projectile__) */
