//Álvaro Miguel Rodríguez Mateos
//A63
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

struct tSol {
    string deporte;
    int valor;
};

bool operator> (tSol a, tSol b) {
    if (a.valor > b.valor) { 
        return true; 
    }
    else if (a.valor == b.valor && a.deporte < b.deporte) {
        return true;
    }
    else {
        return false;
    }
}

bool resuelveCaso() {

    string entrada, alumno, deporte ;
    unordered_map<string, int>mapaInscritos;
    unordered_map<string, string>mapaAlumnos;

    cin >> entrada;

    if (!cin) return false;

    while (entrada != "_FIN_") {

        if (entrada[0] >= 'A' && entrada[0] <= 'Z') {

            deporte = entrada;
            mapaInscritos[entrada] = 0;

        }
        else {
            if (mapaAlumnos.count(entrada) == 0) {

                mapaAlumnos[entrada] = deporte;
                mapaInscritos[deporte]++;

            }
            else if (mapaAlumnos.count(entrada) == 1 && mapaAlumnos[entrada] != "sinDeporte") {

                string borrar;
                borrar = mapaAlumnos[entrada];

                if (borrar != deporte) {
                    mapaInscritos[borrar]--;
                    mapaAlumnos[entrada] = "sinDeporte";
                }
            }
        }
        cin >> entrada;
    }

    vector<tSol>sol;

    for (auto& m : mapaInscritos) {
        tSol elem;
        elem.deporte = m.first;
        elem.valor = m.second;
        sol.push_back(elem);
    }

    sort(sol.begin(), sol.end(), greater<tSol>());

    for (auto& t : sol) {
        cout << t.deporte << " " << t.valor << endl;
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