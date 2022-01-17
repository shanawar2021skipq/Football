//
//  wall.cpp
//  InstallingSFML
//
//  Created by Blank Blank on 2015-08-12.
//  Copyright (c) 2015 Blank Blank. All rights reserved.
//

#include "wall.h"

wall::wall()
{
    rect.setSize(sf::Vector2f(50, 50));
    rect.setPosition(0, 0);
    rect.setFillColor(sf::Color::White);
    //sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void wall::update()
{
    sprite.setPosition(rect.getPosition());
}
