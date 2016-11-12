#pragma once
#include <iostream>
#include <limits>

using namespace std;

class gato
{
public:
	gato(); // jugador vs player
	gato(char[3][3],int, int); // PC
	gato(char[3][3]); // player vs PC
	char cat[3][3];	// tablero para el juego
	bool termino;	// booleano para 
	int fila, columna, valor; // fila columna 
	bool jugar(bool); // nos permite jugar				jugador vs jugador
	void mostrar(); // mostar matriz 
	~gato();		// destructor

};

