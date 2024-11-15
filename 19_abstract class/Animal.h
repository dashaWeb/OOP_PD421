#pragma once
#include "lib.h"
class Animal abstract
{
public:
	void setAge(const size_t& age);
	void setPLace(const string& place);
	const string& getPlace() const;
	const size_t& getAge() const;

	virtual void print() const = 0; // чисто віртуальна функція, може не містити реалізацію
	virtual void eat() const = 0;

	Animal(const string& place = "No place", const size_t& age = 0); // default
	~Animal();

private:
	size_t age;
	static size_t last_id;
protected:
	size_t id;
	string place;
};

