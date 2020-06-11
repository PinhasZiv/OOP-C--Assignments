#include <iostream>

using namespace std;

// Declaring variables const for Fixed prices.
const double PPKM = 8.25, PPFLOOR = 15.95, TIP = 1.1;
const int PPBOX = 2, EXTRAFORHEAVY = 20;

// Declaration of functions.
double totalPayment(double, int, int, int);

int main() {
	
	double km,payment;
	int floor, box, heavyObj;
	
	cout << "Enter num of km for transport: " << endl;
	cin >> km;
	cout << "Enter num of floors: " << endl;
	cin >> floor;
	cout << "Enter num of boxes: " << endl;
	cin >> box;
	cout << "Enter num of heavy furniture: " << endl;
	cin >> heavyObj;

	// payment recive total payment by the values the user entered.
	payment = totalPayment(km, floor, box, heavyObj);
	cout << "Total payment: " << payment << endl;

	return 0;
}

double totalPayment(double km, int floor, int box, int heavyObj) {

	// calculate price per values.
	double sumForKm = PPKM * km;
	double sumForFloors = PPFLOOR * floor;
	int sumForBoxes = PPBOX * box;
	int sumForHeavy	= EXTRAFORHEAVY * heavyObj;

	//TODO
	//check about the compiler circles three digits after the point
	return ((sumForKm + sumForFloors + sumForBoxes + sumForHeavy) * TIP);
}