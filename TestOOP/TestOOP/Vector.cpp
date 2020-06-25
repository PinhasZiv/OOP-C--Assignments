#include "Vector.h"

Vector::Vector(const Vector& other) {

	*this = other;
}
void Vector::setValue(const int value, const int index) {
	this->vecArray[index] = value;
}
void Vector::setVecArray() {

	for (int i = 0; i < this->size; i++) {
		int value;
		cout << "enter value for " << i << " place" << endl;
		cin >> value;
		setValue(value, i);
	}
}
int Vector::get_value(const int index) const{
	return this->vecArray[index];
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other && &other != NULL) {
		this->size = other.size;
		
		if (this->vecArray != NULL)
			delete[]vecArray;
		this->vecArray = new int[size];
		assert(this->vecArray);// check if the memory save was succsed

		for (int i = 0; i < this->size; i++) {
			setValue(other.get_value(i), i);
		}
	}
	return *this;
}
 ostream& operator<<(ostream& out, const Vector& other) {
	 out << "[ ";
	 for (int i = 0; i < other.size; i++) {
		 out << other.vecArray[i] << ", ";
	 }
	 return out << " ]";
}
 bool Vector::operator==(const Vector& other) {
	 if (this->size != other.size)return false;

	 for (int i = 0; i < this->size; i++) {
		 if (this->vecArray[i] != other.vecArray[i]) {
			 return false;
		 }
		
	 }
	 return true;
 }