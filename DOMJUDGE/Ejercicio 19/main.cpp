//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <fstream>
#include <vector>
#include "bintree_eda_19.h"


bool resuelveCaso() {

    bintreeFrontera<int> arbol = leerArbolFrontera(-1);

    std::vector<int> sol;

    sol = arbol.frontera();

    for (int i = 0; i < sol.size(); ++i) {
        std::cout << sol[i];
        if (i != sol.size() - 1)
            std::cout << " ";
    }

    std::cout << "\n";

    return true;
}

int main() {

    // Para la entrada por fichero.
    // Comentar para acepta el reto
    //#ifndef DOMJUDGE
    //std::ifstream in("datos.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    //#endif

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) resuelveCaso();

    //// Para restablecer entrada. Comentar para acepta el reto
    //#ifndef DOMJUDGE // para dejar todo como estaba al principio
    //std::cin.rdbuf(cinbuf);
    ////system("PAUSE");
    //#endif

}