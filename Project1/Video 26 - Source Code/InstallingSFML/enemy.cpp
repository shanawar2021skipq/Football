//
//  enemy.cpp
//  InstallingSFML
//
//  Created by Blank Blank on 2015-08-11.
//  Copyright (c) 2015 Blank Blank. All rights reserved.
//

#include "enemy.h"

enemy::enemy()
{
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(400, 200);
    rect.setFillColor(sf::Color::Blue);
    sprite.setTextureRect(sf::IntRect((spritex * counterWalking) + spritexStart, spritey * 0 + spriteyStart, spritex, spritey));
}

void enemy::update()
{
    sprite.setPosition(rect.getPosition());
    text.setPosition(rect.getPosition().x - rect.getSize().x/2, rect.getPosition().y - rect.getSize().y/2 - 5);
    
    if (isBlood == true)
    {
        bloodCounter++;
        
        if (bloodCounter >= bloodLifetime)
        {
            alive = false;
        }
    }
}

void enemy::updateMovement()
{
    if (direction == 1) // Up
    {
        if (canMoveUp == true)
        {
            rect.move(0,-movementSpeed);
            sprite.setTextureRect(sf::IntRect((spritex * counterWalking) + spritexStart, spritey * 3 + spriteyStart, spritex, spritey));
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else if (direction == 2) // Down
    {
        if (canMoveDown == true)
        {
            rect.move(0,movementSpeed);
            sprite.setTextureRect(sf::IntRect((spritex * counterWalking) + spritexStart, spritey * 0 + spriteyStart, spritex, spritey));
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else if (direction == 3) // Left
    {
        if (canMoveLeft == true)
        {
            rect.move(-movementSpeed,0);
            sprite.setTextureRect(sf::IntRect((spritex * counterWalking) + spritexStart, spritey * 1 + spriteyStart, spritex, spritey));
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else if (direction == 4) // Right
    {
        if (canMoveRight == true)
        {
            rect.move(movementSpeed,0);
            sprite.setTextureRect(sf::IntRect((spritex * counterWalking) + spritexStart, spritey * 2 + spriteyStart, spritex, spritey));
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else
    {
        // No movement
    }
    
    counterWalking++;
    if (counterWalking == 2)
    {
        counterWalking = 0;
    }
    
    if (aggroed != true)
    {
        counter++;
        if (counter >= movementLength)
        {
            direction = generateRandom(10);
            counter = 0;
        }
    }
    
}


void enemy::isUnwrappedMummyGoblin(int counter, int counter2, float x, float y)
{
    hp = 5; maxhp = 5;
    attackDamage = 1;
    spritexStart = 32 * 0;
    spriteyStart = 32 * 0;
    rect.setPosition((counter * 50) + 50 + x, (counter2 * 50) + 50 + y);
}

void enemy::isGoblin(int counter, int counter2, float x, float y)
{
    hp = 3; maxhp = 3;
    attackDamage = 2;
    spritexStart = 32 * 3;
    spriteyStart = 32 * 0;
    rect.setPosition((counter * 50) + 50 + x, (counter2 * 50) + 50 + y);
}

void enemy::isArmouredGoblin(int counter, int counter2, float x, float y)
{
    hp = 25; maxhp = 25;
    attackDamage = 5;
    spritexStart = 32 * 6;
    spriteyStart = 32 * 0;
    rect.setPosition((counter * 50) + 50 + x, (counter2 * 50) + 50 + y);
}

void enemy::isRobedGoblin(int counter, int counter2, float x, float y)
{
    hp = 6; maxhp = 6;
    attackDamage = 3;
    spritexStart = 32 * 0;
    spriteyStart = 32 * 4;
    rect.setPosition((counter * 50) + 50 + x, (counter2 * 50) + 50 + y);
}

void enemy::isLeaderGoblin(int counter, int counter2, float x, float y)
{
    hp = 50; maxhp = 50;
    attackDamage = 10;
    spritexStart = 32 * 3;
    spriteyStart = 32 * 4;
    rect.setPosition((counter * 50) + 50 + x, (counter2 * 50) + 50 + y);
}

void enemy::isWrappedMummyGoblin(int counter, int counter2, float x, float y)
{
    hp = 10; maxhp = 10;
    attackDamage = 3;
    spritexStart = 32 * 6;
    spriteyStart = 32 * 4;
    rect.setPosition((counter * 50) + 50 + x, (counter2 * 50) + 50 + y);
}
