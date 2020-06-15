#pragma once
#include "Cat.h"
class WildCat:public Cat
{
	int hunger_level;
public:
	WildCat(int hunger_level, int age, const char* sound, int tail_length, int num_of_souls, const char* breed);
	void hunt();
	void make_sound();
	void print();
	int calcFood();
};

