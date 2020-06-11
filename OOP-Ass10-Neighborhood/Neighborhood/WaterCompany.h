#pragma once
#include "House.h"

class WaterCompany {

public:

	// The water company measures water consumption, calculates the payment and updates the data.
	void add_usage(House& h, float consumption = 100);

};