
#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<sstream>
#include"Menu.h"//Olivia means nothing you think i can live like this you think i bloody enjoy living like this
using namespace std;//The same man comes out of the second cabinet
using namespace sf;

//They'll beg you and flatter you for the secret.But soon you give it up You will be nothing to them.The secret impresses no one.The trick you use it for is everything
                                                                                 
bool intersects(RectangleShape& c1, RectangleShape& rect2)
{
	FloatRect rec = c1.getGlobalBounds();
    FloatRect rectangle = rect2.getGlobalBounds();
	return rec.intersects(rectangle);
}

int main()
{

	RectangleShape outleft(Vector2f(30.0f, 700.0f));
	//	outleft.setFillColor(sf::Color::Black);
	outleft.setPosition(0, 0);

	RectangleShape outright(Vector2f(50.0f, 700.0f));
	//	outright.setFillColor(sf::Color::Black);
	//	outright.setSize(sf::Vector2f(10, 400));
	outright.setPosition(1170, 0);

	RectangleShape mid;
	//mid.setFillColor(sf::Color::Blue);
	mid.setSize(sf::Vector2f(20, 700));
	mid.setPosition(585.0f, 0.0f);

	RectangleShape up(Vector2f(1200.0f, 20.0f));
	//	up.setFillColor(sf::Color::Blue);
	up.setPosition(0, 0);


	RectangleShape down(Vector2f(1200.0f, 700.0f));
	//	down.setFillColor(sf::Color::Blue);
	down.setPosition(0, 650);

	RectangleShape left;
	RectangleShape right;
	float LO = -0.5;
	float HI = 3;
	float r0 = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));

	Vector2<float>ballSpeed(r0, r0);



	RenderWindow window(VideoMode(1200, 700), "PLAY", Style::Close | Style::Resize);
	RenderWindow window2(VideoMode(1200, 700), "PING PONG", Style::Close | Style::Resize);
	RenderWindow window3(VideoMode(1200, 700), "1 ON 1", Style::Close | Style::Resize);
	RenderWindow window4(VideoMode(1200, 700), "5 VS 5", Style::Close | Style::Resize);
	RenderWindow window1(VideoMode(1380, 785), "Menu", Style::Close | Style::Resize);
	Menu menu(window1.getSize().x, window1.getSize().y);

	//View view(Vector2f(0.0f, 0.0f), Vector2f(View_width, View_height));
	int count = 0;
	int score = 0;
	float Playerspeed1 = 0.36;
	float Playerspeed2 = 0.35;





	///////////////
	//////////////////////////////////          SCORE YAKI?  //////////////////////////////////////
	//////////////////////
	/////////////////////////////

	Font a;
	a.loadFromFile("arial.ttf");
	int score1 = 0;



	Font a1;
	a1.loadFromFile("arial.ttf");
	int score2 = 0;


	Text mytext;
	//Text pl2;
	mytext.setFont(a1);
	mytext.setCharacterSize(35);
	mytext.setPosition(1000, 100);
	// Update the text
	std::stringstream ss;
	ss << "Goals :" << score2;
	mytext.setString(ss.str());



	//	cout << "GOALS : \n" << score1;
	Text playerscore;
	playerscore.setCharacterSize(35);
	playerscore.setPosition(100, 100);
	playerscore.setFont(a);



	//	Player.setOutlineColor(Color::Transparent);




	///////////////////////////////////////////////////////////////
	///////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	RectangleShape Field(Vector2f(1200.0f, 700.0f));
	RectangleShape Player(Vector2f(60.0f, 60.0f));
	RectangleShape Ball(Vector2f(35.0f, 35.0f));
	RectangleShape Player2(Vector2f(60.0f, 60.0f));
	Player2.setPosition(1050.0f, 290.0f);
	Ball.setPosition(585.0f, 320.0f);
	Player.setPosition(50.0f, 290.0f);
	Texture f, p, b, p2;
	f.loadFromFile("Field.jpg");
	Field.setTexture(&f);
	p.loadFromFile("Player.png");
	Player.setTexture(&p);
	b.loadFromFile("Football.png");
	Ball.setTexture(&b);
	p2.loadFromFile("Player.png");
	Player2.setTexture(&p2);

	/////////SPRITE YAKI
	/////
	/////

	Texture s;
	s.loadFromFile("Sprite1.png");
	Sprite splayer(s);
	splayer.setPosition(500, 200);
	Vector2u textureSize = s.getSize();
	textureSize.x /= 4;
	textureSize.y /= 4;
	splayer.setTextureRect(IntRect(textureSize.x * 2, textureSize.y * 2, textureSize.x, textureSize.y));
	splayer.scale(Vector2f(1.1f, 1.3f));

	Texture s2;
	s2.loadFromFile("Sprite1.png");
	Sprite splayer2(s2);
	splayer2.setPosition(500, 400);
	Vector2u textureSize2 = s2.getSize();
	textureSize2.x /= 4;
	textureSize2.y /= 4;
	splayer2.setTextureRect(IntRect(textureSize2.x * 2, textureSize2.y * 2, textureSize2.x, textureSize2.y));
	splayer2.scale(Vector2f(1.1f, 1.3f));




	Texture s3;
	s3.loadFromFile("Sprite1.png");
	Sprite splayer3(s3);
	splayer3.setPosition(150, 300);
	Vector2u textureSize3 = s3.getSize();
	textureSize3.x /= 4;
	textureSize3.y /= 4;
	splayer3.setTextureRect(IntRect(textureSize3.x * 2, textureSize3.y * 2, textureSize3.x, textureSize3.y));
	splayer3.scale(Vector2f(1.1f, 1.3f));



	Texture s4;
	s4.loadFromFile("Sprite1.png");
	Sprite splayer4(s4);
	splayer4.setPosition(310, 150);
	Vector2u textureSize4 = s4.getSize();
	textureSize4.x /= 4;
	textureSize4.y /= 4;
	splayer4.setTextureRect(IntRect(textureSize4.x * 2, textureSize4.y * 2, textureSize4.x, textureSize4.y));
	splayer4.scale(Vector2f(1.1f, 1.3f));


	Texture s5;
	s5.loadFromFile("Sprite1.png");
	Sprite splayer5(s5);
	splayer5.setPosition(310, 400);
	Vector2u textureSize5 = s5.getSize();
	textureSize5.x /= 4;
	textureSize5.y /= 4;
	splayer5.setTextureRect(IntRect(textureSize5.x * 2, textureSize5.y * 2, textureSize5.x, textureSize5.y));
	splayer5.scale(Vector2f(1.1f, 1.3f));



	Texture s6;
	s6.loadFromFile("Sprite.png");
	Sprite splayer6(s6);
	splayer6.setPosition(700, 400);
	Vector2u textureSize6 = s6.getSize();
	textureSize6.x /= 3;
	textureSize6.y /= 7;
	splayer6.setTextureRect(IntRect(textureSize6.x, textureSize6.y, textureSize6.x, textureSize6.y));
	splayer6.scale(Vector2f(1.15f, 1.4f));

	Texture s7;
	s7.loadFromFile("Sprite.png");
	Sprite splayer7(s7);
	splayer7.setPosition(700, 200);
	Vector2u textureSize7 = s7.getSize();
	textureSize7.x /= 3;
	textureSize7.y /= 7;
	splayer7.setTextureRect(IntRect(textureSize7.x * 1, textureSize7.y*1., textureSize7.x, textureSize7.y));
	splayer7.scale(Vector2f(1.15f, 1.4f));




	Texture s8;
	s8.loadFromFile("Sprite.png");
	Sprite splayer8(s8);
	splayer8.setPosition(850, 150);
	Vector2u textureSize8 = s8.getSize();
	textureSize8.x /= 3;
	textureSize8.y /= 7;
	splayer8.setTextureRect(IntRect(textureSize8.x, textureSize8.y, textureSize8.x, textureSize8.y));
	splayer8.scale(Vector2f(1.15f, 1.4f));



	Texture s9;
	s9.loadFromFile("Sprite.png");
	Sprite splayer9(s9);
	splayer9.setPosition(850, 450);
	Vector2u textureSize9 = s9.getSize();
	textureSize9.x /= 3;
	textureSize9.y /= 7;
	splayer9.setTextureRect(IntRect(textureSize9.x, textureSize9.y, textureSize9.x, textureSize9.y));
	splayer9.scale(Vector2f(1.15f, 1.4f));


	Texture s0;
	s0.loadFromFile("Sprite.png");
	Sprite splayer0(s0);
	splayer0.setPosition(970, 300);
	Vector2u textureSize0 = s0.getSize();
	textureSize0.x /= 3;
	textureSize0.y /= 7;
	splayer0.setTextureRect(IntRect(textureSize0.x * 1, textureSize0.y * 1, textureSize0.x, textureSize0.y));
	splayer0.scale(Vector2f(1.15f, 1.4f));







	///////////////
	////////////////////////////////
	/////////////


	/*soundBuffer buffer;
	buffer.loadFromFile("All.wav");
	Sound sound;
	sound.setBuffer(buffer);
	sound.play();
	sound.setLoop(true);*/
	RectangleShape Fifa(Vector2f(1380, 785));
	Texture fifa;
	fifa.loadFromFile("fifa.jpg");
	Fifa.setTexture(&fifa);



	/////////////////
	////////////////////////////////////////////////////             MENU WINDOW
	/////////////////////////////////
	while (window1.isOpen())
	{

	Event event;
		while (window1.pollEvent(event))

		{


			if (event.type == sf::Event::Closed)
				window1.close();

			if (Keyboard::isKeyPressed(Keyboard::Up))
				menu.moveup();

			if (Keyboard::isKeyPressed(Keyboard::Down))
				menu.movedown();

			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Return:
					switch (menu.getitem())
					{
					case 0:
						cout << "Play Button is pressed " << endl;

						window1.close();
						window2.close();
						window4.close();
						window3.close();

						window.clear();
						window.display();
						break;

					case 1:
						cout << "Ping Pong Button is pressed " << endl;
						window1.close();
						window.close();
						window4.close();
						window3.close();
						window2.display();
						break;

					case 2:
						cout << "1 ON 1 Button is pressed" << endl;
						window.close();
						window1.close();
						window2.close();
						window4.close();
						window3.clear();
						window3.display();
						break;
					case 3:
						cout << "5 VS 5 Button is pressed" << endl;
						window.close();
						window1.close();
						window2.close();
						window3.close();
						window4.clear();
						window4.display();
						break;

					case 5:
						window.close();
						window1.close();
						window2.close();
						window3.close();
						window4.close();
						break;


					}
				}
			}


		}
		window1.draw(Fifa);
		menu.draw(window1);
		window1.display();

	}

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}



		/////////////////////////////
		//////////////////////////////////////////////////////            PING PONG  YAKI
		/////////////////////////////////////
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			Player.move(0, -Playerspeed1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Player.move(0, Playerspeed1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			Player2.move(0, -Playerspeed2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) 
		{
			Player2.move(0, Playerspeed2);
		}
		if (intersects(Ball, outleft))
		{
			//player1score++;
			score2++;
			Ball.setPosition(585, 290);
			std::stringstream ss;
			ss << "Goals :" << score2;
			mytext.setString(ss.str());
			//std::cout << "Player1=  " << player1score << std::endl;
		}
		if (intersects(Ball, outright))
		{
			//			player2score++;
			Ball.setPosition(585, 290);	//		std::cout << "Player2 =  " << player2score << std::endl;
		}
		if (intersects(Ball, up) || (intersects(Ball, down)))
		{
			ballSpeed.y = -ballSpeed.y;
		}
		if (intersects(Ball, Player) || (intersects(Ball, Player2))) 
		{
			ballSpeed.x = -ballSpeed.x;
		}
		Ball.move(ballSpeed.x, ballSpeed.y);
		if (Ball.getPosition().x > 1080.0f)

		{
			//int score1 = 0;
			score1++;
			Ball.setPosition(585.0f, 320.0f);
			//	cout << "SCORE : " << score1 << endl;
			ostringstream sscore;
			sscore << "Goals :" << score1;
			playerscore.setString(sscore.str());

		}
		ostringstream sscore;
		sscore << "Goals :" << score1;
		playerscore.setString(sscore.str());


		if (intersects(Ball, down))
		{
			Player2.move(0, -Playerspeed2);
		}
		
		// DRAWING
		//
		//

		Player.setFillColor(Color::Blue);
		Player2.setFillColor(Color::Red);
		//	window.clear();
		//	window.setView(view);




		window.draw(Field);
		window.draw(Player);
		window.draw(playerscore);
		window.draw(Player2);
		window.draw(Ball);
		//		window.draw(Ball1);
		window.draw(down);
		window.draw(up);
		window.draw(outleft);
		window.draw(outright);
		window.draw(mytext);
		//window1.clear();
		window.display();

	}

	/////////////////////////
	/////////////////////////////////////////////////
	/////////////////

	while (window2.isOpen())
	{
		sf::Event event;
		while (window2.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window2.close();
		}
		/////////////////////////////
		//////////////////////////////////////////////////////            PING PONG  YAKI
		/////////////////////////////////////
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			Player.move(0, -Playerspeed1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Player.move(0, Playerspeed1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			Player2.move(0, -Playerspeed2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			Player2.move(0, Playerspeed2);
		}
		if (intersects(Ball, outleft))
		{
			//player1score++;
			score2++;
			Ball.setPosition(585, 290);
			std::stringstream ss;
			ss << "Goals :" << score2;
			mytext.setString(ss.str());
			//std::cout << "Player1=  " << player1score << std::endl;
		}
		if (intersects(Ball, outright))
		{
			//			player2score++;
			Ball.setPosition(585, 290);
		}
		if (intersects(Ball, up) || (intersects(Ball, down))) {
			ballSpeed.y = -ballSpeed.y;
		}
		if (intersects(Ball, Player) || (intersects(Ball, Player2))) {
			ballSpeed.x = -ballSpeed.x;
		}
		Ball.move(ballSpeed.x, ballSpeed.y);
		if (Ball.getPosition().x > 1080.0f)

		{
			//int score1 = 0;
			score1++;
			Ball.setPosition(585.0f, 320.0f);
			//	cout << "SCORE : " << score1 << endl;
			ostringstream sscore;
			sscore << "Goals :" << score1;
			playerscore.setString(sscore.str());

		}
		ostringstream sscore;
		sscore << "Goals :" << score1;
		playerscore.setString(sscore.str());

		// DRAWING
		//
		//

		Player.setFillColor(Color::Blue);
		Player2.setFillColor(Color::Red);

		window2.draw(Field);
		window2.draw(Player);
		window2.draw(playerscore);
		window2.draw(Player2);
		window2.draw(Ball);
		window2.draw(down);
		window2.draw(up);
		window2.draw(outleft);
		window2.draw(outright);
		window2.draw(mytext);
		window2.display();
	}
	/////////////////////////
	/////////////////////////////////////////////////
	/////////////////

	while (window3.isOpen())
	{
		sf::Event event;
		while (window3.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window3.close();
		}



		///////////////
		////////////////////////////////
		////////////////////////////////
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			Player.move(-Playerspeed1, 0.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			Player.move(Playerspeed1, 0.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			Player.move(0.0f, Playerspeed1);
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			Player.move(0.0f, -Playerspeed1);
		}
		////////////////////////////////////////////////////////////////////////////

		///////////////
		////////////////////////////////
		////////////////////////////////
		if (Keyboard::isKeyPressed(Keyboard::J))
		{
			Player2.move(-Playerspeed1, 0.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::L))
		{
			Player2.move(Playerspeed1, 0.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::K))
		{
			Player2.move(0.0f, Playerspeed1);
		}
		if (Keyboard::isKeyPressed(Keyboard::I))
		{
			Player2.move(0.0f, -Playerspeed1);
		}
		////////////////////////////////////////////////////////////////////////////













		/////////////////////
		////////////////                        Splayer 
		//////////////////////////////////////////////////////////






		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			splayer.move(0.0f, Playerspeed1);
			splayer.setTextureRect(IntRect(count*textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));

		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			splayer.move(-Playerspeed1, 0.0f);
			splayer.setTextureRect(IntRect(count*textureSize.x * 1, textureSize.y * 1, textureSize.x, textureSize.y));

		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			splayer.move(Playerspeed1, 0.0f);
			splayer.setTextureRect(IntRect(count*textureSize.x * 2, textureSize.y * 2, textureSize.x, textureSize.y));
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			splayer.move(0.0f, -Playerspeed1);
			splayer.setTextureRect(IntRect(count*textureSize.x * 3, textureSize.y * 3, textureSize.x, textureSize.y));
		}
		count++;
		if (count == 3)
		{
			count = 0;

		}




		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			splayer2.move(0.0f, Playerspeed1);
			splayer2.setTextureRect(IntRect(count*textureSize2.x * 0, textureSize2.y * 0, textureSize2.x, textureSize2.y));

		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			splayer2.move(-Playerspeed1, 0.0f);
			splayer2.setTextureRect(IntRect(count*textureSize2.x * 1, textureSize2.y * 1, textureSize2.x, textureSize2.y));

		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			splayer2.move(Playerspeed1, 0.0f);
			splayer2.setTextureRect(IntRect(count*textureSize2.x * 2, textureSize2.y * 2, textureSize2.x, textureSize2.y));
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			splayer2.move(0.0f, -Playerspeed1);
			splayer2.setTextureRect(IntRect(count*textureSize2.x * 3, textureSize2.y * 3, textureSize2.x, textureSize2.y));
		}
		count++;
		if (count == 3)
		{
			count = 0;

		}


		if (Player.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			if (Keyboard::isKeyPressed(Keyboard::D))
				Ball.move(Playerspeed1, 0.0f);

			if (Keyboard::isKeyPressed(Keyboard::A))
				Ball.move(-Playerspeed1, 0.0f);

			if (Keyboard::isKeyPressed(Keyboard::W))
				Ball.move(0.0f, -Playerspeed1);

			if (Keyboard::isKeyPressed(Keyboard::S))
				Ball.move(0.0f, Playerspeed1);

			if (Keyboard::isKeyPressed(Keyboard::G))
				Ball.move(0.9f, 0.0f);
		}
		///
		///         Football moved by Player2
		///
		//
		if (Player2.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{

			if (Keyboard::isKeyPressed(Keyboard::L))
				Ball.move(Playerspeed2, 0.0f);

			if (Keyboard::isKeyPressed(Keyboard::J))
				Ball.move(-Playerspeed2, 0.0f);

			if (Keyboard::isKeyPressed(Keyboard::I))
				Ball.move(0.0f, -Playerspeed2);

			if (Keyboard::isKeyPressed(Keyboard::K))
				Ball.move(0.0f, Playerspeed2);


		}
		//if (Player.getGlobalBounds().intersects(Ball.getGlobalBounds()) || Player2.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		//{

		if (Keyboard::isKeyPressed(Keyboard::G) && (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::L) || Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::M)))
		{
			//Ball.setPosition(Vector2f(200.0f, 1000.0f));
			Ball.move(01.5f, 0.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::H) && (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::J) || Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::B)))
		{
			Ball.move(-0.9f, 0.0f);
		}

		if (Keyboard::isKeyPressed(Keyboard::G) && (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::J)))
		{
			Ball.move(-0.9f, 0.0f);
		}
		//}
		//if (Keyboard::isKeyPressed(Keyboard::G))
		//{
		//	Ball.move(0.9f, 0.0f);
		//}

		if (intersects(Ball, outleft))
		{
			//player1score++;
			score2++;
			Ball.setPosition(585, 290);
			std::stringstream ss;
			ss << "Goals :" << score2;
			mytext.setString(ss.str());
			//std::cout << "Player1=  " << player1score << std::endl;
		}

		if (Ball.getPosition().x > 1080.0f)

		{
			//int score1 = 0;
			score1++;
			Ball.setPosition(585.0f, 320.0f);
			//	cout << "SCORE : " << score1 << endl;
			ostringstream sscore;
			sscore << "Goals :" << score1;
			playerscore.setString(sscore.str());

		}
		ostringstream sscore;
		sscore << "Goals :" << score1;
		playerscore.setString(sscore.str());

		splayer6.setPosition(100, 290);


		window3.draw(outleft);
		window3.draw(Field);
		window3.draw(playerscore);
		window3.draw(mytext);
		window3.draw(Player);
		window3.draw(Ball);
		window3.draw(Player2);
		window3.display();
		window3.clear();

		/////////////////////////////
		//////////////////////////////////////////////////////  //////////////////////////////////////////////////////     
		/////////////////////////////////////

	}


	/////////////////////////
	/////////////////////////////////////////////////
	/////////////////

	while (window4.isOpen())
	{



		sf::Event event;
		while (window4.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window4.close();
		}
		/////////////////////

		////////////////////////////////////////////////////////////////////////////
		// BALL MOVEMENT
		//
		//

		/*if (Keyboard::isKeyPressed(Keyboard::Down))
		{
		splayer.move(0.0f, Playerspeed1);
		splayer.setTextureRect(IntRect(count*textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));

		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
		splayer.move(-Playerspeed1, 0.0f);
		splayer.setTextureRect(IntRect(count*textureSize.x * 1, textureSize.y * 1, textureSize.x, textureSize.y));

		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
		splayer.move(Playerspeed1, 0.0f);
		splayer.setTextureRect(IntRect(count*textureSize.x * 2, textureSize.y * 2, textureSize.x, textureSize.y));
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
		splayer.move(0.0f, -Playerspeed1);
		splayer.setTextureRect(IntRect(count*textureSize.x * 3, textureSize.y * 3, textureSize.x, textureSize.y));
		}
		count++;
		if (count == 3)
		{
		count = 0;

		}*/
		/////////////////////
		/////////////////////////////////////

		//////////////
		///////////////////////////////////////
		/////////////
		int c = 0;
		if (!splayer.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			c = 0;
		}
		if (splayer.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			c = 1;
		}
		else if (splayer2.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			c = 2;
		}
		else if (splayer3.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			c = 3;
		}
		else if (splayer4.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			c = 4;
		}
		else if (splayer5.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			c = 5;
		}

		switch (c)
		{
		case 0:
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				splayer.move(0.0f, Playerspeed1);
				splayer.setTextureRect(IntRect(count*textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				splayer.move(-Playerspeed1, 0.0f);
				splayer.setTextureRect(IntRect(count*textureSize.x * 1, textureSize.y * 1, textureSize.x, textureSize.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				splayer.move(Playerspeed1, 0.0f);
				splayer.setTextureRect(IntRect(count*textureSize.x * 2, textureSize.y * 2, textureSize.x, textureSize.y));
			}

			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				splayer.move(0.0f, -Playerspeed1);
				splayer.setTextureRect(IntRect(count*textureSize.x * 3, textureSize.y * 3, textureSize.x, textureSize.y));
			}
			count++;
			if (count == 3)
			{
				count = 0;

			}
			break;
		case 1:
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				splayer.move(0.0f, Playerspeed1);
				splayer.setTextureRect(IntRect(count*textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				splayer.move(-Playerspeed1, 0.0f);
				splayer.setTextureRect(IntRect(count*textureSize.x * 1, textureSize.y * 1, textureSize.x, textureSize.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				splayer.move(Playerspeed1, 0.0f);
				splayer.setTextureRect(IntRect(count*textureSize.x * 2, textureSize.y * 2, textureSize.x, textureSize.y));
			}

			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				splayer.move(0.0f, -Playerspeed1);
				splayer.setTextureRect(IntRect(count*textureSize.x * 3, textureSize.y * 3, textureSize.x, textureSize.y));
			}
			count++;
			if (count == 3)
			{
				count = 0;

			}
			break;

		case 2:
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				splayer2.move(0.0f, Playerspeed1);
				splayer2.setTextureRect(IntRect(count*textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				splayer2.move(-Playerspeed1, 0.0f);
				splayer2.setTextureRect(IntRect(count*textureSize.x * 1, textureSize.y * 1, textureSize.x, textureSize.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				splayer2.move(Playerspeed1, 0.0f);
				splayer2.setTextureRect(IntRect(count*textureSize.x * 2, textureSize.y * 2, textureSize.x, textureSize.y));
			}

			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				splayer2.move(0.0f, -Playerspeed1);
				splayer2.setTextureRect(IntRect(count*textureSize.x * 3, textureSize.y * 3, textureSize.x, textureSize.y));
			}
			count++;
			if (count == 3)
			{
				count = 0;

			}
			break;

		case 3:
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				splayer3.move(0.0f, Playerspeed1);
				splayer3.setTextureRect(IntRect(count*textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				splayer3.move(-Playerspeed1, 0.0f);
				splayer3.setTextureRect(IntRect(count*textureSize.x * 1, textureSize.y * 1, textureSize.x, textureSize.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				splayer3.move(Playerspeed1, 0.0f);
				splayer3.setTextureRect(IntRect(count*textureSize.x * 2, textureSize.y * 2, textureSize.x, textureSize.y));
			}

			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				splayer3.move(0.0f, -Playerspeed1);
				splayer3.setTextureRect(IntRect(count*textureSize.x * 3, textureSize.y * 3, textureSize.x, textureSize.y));
			}
			count++;
			if (count == 3)
			{
				count = 0;

			}
			break;
		case 4:
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				splayer4.move(0.0f, Playerspeed1);
				splayer4.setTextureRect(IntRect(count*textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				splayer4.move(-Playerspeed1, 0.0f);
				splayer4.setTextureRect(IntRect(count*textureSize.x * 1, textureSize.y * 1, textureSize.x, textureSize.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				splayer4.move(Playerspeed1, 0.0f);
				splayer4.setTextureRect(IntRect(count*textureSize.x * 2, textureSize.y * 2, textureSize.x, textureSize.y));
			}

			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				splayer4.move(0.0f, -Playerspeed1);
				splayer4.setTextureRect(IntRect(count*textureSize.x * 3, textureSize.y * 3, textureSize.x, textureSize.y));
			}
			count++;
			if (count == 3)
			{
				count = 0;

			}
			break;
		case 5:
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				splayer5.move(0.0f, Playerspeed1);
				splayer5.setTextureRect(IntRect(count*textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				splayer5.move(-Playerspeed1, 0.0f);
				splayer5.setTextureRect(IntRect(count*textureSize.x * 1, textureSize.y * 1, textureSize.x, textureSize.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				splayer5.move(Playerspeed1, 0.0f);
				splayer5.setTextureRect(IntRect(count*textureSize.x * 2, textureSize.y * 2, textureSize.x, textureSize.y));
			}

			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				splayer5.move(0.0f, -Playerspeed1);
				splayer5.setTextureRect(IntRect(count*textureSize.x * 3, textureSize.y * 3, textureSize.x, textureSize.y));
			}
			count++;
			if (count == 3)
			{
				count = 0;

			}
			break;

		}

		//////////////////////////////////
		/////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////
		///////////////////////


		//////////////
		///////////////////////////////////////
		/////////////
		int c1 = 0;
		if (!splayer6.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			c = 0;
		}
		if (splayer6.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			c = 1;
		}
		else if (splayer7.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			c = 2;
		}
		else if (splayer8.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			c = 3;
		}
		else if (splayer9.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			c = 4;
		}
		else if (splayer0.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			c = 5;
		}

		switch (c)
		{
		case 0:
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				splayer6.move(0.0f, Playerspeed1);
				splayer6.setTextureRect(IntRect(count*textureSize6.x * 0, textureSize6.y * 0, textureSize6.x, textureSize6.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				splayer6.move(-Playerspeed1, 0.0f);
				splayer6.setTextureRect(IntRect(count*textureSize6.x * 1, textureSize6.y * 1, textureSize6.x, textureSize6.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				splayer6.move(Playerspeed1, 0.0f);
				splayer6.setTextureRect(IntRect(count*textureSize6.x * 2, textureSize6.y * 2, textureSize6.x, textureSize6.y));
			}

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				splayer6.move(0.0f, -Playerspeed1);
				splayer6.setTextureRect(IntRect(count*textureSize6.x * 1, textureSize6.y * 1, textureSize6.x, textureSize6.y));
			}
			count++;
			if (count == 3)
			{
				count = 0;

			}
			break;
		case 1:
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				splayer6.move(0.0f, Playerspeed1);
				splayer6.setTextureRect(IntRect(count*textureSize6.x * 0, textureSize6.y * 0, textureSize6.x, textureSize6.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				splayer6.move(-Playerspeed1, 0.0f);
				splayer6.setTextureRect(IntRect(count*textureSize6.x * 1, textureSize6.y * 1, textureSize6.x, textureSize6.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				splayer6.move(Playerspeed1, 0.0f);
				splayer6.setTextureRect(IntRect(count*textureSize6.x * 2, textureSize6.y * 2, textureSize6.x, textureSize6.y));
			}

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				splayer6.move(0.0f, -Playerspeed1);
				splayer6.setTextureRect(IntRect(count*textureSize6.x * 1, textureSize6.y * 1, textureSize6.x, textureSize6.y));
			}
			count++;
			if (count == 3)
			{
				count = 0;

			}
			break;

		case 2:
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				splayer7.move(0.0f, Playerspeed1);
				splayer7.setTextureRect(IntRect(count*textureSize6.x * 0, textureSize6.y * 0, textureSize6.x, textureSize6.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				splayer7.move(-Playerspeed1, 0.0f);
				splayer7.setTextureRect(IntRect(count*textureSize6.x * 1, textureSize6.y * 1, textureSize6.x, textureSize6.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				splayer7.move(Playerspeed1, 0.0f);
				splayer7.setTextureRect(IntRect(count*textureSize6.x * 2, textureSize6.y * 2, textureSize6.x, textureSize6.y));
			}

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				splayer7.move(0.0f, -Playerspeed1);
				splayer7.setTextureRect(IntRect(count*textureSize6.x * 1, textureSize6.y * 1, textureSize6.x, textureSize6.y));
			}
			count++;
			if (count == 3)
			{
				count = 0;

			}
			break;

		case 3:
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				splayer8.move(0.0f, Playerspeed1);
				splayer8.setTextureRect(IntRect(count*textureSize6.x * 0, textureSize6.y * 0, textureSize6.x, textureSize6.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				splayer8.move(-Playerspeed1, 0.0f);
				splayer8.setTextureRect(IntRect(count*textureSize6.x * 1, textureSize6.y * 1, textureSize6.x, textureSize6.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				splayer8.move(Playerspeed1, 0.0f);
				splayer8.setTextureRect(IntRect(count*textureSize6.x * 2, textureSize6.y * 2, textureSize6.x, textureSize6.y));
			}

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				splayer8.move(0.0f, -Playerspeed1);
				splayer8.setTextureRect(IntRect(count*textureSize6.x * 1, textureSize6.y * 1, textureSize6.x, textureSize6.y));
			}
			count++;
			if (count == 3)
			{
				count = 0;

			}
			break;
		case 4:
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				splayer9.move(0.0f, Playerspeed1);
				splayer9.setTextureRect(IntRect(count*textureSize6.x * 0, textureSize6.y * 0, textureSize6.x, textureSize6.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				splayer9.move(-Playerspeed1, 0.0f);
				splayer9.setTextureRect(IntRect(count*textureSize6.x * 1, textureSize6.y * 1, textureSize6.x, textureSize6.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				splayer9.move(Playerspeed1, 0.0f);
				splayer9.setTextureRect(IntRect(count*textureSize6.x * 2, textureSize6.y * 2, textureSize6.x, textureSize6.y));
			}

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				splayer9.move(0.0f, -Playerspeed1);
				splayer9.setTextureRect(IntRect(count*textureSize6.x * 1, textureSize6.y * 1, textureSize6.x, textureSize6.y));
			}
			count++;
			if (count == 3)
			{
				count = 0;

			}
			break;
		case 5:
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				splayer0.move(0.0f, Playerspeed1);
				splayer0.setTextureRect(IntRect(count*textureSize6.x * 0, textureSize6.y * 0, textureSize6.x, textureSize6.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				splayer0.move(-Playerspeed1, 0.0f);
				splayer0.setTextureRect(IntRect(count*textureSize6.x * 1, textureSize6.y * 1, textureSize6.x, textureSize6.y));

			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				splayer0.move(Playerspeed1, 0.0f);
				splayer0.setTextureRect(IntRect(count*textureSize6.x * 2, textureSize6.y * 2, textureSize6.x, textureSize6.y));
			}

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				splayer0.move(0.0f, -Playerspeed1);
				splayer0.setTextureRect(IntRect(count*textureSize6.x * 1, textureSize6.y * 1, textureSize6.x, textureSize6.y));
			}
			count++;
			if (count == 3)
			{
				count = 0;

			}
			break;

		}














		//////////////////////
		/////////////////////////////////
		////////////////////////////////////////////////////          NEW YAKII

		//////////////////////////////////////////////////////////////////
		///////////////////////////////////
		//////////////////                        Sprite Player 2 Yaki
		////////////////////////

		//	if (Ball.getPosition(Vector2f(1050.0f,0.0f))
		//{
		//	score1++;
		//}



		///////////////
		///////////////

		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			splayer2.move(0.0f, Playerspeed1);
			splayer2.setTextureRect(IntRect(count*textureSize2.x * 0, textureSize2.y * 0, textureSize2.x, textureSize2.y));

		}
		if (Keyboard::isKeyPressed(Keyboard::B))
		{
			splayer2.move(-Playerspeed1, 0.0f);
			splayer2.setTextureRect(IntRect(count*textureSize2.x * 1, textureSize2.y * 1, textureSize2.x, textureSize2.y));

		}
		if (Keyboard::isKeyPressed(Keyboard::M))
		{
			splayer2.move(Playerspeed1, 0.0f);
			splayer2.setTextureRect(IntRect(count*textureSize2.x * 2, textureSize2.y * 2, textureSize2.x, textureSize2.y));
		}

		if (Keyboard::isKeyPressed(Keyboard::N))
		{
			splayer2.move(0.0f, -Playerspeed1);
			splayer2.setTextureRect(IntRect(count*textureSize2.x * 3, textureSize2.y * 3, textureSize2.x, textureSize2.y));
		}
		count++;
		if (count == 3)
		{
			count = 0;

		}
		/////////////////////////////////////////////////////////////////]\]]===============================================
		//                              //////////////////        Player2
		//////////////////////////////////////////////////////////////////////////////////////=======0***************
		///////////////////////////////////////////////////////////////////////////////////////////============********************8
		if (Keyboard::isKeyPressed(Keyboard::J))
		{
			Player2.move(-Playerspeed2, 0.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::L))
		{
			Player2.move(Playerspeed2, 0.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::K))
		{
			Player2.move(0.0f, Playerspeed2);
		}
		if (Keyboard::isKeyPressed(Keyboard::I))
		{
			Player2.move(0.0f, -Playerspeed2);
		}

		/*	if (Player.getPosition().x > Ball.getPosition().x)
		{
		Ball.move(0.1f,0.0f);
		Player.move(0.1f,0.0f);
		}

		if (Player.getPosition().x < Ball.getPosition().x)
		{
		Ball.move(-0.1f, 0.0f);
		Player.move(-0.1f, 0.0f);
		}
		*/
		RectangleShape Field1(Vector2f(1200.0f, 35.0f));

		if (splayer.getGlobalBounds().intersects(Field1.getGlobalBounds()) && splayer.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			splayer.move(0.0f, 0.5f);
			Ball.move(0.0f, 0.5f);
		}



		/// 
		///         Football moved by Player 
		///
		//
		if (splayer6.getGlobalBounds().intersects(Field1.getGlobalBounds()) && splayer6.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			splayer6.move(0.0f, 0.5f);
			Ball.move(0.0f, 0.5f);
		}



		/// 
		///         Football moved by Player2 
		///
		//
		if (Player2.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{

			if (Keyboard::isKeyPressed(Keyboard::L))
				Ball.move(Playerspeed2, 0.0f);

			if (Keyboard::isKeyPressed(Keyboard::J))
				Ball.move(-Playerspeed2, 0.0f);

			if (Keyboard::isKeyPressed(Keyboard::I))
				Ball.move(0.0f, -Playerspeed2);

			if (Keyboard::isKeyPressed(Keyboard::K))
				Ball.move(0.0f, Playerspeed2);


		}
		//if (Player.getGlobalBounds().intersects(Ball.getGlobalBounds()) || Player2.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		//{

		if (Keyboard::isKeyPressed(Keyboard::G) && (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::L) || Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::M)))
		{
			//Ball.setPosition(Vector2f(200.0f, 1000.0f));
			Ball.move(01.5f, 0.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::H) && (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::J) || Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::B)))
		{
			Ball.move(-0.9f, 0.0f);
		}

		/*if (Keyboard::isKeyPressed(Keyboard::G) &&( Keyboard::isKeyPressed(Keyboard::A)|| Keyboard::isKeyPressed(Keyboard::J)))
		{
		Ball.move(-0.9f, 0.0f);
		}*/
		//}
		//if (Keyboard::isKeyPressed(Keyboard::G))
		//{
		//	Ball.move(0.9f, 0.0f);
		//}

		/////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
												///////////                     Sprite YAki movement
//////

//		int c;
		if (splayer.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			if (Keyboard::isKeyPressed(Keyboard::Right))
				Ball.move(Playerspeed1, 0.0f);

			if (Keyboard::isKeyPressed(Keyboard::Left))
				Ball.move(-Playerspeed1, 0.0f);

			if (Keyboard::isKeyPressed(Keyboard::Up))
				Ball.move(0.0f, -Playerspeed1);

			if (Keyboard::isKeyPressed(Keyboard::Down))
				Ball.move(0.0f, Playerspeed1);

			if (Keyboard::isKeyPressed(Keyboard::G))
				Ball.move(0.9f, 0.0f);
		}

		/////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////

		if (splayer6.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			if (Keyboard::isKeyPressed(Keyboard::D))
				Ball.move(Playerspeed1, 0.0f);

			if (Keyboard::isKeyPressed(Keyboard::A))
				Ball.move(-Playerspeed1, 0.0f);


			if (Keyboard::isKeyPressed(Keyboard::W))
				Ball.move(0.0f, -Playerspeed1);

			if (Keyboard::isKeyPressed(Keyboard::S))
				Ball.move(0.0f, Playerspeed1);

			if (Keyboard::isKeyPressed(Keyboard::G))
				Ball.move(0.9f, 0.0f);
		}



		if (splayer2.getGlobalBounds().intersects(Ball.getGlobalBounds()) || splayer3.getGlobalBounds().intersects(Ball.getGlobalBounds()) || splayer4.getGlobalBounds().intersects(Ball.getGlobalBounds()) || splayer5.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			if (Keyboard::isKeyPressed(Keyboard::Right))
				Ball.move(Playerspeed1, 0.0f);

			if (Keyboard::isKeyPressed(Keyboard::Left))
				Ball.move(-Playerspeed1, 0.0f);

			if (Keyboard::isKeyPressed(Keyboard::Up))
				Ball.move(0.0f, -Playerspeed1);

			if (Keyboard::isKeyPressed(Keyboard::Down))
				Ball.move(0.0f, Playerspeed1);

			if (Keyboard::isKeyPressed(Keyboard::G))
				Ball.move(0.9f, 0.0f);
		}






		if (splayer7.getGlobalBounds().intersects(Ball.getGlobalBounds()) || splayer8.getGlobalBounds().intersects(Ball.getGlobalBounds()) || splayer9.getGlobalBounds().intersects(Ball.getGlobalBounds()) || splayer0.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			if (Keyboard::isKeyPressed(Keyboard::D))
				Ball.move(Playerspeed1, 0.0f);

			if (Keyboard::isKeyPressed(Keyboard::A))
				Ball.move(-Playerspeed1, 0.0f);

			if (Keyboard::isKeyPressed(Keyboard::W))
				Ball.move(0.0f, -Playerspeed1);

			if (Keyboard::isKeyPressed(Keyboard::S))
				Ball.move(0.0f, Playerspeed1);

			if (Keyboard::isKeyPressed(Keyboard::G))
				Ball.move(0.9f, 0.0f);
		}














		/////////////
		///////////                     Three collision
		//////

		float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		float LO = -0.5;
		float HI = 2.2;
		float r3 = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));

		float L = -1.2;
		float H = 2.2;
		float r2 = L + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (H - L)));


		if (Player2.getGlobalBounds().intersects(Player.getGlobalBounds()) && Player2.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			Ball.move(r, 0.8f);
		}
		if (splayer.getGlobalBounds().intersects(Player.getGlobalBounds()) && splayer.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			Ball.move(0.5f, 0.8f);
		}
		if (splayer.getGlobalBounds().intersects(Player2.getGlobalBounds()) && splayer.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			Ball.move(0.5f, 0.8f);
		}
		if (splayer2.getGlobalBounds().intersects(Player.getGlobalBounds()) && splayer2.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			Ball.move(0.5f, 0.8f);
		}
		if (splayer2.getGlobalBounds().intersects(Player2.getGlobalBounds()) && splayer2.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			Ball.move(0.5f, 0.8f);
		}

		if (splayer2.getGlobalBounds().intersects(splayer.getGlobalBounds()) && splayer2.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			if (splayer.getPosition().x < splayer2.getPosition().x)
				Ball.move(0.7f, 0.6f);

			if (splayer.getPosition().x > splayer2.getPosition().x)
				Ball.move(0.5f, -0.8f);

			if (splayer.getPosition().y < splayer2.getPosition().y)
				Ball.move(0.6f, -0.9f);

			if (splayer.getPosition().y > splayer2.getPosition().y)
				Ball.move(0.6f, 0.5f);
		}
		////////////////////////////////////////////////////////////////////////////////----------======0000000000000000000000//////////////
		///////////////////////
		///////////////////////////////////////////PPPPPPPPPPPPPPPPPPPPPAAAAAAAAAAASSSSSSSSS
		///////////////       PASSING



		int pass;
		float d1, d2, d3, d4;
		double d, x0, y0;
		float x1 = Ball.getPosition().x;
		float x2 = splayer.getPosition().x;
		float y1 = Ball.getPosition().y;
		float y2 = splayer.getPosition().y;
		x0 = (x2 - x1)*(x2 - x1);

		y0 = (y2 - y1)*(y2 - y1);

		d1 = sqrt(x0 + y0);

		float x12 = Ball.getPosition().x;
		float x22 = splayer2.getPosition().x;
		float y12 = Ball.getPosition().y;
		float y22 = splayer2.getPosition().y;
		float	x02 = (x22 - x12)*(x22 - x12);

		float y02 = (y2 - y1)*(y2 - y1);

		d2 = sqrt(x02 + y02);




		/////////////////////////////////////////////////////////////////////////

		/////////////////////////////////////////                 SWITTCH YAKI FOR PASSING
		//////////////////////////////////////////////////////////////////////////////

		int z = 0;
		if (Player.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			z = 0;
		}
		if (splayer.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			z = 1;
		}
		else if (splayer2.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			z = 2;
		}
		else if (splayer3.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			z = 3;
		}
		else if (splayer4.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			z = 4;
		}
		else if (splayer5.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			z = 5;
		}

		switch (z)
		{
		case 0:
			if (Keyboard::isKeyPressed(Keyboard::P))
			{
				float q1 = sqrt((splayer.getPosition().x - Ball.getPosition().x)*(splayer.getPosition().x - Ball.getPosition().x)) + (splayer.getPosition().y - Ball.getPosition().y)*(splayer.getPosition().y - Ball.getPosition().y);
				float q2 = sqrt((splayer2.getPosition().x - Ball.getPosition().x)*(splayer2.getPosition().x - Ball.getPosition().x)) + (splayer2.getPosition().y - Ball.getPosition().y)*(splayer2.getPosition().y - Ball.getPosition().y);
				float q3 = sqrt((splayer3.getPosition().x - Ball.getPosition().x)*(splayer3.getPosition().x - Ball.getPosition().x)) + (splayer3.getPosition().y - Ball.getPosition().y)*(splayer3.getPosition().y - Ball.getPosition().y);
				float q4 = sqrt((splayer4.getPosition().x - Ball.getPosition().x)*(splayer4.getPosition().x - Ball.getPosition().x)) + (splayer4.getPosition().y - Ball.getPosition().y)*(splayer4.getPosition().y - Ball.getPosition().y);
				float q5 = sqrt((splayer5.getPosition().x - Ball.getPosition().x)*(splayer5.getPosition().x - Ball.getPosition().x)) + (splayer5.getPosition().y - Ball.getPosition().y)*(splayer5.getPosition().y - Ball.getPosition().y);

				if (q1 < q2&& q1 < q3&&q1 < q4&&q1 < q5)
				{
					Ball.setPosition(Vector2f(splayer.getPosition().x + 10.0f, splayer.getPosition().y + 15.0f));

				}
				else if (q2 < q1&&q2 < q3&&q2 < q4&&q2 < q5)
				{
					Ball.setPosition(Vector2f(splayer2.getPosition().x, splayer2.getPosition().y));

				}
				else if (q3 < q2&&q3 < q1&&q3 < q4&&q3 < q5)
				{
					Ball.setPosition(Vector2f(splayer3.getPosition().x, splayer3.getPosition().y));

				}
				else if (q4 < q3&&q4 < q2&&q4 < q1&&q4 < q5)
				{
					Ball.setPosition(Vector2f(splayer4.getPosition().x, splayer4.getPosition().y));
				}
				else if (q5 < q4&&q5 < q3&&q5 < q2&&q5 < q1)
				{
					Ball.setPosition(Vector2f(splayer5.getPosition().x, splayer5.getPosition().y));

				}
			}
			break;

		case 1:
			if (Keyboard::isKeyPressed(Keyboard::P))
			{
				/*
				if (Ball.getGlobalBounds().intersects(splayer6.getGlobalBounds()))
				{
				float zz1 = sqrt((splayer6.getPosition().x - splayer5.getPosition().x)*(splayer6.getPosition().x - splayer5.getPosition().x) + (splayer6.getPosition().y - splayer5.getPosition().y)*(splayer6.getPosition().y - splayer5.getPosition().y));

				Vector2f zz = Vector2f(splayer6.getPosition()) - Vector2f(splayer5.getPosition());
				float az = sqrt(zz.x*zz.x + zz.y*zz.y);
				Vector2f zzx = (Vector2f(splayer6.getPosition()) - Vector2f(splayer5.getPosition()))/az;

				splayer5.move(zzx.x-0.2, zzx.y-0.2);
				}
				*/
				//	float q1 = sqrt((splayer.getPosition().x - Ball.getPosition().x)*(splayer.getPosition().x - Ball.getPosition().x)) + (splayer.getPosition().y - Ball.getPosition().y)*(splayer.getPosition().y - Ball.getPosition().y);
				float q2 = sqrt((splayer2.getPosition().x - Ball.getPosition().x)*(splayer2.getPosition().x - Ball.getPosition().x)) + (splayer2.getPosition().y - Ball.getPosition().y)*(splayer2.getPosition().y - Ball.getPosition().y);
				float q3 = sqrt((splayer3.getPosition().x - Ball.getPosition().x)*(splayer3.getPosition().x - Ball.getPosition().x)) + (splayer3.getPosition().y - Ball.getPosition().y)*(splayer3.getPosition().y - Ball.getPosition().y);
				float q4 = sqrt((splayer4.getPosition().x - Ball.getPosition().x)*(splayer4.getPosition().x - Ball.getPosition().x)) + (splayer4.getPosition().y - Ball.getPosition().y)*(splayer4.getPosition().y - Ball.getPosition().y);
				float q5 = sqrt((splayer5.getPosition().x - Ball.getPosition().x)*(splayer5.getPosition().x - Ball.getPosition().x)) + (splayer5.getPosition().y - Ball.getPosition().y)*(splayer5.getPosition().y - Ball.getPosition().y);

				//	if ( q2< q3 && q3<q4 && q4&&q1 < q5)
				//{
				//	Ball.setPosition(Vector2f(splayer.getPosition().x + 10.0f, splayer.getPosition().y + 15.0f));
				//}
				float zz1 = sqrt((splayer2.getPosition().x - splayer.getPosition().x)*(splayer2.getPosition().x - splayer.getPosition().x) + (splayer2.getPosition().y - splayer.getPosition().y)*(splayer2.getPosition().y - splayer.getPosition().y));
				Vector2f zz = Vector2f(splayer2.getPosition()) - Vector2f(splayer.getPosition());
				float az = sqrt(zz.x*zz.x + zz.y*zz.y);
				Vector2f zzx = (Vector2f(splayer2.getPosition()) - Vector2f(splayer.getPosition())) / az;
				if (q2 < q3&&q2 < q4&&q2 < q5)
				{
					Ball.move(zzx.x, zzx.y);
				//	Ball.setPosition(Vector2f(splayer2.getPosition().x + 10.0f, splayer2.getPosition().y));

				}
				else if (q3 < q2&&q3 < q4&&q3 < q5)
				{
					Ball.setPosition(Vector2f(splayer3.getPosition().x + 10.0f, splayer3.getPosition().y));

				}
				else if (q4 < q3&&q4 < q2&&q4 < q5)
				{
					Ball.setPosition(Vector2f(splayer4.getPosition().x + 10.0f, splayer4.getPosition().y));
				}
				else if (q5 < q4&&q5 < q3&&q5 < q2)
				{
					Ball.setPosition(Vector2f(splayer5.getPosition().x + 10.0f, splayer5.getPosition().y));

				}
			}
			break;

		case 2:
			if (Keyboard::isKeyPressed(Keyboard::P))
			{
				float q1 = sqrt((splayer.getPosition().x - Ball.getPosition().x)*(splayer.getPosition().x - Ball.getPosition().x)) + (splayer.getPosition().y - Ball.getPosition().y)*(splayer.getPosition().y - Ball.getPosition().y);
				//float q2 = sqrt((splayer2.getPosition().x - Ball.getPosition().x)*(splayer2.getPosition().x - Ball.getPosition().x)) + (splayer2.getPosition().y - Ball.getPosition().y)*(splayer2.getPosition().y - Ball.getPosition().y);
				float q3 = sqrt((splayer3.getPosition().x - Ball.getPosition().x)*(splayer3.getPosition().x - Ball.getPosition().x)) + (splayer3.getPosition().y - Ball.getPosition().y)*(splayer3.getPosition().y - Ball.getPosition().y);
				float q4 = sqrt((splayer4.getPosition().x - Ball.getPosition().x)*(splayer4.getPosition().x - Ball.getPosition().x)) + (splayer4.getPosition().y - Ball.getPosition().y)*(splayer4.getPosition().y - Ball.getPosition().y);
				float q5 = sqrt((splayer5.getPosition().x - Ball.getPosition().x)*(splayer5.getPosition().x - Ball.getPosition().x)) + (splayer5.getPosition().y - Ball.getPosition().y)*(splayer5.getPosition().y - Ball.getPosition().y);

				if (q1 < q3 && q1 < q4 &&q1 < q5)
				{
					Ball.setPosition(Vector2f(splayer.getPosition().x + 10.0f, splayer.getPosition().y + 15.0f));
				}


				else if (q3 < q1 && q3 < q4 &&q3 < q5)
				{
					Ball.setPosition(Vector2f(splayer3.getPosition().x + 10.0f, splayer3.getPosition().y));

				}
				else if (q4 < q1 && q4 < q3&&q4 < q5)
				{
					Ball.setPosition(Vector2f(splayer4.getPosition().x + 10.0f, splayer4.getPosition().y));
				}
				else if (q5 < q1 && q5 < q4 && q5 < q3)
				{
					Ball.setPosition(Vector2f(splayer5.getPosition().x + 10.0f, splayer5.getPosition().y));

				}
			}
			break;

		case 3:
			if (Keyboard::isKeyPressed(Keyboard::P))
			{
				float q1 = sqrt((splayer.getPosition().x - Ball.getPosition().x)*(splayer.getPosition().x - Ball.getPosition().x)) + (splayer.getPosition().y - Ball.getPosition().y)*(splayer.getPosition().y - Ball.getPosition().y);
				float q2 = sqrt((splayer2.getPosition().x - Ball.getPosition().x)*(splayer2.getPosition().x - Ball.getPosition().x)) + (splayer2.getPosition().y - Ball.getPosition().y)*(splayer2.getPosition().y - Ball.getPosition().y);
				//float q3 = sqrt((splayer3.getPosition().x - Ball.getPosition().x)*(splayer3.getPosition().x - Ball.getPosition().x)) + (splayer3.getPosition().y - Ball.getPosition().y)*(splayer3.getPosition().y - Ball.getPosition().y);
				float q4 = sqrt((splayer4.getPosition().x - Ball.getPosition().x)*(splayer4.getPosition().x - Ball.getPosition().x)) + (splayer4.getPosition().y - Ball.getPosition().y)*(splayer4.getPosition().y - Ball.getPosition().y);
				float q5 = sqrt((splayer5.getPosition().x - Ball.getPosition().x)*(splayer5.getPosition().x - Ball.getPosition().x)) + (splayer5.getPosition().y - Ball.getPosition().y)*(splayer5.getPosition().y - Ball.getPosition().y);

				//	if ( q2< q3 && q3<q4 && q4&&q1 < q5)
				//{
				//	Ball.setPosition(Vector2f(splayer.getPosition().x + 10.0f, splayer.getPosition().y + 15.0f));
				//}


				if (q1 < q2 && q1 < q4 &&q1 < q5)
				{
					Ball.setPosition(Vector2f(splayer.getPosition().x + 10.0f, splayer.getPosition().y + 15.0f));
				}


				else if (q2 < q1 && q2 < q4 &&q2 < q5)
				{
					Ball.setPosition(Vector2f(splayer2.getPosition().x + 10.0f, splayer2.getPosition().y));

				}
				else if (q4 < q1 && q4 < q2&&q4 < q5)
				{
					Ball.setPosition(Vector2f(splayer4.getPosition().x + 10.0f, splayer4.getPosition().y));
				}
				else if (q5 < q1 && q5 < q4 && q5 < q2)
				{
					Ball.setPosition(Vector2f(splayer5.getPosition().x + 10.0f, splayer5.getPosition().y));

				}
			}
			break;
		case 4:

			if (Keyboard::isKeyPressed(Keyboard::P))
			{
				float q1 = sqrt((splayer.getPosition().x - Ball.getPosition().x)*(splayer.getPosition().x - Ball.getPosition().x)) + (splayer.getPosition().y - Ball.getPosition().y)*(splayer.getPosition().y - Ball.getPosition().y);
				float q2 = sqrt((splayer2.getPosition().x - Ball.getPosition().x)*(splayer2.getPosition().x - Ball.getPosition().x)) + (splayer2.getPosition().y - Ball.getPosition().y)*(splayer2.getPosition().y - Ball.getPosition().y);
				float q3 = sqrt((splayer3.getPosition().x - Ball.getPosition().x)*(splayer3.getPosition().x - Ball.getPosition().x)) + (splayer3.getPosition().y - Ball.getPosition().y)*(splayer3.getPosition().y - Ball.getPosition().y);
				//float q4 = sqrt((splayer4.getPosition().x - Ball.getPosition().x)*(splayer4.getPosition().x - Ball.getPosition().x)) + (splayer4.getPosition().y - Ball.getPosition().y)*(splayer4.getPosition().y - Ball.getPosition().y);
				float q5 = sqrt((splayer5.getPosition().x - Ball.getPosition().x)*(splayer5.getPosition().x - Ball.getPosition().x)) + (splayer5.getPosition().y - Ball.getPosition().y)*(splayer5.getPosition().y - Ball.getPosition().y);

				//	if ( q2< q3 && q3<q4 && q4&&q1 < q5)
				//{
				//	Ball.setPosition(Vector2f(splayer.getPosition().x + 10.0f, splayer.getPosition().y + 15.0f));
				//}


				if (q1 < q2 && q1 < q3 &&q1 < q5)
				{
					Ball.setPosition(Vector2f(splayer.getPosition().x + 10.0f, splayer.getPosition().y + 15.0f));
				}


				else if (q2 < q1 && q2 < q3 &&q2 < q5)
				{
					Ball.setPosition(Vector2f(splayer2.getPosition().x + 10.0f, splayer2.getPosition().y));

				}
				else if (q3 < q1 && q3 < q2&&q3 < q5)
				{
					Ball.setPosition(Vector2f(splayer3.getPosition().x + 10.0f, splayer3.getPosition().y));
				}
				else if (q5 < q1 && q5 < q3 && q5 < q2)
				{
					Ball.setPosition(Vector2f(splayer5.getPosition().x + 10.0f, splayer5.getPosition().y));

				}
			}

			break;
		case 5:

			if (Keyboard::isKeyPressed(Keyboard::P))
			{
				float q1 = sqrt((splayer.getPosition().x - Ball.getPosition().x)*(splayer.getPosition().x - Ball.getPosition().x)) + (splayer.getPosition().y - Ball.getPosition().y)*(splayer.getPosition().y - Ball.getPosition().y);
				float q2 = sqrt((splayer2.getPosition().x - Ball.getPosition().x)*(splayer2.getPosition().x - Ball.getPosition().x)) + (splayer2.getPosition().y - Ball.getPosition().y)*(splayer2.getPosition().y - Ball.getPosition().y);
				float q3 = sqrt((splayer3.getPosition().x - Ball.getPosition().x)*(splayer3.getPosition().x - Ball.getPosition().x)) + (splayer3.getPosition().y - Ball.getPosition().y)*(splayer3.getPosition().y - Ball.getPosition().y);
				float q4 = sqrt((splayer4.getPosition().x - Ball.getPosition().x)*(splayer4.getPosition().x - Ball.getPosition().x)) + (splayer4.getPosition().y - Ball.getPosition().y)*(splayer4.getPosition().y - Ball.getPosition().y);
				//float q5 = sqrt((splayer5.getPosition().x - Ball.getPosition().x)*(splayer5.getPosition().x - Ball.getPosition().x)) + (splayer5.getPosition().y - Ball.getPosition().y)*(splayer5.getPosition().y - Ball.getPosition().y);

				//	if ( q2< q3 && q3<q4 && q4&&q1 < q5)
				//{
				//	Ball.setPosition(Vector2f(splayer.getPosition().x + 10.0f, splayer.getPosition().y + 15.0f));
				//}


				if (q1 < q2 && q1 < q4 &&q1 < q3)
				{
					Ball.setPosition(Vector2f(splayer.getPosition().x + 10.0f, splayer.getPosition().y + 15.0f));
				}


				else if (q2 < q1 && q2 < q4 &&q2 < q3)
				{
					Ball.setPosition(Vector2f(splayer2.getPosition().x + 10.0f, splayer2.getPosition().y));

				}
				else if (q3 < q1 && q3 < q2&&q3 < q4)
				{
					Ball.setPosition(Vector2f(splayer3.getPosition().x + 10.0f, splayer3.getPosition().y));
				}
				else if (q4 < q1 && q4 < q2 && q4 < q3)
				{
					Ball.setPosition(Vector2f(splayer4.getPosition().x + 10.0f, splayer4.getPosition().y));

				}
			}
			break;



		}
		if (Ball.getPosition().x > 1080.0f)

		{


			//int score1 = 0;
			score1++;
			Ball.setPosition(585.0f, 320.0f);
			cout << "SCORE : " << score1 << endl;
			ostringstream sscore;
			sscore << "Goals :" << score1;
			playerscore.setString(sscore.str());

		}
		ostringstream sscore;
		sscore << "Goals :" << score1;
		playerscore.setString(sscore.str());



		if (Ball.getPosition().x <100.0f)

		{


			//int score1 = 0;
			score2++;
			Ball.setPosition(585.0f, 320.0f);
			cout << "SCORE : " << score2 << endl;
			ostringstream sscore1;
			sscore1 << "Goals :" << score2;
			mytext.setString(sscore1.str());

		}
		ostringstream sscore1;
		sscore1 << "Goals :" << score2;
		mytext.setString(sscore1.str());



		// DRAWING
		//
		//

		Player.setFillColor(Color::Blue);
		Player2.setFillColor(Color::Red);

		int z1 = 0;
		if (Player2.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			z1 = 0;
		}
		if (splayer6.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			z1 = 1;
		}
		else if (splayer7.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			z1 = 2;
		}
		else if (splayer8.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			z1 = 3;
		}
		else if (splayer9.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			z1 = 4;
		}
		else if (splayer0.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			z1 = 5;
		}

		switch (z1)
		{
		case 0:
			if (Keyboard::isKeyPressed(Keyboard::O))
			{
				float q11 = sqrt((splayer6.getPosition().x - Ball.getPosition().x)*(splayer6.getPosition().x - Ball.getPosition().x)) + (splayer6.getPosition().y - Ball.getPosition().y)*(splayer6.getPosition().y - Ball.getPosition().y);
				float q21 = sqrt((splayer7.getPosition().x - Ball.getPosition().x)*(splayer7.getPosition().x - Ball.getPosition().x)) + (splayer7.getPosition().y - Ball.getPosition().y)*(splayer7.getPosition().y - Ball.getPosition().y);
				float q31 = sqrt((splayer8.getPosition().x - Ball.getPosition().x)*(splayer8.getPosition().x - Ball.getPosition().x)) + (splayer8.getPosition().y - Ball.getPosition().y)*(splayer8.getPosition().y - Ball.getPosition().y);
				float q41 = sqrt((splayer9.getPosition().x - Ball.getPosition().x)*(splayer9.getPosition().x - Ball.getPosition().x)) + (splayer9.getPosition().y - Ball.getPosition().y)*(splayer9.getPosition().y - Ball.getPosition().y);
				float q51 = sqrt((splayer0.getPosition().x - Ball.getPosition().x)*(splayer0.getPosition().x - Ball.getPosition().x)) + (splayer0.getPosition().y - Ball.getPosition().y)*(splayer0.getPosition().y - Ball.getPosition().y);

				if (q11 < q21&& q11 < q31&&q11 < q41&&q11 < q51)
				{
					Ball.setPosition(Vector2f(splayer6.getPosition().x + 10.0f, splayer6.getPosition().y + 15.0f));

				}
				else if (q21 < q11&&q21 < q31&&q21 < q41&&q21 < q51)
				{
					Ball.setPosition(Vector2f(splayer7.getPosition().x, splayer7.getPosition().y));

				}
				else if (q31 < q21&&q31 < q11&&q31 < q41&&q31 < q51)
				{
					Ball.setPosition(Vector2f(splayer8.getPosition().x, splayer8.getPosition().y));

				}
				else if (q41 < q31&&q41 < q21&&q41 < q11&&q41 < q51)
				{
					Ball.setPosition(Vector2f(splayer9.getPosition().x, splayer9.getPosition().y));
				}
				else if (q51 < q41&&q51 < q31&&q51 < q21&&q51 < q11)
				{
					Ball.setPosition(Vector2f(splayer0.getPosition().x, splayer0.getPosition().y));

				}
			}
			break;

		case 1:
			if (Keyboard::isKeyPressed(Keyboard::O))
			{


				float q11 = sqrt((splayer6.getPosition().x - Ball.getPosition().x)*(splayer6.getPosition().x - Ball.getPosition().x)) + (splayer6.getPosition().y - Ball.getPosition().y)*(splayer6.getPosition().y - Ball.getPosition().y);
				float q21 = sqrt((splayer7.getPosition().x - Ball.getPosition().x)*(splayer7.getPosition().x - Ball.getPosition().x)) + (splayer7.getPosition().y - Ball.getPosition().y)*(splayer7.getPosition().y - Ball.getPosition().y);
				float q31 = sqrt((splayer8.getPosition().x - Ball.getPosition().x)*(splayer8.getPosition().x - Ball.getPosition().x)) + (splayer8.getPosition().y - Ball.getPosition().y)*(splayer8.getPosition().y - Ball.getPosition().y);
				float q41 = sqrt((splayer9.getPosition().x - Ball.getPosition().x)*(splayer9.getPosition().x - Ball.getPosition().x)) + (splayer9.getPosition().y - Ball.getPosition().y)*(splayer9.getPosition().y - Ball.getPosition().y);
				float q51 = sqrt((splayer0.getPosition().x - Ball.getPosition().x)*(splayer0.getPosition().x - Ball.getPosition().x)) + (splayer0.getPosition().y - Ball.getPosition().y)*(splayer0.getPosition().y - Ball.getPosition().y);

				if (q21 < q31&&q21 < q41&&q21 < q51)
				{
					Ball.setPosition(Vector2f(splayer7.getPosition().x + 10.0f, splayer7.getPosition().y));

				}
				else if (q31 < q21&&q31 < q41&&q31 < q51)
				{
					Ball.setPosition(Vector2f(splayer8.getPosition().x + 10.0f, splayer8.getPosition().y));

				}
				else if (q41 < q31&&q41 < q21&&q41 < q51)
				{
					Ball.setPosition(Vector2f(splayer9.getPosition().x + 10.0f, splayer9.getPosition().y));
				}
				else if (q51 < q41&&q51 < q31&&q51 < q21)
				{
					Ball.setPosition(Vector2f(splayer0.getPosition().x + 10.0f, splayer0.getPosition().y));

				}
			}
			break;

		case 2:
			if (Keyboard::isKeyPressed(Keyboard::O))
			{
				float q11 = sqrt((splayer6.getPosition().x - Ball.getPosition().x)*(splayer6.getPosition().x - Ball.getPosition().x)) + (splayer6.getPosition().y - Ball.getPosition().y)*(splayer6.getPosition().y - Ball.getPosition().y);
				float q21 = sqrt((splayer7.getPosition().x - Ball.getPosition().x)*(splayer7.getPosition().x - Ball.getPosition().x)) + (splayer7.getPosition().y - Ball.getPosition().y)*(splayer7.getPosition().y - Ball.getPosition().y);
				float q31 = sqrt((splayer8.getPosition().x - Ball.getPosition().x)*(splayer8.getPosition().x - Ball.getPosition().x)) + (splayer8.getPosition().y - Ball.getPosition().y)*(splayer8.getPosition().y - Ball.getPosition().y);
				float q41 = sqrt((splayer9.getPosition().x - Ball.getPosition().x)*(splayer9.getPosition().x - Ball.getPosition().x)) + (splayer9.getPosition().y - Ball.getPosition().y)*(splayer9.getPosition().y - Ball.getPosition().y);
				float q51 = sqrt((splayer0.getPosition().x - Ball.getPosition().x)*(splayer0.getPosition().x - Ball.getPosition().x)) + (splayer0.getPosition().y - Ball.getPosition().y)*(splayer0.getPosition().y - Ball.getPosition().y);

				if (q11 < q31 && q11 < q41 &&q11 < q51)
				{
					Ball.setPosition(Vector2f(splayer6.getPosition().x + 10.0f, splayer6.getPosition().y + 15.0f));
				}


				else if (q31 < q11 && q31 < q41 &&q31 < q51)
				{
					Ball.setPosition(Vector2f(splayer8.getPosition().x + 10.0f, splayer8.getPosition().y));

				}
				else if (q41 < q11 && q41 < q31&&q41 < q51)
				{
					Ball.setPosition(Vector2f(splayer9.getPosition().x + 10.0f, splayer9.getPosition().y));
				}
				else if (q51 < q11 && q51 < q41 && q51 < q31)
				{
					Ball.setPosition(Vector2f(splayer0.getPosition().x + 10.0f, splayer0.getPosition().y));

				}
			}
			break;

		case 3:
			if (Keyboard::isKeyPressed(Keyboard::O))
			{
				float q11 = sqrt((splayer6.getPosition().x - Ball.getPosition().x)*(splayer6.getPosition().x - Ball.getPosition().x)) + (splayer6.getPosition().y - Ball.getPosition().y)*(splayer6.getPosition().y - Ball.getPosition().y);
				float q21 = sqrt((splayer7.getPosition().x - Ball.getPosition().x)*(splayer7.getPosition().x - Ball.getPosition().x)) + (splayer7.getPosition().y - Ball.getPosition().y)*(splayer7.getPosition().y - Ball.getPosition().y);
				float q31 = sqrt((splayer8.getPosition().x - Ball.getPosition().x)*(splayer8.getPosition().x - Ball.getPosition().x)) + (splayer8.getPosition().y - Ball.getPosition().y)*(splayer8.getPosition().y - Ball.getPosition().y);
				float q41 = sqrt((splayer9.getPosition().x - Ball.getPosition().x)*(splayer9.getPosition().x - Ball.getPosition().x)) + (splayer9.getPosition().y - Ball.getPosition().y)*(splayer9.getPosition().y - Ball.getPosition().y);
				float q51 = sqrt((splayer0.getPosition().x - Ball.getPosition().x)*(splayer0.getPosition().x - Ball.getPosition().x)) + (splayer0.getPosition().y - Ball.getPosition().y)*(splayer0.getPosition().y - Ball.getPosition().y);



				if (q11 < q21 && q11 < q41 &&q11 < q51)
				{
					Ball.setPosition(Vector2f(splayer6.getPosition().x + 10.0f, splayer6.getPosition().y + 15.0f));
				}


				else if (q21 < q11 && q21 < q41 &&q21 < q51)
				{
					Ball.setPosition(Vector2f(splayer7.getPosition().x + 10.0f, splayer7.getPosition().y));

				}
				else if (q41 < q11 && q41 < q21&&q41 < q51)
				{
					Ball.setPosition(Vector2f(splayer9.getPosition().x + 10.0f, splayer9.getPosition().y));
				}
				else if (q51 < q11 && q51 < q41 && q51 < q21)
				{
					Ball.setPosition(Vector2f(splayer0.getPosition().x + 10.0f, splayer0.getPosition().y));

				}
			}
			break;
		case 4:

			if (Keyboard::isKeyPressed(Keyboard::O))
			{
				float q11 = sqrt((splayer6.getPosition().x - Ball.getPosition().x)*(splayer6.getPosition().x - Ball.getPosition().x)) + (splayer6.getPosition().y - Ball.getPosition().y)*(splayer6.getPosition().y - Ball.getPosition().y);
				float q21 = sqrt((splayer7.getPosition().x - Ball.getPosition().x)*(splayer7.getPosition().x - Ball.getPosition().x)) + (splayer7.getPosition().y - Ball.getPosition().y)*(splayer7.getPosition().y - Ball.getPosition().y);
				float q31 = sqrt((splayer8.getPosition().x - Ball.getPosition().x)*(splayer8.getPosition().x - Ball.getPosition().x)) + (splayer8.getPosition().y - Ball.getPosition().y)*(splayer8.getPosition().y - Ball.getPosition().y);
				float q41 = sqrt((splayer9.getPosition().x - Ball.getPosition().x)*(splayer9.getPosition().x - Ball.getPosition().x)) + (splayer9.getPosition().y - Ball.getPosition().y)*(splayer9.getPosition().y - Ball.getPosition().y);
				float q51 = sqrt((splayer0.getPosition().x - Ball.getPosition().x)*(splayer0.getPosition().x - Ball.getPosition().x)) + (splayer0.getPosition().y - Ball.getPosition().y)*(splayer0.getPosition().y - Ball.getPosition().y);


				if (q11 < q21 && q11 < q31 &&q11 < q51)
				{
					Ball.setPosition(Vector2f(splayer6.getPosition().x + 10.0f, splayer6.getPosition().y + 15.0f));
				}


				else if (q21 < q11 && q21 < q31 &&q21 < q51)
				{
					Ball.setPosition(Vector2f(splayer7.getPosition().x + 10.0f, splayer7.getPosition().y));

				}
				else if (q31 < q11 && q31 < q21&&q31 < q51)
				{
					Ball.setPosition(Vector2f(splayer8.getPosition().x + 10.0f, splayer8.getPosition().y));
				}
				else if (q51 < q11 && q51 < q31 && q51 < q21)
				{
					Ball.setPosition(Vector2f(splayer0.getPosition().x + 10.0f, splayer0.getPosition().y));

				}
			}

			break;
		case 5:

			if (Keyboard::isKeyPressed(Keyboard::O))
			{
				float q11 = sqrt((splayer6.getPosition().x - Ball.getPosition().x)*(splayer6.getPosition().x - Ball.getPosition().x)) + (splayer6.getPosition().y - Ball.getPosition().y)*(splayer6.getPosition().y - Ball.getPosition().y);
				float q21 = sqrt((splayer7.getPosition().x - Ball.getPosition().x)*(splayer7.getPosition().x - Ball.getPosition().x)) + (splayer7.getPosition().y - Ball.getPosition().y)*(splayer7.getPosition().y - Ball.getPosition().y);
				float q31 = sqrt((splayer8.getPosition().x - Ball.getPosition().x)*(splayer8.getPosition().x - Ball.getPosition().x)) + (splayer8.getPosition().y - Ball.getPosition().y)*(splayer8.getPosition().y - Ball.getPosition().y);
				float q41 = sqrt((splayer9.getPosition().x - Ball.getPosition().x)*(splayer9.getPosition().x - Ball.getPosition().x)) + (splayer9.getPosition().y - Ball.getPosition().y)*(splayer9.getPosition().y - Ball.getPosition().y);
				float q51 = sqrt((splayer0.getPosition().x - Ball.getPosition().x)*(splayer0.getPosition().x - Ball.getPosition().x)) + (splayer0.getPosition().y - Ball.getPosition().y)*(splayer0.getPosition().y - Ball.getPosition().y);


				if (q11 < q21 && q11 < q41 &&q11 < q31)
				{
					Ball.setPosition(Vector2f(splayer6.getPosition().x + 10.0f, splayer6.getPosition().y + 15.0f));
				}


				else if (q21 < q11 && q21 < q41 &&q21 < q31)
				{
					Ball.setPosition(Vector2f(splayer7.getPosition().x + 10.0f, splayer7.getPosition().y));

				}
				else if (q31 < q11 && q31 < q21&&q31 < q41)
				{
					Ball.setPosition(Vector2f(splayer8.getPosition().x + 10.0f, splayer8.getPosition().y));
				}
				else if (q41 < q11 && q41 < q21 && q41 < q31)
				{
					Ball.setPosition(Vector2f(splayer9.getPosition().x + 10.0f, splayer9.getPosition().y));

				}
				break;
			}

		}



	/*	if (Ball.getGlobalBounds().intersects(splayer6.getGlobalBounds()))
		{
			float zz1 = sqrt((splayer6.getPosition().x - splayer5.getPosition().x)*(splayer6.getPosition().x - splayer5.getPosition().x) + (splayer6.getPosition().y - splayer5.getPosition().y)*(splayer6.getPosition().y - splayer5.getPosition().y));

			Vector2f zz = Vector2f(splayer6.getPosition()) - Vector2f(splayer5.getPosition());
			float az = sqrt(zz.x*zz.x + zz.y*zz.y);
			Vector2f zzx = (Vector2f(splayer6.getPosition()) - Vector2f(splayer5.getPosition()))/az;

			splayer5.move(zzx.x-0.2, zzx.y-0.2);
		}
*/

		float zz1 = sqrt((splayer2.getPosition().x - splayer.getPosition().x)*(splayer2.getPosition().x - splayer.getPosition().x)) + (splayer2.getPosition().y - splayer.getPosition().y)*(splayer2.getPosition().y - splayer.getPosition().y);
		Vector2f zz = Vector2f(splayer2.getPosition()) - Vector2f(splayer.getPosition());
		float az = sqrt(zz.x*zz.x + zz.y*zz.y);
		Vector2f zzx = (Vector2f(splayer2.getPosition()) - Vector2f(splayer.getPosition())) / az;
		if (splayer.getGlobalBounds().intersects(Ball.getGlobalBounds()))
		{
			if (Keyboard::isKeyPressed(Keyboard::Y))
			{
				Ball.move(zzx.x, zzx.y);
			}

		}

		window4.clear();
		window4.draw(Field);
		window4.draw(playerscore);
		window4.draw(mytext);
		window4.draw(Ball);
		window4.draw(Player);
		window4.draw(Player2);
		window4.draw(splayer);
		window4.draw(splayer2);
		window4.draw(splayer3);
		window4.draw(splayer4);
		window4.draw(splayer5);
		window4.draw(splayer6);
		window4.draw(splayer7);
		window4.draw(splayer8);
		window4.draw(splayer9);
		window4.draw(splayer0);
		window4.display();
		window4.clear();


	}

}
