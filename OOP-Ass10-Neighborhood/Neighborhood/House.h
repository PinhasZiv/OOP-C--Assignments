#pragma once
#include <iostream>
using namespace std;

class House{

	// Declaring fields
	float water_consumption;
	int debt;

public:

	// Fields constructor
	House(float water_consumption = 0, int debt = 0);
	void print();

	// Declaring friends class and functions
	friend class WaterCompany;
	friend void pay(House& h);
};

