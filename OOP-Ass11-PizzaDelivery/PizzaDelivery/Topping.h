#pragma once
#include <iostream>
#include <cassert>
using namespace std;

class Topping
{

	char* name;
	char coverege; // r, l, f.
	float price; // Greater than 0

public:

	Topping(const char* name = nullptr, char coverege = 'f', float price = 10);
	Topping(const Topping& other);
	~Topping();
	void setName(const char* name);
	void setCoverege(const char coverege);
	void setPrice(const float price);
	float getPrice();
	Topping& operator=(const Topping &other);
	friend ostream& operator<<(ostream & output, const Topping other);
	bool operator<(const Topping& other) const;
	bool operator>(const Topping& other) const;
	bool operator==(const Topping& other) const;
};

