#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class celda
{
public:
	sf::Sprite actual; // sprite actual en la ventana
	sf::Texture textActual; // textura actual en la pantalla
	int valor, x, y; // valor de cada celda y posicion en x, y
	void setValor(int valor); // set valor 
	void setX(int x); // posicion en x
	void setY(int y); // posicion en y
	int getValor(); // obtiene el valor
	int getX(); // obtiene X
	int getY(); // obtiene Y
	void actualizarSprite(); //actualiza sprite
	sf::Sprite getSprite(); // obtiene el sprite

};
