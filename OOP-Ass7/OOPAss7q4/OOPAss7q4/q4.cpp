#include <iostream>

using namespace std;

// Declaration of functions.
void the_power(float*, float*);
void set_char(char*, char*);
void series(double*, double*, double*);
double series_next(double*, double*, double);


int main() {

	int userChoice = 0;
	bool validInput = 0;
	while (!validInput) {
		// Get the num of function to run from user.
		cout << "Enter a number (4-7): " << endl;
		cin >> userChoice;
		if (userChoice > 3 && userChoice < 8) {
			validInput = true;
		}
	}

	// running the appropriate function by user choice.
	switch (userChoice) {
		case 4:
			float num1, num2;
			cout << "Enter first number: " << endl;
			cin >> num1;
			cout << "Enter second number: " << endl;
			cin >> num2;
			the_power(&num1, &num2);
			cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
			break;
		case 5:
			char c1, c2;
			cout << "Enter a charactor: " << endl;
			cin >> c1;
			cout << "Enter another charactor: " << endl;
			cin >> c2;
			set_char(&c1, &c2);
			cout << "to lower: " << c1 << ", to upper: " << c2 << endl;
			break;
		case 6:
			double a, b, c;
			cout << "Enter the first number in the series: " << endl;
			cin >> a;
			cout << "Enter the second number in the series: " << endl;
			cin >> b;
			cout << "Enter the third number in the series: " << endl;
			cin >> c;
			series(&a, &b, &c);
			cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
			break;
		case 7:
			double a2, b2, c3;
			cout << "Enter the first number in the series: " << endl;
			cin >> a2;
			cout << "Enter the second number in the series: " << endl;
			cin >> b2;
			cout << "Enter the third number in the series: " << endl;
			cin >> c3;
			cout << "a = " << a2 << ", b = " << b2
				<< ", The value returned from the function: " 
				<< series_next(&a2, &b2, c3) << endl;
			break;
		}
		return 0;
}

// change the value in 'a' to a^b, and the value of 'b' to b^a.
	void the_power(float* a, float* b) {

		float tempa = *a; // using temp because the first pow change the value in *a.
		*a = pow(*a, *b);
		*b = pow(*b, tempa);
	}
// forced c1 to be a lowercase character, and c2 to be a uppercase charcter.
	void set_char(char* c1, char* c2) {

		*c1 = tolower(*c1);
		*c2 = toupper(*c2);
	}
	// The function receives three addresses of variables
	// that are successive invoice series organs ,when 'a' is smaller than them.
	// The function sets:
	// 'a' - series difference, 'b' the sum of the three organs, 'c' the next organ in the series after c.
	void series(double* a, double* b, double* c) {

		double tempa = *a; // using temp because the first placement action changed the value in *a.
		*a = (*b - *a);
		*b = (tempa + *b + *c);
		*c = (*c + *a);
	}

	// The function receives two variable addresses and an additional number 'c',
	// which are successive invoice series organs, with 'a' being the smaller of them.
	// The function places : 'a' - the series difference, 'b' - the sum of the three organs.
	// The function returns the next organ in the series after c.
	double series_next(double* a, double* b, double c) {

		*a = *b - *a;
		*b = (*a + *b + c);
		return *a + c;
	}
