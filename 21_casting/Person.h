#pragma once
#include <iostream>
using namespace std;


class Person
{
private:
	string name = "Noname";
	size_t counter = 0;
public:
	Person() = default;
	Person(const string& name)
	{
		setName(name);
	}

	void setName(const string& name)
	{
		if (!name.empty())
			this->name = name;
	}
	string getName() const
	{
		const_cast<size_t&>(counter)++;
		return name;
	}

	virtual void print() const
	{
		cout << "Name :: " << name << "\t counter = " << counter << endl;
	}
};

class Student :
	public Person
{
	string specialization = "NoSpec";
public:
	Student() = default;
	Student(const string& name, const string& spec = "NoSpec")
		:Person(name), specialization(spec)
	{

	}

	virtual void learn()
	{
		cout << ">>>>>>>>>> " << typeid(*this).name() << " studies :: " << specialization << endl;
	}
	virtual void print() const
	{
		cout << ">>>>>>>>>> " << typeid(*this).name() << " studies :: " << specialization << endl;
		Person::print();
	}
};

class Aspirant
	:public Student
{
	string theme = "Important theme";
public:
	Aspirant() = default;
	Aspirant(const string& name, const string& spec = "NoSpec", const string& theme = "Important theme")
		:Student(name,spec), theme(theme)
	{}

	void print() const
	{
		Student::print();
		cout << "Theme :: " << theme << endl;
	}
	virtual void WriteDymlom()
	{
		cout << "Scientic theme :: " << theme << endl;
	}
};