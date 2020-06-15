#include "Cat.h"
#include "Animal.h"

Cat::Cat(int age, const char* sound, int tail_length, int num_of_souls, const char* breed)
	:Animal(age, sound), tail_length(tail_length), num_of_souls(num_of_souls)
{
	set_breed(breed);
}

Cat::Cat(const Cat& other)
: Animal(other), tail_length(tail_length)
{
	*this = other;
}

Cat::~Cat()
{
	delete[] this->breed;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other) {
		Animal::operator=(other);
	}
	// this->tail_length = other.tail_length; // how to set const field
	this->num_of_souls = other.num_of_souls;
	set_breed(other.breed);
	return *this;
}

void Cat::make_fur_ball()
{
	for (int i = 0; i < this->tail_length; i++)
	{
		cout << "fur";
	}
	cout << endl;
}


void Cat::set_breed(const char* breed)
{
	if (breed != NULL) {
		if (this->breed != NULL)
			delete[]this->breed;

		int len = strlen(breed) + 1;
		this->breed = new char[len];
		assert(this->breed);
		strcpy_s(this->breed, len, breed);
	}
}
