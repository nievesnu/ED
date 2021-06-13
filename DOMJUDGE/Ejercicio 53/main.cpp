//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <fstream>
#include "ListaIntercambia.h"

bool resuelveCaso() {

    int n;
    std::cin >> n;

    if ((!std::cin ) || (n == 0)) {
        return false;
    };

    int v;
 
    ListaIntercambia<int> lista;

    for (int i = 0; i < n; i++) {
        std::cin >> v;
        if (!std::cin) {
            return false;
        }
        lista.push(v);
    }

    lista.intercambia();

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