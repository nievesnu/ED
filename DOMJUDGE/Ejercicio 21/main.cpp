//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"


int diametro(bintree<char> const& arbol, int & alt) {
    if (arbol.empty()) {
        alt = 0;
        return 0;

    }
    else {
        int altIz, altDer;
        int diamIz = diametro(arbol.left(), altIz);
        int diamDer = diametro(arbol.right(), altDer);
        alt = 1 + max(altIz, altDer);
        return max(1+ altIz + altDer, max(diamIz, diamDer));
    }
}


int diametro(bintree<char> const& arbol) {
    int altura;
    return diametro(arbol, altura);
}

void resuelveCaso() {
    auto arbol = leerArbol('.');
    cout << diametro(arbol) << endl;
 
}

int main() {

    int nCasos;
    cin >> nCasos;

    for (int i = 0; i < nCasos; i++)
    {
        resuelveCaso();
    }


}