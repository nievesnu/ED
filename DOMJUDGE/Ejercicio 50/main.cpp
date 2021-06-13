#include <iostream>
#include <fstream>
#include <vector>
#include "iPud.h"
using namespace std;


bool resuelveCaso() {

    iPud iPod;
    cancion song;
    artista artist;
    int duracion;

    string orden;
    cin >> orden;

    if (!cin) return false;

    while (orden != "FIN") {
        try {
            if (orden == "addSong") {
                cin >> song >> artist >> duracion;
                iPod.addSong(song, artist, duracion);
            }
            else if (orden == "addToPlaylist") {
                cin >> song;
                iPod.addToPlaylist(song);
            }
            else if (orden == "play")
                iPod.play();
            else if (orden == "deleteSong") {
                cin >> song;
                iPod.deleteSong(song);
            }
            else if (orden == "totalTime")
                cout << "Tiempo total " << iPod.totalTime() << endl;
            else if (orden == "recent") {
                cin >> duracion;
                list<cancion> lista = iPod.recent(duracion);
                if (!lista.empty()) {
                    cout << "Las " << lista.size() << " mas recientes"<< endl;
                    for (auto const& c : lista)
                        cout << "    " << c << endl;
                }
                else cout << "No hay canciones recientes" << endl;
            }
            else if (orden == "current")
                iPod.current();
        }
        catch (domain_error e) {
            cout << "ERROR " << e.what() << endl;
        }
        cin >> orden;
    }
    cout << "---" << endl;

    return true;

}

int main() {

    // Para la entrada por fichero.
    // Comentar para acepta el reto
//#ifndef DOMJUDGE
//    ifstream in("datos.txt");
//    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect cin to casos.txt
//#endif

    while (resuelveCaso());

//    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    cin.rdbuf(cinbuf);
//    //system("PAUSE");
//#endif

}