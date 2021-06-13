//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

int resolver(int ramas) {
	int altura = 1;
	int rama;

	if (ramas != 0) {

		for (int i = 0; i < ramas; i++) {
			cin >> rama;
			if (rama > 0) {
				altura = max(altura, 1 + resolver(rama));
			}
		}
	}

	return altura;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int raiz, altura = 1;

	cin >> raiz;
	if (raiz != 0) {
		altura += resolver(raiz);
	}

	cout << altura << endl;

}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
	//#ifndef DOMJUDGE
	//std::ifstream in("casos.txt");
	//auto cinbuf = std::cin.rdbuf(in.rdbuf());
	//#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
	//#ifndef DOMJUDGE
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
	//#endif
	return 0;
}