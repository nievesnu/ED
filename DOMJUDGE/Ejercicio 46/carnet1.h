//Álvaro Miguel Rodríguez Mateos
//A63


#ifndef carnet1_h
#define carnet1_h

#include <unordered_map>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class carnet_puntos {

	const int MAXPUNTOS = 15;
	unordered_map<string, int> map;
	vector<int> cuantosConPuntos;

public:

	carnet_puntos() : cuantosConPuntos(MAXPUNTOS + 1, 0) {}

	void nuevo(const string& dni) {
		if (map.count(dni) == 1)
			throw domain_error("Conductor duplicado");
		map[dni] = MAXPUNTOS;
		cuantosConPuntos[MAXPUNTOS]++;
	}

	void quitar(const string& dni, int puntos) {
		if (map.count(dni) == 0)
			throw domain_error("Conductor inexistente");
		if (map.at(dni) == 0)
			map[dni] = 0;
		else if (map.at(dni) < puntos) {
			cuantosConPuntos[map[dni]]--;
			map[dni] = 0;
			cuantosConPuntos[0]++;
		}
		else {
			cuantosConPuntos[map[dni]]--;
			map[dni] -= puntos;
			cuantosConPuntos[map[dni]]++;
		}
	}

	int consultar(const string& dni) const {
		if (map.count(dni) == 0)
			throw domain_error("Conductor inexistente");
		return map.at(dni);
	}

	int cuantos_con_puntos(int puntos) const {
		if (puntos < 0 || puntos > MAXPUNTOS)
			throw domain_error("Puntos no validos");

		return cuantosConPuntos[puntos];
	}
};

#endif