//Álvaro Miguel Rodríguez Mateos
//A63

#ifndef bintree_eda_18_h
#define bintree_eda_18_h

#include <iostream>
#include <algorithm>
#include "bintree_eda.h"

template<class T>
class bintreeExtendido : public bintree<T> {
    using Link = typename bintree<T>::Link;

public:

    bintreeExtendido() : bintree<T>() {
    
    }

    bintreeExtendido(bintreeExtendido<T> const& l, T const& e, bintreeExtendido<T> const& r) : bintree<T>(l, e, r) {
    
    }

    int altura() const {
        return altura(this->raiz);
    }

    int nodos() const {
        return nodos(this->raiz);
    }

    int hojas() const {
        return hojas(this->raiz);
    }

private:

    int altura(Link r) const {
        if (r == nullptr)
            return 0;
        else
            return 1 + std::max(altura(r->left), altura(r->right));
    }

    int nodos(Link r) const {
        if (r == nullptr)
            return 0;
        else
            return 1 + nodos(r->left) + nodos(r->right);
    }

    int hojas(Link r) const {
        if (r == nullptr)
            return 0;
        else {
            if (hojas(r->left) + hojas(r->right) == 0)
                return 1;
            else
                return hojas(r->left) + hojas(r->right);
        }
    }

};

template <class T>
inline bintreeExtendido<T> leerBintreeExtendido(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) {
        return {};
    }
    else {
        auto iz = leerBintreeExtendido(vacio);
        auto dr = leerBintreeExtendido(vacio);
        return { iz, raiz, dr };
    }
}


#endif /* bintree_eda_18_h */