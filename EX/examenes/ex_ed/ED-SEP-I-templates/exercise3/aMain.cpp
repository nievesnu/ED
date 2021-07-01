// Do not change this file

#include <iostream>
#include <string>
#include <fstream>
#include "CommandManagement.h"
#include "SearchTree.h"
using namespace std;

void registerService(CommandManagement &cm) {
	Service s;
	cin >> s;
	try {
		cm.registerService(s);
	}
	catch (EServiceExists e) {
		cout << "EServiceExists" << endl;
	}
}

void registerProduct(CommandManagement &cm) {
	Product p;
	int c;
	cin >> p;
	cin >> c;
	cm.registerProduct(p, c);
}

void registerCommand(CommandManagement& cm) {
	Service s;
	Product p;
	cin >> s;
	List<Product> ps = List<Product>();
	cin >> p;
	while (p.compare("end")) {
		ps.push_back(p);
		cin >> p;
	}
	try {
		cm.registerCommand(s, ps);
	}
	catch (ERegisterCommand e) {
		cout << "ERegisterCommand" << endl;
	}
}

void processCommand(CommandManagement& cm) {
	try {
		cm.processCommand();
	}
	catch (ENoCommands e) {
		cout << "ENoCommands" << endl;
	}
}

void closeService(CommandManagement& cm) {
	Service s;
	cin >> s;
	try {
		Bill b = cm.closeService(s);
		List<BillItem>::Iterator it = b.units.cbegin();
		while (it != b.units.cend()) {
			cout << it.elem().product << " " << it.elem().units << " ";
			it.next();
		}
		cout << b.price << endl;
	}
	catch (ECloseService e) {
		cout << "ECloseService" << endl;
	}
}

/* Template for the Exam about Spicy Chips.
This file does not need to be changed */
bool solveCase() {
	string op;
	cin >> op;
	CommandManagement cm = CommandManagement();
	bool ret = op.compare("end");
	while (op.compare("end")) {
		if (!op.compare("registerService")) {
			registerService(cm);
		}else if (!op.compare("registerProduct")) {
			registerProduct(cm);
		}else if (!op.compare("registerCommand")) {
			registerCommand(cm);
		}else if (!op.compare("processCommand")) {
			processCommand(cm);
		}else if (!op.compare("closeService")) {
			closeService(cm);
		}
		cin >> op;
	}
	return ret;
}

int main()
{
	while (solveCase()){}
}
