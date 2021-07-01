/**
Este programa lee �rboles de la entrada est�ndar,
codificados de acuerdo con las siguientes reglas:
(1) El �rbol vac�o se codifica como #
(2) Los �rboles simples se codifican como [v], con
	v el valor del nodo
(3) Los �rboles complejos se codifican como (IvD),
	con I la codificaci�n del hijo izquierdo,
	v el valor de la ra�z, y D la codificaci�n
	del hijo derecho.
Para cada �rbol le�do, escribe en la salida est�ndar
el n�mero de nodos singulares de dicho �rbol.

Algunos casos representativos:
#
[0] 
[5]
(([4]3[-3])1[-4])
-El primero representa el �rbol vac�o. Al no tener nodos,
un �rbol vac�o tiene 0 nodos sigulares.
-El segundo representa un �rbol con un �nico nodo, cuyo valor
es 0. Dicho nodo es singular, ya que: (i) como no tiene
ascestros, la suma de los ancestros es 0, (ii) como no
tiene descendientes, la suma de los descendientes es 0.
-El tercero representa otro �rbol con un �nico nodo, cuyo
valor es 5. Por la misma raz�n que en el segundo ejemplo,
este nodo es singular.
-El cuarto representa el siguiente �rbol:

		   1
		  /  \
		  3  -4
		 / \
		4  -3
Este �rbol tiene 2 nodos sigulares: la ra�z, y la ra�z del hijo
izquierdo.
Por tanto, la salida del programa para estos casos ser�:
0
1
1
2
Algunos casos de prueba m�s:
ENTRADAS
(((#-2[-2])0#)0[-1])
(#-1[0])
([2]1[2])
(#-2(((#0([2]0(((((#1#)0(#0#))0(#-1[-2]))0(((#0#)2#)0[2]))0#)))2#)-1#))
((((#0[1])1#)1((#2(([-2]1#)1([2]1#)))0#))0(#0(#2[-1])))
SALIDAS ASOCIADAS
1
1
0
0
1
*/
#include "arbin_17.h"
#include <iostream>
#include <string>

using namespace std;

unsigned int aux_numero_singulares(const Arbin<int>& a, unsigned int contador, int suma);
unsigned int suma_descendientes(const Arbin<int>& a, int suma);

/**
  COMPLEJIDAD: Explica aqu� justificadamente cu�l es la complejidad de
			   esta funci�n
			   ***A COMPLETAR***
*/
unsigned int numero_singulares(const Arbin<int>& a) {
	int cont = 0, suma = a.raiz();
	if (a.esVacio())
	{
		return 0;
	}
	else
	{
		cont = aux_numero_singulares(a, cont, suma);
	}
	return cont;
}

unsigned int aux_numero_singulares(const Arbin<int>& a, unsigned int contador, int suma) {
	int aux  = suma_descendientes(a, 0);
	
	if (suma == aux)
	{
		contador++;
	}
	suma += a.raiz();
	if (a.esVacio())
	{
		return contador;
	}
	else
	{
		if (!a.hijoDer().esVacio())
		{
			contador = aux_numero_singulares(a.hijoDer(), contador, suma);
		}
		if (!a.hijoIz().esVacio())
		{
			contador = aux_numero_singulares(a.hijoIz(), contador, suma);
		}
	}
	return contador;
}

unsigned int suma_descendientes(const Arbin<int>& a, int suma) {
	if (a.esVacio())
	{
		return 0;
	}
	else
	{
		suma += a.raiz();
		if (!a.hijoDer().esVacio())
		{
			suma = suma_descendientes(a.hijoDer(), suma);
		}
		if (!a.hijoIz().esVacio())
		{
			suma = suma_descendientes(a.hijoIz(), suma);
		}
	}
	return suma;
}


Arbin<int> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF) {
		cout << numero_singulares(lee_arbol(cin)) << endl;
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}