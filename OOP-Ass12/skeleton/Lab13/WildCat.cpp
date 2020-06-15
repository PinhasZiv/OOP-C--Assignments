#include "WildCat.h"


WildCat::WildCat(int hunger_level, int age, const char* sound, int tail_length, int num_of_souls, const char* breed)
:Cat(age, sound, tail_length, num_of_souls, breed), hunger_level(hunger_level){}

void WildCat::hunt()
{
	if (this->hunger_level < 5)
		cout << "I'm chiling now talk to you'll later...." << endl;
	if (this->hunger_level > 4)
		cout << "I am a natural hunter!" << endl;
}

void WildCat::make_sound()
{
	cout << "I'm so wild " << this->sound << endl;
}

void WildCat::print()
{
	cout << "Age: " << this->age << ". Sound: " << this->sound
		<< ". Tail length: " << this->tail_length << ". Num of souls: " << this->num_of_souls
		<< ". Breed: " << this->breed << ". Hunger level: " << this->hunger_level << endl;
}

int WildCat::calcFood()
{
	return (this->hunger_level * this->tail_length);
}
