# ifndef HORAS
# define HORAS
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <string>


class horas
{
private:
	const int HORAS_MAX=23;
	const int MIN_MAX=59;
	const int SEG_MAX=59;
	int hora, minutos, segundos;

public:

	//comprobamos si los datos que se dan paracrear el objeto son correctos 	
	horas(): hora(0), minutos(0), segundos(0){}
	horas(int h, int m, int s) : hora(h), minutos(m), segundos(s) {
		if (h<0||h>HORAS_MAX) throw std::invalid_argument("ERROR");
		if (m<0||m>MIN_MAX) throw std::invalid_argument("ERROR");
		if (s<0||s>SEG_MAX) throw std::invalid_argument("ERROR");		
	}
	
	int get_hora() const { return hora; };
	int get_minutos() const { return minutos; }
	int get_segundos() const { return segundos; }


	// operador sobrecarga
	bool operator < (horas const& h) const {
		if (hora < h.hora) return  true;
		else if (hora > h.hora) return  false;
		else if (minutos < h.minutos) return  true;
		else if (minutos > h.minutos) return  false;
		else if (segundos < h.segundos) return  true;
		else  return  false;
		}
			 			 
	}
};

//para mostrar 
inline std::ostream& operator << (std::ostream& out, horas const& h) {
	//out << h.get_hora() << ' ' << h.get_minutos() << ' ' << h.get_segundos() << '\n';
	out << std::setfill('0') << std::setw(2) << h.get_hora() << ":" << 
		std::setfill('0') << std::setw(2) << h.get_minutos() << ":" <<
		std::setfill('0') << std::setw(2) << h.get_segundos();
	return out;
}

inline std::istream& operator >> (std::istream& in, horas& hor) {
	int h, m, s;
	char aux;

	in >> h >> aux >> m >> aux >> s;
	hor = horas(h, m, s);

	return in;
}
#endif