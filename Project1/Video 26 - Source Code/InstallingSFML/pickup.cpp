//
//  pickup.cpp
//  InstallingSFML
//
//  Created by Blank Blank on 2015-08-12.
//  Copyright (c) 2015 Blank Blank. All rights reserved.
//

#include "pickup.h"

pickup::pickup()
{
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(0, 0);
    rect.setFillColor(sf::Color::Yellow);
    //sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void pickup::update()
{
    sprite.setPosition(rect.getPosition());
    text.setPosition(rect.getPosition().x - 25, rect.getPosition().y - 30);
}
