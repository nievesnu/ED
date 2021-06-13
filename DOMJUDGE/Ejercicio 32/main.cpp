//Álvaro Miguel Roderíguez Mateos
//A63
#include <iostream>
#include <fstream>
#include <vector>
#include "set_eda.h"


bool resuelveCaso() {

	int n, tmp;

	std::cin >> n;

	if (n == 0) {
		return false;
	}

	set<int> s;

	for (int i = 0; i < n; ++i) {
		std::cin >> tmp;
		s.insert(tmp);
	}

	int m;
	std::cin >> m;

	for (int i = 0; i < m; ++i) {
		std::cin >> tmp;
		std::pair<bool, int> sol = s.lower_bound(tmp);

		if (!sol.first) {
			std::cout << "NO HAY\n"; 
		}
		else {
			std::cout << sol.second << "\n";
		}
	}

	std::cout << "---\n";
	return true;
}


int main() {

    //// Para la entrada por fichero.
    //// Comentar para acepta el reto
    //#ifndef DOMJUDGE
    //ifstream in("datos.txt");
    //auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect cin to casos.txt
    //#endif

	while (resuelveCaso());

    //// Para restablecer entrada. Comentar para acepta el reto
    //#ifndef DOMJUDGE // para dejar todo como estaba al principio
    //cin.rdbuf(cinbuf);
    ////system("PAUSE");
    //#endif

}