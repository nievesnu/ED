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
	int hora, minutos, segundos;

public:

	//comprobamos si los datos que se dan paracrear el objeto son correctos 	
	horas(int h = 0, int m = 0, int s = 0) : hora(h), minutos(m), segundos(s) {
		if (s < 0 || s > 59 || m < 0 || m > 59 || h < 0 || h > 23)  throw  std::invalid_argument("ERROR");
		
	}
	
	int get_hora() const { return hora; };
	int get_minutos() const { return minutos; }
	int get_segundos() const { return segundos; }


	// operador sobrecarga
	bool operator < (horas const& h) const {
		if (hora < h.hora) return  true;
		else if (hora > h.hora) return  false;
		else //si las horas son iguales
		{
			if (minutos < h.minutos) return  true;
			else if (minutos > h.minutos) return  false;
			else //si los minutos son iguales
			{	if (segundos < h.segundos) return  true;
				else  return  false;
			}	
		}
			 			 
	}

	//operador suma

	bool operator +(horas const& h)const {
		int h, m, s
		if (//horas mas minutos mas segundos sobrepasan valores)
		{
			throw std::invalida_argument("ERROR");
		}
		else
		{
			s = (segundos + h.get_segundos()) % 60;
			m = (((segundos + h.get_segundos())/60) + minutos +h.get_minutos()%60);
			h = ((((segundos + h.get_segundos()) / 60) + minutos + h.get_minutos()) / 60) (+ hora + h.get_hora()%60);
		}
		return suma;
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