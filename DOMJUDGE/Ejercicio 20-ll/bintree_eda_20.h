//Álvaro Miguel Rodríguez Mateos
//A63

#ifndef bintree_eda_20_h
#define bintree_eda_20_h

#include <iostream>
#include <algorithm>
#include "bintree_eda.h"

template<class T>
class bintreeMinimo : public bintree<T> {
    using Link = typename bintree<T>::Link;

public:

    bintreeMinimo() : bintree<T>() {}

    bintreeMinimo(bintreeMinimo<T> const& l, T const& e, bintreeMinimo<T> const& r) : bintree<T>(l, e, r) {}

    T minimo() const {
        T min;
        minimo(this->raiz, min);
        return min;
    }


private:

    void minimo(Link r, T& min) const {
        if (r->left == nullptr && r->right == nullptr)
            min = r->elem;
        else {
            T minIz, minDr;
            if (r->left != nullptr) {
                minimo(r->left, minIz);
                min = std::min(r->elem, minIz);

                if (r->right != nullptr) {
                    minimo(r->right, minDr);
                    min = std::min(min, minDr);
                }
            }
            else {
                minimo(r->right, minDr);
                min = std::min(r->elem, minDr);
            }
        }

    }
};

template <class T>
inline bintreeMinimo<T> leerArbolMinimo(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) {
        return {};
    }
    else {
        auto iz = leerArbolMinimo(vacio);
        auto dr = leerArbolMinimo(vacio);
        return { iz, raiz, dr };
    }
}

#endif /* bintree_eda_20_h */