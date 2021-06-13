//Álvaro Miguel Rodríguez Mateos
//A63

#ifndef ListaDuplicaDoble_h
#define ListaDuplicaDoble_h

#include <iostream>
#include "deque_eda.h"

template <class T>
class ListaDuplicaDoble : public deque<T> {
    using Nodo = typename deque<T>::Nodo;

public:

    void duplicar() {
        Nodo* aux = this->fantasma->sig;

        for (int i = 0; i < this->nelems; ++i) {
            Nodo* nuevo = new Nodo(aux->elem, aux, aux->sig);
            aux->sig->ant = nuevo;
            aux->sig = nuevo;
            aux = aux->sig->sig;
        }

        this->nelems = this->nelems * 2;
    }


    friend std::ostream& operator<<(std::ostream& output, ListaDuplicaDoble<T>& lista) {

        for (size_t i = 0; i < lista.size(); i++) {
            int temp = lista.front();
            output << temp << " ";
            lista.push_back(temp);
            lista.pop_front();
        }

        return output;
    }
};

#endif /* ListaDuplicaDoble_H */