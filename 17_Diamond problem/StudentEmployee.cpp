#include "StudentEmployee.h"

StudentEmployee::StudentEmployee(const string& name, const string& specialization, const string& position)
	:Person(name), Student("", specialization), Employee("---", position)

{
	/*Student::name = nameStudent;
	this->specialization = specialization;
	Employee::name = nameEmployee;
	this->position = position;*/
	cout << "\t\t >>>>>>>>>>>>>>>>>> Ctor STUDENT_EMPLOYEE " << Student::name << " - " << Employee::name << endl;
}

StudentEmployee::StudentEmployee(const Student& student, const Employee& employee)
	:Person(student),Student(student), Employee(employee) // copy ctor
{
}

void StudentEmployee::print() const
{
	/*Student::print();
	Employee::print();*/
	cout << "Name :: " << name << endl;
	cout << name <<  " studies " << specialization << endl;
	cout << name <<  " work as " << position << endl;

}

StudentEmployee::~StudentEmployee()
{
	cout << "\t\t >>>>>>>>>>>>>>>>>> Dtor STUDENT_EMPLOYEE " << Student::name << " - " << Employee::name << endl;
}
