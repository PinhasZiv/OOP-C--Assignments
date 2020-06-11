#include "Pizza.h"

void order(Pizza &p);

int main()
{

Pizza p1;
Pizza p2;
order(p1);
order(p2);


cout << p1 << endl;
cout << p2 << endl;

cout << "(p1 == p2)? : " << (p1 == p2) << endl;

p1.setToppingPrice(0, 15); // change Topping price value, to check the operators: <, >.
cout << "p1.topings[0].price set to 15:\n" << p1.getTopings()[0] << endl;
cout << "(p1.topings[0] < p2.topings[0])? : " << (p1.getTopings()[0] < p2.getTopings()[0]) << endl;
cout << "(p1.topings[0] > p2.topings[0])? : "  <<(p1.getTopings()[0] > p2.getTopings()[0]) << endl;

	return 0;
}

void order(Pizza &p)
{
	char tmpType[128];
	int topingsSize;
	cout << "Hello,\nWhat type of dough do you want to order? " << endl;
	cin >> tmpType;
	p.setType(tmpType);
	cout << "How many topping do you want"
		<< " on your pizza? " << endl;
	cin >> topingsSize;
	p.setTopings(topingsSize);
	for (int i = 0; i < topingsSize; i++)
	{
		char tmpName[128];
		char tmpCover;
		cout << "what the topping name? " << endl;
		cin >> tmpName;
		cout << "how to cover? " << endl;
		cin >> tmpCover;
		Topping tmpTop = Topping();
		tmpTop.setName(tmpName);
		tmpTop.setCoverege(tmpCover);
		p + tmpTop;
	}
}
