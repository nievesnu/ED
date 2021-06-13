//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

bool resuelveCaso() {

    int n;
    std::cin >> n;

    if (n == 0) return false;

    std::map<std::string, int>lista;
    std::string nombre, entrada;

    for (int i = 0; i < n; ++i) {
        std::cin.ignore();
        getline(std::cin, nombre);
        std::cin >> entrada;

        if (entrada == "INCORRECTO")
            lista[nombre]--;
        else
            lista[nombre]++;
    }

    for (auto c : lista) {
        if (c.second != 0)
            std::cout << c.first << ", " << c.second << "\n";
    }
    std::cout << "---" << endl;

    return true;
}



int main() {
	//// ajustes para que cin extraiga directamente de un fichero
	//#ifndef DOMJUDGE
	//std::ifstream in("casos.txt");
	//auto cinbuf = std::cin.rdbuf(in.rdbuf());
	//#endif

    while (resuelveCaso());

	//// para dejar todo como estaba al principio
	//#ifndef DOMJUDGE
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
	//#endif
	return 0;
}