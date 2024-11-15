#include "Wolf.h"

void Wolf::print() const
{
	cout << "------------------------- Wolf #" << id << " -------------------" << endl;
	//cout << age // compile error - бо приватне поле в успадкованому класі, не видно
	Animal::print();
	cout << "\t\t Weight :: " << boolalpha << weight << endl;

}

Wolf::Wolf(const string& place, const size_t& age, const size_t& weight)
	:Animal(place, age), weight(weight)
{
	cout << "\t >>>>>>>>>>>>> Ctor Wolf ID #" << id << endl;
}

Wolf::~Wolf()
{
	cout << "\t >>>>>>>>>>>>> Dtor LION ID #" << id << endl;
}
