#include<iostream>
using namespace std;

template<class T>
void swap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

/*
int main()
{

	int num1 = 5;
	int num2 = 8;

	cout << num1 << ", " << num2 << endl;

	swap<int>(num1, num2);

	cout << num1 << ", " << num2 << endl;
	return 0;
}

*/
