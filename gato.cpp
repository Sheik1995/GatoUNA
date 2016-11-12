#include "gato.h"

gato::gato() // juga vs juga
{
	termino = false; // porque aun no termia el juego
	fila = columna = valor = 0;		
	for (int i = 0; i < 3; i++)		//inicializamos todo
		for (int j = 0; j < 3; j++)
			cat[i][j] = ' ';
}
gato::gato(char tb[3][3], int x, int y)	// se encarga de asignarle 
{										// una posicion en la matriz
	termino = false;				    // a la PC
	fila = x; columna = y;
	valor = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cat[i][j] = tb[i][j];
}
void gato::mostrar() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {	//								  |  |
			cout << cat[i][j] << '|';	// nos muestra el gato			--+--+--
										//								  |  |  
										// en pantalla					--+--+--	
										//								  |  |		
		}															
		cout << "\b \n ---" << endl;
	}
}

gato::gato(char tb[3][3]) // jugador vs PC
{
	termino = false; // aun no termina el juego
	fila = columna = valor = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cat[i][j] = tb[i][j]; // sustituimos valores en la matriz

}
bool gato::jugar(bool turno) {	
	char comodin;	// ficha de cada jugador: X o O
	mostrar();		// muestra matriz conforme juega
	comodin = (turno ? 'X' : 'O'); // ficha de cada jugador
	 // elegir juga 
	cout << "Turno del: " << (turno ? "Jugador #1 " : "Jugador #2 ") << endl; // asi sabemos cual jugador le toca
	do{
		while (1) {
			cout << "Digite la fila: ";
			cin >> fila;
			if (cin.fail()) { // si el cin falla:
				cout << "Digite un numero base 10" << endl;
				cin.clear(); // quita bit de error
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// limpia buffer
				continue;
			}
			if (fila > 2 || fila < 0) { // valida que no se salga de las filas
				cout << "Digite un numero en el rango [0,2]" << endl;
				continue;
			}
			break;
		}
		while (1) {
			cout << "Digite la columna: ";
			cin >> columna;
			if (cin.fail()) { // si cin falla:
				cout << "Digite un numero base 10" << endl;
				cin.clear(); // quita bit de error
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// limpia buffer
				continue;
			}
			if (columna > 2 || columna < 0) { // valida que no se salga de las columnas
				cout << "Digite un numero en el rango [0,2]" << endl;
				continue;
			}
			break;
		}
		if (cat[fila][columna] != ' ') { // si la casilla esta ocupada muestre mensaje
			cout << "Casilla ocupada... " << endl;

		}
	} while (cat[fila][columna] != ' '); // mientras no este ocupada
		cat[fila][columna] = comodin; // ingresa ficha en la posicion elejida
		int row[3] = { 0 }, col[3] = { 0 }, diag[2] = { 0 }; // vectores de las 3 filas, 3 columnas y 
		for (int i = 0; i<3; i++) {							 // 2 diagonales
			for (int j = 0; j<3; j++) {
				if (cat[i][j] == comodin)		// filas
					row[i]++;			// si esta ocupada le sumo una posicion al vector de folas
				if (row[i] == 3 && fila == i) 					
					return true;				// retorna true si hay 3 filas con X o O
			}
		}

		for (int i = 0; i<3; i++) {
			for (int j = 0; j<3; j++) {
				if (cat[j][i] == comodin)		// columnas
					col[i]++;						
				if (col[i] == 3 && columna == i) 
					return true;			// retorna true si hay 3 filas con X o O	
			}
		}

		for (int i = 0; i<3; i++) {
			if (cat[i][i] == comodin)
				diag[0]++;							// primer diagonal
			if (diag[0] == 3 && fila == columna)
				return true;	// retorna true si hay 1 diagonal llena de X o O
			
		}

		for (int i = 2; i >= 0; i--) {
			if (cat[2 - i][i] == comodin)
				diag[1]++;							// segunda diagonal
			if (diag[1] == 3 && (fila + columna) == 2) 
				return true;			// retorna true si hay 1 diagonal llena de X o O
		}		
	return false; // nadie gano
}
gato::~gato() {  } // destructor