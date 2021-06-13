
#include <iostream>
#include <fstream>
#include "pelis.h"
#include <algorithm>
#include <vector>


bool resuelveCaso() {
	int n;
	std::cin >> n;

	if (n == 0) {
		return false;
	}
	std::vector<pelicula> v(n);

	for (int i = 0; i < n; i++) {
		
	}
	
	return true;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("datos_02.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}