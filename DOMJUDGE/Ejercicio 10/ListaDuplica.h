//Álvaro Miguel Rodríguez Mateos

#ifndef ListaDuplica_h
#define ListaDuplica_h

#include <iostream>
#include <string>
#include "queue_eda.h"

template <class T>
class ListaDuplica : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:

     void insertarElementos(ListaDuplica<T>& nuevaLista, const int& p) {

        Nodo* nodoActual = this->prim;

        for (int i = 0; i < p - 1 && nodoActual->sig != nullptr; i++) {
            nodoActual = nodoActual->sig;
        }

        Nodo* tmp = nodoActual->sig;

        if (p == 0) {
            if (nodoActual->sig == nullptr) {
                this->ult = nodoActual;
            }
            nuevaLista.ult->sig = nodoActual;
            nodoActual = nuevaLista.prim;
            this->prim = nodoActual;
        }
        else {
            nodoActual->sig = nuevaLista.prim;
            nuevaLista.ult->sig = tmp;
            if (tmp == nullptr) {
                this->ult = nuevaLista.ult;
            }
        }

        this->nelems = this->nelems + nuevaLista.size();

        nuevaLista.nelems = 0;
        nuevaLista.prim = nullptr;
        nuevaLista.ult = nullptr;
    }

     friend std::ostream& operator<<(std::ostream& output, ListaDuplica<T>& lista) {

         for (size_t i = 0; i < lista.size(); i++) {
             int temp = lista.front();
             output << temp << " ";
             lista.push(temp);
             lista.pop();
         }

         return output;
     }

};


#endif // ListaDuplica_h