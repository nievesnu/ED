#ifndef carnet2_h
#define carnet2_h

#include <unordered_map>
#include <stdexcept>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class carnet_puntos {

    const int MAXPUNTOS = 15;
    unordered_map<string, int> map;
    unordered_map<string, list<string>::const_iterator> posDNI;
    vector<list<string>> lista;

public:

    carnet_puntos() : lista(MAXPUNTOS + 1, list<string>()) {}

    void nuevo(const string& dni) {
        if (map.count(dni) == 1) {
            throw domain_error("Conductor duplicado");
        }
        map[dni] = MAXPUNTOS;
        lista[MAXPUNTOS].push_front(dni);
        posDNI[dni] = lista[MAXPUNTOS].cbegin();
    }

    void recuperar(const string& dni, int puntos) {
        if (map.count(dni) == 0) {
            throw domain_error("Conductor inexistente");
        }
        int nuevosPuntos = min(map[dni] + puntos, MAXPUNTOS);
        if (nuevosPuntos != map[dni]) {
            lista[map[dni]].erase(posDNI[dni]);
            map[dni] = nuevosPuntos;
            lista[map[dni]].push_front(dni);
            posDNI[dni] = lista[map[dni]].cbegin();
        }
    }

    void quitar(const string& dni, int puntos) {
        if (map.count(dni) == 0) {
            throw domain_error("Conductor inexistente");
        }
        int nuevosPuntos = max(map[dni] - puntos, 0);
        if (nuevosPuntos != map[dni]) {
            lista[map[dni]].erase(posDNI[dni]);
            map[dni] = nuevosPuntos;
            lista[map[dni]].push_front(dni);
            posDNI[dni] = lista[map[dni]].cbegin();
        }
    }

    int consultar(const string& dni) const {
        if (map.count(dni) == 0) {
            throw domain_error("Conductor inexistente");
        }
        return map.at(dni);
    }

    int cuantos_con_puntos(int puntos) const {
        if (puntos < 0 || puntos > MAXPUNTOS) {
            throw domain_error("Puntos no validos");
        }

        return lista[puntos].size();
    }

    list<string> lista_por_puntos(int puntos) {
        if (puntos < 0 || puntos > MAXPUNTOS) {
            throw domain_error("Puntos no validos");
        }
        return lista[puntos];
    }


};

#endif