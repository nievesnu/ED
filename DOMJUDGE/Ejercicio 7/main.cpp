//Álvaro Miguel Rodríguez Mateos
//A63

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

void calculaVictimas(std::stack<std::string>& pila1, std::stack<int>& pila2) {


    std::stack<std::string> aux1 = pila1;

    std::stack<int> aux2 = pila2;

    std::stack<std::string> pilaSalida;

    int v;
    int size = pila1.size();
    bool exit;

    pilaSalida.push("---");

    for(int i = size-1; i >= 0; i--) {

        v = pila2.top();
        aux1.pop();
        aux2.pop();

        if (i == 0) {
            pilaSalida.push("NO HAY");
        }

        else {
            exit = false;

            for (size_t j = 0; (j < aux2.size()) && (!exit); j++) {
                if (aux2.top() > v) {
                    exit = true;
                }
                else {
                    aux2.pop();
                    aux1.pop();
                }

            }

       
            if (!aux1.empty()) { 
                pilaSalida.push(aux1.top());
            }
            else {
                pilaSalida.push("NO HAY");
            }

            pila1.pop();
            pila2.pop();
            aux1 = pila1;
            aux2 = pila2;
            exit = false;

        }

    }

    for (int k = 0; k <= size; k++) {
        std::cout << pilaSalida.top() << "\n";
        pilaSalida.pop();
    }

}

bool resuelveCaso() {


    int n;
    std::cin >> n;

    if ((!std::cin ) || (n == 0)) {
        return false;
    };
    std::string entrada;

    int v;
   

    std::stack<std::string> pilaFechas;
    std::stack<int> pilaMuertes;

    for (int i = 0; i < n; i++) {

        std::cin >> entrada;

        if (!std::cin) return false;

        std::cin >> v;
        if (!std::cin) {
            return false;
        };

        pilaFechas.push(entrada);
        pilaMuertes.push(v);
    }

    calculaVictimas(pilaFechas, pilaMuertes);

    //lista.intercambia();


    return true;
}

int main() {

    // Para la entrada por fichero.
    // Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	//system("PAUSE");
//#endif

}