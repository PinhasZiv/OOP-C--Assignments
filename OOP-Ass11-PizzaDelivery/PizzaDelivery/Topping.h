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
	// Union constructor of fields and default constructor
	Topping(const char* name, char coverege, float price = 10);
	Topping() { this->name = NULL, this->coverege = 'f', this->price = 0;  };
	Topping(const Topping& other);
	~Topping();
	void setName(const char* name);
	void setCoverege(const char coverege);
	void setPrice(const float price);
	char getCoverege() const;
	float getPrice() const; // get the field 'price'
	float getCalcPrice() const; // get the calculate price (depends on coverege)
	Topping& operator=(const Topping &other);
	friend ostream& operator<<(ostream & output, const Topping& other);
	bool operator<(const Topping& other) const;
	bool operator>(const Topping& other) const;
	bool operator==(const Topping& other) const;
};

