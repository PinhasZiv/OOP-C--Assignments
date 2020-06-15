#include "WildCat.h"
#include "DomesticCat.h"
#define SIZE 10
void main() {

	Animal* animals[SIZE];
	animals[0] = new DomesticCat(5, "Miauissimo", "Charley", 9, 7, 9, "Persian ");
	animals[2] = new DomesticCat(7, "Spoillllll", "Sleepy", 6, 2, 9, "American ");
	animals[4] = new DomesticCat(2, "Wiiii", "Loli", 5, 4, 9, "Scottish ");
	animals[6] = new DomesticCat(8, "MiiiiiiAUU", "Mitsi", 4, 8, 9, "Abyssinian ");
	animals[8] = new DomesticCat(9, "SpotSpot", "Spot", 3, 5, 9, "Devon Rex");
	animals[1] = new WildCat(9, 10, "rrrrrr", 6, 5, "African");
	animals[3] = new WildCat(3, 5, "Grrr", 2, 2, "Jungle");
	animals[5] = new WildCat(6, 5, "#!*tt", 3, 5, "Desert");
	animals[7] = new WildCat(2, 9, "SSSSSK", 4, 4, "Mountain");
	animals[9] = new WildCat(8, 7, "TCHHHH", 6, 3, "Asian");

	for (int i = 0; i < SIZE; i++)
	{
		cout << i + 1 << ") ";
		animals[i]->print();
		animals[i]->make_sound();
		((Cat*)(animals[i]))->make_fur_ball();

		if (typeid(*animals[i]) == typeid(DomesticCat))
		{
			DomesticCat* tmp = dynamic_cast<DomesticCat*>(animals[i]);
			cout << "Food requirement: " << tmp->calcFood() << endl;
			tmp->scratch();
		}
		else {
			WildCat* tmp = dynamic_cast<WildCat*>(animals[i]);
			cout << "Food requirement: " << tmp->calcFood() << endl;
			tmp->hunt();
		}
		cout << endl;
	}
	for (int i = 0; i < SIZE; i++)
	{
		delete animals[i];
	}

}