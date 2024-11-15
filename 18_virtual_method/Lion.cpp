#include "Lion.h"

Lion::Lion(const string& place, const size_t& age, bool isAlone)
// Animal(); спочатку викликається конструктор базового класу
	:Animal(place, age),  // явно викликаємо потрібний конструктор базового класу
	isAlone(isAlone)
{
	/*setAge();
	setPLace()*/
	cout << "\t >>>>>>>>>>>>> Ctor LION ID #" << id << endl;
}

void Lion::print() const
{
	cout << "------------------------- LION #" << id << " -------------------" << endl;
	//cout << age // compile error - бо приватне поле в успадкованому класі, не видно
	cout << "\t\t Age   :: " << getAge() << endl;
	cout << "\t\t Place :: " << place << endl; // protected
	cout << "\t\t Alone :: " << boolalpha << isAlone << endl;

}

void Lion::eat() const
{
	cout << "Lion id " << id << " like eat meat" << endl;
}

Lion::~Lion()
{
	cout << "\t >>>>>>>>>>>>> Dtor LION ID #" << id << endl;
}
