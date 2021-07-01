//Nieves Núñez Ugena
//A52
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "ipud.h"

using namespace std;


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	string orden, cancion, artista;
	int duracion, n;
	iPud mp3;

	cin >> orden;

	if (!std::cin)  // fin de la entrada
		return false;

	while (orden != "FIN"){
		try{
			if (orden == "addSong"){
				cin >> cancion >> artista >> duracion;
				mp3.addSong(cancion, artista, duracion);
			}
			else if (orden == "addToPlaylist"){
				cin >> cancion;
				mp3.addToPlaylist(cancion);
			}
			else if (orden == "play"){
				cancion = mp3.play();
				if (cancion != "ERROR"){
					cout << "Sonando " << cancion << endl;
				}
				else{
					cout << "No hay canciones en la lista" << endl;
				}
			}
			else if (orden == "totalTime"){
				cout << "Tiempo total " << mp3.totalTime() << endl;
			}
			else if (orden == "deleteSong"){
				cin >> cancion;
				mp3.deleteSong(cancion);
			}
			else if (orden == "current"){
				mp3.current();
			}
			else if (orden == "recent"){
				cin >> n;
				list<string> lista = mp3.recent(n);
				if (lista.empty()){
					cout << "No hay canciones recientes" << endl;
				}
				else{
					cout << "Las " << n << " mas recientes" << endl;
					for (auto const &i : lista){
						cout << "    " << i << endl;
					}
				}
			}

			cin >> orden;
		}

		catch (domain_error e){
			cout << e.what() << endl;
			cin >> orden;
		}
	}
	cout << "----" << endl;

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}