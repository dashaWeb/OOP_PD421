#include "Student.h"

Student::Student(const string& name, const string& specialization)
	:name(name),specialization(specialization)
{
	cout << "\t\t >>>>>>>>>>>>>>>>>> Ctor STUDENT " << name << endl;
}

void Student::print() const
{
	cout << "Student name :: " << name << endl;
	cout << "Student spec :: " << specialization << endl;
}

Student::~Student()
{
	cout << "\t\t >>>>>>>>>>>>>>>>>> Dtor STUDENT " << name << endl;
}
