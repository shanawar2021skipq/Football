//
//  textDisplay.cpp
//  InstallingSFML
//
//  Created by Blank Blank on 2015-08-12.
//  Copyright (c) 2015 Blank Blank. All rights reserved.
//

#include "textDisplay.h"

textDisplay::textDisplay()
{
    text.setColor(sf::Color::Red);
    text.setCharacterSize(30);
    text.setString(myString);
}

void textDisplay::update()
{
    text.move(0,-movementSpeed);
    
    counter++;
    if (counter >= lifeTime)
    {
        destroy = true;
    }
}
