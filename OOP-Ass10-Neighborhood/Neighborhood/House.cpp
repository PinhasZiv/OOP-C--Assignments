// Pinhas Ziv, Nir Avisror
#include "House.h"

House::House(float water_consumption, int debt){
	this->water_consumption = water_consumption;
	this->debt = debt;
}

void House::print(){
	cout << "water_consumption: " << water_consumption << ", debt: " << debt << endl;
}