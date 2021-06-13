#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "01-horas.h"

bool resuelveCaso() {
	int nt, nh;
	horas h;
	
	std::cin >> nt >> nh;
	if (nt == 0 && nh == 0) return false;
	std :: vector<horas> v;

	for (int i = 0; i < nh; i++) {
		std::cin >> v[i];
	}

	for (int j = 0; j < nt; j++) {
		try {
			std::cin >> h;
			//iterador automatico
			auto p = lower_bound(v.begin(), v.end(), h);

			if (p == v.end()) {
				std::cout << "NO\n";
			}
			else {
				//*p = objeto que está apuntando ese iterador
				std::cout << *p << "\n";
			}
		}
		catch (std::invalid_argument const& ia) {
			std::cout << ia.what() << "\n";
		}
	}

	std::cout << "---" << std::endl;
	return true;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("datos_tren.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	// Resolvemos
	while (resuelveCaso());


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}