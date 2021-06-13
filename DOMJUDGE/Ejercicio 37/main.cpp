//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

long long int resolver(int capitulos) {

    unordered_map<int, int> lista;
    long long int distancia = 0, max = 0;
    int init = 1, elem;

    for (int i = 1; i <= capitulos; i++) {
        std::cin >> elem;
        if (lista[elem] >= init) {
            init = lista[elem] + 1;
            distancia = i - lista[elem];
        }
        else {
            distancia++;
            if (distancia > max) {
                max = distancia;
            }
        }
        lista[elem] = i;
    }
    return max;
}

void resuelveCaso() {

    int capitulos;
    cin >> capitulos;

    long long int max = resolver(capitulos);

    cout << max << "\n";
}


int main() {
	//// ajustes para que cin extraiga directamente de un fichero
	//#ifndef DOMJUDGE
	//std::ifstream in("casos.txt");
	//auto cinbuf = std::cin.rdbuf(in.rdbuf());
	//#endif

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
        resuelveCaso();

	//// para dejar todo como estaba al principio
	//#ifndef DOMJUDGE
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
	//#endif
	return 0;
}