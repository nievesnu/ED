// EDseptember1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h"
#include "ListInputOutput.h"

void solveCase() {
	List<int> l1 = readList();
	List<int> l2 = readList();
	l1.merge(l2);
	printList(l1);
}

int main()
{
	int numCases;
	cin >> numCases;
	for (int i = 0; i < numCases; i++)
		solveCase();
}

