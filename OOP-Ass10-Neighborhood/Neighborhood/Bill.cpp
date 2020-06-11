// Pinhas Ziv, Nir Avisror
#include "WaterCompany.h"

int main() {

	// Creating 3 houses
	House h1;
	House h2(55.5);
	House h3(12.4, 300);

	// Printing the fields
	h1.print();
	h2.print();
	h3.print();
	cout << "-------------------------" << endl;

	// Creating a water comany
	WaterCompany mekorot;
	// Adding 100 units of water (using deafult value)
	mekorot.add_usage(h1);
	mekorot.add_usage(h2);
	mekorot.add_usage(h3);

	// Printing the fields
	h1.print();
	h2.print();
	h3.print();
	cout << "-------------------------" << endl;

	// Paying the water debt and reset the debt
	pay(h1);
	pay(h2);
	pay(h3);

	// Printing the fields
	h1.print();
	h2.print();
	h3.print();
	cout << "-------------------------" << endl;

	return 0;
} 

// friend function of House class. resets water consumption
void pay(House& h) {
	h.debt = 0;
}