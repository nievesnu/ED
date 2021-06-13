//�lvaro Miguel Rodr�guez Mateos
//A63

#ifndef Persona_h
#define Persona_h

#include <iostream>
#include <string>

class Persona {
	int edad;
	std::string nombre;
	std::string apellidos;

public:
	Persona() : edad(0), nombre(""), apellidos("") {}
	Persona(int e, const std::string& n, const std::string& a) : edad(e), nombre(n), apellidos(a) {}

	int getEdad() const { return edad; }

	std::string getNombre() const { return nombre; }

	std::string getApellidos() const { return apellidos; }


	friend std::ostream& operator <<(std::ostream& out, Persona const& p) {

		out << p.getNombre() << " " << p.getApellidos();

		return out;
	}


	friend std::istream& operator >>(std::istream& in, Persona& p) {

		int edad;
		std::string n, ap;

		in >> edad >> n;
		std::getline(in, ap);

		p = Persona(edad, n, ap);

		return in;
	}

};



#endif /* Persona_h */