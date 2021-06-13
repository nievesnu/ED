//Nieves Núñez Ugena 2ºA A52

#include <iostream>
#include <fstream>
#include <vector>
#include "complejo.h"



bool resuelveCaso() {
	complejo c, aux;
	int i = 0;
	bool ok = true;

	cin >> c;
	aux = c;
	int n = c.numIter();

	while (ok && i < n) {
		if (c % c > 2) {
			ok = false;
		}
		else {
			c = (c * c) + aux;
		}

		i++;
	}

	return ok;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos2_03.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numCasos;
	cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		if (resuelveCaso()) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}