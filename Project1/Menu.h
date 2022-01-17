#pragma once
#include<SFML\Graphics.hpp>
#include<memory>
#include<stack>
# define Max 6
# define Max2 3

class Menu
{
public:
	Menu(float width, float height);
	~Menu();
	void draw(sf::RenderWindow &window1);
	void draw2(sf::RenderWindow &window1);
	void moveup();
	void movedown();
	void moveup2();
	void movedown2();
	void sound();
	int getitem() { return item; };
	//void menu2();

private:
	int item;
	int item2;
	sf::Font fanta;
	sf::Text menu[Max];
	sf::Text menu2[Max2];
};






