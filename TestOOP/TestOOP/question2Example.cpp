#include <iostream>
using namespace std;
class ComDevice
{
public:
	ComDevice() { cout << "Hello "; }
	virtual void msg() { cout << "nock-nock\n"; }
	virtual void note() { print(); }
	void print() { cout << "I am in com-mode "; msg(); }
	~ComDevice() { cout << "Bye-bye!\n"; }
};
class Phone : public ComDevice
{
public:
	Phone() { cout << "Ring-Ring\n"; }
	void msg() { cout << "new message\n"; }
	void print() { cout << "connecting people "; msg(); }
	~Phone() { cout << "See you!\n"; }
};
class SmartPhone : public Phone
{
public:
	SmartPhone() { cout << "Hi!\n"; }
	void note() { print(); }
	void print() { cout << "Always with you "; msg(); }
	~SmartPhone() { cout << "Shut down\n"; }
};

/*
int main()
{
	ComDevice* tel = NULL;
	Phone shavit, * bzq = NULL;
	SmartPhone shisu;

	tel = &shavit;
	bzq = &shisu;

	tel->msg();
	tel->ComDevice::msg();
	tel->note();
	bzq->note();
	bzq->print();

	return 0;
}
*/