//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <list>

using namespace std;

using diccionario = std::map<std::string, int>;

void resolver(const diccionario& viejo, const diccionario& nuevo) {

    auto itViejo = viejo.cbegin();
    auto itNuevo = nuevo.cbegin();

    std::list<std::string>nuevos, eliminados, cambiados;

    while (itViejo != viejo.cend() || itNuevo != nuevo.cend()) {
        if (itViejo != viejo.cend() && itNuevo != nuevo.cend() && itViejo->first == itNuevo->first) {
            if (itViejo->second != itNuevo->second) cambiados.push_back(itViejo->first);
            itViejo++; itNuevo++;
        }
        else if (itNuevo != nuevo.cend() && itViejo != viejo.cend() && itViejo->first > itNuevo->first) {
            nuevos.push_back(itNuevo->first);
            itNuevo++;
        }
        else if (itViejo != viejo.cend() && itNuevo != nuevo.cend() && itViejo->first < itNuevo->first) {
            eliminados.push_back(itViejo->first);
            itViejo++;
        }
        else if (itViejo == viejo.cend() && itNuevo != nuevo.cend()) {
            nuevos.push_back(itNuevo->first);
            itNuevo++;
        }
        else if (itViejo != viejo.cend() && itNuevo == nuevo.cend()) {
            eliminados.push_back(itViejo->first);
            itViejo++;
        }

    }

    if (nuevos.size() == 0 && eliminados.size() == 0 && cambiados.size() == 0)
        std::cout << "Sin cambios\n";
    else {
        if (nuevos.size() != 0) {
            std::cout << "+";
            for (auto& n : nuevos)
                std::cout << " " << n;
        }

        if (eliminados.size() != 0) {
            std::cout << "\n" << "-";
            for (auto& e : eliminados)
                std::cout << " " << e;
        }

        if (cambiados.size() != 0) {
            std::cout << "\n" << "*";
            for (auto& m : cambiados)
                std::cout << " " << m;
        }
        std::cout << "\n";
    }
}

void resuelveCaso() {

    diccionario viejo, nuevo;
    std::string clave, entrada;
    int valor;
    
    getline(std::cin, entrada);

    std::stringstream v(entrada);
    while (v >> clave >> valor)
        viejo[clave] = valor;

    getline(std::cin, entrada);
    std::stringstream n(entrada);

    while (n >> clave >> valor) {
        nuevo[clave] = valor;
    }

    resolver(viejo, nuevo);

    std::cout << "---" << endl;
}

int main() {

    // Para la entrada por fichero.
    // Comentar para acepta el reto
//#ifndef DOMJUDGE
//    std::ifstream in("datos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif

    int n;
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; ++i)
        resuelveCaso();

//    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    //system("PAUSE");
//#endif

}