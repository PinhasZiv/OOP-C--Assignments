#pragma once
#include <iostream>
#include <cassert>
using namespace std;

class Vector
{
	int* vecArray;
	int size;

public:
	Vector(int* vecArray = NULL, int size = 3) : vecArray(vecArray), size(size) {}//def and param
	Vector(const Vector &other);
	~Vector() { delete[]vecArray; }
		
	void setValue(const int val, const int index);
	void setVecArray();
	int get_value(const int index)const;
	int get_size()const { return this->size; }

	Vector& operator=(const Vector& other);
	friend ostream&operator <<(ostream & out, const Vector & other);
	bool operator ==(const Vector& other);
};

