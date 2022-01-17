//
//  player.cpp
//  InstallingSFML
//
//  Created by Blank Blank on 2015-08-11.
//  Copyright (c) 2015 Blank Blank. All rights reserved.
//

#include "player.h"

player::player()
{
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(400, 200);
    rect.setFillColor(sf::Color::Blue);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void player::update()
{
    sprite.setPosition(rect.getPosition());
}

void player::updateMovement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (canMoveUp == true)
        {
            rect.move(0,-movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 3, 32, 32));
            direction = 1;
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (canMoveDown == true)
        {
            rect.move(0,movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));
            direction = 2;
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (canMoveLeft == true)
        {
            rect.move(-movementSpeed,0);
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 1, 32, 32));
            direction = 3;
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (canMoveRight == true)
        {
            rect.move(movementSpeed,0);
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 2, 32, 32));
            direction = 4;
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else
    {
        // Player not Moving
    }
    
    counterWalking++;
    
    if (counterWalking == 2)
    {
        counterWalking = 0;
    }
}