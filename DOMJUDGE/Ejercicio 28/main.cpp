//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

struct tSol {
    int mult;
    int profundidad;
};

bool esPrimo(int num) {
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

tSol resuelve(const bintree<int>& arbol, int profundidad) {

    if (arbol.empty() || esPrimo(arbol.root())) return { -1, 0 };

    if (arbol.root() % 7 == 0)
        return { arbol.root(), profundidad };
    else if (arbol.left().empty() && arbol.right().empty())
        return { -1, 0 };
    else if (arbol.left().empty())
        return resuelve(arbol.right(), profundidad + 1);
    else if (arbol.right().empty())
        return resuelve(arbol.left(), profundidad + 1);
    else {
        tSol iz = resuelve(arbol.left(), profundidad + 1);
        tSol dr = resuelve(arbol.right(), profundidad + 1);
        if (iz.mult != -1 && dr.mult != -1) {
            if (iz.profundidad <= dr.profundidad) return { iz.mult, iz.profundidad };
            return { dr.mult, dr.profundidad };
        }
        else if (iz.mult != -1)
            return iz;
        else
            return dr;
    }
}

void resuelveCaso() {

    bintree<int>tree = leerArbol(-1);

    tSol sol = resuelve(tree, 1);

    if (sol.mult == -1)
        std::cout << "NO HAY\n";
    else
        std::cout << sol.mult << " " << sol.profundidad << "\n";
}

int main() {

    //// Para la entrada por fichero.
    //// Comentar para acepta el reto
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