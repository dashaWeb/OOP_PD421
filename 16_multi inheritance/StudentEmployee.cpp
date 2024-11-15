#include "StudentEmployee.h"

StudentEmployee::StudentEmployee(const string& nameStudent, const string& nameEmployee, const string& specialization, const string& position)
	:Student(nameStudent,specialization), Employee(nameEmployee, position)

{
	/*Student::name = nameStudent;
	this->specialization = specialization;
	Employee::name = nameEmployee;
	this->position = position;*/
	cout << "\t\t >>>>>>>>>>>>>>>>>> Ctor STUDENT_EMPLOYEE " << Student::name << " - " << Employee::name << endl;
}

StudentEmployee::StudentEmployee(const Student& student, const Employee& employee)
	:Student(student), Employee(employee) // copy ctor
{
}

void StudentEmployee::print() const
{
	Student::print();
	Employee::print();
	cout << Student::name;
	cout << Employee::name;
}

StudentEmployee::~StudentEmployee()
{
	cout << "\t\t >>>>>>>>>>>>>>>>>> Dtor STUDENT_EMPLOYEE " << Student::name << " - " << Employee::name << endl;
}
