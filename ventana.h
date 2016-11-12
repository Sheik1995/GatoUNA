#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "celda.h"
#include <iostream>

class ventana
{
public:
	ventana();
	~ventana();
	void cargarSptrites();
	void menuPrincipal();
	void jugar();
	sf::RenderWindow menu, game;
	sf::Texture menuLogo;
	sf::Texture gameBack;
	sf::Sprite gameSprite;
	sf::Sprite menuLogoSprite;
	sf::RectangleShape xbox;
	sf::RectangleShape obox;
	sf::Text enter;
	sf::Font font;
	char tablero[3][3];
	celda tableroJuego[3][3];


};

