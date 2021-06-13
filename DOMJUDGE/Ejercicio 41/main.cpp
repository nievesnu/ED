//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <unordered_map>
#include <functional>

using namespace std;


struct tProblema {

    int tiempo = 0;
    int intentos = 0;
    bool resuelto = false;
    string veredicto;

};

struct tSol {

    string equipo;
    int resueltos;
    int tiempoTotal;

};

using iMap = unordered_map<string, unordered_map<string, tProblema>>;

bool operator> (tSol a, tSol b) {
    if (a.resueltos > b.resueltos) {
        return true;

    }
    else if (a.resueltos == b.resueltos && a.tiempoTotal < b.tiempoTotal) {
        return true;
    }
    else if (a.resueltos == b.resueltos && a.tiempoTotal == b.tiempoTotal && a.equipo < b.equipo) {
        return true;
    }
    else {
        return false;
    }
}

void resuelveCaso() {

    string equipo, problema;
    iMap mapaInscritos;
    unordered_map<string, tSol> mapaResueltos;
    cin >> equipo;

    while (equipo != "FIN") {

        tProblema structProblema;
        cin >> problema;
        cin.ignore();
        cin >> structProblema.tiempo >> structProblema.veredicto;

        if (structProblema.veredicto != "AC") {
            structProblema.intentos = 1;
        }

        if (mapaInscritos.count(equipo) == 0) { 
            mapaResueltos[equipo] = { equipo, 0, 0 };
            mapaInscritos[equipo].insert({ problema, structProblema });
        }
        else if (mapaInscritos.count(equipo) == 1 && mapaInscritos.at(equipo).count(problema) == 1) {

            if (structProblema.veredicto != "AC" && !mapaInscritos[equipo][problema].resuelto) {
                mapaInscritos[equipo][problema].intentos++;
            }
        }
        else {
            mapaInscritos[equipo].insert({ problema, structProblema });
        }

        if (structProblema.veredicto == "AC" && !mapaInscritos[equipo][problema].resuelto) {
            mapaResueltos[equipo].resueltos++;
            mapaInscritos[equipo][problema].resuelto = true;
            mapaResueltos[equipo].tiempoTotal += structProblema.tiempo + (mapaInscritos[equipo][problema].intentos * 20);
        }

        cin.ignore();
        cin >> equipo;
    }

    set<tSol, greater<tSol>>sol;

    for (auto& m : mapaResueltos) {
        sol.insert({ m.first, m.second.resueltos, m.second.tiempoTotal });
    }

    for (auto& t : sol) {
        cout << t.equipo << " " << t.resueltos << " " << t.tiempoTotal << "\n";
    }

    cout << "---\n";

}

int main() {

    //// Para la entrada por fichero.
    //// Comentar para acepta el reto
    //#ifndef DOMJUDGE
    //ifstream in("datos.txt");
    //auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect cin to casos.txt
    //#endif

    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) resuelveCaso();

    //// Para restablecer entrada. Comentar para acepta el reto
    //#ifndef DOMJUDGE // para dejar todo como estaba al principio
    //cin.rdbuf(cinbuf);
    ////system("PAUSE");
    //#endif

}