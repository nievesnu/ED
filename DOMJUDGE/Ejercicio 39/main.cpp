//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

bool resuelveCaso() {

    int n;
    cin >> n;
    cin.get();

    if (n == 0)
        return false;

    string entrada;
    string clave;
    map<string, vector<int>> map;

    for (int i = 1; i <= n; ++i) {

        getline(cin, entrada);
        stringstream v(entrada);

        while (v >> clave) {

            for (int t = 0; t < clave.size(); t++) {
                clave[t] = tolower(clave[t]);
            }

            if (clave.size() > 2) {
                if (map[clave].size() > 0 && map[clave][map[clave].size() - 1] != i) {
                    map[clave].push_back(i);
                }
                else if (map[clave].size() == 0){
                    map[clave].push_back(i);
                }
            }
        }
    }

    for (auto& it : map) {
        cout << it.first;
        for (int i = 0; i < it.second.size(); ++i)
            cout << " " << it.second[i];
        cout << endl;
    }

    cout << "---" << endl;
    return true;
}

int main() {

    //// Para la entrada por fichero.
    //// Comentar para acepta el reto
    //#ifndef DOMJUDGE
    //ifstream in("datos.txt");
    //auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect cin to casos.txt
    //#endif

    while (resuelveCaso());

    //// Para restablecer entrada. Comentar para acepta el reto
    //#ifndef DOMJUDGE // para dejar todo como estaba al principio
    //cin.rdbuf(cinbuf);
    ////system("PAUSE");
    //#endif

}