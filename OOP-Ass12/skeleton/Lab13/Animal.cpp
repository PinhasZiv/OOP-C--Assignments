#include "Animal.h"

Animal::Animal(int age, const char* sound)
:age(age)
{
	set_sound(sound);
}

Animal::Animal(const Animal& other)
{
	*this = other;
}

Animal::~Animal()
{
	delete[] sound;
}


Animal& Animal::operator=(const Animal& other)
{
	if (this != &other) {
		this->age = other.age;
		set_sound(other.sound);
	}
	return *this;
}

void Animal::set_sound(const char* sound)
{
	if (sound != NULL) {
		if (this->sound != NULL) 
			delete[]this->sound;
		
		int len = strlen(sound)+1;
		this->sound = new char[len];
		assert(this->sound);
		strcpy_s(this->sound, len, sound);
	}
}

