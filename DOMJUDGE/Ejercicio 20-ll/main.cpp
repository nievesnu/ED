//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda_20.h"


bool resuelveCaso() {

    char tipo;
    std::cin >> tipo;

    if (!std::cin) return false;

    if (tipo == 'N') {
        bintreeMinimo<int> arbol = leerArbolMinimo(-1);
        std::cout << arbol.minimo() << "\n";
    }
    else {
        std::string fin = "#";
        bintreeMinimo<std::string> arbol = leerArbolMinimo(fin);
        std::cout << arbol.minimo() << "\n";
    }

    return true;
}

int main() {

    while(resuelveCaso());
    return 0;

}