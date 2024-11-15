#include "Wolf.h"

void Wolf::print() const
{
	cout << "------------------------- Wolf #" << id << " -------------------" << endl;
	//cout << age // compile error - бо приватне поле в успадкованому класі, не видно
	cout << "\t Age   :: " << getAge() << endl;
	cout << "\t Place :: " << getPlace() << endl;
	cout << "\t\t Weight :: " << boolalpha << weight << endl;

}

void Wolf::eat() const
{
	cout << "Dog id " << id << " likes to eat hares" << endl;
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
