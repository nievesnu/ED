//Nieves N??ez Ugena
//A52

#include <iostream>
#include <fstream>
#include "ListaInvierteDoble.h"


bool resuelveCaso() {

	ListaInvierteDoble<int> lista;
	int tmp;

	std::cin >> tmp;

	if (!std::cin) return false;

	while (tmp != 0) {
		lista.push_back(tmp);
		std::cin >> tmp;
	}

	lista.invierte();

	std::cout << lista << '\n';

	return true;
}

int main() {

	// Para la entrada por fichero.
	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	//system("PAUSE");
//#endif

}