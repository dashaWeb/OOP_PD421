#include "Animal.h"

size_t Animal::last_id = 0; // definition of static field

void Animal::setAge(const size_t& age)
{
	this->age = age;
}

void Animal::setPLace(const string& place)
{
	if (!place.empty())
		this->place = place;
}

const string& Animal::getPlace() const
{
	return place;
}

const size_t& Animal::getAge() const
{
	return age;
}

void Animal::print() const
{
	cout << "\t Animal  ID   :: #" << id << endl;
	cout << "\t Animal age   :: " << age << endl;
	cout << "\t Animal place :: " << place << endl;
}

Animal::Animal(const string& place, const size_t& age)
{
	setAge(age);
	setPLace(place);
	id = ++last_id;
	cout << ">>>>>>>>>>>>> Ctor Animal ID #" << id << endl;
}

Animal::~Animal()
{
	cout << ">>>>>>>>>>>>> Dtor Animal ID #" << id << endl;
}
