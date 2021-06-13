//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <fstream>
#include <string>
#include "carnet2.h"


bool resuelveCaso() {

	string orden, dni;
	int puntos;
	cin >> orden;
	if (!cin)
		return false;

	carnet_puntos carnet;

	while (orden != "FIN") {
		try {
			if (orden == "nuevo") {
				cin >> dni;
				carnet.nuevo(dni);
			}
			else if (orden == "quitar") {
				cin >> dni >> puntos;
				carnet.quitar(dni, puntos);
			}
			else if (orden == "recuperar") {
				cin >> dni >> puntos;
				carnet.recuperar(dni, puntos);
			}
			else if (orden == "consultar") {
				cin >> dni;
				puntos = carnet.consultar(dni);
				cout << "puntos de " << dni << ": " << puntos << endl;
			}
			else if (orden == "cuantos_con_puntos") {
				cin >> puntos;
				int cuantos = carnet.cuantos_con_puntos(puntos);
				cout << "Con " << puntos << " puntos hay " << cuantos << endl;
			}
			else if (orden == "lista_por_puntos") {
				cin >> puntos;
				auto const& lista = carnet.lista_por_puntos(puntos);
				cout << "Tienen " << puntos << " puntos:";
				for (auto const& dni : lista)
					cout << ' ' << dni;
				cout << '\n';
			}
			else
				cout << "OPERACION DESCONOCIDA\n";
		}
		catch (domain_error e) {
			cout << "ERROR: " << e.what() << endl;
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