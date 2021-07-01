// EDp7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include "Bintree.h"
#include "List.h"
using namespace std;
Bintree<int> readBintree();

// It  calculates the height, the 
// number of nodes with postive inclination and the number of nodes
// with negative inclination
void solveCase(Bintree<int> t, int& height, int& nPos, int& nNeg) {
	if (t.empty()) {
		height = 0;
		nPos = 0;
		nNeg = 0;
	}
	else {
		int heightLf, heightRg, nPosLf, nPosRg, nNegLf, nNegRg;
		solveCase(t.leftChild(), heightLf, nPosLf, nNegLf);
		solveCase(t.rightChild(), heightRg, nPosRg, nNegRg);
		height = max(heightLf, heightRg)+1;
		nPos = nPosLf + nPosRg;
		nNeg = nNegLf + nNegRg;
		if (heightLf > heightRg)
			nNeg++;
		else if (heightRg > heightLf)
			nPos++;
	}
}

/* It solves the case for a given input binary tree, and returns
the number.
The student should implement this function and probably
the generalization of this function. */
int solveCase(Bintree<int> t) {
	int height, nPos, nNeg, ret=0;
	solveCase(t, height, nPos, nNeg);
	if (nNeg > nPos)
		ret = -1;
	else if (nPos > nNeg)
		ret = 1;
	return ret;
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
