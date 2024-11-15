#pragma once
#include "Person.h"
class Student
	: virtual public Person
{
public:
	Student(const string& name = "Noname", const string& specialization = "NoSpec");
	void print() const;
	~Student();
protected:
	//string name; // успадковується від Персони
	string specialization;
};

