#pragma once
#include "lib.h"

class Person
{
public:
	Person(const string& name)
		:name(name)
	{
		cout << "\t\t >>>>>>>>>>>>>>>>>> Ctor PERSON " << name << endl;
	}
	void print() const;
	~Person()
	{
		cout << "\t\t >>>>>>>>>>>>>>>>>> Dtor PERSON " << name << endl;
	}
protected:
	string name;
};

