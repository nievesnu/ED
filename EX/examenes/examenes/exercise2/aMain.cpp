// Name:
// Surname:

#include <iostream>
#include <algorithm>
#include "Bintree.h"
#include "List.h"
using namespace std;
Bintree<int> readBintree();


/* It solves the case for a given input binary tree, and returns
the number.
The student should implement this function and probably
the generalization of this function. */
int solveCase(Bintree<int> t) {
	// IMPLEMENT THIS FUNCTION AND ITS GENERALIZATION
	return -1;
}



/* Main function*/
int main()
{
	int numCases;
	cin >> numCases;
	for (int i = 0; i < numCases; i++) {
		Bintree<int> t = readBintree();
		cout << solveCase(t) << endl;
	}
}


// It reads a binary tree of integers from the standard input
Bintree<int> readBintree() {
	char c;
	cin >> c;
	switch (c) {
	case '#': return Bintree<int>();
	case '[': {
		int raiz;
		cin >> raiz;
		cin >> c;
		return Bintree<int>(raiz);
	}
	case '(': {
		Bintree<int> left = readBintree();
		int root;
		cin >> root;
		Bintree<int> right = readBintree();
		cin >> c;
		return Bintree<int>(left, root, right);
	}
	default:
		return Bintree<int>();
	}
}
