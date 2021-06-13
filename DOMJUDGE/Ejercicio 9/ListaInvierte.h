#ifndef ListaInvierte_h
#define ListaInvierte_h

#include <iostream>
#include "queue_eda.h"

template <class T>
class ListaInvierte : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:

	void invierte() {
		Nodo* ant = nullptr, * actual = this->prim, * sig = nullptr;

		while (actual != nullptr) {
			sig = actual->sig;
			actual->sig = ant;
			ant = actual;
			actual = sig;
		}
		Nodo* tmp = this->prim;
		this->prim = this->ult;
		this->ult = tmp;
	}

	friend std::ostream& operator<<(std::ostream& output, ListaInvierte<T>& lista) {

		for (size_t i = 0; i < lista.size(); i++) {
			int temp = lista.front();
			output << temp << " ";
			lista.push(temp);
			lista.pop();
		}

		return output;
	}

};

#endif /* ListaInvierte_h */