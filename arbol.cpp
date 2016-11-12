#include "arbol.h"

arbol::arbol()
{
	ronda =  0;						//  son 9 rondas, iniciamos en 0
	turno = fallo = false;			//	se inicializa
	raiz = actual = nullptr;		//	todos los valores dados
	for (int i = 0; i<3; i++)		// recorremos filas
		for (int j = 0; j<3; j++)	// recorremos columnas
			cat[i][j] = ' ';		// inicializa matriz en espacios en blanco
}

arbol::~arbol() {  }		// destructor

nodo*arbol::mejor() {
	nodo*best = actual = raiz; // no perder la raiz
	while (actual) {
		if (actual->down) {		// si actual tiene abajo entonces:
			actual = actual->down; // si tiene hijo nos movemos a el
			best = actual; // por el momento el mejor es el actual
			continue;	// brinca los demas pasos entrando al while nuevamente
		}
		else if (actual->value > best->value) // si el valor actual es mejor que el mejor anterior
			best = actual; // el mejor es actual
		actual = actual->rigth; // nos movemos a la derecha -->
	}
	return best; // retorna la mejor jugada para la PC
}

nodo*arbol::peor() {
	nodo*worst = actual = raiz;	// nos ubicamos en la raiz
	while (actual) {
		if (actual->down) { // si actual tiene abajo:
			actual = actual->down; // nos movemos hacia abajo
			worst = actual; // el peor por el momento es actual
			continue;
		}
		else if (actual->value < worst->value) { // si el peor por el momento es menor que otro peor
			worst = actual; // el peor es el actual
		}
		actual = actual->rigth;
	}
	return worst; // retorna la peor jugada para la PC
}

void arbol::jugar() { // queriamos que jugara vs pc
	int row, col;
	nodo*aux;
	do {
		// En proceso
	} while (ronda<9);
}

void arbol::insertar() {
	// se encarga de insertar nodos en el
	// arbol
}	// En proceso...

void arbol::borrar() {
	// encargado de borrar					borra de abajo 
	// el arbol nodo por nodo				hacia arriba
	// hasta llegar a la raiz 
}

void arbol::mostrar() {
	for (int i = 0; i < 3; i++)		// muestra matriz	
		for (int j = 0; j < 3; j++) // de 3*3
			cout << cat[i][j];
}

nodo*arbol::getUp() 
{ 
	return up;
}
nodo*arbol::getDown() 
{
	return down;						// getter de las 4 direcciones
}
nodo*arbol::getLeft() 
{
	return left; 
}		
nodo*arbol::getRigth() 
{ 
	return rigth;
}


void arbol::setUp(nodo* up)
{ 
	this->up = up; 
}
void arbol::setDown(nodo* down) 
{ 
	this->down = down;					// setter de las 4 direcciones
}		
void arbol::setLeft(nodo* left)
{ 
	this->left = left; 
}		
void arbol::setRigth(nodo* rigth)
{ 
	this->rigth = rigth;
}