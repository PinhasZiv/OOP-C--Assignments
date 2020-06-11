// Pinhas Ziv, Nir Avisror
#include "WaterCompany.h"

void WaterCompany::add_usage(House& h, float consumption){
	h.water_consumption += consumption;
	h.debt += (10 * consumption);
}