#include "celda.h"

void celda::setValor(int valor)
{
	this->valor = valor;		// set del valor
}
void celda::setX(int x)
{
	this->x = x;		// set en X
}
void celda::setY(int y)
{
	this->y = y;		// set en Y
}
void celda::actualizarSprite() // actualizamos el sprite
{
	switch (valor) // depende del valor actualizamos el sprite
	{
	case -1:
		textActual.loadFromFile("blank.png"); // espacio en blanco
		actual.setTexture(textActual);
		actual.setScale(0.5, 0.5); // escala de la imagen
		break;
	case 0:
		textActual.loadFromFile("x.jpg"); // X de ficha
		actual.setTexture(textActual);
		actual.setScale(0.5, 0.5);// escala de la imagen
		break;
	case 1:
		textActual.loadFromFile("o.jpg"); // O de ficha
		actual.setTexture(textActual);
		actual.setScale(0.5, 0.5);// escala de la imagen
		break;
	}
}

sf::Sprite celda::getSprite() // obtiene el sprite
{
	return this->actual; // sprite actual
}