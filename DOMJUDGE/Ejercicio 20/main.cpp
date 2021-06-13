//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"

template <typename T>
T menor(bintree<T> arbol) {
   
    auto it = arbol.begin();
    T minimo = *it;
    ++it;
    while (it != arbol.end())
    {
        minimo = std::min(minimo, *it);
        ++it;
    }
    return minimo;
}

template <typename T>
void resuelve(T vacio) {
    auto arbol = leerArbol(vacio);
    std::cout << menor(arbol) << '\n';
}


bool resuelveCaso() {

    char tipo;
    std::cin >> tipo;

    if (!std::cin) return false;

    if (tipo == 'N') {
        resuelve(-1);
    }
    else {
        resuelve(std::string("#"));
    }

    return true;
}

int main() {

    // Para la entrada por fichero.
    // Comentar para acepta el reto
    //#ifndef DOMJUDGE
    //std::ifstream in("datos.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    //#endif


    while (resuelveCaso());
    return 0;

    //// Para restablecer entrada. Comentar para acepta el reto
    //#ifndef DOMJUDGE // para dejar todo como estaba al principio
    //std::cin.rdbuf(cinbuf);
    ////system("PAUSE");
    //#endif

}