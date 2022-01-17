#include "Menu.h"
#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<iostream>
using namespace sf;
using namespace std;
#include<memory>
#include<stack>

Menu::Menu(float width, float height)
{

	fanta.loadFromFile("Arial.ttf");
	menu[0].setFont(fanta);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].Bold;
	menu[0].setCharacterSize(50);
	menu[0].setOutlineThickness(7);
	
	//menu[0].setOutlineColor(Color::Magenta);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2.3, height / (Max + 1) * 1));


	menu[1].setFont(fanta);
	menu[1].setFillColor(sf::Color::Red);
	menu[1].Bold;
	menu[1].setCharacterSize(40);
	menu[1].setOutlineThickness(7);
	menu[1].setFillColor(sf::Color::Blue);
	menu[1].setString("Ping Pong");
	menu[1].setPosition(sf::Vector2f(width / 2.3 , height / (Max + 1) * 2));

	menu[2].setFont(fanta);
	menu[2].setFillColor(sf::Color::Red);
	menu[2].Bold;
	menu[2].setCharacterSize(45);
	menu[2].setOutlineThickness(7);
	menu[2].setFillColor(sf::Color::Blue);
	menu[2].setString("1 on 1");
	menu[2].setPosition(sf::Vector2f(width / 2.3 , height / (Max + 1) * 3));
	item = 0;


	menu[3].setFont(fanta);
	menu[3].setFillColor(sf::Color::Red);
	menu[3].Bold;
	menu[3].setCharacterSize(45);
	menu[3].setOutlineThickness(7);
	menu[3].setFillColor(sf::Color::Blue);
	menu[3].setString("5 vs 5");
	menu[3].setPosition(sf::Vector2f(width / 2.3, height / (Max + 1) * 4));


	menu[4].setFont(fanta);
	menu[4].setFillColor(sf::Color::Red);
	menu[4].Bold;
	menu[4].setCharacterSize(45);
	menu[4].setOutlineThickness(7);
	menu[4].setFillColor(sf::Color::Blue);
	menu[4].setString("Options");
	menu[4].setPosition(sf::Vector2f(width / 2.3, height / (Max + 1) * 5));

	menu[5].setFont(fanta);
	menu[5].setFillColor(sf::Color::Red);
	menu[5].Bold;
	menu[5].setCharacterSize(45);
	menu[5].setOutlineThickness(7);
	menu[5].setFillColor(sf::Color::Blue);
	menu[5].setString("Exit");
	menu[5].setPosition(sf::Vector2f(width / 2.3, height / (Max + 1) * 6));
	item2 = 0;


}


void Menu::draw(sf::RenderWindow& window1)
{
	for (int i = 0; i < Max; i++)
	{
		window1.draw(menu[i]);
	}

}

void Menu::sound()
{
	SoundBuffer b1;
	if (!b1.loadFromFile("Background019.wav"))
	{
		cout << "ERROR" << endl;
	}
	Sound sound;
	sound.setBuffer(b1);
	sound.play();
	//sound.setLoop(true);

}

void Menu::moveup()
{

	if (item - 1 >= 0)
	{
		menu[item].setFillColor(sf::Color::White);
		item--;
		menu[item].setFillColor(sf::Color::Red);

	}
}

void Menu::movedown()
{

	if (item + 1 < Max)
	{
		menu[item].setFillColor(sf::Color::White);
		item++;
		menu[item].setFillColor(sf::Color::Red);

	}
}

void Menu::moveup2()
{

	if (item2 - 1 >= 0)
	{
		menu2[item2].setFillColor(sf::Color::White);
		item2--;
		menu2[item2].setFillColor(sf::Color::Red);

	}
}

void Menu::movedown2()
{

	if (item2 + 1 < Max)
	{
		menu2[item2].setFillColor(sf::Color::White);
		item2++;
		menu2[item2].setFillColor(sf::Color::Red);

	}
}


void Menu::draw2(sf::RenderWindow& window1)
{

	for (int j = 0; j < Max2; j++)
	{
		window1.draw(menu2[j]);
	}

}
Menu::~Menu()
{}
