//Álvaro Miguel Rodríguez Mateos
//A63


#ifndef bintree_eda_22_h
#define bintree_eda_22_h

#include <iostream>
#include <algorithm>
#include "bintree_eda.h"

template<class T>
class bintreeRescate : public bintree<T> {
    using Link = typename bintree<T>::Link;

public:

    bintreeRescate() : bintree<T>() {}

    bintreeRescate(bintreeRescate<T> const& l, T const& e, bintreeRescate<T> const& r) : bintree<T>(l, e, r) {}

    void rescate(int& grupos, int& max) {
        rescate(this->raiz, grupos, max);
    }


private:

    void rescate(Link r, int& grupos, int& max) {
        int gruIzq, maxIzq, gruDer, maxDer;

        if (r == nullptr) {
            grupos = 0;
            max = 0;
        }

        else {
            rescate(r->left, gruIzq, maxIzq);
            rescate(r->right, gruDer, maxDer);

            if (gruIzq == 0 && gruDer == 0 && r->elem != 0)
                grupos = 1;
            else
                grupos = gruDer + gruIzq;

            if (maxIzq > maxDer)
                max = maxIzq + r->elem;
            else
                max = maxDer + r->elem;
        }

    }
};

template <class T>
inline bintreeRescate<T> leerArbolRescate(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) {
        return {};
    }
    else {
        auto iz = leerArbolRescate(vacio);
        auto dr = leerArbolRescate(vacio);
        return { iz, raiz, dr };
    }
}


#endif /* bintree_eda_22_h */