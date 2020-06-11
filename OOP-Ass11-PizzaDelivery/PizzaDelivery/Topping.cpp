#include "Topping.h"

Topping::Topping(const char* name, char coverege, float price)
{
	setName(name);
	setCoverege(coverege);
	setPrice(price);
}

Topping::Topping(const Topping& other)
{
	this->name = nullptr;
	*this = other;
}

Topping::~Topping()
{
	delete[] name;
}

void Topping::setName(const char* name)
{
	if (name != nullptr)
	{
		if (this->name != nullptr)
			delete[] this->name;
		int size = strlen(name) + 1;
		this->name = new char[size];
		assert(this->name);
		strcpy_s(this->name, size, name);
	}
	else
		this->name = nullptr;
}

void Topping::setCoverege(const char coverege)
{
	if (coverege != 'r' && coverege != 'l' && coverege != 'f')
	{
		cout << "coverege not valid. set to 'f'" << endl;
		this->coverege = 'f';
	}
	else
		this->coverege = coverege;
}

void Topping::setPrice(const float price)
{
	if (price <= 0)
		cout << "Price not valid" << endl;
	else
		this->price = price;
}

float Topping::getPrice()
{
	return this->price;
}

Topping& Topping::operator=(const Topping& other)
{
	if (this != &other) {
		setName(other.name);
		setCoverege(other.coverege);
		setPrice(other.price);
	}
	return *this;
}

bool Topping::operator<(const Topping& other) const
{
	return (this->price < other.price);
}

bool Topping::operator==(const Topping& other) const
{
	return (this->coverege == other.coverege);
}

bool Topping::operator>(const Topping& other) const
{
	return (this->price > other.price);
}

ostream& operator<<(ostream& output, const Topping other)
{
	return output << "Topping: \nname: " << other.name << ", coverage: "
		<< other.coverege << ", price: " << other.price << endl;
}

