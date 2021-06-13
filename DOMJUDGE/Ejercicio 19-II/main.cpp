//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

void frontera(bintree<int> const& arbol) {

	if (!arbol.empty()) {
		if (arbol.right().empty() && arbol.left().empty()) {
			cout << arbol.root() << " ";
		}
		else {
			frontera(arbol.left());
			frontera(arbol.right());
		}
	}

}


void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);

	frontera(arbol);

	cout << endl;
}

int main() {
	//// ajustes para que cin extraiga directamente de un fichero
	//#ifndef DOMJUDGE
	//std::ifstream in("casos.txt");
	//auto cinbuf = std::cin.rdbuf(in.rdbuf());
	//#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	//// para dejar todo como estaba al principio
	//#ifndef DOMJUDGE
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
	//#endif
	return 0;
}