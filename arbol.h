#pragma once
#include "gato.h"

struct nodo {
	int value;	// valor en cada nodo
	nodo *up, *down, *left, *rigth; // 4 direcciones que posee el nodo para lograr moverse por el arbol
	gato *cat; // puntero a gato
};
class arbol
{
public:

	int ronda,fila,columna; // movimientos totales en el tablero = 9, fila, columna
	bool turno, fallo; // turno de cada uno
	char cat[3][3];	//	matriz 3*3		
	void setUp(nodo*);	 //				--|-|--
	void setDown(nodo*); //				--|-|--
	void setLeft(nodo*); //				
	void setRigth(nodo*);//			apunta hacia las 4 direcciones
	nodo*getUp();		//			para asi saber cuantas hojas
	nodo*getDown();		//			e hijos posee y saber que 
	nodo*getLeft();		//			direccion tomar
	nodo*getRigth();	//
	nodo*raiz, *actual;
	nodo *up, *down, *left, *rigth; // 4 direcciones que posee el nodo para lograr moverse por el arbol
	nodo*mejor(); // mejor jugada
	nodo*peor();  // peor jugada
	void jugar(); // juega vs la PC
	void insertar(); // inserta un nuevo nodo
	void borrar(); // borra el arbol 
	void mostrar(); // 
	arbol();
	virtual ~arbol();
};