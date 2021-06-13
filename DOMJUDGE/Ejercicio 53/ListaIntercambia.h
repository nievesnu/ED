//Álvaro Miguel Rodríguez Mateos
//A63

#ifndef ListaIntercambia_h
#define ListaIntercambia_h

#include <iostream>
#include "queue_eda.h"

template <class T>
class ListaIntercambia : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:

	void intercambia() {
		Nodo* actual = this->prim, * aux = nullptr;
		int elem = 0;
		Nodo* sig = actual->sig;

			while (actual != nullptr) {

				if (actual->sig != nullptr) {
					elem = actual->elem;
					actual->elem = actual->sig->elem;
					actual->sig->elem = elem;
					actual = actual->sig->sig;				
				}
				else {
					actual = nullptr;
				}
				
		}

	}

	friend std::ostream& operator<<(std::ostream& output, ListaIntercambia<T>& lista) {

		for (size_t i = 0; i < lista.size(); i++) {
			int temp = lista.front();
			output << temp << " ";
			lista.push(temp);
			lista.pop();
		}

		return output;
	}

};

#endif /* ListaIntercambia_h */