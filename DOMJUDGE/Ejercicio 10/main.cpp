//Álvaro Miguel Ródríguez Mateos
//A67

#include <iostream>
#include <fstream>
#include "ListaDuplica.h"


bool resuelveCaso() {

    int n;
    std::cin >> n;

    if (!std::cin) return false;

    ListaDuplica<int> lista;
   
    int elementos;

    //Añadimos los n elementos a la lista

    for (int i = 0; i < n; i++) {
        std::cin >> elementos;
        lista.push(elementos);
    }

    //m número de elementos a insertar a partir de la posición p
    int m, p;
    std::cin >> m >> p;

    ListaDuplica<int> listaDuplicada;

    for (int i = 0; i < m; ++i) {
        std::cin >> elementos;
        listaDuplicada.push(elementos);
    }

    lista.insertarElementos(listaDuplicada, p);

    std::cout << lista << '\n';

    return true;
}

int main() {

    // Para la entrada por fichero.
    // Comentar para acepta el reto
//#ifndef DOMJUDGE
//    std::ifstream in("datos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    //system("PAUSE");
//#endif

}
