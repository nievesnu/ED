#ifndef bintree_eda_19_h
#define bintree_eda_19_h

#include <iostream>
#include <algorithm>
#include "bintree_eda.h"

template<class T>
class bintreeFrontera : public bintree<T> {
    using Link = typename bintree<T>::Link;

public:

    bintreeFrontera() : bintree<T>() {}

    bintreeFrontera(bintreeFrontera<T> const& l, T const& e, bintreeFrontera<T> const& r) : bintree<T>(l, e, r) {}

    std::vector<T> frontera() const {
        std::vector<T> sol;
        frontera(sol, this->raiz);
        return sol;
    }


private:

    void frontera(std::vector<T>& sol, Link r) const {
        if (r == nullptr) return;

        if (r->left == nullptr && r->right == nullptr)
            sol.push_back(r->elem);
        else if (r->left == nullptr && r->right != nullptr)
            frontera(sol, r->right);
        else if (r->left != nullptr && r->right == nullptr)
            frontera(sol, r->left);
        else {
            frontera(sol, r->left);
            frontera(sol, r->right);
        }
    }
};

template <class T>
inline bintreeFrontera<T> leerArbolFrontera(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) {
        return {};
    }
    else {
        auto iz = leerArbolFrontera(vacio);
        auto dr = leerArbolFrontera(vacio);
        return { iz, raiz, dr };
    }
}


#endif /* bintree_eda_19_h */