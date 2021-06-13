//Nieves Núñez Ugena 2ºA A52
#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "horas_02.h"

class peliculas
{

private: horas comienzo, duracion, fin; std::string nombre;
public:
	peliculas(horas ini = 0, horas dur = 0, std::string titulo = "") : comienzo(ini), duracion(dur), nombre(titulo) {

		fin = comienzo + duracion; //fin = ini+dur
	}

	peliculas get_comienzo() const { return comienzo; };
	peliculas get_duracion() const { return duracion; };
	peliculas get_fin() const { return fin; };
	std::string get_nombre() const { return nombre; };
	
	//operadores de +

	bool operator <(const peliculas& p)const {
		if (true)
		{

		}
	}


};

inline std::ostream& operator<<(std::ostream& out, peliculas const& p) {
	out << p.get_comienzo() << " " << p.get_nombre();
	return out;
}
inline std::istream& operator >>(std::istream& in, peliculas& p) {
	horas i, d;
	std::string t;
	in >> i >> d >> t;
	//std::getline(in, t); si no coge titulo ponerlo asi y quitar titulo de arriba
	p = peliculas(i, d, t);
	return in;
}
#endif