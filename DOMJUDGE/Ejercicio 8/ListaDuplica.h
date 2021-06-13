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

    void duplicar() {
        Nodo* aux = this->prim;

        while (aux != nullptr) {
            Nodo* nuevo = new Nodo(aux->elem, aux->sig);
            if (nuevo->sig == nullptr)
                this->ult = nuevo;
            aux->sig = nuevo;
            aux = aux->sig->sig;
        }

        this->nelems = this->nelems * 2;
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