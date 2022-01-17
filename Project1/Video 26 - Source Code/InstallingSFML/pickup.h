//
//  pickup.h
//  InstallingSFML
//
//  Created by Blank Blank on 2015-08-12.
//  Copyright (c) 2015 Blank Blank. All rights reserved.
//

#ifndef __InstallingSFML__pickup__
#define __InstallingSFML__pickup__

#include "entity.h"

class pickup: public entity
{
public:
    bool isCoin = false;
    bool isPowerup = false;
    bool isNovaPowerup = false;
    bool isHPShield = false;
    bool isPotion = false;
    int coinValue = 5;
    bool destroy = false;
    bool inShop = false;
    int cost = 30;
    
    pickup();
    void update();
};

#endif /* defined(__InstallingSFML__pickup__) */
