#pragma once
#include <string>
#include "List.h"
#include "SearchTree.h"
#include "Table.h"
#include "Queue.h"
using namespace std;

// Definition of the necessary types for the template
typedef string Service;
typedef string Product;
struct BillItem {
	Product product;
	int units;
};
struct Bill{
	List<BillItem> units;
	int price ;
};

// Definition of the type of the solution
struct Command {
	Service service;
	List<Product> products;
	int price;
};

struct ServiceInfo {
	SearchTree<Product, int> units;
	int price;
	int pendingCommands;
};

/* Template for the Exam about SpicyChips restaurant. 
Read the instructions carefully to know the behaviour that you 
have to implement for each funcion*/
class CommandManagement {
public:
	// Builder
	CommandManagement() {
		// To be implemented here.
		menu = Table<Product, int>();
		commands = Queue<Command>();
		services = Table<Service, ServiceInfo>();
	}

	void registerService(Service s) {
		// To be implemented here.
		if(services.exists(s)){
			throw EServiceExists();
		}
		else {
			ServiceInfo si;
			si.units = SearchTree<Product, int>();
			si.price = 0;
			si.pendingCommands = 0;
			services.insert(s, si);
		}
	}

	void registerProduct(Product p, int c) {
		// To be implemented here.
		menu.insert(p, c);
	}

	void registerCommand(Service s, List<Product> ps) {
		// To be implemented here
		if (!services.exists(s)) {
			throw ERegisterCommand();
		}
		Command c;
		c.price = 0;
		List<Product>::Iterator it = ps.cbegin();
		while (it != ps.cend()) {
			if (menu.exists(it.elem())) {
				c.price += menu.get(it.elem());
			}
			else {
				throw ERegisterCommand();
			}
			it.next();
		}
		c.service = s;
		c.products = ps;
		commands.push(c);
		services.get(s).pendingCommands++;
	}

	void processCommand() {
		// To be implemented here
		if (commands.empty()) {
			throw ENoCommands();
		}
		Command c = commands.front();
		services.get(c.service).price += c.price;
		services.get(c.service).pendingCommands--;
		List<Product>::Iterator it = c.products.cbegin();
		while (it != c.products.cend()) {
			int units = 0;
			if(services.get(c.service).units.exists(it.elem()))
				units = services.get(c.service).units.get(it.elem()); 
			services.get(c.service).units.insert(it.elem(), units+1);
			it.next();
		}
		commands.pop();
	}
	Bill closeService(Service s){
		// To be implemented here. You can replace the following code with your code.
		if (!services.exists(s) || services.get(s).pendingCommands > 0)
			throw ECloseService();
		Bill b;
		b.units = List<BillItem>();
		SearchTree<Product, int>::Iterator it = services.get(s).units.begin();
		while (it != services.get(s).units.end()) {
			BillItem bi;
			bi.product = it.key();
			bi.units = it.value();
			b.units.push_back(bi);
			it.next();
		}
		b.price = services.get(s).price;
		services.remove(s);
		return b;
	}
	

private:
	// INCLUDE HERE THE PRIVATE ATTRIBUTES
	Table<Product, int> menu;
	Queue<Command> commands;
	Table<Service, ServiceInfo> services;
};
