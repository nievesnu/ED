//Álvaro Miguel Rodríguez Mateos
//A63
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include "carnet1.h"

using namespace std;


bool resuelveCaso() {


	carnet_puntos carnet;
	string operacion, dni;
	int puntos;

	cin >> operacion;
	if (!cin) return false;

	while (operacion != "FIN") {
		try {
			if (operacion == "nuevo") {
				cin >> dni;
				carnet.nuevo(dni);
			}
			else if (operacion == "cuantos_con_puntos") {
				cin >> puntos;
				int sol = carnet.cuantos_con_puntos(puntos);
				cout << "Con " << puntos << " puntos hay " << sol << "\n";
			}
			else if (operacion == "quitar") {
				cin >> dni >> puntos;
				carnet.quitar(dni, puntos);
			}
			else if (operacion == "consultar") {
				cin >> dni;
				int sol = carnet.consultar(dni);
				cout << "Puntos de " << dni << ": " << sol << "\n";
			}
		}
		catch (domain_error e) {
			cout << "ERROR: " << e.what() << "\n";
		}
		cin >> operacion;
	}

	cout << "---\n";

	return true;
}

int main() {

	// Para la entrada por fichero.
	// Comentar para acepta el reto
	//#ifndef DOMJUDGE
	//ifstream in("datos.txt");
	//auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect cin to casos.txt
	//#endif

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
	//#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//cin.rdbuf(cinbuf);
	////system("PAUSE");
	//#endif

}
