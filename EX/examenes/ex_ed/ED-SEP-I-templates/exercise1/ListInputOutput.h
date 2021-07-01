#pragma once
#include <iostream>
#include <string>
#include "List.h"
using namespace std;

// It reads a list of positive integers ended by -1 from the 
// the standard input
List<int> readList() {
	int elem;
	cin >> elem;
	List<int> list = List<int>();
	while (elem >= 0) {
		list.push_back(elem);
		cin >> elem;
	}
	return list;
}

// It prints a list of intergers
void printList(List<int>& list) { 
	string res;
	List<int>::Iterator it = list.cbegin();
	while (it != list.cend()) {
		cout << it.elem();
		it.next();
		if (it != list.cend())
			cout << " ";
	}
	cout << endl;
}