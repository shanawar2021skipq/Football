
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
#include <iostream>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

#include "random.h"
#include "player.h"
#include "entity.h"
#include "projectile.h"
#include "enemy.h"
#include "textDisplay.h"
#include "pickup.h"
#include "wall.h"

int main(int, char const**)
{
    // Variables
    srand(time(NULL));
    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;
    float playerMovementSpeed = 2;
    int counterWalking = 0;
    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 800), "I want to learn SFML! W00tsaurs");
    window.setFramerateLimit(60);
    
    // View
    sf::View view1(sf::FloatRect(200, 200, 300, 200));
    view1.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    view1.setCenter(sf::Vector2f(view1.getSize().x/2, view1.getSize().y/2));
    window.setView(view1);
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture textureLion;
    if (!textureLion.loadFromFile(resourcePath() + "lion.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteLion(textureLion);
    spriteLion.setPosition(500, 500);
    
    sf::Texture textureEnemy;
    if (!textureEnemy.loadFromFile(resourcePath() + "enemySpriteSheet.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Texture textureCoin;
    if (!textureCoin.loadFromFile(resourcePath() + "coin.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Texture texturePowerup;
    if (!texturePowerup.loadFromFile(resourcePath() + "powerup.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Texture textureFireBall;
    if (!textureFireBall.loadFromFile(resourcePath() + "fireball.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Texture textureBlood;
    if (!textureBlood.loadFromFile(resourcePath() + "blood.gif")) {
        return EXIT_FAILURE;
    }
    
    sf::Texture textureCrate;
    if (!textureCrate.loadFromFile(resourcePath() + "Crate_001.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Texture textureWall;
    if (!textureWall.loadFromFile(resourcePath() + "Back_002.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Texture textureItems;
    if (!textureItems.loadFromFile(resourcePath() + "weapons.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Texture textureEnemySprite;
    if (!textureEnemySprite.loadFromFile(resourcePath() + "enemySprite.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Texture textureGround;
    if (!textureGround.loadFromFile(resourcePath() + "tile.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Texture texturePotion;
    if (!texturePotion.loadFromFile(resourcePath() + "potion.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Texture textureFood;
    if (!textureFood.loadFromFile(resourcePath() + "food.png")) {
        return EXIT_FAILURE;
    }
    
    // Load a sprite to display
    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile(resourcePath() + "spriteWalk.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spritePlayer(texturePlayer);
    spritePlayer.setPosition(window.getSize().x/2, window.getSize().y/2);
    spritePlayer.setTextureRect(sf::IntRect(0, 0, 32, 32));
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "pixel.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Gil: ", font, 25);
    text.setColor(sf::Color::Yellow);
    text.setPosition(0, 0);
    
    // Player HP Text
    sf::Text textHP("HP: ", font, 25);
    textHP.setColor(sf::Color::Green);
    textHP.setPosition(0, 0);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "music.ogg")) {
        return EXIT_FAILURE;
    }
    
    // Play the music
    music.play();
    music.setLoop(true);

    // Sound effects
    sf::SoundBuffer bufferShot;
    if (!bufferShot.loadFromFile(resourcePath() + "shot.ogg"))
        return -1;
    sf::Sound soundShot;
    soundShot.setBuffer(bufferShot);
    
    sf::SoundBuffer bufferCollision;
    if (!bufferCollision.loadFromFile(resourcePath() + "collision.ogg"))
        return -1;
    sf::Sound soundCollision;
    soundCollision.setBuffer(bufferCollision);
    
    sf::SoundBuffer bufferPlayerDamaged;
    if (!bufferPlayerDamaged.loadFromFile(resourcePath() + "playerhit.ogg"))
        return -1;
    sf::Sound soundPlayerDamaged;
    soundPlayerDamaged.setBuffer(bufferPlayerDamaged);
    
    sf::SoundBuffer bufferCoin;
    if (!bufferCoin.loadFromFile(resourcePath() + "coin.wav"))
        return -1;
    sf::Sound soundCoin;
    soundCoin.setBuffer(bufferCoin);
    
    // Class Object
    class player Player1;
    Player1.sprite.setTexture(texturePlayer);
    
    
    // Projectile Vector Array
    vector<projectile>::const_iterator iter;
    vector<projectile> projectileArray;
    
    // Projectile Object
    class projectile projectile1;
    projectile1.sprite.setTexture(textureFireBall);
    
    
    // Enemy Vector Array
    vector<enemy>::const_iterator iter4;
    vector<enemy> enemyArray;
    
    // Enemy Object
    class enemy enemy1;
    enemy1.sprite.setTexture(textureEnemySprite);
    enemy1.text.setFont(font);
    enemy1.text.setCharacterSize(17);
    enemy1.text.setColor(sf::Color::Red);
    //enemy1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    
    enemy1.rect.setPosition(600, 200);
    //enemyArray.push_back(enemy1);
    
    
    
    // Blood Vector Array
    vector<enemy>::const_iterator iter20;
    vector<enemy> bloodArray;
    
    // Blood Object
    class enemy blood1;
    blood1.isBlood = true;
    blood1.sprite.setTexture(textureBlood);
    blood1.sprite.setTextureRect(sf::IntRect(32 * 5, 0, 32, 32));
    blood1.rect.setPosition(300, 300);
    //bloodArray.push_back(blood1);
    
    
    
    // Text Vector Array
    vector<textDisplay>::const_iterator iter8;
    vector<textDisplay> textDisplayArray;
    
    // Text Display Object
    class textDisplay textDisplay1;
    textDisplay1.text.setFont(font);
    
    // Wall Vector Array
    vector<wall>::const_iterator iter15;
    vector<wall> wallArray;
    
    class wall wall1;
    wall1.rect.setPosition(100, 100);
    wall1.sprite.setScale(0.2,0.2);
    //wallArray.push_back(wall1);
    
    int roomSize = generateRandom(10) + 3;
    int verticalDoorLocationRight = 0;
    int verticalDoorLocationLeft = 0;
    int horizontalDoorLocationUp = 0;
    int horizontalDoorLocationDown = 0;
    int roomStartX = 0;
    int roomStartY = 0;
    
    // Pickup Vector Array
    vector<pickup>::const_iterator iter11;
    vector<pickup> pickupArray;
    
    // Coin Object
    class pickup pickup1;
    pickup1.sprite.setTexture(textureCoin);
    pickup1.text.setFont(font);
    pickup1.text.setCharacterSize(17);
    pickup1.text.setColor(sf::Color::Green);
    pickup1.rect.setPosition(500, 500);
    pickup1.rect.setSize(sf::Vector2f(32, 32));
    //pickupArray.push_back(pickup1);
    
    // Ground Vector Array
    vector<wall>::const_iterator iter25;
    vector<wall> groundArray;
    
    class wall ground1;
    ground1.sprite.setTexture(textureGround);
    ground1.sprite.setTextureRect(sf::IntRect(25,25,50,50));
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // Custom Room 1st
    roomSize = 5;
    verticalDoorLocationRight = 3;
    verticalDoorLocationLeft = 100;
    horizontalDoorLocationUp = 100;
    horizontalDoorLocationDown = 100;
    roomStartX = 0;
    roomStartY = 0;
    wall1.destructable = false; // Can be destroyed
    wall1.sprite.setTexture(textureWall);
    
    // Lay Floor Tiles
    ground1.sprite.setTextureRect(sf::IntRect(425,100,50,50));
    counter = 0;
    while (counter <= roomSize)
    {
        counter2 = 0;
        while (counter2 <= roomSize)
        {
            ground1.sprite.setPosition(50 * counter + roomStartX, 50 * counter2 + roomStartY);
            groundArray.push_back(ground1);
            
            counter2++;
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationUp)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationDown)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != verticalDoorLocationLeft)
        {
            wall1.rect.setPosition(0 + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize+1)
    {
        if (counter != verticalDoorLocationRight)
        {
            wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    
    // Random Stuff in Room
    wall1.sprite.setTexture(textureCrate);
    counter = 0;
    while (counter < (roomSize - 1))
    {
        counter2 = 0;
        while (counter2 < (roomSize - 1))
        {
            int tempRandom = generateRandom(40);
            if (tempRandom == 1)
            {
                // Destructable Boxes
                wall1.destructable = true; // Can be destroyed
                wall1.rect.setFillColor(sf::Color::Yellow);
                wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
                wallArray.push_back(wall1);
                wall1.destructable = false;
                wall1.rect.setFillColor(sf::Color::White);
            }
            if (tempRandom == 2)
            {
                // Mummy Enemy
                enemy1.isUnwrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 3)
            {
                // Goblin Enemy
                enemy1.isGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 4)
            {
                // Armoured Goblin Enemy
                enemy1.isArmouredGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 5)
            {
                // Robed Goblin Enemy
                enemy1.isRobedGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 6)
            {
                // Leader Goblin Enemy
                enemy1.isLeaderGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 7)
            {
                // Wrapped Mummy Goblin Enemy
                enemy1.isWrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            
            counter2++;
        }
        
        counter++;
    }
    
    
    
    
    
    
    // Custom Room 2nd
    roomSize = 10;
    verticalDoorLocationRight = 3;
    verticalDoorLocationLeft = 3;
    horizontalDoorLocationUp = 5;
    horizontalDoorLocationDown = 5;
    roomStartX = 5 * 50;
    roomStartY = 0;
    wall1.destructable = false; // Can be destroyed
    wall1.sprite.setTexture(textureWall);
    
    // Lay Floor Tiles
    ground1.sprite.setTextureRect(sf::IntRect(425,100,50,50));
    counter = 0;
    while (counter <= roomSize)
    {
        counter2 = 0;
        while (counter2 <= roomSize)
        {
            ground1.sprite.setPosition(50 * counter + roomStartX, 50 * counter2 + roomStartY);
            groundArray.push_back(ground1);
            
            counter2++;
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationUp)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationDown)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != verticalDoorLocationLeft)
        {
            wall1.rect.setPosition(0 + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize+1)
    {
        if (counter != verticalDoorLocationRight)
        {
            wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Random Stuff in Room
    wall1.sprite.setTexture(textureCrate);
    counter = 0;
    while (counter < (roomSize - 1))
    {
        counter2 = 0;
        while (counter2 < (roomSize - 1))
        {
            int tempRandom = generateRandom(40);
            if (tempRandom == 1)
            {
                // Destructable Boxes
                wall1.destructable = true; // Can be destroyed
                wall1.rect.setFillColor(sf::Color::Yellow);
                wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
                wallArray.push_back(wall1);
                wall1.destructable = false;
                wall1.rect.setFillColor(sf::Color::White);
            }
            if (tempRandom == 2)
            {
                // Mummy Enemy
                enemy1.isUnwrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 3)
            {
                // Goblin Enemy
                enemy1.isGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 4)
            {
                // Armoured Goblin Enemy
                enemy1.isArmouredGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 5)
            {
                // Robed Goblin Enemy
                enemy1.isRobedGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 6)
            {
                // Leader Goblin Enemy
                enemy1.isLeaderGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 7)
            {
                // Wrapped Mummy Goblin Enemy
                enemy1.isWrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }

            
            counter2++;
        }
        
        counter++;
    }
    
    
    
    
    // Custom Room 3rd
    roomSize = 6;
    verticalDoorLocationRight = 100;
    verticalDoorLocationLeft = 100;
    horizontalDoorLocationUp = 5;
    horizontalDoorLocationDown = 100;
    roomStartX = 5 * 50;
    roomStartY = 10 * 50;
    wall1.destructable = false; // Can be destroyed
    wall1.sprite.setTexture(textureWall);
    
    // Lay Floor Tiles
    ground1.sprite.setTextureRect(sf::IntRect(425,100,50,50));
    counter = 0;
    while (counter <= roomSize)
    {
        counter2 = 0;
        while (counter2 <= roomSize)
        {
            ground1.sprite.setPosition(50 * counter + roomStartX, 50 * counter2 + roomStartY);
            groundArray.push_back(ground1);
            
            counter2++;
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationUp)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationDown)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != verticalDoorLocationLeft)
        {
            wall1.rect.setPosition(0 + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize+1)
    {
        if (counter != verticalDoorLocationRight)
        {
            wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Random Stuff in Room
    wall1.sprite.setTexture(textureCrate);
    counter = 0;
    while (counter < (roomSize - 1))
    {
        counter2 = 0;
        while (counter2 < (roomSize - 1))
        {
            int tempRandom = generateRandom(40);
            if (tempRandom == 1)
            {
                // Destructable Boxes
                wall1.destructable = true; // Can be destroyed
                wall1.rect.setFillColor(sf::Color::Yellow);
                wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
                wallArray.push_back(wall1);
                wall1.destructable = false;
                wall1.rect.setFillColor(sf::Color::White);
            }
            if (tempRandom == 2)
            {
                // Mummy Enemy
                enemy1.isUnwrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 3)
            {
                // Goblin Enemy
                enemy1.isGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 4)
            {
                // Armoured Goblin Enemy
                enemy1.isArmouredGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 5)
            {
                // Robed Goblin Enemy
                enemy1.isRobedGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 6)
            {
                // Leader Goblin Enemy
                enemy1.isLeaderGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 7)
            {
                // Wrapped Mummy Goblin Enemy
                enemy1.isWrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }

            
            counter2++;
        }
        
        counter++;
    }
    
    
    
    // Custom Room 4th
    roomSize = 10;
    verticalDoorLocationRight = 100;
    verticalDoorLocationLeft = 100;
    horizontalDoorLocationUp = 5;
    horizontalDoorLocationDown = 5;
    roomStartX = 5 * 50;
    roomStartY = -1 * (10 * 50);
    wall1.destructable = false; // Can be destroyed
    wall1.sprite.setTexture(textureWall);
    
    // Lay Floor Tiles
    ground1.sprite.setTextureRect(sf::IntRect(425,100,50,50));
    counter = 0;
    while (counter <= roomSize)
    {
        counter2 = 0;
        while (counter2 <= roomSize)
        {
            ground1.sprite.setPosition(50 * counter + roomStartX, 50 * counter2 + roomStartY);
            groundArray.push_back(ground1);
            
            counter2++;
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationUp)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationDown)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != verticalDoorLocationLeft)
        {
            wall1.rect.setPosition(0 + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize+1)
    {
        if (counter != verticalDoorLocationRight)
        {
            wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Random Stuff in Room
    wall1.sprite.setTexture(textureCrate);
    counter = 0;
    while (counter < (roomSize - 1))
    {
        counter2 = 0;
        while (counter2 < (roomSize - 1))
        {
            int tempRandom = generateRandom(40);
            if (tempRandom == 1)
            {
                // Destructable Boxes
                wall1.destructable = true; // Can be destroyed
                wall1.rect.setFillColor(sf::Color::Yellow);
                wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
                wallArray.push_back(wall1);
                wall1.destructable = false;
                wall1.rect.setFillColor(sf::Color::White);
            }
            if (tempRandom == 2)
            {
                // Mummy Enemy
                enemy1.isUnwrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 3)
            {
                // Goblin Enemy
                enemy1.isGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 4)
            {
                // Armoured Goblin Enemy
                enemy1.isArmouredGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 5)
            {
                // Robed Goblin Enemy
                enemy1.isRobedGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 6)
            {
                // Leader Goblin Enemy
                enemy1.isLeaderGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 7)
            {
                // Wrapped Mummy Goblin Enemy
                enemy1.isWrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }

            
            counter2++;
        }
        
        counter++;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    // Custom Room 5th
    roomSize = 30;
    verticalDoorLocationRight = 100;
    verticalDoorLocationLeft = 100;
    horizontalDoorLocationUp = 100;
    horizontalDoorLocationDown = 5;
    roomStartX = 5 * 50;
    roomStartY = -1 * (45 * 50);
    wall1.destructable = false; // Can be destroyed
    wall1.sprite.setTexture(textureWall);
    
    // Lay Floor Tiles
    ground1.sprite.setTextureRect(sf::IntRect(425,100,50,50));
    counter = 0;
    while (counter <= roomSize)
    {
        counter2 = 0;
        while (counter2 <= roomSize)
        {
            ground1.sprite.setPosition(50 * counter + roomStartX, 50 * counter2 + roomStartY);
            groundArray.push_back(ground1);
            
            counter2++;
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationUp)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationDown)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != verticalDoorLocationLeft)
        {
            wall1.rect.setPosition(0 + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize+1)
    {
        if (counter != verticalDoorLocationRight)
        {
            wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Random Stuff in Room
    wall1.sprite.setTexture(textureCrate);
    counter = 0;
    while (counter < (roomSize - 1))
    {
        counter2 = 0;
        while (counter2 < (roomSize - 1))
        {
            int tempRandom = generateRandom(3);
            if (tempRandom == 1)
            {
                // Destructable Boxes
                wall1.destructable = true; // Can be destroyed
                wall1.rect.setFillColor(sf::Color::Yellow);
                wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
                wallArray.push_back(wall1);
                wall1.destructable = false;
                wall1.rect.setFillColor(sf::Color::White);
            }
            
            if (tempRandom == 3)
            {
                if (generateRandom(5) == 1)
                {
                    // Wrapped Mummy Goblin Enemy
                    enemy1.isWrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                    enemyArray.push_back(enemy1);
                }
            }
            
            
            
            counter2++;
        }
        
        counter++;
    }

    // Wrapped Mummy Goblin BOSS Enemy
    class enemy enemyBoss;
    enemyBoss.isWrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
    enemyBoss.sprite.setTexture(textureEnemySprite);
    enemyBoss.boss = true;
    enemyBoss.text.setFont(font);
    enemyBoss.text.setCharacterSize(17);
    enemyBoss.text.setColor(sf::Color::Red);
    enemyBoss.attackDamage = 15;
    enemyBoss.aggroed = true;
    enemyBoss.hp = 150;
    enemyBoss.maxhp = 150;
    enemyBoss.sprite.setColor(sf::Color::Red);
    enemyBoss.rect.setPosition((10 * 50) + 50 + roomStartX, (10 * 50) + 50 + roomStartY);
    enemyArray.push_back(enemyBoss);
    
    
    
    
    
    
    
    
    // Room (Item Shop)
    roomSize = 8;
    verticalDoorLocationRight = 100;
    verticalDoorLocationLeft = 3;
    horizontalDoorLocationUp = 100;
    horizontalDoorLocationDown = 100;
    roomStartX = 15 * 50;
    roomStartY = 0;
    wall1.destructable = false; // Can be destroyed
    wall1.sprite.setTexture(textureWall);
    
    // Lay Floor Tiles
    ground1.sprite.setTextureRect(sf::IntRect(25,25,50,50));
    counter = 0;
    while (counter <= roomSize)
    {
        counter2 = 0;
        while (counter2 <= roomSize)
        {
            ground1.sprite.setPosition(50 * counter + roomStartX, 50 * counter2 + roomStartY);
            groundArray.push_back(ground1);
            
            counter2++;
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationUp)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationDown)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != verticalDoorLocationLeft)
        {
            wall1.rect.setPosition(0 + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize+1)
    {
        if (counter != verticalDoorLocationRight)
        {
            wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    
        // Regular Power Up
        pickup1.cost = 15;
        pickup1.text.setString("Costs " + to_string(pickup1.cost));
        pickup1.inShop = true;
        pickup1.isCoin = false;
        pickup1.isPowerup = true;
        pickup1.isNovaPowerup = false;
        pickup1.sprite.setTexture(textureItems);
        pickup1.sprite.setTextureRect(sf::IntRect(34 * 3, 34 * 0, 32, 32));
        pickup1.rect.setPosition((15 * 50) + (2 * 50), (4 * 50));
        pickupArray.push_back(pickup1);

        // Nova Power Up
        pickup1.cost = 30;
        pickup1.text.setString("Costs " + to_string(pickup1.cost));
        pickup1.inShop = true;
        pickup1.isCoin = false;
        pickup1.isPowerup = false;
        pickup1.isNovaPowerup = true;
        pickup1.sprite.setTexture(textureItems);
        pickup1.sprite.setTextureRect(sf::IntRect(34 * 4, 34 * 0, 32, 32));
        pickup1.rect.setPosition((15 * 50) + (4 * 50), (4 * 50));
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;
    
    
        // HP Up Shield
        pickup1.cost = 100;
        pickup1.text.setString("Costs " + to_string(pickup1.cost));
        pickup1.inShop = true;
        pickup1.isCoin = false;
        pickup1.isPowerup = false;
        pickup1.isNovaPowerup = false;
        pickup1.isHPShield = true;
        pickup1.sprite.setTexture(textureItems);
        pickup1.sprite.setTextureRect(sf::IntRect(34 * 11, 34 * 0, 32, 32));
        pickup1.rect.setPosition((15 * 50) + (6 * 50), (4 * 50));
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;
        pickup1.isHPShield = false;
    

        // HP Potion
        pickup1.cost = 5;
        pickup1.text.setString("Costs " + to_string(pickup1.cost));
        pickup1.inShop = true;
        pickup1.isCoin = false;
        pickup1.isPowerup = false;
        pickup1.isNovaPowerup = false;
        pickup1.isHPShield = false;
        pickup1.isPotion = true;
        pickup1.sprite.setTexture(texturePotion);
        pickup1.sprite.setTextureRect(sf::IntRect(32 * 1, 32 * 3, 32, 32));
        pickup1.rect.setPosition((15 * 50) + (4 * 50), (2 * 50));
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;
        pickup1.isPotion = false;
    

        // French Fries Food
        pickup1.cost = 25;
        pickup1.text.setString("Costs " + to_string(pickup1.cost));
        pickup1.inShop = true;
        pickup1.isCoin = false;
        pickup1.isPowerup = false;
        pickup1.isNovaPowerup = false;
        pickup1.isHPShield = false;
        pickup1.isPotion = true;
        pickup1.sprite.setTexture(textureFood);
        pickup1.sprite.setTextureRect(sf::IntRect(32 * 14, 32 * 0, 32, 32));
        pickup1.rect.setPosition((15 * 50) + (3 * 50), (6 * 50));
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;
        pickup1.isPotion = false;
    
        // Hamburger Food
        pickup1.cost = 50;
        pickup1.text.setString("Costs " + to_string(pickup1.cost));
        pickup1.inShop = true;
        pickup1.isCoin = false;
        pickup1.isPowerup = false;
        pickup1.isNovaPowerup = false;
        pickup1.isHPShield = false;
        pickup1.isPotion = true;
        pickup1.sprite.setTexture(textureFood);
        pickup1.sprite.setTextureRect(sf::IntRect(32 * 13, 32 * 0, 32, 32));
        pickup1.rect.setPosition((15 * 50) + (5 * 50), (6 * 50));
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;
        pickup1.isPotion = false;
    
    
    
    
    
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();
        
        // Clock
        sf::Time elapsed1 = clock.getElapsedTime();
        sf::Time elapsed2 = clock2.getElapsedTime();
        sf::Time elapsed3 = clock3.getElapsedTime();
        
        
        
        
        
        /*
        // Test
        projectile1.rect.setPosition(400,300);
        projectile1.randomDirection = true;
        projectile1.lifeTime = 50;
        projectile1.sprite.setRotation(generateRandom(360));
        projectile1.randomx = cos(generateRandom(360));
        projectile1.randomy = cos(generateRandom(360));
        projectileArray.push_back(projectile1);
        projectile1.randomDirection = false;
        projectile1.lifeTime = 150;
        projectile1.sprite.setRotation(0);
        */
        
        
        
        
        
        
        
        
        // Enemy Collides with Wall
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            counter2 = 0;
            for (iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
            {
                
                if (enemyArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
                {
                    // Hit Wall
                    if (enemyArray[counter].direction == 1) // Up
                    {
                        enemyArray[counter].canMoveUp = false;
                        enemyArray[counter].rect.move(0,1);
                    }
                    else if (enemyArray[counter].direction == 2) // Down
                    {
                        enemyArray[counter].canMoveDown = false;
                        enemyArray[counter].rect.move(0,-1);
                    }
                    else if (enemyArray[counter].direction == 3) // Left
                    {
                        enemyArray[counter].canMoveLeft = false;
                        enemyArray[counter].rect.move(1,0);
                    }
                    else if (enemyArray[counter].direction == 4) // Right
                    {
                        enemyArray[counter].canMoveRight = false;
                        enemyArray[counter].rect.move(-1,0);
                    }
                    else
                    {
                        
                    }
                }
                
                counter2++;
            }
            
            
            counter++;
        }
        
        
        
        
        
        
        // Player Collides with Wall
        counter = 0;
        for (iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
        {
            if (Player1.rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds()))
            {
                // Hit Wall
                if (Player1.direction == 1) // Up
                {
                    Player1.canMoveUp = false;
                    Player1.rect.move(0,1);
                }
                else if (Player1.direction == 2) // Down
                {
                    Player1.canMoveDown = false;
                    Player1.rect.move(0,-1);
                }
                else if (Player1.direction == 3) // Left
                {
                    Player1.canMoveLeft = false;
                    Player1.rect.move(1,0);
                }
                else if (Player1.direction == 4) // Right
                {
                    Player1.canMoveRight = false;
                    Player1.rect.move(-1,0);
                }
                else
                {
                    
                }
            }
            
            counter++;
        }
        
        
        

        // Player collides with Pickup Item
        counter = 0;
        for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            if (Player1.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds()))
            {
                if (pickupArray[counter].inShop == true)
                {
                    if (Player1.gil >= pickupArray[counter].cost)
                    {
                        Player1.gil -= pickupArray[counter].cost;
                        
                        if (pickupArray[counter].isPowerup == true)
                        {
                            Player1.powerup = true;
                            Player1.novaAttack = false;
                            pickupArray[counter].destroy = true;
                        }
                        
                        if (pickupArray[counter].isNovaPowerup == true)
                        {
                            Player1.powerup = false;
                            Player1.novaAttack = true;
                            pickupArray[counter].destroy = true;
                        }
                        
                        if (pickupArray[counter].isHPShield == true)
                        {
                            Player1.hp += 10;
                            Player1.maxhp += 10;
                            pickupArray[counter].destroy = true;
                        }
                        if (pickupArray[counter].isPotion == true)
                        {
                            Player1.hp += 5;
                            if (Player1.hp >= Player1.maxhp)
                            {
                                Player1.hp = Player1.maxhp;
                            }
                            pickupArray[counter].destroy = true;
                        }
                    }
                }
                
                if (pickupArray[counter].inShop == false)
                {
                    if (pickupArray[counter].isCoin == true)
                    {
                        soundCoin.setVolume(30000);
                        soundCoin.play();
                        Player1.gil += pickupArray[counter].coinValue;
                        pickupArray[counter].destroy = true;
                    }
                    if (pickupArray[counter].isPowerup == true)
                    {
                        Player1.powerup = true;
                        Player1.novaAttack = false;
                        pickupArray[counter].destroy = true;
                    }
                    if (pickupArray[counter].isNovaPowerup == true)
                    {
                        Player1.powerup = false;
                        Player1.novaAttack = true;
                        pickupArray[counter].destroy = true;
                    }
                    if (pickupArray[counter].isPotion == true)
                    {
                        Player1.hp += 5;
                        if (Player1.hp >= Player1.maxhp)
                        {
                            Player1.hp = Player1.maxhp;
                        }
                        pickupArray[counter].destroy = true;
                    }
                }

                
            }
            
            counter++;
        }
        
        
        
        
        
        if (elapsed2.asSeconds() >= 0.5)
        {
            clock2.restart();
            
            // Enemy Collides with Player (Player takes damage)
            counter = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if (Player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
                {
                    soundPlayerDamaged.play();
                    
                    // Text Display
                    textDisplay1.text.setString(to_string(enemyArray[counter].attackDamage));
                    textDisplay1.text.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2, Player1.rect.getPosition().y - Player1.rect.getSize().y/2);
                    textDisplayArray.push_back(textDisplay1);
                    
                    Player1.hp -= enemyArray[counter].attackDamage;
                    Player1.powerup = false;
                    Player1.novaAttack = false;
                }
                
                counter++;
            }
        }
        
        //cout << Player1.hp << endl;
        
        
        
        
        // Projectile Collides with Wall
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            counter2 = 0;
            for (iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
            {
                if (projectileArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
                {
                    projectileArray[counter].destroy = true;
                    
                    if (wallArray[counter2].destructable == true)
                    {
                        wallArray[counter2].hp -= Player1.attackDamage;
                        
                        if (wallArray[counter2].hp <= 0)
                        {
                            wallArray[counter2].destroy = true;
                        }
                    }
                }

                counter2++;
            }

            counter++;
        }
        
        
        
        // Enemy Aggro (AI)
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            if (enemyArray[counter].aggroed == true)
            {
                if (elapsed3.asSeconds() >= 1)
                {
                    clock3.restart();
                    
                    int tempRand = generateRandom(3);
                    
                    if (tempRand == 1) // Enemy Fires Projectile at Player & Chases Player
                    {
                        projectile1.attackDamage = enemyArray[counter].attackDamage;
                        
                        // Player to Right
                        if ((Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x) && (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
                        {
                             soundShot.play();
                             projectile1.enemyProjectile = true;
                             projectile1.direction = 3;
                             projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                             projectileArray.push_back(projectile1);
                             projectile1.enemyProjectile = false;
                            
                             enemyArray[counter].direction = 3;
                        }
                        
                        // Player to Left
                        if ((Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x) && (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
                        {
                            soundShot.play();
                            projectile1.enemyProjectile = true;
                            projectile1.direction = 4;
                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectileArray.push_back(projectile1);
                            projectile1.enemyProjectile = false;
                            
                            enemyArray[counter].direction = 4;
                        }
                        
                        // Player to Top
                        if ((Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y) && (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 40))
                        {
                            soundShot.play();
                            projectile1.enemyProjectile = true;
                            projectile1.direction = 1;
                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectileArray.push_back(projectile1);
                            projectile1.enemyProjectile = false;
                            
                            enemyArray[counter].direction = 1;
                        }
                        
                        // Player to Bottom
                        if ((Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y) && (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 40))
                        {
                            soundShot.play();
                            projectile1.enemyProjectile = true;
                            projectile1.direction = 2;
                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectileArray.push_back(projectile1);
                            projectile1.enemyProjectile = false;
                            
                            enemyArray[counter].direction = 2;
                            }
                    }
                    else if (tempRand == 2) // Enemy Chases Player
                    {
                        if (Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
                        {
                            enemyArray[counter].direction = 1;
                        }
                        else if (Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
                        {
                            enemyArray[counter].direction = 2;
                        }
                        else if (Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
                        {
                            enemyArray[counter].direction = 3;
                        }
                        else if (Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
                        {
                            enemyArray[counter].direction = 4;
                        }
                    }
                    else // Enemy Chases Player
                    {
                        if (Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
                        {
                            enemyArray[counter].direction = 3;
                        }
                        else if (Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
                        {
                            enemyArray[counter].direction = 4;
                        }
                        else if (Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
                        {
                            enemyArray[counter].direction = 1;
                        }
                        else if (Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
                        {
                            enemyArray[counter].direction = 2;
                        }
                    }
                    
                }
            }
            
            counter++;
        }
        
        
        
        
        
        // Projectile Collides with Enemy
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            counter2 = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
                {
                    if (projectileArray[counter].enemyProjectile == false)
                    {
                        soundCollision.play();
                        
                        projectileArray[counter].destroy = true;
                        
                        // Text Display
                        textDisplay1.text.setString(to_string(Player1.attackDamage));
                        textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x + enemyArray[counter2].rect.getSize().x/2, enemyArray[counter2].rect.getPosition().y - enemyArray[counter2].rect.getSize().y/2);
                        textDisplayArray.push_back(textDisplay1);
                        
                        enemyArray[counter2].hp -= Player1.attackDamage;
                        if (enemyArray[counter2].hp <= 0)
                        {
                            enemyArray[counter2].alive = false;
                        }
                        
                        // Aggro
                        enemyArray[counter2].aggroed = true;
                    }
                }
                
                counter2++;
            }
            
            counter++;
        }
        
        
        // Enemy Projectile Collides with Player
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            if (projectileArray[counter].enemyProjectile == true)
            {
                if (projectileArray[counter].rect.getGlobalBounds().intersects(Player1.rect.getGlobalBounds()))
                {
                    Player1.hp -= projectileArray[counter].attackDamage;
                    
                    // Text Display
                    textDisplay1.text.setString(to_string(projectileArray[counter].attackDamage));
                    textDisplay1.text.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2, Player1.rect.getPosition().y - Player1.rect.getSize().y/2);
                    textDisplayArray.push_back(textDisplay1);
                    
                    projectileArray[counter].destroy = true;
                }
            }
            
            counter++;
        }
        
        
        
        // Delete Dead Enemy
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            if (enemyArray[counter].alive == false)
            {
                int tempRandom = generateRandom(20);
                
                // Drop Coin
                if ((tempRandom >= 1) && (tempRandom <= 3))
                {
                    pickup1.isCoin = true;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.sprite.setTexture(textureCoin);
                    pickup1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                    pickup1.sprite.setScale(1, 1);
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                // Drop Powerup
                if (tempRandom == 4)
                {
                    pickup1.isCoin = false;
                    pickup1.isPowerup = true;
                    pickup1.isNovaPowerup = false;
                    pickup1.sprite.setTexture(textureItems);
                    pickup1.sprite.setTextureRect(sf::IntRect(34 * 3, 34 * 0, 32, 32));
                    pickup1.sprite.setScale(1, 1);
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                
                // Drop nova Powerup
                if (tempRandom == 5)
                {
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = true;
                    pickup1.sprite.setTexture(textureItems);
                    pickup1.sprite.setTextureRect(sf::IntRect(34 * 4, 34 * 0, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                
                // Drop Regular HP Potion
                if (tempRandom == 6)
                {
                    pickup1.inShop = false;
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.isHPShield = false;
                    pickup1.isPotion = true;
                    pickup1.sprite.setTexture(texturePotion);
                    pickup1.sprite.setTextureRect(sf::IntRect(32 * 1, 32 * 3, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                    pickup1.inShop = false;
                    pickup1.isPotion = false;
                }
                
                // Drop Uncommon HP Potion
                if (tempRandom == 7)
                {
                    pickup1.inShop = false;
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.isHPShield = false;
                    pickup1.isPotion = true;
                    pickup1.sprite.setTexture(texturePotion);
                    pickup1.sprite.setTextureRect(sf::IntRect(32 * 2, 32 * 3, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                    pickup1.inShop = false;
                    pickup1.isPotion = false;
                }
                
                // Killed Boss (Drops)
                if (enemyArray[counter].boss == true)
                {
                    pickup1.isCoin = true;
                    pickup1.sprite.setTexture(textureCoin);
                    pickup1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                    pickup1.sprite.setScale(1, 1);
                    
                    counter3 = 0;
                    while (counter3 <= 20)
                    {
                        pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x - generateRandom(30),enemyArray[counter].rect.getPosition().y - generateRandom(30));
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x + generateRandom(30),enemyArray[counter].rect.getPosition().y + generateRandom(30));
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x - generateRandom(30),enemyArray[counter].rect.getPosition().y + generateRandom(30));
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x + generateRandom(30),enemyArray[counter].rect.getPosition().y - generateRandom(30));
                        pickupArray.push_back(pickup1);
                    
                        counter3++;
                    }
                }
                
                
                // Create Enemy Blood Stain
                blood1.rect.setPosition(enemyArray[counter].rect.getPosition());
                bloodArray.push_back(blood1);
                
                
                enemyArray.erase(iter4);
                break;
            }
            
            counter++;
        }
        
        // Delete Projectile
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            if (projectileArray[counter].destroy == true)
            {
                projectileArray.erase(iter);
                break;
            }
            
            counter++;
        }
        
        // Delete Text Display
        counter = 0;
        for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
        {
            if (textDisplayArray[counter].destroy == true)
            {
                textDisplayArray.erase(iter8);
                break;
            }
            
            counter++;
        }
        
        // Delete Pickup Items
        counter = 0;
        for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            if (pickupArray[counter].destroy == true)
            {
                pickupArray.erase(iter11);
                break;
            }
            
            counter++;
        }
        
        // Delete Wall
        counter = 0;
        for (iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
        {
            if (wallArray[counter].destroy == true)
            {
                int tempRandom = generateRandom(15);
                
                // Drop Coin
                if ((tempRandom >= 1) && (tempRandom <= 3))
                {
                    pickup1.isCoin = true;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.sprite.setTexture(textureCoin);
                    pickup1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                    pickup1.sprite.setScale(1, 1);
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                // Drop Multiple Coins
                if (tempRandom >= 4)
                {
                    pickup1.isCoin = true;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.sprite.setTexture(textureCoin);
                    pickup1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                    pickup1.sprite.setScale(1, 1);
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x-5,wallArray[counter].rect.getPosition().y);
                    pickupArray.push_back(pickup1);
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x,wallArray[counter].rect.getPosition().y+5);
                    pickupArray.push_back(pickup1);
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x+5,wallArray[counter].rect.getPosition().y);
                    pickupArray.push_back(pickup1);
                    
                    if (generateRandom(5) == 1)
                    {
                        pickup1.isCoin = true;
                        pickup1.sprite.setTexture(textureCoin);
                        pickup1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                        pickup1.sprite.setScale(1, 1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x-5,wallArray[counter].rect.getPosition().y);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x,wallArray[counter].rect.getPosition().y+5);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x+5,wallArray[counter].rect.getPosition().y);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x-10,wallArray[counter].rect.getPosition().y);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x,wallArray[counter].rect.getPosition().y+10);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x+10,wallArray[counter].rect.getPosition().y);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x-15,wallArray[counter].rect.getPosition().y);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x,wallArray[counter].rect.getPosition().y+15);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x+15,wallArray[counter].rect.getPosition().y);
                        pickupArray.push_back(pickup1);
                    }
                }
                // Drop Powerup
                if (tempRandom == 5)
                {
                    pickup1.isCoin = false;
                    pickup1.isPowerup = true;
                    pickup1.isNovaPowerup = false;
                    pickup1.sprite.setTexture(textureItems);
                    pickup1.sprite.setTextureRect(sf::IntRect(34 * 3, 34 * 0, 32, 32));
                    pickup1.sprite.setScale(1, 1);
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                
                // Drop nova Powerup
                if (tempRandom == 6)
                {
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = true;
                    pickup1.sprite.setTexture(textureItems);
                    pickup1.sprite.setTextureRect(sf::IntRect(34 * 4, 34 * 0, 32, 32));
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                
                // Drop Regular HP Potion
                if (tempRandom == 7)
                {
                    pickup1.inShop = false;
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.isHPShield = false;
                    pickup1.isPotion = true;
                    pickup1.sprite.setTexture(texturePotion);
                    pickup1.sprite.setTextureRect(sf::IntRect(32 * 1, 32 * 3, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                    pickup1.inShop = false;
                    pickup1.isPotion = false;
                }
                
                // Drop Uncommon HP Potion
                if (tempRandom == 8)
                {
                    pickup1.inShop = false;
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.isHPShield = false;
                    pickup1.isPotion = true;
                    pickup1.sprite.setTexture(texturePotion);
                    pickup1.sprite.setTextureRect(sf::IntRect(32 * 2, 32 * 3, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                    pickup1.inShop = false;
                    pickup1.isPotion = false;
                }

                // French Fries Food
                if (tempRandom == 9)
                {
                    pickup1.cost = 25;
                    pickup1.text.setString("Costs " + to_string(pickup1.cost));
                    pickup1.inShop = false;
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.isHPShield = false;
                    pickup1.isPotion = true;
                    pickup1.sprite.setTexture(textureFood);
                    pickup1.sprite.setTextureRect(sf::IntRect(32 * 14, 32 * 0, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                    pickup1.inShop = false;
                    pickup1.isPotion = false;
                }
                
                // Hamburger Food
                if (tempRandom == 10)
                {
                    pickup1.cost = 50;
                    pickup1.text.setString("Costs " + to_string(pickup1.cost));
                    pickup1.inShop = false;
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.isHPShield = false;
                    pickup1.isPotion = true;
                    pickup1.sprite.setTexture(textureFood);
                    pickup1.sprite.setTextureRect(sf::IntRect(32 * 13, 32 * 0, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                    pickup1.inShop = false;
                    pickup1.isPotion = false;
                }
                
                
                
                
                
                
                wallArray.erase(iter15);
                break;
            }
            
            counter++;
        }
        
        // Delete Enemy Blood Stain
        counter = 0;
        for (iter20 = bloodArray.begin(); iter20 != bloodArray.end(); iter20++)
        {
            if (bloodArray[counter].alive == false)
            {
                bloodArray.erase(iter20);
                break;
            }
            
            counter++;
        }
        
        
        
        
        
        
        
        // Spawn Enemies (Y-Key)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        {
            enemy1.rect.setPosition(generateRandom(window.getSize().x), generateRandom(window.getSize().y));
            enemyArray.push_back(enemy1);
        }

        // Fires Missle (Space bar)
        if (elapsed1.asSeconds() >= Player1.attackSpeed)
        {
            clock.restart();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                soundShot.play();
                
                if (Player1.powerup == true) // Powerup Attack
                {
                    if (Player1.direction == 1) // UP
                    {
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 15);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 - 15,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 0);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 + 15,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 0);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                    }
                    
                    if (Player1.direction == 2) // Down
                    {
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 15);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 - 15,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 0);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 + 15,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 0);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                    }
                    
                    if (Player1.direction == 3) // Left
                    {
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 - 15,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 15);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 15);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                    }
                    
                    if (Player1.direction == 4) // Right
                    {
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 + 15,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 15);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 15);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                    }
                }
                else if (Player1.novaAttack == true)
                {
                    projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                    projectile1.direction = 1;
                    projectileArray.push_back(projectile1);
                    
                    projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                    projectile1.direction = 2;
                    projectileArray.push_back(projectile1);
                    
                    projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                    projectile1.direction = 3;
                    projectileArray.push_back(projectile1);
                    
                    projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                    projectile1.direction = 4;
                    projectileArray.push_back(projectile1);
                }
                else // Normal Attack
                {
                    projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                    projectile1.direction = Player1.direction;
                    projectileArray.push_back(projectile1);
                }
            }
        }
        
        // Draw Ground
        counter = 0;
        for (iter25 = groundArray.begin(); iter25 != groundArray.end(); iter25++)
        {
            //window.draw(groundArray[counter].sprite);
            
            counter++;
        }
        
        // Draw Wall
        counter = 0;
        for (iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
        {
            wallArray[counter].update();
            
            window.draw(wallArray[counter].rect);
            window.draw(wallArray[counter].sprite);
            
            counter++;
        }
        
        // Draw Enemy Dead Blood
        counter = 0;
        for (iter20 = bloodArray.begin(); iter20 != bloodArray.end(); iter20++)
        {
            bloodArray[counter].update();
            window.draw(bloodArray[counter].sprite);
            
            counter++;
        }
        
        // Draw Pickup Items
        counter = 0;
        for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            if (pickupArray[counter].inShop == true)
            {
                window.draw(pickupArray[counter].text);
            }
            
            pickupArray[counter].update();
            //window.draw(pickupArray[counter].rect);
            window.draw(pickupArray[counter].sprite);
            
            counter++;
        }
        
        // Draw Projectiles
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            projectileArray[counter].update(); // Update Projectile
            //window.draw(projectileArray[counter].rect);
            window.draw(projectileArray[counter].sprite);
            
            counter++;
        }
        
        // Draw Enemies
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            enemyArray[counter].update();
            enemyArray[counter].updateMovement();
            //window.draw(enemyArray[counter].rect);
            window.draw(enemyArray[counter].sprite);
            
            counter++;
        }
        
        // Draw Enemies
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            enemyArray[counter].text.setString("HP " + to_string(enemyArray[counter].hp) + "/" + to_string(enemyArray[counter].maxhp));
            window.draw(enemyArray[counter].text);
            
            counter++;
        }
        
        // Update Player
        Player1.update();
        Player1.updateMovement();
        
        // Player View
        window.setView(view1);
        view1.setCenter(Player1.rect.getPosition());
        
        
        // Draw Player
        window.draw(Player1.sprite);
        //window.draw(Player1.rect);
        
        // Draw Text
        counter = 0;
        for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
        {
            textDisplayArray[counter].update();
            window.draw(textDisplayArray[counter].text);
            
            counter++;
        }
        
        // Player HP TEXT
        textHP.setString("HP : " + to_string(Player1.hp) + "/" + to_string(Player1.maxhp));
        window.draw(textHP);
        textHP.setPosition(Player1.rect.getPosition().x - window.getSize().x/2, Player1.rect.getPosition().y - window.getSize().y/2);
        
        // Gil TEXT
        text.setString("Gil : " + to_string(Player1.gil) + "\nAttack Damage : " + to_string(Player1.attackDamage) + "\nAttack Speed : " + to_string(Player1.attackSpeed));
        window.draw(text);
        text.setPosition(Player1.rect.getPosition().x - window.getSize().x/2, Player1.rect.getPosition().y - window.getSize().y/2 + 25);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
