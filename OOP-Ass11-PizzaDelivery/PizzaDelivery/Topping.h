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
	// Fields constructor
	Topping(const char* name, char coverege, float price = 10);
	// Default constructor seperatly (because in the assignment instructions it is written
	// that different values must be set for the price
	// in the parametric constructor and in the dipolar constructor
	Topping() { this->name = NULL, this->coverege = 'f', this->price = 0;  };
	// Copy constructor
	Topping(const Topping& other);
	// Destructor
	~Topping();
	void setName(const char* name);
	void setCoverege(const char coverege); // (r\l\f. default = f)
	void setPrice(const float price); // (price > 0. default = 0)
	char getCoverege() const;
	float getPrice() const; // get the field 'price'
	float getCalcPrice() const; // get the calculate price (depends on coverege)
	Topping& operator=(const Topping &other);
	friend ostream& operator<<(ostream & output, const Topping& other); // print Topping fields (print the calcPrice of Topping. depends on coverege).
	bool operator<(const Topping& other) const;
	bool operator>(const Topping& other) const;
	bool operator==(const Topping& other) const;
};

