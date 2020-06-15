#pragma once
#include "Cat.h"
class DomesticCat:public Cat
{
	int itchiness_level;
	char* name;
public:
	DomesticCat(int age, const char* sound, const char* name, int itchiness_level, int tail_length, int num_of_souls, const char* breed);
	DomesticCat(const DomesticCat& other);
	DomesticCat& operator=(const DomesticCat& other);
	~DomesticCat(); // check how to initialize
	void print();
	void set_name(const char* name);
	void scratch();
	void make_sound();
	int calcFood();

};

