#include "DomesticCat.h"

DomesticCat::DomesticCat(int age, const char* sound, const char* name, int itchiness_level, int tail_length, int num_of_souls, const char* breed)
:Cat::Cat(age, sound, tail_length, num_of_souls, breed), itchiness_level(itchiness_level)
{
	set_name(name);
}

DomesticCat::DomesticCat(const DomesticCat& other)
	:Cat(other)
{
	*this = other;
}

DomesticCat& DomesticCat::operator=(const DomesticCat& other)
{
	if (this != &other) {
		Cat::operator=(other);
		this->itchiness_level = other.itchiness_level;
		set_name(other.name);
	}
	return *this;
}

DomesticCat::~DomesticCat() // check if ok
{
	delete[] this->name;
}

void DomesticCat::set_name(const char* name)
{
	if (name != NULL) {
		if (this->name != NULL)
			delete[]this->name;

		int len = strlen(name) + 1;
		this->name = new char[len];
		assert(this->name);
		strcpy_s(this->name, len, name);
	}
}

void DomesticCat::print()
{
	cout << "Domestic Cat Name: " << this->name << ", Breed: " << this->breed
		<< ", Age " << this->age << " Souls: " << this->num_of_souls
		<< ", Tail: " << this->tail_length << "'' long" << endl;
}

void DomesticCat::make_sound()
{
	cout << "I Miau you " << this->sound << endl;
}

int DomesticCat::calcFood()
{
	return (10 * this->itchiness_level);
}

void DomesticCat::scratch()
{
	if (this->itchiness_level < 5)
		cout << "I'm not so itchy!!!" << endl;
	if (this->itchiness_level >= 5 && this->itchiness_level <= 8)
		cout << "I'm so itchy!!!" << endl;
	else
		cout << "I'm very itchy!!!" << endl;
}


