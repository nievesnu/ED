//Álvaro Miguel Roderíguez Mateos
//A63
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include "bintree_eda.h"
using namespace std;

bintree<int> reconstruye(const vector<int>& v, const pair<int, int>& indices) {

	if (indices.first > indices.second) return {};
	else {
		int i = indices.first + 1;
		int ac = v[indices.first];
		while (i <= indices.second && ac > v[i]) ++i;

		bintree<int> izq = reconstruye(v, { indices.first + 1,i - 1 });
		bintree<int> der = reconstruye(v, { i,indices.second });

		return { izq , ac , der };
	}

}

bool resuelveCaso() {

	string linea;
	getline(cin, linea);

	if (!cin) return false;

	int dato;
	vector<int> entrada;
	pair<int, int> indices;
	stringstream ss(linea);

	while (ss >> dato)
		entrada.push_back(dato);

	bintree<int> arbol = reconstruye(entrada, { 0, entrada.size() - 1 });

	auto sol = arbol.postorder();

	cout << sol[0];
	for (int i = 1; i < sol.size(); ++i)
		cout << " " << sol[i];

	cout << "\n";

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