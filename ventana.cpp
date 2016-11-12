#include "ventana.h"
using namespace std;
ventana::ventana() {}
ventana::~ventana() {}
void ventana::menuPrincipal()
{
	sf::Event event;
	menu.create(sf::VideoMode(600, 300), "TIC TAC TOE", sf::Style::Default);

	while (menu.isOpen())
	{

		menu.draw(menuLogoSprite);
		menu.draw(enter);
		menu.display();
		while (menu.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				menu.close();
				break;
			case::sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Return)
				{
					menu.close();
					jugar();
					break;
				}
			}
		}
	}

}
void ventana::cargarSptrites()
{

	menuLogo.loadFromFile("background.jpg");
	menuLogoSprite.setTexture(menuLogo);
	gameBack.loadFromFile("gameBackground.png");
	gameSprite.setTexture(gameBack);
	font.loadFromFile("arial.ttf");
	enter.setString("PRESIONE ENTER");
	menuLogoSprite.setScale(0.40, 0.30);
	gameSprite.setScale(2, 1.5);
	enter.setFont(font);
	enter.setColor(sf::Color::Cyan);
	enter.setPosition(sf::Vector2f(160, 100));

}
void ventana::jugar()
{
	bool turno = true;
	sf::Vector2i position;
	sf::Event event;
	int x = 0, y = 0;
	for (int i = 0; i < 3; i++)// crear el tablero
	{
		x = 0;
		for (int j = 0; j < 3; j++)
		{
			tableroJuego[i][j].setValor(-1);
			tableroJuego[i][j].actualizarSprite();
			tableroJuego[i][j].actual.setPosition(x, y);
			x += 150;
		}
		y += 140;
	}
	game.create(sf::VideoMode(450, 420), "TIC TAC TOE", sf::Style::Default);
	while (game.isOpen())
	{

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				game.draw(tableroJuego[i][j].getSprite());
			}

		}
		game.pollEvent(event);
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
		{
			turno = !turno;
			position = sf::Mouse::getPosition();
			if (position.x < 625 && position.y < 340) //primera celda
			{
				if (turno)
				{

					tableroJuego[0][0].setValor(0);
					tableroJuego[0][0].actualizarSprite();
					game.draw(tableroJuego[0][0].getSprite());
					continue;


				}
				if (!turno)
				{

					tableroJuego[0][0].setValor(1);
					tableroJuego[0][0].actualizarSprite();
					game.draw(tableroJuego[0][0].getSprite());
					continue;

				}

			}
			if ((position.x > 625 && position.x < 765) && position.y < 340) //segunda celda
			{
				if (turno)
				{

					tableroJuego[0][1].setValor(0);
					tableroJuego[0][1].actualizarSprite();
					game.draw(tableroJuego[0][1].getSprite());

					continue;
				}
				if (!turno)
				{

					tableroJuego[0][1].setValor(1);
					tableroJuego[0][1].actualizarSprite();
					game.draw(tableroJuego[0][1].getSprite());

					continue;
				}
			}
			if (position.x >765 && position.y < 340)//tercera celda
			{
				if (turno)
				{

					tableroJuego[0][2].setValor(0);
					tableroJuego[0][2].actualizarSprite();
					game.draw(tableroJuego[0][2].getSprite());
					continue;
				}
				if (!turno)
				{

					tableroJuego[0][2].setValor(1);
					tableroJuego[0][2].actualizarSprite();
					game.draw(tableroJuego[0][2].getSprite());
					continue;
				}

			}
			if (position.x <625 && (position.y > 340 && position.y < 485))//cuarta celda
			{
				if (turno)
				{

					tableroJuego[1][0].setValor(0);
					tableroJuego[1][0].actualizarSprite();
					game.draw(tableroJuego[1][0].getSprite());
					continue;
				}
				if (!turno)
				{

					tableroJuego[1][0].setValor(1);
					tableroJuego[1][0].actualizarSprite();
					game.draw(tableroJuego[1][0].getSprite());
					continue;
				}

			}
			if ((position.x > 625 && position.x < 765) && (position.y > 340 && position.y < 485))//quinta celda
			{
				if (turno)
				{

					tableroJuego[1][1].setValor(0);
					tableroJuego[1][1].actualizarSprite();
					game.draw(tableroJuego[1][1].getSprite());
					continue;
				}
				if (!turno)
				{

					tableroJuego[1][1].setValor(1);
					tableroJuego[1][1].actualizarSprite();
					game.draw(tableroJuego[1][1].getSprite());
					continue;
				}

			}
			if (position.x > 765 && (position.y > 340 && position.y < 485))//sexta celda
			{
				if (turno)
				{

					tableroJuego[1][2].setValor(0);
					tableroJuego[1][2].actualizarSprite();
					game.draw(tableroJuego[1][2].getSprite());
					continue;
				}
				if (!turno)
				{

					tableroJuego[1][2].setValor(1);
					tableroJuego[1][2].actualizarSprite();
					game.draw(tableroJuego[1][2].getSprite());
					continue;
				}

			}
			if (position.x < 625 && position.y > 485)//setima celda
			{
				if (turno)
				{

					tableroJuego[2][0].setValor(0);
					tableroJuego[2][0].actualizarSprite();
					game.draw(tableroJuego[2][0].getSprite());
					continue;
				}
				if (!turno)
				{

					tableroJuego[2][0].setValor(1);
					tableroJuego[2][0].actualizarSprite();
					game.draw(tableroJuego[2][0].getSprite());
					continue;
				}

			}
			if ((position.x > 625 && position.x<785) && position.y > 485)//octava celda
			{
				if (turno)
				{

					tableroJuego[2][1].setValor(0);
					tableroJuego[2][1].actualizarSprite();
					game.draw(tableroJuego[2][1].getSprite());
					continue;
				}
				if (!turno)
				{

					tableroJuego[2][1].setValor(1);
					tableroJuego[2][1].actualizarSprite();
					game.draw(tableroJuego[2][1].getSprite());
					continue;
				}

			}
			if (position.x>785 && position.y > 485)//novena celda
			{
				if (turno)
				{

					tableroJuego[2][2].setValor(0);
					tableroJuego[2][2].actualizarSprite();
					game.draw(tableroJuego[2][2].getSprite());
					continue;
				}
				if (!turno)
				{

					tableroJuego[2][2].setValor(1);
					tableroJuego[2][2].actualizarSprite();
					game.draw(tableroJuego[2][2].getSprite());
					continue;
				}

			}


		}


		game.display();
	}
}