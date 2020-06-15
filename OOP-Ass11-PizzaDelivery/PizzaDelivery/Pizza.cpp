#include "Pizza.h"

Pizza::Pizza(const char* type, const float baseprice, const Topping* topings, const int num_top)
{
	if(type != nullptr) // For default constructor 
		setType(type);
	setBaseprice(baseprice);
	setTopings(num_top);

}

Pizza::Pizza(const Pizza& other)
{
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
	this->type = new char[len];
	assert(this->type);
	strcpy_s(this->type, len, type);
}

void Pizza::setBaseprice(const float baseprice)
{
	if (baseprice <= 0) {
		cout << "baseprice not valid. set to 50" << endl;
		this->baseprice = 50;
	}
	else
		this->baseprice = baseprice;
}

void Pizza::setTopings(const int num_top)
{
	if (num_top < 0) {
		cout << "num top not valid. set to 0." << endl;
		this->num_top = 0;
	} else
		this->num_top = num_top;
	if(this->topings != nullptr)
		delete[] this->topings;
	if (this->num_top != 0) {
		this->topings = new Topping[this->num_top];
		assert(this->topings);
	}
	else
		this->topings = nullptr;
}

void Pizza::setToppingPrice(const int index, const float price)
{
	this->topings[index].setPrice(price);
}

 Topping& Pizza::getTopings() const
{
	return *this->topings;
}

float Pizza::calcPrice() const
{
	float totalPrice = this->baseprice;
	for (int i = 0; i < this->num_top; i++)
	{
			totalPrice += this->topings[i].getCalcPrice();
	}
	return totalPrice;
}

Pizza& Pizza::operator=(const Pizza& other)
{
	if (this != &other) {
		this->setType(other.type);
		this->baseprice = other.baseprice;
		this->setTopings(other.num_top);
		for (int i = 0; i < this->num_top; i++)
		{
			this->topings[i] = other.topings[i];
		}
	}
	return *this;
}

Pizza& Pizza::operator+(const Topping& other)
{
	this->topings[this->counter++] = other;
	return *this;
}

bool Pizza::operator==(const Pizza& other) const
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
	output << "Total Price: " << other.calcPrice() << endl;
	return output;
}
