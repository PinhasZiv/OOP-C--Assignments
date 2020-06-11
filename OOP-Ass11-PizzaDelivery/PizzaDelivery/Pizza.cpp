#include "Pizza.h"

Pizza::Pizza(const char* type, const float baseprice, const Topping* topings, const int num_top)
{
	if(type != nullptr)
		setType(type);
	setBaseprice(baseprice);
	if(topings != nullptr)
		setTopings(num_top);
	this->num_top = num_top;

}

Pizza::Pizza(const Pizza& other)
{
	this->type = nullptr;
	*this = other;
}

Pizza::~Pizza()
{
	delete[] this->type;
	delete[] this->topings;
}

void Pizza::setType(const char* type)
{
	if(this->type != nullptr)
		delete[] this->type;
	int len = strlen(type) + 1;
	this->type = new char[strlen(type) + 1];
	assert(this->type);
	strcpy_s(this->type, len, type);
}

void Pizza::setBaseprice(const float baseprice)
{
	if (baseprice <= 0)
		cout << "baseprice not valid" << endl;
	else
		this->baseprice = baseprice;
}

void Pizza::setTopings(const int num_top)
{
	this->num_top = num_top;
	if(this->topings != nullptr)
		delete[] this->topings;
	this->topings = new Topping[this->num_top];
	assert(this->topings);
}

void Pizza::setToppingPrice(const int index, const float price)
{
	this->topings[index].setPrice(price);
}

 Topping* Pizza::getTopings()
{
	return this->topings;
}

float Pizza::calcPrice()
{
	float totalPrice = this->baseprice;
	for (int i = 0; i < this->num_top; i++)
	{
		totalPrice += this->topings[i].getPrice();
	}
	return totalPrice;
}

Pizza& Pizza::operator=(const Pizza& other)
{
	if (this != &other) {
		setType(other.type);
		setBaseprice(other.baseprice);
		setTopings(other.num_top);
		this->num_top = other.num_top;
	}
	return *this;
}

Pizza& Pizza::operator+(const Topping& other)
{
	this->topings[this->counter++] = other;
	return *this;
}

bool Pizza::operator==(const Pizza& other)
{
	for (int i = 0; i < this->num_top; i++)
	{
		if (!(this->topings[i] == other.topings[i]))
			return false;
	}
	return true;
}



ostream& operator<<(ostream& output, const Pizza& other)
{
	output << "Pizza:\nType: " << other.type << ", Base price: "
		<< other.baseprice << endl;
	for (int i = 0; i < other.num_top; i++)
	{
		output << other.topings[i];
	}
	return output;
}
