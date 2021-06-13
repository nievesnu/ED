//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <fstream>
#include "ListaDuplica.h"


bool resuelveCaso() {

    int n;
    std::cin >> n;

    if (!std::cin) { 
        return false;
    };

    ListaDuplica<int> lista;

    while (n != 0) {
        lista.push(n);
        std::cin >> n;
    }

    lista.duplicar();

    std::cout << lista << '\n';

    return true;
}

int main() {

//    // Para la entrada por fichero.
//    // Comentar para acepta el reto
//#ifndef DOMJUDGE
//    std::ifstream in("datos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif

    while (resuelveCaso());

//    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    //system("PAUSE");
//#endif

}