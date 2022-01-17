//
//  projectile.cpp
//  InstallingSFML
//
//  Created by Blank Blank on 2015-08-11.
//  Copyright (c) 2015 Blank Blank. All rights reserved.
//

#include "projectile.h"
#include "random.h"

projectile::projectile()
{
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(0, 0);
    rect.setFillColor(sf::Color::Green);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void projectile::update()
{
    if (randomDirection == true)
    {
        rect.move(randomx,randomy);
        sprite.setTextureRect(sf::IntRect(counterAnimation * 32, 3 * 32, 32, 32));
    }
    else
    {
        if (direction == 1) // Up
        {
            rect.move(0, -movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterAnimation * 32, 3 * 32, 32, 32));
        }
        if (direction == 2) // Down
        {
            rect.move(0, movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterAnimation * 32, 0, 32, 32));
        }
        if (direction == 3) // Left
        {
            rect.move(-movementSpeed, 0);
            sprite.setTextureRect(sf::IntRect(counterAnimation * 32, 1 * 32, 32, 32));
        }
        if (direction == 4) // Right
        {
            rect.move(movementSpeed, 0);
            sprite.setTextureRect(sf::IntRect(counterAnimation * 32, 2 * 32, 32, 32));
        }
    }
    
    counterLifetime++;
    if (counterLifetime >= lifeTime)
    {
        destroy = true;
    }
    
    counterAnimation++;
    if (counterAnimation >= 2)
    {
        counterAnimation = 0;
    }
    
    // Sprite set at Rect
    sprite.setPosition(rect.getPosition());
}