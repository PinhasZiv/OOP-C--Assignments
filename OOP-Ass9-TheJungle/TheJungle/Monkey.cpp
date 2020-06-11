// Pinhas Ziv, Nir Avisror
#include <iostream>
using namespace std;

class Monkey {

private:
	int _age; // _age >= 0 , _age <= 100
	char* _name; // without digits
	double _weight; // _weight >= 3 , _weight >= 200

public:

	// Default constractor
	Monkey() {
		_age = 0;
		_name == NULL;
		setName("NoName");
		_weight = 0;
	}

	// Fields constractor
	Monkey(int age, const char* name, double weight) {
		setAge(age);
		_name = NULL;
		setName(name);
		setWeight(weight);
	}

	// Copying constructor. for array of monkies (calls the copy constructor when initialize the monkies)
	Monkey(const Monkey& monkey) {
		_age = monkey._age;
		_weight = monkey._weight;
		_name = NULL;
		_name = new char[strlen(monkey._name) + 1];
		strcpy_s(_name, strlen(monkey._name) + 1, monkey._name);
	}

	int getAge(){
		return _age;
	}

	const char* getName() {
		return _name;
	}

	double getWeight() {
		return _weight;
	}

	// set weight field (_weight >= 3 , _weight <= 200, else: _weight = 100)
	void setWeight(double weight) {
		if (weight < 3 || weight > 200) {
			cout << "Error: weight" << endl;
			_weight = 100;
		} else {
			_weight = weight;
		}
	}

	// set name field (without digits, else: _name = "Kofiko")
	void setName(const char* str) {
		int i = 0;
		while (*(str + i) != '\0') {
			if (*(str + i) >= '0' && *(str + i) <= '9') {
				cout << "Error: name" << endl;
				char tmp[] = "Kofiko";
				_name = NULL;
				_name = new char[strlen(tmp) + 1];

				if (_name == NULL) {
					cout << "Cannot allocate memory" << endl;
					exit(1);
				}

				strcpy_s(_name, strlen(tmp) + 1, tmp);
				return;
			}
			i++;
		}
			int size = strlen(str);
			_name = NULL;
			_name = new char[size + 1];

			if (_name == NULL) {
				cout << "Cannot allocate memory" << endl;
				exit(1);
			}

			strcpy_s(_name, size + 1, str);
	}

	// set age field (_age >= 0 , _age <= 100, else: _age = 40)
	void setAge(int age) {
		if (age < 0 || age > 100) 
			_age = 40;
		else 
			_age = age;
	}

	// print the fields of a monkey
	void print() {
		cout << "Name: " << _name << ", Age: "
			<< _age << ", Weight: " << _weight << endl;
	}
	// a monkey eat. (monkey weight set _weight += 10)
	void eat(const char* food) {
		setWeight(_weight + 10);
		cout << _name << " eats " << food << endl;
	}

	// a monkey poop. (monkey weight set _weight -= 15)
	void poop() {
		setWeight(_weight - 15);
		cout << _name << " poops " << endl;
	}

	// distructor
	~Monkey() {
		delete[] _name;
	}
};