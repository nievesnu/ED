// Name and surname:

// Implement the functions required in the exercise.
// You can define additional types

#pragma once
#include <string>
#include "List.h"

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

// DEFINE ADDITIONAL TYPES HERE IF NEEDED


/* Template for the Exam about SpicyChips restaurant. 
Read the instructions carefully to know the behaviour that you 
have to implement for each funcion*/
class CommandManagement {
public:
	// Builder
	CommandManagement() {
		// To be implemented here.
	}

	void registerService(Service s) {
		// To be implemented here. Replace the following code:
		throw EServiceExists();
	}

	void registerProduct(Product p, int c) {
		// To be implemented here.
	}

	void registerCommand(Service s, List<Product> ps) {
		// To be implemented here. Replace the following code:
		throw ERegisterCommand();
	}

	void processCommand() {
		// To be implemented here. Replace the following code:
		throw ENoCommands();
		
	}
	Bill closeService(Service s){
		// To be implemented here. Replace the following code:
		throw ECloseService();
		Bill b;
		return b;
	}
	

private:
	// INCLUDE HERE THE PRIVATE ATTRIBUTES
};
