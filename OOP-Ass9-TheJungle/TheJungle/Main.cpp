// Pinhas Ziv, Nir Avisror
#include "Monkey.cpp"

int main() {
	
	// create monkies.
	Monkey monk;
	Monkey monk1(8, "moka11", 34.25);
	Monkey monk2(-3, "sami", 42);
	Monkey monk3(5, "charly", 270);

	Monkey *monk4 = new Monkey();
	if (monk4 == NULL) {
		cout << "Cannot allocate memory" << endl;
		exit(1);
	}

	Monkey *monk5 = new Monkey(10, "tintin", 50);
	if (monk5 == NULL) {
		cout << "Cannot allocate memory" << endl;
		exit(1);
	}

	// change fields
	monk5->setName("JOE");
	monk4->setWeight(55);
	monk1.setAge(12);

	
	// create an array of monkies
	Monkey monkies[6] = { monk, monk1, monk2, monk3, *monk4, *monk5 };

	// print the monkies fields
	for (int i = 0; i < 6; i++){
		(monkies+i)->print();
	}

	// first monkey eat * 20
	for (int i = 0; i < 20; i++) {
		monkies->eat("food");
	}
	cout << monkies->getName() << " weight: " << monkies->getWeight() << endl;
	
	// second monkey poop * 15
	for (int i = 0; i < 15; i++) {
		(monkies+1)->poop();
	}
	cout << (monkies+1)->getName() << " weight: " << (monkies+1)->getWeight() << endl;

	delete monk4;
	delete monk5;
	
	return 0;
}