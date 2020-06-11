#pragma once
#include "Topping.h"
class Pizza
{
	char* type;
	float baseprice;
	Topping* topings;
	int num_top;
	int counter = 0; // count num of tops that was entered to topings field;

public:
	Pizza(const char* type = nullptr, const float baseprice = 50, const Topping* topings = nullptr, const int num_top = 0);
	Pizza(const Pizza& other);
	~Pizza();
	void setType(const char* type);
	void setBaseprice(const float baseprice);
	void setTopings(const int num_top);
	void setToppingPrice(const int index, const float price); // Function that get index and price of Topping and set its price
	Topping* getTopings();
	float calcPrice();
	Pizza& operator=(const Pizza& other);
	friend ostream& operator<<(ostream& output, const Pizza& other);
	Pizza& operator+(const Topping& other);
	bool operator==(const Pizza& other);
};

